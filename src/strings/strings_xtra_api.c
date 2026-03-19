// Module: strings
// Topic: Xtra API wrappers - context resolution and dispatching to internal functions
// Address range: 0x6816f0b0 - 0x6816fff0
// Functions (60):
//   strings_wrapGetApiContext
//   strings_wrapGetApiState
//   strings_wrapGetContextState
//   strings_wrapCreateRect
//   strings_wrapStoreIntValue
//   strings_wrapStoreObjectRef
//   strings_wrapStoreFloatDirect
//   strings_wrapLoadStringValue
//   strings_wrapGetExtPair
//   strings_wrapCoerceAndStore
//   strings_wrapStoreFloatValue
//   strings_wrapComputeValue
//   strings_wrapConvertDate
//   strings_wrapStoreSymbolRef
//   strings_xtraQueryInterface
//   strings_xtraSetProperty
//   strings_xtraGetBuildInfo
//   strings_getXtraVersion
//   strings_xtraGetEncoding
//   strings_xtraGetOS
//   strings_xtraGetPlatform
//   strings_xtraGetAppInfo
//   strings_xtraShowDialogW
//   strings_xtraShowDialog
//   strings_xtraSetCallback
//   strings_xtraGetVersion
//   strings_xtraGetValue
//   strings_xtraReadByte
//   strings_xtraWriteByte
//   strings_xtraGetProperty
//   strings_xtraGetText
//   strings_xtraCreateTimer
//   strings_wrapReadScoreSlot
//   strings_wrapGetCastInfo
//   strings_wrapGetCastProperty
//   strings_wrapSetCastProperty
//   strings_wrapSetXtraProperty
//   strings_wrapResolveScript
//   strings_wrapGetScriptFormat
//   strings_wrapResolveFormat
//   strings_wrapGetFormatProperty
//   strings_wrapResolveMedia
//   strings_wrapGetMediaRef
//   strings_wrapSetMediaRef
//   strings_wrapGetMediaFormat
//   strings_wrapCreateListValue
//   strings_wrapPopScoreSlot
//   strings_wrapGetScoreContext
//   strings_wrapSetScoreContext
//   strings_wrapGetListEntry
//   strings_wrapSetListEntry
//   strings_wrapGetListCount
//   strings_wrapAppendListEntry
//   strings_wrapInsertListEntry
//   strings_wrapDeleteListEntry
//   strings_wrapFindListEntry
//   strings_wrapSortList
//   strings_wrapGetListProperty
//   strings_wrapSetListProperty
//   strings_wrapGetPropListEntry

// ============================================================
// Function: strings_wrapGetApiContext (FUN_6816f0b0)
// Address: 6816f0b0
// Size: 55 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetApiContext(undefined4 param_1,uint *param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getApiContext(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapGetApiState (FUN_6816f0f0)
// Address: 6816f0f0
// Size: 51 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetApiState(undefined4 param_1,int *param_2)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getApiState(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapGetContextState (FUN_6816f130)
// Address: 6816f130
// Size: 55 bytes
// Params: undefined4 param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetContextState(undefined4 param_1,uint *param_2)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getContextState(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapCreateRect (FUN_6816f170)
// Address: 6816f170
// Size: 55 bytes
// Params: undefined4 param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapCreateRect(undefined4 param_1,uint *param_2)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_createRect(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapStoreIntValue (FUN_6816f1b0)
// Address: 6816f1b0
// Size: 55 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapStoreIntValue(undefined4 param_1,undefined4 param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_storeIntValue(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapStoreObjectRef (FUN_6816f1f0)
// Address: 6816f1f0
// Size: 55 bytes
// Params: undefined4 param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapStoreObjectRef(undefined4 param_1,int param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_storeObjectRef(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapStoreFloatDirect (FUN_6816f230)
// Address: 6816f230
// Size: 60 bytes
// Params: undefined4 param_1, double param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapStoreFloatDirect(undefined4 param_1,double param_2,int *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_storeFloatDirect(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapLoadStringValue (FUN_6816f270)
// Address: 6816f270
// Size: 55 bytes
// Params: undefined4 param_1, char * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapLoadStringValue(undefined4 param_1,char *param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_loadStringValue(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapGetExtPair (FUN_6816f2b0)
// Address: 6816f2b0
// Size: 55 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetExtPair(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getExtPair(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapCoerceAndStore (FUN_6816f2f0)
// Address: 6816f2f0
// Size: 55 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapCoerceAndStore(undefined4 param_1,uint *param_2,int *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_coerceAndStore(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapStoreFloatValue (FUN_6816f330)
// Address: 6816f330
// Size: 55 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapStoreFloatValue(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_storeFloatValue(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapComputeValue (FUN_6816f370)
// Address: 6816f370
// Size: 59 bytes
// Params: undefined4 param_1, uint param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapComputeValue(undefined4 param_1,uint param_2,undefined4 param_3,undefined4 *param_4)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_computeValue(local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_wrapConvertDate (FUN_6816f3b0)
// Address: 6816f3b0
// Size: 55 bytes
// Params: undefined4 param_1, uint * param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapConvertDate(undefined4 param_1,uint *param_2,uint *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_convertDateToTime(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapStoreSymbolRef (FUN_6816f3f0)
// Address: 6816f3f0
// Size: 55 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapStoreSymbolRef(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_storeSymbolRef(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_xtraQueryInterface (FUN_6816f430)
// Address: 6816f430
// Size: 55 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_xtraQueryInterface(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_queryInterface(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_xtraSetProperty (FUN_6816f470)
// Address: 6816f470
// Size: 20 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_xtraSetProperty(undefined4 param_1,int *param_2,undefined4 *param_3)
{
  mediaPlayback_copyMovieStateData(param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_xtraGetBuildInfo (FUN_6816f490)
// Address: 6816f490
// Size: 43 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_xtraGetBuildInfo(void)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  return 0x800407d0;
}



// ============================================================
// Function: strings_getXtraVersion (FUN_6816f4c0)
// Address: 6816f4c0
// Size: 36 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_getXtraVersion(void)

{
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  return 0x800407d0;
}



// ============================================================
// Function: strings_xtraGetEncoding (FUN_6816f4f0)
// Address: 6816f4f0
// Size: 43 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_xtraGetEncoding(void)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  return 0x800407d0;
}



// ============================================================
// Function: strings_xtraGetOS (FUN_6816f520)
// Address: 6816f520
// Size: 41 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_xtraGetOS(void)

{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  return 0xffffffff;
}



// ============================================================
// Function: strings_xtraGetPlatform (FUN_6816f550)
// Address: 6816f550
// Size: 50 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_xtraGetPlatform(void)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  lingo_resolveContext(&local_20,&local_1c,&local_18,&local_14,&local_10,&local_c,&local_8);
  return 0x800407d0;
}



// ============================================================
// Function: strings_xtraGetAppInfo (FUN_6816f5a0)
// Address: 6816f5a0
// Size: 50 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_xtraGetAppInfo(void)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  lingo_resolveContext(&local_20,&local_1c,&local_18,&local_14,&local_10,&local_c,&local_8);
  return 0x800407d0;
}



// ============================================================
// Function: strings_xtraShowDialogW (FUN_6816f5e0)
// Address: 6816f5e0
// Size: 52 bytes
// Params: undefined4 param_1, HINSTANCE param_2, LPCWSTR param_3, DLGPROC param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_xtraShowDialogW(undefined4 param_1,HINSTANCE param_2,LPCWSTR param_3,DLGPROC param_4)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  crt_showDialogW(&local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_xtraShowDialog (FUN_6816f620)
// Address: 6816f620
// Size: 56 bytes
// Params: undefined4 param_1, HINSTANCE param_2, LPCSTR param_3, DLGPROC param_4, LPARAM param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_xtraShowDialog(undefined4 param_1,HINSTANCE param_2,LPCSTR param_3,DLGPROC param_4,LPARAM param_5
                 )
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  crt_showDialogA(&local_8,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: strings_xtraSetCallback (FUN_6816f660)
// Address: 6816f660
// Size: 44 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_xtraSetCallback(undefined4 param_1,undefined4 param_2)
{
  int param_4;
  int _local_8;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  crt_invokeMediaCallback(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_xtraGetVersion (FUN_6816f690)
// Address: 6816f690
// Size: 44 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_xtraGetVersion(void)
{
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  crt_invokeMediaCallbackEx(local_8);
  return 0;
}



// ============================================================
// Function: strings_xtraGetValue (FUN_6816f6c0)
// Address: 6816f6c0
// Size: 48 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_xtraGetValue(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  crt_getDialogOwner(&local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_xtraReadByte (FUN_6816f6f0)
// Address: 6816f6f0
// Size: 48 bytes
// Params: undefined4 param_1, undefined1 * param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_xtraReadByte(undefined4 param_1,undefined1 *param_2,undefined1 *param_3)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_convertRgbToPalette(&local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_xtraWriteByte (FUN_6816f720)
// Address: 6816f720
// Size: 48 bytes
// Params: undefined4 param_1, undefined1 param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_xtraWriteByte(undefined4 param_1,undefined1 param_2,undefined1 *param_3)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_convertPaletteToRgb(&local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_xtraGetProperty (FUN_6816f750)
// Address: 6816f750
// Size: 98 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_xtraGetProperty(undefined4 param_1,uint *param_2,int *param_3)

{
  undefined4 uVar1;
  short local_c;
  short local_a;
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  uVar1 = cast_getXtraProperty(local_8,param_2,(int *)&local_c);
  *param_3 = (int)local_c;
  param_3[1] = (int)local_a;
  if (local_c == -1) {
    uVar1 = 0x80040001;
  }
  score_resetPropertyCache(local_8);
  return uVar1;
}



// ============================================================
// Function: strings_xtraGetText (FUN_6816f7c0)
// Address: 6816f7c0
// Size: 88 bytes
// Params: undefined4 param_1, undefined2 * param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_xtraGetText(undefined4 param_1,undefined2 *param_2,undefined4 param_3)

{
    int _local_8; /* FIXUP(C2065): missing Ghidra variable declaration */
  undefined4 uVar1;
  short local_8;
  undefined2 local_6;
  
  _local_8 = CONCAT22(param_2[2],*param_2);
  param_2 = (undefined2 *)0x0;
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)&param_2,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  uVar1 = cast_getScoreXtraData((int)param_2,&local_8);
  score_resetPropertyCache((int)param_2);
  return uVar1;
}



// ============================================================
// Function: strings_xtraCreateTimer (FUN_6816f820)
// Address: 6816f820
// Size: 78 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 * param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
strings_xtraCreateTimer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  undefined4 *puVar1;
  
  puVar1 = param_7;
  param_7[2] = param_4;
  *param_7 = param_2;
  param_7[1] = param_3;
  param_7[3] = param_5;
  param_7[4] = param_6;
  param_7 = (undefined4 *)0x0;
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)&param_7,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  puVar1[5] = 0;
  return 0;
}



// ============================================================
// Function: strings_wrapReadScoreSlot (FUN_6816f870)
// Address: 6816f870
// Size: 47 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapReadScoreSlot(undefined4 param_1,int param_2)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_readScoreSlot(param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapGetCastInfo (FUN_6816f8a0)
// Address: 6816f8a0
// Size: 50 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetCastInfo(undefined4 param_1,int *param_2)
{
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  mediaPlayback_createXtraInstance(0,local_8,0,0,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapGetCastProperty (FUN_6816f8e0)
// Address: 6816f8e0
// Size: 67 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapGetCastProperty(undefined4 param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  void *local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)&local_8,(int *)0x0,(int *)0x0);
  if (param_2 != (int *)0x0) {
    uVar1 = media_registerXtraDefault(local_8,param_3,param_2);
    return uVar1;
  }
  return 0x80040001;
}



// ============================================================
// Function: strings_wrapSetCastProperty (FUN_6816f930)
// Address: 6816f930
// Size: 48 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapSetCastProperty(undefined4 param_1,int *param_2,int param_3)
{
  int *local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)&local_8,(int *)0x0,(int *)0x0);
  media_unregisterXtraDefault(local_8,param_3,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapSetXtraProperty (FUN_6816f960)
// Address: 6816f960
// Size: 82 bytes
// Params: undefined4 param_1, uint * param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapSetXtraProperty(undefined4 param_1,uint *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  int local_c;
  undefined2 local_8 [2];
  
  local_c = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  uVar1 = cast_setXtraPropertyEx(local_c,param_2,local_8);
  *param_3 = local_8[0];
  score_resetPropertyCache(local_c);
  return uVar1;
}



// ============================================================
// Function: strings_wrapResolveScript (FUN_6816f9c0)
// Address: 6816f9c0
// Size: 73 bytes
// Params: undefined4 param_1, short * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_wrapResolveScript(undefined4 param_1,short *param_2,int *param_3)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = cast_resolveScriptProperty(local_8,*param_2,param_3);
  score_resetPropertyCache(local_8);
  return iVar1;
}



// ============================================================
// Function: strings_wrapGetScriptFormat (FUN_6816fa10)
// Address: 6816fa10
// Size: 82 bytes
// Params: undefined4 param_1, uint * param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapGetScriptFormat(undefined4 param_1,uint *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  int local_c;
  undefined2 local_8 [2];
  
  local_c = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  uVar1 = cast_getScriptFormatProperty(local_c,param_2,local_8);
  *param_3 = local_8[0];
  score_resetPropertyCache(local_c);
  return uVar1;
}



// ============================================================
// Function: strings_wrapResolveFormat (FUN_6816fa70)
// Address: 6816fa70
// Size: 73 bytes
// Params: undefined4 param_1, short * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_wrapResolveFormat(undefined4 param_1,short *param_2,int *param_3)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = cast_resolveFormatProperty(local_8,*param_2,param_3);
  score_resetPropertyCache(local_8);
  return iVar1;
}



// ============================================================
// Function: strings_wrapGetFormatProperty (FUN_6816fac0)
// Address: 6816fac0
// Size: 82 bytes
// Params: undefined4 param_1, uint * param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapGetFormatProperty(undefined4 param_1,uint *param_2,undefined2 *param_3)

{
  undefined4 uVar1;
  int local_c;
  undefined2 local_8 [2];
  
  local_c = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  uVar1 = cast_getFormatProperty(local_c,param_2,local_8);
  *param_3 = local_8[0];
  score_resetPropertyCache(local_c);
  return uVar1;
}



// ============================================================
// Function: strings_wrapResolveMedia (FUN_6816fb20)
// Address: 6816fb20
// Size: 73 bytes
// Params: undefined4 param_1, undefined2 * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_wrapResolveMedia(undefined4 param_1,undefined2 *param_2,int *param_3)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = cast_resolveMediaProperty(local_8,*param_2,param_3);
  score_resetPropertyCache(local_8);
  return iVar1;
}



// ============================================================
// Function: strings_wrapGetMediaRef (FUN_6816fb70)
// Address: 6816fb70
// Size: 70 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapGetMediaRef(undefined4 param_1,uint *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  uVar1 = props_validateMediaRef(local_8,param_2,param_3);
  score_resetPropertyCache(local_8);
  return uVar1;
}



// ============================================================
// Function: strings_wrapSetMediaRef (FUN_6816fbc0)
// Address: 6816fbc0
// Size: 70 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapSetMediaRef(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  uVar1 = props_storeMediaRef(local_8,param_2,param_3);
  score_resetPropertyCache(local_8);
  return uVar1;
}



// ============================================================
// Function: strings_wrapGetMediaFormat (FUN_6816fc10)
// Address: 6816fc10
// Size: 70 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_wrapGetMediaFormat(undefined4 param_1,uint *param_2,int *param_3)

{
  undefined4 uVar1;
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  uVar1 = props_coerceToShort(local_8,param_2,param_3);
  score_resetPropertyCache(local_8);
  return uVar1;
}



// ============================================================
// Function: strings_wrapCreateListValue (FUN_6816fc60)
// Address: 6816fc60
// Size: 70 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_wrapCreateListValue(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = props_storeSymbolValue(local_8,param_2,param_3);
  score_resetPropertyCache(local_8);
  return iVar1;
}



// ============================================================
// Function: strings_wrapPopScoreSlot (FUN_6816fcb0)
// Address: 6816fcb0
// Size: 51 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapPopScoreSlot(undefined4 param_1,int *param_2)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getPropertyIndexBA(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapGetScoreContext (FUN_6816fcf0)
// Address: 6816fcf0
// Size: 55 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetScoreContext(undefined4 param_1,uint *param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  props_dispatchMethod(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapSetScoreContext (FUN_6816fd30)
// Address: 6816fd30
// Size: 51 bytes
// Params: undefined4 param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapSetScoreContext(undefined4 param_1,uint *param_2)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  props_resolveRef(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapGetListEntry (FUN_6816fd70)
// Address: 6816fd70
// Size: 59 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetListEntry(undefined4 param_1,uint *param_2,undefined4 param_3,int *param_4)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_callMethodChecked(local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_wrapSetListEntry (FUN_6816fdb0)
// Address: 6816fdb0
// Size: 59 bytes
// Params: undefined4 param_1, uint * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapSetListEntry(undefined4 param_1,uint *param_2,int param_3,undefined4 *param_4)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_storeByIndexDA(local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_wrapGetListCount (FUN_6816fdf0)
// Address: 6816fdf0
// Size: 51 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetListCount(undefined4 param_1,int *param_2)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getPropertyIndexBB(local_8,param_2);
  return 0;
}



// ============================================================
// Function: strings_wrapAppendListEntry (FUN_6816fe30)
// Address: 6816fe30
// Size: 59 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapAppendListEntry(undefined4 param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_dispatchTripleByCD(local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_wrapInsertListEntry (FUN_6816fe70)
// Address: 6816fe70
// Size: 59 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapInsertListEntry(undefined4 param_1,uint *param_2,undefined4 *param_3,int *param_4)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getPropertyByD4(local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_wrapDeleteListEntry (FUN_6816feb0)
// Address: 6816feb0
// Size: 59 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapDeleteListEntry(undefined4 param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_setPropertyTriple(local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_wrapFindListEntry (FUN_6816fef0)
// Address: 6816fef0
// Size: 59 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapFindListEntry(undefined4 param_1,uint *param_2,undefined4 param_3,int *param_4)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getPropertyConditional(local_8,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: strings_wrapSortList (FUN_6816ff30)
// Address: 6816ff30
// Size: 55 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapSortList(undefined4 param_1,int *param_2,int *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getScriptMember(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapGetListProperty (FUN_6816ff70)
// Address: 6816ff70
// Size: 55 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetListProperty(undefined4 param_1,int *param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_setScriptMember(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapSetListProperty (FUN_6816ffb0)
// Address: 6816ffb0
// Size: 55 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapSetListProperty(undefined4 param_1,int *param_2,int *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_getMediaMember(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_wrapGetPropListEntry (FUN_6816fff0)
// Address: 6816fff0
// Size: 55 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_wrapGetPropListEntry(undefined4 param_1,int *param_2,undefined4 *param_3)
{
  int local_8;
  
  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_setMediaMember(local_8,param_2,param_3);
  return 0;
}



