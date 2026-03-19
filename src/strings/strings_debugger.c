// Module: strings
// Topic: Debugger support - breakpoints, call stack navigation, single stepping
// Address range: 0x6816a2b0 - 0x6816ae70
// Functions (25):
//   strings_debugStep
//   strings_debugToggleStep (FUN_6816a330)
//   strings_debugFindContext (FUN_6816a390)
//   strings_debugStepToLine (FUN_6816a410)
//   strings_debugBreakpointHit (FUN_6816a460)
//   strings_debugToggleBreakpoint (FUN_6816a540)
//   strings_debugStepOver (FUN_6816a5c0)
//   strings_debugAccessBreakpoint (FUN_6816a600)
//   strings_debugCountFrames (FUN_6816a650)
//   strings_debugSetBreakpoint
//   strings_debugResolvePath (FUN_6816a680)
//   strings_debugGetFrameInfo (FUN_6816a6a0)
//   strings_debugGetFrameContext (FUN_6816a710)
//   strings_debugGetValue
//   strings_debugLookupVariable (FUN_6816a7d0)
//   strings_debugGetVariable (FUN_6816a820)
//   strings_debugGetVariableInfo (FUN_6816a970)
//   strings_debugGetFrameCount (FUN_6816aa40)
//   strings_debugGetFrameEntry (FUN_6816aa80)
//   strings_debugGetScopeInfo (FUN_6816aae0)
//   strings_debugGetContextValue (FUN_6816ab40)
//   strings_debugResolveRange (FUN_6816abb0)
//   strings_debugGetArgValue (FUN_6816ad40)
//   strings_debugDispatchCommand (FUN_6816ae50)
//   strings_debugSetColor (FUN_6816ae70)

// ============================================================
// Function: strings_debugStep (FUN_6816a2b0)
// Address: 6816a2b0
// Size: 122 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_debugStep(int param_1,int param_2)
{
  int iVar1;
  
  if ((*(int *)(**(int **)(param_1 + 8) + 0x580) != 0) &&
     (iVar1 = core_getAsyncState(param_1), iVar1 != 0)) {
    if (param_2 != 0) {
      runtime_checkBreakpoint(*(int *)(iVar1 + 0x14),strings_debugLineCallback,param_1);
      runtime_setDebugErrorHandler(*(int *)(iVar1 + 0x14),strings_debugErrorCallback,param_1);
      core_dispatchScript(param_1,iVar1);
      return 0;
    }
    runtime_checkBreakpoint(*(int *)(iVar1 + 0x14),0,0);
    runtime_setDebugErrorHandler(*(int *)(iVar1 + 0x14),0,0);
    core_dispatchScript(param_1,iVar1);
  }
  return 0;
}



// ============================================================
// Function: strings_debugToggleStep (FUN_6816a330)
// Address: 6816a330
// Size: 84 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_debugToggleStep(int param_1,int param_2)
{
  props_setSingleStep(param_1,param_2);
  strings_debugStep(param_1,param_2);
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x134) = DAT_68196a38;
    DAT_68196a38 = 0xffffffff;
    return 0;
  }
  *(undefined4 *)(param_1 + 300) = 0;
  DAT_68196a38 = *(undefined4 *)(param_1 + 0x134);
  return 0;
}



// ============================================================
// Function: strings_debugFindContext (FUN_6816a390)
// Address: 6816a390
// Size: 119 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_debugFindContext(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *unaff_EDI;
  
  iVar1 = *(int *)(*unaff_EDI + 0x80);
  iVar4 = 0;
  if (0 < iVar1) {
    do {
      iVar2 = props_getContextSlot(param_1,unaff_EDI,iVar4);
      if (param_3 < *(int *)(iVar2 + 0x2c)) break;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  if (-1 < iVar4 + -1) {
    uVar3 = core_getHandlerArgAt(param_1,unaff_EDI,iVar4 + -1);
    if ((((uVar3 & 7) == 0) && ((uVar3 & 0xfffffff8) != 0)) &&
       ((undefined **)(*(uint *)(*(int *)((uVar3 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
        &PTR_s_Function_681928b8)) {
      uVar3 = xtra_getObjectTag(param_2,uVar3 & 0xfffffff8);
      if (uVar3 != 0) {
        return *(undefined4 *)(uVar3 + 0xc);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_debugStepToLine (FUN_6816a410)
// Address: 6816a410
// Size: 79 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_debugStepToLine(int param_1)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = core_getAsyncState(param_1);
  if (iVar1 != 0) {
    uVar2 = strings_debugFindContext(param_1,iVar1,in_EAX);
    if (uVar2 != 0) {
      iVar3 = runtime_setObjectField(iVar1,uVar2,in_EAX + 1);
      iVar3 = runtime_setBreakpoint(iVar1,uVar2,iVar3);
      in_EAX = iVar3 + -1;
    }
    core_dispatchScript(param_1,iVar1);
  }
  return in_EAX;
}



// ============================================================
// Function: strings_debugBreakpointHit (FUN_6816a460)
// Address: 6816a460
// Size: 211 bytes
// Params: int param_1, uint param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_debugBreakpointHit(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar4 = param_1;
  iVar3 = xtra_getPlatformData(param_1);
  uVar2 = param_2;
  param_1 = 0;
  local_10 = 0;
  *(undefined4 *)(iVar3 + 300) = 1;
  iVar4 = runtime_setBreakpoint(iVar4,param_2,param_3);
  piVar1 = *(int **)(uVar2 + 0x34);
  iVar4 = iVar4 + -1;
  if (piVar1 != (int *)0x0) {
    crt_executePlatformOp(iVar3,piVar1,(short)*(undefined4 *)(param_2 + 0x38),iVar4,&local_c,&local_8,
                 &param_1,(undefined1 *)0x0);
    if (local_8 != 0) {
      cast_freeHandle(local_c);
    }
    uVar2 = *(uint *)(*(int *)(iVar3 + 8) + 4);
    param_2 = uVar2;
    if (*(int *)(iVar3 + 0xc) != 0) {
      param_2 = *(uint *)(*(int *)(iVar3 + 0xc) + 4);
    }
    param_3 = lingo_initLifecycle(*(int *)(uVar2 + 0x20));
    uVar5 = lingo_initLifecycle(*(int *)(param_2 + 0x20));
    iVar6 = ((code *)(size_t)DAT_68196314)(param_3,uVar5,piVar1,iVar4,param_1,0);
    if (iVar6 != 0) {
      sprites_getMovieRefByPath(iVar3,piVar1,iVar4,param_1,&local_10);
    }
  }
  return 1;
}



// ============================================================
// Function: strings_debugToggleBreakpoint (FUN_6816a540)
// Address: 6816a540
// Size: 123 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_debugToggleBreakpoint(int param_1,undefined4 param_2,int param_3,undefined4 *param_4)
{
  int in_EAX;
  int iVar1;
  int iVar2;
  byte *pbVar3;
  
  iVar1 = core_getAsyncState(param_1);
  if (iVar1 != 0) {
    iVar2 = strings_debugFindContext(param_1,iVar1,in_EAX);
    if (iVar2 != 0) {
      pbVar3 = (byte *)runtime_setObjectField(iVar1,iVar2,in_EAX + 1);
      if (param_3 != 0) {
        *param_4 = 0;
        runtime_insertBreakpoint(iVar1,iVar2,pbVar3,0x6816a460,0);
        core_dispatchScript(param_1,iVar1);
        return 0;
      }
      runtime_detachBreakpoint(iVar1,iVar2,(int)pbVar3,(undefined4 *)0x0,(undefined4 *)0x0);
    }
    core_dispatchScript(param_1,iVar1);
  }
  return 0;
}



// ============================================================
// Function: strings_debugStepOver (FUN_6816a5c0)
// Address: 6816a5c0
// Size: 49 bytes
// Params: int param_1, int * param_2, void * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_debugStepOver(int param_1,int *param_2,void *param_3)
{
  if ((*(uint *)(*param_2 + 0x54) & 0x4000) != 0) {
    strings_debugStepToLine(param_1);
    return 0;
  }
  cast_findContextRange(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: strings_debugAccessBreakpoint (FUN_6816a600)
// Address: 6816a600
// Size: 68 bytes
// Params: int param_1, int * param_2, int param_3, void * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_debugAccessBreakpoint(int param_1,int *param_2,int param_3,void *param_4,uint *param_5)
{
  if ((*(uint *)(*param_2 + 0x54) & 0x4000) != 0) {
    strings_debugToggleBreakpoint(param_1,param_2,param_3,param_5);
    return 0;
  }
  cast_accessCharByte(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: strings_debugCountFrames (FUN_6816a650)
// Address: 6816a650
// Size: 15 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall strings_debugCountFrames(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x2c)) {
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



// ============================================================
// Function: strings_debugSetBreakpoint (FUN_6816a660)
// Address: 6816a660
// Size: 17 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall strings_debugSetBreakpoint(int param_1)
{
  int in_EAX;
  
  for (; (0 < param_1 && (in_EAX != 0)); in_EAX = *(int *)(in_EAX + 0x2c)) {
    param_1 = param_1 + -1;
  }
  return 0;
}



// ============================================================
// Function: strings_debugResolvePath (FUN_6816a680)
// Address: 6816a680
// Size: 32 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_debugResolvePath(void)

{
  int iVar1;
  int *in_EAX;
  int *piVar2;
  uint unaff_ESI;
  
  if (in_EAX != (int *)0x0) {
    piVar2 = xtra_resolvePath(unaff_ESI,in_EAX);
    if (piVar2 != (int *)0x0) {
      iVar1 = *piVar2;
      xtra_flushAndCheck(unaff_ESI,(int)piVar2);
      return iVar1;
    }
  }
  return 0;
}



// ============================================================
// Function: strings_debugGetFrameInfo (FUN_6816a6a0)
// Address: 6816a6a0
// Size: 110 bytes
// Params: void * this, undefined4 param_1, undefined2 * param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall strings_debugGetFrameInfo(void *this,undefined4 param_1,undefined2 *param_2)
{
  int iVar1;
  uint *puVar2;
  undefined *puVar3;
  int iVar4;
  int iVar5;
  int *unaff_EBX;
  
  *param_2 = 0;
  *unaff_EBX = 0;
  iVar1 = strings_debugSetBreakpoint((int)this);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x10) != 0)) {
    puVar2 = (uint *)xtra_getGlobalFlags(*(int *)(iVar1 + 0x10));
    if (puVar2 != (uint *)0x0) {
      puVar3 = xtra_getStringValue(puVar2);
      if (puVar3 != (undefined *)0x0) {
        Ordinal_1238(param_2,puVar3,0xff);
        iVar4 = strings_debugResolvePath();
        iVar5 = strings_debugResolvePath();
        *unaff_EBX = iVar4 + iVar5 + *(int *)(iVar1 + 0x24) + *(int *)(iVar1 + 0x18);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_debugGetFrameContext (FUN_6816a710)
// Address: 6816a710
// Size: 127 bytes
// Params: void * this, int param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall strings_debugGetFrameContext(void *this,int param_1,int param_2,int param_3,int *param_4)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_EBX;
  undefined4 *unaff_EDI;
  
  *unaff_EDI = 0;
  *param_4 = -1;
  *unaff_EBX = 0xffffffff;
  iVar1 = strings_debugSetBreakpoint((int)this);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0xc) != 0)) {
    *unaff_EDI = *(undefined4 *)(*(int *)(iVar1 + 0xc) + 0x34);
    iVar2 = runtime_setBreakpoint(param_2,*(uint *)(iVar1 + 0xc),*(int *)(iVar1 + 0x38));
    *param_4 = iVar2 + -1;
    crt_executePlatformOp(param_1,(int *)*unaff_EDI,(short)*(undefined4 *)(*(int *)(iVar1 + 0xc) + 0x38),
                 iVar2 + -1,&param_2,&param_3,unaff_EBX,(undefined1 *)0x0);
    if (param_3 != 0) {
      cast_freeHandle(param_2);
    }
  }
  return 0;
}



// ============================================================
// Function: strings_debugGetValue (FUN_6816a790)
// Address: 6816a790
// Size: 64 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall strings_debugGetValue(uint param_1)
{
  int iVar1;
  uint *puVar2;
  undefined *puVar3;
  undefined2 *unaff_ESI;
  int unaff_EDI;
  uint local_8;
  
  *unaff_ESI = 0;
  local_8 = param_1;
  iVar1 = xtra_getResourceDataEx(unaff_EDI,param_1,&local_8);
  if (iVar1 != 0) {
    puVar2 = (uint *)xtra_lookupHash(unaff_EDI,local_8);
    if (puVar2 != (uint *)0x0) {
      puVar3 = xtra_getStringValue(puVar2);
      if (puVar3 != (undefined *)0x0) {
        Ordinal_1238();
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_debugLookupVariable (FUN_6816a7d0)
// Address: 6816a7d0
// Size: 74 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall strings_debugLookupVariable(int param_1,uint param_2)
{
  int *piVar1;
  int in_EAX;
  uint *puVar2;
  
  if (((*(int *)(in_EAX + 0x10) != 0) &&
      (piVar1 = *(int **)(*(int *)(in_EAX + 0x10) + 4), piVar1 != (int *)0x0)) &&
     (puVar2 = *(uint **)(*piVar1 + 0x24), puVar2 != (uint *)0x0)) {
    while ((puVar2[1] != param_2 || (*(short *)((int)puVar2 + 0x12) != param_1))) {
      puVar2 = (uint *)puVar2[5];
      if (puVar2 == (uint *)0x0) {
        return 0;
      }
    }
    strings_debugGetValue(*puVar2);
  }
  return 0;
}



// ============================================================
// Function: strings_debugGetVariable (FUN_6816a820)
// Address: 6816a820
// Size: 325 bytes
// Params: void * this, uint param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall strings_debugGetVariable(void *this,uint param_1,int param_2,undefined4 *param_3)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_8;
  
  local_8 = 0x80000001;
  if (in_EAX < *(int *)((int)this + 0x18)) {
    *param_3 = 4;
    local_8 = *(undefined4 *)(*(int *)((int)this + 0x1c) + in_EAX * 4);
    strings_debugLookupVariable(in_EAX,0x68153f40);
    return local_8;
  }
  iVar2 = in_EAX - *(int *)((int)this + 0x18);
  if (iVar2 < *(int *)((int)this + 0x24)) {
    *param_3 = 4;
    local_8 = *(undefined4 *)(*(int *)((int)this + 0x28) + iVar2 * 4);
    strings_debugLookupVariable(iVar2,0x681541c0);
    return local_8;
  }
  iVar2 = iVar2 - *(int *)((int)this + 0x24);
  piVar3 = *(int **)((int)this + 0x14);
  if (piVar3 == (int *)0x0) {
LAB_6816a905:
    piVar3 = *(int **)((int)this + 0x34);
    if (piVar3 == (int *)0x0) {
      return local_8;
    }
    *param_3 = 1;
    piVar1 = xtra_resolvePath(param_1,piVar3);
    if (piVar1 == (int *)0x0) {
      return local_8;
    }
    if (*piVar1 <= iVar2) goto LAB_6816a94f;
    strings_debugGetValue(piVar1[iVar2 + 1]);
  }
  else {
    *param_3 = 3;
    piVar1 = xtra_resolvePath(param_1,piVar3);
    if (piVar1 == (int *)0x0) {
      return local_8;
    }
    if (*piVar1 <= iVar2) {
      iVar2 = iVar2 - *piVar1;
      xtra_flushAndCheck(param_1,(int)piVar1);
      goto LAB_6816a905;
    }
    strings_debugGetValue(piVar1[iVar2 + 1]);
  }
  xtra_parsePath(param_1,piVar3,(char *)(param_2 + 1),&local_8);
LAB_6816a94f:
  xtra_flushAndCheck(param_1,(int)piVar1);
  return local_8;
}



// ============================================================
// Function: strings_debugGetVariableInfo (FUN_6816a970)
// Address: 6816a970
// Size: 193 bytes
// Params: void * this, uint param_1, undefined4 param_2, undefined2 * param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall
strings_debugGetVariableInfo(void *this,uint param_1,undefined4 param_2,undefined2 *param_3,undefined4 *param_4,
            undefined4 *param_5)
{
  char cVar1;
  bool bVar2;
  uint uVar3;
  undefined3 extraout_var;
  uint *puVar4;
  char *pcVar5;
  undefined4 *puVar6;
  undefined2 *puVar7;
  char *pcVar8;
  undefined8 uVar9;
  
  uVar9 = strings_debugSetBreakpoint((int)this);
  puVar7 = (undefined2 *)((ulonglong)uVar9 >> 0x20);
  if ((void *)(size_t)uVar9 != (void *)0x0) {
    *puVar7 = 0;
    *param_3 = 0;
    if (param_4 != (undefined4 *)0x0) {
      *param_4 = 0;
    }
    uVar3 = strings_debugGetVariable((void *)(size_t)uVar9,param_1,(int)puVar7,param_5);
    if (uVar3 != 0) {
      if (((uVar3 & 7) == 0) &&
         (bVar2 = xtra_isFunction(param_1,uVar3 & 0xfffffff8), CONCAT31(extraout_var,bVar2) != 0)) {
        pcVar8 = "function...";
      }
      else {
        puVar4 = (uint *)xtra_lookupHash(param_1,uVar3);
        if (puVar4 == (uint *)0x0) {
          return 0;
        }
        pcVar8 = xtra_getStringValue(puVar4);
        if (pcVar8 == (char *)0x0) {
          return 0;
        }
      }
      Ordinal_1238(param_3,pcVar8,0xff);
      if (param_4 != (undefined4 *)0x0) {
        pcVar5 = pcVar8;
        do {
          cVar1 = *pcVar5;
          pcVar5 = pcVar5 + 1;
        } while (cVar1 != '\0');
        puVar6 = (undefined4 *)Ordinal_1111(pcVar5 + (1 - (int)(pcVar8 + 1)),0);
        if (puVar6 != (undefined4 *)0x0) {
          Ordinal_1128(*puVar6,pcVar8,pcVar5 + (1 - (int)(pcVar8 + 1)));
        }
        *param_4 = puVar6;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_debugGetFrameCount (FUN_6816aa40)
// Address: 6816aa40
// Size: 64 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_debugGetFrameCount(int param_1,int *param_2)
{
  int iVar1;
  int extraout_EDX;
  
  if (*(int *)(param_1 + 300) == 0) {
    stage_countScopes(param_1,param_2);
    return 0;
  }
  iVar1 = core_getAsyncState(param_1);
  iVar1 = strings_debugCountFrames(*(int *)(iVar1 + 0x34));
  *param_2 = iVar1;
  core_dispatchScript(param_1,extraout_EDX);
  return 0;
}



// ============================================================
// Function: strings_debugGetFrameEntry (FUN_6816aa80)
// Address: 6816aa80
// Size: 82 bytes
// Params: int param_1, void * param_2, undefined2 * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_debugGetFrameEntry(int param_1,void *param_2,undefined2 *param_3,int *param_4)
{
  int iVar1;
  
  if (*(int *)(param_1 + 300) == 0) {
    stage_getScopeEntry(param_1,(int)param_2,param_3,param_4);
    return 0;
  }
  iVar1 = core_getAsyncState(param_1);
  strings_debugGetFrameInfo(param_2,iVar1,param_3);
  core_dispatchScript(param_1,iVar1);
  return 0;
}



// ============================================================
// Function: strings_debugGetScopeInfo (FUN_6816aae0)
// Address: 6816aae0
// Size: 94 bytes
// Params: int param_1, void * param_2, int * param_3, int * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_debugGetScopeInfo(int param_1,void *param_2,int *param_3,int *param_4,undefined4 *param_5)
{
  int iVar1;
  
  if (*(int *)(param_1 + 300) == 0) {
    stage_getScopeInfo(param_1,(int)param_2,param_3,param_4,param_5);
    return 0;
  }
  iVar1 = core_getAsyncState(param_1);
  strings_debugGetFrameContext(param_2,param_1,iVar1,*(int *)(iVar1 + 0x34),param_4);
  core_dispatchScript(param_1,iVar1);
  return 0;
}



// ============================================================
// Function: strings_debugGetContextValue (FUN_6816ab40)
// Address: 6816ab40
// Size: 104 bytes
// Params: undefined * param_1, void * param_2, int param_3, undefined1 * param_4, undefined2 * param_5, undefined4 * param_6, int * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_debugGetContextValue(undefined *param_1,void *param_2,int param_3,undefined1 *param_4,
                 undefined2 *param_5,undefined4 *param_6,int *param_7)
{
  uint uVar1;
  
  if (*(int *)(param_1 + 300) == 0) {
    stage_getContextValue(param_1,(int)param_2,param_3,param_4,param_5,param_6,param_7);
    return 0;
  }
  uVar1 = core_getAsyncState((int)param_1);
  strings_debugGetVariableInfo(param_2,uVar1,param_3,param_5,param_6,param_7);
  core_dispatchScript((int)param_1,uVar1);
  return 0;
}



// ============================================================
// Function: strings_debugResolveRange (FUN_6816abb0)
// Address: 6816abb0
// Size: 400 bytes
// Params: int * param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_debugResolveRange(int *param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  (*(unsigned short *)((char *)&local_c + 0)) = 1;
  (*(unsigned short *)((char *)&local_8 + 0)) = 1;
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 < 1) {
    local_c = CONCAT22(1,(short)local_c);
    uVar2 = sprites_getMemberCount(unaff_ESI);
    local_8 = CONCAT22((*(unsigned short *)((char *)&local_8 + 2)),(short)uVar2);
    iVar3 = sprites_getMemberByChannel(unaff_ESI,(short)uVar2);
    local_8 = CONCAT22((short)iVar3,(short)local_8);
  }
  else {
    _DAT_68197764 =
         (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
                *(int *)(unaff_ESI + 0x18));
    local_10 = DAT_6819776c;
    local_14 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_10 = ((int *)(size_t)_DAT_68197764)[1];
      local_14 = *(int *)(size_t)_DAT_68197764;
    }
    local_c = (uint)(*(unsigned short *)((char *)&local_c + 2)) << 0x10;
    crt_executePlatformQuery(unaff_ESI,&local_14,sprites_resetMember,(short *)&local_c);
    if (*(int *)(unaff_ESI + 0x7c) != 0) {
      return *(int *)(unaff_ESI + 0x7c);
    }
    if (iVar1 < 2) {
      local_8 = local_c;
    }
    else {
      _DAT_68197764 =
           (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
                  *(int *)(unaff_ESI + 0x18));
      local_10 = DAT_6819776c;
      local_14 = DAT_68197768;
      if (_DAT_68197764 != (int *)0x0) {
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        local_10 = ((int *)(size_t)_DAT_68197764)[1];
        local_14 = *(int *)(size_t)_DAT_68197764;
      }
      local_8 = (uint)(*(unsigned short *)((char *)&local_8 + 2)) << 0x10;
      crt_executePlatformQuery(unaff_ESI,&local_14,sprites_resetMember,(short *)&local_8);
    }
  }
  sprites_checkBounds(unaff_ESI,(short *)&local_c);
  sprites_checkBounds(unaff_ESI,(short *)&local_8);
  if (iVar1 < 1) {
LAB_6816ad26:
    *param_1 = local_c;
    *param_2 = local_8;
    return 0;
  }
  if ((-1 < local_c) && (-1 < local_8)) {
    iVar1 = sprites_getMemberByChannel(unaff_ESI,(short)local_c);
    if ((short)(*(unsigned short *)((char *)&local_c + 2)) <= iVar1) {
      iVar1 = sprites_getMemberByChannel(unaff_ESI,(short)local_8);
      if ((short)(*(unsigned short *)((char *)&local_8 + 2)) <= iVar1) goto LAB_6816ad26;
    }
  }
  props_setError(unaff_ESI,0x24);
  return 0x24;
}



// ============================================================
// Function: strings_debugGetArgValue (FUN_6816ad40)
// Address: 6816ad40
// Size: 270 bytes
// Params: undefined4 * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_debugGetArgValue(undefined4 *param_1,int param_2)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int unaff_ESI;
  uint *unaff_EDI;
  uint local_10 [3];
  
  *unaff_EDI = 0;
  *param_1 = 0;
  local_10[0] = 0;
  local_10[1] = 0;
  local_10[2] = props_getInt(unaff_ESI);
  if (local_10[2] == 0) {
    if (param_2 != 0) {
      return 0;
    }
    props_setError(unaff_ESI,0x19);
    return local_10[2];
  }
  if (local_10[2] == 1) {
    _DAT_68197764 =
         (uint *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
                 *(int *)(unaff_ESI + 0x18));
    uVar1 = DAT_6819776c;
    uVar3 = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      uVar1 = ((int *)(size_t)_DAT_68197764)[1];
      uVar3 = *(int *)(size_t)_DAT_68197764;
    }
    *unaff_EDI = uVar3;
    unaff_EDI[1] = uVar1;
  }
  else {
    _DAT_68197764 =
         (uint *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
                 *(int *)(unaff_ESI + 0x18));
    uVar1 = DAT_6819776c;
    uVar3 = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      uVar1 = ((int *)(size_t)_DAT_68197764)[1];
      uVar3 = *(int *)(size_t)_DAT_68197764;
    }
    unaff_EDI[1] = uVar1;
    *unaff_EDI = uVar3;
    props_getValueDirect(unaff_ESI,2,1,local_10);
  }
  if (*(int *)(unaff_ESI + 0x7c) == 0) {
    props_retainValue(unaff_ESI,unaff_EDI);
    if ((local_10[0] == 0x40) || (local_10[0] == 0x43)) {
      props_retainValue(unaff_ESI,local_10);
      puVar2 = props_detachString(unaff_ESI,(int *)local_10);
      *param_1 = puVar2;
    }
    return local_10[2];
  }
  return -1;
}



// ============================================================
// Function: strings_debugDispatchCommand (FUN_6816ae50)
// Address: 6816ae50
// Size: 30 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_debugDispatchCommand(uint param_1)
{
  crt_setMiawProperty(param_1,0x15,0);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: strings_debugSetColor (FUN_6816ae70)
// Address: 6816ae70
// Size: 193 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int strings_debugSetColor(int param_1)
{
  int iVar1;
  int local_1c;
  int local_18;
  int local_14 [4];
  
  local_14[0] = 0;
  local_14[1] = 0;
  local_14[2] = 0;
  iVar1 = props_getInt(param_1);
  if (iVar1 == 1) {
    _DAT_68197764 =
         (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                *(int *)(param_1 + 0x18));
    local_18 = DAT_6819776c;
    local_1c = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_18 = ((int *)(size_t)_DAT_68197764)[1];
      local_1c = *(int *)(size_t)_DAT_68197764;
    }
    iVar1 = core_parseColorValue(param_1,&local_1c,local_14);
    if (iVar1 != 0) {
      events_getWindowInfo(param_1,0,local_14);
    }
    props_popArgs(param_1,(undefined4 *)0x0);
    return 0;
  }
  props_setError(param_1,0x15);
  return 0;
}



