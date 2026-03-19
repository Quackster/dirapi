// Module: runtime
// Topic: Breakpoint hooks, callback registration, and linked list management
// Address range: 0x68120130 - 0x68120c60
// Functions (26):
//   runtime_executeBreakpointHook
//   runtime_dispatchBreakpoint
//   runtime_addBreakpoint
//   runtime_getBreakpointRef
//   runtime_insertBreakpoint
//   runtime_getBreakpointOpcode
//   runtime_removeBreakpoint
//   runtime_detachBreakpoint
//   runtime_removeBreakpointsForScript
//   runtime_clearAllBreakpoints
//   runtime_invokeBreakpointCallback
//   runtime_checkBreakpoint
//   runtime_markWatchesDirty
//   runtime_findWatch
//   runtime_getWatchProperty
//   runtime_getWatchCallback
//   runtime_setBreakpoint
//   runtime_setObjectField
//   runtime_setDebugErrorHandler
//   runtime_setDebugFrameHandler
//   runtime_getBreakpointState
//   runtime_evaluateWatch
//   runtime_notifyWatchChange
//   runtime_createWatchCallback
//   runtime_registerWatch
//   runtime_lookupWatch

// ============================================================
// Function: runtime_executeBreakpointHook (FUN_68120130)
// Address: 68120130
// Size: 73 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_executeBreakpointHook(void)
{
  int iVar1;
  char *unaff_EBX;
  uint *unaff_ESI;
  undefined4 *unaff_EDI;
  
  if ((unaff_EDI != (undefined4 *)0x0) && (unaff_EDI[7] == 0x93)) {
    unaff_EDI[6] = unaff_EDI[6] | 2;
  }
  iVar1 = runtime_throwError(unaff_ESI,unaff_EBX,unaff_EDI);
  if (iVar1 == 0) {
    xtra_reportErrorDirect((int)unaff_ESI,unaff_EBX,unaff_EDI);
    return 0;
  }
  if ((*(code **)(unaff_ESI[5] + 0x230) != (code *)0x0) && (unaff_ESI[0x52] != 0)) {
    (**(code **)(unaff_ESI[5] + 0x230))();
  }
  return 0;
}



// ============================================================
// Function: runtime_dispatchBreakpoint (FUN_68120180)
// Address: 68120180
// Size: 343 bytes
// Params: uint param_1, uint param_2, undefined * param_3, undefined4 param_4, undefined4 param_5, int param_6, undefined4 * param_7
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_dispatchBreakpoint(uint param_1,uint param_2,undefined *param_3,undefined4 param_4,undefined4 param_5,
                int param_6,undefined4 *param_7)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_8;
  
  uVar2 = param_1;
  if (((param_2 & 4) != 0) && ((*(byte *)(param_1 + 0x164) & 1) == 0)) {
    return 1;
  }
  memset(&local_34,0,0x30);
  iVar4 = *(int *)(uVar2 + 0x34);
  if (iVar4 != 0) {
    if ((*(int *)(iVar4 + 0xc) != 0) && (*(int *)(iVar4 + 0x38) != 0)) {
      local_34 = *(undefined4 *)(*(int *)(iVar4 + 0xc) + 0x18);
      local_30 = runtime_getObjectField(*(uint *)(iVar4 + 0xc),*(int *)(iVar4 + 0x38));
      local_8 = *(undefined4 *)(*(int *)(iVar4 + 0xc) + 0x34);
      goto LAB_6812022a;
    }
    iVar5 = *(int *)(iVar4 + 0x2c);
    if ((iVar5 != 0) && ((*(int *)(iVar5 + 0xc) != 0 && (*(int *)(iVar5 + 0x38) != 0)))) {
      local_34 = *(undefined4 *)(*(int *)(iVar5 + 0xc) + 0x18);
      local_30 = runtime_getObjectField(*(uint *)(*(int *)(iVar4 + 0x2c) + 0xc),
                              *(int *)(*(int *)(iVar4 + 0x2c) + 0x38));
      local_8 = *(undefined4 *)(*(int *)(*(int *)(iVar4 + 0x2c) + 0xc) + 0x34);
      goto LAB_6812022a;
    }
  }
  local_34 = 0;
  local_30 = 0;
LAB_6812022a:
  local_1c = param_2;
  local_18 = param_5;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_14 = 0;
  local_10 = (int *)0x0;
  iVar4 = xtra_formatError(uVar2,param_3,param_4,param_5,(int *)&param_2,(int)&local_34,&param_1,param_6
                       ,param_7);
  uVar3 = param_2;
  if (iVar4 != 0) {
    runtime_executeBreakpointHook();
    if (uVar3 != 0) {
      xtra_checkAndFlush(uVar2,uVar3);
    }
    if (local_10 != (int *)0x0) {
      iVar5 = 0;
      iVar4 = *local_10;
      piVar1 = local_10;
      while (iVar4 != 0) {
        xtra_checkAndFlush(uVar2,*piVar1);
        iVar5 = iVar5 + 1;
        piVar1 = local_10 + iVar5;
        iVar4 = local_10[iVar5];
      }
      xtra_checkAndFlush(uVar2,(int)local_10);
    }
    if (local_14 != 0) {
      xtra_checkAndFlush(uVar2,local_14);
    }
    return param_1;
  }
  return 0;
}



// ============================================================
// Function: runtime_addBreakpoint (FUN_681202e0)
// Address: 681202e0
// Size: 32 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_addBreakpoint(uint param_1,undefined4 param_2)
{
  xtra_invokeMethod(param_1,xtra_getErrorString,0,1);
  return 0;
}



// ============================================================
// Function: runtime_getBreakpointRef (FUN_68120300)
// Address: 68120300
// Size: 35 bytes
// Params: int param_1, int param_2
// Return: undefined4 *
// Calling convention: __fastcall
// ============================================================

undefined4 * __fastcall runtime_getBreakpointRef(int param_1,int param_2)

{
  undefined4 *puVar1;
  int unaff_ESI;
  
  puVar1 = *(undefined4 **)(param_1 + 0x238);
  while( true ) {
    if (puVar1 == (undefined4 *)(param_1 + 0x238)) {
      return (undefined4 *)0x0;
    }
    if ((puVar1[2] == unaff_ESI) && (puVar1[3] == param_2)) break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1;
}



// ============================================================
// Function: runtime_insertBreakpoint (FUN_68120330)
// Address: 68120330
// Size: 168 bytes
// Params: int param_1, int param_2, byte * param_3, int param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_insertBreakpoint(int param_1,int param_2,byte *param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  byte *extraout_EDX;
  
  iVar1 = *(int *)(param_1 + 0x14);
  piVar2 = runtime_getBreakpointRef(iVar1,(int)param_3);
  if (piVar2 == (int *)0x0) {
    piVar2 = (int *)xtra_getPropertyById(param_1,0x1c);
    if (piVar2 != (int *)0x0) {
      iVar3 = js_internAtom(param_1,(uint)(piVar2 + 6),0x6817e7bc);
      if (iVar3 != 0) goto LAB_6812037f;
      xtra_checkAndFlush(param_1,(int)piVar2);
    }
    return 0;
  }
  *extraout_EDX = *(byte *)(piVar2 + 4);
  param_3 = extraout_EDX;
LAB_6812037f:
  *piVar2 = iVar1 + 0x238;
  piVar2[1] = *(int *)(iVar1 + 0x23c);
  **(undefined4 **)(iVar1 + 0x23c) = piVar2;
  *(int **)(iVar1 + 0x23c) = piVar2;
  piVar2[2] = param_2;
  piVar2[3] = (int)param_3;
  piVar2[4] = (uint)*param_3;
  piVar2[5] = param_4;
  piVar2[6] = param_5;
  *param_3 = 0x53;
  return 1;
}



// ============================================================
// Function: runtime_getBreakpointOpcode (FUN_681203e0)
// Address: 681203e0
// Size: 42 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getBreakpointOpcode(int param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = runtime_getBreakpointRef(*(int *)(param_1 + 0x14),param_3);
  if (puVar1 == (undefined4 *)0x0) {
    return 0x9a;
  }
  return puVar1[4];
}



// ============================================================
// Function: runtime_removeBreakpoint (FUN_68120410)
// Address: 68120410
// Size: 44 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_removeBreakpoint(void)
{
  int *unaff_ESI;
  int unaff_EDI;
  
  *(int *)unaff_ESI[1] = *unaff_ESI;
  *(int *)(*unaff_ESI + 4) = unaff_ESI[1];
  *(char *)unaff_ESI[3] = (char)unaff_ESI[4];
  js_markAtom(*(int *)(unaff_EDI + 0x14),unaff_ESI + 6);
  xtra_checkAndFlush(unaff_EDI,(int)unaff_ESI);
  return 0;
}



// ============================================================
// Function: runtime_detachBreakpoint (FUN_68120440)
// Address: 68120440
// Size: 79 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_detachBreakpoint(int param_1,undefined4 param_2,int param_3,undefined4 *param_4,undefined4 *param_5
                 )
{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = runtime_getBreakpointRef(*(int *)(param_1 + 0x14),param_3);
  if (param_4 != (undefined4 *)0x0) {
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = puVar1[5];
    }
    *param_4 = uVar2;
  }
  if (param_5 != (undefined4 *)0x0) {
    if (puVar1 == (undefined4 *)0x0) {
      uVar2 = 0;
    }
    else {
      uVar2 = puVar1[6];
    }
    *param_5 = uVar2;
  }
  if (puVar1 != (undefined4 *)0x0) {
    runtime_removeBreakpoint();
  }
  return 0;
}



// ============================================================
// Function: runtime_removeBreakpointsForScript (FUN_68120490)
// Address: 68120490
// Size: 63 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_removeBreakpointsForScript(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar2 = *(int *)(param_1 + 0x14);
  puVar4 = *(undefined4 **)(iVar2 + 0x238);
  while (puVar4 != (undefined4 *)(iVar2 + 0x238)) {
    puVar3 = (undefined4 *)*puVar4;
    piVar1 = puVar4 + 2;
    puVar4 = puVar3;
    if (*piVar1 == param_2) {
      runtime_removeBreakpoint();
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_clearAllBreakpoints (FUN_681204d0)
// Address: 681204d0
// Size: 53 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_clearAllBreakpoints(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  puVar2 = *(undefined4 **)(iVar1 + 0x238);
  while (puVar2 != (undefined4 *)(iVar1 + 0x238)) {
    puVar2 = (undefined4 *)*puVar2;
    runtime_removeBreakpoint();
  }
  return 0;
}



// ============================================================
// Function: runtime_invokeBreakpointCallback (FUN_68120510)
// Address: 68120510
// Size: 74 bytes
// Params: int param_1, undefined4 param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_invokeBreakpointCallback(int param_1,undefined4 param_2,int param_3,uint *param_4)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 extraout_EDX;
  
  puVar2 = runtime_getBreakpointRef(*(int *)(param_1 + 0x14),param_3);
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  iVar1 = puVar2[4];
  iVar3 = (*(code *)puVar2[5])(param_1,param_2,extraout_EDX,param_4,puVar2[6]);
  if (iVar3 == 1) {
    *param_4 = iVar1 * 2 | 1;
  }
  return 0;
}



// ============================================================
// Function: runtime_checkBreakpoint (FUN_68120560)
// Address: 68120560
// Size: 33 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_checkBreakpoint(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x1e8) = param_2;
  *(undefined4 *)(param_1 + 0x1ec) = param_3;
  return 1;
}



// ============================================================
// Function: runtime_markWatchesDirty (FUN_68120590)
// Address: 68120590
// Size: 39 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_markWatchesDirty(int param_1)
{
  undefined4 *puVar1;
  
  for (puVar1 = *(undefined4 **)(param_1 + 0x240); puVar1 != (undefined4 *)(param_1 + 0x240);
      puVar1 = (undefined4 *)*puVar1) {
    *(byte *)(puVar1[3] + 0x11) = *(byte *)(puVar1[3] + 0x11) | 1;
  }
  return 0;
}



// ============================================================
// Function: runtime_findWatch (FUN_681205c0)
// Address: 681205c0
// Size: 42 bytes
// Params: int param_1, int param_2
// Return: int *
// Calling convention: __fastcall
// ============================================================

int * __fastcall runtime_findWatch(int param_1,int param_2)

{
  int *piVar1;
  int unaff_ESI;
  
  piVar1 = *(int **)(param_1 + 0x240);
  if (piVar1 != (int *)(param_1 + 0x240)) {
    do {
      if ((piVar1[2] == *(int *)(param_2 + 0x10)) && (*(int *)piVar1[3] == unaff_ESI)) {
        return piVar1;
      }
      piVar1 = (int *)*piVar1;
    } while (piVar1 != (int *)(param_1 + 0x240));
  }
  return (int *)0x0;
}



// ============================================================
// Function: runtime_getWatchProperty (FUN_681205f0)
// Address: 681205f0
// Size: 34 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_getWatchProperty(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = runtime_findWatch(param_1,param_2);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  return piVar1[3];
}



// ============================================================
// Function: runtime_getWatchCallback (FUN_68120620)
// Address: 68120620
// Size: 72 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getWatchCallback(int param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(param_1 + 0x240);
  while( true ) {
    if (puVar1 == (undefined4 *)(param_1 + 0x240)) {
      return 0;
    }
    if (((param_2 == 0) || (puVar1[2] == *(int *)(param_2 + 0x10))) && (puVar1[3] == param_3))
    break;
    puVar1 = (undefined4 *)*puVar1;
  }
  return puVar1[4];
}



// ============================================================
// Function: runtime_setBreakpoint (FUN_68120670)
// Address: 68120670
// Size: 20 bytes
// Params: undefined4 param_1, uint param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_setBreakpoint(undefined4 param_1,uint param_2,int param_3)
{
  runtime_getObjectField(param_2,param_3);
  return 0;
}



// ============================================================
// Function: runtime_setObjectField (FUN_68120690)
// Address: 68120690
// Size: 20 bytes
// Params: undefined4 param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_setObjectField(undefined4 param_1,int param_2,uint param_3)
{
  runtime_computeObjectSize(param_2,param_3);
  return 0;
}



// ============================================================
// Function: runtime_setDebugErrorHandler (FUN_681206b0)
// Address: 681206b0
// Size: 33 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_setDebugErrorHandler(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x218) = param_2;
  *(undefined4 *)(param_1 + 0x21c) = param_3;
  return 1;
}



// ============================================================
// Function: runtime_setDebugFrameHandler (FUN_681206e0)
// Address: 681206e0
// Size: 33 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_setDebugFrameHandler(int param_1,undefined4 param_2,undefined4 param_3)

{
  *(undefined4 *)(param_1 + 0x230) = param_2;
  *(undefined4 *)(param_1 + 0x234) = param_3;
  return 1;
}



// ============================================================
// Function: runtime_getBreakpointState (FUN_68120710)
// Address: 68120710
// Size: 105 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getBreakpointState(void)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  uint unaff_EBX;
  int *unaff_ESI;
  
  piVar1 = unaff_ESI + 7;
  *piVar1 = *piVar1 + -1;
  if (*piVar1 != 0) {
    return 1;
  }
  *(int *)unaff_ESI[1] = *unaff_ESI;
  *(int *)(*unaff_ESI + 4) = unaff_ESI[1];
  puVar2 = (uint *)unaff_ESI[3];
  iVar3 = runtime_getWatchCallback(*(int *)(unaff_EBX + 0x14),0,(int)puVar2);
  if (iVar3 == 0) {
    iVar3 = runtime_setPropertyValue(unaff_EBX,(undefined4 *)unaff_ESI[2],puVar2,0,(uint)(byte)puVar2[4],
                         (undefined *)puVar2[1],(undefined *)unaff_ESI[4]);
    if (iVar3 == 0) {
      return 0;
    }
  }
  js_markAtom(*(int *)(unaff_EBX + 0x14),unaff_ESI + 6);
  xtra_checkAndFlush(unaff_EBX,(int)unaff_ESI);
  return 1;
}



// ============================================================
// Function: runtime_evaluateWatch (FUN_68120780)
// Address: 68120780
// Size: 351 bytes
// Params: uint param_1, int * param_2, uint param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_evaluateWatch(uint param_1,int *param_2,uint param_3,int param_4)

{
  undefined4 *puVar1;
  uint *puVar2;
  code *pcVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  undefined1 local_5c [12];
  undefined4 local_50;
  uint local_4c;
  undefined4 local_30;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 0x14) + 0x240);
  do {
    if (puVar1 == (undefined4 *)(*(int *)(param_1 + 0x14) + 0x240)) {
      return 0;
    }
    puVar2 = (uint *)puVar1[3];
    if ((int *)puVar1[2] == param_2) {
      if ((*(byte *)((int)puVar2 + 0x11) & 8) == 0) {
        uVar4 = *puVar2;
        if ((uVar4 & 1) == 0) {
          uVar4 = *(uint *)(uVar4 + 8);
        }
      }
      else {
        uVar4 = *(short *)((int)puVar2 + 0x12) * 2 | 1;
      }
      if (uVar4 == param_3) {
        if ((*(byte *)((int)puVar2 + 0x11) & 8) == 0) {
          param_3 = *puVar2;
          if ((param_3 & 1) == 0) {
            param_3 = *(uint *)(param_3 + 8);
          }
        }
        else {
          param_3 = *(short *)((int)puVar2 + 0x12) * 2 | 1;
        }
        iVar5 = *param_2;
        puVar1[7] = puVar1[7] + 1;
        if (puVar2[3] < *(uint *)(iVar5 + 0xc)) {
          uVar6 = *(undefined4 *)(param_2[1] + puVar2[3] * 4);
        }
        else {
          uVar6 = 0x80000001;
        }
        iVar5 = (*(code *)puVar1[5])(param_1,param_2,param_3,uVar6,param_4,puVar1[6]);
        if (iVar5 != 0) {
          uVar4 = xtra_getObjectTag(param_1,puVar1[6]);
          memset(local_5c,0,0x58);
          local_50 = *(undefined4 *)(uVar4 + 0xc);
          local_30 = *(undefined4 *)(param_1 + 0x34);
          *(undefined1 **)(param_1 + 0x34) = local_5c;
          local_4c = uVar4;
          if (puVar1[4] != 0) {
            if ((puVar2[4] & 0x20) != 0) {
              certs_validateExtension(param_1,(int)param_2,puVar1[4],0,1,param_4,(int *)param_4);
              *(undefined4 *)(param_1 + 0x34) = local_30;
              uVar6 = runtime_getBreakpointState();
              return uVar6;
            }
            pcVar3 = *(code **)(*(int *)(*param_2 + 4) + 0x30);
            if (pcVar3 != (code *)0x0) {
              param_2 = (int *)(*pcVar3)(param_1,param_2);
            }
            (*(code *)puVar1[4])(param_1,param_2,param_3,param_4);
          }
          *(undefined4 *)(param_1 + 0x34) = local_30;
        }
        uVar6 = runtime_getBreakpointState();
        return uVar6;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}



// ============================================================
// Function: runtime_notifyWatchChange (FUN_681208e0)
// Address: 681208e0
// Size: 55 bytes
// Params: uint param_1, int * param_2, undefined4 param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_notifyWatchChange(uint param_1,int *param_2,undefined4 param_3,undefined4 *param_4,
                 undefined4 *param_5)
{
  uint uVar1;
  
  uVar1 = xtra_getObjectTag(param_1,param_4[-2] & 0xfffffff8);
  uVar1 = *(uint *)(*(int *)(uVar1 + 0x18) + 8);
  *param_5 = *param_4;
  runtime_evaluateWatch(param_1,param_2,uVar1,(int)param_5);
  return 0;
}



// ============================================================
// Function: runtime_createWatchCallback (FUN_68120920)
// Address: 68120920
// Size: 101 bytes
// Params: int param_1, uint param_2, byte param_3, int param_4
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

undefined * runtime_createWatchCallback(int param_1,uint param_2,byte param_3,int param_4)

{
  int *piVar1;
  
  if ((param_3 & 0x20) == 0) {
    return runtime_evaluateWatch;
  }
  if ((((param_2 & 1) != 0) && (param_2 != 0x80000001)) &&
     (param_2 = javascript_gcSweepInteger(param_1,(int)param_2 >> 1,0), param_2 == 0)) {
    return (undefined *)0x0;
  }
  piVar1 = runtime_createFunction(param_1,(int *)0x0,0x681208e0,1,0,
                        *(uint *)(*(int *)(param_4 + 4) + 4) & 0xfffffff8,param_2);
  if (piVar1 == (int *)0x0) {
    return (undefined *)0x0;
  }
  return (undefined *)piVar1[1];
}



// ============================================================
// Function: runtime_registerWatch (FUN_68120990)
// Address: 68120990
// Size: 714 bytes
// Params: uint * param_1, int * param_2, undefined * param_3, int param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_registerWatch(uint *param_1,int *param_2,undefined *param_3,int param_4,int param_5)

{
  undefined **ppuVar1;
  uint uVar2;
  code *pcVar3;
  uint *puVar4;
  uint *puVar5;
  undefined *puVar6;
  int iVar7;
  int *piVar8;
  undefined4 uVar9;
  code *pcVar10;
  int *piVar11;
  code *local_14;
  uint local_10;
  int *local_c;
  undefined *local_8;
  
  piVar11 = param_2;
  puVar4 = param_1;
  ppuVar1 = *(undefined ***)(*param_2 + 4);
  if ((ppuVar1 != &PTR_FUN_68192948) &&
     ((ppuVar1 == (undefined **)0x0 || (*ppuVar1 != PTR_FUN_68192948)))) {
    xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0xf);
    return 0;
  }
  if (((((uint)param_3 & 1) == 0) || (puVar6 = param_3, param_3 == (undefined *)0x80000001)) &&
     (puVar6 = (undefined *)js_resolveAtom((int)param_1,(uint)param_3), puVar6 == (undefined *)0x0)) {
    return 0;
  }
  local_8 = puVar6;
  iVar7 = runtime_getProperty((uint)puVar4,piVar11,(uint)puVar6,&local_c,(uint *)&param_1);
  if (iVar7 == 0) {
    return 0;
  }
  uVar2 = puVar4[5];
  if (param_1 == (uint *)0x0) {
    param_1 = (uint *)runtime_getWatchProperty(uVar2,*param_2);
    if (param_1 == (uint *)0x0) {
      iVar7 = runtime_callProperty((uint)puVar4,param_2,(uint)puVar6,0x80000001,0,0,1,&param_1);
joined_r0x68120b3f:
      if (iVar7 == 0) {
        return 0;
      }
      goto LAB_68120b47;
    }
  }
  else {
    if (local_c != param_2) {
      ppuVar1 = *(undefined ***)(*local_c + 4);
      if ((ppuVar1 == &PTR_FUN_68192948) ||
         ((ppuVar1 != (undefined **)0x0 && (*ppuVar1 == PTR_FUN_68192948)))) {
        if (param_1[3] < *(uint *)(*local_c + 0xc)) {
          param_3 = *(undefined **)(local_c[1] + param_1[3] * 4);
        }
        else {
          param_3 = (undefined *)0x80000001;
        }
        local_10 = (uint)(byte)param_1[4];
        local_14 = (code *)param_1[2];
        pcVar10 = (code *)param_1[1];
      }
      else {
        iVar7 = (*(code *)ppuVar1[4])(puVar4,local_c,param_3,&param_3);
        if (iVar7 == 0) {
          pcVar10 = *(code **)(*(int *)(*local_c + 4) + 0x34);
          if (pcVar10 != (code *)0x0) {
            (*pcVar10)(puVar4,local_c,param_1);
          }
          return 0;
        }
        pcVar10 = xtra_getPlatformVersion;
        local_14 = xtra_getPlatformVersion;
        local_10 = 1;
      }
      pcVar3 = *(code **)(*(int *)(*local_c + 4) + 0x34);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(puVar4,local_c,param_1);
      }
      iVar7 = runtime_callProperty((uint)puVar4,param_2,(uint)local_8,param_3,(uint)pcVar10,(uint)local_14,
                           local_10,&param_1);
      goto joined_r0x68120b3f;
    }
LAB_68120b47:
    if (param_1 == (uint *)0x0) {
      return 0;
    }
  }
  puVar5 = param_1;
  piVar8 = runtime_findWatch(uVar2,*param_2);
  piVar11 = param_2;
  if (piVar8 != (int *)0x0) {
LAB_68120c2c:
    piVar8[5] = param_4;
    piVar8[6] = param_5;
    pcVar10 = *(code **)(*(int *)(*piVar11 + 4) + 0x34);
    if (pcVar10 != (code *)0x0) {
      (*pcVar10)(puVar4,piVar11,param_1);
    }
    return 1;
  }
  param_3 = runtime_createWatchCallback((int)puVar4,(uint)local_8,(byte)puVar5[4],puVar5[2]);
  if ((param_3 != (undefined *)0x0) &&
     (piVar8 = (int *)xtra_getPropertyById((int)puVar4,0x20), piVar8 != (int *)0x0)) {
    piVar8[5] = 0;
    piVar8[6] = 0;
    iVar7 = js_internAtom((int)puVar4,(uint)(piVar8 + 6),0x6817e7cc);
    piVar11 = param_2;
    if (iVar7 != 0) {
      *piVar8 = uVar2 + 0x240;
      piVar8[1] = *(int *)(uVar2 + 0x244);
      **(undefined4 **)(uVar2 + 0x244) = piVar8;
      *(int **)(uVar2 + 0x244) = piVar8;
      piVar8[2] = (int)param_2;
      piVar8[3] = (int)param_1;
      piVar8[4] = param_1[2];
      piVar8[7] = 1;
      param_1 = (uint *)runtime_setPropertyValue((uint)puVar4,param_2,param_1,0,(uint)(byte)param_1[4],
                                     (undefined *)param_1[1],param_3);
      if (param_1 == (uint *)0x0) {
        uVar9 = runtime_getBreakpointState();
        return uVar9;
      }
      goto LAB_68120c2c;
    }
    xtra_checkAndFlush(puVar4,(int)piVar8);
  }
  return 0;
}



// ============================================================
// Function: runtime_lookupWatch (FUN_68120c60)
// Address: 68120c60
// Size: 153 bytes
// Params: int param_1, int param_2, uint param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_lookupWatch(int param_1,int param_2,uint param_3,undefined4 *param_4,undefined4 *param_5)

{
  undefined4 *puVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(*(int *)(param_1 + 0x14) + 0x240);
  puVar1 = (undefined4 *)*puVar5;
  do {
    if (puVar1 == puVar5) {
      if (param_4 != (undefined4 *)0x0) {
        *param_4 = 0;
      }
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = 0;
      }
      return 1;
    }
    if (puVar1[2] == param_2) {
      puVar2 = (uint *)puVar1[3];
      if ((*(byte *)((int)puVar2 + 0x11) & 8) == 0) {
        uVar3 = *puVar2;
        if ((uVar3 & 1) == 0) {
          uVar3 = *(uint *)(uVar3 + 8);
        }
      }
      else {
        uVar3 = *(short *)((int)puVar2 + 0x12) * 2 | 1;
      }
      if (uVar3 == param_3) {
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = puVar1[5];
        }
        if (param_5 != (undefined4 *)0x0) {
          *param_5 = puVar1[6];
        }
        uVar4 = runtime_getBreakpointState();
        return uVar4;
      }
    }
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}



