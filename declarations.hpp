#ifndef _DECLARATIONS_HPP_
#define _DECLARATIONS_HPP_

#define qboolean int
#define qtrue 1
#define qfalse 0

#define DotProduct(a,b)         ((a)[0]*(b)[0]+(a)[1]*(b)[1]+(a)[2]*(b)[2])
#define VectorSubtract(a,b,c)   ((c)[0]=(a)[0]-(b)[0],(c)[1]=(a)[1]-(b)[1],(c)[2]=(a)[2]-(b)[2])
#define VectorAdd(a,b,c)        ((c)[0]=(a)[0]+(b)[0],(c)[1]=(a)[1]+(b)[1],(c)[2]=(a)[2]+(b)[2])
#define VectorCopy(a,b)         ((b)[0]=(a)[0],(b)[1]=(a)[1],(b)[2]=(a)[2])

#define	VectorScale(v, s, o)    ((o)[0]=(v)[0]*(s),(o)[1]=(v)[1]*(s),(o)[2]=(v)[2]*(s))
#define VectorMA(v, s, b, o)    ((o)[0]=(v)[0]+(b)[0]*(s),(o)[1]=(v)[1]+(b)[1]*(s),(o)[2]=(v)[2]+(b)[2]*(s))
#define CrossProduct(a,b,c)     ((c)[0]=(a)[1]*(b)[2]-(a)[2]*(b)[1],(c)[1]=(a)[2]*(b)[0]-(a)[0]*(b)[2],(c)[2]=(a)[0]*(b)[1]-(a)[1]*(b)[0])

#define DotProduct4( x,y )        ( ( x )[0] * ( y )[0] + ( x )[1] * ( y )[1] + ( x )[2] * ( y )[2] + ( x )[3] * ( y )[3] )
#define VectorSubtract4( a,b,c )  ( ( c )[0] = ( a )[0] - ( b )[0],( c )[1] = ( a )[1] - ( b )[1],( c )[2] = ( a )[2] - ( b )[2],( c )[3] = ( a )[3] - ( b )[3] )
#define VectorAdd4( a,b,c )       ( ( c )[0] = ( a )[0] + ( b )[0],( c )[1] = ( a )[1] + ( b )[1],( c )[2] = ( a )[2] + ( b )[2],( c )[3] = ( a )[3] + ( b )[3] )
#define VectorCopy4( a,b )        ( ( b )[0] = ( a )[0],( b )[1] = ( a )[1],( b )[2] = ( a )[2],( b )[3] = ( a )[3] )
#define VectorScale4( v, s, o )   ( ( o )[0] = ( v )[0] * ( s ),( o )[1] = ( v )[1] * ( s ),( o )[2] = ( v )[2] * ( s ),( o )[3] = ( v )[3] * ( s ) )
#define VectorMA4( v, s, b, o )   ( ( o )[0] = ( v )[0] + ( b )[0] * ( s ),( o )[1] = ( v )[1] + ( b )[1] * ( s ),( o )[2] = ( v )[2] + ( b )[2] * ( s ),( o )[3] = ( v )[3] + ( b )[3] * ( s ) )

#define VectorClear(a)		((a)[0]=(a)[1]=(a)[2]=0)
#define VectorNegate( a,b )       ( ( b )[0] = -( a )[0],( b )[1] = -( a )[1],( b )[2] = -( a )[2] )
#define VectorSet(v, x, y, z)	((v)[0]=(x), (v)[1]=(y), (v)[2]=(z))
#define Vector4Copy( a,b )        ( ( b )[0] = ( a )[0],( b )[1] = ( a )[1],( b )[2] = ( a )[2],( b )[3] = ( a )[3] )

#define SnapVector( v ) {v[0] = (int)v[0]; v[1] = (int)v[1]; v[2] = (int)v[2];}

#define MAX_CLIENTS 64
#define PACKET_BACKUP 32
#define MAX_QPATH 64
#define MAX_OSPATH 256
#define FRAMETIME 50

typedef unsigned char byte;
typedef struct gclient_s gclient_t;
typedef struct gentity_s gentity_t;
typedef int scr_entref_t;

typedef enum
{
	MOD_UNKNOWN,
	MOD_PISTOL_BULLET,
	MOD_RIFLE_BULLET,
	MOD_GRENADE,
	MOD_GRENADE_SPLASH,
	MOD_PROJECTILE,
	MOD_PROJECTILE_SPLASH,
	MOD_MELEE,
	MOD_HEAD_SHOT,
	MOD_CRUSH,
	MOD_TELEFRAG,
	MOD_FALLING,
	MOD_SUICIDE,
	MOD_TRIGGER_HURT,
	MOD_EXPLOSIVE,
	MOD_BAD
} meansOfDeath_t;

enum svc_ops_e
{
	svc_nop,
	svc_gamestate,
	svc_configstring,
	svc_baseline,
	svc_serverCommand,
	svc_download,
	svc_snapshot,
	svc_EOF
};

typedef enum
{
	ET_GENERAL = 0,
	ET_PLAYER = 1,
	ET_CORPSE = 2,
	ET_ITEM = 3,
	ET_MISSILE = 4,
	ET_INVISIBLE = 5,
	ET_SCRIPTMOVER = 6
} entityType_t;

typedef enum
{
	TEAM_FREE,
	TEAM_RED,
	TEAM_BLUE,
	TEAM_SPEC,
	TEAM_NUM_TEAMS
} team_t;

typedef enum
{
	CS_FREE,
	CS_ZOMBIE,
	CS_CONNECTED,
	CS_PRIMED,
	CS_ACTIVE
} clientState_t;

typedef enum
{
	STATE_PLAYING,
	STATE_DEAD,
	STATE_SPECTATOR,
	STATE_INTERMISSION
} sessionState_t;

typedef enum
{
	CON_DISCONNECTED,
	CON_CONNECTING,
	CON_CONNECTED
} clientConnected_t;

typedef enum
{
	NA_BOT = 0,
	NA_BAD = 0,
	NA_LOOPBACK = 2,
	NA_BROADCAST = 3,
	NA_IP = 4,
	NA_IPX = 5,
	NA_BROADCAST_IPX = 6
} netadrtype_t;

typedef struct
{
	netadrtype_t type;
	byte ip[4];
	unsigned short port;
	byte ipx[10];
} netadr_t;

typedef enum
{
	NS_CLIENT,
	NS_SERVER
} netsrc_t;

typedef struct
{
	qboolean overflowed;
	byte *data;
	int maxsize;
	int cursize;
	int readcount;
	int bit;
} msg_t;

typedef float vec_t;
typedef vec_t vec2_t[2];
typedef vec_t vec3_t[3];
typedef vec_t vec4_t[4];
typedef vec_t vec5_t[5];

typedef union
{
	int i;
	byte rgba[4];
} ucolor_t;

typedef struct cvar_s
{
	char *name;
	unsigned short flags;
	byte type;
	byte modified;
	union
	{
		float floatval;
		int integer;
		char* string;
		byte boolean;
		vec2_t vec2;
		vec3_t vec3;
		vec4_t vec4;
		ucolor_t color;
	};
	union
	{
		float latchedFloatval;
		int latchedInteger;
		char* latchedString;
		byte latchedBoolean;
		vec2_t latchedVec2;
		vec3_t latchedVec3;
		vec4_t latchedVec4;
		ucolor_t latchedColor;
	};
	union
	{
		float resetFloatval;
		int resetInteger;
		char* resetString;
		byte resetBoolean;
		vec2_t resetVec2;
		vec3_t resetVec3;
		vec4_t resetVec4;
		ucolor_t resetColor;
	};
	union
	{
		int imin;
		float fmin;
	};
	union
	{
		int imax;
		float fmax;
		const char** enumStr;
	};
	struct cvar_s *next;
	struct cvar_s *hashNext;
} cvar_t;

#define	CVAR_ARCHIVE		1
#define	CVAR_USERINFO		2
#define	CVAR_SERVERINFO		4
#define	CVAR_SYSTEMINFO		8
#define	CVAR_INIT			16
#define	CVAR_LATCH			32
#define	CVAR_ROM			64
#define CVAR_CHEAT			128
#define	CVAR_TEMP			256
#define CVAR_NORESTART		1024
#define	CVAR_USER_CREATED	16384

struct VariableStackBuffer
{
	const char *pos;
	u_int16_t size;
	u_int16_t bufLen;
	u_int16_t localId;
	char time;
	char buf[1];
};

union VariableUnion
{
	int intValue;
	float floatValue;
	unsigned int stringValue;
	const float *vectorValue;
	const char *codePosValue;
	unsigned int pointerValue;
	struct VariableStackBuffer *stackValue;
	unsigned int entityOffset;
};

union ObjectInfo_u
{
	u_int16_t size;
	u_int16_t entnum;
	u_int16_t nextEntId;
	u_int16_t self;
};

struct ObjectInfo
{
	u_int16_t refCount;
	union ObjectInfo_u u;
};

union VariableValueInternal_u
{
	u_int16_t next;
	union VariableUnion u;
	struct ObjectInfo o;
};

union VariableValueInternal_w
{
	unsigned int status;
	unsigned int type;
	unsigned int name;
	unsigned int classnum;
	unsigned int notifyName;
	unsigned int waitTime;
	unsigned int parentLocalId;
};

union VariableValueInternal_v
{
	u_int16_t next;
	u_int16_t index;
};

typedef struct
{
	union VariableUnion u;
	int type;
} VariableValue;

union Variable_u
{
	u_int16_t prev;
	u_int16_t prevSibling;
};

struct Variable
{
	u_int16_t id;
	union Variable_u u;
};

typedef struct
{
	struct Variable hash;
	union VariableValueInternal_u u;
	union VariableValueInternal_w w;
	union VariableValueInternal_v v;
	u_int16_t nextSibling;
} VariableValueInternal;

typedef struct
{
	const char *fieldBuffer;
	struct HunkUser *programHunkUser;
	u_int16_t canonicalStrCount;
	byte developer;
	byte developer_script;
	byte evaluate;
	byte pad[3];
	const char *error_message;
	int error_index;
	unsigned int time;
	unsigned int timeArrayId;
	unsigned int pauseArrayId;
	unsigned int levelId;
	unsigned int gameId;
	unsigned int animId;
	unsigned int freeEntList;
	unsigned int tempVariable;
	byte bInited;
	byte pad2;
	u_int16_t savecount;
	unsigned int checksum;
	unsigned int entId;
	unsigned int entFieldName;
	const char *programBuffer;
	const char *endScriptBuffer;
} scrVarPub_t;

struct function_stack_t
{
	const char *pos;
	unsigned int localId;
	unsigned int localVarCount;
	VariableValue *top;
	VariableValue *startTop;
};

struct function_frame_t
{
	struct function_stack_t fs;
	int topType;
};

typedef struct
{
	unsigned int *localVars;
	VariableValue *maxstack;
	int function_count;
	struct function_frame_t *function_frame;
	VariableValue *top;
	byte debugCode;
	byte abort_on_error;
	byte terminal_error;
	byte pad;
	unsigned int inparamcount;
	unsigned int outparamcount;
	struct function_frame_t function_frame_start[32];
	VariableValue stack[2048];
} scrVmPub_t;

typedef int	fileHandle_t;
typedef void (*xfunction_t)();
typedef void (*xmethod_t)(scr_entref_t);

typedef struct scr_function_s
{
	const char      *name;
	xfunction_t     call;
	qboolean        developer;
} scr_function_t;

typedef struct scr_method_s
{
	const char     *name;
	xmethod_t      call;
	qboolean       developer;
} scr_method_t;


typedef enum
{
	TRACE_HITTYPE_NONE = 0x0,
	TRACE_HITTYPE_ENTITY = 0x1,
	TRACE_HITTYPE_DYNENT_MODEL = 0x2,
	TRACE_HITTYPE_DYNENT_BRUSH = 0x3,
	TRACE_HITTYPE_GLASS = 0x4
} TraceHitType;

typedef struct trace_s
{
	float fraction;
	vec3_t normal;
	int surfaceFlags;
	int contents;
	const char *material;
	TraceHitType hitType;
	u_int16_t hitId;
	u_int16_t modelIndex;
	u_int16_t partName;
	u_int16_t partGroup;
	byte allsolid;
	byte startsolid;
	byte walkable;
	byte padding;
} trace_t;

typedef struct leakyBucket_s leakyBucket_t;
struct leakyBucket_s
{
	netadrtype_t type;
	unsigned char adr[4];
	int	lastTime;
	signed char	burst;
	long hash;
	leakyBucket_t *prev, *next;
};

typedef struct usercmd_s
{
	int serverTime;
	int buttons;
	byte weapon;
	byte offHandIndex;
	int angles[3];
	char forwardmove;
	char rightmove;
} usercmd_t;

#if COD_VERSION == COD2_1_0 || COD_VERSION == COD2_1_2
#define MAX_MSGLEN 0x4000
#elif COD_VERSION == COD2_1_3
#define MAX_MSGLEN 0x20000
#endif

typedef void netProfileInfo_t;

typedef struct
{
	int			outgoingSequence;
	netsrc_t	sock;
	int			dropped;
	int			incomingSequence;
	netadr_t	remoteAddress;
	int 		qport;
	int			fragmentSequence;
	int			fragmentLength;
	byte		fragmentBuffer[MAX_MSGLEN];
	qboolean	unsentFragments;
	int			unsentFragmentStart;
	int			unsentLength;
	byte		unsentBuffer[MAX_MSGLEN];
	netProfileInfo_t *netProfile;
} netchan_t;

typedef struct
{
	char command[1024];
	int cmdTime;
	int cmdType;
} reliableCommands_t;

typedef struct
{
	netadr_t adr;
	int challenge;
	int time;
	int pingTime;
	int firstTime;
	int firstPing;
	qboolean connected;
	int guid;
#if COD_VERSION == COD2_1_2 || COD_VERSION == COD2_1_3
	char pbguid[64];
	int ipAuthorize;
#endif
} challenge_t; // verified for 1.0, guessed for 1.2 and 1.3

typedef enum
{
	TR_STATIONARY = 0,
	TR_INTERPOLATE = 1,
	TR_LINEAR = 2,
	TR_LINEAR_STOP = 3,
	TR_SINE = 4,
	TR_GRAVITY = 5,
	TR_GRAVITY_PAUSED = 6,
	TR_ACCELERATE = 7,
	TR_DECCELERATE = 8
} trType_t;

typedef struct
{
	trType_t	trType;
	int			trTime;
	int			trDuration;
	vec3_t		trBase;
	vec3_t		trDelta;
} trajectory_t;

typedef struct entityState_s
{
	int number;
	int eType;
	int eFlags;
	trajectory_t pos;
	trajectory_t apos;
	int time;
	int time2;
	vec3_t origin;
	vec3_t angles;
	int otherEntityNum;
	int attackerEntityNum;
	int groundEntityNum;
	int constantLight;
	int loopSound;
	int surfaceFlags;
	int modelindex;
	int clientNum;
	int	iHeadIcon;
	int	iHeadIconTeam;
	int	solid;
	int	eventParm;
	int	eventSequence;
	vec4_t events;
	vec4_t eventParms;
	int weapon;
	int legsAnim;
	int torsoAnim;
	int stage;
	int loopfxid;
	int hintstring;
	int animMovetype;
	vec3_t unkAngles;
} entityState_t; // verified

typedef struct
{
	byte		linked;
	byte		bmodel;
	byte		svFlags;
	byte		pad1;
	int			clientMask[2];
	byte		inuse;
	byte		pad2[3];
	int			broadcastTime;
	vec3_t		mins, maxs;
	int			contents;
	vec3_t		absmin, absmax;
	vec3_t		currentOrigin;
	vec3_t		currentAngles;
	u_int16_t	ownerNum;
	u_int16_t	pad3;
	int			eventTime;
} entityShared_t; // verified

typedef enum
{
	STAT_HEALTH,
	STAT_DEAD_YAW,
	STAT_MAX_HEALTH,
	STAT_FRIENDLY_LOOKAT_CLIENTNUM,
	STAT_FRIENDLY_LOOKAT_HEALTH,
	STAT_SPAWN_COUNT
} statIndex_t;

typedef enum
{
	PLAYERVIEWLOCK_NONE = 0x0,
	PLAYERVIEWLOCK_FULL = 0x1,
	PLAYERVIEWLOCK_WEAPONJITTER = 0x2,
	PLAYERVIEWLOCKCOUNT = 0x3,
} ViewLockTypes_t;

typedef enum
{
	OBJST_EMPTY = 0x0,
	OBJST_ACTIVE = 0x1,
	OBJST_INVISIBLE = 0x2,
	OBJST_DONE = 0x3,
	OBJST_CURRENT = 0x4,
	OBJST_FAILED = 0x5,
	OBJST_NUMSTATES = 0x6,
} objectiveState_t;

typedef struct objective_s
{
	objectiveState_t state;
	vec3_t origin;
	int entNum;
	int teamNum;
	int icon;
} objective_t;

typedef enum
{
	HE_TYPE_FREE = 0x0,
	HE_TYPE_TEXT = 0x1,
	HE_TYPE_VALUE = 0x2,
	HE_TYPE_PLAYERNAME = 0x3,
	HE_TYPE_MAPNAME = 0x4,
	HE_TYPE_GAMETYPE = 0x5,
	HE_TYPE_MATERIAL = 0x6,
	HE_TYPE_TIMER_DOWN = 0x7,
	HE_TYPE_TIMER_UP = 0x8,
	HE_TYPE_TENTHS_TIMER_DOWN = 0x9,
	HE_TYPE_TENTHS_TIMER_UP = 0xA,
	HE_TYPE_CLOCK_DOWN = 0xB,
	HE_TYPE_CLOCK_UP = 0xC,
	HE_TYPE_WAYPOINT = 0xD,
	HE_TYPE_COUNT = 0xE,
} he_type_t;

typedef struct
{
	char r;
	char g;
	char b;
	char a;
} hudelem_colorsplit_t;

typedef union
{
	hudelem_colorsplit_t split;
	int rgba;
} hudelem_color_t;

typedef struct hudelem_s
{
	he_type_t type;
	float x;
	float y;
	float z;
	float fontScale;
	int font;
	int alignOrg;
	int alignScreen;
	hudelem_color_t color;
	hudelem_color_t fromColor;
	int fadeStartTime;
	int fadeTime;
	int label;
	int width;
	int height;
	int materialIndex;
	int fromWidth;
	int fromHeight;
	int scaleStartTime;
	int scaleTime;
	float fromX;
	float fromY;
	int fromAlignOrg;
	int fromAlignScreen;
	int moveStartTime;
	int moveTime;
	int time;
	int duration;
	float value;
	int text;
	float sort;
	hudelem_color_t glowColor;
} hudelem_t; // verified

typedef struct hudElemState_s
{
	hudelem_t current[31];
	hudelem_t archival[31];
} hudElemState_t;

typedef struct
{
	float	yaw;
	int	timer;
	int	transIndex;
	int	flags;
} mantleState_t;

typedef struct playerState_s
{
	int	commandTime;
	int pm_type;
	int bobCycle;
	int pm_flags;
	int pm_time;
	vec3_t origin;
	vec3_t velocity;
	vec2_t oldVelocity; // 48
	int	weaponTime;
	int weaponDelay;
	int	grenadeTimeLeft;
	int	throwBackGrenadeOwner;
	int	throwBackGrenadeTimeLeft;
	int	gravity;
	float leanf;
	int speed;
	vec3_t delta_angles;
	int groundEntityNum;
	vec3_t vLadderVec;
	int jumpTime;
	float jumpOriginZ;
	int legsTime;
	int legsAnim;
	int torsoTime;
	int torsoAnim;
	int	legsAnimDuration;
	int	torsoAnimDuration;
	int	damageTimer;
	int	damageDuration;
	int	flinchYawAnim;
	int	movementDir;
	int	eFlags;
	int	eventSequence;
	int events[4];
	unsigned int eventParms[4];
	int	oldEventSequence;
	int	clientNum;
	int	offHandIndex;
	unsigned int weapon;
	int	weaponstate;
	float fWeaponPosFrac;
	int adsDelayTime;
	int	viewmodelIndex;
	vec3_t viewangles;
	int viewHeightTarget;
	float viewHeightCurrent;
	int viewHeightLerpTime;
	int viewHeightLerpTarget;
	int viewHeightLerpDown;
	int unknown[5];
	int	damageEvent;
	int	damageYaw;
	int	damagePitch;
	int	damageCount;
	int	stats[6];
	int	ammo[128];
	int	ammoclip[128]; // 836
	int weapFlags;
	int weapFlags2;
	int unknown2[2];
	byte slot_none;
	byte slot_primary;
	byte slot_primaryb;
	int unknown3[5];
	vec3_t mins;
	vec3_t maxs;
	float proneDirection;
	float proneDirectionPitch;
	float proneTorsoPitch;
	ViewLockTypes_t viewlocked;
	int viewlocked_entNum;
	int	cursorHint;
	int	cursorHintString;
	int	cursorHintEntIndex;
	int unknown1;
	vec3_t unkAngles;
	float holdBreathScale;
	int holdBreathTimer;
	mantleState_t mantleState;
	int entityEventSequence;
	int	weapAnim;
	float aimSpreadScale;
	int	shellshockIndex;
	int	shellshockTime;
	int	shellshockDuration;
	objective_t objective[16];
	int archiveTime;
	hudElemState_t hud;
} playerState_t;

typedef enum
{
	TEAM_NONE,
	TEAM_AXIS,
	TEAM_ALLIES,
	TEAM_SPECTATOR
} sessionTeam_t;

typedef struct
{
	sessionState_t state;
	int forceSpectatorClient;
	int statusIcon;
	int archiveTime;
	int	score;
	int deaths;
	u_int16_t scriptPersId;
	byte pad2;
	byte pad;
	clientConnected_t connected;
	usercmd_t cmd;
	usercmd_t oldcmd;
	qboolean localClient;
	qboolean predictItemPickup;
	char name[32];
	int maxHealth;
	int enterTime;
	int voteCount;
	int teamVoteCount;
	float moveSpeedScaleMultiplier; // ?
	int viewmodelIndex;
	qboolean noSpectate;
	int teamInfo;
	int clientId;
	sessionTeam_t team;
	int model;
	int attachedModels[6];
	int attachedModelsTags[6];
	char manualModeName[32];
	int psOffsetTime;
} clientSession_t; // verified

struct gclient_s
{
	playerState_t ps;
	clientSession_t sess;
	int spectatorClient;
	qboolean noclip;
	qboolean ufo;
	qboolean bFrozen;
	int lastCmdTime;
	int buttons;
	int oldbuttons;
	int latched_buttons;
	int buttonsSinceLastFrame;
	vec3_t oldOrigin;
	float fGunPitch;
	float fGunYaw;
	int damage_blood;
	vec3_t damage_from;
	qboolean damage_fromWorld;
	int accurateCount; // N/A
	int accuracy_shots; // N/A
	int accuracy_hits; // N/A
	int inactivityTime;
	qboolean inactivityWarning;
	int playerTalkTime;
	int rewardTime; // N/A
	float antilagShootTime; // 10256
	int unknown_space[2];
	int unknownClientEndFrameVar;
	int unknown_space2[3];
	gentity_t *lookAtEntity; // needs a NULL check, otherwise crash.
	int activateEntNumber;
	int activateTime;
	int nonPVSFriendlyEntNum;
	int pingPlayerTime;
	int damageFeedBackTime;
	vec2_t damageFeedBackDir;
	vec3_t swayViewAngles; // 10316
	vec3_t swayOffset;
	vec3_t swayAngles;
	int unknown_space3[7];
	float weaponRecoil; // 10380
	int unknown_space4[3];
	int lastServerTime;
	int lastActivateTime;
}; // verified

typedef int turretInfo_s;

struct gentity_s
{
	entityState_t s;
	entityShared_t r;
	struct gclient_s *client; // 344
	turretInfo_s *pTurretInfo;
	byte physicsObject; // 352
	byte takedamage; // 353
	byte active; // 354
	byte nopickup; // 355 ?
	byte model; // 356
	byte dobjbits; // 357 ?
	byte handler; // 358
	byte team; // 359
	u_int16_t classname; // 360
	u_int16_t target;
	u_int16_t targetname;
	u_int16_t padding;
	int spawnflags;
	int flags;
	int eventTime;
	qboolean freeAfterEvent; // 380
	qboolean unlinkAfterEvent; // 384
	int clipmask; // 388
	int framenum; // 392
	gentity_t *parent; // 396
	int nextthink; // 400
	int healthPoints; // 404
	int reservedHealth; // 408 ?
	int damage; // 412
	int splashDamage; // 416 ?
	int splashRadius; // 420 ?
	float pfDecelTimeMove; // 424
	float pfDecelTimeRotate; // 428
	float pfSpeedMove; // 432
	float pfSpeedRotate; // 436
	float pfMidTimeMove; // 440
	float pfMidTimeRotate; // 444
	vec3_t vPos1Move; // 448 ?
	vec3_t vPos2Move; // 460
	vec3_t vPos3Move; // 472
	vec3_t vPos1Rotate; // 484 ?
	vec3_t vPos2Rotate; // 496
	vec3_t vPos3Rotate; // 508
	int moverState; // 520 ?
	gentity_t** linkedEntities; // 524 ??
	byte attachedModels[6]; // 528
	u_int16_t attachedModelsIndexes; // 536 ?
	u_int16_t numAttachedModels; // 538 ?
	int animTree; // 540 ?
	vec4_t color; // ?
}; // verified

#define MAX_DOWNLOAD_BLKSIZE 1024
#define MAX_DOWNLOAD_WINDOW 8

typedef struct
{
	playerState_t ps;
	int	num_entities;
	int	num_clients;
	int	first_entity;
	int	first_client;
	unsigned int messageSent;
	unsigned int messageAcked;
	int	messageSize;
} clientSnapshot_t;

#pragma pack(push)
#pragma pack(1)
typedef struct
{
	char num;
	char data[256];
	int dataLen;
} voices_t;
#pragma pack(pop)

typedef struct client_s
{
	clientState_t	state;
	int				unksnapshotvar;
	int				unksnapshotvar2;
	char			userinfo[1024];
	reliableCommands_t	reliableCommands[128];
	int				reliableSequence;
	int				reliableAcknowledge;
	int				reliableSent;
	int				messageAcknowledge;
	int				gamestateMessageNum;
	int				challenge;
	usercmd_t  	 	lastUsercmd;
	int				lastClientCommand;
	char			lastClientCommandString[1024];
	gentity_t 		*gentity;
	char 			name[32];
	char			downloadName[MAX_QPATH];
	fileHandle_t	download;
	int				downloadSize;
	int				downloadCount;
	int				downloadClientBlock;
	int				downloadCurrentBlock;
	int				downloadXmitBlock;
	unsigned char	*downloadBlocks[MAX_DOWNLOAD_WINDOW];
	int				downloadBlockSize[MAX_DOWNLOAD_WINDOW];
	qboolean		downloadEOF;
	int				downloadSendTime;
#if COD_VERSION == COD2_1_2 || COD_VERSION == COD2_1_3
	char			wwwDownloadURL[MAX_OSPATH];
	qboolean		wwwDownload;
	qboolean		wwwDownloadStarted;
	qboolean		wwwDlAck;
	qboolean		wwwDl_failed;
#endif
	int				deltaMessage;
	int				floodprotect;
	int				lastPacketTime;
	int				lastConnectTime;
	int				nextSnapshotTime;
	qboolean		rateDelayed;
	int				timeoutCount;
	clientSnapshot_t frames[PACKET_BACKUP];
	int				ping;
	int				rate;
	int				snapshotMsec;
	int				pureAuthentic;
	netchan_t		netchan;
	int 			guid;
	short			clscriptid;
	int				bot;
	int				serverId;
	voices_t		voicedata[40];
	int				unsentVoiceData;
	byte			mutedClients[MAX_CLIENTS];
	byte			hasVoip;
#if COD_VERSION == COD2_1_2 || COD_VERSION == COD2_1_3
	char 			pbguid[64];
#endif
} client_t;

typedef struct archivedSnapshot_s
{
	int start;
	int size;
} archivedSnapshot_t;

typedef struct cachedClient_s
{
	int playerStateExists;
	clientState_t *cs;
	playerState_t *ps;
} cachedClient_t;

typedef struct
{
	qboolean	initialized;
	int			time;
	int			snapFlagServerBit;
	client_t	*clients;
	int			numSnapshotEntities;
	int			numSnapshotClients;
	int			nextSnapshotEntities;
	int			nextSnapshotClients;
	entityState_t *snapshotEntities;
	clientState_t *snapshotClients;
	int 		archivedSnapshotEnabled;
	int 		nextArchivedSnapshotFrames;
	archivedSnapshot_t *archivedSnapshotFrames;
	int 		*archivedSnapshotBuffer;
	int 		nextArchivedSnapshotBuffer;
	int			nextCachedSnapshotEntities;
	int 		nextCachedSnapshotClients;
	int 		nextCachedSnapshotFrames;
	cachedClient_t cachedSnapshotClients;
	int			nextHeartbeatTime;
	int 		nextStatusResponseTime;
	challenge_t	challenges[1024];
	netadr_t	redirectAddress;
	netadr_t	authorizeAddress;
	char 		netProfilingBuf[1504];
} serverStatic_t; // verified

typedef struct
{
	const char *key;
	const char *value;
} keyValueStr_t;

typedef struct
{
	byte spawnVarsValid;
	int numSpawnVars;
	keyValueStr_t spawnVars[64];
	int numSpawnVarChars;
	char spawnVarChars[2048];
} SpawnVar;

typedef struct
{
	u_int16_t entnum;
	u_int16_t otherEntnum;
	int useCount;
	int otherUseCount;
} trigger_info_t;

typedef struct
{
	struct gclient_s *clients;
	struct gentity_s *gentities;
	int gentitySize;
	int num_entities;
	struct gentity_s *firstFreeEnt;
	struct gentity_s *lastFreeEnt;
	fileHandle_t logFile;
	int initializing;
	int clientIsSpawning;
	objective_t objectives[16];
	int maxclients;
	int framenum;
	int time;
	int previousTime;
	int frameTime;
	int startTime;
	int teamScores[TEAM_NUM_TEAMS];
	int lastTeammateHealthTime;
	qboolean bUpdateScoresForIntermission;
	int manualNameChange;
	int numConnectedClients;
	int sortedClients[MAX_CLIENTS];
	char voteString[1024];
	char voteDisplayString[1024];
	int voteTime; // 711
	int voteExecuteTime;
	int voteYes;
	int voteNo;
	int numVotingClients;
	byte gap[2072];
	SpawnVar spawnVars;
	int savePersist;
	struct gentity_s *droppedWeaponCue[32];
	float fFogOpaqueDist;
	float fFogOpaqueDistSqrd;
	int remapCount;
	int currentPlayerClone;
	trigger_info_t pendingTriggerList[256];
	trigger_info_t currentTriggerList[256];
	int pendingTriggerListSize;
	int currentTriggerListSize;
	int finished;
	int bPlayerIgnoreRadiusDamage;
	int bPlayerIgnoreRadiusDamageLatched;
	int registerWeapons;
	int bRegisterItems;
	int currentEntityThink;
	void *openScriptIOFileHandles[1];
	char *openScriptIOFileBuffers[1];
} level_locals_t; // possibly more stuff here

typedef enum
{
	SS_DEAD,
	SS_LOADING,
	SS_GAME
} serverState_t;

#define MAX_CONFIGSTRINGS   2048
#define MAX_MODELS          256
#define GENTITYNUM_BITS     10
#define MAX_GENTITIES       ( 1 << GENTITYNUM_BITS )
#define MAX_ENT_CLUSTERS    16
#define MAX_BPS_WINDOW 		20

typedef struct
{
	int cluster;
	int area;
	int firstLeafBrush;
	int numLeafBrushes;
	int firstLeafSurface;
	int numLeafSurfaces;
} cLeaf_t;

typedef struct cmodel_s
{
	vec3_t mins, maxs;
	cLeaf_t leaf;
} cmodel_t;

typedef struct
{
	int svFlags;
	int clientMask[2];
	vec3_t absmin;
	vec3_t absmax;
} archivedEntityShared_t;

typedef struct archivedEntity_s
{
	entityState_t s;
	archivedEntityShared_t r;
} archivedEntity_t;

typedef struct svEntity_s
{
	u_int16_t worldSector;
	u_int16_t nextEntityInWorldSector;
	archivedEntity_t baseline;
	int numClusters;
	int clusternums[MAX_ENT_CLUSTERS];
	int	lastCluster;
	int	linkcontents;
	float linkmin[2];
	float linkmax[2];
} svEntity_t;

typedef struct
{
	serverState_t state;
	qboolean restarting;
	int start_frameTime;
	int	checksumFeed;
	int timeResidual;
	int unk; // ?
	struct cmodel_s *models[MAX_MODELS]; // ?
	char *configstrings[MAX_CONFIGSTRINGS];
	svEntity_t svEntities[MAX_GENTITIES];
	char *entityParsePoint;
	gentity_t *gentities;
	int gentitySize;
	int	num_entities;
	playerState_t *gameClients;
	int gameClientSize;
	int	skelTimeStamp;
	int	skelMemPos;
	int	bpsWindow[MAX_BPS_WINDOW];
	int	bpsWindowSteps;
	int	bpsTotalBytes;
	int	bpsMaxBytes;
	int	ubpsWindow[MAX_BPS_WINDOW];
	int	ubpsTotalBytes;
	int	ubpsMaxBytes;
	float ucompAve;
	int	ucompNum;
	char gametype[MAX_QPATH];
} server_t; // verified

typedef enum weapType_t
{
	WEAPTYPE_BULLET = 0x0,
	WEAPTYPE_GRENADE = 0x1,
	WEAPTYPE_PROJECTILE = 0x2,
	WEAPTYPE_BINOCULARS = 0x3,
	WEAPTYPE_NUM = 0x4
} weapType_t;

typedef enum weapClass_t
{
	WEAPCLASS_RIFLE = 0x0,
	WEAPCLASS_MG = 0x1,
	WEAPCLASS_SMG = 0x2,
	WEAPCLASS_SPREAD = 0x3,
	WEAPCLASS_PISTOL = 0x4,
	WEAPCLASS_GRENADE = 0x5,
	WEAPCLASS_ROCKETLAUNCHER = 0x6,
	WEAPCLASS_TURRET = 0x7,
	WEAPCLASS_NON_PLAYER = 0x8,
	WEAPCLASS_ITEM = 0x9,
	WEAPCLASS_NUM = 0xA
} weapClass_t;

typedef enum ImpactType_t
{
	IMPACT_TYPE_NONE = 0x0,
	IMPACT_TYPE_BULLET_SMALL = 0x1,
	IMPACT_TYPE_BULLET_LARGE = 0x2,
	IMPACT_TYPE_BULLET_AP = 0x3,
	IMPACT_TYPE_SHOTGUN = 0x4,
	IMPACT_TYPE_GRENADE_BOUNCE = 0x5,
	IMPACT_TYPE_GRENADE_EXPLODE = 0x6,
	IMPACT_TYPE_ROCKET_EXPLODE = 0x7,
	IMPACT_TYPE_PROJECTILE_DUD = 0x8,
	IMPACT_TYPE_COUNT = 0x9
} ImpactType_t;

typedef enum weapInventoryType_t
{
	WEAPINVENTORY_PRIMARY = 0x0,
	WEAPINVENTORY_OFFHAND = 0x1,
	WEAPINVENTORY_ITEM = 0x2,
	WEAPINVENTORY_ALTMODE = 0x3,
	WEAPINVENTORYCOUNT = 0x4
} weapInventoryType_t;

typedef enum OffhandClass_t
{
	OFFHAND_CLASS_NONE = 0x0,
	OFFHAND_CLASS_FRAG_GRENADE = 0x1,
	OFFHAND_CLASS_SMOKE_GRENADE = 0x2,
	OFFHAND_CLASS_COUNT = 0x3
} OffhandClass_t;

typedef enum weapStance_t
{
	WEAPSTANCE_STAND = 0x0,
	WEAPSTANCE_DUCK = 0x1,
	WEAPSTANCE_PRONE = 0x2,
	WEAPSTANCE_NUM = 0x3
} weapStance_t;

typedef enum weapOverlayReticle_t
{
	WEAPOVERLAYRETICLE_NONE = 0x0,
	WEAPOVERLAYRETICLE_CROSSHAIR = 0x1,
	WEAPOVERLAYRETICLE_NUM = 0x2
} weapOverlayReticle_t;

typedef enum weaponIconRatioType_t
{
	WEAPON_ICON_RATIO_1TO1 = 0x0,
	WEAPON_ICON_RATIO_2TO1 = 0x1,
	WEAPON_ICON_RATIO_4TO1 = 0x2,
	WEAPON_ICON_RATIO_COUNT = 0x3
} weaponIconRatioType_t;

typedef enum weapProjExposion_t
{
	WEAPPROJEXP_GRENADE = 0x0,
	WEAPPROJEXP_MOLOTOV = 0x1,
	WEAPPROJEXP_ROCKET = 0x2,
	WEAPPROJEXP_NONE = 0x3,
	WEAPPROJEXP_NUM = 0x4
} weapProjExposion_t;

typedef const char FxEffectDef_t;
typedef const char snd_alias_list_t;
typedef const char Material_t;

typedef struct WeaponDef_t
{
	const char *szInternalName;
	const char *szDisplayName;
	const char *szOverlayName;
	const char *szViewModelName;
	const char *szHandModelName;
	int unknown;
	const char *szXAnims[22];
	const char *szModeName;
	int playerAnimType;
	weapType_t weapType;
	weapClass_t weapClass;
	ImpactType_t impactType;
	weapInventoryType_t inventoryType;
	OffhandClass_t offhandClass; // ? not confirmed
	weapStance_t stance; // ? not confirmed
	FxEffectDef_t *viewFlashEffect;
	FxEffectDef_t *worldFlashEffect;
	snd_alias_list_t *pickupSound;
	snd_alias_list_t *ammoPickupSound;
	snd_alias_list_t *projectileSound;
	snd_alias_list_t *pullbackSound;
	snd_alias_list_t *fireSound;
	snd_alias_list_t *fireSoundPlayer;
	snd_alias_list_t *unknown4[4];
	snd_alias_list_t *fireLastSound;
	snd_alias_list_t *fireLastSoundPlayer;
	snd_alias_list_t *meleeSwipeSound;
	snd_alias_list_t *rechamberSound;
	snd_alias_list_t *rechamberSoundPlayer;
	snd_alias_list_t *reloadSound;
	snd_alias_list_t *reloadSoundPlayer;
	snd_alias_list_t *reloadEmptySound;
	snd_alias_list_t *reloadEmptySoundPlayer;
	snd_alias_list_t *reloadStartSound;
	snd_alias_list_t *reloadStartSoundPlayer;
	snd_alias_list_t *reloadEndSound;
	snd_alias_list_t *reloadEndSoundPlayer;
	snd_alias_list_t *altSwitchSound;
	snd_alias_list_t *raiseSound;
	snd_alias_list_t *putawaySound;
	snd_alias_list_t *noteTrackSoundA;
	snd_alias_list_t *noteTrackSoundB;
	snd_alias_list_t *noteTrackSoundC;
	snd_alias_list_t *noteTrackSoundD;
	FxEffectDef_t *shellEjectEffect;
	FxEffectDef_t *lastShotEjectEffect;
	Material_t *reticleCenter;
	Material_t *reticleSide;
	int iReticleCenterSize;
	int iReticleSideSize;
	int iReticleMinOfs;
	float vStandMove[3];
	float vStandRot[3];
	float vDuckedOfs[3];
	float vDuckedMove[3];
	float vDuckedRot[3];
	float vProneOfs[3];
	float vProneMove[3];
	float vProneRot[3];
	float fPosMoveRate;
	float fPosProneMoveRate;
	float fStandMoveMinSpeed;
	float fDuckedMoveMinSpeed;
	float fProneMoveMinSpeed;
	float fPosRotRate;
	float fPosProneRotRate;
	float fStandRotMinSpeed;
	float fDuckedRotMinSpeed;
	float fProneRotMinSpeed;
	const char *worldModel;
	Material_t *hudIcon;
	Material_t *modeIcon;
	int iStartAmmo;
	const char *szAmmoName;
	int iAmmoIndex;
	const char *szClipName;
	int iClipIndex;
	int iMaxAmmo;
	int iClipSize;
	int shotCount;
	const char *szSharedAmmoCapName;
	int iSharedAmmoCapIndex;
	int iSharedAmmoCap;
	int damage;
	int playerDamage;
	int iMeleeDamage;
	int iDamageType;
	int iFireDelay;
	int iMeleeDelay;
	int iFireTime;
	int iRechamberTime;
	int iRechamberBoltTime;
	int iHoldFireTime;
	int iMeleeTime;
	int iReloadTime;
	int iReloadEmptyTime;
	int iReloadAddTime;
	int iReloadStartTime;
	int iReloadStartAddTime;
	int iReloadEndTime;
	int iDropTime;
	int iRaiseTime;
	int iAltDropTime;
	int iAltRaiseTime;
	int quickDropTime;
	int quickRaiseTime;
	int fuseTime;
	float autoAimRange;
	float aimAssistRange;
	float aimAssistRangeAds;
	float aimPadding;
	float enemyCrosshairRange;
	int crosshairColorChange;
	float moveSpeedScale;
	float fAdsZoomFov;
	float fAdsZoomInFrac;
	float fAdsZoomOutFrac;
	Material_t *overlayMaterial;
	weapOverlayReticle_t overlayReticle;
	float overlayWidth;
	float overlayHeight;
	float fAdsBobFactor;
	float fAdsViewBobMult;
	float fHipSpreadStandMin;
	float fHipSpreadDuckedMin;
	float fHipSpreadProneMin;
	float hipSpreadStandMax;
	float hipSpreadDuckedMax;
	float hipSpreadProneMax;
	float fHipSpreadDecayRate;
	float fHipSpreadFireAdd;
	float fHipSpreadTurnAdd;
	float fHipSpreadMoveAdd;
	float fHipSpreadDuckedDecay;
	float fHipSpreadProneDecay;
	float fHipReticleSidePos;
	int iAdsTransInTime;
	int iAdsTransOutTime;
	float fAdsIdleAmount;
	float fHipIdleAmount;
	float adsIdleSpeed;
	float hipIdleSpeed;
	float fIdleCrouchFactor;
	float fIdleProneFactor;
	float fGunMaxPitch;
	float fGunMaxYaw;
	float swayMaxAngle;
	float swayLerpSpeed;
	float swayPitchScale;
	float swayYawScale;
	float swayHorizScale;
	float swayVertScale;
	float swayShellShockScale;
	float adsSwayMaxAngle;
	float adsSwayLerpSpeed;
	float adsSwayPitchScale;
	float adsSwayYawScale;
	float adsSwayHorizScale;
	float adsSwayVertScale;
	int bRifleBullet;
	int armorPiercing;
	int semiAuto;
	int bBoltAction;
	int aimDownSight;
	int bRechamberWhileAds;
	float adsViewErrorMin;
	float adsViewErrorMax;
	int bCookOffHold;
	int bClipOnly;
	int cancelAutoHolsterWhenEmpty; // ?
	int suppressAmmoReserveDisplay; // ?
	Material_t *killIcon;
	weaponIconRatioType_t killIconRatio; // ?
	int flipKillIcon;
	int bNoPartialReload;
	int bSegmentedReload;
	int iReloadAmmoAdd;
	int iReloadStartAdd;
	const char *szAltWeaponName;
	uint altWeaponIndex;
	int iDropAmmoMin;
	int iDropAmmoMax;
	int iExplosionRadius;
	int iExplosionInnerDamage;
	int iExplosionOuterDamage;
	int iProjectileSpeed;
	int iProjectileSpeedUp;
	const char *projectileModel;
	weapProjExposion_t projExplosion;
	FxEffectDef_t *projExplosionEffect;
	snd_alias_list_t *projExplosionSound;
	int bProjImpactExplode;
	float parallelBounce[23];
	float perpendicularBounce[23];
	FxEffectDef_t *projTrailEffect;
	int unknown2[4];
	float fAdsAimPitch;
	float fAdsCrosshairInFrac;
	float fAdsCrosshairOutFrac;
	int adsGunKickReducedKickBullets;
	float adsGunKickReducedKickPercent;
	float fAdsGunKickPitchMin;
	float fAdsGunKickPitchMax;
	float fAdsGunKickYawMin;
	float fAdsGunKickYawMax;
	float fAdsGunKickAccel;
	float fAdsGunKickSpeedMax;
	float fAdsGunKickSpeedDecay;
	float fAdsGunKickStaticDecay;
	float fAdsViewKickPitchMin;
	float fAdsViewKickPitchMax;
	float fAdsViewKickYawMin;
	float fAdsViewKickYawMax;
	float fAdsViewKickCenterSpeed;
	float fAdsViewScatterMin;
	float fAdsViewScatterMax;
	float fAdsSpread;
	int hipGunKickReducedKickBullets;
	float hipGunKickReducedKickPercent;
	float fHipGunKickPitchMin;
	float fHipGunKickPitchMax;
	float fHipGunKickYawMin;
	float fHipGunKickYawMax;
	float fHipGunKickAccel;
	float fHipGunKickSpeedMax;
	float fHipGunKickSpeedDecay;
	float fHipGunKickStaticDecay;
	float fHipViewKickPitchMin;
	float fHipViewKickPitchMax;
	float fHipViewKickYawMin;
	float fHipViewKickYawMax;
	float fHipViewKickCenterSpeed;
	float fHipViewScatterMin;
	float fHipViewScatterMax;
	float fightDist;
	float maxDist;
	const char *aiVsAiAccuracyGraph;
	const char *aiVsPlayerAccuracyGraph;
	int accuracyGraphKnotCount[2];
	int originalAccuracyGraphKnotCount[2];
	int iPositionReloadTransTime;
	float leftArc;
	float rightArc;
	float topArc;
	float bottomArc;
	float accuracy;
	float aiSpread;
	float playerSpread;
	int minVertTurnSpeed;
	int minHorTurnSpeed;
	int maxVertTurnSpeed;
	int maxHorTurnSpeed;
	float pitchConvergenceTime;
	float yawConvergenceTime;
	float suppressTime;
	float maxRange;
	float fAnimHorRotateInc;
	float fPlayerPositionDist;
	const char *szUseHintString;
	const char *dropHintString;
	int iUseHintStringIndex;
	int dropHintStringIndex;
	float horizViewJitter;
	float vertViewJitter;
	const char *szScript;
	float fOOPosAnimLength[2];
	int minDamage;
	int minPlayerDamage;
	float fMaxDamageRange;
	float fMinDamageRange;
	int unknown5[4];
	float locationDamageMultipliers[19];
	const char *fireRumble;
	const char *meleeImpactRumble;
} WeaponDef_t;

typedef enum
{
	ANIM_BP_UNUSED,
	ANIM_BP_LEGS,
	ANIM_BP_TORSO,
	ANIM_BP_BOTH,
	NUM_ANIM_BODYPARTS
} animBodyPart_t;

typedef enum
{
	IT_BAD,
	IT_WEAPON,
	IT_AMMO,
	IT_HEALTH,
	IT_HOLDABLE,
} itemType_t;

typedef struct gitem_s
{
	char *classname; // ??? They don't set classname or what? Other fields work fine.
	char *pickup_sound;
	char *world_model;
	int giTag; // ?
	char *icon;
	char *display_name; // Weapon string e.g WEAPON_STEN
	int quantity; // ammo for weapons
	itemType_t giType;
	int giAmmoIndex;
	int giClipIndex;
	int giSharedAmmoCapIndex; // guessed
} gitem_t;

typedef struct XBoneInfo_s
{
	float bounds[2][3];
	float offset[3];
	float radiusSquared;
} XBoneInfo_t;

typedef struct XModelCollSurf_s
{
	float mins[3];
	float maxs[3];
	int boneIdx;
	int contents;
	int surfFlags;
} XModelCollSurf_t;

typedef struct XModelHighMipBounds_s
{
	float mins[3];
	float maxs[3];
} XModelHighMipBounds_t;

typedef struct XModelStreamInfo_s
{
	XModelHighMipBounds_t *highMipBounds;
} XModelStreamInfo_t;

typedef struct XModel_s
{
	char numBones;
	char numRootBones;
	u_int16_t *boneNames;
	char *parentList;
	byte unk[72];
	XModelCollSurf_t *collSurfs; // 84
	int numCollSurfs; // 88
	int contents; // 92
	XBoneInfo_t *boneInfo; // 96
	vec3_t mins; // 100
	vec3_t maxs;
	short numLods; // 124
	short collLod;
	XModelStreamInfo_t streamInfo; // 128
	int memUsage; // 132
	const char *name; // 136
	char flags; // 140
	char bad; // 141
} XModel_t;

typedef struct DObjSkeletonPartMatrix_s
{
	float p1[4];
	float p2[4];
} DObjSkeletonPartMatrix_t;

typedef struct DSkelPartBits_s
{
	int anim[4];
	int control[4];
	int skel[4];
} DSkelPartBits_t;

typedef struct DSkel_s
{
	DSkelPartBits_t *partBits;
	int timeStamp;
	DObjSkeletonPartMatrix_t *mat;
} DSkel_t;

typedef struct DObj_s
{
	int *tree;
	DSkel_t skel;
	unsigned short duplicateParts; // 16
	int unk2;
	byte numModels; // 24
	byte numBones; // 25
	byte duplicatePartsSize; // 26
	byte pad;
	XModel_t *models; // 28
} DObj_t;

typedef struct
{
	short emptystring;
	short allies;
	short axis;
	short current;
	short damage;
	short death;
	short dlight;
	short done;
	short empty;
	short entity;
	short failed;
	short fraction;
	short goal;
	short grenade;
	short info_notnull;
	short invisible;
	short key1;
	short key2;
	short killanimscript;
	short left;
	short movedone;
	short noclass;
	short normal;
	short pistol;
	short plane_waypoint;
	short player;
	short position;
	short primary;
	short primaryb;
	short prone;
	short right;
	short rocket;
	short rotatedone;
	short script_brushmodel;
	short script_model;
	short script_origin;
	short spectator;
	short stand;
	short surfacetype;
	short target_script_trigger;
	short tempEntity;
	short touch;
	short trigger;
	short trigger_use;
	short trigger_use_touch;
	short trigger_damage;
	short trigger_lookat;
	short truck_cam;
	short worldspawn;
	short binocular_enter;
	short binocular_exit;
	short binocular_fire;
	short binocular_release;
	short binocular_drop;
	short begin;
	short intermission;
	short menuresponse;
	short playing;
	short none;
	short dead;
	short auto_change;
	short manual_change;
	short freelook;
	short call_vote;
	short vote;
	short snd_enveffectsprio_level;
	short snd_enveffectsprio_shellshock;
	short snd_channelvolprio_holdbreath;
	short snd_channelvolprio_pain;
	short snd_channelvolprio_shellshock;
	short tag_flash;
	short tag_flash_11;
	short tag_flash_2;
	short tag_flash_22;
	short tag_brass;
	short j_head;
	short tag_weapon;
	short tag_player;
	short tag_camera;
	short tag_aim;
	short tag_aim_animated;
	short tag_origin;
	short tag_butt;
	short tag_weapon_right;
	short back_low;
	short back_mid;
	short back_up;
	short neck;
	short head;
	short pelvis;
} stringIndex_t;

#define	SVF_NOCLIENT  0x00000001
#define	SVF_BROADCAST 0x00000008

#define KEY_MASK_NONE        	0

#define KEY_MASK_FORWARD        127
#define KEY_MASK_BACK           -127
#define KEY_MASK_MOVERIGHT      127
#define KEY_MASK_MOVELEFT       -127

#define KEY_MASK_FIRE           1
#define KEY_MASK_MELEE          4
#define KEY_MASK_USE            8
#define KEY_MASK_RELOAD         16
#define KEY_MASK_LEANLEFT       64
#define KEY_MASK_LEANRIGHT      128
#define KEY_MASK_PRONE          256
#define KEY_MASK_CROUCH         512
#define KEY_MASK_JUMP           1024
#define KEY_MASK_ADS_MODE       4096
#define KEY_MASK_MELEE_BREATH   32772
#define KEY_MASK_HOLDBREATH     32768
#define KEY_MASK_FRAG           65536
#define KEY_MASK_SMOKE          131072

#define EF_VOTED 0x00100000
#define EF_TALK 0x00200000
#define EF_TAUNT 0x00400000
#define EF_FIRING 0x00000020
#define EF_MANTLE 0x00004000
#define EF_CROUCHING 0x00000004
#define EF_PRONE 0x00000008
#define EF_DEAD 0x00020000
#define EF_USETURRET 0x00000300
#define EF_AIMDOWNSIGHT 0x00040000

#define PMF_MANTLE 4
#define PMF_LADDER 32

#define CONTENTS_SOLID          1
#define CONTENTS_NONCOLLIDING   4
#define CONTENTS_LAVA           8
#define CONTENTS_WATER          0x20
#define CONTENTS_CANSHOTCLIP    0x40
#define CONTENTS_MISSILECLIP    0x80
#define CONTENTS_VEHICLECLIP	0x200
#define CONTENTS_ITEMCLIP       0x400
#define CONTENTS_SKY            0x800
#define CONTENTS_AI_NOSIGHT     0x1000
#define CONTENTS_CLIPSHOT       0x2000
#define CONTENTS_MOVER          0x4000
#define CONTENTS_PLAYERCLIP     0x10000
#define CONTENTS_MONSTERCLIP    0x20000
#define CONTENTS_TELEPORTER     0x40000
#define CONTENTS_JUMPPAD        0x80000
#define CONTENTS_CLUSTERPORTAL  0x100000
#define CONTENTS_DONOTENTER     0x200000
#define CONTENTS_DONOTENTER_LARGE 0x400000

#define CONTENTS_MANTLE         0x1000000
#define CONTENTS_DETAIL         0x8000000
#define CONTENTS_STRUCTURAL     0x10000000
#define CONTENTS_TRANSPARENT    0x20000000
#define CONTENTS_NODROP         0x80000000

#define CONTENTS_BODY           0x2000000
#define CONTENTS_TRIGGER        0x40000000

#define SURF_NOLIGHTMAP         0x0
#define SURF_NODAMAGE           0x1
#define SURF_SLICK              0x2
#define SURF_SKY                0x4
#define SURF_LADDER             0x8
#define SURF_NOIMPACT           0x10
#define SURF_NOMARKS            0x20
#define SURF_NODRAW             0x80
#define SURF_NOSTEPS            0x2000
#define SURF_NONSOLID           0x4000
#define SURF_NODLIGHT           0x20000
#define SURF_NOCASTSHADOW       0x40000
#define SURF_MANTLEON           0x2000000
#define SURF_MANTLEOVER         0x4000000
#define SURF_PORTAL             0x80000000

#define SURF_BARK               0x100000
#define SURF_BRICK              0x200000
#define SURF_CARPET             0x300000
#define SURF_CLOTH              0x400000
#define SURF_CONCRETE           0x500000
#define SURF_DIRT               0x600000
#define SURF_FLESH              0x700000
#define SURF_FOLIAGE            0x800000
#define SURF_GLASS              0x900000
#define SURF_GRASS              0xa00000
#define SURF_GRAVEL             0xb00000
#define SURF_ICE                0xc00000
#define SURF_METAL              0xd00000
#define SURF_MUD                0xe00000
#define SURF_PAPER              0xf00000
#define SURF_PLASTER            0x1000000
#define SURF_ROCK               0x1100000
#define SURF_SAND               0x1200000
#define SURF_SNOW               0x1300000
#define SURF_WATER              0x1400000
#define SURF_WOOD               0x1500000
#define SURF_ASPHALT            0x1600000

#define TOOL_OCCLUDER           0x1
#define TOOL_DRAWTOGGLE         0x2
#define TOOL_ORIGIN             0x4
#define TOOL_RADIALNORMALS      0x8

#define MASK_ALL                ( -1 )
#define MASK_SOLID              ( CONTENTS_SOLID )
#define MASK_PLAYERSOLID        ( CONTENTS_SOLID | CONTENTS_PLAYERCLIP | CONTENTS_BODY )
#define MASK_DEADSOLID          ( CONTENTS_SOLID | CONTENTS_PLAYERCLIP )
#define MASK_WATER              ( CONTENTS_WATER | CONTENTS_LAVA | CONTENTS_SLIME )
#define MASK_OPAQUE             ( CONTENTS_SOLID | CONTENTS_LAVA )
#define MASK_SHOT               ( CONTENTS_SOLID | CONTENTS_BODY | CONTENTS_CORPSE )
#define MASK_MISSILESHOT        ( MASK_SHOT | CONTENTS_MISSILECLIP )

static const int gentities_offset = 0x08716400;
static const int gclients_offset = 0x087A2500;

#define g_entities ((gentity_t*)(gentities_offset))
#define g_clients ((gclient_t*)(gclients_offset))

static const int varpub_offset = 0x08397500;
static const int varglob_offset = 0x08297500;
static const int vmpub_offset = 0x083D8A80;
static const int sv_offset = 0x08440200;
static const int svs_offset = 0x08423080;
static const int level_offset = 0x0864C380;
static const int const_offset = 0x08853220;

#define scrVarPub (*((scrVarPub_t*)( varpub_offset )))
#define scrVmPub (*((scrVmPub_t*)( vmpub_offset )))
#define scrVarGlob (((VariableValueInternal*)( varglob_offset )))
#define scrVarGlob_high (((VariableValueInternal*)( varglob_offset + 16 * 32770 )))
#define sv (*((server_t*)( sv_offset )))
#define svs (*((serverStatic_t*)( svs_offset )))
#define level (*((level_locals_t*)( level_offset )))
#define scr_const (*((stringIndex_t*)( const_offset )))

// Check for critical structure sizes and fail if not match
#if __GNUC__ >= 6
static_assert((sizeof(client_t) == 0xB1064), "ERROR: client_t size is invalid!");
static_assert((sizeof(gentity_t) == 560), "ERROR: gentity_t size is invalid!");
static_assert((sizeof(gclient_t) == 0x28A4), "ERROR: gclient_t size is invalid!");
static_assert((sizeof(gitem_t) == 44), "ERROR: gitem_t size is invalid!");
static_assert((sizeof(XModel_t) == 144), "ERROR: XModel_t size is invalid!");
#endif

#endif
