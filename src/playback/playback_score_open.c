// Module: playback
// Topic: Score opening flow, file IO dispatch, main playback loop
// Address range: 0x680d5f80 - 0x680d77e0
// Functions (21):
//   playback_executeScoreFrame, playback_loadMediaChunk, playback_processScoreChannelBlock, playback_readScoreChannelEntry, playback_processScoreEntry
//   playback_processScoreChannelData, playback_parseScoreBlock, playback_processScoreBlockData, playback_readScoreFrameData, playback_dispatchScoreChannel
//   playback_processScoreActions, playback_notifyScoreEvent, playback_applyScoreDefaults, playback_openScore, playback_loadScoreData
//   playback_loadScoreDataDirect, playback_openScoreEx, playback_initScoreDataStream, playback_createScoreContext, playback_resetTimerState
//   playback_isScoreReady

// ============================================================
// Function: playback_executeScoreFrame (playback_executeScoreFrame)
// Address: 680d5f80
// Size: 3068 bytes
// Params: void * this, int * param_1, int param_2, int param_3, void * param_4
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall playback_executeScoreFrame(void *this,int *param_1,int param_2,int param_3,void *param_4)
{
  bool bVar1;
  bool bVar2;
  ushort uVar3;
  short sVar4;
  int iVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined4 uVar7;
  uint uVar8;
  int *piVar9;
  undefined3 extraout_var_00;
  void *pvVar10;
  undefined3 extraout_var_01;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  uint uVar11;
  int *piVar12;
  byte *pbVar13;
  int *piVar14;
  short local_550 [2];
  undefined4 local_54c;
  uint local_548;
  int *local_540;
  undefined4 local_53c;
  int local_538;
  int local_534;
  int local_530;
  int local_52c;
  int local_528;
  uint local_524;
  int local_520;
  int *local_51c;
  int *local_518;
  int *local_514;
  byte *local_510;
  uint local_50c;
  int local_508;
  int *local_504;
  int *local_500;
  int local_4fc [5];
  undefined4 local_4e8;
  int *local_4e0;
  undefined1 local_4dc [28];
  undefined4 local_4c0;
  undefined2 local_488;
  undefined2 local_486;
  int local_420 [5];
  char acStack_40c [244];
  undefined4 local_318 [196];
  uint local_8;
  
  piVar9 = *(int **)((int)this + 0x20);
  local_514 = param_1;
  local_50c = (uint)param_4 >> 4 & 1;
  local_500 = *(int **)(piVar9[1] + 8);
  uVar11 = (uint)param_4 & 1;
  local_508 = 0;
  local_530 = 0;
  local_528 = 0;
  local_524 = uVar11;
  local_510 = this;
  local_504 = piVar9;
  iVar5 = playback_getLifecycleData((int)this);
  local_520 = iVar5;
  bVar1 = lingo_isScriptReady(piVar9[1]);
  local_52c = CONCAT31(extraout_var,bVar1);
  if ((iVar5 != 0) && ((*(byte *)(piVar9[1] + 0xc) & 4) != 0)) {
    param_4 = (void *)((uint)param_4 | 0x10);
    local_50c = 1;
  }
  piVar9[8] = (int)param_4;
  if (local_514 == (int *)0x0) goto LAB_680d64c1;
  if (piVar9[0x113] == 0) {
    if (uVar11 == 0) {
      iVar5 = playback_loadMediaBlock(piVar9,0,0);
      piVar9[0x112] = iVar5;
    }
    piVar9[0x141] = 0;
    *(undefined2 *)(piVar9 + 0x126) = 1;
  }
  if (piVar9[0x113] < 2) {
    Ordinal_1310(local_514,acStack_40c + 4,0x3ff);
    iVar5 = Ordinal_1201(acStack_40c + 4);
    piVar12 = local_514;
    if (((4 < iVar5) && (acStack_40c[iVar5 + 3] == 'r')) &&
       (((acStack_40c[iVar5 + 2] == 'x' &&
         ((acStack_40c[iVar5 + 1] == 'd' && (acStack_40c[iVar5] == '.')))) ||
        ((acStack_40c[iVar5 + 2] == 'c' &&
         ((acStack_40c[iVar5 + 1] == 'd' && (acStack_40c[iVar5] == '.')))))))) {
      param_4 = (void *)((uint)param_4 | 2);
    }
    piVar9[7] = param_2;
    local_518 = (int *)playback_createScoreContext((int)local_500,piVar9 + 3,local_514,param_2,param_4);
    playback_resolveMediaPath(piVar12);
    piVar14 = piVar9 + 10;
    for (iVar5 = 0x106; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar14 = *piVar12;
      piVar12 = piVar12 + 1;
      piVar14 = piVar14 + 1;
    }
    piVar9[0x2ea] = 0;
    piVar9[0x2eb] = 0;
    if (local_518 == (int *)0xc) {
      piVar9[0x113] = 1;
      return 0;
    }
    iVar5 = playback_initMediaChannels();
    piVar9 = local_504;
    if (iVar5 != 0) goto LAB_680d616c;
    goto LAB_680d6420;
  }
LAB_680d616c:
  if (param_3 == 0) {
    piVar12 = local_514;
    piVar14 = local_420;
    for (iVar5 = 0x106; iVar5 != 0; iVar5 = iVar5 + -1) {
      *piVar14 = *piVar12;
      piVar12 = piVar12 + 1;
      piVar14 = piVar14 + 1;
    }
    Ordinal_1316(local_420);
    Ordinal_1300(local_420);
  }
  piVar12 = local_514;
  if (piVar9[0x113] < 2) {
    local_51c = piVar9 + 3;
    local_518 = piVar9 + 0x123;
    playback_initScoreChannelState(local_500,(undefined2 *)local_518,(int)local_51c,local_514,piVar9 + 0x1a0);
    iVar5 = lingo_getMovieRef((int)local_500);
    if (iVar5 == 0) {
      iVar5 = rendering_updateChannelState((int)local_518);
      piVar9[0x140] = iVar5;
      piVar9[0x13d] = (int)(short)piVar9[0x124];
      piVar9[0x13c] = (int)*(short *)((int)piVar9 + 0x492);
      piVar9[0x13e] = (int)*(short *)((int)piVar9 + 0x496);
      piVar9[0x13f] = (int)(short)piVar9[0x125];
      if ((piVar9[0x1a0] == 0) || (local_50c == 0)) {
        iVar5 = 0;
      }
      else {
        iVar5 = 1;
      }
      iVar5 = playback_loadFontMapData(local_500,piVar12,iVar5);
      if (iVar5 == 0) {
        iVar5 = media_getDataPtr((int *)local_500[1]);
        local_530 = iVar5;
        uVar11 = scoreEngine_getScoreFlag((int)piVar9);
        if (((uVar11 == 0) && (((uint)param_4 & 2) == 0)) && (*(int *)(iVar5 + 0x180) != 0)) {
          acStack_40c[4] = 0;
          local_50c = uVar11;
          memset(acStack_40c + 5,0,0x3fe);
          Ordinal_1310(piVar9 + 10,acStack_40c + 4,0x3ff);
          if ((uint)piVar9[0x140] < 0x1100) {
            (**(code **)(iVar5 + 0x180))(piVar9[0x140],&local_50c,acStack_40c + 4);
            if (local_50c == 0xfffffe36) {
              param_4 = (void *)((uint)param_4 | 2);
            }
            local_528 = 1;
          }
        }
        pbVar13 = local_510;
        if ((local_52c != 0) && (*(int *)(*(int *)(local_510 + 0x20) + 0x674) != 0)) {
          scoreEngine_updateMonitorRegions(*(int *)(local_510 + 0x20));
        }
        if (local_520 != 0) {
          playback_setSoundProperty(pbVar13,0);
          scoreEngine_readCastXtraBlock((int)piVar9,(undefined1 *)&local_50c);
          rendering_getStageData(piVar9,*(int *)(pbVar13 + 0x24),(int *)&local_50c);
        }
        playback_processLoadedChannels((int *)pbVar13);
        piVar12 = local_51c;
        uVar7 = extraout_ECX;
        if (param_3 == 0) {
          playback_isMediaLoaded(extraout_ECX,(int)local_51c,(int)pbVar13);
          iVar5 = lingo_getMovieRef((int)local_500);
          uVar7 = extraout_ECX_00;
          piVar9 = local_504;
          pbVar13 = local_510;
          if (iVar5 != 0) goto LAB_680d6420;
        }
        playback_isMediaLoaded(uVar7,(int)piVar12,(int)pbVar13);
        iVar5 = lingo_getMovieRef((int)local_500);
        piVar9 = local_504;
        if (iVar5 != 0) goto LAB_680d6420;
        uVar11 = rendering_updateChannelState((int)local_518);
        if (uVar11 < 0x500) {
          Ordinal_1130(local_550,0x20);
          Ordinal_1130(local_4fc,0xdc);
          iVar5 = Ordinal_1201("Internal",0);
          local_54c = Ordinal_1111(iVar5 + 1);
          uVar7 = Ordinal_1114(local_54c);
          Ordinal_1219(uVar7,"Internal");
          Ordinal_1115(local_54c);
          piVar12 = local_504;
          local_4e8 = 1;
          local_4e0 = local_504;
          Ordinal_1130(local_4dc,0x10);
          uVar3 = scoreEngine_readChannelWord((int)piVar12);
          local_488 = (undefined2)piVar12[0x126];
          local_486 = *(undefined2 *)((int)piVar12 + 0x49a);
          local_548 = (uint)uVar3;
          local_4c0 = 0x400;
          uVar11 = rendering_getChannelInfo((int)local_500,local_4fc);
          local_550[0] = (short)uVar11;
          piVar9 = local_504;
          if ((local_550[0] != 0) &&
             (sVar4 = scoreEngine_getChannelValue((int)piVar12,(int)local_550), piVar9 = local_504, sVar4 != 0)) {
LAB_680d65c6:
            local_504[0x113] = 2;
            piVar9 = local_504;
            goto LAB_680d65d8;
          }
          goto LAB_680d6420;
        }
        playback_isMediaLoaded(local_510,(int)piVar12,(int)local_510);
        iVar5 = lingo_getMovieRef((int)local_500);
        piVar9 = local_504;
        if (iVar5 != 0) goto LAB_680d6420;
        iVar5 = scoreEngine_getChannelField((int)local_504,1);
        if (iVar5 != 0) goto LAB_680d65c6;
        iVar5 = -0x1ae;
LAB_680d6412:
        lingo_formatDebugMsg(local_500,iVar5);
        piVar9 = local_504;
      }
    }
LAB_680d6420:
    if (piVar9[9] != 0) {
      Ordinal_1163(piVar9 + 9);
      piVar9[9] = 0;
    }
    piVar9[0x113] = 0;
    if (local_508 == 1) {
      piVar9[0x111] = 1;
    }
    if (piVar9[0x112] != 0) {
      iVar5 = Ordinal_1154(piVar9[0x112]);
      piVar12 = local_500;
      while (0 < iVar5) {
        iVar5 = iVar5 + -1;
        iVar6 = Ordinal_1155(piVar9[0x112],iVar5,&local_524);
        if (iVar6 != 0) {
          rendering_setChannelProperty(piVar12,local_524,0);
        }
      }
      Ordinal_1163(piVar9 + 0x112);
    }
  }
  else {
LAB_680d65d8:
    piVar12 = local_500;
    if (2 < piVar9[0x113]) {
LAB_680d6637:
      uVar11 = local_524;
      if ((piVar9[0x113] < 4) && (param_3 == 0)) {
        uVar8 = 0;
        if (local_524 != 0) {
          uVar8 = ~((uint)param_4 >> 3) & 1;
        }
        piVar12 = piVar9 + 3;
        local_51c = piVar12;
        iVar5 = media_loadXtraOrchestrator(piVar9 + 0x114,local_500,piVar9 + 0x114,piVar12,(int)piVar9,uVar8);
        if (iVar5 == 2) {
          local_508 = 2;
          goto LAB_680d64a2;
        }
        if (((uVar11 == 0) || (((uint)param_4 & 0xc0) == 0)) && (iVar5 != 0)) {
          iVar5 = crt_finalizeResource((int *)piVar9[4]);
          if (iVar5 == 0) {
            local_540 = piVar9 + 0x143;
            local_53c = 0;
            local_538 = 0;
            local_534 = 0;
            local_53c = rendering_updateChannelState((int)(piVar9 + 0x123));
            local_538 = rendering_refreshChannel((int)(piVar9 + 0x123));
            local_534 = piVar9[0x120];
            if (piVar9[9] == 0) {
              iVar5 = Ordinal_1150(0,1,4);
              piVar9[9] = iVar5;
            }
            local_50c = 1;
            if (0 < (short)piVar9[0x11e]) {
              do {
                uVar11 = local_50c;
                iVar5 = scoreEngine_getChannelField((int)piVar9,(short)local_50c);
                if (((iVar5 != 0) && (*(int *)(iVar5 + 0x14) != 0)) &&
                   ((*(int *)(iVar5 + 0xc) == 0 &&
                    (iVar5 = playback_buildMediaTable((int)piVar12), piVar9 = local_504, uVar11 = local_50c,
                    piVar12 = local_51c, iVar5 == 0)))) goto LAB_680d6420;
                local_50c = uVar11 + 1;
              } while ((short)local_50c <= (short)piVar9[0x11e]);
            }
            piVar9[0x113] = 4;
            goto LAB_680d679f;
          }
          lingo_formatDebugMsg(local_500,iVar5);
        }
      }
      else {
LAB_680d679f:
        pbVar13 = local_510;
        if ((piVar9[0x113] < 5) && (param_3 == 0)) {
          sVar4 = 1;
          if (0 < (short)piVar9[0x11e]) {
            do {
              iVar5 = scoreEngine_getChannelField((int)piVar9,sVar4);
              if ((((iVar5 != 0) && (*(int *)(iVar5 + 0x14) != 0)) && (*(int *)(iVar5 + 0xc) == 0))
                 && (iVar5 = display_checkChannelSlots((int)pbVar13,iVar5), iVar5 == 0)) goto LAB_680d6608;
              sVar4 = sVar4 + 1;
            } while (sVar4 <= (short)piVar9[0x11e]);
          }
          local_53c = 0;
          local_538 = 0;
          local_534 = 0;
          local_540 = piVar9 + 0x143;
          local_53c = rendering_updateChannelState((int)(piVar9 + 0x123));
          local_538 = rendering_refreshChannel((int)(piVar9 + 0x123));
          local_534 = piVar9[0x120];
          sVar4 = 1;
          if (0 < (short)piVar9[0x11e]) {
            do {
              iVar5 = scoreEngine_getChannelField((int)piVar9,sVar4);
              if (((iVar5 != 0) && (*(int *)(iVar5 + 0x14) != 0)) && (*(int *)(iVar5 + 0xc) == 0)) {
                iVar6 = playback_indexMediaEntries((int)local_510,(int)(piVar9 + 3),piVar9[2],(int)&local_540,
                                     param_4);
                piVar9 = local_504;
                if (iVar6 == 0) goto LAB_680d6420;
                *(undefined4 *)(iVar5 + 0xc) = 1;
              }
              sVar4 = sVar4 + 1;
            } while (sVar4 <= (short)piVar9[0x11e]);
          }
          lingo_executeMethod((int)local_500,local_318);
          piVar12 = piVar9 + 3;
          playback_isMediaLoaded(extraout_ECX_01,(int)piVar12,(int)local_510);
          iVar5 = lingo_getMovieRef((int)local_500);
          pbVar13 = local_510;
          piVar9 = local_504;
          if (iVar5 == 0) {
            uVar7 = extraout_ECX_02;
            if (*(int *)(local_510 + 0x28) == 0) {
              piVar9 = media_getScoreStatePtr();
              if (piVar9 == (int *)0x0) {
                iVar5 = -0x7a;
                goto LAB_680d6412;
              }
              iVar5 = 0;
              uVar3 = scoreEngine_getChannelFlags((int)local_504);
              iVar5 = playback_goToFrame((void *)(uint)uVar3,(uint *)*local_504,(int)piVar9,uVar3,iVar5);
              uVar7 = extraout_ECX_03;
              piVar9 = local_504;
              if (iVar5 == 0) goto LAB_680d6420;
            }
            playback_isMediaLoaded(uVar7,(int)piVar12,(int)pbVar13);
            iVar5 = lingo_getMovieRef((int)local_500);
            piVar9 = local_504;
            if (iVar5 == 0) {
              playback_isMediaLoaded(extraout_ECX_04,(int)piVar12,(int)pbVar13);
              iVar5 = lingo_getMovieRef((int)local_500);
              piVar9 = local_504;
              if (iVar5 == 0) {
                playback_isMediaLoaded(extraout_ECX_05,(int)piVar12,(int)pbVar13);
                iVar5 = lingo_getMovieRef((int)local_500);
                piVar9 = local_504;
                if (iVar5 == 0) {
                  playback_isMediaLoaded(extraout_ECX_06,(int)piVar12,(int)pbVar13);
                  iVar5 = lingo_getMovieRef((int)local_500);
                  piVar9 = local_504;
                  if (iVar5 == 0) {
                    sVar4 = scoreEngine_getChannelFlags((int)local_504);
                    scoreEngine_setPlaybackFrame(piVar9,sVar4);
                    if (local_520 != 0) {
                      if (((local_52c == 0) || (*(int *)(*(int *)(pbVar13 + 0x20) + 0x674) == 0)) ||
                         ((*(int *)(*(int *)(pbVar13 + 0x24) + 0x10) != 0 &&
                          (*(int *)(*(int *)(pbVar13 + 0x24) + 0x14) != 0)))) {
                        bVar1 = false;
                      }
                      else {
                        bVar1 = true;
                      }
                      bVar2 = lingo_isScriptReady(*(int *)(*(int *)(pbVar13 + 0x20) + 4));
                      playback_setSoundProperty(pbVar13,CONCAT31(extraout_var_00,bVar2));
                      if (bVar1) {
                        scoreEngine_updateMonitorRegions((int)piVar9);
                      }
                    }
                    piVar9[0x113] = 5;
                    goto LAB_680d6a3c;
                  }
                }
              }
            }
          }
        }
        else {
LAB_680d6a3c:
          if (piVar9[0x113] < 6) {
            pvVar10 = param_4;
            if (piVar9[7] != 0) {
              pvVar10 = (void *)((uint)param_4 & 0xfffffffd);
            }
            local_508 = scoreEngine_resetThumbnails(piVar9,pvVar10);
            if (local_508 == 2) goto LAB_680d64a2;
            piVar9[0x113] = 6;
          }
          if ((piVar9[0x113] < 7) && (((uint)param_4 & 8) == 0)) {
            if ((char)piVar9[0x137] == '\0') {
              if (0 < *(short *)((int)piVar9 + 0x4de)) {
                local_50c = 0;
                iVar5 = scoreEngine_editFrameRange(piVar9,1,(int)*(short *)((int)piVar9 + 0x4de),1,1,
                                     (int *)&local_50c);
                if ((iVar5 == 0) && (local_50c == 0)) {
                  local_508 = 2;
                  goto LAB_680d64a2;
                }
              }
            }
            else {
              bVar1 = strings_checkStreamBounds(piVar9[4]);
              if (CONCAT31(extraout_var_01,bVar1) == 0) {
                local_508 = 2;
                goto LAB_680d64a2;
              }
            }
          }
          uVar11 = rendering_updateChannelState((int)(piVar9 + 0x123));
          pbVar13 = local_510;
          if ((uVar11 < 0x1100) && (local_528 != 0)) {
            playback_finalizeMediaLoad();
          }
          local_508 = 1;
          rendering_getChannelType((int)(piVar9 + 0x123));
          if ((local_520 != 0) && (local_52c != 0)) {
            uVar3 = rendering_getChannelType(*(int *)(pbVar13 + 0x20) + 0x48c);
            if (uVar3 < 0x57e) {
              scoreEngine_invokeCallback(*(int *)(*(int *)(pbVar13 + 0x20) + 4),0);
            }
            else {
              scoreEngine_invokeCallback(*(int *)(*(int *)(pbVar13 + 0x20) + 4),1);
            }
          }
        }
      }
      goto LAB_680d6420;
    }
    if (param_3 != 0) {
LAB_680d6625:
      piVar9[0x113] = 3;
      bitmap_readCastStreams((int)piVar9);
      bitmap_processFontMapping((int)piVar9);
      goto LAB_680d6637;
    }
    iVar5 = playback_loadFontMapFromScore(local_500,piVar9 + 0x143,(int)(piVar9 + 3));
    if (iVar5 != 2) {
      iVar5 = lingo_getMovieRef((int)piVar12);
      if (iVar5 != 0) goto LAB_680d6420;
      goto LAB_680d6625;
    }
LAB_680d6608:
    local_508 = 2;
  }
LAB_680d64a2:
  if (((local_528 != 0) && (local_530 != 0)) && (*(code **)(local_530 + 0x184) != (code *)0x0)) {
    (**(code **)(local_530 + 0x184))();
  }
LAB_680d64c1:
  return 0;
}



// ============================================================
// Function: playback_loadMediaChunk (FUN_680d6b80)
// Address: 680d6b80
// Size: 366 bytes
// Params: void * param_1, int * param_2, int param_3, int param_4, void * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int playback_loadMediaChunk(void *param_1,int *param_2,int param_3,int param_4,void *param_5)

{
  undefined1 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *piVar5;
  int local_18 [3];
  int *local_c;
  int local_8;
  
  local_c = (int *)0x0;
  local_8 = 0;
  if (((uint)param_5 & 1) != 0) {
    iVar3 = playback_executeScoreFrame(param_1,param_2,param_3,param_4,param_5);
    return iVar3;
  }
  local_18[1] = 0;
  local_18[0] = 0;
  local_18[2] = 0;
  *(undefined4 *)(*(int *)((int)param_1 + 0x18) + 900) = 0;
  do {
    iVar3 = playback_executeScoreFrame(param_1,param_2,param_3,param_4,param_5);
    if ((local_c == (int *)0x0) &&
       (iVar4 = *(int *)(*(int *)((int)param_1 + 0x20) + 0x10), iVar4 != 0)) {
      if (iVar3 != 2) goto LAB_680d6c77;
      iVar4 = xtra_getScriptContext(iVar4);
      if (iVar4 != 0) {
        crt_getStreamRef(iVar4,(int *)&local_c);
      }
    }
    else if (iVar3 != 2) goto LAB_680d6c77;
    if (local_18[2] == 0) {
      uVar1 = lingo_resolveRef(*(int *)((int)param_1 + 0x18),0,&local_8);
      iVar4 = CONCAT31(extraout_var,uVar1);
      if (iVar4 == 0) goto LAB_680d6c93;
      local_18[2] = 1;
    }
    else {
      iVar4 = lingo_callMethod(*(int *)((int)param_1 + 0x18),&local_8,param_2,local_c,
                           (int)(local_18 + 1),0);
    }
    if (iVar4 == 0) goto LAB_680d6c77;
    if ((*(int **)((int)param_1 + 0x18))[0xe1] != 0) break;
    bVar2 = lingo_isMovieLoaded(*(int **)((int)param_1 + 0x18));
  } while (CONCAT31(extraout_var_00,bVar2) == 0);
  local_8 = -0x7ffbadf8;
  iVar3 = 0;
LAB_680d6c77:
  if (local_18[2] != 0) {
    lingo_callMethod(*(int *)((int)param_1 + 0x18),local_18,param_2,0,(int)(local_18 + 1),0);
  }
LAB_680d6c93:
  if (local_8 == 0) {
    if (local_18[0] == 0) goto LAB_680d6cd4;
    local_8 = local_18[0];
  }
  iVar4 = lingo_getMovieRef(*(int *)((int)param_1 + 0x18));
  if (iVar4 == 0) {
    if (local_8 == -0x7ffbef70) {
      piVar5 = *(int **)((int)param_1 + 0x18);
      iVar3 = -0x1c7;
    }
    else {
      piVar5 = *(int **)((int)param_1 + 0x18);
      iVar3 = -0x74;
    }
    lingo_formatDebugMsg(piVar5,iVar3);
    iVar3 = 0;
  }
LAB_680d6cd4:
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  return iVar3;
}



// ============================================================
// Function: playback_processScoreChannelBlock (playback_processScoreChannelBlock)
// Address: 680d6cf0
// Size: 58 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_processScoreChannelBlock(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return 0;
  default:
    return 1;
  case 0x66:
    return 6;
  case 0x67:
    return 2;
  case 0x68:
    return 3;
  case 0x6d:
    return 0xc;
  case 0x75:
    return 7;
  }
}



// ============================================================
// Function: playback_readScoreChannelEntry (playback_readScoreChannelEntry)
// Address: 680d6dc0
// Size: 80 bytes
// Params: int param_1, int param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_readScoreChannelEntry(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  
  iVar3 = 1;
  puVar4 = param_4;
  iVar1 = crt_searchChunkByType(param_1,param_2);
  iVar1 = display_openStream(param_1,param_2,iVar1,iVar3,puVar4);
  if (iVar1 == 0) {
    Ordinal_1042();
    uVar2 = playback_processScoreChannelBlock();
    return uVar2;
  }
  if (param_3 != (undefined4 *)0x0) {
    uVar2 = Ordinal_1435(*param_4);
    *param_3 = uVar2;
  }
  return 0;
}



// ============================================================
// Function: playback_processScoreEntry (playback_processScoreEntry)
// Address: 680d6e10
// Size: 50 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_processScoreEntry(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = display_openStream(param_1,param_2,param_3,2,param_4);
  if (iVar1 == 0) {
    Ordinal_1042();
    uVar2 = playback_processScoreChannelBlock();
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: playback_processScoreChannelData (playback_processScoreChannelData)
// Address: 680d6e50
// Size: 91 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_processScoreChannelData(void)

{
  int in_EAX;
  
  if (in_EAX < 1) {
    if (in_EAX == 0) {
      return 0;
    }
    switch(in_EAX) {
    case -0x31:
    case -0x2f:
    case -0x2b:
      return 2;
    case -0x27:
      return 3;
    }
  }
  else {
    switch(in_EAX) {
    case 0xc9:
    case 0xcf:
    case 0xd0:
      return 5;
    case 0xcb:
    case 0xcc:
    case 0xcd:
    case 0xce:
      return 7;
    case 0xd1:
      return 6;
    }
  }
  return 1;
}



// ============================================================
// Function: playback_parseScoreBlock (playback_parseScoreBlock)
// Address: 680d6ee0
// Size: 90 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_parseScoreBlock(void)

{
  int in_EAX;
  
  if (-0x7ffbffa9 < in_EAX) {
    if (in_EAX == -0x7ffbffa8) {
      return 4;
    }
    if (in_EAX == -0x7ffbadf8) {
      return 0xd;
    }
    if (in_EAX == 0) {
      return 0;
    }
switchD_680d6efa_caseD_80040003:
    return 0xf;
  }
  if (in_EAX != -0x7ffbffa9) {
    switch(in_EAX) {
    case -0x7ffbfffe:
      return 0xe;
    default:
      goto switchD_680d6efa_caseD_80040003;
    case -0x7ffbfffa:
    case -0x7ffbffaf:
      return 2;
    case -0x7ffbffac:
      break;
    }
  }
  return 3;
}



// ============================================================
// Function: playback_processScoreBlockData (playback_processScoreBlockData)
// Address: 680d6fa0
// Size: 339 bytes
// Params: undefined4 param_1, undefined4 * param_2, int * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_processScoreBlockData(int param_1,undefined4 *param_2,int *param_3,undefined4 param_4)
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *unaff_EBX;
  undefined4 *puVar5;
  int local_440;
  int local_43c;
  int *local_438;
  int *local_434;
  undefined4 local_430 [262];
  int local_18;
  int *local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_438 = param_3;
  local_43c = 0;
  local_434 = (int *)param_1;
  if (param_2 != (undefined4 *)0x0) {
    if (unaff_EBX[0xd5] == 0) {
      iVar2 = Ordinal_1150(0,0,0x428);
      unaff_EBX[0xd5] = iVar2;
      if (iVar2 != 0) {
LAB_680d7029:
        piVar3 = strings_openMediaContainer(unaff_EBX,param_2,&local_440,param_4,(int)local_434);
        local_434 = piVar3;
        iVar2 = playback_processScoreChannelData();
        *local_438 = iVar2;
        if ((piVar3 != (int *)0x0) && (iVar2 == 0)) {
          uVar1 = unaff_EBX[0xd5];
          puVar5 = local_430;
          for (iVar4 = 0x106; iVar4 != 0; iVar4 = iVar4 + -1) {
            *puVar5 = *param_2;
            param_2 = param_2 + 1;
            puVar5 = puVar5 + 1;
          }
          local_14 = local_434;
          local_10 = 3;
          local_c = 1;
          local_18 = iVar2;
          iVar2 = Ordinal_1152(uVar1,local_430);
          if (iVar2 == 0) {
            strings_closeMediaStream(local_434);
            *local_438 = 6;
            local_434 = (int *)0x0;
          }
        }
        if (local_43c != 0) {
          Ordinal_1158(unaff_EBX[0xd5],local_43c);
        }
        return 0;
      }
      *local_438 = 6;
    }
    else {
      local_43c = Ordinal_1157(unaff_EBX[0xd5]);
      if (local_43c != 0) goto LAB_680d7029;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_readScoreFrameData (playback_readScoreFrameData)
// Address: 680d7100
// Size: 637 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int param_3, undefined4 * param_4, int param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
playback_readScoreFrameData(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4,int param_5)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  int local_43c;
  int *local_434;
  undefined4 local_430 [262];
  int local_18;
  int *local_14;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  local_434 = (int *)*param_4;
  local_43c = 0;
  if (param_2 != (undefined4 *)0x0) {
    if (param_1[0xd5] == 0) {
      iVar1 = Ordinal_1150(0,0,0x428);
      param_1[0xd5] = iVar1;
      if (iVar1 == 0) goto LAB_680d733d;
    }
    else {
      local_43c = Ordinal_1157(param_1[0xd5]);
      if (local_43c == 0) goto LAB_680d733d;
      uVar2 = Ordinal_1154(param_1[0xd5]);
      uVar4 = 0;
      if (uVar2 != 0) {
        do {
          iVar1 = Ordinal_1156(param_1[0xd5],local_43c,uVar4);
          iVar3 = Ordinal_1319(iVar1,param_2);
          if ((iVar3 != 0) && (*(int *)(iVar1 + 0x418) == param_3)) {
            if ((uVar4 != 0xffffffff) &&
               (((iVar3 = Ordinal_1377(0x19,param_2), iVar3 == 0 &&
                 (iVar3 = Ordinal_1313(param_2), iVar3 != 4)) &&
                (iVar3 = Ordinal_1377(0x15,param_2), iVar3 == 0)))) {
              if ((param_5 != 3) || (*(int *)(iVar1 + 0x420) != 1)) {
                local_434 = *(int **)(iVar1 + 0x41c);
                *(int *)(iVar1 + 0x424) = *(int *)(iVar1 + 0x424) + 1;
              }
              goto LAB_680d733d;
            }
            break;
          }
          uVar4 = uVar4 + 1;
        } while (uVar4 < uVar2);
      }
    }
    puVar5 = local_430;
    for (iVar1 = 0x106; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar5 = *param_2;
      param_2 = param_2 + 1;
      puVar5 = puVar5 + 1;
    }
    iVar1 = strings_loadMediaContainer(param_1,(int *)&local_434,local_430,0,(param_5 == 3) * '\x02' + '\x01',
                         param_3);
    if (iVar1 == 0) {
      local_18 = param_3;
      local_14 = local_434;
      local_10 = param_5;
      local_c = 1;
      iVar1 = Ordinal_1152(param_1[0xd5],local_430);
      if (iVar1 == 0) {
        strings_closeMediaStream(local_434);
      }
      else {
        *param_4 = local_434;
      }
    }
    else {
      if (iVar1 < 0xd0) {
        if ((iVar1 == 0xcf) || (((iVar1 == -0x3b || (iVar1 == -0x2d)) || (iVar1 == 0xc9))))
        goto LAB_680d733d;
      }
      else if ((iVar1 == 0xd3) || (iVar1 == 0x1f6)) goto LAB_680d733d;
      Ordinal_1351(local_430);
    }
  }
LAB_680d733d:
  *param_4 = local_434;
  if (local_43c != 0) {
    Ordinal_1158(param_1[0xd5],local_43c);
  }
  return 0;
}



// ============================================================
// Function: playback_dispatchScoreChannel (playback_dispatchScoreChannel)
// Address: 680d7380
// Size: 204 bytes
// Params: undefined4 param_1, int param_2, int * param_3, undefined4 * param_4
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_dispatchScoreChannel(undefined4 param_1,int param_2,int *param_3,undefined4 *param_4)

{
  int local_18;
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 local_c;
  
  local_c = 0;
  *param_4 = 0;
  iVar3 = 0;
  if (param_3 != (int *)0x0) {
    puVar1 = (undefined4 *)(param_2 + 0x354);
    if (*(int *)(param_2 + 0x354) != 0) {
      iVar3 = Ordinal_1157(*(int *)(param_2 + 0x354));
      if (iVar3 == 0) {
        return 1;
      }
      uVar4 = Ordinal_1154(*puVar1);
      uVar6 = 0;
      if (uVar4 != 0) {
        do {
          iVar5 = Ordinal_1156(*puVar1,iVar3,uVar6);
          if (*(int **)(iVar5 + 0x41c) == param_3) {
            *param_4 = 1;
            piVar2 = (int *)(iVar5 + 0x424);
            *piVar2 = *piVar2 + -1;
            if (*piVar2 == 0) {
              local_c = strings_closeMediaStream(param_3);
              Ordinal_1160(*puVar1,uVar6);
              if (uVar4 == 1) {
                Ordinal_1158(*puVar1,iVar3);
                Ordinal_1163(puVar1);
                return local_c;
              }
            }
            break;
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < uVar4);
      }
      Ordinal_1158(*puVar1,iVar3);
      iVar3 = local_c;
    }
  }
  return iVar3;
}



// ============================================================
// Function: playback_processScoreActions (playback_processScoreActions)
// Address: 680d7450
// Size: 286 bytes
// Params: void * this, undefined4 * param_1, int param_2, int * param_3, int param_4
// Return: int
// Calling convention: __thiscall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int __thiscall playback_processScoreActions(void *this,undefined4 *param_1,int param_2,int *param_3,int param_4)

{
  undefined1 uVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int *unaff_ESI;
  int **ppiVar5;
  int local_18 [3];
  int *local_c;
  int local_8;
  
  local_8 = 0;
  local_c = (int *)0x0;
  local_18[2] = 0;
  local_18[1] = 0;
  local_18[0] = 0;
  unaff_ESI[0xe1] = 0;
  do {
    iVar3 = playback_readScoreFrameData(unaff_ESI,param_1,param_2,param_3,param_4);
    if (((uint)this & 1) != 0) goto LAB_680d7518;
    if (local_c == (int *)0x0) {
      if (iVar3 != 0xc) goto LAB_680d7518;
      ppiVar5 = &local_c;
      iVar4 = xtra_getScriptContext(*param_3);
      crt_getStreamRef(iVar4,(int *)ppiVar5);
    }
    else if (iVar3 != 0xc) goto LAB_680d7518;
    if (local_18[2] == 0) {
      uVar1 = lingo_resolveRef((int)unaff_ESI,0,&local_8);
      iVar4 = CONCAT31(extraout_var,uVar1);
      if (iVar4 == 0) goto LAB_680d7534;
      local_18[2] = 1;
    }
    else {
      iVar4 = lingo_callMethod((int)unaff_ESI,&local_8,param_1,local_c,(int)(local_18 + 1),0);
    }
    if (iVar4 == 0) goto LAB_680d7518;
    if (unaff_ESI[0xe1] != 0) break;
    bVar2 = lingo_isMovieLoaded(unaff_ESI);
  } while (CONCAT31(extraout_var_00,bVar2) == 0);
  local_8 = -0x7ffbadf8;
LAB_680d7518:
  if (local_18[2] != 0) {
    lingo_callMethod((int)unaff_ESI,local_18,param_1,0,(int)(local_18 + 1),0);
  }
LAB_680d7534:
  if (local_8 == 0) {
    if (local_18[0] == 0) goto LAB_680d7555;
    local_8 = local_18[0];
  }
  if ((iVar3 == 0) || (iVar3 == 0xc)) {
    iVar3 = playback_parseScoreBlock();
  }
LAB_680d7555:
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  return iVar3;
}



// ============================================================
// Function: playback_notifyScoreEvent (playback_notifyScoreEvent)
// Address: 680d7570
// Size: 18 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_notifyScoreEvent(undefined4 param_1)
{
  Ordinal_1130(param_1,0x10);
  return 0;
}



// ============================================================
// Function: playback_applyScoreDefaults (playback_applyScoreDefaults)
// Address: 680d7590
// Size: 103 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3, undefined4 param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_applyScoreDefaults(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
                int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_2[1] != 0) {
    return 2;
  }
  *param_2 = param_1;
  iVar1 = Ordinal_1351(param_3);
  if (iVar1 == 0) {
    if (param_5 == 1) {
      return 9;
    }
  }
  else if (param_5 == 0) {
    return 9;
  }
  uVar2 = playback_processScoreBlockData(param_5,param_3,&param_5,param_4);
  param_2[1] = uVar2;
  return param_5;
}



// ============================================================
// Function: playback_openScore (FUN_680d7600)
// Address: 680d7600
// Size: 67 bytes
// Params: int param_1, int param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_openScore(int param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = strings_openMediaStream(*(int *)(param_1 + 4),param_2,param_3);
  if (iVar1 != -1) {
    uVar2 = playback_readScoreChannelEntry(*(int *)(param_1 + 4),iVar1,param_4,param_5);
    return uVar2;
  }
  return 7;
}



// ============================================================
// Function: playback_loadScoreData (playback_loadScoreData)
// Address: 680d7650
// Size: 24 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_loadScoreData(int param_1)
{
  strings_finalizeMediaStream(*(int *)(param_1 + 4));
  playback_processScoreChannelData();
  return 0;
}



// ============================================================
// Function: playback_loadScoreDataDirect (playback_loadScoreDataDirect)
// Address: 680d7670
// Size: 34 bytes
// Params: int param_1, int param_2, int param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_loadScoreDataDirect(int param_1,int param_2,int param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = strings_searchMediaByType(*(int *)(param_1 + 4),param_2,param_3);
  *param_4 = iVar1;
  return 0;
}



// ============================================================
// Function: playback_openScoreEx (FUN_680d76a0)
// Address: 680d76a0
// Size: 69 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_openScoreEx(int *param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = param_1;
  iVar1 = param_1[1];
  if (iVar1 != 0) {
    iVar2 = *param_1;
    param_1 = (int *)0x0;
    playback_dispatchScoreChannel(iVar1,iVar2,(int *)(size_t)iVar1,&param_1);
    if (param_1 == (int *)0x0) {
      strings_closeMediaStream((int *)piVar3[1]);
    }
    piVar3[1] = 0;
    *piVar3 = 0;
  }
  playback_processScoreChannelData();
  return 0;
}



// ============================================================
// Function: playback_initScoreDataStream (playback_initScoreDataStream)
// Address: 680d76f0
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_initScoreDataStream(int param_1)
{
  if (*(int *)(param_1 + 0x354) != 0) {
    Ordinal_1163((int *)(param_1 + 0x354));
  }
  return 0;
}



// ============================================================
// Function: playback_createScoreContext (FUN_680d7710)
// Address: 680d7710
// Size: 175 bytes
// Params: int param_1, int * param_2, undefined4 * param_3, int param_4, void * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_createScoreContext(int param_1,int *param_2,undefined4 *param_3,int param_4,void *param_5)

{
  int *piVar1;
  void *this;
  int iVar2;
  int iVar3;
  
  this = param_5;
  piVar1 = param_2;
  iVar3 = 3;
  if ((param_2[1] != 0) && (param_2[3] != 0xc)) {
    return 2;
  }
  *param_2 = param_1;
  if ((((uint)param_5 & 2) == 0) && (param_4 < 1)) {
    iVar2 = Ordinal_1402(&param_2,param_3,3);
    if (iVar2 != 0) {
      Ordinal_1407(&param_2);
      goto LAB_680d7769;
    }
  }
  iVar3 = 1;
LAB_680d7769:
  piVar1[2] = iVar3;
  iVar3 = playback_processScoreActions(this,param_3,param_4,piVar1 + 1,iVar3);
  piVar1[3] = iVar3;
  if (iVar3 == 2) {
    iVar2 = Ordinal_1351(param_3);
    if (iVar2 != 0) {
      return 8;
    }
  }
  if ((iVar3 == 0xc) && (((uint)this & 1) == 0)) {
    playback_openScoreEx(piVar1);
  }
  return iVar3;
}



// ============================================================
// Function: playback_resetTimerState (playback_resetTimerState)
// Address: 680d77c0
// Size: 31 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resetTimerState(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0xcc) == 0) {
    uVar1 = Ordinal_1541();
    *(undefined4 *)(unaff_ESI + 200) = uVar1;
    *(undefined4 *)(unaff_ESI + 0xcc) = 1;
  }
  return 0;
}



// ============================================================
// Function: playback_isScoreReady (FUN_680d77e0)
// Address: 680d77e0
// Size: 31 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool playback_isScoreReady(void)

{
  bool bVar1;
  int in_EAX;
  
  if (*(int *)(*(int *)(*(int *)(in_EAX + 0x20) + 4) + 0x110) != 0) {
    return true;
  }
  bVar1 = lingo_isMovieLoaded(*(int **)(in_EAX + 0x18));
  return bVar1;
}



