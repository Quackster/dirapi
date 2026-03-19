// Module: playback
// Topic: Core playback lifecycle - registration, initialization, setup, reset, frame advance
// Address range: 0x680d01c0 - 0x680d1cb0
// Functions (62):
//   playback_registerPaletteEvent, playback_clearPaletteEvents, playback_buildChannelMapByType, playback_resetPaletteState, playback_initScore
//   playback_addChannelIndex, playback_importChannelSprites, playback_updatePlaybackFlags, playback_checkSoundChannels, playback_initScoreEx
//   playback_clearSpriteDefaults, playback_toggleSoundChannels, playback_resumeSoundChannels, playback_notifyStageResize, playback_initPlaybackState
//   playback_allocateChannelBuffers, playback_dispatchLifecycle, playback_refreshStageDisplay, playback_createLifecycle, playback_notifyRecursiveChannels
//   playback_updateAllSprites, playback_resetPlaybackPosition, playback_destroyLifecycle, playback_reinitScore, playback_processChannelTypes
//   playback_initLifecycleEx, playback_getCurrentFrame, playback_getMaxFrame, playback_findSpriteByState
//   playback_getLifecycleCount, playback_processLifecycle, playback_setTempo, playback_getStageRect
//   playback_setSoundProperty, playback_toggleSoundPause, playback_setSpriteFrame
//   playback_invalidateSpriteRegion, playback_getLifecycleBlock, playback_getBlockFlag, playback_setScaleRatio
//   playback_getLifecycleSize, playback_getChannelCount, playback_getChannelCountEx, playback_findChannelBySpriteData, playback_initLifecycleBlock
//   playback_initLifecycle, playback_setLifecycleData, playback_applyLifecycleTransformReverse, playback_applyLifecycleIntersect, playback_applyLifecycleIntersectReverse
//   playback_scaleLifecycleCoords, playback_getLifecycleRef, playback_walkLifecycleChain, playback_getLifecycleData, playback_countLifecycleDepth
//   playback_clearSpriteDisplayState, playback_getLifecycleState, playback_resetLifecycle, playback_advanceFrame, playback_recreateLifecycleIfActive
//   playback_getLifecycleValue, playback_setLifecycleState, playback_setLifecycleRef, playback_resetAllState, playback_getLifecycleFlags
//   playback_setLifecycleFlags

// ============================================================
// Function: playback_registerPaletteEvent (playback_registerPaletteEvent)
// Address: 680d01c0
// Size: 51 bytes
// Params: void * param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_registerPaletteEvent(void *param_1,int param_2)
{
  undefined4 in_EAX;
  uint uVar1;
  int unaff_ESI;
  
  if ((unaff_ESI != 0) && (param_1 != (void *)0x0)) {
    *(int *)(unaff_ESI + -0x1a) = *(int *)(unaff_ESI + -0x1a) + 1;
    *(void **)(unaff_ESI + -0x16) = param_1;
    *(undefined4 *)(unaff_ESI + -0x12) = in_EAX;
    uVar1 = rendering_computePaletteHash(param_1,param_2);
    if ((&DAT_68197be0)[uVar1] != 0) {
      rendering_processChannelEvent(&DAT_68197be0 + uVar1);
    }
    (&DAT_68197be0)[uVar1] = unaff_ESI;
  }
  return 0;
}



// ============================================================
// Function: playback_clearPaletteEvents (playback_clearPaletteEvents)
// Address: 680d0200
// Size: 87 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_clearPaletteEvents(void)
{
  int iVar1;
  bool bVar2;
  int unaff_EBX;
  int *piVar3;
  int unaff_EDI;
  
  if ((unaff_EBX != 0) || (unaff_EDI != 0)) {
    piVar3 = &DAT_68197be0;
    do {
      iVar1 = *piVar3;
      if (iVar1 != 0) {
        bVar2 = false;
        if ((unaff_EDI != 0) && (unaff_EDI == *(int *)(iVar1 + -0x12))) {
          bVar2 = true;
        }
        if ((unaff_EBX != 0) && (unaff_EBX == *(int *)(iVar1 + -0x16))) {
          bVar2 = true;
        }
        if (((*(int *)(iVar1 + -0x12) == 0) && (*(int *)(iVar1 + -0x16) == 0)) || (bVar2)) {
          rendering_processChannelEvent(piVar3);
        }
      }
      piVar3 = piVar3 + 1;
    } while ((int)piVar3 < 0x68197fe0);
  }
  return 0;
}



// ============================================================
// Function: playback_buildChannelMapByType (playback_buildChannelMapByType)
// Address: 680d0260
// Size: 116 bytes
// Params: void * this, undefined4 param_1, void * param_2, int param_3, int param_4
// Return: undefined2 *
// Calling convention: __thiscall
// ============================================================

undefined2 * __thiscall
playback_buildChannelMapByType(void *this,undefined4 param_1,void *param_2,int param_3,int param_4)

{
  undefined2 *puVar1;
  void *this_00;
  
  puVar1 = (undefined2 *)rendering_lookupPaletteCache(this,param_2);
  if (puVar1 == (undefined2 *)0x0) {
    switch(param_3) {
    case 1:
      puVar1 = rendering_buildChannelReverseMap((int)param_2);
      break;
    case 2:
      puVar1 = (undefined2 *)rendering_buildChannelMap((int)param_2);
      break;
    case 3:
      if (param_4 == 0) {
        return (undefined2 *)0x0;
      }
      puVar1 = rendering_buildChannelScoreReverseMap(this_00,(int)param_2,param_4);
      break;
    case 4:
      if (param_4 == 0) {
        return (undefined2 *)0x0;
      }
      puVar1 = (undefined2 *)rendering_buildChannelScoreMap((int)param_2,param_4);
      break;
    default:
      goto switchD_680d0287_default;
    }
    if (puVar1 != (undefined2 *)0x0) {
      playback_registerPaletteEvent(param_2,param_3);
    }
  }
switchD_680d0287_default:
  return puVar1;
}



// ============================================================
// Function: playback_resetPaletteState (playback_resetPaletteState)
// Address: 680d02f0
// Size: 21 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resetPaletteState(void)
{
  playback_clearPaletteEvents();
  return 0;
}



// ============================================================
// Function: playback_initScore (FUN_680d0310)
// Address: 680d0310
// Size: 31 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_initScore(undefined4 param_1)
{
  playback_clearPaletteEvents();
  Ordinal_1113(param_1);
  return 0;
}



// ============================================================
// Function: playback_addChannelIndex (playback_addChannelIndex)
// Address: 680d0330
// Size: 187 bytes
// Params: undefined4 param_1, short param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_addChannelIndex(undefined4 param_1,short param_2)

{
  int iVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined2 uVar6;
  undefined2 extraout_var;
  short *psVar7;
  undefined2 local_8;
  
  local_8 = 0xfffe;
  piVar3 = (int *)Ordinal_1114(param_1);
  sVar2 = param_2;
  if (piVar3 == (int *)0x0) {
    return 0xfffe;
  }
  iVar5 = *piVar3;
  iVar4 = 0;
  if (0 < iVar5) {
    psVar7 = (short *)((int)piVar3 + 10);
    do {
      if (*psVar7 == param_2) {
        local_8 = (undefined2)iVar4;
        goto LAB_680d03be;
      }
      iVar4 = iVar4 + 1;
      psVar7 = psVar7 + 1;
    } while (iVar4 < iVar5);
  }
  iVar1 = piVar3[1];
  if (iVar5 == iVar1) {
    piVar3 = (int *)Ordinal_1115(param_1);
    iVar5 = Ordinal_1117(&param_1,iVar1 + 0x10 + iVar1 + 4,1);
    iVar4 = 0;
    if (iVar5 == 0) goto LAB_680d03be;
    piVar3 = (int *)Ordinal_1114(param_1);
    piVar3[1] = iVar1 + 4;
  }
  *(short *)((int)piVar3 + *piVar3 * 2 + 10) = sVar2;
  local_8 = (undefined2)*piVar3;
  *piVar3 = *piVar3 + 1;
  iVar4 = playback_clearPaletteEvents();
LAB_680d03be:
  uVar6 = (undefined2)((uint)iVar4 >> 0x10);
  if (piVar3 != (int *)0x0) {
    Ordinal_1115(param_1);
    uVar6 = extraout_var;
  }
  return CONCAT22(uVar6,local_8);
}



// ============================================================
// Function: playback_importChannelSprites (playback_importChannelSprites)
// Address: 680d03f0
// Size: 404 bytes
// Params: int * param_1, int param_2, int param_3, int param_4, int * param_5, void * param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_importChannelSprites(int *param_1,int param_2,int param_3,int param_4,int *param_5,void *param_6)

{
  bool bVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  void *this;
  int iVar7;
  int local_14;
  int local_c;
  int *local_8;
  
  local_c = 0;
  local_8 = (int *)0x0;
  local_14 = 0;
  bVar1 = false;
  if (((param_2 != 0) && (param_3 != 0)) && (param_5 != (int *)0x0)) {
    iVar3 = rendering_getChannelSprite((int)param_1,(short)param_4);
    if (iVar3 != 0) {
      iVar4 = rendering_refreshChannel(iVar3 + 0x68);
      local_14 = Ordinal_1042();
      local_8 = (int *)cast_writeDataEntry(param_2,param_3,1);
      if (local_8 == (int *)0x0) goto LAB_680d055d;
      iVar5 = Ordinal_1042();
      if (iVar5 == 0) {
        iVar5 = Ordinal_39(local_8);
        iVar7 = (int)((iVar5 + 3 >> 0x1f & 3U) + iVar5 + 3) >> 2;
        local_c = Ordinal_1111(iVar7 * 8 + 0xc,0);
        if (local_c != 0) {
          piVar6 = (int *)Ordinal_1114(local_c);
          piVar6[1] = iVar7 * 4;
          iVar7 = 0;
          *piVar6 = 0;
          *(undefined2 *)(piVar6 + 2) = (undefined2)param_4;
          if (0 < iVar5) {
            param_2 = 10;
            do {
              param_4 = cast_lookupDataEntry((int)local_8,iVar7,0);
              if (param_4 == 0) goto LAB_680d053f;
              Ordinal_1116(param_4);
              this = (void *)Ordinal_1114(param_4);
              uVar2 = rendering_importChannelSpriteData(this,param_1,param_5,iVar3,iVar4,param_6);
              *(undefined2 *)(param_2 + (int)piVar6) = uVar2;
              Ordinal_1115(param_4);
              Ordinal_1113(&param_4);
              *piVar6 = *piVar6 + 1;
              iVar7 = iVar7 + 1;
              param_2 = param_2 + 2;
            } while (iVar7 < iVar5);
          }
          bVar1 = true;
LAB_680d053f:
          Ordinal_1115(local_c);
        }
      }
    }
    if (local_8 != (int *)0x0) {
      Ordinal_36((int *)&local_8);
    }
    if (bVar1) goto LAB_680d0566;
  }
LAB_680d055d:
  playback_initScore(&local_c);
LAB_680d0566:
  Ordinal_1042();
  if (local_14 != 0) {
    Ordinal_1040(local_14);
  }
  return local_c;
}



// ============================================================
// Function: playback_updatePlaybackFlags (playback_updatePlaybackFlags)
// Address: 680d0590
// Size: 53 bytes
// Params: undefined4 param_1, uint * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_updatePlaybackFlags(undefined4 param_1,uint *param_2)
{
  uint uVar1;
  
  if (param_2 != (uint *)0x0) {
    uVar1 = *param_2;
    if (((uVar1 & 0x20) != 0) && ((uVar1 & 0x10) != 0)) {
      *param_2 = (uVar1 ^ 8) & 8 ^ uVar1;
      return 0;
    }
    *param_2 = uVar1 & 8 ^ uVar1;
  }
  return 0;
}



// ============================================================
// Function: playback_checkSoundChannels (playback_checkSoundChannels)
// Address: 680d05d0
// Size: 12 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_checkSoundChannels(void)
{
  byte *in_EAX;
  
  if ((*in_EAX & 1) != 0) {
    playback_playSoundChannels((int)in_EAX);
  }
  return 0;
}



// ============================================================
// Function: playback_initScoreEx (FUN_680d05e0)
// Address: 680d05e0
// Size: 41 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_initScoreEx(int param_1)
{
  uint *unaff_ESI;
  
  if ((unaff_ESI != (uint *)0x0) && ((*unaff_ESI & 8) != 0)) {
    playback_readScoreFrameProperties((byte *)unaff_ESI);
    if (param_1 != 0) {
      playback_checkSoundChannels();
    }
    rendering_updateSpriteChannels(unaff_ESI);
  }
  return 0;
}



// ============================================================
// Function: playback_clearSpriteDefaults (playback_clearSpriteDefaults)
// Address: 680d0610
// Size: 46 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_clearSpriteDefaults(void)
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0x124);
  if (*(int *)(unaff_ESI + 0x120) <= iVar2) {
    iVar3 = iVar2 * 400;
    do {
      puVar1 = (uint *)(*(int *)(unaff_ESI + 0x34) + 0x58 + iVar3);
      *puVar1 = *puVar1 & 0xffffffdf;
      iVar2 = iVar2 + -1;
      iVar3 = iVar3 + -400;
    } while (*(int *)(unaff_ESI + 0x120) <= iVar2);
  }
  return 0;
}



// ============================================================
// Function: playback_toggleSoundChannels (playback_toggleSoundChannels)
// Address: 680d0640
// Size: 95 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_toggleSoundChannels(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  
  iVar3 = *(int *)(unaff_EDI + 0x120);
  if (iVar3 <= *(int *)(unaff_EDI + 0x124)) {
    iVar2 = iVar3 * 400;
    do {
      if ((*(char *)(iVar3 + *(int *)(unaff_EDI + 0x30)) == '\x06') &&
         (iVar1 = *(int *)(*(int *)(unaff_EDI + 0x34) + 0x14c + iVar2), iVar1 != 0)) {
        if (param_1 == 0) {
          Ordinal_1970(iVar1,0);
        }
        else {
          Ordinal_1971(iVar1);
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 400;
    } while (iVar3 <= *(int *)(unaff_EDI + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_resumeSoundChannels (playback_resumeSoundChannels)
// Address: 680d06b0
// Size: 8 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resumeSoundChannels(void)
{
  playback_toggleSoundChannels(1);
  return 0;
}



// ============================================================
// Function: playback_notifyStageResize (playback_notifyStageResize)
// Address: 680d06c0
// Size: 112 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_notifyStageResize(void)
{
  int local_18;
  undefined4 uVar1;
  int iVar2;
  int *unaff_ESI;
  /* FIXUP(C2040: 'local_18': 'undefined1): undefined1 local_18 [16]; */
  uint local_8;
  
  Ordinal_1060(local_18,unaff_ESI[2],unaff_ESI[3],unaff_ESI[4] + unaff_ESI[2],
               unaff_ESI[5] + unaff_ESI[3]);
  uVar1 = *(undefined4 *)(*(int *)(*unaff_ESI + 4) + 0xc);
  iVar2 = media_getDataPtr(*(int **)(*(int *)(*unaff_ESI + 8) + 4));
  if (*(code **)(iVar2 + 0x38) != (code *)0x0) {
    iVar2 = (**(code **)(iVar2 + 0x38))(uVar1,local_18);
    if (iVar2 != 0) goto LAB_680d0721;
  }
  Ordinal_1834(unaff_ESI[1],local_18);
LAB_680d0721:
  return 0;
}



// ============================================================
// Function: playback_initPlaybackState (playback_initPlaybackState)
// Address: 680d0730
// Size: 125 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_initPlaybackState(int param_1,int param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (param_1 != 0) {
    Ordinal_1130(param_1,4);
    iVar3 = lingo_dispatchVtableOp(param_1,(undefined4 *)(param_1 + 0x184));
    if (iVar3 == 0) {
      piVar1 = *(int **)(param_1 + 0x184);
      (**(code **)(*piVar1 + 8))(piVar1);
    }
    iVar3 = media_writePlaybackData(*(undefined4 *)(*(int *)(param_2 + 4) + 8),0,param_1);
    *(int *)(param_1 + 0x28) = iVar3;
    *(int *)(param_1 + 0x20) = param_2;
    *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(*(int *)(param_2 + 4) + 8);
    *(undefined2 *)(param_1 + 0x154) = 0x100;
    *(undefined4 *)(param_1 + 0x120) = 0;
    *(undefined4 *)(param_1 + 0x124) = 0xffffffff;
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: playback_allocateChannelBuffers (playback_allocateChannelBuffers)
// Address: 680d07b0
// Size: 273 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_allocateChannelBuffers(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int local_10;
  int local_c;
  int local_8;
  
  uVar6 = 1;
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  if (*(int *)(param_1 + 0x2c) != 0) {
    local_8 = Ordinal_1124(*(int *)(param_1 + 0x2c) * 400);
    local_c = Ordinal_1124((*(int *)(param_1 + 0x2c) + 1) * 0x34);
    local_10 = Ordinal_1124(*(undefined4 *)(param_1 + 0x2c));
    if (((local_8 == 0) || (local_c == 0)) || (local_10 == 0)) {
      Ordinal_1125(&local_8);
      Ordinal_1125(&local_c);
      Ordinal_1125(&local_10);
      *(undefined4 *)(param_1 + 0x2c) = 0;
      *(undefined4 *)(param_1 + 0x120) = 0;
      *(undefined4 *)(param_1 + 0x124) = 0xffffffff;
      uVar6 = 0;
    }
  }
  *(int *)(param_1 + 0x34) = local_8;
  *(int *)(param_1 + 0x38) = local_c;
  *(int *)(param_1 + 0x30) = local_10;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  if (0 < *(int *)(param_1 + 0x2c)) {
    iVar5 = 0;
    iVar4 = 1;
    do {
      iVar2 = *(int *)(param_1 + 0x34);
      *(int *)(iVar2 + 0x48 + iVar5) = iVar4;
      *(int *)(iVar2 + 0x44 + iVar5) = iVar4;
      iVar5 = iVar5 + 400;
      bVar3 = iVar4 < *(int *)(param_1 + 0x2c);
      iVar4 = iVar4 + 1;
    } while (bVar3);
  }
  puVar1 = (undefined4 *)(param_1 + 0x184);
  *puVar1 = 0;
  iVar4 = lingo_dispatchVtableOp(param_1,puVar1);
  if (iVar4 == 0) {
    (**(code **)(*(int *)*puVar1 + 8))((int *)*puVar1);
  }
  if (0 < *(int *)(param_1 + 0x2c)) {
    iVar4 = *(int *)(param_1 + 0x38);
    *(undefined4 *)(iVar4 + 0x14) = 0xffffffff;
    *(undefined4 *)(iVar4 + 0x20) = 1;
    *(undefined4 *)(iVar4 + 0x24) = 1;
  }
  return uVar6;
}



// ============================================================
// Function: playback_dispatchLifecycle (FUN_680d08d0)
// Address: 680d08d0
// Size: 39 bytes
// Params: uint * param_1, uint param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_dispatchLifecycle(uint *param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (uint *)0x0) && (param_2 != 0)) {
    *param_1 = *param_1 | 0x20;
    param_1[9] = param_2;
    playback_updatePlaybackFlags(param_2,param_1);
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: playback_refreshStageDisplay (playback_refreshStageDisplay)
// Address: 680d0900
// Size: 31 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_refreshStageDisplay(int *param_1)
{
  rendering_updateStageDisplay(param_1[9]);
  rendering_setStageSize(param_1,param_1[9]);
  return 0;
}



// ============================================================
// Function: playback_createLifecycle (FUN_680d0920)
// Address: 680d0920
// Size: 378 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_createLifecycle(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  undefined4 *puVar8;
  int iVar9;
  int local_10;
  int local_c;
  
  iVar3 = param_1;
  Ordinal_1163(param_1 + 0x3c);
  local_10 = 0;
  if (0 < *(int *)(param_1 + 0x2c)) {
    local_c = 0;
    param_1 = 0;
    do {
      puVar8 = (undefined4 *)(*(int *)(iVar3 + 0x34) + param_1);
      iVar9 = *(int *)(iVar3 + 0x38) + local_c;
      if (puVar8[0xc] != 0) {
        playback_updateSpriteData(iVar3,puVar8);
        playback_getSpriteRenderData(iVar3,(int)puVar8);
      }
      if ((*(int *)(iVar9 + 0x20) == 2) && (*(int *)(iVar9 + 0x24) != 0)) {
        Ordinal_1762(iVar9 + 0x24);
      }
      else if ((*(int *)(iVar9 + 0x20) == 4) && (*(int **)(iVar9 + 0x24) != (int *)0x0)) {
        media_dispatchDestroy(iVar3,*(int **)(iVar9 + 0x24));
      }
      Ordinal_1130(iVar9 + 0x14,0x18);
      param_1 = param_1 + 400;
      local_c = local_c + 0x34;
      local_10 = local_10 + 1;
      *(undefined4 *)(iVar9 + 0x2c) = 0;
      *(undefined2 *)(iVar9 + 0x30) = 0;
    } while (local_10 < *(int *)(iVar3 + 0x2c));
  }
  iVar9 = 1000;
  if (*(int **)(iVar3 + 0x28) != (int *)0x0) {
    iVar9 = media_isScoreReady(*(int **)(iVar3 + 0x28));
  }
  if (*(int *)(iVar3 + 0x2c) != iVar9) {
    piVar1 = (int *)(iVar3 + 0x34);
    Ordinal_1125(piVar1);
    Ordinal_1125(iVar3 + 0x38);
    Ordinal_1125(iVar3 + 0x30);
    iVar4 = Ordinal_1124(iVar9 * 400);
    *piVar1 = iVar4;
    uVar5 = Ordinal_1124((iVar9 + 1) * 0x34);
    *(undefined4 *)(iVar3 + 0x38) = uVar5;
    iVar4 = Ordinal_1124(iVar9);
    *(int *)(iVar3 + 0x30) = iVar4;
    if (((*piVar1 == 0) || (*(int *)(iVar3 + 0x38) == 0)) || (iVar4 == 0)) {
      iVar9 = 0;
    }
    *(undefined4 *)(iVar3 + 0x120) = 0;
    *(int *)(iVar3 + 0x2c) = iVar9;
    *(int *)(iVar3 + 0x124) = iVar9 + -1;
  }
  if (0 < iVar9) {
    iVar6 = 1;
    iVar7 = 0;
    iVar4 = iVar9;
    do {
      iVar2 = *(int *)(iVar3 + 0x34);
      *(int *)(iVar2 + 0x48 + iVar7) = iVar6;
      *(int *)(iVar2 + 0x44 + iVar7) = iVar6;
      iVar7 = iVar7 + 400;
      iVar6 = iVar6 + 1;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  *(undefined4 *)(iVar3 + 0x40) = 1;
  if (0 < iVar9) {
    iVar3 = *(int *)(iVar3 + 0x38);
    *(undefined4 *)(iVar3 + 0x14) = 0xffffffff;
    *(undefined4 *)(iVar3 + 0x20) = 1;
    *(undefined4 *)(iVar3 + 0x24) = 1;
  }
  return 0;
}



// ============================================================
// Function: playback_notifyRecursiveChannels (playback_notifyRecursiveChannels)
// Address: 680d0aa0
// Size: 143 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_notifyRecursiveChannels(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((param_2 != 0) && (iVar3 = *(int *)(param_1 + 0x120), iVar3 <= *(int *)(param_1 + 0x124))) {
    iVar2 = iVar3 * 400;
    do {
      if (((byte)(*(char *)(iVar3 + *(int *)(param_1 + 0x30)) - 4U) < 2) &&
         (iVar1 = *(int *)(*(int *)(param_1 + 0x34) + 0x14c + iVar2), iVar1 != 0)) {
        playback_notifyRecursiveChannels(iVar1,param_2);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 400;
    } while (iVar3 <= *(int *)(param_1 + 0x124));
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x20) + 8);
  if (iVar3 == 0) {
    iVar3 = *(int *)(**(int **)(param_1 + 0x18) + 0x14);
    if (iVar3 != 0) {
      events_releaseSpriteSlotObjects(iVar3,*(undefined4 **)(param_1 + 0x38),*(int *)(param_1 + 0x2c));
    }
    return 0;
  }
  events_removeAllSpriteSlots(iVar3,param_1);
  return 0;
}



// ============================================================
// Function: playback_updateAllSprites (playback_updateAllSprites)
// Address: 680d0b30
// Size: 71 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_updateAllSprites(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x120);
  if (iVar2 <= *(int *)(param_1 + 0x124)) {
    iVar1 = iVar2 * 400;
    do {
      playback_teardownSpriteState(param_1,(undefined4 *)(*(int *)(param_1 + 0x34) + iVar1));
      iVar2 = iVar2 + 1;
      iVar1 = iVar1 + 400;
    } while (iVar2 <= *(int *)(param_1 + 0x124));
  }
  playback_resumeSoundChannels();
  return 0;
}



// ============================================================
// Function: playback_resetPlaybackPosition (playback_resetPlaybackPosition)
// Address: 680d0b80
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resetPlaybackPosition(int param_1)
{
  *(undefined4 *)(param_1 + 0x180) = 0;
  media_getPlaybackPosition(*(int *)(param_1 + 0x28));
  return 0;
}



// ============================================================
// Function: playback_destroyLifecycle (FUN_680d0ba0)
// Address: 680d0ba0
// Size: 84 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_destroyLifecycle(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x120);
  if (iVar3 <= *(int *)(param_1 + 0x124)) {
    iVar2 = iVar3 * 400;
    do {
      if (((byte)(*(char *)(iVar3 + *(int *)(param_1 + 0x30)) - 4U) < 2) &&
         (puVar1 = (undefined4 *)(*(int *)(param_1 + 0x34) + iVar2),
         (*(byte *)(puVar1 + 0x14) & 2) == 0)) {
        playback_destroySpriteInstance(param_1,puVar1);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 400;
    } while (iVar3 <= *(int *)(param_1 + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_reinitScore (playback_reinitScore)
// Address: 680d0c00
// Size: 19 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_reinitScore(void)
{
  playback_initScoreEx(1);
  return 0;
}



// ============================================================
// Function: playback_processChannelTypes (playback_processChannelTypes)
// Address: 680d0c20
// Size: 143 bytes
// Params: byte * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_processChannelTypes(byte *param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) &&
     (iVar3 = *(int *)(param_1 + 0x120), iVar3 <= *(int *)(param_1 + 0x124))) {
    iVar2 = iVar3 * 400;
    do {
      if (*(char *)(iVar3 + *(int *)(param_1 + 0x30)) != '\0') {
        puVar1 = (undefined4 *)(*(int *)(param_1 + 0x34) + iVar2);
        switch(*(char *)(iVar3 + *(int *)(param_1 + 0x30))) {
        case '\x03':
        case '\x06':
        case '\t':
          if ((*(byte *)(puVar1 + 0x14) & 2) == 0) {
            playback_processChannelScript((int)param_1,puVar1,param_2);
          }
          break;
        case '\x04':
        case '\x05':
          if ((*(byte *)(puVar1 + 0x14) & 2) == 0) {
            playback_processChannelTypes((byte *)puVar1[0x53],param_2);
          }
        }
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 400;
    } while (iVar3 <= *(int *)(param_1 + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_initLifecycleEx (FUN_680d0cd0)
// Address: 680d0cd0
// Size: 123 bytes
// Params: byte * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_initLifecycleEx(byte *param_1)
{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  if (((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) &&
     (iVar4 = *(int *)(param_1 + 0x120), iVar4 <= *(int *)(param_1 + 0x124))) {
    iVar3 = iVar4 * 400;
    do {
      bVar1 = *(byte *)(iVar4 + *(int *)(param_1 + 0x30));
      puVar2 = (undefined4 *)(*(int *)(param_1 + 0x34) + iVar3);
      if (3 < bVar1) {
        if (bVar1 < 6) {
          if ((*(byte *)(puVar2 + 0x14) & 2) == 0) {
            playback_initLifecycleEx((byte *)puVar2[0x53]);
          }
        }
        else if ((bVar1 == 6) && ((*(byte *)(puVar2 + 0x14) & 2) == 0)) {
          playback_initSpriteInstance((int)param_1,puVar2);
        }
      }
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + 400;
    } while (iVar4 <= *(int *)(param_1 + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_getCurrentFrame (FUN_680d0d60)
// Address: 680d0d60
// Size: 30 bytes
// Params: byte * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getCurrentFrame(byte *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    uVar1 = media_getScoreState(*(int **)(param_1 + 0x28));
  }
  return uVar1;
}



// ============================================================
// Function: playback_getMaxFrame (playback_getMaxFrame)
// Address: 680d0d80
// Size: 30 bytes
// Params: byte * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getMaxFrame(byte *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    uVar1 = media_isScoreLocked(*(int **)(param_1 + 0x28));
  }
  return uVar1;
}



// ============================================================
// Function: playback_findSpriteByState (playback_findSpriteByState)
// Address: 680d0da0
// Size: 190 bytes
// Params: byte * param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_findSpriteByState(byte *param_1,undefined4 param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int iVar7;
  
  iVar4 = 0;
  if (((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) &&
     (*(int **)(param_1 + 0x3c) != (int *)0x0)) {
    iVar2 = *(int *)(**(int **)(param_1 + 0x3c) + 8);
    iVar7 = 0;
    if (0 < iVar2) {
      do {
        iVar3 = *(int *)(*(int *)(*(int *)((undefined4 *)**(int **)(param_1 + 0x3c))[9] + iVar7 * 4)
                         + 4 + **(int **)**(int **)(param_1 + 0x3c));
        cVar1 = *(char *)(iVar3 + *(int *)(param_1 + 0x30));
        puVar6 = (undefined4 *)(iVar3 * 400 + *(int *)(param_1 + 0x34));
        if ((cVar1 != '\0') && ((*(byte *)(puVar6 + 0x14) & 2) == 0)) {
          if ((byte)(cVar1 - 4U) < 2) {
            iVar4 = playback_findSpriteByState((byte *)puVar6[0x53],param_2);
            if (iVar4 != 0) {
              return iVar4;
            }
          }
          else {
            uVar5 = playback_getSpriteState(puVar6);
            if (((short)uVar5 == (short)param_2) && ((short)((uint)uVar5 >> 0x10) == (*(unsigned short *)((char *)&param_2 + 2))))
            {
              return 1;
            }
            iVar4 = 0;
          }
        }
        iVar7 = iVar7 + 1;
        if (iVar2 <= iVar7) {
          return iVar4;
        }
      } while( true );
    }
  }
  return iVar4;
}



// ============================================================
// Function: playback_getLifecycleCount (FUN_680d0e60)
// Address: 680d0e60
// Size: 19 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getLifecycleCount(int param_1)
{
  rendering_updateStageDisplay(*(int *)(param_1 + 0x24));
  return 0;
}



// ============================================================
// Function: playback_processLifecycle (FUN_680d0e80)
// Address: 680d0e80
// Size: 32 bytes
// Params: byte * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_processLifecycle(byte *param_1,int param_2)
{
  rendering_getStageProperty((int)param_1,*(int *)(param_1 + 0x24));
  playback_processChannelTypes(param_1,param_2);
  return 0;
}



// ============================================================
// Function: playback_setTempo (FUN_680d0ea0)
// Address: 680d0ea0
// Size: 80 bytes
// Params: byte * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_setTempo(byte *param_1,int param_2)

{
  int iVar1;
  
  Ordinal_1061(param_2);
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    iVar1 = *(int *)(param_1 + 0x24);
    if (param_2 != 0) {
      Ordinal_1060(param_2,*(int *)(iVar1 + 8),*(int *)(iVar1 + 0xc),
                   *(int *)(iVar1 + 0x10) + *(int *)(iVar1 + 8),
                   *(int *)(iVar1 + 0x14) + *(int *)(iVar1 + 0xc));
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: playback_getStageRect (playback_getStageRect)
// Address: 680d0ef0
// Size: 83 bytes
// Params: byte * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getStageRect(byte *param_1,undefined4 *param_2)

{
  int iVar1;
  
  Ordinal_1061(param_2);
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    iVar1 = *(int *)(param_1 + 0x20);
    *param_2 = *(undefined4 *)(iVar1 + 0x4f0);
    param_2[1] = *(undefined4 *)(iVar1 + 0x4f4);
    param_2[2] = *(undefined4 *)(iVar1 + 0x4f8);
    param_2[3] = *(undefined4 *)(iVar1 + 0x4fc);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: playback_setSoundProperty (FUN_680d0f50)
// Address: 680d0f50
// Size: 563 bytes
// Params: byte * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_setSoundProperty(byte *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_50;
  undefined4 local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 0x20);
  local_50 = 1;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  if (((*param_1 & 8) != 0) &&
     (iVar6 = Ordinal_2031(0,&local_48), iVar5 = local_38, iVar4 = local_3c, iVar3 = local_40,
     iVar2 = local_44, iVar6 != 0)) {
    local_24 = local_40;
    local_28 = local_44;
    local_20 = local_3c;
    local_1c = local_38;
    iVar6 = Ordinal_2031(1,&local_48);
    while (iVar6 != 0) {
      if (local_40 < local_24) {
        local_24 = local_40;
      }
      if (local_1c < local_38) {
        local_1c = local_38;
      }
      if (local_44 < local_28) {
        local_28 = local_44;
      }
      if (local_20 < local_3c) {
        local_20 = local_3c;
      }
      local_50 = local_50 + 1;
      iVar6 = Ordinal_2031(local_50,&local_48);
    }
    iVar6 = *(int *)(param_1 + 0x24);
    Ordinal_1060(&local_18,*(int *)(iVar6 + 8),*(int *)(iVar6 + 0xc),
                 *(int *)(iVar6 + 0x10) + *(int *)(iVar6 + 8),
                 *(int *)(iVar6 + 0x14) + *(int *)(iVar6 + 0xc));
    if (((*(int *)(iVar1 + 0x678) == 0) || (local_10 <= local_18)) || (local_c <= local_14)) {
      local_18 = (int)*(short *)(iVar1 + 0x492);
      local_10 = (int)*(short *)(iVar1 + 0x496);
      local_14 = (int)*(short *)(iVar1 + 0x490);
      local_c = (int)*(short *)(iVar1 + 0x494);
    }
    if (*(int *)(iVar1 + 0x670) != 0) {
      Ordinal_1064(&local_18,(((iVar4 - iVar2) - local_10) + local_18) / 2 - local_18,
                   (((iVar5 - iVar3) - local_c) + local_14) / 2 - local_14);
    }
    iVar7 = Ordinal_1068(&local_28,&local_18);
    if (iVar7 == 0) {
      Ordinal_1064(&local_18,(((iVar4 - iVar2) - local_10) + local_18) / 2 - local_18,
                   (((iVar5 - iVar3) - local_c) + local_14) / 2 - local_14);
    }
    if ((*(byte *)(iVar1 + 0x20) & 4) != 0) {
      Ordinal_1064(&local_18,-local_18,-local_14);
    }
    rendering_resizeStageSurface(iVar6,local_10 - local_18,local_c - local_14,local_18,local_14);
    if ((param_2 != 0) && (*(int *)(iVar6 + 4) != 0)) {
      playback_notifyStageResize();
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: playback_toggleSoundPause (FUN_680d1190)
// Address: 680d1190
// Size: 81 bytes
// Params: uint * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_toggleSoundPause(uint *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (uint *)0x0) && (uVar1 = *param_1, (uVar1 & 8) != 0)) {
    if (param_2 == 0) {
      if ((uVar1 & 4) != 0) {
        playback_toggleSoundChannels(0);
        *param_1 = *param_1 & 0xfffffffb;
      }
    }
    else if ((uVar1 & 4) == 0) {
      playback_getControlSize((int *)param_1);
      playback_toggleSoundChannels(1);
      *param_1 = *param_1 | 4;
      return 1;
    }
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: playback_setSpriteFrame (FUN_680d11f0)
// Address: 680d11f0
// Size: 31 bytes
// Params: byte * param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_setSpriteFrame(byte *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    uVar1 = playback_setNextFrame((int)param_1,param_2);
  }
  return uVar1;
}



// ============================================================
// Function: playback_invalidateSpriteRegion (FUN_680d1210)
// Address: 680d1210
// Size: 9 bytes
// Params: byte * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_invalidateSpriteRegion(byte *param_1)
{
  playback_computeNextFrame(param_1);
  return 0;
}



// ============================================================
// Function: playback_getLifecycleBlock (FUN_680d1220)
// Address: 680d1220
// Size: 33 bytes
// Params: uint * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getLifecycleBlock(uint *param_1,int param_2)
{
  *param_1 = *param_1 ^ (param_2 * 2 ^ *param_1) & 2;
  rendering_getChannelProperty((int)param_1,1,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: playback_getBlockFlag (playback_getBlockFlag)
// Address: 680d1250
// Size: 23 bytes
// Params: uint * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint playback_getBlockFlag(uint *param_1)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != (uint *)0x0) {
    uVar1 = *param_1 >> 1 & 1;
  }
  return uVar1;
}



// ============================================================
// Function: playback_setScaleRatio (playback_setScaleRatio)
// Address: 680d1270
// Size: 45 bytes
// Params: int param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_setScaleRatio(int param_1,short param_2)
{
  if (param_2 == 0) {
    *(undefined2 *)(param_1 + 0x154) = 0x100;
    return 0;
  }
  *(short *)(param_1 + 0x154) = param_2;
  return 0;
}



// ============================================================
// Function: playback_getLifecycleSize (FUN_680d12a0)
// Address: 680d12a0
// Size: 17 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 playback_getLifecycleSize(int param_1)

{
  return *(undefined2 *)(param_1 + 0x154);
}



// ============================================================
// Function: playback_getChannelCount (FUN_680d12c0)
// Address: 680d12c0
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getChannelCount(int param_1)
{
  scoreEngine_getChannelCount(*(int *)(param_1 + 0x20),(short)*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x34));
  return 0;
}



// ============================================================
// Function: playback_getChannelCountEx (FUN_680d12e0)
// Address: 680d12e0
// Size: 170 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int * param_4, int * param_5, undefined4 param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_getChannelCountEx(int param_1,int param_2,int param_3,int *param_4,int *param_5,uint param_6)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  if (((param_1 != 0) && (*(int **)(param_1 + 0x3c) != (int *)0x0)) &&
     (iVar3 = *(int *)(**(int **)(param_1 + 0x3c) + 8) + -1, -1 < iVar3)) {
    while ((iVar1 = *(int *)(*(int *)(*(int *)((undefined4 *)**(int **)(param_1 + 0x3c))[9] +
                                     iVar3 * 4) + 4 + **(int **)**(int **)(param_1 + 0x3c)),
           *(char *)(iVar1 + *(int *)(param_1 + 0x30)) == '\0' ||
           (uVar2 = playback_hitTestSprite(param_1,(undefined4 *)(iVar1 * 400 + *(int *)(param_1 + 0x34)),
                                 param_2,param_3,param_4,param_5,param_6), uVar2 == 0))) {
      iVar3 = iVar3 + -1;
      if (iVar3 < 0) {
        return 0;
      }
    }
    if (param_4 == (int *)0x0) {
      *param_5 = iVar1;
    }
    else if (*param_4 == 0) {
      *param_4 = param_1;
      *param_5 = iVar1;
      return uVar2;
    }
  }
  return uVar2;
}



// ============================================================
// Function: playback_findChannelBySpriteData (playback_findChannelBySpriteData)
// Address: 680d1390
// Size: 97 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int * param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_findChannelBySpriteData(int param_1,undefined4 param_2,undefined4 param_3,int *param_4,int *param_5)

{
  int iVar1;
  int iVar2;
  
  iVar2 = param_1;
  iVar1 = playback_getChannelCountEx(param_1,param_2,param_3,(int *)0x0,&param_1,0x80ff);
  if (iVar1 != 0) {
    if (param_5 != (int *)0x0) {
      *param_5 = param_1 + 1;
    }
    iVar2 = playback_getSpriteData(iVar2,(undefined4 *)(param_1 * 400 + *(int *)(iVar2 + 0x34)));
    if (iVar2 != 0) {
      *param_4 = iVar2;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_initLifecycleBlock (FUN_680d1400)
// Address: 680d1400
// Size: 279 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_initLifecycleBlock(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = Ordinal_1063(param_1 + 0x130,param_2);
  if ((iVar2 != 0) && (iVar2 = Ordinal_1063(param_1 + 0x140,param_3), iVar2 != 0)) {
    return 0;
  }
  bVar1 = false;
  iVar2 = Ordinal_1063(param_2,param_3);
  if (iVar2 == 0) {
    *(undefined4 *)(param_1 + 300) = 1;
    bVar1 = true;
  }
  else if (*(int *)(param_1 + 300) != 0) {
    *(undefined4 *)(param_1 + 300) = 0;
    bVar1 = true;
  }
  *(undefined4 *)(param_1 + 0x130) = *param_2;
  *(undefined4 *)(param_1 + 0x134) = param_2[1];
  *(undefined4 *)(param_1 + 0x138) = param_2[2];
  *(undefined4 *)(param_1 + 0x13c) = param_2[3];
  *(undefined4 *)(param_1 + 0x140) = *param_3;
  *(undefined4 *)(param_1 + 0x144) = param_3[1];
  *(undefined4 *)(param_1 + 0x148) = param_3[2];
  *(undefined4 *)(param_1 + 0x14c) = param_3[3];
  if ((bVar1) && (iVar2 = *(int *)(param_1 + 0x120), iVar2 <= *(int *)(param_1 + 0x124))) {
    iVar3 = iVar2 * 400;
    do {
      puVar4 = (undefined4 *)(*(int *)(param_1 + 0x34) + iVar3);
      if ((*(byte *)(puVar4 + 0x13) & 1) != 0) {
        playback_resetSpriteRegion((int)puVar4);
        playback_getSpriteInfoEx(param_1,puVar4,0x1000);
        playback_renderSpriteFrame((int)puVar4,0);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 400;
    } while (iVar2 <= *(int *)(param_1 + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_initLifecycle (FUN_680d1520)
// Address: 680d1520
// Size: 101 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_initLifecycle(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (*(int *)(param_1 + 300) != 0) {
    *param_2 = *(undefined4 *)(param_1 + 0x130);
    param_2[1] = *(undefined4 *)(param_1 + 0x134);
    param_2[2] = *(undefined4 *)(param_1 + 0x138);
    param_2[3] = *(undefined4 *)(param_1 + 0x13c);
    *param_3 = *(undefined4 *)(param_1 + 0x140);
    param_3[1] = *(undefined4 *)(param_1 + 0x144);
    param_3[2] = *(undefined4 *)(param_1 + 0x148);
    param_3[3] = *(undefined4 *)(param_1 + 0x14c);
  }
  return *(undefined4 *)(param_1 + 300);
}



// ============================================================
// Function: playback_setLifecycleData (FUN_680d1590)
// Address: 680d1590
// Size: 58 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_setLifecycleData(int param_1,undefined4 param_2)
{
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x1c)) {
    if (*(int *)(param_1 + 300) != 0) {
      Ordinal_1071(param_2,param_1 + 0x130,param_1 + 0x140);
    }
  }
  return 0;
}



// ============================================================
// Function: playback_applyLifecycleTransformReverse (playback_applyLifecycleTransformReverse)
// Address: 680d15d0
// Size: 171 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_applyLifecycleTransformReverse(int param_1,undefined4 param_2)
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *local_8;
  
  bVar1 = false;
  local_8 = (int *)0x0;
  if (param_1 != 0) {
    iVar4 = param_1;
    iVar5 = 0;
    do {
      iVar6 = iVar5;
      iVar4 = *(int *)(iVar4 + 0x1c);
      iVar5 = iVar6 + 1;
    } while (iVar4 != 0);
    if (iVar5 == 1) {
      local_8 = &param_1;
      uVar2 = param_2;
    }
    else {
      local_8 = (int *)Ordinal_1124(iVar5 * 4);
      if (local_8 == (int *)0x0) {
        return 0;
      }
      bVar1 = true;
      uVar2 = param_2;
      if (param_1 != 0) {
        iVar5 = 0;
        iVar4 = param_1;
        do {
          *(int *)(iVar5 + (int)local_8) = iVar4;
          iVar4 = *(int *)(iVar4 + 0x1c);
          iVar5 = iVar5 + 4;
        } while (iVar4 != 0);
      }
    }
    for (; uVar3 = param_2, param_2 = uVar2, -1 < iVar6; iVar6 = iVar6 + -1) {
      iVar4 = local_8[iVar6];
      if (*(int *)(iVar4 + 300) != 0) {
        Ordinal_1071(uVar3,iVar4 + 0x140,iVar4 + 0x130);
      }
      uVar2 = param_2;
      param_2 = uVar3;
    }
    if (bVar1) {
      Ordinal_1125(&local_8);
    }
  }
  return 0;
}



// ============================================================
// Function: playback_applyLifecycleIntersect (playback_applyLifecycleIntersect)
// Address: 680d1680
// Size: 58 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_applyLifecycleIntersect(int param_1,undefined4 param_2)
{
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x1c)) {
    if (*(int *)(param_1 + 300) != 0) {
      Ordinal_1091(param_2,param_1 + 0x130,param_1 + 0x140);
    }
  }
  return 0;
}



// ============================================================
// Function: playback_applyLifecycleIntersectReverse (playback_applyLifecycleIntersectReverse)
// Address: 680d16c0
// Size: 171 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_applyLifecycleIntersectReverse(int param_1,undefined4 param_2)
{
  bool bVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *local_8;
  
  bVar1 = false;
  local_8 = (int *)0x0;
  if (param_1 != 0) {
    iVar4 = param_1;
    iVar5 = 0;
    do {
      iVar6 = iVar5;
      iVar4 = *(int *)(iVar4 + 0x1c);
      iVar5 = iVar6 + 1;
    } while (iVar4 != 0);
    if (iVar5 == 1) {
      local_8 = &param_1;
      uVar2 = param_2;
    }
    else {
      local_8 = (int *)Ordinal_1124(iVar5 * 4);
      if (local_8 == (int *)0x0) {
        return 0;
      }
      bVar1 = true;
      uVar2 = param_2;
      if (param_1 != 0) {
        iVar5 = 0;
        iVar4 = param_1;
        do {
          *(int *)(iVar5 + (int)local_8) = iVar4;
          iVar4 = *(int *)(iVar4 + 0x1c);
          iVar5 = iVar5 + 4;
        } while (iVar4 != 0);
      }
    }
    for (; uVar3 = param_2, param_2 = uVar2, -1 < iVar6; iVar6 = iVar6 + -1) {
      iVar4 = local_8[iVar6];
      if (*(int *)(iVar4 + 300) != 0) {
        Ordinal_1091(uVar3,iVar4 + 0x140,iVar4 + 0x130);
      }
      uVar2 = param_2;
      param_2 = uVar3;
    }
    if (bVar1) {
      Ordinal_1125(&local_8);
    }
  }
  return 0;
}



// ============================================================
// Function: playback_scaleLifecycleCoords (playback_scaleLifecycleCoords)
// Address: 680d1770
// Size: 136 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_scaleLifecycleCoords(int param_1,int *param_2,int *param_3)
{
  int iVar1;
  
  for (; param_1 != 0; param_1 = *(int *)(param_1 + 0x1c)) {
    if (*(int *)(param_1 + 300) != 0) {
      if (*(int *)(param_1 + 0x130) < *(int *)(param_1 + 0x138)) {
        iVar1 = *(int *)(param_1 + 0x138) - *(int *)(param_1 + 0x130);
      }
      else {
        iVar1 = 1;
      }
      *param_2 = ((*(int *)(param_1 + 0x148) - *(int *)(param_1 + 0x140)) * *param_2) / iVar1;
      if (*(int *)(param_1 + 0x134) < *(int *)(param_1 + 0x13c)) {
        iVar1 = *(int *)(param_1 + 0x13c) - *(int *)(param_1 + 0x134);
      }
      else {
        iVar1 = 1;
      }
      *param_3 = ((*(int *)(param_1 + 0x14c) - *(int *)(param_1 + 0x144)) * *param_3) / iVar1;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_getLifecycleRef (FUN_680d1800)
// Address: 680d1800
// Size: 35 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getLifecycleRef(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 8);
  while ((iVar1 == 0 && (param_1 = *(int *)(param_1 + 0x1c), param_1 != 0))) {
    iVar1 = *(int *)(param_1 + 8);
  }
  return 0;
}



// ============================================================
// Function: playback_walkLifecycleChain (playback_walkLifecycleChain)
// Address: 680d1830
// Size: 33 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_walkLifecycleChain(int param_1)
{
  do {
    if (param_1 == 0) {
      return 0;
    }
    param_1 = *(int *)(param_1 + 0x1c);
  } while (param_1 != 0);
  return 0;
}



// ============================================================
// Function: playback_getLifecycleData (FUN_680d1860)
// Address: 680d1860
// Size: 38 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getLifecycleData(int param_1)

{
  if ((*(int *)(param_1 + 8) != 0) &&
     (*(int *)(param_1 + 0x20) == *(int *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 0x20))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: playback_countLifecycleDepth (playback_countLifecycleDepth)
// Address: 680d1890
// Size: 36 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_countLifecycleDepth(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 != 0) {
    iVar2 = 1;
    for (iVar1 = *(int *)(param_1 + 0x1c); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x1c)) {
      iVar2 = iVar2 + 1;
    }
  }
  return iVar2;
}



// ============================================================
// Function: playback_clearSpriteDisplayState (playback_clearSpriteDisplayState)
// Address: 680d18c0
// Size: 84 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_clearSpriteDisplayState(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x120);
  if (iVar3 <= *(int *)(param_1 + 0x124)) {
    iVar2 = iVar3 * 400;
    do {
      if ((*(char *)(iVar3 + *(int *)(param_1 + 0x30)) != '\0') &&
         (iVar1 = *(int *)(param_1 + 0x34) + iVar2, (*(byte *)(iVar1 + 0x50) & 2) == 0)) {
        playback_invalidateSpriteRect(iVar1);
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 400;
    } while (iVar3 <= *(int *)(param_1 + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_getLifecycleState (FUN_680d1920)
// Address: 680d1920
// Size: 46 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getLifecycleState(int param_1)

{
  int iVar1;
  
  iVar1 = scoreEngine_isXtraEditable(*(undefined4 **)(param_1 + 0x20));
  if ((iVar1 != 0) && (*(int *)(param_1 + 0x174) == 0)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: playback_resetLifecycle (FUN_680d1950)
// Address: 680d1950
// Size: 127 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_resetLifecycle(int param_1,undefined4 param_2,undefined4 param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  uVar2 = 0;
  if (param_1 != 0) {
    iVar5 = *(int *)(param_1 + 0x120);
    if (iVar5 <= *(int *)(param_1 + 0x124)) {
      iVar4 = iVar5 * 400;
      do {
        bVar1 = *(byte *)(iVar5 + *(int *)(param_1 + 0x30));
        iVar3 = *(int *)(param_1 + 0x34) + iVar4;
        if (3 < bVar1) {
          if (bVar1 < 6) {
            playback_resetLifecycle(*(int *)(iVar3 + 0x14c),param_2,param_3);
          }
          else if (bVar1 == 10) {
            bitmap_setSpriteProperty(param_1,iVar3,param_2);
          }
        }
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 400;
      } while (iVar5 <= *(int *)(param_1 + 0x124));
    }
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: playback_advanceFrame (playback_advanceFrame)
// Address: 680d19d0
// Size: 128 bytes
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint playback_advanceFrame(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined3 extraout_var;
  byte *unaff_ESI;
  uint uVar4;
  
  uVar4 = 0;
  if ((unaff_ESI != (byte *)0x0) && ((*unaff_ESI & 8) != 0)) {
    iVar2 = playback_getLifecycleState((int)unaff_ESI);
    if ((iVar2 != 0) || (*(int *)(unaff_ESI + 8) != 0)) {
      if (*(int *)(unaff_ESI + 0x170) == 0) {
        media_isPlaybackActive(*(int *)(unaff_ESI + 0x28),1);
        iVar2 = media_getScoreState(*(int **)(unaff_ESI + 0x28));
        iVar3 = media_isScoreLocked(*(int **)(unaff_ESI + 0x28));
        uVar4 = (uint)(iVar2 <= iVar3);
        goto LAB_680d1a32;
      }
      unaff_ESI[0x170] = 0;
      unaff_ESI[0x171] = 0;
      unaff_ESI[0x172] = 0;
      unaff_ESI[0x173] = 0;
    }
    uVar4 = media_readPlaybackData(*(int *)(unaff_ESI + 0x28),1,1);
  }
LAB_680d1a32:
  bVar1 = lingo_isScriptReady(*(int *)(*(int *)(unaff_ESI + 0x20) + 4));
  if (CONCAT31(extraout_var,bVar1) != 0) {
    rendering_getChannelProperty((int)unaff_ESI,3,(undefined4 *)0x0);
  }
  return uVar4;
}



// ============================================================
// Function: playback_recreateLifecycleIfActive (playback_recreateLifecycleIfActive)
// Address: 680d1a50
// Size: 16 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_recreateLifecycleIfActive(void)
{
  byte *in_EAX;
  
  if ((in_EAX != (byte *)0x0) && ((*in_EAX & 8) != 0)) {
    playback_createLifecycle((int)in_EAX);
  }
  return 0;
}



// ============================================================
// Function: playback_getLifecycleValue (FUN_680d1a60)
// Address: 680d1a60
// Size: 232 bytes
// Params: uint * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getLifecycleValue(uint *param_1)
{
  undefined4 *puVar1;
  uint *puVar2;
  undefined4 local_8;
  
  puVar2 = param_1;
  if (param_1 != (uint *)0x0) {
    stage_detachSprite(*(int *)(param_1[8] + 8),(int)param_1);
    puVar1 = (undefined4 *)puVar2[0x61];
    if (puVar1 != (undefined4 *)0x0) {
      param_1 = (uint *)0x0;
      local_8 = 0;
      (**(code **)*puVar1)(puVar1,&DAT_68176378,&param_1);
      if (param_1 != (uint *)0x0) {
        (**(code **)(*param_1 + 0x10))(param_1,&local_8);
        (**(code **)(*param_1 + 8))(param_1);
      }
      (**(code **)(*(int *)puVar2[0x61] + 8))((int *)puVar2[0x61]);
      puVar2[0x61] = 0;
    }
    if ((*puVar2 & 0x10) != 0) {
      playback_createLifecycle((int)puVar2);
      media_getScorePlayState((int *)(puVar2 + 10));
      *puVar2 = *puVar2 & 0xffffffef;
    }
    Ordinal_1163(puVar2 + 0xf);
    if (puVar2[0x4a] != 0) {
      Ordinal_1113(puVar2 + 0x4a);
    }
    media_getScorePlayState((int *)(puVar2 + 10));
    Ordinal_1125(puVar2 + 0xd);
    Ordinal_1125(puVar2 + 0xe);
    Ordinal_1125(puVar2 + 0xc);
    puVar2[0xb] = 0;
    puVar2[0x48] = 0;
    puVar2[0x49] = 0xffffffff;
    puVar2[9] = 0;
  }
  return 0;
}



// ============================================================
// Function: playback_setLifecycleState (FUN_680d1b50)
// Address: 680d1b50
// Size: 41 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_setLifecycleState(int param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = rendering_resizeSprite(*(int **)(param_1 + 0x24),param_2);
  playback_resetLifecycle(param_1,0x14,0);
  return uVar1;
}



// ============================================================
// Function: playback_setLifecycleRef (FUN_680d1b80)
// Address: 680d1b80
// Size: 76 bytes
// Params: byte * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_setLifecycleRef(byte *param_1)
{
  int iVar1;
  
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    playback_notifyRecursiveChannels((int)param_1,0);
    iVar1 = *(int *)(param_1 + 0x28);
    param_1[0x180] = 0;
    param_1[0x181] = 0;
    param_1[0x182] = 0;
    param_1[0x183] = 0;
    media_getPlaybackPosition(iVar1);
    playback_recreateLifecycleIfActive();
    playback_clearSpriteDefaults();
    playback_resetControlState((int)param_1);
    param_1[0x170] = 0;
    param_1[0x171] = 0;
    param_1[0x172] = 0;
    param_1[0x173] = 0;
  }
  return 0;
}



// ============================================================
// Function: playback_resetAllState (playback_resetAllState)
// Address: 680d1bd0
// Size: 96 bytes
// Params: byte * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resetAllState(byte *param_1)
{
  int iVar1;
  
  if (param_1 != (byte *)0x0) {
    iVar1 = *(int *)(param_1 + 0x24);
    playback_setLifecycleRef(param_1);
    Ordinal_1130(*(undefined4 *)(param_1 + 0x34),*(int *)(param_1 + 0x2c) * 400);
    Ordinal_1130(*(undefined4 *)(param_1 + 0x30),*(undefined4 *)(param_1 + 0x2c));
    playback_createLifecycle((int)param_1);
    param_1[0x48] = 0xff;
    param_1[0x49] = 0xff;
    param_1[0x4a] = 0xff;
    param_1[0x4b] = 0xff;
    param_1[0x44] = 0xff;
    param_1[0x45] = 0xff;
    param_1[0x46] = 0xff;
    param_1[0x47] = 0xff;
    rendering_getStageRefById(iVar1);
    param_1[0x70] = 0;
    param_1[0x71] = 0;
    param_1[0x72] = 0;
    param_1[0x73] = 0;
    param_1[0x74] = 0;
    param_1[0x75] = 0;
    param_1[0x76] = 0;
    param_1[0x77] = 0;
    param_1[0x178] = 0;
    param_1[0x179] = 0;
    param_1[0x17a] = 0;
    param_1[0x17b] = 0;
  }
  return 0;
}



// ============================================================
// Function: playback_getLifecycleFlags (FUN_680d1c30)
// Address: 680d1c30
// Size: 128 bytes
// Params: byte * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint playback_getLifecycleFlags(byte *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar2 = 0;
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    iVar3 = playback_invalidateSpriteRegion(param_1);
    media_validateScoreFrameData(*(int *)(param_1 + 0x28),iVar3);
    uVar2 = playback_advanceFrame();
    if (uVar2 == 0) {
      bVar1 = *param_1;
      param_1[0x180] = 0;
      param_1[0x181] = 0;
      param_1[0x182] = 0;
      param_1[0x183] = 0;
      iVar3 = 1;
      if ((bVar1 & 2) == 0) {
        uVar4 = media_isScoreLocked(*(int **)(param_1 + 0x28));
        media_readPlaybackData(*(int *)(param_1 + 0x28),uVar4,iVar3);
        return 0;
      }
      media_readPlaybackData(*(int *)(param_1 + 0x28),0,1);
      uVar2 = playback_advanceFrame();
      if (uVar2 == 0) {
        return 0;
      }
    }
    playback_initScoreEx(1);
    playback_destroyLifecycle((int)param_1);
  }
  return uVar2;
}



// ============================================================
// Function: playback_setLifecycleFlags (FUN_680d1cb0)
// Address: 680d1cb0
// Size: 242 bytes
// Params: byte * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_setLifecycleFlags(byte *param_1,int param_2)
{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  
  if (param_1 == (byte *)0x0) {
    return 0;
  }
  if ((*param_1 & 8) != 0) {
    if (param_2 < 1) {
      param_2 = 1;
    }
    if ((((*(uint *)(*(int *)(param_1 + 0x20) + 0x500) < 0x600) ||
         (iVar2 = events_getAndClearPendingFlag(*(int *)(*(int *)(param_1 + 0x20) + 8)), iVar2 == 0)) ||
        (iVar2 = media_getScoreState(*(int **)(param_1 + 0x28)), param_2 != iVar2)) ||
       (*(int *)(param_1 + 0x180) != 0)) {
      media_validateScoreFrameData(*(int *)(param_1 + 0x28),param_2);
      iVar2 = media_getScoreState(*(int **)(param_1 + 0x28));
      if ((param_2 <= iVar2) || (param_2 == 1)) {
        param_1[0x180] = 0;
        param_1[0x181] = 0;
        param_1[0x182] = 0;
        param_1[0x183] = 0;
      }
      media_readPlaybackData(*(int *)(param_1 + 0x28),param_2 + -1,1);
      uVar3 = playback_advanceFrame();
    }
    else {
      bVar1 = lingo_isScriptReady(*(int *)(*(int *)(param_1 + 0x20) + 4));
      if (CONCAT31(extraout_var,bVar1) != 0) {
        rendering_getChannelProperty((int)param_1,3,(undefined4 *)0x0);
      }
      uVar3 = 1;
    }
    playback_initScoreEx(1);
    if (((*(int *)(param_1 + 0x1c) == 0) && (uVar3 == 0)) &&
       (((*param_1 & 2) == 0 &&
        (*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 4) ==
         *(int *)(**(int **)(param_1 + 0x18) + 0x18))))) {
      scoreEngine_markDirty(*(int *)(param_1 + 0x20),0);
    }
    media_getScoreState(*(int **)(param_1 + 0x28));
    return 0;
  }
  return 0;
}



