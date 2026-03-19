// Module: media_playback
// Topic: Interface dispatch and property accessors
// Address range: 0x680B0010 - 0x680B0D90
// Functions (59):
//   mediaPlayback_findCastMemberByName (FUN_680b0010)
//   mediaPlayback_findCastByName (FUN_680b0050)
//   mediaPlayback_findCastByNameEx (FUN_680b0080)
//   mediaPlayback_deleteCastMember (FUN_680b00b0)
//   mediaPlayback_getCastMemberPosition (FUN_680b00d0)
//   mediaPlayback_loadComObject (FUN_680b00f0)
//   mediaPlayback_resolveScoreRef (FUN_680b0180)
//   mediaPlayback_renderTransfer (FUN_680b01c0)
//   mediaPlayback_findCastByGuid (FUN_680b0230)
//   mediaPlayback_getCastStreamGuid (FUN_680b0250)
//   mediaPlayback_convertCastPoint (FUN_680b0270)
//   mediaPlayback_createComInstance (FUN_680b0290)
//   mediaPlayback_getImageComInstance (FUN_680b0330)
//   mediaPlayback_getLinkedImageComInstance (FUN_680b0380)
//   mediaPlayback_getCastProperty (FUN_680b03e0)
//   mediaPlayback_getCastPropertyData (FUN_680b0400)
//   mediaPlayback_setCastProperty (FUN_680b0430)
//   mediaPlayback_createXtraInstance (FUN_680b0450)
//   mediaPlayback_createXtraPlayer (FUN_680b04c0)
//   mediaPlayback_saveCastMember (FUN_680b0570)
//   mediaPlayback_dispatchSpriteProperty (FUN_680b0590)
//   mediaPlayback_getCastPropertyPair (FUN_680b05d0)
//   mediaPlayback_getMovieProperty (FUN_680b0600)
//   mediaPlayback_setMovieProperty (FUN_680b0620)
//   mediaPlayback_getCastSoundRef (FUN_680b0640)
//   mediaPlayback_setCastSoundRef (FUN_680b0660)
//   mediaPlayback_resolveScoreSlot (FUN_680b0680)
//   mediaPlayback_convertCastToStage (FUN_680b06a0)
//   mediaPlayback_convertStageToCast (FUN_680b06c0)
//   media_invokeCallback (media_invokeCallback)
//   mediaPlayback_clearInterfaceRef (FUN_680b0700)
//   mediaPlayback_getSoundProperty (FUN_680b0720)
//   mediaPlayback_setSoundProperty (FUN_680b0740)
//   mediaPlayback_setInterfaceData (FUN_680b0760)
//   mediaPlayback_getSoundChannelProperty (FUN_680b0780)
//   mediaPlayback_setSoundChannelProperty (FUN_680b07b0)
//   mediaPlayback_getScoreChannelProperty (FUN_680b07e0)
//   mediaPlayback_setScoreChannelProperty (FUN_680b0810)
//   media_getInterfaceRef
//   media_getInterfaceState
//   mediaPlayback_resetInterfaceState (FUN_680b0880)
//   mediaPlayback_cleanupInterface (FUN_680b08a0)
//   mediaPlayback_reinitXtraCall (FUN_680b08e0)
//   mediaPlayback_initScorePlayback (FUN_680b0930)
//   mediaPlayback_writeScoreData (FUN_680b09d0)
//   mediaPlayback_getScoreReaderRef (FUN_680b0a40)
//   mediaPlayback_setScoreReaderRef (FUN_680b0a80)
//   mediaPlayback_setScoreReaderFromData (FUN_680b0ad0)
//   mediaPlayback_validateSpriteOp (FUN_680b0b10)
//   mediaPlayback_flushSpriteOps (FUN_680b0b40)
//   mediaPlayback_readWithFlush (FUN_680b0b70)
//   mediaPlayback_getOrdinal402 (FUN_680b0ba0)
//   mediaPlayback_getOrdinal401 (FUN_680b0bd0)
//   mediaPlayback_beginScorePlayback (FUN_680b0c00)
//   mediaPlayback_resetScoreState (FUN_680b0c30)
//   mediaPlayback_advanceScoreFrame (FUN_680b0c60)
//   mediaPlayback_beginScorePlaybackEx (FUN_680b0c90)
//   mediaPlayback_createScoreComObject (FUN_680b0cc0)
//   mediaPlayback_createScoreComObjectEx (FUN_680b0d90)

// ============================================================
// Function: mediaPlayback_findCastMemberByName (FUN_680b0010)
// Address: 680b0010
// Size: 61 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_findCastMemberByName(int param_1,undefined4 param_2,int *param_3)
{
  int local_18;
  int iVar1;
  int local_14 [4];

  iVar1 = media_findCastMemberByName((int *)(*(int *)(param_1 + 4) + 0x18),param_2,local_14);
  if (iVar1 == 0) {
    media_resolveXtraContext(local_14,(int *)(*(int *)(param_1 + 4) + 0x18),param_3);
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_findCastByName (FUN_680b0050)
// Address: 680b0050
// Size: 34 bytes
// Params: int param_1, undefined1 * param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_findCastByName(int param_1,undefined1 *param_2,int param_3,int *param_4)
{
  media_findCastByName((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: mediaPlayback_findCastByNameEx (FUN_680b0080)
// Address: 680b0080
// Size: 34 bytes
// Params: int param_1, undefined1 * param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_findCastByNameEx(int param_1,undefined1 *param_2,undefined4 param_3,int *param_4)
{
  media_findCastByNameEx((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: mediaPlayback_deleteCastMember (FUN_680b00b0)
// Address: 680b00b0
// Size: 26 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_deleteCastMember(int param_1,int param_2)
{
  media_deleteCastMember((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getCastMemberPosition (FUN_680b00d0)
// Address: 680b00d0
// Size: 30 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getCastMemberPosition(int param_1,int param_2,int *param_3)
{
  media_getCastMemberPosition((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_loadComObject (FUN_680b00f0)
// Address: 680b00f0
// Size: 131 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_loadComObject(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *unaff_EDI;
  int *local_8;

  local_8 = (int *)0x0;
  *unaff_EDI = 0;
  uVar2 = Ordinal_1038(&DAT_68176418,&DAT_68175f68);
  iVar3 = Ordinal_2063(uVar2);
  if ((iVar3 == 0) &&
     (iVar3 = (*(code *)**(undefined4 **)*unaff_EDI)
                        ((undefined4 *)*unaff_EDI,&DAT_68176428,&local_8), iVar3 == 0)) {
    iVar3 = (**(code **)(*local_8 + 0x10))(local_8,param_1);
    (**(code **)(*local_8 + 8))(local_8);
    if (iVar3 == 0) {
      return 0;
    }
  }
  piVar1 = (int *)*unaff_EDI;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *unaff_EDI = 0;
  }
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_resolveScoreRef (FUN_680b0180)
// Address: 680b0180
// Size: 53 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_resolveScoreRef(int param_1,int *param_2)
{
  int iVar1;
  undefined4 local_18 [5];

  iVar1 = media_resolveScoreRef((int *)(*(int *)(param_1 + 4) + 0x18),param_2,local_18);
  if (iVar1 == 0) {
    mediaPlayback_loadComObject(local_18);
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_renderTransfer (FUN_680b01c0)
// Address: 680b01c0
// Size: 102 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_renderTransfer(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 local_3c [7];
  int local_20 [7];

  crt_resolveLinkedImageData((int *)(*(int *)(param_1 + 4) + 0x18),local_20);
  crt_resolveImageData((int *)(*(int *)(param_1 + 4) + 0x18),local_3c);
  uVar1 = media_renderTransfer(local_20,local_3c,param_3,param_2,0,(undefined4 *)0x0,0,(int *)0x0,0);
  crt_getMovieApiState(local_20);
  crt_getMovieApiState(local_3c);
  return uVar1;
}



// ============================================================
// Function: mediaPlayback_findCastByGuid (FUN_680b0230)
// Address: 680b0230
// Size: 30 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_findCastByGuid(int param_1,undefined4 param_2,int *param_3)
{
  media_findCastByGuid((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getCastStreamGuid (FUN_680b0250)
// Address: 680b0250
// Size: 30 bytes
// Params: int param_1, undefined2 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getCastStreamGuid(int param_1,undefined2 *param_2,undefined4 *param_3)
{
  media_getCastStreamGuid((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_convertCastPoint (FUN_680b0270)
// Address: 680b0270
// Size: 30 bytes
// Params: int param_1, undefined2 * param_2, undefined2 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_convertCastPoint(int param_1,undefined2 *param_2,undefined2 *param_3)
{
  media_convertCastPoint((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_createComInstance (FUN_680b0290)
// Address: 680b0290
// Size: 150 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createComInstance(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  int iVar2;
  int *local_c;
  int *local_8;

  local_8 = (int *)0x0;
  uVar1 = Ordinal_1038(&DAT_68176458,&DAT_68175ca8,&local_c);
  iVar2 = Ordinal_2063(uVar1);
  if (iVar2 == 0) {
    iVar2 = (**(code **)*local_c)(local_c,&DAT_68176468,&local_8);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*local_8 + 0x10))(local_8,param_1);
      (**(code **)(*local_8 + 8))(local_8);
      if (iVar2 == 0) {
        *param_2 = local_c;
        return 0;
      }
    }
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  *param_2 = 0;
  return iVar2;
}



// ============================================================
// Function: mediaPlayback_getImageComInstance (FUN_680b0330)
// Address: 680b0330
// Size: 67 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getImageComInstance(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 local_20 [7];

  iVar1 = crt_resolveImageData((int *)(*(int *)(param_1 + 4) + 0x18),local_20);
  if ((iVar1 == 0) && (iVar1 = mediaPlayback_createComInstance(local_20,param_2), iVar1 != 0)) {
    crt_getMovieApiState(local_20);
  }
  return iVar1;
}



// ============================================================
// Function: mediaPlayback_getLinkedImageComInstance (FUN_680b0380)
// Address: 680b0380
// Size: 83 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getLinkedImageComInstance(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 local_20 [7];

  piVar1 = (int *)(*(int *)(param_1 + 4) + 0x18);
  if (*piVar1 != 0) {
    iVar2 = crt_resolveLinkedImageData(piVar1,local_20);
    if ((iVar2 == 0) && (iVar2 = mediaPlayback_createComInstance(local_20,param_2), iVar2 != 0)) {
      crt_getMovieApiState(local_20);
    }
    return iVar2;
  }
  return -0x7ffbffff;
}



// ============================================================
// Function: mediaPlayback_getCastProperty (FUN_680b03e0)
// Address: 680b03e0
// Size: 30 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getCastProperty(int param_1,int param_2,undefined4 *param_3)
{
  media_getCastProperty((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getCastPropertyData (FUN_680b0400)
// Address: 680b0400
// Size: 34 bytes
// Params: int param_1, int param_2, undefined1 * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getCastPropertyData(int param_1,int param_2,undefined1 *param_3,int param_4)
{
  media_getCastPropertyData((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: mediaPlayback_setCastProperty (FUN_680b0430)
// Address: 680b0430
// Size: 30 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_setCastProperty(int param_1,int param_2,int param_3)
{
  media_setCastProperty((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_createXtraInstance (FUN_680b0450)
// Address: 680b0450
// Size: 98 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraInstance(undefined4 param_1,undefined4 param_2,int param_3,int param_4,int *param_5)
{
  undefined4 uVar1;
  int iVar2;

  uVar1 = Ordinal_1038(&DAT_681763e8,&DAT_68175fb8,param_5);
  iVar2 = Ordinal_2063(uVar1);
  if (iVar2 == 0) {
    iVar2 = *param_5;
    *(undefined4 *)(*(int *)(iVar2 + 4) + 0x34) = param_2;
    *(undefined4 *)(*(int *)(iVar2 + 4) + 0x38) = param_1;
    if (param_3 != 0) {
      iVar2 = (**(code **)(*(int *)*param_5 + 0x20))((int *)*param_5,param_3);
      if ((param_4 != 0) && (iVar2 == 0)) {
        (**(code **)(*(int *)*param_5 + 0x10))((int *)*param_5);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_createXtraPlayer (FUN_680b04c0)
// Address: 680b04c0
// Size: 162 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraPlayer(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 0x18);
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x20);
  }
  uVar3 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    uVar3 = *(undefined4 *)(piVar2[1] + 8);
    if (iVar1 == 0) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_10 = DAT_68196374;
    local_c = 0;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  mediaPlayback_createXtraInstance(piVar2,uVar3,param_1,1,param_2);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_saveCastMember (FUN_680b0570)
// Address: 680b0570
// Size: 30 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_saveCastMember(int param_1,undefined4 param_2,int param_3)
{
  media_saveCastMember((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}




// ============================================================
// Function: mediaPlayback_dispatchSpriteProperty (FUN_680b0590)
// Address: 680b0590
// Size: 59 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint param_4, uint * param_5, int * param_6, undefined1 * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_dispatchSpriteProperty(int param_1,undefined4 param_2,uint param_3,uint param_4,uint *param_5,
                 int *param_6,undefined1 *param_7)
{
  int local_c;
  undefined4 local_8;

  local_c = *(int *)(*(int *)(param_1 + 4) + 0x18);
  local_8 = param_2;
  media_dispatchSpriteProperty(&local_c,param_3,param_4,param_5,param_6,param_7);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getCastPropertyPair (FUN_680b05d0)
// Address: 680b05d0
// Size: 38 bytes
// Params: int param_1, uint param_2, uint param_3, uint * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getCastPropertyPair(int param_1,uint param_2,uint param_3,uint *param_4,int *param_5)
{
  media_getCastPropertyPair((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getMovieProperty (FUN_680b0600)
// Address: 680b0600
// Size: 32 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getMovieProperty(int param_1,int param_2,uint *param_3)
{
  media_getMovieProperty((int *)(*(int *)(param_1 + 4) + 0x18),0,param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_setMovieProperty (FUN_680b0620)
// Address: 680b0620
// Size: 32 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_setMovieProperty(int param_1,int param_2,uint *param_3)
{
  media_getMovieProperty((int *)(*(int *)(param_1 + 4) + 0x18),1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getCastSoundRef (FUN_680b0640)
// Address: 680b0640
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getCastSoundRef(int param_1,int *param_2)
{
  media_getCastSoundRef((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_setCastSoundRef (FUN_680b0660)
// Address: 680b0660
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_setCastSoundRef(int param_1,int *param_2)
{
  media_setCastSoundRef((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_resolveScoreSlot (FUN_680b0680)
// Address: 680b0680
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_resolveScoreSlot(int param_1,int *param_2)
{
  media_resolveScoreSlot((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_convertCastToStage (FUN_680b06a0)
// Address: 680b06a0
// Size: 26 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_convertCastToStage(int param_1,undefined4 *param_2)
{
  media_convertCastToStage((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_convertStageToCast (FUN_680b06c0)
// Address: 680b06c0
// Size: 26 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_convertStageToCast(int param_1,undefined4 *param_2)
{
  media_convertStageToCast((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_invokeCallback (media_invokeCallback)
// Address: 680b06e0
// Size: 28 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_invokeCallback(int param_1,undefined4 param_2,undefined4 param_3)
{
  (**(code **)**(undefined4 **)(param_1 + 4))(*(undefined4 **)(param_1 + 4),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_clearInterfaceRef (FUN_680b0700)
// Address: 680b0700
// Size: 19 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_clearInterfaceRef(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  return 0;
}



// ============================================================
// Function: mediaPlayback_getSoundProperty (FUN_680b0720)
// Address: 680b0720
// Size: 32 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getSoundProperty(int param_1,int param_2,uint *param_3)
{
  media_getSoundProperty(*(int *)(*(int *)(param_1 + 4) + 0x18),0,param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_setSoundProperty (FUN_680b0740)
// Address: 680b0740
// Size: 32 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_setSoundProperty(int param_1,int param_2,uint *param_3)
{
  media_getSoundProperty(*(int *)(*(int *)(param_1 + 4) + 0x18),1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_setInterfaceData (FUN_680b0760)
// Address: 680b0760
// Size: 23 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_setInterfaceData(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x18) = *param_2;
  return 0;
}



// ============================================================
// Function: mediaPlayback_getSoundChannelProperty (FUN_680b0780)
// Address: 680b0780
// Size: 36 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getSoundChannelProperty(int param_1,int param_2,uint *param_3)
{
  media_getSoundChannelProperty(*(int *)(*(int *)(param_1 + 4) + 0x18),*(int *)(*(int *)(param_1 + 4) + 0x1c),0,
               param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_setSoundChannelProperty (FUN_680b07b0)
// Address: 680b07b0
// Size: 36 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_setSoundChannelProperty(int param_1,int param_2,uint *param_3)
{
  media_getSoundChannelProperty(*(int *)(*(int *)(param_1 + 4) + 0x18),*(int *)(*(int *)(param_1 + 4) + 0x1c),1,
               param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getScoreChannelProperty (FUN_680b07e0)
// Address: 680b07e0
// Size: 36 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getScoreChannelProperty(int param_1,int param_2,uint *param_3)
{
  media_getScoreChannelProperty(*(int *)(*(int *)(param_1 + 4) + 0x18),*(int *)(*(int *)(param_1 + 4) + 0x1c),0,
               param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_setScoreChannelProperty (FUN_680b0810)
// Address: 680b0810
// Size: 36 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_setScoreChannelProperty(int param_1,int param_2,uint *param_3)
{
  media_getScoreChannelProperty(*(int *)(*(int *)(param_1 + 4) + 0x18),*(int *)(*(int *)(param_1 + 4) + 0x1c),1,
               param_2,param_3);
  return 0;
}



// ============================================================
// Function: media_getInterfaceRef (FUN_680b0840)
// Address: 680b0840
// Size: 29 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getInterfaceRef(int param_1,undefined4 *param_2)

{
  int iVar1;

  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x18) = *param_2;
  *(undefined4 *)(iVar1 + 0x1c) = param_2[1];
  return 0;
}



// ============================================================
// Function: media_getInterfaceState (FUN_680b0860)
// Address: 680b0860
// Size: 30 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall media_getInterfaceState(int param_1)

{
  undefined4 *in_EAX;

  if (*(int *)(*(int *)(param_1 + 4) + 0x24) != 0) {
    *in_EAX = 0;
    return 1;
  }
  *in_EAX = 0x80040bbf;
  return 0;
}



// ============================================================
// Function: mediaPlayback_resetInterfaceState (FUN_680b0880)
// Address: 680b0880
// Size: 23 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_resetInterfaceState(int param_1)

{
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return 0;
}



// ============================================================
// Function: mediaPlayback_cleanupInterface (FUN_680b08a0)
// Address: 680b08a0
// Size: 49 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_cleanupInterface(int param_1)
{
  int *piVar1;

  if (*(int *)(param_1 + 0x24) != 0) {
    media_resetXtraVtable((undefined4 *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x28);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_reinitXtraCall (FUN_680b08e0)
// Address: 680b08e0
// Size: 74 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_reinitXtraCall(int param_1)
{
  int iVar1;

  if (*(int *)(*(int *)(param_1 + 4) + 0x24) != 0) {
    media_resetXtraVtable((undefined4 *)(*(int *)(param_1 + 4) + 0x18));
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x24) = 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  iVar1 = media_forwardXtraCall(*(int **)(iVar1 + 0x38),*(undefined4 *)(iVar1 + 0x34),(int *)(iVar1 + 0x18));
  if (iVar1 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x24) = 1;
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_initScorePlayback (FUN_680b0930)
// Address: 680b0930
// Size: 146 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_initScorePlayback(int param_1)

{
  int *piVar1;
  int iVar2;
  int local_1c [6];

  piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x28);
  if (piVar1 == (int *)0x0) {
    iVar2 = -0x7ffbf43e;
  }
  else {
    media_getScoreReaderData(local_1c);
    iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,local_1c);
    if (iVar2 == 0) {
      if (*(int *)(*(int *)(param_1 + 4) + 0x24) != 0) {
        media_resetXtraVtable((undefined4 *)(*(int *)(param_1 + 4) + 0x18));
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x24) = 0;
      }
      iVar2 = *(int *)(param_1 + 4);
      iVar2 = media_initScorePlayback(*(int **)(iVar2 + 0x38),*(undefined4 *)(iVar2 + 0x34),local_1c,
                           (int *)(iVar2 + 0x18));
      if (iVar2 == 0) {
        *(undefined4 *)(*(int *)(param_1 + 4) + 0x24) = 1;
      }
      media_readScoreSlot((int)local_1c);
      return iVar2;
    }
  }
  return iVar2;
}




// ============================================================
// Function: mediaPlayback_writeScoreData (FUN_680b09d0)
// Address: 680b09d0
// Size: 100 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_writeScoreData(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_1c [6];

  iVar2 = *(int *)(param_1 + 4);
  piVar1 = *(int **)(iVar2 + 0x28);
  if (piVar1 == (int *)0x0) {
    iVar2 = -0x7ffbf43e;
  }
  else {
    if (*(int *)(iVar2 + 0x24) == 0) {
      return -0x7ffbf441;
    }
    iVar2 = media_createScoreWriter(piVar1,iVar2 + 0x18,local_1c);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,local_1c);
      media_readScoreSlot((int)local_1c);
      return iVar2;
    }
  }
  return iVar2;
}



// ============================================================
// Function: mediaPlayback_getScoreReaderRef (FUN_680b0a40)
// Address: 680b0a40
// Size: 49 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_getScoreReaderRef(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;

  iVar1 = *(int *)(param_1 + 4);
  *param_2 = *(int *)(iVar1 + 0x28);
  param_2[1] = *(int *)(iVar1 + 0x2c);
  param_2[2] = *(int *)(iVar1 + 0x30);
  piVar2 = (int *)*param_2;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 4))(piVar2);
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_setScoreReaderRef (FUN_680b0a80)
// Address: 680b0a80
// Size: 77 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_setScoreReaderRef(int param_1,undefined4 *param_2)

{
  int *piVar1;
  int iVar2;

  if (*(int *)(*(int *)(param_1 + 4) + 0x28) != 0) {
    piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x28);
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  iVar2 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar2 + 0x28) = *param_2;
  *(undefined4 *)(iVar2 + 0x2c) = param_2[1];
  *(undefined4 *)(iVar2 + 0x30) = param_2[2];
  if (*(int *)(*(int *)(param_1 + 4) + 0x28) != 0) {
    piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x28);
    (**(code **)(*piVar1 + 4))(piVar1);
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_setScoreReaderFromData (FUN_680b0ad0)
// Address: 680b0ad0
// Size: 52 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_setScoreReaderFromData(int param_1,undefined4 param_2)
{
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;

  media_getScoreReaderData(&local_28);
  local_8 = local_24;
  local_c = local_28;
  local_10 = param_2;
  mediaPlayback_setScoreReaderRef(param_1,&local_10);
  return 0;
}



// ============================================================
// Function: mediaPlayback_validateSpriteOp (FUN_680b0b10)
// Address: 680b0b10
// Size: 41 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_validateSpriteOp(int param_1)

{
  int iVar1;
  void *this;

  iVar1 = media_getInterfaceState(param_1);
  if (iVar1 != 0) {
    iVar1 = media_validateSpriteOp(this,*(int *)((int)this + 4) + 0x18);
    return iVar1;
  }
  return param_1;
}



// ============================================================
// Function: mediaPlayback_flushSpriteOps (FUN_680b0b40)
// Address: 680b0b40
// Size: 41 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_flushSpriteOps(int param_1)

{
  int iVar1;
  int extraout_ECX;

  iVar1 = media_getInterfaceState(param_1);
  if (iVar1 != 0) {
    iVar1 = media_flushSpriteOps(*(int *)(extraout_ECX + 4) + 0x18);
    return iVar1;
  }
  return param_1;
}



// ============================================================
// Function: mediaPlayback_readWithFlush (FUN_680b0b70)
// Address: 680b0b70
// Size: 45 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_readWithFlush(int param_1,undefined4 param_2)

{
  int iVar1;
  int extraout_ECX;

  iVar1 = media_getInterfaceState(param_1);
  if (iVar1 != 0) {
    iVar1 = media_readWithFlush(*(int *)(extraout_ECX + 4) + 0x18,param_2);
    return iVar1;
  }
  return param_1;
}



// ============================================================
// Function: mediaPlayback_getOrdinal402 (FUN_680b0ba0)
// Address: 680b0ba0
// Size: 42 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getOrdinal402(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;

  iVar1 = media_getInterfaceState(param_1);
  if (iVar1 != 0) {
    uVar2 = Ordinal_402(*(int **)(*(int *)(extraout_ECX + 4) + 0x1c));
    *param_2 = uVar2;
  }
  return param_1;
}



// ============================================================
// Function: mediaPlayback_getOrdinal401 (FUN_680b0bd0)
// Address: 680b0bd0
// Size: 46 bytes
// Params: int param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getOrdinal401(int param_1,int *param_2)

{
  int iVar1;
  int extraout_ECX;

  iVar1 = media_getInterfaceState(param_1);
  if (iVar1 != 0) {
    iVar1 = Ordinal_401(*(int **)(*(int *)(extraout_ECX + 4) + 0x1c));
    *param_2 = iVar1;
    return iVar1;
  }
  return param_1;
}



// ============================================================
// Function: mediaPlayback_beginScorePlayback (FUN_680b0c00)
// Address: 680b0c00
// Size: 41 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_beginScorePlayback(int param_1)

{
  int iVar1;
  int extraout_ECX;

  iVar1 = media_getInterfaceState(param_1);
  if (iVar1 != 0) {
    iVar1 = media_beginScorePlayback(*(int *)(extraout_ECX + 4) + 0x18);
    return iVar1;
  }
  return param_1;
}



// ============================================================
// Function: mediaPlayback_resetScoreState (FUN_680b0c30)
// Address: 680b0c30
// Size: 41 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_resetScoreState(int param_1)

{
  int iVar1;
  int extraout_ECX;

  iVar1 = media_getInterfaceState(param_1);
  if (iVar1 != 0) {
    iVar1 = media_resetScoreState(*(int *)(extraout_ECX + 4) + 0x18);
    return iVar1;
  }
  return param_1;
}



// ============================================================
// Function: mediaPlayback_advanceScoreFrame (FUN_680b0c60)
// Address: 680b0c60
// Size: 41 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_advanceScoreFrame(int param_1)

{
  int iVar1;
  int extraout_ECX;

  iVar1 = media_getInterfaceState(param_1);
  if (iVar1 != 0) {
    iVar1 = media_advanceScoreFrame(*(int *)(extraout_ECX + 4) + 0x18);
    return iVar1;
  }
  return param_1;
}



// ============================================================
// Function: mediaPlayback_beginScorePlaybackEx (FUN_680b0c90)
// Address: 680b0c90
// Size: 41 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_beginScorePlaybackEx(int param_1)

{
  int iVar1;
  int extraout_ECX;

  iVar1 = media_getInterfaceState(param_1);
  if (iVar1 != 0) {
    iVar1 = media_beginScorePlaybackEx(*(int *)(extraout_ECX + 4) + 0x18);
    return iVar1;
  }
  return param_1;
}



// ============================================================
// Function: mediaPlayback_createScoreComObject (FUN_680b0cc0)
// Address: 680b0cc0
// Size: 200 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createScoreComObject(int param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int local_10;
  int *local_c;
  int *local_8;

  iVar1 = param_1;
  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  iVar2 = media_getInterfaceState(param_1);
  if (iVar2 == 0) {
    *param_2 = 0;
    return local_10;
  }
  uVar3 = Ordinal_1038(&DAT_68176388,&DAT_68175f88,&local_8);
  iVar2 = Ordinal_2063(uVar3);
  if (iVar2 == 0) {
    iVar2 = (**(code **)*local_8)(local_8,&DAT_68176398,&local_c);
    if (iVar2 == 0) {
      param_1 = *(int *)(iVar1 + 4) + 0x18;
      iVar2 = (**(code **)(*local_c + 0x10))(local_c,&param_1);
      (**(code **)(*local_c + 8))(local_c);
      if (iVar2 == 0) {
        *param_2 = local_8;
        return 0;
      }
    }
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  *param_2 = 0;
  return iVar2;
}



// ============================================================
// Function: mediaPlayback_createScoreComObjectEx (FUN_680b0d90)
// Address: 680b0d90
// Size: 206 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createScoreComObjectEx(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_14;
  undefined4 local_10;
  int *local_c;
  int *local_8;

  local_8 = (int *)0x0;
  local_c = (int *)0x0;
  iVar1 = media_getInterfaceState(param_1);
  if (iVar1 == 0) {
    *param_3 = 0;
    return param_1;
  }
  uVar2 = Ordinal_1038(&DAT_681763a8,&DAT_68175f98,&local_8);
  iVar1 = Ordinal_2063(uVar2);
  if (iVar1 == 0) {
    iVar1 = (**(code **)*local_8)(local_8,&DAT_681763b8,&local_c);
    if (iVar1 == 0) {
      local_10 = param_2;
      local_14 = *(int *)(param_1 + 4) + 0x18;
      iVar1 = (**(code **)(*local_c + 0x10))(local_c,&local_14);
      (**(code **)(*local_c + 8))(local_c);
      if (iVar1 == 0) {
        *param_3 = local_8;
        return 0;
      }
    }
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  *param_3 = 0;
  return iVar1;
}


