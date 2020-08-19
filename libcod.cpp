#include "gsc.hpp"

cvar_t *developer;
cvar_t *sv_pure;

cvar_t *sv_allowDownload;
cvar_t *sv_wwwDownload;
cvar_t *cl_allowDownload;
cvar_t *cl_wwwDownload;

cvar_t *sv_downloadMessage;

void hook_sv_init(const char *format, ...)
{
	char s[COD2_MAX_STRINGLENGTH];
	va_list va;

	va_start(va, format);
	vsnprintf(s, sizeof(s), format, va);
	va_end(va);

	Com_Printf("%s", s);

	/* Do stuff after sv has been initialized here */

	// Register custom cvars
	sv_downloadMessage = Cvar_RegisterString("sv_downloadMessage", "", CVAR_ARCHIVE);

	// Force download on clients
	cl_allowDownload = Cvar_RegisterBool("cl_allowDownload", qtrue, CVAR_ARCHIVE | CVAR_SYSTEMINFO);
	cl_wwwDownload = Cvar_RegisterBool("cl_wwwDownload", qtrue, CVAR_ARCHIVE | CVAR_SYSTEMINFO);

	developer = Cvar_FindVar("developer");
	sv_pure = Cvar_FindVar("sv_pure");
	sv_allowDownload = Cvar_FindVar("sv_allowDownload");
	sv_wwwDownload = Cvar_FindVar("sv_wwwDownload");

}

void hook_sv_spawnserver(const char *format, ...)
{
	char s[COD2_MAX_STRINGLENGTH];
	va_list va;

	va_start(va, format);
	vsnprintf(s, sizeof(s), format, va);
	va_end(va);

	Com_Printf("%s", s);

	/* Do stuff after sv has been spawned here */

}

void custom_SV_MasterHeartbeat(const char *game)
{
	return;	// disabled masterserver listing
}

void custom_SV_WriteDownloadToClient(client_t *cl, msg_t *msg)
{
	int curindex;
	int iwdFile;
	char errorMessage[COD2_MAX_STRINGLENGTH];

	if (cl->state == CS_ACTIVE)
		return; // Client already in game

	if (!*cl->downloadName)
		return;	// Nothing being downloaded

	if (strlen(cl->downloadName) < 4)
		return; // File length too short

	if (strcmp(&cl->downloadName[strlen(cl->downloadName) - 4], ".iwd") != 0)
		return; // Not a iwd file

	if ( cl->wwwDlAck )
		return; // wwwDl acknowleged

	if (strlen(sv_downloadMessage->string))
	{
		Com_sprintf(errorMessage, sizeof(errorMessage), sv_downloadMessage->string);

		MSG_WriteByte( msg, svc_download );
		MSG_WriteShort( msg, 0 ); // client is expecting block zero
		MSG_WriteLong( msg, -1 ); // illegal file size
		MSG_WriteString( msg, errorMessage );

		*cl->downloadName = 0;
		return; // Download message instead of download
	}

	if (sv_wwwDownload->boolean && cl->wwwDownload)
	{
		if (!cl->wwwDl_failed)
		{
			SV_WWWRedirectClient(cl, msg);
			return; // wwwDl redirect
		}
	}

	// Hardcode client variables to make max download speed for everyone
	cl->state = CS_CONNECTED;
	cl->rate = 25000;
	cl->snapshotMsec = 50;

	if (!cl->download)
	{
		// We open the file here

		Com_Printf("clientDownload: %d : begining \"%s\"\n", cl - svs.clients, cl->downloadName);

		iwdFile = FS_iwIwd(cl->downloadName, "main");

		if ( !sv_allowDownload->integer || iwdFile || ( cl->downloadSize = FS_SV_FOpenFileRead( cl->downloadName, &cl->download ) ) <= 0 )
		{
			// cannot auto-download file
			if (iwdFile)
			{
				Com_Printf("clientDownload: %d : \"%s\" cannot download iwd files\n", cl - svs.clients, cl->downloadName);
				Com_sprintf(errorMessage, sizeof(errorMessage), "EXE_CANTAUTODLGAMEIWD\x15%s", cl->downloadName);
			}
			else if ( !sv_allowDownload->boolean )
			{
				Com_Printf("clientDownload: %d : \"%s\" download disabled\n", cl - svs.clients, cl->downloadName);

				if (sv_pure->boolean)
					Com_sprintf(errorMessage, sizeof(errorMessage), "EXE_AUTODL_SERVERDISABLED_PURE\x15%s", cl->downloadName);
				else
					Com_sprintf(errorMessage, sizeof(errorMessage), "EXE_AUTODL_SERVERDISABLED\x15%s", cl->downloadName);
			}
			else
			{
				Com_Printf("clientDownload: %d : \"%s\" file not found on server\n", cl - svs.clients, cl->downloadName);
				Com_sprintf(errorMessage, sizeof(errorMessage), "EXE_AUTODL_FILENOTONSERVER\x15%s", cl->downloadName);
			}

			MSG_WriteByte( msg, svc_download );
			MSG_WriteShort( msg, 0 ); // client is expecting block zero
			MSG_WriteLong( msg, -1 ); // illegal file size
			MSG_WriteString( msg, errorMessage );

			*cl->downloadName = 0;
			return;
		}

		// Init
		cl->downloadCurrentBlock = cl->downloadClientBlock = cl->downloadXmitBlock = 0;
		cl->downloadCount = 0;
		cl->downloadEOF = qfalse;
	}

	// Perform any reads that we need to
	while (cl->downloadCurrentBlock - cl->downloadClientBlock < MAX_DOWNLOAD_WINDOW && cl->downloadSize != cl->downloadCount)
	{
		curindex = (cl->downloadCurrentBlock % MAX_DOWNLOAD_WINDOW);

		if (!cl->downloadBlocks[curindex])
			cl->downloadBlocks[curindex] = (unsigned char *)Z_MallocInternal(MAX_DOWNLOAD_BLKSIZE);

		cl->downloadBlockSize[curindex] = FS_Read( cl->downloadBlocks[curindex], MAX_DOWNLOAD_BLKSIZE, cl->download );

		if (cl->downloadBlockSize[curindex] < 0)
		{
			// EOF right now
			cl->downloadCount = cl->downloadSize;
			break;
		}

		cl->downloadCount += cl->downloadBlockSize[curindex];

		// Load in next block
		cl->downloadCurrentBlock++;
	}

	// Check to see if we have eof condition and add the EOF block
	if (cl->downloadCount == cl->downloadSize && !cl->downloadEOF && cl->downloadCurrentBlock - cl->downloadClientBlock < MAX_DOWNLOAD_WINDOW)
	{
		cl->downloadBlockSize[cl->downloadCurrentBlock % MAX_DOWNLOAD_WINDOW] = 0;
		cl->downloadCurrentBlock++;
		cl->downloadEOF = qtrue;  // We have added the EOF block
	}

	// Write out the next section of the file, if we have already reached our window,
	// automatically start retransmitting

	if (cl->downloadClientBlock == cl->downloadCurrentBlock)
		return; // Nothing to transmit

	if (cl->downloadXmitBlock == cl->downloadCurrentBlock)
	{
		// We have transmitted the complete window, should we start resending?

		//FIXME:  This uses a hardcoded one second timeout for lost blocks
		//the timeout should be based on client rate somehow
		if (svs.time - cl->downloadSendTime > 1000)
			cl->downloadXmitBlock = cl->downloadClientBlock;
		else
			return;
	}

	// Send current block
	curindex = (cl->downloadXmitBlock % MAX_DOWNLOAD_WINDOW);

	MSG_WriteByte( msg, svc_download );
	MSG_WriteShort( msg, cl->downloadXmitBlock );

	// block zero is special, contains file size
	if ( cl->downloadXmitBlock == 0 )
		MSG_WriteLong( msg, cl->downloadSize );

	MSG_WriteShort( msg, cl->downloadBlockSize[curindex] );

	// Write the block
	if ( cl->downloadBlockSize[curindex] )
		MSG_WriteData( msg, cl->downloadBlocks[curindex], cl->downloadBlockSize[curindex] );

	Com_DPrintf("clientDownload: %d : writing block %d\n", cl - svs.clients, cl->downloadXmitBlock);

	// Move on to the next block
	// It will get sent with next snap shot.  The rate will keep us in line.
	cl->downloadXmitBlock++;

	cl->downloadSendTime = svs.time;
}

// Segfault fix
int hook_BG_IsWeaponValid(int a1, int a2)
{
	if ( !(unsigned char)sub_80E9758(a2) )
		return 0;

	if ( !(unsigned char)sub_80D9E84(a1 + 1348, a2) )
		return 0;

	int weapon = (int)BG_WeaponDefs(a2);

	if ( !weapon )
		return 0;

	if ( !*(long *)(weapon + 132) && *(char *)(a1 + 1365) != a2 && *(char *)(a1 + 1366) != a2 && *(long *)(weapon + 876) != a2 )
		return 0;

	return 1;
}

char *custom_va(const char *format, ...)
{
	char *s;
	va_list va;
	int v1;
	signed int v3;

	v1 = Sys_GetValue(1);
	s = (char *)(v1 + (*(int *)(v1 + 2048) << 10));
	v3 = *(int *)(v1 + 2048) + 1;
	*(int *)(v1 + 2048) = v3 / 2;
	*(int *)(v1 + 2048) = v3 - 2 * *(int *)(v1 + 2048);

	va_start(va, format);
	vsnprintf(s, COD2_MAX_STRINGLENGTH, format, va);
	va_end(va);

	s[COD2_MAX_STRINGLENGTH - 1] = '\0';

	return s;
}


#if COMPILE_RATELIMITER == 1
// ioquake3 rate limit connectionless requests
// https://github.com/ioquake/ioq3/blob/master/code/server/sv_main.c

// This is deliberately quite large to make it more of an effort to DoS
#define MAX_BUCKETS	16384
#define MAX_HASHES 1024

static leakyBucket_t buckets[ MAX_BUCKETS ];
static leakyBucket_t* bucketHashes[ MAX_HASHES ];
leakyBucket_t outboundLeakyBucket;

static long SVC_HashForAddress( netadr_t address )
{
	unsigned char *ip = address.ip;
	int	i;
	long hash = 0;

	for ( i = 0; i < 4; i++ )
	{
		hash += (long)( ip[ i ] ) * ( i + 119 );
	}

	hash = ( hash ^ ( hash >> 10 ) ^ ( hash >> 20 ) );
	hash &= ( MAX_HASHES - 1 );

	return hash;
}

static leakyBucket_t *SVC_BucketForAddress( netadr_t address, int burst, int period )
{
	leakyBucket_t *bucket = NULL;
	int	i;
	long hash = SVC_HashForAddress( address );
	int	now = Sys_MilliSeconds();

	for ( bucket = bucketHashes[ hash ]; bucket; bucket = bucket->next )
	{
		if ( memcmp( bucket->adr, address.ip, 4 ) == 0 )
		{
			return bucket;
		}
	}

	for ( i = 0; i < MAX_BUCKETS; i++ )
	{
		int interval;

		bucket = &buckets[ i ];
		interval = now - bucket->lastTime;

		// Reclaim expired buckets
		if ( bucket->lastTime > 0 && ( interval > ( burst * period ) ||
		                               interval < 0 ) )
		{
			if ( bucket->prev != NULL )
			{
				bucket->prev->next = bucket->next;
			}
			else
			{
				bucketHashes[ bucket->hash ] = bucket->next;
			}

			if ( bucket->next != NULL )
			{
				bucket->next->prev = bucket->prev;
			}

			memset( bucket, 0, sizeof( leakyBucket_t ) );
		}

		if ( bucket->type == 0 )
		{
			bucket->type = address.type;
			memcpy( bucket->adr, address.ip, 4 );

			bucket->lastTime = now;
			bucket->burst = 0;
			bucket->hash = hash;

			// Add to the head of the relevant hash chain
			bucket->next = bucketHashes[ hash ];
			if ( bucketHashes[ hash ] != NULL )
			{
				bucketHashes[ hash ]->prev = bucket;
			}

			bucket->prev = NULL;
			bucketHashes[ hash ] = bucket;

			return bucket;
		}
	}

	// Couldn't allocate a bucket for this address
	return NULL;
}

bool SVC_RateLimit( leakyBucket_t *bucket, int burst, int period )
{
	if ( bucket != NULL )
	{
		int now = Sys_MilliSeconds();
		int interval = now - bucket->lastTime;
		int expired = interval / period;
		int expiredRemainder = interval % period;

		if ( expired > bucket->burst || interval < 0 )
		{
			bucket->burst = 0;
			bucket->lastTime = now;
		}
		else
		{
			bucket->burst -= expired;
			bucket->lastTime = now - expiredRemainder;
		}

		if ( bucket->burst < burst )
		{
			bucket->burst++;

			return false;
		}
	}

	return true;
}

bool SVC_RateLimitAddress( netadr_t from, int burst, int period )
{
	leakyBucket_t *bucket = SVC_BucketForAddress( from, burst, period );

	return SVC_RateLimit( bucket, burst, period );
}

void hook_SV_GetChallenge(netadr_t from)
{
	// Prevent using getchallenge as an amplifier
	if ( SVC_RateLimitAddress( from, 10, 1000 ) )
	{
		Com_DPrintf( "SV_GetChallenge: rate limit from %s exceeded, dropping request\n", NET_AdrToString( from ) );
		return;
	}

	// Allow getchallenge to be DoSed relatively easily, but prevent
	// excess outbound bandwidth usage when being flooded inbound
	if ( SVC_RateLimit( &outboundLeakyBucket, 10, 100 ) )
	{
		Com_DPrintf( "SV_GetChallenge: rate limit exceeded, dropping request\n" );
		return;
	}

	SV_GetChallenge(from);
}

void hook_SVC_Info(netadr_t from)
{
	// Prevent using getinfo as an amplifier
	if ( SVC_RateLimitAddress( from, 10, 1000 ) )
	{
		Com_DPrintf( "SVC_Info: rate limit from %s exceeded, dropping request\n", NET_AdrToString( from ) );
		return;
	}

	// Allow getinfo to be DoSed relatively easily, but prevent
	// excess outbound bandwidth usage when being flooded inbound
	if ( SVC_RateLimit( &outboundLeakyBucket, 10, 100 ) )
	{
		Com_DPrintf( "SVC_Info: rate limit exceeded, dropping request\n" );
		return;
	}

	SVC_Info(from);
}

void hook_SVC_Status(netadr_t from)
{
	// Prevent using getstatus as an amplifier
	if ( SVC_RateLimitAddress( from, 10, 1000 ) )
	{
		Com_DPrintf( "SVC_Status: rate limit from %s exceeded, dropping request\n", NET_AdrToString( from ) );
		return;
	}

	// Allow getstatus to be DoSed relatively easily, but prevent
	// excess outbound bandwidth usage when being flooded inbound
	if ( SVC_RateLimit( &outboundLeakyBucket, 10, 100 ) )
	{
		Com_DPrintf( "SVC_Status: rate limit exceeded, dropping request\n" );
		return;
	}

	SVC_Status(from);
}
#endif


class cCallOfDuty2Pro
{
public:
	cCallOfDuty2Pro()
	{
		// dont inherit lib of parent
		unsetenv("LD_PRELOAD");

		// otherwise the printf()'s are printed at crash/end on older os/compiler versions
		setbuf(stdout, NULL);

		printf("> [LIBCOD] Compiled for CoD2 MP 1.3 on %s\n", __DATE__);

		// allow to write in executable memory
		mprotect((void *)0x08048000, 0x135000, PROT_READ | PROT_WRITE | PROT_EXEC);

		cracking_hook_call(0x080622F9, (int)hook_sv_init);
		cracking_hook_call(0x0809362A, (int)hook_sv_spawnserver);
		cracking_hook_call(0x08070BE7, (int)Scr_GetCustomFunction);
		cracking_hook_call(0x08070E0B, (int)Scr_GetCustomMethod);
		cracking_hook_call(0x0811098E, (int)Com_DPrintf);
		
		cracking_hook_function(0x080EBF24, (int)hook_BG_IsWeaponValid);
		cracking_hook_function(0x0808FDC2, (int)custom_SV_WriteDownloadToClient);
		cracking_hook_function(0x080B7FA6, (int)custom_va);
		cracking_hook_function(0x08096ED6, (int)custom_SV_MasterHeartbeat);

#if COMPILE_RATELIMITER == 1
		cracking_hook_call(0x08095C48, (int)hook_SVC_Info);
		cracking_hook_call(0x08095B94, (int)hook_SVC_Status);
		cracking_hook_call(0x08095CB2, (int)hook_SV_GetChallenge);
#endif

		printf("> [PLUGIN LOADED]\n");
	}

	~cCallOfDuty2Pro()
	{
		printf("> [PLUGIN UNLOADED]\n");
	}
};

cCallOfDuty2Pro *pro;

// lol, single again: because it got loaded two times now
// both now: able to load with wrapper AND directly
// IMPORTANT: file needs "lib" infront of name, otherwise it wont be loaded
// will be called when LD_PRELOAD is referencing this .so

void __attribute__ ((constructor)) lib_load(void)
{
	pro = new cCallOfDuty2Pro;
}

void __attribute__ ((destructor)) lib_unload(void)
{
	delete pro;
}
