int media_queryXtraInterface(); /* FIXUP(C2065): missing forward declaration */
int media_queryXtraInterfaceEx(); /* FIXUP(C2065): missing forward declaration */
int mediaPlayback_dispatchChannelPropertyOp(); /* FIXUP(C2065): missing forward declaration */
int mediaPlayback_dispatchSpriteProperty(); /* FIXUP(C2065): missing forward declaration */
// Module: media_playback
// Topic: Vtable initialization, factory functions, and object creation
// Address range: 0x680B0E60 - 0x680B2EC0
// Functions (97):
//   mediaPlayback_createFilterGraph
//   mediaPlayback_clearPlaybackRect
//   mediaPlayback_getChannelProperty
//   mediaPlayback_getChannelPropertyAlt
//   mediaPlayback_resolveXtraContext
//   mediaPlayback_resetXtraState
//   mediaPlayback_getNextKeyframe
//   mediaPlayback_getChannelMode
//   mediaPlayback_getChannelSpan
//   mediaPlayback_getNextChannelFrame
//   mediaPlayback_getLastChannelFrame
//   mediaPlayback_getMemberDataBlock
//   mediaPlayback_readAndDispatchScore
//   mediaPlayback_importMemberFromChannel
//   mediaPlayback_updateChannelMediaRef
//   mediaPlayback_copyChannelMember
//   mediaPlayback_readCastData
//   mediaPlayback_getPlaybackRect
//   mediaPlayback_setPlaybackRect
//   mediaPlayback_clearPlaybackRectEx
//   rendering_updateDisplay
//   mediaPlayback_dispatchChannelProperty
//   mediaPlayback_getXtraMemberData
//   mediaPlayback_getChannelMediaInfo
//   mediaPlayback_readXtraScoreSlot
//   mediaPlayback_initChannelWithContext
//   mediaPlayback_getChannelOffset
//   mediaPlayback_resolveAndDispatch
//   mediaPlayback_dispatchChannelPropertyOp
//   mediaPlayback_getTransformData
//   mediaPlayback_clearCallbackState
//   mediaPlayback_setCallbackState
//   mediaPlayback_initXtraImageVtable
//   mediaPlayback_initXtraInterfaceVtable
//   mediaPlayback_initXtraMovieDataVtable
//   mediaPlayback_initXtraDirtyCheckVtable
//   mediaPlayback_initXtraValueVtable
//   mediaPlayback_initXtraPixelDataVtable
//   mediaPlayback_initXtraPixelFlushVtable
//   mediaPlayback_initXtraPixelBlockVtable
//   mediaPlayback_initXtraTransformVtable
//   mediaPlayback_initXtraPixelRegionVtable
//   mediaPlayback_initXtraAssetVtable
//   mediaPlayback_initXtraAssetExVtable
//   mediaPlayback_initXtraCallbackVtable
//   mediaPlayback_initXtraValueReadVtable
//   mediaPlayback_copyMovieStateData
//   mediaPlayback_initXtraHandlerVtable
//   mediaPlayback_initXtraValueReadAltVtable
//   mediaPlayback_initXtraStreamVtable
//   mediaPlayback_initXtraStreamReadVtable
//   mediaPlayback_initXtraNotifyVtable
//   mediaPlayback_initXtraStreamReadAltVtable
//   mediaPlayback_initXtraScoreVtable
//   mediaPlayback_initXtraChannelVtable
//   mediaPlayback_initXtraRectVtable
//   mediaPlayback_initXtraScoreChannelVtable
//   mediaPlayback_initXtraTransformAltVtable
//   mediaPlayback_initXtraCallbackClearVtable
//   mediaPlayback_initXtraCallbackSetVtable
//   mediaPlayback_createXtraImageObject
//   mediaPlayback_createXtraInterfaceObject
//   mediaPlayback_createXtraMovieDataObject
//   mediaPlayback_createXtraDirtyCheckObject
//   mediaPlayback_createXtraValueObject
//   mediaPlayback_createXtraPixelDataObject
//   mediaPlayback_createXtraPixelFlushObject
//   mediaPlayback_createXtraPixelBlockObject
//   mediaPlayback_createXtraTransformObject
//   mediaPlayback_createXtraPixelRegionObject
//   mediaPlayback_createXtraAssetObject
//   mediaPlayback_createXtraAssetExObject
//   mediaPlayback_createXtraCallbackObject
//   mediaPlayback_createXtraValueReadObject
//   mediaPlayback_createXtraHandlerObject
//   mediaPlayback_createXtraValueReadAltObject
//   mediaPlayback_createXtraStreamObject
//   mediaPlayback_createXtraStreamReadObject
//   mediaPlayback_createXtraNotifyObject
//   mediaPlayback_createXtraStreamReadAltObject
//   mediaPlayback_createXtraScoreObject
//   mediaPlayback_createXtraChannelObject
//   mediaPlayback_createXtraRectObject
//   mediaPlayback_createXtraScoreChannelObject
//   mediaPlayback_createXtraTransformAltObject
//   mediaPlayback_createXtraCallbackClearObject
//   mediaPlayback_createXtraCallbackSetObject
//   mediaPlayback_releaseSlotEntry
//   mediaPlayback_getEntryCount
//   mediaPlayback_getSlotValue
//   mediaPlayback_getSlotData
//   mediaPlayback_notifySlotRead
//   mediaPlayback_notifySlotWrite
//   mediaPlayback_releaseObject
//   mediaPlayback_setNotifyParam
//   mediaPlayback_getNotifyParam
//   media_setVtableEntry

// ============================================================
// Function: mediaPlayback_createFilterGraph (FUN_680b0e60)
// Address: 680b0e60
// Size: 206 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createFilterGraph(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int local_18;
  int local_2c;
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
  uVar2 = Ordinal_1038(&DAT_681763c8,&DAT_68175fa8,&local_8);
  iVar1 = Ordinal_2063(uVar2);
  if (iVar1 == 0) {
    iVar1 = (**(code **)*local_8)(local_8,&DAT_681763d8,&local_c);
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



// ============================================================
// Function: mediaPlayback_clearPlaybackRect (FUN_680b0f30)
// Address: 680b0f30
// Size: 26 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_clearPlaybackRect(int param_1)

{
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  return 0;
}



// ============================================================
// Function: mediaPlayback_getChannelProperty (FUN_680b0f50)
// Address: 680b0f50
// Size: 32 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getChannelProperty(int param_1,int param_2,uint *param_3)
{
  media_getChannelPropertyEx((int *)(*(int *)(param_1 + 4) + 0x18),0,param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getChannelPropertyAlt (FUN_680b0f70)
// Address: 680b0f70
// Size: 32 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getChannelPropertyAlt(int param_1,int param_2,uint *param_3)
{
  media_getChannelPropertyEx((int *)(*(int *)(param_1 + 4) + 0x18),1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_resolveXtraContext (FUN_680b0f90)
// Address: 680b0f90
// Size: 101 bytes
// Params: int param_1, undefined4 * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_resolveXtraContext(int param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_68176378,&local_8);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*local_8 + 0xc))(local_8,&param_2);
    if (iVar1 == 0) {
      iVar1 = media_resolveXtraContext((int *)(*(int *)(param_1 + 4) + 0x18),(int *)&param_2,param_3);
    }
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar1;
}



// ============================================================
// Function: mediaPlayback_resetXtraState (FUN_680b1000)
// Address: 680b1000
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_resetXtraState(int param_1,int *param_2)
{
  media_resetXtraState((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getNextKeyframe (FUN_680b1020)
// Address: 680b1020
// Size: 30 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getNextKeyframe(int param_1,int param_2,int *param_3)
{
  media_getNextKeyframe((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getChannelMode (FUN_680b1040)
// Address: 680b1040
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getChannelMode(int param_1,int *param_2)
{
  media_getChannelMode((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getChannelSpan (FUN_680b1060)
// Address: 680b1060
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getChannelSpan(int param_1,int *param_2)
{
  media_getChannelSpan((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getNextChannelFrame (FUN_680b1080)
// Address: 680b1080
// Size: 30 bytes
// Params: int param_1, short param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getNextChannelFrame(int param_1,short param_2,int *param_3)
{
  media_getNextChannelFrame((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getLastChannelFrame (FUN_680b10a0)
// Address: 680b10a0
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getLastChannelFrame(int param_1,int *param_2)
{
  media_getLastChannelFrame((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getMemberDataBlock (FUN_680b10c0)
// Address: 680b10c0
// Size: 30 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getMemberDataBlock(int param_1,int param_2,int *param_3)
{
  media_getMemberDataBlock((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_readAndDispatchScore (FUN_680b10e0)
// Address: 680b10e0
// Size: 53 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_readAndDispatchScore(int param_1,int param_2)
{
  int iVar1;
  undefined4 local_18 [5];
  
  iVar1 = media_readScoreBlock2((undefined4 *)(*(int *)(param_1 + 4) + 0x18),param_2,local_18);
  if (iVar1 == 0) {
    mediaPlayback_loadComObject(local_18);
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_importMemberFromChannel (FUN_680b1120)
// Address: 680b1120
// Size: 30 bytes
// Params: int param_1, undefined2 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_importMemberFromChannel(int param_1,undefined2 param_2,int param_3)
{
  media_importMemberFromChannel((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: mediaPlayback_updateChannelMediaRef (FUN_680b1140)
// Address: 680b1140
// Size: 48 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_updateChannelMediaRef(int param_1,int param_2)
{
  int iVar1;
  int local_18 [5];
  
  iVar1 = media_readScoreBlock2((undefined4 *)(*(int *)(param_1 + 4) + 0x18),param_2,local_18);
  if (iVar1 == 0) {
    media_updateChannelMediaRef(local_18);
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_copyChannelMember (FUN_680b1170)
// Address: 680b1170
// Size: 124 bytes
// Params: int param_1, int param_2, undefined4 * param_3, undefined2 param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_copyChannelMember(int param_1,int param_2,undefined4 *param_3,undefined2 param_4)

{
  int iVar1;
  int local_2c [5];
  undefined1 local_18 [16];
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar1 = media_readScoreBlock2((undefined4 *)(*(int *)(param_1 + 4) + 0x18),param_2,local_2c);
  if (iVar1 == 0) {
    iVar1 = (**(code **)*param_3)(param_3,&DAT_68176408,&local_8);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*local_8 + 0xc))(local_8,local_18);
      if (iVar1 == 0) {
        iVar1 = media_copyChannelMember(local_2c,(int)local_18,param_4);
      }
      (**(code **)(*local_8 + 8))(local_8);
    }
  }
  return iVar1;
}



// ============================================================
// Function: mediaPlayback_readCastData (FUN_680b11f0)
// Address: 680b11f0
// Size: 26 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_readCastData(int param_1,undefined4 param_2)
{
  media_readCastDataFromChannel((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getPlaybackRect (FUN_680b1210)
// Address: 680b1210
// Size: 41 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_getPlaybackRect(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *param_2 = *(undefined4 *)(iVar1 + 0x18);
  param_2[1] = *(undefined4 *)(iVar1 + 0x1c);
  param_2[2] = *(undefined4 *)(iVar1 + 0x20);
  param_2[3] = *(undefined4 *)(iVar1 + 0x24);
  return 0;
}



// ============================================================
// Function: mediaPlayback_setPlaybackRect (FUN_680b1240)
// Address: 680b1240
// Size: 41 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_setPlaybackRect(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x18) = *param_2;
  *(undefined4 *)(iVar1 + 0x1c) = param_2[1];
  *(undefined4 *)(iVar1 + 0x20) = param_2[2];
  *(undefined4 *)(iVar1 + 0x24) = param_2[3];
  return 0;
}



// ============================================================
// Function: mediaPlayback_clearPlaybackRectEx (FUN_680b1270)
// Address: 680b1270
// Size: 29 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_clearPlaybackRectEx(int param_1)

{
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x28) = 0;
  return 0;
}



// ============================================================
// Function: rendering_updateDisplay (FUN_680b1290)
// Address: 680b1290
// Size: 3 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_updateDisplay(void)
{
  return 0;
}



// ============================================================
// Function: mediaPlayback_dispatchChannelProperty (FUN_680b12a0)
// Address: 680b12a0
// Size: 32 bytes
// Params: int param_1, uint param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_dispatchChannelProperty(int param_1,uint param_2,uint *param_3)
{
  media_dispatchChannelProperty((int *)(*(int *)(param_1 + 4) + 0x18),1,param_2,param_3);
  return 0;
}




// ============================================================
// Function: mediaPlayback_getXtraMemberData (FUN_680b12c0)
// Address: 680b12c0
// Size: 26 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getXtraMemberData(int param_1,int param_2)
{
  media_getXtraMemberData((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getChannelMediaInfo (FUN_680b12e0)
// Address: 680b12e0
// Size: 26 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getChannelMediaInfo(int param_1,undefined4 param_2)
{
  media_getChannelMediaInfo((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_readXtraScoreSlot (FUN_680b1300)
// Address: 680b1300
// Size: 26 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_readXtraScoreSlot(int param_1,int param_2)
{
  media_readXtraScoreSlot((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_initChannelWithContext (FUN_680b1320)
// Address: 680b1320
// Size: 283 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_initChannelWithContext(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int *param_5)
{
  undefined4 uVar1;
  int *piVar2;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  undefined4 local_30;
  undefined4 local_2c;
  int *local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = param_4;
  local_28 = param_5;
  local_1c = *(int *)(*(int *)(param_1 + 4) + 0x18);
  local_24 = *(int *)(*(int *)(param_1 + 4) + 0x1c);
  if ((local_1c == 0) &&
     (lingo_resolveContext(&local_1c,(int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0),
     local_1c == 0)) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(local_1c + 0x20);
  }
  uVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    local_18 = local_1c;
    if (local_1c == 0) {
      local_18 = *piVar2;
    }
    if (piVar2[2] == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = *(undefined4 *)(piVar2[2] + 0xc);
    }
    Ordinal_2330();
    local_14 = local_18;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  props_clearValue(uVar1,&local_38);
  local_30 = param_3;
  local_3c = param_2;
  local_44 = 0;
  local_40 = 0;
  local_2c = local_20;
  media_initChannelState((int *)(*(int *)(param_1 + 4) + 0x18),&local_44);
  if (local_28 == (int *)0x0) {
    props_releaseAndClear(uVar1,&local_38);
  }
  else {
    *local_28 = local_38;
    local_28[1] = local_34;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_getChannelOffset (FUN_680b1440)
// Address: 680b1440
// Size: 26 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getChannelOffset(int param_1,undefined4 *param_2)
{
  media_getChannelOffset(*(int *)(param_1 + 4) + 0x18,param_2);
  return 0;
}



// ============================================================
// Function: mediaPlayback_resolveAndDispatch (FUN_680b1460)
// Address: 680b1460
// Size: 197 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_resolveAndDispatch(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  int local_24;
  int *local_20;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = param_2;
  local_18 = *(int *)(*(int *)(param_1 + 4) + 0x18);
  local_24 = *(int *)(*(int *)(param_1 + 4) + 0x1c);
  local_1c = param_1;
  if (local_18 == 0) {
    lingo_resolveContext(&local_18,(int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0);
    if (local_18 == 0) {
      piVar2 = (int *)0x0;
      goto LAB_680b14b2;
    }
  }
  piVar2 = *(int **)(local_18 + 0x20);
LAB_680b14b2:
  uVar3 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    uVar3 = *(undefined4 *)(piVar2[1] + 8);
    iVar1 = local_18;
    if (local_18 == 0) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    param_1 = local_1c;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  mediaPlayback_createXtraInstance(piVar2,uVar3,param_1,1,local_20);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_dispatchChannelPropertyOp (FUN_680b1530)
// Address: 680b1530
// Size: 42 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4, int * param_5, undefined1 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_dispatchChannelPropertyOp(int param_1,undefined4 param_2,uint param_3,uint *param_4,int *param_5,
                 undefined1 *param_6)
{
  media_dispatchChannelPropertyOp((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: mediaPlayback_getTransformData (FUN_680b1560)
// Address: 680b1560
// Size: 47 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_getTransformData(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *param_2 = *(undefined4 *)(iVar1 + 0x18);
  param_2[1] = *(undefined4 *)(iVar1 + 0x1c);
  param_2[2] = *(undefined4 *)(iVar1 + 0x20);
  param_2[3] = *(undefined4 *)(iVar1 + 0x24);
  param_2[4] = *(undefined4 *)(iVar1 + 0x28);
  return 0;
}



// ============================================================
// Function: mediaPlayback_clearCallbackState (FUN_680b1590)
// Address: 680b1590
// Size: 32 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_clearCallbackState(int param_1)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  scoreEngine_clearCallbackState(*(int *)(iVar1 + 0x2c),*(int *)(iVar1 + 0x30),*(int *)(iVar1 + 0x34));
  return 0;
}



// ============================================================
// Function: mediaPlayback_setCallbackState (FUN_680b15b0)
// Address: 680b15b0
// Size: 35 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_setCallbackState(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x2c) = *param_2;
  *(undefined4 *)(iVar1 + 0x30) = param_2[1];
  *(undefined4 *)(iVar1 + 0x34) = param_2[2];
  return 0;
}



// ============================================================
// Function: mediaPlayback_initXtraImageVtable (FUN_680b15e0)
// Address: 680b15e0
// Size: 102 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraImageVtable(void)

{
  if (DAT_681963b0 == '\0') {
    DAT_681963b0 = '\x01';
    _DAT_68198120 = media_invokeCallback;
    _DAT_68198124 = media_addRef;
    _DAT_68198128 = globals_release;
    _DAT_6819812c = media_getXtraImageRect;
    _DAT_68198130 = media_getXtraImageDepth;
    _DAT_68198134 = media_copyXtraMovieFields;
    _DAT_68198138 = media_updateXtraMovieState;
    _DAT_6819813c = media_queryXtraInterface;
  }
  return &DAT_68198120;
}



// ============================================================
// Function: mediaPlayback_initXtraInterfaceVtable (FUN_680b1650)
// Address: 680b1650
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraInterfaceVtable(void)

{
  if (DAT_681963b1 == '\0') {
    DAT_681963b1 = '\x01';
    _DAT_68198340 = media_invokeCallback;
    _DAT_68198344 = media_addRef;
    _DAT_68198348 = globals_release;
    _DAT_6819834c = media_queryXtraInterfaceEx;
  }
  return &DAT_68198340;
}



// ============================================================
// Function: mediaPlayback_initXtraMovieDataVtable (FUN_680b1690)
// Address: 680b1690
// Size: 82 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraMovieDataVtable(void)

{
  if (DAT_681963b2 == '\0') {
    DAT_681963b2 = '\x01';
    _DAT_681981e0 = media_invokeCallback;
    _DAT_681981e4 = media_addRef;
    _DAT_681981e8 = globals_release;
    _DAT_681981ec = media_getXtraMovieData;
    _DAT_681981f0 = media_setXtraMovieData;
    _DAT_681981f4 = media_getXtraMovieStateEx;
  }
  return &DAT_681981e0;
}



// ============================================================
// Function: mediaPlayback_initXtraDirtyCheckVtable (FUN_680b16f0)
// Address: 680b16f0
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraDirtyCheckVtable(void)

{
  if (DAT_681963b3 == '\0') {
    DAT_681963b3 = '\x01';
    _DAT_68197fe0 = media_invokeCallback;
    _DAT_68197fe4 = media_addRef;
    _DAT_68197fe8 = globals_release;
    _DAT_68197fec = media_checkXtraDirty;
    _DAT_68197ff0 = media_checkXtraDirty;
  }
  return &DAT_68197fe0;
}



// ============================================================
// Function: mediaPlayback_initXtraValueVtable (FUN_680b1740)
// Address: 680b1740
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraValueVtable(void)

{
  if (DAT_681963b4 == '\0') {
    DAT_681963b4 = '\x01';
    _DAT_68198360 = media_invokeCallback;
    _DAT_68198364 = media_addRef;
    _DAT_68198368 = globals_release;
    _DAT_6819836c = media_setXtraValue;
    _DAT_68198370 = media_getXtraValue;
    _DAT_68198374 = media_setXtraFlag;
    _DAT_68198378 = media_getXtraFlag;
  }
  return &DAT_68198360;
}



// ============================================================
// Function: mediaPlayback_initXtraPixelDataVtable (FUN_680b17a0)
// Address: 680b17a0
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraPixelDataVtable(void)

{
  if (DAT_681963b5 == '\0') {
    DAT_681963b5 = '\x01';
    _DAT_681984c0 = media_invokeCallback;
    _DAT_681984c4 = media_addRef;
    _DAT_681984c8 = globals_release;
    _DAT_681984cc = media_getXtraPixelData;
    _DAT_681984d0 = media_setXtraPixelByte;
    _DAT_681984d4 = media_setXtraPixelData;
    _DAT_681984d8 = media_resetXtraPixel;
  }
  return &DAT_681984c0;
}




// ============================================================
// Function: mediaPlayback_initXtraPixelFlushVtable (FUN_680b1800)
// Address: 680b1800
// Size: 112 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraPixelFlushVtable(void)

{
  if (DAT_681963b6 == '\0') {
    DAT_681963b6 = '\x01';
    _DAT_68198480 = media_invokeCallback;
    _DAT_68198484 = media_addRef;
    _DAT_68198488 = globals_release;
    _DAT_6819848c = media_getXtraPixelData;
    _DAT_68198490 = media_setXtraPixelByte;
    _DAT_68198494 = media_setXtraPixelData;
    _DAT_68198498 = media_resetXtraPixel;
    _DAT_6819849c = media_flushXtraPixel;
    _DAT_681984a0 = media_commitXtraPixel;
  }
  return &DAT_68198480;
}



// ============================================================
// Function: mediaPlayback_initXtraPixelBlockVtable (FUN_680b1870)
// Address: 680b1870
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraPixelBlockVtable(void)

{
  if (DAT_681963b7 == '\0') {
    DAT_681963b7 = '\x01';
    _DAT_68198140 = media_invokeCallback;
    _DAT_68198144 = media_addRef;
    _DAT_68198148 = globals_release;
    _DAT_6819814c = media_getXtraPixelBlock;
    _DAT_68198150 = mediaPlayback_dispatchChannelProperty;
    _DAT_68198154 = media_getXtraTransform;
    _DAT_68198158 = mediaPlayback_dispatchChannelPropertyOp;
  }
  return &DAT_68198140;
}



// ============================================================
// Function: mediaPlayback_initXtraTransformVtable (FUN_680b18d0)
// Address: 680b18d0
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraTransformVtable(void)

{
  if (DAT_681963b8 == '\0') {
    DAT_681963b8 = '\x01';
    _DAT_681980a0 = media_invokeCallback;
    _DAT_681980a4 = media_addRef;
    _DAT_681980a8 = globals_release;
    _DAT_681980ac = mediaPlayback_getTransformData;
    _DAT_681980b0 = media_setXtraTransform;
  }
  return &DAT_681980a0;
}



// ============================================================
// Function: mediaPlayback_initXtraPixelRegionVtable (FUN_680b1920)
// Address: 680b1920
// Size: 156 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraPixelRegionVtable(void)

{
  if (DAT_681963b9 == '\0') {
    DAT_681963b9 = '\x01';
    _DAT_681983c0 = media_invokeCallback;
    _DAT_681983c4 = media_addRef;
    _DAT_681983c8 = globals_release;
    _DAT_681983cc = media_getXtraPixelRegion;
    _DAT_681983d0 = media_getXtraPixelMap;
    _DAT_681983d4 = media_getXtraPixelPalette;
    _DAT_681983d8 = media_getXtraPixelFormat;
    _DAT_681983dc = media_setXtraPixelFormat;
    _DAT_681983e0 = media_finalizeXtraPixel;
    _DAT_681983e4 = media_getXtraPixelState;
    _DAT_681983e8 = media_resetXtraPixelState;
    _DAT_681983ec = media_setXtraPixelState;
    _DAT_681983f0 = media_clearXtraPixelState;
  }
  return &DAT_681983c0;
}



// ============================================================
// Function: mediaPlayback_initXtraAssetVtable (FUN_680b19c0)
// Address: 680b19c0
// Size: 296 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraAssetVtable(void)

{
  if (DAT_681963ba == '\0') {
    DAT_681963ba = '\x01';
    _DAT_68198160 = media_invokeCallback;
    _DAT_68198164 = media_addRef;
    _DAT_68198168 = globals_release;
    _DAT_6819816c = mediaPlayback_getMovieProperty;
    _DAT_68198170 = mediaPlayback_setMovieProperty;
    _DAT_68198174 = mediaPlayback_getCastSoundRef;
    _DAT_68198178 = mediaPlayback_setCastSoundRef;
    _DAT_6819817c = mediaPlayback_resolveScoreSlot;
    _DAT_68198180 = mediaPlayback_getCastPropertyPair;
    _DAT_68198184 = media_getXtraDataRef;
    _DAT_68198188 = media_createXtraFromData;
    _DAT_6819818c = media_createXtraFromRef;
    _DAT_68198190 = mediaPlayback_findCastMemberByName;
    _DAT_68198194 = mediaPlayback_findCastByName;
    _DAT_68198198 = mediaPlayback_findCastByNameEx;
    _DAT_6819819c = mediaPlayback_deleteCastMember;
    _DAT_681981a0 = mediaPlayback_getCastMemberPosition;
    _DAT_681981a4 = mediaPlayback_resolveScoreRef;
    _DAT_681981a8 = mediaPlayback_renderTransfer;
    _DAT_681981ac = mediaPlayback_getImageComInstance;
    _DAT_681981b0 = mediaPlayback_getLinkedImageComInstance;
    _DAT_681981b4 = mediaPlayback_getCastProperty;
    _DAT_681981b8 = mediaPlayback_getCastPropertyData;
    _DAT_681981bc = mediaPlayback_setCastProperty;
    _DAT_681981c0 = mediaPlayback_createXtraPlayer;
    _DAT_681981c4 = mediaPlayback_saveCastMember;
    _DAT_681981c8 = mediaPlayback_dispatchSpriteProperty;
  }
  return &DAT_68198160;
}



// ============================================================
// Function: mediaPlayback_initXtraAssetExVtable (FUN_680b1af0)
// Address: 680b1af0
// Size: 326 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraAssetExVtable(void)

{
  if (DAT_681963bb == '\0') {
    DAT_681963bb = '\x01';
    _DAT_68198200 = media_invokeCallback;
    _DAT_68198204 = media_addRef;
    _DAT_68198208 = globals_release;
    _DAT_6819820c = mediaPlayback_getMovieProperty;
    _DAT_68198210 = mediaPlayback_setMovieProperty;
    _DAT_68198214 = mediaPlayback_getCastSoundRef;
    _DAT_68198218 = mediaPlayback_setCastSoundRef;
    _DAT_6819821c = mediaPlayback_resolveScoreSlot;
    _DAT_68198220 = mediaPlayback_getCastPropertyPair;
    _DAT_68198224 = media_getXtraDataRef;
    _DAT_68198228 = media_createXtraFromData;
    _DAT_6819822c = media_createXtraFromRef;
    _DAT_68198230 = mediaPlayback_findCastMemberByName;
    _DAT_68198234 = mediaPlayback_findCastByName;
    _DAT_68198238 = mediaPlayback_findCastByNameEx;
    _DAT_6819823c = mediaPlayback_deleteCastMember;
    _DAT_68198240 = mediaPlayback_getCastMemberPosition;
    _DAT_68198244 = mediaPlayback_resolveScoreRef;
    _DAT_68198250 = mediaPlayback_renderTransfer;
    _DAT_68198254 = mediaPlayback_getImageComInstance;
    _DAT_68198258 = mediaPlayback_getLinkedImageComInstance;
    _DAT_6819825c = mediaPlayback_getCastProperty;
    _DAT_68198260 = mediaPlayback_getCastPropertyData;
    _DAT_68198264 = mediaPlayback_setCastProperty;
    _DAT_68198268 = mediaPlayback_createXtraPlayer;
    _DAT_6819826c = mediaPlayback_saveCastMember;
    _DAT_68198270 = mediaPlayback_dispatchSpriteProperty;
    _DAT_68198248 = mediaPlayback_findCastByGuid;
    _DAT_6819824c = mediaPlayback_getCastStreamGuid;
    _DAT_68198274 = mediaPlayback_convertCastPoint;
  }
  return &DAT_68198200;
}



// ============================================================
// Function: mediaPlayback_initXtraCallbackVtable (FUN_680b1c40)
// Address: 680b1c40
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraCallbackVtable(void)

{
  if (DAT_681963bc == '\0') {
    DAT_681963bc = '\x01';
    _DAT_68198020 = media_invokeCallback;
    _DAT_68198024 = media_addRef;
    _DAT_68198028 = globals_release;
    _DAT_6819802c = mediaPlayback_convertCastToStage;
    _DAT_68198030 = mediaPlayback_convertStageToCast;
  }
  return &DAT_68198020;
}



// ============================================================
// Function: mediaPlayback_initXtraValueReadVtable (FUN_680b1c90)
// Address: 680b1c90
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraValueReadVtable(void)

{
  if (DAT_681963bd == '\0') {
    DAT_681963bd = '\x01';
    _DAT_681980c0 = media_invokeCallback;
    _DAT_681980c4 = media_addRef;
    _DAT_681980c8 = globals_release;
    _DAT_681980cc = media_getXtraValue;
    _DAT_681980d0 = mediaPlayback_setInterfaceData;
  }
  return &DAT_681980c0;
}



// ============================================================
// Function: mediaPlayback_copyMovieStateData (FUN_680b1ce0)
// Address: 680b1ce0
// Size: 42 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_copyMovieStateData(int *param_1,undefined4 *param_2)
{
  int iVar1;
  int local_20 [7];
  
  iVar1 = crt_copyMovieState(param_1,local_20);
  if (iVar1 == 0) {
    mediaPlayback_createComInstance(local_20,param_2);
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_initXtraHandlerVtable (FUN_680b1d10)
// Address: 680b1d10
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraHandlerVtable(void)

{
  if (DAT_681963be == '\0') {
    DAT_681963be = '\x01';
    _DAT_68198100 = media_invokeCallback;
    _DAT_68198104 = media_addRef;
    _DAT_68198108 = globals_release;
    _DAT_6819810c = mediaPlayback_getSoundProperty;
    _DAT_68198110 = mediaPlayback_setSoundProperty;
  }
  return &DAT_68198100;
}



// ============================================================
// Function: mediaPlayback_initXtraValueReadAltVtable (FUN_680b1d60)
// Address: 680b1d60
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraValueReadAltVtable(void)

{
  if (DAT_681963bf == '\0') {
    DAT_681963bf = '\x01';
    _DAT_68198320 = media_invokeCallback;
    _DAT_68198324 = media_addRef;
    _DAT_68198328 = globals_release;
    _DAT_6819832c = media_getXtraValue;
    _DAT_68198330 = mediaPlayback_setInterfaceData;
  }
  return &DAT_68198320;
}



// ============================================================
// Function: mediaPlayback_initXtraStreamVtable (FUN_680b1db0)
// Address: 680b1db0
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraStreamVtable(void)

{
  if (DAT_681963c0 == '\0') {
    DAT_681963c0 = '\x01';
    _DAT_68198000 = media_invokeCallback;
    _DAT_68198004 = media_addRef;
    _DAT_68198008 = globals_release;
    _DAT_6819800c = mediaPlayback_getSoundChannelProperty;
    _DAT_68198010 = mediaPlayback_setSoundChannelProperty;
  }
  return &DAT_68198000;
}



// ============================================================
// Function: mediaPlayback_initXtraStreamReadVtable (FUN_680b1e00)
// Address: 680b1e00
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraStreamReadVtable(void)

{
  if (DAT_681963c1 == '\0') {
    DAT_681963c1 = '\x01';
    _DAT_68198300 = media_invokeCallback;
    _DAT_68198304 = media_addRef;
    _DAT_68198308 = globals_release;
    _DAT_6819830c = lingo_readStream;
    _DAT_68198310 = media_getInterfaceRef;
  }
  return &DAT_68198300;
}



// ============================================================
// Function: mediaPlayback_initXtraNotifyVtable (FUN_680b1e50)
// Address: 680b1e50
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraNotifyVtable(void)

{
  if (DAT_681963c2 == '\0') {
    DAT_681963c2 = '\x01';
    _DAT_68198080 = media_invokeCallback;
    _DAT_68198084 = media_addRef;
    _DAT_68198088 = globals_release;
    _DAT_6819808c = mediaPlayback_getScoreChannelProperty;
    _DAT_68198090 = mediaPlayback_setScoreChannelProperty;
  }
  return &DAT_68198080;
}



// ============================================================
// Function: mediaPlayback_initXtraStreamReadAltVtable (FUN_680b1ea0)
// Address: 680b1ea0
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraStreamReadAltVtable(void)

{
  if (DAT_681963c3 == '\0') {
    DAT_681963c3 = '\x01';
    _DAT_68198060 = media_invokeCallback;
    _DAT_68198064 = media_addRef;
    _DAT_68198068 = globals_release;
    _DAT_6819806c = lingo_readStream;
    _DAT_68198070 = media_getInterfaceRef;
  }
  return &DAT_68198060;
}



// ============================================================
// Function: mediaPlayback_initXtraScoreVtable (FUN_680b1ef0)
// Address: 680b1ef0
// Size: 246 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraScoreVtable(void)

{
  if (DAT_681963c4 == '\0') {
    DAT_681963c4 = '\x01';
    _DAT_68198280 = media_invokeCallback;
    _DAT_68198284 = media_addRef;
    _DAT_68198288 = globals_release;
    _DAT_6819828c = mediaPlayback_reinitXtraCall;
    _DAT_68198290 = mediaPlayback_initScorePlayback;
    _DAT_68198294 = mediaPlayback_writeScoreData;
    _DAT_68198298 = mediaPlayback_getScoreReaderRef;
    _DAT_6819829c = mediaPlayback_setScoreReaderRef;
    _DAT_681982a0 = mediaPlayback_setScoreReaderFromData;
    _DAT_681982a4 = mediaPlayback_validateSpriteOp;
    _DAT_681982a8 = mediaPlayback_flushSpriteOps;
    _DAT_681982ac = mediaPlayback_readWithFlush;
    _DAT_681982b0 = mediaPlayback_getOrdinal402;
    _DAT_681982b4 = mediaPlayback_getOrdinal401;
    _DAT_681982b8 = mediaPlayback_beginScorePlayback;
    _DAT_681982bc = mediaPlayback_resetScoreState;
    _DAT_681982c0 = mediaPlayback_resetScoreState;
    _DAT_681982c4 = mediaPlayback_advanceScoreFrame;
    _DAT_681982c8 = mediaPlayback_beginScorePlaybackEx;
    _DAT_681982cc = mediaPlayback_createScoreComObject;
    _DAT_681982d0 = mediaPlayback_createScoreComObjectEx;
    _DAT_681982d4 = mediaPlayback_createFilterGraph;
  }
  return &DAT_68198280;
}




// ============================================================
// Function: mediaPlayback_initXtraChannelVtable (FUN_680b1ff0)
// Address: 680b1ff0
// Size: 206 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraChannelVtable(void)

{
  if (DAT_681963c5 == '\0') {
    DAT_681963c5 = '\x01';
    _DAT_68198420 = media_invokeCallback;
    _DAT_68198424 = media_addRef;
    _DAT_68198428 = globals_release;
    _DAT_6819842c = mediaPlayback_getChannelProperty;
    _DAT_68198430 = mediaPlayback_getChannelPropertyAlt;
    _DAT_68198434 = mediaPlayback_resolveXtraContext;
    _DAT_68198438 = mediaPlayback_resetXtraState;
    _DAT_6819843c = mediaPlayback_getNextKeyframe;
    _DAT_68198440 = mediaPlayback_getChannelMode;
    _DAT_68198444 = mediaPlayback_getChannelSpan;
    _DAT_68198448 = mediaPlayback_getNextChannelFrame;
    _DAT_6819844c = mediaPlayback_getLastChannelFrame;
    _DAT_68198450 = mediaPlayback_getMemberDataBlock;
    _DAT_68198454 = mediaPlayback_readAndDispatchScore;
    _DAT_68198458 = mediaPlayback_importMemberFromChannel;
    _DAT_6819845c = mediaPlayback_updateChannelMediaRef;
    _DAT_68198460 = mediaPlayback_copyChannelMember;
    _DAT_68198464 = mediaPlayback_readCastData;
  }
  return &DAT_68198420;
}



// ============================================================
// Function: mediaPlayback_initXtraRectVtable (FUN_680b20c0)
// Address: 680b20c0
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraRectVtable(void)

{
  if (DAT_681963c6 == '\0') {
    DAT_681963c6 = '\x01';
    _DAT_681980e0 = media_invokeCallback;
    _DAT_681980e4 = media_addRef;
    _DAT_681980e8 = globals_release;
    _DAT_681980ec = mediaPlayback_getPlaybackRect;
    _DAT_681980f0 = mediaPlayback_setPlaybackRect;
  }
  return &DAT_681980e0;
}



// ============================================================
// Function: mediaPlayback_initXtraScoreChannelVtable (FUN_680b2110)
// Address: 680b2110
// Size: 142 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraScoreChannelVtable(void)

{
  if (DAT_681963c7 == '\0') {
    DAT_681963c7 = '\x01';
    _DAT_68198380 = media_invokeCallback;
    _DAT_68198384 = media_addRef;
    _DAT_68198388 = globals_release;
    _DAT_6819838c = media_getXtraPixelBlock;
    _DAT_68198390 = mediaPlayback_dispatchChannelProperty;
    _DAT_68198394 = mediaPlayback_getXtraMemberData;
    _DAT_68198398 = mediaPlayback_getChannelMediaInfo;
    _DAT_6819839c = mediaPlayback_readXtraScoreSlot;
    _DAT_681983a0 = mediaPlayback_initChannelWithContext;
    _DAT_681983a4 = mediaPlayback_getChannelOffset;
    _DAT_681983a8 = mediaPlayback_resolveAndDispatch;
    _DAT_681983ac = mediaPlayback_dispatchChannelPropertyOp;
  }
  return &DAT_68198380;
}



// ============================================================
// Function: mediaPlayback_initXtraTransformAltVtable (FUN_680b21a0)
// Address: 680b21a0
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraTransformAltVtable(void)

{
  if (DAT_681963c8 == '\0') {
    DAT_681963c8 = '\x01';
    _DAT_681982e0 = media_invokeCallback;
    _DAT_681982e4 = media_addRef;
    _DAT_681982e8 = globals_release;
    _DAT_681982ec = mediaPlayback_getTransformData;
    _DAT_681982f0 = media_setXtraTransform;
  }
  return &DAT_681982e0;
}



// ============================================================
// Function: mediaPlayback_initXtraCallbackClearVtable (FUN_680b21f0)
// Address: 680b21f0
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraCallbackClearVtable(void)

{
  if (DAT_681963c9 == '\0') {
    DAT_681963c9 = '\x01';
    _DAT_68198040 = media_invokeCallback;
    _DAT_68198044 = media_addRef;
    _DAT_68198048 = globals_release;
    _DAT_6819804c = mediaPlayback_clearCallbackState;
  }
  return &DAT_68198040;
}



// ============================================================
// Function: mediaPlayback_initXtraCallbackSetVtable (FUN_680b2230)
// Address: 680b2230
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * mediaPlayback_initXtraCallbackSetVtable(void)

{
  if (DAT_681963ca == '\0') {
    DAT_681963ca = '\x01';
    _DAT_68198400 = media_invokeCallback;
    _DAT_68198404 = media_addRef;
    _DAT_68198408 = globals_release;
    _DAT_6819840c = mediaPlayback_setCallbackState;
  }
  return &DAT_68198400;
}



// ============================================================
// Function: mediaPlayback_createXtraImageObject (FUN_680b2270)
// Address: 680b2270
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraImageObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraImageVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraInterfaceObject (FUN_680b22d0)
// Address: 680b22d0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraInterfaceObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraInterfaceVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraMovieDataObject (FUN_680b2330)
// Address: 680b2330
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraMovieDataObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraMovieDataVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraDirtyCheckObject (FUN_680b2390)
// Address: 680b2390
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraDirtyCheckObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraDirtyCheckVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraValueObject (FUN_680b23f0)
// Address: 680b23f0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraValueObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraValueVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraPixelDataObject (FUN_680b2450)
// Address: 680b2450
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraPixelDataObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraPixelDataVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraPixelFlushObject (FUN_680b24b0)
// Address: 680b24b0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraPixelFlushObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraPixelFlushVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraPixelBlockObject (FUN_680b2510)
// Address: 680b2510
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraPixelBlockObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraPixelBlockVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}




// ============================================================
// Function: mediaPlayback_createXtraTransformObject (FUN_680b2570)
// Address: 680b2570
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraTransformObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraTransformVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraPixelRegionObject (FUN_680b25d0)
// Address: 680b25d0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraPixelRegionObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraPixelRegionVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraAssetObject (FUN_680b2630)
// Address: 680b2630
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraAssetObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraAssetVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraAssetExObject (FUN_680b2690)
// Address: 680b2690
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraAssetExObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraAssetExVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraCallbackObject (FUN_680b26f0)
// Address: 680b26f0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraCallbackObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraCallbackVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraValueReadObject (FUN_680b2750)
// Address: 680b2750
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraValueReadObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraValueReadVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraHandlerObject (FUN_680b27b0)
// Address: 680b27b0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraHandlerObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraHandlerVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraValueReadAltObject (FUN_680b2810)
// Address: 680b2810
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraValueReadAltObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraValueReadAltVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraStreamObject (FUN_680b2870)
// Address: 680b2870
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraStreamObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraStreamVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraStreamReadObject (FUN_680b28d0)
// Address: 680b28d0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraStreamReadObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraStreamReadVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraNotifyObject (FUN_680b2930)
// Address: 680b2930
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraNotifyObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraNotifyVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraStreamReadAltObject (FUN_680b2990)
// Address: 680b2990
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraStreamReadAltObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraStreamReadAltVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraScoreObject (FUN_680b29f0)
// Address: 680b29f0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraScoreObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraScoreVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}




// ============================================================
// Function: mediaPlayback_createXtraChannelObject (FUN_680b2a50)
// Address: 680b2a50
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraChannelObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraChannelVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraRectObject (FUN_680b2ab0)
// Address: 680b2ab0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraRectObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraRectVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraScoreChannelObject (FUN_680b2b10)
// Address: 680b2b10
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraScoreChannelObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraScoreChannelVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraTransformAltObject (FUN_680b2b70)
// Address: 680b2b70
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraTransformAltObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraTransformAltVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraCallbackClearObject (FUN_680b2bd0)
// Address: 680b2bd0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraCallbackClearObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraCallbackClearVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_createXtraCallbackSetObject (FUN_680b2c30)
// Address: 680b2c30
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_createXtraCallbackSetObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = mediaPlayback_initXtraCallbackSetVtable();
  piVar2 = lingo_createObject(param_1,0xc,lingo_noop,puVar1,piVar2);
  if (piVar2 == (int *)0x0) {
    iVar3 = -0x7ffbfffe;
  }
  else {
    iVar3 = 0;
    if (local_8 != 0) {
      (**(code **)(*piVar2 + 8))(piVar2);
      *param_2 = 0;
      return local_8;
    }
  }
  *param_2 = piVar2;
  return iVar3;
}



// ============================================================
// Function: mediaPlayback_releaseSlotEntry (FUN_680b2c90)
// Address: 680b2c90
// Size: 16 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall mediaPlayback_releaseSlotEntry(int *param_1)
{
  int in_EAX;
  
  Ordinal_1384(*(undefined4 *)(in_EAX * 0x20 + 0x3c + *param_1));
  return 0;
}



// ============================================================
// Function: mediaPlayback_getEntryCount (FUN_680b2ca0)
// Address: 680b2ca0
// Size: 25 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_getEntryCount(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *(undefined4 *)(*param_1 + 0x10);
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_getSlotValue (FUN_680b2cc0)
// Address: 680b2cc0
// Size: 50 bytes
// Params: int * param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_getSlotValue(int *param_1,int param_2,undefined4 *param_3)

{
  if (((param_1 != (int *)0x0) && (0 < param_2)) && (param_2 <= *(int *)(*param_1 + 0x10))) {
    *param_3 = *(undefined4 *)(param_2 * 0x20 + *param_1);
    return 0;
  }
  return 0x800407d8;
}



// ============================================================
// Function: mediaPlayback_getSlotData (FUN_680b2d00)
// Address: 680b2d00
// Size: 51 bytes
// Params: int * param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_getSlotData(int *param_1,int param_2,undefined4 *param_3)

{
  if (((param_1 != (int *)0x0) && (0 < param_2)) && (param_2 <= *(int *)(*param_1 + 0x10))) {
    *param_3 = *(undefined4 *)(param_2 * 0x20 + 0x18 + *param_1);
    return 0;
  }
  return 0x800407d8;
}



// ============================================================
// Function: mediaPlayback_notifySlotRead (FUN_680b2d40)
// Address: 680b2d40
// Size: 89 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_notifySlotRead(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_68176118,&local_8);
  iVar2 = 0;
  if (iVar1 != -0x7ffbfffc) {
    iVar1 = (**(code **)(*local_8 + 0xc))(local_8,param_3,0,0);
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar2;
}



// ============================================================
// Function: mediaPlayback_notifySlotWrite (FUN_680b2da0)
// Address: 680b2da0
// Size: 89 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_notifySlotWrite(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *local_8;
  
  local_8 = (int *)0x0;
  iVar1 = (**(code **)*param_2)(param_2,&DAT_68176118,&local_8);
  iVar2 = 0;
  if (iVar1 != -0x7ffbfffc) {
    iVar1 = (**(code **)(*local_8 + 0x10))(local_8,param_3,0,0);
    if (iVar1 != 0) {
      iVar2 = iVar1;
    }
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar2;
}



// ============================================================
// Function: mediaPlayback_releaseObject (FUN_680b2e00)
// Address: 680b2e00
// Size: 24 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 mediaPlayback_releaseObject(int *param_1)

{
  if (param_1 != (int *)0x0) {
    (**(code **)(*param_1 + 8))(param_1);
  }
  return 0;
}



// ============================================================
// Function: mediaPlayback_setNotifyParam (FUN_680b2e20)
// Address: 680b2e20
// Size: 74 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_setNotifyParam(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_8;
  
  iVar1 = 0;
  local_8 = (int *)0x0;
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&DAT_681764a8,&local_8), iVar1 == 0)) {
    (**(code **)(*local_8 + 0x10))(local_8,param_2);
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar1;
}



// ============================================================
// Function: mediaPlayback_getNotifyParam (FUN_680b2e70)
// Address: 680b2e70
// Size: 74 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int mediaPlayback_getNotifyParam(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int *local_8;
  
  iVar1 = 0;
  local_8 = (int *)0x0;
  if ((param_1 != (undefined4 *)0x0) &&
     (iVar1 = (**(code **)*param_1)(param_1,&DAT_681764a8,&local_8), iVar1 == 0)) {
    (**(code **)(*local_8 + 0xc))(local_8,param_2);
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar1;
}



// ============================================================
// Function: media_setVtableEntry (FUN_680b2ec0)
// Address: 680b2ec0
// Size: 43 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_setVtableEntry(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_1;
  piVar1 = piVar3 + 4;
  iVar2 = 0;
  if (0 < *piVar1) {
    do {
      piVar3 = piVar3 + 8;
      iVar2 = iVar2 + 1;
      if (*piVar3 == param_2) {
        return iVar2;
      }
    } while (iVar2 < *piVar1);
  }
  return 0;
}



