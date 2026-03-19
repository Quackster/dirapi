// Module: display
// Topic: Cast member type handlers for sound, flash, picture, palette, and video
// Address range: 0x680f5600 - 0x680f7f60
// Functions (40):
//   display_loadSoundMedia
//   display_resolveSoundMedia
//   display_dispatchSoundEvent
//   display_readCuePointData
//   display_writeCuePointData
//   display_setSoundSampleRef
//   display_getSoundSampleInfo
//   display_readSoundHeader
//   display_writeSoundHeader
//   display_initMediaRef
//   display_getMediaDataRef
//   display_getCastMemberMedia
//   display_getCastMediaByFormat
//   display_loadAllCastMedia
//   display_setCastMemberMediaRef
//   display_setMediaRefAndUpdate
//   display_encodeMediaStream
//   display_getSoundProperty
//   display_setSoundProperty
//   display_dispatchSoundHandler
//   display_loadPictureMedia
//   display_getPictureMediaData
//   display_resolvePictureMedia
//   display_createPictureMediaCopy
//   display_getPictureProperty
//   display_setPictureProperty
//   display_dispatchPictureHandler
//   display_loadPaletteMedia
//   display_getPaletteMediaData
//   display_initDefaultPalette
//   display_resolvePaletteMedia
//   display_validatePaletteType
//   display_getPaletteProperty
//   display_setPaletteProperty
//   display_dispatchPaletteHandler
//   display_initVideoPlayback
//   display_loadVideoMedia
//   display_getVideoMediaLayout
//   display_resolveVideoMedia
//   display_clearMediaLoaded


// ============================================================
// Function: display_loadSoundMedia (FUN_680f5600)
// Address: 680f5600
// Size: 330 bytes
// Params: int param_1, int * param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_loadSoundMedia(int param_1,int *param_2,int param_3,int param_4)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  void *pvVar3;
  
  iVar2 = 0;
  if (*(int *)(in_EAX + 0x54) != 0) {
    if ((*(uint *)(in_EAX + 0x2c) & 0x400) == 0) {
      piVar1 = (int *)Ordinal_1114(*(int *)(in_EAX + 0x54));
      if (param_4 == 0) {
        iVar2 = scoreEngine_initScoreChannel(*(int *)(*(int *)(param_1 + 0x20) + 4),piVar1,1);
        if (iVar2 == 0) goto LAB_680f573c;
        *(int **)(in_EAX + 0x70) = piVar1;
      }
      else {
        playback_dispatchLifecycle((uint *)*piVar1,*(uint *)(param_1 + 0x24));
        *(int **)(in_EAX + 0x70) = piVar1;
      }
    }
    else {
      piVar1 = *(int **)(in_EAX + 0x70);
    }
    *(undefined4 *)(*piVar1 + 4) = 1;
    piVar1[0x19a] = 1;
    if (param_4 == 0) {
      pvVar3 = (void *)0x2;
      iVar2 = Ordinal_1313(param_2);
      if (iVar2 == 4) {
        pvVar3 = (void *)0x3;
      }
      iVar2 = playback_loadMediaChunk((void *)*piVar1,param_2,param_3,0,pvVar3);
      if (iVar2 == 1) {
        *(uint *)(in_EAX + 0x2c) = *(uint *)(in_EAX + 0x2c) & 0xfffffbff;
        iVar2 = 1;
        playback_createMediaBuffer(*piVar1,1);
        stage_renderFrame(piVar1[2],param_2);
        stage_getSpriteApiRef(piVar1[2],1);
        stage_updateProperty(piVar1[2],0);
      }
      else {
        if (iVar2 == 2) {
          *(uint *)(in_EAX + 0x2c) = *(uint *)(in_EAX + 0x2c) | 0x400;
          return 1;
        }
        *(uint *)(in_EAX + 0x2c) = *(uint *)(in_EAX + 0x2c) & 0xfffffbff;
        iVar2 = 0;
      }
    }
    scoreEngine_markDirty((int)piVar1,1);
    scoreEngine_setCastXtraFlag((int)piVar1,1);
    *(int *)(in_EAX + 0x58) = (int)*(short *)((int)piVar1 + 0x492);
    *(int *)(in_EAX + 0x60) = (int)*(short *)((int)piVar1 + 0x496);
    *(int *)(in_EAX + 0x5c) = (int)(short)piVar1[0x124];
    *(int *)(in_EAX + 100) = (int)(short)piVar1[0x125];
    if (iVar2 != 0) {
      return iVar2;
    }
  }
LAB_680f573c:
  display_releaseMovieMember();
  return 0;
}



// ============================================================
// Function: display_resolveSoundMedia (FUN_680f5750)
// Address: 680f5750
// Size: 329 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_resolveSoundMedia(void)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *unaff_ESI;
  int unaff_EDI;
  int local_424;
  int local_420 [262];
  uint local_8;
  
  piVar1 = *(int **)(unaff_EDI + 0x18);
  iVar3 = 0;
  local_424 = 0;
  if ((unaff_ESI[0x15] != 0) && ((unaff_ESI[0xb] & 0x400U) == 0)) {
    iVar3 = 1;
    goto LAB_680f5877;
  }
  iVar2 = rendering_dispatchUpdate(*(int *)(unaff_EDI + 0x20),unaff_ESI,local_420,0);
  if (iVar2 == 0) {
LAB_680f57d1:
    iVar2 = rendering_dispatchUpdate(*(int *)(unaff_EDI + 0x20),unaff_ESI,local_420,1);
    if (iVar2 == 0) {
      lingo_callMethodEx(piVar1,-0x1ac,local_420);
      goto LAB_680f5877;
    }
  }
  else {
    iVar2 = media_getDataPtr(*(int **)(*(int *)(unaff_EDI + 0x18) + 4));
    if (*(code **)(iVar2 + 8) == (code *)0x0) goto LAB_680f57d1;
    iVar2 = (**(code **)(iVar2 + 8))(local_420,local_420,&local_424,0,0);
    if (iVar2 == 0) goto LAB_680f57d1;
  }
  if ((unaff_ESI[0xb] & 0x400U) == 0) {
    iVar2 = lingo_setPropertyWrapped(piVar1,local_420);
    if (iVar2 == 0) {
      iVar2 = Ordinal_1111(0xbb0,1);
      unaff_ESI[0x15] = iVar2;
      if (iVar2 == 0) goto LAB_680f5877;
      goto LAB_680f583f;
    }
    iVar3 = 1;
    unaff_ESI[0x15] = iVar2;
  }
  else {
LAB_680f583f:
    iVar3 = 0;
  }
  iVar3 = display_loadSoundMedia(unaff_EDI,local_420,local_424,iVar3);
  if ((iVar3 != 0) && ((unaff_ESI[0xb] & 0x400U) == 0)) {
    stage_updateProperty(*(int *)(unaff_ESI[0x1c] + 8),0);
  }
LAB_680f5877:
  unaff_ESI[0xb] = unaff_ESI[0xb] ^ (iVar3 << 9 ^ unaff_ESI[0xb]) & 0x200U;
  return 0;
}



// ============================================================
// Function: display_dispatchSoundEvent (FUN_680f58a0)
// Address: 680f58a0
// Size: 389 bytes
// Params: void * this, int * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall display_dispatchSoundEvent(void *this,int *param_1)
{
  int *piVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  uint local_8;
  
  piVar1 = (int *)*param_1;
  switch(param_1[2]) {
  case 0:
    param_1[6] = 1;
    iVar2 = display_initMovieMember((undefined4 *)param_1[5]);
    if (iVar2 == 0) goto LAB_680f5a10;
  default:
    goto switchD_680f58c9_caseD_1;
  case CMTYPE_TEXT_FIELD:
    piVar1[0xb] = piVar1[0xb] & 0xfffff9ff;
    piVar1[0x15] = 0;
    piVar1[0x1c] = 0;
    break;
  case CMTYPE_PICTURE:
    iVar2 = display_resolveSoundMedia();
    goto LAB_680f58f0;
  case CMTYPE_SOUND:
  case CMTYPE_BUTTON:
    break;
  case CMTYPE_SHAPE:
    display_releaseMovieMember();
    break;
  case CMTYPE_MOVIE:
    if ((piVar1[0xb] & 0x200U) != 0) goto switchD_680f58c9_caseD_a;
    param_1[3] = 0;
    goto switchD_680f58c9_caseD_1;
  case CMTYPE_DIGITAL_VIDEO:
switchD_680f58c9_caseD_a:
    iVar2 = rendering_getMemberDataRef(param_1[1],piVar1);
    param_1[3] = iVar2;
    break;
  case CMTYPE_TEXT_RICH:
    display_resetMovieMemberFields();
    break;
  case CMTYPE_OLE:
    param_1[3] = 0x15;
    break;
  case CMTYPE_TRANSITION:
    param_1[3] = 0x12;
    break;
  case CMTYPE_XTRA:
    display_readSpriteRect();
    break;
  case CMTYPE_SWA:
    display_writeMovieStream();
    break;
  case 0x19:
    iVar2 = display_getPaletteMemberProperty(this,param_1);
    goto LAB_680f598e;
  case 0x1a:
    iVar2 = display_setPaletteMemberProperty(this,param_1);
LAB_680f598e:
    if ((iVar2 != 0) || (iVar2 = display_dispatchSpriteMessage(param_1), iVar2 != 0)) break;
switchD_680f58c9_caseD_1:
    iVar2 = rendering_validateState(param_1);
LAB_680f58f0:
    if (iVar2 == 0) {
LAB_680f5a10:
      return 0;
    }
    break;
  case 0x1c:
    param_1[3] = 0;
    iVar2 = rendering_getMemberData(param_1[1],piVar1);
    if (iVar2 != 0) {
      iVar2 = media_isScoreLocked(*(int **)(*(int *)piVar1[0x1c] + 0x28));
      local_10 = 1;
      local_18 = 0;
      local_14 = 0;
      scoreEngine_initScoreData((int *)piVar1[0x1c],*(int **)(*(int *)piVar1[0x1c] + 0x28),1,1,iVar2,scoreEngine_readChannelWithBlend
                   ,&local_18);
      rendering_isStateValid((int)piVar1);
      param_1[3] = local_10;
    }
  }
  return 0;
}



// ============================================================
// Function: display_readCuePointData (FUN_680f5a90)
// Address: 680f5a90
// Size: 256 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_readCuePointData(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  uint uVar6;
  
  if ((param_1 == (undefined4 *)0x0) || (param_1[2] != 6)) {
    rendering_initMemberSlot(param_1,-0x79);
    return 0;
  }
  iVar2 = Ordinal_1414(param_2);
  if ((((iVar2 != 0) && (iVar2 - 1U < 0x6666666)) &&
      (uVar6 = (iVar2 - 1U) * 0x28, uVar6 < 0xffffffb3)) && (iVar3 = uVar6 + 0x4c, iVar3 != -1)) {
    uVar4 = Ordinal_1111(iVar3,1);
    iVar3 = Ordinal_1114(uVar4);
    if (iVar3 == 0) {
      return 0;
    }
    *(int *)(iVar3 + 0x1c) = iVar2;
    uVar6 = 0;
    iVar1 = iVar3;
    if (iVar2 != 0) {
      do {
        uVar5 = Ordinal_1414(param_2);
        *(undefined4 *)(iVar1 + 0x24) = uVar5;
        Ordinal_1409(param_2,iVar1 + 0x28,0x20);
        uVar6 = uVar6 + 1;
        iVar1 = iVar1 + 0x28;
      } while (uVar6 < *(uint *)(iVar3 + 0x1c));
    }
    iVar2 = Ordinal_1115(uVar4);
    param_1[0x17] = uVar4;
    if (iVar2 != 0) {
      Ordinal_1115(uVar4);
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: display_writeCuePointData (FUN_680f5b90)
// Address: 680f5b90
// Size: 135 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_writeCuePointData(int param_1,int *param_2)

{
  int iVar1;
  int unaff_EBX;
  undefined4 local_8;
  
  iVar1 = Ordinal_1114(*(undefined4 *)(param_1 + 0x5c));
  if (iVar1 != 0) {
    if (unaff_EBX != 0) {
      Ordinal_1425();
      local_8 = 0;
      if (*(int *)(iVar1 + 0x1c) != 0) {
        do {
          Ordinal_1425();
          Ordinal_1420();
          local_8 = local_8 + 1;
        } while (local_8 < *(uint *)(iVar1 + 0x1c));
      }
    }
    if (param_2 != (int *)0x0) {
      *param_2 = *(int *)(iVar1 + 0x1c) * 0x24 + 4;
    }
    Ordinal_1115(*(undefined4 *)(param_1 + 0x5c));
  }
  return 1;
}



// ============================================================
// Function: display_setSoundSampleRef (FUN_680f5c20)
// Address: 680f5c20
// Size: 54 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool display_setSoundSampleRef(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x60) != 0) {
    uVar1 = Ordinal_1114(*(int *)(unaff_ESI + 0x60));
    uVar1 = Ordinal_1934(param_1,param_2,uVar1);
    *(undefined4 *)(unaff_ESI + 0x54) = uVar1;
    Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x60));
  }
  return *(int *)(unaff_ESI + 0x54) != 0;
}



// ============================================================
// Function: display_getSoundSampleInfo (FUN_680f5c60)
// Address: 680f5c60
// Size: 73 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool display_getSoundSampleInfo(void)

{
  undefined4 *in_EAX;
  undefined4 uVar1;
  int iVar2;
  int unaff_EBX;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x60) != 0) {
    if (in_EAX != (undefined4 *)0x0) {
      uVar1 = Ordinal_1116(*(undefined4 *)(unaff_ESI + 0x54));
      *in_EAX = uVar1;
    }
    if (unaff_EBX != 0) {
      iVar2 = Ordinal_1114(*(undefined4 *)(unaff_ESI + 0x60));
      Ordinal_1935();
      if (iVar2 != 0) {
        Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x60));
      }
    }
  }
  return *(int *)(unaff_ESI + 0x54) != 0;
}



// ============================================================
// Function: display_readSoundHeader (FUN_680f5cb0)
// Address: 680f5cb0
// Size: 369 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_readSoundHeader(int param_1)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  
  iVar2 = Ordinal_1111(0x164,1);
  *(int *)(param_1 + 0x60) = iVar2;
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)Ordinal_1114(iVar2);
    uVar4 = Ordinal_1414();
    *puVar3 = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[1] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[2] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[3] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[4] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[5] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[6] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[7] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[8] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[9] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[10] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[0xb] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[0xc] = uVar4;
    iVar2 = puVar3[7];
    if (((int)puVar3[9] < iVar2) && (iVar2 == puVar3[10])) {
      uVar4 = puVar3[6];
      puVar3[6] = puVar3[8];
      puVar3[7] = puVar3[9];
      puVar3[8] = uVar4;
      puVar3[9] = iVar2;
    }
    uVar4 = Ordinal_1414();
    puVar3[0xd] = uVar4;
    uVar1 = Ordinal_1412();
    *(undefined2 *)(puVar3 + 0xe) = uVar1;
    uVar1 = Ordinal_1412();
    *(undefined2 *)((int)puVar3 + 0x3a) = uVar1;
    Ordinal_1409();
    uVar4 = Ordinal_1414();
    puVar3[0x11] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[0x12] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[0x13] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[0x14] = uVar4;
    uVar4 = Ordinal_1414();
    puVar3[0x15] = uVar4;
    uVar1 = Ordinal_1412();
    *(undefined2 *)(puVar3 + 0x16) = uVar1;
    uVar1 = Ordinal_1412();
    *(undefined2 *)((int)puVar3 + 0x5a) = uVar1;
    Ordinal_1409();
    iVar2 = puVar3[10] * puVar3[0x14];
    puVar3[2] = 0;
    puVar3[8] = iVar2;
    if (iVar2 < (int)puVar3[6]) {
      puVar3[6] = iVar2;
    }
    *puVar3 = 0;
    Ordinal_1115(*(undefined4 *)(param_1 + 0x60));
    return 1;
  }
  return 0;
}




// ============================================================
// Function: display_writeSoundHeader (FUN_680f5e30)
// Address: 680f5e30
// Size: 340 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_writeSoundHeader(int param_1,undefined4 *param_2)

{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = Ordinal_1114(*(undefined4 *)(param_1 + 0x60));
  if (iVar1 != 0) {
    if (unaff_EDI != 0) {
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1423();
      Ordinal_1423();
      Ordinal_1420();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1425();
      Ordinal_1423();
      Ordinal_1423();
      Ordinal_1420();
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = 100;
    }
    Ordinal_1115(*(undefined4 *)(param_1 + 0x60));
    return 1;
  }
  return 0;
}



// ============================================================
// Function: display_initMediaRef (FUN_680f5f90)
// Address: 680f5f90
// Size: 116 bytes
// Params: undefined4 param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool display_initMediaRef(undefined4 param_1)

{
  int in_EAX;
  undefined4 uVar1;
  int iVar2;
  undefined4 unaff_EDI;
  int local_8;
  
  local_8 = 0;
  uVar1 = rendering_getMediaState(in_EAX);
  iVar2 = Ordinal_1927(param_1,uVar1);
  *(int *)(in_EAX + 0x54) = iVar2;
  *(undefined4 *)(in_EAX + 0x58) = unaff_EDI;
  *(undefined4 *)(in_EAX + 0x60) = 0;
  if (local_8 != 0) {
    Ordinal_1113((undefined4 *)(in_EAX + 0x5c));
    uVar1 = Ordinal_1112(local_8);
    *(undefined4 *)(in_EAX + 0x5c) = uVar1;
  }
  Ordinal_1113(&local_8);
  return iVar2 != 0;
}



// ============================================================
// Function: display_getMediaDataRef (FUN_680f6010)
// Address: 680f6010
// Size: 42 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getMediaDataRef(void)

{
  undefined4 uVar1;
  int unaff_EBX;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  uVar1 = 0;
  if (*(int *)(unaff_ESI + 0x54) != 0) {
    if (unaff_EDI != (undefined4 *)0x0) {
      uVar1 = Ordinal_1929(*(int *)(unaff_ESI + 0x54));
      *unaff_EDI = uVar1;
    }
    if (unaff_EBX != 0) {
      uVar1 = Ordinal_1928();
      return uVar1;
    }
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: display_getCastMemberMedia (FUN_680f6040)
// Address: 680f6040
// Size: 205 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall display_getCastMemberMedia(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  bool bVar1;
  uint in_EAX;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar2;
  
  uVar2 = 0;
  if ((param_2 == (undefined4 *)0x0) || (param_2[2] != 6)) {
    rendering_initMemberSlot(param_2,-0x79);
    return 0;
  }
  if (FOURCC_snd < in_EAX) {
    if (in_EAX == FOURCC_sndH) {
      uVar2 = display_readSoundHeader((int)param_2);
    }
    else if (in_EAX == FOURCC_sndS) {
      bVar1 = display_setSoundSampleRef(param_1,param_3);
      Ordinal_1042();
      return CONCAT31(extraout_var_00,bVar1);
    }
    Ordinal_1042();
    return uVar2;
  }
  if (in_EAX == FOURCC_snd) {
    rendering_setMemberSlot((int)param_2,"kMoaCfFormat_snd");
  }
  else {
    if (in_EAX == FOURCC_cupt) {
      uVar2 = display_readCuePointData(param_2,param_1);
      Ordinal_1042();
      return uVar2;
    }
    if (in_EAX != FOURCC_ediM) {
      Ordinal_1042();
      return 0;
    }
  }
  bVar1 = display_initMediaRef(param_1);
  Ordinal_1042();
  return CONCAT31(extraout_var,bVar1);
}



// ============================================================
// Function: display_getCastMediaByFormat (FUN_680f6110)
// Address: 680f6110
// Size: 298 bytes
// Params: void * this, uint param_1
// Return: uint
// Calling convention: __thiscall
// ============================================================

uint __thiscall display_getCastMediaByFormat(void *this,uint param_1)

{
  bool bVar1;
  int *in_EAX;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  
  uVar3 = 0;
  if (in_EAX != (int *)0x0) {
    *in_EAX = 0;
  }
  if ((this == (void *)0x0) || (*(int *)((int)this + 8) != 6)) {
    rendering_initMemberSlot(this,-0x79);
    return 0;
  }
  iVar2 = Ordinal_1114(*(undefined4 *)((int)this + 0x60));
  if (iVar2 == 0) {
    return 1;
  }
  if (param_1 < FOURCC_sndE) {
    if (param_1 == FOURCC_snd) {
      if (in_EAX != (int *)0x0) {
        *in_EAX = 0;
      }
    }
    else if (param_1 == FOURCC_cupt) {
      iVar2 = Ordinal_2066(iVar2 + 0x34,&DAT_68175b38);
      if (iVar2 != 0) {
        uVar3 = display_writeCuePointData((int)this,in_EAX);
        goto LAB_680f61b9;
      }
    }
    else {
      if (param_1 != FOURCC_ediM) goto LAB_680f61b9;
      iVar2 = Ordinal_2066(iVar2 + 0x34,&DAT_68175b38);
      if (iVar2 == 0) {
        uVar3 = display_getMediaDataRef();
        goto LAB_680f61b9;
      }
    }
  }
  else if (param_1 == FOURCC_sndH) {
    iVar2 = Ordinal_2066(iVar2 + 0x34,&DAT_68175b38);
    if (iVar2 != 0) {
      uVar3 = display_writeSoundHeader((int)this,in_EAX);
      goto LAB_680f61b9;
    }
  }
  else {
    if (param_1 != FOURCC_sndS) goto LAB_680f61b9;
    iVar2 = Ordinal_2066(iVar2 + 0x34,&DAT_68175b38);
    if (iVar2 != 0) {
      bVar1 = display_getSoundSampleInfo();
      uVar3 = CONCAT31(extraout_var,bVar1);
      goto LAB_680f61b9;
    }
  }
  uVar3 = 1;
LAB_680f61b9:
  iVar2 = Ordinal_1042();
  if (iVar2 != 0) {
    rendering_initMemberSlot(this,-0x7c);
  }
  Ordinal_1115(*(undefined4 *)((int)this + 0x60));
  return uVar3;
}



// ============================================================
// Function: display_loadAllCastMedia (FUN_680f6240)
// Address: 680f6240
// Size: 578 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_loadAllCastMedia(int param_1)

{
  int *piVar1;
  ushort uVar2;
  int iVar3;
  undefined4 uVar4;
  int *unaff_ESI;
  uint uVar5;
  int *piVar6;
  int local_8;
  
  uVar5 = 0;
  if ((unaff_ESI == (int *)0x0) || (unaff_ESI[2] != 6)) goto LAB_680f6442;
  iVar3 = rendering_getFrameCount((int)unaff_ESI);
  if (iVar3 != 0) {
    uVar2 = rendering_getChannelType(*(int *)(param_1 + 0x20) + 0x48c);
    if (uVar2 < 0x582) {
      rendering_setStateFlag((int)unaff_ESI,4);
    }
    return 1;
  }
  uVar4 = rendering_getMediaState((int)unaff_ESI);
  if (unaff_ESI[0x15] != 0) goto LAB_680f646e;
  param_1 = 0;
  iVar3 = rendering_updateMemberState(unaff_ESI,FOURCC_cupt,&local_8,&param_1,(int *)0x0);
  if ((iVar3 == 1) && (local_8 != 0)) {
    display_getCastMemberMedia(param_1,unaff_ESI,local_8);
  }
  Ordinal_1407(&param_1);
  iVar3 = rendering_updateMemberState(unaff_ESI,FOURCC_sndH,&local_8,&param_1,(int *)0x0);
  if ((iVar3 == 1) && (local_8 != 0)) {
    uVar5 = display_getCastMemberMedia(param_1,unaff_ESI,local_8);
  }
  Ordinal_1407(&param_1);
  piVar1 = unaff_ESI + 0x18;
  if (unaff_ESI[0x18] != 0) {
    iVar3 = rendering_updateMemberState(unaff_ESI,FOURCC_sndS,&local_8,&param_1,(int *)0x0);
    if ((iVar3 == 1) && (local_8 != 0)) {
      uVar5 = display_getCastMemberMedia(param_1,unaff_ESI,local_8);
    }
    else {
      Ordinal_1113(piVar1);
      uVar5 = 0;
    }
    Ordinal_1407(&param_1);
  }
  if (uVar5 != 0) goto LAB_680f646e;
  iVar3 = rendering_updateMemberState(unaff_ESI,FOURCC_ediM,&local_8,&param_1,(int *)0x0);
  if ((iVar3 == 1) && (local_8 != 0)) {
LAB_680f63dc:
    uVar5 = display_getCastMemberMedia(param_1,unaff_ESI,local_8);
  }
  else {
    if (param_1 != 0) {
      Ordinal_1407(&param_1);
    }
    iVar3 = rendering_updateMemberState(unaff_ESI,FOURCC_snd,&local_8,&param_1,(int *)0x0);
    uVar5 = (uint)(iVar3 == 1);
    if ((uVar5 != 0) && (local_8 != 0)) goto LAB_680f63dc;
  }
  Ordinal_1407(&param_1);
  if (uVar5 != 0) {
    if (*piVar1 != 0) {
LAB_680f646e:
      unaff_ESI[0xb] = unaff_ESI[0xb] | 0x200;
      return 1;
    }
    iVar3 = Ordinal_1111(0x164,1);
    *piVar1 = iVar3;
    iVar3 = Ordinal_1114(iVar3);
    if (iVar3 != 0) {
      piVar6 = unaff_ESI + 0x17;
      if (unaff_ESI[0x17] != 0) {
        piVar6 = (int *)0x0;
      }
      iVar3 = Ordinal_1922(iVar3,unaff_ESI[0x15],uVar4,piVar6);
      Ordinal_1115(*piVar1);
      if (iVar3 != 0) goto LAB_680f646e;
      Ordinal_1113(piVar1);
    }
  }
LAB_680f6442:
  Ordinal_1113(unaff_ESI + 0x15);
  Ordinal_1113(unaff_ESI + 0x17);
  Ordinal_1113(unaff_ESI + 0x18);
  unaff_ESI[0x16] = 0;
  return 0;
}



// ============================================================
// Function: display_setCastMemberMediaRef (FUN_680f6490)
// Address: 680f6490
// Size: 148 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_setCastMemberMediaRef(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int in_EAX;
  undefined4 uVar2;
  int iVar3;
  
  Ordinal_1113((undefined4 *)(in_EAX + 0x54));
  puVar1 = (undefined4 *)(in_EAX + 0x60);
  Ordinal_1113(puVar1);
  Ordinal_1113(in_EAX + 0x5c);
  uVar2 = Ordinal_1112(param_1);
  *(undefined4 *)(in_EAX + 0x54) = uVar2;
  uVar2 = Ordinal_1116(param_1);
  *(undefined4 *)(in_EAX + 0x58) = uVar2;
  uVar2 = Ordinal_1112(param_2);
  *puVar1 = uVar2;
  uVar2 = Ordinal_1112(param_3);
  *(undefined4 *)(in_EAX + 0x5c) = uVar2;
  iVar3 = Ordinal_1114(*puVar1);
  if (iVar3 != 0) {
    iVar3 = Ordinal_2066(iVar3 + 0x34,&DAT_68175b38);
    if (iVar3 == 0) {
      Ordinal_1113((undefined4 *)(in_EAX + 0x28));
      uVar2 = Ordinal_1112(param_1);
      *(undefined4 *)(in_EAX + 0x28) = uVar2;
    }
    Ordinal_1115(*puVar1);
  }
  return 1;
}



// ============================================================
// Function: display_setMediaRefAndUpdate (FUN_680f6530)
// Address: 680f6530
// Size: 136 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_setMediaRefAndUpdate(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EDI;
  
  uVar2 = 0;
  iVar3 = 0;
  iVar1 = display_setCastMemberMediaRef(param_1,param_2,param_3);
  if (iVar1 != 0) {
    rendering_setStateFlag(unaff_EDI,4);
    iVar3 = Ordinal_1114(*(undefined4 *)(unaff_EDI + 0x60));
    if ((iVar3 == 0) || ((*(int *)(iVar3 + 0x10) == 0 && (*(int *)(iVar3 + 0x18) == 0)))) {
      rendering_setStateFlag(unaff_EDI,4);
    }
    else {
      rendering_clearStateFlag(unaff_EDI,4);
    }
    uVar2 = 1;
  }
  Ordinal_1113(&param_1);
  Ordinal_1113(&param_2);
  Ordinal_1113(&param_3);
  if (iVar3 != 0) {
    Ordinal_1115(*(undefined4 *)(unaff_EDI + 0x60));
  }
  return uVar2;
}



// ============================================================
// Function: display_encodeMediaStream (FUN_680f65c0)
// Address: 680f65c0
// Size: 263 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall display_encodeMediaStream(void *this,undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  int unaff_EDI;
  undefined4 local_424;
  undefined4 local_420;
  undefined1 local_41c [1044];
  uint local_8;
  
  local_424 = 0;
  iVar1 = rendering_getFrameCount((int)unaff_ESI);
  if (iVar1 == 0) goto LAB_680f66a8;
  local_420 = 0;
  memset(local_41c,0,0x414);
  iVar1 = rendering_dispatchUpdate(*(int *)(unaff_EDI + 0x20),unaff_ESI,&local_420,1);
  if (iVar1 == 0) goto LAB_680f66a8;
  if (unaff_ESI[8] == 0) {
    iVar1 = Ordinal_1402(&local_424,&local_420,1);
LAB_680f667b:
    if (iVar1 == 0) goto LAB_680f66a8;
  }
  else {
    iVar1 = Ordinal_1405(&local_424,unaff_ESI[8],1);
    if (iVar1 == 0) {
      Ordinal_1407(&local_424);
      iVar1 = Ordinal_1405(&local_424,unaff_ESI[8],1,0);
      goto LAB_680f667b;
    }
  }
  uVar2 = Ordinal_1330(&local_420,this);
  Ordinal_1923(param_1,&local_424,uVar2);
LAB_680f66a8:
  Ordinal_1407(&local_424);
  return 0;
}




// ============================================================
// Function: display_getSoundProperty (FUN_680f66d0)
// Address: 680f66d0
// Size: 751 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall display_getSoundProperty(undefined4 *param_1)
{
  int *piVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  undefined8 uVar7;
  ulonglong uVar8;
  uint *local_184;
  uint local_180;
  int local_17c;
  int *local_178;
  undefined1 *local_174;
  uint *local_170;
  undefined1 local_16c [68];
  uint local_128;
  uint local_8;
  
  local_170 = (uint *)param_1[4];
  piVar1 = (int *)*param_1;
  local_180 = 0;
  local_178 = (int *)0x0;
  local_174 = (undefined1 *)0x0;
  local_17c = 0;
  local_184 = (uint *)0x0;
  if (piVar1[2] != 6) goto LAB_680f699a;
  iVar2 = rendering_getMemberData(param_1[1],piVar1);
  if (iVar2 == 0) goto switchD_680f67a9_caseD_31;
  if (param_1[3] == 0x79) {
    if (piVar1[0x17] == 0) {
      local_184 = &local_180;
    }
    else {
      local_180 = Ordinal_1120(piVar1[0x17],0);
    }
  }
  if (piVar1[0x18] == 0) {
    iVar4 = display_encodeMediaStream(local_184,local_16c);
    if (iVar4 == 0) goto switchD_680f67a9_caseD_31;
    puVar3 = local_16c;
  }
  else {
    puVar3 = (undefined1 *)Ordinal_1114(piVar1[0x18]);
  }
  local_174 = puVar3;
  switch(param_1[3]) {
  case 0x2f:
    uVar6 = rendering_getRawStateFlags((int)piVar1);
    *local_170 = ~(uVar6 >> 4) & 1;
    break;
  case 0x30:
    uVar7 = Ordinal_2066(puVar3 + 0x34,&DAT_68175b38);
    if ((int)uVar7 != 0) {
      uVar8 = strings_floatToUint64(extraout_ECX,(int)((ulonglong)uVar7 >> 0x20));
      *local_170 = (uint)uVar8;
      break;
    }
    uVar5 = Ordinal_1038(&DAT_68176558,&DAT_68176568,&local_178);
    iVar4 = Ordinal_2063(uVar5);
    if (iVar4 == 0) {
      uVar7 = (**(code **)(*local_178 + 0x20))(local_178,puVar3 + 0x34,local_174,local_16c);
      if ((int)uVar7 == 0) {
        uVar8 = strings_floatToUint64(local_174,(int)((ulonglong)uVar7 >> 0x20));
        *local_170 = (uint)uVar8;
        break;
      }
    }
  default:
    goto switchD_680f67a9_caseD_31;
  case 0x44:
    uVar6 = rendering_getMediaState((int)piVar1);
    *local_170 = uVar6;
    local_170[1] = piVar1[0x15];
    local_170[2] = piVar1[0x18];
    local_170[3] = piVar1[0x17];
    break;
  case 0x45:
    *local_170 = *(uint *)(puVar3 + 0x4c);
    break;
  case 0x46:
    *local_170 = *(uint *)(puVar3 + 0x2c);
    break;
  case 0x47:
    iVar4 = Ordinal_2066(puVar3 + 0x34,&DAT_68175b38);
    if (iVar4 == 0) {
      uVar5 = Ordinal_1038(&DAT_68176558,&DAT_68176568,&local_178);
      iVar4 = Ordinal_2063(uVar5);
      if ((iVar4 != 0) ||
         (iVar4 = (**(code **)(*local_178 + 0x20))(local_178,puVar3 + 0x34,local_174,local_16c),
         iVar4 != 0)) goto switchD_680f67a9_caseD_31;
      *local_170 = local_128;
    }
    else {
      *local_170 = *(uint *)(puVar3 + 0x44);
    }
    break;
  case 0x79:
    *local_170 = local_180;
  }
  local_17c = 1;
switchD_680f67a9_caseD_31:
  if (local_178 != (int *)0x0) {
    (**(code **)(*local_178 + 8))(local_178);
    local_178 = (int *)0x0;
  }
  if (iVar2 != 0) {
    rendering_isStateValid((int)piVar1);
  }
  if ((local_174 != (undefined1 *)0x0) && (piVar1[0x18] != 0)) {
    Ordinal_1115(piVar1[0x18]);
  }
  if (local_17c == 0) {
LAB_680f699a:
    Ordinal_1130(local_170,0x18);
  }
  return 0;
}



// ============================================================
// Function: display_setSoundProperty (FUN_680f6a30)
// Address: 680f6a30
// Size: 232 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_setSoundProperty(void)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *in_EAX;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_1c;
  int local_18;
  byte local_14;
  undefined3 uStack_13;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = in_EAX[1];
  piVar2 = (int *)*in_EAX;
  local_8 = 0;
  local_18 = 0;
  local_c = 0;
  local_10 = 0;
  piVar3 = (int *)in_EAX[4];
  local_14 = 1;
  local_1c = 0;
  if (piVar2[2] != 6) goto LAB_680f6aea;
  if (in_EAX[3] == 0x2f) {
    if (*piVar3 == 0) {
      rendering_setStateFlag((int)piVar2,4);
    }
    else {
      rendering_clearStateFlag((int)piVar2,4);
    }
  }
  else {
    if (in_EAX[3] != 0x44) goto LAB_680f6aea;
    iVar4 = Ordinal_1404(&local_8,piVar3[1],1);
    if (iVar4 == 0) goto LAB_680f6aea;
    uVar5 = Ordinal_1435(local_8,&local_c,&local_10);
    local_18 = Ordinal_1927(local_8,*piVar3,uVar5);
    if (local_18 == 0) goto LAB_680f6aea;
    iVar4 = display_setCastMemberMediaRef(local_18,local_c,local_10);
    if (iVar4 == 0) goto LAB_680f6aea;
    local_14 = 2;
  }
  rendering_setMemberData(iVar1,piVar2,local_14);
  local_1c = 1;
LAB_680f6aea:
  Ordinal_1407(&local_8);
  Ordinal_1113(&local_18);
  Ordinal_1113(&local_c);
  Ordinal_1113(&local_10);
  return local_1c;
}



// ============================================================
// Function: display_dispatchSoundHandler (FUN_680f6b20)
// Address: 680f6b20
// Size: 1069 bytes
// Params: undefined4 * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_dispatchSoundHandler(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *this;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint local_14;
  int local_10;
  int local_c;
  int local_8;
  
  puVar2 = param_1;
  puVar1 = param_1 + 2;
  this = (int *)*param_1;
  local_10 = 0;
  local_8 = 0;
  local_c = 0;
  param_1 = (undefined4 *)0x0;
  switch(*puVar1) {
  case 0:
    iVar7 = display_setMediaRefAndUpdate(puVar2[4],puVar2[7],puVar2[8]);
    if (iVar7 == 0) goto LAB_680f6b7c;
  default:
    goto switchD_680f6b4d_caseD_1;
  case CMTYPE_TEXT_FIELD:
    if (this[0x15] != 0) {
      iVar7 = Ordinal_1120(this[0x15],0);
      this[0x15] = iVar7;
      if (iVar7 == 0) goto LAB_680f6b7c;
    }
    if (this[0x18] != 0) {
      iVar7 = Ordinal_1120(this[0x18],0);
      this[0x18] = iVar7;
      if (iVar7 == 0) goto LAB_680f6b7c;
    }
    if (this[0x17] != 0) {
      uVar3 = Ordinal_1120(this[0x17],0);
      this[0x17] = uVar3;
      goto LAB_680f6b73;
    }
    break;
  case CMTYPE_PICTURE:
    uVar3 = display_loadAllCastMedia(puVar2[1]);
    goto LAB_680f6b73;
  case CMTYPE_SOUND:
    uVar3 = display_getCastMemberMedia(puVar2[4],this,puVar2[6]);
    goto LAB_680f6b73;
  case CMTYPE_BUTTON:
    uVar3 = 0;
    do {
      if (puVar2[5] == *(uint *)("Midetpuc dnsHdnsSdns" + uVar3)) {
        uVar3 = display_getCastMediaByFormat(this,puVar2[5]);
        goto LAB_680f6b73;
      }
      uVar3 = uVar3 + 4;
    } while (uVar3 < 0x14);
    goto switchD_680f6b4d_caseD_1;
  case CMTYPE_SHAPE:
    Ordinal_1113(this + 0x15);
    Ordinal_1113(this + 0x17);
    Ordinal_1113(this + 0x18);
    this[0xb] = this[0xb] & 0xfffffdff;
    this[0x16] = 0;
    break;
  case CMTYPE_MOVIE:
    iVar7 = Ordinal_1116(this[0x18]);
    iVar6 = Ordinal_1116(this[0x17]);
    iVar4 = Ordinal_1116(this[0x15]);
    puVar2[3] = iVar4 + iVar7 + iVar6;
switchD_680f6b4d_caseD_1:
    uVar3 = rendering_validateState(puVar2);
LAB_680f6b73:
    if (uVar3 == 0) goto LAB_680f6b7c;
    break;
  case CMTYPE_DIGITAL_VIDEO:
    iVar7 = rendering_getFrameCount((int)this);
    if (iVar7 == 0) {
      if (this[0x16] == 0) {
        piVar8 = puVar2 + 3;
        rendering_updateMemberState(this,FOURCC_snd,piVar8,(undefined4 *)0x0,(int *)0x0);
        if ((*piVar8 == 0) &&
           (rendering_updateMemberState(this,FOURCC_ediM,piVar8,(undefined4 *)0x0,(int *)0x0), *piVar8 == 0)) {
          param_1 = (undefined4 *)0x0;
          rendering_updateMemberState(this,FOURCC_sndH,(int *)&param_1,(undefined4 *)0x0,(int *)0x0);
          *piVar8 = *piVar8 + (int)param_1;
          rendering_updateMemberState(this,FOURCC_sndS,(int *)&param_1,(undefined4 *)0x0,(int *)0x0);
          *piVar8 = *piVar8 + (int)param_1;
          rendering_updateMemberState(this,FOURCC_cupt,(int *)&param_1,(undefined4 *)0x0,(int *)0x0);
          *piVar8 = *piVar8 + (int)param_1;
        }
      }
      else {
        puVar2[3] = this[0x16];
      }
    }
    else {
      uVar5 = rendering_getMemberDataRef(puVar2[1],this);
      puVar2[3] = uVar5;
    }
    break;
  case CMTYPE_SCRIPT:
    iVar7 = rendering_getFrameCount((int)this);
    if (iVar7 == 0) {
      iVar7 = this[0x17];
      iVar6 = this[0x18];
      iVar4 = this[0x15];
      uVar5 = rendering_getMediaState((int)this);
      uVar3 = Ordinal_2012(uVar5,iVar4,iVar6,iVar7);
      goto LAB_680f6b73;
    }
    break;
  case CMTYPE_TEXT_RICH:
    iVar7 = rendering_getFrameCount((int)this);
    if (iVar7 == 0) {
      local_10 = Ordinal_2006(&local_14,&local_8,&local_c);
      this[0x15] = 0;
      this[0x18] = 0;
      this[0x17] = 0;
      iVar7 = display_setCastMemberMediaRef(local_10,local_8,local_c);
      if (iVar7 == 0) goto LAB_680f6b7c;
      rendering_getMediaRef((int)this,local_14);
    }
    break;
  case CMTYPE_OLE:
    puVar2[3] = 4;
    break;
  case CMTYPE_VECTOR:
    puVar2[3] = 5;
    break;
  case CMTYPE_FLASH:
    uVar3 = 0;
    do {
      iVar7 = crt_negotiateFormat(puVar2 + 4,puVar2[3],*(int *)("Midetpuc dnsHdnsSdns" + uVar3));
      uVar3 = uVar3 + 4;
      puVar2[3] = iVar7;
    } while (uVar3 < 0x14);
    break;
  case CMTYPE_WINDOWS_MEDIA:
    piVar8 = (int *)puVar2[3];
    if (*piVar8 != 4) {
LAB_680f6e1a:
      puVar2[4] = 2;
      return 0;
    }
    if ((piVar8[1] != 4) && (piVar8[1] != 8)) {
LAB_680f6de1:
      puVar2[4] = 3;
      return 0;
    }
    iVar7 = this[0x17];
    iVar6 = this[0x18];
    iVar4 = this[0x15];
    uVar5 = rendering_getMediaState((int)this);
    iVar7 = Ordinal_1931(uVar5,iVar4,iVar6,iVar7);
    piVar8[2] = iVar7;
    puVar2[4] = 0;
    break;
  case 0x18:
    piVar8 = (int *)puVar2[3];
    if (*piVar8 != 4) goto LAB_680f6e1a;
    if ((piVar8[1] != 4) && (piVar8[1] != 8)) goto LAB_680f6de1;
    local_10 = Ordinal_1930(piVar8[2],&local_14,&local_8,&local_c);
    iVar7 = display_setCastMemberMediaRef(local_10,local_8,local_c);
    if (iVar7 == 0) goto LAB_680f6b7c;
    rendering_getMediaRef((int)this,local_14);
    puVar2[4] = 0;
    break;
  case 0x19:
    iVar7 = display_getSoundProperty(puVar2);
    goto joined_r0x680f6ea0;
  case 0x1a:
    iVar7 = display_setSoundProperty();
joined_r0x680f6ea0:
    if (iVar7 == 0) goto switchD_680f6b4d_caseD_1;
    break;
  case 0x1d:
    iVar7 = puVar2[3];
    if ((((this[0x16] == *(int *)(iVar7 + 0x58)) &&
         (iVar6 = Ordinal_1122(this[0x15],*(undefined4 *)(iVar7 + 0x54)), iVar6 != 0)) &&
        (((this[0x17] == 0 && (*(int *)(iVar7 + 0x5c) == 0)) ||
         (iVar6 = Ordinal_1122(this[0x17],*(undefined4 *)(iVar7 + 0x5c)), iVar6 != 0)))) &&
       (((this[0x18] == 0 && (*(int *)(iVar7 + 0x60) == 0)) ||
        (iVar7 = Ordinal_1122(this[0x18],*(undefined4 *)(iVar7 + 0x60)), iVar7 != 0)))) {
      puVar2[4] = 1;
    }
  }
  param_1 = (undefined4 *)0x1;
LAB_680f6b7c:
  if (local_10 != 0) {
    Ordinal_1113(&local_10);
  }
  if (local_8 != 0) {
    Ordinal_1113(&local_8);
  }
  if (local_c != 0) {
    Ordinal_1113(&local_c);
  }
  return (int)param_1;
}



// ============================================================
// Function: display_loadPictureMedia (FUN_680f6fc0)
// Address: 680f6fc0
// Size: 76 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_loadPictureMedia(undefined4 param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *unaff_ESI;
  
  if ((unaff_ESI == (undefined4 *)0x0) || (unaff_ESI[2] != 5)) {
    rendering_initMemberSlot(unaff_ESI,-0x79);
    return 0;
  }
  uVar1 = Ordinal_1710(param_1);
  unaff_ESI[0x15] = uVar1;
  iVar2 = Ordinal_1042();
  if ((iVar2 == 0) && (unaff_ESI[0x15] != 0)) {
    return 1;
  }
  rendering_initMemberSlot(unaff_ESI,-0x7b);
  return 0;
}



// ============================================================
// Function: display_getPictureMediaData (FUN_680f7010)
// Address: 680f7010
// Size: 116 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getPictureMediaData(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  if ((unaff_ESI == (undefined4 *)0x0) || (unaff_ESI[2] != 5)) {
    iVar3 = -0x79;
  }
  else {
    iVar1 = Ordinal_1711(0,unaff_ESI[0x15]);
    if (iVar1 != 0) {
      if (param_1 != 0) {
        iVar1 = Ordinal_1711(param_1,unaff_ESI[0x15],0);
        if (iVar1 == 0) goto LAB_680f7054;
      }
      uVar2 = 1;
    }
  }
LAB_680f7054:
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
// Function: display_resolvePictureMedia (FUN_680f7090)
// Address: 680f7090
// Size: 108 bytes
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 display_resolvePictureMedia(void)

{
  int *in_EAX;
  int iVar1;
  int local_c;
  undefined4 local_8;
  
  if ((in_EAX != (int *)0x0) && (in_EAX[2] == 5)) {
    if (in_EAX[0x15] == 0) {
      local_8 = 0;
      iVar1 = rendering_updateMemberState(in_EAX,FOURCC_PICT,&local_c,&local_8,(int *)0x0);
      if (iVar1 != 1) {
        return 0;
      }
      display_loadPictureMedia(local_8);
      Ordinal_1407(&local_8);
    }
    if (in_EAX[0x15] != 0) {
      in_EAX[0xb] = in_EAX[0xb] | 0x200;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: display_createPictureMediaCopy (FUN_680f7100)
// Address: 680f7100
// Size: 111 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_createPictureMediaCopy(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 local_c;
  int local_8;
  
  bVar1 = false;
  local_8 = 0;
  local_c = 0;
  local_8 = Ordinal_1111(0,0);
  if (local_8 != 0) {
    iVar2 = Ordinal_1404(&local_c,local_8,3);
    if (iVar2 != 0) {
      iVar2 = Ordinal_1711(local_c,*(undefined4 *)(param_1 + 0x54),0);
      if (iVar2 != 0) {
        bVar1 = true;
      }
    }
  }
  Ordinal_1407(&local_c);
  if (!bVar1) {
    Ordinal_1113(&local_8);
  }
  return local_8;
}



// ============================================================
// Function: display_getPictureProperty (FUN_680f7170)
// Address: 680f7170
// Size: 115 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_getPictureProperty(void)

{
  int *piVar1;
  int *piVar2;
  undefined4 *in_EAX;
  int iVar3;
  int local_8;
  
  piVar1 = (int *)*in_EAX;
  piVar2 = (int *)in_EAX[4];
  local_8 = 0;
  if ((piVar1[2] != 5) || (iVar3 = rendering_getMemberData(in_EAX[1],piVar1), iVar3 == 0)) goto LAB_680f71d1;
  if (in_EAX[3] == 5) {
    Ordinal_1716(piVar1[0x15],piVar2);
LAB_680f71be:
    local_8 = 1;
  }
  else if (in_EAX[3] == 0xf) {
    iVar3 = display_createPictureMediaCopy((int)piVar1);
    *piVar2 = iVar3;
    if (iVar3 != 0) goto LAB_680f71be;
  }
  rendering_isStateValid((int)piVar1);
  if (local_8 != 0) {
    return local_8;
  }
LAB_680f71d1:
  Ordinal_1130(piVar2,0x18);
  return local_8;
}



// ============================================================
// Function: display_setPictureProperty (FUN_680f71f0)
// Address: 680f71f0
// Size: 152 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_setPictureProperty(void)

{
  int iVar1;
  int iVar2;
  int *in_EAX;
  int iVar3;
  undefined4 uVar4;
  int local_c;
  undefined4 local_8;
  
  iVar1 = in_EAX[1];
  iVar2 = *in_EAX;
  local_8 = 0;
  local_c = 0;
  if ((*(int *)(iVar2 + 8) == 5) && (in_EAX[3] == 0xf)) {
    iVar3 = Ordinal_1404(&local_8,*(undefined4 *)in_EAX[4],1);
    if (iVar3 != 0) {
      uVar4 = Ordinal_1435(local_8);
      local_c = Ordinal_1710(local_8,uVar4);
      if (local_c != 0) {
        Ordinal_1714((int *)(iVar2 + 0x54));
        *(int *)(iVar2 + 0x54) = local_c;
        rendering_updateMemberMedia(iVar1,iVar2);
        Ordinal_1407(&local_8);
        return 1;
      }
    }
  }
  Ordinal_1714(&local_c);
  Ordinal_1407(&local_8);
  return 0;
}



// ============================================================
// Function: display_dispatchPictureHandler (FUN_680f7290)
// Address: 680f7290
// Size: 620 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 * display_dispatchPictureHandler(undefined4 *param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined1 uVar5;
  int iVar6;
  undefined3 extraout_var;
  undefined4 uVar7;
  
  puVar4 = param_1;
  puVar1 = param_1 + 2;
  piVar2 = (int *)*param_1;
  param_1 = (undefined4 *)0x0;
  switch(*puVar1) {
  case 0:
    piVar2[0x15] = puVar4[4];
  default:
    goto switchD_680f72b1_caseD_1;
  case CMTYPE_TEXT_FIELD:
    if (piVar2[0x15] != 0) {
      iVar6 = Ordinal_1713(piVar2[0x15]);
      piVar2[0x15] = iVar6;
      break;
    }
    goto LAB_680f72c8;
  case CMTYPE_PICTURE:
    uVar5 = display_resolvePictureMedia();
    iVar6 = CONCAT31(extraout_var,uVar5);
    break;
  case CMTYPE_SOUND:
    iVar6 = display_loadPictureMedia(puVar4[4]);
    break;
  case CMTYPE_BUTTON:
    if (puVar4[5] != FOURCC_PICT) goto switchD_680f72b1_caseD_1;
    iVar6 = display_getPictureMediaData(puVar4[4]);
    break;
  case CMTYPE_SHAPE:
    Ordinal_1714(piVar2 + 0x15);
    piVar2[0xb] = piVar2[0xb] & 0xfffffdff;
    return (undefined4 *)1;
  case CMTYPE_MOVIE:
    uVar7 = Ordinal_1719(piVar2[0x15]);
    puVar4[3] = uVar7;
    goto switchD_680f72b1_caseD_1;
  case CMTYPE_DIGITAL_VIDEO:
    rendering_updateMemberState(piVar2,FOURCC_PICT,puVar4 + 3,(undefined4 *)0x0,(int *)0x0);
    return (undefined4 *)1;
  case CMTYPE_SCRIPT:
    iVar6 = Ordinal_2010(piVar2[0x15]);
    break;
  case CMTYPE_TEXT_RICH:
    iVar6 = Ordinal_2004();
    piVar2[0x15] = iVar6;
    break;
  case CMTYPE_TRANSITION:
    puVar4[3] = 0xb;
    return (undefined4 *)1;
  case CMTYPE_VECTOR:
    puVar4[3] = 1;
    return (undefined4 *)1;
  case CMTYPE_FLASH:
    iVar6 = crt_negotiateFormat(puVar4 + 4,puVar4[3],FOURCC_PICT);
    puVar4[3] = iVar6;
    return (undefined4 *)1;
  case CMTYPE_WINDOWS_MEDIA:
    piVar3 = (int *)puVar4[3];
    if (*piVar3 != 2) {
LAB_680f7480:
      puVar4[4] = 2;
      return (undefined4 *)0;
    }
    if (piVar3[1] == 2) {
      iVar6 = Ordinal_1717(piVar2[0x15]);
      piVar3[2] = iVar6;
      puVar4[4] = 0;
      return (undefined4 *)1;
    }
    if (piVar3[1] == 6) {
      iVar6 = Ordinal_1717(piVar2[0x15]);
      piVar3[2] = iVar6;
      puVar4[4] = 0;
      return (undefined4 *)1;
    }
    goto LAB_680f74bb;
  case 0x18:
    piVar3 = (int *)puVar4[3];
    if (*piVar3 != 2) goto LAB_680f7480;
    if ((piVar3[1] == 2) && (iVar6 = Ordinal_1718(piVar3[2]), iVar6 != 0)) {
      Ordinal_1714(piVar2 + 0x15);
      piVar2[0x15] = iVar6;
    }
LAB_680f74bb:
    puVar4[4] = 3;
    return (undefined4 *)0;
  case 0x19:
    iVar6 = display_getPictureProperty();
    if (iVar6 != 0) {
      return (undefined4 *)1;
    }
    goto switchD_680f72b1_caseD_1;
  case 0x1a:
    iVar6 = display_setPictureProperty();
    if (iVar6 != 0) {
      return (undefined4 *)1;
    }
switchD_680f72b1_caseD_1:
    iVar6 = rendering_validateState(puVar4);
    break;
  case 0x1d:
    iVar6 = Ordinal_1720(piVar2[0x15],*(undefined4 *)(puVar4[3] + 0x54));
    if (iVar6 != 0) {
      puVar4[4] = 1;
      return (undefined4 *)1;
    }
    goto LAB_680f72c8;
  }
  if (iVar6 != 0) {
LAB_680f72c8:
    param_1 = (undefined4 *)0x1;
  }
  return param_1;
}



// ============================================================
// Function: display_loadPaletteMedia (FUN_680f7570)
// Address: 680f7570
// Size: 257 bytes
// Params: void * this, undefined4 * param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall display_loadPaletteMedia(void *this,undefined4 *param_1)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined2 local_10;
  undefined2 local_e;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  local_8 = Ordinal_1439();
  if (local_8 == 0) {
    return 0;
  }
  puVar2 = (undefined1 *)Ordinal_1114(local_8);
  if ((param_1 == (undefined4 *)0x0) || (param_1[2] != 4)) {
    iVar3 = -0x79;
  }
  else {
    uVar5 = ((uint)this & 0xffff) / 6;
    param_1[0x15] = 0;
    if (0x100 < uVar5) {
      uVar5 = 0x100;
    }
    iVar3 = Ordinal_1730(uVar5);
    if (iVar3 != 0) {
      iVar4 = 0;
      if (uVar5 != 0) {
        do {
          local_e = xtra_readBE16(puVar2);
          uVar1 = xtra_readBE16(puVar2 + 2);
          local_c = CONCAT22((*(unsigned short *)((char *)&local_c + 2)),uVar1);
          uVar1 = xtra_readBE16(puVar2 + 4);
          local_c = CONCAT22(uVar1,(undefined2)local_c);
          puVar2 = puVar2 + 6;
          local_10 = 0;
          Ordinal_1737(iVar3,iVar4,&local_10,1);
          iVar4 = iVar4 + 1;
        } while (iVar4 < (int)uVar5);
      }
      param_1[0x15] = iVar3;
      local_c = 1;
      goto LAB_680f764c;
    }
    iVar3 = -0x7b;
  }
  rendering_initMemberSlot(param_1,iVar3);
LAB_680f764c:
  if (local_8 != 0) {
    Ordinal_1113(&local_8);
  }
  return local_c;
}



// ============================================================
// Function: display_getPaletteMediaData (FUN_680f7680)
// Address: 680f7680
// Size: 210 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getPaletteMediaData(int param_1)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *unaff_EBX;
  int iVar3;
  undefined1 local_10 [2];
  undefined2 local_e;
  undefined2 uStack_c;
  undefined2 local_a;
  undefined2 uStack_8;
  
  if (in_EAX != (int *)0x0) {
    *in_EAX = 0;
  }
  if (((unaff_EBX == (undefined4 *)0x0) || (unaff_EBX[2] != 4)) || (unaff_EBX[0x15] == 0)) {
    rendering_initMemberSlot(unaff_EBX,-0x79);
    return 0;
  }
  iVar1 = Ordinal_1734(unaff_EBX[0x15]);
  if (in_EAX != (int *)0x0) {
    *in_EAX = iVar1 * 6;
  }
  if (param_1 != 0) {
    iVar3 = 0;
    if (0 < iVar1) {
      do {
        Ordinal_1736(unaff_EBX[0x15],iVar3,local_10,1);
        iVar2 = Ordinal_1423(param_1,CONCAT22(uStack_c,local_e));
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = Ordinal_1423(param_1,CONCAT22(local_a,uStack_c));
        if (iVar2 == 0) {
          return 0;
        }
        iVar2 = Ordinal_1423(param_1,CONCAT22(uStack_8,local_a));
        if (iVar2 == 0) {
          return 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
    iVar1 = Ordinal_1042();
    if (iVar1 != 0) {
      rendering_initMemberSlot(unaff_EBX,-0x7c);
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: display_initDefaultPalette (FUN_680f7760)
// Address: 680f7760
// Size: 215 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_initDefaultPalette(int param_1)
{
  undefined4 uVar1;
  int iVar2;
  int *unaff_ESI;
  int unaff_EDI;
  undefined4 local_81c;
  int local_818;
  int local_814 [3];
  undefined1 local_808 [2048];
  uint local_8;
  
  local_818 = param_1;
  if ((param_1 != 0) || (unaff_ESI == (int *)0x0)) {
LAB_680f77ff:
    *(int *)(unaff_EDI + 0x54) = local_818;
    return 0;
  }
  uVar1 = strings_getDefaultCastType();
  local_81c = CONCAT22((short)uVar1,0xffff);
  local_818 = Ordinal_1730(0x100);
  if (local_818 != 0) {
    iVar2 = rendering_transformPaletteData(unaff_ESI,local_81c,local_814);
    if (iVar2 != 0) {
      iVar2 = Ordinal_1737(local_818,0,local_808,0x100);
      if (iVar2 != 0) {
        Ordinal_1735(local_818,local_814[0]);
        goto LAB_680f77ff;
      }
      goto LAB_680f7824;
    }
  }
  Ordinal_1733(&local_818);
LAB_680f7824:
  return 0;
}




// ============================================================
// Function: display_resolvePaletteMedia (FUN_680f7840)
// Address: 680f7840
// Size: 110 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool display_resolvePaletteMedia(void)

{
  int local_18;
  int iVar1;
  int *unaff_ESI;
  bool bVar2;
  void *local_c;
  undefined4 local_8;
  
  bVar2 = false;
  if (unaff_ESI[0x15] == 0) {
    local_8 = 0;
    iVar1 = rendering_updateMemberState(unaff_ESI,FOURCC_CLUT,(int *)&local_c,&local_8,(int *)0x0);
    if (iVar1 == 1) {
      display_loadPaletteMedia(local_c,unaff_ESI);
      bVar2 = unaff_ESI[0x15] != 0;
      Ordinal_1407(&local_8);
      if (bVar2) {
        unaff_ESI[0xb] = unaff_ESI[0xb] | 0x200;
      }
    }
    return bVar2;
  }
  unaff_ESI[0xb] = unaff_ESI[0xb] | 0x200;
  return true;
}



// ============================================================
// Function: display_validatePaletteType (FUN_680f78b0)
// Address: 680f78b0
// Size: 18 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall display_validatePaletteType(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 4)) {
    uVar1 = 0x80c;
  }
  return uVar1;
}



// ============================================================
// Function: display_getPaletteProperty (FUN_680f78d0)
// Address: 680f78d0
// Size: 76 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getPaletteProperty(void)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *in_EAX;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = (int *)*in_EAX;
  puVar2 = (undefined4 *)in_EAX[4];
  if ((piVar1[2] == 4) && (in_EAX[3] == 0x2e)) {
    iVar3 = rendering_getMemberData(in_EAX[1],piVar1);
    if (iVar3 != 0) {
      uVar4 = Ordinal_1731(piVar1[0x15]);
      *puVar2 = uVar4;
      rendering_isStateValid((int)piVar1);
      return 1;
    }
    *puVar2 = 0;
  }
  Ordinal_1130(puVar2,0x18);
  return 0;
}



// ============================================================
// Function: display_setPaletteProperty (FUN_680f7920)
// Address: 680f7920
// Size: 153 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_setPaletteProperty(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *in_EAX;
  undefined4 uVar5;
  int iVar6;
  
  puVar1 = (undefined4 *)in_EAX[4];
  piVar2 = (int *)*in_EAX;
  iVar3 = in_EAX[1];
  uVar5 = 0;
  if ((piVar2[2] == 4) && (in_EAX[3] == 0x2e)) {
    Ordinal_1733(piVar2 + 0x15);
    iVar6 = Ordinal_1731(*puVar1);
    piVar2[0xb] = piVar2[0xb] | 0x200;
    piVar2[0x15] = iVar6;
    piVar4 = (int *)in_EAX[1];
    iVar6 = piVar4[9];
    if ((((short)piVar2[1] == *(short *)(iVar6 + 0x30)) &&
        (*(short *)((int)piVar2 + 6) == *(short *)(iVar6 + 0x32))) ||
       (((short)piVar2[1] == *(short *)(iVar6 + 0x34) &&
        (*(short *)((int)piVar2 + 6) == *(short *)(iVar6 + 0x36))))) {
      *(undefined4 *)(iVar6 + 0x30) = 0;
      *(undefined4 *)(iVar6 + 0x34) = 0;
      rendering_setChannelProperty(piVar4,iVar6,piVar2[1]);
    }
    rendering_setMemberData(iVar3,piVar2,2);
    uVar5 = 1;
  }
  return uVar5;
}



// ============================================================
// Function: display_dispatchPaletteHandler (FUN_680f79c0)
// Address: 680f79c0
// Size: 767 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 * display_dispatchPaletteHandler(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined3 extraout_var;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  undefined1 local_18 [8];
  undefined1 local_10 [8];
  int local_8;
  
  puVar4 = param_1;
  puVar1 = param_1 + 2;
  puVar2 = (undefined4 *)*param_1;
  param_1 = (undefined4 *)0x0;
  switch(*puVar1) {
  case 0:
    iVar5 = display_initDefaultPalette(puVar4[4]);
    if (iVar5 == 0) {
      return (undefined4 *)0;
    }
  default:
    goto switchD_680f79e4_caseD_1;
  case CMTYPE_TEXT_FIELD:
    if (puVar2[0x15] != 0) {
      iVar5 = Ordinal_1732(puVar2[0x15]);
      puVar2[0x15] = iVar5;
      break;
    }
    goto LAB_680f7a05;
  case CMTYPE_PICTURE:
    bVar9 = display_resolvePaletteMedia();
    iVar5 = CONCAT31(extraout_var,bVar9);
    break;
  case CMTYPE_SOUND:
    iVar5 = display_loadPaletteMedia((void *)puVar4[6],puVar2);
    break;
  case CMTYPE_BUTTON:
    if (puVar4[5] != FOURCC_CLUT) goto switchD_680f79e4_caseD_1;
    iVar5 = display_getPaletteMediaData(puVar4[4]);
    break;
  case CMTYPE_SHAPE:
    Ordinal_1733(puVar2 + 0x15);
    puVar2[0xb] = puVar2[0xb] & 0xfffffdff;
    return (undefined4 *)1;
  case CMTYPE_MOVIE:
    uVar6 = Ordinal_1747(puVar2[0x15]);
    puVar4[3] = uVar6;
    goto switchD_680f79e4_caseD_1;
  case CMTYPE_DIGITAL_VIDEO:
    uVar6 = display_validatePaletteType((int)puVar2);
    puVar4[3] = uVar6;
    return (undefined4 *)1;
  case CMTYPE_SCRIPT:
    iVar5 = Ordinal_2011(puVar2[0x15]);
    break;
  case CMTYPE_TEXT_RICH:
    iVar5 = Ordinal_2005();
    puVar2[0x15] = iVar5;
    break;
  case CMTYPE_OLE:
    puVar4[3] = 3;
    return (undefined4 *)1;
  case CMTYPE_VECTOR:
    puVar4[3] = 1;
    return (undefined4 *)1;
  case CMTYPE_FLASH:
    iVar5 = crt_negotiateFormat(puVar4 + 4,puVar4[3],FOURCC_CLUT);
    puVar4[3] = iVar5;
    return (undefined4 *)1;
  case CMTYPE_WINDOWS_MEDIA:
    piVar3 = (int *)puVar4[3];
    if (*piVar3 == 3) {
      if ((piVar3[1] != 3) && (piVar3[1] != 7)) {
        puVar4[4] = 3;
        return (undefined4 *)0;
      }
      iVar5 = Ordinal_1744(puVar2[0x15]);
      piVar3[2] = iVar5;
      puVar4[4] = 0;
      return (undefined4 *)1;
    }
    goto LAB_680f7b9e;
  case 0x18:
    piVar3 = (int *)puVar4[3];
    if (*piVar3 == 3) {
      if ((piVar3[1] != 3) && (piVar3[1] != 7)) {
        puVar4[4] = 3;
        return (undefined4 *)1;
      }
      iVar5 = Ordinal_1743(piVar3[2]);
      if (iVar5 == 0) {
        puVar4[4] = 5;
        return (undefined4 *)1;
      }
      Ordinal_1733(puVar2 + 0x15);
      puVar2[0x15] = iVar5;
      puVar4[4] = 0;
      return (undefined4 *)1;
    }
LAB_680f7b9e:
    puVar4[4] = 2;
    return (undefined4 *)0;
  case 0x19:
    iVar5 = display_getPaletteProperty();
    if (iVar5 != 0) {
      return (undefined4 *)1;
    }
switchD_680f79e4_caseD_1:
    iVar5 = rendering_validateState(puVar4);
    break;
  case 0x1a:
    iVar5 = display_setPaletteProperty();
    break;
  case 0x1d:
    iVar5 = puVar4[3];
    local_8 = iVar5;
    iVar7 = Ordinal_1734(puVar2[0x15]);
    iVar5 = Ordinal_1734(*(undefined4 *)(iVar5 + 0x54));
    if (iVar7 == iVar5) {
      iVar5 = 0;
      bVar9 = iVar7 == 0;
      if (0 < iVar7) {
        do {
          Ordinal_1736(puVar2[0x15],iVar5,local_18,1);
          Ordinal_1736(*(undefined4 *)(local_8 + 0x54),iVar5,local_10,1);
          iVar8 = Ordinal_1131(local_18,local_10,8);
          if (iVar8 == 0) break;
          iVar5 = iVar5 + 1;
        } while (iVar5 < iVar7);
        bVar9 = iVar5 == iVar7;
      }
      if (bVar9) {
        puVar4[4] = 1;
        return (undefined4 *)1;
      }
    }
    goto LAB_680f7a05;
  }
  if (iVar5 != 0) {
LAB_680f7a05:
    param_1 = (undefined4 *)0x1;
  }
  return param_1;
}



// ============================================================
// Function: display_initVideoPlayback (FUN_680f7d30)
// Address: 680f7d30
// Size: 102 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_initVideoPlayback(int param_1)
{
  undefined1 uVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 *unaff_ESI;
  int iVar4;
  int local_8;
  
  local_8 = 0;
  unaff_ESI[0x1c] = 1000;
  local_8 = media_writePlaybackData(*unaff_ESI,0,0);
  if (local_8 != 0) {
    iVar3 = *(int *)(*(int *)(param_1 + 0x20) + 0x500);
    iVar4 = 0;
    iVar2 = Ordinal_1112(unaff_ESI[0x15]);
    uVar1 = media_getPlaybackByte(local_8,iVar2,iVar3,iVar4);
    if (CONCAT31(extraout_var,uVar1) != 0) {
      iVar3 = media_getScoreVersionInfo(local_8);
      unaff_ESI[0x1c] = iVar3;
    }
  }
  media_getScorePlayState(&local_8);
  return 0;
}



// ============================================================
// Function: display_loadVideoMedia (FUN_680f7da0)
// Address: 680f7da0
// Size: 121 bytes
// Params: undefined4 param_1, uint param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_loadVideoMedia(undefined4 param_1,uint param_2)

{
  undefined4 *in_EAX;
  uint uVar1;
  short *psVar2;
  int *piVar3;
  int unaff_EBX;
  int unaff_EDI;
  
  uVar1 = scoreEngine_getChannelRange(*(int *)(unaff_EDI + 0x20),*(short *)(in_EAX + 1),0);
  psVar2 = (short *)scoreEngine_getFrameData(*(int *)(unaff_EDI + 0x20),(short)uVar1);
  if (((unaff_EBX != 0) && (psVar2 == (short *)0x0)) &&
     (psVar2 = (short *)scoreEngine_getFrameData(*(int *)(unaff_EDI + 0x20),1), psVar2 == (short *)0x0)) {
    return 0;
  }
  if (in_EAX[2] == 2) {
    piVar3 = media_loadScoreResource(param_1,param_2,*(int **)(unaff_EDI + 0x20),unaff_EBX,psVar2);
    if (piVar3 != (int *)0x0) {
      in_EAX[0x15] = piVar3;
      display_initVideoPlayback(unaff_EDI);
      return 1;
    }
  }
  else {
    rendering_initMemberSlot(in_EAX,-0x79);
  }
  return 0;
}



// ============================================================
// Function: display_getVideoMediaLayout (FUN_680f7e20)
// Address: 680f7e20
// Size: 188 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_getVideoMediaLayout(int param_1,undefined4 *param_2,int param_3)

{
  int *in_EAX;
  uint uVar1;
  int iVar2;
  int iVar3;
  int *unaff_EBX;
  
  uVar1 = scoreEngine_getChannelRange((int)in_EAX,(short)unaff_EBX[1],0);
  iVar2 = scoreEngine_getFrameData((int)in_EAX,(short)uVar1);
  if (((param_3 != 0) && (iVar2 == 0)) && (iVar2 = scoreEngine_getFrameData((int)in_EAX,1), iVar2 == 0)) {
    return 0;
  }
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if (unaff_EBX[2] != 2) {
    rendering_initMemberSlot(unaff_EBX,-0x79);
    return 0;
  }
  if ((int *)unaff_EBX[0x15] == (int *)0x0) {
    iVar2 = 0;
  }
  else {
    media_getScoreLayoutData((int *)unaff_EBX[0x15]);
    iVar2 = media_mergeScoreEntries((int *)unaff_EBX[0x15],param_1,param_2,in_EAX,param_3);
  }
  iVar3 = Ordinal_1042();
  if (((iVar3 != 0) || (iVar2 == 0)) && (iVar3 = lingo_getMovieRef(*unaff_EBX), iVar3 == 0)) {
    rendering_initMemberSlot(unaff_EBX,-0x7c);
  }
  return iVar2;
}



// ============================================================
// Function: display_resolveVideoMedia (FUN_680f7ee0)
// Address: 680f7ee0
// Size: 124 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool display_resolveVideoMedia(void)

{
  int iVar1;
  int *unaff_ESI;
  bool bVar2;
  uint local_c;
  undefined4 local_8;
  
  bVar2 = false;
  if (unaff_ESI[0x15] == 0) {
    local_8 = 0;
    iVar1 = rendering_updateMemberState(unaff_ESI,FOURCC_SCVW,(int *)&local_c,&local_8,(int *)0x0);
    if (iVar1 == 1) {
      display_loadVideoMedia(local_8,local_c);
      bVar2 = unaff_ESI[0x15] != 0;
      Ordinal_1407(&local_8);
      if (bVar2) {
        unaff_ESI[0xb] = unaff_ESI[0xb] | 0x200;
      }
    }
    return bVar2;
  }
  unaff_ESI[0xb] = unaff_ESI[0xb] | 0x200;
  return true;
}



// ============================================================
// Function: display_clearMediaLoaded (FUN_680f7f60)
// Address: 680f7f60
// Size: 17 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_clearMediaLoaded(void)
{
  int unaff_ESI;
  
  Ordinal_1113(unaff_ESI + 0x54);
  *(uint *)(unaff_ESI + 0x2c) = *(uint *)(unaff_ESI + 0x2c) & 0xfffffdff;
  return 0;
}



