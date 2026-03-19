// Module: playback
// Topic: Frame navigation, properties, and member data management
// Address range: 0x680d1db0 - 0x680d3880
// Functions (37):
//   playback_getLifecycleInfo, playback_applyChannelCast, playback_setFrameRange, playback_updateFrameProperty
//   playback_setFrameInternal, playback_goToFrame, playback_setFlagsAndDestroy, playback_applyFrameFlags
//   playback_openMemberStream, playback_readMemberStream, playback_readMemberData, playback_dispatchMemberRead, playback_writeMemberStream
//   playback_importMemberFile, playback_saveMemberData, playback_discardMemberChanges, playback_getMemberBounds, playback_readMemberProperties
//   playback_getMemberChannelRef, playback_storeMemberChannelRef, playback_updateMemberChannelRef, playback_checkMemberChannelDirty, playback_loadMemberFromScore
//   playback_writeMemberToStream, playback_getMemberDataSize, playback_exportMemberData, playback_importMemberFromClipboard, playback_syncSpritePlaybackState
//   playback_navigateFrame, playback_findAndUpdateLinkedSprites, playback_detachMember, playback_reattachMember, playback_getMemberProperty
//   playback_setMemberBoundsProperty, playback_getMemberInkMode, playback_applyMemberImport, playback_createMemberInstance, playback_reassignMember

// ============================================================
// Function: playback_getLifecycleInfo (FUN_680d1db0)
// Address: 680d1db0
// Size: 186 bytes
// Params: byte * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getLifecycleInfo(byte *param_1)
{
  int local_18;
  void *pvVar1;
  short sVar2;
  int iVar3;
  /* FIXUP(C2040: 'local_18': 'undefined1): undefined1 local_18 [16]; */
  uint local_8;
  
  pvVar1 = *(void **)(param_1 + 0x24);
  if ((*param_1 & 8) != 0) {
    iVar3 = playback_getLifecycleState((int)param_1);
    if (iVar3 == 0) {
      rendering_setStageSize((int *)param_1,(int)pvVar1);
    }
    rendering_refreshStage(param_1,pvVar1);
    return 0;
  }
  iVar3 = media_applyPixelOp(*(int *)(**(int **)(param_1 + 0x18) + 0xc),1,local_18,0xf);
  if (iVar3 == 0) {
    sVar2 = Ordinal_1208(local_18,"Author");
    if (sVar2 == 0) {
      if (((*param_1 & 0x20) != 0) && (pvVar1 != (void *)0x0)) {
        rendering_refreshStage(param_1,pvVar1);
      }
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_applyChannelCast (playback_applyChannelCast)
// Address: 680d1e70
// Size: 30 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_applyChannelCast(int param_1)
{
  int iVar1;
  int *extraout_EDX;
  
  iVar1 = playback_getLifecycleData(param_1);
  if (iVar1 != 0) {
    rendering_applyChannelCast(extraout_EDX,extraout_EDX[9]);
  }
  return 0;
}



// ============================================================
// Function: playback_setFrameRange (FUN_680d1e90)
// Address: 680d1e90
// Size: 126 bytes
// Params: byte * param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_setFrameRange(byte *param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    if ((*(byte *)(**(int **)(param_1 + 0x18) + 0x1c) & 2) != 0) {
      param_3 = 0;
    }
    iVar1 = *(int *)(param_1 + 0x24);
    if ((param_2 != (int *)0x0) &&
       (iVar2 = rendering_resizeStageSurface(iVar1,param_2[2] - *param_2,param_2[3] - param_2[1],*param_2,param_2[1]
                            ), iVar2 != 0)) {
      iVar2 = playback_setLifecycleState((int)param_1,0);
      if (iVar2 == 0) {
        return 0;
      }
      if ((param_3 != 0) && (*(int *)(iVar1 + 4) != 0)) {
        playback_notifyStageResize();
      }
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: playback_updateFrameProperty (FUN_680d1f10)
// Address: 680d1f10
// Size: 166 bytes
// Params: byte * param_1, uint param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_updateFrameProperty(byte *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    iVar1 = *(int *)(param_1 + 0x24);
    if ((param_2 & 0x200) != 0) {
      lingo_noop();
    }
    playback_setLifecycleRef(param_1);
    rendering_updateStageDisplay(iVar1);
    playback_resetScoreSlots((int)param_1);
    playback_setLifecycleFlags(param_1,param_3);
    playback_setNextFrame((int)param_1,0);
    playback_resumeSoundChannels();
    if ((param_2 & 0x400) != 0) {
      playback_applyChannelCast((int)param_1);
    }
    if ((param_2 & 0x1000) != 0) {
      rendering_setStageSize((int *)param_1,iVar1);
      if ((param_2 & 0x2000) != 0) {
        playback_processLifecycle(param_1,0);
        return 1;
      }
      playback_processLifecycle(param_1,1);
    }
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: playback_setFrameInternal (FUN_680d1fc0)
// Address: 680d1fc0
// Size: 137 bytes
// Params: byte * param_1, int param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_setFrameInternal(byte *param_1,int param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    iVar1 = *(int *)(param_1 + 0x24);
    if ((param_3 & 0x200) != 0) {
      lingo_noop();
    }
    playback_getControlSize((int *)param_1);
    playback_setLifecycleFlags(param_1,param_2);
    playback_setSpriteFrame(param_1,param_2);
    playback_applyChannelCast((int)param_1);
    if ((param_3 & 0x1000) != 0) {
      rendering_setStageSize((int *)param_1,iVar1);
      if ((param_3 & 0x2000) != 0) {
        playback_processLifecycle(param_1,0);
        return 1;
      }
      playback_processLifecycle(param_1,1);
    }
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: playback_goToFrame (FUN_680d2050)
// Address: 680d2050
// Size: 136 bytes
// Params: void * this, uint * param_1, int param_2, undefined2 param_3, int param_4
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall
playback_goToFrame(void *this,uint *param_1,int param_2,undefined2 param_3,int param_4)

{
  int *piVar1;
  undefined1 uVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined3 extraout_var;
  void *extraout_ECX;
  void *extraout_ECX_00;
  
  uVar3 = 0;
  if (param_1 != (uint *)0x0) {
    piVar1 = (int *)param_1[6];
    if (param_1[10] != 0) {
      media_getScorePlayState((int *)(param_1 + 10));
      *param_1 = *param_1 & 0xffffffef;
      this = extraout_ECX;
    }
    if (param_2 != 0) {
      uVar4 = media_writePlaybackData(piVar1,param_3,param_1);
      param_1[10] = uVar4;
      uVar2 = media_getPlaybackByte(uVar4,param_2,*(int *)(param_1[8] + 0x500),param_4);
      if (CONCAT31(extraout_var,uVar2) == 0) {
        lingo_formatDebugMsg(piVar1,-0x7a);
        return 0;
      }
      *param_1 = *param_1 | 0x10;
      this = extraout_ECX_00;
    }
    playback_updatePlaybackFlags(this,param_1);
    playback_setLifecycleRef((byte *)param_1);
    playback_resetScoreSlots((int)param_1);
    uVar3 = 1;
  }
  return uVar3;
}



// ============================================================
// Function: playback_setFlagsAndDestroy (playback_setFlagsAndDestroy)
// Address: 680d20e0
// Size: 34 bytes
// Params: byte * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_setFlagsAndDestroy(byte *param_1,int param_2)

{
  undefined4 uVar1;
  
  uVar1 = playback_setLifecycleFlags(param_1,param_2);
  playback_destroyLifecycle((int)param_1);
  return uVar1;
}



// ============================================================
// Function: playback_applyFrameFlags (playback_applyFrameFlags)
// Address: 680d2110
// Size: 141 bytes
// Params: byte * param_1, uint param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_applyFrameFlags(byte *param_1,uint param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_1 != (byte *)0x0) && ((*param_1 & 8) != 0)) {
    iVar1 = *(int *)(param_1 + 0x24);
    if ((param_2 & 0x200) != 0) {
      lingo_noop();
    }
    if ((param_2 & 0x400) != 0) {
      playback_applyChannelCast((int)param_1);
    }
    if ((param_2 & 0x800) != 0) {
      playback_initScoreEx(~(param_2 >> 0xe) & 1);
    }
    if ((param_2 & 0x1000) != 0) {
      rendering_setStageSize((int *)param_1,iVar1);
      if ((param_2 & 0x2000) != 0) {
        playback_processLifecycle(param_1,0);
        return 1;
      }
      playback_processLifecycle(param_1,1);
    }
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: playback_openMemberStream (playback_openMemberStream)
// Address: 680d21a0
// Size: 198 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_openMemberStream(undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_40c = (int *)0x0;
  iVar1 = rendering_getFrameCount(unaff_ESI);
  if (iVar1 == 0) {
    uVar2 = Ordinal_1038(&DAT_68175c98,&DAT_68175c88,&local_40c);
    iVar1 = Ordinal_2063(uVar2);
    if (iVar1 == 0) {
      iVar1 = Ordinal_1310();
      if (iVar1 != 0) {
        iVar1 = (**(code **)(*local_40c + 0xc))(local_40c,local_408,0xffffffff,0,0);
        if (iVar1 == 0) {
          iVar1 = mediaPlayback_notifySlotWrite(param_1,*(undefined4 **)(unaff_ESI + 0x54),local_40c);
          if (iVar1 == 0) goto LAB_680d223d;
        }
      }
    }
    return 0;
  }
LAB_680d223d:
  return 0;
}



// ============================================================
// Function: playback_readMemberStream (playback_readMemberStream)
// Address: 680d2270
// Size: 55 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_readMemberStream(undefined4 param_1)

{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = rendering_getFrameCount(unaff_ESI);
  if ((iVar1 == 0) && (unaff_EDI != 0)) {
    iVar1 = mediaPlayback_notifySlotRead(param_1,*(undefined4 **)(unaff_ESI + 0x54),unaff_EDI);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: playback_readMemberData (playback_readMemberData)
// Address: 680d22b0
// Size: 301 bytes
// Params: int param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_readMemberData(int param_1,int *param_2)

{
  int in_EAX;
  int iVar1;
  int *unaff_EBX;
  int iVar2;
  undefined4 local_34 [10];
  int *local_c;
  int local_8;
  
  iVar2 = 0;
  local_8 = 0;
  if (*(int **)(in_EAX + 0x54) == (int *)0x0) {
    local_8 = Ordinal_1116(*(undefined4 *)(in_EAX + 0x7c));
  }
  else {
    if (unaff_EBX == (int *)0x0) {
      iVar2 = 0;
    }
    else {
      iVar2 = *unaff_EBX;
    }
    iVar2 = media_dispatchSetRate(iVar2,*(int **)(in_EAX + 0x54),&local_8);
    if (iVar2 != 0) goto LAB_680d23c7;
  }
  if (param_1 == 0) {
    if (local_8 != -1) goto LAB_680d23c7;
    if (param_2 == (int *)0x0) {
      return iVar2;
    }
  }
  if (*(int *)(in_EAX + 0x54) == 0) {
    iVar1 = Ordinal_1114(*(undefined4 *)(in_EAX + 0x7c));
    if (iVar1 != 0) {
      Ordinal_1420(param_1,iVar1,local_8);
      Ordinal_1115(*(undefined4 *)(in_EAX + 0x7c));
    }
  }
  else {
    local_c = (int *)stage_createBytecodeBlock(0x20,0x1c,local_8);
    if (local_c != (int *)0x0) {
      strings_createMediaStream(local_34,local_c,*(undefined4 *)(*local_c + 0x10));
      if (unaff_EBX == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *unaff_EBX;
      }
      iVar2 = media_dispatchSetSoundXtra(iVar2,*(int **)(in_EAX + 0x54),local_34,0xffffffff,local_8);
      stage_getBytecodeSize(local_c);
      if ((local_8 == -1) && (*(int *)(*local_c + 0x10) != 0)) {
        local_8 = *(int *)(*local_c + 0x10);
      }
      if (param_1 != 0) {
        Ordinal_1420(param_1,(int)*(short *)(*local_c + 0x18) + *local_c,local_8);
      }
      Ordinal_1113(&local_c);
    }
  }
LAB_680d23c7:
  if (param_2 != (int *)0x0) {
    *param_2 = local_8;
  }
  return iVar2;
}



// ============================================================
// Function: playback_dispatchMemberRead (playback_dispatchMemberRead)
// Address: 680d23e0
// Size: 123 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_dispatchMemberRead(undefined4 param_1,int param_2,int *param_3)

{
  int local_2c;
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  if ((unaff_ESI == (undefined4 *)0x0) || ((unaff_ESI[2] != 0xf && (unaff_ESI[2] != 0xe)))) {
    iVar3 = -0x79;
  }
  else {
    iVar1 = rendering_getFrameCount((int)unaff_ESI);
    if (iVar1 == 0) {
      iVar1 = playback_readMemberData(param_2,param_3);
      if (iVar1 != 0) {
        iVar3 = -0x7c;
      }
    }
    uVar2 = 1;
  }
  iVar1 = Ordinal_1042();
  if (iVar1 != 0) {
    rendering_initMemberSlot(unaff_ESI,-0x7b);
    return uVar2;
  }
  if (iVar3 != 0) {
    rendering_initMemberSlot(unaff_ESI,iVar3);
  }
  return uVar2;
}



// ============================================================
// Function: playback_writeMemberStream (playback_writeMemberStream)
// Address: 680d2460
// Size: 172 bytes
// Params: void * this, int * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall playback_writeMemberStream(void *this,int *param_1,int param_2,int param_3)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined4 local_30 [10];
  int local_8;
  
  local_8 = Ordinal_1439(*(undefined4 *)this);
  if (local_8 == 0) {
    return 0x80040014;
  }
  if (param_3 != 0) {
    Ordinal_1407(this);
  }
  if (*(int *)(param_2 + 0x54) != 0) {
    strings_writeMediaData(local_30,local_8,0x79f,0,in_EAX);
    if (param_1 == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *param_1;
    }
    uVar2 = media_dispatchSetImageXtra(iVar1,*(int **)(param_2 + 0x54),local_30,0xffffffff,in_EAX);
    Ordinal_1113(&local_8);
    return uVar2;
  }
  if (*(int *)(param_2 + 0x7c) != 0) {
    Ordinal_1113((int *)(param_2 + 0x7c));
  }
  *(int *)(param_2 + 0x7c) = local_8;
  return 0;
}



// ============================================================
// Function: playback_importMemberFile (playback_importMemberFile)
// Address: 680d2510
// Size: 271 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_importMemberFile(undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  int *local_410;
  int *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_40c = (int *)0x0;
  local_410 = (int *)0x0;
  if ((*(uint *)(unaff_ESI + 0x60) & 0x8000) == 0) {
    iVar1 = Ordinal_1310(param_1,local_408,0x3ff);
    if (iVar1 == 0) goto LAB_680d25e8;
    uVar2 = Ordinal_1038(&DAT_681761b8,&DAT_68176198,&local_40c);
    iVar1 = Ordinal_2063(uVar2);
    if (iVar1 != 0) {
      uVar2 = Ordinal_1038(&DAT_681761a8,&DAT_68176198,&local_40c);
      iVar1 = Ordinal_2063(uVar2);
      if (iVar1 != 0) goto LAB_680d25e8;
    }
    iVar1 = (**(code **)(*local_40c + 0xc))(local_40c,local_408);
    if ((iVar1 != 0) ||
       (iVar1 = (**(code **)(*local_40c + 0x18))(local_40c,0,&local_410), iVar1 != 0))
    goto LAB_680d25e8;
  }
  media_dispatchSetImage(unaff_EDI,*(int **)(unaff_ESI + 0x54),local_410);
LAB_680d25e8:
  if (local_40c != (int *)0x0) {
    (**(code **)(*local_40c + 8))(local_40c);
  }
  if (local_410 != (int *)0x0) {
    (**(code **)(*local_410 + 8))(local_410);
  }
  return 0;
}



// ============================================================
// Function: playback_saveMemberData (playback_saveMemberData)
// Address: 680d2620
// Size: 256 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_saveMemberData(int param_1,int *param_2)
{
  int iVar1;
  int local_428;
  int local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  local_424 = 0;
  if ((param_2 == (int *)0x0) || ((param_2[2] != 0xf && (param_2[2] != 0xe)))) goto LAB_680d2701;
  if ((param_2[0xb] & 0x200U) == 0) {
    iVar1 = rendering_getFrameCount((int)param_2);
    if (iVar1 == 0) {
      iVar1 = rendering_updateMemberState(param_2,FOURCC_XMED,&local_428,&local_424,(int *)0x0);
      if ((iVar1 == 1) && (local_424 != 0)) {
        iVar1 = playback_writeMemberStream(&local_424,*(int **)(param_1 + 0x20),(int)param_2,1);
        if (iVar1 == -0x7ffbffe8) {
          lingo_formatDebugMsg(*(int **)(param_1 + 0x18),-0x78);
          goto LAB_680d2701;
        }
        if (iVar1 != 0) goto LAB_680d2701;
      }
    }
    else {
      iVar1 = rendering_dispatchUpdate(*(int *)(param_1 + 0x20),param_2,local_420,1);
      if ((iVar1 != 0) && (iVar1 = playback_importMemberFile(local_420), iVar1 == 0)) goto LAB_680d2701;
    }
  }
  param_2[0xb] = param_2[0xb] | 0x200;
LAB_680d2701:
  Ordinal_1407(&local_424);
  return 0;
}



// ============================================================
// Function: playback_discardMemberChanges (playback_discardMemberChanges)
// Address: 680d2720
// Size: 89 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_discardMemberChanges(void)
{
  int *piVar1;
  int *in_EAX;
  int unaff_ESI;
  
  if ((*(uint *)(unaff_ESI + 0x2c) & 0x200) != 0) {
    piVar1 = *(int **)(unaff_ESI + 0x54);
    if (piVar1 != (int *)0x0) {
      if (in_EAX != (int *)0x0) {
        media_dispatchInvalidate(*in_EAX,piVar1);
        *(uint *)(unaff_ESI + 0x2c) = *(uint *)(unaff_ESI + 0x2c) & 0xfffffdff;
        *(uint *)(unaff_ESI + 0x74) = *(uint *)(unaff_ESI + 0x74) & 0xfffffffe;
        return 0;
      }
      media_dispatchInvalidate(0,piVar1);
      *(uint *)(unaff_ESI + 0x2c) = *(uint *)(unaff_ESI + 0x2c) & 0xfffffdff;
      *(uint *)(unaff_ESI + 0x74) = *(uint *)(unaff_ESI + 0x74) & 0xfffffffe;
      return 0;
    }
    if (*(int *)(unaff_ESI + 0x7c) != 0) {
      Ordinal_1113(unaff_ESI + 0x7c);
    }
    *(uint *)(unaff_ESI + 0x2c) = *(uint *)(unaff_ESI + 0x2c) & 0xfffffdff;
    *(uint *)(unaff_ESI + 0x74) = *(uint *)(unaff_ESI + 0x74) & 0xfffffffe;
  }
  return 0;
}



// ============================================================
// Function: playback_getMemberBounds (playback_getMemberBounds)
// Address: 680d2780
// Size: 334 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getMemberBounds(int *param_1)
{
  int iVar1;
  int iVar2;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if ((unaff_ESI == 0) || ((*(int *)(unaff_ESI + 8) != 0xf && (*(int *)(unaff_ESI + 8) != 0xe)))) {
LAB_680d28be:
    return 0;
  }
  if ((*(byte *)(unaff_ESI + 0x74) & 1) == 0) {
    if (param_1 == (int *)0x0) {
      iVar1 = 0;
    }
    else {
      iVar1 = *param_1;
    }
    iVar1 = media_dispatchGetRect(iVar1,*(int **)(unaff_ESI + 0x54),&local_18);
    if (iVar1 == 0) {
      xtra_skipBytes((undefined1 *)&local_14);
      xtra_skipBytes((undefined1 *)&local_c);
      xtra_skipBytes((undefined1 *)&local_18);
      xtra_skipBytes((undefined1 *)&local_10);
      Ordinal_37((undefined4 *)(unaff_ESI + 0x4c),0xc,&local_18,0x10);
    }
    else {
      iVar2 = Ordinal_38(*(int *)(unaff_ESI + 0x4c),0xc,&local_18,0x10);
      if (iVar2 == 0x10) {
        iVar1 = 0;
      }
    }
    local_14 = xtra_readBE32Ptr((undefined1 *)&local_14);
    local_c = xtra_readBE32Ptr((undefined1 *)&local_c);
    local_18 = xtra_readBE32Ptr((undefined1 *)&local_18);
    local_10 = xtra_readBE32Ptr((undefined1 *)&local_10);
    if (iVar1 == 0) {
      Ordinal_1060(unaff_ESI + 100,local_14,local_18,local_c,local_10);
      *(uint *)(unaff_ESI + 0x74) = *(uint *)(unaff_ESI + 0x74) | 1;
    }
    if ((*(byte *)(unaff_ESI + 0x74) & 1) == 0) {
      Ordinal_1060();
      goto LAB_680d28be;
    }
  }
  *unaff_EBX = *(undefined4 *)(unaff_ESI + 100);
  unaff_EBX[1] = *(undefined4 *)(unaff_ESI + 0x68);
  unaff_EBX[2] = *(undefined4 *)(unaff_ESI + 0x6c);
  unaff_EBX[3] = *(undefined4 *)(unaff_ESI + 0x70);
  return 0;
}



// ============================================================
// Function: playback_readMemberProperties (playback_readMemberProperties)
// Address: 680d28d0
// Size: 264 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_readMemberProperties(void)
{
  int *piVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  char *pcVar6;
  int *unaff_ESI;
  undefined4 *puVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 local_58;
  undefined1 local_54 [2];
  undefined1 auStack_52 [10];
  char local_48 [63];
  undefined1 local_9;
  uint local_8;
  
  sVar3 = 0x79f;
  iVar4 = rendering_getChannelState(unaff_ESI);
  if (iVar4 != 0) {
    sVar3 = rendering_getChannelType(iVar4 + 0x68);
  }
  piVar1 = unaff_ESI + 0x13;
  iVar4 = Ordinal_38(unaff_ESI[0x13],9,&local_58,0x10);
  if ((iVar4 < 0x10) || ((ushort)(sVar3 - 0x4c8U) < 0xb4)) {
    iVar4 = unaff_ESI[0x17];
    uVar8 = 0x10;
    puVar7 = &local_58;
    piVar5 = (int *)lingo_getGlobalRef(*unaff_ESI);
    iVar4 = media_getAssetGuid(piVar5,iVar4,puVar7,uVar8);
    if (iVar4 == 0) {
      xtra_skipBytes((undefined1 *)&local_58);
      xtra_readBE32(local_54);
      xtra_readBE32(auStack_52);
      Ordinal_37(piVar1,9,&local_58,0x10);
    }
  }
  iVar4 = Ordinal_38(*piVar1,10,local_48,0x40);
  if (iVar4 < 1) {
    iVar4 = unaff_ESI[0x17];
    uVar9 = 0x40;
    pcVar6 = local_48;
    piVar5 = (int *)lingo_getGlobalRef(*unaff_ESI);
    iVar4 = media_getDisplayName(piVar5,iVar4,pcVar6,uVar9);
    if (iVar4 == 0) {
      local_9 = 0;
      pcVar6 = local_48;
      do {
        cVar2 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar2 != '\0');
      Ordinal_37(piVar1,10,local_48,(int)(pcVar6 + (1 - (int)(local_48 + 1))));
    }
  }
  return 0;
}



// ============================================================
// Function: playback_getMemberChannelRef (playback_getMemberChannelRef)
// Address: 680d29e0
// Size: 98 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_getMemberChannelRef(undefined4 *param_1)
{
  short sVar1;
  short extraout_var;
  int unaff_EBX;
  int unaff_EDI;
  int local_10;
  int local_c;
  
  sVar1 = scoreEngine_getChannelCount(*(int *)(unaff_EBX + 0x20),(short)*(undefined4 *)(unaff_EDI + 4));
  if (sVar1 != 0) {
    local_10 = (int)sVar1;
    local_c = (int)extraout_var;
    media_resolveScoreRef((int *)&stack0xfffffff8,&local_10,param_1);
    return 0;
  }
  media_initCastSlot((undefined4 *)&stack0xfffffff8,(short *)(unaff_EDI + 4),(int)param_1);
  return 0;
}



// ============================================================
// Function: playback_storeMemberChannelRef (playback_storeMemberChannelRef)
// Address: 680d2a50
// Size: 36 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_storeMemberChannelRef(void)
{
  int in_EAX;
  undefined4 local_18 [5];
  
  playback_getMemberChannelRef(local_18);
  media_createAssetContainer(local_18,(undefined4 *)(in_EAX + 0x58));
  return 0;
}



// ============================================================
// Function: playback_updateMemberChannelRef (playback_updateMemberChannelRef)
// Address: 680d2a80
// Size: 36 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_updateMemberChannelRef(void)
{
  int in_EAX;
  undefined4 local_18 [5];
  
  playback_getMemberChannelRef(local_18);
  mediaPlayback_setNotifyParam(*(undefined4 **)(in_EAX + 0x58),local_18);
  return 0;
}



// ============================================================
// Function: playback_checkMemberChannelDirty (playback_checkMemberChannelDirty)
// Address: 680d2ab0
// Size: 74 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_checkMemberChannelDirty(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  undefined1 local_2c [20];
  undefined4 local_18 [5];
  
  playback_getMemberChannelRef(local_18);
  mediaPlayback_getNotifyParam(*(undefined4 **)(in_EAX + 0x58),local_2c);
  iVar1 = Ordinal_1131(local_2c,local_18,0x14);
  if (iVar1 == 0) {
    uVar2 = playback_updateMemberChannelRef();
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: playback_loadMemberFromScore (playback_loadMemberFromScore)
// Address: 680d2b00
// Size: 454 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_loadMemberFromScore(int param_1,int param_2,undefined4 param_3)
{
  int local_2c;
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_7c;
  int *local_78;
  int local_74;
  undefined4 local_70;
  undefined1 local_6c [24];
  undefined4 local_54 [10];
  /* FIXUP(C2040: 'local_2c': 'undefined1): undefined1 local_2c [36]; */
  uint local_8;
  
  local_70 = param_3;
  uVar1 = Ordinal_1414(param_3);
  if (0x20 < uVar1) goto LAB_680d2cb3;
  iVar2 = Ordinal_1409(local_70,local_2c,uVar1);
  if (iVar2 == 0) goto LAB_680d2cb3;
  local_78 = (int *)(param_2 + 0x5c);
  iVar2 = *(int *)(param_1 + 0x20);
  ((int *)(size_t)local_2c)[ /* FIXUP(C2109): cast to pointer for subscript */uVar1] = 0;
  iVar2 = media_getScoreSlotRef(*(undefined4 *)(*(int *)(iVar2 + 8) + 0xc),local_2c,local_78);
  if (iVar2 == 0) {
    playback_readMemberProperties();
    iVar2 = *local_78;
    puVar7 = (undefined4 *)(param_2 + 0x60);
    puVar6 = (undefined4 *)(param_2 + 0x54);
    piVar3 = (int *)lingo_getGlobalRef(*(int *)(param_1 + 0x18));
    iVar2 = media_loadCastWithContext(param_1,piVar3,iVar2,puVar6,puVar7);
    if (iVar2 != 0) goto LAB_680d2b8e;
  }
  else {
LAB_680d2b8e:
    *(undefined4 *)(param_2 + 0x54) = 0;
    *(undefined4 *)(param_2 + 0x60) = 0;
  }
  piVar3 = (int *)(param_2 + 0x54);
  if (*piVar3 != 0) {
    playback_storeMemberChannelRef();
    media_dispatchSetPosition(param_1,(int *)*piVar3,*(undefined4 *)(param_2 + 0x58));
  }
  local_74 = Ordinal_1414(local_70);
  iVar2 = Ordinal_1435(local_70);
  iVar4 = Ordinal_1433(local_70);
  if (iVar2 - iVar4 < local_74) {
    local_74 = iVar2 - iVar4;
  }
  local_7c = Ordinal_1439(local_70,local_74,0);
  if (local_7c != 0) {
    if (*piVar3 == 0) {
      if (*(int *)(param_2 + 0x78) != 0) {
        Ordinal_1113(param_2 + 0x78);
      }
      if (local_74 != 0) {
        *(int *)(param_2 + 0x78) = local_7c;
      }
    }
    else {
      strings_writeMediaData(local_54,local_7c,0x79f,0,local_74);
      media_dispatchSetOverlayXtra(param_1,(int *)*piVar3,local_54,0xffffffff,local_74);
      Ordinal_1113(&local_7c);
    }
    if (*piVar3 == 0) {
      puVar5 = local_6c;
      local_70 = 0;
      iVar2 = Ordinal_38(*(int *)(param_2 + 0x4c),10,puVar5,0x40);
      piVar3 = local_78;
      if (iVar2 == 0) {
        puVar5 = local_2c;
      }
      iVar2 = Ordinal_1165(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24),&local_70,local_78,
                           xtra_comparePositions,0);
      if (iVar2 == 0) {
        Ordinal_1151(*(undefined4 *)(*(int *)(param_1 + 0x20) + 0x24),local_70,piVar3);
        media_readScoreEntry(3,(int)puVar5,0);
      }
    }
  }
LAB_680d2cb3:
  return 0;
}



// ============================================================
// Function: playback_writeMemberToStream (playback_writeMemberToStream)
// Address: 680d2cd0
// Size: 305 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_writeMemberToStream(int *param_1)
{
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  undefined4 local_5c [10];
  int local_34;
  int *local_30;
  undefined1 local_2c [36];
  uint local_8;
  
  local_30 = param_1;
  media_getSymbolName(*(int *)(unaff_EDI + 0x5c),(int)local_2c,0x20);
  Ordinal_1201(local_2c);
  Ordinal_1425();
  Ordinal_1420();
  piVar1 = local_30;
  iVar2 = 0;
  if (*(int **)(unaff_EDI + 0x54) == (int *)0x0) {
    Ordinal_1116(*(undefined4 *)(unaff_EDI + 0x78));
    Ordinal_1425();
    iVar2 = Ordinal_1114(*(undefined4 *)(unaff_EDI + 0x78));
    if (iVar2 != 0) {
      Ordinal_1420();
      Ordinal_1115(*(undefined4 *)(unaff_EDI + 0x78));
    }
  }
  else {
    local_34 = 0;
    if (local_30 != (int *)0x0) {
      iVar2 = *local_30;
    }
    media_dispatchGetDuration(iVar2,*(int **)(unaff_EDI + 0x54),&local_34);
    Ordinal_1425();
    local_30 = (int *)stage_createBytecodeBlock(0x20,0x1c,local_34);
    if (local_30 != (int *)0x0) {
      strings_createMediaStream(local_5c,local_30,*(undefined4 *)(*local_30 + 0x10));
      if (piVar1 == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *piVar1;
      }
      media_dispatchSetTransitionXtra(iVar2,*(int **)(unaff_EDI + 0x54),local_5c,0xffffffff,local_34);
      stage_getBytecodeSize(local_30);
      Ordinal_1420();
      Ordinal_1113(&local_30);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_getMemberDataSize (playback_getMemberDataSize)
// Address: 680d2e10
// Size: 160 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_getMemberDataSize(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  int local_8;
  
  iVar1 = 0;
  if ((in_EAX != 0) && ((*(int *)(in_EAX + 8) == 0xf || (*(int *)(in_EAX + 8) == 0xe)))) {
    iVar1 = 0xa8;
    if (*(int **)(in_EAX + 0x54) == (int *)0x0) {
      if (*(int *)(in_EAX + 0x78) != 0) {
        iVar1 = Ordinal_1116(*(int *)(in_EAX + 0x78));
        iVar1 = iVar1 + 0xa8;
      }
      if (*(int *)(in_EAX + 0x7c) != 0) {
        iVar2 = Ordinal_1116(*(int *)(in_EAX + 0x7c));
        return iVar2 + iVar1;
      }
    }
    else {
      local_8 = 0;
      if (unaff_EBX == (int *)0x0) {
        iVar2 = 0;
      }
      else {
        iVar2 = *unaff_EBX;
      }
      iVar2 = media_dispatchGetDuration(iVar2,*(int **)(in_EAX + 0x54),&local_8);
      if (iVar2 == 0) {
        iVar1 = local_8 + 0xa8;
      }
      iVar2 = 0;
      local_8 = 0;
      if (unaff_EBX != (int *)0x0) {
        iVar2 = *unaff_EBX;
      }
      iVar2 = media_dispatchSetBlend(iVar2,*(int **)(in_EAX + 0x54),&local_8);
      if (iVar2 == 0) {
        iVar1 = iVar1 + local_8;
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: playback_exportMemberData (playback_exportMemberData)
// Address: 680d2eb0
// Size: 200 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall playback_exportMemberData(int *param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int local_10;
  int local_c;
  int local_8;
  
  uVar2 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  local_10 = Ordinal_1111(0,1);
  if (local_10 != 0) {
    iVar1 = Ordinal_1404(&local_c,local_10,3);
    if (iVar1 != 0) {
      playback_writeMemberToStream(param_1);
      if (*(int **)(in_EAX + 0x54) == (int *)0x0) {
        local_8 = Ordinal_1116(*(undefined4 *)(in_EAX + 0x7c));
      }
      else {
        if (param_1 == (int *)0x0) {
          iVar1 = 0;
        }
        else {
          iVar1 = *param_1;
        }
        media_dispatchSetRate(iVar1,*(int **)(in_EAX + 0x54),&local_8);
        if (local_8 == -1) {
          playback_readMemberData(0,&local_8);
        }
      }
      Ordinal_1425(local_c,local_8);
      playback_readMemberData(local_c,&local_8);
      uVar2 = Ordinal_2008(local_10,0x3ed);
    }
  }
  Ordinal_1407(&local_c);
  Ordinal_1113(&local_10);
  return uVar2;
}



// ============================================================
// Function: playback_importMemberFromClipboard (playback_importMemberFromClipboard)
// Address: 680d2f80
// Size: 151 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool playback_importMemberFromClipboard(int param_1)

{
  int iVar1;
  int unaff_EDI;
  bool bVar2;
  int local_c;
  undefined4 local_8;
  
  bVar2 = false;
  local_c = 0;
  local_8 = 0;
  local_c = Ordinal_2002(0x3ed);
  if (local_c != 0) {
    iVar1 = Ordinal_1404(&local_8,local_c,1);
    if (iVar1 != 0) {
      *(undefined4 *)(unaff_EDI + 0x54) = 0;
      *(undefined4 *)(unaff_EDI + 0x58) = 0;
      *(undefined4 *)(unaff_EDI + 0x78) = 0;
      *(undefined4 *)(unaff_EDI + 0x7c) = 0;
      playback_loadMemberFromScore(param_1,unaff_EDI,local_8);
      iVar1 = rendering_getFrameCount(unaff_EDI);
      if (iVar1 == 0) {
        Ordinal_1414(local_8);
        iVar1 = playback_writeMemberStream(&local_8,*(int **)(param_1 + 0x20),unaff_EDI,1);
        bVar2 = iVar1 == 0;
      }
      else {
        bVar2 = true;
      }
    }
  }
  Ordinal_1407(&local_8);
  Ordinal_1113(&local_c);
  return bVar2;
}



// ============================================================
// Function: playback_syncSpritePlaybackState (playback_syncSpritePlaybackState)
// Address: 680d3020
// Size: 112 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_syncSpritePlaybackState(int param_1,undefined4 param_2)
{
  short sVar1;
  int iVar2;
  short extraout_var;
  int iVar3;
  undefined4 *puVar4;
  int unaff_EDI;
  
  iVar3 = *(int *)(unaff_EDI + 0x120);
  if (iVar3 <= *(int *)(unaff_EDI + 0x124)) {
    iVar2 = iVar3 * 400;
    do {
      puVar4 = (undefined4 *)(*(int *)(unaff_EDI + 0x34) + iVar2);
      if ((((puVar4 != (undefined4 *)0x0) && (puVar4[0x18] == 10)) &&
          (sVar1 = scoreEngine_getChannelData(*(int *)(unaff_EDI + 0x20),(short)*puVar4),
          sVar1 == *(short *)(param_1 + 4))) && (extraout_var == *(short *)(param_1 + 6))) {
        puVar4[0x49] = param_2;
      }
      iVar3 = iVar3 + 1;
      iVar2 = iVar2 + 400;
    } while (iVar3 <= *(int *)(unaff_EDI + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_navigateFrame (FUN_680d3090)
// Address: 680d3090
// Size: 178 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_navigateFrame(int param_1,int param_2,uint *param_3)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  
  playback_checkMemberChannelDirty();
  if (param_1 == 0) {
    iVar3 = media_getVtableData(in_EAX,*(int **)(unaff_ESI + 0x54),param_2,param_3);
    if ((iVar3 != 0) && (param_2 == 0x102)) {
      piVar1 = *(int **)(unaff_ESI + 0x54);
      if (piVar1 != (int *)0x0) {
        (**(code **)(*piVar1 + 4))(piVar1);
      }
      iVar3 = props_storeIntValue(*(undefined4 *)(*(int *)(*(int *)(in_EAX + 0x20) + 8) + 0xc),
                           *(undefined4 *)(unaff_ESI + 0x54),param_3);
    }
  }
  else {
    iVar2 = bitmap_getDirectToStage(in_EAX,param_2,param_3);
    if (iVar2 != 0) {
      playback_syncSpritePlaybackState(unaff_ESI,1);
    }
    iVar3 = media_dispatchRenderAt(in_EAX,*(int **)(unaff_ESI + 0x54),param_2,param_3);
    if (iVar2 != 0) {
      playback_syncSpritePlaybackState(unaff_ESI,0);
    }
  }
  iVar2 = -0x7ffbf82b;
  if (iVar3 != -0x7ffbf830) {
    iVar2 = iVar3;
  }
  return iVar2;
}



// ============================================================
// Function: playback_findAndUpdateLinkedSprites (playback_findAndUpdateLinkedSprites)
// Address: 680d3150
// Size: 137 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_findAndUpdateLinkedSprites(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  short sVar3;
  short extraout_var;
  int iVar4;
  undefined4 *puVar5;
  
  iVar2 = param_1;
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x120), iVar1 <= *(int *)(param_1 + 0x124))) {
    iVar4 = iVar1 * 400;
    param_1 = iVar1;
    do {
      iVar1 = *(int *)(*(int *)(iVar2 + 0x34) + 0x60 + iVar4);
      puVar5 = (undefined4 *)(*(int *)(iVar2 + 0x34) + iVar4);
      if (iVar1 == 10) {
        sVar3 = scoreEngine_getChannelData(*(int *)(iVar2 + 0x20),(short)*puVar5);
        if ((sVar3 == *(short *)(param_2 + 4)) && (extraout_var == *(short *)(param_2 + 6))) {
          bitmap_cleanupSpriteXtra();
        }
      }
      else if (iVar1 == 4) {
        playback_findAndUpdateLinkedSprites(puVar5[0x53],param_2);
      }
      param_1 = param_1 + 1;
      iVar4 = iVar4 + 400;
    } while (param_1 <= *(int *)(iVar2 + 0x124));
  }
  return 0;
}



// ============================================================
// Function: playback_detachMember (playback_detachMember)
// Address: 680d31e0
// Size: 108 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_detachMember(void)

{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  uVar2 = 0;
  if (unaff_EDI != 0) {
    iVar1 = rendering_resolveState(*(int *)(unaff_EDI + 0x18),*(undefined4 *)(unaff_ESI + 4));
    if (unaff_ESI == iVar1) {
      playback_findAndUpdateLinkedSprites(unaff_EDI,unaff_ESI);
    }
  }
  if (*(int **)(unaff_ESI + 0x54) == (int *)0x0) {
    if (*(int *)(unaff_ESI + 0x78) != 0) {
      Ordinal_1113(unaff_ESI + 0x78);
    }
  }
  else {
    media_dispatchFinalize(unaff_EDI,*(int **)(unaff_ESI + 0x54));
  }
  if (*(int **)(unaff_ESI + 0x54) != (int *)0x0) {
    uVar2 = media_dispatchRelease(unaff_EDI,*(int **)(unaff_ESI + 0x54));
    *(undefined4 *)(unaff_ESI + 0x54) = 0;
  }
  if (*(int **)(unaff_ESI + 0x58) != (int *)0x0) {
    mediaPlayback_releaseObject(*(int **)(unaff_ESI + 0x58));
    *(undefined4 *)(unaff_ESI + 0x58) = 0;
  }
  return uVar2;
}



// ============================================================
// Function: playback_reattachMember (playback_reattachMember)
// Address: 680d3250
// Size: 188 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_reattachMember(void)

{
  int *piVar1;
  int *piVar2;
  int in_EAX;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int unaff_ESI;
  int *piVar7;
  undefined4 *puVar8;
  
  piVar2 = *(int **)(unaff_ESI + 0x54);
  piVar1 = (int *)(unaff_ESI + 0x54);
  iVar3 = rendering_getFrameCount(unaff_ESI);
  if (piVar2 == (int *)0x0) {
    uVar6 = Ordinal_1120(*(undefined4 *)(unaff_ESI + 0x7c),0);
    *(undefined4 *)(unaff_ESI + 0x7c) = uVar6;
    uVar6 = Ordinal_1120(*(undefined4 *)(unaff_ESI + 0x78),0);
    *(undefined4 *)(unaff_ESI + 0x78) = uVar6;
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(unaff_ESI + 0x5c);
    puVar8 = (undefined4 *)(unaff_ESI + 0x60);
    piVar7 = piVar1;
    piVar4 = (int *)lingo_getGlobalRef(*(int *)(in_EAX + 0x18));
    iVar5 = media_loadCastWithContext(in_EAX,piVar4,iVar5,piVar7,puVar8);
    if (iVar5 != 0) {
      *piVar1 = 0;
      *(undefined4 *)(unaff_ESI + 0x60) = 0;
    }
    if (*piVar1 != 0) {
      playback_storeMemberChannelRef();
      media_dispatchSetPosition(in_EAX,(int *)*piVar1,*(undefined4 *)(unaff_ESI + 0x58));
      if (iVar5 == 0) {
        iVar5 = media_composeSpriteMedia(in_EAX,(int *)*piVar1,piVar2,0x79f,iVar3);
      }
      if (iVar3 != 0) {
        *(uint *)(unaff_ESI + 0x2c) = *(uint *)(unaff_ESI + 0x2c) & 0xfffffdff;
        return iVar5;
      }
    }
  }
  return iVar5;
}



// ============================================================
// Function: playback_getMemberProperty (playback_getMemberProperty)
// Address: 680d3310
// Size: 585 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_getMemberProperty(int *param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int local_28;
  int local_24;
  undefined4 local_18;
  undefined2 local_14;
  undefined2 local_12;
  uint local_10;
  int *local_c;
  uint local_8;
  
  iVar3 = *param_1;
  piVar1 = (int *)param_1[4];
  if ((*(int *)(iVar3 + 8) == 0xf) || (*(int *)(iVar3 + 8) == 0xe)) {
    playback_checkMemberChannelDirty();
    switch(param_1[3]) {
    case 5:
      playback_getMemberBounds(*(int **)(param_1[1] + 0x20));
      Ordinal_1064(piVar1,-*piVar1,-piVar1[1]);
      return 0;
    case 0xf:
      iVar3 = playback_navigateFrame(0,0xa9,&local_10);
      if (iVar3 == 0) {
        *piVar1 = (int)local_c;
        return 0;
      }
      break;
    case 0x35:
      piVar2 = *(int **)(iVar3 + 0x54);
      if (piVar2 != (int *)0x0) {
        (**(code **)(*piVar2 + 4))(piVar2);
      }
      *piVar1 = *(int *)(iVar3 + 0x54);
      return 0;
    case 0x36:
      *piVar1 = *(int *)(iVar3 + 0x60);
      return 0;
    case 0x37:
      iVar3 = media_queryDrawInterface(param_1[1],*(undefined4 **)(iVar3 + 0x54),piVar1);
      if (iVar3 == 0) {
LAB_680d3543:
        return 0;
      }
      break;
    case 0x3b:
      iVar3 = playback_navigateFrame(0,0x291,&local_10);
      if (iVar3 == 0) {
        if (local_10 == 3) {
          iVar3 = events_getXtraPalette(*(int *)(*(int *)(param_1[1] + 0x20) + 8),&local_10);
          *piVar1 = iVar3;
          Ordinal_4100(*(int *)(*(int *)(*(int *)(*(int *)(param_1[1] + 0x20) + 4) + 4) + 0xc),
                       (byte)local_10,local_c);
          return 0;
        }
        *piVar1 = (int)local_c;
        goto LAB_680d3543;
      }
      break;
    case 0x3c:
      playback_getMemberBounds(*(int **)(param_1[1] + 0x20));
      piVar1[1] = -local_24;
      *piVar1 = -local_28;
      return 0;
    case 0x7b:
      iVar3 = Ordinal_38(*(int *)(iVar3 + 0x4c),9,&local_18,0x10);
      if (iVar3 == 0x10) {
        local_18 = xtra_readBE32Ptr((undefined1 *)&local_18);
        local_14 = xtra_readBE16((undefined1 *)&local_14);
        local_12 = xtra_readBE16((undefined1 *)&local_12);
        Ordinal_1128(piVar1,&local_18,0x10);
        return 0;
      }
    }
  }
  Ordinal_1130(piVar1,0x18);
  return 0;
}



// ============================================================
// Function: playback_setMemberBoundsProperty (playback_setMemberBoundsProperty)
// Address: 680d3600
// Size: 222 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_setMemberBoundsProperty(void)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *in_EAX;
  uint local_24 [2];
  uint local_1c [2];
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = *in_EAX;
  iVar1 = in_EAX[1];
  piVar2 = (int *)in_EAX[4];
  local_10 = iVar1;
  if ((*(int *)(local_8 + 8) == 0xf) || (*(int *)(local_8 + 8) == 0xe)) {
    playback_checkMemberChannelDirty();
    uVar3 = *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x20) + 8) + 0xc);
    if ((in_EAX[3] == 5) && ((*(uint *)(local_8 + 0x60) & 0x200) != 0)) {
      iVar1 = *piVar2;
      iVar4 = piVar2[1];
      iVar5 = piVar2[2];
      iVar6 = piVar2[3];
      local_c = props_resolvePropertyId(uVar3,"width");
      local_14 = props_resolvePropertyId(uVar3,"height");
      props_storeIntValue(uVar3,iVar5 - iVar1,local_1c);
      props_storeIntValue(uVar3,iVar6 - iVar4,local_24);
      playback_navigateFrame(1,local_c,local_1c);
      playback_navigateFrame(1,local_14,local_24);
      return 1;
    }
  }
  Ordinal_1130(piVar2,0x18);
  return 0;
}



// ============================================================
// Function: playback_getMemberInkMode (playback_getMemberInkMode)
// Address: 680d36e0
// Size: 90 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getMemberInkMode(int param_1,int param_2)

{
  int iVar1;
  uint local_c [2];
  
  local_c[0] = 0;
  local_c[1] = 0;
  iVar1 = playback_navigateFrame(0,0x330,local_c);
  if ((iVar1 == 0) &&
     (iVar1 = props_coerceAndReturnInt(*(int *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0xc),local_c,&param_2),
     iVar1 == 0)) {
    return param_2;
  }
  return 1;
}



// ============================================================
// Function: playback_applyMemberImport (playback_applyMemberImport)
// Address: 680d3740
// Size: 181 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_applyMemberImport(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  int iVar4;
  int iVar5;
  int unaff_EDI;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  puVar1 = *(undefined4 **)(unaff_EDI + 0x14);
  iVar2 = *(int *)(unaff_EDI + 0x18);
  iVar5 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(in_EAX + 0x5c) = *(undefined4 *)(unaff_EDI + 0xc);
  playback_readMemberProperties();
  iVar4 = *(int *)(in_EAX + 0x5c);
  puVar7 = (undefined4 *)(in_EAX + 0x60);
  puVar6 = (undefined4 *)(in_EAX + 0x54);
  piVar3 = (int *)lingo_getGlobalRef(iVar5);
  iVar4 = media_loadCastWithContext(param_1,piVar3,iVar4,puVar6,puVar7);
  if (iVar4 != 0) {
    lingo_mutateProperty(iVar5,iVar4);
    return 0;
  }
  iVar5 = 1;
  if ((*(uint *)(in_EAX + 0x60) & 0x2000) == 0) {
    iVar5 = iVar2;
  }
  if ((*(uint *)(in_EAX + 0x60) & 0x1000) == 0) {
    *(undefined4 *)(unaff_EDI + 0x18) = 0;
    return 1;
  }
  if (iVar5 != 0) {
    rendering_setStateFlag(in_EAX,0);
    if (puVar1 != (undefined4 *)0x0) {
      rendering_getStatePair(in_EAX,puVar1);
    }
  }
  *(int *)(unaff_EDI + 0x18) = iVar5;
  return 1;
}



// ============================================================
// Function: playback_createMemberInstance (playback_createMemberInstance)
// Address: 680d3800
// Size: 122 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall playback_createMemberInstance(int param_1)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  int *piVar4;
  
  uVar3 = *(uint *)(param_1 + 0xc);
  iVar1 = *(int *)(in_EAX + 0x18);
  iVar2 = playback_storeMemberChannelRef();
  if (iVar2 == 0) {
    iVar2 = media_dispatchSetPosition(in_EAX,*(int **)(unaff_ESI + 0x54),*(undefined4 *)(unaff_ESI + 0x58));
    if (iVar2 == 0) {
      if ((uVar3 & 2) == 0) {
        if ((uVar3 & 0x8000) == 0) {
          piVar4 = *(int **)(unaff_ESI + 0x54);
          uVar3 = 0;
        }
        else {
          piVar4 = *(int **)(unaff_ESI + 0x54);
          uVar3 = uVar3 & 3;
        }
        iVar2 = media_dispatchSetValue(in_EAX,piVar4,uVar3);
        if (iVar2 != 0) goto LAB_680d3868;
      }
      return 1;
    }
  }
LAB_680d3868:
  lingo_mutateProperty(iVar1,iVar2);
  return 0;
}



// ============================================================
// Function: playback_reassignMember (playback_reassignMember)
// Address: 680d3880
// Size: 123 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall playback_reassignMember(int param_1,int param_2)

{
  int in_EAX;
  int iVar1;
  
  if ((param_2 != 0) &&
     (iVar1 = rendering_resolveState(*(int *)(param_2 + 0x18),*(undefined4 *)(param_1 + 4)), param_1 == iVar1)
     ) {
    playback_findAndUpdateLinkedSprites(param_2,param_1);
  }
  if (*(short *)(param_1 + 4) == *(short *)(in_EAX + 4)) {
    if (*(short *)(param_1 + 6) == *(short *)(in_EAX + 6)) {
      return 1;
    }
    iVar1 = playback_updateMemberChannelRef();
  }
  else {
    iVar1 = playback_reattachMember();
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = playback_detachMember();
  }
  if (iVar1 == 0) {
    return 1;
  }
  return 0;
}



