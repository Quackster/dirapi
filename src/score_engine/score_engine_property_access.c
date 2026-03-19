// Module: score_engine
// Topic: Property access - sprite/channel property get/set ordinals, score data serialization
// Address range: 0x68088470 - 0x6808d820
// Functions (83):
//   Ordinal_293
//   Ordinal_294
//   Ordinal_206
//   Ordinal_210
//   Ordinal_211
//   Ordinal_271
//   Ordinal_341
//   Ordinal_272
//   Ordinal_273
//   Ordinal_274
//   Ordinal_275
//   Ordinal_277
//   Ordinal_393
//   Ordinal_278
//   Ordinal_279
//   scoreEngine_getPropertyInt
//   scoreEngine_setPropertyInt
//   Ordinal_340
//   Ordinal_291
//   scoreEngine_getPropertyStr
//   Ordinal_297
//   Ordinal_312
//   scoreEngine_setPropertyStr
//   Ordinal_220
//   Ordinal_214
//   scoreEngine_getPropertyRect
//   scoreEngine_setPropertyRect
//   scoreEngine_getPropertyFloat
//   Ordinal_342
//   Ordinal_209
//   Ordinal_369
//   Ordinal_217
//   scoreEngine_setPropertyFloat
//   Ordinal_343
//   scoreEngine_getPropertyBool
//   scoreEngine_setPropertyBool
//   scoreEngine_getPropertyPoint
//   Ordinal_250
//   Ordinal_251
//   scoreEngine_setPropertyPoint
//   scoreEngine_getPropertyColor
//   scoreEngine_setPropertyColor
//   scoreEngine_getPropertyList
//   Ordinal_256
//   Ordinal_257
//   Ordinal_270
//   Ordinal_376
//   scoreEngine_getPropertyData
//   Ordinal_371
//   Ordinal_372
//   Ordinal_374
//   Ordinal_377
//   Ordinal_208
//   scoreEngine_resolvePropertyName
//   scoreEngine_resolvePropertyId
//   scoreEngine_mapPropertyIndex
//   scoreEngine_unmapPropertyIndex
//   Ordinal_382
//   Ordinal_383
//   scoreEngine_readPropertyBlock
//   scoreEngine_readProperty
//   scoreEngine_writePropertyBlock
//   scoreEngine_getPropertyAccess
//   scoreEngine_accessProperty
//   scoreEngine_setPropertyAccess
//   scoreEngine_getPropertyRange
//   scoreEngine_setPropertyRange
//   scoreEngine_writePropertyData
//   scoreEngine_writeProperty
//   Ordinal_332
//   Ordinal_333
//   scoreEngine_readPropertyData
//   scoreEngine_getPropertyExData
//   scoreEngine_setPropertyExData
//   scoreEngine_setPropertyEx
//   scoreEngine_accessPropertyEx
//   scoreEngine_writePropertyEx
//   scoreEngine_getPropertyCallback
//   scoreEngine_setPropertyCallback
//   scoreEngine_getPropertyHandler
//   scoreEngine_setPropertyHandler
//   Ordinal_212
//   scoreEngine_dispatchPropertyOp

// ============================================================
// Function: Ordinal_293
// Address: 68088470
// Size: 1613 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_293(int param_1,int param_2,undefined4 param_3,undefined4 param_4,uint *param_5)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  byte bVar7;
  int local_884;
  undefined4 local_880;
  int local_87c;
  int *local_878;
  byte local_874;
  undefined3 uStack_873;
  int local_870;
  int local_86c;
  int *local_868;
  undefined4 local_864;
  int *local_860;
  int local_85c;
  undefined4 local_858;
  undefined4 local_854;
  uint *local_850;
  undefined4 local_84c;
  undefined4 local_848;
  undefined4 local_844;
  undefined4 local_840;
  undefined4 local_83c;
  undefined4 local_838 [262];
  undefined4 local_420 [262];
  uint local_8;
  
                    /* 0x88470  293   */
  local_87c = param_1;
  local_878 = *(int **)(param_1 + 0x20);
  iVar5 = 0;
  local_880 = param_3;
  local_874 = 1;
  local_870 = 0;
  if ((local_878 != (int *)0x0) && (local_878[1] != 0)) {
    iVar5 = *(int *)(local_878[1] + 8);
    if (param_2 == 0) {
      local_870 = *local_878;
    }
    else {
      local_870 = param_2;
    }
    Ordinal_2330();
    local_86c = local_870;
    local_864 = 0;
    local_868 = DAT_68196374;
    DAT_68196374 = &local_86c;
  }
  piVar1 = (int *)rendering_resolveState(iVar5,local_880);
  if (piVar1 == (int *)0x0) goto switchD_6808852e_caseD_0;
  switch(param_4) {
  case CPROP_TYPE:
  case CPROP_MEDIA_TYPE:
  case CPROP_EMPTY:
  case CPROP_SKIP_TYPE:
  case CPROP_NO_OP_A:
  case CPROP_NO_OP_B:
    goto switchD_6808852e_caseD_0;
  case CPROP_NAME:
    iVar3 = rendering_blendMediaEx(piVar1,*param_5,0);
    goto LAB_68088542;
  case CPROP_MODIFIED:
    rendering_moveMemberSlot((int)piVar1,*param_5);
    break;
  default:
    local_85c = local_870;
    local_858 = 0x1a;
    local_854 = param_4;
    local_850 = param_5;
    local_860 = piVar1;
    rendering_initState((int *)&local_860);
    goto switchD_6808852e_caseD_0;
  case CPROP_HAS_DATA:
    iVar5 = rendering_getFrameCount((int)piVar1);
    if ((iVar5 == 0) || (*param_5 != 0)) goto switchD_6808852e_caseD_0;
    bVar7 = 0;
LAB_68088652:
    rendering_clearStateFlag((int)piVar1,bVar7);
    break;
  case CPROP_FILENAME:
    iVar5 = rendering_getFrameCount((int)piVar1);
    if (iVar5 == 0) goto switchD_6808852e_caseD_0;
    local_85c = 0;
    local_854 = 0;
    local_850 = (uint *)0x0;
    local_84c = 0;
    local_848 = 0;
    local_844 = 0;
    local_840 = 0;
    local_83c = 0;
    local_858 = 0xe;
    local_860 = piVar1;
    rendering_initState((int *)&local_860);
    Ordinal_1309(local_420,0x400,*param_5,2);
    if (param_5[1] == 0) {
      uVar2 = 1;
    }
    else {
      uVar2 = scoreEngine_writeChannelData(*(int *)(local_870 + 0x20),0,local_420,local_854,(uint)(param_5[1] == 1),
                           0,0);
    }
    param_5[2] = uVar2;
    if (uVar2 == 0) goto switchD_6808852e_caseD_0;
    iVar3 = rendering_getStatePair((int)piVar1,local_420);
    iVar5 = local_870;
    if (param_5[1] == 0) {
      piVar1[0xb] = piVar1[0xb] & 0xffffdfff;
    }
    else {
      piVar1[0xb] = piVar1[0xb] | 0x2000;
    }
    playback_renderSpriteAt(local_870,piVar1[1],0x80008000);
    rendering_readMediaBlock((byte *)**(undefined4 **)(iVar5 + 0x20),piVar1,0);
    rendering_setStateIndex((int)piVar1,0);
    local_884 = piVar1[1];
    rendering_getChannelProperty(iVar5,0xc,&local_884);
    local_874 = 3;
    if (iVar3 == 0) goto switchD_6808852e_caseD_0;
    if ((piVar1[2] == CMTYPE_SCRIPT) && (iVar4 = rendering_getFrameCount((int)piVar1), iVar4 != 0)) {
      local_860 = (int *)0x0;
      local_85c = 0;
      local_858 = 0;
      local_854 = 0;
      local_850 = (uint *)0x0;
      local_84c = 0;
      local_848 = 0;
      local_844 = 0;
      local_840 = 0;
      local_83c = 0;
      iVar4 = rendering_dispatchUpdate(*(int *)(iVar5 + 0x20),piVar1,local_838,2);
      if (iVar4 != 0) {
        iVar4 = lingo_setPlaybackProperty(local_87c,local_838,piVar1 + 8);
        if (iVar4 == 0) {
          iVar3 = 0;
        }
        else {
          local_85c = iVar5;
          local_858 = 5;
          local_860 = piVar1;
          rendering_initState((int *)&local_860);
        }
      }
    }
    rendering_compositeMedia(*(int **)(iVar5 + 0x20),piVar1,1);
    rendering_writeMediaBlock(iVar5,piVar1,0);
LAB_68088542:
    bVar6 = iVar3 == 0;
    goto LAB_68088544;
  case CPROP_LOOP:
    if (piVar1[2] != CMTYPE_BITMAP) goto switchD_6808852e_caseD_0;
    iVar5 = rendering_getStateFlags((int)piVar1);
    if (iVar5 != 0) {
      iVar5 = Ordinal_1114(piVar1[0x13]);
      if (*param_5 == 0) {
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfffffffd;
        Ordinal_1115(piVar1[0x13]);
      }
      else {
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 2;
        Ordinal_1115(piVar1[0x13]);
      }
    }
    break;
  case CPROP_SCRIPT:
    local_874 = 3;
    break;
  case CPROP_PURGEABLE:
    local_874 = 8;
    break;
  case CPROP_COMMENT:
    piVar1[0xf] = *param_5;
    goto switchD_6808852e_caseD_0;
  case CPROP_PALETTE:
    iVar5 = rendering_bindMemberRef(*(undefined4 *)(local_870 + 0x20),(int)piVar1,(int *)*param_5);
    bVar6 = iVar5 == 0;
    goto LAB_68088544;
  case CPROP_EXT_INFO2:
    iVar5 = rendering_replaceMediaData(local_870,piVar1,(int *)param_5);
    bVar6 = iVar5 == 0;
    goto LAB_68088544;
  case CPROP_SCRIPT_TEXT:
    iVar5 = rendering_getMediaRef((int)piVar1,*param_5);
    bVar6 = iVar5 == 0;
LAB_68088544:
    if (bVar6) goto switchD_6808852e_caseD_0;
    break;
  case CPROP_USER_DATA:
    piVar1[0x11] = *param_5;
    goto switchD_6808852e_caseD_0;
  case CPROP_PRELOAD:
    if (*param_5 == 0) {
      iVar5 = rendering_toggleStateFlag((int)piVar1,7);
      if (iVar5 == 0) goto switchD_6808852e_caseD_0;
      rendering_checkThumbnailData((int)piVar1);
      rendering_clearStateFlag((int)piVar1,7);
    }
    else {
      rendering_setStateFlag((int)piVar1,7);
    }
    break;
  case CPROP_MEDIA_DIM_H:
    iVar5 = rendering_getStateFlags((int)piVar1);
    if (iVar5 != 0) {
      cast_formatNumber(piVar1 + 0x13,0x13,*param_5);
    }
    break;
  case CPROP_MEDIA_DIM_V:
    iVar5 = rendering_getStateFlags((int)piVar1);
    if (iVar5 != 0) {
      cast_formatNumber(piVar1 + 0x13,0x14,*param_5);
    }
    break;
  case CPROP_PURGEABLE_STATE:
    bVar7 = 9;
    if (*param_5 != 1) goto LAB_68088652;
    rendering_setStateFlag((int)piVar1,9);
    break;
  case CPROP_ANTI_ALIAS:
    iVar5 = rendering_getStateFlags((int)piVar1);
    if (iVar5 != 0) {
      cast_formatNumber(piVar1 + 0x13,0xb,*param_5);
    }
    goto switchD_6808852e_caseD_0;
  case CPROP_REG_POINT_X:
    rendering_getDispatchDataRef((int)piVar1,*param_5);
    break;
  case CPROP_REG_POINT_Y:
    rendering_setDispatchRef((int)piVar1,*param_5);
    break;
  case CPROP_BOUNDS_LEFT:
    rendering_getDispatchInfo((int)piVar1,*param_5);
    local_874 = 5;
    break;
  case CPROP_BOUNDS_TOP:
    rendering_getDispatchRef((int)piVar1,*param_5);
    local_874 = 5;
    break;
  case CPROP_HILITE:
    iVar5 = rendering_getStateFlags((int)piVar1);
    if (iVar5 != 0) {
      iVar5 = Ordinal_1114(piVar1[0x13]);
      if (*param_5 == 0) {
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xffffffbf;
        Ordinal_1115(piVar1[0x13]);
      }
      else {
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x40;
        Ordinal_1115(piVar1[0x13]);
      }
    }
    break;
  case CPROP_AUTO_TAB:
    iVar5 = rendering_getStateFlags((int)piVar1);
    if (iVar5 != 0) {
      iVar5 = Ordinal_1114(piVar1[0x13]);
      if (*param_5 == 0) {
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xfffffbff;
        Ordinal_1115(piVar1[0x13]);
      }
      else {
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x400;
        Ordinal_1115(piVar1[0x13]);
      }
    }
    break;
  case CPROP_EDITABLE:
    iVar5 = rendering_getStateFlags((int)piVar1);
    if (iVar5 != 0) {
      iVar5 = Ordinal_1114(piVar1[0x13]);
      if (*param_5 == 0) {
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) & 0xffffffdf;
        Ordinal_1115(piVar1[0x13]);
      }
      else {
        *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x20;
        Ordinal_1115(piVar1[0x13]);
      }
    }
    break;
  case CPROP_FONT_MAP:
    iVar5 = rendering_getStateFlags((int)piVar1);
    if (iVar5 != 0) {
      cast_formatNumber(piVar1 + 0x13,4,*param_5);
    }
    break;
  case CPROP_ALIGNMENT:
    iVar5 = rendering_getStateFlags((int)piVar1);
    if (iVar5 != 0) {
      cast_formatNumber(piVar1 + 0x13,5,*param_5);
    }
    goto switchD_6808852e_caseD_0;
  case CPROP_LINE_SPACING:
    iVar5 = rendering_getStateFlags((int)piVar1);
    if (iVar5 != 0) {
      cast_formatNumber(piVar1 + 0x13,7,*param_5);
    }
    goto switchD_6808852e_caseD_0;
  }
  rendering_setMemberData(local_870,piVar1,local_874);
switchD_6808852e_caseD_0:
  if (local_878 != (int *)0x0) {
    DAT_68196374 = local_868;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_294
// Address: 68088bc0
// Size: 1882 bytes
// Params: int param_1, int param_2, undefined4 param_3, uint param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_294(int param_1,int param_2,undefined4 param_3,uint param_4,uint *param_5)
{
  int *piVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint local_860;
  int local_85c;
  undefined4 local_858;
  int local_854;
  int *local_850;
  undefined4 local_84c;
  int *local_848;
  int local_844;
  undefined4 local_840;
  uint local_83c;
  uint *local_838;
  undefined4 local_834;
  undefined4 local_830;
  undefined4 local_82c;
  undefined4 local_828;
  undefined4 local_824;
  undefined4 local_820 [262];
  byte local_408 [1024];
  uint local_8;
  
                    /* 0x88bc0  294   */
  piVar1 = *(int **)(param_1 + 0x20);
  local_858 = param_3;
  local_860 = 0;
  local_85c = 0;
  iVar8 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    local_85c = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_84c = 0;
    local_850 = DAT_68196374;
    iVar8 = param_2;
    DAT_68196374 = &local_854;
    local_854 = param_2;
  }
  piVar2 = (int *)rendering_resolveState(local_85c,local_858);
  if (piVar2 == (int *)0x0) goto switchD_68088c75_caseD_0;
  switch(param_4) {
  case CPROP_TYPE:
  case CPROP_NO_OP_B:
    goto switchD_68088c75_caseD_0;
  case CPROP_NAME:
    iVar8 = Ordinal_38(piVar2[0x13],1,local_408,0x3ff);
    if (1 < iVar8) {
      if (local_408[0] == 0xff) {
        uVar7 = Ordinal_1201(local_408 + 1);
      }
      else {
        uVar7 = (uint)local_408[0];
      }
      if ((int)(param_5[1] - 1) < (int)uVar7) {
        local_858 = 0;
        iVar8 = Ordinal_1251(local_408 + 1,local_408 + param_5[1],&local_858);
        uVar7 = iVar8 - (int)(local_408 + 1);
      }
      Ordinal_1128(*param_5,local_408 + 1,uVar7);
      *(undefined1 *)(uVar7 + *param_5) = 0;
      param_5[1] = uVar7;
      break;
    }
    goto switchD_68088c75_caseD_0;
  case CPROP_MEDIA_TYPE:
    *param_5 = piVar2[2];
    break;
  case CPROP_EMPTY:
    uVar7 = rendering_getStateCount((int)piVar2);
    *param_5 = (uint)(uVar7 == 0);
    if (((uVar7 == 0) == 1) && (iVar4 = rendering_getFrameCount((int)piVar2), iVar4 == 0)) {
      iVar8 = rendering_queryMemberDataSize(iVar8,piVar2,&local_860);
      *param_5 = (uint)(iVar8 == 0);
    }
    break;
  case CPROP_MODIFIED:
    *param_5 = piVar2[4];
    break;
  default:
    goto switchD_68088c75_caseD_5;
  case CPROP_HAS_DATA:
    uVar7 = rendering_getFrameCount((int)piVar2);
    *param_5 = uVar7;
    break;
  case CPROP_LINKED_FLAG:
    *param_5 = (uint)piVar2[0xb] >> 0xc & 1;
    break;
  case CPROP_FILENAME:
    local_408[0] = 0;
    memset(local_408 + 1,0,0x3fe);
    uVar7 = rendering_dispatchUpdate(*(int *)(iVar8 + 0x20),piVar2,local_820,param_5[2]);
    param_5[3] = uVar7;
    uVar7 = Ordinal_1313(local_820);
    param_5[4] = uVar7;
    if (param_5[3] == 0) {
      *(undefined1 *)*param_5 = 0;
      param_5[1] = 0;
    }
    else {
      Ordinal_1310(local_820,local_408,0x3ff);
      Ordinal_1203(*param_5,local_408,param_5[1]);
      uVar7 = Ordinal_1201(*param_5);
      param_5[1] = uVar7;
    }
    break;
  case CPROP_LOOP:
    if (piVar2[2] == CMTYPE_BITMAP) {
      uVar7 = rendering_getRawStateFlags((int)piVar2);
      *param_5 = uVar7 >> 1 & 1;
      break;
    }
    if (piVar2[2] == CMTYPE_BUTTON) {
      *param_5 = 1;
      break;
    }
    goto LAB_68088fef;
  case CPROP_SCRIPT:
    *param_5 = (uint)((*(byte *)(piVar2 + 0xe) & 0xf7) != 0);
    break;
  case CPROP_PURGEABLE:
    *param_5 = (int)(char)piVar2[0xe] & 8;
    break;
  case CPROP_VERSION:
    puVar5 = (undefined4 *)rendering_getChannelSprite(local_85c,(short)local_858);
    if (puVar5 != (undefined4 *)0x0) {
      if (puVar5[0x12] == 0) {
        uVar6 = stage_getSpriteScriptCount(*(int *)(*(int *)*puVar5 + 0x14));
        puVar5[0x12] = uVar6;
      }
      *param_5 = puVar5[0x12];
      break;
    }
    goto LAB_68088fef;
  case CPROP_COMMENT:
    *param_5 = piVar2[0xf];
    break;
  case CPROP_LONG_COMMENT:
    *param_5 = piVar2[0x10];
    break;
  case CPROP_PALETTE:
    iVar8 = rendering_updateMemberMediaEx(*(int **)(iVar8 + 0x20),piVar2,(int *)param_5,1);
    goto LAB_680892d3;
  case CPROP_EXT_INFO:
    iVar8 = rendering_openMemberMedia(piVar2,param_5,(int *)0x0);
    goto LAB_680892d3;
  case CPROP_EXT_INFO2:
    iVar8 = rendering_copyMemberData(piVar2,(int *)param_5);
    goto LAB_680892d3;
  case CPROP_SCRIPT_TEXT:
    uVar7 = rendering_getMediaState((int)piVar2);
    *param_5 = uVar7;
    break;
  case CPROP_MEDIA_FORMAT:
    local_844 = 0;
    local_83c = 0;
    local_838 = (uint *)0x0;
    local_834 = 0;
    local_830 = 0;
    local_82c = 0;
    local_828 = 0;
    local_824 = 0;
    local_840 = 0xe;
    local_848 = piVar2;
    rendering_initState((int *)&local_848);
    *param_5 = local_83c;
    break;
  case CPROP_CAST_LIB:
    *param_5 = piVar2[3];
    break;
  case CPROP_PROPERTY_STORE:
    puVar3 = (uint *)0x0;
    if (param_5[1] != 0) {
      puVar3 = param_5 + 2;
    }
    iVar8 = rendering_updateMemberState(piVar2,*param_5,(int *)(param_5 + 3),(undefined4 *)0x0,(int *)puVar3);
    goto LAB_680892d3;
  case CPROP_USER_DATA:
    *param_5 = piVar2[0x11];
    break;
  case CPROP_PRELOAD:
    uVar7 = rendering_getRawStateFlags((int)piVar2);
    *param_5 = uVar7 >> 7 & 1;
    break;
  case CPROP_PRELOAD2:
    uVar7 = rendering_getRawStateFlags((int)piVar2);
    *param_5 = uVar7 >> 8 & 1;
    break;
  case CPROP_MEDIA_SIZE_A:
    iVar8 = piVar2[0x13];
    *param_5 = 0;
    if ((iVar8 != 0) && (iVar8 = Ordinal_38(piVar2[0x13],0x11,&local_858,4), iVar8 != 0)) {
      uVar7 = xtra_readBE32Ptr((undefined1 *)&local_858);
      *param_5 = uVar7;
    }
    break;
  case CPROP_MEDIA_SIZE_B:
    iVar8 = piVar2[0x13];
    *param_5 = 0;
    if ((iVar8 != 0) && (iVar8 = Ordinal_38(piVar2[0x13],0x12,&local_858,4), iVar8 != 0)) {
      uVar7 = xtra_readBE32Ptr((undefined1 *)&local_858);
      *param_5 = uVar7;
    }
    break;
  case CPROP_MEDIA_DIM_H:
    if (piVar2[0x13] != 0) {
      uVar7 = cast_lookupDataEntry(piVar2[0x13],0x13,0);
      *param_5 = uVar7;
      break;
    }
    goto LAB_68088fef;
  case CPROP_MEDIA_DIM_V:
    if (piVar2[0x13] != 0) {
      uVar7 = cast_lookupDataEntry(piVar2[0x13],0x14,0);
      *param_5 = uVar7;
      break;
    }
    goto LAB_68088fef;
  case CPROP_COMPRESSION:
    if (piVar2[2] != CMTYPE_SCRIPT) {
      *param_5 = 4;
      break;
    }
    goto switchD_68088c75_caseD_5;
  case CPROP_PURGEABLE_STATE:
    iVar8 = rendering_toggleStateFlag((int)piVar2,9);
    *param_5 = (uint)(iVar8 != 0);
    break;
  case CPROP_ANTI_ALIAS:
    uVar7 = cast_lookupDataEntry(piVar2[0x13],0xb,0);
    *param_5 = uVar7;
    break;
  case CPROP_REG_POINT_X:
    uVar7 = rendering_getDispatchSize((int)piVar2);
    *param_5 = uVar7;
    break;
  case CPROP_REG_POINT_Y:
    uVar7 = 0;
    if (((int *)piVar2[0x13] != (int *)0x0) &&
       (uVar7 = *(uint *)(*(int *)piVar2[0x13] + 4), (int)uVar7 < 0)) {
      uVar7 = 0;
    }
    *param_5 = uVar7;
    break;
  case CPROP_BOUNDS_LEFT:
    uVar7 = cast_lookupDataEntry(piVar2[0x13],0,1);
    *param_5 = uVar7;
    break;
  case CPROP_BOUNDS_TOP:
    uVar7 = rendering_getDispatchData((int)piVar2);
    *param_5 = uVar7;
    break;
  case CPROP_HILITE:
    if (piVar2[0x13] != 0) {
      iVar8 = Ordinal_1114(piVar2[0x13]);
      *param_5 = ((int)*(char *)(iVar8 + 0xc) & 0x40U) >> 6;
      Ordinal_1115(piVar2[0x13]);
    }
    break;
  case CPROP_AUTO_TAB:
    if (piVar2[0x13] != 0) {
      iVar8 = Ordinal_1114(piVar2[0x13]);
      *param_5 = *(uint *)(iVar8 + 0xc) >> 10 & 1;
      Ordinal_1115(piVar2[0x13]);
    }
    break;
  case CPROP_EDITABLE:
    if (piVar2[0x13] != 0) {
      iVar8 = Ordinal_1114(piVar2[0x13]);
      *param_5 = ((int)*(char *)(iVar8 + 0xc) & 0x20U) >> 5;
      Ordinal_1115(piVar2[0x13]);
    }
    break;
  case CPROP_FONT_MAP:
    uVar7 = cast_lookupDataEntry(piVar2[0x13],4,0);
    *param_5 = uVar7;
    break;
  case CPROP_ALIGNMENT:
    if (piVar2[0x13] != 0) {
      uVar7 = cast_lookupDataEntry(piVar2[0x13],5,0);
      *param_5 = uVar7;
      break;
    }
    goto LAB_68088fef;
  case CPROP_LINE_SPACING:
    if (piVar2[0x13] != 0) {
      uVar7 = cast_lookupDataEntry(piVar2[0x13],7,0);
      *param_5 = uVar7;
      break;
    }
LAB_68088fef:
    *param_5 = 0;
    break;
  case CPROP_SKIP_TYPE:
    if ((piVar2[2] == CMTYPE_TRANSITION) || (piVar2[2] == CMTYPE_OLE)) {
      *param_5 = piVar2[0x17];
      break;
    }
    goto switchD_68088c75_caseD_0;
  case CPROP_SCORE_INDEX:
    uVar7 = scoreEngine_initChannelBlock(*(int **)(iVar8 + 0x20),piVar2);
    *param_5 = uVar7;
  }
LAB_680892ec:
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_850;
    Ordinal_2331();
  }
  return 0;
switchD_68088c75_caseD_5:
  local_840 = 0x19;
  local_83c = param_4;
  local_838 = param_5;
  local_848 = piVar2;
  local_844 = iVar8;
  iVar8 = rendering_initState((int *)&local_848);
LAB_680892d3:
  if (iVar8 == 0) {
switchD_68088c75_caseD_0:
    Ordinal_1130(param_5,0x18);
  }
  goto LAB_680892ec;
}



// ============================================================
// Function: Ordinal_206
// Address: 68089450
// Size: 166 bytes
// Params: int param_1, int param_2, undefined4 param_3, byte param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_206(int param_1,int param_2,undefined4 param_3,byte param_4)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89450  206   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar3 = 0;
  iVar4 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar3 = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  piVar2 = (int *)rendering_resolveState(iVar3,param_3);
  if (piVar2 != (int *)0x0) {
    rendering_setMemberData(iVar4,piVar2,param_4);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_210
// Address: 68089500
// Size: 161 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_210(int param_1,int param_2,undefined4 param_3)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89500  210   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar3 = 0;
  iVar4 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar3 = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  piVar2 = (int *)rendering_resolveState(iVar3,param_3);
  if (piVar2 != (int *)0x0) {
    rendering_getMemberData(iVar4,piVar2);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_211
// Address: 680895b0
// Size: 154 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_211(int param_1,int param_2,undefined4 param_3)
{
  int *piVar1;
  bool bVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x895b0  211   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar3 = 0;
  uVar4 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar3 = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar3 = rendering_resolveState(iVar3,param_3);
  if (iVar3 != 0) {
    bVar2 = rendering_isStateValid(iVar3);
    uVar4 = (uint)bVar2;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_3,uVar4);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_271
// Address: 68089650
// Size: 127 bytes
// Params: int param_1, byte * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_271(int param_1,byte *param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89650  271   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  rendering_updateMediaRef(pbVar2,param_3);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_341
// Address: 680896d0
// Size: 200 bytes
// Params: int param_1, byte * param_2, int param_3, int param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, int param_8, int * param_9
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_341(int param_1,byte *param_2,int param_3,int param_4,undefined4 param_5,
                undefined4 param_6,undefined4 param_7,int param_8,int *param_9)
{
  undefined4 *puVar1;
  int iVar2;
  byte *pbVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x896d0  341   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  iVar2 = 0;
  pbVar3 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    iVar2 = *(int *)(puVar1[1] + 8);
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar3 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  rendering_blitMedia(pbVar3,iVar2,param_3,param_4,param_5,param_7,param_6,param_8,param_9,0);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_272
// Address: 680897a0
// Size: 132 bytes
// Params: int param_1, byte * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_272(int param_1,byte *param_2,int param_3)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x897a0  272   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  rendering_addSpriteMedia(pbVar2,param_3,1);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_273
// Address: 68089830
// Size: 130 bytes
// Params: int param_1, byte * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_273(int param_1,byte *param_2,int param_3)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89830  273   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  rendering_removeSpriteMedia(pbVar2,param_3);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_274
// Address: 680898c0
// Size: 156 bytes
// Params: int param_1, byte * param_2, int param_3, undefined4 * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_274(int param_1,byte *param_2,int param_3,undefined4 *param_4,int *param_5)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x898c0  274   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    rendering_loadMediaBlock(pbVar2,param_3,param_4,param_5,1);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_275
// Address: 68089960
// Size: 126 bytes
// Params: int param_1, byte * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_275(int param_1,byte *param_2,int *param_3)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89960  275   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  rendering_loadMediaData(pbVar2,param_3);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_277
// Address: 680899e0
// Size: 152 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_277(int param_1,undefined4 param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x899e0  277   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar1 = *(int *)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  rendering_insertChannelEvent(iVar1,param_2);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_393
// Address: 68089a80
// Size: 216 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_393(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
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
  
                    /* 0x89a80  393   */
  iVar2 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  iVar1 = rendering_resolveState(iVar1,param_2);
  if (iVar1 != 0) {
    local_34 = 5;
    local_3c = iVar1;
    local_38 = iVar2;
    rendering_initState(&local_3c);
  }
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_278
// Address: 68089b60
// Size: 138 bytes
// Params: int param_1, int param_2, undefined4 param_3, short param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_278(int param_1,int param_2,undefined4 param_3,short param_4,int param_5)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89b60  278   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  scoreEngine_insertScoreFrame(*(int *)(iVar2 + 0x20),param_3,param_4,param_5);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_279
// Address: 68089bf0
// Size: 134 bytes
// Params: int param_1, int param_2, undefined4 param_3, short param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_279(int param_1,int param_2,undefined4 param_3,short param_4,int param_5)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89bf0  279   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  scoreEngine_appendScoreFrame(*(undefined4 **)(iVar2 + 0x20),param_3,param_4,param_5);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyInt (FUN_68089c80)
// Address: 68089c80
// Size: 138 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyInt(int param_1,int param_2,int param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  scoreEngine_duplicateFrames(*(int **)(iVar2 + 0x20),param_3,param_4);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyInt (FUN_68089d10)
// Address: 68089d10
// Size: 131 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyInt(int param_1,int param_2,int param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  scoreEngine_deleteFrames(*(int **)(iVar2 + 0x20),param_3,param_4);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_340
// Address: 68089da0
// Size: 115 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_340(undefined4 *param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89da0  340   */
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  puVar1 = (undefined4 *)rendering_resolveState((int)param_1,param_2);
  if (puVar1 != (undefined4 *)0x0) {
    rendering_initStateFromProperty(puVar1);
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_291
// Address: 68089e20
// Size: 115 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_291(undefined4 *param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89e20  291   */
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  iVar1 = rendering_resolveState((int)param_1,param_2);
  if (iVar1 != 0) {
    rendering_updateStateFromProperty(iVar1);
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyStr (FUN_68089ea0)
// Address: 68089ea0
// Size: 135 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyStr(int param_1,int param_2,int param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  scoreEngine_pasteFrames(*(int **)(iVar2 + 0x20),param_3,param_4);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_297
// Address: 68089f30
// Size: 184 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_297(int param_1,undefined4 param_2,undefined4 param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89f30  297   */
  iVar4 = 0;
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
  }
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar3 = *(int *)(piVar1[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  iVar3 = rendering_resolveState(iVar3,param_3);
  if (iVar3 != 0) {
    iVar4 = cast_lookupDataEntry(*(int *)(iVar3 + 0x4c),0,0);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_3,iVar4);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_312
// Address: 68089ff0
// Size: 162 bytes
// Params: int param_1, int param_2, short param_3, int param_4, int param_5, undefined4 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_312(int param_1,int param_2,short param_3,int param_4,int param_5,undefined4 *param_6)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x89ff0  312   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar2 = rendering_getMemberDataBlock(iVar2,param_3,param_4,param_5,param_6);
  if ((iVar2 == 0) && (param_6 != (undefined4 *)0x0)) {
    *param_6 = 1;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyStr (FUN_6808a0a0)
// Address: 6808a0a0
// Size: 242 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, undefined4 param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyStr(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4,int *param_5)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  byte *pbVar4;
  int local_28;
  byte *local_24;
  byte **local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_8;
  
  piVar2 = param_5;
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  local_28 = 0;
  pbVar4 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_1c = 0;
    local_20 = DAT_68196374;
    pbVar4 = param_2;
    DAT_68196374 = &local_24;
    local_24 = param_2;
  }
  Ordinal_51(param_1,(int)&local_18);
  Ordinal_1064(&local_18,-local_18,-local_14);
  iVar3 = Ordinal_1070(&local_18,&param_3);
  if ((iVar3 != 0) && ((*pbVar4 & 8) != 0)) {
    playback_findChannelBySpriteData((int)pbVar4,param_3,param_4,&local_28,piVar2);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_20;
    Ordinal_2331();
  }
  if (local_28 != 0) {
    return 0;
  }
  local_28 = -0x10000;
  return 0;
}



// ============================================================
// Function: Ordinal_220
// Address: 6808a1a0
// Size: 250 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_220(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
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
  
                    /* 0x8a1a0  220   */
  iVar2 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
  }
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar3 = *(int *)(piVar1[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  iVar3 = rendering_resolveState(iVar3,param_2);
  if (iVar3 != 0) {
    local_34 = 0x15;
    local_30 = param_3;
    local_3c = iVar3;
    local_38 = iVar2;
    rendering_initState(&local_3c);
  }
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = local_2c;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_214
// Address: 6808a2a0
// Size: 241 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_214(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                undefined4 param_6)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_3c;
  int *local_38;
  undefined4 local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8a2a0  214   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
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
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar2 = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_34 = 0;
    local_38 = DAT_68196374;
    iVar3 = param_2;
    DAT_68196374 = &local_3c;
    local_3c = param_2;
  }
  iVar2 = rendering_resolveState(iVar2,param_3);
  if (iVar2 == 0) {
    local_18 = 0xffffffff;
  }
  else {
    local_24 = param_4;
    local_28 = 0x14;
    local_20 = param_5;
    local_1c = param_6;
    local_18 = 0x800407d5;
    local_30 = iVar2;
    local_2c = iVar3;
    rendering_initState(&local_30);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_38;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyRect (FUN_6808a3a0)
// Address: 6808a3a0
// Size: 159 bytes
// Params: int param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyRect(int param_1,short param_2)
{
  short sVar1;
  undefined2 extraout_var;
  int iVar2;
  int *piVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  sVar1 = scoreEngine_getChannelCount(*(int *)(iVar2 + 0x20),param_2);
  rendering_convertPaletteEntry(*(uint *)(iVar2 + 0x20),CONCAT22(extraout_var,sVar1));
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyRect (FUN_6808a440)
// Address: 6808a440
// Size: 176 bytes
// Params: int param_1, int param_2, undefined4 param_3, int * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyRect(int param_1,int param_2,undefined4 param_3,int *param_4,int param_5)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar3 = 0;
  iVar4 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar3 = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  piVar2 = (int *)rendering_resolveState(iVar3,param_3);
  if (piVar2 != (int *)0x0) {
    rendering_resolveMemberData(*(undefined4 **)(iVar4 + 0x20),piVar2,param_4,param_5);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyFloat (FUN_6808a4f0)
// Address: 6808a4f0
// Size: 137 bytes
// Params: int param_1, int param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyFloat(int param_1,int param_2,undefined4 param_3,int *param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  rendering_getMediaInfo(*(undefined4 **)(iVar2 + 0x20),param_3,param_4);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_342
// Address: 6808a580
// Size: 200 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_342(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8a580  342   */
  iVar2 = 0;
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
  }
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar3 = *(int *)(piVar1[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  iVar3 = rendering_resolveState(iVar3,param_2);
  if (iVar3 != 0) {
    bitmap_setupSpriteInk(iVar2,iVar3,param_3,param_4);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_209
// Address: 6808a650
// Size: 645 bytes
// Params: int param_1, undefined4 param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_209(int param_1,undefined4 param_2,int param_3,int param_4)
{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  int *local_5c;
  int local_58;
  undefined4 local_54;
  int local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  int *local_3c;
  int local_38;
  undefined4 local_34;
  int *local_30;
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
  
                    /* 0x8a650  209   */
  local_58 = param_3;
  local_3c = (int *)0x0;
  local_38 = 0;
  local_34 = 0;
  local_30 = (int *)0x0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_54 = 0;
  local_60 = 0;
  local_64 = 0;
  local_4c = 0;
  local_50 = 0;
  local_68 = 0;
  if (param_1 == 0) {
    local_5c = (int *)0x0;
  }
  else {
    local_5c = *(int **)(param_1 + 0x20);
  }
  iVar4 = 0;
  local_40 = 0;
  if ((local_5c != (int *)0x0) && (local_5c[1] != 0)) {
    iVar4 = *(int *)(local_5c[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (local_40 = **(int **)(param_1 + 0x20), local_40 == 0)))) {
      local_40 = *local_5c;
    }
    Ordinal_2330();
    local_14 = local_40;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  piVar1 = (int *)rendering_resolveState(iVar4,param_2);
  if ((((piVar1 != (int *)0x0) &&
       (piVar2 = (int *)rendering_resolveState(iVar4,local_58), piVar2 != (int *)0x0)) &&
      (piVar1[2] == piVar2[2])) && (iVar4 = rendering_getMemberData(local_40,piVar1), iVar4 != 0)) {
    local_58 = rendering_getMemberData(local_40,piVar2);
    if (local_58 != 0) {
      local_48 = piVar1[0x13];
      local_44 = piVar2[0x13];
      if (param_4 == 0) {
        Ordinal_38(local_48,0x12,&local_60,4);
        Ordinal_38(local_44,0x12,&local_64,4);
        local_4c = cast_lookupDataEntry(local_48,0x13,0);
        local_50 = cast_lookupDataEntry(local_44,0x13,0);
        Ordinal_37(&local_48,0x12,&local_68,4);
        Ordinal_37(&local_44,0x12,&local_68,4);
        cast_formatNumber(&local_48,0x13,0);
        cast_formatNumber(&local_44,0x13,0);
        uVar3 = cast_compareHandleData(piVar1[0x13],piVar2[0x13]);
        Ordinal_37(&local_48,0x12,&local_60,4);
        Ordinal_37(&local_44,0x12,&local_64,4);
        cast_formatNumber(&local_48,0x13,local_4c);
        cast_formatNumber(&local_44,0x13,local_50);
      }
      else {
        uVar3 = cast_compareHandleData(local_48,local_44);
      }
      if ((uVar3 != 0) &&
         (((piVar1[10] == 0 && (piVar2[10] == 0)) ||
          (iVar4 = Ordinal_1122(piVar1[10],piVar2[10]), iVar4 != 0)))) {
        local_38 = local_40;
        local_34 = 0x1d;
        local_3c = piVar1;
        local_30 = piVar2;
        iVar4 = rendering_initState((int *)&local_3c);
        if (iVar4 != 0) {
          local_54 = local_2c;
        }
      }
    }
    rendering_isStateValid((int)piVar1);
    if (local_58 != 0) {
      rendering_isStateValid((int)piVar2);
    }
  }
  if (local_4c != 0) {
    Ordinal_1113(&local_4c);
  }
  if (local_50 != 0) {
    Ordinal_1113(&local_50);
  }
  if (local_5c != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_369
// Address: 6808a8e0
// Size: 362 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_369(int param_1,undefined4 param_2)
{
  int iVar1;
  int *piVar2;
  byte *pbVar3;
  int local_58;
  int local_54;
  undefined4 local_50;
  int *local_4c;
  int *local_48;
  byte *local_44;
  byte **local_40;
  undefined4 local_3c;
  uint local_38;
  int local_34;
  uint local_20;
  int local_1c;
  uint local_8;
  
                    /* 0x8a8e0  369   */
  local_50 = 0;
  if (param_1 == 0) {
    local_4c = (int *)0x0;
  }
  else {
    local_4c = *(int **)(param_1 + 0x20);
  }
  pbVar3 = (byte *)0x0;
  piVar2 = (int *)0;
  if ((local_4c != (int *)0x0) && (local_4c[1] != 0)) {
    local_48 = *(int **)(local_4c[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar3 = (byte *)**(int **)(param_1 + 0x20), pbVar3 == (byte *)0x0)))) {
      pbVar3 = (byte *)*local_4c;
    }
    Ordinal_2330();
    local_40 = DAT_68196374;
    local_3c = 0;
    piVar2 = local_48;
    DAT_68196374 = &local_44;
    local_44 = pbVar3;
  }
  local_48 = (int *)rendering_resolveState((int)piVar2,param_2);
  if (local_48 != (int *)0x0) {
    local_34 = 0;
    local_38 = 0;
    Ordinal_294(param_1,0,param_2,0x3c,&local_38);
    local_20 = local_38;
    local_1c = local_34;
    local_38 = 0;
    iVar1 = Ordinal_294(param_1,0,param_2,0xf,&local_38);
    if ((iVar1 == 1) && (iVar1 = rendering_processMediaBlock(pbVar3,local_48,local_38,&local_58), iVar1 != 0)) {
      local_20 = local_20 - local_58;
      local_1c = local_1c - local_54;
      iVar1 = Ordinal_293(param_1,0,param_2,0x3c,&local_20);
      if (iVar1 != 0) {
        local_20 = 0;
        iVar1 = Ordinal_293(param_1,0,param_2,0x3d,&local_20);
        if (iVar1 != 0) {
          rendering_setMemberSlot((int)local_48,"");
        }
      }
    }
  }
  if (local_38 != 0) {
    Ordinal_1113(&local_38);
  }
  if (local_4c != (int *)0x0) {
    DAT_68196374 = local_40;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_217
// Address: 6808aa50
// Size: 182 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_217(int param_1,undefined4 param_2)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8aa50  217   */
  local_1c = param_2;
  local_18 = 0;
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar2 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar4 = **(int **)(param_1 + 0x20), iVar4 == 0)
        ))) {
      iVar4 = *piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar4;
  }
  piVar1 = (int *)rendering_resolveState(iVar2,local_1c);
  if (piVar1 != (int *)0x0) {
    local_18 = rendering_blendMedia(piVar3,piVar1,&local_20);
  }
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyFloat (FUN_6808ab10)
// Address: 6808ab10
// Size: 156 bytes
// Params: int param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyFloat(int param_1,short param_2)
{
  short sVar1;
  undefined2 extraout_var;
  byte *pbVar2;
  int *piVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  pbVar2 = (byte *)0x0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  sVar1 = scoreEngine_getChannelCount(*(int *)(pbVar2 + 0x20),param_2);
  playback_findSpriteByState(pbVar2,CONCAT22(extraout_var,sVar1));
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_343
// Address: 6808abb0
// Size: 148 bytes
// Params: int param_1, byte * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_343(int param_1,byte *param_2,int param_3,int param_4)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8abb0  343   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    rendering_swapSpriteMedia(pbVar2,param_3,param_4);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyBool (FUN_6808ac50)
// Address: 6808ac50
// Size: 22 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall scoreEngine_getPropertyBool(int param_1)

{
  int in_EAX;
  
  if ((-1 < in_EAX) && (in_EAX < *(int *)(param_1 + 0x2c))) {
    return in_EAX * 400 + *(int *)(param_1 + 0x34);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyBool (FUN_6808ac70)
// Address: 6808ac70
// Size: 144 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyBool(void)
{
  int iVar1;
  int *piVar2;
  byte *pbVar3;
  int unaff_ESI;
  uint *unaff_EDI;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  iVar1 = media_lockScoreData((int *)unaff_EDI[10],&local_c,&local_8);
  if ((local_c != 0) && (local_8 != 0)) {
    if (unaff_ESI < iVar1) {
      iVar1 = unaff_ESI + 6;
      if ((iVar1 < 0) || (0x3ed < iVar1)) {
        pbVar3 = (byte *)0x0;
      }
      else {
        pbVar3 = (byte *)(iVar1 * 0x30 + local_c);
      }
      if ((iVar1 < 0) || (0x3ed < iVar1)) {
        piVar2 = (int *)0x0;
      }
      else {
        piVar2 = (int *)(iVar1 * 0x30 + local_8);
      }
      rendering_processScoreChannel(unaff_EDI,unaff_ESI,(undefined4 *)(unaff_ESI * 400 + unaff_EDI[0xd]),piVar2,
                   pbVar3,0);
    }
    media_unlockScoreData((int *)unaff_EDI[10],&local_c,&local_8);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyPoint (FUN_6808ad00)
// Address: 6808ad00
// Size: 106 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_getPropertyPoint(int param_1)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  
  do {
    iVar2 = *(int *)(in_EAX + 0x124);
    iVar3 = iVar2 * 400;
    while( true ) {
      if (iVar2 < *(int *)(in_EAX + 0x120)) {
        return 0;
      }
      cVar1 = *(char *)(iVar2 + *(int *)(in_EAX + 0x30));
      if (((cVar1 != '\0') && ((byte)(cVar1 - 4U) < 2)) &&
         ((*(byte *)(*(int *)(in_EAX + 0x34) + 0x4c + iVar3) & 1) != 0)) break;
      iVar2 = iVar2 + -1;
      iVar3 = iVar3 + -400;
    }
    in_EAX = *(int *)(*(int *)(in_EAX + 0x34) + 0x14c + iVar3);
  } while (in_EAX != param_1);
  return *(undefined4 *)(in_EAX + 0x1c);
}



// ============================================================
// Function: Ordinal_250
// Address: 6808ad70
// Size: 161 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_250(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8ad70  250   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  scoreEngine_writeCastXtraBlock(*(int **)(iVar1 + 0x20),param_2);
  rendering_getChannelProperty(iVar1,5,(undefined4 *)0x0);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_251
// Address: 6808ae20
// Size: 151 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_251(int param_1,undefined1 *param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8ae20  251   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  scoreEngine_readCastXtraBlock(*(int *)(iVar1 + 0x20),param_2);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyPoint (FUN_6808aec0)
// Address: 6808aec0
// Size: 163 bytes
// Params: int param_1, int param_2, ushort param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyPoint(int param_1,int param_2,ushort param_3)
{
  int *piVar1;
  int iVar2;
  uint local_1c;
  uint local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  local_1c = (uint)param_3 << 8 | (uint)param_3;
  local_18 = local_1c;
  Ordinal_1918(param_2 + -1,&local_1c);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyColor (FUN_6808af70)
// Address: 6808af70
// Size: 180 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyColor(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = 0;
  local_18 = 0;
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  Ordinal_1919(param_2 + -1,0,&local_1c);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyColor (FUN_6808b030)
// Address: 6808b030
// Size: 249 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyColor(int param_1,int param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  int *piVar2;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = 0;
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
    if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
      if ((piVar2 == (int *)0x0) || (iVar1 = *piVar2, iVar1 == 0)) {
        iVar1 = *piVar2;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  if (param_4 == 0) {
    return 0;
  }
  iVar1 = param_2 + -1;
  if (0 < param_4) {
    Ordinal_1919(iVar1,0,&local_20);
    local_28 = 0;
    local_24 = 0;
    Ordinal_1918(iVar1,&local_28);
  }
  if (param_4 < 0) {
    local_20 = 0;
    local_1c = 0;
    local_18 = 1;
  }
  local_30 = param_4;
  local_2c = param_4;
  Ordinal_1920(iVar1,param_3,&local_30,&local_20,local_18);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyList (FUN_6808b130)
// Address: 6808b130
// Size: 401 bytes
// Params: int param_1, int param_2, int param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyList(int param_1,int param_2,int param_3,undefined4 param_4)
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined1 local_188 [4];
  int *local_184;
  uint local_180;
  undefined4 local_17c;
  int local_178;
  int *local_174;
  undefined4 local_170;
  undefined1 local_16c [356];
  uint local_8;
  
  piVar6 = *(int **)(param_1 + 0x20);
  local_17c = param_4;
  iVar4 = 0;
  local_184 = piVar6;
  if ((piVar6 != (int *)0x0) && (piVar6[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar6;
    }
    Ordinal_2330();
    local_170 = 0;
    local_174 = DAT_68196374;
    iVar4 = param_2;
    DAT_68196374 = &local_178;
    local_178 = param_2;
  }
  Ordinal_1900(&local_180);
  if (local_180 != 0) {
    uVar5 = param_3 - 1;
    uVar1 = local_180;
    if (((int)uVar5 < 0) || ((int)local_180 <= (int)uVar5)) {
      do {
        uVar5 = uVar1 - 1;
        if ((int)uVar5 < 0) goto LAB_6808b1f4;
        iVar2 = scoreEngine_getCastXtraRef(*(int **)(iVar4 + 0x20),uVar5);
        uVar1 = uVar5;
      } while (iVar2 != 0);
      if ((int)uVar5 < 0) {
LAB_6808b1f4:
        uVar5 = local_180 - 1;
      }
    }
    iVar2 = Ordinal_1402(local_188,local_17c,1);
    if (iVar2 != 0) {
      uVar3 = Ordinal_1330(local_17c);
      iVar2 = Ordinal_1923(local_16c,local_188,uVar3,&local_17c);
      if (iVar2 == 0) {
        Ordinal_1042();
        Ordinal_1407(local_188);
        piVar6 = local_184;
      }
      else {
        iVar2 = Ordinal_1910(uVar5,local_16c,local_188,uVar3,1);
        piVar6 = local_184;
        if ((iVar2 != 0) &&
           (iVar2 = Ordinal_1908(uVar5,local_17c,0,iVar4), piVar6 = local_184, iVar2 != 0)) {
          scoreEngine_resumeSound(*(int **)(iVar4 + 0x20),uVar5);
          piVar6 = local_184;
        }
      }
    }
  }
  if (piVar6 != (int *)0x0) {
    DAT_68196374 = local_174;
    Ordinal_2331();
  }
  Ordinal_1042();
  return 0;
}



// ============================================================
// Function: Ordinal_256
// Address: 6808b2d0
// Size: 138 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_256(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8b2d0  256   */
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  scoreEngine_loadCastXtra(piVar1,param_2 + -1);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_257
// Address: 6808b360
// Size: 190 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_257(int param_1,int param_2,int param_3)
{
  int *piVar1;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8b360  257   */
  piVar1 = *(int **)(param_1 + 0x20);
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  Ordinal_1900(&local_18);
  if (local_18 == 1) {
    scoreEngine_getCastXtraRef(piVar1,0);
  }
  else {
    scoreEngine_getCastXtraRef(piVar1,param_3 - 1);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_270
// Address: 6808b420
// Size: 142 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_270(int param_1)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8b420  270   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_376
// Address: 6808b4b0
// Size: 337 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_376(int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  byte *pbVar3;
  int *piVar4;
  short sStack_1a;
  undefined4 *local_18;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8b4b0  376   */
  pbVar3 = (byte *)0x0;
  piVar4 = (int *)0x0;
  if (param_1 == 0) {
    local_18 = (undefined4 *)0x0;
  }
  else {
    local_18 = *(undefined4 **)(param_1 + 0x20);
  }
  piVar2 = (int *)0x0;
  if ((local_18 != (undefined4 *)0x0) && (local_18[1] != 0)) {
    piVar2 = *(int **)(local_18[1] + 8);
    if ((param_1 == 0) ||
       ((*(undefined4 **)(param_1 + 0x20) == (undefined4 *)0x0 ||
        (pbVar3 = (byte *)**(undefined4 **)(param_1 + 0x20), pbVar3 == (byte *)0x0)))) {
      pbVar3 = (byte *)*local_18;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar3;
  }
  if ((*pbVar3 & 8) != 0) {
    sStack_1a = (short)((uint)param_2 >> 0x10);
    if (sStack_1a < 1) {
      scoreEngine_loadCastXtra(*(int **)(pbVar3 + 0x20),param_3 + -1);
    }
    else {
      piVar4 = (int *)rendering_resolveState((int)piVar2,param_2);
      if ((piVar4 != (int *)0x0) && (piVar4[2] == CMTYPE_SOUND)) {
        iVar1 = rendering_getFrameCount((int)piVar4);
        if (iVar1 == 0) {
          scoreEngine_saveSoundData(*(int **)(pbVar3 + 0x20),pbVar3,piVar4,param_3 - 1);
        }
        else {
          scoreEngine_loadSoundData((int)pbVar3,(int)piVar4,param_3 - 1);
        }
      }
    }
  }
  iVar1 = Ordinal_1042();
  if ((iVar1 != 0) && ((iVar1 == 0x6e || (iVar1 == 0x70)))) {
    iVar1 = rendering_getFrameCount((int)piVar4);
    if (iVar1 == 0) {
      rendering_writeStateData((int)piVar4,(undefined *)0x0);
      lingo_formatDebugMsg(piVar2,-0x1af);
    }
    else {
      rendering_writeStateData((int)piVar4,(undefined *)0x0);
      lingo_formatDebugMsg(piVar2,-0x1b0);
    }
  }
  if (local_18 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyData (FUN_6808b610)
// Address: 6808b610
// Size: 615 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, byte * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyData(int param_1,byte *param_2,undefined4 param_3,byte *param_4)
{
  undefined4 *puVar1;
  undefined2 uVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  byte *pbVar6;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  piVar5 = (int *)0x0;
  local_1c = 0;
  local_18 = 0;
  pbVar6 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar6 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar6 & 8) != 0) {
    piVar5 = *(int **)(pbVar6 + 0x28);
    media_lockScoreData(piVar5,&local_18,(undefined4 *)0x0);
    switch(param_3) {
    case 1:
      rendering_getSpriteScoreData(piVar5,1);
      if (*param_4 == 0) {
        pbVar6[0x180] = 1;
        pbVar6[0x181] = 0;
        pbVar6[0x182] = 0;
        pbVar6[0x183] = 0;
      }
      rendering_applyScoreColor(local_18,*param_4,param_4[1],param_4[2],*(int *)(param_4 + 4));
      break;
    case 2:
      if (*(short *)(param_4 + 2) == 0) {
        pbVar6[0x180] = 1;
        pbVar6[0x181] = 0;
        pbVar6[0x182] = 0;
        pbVar6[0x183] = 0;
        rendering_getSpriteScoreBlock(local_18,(int)pbVar6,(short)*(undefined4 *)param_4);
      }
      else {
        rendering_getSpriteScoreData(piVar5,1);
        rendering_getSpriteScoreBlock(local_18,(int)pbVar6,(short)*(undefined4 *)param_4);
      }
      break;
    case 3:
      sVar3 = *(short *)(param_4 + 2);
      if (sVar3 == 0) {
        pbVar6[0x180] = 1;
        pbVar6[0x181] = 0;
        pbVar6[0x182] = 0;
        pbVar6[0x183] = 0;
      }
      rendering_setScoreSlotRef(piVar5,(uint)(sVar3 != 0));
      rendering_writeScoreFieldEx(local_18,(int)pbVar6,(short)*(undefined4 *)param_4,param_4[4],
                   *(int *)(param_4 + 8));
      pbVar6[0x180] = 1;
      pbVar6[0x181] = 0;
      pbVar6[0x182] = 0;
      pbVar6[0x183] = 0;
      break;
    case 4:
      rendering_setScoreTransitionSlot(piVar5,1);
      rendering_setScoreParam(local_18,(int)pbVar6,*(short *)param_4);
      break;
    default:
      goto switchD_6808b68e_caseD_5;
    case 6:
      if (*(short *)(param_4 + 2) == 0) {
        local_20 = -0xffff;
        rendering_setScoreSlotRefEx(piVar5,(int)pbVar6,0,0);
        scoreEngine_playSoundChannel(*(int **)(pbVar6 + 0x20),0,(int)pbVar6,local_20);
        pbVar6[0x70] = 0;
        pbVar6[0x71] = 0;
        pbVar6[0x72] = 0;
        pbVar6[0x73] = 0;
        param_4[0] = 0;
        param_4[1] = 0;
        param_4[2] = 0;
        param_4[3] = 0;
        pbVar6[0x180] = 1;
        pbVar6[0x181] = 0;
        pbVar6[0x182] = 0;
        pbVar6[0x183] = 0;
      }
      else {
        local_20 = 1;
        Ordinal_1900(&local_24);
        iVar4 = local_18;
        if (local_24 == 1) {
          uVar2 = xtra_readBE16((undefined1 *)(local_18 + 0x90));
          local_1c = CONCAT22((*(unsigned short *)((char *)&local_1c + 2)),uVar2);
          sVar3 = xtra_readBE16((undefined1 *)(iVar4 + 0x92));
          local_1c = CONCAT22(sVar3,(undefined2)local_1c);
          if (((sVar3 != 0) && (iVar4 = scoreEngine_setChannelField(*(uint *)(pbVar6 + 0x20),local_1c), iVar4 != 0)
              ) && (*(int *)(iVar4 + 8) == 6)) {
            local_20 = 0;
          }
        }
        rendering_setScoreSlotRefEx(piVar5,(int)pbVar6,1,local_20);
      }
      rendering_writeScoreRect(local_18,(int)pbVar6,(short)*(undefined4 *)param_4);
    }
    local_1c = 1;
    if (*(int *)(pbVar6 + 0x16c) != 0) {
      playback_readScoreFrameProperties(pbVar6);
    }
  }
switchD_6808b68e_caseD_5:
  if (local_18 != 0) {
    media_unlockScoreData(piVar5,&local_18,(undefined4 *)0x0);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_371
// Address: 6808b890
// Size: 359 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, short * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_371(int param_1,byte *param_2,undefined4 param_3,short *param_4)
{
  short sVar1;
  undefined2 extraout_var;
  byte *pbVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  undefined1 *local_18;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8b890  371   */
  puVar5 = *(undefined4 **)(param_1 + 0x20);
  piVar3 = (int *)0x0;
  uVar6 = 0;
  local_18 = (undefined1 *)0x0;
  pbVar2 = (byte *)0x0;
  if ((puVar5 != (undefined4 *)0x0) && (puVar5[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar5;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) == 0) goto switchD_6808b910_caseD_8;
  piVar3 = *(int **)(pbVar2 + 0x28);
  media_lockScoreData(piVar3,&local_18,(undefined4 *)0x0);
  switch(param_3) {
  case 2:
    rendering_getSpriteScoreBlock((int)local_18,(int)pbVar2,(short)*(undefined4 *)param_4);
    iVar4 = 2;
    break;
  case 3:
    rendering_writeScoreFieldDefault((int)local_18,(int)pbVar2,(short)*(undefined4 *)param_4);
    iVar4 = 5;
    break;
  case 4:
    rendering_setScoreParam((int)local_18,(int)pbVar2,*param_4);
    iVar4 = 1;
    break;
  case 5:
    media_setScoreTempo(piVar3,*param_4);
    goto LAB_6808b9b4;
  case 6:
    rendering_writeScoreRect((int)local_18,(int)pbVar2,(short)*(undefined4 *)param_4);
    iVar4 = 4;
    break;
  case 7:
    rendering_writeScoreTransition((int)local_18,(int)pbVar2,(short)*(undefined4 *)param_4);
    iVar4 = 3;
    break;
  default:
    goto switchD_6808b910_caseD_8;
  case 9:
    puVar7 = local_18;
    rendering_writeScoreData(local_18,(int)pbVar2,(short)*(undefined4 *)param_4);
    sVar1 = scoreEngine_getChannelCount(*(int *)(pbVar2 + 0x20),(short)*(undefined4 *)param_4);
    if (*(int *)(puVar7 + 4) == 0) {
      iVar4 = 0;
      break;
    }
    media_readPlaybackBlockEx((int)piVar3,0,CONCAT22(extraout_var,sVar1));
    goto LAB_6808b9b4;
  }
  media_setScorePosition((int)piVar3,iVar4);
LAB_6808b9b4:
  uVar6 = 1;
switchD_6808b910_caseD_8:
  if (local_18 != (undefined1 *)0x0) {
    media_unlockScoreData(piVar3,&local_18,(undefined4 *)0x0);
  }
  if (puVar5 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(puVar5,uVar6);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_372
// Address: 6808ba20
// Size: 376 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_372(int param_1,byte *param_2,undefined4 param_3,undefined4 *param_4)
{
  undefined4 *puVar1;
  int iVar2;
  undefined2 uVar3;
  short sVar4;
  undefined2 extraout_var;
  undefined2 extraout_var_00;
  undefined4 uVar5;
  byte *pbVar6;
  undefined1 *puVar7;
  int *local_20;
  int local_1c;
  undefined4 local_18;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8ba20  372   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  local_20 = (int *)0x0;
  local_1c = 0;
  local_18 = 0;
  pbVar6 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar6 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (((*pbVar6 & 8) == 0) || (local_20 = *(int **)(pbVar6 + 0x28), local_20 == (int *)0x0))
  goto LAB_6808bb4d;
  media_lockScoreData(local_20,&local_1c,(undefined4 *)0x0);
  iVar2 = local_1c;
  switch(param_3) {
  case 2:
    puVar7 = (undefined1 *)(local_1c + 0x60);
    goto LAB_6808babf;
  case 3:
    uVar5 = scoreEngine_commitScoreEdit(*(int **)(pbVar6 + 0x20));
    break;
  case 4:
    uVar5 = media_getScoreCompositeRef(local_20);
    *(short *)param_4 = (short)uVar5;
    goto LAB_6808bb43;
  default:
    goto switchD_6808bab2_caseD_5;
  case 6:
    puVar7 = (undefined1 *)(local_1c + 0xc0);
LAB_6808babf:
    uVar3 = xtra_readBE16(puVar7);
    local_18 = CONCAT22((*(unsigned short *)((char *)&local_18 + 2)),uVar3);
    uVar3 = xtra_readBE16(puVar7 + 2);
    local_18 = CONCAT22(uVar3,(short)local_18);
    sVar4 = scoreEngine_getChannelData(*(int *)(pbVar6 + 0x20),(short)local_18);
    uVar5 = CONCAT22(extraout_var,sVar4);
    break;
  case 7:
    uVar3 = xtra_readBE16((undefined1 *)(local_1c + 0x90));
    local_18 = CONCAT22((*(unsigned short *)((char *)&local_18 + 2)),uVar3);
    uVar3 = xtra_readBE16((undefined1 *)(iVar2 + 0x92));
    local_18 = CONCAT22(uVar3,(short)local_18);
    sVar4 = scoreEngine_getChannelData(*(int *)(pbVar6 + 0x20),(short)local_18);
    uVar5 = CONCAT22(extraout_var_00,sVar4);
    break;
  case 8:
    uVar5 = xtra_readBE32Ptr((undefined1 *)(local_1c + 4));
  }
  *param_4 = uVar5;
LAB_6808bb43:
  local_18 = 1;
switchD_6808bab2_caseD_5:
LAB_6808bb4d:
  if (local_1c != 0) {
    media_unlockScoreData(local_20,&local_1c,(undefined4 *)0x0);
  }
  if (local_18 == 0) {
    Ordinal_1130(param_4,0xc);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_374
// Address: 6808bbc0
// Size: 1734 bytes
// Params: int param_1, int param_2, int param_3, undefined4 param_4, double * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_374(int param_1,int param_2,int param_3,undefined4 param_4,double *param_5)
{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  undefined1 uVar4;
  bool bVar5;
  byte bVar6;
  undefined2 uVar7;
  short sVar8;
  int iVar9;
  undefined3 extraout_var;
  undefined2 extraout_var_02;
  undefined2 extraout_var_03;
  undefined3 extraout_var_00;
  int *piVar10;
  undefined3 extraout_var_01;
  undefined4 uVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  undefined1 *puVar15;
  double *pdVar16;
  float10 fVar17;
  int local_64;
  int local_60;
  undefined4 local_5c;
  int local_58;
  int local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  int *local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  int local_2c;
  int *local_28;
  undefined4 local_24;
  int local_20;
  float local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
                    /* 0x8bbc0  374   */
  piVar1 = *(int **)(param_1 + 0x20);
  iVar12 = 0;
  bVar3 = false;
  local_64 = 0;
  local_58 = 0;
  local_5c = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    if (piVar1[2] != 0) {
      iVar12 = *(int *)(piVar1[2] + 0xc);
    }
    local_5c = iVar12;
    local_58 = param_2;
    Ordinal_2330();
    local_24 = 0;
    local_2c = local_58;
    local_28 = DAT_68196374;
    DAT_68196374 = &local_2c;
  }
  iVar12 = local_58;
  piVar2 = *(int **)(local_58 + 0x28);
  iVar14 = param_3 + -1;
  local_60 = iVar14;
  iVar9 = media_lockScoreData(piVar2,&local_64,(undefined4 *)0x0);
  if ((((iVar9 <= iVar14) || (iVar14 < 0)) || (*(int *)(iVar12 + 0x2c) <= iVar14)) ||
     (puVar13 = (undefined4 *)(iVar14 * 400 + *(int *)(local_58 + 0x34)),
     puVar13 == (undefined4 *)0x0)) goto switchD_6808bca2_caseD_20;
  iVar12 = param_3 + 5;
  if ((iVar12 < 0) || (0x3ed < iVar12)) {
    puVar15 = (undefined1 *)0x0;
  }
  else {
    puVar15 = (undefined1 *)(iVar12 * 0x30 + local_64);
  }
  switch(param_4) {
  case SPROP_SCRIPT_NUM:
    uVar4 = media_getScoreChannelByte(piVar2,local_60);
    *(uint *)param_5 = CONCAT31(extraout_var,uVar4);
    break;
  case SPROP_CAST_NUM:
    uVar7 = xtra_readBE16(puVar15 + 4);
    local_5c = CONCAT22((*(unsigned short *)((char *)&local_5c + 2)),uVar7);
    uVar7 = xtra_readBE16(puVar15 + 6);
    local_5c = CONCAT22(uVar7,(short)local_5c);
    sVar8 = scoreEngine_getChannelData(*(int *)(local_58 + 0x20),(short)local_5c);
    *(uint *)param_5 = CONCAT22(extraout_var_02,sVar8);
    break;
  case SPROP_CAST_REF_RAW:
    uVar7 = xtra_readBE16(puVar15 + 4);
    *(undefined2 *)param_5 = uVar7;
    uVar7 = xtra_readBE16(puVar15 + 6);
    *(undefined2 *)((int)param_5 + 2) = uVar7;
    break;
  case SPROP_TYPE_BYTE:
    *(undefined1 *)param_5 = *puVar15;
    break;
  case SPROP_POSITION:
    uVar11 = xtra_readBE32Ptr(puVar15 + 8);
    *(undefined4 *)param_5 = uVar11;
    break;
  case SPROP_INK:
    *(byte *)param_5 = puVar15[1] & 0x3f;
    break;
  case SPROP_CAST_RESOLVED:
    uVar7 = xtra_readBE16(puVar15 + 4);
    local_5c = CONCAT22((*(unsigned short *)((char *)&local_5c + 2)),uVar7);
    uVar7 = xtra_readBE16(puVar15 + 6);
    local_5c = CONCAT22(uVar7,(short)local_5c);
    sVar8 = scoreEngine_getChannelData(*(int *)(local_58 + 0x20),(short)local_5c);
    *(uint *)param_5 = CONCAT22(extraout_var_03,sVar8);
    break;
  case SPROP_BACK_COLOR:
    *(undefined1 *)param_5 = puVar15[3];
    *(undefined1 *)((int)param_5 + 1) = puVar15[0x19];
    *(undefined1 *)((int)param_5 + 2) = puVar15[0x1b];
    *(byte *)((int)param_5 + 3) = (byte)puVar15[0x14] >> 5 & 1;
    break;
  case SPROP_FORE_COLOR:
    *(undefined1 *)param_5 = puVar15[2];
    *(undefined1 *)((int)param_5 + 1) = puVar15[0x18];
    *(undefined1 *)((int)param_5 + 2) = puVar15[0x1a];
    *(byte *)((int)param_5 + 3) = (byte)puVar15[0x14] >> 4 & 1;
    break;
  case 10:
    *(byte *)param_5 = (puVar15[0x16] & 0xf) - 1;
    break;
  case SPROP_FLAGS:
    *(undefined4 *)param_5 = puVar13[0x32];
    *(undefined4 *)((int)param_5 + 4) = puVar13[0x33];
    *(undefined4 *)(param_5 + 1) = puVar13[0x34];
    *(undefined4 *)((int)param_5 + 0xc) = puVar13[0x35];
    goto LAB_6808c22e;
  case 0xc:
    *(undefined4 *)param_5 = puVar13[0x1e];
    *(undefined4 *)((int)param_5 + 4) = puVar13[0x1f];
    *(undefined4 *)(param_5 + 1) = puVar13[0x20];
    *(undefined4 *)((int)param_5 + 0xc) = puVar13[0x21];
    break;
  case 0xd:
    bitmap_getSpriteRect(puVar13,0,(undefined4 *)param_5);
    break;
  case SPROP_LINE_SIZE:
    if ((*(byte *)(puVar13 + 0x16) & 0x20) == 0) {
      sVar8 = xtra_readBE16(puVar15 + 0xe);
      *(int *)param_5 = (int)sVar8;
    }
    else {
      *(undefined4 *)param_5 = puVar13[0x1c];
    }
    break;
  case 0xf:
    if ((*(byte *)(puVar13 + 0x16) & 0x20) == 0) {
      sVar8 = xtra_readBE16(puVar15 + 0xc);
      *(int *)((int)param_5 + 4) = (int)sVar8;
    }
    else {
      *(undefined4 *)((int)param_5 + 4) = puVar13[0x1d];
    }
    break;
  case 0x10:
    sVar8 = xtra_readBE16(puVar15 + 0x12);
    *(int *)param_5 = (int)sVar8;
    if ((0x7ff < *(uint *)(*(int *)(local_58 + 0x20) + 0x500)) && ((puVar15[1] & 0x80) == 0)) {
      *(undefined4 *)param_5 = puVar13[0x20] - puVar13[0x1e];
    }
    break;
  case 0x11:
    sVar8 = xtra_readBE16(puVar15 + 0x10);
    iVar12 = local_58;
    *(int *)((int)param_5 + 4) = (int)sVar8;
    if ((0x7ff < *(uint *)(*(int *)(local_58 + 0x20) + 0x500)) && ((puVar15[1] & 0x80) == 0)) {
      *(undefined4 *)((int)param_5 + 4) = puVar13[0x21] - puVar13[0x1f];
    }
    iVar9 = playback_getSpriteData(local_58,puVar13);
    if ((iVar9 != 0) && (*(int *)(iVar9 + 8) == 3)) {
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      local_44 = &local_20;
      local_4c = 0x19;
      local_50 = iVar12;
      local_48 = 0x65;
      local_54 = iVar9;
      iVar12 = rendering_initState(&local_54);
      if ((iVar12 != 0) && (local_20 != 0)) {
        *(undefined4 *)((int)param_5 + 4) = puVar13[0x35] - puVar13[0x33];
      }
    }
    break;
  case 0x12:
    *(undefined4 *)param_5 = puVar13[0x11];
    break;
  case 0x13:
    *(uint *)param_5 = (uint)((byte)puVar15[1] >> 7);
    break;
  case 0x14:
    *(uint *)param_5 = (byte)puVar15[1] >> 6 & 1;
    break;
  case 0x15:
    *(uint *)param_5 = ~((uint)puVar13[0x14] >> 1) & 1;
    break;
  case SPROP_BLEND:
    *(undefined1 *)param_5 = puVar15[0x15];
    break;
  case 0x17:
    *(uint *)param_5 = (uint)((byte)puVar15[0x14] >> 7);
    break;
  case 0x18:
    *(uint *)param_5 = (byte)puVar15[0x14] >> 6 & 1;
    break;
  case 0x19:
    *(byte *)param_5 = puVar15[0x14] & 0xf;
    break;
  case 0x1a:
    if (puVar13[0x18] == 6) goto LAB_6808bfc9;
LAB_6808c12f:
    *(undefined4 *)param_5 = 0;
    break;
  case 0x1b:
    if ((puVar13[0x18] != 10) ||
       (bVar5 = bitmap_getXtraProperty((int)puVar13,0,*(int *)param_5,*(uint **)((int)param_5 + 4)),
       CONCAT31(extraout_var_00,bVar5) == 0)) goto switchD_6808bca2_caseD_20;
    break;
  case 0x1c:
    if (puVar13[0x18] != 10) goto LAB_6808c12f;
    *(int *)param_5 = (int)*(short *)(puVar13 + 0x53);
    break;
  case 0x1d:
    *(uint *)param_5 = (uint)((byte)puVar15[0x16] >> 7);
    break;
  case 0x1e:
    if (puVar13[0x18] != 6) goto LAB_6808c12f;
    uVar11 = Ordinal_1988(puVar13[0x53]);
    *(undefined4 *)param_5 = uVar11;
    break;
  case 0x1f:
    if (puVar13[0x18] != 6) goto LAB_6808c12f;
    uVar11 = Ordinal_1962(puVar13[0x53]);
    *(undefined4 *)param_5 = uVar11;
    break;
  default:
    goto switchD_6808bca2_caseD_20;
  case 0x21:
    puVar13 = puVar13 + 0x36;
    pdVar16 = param_5;
    for (iVar12 = 0x10; iVar12 != 0; iVar12 = iVar12 + -1) {
      *(undefined4 *)pdVar16 = *puVar13;
      puVar13 = puVar13 + 1;
      pdVar16 = (double *)((int)pdVar16 + 4);
    }
    playback_applyLifecycleIntersectReverse(local_58,param_5);
    break;
  case 0x22:
    local_60 = xtra_readBE32Ptr(puVar15 + 0x1c);
    *param_5 = (double)local_60 / 100.0;
    break;
  case 0x23:
    local_60 = xtra_readBE32Ptr(puVar15 + 0x20);
    *param_5 = (double)local_60 / 100.0;
    break;
  case 0x24:
    *(uint *)param_5 = (byte)puVar15[0x16] >> 5 & 1;
    break;
  case 0x25:
    *(uint *)param_5 = (byte)puVar15[0x16] >> 6 & 1;
    break;
  case 0x26:
    piVar10 = (int *)playback_getSpriteData(local_58,puVar13);
    if (piVar10 == (int *)0x0) goto switchD_6808bca2_caseD_20;
    uVar11 = scoreEngine_initChannelBlock(*(int **)(local_58 + 0x20),piVar10);
    *(undefined4 *)param_5 = uVar11;
    break;
  case 0x28:
    iVar12 = playback_getSpriteData(local_58,puVar13);
    if (iVar12 == 0) goto switchD_6808bca2_caseD_20;
    bVar6 = playback_renderSpriteLayer((int)puVar13,iVar12);
    *(uint *)param_5 = CONCAT31(extraout_var_01,bVar6);
    break;
  case 0x29:
    if ((puVar13[0x18] != 5) && (puVar13[0x18] != 4)) goto LAB_6808c12f;
LAB_6808bfc9:
    *(undefined4 *)param_5 = puVar13[0x53];
    break;
  case 0x2a:
    if (puVar13[0x60] == 0) {
      uVar11 = cast_resetAndSort(local_5c);
      puVar13[0x60] = uVar11;
      puVar13[0x62] = 0;
    }
    *(undefined4 *)param_5 = puVar13[0x60];
    break;
  case 0x2b:
    if ((puVar13[0x13] & 0x1000) != 0) {
      fVar17 = rendering_renderStageFrame(puVar13[0xf]);
      local_1c = (float)fVar17;
      local_c = puVar13[0x34];
      local_18 = puVar13[0x33];
      local_14 = puVar13[0x32];
      local_10 = puVar13[0x35];
      uVar11 = events_computeSpriteTransform(*(int *)(*(int *)(puVar13[0xf] + 0x20) + 8),(int *)puVar13[0x60],
                            local_1c,local_18,local_14,local_10,local_c,(int)&local_1c);
      puVar13[0x62] = uVar11;
      puVar13[0x5c] = local_14;
      puVar13[0x5d] = local_18;
      puVar13[0x5e] = local_c;
      puVar13[0x5f] = local_10;
    }
    *(undefined4 *)param_5 = puVar13[0x5c];
    *(undefined4 *)((int)param_5 + 4) = puVar13[0x5d];
    *(undefined4 *)(param_5 + 1) = puVar13[0x5e];
    *(undefined4 *)((int)param_5 + 0xc) = puVar13[0x5f];
LAB_6808c22e:
    playback_applyLifecycleTransformReverse(local_58,param_5);
  }
  bVar3 = true;
switchD_6808bca2_caseD_20:
  if (local_64 != 0) {
    media_unlockScoreData(piVar2,&local_64,(undefined4 *)0x0);
  }
  if (!bVar3) {
    Ordinal_1130(param_5,0x40);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_28;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_377
// Address: 6808c340
// Size: 57 bytes
// Params: undefined4 param_1, int param_2, int * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_377(undefined4 param_1,int param_2,int *param_3,int *param_4)
{
                    /* 0x8c340  377   */
  if (param_2 != 0) {
    *param_3 = *(int *)(param_2 + 0x120) + 1;
    *param_4 = *(int *)(param_2 + 0x124) + 1;
    return 0;
  }
  *param_3 = 1;
  *param_4 = 1000;
  return 0;
}



// ============================================================
// Function: Ordinal_208
// Address: 6808c380
// Size: 373 bytes
// Params: int param_1, byte * param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_208(int param_1,byte *param_2,int param_3,undefined4 *param_4,undefined4 *param_5)
{
  undefined4 *puVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  byte *pbVar6;
  int *local_24;
  int local_1c;
  undefined4 local_18;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8c380  208   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  local_18 = 0;
  local_1c = 0;
  local_24 = (int *)0x0;
  pbVar6 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar6 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar4 = param_3 + -1;
  if ((((-1 < iVar4) && (iVar4 < *(int *)(pbVar6 + 0x2c))) && (*(int *)(pbVar6 + 0x120) <= iVar4))
     && ((iVar4 <= *(int *)(pbVar6 + 0x124) && ((*pbVar6 & 8) != 0)))) {
    local_24 = *(int **)(pbVar6 + 0x28);
    iVar3 = media_lockScoreData(local_24,&local_1c,(undefined4 *)0x0);
    if (iVar4 < iVar3) {
      if (local_1c != 0) {
        iVar4 = param_3 + 5;
        if ((iVar4 < 0) || (0x3ed < iVar4)) {
          pcVar5 = (char *)0x0;
        }
        else {
          pcVar5 = (char *)(iVar4 * 0x30 + local_1c);
        }
        if (*pcVar5 == '\0') goto LAB_6808c4b6;
        uVar2 = xtra_readBE16(pcVar5 + 4);
        local_18 = CONCAT22((*(unsigned short *)((char *)&local_18 + 2)),uVar2);
        uVar2 = xtra_readBE16(pcVar5 + 6);
        local_18 = CONCAT22(uVar2,(undefined2)local_18);
        iVar4 = scoreEngine_setChannelField(*(uint *)(pbVar6 + 0x20),local_18);
        if (iVar4 == 0) {
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = 0;
          }
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = 0;
          }
        }
        else {
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = *(undefined4 *)(iVar4 + 4);
          }
          if (param_5 != (undefined4 *)0x0) {
            *param_5 = *(undefined4 *)(iVar4 + 8);
          }
        }
      }
      local_18 = 1;
    }
  }
LAB_6808c4b6:
  if (local_1c != 0) {
    media_unlockScoreData(local_24,&local_1c,(undefined4 *)0x0);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_resolvePropertyName (FUN_6808c500)
// Address: 6808c500
// Size: 256 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_resolvePropertyName(int param_1,int *param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = *param_2;
  iVar5 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (iVar2 == 0) {
      iVar2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar5 = iVar2;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  iVar2 = *param_3 + -1;
  if ((((-1 < iVar2) && (iVar2 < *(int *)(iVar5 + 0x2c))) &&
      (iVar2 = iVar2 * 400 + *(int *)(iVar5 + 0x34), iVar2 != 0)) &&
     ((*(int *)(iVar2 + 0x30) != 0 && (*(int *)(iVar5 + 8) == 0)))) {
    iVar2 = *(int *)(iVar5 + 0x1c);
    iVar3 = *(int *)(iVar2 + 0x120);
    if (iVar3 <= *(int *)(iVar2 + 0x124)) {
      piVar4 = (int *)(*(int *)(iVar2 + 0x34) + 0x60 + iVar3 * 400);
      do {
        if (((*piVar4 == 4) || (*piVar4 == 5)) && (piVar4[0x3b] == iVar5)) {
          *param_2 = iVar2;
          *param_3 = iVar3 + 1;
          break;
        }
        iVar3 = iVar3 + 1;
        piVar4 = piVar4 + 100;
      } while (iVar3 <= *(int *)(iVar2 + 0x124));
    }
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_resolvePropertyId (FUN_6808c600)
// Address: 6808c600
// Size: 162 bytes
// Params: int param_1, byte * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_resolvePropertyId(int param_1,byte *param_2)
{
  undefined4 *puVar1;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_mapPropertyIndex (FUN_6808c6b0)
// Address: 6808c6b0
// Size: 173 bytes
// Params: int param_1, byte * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_mapPropertyIndex(int param_1,byte *param_2,int param_3,int param_4)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar4 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (((((*pbVar4 & 8) != 0) && (iVar3 = param_3 + -1, -1 < iVar3)) &&
      (iVar3 < *(int *)(pbVar4 + 0x2c))) &&
     ((iVar2 = param_4 + -1, -1 < iVar2 && (iVar2 < *(int *)(pbVar4 + 0x2c))))) {
    playback_renderSpriteToBuffer((int)pbVar4,(undefined4 *)(iVar3 * 400 + *(int *)(pbVar4 + 0x34)),
                 (undefined4 *)(iVar2 * 400 + *(int *)(pbVar4 + 0x34)));
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_unmapPropertyIndex (FUN_6808c760)
// Address: 6808c760
// Size: 173 bytes
// Params: int param_1, byte * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_unmapPropertyIndex(int param_1,byte *param_2,int param_3,int param_4)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar4 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (((((*pbVar4 & 8) != 0) && (iVar3 = param_3 + -1, -1 < iVar3)) &&
      (iVar3 < *(int *)(pbVar4 + 0x2c))) &&
     ((iVar2 = param_4 + -1, -1 < iVar2 && (iVar2 < *(int *)(pbVar4 + 0x2c))))) {
    playback_composeSpriteLayer((int)pbVar4,(undefined4 *)(iVar3 * 400 + *(int *)(pbVar4 + 0x34)),
                 (undefined4 *)(iVar2 * 400 + *(int *)(pbVar4 + 0x34)));
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_382
// Address: 6808c810
// Size: 226 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_382(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  byte *local_24;
  byte **local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_8;
  
                    /* 0x8c810  382   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  iVar3 = param_5 + -1;
  pbVar4 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_20 = DAT_68196374;
    local_1c = 0;
    pbVar4 = param_2;
    DAT_68196374 = &local_24;
    local_24 = param_2;
  }
  Ordinal_51(param_1,(int)&local_18);
  Ordinal_1064(&local_18,-local_18,-local_14);
  iVar2 = Ordinal_1070(&local_18,&param_3);
  if ((((iVar2 != 0) && ((*pbVar4 & 8) != 0)) && (-1 < iVar3)) &&
     ((iVar3 < *(int *)(pbVar4 + 0x2c) &&
      (iVar3 = iVar3 * 400 + *(int *)(pbVar4 + 0x34), iVar3 != 0)))) {
    Ordinal_1070(iVar3 + 200,&param_3);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_20;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_383
// Address: 6808c900
// Size: 185 bytes
// Params: int param_1, byte * param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_383(int param_1,byte *param_2,int param_3,int param_4,int param_5)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  byte *pbVar4;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8c900  383   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  iVar2 = param_5 + -1;
  pbVar4 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_10 = DAT_68196374;
    local_c = 0;
    pbVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (((((*pbVar4 & 8) != 0) && (-1 < iVar2)) && (iVar2 < *(int *)(pbVar4 + 0x2c))) &&
     (puVar3 = (undefined4 *)(iVar2 * 400 + *(int *)(pbVar4 + 0x34)), puVar3 != (undefined4 *)0x0))
  {
    playback_hitTestSprite((int)pbVar4,puVar3,param_3,param_4,(int *)0x0,(int *)0x0,0x80ff);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_readPropertyBlock (FUN_6808c9c0)
// Address: 6808c9c0
// Size: 267 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, undefined4 param_4, int * param_5, undefined4 param_6, int * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_readPropertyBlock(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4,int *param_5,
                 undefined4 param_6,int *param_7)
{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  byte *pbVar5;
  int local_28;
  byte *local_24;
  byte **local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  uint local_8;
  
  piVar3 = param_7;
  piVar2 = param_5;
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  local_28 = -1;
  pbVar5 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_1c = 0;
    local_20 = DAT_68196374;
    pbVar5 = param_2;
    DAT_68196374 = &local_24;
    local_24 = param_2;
  }
  if (piVar2 != (int *)0x0) {
    *piVar2 = 0;
  }
  Ordinal_51(param_1,(int)&local_18);
  Ordinal_1064(&local_18,-local_18,-local_14);
  iVar4 = Ordinal_1070(&local_18,&param_3);
  if (iVar4 == 0) {
    local_28 = -1;
  }
  else {
    if ((*pbVar5 & 8) == 0) {
      iVar4 = 0;
    }
    else {
      iVar4 = playback_getChannelCountEx((int)pbVar5,param_3,param_4,piVar2,&local_28,param_6);
      if (iVar4 == 0) {
        local_28 = -1;
      }
    }
    if (piVar3 != (int *)0x0) {
      *piVar3 = iVar4;
    }
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_20;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_readProperty (FUN_6808cad0)
// Address: 6808cad0
// Size: 167 bytes
// Params: int param_1, int param_2, int param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_readProperty(int param_1,int param_2,int param_3,undefined4 param_4)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar3 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar2 = param_3 + -1;
  if ((((-1 < iVar2) && (iVar2 < *(int *)(iVar3 + 0x2c))) &&
      (iVar2 = iVar2 * 400 + *(int *)(iVar3 + 0x34), iVar2 != 0)) && (*(int *)(iVar2 + 0x60) == 10))
  {
    bitmap_setSpriteProperty(iVar3,iVar2,param_4);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_writePropertyBlock (FUN_6808cb80)
// Address: 6808cb80
// Size: 133 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_writePropertyBlock(int param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  playback_resetLifecycle(iVar2,param_3,param_4);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyAccess (FUN_6808cc10)
// Address: 6808cc10
// Size: 136 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyAccess(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((iVar2 != **(int **)(piVar1[1] + 0x20)) && (*(int *)(iVar2 + 0x1c) == 0)) {
    scoreEngine_getPropertyPoint(iVar2);
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: scoreEngine_accessProperty (FUN_6808cca0)
// Address: 6808cca0
// Size: 124 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_accessProperty(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  playback_getLifecycleRef(iVar2);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyAccess (FUN_6808cd20)
// Address: 6808cd20
// Size: 119 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyAccess(int param_1)
{
  uint uVar1;
  int iVar2;
  undefined4 local_10;
  
  if (param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x20);
  }
  if (iVar2 != 0) {
    if (*(int *)(iVar2 + 4) != 0) {
      Ordinal_2330();
      local_10 = DAT_68196374;
    }
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyRange (FUN_6808cda0)
// Address: 6808cda0
// Size: 125 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyRange(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  playback_getLifecycleRef(iVar2);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyRange (FUN_6808ce20)
// Address: 6808ce20
// Size: 158 bytes
// Params: int param_1, byte * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyRange(int param_1,byte *param_2,int param_3,int param_4)
{
  undefined4 *puVar1;
  int iVar2;
  byte *pbVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar3 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar3 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (((((*pbVar3 & 8) != 0) && (iVar2 = param_3 + -1, -1 < iVar2)) &&
      (iVar2 < *(int *)(pbVar3 + 0x2c))) &&
     (iVar2 = iVar2 * 400 + *(int *)(pbVar3 + 0x34), iVar2 != 0)) {
    playback_setSpriteChannelRef(pbVar3,iVar2,param_4);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_writePropertyData (FUN_6808cec0)
// Address: 6808cec0
// Size: 233 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, undefined4 * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_writePropertyData(int param_1,byte *param_2,undefined4 param_3,undefined4 *param_4,uint *param_5)
{
  undefined4 *puVar1;
  short sVar2;
  undefined4 *puVar3;
  int iVar4;
  byte *pbVar5;
  undefined4 uVar6;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  uVar6 = 0;
  pbVar5 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar5 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar5 & 8) != 0) {
    puVar3 = (undefined4 *)scoreEngine_getPropertyBool((int)pbVar5);
    if (puVar3 != (undefined4 *)0x0) {
      sVar2 = playback_getSpriteProperty((int)pbVar5,puVar3);
      if ((sVar2 == 9) || (sVar2 == 10)) {
        uVar6 = 1;
        iVar4 = playback_getSpriteData((int)pbVar5,puVar3);
        if (iVar4 != 0) {
          if (param_4 != (undefined4 *)0x0) {
            *param_4 = *(undefined4 *)(iVar4 + 4);
          }
          *param_5 = *(uint *)(iVar4 + 0x2c) >> 8 & 1;
        }
      }
      else {
        uVar6 = 0;
      }
    }
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_5,param_4,uVar6);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_writeProperty (FUN_6808cfb0)
// Address: 6808cfb0
// Size: 216 bytes
// Params: int param_1, byte * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_writeProperty(int param_1,byte *param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint *extraout_EDX;
  byte *pbVar4;
  undefined4 uVar5;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  uVar5 = 0;
  pbVar4 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar4 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar4 & 8) != 0) {
    iVar2 = scoreEngine_getPropertyBool((int)pbVar4);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 0x30) != 0)) {
      if (((*(uint *)(iVar2 + 0x58) >> 4 & 1) != 0) && (uVar5 = 2, extraout_EDX != (uint *)0x0)) {
        *extraout_EDX = *(uint *)(iVar2 + 0x58) >> 6 & 1;
      }
      if (*(int *)(iVar2 + 0x60) == 10) {
        uVar3 = bitmap_getSpriteEditability(pbVar4,iVar2,extraout_EDX);
        if (uVar3 != 0) {
          uVar5 = 3;
        }
      }
    }
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_4,uVar5);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_332
// Address: 6808d090
// Size: 139 bytes
// Params: int param_1, byte * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_332(int param_1,byte *param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8d090  332   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    bitmap_dispatchRenderUpdate((int)pbVar2,param_3);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_333
// Address: 6808d120
// Size: 139 bytes
// Params: int param_1, byte * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_333(int param_1,byte *param_2,int param_3)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8d120  333   */
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    bitmap_importMemberFromSource(pbVar2,param_3);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_readPropertyData (FUN_6808d1b0)
// Address: 6808d1b0
// Size: 166 bytes
// Params: int param_1, byte * param_2, int param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_readPropertyData(int param_1,byte *param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6)
{
  undefined4 *puVar1;
  byte *pbVar2;
  undefined4 uVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  uVar3 = 0;
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    uVar3 = bitmap_importMediaFile(param_1,param_3,param_4,param_5,param_6);
    Ordinal_1042();
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_4,uVar3);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyExData (FUN_6808d260)
// Address: 6808d260
// Size: 166 bytes
// Params: int param_1, byte * param_2, int param_3, undefined4 param_4, int param_5, int * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyExData(int param_1,byte *param_2,int param_3,undefined4 param_4,int param_5,int *param_6)
{
  undefined4 *puVar1;
  byte *pbVar2;
  undefined4 uVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  uVar3 = 0;
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    uVar3 = bitmap_exportMediaFile(param_1,param_3,param_4,param_5,param_6);
    Ordinal_1042();
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_4,uVar3);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyExData (FUN_6808d310)
// Address: 6808d310
// Size: 141 bytes
// Params: int param_1, byte * param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyExData(int param_1,byte *param_2,int param_3,int param_4,int param_5)
{
  undefined4 *puVar1;
  byte *pbVar2;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  pbVar2 = (byte *)0x0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    if (param_2 == (byte *)0x0) {
      param_2 = (byte *)*puVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    pbVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((*pbVar2 & 8) != 0) {
    bitmap_printThumbnails(pbVar2,param_3,param_4,param_5);
  }
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyEx (FUN_6808d3a0)
// Address: 6808d3a0
// Size: 166 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyEx(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  scoreEngine_writeChannelData(*(int *)(iVar1 + 0x20),0,param_2,param_3,param_4,param_5,0);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_accessPropertyEx (FUN_6808d450)
// Address: 6808d450
// Size: 354 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_accessPropertyEx(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  int local_42c;
  int *local_428;
  undefined4 local_424;
  int local_420 [262];
  uint local_8;
  
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  piVar4 = (int *)0x0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    piVar4 = *(int **)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar3;
    }
    Ordinal_2330();
    local_424 = 0;
    local_428 = DAT_68196374;
    DAT_68196374 = &local_42c;
    local_42c = iVar2;
  }
  if (*(int *)(*piVar4 + 0x20) == 0) {
    iVar2 = Ordinal_1310(param_2,param_3,param_4);
    if (param_5 != (undefined4 *)0x0) {
      uVar1 = Ordinal_1313(param_2);
      *param_5 = uVar1;
    }
  }
  else {
    piVar4 = piVar3 + 10;
    piVar5 = local_420;
    for (iVar2 = 0x106; iVar2 != 0; iVar2 = iVar2 + -1) {
      *piVar5 = *piVar4;
      piVar4 = piVar4 + 1;
      piVar5 = piVar5 + 1;
    }
    Ordinal_1316(local_420);
    iVar2 = Ordinal_1331(param_2,local_420,param_3,param_4,param_5,piVar3[1]);
  }
  if (iVar2 == 0) {
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 2;
    }
    Ordinal_1130(param_3,param_4);
  }
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_428;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_writePropertyEx (FUN_6808d5c0)
// Address: 6808d5c0
// Size: 329 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_writePropertyEx(int param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  undefined4 uVar5;
  int local_844;
  int *local_840;
  undefined4 local_83c;
  undefined1 local_838 [1048];
  int local_420 [262];
  uint local_8;
  
  uVar5 = 1;
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  piVar3 = (int *)0x0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    piVar3 = *(int **)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_83c = 0;
    local_840 = DAT_68196374;
    DAT_68196374 = &local_844;
    local_844 = iVar1;
  }
  if (*(int *)(*piVar3 + 0x20) != 0) {
    uVar5 = 0;
    iVar1 = Ordinal_1309(local_838,0x400,param_2,2);
    if (iVar1 != 0) {
      piVar3 = piVar2 + 10;
      piVar4 = local_420;
      for (iVar1 = 0x106; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar4 = *piVar3;
        piVar3 = piVar3 + 1;
        piVar4 = piVar4 + 1;
      }
      Ordinal_1316(local_420);
      iVar1 = Ordinal_1331(local_838,local_420,param_2,param_3,0,piVar2[1]);
      if (iVar1 != 0) {
        uVar5 = 1;
        goto LAB_6808d6dc;
      }
    }
    Ordinal_1130(param_2,param_3);
  }
LAB_6808d6dc:
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_840;
    Ordinal_2331(param_2,uVar5);
  }
  return 0;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: scoreEngine_getPropertyCallback (FUN_6808d720)
// Address: 6808d720
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyCallback(int param_1)
{
  bitmap_setTraceLevel(param_1);
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyCallback (FUN_6808d730)
// Address: 6808d730
// Size: 9 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyCallback(undefined4 *param_1)
{
  bitmap_getExportPath(param_1);
  return 0;
}



// ============================================================
// Function: scoreEngine_getPropertyHandler (FUN_6808d740)
// Address: 6808d740
// Size: 14 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getPropertyHandler(undefined4 *param_1)
{
  bitmap_cleanupExportState();
  bitmap_initExportPath(param_1);
  return 0;
}



// ============================================================
// Function: scoreEngine_setPropertyHandler (FUN_6808d750)
// Address: 6808d750
// Size: 9 bytes
// Params: int * param_1, char * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPropertyHandler(int *param_1,char *param_2)
{
  bitmap_logString(param_1,param_2);
  return 0;
}



// ============================================================
// Function: Ordinal_212
// Address: 6808d760
// Size: 180 bytes
// Params: int param_1, byte * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_212(int param_1,byte *param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x8d760  212   */
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  uVar2 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar3;
    }
    if (piVar3[2] == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = *(undefined4 *)(piVar3[2] + 0xc);
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  props_renderFormatted(uVar2,sprites_getNetProgress,uVar2,param_2,param_3);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_dispatchPropertyOp (FUN_6808d820)
// Address: 6808d820
// Size: 149 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_dispatchPropertyOp(int param_1,int param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar3 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  iVar2 = param_3 + -1;
  if (((-1 < iVar2) && (iVar2 < *(int *)(iVar3 + 0x2c))) &&
     (iVar3 = iVar2 * 400 + *(int *)(iVar3 + 0x34), iVar3 != 0)) {
    playback_getSpriteDataRef(iVar3);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}




/* Restored functions that were incorrectly removed during thunk cleanup */

// ============================================================

undefined4 thunk_FUN_680e4be0(void)

{
  return DAT_681964a8;
}

