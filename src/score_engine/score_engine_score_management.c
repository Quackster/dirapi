// Module: score_engine
// Topic: Score management - score init, thumbnails, frame walking, member lookup, step recording
// Address range: 0x68086200 - 0x680883e0
// Functions (41):
//   scoreEngine_readChannelWithBlend
//   scoreEngine_updateScore
//   scoreEngine_initScoreChannel
//   scoreEngine_swapScoreData
//   scoreEngine_initScoreDefaults
//   scoreEngine_readAndWriteMedia
//   scoreEngine_getChannelData
//   scoreEngine_getChannelCount
//   scoreEngine_getLastFrameKey
//   scoreEngine_getLastChannelFrame
//   scoreEngine_setScoreField
//   scoreEngine_setChannelField
//   scoreEngine_resetScore
//   scoreEngine_getScoreState
//   scoreEngine_seekToFrame
//   scoreEngine_loadMemberData
//   scoreEngine_getMaxZOrder
//   scoreEngine_createThumbnail
//   scoreEngine_resetThumbnails
//   scoreEngine_deleteFrame
//   scoreEngine_loadSoundData
//   scoreEngine_saveSoundData
//   scoreEngine_playSoundChannel
//   scoreEngine_stopSoundChannel
//   scoreEngine_setSoundVolume
//   scoreEngine_getScoreIterator
//   scoreEngine_advanceIterator
//   scoreEngine_resetIterator
//   scoreEngine_freeIterator
//   scoreEngine_applyScoreEdit
//   scoreEngine_initScoreData
//   scoreEngine_commitScoreEdit
//   scoreEngine_insertScoreFrame
//   scoreEngine_appendScoreFrame
//   scoreEngine_duplicateFrames
//   scoreEngine_deleteFrames
//   scoreEngine_pasteFrames
//   scoreEngine_editFrameRange
//   scoreEngine_getScoreContext
//   Ordinal_213
//   scoreEngine_setScoreContext

// ============================================================
// Function: scoreEngine_readChannelWithBlend (FUN_68086200)
// Address: 68086200
// Size: 117 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_readChannelWithBlend(int *param_1,int *param_2,int *param_3)

{
  int local_18;
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  piVar1 = param_3;
  if (param_3[2] == 0) goto LAB_6808625e;
  iVar3 = *param_3;
  param_3 = (int *)0x0;
  uVar2 = scoreEngine_readChannelBlock(param_1,param_2,iVar3);
  if (uVar2 == 0) {
    if (*piVar1 != 0) {
      iVar3 = rendering_blendMedia(param_1,param_2,(int *)&param_3);
      if ((param_3 != (int *)0x800412e0) && (param_3 != (int *)0x0)) {
        piVar1[3] = (int)param_3;
      }
      if (iVar3 != 0) goto LAB_68086256;
    }
    piVar1[2] = 0;
  }
LAB_68086256:
  if (piVar1[2] != 0) {
    return 1;
  }
LAB_6808625e:
  if (piVar1[1] != 0) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_updateScore (FUN_68086280)
// Address: 68086280
// Size: 87 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_updateScore(int *param_1,int param_2)
{
  uint *puVar1;
  
  if (param_1[2] != 0) {
    stage_releaseSpriteRef(param_1 + 2);
  }
  puVar1 = (uint *)*param_1;
  scoreEngine_freeScoreData();
  scoreEngine_writePropertyFlags(param_1);
  playback_loadMediaBlock(param_1,1,param_2);
  playback_getLifecycleValue(puVar1);
  Ordinal_1125(param_1);
  Ordinal_1309(param_1 + 10,0x400,"",0);
  return 0;
}



// ============================================================
// Function: scoreEngine_initScoreChannel (FUN_680862e0)
// Address: 680862e0
// Size: 339 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_initScoreChannel(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  uint *puVar2;
  int iVar3;
  int *piVar4;
  int extraout_EDX;
  
  piVar1 = param_2;
  piVar4 = *(int **)(param_1 + 8);
  param_2[1] = param_1;
  puVar2 = (uint *)Ordinal_1124(0x18c);
  *param_2 = (int)puVar2;
  if (puVar2 != (uint *)0x0) {
    if (param_3 != 0) {
      param_2 = (int *)(param_2[1] + 0x24);
    }
    playback_initPlaybackState((int)puVar2,(int)piVar1);
    puVar2[2] = 1;
    if (param_3 != 0) {
      iVar3 = playback_dispatchLifecycle(puVar2,(uint)param_2);
      if (iVar3 == 0) goto LAB_68086422;
    }
    scoreEngine_markDirty((int)piVar1,0);
    *(char *)((int)piVar1 + 0x5f9) = (char)extraout_EDX;
    *(undefined2 *)(piVar1 + 0x122) = 1;
    piVar1[0x17f] = extraout_EDX;
    piVar1[0x180] = extraout_EDX;
    if (param_3 != extraout_EDX) {
      rendering_getStageRefById((int)param_2);
    }
    playback_resetControlState((int)puVar2);
    playback_notifyScoreEvent(piVar1 + 3);
    media_initCastPair(piVar1 + 0x114);
    Ordinal_1309(piVar1 + 10,0x400,"",0);
    iVar3 = rendering_initScorePalette((int)piVar1);
    if (iVar3 != 0) {
      piVar1[0x188] = *(int *)(piVar4[1] + 0x84);
      piVar1[0x189] = 2;
      piVar1[0x18a] = (int)piVar1;
      Ordinal_1109(piVar1 + 0x188);
      *(undefined2 *)((int)piVar1 + 0x48e) = 0x79f;
      *(undefined2 *)(piVar1 + 300) = 0x79f;
      iVar3 = rendering_updateChannelState((int)(piVar1 + 0x123));
      piVar1[0x140] = iVar3;
      piVar4 = stage_createSpriteFromChannel(*(undefined4 *)(*piVar4 + 0x14),*(int *)(param_1 + 4),*piVar1);
      piVar1[2] = (int)piVar4;
      if (piVar4 != (int *)0x0) {
        return 1;
      }
    }
  }
LAB_68086422:
  scoreEngine_updateScore(piVar1,0);
  return 0;
}



// ============================================================
// Function: scoreEngine_swapScoreData (FUN_68086440)
// Address: 68086440
// Size: 415 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_swapScoreData(int *param_1,undefined4 *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  short sVar10;
  int *piVar11;
  int *piVar12;
  int local_30;
  int local_2c;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  local_2c = playback_initLifecycle(*param_1,local_18,local_28);
  iVar8 = param_1[0x188];
  iVar1 = param_1[0x189];
  local_30 = param_1[2];
  iVar2 = param_1[0x18a];
  iVar3 = param_1[0x18b];
  iVar4 = param_1[0x18c];
  iVar5 = param_1[0x18d];
  param_1[2] = 0;
  Ordinal_1130(param_1 + 0x188,0x18);
  Ordinal_1110(*(int *)*param_2 + 0x620);
  iVar6 = *param_1;
  scoreEngine_updateScore(param_1,local_30);
  piVar11 = *(int **)*param_2;
  piVar12 = param_1;
  for (iVar9 = 0x2ec; iVar9 != 0; iVar9 = iVar9 + -1) {
    *piVar12 = *piVar11;
    piVar11 = piVar11 + 1;
    piVar12 = piVar12 + 1;
  }
  param_1[0x188] = iVar8;
  param_1[0x189] = iVar1;
  param_1[0x18a] = iVar2;
  param_1[0x18b] = iVar3;
  param_1[0x18c] = iVar4;
  param_1[0x18d] = iVar5;
  if (local_2c != 0) {
    playback_initLifecycleBlock(*param_1,local_18,local_28);
  }
  *(int **)(*param_1 + 0x20) = param_1;
  local_2c = *(int *)(param_1[1] + 8);
  sVar10 = 1;
  if (0 < (short)param_1[0x11e]) {
    do {
      psVar7 = (short *)scoreEngine_getFrameData((int)param_1,sVar10);
      if (psVar7 != (short *)0x0) {
        if (*(int *)(psVar7 + 0xe) == *(int *)*param_2) {
          *(int **)(psVar7 + 0xe) = param_1;
        }
        iVar8 = rendering_getChannelSprite(local_2c,*psVar7);
        if ((*(int *)(iVar8 + 0x14) != 0) && (*(int *)(iVar8 + 0x1c) == *(int *)*param_2)) {
          *(int **)(iVar8 + 0x1c) = param_1;
        }
        scoreEngine_cleanupMembers(param_1,psVar7);
      }
      sVar10 = sVar10 + 1;
    } while (sVar10 <= (short)param_1[0x11e]);
  }
  iVar8 = local_30;
  stage_detachSprite(local_30,iVar6);
  stage_detachSprite(param_1[2],iVar6);
  Ordinal_1113(param_2);
  if (iVar8 != 0) {
    stage_swapFrameData(param_1[2],iVar8);
    scoreEngine_storeDeferredAsset(*(int *)(param_1[1] + 8),&local_30,0);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_initScoreDefaults (FUN_680865f0)
// Address: 680865f0
// Size: 258 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_initScoreDefaults(int *param_1)
{
  undefined2 uVar1;
  short sVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_2c;
  undefined1 local_28 [32];
  uint local_8;
  
  iVar3 = scoreEngine_getScoreLibraryId((int)param_1);
  *(undefined2 *)(param_1 + 300) = 0x79f;
  param_1[0x123] = 0x79f0064;
  param_1[0x126] = 1;
  *(undefined2 *)((int)param_1 + 0x4c2) = 0x1e;
  uVar1 = rendering_updateStageLayout(*(int *)(*param_1 + 0x24));
  *(undefined2 *)(param_1 + 0x12a) = uVar1;
  *(undefined2 *)((int)param_1 + 0x4b2) = 0;
  *(undefined1 *)((int)param_1 + 0x49d) = 0;
  uVar4 = strings_getDefaultCastType();
  local_2c = CONCAT22((short)uVar4,0xffff);
  scoreEngine_setChannelState((int)param_1,local_2c);
  *(undefined2 *)((int)param_1 + 0x4de) = 1;
  *(undefined1 *)((int)param_1 + 0x4aa) = 0xfd;
  *(undefined1 *)((int)param_1 + 0x4c1) = 0x50;
  *(undefined1 *)(param_1 + 0x137) = 1;
  if (*(code **)(iVar3 + 0x194) != (code *)0x0) {
    (**(code **)(iVar3 + 0x194))(local_28,0x20);
    sVar2 = Ordinal_1206(local_28,"Trial");
    *(bool *)(param_1 + 0x130) = sVar2 == 0;
    return 0;
  }
  *(undefined1 *)(param_1 + 0x130) = 0;
  return 0;
}



// ============================================================
// Function: scoreEngine_readAndWriteMedia (FUN_68086700)
// Address: 68086700
// Size: 66 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_readAndWriteMedia(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int *unaff_ESI;
  int unaff_EDI;
  int local_8;
  
  uVar1 = scoreEngine_readChannelBlock(*(int **)(unaff_EDI + 0x20),unaff_ESI,1);
  if (uVar1 == 0) {
    iVar2 = rendering_blendMedia(*(int **)(unaff_EDI + 0x20),unaff_ESI,&local_8);
    if (iVar2 == 0) {
      return 1;
    }
  }
  uVar3 = rendering_writeMediaBlock(unaff_EDI,unaff_ESI,param_1);
  return uVar3;
}



// ============================================================
// Function: scoreEngine_getChannelData (scoreEngine_getChannelData)
// Address: 68086750
// Size: 120 bytes
// Params: int param_1, short param_2
// Return: short
// Calling convention: __stdcall
// ============================================================

short scoreEngine_getChannelData(int param_1,short param_2)

{
  short sVar1;
  short *psVar2;
  
  sVar1 = 0;
  if (param_2 != 0) {
    if (param_2 == -1) {
      return -1;
    }
    if (0x3fff < param_2) {
      return param_2 + -0x4000;
    }
    psVar2 = (short *)scoreEngine_getFrameData(param_1,param_2);
    if (psVar2 != (short *)0x0) {
      sVar1 = *psVar2;
    }
  }
  return sVar1;
}



// ============================================================
// Function: scoreEngine_getChannelCount (FUN_680867d0)
// Address: 680867d0
// Size: 144 bytes
// Params: int param_1, short param_2
// Return: short
// Calling convention: __stdcall
// ============================================================

short scoreEngine_getChannelCount(int param_1,short param_2)

{
  short *psVar1;
  short sVar2;
  
  sVar2 = 0;
  if (param_2 != 0) {
    if (param_2 == -1) {
      return -1;
    }
    sVar2 = 1;
    if (0 < *(short *)(param_1 + 0x478)) {
      do {
        psVar1 = (short *)scoreEngine_getFrameData(param_1,sVar2);
        if ((psVar1 != (short *)0x0) && (*psVar1 == param_2)) {
          if (sVar2 != 0) {
            return sVar2;
          }
          break;
        }
        sVar2 = sVar2 + 1;
      } while (sVar2 <= *(short *)(param_1 + 0x478));
    }
    sVar2 = param_2 + 0x4000;
  }
  return sVar2;
}



// ============================================================
// Function: scoreEngine_getLastFrameKey (FUN_68086860)
// Address: 68086860
// Size: 96 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_getLastFrameKey(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = scoreEngine_getChannelField(param_1,*(short *)(param_1 + 0x478));
  if ((iVar1 != 0) && (*(int *)(iVar1 + 0x40) != 0)) {
    iVar2 = Ordinal_1154(*(int *)(iVar1 + 0x40));
    iVar1 = Ordinal_1156(*(undefined4 *)(iVar1 + 0x40),*(undefined4 *)(iVar1 + 0x44),iVar2 + -1);
    if (iVar1 != 0) {
      local_8 = CONCAT22(*(undefined2 *)(iVar1 + 6),*(undefined2 *)(param_1 + 0x478));
    }
  }
  return local_8;
}



// ============================================================
// Function: scoreEngine_getLastChannelFrame (FUN_680868c0)
// Address: 680868c0
// Size: 26 bytes
// Params: int param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getLastChannelFrame(int param_1,short param_2)
{
  int iVar1;
  
  iVar1 = scoreEngine_getChannelField(param_1,param_2);
  rendering_getLastChannelFrame(iVar1);
  return 0;
}



// ============================================================
// Function: scoreEngine_setScoreField (FUN_680868e0)
// Address: 680868e0
// Size: 63 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_setScoreField(int param_1,int param_2)

{
  short sVar1;
  
  sVar1 = (short)param_2;
  if (((0 < sVar1) && (sVar1 <= *(short *)(param_1 + 0x478))) && (0xffff < param_2)) {
    sVar1 = scoreEngine_getLastChannelFrame(param_1,sVar1);
    if ((short)((uint)param_2 >> 0x10) <= sVar1) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setChannelField (FUN_68086920)
// Address: 68086920
// Size: 58 bytes
// Params: uint param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setChannelField(uint param_1,undefined4 param_2)

{
  uint uVar1;
  short sVar2;
  undefined2 extraout_var;
  int iVar3;
  int local_8;
  
  uVar1 = param_1;
  local_8 = 0;
  iVar3 = 0;
  if (param_1 != 0) {
    sVar2 = scoreEngine_getChannelData(param_1,(short)param_2);
    rendering_resolveStateEx(*(int *)(*(int *)(uVar1 + 4) + 8),CONCAT22(extraout_var,sVar2),&param_1,&local_8);
    iVar3 = local_8;
  }
  return iVar3;
}



// ============================================================
// Function: scoreEngine_resetScore (FUN_68086960)
// Address: 68086960
// Size: 71 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_resetScore(int *param_1)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = param_1;
  if ((param_1 != (int *)0x0) && (puVar1 = (undefined4 *)*param_1, puVar1 != (undefined4 *)0x0)) {
    param_1 = (int *)*puVar1;
    rendering_getDispatchState(puVar1 + 3);
    rendering_getDispatchState(puVar1 + 2);
    Ordinal_1115(param_1);
    Ordinal_1113(&param_1);
    *piVar2 = 0;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getScoreState (FUN_680869b0)
// Address: 680869b0
// Size: 105 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getScoreState(int param_1)

{
  int *piVar1;
  int iVar2;
  short *psVar3;
  int *piVar4;
  
  if (param_1 != 0) {
    piVar1 = (int *)(param_1 + 0xc);
    do {
      while (*piVar1 != 0) {
        iVar2 = rendering_getMemberCache(*piVar1);
        if (iVar2 != 0) {
          return iVar2;
        }
        rendering_getDispatchState(piVar1);
      }
      psVar3 = (short *)scoreEngine_getFrameSize(*(int *)(param_1 + 8));
      if (psVar3 == (short *)0x0) {
        return 0;
      }
      piVar4 = rendering_getDispatchByChannel(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 8),*psVar3);
      *piVar1 = (int)piVar4;
    } while (piVar4 != (int *)0x0);
    scoreEngine_setChannelData(*(int *)(param_1 + 8),0x7fff);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_seekToFrame (FUN_68086a20)
// Address: 68086a20
// Size: 170 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_seekToFrame(int param_1,int param_2)
{
  int iVar1;
  short *psVar2;
  int *piVar3;
  short sVar4;
  undefined4 local_8;
  
  iVar1 = param_1;
  if (param_1 != 0) {
    sVar4 = (short)param_2;
    if (sVar4 < 1) {
      sVar4 = 1;
    }
    (*(unsigned short *)((char *)&param_1 + 0)) = (undefined2)((uint)param_2 >> 0x10);
    if (param_2 < 0x10000) {
      (*(unsigned short *)((char *)&param_1 + 0)) = 1;
    }
    rendering_getDispatchState((int *)(iVar1 + 0xc));
    scoreEngine_setChannelData(*(int *)(iVar1 + 8),sVar4);
    psVar2 = (short *)scoreEngine_getFrameSize(*(int *)(iVar1 + 8));
    if (psVar2 != (short *)0x0) {
      piVar3 = rendering_getDispatchByChannel(*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 8),*psVar2);
      *(int *)(iVar1 + 0xc) = (int)piVar3;
      if (piVar3 == (int *)0x0) {
        scoreEngine_setChannelData(*(int *)(iVar1 + 8),0x7fff);
        return 0;
      }
      local_8 = CONCAT22((undefined2)param_1,*psVar2);
      rendering_resolveSlotState((int)piVar3,local_8);
    }
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_loadMemberData (FUN_68086ad0)
// Address: 68086ad0
// Size: 501 bytes
// Params: int * param_1, undefined4 * param_2, void * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_loadMemberData(int *param_1,undefined4 *param_2,void *param_3)
{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  undefined2 local_434 [2];
  int local_430 [7];
  int *local_414;
  uint local_410;
  int *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_434[0] = 0;
  local_430[0] = 0;
  local_430[1] = 0;
  local_430[2] = 0;
  local_430[3] = 0;
  local_430[4] = 0;
  local_430[5] = 0;
  local_430[6] = 0;
  local_40c = *(int **)(param_1[1] + 8);
  local_410 = 0;
  local_414 = (int *)0x0;
  if (param_2 == (undefined4 *)0x0) {
LAB_68086b6c:
    piVar4 = local_414;
    local_430[3] = 0x400;
    local_430[1] = 0;
    if (param_2 == (undefined4 *)0x0) {
LAB_68086bda:
      if (piVar4 == (int *)0x0) {
        piVar4 = (int *)rendering_getChannelDataEx((int)local_40c,1,param_2,0);
        if (piVar4 != (int *)0x0) {
          local_434[0] = (undefined2)piVar4[1];
          local_414 = piVar4;
          if (param_2 == (undefined4 *)0x0) {
            iVar2 = rendering_getChannelFormat((int)piVar4);
            if (iVar2 != 0) goto LAB_68086c52;
          }
          else {
            iVar2 = playback_loadMediaData(param_1,piVar4,param_3);
            if (iVar2 == 1) {
LAB_68086c52:
              uVar1 = scoreEngine_getChannelValue((int)param_1,(int)local_434);
              local_410 = (uint)uVar1;
              if (uVar1 != 0) goto LAB_68086cb2;
            }
          }
        }
      }
      else {
        if ((piVar4[0x33] == 0) || (((uint)param_3 & 0x10) == 0)) {
          local_434[0] = (undefined2)piVar4[1];
          goto LAB_68086c52;
        }
        lingo_formatDebugMsg(local_40c,-0x67);
      }
    }
    else {
      uVar3 = Ordinal_1378(param_2,param_2,local_408);
      Ordinal_1379(uVar3);
      iVar2 = Ordinal_1201(local_408,1);
      local_430[0] = Ordinal_1111(iVar2 + 1);
      if (local_430[0] != 0) {
        uVar3 = Ordinal_1114(local_430[0]);
        Ordinal_1202(uVar3,local_408);
        Ordinal_1115(local_430[0]);
        goto LAB_68086bda;
      }
    }
    if (local_414 != (int *)0x0) {
      rendering_setChannelProperty(local_40c,(uint)*(ushort *)(local_414 + 1),0);
    }
  }
  else {
    iVar2 = scoreEngine_writeChannelData((int)param_1,0,param_2,0x16,1,1,1);
    if (iVar2 != 0) {
      local_414 = (int *)rendering_getChannelRect((int)local_40c,param_2);
      goto LAB_68086b6c;
    }
  }
  playback_getFontMapState(local_430 + 4);
  if (local_430[0] != 0) {
    Ordinal_1113(local_430);
  }
LAB_68086cb2:
  return 0;
}



// ============================================================
// Function: scoreEngine_getMaxZOrder (FUN_68086cd0)
// Address: 68086cd0
// Size: 106 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getMaxZOrder(void)

{
  int iVar1;
  int in_EAX;
  int *piVar2;
  short *psVar3;
  int iVar4;
  int iVar5;
  int *local_8;
  
  iVar1 = *(int *)(*(int *)(in_EAX + 4) + 8);
  iVar5 = 0x400;
  piVar2 = scoreEngine_getFrameDataPtr(in_EAX);
  local_8 = piVar2;
  if (piVar2 != (int *)0x0) {
    psVar3 = (short *)scoreEngine_getFrameSize((int)piVar2);
    while (psVar3 != (short *)0x0) {
      iVar4 = rendering_getChannelSprite(iVar1,*psVar3);
      if (((iVar4 != 0) && (*(int *)(iVar4 + 0x14) != 0)) && (iVar5 <= *(int *)(iVar4 + 0x3c))) {
        iVar5 = *(int *)(iVar4 + 0x3c);
      }
      psVar3 = (short *)scoreEngine_getFrameSize((int)piVar2);
    }
  }
  rendering_getDispatchState((int *)&local_8);
  return iVar5 + 0x10000;
}



// ============================================================
// Function: scoreEngine_createThumbnail (FUN_68086d40)
// Address: 68086d40
// Size: 440 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_createThumbnail(int param_1,undefined1 *param_2)
{
  int *piVar1;
  short sVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined2 local_42c [2];
  int local_428 [8];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_428[0] = 0;
  local_428[1] = 0;
  local_428[2] = 0;
  local_428[3] = 0;
  local_428[4] = 0;
  local_428[5] = 0;
  local_428[6] = 0;
  local_428[7] = 0;
  local_42c[0] = 0;
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 8);
  local_428[3] = scoreEngine_getMaxZOrder();
  local_428[1] = 0;
  if (param_2 == (undefined1 *)0x0) {
    uVar3 = Ordinal_1261();
    switch(uVar3) {
    default:
      iVar4 = 0;
      break;
    case 1:
      iVar4 = 300;
      break;
    case 2:
      iVar4 = 400;
      break;
    case 3:
      iVar4 = 500;
      break;
    case 9:
      iVar4 = 600;
    }
    uVar5 = Ordinal_1517(DAT_681956e0,iVar4 + 0x1fe,local_408,0x3ff);
  }
  else {
    uVar5 = Ordinal_1201(param_2);
  }
  if (0x3fd < uVar5) {
    uVar5 = 0x3fe;
  }
  local_428[0] = Ordinal_1111(uVar5 + 1,1);
  if (local_428[0] != 0) {
    uVar3 = Ordinal_1114(local_428[0]);
    if (param_2 == (undefined1 *)0x0) {
      param_2 = local_408;
    }
    Ordinal_1202(uVar3,param_2);
    Ordinal_1115(local_428[0]);
    iVar4 = rendering_getChannelDataEx((int)piVar1,0,(undefined4 *)0x0,param_1);
    if (iVar4 != 0) {
      local_42c[0] = *(undefined2 *)(iVar4 + 4);
      *(int *)(iVar4 + 0x3c) = local_428[3];
      iVar6 = rendering_getChannelFormat(iVar4);
      if (iVar6 == 0) {
        rendering_setChannelProperty(piVar1,(uint)*(ushort *)(iVar4 + 4),0);
      }
      else {
        sVar2 = scoreEngine_getChannelValue(param_1,(int)local_42c);
        if (sVar2 != 0) goto LAB_68086ee2;
        rendering_setChannelProperty(piVar1,(uint)*(ushort *)(iVar4 + 4),0);
      }
    }
  }
  playback_getFontMapState(local_428 + 4);
  if (local_428[0] != 0) {
    Ordinal_1113(local_428);
  }
LAB_68086ee2:
  return 0;
}



// ============================================================
// Function: scoreEngine_resetThumbnails (FUN_68086f20)
// Address: 68086f20
// Size: 441 bytes
// Params: int * param_1, void * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_resetThumbnails(int *param_1,void *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  bool bVar3;
  bool bVar4;
  short sVar5;
  int *piVar6;
  short *psVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  int *local_c;
  int local_8;
  
  piVar1 = *(int **)(param_1[1] + 8);
  local_8 = 0;
  bVar3 = false;
  bVar4 = false;
  piVar6 = scoreEngine_getFrameDataPtr((int)param_1);
  local_c = piVar6;
  if (piVar6 == (int *)0x0) goto LAB_680870c6;
  psVar7 = (short *)scoreEngine_getFrameSize((int)piVar6);
  if (psVar7 != (short *)0x0) {
    do {
      piVar6 = (int *)rendering_getChannelSprite((int)piVar1,*psVar7);
      if ((piVar6[3] == 0) && (local_8 = playback_loadMediaData(param_1,piVar6,param_2), local_8 != 1)) {
        if (local_8 == 2) {
          bVar4 = true;
        }
        else {
          bVar3 = true;
        }
      }
      else {
        iVar8 = rendering_writeChannelBlock(piVar6,param_1,param_2);
        if ((iVar8 == 0) ||
           (((*(int *)(psVar7 + 0xc) == 0 && (piVar6[0x13] != 0)) &&
            (iVar8 = playback_deserializeFontMap(piVar1,(int *)(psVar7 + 10),piVar6[0x13],(int)(param_1 + 0x143)),
            iVar8 == 0)))) goto LAB_680870c6;
      }
      psVar7 = (short *)scoreEngine_getFrameSize((int)local_c);
    } while (psVar7 != (short *)0x0);
    if (bVar3) {
      local_8 = 0;
      goto LAB_680870c6;
    }
    piVar6 = local_c;
    if (bVar4) {
      local_8 = 2;
      goto LAB_680870c6;
    }
  }
  scoreEngine_setChannelData((int)piVar6,1);
  psVar7 = (short *)scoreEngine_getFrameSize((int)piVar6);
  while (psVar7 != (short *)0x0) {
    iVar8 = rendering_getChannelSprite((int)piVar1,*psVar7);
    iVar9 = rendering_getChannelVisibility(*(int *)(iVar8 + 0x60));
    param_2 = (void *)0x0;
    if (0 < iVar9) {
      do {
        sVar5 = rendering_getChannelFlags(*(int *)(iVar8 + 0x60),(int)param_2);
        if ((sVar5 != 0) && (uVar10 = scoreEngine_getChannelRange((int)param_1,sVar5,0), (short)uVar10 < 1)) {
          iVar11 = rendering_getChannelSprite((int)piVar1,sVar5);
          if (iVar11 == 0) goto LAB_680870c6;
          uVar2 = *(undefined4 *)(iVar11 + 0x30);
          puVar12 = (undefined4 *)Ordinal_1114(uVar2);
          sVar5 = scoreEngine_loadMemberData(param_1,puVar12,(void *)0x0);
          Ordinal_1115(uVar2);
          if (sVar5 == 0) goto LAB_680870c6;
        }
        param_2 = (void *)((int)param_2 + 1);
      } while ((int)param_2 < iVar9);
    }
    psVar7 = (short *)scoreEngine_getFrameSize((int)local_c);
  }
  local_8 = 1;
LAB_680870c6:
  rendering_getDispatchState((int *)&local_c);
  return local_8;
}



// ============================================================
// Function: scoreEngine_deleteFrame (FUN_680870e0)
// Address: 680870e0
// Size: 283 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_deleteFrame(int *param_1,int param_2)

{
  int local_c;
  int *piVar1;
  code *pcVar2;
  ushort *puVar3;
  int iVar4;
  short *psVar5;
  undefined4 *puVar6;
  uint uVar7;
  short sVar8;
  /* FIXUP(C2040: 'local_c': 'short): short local_c [4]; */
  
  piVar1 = *(int **)(param_1[1] + 8);
  sVar8 = (short)param_2;
  puVar3 = (ushort *)scoreEngine_getFrameData((int)param_1,sVar8);
  if (puVar3 == (ushort *)0x0) {
    return 0;
  }
  pcVar2 = *(code **)(*(int *)(*piVar1 + 0xc) + 0x108);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(*(undefined4 *)(param_1[1] + 4),*puVar3,param_2);
  }
  playback_resetPaletteState();
  rendering_setChannelProperty(piVar1,(uint)*puVar3,0);
  Ordinal_1158(param_1[0x11c],param_1[0x11d]);
  Ordinal_1160(param_1[0x11c],(int)sVar8);
  if (param_1[0x11c] != 0) {
    iVar4 = Ordinal_1157(param_1[0x11c]);
    param_1[0x11d] = iVar4;
  }
  uVar7 = param_2 + 1U & 0xffff;
  if ((short)(param_2 + 1U) <= (short)param_1[0x11e]) {
    do {
      psVar5 = (short *)scoreEngine_getFrameData((int)param_1,(short)uVar7);
      if (psVar5 != (short *)0x0) {
        psVar5[6] = psVar5[6] + -1;
      }
      puVar6 = (undefined4 *)rendering_getChannelSprite((int)piVar1,*psVar5);
      rendering_initChannelState(puVar6);
      scoreEngine_cleanupMembers(param_1,psVar5);
      uVar7 = uVar7 + 1;
    } while ((short)uVar7 <= (short)param_1[0x11e]);
  }
  param_1[0x116] = 1;
  ((int *)(size_t)local_c)[ /* FIXUP(C2109): cast to pointer for subscript */0] = sVar8;
  rendering_getChannelProperty(*param_1,0x17,(undefined4 *)local_c);
  *(short *)(param_1 + 0x11e) = (short)param_1[0x11e] + -1;
  return 1;
}



// ============================================================
// Function: scoreEngine_loadSoundData (FUN_68087200)
// Address: 68087200
// Size: 927 bytes
// Params: int param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_loadSoundData(int param_1,int param_2,uint param_3)
{
  short sVar1;
  int iVar2;
  short extraout_var;
  int iVar3;
  int local_628;
  int local_624;
  undefined4 local_620;
  undefined4 local_61c;
  undefined4 local_618;
  undefined4 local_614;
  undefined4 local_610;
  undefined4 local_60c;
  undefined4 *local_608;
  undefined4 local_604;
  undefined4 local_600;
  undefined4 local_5fc;
  undefined4 local_5f8;
  undefined4 local_5f4;
  undefined4 local_5f0;
  undefined4 local_5ec;
  int *local_5e8;
  int *local_5e0;
  int *local_5dc;
  uint local_5d8;
  undefined4 local_5d4;
  int local_5d0;
  int local_5cc;
  undefined4 local_5c8;
  undefined4 local_5c4;
  undefined4 *local_5c0;
  undefined4 local_5bc;
  undefined4 local_5b8;
  undefined4 local_5b4;
  undefined4 local_5b0;
  undefined4 local_5ac;
  int local_5a8;
  int *local_5a4;
  undefined4 local_5a0;
  undefined4 local_59c [262];
  undefined1 local_184 [8];
  undefined4 local_17c;
  undefined4 local_178;
  undefined4 local_174;
  undefined4 local_170;
  undefined4 local_16c;
  undefined4 local_168;
  undefined4 local_20 [6];
  uint local_8;
  
  local_5e8 = *(int **)(param_1 + 0x20);
  local_5d8 = param_3;
  iVar3 = 0;
  local_5d4 = 0;
  local_5e0 = (int *)0x0;
  local_5fc = 0;
  local_5f8 = 0;
  local_5f4 = 0;
  local_5f0 = 0;
  local_620 = 0;
  local_61c = 0;
  local_618 = 0;
  local_614 = 0;
  local_610 = 0;
  local_60c = 0;
  local_608 = (undefined4 *)0x0;
  local_5dc = (int *)0x0;
  if ((local_5e8 != (int *)0x0) && (local_5e8[1] != 0)) {
    iVar3 = *local_5e8;
    Ordinal_2330();
    local_5a0 = 0;
    local_5a4 = DAT_68196374;
    DAT_68196374 = &local_5a8;
    local_5a8 = iVar3;
  }
  iVar2 = rendering_dispatchUpdate(*(int *)(iVar3 + 0x20),(int *)param_2,local_59c,1);
  if (iVar2 == 0) {
LAB_6808732b:
    Ordinal_1040(0x67);
    goto LAB_68087334;
  }
  if (*(int *)(param_2 + 0x20) == 0) {
    iVar2 = Ordinal_1402(&local_5d4,local_59c,1);
LAB_68087327:
    if (iVar2 == 0) goto LAB_6808732b;
  }
  else {
    iVar2 = Ordinal_1405(&local_5d4,*(int *)(param_2 + 0x20),1);
    if (iVar2 == 0) {
      Ordinal_1407(&local_5d4);
      iVar2 = Ordinal_1405(&local_5d4,*(undefined4 *)(param_2 + 0x20),1,0);
      goto LAB_68087327;
    }
  }
  iVar2 = scoreEngine_invokeXtraMethod(&local_5fc,(undefined4 *)0x0,*(int **)(iVar3 + 0x20),local_5d8,&DAT_6817c6bc,
                       &local_604,&local_5e0,&local_5dc);
  if (iVar2 == 0) {
LAB_68087448:
    local_600 = Ordinal_1330(local_59c);
    iVar2 = Ordinal_1923(local_184,&local_5d4,local_600,&local_5ec);
    if (iVar2 == 0) goto LAB_68087334;
    local_174 = local_17c;
    local_16c = local_17c;
    local_170 = local_178;
    local_168 = local_178;
    iVar2 = Ordinal_1910(local_5d8,local_184,&local_5d4,local_600,1);
    if (((iVar2 == 0) || (iVar2 = Ordinal_1908(local_5d8,local_5ec,0,iVar3), iVar2 == 0)) ||
       (iVar2 = scoreEngine_resumeSound(*(int **)(iVar3 + 0x20),local_5d8), iVar2 == 0)) goto LAB_68087334;
  }
  else {
    sVar1 = scoreEngine_getChannelCount(*(int *)(iVar3 + 0x20),(short)*(undefined4 *)(param_2 + 4));
    local_628 = (int)sVar1;
    local_624 = (int)extraout_var;
    iVar2 = (**(code **)(*local_5e0 + 0x10))(local_5e0,&local_628,&local_5f4);
    if (iVar2 != 0) goto LAB_68087448;
    local_608 = &local_5fc;
    local_618 = local_604;
    local_60c = 2;
    iVar2 = (**(code **)(*local_5dc + 0x38))(local_5dc,&local_620);
    if (iVar2 != 0) goto LAB_68087448;
  }
  if ((local_5d8 == 0) || (local_5d8 == 1)) {
    local_5c0 = local_20;
    local_5bc = 0;
    local_5b8 = 0;
    local_5b4 = 0;
    local_5b0 = 0;
    local_5ac = 0;
    local_5d0 = param_2;
    local_5c8 = 0x19;
    local_5c4 = 0x2f;
    local_5cc = iVar3;
    iVar2 = rendering_initState(&local_5d0);
    if (iVar2 != 0) {
      *(undefined4 *)(iVar3 + 0x80 + local_5d8 * 4) = local_20[0];
    }
  }
LAB_68087334:
  scoreEngine_getCastXtraData((int)&local_5fc,(int *)0x0,(int *)&local_5e0,(int *)&local_5dc);
  Ordinal_1407(&local_5d4);
  if (local_5e8 != (int *)0x0) {
    DAT_68196374 = local_5a4;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_saveSoundData (FUN_680875a0)
// Address: 680875a0
// Size: 1063 bytes
// Params: int * param_1, undefined4 param_2, int * param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_saveSoundData(int *param_1,undefined4 param_2,int *param_3,uint param_4)
{
  short sVar1;
  int iVar2;
  short extraout_var;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar6;
  int *piVar7;
  int local_214;
  int local_210;
  undefined4 local_20c;
  undefined4 local_208;
  undefined4 local_204;
  undefined4 local_200;
  undefined4 local_1fc;
  undefined4 local_1f8;
  undefined4 *local_1f4;
  undefined4 local_1f0;
  undefined4 local_1ec;
  undefined4 local_1e8;
  undefined4 local_1e4;
  undefined4 local_1e0;
  uint local_1dc;
  int *local_1d8;
  int local_1d4;
  int *local_1d0;
  undefined4 local_1cc;
  undefined4 local_1c8;
  int *local_1c4;
  undefined4 local_1c0;
  int local_1bc;
  int *local_1b8;
  int local_1b4;
  undefined4 local_1b0;
  undefined4 local_1ac;
  undefined4 *local_1a8;
  undefined4 local_1a4;
  undefined4 local_1a0;
  undefined4 local_19c;
  undefined4 local_198;
  undefined4 local_194;
  int local_190;
  int *local_18c;
  undefined4 local_188;
  int local_184 [4];
  int local_174;
  undefined4 local_170;
  int local_16c;
  undefined4 local_168;
  int local_164;
  undefined4 local_160;
  undefined4 local_20 [6];
  uint local_8;
  
  local_1d8 = param_1;
  local_1dc = param_4;
  local_1d0 = (int *)0x0;
  local_1f0 = 0;
  local_1ec = 0;
  local_1e8 = 0;
  local_1e4 = 0;
  local_1c0 = 0;
  local_1d4 = 0;
  local_1cc = rendering_getMediaState((int)param_3);
  local_20c = 0;
  local_208 = 0;
  local_204 = 0;
  local_200 = 0;
  local_1fc = 0;
  local_1f8 = 0;
  local_1f4 = (undefined4 *)0x0;
  local_1c4 = (int *)0x0;
  local_1bc = 0;
  if ((param_1 != (int *)0x0) && (param_1[1] != 0)) {
    local_1bc = *param_1;
    Ordinal_2330();
    local_190 = local_1bc;
    local_188 = 0;
    local_18c = DAT_68196374;
    DAT_68196374 = &local_190;
  }
  iVar2 = scoreEngine_invokeXtraMethod(&local_1f0,(undefined4 *)0x0,param_1,param_4,&DAT_6817c6bc,&local_1e0,
                       &local_1d0,&local_1c4);
  if (iVar2 == 0) {
LAB_68087727:
    local_1d4 = rendering_getMemberData(*param_1,param_3);
    if (local_1d4 == 0) goto LAB_6808796a;
    iVar2 = param_3[0x15];
    if (iVar2 != 0) {
      if (param_3[0x18] == 0) {
        if (param_3[0x17] == 0) {
          iVar2 = Ordinal_1922(local_184,iVar2,local_1cc,&local_1c8);
          uVar6 = extraout_ECX_01;
          if (iVar2 == 0) goto LAB_6808796a;
        }
        else {
          iVar2 = Ordinal_1922(local_184,iVar2,local_1cc,0);
          if (iVar2 == 0) goto LAB_6808796a;
          local_1c8 = Ordinal_1120(param_3[0x17],0);
          uVar6 = extraout_ECX_00;
        }
      }
      else {
        piVar3 = (int *)Ordinal_1114(param_3[0x18]);
        iVar2 = param_3[0x18];
        piVar7 = local_184;
        for (iVar5 = 0x59; iVar5 != 0; iVar5 = iVar5 + -1) {
          *piVar7 = *piVar3;
          piVar3 = piVar3 + 1;
          piVar7 = piVar7 + 1;
        }
        Ordinal_1115(iVar2);
        local_1c8 = Ordinal_1120(param_3[0x17],0);
        uVar6 = extraout_ECX;
        param_1 = local_1d8;
        param_4 = local_1dc;
      }
      scoreEngine_checkVersionFlag(uVar6,(int)param_1,(int)param_3);
      uVar4 = rendering_getRawStateFlags((int)param_3);
      if ((uVar4 & 0x10) == 0) {
        if (local_16c <= local_174) {
          local_174 = local_184[2];
          local_16c = local_164;
          local_170 = local_184[3];
          local_168 = local_160;
        }
        if ((param_4 == 0) || (param_4 == 1)) {
          *(undefined4 *)(local_1bc + 0x88 + param_4 * 4) = 1;
        }
      }
      else {
        local_174 = local_184[2];
        local_16c = local_184[2];
        local_170 = local_184[3];
        local_168 = local_184[3];
      }
      iVar2 = Ordinal_1909(param_4,local_184,param_3[0x15],local_1cc,0);
      if (iVar2 == 0) goto LAB_6808796a;
      iVar2 = Ordinal_1908(param_4,local_1c8,0,local_1bc);
      if (iVar2 == 0) goto LAB_6808796a;
      iVar2 = scoreEngine_resumeSound(param_1,param_4);
      if (iVar2 == 0) goto LAB_6808796a;
    }
  }
  else {
    sVar1 = scoreEngine_getChannelCount((int)param_1,(short)param_3[1]);
    local_214 = (int)sVar1;
    local_210 = (int)extraout_var;
    iVar2 = (**(code **)(*local_1d0 + 0x10))(local_1d0,&local_214,&local_1e8);
    if (iVar2 != 0) goto LAB_68087727;
    local_1f4 = &local_1f0;
    local_204 = local_1e0;
    local_1f8 = 2;
    iVar2 = (**(code **)(*local_1c4 + 0x38))(local_1c4,&local_20c);
    if (iVar2 != 0) goto LAB_68087727;
  }
  if ((param_4 == 0) || (param_4 == 1)) {
    local_1a4 = 0;
    local_1a0 = 0;
    local_19c = 0;
    local_198 = 0;
    local_194 = 0;
    local_1a8 = local_20;
    local_1b8 = param_3;
    local_1b0 = 0x19;
    local_1b4 = local_1bc;
    local_1ac = 0x2f;
    iVar2 = rendering_initState((int *)&local_1b8);
    if (iVar2 != 0) {
      *(undefined4 *)(local_1bc + 0x80 + param_4 * 4) = local_20[0];
    }
  }
  local_1c0 = 1;
LAB_6808796a:
  scoreEngine_getCastXtraData((int)&local_1f0,(int *)0x0,(int *)&local_1d0,(int *)&local_1c4);
  if (local_1d4 != 0) {
    rendering_isStateValid((int)param_3);
  }
  if (param_1 != (int *)0x0) {
    DAT_68196374 = local_18c;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_playSoundChannel (FUN_680879d0)
// Address: 680879d0
// Size: 439 bytes
// Params: int * param_1, uint param_2, int param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_playSoundChannel(int *param_1,uint param_2,int param_3,undefined4 param_4)

{
  short sVar1;
  int *piVar2;
  short sVar3;
  int *piVar4;
  int iVar5;
  
  piVar2 = *(int **)(param_1[1] + 8);
  sVar3 = (short)((uint)param_4 >> 0x10);
  if (param_2 == 0) {
    if ((short)param_4 == *(short *)(param_3 + 0x70)) {
      sVar1 = *(short *)(param_3 + 0x72);
      goto joined_r0x68087a29;
    }
  }
  else if ((param_2 == 1) && ((short)param_4 == *(short *)(param_3 + 0x74))) {
    sVar1 = *(short *)(param_3 + 0x76);
joined_r0x68087a29:
    if (sVar3 == sVar1) {
      return 1;
    }
  }
  switch(sVar3) {
  case 0:
    if (*(int *)(param_3 + 0x80 + param_2 * 4) == 0) goto LAB_68087a49;
    scoreEngine_breakSoundLoop(param_1,param_2);
    break;
  case -4:
    goto switchD_68087a40_caseD_fffc;
  case -3:
    scoreEngine_resumeSound(param_1,param_2);
    return 1;
  case -2:
    scoreEngine_pauseSound(param_1,param_2);
    return 1;
  case -1:
LAB_68087a49:
    scoreEngine_loadCastXtra(param_1,param_2);
    break;
  default:
    piVar4 = (int *)rendering_resolveState((int)piVar2,param_4);
    if ((piVar4 != (int *)0x0) && (piVar4[2] == 6)) {
      iVar5 = rendering_getFrameCount((int)piVar4);
      if (iVar5 == 0) {
        scoreEngine_saveSoundData(param_1,param_3,piVar4,param_2);
      }
      else {
        scoreEngine_loadSoundData(param_3,(int)piVar4,param_2);
      }
      rendering_releaseMemberData(piVar4);
      if ((param_2 == 0) || (param_2 == 1)) {
        param_1[param_2 + 0x181] = param_3;
      }
      iVar5 = Ordinal_1042();
      if (iVar5 != 0) {
        if ((iVar5 == 0x6e) || (iVar5 == 0x70)) {
          iVar5 = rendering_getFrameCount((int)piVar4);
          if (iVar5 != 0) {
            rendering_writeStateData((int)piVar4,(undefined *)0x0);
            lingo_formatDebugMsg(piVar2,-0x1b0);
            return 0;
          }
          rendering_writeStateData((int)piVar4,(undefined *)0x0);
          lingo_formatDebugMsg(piVar2,-0x1af);
        }
        return 0;
      }
    }
  }
  if (param_2 == 0) {
    *(undefined4 *)(param_3 + 0x70) = param_4;
  }
  else if (param_2 == 1) {
    *(undefined4 *)(param_3 + 0x74) = param_4;
    return 1;
  }
switchD_68087a40_caseD_fffc:
  return 1;
}



// ============================================================
// Function: scoreEngine_stopSoundChannel (FUN_68087ba0)
// Address: 68087ba0
// Size: 202 bytes
// Params: uint param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_stopSoundChannel(uint param_1,int param_2)

{
  uint uVar1;
  bool bVar2;
  uint uVar3;
  int iVar4;
  undefined3 extraout_var;
  short *psVar5;
  int iVar6;
  
  uVar1 = param_1;
  if ((*(int *)(param_1 + 0x480) != 0) &&
     (uVar3 = Ordinal_1154(*(int *)(param_1 + 0x480)), uVar3 != 0)) {
    iVar4 = Ordinal_1157(*(undefined4 *)(param_1 + 0x480));
    param_1 = 0;
    if (uVar3 != 0) {
      while (bVar2 = scoreEngine_isScoreActive(), CONCAT31(extraout_var,bVar2) == 0) {
        psVar5 = (short *)Ordinal_1156(*(undefined4 *)(uVar1 + 0x480),iVar4,param_1);
        iVar6 = scoreEngine_setChannelField(uVar1,*(undefined4 *)psVar5);
        if (((((iVar6 != 0) && (iVar6 = scoreEngine_getFrameData(uVar1,*psVar5), iVar6 != 0)) &&
             (param_2 <= *(int *)(iVar6 + 8))) && (iVar6 = scoreEngine_readAndWriteMedia(0), iVar6 == 0)) ||
           (param_1 = param_1 + 1, uVar3 <= param_1)) break;
      }
    }
    if (iVar4 != 0) {
      Ordinal_1158(*(undefined4 *)(uVar1 + 0x480),iVar4);
    }
  }
  return 1;
}



// ============================================================
// Function: scoreEngine_setSoundVolume (FUN_68087c70)
// Address: 68087c70
// Size: 83 bytes
// Params: uint param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_setSoundVolume(uint param_1,uint param_2)

{
  int iVar1;
  
  if ((0x7fffffff < param_2) && ((short)param_2 != 0)) {
    return 1;
  }
  iVar1 = scoreEngine_setScoreField(param_1,param_2);
  if (iVar1 != 0) {
    iVar1 = scoreEngine_setChannelField(param_1,param_2);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 8) == 4)) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getScoreIterator (FUN_68087cd0)
// Address: 68087cd0
// Size: 99 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * scoreEngine_getScoreIterator(int param_1)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *local_8;
  
  iVar1 = Ordinal_1111(0x10,0);
  if (iVar1 == 0) {
    return (int *)0x0;
  }
  piVar2 = (int *)Ordinal_1114(iVar1);
  *piVar2 = iVar1;
  piVar2[1] = param_1;
  local_8 = piVar2;
  piVar3 = scoreEngine_getFrameDataPtr(param_1);
  piVar2[2] = (int)piVar3;
  if (piVar3 != (int *)0x0) {
    piVar2[3] = 0;
    return piVar2;
  }
  scoreEngine_resetScore((int *)&local_8);
  return (int *)0x0;
}



// ============================================================
// Function: scoreEngine_advanceIterator (FUN_68087d40)
// Address: 68087d40
// Size: 60 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_advanceIterator(void)
{
  int in_EAX;
  int *piVar1;
  int iVar2;
  int *local_8;
  
  piVar1 = scoreEngine_getScoreIterator(in_EAX);
  local_8 = piVar1;
  iVar2 = scoreEngine_getScoreState((int)piVar1);
  while (iVar2 != 0) {
    *(uint *)(iVar2 + 0x30) = *(uint *)(iVar2 + 0x30) & 0xfffffff7;
    iVar2 = scoreEngine_getScoreState((int)piVar1);
  }
  scoreEngine_resetScore((int *)&local_8);
  return 0;
}



// ============================================================
// Function: scoreEngine_resetIterator (FUN_68087d80)
// Address: 68087d80
// Size: 21 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_resetIterator(void)
{
  int in_EAX;
  
  *(int *)(in_EAX + 0x648) = *(int *)(in_EAX + 0x648) + 1;
  if (*(int *)(in_EAX + 0x648) == 1) {
    scoreEngine_advanceIterator();
    return 0;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_freeIterator (FUN_68087da0)
// Address: 68087da0
// Size: 14 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_freeIterator(void)
{
  int *piVar1;
  int in_EAX;
  
  piVar1 = (int *)(in_EAX + 0x648);
  *piVar1 = *piVar1 + -1;
  if (*piVar1 == 0) {
    scoreEngine_advanceIterator();
    return 0;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_applyScoreEdit (FUN_68087db0)
// Address: 68087db0
// Size: 607 bytes
// Params: undefined4 * param_1, int * param_2, int param_3, int param_4, int param_5, undefined * param_6, undefined4 param_7
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_applyScoreEdit(undefined4 *param_1,int *param_2,int param_3,int param_4,int param_5,
                undefined *param_6,undefined4 param_7)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined2 uVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  undefined3 extraout_var;
  uint uVar9;
  int local_14;
  int local_10;
  int local_8;
  
  puVar1 = param_1;
  local_10 = 0;
  local_14 = 0;
  local_8 = 0;
  scoreEngine_resetIterator();
  param_1[0x2e8] = param_1[0x2e8] + 1;
  if ((int)param_1[0x2e8] < 0x14) {
    if (param_4 < 1) {
      param_4 = 1;
    }
    if ((param_4 <= param_5) && (local_10 = media_cloneScoreState((int)param_2), local_10 != 0)) {
      media_getPlaybackPosition((int)param_2);
      iVar5 = media_readPlaybackData((int)param_2,param_4,0);
      if (iVar5 != 0) {
        iVar5 = media_lockScoreData(param_2,&local_8,(undefined4 *)0x0);
        if (local_8 == 0) goto LAB_68087fe8;
        while( true ) {
          iVar6 = local_8;
          uVar3 = xtra_readBE16((undefined1 *)(local_8 + 0xf0));
          uVar4 = xtra_readBE16((undefined1 *)(iVar6 + 0xf2));
          param_1 = (undefined4 *)CONCAT22(uVar4,uVar3);
          iVar6 = scoreEngine_setScoreField((int)puVar1,param_1);
          if (((iVar6 != 0) && (iVar6 = scoreEngine_setChannelField((uint)puVar1,param_1), iVar6 != 0)) &&
             (iVar6 = (*(code *)param_6)(puVar1,iVar6,param_7), iVar6 == 0)) break;
          iVar6 = local_8;
          uVar3 = xtra_readBE16((undefined1 *)(local_8 + 0x60));
          uVar4 = xtra_readBE16((undefined1 *)(iVar6 + 0x62));
          param_1 = (undefined4 *)CONCAT22(uVar4,uVar3);
          iVar6 = rendering_getStageFlags((uint)param_1);
          if (((iVar6 == 0) && (iVar6 = scoreEngine_setScoreField((int)puVar1,param_1), iVar6 != 0)) &&
             ((iVar6 = scoreEngine_setChannelField((uint)puVar1,param_1), iVar6 != 0 &&
              (iVar6 = (*(code *)param_6)(puVar1,iVar6,param_7), iVar6 == 0)))) break;
          iVar6 = local_8;
          uVar3 = xtra_readBE16((undefined1 *)(local_8 + 0xc0));
          uVar4 = xtra_readBE16((undefined1 *)(iVar6 + 0xc2));
          param_1 = (undefined4 *)CONCAT22(uVar4,uVar3);
          iVar6 = scoreEngine_setScoreField((int)puVar1,param_1);
          if (((iVar6 != 0) && (iVar6 = scoreEngine_setChannelField((uint)puVar1,param_1), iVar6 != 0)) &&
             (iVar6 = (*(code *)param_6)(puVar1,iVar6,param_7), iVar6 == 0)) break;
          iVar6 = local_8;
          uVar3 = xtra_readBE16((undefined1 *)(local_8 + 0x90));
          uVar4 = xtra_readBE16((undefined1 *)(iVar6 + 0x92));
          param_1 = (undefined4 *)CONCAT22(uVar4,uVar3);
          iVar6 = scoreEngine_setScoreField((int)puVar1,param_1);
          if (((iVar6 != 0) && (iVar6 = scoreEngine_setChannelField((uint)puVar1,param_1), iVar6 != 0)) &&
             (iVar6 = (*(code *)param_6)(puVar1,iVar6,param_7), iVar6 == 0)) break;
          if (0 < iVar5) {
            iVar6 = 0x120;
            uVar9 = 6;
            do {
              if (uVar9 < 0x3ee) {
                pbVar7 = (byte *)(iVar6 + local_8);
              }
              else {
                pbVar7 = (byte *)0x0;
              }
              if ((*pbVar7 != 0) &&
                 (iVar8 = scoreEngine_iterateSprites(param_7,puVar1,pbVar7,param_3,param_6), iVar8 == 0))
              goto LAB_68087fd3;
              iVar8 = uVar9 - 5;
              iVar6 = iVar6 + 0x30;
              uVar9 = uVar9 + 1;
            } while (iVar8 < iVar5);
          }
          local_14 = param_4;
          param_4 = param_4 + 1;
          bVar2 = media_isPlaybackActive((int)param_2,0);
          if ((CONCAT31(extraout_var,bVar2) == 0) || (param_5 < param_4)) break;
        }
      }
    }
  }
LAB_68087fd3:
  if (local_8 != 0) {
    media_unlockScoreData(param_2,&local_8,(undefined4 *)0x0);
  }
LAB_68087fe8:
  if (local_10 != 0) {
    media_copyScoreState((int)param_2,local_10);
  }
  puVar1[0x2e8] = puVar1[0x2e8] + -1;
  scoreEngine_freeIterator();
  return local_14;
}



// ============================================================
// Function: scoreEngine_initScoreData (FUN_68088010)
// Address: 68088010
// Size: 50 bytes
// Params: undefined4 * param_1, int * param_2, int param_3, int param_4, int param_5, undefined * param_6, undefined4 param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_initScoreData(undefined4 *param_1,int *param_2,int param_3,int param_4,int param_5,
                 undefined *param_6,undefined4 param_7)
{
  param_1[0x2e8] = 0;
  scoreEngine_applyScoreEdit(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  return 0;
}



// ============================================================
// Function: scoreEngine_commitScoreEdit (FUN_68088050)
// Address: 68088050
// Size: 88 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_commitScoreEdit(int *param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = param_1;
  piVar2 = (int *)media_getScoreReadRef(*(int **)(*param_1 + 0x28),(undefined4 *)0x0);
  iVar3 = scoreEngine_setSoundVolume((uint)param_1,piVar2);
  if (iVar3 == 0) {
    piVar2 = (int *)scoreEngine_getChannelState((int)param_1);
    iVar3 = scoreEngine_setSoundVolume((uint)param_1,piVar2);
    if (iVar3 == 0) {
      strings_getDefaultCastType();
      param_1 = (int *)0xffff;
      piVar2 = param_1;
    }
  }
  scoreEngine_getChannelData((int)piVar1,(short)piVar2);
  return 0;
}



// ============================================================
// Function: scoreEngine_insertScoreFrame (FUN_680880b0)
// Address: 680880b0
// Size: 168 bytes
// Params: int param_1, undefined4 param_2, short param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_insertScoreFrame(int param_1,undefined4 param_2,short param_3,int param_4)
{
  bool bVar1;
  short sVar2;
  int *piVar3;
  undefined2 extraout_var_00;
  int iVar4;
  undefined3 extraout_var;
  int iVar5;
  int *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  piVar3 = scoreEngine_getScoreIterator(param_1);
  local_10 = piVar3;
  if (piVar3 != (int *)0x0) {
    scoreEngine_seekToFrame((int)piVar3,param_2);
    sVar2 = scoreEngine_getChannelData(param_1,param_3);
    local_c = CONCAT22(extraout_var_00,sVar2);
    iVar4 = scoreEngine_getScoreState((int)piVar3);
    if (iVar4 != 0) {
      while ((bVar1 = scoreEngine_isScoreActive(), CONCAT31(extraout_var,bVar1) == 0 &&
             (iVar5 = scoreEngine_readAndWriteMedia(param_4), iVar5 != 0))) {
        local_8 = *(undefined4 *)(iVar4 + 4);
        if ((((short)local_c == (short)local_8) && ((*(unsigned short *)((char *)&local_c + 2)) == *(short *)(iVar4 + 6))) ||
           (iVar4 = scoreEngine_getScoreState((int)local_10), iVar4 == 0)) break;
      }
    }
  }
  scoreEngine_resetScore((int *)&local_10);
  scoreEngine_getChannelCount(param_1,(short)local_8);
  return 0;
}



// ============================================================
// Function: scoreEngine_appendScoreFrame (FUN_68088160)
// Address: 68088160
// Size: 148 bytes
// Params: undefined4 * param_1, undefined4 param_2, short param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_appendScoreFrame(undefined4 *param_1,undefined4 param_2,short param_3,int param_4)
{
  short sVar1;
  int *piVar2;
  short extraout_var;
  int *piVar3;
  int *local_8;
  
  piVar2 = scoreEngine_getScoreIterator((int)param_1);
  local_8 = piVar2;
  if (piVar2 != (int *)0x0) {
    scoreEngine_seekToFrame((int)piVar2,param_2);
    sVar1 = scoreEngine_getChannelData((int)param_1,param_3);
    piVar3 = (int *)scoreEngine_getScoreState((int)piVar2);
    while (piVar3 != (int *)0x0) {
      if ((param_4 == 0) || (piVar3[0x12] != 0)) {
        rendering_getMediaFormat((byte *)*param_1,piVar3);
      }
      else {
        rendering_readMediaBlock((byte *)*param_1,piVar3,0);
      }
      if ((sVar1 == (short)piVar3[1]) && (extraout_var == *(short *)((int)piVar3 + 6))) break;
      piVar3 = (int *)scoreEngine_getScoreState((int)piVar2);
    }
  }
  scoreEngine_resetScore((int *)&local_8);
  return 0;
}



// ============================================================
// Function: scoreEngine_duplicateFrames (FUN_68088200)
// Address: 68088200
// Size: 41 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_duplicateFrames(int *param_1,int param_2,int param_3)
{
  scoreEngine_initScoreData(param_1,*(int **)(*param_1 + 0x28),0,param_2,param_3,scoreEngine_processMediaBlock,&stack0x00000010);
  return 0;
}



// ============================================================
// Function: scoreEngine_deleteFrames (FUN_68088230)
// Address: 68088230
// Size: 39 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_deleteFrames(int *param_1,int param_2,int param_3)
{
  scoreEngine_initScoreData(param_1,*(int **)(*param_1 + 0x28),0,param_2,param_3,scoreEngine_getMediaFormat,0);
  return 0;
}



// ============================================================
// Function: scoreEngine_pasteFrames (FUN_68088260)
// Address: 68088260
// Size: 54 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_pasteFrames(int *param_1,int param_2,int param_3)

{
  undefined4 local_8;
  
  local_8 = 0;
  scoreEngine_initScoreData(param_1,*(int **)(*param_1 + 0x28),0,param_2,param_3,scoreEngine_updateStateProperty,&local_8);
  return local_8;
}



// ============================================================
// Function: scoreEngine_editFrameRange (FUN_680882a0)
// Address: 680882a0
// Size: 142 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 param_4, undefined4 param_5, int * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_editFrameRange(int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                 int *param_6)
{
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  if (param_6 != (int *)0x0) {
    *param_6 = 0;
  }
  local_18 = param_4;
  local_14 = param_5;
  local_10 = 1;
  local_c = 0;
  scoreEngine_initScoreData(param_1,*(int **)(*param_1 + 0x28),1,param_2,param_3,scoreEngine_readChannelWithBlend,&local_18);
  if ((local_c != 0) && (param_6 != (int *)0x0)) {
    *param_6 = local_c;
    return 0;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getScoreContext (FUN_68088330)
// Address: 68088330
// Size: 30 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getScoreContext(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((*(int **)(param_1 + 0x4c) != (int *)0x0) &&
     (iVar1 = *(int *)(**(int **)(param_1 + 0x4c) + 4), iVar1 < 0)) {
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: Ordinal_213
// Address: 68088350
// Size: 136 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_213(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x88350  213   */
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
  rendering_resolveDispatchFlags(param_2);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setScoreContext (FUN_680883e0)
// Address: 680883e0
// Size: 136 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setScoreContext(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
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
  rendering_getDispatchFlags(param_2);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



