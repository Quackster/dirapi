// Module: rendering
// Topic: Channel property mapping, cast lib management, event notification, and palette tables
// Address range: 0x680cD920 - 0x680cFFE0
// Functions (65):
//   rendering_dispatchChannelOp
//   rendering_getChannelBlend
//   rendering_getChannelInk
//   rendering_getChannelTempo
//   rendering_loadChannelSprite
//   rendering_applyChannelCast
//   rendering_getChannelType
//   rendering_resolveChannelType
//   rendering_refreshChannel
//   rendering_updateChannelState
//   rendering_initChannelState
//   rendering_processChannelMediaEvents
//   rendering_findNextChannelSprite
//   rendering_getChannelSprite
//   rendering_getChannelState
//   rendering_addChannelSpriteRef
//   rendering_getChannelInfo
//   rendering_getChannelDataEx
//   rendering_initChannelDefaults
//   rendering_getChannelFormat
//   rendering_getChannelDepth
//   rendering_findChannelByName
//   rendering_getChannelRect
//   rendering_getLastChannelFrame
//   rendering_getChannelMode
//   rendering_getFirstChannelFrame
//   rendering_getFirstActiveFrame
//   rendering_getChannelLock
//   rendering_writeChannelBlock
//   rendering_getChannelIndex
//   rendering_getChannelSlot
//   rendering_getChannelBlock
//   rendering_validateChannelScript
//   rendering_validateChannelMembers
//   rendering_insertChannelEvent
//   rendering_destroyChannelSpriteData
//   rendering_setChannelProperty
//   rendering_resetChannelSprite
//   rendering_deduplicateChannelEvent
//   rendering_dispatchChannelNotification
//   rendering_getChannelProperty
//   rendering_flushChannelEvents
//   rendering_getChannelSize
//   rendering_releaseChannelHandle
//   rendering_getChannelWidth
//   rendering_getChannelVisibility
//   rendering_getChannelFlags
//   rendering_compareChannelData
//   rendering_getChannelSpriteName
//   rendering_writeChannelScoreData
//   rendering_computePaletteHash
//   rendering_lookupPaletteCache
//   rendering_buildChannelMap
//   rendering_buildChannelReverseMap
//   rendering_buildChannelScoreMap
//   rendering_buildChannelScoreReverseMap
//   rendering_getChannelHeight
//   rendering_getChannelDefaultHeight
//   rendering_processChannelEvent
//   rendering_setChannelRect
//   rendering_resolveChannelHeight
//   rendering_writeChannelData
//   rendering_convertChannelFontData
//   rendering_importChannelSpriteData
//   rendering_setChannelProperty

// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680cd920 - 0x680ce160
// Functions (10):
//   rendering_dispatchChannelOp
//   rendering_getChannelBlend
//   rendering_getChannelInk
//   rendering_getChannelTempo
//   rendering_setChannelProperty
//   rendering_loadChannelSprite
//   rendering_applyChannelCast
//   rendering_getChannelType
//   rendering_resolveChannelType
//   rendering_refreshChannel

// ============================================================
// Function: rendering_dispatchChannelOp (FUN_680cd920)
// Address: 680cd920
// Size: 793 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_dispatchChannelOp(int param_1,int param_2,int *param_3)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int *local_b30;
  undefined4 local_b2c;
  int local_b28;
  int local_b24 [3];
  undefined1 local_b18 [2048];
  undefined4 local_318 [196];
  uint local_8;
  
  piVar2 = *(int **)(param_1 + 0x18);
  iVar3 = *(int *)(param_1 + 0x20);
  local_b2c = param_2;
  local_b28 = 0;
  local_b30 = (int *)0x0;
  bVar4 = false;
  lingo_executeMethod((int)piVar2,local_318);
  if (((int)param_3 < 1) || (8 < (int)param_3)) {
    param_3 = (int *)0x8;
  }
  do {
    if ((*(unsigned short *)((char *)&local_b2c + 2)) < 1) {
LAB_680cda01:
      if (param_3 == (int *)0x1) {
        local_b28 = *(int *)(*(int *)(param_1 + 0x20) + 0x618);
        goto LAB_680cdb98;
      }
      if (param_3 == (int *)0x2) {
        local_b28 = *(int *)(*(int *)(param_1 + 0x20) + 0x61c);
        goto LAB_680cdb98;
      }
      piVar5 = (int *)(iVar3 + 0x614);
      iVar6 = 1 << ((byte)param_3 & 0x1f);
      if (*(int *)(iVar3 + 0x614) != 0) {
        local_b30 = (int *)Ordinal_1114(*(int *)(iVar3 + 0x614));
        iVar7 = 0;
        if (0 < *(int *)(iVar3 + 0x60c)) {
          do {
            if ((((short)local_b30[1] == (short)local_b2c) &&
                (*(short *)((int)local_b30 + 6) == (*(unsigned short *)((char *)&local_b2c + 2)))) &&
               ((int *)local_b30[2] == param_3)) {
              local_b28 = *local_b30;
              goto LAB_680cdb98;
            }
            iVar7 = iVar7 + 1;
            local_b30 = local_b30 + 3;
          } while (iVar7 < *(int *)(iVar3 + 0x60c));
        }
        Ordinal_1115(*piVar5);
        local_b30 = (int *)0x0;
      }
      iVar7 = rendering_processStagePalette(param_1,local_b2c,local_b24,param_3);
      if (iVar7 == 0) goto LAB_680cdb98;
      local_b28 = Ordinal_1730(iVar6);
      if (local_b28 != 0) {
        iVar6 = Ordinal_1737(local_b28,0,local_b18,iVar6);
        if (iVar6 != 0) {
          if (*piVar5 == 0) {
            iVar6 = Ordinal_1111(0xc,0);
            *piVar5 = iVar6;
            if (iVar6 == 0) goto LAB_680cdb98;
            *(undefined4 *)(iVar3 + 0x60c) = 0;
            *(undefined4 *)(iVar3 + 0x610) = 1;
          }
          if (*(int *)(iVar3 + 0x60c) == *(int *)(iVar3 + 0x610)) {
            iVar6 = *(int *)(iVar3 + 0x610) + 1;
            iVar7 = Ordinal_1117(piVar5,iVar6 * 0xc,0);
            if (iVar7 == 0) goto LAB_680cdb98;
            *(int *)(iVar3 + 0x610) = iVar6;
          }
          iVar6 = *(int *)(iVar3 + 0x60c);
          iVar7 = Ordinal_1114(*piVar5);
          piVar1 = (int *)(iVar7 + iVar6 * 0xc);
          piVar1[1] = local_b2c;
          piVar1[2] = (int)param_3;
          *piVar1 = local_b28;
          *(int *)(iVar3 + 0x60c) = *(int *)(iVar3 + 0x60c) + 1;
          Ordinal_1115(*piVar5);
          local_b30 = (int *)0x0;
        }
        goto LAB_680cdb98;
      }
    }
    else {
      piVar5 = (int *)rendering_resolveState((int)piVar2,local_b2c);
      if ((piVar5 == (int *)0x0) || (piVar5[2] != 4)) {
        local_b2c = *(int *)(*(int *)(param_1 + 0x24) + 0x30);
        piVar5 = (int *)rendering_resolveState((int)piVar2,local_b2c);
      }
      if (piVar5 == (int *)0x0) goto LAB_680cda01;
      if ((piVar5[0x12] != 0) || (iVar6 = rendering_getMemberData(param_1,piVar5), iVar6 != 0)) {
        local_b28 = piVar5[0x15];
      }
LAB_680cdb98:
      if (local_b28 != 0) goto LAB_680cdc0f;
    }
    if (bVar4) {
      lingo_formatDebugMsg(piVar2,-0x7a);
LAB_680cdc0f:
      if (local_b30 != (int *)0x0) {
        Ordinal_1115(*(undefined4 *)(iVar3 + 0x614));
      }
      return 0;
    }
    local_b2c = strings_getDefaultCastType();
    local_b2c = local_b2c << 0x10;
    lingo_dispatchMethod((int)piVar2,local_318);
    bVar4 = true;
  } while( true );
}



// ============================================================
// Function: rendering_getChannelBlend (FUN_680cdc40)
// Address: 680cdc40
// Size: 72 bytes
// Params: uint param_1
// Return: byte
// Calling convention: __stdcall
// ============================================================

byte rendering_getChannelBlend(uint param_1)

{
  int iVar1;
  uint extraout_EDX;
  uint unaff_ESI;
  
  iVar1 = rendering_getStageFlags(param_1);
  if (iVar1 != 0) {
    return (byte)(param_1 >> 0x18) & 0x7f;
  }
  iVar1 = rendering_comparePaletteEntry(unaff_ESI,extraout_EDX);
  if (iVar1 != 0) {
    iVar1 = scoreEngine_setChannelField(unaff_ESI,param_1);
    return *(byte *)(iVar1 + 0x82);
  }
  return 0;
}



// ============================================================
// Function: rendering_getChannelInk (FUN_680cdc90)
// Address: 680cdc90
// Size: 66 bytes
// Params: uint param_1
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 rendering_getChannelInk(uint param_1)

{
  int iVar1;
  uint extraout_EDX;
  uint unaff_ESI;
  
  iVar1 = rendering_getStageFlags(param_1);
  if (iVar1 != 0) {
    return (*(unsigned char *)((char *)&param_1 + 2));
  }
  iVar1 = rendering_comparePaletteEntry(unaff_ESI,extraout_EDX);
  if (iVar1 != 0) {
    iVar1 = scoreEngine_setChannelField(unaff_ESI,param_1);
    return *(undefined1 *)(iVar1 + 0x81);
  }
  return 0;
}



// ============================================================
// Function: rendering_getChannelTempo (FUN_680cdce0)
// Address: 680cdce0
// Size: 80 bytes
// Params: uint param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint rendering_getChannelTempo(uint param_1)

{
  int iVar1;
  uint extraout_EDX;
  uint unaff_ESI;
  
  iVar1 = rendering_getStageFlags(param_1);
  if (iVar1 != 0) {
    return (extraout_EDX & 0xff) * 0xfa;
  }
  iVar1 = rendering_comparePaletteEntry(unaff_ESI,extraout_EDX);
  if (iVar1 != 0) {
    iVar1 = scoreEngine_setChannelField(unaff_ESI,param_1);
    return (uint)*(ushort *)(iVar1 + 0x84);
  }
  return 0;
}



// ============================================================
// Function: rendering_setChannelProperty (FUN_680cdd30)
// Address: 680cdd30
// Size: 119 bytes
// Params: int * param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_setChannelProperty(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  undefined4 local_c [2];
  
  rendering_applyStageOffset(param_1,param_2,param_3);
  if (((short)param_3 == *(short *)(param_2 + 0x34)) &&
     ((*(unsigned short *)((char *)&param_3 + 2)) == *(short *)(param_2 + 0x36))) {
    return 0;
  }
  uVar1 = Ordinal_1610(*(undefined4 *)(param_2 + 0x94));
  Ordinal_1836(*(undefined4 *)(param_2 + 4),uVar1);
  local_c[0] = param_3;
  rendering_getChannelProperty((int)param_1,0x11,local_c);
  *(undefined4 *)(param_2 + 0x34) = param_3;
  return 1;
}



// ============================================================
// Function: rendering_loadChannelSprite (FUN_680cddb0)
// Address: 680cddb0
// Size: 625 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_loadChannelSprite(int *param_1,uint param_2)
{
  short sVar1;
  int *piVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *local_24;
  int *local_20;
  int *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (param_1 != (int *)0x0) {
    local_1c = (int *)param_1[8];
    piVar7 = (int *)param_1[9];
    local_20 = piVar7;
    rendering_getStageData2(piVar7);
    iVar4 = rendering_getStageFlags(param_2);
    if (iVar4 == 0) {
      local_24 = (int *)scoreEngine_setChannelField((uint)local_1c,param_2);
      iVar4 = rendering_getMemberData(param_1,local_24);
      if (iVar4 == 0) goto LAB_680ce00c;
      piVar7[0x22] = local_24[1];
    }
    iVar4 = rendering_blendPaletteEntry((uint)local_1c,param_2);
    if (iVar4 == 0) {
      rendering_buildDirtyRegion((int)piVar7,&local_18);
    }
    else {
      Ordinal_1060(&local_18,0,0,piVar7[4],piVar7[5]);
    }
    iVar4 = rendering_convertPaletteEntry((uint)local_1c,param_2);
    piVar2 = local_1c;
    if (iVar4 == 0) {
      iVar4 = scoreEngine_setChannelField((uint)local_1c,param_2);
      iVar6 = Ordinal_1111(0x7c,3);
      if (iVar6 != 0) {
        piVar7 = (int *)Ordinal_1114(iVar6);
        local_20[0x23] = (int)piVar7;
        *piVar7 = iVar6;
        iVar6 = media_dispatchGetStatus((int)param_1,*(int **)(iVar4 + 0x54),piVar7 + 3);
        if (iVar6 == 0) {
          local_24 = param_1;
          iVar6 = crt_resolveLinkedImageData((int *)&local_24,piVar7 + 4);
          if (iVar6 == 0) {
            piVar7[0x1d] = 1;
            iVar6 = crt_resolveImageData((int *)&local_24,piVar7 + 0xb);
            if (iVar6 == 0) {
              piVar7[0x1e] = 1;
              piVar7[0x12] = (uint)*(byte *)(iVar4 + 0x81);
              sVar1 = *(short *)(iVar4 + 0x84);
              piVar7[0x14] = 1;
              piVar7[0x13] = (int)sVar1;
              piVar7[0x17] = local_14;
              piVar7[0x18] = local_18;
              piVar7[0x19] = local_c;
              piVar7[0x1a] = local_10;
              iVar4 = media_callSpriteMethod(param_1[6],(int *)piVar7[3],piVar7 + 0xb,piVar7 + 4,piVar7 + 0x17
                                   ,piVar7 + 0x12);
              if (iVar4 == 0) {
                iVar4 = Ordinal_1541();
                piVar7[1] = iVar4;
                piVar7[0x1b] = 1;
                goto LAB_680ce00c;
              }
            }
          }
        }
        piVar7 = local_20;
        rendering_getStageProperty(*local_1c,(int)local_20);
        rendering_getStageData2(piVar7);
      }
    }
    else {
      bVar3 = rendering_getChannelBlend(param_2);
      if (('\0' < (char)bVar3) && (bVar3 < 0x36)) {
        piVar7[0xe] = local_20[1];
        piVar7[0xf] = 0;
        piVar7[0x10] = 0;
        piVar7[0x11] = local_20[0x25];
        piVar7[0x12] = local_18;
        piVar7[0x13] = local_14;
        piVar7[0x14] = local_10;
        piVar7[0x15] = local_c;
        piVar7[0x16] = *(int *)(&DAT_6818e5e8 + (char)bVar3 * 8);
        piVar7[0x17] = *(int *)(&DAT_6818e5ec + (char)bVar3 * 8);
        bVar3 = rendering_getChannelInk(param_2);
        piVar7[0x18] = (uint)bVar3;
        uVar5 = rendering_getChannelTempo(param_2);
        piVar7[0x19] = (int)(short)uVar5;
        iVar4 = Ordinal_1292(piVar7 + 0xe);
        if (iVar4 == 0) {
          rendering_getStageProperty(*piVar2,(int)local_20);
        }
        else {
          local_20[0xb] = 0;
        }
      }
    }
  }
LAB_680ce00c:
  return 0;
}



// ============================================================
// Function: rendering_applyChannelCast (FUN_680ce030)
// Address: 680ce030
// Size: 32 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_applyChannelCast(int *param_1,int param_2)
{
  undefined4 uVar1;
  
  uVar1 = scoreEngine_commitScoreEdit((int *)param_1[8]);
  rendering_setChannelProperty(param_1,param_2,uVar1);
  return 0;
}



// ============================================================
// Function: rendering_getChannelType (FUN_680ce050)
// Address: 680ce050
// Size: 23 bytes
// Params: int param_1
// Return: short
// Calling convention: __stdcall
// ============================================================

short rendering_getChannelType(int param_1)

{
  short sVar1;
  
  sVar1 = *(short *)(param_1 + 0x24);
  if (sVar1 == 0) {
    sVar1 = *(short *)(param_1 + 2);
  }
  return sVar1;
}



// ============================================================
// Function: rendering_resolveChannelType (FUN_680ce070)
// Address: 680ce070
// Size: 235 bytes
// Params: uint param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_resolveChannelType(uint param_1)

{
  if (0x79e < param_1) {
    return 0x1201;
  }
  if (0x782 < param_1) {
    return 0x1200;
  }
  if (0x781 < param_1) {
    return 0x1150;
  }
  if (0x780 < param_1) {
    return 0x1100;
  }
  if (0x73a < param_1) {
    return 0x1000;
  }
  if (0x6a3 < param_1) {
    return 0x850;
  }
  if (0x581 < param_1) {
    return 0x800;
  }
  if (0x4c7 < param_1) {
    return 0x700;
  }
  if (0x4c1 < param_1) {
    return 0x600;
  }
  if (0x4b0 < param_1) {
    return 0x500;
  }
  if (0x45c < param_1) {
    return 0x404;
  }
  if (0x45a < param_1) {
    return 0x400;
  }
  if (0x404 < param_1) {
    return 0x310;
  }
  return (-(uint)(param_1 < 0x404) & 0xffffff00) + 0x300;
}



// ============================================================
// Function: rendering_refreshChannel (FUN_680ce160)
// Address: 680ce160
// Size: 14 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_refreshChannel(int param_1)

{
  return (int)*(short *)(param_1 + 0x38);
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680ce170 - 0x680ce6b0
// Functions (13):
//   rendering_updateChannelState
//   rendering_initChannelState
//   rendering_processChannelMediaEvents
//   rendering_findNextChannelSprite
//   rendering_getChannelSprite
//   rendering_getChannelState
//   rendering_addChannelSpriteRef
//   rendering_getChannelInfo
//   rendering_getChannelDataEx
//   rendering_initChannelDefaults
//   rendering_getChannelFormat
//   rendering_getChannelDepth
//   rendering_findChannelByName

// ============================================================
// Function: rendering_updateChannelState (FUN_680ce170)
// Address: 680ce170
// Size: 25 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_updateChannelState(int param_1)
{
  ushort uVar1;
  
  uVar1 = rendering_getChannelType(param_1);
  rendering_resolveChannelType((uint)uVar1);
  return 0;
}



// ============================================================
// Function: rendering_initChannelState (FUN_680ce190)
// Address: 680ce190
// Size: 34 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_initChannelState(undefined4 *param_1)
{
  *(undefined2 *)(param_1 + 0x14) = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0xffffffff;
  lingo_getDebugState((int *)*param_1);
  return 0;
}



// ============================================================
// Function: rendering_processChannelMediaEvents (FUN_680ce1c0)
// Address: 680ce1c0
// Size: 208 bytes
// Params: byte * param_1, undefined4 param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_processChannelMediaEvents(byte *param_1,undefined4 param_2,short param_3)
{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int *unaff_ESI;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  local_c = 0;
  if ((unaff_ESI != (int *)0x0) && (unaff_ESI[0x10] != 0)) {
    Ordinal_1165(unaff_ESI[0x10],&local_8,&param_2,*(undefined4 *)(*unaff_ESI + 0x36c),*unaff_ESI);
    uVar2 = Ordinal_1154(unaff_ESI[0x10]);
    uVar1 = local_8;
    if (uVar2 != 0) {
      while (((uVar1 < uVar2 &&
              (piVar3 = (int *)Ordinal_1156(unaff_ESI[0x10],unaff_ESI[0x11],uVar1),
              piVar3 != (int *)0x0)) && (*(short *)((int)piVar3 + 6) <= param_3))) {
        *(short *)(unaff_ESI + 0x14) = *(short *)((int)piVar3 + 6);
        unaff_ESI[0x15] = (int)piVar3;
        rendering_processMediaOp(param_1,*unaff_ESI,piVar3,1);
        local_c = uVar1;
        uVar1 = uVar1 + 1;
      }
      Ordinal_1158(unaff_ESI[0x10],unaff_ESI[0x11]);
      Ordinal_1161(unaff_ESI[0x10],local_8,local_c);
      Ordinal_1169(unaff_ESI[0x10]);
      iVar4 = Ordinal_1157(unaff_ESI[0x10]);
      unaff_ESI[0x11] = iVar4;
      rendering_initChannelState(unaff_ESI);
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_findNextChannelSprite (FUN_680ce290)
// Address: 680ce290
// Size: 109 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_findNextChannelSprite(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  int local_8;
  
  local_8 = 0;
  uVar1 = Ordinal_1154(*(undefined4 *)(param_1 + 0x318));
  if (param_2 == 0) {
    uVar2 = 1;
  }
  else {
    uVar2 = (int)*(short *)(param_2 + 4) + 1;
  }
  while ((uVar2 < uVar1 &&
         ((Ordinal_1155(*(undefined4 *)(param_1 + 0x318),uVar2,&local_8), local_8 == 0 ||
          (*(int *)(local_8 + 8) < 1))))) {
    uVar2 = uVar2 + 1;
  }
  if (uVar2 == uVar1) {
    local_8 = 0;
  }
  return local_8;
}



// ============================================================
// Function: rendering_getChannelSprite (rendering_getChannelSprite)
// Address: 680ce300
// Size: 123 bytes
// Params: int param_1, short param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_getChannelSprite(int param_1,short param_2)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  iVar2 = 0;
  if (0 < param_2) {
    if (param_2 == *(short *)(param_1 + 0x344)) {
      return *(int *)(param_1 + 0x348);
    }
    if ((uint)(int)param_2 < *(uint *)(param_1 + 0x31c)) {
      iVar1 = Ordinal_1155(*(undefined4 *)(param_1 + 0x318),(int)param_2,&local_8);
      iVar2 = local_8;
      if ((iVar1 != 0) && (local_8 != 0)) {
        if (*(short *)(local_8 + 4) == 0) {
          return 0;
        }
        *(short *)(param_1 + 0x344) = param_2;
        *(int *)(param_1 + 0x348) = local_8;
      }
    }
  }
  return iVar2;
}



// ============================================================
// Function: rendering_getChannelState (FUN_680ce380)
// Address: 680ce380
// Size: 23 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getChannelState(int *param_1)
{
  rendering_getChannelSprite(*param_1,(short)param_1[1]);
  return 0;
}



// ============================================================
// Function: rendering_addChannelSpriteRef (FUN_680ce3a0)
// Address: 680ce3a0
// Size: 41 bytes
// Params: int param_1, short param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_addChannelSpriteRef(int param_1,short param_2)

{
  int iVar1;
  
  iVar1 = rendering_getChannelSprite(param_1,param_2);
  if (iVar1 != 0) {
    *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_getChannelInfo (FUN_680ce3d0)
// Address: 680ce3d0
// Size: 220 bytes
// Params: int param_1, int * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint rendering_getChannelInfo(int param_1,int *param_2)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int local_c;
  int *local_8;
  
  uVar2 = *(uint *)(param_1 + 0x31c);
  uVar4 = 1;
  local_8 = (int *)0x0;
  if (1 < uVar2) {
    do {
      Ordinal_1155(*(undefined4 *)(param_1 + 0x318),uVar4,&local_c);
      if (local_c == 0) break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  *param_2 = param_1;
  *(short *)(param_2 + 1) = (short)uVar4;
  param_2[2] = 1;
  param_2[0x33] = 0;
  local_8 = (int *)Ordinal_1124(0xdc);
  piVar5 = local_8;
  for (iVar3 = 0x37; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar5 = *param_2;
    param_2 = param_2 + 1;
    piVar5 = piVar5 + 1;
  }
  if (uVar4 == uVar2) {
    iVar3 = Ordinal_1152(*(undefined4 *)(param_1 + 0x318),&local_8);
    uVar1 = Ordinal_1154(*(undefined4 *)(param_1 + 0x318));
    *(undefined4 *)(param_1 + 0x31c) = uVar1;
    uVar2 = 0;
    *(undefined2 *)(param_1 + 0x344) = 0xffff;
    *(undefined4 *)(param_1 + 0x348) = 0;
    if (iVar3 == 0) {
      return uVar2;
    }
  }
  else {
    uVar2 = Ordinal_1159(*(undefined4 *)(param_1 + 0x318),uVar4,&local_8);
  }
  return CONCAT22((short)(uVar2 >> 0x10),(short)uVar4);
}



// ============================================================
// Function: rendering_getChannelDataEx (FUN_680ce4b0)
// Address: 680ce4b0
// Size: 293 bytes
// Params: int param_1, int param_2, undefined4 * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getChannelDataEx(int param_1,int param_2,undefined4 *param_3,int param_4)
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  int local_e8;
  int local_e4 [5];
  undefined4 local_d0;
  int local_c8;
  int local_b4;
  undefined4 local_a8;
  undefined4 local_98;
  undefined4 local_7c [29];
  uint local_8;
  
  local_e8 = 0;
  Ordinal_1130(local_e4,0xdc);
  local_a8 = 0x400;
  if (param_2 == 0) {
    local_c8 = param_4;
    local_d0 = 1;
    puVar1 = (undefined4 *)(param_4 + 0x48c);
    puVar4 = local_7c;
    for (iVar3 = 0x19; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar4 = *puVar1;
      puVar1 = puVar1 + 1;
      puVar4 = puVar4 + 1;
    }
    local_98 = Ordinal_1111(0,1);
LAB_680ce58c:
    uVar2 = rendering_getChannelInfo(param_1,local_e4);
    if (((short)uVar2 != 0) && (iVar3 = rendering_getChannelSprite(param_1,(short)uVar2), iVar3 != 0))
    goto LAB_680ce5c0;
  }
  else {
    local_e8 = Ordinal_1111(0x418,0);
    if (local_e8 != 0) {
      puVar1 = (undefined4 *)Ordinal_1114(local_e8);
      if (param_3 == (undefined4 *)0x0) {
        Ordinal_1309(puVar1,0x400,"",2);
      }
      else {
        for (iVar3 = 0x106; iVar3 != 0; iVar3 = iVar3 + -1) {
          *puVar1 = *param_3;
          param_3 = param_3 + 1;
          puVar1 = puVar1 + 1;
        }
      }
      Ordinal_1115(local_e8);
      local_d0 = 0;
      local_b4 = local_e8;
      goto LAB_680ce58c;
    }
  }
  Ordinal_1113(&local_e8);
LAB_680ce5c0:
  return 0;
}



// ============================================================
// Function: rendering_initChannelDefaults (FUN_680ce5e0)
// Address: 680ce5e0
// Size: 52 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_initChannelDefaults(void)

{
  int unaff_ESI;
  
  Ordinal_1130((undefined2 *)(unaff_ESI + 0x68),100);
  *(undefined2 *)(unaff_ESI + 0x68) = 100;
  *(undefined2 *)(unaff_ESI + 0x6a) = 0x79f;
  *(undefined2 *)(unaff_ESI + 0x8c) = 0x79f;
  *(undefined4 *)(unaff_ESI + 0x74) = 1;
  return 1;
}



// ============================================================
// Function: rendering_getChannelFormat (FUN_680ce620)
// Address: 680ce620
// Size: 102 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getChannelFormat(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_1 != 0) {
    rendering_initChannelDefaults();
    iVar1 = Ordinal_1150(0x14,0x14,0xa8);
    *(int *)(param_1 + 0x40) = iVar1;
    if (iVar1 != 0) {
      uVar2 = Ordinal_1157(iVar1);
      *(undefined4 *)(param_1 + 0x44) = uVar2;
      puVar3 = (undefined4 *)(param_1 + 0x4c);
      playback_initFontMapEx();
      uVar2 = Ordinal_1111(0,1,puVar3);
      *(undefined4 *)(param_1 + 0x4c) = uVar2;
      *(undefined4 *)(param_1 + 0x48) = 0;
      *(undefined4 *)(param_1 + 0xc) = 1;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_getChannelDepth (FUN_680ce690)
// Address: 680ce690
// Size: 29 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_getChannelDepth(int param_1)

{
  if (*(int *)(param_1 + 0x14) != 0) {
    return *(int *)(param_1 + 0x1c) + 0xc;
  }
  return param_1 + 0x20;
}



// ============================================================
// Function: rendering_findChannelByName (FUN_680ce6b0)
// Address: 680ce6b0
// Size: 292 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_findChannelByName(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  int local_428;
  int local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  local_424 = 0;
  local_428 = 0;
  if ((*(int *)(param_1 + 0x318) != 0) && (param_2 != (undefined4 *)0x0)) {
    iVar1 = *(int *)(param_1 + 0x31c);
    puVar4 = param_2;
    puVar5 = local_420;
    for (iVar3 = 0x106; iVar3 != 0; iVar3 = iVar3 + -1) {
      *puVar5 = *puVar4;
      puVar4 = puVar4 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar3 = media_getDataPtr(*(int **)(param_1 + 4));
    iVar6 = 0;
    if (((iVar3 != 0) && (*(code **)(iVar3 + 8) != (code *)0x0)) &&
       (iVar3 = (**(code **)(iVar3 + 8))(param_2,local_420,&local_428,1,0), iVar3 == 0)) {
      local_428 = 0;
    }
    if (0 < iVar1) {
      do {
        iVar3 = Ordinal_1155(*(undefined4 *)(param_1 + 0x318),iVar6,&local_424);
        if (((iVar3 != 0) && (local_424 != 0)) && (*(int *)(local_424 + 0x30) != 0)) {
          uVar2 = Ordinal_1114(*(undefined4 *)(local_424 + 0x30));
          iVar3 = Ordinal_1319(uVar2,local_420);
          Ordinal_1115(*(undefined4 *)(local_424 + 0x30));
          if ((local_428 == *(int *)(local_424 + 0x38)) && (iVar3 != 0)) break;
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < iVar1);
    }
  }
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680ce7e0 - 0x680ced00
// Functions (12):
//   rendering_getChannelRect
//   rendering_getLastChannelFrame
//   rendering_getChannelMode
//   rendering_getFirstChannelFrame
//   rendering_getFirstActiveFrame
//   rendering_getChannelLock
//   rendering_writeChannelBlock
//   rendering_getChannelIndex
//   rendering_getChannelSlot
//   rendering_getChannelBlock
//   rendering_validateChannelScript
//   rendering_validateChannelMembers

// ============================================================
// Function: rendering_getChannelRect (FUN_680ce7e0)
// Address: 680ce7e0
// Size: 43 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_getChannelRect(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = rendering_findChannelByName(param_1,param_2);
  if (iVar1 != 0) {
    rendering_addChannelSpriteRef(param_1,*(short *)(iVar1 + 4));
  }
  return iVar1;
}



// ============================================================
// Function: rendering_getLastChannelFrame (FUN_680ce810)
// Address: 680ce810
// Size: 65 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 rendering_getLastChannelFrame(int param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x40) != 0)) {
    iVar1 = Ordinal_1154(*(int *)(param_1 + 0x40));
    iVar1 = Ordinal_1156(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),iVar1 + -1)
    ;
    if (iVar1 != 0) {
      return *(undefined2 *)(iVar1 + 6);
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_getChannelMode (FUN_680ce860)
// Address: 680ce860
// Size: 104 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 rendering_getChannelMode(int param_1)

{
  int iVar1;
  int iVar2;
  
  if (((param_1 != 0) && (*(int *)(param_1 + 0x40) != 0)) &&
     (iVar1 = Ordinal_1154(*(int *)(param_1 + 0x40)), iVar1 != 0)) {
    iVar1 = Ordinal_1154(*(undefined4 *)(param_1 + 0x40));
    do {
      iVar1 = iVar1 + -1;
      if (iVar1 < 0) {
        return 0;
      }
      iVar2 = Ordinal_1156(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),iVar1);
    } while ((iVar2 == 0) || (*(int *)(iVar2 + 8) == 0));
    return *(undefined2 *)(iVar2 + 6);
  }
  return 0;
}



// ============================================================
// Function: rendering_getFirstChannelFrame (FUN_680ce8d0)
// Address: 680ce8d0
// Size: 56 bytes
// Params: uint param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint rendering_getFirstChannelFrame(uint param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  if (((param_1 != 0) && (piVar1 = (int *)(param_1 + 0x40), *piVar1 != 0)) &&
     (piVar2 = (int *)(param_1 + 0x44), param_1 = 0, *piVar2 != 0)) {
    iVar3 = Ordinal_1156(*piVar1,*piVar2,0);
    param_1 = 0;
    if (iVar3 != 0) {
      return (uint)*(ushort *)(iVar3 + 6);
    }
  }
  return param_1 & 0xffff0000;
}



// ============================================================
// Function: rendering_getFirstActiveFrame (FUN_680ce910)
// Address: 680ce910
// Size: 101 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 rendering_getFirstActiveFrame(int param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x40) == 0)) {
    return 0;
  }
  uVar3 = 0;
  iVar1 = Ordinal_1154(*(int *)(param_1 + 0x40));
  if (iVar1 != 0) {
    do {
      iVar1 = Ordinal_1156(*(undefined4 *)(param_1 + 0x40),*(undefined4 *)(param_1 + 0x44),uVar3);
      if ((iVar1 != 0) && (*(int *)(iVar1 + 8) != 0)) {
        return *(undefined2 *)(iVar1 + 6);
      }
      uVar3 = uVar3 + 1;
      uVar2 = Ordinal_1154(*(undefined4 *)(param_1 + 0x40));
    } while (uVar3 < uVar2);
  }
  return 0;
}



// ============================================================
// Function: rendering_getChannelLock (FUN_680ce980)
// Address: 680ce980
// Size: 19 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getChannelLock(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x60);
  }
  return uVar1;
}



// ============================================================
// Function: rendering_writeChannelBlock (FUN_680ce9a0)
// Address: 680ce9a0
// Size: 133 bytes
// Params: int * param_1, int * param_2, void * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_writeChannelBlock(int *param_1,int *param_2,void *param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  int local_8;
  
  iVar3 = *param_1;
  local_8 = 0;
  local_c = 0;
  if (param_1[0x19] != 0) {
    iVar2 = Ordinal_1404(&local_8,param_1[0x19],1);
    if (iVar2 == 0) goto LAB_680cea11;
    iVar2 = Ordinal_1435(local_8);
    uVar1 = *(ushort *)(param_1 + 1);
    iVar2 = playback_importChannelSprites((int *)*param_1,local_8,iVar2,(uint)uVar1,param_2,param_3);
    iVar3 = rendering_getChannelSprite(iVar3,uVar1);
    *(int *)(iVar3 + 0x60) = iVar2;
    if (iVar2 == 0) goto LAB_680cea11;
    Ordinal_1113(iVar3 + 100);
  }
  local_c = 1;
LAB_680cea11:
  Ordinal_1407(&local_8);
  return local_c;
}



// ============================================================
// Function: rendering_getChannelIndex (FUN_680cea30)
// Address: 680cea30
// Size: 103 bytes
// Params: int param_1, short param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint rendering_getChannelIndex(int param_1,short param_2)

{
  undefined4 in_EAX;
  undefined2 uVar3;
  int iVar1;
  uint uVar2;
  
  uVar3 = (undefined2)((uint)in_EAX >> 0x10);
  if (param_1 == 0) {
    return CONCAT22(uVar3,0xfffe);
  }
  if (param_2 != 0) {
    if (*(short *)(param_1 + 4) == param_2) {
      return 0xffffffff;
    }
    if (*(int *)(param_1 + 0x60) == 0) {
      iVar1 = rendering_getChannelSize(*(short *)(param_1 + 4));
      *(int *)(param_1 + 0x60) = iVar1;
      uVar3 = 0;
      if (iVar1 == 0) goto LAB_680cea84;
    }
    uVar2 = playback_addChannelIndex(*(undefined4 *)(param_1 + 0x60),param_2);
    return uVar2 & 0xffff;
  }
LAB_680cea84:
  return CONCAT22(uVar3,0xfffe);
}



// ============================================================
// Function: rendering_getChannelSlot (FUN_680ceaa0)
// Address: 680ceaa0
// Size: 162 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: undefined2 *
// Calling convention: __stdcall
// ============================================================

undefined2 * rendering_getChannelSlot(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)0x0;
  if (((param_1 != (undefined4 *)0x0) &&
      (puVar2 = playback_buildChannelMapByType((void *)param_1[0x18],*param_1,(void *)param_1[0x18],param_2,param_3),
      puVar2 != (undefined2 *)0x0)) && (param_1[0x18] == 0)) {
    switch(param_2) {
    case 1:
      puVar2[*(short *)(param_1 + 1)] = 0xffff;
      return puVar2;
    case 2:
      puVar2[-1] = *(undefined2 *)(param_1 + 1);
      return puVar2;
    case 3:
      uVar1 = scoreEngine_getChannelRange(param_3,*(short *)(param_1 + 1),0);
      puVar2[(short)uVar1] = 0xffff;
      return puVar2;
    case 4:
      uVar1 = scoreEngine_getChannelRange(param_3,*(short *)(param_1 + 1),0);
      puVar2[-1] = (short)uVar1;
    }
  }
  return puVar2;
}



// ============================================================
// Function: rendering_getChannelBlock (FUN_680ceb60)
// Address: 680ceb60
// Size: 314 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getChannelBlock(int *param_1)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_3c;
  int local_38;
  int *local_34;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_38 = param_1[0x18];
  local_34 = (int *)0x0;
  if ((local_38 != 0) &&
     (local_34 = rendering_getDispatchByChannel(*param_1,(short)param_1[1]), local_34 != (int *)0x0)) {
    iVar2 = rendering_getChannelSize((short)param_1[1]);
    piVar3 = (int *)rendering_getMemberCache((int)local_34);
    while (piVar3 != (int *)0x0) {
      iVar4 = piVar3[2];
      if ((iVar4 == 1) || (iVar4 == 0xd)) {
        iVar4 = rendering_getMemberPropertyState(piVar3,&local_3c);
        if (iVar4 != 0) {
          param_1[0x18] = iVar2;
          rendering_getMemberPropertyEx(piVar3,local_3c);
LAB_680cec52:
          param_1[0x18] = local_38;
        }
      }
      else if (iVar4 == 2) {
        iVar4 = *(int *)(*(int *)*param_1 + 0x18);
        if ((iVar4 != 0) && (*(int *)(iVar4 + 0xc) != 0)) {
          local_20 = 0;
          local_1c = 0;
          local_18 = 0;
          local_14 = 0;
          local_10 = 0;
          local_c = 0;
          puVar1 = *(undefined4 **)(*(int *)(*(int *)(*(int *)*param_1 + 0x18) + 0xc) + 0x20);
          param_1[0x18] = iVar2;
          local_2c = *puVar1;
          local_28 = 0x16;
          local_30 = piVar3;
          local_24 = local_38;
          rendering_initState((int *)&local_30);
          goto LAB_680cec52;
        }
      }
      piVar3 = (int *)rendering_getMemberCache((int)local_34);
    }
    playback_initScore(&local_38);
    param_1[0x18] = iVar2;
  }
  rendering_getDispatchState((int *)&local_34);
  return 0;
}



// ============================================================
// Function: rendering_validateChannelScript (FUN_680ceca0)
// Address: 680ceca0
// Size: 91 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_validateChannelScript(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_2 + 0x48) == 0) {
    return 1;
  }
  iVar1 = stage_invalidateSpriteScriptByIndex(*(int *)(param_1 + 8),(int *)(param_2 + 0x48));
  if (((iVar1 != 0) && (iVar2 = rendering_getChannelDepth(param_2), iVar2 != 0)) &&
     (iVar2 = strings_readMediaBlock(*(int *)(iVar2 + 4),FOURCC_LctX,*(int *)(param_2 + 0x3c)), iVar2 == 0)) {
    return 1;
  }
  return iVar1;
}



// ============================================================
// Function: rendering_validateChannelMembers (FUN_680ced00)
// Address: 680ced00
// Size: 136 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_validateChannelMembers(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_8;
  
  uVar3 = 0;
  local_8 = (int *)0x0;
  local_8 = rendering_getDispatchByChannel(*(int *)(param_1 + 0x18),*(short *)(param_2 + 4));
  if (local_8 != (int *)0x0) {
    piVar1 = (int *)rendering_getMemberCache((int)local_8);
    while (piVar1 != (int *)0x0) {
      if ((piVar1[2] != 0xd) && (iVar2 = rendering_getMemberSlot(piVar1), iVar2 != 0)) {
        iVar2 = rendering_getMemberData(param_1,piVar1);
        if (iVar2 == 0) goto LAB_680ced6e;
        rendering_isStateValid((int)piVar1);
      }
      piVar1 = (int *)rendering_getMemberCache((int)local_8);
    }
    uVar3 = 1;
LAB_680ced6e:
    if (local_8 != (int *)0x0) {
      rendering_getDispatchState((int *)&local_8);
    }
  }
  return uVar3;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680ced90 - 0x680cf4e0
// Functions (8):
//   rendering_insertChannelEvent
//   rendering_destroyChannelSpriteData
//   rendering_setChannelProperty
//   rendering_resetChannelSprite
//   rendering_deduplicateChannelEvent
//   rendering_dispatchChannelNotification
//   rendering_getChannelProperty
//   rendering_flushChannelEvents

// ============================================================
// Function: rendering_insertChannelEvent (FUN_680ced90)
// Address: 680ced90
// Size: 438 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_insertChannelEvent(int param_1,int param_2)
{
  short sVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  short sVar5;
  int local_c8;
  uint local_c4;
  int local_c0;
  undefined4 local_bc;
  undefined4 local_b8;
  int local_b0;
  undefined2 local_ac;
  short local_aa;
  uint local_8;
  
  local_c0 = param_1;
  (*(unsigned short *)((char *)&local_b8 + 0)) = (short)param_2;
  local_bc = 0;
  iVar3 = param_2;
  puVar2 = (undefined4 *)rendering_getChannelSprite(param_1,(short)local_b8);
  local_b8 = iVar3;
  if (puVar2 == (undefined4 *)0x0) {
    return 0;
  }
  sVar1 = (*(unsigned short *)((char *)&local_b8 + 2)) + -1;
  if ((local_b8 < 0x10000) || (0x7d00ffff < local_b8)) {
    (*(unsigned short *)((char *)&local_b8 + 2)) = 1;
    param_2 = CONCAT22(1,(short)local_b8);
  }
  sVar5 = (*(unsigned short *)((char *)&local_b8 + 2));
  iVar3 = rendering_resolveStateEx(local_c0,param_2,&local_c4,&local_c8);
  do {
    if (local_c4 == 0) {
LAB_680cee97:
      Ordinal_1130(&local_b0,0xa8);
      local_ac = *(undefined2 *)(puVar2 + 1);
      local_b0 = local_c0;
      local_aa = sVar5;
      Ordinal_1158(puVar2[0x10],puVar2[0x11]);
      iVar3 = Ordinal_1151(puVar2[0x10],iVar3,&local_b0);
      uVar4 = Ordinal_1157(puVar2[0x10]);
      puVar2[0x11] = uVar4;
      rendering_initChannelState(puVar2);
      if (iVar3 == 0) {
LAB_680cef2d:
        return 0;
      }
LAB_680ceefc:
      return 0;
    }
    if (*(int *)(local_c8 + 8) == 0) {
      if (local_c4 != 0) goto LAB_680ceefc;
      goto LAB_680cee97;
    }
    if (sVar5 == 32000) {
      sVar5 = 1;
    }
    else {
      if (sVar5 == sVar1) goto LAB_680cef2d;
      sVar5 = sVar5 + 1;
    }
    (*(unsigned short *)((char *)&local_b8 + 2)) = sVar5;
    iVar3 = rendering_resolveStateEx(local_c0,CONCAT22(sVar5,(short)local_b8),&local_c4,&local_c8);
  } while( true );
}



// ============================================================
// Function: rendering_destroyChannelSpriteData (FUN_680cef50)
// Address: 680cef50
// Size: 251 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_destroyChannelSpriteData(int param_1,undefined4 *param_2,int param_3)
{
  short sVar1;
  uint in_EAX;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  Ordinal_1163(in_EAX + 0x5c);
  if (*(int *)(in_EAX + 0x40) != 0) {
    uVar2 = rendering_getFirstChannelFrame(in_EAX);
    sVar1 = rendering_getLastChannelFrame(in_EAX);
    pbVar3 = (byte *)0x0;
    if (param_2 != (undefined4 *)0x0) {
      pbVar3 = (byte *)*param_2;
    }
    rendering_processChannelMediaEvents(pbVar3,uVar2 & 0xffff,sVar1);
    if (*(int *)(in_EAX + 0x44) != 0) {
      Ordinal_1158(*(undefined4 *)(in_EAX + 0x40),*(int *)(in_EAX + 0x44));
      *(undefined4 *)(in_EAX + 0x44) = 0;
    }
    Ordinal_1163((undefined4 *)(in_EAX + 0x40));
  }
  playback_initScore(in_EAX + 0x60);
  Ordinal_1113(in_EAX + 100);
  iVar4 = media_getDataPtr(*(int **)(param_1 + 4));
  if (*(code **)(iVar4 + 0xd8) != (code *)0x0) {
    (**(code **)(iVar4 + 0xd8))(param_1,in_EAX + 0xd4);
  }
  if (*(int *)(in_EAX + 0x14) == 0) {
    playback_openScoreEx((int *)(in_EAX + 0x20));
  }
  Ordinal_1113(in_EAX + 0x34);
  if (param_2 != (undefined4 *)0x0) {
    if (*(int *)(in_EAX + 0x48) != 0) {
      if (param_3 == 0) {
        stage_invalidateSpriteScript(param_2[2],(int *)(in_EAX + 0x48));
      }
      else {
        scoreEngine_storeDeferredAsset(param_1,&param_3,*(int *)(in_EAX + 0x48));
      }
    }
  }
  Ordinal_1113(in_EAX + 0x30);
  Ordinal_36((int *)(in_EAX + 0xd0));
  playback_initFontMapEx();
  return 0;
}



// ============================================================
// Function: rendering_setChannelPropertyEx (FUN_680cf050)
// Address: 680cf050
// Size: 160 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_setChannelPropertyEx(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int local_8;
  
  local_8 = 0;
  puVar2 = (undefined4 *)0x0;
  local_8 = rendering_getChannelSprite((int)param_1,(short)param_2);
  if ((*(int *)(*param_1 + 0x18) != 0) &&
     (iVar1 = *(int *)(*(int *)(*param_1 + 0x18) + 0xc), iVar1 != 0)) {
    puVar2 = *(undefined4 **)(iVar1 + 0x20);
  }
  if (local_8 != 0) {
    *(int *)(local_8 + 8) = *(int *)(local_8 + 8) + -1;
    if (*(int *)(local_8 + 8) == 0) {
      rendering_destroyChannelSpriteData((int)param_1,puVar2,param_3);
      param_2 = 0;
      Ordinal_1159(param_1[0xc6],(int)*(short *)(local_8 + 4),&param_2);
      Ordinal_1125(&local_8);
      *(undefined2 *)(param_1 + 0xd1) = 0xffff;
      param_1[0xd2] = 0;
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: rendering_resetChannelSprite (FUN_680cf0f0)
// Address: 680cf0f0
// Size: 87 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_resetChannelSprite(int param_1,undefined4 *param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  
  rendering_destroyChannelSpriteData(param_1,param_2,0);
  if (*(int *)(param_3 + 0x14) == 0) {
    iVar1 = Ordinal_1111(0x418,0);
    *(int *)(param_3 + 0x30) = iVar1;
    if (iVar1 != 0) {
      uVar2 = Ordinal_1114(iVar1);
      Ordinal_1309(uVar2,0x400,"",2);
      Ordinal_1115(*(undefined4 *)(param_3 + 0x30));
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_deduplicateChannelEvent (FUN_680cf150)
// Address: 680cf150
// Size: 278 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_deduplicateChannelEvent(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *in_EAX;
  int iVar6;
  undefined4 uVar7;
  int *piVar8;
  int unaff_EBX;
  short local_18;
  short sStack_16;
  undefined4 local_c;
  
  local_c = 0;
  iVar6 = Ordinal_1154(*(undefined4 *)(unaff_EBX + 0x11c));
  uVar7 = Ordinal_1157(*(undefined4 *)(unaff_EBX + 0x11c));
  iVar1 = *in_EAX;
  iVar2 = in_EAX[2];
  iVar3 = in_EAX[1];
  iVar4 = in_EAX[3];
joined_r0x680cf1a3:
  do {
    if (iVar6 < 1) goto LAB_680cf24d;
    iVar6 = iVar6 + -1;
    piVar8 = (int *)Ordinal_1156(*(undefined4 *)(unaff_EBX + 0x11c),uVar7,iVar6);
    iVar5 = piVar8[3];
  } while (piVar8[2] != iVar2);
  local_18 = (short)iVar4;
  sStack_16 = (short)((uint)iVar4 >> 0x10);
  switch(piVar8[2]) {
  case 0xb:
  case 0xc:
  case 0xd:
    if (((short)iVar5 != local_18) || ((short)((uint)iVar5 >> 0x10) != sStack_16))
    goto joined_r0x680cf1a3;
    break;
  default:
    goto switchD_680cf1f3_caseD_e;
  case 0x11:
    goto switchD_680cf1f3_caseD_11;
  case 0x17:
  case 0x18:
  case 0x19:
  case 0x1a:
    break;
  case 0x1e:
    goto switchD_680cf1f3_caseD_1e;
  }
  if ((short)iVar5 == local_18) {
switchD_680cf1f3_caseD_1e:
    if (iVar5 == iVar4) {
switchD_680cf1f3_caseD_11:
      *(short *)(piVar8 + 3) = local_18;
      *(short *)((int)piVar8 + 0xe) = sStack_16;
switchD_680cf1f3_caseD_e:
      if (((piVar8[5] == 0) && (*piVar8 == iVar1)) && (piVar8[1] == iVar3)) {
        local_c = 1;
LAB_680cf24d:
        Ordinal_1158(*(undefined4 *)(unaff_EBX + 0x11c),uVar7);
        return local_c;
      }
    }
  }
  goto joined_r0x680cf1a3;
}



// ============================================================
// Function: rendering_dispatchChannelNotification (FUN_680cf290)
// Address: 680cf290
// Size: 264 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_dispatchChannelNotification(undefined4 param_1,undefined4 *param_2)
{
  uint uVar1;
  short sVar2;
  uint *in_EAX;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  uint local_c;
  uint local_8;
  
  uVar1 = in_EAX[1];
  switch(param_1) {
  case 0:
    media_queryXtraProperty(uVar1,0x10,(uint *)(*(int *)(uVar1 + 4) + 0x10));
    return 0;
  case 8:
    local_8 = *in_EAX;
    media_queryXtraProperty(uVar1,0xb,&local_8);
    return 0;
  case 9:
    local_8 = *in_EAX;
    media_queryXtraProperty(uVar1,0xc,&local_8);
    return 0;
  case 0xc:
  case 0xd:
    sVar2 = scoreEngine_getChannelCount(*(int *)(uVar1 + 0x20),(short)*param_2);
    local_c = CONCAT22(extraout_var,sVar2);
    media_queryXtraProperty(uVar1,2,&local_c);
    return 0;
  case 0xf:
    media_queryXtraProperty(uVar1,4,(uint *)0x0);
    return 0;
  case 0x11:
    sVar2 = scoreEngine_getChannelCount(*(int *)(uVar1 + 0x20),(short)*param_2);
    local_c = CONCAT22(extraout_var_00,sVar2);
    media_queryXtraProperty(uVar1,6,&local_c);
    return 0;
  case 0x13:
    media_queryXtraProperty(uVar1,7,(uint *)uVar1);
    return 0;
  case 0x14:
    media_queryXtraProperty(uVar1,8,(uint *)0x0);
    return 0;
  case 0x15:
    media_fireAllXtraEvents(uVar1);
    return 0;
  case 0x20:
    media_queryXtraPropertyEx(uVar1,&DAT_68176218,(uint *)0x0);
    return 0;
  case 0x24:
    media_queryXtraProperty(uVar1,0x15,(uint *)0x0);
    return 0;
  case 0x25:
    media_queryXtraProperty(uVar1,0x16,(uint *)0x0);
  }
  return 0;
}



// ============================================================
// Function: rendering_getChannelProperty (FUN_680cf400)
// Address: 680cf400
// Size: 218 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getChannelProperty(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    iVar2 = *(int *)(*(int *)(param_1 + 0x20) + 4);
    iVar1 = playback_getLifecycleData(param_1);
    if (iVar1 != 0) {
      param_1 = 0;
    }
    rendering_dispatchChannelNotification(param_2,param_3);
    iVar1 = **(int **)(*(int *)(iVar2 + 8) + 4);
    if ((*(int *)(iVar1 + 0xe0) == 0) && (*(int *)(iVar1 + 0x5c) == 0)) {
      return 1;
    }
    if (*(int *)(iVar2 + 0x11c) == 0) {
      iVar1 = Ordinal_1150(10,10,0x18);
      *(int *)(iVar2 + 0x11c) = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
    }
    Ordinal_1130(&local_1c,0x18);
    local_14 = param_2;
    if (param_3 != (undefined4 *)0x0) {
      local_10 = *param_3;
      local_c = param_3[1];
    }
    local_8 = 0;
    local_1c = iVar2;
    local_18 = param_1;
    iVar1 = rendering_deduplicateChannelEvent();
    if ((iVar1 == 0) && (iVar2 = Ordinal_1152(*(undefined4 *)(iVar2 + 0x11c),&local_1c), iVar2 == 0)
       ) {
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: rendering_flushChannelEvents (FUN_680cf4e0)
// Address: 680cf4e0
// Size: 317 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_flushChannelEvents(int param_1)
{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  uint uVar8;
  uint local_8;
  
  iVar3 = param_1;
  piVar1 = (int *)(param_1 + 0x11c);
  puVar6 = (undefined4 *)(param_1 + 0x11c);
  if ((*piVar1 != 0) &&
     (((iVar5 = **(int **)(*(int *)(param_1 + 8) + 4), *(int *)(iVar5 + 0xe0) != 0 ||
       (*(int *)(iVar5 + 0x5c) != 0)) && (DAT_68196470 == 0)))) {
    DAT_68196470 = 1;
    local_8 = 0;
    param_1 = 0;
    uVar4 = Ordinal_1157(*piVar1);
    if (**(int **)(iVar3 + 8) != 0) {
      param_1 = *(int *)(**(int **)(iVar3 + 8) + 0x24);
    }
    iVar5 = Ordinal_1154(*puVar6);
    if (iVar5 != 0) {
      do {
        puVar6 = (undefined4 *)Ordinal_1156(*(undefined4 *)(iVar3 + 0x11c),uVar4,local_8);
        if (puVar6 != (undefined4 *)0x0) {
          puVar6[5] = 1;
          if ((puVar6[2] - 8 < 2) &&
             (iVar5 = **(int **)(*(int *)(iVar3 + 8) + 4), *(int *)(iVar5 + 0x5c) != 0)) {
            iVar7 = crt_getFileEndOffset(*(int **)(*(int *)(iVar3 + 0x20) + 0x10));
            (**(code **)(iVar5 + 0x5c))(param_1,puVar6[2],*(int *)(iVar3 + 0x20) + 0x28,iVar7);
          }
          pcVar2 = *(code **)(**(int **)(*(int *)(iVar3 + 8) + 4) + 0xe0);
          if (pcVar2 != (code *)0x0) {
            (*pcVar2)(*puVar6,puVar6[1],puVar6[2],puVar6 + 3);
          }
        }
        local_8 = local_8 + 1;
        uVar8 = Ordinal_1154(*(undefined4 *)(iVar3 + 0x11c));
      } while (local_8 < uVar8);
    }
    Ordinal_1158(*(undefined4 *)(iVar3 + 0x11c),uVar4);
    Ordinal_1163((undefined4 *)(iVar3 + 0x11c));
    DAT_68196470 = 0;
  }
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680cf620 - 0x680cfaa0
// Functions (12):
//   rendering_getChannelSize
//   rendering_releaseChannelHandle
//   rendering_getChannelWidth
//   rendering_getChannelVisibility
//   rendering_getChannelFlags
//   rendering_compareChannelData
//   rendering_getChannelSpriteName
//   rendering_writeChannelScoreData
//   rendering_computePaletteHash
//   rendering_lookupPaletteCache
//   rendering_buildChannelMap
//   rendering_buildChannelReverseMap

// ============================================================
// Function: rendering_getChannelSize (FUN_680cf620)
// Address: 680cf620
// Size: 59 bytes
// Params: undefined2 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_getChannelSize(undefined2 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = Ordinal_1111(0x14,0);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)Ordinal_1114(iVar1);
    puVar2[1] = 4;
    *puVar2 = 0;
    *(undefined2 *)(puVar2 + 2) = param_1;
    Ordinal_1115(iVar1);
  }
  return iVar1;
}



// ============================================================
// Function: rendering_releaseChannelHandle (FUN_680cf660)
// Address: 680cf660
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_releaseChannelHandle(void)
{
  Ordinal_1112();
  return 0;
}



// ============================================================
// Function: rendering_getChannelWidth (FUN_680cf670)
// Address: 680cf670
// Size: 43 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 rendering_getChannelWidth(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    if (iVar1 != 0) {
      uVar2 = *(undefined2 *)(iVar1 + 8);
      Ordinal_1115(param_1);
    }
  }
  return uVar2;
}



// ============================================================
// Function: rendering_getChannelVisibility (FUN_680cf6a0)
// Address: 680cf6a0
// Size: 40 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getChannelVisibility(int param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    puVar1 = (undefined4 *)Ordinal_1114(param_1);
    if (puVar1 != (undefined4 *)0x0) {
      uVar2 = *puVar1;
      Ordinal_1115(param_1);
    }
  }
  return uVar2;
}



// ============================================================
// Function: rendering_getChannelFlags (FUN_680cf6d0)
// Address: 680cf6d0
// Size: 55 bytes
// Params: int param_1, int param_2
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 rendering_getChannelFlags(int param_1,int param_2)

{
  int *piVar1;
  undefined2 uVar2;
  
  uVar2 = 0;
  if (param_1 != 0) {
    piVar1 = (int *)Ordinal_1114(param_1);
    if (piVar1 != (int *)0x0) {
      if ((-1 < param_2) || (param_2 < *piVar1)) {
        uVar2 = *(undefined2 *)((int)piVar1 + param_2 * 2 + 10);
      }
      Ordinal_1115(param_1);
    }
  }
  return uVar2;
}



// ============================================================
// Function: rendering_compareChannelData (FUN_680cf710)
// Address: 680cf710
// Size: 127 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_compareChannelData(int param_1,int param_2)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 == param_2) {
    return 1;
  }
  sVar1 = rendering_getChannelWidth(param_1);
  sVar2 = rendering_getChannelWidth(param_2);
  if (sVar1 == sVar2) {
    iVar3 = rendering_getChannelVisibility(param_1);
    iVar4 = rendering_getChannelVisibility(param_2);
    if (iVar3 == iVar4) {
      iVar4 = 0;
      if (0 < iVar3) {
        do {
          sVar1 = rendering_getChannelFlags(param_1,iVar4);
          sVar2 = rendering_getChannelFlags(param_2,iVar4);
          if (sVar1 != sVar2) {
            return 0;
          }
          iVar4 = iVar4 + 1;
        } while (iVar4 < iVar3);
      }
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_getChannelSpriteName (FUN_680cf7a0)
// Address: 680cf7a0
// Size: 240 bytes
// Params: short param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall rendering_getChannelSpriteName(short param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined1 *puVar3;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_40c = 0;
  iVar1 = rendering_getChannelSprite(param_2,param_1);
  if (iVar1 != 0) {
    if (*(int *)(iVar1 + 0x14) == 0) {
      uVar2 = Ordinal_1114(*(undefined4 *)(iVar1 + 0x30));
      Ordinal_1310(uVar2,local_408,0x3ff);
      Ordinal_1115(*(undefined4 *)(iVar1 + 0x30));
    }
    else {
      scoreEngine_getChannelRange(*(int *)(iVar1 + 0x1c),param_1,0);
      local_408[0] = 0;
    }
    iVar1 = Ordinal_1201(local_408,0);
    local_40c = Ordinal_1111(iVar1 + 4);
    if (local_40c != 0) {
      puVar3 = (undefined1 *)Ordinal_1114(local_40c);
      xtra_readBE32(puVar3);
      Ordinal_1233(puVar3 + 2,local_408);
      if (puVar3 + 2 != (undefined1 *)0x0) {
        Ordinal_1115(local_40c);
      }
      goto LAB_680cf87e;
    }
  }
  Ordinal_1113(&local_40c);
LAB_680cf87e:
  return 0;
}



// ============================================================
// Function: rendering_writeChannelScoreData (FUN_680cf890)
// Address: 680cf890
// Size: 259 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_writeChannelScoreData(int param_1,int param_2,int param_3)

{
  bool bVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_14;
  int local_c;
  undefined4 *local_8;
  
  iVar7 = 0;
  local_8 = (undefined4 *)0x0;
  local_c = 0;
  local_14 = 0;
  bVar1 = false;
  uVar3 = Ordinal_1433(param_2);
  iVar6 = param_3;
  if (param_3 == 0) {
LAB_680cf94f:
    if (local_8 != (undefined4 *)0x0) {
      Ordinal_36((int *)&local_8);
    }
    if (bVar1) goto LAB_680cf975;
  }
  else {
    iVar4 = rendering_getChannelVisibility(param_3);
    local_8 = (undefined4 *)Ordinal_35(4);
    if (local_8 != (undefined4 *)0x0) {
      *(undefined4 *)*local_8 = 4;
      if (0 < iVar4) {
        do {
          sVar2 = rendering_getChannelFlags(iVar6,iVar7);
          param_3 = rendering_getChannelSpriteName(sVar2,param_1);
          if (param_3 == 0) goto LAB_680cf94f;
          iVar5 = cast_formatNumber(&local_8,(short)iVar7,param_3);
          Ordinal_1113(&param_3);
          if (iVar5 == 0) goto LAB_680cf94f;
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar4);
      }
      local_14 = Ordinal_1042();
      local_c = cast_readDataEntry((int)local_8,param_2,1);
      if (local_c != 0) {
        iVar6 = Ordinal_1042();
        if (iVar6 == 0) {
          bVar1 = true;
        }
      }
      goto LAB_680cf94f;
    }
  }
  Ordinal_1432(param_2,uVar3,0);
  local_c = 0;
LAB_680cf975:
  Ordinal_1042();
  if (local_14 != 0) {
    Ordinal_1040(local_14);
  }
  return local_c;
}



// ============================================================
// Function: rendering_computePaletteHash (FUN_680cf9a0)
// Address: 680cf9a0
// Size: 27 bytes
// Params: void * this, int param_1
// Return: uint
// Calling convention: __thiscall
// ============================================================

uint __thiscall rendering_computePaletteHash(void *this,int param_1)

{
  uint in_EAX;
  
  return (in_EAX & 0x1c) * 8 | (uint)this & 0x1c | param_1 - 1U;
}



// ============================================================
// Function: rendering_lookupPaletteCache (FUN_680cf9c0)
// Address: 680cf9c0
// Size: 38 bytes
// Params: undefined4 param_1, void * param_2
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_lookupPaletteCache(undefined4 param_1,void *param_2)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  int extraout_EDX;
  int unaff_ESI;
  
  uVar2 = rendering_computePaletteHash(param_2,in_EAX);
  iVar1 = (&DAT_68197be0)[uVar2];
  if (((iVar1 != 0) && (*(int *)(iVar1 + -0x16) == extraout_EDX)) &&
     (*(int *)(iVar1 + -0x12) == unaff_ESI)) {
    *(int *)(iVar1 + -0x1a) = *(int *)(iVar1 + -0x1a) + 1;
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: rendering_buildChannelMap (FUN_680cf9f0)
// Address: 680cf9f0
// Size: 166 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_buildChannelMap(int param_1)

{
  int iVar1;
  undefined2 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_8;
  
  iVar3 = rendering_getChannelVisibility(param_1);
  local_8 = Ordinal_1111(iVar3 * 2 + 0x1e,2);
  if (local_8 != 0) {
    piVar4 = (int *)Ordinal_1114(local_8);
    *piVar4 = local_8;
    piVar4[4] = iVar3 + 2;
    piVar4[1] = 1;
    *(undefined2 *)(piVar4 + 5) = 0xfffe;
    *(short *)((int)piVar4 + 0x16) = (short)iVar3 + -1;
    piVar4[6] = 0;
    uVar2 = rendering_getChannelWidth(param_1);
    *(undefined2 *)(piVar4 + 7) = uVar2;
    iVar1 = (int)piVar4 + 0x1e;
    iVar5 = 0;
    if (0 < iVar3) {
      do {
        uVar2 = rendering_getChannelFlags(param_1,iVar5);
        *(undefined2 *)(iVar1 + iVar5 * 2) = uVar2;
        iVar5 = iVar5 + 1;
      } while (iVar5 < iVar3);
    }
    if (iVar1 != 0) {
      return iVar1;
    }
    Ordinal_1115(local_8);
  }
  Ordinal_1113(&local_8);
  return 0;
}



// ============================================================
// Function: rendering_buildChannelReverseMap (FUN_680cfaa0)
// Address: 680cfaa0
// Size: 232 bytes
// Params: int param_1
// Return: undefined2 *
// Calling convention: __stdcall
// ============================================================

undefined2 * rendering_buildChannelReverseMap(int param_1)

{
  short sVar1;
  int in_EAX;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined2 *puVar5;
  int local_8;
  
  iVar3 = *(int *)(in_EAX + 0x31c);
  puVar5 = (undefined2 *)0x0;
  local_8 = Ordinal_1111(iVar3 * 2 + 0x20,2);
  if (local_8 == 0) {
    Ordinal_1113(&local_8);
  }
  else {
    piVar2 = (int *)Ordinal_1114(local_8);
    *(undefined2 *)(piVar2 + 5) = 0;
    *piVar2 = local_8;
    *(undefined2 *)(piVar2 + 6) = 0xfffe;
    iVar4 = 0;
    piVar2[1] = 1;
    piVar2[4] = iVar3 + 3;
    *(short *)((int)piVar2 + 0x16) = (short)iVar3;
    if (0 < iVar3 + 3) {
      puVar5 = (undefined2 *)((int)piVar2 + 0x1a);
      do {
        *puVar5 = (short)piVar2[6];
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar4 < piVar2[4]);
    }
    puVar5 = (undefined2 *)((int)piVar2 + 0x1e);
    *puVar5 = (short)piVar2[6];
    iVar3 = rendering_getChannelVisibility(param_1);
    iVar4 = 0;
    if (0 < iVar3) {
      do {
        sVar1 = rendering_getChannelFlags(param_1,iVar4);
        if (sVar1 != 0) {
          puVar5[sVar1] = (short)iVar4;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar3);
    }
    sVar1 = rendering_getChannelWidth(param_1);
    if (sVar1 != 0) {
      sVar1 = rendering_getChannelWidth(param_1);
      puVar5[sVar1] = 0xffff;
      return puVar5;
    }
  }
  return puVar5;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680cfb90 - 0x680cffe0
// Functions (10):
//   rendering_buildChannelScoreMap
//   rendering_buildChannelScoreReverseMap
//   rendering_getChannelHeight
//   rendering_getChannelDefaultHeight
//   rendering_processChannelEvent
//   rendering_setChannelRect
//   rendering_resolveChannelHeight
//   rendering_writeChannelData
//   rendering_convertChannelFontData
//   rendering_importChannelSpriteData

// ============================================================
// Function: rendering_buildChannelScoreMap (FUN_680cfb90)
// Address: 680cfb90
// Size: 232 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int rendering_buildChannelScoreMap(int param_1,int param_2)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  short sVar7;
  int local_8;
  
  if (param_2 != 0) {
    iVar3 = rendering_getChannelVisibility(param_1);
    local_8 = Ordinal_1111(iVar3 * 2 + 0x1e,2);
    if (local_8 != 0) {
      piVar4 = (int *)Ordinal_1114(local_8);
      *piVar4 = local_8;
      sVar7 = 0;
      piVar4[1] = 1;
      piVar4[4] = iVar3 + 2;
      *(undefined2 *)(piVar4 + 5) = 0xfffe;
      *(short *)((int)piVar4 + 0x16) = (short)iVar3 + -1;
      piVar4[6] = 0;
      sVar2 = rendering_getChannelWidth(param_1);
      uVar5 = scoreEngine_getChannelRange(param_2,sVar2,sVar7);
      *(short *)(piVar4 + 7) = (short)uVar5;
      if ((short)uVar5 < 1) {
        *(short *)(piVar4 + 7) = (short)piVar4[6];
      }
      iVar6 = 0;
      iVar1 = (int)piVar4 + 0x1e;
      if (0 < iVar3) {
        do {
          sVar7 = 0;
          sVar2 = rendering_getChannelFlags(param_1,iVar6);
          uVar5 = scoreEngine_getChannelRange(param_2,sVar2,sVar7);
          *(short *)(iVar1 + iVar6 * 2) = (short)uVar5;
          if ((short)uVar5 < 1) {
            *(short *)(iVar1 + iVar6 * 2) = (short)piVar4[6];
          }
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar3);
      }
      if (iVar1 != 0) {
        return iVar1;
      }
      Ordinal_1115(local_8);
    }
  }
  Ordinal_1113(&local_8);
  return 0;
}



// ============================================================
// Function: rendering_buildChannelScoreReverseMap (FUN_680cfc80)
// Address: 680cfc80
// Size: 262 bytes
// Params: void * this, int param_1, int param_2
// Return: undefined2 *
// Calling convention: __thiscall
// ============================================================

undefined2 * __thiscall rendering_buildChannelScoreReverseMap(void *this,int param_1,int param_2)

{
  short sVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 *puVar6;
  short sVar7;
  void *local_8;
  
  local_8 = this;
  if (param_2 != 0) {
    sVar1 = *(short *)(param_2 + 0x478);
    local_8 = (void *)Ordinal_1111(sVar1 * 2 + 0x20,2);
    if (local_8 != (void *)0x0) {
      piVar2 = (int *)Ordinal_1114(local_8);
      *piVar2 = (int)local_8;
      *(undefined2 *)(piVar2 + 5) = 0;
      iVar3 = sVar1 + 3;
      *(undefined2 *)(piVar2 + 6) = 0xfffe;
      iVar5 = 0;
      piVar2[1] = 1;
      piVar2[4] = iVar3;
      *(short *)((int)piVar2 + 0x16) = sVar1;
      if (0 < iVar3) {
        puVar6 = (undefined2 *)((int)piVar2 + 0x1a);
        do {
          *puVar6 = (short)piVar2[6];
          iVar5 = iVar5 + 1;
          puVar6 = puVar6 + 1;
        } while (iVar5 < piVar2[4]);
      }
      puVar6 = (undefined2 *)((int)piVar2 + 0x1e);
      *puVar6 = (short)piVar2[6];
      iVar3 = rendering_getChannelVisibility(param_1);
      iVar5 = 0;
      if (0 < iVar3) {
        do {
          sVar7 = 0;
          sVar1 = rendering_getChannelFlags(param_1,iVar5);
          uVar4 = scoreEngine_getChannelRange(param_2,sVar1,sVar7);
          if (0 < (short)uVar4) {
            puVar6[(short)uVar4] = (short)iVar5;
          }
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar3);
      }
      sVar7 = 0;
      sVar1 = rendering_getChannelWidth(param_1);
      uVar4 = scoreEngine_getChannelRange(param_2,sVar1,sVar7);
      if ((short)uVar4 < 1) {
        return puVar6;
      }
      puVar6[(short)uVar4] = 0xffff;
      return puVar6;
    }
  }
  Ordinal_1113(&local_8);
  return (undefined2 *)0x0;
}



// ============================================================
// Function: rendering_getChannelHeight (FUN_680cfd90)
// Address: 680cfd90
// Size: 41 bytes
// Params: int param_1, short param_2
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 rendering_getChannelHeight(int param_1,short param_2)

{
  if ((*(short *)(param_1 + -10) <= param_2) && (param_2 <= *(short *)(param_1 + -8))) {
    return *(undefined2 *)(param_1 + param_2 * 2);
  }
  return *(undefined2 *)(param_1 + -6);
}



// ============================================================
// Function: rendering_getChannelDefaultHeight (FUN_680cfdc0)
// Address: 680cfdc0
// Size: 20 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 rendering_getChannelDefaultHeight(int param_1)

{
  undefined2 uVar1;
  
  uVar1 = 0;
  if (param_1 != 0) {
    uVar1 = *(undefined2 *)(param_1 + -6);
  }
  return uVar1;
}



// ============================================================
// Function: rendering_processChannelEvent (FUN_680cfde0)
// Address: 680cfde0
// Size: 58 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_processChannelEvent(int *param_1)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_1;
  if (param_1 != (int *)0x0) {
    iVar1 = *param_1;
    if ((iVar1 != 0) &&
       (*(int *)(iVar1 + -0x1a) = *(int *)(iVar1 + -0x1a) + -1, *(int *)(iVar1 + -0x1a) < 1)) {
      param_1 = *(int **)(iVar1 + -0x1e);
      Ordinal_1115(param_1);
      Ordinal_1113(&param_1);
    }
    *piVar2 = 0;
  }
  return 0;
}



// ============================================================
// Function: rendering_setChannelRect (FUN_680cfe20)
// Address: 680cfe20
// Size: 100 bytes
// Params: int param_1, short * param_2, int param_3, short param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_setChannelRect(int param_1,short *param_2,int param_3,short param_4)
{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  if (((param_4 != param_2[6]) && (iVar2 = scoreEngine_getChannelField(param_1,param_4), iVar2 != 0)) &&
     (sVar1 = rendering_getChannelHeight(param_3,param_4), sVar1 == -2)) {
    iVar3 = scoreEngine_getChannelField(param_1,*param_2);
    uVar4 = rendering_getChannelIndex(iVar3,*(short *)(iVar2 + 4));
    if ((short)uVar4 != -2) {
      *(short *)(param_3 + param_4 * 2) = (short)uVar4;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_resolveChannelHeight (FUN_680cfe90)
// Address: 680cfe90
// Size: 69 bytes
// Params: short * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_resolveChannelHeight(short *param_1,int param_2)
{
  short sVar1;
  short sVar2;
  short *extraout_EDX;
  
  sVar1 = rendering_getChannelDefaultHeight(param_2);
  if (param_1[1] == 0) {
    *param_1 = sVar1;
    return 0;
  }
  sVar2 = rendering_getChannelHeight(param_2,*param_1);
  *extraout_EDX = sVar2;
  if (sVar2 == sVar1) {
    extraout_EDX[1] = 0;
  }
  return 0;
}



// ============================================================
// Function: rendering_writeChannelData (FUN_680cfee0)
// Address: 680cfee0
// Size: 86 bytes
// Params: undefined1 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_writeChannelData(undefined1 *param_1,int param_2)
{
  short sVar1;
  short sVar2;
  
  sVar1 = rendering_getChannelDefaultHeight(param_2);
  if (*(short *)(param_1 + 2) == 0) {
    xtra_readBE32(param_1);
    return 0;
  }
  sVar2 = xtra_readBE16(param_1);
  sVar2 = rendering_getChannelHeight(param_2,sVar2);
  xtra_readBE32(param_1);
  if (sVar2 == sVar1) {
    *(undefined2 *)(param_1 + 2) = 0;
  }
  return 0;
}



// ============================================================
// Function: rendering_convertChannelFontData (FUN_680cff40)
// Address: 680cff40
// Size: 154 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_convertChannelFontData(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_c = 0;
  uVar3 = 0xffffffff;
  local_8 = Ordinal_1111(unaff_EDI + 1,1);
  if (local_8 != 0) {
    uVar1 = Ordinal_1114(local_8);
    Ordinal_1203(uVar1,param_2,unaff_EDI + 1);
    Ordinal_1115(local_8);
    local_c = playback_mapFont(local_8,0,unaff_EDI,0);
    if (local_c != 0) {
      iVar2 = Ordinal_1114(local_c);
      Ordinal_1309(param_1,0x400,iVar2,param_3);
      uVar3 = 0;
      if (iVar2 != 0) {
        Ordinal_1115(local_c);
      }
    }
  }
  Ordinal_1113(&local_c);
  Ordinal_1113(&local_8);
  return uVar3;
}



// ============================================================
// Function: rendering_importChannelSpriteData (FUN_680cffe0)
// Address: 680cffe0
// Size: 471 bytes
// Params: void * this, int * param_1, int * param_2, int param_3, undefined4 param_4, void * param_5
// Return: undefined2
// Calling convention: __thiscall
// ============================================================

undefined2 __thiscall
rendering_importChannelSpriteData(void *this,int *param_1,int *param_2,int param_3,undefined4 param_4,void *param_5)

{
  undefined2 uVar1;
  code *pcVar2;
  short sVar3;
  uint in_EAX;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined4 uVar8;
  int *piVar9;
  int local_8;
  
  uVar1 = 0;
  local_8 = 0;
  sVar3 = xtra_readBE16(this);
  if (0 < sVar3) {
    iVar4 = scoreEngine_getChannelField((int)param_2,sVar3);
    if ((iVar4 == 0) || (*(int *)(iVar4 + 0x14) == 0)) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined2 *)(iVar4 + 4);
    }
    goto LAB_680d01a1;
  }
  if (in_EAX < 3) goto LAB_680d01a1;
  iVar4 = (int)this + 2;
  uVar5 = (uint)*(byte *)((int)this + 2);
  if (uVar5 == 0xff) {
    if ((int)(in_EAX - 2) < 0x100) goto LAB_680d01a1;
    uVar5 = Ordinal_1201((int)this + 3);
  }
  if (((int)(in_EAX - 2) <= (int)uVar5) || (local_8 = Ordinal_1111(0x418,0), local_8 == 0))
  goto LAB_680d01a1;
  puVar6 = (undefined4 *)Ordinal_1114(local_8);
  Ordinal_1232(iVar4,iVar4);
  uVar5 = rendering_updateChannelState((int)(param_2 + 0x123));
  if (uVar5 < 0x1100) {
    iVar7 = Ordinal_1201(iVar4);
    playback_renderSpriteEx((int)param_1,(int)(param_2 + 0x143),iVar4,iVar7);
    iVar4 = rendering_convertChannelFontData(puVar6,iVar4,param_4);
    if (-1 < iVar4) goto LAB_680d00e3;
  }
  else {
    Ordinal_1309(puVar6,0x400,iVar4,param_4);
LAB_680d00e3:
    iVar4 = bitmap_resolvePathData((int)param_2,param_3,puVar6);
    if (iVar4 != 0) {
      iVar4 = rendering_findChannelByName((int)param_1,puVar6);
      if (iVar4 == 0) {
        pcVar2 = *(code **)(*(int *)(*param_1 + 0xc) + 0x104);
        if (pcVar2 != (code *)0x0) {
          uVar8 = Ordinal_1114(*(undefined4 *)(param_3 + 0x30));
          (*pcVar2)(*(undefined4 *)(param_2[1] + 4),uVar8,puVar6);
          Ordinal_1115(*(undefined4 *)(param_3 + 0x30));
        }
        piVar9 = (int *)rendering_getChannelDataEx((int)param_1,1,puVar6,0);
        if (piVar9 != (int *)0x0) {
          if (puVar6 != (undefined4 *)0x0) {
            puVar6 = (undefined4 *)Ordinal_1115(local_8);
          }
          Ordinal_1113(&local_8);
          iVar4 = playback_loadMediaData(param_2,piVar9,param_5);
          if ((iVar4 == 1) && (iVar4 = rendering_writeChannelBlock(piVar9,param_2,param_5), iVar4 != 0)) {
            uVar1 = (undefined2)piVar9[1];
          }
        }
      }
      else {
        uVar1 = *(undefined2 *)(iVar4 + 4);
      }
    }
  }
  if (puVar6 != (undefined4 *)0x0) {
    Ordinal_1115(local_8);
  }
LAB_680d01a1:
  Ordinal_1113(&local_8);
  return uVar1;
}



