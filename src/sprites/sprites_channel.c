// Module: sprites
// Topic: Channel management, sprite property setting, and dispatch
// Address range: 0x68070D60 - 0x68071DA0
// Functions (16):
//   sprites_resetChannel
//   sprites_checkCallbackState
//   sprites_clearCallbackState
//   sprites_updateMemberCallback
//   sprites_mutateScoreData
//   sprites_resizeChannelBuffer
//   sprites_getChannelBufferSize
//   sprites_dispatchChannelProperty
//   sprites_writeChannelProperty
//   sprites_getChannelCursorState
//   sprites_saveChannelContext
//   sprites_restoreChannelContext
//   sprites_setChannelPropertyByType
//   sprites_mapPropertyToChannel
//   sprites_resolveChannelProperty
//   sprites_getChannelBounds


// ============================================================
// Function: sprites_resetChannel (FUN_68070d60)
// Address: 68070d60
// Size: 33 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_resetChannel(void)
{
  sprites_updateChannelFlag(0);
  return 0;
}



// ============================================================
// Function: sprites_checkCallbackState (FUN_68070d90)
// Address: 68070d90
// Size: 33 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_checkCallbackState(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  scoreEngine_checkCallbackState(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  return 0;
}



// ============================================================
// Function: sprites_clearCallbackState (FUN_68070dc0)
// Address: 68070dc0
// Size: 33 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_clearCallbackState(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  scoreEngine_clearCallbackState(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2);
  return 0;
}



// ============================================================
// Function: sprites_updateMemberCallback (FUN_68070df0)
// Address: 68070df0
// Size: 200 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_updateMemberCallback(int param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 4);
  piVar1 = (int *)Ordinal_165(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),&local_8);
  local_10 = piVar1;
  Ordinal_377(*(undefined4 *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),&local_c,&local_14);
  iVar4 = 0;
  if (-1 < local_8) {
    while ((int *)*piVar1 != param_2) {
      iVar4 = iVar4 + 1;
      piVar1 = piVar1 + 0xd;
      if (local_8 < iVar4) {
        return 0;
      }
    }
    iVar2 = cast_getMemberData(param_1,param_2);
    sprites_syncChannelIndex(iVar4,param_2);
    if ((*(int *)(iVar3 + 500) == 0x700) && (iVar4 != local_c)) {
      local_10[iVar4 * 0xd + 3] = -(uint)(iVar2 != 0);
      return 0;
    }
    iVar3 = 0;
    if (iVar2 == 0) {
      iVar3 = (*(int *)(param_1 + 0xe0) != 0) + 1;
    }
    sprites_updateChannelFlag(iVar3);
  }
  return 0;
}



// ============================================================
// Function: sprites_mutateScoreData (FUN_68070ec0)
// Address: 68070ec0
// Size: 44 bytes
// Params: int param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_mutateScoreData(int param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  uVar2 = lingo_mutateScoreData(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,param_3);
  *param_4 = uVar2;
  return 0;
}



// ============================================================
// Function: sprites_resizeChannelBuffer (FUN_68070ef0)
// Address: 68070ef0
// Size: 36 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_resizeChannelBuffer(int param_1,int param_2)
{
  Ordinal_218(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20),param_2 * 0x11);
  return 0;
}



// ============================================================
// Function: sprites_getChannelBufferSize (FUN_68070f20)
// Address: 68070f20
// Size: 39 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint sprites_getChannelBufferSize(int param_1)

{
  uint uVar1;
  
  uVar1 = Ordinal_219(*(int *)(*(int *)(*(int *)(param_1 + 8) + 4) + 0x20));
  return uVar1 / 0x11;
}



// ============================================================
// Function: sprites_dispatchChannelProperty (FUN_68070f50)
// Address: 68070f50
// Size: 65 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_dispatchChannelProperty(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = events_getMiawVideoRef(param_1,param_2);
  if (iVar2 != 0) {
    scoreEngine_dispatchPropertySet(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,&local_8);
  }
  return local_8;
}



// ============================================================
// Function: sprites_writeChannelProperty (FUN_68070fa0)
// Address: 68070fa0
// Size: 122 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_writeChannelProperty(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 4);
  if (param_2 == -1) {
    sprites_setCursorVisible((int)piVar1,1);
    piVar1[0x1e] = 0;
    return 0;
  }
  if (param_2 != 0) {
    iVar2 = scoreEngine_writeProperty(piVar1[8],(byte *)piVar1[9],param_2,&local_8);
    scoreEngine_writeNotation(piVar1,piVar1[9],param_2,local_8,iVar2);
    return 0;
  }
  sprites_setCursorVisible((int)piVar1,1);
  piVar1[0x1e] = 1;
  return 0;
}



// ============================================================
// Function: sprites_getChannelCursorState (FUN_68071020)
// Address: 68071020
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 sprites_getChannelCursorState(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
  iVar2 = *(int *)(iVar1 + 0x78);
  if (iVar2 == 0) {
    return 0xffffffff;
  }
  if (iVar2 != 1) {
    return *(undefined4 *)(iVar1 + 0x7c);
  }
  return 0;
}



// ============================================================
// Function: sprites_saveChannelContext (FUN_68071050)
// Address: 68071050
// Size: 151 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_saveChannelContext(int param_1,int param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int local_48 [16];
  uint local_8;
  
  iVar3 = *(int *)(*(int *)(param_1 + 8) + 4);
  piVar2 = (int *)cast_allocHandle(0xc,0);
  if (piVar2 != (int *)0x0) {
    puVar1 = (undefined4 *)*piVar2;
    *puVar1 = *(undefined4 *)(param_1 + 8);
    puVar1[1] = *(undefined4 *)(iVar3 + 0x28);
    puVar1[2] = *(undefined4 *)(iVar3 + 0x24);
    local_48[0] = 0;
    Ordinal_374(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),param_2,0x29,(double *)local_48);
    if ((local_48[0] != 0) && (iVar3 = lingo_getLifecycleRef(local_48[0]), iVar3 != 0)) {
      *(int *)(param_1 + 8) = iVar3 + 4;
      iVar3 = *(int *)(iVar3 + 8);
      *(int *)(iVar3 + 0x28) = local_48[0];
      *(int *)(iVar3 + 0x24) = local_48[0];
    }
  }
  return 0;
}



// ============================================================
// Function: sprites_restoreChannelContext (FUN_680710f0)
// Address: 680710f0
// Size: 47 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_restoreChannelContext(int param_1,undefined4 param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  
  if (param_3 != (int *)0x0) {
    piVar1 = (int *)*param_3;
    iVar2 = *piVar1;
    *(int *)(param_1 + 8) = iVar2;
    iVar2 = *(int *)(iVar2 + 4);
    *(int *)(iVar2 + 0x28) = piVar1[1];
    *(int *)(iVar2 + 0x24) = piVar1[2];
    cast_freeHandle(param_3);
  }
  return 0;
}




// ============================================================
// Function: sprites_setChannelPropertyByType (FUN_68071120)
// Address: 68071120
// Size: 1396 bytes
// Params: int param_1, uint * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall sprites_setChannelPropertyByType(int param_1,uint *param_2,int param_3,int param_4)
{
  int local_14;
  int *piVar1;
  uint uVar2;
  undefined1 uVar3;
  int iVar5;
  int iVar6;
  uint local_a0;
  uint local_9c;
  uint local_98;
  uint local_94;
  uint *local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined8 local_48;
  uint local_8;
  short sVar4;
  
  (*(unsigned int *)((char *)&local_48 + 0)) = 0;
  local_90 = param_2;
  memset((void *)((int)&local_48 + 4),0,0x3c);
  piVar1 = *(int **)(*(int *)(param_1 + 8) + 4);
  if (piVar1 == (int *)0x0) goto LAB_68071681;
  uVar2 = *param_2;
  uVar3 = (undefined1)uVar2;
  sVar4 = (short)(uVar2 >> 0x10);
  switch(param_4) {
  case 1:
    (*(unsigned int *)((char *)&local_48 + 0)) = CONCAT31((*(unsigned int *)((char *)&local_48 + 1)),uVar3);
    iVar5 = 4;
    break;
  case 2:
    (*(unsigned int *)((char *)&local_48 + 0)) = CONCAT31((*(unsigned int *)((char *)&local_48 + 1)),uVar3);
    (*(unsigned int *)((char *)&local_48 + 0)) = (uint)local_48 & 0xffffff;
    iVar5 = 8;
    break;
  case 3:
    events_getWindowData(param_1,param_3,&local_a0);
    local_98 = uVar2;
    events_setWindowData(param_1,param_3,(int *)&local_a0);
    goto switchD_68071174_caseD_6;
  case 4:
    local_8c = CONCAT22((short)*local_90,sVar4);
    if ((-1 < (short)*local_90) || (sVar4 != 1)) {
      sprites_checkBounds(param_1,(short *)&local_8c);
      iVar5 = piVar1[10];
      iVar6 = piVar1[8];
      goto LAB_68071615;
    }
    props_setError(param_1,0x23);
    goto switchD_68071174_caseD_6;
  case 5:
    if (((0 < (int)uVar2) && ((int)uVar2 <= *(int *)(param_1 + 0xf4))) || (uVar2 == 0)) {
      events_setCastSlotData((int)piVar1,piVar1[10],param_3,2,uVar2);
    }
  default:
    goto switchD_68071174_caseD_6;
  case 7:
    (*(unsigned int *)((char *)&local_48 + 0)) = CONCAT31((*(unsigned int *)((char *)&local_48 + 1)),uVar3);
    (*(unsigned int *)((char *)&local_48 + 0)) = (uint)local_48 & 0xffffff;
    iVar5 = 9;
    break;
  case 8:
    iVar5 = 0x11;
    (*(unsigned int *)((char *)&local_48 + 4)) = uVar2;
    break;
  case 9:
    events_setCastSlotData((int)piVar1,piVar1[10],param_3,1,(uint)(uVar2 != 0));
    goto switchD_68071174_caseD_6;
  case 10:
    (*(unsigned int *)((char *)&local_48 + 0)) = CONCAT31((*(unsigned int *)((char *)&local_48 + 1)),uVar3);
    iVar5 = 6;
    break;
  case 0xb:
    events_getWindowData(param_1,param_3,&local_a0);
    local_9c = uVar2;
    events_setWindowData(param_1,param_3,(int *)&local_a0);
    goto switchD_68071174_caseD_6;
  case 0xc:
    (*(unsigned int *)((char *)&local_48 + 0)) = CONCAT31((*(unsigned int *)((char *)&local_48 + 1)),uVar3);
    iVar5 = 10;
    break;
  case 0xd:
    (*(unsigned int *)((char *)&local_48 + 0)) = uVar2;
    events_clampToSpriteRect((int)piVar1,(int)(short)param_3,(int *)&local_48);
    iVar5 = 0xe;
    break;
  case 0xe:
    (*(unsigned int *)((char *)&local_48 + 4)) = uVar2;
    events_clampToSpriteRect((int)piVar1,(int)(short)param_3,(int *)&local_48);
    iVar5 = 0xf;
    break;
  case 0x11:
    local_8c = CONCAT22((short)*local_90,sVar4);
    if ((-1 < (short)*local_90) || (sVar4 != 1)) {
      sprites_checkBounds(param_1,(short *)&local_8c);
      (*(unsigned int *)((char *)&local_48 + 0)) = Ordinal_362(piVar1[8],piVar1[10],&local_8c);
      iVar5 = 7;
      break;
    }
    props_setError(param_1,0x23);
    goto switchD_68071174_caseD_6;
  case 0x12:
    (*(unsigned int *)((char *)&local_48 + 0)) = (uint)(uVar2 != 0);
    iVar5 = 1;
    break;
  case 0x13:
    events_getWindowData(param_1,param_3,&local_a0);
    local_94 = uVar2;
    events_setWindowData(param_1,param_3,(int *)&local_a0);
    goto switchD_68071174_caseD_6;
  case 0x16:
    (*(unsigned int *)((char *)&local_48 + 0)) = (uint)(uVar2 != 0);
    iVar5 = 0x13;
    break;
  case 0x17:
    events_getWindowData(param_1,param_3,&local_a0);
    local_a0 = uVar2;
    events_setWindowData(param_1,param_3,(int *)&local_a0);
    goto switchD_68071174_caseD_6;
  case 0x18:
    (*(unsigned int *)((char *)&local_48 + 0)) = (uint)(uVar2 != 0);
    iVar5 = 0x14;
    break;
  case 0x19:
    Ordinal_374(piVar1[8],piVar1[10],param_3,0x15,(double *)&local_88);
    (*(unsigned int *)((char *)&local_48 + 0)) = (uint)(uVar2 != 0);
    iVar5 = 0x15;
    Ordinal_373(piVar1[8],piVar1[10],param_3,0x15,(double *)&local_48,1);
    if ((piVar1[0x1f] == param_3) && ((uint)local_48 == 0)) {
      sprites_setCursorVisible((int)piVar1,1);
    }
    if (local_88 != (uint)local_48) {
      scoreEngine_dispatchPropertyOp(piVar1[8],piVar1[10],param_3);
    }
    break;
  case 0x1b:
    iVar5 = 0x10;
    (*(unsigned int *)((char *)&local_48 + 0)) = uVar2;
    break;
  case 0x1c:
    iVar5 = uVar2 * -0xff + 0x63ce;
    (*(unsigned int *)((char *)&local_48 + 0)) =
         CONCAT31((*(unsigned int *)((char *)&local_48 + 1)),
                  ((char)(iVar5 / 100) + (char)(iVar5 >> 0x1f)) -
                  (char)((longlong)iVar5 * 0x51eb851f >> 0x3f));
    iVar5 = 0x16;
    break;
  case 0x1d:
    local_8c = CONCAT22((short)*local_90,sVar4);
    if (((short)*local_90 < 0) && (sVar4 == 1)) {
      props_setError(param_1,0x23);
    }
    else {
      sprites_checkBounds(param_1,(short *)&local_8c);
      if (piVar1[0x1cd] != 0) {
        iVar5 = 0x20;
        (*(unsigned int *)((char *)&local_48 + 0)) = Ordinal_362(piVar1[8],piVar1[10],&local_8c);
        break;
      }
      events_setupSpriteSlot((int)piVar1,(undefined4 *)piVar1[10],param_3,local_8c);
    }
    goto switchD_68071174_caseD_6;
  case 0x1e:
    iVar5 = 0x17;
    (*(unsigned int *)((char *)&local_48 + 0)) = (uint)(uVar2 != 0);
    break;
  case 0x1f:
    iVar5 = 0x18;
    (*(unsigned int *)((char *)&local_48 + 0)) = (uint)(uVar2 != 0);
    break;
  case 0x20:
    (*(unsigned int *)((char *)&local_48 + 0)) = CONCAT31((*(unsigned int *)((char *)&local_48 + 1)),uVar3);
    iVar5 = 0x19;
    break;
  case 0x23:
    Ordinal_374(piVar1[8],piVar1[10],param_3,2,(double *)&local_88);
    if ((*(unsigned short *)((char *)&local_88 + 2)) == 0) {
      local_90 = (uint *)sprites_dispatchProperty(param_1,*local_90);
      (*(unsigned int *)((char *)&local_48 + 0)) = Ordinal_362(piVar1[8],piVar1[10],&local_90);
      iVar5 = 2;
    }
    else {
      iVar5 = 2;
      (*(unsigned int *)((char *)&local_48 + 0)) = CONCAT22((short)*local_90,(short)local_88);
    }
    break;
  case 0x24:
    Ordinal_374(piVar1[8],piVar1[10],param_3,2,(double *)&local_88);
    local_8c = CONCAT22((*(unsigned short *)((char *)&local_88 + 2)),(short)*local_90);
    iVar5 = piVar1[10];
    iVar6 = piVar1[8];
LAB_68071615:
    (*(unsigned int *)((char *)&local_48 + 0)) = Ordinal_362(iVar6,iVar5,&local_8c);
    iVar5 = 2;
    break;
  case 0x29:
    (*(unsigned int *)((char *)&local_48 + 0)) = (uint)(uVar2 != 0);
    iVar5 = 0x1d;
  }
  Ordinal_373(piVar1[8],piVar1[10],param_3,iVar5,(double *)&local_48,1);
switchD_68071174_caseD_6:
  if (param_4 == 0x1f) {
    if ((uint)local_48 != 0) {
      scoreEngine_writeNotation(piVar1,piVar1[10],param_3,1,2);
      return 0;
    }
    if ((piVar1[0x1e] != 0) && (piVar1[0x1f] == param_3)) {
      sprites_setCursorVisible((int)piVar1,1);
    }
  }
LAB_68071681:
  return 0;
}



// ============================================================
// Function: sprites_mapPropertyToChannel (FUN_68071740)
// Address: 68071740
// Size: 472 bytes
// Params: void * this, int param_1, uint param_2
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall sprites_mapPropertyToChannel(void *this,int param_1,uint param_2)

{
  int in_EAX;
  undefined4 extraout_ECX;
  int extraout_EDX;
  short sVar1;
  int unaff_ESI;
  uint local_c;
  undefined4 local_8;
  
  if (in_EAX < 0x165) {
    if (in_EAX == 0x164) {
      sVar1 = 0x12;
    }
    else {
      switch(in_EAX) {
      case 0x46:
        sVar1 = 0x17;
        break;
      case 0x47:
        sVar1 = 0xb;
        break;
      case 0x48:
        sVar1 = 0x1b;
        break;
      case 0x49:
        sVar1 = 8;
        break;
      default:
switchD_6807176b_caseD_4a:
        return 0;
      case 0x50:
        sVar1 = 0x13;
        break;
      case 0x51:
        sVar1 = 3;
        break;
      case 0x52:
        sVar1 = 0xe;
        break;
      case 0x53:
        sVar1 = 0xd;
        break;
      case 0xff:
      case 0x139:
        sVar1 = 1;
      }
    }
  }
  else if (in_EAX < 0x274) {
    if (in_EAX == 0x273) {
      sVar1 = 0x1f;
    }
    else {
      switch(in_EAX) {
      case 0x165:
        sVar1 = 9;
        break;
      default:
        goto switchD_6807176b_caseD_4a;
      case 0x167:
        sVar1 = 4;
        break;
      case 0x168:
        sVar1 = 7;
        break;
      case 0x169:
        sVar1 = 2;
        break;
      case 0x16a:
        sVar1 = 0xc;
        break;
      case 0x16b:
        sVar1 = 0x16;
        break;
      case 0x16c:
        sVar1 = 10;
        break;
      case 0x16d:
        sVar1 = 0x11;
        break;
      case 0x16e:
        sVar1 = 0x1e;
        break;
      case 0x173:
        sVar1 = 5;
        break;
      case 0x1e2:
        sVar1 = 0x18;
        break;
      case 0x235:
        sVar1 = 0x1c;
        break;
      case 0x236:
        sVar1 = 0x20;
        break;
      case 0x237:
        sVar1 = 0x1d;
      }
    }
  }
  else if (in_EAX == 0x2d8) {
    sVar1 = 0x23;
  }
  else if (in_EAX == 0x2d9) {
    sVar1 = 0x24;
  }
  else {
    if (in_EAX != 0x336) {
      return 0;
    }
    sVar1 = 0x29;
  }
  if (param_2 == 0) {
    events_getMiawPropertyList(param_1,(int)sVar1);
    return 1;
  }
  local_c = *(uint *)this;
  local_8 = *(undefined4 *)((int)this + 4);
  props_retainValueCallback(unaff_ESI,&local_c);
  props_callBuiltinDirect(extraout_ECX,extraout_EDX,unaff_ESI,(byte *)&local_c);
  props_coerceAndReturnInt(unaff_ESI,&local_c,(int *)&param_2);
  props_releaseAndClear(unaff_ESI,(int *)&local_c);
  sprites_setChannelPropertyByType(unaff_ESI,&param_2,param_1,(int)sVar1);
  return 1;
}



// ============================================================
// Function: sprites_resolveChannelProperty (FUN_68071b50)
// Address: 68071b50
// Size: 589 bytes
// Params: double * param_1, int param_2, uint param_3, uint param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_resolveChannelProperty(double *param_1,int param_2,uint param_3,uint param_4,uint *param_5)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_b8;
  int *local_b4;
  uint local_b0;
  int local_ac [16];
  uint local_6c [6];
  uint local_54;
  uint *local_50 [15];
  int local_14 [3];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(param_1 + 1) + 4);
  local_b0 = 0;
  if (param_2 == 0) {
    if ((0x354 < (int)param_4) && ((int)param_4 < 0x357)) {
      if (param_3 == 0) {
        local_b4 = (int *)Ordinal_482(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28));
        Ordinal_372(*(int *)(iVar1 + 0x20),*(byte **)(iVar1 + 0x28),8,local_14);
        if (param_4 == 0x355) {
          uVar2 = Ordinal_433(local_b4,local_14[0]);
          local_b0 = props_storeIntValue(param_1,uVar2,param_5);
        }
        else if (param_4 == 0x356) {
          uVar2 = Ordinal_434(local_b4,local_14[0]);
          local_b0 = props_storeIntValue(param_1,uVar2,param_5);
        }
      }
      else {
        local_b0 = 0x800407d6;
      }
      goto LAB_68071d84;
    }
  }
  else {
    iVar3 = sprites_mapPropertyToChannel(param_5,param_2,param_3);
    if (iVar3 != 0) {
LAB_68071d5c:
      return 0;
    }
    memset(local_50,0,0x3c);
    if (param_3 == 0) {
      local_b8 = 0;
      local_b4 = (int *)0x0;
      local_54 = param_4;
      local_50[0] = &local_b8;
      iVar3 = Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x1b,
                          (double *)&local_54);
      if ((local_50[0] != (uint *)0x0) && (param_5 != (uint *)0x0)) {
        *param_5 = *local_50[0];
        param_5[1] = local_50[0][1];
      }
    }
    else {
      local_54 = param_4;
      local_50[0] = param_5;
      iVar3 = Ordinal_373(*(uint *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,0x1b,
                          (double *)&local_54,1);
    }
    if (iVar3 != 0) goto LAB_68071d84;
    iVar3 = events_setMiawPropertyList(param_2,param_3,param_4,param_5);
    if (iVar3 != 0) goto LAB_68071d84;
    iVar3 = events_handleMiawNavigation(param_5,param_1,param_2,param_3,param_4,&local_b0);
    if (iVar3 != 0) goto LAB_68071d84;
    Ordinal_374(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),param_2,2,(double *)local_ac);
    Ordinal_294(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),local_ac[0],2,local_6c);
    if (local_6c[0] == 10) {
      sprites_dispatchPropertyEx(param_1,local_ac[0],param_3,param_4,param_5);
      goto LAB_68071d5c;
    }
    if (local_b0 != 0) goto LAB_68071d84;
  }
  local_b0 = 0x800407d5;
LAB_68071d84:
  return 0;
}



// ============================================================
// Function: sprites_getChannelBounds (FUN_68071da0)
// Address: 68071da0
// Size: 59 bytes
// Params: int param_1, int param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int sprites_getChannelBounds(int param_1,int param_2,int param_3,int param_4,uint *param_5)
{
  if (param_3 != 0) {
    sprites_setChannelPropertyByType(param_1,param_5,param_2,param_4);
    return 0;
  }
  events_getMiawPropertyList(param_2,param_4);
  return 0;
}



