// Module: playback
// Topic: Sprite channel rendering - ink, geometry, transforms, channel setup and updates
// Address range: 0x680dc230 - 0x680dfd80
// Functions (68):
//   playback_renderSpriteEx, playback_initSpriteChannelState, playback_updateSpriteChannelState, playback_setupSpriteTransform, playback_applySpriteInk
//   playback_renderSpriteInk, playback_processSpriteRegion, playback_computeSpriteRect, playback_initSpriteRender, playback_resolveSpriteChannel
//   playback_computeSpriteTransform, playback_updateSpriteFrame, playback_renderSpriteFrame, playback_getSpriteRef, playback_validateSpriteState
//   playback_resetSpriteRegion, playback_getSpriteDataRef, playback_updateSpriteData, playback_destroySpriteInstance, playback_initSpriteInstance
//   playback_isSpriteChannelActive, playback_createSpriteState, playback_updateSpriteChannelData, playback_processSpriteChannelUpdate, playback_resolveSpriteCastMember
//   playback_getSpriteState, playback_getSpriteData, playback_processSpriteVisibility, playback_hitTestSprite, playback_setSpriteChannelRef
//   playback_getSpriteChannelDataRef, playback_writeSpriteChannelState, playback_readSpriteChannelState, playback_renderSpriteLayer, playback_processSpriteScript
//   playback_renderSprite, playback_notifySpriteEvent, playback_handleSpriteMouseEvent, playback_dispatchSpriteEvent, playback_getSpriteRegionRef
//   playback_initSpriteRectState, playback_clearSpriteRectState, playback_updateSpriteRectRegion, playback_invalidateSpriteRect, playback_getSpriteBounds
//   playback_checkSpriteSound, playback_querySpriteInkProperty, playback_processSpriteInkBlend, playback_renderSpriteData, playback_getSpriteRenderData
//   playback_getSpriteProperty, playback_renderSpriteToBuffer, playback_composeSpriteLayer, playback_blendSpriteLayer, playback_paintSpriteToStage
//   playback_getSpriteInfo, playback_getSpriteInfoEx, playback_teardownSpriteState, playback_processChannelScript, playback_handleSpriteCallback
//   playback_dispatchSpriteCallback, playback_renderSpriteAt, playback_renderSpriteBlock, playback_processSpriteCallback, playback_checkSpriteCallbackEvent
//   playback_verifySpriteCallbackTarget, playback_buildSpriteCallbackParams, playback_executeSpriteCallback, playback_releaseSpriteCallback, playback_initSpriteCallbackState
//   playback_registerSpriteCallback, playback_unregisterSpriteCallback

// ============================================================
// Function: playback_renderSpriteEx (FUN_680dc230)
// Address: 680dc230
// Size: 125 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_renderSpriteEx(int param_1,int param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  int iVar2;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  undefined4 *puVar3;
  undefined4 local_8;
  
  puVar3 = &local_8;
  local_8 = 0;
  uVar1 = Ordinal_1016();
  iVar2 = playback_setControlProperty(param_2,&DAT_6817ce98,uVar1,puVar3);
  this = extraout_ECX;
  if (iVar2 == 0) {
    puVar3 = &local_8;
    uVar1 = Ordinal_1016();
    iVar2 = playback_setControlProperty(*(int *)(param_1 + 4) + 8,&DAT_6817ce98,uVar1,puVar3);
    this = extraout_ECX_00;
    if (iVar2 == 0) {
      return 0;
    }
  }
  if (0 < param_4) {
    playback_initFontMap(this,param_4);
  }
  if (iVar2 != 0) {
    Ordinal_1115(local_8);
  }
  return 1;
}



// ============================================================
// Function: playback_initSpriteChannelState (playback_initSpriteChannelState)
// Address: 680dc2b0
// Size: 120 bytes
// Params: int param_1, int param_2, ushort * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_initSpriteChannelState(int param_1,int param_2,ushort *param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 local_8;
  
  puVar3 = &local_8;
  local_8 = 0;
  uVar1 = Ordinal_1016();
  iVar2 = playback_setControlProperty(param_2,&DAT_6817ce94,uVar1,puVar3);
  if (iVar2 == 0) {
    puVar3 = &local_8;
    uVar1 = Ordinal_1016();
    iVar2 = playback_setControlProperty(*(int *)(param_1 + 4) + 8,&DAT_6817ce94,uVar1,puVar3);
    if (iVar2 == 0) {
      return 0;
    }
  }
  playback_remapFontCharacters(param_3);
  if (iVar2 != 0) {
    Ordinal_1115(local_8);
  }
  return 1;
}



// ============================================================
// Function: playback_updateSpriteChannelState (playback_updateSpriteChannelState)
// Address: 680dc330
// Size: 136 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_updateSpriteChannelState(int param_1,int param_2,undefined4 param_3,int param_4)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0;
  uVar2 = Ordinal_1016(&DAT_6817ce98);
  sVar1 = Ordinal_1206(uVar2);
  if (sVar1 != 0) {
    puVar5 = &local_8;
    puVar4 = &DAT_6817ce98;
    uVar2 = Ordinal_1016();
    iVar3 = playback_setControlProperty(param_2,uVar2,puVar4,puVar5);
    this = extraout_ECX;
    if (iVar3 == 0) {
      puVar5 = &local_8;
      puVar4 = &DAT_6817ce98;
      uVar2 = Ordinal_1016();
      iVar3 = playback_setControlProperty(*(int *)(param_1 + 4) + 8,uVar2,puVar4,puVar5);
      this = extraout_ECX_00;
      if (iVar3 == 0) {
        return 1;
      }
    }
    playback_initFontMap(this,param_4);
    if (iVar3 != 0) {
      Ordinal_1115(local_8);
    }
  }
  return 1;
}



// ============================================================
// Function: playback_setupSpriteTransform (playback_setupSpriteTransform)
// Address: 680dc3c0
// Size: 135 bytes
// Params: int param_1, int param_2, ushort * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_setupSpriteTransform(int param_1,int param_2,ushort *param_3)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  undefined4 *puVar5;
  undefined4 local_8;
  
  local_8 = 0;
  uVar2 = Ordinal_1016(&DAT_6817ce94);
  sVar1 = Ordinal_1206(uVar2);
  if (sVar1 != 0) {
    puVar5 = &local_8;
    puVar4 = &DAT_6817ce94;
    uVar2 = Ordinal_1016();
    iVar3 = playback_setControlProperty(param_2,uVar2,puVar4,puVar5);
    if (iVar3 == 0) {
      puVar5 = &local_8;
      puVar4 = &DAT_6817ce94;
      uVar2 = Ordinal_1016();
      iVar3 = playback_setControlProperty(*(int *)(param_1 + 4) + 8,uVar2,puVar4,puVar5);
      if (iVar3 == 0) {
        return 1;
      }
    }
    playback_remapFontCharacters(param_3);
    if (iVar3 != 0) {
      Ordinal_1115(local_8);
    }
  }
  return 1;
}



// ============================================================
// Function: playback_applySpriteInk (playback_applySpriteInk)
// Address: 680dc450
// Size: 195 bytes
// Params: int * param_1, int param_2, int param_3, uint param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_applySpriteInk(int *param_1,int param_2,int param_3,uint param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  int local_14;
  void *local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  local_10 = (void *)0x0;
  bVar1 = false;
  local_8 = Ordinal_1111(1,1);
  if ((local_8 == 0) || (iVar2 = Ordinal_1404(&local_10,local_8,2), iVar2 == 0)) {
    lingo_formatDebugMsg(param_1,-0x7a);
  }
  else {
    iVar2 = playback_openScore(param_2,FOURCC_Fmap,param_3,&local_14,&local_c);
    if (iVar2 != 0) {
      local_c = 0;
      local_14 = 0;
    }
    iVar2 = playback_writeFontMapBlock(local_10,param_1,local_14,param_4);
    if (iVar2 != 0) {
      bVar1 = true;
    }
  }
  Ordinal_1407(&local_c);
  Ordinal_1407(&local_10);
  if ((bVar1) && (uVar3 = Ordinal_1116(local_8), 1 < uVar3)) {
    return local_8;
  }
  playback_initFontMapEx();
  return local_8;
}



// ============================================================
// Function: playback_renderSpriteInk (playback_renderSpriteInk)
// Address: 680dc520
// Size: 220 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_renderSpriteInk(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int local_10 [2];
  undefined4 local_8;
  
  piVar1 = (int *)*param_1;
  local_8 = 0;
  if (param_3 == 0) {
    Ordinal_1130(local_10,8);
    piVar5 = local_10;
    iVar2 = playback_deserializeFontMap(piVar1,piVar5,param_1[0x13],piVar1[1] + 8);
    if (iVar2 == 0) {
      piVar5 = (int *)0x0;
      lingo_formatDebugMsg(piVar1,-0x7a);
      goto LAB_680dc5e0;
    }
  }
  else {
    piVar5 = (int *)(param_3 + 0x14);
  }
  iVar2 = playback_scanMemberFontRefs((short)param_1[1],(int)piVar5,*param_1);
  if ((iVar2 != 0) && (iVar2 = playback_saveFontMapToScore(param_1[0x13],(int)piVar5), iVar2 != 0)) {
    uVar3 = Ordinal_1116(param_1[0x13]);
    uVar4 = Ordinal_1114(param_1[0x13]);
    iVar2 = Ordinal_1420(param_2,uVar4,uVar3);
    Ordinal_1115(param_1[0x13]);
    if (iVar2 != 0) {
      local_8 = 1;
      goto LAB_680dc5e0;
    }
  }
  lingo_formatDebugMsg(piVar1,-0x7a);
LAB_680dc5e0:
  if ((param_3 == 0) && (piVar5 != (int *)0x0)) {
    playback_getFontMapState(piVar5);
  }
  return local_8;
}



// ============================================================
// Function: playback_processSpriteRegion (playback_processSpriteRegion)
// Address: 680dc600
// Size: 138 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_processSpriteRegion(int *param_1,int param_2,int param_3,undefined4 param_4)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  piVar1 = (int *)*param_1;
  uVar3 = 0;
  local_8 = 0;
  iVar2 = Ordinal_1403(&local_8,0);
  if (iVar2 == 0) {
    lingo_formatDebugMsg(piVar1,-0x7a);
    Ordinal_1407(&local_8);
    return 0;
  }
  iVar2 = playback_renderSpriteInk(param_1,local_8,param_3);
  if (iVar2 != 0) {
    Ordinal_1432(local_8,0,0);
    iVar2 = playback_serializeFontMap(param_4,local_8,piVar1,param_2);
    if (iVar2 != 0) {
      uVar3 = 1;
    }
  }
  Ordinal_1407(&local_8);
  return uVar3;
}



// ============================================================
// Function: playback_computeSpriteRect (playback_computeSpriteRect)
// Address: 680dc690
// Size: 201 bytes
// Params: int param_1, ushort param_2, int param_3, void * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_computeSpriteRect(int param_1,ushort param_2,int param_3,void *param_4)

{
  ushort uVar1;
  int iVar2;
  ushort *puVar3;
  int *piVar4;
  ushort local_20 [14];
  
  piVar4 = (int *)0x0;
  if (param_1 == 0) {
    return 0;
  }
  if (param_3 == 0) {
    return 0;
  }
  if (param_4 == (void *)0x0) {
    return 0;
  }
  if (*(int *)(param_1 + 4) != 0) {
    piVar4 = (int *)Ordinal_1114(*(int *)(param_1 + 4));
    iVar2 = *piVar4;
    puVar3 = (ushort *)(piVar4 + 2);
    if (iVar2 != 0) {
      uVar1 = *puVar3;
      while ((uVar1 != param_2 && (iVar2 = iVar2 + -1, 0 < iVar2))) {
        puVar3 = puVar3 + 0xe;
        uVar1 = *puVar3;
      }
      if (iVar2 != 0) goto LAB_680dc6ff;
    }
  }
  Ordinal_1130(local_20,0x1c);
  puVar3 = local_20;
LAB_680dc6ff:
  if ((*(int *)(puVar3 + 8) != 0) && ((param_2 & 0x4000) == 0)) {
    Ordinal_1114(*(int *)(puVar3 + 8));
    playback_initFontMap(param_4,(int)param_4);
    Ordinal_1115(*(int *)(puVar3 + 8));
  }
  iVar2 = playback_mapFont(0,param_3,(int)param_4,0);
  if (piVar4 != (int *)0x0) {
    Ordinal_1115(*(undefined4 *)(param_1 + 4));
  }
  return iVar2;
}



// ============================================================
// Function: playback_initSpriteRender (FUN_680dc760)
// Address: 680dc760
// Size: 61 bytes
// Params: int * param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_initSpriteRender(int *param_1,int *param_2)

{
  short sVar1;
  
  sVar1 = 0;
  if (*param_2 < *param_1) {
    return 1;
  }
  if (*param_2 <= *param_1) {
    if (param_2[1] < param_1[1]) {
      return 1;
    }
    if (param_2[1] <= param_1[1]) goto LAB_680dc794;
  }
  sVar1 = -1;
LAB_680dc794:
  return (int)sVar1;
}



// ============================================================
// Function: playback_resolveSpriteChannel (playback_resolveSpriteChannel)
// Address: 680dc7a0
// Size: 100 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resolveSpriteChannel(void)
{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(unaff_EDI + 0x3c) != 0) {
    local_c = *(undefined4 *)(unaff_ESI + 0x40);
    local_10 = *(undefined4 *)(unaff_ESI + 0x44);
    iVar1 = Ordinal_1165(*(int *)(unaff_EDI + 0x3c),&local_8,&local_10,playback_initSpriteRender,0);
    if (iVar1 == 0) {
      local_10 = *(undefined4 *)(unaff_ESI + 0x48);
      iVar1 = Ordinal_1165(*(undefined4 *)(unaff_EDI + 0x3c),&local_8,&local_10,playback_initSpriteRender,0);
      if (iVar1 == 0) {
        return 0;
      }
    }
    Ordinal_1160(*(undefined4 *)(unaff_EDI + 0x3c),local_8);
  }
  return 0;
}



// ============================================================
// Function: playback_computeSpriteTransform (playback_computeSpriteTransform)
// Address: 680dc810
// Size: 179 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_computeSpriteTransform(void)
{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = *(undefined4 *)(unaff_EDI + 0x40);
  local_10 = *(int *)(unaff_EDI + 0x48);
  if (*(int *)(unaff_ESI + 0x3c) == 0) {
    uVar1 = Ordinal_1150(0x78,0x78,8);
    *(undefined4 *)(unaff_ESI + 0x3c) = uVar1;
  }
  if (*(int *)(unaff_ESI + 0x3c) != 0) {
    iVar2 = Ordinal_1165(*(int *)(unaff_ESI + 0x3c),&local_8,&local_10,playback_initSpriteRender,0);
    if (iVar2 != 0) {
      if (*(int *)(unaff_EDI + 0x44) == *(int *)(unaff_EDI + 0x48)) {
        return 0;
      }
      iVar2 = Ordinal_1160(*(undefined4 *)(unaff_ESI + 0x3c),local_8);
      if (iVar2 == 0) goto LAB_680dc8ab;
    }
    if ((*(int *)(unaff_EDI + 0x44) != *(int *)(unaff_EDI + 0x48)) &&
       (local_10 = *(int *)(unaff_EDI + 0x44),
       iVar2 = Ordinal_1165(*(undefined4 *)(unaff_ESI + 0x3c),&local_8,&local_10,playback_initSpriteRender,0),
       iVar2 != 0)) {
      return 0;
    }
    iVar2 = Ordinal_1151(*(undefined4 *)(unaff_ESI + 0x3c),local_8,&local_10);
    if (iVar2 != 0) {
      return 0;
    }
  }
LAB_680dc8ab:
  lingo_formatDebugMsg(*(int **)(*(int *)(*(int *)(unaff_ESI + 0x20) + 4) + 8),-0x7a);
  return 0;
}



// ============================================================
// Function: playback_updateSpriteFrame (FUN_680dc8d0)
// Address: 680dc8d0
// Size: 109 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_updateSpriteFrame(int param_1,int param_2)
{
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = *(int *)(param_1 + 0x170);
  local_14 = *(undefined4 *)(param_1 + 0x174);
  local_10 = *(undefined4 *)(param_1 + 0x178);
  local_c = *(undefined4 *)(param_1 + 0x17c);
  if (*(int *)(param_1 + 0x124) == 0) {
    bitmap_updateMovieStage(*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x20) + 4) + 0xb4,&local_18,param_2);
  }
  return 0;
}



// ============================================================
// Function: playback_renderSpriteFrame (FUN_680dc940)
// Address: 680dc940
// Size: 71 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_renderSpriteFrame(int param_1,int param_2)
{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 0x4c);
  if (((uVar1 & 1) != 0) && ((uVar1 & 4) == 0)) {
    if ((uVar1 & 8) != 0) {
      rendering_addDirtySprite(*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x20) + 4) + 0x24,param_1);
      return 0;
    }
    if ((*(int *)(param_1 + 0x60) < 4) || (5 < *(int *)(param_1 + 0x60))) {
      playback_updateSpriteFrame(param_1,param_2);
    }
  }
  return 0;
}



// ============================================================
// Function: playback_getSpriteRef (FUN_680dc990)
// Address: 680dc990
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getSpriteRef(int param_1)
{
  if (((*(uint *)(param_1 + 0x4c) & 1) != 0) && ((*(uint *)(param_1 + 0x4c) & 0xc) == 0)) {
    playback_updateSpriteFrame(param_1,0);
  }
  return 0;
}



// ============================================================
// Function: playback_validateSpriteState (playback_validateSpriteState)
// Address: 680dc9b0
// Size: 53 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_validateSpriteState(void)
{
  int unaff_EBX;
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(unaff_EBX + 0x120);
  if (iVar1 <= *(int *)(unaff_EBX + 0x124)) {
    iVar2 = iVar1 * 400;
    do {
      playback_resetSpriteRegion(*(int *)(unaff_EBX + 0x34) + iVar2);
      iVar1 = iVar1 + 1;
      iVar2 = iVar2 + 400;
    } while (iVar1 <= *(int *)(unaff_EBX + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_resetSpriteRegion (playback_resetSpriteRegion)
// Address: 680dc9f0
// Size: 59 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resetSpriteRegion(int param_1)
{
  if (((*(uint *)(param_1 + 0x4c) & 1) != 0) && ((*(uint *)(param_1 + 0x4c) & 0xc) == 0)) {
    if (*(int *)(param_1 + 0x60) - 4U < 2) {
      playback_validateSpriteState();
      return 0;
    }
    playback_updateSpriteFrame(param_1,0);
  }
  return 0;
}



// ============================================================
// Function: playback_getSpriteDataRef (FUN_680dca30)
// Address: 680dca30
// Size: 24 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getSpriteDataRef(int param_1)
{
  if ((*(byte *)(param_1 + 0x4c) & 1) != 0) {
    playback_updateSpriteFrame(param_1,0);
  }
  return 0;
}



// ============================================================
// Function: playback_updateSpriteData (FUN_680dca50)
// Address: 680dca50
// Size: 175 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_updateSpriteData(int param_1,undefined4 *param_2)
{
  switch(param_2[0x18]) {
  case 1:
    display_clearDrawRef((int)param_2);
    break;
  case 2:
    rendering_updateDisplay();
    break;
  case 3:
    bitmap_teardownSpriteText(param_1,param_2);
    break;
  case 4:
    display_releaseSpriteChannel((int)param_2);
    break;
  case 5:
    display_detachSprite((int)param_2);
    break;
  case 6:
    display_clearVideoOverlay((int)param_2);
    break;
  case 8:
    rendering_updateDisplay();
    break;
  case 9:
    display_wrapGetSpriteBounds(param_1,param_2);
    break;
  case 10:
    bitmap_cleanupSpriteXtra();
  }
  param_2[0x18] = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x30) + param_2[0x10]) = 0;
  param_2[0x13] = param_2[0x13] & 0xfffffdfe;
  param_2[0x48] = 0;
  param_2[0x4a] = 0;
  Ordinal_1130(param_2 + 0x52,0x28);
  bitmap_markStageDirty(*(int *)(*(int *)(param_1 + 0x20) + 4) + 0xb4);
  playback_resolveSpriteChannel();
  return 0;
}



// ============================================================
// Function: playback_destroySpriteInstance (playback_destroySpriteInstance)
// Address: 680dcb30
// Size: 53 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_destroySpriteInstance(int param_1,undefined4 *param_2)
{
  if ((*(byte *)(param_2 + 0x13) & 1) != 0) {
    if (param_2[0x18] == 4) {
      playback_getLifecycleFlags((byte *)param_2[0x53]);
    }
    else if (param_2[0x18] == 5) {
      display_updateSpriteChannel(param_1,param_2);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_initSpriteInstance (playback_initSpriteInstance)
// Address: 680dcb70
// Size: 26 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_initSpriteInstance(int param_1,undefined4 *param_2)
{
  if (param_2[0x18] == 6) {
    display_updateVideoSprite(param_1,param_2);
  }
  return 0;
}



// ============================================================
// Function: playback_isSpriteChannelActive (playback_isSpriteChannelActive)
// Address: 680dcb90
// Size: 52 bytes
// Params: int param_1, undefined4 * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint playback_isSpriteChannelActive(int param_1,undefined4 *param_2)

{
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  
  uVar2 = 1;
  if (param_2[0x18] == 6) {
    uVar2 = display_isVideoReady(param_1,param_2);
  }
  else if (param_2[0x18] == 10) {
    bVar1 = bitmap_checkXtraAutoTab(param_1,(int)param_2);
    return CONCAT31(extraout_var,bVar1);
  }
  return uVar2;
}



// ============================================================
// Function: playback_createSpriteState (playback_createSpriteState)
// Address: 680dcbd0
// Size: 234 bytes
// Params: int param_1, undefined4 * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_createSpriteState(int param_1,undefined4 *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  
  piVar3 = param_3;
  if ((param_3 == (int *)0x0) || ((*(byte *)(param_2 + 0x14) & 2) != 0)) {
    return 1;
  }
  uVar1 = scoreEngine_readChannelBlock(*(int **)(param_1 + 0x20),param_3,0);
  if (uVar1 != 0) {
    if (param_2[0x18] == 1) {
      iVar2 = display_getLinkedCastRef((int)param_2,(int)piVar3,&param_3);
      if (((iVar2 != 0) &&
          (piVar4 = (int *)rendering_resolveState(*(int *)(param_1 + 0x18),param_3), piVar4 != (int *)0x0)) &&
         (uVar1 = scoreEngine_readChannelBlock(*(int **)(param_1 + 0x20),piVar4,0), uVar1 == 0)) {
        return 0;
      }
      iVar2 = rendering_getMemberPropertyState(piVar3,&param_3);
      if (iVar2 == 0) {
        return 1;
      }
      piVar3 = (int *)rendering_resolveState(*(int *)(param_1 + 0x18),param_3);
      if (piVar3 == (int *)0x0) {
        return 1;
      }
      piVar4 = *(int **)(param_1 + 0x20);
    }
    else {
      if (param_2[0x18] != 2) {
        return 1;
      }
      iVar2 = playback_releaseSpriteCallback(param_1,param_2);
      if (iVar2 == 0) {
        return 1;
      }
      piVar3 = (int *)rendering_resolveState(*(int *)(param_1 + 0x18),param_3);
      if (piVar3 == (int *)0x0) {
        return 1;
      }
      piVar4 = *(int **)(param_1 + 0x20);
    }
    uVar1 = scoreEngine_readChannelBlock(piVar4,piVar3,0);
    if (uVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_updateSpriteChannelData (playback_updateSpriteChannelData)
// Address: 680dccc0
// Size: 198 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_updateSpriteChannelData(int param_1,undefined4 param_2,int param_3)
{
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  uint local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if (*(char *)(*(int *)(param_1 + 0x20) + 0x4dd) != '\0') {
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_14 = 0;
    local_10 = 0;
    local_c = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_30 = 0;
    Ordinal_1602(param_2);
    Ordinal_1608(param_2,param_3 + 0x170);
    local_2c = 0;
    local_28 = (local_28 >> 8 & 0xffff) << 8;
    local_40 = 6;
    Ordinal_1623(param_2,0,param_3 + 200,0,2,&local_2c,&local_40);
    if ((*(byte *)(param_3 + 0x50) & 1) != 0) {
      Ordinal_1624(param_2,0,param_3 + 0x170,0);
    }
    Ordinal_1603(param_2);
  }
  return 0;
}



// ============================================================
// Function: playback_processSpriteChannelUpdate (playback_processSpriteChannelUpdate)
// Address: 680dcd90
// Size: 198 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_processSpriteChannelUpdate(int param_1,int param_2)

{
  int param_4;
  char cVar1;
  short sVar2;
  char cVar3;
  
  if (param_1 == 0x10) {
    if (param_2 == 0) {
      return 0;
    }
    switch(*(int *)(param_2 + 8)) {
    case 2:
      return 0x11;
    case 3:
      return 7;
    default:
      param_1 = *(int *)(param_2 + 8);
      break;
    case 7:
      sVar2 = *(short *)(param_2 + 0x80);
      if (sVar2 == 1) {
        return 8;
      }
      if (sVar2 == 2) {
        return 9;
      }
      if (sVar2 == 3) {
        return 10;
      }
      break;
    case 8:
      cVar1 = *(char *)(param_2 + 0x54);
      if (cVar1 == '\x04') {
        return (int)*(char *)(param_2 + 0x79);
      }
      cVar3 = cVar1 + '\x01';
      if (*(int *)(param_2 + 0x74) == 0) {
        cVar3 = cVar1 + '\v';
      }
      return (int)cVar3;
    case 9:
      return 0x12;
    case 10:
      return 0x13;
    case 0xd:
      return 0x16;
    case 0xf:
      return 0x15;
    }
  }
  return param_1;
}



// ============================================================
// Function: playback_resolveSpriteCastMember (playback_resolveSpriteCastMember)
// Address: 680dce90
// Size: 113 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_resolveSpriteCastMember(undefined4 param_1)

{
  switch(param_1) {
  case 1:
    return 1;
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    return 2;
  case 7:
  case 8:
  case 9:
  case 10:
    return 3;
  case 0xb:
    return 8;
  default:
    return 0;
  case 0x11:
    return 4;
  case 0x12:
    return 5;
  case 0x13:
    return 6;
  case 0x14:
    return 9;
  case 0x15:
    return 10;
  }
}



// ============================================================
// Function: playback_getSpriteState (FUN_680dcf50)
// Address: 680dcf50
// Size: 64 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getSpriteState(undefined4 *param_1)

{
  switch(param_1[0xc]) {
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    return 1;
  default:
    return *param_1;
  }
}



// ============================================================
// Function: playback_getSpriteData (playback_getSpriteData)
// Address: 680dcfb0
// Size: 105 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getSpriteData(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = param_2;
  if ((param_2[1] == 0) || (*(short *)(param_2[1] + 6) != *(short *)((int)param_2 + 2))) {
    switch(param_2[0xc]) {
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      param_2 = (undefined4 *)0x1;
      break;
    default:
      param_2 = (undefined4 *)*param_2;
    }
    if (0 < (short)((uint)param_2 >> 0x10)) {
      iVar2 = scoreEngine_setChannelField(*(uint *)(param_1 + 0x20),param_2);
      puVar1[1] = iVar2;
    }
  }
  return puVar1[1];
}



// ============================================================
// Function: playback_processSpriteVisibility (playback_processSpriteVisibility)
// Address: 680dd040
// Size: 82 bytes
// Params: int param_1, undefined4 * param_2
// Return: short
// Calling convention: __stdcall
// ============================================================

short playback_processSpriteVisibility(int param_1,undefined4 *param_2)

{
  int iVar1;
  short sVar2;
  
  sVar2 = 0;
  switch(param_2[0xc]) {
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    return *(short *)((int)param_2 + 2);
  case 0x10:
    iVar1 = playback_getSpriteData(param_1,param_2);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 8) == 8)) {
      sVar2 = (short)*(char *)(iVar1 + 0x68);
    }
  }
  return sVar2;
}



// ============================================================
// Function: playback_hitTestSprite (playback_hitTestSprite)
// Address: 680dd0b0
// Size: 547 bytes
// Params: int param_1, undefined4 * param_2, int param_3, int param_4, int * param_5, int * param_6, uint param_7
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint playback_hitTestSprite(int param_1,undefined4 *param_2,int param_3,int param_4,int *param_5,int *param_6,
                 uint param_7)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  uint local_8;
  
  uVar3 = 0;
  local_8 = 0;
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  uVar1 = param_2[0x16];
  if ((((uVar1 & 1) != 0) || (((param_2[0x14] & 4) != 0 && ((param_2[0x14] & 2) == 0)))) &&
     (local_8 = 1, (param_7 & 1) != 0)) {
    uVar3 = 1;
  }
  if ((((uVar1 & 2) != 0) || (((param_2[0x14] & 4) != 0 && ((param_2[0x14] & 2) == 0)))) &&
     (local_8 = local_8 | 2, (param_7 & 2) != 0)) {
    uVar3 = 1;
  }
  if (local_8 == 0) {
    local_8 = 0x10;
  }
  if ((param_7 & 0xffff7fff) == 0xff) {
    if ((param_7 & 0x8000) == 0) {
      uVar3 = 1;
    }
    else {
      uVar3 = ~((uint)param_2[0x14] >> 1) & 1;
    }
  }
  switch(param_2[0x18]) {
  case 1:
    if (uVar3 == 0) {
      return 0;
    }
    iVar4 = display_hitTestSprite(param_1,param_2,param_3,param_4);
    break;
  case 2:
    if (uVar3 == 0) {
      return 0;
    }
    iVar4 = display_getSpriteDrawRef(param_1,(int)param_2);
    break;
  case 3:
    if (uVar3 == 0) {
      return 0;
    }
    iVar4 = bitmap_drawScrollbarRect(param_1,(int)param_2);
    break;
  case 4:
  case 5:
    if (uVar3 == 0) {
      if (param_5 == (int *)0x0) {
        return 0;
      }
      if ((uVar1 & 0x100) == 0) {
        return 0;
      }
      local_8 = playback_getChannelCountEx(param_2[0x53],param_3,param_4,param_5,param_6,param_7);
      uVar3 = (uint)(local_8 != 0);
    }
    else {
      uVar3 = Ordinal_1070(param_2 + 0x32,&param_3);
    }
    if (uVar3 == 0) {
      return 0;
    }
    return local_8;
  case 6:
    if (uVar3 == 0) {
      return 0;
    }
    iVar4 = display_getSpriteDrawRef(param_1,(int)param_2);
    break;
  default:
    goto switchD_680dd150_caseD_7;
  case 8:
    if (uVar3 == 0) {
      return 0;
    }
    iVar4 = display_getSpriteDrawRef(param_1,(int)param_2);
    break;
  case 9:
    if (uVar3 == 0) {
      return 0;
    }
    iVar4 = display_getSpriteDrawRef(param_1,(int)param_2);
    break;
  case 10:
    if ((((param_7 & 1) == 0) || ((*(byte *)(param_2 + 0x54) & 2) == 0)) &&
       (((param_7 & 2) == 0 || ((*(byte *)(param_2 + 0x54) & 8) == 0)))) {
      bVar2 = false;
    }
    else {
      bVar2 = true;
    }
    if ((param_7 & 0x8000) != 0) {
      if ((bVar2) && ((*(byte *)(param_2 + 0x14) & 2) == 0)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
    }
    if ((uVar3 == 0) && (!bVar2)) {
      return 0;
    }
    iVar4 = bitmap_hitTestSpriteXtra(param_1,param_2,param_3,param_4);
  }
  if (iVar4 != 0) {
    return local_8;
  }
switchD_680dd150_caseD_7:
  return 0;
}



// ============================================================
// Function: playback_setSpriteChannelRef (playback_setSpriteChannelRef)
// Address: 680dd300
// Size: 44 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_setSpriteChannelRef(undefined4 param_1,int param_2,int param_3)
{
  if (param_3 != 0) {
    *(uint *)(param_2 + 0x50) = *(uint *)(param_2 + 0x50) | 1;
    playback_updateSpriteFrame(param_2,0);
    return 0;
  }
  *(uint *)(param_2 + 0x50) = *(uint *)(param_2 + 0x50) & 0xfffffffe;
  playback_updateSpriteFrame(param_2,0);
  return 0;
}



// ============================================================
// Function: playback_getSpriteChannelDataRef (playback_getSpriteChannelDataRef)
// Address: 680dd330
// Size: 45 bytes
// Params: int param_1
// Return: float10
// Calling convention: __fastcall
// ============================================================

float10 __fastcall playback_getSpriteChannelDataRef(int param_1)

{
  return (float10)(param_1 % 36000) / (float10)5729.5779513082325;
}



// ============================================================
// Function: playback_writeSpriteChannelState (playback_writeSpriteChannelState)
// Address: 680dd360
// Size: 232 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall playback_writeSpriteChannelState(void *this,int param_1)
{
  double dVar1;
  double *unaff_ESI;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 extraout_ST1;
  
  fVar2 = playback_getSpriteChannelDataRef((int)this);
  fVar3 = playback_getSpriteChannelDataRef(param_1);
  fVar4 = (float10)Ordinal_1528((double)extraout_ST1);
  fVar2 = (float10)Ordinal_1527((double)fVar2);
  fVar5 = (float10)Ordinal_1528((double)(fVar3 + extraout_ST1));
  fVar3 = (float10)Ordinal_1527((double)(fVar3 + extraout_ST1));
  dVar1 = *unaff_ESI;
  fVar2 = (float10)(double)fVar2;
  fVar5 = (float10)(double)fVar5;
  *unaff_ESI = (double)((float10)dVar1 * fVar2 - (float10)unaff_ESI[1] * fVar5);
  fVar4 = (float10)(double)fVar4;
  unaff_ESI[1] = (double)((float10)unaff_ESI[1] * fVar3 + (float10)dVar1 * fVar4);
  dVar1 = unaff_ESI[2];
  unaff_ESI[2] = (double)((float10)dVar1 * fVar2 - (float10)unaff_ESI[3] * fVar5);
  unaff_ESI[3] = (double)((float10)dVar1 * fVar4 + (float10)unaff_ESI[3] * fVar3);
  dVar1 = unaff_ESI[4];
  unaff_ESI[4] = (double)((float10)dVar1 * fVar2 - (float10)unaff_ESI[5] * fVar5);
  unaff_ESI[5] = (double)((float10)dVar1 * fVar4 + (float10)unaff_ESI[5] * fVar3);
  dVar1 = unaff_ESI[6];
  unaff_ESI[6] = (double)((float10)dVar1 * fVar2 - (float10)unaff_ESI[7] * fVar5);
  unaff_ESI[7] = (double)((float10)dVar1 * fVar4 + (float10)unaff_ESI[7] * fVar3);
  return 0;
}



// ============================================================
// Function: playback_readSpriteChannelState (playback_readSpriteChannelState)
// Address: 680dd450
// Size: 69 bytes
// Params: void * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_readSpriteChannelState(void *param_1,int param_2)
{
  Ordinal_1083();
  playback_writeSpriteChannelState(param_1,param_2);
  Ordinal_1083();
  return 0;
}



// ============================================================
// Function: playback_renderSpriteLayer (FUN_680dd4a0)
// Address: 680dd4a0
// Size: 113 bytes
// Params: int param_1, int param_2
// Return: byte
// Calling convention: __stdcall
// ============================================================

byte playback_renderSpriteLayer(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  byte bVar3;
  
  bVar3 = 0;
  if (param_2 != 0) {
    iVar2 = *(int *)(param_2 + 8);
    if ((iVar2 == 1) || (iVar2 == 0xd)) {
      bVar3 = 0x3f;
    }
    else {
      if (iVar2 != 0xf) {
        return 0x20;
      }
      if (param_1 != 0) {
        uVar1 = *(ushort *)(param_1 + 0x14c);
        bVar3 = (uVar1 & 4) != 0;
        if ((uVar1 & 8) != 0) {
          bVar3 = bVar3 | 2;
        }
        if ((uVar1 & 0x10) != 0) {
          bVar3 = bVar3 | 4;
        }
        if ((uVar1 & 0x20) != 0) {
          bVar3 = bVar3 | 8;
        }
        if ((uVar1 & 0x40) != 0) {
          bVar3 = bVar3 | 0x10;
        }
        if ((char)uVar1 < '\0') {
          return bVar3 | 0x20;
        }
      }
    }
  }
  return bVar3;
}



// ============================================================
// Function: playback_processSpriteScript (playback_processSpriteScript)
// Address: 680dd520
// Size: 35 bytes
// Params: void * this, int param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall playback_processSpriteScript(void *this,int param_1,int param_2)
{
  double *in_EAX;
  
  *in_EAX = (double)(*(int *)this + param_1);
  in_EAX[1] = (double)(*(int *)((int)this + 4) + param_2);
  return 0;
}



// ============================================================
// Function: playback_renderSprite (FUN_680dd550)
// Address: 680dd550
// Size: 1371 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_renderSprite(int param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  byte bVar3;
  undefined4 uVar4;
  int extraout_EDX;
  int iVar5;
  void *pvVar6;
  undefined4 *puVar7;
  int iVar8;
  undefined4 *puVar9;
  float10 fVar10;
  int local_80;
  uint local_7c;
  float local_78;
  int local_74;
  int local_70;
  int local_6c;
  uint local_68;
  float local_64;
  float local_60;
  uint local_5c;
  int local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  uint *local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  uint local_30;
  float local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar5 = 0;
  local_78 = 0.0;
  local_74 = 1;
  local_80 = 0;
  bVar3 = playback_renderSpriteLayer(param_1,param_2);
  if (extraout_EDX != 0) {
    local_80 = *(int *)(extraout_EDX + 8);
  }
  switch(local_80) {
  case 1:
  case 0xd:
    iVar8 = *(int *)(extraout_EDX + 0x6c) - *(int *)(extraout_EDX + 100);
    iVar5 = *(int *)(extraout_EDX + 0x70) - *(int *)(extraout_EDX + 0x68);
    if ((*(uint *)(extraout_EDX + 0x9c) >> 5 & 1) == 0) {
      local_5c = *(uint *)(extraout_EDX + 0x88);
      local_60 = *(float *)(extraout_EDX + 0x8c);
    }
    else {
      local_5c = iVar8 / 2;
      local_60 = (float)(iVar5 / 2);
    }
    break;
  case 2:
  case 9:
    if (param_3 == 0) {
      local_74 = 0;
    }
    iVar8 = *(int *)(extraout_EDX + 0x60) - *(int *)(extraout_EDX + 0x58);
    iVar5 = *(int *)(extraout_EDX + 100) - *(int *)(extraout_EDX + 0x5c);
    local_5c = iVar8 / 2;
    local_60 = (float)(iVar5 / 2);
    break;
  case 3:
  case 7:
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & 0xff7f;
    iVar8 = *(int *)(extraout_EDX + 0x70);
    iVar5 = *(int *)(extraout_EDX + 0x74);
    local_60 = 0.0;
    local_5c = 0;
    break;
  default:
    local_60 = 0.0;
    local_5c = 0;
    iVar8 = 0;
    break;
  case 5:
    Ordinal_1716(*(undefined4 *)(extraout_EDX + 0x54),&local_18);
    iVar8 = local_10 - local_18;
    iVar5 = local_c - local_14;
    local_60 = 0.0;
    local_5c = 0;
    break;
  case 8:
    iVar8 = *(int *)(param_1 + 0x20);
    iVar5 = *(int *)(param_1 + 0x24);
    local_60 = 0.0;
    local_5c = 0;
    break;
  case 10:
    iVar8 = *(int *)(extraout_EDX + 0x5c) - *(int *)(extraout_EDX + 0x54);
    iVar5 = *(int *)(extraout_EDX + 0x60) - *(int *)(extraout_EDX + 0x58);
    local_5c = iVar8 / 2;
    local_60 = (float)(iVar5 / 2);
    break;
  case 0xc:
    *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & 0xff7f;
    iVar8 = *(int *)(extraout_EDX + 0x5c) - *(int *)(extraout_EDX + 0x54);
    iVar5 = *(int *)(extraout_EDX + 0x80);
    local_60 = 0.0;
    local_5c = 0;
    break;
  case 0xf:
    local_54 = *(undefined4 *)(param_1 + 0x3c);
    local_44 = 0;
    local_40 = 0;
    local_3c = 0;
    local_38 = 0;
    local_34 = 0;
    local_2c = 0.0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_48 = &local_30;
    local_30 = 0;
    local_50 = 0x19;
    local_4c = 5;
    rendering_initState(&local_58);
    iVar8 = local_28 - local_30;
    iVar5 = local_24 - (int)local_2c;
    local_4c = 0x3c;
    rendering_initState(&local_58);
    local_5c = local_30;
    local_60 = local_2c;
    local_4c = 0x36;
    rendering_initState(&local_58);
    if ((local_30 & 0x200) != 0) {
      *(ushort *)(param_1 + 0xc) = *(ushort *)(param_1 + 0xc) & 0xff7f;
    }
  }
  local_6c = *(int *)(param_1 + 0x20);
  local_68 = *(uint *)(param_1 + 0x18);
  local_64 = *(float *)(param_1 + 0x1c);
  local_70 = *(int *)(param_1 + 0x24);
  *(uint *)(param_1 + 0x68) = local_5c;
  *(float *)(param_1 + 0x6c) = local_60;
  iVar1 = iVar5;
  iVar2 = iVar8;
  if (((*(byte *)(param_1 + 0xc) & 0x80) != 0) && ((local_6c != iVar8 || (local_70 != iVar5)))) {
    local_7c = local_5c;
    local_78 = local_60;
    if (iVar8 == 0) {
      iVar8 = 1;
    }
    if (iVar5 == 0) {
      iVar5 = 1;
    }
    Ordinal_1060(&local_28,0,0,iVar8,iVar5);
    Ordinal_1060(&local_18,0,0,local_6c,local_70);
    Ordinal_1072(&local_7c,&local_28,&local_18);
    local_5c = local_7c;
    local_60 = local_78;
    local_78 = 1.4013e-45;
    iVar1 = local_70;
    iVar2 = local_6c;
  }
  local_6c = iVar2;
  local_70 = iVar1;
  *(int *)(param_1 + 0x28) = local_6c;
  *(int *)(param_1 + 0x2c) = local_70;
  Ordinal_1060(param_1 + 0x78,local_68,local_64,local_68 + iVar8,(int)local_64 + iVar5);
  if ((*(uint *)(param_1 + 0x4c) & 0x200) == 0) {
    iVar5 = param_1 + 200;
    Ordinal_1060(iVar5,local_68 - local_5c,(int)local_64 - (int)local_60,
                 local_6c + (local_68 - local_5c),local_70 + ((int)local_64 - (int)local_60));
    if (local_74 != 0) {
      playback_setLifecycleData(*(int *)(param_1 + 0x3c),iVar5);
    }
    Ordinal_1080(param_1 + 0xd8,iVar5);
    *(undefined4 *)(param_1 + 0x118) = 1;
    if (((*(uint *)(param_1 + 0x4c) & 0x200) == 0) && ((bVar3 & 3) != 0)) {
      pvVar6 = (void *)0x0;
      iVar5 = 0;
      if ((bVar3 & 1) != 0) {
        pvVar6 = *(void **)(param_1 + 0x34);
      }
      if ((bVar3 & 2) != 0) {
        iVar5 = *(int *)(param_1 + 0x38);
      }
      if ((*(byte *)(param_1 + 0x16) & 0x20) != 0) {
        pvVar6 = (void *)((int)pvVar6 + 18000);
        iVar5 = iVar5 + 18000;
      }
      if ((*(byte *)(param_1 + 0x16) & 0x40) != 0) {
        iVar5 = iVar5 + 18000;
      }
      if ((pvVar6 != (void *)(((int)pvVar6 / 36000) * 36000)) || (iVar5 != (iVar5 / 36000) * 36000))
      {
        local_68 = local_5c;
        local_64 = local_60;
        playback_scaleLifecycleCoords(*(int *)(param_1 + 0x3c),(int *)&local_68,(int *)&local_64);
        playback_processSpriteScript((void *)(param_1 + 200),local_68,(int)local_64);
        playback_readSpriteChannelState(pvVar6,iVar5);
        *(undefined4 *)(param_1 + 0x118) = 0;
      }
    }
  }
  if ((*(uint *)(param_1 + 0x4c) & 0x200) != 0) {
    *(undefined4 *)(param_1 + 0x118) = 0;
    puVar7 = (undefined4 *)(param_1 + 0x88);
    puVar9 = (undefined4 *)(param_1 + 0xd8);
    for (iVar5 = 0x10; iVar5 != 0; iVar5 = iVar5 + -1) {
      *puVar9 = *puVar7;
      puVar7 = puVar7 + 1;
      puVar9 = puVar9 + 1;
    }
    if (local_74 != 0) {
      playback_applyLifecycleIntersect(*(int *)(param_1 + 0x3c),(undefined4 *)(param_1 + 0xd8));
    }
  }
  if (((bVar3 & 0x20) != 0) && (*(int *)(param_1 + 0x118) == 0)) {
    Ordinal_1082(param_1 + 0xd8,param_1 + 200);
  }
  if ((local_80 == 3) || (local_80 == 7)) {
    bitmap_computeTextLayout(param_1,param_2);
  }
  *(undefined4 *)(param_1 + 0x170) = *(undefined4 *)(param_1 + 200);
  *(undefined4 *)(param_1 + 0x174) = *(undefined4 *)(param_1 + 0xcc);
  *(undefined4 *)(param_1 + 0x178) = *(undefined4 *)(param_1 + 0xd0);
  *(undefined4 *)(param_1 + 0x17c) = *(undefined4 *)(param_1 + 0xd4);
  if (*(int *)(param_1 + 0x180) != 0) {
    fVar10 = rendering_renderStageFrame(*(int *)(param_1 + 0x3c));
    local_2c = (float)fVar10;
    local_20 = *(int *)(param_1 + 0xd4);
    local_28 = *(int *)(param_1 + 0xcc);
    local_24 = *(int *)(param_1 + 200);
    local_1c = *(int *)(param_1 + 0xd0);
    uVar4 = events_computeSpriteTransform(*(int *)(*(int *)(*(int *)(param_1 + 0x3c) + 0x20) + 8),
                         *(int **)(param_1 + 0x180),local_2c,local_28,local_24,local_20,local_1c,
                         (int)&local_2c);
    *(undefined4 *)(param_1 + 0x188) = uVar4;
    *(int *)(param_1 + 0x170) = local_24;
    *(int *)(param_1 + 0x174) = local_28;
    *(int *)(param_1 + 0x178) = local_1c;
    *(int *)(param_1 + 0x17c) = local_20;
  }
  return 0;
}



// ============================================================
// Function: playback_notifySpriteEvent (playback_notifySpriteEvent)
// Address: 680ddaf0
// Size: 86 bytes
// Params: double * param_1
// Return: float10
// Calling convention: __fastcall
// ============================================================

float10 __fastcall playback_notifySpriteEvent(double *param_1)

{
  double dVar1;
  double dVar2;
  double *in_EAX;
  double *unaff_ESI;
  float10 fVar3;
  float10 fVar4;
  
  dVar1 = *in_EAX - *param_1;
  dVar2 = in_EAX[1] - param_1[1];
  fVar3 = (float10)Ordinal_1531(dVar2,dVar1);
  fVar3 = fVar3 * (float10)57.29577951308232;
  if (unaff_ESI != (double *)0x0) {
    fVar4 = (float10)Ordinal_1522(dVar1 * dVar1 + dVar2 * dVar2);
    *unaff_ESI = (double)fVar4;
    fVar3 = (float10)(double)fVar3;
  }
  return fVar3;
}



// ============================================================
// Function: playback_handleSpriteMouseEvent (playback_handleSpriteMouseEvent)
// Address: 680ddb50
// Size: 76 bytes
// Params: double param_1, double param_2
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 playback_handleSpriteMouseEvent(double param_1,double param_2)

{
  double dVar1;
  
  dVar1 = (param_1 - param_2) / 360.0;
  if (0.0 <= dVar1) {
    param_1 = dVar1 + 0.5;
  }
  else {
    param_1 = dVar1 - 0.5;
  }
  Ordinal_1521(param_1,&param_1);
  return (float10)param_1 * (float10)360.0 + (float10)param_2;
}



// ============================================================
// Function: playback_dispatchSpriteEvent (playback_dispatchSpriteEvent)
// Address: 680ddba0
// Size: 1602 bytes
// Params: undefined4 param_1, int param_2, int param_3, int * param_4, int * param_5, int * param_6, int * param_7, int * param_8, double * param_9, double * param_10, int * param_11, int * param_12
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_dispatchSpriteEvent(undefined4 param_1,int param_2,int param_3,int *param_4,int *param_5,int *param_6,
                 int *param_7,int *param_8,double *param_9,double *param_10,int *param_11,
                 int *param_12)
{
  int iVar1;
  double *pdVar2;
  double *pdVar3;
  byte bVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  float10 fVar8;
  float10 fVar9;
  float10 extraout_ST0;
  float10 fVar10;
  ulonglong uVar11;
  int local_134;
  int local_130;
  int *local_12c;
  int *local_128;
  int *local_124;
  int *local_120;
  double local_11c;
  undefined8 local_114;
  int iStack_108;
  int local_104;
  double *local_100;
  double *local_fc;
  int local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  undefined8 local_e8;
  int local_e0;
  int local_dc;
  int local_d8;
  int local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  double local_c8;
  double local_c0;
  double local_b8;
  double local_b0;
  double local_a8;
  double local_a0;
  double local_98;
  double local_90;
  int local_88;
  int local_84;
  int local_80;
  int local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  int local_6c;
  double local_68;
  double local_60;
  double local_58;
  undefined8 local_50;
  undefined8 local_48;
  double local_40;
  double local_38;
  double local_30;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_f4 = param_1;
  local_128 = param_5;
  local_12c = param_7;
  local_124 = param_6;
  local_120 = param_8;
  local_1c = param_4[3] - param_4[1];
  local_100 = param_10;
  iVar5 = param_4[2] - *param_4;
  local_fc = param_9;
  iStack_108 = param_4[1];
  local_e8 = (double)CONCAT44(*param_4,(undefined4)local_e8);
  local_104 = param_4[3] - iStack_108;
  local_88 = *param_4;
  local_7c = param_4[3];
  local_80 = param_4[2];
  local_20 = local_80 - *param_4;
  local_114 = (double)CONCAT44(iVar5,(undefined4)local_114);
  local_28 = 0;
  local_24 = 0;
  iVar7 = local_ec;
  local_84 = iStack_108;
  if (param_3 != 0) {
    local_10 = local_20;
    local_c = local_1c;
    switch(*(undefined4 *)(param_3 + 8)) {
    case 1:
    case 0xd:
      local_10 = *(int *)(param_3 + 0x6c);
      local_18 = *(int *)(param_3 + 100);
      local_14 = *(int *)(param_3 + 0x68);
      local_c = *(int *)(param_3 + 0x70);
      if ((*(uint *)(param_3 + 0x9c) >> 5 & 1) == 0) {
        local_f0 = *(int *)(param_3 + 0x88);
        iVar7 = *(int *)(param_3 + 0x8c);
      }
      else {
        local_f0 = (*(int *)(param_3 + 0x6c) - *(int *)(param_3 + 100)) / 2;
        iVar7 = (*(int *)(param_3 + 0x70) - *(int *)(param_3 + 0x68)) / 2;
      }
      break;
    case 2:
    case 9:
    case 10:
      local_f0 = iVar5 / 2;
      local_18 = 0;
      local_14 = 0;
      iVar7 = local_104 / 2;
      break;
    default:
      local_18 = 0;
      local_14 = 0;
      local_f0 = 0;
      iVar7 = 0;
      break;
    case 0xf:
      local_38 = 0.0;
      local_30 = 0.0;
      local_e0 = 0;
      local_dc = 0;
      local_d8 = 0;
      local_d4 = 0;
      local_d0 = 0;
      local_cc = 0;
      local_50 = (double)CONCAT44(param_1,param_3);
      local_48 = 1.0609978967178e-313;
      local_40 = (double)ZEXT48(&local_e0);
      rendering_initState((int *)&local_50);
      local_14 = local_dc;
      local_18 = local_e0;
      local_10 = local_d8;
      local_c = local_d4;
      local_48 = (double)CONCAT44(0x3c,(undefined4)local_48);
      rendering_initState((int *)&local_50);
      local_f0 = local_e0;
      iVar7 = local_dc;
    }
  }
  iVar6 = local_10 - local_18;
  local_6c = local_c - local_14;
  local_78 = 0;
  local_74 = 0;
  local_134 = local_f0;
  local_130 = iVar7;
  local_70 = iVar6;
  Ordinal_1072(&local_134,&local_78,&local_28);
  local_f4 = local_130 + iStack_108;
  bVar4 = playback_renderSpriteLayer(param_2,param_3);
  iVar5 = extraout_EDX;
  if (((bVar4 & 1) != 0) &&
     ((((*local_fc != 0.0 || (*local_100 != 0.0)) || (*param_11 != 0)) ||
      (iVar5 = extraout_EDX, *param_12 != 0)))) {
    iVar1 = *local_12c;
    local_e8 = (double)CONCAT44(iVar1,(undefined4)local_e8);
    iVar5 = extraout_EDX;
    if ((iVar1 != 0) && (iStack_108 = *local_120, iVar5 = extraout_EDX, iStack_108 != 0)) {
      local_f8 = *local_128;
      local_f4 = *local_124;
      iVar5 = local_f0;
      if (*param_11 != 0) {
        iVar5 = iVar6 - local_f0;
      }
      if (*param_12 != 0) {
        iVar7 = (local_c - local_14) - iVar7;
      }
      if (local_10 <= local_18) {
        iVar6 = 1;
      }
      iVar5 = local_f8 - (iVar5 * iVar1) / iVar6;
      if (local_14 < local_c) {
        iVar6 = local_c - local_14;
      }
      else {
        iVar6 = 1;
      }
      iVar7 = local_f4 - (iVar7 * iStack_108) / iVar6;
      Ordinal_1060(&local_18,iVar5,iVar7,iVar5 + iVar1,iVar7 + iStack_108);
      Ordinal_1080(&local_c8,&local_18);
      local_11c = (double)local_f8;
      local_114 = (double)local_f4;
      uVar11 = strings_floatToUint64(extraout_ECX,extraout_EDX_00);
      iVar7 = (int)uVar11;
      uVar11 = strings_floatToUint64(local_fc,(int)(uVar11 >> 0x20));
      playback_readSpriteChannelState((void *)(size_t)uVar11,iVar7);
      Ordinal_1082(&local_c8,&local_18);
      if (local_18 < local_10) {
        (*(unsigned int *)((char *)&local_e8 + 4)) = local_10 - local_18;
      }
      else {
        (*(unsigned int *)((char *)&local_e8 + 4)) = 1;
      }
      local_38 = (double)(param_4[2] - *param_4) / (double)(*(unsigned int *)((char *)&local_e8 + 4));
      if (local_14 < local_c) {
        (*(unsigned int *)((char *)&local_e8 + 4)) = local_c - local_14;
      }
      else {
        (*(unsigned int *)((char *)&local_e8 + 4)) = 1;
      }
      local_114 = (double)CONCAT44(param_4[3] - param_4[1],(undefined4)local_114);
      local_30 = (double)(param_4[3] - param_4[1]) / (double)(*(unsigned int *)((char *)&local_e8 + 4));
      local_68 = local_c8 * local_38;
      local_60 = local_c0 * local_30;
      local_58 = local_b8 * local_38;
      local_50 = local_b0 * local_30;
      local_48 = local_a8 * local_38;
      local_40 = local_a0 * local_30;
      local_38 = local_98 * local_38;
      local_30 = local_30 * local_90;
      fVar8 = playback_notifySpriteEvent(&local_38);
      local_e8 = (double)fVar8;
      fVar8 = playback_notifySpriteEvent(&local_38);
      fVar9 = (float10)local_e8;
      uVar11 = strings_floatToUint64(extraout_ECX_00,extraout_EDX_01);
      local_114 = (double)CONCAT44((int)uVar11,(undefined4)local_114);
      uVar11 = strings_floatToUint64(extraout_ECX_01,(int)(uVar11 >> 0x20));
      pdVar3 = local_fc;
      local_104 = (int)uVar11;
      fVar10 = playback_handleSpriteMouseEvent(*local_fc,(double)extraout_ST0);
      pdVar2 = local_100;
      local_e8 = (double)fVar10;
      fVar8 = playback_handleSpriteMouseEvent(*local_100,(double)((float10)90.0 - (fVar9 - fVar8)));
      *pdVar3 = local_e8;
      local_f0 = local_f8;
      *pdVar2 = (double)fVar8;
      local_ec = local_f4;
      Ordinal_1072();
      local_f4 = local_ec;
      iVar5 = local_f0;
    }
  }
  *local_128 = iVar5;
  *local_124 = local_f4;
  *local_12c = (*(unsigned int *)((char *)&local_114 + 4));
  *local_120 = local_104;
  return 0;
}



// ============================================================
// Function: playback_getSpriteRegionRef (playback_getSpriteRegionRef)
// Address: 680de210
// Size: 36 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getSpriteRegionRef(void)
{
  int param_4;
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  iVar1 = *(int *)(in_EAX + 0x3c);
  puVar3 = (undefined4 *)(in_EAX + 0x88);
  puVar4 = (undefined4 *)(in_EAX + 0xd8);
  for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  playback_applyLifecycleIntersect(iVar1,(undefined4 *)(in_EAX + 0xd8));
  return 0;
}



// ============================================================
// Function: playback_initSpriteRectState (playback_initSpriteRectState)
// Address: 680de240
// Size: 64 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_initSpriteRectState(int param_1,int param_2,undefined4 *param_3)
{
  byte bVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if ((param_2 != 0) && (bVar1 = playback_renderSpriteLayer(param_1,param_2), (bVar1 & 0x10) != 0)) {
    puVar3 = (undefined4 *)(param_1 + 0x88);
    for (iVar2 = 0x10; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar3 = *param_3;
      param_3 = param_3 + 1;
      puVar3 = puVar3 + 1;
    }
    playback_getSpriteRegionRef();
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x600;
  }
  return 0;
}



// ============================================================
// Function: playback_clearSpriteRectState (playback_clearSpriteRectState)
// Address: 680de280
// Size: 63 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_clearSpriteRectState(int param_1,int param_2,int param_3)
{
  if ((*(uint *)(param_1 + 0x4c) & 0x200) != 0) {
    Ordinal_1083(param_1 + 0x88,(double)param_2,(double)param_3);
    playback_getSpriteRegionRef();
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x400;
  }
  return 0;
}



// ============================================================
// Function: playback_updateSpriteRectRegion (playback_updateSpriteRectRegion)
// Address: 680de2c0
// Size: 71 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_updateSpriteRectRegion(int param_1)

{
  if ((*(int *)(param_1 + 0x80) - *(int *)(param_1 + 0x78) ==
       *(int *)(param_1 + 0xd0) - *(int *)(param_1 + 200)) &&
     (*(int *)(param_1 + 0x84) - *(int *)(param_1 + 0x7c) ==
      *(int *)(param_1 + 0xd4) - *(int *)(param_1 + 0xcc))) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: playback_invalidateSpriteRect (playback_invalidateSpriteRect)
// Address: 680de310
// Size: 31 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_invalidateSpriteRect(int param_1)
{
  if (*(int *)(param_1 + 0x60) == 10) {
    bitmap_handleSpriteIdle(param_1);
  }
  return 0;
}



// ============================================================
// Function: playback_getSpriteBounds (FUN_680de330)
// Address: 680de330
// Size: 48 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getSpriteBounds(int param_1,undefined4 *param_2)
{
  int iVar1;
  
  iVar1 = playback_getSpriteData(param_1,param_2);
  if (iVar1 != 0) {
    Ordinal_1872(param_2 + 0x57);
    param_2[0x58] = 0;
  }
  return 0;
}



// ============================================================
// Function: playback_checkSpriteSound (playback_checkSpriteSound)
// Address: 680de360
// Size: 35 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_checkSpriteSound(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  iVar1 = 1;
  if (*(int *)(param_2 + 0x60) == 10) {
    iVar1 = bitmap_invokeXtraScript(param_1,param_2,param_3);
  }
  return iVar1;
}



// ============================================================
// Function: playback_querySpriteInkProperty (playback_querySpriteInkProperty)
// Address: 680de390
// Size: 106 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_querySpriteInkProperty(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar2 = param_1;
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x120), iVar1 <= *(int *)(param_1 + 0x124))) {
    iVar3 = iVar1 * 400;
    param_1 = iVar1;
    do {
      puVar4 = (undefined4 *)(*(int *)(iVar2 + 0x34) + iVar3);
      puVar4[1] = 0;
      playback_getSpriteData(iVar2,puVar4);
      if (puVar4[0x18] - 4 < 2) {
        playback_querySpriteInkProperty(puVar4[0x53]);
      }
      param_1 = param_1 + 1;
      iVar3 = iVar3 + 400;
    } while (param_1 <= *(int *)(iVar2 + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_processSpriteInkBlend (playback_processSpriteInkBlend)
// Address: 680de400
// Size: 1289 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_processSpriteInkBlend(int param_1,int param_2)
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  undefined4 *unaff_ESI;
  undefined4 local_c;
  ushort local_8;
  
  local_8 = *(ushort *)(unaff_ESI + 3) & 0x3f;
  bVar2 = false;
  uVar8 = 0;
  bVar4 = false;
  bVar3 = false;
  if ((unaff_ESI[0x20] - unaff_ESI[0x1e] != unaff_ESI[0x34] - unaff_ESI[0x32]) ||
     (unaff_ESI[0x21] - unaff_ESI[0x1f] != unaff_ESI[0x35] - unaff_ESI[0x33])) {
    bVar2 = true;
    bVar3 = true;
  }
  if ((param_2 != 0) && (!bVar2)) {
    bVar4 = true;
  }
  if ((*(byte *)((int)unaff_ESI + 0x15) & 0x10) == 0) {
    *(undefined1 *)(unaff_ESI + 0x50) = *(undefined1 *)((int)unaff_ESI + 0xf);
    *(undefined1 *)((int)unaff_ESI + 0x143) = 0;
  }
  else {
    *(undefined1 *)(unaff_ESI + 0x50) = *(undefined1 *)((int)unaff_ESI + 0xf);
    *(undefined1 *)((int)unaff_ESI + 0x141) = *(undefined1 *)(unaff_ESI + 4);
    *(undefined1 *)((int)unaff_ESI + 0x142) = *(undefined1 *)((int)unaff_ESI + 0x11);
    *(undefined1 *)((int)unaff_ESI + 0x143) = 1;
  }
  if ((*(byte *)((int)unaff_ESI + 0x15) & 0x20) == 0) {
    *(undefined1 *)(unaff_ESI + 0x51) = *(undefined1 *)((int)unaff_ESI + 0x12);
    *(undefined1 *)((int)unaff_ESI + 0x147) = 0;
  }
  else {
    *(undefined1 *)(unaff_ESI + 0x51) = *(undefined1 *)((int)unaff_ESI + 0x12);
    *(undefined1 *)((int)unaff_ESI + 0x145) = *(undefined1 *)((int)unaff_ESI + 0x13);
    *(undefined1 *)((int)unaff_ESI + 0x146) = *(undefined1 *)(unaff_ESI + 5);
    *(undefined1 *)((int)unaff_ESI + 0x147) = 1;
  }
  if (unaff_ESI[0x18] == 2) {
    if (local_8 == 0x20) {
      uVar7 = (uint)((ulonglong)((0xff - (uint)*(byte *)((int)unaff_ESI + 0xe)) * 0x100) *
                     0x80808081 >> 0x20);
LAB_680de531:
      uVar7 = uVar7 >> 7;
    }
    else {
      uVar7 = 0x100;
    }
  }
  else {
    if (((*(byte *)((int)unaff_ESI + 0x16) & 0x10) != 0) || (local_8 == 0x20)) {
      uVar7 = (uint)((ulonglong)((0xff - (uint)*(byte *)((int)unaff_ESI + 0xe)) * 0x100) *
                     0x80808081 >> 0x20);
      goto LAB_680de531;
    }
    uVar7 = 0x100;
  }
  unaff_ESI[0x4c] = uVar7;
  switch(local_8) {
  case 0:
    unaff_ESI[0x4b] = 0;
    break;
  case 1:
    unaff_ESI[0x4b] = 4;
    break;
  case 2:
    unaff_ESI[0x4b] = 6;
    break;
  case 3:
    unaff_ESI[0x4b] = 8;
    break;
  case 4:
    if (bVar4) {
      uVar8 = 0x20;
    }
    unaff_ESI[0x4b] = 1;
    break;
  case 5:
    if (bVar4) {
      uVar8 = 0x20;
    }
    unaff_ESI[0x4b] = 5;
    break;
  case 6:
    if (bVar4) {
      uVar8 = 0x20;
    }
    unaff_ESI[0x4b] = 7;
    break;
  case 7:
    if (bVar4) {
      uVar8 = 0x20;
    }
    unaff_ESI[0x4b] = 9;
    break;
  default:
switchD_680de54e_caseD_8:
    unaff_ESI[0x4b] = 0;
    goto LAB_680de7db;
  case 9:
    uVar5 = playback_getSpriteState(unaff_ESI);
    local_c = CONCAT22((short)((uint)uVar5 >> 0x10) + 1,(short)uVar5);
    iVar6 = scoreEngine_setChannelField(*(uint *)(param_1 + 0x20),local_c);
    if (unaff_ESI[0x18] == 3) {
      if (unaff_ESI[0x4c] != 0x100) goto LAB_680de6c9;
      unaff_ESI[0x4b] = 2;
      unaff_ESI[0x4d] = unaff_ESI[0x51];
    }
    else {
      if ((iVar6 == 0) ||
         (((*(int *)(iVar6 + 8) != 1 && (*(int *)(iVar6 + 8) != 0xd)) ||
          (*(int *)(iVar6 + 0x60) != 1)))) goto switchD_680de54e_caseD_8;
      uVar8 = 0x10;
      unaff_ESI[0x4b] = 0;
    }
    break;
  case 0x20:
    if (bVar4) {
      uVar8 = 0x20;
    }
LAB_680de6c9:
    unaff_ESI[0x4b] = 10;
    break;
  case 0x21:
    if (bVar4) {
      uVar8 = 0x20;
    }
    unaff_ESI[0x4b] = 0x12;
    break;
  case 0x22:
    if (bVar4) {
      uVar8 = 0x20;
    }
    unaff_ESI[0x4b] = 0xe;
    break;
  case 0x23:
    if (bVar4) {
      uVar8 = 0x20;
    }
    unaff_ESI[0x4b] = 0x14;
    break;
  case 0x24:
    unaff_ESI[0x4b] = 2;
    if ((param_2 == 0) || (unaff_ESI[0x18] == 2)) {
      unaff_ESI[0x4d] = 0x1ffffff;
    }
    else {
      unaff_ESI[0x4d] = unaff_ESI[0x51];
    }
    if ((param_2 != 0) && (unaff_ESI[0x18] == 1)) {
      unaff_ESI[0x50] = 0x1000000;
    }
    break;
  case 0x25:
    if (bVar4) {
      uVar8 = 0x20;
    }
    unaff_ESI[0x4b] = 0x18;
    break;
  case 0x26:
    if (bVar4) {
      uVar8 = 0x20;
    }
    unaff_ESI[0x4b] = 0x10;
    break;
  case 0x27:
    if (bVar4) {
      uVar8 = 0x20;
    }
    unaff_ESI[0x4b] = 0x16;
    break;
  case 0x28:
    unaff_ESI[0x4b] = 0x1a;
    unaff_ESI[0x4e] = unaff_ESI[0x51];
    unaff_ESI[0x4f] = unaff_ESI[0x50];
    unaff_ESI[0x50] = 0x1000000;
    unaff_ESI[0x51] = 0x1ffffff;
    goto LAB_680de7db;
  case 0x29:
    unaff_ESI[0x4b] = 0x1c;
    unaff_ESI[0x4e] = unaff_ESI[0x51];
    unaff_ESI[0x4f] = unaff_ESI[0x50];
    unaff_ESI[0x50] = 0x1000000;
    unaff_ESI[0x51] = 0x1ffffff;
LAB_680de7db:
    uVar8 = 0x20;
  }
  iVar6 = unaff_ESI[0x4b];
  if (((iVar6 == 10) || (0xff < (uint)unaff_ESI[0x4c])) ||
     ((local_8 == 9 || ((param_2 == 0 && (iVar6 == 2)))))) goto LAB_680de83a;
  if (bVar3) {
    uVar8 = uVar8 & 0xffffffdf;
  }
  else {
    if (param_2 == 0) goto LAB_680de83a;
    if (iVar6 == 2) {
      unaff_ESI[0x4b] = 0xc;
      uVar8 = uVar8 & 0xffffffdf;
      goto LAB_680de83a;
    }
    uVar8 = uVar8 | 0x20;
  }
  unaff_ESI[0x4b] = 10;
LAB_680de83a:
  iVar6 = unaff_ESI[0x18];
  if ((((iVar6 != 2) && (local_8 == 0)) && (bVar4)) &&
     (((*(byte *)((int)unaff_ESI + 0x16) & 0x10) != 0 && (unaff_ESI[0x4c] == 0x100)))) {
    unaff_ESI[0x4b] = 10;
    uVar8 = uVar8 | 0x20;
    unaff_ESI[0x50] = 0x1000000;
    unaff_ESI[0x51] = 0x1ffffff;
  }
  iVar1 = unaff_ESI[0x4b];
  if ((iVar1 == 10) || (iVar1 == 0xc)) {
    if (param_2 == 0) {
      unaff_ESI[0x50] = 0x1000000;
      unaff_ESI[0x51] = 0x1ffffff;
    }
    unaff_ESI[0x4d] = 0x1ffffff;
  }
  if (((iVar1 == 0) && (uVar8 == 0)) && (unaff_ESI[0x46] != 0)) {
    uVar8 = 1;
  }
  if ((iVar1 == 10) || (iVar1 == 0xc)) {
    if (iVar6 != 2) {
      unaff_ESI[0x17] = uVar8;
      if (iVar6 == 10) {
        return 0;
      }
      unaff_ESI[0x50] = 0x1000000;
      unaff_ESI[0x51] = 0x1ffffff;
      return 0;
    }
    unaff_ESI[0x51] = 0x1ffffff;
  }
  unaff_ESI[0x17] = uVar8;
  return 0;
}



// ============================================================
// Function: playback_renderSpriteData (FUN_680de990)
// Address: 680de990
// Size: 872 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_renderSpriteData(int param_1,undefined4 *param_2,int param_3)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  ushort uVar4;
  uint uVar5;
  uint uVar6;
  
  puVar1 = param_2;
  if ((*(byte *)(*(int *)(param_1 + 0x20) + 0x49c) & 1) != 0) {
    playback_processSpriteInkBlend(param_1,param_3);
    return 0;
  }
  uVar4 = *(ushort *)(param_2 + 3) & 0x3f;
  uVar6 = 0;
  if ((*(byte *)((int)param_2 + 0x15) & 0x10) == 0) {
    *(undefined1 *)(param_2 + 0x50) = *(undefined1 *)((int)param_2 + 0xf);
    *(undefined1 *)((int)param_2 + 0x143) = 0;
  }
  else {
    *(undefined1 *)(param_2 + 0x50) = *(undefined1 *)((int)param_2 + 0xf);
    *(undefined1 *)((int)param_2 + 0x141) = *(undefined1 *)(param_2 + 4);
    *(undefined1 *)((int)param_2 + 0x142) = *(undefined1 *)((int)param_2 + 0x11);
    *(undefined1 *)((int)param_2 + 0x143) = 1;
  }
  if ((*(byte *)((int)param_2 + 0x15) & 0x20) == 0) {
    *(undefined1 *)(param_2 + 0x51) = *(undefined1 *)((int)param_2 + 0x12);
    *(undefined1 *)((int)param_2 + 0x147) = 0;
  }
  else {
    *(undefined1 *)(param_2 + 0x51) = *(undefined1 *)((int)param_2 + 0x12);
    *(undefined1 *)((int)param_2 + 0x145) = *(undefined1 *)((int)param_2 + 0x13);
    *(undefined1 *)((int)param_2 + 0x146) = *(undefined1 *)(param_2 + 5);
    *(undefined1 *)((int)param_2 + 0x147) = 1;
  }
  if (((*(byte *)((int)param_2 + 0x16) & 0x10) == 0) && (uVar4 != 0x20)) {
    uVar5 = 0x100;
  }
  else {
    uVar5 = ((0xff - (uint)*(byte *)((int)param_2 + 0xe)) * 0x100) / 0xff;
  }
  param_2[0x4c] = uVar5;
  switch(uVar4) {
  case 0:
    param_2[0x4b] = 0;
    goto LAB_680dec82;
  case 1:
    param_2[0x4b] = 4;
    goto LAB_680dec82;
  case 2:
    param_2[0x4b] = 6;
    goto LAB_680dec82;
  case 3:
    param_2[0x4b] = 8;
    goto LAB_680dec82;
  case 4:
    param_2[0x4b] = 1;
    break;
  case 5:
    param_2[0x4b] = 5;
    break;
  case 6:
    param_2[0x4b] = 7;
    break;
  case 7:
    param_2[0x4b] = 9;
    break;
  default:
    goto switchD_680dea87_caseD_8;
  case 9:
    uVar2 = playback_getSpriteState(param_2);
    param_2 = (undefined4 *)CONCAT22((short)((uint)uVar2 >> 0x10) + 1,(short)uVar2);
    iVar3 = scoreEngine_setChannelField(*(uint *)(param_1 + 0x20),param_2);
    if (puVar1[0x18] == 3) {
      if (puVar1[0x4c] == 0x100) {
        puVar1[0x4b] = 2;
        puVar1[0x4d] = puVar1[0x51];
      }
      else {
        puVar1[0x4b] = 10;
      }
      goto LAB_680dec82;
    }
    if ((iVar3 != 0) && ((*(int *)(iVar3 + 8) == 1 || (*(int *)(iVar3 + 8) == 0xd)))) {
      switch(*(undefined4 *)(iVar3 + 0x60)) {
      case 1:
      case 2:
      case 4:
      case 8:
      case 0x20:
        uVar6 = 0x10;
        puVar1[0x4b] = 0;
        goto LAB_680dec82;
      }
    }
    goto switchD_680dea87_caseD_8;
  case 0x20:
    param_2[0x4b] = 10;
    break;
  case 0x21:
    param_2[0x4b] = 0x12;
    break;
  case 0x22:
    param_2[0x4b] = 0xe;
    break;
  case 0x23:
    param_2[0x4b] = 0x14;
    break;
  case 0x24:
    param_2[0x4b] = 2;
    if ((param_3 == 0) || (param_2[0x18] == 2)) {
      param_2[0x4d] = 0x1ffffff;
    }
    else {
      param_2[0x4d] = param_2[0x51];
    }
    goto LAB_680dec82;
  case 0x25:
    param_2[0x4b] = 0x18;
    break;
  case 0x26:
    param_2[0x4b] = 0x10;
    break;
  case 0x27:
    param_2[0x4b] = 0x16;
    break;
  case 0x28:
    param_2[0x4b] = 0x1a;
    goto LAB_680dec3d;
  case 0x29:
    param_2[0x4b] = 0x1c;
LAB_680dec3d:
    param_2[0x4e] = param_2[0x51];
    param_2[0x4f] = param_2[0x50];
    param_2[0x50] = 0x1000000;
    param_2[0x51] = 0x1ffffff;
  }
LAB_680dec7d:
  uVar6 = 0x20;
LAB_680dec82:
  iVar3 = puVar1[0x4b];
  if (((iVar3 != 10) && ((uint)puVar1[0x4c] < 0x100)) && ((param_3 != 0 || (iVar3 != 2)))) {
    if (iVar3 == 2) {
      puVar1[0x4b] = 0xc;
      uVar6 = uVar6 & 0xffffffdf;
    }
    else {
      puVar1[0x4b] = 10;
      if (uVar4 != 0) {
        uVar6 = uVar6 | 0x20;
      }
    }
  }
  if ((uVar6 & 0x10) != 0) {
    uVar6 = uVar6 & 0xffffffdf;
  }
  if (((puVar1[0x4b] == 0) && (uVar6 == 0)) && (puVar1[0x46] != 0)) {
    uVar6 = 1;
  }
  puVar1[0x17] = uVar6;
  return 0;
switchD_680dea87_caseD_8:
  puVar1[0x4b] = 0;
  goto LAB_680dec7d;
}



// ============================================================
// Function: playback_getSpriteRenderData (FUN_680deda0)
// Address: 680deda0
// Size: 83 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getSpriteRenderData(int param_1,int param_2)
{
  int iVar1;
  
  if (*(int *)(param_2 + 0x184) != 0) {
    Ordinal_1653(param_2 + 0x184);
  }
  if ((*(int **)(param_2 + 0x180) != (int *)0x0) &&
     (iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 8), iVar1 != 0)) {
    events_updateMovieNav(iVar1,*(int **)(param_2 + 0x180));
    *(undefined4 *)(param_2 + 0x180) = 0;
    *(undefined4 *)(param_2 + 0x188) = 0;
  }
  return 0;
}



// ============================================================
// Function: playback_getSpriteProperty (FUN_680dee00)
// Address: 680dee00
// Size: 137 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getSpriteProperty(int param_1,undefined4 *param_2)
{
  int iVar1;
  int local_30 [11];
  
  if (param_2[0xc] == 0x10) {
    local_30[0] = 0;
    local_30[1] = 0;
    local_30[2] = 0;
    local_30[3] = 0;
    local_30[4] = 0;
    local_30[5] = 0;
    local_30[6] = 0;
    local_30[7] = 0;
    local_30[8] = 0;
    local_30[9] = 0;
    local_30[0] = playback_getSpriteData(param_1,param_2);
    local_30[2] = 0xf;
    if ((local_30[0] != 0) && (iVar1 = rendering_initState(local_30), iVar1 != 0)) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_renderSpriteToBuffer (playback_renderSpriteToBuffer)
// Address: 680dee90
// Size: 572 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_renderSpriteToBuffer(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined1 local_28 [16];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar3 = playback_getSpriteProperty(param_1,param_2);
  iVar4 = playback_getSpriteProperty(param_1,param_3);
  if ((iVar3 == 0) || (iVar4 == 0)) {
    return 0;
  }
  bVar1 = true;
  if ((iVar3 != 1) || (bVar2 = true, (*(byte *)(param_2 + 3) & 0x3f) != 8)) {
    bVar2 = false;
  }
  if ((iVar4 != 1) || ((*(byte *)(param_3 + 3) & 0x3f) != 8)) {
    bVar1 = false;
  }
  if ((param_2[0x46] != 0) && (param_3[0x46] != 0)) {
    if (!bVar1) {
      Ordinal_1069(param_3 + 0x32,param_2 + 0x32);
      return 0;
    }
    iVar3 = display_drawSprite(param_1,param_3,(int *)0x0);
    if (bVar2) {
      iVar4 = display_drawSprite(param_1,param_2,(int *)0x0);
      Ordinal_1674(iVar3,iVar4,param_3 + 0x1e,param_2 + 0x1e,param_3 + 0x32,param_2 + 0x32);
      return 0;
    }
    local_18 = param_2[0x32];
    local_14 = param_2[0x33];
    local_10 = param_2[0x34];
    local_c = param_2[0x35];
    Ordinal_1071(&local_18,param_3 + 0x32,param_3 + 0x1e);
    iVar4 = local_18 - param_3[0x1e];
    Ordinal_1060(local_28,iVar4,local_14 - param_3[0x1f],(local_10 - local_18) + iVar4,
                 (local_c - local_14) + (local_14 - param_3[0x1f]));
    Ordinal_1676(iVar3,local_28);
    return 0;
  }
  if (!bVar1) {
    Ordinal_1086(param_3 + 0x36,param_2 + 0x36);
    return 0;
  }
  iVar3 = display_drawSprite(param_1,param_3,(int *)0x0);
  if (bVar2) {
    iVar4 = display_drawSprite(param_1,param_2,(int *)0x0);
    Ordinal_1682(iVar3,iVar4,param_3 + 0x36,param_2 + 0x36);
    return 0;
  }
  Ordinal_1681(iVar3,param_3 + 0x36,param_2 + 0x36);
  return 0;
}



// ============================================================
// Function: playback_composeSpriteLayer (playback_composeSpriteLayer)
// Address: 680df0d0
// Size: 544 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_composeSpriteLayer(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  bool bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int local_38;
  int local_2c;
  undefined1 local_28 [16];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_2c = param_1;
  local_38 = playback_getSpriteProperty(param_1,param_2);
  iVar3 = playback_getSpriteProperty(param_1,param_3);
  if ((local_38 != 0) && (iVar3 != 0)) {
    if ((local_38 != 1) || (bVar1 = true, (*(byte *)(param_2 + 3) & 0x3f) != 8)) {
      bVar1 = false;
    }
    if ((iVar3 != 1) || (bVar2 = true, (*(byte *)(param_3 + 3) & 0x3f) != 8)) {
      bVar2 = false;
    }
    if ((bVar1) && (local_38 = display_drawSprite(param_1,param_2,(int *)0x0), local_38 == 0)) {
      bVar1 = false;
    }
    if ((bVar2) && (local_2c = display_drawSprite(param_1,param_3,(int *)0x0), local_2c == 0)) {
      bVar2 = false;
    }
    if ((param_2[0x46] == 0) || (param_3[0x46] == 0)) {
      puVar4 = param_2 + 0x36;
      puVar5 = param_3 + 0x36;
      iVar3 = Ordinal_1088(puVar5,puVar4);
      if ((iVar3 != 0) && (bVar2)) {
        if (bVar1) {
          Ordinal_1680(local_38,local_2c,puVar4,puVar5);
        }
        else {
          Ordinal_1679(local_2c,puVar5,puVar4);
        }
      }
    }
    else if (bVar2) {
      if (bVar1) {
        Ordinal_1673(local_38,local_2c,param_2 + 0x1e,param_3 + 0x1e,param_2 + 0x32,param_3 + 0x32);
      }
      else {
        local_18 = param_2[0x32];
        local_14 = param_2[0x33];
        local_10 = param_2[0x34];
        local_c = param_2[0x35];
        Ordinal_1071(&local_18,param_3 + 0x32,param_3 + 0x1e);
        iVar3 = local_18 - param_3[0x1e];
        Ordinal_1060(local_28,iVar3,local_14 - param_3[0x1f],(local_10 - local_18) + iVar3,
                     (local_c - local_14) + (local_14 - param_3[0x1f]));
        Ordinal_1675(local_2c,local_28);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: playback_blendSpriteLayer (playback_blendSpriteLayer)
// Address: 680df2f0
// Size: 192 bytes
// Params: int param_1, int param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_blendSpriteLayer(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  
  if ((param_1 == 0) || (iVar4 = *(int *)(param_1 + 0x120), *(int *)(param_1 + 0x124) < iVar4)) {
    return -1;
  }
  iVar1 = iVar4 * 400;
  do {
    puVar5 = (undefined4 *)(*(int *)(param_1 + 0x34) + iVar1);
    uVar2 = playback_getSpriteProperty(param_1,puVar5);
    switch(uVar2) {
    case 7:
    case 0x14:
      if (puVar5[0x57] == param_2) {
LAB_680df350:
        if (param_3 == (int *)0x0) {
          return iVar4;
        }
        *param_3 = param_1;
        return iVar4;
      }
      break;
    case 0x11:
    case 0x12:
      iVar3 = playback_blendSpriteLayer(puVar5[0x53],param_2,param_3);
      if (iVar3 != -1) {
        return iVar3;
      }
      break;
    case 0x15:
      iVar3 = bitmap_checkXtraPropertyMatch(param_1,(int)puVar5,param_2);
      if (iVar3 != 0) goto LAB_680df350;
    }
    iVar1 = iVar1 + 400;
    iVar4 = iVar4 + 1;
    if (*(int *)(param_1 + 0x124) < iVar4) {
      return -1;
    }
  } while( true );
}



// ============================================================
// Function: playback_paintSpriteToStage (playback_paintSpriteToStage)
// Address: 680df3e0
// Size: 72 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_paintSpriteToStage(int param_1,undefined4 *param_2)
{
  uint uVar1;
  int iVar2;
  
  if (param_1 != 0) {
    uVar1 = *(uint *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 0x28);
    iVar2 = playback_getSpriteProperty(param_1,param_2);
    if (iVar2 == 7) {
      bitmap_updateSpriteScroll(param_1,param_2,uVar1);
    }
    else if (iVar2 == 0x14) {
      display_updateSpriteSound(param_1,param_2,uVar1);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_getSpriteInfo (FUN_680df430)
// Address: 680df430
// Size: 219 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getSpriteInfo(int param_1,undefined4 *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_2[0x62] != 0) {
    iVar1 = playback_getSpriteProperty(param_1,param_2);
    iVar2 = playback_getSpriteData(param_1,param_2);
    if ((iVar1 != 0x15) ||
       (((iVar2 != 0 && ((*(uint *)(iVar2 + 0x60) & 0x10000) != 0)) &&
        ((*(ushort *)(param_2 + 0x53) & 0x8000) == 0)))) {
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      iVar1 = Ordinal_1606(*(undefined4 *)(*(int *)(param_1 + 0x24) + 0x94),&local_34);
      if ((iVar1 != 0) && (local_20 == 0x20)) {
        return 0;
      }
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_getSpriteInfoEx (FUN_680df510)
// Address: 680df510
// Size: 497 bytes
// Params: int param_1, undefined4 * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getSpriteInfoEx(int param_1,undefined4 *param_2,uint param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint local_8;
  
  local_8 = 0;
  piVar2 = (int *)playback_getSpriteData(param_1,param_2);
  if ((piVar2 == (int *)0x0) || ((piVar2[0xb] & 0x4000U) == 0)) {
    iVar3 = playback_getSpriteProperty(param_1,param_2);
    if ((iVar3 != 0) && ((param_2[0x18] == 0 || ((param_3 & 0x102) != 0)))) {
      playback_computeSpriteTransform();
    }
    param_2[0x13] = param_2[0x13] & 0xa65;
    param_2[0x14] = param_2[0x14] & 7;
    if ((param_3 & 2) != 0) {
      param_2[0x14] = param_2[0x14] & 0xfffffffe;
    }
    if ((param_3 & 0x30000) != 0) {
      param_2[0x13] = param_2[0x13] | 0x2000;
    }
    if ((param_3 & 0x200000) != 0) {
      playback_getSpriteRenderData(param_1,(int)param_2);
    }
    if (((param_2[0x60] == 0) && (*(int *)(param_1 + 0x20) != 0)) &&
       (iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 8), iVar1 != 0)) {
      uVar4 = events_loadSpriteScripts(iVar1,param_1,(undefined4 *)0x0,param_2[2]);
      param_2[0x60] = uVar4;
      param_2[0x62] = 0;
    }
    switch(iVar3) {
    case 1:
      iVar3 = display_drawBitmapMember(param_1,param_2);
      break;
    case 2:
    case 3:
    case 4:
    case 5:
    case 6:
    case 0xc:
    case 0xd:
    case 0xe:
    case 0xf:
      iVar3 = playback_buildSpriteCallbackParams(param_1,param_2);
      break;
    case 7:
    case 8:
    case 9:
    case 10:
      iVar3 = bitmap_setupSpriteText(param_1,param_2,param_3);
      break;
    case 0xb:
      iVar3 = display_drawShapeSprite(param_1,param_2);
      break;
    default:
      goto switchD_680df5e5_caseD_10;
    case 0x11:
      iVar3 = display_drawBitmapSprite(param_1,param_2,param_3);
      break;
    case 0x12:
      iVar3 = display_drawFilmLoopSprite(param_1,param_2,param_3);
      break;
    case 0x13:
      iVar3 = display_setupVideoSprite(param_1,param_2,param_3);
      break;
    case 0x14:
      iVar3 = display_setupFlashSprite(param_1,param_2,param_3);
      break;
    case 0x15:
      iVar3 = bitmap_initSpriteXtra(param_1,param_2,(byte)param_3);
    }
    if (iVar3 != 0) {
switchD_680df5e5_caseD_10:
      events_querySpriteCapability(*(int *)(*(int *)(param_2[0xf] + 0x20) + 8),(int *)param_2[0x60],&local_8);
      if ((local_8 & 1) != 0) {
        param_2[0x17] = param_2[0x17] | 0x40;
      }
      goto LAB_680df623;
    }
  }
  *(undefined1 *)(*(int *)(param_1 + 0x30) + param_2[0x10]) = *(undefined1 *)(param_2 + 0x18);
  playback_updateSpriteData(param_1,param_2);
LAB_680df623:
  *(undefined1 *)(*(int *)(param_1 + 0x30) + param_2[0x10]) = *(undefined1 *)(param_2 + 0x18);
  iVar3 = playback_createSpriteState(param_1,param_2,piVar2);
  if (iVar3 == 0) {
    param_2[0x13] = param_2[0x13] & 0xfffffeff;
    if ((piVar2 != (int *)0x0) && (iVar3 = rendering_getFrameCount((int)piVar2), iVar3 != 0)) {
      rendering_compositeMedia(*(int **)(param_1 + 0x20),piVar2,1);
    }
  }
  else {
    param_2[0x13] = param_2[0x13] | 0x100;
  }
  bitmap_markStageDirty(*(int *)(*(int *)(param_1 + 0x20) + 4) + 0xb4);
  return 0;
}



// ============================================================
// Function: playback_teardownSpriteState (playback_teardownSpriteState)
// Address: 680df750
// Size: 171 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_teardownSpriteState(int param_1,undefined4 *param_2)
{
  int local_18;
  switch(param_2[0x18]) {
  case 3:
    if (*(int *)(*(int *)(*(int *)(param_2[0xf] + 0x20) + 4) + 0x28) != 0) {
      playback_getSpriteBounds(param_1,param_2);
      if ((*(byte *)(param_2 + 0x14) & 2) == 0) {
        param_2[0x13] = param_2[0x13] | 0x40;
      }
      playback_paintSpriteToStage(param_1,param_2);
      return 0;
    }
    playback_getSpriteBounds(param_1,param_2);
switchD_680df767_default:
    return 0;
  case 4:
  case 5:
  case 7:
  case 8:
    goto switchD_680df767_default;
  case 6:
    display_refreshVideoSprite(param_1,param_2);
    return 0;
  case 9:
  case 10:
    if (*(int *)(*(int *)(*(int *)(param_2[0xf] + 0x20) + 4) + 0x28) != 0) {
      bitmap_setSpriteProperty(param_1,(int)param_2,0x14);
      bitmap_setSpriteProperty(param_1,(int)param_2,0x22);
      return 0;
    }
    playback_updateSpriteData(param_1,param_2);
    return 0;
  default:
    return 0;
  }
}



// ============================================================
// Function: playback_processChannelScript (playback_processChannelScript)
// Address: 680df820
// Size: 56 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_processChannelScript(int param_1,undefined4 *param_2,int param_3)
{
  int iVar1;
  
  iVar1 = param_2[0x18];
  if (iVar1 != 3) {
    if (iVar1 == 6) {
      display_syncVideoPlayback(param_1,param_2,param_3);
      return 0;
    }
    if (iVar1 != 9) {
      return 0;
    }
  }
  playback_paintSpriteToStage(param_1,param_2);
  return 0;
}



// ============================================================
// Function: playback_handleSpriteCallback (playback_handleSpriteCallback)
// Address: 680df860
// Size: 98 bytes
// Params: int param_1, undefined4 * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_handleSpriteCallback(int param_1,undefined4 *param_2,uint param_3)
{
  if (((param_3 & 0x80000) == 0) || ((*(byte *)(param_2 + 0x13) & 8) == 0)) {
    playback_getSpriteRef((int)param_2);
  }
  else {
    playback_getSpriteDataRef((int)param_2);
  }
  if ((param_3 & 0x8000) != 0) {
    playback_updateSpriteData(param_1,param_2);
  }
  if (-1 < (int)param_3) {
    playback_getSpriteInfoEx(param_1,param_2,param_3);
    playback_renderSpriteFrame((int)param_2,0);
  }
  if (param_2[0x18] == 10) {
    bitmap_handleModifierKey((int)param_2,param_3);
  }
  return 0;
}



// ============================================================
// Function: playback_dispatchSpriteCallback (playback_dispatchSpriteCallback)
// Address: 680df8d0
// Size: 86 bytes
// Params: int param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_dispatchSpriteCallback(int param_1,int param_2,uint param_3)
{
  undefined4 *puVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x120);
    if (iVar2 <= *(int *)(param_1 + 0x124)) {
      puVar1 = (undefined4 *)(iVar2 * 400 + *(int *)(param_1 + 0x34));
      while (puVar1[2] != param_2) {
        iVar2 = iVar2 + 1;
        puVar1 = puVar1 + 100;
        if (*(int *)(param_1 + 0x124) < iVar2) {
          return 0;
        }
      }
      playback_handleSpriteCallback(param_1,puVar1,param_3);
    }
  }
  return 0;
}



// ============================================================
// Function: playback_renderSpriteAt (FUN_680df930)
// Address: 680df930
// Size: 237 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_renderSpriteAt(int param_1,int param_2,uint param_3)
{
  bool bVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  short extraout_var;
  undefined4 *puVar5;
  int local_8;
  
  if ((param_1 != 0) && (local_8 = *(int *)(param_1 + 0x120), local_8 <= *(int *)(param_1 + 0x124)))
  {
    iVar3 = local_8 * 400;
    do {
      puVar5 = (undefined4 *)(*(int *)(param_1 + 0x34) + iVar3);
      bVar1 = false;
      uVar4 = playback_getSpriteState(puVar5);
      sVar2 = scoreEngine_getChannelData(*(int *)(param_1 + 0x20),(short)uVar4);
      if (((((param_3 & 0x80000000) == 0) && (puVar5[0x18] == 1)) &&
          ((*(byte *)(puVar5 + 3) & 0x3f) == 9)) && (param_2 == CONCAT22(extraout_var + 1,sVar2))) {
        bVar1 = true;
      }
      if ((param_2 == CONCAT22(extraout_var,sVar2)) || (bVar1)) {
        playback_handleSpriteCallback(param_1,puVar5,param_3);
      }
      if (puVar5[0x18] - 4 < 2) {
        playback_renderSpriteAt(puVar5[0x53],param_2,param_3);
      }
      iVar3 = iVar3 + 400;
      local_8 = local_8 + 1;
    } while (local_8 <= *(int *)(param_1 + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_renderSpriteBlock (FUN_680dfa20)
// Address: 680dfa20
// Size: 59 bytes
// Params: int param_1, int param_2, byte param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_renderSpriteBlock(int param_1,int param_2,byte param_3)
{
  uint uVar1;
  
  uVar1 = 0;
  if ((param_3 & 2) != 0) {
    uVar1 = 0x20000;
  }
  if ((param_3 & 1) != 0) {
    uVar1 = uVar1 | 0x10000;
  }
  if ((param_3 & 0x10) != 0) {
    uVar1 = 0x30000;
  }
  playback_renderSpriteAt(param_1,*(undefined4 *)(param_2 + 4),uVar1);
  return 0;
}



// ============================================================
// Function: playback_processSpriteCallback (playback_processSpriteCallback)
// Address: 680dfa60
// Size: 136 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_processSpriteCallback(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  
  iVar2 = param_1;
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x120), iVar1 <= *(int *)(param_1 + 0x124))) {
    iVar4 = iVar1 * 400;
    param_1 = iVar1;
    do {
      puVar5 = (undefined4 *)(*(int *)(iVar2 + 0x34) + iVar4);
      uVar3 = playback_getSpriteState(puVar5);
      if ((short)uVar3 == (short)param_2) {
        playback_getSpriteRef((int)puVar5);
        playback_updateSpriteData(iVar2,puVar5);
        playback_getSpriteInfoEx(iVar2,puVar5,0x30004);
        playback_renderSpriteFrame((int)puVar5,0);
      }
      if (puVar5[0x18] == 4) {
        playback_processSpriteCallback(puVar5[0x53],param_2);
      }
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 400;
    } while (param_1 <= *(int *)(iVar2 + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_checkSpriteCallbackEvent (playback_checkSpriteCallbackEvent)
// Address: 680dfaf0
// Size: 124 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_checkSpriteCallbackEvent(void)
{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  undefined1 *unaff_ESI;
  short unaff_DI;
  
  if (((0 < unaff_DI) || (unaff_DI < 0x39)) &&
     (iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(unaff_EBX + 4) + 8) + 4) + 0x60), iVar2 != 0)) {
    iVar2 = Ordinal_1512(iVar2);
    if (iVar2 != 0) {
      iVar1 = iVar2 + -8 + unaff_DI * 8;
      *unaff_ESI = *(undefined1 *)(iVar2 + -8 + unaff_DI * 8);
      unaff_ESI[1] = *(undefined1 *)(iVar1 + 1);
      unaff_ESI[2] = *(undefined1 *)(iVar1 + 2);
      unaff_ESI[3] = *(undefined1 *)(iVar1 + 3);
      unaff_ESI[4] = *(undefined1 *)(iVar1 + 4);
      unaff_ESI[5] = *(undefined1 *)(iVar1 + 5);
      unaff_ESI[6] = *(undefined1 *)(iVar1 + 6);
      unaff_ESI[7] = *(undefined1 *)(iVar1 + 7);
      if (iVar1 != -8) {
        Ordinal_1513(*(undefined4 *)(*(int *)(*(int *)(*(int *)(unaff_EBX + 4) + 8) + 4) + 0x60));
      }
    }
  }
  return 0;
}



// ============================================================
// Function: playback_verifySpriteCallbackTarget (playback_verifySpriteCallbackTarget)
// Address: 680dfb70
// Size: 43 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_verifySpriteCallbackTarget(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  default:
    return 0;
  case 3:
  case 0xd:
    return 1;
  case 4:
  case 0xe:
    return 2;
  case 5:
  case 6:
  case 0xf:
    return 3;
  }
}



// ============================================================
// Function: playback_buildSpriteCallbackParams (playback_buildSpriteCallbackParams)
// Address: 680dfbc0
// Size: 62 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_buildSpriteCallbackParams(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = playback_getSpriteData(param_1,param_2);
  param_2[0x18] = 2;
  playback_renderSprite((int)param_2,iVar1,0);
  playback_renderSpriteData(param_1,param_2,1);
  param_2[0x17] = param_2[0x17] & 0xfffffffe;
  param_2[0x13] = param_2[0x13] | 3;
  return 1;
}



// ============================================================
// Function: playback_executeSpriteCallback (playback_executeSpriteCallback)
// Address: 680dfc00
// Size: 61 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_executeSpriteCallback(void)

{
  short in_AX;
  short sVar1;
  undefined4 *puVar2;
  undefined2 extraout_var;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (0x38 < in_AX) {
    puVar2 = (undefined4 *)scoreEngine_getSoundChannel(*(int *)(unaff_ESI + 0x20),(int)(short)(in_AX + -0x39));
    if ((puVar2 != (undefined4 *)0x0) && (*(short *)((int)puVar2 + 2) != 0)) {
      sVar1 = scoreEngine_getChannelData(*(int *)(unaff_ESI + 0x20),(short)*puVar2);
      *unaff_EDI = CONCAT22(extraout_var,sVar1);
      if (*(short *)((int)unaff_EDI + 2) != 0) {
        return 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: playback_releaseSpriteCallback (playback_releaseSpriteCallback)
// Address: 680dfc40
// Size: 32 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_releaseSpriteCallback(int param_1,undefined4 *param_2)
{
  playback_processSpriteVisibility(param_1,param_2);
  playback_executeSpriteCallback();
  return 0;
}



// ============================================================
// Function: playback_initSpriteCallbackState (playback_initSpriteCallbackState)
// Address: 680dfc60
// Size: 36 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_initSpriteCallbackState(void)
{
  int *unaff_ESI;
  
  if (*unaff_ESI < 0) {
    Ordinal_1064();
  }
  if (unaff_ESI[1] < 0) {
    Ordinal_1064();
  }
  return 0;
}



// ============================================================
// Function: playback_registerSpriteCallback (playback_registerSpriteCallback)
// Address: 680dfc90
// Size: 234 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_registerSpriteCallback(undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int unaff_ESI;
  undefined1 local_18 [3];
  undefined1 uStack_15;
  undefined2 uStack_14;
  undefined1 uStack_13;
  undefined2 local_12;
  undefined1 uStack_11;
  undefined4 local_c;
  undefined4 local_8;
  
  puVar1 = (undefined4 *)(unaff_ESI + 0x144);
  puVar2 = (undefined4 *)(unaff_ESI + 0x140);
  iVar3 = Ordinal_1079(puVar2,puVar1);
  if (iVar3 != 0) {
    return 1;
  }
  if (*(char *)(unaff_ESI + 0x143) != *(char *)(unaff_ESI + 0x147)) {
    local_c = Ordinal_1610(param_1);
    if (*(char *)(unaff_ESI + 0x143) == '\x01') {
      local_8 = *puVar2;
    }
    else {
      Ordinal_1736(local_c,*(undefined1 *)puVar2,local_18,1);
      local_8 = CONCAT13(1,CONCAT12(uStack_11,CONCAT11(uStack_13,uStack_15)));
    }
    if (*(char *)(unaff_ESI + 0x147) == '\x01') {
      param_1 = *puVar1;
    }
    else {
      Ordinal_1736(local_c,*(undefined1 *)puVar1,local_18,1);
      param_1 = CONCAT13(1,CONCAT12(uStack_11,CONCAT11(uStack_13,uStack_15)));
    }
    iVar3 = Ordinal_1079(&local_8,&param_1);
    if (iVar3 != 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_unregisterSpriteCallback (playback_unregisterSpriteCallback)
// Address: 680dfd80
// Size: 743 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4, short param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_unregisterSpriteCallback(undefined4 param_1,int param_2,int param_3,int param_4,short param_5)
{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int extraout_EDX;
  undefined4 local_8c;
  int *local_70;
  
  local_70 = (int *)0x0;
  iVar4 = Ordinal_1602(param_1);
  Ordinal_1608(param_1,param_2 + 200);
  bVar1 = *(byte *)(param_2 + 0x16);
  if (param_5 == 0) {
    if (param_4 == 2) {
      param_4 = 0xc;
    }
    else if (param_4 == 3) {
      param_4 = 0xd;
    }
    else if (param_4 == 4) {
      param_4 = 0xe;
    }
    param_5 = 1;
  }
  if (((*(int *)(param_2 + 300) == 2) && (iVar5 = playback_registerSpriteCallback(param_1), iVar5 != 0)) ||
     (((iVar5 = *(int *)(param_2 + 300), iVar5 == 7 || ((iVar5 == 9 || (iVar5 == 5)))) &&
      (param_5 == 1)))) goto switchD_680dfe89_caseD_7;
  switch(param_4) {
  case 2:
  case 3:
  case 4:
    if (param_5 != 1) {
      if ((ushort)(param_5 - 1U) < 0x38) {
        playback_checkSpriteCallbackEvent();
      }
      else {
        uVar2 = param_5 - 0x39;
        iVar5 = scoreEngine_getSoundChannel(*(int *)(param_3 + 0x20),(int)(short)uVar2);
        if (iVar5 == 0) goto switchD_680dfe89_caseD_7;
        iVar5 = playback_executeSpriteCallback();
        if (iVar5 == 0) {
          if (7 < uVar2) goto switchD_680dfe89_caseD_7;
          uVar6 = lingo_isValidObject(*(int *)(*(int *)(param_3 + 0x20) + 4));
          Ordinal_1604(uVar6,*(undefined4 *)(*(int *)(param_3 + 0x20) + 0x5d4 + (short)uVar2 * 4));
        }
        else {
          local_70 = (int *)rendering_resolveState(*(int *)(param_3 + 0x18),local_8c);
          if (local_70 == (int *)0x0) goto switchD_680dfe89_caseD_7;
          if (local_70[2] != 1) break;
          iVar5 = rendering_getMemberData(param_3,local_70);
          if (iVar5 == 0) goto switchD_680dfe89_caseD_7;
          uVar6 = lingo_isValidObject(*(int *)(*(int *)(param_3 + 0x20) + 4));
          Ordinal_1604(uVar6,local_70[0x15]);
        }
        playback_initSpriteCallbackState();
      }
    }
    break;
  case 5:
  case 6:
  case 0xf:
    break;
  case 0xc:
  case 0xd:
  case 0xe:
    if ((bVar1 & 0xf) != 0) break;
  default:
switchD_680dfe89_caseD_7:
    if (iVar4 != 0) {
      Ordinal_1603(param_1);
    }
    if (local_70 != (int *)0x0) {
      rendering_isStateValid((int)local_70);
    }
    return 0;
  }
  playback_verifySpriteCallbackTarget();
                    /* WARNING: Could not recover jumptable at 0x680e002e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)(&PTR_LAB_680e0128)[(byte)(&DAT_680e0138)[extraout_EDX]])();
  return 0;
}



