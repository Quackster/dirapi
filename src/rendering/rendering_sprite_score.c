// Module: rendering
// Topic: Sprite channel processing, score rendering, and frame update pipeline
// Address range: 0x680c7AF0 - 0x680c9DD0
// Functions (47):
//   rendering_readSpritePosition
//   rendering_computeSpriteFlags
//   rendering_initSpriteDefault
//   rendering_writeSpriteData
//   rendering_processSpriteChannel
//   rendering_processScoreChannel
//   rendering_scanSpriteRange
//   rendering_updateSpriteChannels
//   rendering_registerSpriteChannel
//   rendering_getSpriteScoreData
//   rendering_setScoreSlotRef
//   rendering_setScoreSlotRefEx
//   rendering_setScoreTransitionSlot
//   rendering_applyScoreColor
//   rendering_getSpriteScoreBlock
//   rendering_writeScoreFieldEx
//   rendering_writeScoreFieldDefault
//   rendering_writeScoreRect
//   rendering_writeScoreTransition
//   rendering_setScoreParam
//   rendering_writeScoreData
//   rendering_resetScoreData
//   rendering_applyScoreData
//   rendering_initScoreState
//   rendering_freeScoreState
//   rendering_getSpriteState
//   rendering_lookupSpriteChannel
//   rendering_validateAllSprites
//   rendering_getCurrentSprite
//   rendering_getSpriteCount
//   rendering_initSpriteScore
//   rendering_findMaxSpriteDepth
//   rendering_computeScoreChecksum
//   rendering_generateScoreRandom
//   rendering_configureScoreLayout
//   rendering_configureSpriteScore
//   rendering_iterateSpriteDispatch
//   rendering_resolveAllSprites
//   rendering_serializeScoreData
//   rendering_clearSpriteFields
//   rendering_restoreScoreState
//   rendering_getSpriteScoreCount
//   rendering_getSpriteScoreState
//   rendering_updateSpriteScore
//   rendering_submitSpriteScore
//   rendering_copySpriteBlock
//   rendering_transferSpriteScore

// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c7af0 - 0x680c7d50
// Functions (5):
//   rendering_readSpritePosition
//   rendering_computeSpriteFlags
//   rendering_initSpriteDefault
//   rendering_writeSpriteData
//   rendering_processSpriteChannel

// ============================================================
// Function: rendering_readSpritePosition (FUN_680c7af0)
// Address: 680c7af0
// Size: 60 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_readSpritePosition(void)

{
  short sVar1;
  char *in_EAX;
  undefined4 uVar2;
  int unaff_EDI;
  
  uVar2 = 0;
  if (((*in_EAX != '\0') && ((in_EAX[0x14] & 0x80U) != 0)) &&
     (uVar2 = 1, (*(byte *)(unaff_EDI + 0x58) & 0x20) == 0)) {
    sVar1 = xtra_readBE16(in_EAX + 0xe);
    *(int *)(unaff_EDI + 0x70) = (int)sVar1;
    sVar1 = xtra_readBE16(in_EAX + 0xc);
    *(int *)(unaff_EDI + 0x74) = (int)sVar1;
  }
  return uVar2;
}



// ============================================================
// Function: rendering_computeSpriteFlags (FUN_680c7b30)
// Address: 680c7b30
// Size: 372 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_computeSpriteFlags(undefined4 *param_1)
{
  int iVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int unaff_EDI;
  bool bVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  
  bVar8 = false;
  bVar7 = false;
  bVar10 = false;
  bVar9 = false;
  bVar3 = false;
  bVar2 = false;
  if (param_1[0x18] != 0) {
    bVar10 = (char)*(byte *)((int)param_1 + 0x15) < '\0';
    if ((*(byte *)(param_1 + 0x14) & 2) == 0) {
      bVar7 = (*(byte *)((int)param_1 + 0x15) & 0x40) != 0;
      uVar4 = events_checkSpriteHandlerFlags(*(int *)(*(int *)(unaff_EDI + 0x20) + 8),unaff_EDI,param_1[0x10] + 1);
      bVar8 = (uVar4 & 1) != 0;
      bVar9 = (uVar4 & 2) != 0;
      iVar5 = playback_getSpriteData(unaff_EDI,param_1);
      bVar2 = bVar7;
      if (iVar5 != 0) {
        iVar1 = *(int *)(iVar5 + 8);
        bVar8 = iVar1 == 7 || bVar8;
        if ((iVar1 == 10) && ((*(byte *)(iVar5 + 100) & 0x40) != 0)) {
          bVar8 = true;
        }
        if ((((iVar1 == 9) && ((*(byte *)(iVar5 + 0x68) & 0x10) != 0)) && (param_1[0x53] != 0)) &&
           (*(int *)(param_1[0x53] + 0x50) != 0)) {
          bVar3 = true;
        }
        if (iVar1 == 2) {
          bVar3 = true;
        }
        piVar6 = (int *)0x0;
        if ((*(int **)(iVar5 + 0x4c) != (int *)0x0) &&
           (piVar6 = *(int **)(**(int **)(iVar5 + 0x4c) + 4), (int)piVar6 < 0)) {
          piVar6 = (int *)0x0;
        }
        uVar4 = events_checkScriptHandlerFlags(*(int *)(*(int *)(unaff_EDI + 0x20) + 8),unaff_EDI,piVar6);
        if ((uVar4 & 1) != 0) {
          bVar8 = true;
        }
        bVar9 = (uVar4 & 2) != 0 || bVar9;
        if (*(int *)(iVar5 + 8) == 3) {
          bVar2 = (*(byte *)(iVar5 + 0x7d) & 2) != 0 || bVar7;
          bVar7 = (*(byte *)(iVar5 + 0x7d) & 1) != 0 || bVar7;
          if (*(char *)(iVar5 + 0x5b) == '\x01') {
            bVar8 = true;
          }
        }
      }
    }
  }
  uVar4 = (uint)bVar8;
  if (bVar9) {
    uVar4 = uVar4 | 2;
  }
  if (bVar2) {
    uVar4 = uVar4 | 0x41;
  }
  if (bVar7) {
    uVar4 = uVar4 | 0x11;
  }
  if (bVar10) {
    uVar4 = uVar4 | 0x21;
  }
  if (bVar3) {
    uVar4 = uVar4 | 0x100;
  }
  param_1[0x16] = uVar4;
  return 0;
}



// ============================================================
// Function: rendering_initSpriteDefault (FUN_680c7cb0)
// Address: 680c7cb0
// Size: 35 bytes
// Params: undefined4 param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_initSpriteDefault(undefined4 param_1,undefined1 *param_2)
{
  *param_2 = 0x10;
  if (((param_2[2] == '\0') && (param_2[3] == '\0')) && ((param_2[0x14] & 0x20) == 0)) {
    param_2[2] = 0xff;
  }
  return 0;
}



// ============================================================
// Function: rendering_writeSpriteData (FUN_680c7ce0)
// Address: 680c7ce0
// Size: 83 bytes
// Params: uint param_1, undefined1 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_writeSpriteData(uint param_1,undefined1 *param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  int iVar3;
  
  switch(*param_2) {
  case 2:
  case 3:
  case 4:
  case 5:
  case 6:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    return 0;
  default:
    uVar1 = xtra_readBE16(param_2 + 4);
    uVar2 = xtra_readBE16(param_2 + 6);
    param_2 = (undefined1 *)CONCAT22(uVar2,uVar1);
    iVar3 = scoreEngine_setChannelField(param_1,param_2);
    return iVar3;
  }
}



// ============================================================
// Function: rendering_processSpriteChannel (FUN_680c7d50)
// Address: 680c7d50
// Size: 1396 bytes
// Params: uint * param_1, byte * param_2, int * param_3, int param_4, int param_5
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool rendering_processSpriteChannel(uint *param_1,byte *param_2,int *param_3,int param_4,int param_5)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  char cVar4;
  undefined2 uVar5;
  short sVar6;
  int in_EAX;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  byte *pbVar13;
  bool bVar14;
  uint local_14;
  uint local_8;
  
  puVar12 = (undefined4 *)(in_EAX * 400 + param_1[0xd]);
  puVar12[0xf] = param_1;
  puVar12[0x10] = in_EAX;
  local_14 = param_1[0x10];
  local_8 = 0;
  bVar1 = false;
  bVar14 = false;
  if (puVar12[0x48] != 0) {
    local_14 = 1;
  }
  iVar7 = rendering_readSpritePosition();
  if ((iVar7 != 0) && (param_5 != 0)) {
    xtra_readBE32(param_2 + 0xe);
    xtra_readBE32(param_2 + 0xc);
  }
  iVar7 = puVar12[1];
  *(byte *)((int)puVar12 + 0x15) = param_2[0x14];
  if ((iVar7 == 0) || (*(int *)(param_2 + 4) != param_3[1])) {
    iVar7 = rendering_writeSpriteData(param_1[8],param_2);
  }
  if (local_14 == 0) {
    iVar11 = *(int *)param_2;
    if (iVar11 != *param_3) {
      bVar2 = param_2[1] ^ *(byte *)((int)param_3 + 1);
      if ((char)bVar2 < '\0') {
        local_8 = 0x400;
      }
      if ((param_2[2] != *(byte *)((int)param_3 + 2)) || (param_2[3] != *(byte *)((int)param_3 + 3))
         ) {
        local_8 = local_8 | 0x10;
      }
      if (((bVar2 & 0x7f) != 0) && (local_8 = local_8 | 8, (bVar2 & 0x40) != 0)) {
        bVar1 = true;
      }
      if ((char)iVar11 != (char)*param_3) {
        local_8 = local_8 | 2;
      }
      *param_3 = iVar11;
    }
    if (*(int *)(param_2 + 4) != param_3[1]) {
      local_8 = local_8 | 4;
      param_3[1] = *(int *)(param_2 + 4);
    }
    bVar14 = *(int *)(param_2 + 8) != param_3[2];
    if (bVar14) {
      local_8 = local_8 | 0x400000;
      param_3[2] = *(int *)(param_2 + 8);
    }
    if (*(int *)(param_2 + 0xc) != param_3[3]) {
      local_8 = local_8 | 0x80;
      param_3[3] = *(int *)(param_2 + 0xc);
    }
    if (*(int *)(param_2 + 0x10) != param_3[4]) {
      if (((param_2[1] & 0x80) != 0) || ((local_8 & 0x400) != 0)) {
        local_8 = local_8 | 0x200;
      }
      param_3[4] = *(int *)(param_2 + 0x10);
    }
    if (*(int *)(param_2 + 0x14) != param_3[5]) {
      bVar2 = (byte)*(int *)(param_2 + 0x14) ^ *(byte *)(param_3 + 5);
      bVar14 = (bVar2 & 0xc0) != 0 || bVar14;
      if ((bVar2 & 0x30) != 0) {
        local_8 = local_8 | 0x10;
      }
      if (((*(byte *)((int)param_3 + 0x16) ^ param_2[0x16]) & 0xf) != 0) {
        local_8 = local_8 | 0x40;
      }
      bVar2 = *(byte *)((int)param_3 + 0x16) ^ param_2[0x16];
      if (((bVar2 & 0x10) != 0) || (param_2[0x15] != *(byte *)((int)param_3 + 0x15))) {
        local_8 = local_8 | 8;
      }
      if ((bVar2 & 0x60) != 0) {
        local_8 = local_8 | 0x40000;
      }
      param_3[5] = *(int *)(param_2 + 0x14);
    }
    if (*(int *)(param_2 + 0x18) != param_3[6]) {
      local_8 = local_8 | 0x10;
      param_3[6] = *(int *)(param_2 + 0x18);
    }
    if (*(int *)(param_2 + 0x1c) != param_3[7]) {
      local_8 = local_8 | 0x40000;
      param_3[7] = *(int *)(param_2 + 0x1c);
    }
    if (*(int *)(param_2 + 0x20) != param_3[8]) {
      local_8 = local_8 | 0x40000;
      param_3[8] = *(int *)(param_2 + 0x20);
    }
    if ((bVar1) || ((param_2[1] & 0x40) != 0)) {
      param_1[0x5f] = 1;
      param_1[0x5e] = 1;
    }
    if ((puVar12[0x13] & 0x400) != 0) {
      local_8 = local_8 | 0x40000;
      puVar12[0x13] = puVar12[0x13] & 0xfffffbff;
    }
    if ((puVar12[0x13] & 0x800) != 0) {
      local_8 = local_8 | 0x180;
      puVar12[0x13] = puVar12[0x13] & 0xfffff7ff;
    }
    if ((puVar12[0x13] & 0x1000) != 0) {
      local_8 = local_8 | 0x100000;
      puVar12[0x13] = puVar12[0x13] & 0xffffefff;
    }
  }
  else {
    local_8 = 0x6d9;
    if (puVar12[0x60] != 0) {
      local_8 = 0x1006d9;
    }
    pbVar13 = param_2;
    for (iVar11 = 0xc; iVar11 != 0; iVar11 = iVar11 + -1) {
      *param_3 = *(int *)pbVar13;
      pbVar13 = pbVar13 + 4;
      param_3 = param_3 + 1;
    }
  }
  if (iVar7 == 0) {
    param_3 = (int *)0x0;
  }
  else {
    param_3 = *(int **)(iVar7 + 8);
  }
  if (param_3 != (int *)puVar12[0x19]) {
    local_8 = local_8 | 2;
  }
  if ((puVar12[1] != 0) && (*(int **)(puVar12[1] + 8) != param_3)) {
    local_8 = local_8 | 2;
  }
  if ((((int *)puVar12[0x19] == (int *)0xf) && ((*(byte *)(puVar12 + 0x13) & 4) == 0)) &&
     ((local_8 & 6) != 0)) {
    playback_getSpriteDataRef((int)puVar12);
  }
  puVar12[0x19] = param_3;
  if (iVar7 != 0) {
    switch(*(undefined4 *)(iVar7 + 8)) {
    case 2:
    case 9:
      local_8 = local_8 | 0x2000;
      break;
    case 3:
      uVar8 = rendering_checkMediaOverlay(iVar7,(int)param_2);
      if (uVar8 != ((uint)puVar12[0x16] >> 4 & 1)) {
        local_8 = local_8 | 0x4000;
      }
      break;
    case 10:
      if (((local_8 & 2) == 0) && ((*(byte *)(puVar12 + 0x13) & 8) == 0)) {
        playback_getSpriteRef((int)puVar12);
      }
    }
  }
  if (((puVar12[0x15] ^ puVar12[0x14]) & 2) != 0) {
    local_8 = local_8 | 0x800;
  }
  puVar12[0x13] = puVar12[0x13] & 0xfffffffd;
  puVar12[0x15] = puVar12[0x14];
  if (local_8 != 0) {
    if (local_8 != 0x2000) {
      playback_getSpriteRef((int)puVar12);
    }
    if (((local_8 & 0x800) != 0) && ((*(byte *)(puVar12 + 0x14) & 2) != 0)) {
      playback_getSpriteDataRef((int)puVar12);
    }
    if ((local_8 & 0x4002) != 0) {
      playback_updateSpriteData((int)param_1,puVar12);
    }
  }
  if ((param_4 == 0) &&
     ((uVar8 = *param_1 >> 6 & 3, uVar8 == 1 || ((uVar8 != 2 && ((param_2[1] >> 6 & 1) != 0)))))) {
    puVar12[0x13] = puVar12[0x13] | 4;
    if (((bVar1) && ((local_8 & 0x800) != 0)) && ((*(byte *)(puVar12 + 0x14) & 2) == 0)) {
      playback_getSpriteRef((int)puVar12);
    }
  }
  else {
    puVar12[0x13] = puVar12[0x13] & 0xfffffffb;
  }
  if (local_8 != 0) {
    uVar5 = xtra_readBE16(param_2 + 4);
    *(undefined2 *)puVar12 = uVar5;
    uVar5 = xtra_readBE16(param_2 + 6);
    *(undefined2 *)((int)puVar12 + 2) = uVar5;
    puVar12[1] = iVar7;
    if (*(ushort *)(puVar12 + 3) != (ushort)param_2[1]) {
      local_8 = local_8 | 0x400;
      *(ushort *)(puVar12 + 3) = (ushort)param_2[1];
    }
    *(byte *)((int)puVar12 + 0xf) = param_2[2];
    *(byte *)(puVar12 + 4) = param_2[0x18];
    *(byte *)((int)puVar12 + 0x11) = param_2[0x1a];
    *(byte *)((int)puVar12 + 0x12) = param_2[3];
    *(byte *)((int)puVar12 + 0x13) = param_2[0x19];
    *(byte *)(puVar12 + 5) = param_2[0x1b];
    bVar2 = param_2[0x16];
    bVar3 = bVar2 - 1 & 0xf;
    if (0xe < bVar3) {
      bVar3 = 0;
    }
    *(byte *)((int)puVar12 + 0x16) = (bVar2 ^ bVar3) & 0xf ^ bVar2;
    sVar6 = xtra_readBE16(param_2 + 0xe);
    puVar12[6] = (int)sVar6;
    sVar6 = xtra_readBE16(param_2 + 0xc);
    puVar12[7] = (int)sVar6;
    sVar6 = xtra_readBE16(param_2 + 0x12);
    puVar12[8] = (int)sVar6;
    sVar6 = xtra_readBE16(param_2 + 0x10);
    puVar12[9] = (int)sVar6;
    puVar12[0xc] = (uint)*param_2;
    iVar7 = xtra_readBE32Ptr(param_2 + 8);
    if (puVar12[2] != iVar7) {
      playback_getSpriteRenderData((int)param_1,(int)puVar12);
    }
    puVar12[2] = iVar7;
    *(byte *)((int)puVar12 + 0x15) = param_2[0x14];
    *(byte *)((int)puVar12 + 0xe) = param_2[0x15];
    uVar9 = xtra_readBE32Ptr(param_2 + 0x1c);
    puVar12[0xd] = uVar9;
    uVar9 = xtra_readBE32Ptr(param_2 + 0x20);
    puVar12[0xe] = uVar9;
  }
  uVar8 = puVar12[0x13];
  uVar10 = playback_createSpriteState((int)param_1,puVar12,(int *)puVar12[1]);
  if (uVar10 != (uVar8 >> 8 & 1)) {
    local_8 = local_8 | 0x20000;
  }
  if (local_8 != 0) {
    playback_getSpriteInfoEx((int)param_1,puVar12,local_8);
    if (puVar12[0x18] == 0) {
      playback_getSpriteRenderData((int)param_1,(int)puVar12);
    }
    puVar12[0x13] = puVar12[0x13] | 0x2000;
    playback_renderSpriteFrame((int)puVar12,(-(uint)(param_1[0x5e] != 0) & 0xffffffec) + 0x14);
    if ((local_8 & 0x100) != 0) {
      puVar12[0x12] = puVar12[0x11];
    }
    return bVar14;
  }
  if (param_3 == (int *)0xf) {
    if ((*(byte *)(puVar12 + 0x13) & 8) == 0) {
      cVar4 = bitmap_processSpriteUpdate(puVar12);
      if (cVar4 != '\0') {
        puVar12[0x13] = puVar12[0x13] | 0x2000;
        return bVar14;
      }
    }
    else {
      playback_renderSpriteFrame((int)puVar12,0);
    }
  }
  return bVar14;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c82e0 - 0x680c8950
// Functions (15):
//   rendering_processScoreChannel
//   rendering_scanSpriteRange
//   rendering_updateSpriteChannels
//   rendering_registerSpriteChannel
//   rendering_getSpriteScoreData
//   rendering_setScoreSlotRef
//   rendering_setScoreSlotRefEx
//   rendering_setScoreTransitionSlot
//   rendering_applyScoreColor
//   rendering_getSpriteScoreBlock
//   rendering_writeScoreFieldEx
//   rendering_writeScoreFieldDefault
//   rendering_writeScoreRect
//   rendering_writeScoreTransition
//   rendering_setScoreParam

// ============================================================
// Function: rendering_processScoreChannel (FUN_680c82e0)
// Address: 680c82e0
// Size: 257 bytes
// Params: uint * param_1, int param_2, undefined4 * param_3, int * param_4, byte * param_5, int param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_processScoreChannel(uint *param_1,int param_2,undefined4 *param_3,int *param_4,byte *param_5,
                 int param_6)
{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  uint *extraout_EAX;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  
  puVar2 = param_1;
  iVar4 = playback_getLifecycleState((int)param_1);
  iVar1 = param_2 + 1;
  rendering_processSpriteChannel(param_1,param_5,param_4,param_6,iVar4);
  puVar3 = extraout_EAX;
  if (iVar4 != 0) {
    iVar5 = xtra_readBE32Ptr(param_5 + 8);
    puVar3 = extraout_EAX;
    if ((iVar5 != 0) && (puVar3 = extraout_EAX, *(int *)(iVar1 * 0x34 + param_1[0xe]) == 0)) {
      iVar8 = iVar5;
      puVar6 = (undefined4 *)media_getVtableFunc((int *)param_1[10]);
      uVar7 = bitmap_readRtfField(puVar6,iVar8);
      puVar3 = extraout_EAX;
      if (uVar7 != 0) {
        uVar7 = param_1[0x5b];
        param_1[0x5b] = 1;
        param_3[0x4a] = param_3[0x4a] + 1;
        events_loadChannelSprites(*(int *)(param_1[8] + 8),param_1,iVar1,iVar5,1);
        param_3[0x4a] = param_3[0x4a] + -1;
        param_1 = (uint *)0x1;
        puVar2[0x5b] = uVar7;
        puVar3 = param_1;
      }
    }
  }
  param_1 = puVar3;
  if ((param_3[0xc] != 0) &&
     ((((param_1 != (uint *)0x0 || (puVar2[0x5b] != 0)) || (param_3[0x4a] != 0)) ||
      ((((*(byte *)(param_3 + 0x14) & 0x14) != 0 ||
        (*(int *)(iVar1 * 0x34 + 0xc + puVar2[0xe]) == -1)) || (iVar4 == 0)))))) {
    rendering_computeSpriteFlags(param_3);
    if ((param_3[0x14] & 0x10) != 0) {
      param_3[0x14] = param_3[0x14] & 0x10;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_scanSpriteRange (FUN_680c83f0)
// Address: 680c83f0
// Size: 172 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_scanSpriteRange(void)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  int iVar5;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar3 = *(int *)(unaff_ESI + 0x120);
  iVar4 = -1;
  local_8 = -1;
  local_c = -1;
  local_10 = 0;
  if (iVar3 <= *(int *)(unaff_ESI + 0x124)) {
    iVar5 = iVar3 * 400;
    do {
      if (*(char *)(*(int *)(unaff_ESI + 0x30) + iVar3) != '\0') {
        iVar1 = *(int *)(unaff_ESI + 0x34);
        if ((iVar4 == -1) && (*(int *)(iVar1 + 0x60 + iVar5) == 10)) {
          iVar4 = iVar3;
        }
        uVar2 = *(uint *)(iVar1 + 0x58 + iVar5);
        if (((uVar2 & 1) != 0) || ((*(byte *)(iVar1 + 0x50 + iVar5) & 4) != 0)) {
          local_10 = 1;
        }
        if ((uVar2 & 0x30) != 0) {
          if ((local_8 == -1) && ((uVar2 & 0x10) != 0)) {
            local_8 = iVar3;
          }
          if ((local_c == -1) && ((uVar2 & 0x20) != 0)) {
            local_c = iVar3;
          }
        }
      }
      iVar3 = iVar3 + 1;
      iVar5 = iVar5 + 400;
    } while (iVar3 <= *(int *)(unaff_ESI + 0x124));
  }
  *(int *)(unaff_ESI + 0x4c) = iVar4;
  *(int *)(unaff_ESI + 0x48) = local_8;
  *(int *)(unaff_ESI + 0x44) = local_c;
  *(undefined4 *)(unaff_ESI + 0x50) = local_10;
  return 0;
}



// ============================================================
// Function: rendering_updateSpriteChannels (FUN_680c84a0)
// Address: 680c84a0
// Size: 466 bytes
// Params: uint * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_updateSpriteChannels(uint *param_1)
{
  short sVar1;
  uint uVar2;
  bool bVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int *piVar8;
  byte *pbVar9;
  int iVar10;
  uint local_20;
  uint local_1c;
  int local_14;
  int local_c;
  int local_8;
  
  puVar4 = param_1;
  local_8 = 0;
  local_c = 0;
  bVar3 = false;
  if (param_1 != (uint *)0x0) {
    uVar2 = param_1[0xb];
    param_1[0x5f] = 0;
    media_lockScoreData((int *)param_1[10],&local_8,&local_c);
    local_1c = 0;
    local_20 = 0xffffffff;
    if (local_8 != 0) {
      if (local_c != 0) {
        iVar5 = playback_getLifecycleState((int)param_1);
        if (((iVar5 != 0) && (iVar5 = xtra_readBE32Ptr((undefined1 *)(local_8 + 4)), iVar5 != 0)) &&
           (*(int *)param_1[0xe] == 0)) {
          iVar10 = iVar5;
          puVar6 = (undefined4 *)media_getVtableFunc((int *)param_1[10]);
          uVar7 = bitmap_readRtfField(puVar6,iVar10);
          if (uVar7 != 0) {
            uVar7 = param_1[0x5b];
            param_1[0x5b] = 1;
            events_loadChannelSprites(*(int *)(param_1[8] + 8),param_1,0,iVar5,1);
            param_1[0x5b] = uVar7;
          }
        }
        sVar1 = *(short *)(*(int *)param_1[8] + 0x6e);
        uVar7 = 0;
        if (0 < (int)uVar2) {
          param_1 = (uint *)0x0;
          local_14 = 0x120;
          do {
            iVar5 = uVar7 + 6;
            if ((iVar5 < 0) || (0x3ed < iVar5)) {
              pbVar9 = (byte *)0x0;
            }
            else {
              pbVar9 = (byte *)(local_14 + local_8);
            }
            if ((iVar5 < 0) || (0x3ed < iVar5)) {
              piVar8 = (int *)0x0;
            }
            else {
              piVar8 = (int *)(local_14 + local_c);
            }
            if ((((*(char *)(uVar7 + puVar4[0xc]) != '\0') || (*pbVar9 != 0)) ||
                (*(int *)(pbVar9 + 8) != 0)) || ((puVar4[0x10] != 0 && ((char)*piVar8 != '\0')))) {
              if ((!bVar3) && (bVar3 = true, local_1c = uVar7, (int)uVar7 < (int)puVar4[0x48])) {
                puVar4[0x48] = uVar7;
              }
              if ((int)puVar4[0x49] < (int)uVar7) {
                puVar4[0x49] = uVar7;
              }
              rendering_processScoreChannel(puVar4,uVar7,(undefined4 *)(puVar4[0xd] + (int)param_1),piVar8,pbVar9,
                           (uint)(sVar1 != 0));
              local_20 = uVar7;
            }
            param_1 = param_1 + 100;
            uVar7 = uVar7 + 1;
            local_14 = local_14 + 0x30;
          } while ((int)uVar7 < (int)uVar2);
        }
        puVar4[0x10] = 0;
        puVar4[0x48] = local_1c;
        puVar4[0x49] = local_20;
        rendering_scanSpriteRange();
        if (puVar4[0x5f] == 0) {
          puVar4[0x5e] = 0;
        }
      }
      if (local_8 != 0) {
        media_unlockScoreData((int *)puVar4[10],&local_8,&local_c);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_registerSpriteChannel (FUN_680c8680)
// Address: 680c8680
// Size: 72 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_registerSpriteChannel(int param_1,undefined4 *param_2)
{
  if ((int)param_2[0x10] < *(int *)(param_1 + 0x120)) {
    *(undefined4 *)(param_1 + 0x120) = param_2[0x10];
  }
  if (*(int *)(param_1 + 0x124) < (int)param_2[0x10]) {
    *(undefined4 *)(param_1 + 0x124) = param_2[0x10];
  }
  rendering_readSpritePosition();
  rendering_computeSpriteFlags(param_2);
  rendering_scanSpriteRange();
  return 0;
}



// ============================================================
// Function: rendering_getSpriteScoreData (FUN_680c86d0)
// Address: 680c86d0
// Size: 37 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getSpriteScoreData(int *param_1,int param_2)
{
  if (param_2 != 0) {
    media_getScoreSlotRef2(param_1,8);
    return 0;
  }
  media_setScoreSlot(param_1,8);
  return 0;
}



// ============================================================
// Function: rendering_setScoreSlotRef (FUN_680c8700)
// Address: 680c8700
// Size: 37 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_setScoreSlotRef(int *param_1,int param_2)
{
  if (param_2 != 0) {
    media_getScoreSlotRef2(param_1,1);
    return 0;
  }
  media_setScoreSlot(param_1,1);
  return 0;
}



// ============================================================
// Function: rendering_setScoreSlotRefEx (FUN_680c8730)
// Address: 680c8730
// Size: 69 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_setScoreSlotRefEx(int *param_1,int param_2,int param_3,int param_4)
{
  if (param_3 == 0) {
    media_setScoreSlot(param_1,2);
  }
  else {
    media_getScoreSlotRef2(param_1,2);
    if (param_4 != 0) {
      *(undefined2 *)(param_2 + 0x7a) = 0xffff;
      scoreEngine_playSoundChannel(*(int **)(param_2 + 0x20),0,param_2,*(undefined4 *)(param_2 + 0x78));
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_setScoreTransitionSlot (FUN_680c8780)
// Address: 680c8780
// Size: 37 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_setScoreTransitionSlot(int *param_1,int param_2)
{
  if (param_2 != 0) {
    media_getScoreSlotRef2(param_1,0x10);
    return 0;
  }
  media_setScoreSlot(param_1,0x10);
  return 0;
}



// ============================================================
// Function: rendering_applyScoreColor (FUN_680c87b0)
// Address: 680c87b0
// Size: 69 bytes
// Params: int param_1, byte param_2, byte param_3, byte param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_applyScoreColor(int param_1,byte param_2,byte param_3,byte param_4,int param_5)
{
  rendering_packColorValue(param_2,param_3,param_4,(ushort)(param_5 == 0));
  xtra_readBE32((undefined1 *)(param_1 + 0x60));
  xtra_readBE32((undefined1 *)(param_1 + 0x62));
  return 0;
}



// ============================================================
// Function: rendering_getSpriteScoreBlock (FUN_680c8800)
// Address: 680c8800
// Size: 59 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getSpriteScoreBlock(int param_1,int param_2,short param_3)
{
  scoreEngine_getChannelCount(*(int *)(param_2 + 0x20),param_3);
  xtra_readBE32((undefined1 *)(param_1 + 0x60));
  xtra_readBE32((undefined1 *)(param_1 + 0x62));
  return 0;
}



// ============================================================
// Function: rendering_writeScoreFieldEx (FUN_680c8840)
// Address: 680c8840
// Size: 97 bytes
// Params: int param_1, int param_2, short param_3, undefined1 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_writeScoreFieldEx(int param_1,int param_2,short param_3,undefined1 param_4,int param_5)
{
  scoreEngine_getChannelCount(*(int *)(param_2 + 0x20),param_3);
  xtra_readBE32((undefined1 *)(param_1 + 0xf0));
  xtra_readBE32((undefined1 *)(param_1 + 0xf2));
  *(undefined1 *)(param_1 + 0xf4) = param_4;
  xtra_readBE32((undefined1 *)(param_1 + 0xf8));
  *(byte *)(param_1 + 0xf5) = (param_5 < 2) - 1U & 4;
  return 0;
}



// ============================================================
// Function: rendering_writeScoreFieldDefault (FUN_680c88b0)
// Address: 680c88b0
// Size: 28 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_writeScoreFieldDefault(int param_1,int param_2,short param_3)
{
  rendering_writeScoreFieldEx(param_1,param_2,param_3,0x1e,0);
  return 0;
}



// ============================================================
// Function: rendering_writeScoreRect (FUN_680c88d0)
// Address: 680c88d0
// Size: 62 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_writeScoreRect(int param_1,int param_2,short param_3)
{
  scoreEngine_getChannelCount(*(int *)(param_2 + 0x20),param_3);
  xtra_readBE32((undefined1 *)(param_1 + 0xc0));
  xtra_readBE32((undefined1 *)(param_1 + 0xc2));
  return 0;
}



// ============================================================
// Function: rendering_writeScoreTransition (FUN_680c8910)
// Address: 680c8910
// Size: 62 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_writeScoreTransition(int param_1,int param_2,short param_3)
{
  scoreEngine_getChannelCount(*(int *)(param_2 + 0x20),param_3);
  xtra_readBE32((undefined1 *)(param_1 + 0x90));
  xtra_readBE32((undefined1 *)(param_1 + 0x92));
  return 0;
}



// ============================================================
// Function: rendering_setScoreParam (FUN_680c8950)
// Address: 680c8950
// Size: 53 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_setScoreParam(int param_1,int param_2,short param_3)
{
  if (param_3 < 1) {
    param_3 = 1;
  }
  *(undefined1 *)(param_1 + 0x36) = 0xf6;
  xtra_readBE32((undefined1 *)(param_1 + 0x34));
  media_setScoreTempo(*(int **)(param_2 + 0x28),param_3);
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c8990 - 0x680c8d40
// Functions (8):
//   rendering_writeScoreData
//   rendering_resetScoreData
//   rendering_applyScoreData
//   rendering_initScoreState
//   rendering_freeScoreState
//   rendering_getSpriteState
//   rendering_lookupSpriteChannel
//   rendering_validateAllSprites

// ============================================================
// Function: rendering_writeScoreData (FUN_680c8990)
// Address: 680c8990
// Size: 56 bytes
// Params: undefined1 * param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_writeScoreData(undefined1 *param_1,int param_2,short param_3)
{
  scoreEngine_getChannelCount(*(int *)(param_2 + 0x20),param_3);
  xtra_readBE32(param_1);
  xtra_readBE32(param_1 + 2);
  return 0;
}



// ============================================================
// Function: rendering_resetScoreData (FUN_680c89d0)
// Address: 680c89d0
// Size: 110 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_resetScoreData(int *param_1)
{
  uint uVar1;
  int local_8;
  
  local_8 = 0;
  uVar1 = media_getScoreSlotFlags(param_1);
  media_lockScoreData(param_1,&local_8,(undefined4 *)0x0);
  if ((uVar1 & 0xfffffff9) != 0) {
    if ((uVar1 & 8) != 0) {
      *(undefined4 *)(local_8 + 0x60) = 0;
      rendering_getSpriteScoreData(param_1,0);
    }
    if ((uVar1 & 0x10) != 0) {
      *(undefined1 *)(local_8 + 0x36) = 0;
      rendering_setScoreTransitionSlot(param_1,0);
    }
  }
  if (local_8 != 0) {
    media_unlockScoreData(param_1,&local_8,(undefined4 *)0x0);
  }
  return 0;
}



// ============================================================
// Function: rendering_applyScoreData (FUN_680c8a40)
// Address: 680c8a40
// Size: 300 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_applyScoreData(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  code *pcVar5;
  int unaff_EDI;
  int *local_1c;
  undefined4 local_18;
  code *local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  pcVar5 = (code *)0x0;
  bVar1 = false;
  local_c = 0;
  local_8 = 0;
  local_10 = 0;
  local_18 = 0;
  local_14 = (code *)0x0;
  if (unaff_EDI == 0) {
    if (param_1 == (undefined4 *)0x0) goto LAB_680c8b42;
    local_1c = (int *)*param_1;
    iVar3 = *local_1c;
    pcVar5 = *(code **)(*(int *)(iVar3 + 0xc) + 0xd0);
  }
  else {
    local_1c = *(int **)(*(int *)(unaff_EDI + 4) + 8);
    iVar3 = *local_1c;
    local_14 = *(code **)(*(int *)(iVar3 + 0xc) + 0xcc);
  }
  local_c = Ordinal_1111(param_3,4);
  if (local_c != 0) {
    iVar2 = Ordinal_1404(&local_8,local_c,3);
    if (iVar2 != 0) {
      if (unaff_EDI == 0) {
        (*pcVar5)(iVar3,*(undefined2 *)(param_1 + 1),param_2,&local_18,&param_3,local_8,&local_10);
      }
      else {
        (*local_14)(iVar3,*(undefined4 *)(*(int *)(unaff_EDI + 4) + 4),param_2,&local_18,&param_3,
                    local_8,&local_10);
      }
      if (local_10 != 0) {
        iVar3 = lingo_getMovieRef((int)local_1c);
        if (iVar3 != 0) {
          lingo_formatDebugMsg(local_1c,local_10);
          goto LAB_680c8b42;
        }
      }
      uVar4 = Ordinal_1433(local_8);
      iVar3 = Ordinal_1434(local_8,uVar4);
      if (iVar3 != 0) {
        bVar1 = true;
      }
    }
  }
LAB_680c8b42:
  Ordinal_1407(&local_8);
  if ((!bVar1) && (local_c != 0)) {
    Ordinal_1113(&local_c);
  }
  return local_c;
}



// ============================================================
// Function: rendering_initScoreState (FUN_680c8b70)
// Address: 680c8b70
// Size: 126 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_initScoreState(void)

{
  int iVar1;
  undefined4 uVar2;
  short sVar3;
  int unaff_EDI;
  int local_8;
  
  uVar2 = 0;
  sVar3 = -1;
  local_8 = 0;
  local_8 = scoreEngine_allocFrameDataPtr(unaff_EDI);
  if (local_8 != 0) {
    iVar1 = scoreEngine_getFrameLayout(local_8);
    while (iVar1 != 0) {
      if (sVar3 < *(short *)(iVar1 + 0x76)) {
        sVar3 = *(short *)(iVar1 + 0x76);
      }
      iVar1 = scoreEngine_getFrameLayout(local_8);
    }
    if (*(int *)(unaff_EDI + 0x480) != 0) {
      Ordinal_1163((int *)(unaff_EDI + 0x480));
    }
    iVar1 = Ordinal_1150(500,500,4);
    *(int *)(unaff_EDI + 0x480) = iVar1;
    if (iVar1 != 0) {
      uVar2 = 1;
    }
  }
  scoreEngine_initCastXtra(&local_8);
  return uVar2;
}



// ============================================================
// Function: rendering_freeScoreState (FUN_680c8bf0)
// Address: 680c8bf0
// Size: 17 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_freeScoreState(void)
{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x480) != 0) {
    Ordinal_1169(*(int *)(in_EAX + 0x480));
  }
  return 0;
}



// ============================================================
// Function: rendering_getSpriteState (FUN_680c8c10)
// Address: 680c8c10
// Size: 266 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getSpriteState(undefined4 param_1)
{
  bool bVar1;
  uint uVar2;
  int *piVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined4 *unaff_EDI;
  undefined4 local_34;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  
  local_34 = param_1;
  piVar3 = (int *)scoreEngine_setChannelField((uint)unaff_EDI,param_1);
  if ((piVar3 == (int *)0x0) || (piVar3[2] == 0)) {
    return 0;
  }
  if (((*(byte *)(piVar3 + 0xc) & 4) == 0) &&
     (bVar1 = rendering_isSpriteEmpty(*piVar3,(short)piVar3[1]), CONCAT31(extraout_var,bVar1) == 0)) {
    if (unaff_EDI[0x120] == 0) {
      return 0;
    }
    piVar3[0xc] = piVar3[0xc] | 4;
    iVar4 = Ordinal_1152(unaff_EDI[0x120],&local_34);
    if (iVar4 != 0) {
      local_2c = *unaff_EDI;
      local_28 = 0x20;
      local_30 = piVar3;
      rendering_initState((int *)&local_30);
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: rendering_lookupSpriteChannel (FUN_680c8d20)
// Address: 680c8d20
// Size: 31 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_lookupSpriteChannel(int param_1,int param_2)
{
  short sVar1;
  undefined2 extraout_var;
  
  sVar1 = scoreEngine_getChannelCount(param_1,(short)*(undefined4 *)(param_2 + 4));
  rendering_getSpriteState(CONCAT22(extraout_var,sVar1));
  return 0;
}



// ============================================================
// Function: rendering_validateAllSprites (FUN_680c8d40)
// Address: 680c8d40
// Size: 908 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_validateAllSprites(void)

{
  int *piVar1;
  bool bVar2;
  short sVar3;
  undefined2 uVar4;
  int *in_EAX;
  int iVar5;
  int iVar6;
  int iVar7;
  short extraout_var_00;
  int iVar8;
  undefined3 extraout_var;
  short extraout_var_01;
  char *pcVar9;
  undefined4 local_34;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  piVar1 = *(int **)(*in_EAX + 0x28);
  local_34 = 0;
  iVar5 = media_cloneScoreState((int)piVar1);
  if (iVar5 != 0) {
    iVar6 = media_lockScoreData(piVar1,&local_8,(undefined4 *)0x0);
    media_getPlaybackPosition((int)piVar1);
    media_readPlaybackData((int)piVar1,1,0);
    iVar7 = rendering_initScoreState();
    if ((iVar7 != 0) && (local_c = scoreEngine_allocFrameDataPtr((int)in_EAX), local_c != 0)) {
      iVar7 = scoreEngine_getFrameLayout(local_c);
      while (iVar7 != 0) {
        sVar3 = scoreEngine_getChannelCount((int)in_EAX,*(short *)(iVar7 + 4));
        local_10 = CONCAT22(extraout_var_00,sVar3);
        if (extraout_var_00 <= *(short *)(iVar7 + 0x76)) {
          do {
            iVar8 = scoreEngine_setChannelField((uint)in_EAX,local_10);
            if (((iVar8 != 0) && (iVar8 = display_isVectorMember(iVar8), iVar8 != 0)) &&
               (iVar8 = rendering_getSpriteState(local_10), iVar8 == 0)) goto LAB_680c90a3;
            sVar3 = (*(unsigned short *)((char *)&local_10 + 2)) + 1;
            local_10 = CONCAT22(sVar3,(undefined2)local_10);
          } while (sVar3 <= *(short *)(iVar7 + 0x76));
        }
        iVar7 = scoreEngine_getFrameLayout(local_c);
      }
      scoreEngine_initCastXtra(&local_c);
      do {
        iVar7 = local_8;
        uVar4 = xtra_readBE16((undefined1 *)(local_8 + 0xf0));
        sVar3 = xtra_readBE16((undefined1 *)(iVar7 + 0xf2));
        local_10 = CONCAT22(sVar3,uVar4);
        if ((sVar3 != 0) && (iVar7 = rendering_getSpriteState(local_10), iVar7 == 0)) goto LAB_680c90a3;
        iVar7 = local_8;
        uVar4 = xtra_readBE16((undefined1 *)(local_8 + 0xc0));
        sVar3 = xtra_readBE16((undefined1 *)(iVar7 + 0xc2));
        local_18 = CONCAT22(sVar3,uVar4);
        if ((sVar3 != 0) && (iVar7 = rendering_getSpriteState(local_18), iVar7 == 0)) goto LAB_680c90a3;
        iVar7 = local_8;
        uVar4 = xtra_readBE16((undefined1 *)(local_8 + 0x90));
        sVar3 = xtra_readBE16((undefined1 *)(iVar7 + 0x92));
        local_1c = CONCAT22(sVar3,uVar4);
        if ((sVar3 != 0) && (iVar7 = rendering_getSpriteState(local_1c), iVar7 == 0)) goto LAB_680c90a3;
        iVar7 = local_8;
        uVar4 = xtra_readBE16((undefined1 *)(local_8 + 0x60));
        sVar3 = xtra_readBE16((undefined1 *)(iVar7 + 0x62));
        local_20 = CONCAT22(sVar3,uVar4);
        if ((sVar3 != 0) && (iVar7 = rendering_getSpriteState(local_20), iVar7 == 0)) goto LAB_680c90a3;
        if (0 < iVar6) {
          local_2c = 6;
          local_28 = 0x120;
          do {
            if (local_2c < 0x3ee) {
              pcVar9 = (char *)(local_28 + local_8);
            }
            else {
              pcVar9 = (char *)0x0;
            }
            if (*pcVar9 != '\0') {
              uVar4 = xtra_readBE16(pcVar9 + 4);
              sVar3 = xtra_readBE16(pcVar9 + 6);
              local_10 = CONCAT22(sVar3,uVar4);
              if ((sVar3 != 0) && (iVar7 = rendering_getSpriteState(local_10), iVar7 == 0)) goto LAB_680c90a3;
              if (*pcVar9 == '\x01') {
                switch(pcVar9[1] & 0x3f) {
                case 4:
                case 5:
                case 6:
                case 7:
                case 8:
                case 0x20:
                case 0x21:
                case 0x22:
                case 0x23:
                case 0x25:
                case 0x26:
                case 0x27:
                  iVar7 = scoreEngine_setChannelField((uint)in_EAX,local_10);
                  if (iVar7 != 0) {
                    *(uint *)(iVar7 + 0x9c) = *(uint *)(iVar7 + 0x9c) | 0x40;
                  }
                  break;
                case 9:
                  local_24 = CONCAT22(sVar3 + 1,uVar4);
                  if (((short)(sVar3 + 1) != 0) && (iVar7 = rendering_getSpriteState(local_24), iVar7 == 0))
                  goto LAB_680c90a3;
                }
              }
            }
            local_28 = local_28 + 0x30;
            iVar7 = local_2c - 5;
            local_2c = local_2c + 1;
          } while (iVar7 < iVar6);
        }
        bVar2 = media_isPlaybackActive((int)piVar1,0);
      } while (CONCAT31(extraout_var,bVar2) != 0);
      local_c = scoreEngine_allocFrameDataPtr((int)in_EAX);
      if (local_c != 0) {
        iVar6 = scoreEngine_getFrameLayout(local_c);
        while (iVar6 != 0) {
          sVar3 = scoreEngine_getChannelCount((int)in_EAX,*(short *)(iVar6 + 4));
          local_10 = CONCAT22(extraout_var_01,sVar3);
          if (extraout_var_01 <= *(short *)(iVar6 + 0x76)) {
            do {
              iVar7 = scoreEngine_setChannelField((uint)in_EAX,local_10);
              if (((iVar7 != 0) && ((*(byte *)(iVar7 + 0x30) & 4) == 0)) &&
                 (iVar7 = rendering_getSpriteState(local_10), iVar7 == 0)) goto LAB_680c90a3;
              sVar3 = (*(unsigned short *)((char *)&local_10 + 2)) + 1;
              local_10 = CONCAT22(sVar3,(undefined2)local_10);
            } while (sVar3 <= *(short *)(iVar6 + 0x76));
          }
          iVar6 = scoreEngine_getFrameLayout(local_c);
        }
        rendering_freeScoreState();
        local_34 = 1;
      }
    }
  }
LAB_680c90a3:
  if (local_8 != 0) {
    media_unlockScoreData(piVar1,&local_8,(undefined4 *)0x0);
  }
  if (iVar5 != 0) {
    media_copyScoreState((int)piVar1,iVar5);
  }
  scoreEngine_initCastXtra(&local_c);
  return local_34;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c9110 - 0x680c97e0
// Functions (10):
//   rendering_getCurrentSprite
//   rendering_getSpriteCount
//   rendering_initSpriteScore
//   rendering_findMaxSpriteDepth
//   rendering_computeScoreChecksum
//   rendering_generateScoreRandom
//   rendering_configureScoreLayout
//   rendering_configureSpriteScore
//   rendering_iterateSpriteDispatch
//   rendering_resolveAllSprites

// ============================================================
// Function: rendering_getCurrentSprite (FUN_680c9110)
// Address: 680c9110
// Size: 343 bytes
// Return: short
// Calling convention: __stdcall
// ============================================================

short rendering_getCurrentSprite(void)

{
  int _local_c;
  int local_c;
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  int *unaff_ESI;
  /* FIXUP(C2040: 'local_c': 'undefined1): undefined1 local_c [2]; */
  short sStack_a;
  int local_8;
  
  local_8 = 0;
  if (unaff_ESI[2] != 0) {
    return 0;
  }
  iVar3 = *unaff_ESI;
  if (iVar3 == 0) {
    if (unaff_ESI[4] != 0) {
      while (iVar3 = Ordinal_1155(unaff_ESI[5],unaff_ESI[1],local_c), iVar3 != 0) {
        if (sStack_a != 0) {
          sVar2 = scoreEngine_getChannelData(unaff_ESI[4],(short)_local_c);
          unaff_ESI[1] = unaff_ESI[1] + 1;
          return sVar2;
        }
      }
    }
  }
  else if (iVar3 == 1) {
    if (unaff_ESI[4] != 0) {
      if (unaff_ESI[6] == 0) {
        do {
          *(short *)(unaff_ESI + 7) = (short)unaff_ESI[7] + 1;
          iVar3 = scoreEngine_getChannelField(unaff_ESI[4],(short)unaff_ESI[7]);
          if (iVar3 == 0) goto LAB_680c9251;
          uVar1 = *(undefined2 *)(iVar3 + 0x74);
          *(undefined2 *)(unaff_ESI + 8) = uVar1;
          sVar2 = *(short *)(iVar3 + 0x76);
          *(short *)((int)unaff_ESI + 0x22) = sVar2;
        } while ((*(int *)(iVar3 + 0x14) == 0) || (sVar2 == 0));
        *(undefined2 *)((int)unaff_ESI + 0x1e) = uVar1;
      }
      local_8 = unaff_ESI[7];
      sVar2 = *(short *)((int)unaff_ESI + 0x1e) + 1;
      *(short *)((int)unaff_ESI + 0x1e) = sVar2;
      unaff_ESI[6] = (uint)(sVar2 <= *(short *)((int)unaff_ESI + 0x22));
      sVar2 = scoreEngine_getChannelData(unaff_ESI[4],(short)unaff_ESI[7]);
      return sVar2;
    }
  }
  else if (iVar3 == 2) {
    if (unaff_ESI[1] == 0) {
      iVar3 = rendering_getChannelSprite(unaff_ESI[3],(short)unaff_ESI[9]);
      if (iVar3 == 0) goto LAB_680c9251;
      *(undefined2 *)(unaff_ESI + 10) = *(undefined2 *)(iVar3 + 0x74);
      *(undefined2 *)((int)unaff_ESI + 0x2a) = *(undefined2 *)(iVar3 + 0x76);
    }
    if ((short)((short)unaff_ESI[10] + (short)unaff_ESI[1]) <= *(short *)((int)unaff_ESI + 0x2a)) {
      unaff_ESI[1] = unaff_ESI[1] + 1;
      return (short)unaff_ESI[9];
    }
  }
LAB_680c9251:
  unaff_ESI[2] = 1;
  return 0;
}



// ============================================================
// Function: rendering_getSpriteCount (FUN_680c9270)
// Address: 680c9270
// Size: 26 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getSpriteCount(undefined4 param_1)
{
  undefined4 *in_EAX;
  
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  *in_EAX = param_1;
  *(undefined2 *)(in_EAX + 7) = 0;
  return 0;
}



// ============================================================
// Function: rendering_initSpriteScore (FUN_680c9290)
// Address: 680c9290
// Size: 193 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_initSpriteScore(void)
{
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int unaff_ESI;
  
  iVar6 = 0;
  uVar2 = 1;
  uVar1 = 0;
  sVar3 = 0;
  if ((unaff_ESI != 0) && (*(int *)(unaff_ESI + 0x40) != 0)) {
    iVar4 = Ordinal_1154(*(int *)(unaff_ESI + 0x40));
    iVar4 = iVar4 + -1;
    do {
      iVar5 = Ordinal_1156(*(undefined4 *)(unaff_ESI + 0x40),*(undefined4 *)(unaff_ESI + 0x44),iVar4
                          );
      if ((iVar5 != 0) && (*(int *)(iVar5 + 8) != 0)) {
        uVar1 = *(undefined2 *)(iVar5 + 6);
        break;
      }
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
    do {
      iVar5 = Ordinal_1156(*(undefined4 *)(unaff_ESI + 0x40),*(undefined4 *)(unaff_ESI + 0x44),iVar6
                          );
      if ((iVar5 != 0) && (*(int *)(iVar5 + 8) != 0)) {
        uVar2 = *(undefined2 *)(iVar5 + 6);
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 <= iVar4);
    for (; iVar6 <= iVar4; iVar6 = iVar6 + 1) {
      iVar5 = Ordinal_1156(*(undefined4 *)(unaff_ESI + 0x40),*(undefined4 *)(unaff_ESI + 0x44),iVar6
                          );
      if ((iVar5 != 0) && (*(int *)(iVar5 + 8) != 0)) {
        sVar3 = sVar3 + 1;
      }
    }
    *(undefined2 *)(unaff_ESI + 0x74) = uVar2;
    *(undefined2 *)(unaff_ESI + 0x76) = uVar1;
    *(short *)(unaff_ESI + 0xac) = sVar3;
  }
  return 0;
}



// ============================================================
// Function: rendering_findMaxSpriteDepth (FUN_680c9360)
// Address: 680c9360
// Size: 139 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_findMaxSpriteDepth(int param_1)

{
  int iVar1;
  short sVar2;
  short extraout_var;
  int iVar4;
  short extraout_var_00;
  int iVar5;
  undefined4 uVar3;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 8);
  iVar5 = 0;
  rendering_getSpriteCount(1);
  sVar2 = rendering_getCurrentSprite();
  uVar3 = CONCAT22(extraout_var,sVar2);
  sVar2 = extraout_var;
  while (sVar2 != 0) {
    iVar4 = rendering_resolveState(iVar1,uVar3);
    if (((iVar4 != 0) && (*(int *)(iVar4 + 8) == 1)) && (iVar5 < *(int *)(iVar4 + 0x60))) {
      iVar5 = *(int *)(iVar4 + 0x60);
    }
    sVar2 = rendering_getCurrentSprite();
    uVar3 = CONCAT22(extraout_var_00,sVar2);
    sVar2 = extraout_var_00;
  }
  return iVar5;
}



// ============================================================
// Function: rendering_computeScoreChecksum (FUN_680c93f0)
// Address: 680c93f0
// Size: 244 bytes
// Params: short * param_1
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall rendering_computeScoreChecksum(short *param_1)

{
  return ((((((((((((((uint)((param_1[1] + 2) * (*param_1 + 1)) / ((int)param_1[2] + 3U)) *
                    (param_1[3] + 4)) / ((int)param_1[4] + 5U)) * (param_1[5] + 6) - (int)param_1[6]
                  ) + -7) * (param_1[7] + 8) - (int)*(char *)((int)param_1 + 0x11)) -
               (int)(char)param_1[8]) + -8 + (int)param_1[9]) * (param_1[10] + 0xc) + 0xd +
             (int)param_1[0xb]) * ((ushort)param_1[0xc] + 0xe) + (uint)*(byte *)(param_1 + 0xf) +
             (int)param_1[0xe] + 0x30 + (uint)*(byte *)((int)param_1 + 0x1b)) *
            (*(byte *)((int)param_1 + 0x1f) + 0x12) + 0x13 + *(int *)(param_1 + 0x10)) *
           (param_1[0x12] + 0x14) + (int)param_1[0x13] + *(int *)(param_1 + 0x18) +
           *(int *)(param_1 + 0x16) + 0x5a + *(int *)(param_1 + 0x14)) *
          ((char)param_1[0x1a] + 0x19) + 0x1a + (int)param_1[0x1b]) *
         (param_1[0x1d] * 0xe06 + -0xbb0000) * (param_1[0x1c] + 0x1b) ^ FOURCC_ralf;
}



// ============================================================
// Function: rendering_generateScoreRandom (FUN_680c94f0)
// Address: 680c94f0
// Size: 139 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_generateScoreRandom(int param_1)

{
  uint uVar1;
  int iVar2;
  short sVar3;
  
  if (DAT_68196458 == 0) {
    Ordinal_1050(&DAT_68196458,0x10);
  }
  if ((DAT_68196458 & 1) == 0) {
    uVar1 = DAT_68196458 >> 1;
  }
  else {
    uVar1 = DAT_68196458 >> 1 ^ DAT_6819645c;
  }
  sVar3 = (short)uVar1;
  if ((uVar1 & 1) == 0) {
    uVar1 = uVar1 >> 1;
  }
  else {
    uVar1 = uVar1 >> 1 ^ DAT_6819645c;
  }
  DAT_68196458 = uVar1;
  if (sVar3 < 0) {
    sVar3 = -sVar3;
  }
  if ((short)uVar1 < 0) {
    uVar1 = -uVar1;
  }
  if (param_1 == 0) {
    iVar2 = (short)((short)uVar1 % 0x13) + 1;
  }
  else {
    iVar2 = 0;
  }
  return ((int)sVar3 % 0x58f) * 0x17 + iVar2;
}



// ============================================================
// Function: rendering_configureScoreLayout (FUN_680c9580)
// Address: 680c9580
// Size: 265 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_configureScoreLayout(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  uint uVar3;
  int *unaff_EDI;
  uint local_8;
  
  *(undefined2 *)(unaff_EDI + 0x123) = 100;
  if (param_1 == 0) {
    *(undefined2 *)((int)unaff_EDI + 0x48e) = 0x79f;
    *(undefined2 *)(unaff_EDI + 300) = 0x79f;
  }
  else {
    *(undefined2 *)((int)unaff_EDI + 0x48e) = 0x163c;
    *(undefined2 *)(unaff_EDI + 300) = 0x79f;
  }
  iVar2 = scoreEngine_getChannelField((int)unaff_EDI,1);
  if (iVar2 == 0) {
    unaff_EDI[0x126] = 1;
  }
  else {
    rendering_initSpriteScore();
    *(undefined2 *)(unaff_EDI + 0x126) = *(undefined2 *)(iVar2 + 0x74);
    *(undefined2 *)((int)unaff_EDI + 0x49a) = *(undefined2 *)(iVar2 + 0x76);
  }
  uVar3 = scoreEngine_getFrameRate(unaff_EDI);
  *(short *)((int)unaff_EDI + 0x4c2) = (short)uVar3;
  uVar1 = rendering_updateStageLayout(*(int *)(*unaff_EDI + 0x24));
  *(undefined2 *)(unaff_EDI + 0x12a) = uVar1;
  local_8 = 1;
  strings_clampPolicyRange(&local_8);
  iVar2 = rendering_findMaxSpriteDepth((int)unaff_EDI);
  if (iVar2 < (int)local_8) {
    iVar2 = (int)(short)unaff_EDI[0x12a];
  }
  *(short *)((int)unaff_EDI + 0x4b2) = (short)iVar2;
  *(undefined2 *)(unaff_EDI + 0x131) = 2;
  iVar2 = rendering_generateScoreRandom(param_1);
  *(short *)((int)unaff_EDI + 0x4c6) = (short)iVar2;
  uVar3 = rendering_computeScoreChecksum((short *)(unaff_EDI + 0x123));
  unaff_EDI[0x133] = uVar3;
  unaff_EDI[0x132] = 0x3c;
  return 1;
}



// ============================================================
// Function: rendering_configureSpriteScore (FUN_680c9690)
// Address: 680c9690
// Size: 131 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_configureSpriteScore(void)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int unaff_EBX;
  
  *(undefined2 *)(in_EAX + 0x68) = 100;
  if (unaff_EBX == 0) {
    *(undefined2 *)(in_EAX + 0x6a) = 0x79f;
    *(undefined2 *)(in_EAX + 0x8c) = 0x79f;
  }
  else {
    *(undefined2 *)(in_EAX + 0x6a) = 0x163c;
    *(undefined2 *)(in_EAX + 0x8c) = 0x79f;
  }
  Ordinal_1130(in_EAX + 0x6c,8);
  rendering_initSpriteScore();
  *(undefined2 *)(in_EAX + 0xa0) = 2;
  iVar1 = rendering_generateScoreRandom(unaff_EBX);
  *(short *)(in_EAX + 0xa2) = (short)iVar1;
  uVar2 = rendering_computeScoreChecksum((short *)(in_EAX + 0x68));
  *(uint *)(in_EAX + 0xa8) = uVar2;
  *(undefined4 *)(in_EAX + 0xa4) = 0x3c;
  return 1;
}



// ============================================================
// Function: rendering_iterateSpriteDispatch (FUN_680c9720)
// Address: 680c9720
// Size: 185 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall rendering_iterateSpriteDispatch(void *this,undefined4 param_1)
{
  short sVar1;
  short extraout_var;
  int *piVar3;
  int iVar4;
  short extraout_var_00;
  int unaff_EBX;
  undefined4 local_420 [262];
  uint local_8;
  undefined4 uVar2;
  
  rendering_getSpriteCount(param_1);
  sVar1 = rendering_getCurrentSprite();
  uVar2 = CONCAT22(extraout_var,sVar1);
  sVar1 = extraout_var;
  while( true ) {
    if (sVar1 == 0) {
      return 0;
    }
    piVar3 = (int *)rendering_resolveState(*(int *)((int)this + 0xc),uVar2);
    if ((((piVar3 != (int *)0x0) && (piVar3[2] != 0)) &&
        (iVar4 = rendering_getFrameCount((int)piVar3), iVar4 != 0)) &&
       ((((piVar3[0xb] & 0x2000U) == 0 &&
         (iVar4 = rendering_dispatchUpdate(unaff_EBX,piVar3,local_420,2), iVar4 != 0)) &&
        (iVar4 = rendering_getStatePair((int)piVar3,local_420), iVar4 == 0)))) break;
    sVar1 = rendering_getCurrentSprite();
    uVar2 = CONCAT22(extraout_var_00,sVar1);
    sVar1 = extraout_var_00;
  }
  return 0;
}



// ============================================================
// Function: rendering_resolveAllSprites (FUN_680c97e0)
// Address: 680c97e0
// Size: 64 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall rendering_resolveAllSprites(int param_1)

{
  short sVar1;
  undefined4 in_EAX;
  short extraout_var;
  short extraout_var_00;
  undefined4 uVar2;
  
  rendering_getSpriteCount(in_EAX);
  sVar1 = rendering_getCurrentSprite();
  uVar2 = CONCAT22(extraout_var,sVar1);
  sVar1 = extraout_var;
  while (sVar1 != 0) {
    rendering_resolveState(*(int *)(param_1 + 0xc),uVar2);
    sVar1 = rendering_getCurrentSprite();
    uVar2 = CONCAT22(extraout_var_00,sVar1);
    sVar1 = extraout_var_00;
  }
  return 1;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680c9820 - 0x680c9cf0
// Functions (9):
//   rendering_serializeScoreData
//   rendering_clearSpriteFields
//   rendering_restoreScoreState
//   rendering_getSpriteScoreCount
//   rendering_getSpriteScoreState
//   rendering_updateSpriteScore
//   rendering_submitSpriteScore
//   rendering_copySpriteBlock
//   rendering_transferSpriteScore

// ============================================================
// Function: rendering_serializeScoreData (FUN_680c9820)
// Address: 680c9820
// Size: 206 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_serializeScoreData(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  undefined4 *local_c;
  undefined1 *local_8;
  
  local_8 = (undefined1 *)0x0;
  local_c = (undefined4 *)0x0;
  uVar3 = 0;
  local_8 = (undefined1 *)Ordinal_1126(0x400,0);
  if (local_8 != (undefined1 *)0x0) {
    local_c = (undefined4 *)Ordinal_1126(0x418,0);
    if (local_c != (undefined4 *)0x0) {
      puVar4 = local_c;
      for (iVar2 = 0x106; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar4 = *param_2;
        param_2 = param_2 + 1;
        puVar4 = puVar4 + 1;
      }
      iVar2 = Ordinal_1316(local_c);
      if (iVar2 != 0) {
        Ordinal_1310(local_c,local_8 + 1,0x3ff);
        iVar2 = Ordinal_1201(local_8 + 1);
        iVar1 = iVar2 + 1;
        local_8[iVar1] = *(undefined1 *)((int)local_c + 0xe);
        if (iVar1 < 0xff) {
          *local_8 = (char)iVar1;
        }
        else {
          *local_8 = 0xff;
        }
        iVar2 = Ordinal_37((undefined4 *)(param_1 + 0x46c),3,local_8,iVar2 + 2);
        if (iVar2 != 0) {
          uVar3 = 1;
        }
      }
    }
  }
  Ordinal_1127(&local_c);
  Ordinal_1127(&local_8);
  return uVar3;
}



// ============================================================
// Function: rendering_clearSpriteFields (FUN_680c98f0)
// Address: 680c98f0
// Size: 87 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_clearSpriteFields(int param_1)
{
  short sVar1;
  undefined4 in_EAX;
  short extraout_var;
  int iVar3;
  short extraout_var_00;
  undefined4 uVar2;
  
  rendering_getSpriteCount(in_EAX);
  sVar1 = rendering_getCurrentSprite();
  uVar2 = CONCAT22(extraout_var,sVar1);
  sVar1 = extraout_var;
  while (sVar1 != 0) {
    iVar3 = rendering_resolveState(*(int *)(param_1 + 0xc),uVar2);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 8) != 0)) {
      Ordinal_1130(iVar3 + 0x30,8);
      *(undefined4 *)(iVar3 + 0x34) = 0xffffffff;
    }
    sVar1 = rendering_getCurrentSprite();
    uVar2 = CONCAT22(extraout_var_00,sVar1);
    sVar1 = extraout_var_00;
  }
  return 0;
}



// ============================================================
// Function: rendering_restoreScoreState (FUN_680c9950)
// Address: 680c9950
// Size: 289 bytes
// Params: int * param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_restoreScoreState(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  piVar1 = (int *)*param_1;
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
  pcVar2 = *(code **)(*(int *)(*piVar1 + 0xc) + 0xd0);
  local_8 = 0;
  local_38 = 0;
  if (pcVar2 != (code *)0x0) {
    local_c = 0;
    (*pcVar2)(*piVar1,(short)param_1[1],0xffffffff,0,0,0,&local_c);
    if ((local_c != 0) && (iVar3 = lingo_getMovieRef((int)piVar1), iVar3 != 0)) {
      lingo_formatDebugMsg(piVar1,local_c);
      return 0;
    }
  }
  if (((param_1[5] == 0) && (param_1[0xc] != 0)) &&
     (puVar4 = (undefined4 *)Ordinal_1114(param_1[0xc]), puVar4 != (undefined4 *)0x0)) {
    for (iVar3 = 0x106; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *param_3;
      param_3 = param_3 + 1;
      puVar4 = puVar4 + 1;
    }
    Ordinal_1115(param_1[0xc]);
  }
  local_2c = *param_1;
  local_14 = CONCAT22((*(unsigned short *)((char *)&local_14 + 2)),(short)param_1[1]);
  rendering_initSpriteScore();
  iVar3 = rendering_getChannelBlock(param_1);
  if (((iVar3 != 0) && (iVar3 = rendering_resolveAllSprites((int)&local_38), iVar3 != 0)) &&
     (iVar3 = rendering_iterateSpriteDispatch(&local_38,2), iVar3 != 0)) {
    param_1[0x36] = (uint)((short)param_1[0x23] < 0x79f);
    iVar3 = rendering_configureSpriteScore();
    if (iVar3 != 0) {
      return 1;
    }
  }
  return local_8;
}



// ============================================================
// Function: rendering_getSpriteScoreCount (FUN_680c9a80)
// Address: 680c9a80
// Size: 94 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getSpriteScoreCount(void)
{
  int iVar1;
  int *unaff_ESI;
  undefined4 unaff_EDI;
  
  iVar1 = lingo_getMovieRef((int)unaff_ESI);
  if (iVar1 == 0) {
    switch(unaff_EDI) {
    case 0:
      break;
    default:
      lingo_formatDebugMsg(unaff_ESI,-0x1c2);
      break;
    case 2:
      lingo_formatDebugMsg(unaff_ESI,-0x1c3);
      return 0;
    case 4:
      lingo_formatDebugMsg(unaff_ESI,-0x1c5);
      return 0;
    case 6:
      lingo_formatDebugMsg(unaff_ESI,-0x7a);
      return 0;
    case 8:
      lingo_formatDebugMsg(unaff_ESI,-0x1c4);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_getSpriteScoreState (FUN_680c9b10)
// Address: 680c9b10
// Size: 106 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getSpriteScoreState(void)
{
  int iVar1;
  int unaff_ESI;
  int *unaff_EDI;
  
  iVar1 = lingo_getMovieRef((int)unaff_EDI);
  if (iVar1 == 0) {
    if (unaff_ESI < -0x2a) {
      if (unaff_ESI != -0x2b) {
        if (unaff_ESI == -0x6c) {
LAB_680c9b5f:
          lingo_formatDebugMsg(unaff_EDI,-0x7a);
          return 0;
        }
        if ((unaff_ESI != -0x31) && (unaff_ESI != -0x2f)) {
LAB_680c9b50:
          lingo_formatDebugMsg(unaff_EDI,-0x1c2);
          return 0;
        }
      }
      lingo_formatDebugMsg(unaff_EDI,-0x1c3);
      return 0;
    }
    if (unaff_ESI == -0x22) {
      lingo_formatDebugMsg(unaff_EDI,-0x1c5);
    }
    else if (unaff_ESI != 0) {
      if (unaff_ESI != 0xd1) goto LAB_680c9b50;
      goto LAB_680c9b5f;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_updateSpriteScore (FUN_680c9b80)
// Address: 680c9b80
// Size: 37 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_updateSpriteScore(int param_1,int param_2,int param_3)
{
  int in_EAX;
  
  if (param_3 != 0) {
    strings_readMediaChunk(*(int *)(param_2 + 4),in_EAX,param_1);
    return 0;
  }
  strings_openMediaStream(*(int *)(param_2 + 4),in_EAX,param_1);
  return 0;
}



// ============================================================
// Function: rendering_submitSpriteScore (FUN_680c9bb0)
// Address: 680c9bb0
// Size: 183 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_submitSpriteScore(void)
{
  uint uVar1;
  int iVar2;
  int unaff_EBX;
  int *unaff_ESI;
  
  if (((((*(byte *)(unaff_ESI + 0xe) & 10) == 0) &&
       (iVar2 = rendering_getChannelSprite(*unaff_ESI,(short)unaff_ESI[1]), *(int *)(iVar2 + 0xd8) == 0)) &&
      (*(int *)(unaff_EBX + 0xba4) != 0)) && ((unaff_ESI[2] == 1 && (unaff_ESI[0x18] == 0x20)))) {
    rendering_initState((int *)&stack0xffffffb8);
  }
  return 0;
}



// ============================================================
// Function: rendering_copySpriteBlock (FUN_680c9c70)
// Address: 680c9c70
// Size: 114 bytes
// Params: void * this, int param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall rendering_copySpriteBlock(void *this,int param_1)

{
  int iVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int *local_8;
  
  iVar1 = in_EAX[0xd];
  iVar4 = 0;
  local_8 = (int *)0x0;
  iVar2 = rendering_getMemberPropertyRef(in_EAX,(int *)&local_8,(int)this);
  if (0 < iVar2) {
    do {
      iVar3 = strings_readMediaChunk(param_1,*(int *)(*local_8 + iVar4 * 4),iVar1);
      if (iVar3 == -1) {
        Ordinal_1113(&local_8);
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  Ordinal_1113(&local_8);
  return 1;
}



// ============================================================
// Function: rendering_transferSpriteScore (FUN_680c9cf0)
// Address: 680c9cf0
// Size: 211 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_transferSpriteScore(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  undefined4 local_10;
  int *local_c;
  int local_8;
  
  local_c = (int *)0x0;
  iVar1 = rendering_getMemberPropertyRef(unaff_EBX,(int *)&local_c,in_EAX);
  if (iVar1 == 0) {
    Ordinal_1113(&local_c);
    return 1;
  }
  local_10 = 1;
  local_8 = 0;
  if (0 < iVar1) {
    do {
      iVar3 = *(int *)(*local_c + local_8 * 4);
      iVar2 = rendering_updateSpriteScore(unaff_EBX[3],param_2,0);
      if ((iVar2 != -1) &&
         ((iVar3 == FOURCC_snd || (iVar3 = crt_searchChunkByType(*(int *)(param_2 + 4),iVar2), iVar3 != 0))))
      {
        iVar3 = rendering_updateSpriteScore(unaff_EBX[0xd],param_1,1);
        if (iVar3 == -1) break;
        iVar3 = crt_copyChunkBetween(*(int **)(param_2 + 4),iVar2,*(int *)(param_1 + 4),iVar3);
        if (iVar3 != 0) {
          local_10 = 0;
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 < iVar1);
  }
  Ordinal_1113(&local_c);
  return local_10;
}



