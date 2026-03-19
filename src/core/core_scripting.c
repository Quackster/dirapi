// Module: core
// Topic: Scripting context - handler calls, error handling, cursor iteration
// Address range: 0x6801C8A0 - 0x6801CE80
// Functions (13):
//   core_resolveChunkValue (0x6801C8A0)
//   core_resetScriptResult (0x6801C920)
//   core_getChannelBounds (0x6801C940)
//   core_computeRectOp (0x6801C980)
//   core_iterateVisibleChannels (0x6801C9D0)
//   core_iterateScriptChannels (0x6801CA10)
//   core_releaseXtraValues (0x6801CA80)
//   core_checkSymbolId (0x6801CB30)
//   core_popScriptFrame (0x6801CB50)
//   core_dispatchScript (0x6801CB80)
//   core_executeScriptHandler (0x6801CC00)
//   core_checkRuntimeRef (0x6801CE60)
//   core_getScriptState (0x6801CE80)

// ============================================================
// Function: core_resolveChunkValue (FUN_6801c8a0)
// Address: 6801c8a0
// Size: 118 bytes
// Params: int param_1, int param_2, int * param_3, int * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resolveChunkValue(int param_1,int param_2,int *param_3,int *param_4,int param_5)
{
  int local_18;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = param_1;
  iVar2 = props_requireInt(param_1,param_3,&param_1);
  if (iVar2 != 0) {
    iVar2 = props_requireInt(iVar1,param_4,(int *)&param_3);
    if (iVar2 != 0) {
      iVar2 = crt_setPlatformParam(iVar1,param_1);
      if (iVar2 != 0) {
        iVar2 = crt_setPlatformParam(iVar1,(int)param_3);
        if (iVar2 != 0) {
          if (param_2 != 0) {
            uVar3 = events_setMiawTimerRef(iVar1,param_1,(int)param_3);
            *(undefined4 *)(param_5 + 4) = uVar3;
            return 0;
          }
          uVar3 = events_getMiawTimerRef(iVar1,param_1,(int)param_3);
          *(undefined4 *)(param_5 + 4) = uVar3;
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: core_resetScriptResult (FUN_6801c920)
// Address: 6801c920
// Size: 29 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resetScriptResult(void)
{
  int in_stack_00000010;
  undefined4 *in_stack_00000014;
  
  if (in_stack_00000010 == 0) {
    *in_stack_00000014 = 4;
    in_stack_00000014[1] = 0;
  }
  return 0;
}



// ============================================================
// Function: core_getChannelBounds (FUN_6801c940)
// Address: 6801c940
// Size: 63 bytes
// Params: int param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getChannelBounds(int param_1,int param_2,int param_3,uint *param_4)
{
  sprites_getChannelBounds(param_1,param_2,param_3,0x2b,param_4 + 1);
  if ((param_3 == 0) && (param_4[1] != 0)) {
    *param_4 = 3;
    props_retainValue(param_1,param_4);
  }
  return 0;
}



// ============================================================
// Function: core_computeRectOp (FUN_6801c980)
// Address: 6801c980
// Size: 67 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_computeRectOp(int param_1,int param_2,undefined4 *param_3)
{
  undefined4 local_18 [4];
  uint local_8;
  
  events_getMiawMediaRef(param_1,param_2,local_18);
  props_computeRectOp(param_1,local_18,param_3);
  return 0;
}



// ============================================================
// Function: core_iterateVisibleChannels (FUN_6801c9d0)
// Address: 6801c9d0
// Size: 64 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_iterateVisibleChannels(int param_1)
{
  int *piVar1;
  int *unaff_EBX;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(*unaff_EBX + 0x10);
  if (0 < iVar3) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(iVar2 + 0xa8 + *unaff_EBX);
      if ((piVar1 != (int *)0x0) && ((*(uint *)(*piVar1 + 0x54) & 0x4000) != 0)) {
        core_inheritMethods(param_1,piVar1);
      }
      iVar2 = iVar2 + 0x10;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}



// ============================================================
// Function: core_iterateScriptChannels (FUN_6801ca10)
// Address: 6801ca10
// Size: 108 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_iterateScriptChannels(int param_1)
{
  int *piVar1;
  int iVar2;
  undefined4 local_8;
  
  piVar1 = *(int **)(**(int **)(param_1 + 8) + 0x4f4);
  local_8 = *(int *)(*piVar1 + 0x10);
  if (0 < local_8) {
    iVar2 = 0;
    do {
      if (*(int *)(*piVar1 + 0x2c + iVar2) != 0) {
        core_iterateVisibleChannels(param_1);
      }
      iVar2 = iVar2 + 0x18;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return 0;
}



// ============================================================
// Function: core_releaseXtraValues (FUN_6801ca80)
// Address: 6801ca80
// Size: 173 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_releaseXtraValues(void)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  int local_1c;
  int local_10;
  int *local_c;
  uint local_8;
  
  local_1c = *(int *)(**(int **)(**(int **)(unaff_EDI + 8) + 0x4e4) + 0x14);
  if (0 < local_1c) {
    iVar3 = 0;
    do {
      piVar1 = (int *)(**(int **)(**(int **)(unaff_EDI + 8) + 0x4e4) + 0x24 + iVar3);
      local_10 = piVar1[2];
      local_c = (int *)piVar1[3];
      if (((*piVar1 != -1) && (local_10 == 3)) &&
         (iVar2 = cast_getXtraHandleValue(unaff_EDI,&local_10), iVar2 != 0)) {
        props_releaseValue(unaff_EDI,(byte)local_10,local_c);
        iVar2 = **(int **)(**(int **)(unaff_EDI + 8) + 0x4e4);
        *(undefined4 *)(iVar2 + 0x2c + iVar3) = 2;
        *(undefined4 *)(iVar2 + 0x30 + iVar3) = 0;
      }
      iVar3 = iVar3 + 0x10;
      local_1c = local_1c + -1;
    } while (local_1c != 0);
  }
  return 0;
}



// ============================================================
// Function: core_checkSymbolId (FUN_6801cb30)
// Address: 6801cb30
// Size: 17 bytes
// Params: int * param_1
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall core_checkSymbolId(int *param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  
  iVar1 = stage_lookupSymbolId(param_1,in_EAX);
  return -1 < iVar1;
}



// ============================================================
// Function: core_popScriptFrame (FUN_6801cb50)
// Address: 6801cb50
// Size: 39 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall core_popScriptFrame(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int *unaff_ESI;
  
  iVar1 = *unaff_ESI;
  iVar2 = *(int *)(iVar1 + 0x10) + -1;
  if (-1 < iVar2) {
    *param_2 = *(undefined4 *)(iVar1 + 0x20 + iVar2 * 8);
    param_2[1] = *(undefined4 *)(iVar1 + 0x24 + iVar2 * 8);
    stage_emitPushRef(unaff_ESI,iVar2);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_dispatchScript (FUN_6801cb80)
// Address: 6801cb80
// Size: 115 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_dispatchScript(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *extraout_ECX;
  int *piVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar3 = *(int **)(param_1 + 8);
  iVar1 = *piVar3;
  if ((*(int *)(iVar1 + 0x58c) == 1) && (*(int *)(iVar1 + 0x59c) != 0)) {
    *(undefined4 *)(iVar1 + 0x59c) = 0;
    xtra_getPlatformSize(param_2);
    piVar3 = extraout_ECX;
  }
  *(int *)(iVar1 + 0x58c) = *(int *)(iVar1 + 0x58c) + -1;
  if (*(int *)(iVar1 + 0x58c) < 1) {
    iVar2 = core_popScriptFrame(piVar3,&local_c);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar1 + 0x58c) = local_8;
      xtra_setPlatformValue(param_2,local_c);
    }
  }
  return 0;
}



// ============================================================
// Function: core_executeScriptHandler (FUN_6801cc00)
// Address: 6801cc00
// Size: 607 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int core_executeScriptHandler(int param_1,int param_2,int param_3)
{
  int *piVar1;
  undefined4 uVar2;
  undefined *puVar3;
  int iVar4;
  int local_1078;
  int local_1074;
  int local_1070;
  int local_106c;
  int *local_1068;
  undefined4 local_1064 [279];
  undefined1 local_c08 [1024];
  undefined1 local_808 [1024];
  undefined2 local_408 [512];
  uint local_8;
  
  puVar3 = (undefined *)xtra_getPlatformData(param_1);
  if (((param_3 != 0) && (param_2 != 0)) &&
     (*(int *)(param_3 + 0x28) = *(int *)(param_3 + 0x28) + 1, *(int *)(param_3 + 0x28) < 2)) {
    iVar4 = *(int *)(param_3 + 4);
    local_1068 = *(int **)(param_3 + 0x2c);
    local_1074 = 0;
    local_1070 = 0;
    if ((local_1068 == (int *)0x0) &&
       (local_1068 = *(int **)(**(int **)(puVar3 + 8) + 0x428), local_1068 == (int *)0x0)) {
      Ordinal_1233(local_808,"");
    }
    else {
      crt_resolveMovieTarget((int)puVar3,local_1068,0,&local_106c,&local_1078);
      if (local_106c == 0) {
        Ordinal_1233(local_808,"");
      }
      else {
        props_parseToken(local_1064,local_106c);
        props_parseBlock(puVar3,(int)local_1064,iVar4 + -1,&local_1070,&local_1074);
        Ordinal_1234(local_808,local_106c,local_1070,local_1074 - local_1070);
      }
      if (local_1078 != 0) {
        cast_freeHandle(local_106c);
      }
    }
    events_openMiawMovie((int)puVar3,2000,4);
    iVar4 = *(int *)(puVar3 + 0x7c);
    if (((iVar4 != 2) && (iVar4 != 1)) && (iVar4 != 0x70)) {
      if (iVar4 == 0) {
        Ordinal_1233(local_c08,param_2);
        Ordinal_1233(local_408,"");
      }
      else {
        cast_loadPascalString(local_c08,2000,iVar4);
        piVar1 = (int *)(puVar3 + 0x80);
        if (*(int *)(puVar3 + 0x80) == 0) {
          Ordinal_1233(local_408,"");
        }
        else {
          props_setupCallback(puVar3,piVar1,local_408);
        }
        props_releaseValue(puVar3,(byte)*piVar1,*(int **)(puVar3 + 0x84));
        *piVar1 = 0;
        *(undefined4 *)(puVar3 + 0x7c) = 0;
      }
      uVar2 = *(undefined4 *)(puVar3 + 300);
      *(undefined4 *)(puVar3 + 300) = 1;
      iVar4 = sprites_getSystemInfo((int)puVar3,(int)local_1068,local_c08,(int)local_808,(int)local_408,1,4,
                           local_1070);
      if (*(int *)(**(int **)(puVar3 + 8) + 0x41c) == 0) {
        *(undefined4 *)(**(int **)(puVar3 + 8) + 0x41c) = 4;
        *(uint *)(**(int **)(puVar3 + 8) + 0x4cc) = (uint)(iVar4 == 0);
      }
      *(undefined4 *)(puVar3 + 300) = uVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: core_checkRuntimeRef (FUN_6801ce60)
// Address: 6801ce60
// Size: 27 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool core_checkRuntimeRef(int param_1)

{
  int iVar1;
  
  iVar1 = xtra_getPlatformData(param_1);
  iVar1 = cast_getRuntimeRef(iVar1);
  return (bool)('\x01' - (iVar1 != 0));
}



// ============================================================
// Function: core_getScriptState (FUN_6801ce80)
// Address: 6801ce80
// Size: 31 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getScriptState(uint param_1)
{
  xtra_invokeMethod(param_1,xtra_getErrorString,0,0xaa);
  return 0;
}


