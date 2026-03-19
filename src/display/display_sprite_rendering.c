// Module: display
// Topic: Vector/script cast member handlers and sprite rendering setup
// Address range: 0x680f7f80 - 0x680fa1f0
// Functions (59):
//   display_readSpriteRect
//   display_getScriptMemberValue
//   display_setScriptMemberValue
//   display_getScriptProperty
//   display_setScriptProperty
//   display_updateChannelMedia
//   display_dispatchSpriteMessage
//   display_validateChannelMembers
//   display_checkChannelSlots
//   display_isVectorMember
//   display_releaseSurface
//   display_getRenderFormat
//   display_destroyRenderTarget
//   display_getRenderTargetSize
//   display_createRenderBuffer
//   display_initRenderTarget
//   display_resizeRenderTarget
//   display_destroyVideoOverlay
//   display_updateVideoSprite
//   display_syncVideoPlayback
//   display_getNetStreamCache
//   display_compositeSprite
//   display_clearVideoOverlay
//   display_isVideoReady
//   display_renderVideoFrame
//   display_setupVideoSprite
//   display_refreshVideoSprite
//   display_releaseStreamObject (FUN_680f9390)
//   display_createStreamObject
//   display_openStream
//   display_getSpriteRenderState
//   display_openStreamAccess
//   display_closeStreamAccess
//   display_readStreamData
//   display_getStreamError
//   display_writeStreamData
//   display_getStreamPosition
//   display_setStreamPosition
//   display_getStreamLength
//   display_getStreamStatus
//   display_getStreamMode
//   display_seekStream
//   display_getStreamPending
//   display_flushStream
//   display_finalizeStream
//   display_getSpriteRenderRef
//   display_initStreamVtable
//   display_createStream
//   display_initSpriteRenderer
//   display_stubInitRenderer
//   display_registerRenderer
//   display_allocRendererState
//   display_registerSpritePlugin
//   display_renderSpriteLayer
//   display_renderSpriteFrame
//   display_setupFlashSprite
//   display_wrapGetSpriteBounds
//   display_renderFlashSprite
//   display_applyRenderTransform


// ============================================================
// Function: display_readSpriteRect (FUN_680f7f80)
// Address: 680f7f80
// Size: 64 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_readSpriteRect(void)
{
  short sVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int unaff_EDI;
  
  sVar1 = Ordinal_1412();
  *(int *)(unaff_EDI + 0x5c) = (int)sVar1;
  sVar1 = Ordinal_1412();
  *(int *)(unaff_EDI + 0x58) = (int)sVar1;
  sVar1 = Ordinal_1412();
  *(int *)(unaff_EDI + 100) = (int)sVar1;
  sVar1 = Ordinal_1412();
  *(int *)(unaff_EDI + 0x60) = (int)sVar1;
  uVar3 = Ordinal_1414();
  *(undefined4 *)(unaff_EDI + 0x68) = uVar3;
  uVar2 = Ordinal_1412();
  *(undefined2 *)(unaff_EDI + 0x6c) = uVar2;
  return 0;
}



// ============================================================
// Function: display_getScriptMemberValue (FUN_680f7fc0)
// Address: 680f7fc0
// Size: 264 bytes
// Params: void * this, int * param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall display_getScriptMemberValue(void *this,int *param_1)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  int local_10;
  undefined4 local_c;
  int *local_8;
  
  piVar1 = *(int **)(in_EAX + 0x20);
  local_c = Ordinal_1116(*(undefined4 *)((int)this + 0x54));
  uVar3 = 0;
  iVar2 = rendering_getMemberData(in_EAX,this);
  if (iVar2 == 0) {
    *param_1 = (int)local_8;
    return 0;
  }
  local_8 = (int *)Ordinal_1111(local_c,4);
  if (local_8 != (int *)0x0) {
    iVar2 = Ordinal_1404(&local_10,local_8,3);
    if (iVar2 != 0) {
      iVar2 = display_getVideoMediaLayout(local_10,&local_c,1);
      Ordinal_1407(&local_10);
      if (iVar2 != 0) {
        iVar2 = xtra_getWriteValue(local_8);
        if (iVar2 == 0) {
          Ordinal_1113(&local_8);
          rendering_isStateValid((int)this);
          *param_1 = (int)local_8;
          return 0;
        }
        uVar3 = bitmap_readRtfSequence(local_8,piVar1,1);
        goto LAB_680f809c;
      }
    }
    Ordinal_1113(&local_8);
    rendering_isStateValid((int)this);
    *param_1 = (int)local_8;
    return 0;
  }
LAB_680f809c:
  rendering_isStateValid((int)this);
  *param_1 = (int)local_8;
  return uVar3;
}



// ============================================================
// Function: display_setScriptMemberValue (FUN_680f80d0)
// Address: 680f80d0
// Size: 157 bytes
// Params: void * this, int * param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall display_setScriptMemberValue(void *this,int *param_1)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  void *local_8;
  
  local_8 = this;
  bitmap_mergeRtfEntries(param_1);
  xtra_byteSwapEndian(param_1);
  iVar1 = Ordinal_1404(&local_8,param_1,3);
  if (iVar1 != 0) {
    display_clearMediaLoaded();
    uVar2 = Ordinal_1435(local_8);
    iVar1 = display_loadVideoMedia(local_8,uVar2);
    Ordinal_1407(&local_8);
    if (iVar1 != 0) {
      *(uint *)((int)this + 0x2c) = *(uint *)((int)this + 0x2c) | 0x200;
    }
  }
  iVar1 = xtra_getWriteValue(param_1);
  uVar3 = 0;
  if (iVar1 != 0) {
    uVar3 = bitmap_readRtfSequence(param_1,*(int **)(in_EAX + 0x20),1);
  }
  Ordinal_1113(&param_1);
  return uVar3;
}



// ============================================================
// Function: display_getScriptProperty (FUN_680f8170)
// Address: 680f8170
// Size: 225 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_getScriptProperty(void)

{
  void *this;
  uint *puVar1;
  undefined4 *in_EAX;
  int iVar2;
  
  this = (void *)*in_EAX;
  puVar1 = (uint *)in_EAX[4];
  if ((*(int *)((int)this + 8) == 2) || (*(int *)((int)this + 8) == 9)) {
    switch(in_EAX[3]) {
    case 5:
      *puVar1 = *(uint *)((int)this + 0x58);
      puVar1[1] = *(uint *)((int)this + 0x5c);
      puVar1[2] = *(uint *)((int)this + 0x60);
      puVar1[3] = *(uint *)((int)this + 100);
      return 1;
    case 0x2f:
      *puVar1 = ~(*(uint *)((int)this + 0x68) >> 5) & 1;
      return 1;
    case 0x3c:
      puVar1[1] = (*(int *)((int)this + 100) - *(int *)((int)this + 0x5c)) / 2;
      *puVar1 = (*(int *)((int)this + 0x60) - *(int *)((int)this + 0x58)) / 2;
      return 1;
    case 0x48:
      *puVar1 = *(uint *)((int)this + 0x68) & 1;
      return 1;
    case 0x49:
      *puVar1 = ~(*(uint *)((int)this + 0x68) >> 1) & 1;
      return 1;
    case 0x4a:
      *puVar1 = *(uint *)((int)this + 0x68) >> 3 & 1;
      return 1;
    case 0x4b:
      iVar2 = display_getScriptMemberValue(this,(int *)puVar1);
      if (iVar2 != 0) {
        return iVar2;
      }
    }
  }
  Ordinal_1130(puVar1,0x18);
  return 0;
}



// ============================================================
// Function: display_setScriptProperty (FUN_680f82c0)
// Address: 680f82c0
// Size: 195 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_setScriptProperty(undefined4 *param_1)

{
  int *piVar1;
  int iVar2;
  int *this;
  undefined4 uVar3;
  byte local_8;
  
  piVar1 = (int *)param_1[4];
  iVar2 = param_1[1];
  this = (int *)*param_1;
  uVar3 = 0;
  local_8 = 1;
  if ((this[2] == 2) || (this[2] == 9)) {
    switch(param_1[3]) {
    case 5:
      this[0x16] = *piVar1;
      this[0x17] = piVar1[1];
      this[0x18] = piVar1[2];
      this[0x19] = piVar1[3];
      break;
    default:
      goto switchD_680f82fc_caseD_6;
    case 0x2f:
      if (*piVar1 == 0) {
        this[0x1a] = this[0x1a] | 0x20;
      }
      else {
        this[0x1a] = this[0x1a] & 0xffffffdf;
      }
      break;
    case 0x48:
      if (*piVar1 == 0) {
        this[0x1a] = this[0x1a] & 0xfffffffe;
      }
      else {
        this[0x1a] = this[0x1a] | 1;
      }
      break;
    case 0x49:
      if (*piVar1 == 0) {
        this[0x1a] = this[0x1a] | 2;
      }
      else {
        this[0x1a] = this[0x1a] & 0xfffffffd;
      }
      break;
    case 0x4a:
      if (*piVar1 == 0) {
        this[0x1a] = this[0x1a] & 0xfffffff7;
      }
      else {
        this[0x1a] = this[0x1a] | 8;
      }
      break;
    case 0x4b:
      local_8 = 2;
      display_setScriptMemberValue(this,(int *)*piVar1);
    }
    rendering_setMemberData(iVar2,this,local_8);
    uVar3 = 1;
  }
switchD_680f82fc_caseD_6:
  return uVar3;
}



// ============================================================
// Function: display_updateChannelMedia (FUN_680f83f0)
// Address: 680f83f0
// Size: 164 bytes
// Params: undefined4 param_1, void * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_updateChannelMedia(undefined4 param_1,void *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *unaff_ESI;
  undefined2 *local_c;
  undefined2 *local_8;
  
  local_8 = (undefined2 *)0x0;
  local_c = (undefined2 *)0x0;
  iVar1 = rendering_getMemberData(param_1,unaff_ESI);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)rendering_getChannelState(unaff_ESI);
    local_8 = playback_buildChannelMapByType(param_2,*unaff_ESI,param_2,2,0);
    if (local_8 != (undefined2 *)0x0) {
      iVar3 = media_saveScoreDataEx((int *)unaff_ESI[0x15],(int)local_8);
      if (iVar3 != 0) {
        iVar3 = media_buildScoreChannelMapEx((undefined4 *)unaff_ESI[0x15],(int)puVar2);
        if (iVar3 != 0) {
          local_c = rendering_getChannelSlot(puVar2,1,0);
          if (local_c != (undefined2 *)0x0) {
            media_saveScoreDataEx((int *)unaff_ESI[0x15],(int)local_c);
          }
        }
      }
    }
  }
  rendering_updateMemberMedia(param_1,unaff_ESI);
  if (iVar1 != 0) {
    rendering_isStateValid((int)unaff_ESI);
  }
  rendering_processChannelEvent((int *)&local_8);
  rendering_processChannelEvent((int *)&local_c);
  return 0;
}



// ============================================================
// Function: display_dispatchSpriteMessage (FUN_680f84a0)
// Address: 680f84a0
// Size: 801 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_dispatchSpriteMessage(undefined4 *param_1)
{
  int *this;
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_8;
  
  this = (int *)*param_1;
  local_20 = 0;
  local_1c = this;
  switch(param_1[2]) {
  case 0:
    playback_setTempo((byte *)param_1[1],(int)(this + 0x16));
    this[0x1a] = 0xe;
    piVar2 = media_getScoreStatePtr();
    if (piVar2 != (int *)0x0) {
      media_getScoreLayoutData(piVar2);
      display_setScriptMemberValue(this,piVar2);
    }
  default:
    goto switchD_680f84cc_caseD_1;
  case 3:
    if (this[0x15] != 0) {
      iVar3 = Ordinal_1120(this[0x15],0);
      this[0x15] = iVar3;
      goto LAB_680f859e;
    }
    break;
  case 5:
    bVar1 = display_resolveVideoMedia();
    iVar3 = CONCAT31(extraout_var,bVar1);
    goto LAB_680f859e;
  case 6:
    iVar3 = display_loadVideoMedia(param_1[4],param_1[6]);
    goto LAB_680f859e;
  case 7:
    if (param_1[5] != FOURCC_SCVW) goto switchD_680f84cc_caseD_1;
    iVar3 = display_getVideoMediaLayout(param_1[4],(undefined4 *)param_1[6],param_1[3]);
    goto LAB_680f859e;
  case 8:
    display_clearMediaLoaded();
    break;
  case 9:
    iVar3 = Ordinal_1116(this[0x15]);
    goto LAB_680f8593;
  case 10:
    rendering_updateMemberState(this,FOURCC_SCVW,param_1 + 3,(undefined4 *)0x0,(int *)0x0);
    break;
  case 0xb:
    iVar3 = Ordinal_2008(this[0x15],0x3eb);
    goto LAB_680f859e;
  case 0xc:
    iVar3 = Ordinal_2002(0x3eb);
    this[0x15] = iVar3;
    if (iVar3 == 0) goto LAB_680f85a7;
    display_initVideoPlayback(param_1[1]);
    break;
  case 0xe:
    param_1[3] = 0;
    break;
  case 0xf:
    param_1[3] = 0x11;
    break;
  case 0x10:
    display_readSpriteRect();
    break;
  case 0x11:
    display_writeMovieStream();
    break;
  case 0x12:
    param_1[3] = 1;
    goto switchD_680f84cc_caseD_1;
  case 0x13:
    iVar3 = crt_negotiateFormat(param_1 + 4,param_1[3],FOURCC_SCVW);
LAB_680f8593:
    param_1[3] = iVar3;
switchD_680f84cc_caseD_1:
    iVar3 = rendering_validateState(param_1);
    goto LAB_680f859e;
  case 0x16:
    display_updateChannelMedia(param_1[1],(void *)param_1[3]);
    break;
  case 0x17:
    if (*(int *)param_1[3] != 5) {
LAB_680f8643:
      param_1[4] = 2;
      goto LAB_680f85a7;
    }
    *(int *)param_1[3] = 0;
    uVar4 = rendering_resolveMemberData(*(undefined4 **)(param_1[1] + 0x20),this,(int *)param_1[3],0);
    param_1[4] = uVar4;
    *(undefined4 *)param_1[3] = 5;
    iVar3 = param_1[4];
    goto joined_r0x680f867c;
  case 0x18:
    if (*(int *)param_1[3] != 5) goto LAB_680f8643;
    *(int *)param_1[3] = 0;
    uVar4 = rendering_getMediaInfo(*(undefined4 **)(param_1[1] + 0x20),this[1],(int *)param_1[3]);
    param_1[4] = uVar4;
    *(undefined4 *)param_1[3] = 5;
    iVar3 = param_1[4];
joined_r0x680f867c:
    if (iVar3 != 0) goto LAB_680f85a7;
    break;
  case 0x19:
    iVar3 = display_getScriptProperty();
    if (iVar3 == 0) goto switchD_680f84cc_caseD_1;
    break;
  case 0x1a:
    iVar3 = display_setScriptProperty(param_1);
LAB_680f859e:
    if (iVar3 == 0) goto LAB_680f85a7;
    break;
  case 0x1c:
    param_1[3] = 0;
    iVar3 = rendering_getMemberData(param_1[1],this);
    if (iVar3 != 0) {
      local_1c = (int *)Ordinal_1120(this[0x15],0);
      if (local_1c != (int *)0x0) {
        local_10 = 1;
        local_18 = 0;
        local_14 = 0;
        scoreEngine_clearAndUpdate(*(int *)(param_1[1] + 0x20),&local_1c,(short)this[1],1,scoreEngine_readChannelWithBlend,&local_18);
        param_1[3] = local_10;
      }
      rendering_isStateValid((int)this);
    }
    break;
  case 0x1d:
    iVar3 = Ordinal_1122(this[0x15],*(undefined4 *)(param_1[3] + 0x54));
    if (iVar3 != 0) {
      param_1[4] = 1;
    }
    break;
  case 0x20:
    iVar3 = rendering_getMemberData(param_1[1],this);
    if (iVar3 != 0) {
      local_1c = (int *)Ordinal_1120(this[0x15],0);
      if (local_1c != (int *)0x0) {
        local_20 = 1;
        scoreEngine_clearAndUpdate(*(int *)(param_1[1] + 0x20),&local_1c,(short)this[1],1,scoreEngine_lookupSpriteChannel,&local_20);
        param_1[4] = local_20;
      }
      rendering_isStateValid((int)this);
    }
  }
  local_20 = 1;
LAB_680f85a7:
  return 0;
}




// ============================================================
// Function: display_validateChannelMembers (FUN_680f8850)
// Address: 680f8850
// Size: 122 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_validateChannelMembers(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int *local_8;
  
  local_8 = (int *)0x0;
  local_8 = rendering_getDispatchByChannel(*(int *)(param_1 + 0x18),*(short *)(param_2 + 4));
  if (local_8 != (int *)0x0) {
    piVar1 = (int *)rendering_getMemberCache((int)local_8);
    while (piVar1 != (int *)0x0) {
      if ((piVar1[2] == 0xf) && ((piVar1[0x18] & 0x100U) != 0)) {
        iVar2 = rendering_getMemberData(param_1,piVar1);
        if (iVar2 == 0) break;
        rendering_isStateValid((int)piVar1);
      }
      piVar1 = (int *)rendering_getMemberCache((int)local_8);
    }
    if (local_8 != (int *)0x0) {
      rendering_getDispatchState((int *)&local_8);
    }
  }
  return 0;
}



// ============================================================
// Function: display_checkChannelSlots (FUN_680f88d0)
// Address: 680f88d0
// Size: 115 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_checkChannelSlots(int param_1,int param_2)

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
      if (((piVar1[2] == 0xf) && ((piVar1[0x18] & 0x100U) != 0)) &&
         (iVar2 = rendering_getMemberSlot(piVar1), iVar2 == 0)) goto LAB_680f892b;
      piVar1 = (int *)rendering_getMemberCache((int)local_8);
    }
    uVar3 = 1;
LAB_680f892b:
    if (local_8 != (int *)0x0) {
      rendering_getDispatchState((int *)&local_8);
    }
  }
  return uVar3;
}



// ============================================================
// Function: display_isVectorMember (FUN_680f8950)
// Address: 680f8950
// Size: 40 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_isVectorMember(int param_1)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 8) == 0xf)) &&
     ((*(uint *)(param_1 + 0x60) & 0x100) != 0)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: display_releaseSurface (FUN_680f8980)
// Address: 680f8980
// Size: 42 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_releaseSurface(void)
{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x18) != 0) {
    Ordinal_1604(*(undefined4 *)(in_EAX + 4),0);
    Ordinal_1653(in_EAX + 0x18);
  }
  Ordinal_1061(in_EAX + 8);
  return 0;
}



// ============================================================
// Function: display_getRenderFormat (FUN_680f89b0)
// Address: 680f89b0
// Size: 144 bytes
// Params: uint * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_getRenderFormat(uint *param_1,undefined4 param_2)
{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_28 = 0;
  iVar1 = Ordinal_2031(param_2,&local_28);
  if (iVar1 != 0) {
    iVar1 = strings_clampPolicyRange(&local_14);
    if (iVar1 != 0) {
      *param_1 = local_14;
      param_1[1] = local_10;
      param_1[2] = local_c;
      return 0;
    }
    *param_1 = local_14;
  }
  return 0;
}



// ============================================================
// Function: display_destroyRenderTarget (FUN_680f8a40)
// Address: 680f8a40
// Size: 50 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_destroyRenderTarget(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (param_1 != (undefined4 *)0x0) {
    display_releaseSurface();
    if (param_1[1] != 0) {
      Ordinal_1601(param_1 + 1);
    }
    *param_1 = 0;
    uVar1 = 0;
  }
  return uVar1;
}



// ============================================================
// Function: display_getRenderTargetSize (FUN_680f8a80)
// Address: 680f8a80
// Size: 66 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getRenderTargetSize(int *param_1,int *param_2,int *param_3)

{
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if (param_2 != (int *)0x0) {
      *param_2 = param_1[4] - param_1[2];
      param_2[1] = param_1[5] - param_1[3];
    }
    if (param_3 != (int *)0x0) {
      *param_3 = param_1[7];
    }
    return 0;
  }
  return 1;
}



// ============================================================
// Function: display_createRenderBuffer (FUN_680f8ad0)
// Address: 680f8ad0
// Size: 178 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_createRenderBuffer(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *in_EAX;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar6 = in_EAX[3];
  iVar1 = in_EAX[1];
  iVar2 = in_EAX[2];
  iVar3 = *in_EAX;
  if (*(int *)(param_2 + 0x18) == 0) {
    Ordinal_1060(param_2 + 8,0,0,iVar2 - iVar3,iVar6 - iVar1);
    local_10 = 0;
    local_c = 0;
    local_8 = 0;
    iVar5 = Ordinal_2033();
    if (iVar5 < 0) {
      iVar5 = 0;
    }
    iVar5 = display_getRenderFormat(&local_10,iVar5);
    uVar4 = local_10;
    if (iVar5 == 0) {
      lingo_formatDebugMsg(param_1,-0x19e);
    }
    else {
      iVar6 = Ordinal_1650(local_10,local_c,local_8,iVar2 - iVar3,iVar6 - iVar1,7);
      *(int *)(param_2 + 0x18) = iVar6;
      *(uint *)(param_2 + 0x1c) = uVar4;
      if (iVar6 != 0) {
        uVar7 = Ordinal_1604(*(undefined4 *)(param_2 + 4),iVar6);
        return uVar7;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: display_initRenderTarget (FUN_680f8b90)
// Address: 680f8b90
// Size: 90 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_initRenderTarget(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 1;
  if (param_2 != (int *)0x0) {
    uVar2 = 2;
    if (*param_2 != 0) {
      display_destroyRenderTarget(param_2);
    }
    iVar1 = Ordinal_1600();
    param_2[1] = iVar1;
    if (iVar1 != 0) {
      iVar1 = display_createRenderBuffer(param_1,(int)param_2);
      if (iVar1 != 0) {
        *param_2 = 1;
        return 0;
      }
    }
  }
  display_destroyRenderTarget(param_2);
  return uVar2;
}



// ============================================================
// Function: display_resizeRenderTarget (FUN_680f8bf0)
// Address: 680f8bf0
// Size: 103 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_resizeRenderTarget(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    return 1;
  }
  if ((*param_2 != 0) &&
     ((param_2[4] - param_2[2] != param_3[2] - *param_3 ||
      (param_2[5] - param_2[3] != param_3[3] - param_3[1])))) {
    display_releaseSurface();
    iVar1 = display_createRenderBuffer(param_1,(int)param_2);
    if (iVar1 == 0) {
      return 2;
    }
  }
  return 0;
}



// ============================================================
// Function: display_destroyVideoOverlay (FUN_680f8c60)
// Address: 680f8c60
// Size: 50 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_destroyVideoOverlay(int param_1)
{
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x14c) != 0) {
      Ordinal_1971(*(int *)(param_1 + 0x14c));
      Ordinal_1951(param_1 + 0x14c);
      *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 2;
    }
  }
  return 0;
}



// ============================================================
// Function: display_updateVideoSprite (FUN_680f8ca0)
// Address: 680f8ca0
// Size: 86 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_updateVideoSprite(int param_1,undefined4 *param_2)
{
  int *piVar1;
  uint uVar2;
  
  piVar1 = (int *)playback_getSpriteData(param_1,param_2);
  if ((piVar1 != (int *)0x0) && (piVar1[2] == 10)) {
    if ((piVar1[0xb] & 0x200U) == 0) {
      uVar2 = scoreEngine_readChannelBlock(*(int **)(param_1 + 0x20),piVar1,1);
      if (uVar2 != 0) {
        piVar1[0xb] = piVar1[0xb] | 0x200;
      }
    }
    if (param_2[0x53] != 0) {
      Ordinal_1974(param_2[0x53]);
    }
  }
  return 0;
}



// ============================================================
// Function: display_syncVideoPlayback (FUN_680f8d00)
// Address: 680f8d00
// Size: 107 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_syncVideoPlayback(int param_1,undefined4 *param_2,int param_3)
{
  int iVar1;
  
  iVar1 = playback_getSpriteData(param_1,param_2);
  if ((((iVar1 != 0) && (*(int *)(iVar1 + 8) == 10)) && (param_2[0x53] != 0)) &&
     ((param_2[0x13] & 0x20) != 0)) {
    param_2[0x13] = param_2[0x13] & 0xffffffdf;
    Ordinal_1964(param_2[0x53],*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 0x28),
                 param_2 + 0x32,param_1,param_2[0x10] + 1);
    Ordinal_1970(param_2[0x53],param_3 == 0);
  }
  return 0;
}



// ============================================================
// Function: display_getNetStreamCache (FUN_680f8d70)
// Address: 680f8d70
// Size: 161 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_getNetStreamCache(int *param_1)
{
  int iVar1;
  int *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_40c = (int *)0x0;
  if (param_1 != (int *)0x0) {
    iVar1 = (**(code **)(*param_1 + 0x44))(param_1,&local_40c);
    if (iVar1 == 0) {
      if (local_40c == (int *)0x0) goto LAB_680f8dfe;
      iVar1 = (**(code **)(*local_40c + 0x14))
                        (local_40c,9,local_408,0x400,"MIOKey_NetStreamCacheFile");
      if (iVar1 == 0) {
        Ordinal_1309();
      }
    }
    if (local_40c != (int *)0x0) {
      (**(code **)(*local_40c + 8))(local_40c);
    }
  }
LAB_680f8dfe:
  return 0;
}




// ============================================================
// Function: display_compositeSprite (FUN_680f8e20)
// Address: 680f8e20
// Size: 237 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_compositeSprite(int *param_1,int *param_2,undefined4 param_3,undefined4 *param_4)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 local_420 [1048];
  uint local_8;
  
  *param_4 = 0;
  iVar1 = rendering_updateMemberRef((int)param_1,param_2);
  if (iVar1 != 4) {
    uVar2 = Ordinal_1950(param_3,param_2[0x19]);
    *param_4 = uVar2;
    return 0;
  }
  param_2[0xb] = param_2[0xb] & 0xfffffdff;
  uVar3 = scoreEngine_readChannelBlock(param_1,param_2,1);
  if (uVar3 != 0) {
    param_2[0xb] = param_2[0xb] | 0x200;
    iVar1 = display_getNetStreamCache((int *)param_2[8]);
    if (iVar1 != 0) {
      uVar2 = Ordinal_1950(local_420,param_2[0x19]);
      *param_4 = uVar2;
      return 0;
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: display_clearVideoOverlay (FUN_680f8f10)
// Address: 680f8f10
// Size: 31 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_clearVideoOverlay(int param_1)
{
  if (*(int *)(param_1 + 0x14c) != 0) {
    display_destroyVideoOverlay(param_1);
  }
  *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) & 0xffffffdf;
  return 0;
}



// ============================================================
// Function: display_isVideoReady (FUN_680f8f30)
// Address: 680f8f30
// Size: 83 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_isVideoReady(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = playback_getSpriteData(param_1,param_2);
  if (((iVar1 != 0) && (*(int *)(iVar1 + 8) == 10)) && (param_2[0x53] != 0)) {
    iVar1 = Ordinal_1953(param_2[0x53]);
    if ((iVar1 != 4) && (iVar1 != 6)) {
      return 0;
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: display_renderVideoFrame (FUN_680f8f90)
// Address: 680f8f90
// Size: 459 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_renderVideoFrame(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = param_1;
  local_1c = param_2;
  local_2c = 0;
  local_24 = 0;
  if ((*(byte *)(param_3 + 0x13) & 8) != 0) goto LAB_680f9148;
  piVar1 = (int *)playback_getSpriteData(param_1,param_3);
  if ((piVar1[0xb] & 0x200U) == 0) goto LAB_680f9148;
  if (param_3[0x18] == 6) {
    iVar2 = Ordinal_1975(param_3[0x53],&local_24);
    param_3[0x52] = iVar2;
    if (iVar2 != 0) goto LAB_680f8fff;
LAB_680f90f5:
    iVar2 = lingo_getMovieRef(*(int *)(param_1 + 0x18));
    if (iVar2 != 0) goto LAB_680f910b;
    iVar2 = Ordinal_1041();
    if (iVar2 != 0) goto LAB_680f910b;
  }
  else {
LAB_680f8fff:
    local_2c = Ordinal_1602(param_2);
    Ordinal_1608(param_2,param_3 + 0x32);
    local_14 = param_3[0x1f];
    local_18 = param_3[0x1e];
    local_10 = param_3[0x20];
    local_c = param_3[0x21];
    local_28 = 0;
    uVar3 = lingo_isValidObject(*(int *)(*(int *)(local_20 + 0x20) + 4));
    Ordinal_1604(uVar3,param_3[0x52]);
    Ordinal_1064(&local_18,-local_18,-local_14);
    param_3[0x50] = 0x1000000;
    param_3[0x51] = 0x1ffffff;
    if (local_24 != 0) {
      local_28 = Ordinal_1610(uVar3);
      Ordinal_1609(uVar3,local_24);
    }
    iVar2 = Ordinal_1616(local_1c,param_3 + 0x32,uVar3,&local_18,0,&DAT_68196928,param_3 + 0x4b,
                         param_3 + 0x50,0);
    Ordinal_1604(uVar3,0);
    if (local_28 != 0) {
      Ordinal_1609(uVar3,local_28);
    }
    Ordinal_1976(param_3[0x53],param_3 + 0x52);
    param_1 = local_20;
    param_2 = local_1c;
    if (iVar2 != 0) goto LAB_680f90f5;
LAB_680f910b:
    iVar2 = Ordinal_1042();
    if (iVar2 == 0x66) {
      lingo_formatDebugMsg(*(int **)(param_1 + 0x18),-0x7d);
    }
    else {
      rendering_initMemberSlot(piVar1,-0x1b7);
    }
  }
  rendering_releaseMemberData(piVar1);
  if (local_2c != 0) {
    Ordinal_1603(param_2);
  }
LAB_680f9148:
  return 0;
}



// ============================================================
// Function: display_setupVideoSprite (FUN_680f9160)
// Address: 680f9160
// Size: 521 bytes
// Params: int param_1, undefined4 * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_setupVideoSprite(int param_1,undefined4 *param_2,uint param_3)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_88c [262];
  undefined1 local_474 [20];
  int local_460;
  int local_45c;
  int local_458;
  int local_454;
  int local_420;
  undefined1 local_408 [1024];
  uint local_8;
  
  Ordinal_1130(local_88c,0x418);
  piVar2 = (int *)playback_getSpriteData(param_1,param_2);
  if ((piVar2 == (int *)0x0) || (piVar2[2] != 10)) {
LAB_680f928e:
    return 0;
  }
  iVar3 = core_returnTrue();
  if (iVar3 == 0) goto LAB_680f928e;
  iVar3 = scoreEngine_validateCastMember(*(int *)(param_1 + 0x20));
  if (iVar3 == 0) goto LAB_680f928e;
  if ((param_3 & 0x20004) != 0) {
    display_clearVideoOverlay((int)param_2);
  }
  iVar3 = param_2[0x53];
  param_2[0x13] = param_2[0x13] | 0x23;
  piVar1 = param_2 + 0x53;
  param_2[0x18] = 6;
  if (iVar3 == 0) {
    iVar3 = rendering_dispatchUpdate(*(int *)(param_1 + 0x20),piVar2,local_88c,1);
    if (iVar3 != 0) {
      iVar3 = display_compositeSprite(*(int **)(param_1 + 0x20),piVar2,local_88c,piVar1);
      if ((iVar3 != 0) && (*piVar1 == 0)) goto LAB_680f9351;
    }
    iVar3 = *piVar1;
    if (iVar3 == 0) {
      local_408[0] = 0;
      Ordinal_1982(local_88c,local_408,0x3ff);
      iVar3 = Ordinal_1981(local_88c);
      if (iVar3 == 0) {
        iVar3 = -0x1b5;
      }
      else {
        iVar3 = -0x1b6;
      }
      lingo_formatDebugMsg(*(int **)(param_1 + 0x18),iVar3);
      goto LAB_680f928e;
    }
  }
  Ordinal_1952(iVar3,local_474);
  if (local_420 == 0) {
    piVar2[0x19] = piVar2[0x19] | 0x20;
  }
  if ((*(byte *)(piVar2 + 0x19) & 0x20) == 0) {
    param_2[0x13] = param_2[0x13] & 0xfffffff7;
  }
  else {
    param_2[0x17] = param_2[0x17] & 0xfffffffe;
    param_2[0x13] = param_2[0x13] | 8;
  }
  Ordinal_1980(*piVar1,~((uint)param_2[0x14] >> 1) & 1);
  if (((piVar2[0x19] & 0x800U) != 0) && ((piVar2[0x19] & 0x2000U) != 0)) {
    Ordinal_1961(*piVar1,*(undefined1 *)((int)piVar2 + 0x67));
  }
  if ((local_458 != local_460) && (local_454 != local_45c)) {
    piVar2[0x15] = local_460;
    piVar2[0x16] = local_45c;
    piVar2[0x17] = local_458;
    piVar2[0x18] = local_454;
  }
  playback_renderSprite((int)param_2,(int)piVar2,0);
LAB_680f9351:
  return 0;
}



// ============================================================
// Function: display_refreshVideoSprite (FUN_680f9370)
// Address: 680f9370
// Size: 30 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_refreshVideoSprite(int param_1,undefined4 *param_2)
{
  display_clearVideoOverlay((int)param_2);
  display_setupVideoSprite(param_1,param_2,1);
  return 0;
}



// ============================================================
// Function: display_releaseStreamObject (FUN_680f9390)
// Address: 680f9390
// Size: 71 bytes
// Params: int param_1
// Return: LONG
// Calling convention: __stdcall
// ============================================================

LONG display_releaseStreamObject(int param_1)

{
  int *piVar1;
  LONG LVar2;
  
  LVar2 = InterlockedDecrement((LONG *)(param_1 + 8));
  piVar1 = *(int **)(param_1 + 4);
  if (LVar2 == 0) {
    (**(code **)(*(int *)piVar1[3] + 0x10))((int *)piVar1[3],param_1);
    DAT_68196934 = DAT_68196934 + -1;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*piVar1 + 8))(piVar1);
  return LVar2;
}



// ============================================================
// Function: display_createStreamObject (FUN_680f93e0)
// Address: 680f93e0
// Size: 98 bytes
// Params: int * param_1, undefined4 param_2, undefined * param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 *
display_createStreamObject(int *param_1,undefined4 param_2,undefined *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)param_1[3] + 0xc))((int *)param_1[3],param_2);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_4;
    puVar1[1] = param_1;
    puVar1[2] = 1;
    (**(code **)(*param_1 + 4))(param_1);
    (**(code **)(*param_1 + 4))(param_1);
    DAT_68196934 = DAT_68196934 + 1;
    uVar2 = (*(code *)param_3)(puVar1);
    *param_5 = uVar2;
    return puVar1;
  }
  *param_5 = 0x80040002;
  return (undefined4 *)0x0;
}



// ============================================================
// Function: display_openStream (FUN_680f9460)
// Address: 680f9460
// Size: 224 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
display_openStream(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            )

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int *local_8;
  
  local_8 = (int *)0x0;
  uVar3 = 0;
  uVar1 = Ordinal_1038(&DAT_68176508,&DAT_681760f8,&local_8);
  iVar2 = Ordinal_2063(uVar1);
  if (local_8 != (int *)0x0) {
    *(undefined4 *)(local_8[1] + 0x18) = param_1;
    *(undefined4 *)(local_8[1] + 0x1c) = param_2;
    *(undefined4 *)(local_8[1] + 0x20) = param_3;
    *(undefined4 *)(local_8[1] + 0x24) = 0;
    *(undefined4 *)(local_8[1] + 0x28) = 0;
    *(undefined4 *)(local_8[1] + 0x2c) = 0;
    *(undefined4 *)(local_8[1] + 0x30) = 0;
    *(undefined4 *)(local_8[1] + 0x34) = 0x80040050;
  }
  if (param_4 == 1) {
    uVar1 = 0;
  }
  else if (param_4 == 2) {
    uVar1 = 2;
  }
  else {
    if (param_4 != 3) {
      return 0;
    }
    uVar1 = 1;
  }
  if ((iVar2 == 0) && (iVar2 = (**(code **)(*local_8 + 0xc))(local_8,uVar1,2), iVar2 == 0)) {
    uVar3 = Ordinal_1405(param_5,local_8,param_4,2);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return uVar3;
}



// ============================================================
// Function: display_getSpriteRenderState (FUN_680f9540)
// Address: 680f9540
// Size: 40 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getSpriteRenderState(void)

{
  int in_EAX;
  
  if (in_EAX < 0xcf) {
    if (((in_EAX == 0xce) || (in_EAX == -3)) || (in_EAX == 0)) {
      return 0;
    }
  }
  else if (in_EAX == 0x1f6) {
    return 0x6d;
  }
  return 0x68;
}




// ============================================================
// Function: display_openStreamAccess (FUN_680f9570)
// Address: 680f9570
// Size: 267 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_openStreamAccess(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(*(int *)(param_1 + 4) + 0x28) != 0) {
    return 0x80040051;
  }
  *(int *)(*(int *)(param_1 + 4) + 0x2c) = param_2;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x30) = param_3;
  if (param_2 == 0) {
    iVar1 = crt_readChunkRange(*(int *)(*(int *)(param_1 + 4) + 0x18),
                         *(int *)(*(int *)(param_1 + 4) + 0x1c),(int *)0x0,(int *)0x0);
    if (((iVar1 == 0xcd) || (iVar1 == 0xcc)) || (iVar1 == 0xcb)) {
      Ordinal_1040(0x75);
      return 0x80040001;
    }
    uVar2 = crt_getChunkSize(*(int **)(*(int *)(param_1 + 4) + 0x18),
                         *(int *)(*(int *)(param_1 + 4) + 0x1c));
    if (uVar2 == 0) {
      Ordinal_1040(0x6d);
      return 0x800412e0;
    }
    iVar1 = crt_setReadSlot(*(int **)(*(int *)(param_1 + 4) + 0x18),
                         *(int *)(*(int *)(param_1 + 4) + 0x1c));
    if (iVar1 != 0) {
      return 0x80040051;
    }
  }
  else {
    if (param_2 != 2) {
      Ordinal_1040(0x65);
      return 0x80040055;
    }
    iVar1 = crt_writeChunkHeader(*(undefined4 *)(*(int *)(param_1 + 4) + 0x18),
                         *(int *)(*(int *)(param_1 + 4) + 0x1c));
    if (iVar1 != 0) {
      return 0x80040051;
    }
  }
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x34) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x28) = 1;
  return 0;
}



// ============================================================
// Function: display_closeStreamAccess (FUN_680f9680)
// Address: 680f9680
// Size: 128 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_closeStreamAccess(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar3 = 0;
  uVar2 = 0x65;
  if ((*(int *)(iVar1 + 0x28) != 0) || (iVar4 = *(int *)(iVar1 + 0x34), iVar4 == 0)) {
    if (*(int *)(iVar1 + 0x2c) == 0) {
      iVar1 = crt_getStreamInfo(*(int **)(iVar1 + 0x18));
      if (iVar1 == 0) goto LAB_680f96e4;
      uVar2 = 0x68;
    }
    else {
      if (*(int *)(iVar1 + 0x2c) != 2) {
        iVar4 = -0x7ffbffab;
        uVar2 = 0x65;
        goto LAB_680f96de;
      }
      iVar1 = crt_resetChunkState(*(int *)(iVar1 + 0x18));
      if (iVar1 == 0) goto LAB_680f96e4;
      uVar2 = 0x69;
    }
    iVar4 = -0x7ffbffff;
  }
LAB_680f96de:
  Ordinal_1040(uVar2);
  iVar3 = iVar4;
LAB_680f96e4:
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x28) = 0;
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x34) = 0x80040050;
  return iVar3;
}



// ============================================================
// Function: display_readStreamData (FUN_680f9700)
// Address: 680f9700
// Size: 225 bytes
// Params: int param_1, int param_2, uint param_3, uint * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_readStreamData(int param_1,int param_2,uint param_3,uint *param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  
  uVar3 = param_3;
  iVar5 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar5 + 0x34);
  if (iVar2 != 0) {
    uVar4 = display_getSpriteRenderState();
    Ordinal_1040(uVar4);
    return iVar2;
  }
  if (*(int *)(iVar5 + 0x2c) != 0) {
    uVar4 = display_getSpriteRenderState();
    Ordinal_1040(uVar4);
    return -0x7ffbffff;
  }
  iVar5 = crt_setFormatContext(*(int **)(iVar5 + 0x18),*(int **)(iVar5 + 0x24));
  if (iVar5 == 0) {
    iVar5 = crt_readChunkData(*(int **)(*(int *)(param_1 + 4) + 0x18),param_2,(int *)&param_3);
  }
  if ((iVar5 != -3) && (iVar5 != 0)) {
    uVar4 = display_getSpriteRenderState();
    Ordinal_1040(uVar4);
    return (iVar5 == 0xce) + 0x80040053;
  }
  piVar1 = (int *)(*(int *)(param_1 + 4) + 0x24);
  *piVar1 = *piVar1 + param_3;
  if (param_4 == (uint *)0x0) {
    if (param_3 < uVar3) {
      uVar4 = display_getSpriteRenderState();
      Ordinal_1040(uVar4);
      return -0x7ffbffac;
    }
  }
  else {
    *param_4 = param_3;
  }
  return 0;
}



// ============================================================
// Function: display_getStreamError (FUN_680f97f0)
// Address: 680f97f0
// Size: 25 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_getStreamError(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x34);
  if (iVar1 == 0) {
    iVar1 = -0x7fffbfff;
  }
  return iVar1;
}



// ============================================================
// Function: display_writeStreamData (FUN_680f9810)
// Address: 680f9810
// Size: 130 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_writeStreamData(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar3 + 0x34);
  if (iVar2 != 0) {
    Ordinal_1040(0x65);
    return iVar2;
  }
  if (*(int *)(iVar3 + 0x2c) != 2) {
    Ordinal_1040(0x65);
    return -0x7ffbffff;
  }
  iVar3 = crt_writeChunkBlock(*(int *)(iVar3 + 0x18),param_2,param_3);
  if (iVar3 != 0) {
    Ordinal_1040(0x69);
    return -0x7ffbffad;
  }
  piVar1 = (int *)(*(int *)(param_1 + 4) + 0x24);
  *piVar1 = *piVar1 + param_3;
  return 0;
}



// ============================================================
// Function: display_getStreamPosition (FUN_680f98a0)
// Address: 680f98a0
// Size: 45 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_getStreamPosition(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x34);
  if (iVar1 == 0) {
    if (param_2 == (undefined4 *)0x0) {
      return -0x7ffbffff;
    }
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x24);
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: display_setStreamPosition (FUN_680f98d0)
// Address: 680f98d0
// Size: 44 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_setStreamPosition(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 0x34);
  if (iVar2 == 0) {
    if (*(uint *)(iVar1 + 0x20) < param_2) {
      return -0x7ffbffad;
    }
    *(uint *)(iVar1 + 0x24) = param_2;
    iVar2 = 0;
  }
  return iVar2;
}



// ============================================================
// Function: display_getStreamLength (FUN_680f9900)
// Address: 680f9900
// Size: 59 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_getStreamLength(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(iVar1 + 0x34);
  if (iVar2 == 0) {
    if (param_2 == (undefined4 *)0x0) {
      return -0x7ffbffff;
    }
    if (*(int *)(iVar1 + 0x2c) != 0) {
      return -0x7fffbfff;
    }
    *param_2 = *(undefined4 *)(iVar1 + 0x20);
    iVar2 = 0;
  }
  return iVar2;
}



// ============================================================
// Function: display_getStreamStatus (FUN_680f9940)
// Address: 680f9940
// Size: 25 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_getStreamStatus(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x34);
  if (iVar1 == 0) {
    iVar1 = -0x7fffbfff;
  }
  return iVar1;
}



// ============================================================
// Function: display_getStreamMode (FUN_680f9960)
// Address: 680f9960
// Size: 58 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_getStreamMode(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x34);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x2c);
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x30);
  }
  return 0;
}



// ============================================================
// Function: display_seekStream (FUN_680f99a0)
// Address: 680f99a0
// Size: 106 bytes
// Params: int * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_seekStream(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = param_1[1];
  if (*(int *)(iVar1 + 0x34) != 0) {
    return *(int *)(iVar1 + 0x34);
  }
  if (param_3 == 0) {
    *(int *)(iVar1 + 0x24) = param_2;
  }
  else if (param_3 == 1) {
    *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x24) + param_2;
  }
  else {
    if (param_3 != 2) {
      return -0x7ffbffad;
    }
    *(int *)(iVar1 + 0x24) = *(int *)(iVar1 + 0x20) + param_2;
  }
  iVar1 = (**(code **)(*param_1 + 0x24))(param_1,*(undefined4 *)(param_1[1] + 0x24));
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: display_getStreamPending (FUN_680f9a10)
// Address: 680f9a10
// Size: 37 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_getStreamPending(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x34);
  if (iVar1 == 0) {
    iVar1 = (-(uint)(*(int *)(*(int *)(param_1 + 4) + 0x2c) != 0) & 0xfffc3fae) + 0x80040053;
  }
  return iVar1;
}



// ============================================================
// Function: display_flushStream (FUN_680f9a40)
// Address: 680f9a40
// Size: 32 bytes
// Params: int * param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_flushStream(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*param_1 + 0x28))(param_1,param_2);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: display_finalizeStream (FUN_680f9a60)
// Address: 680f9a60
// Size: 51 bytes
// Params: int * param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_finalizeStream(int *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1[1] + 0x34);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_1 + 0x10))(param_1);
    iVar2 = 0;
    if (iVar1 == 0) goto LAB_680f9a82;
  }
  iVar2 = iVar1;
LAB_680f9a82:
  *(undefined4 *)(param_1[1] + 0x34) = param_2;
  return iVar2;
}




// ============================================================
// Function: display_getSpriteRenderRef (FUN_680f9aa0)
// Address: 680f9aa0
// Size: 25 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_getSpriteRenderRef(int param_1)

{
  int local_2c;
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x34);
  if (iVar1 == 0) {
    iVar1 = -0x7fffbfff;
  }
  return iVar1;
}



// ============================================================
// Function: display_initStreamVtable (FUN_680f9ac0)
// Address: 680f9ac0
// Size: 236 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * display_initStreamVtable(void)

{
  if (DAT_68196930 == '\0') {
    DAT_68196930 = '\x01';
    _DAT_68197b80 = media_invokeCallback;
    _DAT_68197b84 = media_addRef;
    _DAT_68197b88 = display_releaseStreamRef;
    _DAT_68197b8c = display_openStreamAccess;
    _DAT_68197b90 = display_closeStreamAccess;
    _DAT_68197b94 = display_readStreamData;
    _DAT_68197b98 = display_getStreamError;
    _DAT_68197b9c = display_writeStreamData;
    _DAT_68197ba0 = display_getStreamPosition;
    _DAT_68197ba4 = display_setStreamPosition;
    _DAT_68197ba8 = display_getStreamLength;
    _DAT_68197bac = display_getStreamStatus;
    _DAT_68197bb0 = display_getStreamMode;
    _DAT_68197bb4 = display_seekStream;
    _DAT_68197bb8 = display_getStreamPending;
    _DAT_68197bbc = display_flushStream;
    _DAT_68197bc0 = display_finalizeStream;
    _DAT_68197bc4 = display_getSpriteRenderRef;
    _DAT_68197bc8 = display_getSpriteRenderRef;
    _DAT_68197bcc = display_getSpriteRenderRef;
    _DAT_68197bd0 = display_getSpriteRenderRef;
  }
  return &DAT_68197b80;
}



// ============================================================
// Function: display_createStream (FUN_680f9bb0)
// Address: 680f9bb0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_createStream(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = display_initStreamVtable();
  piVar3 = display_createStreamObject(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: display_initSpriteRenderer (FUN_680f9c10)
// Address: 680f9c10
// Size: 111 bytes
// Params: undefined * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_initSpriteRenderer(undefined *param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  code *unaff_EDI;
  
  iVar2 = 0;
  if ((in_EAX == 0) || (iVar1 = Ordinal_2066(), iVar1 != 0)) {
    if ((unaff_EDI != (code *)0x0) &&
       (iVar2 = (*unaff_EDI)(&DAT_68176508,1,0x38,lingo_noop,rendering_updateDisplay), iVar2 != 0)) {
      return iVar2;
    }
    iVar2 = 0;
    if (param_1 != (undefined *)0x0) {
      iVar2 = (*(code *)param_1)(&DAT_68176508,1,&DAT_681760f8,1,display_createStream);
    }
  }
  return iVar2;
}



// ============================================================
// Function: display_stubInitRenderer (FUN_680f9c80)
// Address: 680f9c80
// Size: 70 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_stubInitRenderer(void)

{
  display_initSpriteRenderer((undefined *)0x0);
  return 0x80040005;
}



// ============================================================
// Function: display_registerRenderer (FUN_680f9cd0)
// Address: 680f9cd0
// Size: 75 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x680f9d00) */

undefined4 display_registerRenderer(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  display_initSpriteRenderer(xtra_matchStreamInterface);
  return 0x80040004;
}



// ============================================================
// Function: display_allocRendererState (FUN_680f9d20)
// Address: 680f9d20
// Size: 207 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_allocRendererState(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  display_initSpriteRenderer(lingo_createObjectEx);
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0xc))(param_1,0x28);
  *param_2 = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0x80040002;
  }
  display_initSpriteRenderer(lingo_createObjectEx);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  return 0;
}



// ============================================================
// Function: display_registerSpritePlugin (FUN_680f9df0)
// Address: 680f9df0
// Size: 51 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_registerSpritePlugin(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_2071(param_1,&LAB_6811d1e0,display_registerRenderer,display_stubInitRenderer,&LAB_680f9450,display_allocRendererState);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: display_renderSpriteLayer (FUN_680f9e30)
// Address: 680f9e30
// Size: 59 bytes
// Params: undefined4 * param_1, undefined4 param_2, int param_3, ushort param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_renderSpriteLayer(undefined4 *param_1,undefined4 param_2,int param_3,ushort param_4)
{
  param_1[1] = param_2;
  *param_1 = 0;
  if (param_4 != 0x100) {
    param_1[2] = (uint)param_4 * param_3 >> 8;
    return 0;
  }
  param_1[2] = param_3;
  return 0;
}



// ============================================================
// Function: display_renderSpriteFrame (FUN_680f9e70)
// Address: 680f9e70
// Size: 64 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_renderSpriteFrame(int *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*param_1 == 0) {
    if ((uint)(param_2 - param_1[1]) < (uint)param_1[2]) {
      iVar2 = param_1[2] - (param_2 - param_1[1]);
      uVar1 = 0;
    }
    else {
      *param_1 = 1;
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 1;
  }
  if (param_3 != (int *)0x0) {
    *param_3 = iVar2;
  }
  return uVar1;
}



// ============================================================
// Function: display_setupFlashSprite (FUN_680f9eb0)
// Address: 680f9eb0
// Size: 374 bytes
// Params: int param_1, undefined4 * param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_setupFlashSprite(int param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  int local_c [2];
  
  iVar1 = playback_getSpriteData(param_1,param_2);
  if ((iVar1 != 0) && (*(int *)(iVar1 + 8) == 0xc)) {
    param_2[0x18] = 9;
    playback_renderSprite((int)param_2,iVar1,0);
    playback_renderSpriteData(param_1,param_2,(uint)(1 < *(uint *)(iVar1 + 0x9c)));
    if ((*(ushort *)(param_2 + 3) & 0x3f) != 0x20) {
      param_2[0x4c] = 0x100;
      if ((*(ushort *)(param_2 + 3) & 0x3f) == 0x24) {
        param_2[0x4b] = 2;
      }
      else {
        param_2[0x4b] = 0;
      }
    }
    if (*(char *)(iVar1 + 0x75) == '\x01') {
      Ordinal_1870(local_c);
      param_2[0x58] = local_c[0];
      param_2[0x56] = 1;
      param_2[0x5a] = param_2[0x34];
      param_2[0x5b] = param_2[0x33];
      param_2[0x59] = *(undefined4 *)(iVar1 + 0x80);
      if ((*(byte *)(param_2 + 0x14) & 2) == 0) {
        if (0 < local_c[0]) {
          if ((param_3 & 0xfffffff7) != 0) {
            param_2[0x13] = param_2[0x13] | 0x40;
            param_2[0x13] = param_2[0x13] | 0x80;
          }
          param_2[0x52] = param_2[0x32];
          param_2[0x53] = param_2[0x33];
          param_2[0x54] = param_2[0x34];
          param_2[0x55] = param_2[0x35];
        }
      }
      else {
        playback_getSpriteBounds(param_1,param_2);
      }
    }
    else {
      param_2[0x58] = 0;
      param_2[0x56] = 0;
    }
    if ((param_2[0x58] == 0) && (param_2[0x57] != 0)) {
      playback_getSpriteBounds(param_1,param_2);
    }
    param_2[0x13] = param_2[0x13] | 3;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: display_wrapGetSpriteBounds (FUN_680fa030)
// Address: 680fa030
// Size: 9 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_wrapGetSpriteBounds(int param_1,undefined4 *param_2)
{
  playback_getSpriteBounds(param_1,param_2);
  return 0;
}



// ============================================================
// Function: display_renderFlashSprite (FUN_680fa040)
// Address: 680fa040
// Size: 420 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_renderFlashSprite(int param_1,undefined4 param_2,undefined4 *param_3)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int local_34;
  int local_30;
  int local_2c [4];
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_30 = 0;
  local_34 = 0;
  piVar2 = (int *)playback_getSpriteData(param_1,param_3);
  if ((piVar2 == (int *)0x0) || (piVar2[2] != 0xc)) {
    local_30 = 1;
  }
  else {
    local_34 = rendering_getMemberData(param_1,piVar2);
    if (local_34 != 0) {
      iVar3 = Ordinal_1602(param_2);
      piVar1 = param_3 + 0x32;
      Ordinal_1608(param_2,piVar1);
      local_18 = param_3[0x4c];
      local_14 = param_3[0x4d];
      local_1c = param_3[0x4b];
      local_10 = param_3[0x4e];
      local_c = param_3[0x4f];
      if (local_1c == 2) {
LAB_680fa0fb:
        if (local_1c != 10) {
          local_1c = 4;
        }
      }
      else if (local_1c != 10) {
        Ordinal_1619(param_2,piVar1,piVar2 + 0x22);
        goto LAB_680fa0fb;
      }
      Ordinal_1060(local_2c,0,0,piVar2[0x25],piVar2[0x20]);
      if (piVar2[0x1e] != 0) {
        Ordinal_1064(local_2c,0,piVar2[0x1e]);
      }
      if (piVar2[0x28] == 0) {
        local_30 = 1;
      }
      else {
        local_30 = media_executeBlitOp(param_2,piVar1,(undefined1 *)0x0,local_2c,piVar2[0x28],&local_1c,
                                piVar2 + 0x21);
      }
      if (iVar3 != 0) {
        Ordinal_1603(param_2);
      }
    }
  }
  iVar3 = lingo_getMovieRef(*(int *)(param_1 + 0x18));
  if ((iVar3 != 0) || (local_30 != 0)) {
    iVar3 = Ordinal_1041();
    if (iVar3 == 0) goto LAB_680fa1bf;
  }
  iVar3 = Ordinal_1042();
  if (iVar3 == 0x66) {
    lingo_formatDebugMsg(*(int **)(param_1 + 0x18),-0x7d);
  }
  else {
    rendering_initMemberSlot(piVar2,-0x1b7);
  }
LAB_680fa1bf:
  if (local_34 != 0) {
    rendering_isStateValid((int)piVar2);
  }
  rendering_releaseMemberData(piVar2);
  return 0;
}



// ============================================================
// Function: display_applyRenderTransform (FUN_680fa1f0)
// Address: 680fa1f0
// Size: 30 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_applyRenderTransform(undefined4 param_1,undefined4 param_2,int param_3)
{
  Ordinal_1621(param_2,param_3 + 200);
  Ordinal_1042();
  return 0;
}



