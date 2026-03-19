// Module: core
// Topic: Async/timer operations - timeout dispatch, network integration, cleanup
// Address range: 0x6801CEA0 - 0x6801D710
// Functions (18):
//   core_invokeAsyncHandler (0x6801CEA0)
//   core_registerAsyncSymbol (0x6801CFB0)
//   core_scanFrameXtras (0x6801D050)
//   core_scanGlobalXtras (0x6801D0F0)
//   core_scanAllFrameXtras (0x6801D160)
//   core_dispatchAsyncEvent (0x6801D1B0)
//   core_initAsyncNetwork (0x6801D260)
//   core_loadMovieResource (0x6801D330)
//   core_dispatchAsync (0x6801D390)
//   core_dispatchPendingEvents (0x6801D3C0)
//   core_getOrCreateAsyncState (0x6801D450)
//   core_getAsyncState (0x6801D490)
//   core_resolveAsyncScript (0x6801D510)
//   core_invokeAsyncScript (0x6801D5E0)
//   core_releaseMovieResource (0x6801D620)
//   core_notifyAsyncXtra (0x6801D660)
//   core_pollAsyncNetwork (0x6801D6C0)
//   core_destroyAsyncNetwork (0x6801D710)

// ============================================================
// Function: core_invokeAsyncHandler (FUN_6801cea0)
// Address: 6801cea0
// Size: 261 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_invokeAsyncHandler(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar5;
  uint uVar6;
  
  piVar3 = (int *)xtra_getPlatformData(param_1);
  uVar4 = cast_resolveXtraPropertyId(piVar3,param_1,*(int *)(param_4 + -8));
  if ((int)uVar4 < 0) {
    return 1;
  }
  uVar6 = 0;
  if (param_3 != 0) {
    do {
      props_pushValue((int)piVar3);
      bVar2 = cast_dispatchScoreXtra((int)piVar3,param_1,*(uint *)(param_4 + uVar6 * 4),(uint *)(piVar3 + 7));
      if (CONCAT31(extraout_var,bVar2) == 0) {
        return 0;
      }
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_3);
  }
  props_pushValue((int)piVar3);
  iVar1 = piVar3[0x1d];
  piVar3[8] = param_3 | 0x80000000;
  piVar3[0x1d] = 1;
  bVar2 = props_callHandler((int)piVar3,uVar4);
  uVar4 = CONCAT31(extraout_var_00,bVar2);
  if (uVar4 != 0) {
    if (piVar3[0x1d] == 2) {
      props_dispatchOpcode(piVar3,(int *)0x2,0,0);
      uVar4 = (uint)(piVar3[0x1d] != 8);
    }
    if (uVar4 != 0) {
      cast_readScoreXtraData((uint)piVar3,param_1,(uint *)(piVar3 + 7),param_5);
      props_popValue((int)piVar3);
      goto LAB_6801cf82;
    }
  }
  iVar5 = piVar3[0x1f];
  if (iVar5 == 0) {
    iVar5 = 4;
  }
  props_reportError((int)piVar3,iVar5);
  core_getScriptState(param_1);
LAB_6801cf82:
  if (uVar4 != 0) {
    piVar3[0x1d] = iVar1;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_registerAsyncSymbol (FUN_6801cfb0)
// Address: 6801cfb0
// Size: 152 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_registerAsyncSymbol(int param_1)
{
  uint uVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  char *pcVar3;
  undefined4 local_40c;
  undefined1 local_408;
  char local_407 [1023];
  uint local_8;
  
  score_lookupSymbol(DAT_68196304,unaff_EDI,(int)&local_408);
  pcVar3 = local_407;
  if (param_1 == 0) {
    xtra_registerNamedMethod(unaff_ESI,unaff_EBX,pcVar3);
  }
  else {
    uVar1 = xtra_getPlatformFlags(unaff_ESI);
    iVar2 = cast_registerXtraSymbol(unaff_ESI,core_invokeAsyncHandler,0,0,uVar1,pcVar3,unaff_EDI);
    if (iVar2 != 0) {
      local_40c = xtra_getScriptContext(iVar2);
      xtra_parsePathEx(unaff_ESI,unaff_EBX,local_407,&local_40c);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_scanFrameXtras (FUN_6801d050)
// Address: 6801d050
// Size: 157 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall core_scanFrameXtras(int param_1)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int in_EAX;
  int iStack00000004;
  int local_8;
  
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x4f4);
  piVar2 = *(int **)(iVar1 + 0x2c + in_EAX * 0x18);
  piVar3 = *(int **)(iVar1 + in_EAX * 0x18 + 0x28);
  local_8 = *(int *)(*piVar3 + 0x10);
  if (0 < local_8) {
    iStack00000004 = 0;
    do {
      iVar1 = *piVar3;
      if ((((*(code **)(iVar1 + 0x20 + iStack00000004) == props_getStackDepth) &&
           (iVar1 = *(int *)(iVar1 + iStack00000004 + 0x2c), -1 < iVar1)) &&
          (iVar4 = *piVar2, iVar1 < *(int *)(iVar4 + 0x10))) &&
         ((piVar5 = *(int **)(iVar4 + 0xa8 + iVar1 * 0x10), piVar5 != (int *)0x0 &&
          ((*(uint *)(*piVar5 + 0x54) & 0x4000) == 0)))) {
        core_registerAsyncSymbol(1);
      }
      iStack00000004 = iStack00000004 + 0x18;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return 0;
}



// ============================================================
// Function: core_scanGlobalXtras (FUN_6801d0f0)
// Address: 6801d0f0
// Size: 111 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_scanGlobalXtras(int param_1)
{
  int iVar1;
  int local_c;
  int local_8;
  
  local_c = *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x4e8) + 0x14);
  if (-1 < local_c + -1) {
    local_8 = 0;
    do {
      iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x4e8);
      if ((*(int *)(iVar1 + 0x24 + local_8) != -1) && (*(int *)(iVar1 + local_8 + 0x2c) == 3)) {
        core_registerAsyncSymbol(1);
      }
      local_8 = local_8 + 0x10;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  return 0;
}



// ============================================================
// Function: core_scanAllFrameXtras (FUN_6801d160)
// Address: 6801d160
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_scanAllFrameXtras(int param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = events_navigateToFrameEx(param_1);
  iVar3 = 1;
  if (0 < iVar1) {
    do {
      uVar2 = events_navigateToFrame(param_1,(ushort)iVar3);
      if (-1 < (int)(uVar2 - 1)) {
        core_scanFrameXtras(param_1);
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar1);
  }
  core_scanGlobalXtras(param_1);
  return 0;
}



// ============================================================
// Function: core_dispatchAsyncEvent (FUN_6801d1b0)
// Address: 6801d1b0
// Size: 166 bytes
// Params: uint param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_dispatchAsyncEvent(uint param_1,int param_2,uint *param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint local_40c;
  undefined1 local_408;
  char local_407 [1023];
  uint local_8;
  
  iVar2 = core_getAsyncState(param_1);
  if (iVar2 != 0) {
    score_lookupSymbol(DAT_68196304,param_2,(int)&local_408);
    piVar1 = *(int **)(**(int **)(param_1 + 8) + 0x584);
    iVar3 = cast_readScoreXtraData(param_1,iVar2,param_3,&local_40c);
    if (iVar3 != 0) {
      xtra_setPlatformValue(iVar2,0);
      xtra_parsePathEx(iVar2,piVar1,local_407,&local_40c);
      xtra_setPlatformValue(iVar2,param_1);
    }
    core_dispatchScript(param_1,iVar2);
  }
  return 0;
}



// ============================================================
// Function: core_initAsyncNetwork (FUN_6801d260)
// Address: 6801d260
// Size: 201 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_initAsyncNetwork(int param_1)

{
  int iVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = **(int **)(param_1 + 8);
  iVar1 = *(int *)(iVar4 + 0x594);
  if (iVar1 == 0) {
    iVar1 = 0x800000;
  }
  iVar5 = *(int *)(iVar4 + 0x598);
  if (iVar5 == 0) {
    iVar5 = 0x2000;
  }
  piVar2 = xtra_initRuntime(iVar1);
  if (piVar2 != (int *)0x0) {
    *(int **)(iVar4 + 0x57c) = piVar2;
    runtime_setDebugFrameHandler((int)piVar2,xtra_getPlatformVersion,0);
    puVar3 = (uint *)xtraRuntime_delegateCall(piVar2,iVar5);
    if (puVar3 != (uint *)0x0) {
      *(uint **)(iVar4 + 0x580) = puVar3;
      xtra_setPropertyDirect((int)puVar3,core_executeScriptHandler);
      xtra_setInterruptHandler((int)puVar3,core_checkRuntimeRef);
      piVar2 = (int *)cast_loadGlobalResource((int)puVar3);
      if (piVar2 != (int *)0x0) {
        *(int **)(iVar4 + 0x584) = piVar2;
        xtraRuntime_setPlatformFlags((int)puVar3,piVar2);
        iVar4 = xtra_initBuiltins(puVar3,piVar2);
        if (iVar4 != 0) {
          xtra_setPlatformRef((int)puVar3,0x96);
          xtra_setPlatformValue((int)puVar3,param_1);
          cast_initGlobalProperties((int)puVar3,piVar2);
          return 1;
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: core_loadMovieResource (FUN_6801d330)
// Address: 6801d330
// Size: 93 bytes
// Params: int param_1, uint param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint core_loadMovieResource(int param_1,uint param_2)

{
  undefined4 *puVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(*(int *)(param_1 + 8) + 0x10);
  if (uVar2 == 0) {
    puVar1 = (undefined4 *)xtra_getPlatformFlags(param_2);
    uVar2 = xtra_loadResource(param_2,(undefined **)0x0,puVar1,(uint)puVar1);
    if (uVar2 != 0) {
      events_registerProperty(param_2,uVar2,"_movie_",uVar2,0,0);
      *(uint *)(*(int *)(param_1 + 8) + 0x10) = uVar2;
      xtra_getMethodById(param_2,uVar2);
      core_scanAllFrameXtras(param_1);
    }
  }
  return uVar2;
}



// ============================================================
// Function: core_dispatchAsync (FUN_6801d390)
// Address: 6801d390
// Size: 38 bytes
// Params: uint param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_dispatchAsync(uint param_1,int param_2,uint *param_3)
{
  if (*(int *)(**(int **)(param_1 + 8) + 0x580) != 0) {
    core_dispatchAsyncEvent(param_1,param_2,param_3);
  }
  return 0;
}



// ============================================================
// Function: core_dispatchPendingEvents (FUN_6801d3c0)
// Address: 6801d3c0
// Size: 137 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_dispatchPendingEvents(uint param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(**(int **)(param_1 + 8) + 0x4e4);
  iVar4 = *(int *)(*piVar1 + 0x14);
  if (0 < iVar4) {
    iVar5 = 0;
    do {
      iVar2 = *piVar1;
      iVar3 = *(int *)(iVar2 + 0x24 + iVar5);
      iVar2 = iVar2 + 0x24 + iVar5;
      local_10 = *(uint *)(iVar2 + 8);
      local_c = *(undefined4 *)(iVar2 + 0xc);
      if (((iVar3 != -1) && (iVar3 != 300)) && (local_10 != 6)) {
        core_dispatchAsyncEvent(param_1,iVar3,&local_10);
      }
      iVar5 = iVar5 + 0x10;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return 0;
}



// ============================================================
// Function: core_getOrCreateAsyncState (FUN_6801d450)
// Address: 6801d450
// Size: 61 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int core_getOrCreateAsyncState(void)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint unaff_EDI;
  
  iVar1 = **(int **)(unaff_EDI + 8);
  iVar2 = *(int *)(iVar1 + 0x580);
  if (iVar2 == 0) {
    iVar2 = core_initAsyncNetwork(unaff_EDI);
    if (iVar2 == 0) {
      return 0;
    }
    piVar3 = stage_allocDispatchEntry(0x28,0x20,8,8);
    *(int **)(iVar1 + 0x588) = piVar3;
    core_dispatchPendingEvents(unaff_EDI);
    iVar2 = *(int *)(iVar1 + 0x580);
  }
  return iVar2;
}



// ============================================================
// Function: core_getAsyncState (FUN_6801d490)
// Address: 6801d490
// Size: 118 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int core_getAsyncState(int param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  
  iVar1 = **(int **)(param_1 + 8);
  iVar3 = core_getOrCreateAsyncState();
  iVar4 = xtra_getPlatformData(iVar3);
  if (iVar4 == param_1) {
    *(int *)(iVar1 + 0x58c) = *(int *)(iVar1 + 0x58c) + 1;
    return iVar3;
  }
  bVar2 = core_checkSymbolId(*(int **)(iVar1 + 0x588));
  if (CONCAT31(extraout_var,bVar2) == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0x58c) = 1;
  xtra_setPlatformValue(iVar3,param_1);
  return iVar3;
}



// ============================================================
// Function: core_resolveAsyncScript (FUN_6801d510)
// Address: 6801d510
// Size: 208 bytes
// Params: int param_1, undefined4 param_2, uint param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resolveAsyncScript(int param_1,undefined4 param_2,uint param_3,int *param_4)
{
  int local_18;
  int *piVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint *unaff_ESI;
  uint local_8;
  
  if (unaff_ESI != (uint *)0x0) {
    piVar1 = (int *)core_loadMovieResource(param_1,(uint)unaff_ESI);
    xtra_clearInterrupt((int)unaff_ESI);
    iVar2 = xtra_evalSubstring(unaff_ESI,piVar1,param_2,param_3,0,1);
    if (iVar2 != 0) {
      iVar3 = xtra_processExtension((uint)unaff_ESI,(uint)piVar1,iVar2,&local_8);
      if (((iVar3 != 0) && (local_8 != 0x80000001)) &&
         (puVar4 = (uint *)xtra_lookupHash((int)unaff_ESI,local_8), puVar4 != (uint *)0x0)) {
        puVar5 = xtra_getStringValue(puVar4);
        if (param_4 == (int *)0x0) {
          props_formatValue(param_1,&DAT_6817c0dc);
        }
        else {
          iVar3 = Ordinal_1201(puVar5,0);
          iVar3 = Ordinal_1111(iVar3 + 1);
          *param_4 = iVar3;
          if (iVar3 != 0) {
            uVar6 = Ordinal_1114(iVar3,puVar5);
            Ordinal_1202(uVar6);
            Ordinal_1115(*param_4);
            xtra_getInterfacePtr((int)unaff_ESI,iVar2);
            return 0;
          }
        }
      }
      xtra_getInterfacePtr((int)unaff_ESI,iVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: core_invokeAsyncScript (FUN_6801d5e0)
// Address: 6801d5e0
// Size: 63 bytes
// Params: int param_1, undefined4 param_2, uint param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_invokeAsyncScript(int param_1,undefined4 param_2,uint param_3,int *param_4)
{
  int iVar1;
  
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  iVar1 = core_getAsyncState(param_1);
  if (iVar1 != 0) {
    core_resolveAsyncScript(param_1,param_2,param_3,param_4);
    core_dispatchScript(param_1,iVar1);
  }
  return 0;
}



// ============================================================
// Function: core_releaseMovieResource (FUN_6801d620)
// Address: 6801d620
// Size: 62 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_releaseMovieResource(int param_1)
{
  uint uVar1;
  uint uVar2;
  
  uVar1 = *(uint *)(*(int *)(param_1 + 8) + 0x10);
  if (uVar1 != 0) {
    uVar2 = core_getAsyncState(param_1);
    if (uVar2 != 0) {
      xtra_resolveMethodId(uVar2,uVar1);
      core_dispatchScript(param_1,uVar2);
    }
    *(undefined4 *)(*(int *)(param_1 + 8) + 0x10) = 0;
  }
  return 0;
}



// ============================================================
// Function: core_notifyAsyncXtra (FUN_6801d660)
// Address: 6801d660
// Size: 87 bytes
// Params: int param_1, int * param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_notifyAsyncXtra(int param_1,int *param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  
  if ((((param_2 == (int *)0x0) || ((*(uint *)(*param_2 + 0x54) & 0x4000) == 0)) &&
      (*(int *)(*(int *)(param_1 + 8) + 0x10) != 0)) && (iVar1 = core_getAsyncState(param_1), iVar1 != 0))
  {
    if (*(char *)(*(int *)(iVar1 + 0x14) + 0x61) == '\0') {
      core_registerAsyncSymbol(param_4);
    }
    core_dispatchScript(param_1,iVar1);
  }
  return 0;
}



// ============================================================
// Function: core_pollAsyncNetwork (FUN_6801d6c0)
// Address: 6801d6c0
// Size: 72 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_pollAsyncNetwork(int param_1)
{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(**(int **)(param_1 + 8) + 0x580) != 0) &&
     (iVar1 = core_getAsyncState(param_1), iVar1 != 0)) {
    iVar2 = 0;
    do {
      xtra_getPlatformSize(iVar1);
      if (*(char *)(*(int *)(iVar1 + 0x14) + 0x60) == '\0') break;
      iVar2 = iVar2 + 1;
    } while (iVar2 < 10);
    core_dispatchScript(param_1,iVar1);
  }
  return 0;
}



// ============================================================
// Function: core_destroyAsyncNetwork (FUN_6801d710)
// Address: 6801d710
// Size: 137 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_destroyAsyncNetwork(int param_1)
{
  int iVar1;
  
  iVar1 = **(int **)(param_1 + 8);
  if (*(int *)(iVar1 + 0x57c) != 0) {
    core_releaseXtraValues();
    core_iterateScriptChannels(param_1);
    core_releaseMovieResource(param_1);
    core_getAsyncState(param_1);
    *(undefined4 *)(iVar1 + 0x584) = 0;
    xtraRuntime_setMode(*(int **)(iVar1 + 0x580));
    *(undefined4 *)(iVar1 + 0x580) = 0;
    xtraRuntime_destroyRuntime(*(int *)(iVar1 + 0x57c));
    *(undefined4 *)(iVar1 + 0x57c) = 0;
    xtraRuntime_destroyGlobals();
    cast_freeHandle(*(undefined4 *)(iVar1 + 0x588));
    *(undefined4 *)(iVar1 + 0x588) = 0;
    *(undefined4 *)(iVar1 + 0x5a0) = 0;
    *(undefined4 *)(iVar1 + 0x5a4) = 0;
    *(undefined4 *)(iVar1 + 0x5a8) = 0;
  }
  return 0;
}


