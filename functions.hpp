#ifndef _FUNCTIONS_HPP_
#define _FUNCTIONS_HPP_

/* MAKE FUNCTIONS STATIC, SO THEY CAN BE IN EVERY FILE */

typedef unsigned int (*GetVariableName_t)(unsigned int a1);
static const GetVariableName_t GetVariableName = (GetVariableName_t)0x0807D0C2;

typedef unsigned int (*GetNextVariable_t)(unsigned int a1);
static const GetNextVariable_t GetNextVariable = (GetNextVariable_t)0x0807D01E;

typedef int (*GetArraySize_t)(unsigned int a1);
static const GetArraySize_t GetArraySize = (GetArraySize_t)0x0807CFFC;

typedef int (*GetVarType_t)(unsigned int a1);
static const GetVarType_t GetVarType = (GetVarType_t)0x0807E5CC;

typedef short (*BigShort_t)(short l);
static const BigShort_t BigShort = (BigShort_t)0x080B7572;

typedef char * (*SL_ConvertToString_t)(unsigned int index);
static const SL_ConvertToString_t SL_ConvertToString = (SL_ConvertToString_t)0x08078EE6;

typedef int (*Scr_GetFunctionHandle_t)(const char* scriptName, const char* labelName, int isNeeded);
static const Scr_GetFunctionHandle_t Scr_GetFunctionHandle = (Scr_GetFunctionHandle_t)0x08110208;

typedef char * (*Cmd_Argv_t)(int arg);
static const Cmd_Argv_t Cmd_Argv = (Cmd_Argv_t)0x08060220;

typedef int (*Cmd_Argc_t)();
static const Cmd_Argc_t Cmd_Argc = (Cmd_Argc_t)0x080601E0;

typedef int (*Scr_GetNumParam_t)(void);
static const Scr_GetNumParam_t Scr_GetNumParam = (Scr_GetNumParam_t)0x08085136;

typedef void (*SV_Cmd_ArgvBuffer_t)(int arg, char *buffer, int bufferLength);
static const SV_Cmd_ArgvBuffer_t SV_Cmd_ArgvBuffer = (SV_Cmd_ArgvBuffer_t)0x08060278;

typedef void (*Com_Printf_t)(const char *format, ...);
static const Com_Printf_t Com_Printf = (Com_Printf_t)0x08060DEA;

typedef void (*Com_DPrintf_t)(const char *format, ...);
static const Com_DPrintf_t Com_DPrintf = (Com_DPrintf_t)0x08060E3A;

typedef int (*Com_sprintf_t)(char *dest, int size, const char *format, ...);
static const Com_sprintf_t Com_sprintf = (Com_sprintf_t)0x080B7F0A;

typedef void (*Cmd_ExecuteString_t)(const char *cmd);
static const Cmd_ExecuteString_t Cmd_ExecuteString = (Cmd_ExecuteString_t)0x080609CC;

typedef void (*ClientCommand_t)(int clientNum);
static const ClientCommand_t ClientCommand = (ClientCommand_t)0x08100E62;

typedef int (*FS_ReadFile_t)(const char *qpath, void **buffer);
static const FS_ReadFile_t FS_ReadFile = (FS_ReadFile_t)0x080A0A9C;

typedef void (*FS_LoadDir_t)(char *path, char *dir);
static const FS_LoadDir_t FS_LoadDir = (FS_LoadDir_t)0x080A241C;

typedef xfunction_t (*Scr_GetFunction_t)(const char** v_functionName, qboolean* v_developer);
static const Scr_GetFunction_t Scr_GetFunction = (Scr_GetFunction_t)0x08117CB2;

typedef xmethod_t (*Scr_GetMethod_t)(const char** v_methodName, qboolean* v_developer);
static const Scr_GetMethod_t Scr_GetMethod = (Scr_GetMethod_t)0x08117DEA;

typedef void (*Cvar_SetString_t)(cvar_t* var, char const* string);
static const Cvar_SetString_t Cvar_SetString = (Cvar_SetString_t)0x080B4A80;

typedef cvar_t* (*Cvar_FindVar_t)(const char *var_name);
static const Cvar_FindVar_t Cvar_FindVar = (Cvar_FindVar_t)0x080B2ED8;

typedef cvar_t* (*Cvar_RegisterBool_t)(const char *var_name, qboolean var_value, unsigned short flags);
static const Cvar_RegisterBool_t Cvar_RegisterBool = (Cvar_RegisterBool_t)0x080B3FD2;

typedef cvar_t* (*Cvar_RegisterString_t)(const char *var_name, const char *var_value, unsigned short flags);
static const Cvar_RegisterString_t Cvar_RegisterString = (Cvar_RegisterString_t)0x080B4232;

typedef void (*SV_ConnectionlessPacket_t)(netadr_t from, msg_t *msg);
static const SV_ConnectionlessPacket_t SV_ConnectionlessPacket = (SV_ConnectionlessPacket_t)0x0809594E;

typedef void (*NET_OutOfBandPrint_t)(netsrc_t net_socket, netadr_t adr, const char *format, ...);
static const NET_OutOfBandPrint_t NET_OutOfBandPrint = (NET_OutOfBandPrint_t)0x0806C8CC;

typedef void (*SV_GameSendServerCommand_t)(int clientnum, int svscmd_type, const char *text);
static const SV_GameSendServerCommand_t SV_GameSendServerCommand = (SV_GameSendServerCommand_t)0x080917AA;

typedef void (*SV_DropClient_t)(client_t *drop, const char *reason);
static const SV_DropClient_t SV_DropClient = (SV_DropClient_t)0x0808F02E;

typedef void (*ClientUserinfoChanged_t)(int clientNum);
static const ClientUserinfoChanged_t ClientUserinfoChanged = (ClientUserinfoChanged_t)0x080F8C5E;

typedef int (*SV_ClientHasClientMuted_t)(int clientnum, int mutedclientnum);
static const SV_ClientHasClientMuted_t SV_ClientHasClientMuted = (SV_ClientHasClientMuted_t)0x0809C1FA;

typedef void (*Info_SetValueForKey_t)(char *s, const char *key, const char *value);
static const Info_SetValueForKey_t Info_SetValueForKey = (Info_SetValueForKey_t)0x080B85CE;

typedef char* (*Info_ValueForKey_t)(const char *s, const char *key);
static const Info_ValueForKey_t Info_ValueForKey = (Info_ValueForKey_t)0x080B8108;

typedef short (*Scr_ExecThread_t)(int callbackHook, unsigned int numArgs);
static const Scr_ExecThread_t Scr_ExecThread = (Scr_ExecThread_t)0x08083FD6;

typedef short (*Scr_ExecEntThread_t)(gentity_t* ent, int callbackHook, unsigned int numArgs);
static const Scr_ExecEntThread_t Scr_ExecEntThread = (Scr_ExecEntThread_t)0x0811B284;

typedef short (*Scr_FreeThread_t)(short thread_id);
static const Scr_FreeThread_t Scr_FreeThread = (Scr_FreeThread_t)0x080841D6;

typedef void (*SV_GetChallenge_t)(netadr_t from);
static const SV_GetChallenge_t SV_GetChallenge = (SV_GetChallenge_t)0x0808D18E;

typedef void (*SVC_Info_t)(netadr_t from);
static const SVC_Info_t SVC_Info = (SVC_Info_t)0x0809537C;

typedef void (*SVC_Status_t)(netadr_t from);
static const SVC_Status_t SVC_Status = (SVC_Status_t)0x08094C84;

typedef const char* (*NET_AdrToString_t)(netadr_t a);
static const NET_AdrToString_t NET_AdrToString = (NET_AdrToString_t)0x0806B1D4;

typedef qboolean (*NET_StringToAdr_t)(char *s, netadr_t *a);
static const NET_StringToAdr_t NET_StringToAdr = (NET_StringToAdr_t)0x0806CD98;

typedef void (*Scr_Error_t)(const char *string);
static const Scr_Error_t Scr_Error = (Scr_Error_t)0x080853FC;

typedef int (*Sys_MilliSeconds_t)(void);
static const Sys_MilliSeconds_t Sys_MilliSeconds = (Sys_MilliSeconds_t)0x080D5D98;

typedef int (*G_FindConfigstringIndex_t)(const char *name, int start, int max, qboolean create, const char *fieldname);
static const G_FindConfigstringIndex_t G_FindConfigstringIndex = (G_FindConfigstringIndex_t)0x0811D300;

typedef const char * (*SV_GetConfigstringConst_t)(int index);
static const SV_GetConfigstringConst_t SV_GetConfigstringConst = (SV_GetConfigstringConst_t)0x08092A1C;

typedef void (*SV_SetConfigstring_t)(int index, const char *val);
static const SV_SetConfigstring_t SV_SetConfigstring = (SV_SetConfigstring_t)0x08092780;

typedef void * (*Z_MallocInternal_t)(int size);
static const Z_MallocInternal_t Z_MallocInternal = (Z_MallocInternal_t)0x080AB65E;

typedef int (*FS_Read_t)(void *buffer, int len, fileHandle_t f);
static const FS_Read_t FS_Read = (FS_Read_t)0x080A052A;

typedef void (*MSG_Init_t)(msg_t *buf, byte *data, int length);
static const MSG_Init_t MSG_Init = (MSG_Init_t)0x08067BD8;

typedef void (*MSG_WriteByte_t)(msg_t *msg, int c);
static const MSG_WriteByte_t MSG_WriteByte = (MSG_WriteByte_t)0x0806800C;

typedef void (*MSG_WriteShort_t)(msg_t *msg, int c);
static const MSG_WriteShort_t MSG_WriteShort = (MSG_WriteShort_t)0x0806809A;

typedef void (*MSG_WriteLong_t)(msg_t *msg, int c);
static const MSG_WriteLong_t MSG_WriteLong = (MSG_WriteLong_t)0x080680EA;

typedef void (*MSG_WriteString_t)(msg_t *msg, const char *s);
static const MSG_WriteString_t MSG_WriteString = (MSG_WriteString_t)0x080681A4;

typedef void (*MSG_WriteData_t)(msg_t *buf, const void *data, int length);
static const MSG_WriteData_t MSG_WriteData = (MSG_WriteData_t)0x08068044;

typedef long (*FS_SV_FOpenFileRead_t)(const char *filename, fileHandle_t *fp);
static const FS_SV_FOpenFileRead_t FS_SV_FOpenFileRead = (FS_SV_FOpenFileRead_t)0x08064558;

typedef int (*FS_iwIwd_t)(const char *a1, const char *a2);
static const FS_iwIwd_t FS_iwIwd = (FS_iwIwd_t)0x08065324;

typedef signed int (*SV_WWWRedirectClient_t)(client_t *cl, msg_t *msg);
static const SV_WWWRedirectClient_t SV_WWWRedirectClient = (SV_WWWRedirectClient_t)0x0808FC0C;

typedef WeaponDef_t * (*BG_WeaponDefs_t)(unsigned int weaponIndex);
static const BG_WeaponDefs_t BG_WeaponDefs = (BG_WeaponDefs_t)0x080EB9A4;

typedef int (*BG_GetNumWeapons_t)(void);
static const BG_GetNumWeapons_t BG_GetNumWeapons = (BG_GetNumWeapons_t)0x080EBA56;

typedef signed int (*sub_80E9758_t)(int a1);
static const sub_80E9758_t sub_80E9758 = (sub_80E9758_t)0x080EBE8C;

typedef int (*sub_80D9E84_t)(int a1, signed int a2);
static const sub_80D9E84_t sub_80D9E84 = (sub_80D9E84_t)0x080DC5A8;

typedef int (*BG_AnimationIndexForString_t)(char *src);
static const BG_AnimationIndexForString_t BG_AnimationIndexForString = (BG_AnimationIndexForString_t)0x080D6DD0;

typedef int (*Sys_IsLANAddress_t)(netadr_t adr);
static const Sys_IsLANAddress_t Sys_IsLANAddress = (Sys_IsLANAddress_t)0x080D5638;

typedef int (*Scr_IsSystemActive_t)();
static const Scr_IsSystemActive_t Scr_IsSystemActive = (Scr_IsSystemActive_t)0x08084678;

typedef int (*Sys_GetValue_t)(int key);
static const Sys_GetValue_t Sys_GetValue = (Sys_GetValue_t)0x080D6BC0;

typedef void (*Scr_AddBool_t)(qboolean);
static const Scr_AddBool_t Scr_AddBool = (Scr_AddBool_t)0x08085140;

typedef void (*Scr_AddInt_t)(int value);
static const Scr_AddInt_t Scr_AddInt = (Scr_AddInt_t)0x08085164;

typedef void (*Scr_AddFloat_t)(float);
static const Scr_AddFloat_t Scr_AddFloat = (Scr_AddFloat_t)0x08085188;

typedef void (*Scr_AddString_t)(const char *string);
static const Scr_AddString_t Scr_AddString = (Scr_AddString_t)0x08085262;

typedef void (*Scr_AddUndefined_t)(void);
static const Scr_AddUndefined_t Scr_AddUndefined = (Scr_AddUndefined_t)0x080851D0;

typedef void (*Scr_AddVector_t)(vec3_t vec);
static const Scr_AddVector_t Scr_AddVector = (Scr_AddVector_t)0x08085306;

typedef void (*Scr_AddEntity_t)(gentity_t* ent);
static const Scr_AddEntity_t Scr_AddEntity = (Scr_AddEntity_t)0x08117F50;

typedef void (*Scr_MakeArray_t)(void);
static const Scr_MakeArray_t Scr_MakeArray = (Scr_MakeArray_t)0x08085338;

typedef void (*Scr_AddArray_t)(void);
static const Scr_AddArray_t Scr_AddArray = (Scr_AddArray_t)0x08085364;

typedef void (*Scr_AddObject_t)(unsigned int object);
static const Scr_AddObject_t Scr_AddObject = (Scr_AddObject_t)0x080851EA;

typedef gentity_t * (*G_TempEntity_t)(vec3_t origin, int event);
static const G_TempEntity_t G_TempEntity = (G_TempEntity_t)0x0811EFC4;

typedef int (*DirToByte_t)(vec3_t dir);
static const DirToByte_t DirToByte = (DirToByte_t)0x080A3F8E;

typedef void (*G_LocationalTrace_t)(trace_t *results, const vec3_t start, const vec3_t end, int passEntityNum, int contentmask);
static const G_LocationalTrace_t G_LocationalTrace = (G_LocationalTrace_t)0x0810A5CC;

typedef void (*G_AddEvent_t)(gentity_t *ent, int event, int eventParm);
static const G_AddEvent_t G_AddEvent = (G_AddEvent_t)0x0811F232;

typedef void (*G_AddPredictableEvent_t)(gentity_t *ent, int event, int eventParm);
static const G_AddPredictableEvent_t G_AddPredictableEvent = (G_AddPredictableEvent_t)0x0811F1FC;

typedef playerState_t * (*SV_GameClientNum_t)(int num);
static const SV_GameClientNum_t SV_GameClientNum = (SV_GameClientNum_t)0x08091716;

typedef gentity_t * (*SV_GentityNum_t)(int num);
static const SV_GentityNum_t SV_GentityNum = (SV_GentityNum_t)0x080916F8;

typedef gentity_t * (*SV_ClientThink_t)(client_t *cl, usercmd_t *);
static const SV_ClientThink_t SV_ClientThink = (SV_ClientThink_t)0x08090DAC;

typedef void (*G_LogPrintf_t)(const char *fmt, ...);
static const G_LogPrintf_t G_LogPrintf = (G_LogPrintf_t)0x08109992;

typedef char * (*I_strlwr_t)(char *s1);
static const I_strlwr_t I_strlwr = (I_strlwr_t)0x080B7D14;

typedef char * (*I_strupr_t)(char *s1);
static const I_strupr_t I_strupr = (I_strupr_t)0x080B7D56;

typedef gentity_t * (*G_Spawn_t)(void);
static const G_Spawn_t G_Spawn = (G_Spawn_t)0x0811E9D6;

typedef void (*SV_LinkEntity_t)(gentity_t *ent);
static const SV_LinkEntity_t SV_LinkEntity = (SV_LinkEntity_t)0x0809C63A;

typedef void (*SV_UnlinkEntity_t)(gentity_t *ent);
static const SV_UnlinkEntity_t SV_UnlinkEntity = (SV_UnlinkEntity_t)0x0809C596;

typedef void (*SV_SetBrushModel_t)(gentity_t *ent);
static const SV_SetBrushModel_t SV_SetBrushModel = (SV_SetBrushModel_t)0x08091858;

typedef void (*Scr_SetString_t)(unsigned short *strindexptr, unsigned const stringindex);
static const Scr_SetString_t Scr_SetString = (Scr_SetString_t)0x08079DE0;

typedef gitem_t * (*BG_FindItemForWeapon_t)(unsigned int weaponIndex);
static const BG_FindItemForWeapon_t BG_FindItemForWeapon = (BG_FindItemForWeapon_t)0x080DF20A;

typedef XModel_t * (*SV_XModelGet_t)(const char *name);
static const SV_XModelGet_t SV_XModelGet = (SV_XModelGet_t)0x08091E48;

typedef XModel_t * (*SV_XModelForIndex_t)(unsigned int modelIndex);
static const SV_XModelForIndex_t SV_XModelForIndex = (SV_XModelForIndex_t)0x0811D588;

typedef qboolean (*SV_DObjExists_t)(gentity_t *ent);
static const SV_DObjExists_t SV_DObjExists = (SV_DObjExists_t)0x0809236E;

typedef DObj_t * (*Com_GetServerDObj_t)(int entNum);
static const Com_GetServerDObj_t Com_GetServerDObj = (Com_GetServerDObj_t)0x08062BC4;

typedef void (*SV_DObjDumpInfo_t)(gentity_t *ent);
static const SV_DObjDumpInfo_t SV_DObjDumpInfo = (SV_DObjDumpInfo_t)0x08091E98;

typedef qboolean (*DObjSkelExists_t)(DObj_t *dobj, int skelTimeStamp);
static const DObjSkelExists_t DObjSkelExists = (DObjSkelExists_t)0x080BA97A;

typedef void (*BG_EvaluateTrajectory_t)(const trajectory_t *tr, int atTime, vec3_t result);
static const BG_EvaluateTrajectory_t BG_EvaluateTrajectory = (BG_EvaluateTrajectory_t)0x080DF5D4;

#endif
