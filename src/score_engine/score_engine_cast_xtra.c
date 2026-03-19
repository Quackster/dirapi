// Module: score_engine
// Topic: Cast and xtra integration - cast member validation, xtra method invocation, sound channel control
// Address range: 0x680833d0 - 0x68084aa0
// Functions (47):
//   scoreEngine_isScoreActive
//   scoreEngine_writeScoreUpdate
//   scoreEngine_clearAndUpdate
//   scoreEngine_iterateSprites
//   scoreEngine_getMediaFormat
//   scoreEngine_updateStateProperty
//   scoreEngine_lookupSpriteChannel
//   scoreEngine_compareCastSlot
//   scoreEngine_compareStringCase
//   scoreEngine_compareStringNoCase
//   scoreEngine_compareMemberName
//   scoreEngine_createLifecycleNode
//   scoreEngine_initCastXtra
//   scoreEngine_getCastXtraState
//   scoreEngine_getCastLibrary
//   scoreEngine_getSoundChannel
//   scoreEngine_getCastDirtyFlag
//   scoreEngine_markDirty
//   scoreEngine_validateCastMember
//   scoreEngine_setCastXtraFlag
//   scoreEngine_isXtraEditable
//   scoreEngine_setPlaybackFrame
//   scoreEngine_getFrameRate
//   scoreEngine_readCastXtraBlock
//   scoreEngine_writeCastXtraBlock
//   scoreEngine_getCastVersion
//   Ordinal_102
//   scoreEngine_freeScoreData
//   scoreEngine_checkVersionFlag
//   scoreEngine_invokeXtraMethod
//   scoreEngine_getCastXtraData
//   scoreEngine_resumeSound
//   scoreEngine_pauseSound
//   scoreEngine_isSoundPaused
//   scoreEngine_suspendSound
//   scoreEngine_resumeSoundChannel
//   scoreEngine_getCastXtraRef
//   scoreEngine_breakSoundLoop
//   scoreEngine_loadCastXtra
//   scoreEngine_clearSoundRef
//   scoreEngine_writePropertyFlags
//   scoreEngine_onResume
//   scoreEngine_onPause
//   scoreEngine_checkPausedChannels
//   scoreEngine_getSoundFlag
//   scoreEngine_getCuePoint
//   scoreEngine_isPastCuePoint

// ============================================================
// Function: scoreEngine_isScoreActive (FUN_680833d0)
// Address: 680833d0
// Size: 24 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool scoreEngine_isScoreActive(void)

{
  bool bVar1;
  int unaff_ESI;
  
  bVar1 = lingo_isMovieLoaded(*(int **)(*(int *)(unaff_ESI + 4) + 8));
  if (*(int *)(unaff_ESI + 0x484) == 0) {
    bVar1 = false;
  }
  return bVar1;
}



// ============================================================
// Function: scoreEngine_writeScoreUpdate (FUN_680833f0)
// Address: 680833f0
// Size: 132 bytes
// Params: undefined2 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool scoreEngine_writeScoreUpdate(undefined2 param_1,int param_2,undefined *param_3,undefined4 param_4)

{
  undefined1 uVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  undefined4 *unaff_ESI;
  bool bVar4;
  int *local_8;
  
  bVar4 = false;
  local_8 = (int *)media_writePlaybackData(*(undefined4 *)(unaff_ESI[1] + 8),0,0);
  if (local_8 != (int *)0x0) {
    uVar1 = media_getPlaybackByte((int)local_8,*unaff_EBX,unaff_ESI[0x140],0);
    if (CONCAT31(extraout_var,uVar1) != 0) {
      iVar2 = media_isScoreLocked(local_8);
      media_setScoreChannelRef(local_8,unaff_ESI,param_1);
      iVar3 = scoreEngine_applyScoreEdit(unaff_ESI,local_8,param_2,1,iVar2,param_3,param_4);
      bVar4 = iVar3 == iVar2;
    }
    media_getScorePlayState((int *)&local_8);
    *unaff_EBX = 0;
  }
  return bVar4;
}



// ============================================================
// Function: scoreEngine_clearAndUpdate (FUN_68083480)
// Address: 68083480
// Size: 48 bytes
// Params: int param_1, undefined4 param_2, undefined2 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_clearAndUpdate(int param_1,undefined4 param_2,undefined2 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 param_6)
{
  *(undefined4 *)(param_1 + 0xba0) = 0;
  scoreEngine_writeScoreUpdate(param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: scoreEngine_iterateSprites (FUN_680834b0)
// Address: 680834b0
// Size: 561 bytes
// Params: undefined4 param_1, undefined4 * param_2, byte * param_3, int param_4, undefined * param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
scoreEngine_iterateSprites(undefined4 param_1,undefined4 *param_2,byte *param_3,int param_4,undefined *param_5)
{
  bool bVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined4 local_34;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar4 = *(int *)(param_2[1] + 8);
  piVar2 = (int *)rendering_writeSpriteData((uint)param_2,param_3);
  if ((piVar2 != (int *)0x0) && ((*(byte *)(piVar2 + 0xc) & 8) == 0)) {
    iVar3 = (*(code *)param_5)(param_2,piVar2,param_1);
    if (iVar3 == 0) {
LAB_680836cb:
      return 0;
    }
    local_34 = (uint)*param_3;
    if (local_34 == 0x10) {
      local_2c = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      local_28 = 0xf;
      local_30 = piVar2;
      iVar3 = rendering_initState((int *)&local_30);
      if (iVar3 != 0) {
        local_34 = local_24;
      }
    }
    if (local_34 == 1) {
      if ((param_3[1] & 0x3f) == 9) {
        local_34 = CONCAT22((short)((uint)piVar2[1] >> 0x10) + 1,(short)piVar2[1]);
        iVar3 = rendering_resolveState(iVar4,local_34);
        if (iVar3 != 0) {
          iVar3 = (*(code *)param_5)(param_2,iVar3,param_1);
          if (iVar3 == 0) goto LAB_680836cb;
        }
      }
      iVar3 = rendering_getMemberPropertyState(piVar2,&local_34);
      if (iVar3 != 0) {
        iVar4 = rendering_resolveState(iVar4,local_34);
        if (iVar4 != 0) {
          iVar4 = (*(code *)param_5)(param_2,iVar4,param_1);
          if (iVar4 == 0) goto LAB_680836cb;
        }
      }
    }
    else if (local_34 == 0x11) {
      if (param_4 != 0) {
        iVar4 = rendering_getMemberData(*param_2,piVar2);
        if (iVar4 != 0) {
          iVar4 = Ordinal_1120(piVar2[0x15],0);
          if (iVar4 == 0) {
            iVar4 = 0;
          }
          else {
            bVar1 = scoreEngine_writeScoreUpdate((short)piVar2[1],param_4,param_5,param_1);
            iVar4 = CONCAT31(extraout_var,bVar1);
          }
          rendering_isStateValid((int)piVar2);
          if (iVar4 != 0) {
            piVar2[0xc] = piVar2[0xc] | 8;
            return 0;
          }
LAB_680835c6:
          return 0;
        }
      }
    }
    else if ((local_34 == 0x12) && (param_4 != 0)) {
      iVar4 = rendering_getMemberData(*param_2,piVar2);
      if (iVar4 != 0) {
        iVar4 = media_isScoreLocked(*(int **)(*(int *)piVar2[0x1c] + 0x28));
        iVar3 = scoreEngine_applyScoreEdit((int *)piVar2[0x1c],*(int **)(*(int *)piVar2[0x1c] + 0x28),param_4,1,
                             iVar4,param_5,param_1);
        rendering_isStateValid((int)piVar2);
        if (iVar3 == iVar4) goto LAB_680835c6;
      }
    }
    piVar2[0xc] = piVar2[0xc] | 8;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getMediaFormat (FUN_680836f0)
// Address: 680836f0
// Size: 27 bytes
// Params: undefined4 * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_getMediaFormat(undefined4 *param_1,int *param_2)

{
  rendering_getMediaFormat((byte *)*param_1,param_2);
  return 1;
}



// ============================================================
// Function: scoreEngine_updateStateProperty (FUN_68083710)
// Address: 68083710
// Size: 41 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_updateStateProperty(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if ((*(uint *)(param_2 + 0x30) & 8) == 0) {
    iVar1 = rendering_updateStateFromProperty(param_2);
    *param_3 = *param_3 + iVar1;
    *(uint *)(param_2 + 0x30) = *(uint *)(param_2 + 0x30) | 8;
  }
  return 1;
}



// ============================================================
// Function: scoreEngine_lookupSpriteChannel (FUN_68083740)
// Address: 68083740
// Size: 42 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_lookupSpriteChannel(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if ((*(byte *)(param_2 + 0x30) & 4) == 0) {
    uVar1 = rendering_lookupSpriteChannel(param_1,param_2);
    *param_3 = uVar1;
    return *param_3;
  }
  return *param_3;
}



// ============================================================
// Function: scoreEngine_compareCastSlot (FUN_68083770)
// Address: 68083770
// Size: 50 bytes
// Params: int param_1, short * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_compareCastSlot(int param_1,short *param_2)

{
  if (*param_2 < *(short *)(param_1 + 6)) {
    return 1;
  }
  if (*(short *)(param_1 + 6) < *param_2) {
    return 0xffffffff;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_compareStringCase (FUN_680837b0)
// Address: 680837b0
// Size: 20 bytes
// Params: PCNZWCH param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall scoreEngine_compareStringCase(PCNZWCH param_1)

{
  PCNZWCH in_EAX;
  int iVar1;
  
  iVar1 = CompareStringW(0x7f,1,param_1,-1,in_EAX,-1);
  return iVar1 + -2;
}



// ============================================================
// Function: scoreEngine_compareStringNoCase (FUN_680837d0)
// Address: 680837d0
// Size: 20 bytes
// Params: PCNZWCH param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall scoreEngine_compareStringNoCase(PCNZWCH param_1)

{
  PCNZWCH in_EAX;
  int iVar1;
  
  iVar1 = CompareStringW(0x7f,0,param_1,-1,in_EAX,-1);
  return iVar1 + -2;
}



// ============================================================
// Function: scoreEngine_compareMemberName (FUN_680837f0)
// Address: 680837f0
// Size: 159 bytes
// Params: undefined4 * param_1, short * param_2, undefined4 param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_compareMemberName(undefined4 *param_1,short *param_2,undefined4 param_3,int param_4)

{
  short sVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  PCNZWCH local_8;
  
  local_8 = (PCNZWCH)0x0;
  sVar1 = *param_2;
  psVar2 = param_2;
  while (sVar1 != 0) {
    psVar2 = psVar2 + 1;
    sVar1 = *psVar2;
  }
  iVar3 = (int)psVar2 - (int)param_2 >> 1;
  iVar4 = rendering_resolveState(param_4,*param_1);
  iVar5 = iVar3;
  iVar7 = iVar3;
  if (iVar4 != 0) {
    iVar5 = rendering_getMemberFlags(iVar4);
    uVar6 = Ordinal_1116(iVar5);
    local_8 = (PCNZWCH)Ordinal_1114(iVar5);
    iVar7 = (uVar6 >> 1) - 1;
  }
  if ((iVar3 == iVar7) && (iVar7 = scoreEngine_compareStringCase(local_8), iVar7 == 0)) {
    sVar1 = 0;
  }
  else {
    iVar7 = scoreEngine_compareStringNoCase(local_8);
    sVar1 = (short)iVar7;
  }
  if (local_8 != (PCNZWCH)0x0) {
    Ordinal_1115(iVar5);
  }
  return (int)sVar1;
}



// ============================================================
// Function: scoreEngine_createLifecycleNode (FUN_680838a0)
// Address: 680838a0
// Size: 18 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_createLifecycleNode(int *param_1)
{
  lingo_createLifecycleNode(*param_1);
  return 0;
}



// ============================================================
// Function: scoreEngine_initCastXtra (FUN_680838c0)
// Address: 680838c0
// Size: 9 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_initCastXtra(int *param_1)
{
  rendering_getDispatchState(param_1);
  return 0;
}



// ============================================================
// Function: scoreEngine_getCastXtraState (FUN_680838d0)
// Address: 680838d0
// Size: 34 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_getCastXtraState(int param_1)

{
  int iVar1;
  
  iVar1 = lingo_advanceLifecycle(param_1);
  if (iVar1 != 0) {
    return *(undefined4 *)(iVar1 + 0x20);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getCastLibrary (FUN_68083900)
// Address: 68083900
// Size: 16 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_getCastLibrary(int param_1)

{
  return *(undefined4 *)(param_1 + 0x444);
}



// ============================================================
// Function: scoreEngine_getSoundChannel (FUN_68083910)
// Address: 68083910
// Size: 34 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getSoundChannel(int param_1,uint param_2)

{
  if (param_2 < 8) {
    return param_1 + 0x530 + param_2 * 0x14;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getCastDirtyFlag (FUN_68083940)
// Address: 68083940
// Size: 18 bytes
// Params: int param_1
// Return: short
// Calling convention: __stdcall
// ============================================================

short scoreEngine_getCastDirtyFlag(int param_1)

{
  return (short)*(char *)(param_1 + 0x5f9);
}



// ============================================================
// Function: scoreEngine_markDirty (FUN_68083960)
// Address: 68083960
// Size: 29 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_markDirty(int param_1,int param_2)
{
  *(int *)(param_1 + 0x5f4) = param_2;
  if (param_2 == 0) {
    *(undefined1 *)(param_1 + 0x5f8) = 0;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_validateCastMember (FUN_68083980)
// Address: 68083980
// Size: 16 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_validateCastMember(int param_1)

{
  return *(undefined4 *)(param_1 + 0x5f4);
}



// ============================================================
// Function: scoreEngine_setCastXtraFlag (FUN_68083990)
// Address: 68083990
// Size: 28 bytes
// Params: int param_1, undefined1 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setCastXtraFlag(int param_1,undefined1 param_2)
{
  if (*(int *)(param_1 + 0x5f4) != 0) {
    *(undefined1 *)(param_1 + 0x5f8) = param_2;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_isXtraEditable (FUN_680839b0)
// Address: 680839b0
// Size: 37 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_isXtraEditable(undefined4 *param_1)

{
  if ((*(char *)(param_1 + 0x17e) != '\0') && ((*(byte *)*param_1 & 4) == 0)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_setPlaybackFrame (FUN_680839e0)
// Address: 680839e0
// Size: 36 bytes
// Params: int * param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_setPlaybackFrame(int *param_1,short param_2)
{
  if (param_2 < 1) {
    param_2 = 1;
  }
  media_setScoreTempo(*(int **)(*param_1 + 0x28),param_2);
  return 0;
}



// ============================================================
// Function: scoreEngine_getFrameRate (FUN_68083a10)
// Address: 68083a10
// Size: 34 bytes
// Params: int * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint scoreEngine_getFrameRate(int *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = media_getScoreCompositeRef(*(int **)(*param_1 + 0x28));
  uVar2 = uVar1 & 0xffff;
  if ((short)uVar1 < 1) {
    uVar2 = 0x1e;
  }
  return uVar2;
}



// ============================================================
// Function: scoreEngine_readCastXtraBlock (FUN_68083a40)
// Address: 68083a40
// Size: 55 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_readCastXtraBlock(int param_1,undefined1 *param_2)
{
  *param_2 = *(undefined1 *)(param_1 + 0x4a7);
  param_2[1] = *(undefined1 *)(param_1 + 0x49e);
  param_2[2] = *(undefined1 *)(param_1 + 0x49f);
  param_2[3] = *(char *)(param_1 + 0x4a6) != '\0';
  return 0;
}



// ============================================================
// Function: scoreEngine_writeCastXtraBlock (FUN_68083a80)
// Address: 68083a80
// Size: 135 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_writeCastXtraBlock(int *param_1,int *param_2)
{
  if ((((*(char *)((int)param_1 + 0x4a7) != (char)*param_2) ||
       (*(char *)((int)param_1 + 0x49e) != *(char *)((int)param_2 + 1))) ||
      (*(char *)((int)param_1 + 0x49f) != *(char *)((int)param_2 + 2))) ||
     ((bool)*(char *)((int)param_1 + 0x4a6) != (*(char *)((int)param_2 + 3) == '\x01'))) {
    param_1[0x116] = 1;
  }
  *(char *)((int)param_1 + 0x4a7) = (char)*param_2;
  *(undefined1 *)((int)param_1 + 0x49e) = *(undefined1 *)((int)param_2 + 1);
  *(undefined1 *)((int)param_1 + 0x49f) = *(undefined1 *)((int)param_2 + 2);
  *(bool *)((int)param_1 + 0x4a6) = *(char *)((int)param_2 + 3) == '\x01';
  rendering_getStageData(param_1,*(int *)(*param_1 + 0x24),param_2);
  return 0;
}



// ============================================================
// Function: scoreEngine_getCastVersion (FUN_68083b10)
// Address: 68083b10
// Size: 17 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 scoreEngine_getCastVersion(int param_1)

{
  return *(undefined2 *)(param_1 + 0x4a8);
}



// ============================================================
// Function: Ordinal_102
// Address: 68083b30
// Size: 44 bytes
// Params: undefined4 param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_102(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *extraout_ECX;
  int iVar2;
  int extraout_EDX;
  
                    /* 0x83b30  102   */
  iVar2 = 0;
  if (param_2 != 0) {
    iVar1 = scoreEngine_getCastLibrary(param_2);
    iVar2 = extraout_EDX;
    if (iVar1 != 0) {
      iVar2 = rendering_scanMediaFormat((byte *)*extraout_ECX);
      return iVar2;
    }
  }
  return iVar2;
}



// ============================================================
// Function: scoreEngine_freeScoreData (FUN_68083b60)
// Address: 68083b60
// Size: 19 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_freeScoreData(void)
{
  int unaff_ESI;
  
  Ordinal_1110(unaff_ESI + 0x620);
  rendering_freeScorePalette(unaff_ESI);
  return 0;
}



// ============================================================
// Function: scoreEngine_checkVersionFlag (FUN_68083b80)
// Address: 68083b80
// Size: 48 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall scoreEngine_checkVersionFlag(undefined4 param_1,int param_2,int param_3)
{
  ushort uVar1;
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x18) <= *(int *)(in_EAX + 0x10)) {
    uVar1 = rendering_getChannelType(param_2 + 0x48c);
    if (uVar1 < 0x45c) {
      rendering_setStateFlag(param_3,4);
    }
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_invokeXtraMethod (FUN_68083bb0)
// Address: 68083bb0
// Size: 542 bytes
// Params: undefined4 param_1, undefined4 * param_2, int * param_3, int param_4, undefined4 param_5, undefined4 param_6, undefined4 * param_7, undefined4 * param_8
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
scoreEngine_invokeXtraMethod(undefined4 param_1,undefined4 *param_2,int *param_3,int param_4,undefined4 param_5,
            undefined4 param_6,undefined4 *param_7,undefined4 *param_8)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_4c [8];
  undefined4 *local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  undefined4 *local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int *local_24;
  int *local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_30 = param_3;
  local_3c = param_7;
  local_34 = param_8;
  local_18 = (int *)0x0;
  local_20 = (int *)0x0;
  local_2c = (int *)0x0;
  local_24 = (int *)0x0;
  local_28 = (int *)0x0;
  local_44 = param_2;
  local_40 = param_1;
  if ((param_3 != (int *)0x0) && (param_3[1] != 0)) {
    local_1c = (int *)*param_3;
    Ordinal_2330();
    local_14 = (int)local_1c;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  uVar2 = Ordinal_1038();
  local_1c = (int *)Ordinal_2075(uVar2);
  if (((((local_1c != (int *)0x0) &&
        (iVar3 = (**(code **)*local_1c)(local_1c,&DAT_68176008,&local_20), iVar3 == 0)) &&
       (iVar3 = (**(code **)*local_1c)(local_1c,&DAT_68175d78,&local_18), iVar3 == 0)) &&
      ((iVar3 = (**(code **)*local_1c)(local_1c,&DAT_681762f8,&local_2c), iVar3 == 0 &&
       (iVar3 = (**(code **)(*local_18 + 0xc))(local_18,param_5,param_6), iVar3 == 0)))) &&
     (iVar3 = (**(code **)(*local_18 + 0x44))(local_18,param_4 + 1,local_4c), iVar3 == 0)) {
    if (local_30 == (int *)0x0) {
      iVar3 = 0;
    }
    else {
      iVar3 = *local_30;
    }
    iVar3 = lingo_dispatchVtableOp(iVar3,&local_28);
    uVar2 = local_40;
    if (((iVar3 == 0) &&
        (iVar3 = (**(code **)(*local_28 + 0x20))(local_28,0x3c5,1,local_4c,local_40), iVar3 == 0))
       && (iVar3 = (**(code **)(*local_2c + 0xc))(local_2c,uVar2,&local_24), puVar1 = local_44,
          iVar3 == 0)) {
      if (local_44 != (undefined4 *)0x0) {
        (**(code **)(*local_18 + 4))(local_18);
        *puVar1 = local_18;
      }
      puVar1 = local_3c;
      if (local_3c != (undefined4 *)0x0) {
        (**(code **)(*local_20 + 4))(local_20);
        *puVar1 = local_20;
      }
      puVar1 = local_34;
      if (local_34 != (undefined4 *)0x0) {
        (**(code **)(*local_24 + 4))(local_24);
        *puVar1 = local_24;
      }
    }
  }
  if (local_28 != (int *)0x0) {
    (**(code **)(*local_28 + 8))(local_28);
  }
  if (local_24 != (int *)0x0) {
    (**(code **)(*local_24 + 8))(local_24);
  }
  if (local_2c != (int *)0x0) {
    (**(code **)(*local_2c + 8))(local_2c);
  }
  if (local_18 != (int *)0x0) {
    (**(code **)(*local_18 + 8))(local_18);
  }
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  if (local_1c != (int *)0x0) {
    (**(code **)(*local_1c + 8))(local_1c);
  }
  if (local_30 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getCastXtraData (FUN_68083dd0)
// Address: 68083dd0
// Size: 193 bytes
// Params: int param_1, int * param_2, int * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getCastXtraData(int param_1,int *param_2,int *param_3,int *param_4)
{
  int in_EAX;
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int *local_8;
  
  local_8 = (int *)0x0;
  uVar1 = Ordinal_1038();
  piVar2 = (int *)Ordinal_2075(uVar1);
  if (piVar2 != (int *)0x0) {
    (**(code **)*piVar2)(piVar2,&DAT_68175d78,&local_8);
  }
  if (local_8 != (int *)0x0) {
    iVar3 = in_EAX + -1;
    if (-1 < iVar3) {
      iVar4 = param_1 + iVar3 * 8;
      do {
        (**(code **)(*local_8 + 0x1c))(local_8,iVar4);
        iVar4 = iVar4 + -8;
        iVar3 = iVar3 + -1;
      } while (-1 < iVar3);
    }
    (**(code **)(*local_8 + 8))(local_8);
  }
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  if ((param_2 != (int *)0x0) && (piVar2 = (int *)*param_2, piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *param_2 = 0;
  }
  if ((param_3 != (int *)0x0) && (piVar2 = (int *)*param_3, piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *param_3 = 0;
  }
  if ((param_4 != (int *)0x0) && (piVar2 = (int *)*param_4, piVar2 != (int *)0x0)) {
    (**(code **)(*piVar2 + 8))(piVar2);
    *param_4 = 0;
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_resumeSound (FUN_68083ea0)
// Address: 68083ea0
// Size: 279 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_resumeSound(int *param_1,uint param_2)
{
  int iVar1;
  int iVar2;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = param_1[1];
  local_20 = 0;
  local_1c = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = (undefined4 *)0x0;
  local_18 = (int *)0x0;
  if (iVar1 != 0) {
    local_28 = *param_1;
    Ordinal_2330();
    local_14 = local_28;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  iVar2 = scoreEngine_invokeXtraMethod(&local_20,(undefined4 *)0x0,param_1,param_2,&DAT_6817c6bc,&local_24,
                       (undefined4 *)0x0,&local_18);
  if (iVar2 != 0) {
    local_3c = local_24;
    local_2c = &local_20;
    local_30 = 1;
    iVar2 = (**(code **)(*local_18 + 0x38))(local_18,&local_44);
    if (iVar2 == 0) goto LAB_68083f69;
  }
  if (0xf < param_2) {
    return 0;
  }
  Ordinal_1912(param_2);
  *(undefined4 *)(*(int *)(*(int *)(iVar1 + 8) + 4) + 0x20 + param_2 * 4) =
       *(undefined4 *)(iVar1 + 4);
LAB_68083f69:
  scoreEngine_getCastXtraData((int)&local_20,(int *)0x0,(int *)0x0,(int *)&local_18);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: scoreEngine_pauseSound (FUN_68083fc0)
// Address: 68083fc0
// Size: 265 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_pauseSound(int *param_1,uint param_2)
{
  int iVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = 0;
  local_1c = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = (undefined4 *)0x0;
  local_18 = (int *)0x0;
  if ((param_1 != (int *)0x0) && (param_1[1] != 0)) {
    iVar1 = *param_1;
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  iVar1 = scoreEngine_invokeXtraMethod(&local_20,(undefined4 *)0x0,param_1,param_2,"Pause",&local_24,
                       (undefined4 *)0x0,&local_18);
  if (iVar1 != 0) {
    local_28 = &local_20;
    local_38 = local_24;
    local_2c = 1;
    iVar1 = (**(code **)(*local_18 + 0x38))(local_18,&local_40);
    if (iVar1 == 0) goto LAB_6808408f;
  }
  if (0xf < param_2) {
    return 0;
  }
  Ordinal_1916(param_2);
LAB_6808408f:
  scoreEngine_getCastXtraData((int)&local_20,(int *)0x0,(int *)0x0,(int *)&local_18);
  if (param_1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_isSoundPaused (FUN_680840d0)
// Address: 680840d0
// Size: 294 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_isSoundPaused(int *param_1,uint param_2)
{
  int iVar1;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 *local_30;
  undefined4 local_2c;
  undefined1 local_28 [4];
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = (int *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = (undefined4 *)0x0;
  local_1c = (int *)0x0;
  if ((param_1 != (int *)0x0) && (param_1[1] != 0)) {
    iVar1 = *param_1;
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  iVar1 = scoreEngine_invokeXtraMethod(&local_24,&local_18,param_1,param_2,"IsPaused",&local_2c,(undefined4 *)0x0,
                       &local_1c);
  if (iVar1 != 0) {
    local_30 = &local_24;
    local_40 = local_2c;
    local_34 = 1;
    iVar1 = (**(code **)(*local_1c + 0x38))(local_1c,&local_48);
    if ((iVar1 == 0) &&
       (iVar1 = (**(code **)(*local_18 + 0x20))(local_18,&local_3c,local_28), iVar1 == 0))
    goto LAB_680841b8;
  }
  if (0xf < param_2) {
    return 0;
  }
  Ordinal_1917(param_2);
LAB_680841b8:
  scoreEngine_getCastXtraData((int)&local_24,(int *)&local_18,(int *)0x0,(int *)&local_1c);
  if (param_1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_suspendSound (FUN_68084200)
// Address: 68084200
// Size: 265 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_suspendSound(int *param_1,uint param_2)
{
  int iVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = 0;
  local_1c = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = (undefined4 *)0x0;
  local_18 = (int *)0x0;
  if ((param_1 != (int *)0x0) && (param_1[1] != 0)) {
    iVar1 = *param_1;
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  iVar1 = scoreEngine_invokeXtraMethod(&local_20,(undefined4 *)0x0,param_1,param_2,"Suspend",&local_24,
                       (undefined4 *)0x0,&local_18);
  if (iVar1 != 0) {
    local_28 = &local_20;
    local_38 = local_24;
    local_2c = 1;
    iVar1 = (**(code **)(*local_18 + 0x38))(local_18,&local_40);
    if (iVar1 == 0) goto LAB_680842cf;
  }
  if (0xf < param_2) {
    return 0;
  }
  Ordinal_1916(param_2);
LAB_680842cf:
  scoreEngine_getCastXtraData((int)&local_20,(int *)0x0,(int *)0x0,(int *)&local_18);
  if (param_1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_resumeSoundChannel (FUN_68084310)
// Address: 68084310
// Size: 279 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_resumeSoundChannel(int *param_1,uint param_2)
{
  int iVar1;
  int iVar2;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = param_1[1];
  local_20 = 0;
  local_1c = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = (undefined4 *)0x0;
  local_18 = (int *)0x0;
  if (iVar1 != 0) {
    local_28 = *param_1;
    Ordinal_2330();
    local_14 = local_28;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  iVar2 = scoreEngine_invokeXtraMethod(&local_20,(undefined4 *)0x0,param_1,param_2,"Resume",&local_24,
                       (undefined4 *)0x0,&local_18);
  if (iVar2 != 0) {
    local_3c = local_24;
    local_2c = &local_20;
    local_30 = 1;
    iVar2 = (**(code **)(*local_18 + 0x38))(local_18,&local_44);
    if (iVar2 == 0) goto LAB_680843d9;
  }
  if (0xf < param_2) {
    return 0;
  }
  Ordinal_1912(param_2);
  *(undefined4 *)(*(int *)(*(int *)(iVar1 + 8) + 4) + 0x20 + param_2 * 4) =
       *(undefined4 *)(iVar1 + 4);
LAB_680843d9:
  scoreEngine_getCastXtraData((int)&local_20,(int *)0x0,(int *)0x0,(int *)&local_18);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: scoreEngine_getCastXtraRef (FUN_68084430)
// Address: 68084430
// Size: 323 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getCastXtraRef(int *param_1,uint param_2)
{
  int iVar1;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 *local_38;
  undefined1 local_34 [4];
  int local_30;
  undefined4 local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = param_1[1];
  local_24 = 0;
  local_20 = 0;
  local_18 = (int *)0x0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = (undefined4 *)0x0;
  local_1c = (int *)0x0;
  if (local_28 != 0) {
    local_30 = *param_1;
    Ordinal_2330();
    local_14 = local_30;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  iVar1 = scoreEngine_invokeXtraMethod(&local_24,&local_18,param_1,param_2,"IsBusy",&local_2c,(undefined4 *)0x0,
                       &local_1c);
  if (iVar1 != 0) {
    local_48 = local_2c;
    local_38 = &local_24;
    local_3c = 1;
    iVar1 = (**(code **)(*local_1c + 0x38))(local_1c,&local_50);
    if ((iVar1 == 0) &&
       (iVar1 = (**(code **)(*local_18 + 0x20))(local_18,&local_44,local_34), iVar1 == 0))
    goto LAB_6808453a;
  }
  if (0xf < param_2) {
    return 0;
  }
  Ordinal_1913(param_2);
LAB_6808453a:
  scoreEngine_getCastXtraData((int)&local_24,(int *)&local_18,(int *)0x0,(int *)&local_1c);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: scoreEngine_breakSoundLoop (FUN_68084580)
// Address: 68084580
// Size: 265 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_breakSoundLoop(int *param_1,uint param_2)
{
  int iVar1;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = 0;
  local_1c = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = (undefined4 *)0x0;
  local_18 = (int *)0x0;
  if ((param_1 != (int *)0x0) && (param_1[1] != 0)) {
    iVar1 = *param_1;
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  iVar1 = scoreEngine_invokeXtraMethod(&local_20,(undefined4 *)0x0,param_1,param_2,"BreakLoop",&local_24,
                       (undefined4 *)0x0,&local_18);
  if (iVar1 != 0) {
    local_28 = &local_20;
    local_38 = local_24;
    local_2c = 1;
    iVar1 = (**(code **)(*local_18 + 0x38))(local_18,&local_40);
    if (iVar1 == 0) goto LAB_6808464f;
  }
  if (0xf < param_2) {
    return 0;
  }
  Ordinal_1914(param_2);
LAB_6808464f:
  scoreEngine_getCastXtraData((int)&local_20,(int *)0x0,(int *)0x0,(int *)&local_18);
  if (param_1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_loadCastXtra (FUN_68084690)
// Address: 68084690
// Size: 245 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_loadCastXtra(int *param_1,int param_2)
{
  int iVar1;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int *local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = 0;
  local_24 = 0;
  local_20 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = (undefined4 *)0x0;
  local_1c = (int *)0x0;
  if ((param_1 != (int *)0x0) && (param_1[1] != 0)) {
    iVar1 = *param_1;
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  iVar1 = scoreEngine_invokeXtraMethod(&local_24,(undefined4 *)0x0,param_1,param_2,&DAT_6817c6fc,&local_28,
                       (undefined4 *)0x0,&local_1c);
  if (iVar1 == 0) {
LAB_68084739:
    iVar1 = Ordinal_1915(param_2);
    if (iVar1 == 0) goto LAB_6808474a;
  }
  else {
    local_2c = &local_24;
    local_3c = local_28;
    local_30 = 1;
    iVar1 = (**(code **)(*local_1c + 0x38))(local_1c,&local_44);
    if (iVar1 != 0) goto LAB_68084739;
  }
  local_18 = 1;
LAB_6808474a:
  scoreEngine_getCastXtraData((int)&local_24,(int *)0x0,(int *)0x0,(int *)&local_1c);
  if (param_1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_clearSoundRef (FUN_68084790)
// Address: 68084790
// Size: 92 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_clearSoundRef(int param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if (1 < param_2) {
    return 1;
  }
  iVar1 = *(int *)(param_1 + 0x604 + param_2 * 4);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    if (*(short *)(iVar1 + 0x72) == 0) goto LAB_680847d1;
    *(undefined4 *)(iVar1 + 0x70) = 0;
  }
  else {
    if ((param_2 != 1) || (*(short *)(iVar1 + 0x76) == 0)) goto LAB_680847d1;
    *(undefined4 *)(iVar1 + 0x74) = 0;
  }
  uVar2 = 1;
LAB_680847d1:
  *(undefined4 *)(param_1 + 0x604 + param_2 * 4) = 0;
  return uVar2;
}



// ============================================================
// Function: scoreEngine_writePropertyFlags (FUN_680847f0)
// Address: 680847f0
// Size: 148 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_writePropertyFlags(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_1[1] != 0) {
    iVar2 = 0;
    iVar3 = 0x20;
    do {
      iVar1 = scoreEngine_clearSoundRef((int)param_1,iVar2);
      if (iVar1 != 0) {
        scoreEngine_loadCastXtra(param_1,iVar2);
        *(undefined4 *)(iVar3 + *(int *)(*(int *)(param_1[1] + 8) + 4)) = 0;
      }
      iVar3 = iVar3 + 4;
      iVar2 = iVar2 + 1;
    } while (iVar3 < 0x28);
    iVar3 = 2;
    iVar2 = 0x28;
    do {
      iVar1 = param_1[1];
      if ((*(int *)(iVar2 + *(int *)(*(int *)(iVar1 + 8) + 4)) == *(int *)(iVar1 + 4)) ||
         (*(int *)(iVar2 + *(int *)(*(int *)(iVar1 + 8) + 4)) == 0)) {
        scoreEngine_loadCastXtra(param_1,iVar3);
        *(undefined4 *)(iVar2 + *(int *)(*(int *)(param_1[1] + 8) + 4)) = 0;
      }
      iVar2 = iVar2 + 4;
      iVar3 = iVar3 + 1;
    } while (iVar2 < 0x60);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_onResume (FUN_68084890)
// Address: 68084890
// Size: 74 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_onResume(int *param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1[1] != 0) {
    uVar2 = 0;
    iVar3 = 0x20;
    do {
      iVar1 = param_1[1];
      if ((*(int *)(iVar3 + *(int *)(*(int *)(iVar1 + 8) + 4)) == *(int *)(iVar1 + 4)) ||
         (*(int *)(iVar3 + *(int *)(*(int *)(iVar1 + 8) + 4)) == 0)) {
        scoreEngine_suspendSound(param_1,uVar2);
      }
      iVar3 = iVar3 + 4;
      uVar2 = uVar2 + 1;
    } while (iVar3 < 0x60);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_onPause (FUN_680848e0)
// Address: 680848e0
// Size: 74 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_onPause(int *param_1)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if (param_1[1] != 0) {
    uVar2 = 0;
    iVar3 = 0x20;
    do {
      iVar1 = param_1[1];
      if ((*(int *)(iVar3 + *(int *)(*(int *)(iVar1 + 8) + 4)) == *(int *)(iVar1 + 4)) ||
         (*(int *)(iVar3 + *(int *)(*(int *)(iVar1 + 8) + 4)) == 0)) {
        scoreEngine_resumeSoundChannel(param_1,uVar2);
      }
      iVar3 = iVar3 + 4;
      uVar2 = uVar2 + 1;
    } while (iVar3 < 0x60);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_checkPausedChannels (FUN_68084930)
// Address: 68084930
// Size: 76 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_checkPausedChannels(int *param_1)
{
  int iVar1;
  uint uVar2;
  int local_8;
  
  Ordinal_1900(&local_8);
  uVar2 = 0;
  if (0 < local_8) {
    do {
      iVar1 = scoreEngine_isSoundPaused(param_1,uVar2);
      if ((iVar1 != 0) && (iVar1 = scoreEngine_clearSoundRef((int)param_1,0), iVar1 != 0)) {
        scoreEngine_loadCastXtra(param_1,uVar2);
      }
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < local_8);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_getSoundFlag (FUN_68084980)
// Address: 68084980
// Size: 20 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_getSoundFlag(int param_1,int param_2)

{
  return *(undefined4 *)(param_1 + 0x5fc + param_2 * 4);
}



// ============================================================
// Function: scoreEngine_getCuePoint (FUN_680849a0)
// Address: 680849a0
// Size: 255 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getCuePoint(int *param_1,int param_2)
{
  int iVar1;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20;
  int *local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = 0;
  local_1c = (int *)0x0;
  local_28 = 0;
  local_24 = 0;
  local_34 = 0;
  local_30 = 0;
  local_20 = (int *)0x0;
  if ((param_1 != (int *)0x0) && (param_1[1] != 0)) {
    iVar1 = *param_1;
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if (param_2 < 0) {
    iVar1 = scoreEngine_invokeXtraMethod(&local_28,&local_1c,param_1,-1 - param_2,"mostRecentCuePoint",&local_2c,
                         (undefined4 *)0x0,&local_20);
    if (iVar1 != 0) {
      iVar1 = (**(code **)(*local_20 + 0x1c))(local_20,&local_28,local_2c,0,0,&local_34);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*local_1c + 0x20))(local_1c,&local_34,&local_18);
        if (iVar1 == 0) goto LAB_68084a5f;
      }
    }
  }
  local_18 = Ordinal_1475(*param_1,param_2);
LAB_68084a5f:
  scoreEngine_getCastXtraData((int)&local_28,(int *)&local_1c,(int *)0x0,(int *)&local_20);
  if (param_1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_isPastCuePoint (FUN_68084aa0)
// Address: 68084aa0
// Size: 330 bytes
// Params: int * param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_isPastCuePoint(int *param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  undefined1 local_38 [4];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int *local_20 [2];
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = (int *)0x0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = (undefined4 *)0x0;
  local_20[0] = (int *)0x0;
  if ((param_1 != (int *)0x0) && (param_1[1] != 0)) {
    iVar1 = *param_1;
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if (((param_2 < 0) &&
      (iVar1 = scoreEngine_invokeXtraMethod(&local_34,&local_18,param_1,-1 - param_2,"IsPastCuePoint",&local_24,
                            (undefined4 *)0x0,local_20), iVar1 != 0)) &&
     (iVar1 = (**(code **)(*local_18 + 0x44))(local_18,param_3,&local_2c), iVar1 == 0)) {
    local_4c = local_24;
    local_3c = &local_34;
    local_40 = 2;
    iVar1 = (**(code **)(*local_20[0] + 0x38))(local_20[0],&local_54);
    if ((iVar1 == 0) &&
       (iVar1 = (**(code **)(*local_18 + 0x20))(local_18,&local_48,local_38), iVar1 == 0))
    goto LAB_68084bac;
  }
  Ordinal_1470(*param_1,param_2,param_3,param_4);
LAB_68084bac:
  scoreEngine_getCastXtraData((int)&local_34,(int *)&local_18,(int *)0x0,(int *)local_20);
  if (param_1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



