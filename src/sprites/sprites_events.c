// Module: sprites
// Topic: Event handling, behavior dispatch, and frame execution
// Address range: 0x68070010 - 0x68070D40
// Functions (28):
//   sprites_setScorePropertyData
//   sprites_getEventRef
//   sprites_getEventData
//   sprites_setEventData
//   sprites_getEventInfo
//   sprites_initEventContext
//   sprites_clearEventContext
//   sprites_getEventContext
//   sprites_resetFrameState
//   sprites_initSpriteOp
//   sprites_executeSpriteOp
//   sprites_suspendSpriteOp
//   sprites_pauseSpriteOp
//   sprites_resumeSpriteOp
//   sprites_cancelSpriteOp
//   sprites_finalizeSpriteOps
//   sprites_invokeHandlerChain
//   sprites_dispatchMemberPropertyOp
//   sprites_dispatchChannelEvent
//   sprites_broadcastEvent
//   sprites_processEvent
//   sprites_updateChannelFlag
//   sprites_setFrameRange
//   sprites_syncChannelIndex
//   sprites_assignMember
//   sprites_getOrInitChannelData
//   sprites_setActiveHandler
//   sprites_getActiveHandler


// ============================================================
// Function: sprites_setScorePropertyData (FUN_68070010)
// Address: 68070010
// Size: 94 bytes
// Params: int param_1, undefined4 * param_2, undefined1 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setScorePropertyData(int param_1,undefined4 *param_2,undefined1 param_3,undefined4 param_4)
{
  int iVar1;
  undefined4 local_14;
  undefined1 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_14 = Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  local_10 = param_3;
  local_c = param_4;
  scoreEngine_getPropertyData(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),3,(byte *)&local_14);
  return 0;
}



// ============================================================
// Function: sprites_getEventRef (FUN_68070070)
// Address: 68070070
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getEventRef(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  Ordinal_58(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28));
  return 0;
}



// ============================================================
// Function: sprites_getEventData (FUN_68070090)
// Address: 68070090
// Size: 143 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getEventData(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  lingo_loadMovieData(*(int *)(iVar1 + 0x20),&local_30);
  iVar1 = Ordinal_184(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_18,local_28);
  if (iVar1 != 0) {
    Ordinal_1072(&local_30,local_28,local_18);
    param_2[1] = local_30;
    *param_2 = local_2c;
    return 0;
  }
  *param_2 = local_2c;
  param_2[1] = local_30;
  return 0;
}



// ============================================================
// Function: sprites_setEventData (FUN_68070120)
// Address: 68070120
// Size: 112 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setEventData(int param_1,undefined4 *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  local_30 = param_2[1];
  local_2c = *param_2;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_184(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_28,local_18);
  if (iVar2 != 0) {
    Ordinal_1072(&local_30,local_28,local_18);
  }
  lingo_getDebugDataWrapped(*(int *)(iVar1 + 0x20),&local_30);
  return 0;
}



// ============================================================
// Function: sprites_getEventInfo (FUN_68070190)
// Address: 68070190
// Size: 87 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getEventInfo(int param_1,int *param_2)
{
  byte local_c [4];
  int *local_8;
  
  core_getObjectRefById(param_1,(uint *)local_c);
  if (local_8 != (int *)0x0) {
    events_handleWindowDispatch(param_1,*(int **)(*local_8 + 8),param_2);
    props_releaseValue(param_1,local_c[0],local_8);
    return 0;
  }
  *param_2 = 0;
  param_2[2] = 0;
  param_2[1] = 0;
  param_2[3] = 0;
  return 0;
}



// ============================================================
// Function: sprites_initEventContext (FUN_680701f0)
// Address: 680701f0
// Size: 3 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_initEventContext(void)
{
  return 0;
}



// ============================================================
// Function: sprites_clearEventContext (FUN_68070200)
// Address: 68070200
// Size: 3 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_clearEventContext(void)
{
  return 0;
}



// ============================================================
// Function: sprites_getEventContext (FUN_68070210)
// Address: 68070210
// Size: 5 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getEventContext(void)

{
  return 0;
}



// ============================================================
// Function: sprites_resetFrameState (FUN_68070220)
// Address: 68070220
// Size: 67 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_resetFrameState(void)
{
  int iVar1;
  int unaff_ESI;
  
  *(undefined4 *)(unaff_ESI + 0x728) = 0;
  iVar1 = Ordinal_58(*(int *)(unaff_ESI + 0x20),(byte *)0x0);
  lingo_mutateMember(*(int *)(unaff_ESI + 0x20),(byte *)0x0,iVar1 + 1);
  iVar1 = lingo_mutateChannelEx(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28));
  if (iVar1 == 1) {
    Ordinal_104(*(int *)(unaff_ESI + 0x20),0x1800);
  }
  return 0;
}



// ============================================================
// Function: sprites_initSpriteOp (FUN_68070270)
// Address: 68070270
// Size: 62 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_initSpriteOp(int param_1)
{
  int iVar1;
  int iVar2;
  void *this;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x734) == 0) {
    iVar2 = Ordinal_410(*(int *)(iVar1 + 0x20),0);
    *(int *)(iVar1 + 0x734) = iVar2;
    iVar2 = lingo_getSpriteOpCount(this,iVar2);
    if (iVar2 == 0) {
      Ordinal_409((int *)(iVar1 + 0x734));
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_executeSpriteOp (FUN_680702b0)
// Address: 680702b0
// Size: 63 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_executeSpriteOp(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x734) != 0) {
    Ordinal_412(*(int *)(iVar1 + 0x734));
    sprites_resetFrameState();
    lingo_getSpriteOpState(*(int *)(iVar1 + 0x734));
    Ordinal_428(*(int *)(iVar1 + 0x734));
  }
  return 0;
}



// ============================================================
// Function: sprites_suspendSpriteOp (FUN_680702f0)
// Address: 680702f0
// Size: 32 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_suspendSpriteOp(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x734);
  if (iVar1 != 0) {
    Ordinal_399(iVar1);
  }
  return 0;
}



// ============================================================
// Function: sprites_pauseSpriteOp (FUN_68070310)
// Address: 68070310
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_pauseSpriteOp(int param_1)
{
  sprites_suspendSpriteOp(param_1);
  return 0;
}



// ============================================================
// Function: sprites_resumeSpriteOp (FUN_68070320)
// Address: 68070320
// Size: 68 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_resumeSpriteOp(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (*(int *)(iVar1 + 0x734) != 0) {
    sprites_resetFrameState();
    lingo_getSpriteOpState(*(int *)(iVar1 + 0x734));
    lingo_getSpriteOpRef(*(int *)(iVar1 + 0x734));
    Ordinal_428(*(int *)(iVar1 + 0x734));
  }
  return 0;
}



// ============================================================
// Function: sprites_cancelSpriteOp (FUN_68070370)
// Address: 68070370
// Size: 32 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_cancelSpriteOp(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x734);
  if (iVar1 != 0) {
    Ordinal_413(iVar1);
  }
  return 0;
}



// ============================================================
// Function: sprites_finalizeSpriteOps (FUN_68070390)
// Address: 68070390
// Size: 139 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_finalizeSpriteOps(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14 [4];
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  piVar1 = (int *)(iVar2 + 0x734);
  if (*(int *)(iVar2 + 0x734) != 0) {
    iVar3 = lingo_getSpriteOp(*(int *)(iVar2 + 0x734));
    if (iVar3 != 0) {
      iVar3 = lingo_getSpriteOp(*piVar1);
      while (iVar3 != 0) {
        sprites_executeSpriteOp(param_1);
        iVar3 = lingo_getSpriteOp(*piVar1);
      }
    }
    sprites_executeSpriteOp(param_1);
    lingo_getSpriteOpData((int *)*piVar1);
    Ordinal_409(piVar1);
    events_removeAllSpriteSlots(iVar2,*(undefined4 *)(iVar2 + 0x28));
    local_14[0] = 1;
    Ordinal_361(*(undefined4 **)(iVar2 + 0x20),*(int **)(iVar2 + 0x28),0xe,(double *)local_14);
  }
  return 0;
}



// ============================================================
// Function: sprites_invokeHandlerChain (FUN_68070420)
// Address: 68070420
// Size: 316 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_invokeHandlerChain(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  int unaff_EBX;
  int *unaff_EDI;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar1 = *(int *)(unaff_EDI[2] + 4);
  local_1c = *(int *)(iVar1 + 0x760);
  local_8 = 0;
  local_18 = 0;
  bVar2 = js_isGCActive();
  if (CONCAT31(extraout_var,bVar2) != 0) {
    *param_3 = -0x7ffbfffe;
    return 1;
  }
  local_14 = *(undefined4 *)(iVar1 + 0x148);
  *(int *)(iVar1 + 0x148) = param_2;
  *(undefined4 *)(unaff_EBX + 0xc) = *(undefined4 *)(iVar1 + 0x760);
  *(undefined4 *)(unaff_EBX + 0x10) = 0;
  cast_retainObject(unaff_EDI,param_1);
  local_10 = cast_getMemberData(unaff_EDI,param_1);
  param_2 = 1;
  if (0 < local_10) {
    do {
      local_c = cast_resolveContext(unaff_EDI,param_1,param_2);
      if (local_c != (int *)0x0) {
        *(undefined4 *)(iVar1 + 0x18c) = 0;
        iVar3 = cast_invokeHandlerDirect(unaff_EDI,local_c,unaff_EBX,&local_1c,param_3);
        if ((iVar3 != 0) || (bVar2 = local_8 != 0, local_8 = 0, bVar2)) {
          local_8 = 1;
        }
        cast_releaseObject(unaff_EDI,local_c);
        if (local_1c != *(int *)(iVar1 + 0x760)) {
          props_releaseValue(unaff_EDI,(byte)*(undefined4 *)(unaff_EBX + 0xc),*(int **)(unaff_EBX + 0x10))
          ;
          *(int *)(unaff_EBX + 0xc) = local_1c;
          *(undefined4 *)(unaff_EBX + 0x10) = local_18;
          local_1c = *(int *)(iVar1 + 0x760);
          local_18 = 0;
        }
        if (*(int *)(iVar1 + 0x18c) != 0) break;
      }
      param_2 = param_2 + 1;
    } while (param_2 <= local_10);
  }
  cast_releaseObject(unaff_EDI,param_1);
  *(undefined4 *)(iVar1 + 0x148) = local_14;
  return local_8;
}




// ============================================================
// Function: sprites_dispatchMemberPropertyOp (FUN_68070560)
// Address: 68070560
// Size: 68 bytes
// Params: void * this, undefined4 param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall sprites_dispatchMemberPropertyOp(void *this,undefined4 param_1,undefined4 param_2,int *param_3)
{
  int iVar1;
  undefined4 uVar2;
  int in_EAX;
  
  iVar1 = *(int *)(*(int *)((int)this + 8) + 4);
  uVar2 = *(undefined4 *)(iVar1 + 0x148);
  *(undefined4 *)(iVar1 + 0x148) = param_1;
  events_dispatchPropertyOp(iVar1,param_2,*(undefined4 *)(in_EAX + 8),*(uint *)(in_EAX + 0x14),
               *(uint **)(in_EAX + 0x18),(int *)(in_EAX + 0xc),param_3);
  *(undefined4 *)(iVar1 + 0x148) = uVar2;
  return 0;
}



// ============================================================
// Function: sprites_dispatchChannelEvent (FUN_680705b0)
// Address: 680705b0
// Size: 499 bytes
// Params: void * param_1, int param_2, uint * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_dispatchChannelEvent(void *param_1,int param_2,uint *param_3,int param_4)
{
  bool bVar1;
  short sVar2;
  undefined3 extraout_var;
  undefined4 *puVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  uint local_90 [4];
  uint local_80 [4];
  uint local_70;
  uint local_6c;
  uint *local_68;
  int local_64;
  int local_60;
  int local_5c;
  uint *local_58;
  void *local_54;
  int local_50;
  int local_4c;
  undefined4 local_48 [16];
  uint local_8;
  
  local_54 = param_1;
  local_4c = 0;
  local_50 = (*(int **)((int)param_1 + 8))[1];
  local_60 = *(int *)(**(int **)((int)param_1 + 8) + 0x51c);
  local_64 = param_2;
  local_58 = param_3;
  bVar1 = js_isGCActive();
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return 0;
  }
  puVar5 = local_80;
  for (iVar4 = 7; iVar6 = local_50, iVar4 != 0; iVar4 = iVar4 + -1) {
    *puVar5 = *param_3;
    param_3 = param_3 + 1;
    puVar5 = puVar5 + 1;
  }
  if (param_4 != 0) {
    local_6c = local_6c - 1;
    local_68 = local_68 + 2;
  }
  puVar3 = (undefined4 *)Ordinal_165(*(int *)(local_50 + 0x20),*(int *)(local_50 + 0x28),&local_5c);
  if (((param_2 <= local_5c) && (0 < param_2)) && (param_2 <= *(int *)((int)local_54 + 0xf4))) {
    if (((int *)puVar3[param_2 * 0xd] != (int *)0x0) &&
       (iVar4 = sprites_invokeHandlerChain((int *)puVar3[param_2 * 0xd],param_2,&local_4c), param_2 = local_64,
       iVar6 = local_50, iVar4 != 0)) goto LAB_6807078d;
    iVar4 = Ordinal_374(*(int *)(iVar6 + 0x20),*(int *)(iVar6 + 0x28),param_2,2,(double *)local_48);
    if ((iVar4 != 0) && (iVar4 = sprites_dispatchMemberPropertyOp(local_54,param_2,local_48[0],&local_4c), iVar4 != 0))
    {
      local_58[3] = local_80[3];
      local_58[4] = local_70;
      goto LAB_6807078d;
    }
  }
  puVar5 = local_58;
  if (((int *)*puVar3 == (int *)0x0) ||
     (iVar4 = sprites_invokeHandlerChain((int *)*puVar3,param_2,&local_4c), iVar6 = local_50, iVar4 == 0)) {
    local_50 = 0;
    iVar4 = Ordinal_355(*(int *)(iVar6 + 0x20),*(int *)(iVar6 + 0x28),(short *)&local_50);
    while (iVar4 != 0) {
      sVar2 = Ordinal_364(*(int *)(iVar6 + 0x20),*(int *)(iVar6 + 0x28),(short)local_50);
      iVar4 = Ordinal_347(*(int *)(local_60 + 8),sVar2,4,local_90);
      if (((iVar4 != 0) && (local_90[0] != 0)) &&
         (iVar4 = cast_invokeHandler((uint)local_54,local_90[0],local_80[2],local_6c,local_68,local_80 + 3
                               ,&local_4c), iVar4 != 0)) {
        puVar5[3] = local_80[3];
        puVar5[4] = local_70;
        break;
      }
      iVar4 = Ordinal_355(*(int *)(iVar6 + 0x20),*(int *)(iVar6 + 0x28),(short *)&local_50);
    }
  }
LAB_6807078d:
  return 0;
}



// ============================================================
// Function: sprites_broadcastEvent (FUN_680707b0)
// Address: 680707b0
// Size: 457 bytes
// Params: void * param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_broadcastEvent(void *param_1,uint *param_2)
{
  void *pvVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  int iVar5;
  int local_74;
  int local_70;
  int *local_6c;
  int local_68;
  uint local_64;
  int local_60;
  uint local_5c;
  int *local_58;
  int *local_54;
  void *local_50;
  int local_4c;
  undefined4 local_48 [16];
  uint local_8;
  
  local_50 = param_1;
  local_60 = 0;
  iVar5 = *(int *)(*(int *)((int)param_1 + 8) + 4);
  local_64 = 0;
  local_4c = iVar5;
  bVar2 = js_isGCActive();
  if (CONCAT31(extraout_var,bVar2) != 0) {
    return 0;
  }
  local_54 = (int *)Ordinal_165(*(int *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),&local_74);
  local_5c = *(uint *)(iVar5 + 0x760);
  param_2[3] = local_5c;
  Ordinal_377(*(undefined4 *)(iVar5 + 0x20),*(int *)(iVar5 + 0x28),&local_70,&local_68);
  if (local_74 < local_68) {
    local_68 = local_74;
  }
  if (local_70 <= local_68) {
    local_54 = local_54 + local_70 * 0xd;
    iVar5 = local_70;
    do {
      iVar4 = local_4c;
      uVar3 = 0;
      local_6c = (int *)*local_54;
      if (local_6c == (int *)0x0) {
LAB_680708af:
        iVar4 = Ordinal_374(*(int *)(local_4c + 0x20),*(int *)(local_4c + 0x28),iVar5,2,
                            (double *)local_48);
        if (iVar4 != 0) {
          uVar3 = sprites_dispatchMemberPropertyOp(local_50,iVar5,local_48[0],&local_60);
        }
      }
      else {
        if (param_2[3] != *(uint *)(local_4c + 0x760)) {
          props_releaseValue(local_50,(byte)local_5c,local_58);
          local_58 = (int *)param_2[4];
          local_5c = param_2[3];
          param_2[3] = *(uint *)(iVar4 + 0x760);
        }
        uVar3 = sprites_invokeHandlerChain(local_6c,iVar5,&local_60);
        if (uVar3 == 0) goto LAB_680708af;
      }
      local_64 = local_64 | uVar3;
      local_54 = local_54 + 0xd;
      iVar5 = iVar5 + 1;
    } while (iVar5 <= local_68);
  }
  pvVar1 = local_50;
  uVar3 = local_5c;
  if (param_2[3] != *(uint *)(local_4c + 0x760)) {
    props_releaseValue(local_50,(byte)local_5c,local_58);
    local_58 = (int *)param_2[4];
    uVar3 = param_2[3];
    param_2[3] = *(uint *)(local_4c + 0x760);
  }
  if (local_64 == 0) {
    local_60 = sprites_dispatchChannelEvent(pvVar1,0,param_2,0);
  }
  if (param_2[3] == *(uint *)(local_4c + 0x760)) {
    param_2[3] = uVar3;
    param_2[4] = (uint)local_58;
  }
  else {
    props_releaseValue(pvVar1,(byte)uVar3,local_58);
  }
  return 0;
}



// ============================================================
// Function: sprites_processEvent (FUN_68070980)
// Address: 68070980
// Size: 82 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_processEvent(int param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(*(int *)(param_1 + 8) + 4);
  if (param_3 != 0) {
    piVar1 = (int *)Ordinal_482(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28));
    iVar2 = Ordinal_58(*(int *)(iVar2 + 0x20),*(byte **)(iVar2 + 0x28));
    lingo_resolveSpriteChannel(piVar1,iVar2,param_2);
    return 0;
  }
  media_saveRestoreAssetRef(*(int *)(iVar2 + 0x20),*(int *)(iVar2 + 0x28),param_2 + 1);
  return 0;
}



// ============================================================
// Function: sprites_updateChannelFlag (FUN_680709e0)
// Address: 680709e0
// Size: 98 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_updateChannelFlag(int param_1)
{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_4c;
  int local_48 [16];
  uint local_8;
  
  iVar1 = Ordinal_165(*(int *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),&local_4c);
  *(uint *)(iVar1 + 0xc + unaff_EDI * 0x34) = (param_1 != 0) - 1;
  local_48[0] = param_1;
  Ordinal_373(*(uint *)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0x28),unaff_EDI,0x27,
              (double *)local_48,0);
  return 0;
}



// ============================================================
// Function: sprites_setFrameRange (FUN_68070a50)
// Address: 68070a50
// Size: 147 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_setFrameRange(int param_1,int param_2,undefined4 param_3)
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *unaff_EDI;
  int local_48 [16];
  uint local_8;
  
  Ordinal_374(*(int *)(param_2 + 0x20),*(int *)(param_2 + 0x28),param_1,5,(double *)local_48);
  piVar1 = (int *)Ordinal_482(*(int *)(param_2 + 0x20),*(int *)(param_2 + 0x28));
  uVar2 = Ordinal_433(piVar1,local_48[0]);
  unaff_EDI[1] = uVar2;
  iVar3 = Ordinal_434(piVar1,local_48[0]);
  unaff_EDI[2] = iVar3;
  if ((int)unaff_EDI[1] < 1) {
    unaff_EDI[1] = 1;
  }
  if (iVar3 < (int)unaff_EDI[1]) {
    unaff_EDI[2] = 0x7fff;
    *unaff_EDI = param_3;
    return 0;
  }
  *unaff_EDI = param_3;
  return 0;
}



// ============================================================
// Function: sprites_syncChannelIndex (FUN_68070af0)
// Address: 68070af0
// Size: 157 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_syncChannelIndex(int param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  uint local_10;
  int local_c;
  int local_8;
  
  local_8 = cast_getMemberData(unaff_EDI,param_2);
  if ((0x7ff < *(uint *)(*(int *)(*(int *)(unaff_EDI + 8) + 4) + 500)) && (iVar2 = 1, 0 < local_8))
  {
    do {
      piVar1 = cast_resolveContext(unaff_EDI,param_2,iVar2);
      if (piVar1 != (int *)0x0) {
        local_10 = 4;
        local_c = 0;
        cast_dispatchVtableCall(unaff_EDI,piVar1,0,0x319,&local_10);
        if (local_c == 0) {
          local_c = param_1;
          if (param_1 == 0) {
            local_c = -5;
          }
          cast_setPropertyValue(unaff_EDI,piVar1,0x319,&local_10);
        }
        cast_releaseObject(unaff_EDI,piVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 <= local_8);
  }
  return 0;
}



// ============================================================
// Function: sprites_assignMember (FUN_68070b90)
// Address: 68070b90
// Size: 240 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_assignMember(int param_1,int param_2,int *param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  int local_8;
  
  piVar4 = param_3;
  iVar3 = param_1;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar5 = Ordinal_165(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),&local_8);
  if (((param_2 <= local_8) && (-1 < param_2)) && (param_2 <= *(int *)(param_1 + 0xf4))) {
    iVar6 = cast_getMemberData(param_1,param_3);
    piVar2 = *(int **)(iVar5 + param_2 * 0x34);
    param_3 = (int *)0x0;
    param_1 = 0;
    if (piVar2 != (int *)0x0) {
      param_3 = (int *)cast_getMemberData(iVar3,piVar2);
    }
    crt_getScriptPropertyEx(iVar3,piVar2);
    cast_releaseObject(iVar3,piVar2);
    cast_retainObject(iVar3,piVar4);
    crt_getScriptProperty(iVar3,piVar4);
    sprites_syncChannelIndex(param_2,piVar4);
    uVar7 = cast_dispatchMemberUpdate(iVar3,piVar4);
    sprites_setFrameRange(param_2,iVar1,uVar7);
    if ((iVar6 == 0) && ((param_3 == (int *)0x0 || (param_1 = 2, *(int *)(iVar3 + 0xe0) == 0)))) {
      param_1 = 1;
    }
    sprites_updateChannelFlag(param_1);
  }
  return 0;
}



// ============================================================
// Function: sprites_getOrInitChannelData (FUN_68070c80)
// Address: 68070c80
// Size: 115 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int sprites_getOrInitChannelData(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = Ordinal_165(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),&local_8);
  if (((param_2 <= local_8) && (-1 < param_2)) && (param_2 <= *(int *)(param_1 + 0xf4))) {
    piVar4 = (int *)(iVar2 + param_2 * 0x34);
    if (*piVar4 == 0) {
      uVar3 = cast_resetAndCountRects(param_1);
      sprites_setFrameRange(param_2,iVar1,uVar3);
      piVar4[3] = 0;
    }
    return *piVar4;
  }
  return 0;
}



// ============================================================
// Function: sprites_setActiveHandler (FUN_68070d00)
// Address: 68070d00
// Size: 58 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_setActiveHandler(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = *(int *)(**(int **)(param_1 + 8) + 0x51c);
  piVar2 = *(int **)(iVar1 + 0x658);
  if (piVar2 != (int *)0x0) {
    cast_releaseObject(param_1,piVar2);
  }
  *(int **)(iVar1 + 0x658) = param_2;
  cast_retainObject(param_1,param_2);
  return 0;
}



// ============================================================
// Function: sprites_getActiveHandler (FUN_68070d40)
// Address: 68070d40
// Size: 27 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getActiveHandler(int param_1)

{
  return *(undefined4 *)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 0x658);
}



