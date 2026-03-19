// Source: decompiled_functions.c
// Module: score_engine
// Address range: 0x6808dc50 - 0x6808dc50
// Functions (1):
//   Ordinal_360

// ============================================================
// Function: Ordinal_360
// Address: 6808dc50
// Size: 3096 bytes
// Params: int * param_1, undefined4 * * * param_2, undefined4 param_3, double * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_360(int *param_1,undefined4 ***param_2,undefined4 param_3,double *param_4)
{
  int *piVar1;
  undefined4 **ppuVar2;
  uint uVar3;
  bool bVar4;
  ushort uVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  undefined4 uVar9;
  int *piVar10;
  undefined4 *puVar11;
  undefined4 ***pppuVar12;
  uint uVar13;
  int *local_7c8;
  int *local_7c4;
  int *local_7c0;
  undefined4 ***local_7bc;
  int *local_7b8;
  undefined4 ***local_7b4;
  undefined4 ****local_7b0;
  undefined4 local_7ac;
  undefined4 local_7a8;
  undefined4 local_7a4;
  undefined4 local_7a0;
  undefined4 local_79c;
  undefined2 local_798;
  undefined1 local_796 [254];
  undefined2 local_698;
  undefined1 local_696 [253];
  undefined1 auStack_599 [1025];
  byte local_198;
  undefined1 local_197 [143];
  undefined2 local_108;
  undefined1 local_106 [254];
  uint local_8;
  
                    /* 0x8dc50  360   */
  piVar1 = (int *)param_1[8];
  uVar9 = 0;
  local_7c0 = param_1;
  local_7bc = param_2;
  local_7c4 = (int *)0x0;
  pppuVar12 = (undefined4 ***)0x0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    uVar9 = *(undefined4 *)(piVar1[1] + 8);
    if (param_2 == (undefined4 ***)0x0) {
      param_2 = (undefined4 ***)*piVar1;
    }
    Ordinal_2330();
    local_7ac = 0;
    local_7b0 = DAT_68196374;
    pppuVar12 = param_2;
    DAT_68196374 = &local_7b4;
    local_7b4 = param_2;
  }
  ppuVar2 = pppuVar12[8];
  switch(param_3) {
  case MPROP_CAST_LIB_NAME:
    uVar9 = rendering_updateChannelState((int)(ppuVar2 + 0x123));
    *(undefined4 *)param_4 = uVar9;
    break;
  case MPROP_DIMENSION_A:
    *(undefined2 *)param_4 = *(undefined2 *)(ppuVar2 + 0x11e);
    break;
  case MPROP_CAST_DATA_199:
    *(undefined4 **)param_4 = ppuVar2[0x199];
    break;
  case MPROP_DIMENSION_B:
    *(undefined2 *)param_4 = *(undefined2 *)(ppuVar2 + 0x122);
    break;
  case MPROP_LIBRARY_VERSION:
    puVar11 = (undefined4 *)scoreEngine_getChannelField((int)ppuVar2,1);
    if (puVar11 != (undefined4 *)0x0) {
      if (puVar11[0x12] == 0) {
        uVar9 = stage_getSpriteScriptCount(*(int *)(*(int *)*puVar11 + 0x14));
        puVar11[0x12] = uVar9;
      }
      goto LAB_6808dd99;
    }
    goto LAB_6808dd9d;
  case MPROP_CHANNEL_VERSION:
    puVar11 = (undefined4 *)scoreEngine_getChannelField((int)ppuVar2,*(short *)param_4);
LAB_6808dd99:
    if (puVar11 != (undefined4 *)0x0) {
      *(undefined4 *)param_4 = puVar11[0x12];
      break;
    }
LAB_6808dd9d:
    *(undefined4 *)param_4 = 0;
    goto switchD_6808dce0_caseD_10;
  case MPROP_CAST_DATA_2E6:
    *(undefined4 **)param_4 = ppuVar2[0x2e6];
    break;
  case MPROP_SCORE_CHANNEL_MAX:
    uVar9 = scoreEngine_createNewScore((int *)ppuVar2);
    *(undefined4 *)param_4 = uVar9;
    break;
  case MPROP_TYPE_BYTE:
    *(int *)param_4 = (int)*(char *)(ppuVar2 + 0x137);
    break;
  case MPROP_EXT_FLAG_A:
    *(int *)param_4 = (int)*(char *)((int)ppuVar2 + 0x4dd);
    break;
  case MPROP_EXT_FLAG_B:
    *(int *)param_4 = (int)*(short *)((int)ppuVar2 + 0x4de);
    break;
  case MPROP_RESERVED_C:
    /* FIXUP(C2094): goto switchD_6808dce0_caseD_c; */
  case MPROP_DISPLAY_CAPABILITY:
    bVar4 = scoreEngine_checkChannelFlag(0);
    *(uint *)param_4 = CONCAT31(extraout_var_00,bVar4);
    break;
  case MPROP_CAST_DATA_116:
    *(undefined4 **)param_4 = ppuVar2[0x116];
    break;
  case MPROP_LOAD_RESOURCE:
    *(undefined4 *)param_4 = 0;
    local_7b8 = (int *)Ordinal_1111(0,4);
    if ((local_7b8 != (int *)0x0) && (iVar8 = Ordinal_1404(&local_7bc,local_7b8,3), iVar8 != 0)) {
      iVar8 = playback_getFontMapRawData((int *)ppuVar2,(int)local_7bc,(int *)0x0);
      iVar6 = Ordinal_1407(&local_7bc);
      if ((iVar6 != 0) && (iVar8 != 0)) {
        *(int **)param_4 = local_7b8;
        break;
      }
    }
    Ordinal_1113(&local_7b8);
  default:
    goto switchD_6808dce0_caseD_10;
  case MPROP_FRAME_COUNT:
    iVar8 = scoreEngine_getChannelState((int)ppuVar2);
    *(int *)param_4 = iVar8;
    break;
  case MPROP_CAST_DATA_19B:
    *(undefined4 **)param_4 = ppuVar2[0x19b];
    break;
  case MPROP_GOTO_FRAME_FIRST:
    *(undefined4 **)param_4 = ppuVar2[0x17f];
    break;
  case MPROP_GOTO_FRAME_SECOND:
    *(undefined4 **)param_4 = ppuVar2[0x180];
    break;
  case MPROP_CAST_DATA_197:
    *(undefined4 **)param_4 = ppuVar2[0x197];
    break;
  case MPROP_CAST_DATA_196:
    *(undefined4 **)param_4 = ppuVar2[0x196];
    break;
  case MPROP_CAST_DATA_198:
    *(undefined4 **)param_4 = ppuVar2[0x198];
    break;
  case MPROP_MOVIE_STATUS_FLAGS:
    *(undefined4 *)param_4 = 0;
    if (ppuVar2[4] == (undefined4 *)0x0) {
      *(undefined4 *)param_4 = 1;
    }
    if (ppuVar2[5] == (undefined4 *)0x1) {
      *(uint *)param_4 = *(uint *)param_4 | 4;
    }
    if (ppuVar2[7] != (undefined4 *)0x0) {
      *(uint *)param_4 = *(uint *)param_4 | 2;
    }
    uVar5 = rendering_getChannelType((int)(ppuVar2 + 0x123));
    if (uVar5 < 0x79f) {
      *(uint *)param_4 = *(uint *)param_4 | 0x10;
      break;
    }
    /* FIXUP(C2094): goto switchD_6808dce0_caseD_c; */
  case MPROP_EXT_COMPAT:
    *(undefined1 *)param_4 = *(undefined1 *)((int)ppuVar2 + 0x49d);
    break;
  case MPROP_MEMBER_FLAG_BIT0:
    *(uint *)param_4 = *(byte *)(ppuVar2 + 0x127) & 1;
    break;
  case MPROP_PROPERTY_STORE:
    if (ppuVar2[0x11b] != (undefined4 *)0x0) {
      iVar8 = cast_lookupDataEntry((int)ppuVar2[0x11b],(uint)*(ushort *)((int)param_4 + 4),1);
      *(int *)param_4 = iVar8;
      break;
    }
    /* FIXUP(C2094): goto switchD_6808dce0_caseD_c; */
  case MPROP_RESOLVE_CAST_REF:
    local_7c4 = (int *)playback_loadScoreOrFontMap(uVar9,(int)(ppuVar2 + 3),*(int *)param_4,
                                    *(int *)((int)param_4 + 4) + 0x400,(int *)((int)param_4 + 0xc),
                                    *(undefined4 **)(param_4 + 1));
    if (local_7c4 != (int *)0x0) break;
    goto switchD_6808dce0_caseD_10;
  case MPROP_CAST_SLOT_COUNT:
    iVar8 = rendering_refreshChannel((int)(ppuVar2 + 0x123));
    *(int *)param_4 = iVar8;
    break;
  case MPROP_CAST_DATA_1A1:
    *(undefined4 **)param_4 = ppuVar2[0x1a1];
    break;
  case MPROP_EXT_QUALITY:
    *(undefined1 *)param_4 = *(undefined1 *)((int)ppuVar2 + 0x4aa);
    break;
  case MPROP_EXT_RATE:
    if (*(byte *)((int)ppuVar2 + 0x4c1) < 0x65) {
      *(byte *)param_4 = *(byte *)((int)ppuVar2 + 0x4c1);
    }
    else {
      *(undefined1 *)param_4 = 0x50;
    }
    break;
  case MPROP_CAST_DATA_1A2:
    *(undefined4 **)param_4 = ppuVar2[0x1a2];
    break;
  case MPROP_CAST_DATA_1A3:
    *(undefined4 **)param_4 = ppuVar2[0x1a3];
    break;
  case MPROP_PALETTE_MODE:
    switch ((int)(size_t)ppuVar2[0x12d]) { /* FIXUP(C2050): cast non-integral switch to int */
    case (undefined4 *)0x0:
      *(undefined4 *)param_4 = 0x54e;
      /* FIXUP(C2094): goto LAB_6808e842; */
    case (undefined4 *)0x1:
switchD_6808e166_caseD_1:
      *(undefined4 *)param_4 = 0x547;
      /* FIXUP(C2094): goto LAB_6808e842; */
    case (undefined4 *)0x2:
switchD_6808e166_caseD_2:
      *(undefined4 *)param_4 = 0x54b;
      /* FIXUP(C2094): goto LAB_6808e842; */
    case (undefined4 *)0x3:
switchD_6808e166_caseD_3:
      *(undefined4 *)param_4 = 0x54a;
      /* FIXUP(C2094): goto LAB_6808e842; */
    case (undefined4 *)0x4:
switchD_6808e166_caseD_4:
      *(undefined4 *)param_4 = 0x54f;
      /* FIXUP(C2094): goto LAB_6808e842; */
    case (undefined4 *)0x5:
switchD_6808e166_caseD_5:
      *(undefined4 *)param_4 = 0x549;
      /* FIXUP(C2094): goto LAB_6808e842; */
    }
    goto switchD_6808e166_default;
  case MPROP_ACTIVE_PALETTE:
    local_7bc = (undefined4 ***)0x0;
    local_7b8 = (int *)0x0;
    uVar9 = Ordinal_1038(&DAT_681765b8,&DAT_681765c8,&local_7b8);
    Ordinal_2063(uVar9);
    if (local_7b8 != (int *)0x0) {
      (**(code **)(*local_7b8 + 0xc))(local_7b8);
      (**(code **)(*local_7b8 + 0x14))(local_7b8,&local_7bc);
      (**(code **)(*local_7b8 + 8))(local_7b8);
    }
    switch ((int)(size_t)local_7bc) { /* FIXUP(C2050): cast non-integral switch to int */
    case (undefined4 ***)0x1:
      goto switchD_6808e166_caseD_1;
    case (undefined4 ***)0x2:
      goto switchD_6808e166_caseD_2;
    case (undefined4 ***)0x3:
      goto switchD_6808e166_caseD_3;
    case (undefined4 ***)0x4:
      goto switchD_6808e166_caseD_4;
    case (undefined4 ***)0x5:
      goto switchD_6808e166_caseD_5;
    }
    goto switchD_6808e166_default;
  case MPROP_XTRA_INFO_STRINGS:
    local_7bc = (undefined4 ***)0x0;
    local_698 = 0;
    memset(local_696,0,0xfe);
    local_798 = 0;
    memset(local_796,0,0xfe);
    local_108 = 0;
    memset(local_106,0,0xfe);
    local_7c0 = (int *)0x0;
    local_7b8 = (int *)0x0;
    uVar9 = Ordinal_1038(&DAT_681765b8,&DAT_681765c8,&local_7b8);
    Ordinal_2063(uVar9);
    /* FIXUP(C2094): if (local_7b8 == (int *)0x0) goto switchD_6808dce0_caseD_c; */
    (**(code **)(*local_7b8 + 0xc))(local_7b8);
    if (*(int *)param_4 == 0) {
LAB_6808e269:
      if (*(int *)(param_4 + 1) != 0) {
        local_7c0 = (int *)&local_798;
        iVar8 = (**(code **)(*local_7b8 + 0x34))(local_7b8,&local_7c0,&local_7bc);
        if (iVar8 != 0) goto LAB_6808e826;
        Ordinal_1203(*(undefined4 *)(param_4 + 1),local_7c0,*(undefined4 *)((int)param_4 + 0xc));
        uVar9 = Ordinal_1201(*(undefined4 *)(param_4 + 1));
        *(undefined4 *)((int)param_4 + 0xc) = uVar9;
      }
      if (*(int *)(param_4 + 2) != 0) {
        local_7c0 = (int *)&local_108;
        iVar8 = (**(code **)(*local_7b8 + 0x38))(local_7b8,&local_7c0,&local_7bc);
        if (iVar8 != 0) goto LAB_6808e826;
        Ordinal_1203(*(undefined4 *)(param_4 + 2),local_7c0,*(undefined4 *)((int)param_4 + 0x14));
        uVar9 = Ordinal_1201(*(undefined4 *)(param_4 + 2));
        *(undefined4 *)((int)param_4 + 0x14) = uVar9;
      }
      (**(code **)(*local_7b8 + 8))(local_7b8);
      break;
    }
    local_7c0 = (int *)&local_698;
    iVar8 = (**(code **)(*local_7b8 + 0x30))(local_7b8,&local_7c0,&local_7bc);
    if (iVar8 == 0) {
      Ordinal_1203(*(undefined4 *)param_4,local_7c0,*(undefined4 *)((int)param_4 + 4));
      uVar9 = Ordinal_1201(*(undefined4 *)param_4);
      *(undefined4 *)((int)param_4 + 4) = uVar9;
      goto LAB_6808e269;
    }
LAB_6808e826:
    (**(code **)(*local_7b8 + 8))(local_7b8);
    goto switchD_6808dce0_caseD_10;
  case MPROP_STREAM_GUID_CHECK:
    local_7b8 = (int *)0x0;
    local_7c0 = (int *)0x0;
    local_7bc = (undefined4 ***)0x0;
    local_7a8 = 0xf8bf17e1;
    local_7a4 = 0x11d388d4;
    local_7a0 = 0xa0009c98;
    local_79c = 0x252d90c9;
    *(undefined4 *)param_4 = 0;
    uVar9 = Ordinal_1038();
    local_7c8 = (int *)Ordinal_2075(uVar9);
    if (local_7c8 != (int *)0x0) {
      (**(code **)*local_7c8)(local_7c8,&DAT_68176258,&local_7b8);
      if (local_7b8 != (int *)0x0) {
        if (ppuVar2 == (undefined4 **)0x0) {
          puVar11 = (undefined4 *)0x0;
        }
        else {
          puVar11 = *ppuVar2;
        }
        lingo_dispatchVtableOp((int)puVar11,&local_7c0);
        if (local_7c0 != (int *)0x0) {
          iVar8 = (**(code **)(*local_7b8 + 0xc))(local_7b8,local_7c0,&local_7c4,&local_7bc);
          if (iVar8 == 0) {
            pppuVar12 = (undefined4 ***)0x0;
            if (local_7bc != (undefined4 ***)0x0) {
              do {
                iVar8 = (**(code **)(*local_7b8 + 0x10))
                                  (local_7b8,local_7c4,pppuVar12,4,0,auStack_599 + 1,0);
                if ((iVar8 == 0) && (iVar8 = Ordinal_2066(&local_7a8,auStack_599 + 1), iVar8 != 0))
                {
                  *(undefined4 *)param_4 = 1;
                  break;
                }
                pppuVar12 = (undefined4 ***)((int)pppuVar12 + 1);
              } while (pppuVar12 < local_7bc);
            }
            (**(code **)(*local_7b8 + 0x18))(local_7b8,local_7c0,local_7c4,0);
          }
          if (local_7c0 != (int *)0x0) {
            (**(code **)(*local_7c0 + 8))(local_7c0);
          }
        }
        if (local_7b8 != (int *)0x0) {
          (**(code **)(*local_7b8 + 8))(local_7b8);
        }
      }
      (**(code **)(*local_7c8 + 8))(local_7c8);
      break;
    }
    /* FIXUP(C2094): goto switchD_6808dce0_caseD_c; */
  case MPROP_LINKED_FILE_DATA:
    if ((0 < *(int *)param_4) &&
       (iVar8 = media_dispatchScoredEvent((int)local_7c0,(int)local_7bc,*(int *)param_4,*(int *)(param_4 + 1),
                             *(int *)((int)param_4 + 4)), iVar8 == -1)) {
      **(undefined1 **)(param_4 + 1) = 0;
      break;
    }
    /* FIXUP(C2094): goto switchD_6808dce0_caseD_c; */
  case MPROP_STRING_PROP_A:
    if ((ppuVar2[0x11b] != (undefined4 *)0x0) &&
       (iVar8 = Ordinal_38((int)ppuVar2[0x11b],9,auStack_599 + 1,0x3ff), 1 < iVar8)) {
      iVar8 = iVar8 + -1;
      if (*(int *)((int)param_4 + 4) + -1 < iVar8) {
        puVar7 = auStack_599 + *(int *)((int)param_4 + 4);
LAB_6808e516:
        local_7c8 = (int *)0x0;
        iVar8 = Ordinal_1251(auStack_599 + 1,puVar7,&local_7c8);
        iVar8 = iVar8 - (int)(auStack_599 + 1);
      }
LAB_6808e53e:
      Ordinal_1128(*(undefined4 *)param_4,auStack_599 + 2,iVar8);
      *(undefined1 *)(iVar8 + *(int *)param_4) = 0;
      *(int *)((int)param_4 + 4) = iVar8;
      break;
    }
    goto switchD_6808dce0_caseD_10;
  case MPROP_STRING_PROP_B:
    if ((ppuVar2[0x11b] != (undefined4 *)0x0) &&
       (iVar8 = Ordinal_38((int)ppuVar2[0x11b],10,auStack_599 + 1,0x3ff), 1 < iVar8)) {
      iVar8 = iVar8 + -1;
      if (*(int *)((int)param_4 + 4) + -1 < iVar8) {
        puVar7 = auStack_599 + *(int *)((int)param_4 + 4);
        goto LAB_6808e516;
      }
      goto LAB_6808e53e;
    }
    goto switchD_6808dce0_caseD_10;
  case MPROP_SOUND_FORMAT:
    puVar11 = ppuVar2[0x12e];
    if (puVar11 == (undefined4 *)0x1) {
      *(undefined4 *)param_4 = 0x217;
      break;
    }
    if (puVar11 == (undefined4 *)0x2) {
      *(undefined4 *)param_4 = 0x218;
      break;
    }
    if (puVar11 == (undefined4 *)0x4) {
      *(undefined4 *)param_4 = 0x21a;
      break;
    }
switchD_6808dce0_caseD_10:
    Ordinal_1130(param_4,0x18);
    break;
  case MPROP_CAST_DATA_139:
    *(undefined4 **)param_4 = ppuVar2[0x139];
    break;
  case MPROP_CAST_DATA_13A:
    *(undefined4 **)param_4 = ppuVar2[0x13a];
    break;
  case MPROP_ENCODING_TYPE:
    if (ppuVar2[0x12f] == (undefined4 *)0x0) {
      *(undefined4 *)param_4 = 0x4a5;
      break;
    }
    if (ppuVar2[0x12f] == (undefined4 *)0x1) {
      *(undefined4 *)param_4 = 0x23;
      break;
    }
switchD_6808e166_default:
    *(undefined4 *)param_4 = 0x37b;
    break;
  case MPROP_CAST_DATA_13B:
    *(undefined4 **)param_4 = ppuVar2[0x13b];
    break;
  case MPROP_BITMASK_PROP:
    *(uint *)((int)param_4 + 4) = (uint)(((uint)ppuVar2[0x138] & *(uint *)param_4) != 0);
    break;
  case MPROP_DISPLAY_MODE:
    bVar4 = scoreEngine_checkChannelFlag(0x10);
    *(uint *)param_4 = (CONCAT31(extraout_var,bVar4) != 0) + 9;
    break;
  case MPROP_CHANNEL_COUNT:
    iVar8 = scoreEngine_getChannelType((int)ppuVar2);
    *(int *)param_4 = iVar8;
    break;
  case MPROP_FILE_ENUM_BOUNDS:
    media_getXtraDownloadStats(ppuVar2 + 0x114,(int *)param_4,(int *)((int)param_4 + 4));
    break;
  case MPROP_FILE_ENUM_LIST:
    piVar10 = (int *)0x0;
    local_7b8 = (int *)0x0;
    local_7c8 = (int *)crt_getPlatformId();
    iVar8 = media_allocCastNodeLocked((int)local_7c0,(int)local_7bc,(int *)&local_7b8,(int)&local_7c4);
    if (iVar8 == 0) {
      uVar3 = *(uint *)((int)param_4 + 4);
      *(undefined4 *)((int)param_4 + 4) = 0;
      if (local_7c4 != (int *)0x0) {
        do {
          iVar8 = media_loadXtraBlock(local_7b8,(int)piVar10,0,0x20,0,&local_198,(int *)0x0);
          if (((iVar8 == 0) && (local_198 == 0)) &&
             (iVar8 = media_loadXtraBlock(local_7b8,(int)piVar10,0,6,(int)local_7c8,&local_198,(int *)0x0),
             iVar8 == 0)) {
            if (local_198 == 0xff) {
              uVar13 = Ordinal_1201(local_197);
            }
            else {
              uVar13 = (uint)local_198;
            }
            if (*(int *)((int)param_4 + 4) + 2 + uVar13 < uVar3) {
              Ordinal_1202(*(int *)param_4 + *(int *)((int)param_4 + 4),local_197);
              *(int *)((int)param_4 + 4) = *(int *)((int)param_4 + 4) + uVar13;
              *(undefined1 *)(*(int *)((int)param_4 + 4) + *(int *)param_4) = 0x2c;
              *(int *)((int)param_4 + 4) = *(int *)((int)param_4 + 4) + 1;
              *(undefined1 *)(*(int *)((int)param_4 + 4) + *(int *)param_4) = 0;
            }
          }
          piVar10 = (int *)((int)piVar10 + 1);
        } while (piVar10 < local_7c4);
      }
    }
    if (local_7b8 != (int *)0x0) {
      media_assignCastDataLocked((int)local_7c0,local_7bc,(int)local_7b8,0);
      break;
    }
    /* FIXUP(C2094): goto switchD_6808dce0_caseD_c; */
  case MPROP_TEMPO_DOUBLE:
    *param_4 = *(double *)(ppuVar2 + 0x2ea);
    break;
  case MPROP_TEMPO_FLOAT:
    local_7bc = (undefined4 ***)0x0;
    local_7c4 = (int *)0x0;
    uVar9 = Ordinal_1038(&DAT_681765b8,&DAT_681765c8,&local_7c4);
    Ordinal_2063(uVar9);
    if (local_7c4 != (int *)0x0) {
      (**(code **)(*local_7c4 + 0x80))(local_7c4,&local_7bc);
    }
    *param_4 = (double)(float)(size_t)local_7bc;
/* FIXUP(C2143-ctx): switchD_6808dce0_caseD_c: */
  } /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */;
/* FIXUP(C2143-ctx): LAB_6808e842: */
  /* FIXUP(C2143-ctx): if (piVar1 != (int *)0x0) { */
    DAT_68196374 = local_7b0;
    Ordinal_2331();
  }
  /* FIXUP(C2143): __security_check_cookie(local_8 ^ (uint)&stack0xfffffffc); */
  /* FIXUP(C2059): return 0; */
/* FIXUP(C2059): } */



