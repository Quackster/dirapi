// Module: bitmap
// Topic: Movie/stage management, screen updates, window events, invalidation, text member helpers
// Address range: 0x680e7560 - 0x680e9750
// Functions (36):
//   bitmap_initCastData
//   bitmap_destroyCastData
//   bitmap_releaseStageResources
//   bitmap_createStageDisplay
//   bitmap_openMovieStage
//   bitmap_closeMovieStage
//   bitmap_computeSpriteOffset
//   bitmap_resolveSpriteAtPos
//   bitmap_dispatchSpriteChange
//   bitmap_handleKeyNav
//   bitmap_dispatchStageEvent
//   bitmap_invalidateClipRegion
//   bitmap_renderSprite
//   bitmap_renderDirtySprites
//   bitmap_updateStageRegion
//   bitmap_setInvalidRect
//   bitmap_markStageDirty
//   bitmap_updateMovieStage
//   bitmap_flushStageBuffer
//   bitmap_processStageUpdates
//   bitmap_handleStageScroll
//   bitmap_getMovieStageData
//   bitmap_getTextStyleData
//   bitmap_getTextLineHeight
//   bitmap_getTextAlignment
//   bitmap_setTextStyle
//   bitmap_resolveTextFont
//   bitmap_getTextRunFormat
//   bitmap_computeTextHeight
//   bitmap_getMovieStageRef
//   bitmap_copyTextToClipboard
//   bitmap_readTextProps
//   bitmap_writeTextProps
//   bitmap_readFontMapEntry
//   bitmap_writeFontMapEntry
//   bitmap_returnOutOfMemory

// ============================================================
// Function: bitmap_initCastData (FUN_680e7560)
// Address: 680e7560
// Size: 151 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_initCastData(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = strings_allocMediaDescriptor();
  param_1[0xd4] = iVar1;
  if ((iVar1 != 0) && (iVar1 = crt_allocFormatList(param_1), iVar1 == 0)) {
    param_1[0xdb] = scoreEngine_compareCastSlot;
    param_1[0xdc] = scoreEngine_compareMemberName;
    param_1[0xdd] = scoreEngine_compareFrameKey;
    iVar1 = Ordinal_1150(1,1,4);
    param_1[0xc6] = iVar1;
    if (iVar1 != 0) {
      Ordinal_1151(iVar1,0,&local_8);
      uVar2 = Ordinal_1154(param_1[0xc6]);
      param_1[199] = uVar2;
      iVar1 = Ordinal_1150(0,0,4);
      param_1[200] = iVar1;
      if (iVar1 != 0) {
        return 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_destroyCastData (FUN_680e7600)
// Address: 680e7600
// Size: 147 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_destroyCastData(undefined4 *param_1)
{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = param_1;
  if (param_1[0xd3] != 0) {
    Ordinal_1163(param_1 + 0xd3);
  }
  iVar2 = Ordinal_1154(puVar1[200]);
  while (iVar2 = iVar2 + -1, -1 < iVar2) {
    Ordinal_1155(puVar1[200],iVar2,&param_1);
    score_dispose((int)param_1);
  }
  Ordinal_1163(puVar1 + 0xc6);
  puVar1[0xdb] = 0;
  puVar1[0xdc] = 0;
  puVar1[0xdd] = 0;
  playback_initScoreDataStream((int)puVar1);
  Ordinal_1163(puVar1 + 200);
  crt_freeFormatList(puVar1);
  strings_freeMediaDescriptor(puVar1 + 0xd4);
  return 0;
}



// ============================================================
// Function: bitmap_releaseStageResources (FUN_680e76a0)
// Address: 680e76a0
// Size: 88 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_releaseStageResources(void)
{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x14) != 0) {
    Ordinal_1601(unaff_ESI + 0x14);
  }
  if (*(int *)(unaff_ESI + 0x18) != 0) {
    Ordinal_1601(unaff_ESI + 0x18);
  }
  if (*(int *)(unaff_ESI + 0x1c) != 0) {
    Ordinal_1601(unaff_ESI + 0x1c);
  }
  if (*(int *)(unaff_ESI + 0x114) != 0) {
    Ordinal_1733(unaff_ESI + 0x114);
  }
  if (*(int *)(unaff_ESI + 0x118) != 0) {
    Ordinal_1742(unaff_ESI + 0x118);
  }
  return 0;
}



// ============================================================
// Function: bitmap_createStageDisplay (FUN_680e7700)
// Address: 680e7700
// Size: 247 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_createStageDisplay(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  
  bitmap_releaseStageResources();
  iVar1 = Ordinal_1730(0x100);
  *(int *)(in_EAX + 0x114) = iVar1;
  if (iVar1 != 0) {
    iVar1 = Ordinal_1740(0,0);
    *(int *)(in_EAX + 0x118) = iVar1;
    if (iVar1 != 0) {
      uVar2 = Ordinal_1600();
      *(undefined4 *)(in_EAX + 0x14) = uVar2;
      uVar2 = Ordinal_1600();
      *(undefined4 *)(in_EAX + 0x18) = uVar2;
      iVar1 = Ordinal_1600();
      *(int *)(in_EAX + 0x1c) = iVar1;
      if (((*(int *)(in_EAX + 0x14) != 0) && (*(int *)(in_EAX + 0x18) != 0)) && (iVar1 != 0)) {
        iVar1 = Ordinal_1609(*(int *)(in_EAX + 0x14),*(undefined4 *)(in_EAX + 0x114));
        if (iVar1 != 0) {
          iVar1 = Ordinal_1609(*(undefined4 *)(in_EAX + 0x18),*(undefined4 *)(in_EAX + 0x114));
          if (iVar1 != 0) {
            iVar1 = Ordinal_1609(*(undefined4 *)(in_EAX + 0x1c),*(undefined4 *)(in_EAX + 0x114));
            if (iVar1 != 0) {
              iVar1 = Ordinal_1611(*(undefined4 *)(in_EAX + 0x14),*(undefined4 *)(in_EAX + 0x118));
              if (iVar1 != 0) {
                iVar1 = Ordinal_1611(*(undefined4 *)(in_EAX + 0x18),*(undefined4 *)(in_EAX + 0x118))
                ;
                if (iVar1 != 0) {
                  iVar1 = Ordinal_1611(*(undefined4 *)(in_EAX + 0x1c),
                                       *(undefined4 *)(in_EAX + 0x118));
                  if (iVar1 != 0) {
                    return 1;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  lingo_formatDebugMsg(*(int **)(in_EAX + 8),-0x7a);
  bitmap_releaseStageResources();
  return 0;
}



// ============================================================
// Function: bitmap_openMovieStage (FUN_680e7800)
// Address: 680e7800
// Size: 145 bytes
// Params: int param_1, int param_2, uint param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_openMovieStage(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = *(int **)(param_1 + 0x20);
  piVar1[0x196] = param_3 & 1;
  *(short *)(param_1 + 0xc) = (short)param_3;
  *(undefined4 *)(param_1 + 0x10) = 1;
  lingo_flushState(*(int *)(param_1 + 8));
  lingo_updateState(*(int *)(param_1 + 8));
  iVar2 = bitmap_createStageDisplay();
  iVar3 = 0;
  if (iVar2 != 0) {
    iVar2 = rendering_createSprite(param_1,(int *)(param_1 + 0x24),param_2);
    iVar3 = 0;
    if (iVar2 != 0) {
      iVar3 = scoreEngine_initScoreChannel(param_1,piVar1,1);
      if (iVar3 != 0) {
        if (*(int *)(param_1 + 0x120) == 0) {
          uVar4 = Ordinal_1150(0x40,8,0x104);
          *(undefined4 *)(param_1 + 0x120) = uVar4;
        }
        *(undefined4 *)(param_1 + 0x124) = 0;
      }
    }
  }
  return iVar3;
}



// ============================================================
// Function: bitmap_closeMovieStage (FUN_680e78a0)
// Address: 680e78a0
// Size: 125 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_closeMovieStage(int param_1)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x20);
  lingo_removeScriptRef(*(undefined4 **)(param_1 + 8),param_1);
  if (*(int *)(param_1 + 8) != 0) {
    if (*(int **)(param_1 + 0x20) == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = **(int **)(param_1 + 0x20);
    }
    media_clearXtraSlot(*(int *)(param_1 + 8),iVar2);
  }
  if (piVar1 != (int *)0x0) {
    stage_releaseCastObjects(piVar1[2]);
    scoreEngine_updateScore(piVar1,0);
  }
  rendering_getStageState(param_1 + 0x24);
  bitmap_releaseStageResources();
  if (*(int *)(param_1 + 0x11c) != 0) {
    Ordinal_1163(param_1 + 0x11c);
  }
  if (*(int *)(param_1 + 0x120) != 0) {
    Ordinal_1163(param_1 + 0x11c);
  }
  return 0;
}



// ============================================================
// Function: bitmap_computeSpriteOffset (FUN_680e7920)
// Address: 680e7920
// Size: 20 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_computeSpriteOffset(int param_1)

{
  uint in_EAX;
  
  if (in_EAX < 0x3e9) {
    return in_EAX * 400 + *(int *)(param_1 + 0x34);
  }
  return 0;
}



// ============================================================
// Function: bitmap_resolveSpriteAtPos (FUN_680e7940)
// Address: 680e7940
// Size: 143 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_resolveSpriteAtPos(int param_1)

{
  int iVar1;
  undefined4 *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  int extraout_ECX;
  int iVar5;
  int *unaff_EBX;
  undefined4 *unaff_EDI;
  int local_8;
  
  local_8 = 0;
  if (unaff_EDI != (undefined4 *)0x0) {
    *unaff_EDI = 0;
  }
  if (unaff_EBX != (int *)0x0) {
    *unaff_EBX = 0;
  }
  if ((param_1 != 0) && ((*(byte *)*in_EAX & 8) != 0)) {
    iVar2 = playback_blendSpriteLayer((int)*in_EAX,param_1,&local_8);
    if (-1 < iVar2) {
      puVar3 = (undefined4 *)bitmap_computeSpriteOffset(local_8);
      iVar5 = extraout_ECX;
      if (unaff_EDI != (undefined4 *)0x0) {
        uVar4 = playback_getSpriteData(extraout_ECX,puVar3);
        *unaff_EDI = uVar4;
        iVar5 = local_8;
      }
      if (unaff_EBX != (int *)0x0) {
        *unaff_EBX = iVar5;
      }
      iVar1 = *(int *)(iVar5 + 0x20);
      if (((*(int *)(iVar1 + 0x644) == iVar2) && (*(int *)(iVar1 + 0x640) == iVar5)) &&
         (*(int *)(iVar1 + 0x63c) != 0)) {
        *(undefined4 *)(iVar1 + 0x638) = 1;
      }
      return iVar2;
    }
  }
  return -1;
}



// ============================================================
// Function: bitmap_dispatchSpriteChange (FUN_680e79d0)
// Address: 680e79d0
// Size: 214 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_dispatchSpriteChange(int param_1,int param_2,int param_3)
{
  uint uVar1;
  int iVar2;
  undefined4 unaff_EBX;
  byte *unaff_ESI;
  int local_30;
  
  if ((param_3 == 0) || (*(int *)(param_3 + 0x60) != 10)) {
    local_30 = param_2;
    rendering_initState(&local_30);
  }
  else {
    iVar2 = 0;
    switch(unaff_EBX) {
    case 0:
      bitmap_setSpriteProperty(unaff_ESI,param_3,(param_1 != 1) + 0x1d);
      break;
    case 1:
      iVar2 = (param_1 != 1) + 0x1f;
    default:
      bitmap_setSpriteProperty(unaff_ESI,param_3,iVar2);
      break;
    case 2:
      bitmap_setSpriteProperty(unaff_ESI,param_3,0x1b - (uint)(param_1 != 1));
      break;
    case 5:
      bitmap_setSpriteProperty(unaff_ESI,param_3,0x1c);
    }
  }
  playback_applyFrameFlags(unaff_ESI,0x1000);
  return 0;
}



// ============================================================
// Function: bitmap_handleKeyNav (FUN_680e7ac0)
// Address: 680e7ac0
// Size: 178 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x680e7af4) */
/* WARNING: Removing unreachable block (ram,0x680e7afa) */

undefined4 bitmap_handleKeyNav(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = bitmap_resolveSpriteAtPos(*(int *)(param_2 + 0x20));
  if (iVar1 != -1) {
    switch(*(undefined4 *)(param_2 + 0x18)) {
    case 1:
      iVar1 = 0;
      break;
    case 2:
      iVar1 = 1;
      break;
    case 3:
      iVar1 = 1;
      break;
    case 4:
      iVar1 = 0;
      break;
    case 5:
      iVar1 = 1;
      break;
    case 6:
      iVar1 = 0;
      break;
    case 7:
      iVar1 = 0;
      break;
    default:
      goto switchD_680e7b13_default;
    }
    bitmap_dispatchSpriteChange(iVar1,0,0);
  }
switchD_680e7b13_default:
  return 1;
}



// ============================================================
// Function: bitmap_dispatchStageEvent (FUN_680e7b90)
// Address: 680e7b90
// Size: 991 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_dispatchStageEvent(int *param_1,int *param_2,undefined4 *param_3)
{
  int local_18;
  int *piVar1;
  undefined4 *puVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  undefined1 *puVar9;
  undefined4 uVar10;
  undefined4 local_40;
  int local_3c [5];
  undefined1 local_28 [32];
  uint local_8;
  
  iVar8 = param_1[1];
  local_3c[0] = *(int *)(iVar8 + 0x28);
  local_40 = 0;
  piVar1 = *(int **)(iVar8 + 8);
  iVar4 = piVar1[1];
  puVar2 = *(undefined4 **)(*piVar1 + 0x14);
  if (*param_2 == 9) {
    piVar1[0xe2] = 1;
  }
  if (((*param_2 != 0x1b) && (*param_2 != 0x1d)) && (local_3c[0] != param_2[1]))
  goto switchD_680e7c10_caseD_3;
  switch(*param_2) {
  case 2:
    iVar7 = core_returnTrue();
    if (iVar7 != 0) {
      iVar7 = media_getDataOffset(iVar4);
      if (iVar7 == 0) {
        *(undefined4 *)(iVar8 + 0x110) = 1;
      }
      else {
        media_getDataSize(iVar4,0);
        Ordinal_1764(0);
        Ordinal_1130(local_3c + 2,0xc);
        local_3c[2] = 1;
        local_3c[3] = 1;
        Ordinal_1763(local_3c + 2,0);
        local_40 = 0;
        *(undefined4 *)(iVar8 + 0x110) = 1;
      }
    }
    break;
  case 10:
    iVar7 = core_returnTrue();
    if (iVar7 != 0) {
      iVar7 = media_getDataOffset(iVar4);
      if (iVar7 == 0) {
        *(undefined4 *)(iVar8 + 0x110) = 1;
      }
      else {
        media_getDataSize(iVar4,0);
        Ordinal_1764(0);
        Ordinal_1130(local_3c + 2,0xc);
        local_3c[2] = 1;
        local_3c[3] = 1;
        Ordinal_1763(local_3c + 2,0);
        *(undefined4 *)(iVar8 + 0x110) = 1;
      }
    }
    break;
  case 0xc:
  case 0xe:
  case 0x1f:
  case 0x20:
  case 0x21:
  case 0x24:
  case 0x25:
    goto switchD_680e7c10_caseD_c;
  case 0xd:
    if ((*(int *)(iVar8 + 4) == 0) ||
       (Ordinal_54(*(int *)(*(int *)(*(int *)(*(int *)(iVar8 + 4) + 8) + 0x18) + 0xc),local_3c),
       *(int *)(iVar8 + 0x28) != local_3c[0])) goto switchD_680e7c10_caseD_c;
    iVar4 = 0;
    if ((*(int *)(*(int *)(iVar8 + 4) + 0x24) == 0) &&
       (iVar7 = *(int *)(*(int *)(iVar8 + 4) + 0xc), iVar7 != 0)) {
      iVar4 = Ordinal_118(iVar7);
      iVar4 = stage_getSpriteConstraint(iVar4);
    }
    if ((*(int *)(*(int *)(iVar8 + 4) + 0x20) == 0) && (iVar4 == 0)) goto switchD_680e7c10_caseD_c;
    goto LAB_680e7e87;
  case 0xf:
  case 0x10:
  case 0x11:
    uVar6 = stage_findSpriteRef(puVar2,*(int *)(iVar8 + 0x28));
    local_3c[3] = param_2[6];
    local_3c[4] = param_2[7];
    uVar10 = 0x20;
    local_3c[0] = 0;
    local_3c[1] = 0;
    local_3c[2] = 0;
    puVar9 = local_28;
    uVar5 = 1;
    iVar4 = scoreEngine_getScoreLibraryId((int)param_1);
    iVar7 = media_applyPixelOp(iVar4,uVar5,puVar9,uVar10);
    iVar4 = local_3c[0];
    if (iVar7 == 0) {
      sVar3 = Ordinal_1206("Author",local_28);
      if (sVar3 == 0) {
        iVar4 = 1;
      }
      else {
        sVar3 = Ordinal_1206("Plugin",local_28);
        iVar4 = local_3c[0];
        if (sVar3 == 0) goto switchD_680e7c10_caseD_c;
      }
    }
    if (((uVar6 & 2) != 0) || ((*param_2 == 0x10 && (((uVar6 & 4) == 0 || (iVar4 == 0)))))) {
      Ordinal_50(*(int *)(*(int *)(iVar8 + 4) + 0xc),local_3c + 1,0);
    }
    if (*param_2 == 0xf) {
      Ordinal_104(*(int *)(*(int *)(iVar8 + 4) + 0xc),0x3000);
      Ordinal_1820(*(undefined4 *)(iVar8 + 0x28),0);
    }
switchD_680e7c10_caseD_c:
    Ordinal_945((int *)param_1[2],*param_2);
LAB_680e7e87:
    local_40 = 1;
    break;
  case 0x13:
    local_3c[0] = 0;
    iVar8 = stage_findSpriteState(puVar2,*(int *)(iVar8 + 0x28));
    uVar10 = 0x20;
    puVar9 = local_28;
    uVar5 = 1;
    iVar4 = scoreEngine_getScoreLibraryId((int)param_1);
    iVar4 = media_applyPixelOp(iVar4,uVar5,puVar9,uVar10);
    if (iVar4 == 0) {
      sVar3 = Ordinal_1206("Plugin",local_28);
      iVar4 = 1;
      if (sVar3 != 0) goto LAB_680e7f27;
    }
    else {
LAB_680e7f27:
      iVar4 = local_3c[0];
    }
    if (iVar8 != 2) {
      Ordinal_168(param_1[2],(uint)(param_2[6] != 0),iVar4);
    }
  case 0x1c:
switchD_680e7c10_caseD_1c:
    local_40 = 1;
    break;
  case 0x15:
    local_40 = bitmap_handleKeyNav(param_1,(int)param_2);
    break;
  case 0x16:
    playback_getLifecycleInfo((byte *)*param_1);
    break;
  case 0x1b:
    if (param_1[0x111] != 0) {
      if (*(int *)(iVar8 + 0x28) == param_2[1]) {
        rendering_getChannelProperty(*param_1,0x20,(undefined4 *)0x0);
      }
      else {
        playback_refreshStageDisplay((int *)*param_1);
      }
    }
    break;
  case 0x1d:
    iVar4 = Ordinal_2032(*(undefined4 *)(iVar8 + 0x28),local_3c);
    if ((iVar4 == param_2[6]) || (local_3c[0] != 0)) {
      playback_setLifecycleState(*param_1,1);
      playback_setLifecycleState(*param_1,0);
      rendering_updateStageDisplay(iVar8 + 0x24);
      rendering_setStageSize((int *)*param_1,iVar8 + 0x24);
    }
    iVar4 = *(int *)(*(int *)(iVar8 + 4) + 0xc);
    uVar5 = Ordinal_70(iVar4);
    *(undefined2 *)(iVar8 + 0x54) = 0;
    *(undefined2 *)(iVar8 + 0x58) = 0;
    Ordinal_71(iVar4,uVar5);
    goto switchD_680e7c10_caseD_1c;
  }
switchD_680e7c10_caseD_3:
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = local_40;
  }
  return 0;
}



// ============================================================
// Function: bitmap_invalidateClipRegion (FUN_680e7fd0)
// Address: 680e7fd0
// Size: 76 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_invalidateClipRegion(undefined4 param_1)
{
  int iVar1;
  int unaff_ESI;
  undefined4 local_1c;
  undefined1 local_18 [16];
  uint local_8;
  
  iVar1 = Ordinal_1066(local_18,param_1,unaff_ESI + 0x10);
  if (iVar1 != 0) {
    local_1c = *(undefined4 *)(unaff_ESI + 0x44);
    Ordinal_1619(*(undefined4 *)(unaff_ESI + 4),local_18,&local_1c);
  }
  return 0;
}



// ============================================================
// Function: bitmap_renderSprite (FUN_680e8020)
// Address: 680e8020
// Size: 2138 bytes
// Params: uint param_1, void * param_2, undefined4 * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_renderSprite(uint param_1,void *param_2,undefined4 *param_3,undefined4 param_4)
{
  void *pvVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  float10 fVar9;
  undefined4 local_264;
  undefined4 local_260;
  undefined4 local_25c;
  int local_258;
  undefined4 *local_254;
  int *local_250;
  uint local_24c;
  undefined4 *local_248;
  int local_244;
  void *local_240;
  int local_23c;
  int local_238;
  int local_234;
  uint local_230;
  void *local_22c;
  undefined4 local_228 [3];
  undefined2 local_21c;
  uint local_1dc;
  byte local_1d8;
  int local_1c8;
  int local_160;
  int local_15c;
  undefined4 local_158;
  undefined4 local_154;
  undefined1 local_150 [64];
  int local_110;
  undefined4 local_fc;
  uint local_dc;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int *local_a8;
  int local_a4;
  uint local_a0;
  undefined1 local_98 [16];
  int local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  undefined4 local_6c;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  float local_30;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  float local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_25c = param_4;
  puVar6 = param_3;
  puVar3 = local_228;
  for (iVar5 = 100; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar3 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar3 = puVar3 + 1;
  }
  local_230 = param_1;
  local_240 = param_2;
  local_248 = param_3;
  local_22c = param_2;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_6c = 0;
  local_68 = 0;
  local_64 = 0;
  local_60 = 0;
  local_234 = 0;
  local_264 = 0;
  local_260 = 0;
  local_238 = 0;
  if ((local_1c8 == 0) || ((local_1d8 & 2) != 0)) goto LAB_680e8836;
  if ((local_1dc & 0x100) == 0) {
    playback_updateSpriteChannelData(param_1,param_2,(int)param_3);
    goto LAB_680e8836;
  }
  iVar5 = Ordinal_1606(param_2);
  if (iVar5 == 0) goto LAB_680e8836;
  local_18 = local_b8;
  local_14 = local_b4;
  if (((local_a0 == 0) || (iVar5 = playback_getSpriteInfo(local_230,local_228), iVar5 == 0)) ||
     (local_48 != 0x20)) {
    local_238 = 1;
    iVar5 = local_23c;
LAB_680e8365:
    uVar4 = local_230;
    switch(local_1c8) {
    case 1:
      display_blitSpriteToCanvas(local_230,local_22c,local_228);
      if ((local_1d8 & 1) != 0) {
        display_renderSpriteToCanvas(uVar4,local_22c,local_228);
      }
      break;
    case 2:
      bitmap_renderSpriteInk(local_230,local_22c,local_228);
      if ((local_1d8 & 1) != 0) {
        bitmap_renderSpriteOverlay(local_230,local_22c,local_228);
      }
      break;
    case 3:
      bitmap_dispatchDraw(local_230,(int)local_22c,local_228);
      if ((local_1d8 & 1) != 0) {
        bitmap_drawSpriteOverlay(local_230,local_22c,local_228,local_234);
      }
      break;
    case 4:
    case 5:
      puVar6 = (undefined4 *)(local_dc + 0x3c);
      local_24c = local_dc;
      local_254 = puVar6;
      if (*(int **)(local_dc + 0x3c) != (int *)0x0) {
        iVar8 = *(int *)(**(int **)(local_dc + 0x3c) + 8);
        iVar2 = 0;
        local_258 = iVar8;
        if (0 < iVar8) {
          local_250 = (int *)(local_dc + 0x30);
          do {
            iVar5 = *(int *)(*(int *)(*(int *)(*(undefined4 **)*puVar6)[9] + iVar2 * 4) + 4 +
                            *(int *)**(undefined4 **)*puVar6);
            iVar7 = 1;
            if ((*(char *)(iVar5 + *local_250) != '\0') &&
               (puVar3 = (undefined4 *)(iVar5 * 400 + *(int *)(local_24c + 0x34)),
               (*(byte *)(puVar3 + 0x14) & 2) == 0)) {
              Ordinal_1602();
              if ((*(int *)(local_24c + 0x158) < *(int *)(local_24c + 0x160)) &&
                 (*(int *)(local_24c + 0x15c) < *(int *)(local_24c + 0x164))) {
                iVar7 = Ordinal_1608();
              }
              if (((*(byte *)(puVar3 + 0x13) & 1) != 0) && (iVar7 != 0)) {
                bitmap_renderSprite(local_24c,local_22c,puVar3,local_25c);
              }
              Ordinal_1603(local_22c);
              puVar6 = local_254;
              iVar8 = local_258;
            }
            iVar2 = iVar2 + 1;
            iVar5 = local_23c;
          } while (iVar2 < iVar8);
        }
      }
      break;
    case 6:
      if ((local_1dc & 8) == 0) {
        display_renderVideoFrame(local_230,local_22c,local_228);
      }
      else {
LAB_680e8630:
        rendering_addDirtySprite(*(int *)(local_230 + 0x24),(int)local_248);
      }
      break;
    case 8:
      display_renderShapeSprite(local_230,local_22c,local_228);
      if ((local_1d8 & 1) != 0) {
        display_applyRenderTransform(local_230,local_22c,(int)local_228);
      }
      break;
    case 9:
      display_renderFlashSprite(local_230,local_22c,local_228);
      if ((local_1d8 & 1) != 0) {
        display_applyRenderTransform(local_230,local_22c,(int)local_228);
      }
      break;
    case 10:
      if ((local_1dc & 8) != 0) goto LAB_680e8630;
      bitmap_drawSpriteXtra(local_230,local_22c,local_228,1);
    }
    param_2 = local_240;
    if (local_234 == 0) goto LAB_680e8836;
  }
  else {
    local_fc = 0;
    if (local_1c8 != 10) {
      local_21c = 0;
      local_244 = -local_14;
      local_23c = -local_b8;
      Ordinal_1064();
      if (local_110 == 0) {
        Ordinal_1083(local_150,(double)local_23c,(double)local_244);
      }
    }
    iVar8 = local_ac - local_14;
    iVar5 = local_b0 - local_b8;
    param_2 = local_240;
    local_244 = iVar8;
    local_23c = iVar5;
    if ((iVar5 < 1) || (iVar8 < 1)) goto LAB_680e8836;
    local_22c = (void *)Ordinal_1600();
    if (local_a4 == 0) goto LAB_680e8241;
    iVar2 = Ordinal_1656(local_a4);
    param_2 = local_240;
    if (iVar2 == 0) goto LAB_680e8836;
    if ((iVar5 == local_84) && (iVar8 == local_88)) {
      if (local_a4 == 0) goto LAB_680e8241;
    }
    else {
      Ordinal_1653();
      local_a4 = 0;
LAB_680e8241:
      if (local_48 == 0x20) {
        local_44 = 8;
      }
      local_a4 = Ordinal_1650(local_48,local_44,local_40,iVar5,iVar8);
      param_2 = local_240;
      if (local_a4 == 0) goto LAB_680e8836;
      local_248[0x61] = local_a4;
      local_238 = 1;
    }
    if ((local_1dc & 0x2000) != 0) {
      local_1dc = local_1dc & 0xffffdfff;
      local_238 = 1;
    }
    Ordinal_1604(local_22c);
    pvVar1 = local_240;
    if (local_238 != 0) {
      iVar8 = Ordinal_1610();
      iVar2 = Ordinal_1612(pvVar1);
      param_2 = local_240;
      if ((((iVar8 == 0) || (iVar8 = Ordinal_1609(local_22c), param_2 = local_240, iVar8 == 0)) ||
          (iVar2 == 0)) || (iVar8 = Ordinal_1611(local_22c), param_2 = local_240, iVar8 == 0))
      goto LAB_680e8836;
      Ordinal_1060(local_98,0,0,iVar5);
      Ordinal_1665(local_a4,1);
      Ordinal_1684(local_a4,0);
    }
    local_234 = 1;
    if (local_238 != 0) goto LAB_680e8365;
  }
  uVar4 = local_230;
  iVar2 = playback_getSpriteData(local_230,local_228);
  uVar4 = rendering_updateChannelState(*(int *)(uVar4 + 0x20) + 0x48c);
  iVar8 = local_a4;
  if ((uVar4 < 0x700) || (local_234 = 1, (*(byte *)(iVar2 + 0x9c) & 1) == 0)) {
    local_234 = 0;
  }
  if (local_238 != 0) {
    cast_retainObject(0,local_a8);
    Ordinal_1064();
    if (local_1c8 == 10) {
      Ordinal_1064();
    }
    fVar9 = rendering_renderStageFrame(local_230);
    local_30 = (float)fVar9;
    uVar4 = 0;
    local_2c = local_15c;
    local_28 = local_160;
    local_24 = local_154;
    local_20 = local_158;
    local_18 = local_15c;
    local_14 = local_160;
    local_10 = local_154;
    local_c = local_158;
    local_1c = local_30;
    if (local_a0 != 0) {
      do {
        iVar5 = cast_findXtraPropertyRef(0,local_a8,uVar4);
        if (((iVar5 != 0) && (*(int *)(iVar5 + 4) != 0)) && (*(int **)(iVar5 + 8) != (int *)0x0)) {
          iVar2 = media_callXtraWithInstance(*(int **)(iVar5 + 8),iVar8,&local_30);
          param_2 = local_240;
          if (iVar2 != 0) goto LAB_680e8836;
          iVar5 = media_invokeXtraMethod(*(int **)(iVar5 + 8),&local_30,&local_1c);
          if (iVar5 == 0) {
            local_2c = local_18;
            local_28 = local_14;
            local_24 = local_10;
            local_20 = local_c;
          }
        }
        uVar4 = uVar4 + 1;
      } while (uVar4 < local_a0);
    }
    cast_releaseObject(0,local_a8);
    iVar5 = local_23c;
  }
  Ordinal_1060(local_98,0,0,iVar5,local_244);
  Ordinal_1616(local_240,local_248 + 0x5c,local_22c,local_98,0,&local_264,local_248 + 0x4b,0,
               local_234);
  param_2 = local_240;
LAB_680e8836:
  if ((local_22c != (void *)0x0) && (local_22c != param_2)) {
    Ordinal_1604(local_22c,0);
    Ordinal_1601();
  }
  return 0;
}



// ============================================================
// Function: bitmap_renderDirtySprites (FUN_680e88b0)
// Address: 680e88b0
// Size: 406 bytes
// Params: uint param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_renderDirtySprites(uint param_1,int param_2,int param_3,int *param_4)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  bool bVar6;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_18 = *param_4;
  local_14 = param_4[1];
  local_10 = param_4[2];
  local_c = param_4[3];
  iVar5 = 0;
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x158) < *(int *)(param_1 + 0x160)) &&
       (*(int *)(param_1 + 0x15c) < *(int *)(param_1 + 0x164))) {
      Ordinal_1066(&local_18,&local_18,param_1 + 0x158);
    }
    if ((local_18 < local_10) && (local_14 < local_c)) {
      iVar2 = Ordinal_1602(*(undefined4 *)(param_3 + 4));
      iVar3 = Ordinal_1608(*(undefined4 *)(param_3 + 4),&local_18);
      if ((iVar3 != 0) && (*(int **)(param_1 + 0x3c) != (int *)0x0)) {
        bVar6 = param_2 == 0;
        iVar3 = *(int *)(**(int **)(param_1 + 0x3c) + 8);
        if (0 < iVar3) {
          do {
            iVar1 = *(int *)(*(int *)(*(int *)((undefined4 *)**(int **)(param_1 + 0x3c))[9] +
                                     iVar5 * 4) + 4 + **(int **)**(int **)(param_1 + 0x3c));
            if (bVar6) {
LAB_680e89a7:
              if ((*(char *)(iVar1 + *(int *)(param_1 + 0x30)) != '\0') &&
                 (puVar4 = (undefined4 *)(iVar1 * 400 + *(int *)(param_1 + 0x34)),
                 (*(byte *)(puVar4 + 0x14) & 2) == 0)) {
                if (puVar4[0x18] - 4 < 2) {
                  bitmap_renderDirtySprites(puVar4[0x53],0,param_3,&local_18);
                }
                else if ((((local_18 < (int)puVar4[0x5e]) && ((int)puVar4[0x5c] < local_10)) &&
                         (local_14 < (int)puVar4[0x5f])) && ((int)puVar4[0x5d] < local_c)) {
                  bitmap_renderSprite(param_1,*(void **)(param_3 + 4),puVar4,&local_18);
                }
              }
            }
            else if (iVar1 == param_2) {
              bVar6 = true;
              goto LAB_680e89a7;
            }
            iVar5 = iVar5 + 1;
          } while (iVar5 < iVar3);
        }
      }
      if (iVar2 != 0) {
        Ordinal_1603(*(undefined4 *)(param_3 + 4));
      }
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_updateStageRegion (FUN_680e8a50)
// Address: 680e8a50
// Size: 382 bytes
// Params: void * this, undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_updateStageRegion(void *this,undefined4 param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint unaff_EBX;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = Ordinal_1066(&local_28,param_1,(int)this + 0x10);
  if (iVar1 != 0) {
    iVar1 = Ordinal_1602(*(undefined4 *)((int)this + 4));
    iVar2 = Ordinal_1608(*(undefined4 *)((int)this + 4),&local_28);
    if (iVar2 != 0) {
      iVar2 = iVar1;
      if (*(int **)(unaff_EBX + 0x3c) == (int *)0x0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(**(int **)(unaff_EBX + 0x3c) + 8);
      }
      while (iVar3 = iVar3 + -1, -2 < iVar3) {
        if ((iVar3 < 0) ||
           (iVar2 = *(int *)(*(int *)(*(int *)((undefined4 *)**(int **)(unaff_EBX + 0x3c))[9] +
                                     iVar3 * 4) + 4 + **(int **)**(int **)(unaff_EBX + 0x3c)),
           iVar2 < 0)) goto LAB_680e8aca;
        if (((*(char *)(iVar2 + *(int *)(unaff_EBX + 0x30)) != '\0') &&
            (((iVar4 = iVar2 * 400 + *(int *)(unaff_EBX + 0x34), (*(byte *)(iVar4 + 0x50) & 2) == 0
              && ((*(uint *)(iVar4 + 0x5c) & 1) != 0)) && ((*(uint *)(iVar4 + 0x5c) & 0x40) == 0))))
           && (((*(uint *)(iVar4 + 0x4c) & 0x100) != 0 &&
               (iVar4 = Ordinal_1069(iVar4 + 200,param_1), iVar4 != 0)))) break;
      }
      if (iVar2 < 0) {
LAB_680e8aca:
        local_18 = local_28;
        local_14 = local_24;
        local_10 = local_20;
        local_c = local_1c;
        if (param_2 == 0) {
        }
        else {
          (**(code **)(*(int *)(*(int *)(*(int *)(**(int **)this + 4) + 8) + 0xc) + 0xec))
                    (*(int *)(**(int **)this + 4),*(undefined4 *)((int)this + 4),&local_28,&local_18
                    );
        }
        bitmap_invalidateClipRegion(&local_18);
        iVar2 = 0;
      }
      bitmap_renderDirtySprites(unaff_EBX,iVar2,(int)this,&local_28);
    }
    if (iVar1 != 0) {
      Ordinal_1603(*(undefined4 *)((int)this + 4));
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_setInvalidRect (FUN_680e8bd0)
// Address: 680e8bd0
// Size: 45 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_setInvalidRect(int param_1,undefined4 param_2)
{
  undefined4 local_8;
  
  local_8 = 0x1ffffff;
  Ordinal_1619(*(undefined4 *)(param_1 + 4),param_1 + 0x10,&local_8);
  *(undefined4 *)(param_1 + 0x30) = param_2;
  return 0;
}



// ============================================================
// Function: bitmap_markStageDirty (FUN_680e8c00)
// Address: 680e8c00
// Size: 21 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_markStageDirty(int param_1)
{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x28) = 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_updateMovieStage (FUN_680e8c20)
// Address: 680e8c20
// Size: 378 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_updateMovieStage(int param_1,int *param_2,int param_3)
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  int *local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_20 = *(int **)(param_1 + 0x38);
  uVar9 = *(uint *)(param_1 + 0x40);
  if ((param_2[2] <= *param_2) || (param_2[3] <= param_2[1])) goto LAB_680e8d88;
  if (*(uint *)(param_1 + 0x3c) <= uVar9) {
    uVar1 = Ordinal_1115(*(undefined4 *)(param_1 + 0x34));
    *(int *)(param_1 + 0x3c) = *(int *)(param_1 + 0x3c) + 100;
    *(undefined4 *)(param_1 + 0x38) = uVar1;
    iVar2 = Ordinal_1117((undefined4 *)(param_1 + 0x34),*(int *)(param_1 + 0x3c) << 4,0);
    if (iVar2 == 0) goto LAB_680e8d88;
    local_20 = (int *)Ordinal_1114(*(undefined4 *)(param_1 + 0x34));
    *(int **)(param_1 + 0x38) = local_20;
  }
  iVar2 = Ordinal_1066(&local_18,param_2,param_1 + 0x10);
  if (iVar2 == 0) goto LAB_680e8d88;
  iVar2 = local_14 - param_3;
  iVar5 = local_10 + param_3;
  iVar4 = local_18 - param_3;
  iVar6 = local_c + param_3;
  uVar3 = 0xffff;
  local_1c = 0xffff;
  if ((*(int *)(param_1 + 0x48) == 0) && (uVar7 = 0, piVar8 = local_20, uVar9 != 0)) {
    do {
      if ((*piVar8 < iVar5) && (((iVar4 < piVar8[2] && (piVar8[1] < iVar6)) && (iVar2 < piVar8[3])))
         ) {
        if (uVar3 == 0xffff) {
          Ordinal_1067(piVar8,piVar8,&local_18);
          uVar3 = uVar7;
          local_1c = uVar7;
        }
        else {
          Ordinal_1067(local_20 + uVar3 * 4,local_20 + uVar3 * 4,piVar8);
          Ordinal_1129(piVar8,piVar8 + 4,((uVar9 - uVar7) + -1) * 0x10);
          uVar9 = uVar9 - 1;
          uVar3 = local_1c;
        }
      }
      uVar7 = uVar7 + 1;
      piVar8 = piVar8 + 4;
    } while (uVar7 < uVar9);
    if (uVar3 == 0xffff) goto LAB_680e8d5e;
  }
  else {
LAB_680e8d5e:
    local_20 = local_20 + uVar9 * 4;
    uVar9 = uVar9 + 1;
    *local_20 = local_18;
    local_20[1] = local_14;
    local_20[2] = local_10;
    local_20[3] = local_c;
  }
  *(uint *)(param_1 + 0x40) = uVar9;
  bitmap_markStageDirty(param_1);
LAB_680e8d88:
  return 0;
}



// ============================================================
// Function: bitmap_flushStageBuffer (FUN_680e8da0)
// Address: 680e8da0
// Size: 74 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_flushStageBuffer(void)
{
  int iVar1;
  undefined4 *unaff_ESI;
  
  iVar1 = Ordinal_1602(unaff_ESI[1]);
  if (iVar1 != 0) {
    iVar1 = Ordinal_1608(unaff_ESI[1]);
    if (iVar1 != 0) {
      (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)*unaff_ESI + 4) + 8) + 0xc) + 0xe8))
                (*(int *)(*(int *)*unaff_ESI + 4),unaff_ESI[1]);
    }
    Ordinal_1603(unaff_ESI[1]);
  }
  return 0;
}



// ============================================================
// Function: bitmap_processStageUpdates (FUN_680e8df0)
// Address: 680e8df0
// Size: 392 bytes
// Params: uint param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_processStageUpdates(uint param_1,undefined4 *param_2)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *this;
  undefined4 *puVar5;
  int iVar6;
  bool bVar7;
  undefined4 local_8;
  
  this = param_2;
  uVar4 = param_1;
  local_8 = 0;
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  iVar6 = *(int *)(*(int *)*param_2 + 4);
  pcVar1 = *(code **)(*(int *)(*(int *)(iVar6 + 8) + 0xc) + 0xe4);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(iVar6);
  }
  if (param_2[10] == 0) {
    return 0;
  }
  param_2[0x12] = param_2[0x12] + 1;
  iVar6 = *(int *)(*(int *)(iVar6 + 8) + 0xc);
  bVar7 = *(int *)(iVar6 + 0xe8) != 0;
  iVar6 = *(int *)(iVar6 + 0xec);
  if (0 < (int)param_2[0x10]) {
    param_1 = 0;
    if (0 < (int)param_2[0x10]) {
      param_2 = (undefined4 *)0x0;
      do {
        bitmap_updateStageRegion(this,this[0xe] + (int)param_2,(uint)(iVar6 != 0));
        if (bVar7) {
          bitmap_flushStageBuffer();
        }
        param_2 = param_2 + 4;
        param_1 = param_1 + 1;
      } while ((int)param_1 < (int)this[0x10]);
    }
    local_8 = 1;
  }
  if (*(int **)(uVar4 + 0x3c) != (int *)0x0) {
    iVar6 = *(int *)(**(int **)(uVar4 + 0x3c) + 8);
    param_2 = (undefined4 *)0x0;
    if (0 < iVar6) {
      do {
        iVar2 = *(int *)(*(int *)(*(int *)((undefined4 *)**(int **)(uVar4 + 0x3c))[9] +
                                 (int)param_2 * 4) + 4 + **(int **)**(int **)(uVar4 + 0x3c));
        if (*(char *)(iVar2 + *(int *)(uVar4 + 0x30)) != '\0') {
          puVar5 = (undefined4 *)(iVar2 * 400 + *(int *)(uVar4 + 0x34));
          uVar3 = puVar5[0x13];
          if ((((uVar3 & 1) != 0) && ((uVar3 & 4) != 0)) && ((uVar3 & 2) != 0)) {
            bitmap_renderSprite(uVar4,(void *)this[1],puVar5,0);
            playback_updateSpriteFrame((int)puVar5,0);
            local_8 = 1;
          }
        }
        param_2 = (undefined4 *)((int)param_2 + 1);
      } while ((int)param_2 < iVar6);
    }
  }
  iVar6 = 0;
  if ((bVar7) && (0 < (int)this[0x10])) {
    do {
      bitmap_flushStageBuffer();
      iVar6 = iVar6 + 1;
    } while (iVar6 < (int)this[0x10]);
  }
  this[0x12] = this[0x12] + -1;
  this[10] = 0;
  this[0xc] = 0;
  this[0xb] = 1;
  return local_8;
}



// ============================================================
// Function: bitmap_handleStageScroll (FUN_680e8f80)
// Address: 680e8f80
// Size: 91 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_handleStageScroll(int *param_1,int *param_2,int *param_3)
{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  if ((param_2 != (int *)0x0) && ((int *)*param_2 != (int *)0x0)) {
    param_2[0x11] = *param_3;
    bVar1 = lingo_isScriptReady(*(int *)*param_2);
    if ((CONCAT31(extraout_var,bVar1) != 0) && ((param_1 != (int *)0x0 && (*param_1 != 0)))) {
      iVar2 = playback_getLifecycleData(*param_1);
      if (iVar2 != 0) {
        Ordinal_1842(param_2 + 1,param_2 + 0x11);
      }
    }
    bitmap_updateMovieStage((int)param_2,param_2 + 4,0);
  }
  return 0;
}



// ============================================================
// Function: bitmap_getMovieStageData (FUN_680e8fe0)
// Address: 680e8fe0
// Size: 90 bytes
// Params: undefined4 param_1, undefined4 * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_getMovieStageData(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *unaff_EBX;
  int *unaff_ESI;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((unaff_ESI[2] == 3) || (unaff_ESI[2] == 7)) {
    iVar1 = rendering_getMemberData(param_1,unaff_ESI);
    if (iVar1 != 0) {
      if (unaff_ESI[0x15] != 0) {
        if (unaff_EBX != (undefined4 *)0x0) {
          xtra_appendToBuffer(unaff_ESI[0x15],unaff_EBX,param_3);
        }
        if (param_2 != (undefined4 *)0x0) {
          xtra_readBufferValue(unaff_ESI[0x15],param_2);
        }
        uVar2 = 1;
      }
      rendering_isStateValid((int)unaff_ESI);
    }
  }
  return uVar2;
}



// ============================================================
// Function: bitmap_getTextStyleData (FUN_680e9040)
// Address: 680e9040
// Size: 66 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_getTextStyleData(void *this,undefined4 param_1)
{
  uint uVar1;
  
  bitmap_getMovieStageData(param_1,(undefined4 *)0x0,(int)this);
  return 0;
}



// ============================================================
// Function: bitmap_getTextLineHeight (FUN_680e9090)
// Address: 680e9090
// Size: 88 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_getTextLineHeight(int param_1)

{
  int iVar1;
  int iVar2;
  undefined2 extraout_var;
  undefined2 uVar3;
  undefined2 uVar4;
  int unaff_ESI;
  int *unaff_EDI;
  
  uVar4 = 0;
  iVar1 = lingo_isValidObject(*(int *)(*(int *)(unaff_ESI + 0x20) + 4));
  iVar2 = rendering_getMemberData(unaff_ESI,unaff_EDI);
  uVar3 = 0;
  if (iVar2 != 0) {
    uVar4 = 0;
    if (((unaff_EDI[2] == 3) || (unaff_EDI[2] == 7)) && (unaff_EDI[0x15] != 0)) {
      iVar1 = xtra_drawTextLine(iVar1,unaff_EDI[0x15],param_1,1);
      uVar4 = (undefined2)iVar1;
    }
    rendering_isStateValid((int)unaff_EDI);
    uVar3 = extraout_var;
  }
  return CONCAT22(uVar3,uVar4);
}



// ============================================================
// Function: bitmap_getTextAlignment (FUN_680e90f0)
// Address: 680e90f0
// Size: 145 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getTextAlignment(undefined4 param_1)
{
  int iVar1;
  undefined4 local_2c;
  short local_28;
  uint local_8;
  
  iVar1 = bitmap_getMovieStageData(param_1,&local_2c,0);
  if (iVar1 != 0) {
    if (local_28 == 1) {
      return 0;
    }
    if (local_28 == 2) {
      return 0;
    }
    if (local_28 == 3) {
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_setTextStyle (FUN_680e9190)
// Address: 680e9190
// Size: 136 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall bitmap_setTextStyle(void *this,undefined4 param_1)
{
  uint uVar1;
  
  bitmap_getMovieStageData(param_1,(undefined4 *)0x0,(int)this);
  return 0;
}



// ============================================================
// Function: bitmap_resolveTextFont (FUN_680e9220)
// Address: 680e9220
// Size: 196 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall bitmap_resolveTextFont(undefined4 param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  undefined1 *puVar2;
  int unaff_EDI;
  undefined1 local_ac [84];
  undefined1 local_58 [80];
  uint local_8;
  
  if (((unaff_EDI == 0) || (param_3 < 1)) ||
     (iVar1 = bitmap_getMovieStageData(param_1,(undefined4 *)0x0,param_4), iVar1 == 0)) {
    return 0;
  }
  iVar1 = Ordinal_1114(*(undefined4 *)(param_2 + 0x54));
  puVar2 = local_58;
  if (*(int *)(iVar1 + 4) == 0) {
    puVar2 = local_ac;
  }
  Ordinal_1115(*(undefined4 *)(param_2 + 0x54));
  iVar1 = Ordinal_1255(puVar2,"_DEFAULT_");
  if (iVar1 != 0) {
    Ordinal_1203();
    Ordinal_1201();
    return 0;
  }
  Ordinal_1701();
  return 0;
}



// ============================================================
// Function: bitmap_getTextRunFormat (FUN_680e92f0)
// Address: 680e92f0
// Size: 110 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getTextRunFormat(undefined4 param_1)
{
  int iVar1;
  int unaff_EBX;
  int *unaff_ESI;
  undefined2 *unaff_EDI;
  undefined4 local_ac [19];
  undefined2 local_60;
  undefined1 local_5e;
  uint local_8;
  
  iVar1 = rendering_getMemberData(param_1,unaff_ESI);
  if (iVar1 != 0) {
    if ((((unaff_ESI[2] == 3) || (unaff_ESI[2] == 7)) && (unaff_ESI[0x15] != 0)) && (-1 < unaff_EBX)
       ) {
      xtra_appendToBuffer(unaff_ESI[0x15],local_ac,unaff_EBX);
      *unaff_EDI = local_60;
      *(undefined1 *)((int)unaff_EDI + 3) = 1;
      *(undefined1 *)(unaff_EDI + 1) = local_5e;
    }
    rendering_isStateValid((int)unaff_ESI);
  }
  return 0;
}



// ============================================================
// Function: bitmap_computeTextHeight (FUN_680e9360)
// Address: 680e9360
// Size: 66 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_computeTextHeight(int param_1,int param_2)
{
  int iVar1;
  
  if (((param_2 != 0) && (*(int *)(param_2 + 0x54) != 0)) &&
     ((*(char *)(param_2 + 0x5b) == '\0' || (*(int *)(param_2 + 8) == 7)))) {
    iVar1 = lingo_isValidObject(*(int *)(*(int *)(param_1 + 0x20) + 4));
    iVar1 = xtra_drawTextLine(iVar1,*(int *)(param_2 + 0x54),0,-1);
    *(int *)(param_2 + 0x78) = iVar1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_getMovieStageRef (FUN_680e93b0)
// Address: 680e93b0
// Size: 65 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getMovieStageRef(int param_1,int param_2)
{
  int iVar1;
  byte bVar2;
  
  if (((param_2 != 0) && (*(int *)(param_2 + 8) == 3)) && (*(int *)(param_2 + 0x8c) != 0)) {
    Ordinal_1163(param_2 + 0x8c);
    if (param_1 != 0) {
      bVar2 = 3;
      iVar1 = playback_getLifecycleRef(param_1);
      playback_renderSpriteBlock(iVar1,param_2,bVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_copyTextToClipboard (FUN_680e9400)
// Address: 680e9400
// Size: 69 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_copyTextToClipboard(void)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = xtra_getBufferSize(*(int *)(in_EAX + 0x54));
  iVar2 = xtra_setBufferPos(*(int *)(in_EAX + 0x54),1);
  iVar3 = Ordinal_1114(iVar2);
  if (iVar3 != 0) {
    Ordinal_2013(iVar3,uVar1);
    Ordinal_1115(iVar2);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_readTextProps (FUN_680e9450)
// Address: 680e9450
// Size: 271 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_readTextProps(void)
{
  int *piVar1;
  undefined1 uVar2;
  undefined2 uVar3;
  undefined1 extraout_AH;
  undefined1 extraout_AH_00;
  undefined1 extraout_AH_01;
  short sVar4;
  int unaff_ESI;
  
  uVar2 = Ordinal_1410();
  *(undefined1 *)(unaff_ESI + 0x58) = uVar2;
  uVar2 = Ordinal_1410();
  *(undefined1 *)(unaff_ESI + 0x59) = uVar2;
  uVar2 = Ordinal_1410();
  *(undefined1 *)(unaff_ESI + 0x5a) = uVar2;
  uVar2 = Ordinal_1410();
  *(undefined1 *)(unaff_ESI + 0x5b) = uVar2;
  uVar3 = Ordinal_1412();
  *(undefined2 *)(unaff_ESI + 0x5c) = uVar3;
  Ordinal_1412();
  Ordinal_1412();
  Ordinal_1412();
  *(undefined1 *)(unaff_ESI + 0x5e) = extraout_AH;
  *(undefined1 *)(unaff_ESI + 0x5f) = extraout_AH_00;
  *(undefined1 *)(unaff_ESI + 0x60) = extraout_AH_01;
  *(undefined1 *)(unaff_ESI + 0x61) = 1;
  sVar4 = Ordinal_1412();
  *(int *)(unaff_ESI + 100) = (int)sVar4;
  sVar4 = Ordinal_1412();
  *(int *)(unaff_ESI + 0x6c) = (int)sVar4;
  piVar1 = (int *)(unaff_ESI + 0x68);
  sVar4 = Ordinal_1412();
  *piVar1 = (int)sVar4;
  sVar4 = Ordinal_1412();
  *(int *)(unaff_ESI + 0x74) = (int)sVar4;
  sVar4 = Ordinal_1412();
  *(int *)(unaff_ESI + 0x70) = (int)sVar4;
  sVar4 = Ordinal_1412();
  *(int *)(unaff_ESI + 0x78) = (int)sVar4;
  uVar2 = Ordinal_1410();
  *(undefined1 *)(unaff_ESI + 0x7c) = uVar2;
  uVar2 = Ordinal_1410();
  *(undefined1 *)(unaff_ESI + 0x7d) = uVar2;
  uVar3 = Ordinal_1412();
  *(undefined2 *)(unaff_ESI + 0x7e) = uVar3;
  if (*(int *)(unaff_ESI + 8) == 7) {
    uVar3 = Ordinal_1412();
    *(undefined2 *)(unaff_ESI + 0x80) = uVar3;
  }
  Ordinal_1064(piVar1,-*piVar1,-*(int *)(unaff_ESI + 0x6c));
  *(undefined4 *)(unaff_ESI + 0x84) = 0;
  *(undefined4 *)(unaff_ESI + 0x88) = 0;
  *(undefined4 *)(unaff_ESI + 0x8c) = 0;
  *(undefined4 *)(unaff_ESI + 0x90) = 0;
  return 0;
}



// ============================================================
// Function: bitmap_writeTextProps (FUN_680e9560)
// Address: 680e9560
// Size: 229 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_writeTextProps(void)
{
  int unaff_ESI;
  
  Ordinal_1421();
  Ordinal_1421();
  Ordinal_1421();
  Ordinal_1421();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1421();
  Ordinal_1421();
  Ordinal_1423();
  if (*(int *)(unaff_ESI + 8) == 7) {
    Ordinal_1423();
  }
  return 0;
}



// ============================================================
// Function: bitmap_readFontMapEntry (FUN_680e9650)
// Address: 680e9650
// Size: 115 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_readFontMapEntry(void)

{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *unaff_ESI;
  
  uVar3 = Ordinal_1414();
  *unaff_ESI = uVar3;
  uVar2 = Ordinal_1412();
  *(undefined2 *)(unaff_ESI + 1) = uVar2;
  uVar2 = Ordinal_1412();
  *(undefined2 *)((int)unaff_ESI + 6) = uVar2;
  uVar2 = Ordinal_1412();
  *(undefined2 *)(unaff_ESI + 2) = uVar2;
  uVar1 = Ordinal_1411();
  *(undefined1 *)((int)unaff_ESI + 10) = uVar1;
  uVar1 = Ordinal_1411();
  *(undefined1 *)((int)unaff_ESI + 0xb) = uVar1;
  uVar2 = Ordinal_1412();
  *(undefined2 *)(unaff_ESI + 3) = uVar2;
  uVar2 = Ordinal_1413();
  *(undefined2 *)((int)unaff_ESI + 0xe) = uVar2;
  uVar2 = Ordinal_1413();
  *(undefined2 *)(unaff_ESI + 4) = uVar2;
  uVar2 = Ordinal_1413();
  *(undefined2 *)((int)unaff_ESI + 0x12) = uVar2;
  iVar4 = Ordinal_1042();
  return iVar4 == 0;
}



// ============================================================
// Function: bitmap_writeFontMapEntry (FUN_680e96d0)
// Address: 680e96d0
// Size: 127 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_writeFontMapEntry(void)

{
  int iVar1;
  
  Ordinal_1425();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1421();
  Ordinal_1421();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  Ordinal_1423();
  iVar1 = Ordinal_1041();
  return iVar1 == 0;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================





/* Restored functions that were incorrectly removed during thunk cleanup */

// ============================================================

undefined4 bitmap_returnOutOfMemory(void)

{
  return 0xffffff85;
}

