// Module: lingo
// Topic: API wrapper functions for COM/vtable dispatch
// Address range: 0x6809B9B0 - 0x6809CD00
// Functions (65):
//   lingo_invokeVtable
//   lingo_getXtraState
//   lingo_getXtraRef
//   lingo_closeXtra
//   lingo_openXtra
//   lingo_getXtraInfo
//   lingo_getXtraList
//   lingo_resolveXtraInterface
//   lingo_getNetData
//   lingo_getNetStatus
//   lingo_getNetResult
//   lingo_dispatchNetOp
//   lingo_setCallArgs
//   lingo_getCallArgs
//   lingo_getCallResult
//   lingo_dispatchCallEx
//   lingo_apiCallFunc
//   lingo_apiAlloc
//   lingo_apiFree
//   lingo_apiDebugPrint
//   lingo_apiBreak
//   lingo_apiResume
//   lingo_apiGetSymbol
//   lingo_apiSetSymbol
//   lingo_apiGetGlobal
//   lingo_apiSetGlobal
//   lingo_apiGetLocal
//   lingo_apiSetLocal
//   lingo_apiGetMember
//   lingo_apiSetMember
//   lingo_apiDeleteMember
//   lingo_apiGetHandler
//   lingo_getRegistrationState
//   lingo_apiRegisterHandler
//   lingo_apiGetCast
//   lingo_apiSetCast
//   lingo_apiDeleteCast
//   lingo_apiGetSprite
//   lingo_apiSetSprite
//   lingo_apiGetChannel
//   lingo_apiSetChannel
//   lingo_apiGetFrame
//   lingo_apiSetFrame
//   lingo_apiGetScore
//   lingo_apiSetScore
//   lingo_apiGetMovie
//   lingo_apiSetMovie
//   lingo_apiGetAppInfo
//   lingo_apiGetBuildInfo
//   lingo_apiGetEncoding
//   lingo_apiGetOS
//   lingo_apiSetPropValue
//   lingo_apiGetPropValue
//   lingo_apiGetText
//   lingo_apiShowDialogW
//   lingo_apiShowDialog
//   lingo_apiWriteByte
//   lingo_apiReadByte
//   lingo_noop (FUN_6809cb50)
//   lingo_apiCreateTimer
//   lingo_apiSetProperty
//   lingo_apiGetProperty
//   lingo_apiGetPlatform
//   lingo_apiSetCallback
//   lingo_apiQueryInterface


// ============================================================
// Function: lingo_invokeVtable (FUN_6809b9b0)
// Address: 6809b9b0
// Size: 69 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_invokeVtable(undefined4 param_1)

{
  int local_14;
  undefined4 *in_EAX;
  int iVar1;
  
  iVar1 = (**(code **)*in_EAX)();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(iRam00000000 + 0xc))(0,param_1);
    (**(code **)(iRam00000000 + 8))(0);
  }
  return iVar1;
}



// ============================================================
// Function: lingo_getXtraState (FUN_6809ba00)
// Address: 6809ba00
// Size: 69 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_getXtraState(undefined4 param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  
  iVar1 = (**(code **)*in_EAX)();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(iRam00000000 + 0xc))(0,param_1);
    (**(code **)(iRam00000000 + 8))(0);
  }
  return iVar1;
}



// ============================================================
// Function: lingo_getXtraRef (FUN_6809ba50)
// Address: 6809ba50
// Size: 30 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getXtraRef(undefined4 param_1,undefined4 *param_2)
{
  if ((param_2 != (undefined4 *)0x0) && ((code *)*param_2 != (code *)0x0)) {
    (*(code *)*param_2)(param_1,param_2[1]);
  }
  return 0;
}



// ============================================================
// Function: lingo_closeXtra (FUN_6809ba70)
// Address: 6809ba70
// Size: 124 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, int param_4, undefined2 * param_5, int * param_6, uint param_7
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_closeXtra(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined2 *param_5,
                int *param_6,uint param_7)

{
  int iVar1;
  int local_14 [4];
  
  if (param_4 == 0) {
    if (param_3 == 0) {
      iVar1 = -0x7ffbffff;
    }
    else {
      iVar1 = lingo_invokeVtable(&param_4);
      if (iVar1 == 0) {
        iVar1 = media_getMediaTypeData(param_2,&param_4,0,param_5,param_6,param_7);
        return iVar1;
      }
    }
  }
  else {
    iVar1 = lingo_getXtraState(local_14);
    if (iVar1 == 0) {
      iVar1 = media_getMediaTypeData(param_2,local_14,(int)local_14,param_5,param_6,param_7);
      return iVar1;
    }
  }
  return iVar1;
}



// ============================================================
// Function: lingo_openXtra (FUN_6809baf0)
// Address: 6809baf0
// Size: 161 bytes
// Params: undefined4 param_1, int param_2, int param_3, int * param_4, int * param_5, int * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_openXtra(undefined4 param_1,int param_2,int param_3,int *param_4,int *param_5,int *param_6)

{
  int iVar1;
  
  if (param_2 == 0) {
    return 0x80040001;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  if (param_6 != (int *)0x0) {
    *param_6 = -1;
  }
  if (param_3 == -1) {
    if (param_6 == (int *)0x0) {
      return 0x80040001;
    }
    iVar1 = Ordinal_17(param_2,0);
    *param_6 = iVar1;
    return 0;
  }
  iVar1 = crt_readChunkRange(param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    return 0x80040c1c;
  }
  if (param_6 != (int *)0x0) {
    iVar1 = crt_findNextChunk(param_2,0,param_3);
    if (iVar1 == 0) {
      iVar1 = -1;
    }
    *param_6 = iVar1;
  }
  return 0;
}



// ============================================================
// Function: lingo_getXtraInfo (FUN_6809bba0)
// Address: 6809bba0
// Size: 121 bytes
// Params: undefined4 param_1, int param_2, int param_3, undefined4 * param_4, undefined4 * param_5, int * param_6, int * param_7
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_getXtraInfo(undefined4 param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5,
                int *param_6,int *param_7)

{
  short sVar1;
  int iVar2;
  
  if (param_2 == 0) {
    return -0x7ffbffff;
  }
  *param_5 = 0;
  if (param_6 != (int *)0x0) {
    *param_6 = 0;
  }
  if (param_7 != (int *)0x0) {
    *param_7 = 0;
  }
  iVar2 = crt_readChunkRange(param_2,param_3,param_6,param_7);
  if (iVar2 != 0) {
    return -0x7ffbf3e4;
  }
  sVar1 = crt_getChunkShortField(param_2);
  strings_initMediaWriter(param_4,param_2,(int)sVar1);
  iVar2 = media_queryXtraMethod(param_4,param_3,0,param_5);
  return iVar2;
}



// ============================================================
// Function: lingo_getXtraList (FUN_6809bc20)
// Address: 6809bc20
// Size: 104 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined2 * param_3, undefined4 param_4, undefined4 * param_5, undefined4 * param_6, undefined4 * param_7
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_getXtraList(undefined4 param_1,undefined4 param_2,undefined2 *param_3,undefined4 param_4,
                undefined4 *param_5,undefined4 *param_6,undefined4 *param_7)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = param_7;
  puVar1 = param_6;
  if (param_6 != (undefined4 *)0x0) {
    *param_6 = 0;
  }
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = 0;
  }
  if (param_5 == (undefined4 *)0x0) {
    return -0x7ffbffff;
  }
  *param_5 = 0;
  iVar3 = lingo_invokeVtable(&param_6);
  if (iVar3 == 0) {
    iVar3 = media_openSoundStream((int *)&param_6,param_3,param_4,(int)param_5,puVar1,puVar2);
  }
  return iVar3;
}



// ============================================================
// Function: lingo_resolveXtraInterface (FUN_6809bc90)
// Address: 6809bc90
// Size: 58 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined2 * param_3, undefined4 * param_4, undefined4 * param_5, undefined4 * param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_resolveXtraInterface(undefined4 param_1,undefined4 param_2,undefined2 *param_3,undefined4 *param_4,
                undefined4 *param_5,undefined4 *param_6)

{
  int iVar1;
  
  iVar1 = lingo_invokeVtable(&param_2);
  if (iVar1 == 0) {
    iVar1 = media_getSoundData(&param_2,param_3,param_4,param_5,param_6);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



// ============================================================
// Function: lingo_getNetData (FUN_6809bcd0)
// Address: 6809bcd0
// Size: 40 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getNetData(void)
{
  int iVar1;
  undefined2 *in_stack_00000010;
  int *in_stack_00000014;
  
  iVar1 = lingo_invokeVtable(&stack0x00000008);
  if (iVar1 == 0) {
    media_writeSoundStream((int *)&stack0x00000008,in_stack_00000010,in_stack_00000014);
  }
  return 0;
}



// ============================================================
// Function: lingo_getNetStatus (FUN_6809bd00)
// Address: 6809bd00
// Size: 24 bytes
// Params: undefined4 param_1, int * param_2, uint param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getNetStatus(undefined4 param_1,int *param_2,uint param_3,int *param_4)
{
  display_loadFileBlock(param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: lingo_getNetResult (FUN_6809bd20)
// Address: 6809bd20
// Size: 92 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_getNetResult(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = Ordinal_1306();
  if (iVar1 == 2) {
    Ordinal_1305(0);
  }
  uVar2 = media_getPixelFilterRef(&local_8,param_2,param_3,param_4,param_5);
  if (iVar1 == 2) {
    Ordinal_1305(2);
  }
  return uVar2;
}



// ============================================================
// Function: lingo_dispatchNetOp (FUN_6809bd80)
// Address: 6809bd80
// Size: 328 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5, int param_6, int param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int lingo_dispatchNetOp(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,int param_6,int param_7)
{
  int iVar1;
  int local_1888;
  undefined4 local_1884 [5];
  undefined4 local_1870;
  undefined4 local_186c;
  undefined4 local_1868;
  undefined4 local_1864;
  undefined4 local_1440;
  undefined1 local_143c [1024];
  undefined1 local_103c [3100];
  undefined4 local_420;
  undefined1 local_41c [1044];
  uint local_8;
  
  local_420 = 0;
  memset(local_41c,0,0x414);
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_1888,(int *)0x0,(int *)0x0);
  if (local_1888 != 0) {
    iVar1 = Ordinal_1309(&local_420,0x400,param_2,2);
    if (iVar1 != 0) {
      iVar1 = lingo_mutateData(*(undefined4 **)(local_1888 + 4),&local_420,local_1884);
      if (iVar1 != 0) {
        if (param_3 != (undefined4 *)0x0) {
          *param_3 = local_1884[0];
        }
        if (param_4 != (undefined4 *)0x0) {
          param_4[1] = local_1870;
          param_4[3] = local_1868;
          *param_4 = local_186c;
          param_4[2] = local_1864;
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = local_1440;
        }
        if (param_6 != 0) {
          Ordinal_1232(param_6,local_143c);
        }
        if (param_7 != 0) {
          Ordinal_1232(param_7,local_103c);
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_setCallArgs (FUN_6809bed0)
// Address: 6809bed0
// Size: 80 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_setCallArgs(undefined4 param_1,uint *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int local_c;
  byte local_5;
  
  local_5 = 0;
  uVar1 = 0;
  local_c = 0;
  crt_checkInternetState(&local_c);
  if (local_c == 1) {
    local_5 = 1;
  }
  else if (local_c != 2) goto LAB_6809befe;
  uVar1 = 1;
LAB_6809befe:
  if (param_2 != (uint *)0x0) {
    *param_2 = (uint)local_5;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar1;
  }
  return 0;
}



// ============================================================
// Function: lingo_getCallArgs (FUN_6809bf20)
// Address: 6809bf20
// Size: 65 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getCallArgs(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  
  *param_3 = 0;
  if (param_2 == 0) {
    return 0x80040001;
  }
  iVar1 = crt_getChunkCount(param_2);
  if (iVar1 != 0) {
    iVar1 = crt_truncateHandle(iVar1);
    *param_3 = iVar1;
    if (iVar1 == 0) {
      return 0x80040002;
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_getCallResult (FUN_6809bf70)
// Address: 6809bf70
// Size: 28 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getCallResult(undefined4 param_1,int *param_2)
{
  if (*param_2 != 0) {
    score_freePropertyHandle(*param_2);
  }
  *param_2 = 0;
  return 0;
}



// ============================================================
// Function: lingo_dispatchCallEx (FUN_6809bf90)
// Address: 6809bf90
// Size: 111 bytes
// Params: undefined4 param_1, int * param_2, int param_3, undefined4 param_4, int param_5, int param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_dispatchCallEx(undefined4 param_1,int *param_2,int param_3,undefined4 param_4,int param_5,
                int param_6)

{
  int iVar1;
  int iVar2;
  
  iVar1 = crt_resolveFormat(param_2,param_3,param_5,&param_5);
  if (iVar1 != -1) {
    crt_getFormatState(param_2,param_5);
  }
  iVar1 = param_6;
  iVar2 = crt_resolveFormat(param_2,param_3,param_6,&param_5);
  if (iVar2 != -1) {
    crt_getFormatState(param_2,param_5);
  }
  iVar1 = crt_insertSortedEntry(param_2,param_5,param_4,param_3,iVar1);
  if (iVar1 != 0) {
    iVar1 = crt_allocCodecBlock(iVar1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: lingo_apiCallFunc (FUN_6809c000)
// Address: 6809c000
// Size: 67 bytes
// Params: undefined4 param_1, undefined4 * param_2, int param_3, int param_4, undefined4 param_5, int * param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_apiCallFunc(undefined4 param_1,undefined4 *param_2,int param_3,int param_4,undefined4 param_5,
                int *param_6)

{
  int iVar1;
  
  if (param_2 == (undefined4 *)0x0) {
    return -0x7ffbffff;
  }
  iVar1 = crt_readChunkFormatted(param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    iVar1 = crt_allocCodecBlock(iVar1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: lingo_apiAlloc (FUN_6809c050)
// Address: 6809c050
// Size: 46 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_apiAlloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = lingo_invokeVtable(&param_2);
  if (iVar1 == 0) {
    iVar1 = media_setCastScriptFlag(&param_2,(byte)param_3);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



// ============================================================
// Function: lingo_apiFree (FUN_6809c080)
// Address: 6809c080
// Size: 46 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_apiFree(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;

  iVar1 = lingo_invokeVtable(&param_2);
  if (iVar1 == 0) {
    iVar1 = media_setCastPreloadFlag(&param_2,(byte)param_3);
    if (iVar1 == 0) {
      iVar1 = 0;
    }
  }
  return iVar1;
}



// ============================================================
// Function: lingo_apiDebugPrint (FUN_6809c0b0)
// Address: 6809c0b0
// Size: 40 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiDebugPrint(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  Ordinal_1780(param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return 0;
}



// ============================================================
// Function: lingo_apiBreak (FUN_6809c0e0)
// Address: 6809c0e0
// Size: 16 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiBreak(undefined4 param_1,undefined4 param_2)
{
  Ordinal_1020(param_2);
  return 0;
}



// ============================================================
// Function: lingo_apiResume (FUN_6809c0f0)
// Address: 6809c0f0
// Size: 20 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiResume(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  Ordinal_1550(param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_apiGetSymbol (FUN_6809c110)
// Address: 6809c110
// Size: 42 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetSymbol(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5)

{
  int iVar1;
  
  iVar1 = Ordinal_1309(param_2,param_3,param_4,param_5);
  return (-(uint)(iVar1 != 0) & 0x7ffbffff) + 0x80040001;
}



// ============================================================
// Function: lingo_apiSetSymbol (FUN_6809c140)
// Address: 6809c140
// Size: 59 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 * param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_apiSetSymbol(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 *param_7)

{
  int iVar1;
  
  iVar1 = Ordinal_1333(param_2,param_3,param_4,param_5,param_6,&param_6);
  if (iVar1 != 0) {
    *param_7 = param_6;
    return 0;
  }
  return 0x800412e0;
}



// ============================================================
// Function: lingo_apiGetGlobal (FUN_6809c180)
// Address: 6809c180
// Size: 21 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetGlobal(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  short sVar1;
  
  sVar1 = Ordinal_1208(param_2,param_3);
  return (int)sVar1;
}



// ============================================================
// Function: lingo_apiSetGlobal (FUN_6809c1a0)
// Address: 6809c1a0
// Size: 95 bytes
// Params: undefined4 param_1, undefined4 * param_2, int * param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_apiSetGlobal(undefined4 param_1,undefined4 *param_2,int *param_3,int param_4)

{
  int iVar1;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_68176378,&local_8);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*local_8 + 0xc))(local_8,&param_2);
    if (iVar1 == 0) {
      iVar1 = media_delegateSoundChannel((int *)&param_2,param_3,param_4);
    }
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar1;
}



// ============================================================
// Function: lingo_apiGetLocal (FUN_6809c200)
// Address: 6809c200
// Size: 38 bytes
// Params: undefined4 param_1, int * param_2, int param_3, uint param_4, int param_5, byte * param_6, int * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetLocal(undefined4 param_1,int *param_2,int param_3,uint param_4,int param_5,byte *param_6
                 ,int *param_7)
{
  media_initScoreReader(param_2,param_3,param_4,param_5,param_6,param_7,'\0');
  return 0;
}



// ============================================================
// Function: lingo_apiSetLocal (FUN_6809c230)
// Address: 6809c230
// Size: 36 bytes
// Params: undefined4 param_1, int * param_2, int param_3, uint param_4, int param_5, byte * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiSetLocal(undefined4 param_1,int *param_2,int param_3,uint param_4,int param_5,byte *param_6
                 )
{
  media_initScoreReader(param_2,param_3,param_4,param_5,param_6,(int *)0x0,'\x01');
  return 0;
}



// ============================================================
// Function: lingo_apiGetMember (FUN_6809c260)
// Address: 6809c260
// Size: 95 bytes
// Params: undefined4 param_1, undefined4 * param_2, int param_3, void * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetMember(undefined4 param_1,undefined4 *param_2,int param_3,void *param_4)

{
  int iVar1;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_68176378,&local_8);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*local_8 + 0xc))(local_8,&param_2);
    if (iVar1 == 0) {
      iVar1 = media_delegateSoundPlayback(param_4,(int *)&param_2,param_3,(int)param_4);
    }
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar1;
}



// ============================================================
// Function: lingo_apiSetMember (FUN_6809c2c0)
// Address: 6809c2c0
// Size: 22 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiSetMember(undefined4 param_1,int *param_2,int *param_3)
{
  media_destroyScoreReader(param_2,param_3,'\x01');
  return 0;
}



// ============================================================
// Function: lingo_apiDeleteMember (FUN_6809c2e0)
// Address: 6809c2e0
// Size: 22 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiDeleteMember(undefined4 param_1,int *param_2)
{
  media_destroyScoreReader(param_2,(int *)&stack0x0000000c,'\0');
  return 0;
}



// ============================================================
// Function: lingo_apiGetHandler (FUN_6809c300)
// Address: 6809c300
// Size: 32 bytes
// Params: undefined4 param_1, uint * param_2, int param_3, int * param_4, uint param_5, int * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetHandler(undefined4 param_1,uint *param_2,int param_3,int *param_4,uint param_5,
                 int *param_6)
{
  media_delegateSoundCallback(param_2,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: lingo_getRegistrationState (FUN_6809c320)
// Address: 6809c320
// Size: 42 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getRegistrationState(void)
{
  int in_EAX;
  
  if ((in_EAX != 0) && (*(int *)(in_EAX + 0x20) != 0)) {
    media_getDataPtr(*(int **)(*(int *)(*(int *)(*(int *)(in_EAX + 0x20) + 4) + 8) + 4));
    return 0;
  }
  media_getDataPtr(*(int **)(iRam00000008 + 4));
  return 0;
}



// ============================================================
// Function: lingo_apiRegisterHandler (FUN_6809c350)
// Address: 6809c350
// Size: 55 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiRegisterHandler(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x18);
  if (iVar1 != 0) {
    Ordinal_2330();
    *param_2 = iVar1;
    param_2[2] = 0;
    param_2[1] = (int)DAT_68196374;
    DAT_68196374 = param_2;
  }
  return 0;
}



// ============================================================
// Function: lingo_apiGetCast (FUN_6809c390)
// Address: 6809c390
// Size: 37 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiGetCast(int param_1,int param_2)

{
  if (*(int *)(*(int *)(param_1 + 4) + 0x18) != 0) {
    DAT_68196374 = *(undefined4 *)(param_2 + 4);
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_apiSetCast (FUN_6809c3c0)
// Address: 6809c3c0
// Size: 53 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiSetCast(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = lingo_getRegistrationState();
  if (*(code **)(iVar1 + 0x4c) != (code *)0x0) {
    uVar2 = (**(code **)(iVar1 + 0x4c))(param_2);
    *(undefined4 *)(param_2 + 0xc) = uVar2;
    return 0;
  }
  *(undefined4 *)(param_2 + 0xc) = 0;
  return 0;
}



// ============================================================
// Function: lingo_apiDeleteCast (FUN_6809c400)
// Address: 6809c400
// Size: 40 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiDeleteCast(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = lingo_getRegistrationState();
  if (*(code **)(iVar1 + 0x50) != (code *)0x0) {
    (**(code **)(iVar1 + 0x50))(*(undefined4 *)(param_2 + 0xc),param_2);
  }
  return 0;
}



// ============================================================
// Function: lingo_apiGetSprite (FUN_6809c430)
// Address: 6809c430
// Size: 338 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4, short param_5, undefined4 * param_6, undefined1 * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetSprite(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,short param_5
                 ,undefined4 *param_6,undefined1 *param_7)
{
  undefined1 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_820;
  int local_81c;
  undefined4 *local_818;
  int local_814;
  int *local_810;
  undefined4 local_80c;
  undefined1 local_808 [1024];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_818 = param_6;
  local_81c = lingo_invokeVtable(&local_820);
  if (local_81c == 0) {
    if (local_820 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(local_820 + 0x20);
    }
    iVar3 = 0;
    if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
      iVar2 = local_820;
      if (local_820 == 0) {
        iVar2 = *piVar4;
      }
      if (piVar4[2] == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(piVar4[2] + 0xc);
      }
      Ordinal_2330();
      local_80c = 0;
      local_810 = DAT_68196374;
      DAT_68196374 = &local_814;
      local_814 = iVar2;
    }
    Ordinal_1233(local_808,param_3);
    if (param_4 == 0) {
      puVar1 = (undefined1 *)0x0;
    }
    else {
      Ordinal_1233(local_408,param_4);
      puVar1 = local_408;
    }
    iVar3 = events_closeCurrentMovie(iVar3,(int)local_808,(int)puVar1,param_5,local_818,&local_818);
    *param_7 = (*(unsigned char *)((char *)&local_818 + 0));
    if (iVar3 != 0) {
      local_81c = -0x7ffbffec;
    }
    if (piVar4 != (int *)0x0) {
      DAT_68196374 = local_810;
      Ordinal_2331();
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_apiSetSprite (FUN_6809c590)
// Address: 6809c590
// Size: 71 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_apiSetSprite(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = lingo_invokeVtable(&param_2);
  if (iVar1 == 0) {
    if ((param_2 == 0) || (*(int *)(param_2 + 0x20) == 0)) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(*(int *)(param_2 + 0x20) + 4);
    }
    scoreEngine_writePropertyEx(*(int *)(*(int *)(iVar2 + 4) + 0xc),param_3,param_4);
  }
  return iVar1;
}



// ============================================================
// Function: lingo_apiGetChannel (FUN_6809c5f0)
// Address: 6809c5f0
// Size: 176 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetChannel(undefined4 param_1,undefined4 param_2,int *param_3)
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = param_3;
  local_18 = lingo_invokeVtable(&local_20);
  if (local_18 == 0) {
    if (local_20 == 0) {
      piVar2 = (int *)0x0;
    }
    else {
      piVar2 = *(int **)(local_20 + 0x20);
    }
    uVar3 = 0;
    if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
      iVar1 = local_20;
      if (local_20 == 0) {
        iVar1 = *piVar2;
      }
      if (piVar2[2] == 0) {
        uVar3 = 0;
      }
      else {
        uVar3 = *(undefined4 *)(piVar2[2] + 0xc);
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
    events_destroyMovieContext(uVar3,local_1c);
    if (piVar2 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
  }
  return 0;
}



// ============================================================
// Function: lingo_apiSetChannel (FUN_6809c6a0)
// Address: 6809c6a0
// Size: 18 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiSetChannel(undefined4 param_1,undefined4 param_2)
{
  cast_allocHandle(param_2,0);
  return 0;
}



// ============================================================
// Function: lingo_apiGetFrame (FUN_6809c6c0)
// Address: 6809c6c0
// Size: 18 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetFrame(undefined4 param_1,undefined4 param_2)
{
  cast_allocHandle(param_2,1);
  return 0;
}



// ============================================================
// Function: lingo_apiSetFrame (FUN_6809c6e0)
// Address: 6809c6e0
// Size: 20 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiSetFrame(undefined4 param_1,int param_2)
{
  if (param_2 != 0) {
    cast_freeHandle(param_2);
  }
  return 0;
}



// ============================================================
// Function: lingo_apiGetScore (FUN_6809c700)
// Address: 6809c700
// Size: 26 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiGetScore(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = Ordinal_1116(param_2);
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: lingo_apiSetScore (FUN_6809c720)
// Address: 6809c720
// Size: 43 bytes
// Params: undefined4 param_1, uint param_2, undefined4 param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool lingo_apiSetScore(undefined4 param_1,uint param_2,undefined4 param_3)

{
  if (param_2 != 0) {
    cast_resizeHandle(param_2,param_3,0);
    return DAT_68195a8c == 0;
  }
  return false;
}



// ============================================================
// Function: lingo_apiGetMovie (FUN_6809c750)
// Address: 6809c750
// Size: 26 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiGetMovie(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = Ordinal_1114(param_2);
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: lingo_apiSetMovie (FUN_6809c770)
// Address: 6809c770
// Size: 20 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiSetMovie(undefined4 param_1,int param_2)
{
  if (param_2 != 0) {
    Ordinal_1115(param_2);
  }
  return 0;
}



// ============================================================
// Function: lingo_apiGetAppInfo (FUN_6809c7a0)
// Address: 6809c7a0
// Size: 16 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetAppInfo(undefined4 param_1,undefined4 param_2)
{
  Ordinal_1124(param_2);
  return 0;
}



// ============================================================
// Function: lingo_apiGetBuildInfo (FUN_6809c7b0)
// Address: 6809c7b0
// Size: 16 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetBuildInfo(undefined4 param_1,undefined4 param_2)
{
  Ordinal_1137(param_2);
  return 0;
}



// ============================================================
// Function: lingo_apiGetEncoding (FUN_6809c7c0)
// Address: 6809c7c0
// Size: 20 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetEncoding(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  Ordinal_1138(param_2,param_3);
  return 0;
}



// ============================================================
// Function: lingo_apiGetOS (FUN_6809c7e0)
// Address: 6809c7e0
// Size: 16 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetOS(undefined4 param_1,undefined4 param_2)
{
  Ordinal_1125(param_2);
  return 0;
}



// ============================================================
// Function: lingo_apiSetPropValue (FUN_6809c7f0)
// Address: 6809c7f0
// Size: 133 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined1 * param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_apiSetPropValue(undefined4 param_1,undefined4 param_2,undefined1 *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  switch(param_2) {
  case 0:
    uVar2 = 0;
    break;
  case 1:
    uVar2 = 1;
    break;
  case 2:
    uVar2 = 2;
    break;
  case 3:
    uVar2 = 3;
    break;
  case 4:
    uVar2 = 4;
    break;
  case 5:
    uVar2 = 5;
    break;
  case 6:
    uVar2 = 6;
    break;
  case 7:
    uVar2 = 7;
    break;
  case 8:
    uVar2 = 8;
    break;
  case 9:
    uVar2 = 9;
    break;
  case 10:
    uVar2 = 10;
    break;
  case 0xb:
    uVar2 = 0xb;
    break;
  default:
    return 0x80040013;
  }
  iVar1 = lingo_cleanupContext();
  uVar2 = media_applyPixelOp(iVar1,uVar2,param_3,param_4);
  return uVar2;
}



// ============================================================
// Function: lingo_apiGetPropValue (FUN_6809c8b0)
// Address: 6809c8b0
// Size: 50 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetPropValue(undefined4 param_1,undefined4 param_2,int *param_3)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_getChannelFontMap(&local_8,param_2,param_3,1);
  return 0;
}



// ============================================================
// Function: lingo_apiGetText (FUN_6809c8f0)
// Address: 6809c8f0
// Size: 54 bytes
// Params: undefined4 param_1, undefined2 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiGetText(undefined4 param_1,undefined2 param_2,undefined4 param_3,undefined4 param_4)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_getFontMapData(&local_8,param_2,param_3,param_4,1);
  return 0;
}



// ============================================================
// Function: lingo_apiShowDialogW (FUN_6809c930)
// Address: 6809c930
// Size: 64 bytes
// Params: undefined4 param_1, short param_2, undefined1 * param_3, undefined4 param_4, int * param_5, int param_6, int param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiShowDialogW(undefined4 param_1,short param_2,undefined1 *param_3,undefined4 param_4,
                 int *param_5,int param_6,int param_7)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_lookupFontRef(&local_8,param_2,param_3,param_4,param_5,param_6,param_7);
  return 0;
}



// ============================================================
// Function: lingo_apiShowDialog (FUN_6809c970)
// Address: 6809c970
// Size: 68 bytes
// Params: undefined4 param_1, short param_2, uint param_3, int * param_4, int param_5, undefined4 param_6, int param_7, void * param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiShowDialog(undefined4 param_1,short param_2,uint param_3,int *param_4,int param_5,
                 undefined4 param_6,int param_7,void *param_8)
{
  int local_8;
  
  lingo_resolveContext(&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  media_lookupFontName(&local_8,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  return 0;
}



// ============================================================
// Function: lingo_apiWriteByte (FUN_6809c9c0)
// Address: 6809c9c0
// Size: 193 bytes
// Params: undefined4 param_1, undefined4 * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_apiWriteByte(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 local_1c;
  int *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  piVar2 = param_3;
  local_8 = (int *)0x0;
  *param_3 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,(int *)&param_3,(int *)0x0,(int *)0x0);
  local_c = param_2[1];
  local_10 = *param_2;
  local_1c = 0;
  local_18 = param_3;
  local_14 = 1;
  uVar3 = Ordinal_1038(&DAT_68176418,&DAT_68175f68,piVar2);
  iVar4 = Ordinal_2063(uVar3);
  if ((iVar4 == 0) &&
     (iVar4 = (*(code *)**(undefined4 **)*piVar2)((undefined4 *)*piVar2,&DAT_68176428,&local_8),
     iVar4 == 0)) {
    iVar4 = (**(code **)(*local_8 + 0x10))(local_8,&local_1c);
    (**(code **)(*local_8 + 8))(local_8);
    if (iVar4 == 0) {
      return 0;
    }
  }
  piVar1 = (int *)*piVar2;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *piVar2 = 0;
  }
  return iVar4;
}



// ============================================================
// Function: lingo_apiReadByte (FUN_6809ca90)
// Address: 6809ca90
// Size: 184 bytes
// Params: undefined4 param_1, undefined4 * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_apiReadByte(undefined4 param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  short extraout_var;
  undefined1 local_38 [12];
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  lingo_resolveContext(&local_24,&local_20,&local_1c,&local_18,&local_14,&local_10,&local_c);
  *param_3 = 0;
  param_3[1] = 0;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_68176428,&local_8);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*local_8 + 0xc))(local_8,local_38);
    if (iVar1 == 0) {
      scoreEngine_getChannelCount(local_c,(short)local_2c);
      if (extraout_var == 0) {
        local_2c = local_2c + 0x4000;
      }
      param_3[1] = local_28;
      *param_3 = local_2c;
    }
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar1;
}



// ============================================================
// Function: lingo_apiCreateTimer (FUN_6809cb60)
// Address: 6809cb60
// Size: 140 bytes
// Params: undefined4 param_1, int param_2, int param_3, undefined2 * param_4, undefined2 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_apiCreateTimer(undefined4 param_1,int param_2,int param_3,undefined2 *param_4,undefined2 *param_5
                 )
{
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_10 = 0;
  local_c = 0;
  local_18 = 0;
  local_14 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_18,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_14 = param_3;
  if (param_4 != (undefined2 *)0x0) {
    local_10 = CONCAT22(param_4[2],*param_4);
  }
  if (param_5 != (undefined2 *)0x0) {
    local_c = CONCAT22(param_5[2],*param_5);
  }
  events_getWindowInfo(local_18,param_2,&local_14);
  return 0;
}



// ============================================================
// Function: lingo_apiSetProperty (FUN_6809cbf0)
// Address: 6809cbf0
// Size: 54 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiSetProperty(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = lingo_getGlobalType(local_8);
  *param_2 = iVar1;
  uVar2 = 0x80040007;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: lingo_apiGetProperty (FUN_6809cc30)
// Address: 6809cc30
// Size: 54 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiGetProperty(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = lingo_getGlobalFlags(local_8);
  *param_2 = iVar1;
  uVar2 = 0x80040007;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: lingo_apiGetPlatform (FUN_6809cc70)
// Address: 6809cc70
// Size: 82 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiGetPlatform(void)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0);
  iVar1 = Ordinal_1706();
  if (iVar1 != 0) {
    iVar2 = media_getDataPtr(*(int **)(local_8 + 4));
    if (*(code **)(iVar2 + 0x158) != (code *)0x0) {
      (**(code **)(iVar2 + 0x158))(iVar1);
    }
    return 0;
  }
  return 1;
}



// ============================================================
// Function: lingo_apiSetCallback (FUN_6809ccd0)
// Address: 6809ccd0
// Size: 40 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiSetCallback(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = param_2;
  local_8 = param_3;
  Ordinal_1707(lingo_getXtraRef,&local_c);
  return 0;
}



// ============================================================
// Function: lingo_apiQueryInterface (FUN_6809cd00)
// Address: 6809cd00
// Size: 80 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_apiQueryInterface(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  lingo_resolveContext(&local_20,&local_1c,&local_18,&local_14,&local_10,&local_c,&local_8);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = DAT_681956e0;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(*(int *)(local_8 + 4) + 0x28);
  }
  return 0;
}


