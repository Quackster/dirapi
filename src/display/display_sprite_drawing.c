// Module: display
// Topic: Sprite drawing, compositing, and text rendering
// Address range: 0x680fa210 - 0x680fbba0
// Functions (25):
//   display_updateSpriteSound
//   display_initSpriteTransform
//   display_detachSprite
//   display_updateSpriteChannel
//   display_drawFilmLoopSprite
//   display_releaseSpriteChannel
//   display_drawBitmapSprite
//   display_drawShapeSprite
//   display_renderShapeSprite
//   display_getSpriteDrawRef
//   display_getLinkedCastRef
//   display_drawSpriteEx
//   display_drawBitmapMember
//   display_clearDrawRef
//   display_renderSpriteToCanvas
//   display_drawSprite
//   display_drawSpriteForced
//   display_blitSpriteToCanvas
//   display_hitTestSprite
//   display_findFontByName
//   display_openFontResource
//   display_checkFontPrefs
//   display_loadFontData
//   display_saveFontData
//   display_lookupFont


// ============================================================
// Function: display_updateSpriteSound (FUN_680fa210)
// Address: 680fa210
// Size: 277 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_updateSpriteSound(int param_1,undefined4 *param_2,undefined4 param_3)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((*(byte *)(param_2 + 0x13) & 0xc0) == 0) {
    return 0;
  }
  piVar1 = (int *)playback_getSpriteData(param_1,param_2);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  if (*(char *)((int)piVar1 + 0x75) != '\x01') {
    return 0;
  }
  iVar2 = rendering_getMemberData(param_1,piVar1);
  if (iVar2 == 0) {
    return 0;
  }
  if ((*(byte *)(param_2 + 0x13) & 0x40) != 0) {
    if (param_2[0x57] == 0) {
      uVar3 = Ordinal_1871(DAT_681956e0,param_3,0,param_2[0x5a],param_2[0x5b],param_2[0x59],100,0,0)
      ;
      param_2[0x57] = uVar3;
    }
    else {
      Ordinal_1876(param_2[0x57],param_3,param_2[0x5a],param_2[0x5b],param_2[0x59]);
    }
  }
  if (((*(byte *)(param_2 + 0x13) & 0xc0) == 0) || (param_2[0x57] == 0)) {
LAB_680fa2fa:
    if (param_2[0x56] != 0) goto LAB_680fa311;
  }
  else {
    Ordinal_1874(param_2[0x57],piVar1[0x18] - piVar1[0x16],1);
    Ordinal_1875(param_2[0x57],piVar1[0x1e]);
    if (param_2[0x56] != 0) {
      Ordinal_1873(param_2[0x57],1);
      goto LAB_680fa2fa;
    }
  }
  Ordinal_1873(param_2[0x57],0);
LAB_680fa311:
  param_2[0x13] = param_2[0x13] & 0xffffff3f;
  rendering_isStateValid((int)piVar1);
  return 0;
}



// ============================================================
// Function: display_initSpriteTransform (FUN_680fa330)
// Address: 680fa330
// Size: 84 bytes
// Params: void * this, undefined4 * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall display_initSpriteTransform(void *this,undefined4 *param_1,undefined4 *param_2)
{
  int iVar1;
  
  iVar1 = *(int *)((int)this + 0x14c);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x158) = *(undefined4 *)((int)this + 200);
    *(undefined4 *)(iVar1 + 0x15c) = *(undefined4 *)((int)this + 0xcc);
    *(undefined4 *)(iVar1 + 0x160) = *(undefined4 *)((int)this + 0xd0);
    *(undefined4 *)(iVar1 + 0x164) = *(undefined4 *)((int)this + 0xd4);
    playback_setLifecycleData(*(int *)(iVar1 + 0x1c),(undefined4 *)(iVar1 + 0x158));
    playback_initLifecycleBlock(iVar1,param_1,param_2);
  }
  return 0;
}



// ============================================================
// Function: display_detachSprite (FUN_680fa390)
// Address: 680fa390
// Size: 289 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_detachSprite(int param_1)
{
  int *piVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  
  piVar5 = (int *)scoreEngine_setChannelField(*(uint *)(*(int *)(param_1 + 0x3c) + 0x20),
                               *(undefined4 *)(param_1 + 0x150));
  if ((piVar5 != (int *)0x0) && (piVar5[2] == 9)) {
    puVar2 = *(uint **)(param_1 + 0x14c);
    piVar3 = (int *)piVar5[0x1c];
    if ((piVar3 != (int *)0x0) && (puVar2 != (uint *)0x0)) {
      iVar4 = *piVar3;
      piVar1 = (int *)(param_1 + 0x148);
      *piVar3 = (int)puVar2;
      if (*piVar1 != 0) {
        if (puVar2[5] != 0) {
          stage_updateChannelsAtFrame(piVar3[2],(int)puVar2);
          puVar2[5] = 0;
        }
        scoreEngine_clearSoundRef((int)piVar3,0);
        scoreEngine_clearSoundRef((int)piVar3,1);
        if (*(int *)(puVar2[8] + 8) == 0) {
          events_releaseSpriteSlotObjects(*(int *)(*(int *)puVar2[6] + 0x14),(undefined4 *)puVar2[0xe],puVar2[0xb]);
        }
        else {
          events_removeAllSpriteSlots(*(int *)(puVar2[8] + 8),puVar2);
        }
        playback_createLifecycle((int)puVar2);
        stage_detachSprite(*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x20) + 8),(int)puVar2);
        playback_getLifecycleValue(puVar2);
        Ordinal_1115(*piVar1);
        Ordinal_1113(piVar1);
      }
      if (*(int *)(param_1 + 0x154) != 0) {
        rendering_isStateValid((int)piVar5);
        *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + -1;
      }
      rendering_releaseMemberData(piVar5);
      Ordinal_1130(piVar1,0x10);
      if (iVar4 != 0) {
        *piVar3 = iVar4;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: display_updateSpriteChannel (FUN_680fa4c0)
// Address: 680fa4c0
// Size: 225 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_updateSpriteChannel(int param_1,undefined4 *param_2)
{
  byte *pbVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = playback_getSpriteData(param_1,param_2);
  if ((*(uint *)(iVar4 + 0x2c) & 0x400) == 0) {
    pbVar1 = (byte *)param_2[0x53];
    piVar2 = *(int **)(iVar4 + 0x70);
    iVar3 = *piVar2;
    *piVar2 = (int)pbVar1;
    if ((*(byte *)(iVar4 + 0x68) & 0x10) == 0) {
      playback_getLifecycleFlags(pbVar1);
    }
    else {
      iVar4 = *(int *)(pbVar1 + 0x10);
      if (iVar4 != 0) {
        pbVar1[0x10] = 0;
        pbVar1[0x11] = 0;
        pbVar1[0x12] = 0;
        pbVar1[0x13] = 0;
        media_readPlaybackData(*(int *)(pbVar1 + 0x28),1,1);
        scoreEngine_markDirty(*(int *)(pbVar1 + 0x20),1);
        stage_renderSpritesAtFrame((int *)piVar2[2],(int)pbVar1);
        scoreEngine_setCastXtraFlag((int)piVar2,1);
        media_readPlaybackData(*(int *)(pbVar1 + 0x28),0,1);
      }
      iVar5 = media_getScoreState(*(int **)(pbVar1 + 0x28));
      if ((iVar5 < 1) || (iVar5 = stage_updateSpriteChannel((int *)piVar2[2],(int)pbVar1), iVar5 != 0)) {
        playback_getLifecycleFlags(pbVar1);
        events_switchChannel((int *)piVar2[2],(int)pbVar1);
        if (iVar4 != 0) {
          stage_drawScoreAtFrame(piVar2[2],(int)pbVar1);
          pbVar1[0x14] = 1;
          pbVar1[0x15] = 0;
          pbVar1[0x16] = 0;
          pbVar1[0x17] = 0;
        }
        stage_updateSpriteMapping(piVar2[2],(int)pbVar1);
      }
    }
    if (iVar3 != 0) {
      *piVar2 = iVar3;
    }
  }
  return 0;
}



// ============================================================
// Function: display_drawFilmLoopSprite (FUN_680fa5b0)
// Address: 680fa5b0
// Size: 1043 bytes
// Params: int param_1, undefined4 * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_drawFilmLoopSprite(int param_1,undefined4 *param_2,uint param_3)
{
  uint *puVar1;
  bool bVar2;
  undefined1 uVar3;
  int *piVar4;
  int iVar5;
  undefined3 extraout_var;
  byte *pbVar6;
  int iVar7;
  undefined3 extraout_var_00;
  int iVar8;
  uint uVar9;
  int *piVar10;
  undefined4 *puVar11;
  byte *pbVar12;
  int *piVar13;
  int local_50;
  int local_4c;
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  piVar4 = (int *)playback_getSpriteData(param_1,param_2);
  if (((piVar4 == (int *)0x0) || (piVar4[2] != 9)) || (iVar5 = playback_countLifecycleDepth(param_1), 0x13 < iVar5))
  goto LAB_680fa999;
  param_2[0x18] = 5;
  local_18 = piVar4[0x16];
  local_14 = piVar4[0x17];
  local_10 = piVar4[0x18];
  local_c = piVar4[0x19];
  Ordinal_1064(&local_18,-local_18,-local_14);
  iVar5 = playback_renderSprite((int)param_2,(int)piVar4,0);
  if ((*(byte *)(piVar4 + 0x1a) & 2) == 0) {
    local_20 = local_10;
    local_1c = local_c;
    local_24 = local_14;
    local_28 = local_18;
    iVar8 = local_c - local_14;
    local_50 = local_10 - local_18;
    if (iVar5 != 0) {
      iVar8 = param_2[9];
      local_50 = param_2[8];
    }
    if ((*(byte *)(piVar4 + 0x1a) & 1) == 0) {
      Ordinal_1064(&local_28,param_2[0x32] - local_18,param_2[0x33] - local_14);
    }
    else {
      Ordinal_1064(&local_28,(param_2[0x32] - ((local_10 - local_18) - local_50) / 2) - local_18,
                   (param_2[0x33] - ((local_c - local_14) - iVar8) / 2) - local_14);
    }
  }
  else {
    local_28 = param_2[0x32];
    local_24 = param_2[0x33];
    local_20 = param_2[0x34];
    local_1c = param_2[0x35];
  }
  if ((piVar4[0xb] & 0x400U) != 0) {
    iVar5 = rendering_getMemberData(param_1,piVar4);
    if ((iVar5 != 0) && (bVar2 = rendering_isStateValid((int)piVar4), CONCAT31(extraout_var,bVar2) == 0))
    goto LAB_680fa999;
    if ((piVar4[0xb] & 0x400U) != 0) goto LAB_680fa97e;
  }
  if ((param_2[0x52] == 0) || ((param_3 & 0x30004) != 0)) {
    display_detachSprite((int)param_2);
    if (param_2[0x55] == 0) {
      iVar5 = rendering_getMemberData(param_1,piVar4);
      if (iVar5 == 0) goto LAB_680fa999;
      param_2[0x55] = param_2[0x55] + 1;
    }
    iVar5 = Ordinal_1111(0x18c,1);
    if (iVar5 == 0) {
LAB_680fa999:
      if (param_2[0x55] != 0) {
        rendering_isStateValid((int)piVar4);
        param_2[0x55] = param_2[0x55] + -1;
      }
      return 0;
    }
    pbVar6 = (byte *)Ordinal_1114(iVar5);
    puVar11 = *(undefined4 **)piVar4[0x1c];
    pbVar12 = pbVar6;
    for (iVar8 = 99; iVar8 != 0; iVar8 = iVar8 + -1) {
      *(undefined4 *)pbVar12 = *puVar11;
      puVar11 = puVar11 + 1;
      pbVar12 = pbVar12 + 4;
    }
    iVar8 = playback_allocateChannelBuffers((int)pbVar6);
    if (iVar8 == 0) goto LAB_680fa999;
    pbVar6[0x128] = 0;
    pbVar6[0x129] = 0;
    pbVar6[0x12a] = 0;
    pbVar6[299] = 0;
    iVar7 = media_getVtableFunc(*(int **)(pbVar6 + 0x28));
    iVar8 = 0;
    if (iVar7 != 0) {
      iVar8 = Ordinal_1112(iVar7);
    }
    iVar7 = media_writePlaybackData(*(undefined4 *)(param_1 + 0x18),0,0);
    *(int *)(pbVar6 + 0x28) = iVar7;
    uVar3 = media_getPlaybackByte(iVar7,iVar8,*(int *)(*(int *)(param_1 + 0x20) + 0x500),0);
    if (CONCAT31(extraout_var_00,uVar3) == 0) goto LAB_680fa999;
    pbVar6[4] = 0;
    pbVar6[5] = 0;
    pbVar6[6] = 0;
    pbVar6[7] = 0;
    pbVar6[0xc] = 1;
    pbVar6[0xd] = 0;
    pbVar6[0xe] = 0;
    pbVar6[0xf] = 0;
    *(undefined4 *)(pbVar6 + 0x1c) = param_2[0xf];
    param_2[0x52] = iVar5;
    param_2[0x53] = pbVar6;
    param_2[0x54] = *param_2;
    playback_resetPlaybackPosition((int)pbVar6);
    playback_getLifecycleBlock((uint *)param_2[0x53],~((uint)piVar4[0x1a] >> 5) & 1);
    pbVar6[0x174] = 1;
    pbVar6[0x175] = 0;
    pbVar6[0x176] = 0;
    pbVar6[0x177] = 0;
    playback_getLifecycleFlags(pbVar6);
    pbVar6[0x174] = 0;
    pbVar6[0x175] = 0;
    pbVar6[0x176] = 0;
    pbVar6[0x177] = 0;
    pbVar6[0x170] = 1;
    pbVar6[0x171] = 0;
    pbVar6[0x172] = 0;
    pbVar6[0x173] = 0;
    pbVar6[0x10] = 1;
    pbVar6[0x11] = 0;
    pbVar6[0x12] = 0;
    pbVar6[0x13] = 0;
  }
  piVar10 = (int *)(param_2[0x53] + 300);
  piVar13 = &local_4c;
  for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar13 = *piVar10;
    piVar10 = piVar10 + 1;
    piVar13 = piVar13 + 1;
  }
  display_initSpriteTransform(param_2,&local_18,&local_28);
  if (((local_4c == *(int *)(param_2[0x53] + 300)) &&
      (iVar5 = Ordinal_1063(local_48,param_2[0x53] + 0x130), iVar5 != 0)) &&
     (iVar5 = Ordinal_1063(local_38,param_2[0x53] + 0x140), iVar5 != 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  puVar1 = (uint *)param_2[0x53];
  *puVar1 = *puVar1 ^ ((uint)piVar4[0x1a] >> 3 ^ *puVar1) & 1;
  uVar9 = *(uint *)param_2[0x53];
  if ((*(byte *)(param_2 + 0x13) & 4) == 0) {
    uVar9 = uVar9 & 0xffffffbf | 0x80;
  }
  else {
    uVar9 = uVar9 & 0xffffff7f | 0x40;
  }
  *(uint *)param_2[0x53] = uVar9;
  if (((param_3 & 0x30004) == 0) && (((param_3 & 0x1680) != 0 || (bVar2)))) {
    iVar5 = param_2[0x53];
    iVar8 = *(int *)(iVar5 + 0x120);
    if (iVar8 <= *(int *)(iVar5 + 0x124)) {
      iVar7 = iVar8 * 400;
      do {
        puVar11 = (undefined4 *)(*(int *)(iVar5 + 0x34) + iVar7);
        if ((*(byte *)(puVar11 + 0x13) & 1) != 0) {
          playback_getSpriteInfoEx(iVar5,puVar11,0x1000);
          playback_renderSpriteFrame((int)puVar11,0);
        }
        iVar8 = iVar8 + 1;
        iVar7 = iVar7 + 400;
      } while (iVar8 <= *(int *)(iVar5 + 0x124));
    }
  }
  param_2[0x13] = param_2[0x13] | 3;
  playback_setLifecycleData(param_2[0xf],param_2 + 0x32);
LAB_680fa97e:
  return 0;
}



// ============================================================
// Function: display_releaseSpriteChannel (FUN_680fa9d0)
// Address: 680fa9d0
// Size: 121 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_releaseSpriteChannel(int param_1)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)scoreEngine_setChannelField(*(uint *)(*(int *)(param_1 + 0x3c) + 0x20),
                               *(undefined4 *)(param_1 + 0x150));
  if ((piVar2 != (int *)0x0) && (piVar2[2] == 2)) {
    if (*(int *)(param_1 + 0x154) != 0) {
      rendering_isStateValid((int)piVar2);
      *(int *)(param_1 + 0x154) = *(int *)(param_1 + 0x154) + -1;
    }
    rendering_releaseMemberData(piVar2);
  }
  puVar1 = (undefined4 *)(param_1 + 0x148);
  if (*(int *)(param_1 + 0x148) != 0) {
    playback_getLifecycleValue(*(uint **)(param_1 + 0x14c));
    Ordinal_1115(*puVar1);
    Ordinal_1113(puVar1);
  }
  Ordinal_1130(puVar1,0x10);
  return 0;
}




// ============================================================
// Function: display_drawBitmapSprite (FUN_680faa50)
// Address: 680faa50
// Size: 1045 bytes
// Params: int param_1, undefined4 * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_drawBitmapSprite(int param_1,undefined4 *param_2,uint param_3)
{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  void *this;
  undefined3 extraout_var;
  int iVar5;
  uint uVar6;
  int *piVar7;
  undefined4 *puVar8;
  int *piVar9;
  bool bVar10;
  int local_50;
  int local_4c;
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  piVar2 = (int *)playback_getSpriteData(param_1,param_2);
  if (((piVar2 != (int *)0x0) && (piVar2[2] == 2)) && (iVar3 = playback_countLifecycleDepth(param_1), iVar3 < 0x14))
  {
    param_2[0x18] = 4;
    local_18 = piVar2[0x16];
    local_14 = piVar2[0x17];
    local_10 = piVar2[0x18];
    local_c = piVar2[0x19];
    param_2[0x17] = param_2[0x17] & 0xfffffffe;
    local_50 = playback_renderSprite((int)param_2,(int)piVar2,0);
    if ((*(byte *)(piVar2 + 0x1a) & 2) == 0) {
      local_20 = local_10;
      local_1c = local_c;
      bVar10 = local_50 != 0;
      local_24 = local_14;
      local_28 = local_18;
      iVar3 = local_c - local_14;
      local_50 = local_10 - local_18;
      if (bVar10) {
        iVar3 = param_2[9];
        local_50 = param_2[8];
      }
      if ((*(byte *)(piVar2 + 0x1a) & 1) == 0) {
        Ordinal_1064(&local_28,param_2[0x32] - local_18,param_2[0x33] - local_14);
      }
      else {
        Ordinal_1064(&local_28,(param_2[0x32] - ((local_10 - local_18) - local_50) / 2) - local_18,
                     (param_2[0x33] - ((local_c - local_14) - iVar3) / 2) - local_14);
      }
    }
    else {
      local_28 = param_2[0x32];
      local_24 = param_2[0x33];
      local_20 = param_2[0x34];
      local_1c = param_2[0x35];
    }
    if ((param_2[0x52] != 0) && ((param_3 & 0x30004) == 0)) {
LAB_680facfb:
      piVar7 = (int *)(param_2[0x53] + 300);
      piVar9 = &local_4c;
      for (iVar3 = 9; iVar3 != 0; iVar3 = iVar3 + -1) {
        *piVar9 = *piVar7;
        piVar7 = piVar7 + 1;
        piVar9 = piVar9 + 1;
      }
      display_initSpriteTransform(param_2,&local_18,&local_28);
      if (((local_4c == *(int *)(param_2[0x53] + 300)) &&
          (iVar3 = Ordinal_1063(local_48,param_2[0x53] + 0x130), iVar3 != 0)) &&
         (iVar3 = Ordinal_1063(local_38,param_2[0x53] + 0x140), iVar3 != 0)) {
        bVar10 = false;
      }
      else {
        bVar10 = true;
      }
      puVar4 = (uint *)param_2[0x53];
      *puVar4 = *puVar4 ^ ((uint)piVar2[0x1a] >> 3 ^ *puVar4) & 1;
      *(uint *)(param_2[0x53] + 0x150) = (uint)piVar2[0x1a] >> 2 & 1;
      uVar6 = *(uint *)param_2[0x53];
      if ((*(byte *)(param_2 + 0x13) & 4) == 0) {
        uVar6 = uVar6 & 0xffffffbf | 0x80;
      }
      else {
        uVar6 = uVar6 & 0xffffff7f | 0x40;
      }
      *(uint *)param_2[0x53] = uVar6;
      if (((param_3 & 0x30004) == 0) && (((param_3 & 0x1680) != 0 || (bVar10)))) {
        iVar3 = param_2[0x53];
        local_50 = *(int *)(iVar3 + 0x120);
        if (local_50 <= *(int *)(iVar3 + 0x124)) {
          iVar5 = local_50 * 400;
          do {
            puVar8 = (undefined4 *)(*(int *)(iVar3 + 0x34) + iVar5);
            if ((*(byte *)(puVar8 + 0x13) & 1) != 0) {
              playback_getSpriteInfoEx(iVar3,puVar8,0x1000);
              playback_renderSpriteFrame((int)puVar8,0);
            }
            local_50 = local_50 + 1;
            iVar5 = iVar5 + 400;
          } while (local_50 <= *(int *)(iVar3 + 0x124));
        }
      }
      param_2[0x13] = param_2[0x13] | 3;
      playback_setLifecycleData(param_2[0xf],param_2 + 0x32);
      playback_setLifecycleData(param_2[0xf],param_2 + 0x5c);
      return 0;
    }
    display_releaseSpriteChannel((int)param_2);
    if (param_2[0x55] == 0) {
      iVar3 = rendering_getMemberData(param_1,piVar2);
      if (iVar3 == 0) goto LAB_680fac7e;
      param_2[0x55] = param_2[0x55] + 1;
    }
    local_50 = Ordinal_1111(0x18c,1);
    if (local_50 != 0) {
      puVar4 = (uint *)Ordinal_1114(local_50);
      iVar3 = playback_initPlaybackState((int)puVar4,*(int *)(param_1 + 0x20));
      if (iVar3 != 0) {
        puVar4[7] = param_2[0xf];
        param_2[0x52] = local_50;
        param_2[0x53] = puVar4;
        param_2[0x54] = *param_2;
        this = (void *)Ordinal_1120(piVar2[0x15],0);
        if (((this != (void *)0x0) &&
            (iVar3 = playback_dispatchLifecycle(puVar4,*(int *)(*(int *)(param_1 + 0x20) + 4) + 0x24), iVar3 != 0)
            ) && ((iVar3 = playback_goToFrame(this,puVar4,(int)this,0,0), iVar3 != 0 &&
                  (uVar1 = media_setScoreChannelCount((int *)puVar4[10],piVar2[0x1c]),
                  CONCAT31(extraout_var,uVar1) != 0)))) {
          playback_setLifecycleRef((byte *)puVar4);
          media_setScoreChannelRef((int *)puVar4[10],*(undefined4 *)(param_1 + 0x20),(short)piVar2[1]);
          playback_resetPlaybackPosition((int)puVar4);
          playback_getLifecycleBlock(puVar4,~((uint)piVar2[0x1a] >> 5) & 1);
          puVar4[0x5d] = 1;
          playback_getLifecycleFlags((byte *)puVar4);
          puVar4[0x5d] = 0;
          puVar4[0x5c] = 1;
          goto LAB_680facfb;
        }
      }
      playback_getLifecycleValue(puVar4);
      Ordinal_1115(local_50);
      Ordinal_1113(&local_50);
      param_2[0x53] = 0;
      param_2[0x52] = 0;
    }
  }
LAB_680fac7e:
  if (param_2[0x55] != 0) {
    rendering_isStateValid((int)piVar2);
    param_2[0x55] = param_2[0x55] + -1;
  }
  return 0;
}



// ============================================================
// Function: display_drawShapeSprite (FUN_680fae70)
// Address: 680fae70
// Size: 193 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_drawShapeSprite(int param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = (int *)playback_getSpriteData(param_1,param_2);
  if ((piVar1 != (int *)0x0) && (piVar1[2] == 5)) {
    param_2[0x18] = 8;
    uVar2 = scoreEngine_readChannelBlock(*(int **)(param_1 + 0x20),piVar1,0);
    if (uVar2 == 0) {
      param_2[0x48] = 1;
      return 1;
    }
    param_2[0x48] = 0;
    iVar3 = rendering_getMemberData(param_1,piVar1);
    if (iVar3 != 0) {
      playback_renderSprite((int)param_2,(int)piVar1,0);
      param_2[0x13] = param_2[0x13] | 3;
      *(undefined1 *)((int)param_2 + 0x146) = 0xff;
      *(undefined2 *)(param_2 + 0x51) = 0xffff;
      *(undefined1 *)((int)param_2 + 0x147) = 1;
      param_2[0x50] = 0x1000000;
      param_2[0x4b] = 0;
      param_2[0x17] = 0x20;
      rendering_isStateValid((int)piVar1);
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: display_renderShapeSprite (FUN_680faf40)
// Address: 680faf40
// Size: 208 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_renderShapeSprite(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  iVar3 = 0;
  local_8 = 0;
  piVar1 = (int *)playback_getSpriteData(param_1,param_3);
  if ((piVar1 == (int *)0x0) || (piVar1[2] != 5)) {
    iVar3 = 1;
  }
  else {
    local_8 = rendering_getMemberData(param_1,piVar1);
    if (local_8 != 0) {
      iVar2 = Ordinal_1602(param_2);
      Ordinal_1608(param_2,param_3 + 0x32);
      iVar3 = Ordinal_1715(piVar1[0x15],param_3 + 0x32,param_2);
      if (iVar2 != 0) {
        Ordinal_1603(param_2);
      }
    }
  }
  iVar2 = lingo_getMovieRef(*(int *)(param_1 + 0x18));
  if (((iVar2 == 0) && (iVar3 == 0)) || (iVar3 = Ordinal_1041(), iVar3 != 0)) {
    iVar3 = Ordinal_1042();
    if (iVar3 == 0x66) {
      lingo_formatDebugMsg(*(int **)(param_1 + 0x18),-0x7d);
    }
    else {
      rendering_initMemberSlot(piVar1,-0x1ba);
    }
  }
  if (local_8 != 0) {
    rendering_isStateValid((int)piVar1);
  }
  rendering_releaseMemberData(piVar1);
  return 0;
}



// ============================================================
// Function: display_getSpriteDrawRef (FUN_680fb010)
// Address: 680fb010
// Size: 26 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_getSpriteDrawRef(undefined4 param_1,int param_2)
{
  Ordinal_1070(param_2 + 200,&stack0x0000000c);
  return 0;
}



// ============================================================
// Function: display_getLinkedCastRef (FUN_680fb030)
// Address: 680fb030
// Size: 46 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getLinkedCastRef(int param_1,int param_2,undefined4 *param_3)

{
  if ((*(byte *)(param_1 + 0x5c) & 0x10) != 0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(param_2 + 4);
      *(short *)((int)param_3 + 2) = *(short *)((int)param_3 + 2) + 1;
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: display_drawSpriteEx (FUN_680fb060)
// Address: 680fb060
// Size: 417 bytes
// Params: int param_1, int param_2, int * param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_drawSpriteEx(int param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  if (param_3 == (int *)0x0) {
    return 1;
  }
  iVar1 = rendering_getMemberData(param_1,param_3);
  if (iVar1 == 0) {
    *param_4 = 0;
    return 0;
  }
  *param_4 = 1;
  rendering_getMemberPropRefSimple(*(int *)(*(int *)(param_1 + 0x20) + 4),(int)param_3);
  *(undefined4 *)(param_2 + 0x148) = 0;
  if ((*(byte *)(param_2 + 0x5c) & 0x20) != 0) {
    *(undefined4 *)(param_2 + 0x148) = 1;
    *(int *)(param_2 + 0x14c) = param_3[1];
    *(undefined4 *)(param_2 + 0x150) = 0;
    *(undefined4 *)(param_2 + 0x154) = 0;
  }
  iVar1 = display_getLinkedCastRef(param_2,(int)param_3,&param_4);
  if (iVar1 != 0) {
    piVar2 = (int *)rendering_resolveState(*(int *)(param_1 + 0x18),param_4);
    if ((piVar2 != (int *)0x0) && ((piVar2[2] == 1 || (piVar2[2] == 0xd)))) {
      if (piVar2[0x1e] == 0) {
        iVar1 = rendering_getMemberData(param_1,piVar2);
        if (iVar1 == 0) {
          return 0;
        }
        uVar3 = lingo_isValidObject(*(int *)(*(int *)(param_1 + 0x20) + 4));
        param_4 = (undefined4 *)Ordinal_1605(uVar3);
        iVar1 = Ordinal_1604(uVar3,piVar2[0x15]);
        if (iVar1 != 0) {
          iVar1 = Ordinal_1670(uVar3,0,0,0);
          piVar2[0x1e] = iVar1;
        }
        Ordinal_1604(uVar3,param_4);
        rendering_isStateValid((int)piVar2);
        if ((*(byte *)(piVar2 + 0xe) & 2) == 0) {
          rendering_getMemberPropertyInfo((int)piVar2,0);
        }
      }
      if (*(int *)(param_2 + 0x148) == 0) {
        *(undefined4 *)(param_2 + 0x148) = 2;
        *(int *)(param_2 + 0x14c) = piVar2[1];
      }
      if ((*(byte *)(piVar2 + 0x27) & 0x20) == 0) {
        iVar1 = piVar2[0x22];
      }
      else {
        iVar1 = (piVar2[0x1b] - piVar2[0x19]) / 2;
      }
      *(int *)(param_2 + 0x150) = iVar1;
      if ((*(byte *)(piVar2 + 0x27) & 0x20) != 0) {
        *(int *)(param_2 + 0x154) = (piVar2[0x1c] - piVar2[0x1a]) / 2;
        return 1;
      }
      *(int *)(param_2 + 0x154) = piVar2[0x23];
    }
  }
  return 1;
}



// ============================================================
// Function: display_drawBitmapMember (FUN_680fb210)
// Address: 680fb210
// Size: 166 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_drawBitmapMember(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  
  puVar1 = param_2;
  piVar2 = (int *)playback_getSpriteData(param_1,param_2);
  if ((piVar2 != (int *)0x0) && ((piVar2[2] == 1 || (piVar2[2] == 0xd)))) {
    puVar1[0x18] = 1;
    if ((piVar2[0xb] & 0x200U) == 0) {
      param_2 = (undefined4 *)0x0;
      display_drawSpriteEx(param_1,(int)puVar1,piVar2,&param_2);
      if (param_2 != (undefined4 *)0x0) {
        rendering_isStateValid((int)piVar2);
      }
    }
    playback_renderSprite((int)puVar1,(int)piVar2,0);
    playback_renderSpriteData(param_1,puVar1,(uint)(1 < piVar2[0x18]));
    if ((*(byte *)(piVar2 + 0x27) & 0x10) != 0) {
      puVar1[0x17] = puVar1[0x17] & 0xfffffffe;
    }
    if ((*(byte *)(puVar1 + 0x17) & 0x20) != 0) {
      piVar2[0x27] = piVar2[0x27] | 0x40;
    }
    puVar1[0x13] = puVar1[0x13] | 3;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: display_clearDrawRef (FUN_680fb2c0)
// Address: 680fb2c0
// Size: 20 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_clearDrawRef(int param_1)
{
  *(undefined4 *)(param_1 + 0x148) = 0;
  return 0;
}



// ============================================================
// Function: display_renderSpriteToCanvas (FUN_680fb2e0)
// Address: 680fb2e0
// Size: 156 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_renderSpriteToCanvas(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  piVar1 = (int *)playback_getSpriteData(param_1,param_3);
  if (piVar1 != (int *)0x0) {
    piVar1[0x27] = piVar1[0x27] | 0x40;
  }
  iVar2 = display_drawSpriteEx(param_1,(int)param_3,piVar1,&local_8);
  if (iVar2 != 0) {
    iVar2 = piVar1[0x1d];
    if (param_3[0x46] == 0) {
      Ordinal_1635(param_2,param_3 + 0x36,iVar2,*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x684));
    }
    else if (iVar2 == 0) {
      Ordinal_1621(param_2,param_3 + 0x32);
    }
    else {
      Ordinal_1618(param_2,param_3 + 0x32,iVar2);
    }
  }
  if (local_8 != 0) {
    rendering_isStateValid((int)piVar1);
  }
  Ordinal_1042();
  return 0;
}




// ============================================================
// Function: display_drawSprite (FUN_680fb380)
// Address: 680fb380
// Size: 166 bytes
// Params: int param_1, undefined4 * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_drawSprite(int param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = param_2;
  iVar1 = param_1;
  if ((param_3 == (int *)0x0) || (param_2[0x52] == 0)) {
    param_1 = 0;
    param_3 = (int *)playback_getSpriteData(iVar1,param_2);
    if (param_3 == (int *)0x0) {
      return 0;
    }
    display_drawSpriteEx(iVar1,(int)puVar2,param_3,&param_1);
    if (param_1 != 0) {
      rendering_isStateValid((int)param_3);
    }
  }
  if (puVar2[0x52] == 1) {
    rendering_resolveStateEx(*(int *)(iVar1 + 0x18),puVar2[0x53],(uint *)0x0,(int *)&param_3);
    if (param_3 != (int *)0x0) {
      return param_3[0x1d];
    }
  }
  else if ((puVar2[0x52] == 2) &&
          (rendering_resolveStateEx(*(int *)(iVar1 + 0x18),puVar2[0x53],(uint *)0x0,(int *)&param_3),
          param_3 != (int *)0x0)) {
    return param_3[0x1e];
  }
  return 0;
}



// ============================================================
// Function: display_drawSpriteForced (FUN_680fb430)
// Address: 680fb430
// Size: 10 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall display_drawSpriteForced(int param_1)
{
  undefined4 *in_EAX;
  
  display_drawSprite(param_1,in_EAX,(int *)0x1);
  return 0;
}



// ============================================================
// Function: display_blitSpriteToCanvas (FUN_680fb440)
// Address: 680fb440
// Size: 670 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_blitSpriteToCanvas(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  int *local_20;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_24 = param_2;
  local_28 = 0;
  local_3c = 0;
  local_1c = (undefined4 *)0x0;
  local_38 = 0;
  piVar1 = (int *)playback_getSpriteData(param_1,param_3);
  local_20 = piVar1;
  if ((piVar1 == (int *)0x0) || ((piVar1[2] != 1 && (piVar1[2] != 0xd)))) {
    local_1c = (undefined4 *)0x1;
  }
  else {
    iVar2 = display_drawSpriteEx(param_1,(int)param_3,piVar1,&local_38);
    if ((iVar2 != 0) &&
       ((8 < piVar1[0x18] || (local_28 = rendering_setMemberProperty(param_1,(int)piVar1,0), local_28 != 0)))) {
      uVar3 = local_24;
      local_3c = Ordinal_1602(local_24);
      local_1c = param_3 + 0x32;
      Ordinal_1608(uVar3,local_1c);
      local_18 = param_3[0x1e];
      local_14 = param_3[0x1f];
      local_10 = param_3[0x20];
      local_c = param_3[0x21];
      local_30 = param_3[0x54];
      local_2c = param_3[0x55];
      local_34 = 0;
      uVar3 = lingo_isValidObject(*(int *)(*(int *)(param_1 + 0x20) + 4));
      uVar4 = Ordinal_1605(uVar3);
      Ordinal_1604(uVar3,local_20[0x15]);
      iVar2 = display_getLinkedCastRef((int)param_3,(int)local_20,(undefined4 *)0x0);
      if (iVar2 != 0) {
        local_30 = param_3[0x1a] - local_30;
        local_2c = param_3[0x1b] - local_2c;
      }
      Ordinal_1064(&local_18,-local_18,-local_14);
      if ((local_28 != 0) && (iVar2 = Ordinal_1610(uVar3), local_28 != iVar2)) {
        local_34 = Ordinal_1610(uVar3);
        Ordinal_1609(uVar3,local_28);
      }
      uVar5 = rendering_updateChannelState(*(int *)(param_1 + 0x20) + 0x48c);
      if ((uVar5 < 0x700) || ((*(byte *)(local_20 + 0x27) & 1) == 0)) {
        uVar6 = 0;
      }
      else {
        uVar6 = 1;
      }
      if (param_3[0x46] == 0) {
        uVar8 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x684);
        puVar10 = param_3 + 0x50;
        puVar9 = param_3 + 0x4b;
        piVar1 = &local_30;
        uVar7 = display_drawSpriteForced(param_1);
        local_1c = (undefined4 *)
                   Ordinal_1634(local_24,param_3 + 0x36,uVar3,&local_18,uVar7,piVar1,puVar9,puVar10,
                                uVar6,uVar8);
      }
      else {
        puVar10 = param_3 + 0x50;
        puVar9 = param_3 + 0x4b;
        piVar1 = &local_30;
        uVar8 = display_drawSpriteForced(param_1);
        local_1c = (undefined4 *)
                   Ordinal_1616(local_24,local_1c,uVar3,&local_18,uVar8,piVar1,puVar9,puVar10,uVar6)
        ;
      }
      Ordinal_1604(uVar3,uVar4);
      piVar1 = local_20;
      if (local_34 != 0) {
        Ordinal_1609(uVar3,local_34);
        piVar1 = local_20;
      }
    }
  }
  iVar2 = lingo_getMovieRef(*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 8));
  if ((((iVar2 == 0) && (local_1c == (undefined4 *)0x0)) || (iVar2 = Ordinal_1041(), iVar2 != 0)) &&
     (iVar2 = Ordinal_1042(), iVar2 != 0)) {
    if (iVar2 == 0x66) {
      lingo_formatDebugMsg(*(int **)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 8),-0x7d);
    }
    else {
      rendering_initMemberSlot(piVar1,-0x1b7);
    }
  }
  if (local_38 != 0) {
    rendering_isStateValid((int)piVar1);
  }
  rendering_releaseMemberData(piVar1);
  if (local_3c != 0) {
    Ordinal_1603(local_24);
  }
  return 0;
}



// ============================================================
// Function: display_hitTestSprite (FUN_680fb6e0)
// Address: 680fb6e0
// Size: 275 bytes
// Params: int param_1, undefined4 * param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_hitTestSprite(int param_1,undefined4 *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = Ordinal_1070(param_2 + 0x32,&param_3);
  if (iVar1 != 0) {
    if (param_2[0x46] == 0) {
      iVar1 = Ordinal_1084(param_2 + 0x36,&param_3);
      if (((iVar1 != 0) && ((*(byte *)(param_2 + 3) & 0x3f) == 8)) &&
         (iVar2 = display_drawSprite(param_1,param_2,(int *)0x0), iVar2 != 0)) {
        iVar1 = Ordinal_1678(iVar2,param_2 + 0x36,param_3,param_4);
        return iVar1;
      }
    }
    else if ((*(byte *)(param_2 + 3) & 0x3f) == 8) {
      iVar2 = display_drawSprite(param_1,param_2,(int *)0x0);
      if (iVar2 == 0) {
        return iVar1;
      }
      iVar4 = param_3 - param_2[0x32];
      iVar3 = param_4 - param_2[0x33];
      iVar1 = playback_updateSpriteRectRegion((int)param_2);
      if (iVar1 != 0) {
        iVar4 = ((param_2[0x20] - param_2[0x1e]) * iVar4) / (int)(param_2[0x34] - param_2[0x32]);
        iVar3 = ((param_2[0x21] - param_2[0x1f]) * iVar3) / (int)(param_2[0x35] - param_2[0x33]);
      }
      iVar1 = Ordinal_1672(iVar2,iVar4,iVar3);
      return iVar1;
    }
  }
  return iVar1;
}



// ============================================================
// Function: display_findFontByName (FUN_680fb800)
// Address: 680fb800
// Size: 278 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_findFontByName(undefined4 param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  undefined4 *in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  iVar5 = 0;
  local_10 = 0;
  iVar2 = Ordinal_1042();
  iVar3 = Ordinal_1404(&local_c,param_1,1);
  if (iVar3 != 0) {
    iVar3 = Ordinal_1414(local_c);
    if (iVar3 == 0x32589bfe) {
      if (in_EAX != (undefined4 *)0x0) {
        *in_EAX = 1;
      }
LAB_680fb84d:
      local_10 = 1;
    }
    else {
      iVar3 = Ordinal_1414(local_c);
      while (((iVar3 != 0 && (1 < iVar3)) && (iVar3 < 0x4001))) {
        if (iVar5 < iVar3) {
          Ordinal_1127(&local_8);
          local_8 = Ordinal_1126(iVar3,0);
          iVar5 = iVar3;
          if (local_8 == 0) break;
        }
        iVar4 = Ordinal_1409(local_c,local_8,iVar3);
        if (iVar4 == 0) break;
        *(undefined1 *)(iVar3 + -1 + local_8) = 0;
        if (param_3 == 0) {
          sVar1 = Ordinal_1208(local_8,param_2);
        }
        else {
          sVar1 = Ordinal_1206(local_8,param_2);
        }
        if (sVar1 == 0) goto LAB_680fb84d;
        iVar3 = Ordinal_1414(local_c);
      }
    }
  }
  Ordinal_1127(&local_8);
  Ordinal_1407(&local_c);
  Ordinal_1042();
  if (iVar2 != 0) {
    Ordinal_1040(iVar2);
  }
  return local_10;
}



// ============================================================
// Function: display_openFontResource (FUN_680fb920)
// Address: 680fb920
// Size: 243 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_openFontResource(int *param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = 0;
  if (*param_1 == 0) {
    iVar1 = Ordinal_1111(4,1);
    *param_1 = iVar1;
    if (iVar1 == 0) goto LAB_680fba01;
  }
  iVar1 = Ordinal_1404(&local_8,*param_1,2);
  if (iVar1 != 0) {
    uVar2 = Ordinal_1435(local_8);
    Ordinal_1425(local_8,-(uint)(in_EAX != 0) & 0x32589bfe);
    if (unaff_EBX != 0) {
      iVar1 = Ordinal_1201();
      if (0x3ffe < iVar1 - 1U) goto LAB_680fba01;
      Ordinal_1432(local_8,0,2);
      iVar1 = Ordinal_1425(local_8,iVar1 + 1);
      if (iVar1 == 0) {
        Ordinal_1434(local_8,uVar2);
        Ordinal_1407(&local_8);
        return 0;
      }
      iVar1 = Ordinal_1420(local_8);
      if (iVar1 == 0) {
        Ordinal_1434(local_8,uVar2);
        Ordinal_1407(&local_8);
        return 0;
      }
    }
    local_c = 1;
  }
LAB_680fba01:
  Ordinal_1407(&local_8);
  return local_c;
}



// ============================================================
// Function: display_checkFontPrefs (FUN_680fba20)
// Address: 680fba20
// Size: 72 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_checkFontPrefs(int param_1)

{
  int iVar1;
  int unaff_ESI;
  
  if ((((unaff_ESI != 0) && (iVar1 = scoreEngine_checkPrefsFile(unaff_ESI), iVar1 != 0)) &&
      ((param_1 == 0 ||
       ((iVar1 = Ordinal_1351(), iVar1 != 0 || (iVar1 = Ordinal_1357(), iVar1 != 0)))))) &&
     (iVar1 = Ordinal_1317(), iVar1 != 0)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: display_loadFontData (FUN_680fba70)
// Address: 680fba70
// Size: 132 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_loadFontData(void)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_424;
  undefined1 local_420 [1048];
  uint local_8;
  
  local_424 = 0;
  if (DAT_68196938 == 0) {
    display_checkFontPrefs(0);
    iVar1 = Ordinal_1402(&local_424,local_420,1);
    if (iVar1 != 0) {
      uVar2 = Ordinal_1435(local_424,0);
      DAT_68196938 = Ordinal_1439(local_424,uVar2);
    }
  }
  Ordinal_1407(&local_424);
  return 0;
}



// ============================================================
// Function: display_saveFontData (FUN_680fbb00)
// Address: 680fbb00
// Size: 151 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_saveFontData(void)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_424;
  undefined1 local_420 [1048];
  uint local_8;
  
  local_424 = 0;
  if (DAT_68196938 != 0) {
    display_checkFontPrefs(1);
    iVar1 = Ordinal_1401(&local_424,local_420,7);
    if (iVar1 != 0) {
      uVar2 = Ordinal_1114(DAT_68196938);
      uVar3 = Ordinal_1116(DAT_68196938);
      Ordinal_1420(local_424,uVar2,uVar3);
      Ordinal_1115(DAT_68196938);
    }
  }
  Ordinal_1407(&local_424);
  return 0;
}



// ============================================================
// Function: display_lookupFont (FUN_680fbba0)
// Address: 680fbba0
// Size: 88 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_lookupFont(undefined4 param_1)

{
  int iVar1;
  char *unaff_EBX;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = 0;
  display_loadFontData();
  if ((DAT_68196938 != 0) && (iVar1 = display_findFontByName(DAT_68196938,param_1,0), iVar1 != 0)) {
    return 1;
  }
  if (((DAT_6819693c != 0) && (*unaff_EBX != '\0')) &&
     (iVar1 = display_findFontByName(DAT_6819693c,unaff_EBX,1), iVar1 != 0)) {
    return 1;
  }
  return 0;
}



