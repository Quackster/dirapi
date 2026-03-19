// Module: playback
// Topic: Frame step state machine - timing, transitions, tempo processing
// Address range: 0x680d7800 - 0x680d8e20
// Functions (30):
//   playback_stepSetupTransition, playback_stepRenderSprites, playback_stepWaitSpriteRender, playback_stepProcessCallbacks, playback_stepApplyTransition
//   playback_stepRenderTransition, playback_stepWaitTransitionRender, playback_stepFinishTransition, playback_stepProcessPalette, playback_stepProcessLifecycle
//   playback_stepSetupPaletteTransition, playback_stepRenderPaletteTransition, playback_stepContinuePalette, playback_stepWaitPaletteRender, playback_stepAdvanceToSound
//   playback_stepProcessSound, playback_stepCheckCuePoint, playback_stepWaitTempo, playback_stepWaitTempoRender, playback_stepRenderTempo
//   playback_stepWaitTempoFrame, playback_stepFinishTempo, playback_stepFinishFrame, playback_isStepActive, playback_isStepPastTransition
//   playback_getStepFrameInfo, playback_setNextFrame, playback_computeNextFrame, playback_syncMemberScore, playback_playSoundChannels
//   playback_readScoreFrameProperties, playback_downgradeTransitionMode, playback_resetScoreSlots, playback_hasSavedStepState, playback_saveStepState
//   playback_restoreStepState, playback_playSoundIfNotLooping, playback_stepBeginFrame

// ============================================================
// Function: playback_stepSetupTransition (playback_stepSetupTransition)
// Address: 680d7800
// Size: 348 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepSetupTransition(void)

{
  short sVar1;
  int iVar2;
  short extraout_var;
  short extraout_var_00;
  undefined4 uVar3;
  short extraout_var_02;
  undefined2 extraout_var_03;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  int *unaff_ESI;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  short sVar7;
  short sVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  undefined1 uVar11;
  undefined2 extraout_var_01;
  
  iVar4 = unaff_ESI[0x2c];
  if (*(int *)(unaff_ESI[8] + 0x67c) != 0) {
    unaff_ESI[0x16] = 0xc;
    return 1;
  }
  if (((*(int *)(unaff_ESI[8] + 0x65c) != 0) || (*(short *)((int)unaff_ESI + 0x6e) == 0)) ||
     (unaff_ESI[0x19] != 0)) {
    unaff_ESI[0x16] = 6;
    return 1;
  }
  iVar2 = rendering_loadChannelSprite(unaff_ESI,unaff_ESI[0x1b]);
  if (iVar2 < 1) {
    iVar2 = 1;
  }
  if (iVar4 == 2) {
    sVar1 = playback_getChannelCount((int)unaff_ESI);
    if (sVar1 == (short)unaff_ESI[0x2d]) {
      playback_getChannelCount((int)unaff_ESI);
      if (extraout_var == *(short *)((int)unaff_ESI + 0xb6)) goto LAB_680d793d;
    }
    iVar4 = 1;
LAB_680d7895:
    if (unaff_ESI[0x2e] != 0) goto LAB_680d789e;
LAB_680d78c4:
    uVar9 = (undefined1)unaff_ESI[0x24];
    sVar8 = 0;
    sVar7 = 0;
    uVar6 = 0;
    uVar5 = 0;
    uVar10 = uVar9;
    uVar11 = uVar9;
    sVar1 = scoreEngine_getChannelData(unaff_ESI[8],(short)unaff_ESI[0x2d]);
    uVar3 = CONCAT22(extraout_var_01,sVar1);
    this = extraout_ECX;
  }
  else {
    if ((iVar4 != 0) && (iVar4 != 3)) goto LAB_680d7895;
LAB_680d789e:
    if (iVar4 == 1) {
      sVar1 = playback_getChannelCount((int)unaff_ESI);
      iVar4 = 1;
      if (sVar1 == (short)unaff_ESI[0x2d]) {
        playback_getChannelCount((int)unaff_ESI);
        if (extraout_var_00 == *(short *)((int)unaff_ESI + 0xb6)) goto LAB_680d793d;
      }
      goto LAB_680d78c4;
    }
    if (iVar4 != 3) goto LAB_680d793d;
    sVar1 = playback_getChannelCount((int)unaff_ESI);
    if (sVar1 == (short)unaff_ESI[0x2d]) {
      playback_getChannelCount((int)unaff_ESI);
      if (extraout_var_02 == *(short *)((int)unaff_ESI + 0xb6)) goto LAB_680d793d;
    }
    uVar11 = 0;
    uVar10 = 0;
    uVar9 = 0;
    sVar8 = 0;
    sVar7 = 0;
    uVar6 = 0;
    uVar5 = 0;
    sVar1 = scoreEngine_getChannelData(unaff_ESI[8],(short)unaff_ESI[0x2d]);
    uVar3 = CONCAT22(extraout_var_03,sVar1);
    iVar4 = 1;
    this = extraout_ECX_00;
  }
  rendering_setupStageTransition(this,unaff_ESI,unaff_ESI[9],iVar4,uVar3,iVar2,uVar5,uVar6,sVar7,sVar8,uVar9,uVar10,
               uVar11);
LAB_680d793d:
  unaff_ESI[0x16] = 3;
  return 1;
}



// ============================================================
// Function: playback_stepRenderSprites (playback_stepRenderSprites)
// Address: 680d7960
// Size: 192 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepRenderSprites(undefined4 *param_1)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int unaff_ESI;
  
  iVar1 = *(int *)(unaff_ESI + 0x20);
  if (*(int *)(unaff_ESI + 100) == 0) {
    bVar2 = playback_isScoreReady();
    if (CONCAT31(extraout_var,bVar2) == 0) {
      uVar3 = Ordinal_1541();
      *param_1 = uVar3;
      display_renderSpriteLayer((undefined4 *)(unaff_ESI + 0x108),uVar3,
                   *(int *)(*(int *)(unaff_ESI + 0x24) + 0x74),*(ushort *)(unaff_ESI + 0x154));
      uVar4 = rendering_updateSpriteStream(*(int **)(unaff_ESI + 0x24));
      rendering_setStageProperty(unaff_ESI,*(int *)(unaff_ESI + 0x24));
      if ((short)uVar4 != 0) {
        iVar5 = media_getDataPtr(*(int **)(*(int *)(unaff_ESI + 0x18) + 4));
        if (*(code **)(iVar5 + 0xe4) != (code *)0x0) {
          (**(code **)(iVar5 + 0xe4))
                    (*(undefined4 *)(*(int *)(iVar1 + 4) + 4),
                     *(undefined4 *)(*(int *)(unaff_ESI + 0x24) + 0x70));
        }
        *(undefined4 *)(unaff_ESI + 0x58) = 4;
        return 1;
      }
      *(undefined4 *)(unaff_ESI + 0x58) = 5;
      return 1;
    }
  }
  *(undefined4 *)(unaff_ESI + 0x58) = 5;
  return 1;
}



// ============================================================
// Function: playback_stepWaitSpriteRender (playback_stepWaitSpriteRender)
// Address: 680d7a20
// Size: 86 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepWaitSpriteRender(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  int *unaff_ESI;
  int unaff_EDI;
  
  uVar3 = *(undefined4 *)(unaff_EDI + 0x58);
  bVar1 = playback_isScoreReady();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar2 = Ordinal_1541();
    *param_1 = iVar2;
    iVar2 = display_renderSpriteFrame((int *)(unaff_EDI + 0x108),iVar2,unaff_ESI);
    if ((iVar2 == 0) && (*(int *)(unaff_EDI + 100) == 0)) goto LAB_680d7a69;
    uVar3 = 3;
  }
  else {
    uVar3 = 5;
  }
  if (unaff_ESI != (int *)0x0) {
    *unaff_ESI = 0;
  }
LAB_680d7a69:
  *(undefined4 *)(unaff_EDI + 0x58) = uVar3;
  return 1;
}



// ============================================================
// Function: playback_stepProcessCallbacks (playback_stepProcessCallbacks)
// Address: 680d7a80
// Size: 40 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepProcessCallbacks(void)

{
  byte *unaff_ESI;
  
  rendering_getStageData2(*(int **)(unaff_ESI + 0x24));
  rendering_updateStageRect((int)unaff_ESI,*(int *)(unaff_ESI + 0x24));
  playback_processChannelTypes(unaff_ESI,1);
  unaff_ESI[0x58] = 0xc;
  unaff_ESI[0x59] = 0;
  unaff_ESI[0x5a] = 0;
  unaff_ESI[0x5b] = 0;
  return 1;
}



// ============================================================
// Function: playback_stepApplyTransition (playback_stepApplyTransition)
// Address: 680d7ab0
// Size: 322 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepApplyTransition(void)

{
  short sVar1;
  undefined2 extraout_var;
  short extraout_var_00;
  undefined2 extraout_var_01;
  short extraout_var_02;
  undefined2 extraout_var_03;
  int *unaff_ESI;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  short sVar6;
  short sVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  undefined1 uVar10;
  
  if (unaff_ESI[0x2e] == 0) {
    if ((unaff_ESI[0x2c] == 1) && (unaff_ESI[0x28] == 0)) {
      sVar1 = scoreEngine_getChannelData(unaff_ESI[8],(short)unaff_ESI[0x2d]);
      rendering_setChannelProperty(unaff_ESI,unaff_ESI[9],CONCAT22(extraout_var,sVar1));
      goto LAB_680d7aea;
    }
    if (((unaff_ESI[0x2c] == 1) &&
        ((sVar1 = playback_getChannelCount((int)unaff_ESI), sVar1 != (short)unaff_ESI[0x2d] ||
         (playback_getChannelCount((int)unaff_ESI), extraout_var_00 != *(short *)((int)unaff_ESI + 0xb6))))) ||
       (unaff_ESI[0x2c] == 2)) {
      uVar8 = (undefined1)unaff_ESI[0x24];
      iVar2 = unaff_ESI[0x28];
      sVar7 = 0;
      sVar6 = 0;
      uVar4 = 0;
      uVar3 = 0;
      uVar9 = uVar8;
      uVar10 = uVar8;
      sVar1 = scoreEngine_getChannelData(unaff_ESI[8],(short)unaff_ESI[0x2d]);
      rendering_setupStageTransition((void *)unaff_ESI[9],unaff_ESI,unaff_ESI[9],unaff_ESI[0x2c],
                   CONCAT22(extraout_var_01,sVar1),iVar2,uVar3,uVar4,sVar6,sVar7,uVar8,uVar9,uVar10)
      ;
      unaff_ESI[0x16] = 7;
      return 1;
    }
  }
  if ((unaff_ESI[0x2c] == 3) &&
     (((sVar1 = playback_getChannelCount((int)unaff_ESI), sVar1 != (short)unaff_ESI[0x2d] ||
       (playback_getChannelCount((int)unaff_ESI), extraout_var_02 != *(short *)((int)unaff_ESI + 0xb6))) &&
      (unaff_ESI[0x2e] == 0)))) {
    uVar10 = 0;
    uVar9 = 0;
    uVar8 = 0;
    sVar7 = 0;
    sVar6 = 0;
    uVar5 = 0;
    uVar4 = 0;
    uVar3 = 0x14;
    sVar1 = scoreEngine_getChannelData(unaff_ESI[8],(short)unaff_ESI[0x2d]);
    rendering_setupStageTransition((void *)unaff_ESI[9],unaff_ESI,unaff_ESI[9],1,CONCAT22(extraout_var_03,sVar1),uVar3
                 ,uVar4,uVar5,sVar6,sVar7,uVar8,uVar9,uVar10);
    unaff_ESI[0x16] = 7;
    return 1;
  }
LAB_680d7aea:
  unaff_ESI[0x16] = 10;
  return 1;
}



// ============================================================
// Function: playback_stepRenderTransition (playback_stepRenderTransition)
// Address: 680d7c00
// Size: 205 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepRenderTransition(undefined4 *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 100) == 0) {
    bVar1 = playback_isScoreReady();
    if (CONCAT31(extraout_var,bVar1) == 0) {
      if (*(int *)(unaff_ESI + 0xb0) == 2) {
        uVar2 = rendering_resolvePlaybackMode();
        if ((char)uVar2 == '\x02') goto LAB_680d7cbc;
      }
      uVar3 = Ordinal_1541();
      *param_1 = uVar3;
      display_renderSpriteLayer((undefined4 *)(unaff_ESI + 0x108),uVar3,
                   0x10 - (int)(0x10 / (longlong)(0x1f - *(int *)(unaff_ESI + 0xa8))),
                   *(ushort *)(unaff_ESI + 0x154));
      iVar4 = rendering_setStageProperty(unaff_ESI,*(int *)(unaff_ESI + 0x24));
      if (iVar4 != 0) {
        iVar4 = media_getDataPtr(*(int **)(*(int *)(unaff_ESI + 0x18) + 4));
        if (*(code **)(iVar4 + 0xe4) != (code *)0x0) {
          (**(code **)(iVar4 + 0xe4))
                    (*(undefined4 *)(*(int *)(*(int *)(unaff_ESI + 0x20) + 4) + 4),
                     *(undefined4 *)(unaff_ESI + 0xa0));
        }
        *(undefined4 *)(unaff_ESI + 0x58) = 8;
        return 1;
      }
    }
  }
LAB_680d7cbc:
  *(undefined4 *)(unaff_ESI + 0x58) = 9;
  return 1;
}



// ============================================================
// Function: playback_stepWaitTransitionRender (playback_stepWaitTransitionRender)
// Address: 680d7cd0
// Size: 86 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepWaitTransitionRender(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  int *unaff_ESI;
  int unaff_EDI;
  
  uVar3 = *(undefined4 *)(unaff_EDI + 0x58);
  bVar1 = playback_isScoreReady();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar2 = Ordinal_1541();
    *param_1 = iVar2;
    iVar2 = display_renderSpriteFrame((int *)(unaff_EDI + 0x108),iVar2,unaff_ESI);
    if ((iVar2 == 0) && (*(int *)(unaff_EDI + 100) == 0)) goto LAB_680d7d19;
    uVar3 = 7;
  }
  else {
    uVar3 = 9;
  }
  if (unaff_ESI != (int *)0x0) {
    *unaff_ESI = 0;
  }
LAB_680d7d19:
  *(undefined4 *)(unaff_EDI + 0x58) = uVar3;
  return 1;
}



// ============================================================
// Function: playback_stepFinishTransition (playback_stepFinishTransition)
// Address: 680d7d30
// Size: 49 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepFinishTransition(void)

{
  bool bVar1;
  undefined3 extraout_var;
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0xb0) == 2) && (*(int *)(unaff_ESI + 100) == 0)) {
    bVar1 = playback_isScoreReady();
    if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_680d7d54;
  }
  rendering_updateStageRect(unaff_ESI,*(int *)(unaff_ESI + 0x24));
LAB_680d7d54:
  *(undefined4 *)(unaff_ESI + 0x58) = 10;
  return 1;
}



// ============================================================
// Function: playback_stepProcessPalette (playback_stepProcessPalette)
// Address: 680d7d70
// Size: 186 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepProcessPalette(void)

{
  short sVar1;
  short extraout_var;
  int iVar2;
  undefined2 extraout_var_00;
  int *unaff_ESI;
  undefined4 uVar3;
  undefined4 uVar4;
  short sVar5;
  short sVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  
  iVar2 = unaff_ESI[0x2c];
  if (((iVar2 != 0) && (iVar2 != 3)) && (unaff_ESI[0x2e] != 0)) {
    if (iVar2 == 1) {
      sVar1 = playback_getChannelCount((int)unaff_ESI);
      if (sVar1 == (short)unaff_ESI[0x2d]) {
        playback_getChannelCount((int)unaff_ESI);
        if (extraout_var == *(short *)((int)unaff_ESI + 0xb6)) goto LAB_680d7e1d;
      }
    }
    if (unaff_ESI[0x2f] != 0) {
      uVar7 = (undefined1)unaff_ESI[0x24];
      iVar2 = (int)(short)unaff_ESI[0x2b];
      sVar6 = 0;
      sVar5 = 0;
      uVar4 = 0;
      uVar3 = 0;
      uVar8 = uVar7;
      uVar9 = uVar7;
      sVar1 = scoreEngine_getChannelData(unaff_ESI[8],(short)unaff_ESI[0x2d]);
      rendering_setupStageTransition((void *)unaff_ESI[9],unaff_ESI,unaff_ESI[9],unaff_ESI[0x2c],
                   CONCAT22(extraout_var_00,sVar1),iVar2,uVar3,uVar4,sVar5,sVar6,uVar7,uVar8,uVar9);
      unaff_ESI[0x2f] = 0;
    }
    iVar2 = rendering_setStageProperty((int)unaff_ESI,unaff_ESI[9]);
    if (iVar2 == 0) {
      unaff_ESI[0x2e] = 0;
    }
  }
LAB_680d7e1d:
  unaff_ESI[0x16] = 0xb;
  return 1;
}



// ============================================================
// Function: playback_stepProcessLifecycle (playback_stepProcessLifecycle)
// Address: 680d7e30
// Size: 33 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepProcessLifecycle(void)

{
  byte *unaff_ESI;
  
  if (*(int *)(*(int *)(unaff_ESI + 0x20) + 0x67c) == 0) {
    playback_processLifecycle(unaff_ESI,1);
  }
  unaff_ESI[0x58] = 0xc;
  unaff_ESI[0x59] = 0;
  unaff_ESI[0x5a] = 0;
  unaff_ESI[0x5b] = 0;
  return 1;
}



// ============================================================
// Function: playback_stepSetupPaletteTransition (playback_stepSetupPaletteTransition)
// Address: 680d7e60
// Size: 125 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepSetupPaletteTransition(void)

{
  short sVar1;
  uint uVar2;
  undefined2 extraout_var;
  uint uVar3;
  void *this;
  int *unaff_ESI;
  undefined4 uVar4;
  short sVar5;
  short sVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  
  if ((unaff_ESI[0x2c] == 3) && (unaff_ESI[0x2e] == 0)) {
    uVar2 = (uint)*(ushort *)((int)unaff_ESI + 0x92);
    uVar3 = (uint)*(ushort *)(unaff_ESI + 0x25);
    if (*(ushort *)((int)unaff_ESI + 0x92) != *(ushort *)(unaff_ESI + 0x25)) {
      sVar6 = (short)unaff_ESI[0x26];
      uVar9 = 0;
      uVar8 = 0;
      uVar7 = 0;
      sVar5 = (short)unaff_ESI[0x30];
      uVar4 = 0;
      sVar1 = scoreEngine_getChannelData(unaff_ESI[8],(short)unaff_ESI[0x2d]);
      rendering_setupStageTransition(this,unaff_ESI,unaff_ESI[9],unaff_ESI[0x2c],CONCAT22(extraout_var,sVar1),uVar4,
                   uVar2,uVar3,sVar5,sVar6,uVar7,uVar8,uVar9);
      unaff_ESI[0x16] = 0xd;
      return 1;
    }
  }
  unaff_ESI[0x16] = 0xe;
  return 1;
}



// ============================================================
// Function: playback_stepRenderPaletteTransition (playback_stepRenderPaletteTransition)
// Address: 680d7ee0
// Size: 116 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepRenderPaletteTransition(undefined4 *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 100) == 0) {
    bVar1 = playback_isScoreReady();
    if (CONCAT31(extraout_var,bVar1) == 0) {
      iVar2 = rendering_setStageProperty(unaff_ESI,*(int *)(unaff_ESI + 0x24));
      if (iVar2 != 0) {
        uVar3 = Ordinal_1541();
        *param_1 = uVar3;
        display_renderSpriteLayer((undefined4 *)(unaff_ESI + 0x108),uVar3,*(int *)(unaff_ESI + 0xa4),
                     *(ushort *)(unaff_ESI + 0x154));
        *(undefined4 *)(unaff_ESI + 0x58) = 0xf;
        return 1;
      }
      goto LAB_680d7f43;
    }
  }
  rendering_updateStageRect(unaff_ESI,*(int *)(unaff_ESI + 0x24));
LAB_680d7f43:
  *(undefined4 *)(unaff_ESI + 0x58) = 0xe;
  return 1;
}



// ============================================================
// Function: playback_stepContinuePalette (playback_stepContinuePalette)
// Address: 680d7f60
// Size: 164 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepContinuePalette(void)

{
  short sVar1;
  uint uVar2;
  undefined2 extraout_var;
  int iVar3;
  uint uVar4;
  int *unaff_ESI;
  short sVar5;
  short sVar6;
  undefined1 uVar7;
  undefined1 uVar8;
  undefined1 uVar9;
  
  if (((unaff_ESI[0x2c] != 0) && (unaff_ESI[0x2c] == 3)) && (unaff_ESI[0x2e] != 0)) {
    if (unaff_ESI[0x2f] != 0) {
      sVar6 = (short)unaff_ESI[0x26];
      sVar5 = (short)unaff_ESI[0x30];
      uVar4 = (uint)*(ushort *)(unaff_ESI + 0x25);
      uVar9 = 0;
      uVar8 = 0;
      uVar7 = 0;
      uVar2 = (uint)*(ushort *)((int)unaff_ESI + 0x92);
      iVar3 = (int)(short)unaff_ESI[0x2b];
      sVar1 = scoreEngine_getChannelData(unaff_ESI[8],(short)unaff_ESI[0x2d]);
      rendering_setupStageTransition((void *)unaff_ESI[0x2c],unaff_ESI,unaff_ESI[9],unaff_ESI[0x2c],
                   CONCAT22(extraout_var,sVar1),iVar3,uVar2,uVar4,sVar5,sVar6,uVar7,uVar8,uVar9);
      unaff_ESI[0x2f] = 0;
    }
    iVar3 = rendering_setStageProperty((int)unaff_ESI,unaff_ESI[9]);
    if (iVar3 == 0) {
      unaff_ESI[0x2e] = 0;
    }
  }
  unaff_ESI[0x16] = 0x10;
  return 1;
}



// ============================================================
// Function: playback_stepWaitPaletteRender (playback_stepWaitPaletteRender)
// Address: 680d8010
// Size: 92 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepWaitPaletteRender(int *param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int unaff_ESI;
  int *unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + 0x58);
  iVar3 = Ordinal_1541();
  *param_1 = iVar3;
  iVar3 = display_renderSpriteFrame((int *)(unaff_ESI + 0x108),iVar3,unaff_EDI);
  if ((iVar3 == 0) && (*(int *)(unaff_ESI + 100) == 0)) {
    bVar2 = playback_isScoreReady();
    if (CONCAT31(extraout_var,bVar2) == 0) {
      *(undefined4 *)(unaff_ESI + 0x58) = uVar1;
      return 1;
    }
  }
  if (unaff_EDI != (int *)0x0) {
    *unaff_EDI = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x58) = 0xd;
  return 1;
}



// ============================================================
// Function: playback_stepAdvanceToSound (playback_stepAdvanceToSound)
// Address: 680d8070
// Size: 13 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepAdvanceToSound(void)

{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x58) = 0x11;
  return 1;
}



// ============================================================
// Function: playback_stepProcessSound (playback_stepProcessSound)
// Address: 680d8080
// Size: 324 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepProcessSound(int *param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int *unaff_ESI;
  undefined4 local_14;
  int local_10;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)(unaff_EBX + 0x58);
  if (*(int *)(unaff_EBX + 100) == 0) {
    iVar1 = media_getDataOffset(*(int *)(*(int *)(unaff_EBX + 0x18) + 4));
    if (iVar1 != 0) {
      iVar1 = 8;
      if (DAT_6818e790 != 0) {
        iVar2 = Ordinal_1541();
        *unaff_ESI = iVar2;
        Ordinal_1764(1);
        display_renderSpriteLayer((undefined4 *)&DAT_68196474,*unaff_ESI,1000,0x100);
        Ordinal_1130(&local_14,0xc);
        local_14 = 1;
        local_10 = 8;
        Ordinal_1763(&local_14,0);
        DAT_68196480 = 8;
        DAT_6818e790 = 0;
      }
      iVar2 = Ordinal_1541();
      *unaff_ESI = iVar2;
      iVar2 = display_renderSpriteFrame((int *)&DAT_68196474,iVar2,param_1);
      if (iVar2 != 0) {
        if (DAT_68196480 == 8) {
          Ordinal_1130(&local_14,0xc);
          iVar1 = 9;
        }
        else {
          Ordinal_1130(&local_14,0xc);
        }
        local_14 = 1;
        local_10 = iVar1;
        Ordinal_1763(&local_14,0);
        DAT_68196480 = iVar1;
        display_renderSpriteLayer((undefined4 *)&DAT_68196474,*unaff_ESI,1000,0x100);
        if (param_1 != (int *)0x0) {
          *param_1 = 0;
        }
      }
      *(undefined4 *)(unaff_EBX + 0x58) = local_8;
      return 2;
    }
  }
  else {
    media_getDataSize(*(int *)(*(int *)(unaff_EBX + 0x18) + 4),0);
  }
  *(undefined4 *)(unaff_EBX + 0x58) = 0x16;
  DAT_6818e790 = 1;
  return 1;
}



// ============================================================
// Function: playback_stepCheckCuePoint (playback_stepCheckCuePoint)
// Address: 680d81d0
// Size: 151 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepCheckCuePoint(void)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int unaff_ESI;
  
  uVar2 = *(undefined4 *)(unaff_ESI + 0x58);
  iVar3 = playback_getLifecycleState(unaff_ESI);
  if (((iVar3 == 0) || (*(int *)(unaff_ESI + 100) != 0)) ||
     (*(int *)(unaff_ESI + 0x2c) < *(int *)(unaff_ESI + 0xd4))) goto LAB_680d824c;
  puVar1 = (undefined4 *)(*(int *)(unaff_ESI + 0xd4) * 400 + -400 + *(int *)(unaff_ESI + 0x34));
  uVar4 = playback_isSpriteChannelActive(unaff_ESI,puVar1);
  if (*(short *)(unaff_ESI + 0xd2) != -2) {
    if (uVar4 != 0) goto LAB_680d824c;
    iVar3 = scoreEngine_isPastCuePoint(*(int **)(unaff_ESI + 0x20),*(int *)(unaff_ESI + 0xd4),
                         (int)*(short *)(unaff_ESI + 0xd2),0);
    if (iVar3 != 0) goto LAB_680d824c;
    if (*(int *)(unaff_ESI + 0xd4) < 0) goto LAB_680d825c;
    uVar4 = playback_checkSpriteSound(unaff_ESI,(int)puVar1,(int)*(short *)(unaff_ESI + 0xd2));
  }
  if (uVar4 == 0) {
LAB_680d825c:
    *(undefined4 *)(unaff_ESI + 0x58) = uVar2;
    return 1;
  }
LAB_680d824c:
  *(undefined4 *)(unaff_ESI + 0x58) = 0x16;
  return 1;
}



// ============================================================
// Function: playback_stepWaitTempo (playback_stepWaitTempo)
// Address: 680d8270
// Size: 168 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepWaitTempo(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int *unaff_EBX;
  int unaff_ESI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + 0x58);
  iVar2 = Ordinal_1541();
  *param_1 = iVar2;
  iVar2 = display_renderSpriteFrame((int *)(unaff_ESI + 0xfc),iVar2,unaff_EBX);
  if (((iVar2 == 0) && (*(int *)(unaff_ESI + 100) == 0)) &&
     (*(int *)(*(int *)(unaff_ESI + 0x20) + 0x660) == 0)) {
    *(undefined4 *)(unaff_ESI + 0x58) = uVar1;
    return 1;
  }
  if ((*(int *)(unaff_ESI + 0xb0) == 2) && (*(int *)(unaff_ESI + 0xb8) == 0)) {
    display_renderSpriteLayer((int *)(unaff_ESI + 0xfc),*param_1,*(int *)(unaff_ESI + 0x9c),
                 *(ushort *)(unaff_ESI + 0x154));
    if (unaff_EBX != (int *)0x0) {
      *unaff_EBX = 0;
    }
    *(undefined4 *)(unaff_ESI + 0x58) = 0x17;
    return 1;
  }
  *(undefined4 *)(unaff_ESI + 0x58) = 0x1b;
  return 1;
}



// ============================================================
// Function: playback_stepWaitTempoRender (playback_stepWaitTempoRender)
// Address: 680d8320
// Size: 92 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepWaitTempoRender(int *param_1)

{
  undefined4 uVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int unaff_ESI;
  int *unaff_EDI;
  
  uVar1 = *(undefined4 *)(unaff_ESI + 0x58);
  iVar3 = Ordinal_1541();
  *param_1 = iVar3;
  iVar3 = display_renderSpriteFrame((int *)(unaff_ESI + 0xfc),iVar3,unaff_EDI);
  if ((iVar3 == 0) && (*(int *)(unaff_ESI + 100) == 0)) {
    bVar2 = playback_isScoreReady();
    if (CONCAT31(extraout_var,bVar2) == 0) {
      *(undefined4 *)(unaff_ESI + 0x58) = uVar1;
      return 1;
    }
  }
  if (unaff_EDI != (int *)0x0) {
    *unaff_EDI = 0;
  }
  *(undefined4 *)(unaff_ESI + 0x58) = 0x18;
  return 1;
}



// ============================================================
// Function: playback_stepRenderTempo (playback_stepRenderTempo)
// Address: 680d8380
// Size: 128 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepRenderTempo(undefined4 *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined3 extraout_var;
  int iVar3;
  int unaff_ESI;
  
  uVar2 = Ordinal_1541();
  *param_1 = uVar2;
  display_renderSpriteLayer((undefined4 *)(unaff_ESI + 0x108),uVar2,
               0x10 - (int)(0x10 / (longlong)(0x1f - *(int *)(unaff_ESI + 0xa8))),
               *(ushort *)(unaff_ESI + 0x154));
  if (*(int *)(unaff_ESI + 100) == 0) {
    bVar1 = playback_isScoreReady();
    if (CONCAT31(extraout_var,bVar1) == 0) {
      iVar3 = rendering_setStageProperty(unaff_ESI,*(int *)(unaff_ESI + 0x24));
      *(uint *)(unaff_ESI + 0x58) = 0x1a - (uint)(iVar3 != 0);
      return 1;
    }
  }
  *(undefined4 *)(unaff_ESI + 0x58) = 0x1a;
  return 1;
}



// ============================================================
// Function: playback_stepWaitTempoFrame (playback_stepWaitTempoFrame)
// Address: 680d8400
// Size: 86 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepWaitTempoFrame(int *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 uVar3;
  int *unaff_ESI;
  int unaff_EDI;
  
  uVar3 = *(undefined4 *)(unaff_EDI + 0x58);
  bVar1 = playback_isScoreReady();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    iVar2 = Ordinal_1541();
    *param_1 = iVar2;
    iVar2 = display_renderSpriteFrame((int *)(unaff_EDI + 0x108),iVar2,unaff_ESI);
    if ((iVar2 == 0) && (*(int *)(unaff_EDI + 100) == 0)) goto LAB_680d8449;
    uVar3 = 0x18;
  }
  else {
    uVar3 = 0x1a;
  }
  if (unaff_ESI != (int *)0x0) {
    *unaff_ESI = 0;
  }
LAB_680d8449:
  *(undefined4 *)(unaff_EDI + 0x58) = uVar3;
  return 1;
}



// ============================================================
// Function: playback_stepFinishTempo (playback_stepFinishTempo)
// Address: 680d8460
// Size: 23 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepFinishTempo(void)

{
  int unaff_ESI;
  
  rendering_updateStageRect(unaff_ESI,*(int *)(unaff_ESI + 0x24));
  *(undefined4 *)(unaff_ESI + 0x58) = 0x1b;
  return 1;
}



// ============================================================
// Function: playback_stepFinishFrame (playback_stepFinishFrame)
// Address: 680d8480
// Size: 123 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_stepFinishFrame(int *param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  byte *unaff_ESI;
  undefined4 local_c;
  int local_8;
  
  uVar3 = *(undefined4 *)(unaff_ESI + 0x58);
  if (*(int *)(unaff_ESI + 100) == 0) {
    iVar1 = Ordinal_1541();
    iVar2 = display_renderSpriteFrame((int *)(unaff_ESI + 0xf0),iVar1,param_1);
    if (iVar2 != 0) {
      uVar3 = 1;
      local_c = playback_getCurrentFrame(unaff_ESI);
      local_8 = iVar1 - *(int *)(unaff_ESI + 0xf4);
      rendering_getChannelProperty((int)unaff_ESI,0x1c,&local_c);
      if (param_1 != (int *)0x0) {
        *param_1 = 0;
      }
    }
  }
  else {
    uVar3 = 1;
  }
  *(undefined4 *)(unaff_ESI + 0x58) = uVar3;
  unaff_ESI[100] = 0;
  unaff_ESI[0x65] = 0;
  unaff_ESI[0x66] = 0;
  unaff_ESI[0x67] = 0;
  return 1;
}



// ============================================================
// Function: playback_isStepActive (FUN_680d8500)
// Address: 680d8500
// Size: 19 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool playback_isStepActive(int param_1)

{
  return *(int *)(param_1 + 0x58) == 1;
}



// ============================================================
// Function: playback_isStepPastTransition (playback_isStepPastTransition)
// Address: 680d8520
// Size: 19 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool playback_isStepPastTransition(int param_1)

{
  return 0xf < *(int *)(param_1 + 0x58);
}



// ============================================================
// Function: playback_getStepFrameInfo (playback_getStepFrameInfo)
// Address: 680d8540
// Size: 50 bytes
// Params: byte * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getStepFrameInfo(byte *param_1,undefined4 *param_2)
{
  undefined4 uVar1;
  
  uVar1 = playback_getCurrentFrame(param_1);
  *param_2 = uVar1;
  param_2[1] = *(undefined4 *)(param_1 + 0xec);
  param_2[3] = *(undefined4 *)(param_1 + 0x48);
  param_2[2] = *(undefined4 *)(param_1 + 0x44);
  param_2[4] = *(undefined4 *)(param_1 + 0x50);
  return 0;
}



// ============================================================
// Function: playback_setNextFrame (playback_setNextFrame)
// Address: 680d8580
// Size: 21 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_setNextFrame(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x54) = param_2;
  return 1;
}



// ============================================================
// Function: playback_computeNextFrame (playback_computeNextFrame)
// Address: 680d85a0
// Size: 62 bytes
// Params: byte * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_computeNextFrame(byte *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = playback_getMaxFrame(param_1);
  iVar2 = *(int *)(param_1 + 0x54);
  if (iVar2 == 0) {
    iVar2 = playback_getCurrentFrame(param_1);
    iVar2 = iVar2 + 1;
  }
  if (iVar1 < iVar2) {
    if (((*param_1 & 2) != 0) && (0 < iVar1)) {
      return 1;
    }
    iVar2 = 0;
  }
  return iVar2;
}



// ============================================================
// Function: playback_syncMemberScore (playback_syncMemberScore)
// Address: 680d85e0
// Size: 121 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_syncMemberScore(void)
{
  int iVar1;
  int *unaff_ESI;
  int *unaff_EDI;
  undefined4 local_420 [262];
  uint local_8;
  
  iVar1 = rendering_getFrameCount((int)unaff_ESI);
  if (iVar1 != 0) {
    unaff_ESI[0xb] = unaff_ESI[0xb] & 0xfffffdff;
    rendering_dispatchUpdate((int)unaff_EDI,unaff_ESI,local_420,1);
    scoreEngine_readChannelBlock(unaff_EDI,unaff_ESI,1);
    unaff_ESI[0xb] = unaff_ESI[0xb] | 0x200;
    return 0;
  }
  scoreEngine_readChannelBlock(unaff_EDI,unaff_ESI,0);
  return 0;
}



// ============================================================
// Function: playback_playSoundChannels (playback_playSoundChannels)
// Address: 680d8660
// Size: 127 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_playSoundChannels(int param_1)
{
  int iVar1;
  uint uVar2;
  int local_c;
  undefined4 *local_8;
  
  Ordinal_1900(&local_c);
  if (local_c != 0) {
    local_8 = (undefined4 *)(param_1 + 0x78);
    uVar2 = 0;
    do {
      iVar1 = scoreEngine_getSoundFlag(*(int *)(param_1 + 0x20),uVar2);
      if (iVar1 == 0) {
        if (0 < (short)((uint)*local_8 >> 0x10)) {
          rendering_resolveState(*(int *)(param_1 + 0x18),*local_8);
          iVar1 = playback_syncMemberScore();
          if (iVar1 == 0) goto LAB_680d86cc;
        }
        scoreEngine_playSoundChannel(*(int **)(param_1 + 0x20),uVar2,param_1,*local_8);
      }
LAB_680d86cc:
      local_8 = local_8 + 1;
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 2);
  }
  return 0;
}



// ============================================================
// Function: playback_readScoreFrameProperties (playback_readScoreFrameProperties)
// Address: 680d86e0
// Size: 1344 bytes
// Params: byte * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_readScoreFrameProperties(byte *param_1)
{
  undefined1 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  byte *pbVar4;
  bool bVar5;
  byte bVar6;
  short sVar7;
  undefined2 uVar8;
  ushort uVar9;
  undefined2 extraout_var_00;
  undefined4 uVar10;
  int iVar11;
  undefined3 extraout_var;
  byte *pbVar12;
  short extraout_var_01;
  undefined2 extraout_var_02;
  byte *pbVar13;
  short sVar14;
  undefined1 *puVar15;
  uint local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined1 *local_8;
  short extraout_var_03;
  
  pbVar4 = param_1;
  local_8 = (undefined1 *)0x0;
  local_10 = (byte *)playback_getCurrentFrame(param_1);
  media_lockScoreData(*(int **)(param_1 + 0x28),&local_8,(undefined4 *)0x0);
  puVar1 = local_8;
  sVar7 = xtra_readBE16(local_8);
  xtra_readBE16(puVar1 + 2);
  sVar7 = scoreEngine_getChannelData(*(int *)(param_1 + 0x20),sVar7);
  *(uint *)(param_1 + 0xec) = CONCAT22(extraout_var_00,sVar7);
  puVar2 = *(undefined4 **)(param_1 + 0x128);
  *(uint *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 0x7fU & 0xff;
  pbVar4[0xd8] = 0;
  pbVar4[0xd9] = 0;
  pbVar4[0xda] = 0;
  pbVar4[0xdb] = 0;
  if ((((puVar2 != (undefined4 *)0x0) && (piVar3 = (int *)*puVar2, 1 < (int)local_10)) &&
      ((int)local_10 <= *piVar3)) && (iVar11 = piVar3[(int)local_10 + 1], 0 < iVar11)) {
    *(int *)(param_1 + 0xd8) = iVar11;
  }
  if (*(int *)(param_1 + 0xd8) == 0) {
    uVar10 = media_getScoreCompositeRef(*(int **)(param_1 + 0x28));
    if ((short)uVar10 < 1) {
      pbVar4[0xd8] = 0;
      pbVar4[0xd9] = 0;
      pbVar4[0xda] = 0;
      pbVar4[0xdb] = 0;
    }
    else {
      *(uint *)(param_1 + 0xd8) =
           (uint)((int)(0x3e800 / (longlong)(int)(short)uVar10) + *(int *)(param_1 + 0xe0)) >> 8;
    }
  }
  sVar14 = (short)(char)local_8[0x36];
  sVar7 = xtra_readBE16(local_8 + 0x34);
  iVar11 = 0;
  if (sVar14 == -9) {
    *(int *)(param_1 + 0xdc) = sVar7 * 1000;
  }
  else {
    pbVar4[0xdc] = 0;
    pbVar4[0xdd] = 0;
    pbVar4[0xde] = 0;
    pbVar4[0xdf] = 0;
    if (0 < sVar14) {
      iVar11 = (int)sVar14;
    }
  }
  *(short *)(param_1 + 0xd0) = sVar14;
  *(short *)(param_1 + 0xd2) = sVar7;
  *(int *)(param_1 + 0xd4) = iVar11;
  if ((sVar14 == -10) &&
     (bVar5 = lingo_isScriptReady(*(int *)(*(int *)(param_1 + 0x20) + 4)),
     CONCAT31(extraout_var,bVar5) != 0)) {
    rendering_getChannelProperty((int)param_1,6,(undefined4 *)0x0);
  }
  puVar1 = local_8;
  if (*(int *)(*(int *)(param_1 + 0x20) + 0x67c) != 0) {
    pbVar4[0xd8] = 0;
    pbVar4[0xd9] = 0;
    pbVar4[0xda] = 0;
    pbVar4[0xdb] = 0;
    pbVar4[0xdc] = 0;
    pbVar4[0xdd] = 0;
    pbVar4[0xde] = 0;
    pbVar4[0xdf] = 0;
  }
  uVar8 = xtra_readBE16(local_8 + 0x60);
  *(undefined2 *)(param_1 + 0x6c) = uVar8;
  uVar8 = xtra_readBE16(puVar1 + 0x62);
  *(undefined2 *)(param_1 + 0x6e) = uVar8;
  iVar11 = rendering_comparePaletteEntry(*(uint *)(param_1 + 0x20),*(uint *)(param_1 + 0x6c));
  if (iVar11 == 0) {
    pbVar4[0x6c] = 0;
    pbVar4[0x6d] = 0;
    pbVar4[0x6e] = 0;
    pbVar4[0x6f] = 0;
  }
  iVar11 = rendering_blendPaletteEntry(*(uint *)(param_1 + 0x20),*(uint *)(param_1 + 0x6c));
  if (iVar11 != 0) {
    rendering_updateStageDisplay(*(int *)(*(int *)(param_1 + 0x20) + 4) + 0x24);
  }
  puVar1 = local_8;
  puVar15 = local_8 + 0xf0;
  local_18 = ((int)(char)local_8[0xf5] & 4U) >> 2;
  local_14 = 0;
  if ((*(int *)(param_1 + 0xb8) == 1) && (local_18 == 0)) {
    rendering_updateStageRect((int)param_1,*(int *)(param_1 + 0x24));
    pbVar4[0xb8] = 0;
    pbVar4[0xb9] = 0;
    pbVar4[0xba] = 0;
    pbVar4[0xbb] = 0;
  }
  else if ((*(int *)(param_1 + 0xb8) == 0) && (local_18 == 1)) {
    pbVar4[0xbc] = 1;
    pbVar4[0xbd] = 0;
    pbVar4[0xbe] = 0;
    pbVar4[0xbf] = 0;
    pbVar4[0xb8] = 1;
    pbVar4[0xb9] = 0;
    pbVar4[0xba] = 0;
    pbVar4[0xbb] = 0;
  }
  switch(puVar1[0xf5] & 0xc0) {
  case 0:
    local_c = 1;
    break;
  case 0x40:
    local_c = 2;
    break;
  case 0x80:
  case 0xc0:
    local_c = 3;
    break;
  default:
    local_c = 0;
  }
  sVar7 = xtra_readBE16(puVar15);
  sVar14 = xtra_readBE16(puVar1 + 0xf2);
  param_1 = (byte *)CONCAT22(sVar14,sVar7);
  if ((local_10 == (byte *)0x1) && (sVar14 == 0)) {
    iVar11 = scoreEngine_getChannelState(*(int *)(pbVar4 + 0x20));
    media_setScoreReadRef(*(int *)(pbVar4 + 0x28),iVar11);
  }
  pbVar12 = (byte *)media_getScoreReadRef(*(int **)(pbVar4 + 0x28),(undefined4 *)0x0);
  local_10 = pbVar12;
  if ((short)((uint)pbVar12 >> 0x10) == 0) {
    pbVar12 = (byte *)scoreEngine_getChannelState(*(int *)(pbVar4 + 0x20));
    local_10 = pbVar12;
    media_setScoreReadRef(*(int *)(pbVar4 + 0x28),pbVar12);
  }
  if ((sVar7 != (short)pbVar12) || (sVar14 != (*(unsigned short *)((char *)&local_10 + 2)))) {
    local_14 = 1;
    param_1 = pbVar12;
  }
  sVar7 = (short)((uint)param_1 >> 0x10);
  if ((((sVar7 == 0) || (iVar11 = scoreEngine_setSoundVolume(*(uint *)(pbVar4 + 0x20),param_1), iVar11 != 0)) &&
      (sVar7 != 0)) &&
     (((short)param_1 != 0 &&
      (((sVar14 = playback_getChannelCount((int)pbVar4), (short)param_1 != sVar14 ||
        (playback_getChannelCount((int)pbVar4), sVar7 != extraout_var_01)) || (local_c != 1)))))) {
    *(byte **)(pbVar4 + 0xb4) = param_1;
    *(int *)(pbVar4 + 0xb0) = local_c;
    bVar6 = 0;
    if ((~(byte)((uint)(int)(char)puVar1[0xf5] >> 5) & 1) != 0) {
      bVar6 = 0xff;
    }
    pbVar4[0x90] = bVar6;
    *(uint *)(pbVar4 + 0xc0) = ((int)(char)puVar1[0xf5] & 0x10U) >> 4;
    uVar8 = xtra_readBE16(puVar1 + 0xf8);
    *(undefined2 *)(pbVar4 + 0xac) = uVar8;
    *(ushort *)(pbVar4 + 0x92) = (short)(char)puVar1[0xf6] ^ 0x80;
    *(ushort *)(pbVar4 + 0x94) = (short)(char)puVar1[0xf7] ^ 0x80;
    uVar9 = xtra_readBE16(puVar1 + 0xfa);
    *(uint *)(pbVar4 + 0x98) = (uint)uVar9;
    if (local_14 == 0) {
      iVar11 = (int)(char)puVar1[0xfd];
      if (iVar11 == 0) {
        iVar11 = 0x1e;
      }
      *(int *)(pbVar4 + 0x9c) = (iVar11 * 1000) / 0x3c;
      uVar9 = (ushort)(byte)puVar1[0xf4];
      if (0x1e < (byte)puVar1[0xf4]) {
        uVar9 = 0x1e;
      }
      sVar7 = uVar9 * -10 + 0x12d;
      *(int *)(pbVar4 + 0xa8) = (int)(short)uVar9;
      if (sVar7 < 0x101) {
        if ((sVar7 == 1) && (local_c == 2)) {
          sVar7 = 2;
        }
      }
      else {
        sVar7 = 0x100;
      }
      *(int *)(pbVar4 + 0xa0) = (int)sVar7;
    }
    else {
      pbVar4[0x9c] = 0;
      pbVar4[0x9d] = 0;
      pbVar4[0x9e] = 0;
      pbVar4[0x9f] = 0;
      pbVar4[0xa8] = 0x1e;
      pbVar4[0xa9] = 0;
      pbVar4[0xaa] = 0;
      pbVar4[0xab] = 0;
      pbVar4[0xa0] = 0;
      pbVar4[0xa1] = 0;
      pbVar4[0xa2] = 0;
      pbVar4[0xa3] = 0;
    }
    *(int *)(pbVar4 + 0xa4) = (int)((0x1e - ((int)(char)puVar1[0xf4] & 0x1fU)) * 1000) / 0x3c + 0x11
    ;
    if ((local_c == 3) && (local_18 == 0)) {
      pbVar4[0xa0] = 0;
      pbVar4[0xa1] = 0;
      pbVar4[0xa2] = 0;
      pbVar4[0xa3] = 0;
    }
  }
  else {
    pbVar4[0xb0] = 0;
    pbVar4[0xb1] = 0;
    pbVar4[0xb2] = 0;
    pbVar4[0xb3] = 0;
  }
  puVar15 = local_8;
  puVar1 = local_8 + 0x90;
  sVar7 = xtra_readBE16(local_8 + 0xc0);
  xtra_readBE16(puVar15 + 0xc2);
  sVar7 = scoreEngine_getChannelData(*(int *)(pbVar4 + 0x20),sVar7);
  pbVar12 = (byte *)CONCAT22(extraout_var_02,sVar7);
  sVar7 = xtra_readBE16(puVar1);
  xtra_readBE16(puVar15 + 0x92);
  sVar7 = scoreEngine_getChannelData(*(int *)(pbVar4 + 0x20),sVar7);
  pbVar13 = (byte *)CONCAT22(extraout_var_03,sVar7);
  Ordinal_1900(&local_18);
  param_1 = pbVar13;
  if ((((local_18 == 1) && (extraout_var_03 != 0)) &&
      (iVar11 = rendering_resolveState(*(int *)(pbVar4 + 0x18),pbVar13), iVar11 != 0)) &&
     (*(int *)(iVar11 + 8) == 6)) {
    param_1 = (byte *)CONCAT22(0xfffc,sVar7);
    pbVar12 = pbVar13;
  }
  *(byte **)(pbVar4 + 0x78) = pbVar12;
  *(byte **)(pbVar4 + 0x7c) = param_1;
  rendering_resetScoreData(*(int **)(pbVar4 + 0x28));
  if (local_8 != (undefined1 *)0x0) {
    media_unlockScoreData(*(int **)(pbVar4 + 0x28),&local_8,(undefined4 *)0x0);
  }
  return 0;
}



// ============================================================
// Function: playback_downgradeTransitionMode (playback_downgradeTransitionMode)
// Address: 680d8d00
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_downgradeTransitionMode(int param_1)
{
  if (*(int *)(param_1 + 0xb0) == 2) {
    *(undefined4 *)(param_1 + 0xb0) = 1;
  }
  return 0;
}



// ============================================================
// Function: playback_resetScoreSlots (playback_resetScoreSlots)
// Address: 680d8d20
// Size: 56 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resetScoreSlots(int param_1)
{
  int iVar1;
  
  media_setScoreSlot(*(int **)(param_1 + 0x28),0xffff);
  iVar1 = 0;
  if (0 < *(int *)(param_1 + 0x2c)) {
    do {
      media_writeScoreBlockEx(*(int **)(param_1 + 0x28),iVar1,0);
      iVar1 = iVar1 + 1;
    } while (iVar1 < *(int *)(param_1 + 0x2c));
  }
  return 0;
}



// ============================================================
// Function: playback_hasSavedStepState (playback_hasSavedStepState)
// Address: 680d8d60
// Size: 21 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool playback_hasSavedStepState(int param_1)

{
  return *(int *)(param_1 + 0xe4) != 0;
}



// ============================================================
// Function: playback_saveStepState (playback_saveStepState)
// Address: 680d8d80
// Size: 47 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_saveStepState(int param_1)
{
  *(undefined4 *)(param_1 + 0xe4) = *(undefined4 *)(param_1 + 0x58);
  *(undefined2 *)(param_1 + 0xe8) = *(undefined2 *)(param_1 + 0xd2);
  *(undefined2 *)(param_1 + 0xea) = *(undefined2 *)(param_1 + 0xd0);
  return 0;
}



// ============================================================
// Function: playback_restoreStepState (playback_restoreStepState)
// Address: 680d8db0
// Size: 89 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_restoreStepState(int param_1)
{
  if (*(int *)(param_1 + 0xe4) != 0) {
    *(int *)(param_1 + 0x58) = *(int *)(param_1 + 0xe4);
    *(undefined4 *)(param_1 + 0xe4) = 0;
  }
  if (*(short *)(param_1 + 0xe8) != 0) {
    *(short *)(param_1 + 0xd2) = *(short *)(param_1 + 0xe8);
    *(undefined2 *)(param_1 + 0xe8) = 0;
  }
  if (*(short *)(param_1 + 0xea) != 0) {
    *(short *)(param_1 + 0xd0) = *(short *)(param_1 + 0xea);
    *(undefined2 *)(param_1 + 0xea) = 0;
  }
  return 0;
}



// ============================================================
// Function: playback_playSoundIfNotLooping (playback_playSoundIfNotLooping)
// Address: 680d8e10
// Size: 12 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_playSoundIfNotLooping(void)
{
  byte *in_EAX;
  
  if ((*in_EAX & 1) == 0) {
    playback_playSoundChannels((int)in_EAX);
  }
  return 0;
}



// ============================================================
// Function: playback_stepBeginFrame (playback_stepBeginFrame)
// Address: 680d8e20
// Size: 374 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall playback_stepBeginFrame(int *param_1)

{
  short sVar1;
  int *in_EAX;
  short extraout_var;
  int *piVar2;
  uint uVar3;
  undefined2 extraout_var_00;
  int iVar4;
  undefined4 local_c [2];
  
  iVar4 = param_1[0x16];
  lingo_checkObjectValid(*(int *)(param_1[8] + 4));
  if ((param_1[0x19] == 0) && (param_1[0x2c] != 0)) {
    sVar1 = scoreEngine_getChannelData(param_1[8],(short)param_1[0x2d]);
    if (0 < extraout_var) {
      piVar2 = (int *)rendering_resolveState(param_1[6],CONCAT22(extraout_var,sVar1));
      if (piVar2 != (int *)0x0) {
        uVar3 = scoreEngine_readChannelBlock((int *)param_1[8],piVar2,0);
        if (uVar3 == 0) {
          param_1[0x16] = iVar4;
          return 1;
        }
      }
    }
    sVar1 = playback_getChannelCount((int)param_1);
    sVar1 = scoreEngine_getChannelData(param_1[8],sVar1);
    local_c[0] = CONCAT22(extraout_var_00,sVar1);
    rendering_getChannelProperty((int)param_1,0x11,local_c);
  }
  if (param_1[0x1a] == 0) {
    playback_resetTimerState();
    *in_EAX = param_1[0x32];
    param_1[0x33] = 0;
    display_renderSpriteLayer(param_1 + 0x3c,*in_EAX,param_1[0x36],*(ushort *)(param_1 + 0x55));
    display_renderSpriteLayer(param_1 + 0x3f,*in_EAX,param_1[0x37],*(ushort *)(param_1 + 0x55));
    iVar4 = Ordinal_1541();
    *in_EAX = iVar4;
  }
  playback_resetLifecycle((int)param_1,0xd,0);
  rendering_getChannelProperty((int)param_1,0x13,(undefined4 *)0x0);
  iVar4 = param_1[0x5b];
  param_1[0x5b] = 1;
  stage_notifySpriteIdle(*(int **)(param_1[8] + 8));
  param_1[0x5b] = iVar4;
  iVar4 = rendering_blendPaletteEntry(param_1[8],param_1[0x1b]);
  if (iVar4 != 0) {
    rendering_updateStageDisplay(param_1[9]);
  }
  if (*(int *)(param_1[8] + 0x67c) == 0) {
    rendering_setStageSize(param_1,param_1[9]);
  }
  playback_playSoundIfNotLooping();
  param_1[0x16] = 2;
  return 1;
}



