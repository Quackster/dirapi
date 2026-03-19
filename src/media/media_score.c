// Module: media
// Topic: Score, channel, and sprite property operations
// Address range: 0x680a63c0 - 0x680aaac0
// Functions (59):
//   media_getScoreChannelProperty
//   media_getScoreReaderData
//   media_initScorePlayback
//   media_createScoreWriter
//   media_validateSpriteOp
//   media_beginScorePlayback
//   media_resetScoreState
//   media_advanceScoreFrame
//   media_beginScorePlaybackEx
//   media_getNextKeyframe
//   media_getChannelMode
//   media_getChannelSpan
//   media_getNextChannelFrame
//   media_getLastChannelFrame
//   media_getMemberDataBlock
//   media_readScoreBlock2
//   media_readCastDataFromChannel
//   media_importMemberFromChannel
//   media_getChannelPropertyEx
//   media_resolveChannelRef
//   media_getChannelOffset
//   media_updateChannelMediaRef
//   media_copyChannelMember
//   media_mapMediaTypeToIndex
//   media_mapIndexToMediaType
//   media_getMediaErrorCode
//   media_renderScoreFrame
//   media_getChannelMediaInfo
//   media_initChannelState
//   media_dispatchChannelProperty
//   media_getChannelStateFlags
//   media_setChannelStateFlags
//   media_findSpriteByRef
//   media_findSpriteInChannel
//   media_clearChannelMemberFlag
//   media_dispatchChannelPropertyOp
//   media_blendChannelMedia
//   media_getChannelMediaFormat
//   media_writeChannelData
//   media_importChannelAsset
//   media_getChannelUpdateData
//   media_updateChannelMedia
//   media_toggleChannelState
//   media_setChannelVisibility
//   media_getChannelVisibility
//   media_getChannelFrameCount
//   media_updateChannelMemberMedia
//   media_resolveChannelState
//   media_updateSpriteStage
//   media_renderChannelSprite
//   media_invalidateChannelSprite
//   media_findSpriteAction
//   media_dispatchSpriteProperty
//   media_setChannelLabel
//   media_convertRgbToPalette
//   media_convertPaletteToRgb
//   media_readScoreEntry
//   media_copyToGlobalAlloc
//   media_getChannelFontMap

// ============================================================
// Function: media_getScoreChannelProperty (FUN_680a63c0)
// Address: 680a63c0
// Size: 1621 bytes
// Params: int param_1, int param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScoreChannelProperty(int param_1,int param_2,int param_3,int param_4,uint *param_5)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_94;
  int local_90;
  int *local_8c;
  undefined4 local_88;
  undefined4 local_84;
  int local_80;
  int local_7c;
  uint local_78;
  uint local_74;
  uint local_70;
  int local_6c;
  int local_68;
  byte local_63;
  uint local_60;
  uint local_5c;
  byte local_58;
  undefined4 local_57;
  undefined4 local_53;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  uint local_3c;
  uint local_38;
  uint local_30;
  uint local_2c;
  byte local_28;
  uint local_8;
  
  local_80 = param_1;
  local_90 = Ordinal_402(*(int **)(param_1 + 4));
  local_8c = (int *)0x0;
  media_setScorePositionEx(*(int **)(param_1 + 4),&local_8c,(undefined4 *)0x0);
  iVar3 = *(int *)(*(int *)(*local_8c + 0x14) + 0x14);
  if ((((param_3 != 0) && ((-(uint)(*(int *)(local_80 + 8) != 0) & 0x7ffbf43f) != 0x7ffbf43f)) ||
      (999 < param_2 - 1U)) ||
     (iVar2 = Ordinal_404(*(int **)(local_80 + 4),local_90,param_2,&local_70), iVar2 == 0))
  goto LAB_680a6a00;
  if (param_4 < 0x143) {
    if (param_4 == 0x142) {
      if (param_3 == 0) {
        local_84 = local_44;
        local_88 = local_40;
        props_storeSymbolRef(iVar3,&local_88,param_5);
        goto LAB_680a6a00;
      }
      iVar3 = props_getContextState(iVar3,param_5);
      if (iVar3 == 0) {
        local_5c = 1;
      }
    }
    else if (param_4 == 0x58) {
      if (param_3 == 0) {
        local_7c = local_6c;
        cast_getScoreXtraData(iVar3,(short *)&local_7c);
        goto LAB_680a6a00;
      }
      iVar3 = cast_getXtraProperty(iVar3,param_5,&local_7c);
      if (iVar3 == 0) {
        if (((local_70 == 0) && ((*(unsigned char *)((char *)&local_57 + 3)) == '\0')) &&
           (((char)local_57 == '\0' && (((*(unsigned char *)((char *)&local_53 + 3)) == '\0' && ((char)local_53 == '\0')))))) {
          uVar1 = local_57 >> 8;
          local_57 = CONCAT31((uint3)uVar1 & 0xffff,0xff);
        }
        local_6c = local_7c;
        local_70 = 0x10;
        media_setScorePosition(*(int *)(local_80 + 4),param_2 + 5);
      }
    }
    else {
      if (param_4 != 0x7b) {
        if (param_4 == 0xbe) {
          if (param_3 == 0) {
            local_78 = local_57;
            props_storeFloatValue(iVar3,&local_78,param_5);
            goto LAB_680a6a00;
          }
          iVar3 = props_coerceAndStore(iVar3,param_5,(int *)&local_78);
          goto LAB_680a64a8;
        }
        goto switchD_680a65fd_caseD_16a;
      }
switchD_680a65fd_caseD_237:
      if (param_3 == 0) {
        local_7c = 0;
        iVar2 = Ordinal_430(*(int **)(local_80 + 4),local_68);
        if ((iVar2 < 1) ||
           (iVar2 = Ordinal_431(*(int **)(local_80 + 4),local_68,0,(short *)&local_94), iVar2 == 0))
        {
          cast_getScoreXtraData(iVar3,(short *)&local_7c);
        }
        else {
          local_7c = local_94;
          cast_getScoreXtraData(iVar3,(short *)&local_7c);
        }
        goto LAB_680a6a00;
      }
      iVar3 = cast_getXtraProperty(iVar3,param_5,&local_7c);
      if (iVar3 == 0) {
        media_readPlaybackBlockEx(*(int *)(local_80 + 4),param_2 + 6,local_7c);
      }
    }
  }
  else if (param_4 < 0x337) {
    if (param_4 == 0x336) {
      if (param_3 == 0) {
        local_74 = local_30;
        props_storeIntValue(iVar3,local_30,param_5);
        goto LAB_680a6a00;
      }
      iVar3 = props_coerceAndReturnInt(iVar3,param_5,(int *)&local_74);
    }
    else {
      switch(param_4) {
      case 0x168:
        if (param_3 == 0) {
          local_78 = local_57;
          if ((char)(local_57 >> 0x18) != '\0') {
            events_manageCastMember(iVar3,(undefined2 *)&local_78,0);
          }
          props_storeIntValue(iVar3,local_78 & 0xff,param_5);
          goto LAB_680a6a00;
        }
        iVar3 = props_coerceAndReturnBool(iVar3,param_5,(undefined1 *)&local_78);
LAB_680a64a8:
        if (iVar3 == 0) {
          local_57 = local_78;
        }
        break;
      case 0x169:
        if (param_3 == 0) {
          local_78 = local_53;
          if ((char)(local_53 >> 0x18) != '\0') {
            events_manageCastMember(iVar3,(undefined2 *)&local_78,0);
          }
          props_storeIntValue(iVar3,local_78 & 0xff,param_5);
          goto LAB_680a6a00;
        }
        iVar3 = props_coerceAndReturnBool(iVar3,param_5,(undefined1 *)&local_78);
        if (iVar3 == 0) {
          local_53 = local_78;
        }
        break;
      default:
        goto switchD_680a65fd_caseD_16a;
      case 0x16b:
        if (param_3 == 0) {
          local_74 = local_5c;
          props_storeIntValue(iVar3,local_5c,param_5);
          goto LAB_680a6a00;
        }
        iVar3 = props_coerceAndReturnInt(iVar3,param_5,(int *)&local_74);
        if (iVar3 == 0) {
          local_5c = local_74;
        }
        break;
      case 0x16c:
        if (param_3 == 0) {
          local_74 = (uint)local_63;
          props_storeIntValue(iVar3,local_74,param_5);
          goto LAB_680a6a00;
        }
        iVar3 = props_coerceAndReturnInt(iVar3,param_5,(int *)&local_74);
        if ((iVar3 == 0) && (local_63 = (byte)local_74, local_74 == 0x20)) {
          local_2c = 1;
        }
        break;
      case 0x16e:
        if (param_3 == 0) {
          local_74 = local_3c;
          props_storeIntValue(iVar3,local_3c,param_5);
          goto LAB_680a6a00;
        }
        iVar3 = props_coerceAndReturnInt(iVar3,param_5,(int *)&local_74);
        break;
      case 0x16f:
        if (param_3 == 0) {
          local_74 = local_38;
          props_storeIntValue(iVar3,local_38,param_5);
          goto LAB_680a6a00;
        }
        iVar3 = props_coerceAndReturnInt(iVar3,param_5,(int *)&local_74);
        break;
      case 0x1e2:
        if (param_3 == 0) {
          local_74 = local_60;
          props_storeIntValue(iVar3,local_60,param_5);
          goto LAB_680a6a00;
        }
        iVar3 = props_coerceAndReturnInt(iVar3,param_5,(int *)&local_74);
        break;
      case 0x1f5:
        if (param_3 == 0) {
          local_84 = local_4c;
          local_88 = local_48;
          props_storeSymbolRef(iVar3,&local_88,param_5);
          goto LAB_680a6a00;
        }
        iVar3 = props_getContextState(iVar3,param_5);
        break;
      case 0x235:
        if (param_3 == 0) {
          local_74 = (int)((0x101 - (uint)local_58) * 100) / 0xff;
          props_storeIntValue(iVar3,local_74,param_5);
          goto LAB_680a6a00;
        }
        iVar3 = props_coerceAndReturnInt(iVar3,param_5,(int *)&local_74);
        if (iVar3 == 0) {
          iVar2 = (100 - local_74) * 0xff;
          local_58 = ((char)(iVar2 / 100) + (char)(iVar2 >> 0x1f)) -
                     (char)((longlong)iVar2 * 0x51eb851f >> 0x3f);
          local_2c = (uint)(local_58 != 0);
        }
        break;
      case 0x236:
        if (param_3 == 0) {
          local_74 = (uint)local_28;
          props_storeIntValue(iVar3,local_74,param_5);
          goto LAB_680a6a00;
        }
        iVar3 = props_coerceAndReturnInt(iVar3,param_5,(int *)&local_74);
        if (iVar3 == 0) {
          local_28 = (byte)local_74;
        }
        break;
      case 0x237:
        goto switchD_680a65fd_caseD_237;
      }
    }
  }
  else if (param_4 == 0x359) {
    if (param_3 == 0) {
      local_78 = local_53;
      props_storeFloatValue(iVar3,&local_78,param_5);
      goto LAB_680a6a00;
    }
    iVar3 = props_coerceAndStore(iVar3,param_5,(int *)&local_78);
    if (iVar3 == 0) {
      local_53 = local_78;
    }
  }
  else {
switchD_680a65fd_caseD_16a:
    iVar3 = -0x7ffbf82b;
  }
  if ((param_3 != 0) && (iVar3 == 0)) {
    Ordinal_405(*(int **)(local_80 + 4),local_90,param_2,(undefined1 *)&local_70,0);
  }
LAB_680a6a00:
  return 0;
}



// ============================================================
// Function: media_getScoreReaderData (FUN_680a6b20)
// Address: 680a6b20
// Size: 33 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreReaderData(undefined4 *param_1)

{
  *param_1 = 0x285;
  param_1[1] = 0x293;
  param_1[2] = 0;
  param_1[5] = 0;
  return 0;
}



// ============================================================
// Function: media_initScorePlayback (FUN_680a6b50)
// Address: 680a6b50
// Size: 332 bytes
// Params: int * param_1, undefined4 param_2, int * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_initScorePlayback(int *param_1,undefined4 param_2,int *param_3,int *param_4)
{
  undefined1 uVar1;
  int iVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  undefined4 local_b0;
  undefined1 local_ac [164];
  uint local_8;
  
  local_b0 = 0;
  memset(local_ac,0,0xa4);
  if (param_3[2] == 0) {
    media_getScoreReaderData(param_3);
  }
  if ((param_3[1] == 0x293) && ((*param_3 == 0x285 || (*param_3 == 0x290)))) {
    if (param_3[2] == 0) {
      iVar2 = media_writePlaybackData(param_2,0,0);
      param_4[1] = iVar2;
      piVar3 = media_getScoreStatePtr();
      iVar4 = 0;
      iVar2 = rendering_resolveChannelType(0x79f);
      media_getPlaybackByte(param_4[1],(int)piVar3,iVar2,iVar4);
    }
    else {
      iVar2 = scoreEngine_readScoreFile(param_3[2],(int)&local_b0);
      *param_4 = iVar2;
      iVar2 = media_writePlaybackData(param_2,0,*param_1);
      iVar4 = 0;
      param_4[1] = iVar2;
      iVar2 = rendering_resolveChannelType(0x79f);
      uVar1 = media_getPlaybackByte(param_4[1],*param_4,iVar2,iVar4);
      if (CONCAT31(extraout_var,uVar1) != 0) {
        iVar4 = 0;
        iVar2 = Ordinal_402(*(int **)(*param_1 + 0x28));
        Ordinal_425((int *)param_4[1],iVar2,iVar4);
        *param_4 = 0;
      }
    }
  }
  param_4[2] = 0;
  return 0;
}



// ============================================================
// Function: media_createScoreWriter (FUN_680a6ca0)
// Address: 680a6ca0
// Size: 412 bytes
// Params: int * param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_createScoreWriter(int *param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  uint local_d8 [2];
  int *local_d0;
  int *local_cc;
  int *local_c8;
  undefined4 *local_c4;
  undefined4 local_c0;
  undefined1 local_bc [4];
  undefined4 local_b8;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined2 local_54;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_c4 = param_3;
  local_c0 = 0;
  memset(local_bc,0,0xa4);
  media_getScoreReaderData(local_c4);
  if ((param_2 == 0) || (*(int **)(param_2 + 4) == (int *)0x0)) {
    return 0;
  }
  local_d0 = (int *)media_getVtableFunc(*(int **)(param_2 + 4));
  local_c8 = (int *)0x0;
  local_cc = (int *)0x0;
  media_setScorePositionEx(*(int **)(param_2 + 4),&local_c8,&local_cc);
  local_b8 = 2;
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0xc))(param_1,599,local_d8);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*param_1 + 0xc))(param_1,0xbc,local_d8);
      if (iVar1 != 0) goto LAB_680a6db5;
    }
    iVar1 = props_createRectFromValue(*(int *)(*(int *)(*local_c8 + 0x14) + 0x14),local_d8);
    if (iVar1 == 0) {
      local_68 = local_14;
      local_64 = local_18;
      local_60 = local_c;
      local_5c = local_10;
      goto LAB_680a6dc6;
    }
  }
LAB_680a6db5:
  Ordinal_1060(&local_68,0,0,0,0);
LAB_680a6dc6:
  local_54 = 0;
  local_58 = 0xe;
  iVar1 = scoreEngine_writeScoreFile(local_cc,local_d0,(int)&local_c0);
  local_c4[2] = iVar1;
  if (iVar1 != 0) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_validateSpriteOp (FUN_680a6e40)
// Address: 680a6e40
// Size: 59 bytes
// Params: void * this, int param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall media_validateSpriteOp(void *this,int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = lingo_getSpriteOpCount(this,*(int *)(param_1 + 4));
    if (iVar1 == 0) {
      Ordinal_409((int *)(param_1 + 4));
      uVar2 = 0x80040014;
    }
    *(undefined4 *)(param_1 + 8) = 1;
  }
  return uVar2;
}



// ============================================================
// Function: media_beginScorePlayback (FUN_680a6e80)
// Address: 680a6e80
// Size: 75 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_beginScorePlayback(int param_1)

{
  int iVar1;
  
  iVar1 = (-(uint)(*(int *)(param_1 + 8) != 0) & 0x7ffbf43f) + 0x80040bc1;
  if (iVar1 == 0) {
    Ordinal_412(*(int *)(param_1 + 4));
    media_isPlaybackActive(*(int *)(param_1 + 4),1);
    lingo_getSpriteOpState(*(int *)(param_1 + 4));
    Ordinal_428(*(int *)(param_1 + 4));
  }
  return iVar1;
}



// ============================================================
// Function: media_resetScoreState (FUN_680a6ed0)
// Address: 680a6ed0
// Size: 44 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_resetScoreState(int param_1)

{
  int iVar1;
  
  iVar1 = (-(uint)(*(int *)(param_1 + 8) != 0) & 0x7ffbf43f) + 0x80040bc1;
  if (iVar1 == 0) {
    Ordinal_399(*(int *)(param_1 + 4));
  }
  return iVar1;
}



// ============================================================
// Function: media_advanceScoreFrame (FUN_680a6f00)
// Address: 680a6f00
// Size: 44 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_advanceScoreFrame(int param_1)

{
  int iVar1;
  
  iVar1 = (-(uint)(*(int *)(param_1 + 8) != 0) & 0x7ffbf43f) + 0x80040bc1;
  if (iVar1 == 0) {
    Ordinal_413(*(int *)(param_1 + 4));
  }
  return iVar1;
}



// ============================================================
// Function: media_beginScorePlaybackEx (FUN_680a6f30)
// Address: 680a6f30
// Size: 75 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_beginScorePlaybackEx(int param_1)

{
  int iVar1;
  
  iVar1 = (-(uint)(*(int *)(param_1 + 8) != 0) & 0x7ffbf43f) + 0x80040bc1;
  if (iVar1 == 0) {
    media_isPlaybackActive(*(int *)(param_1 + 4),1);
    lingo_getSpriteOpState(*(int *)(param_1 + 4));
    lingo_getSpriteOpRef(*(int *)(param_1 + 4));
    Ordinal_428(*(int *)(param_1 + 4));
  }
  return iVar1;
}



// ============================================================
// Function: media_getNextKeyframe (FUN_680a6f80)
// Address: 680a6f80
// Size: 374 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getNextKeyframe(int *param_1,int param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_34;
  int *local_30;
  uint local_2c;
  int local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = *param_1;
  local_34 = param_1[1];
  local_30 = param_3;
  local_18 = 0x80040bc5;
  if ((local_28 == 0) &&
     (lingo_resolveContext(&local_28,(int *)0x0,(int *)0x0,&local_34,(int *)0x0,(int *)0x0,(int *)0x0),
     local_28 == 0)) {
    local_1c = 0;
  }
  else {
    iVar2 = local_28;
    local_1c = *(int *)(local_28 + 0x20);
    if ((local_1c != 0) && (*(int *)(local_1c + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  *param_3 = 0;
  piVar1 = (int *)scoreEngine_getChannelField(local_1c,(short)param_1[3]);
  if (piVar1 == (int *)0x0) {
    local_18 = 0x80040bc4;
    goto LAB_680a70cc;
  }
  local_24 = CONCAT22((undefined2)param_2,(short)piVar1[1]);
  iVar2 = rendering_resolveStateEx(*piVar1,local_24,&local_2c,&local_20);
  if (local_2c == 0) {
    iVar2 = 0;
  }
  else {
    local_20 = Ordinal_1156(piVar1[0x10],piVar1[0x11],iVar2 + 1);
    if (local_20 == 0) goto LAB_680a70cc;
    if (*(int *)(local_20 + 8) != 0) {
      *param_3 = (int)*(short *)(local_20 + 6);
LAB_680a70c5:
      local_18 = 0;
      goto LAB_680a70cc;
    }
    iVar2 = iVar2 + 2;
  }
  iVar3 = Ordinal_1154(piVar1[0x10]);
  for (; iVar2 < iVar3; iVar2 = iVar2 + 1) {
    local_20 = Ordinal_1156(piVar1[0x10],piVar1[0x11],iVar2);
    if (((local_20 != 0) && (*(int *)(local_20 + 8) != 0)) && (param_2 < *(short *)(local_20 + 6)))
    {
      *local_30 = (int)*(short *)(local_20 + 6);
      goto LAB_680a70c5;
    }
  }
LAB_680a70cc:
  if (local_1c != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getChannelMode (FUN_680a7100)
// Address: 680a7100
// Size: 203 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelMode(int *param_1,int *param_2)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int local_20;
  int local_1c [3];
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = param_1[1];
  local_1c[0] = *param_1;
  local_1c[1] = 0;
  if (local_1c[0] == 0) {
    lingo_resolveContext(local_1c,(int *)0x0,(int *)0x0,&local_20,(int *)0x0,(int *)0x0,(int *)0x0);
    if (local_1c[0] == 0) {
      iVar3 = 0;
      goto LAB_680a717c;
    }
  }
  iVar2 = local_1c[0];
  iVar3 = *(int *)(local_1c[0] + 0x20);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = local_1c + 2;
    local_1c[2] = iVar2;
  }
LAB_680a717c:
  iVar2 = scoreEngine_getChannelField(iVar3,(short)param_1[3]);
  if (iVar2 == 0) {
    local_1c[1] = 0x80040bc4;
  }
  else {
    sVar1 = rendering_getChannelMode(iVar2);
    *param_2 = (int)sVar1;
  }
  if (iVar3 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getChannelSpan (FUN_680a71d0)
// Address: 680a71d0
// Size: 281 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelSpan(int *param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int local_28;
  int *local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = param_1[1];
  local_24 = param_2;
  local_20 = *param_1;
  local_18 = 0x80040bc5;
  if ((local_20 == 0) &&
     (lingo_resolveContext(&local_20,(int *)0x0,(int *)0x0,&local_28,(int *)0x0,(int *)0x0,(int *)0x0),
     local_20 == 0)) {
    iVar3 = 0;
  }
  else {
    iVar2 = local_20;
    iVar3 = *(int *)(local_20 + 0x20);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  *local_24 = 0;
  piVar1 = (int *)scoreEngine_getChannelField(iVar3,(short)param_1[3]);
  if (piVar1 == (int *)0x0) {
    local_18 = 0x80040bc4;
  }
  else {
    sVar4 = 1;
    local_1c = CONCAT22(1,(short)piVar1[1]);
    do {
      iVar2 = rendering_resolveState(*piVar1,local_1c);
      if ((iVar2 == 0) || (*(int *)(iVar2 + 8) == 0)) {
        *local_24 = (int)sVar4;
        break;
      }
      sVar4 = sVar4 + 1;
      local_1c = CONCAT22(sVar4,(undefined2)local_1c);
    } while (sVar4 < 0x7d01);
  }
  if (iVar3 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getNextChannelFrame (FUN_680a72f0)
// Address: 680a72f0
// Size: 286 bytes
// Params: int * param_1, short param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getNextChannelFrame(int *param_1,short param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int local_28;
  int *local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = param_1[1];
  local_24 = param_3;
  local_20 = *param_1;
  local_18 = 0x80040bc5;
  if ((local_20 == 0) &&
     (lingo_resolveContext(&local_20,(int *)0x0,(int *)0x0,&local_28,(int *)0x0,(int *)0x0,(int *)0x0),
     local_20 == 0)) {
    iVar3 = 0;
  }
  else {
    iVar2 = local_20;
    iVar3 = *(int *)(local_20 + 0x20);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  *local_24 = 0;
  piVar1 = (int *)scoreEngine_getChannelField(iVar3,(short)param_1[3]);
  if (piVar1 == (int *)0x0) {
    local_18 = 0x80040bc4;
  }
  else {
    sVar4 = param_2 + 1;
    local_1c = CONCAT22(sVar4,(short)piVar1[1]);
    while (sVar4 < 0x7d01) {
      iVar2 = rendering_resolveState(*piVar1,local_1c);
      if ((iVar2 == 0) || (*(int *)(iVar2 + 8) == 0)) {
        *local_24 = (int)sVar4;
        local_18 = 0;
        break;
      }
      sVar4 = sVar4 + 1;
      local_1c = CONCAT22(sVar4,(undefined2)local_1c);
    }
  }
  if (iVar3 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getLastChannelFrame (FUN_680a7410)
// Address: 680a7410
// Size: 266 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getLastChannelFrame(int *param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  short sVar4;
  int local_28;
  int *local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = param_1[1];
  local_24 = param_2;
  local_20 = *param_1;
  local_18 = 0x80040bc5;
  if ((local_20 == 0) &&
     (lingo_resolveContext(&local_20,(int *)0x0,(int *)0x0,&local_28,(int *)0x0,(int *)0x0,(int *)0x0),
     local_20 == 0)) {
    iVar3 = 0;
  }
  else {
    iVar2 = local_20;
    iVar3 = *(int *)(local_20 + 0x20);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  *local_24 = 0;
  piVar1 = (int *)scoreEngine_getChannelField(iVar3,(short)param_1[3]);
  if (piVar1 == (int *)0x0) {
    local_18 = 0x80040bc4;
  }
  else {
    sVar4 = 32000;
    local_1c = CONCAT22(32000,(short)piVar1[1]);
    do {
      iVar2 = rendering_resolveState(*piVar1,local_1c);
      if ((iVar2 == 0) || (*(int *)(iVar2 + 8) == 0)) {
        *local_24 = (int)sVar4;
        break;
      }
      sVar4 = sVar4 + -1;
      local_1c = CONCAT22(sVar4,(undefined2)local_1c);
    } while (0 < sVar4);
  }
  if (iVar3 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getMemberDataBlock (FUN_680a7520)
// Address: 680a7520
// Size: 232 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getMemberDataBlock(int *param_1,int param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  int local_24;
  int *local_20;
  int local_1c;
  undefined4 local_18;
  short sStack_16;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = *param_1;
  iVar2 = 0;
  local_20 = param_3;
  local_24 = param_1[1];
  local_18 = 0;
  if (local_1c == 0) {
    lingo_resolveContext(&local_1c,(int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0);
    if (local_1c == 0) {
      piVar1 = (int *)0x0;
      goto LAB_680a757b;
    }
  }
  piVar1 = *(int **)(local_1c + 0x20);
LAB_680a757b:
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar2 = local_1c;
    if (local_1c == 0) {
      iVar2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  iVar2 = rendering_getMemberDataBlock(iVar2,(short)param_1[3],param_2,-1,&stack0xffffffe8);
  if (iVar2 == 0) {
    *local_20 = 0;
  }
  else {
    *local_20 = (int)sStack_16;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_readScoreBlock2 (FUN_680a7610)
// Address: 680a7610
// Size: 68 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_readScoreBlock2(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if (param_2 - 1U < 32000) {
    *param_3 = *param_1;
    param_3[1] = param_1[1];
    param_3[2] = param_1[2];
    uVar1 = param_1[3];
    param_3[4] = param_2;
    param_3[3] = uVar1;
    return 0;
  }
  return 0x800407d8;
}



// ============================================================
// Function: media_readCastDataFromChannel (FUN_680a7660)
// Address: 680a7660
// Size: 317 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_readCastDataFromChannel(int *param_1,undefined4 param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_438;
  int local_434 [3];
  int *local_428;
  undefined4 local_424;
  undefined4 local_420;
  undefined1 local_41c [1044];
  uint local_8;
  
  local_434[1] = 0;
  local_420 = 0;
  memset(local_41c,0,0x414);
  local_434[0] = *param_1;
  local_438 = param_1[1];
  if (local_434[0] == 0) {
    lingo_resolveContext(local_434,(int *)0x0,(int *)0x0,&local_438,(int *)0x0,(int *)0x0,(int *)0x0);
    if (local_434[0] == 0) {
      iVar3 = 0;
      goto LAB_680a7716;
    }
  }
  iVar2 = local_434[0];
  iVar3 = *(int *)(local_434[0] + 0x20);
  if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
    Ordinal_2330();
    local_424 = 0;
    local_428 = DAT_68196374;
    DAT_68196374 = local_434 + 2;
    local_434[2] = iVar2;
  }
LAB_680a7716:
  piVar1 = (int *)scoreEngine_getChannelField(iVar3,(short)param_1[3]);
  if (piVar1 == (int *)0x0) {
    local_434[1] = 0x80040bc4;
  }
  else {
    Ordinal_1309(&local_420,0x400,param_2,2);
    iVar2 = rendering_readCastData(iVar3,piVar1,&local_420,(void *)0x0);
    if (iVar2 == 0) {
      local_434[1] = 0x800407de;
    }
  }
  if (iVar3 != 0) {
    DAT_68196374 = local_428;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_importMemberFromChannel (FUN_680a77a0)
// Address: 680a77a0
// Size: 219 bytes
// Params: int * param_1, undefined2 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_importMemberFromChannel(int *param_1,undefined2 param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_20;
  int local_1c;
  undefined2 local_18;
  undefined2 local_16;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = *param_1;
  local_20 = param_1[1];
  if (local_1c == 0) {
    lingo_resolveContext(&local_1c,(int *)0x0,(int *)0x0,&local_20,(int *)0x0,(int *)0x0,(int *)0x0);
    if (local_1c == 0) {
      piVar2 = (int *)0x0;
      goto LAB_680a77e8;
    }
  }
  piVar2 = *(int **)(local_1c + 0x20);
LAB_680a77e8:
  iVar3 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar1 = local_1c;
    if (local_1c == 0) {
      iVar1 = *piVar2;
    }
    if (piVar2[2] == 0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *(int *)(piVar2[2] + 0xc);
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  local_18 = (undefined2)param_1[3];
  local_16 = param_2;
  iVar1 = sprites_getMemberInfo(iVar3,(undefined4 *)&local_18);
  sprites_importMemberFromFile(iVar3,iVar1,param_3);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getChannelPropertyEx (FUN_680a7880)
// Address: 680a7880
// Size: 1076 bytes
// Params: int * param_1, int param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelPropertyEx(int *param_1,int param_2,int param_3,uint *param_4)
{
  ushort uVar1;
  short sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_430;
  int local_42c;
  int local_428;
  int local_424;
  uint local_420;
  int *local_41c;
  int local_418;
  int local_414;
  int *local_410;
  undefined4 local_40c;
  byte local_408;
  char local_407 [1023];
  uint local_8;
  
  local_424 = param_1[3];
  local_430 = param_1[1];
  iVar5 = 0;
  local_428 = *param_1;
  local_418 = 0;
  if ((local_428 == 0) &&
     (lingo_resolveContext(&local_428,(int *)0x0,(int *)0x0,&local_430,(int *)0x0,(int *)0x0,(int *)0x0),
     local_428 == 0)) {
    local_41c = (int *)0x0;
  }
  else {
    local_41c = *(int **)(local_428 + 0x20);
  }
  if ((local_41c != (int *)0x0) && (local_41c[1] != 0)) {
    local_42c = local_428;
    if (local_428 == 0) {
      local_42c = *local_41c;
    }
    if (local_41c[2] == 0) {
      iVar5 = 0;
    }
    else {
      iVar5 = *(int *)(local_41c[2] + 0xc);
    }
    Ordinal_2330();
    local_410 = DAT_68196374;
    local_414 = local_42c;
    local_40c = 0;
    DAT_68196374 = &local_414;
  }
  iVar3 = scoreEngine_getChannelField((int)local_41c,(short)local_424);
  if (0x1fd < param_3) {
    switch(param_3) {
    case 0x25c:
      if (param_2 != 0) {
        local_418 = -0x7ffbf82a;
        goto LAB_680a7c82;
      }
      iVar3 = scoreEngine_getChannelField((int)local_41c,(short)param_1[3]);
      if (iVar3 != 0) {
        local_420 = Ordinal_1154(*(undefined4 *)(iVar3 + 0x40));
        local_418 = props_storeIntValue(iVar5,local_420,param_4);
        goto LAB_680a7c82;
      }
      break;
    case 0x25d:
      if (param_2 != 0) {
        local_418 = -0x7ffbf82a;
        goto LAB_680a7c82;
      }
      iVar3 = scoreEngine_getChannelField((int)local_41c,(short)param_1[3]);
      if (iVar3 != 0) {
        sVar2 = rendering_getFirstActiveFrame(iVar3);
        local_420 = (uint)sVar2;
        local_418 = props_storeIntValue(iVar5,local_420,param_4);
        goto LAB_680a7c82;
      }
      break;
    case 0x25e:
      if (param_2 != 0) {
        local_418 = -0x7ffbf82a;
        goto LAB_680a7c82;
      }
      iVar3 = scoreEngine_getChannelField((int)local_41c,(short)param_1[3]);
      if (iVar3 != 0) {
        sVar2 = rendering_getChannelMode(iVar3);
        local_420 = (uint)sVar2;
        local_418 = props_storeIntValue(iVar5,local_420,param_4);
        goto LAB_680a7c82;
      }
      break;
    default:
switchD_680a7996_caseD_104:
      local_418 = -0x7ffbf82b;
      goto LAB_680a7c82;
    case 0x267:
      if (param_2 == 0) {
        local_420 = sprites_getMemberFlag(iVar5,(short)param_1[3]);
        local_418 = props_storeIntValue(iVar5,local_420,param_4);
      }
      else {
        local_418 = props_coerceAndReturnInt(iVar5,param_4,(int *)&local_420);
        if (local_418 == 0) {
          if (local_420 < 3) {
            sprites_setMemberFlag(iVar5,(short)param_1[3],(int)(short)local_420);
          }
          else {
            local_418 = -0x7ffbf828;
          }
        }
      }
      goto LAB_680a7c82;
    }
    local_418 = -0x7ffbf43c;
    goto LAB_680a7c82;
  }
  if (param_3 == 0x1fd) {
    if (param_2 == 0) {
      local_418 = props_storeIntValue(iVar5,*(undefined4 *)(iVar3 + 0x18),param_4);
    }
    else {
      local_418 = -0x7ffbf82a;
    }
    goto LAB_680a7c82;
  }
  switch(param_3) {
  case 0x103:
    if (param_2 == 0) {
      sprites_getMemberName(iVar5,(short)param_1[3],&local_408);
LAB_680a79f8:
      props_loadStringValue(iVar5,local_407,param_4);
      if ((*param_4 != 0x40) && (*param_4 != 0x43)) {
        local_418 = -0x7ffbfffe;
      }
      goto LAB_680a7c82;
    }
    piVar4 = props_getApiContext((int *)param_4);
    if (piVar4 != (int *)0x0) {
      Ordinal_1233(&local_408,piVar4);
      sprites_setMemberName(iVar5,(short)param_1[3],&local_408);
      props_getApiState((int *)param_4);
      goto LAB_680a7c82;
    }
    break;
  default:
    goto switchD_680a7996_caseD_104;
  case 300:
    if (param_2 == 0) {
      uVar1 = rendering_getChannelType(iVar3 + 0x68);
      local_418 = props_storeIntValue(iVar5,(uint)uVar1,param_4);
    }
    else {
      local_418 = -0x7ffbf82a;
    }
    goto LAB_680a7c82;
  case 0x1b1:
    if (param_2 == 0) {
      sprites_getNetworkErrorString(iVar5,local_424,param_4);
    }
    else {
      sprites_setAlertHook(iVar5,local_424,param_4);
    }
    goto LAB_680a7c82;
  case 0x1b2:
    if (param_2 == 0) {
      sprites_getMemberComment(iVar5,(short)param_1[3],&local_408);
      goto LAB_680a79f8;
    }
    piVar4 = props_getApiContext((int *)param_4);
    if (piVar4 != (int *)0x0) {
      Ordinal_1233(&local_408,piVar4);
      sprites_setMemberComment(iVar5,(short)param_1[3],&local_408);
      props_getApiState((int *)param_4);
      goto LAB_680a7c82;
    }
  }
  local_418 = -0x7ffbf824;
LAB_680a7c82:
  if (local_41c != (int *)0x0) {
    DAT_68196374 = local_410;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_resolveChannelRef (FUN_680a7da0)
// Address: 680a7da0
// Size: 172 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resolveChannelRef(int param_1,int *param_2)
{
  short *psVar1;
  int *piVar2;
  int iVar3;
  short sVar4;
  undefined2 extraout_var;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  int *local_8;
  
  iVar3 = param_1;
  if (*(int *)(param_1 + 8) != 0) {
    lingo_resolveContext(&local_24,&local_20,&local_1c,&local_18,&local_14,&local_10,(int *)&local_8);
    psVar1 = (short *)(param_1 + 0xc);
    piVar2 = (int *)(param_1 + 8);
    param_1 = 0;
    local_c = CONCAT22(*(undefined2 *)(iVar3 + 0x10),*psVar1);
    if ((*piVar2 == 0) && (local_8 != (int *)0x0)) {
      sVar4 = scoreEngine_getChannelData((int)local_8,*psVar1);
      local_c = CONCAT22(extraout_var,sVar4);
    }
    if (local_8[1] != 0) {
      param_1 = Ordinal_363(local_8[1],*local_8,(short)local_c);
    }
    *param_2 = (int)(short)param_1;
    param_2[1] = (int)(short)((uint)param_1 >> 0x10);
    return 0;
  }
  *param_2 = *(int *)(param_1 + 0xc);
  param_2[1] = *(int *)(param_1 + 0x10);
  return 0;
}



// ============================================================
// Function: media_getChannelOffset (FUN_680a7e50)
// Address: 680a7e50
// Size: 20 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getChannelOffset(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(param_1 + 0x10);
  return 0;
}



// ============================================================
// Function: media_updateChannelMediaRef (FUN_680a7e70)
// Address: 680a7e70
// Size: 247 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_updateChannelMediaRef(int *param_1)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  int local_20;
  byte *local_1c;
  undefined4 local_18;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = (byte *)*param_1;
  local_20 = param_1[1];
  pbVar3 = (byte *)0x0;
  if ((local_1c == (byte *)0x0) &&
     (lingo_resolveContext((int *)&local_1c,(int *)0x0,(int *)0x0,&local_20,(int *)0x0,(int *)0x0,(int *)0x0
                  ), local_1c == (byte *)0x0)) {
    puVar4 = (undefined4 *)0x0;
  }
  else {
    puVar4 = *(undefined4 **)(local_1c + 0x20);
  }
  if ((puVar4 != (undefined4 *)0x0) && (puVar4[1] != 0)) {
    pbVar3 = local_1c;
    if (local_1c == (byte *)0x0) {
      pbVar3 = (byte *)*puVar4;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar3;
  }
  local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
  uVar2 = local_18;
  if (param_1[2] == 0) {
    if (puVar4 == (undefined4 *)0x0) {
      return 0;
    }
    sVar1 = scoreEngine_getChannelData((int)puVar4,(short)param_1[3]);
    uVar2 = CONCAT22(extraout_var,sVar1);
  }
  rendering_updateMediaRef(pbVar3,uVar2);
  if (puVar4 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_copyChannelMember (FUN_680a7f70)
// Address: 680a7f70
// Size: 252 bytes
// Params: int * param_1, int param_2, undefined2 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_copyChannelMember(int *param_1,int param_2,undefined2 param_3)
{
  int *piVar1;
  int iVar2;
  int local_28;
  undefined2 local_24;
  undefined2 local_22;
  int local_20;
  int local_1c;
  undefined2 local_18;
  undefined2 local_16;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = param_1[1];
  local_1c = *param_1;
  iVar2 = 0;
  if ((local_1c == 0) &&
     (lingo_resolveContext(&local_1c,(int *)0x0,(int *)0x0,&local_28,(int *)0x0,(int *)0x0,(int *)0x0),
     local_1c == 0)) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(local_1c + 0x20);
  }
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    local_20 = local_1c;
    if (local_1c == 0) {
      local_20 = *piVar1;
    }
    if (piVar1[2] == 0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *(int *)(piVar1[2] + 0xc);
    }
    Ordinal_2330();
    local_14 = local_20;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  local_18 = (undefined2)param_1[3];
  local_16 = (undefined2)param_1[4];
  local_24 = *(undefined2 *)(param_2 + 0xc);
  local_22 = param_3;
  sprites_copyMemberToCast(iVar2,(undefined4 *)&local_18,(undefined4 *)&local_24);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_mapMediaTypeToIndex (FUN_680a8070)
// Address: 680a8070
// Size: 284 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_mapMediaTypeToIndex(void)
{
  int iVar1;
  int *in_EAX;
  int *unaff_ESI;
  
  iVar1 = *unaff_ESI;
  if (iVar1 < 0x291) {
    if (iVar1 == 0x290) {
      *in_EAX = 0;
      goto LAB_680a8103;
    }
    if (iVar1 < 0x171) {
      if (iVar1 == 0x170) {
        *in_EAX = 3;
        goto LAB_680a8103;
      }
      if (iVar1 == 0x54) {
        *in_EAX = 4;
        goto LAB_680a8103;
      }
      if (iVar1 == 0xfb) {
        *in_EAX = 6;
        goto LAB_680a8103;
      }
    }
    else if (iVar1 == 0x285) {
      *in_EAX = 5;
      goto LAB_680a8103;
    }
switchD_680a80da_caseD_293:
    *in_EAX = iVar1;
  }
  else {
    switch(iVar1) {
    case 0x291:
      *in_EAX = 2;
      break;
    case 0x292:
      *in_EAX = 7;
      break;
    default:
      goto switchD_680a80da_caseD_293;
    case 0x337:
      *in_EAX = 8;
      break;
    case 0x35f:
      *in_EAX = 1;
    }
  }
LAB_680a8103:
  switch(unaff_ESI[1]) {
  case 0x293:
    in_EAX[1] = 0;
    break;
  default:
    in_EAX[1] = unaff_ESI[1];
    break;
  case 0x296:
    in_EAX[1] = 2;
    break;
  case 0x298:
    in_EAX[1] = 4;
    break;
  case 0x299:
    in_EAX[1] = 5;
    break;
  case 0x29a:
    in_EAX[1] = 3;
    break;
  case 0x29b:
    in_EAX[1] = 6;
    break;
  case 0x29d:
    in_EAX[1] = 8;
    break;
  case 0x29e:
    in_EAX[1] = 7;
    break;
  case 0x2ed:
    in_EAX[1] = 1;
  }
  in_EAX[2] = unaff_ESI[2];
  in_EAX[3] = unaff_ESI[3];
  in_EAX[4] = unaff_ESI[4];
  in_EAX[5] = unaff_ESI[5];
  return 0;
}



// ============================================================
// Function: media_mapIndexToMediaType (FUN_680a8300)
// Address: 680a8300
// Size: 195 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_mapIndexToMediaType(undefined4 param_1,undefined4 *param_2)
{
  undefined4 *in_EAX;
  
  switch(*param_2) {
  case 0:
    *in_EAX = 0x290;
    break;
  case 2:
    *in_EAX = 0x291;
    break;
  case 3:
    *in_EAX = 0x170;
    break;
  case 4:
    *in_EAX = 0x54;
    break;
  case 5:
    *in_EAX = 0x285;
    break;
  case 6:
    *in_EAX = 0xfb;
    break;
  case 7:
    *in_EAX = 0x292;
    break;
  case 8:
    *in_EAX = 0x337;
  }
  switch(param_2[1]) {
  case 0:
    in_EAX[1] = 0x293;
    break;
  case 1:
    in_EAX[1] = 0x2ed;
    break;
  case 2:
    in_EAX[1] = 0x296;
    break;
  case 3:
    in_EAX[1] = 0x29a;
    break;
  case 4:
    in_EAX[1] = 0x298;
    break;
  case 5:
    in_EAX[1] = 0x299;
    break;
  case 6:
    in_EAX[1] = 0x29b;
    break;
  case 7:
    in_EAX[1] = 0x29e;
    break;
  case 8:
    in_EAX[1] = 0x29d;
  }
  in_EAX[2] = param_2[2];
  in_EAX[3] = param_2[3];
  in_EAX[4] = param_2[4];
  in_EAX[5] = param_2[5];
  return 0;
}



// ============================================================
// Function: media_getMediaErrorCode (FUN_680a8410)
// Address: 680a8410
// Size: 69 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getMediaErrorCode(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return 0;
  case 1:
    return 0x80040001;
  case 2:
    return 0x80040bbb;
  case 3:
    return 0x80040bbc;
  case 4:
    return 0x80040bbd;
  case 5:
    return 0x80040bbe;
  case 6:
    return 0x80040bbf;
  case 7:
    return 0x80040bc0;
  case 8:
    return 0x80040bc5;
  default:
    return 0x80040014;
  }
}



// ============================================================
// Function: media_renderScoreFrame (FUN_680a8480)
// Address: 680a8480
// Size: 365 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_renderScoreFrame(int param_1,int *param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int local_430;
  undefined4 local_42c;
  undefined4 local_428;
  int local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  local_424 = 0;
  local_430 = 0;
  local_42c = 0;
  local_428 = 0;
  if (*(int *)(param_3 + 4) != 8) {
    return 0;
  }
  iVar1 = rendering_getFrameCount((int)param_2);
  if (iVar1 != 0) {
    iVar1 = rendering_dispatchUpdate(param_1,param_2,local_420,1);
    if ((iVar1 != 0) && (iVar1 = Ordinal_1402(&local_424,local_420,1), iVar1 != 0)) {
      uVar2 = Ordinal_1330(local_420);
      uVar3 = Ordinal_1435(local_424);
      local_430 = Ordinal_1927(local_424,uVar2,uVar3,&local_428,&local_42c);
      if (local_430 != 0) {
        uVar2 = Ordinal_1931(uVar2,local_430,local_428,local_42c);
        *(undefined4 *)(param_3 + 8) = uVar2;
      }
    }
    if (local_424 != 0) {
      Ordinal_1407(&local_424);
    }
    Ordinal_1113(&local_430);
    Ordinal_1113(&local_428);
    Ordinal_1113(&local_42c);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_getChannelMediaInfo (FUN_680a85f0)
// Address: 680a85f0
// Size: 277 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelMediaInfo(int *param_1,undefined4 param_2)
{
  short sVar1;
  undefined2 extraout_var;
  int *piVar2;
  undefined4 extraout_ECX;
  int iVar3;
  int *piVar4;
  undefined4 local_3c [6];
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_24 = param_1[1];
  local_1c = param_2;
  local_20 = *param_1;
  if (local_20 == 0) {
    lingo_resolveContext(&local_20,(int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0);
    if (local_20 == 0) {
      piVar4 = (int *)0x0;
      goto LAB_680a863b;
    }
  }
  piVar4 = *(int **)(local_20 + 0x20);
LAB_680a863b:
  iVar3 = 0;
  if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
    iVar3 = local_20;
    if (local_20 == 0) {
      iVar3 = *piVar4;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
  if (param_1[2] == 0) {
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    sVar1 = scoreEngine_getChannelData((int)piVar4,(short)param_1[3]);
    local_18 = CONCAT22(extraout_var,sVar1);
  }
  piVar2 = (int *)media_mapMediaTypeToIndex();
  rendering_getMediaInfo(*(undefined4 **)(iVar3 + 0x20),local_18,piVar2);
  media_mapIndexToMediaType(extraout_ECX,local_3c);
  media_getMediaErrorCode();
  if (piVar4 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_initChannelState (FUN_680a8710)
// Address: 680a8710
// Size: 316 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_initChannelState(int *param_1,undefined4 param_2)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_48;
  int local_44;
  undefined4 local_40;
  int local_3c [4];
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_48 = param_1[1];
  local_44 = *param_1;
  if ((local_44 == 0) &&
     (lingo_resolveContext(&local_44,(int *)0x0,(int *)0x0,&local_48,(int *)0x0,(int *)0x0,(int *)0x0),
     local_44 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(local_44 + 0x20);
  }
  iVar3 = 0;
  if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
    local_40 = *(int *)(piVar5[1] + 8);
    iVar4 = local_44;
    if (local_44 == 0) {
      iVar4 = *piVar5;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar3 = local_40;
    DAT_68196374 = &local_14;
    local_14 = iVar4;
  }
  local_40 = CONCAT22((short)param_1[4],(short)param_1[3]);
  uVar2 = local_40;
  if (param_1[2] == 0) {
    if (piVar5 == (int *)0x0) {
      return 0;
    }
    sVar1 = scoreEngine_getChannelData((int)piVar5,(short)param_1[3]);
    uVar2 = CONCAT22(extraout_var,sVar1);
  }
  iVar3 = rendering_resolveState(iVar3,uVar2);
  if (iVar3 != 0) {
    local_3c[1] = 0;
    local_2c = 0;
    local_28 = 0;
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_18 = 0;
    local_3c[2] = 0x15;
    local_3c[3] = param_2;
    local_3c[0] = iVar3;
    rendering_initState(local_3c);
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_dispatchChannelProperty (FUN_680a8850)
// Address: 680a8850
// Size: 291 bytes
// Params: int * param_1, int param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchChannelProperty(int *param_1,int param_2,uint param_3,uint *param_4)
{
  short sVar1;
  undefined2 extraout_var;
  void *pvVar2;
  int *piVar3;
  int local_24;
  int local_20;
  uint *local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_24 = param_1[1];
  local_1c = param_4;
  local_20 = *param_1;
  if ((local_20 == 0) &&
     (lingo_resolveContext(&local_20,(int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0),
     local_20 == 0)) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(local_20 + 0x20);
  }
  pvVar2 = (void *)0x0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    local_18 = local_20;
    if (local_20 == 0) {
      local_18 = *piVar3;
    }
    if (piVar3[2] == 0) {
      pvVar2 = (void *)0x0;
    }
    else {
      pvVar2 = *(void **)(piVar3[2] + 0xc);
    }
    Ordinal_2330();
    local_14 = local_18;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
  if ((param_1[2] == 0) && (piVar3 != (int *)0x0)) {
    sVar1 = scoreEngine_getChannelData((int)piVar3,(short)param_1[3]);
    local_18 = CONCAT22(extraout_var,sVar1);
  }
  if (piVar3[2] != 0) {
    if (param_2 == 0) {
      props_clearValue(pvVar2,local_1c);
    }
    sprites_dispatchPropertyEx(pvVar2,local_18,param_2,param_3,local_1c);
    DAT_68196374 = local_10;
    Ordinal_2331();
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_getChannelStateFlags (FUN_680a8980)
// Address: 680a8980
// Size: 278 bytes
// Params: int * param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelStateFlags(int *param_1,uint *param_2)
{
  short sVar1;
  undefined2 extraout_var;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_28;
  int local_24;
  uint *local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = param_1[1];
  local_20 = param_2;
  local_24 = *param_1;
  local_1c = 0;
  if (local_24 == 0) {
    lingo_resolveContext(&local_24,(int *)0x0,(int *)0x0,&local_28,(int *)0x0,(int *)0x0,(int *)0x0);
    if (local_24 == 0) {
      piVar3 = (int *)0x0;
      goto LAB_680a89d0;
    }
  }
  piVar3 = *(int **)(local_24 + 0x20);
LAB_680a89d0:
  iVar2 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    local_18 = *(int *)(piVar3[1] + 8);
    iVar4 = local_24;
    if (local_24 == 0) {
      iVar4 = *piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = local_18;
    DAT_68196374 = &local_14;
    local_14 = iVar4;
  }
  local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
  if (param_1[2] == 0) {
    if (piVar3 == (int *)0x0) {
      local_1c = 0x80040014;
    }
    else {
      sVar1 = scoreEngine_getChannelData((int)piVar3,(short)param_1[3]);
      local_18 = CONCAT22(extraout_var,sVar1);
    }
  }
  iVar2 = rendering_resolveState(iVar2,local_18);
  if (iVar2 == 0) {
    *local_20 = 0;
    local_1c = 0x800407d8;
  }
  else {
    if ((*(byte *)(iVar2 + 0x38) & 2) != 0) {
      *local_20 = *local_20 | 1;
    }
    if ((*(byte *)(iVar2 + 0x38) & 1) != 0) {
      *local_20 = *local_20 | 2;
    }
  }
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_setChannelStateFlags (FUN_680a8aa0)
// Address: 680a8aa0
// Size: 293 bytes
// Params: int * param_1, byte param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setChannelStateFlags(int *param_1,byte param_2)
{
  uint uVar1;
  short sVar2;
  undefined2 extraout_var;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_24 = *param_1;
  local_28 = param_1[1];
  iVar4 = 0;
  local_1c = 0;
  if ((local_24 == 0) &&
     (lingo_resolveContext(&local_24,(int *)0x0,(int *)0x0,&local_28,(int *)0x0,(int *)0x0,(int *)0x0),
     local_24 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(local_24 + 0x20);
  }
  local_20 = 0;
  if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
    iVar4 = *(int *)(piVar5[1] + 8);
    local_20 = local_24;
    if (local_24 == 0) {
      local_20 = *piVar5;
    }
    Ordinal_2330();
    local_14 = local_20;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
  if (param_1[2] == 0) {
    if (piVar5 == (int *)0x0) {
      local_1c = 0x80040014;
    }
    else {
      sVar2 = scoreEngine_getChannelData((int)piVar5,(short)param_1[3]);
      local_18 = CONCAT22(extraout_var,sVar2);
    }
  }
  piVar3 = (int *)rendering_resolveState(iVar4,local_18);
  uVar1 = local_18;
  if (piVar3 == (int *)0x0) {
    local_1c = 0x800407d8;
  }
  else {
    local_18 = local_18 & 0xffffff00;
    if ((param_2 & 1) != 0) {
      local_18 = CONCAT31(SUB43(uVar1,1),2);
    }
    if ((param_2 & 2) != 0) {
      local_18 = local_18 | 1;
    }
    if (local_20 != 0) {
      rendering_setMemberData(local_20,piVar3,(byte)local_18);
    }
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_findSpriteByRef (FUN_680a8bd0)
// Address: 680a8bd0
// Size: 200 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_findSpriteByRef(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 local_8;
  
  iVar5 = *(int *)(param_1 + 0x120);
  local_8 = 0;
  uVar4 = 0;
  if (iVar5 <= *(int *)(param_1 + 0x124)) {
    iVar2 = iVar5 * 400;
    do {
      if (*(char *)(iVar5 + *(int *)(param_1 + 0x30)) != '\0') {
        puVar6 = (undefined4 *)(*(int *)(param_1 + 0x34) + iVar2);
        iVar3 = playback_getSpriteData(param_1,puVar6);
        if (iVar3 != 0) {
          iVar1 = *(int *)(iVar3 + 8);
          if (((iVar1 == 0xf) && ((short)param_2 == *(short *)(iVar3 + 4))) &&
             ((*(unsigned short *)((char *)&param_2 + 2)) == *(short *)(iVar3 + 6))) {
            if ((int *)puVar6[0x52] != (int *)0x0) {
              local_8 = media_dispatchSetScale(param_1,(int *)puVar6[0x52],param_3);
            }
          }
          else if (((iVar1 == 2) || (iVar1 == 9)) && (puVar6[0x53] != 0)) {
            local_8 = media_findSpriteByRef(puVar6[0x53],param_2,param_3);
          }
        }
      }
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + 400;
      uVar4 = local_8;
    } while (iVar5 <= *(int *)(param_1 + 0x124));
  }
  return uVar4;
}



// ============================================================
// Function: media_findSpriteInChannel (FUN_680a8ca0)
// Address: 680a8ca0
// Size: 255 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_findSpriteInChannel(int *param_1,undefined4 param_2,undefined4 param_3)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = param_1[1];
  local_24 = param_3;
  local_1c = *param_1;
  if ((local_1c == 0) &&
     (lingo_resolveContext(&local_1c,(int *)0x0,(int *)0x0,&local_20,(int *)0x0,(int *)0x0,(int *)0x0),
     local_1c == 0)) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(local_1c + 0x20);
  }
  iVar3 = 0;
  if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
    iVar3 = local_1c;
    if (local_1c == 0) {
      iVar3 = *piVar4;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
  uVar2 = local_18;
  if (param_1[2] == 0) {
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    sVar1 = scoreEngine_getChannelData((int)piVar4,(short)param_1[3]);
    uVar2 = CONCAT22(extraout_var,sVar1);
  }
  local_2c = param_2;
  local_28 = local_24;
  media_findSpriteByRef(iVar3,uVar2,&local_2c);
  if (piVar4 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_clearChannelMemberFlag (FUN_680a8da0)
// Address: 680a8da0
// Size: 271 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_clearChannelMemberFlag(int *param_1)
{
  short sVar1;
  undefined2 extraout_var;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_28;
  int local_24;
  int local_20 [2];
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20[0] = *param_1;
  local_28 = param_1[1];
  iVar3 = 0;
  local_20[1] = 0;
  if (local_20[0] == 0) {
    lingo_resolveContext(local_20,(int *)0x0,(int *)0x0,&local_28,(int *)0x0,(int *)0x0,(int *)0x0);
    if (local_20[0] == 0) {
      piVar4 = (int *)0x0;
      goto LAB_680a8dea;
    }
  }
  piVar4 = *(int **)(local_20[0] + 0x20);
LAB_680a8dea:
  local_24 = 0;
  if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
    local_24 = *(int *)(piVar4[1] + 8);
    iVar3 = local_20[0];
    if (local_20[0] == 0) {
      iVar3 = *piVar4;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
  if (param_1[2] == 0) {
    if (piVar4 == (int *)0x0) {
      local_20[1] = 0x80040014;
    }
    else {
      sVar1 = scoreEngine_getChannelData((int)piVar4,(short)param_1[3]);
      local_18 = CONCAT22(extraout_var,sVar1);
    }
  }
  piVar2 = (int *)rendering_resolveState(local_24,local_18);
  if ((piVar2 == (int *)0x0) || (piVar2[2] != 0xf)) {
    local_20[1] = 0x800407d0;
  }
  else {
    piVar2[0x1d] = piVar2[0x1d] & 0xfffffffe;
    if (iVar3 != 0) {
      rendering_setMemberData(iVar3,piVar2,0x10);
    }
  }
  if (piVar4 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_dispatchChannelPropertyOp (FUN_680a8eb0)
// Address: 680a8eb0
// Size: 270 bytes
// Params: int * param_1, undefined4 param_2, uint param_3, uint * param_4, int * param_5, undefined1 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchChannelPropertyOp(int *param_1,undefined4 param_2,uint param_3,uint *param_4,int *param_5,
                 undefined1 *param_6)
{
  int iVar1;
  undefined1 uVar2;
  short sVar3;
  undefined2 extraout_var;
  undefined4 uVar4;
  int iVar5;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_24 = param_1[1];
  local_20 = *param_1;
  iVar5 = 0;
  local_18 = param_6;
  local_1c = 0;
  if ((((local_20 != 0) ||
       (lingo_resolveContext(&local_20,(int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0),
       local_20 != 0)) && (iVar1 = local_20, iVar5 = *(int *)(local_20 + 0x20), iVar5 != 0)) &&
     (*(int *)(iVar5 + 4) != 0)) {
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    param_6 = local_18;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  local_18 = (undefined1 *)CONCAT22((short)param_1[4],(short)param_1[3]);
  uVar4 = local_18;
  if (param_1[2] == 0) {
    if (iVar5 == 0) {
      local_1c = -0x7ffbffec;
      *param_6 = 0;
      goto LAB_680a8f97;
    }
    sVar3 = scoreEngine_getChannelData(iVar5,(short)param_1[3]);
    uVar4 = CONCAT22(extraout_var,sVar3);
  }
  if (local_1c == 0) {
    uVar2 = events_dispatchPropertyOp(*(int *)(iVar5 + 8),uVar4,param_2,param_3,param_4,param_5,&local_1c);
    *param_6 = uVar2;
  }
  else {
    *param_6 = 0;
  }
LAB_680a8f97:
  if (iVar5 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_blendChannelMedia (FUN_680a8fc0)
// Address: 680a8fc0
// Size: 348 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_blendChannelMedia(int *param_1)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_24 = *param_1;
  local_28 = param_1[1];
  iVar5 = 0;
  local_18 = 0;
  if ((local_24 == 0) &&
     (lingo_resolveContext(&local_24,(int *)0x0,(int *)0x0,&local_28,(int *)0x0,(int *)0x0,(int *)0x0),
     local_24 == 0)) {
    piVar6 = (int *)0x0;
  }
  else {
    piVar6 = *(int **)(local_24 + 0x20);
  }
  local_20 = 0;
  if ((piVar6 != (int *)0x0) && (piVar6[1] != 0)) {
    iVar5 = *(int *)(piVar6[1] + 8);
    local_20 = local_24;
    if (local_24 == 0) {
      local_20 = *piVar6;
    }
    Ordinal_2330();
    local_14 = local_20;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  local_1c = CONCAT22((short)param_1[4],(short)param_1[3]);
  uVar2 = local_1c;
  if (param_1[2] == 0) {
    if (piVar6 == (int *)0x0) {
      return 0;
    }
    sVar1 = scoreEngine_getChannelData((int)piVar6,(short)param_1[3]);
    uVar2 = CONCAT22(extraout_var,sVar1);
  }
  if (local_18 != 0) goto LAB_680a90c3;
  piVar3 = (int *)rendering_resolveState(iVar5,uVar2);
  if (piVar3 != (int *)0x0) {
    uVar4 = rendering_getStateCount((int)piVar3);
    iVar5 = rendering_blendMedia(piVar6,piVar3,&local_18);
    if (iVar5 == 0) {
      if (local_18 != 0) goto LAB_680a90c3;
    }
    else {
      if ((piVar3[2] == 0xf) && (uVar4 != 0)) {
        piVar3[0xb] = piVar3[0xb] & 0xfffffdff;
        rendering_moveMemberSlot((int)piVar3,piVar3[4]);
      }
      iVar5 = rendering_getMemberData(local_20,piVar3);
      if (iVar5 != 0) {
        rendering_isStateValid((int)piVar3);
        goto LAB_680a90c3;
      }
    }
  }
  local_18 = -0x7ffbffec;
LAB_680a90c3:
  if (piVar6 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getChannelMediaFormat (FUN_680a9120)
// Address: 680a9120
// Size: 256 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelMediaFormat(int *param_1)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int *piVar3;
  byte *pbVar4;
  undefined4 *puVar5;
  int local_24;
  byte *local_20;
  int local_1c;
  undefined4 local_18;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = (byte *)*param_1;
  local_24 = param_1[1];
  if ((local_20 == (byte *)0x0) &&
     (lingo_resolveContext((int *)&local_20,(int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0
                  ), local_20 == (byte *)0x0)) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    puVar5 = *(undefined4 **)(local_20 + 0x20);
  }
  pbVar4 = (byte *)0x0;
  local_1c = 0;
  if ((puVar5 != (undefined4 *)0x0) && (puVar5[1] != 0)) {
    local_1c = *(int *)(puVar5[1] + 8);
    pbVar4 = local_20;
    if (local_20 == (byte *)0x0) {
      pbVar4 = (byte *)*puVar5;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar4;
  }
  local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
  uVar2 = local_18;
  if (param_1[2] == 0) {
    if (puVar5 == (undefined4 *)0x0) {
      return 0;
    }
    sVar1 = scoreEngine_getChannelData((int)puVar5,(short)param_1[3]);
    uVar2 = CONCAT22(extraout_var,sVar1);
  }
  piVar3 = (int *)rendering_resolveState(local_1c,uVar2);
  if (piVar3 != (int *)0x0) {
    rendering_getMediaFormat(pbVar4,piVar3);
  }
  if (puVar5 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_writeChannelData (FUN_680a9220)
// Address: 680a9220
// Size: 513 bytes
// Params: int * param_1, int * param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeChannelData(int *param_1,int *param_2,int param_3,int *param_4)
{
  short sVar1;
  undefined2 extraout_var;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_840;
  int *local_83c;
  int *local_838;
  int local_834;
  undefined4 local_830;
  int local_82c;
  int *local_828;
  undefined4 local_824;
  undefined1 local_820 [1048];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_840 = param_1[1];
  local_838 = param_2;
  local_834 = *param_1;
  local_83c = param_4;
  if ((local_834 == 0) &&
     (lingo_resolveContext(&local_834,(int *)0x0,(int *)0x0,&local_840,(int *)0x0,(int *)0x0,(int *)0x0),
     local_834 == 0)) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(local_834 + 0x20);
  }
  iVar4 = 0;
  if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
    local_830 = *(int *)(piVar5[1] + 8);
    iVar3 = local_834;
    if (local_834 == 0) {
      iVar3 = *piVar5;
    }
    Ordinal_2330();
    local_824 = 0;
    local_828 = DAT_68196374;
    iVar4 = local_830;
    DAT_68196374 = &local_82c;
    local_82c = iVar3;
  }
  local_830 = CONCAT22((short)param_1[4],(short)param_1[3]);
  if ((param_1[2] == 0) && (piVar5 != (int *)0x0)) {
    sVar1 = scoreEngine_getChannelData((int)piVar5,(short)param_1[3]);
    local_830 = CONCAT22(extraout_var,sVar1);
  }
  piVar2 = (int *)rendering_resolveState(iVar4,local_830);
  if (piVar2 != (int *)0x0) {
    iVar3 = rendering_getChannelState(piVar2);
    iVar4 = piVar2[0x17];
    piVar2 = (int *)lingo_getGlobalRef(*piVar2);
    local_830 = media_getModifiedTime(piVar2,iVar4);
    if ((((local_838 != (int *)0x0) &&
         (iVar4 = (**(code **)(*local_838 + 0x4c))(local_838,local_408,0x400), iVar4 == 0)) &&
        (iVar4 = Ordinal_1309(local_820,0x400,local_408,2), iVar4 != 0)) &&
       (((piVar5 == (int *)0x0 ||
         (iVar4 = scoreEngine_writeChannelData((int)piVar5,iVar3,local_820,local_830,param_3,0,1), iVar4 != 0)) &&
        (iVar4 = Ordinal_1310(local_820,local_408,0x3ff), iVar4 != 0)))) {
      (**(code **)(*local_83c + 0xc))(local_83c,local_408,0xffffffff,0,0);
    }
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_828;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_importChannelAsset (FUN_680a9430)
// Address: 680a9430
// Size: 611 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_importChannelAsset(int *param_1,int *param_2)
{
  short sVar1;
  undefined2 extraout_var;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_85c;
  int local_858;
  int local_854;
  int *local_850;
  int *local_84c;
  undefined4 local_848;
  undefined1 *local_844;
  int local_840;
  undefined4 local_83c;
  undefined4 local_838;
  undefined4 local_834;
  undefined4 local_830;
  int local_82c;
  int *local_828;
  undefined4 local_824;
  undefined1 local_820 [1048];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_850 = param_2;
  local_844 = (undefined1 *)0x0;
  local_840 = 0;
  local_83c = 0;
  local_838 = 0;
  local_834 = 0;
  local_830 = 0;
  piVar5 = local_84c;
  if (param_1 != (int *)0x0) {
    local_854 = *param_1;
    local_85c = param_1[1];
    if ((local_854 == 0) &&
       (lingo_resolveContext(&local_854,(int *)0x0,(int *)0x0,&local_85c,(int *)0x0,(int *)0x0,(int *)0x0),
       local_854 == 0)) {
      local_84c = (int *)0x0;
    }
    else {
      local_84c = *(int **)(local_854 + 0x20);
    }
    piVar5 = local_84c;
    local_858 = 0;
    iVar2 = 0;
    if ((local_84c != (int *)0x0) && (local_84c[1] != 0)) {
      local_848 = *(int *)(local_84c[1] + 8);
      iVar3 = local_854;
      if (local_854 == 0) {
        iVar3 = *local_84c;
      }
      local_858 = local_84c[2];
      Ordinal_2330();
      local_824 = 0;
      local_828 = DAT_68196374;
      iVar2 = local_848;
      DAT_68196374 = &local_82c;
      local_82c = iVar3;
    }
    local_848 = CONCAT22((short)param_1[4],(short)param_1[3]);
    if (param_1[2] == 0) {
      if (piVar5 == (int *)0x0) {
        return 0;
      }
      sVar1 = scoreEngine_getChannelData((int)piVar5,(short)param_1[3]);
      local_848 = CONCAT22(extraout_var,sVar1);
    }
    iVar2 = rendering_resolveState(iVar2,local_848);
    if ((((iVar2 != 0) && (local_850 != (int *)0x0)) &&
        (iVar3 = (**(code **)(*local_850 + 0x4c))(local_850,local_408,0x400), iVar3 == 0)) &&
       (iVar4 = Ordinal_1309(local_820,0x400,local_408,2), iVar4 != 0)) {
      iVar4 = rendering_toggleStateFlag(iVar2,0);
      rendering_setStateFlag(iVar2,0);
      local_844 = local_408;
      local_840 = iVar3;
      local_850 = (int *)Ordinal_293(*(int *)(local_858 + 0x20),*(int *)(local_858 + 0x28),local_848
                                     ,8,(uint *)&local_844);
      if (iVar4 == 0) {
        rendering_clearStateFlag(iVar2,0);
      }
      piVar5 = local_84c;
      if (local_850 != (int *)0x0) {
        *(uint *)(iVar2 + 0x2c) = *(uint *)(iVar2 + 0x2c) & 0xffffdfff;
      }
    }
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_828;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getChannelUpdateData (FUN_680a96a0)
// Address: 680a96a0
// Size: 449 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelUpdateData(int *param_1,int *param_2)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_83c;
  int local_838;
  int *local_834;
  undefined4 local_830;
  int local_82c;
  int *local_828;
  undefined4 local_824;
  undefined4 local_820 [262];
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_834 = param_2;
  local_408 = 0;
  memset(local_407,0,0x3ff);
  piVar6 = local_834;
  if (param_1 != (int *)0x0) {
    local_838 = *param_1;
    local_83c = param_1[1];
    if ((local_838 == 0) &&
       (lingo_resolveContext(&local_838,(int *)0x0,(int *)0x0,&local_83c,(int *)0x0,(int *)0x0,(int *)0x0),
       local_838 == 0)) {
      piVar6 = (int *)0x0;
    }
    else {
      piVar6 = *(int **)(local_838 + 0x20);
    }
    iVar4 = 0;
    if ((piVar6 != (int *)0x0) && (piVar6[1] != 0)) {
      local_830 = *(int *)(piVar6[1] + 8);
      iVar5 = local_838;
      if (local_838 == 0) {
        iVar5 = *piVar6;
      }
      Ordinal_2330();
      local_824 = 0;
      local_828 = DAT_68196374;
      iVar4 = local_830;
      DAT_68196374 = &local_82c;
      local_82c = iVar5;
    }
    local_830 = CONCAT22((short)param_1[4],(short)param_1[3]);
    uVar2 = local_830;
    if (param_1[2] == 0) {
      if (piVar6 == (int *)0x0) {
        return 0;
      }
      sVar1 = scoreEngine_getChannelData((int)piVar6,(short)param_1[3]);
      uVar2 = CONCAT22(extraout_var,sVar1);
    }
    piVar3 = (int *)rendering_resolveState(iVar4,uVar2);
    if ((piVar3 != (int *)0x0) &&
       (((iVar4 = rendering_dispatchUpdate((int)piVar6,piVar3,local_820,0), iVar4 == 0 ||
         (iVar4 = Ordinal_1310(local_820,&local_408,0x3ff), iVar4 != 0)) &&
        (local_834 != (int *)0x0)))) {
      (**(code **)(*local_834 + 0xc))(local_834,&local_408,0xffffffff,0,0);
    }
  }
  if (piVar6 != (int *)0x0) {
    DAT_68196374 = local_828;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_updateChannelMedia (FUN_680a9870)
// Address: 680a9870
// Size: 534 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_updateChannelMedia(int *param_1,int *param_2)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_430;
  int local_42c;
  int *local_428;
  int *local_424;
  int *local_420;
  int *local_41c;
  undefined4 local_418;
  int local_414;
  int *local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar4 = 0;
  local_428 = param_2;
  local_420 = (int *)0x0;
  local_424 = (int *)0x0;
  if (param_1 == (int *)0x0) goto LAB_680a9a58;
  local_42c = *param_1;
  local_430 = param_1[1];
  if ((local_42c == 0) &&
     (lingo_resolveContext(&local_42c,(int *)0x0,(int *)0x0,&local_430,(int *)0x0,(int *)0x0,(int *)0x0),
     local_42c == 0)) {
    local_41c = (int *)0x0;
  }
  else {
    local_41c = *(int **)(local_42c + 0x20);
  }
  if ((local_41c != (int *)0x0) && (local_41c[1] != 0)) {
    iVar4 = *(int *)(local_41c[1] + 8);
    iVar5 = local_42c;
    if (local_42c == 0) {
      iVar5 = *local_41c;
    }
    Ordinal_2330();
    local_40c = 0;
    local_410 = DAT_68196374;
    DAT_68196374 = &local_414;
    local_414 = iVar5;
  }
  local_418 = CONCAT22((short)param_1[4],(short)param_1[3]);
  uVar2 = local_418;
  if (param_1[2] == 0) {
    if (local_41c != (int *)0x0) {
      sVar1 = scoreEngine_getChannelData((int)local_41c,(short)param_1[3]);
      uVar2 = CONCAT22(extraout_var,sVar1);
      goto LAB_680a9983;
    }
  }
  else {
LAB_680a9983:
    piVar3 = (int *)rendering_resolveState(iVar4,uVar2);
    if (piVar3 != (int *)0x0) {
      iVar4 = rendering_updateMemberMediaEx(local_41c,piVar3,(int *)&local_420,1);
      if (iVar4 == 0) {
        media_getChannelUpdateData(param_1,local_428);
      }
      else if ((((local_420 != (int *)0x0) &&
                (iVar4 = (**(code **)(*local_420 + 0x44))(local_420,&local_424), iVar4 == 0)) &&
               (iVar4 = (**(code **)(*local_424 + 0x14))
                                  (local_424,9,local_408,0x400,"MIOKey_NetStreamCacheFile"),
               iVar4 == 0)) && (local_428 != (int *)0x0)) {
        (**(code **)(*local_428 + 0xc))(local_428,local_408,2,0,0);
      }
    }
  }
  if (local_424 != (int *)0x0) {
    (**(code **)(*local_424 + 8))(local_424);
  }
  if (local_420 != (int *)0x0) {
    (**(code **)(*local_420 + 8))(local_420);
  }
LAB_680a9a58:
  if (local_41c != (int *)0x0) {
    DAT_68196374 = local_410;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_toggleChannelState (FUN_680a9a90)
// Address: 680a9a90
// Size: 543 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_toggleChannelState(int *param_1,int param_2)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int local_468;
  int *local_464;
  int local_460;
  int local_45c;
  undefined4 local_458;
  int *local_454;
  int local_450;
  undefined4 local_44c;
  undefined4 local_448;
  undefined4 local_444;
  undefined4 *local_440;
  undefined4 local_43c;
  undefined4 local_438;
  undefined4 local_434;
  undefined4 local_430;
  int local_42c;
  int *local_428;
  undefined4 local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  piVar5 = local_464;
  if (param_1 != (int *)0x0) {
    local_468 = *param_1;
    local_464 = (int *)param_1[1];
    if ((local_468 == 0) &&
       (lingo_resolveContext(&local_468,(int *)0x0,(int *)0x0,(int *)&local_464,(int *)0x0,(int *)0x0,
                     (int *)0x0), local_468 == 0)) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)(local_468 + 0x20);
    }
    local_45c = 0;
    local_460 = 0;
    if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
      local_460 = *(int *)(piVar5[1] + 8);
      local_45c = local_468;
      if (local_468 == 0) {
        local_45c = *piVar5;
      }
      Ordinal_2330();
      local_42c = local_45c;
      local_424 = 0;
      local_428 = DAT_68196374;
      DAT_68196374 = &local_42c;
    }
    local_458 = CONCAT22((short)param_1[4],(short)param_1[3]);
    uVar2 = local_458;
    if (param_1[2] == 0) {
      if (piVar5 == (int *)0x0) {
        return 0;
      }
      sVar1 = scoreEngine_getChannelData((int)piVar5,(short)param_1[3]);
      uVar2 = CONCAT22(extraout_var,sVar1);
    }
    piVar3 = (int *)rendering_resolveState(local_460,uVar2);
    if (piVar3 != (int *)0x0) {
      if (param_2 == 0) {
        iVar4 = rendering_toggleStateFlag((int)piVar3,0);
        if ((iVar4 != 0) && (iVar4 = rendering_dispatchUpdate((int)piVar5,piVar3,local_420,0), iVar4 != 0)) {
          rendering_clearStateFlag((int)piVar3,0);
          local_448 = 0;
          local_444 = 0;
          local_438 = 0;
          local_434 = 0;
          local_430 = 0;
          local_43c = 0;
          local_440 = local_420;
          local_450 = local_45c;
          local_44c = 1;
          local_454 = piVar3;
          rendering_initState((int *)&local_454);
        }
      }
      else {
        rendering_setStateFlag((int)piVar3,0);
      }
    }
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_428;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_setChannelVisibility (FUN_680a9cb0)
// Address: 680a9cb0
// Size: 291 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setChannelVisibility(int *param_1,int param_2)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_20;
  int *local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar5 = local_1c;
  if (param_1 != (int *)0x0) {
    local_20 = *param_1;
    local_1c = (int *)param_1[1];
    if ((local_20 == 0) &&
       (lingo_resolveContext(&local_20,(int *)0x0,(int *)0x0,(int *)&local_1c,(int *)0x0,(int *)0x0,
                     (int *)0x0), local_20 == 0)) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)(local_20 + 0x20);
    }
    iVar3 = 0;
    if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
      local_18 = *(int *)(piVar5[1] + 8);
      iVar4 = local_20;
      if (local_20 == 0) {
        iVar4 = *piVar5;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      iVar3 = local_18;
      DAT_68196374 = &local_14;
      local_14 = iVar4;
    }
    local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
    uVar2 = local_18;
    if (param_1[2] == 0) {
      if (piVar5 == (int *)0x0) {
        return 0;
      }
      sVar1 = scoreEngine_getChannelData((int)piVar5,(short)param_1[3]);
      uVar2 = CONCAT22(extraout_var,sVar1);
    }
    iVar3 = rendering_resolveState(iVar3,uVar2);
    if (iVar3 != 0) {
      if (param_2 == 0) {
        *(uint *)(iVar3 + 0x60) = *(uint *)(iVar3 + 0x60) & 0xffffbfff;
      }
      else {
        *(uint *)(iVar3 + 0x60) = *(uint *)(iVar3 + 0x60) | 0x4000;
      }
    }
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getChannelVisibility (FUN_680a9de0)
// Address: 680a9de0
// Size: 250 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelVisibility(int *param_1)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_24;
  int *local_20;
  uint local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = 0;
  piVar5 = local_20;
  if (param_1 != (int *)0x0) {
    local_24 = *param_1;
    local_20 = (int *)param_1[1];
    if ((local_24 == 0) &&
       (lingo_resolveContext(&local_24,(int *)0x0,(int *)0x0,(int *)&local_20,(int *)0x0,(int *)0x0,
                     (int *)0x0), local_24 == 0)) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)(local_24 + 0x20);
    }
    iVar3 = 0;
    if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
      local_18 = *(int *)(piVar5[1] + 8);
      iVar4 = local_24;
      if (local_24 == 0) {
        iVar4 = *piVar5;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      iVar3 = local_18;
      DAT_68196374 = &local_14;
      local_14 = iVar4;
    }
    local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
    uVar2 = local_18;
    if (param_1[2] == 0) {
      if (piVar5 == (int *)0x0) goto LAB_680a9ec4;
      sVar1 = scoreEngine_getChannelData((int)piVar5,(short)param_1[3]);
      uVar2 = CONCAT22(extraout_var,sVar1);
    }
    iVar3 = rendering_resolveState(iVar3,uVar2);
    if (iVar3 != 0) {
      local_1c = *(uint *)(iVar3 + 0x60) >> 0xe & 1;
    }
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
LAB_680a9ec4:
  return 0;
}



// ============================================================
// Function: media_getChannelFrameCount (FUN_680a9ee0)
// Address: 680a9ee0
// Size: 247 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelFrameCount(int *param_1)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_24;
  int *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = 0;
  piVar5 = local_20;
  if (param_1 != (int *)0x0) {
    local_24 = *param_1;
    local_20 = (int *)param_1[1];
    if ((local_24 == 0) &&
       (lingo_resolveContext(&local_24,(int *)0x0,(int *)0x0,(int *)&local_20,(int *)0x0,(int *)0x0,
                     (int *)0x0), local_24 == 0)) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)(local_24 + 0x20);
    }
    iVar3 = 0;
    if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
      local_18 = *(int *)(piVar5[1] + 8);
      iVar4 = local_24;
      if (local_24 == 0) {
        iVar4 = *piVar5;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      iVar3 = local_18;
      DAT_68196374 = &local_14;
      local_14 = iVar4;
    }
    local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
    uVar2 = local_18;
    if (param_1[2] == 0) {
      if (piVar5 == (int *)0x0) goto LAB_680a9fc1;
      sVar1 = scoreEngine_getChannelData((int)piVar5,(short)param_1[3]);
      uVar2 = CONCAT22(extraout_var,sVar1);
    }
    iVar3 = rendering_resolveState(iVar3,uVar2);
    if (iVar3 != 0) {
      local_1c = rendering_getFrameCount(iVar3);
    }
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
LAB_680a9fc1:
  return 0;
}



// ============================================================
// Function: media_updateChannelMemberMedia (FUN_680a9fe0)
// Address: 680a9fe0
// Size: 305 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_updateChannelMemberMedia(int *param_1,int *param_2)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int local_24;
  int *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = param_2;
  if (param_1 != (int *)0x0) {
    local_1c = *param_1;
    local_24 = param_1[1];
    if ((local_1c == 0) &&
       (lingo_resolveContext(&local_1c,(int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0),
       local_1c == 0)) {
      param_2 = (int *)0x0;
    }
    else {
      param_2 = *(int **)(local_1c + 0x20);
    }
    iVar5 = 0;
    if ((param_2 != (int *)0x0) && (param_2[1] != 0)) {
      local_18 = *(int *)(param_2[1] + 8);
      iVar4 = local_1c;
      if (local_1c == 0) {
        iVar4 = *param_2;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      iVar5 = local_18;
      DAT_68196374 = &local_14;
      local_14 = iVar4;
    }
    local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
    uVar2 = local_18;
    if (param_1[2] == 0) {
      if (param_2 == (int *)0x0) {
        return 0;
      }
      sVar1 = scoreEngine_getChannelData((int)param_2,(short)param_1[3]);
      uVar2 = CONCAT22(extraout_var,sVar1);
    }
    piVar3 = (int *)rendering_resolveState(iVar5,uVar2);
    if ((local_20 != (int *)0x0) && (piVar3 != (int *)0x0)) {
      rendering_updateMemberMediaEx(param_2,piVar3,local_20,1);
    }
  }
  if (param_2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_resolveChannelState (FUN_680aa120)
// Address: 680aa120
// Size: 270 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resolveChannelState(int *param_1)
{
  short sVar1;
  undefined2 extraout_var;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_20;
  int *local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar5 = local_1c;
  if (param_1 != (int *)0x0) {
    local_20 = *param_1;
    local_1c = (int *)param_1[1];
    if ((local_20 == 0) &&
       (lingo_resolveContext(&local_20,(int *)0x0,(int *)0x0,(int *)&local_1c,(int *)0x0,(int *)0x0,
                     (int *)0x0), local_20 == 0)) {
      piVar5 = (int *)0x0;
    }
    else {
      piVar5 = *(int **)(local_20 + 0x20);
    }
    iVar4 = 0;
    if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
      local_18 = *(int *)(piVar5[1] + 8);
      iVar3 = local_20;
      if (local_20 == 0) {
        iVar3 = *piVar5;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      iVar4 = local_18;
      DAT_68196374 = &local_14;
      local_14 = iVar3;
    }
    local_18 = CONCAT22((short)param_1[4],(short)param_1[3]);
    uVar2 = local_18;
    if (param_1[2] == 0) {
      if (piVar5 == (int *)0x0) {
        return 0;
      }
      sVar1 = scoreEngine_getChannelData((int)piVar5,(short)param_1[3]);
      uVar2 = CONCAT22(extraout_var,sVar1);
    }
    rendering_resolveState(iVar4,uVar2);
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_updateSpriteStage (FUN_680aa230)
// Address: 680aa230
// Size: 204 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_updateSpriteStage(undefined4 *param_1,undefined4 *param_2)
{
  int iVar1;
  int iVar2;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_1[1];
  iVar1 = *(int *)(*(int *)(param_2[0xf] + 0x20) + 4);
  local_14 = *param_1;
  local_10 = param_1[3];
  local_c = param_1[2];
  iVar2 = Ordinal_1062(&local_18);
  if (iVar2 == 0) {
    if (((*(byte *)(param_2 + 0x13) & 0xc) == 0) && (param_2[0x49] == 0)) {
      if (param_2[0x62] != 0) {
        iVar2 = playback_getSpriteInfo(param_2[0xf],param_2);
        if (iVar2 != 0) {
          local_18 = param_2[0x5c];
          local_14 = param_2[0x5d];
          local_10 = param_2[0x5e];
          local_c = param_2[0x5f];
        }
      }
      bitmap_updateMovieStage(iVar1 + 0xb4,&local_18,0);
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_renderChannelSprite (FUN_680aa300)
// Address: 680aa300
// Size: 308 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_renderChannelSprite(int *param_1)
{
  undefined4 *puVar1;
  code *pcVar2;
  bool bVar3;
  int iVar4;
  undefined3 extraout_var;
  int *piVar5;
  int iVar6;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar4 = *param_1;
  local_18 = param_1;
  if (iVar4 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar4 + 0x20);
  }
  local_1c = 0;
  iVar6 = 0;
  if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
    local_1c = *(int *)(piVar5[1] + 8);
    if (iVar4 == 0) {
      iVar4 = *piVar5;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar6 = iVar4;
    DAT_68196374 = &local_14;
    local_14 = iVar4;
  }
  if (local_18[1] <= *(int *)(iVar6 + 0x2c)) {
    iVar4 = local_18[1] * 400;
    puVar1 = (undefined4 *)(iVar4 + -400 + *(int *)(iVar6 + 0x34));
    if (*(int *)(iVar4 + -0x130 + *(int *)(iVar6 + 0x34)) == 10) {
      bVar3 = playback_isStepActive(iVar6);
      if (CONCAT31(extraout_var,bVar3) == 0) {
        *(ushort *)(puVar1 + 0x53) = *(ushort *)(puVar1 + 0x53) | 0x1000;
      }
      else {
        local_20 = puVar1[0x34];
        local_28 = puVar1[0x32];
        local_2c = puVar1[0x33];
        local_24 = puVar1[0x35];
        media_updateSpriteStage(&local_2c,puVar1);
        *(ushort *)(puVar1 + 0x53) = *(ushort *)(puVar1 + 0x53) & 0xefff;
      }
    }
    if ((**(int **)(local_1c + 4) != 0) &&
       (pcVar2 = *(code **)(**(int **)(local_1c + 4) + 0xfc), pcVar2 != (code *)0x0)) {
      (*pcVar2)(*(undefined4 *)(piVar5[1] + 4),local_18[1],puVar1 + 0x32);
    }
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_invalidateChannelSprite (FUN_680aa440)
// Address: 680aa440
// Size: 193 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_invalidateChannelSprite(int *param_1)
{
  ushort *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar3 = *param_1;
  if (iVar3 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar3 + 0x20);
  }
  iVar4 = 0;
  if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
    if (iVar3 == 0) {
      iVar3 = *piVar5;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar4 = iVar3;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  if ((param_1[1] <= *(int *)(iVar4 + 0x2c)) &&
     (iVar3 = param_1[1] * 400, puVar2 = (undefined4 *)(iVar3 + -400 + *(int *)(iVar4 + 0x34)),
     *(int *)(iVar3 + -0x130 + *(int *)(iVar4 + 0x34)) == 10)) {
    puVar1 = (ushort *)(puVar2 + 0x53);
    *puVar1 = *puVar1 | 0x2000;
    iVar3 = playback_getSpriteData(iVar4,puVar2);
    if (iVar3 != 0) {
      playback_renderSpriteAt(iVar4,*(undefined4 *)(iVar3 + 4),1);
    }
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_findSpriteAction (FUN_680aa510)
// Address: 680aa510
// Size: 209 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_findSpriteAction(int *param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = param_3;
  iVar1 = *param_1;
  local_18 = 0;
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x20);
  }
  iVar3 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if (iVar1 == 0) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar3 = iVar1;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if (param_1[1] <= *(int *)(iVar3 + 0x2c)) {
    iVar1 = playback_getSpriteData(iVar3,(undefined4 *)(param_1[1] * 400 + -400 + *(int *)(iVar3 + 0x34)));
    local_24 = param_2;
    local_20 = local_1c;
    if (((iVar1 != 0) && (*(int *)(iVar1 + 8) == 0xf)) && (*(int **)(iVar1 + 0x54) != (int *)0x0)) {
      local_18 = media_dispatchSetScale(iVar3,*(int **)(iVar1 + 0x54),&local_24);
    }
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_dispatchSpriteProperty (FUN_680aa5f0)
// Address: 680aa5f0
// Size: 181 bytes
// Params: int * param_1, uint param_2, uint param_3, uint * param_4, int * param_5, undefined1 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchSpriteProperty(int *param_1,uint param_2,uint param_3,uint *param_4,int *param_5,
                 undefined1 *param_6)
{
  int iVar1;
  undefined1 uVar2;
  int iVar3;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  local_18 = 0;
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar1 + 0x20);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  uVar2 = events_dispatchSpriteHandlers(*(int **)(iVar3 + 8),(byte *)(*(int **)(iVar3 + 8))[9],(short)param_1[1],
                       param_2,param_3,param_4,param_5,&local_18);
  *param_6 = uVar2;
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: media_setChannelLabel (FUN_680aa6b0)
// Address: 680aa6b0
// Size: 201 bytes
// Params: int * param_1, short param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setChannelLabel(int *param_1,short param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_414;
  int *local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(iVar1 + 0x20);
  }
  iVar2 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    if (iVar1 == 0) {
      iVar1 = *piVar3;
    }
    Ordinal_2330();
    local_40c = 0;
    local_410 = DAT_68196374;
    iVar2 = iVar1;
    DAT_68196374 = &local_414;
    local_414 = iVar1;
  }
  Ordinal_1233(local_408,param_4);
  Ordinal_1472((int)param_2,param_3,local_408,iVar2);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_410;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_convertRgbToPalette (FUN_680aa780)
// Address: 680aa780
// Size: 186 bytes
// Params: int * param_1, undefined1 * param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_convertRgbToPalette(int *param_1,undefined1 *param_2,undefined1 *param_3)
{
  int iVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar1 + 0x20);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  uVar3 = Ordinal_1610(*(undefined4 *)(*(int *)(iVar4 + 4) + 0xb8));
  uVar2 = Ordinal_1738(uVar3,CONCAT11(*param_2,*param_2),CONCAT11(param_2[1],param_2[1]),
                       CONCAT11(param_2[2],param_2[2]));
  *param_3 = uVar2;
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: media_convertPaletteToRgb (FUN_680aa840)
// Address: 680aa840
// Size: 180 bytes
// Params: int * param_1, undefined1 param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_convertPaletteToRgb(int *param_1,undefined1 param_2,undefined1 *param_3)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_20 [3];
  undefined1 uStack_1d;
  undefined2 uStack_1c;
  undefined1 uStack_1b;
  undefined2 local_1a;
  undefined1 uStack_19;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar2 + 0x20);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  uVar1 = Ordinal_1610(*(undefined4 *)(*(int *)(iVar3 + 4) + 0xb8));
  iVar2 = Ordinal_1736(uVar1,param_2,local_20,1);
  if (iVar2 != 0) {
    *param_3 = uStack_1d;
    param_3[1] = uStack_1b;
    param_3[2] = uStack_19;
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: media_readScoreEntry (FUN_680aa900)
// Address: 680aa900
// Size: 333 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_readScoreEntry(int param_1,int param_2,int param_3)
{
  undefined1 local_320 [12];
  undefined4 local_314;
  undefined4 local_310;
  undefined1 local_308 [256];
  undefined1 local_208 [256];
  undefined1 local_108 [256];
  uint local_8;
  
  Ordinal_1130(&local_314,0xc);
  local_314 = 1;
  local_310 = 1;
  Ordinal_1763(&local_314,local_320);
  Ordinal_1764(1);
  local_308[0] = 0;
  Ordinal_1517(DAT_681956e0,0x57a,local_308,0x100);
  Ordinal_1517(DAT_681956e0,param_1 + 0x144f,local_108,0x100);
  if (param_2 == 0) {
    if (param_3 == 0) {
      Ordinal_1202(local_208,local_108);
    }
    else {
      Ordinal_1219(local_208,local_108,param_3);
    }
  }
  else if (param_3 == 0) {
    Ordinal_1219(local_208,local_108,param_2);
  }
  else {
    Ordinal_1219(local_208,local_108,param_2,param_3);
  }
  Ordinal_1780(local_208,local_308,2,1,1,1,0);
  Ordinal_1764(0);
  Ordinal_1763(local_320,0);
  return 0;
}



// ============================================================
// Function: media_copyToGlobalAlloc (FUN_680aaa50)
// Address: 680aaa50
// Size: 104 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_copyToGlobalAlloc(undefined4 param_1,undefined4 *param_2)

{
  SIZE_T dwBytes;
  undefined4 uVar1;
  HGLOBAL hMem;
  LPVOID pvVar2;
  
  dwBytes = Ordinal_1116(param_1);
  uVar1 = Ordinal_1114(param_1);
  hMem = GlobalAlloc(0x42,dwBytes);
  if (hMem != (HGLOBAL)0x0) {
    pvVar2 = GlobalLock(hMem);
    Ordinal_1128(pvVar2,uVar1,dwBytes);
    GlobalUnlock(hMem);
  }
  Ordinal_1115(param_1);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = hMem;
  }
  return (-(uint)(hMem != (HGLOBAL)0x0) & 0x7ffbfffe) + 0x80040002;
}



// ============================================================
// Function: media_getChannelFontMap (FUN_680aaac0)
// Address: 680aaac0
// Size: 182 bytes
// Params: int * param_1, undefined4 param_2, int * param_3, short param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getChannelFontMap(int *param_1,undefined4 param_2,int *param_3,short param_4)
{
  int iVar1;
  undefined1 local_c0 [84];
  undefined1 local_6c [80];
  undefined1 local_1c [8];
  short local_14;
  uint local_8;
  
  Ordinal_1130(local_1c,0x14);
  if (*param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*param_1 + 0x20);
  }
  iVar1 = scoreEngine_getFrameData(iVar1,param_4);
  if (iVar1 == 0) {
    return 0;
  }
  Ordinal_1130(local_c0,0xa4);
  Ordinal_1203(local_6c,param_2,0x40);
  Ordinal_1130(local_1c,0x14);
  playback_getFontMapRef(iVar1 + 0x14,(int)local_c0,(int)local_1c);
  *param_3 = (int)local_14;
  return 0;
}
