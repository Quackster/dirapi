// Module: playback
// Topic: Playback state dispatcher, play/stop/step control, tempo, utilities
// Address range: 0x680d8fa0 - 0x680d9b80
// Functions (23):
//   playback_dispatchCuePoint, playback_checkCuePointReached, playback_dispatchStepAction, playback_resetControlState, playback_getControlSize
//   playback_processControl, playback_executeControlStep, playback_getControlFlags, playback_getControlState, playback_setControlState
//   playback_findFirstControlState, playback_lookupControlByChannel, playback_getControlRef, playback_addControlRef, playback_destroyAllControlRefs
//   playback_createControlPairs, playback_setControlProperty, playback_createControlProperty, playback_checkDoubleByteSupport, playback_isDoubleByteLeadChar
//   playback_readDoubleByteChar, playback_writeDoubleByteChar, playback_getControlRef2

// ============================================================
// Function: playback_dispatchCuePoint (playback_dispatchCuePoint)
// Address: 680d8fa0
// Size: 260 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_dispatchCuePoint(void)

{
  short sVar1;
  int *piVar2;
  bool bVar3;
  undefined2 uVar4;
  undefined3 extraout_var;
  int unaff_ESI;
  
  lingo_checkObjectValid(*(int *)(*(int *)(unaff_ESI + 0x20) + 4));
  bVar3 = playback_hasSavedStepState(unaff_ESI);
  if (CONCAT31(extraout_var,bVar3) != 0) {
    playback_restoreStepState(unaff_ESI);
  }
  piVar2 = *(int **)(unaff_ESI + 0x20);
  if ((((piVar2[0x198] == 0) && (*(int *)(unaff_ESI + 100) == 0)) &&
      (sVar1 = *(short *)(unaff_ESI + 0xd0), sVar1 != 0)) && (sVar1 != -10)) {
    switch(sVar1) {
    case -9:
      break;
    case -8:
      media_getDataSize(*(int *)(*(int *)(unaff_ESI + 0x18) + 4),1);
      *(undefined4 *)(unaff_ESI + 0x58) = 0x12;
      return 1;
    default:
      if (*(short *)(unaff_ESI + 0xd2) == -1) {
        uVar4 = scoreEngine_getCuePoint(piVar2,*(int *)(unaff_ESI + 0xd4));
        *(undefined2 *)(unaff_ESI + 0xd2) = uVar4;
      }
      *(undefined4 *)(unaff_ESI + 0x58) = 0x15;
      return 1;
    case -2:
      if (*(short *)(unaff_ESI + 0xd2) == -1) {
        uVar4 = scoreEngine_getCuePoint(piVar2,-2);
        *(undefined2 *)(unaff_ESI + 0xd2) = uVar4;
      }
      *(undefined4 *)(unaff_ESI + 0x58) = 0x14;
      return 1;
    case -1:
      if (*(short *)(unaff_ESI + 0xd2) == -1) {
        uVar4 = scoreEngine_getCuePoint(piVar2,-1);
        *(undefined2 *)(unaff_ESI + 0xd2) = uVar4;
      }
      *(undefined4 *)(unaff_ESI + 0x58) = 0x13;
      return 1;
    }
  }
  *(undefined4 *)(unaff_ESI + 0x58) = 0x16;
  return 1;
}



// ============================================================
// Function: playback_checkCuePointReached (playback_checkCuePointReached)
// Address: 680d90d0
// Size: 132 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_checkCuePointReached(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  uint unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + 0x58);
  if (*(int *)(unaff_ESI + 100) != 0) {
    playback_saveStepState(unaff_ESI);
    *(undefined4 *)(unaff_ESI + 0x58) = 0x16;
    return 1;
  }
  if (*(short *)(unaff_ESI + 0xd2) == -2) {
    scoreEngine_breakSoundLoop(*(int **)(unaff_ESI + 0x20),unaff_EDI);
    iVar2 = scoreEngine_getCastXtraRef(*(int **)(unaff_ESI + 0x20),unaff_EDI);
    if (iVar2 != 0) {
LAB_680d9111:
      *(undefined4 *)(unaff_ESI + 0x58) = uVar1;
      return 1;
    }
  }
  else {
    iVar2 = scoreEngine_getCastXtraRef(*(int **)(unaff_ESI + 0x20),unaff_EDI);
    if (iVar2 != 0) {
      iVar2 = scoreEngine_isPastCuePoint(*(int **)(unaff_ESI + 0x20),-1 - unaff_EDI,
                           (int)*(short *)(unaff_ESI + 0xd2),0);
      if (iVar2 == 0) goto LAB_680d9111;
    }
  }
  *(undefined4 *)(unaff_ESI + 0x58) = 0x16;
  return 1;
}



// ============================================================
// Function: playback_dispatchStepAction (playback_dispatchStepAction)
// Address: 680d9160
// Size: 503 bytes
// Params: void * this, int * param_1, int param_2
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall playback_dispatchStepAction(void *this,int *param_1,int param_2)

{
  int *in_EAX;
  undefined4 uVar1;
  int iVar2;
  
  if (in_EAX != (int *)0x0) {
    *in_EAX = 0;
  }
  if ((param_1[0x18] != 0) && (*(int *)(*(int *)(param_1[8] + 4) + 0x10) != 0)) {
    if (param_2 != 0) {
      param_1[0x19] = 1;
    }
    switch(param_1[0x16]) {
    case 1:
      iVar2 = playback_stepBeginFrame(param_1);
      return iVar2;
    case 2:
      iVar2 = playback_stepSetupTransition();
      return iVar2;
    case 3:
      iVar2 = playback_stepRenderSprites(this);
      return iVar2;
    case 4:
      iVar2 = playback_stepWaitSpriteRender(this);
      return iVar2;
    case 5:
      iVar2 = playback_stepProcessCallbacks();
      return iVar2;
    case 6:
      iVar2 = playback_stepApplyTransition();
      return iVar2;
    case 7:
      iVar2 = playback_stepRenderTransition(this);
      return iVar2;
    case 8:
      iVar2 = playback_stepWaitTransitionRender(this);
      return iVar2;
    case 9:
      iVar2 = playback_stepFinishTransition();
      return iVar2;
    case 10:
      uVar1 = playback_stepProcessPalette();
      return (int)(short)uVar1;
    case 0xb:
      iVar2 = playback_stepProcessLifecycle();
      return iVar2;
    case 0xc:
      iVar2 = playback_stepSetupPaletteTransition();
      return iVar2;
    case 0xd:
      iVar2 = playback_stepRenderPaletteTransition(this);
      return iVar2;
    case 0xe:
      iVar2 = playback_stepContinuePalette();
      return iVar2;
    case 0xf:
      iVar2 = playback_stepWaitPaletteRender(this);
      return iVar2;
    case 0x10:
      iVar2 = playback_stepAdvanceToSound();
      return iVar2;
    case 0x11:
      iVar2 = playback_dispatchCuePoint();
      return iVar2;
    case 0x12:
      iVar2 = playback_stepProcessSound(in_EAX);
      return iVar2;
    case 0x13:
      iVar2 = playback_checkCuePointReached();
      return iVar2;
    case 0x14:
      Ordinal_1900(&param_1);
      iVar2 = playback_checkCuePointReached();
      return iVar2;
    case 0x15:
      iVar2 = playback_stepCheckCuePoint();
      return iVar2;
    case 0x16:
      iVar2 = playback_stepWaitTempo(this);
      return iVar2;
    case 0x17:
      iVar2 = playback_stepWaitTempoRender(this);
      return iVar2;
    case 0x18:
      iVar2 = playback_stepRenderTempo(this);
      return iVar2;
    case 0x19:
      iVar2 = playback_stepWaitTempoFrame(this);
      return iVar2;
    case 0x1a:
      iVar2 = playback_stepFinishTempo();
      return iVar2;
    case 0x1b:
      iVar2 = playback_stepFinishFrame(in_EAX);
      return iVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_resetControlState (playback_resetControlState)
// Address: 680d93d0
// Size: 53 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resetControlState(int param_1)
{
  int extraout_EDX;
  
  *(undefined4 *)(param_1 + 0x5c) = 0;
  *(undefined4 *)(param_1 + 0x58) = 1;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  playback_setNextFrame(param_1,0);
  *(undefined4 *)(extraout_EDX + 100) = 0;
  *(undefined4 *)(extraout_EDX + 0x60) = 1;
  return 0;
}



// ============================================================
// Function: playback_getControlSize (FUN_680d9410)
// Address: 680d9410
// Size: 45 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getControlSize(int *param_1)
{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  
  piVar1 = param_1;
  bVar2 = playback_isStepActive((int)param_1);
  iVar3 = CONCAT31(extraout_var,bVar2);
  while (iVar3 == 0) {
    playback_dispatchStepAction(&param_1,piVar1,1);
    bVar2 = playback_isStepActive((int)piVar1);
    iVar3 = CONCAT31(extraout_var_00,bVar2);
  }
  return 0;
}



// ============================================================
// Function: playback_processControl (FUN_680d9440)
// Address: 680d9440
// Size: 178 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_processControl(int *param_1,int param_2)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar4;
  byte bVar5;
  int local_c;
  int local_8;
  
  bVar5 = 0;
  local_c = 0;
  if (param_2 == 0) {
    param_2 = 100;
  }
  local_8 = Ordinal_1541();
  display_renderSpriteLayer(param_1 + 0x45,local_8,param_2,0x100);
  while( true ) {
    bVar1 = bVar5 & 0xf;
    bVar5 = bVar5 + 1;
    if (bVar1 == 0xf) {
      local_8 = Ordinal_1541();
      bVar5 = 0;
    }
    iVar3 = playback_dispatchStepAction(&local_8,param_1,0);
    if (iVar3 == 2) {
      return 2;
    }
    bVar2 = playback_isStepActive((int)param_1);
    if (CONCAT31(extraout_var,bVar2) != 0) {
      return iVar3;
    }
    if ((param_1[0x17] == 0) &&
       (bVar2 = playback_isStepPastTransition((int)param_1), CONCAT31(extraout_var_00,bVar2) != 0)) break;
    if ((param_2 == -1) && (local_c = local_c + 1, local_c == 5)) {
      return iVar3;
    }
    iVar4 = display_renderSpriteFrame(param_1 + 0x45,local_8,(int *)0x0);
    if (iVar4 != 0) {
      return iVar3;
    }
  }
  return iVar3;
}



// ============================================================
// Function: playback_executeControlStep (playback_executeControlStep)
// Address: 680d9500
// Size: 118 bytes
// Params: byte * param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool playback_executeControlStep(byte *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  bool bVar4;
  
  bVar4 = false;
  if (*(int *)(param_1 + 0x60) != 0) {
    bVar4 = true;
    bVar1 = playback_isStepActive((int)param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      playback_getControlSize((int *)param_1);
    }
    playback_resetTimerState();
    param_1[0xe4] = 0;
    param_1[0xe5] = 0;
    param_1[0xe6] = 0;
    param_1[0xe7] = 0;
    param_1[0xe8] = 0;
    param_1[0xe9] = 0;
    param_1[0xea] = 0;
    param_1[0xeb] = 0;
    Ordinal_1913(0);
    Ordinal_1913(1);
    if (*(int *)(param_1 + 0x54) == 0) {
      uVar3 = playback_getLifecycleFlags(param_1);
      if (uVar3 == 0) {
        return false;
      }
    }
    else {
      iVar2 = playback_setFlagsAndDestroy(param_1,*(int *)(param_1 + 0x54));
      bVar4 = iVar2 == *(int *)(param_1 + 0x54);
      param_1[0x54] = 0;
      param_1[0x55] = 0;
      param_1[0x56] = 0;
      param_1[0x57] = 0;
    }
  }
  return bVar4;
}



// ============================================================
// Function: playback_getControlFlags (FUN_680d9580)
// Address: 680d9580
// Size: 45 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getControlFlags(int *param_1,int param_2)
{
  bool bVar1;
  undefined3 extraout_var;
  
  bVar1 = playback_isStepActive((int)param_1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    playback_getControlSize(param_1);
    param_1[0x1a] = param_2;
    return 0;
  }
  param_1[0x1a] = param_2;
  return 0;
}



// ============================================================
// Function: playback_getControlState (FUN_680d95b0)
// Address: 680d95b0
// Size: 19 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall playback_getControlState(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = Ordinal_1255(param_1);
  Ordinal_1042();
  return uVar1;
}



// ============================================================
// Function: playback_setControlState (FUN_680d95d0)
// Address: 680d95d0
// Size: 65 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_setControlState(undefined4 param_1)

{
  byte bVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int unaff_EDI;
  
  if (1 < unaff_EBX) {
    bVar1 = Ordinal_1411(param_1);
    if (bVar1 != 0) {
      if ((int)(uint)bVar1 < unaff_EBX) {
        uVar2 = Ordinal_1409(param_1);
        *(undefined1 *)((uint)bVar1 + unaff_EDI) = 0;
        return uVar2;
      }
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_findFirstControlState (playback_findFirstControlState)
// Address: 680d9620
// Size: 51 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_findFirstControlState(void)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = &DAT_6818e794;
  iVar1 = DAT_6818e794;
  while ((iVar1 != 0 && (iVar1 = playback_getControlState(piVar2[1]), iVar1 != 0))) {
    piVar2 = piVar2 + 2;
    iVar1 = *piVar2;
  }
  iVar1 = *piVar2;
  if (iVar1 == 0) {
    iVar1 = 1;
  }
  return iVar1;
}



// ============================================================
// Function: playback_lookupControlByChannel (playback_lookupControlByChannel)
// Address: 680d9660
// Size: 39 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_lookupControlByChannel(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  short unaff_SI;
  
  uVar1 = 0;
  puVar3 = &DAT_6818e794;
  if (DAT_6818e794 != 0) {
    iVar2 = DAT_6818e794;
    while (iVar2 != unaff_SI) {
      iVar2 = puVar3[2];
      puVar3 = puVar3 + 2;
      if (iVar2 == 0) {
        return uVar1;
      }
    }
    uVar1 = puVar3[1];
  }
  return uVar1;
}



// ============================================================
// Function: playback_getControlRef (FUN_680d9690)
// Address: 680d9690
// Size: 165 bytes
// Params: undefined1 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_getControlRef(undefined1 *param_1)
{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  int *piVar3;
  undefined1 *local_4c;
  undefined1 local_48 [64];
  uint local_8;
  
  if ((unaff_EBX != (int *)0x0) && (unaff_EBX[1] != 0)) {
    Ordinal_1114(unaff_EBX[1]);
    iVar1 = playback_getControlState(param_1);
    local_4c = param_1;
    if (iVar1 == 0) {
      Ordinal_1701(local_48,0x40);
      local_4c = local_48;
    }
    iVar1 = *unaff_EBX;
    piVar3 = unaff_EBX + 2;
    while ((iVar1 != 0 && ((piVar3[5] == 0 || (iVar2 = playback_getControlState(local_4c), iVar2 != 0))))) {
      piVar3 = piVar3 + 7;
      iVar1 = iVar1 + -1;
    }
    Ordinal_1115(unaff_EBX[1]);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: playback_addControlRef (playback_addControlRef)
// Address: 680d9740
// Size: 405 bytes
// Params: void * this, undefined1 * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall playback_addControlRef(void *this,undefined1 *param_1)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  short sVar5;
  int local_50;
  undefined1 local_48 [64];
  uint local_8;
  
  local_50 = *(int *)this;
  sVar5 = -0x8000;
  if (local_50 == 0) {
    local_50 = Ordinal_1111(0x24,1);
    *(int *)this = local_50;
    if (local_50 == 0) goto LAB_680d98bf;
    piVar2 = (int *)Ordinal_1114(local_50);
    iVar1 = Ordinal_1111(0,0);
    piVar2[1] = iVar1;
    if (iVar1 != 0) goto LAB_680d9799;
    Ordinal_1115(local_50);
    Ordinal_1113(this);
  }
  else {
    iVar1 = Ordinal_1116(local_50);
    iVar1 = Ordinal_1117(this,iVar1 + 0x1c,1);
    if (iVar1 == 0) goto LAB_680d98bf;
    piVar2 = (int *)Ordinal_1114(local_50);
LAB_680d9799:
    iVar1 = *piVar2;
    if (0 < iVar1) {
      piVar3 = piVar2 + 2;
      iVar4 = iVar1;
      do {
        if (sVar5 < (short)*piVar3) {
          sVar5 = (short)*piVar3;
        }
        piVar3 = piVar3 + 7;
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      if (0x7ffe < sVar5) {
        if ((short)piVar2[2] == 0x7fff) {
          sVar5 = 0x7ffe;
        }
        else {
          sVar5 = (short)piVar2[2] + 1;
        }
        do {
          iVar4 = 0;
          piVar3 = piVar2 + 2;
          while( true ) {
            if (iVar1 <= iVar4) goto LAB_680d97c3;
            if ((short)*piVar3 == sVar5) break;
            iVar4 = iVar4 + 1;
            piVar3 = piVar3 + 7;
          }
          sVar5 = sVar5 + 1;
        } while( true );
      }
    }
    sVar5 = sVar5 + 1;
LAB_680d97c3:
    piVar3 = piVar2 + iVar1 * 7 + 2;
    Ordinal_1130(piVar3,0x1c);
    *(short *)piVar3 = sVar5;
    iVar1 = Ordinal_1116(piVar2[1]);
    piVar3[1] = iVar1;
    piVar3[5] = 1;
    piVar3[6] = 1;
    iVar1 = playback_getControlState(param_1);
    if (iVar1 == 0) {
      Ordinal_1701(local_48,0x40);
      param_1 = local_48;
    }
    iVar1 = Ordinal_1201(param_1);
    iVar1 = Ordinal_1121(piVar2 + 1,param_1,iVar1 + 1);
    if (iVar1 == 0) {
      Ordinal_1121(this,0,0xffffffe4);
    }
    else {
      *piVar2 = *piVar2 + 1;
    }
  }
  Ordinal_1115(local_50);
LAB_680d98bf:
  return 0;
}



// ============================================================
// Function: playback_destroyAllControlRefs (playback_destroyAllControlRefs)
// Address: 680d98e0
// Size: 75 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_destroyAllControlRefs(void)
{
  int *piVar1;
  int *unaff_EBX;
  int *piVar2;
  
  if ((unaff_EBX != (int *)0x0) && (*unaff_EBX != 0)) {
    piVar1 = (int *)Ordinal_1114(*unaff_EBX);
    Ordinal_1113(piVar1 + 1);
    *piVar1 = *piVar1 + -1;
    if (-1 < *piVar1) {
      piVar2 = piVar1 + 6;
      do {
        Ordinal_1113(piVar2 + -1);
        Ordinal_1113(piVar2);
        piVar2 = piVar2 + 7;
        *piVar1 = *piVar1 + -1;
      } while (-1 < *piVar1);
    }
    Ordinal_1115(*unaff_EBX);
    Ordinal_1113();
  }
  return 0;
}



// ============================================================
// Function: playback_createControlPairs (playback_createControlPairs)
// Address: 680d9930
// Size: 74 bytes
// Params: short * param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_createControlPairs(short *param_1)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  
  iVar1 = Ordinal_1111(in_EAX * 8,0);
  if (iVar1 != 0) {
    piVar2 = (int *)Ordinal_1114(iVar1);
    while (in_EAX = in_EAX + -1, -1 < in_EAX) {
      *piVar2 = (int)*param_1;
      piVar2[1] = (int)param_1[1];
      param_1 = param_1 + 2;
      piVar2 = piVar2 + 2;
    }
    if (piVar2 != (int *)0x0) {
      Ordinal_1115(iVar1);
    }
  }
  return iVar1;
}



// ============================================================
// Function: playback_setControlProperty (FUN_680d9980)
// Address: 680d9980
// Size: 192 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_setControlProperty(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  
  iVar6 = 0;
  uVar7 = 0;
  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {
    uVar2 = Ordinal_1157(*(int *)(param_1 + 8));
    iVar3 = Ordinal_1154(*(undefined4 *)(param_1 + 8));
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        puVar4 = (undefined4 *)Ordinal_1156(*(undefined4 *)(param_1 + 8),uVar2,iVar5);
        uVar7 = *puVar4;
        iVar6 = Ordinal_1114(uVar7);
        sVar1 = Ordinal_1207(iVar6 + 8,param_2,0x20);
        if ((sVar1 == 0) && (sVar1 = Ordinal_1207(iVar6 + 0x28,param_3,0x20), sVar1 == 0)) break;
        iVar6 = Ordinal_1115(uVar7);
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
    Ordinal_1158(*(undefined4 *)(param_1 + 8),uVar2);
    if (iVar6 != 0) {
      *param_4 = uVar7;
      return iVar6;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_createControlProperty (playback_createControlProperty)
// Address: 680d9a40
// Size: 181 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * playback_createControlProperty(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int in_EAX;
  int iVar1;
  int *piVar2;
  int local_8;
  
  local_8 = 0;
  if (*(int *)(in_EAX + 8) == 0) {
    iVar1 = Ordinal_1150(0x10,0x10,4);
    *(int *)(in_EAX + 8) = iVar1;
    if (iVar1 == 0) goto LAB_680d9ae2;
  }
  local_8 = Ordinal_1111(200,0);
  if (local_8 != 0) {
    iVar1 = Ordinal_1152(*(undefined4 *)(in_EAX + 8),&local_8);
    if (iVar1 != 0) {
      piVar2 = (int *)Ordinal_1114(local_8);
      Ordinal_1203(piVar2 + 2,param_1,0x20);
      Ordinal_1203(piVar2 + 10,param_2,0x20);
      *piVar2 = 0x80;
      piVar2[1] = 0xff;
      iVar1 = 0x80;
      do {
        *(char *)((iVar1 - *piVar2) + 0x48 + (int)piVar2) = (char)iVar1;
        iVar1 = iVar1 + 1;
      } while (iVar1 <= piVar2[1]);
      *param_3 = local_8;
      return piVar2;
    }
  }
LAB_680d9ae2:
  Ordinal_1113(&local_8);
  return (int *)0x0;
}



// ============================================================
// Function: playback_checkDoubleByteSupport (playback_checkDoubleByteSupport)
// Address: 680d9b00
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_checkDoubleByteSupport(void)
{
  GetSystemMetrics(0x2a);
  return 0;
}



// ============================================================
// Function: playback_isDoubleByteLeadChar (playback_isDoubleByteLeadChar)
// Address: 680d9b10
// Size: 11 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_isDoubleByteLeadChar(void)
{
  BYTE *in_EAX;
  
  IsDBCSLeadByte(*in_EAX);
  return 0;
}



// ============================================================
// Function: playback_readDoubleByteChar (playback_readDoubleByteChar)
// Address: 680d9b20
// Size: 49 bytes
// Return: ushort
// Calling convention: __stdcall
// ============================================================

ushort playback_readDoubleByteChar(void)

{
  int iVar1;
  byte *unaff_ESI;
  undefined4 *unaff_EDI;
  
  iVar1 = playback_checkDoubleByteSupport();
  if (iVar1 != 0) {
    iVar1 = playback_isDoubleByteLeadChar();
    if (iVar1 != 0) {
      *unaff_EDI = 2;
      return CONCAT11(*unaff_ESI,unaff_ESI[1]);
    }
  }
  *unaff_EDI = 1;
  return (ushort)*unaff_ESI;
}



// ============================================================
// Function: playback_writeDoubleByteChar (playback_writeDoubleByteChar)
// Address: 680d9b60
// Size: 21 bytes
// Params: undefined1 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_writeDoubleByteChar(undefined1 *param_1)
{
  uint in_EAX;
  
  if ((in_EAX & 0xff00) != 0) {
    *param_1 = (char)(in_EAX >> 8);
    param_1[1] = (char)in_EAX;
    return 0;
  }
  *param_1 = (char)in_EAX;
  return 0;
}



// ============================================================
// Function: playback_getControlRef2 (FUN_680d9b80)
// Address: 680d9b80
// Size: 79 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getControlRef2(void)

{
  char *pcVar1;
  int iVar2;
  undefined4 *unaff_EDI;
  int local_8;
  
  pcVar1 = xtra_trimString((char *)*unaff_EDI);
  iVar2 = Ordinal_1252(pcVar1,&local_8);
  if (iVar2 == 0x3d) {
    pcVar1 = pcVar1 + local_8;
    iVar2 = Ordinal_1252(pcVar1,&local_8);
    if (iVar2 == 0x3e) {
      pcVar1 = xtra_trimString(pcVar1 + local_8);
      *unaff_EDI = pcVar1;
      return 1;
    }
  }
  return 0;
}



