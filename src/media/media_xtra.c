// Module: media
// Topic: Xtra/plugin operations, scripting interfaces, rendering hooks, and callbacks
// Address range: 0x680ad520 - 0x680affd0
// Functions (87):
//   media_forwardXtraCall (FUN_680ad520)
//   media_flushSpriteOps (FUN_680ad550)
//   media_readWithFlush (FUN_680ad5c0)
//   media_resolveXtraContext (FUN_680ad600)
//   media_resetXtraState (FUN_680ad730)
//   media_getXtraMemberData (FUN_680ad750)
//   media_readXtraScoreSlot (FUN_680ad950)
//   media_resetXtraVtable (FUN_680ad990)
//   media_dispatchXtraVtable (FUN_680ad9d0)
//   media_invokeXtraHandler (FUN_680ada10)
//   media_invokeXtraMethod (FUN_680ada50)
//   media_invokeXtraNotify (FUN_680ada80)
//   media_getXtraCallbackRef
//   media_setXtraCallback
//   media_getXtraCallback
//   media_copyXtraCallback (FUN_680adc40)
//   media_createXtraInstance (FUN_680adcd0)
//   media_destroyXtraInstance (FUN_680adda0)
//   media_callXtraWithInstance (FUN_680addd0)
//   media_dispatchXtraEvent (FUN_680ade30)
//   media_createXtraPlugin (FUN_680adeb0)
//   media_createXtraPluginEx (FUN_680ae010)
//   media_initXtraDispatch (FUN_680ae120)
//   media_destroyXtraDispatch (FUN_680ae570)
//   media_getXtraSlotIndex (FUN_680ae670)
//   media_initXtraCallback
//   media_getNextXtraSlot (FUN_680ae880)
//   media_resolveXtraEventType (FUN_680ae8a0)
//   media_getXtraEventName (FUN_680aea30)
//   media_registerXtraEvent (FUN_680aeb20)
//   media_adjustXtraIndices (FUN_680aecf0)
//   media_unregisterXtraEvent (FUN_680aed20)
//   media_dispatchXtraNotify (FUN_680aef70)
//   media_notifyXtraProperty (FUN_680af330)
//   media_fireAllXtraEvents (FUN_680af460)
//   media_clearXtraSlot (FUN_680af560)
//   media_queryXtraMethod
//   media_initXtraDispatchWrapper (FUN_680af620)
//   media_destroyXtraDispatchWrapper (FUN_680af640)
//   media_queryXtraService (FUN_680af650)
//   rendering_onPause (FUN_680af6a0)
//   media_registerXtraDefault (FUN_680af780)
//   media_registerXtraEventEx (FUN_680af7d0)
//   media_unregisterXtraDefault (FUN_680af810)
//   media_unregisterXtraEventEx (FUN_680af850)
//   media_queryXtraProperty
//   media_queryXtraPropertyEx
//   media_getXtraMovieState (FUN_680af8e0)
//   media_getXtraImageRect (FUN_680af900)
//   media_getXtraImageDepth (FUN_680af920)
//   media_copyXtraMovieFields (FUN_680af940)
//   media_updateXtraMovieState (FUN_680af960)
//   media_queryXtraInterface (FUN_680af980)
//   media_queryXtraInterfaceEx (FUN_680afa10)
//   media_getXtraMovieData (FUN_680afaf0)
//   media_setXtraMovieData (FUN_680afb10)
//   media_getXtraMovieStateEx (FUN_680afb30)
//   media_resetXtraFields (FUN_680afb50)
//   media_checkXtraDirty (FUN_680afb70)
//   media_setXtraValue (FUN_680afba0)
//   media_getXtraValue (FUN_680afbc0)
//   media_setXtraFlag (FUN_680afbe0)
//   media_getXtraFlag (FUN_680afc00)
//   media_addRef (media_addRef)
//   media_getXtraPixelData (FUN_680afc50)
//   media_setXtraPixelByte (FUN_680afc70)
//   media_setXtraPixelData (FUN_680afc90)
//   media_resetXtraPixel (FUN_680afcb0)
//   media_flushXtraPixel (FUN_680afcd0)
//   media_commitXtraPixel (FUN_680afcf0)
//   media_getXtraPixelBlock (FUN_680afd10)
//   media_getXtraTransform (FUN_680afd30)
//   media_setXtraTransform (FUN_680afd50)
//   media_getXtraPixelRegion (FUN_680afd80)
//   media_getXtraPixelMap (FUN_680afdb0)
//   media_getXtraPixelPalette (FUN_680afdd0)
//   media_getXtraPixelFormat (FUN_680afdf0)
//   media_setXtraPixelFormat (FUN_680afe10)
//   media_finalizeXtraPixel (FUN_680afe30)
//   media_getXtraPixelState (FUN_680afe50)
//   media_resetXtraPixelState (FUN_680afe70)
//   media_setXtraPixelState (FUN_680afea0)
//   media_clearXtraPixelState (FUN_680afec0)
//   media_getXtraDataRef (FUN_680afee0)
//   media_createXtraFactory (FUN_680aff00)
//   media_createXtraFromData (FUN_680aff90)
//   media_createXtraFromRef (FUN_680affd0)

// ============================================================
// Function: media_forwardXtraCall (FUN_680ad520)
// Address: 680ad520
// Size: 44 bytes
// Params: int * param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_forwardXtraCall(int *param_1,undefined4 param_2,int *param_3)
{
  int local_1c [6];
  
  local_1c[0] = 0;
  local_1c[1] = 0;
  local_1c[2] = 0;
  media_initScorePlayback(param_1,param_2,local_1c,param_3);
  return 0;
}



// ============================================================
// Function: media_flushSpriteOps (FUN_680ad550)
// Address: 680ad550
// Size: 110 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_flushSpriteOps(int param_1)

{
  int iVar1;
  uint uVar2;
  
  if (*(int *)(param_1 + 8) != 0) {
    iVar1 = lingo_getSpriteOp(*(int *)(param_1 + 4));
    if (iVar1 == 0) {
      media_beginScorePlayback(param_1);
    }
    else {
      iVar1 = lingo_getSpriteOp(*(int *)(param_1 + 4));
      while (iVar1 != 0) {
        media_beginScorePlayback(param_1);
        iVar1 = lingo_getSpriteOp(*(int *)(param_1 + 4));
      }
    }
    uVar2 = lingo_getSpriteOpData(*(int **)(param_1 + 4));
    if (uVar2 == 0) {
      return 0x80040014;
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return 0;
}



// ============================================================
// Function: media_readWithFlush (FUN_680ad5c0)
// Address: 680ad5c0
// Size: 54 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_readWithFlush(int param_1,undefined4 param_2)

{
  int iVar1;
  void *this;
  
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 != 0) {
    media_flushSpriteOps(param_1);
  }
  media_readPlaybackData(*(int *)(param_1 + 4),param_2,1);
  if (iVar1 != 0) {
    media_validateSpriteOp(this,param_1);
  }
  return 0;
}



// ============================================================
// Function: media_resolveXtraContext (FUN_680ad600)
// Address: 680ad600
// Size: 304 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resolveXtraContext(int *param_1,int *param_2,int *param_3)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int local_44 [3];
  int local_38;
  uint local_34 [2];
  int *local_2c;
  int local_28;
  int *local_24;
  int local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = param_1[1];
  local_24 = param_3;
  local_20 = *param_1;
  piVar2 = (int *)0x0;
  local_2c = param_2;
  local_18 = 0;
  if (local_20 == 0) {
    lingo_resolveContext(&local_20,(int *)0x0,(int *)0x0,&local_28,(int *)0x0,(int *)0x0,(int *)0x0);
    if (local_20 == 0) goto LAB_680ad652;
  }
  piVar2 = *(int **)(local_20 + 0x20);
LAB_680ad652:
  local_1c = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar3 = local_20;
    if (local_20 == 0) {
      iVar3 = *piVar2;
    }
    if (piVar2[2] == 0) {
      local_1c = 0;
    }
    else {
      local_1c = *(undefined4 *)(piVar2[2] + 0xc);
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    param_2 = local_2c;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  if ((param_2 == (int *)0x0) || (*param_2 == *param_1)) {
    *local_24 = param_1[3];
  }
  else {
    local_18 = media_getChannelPropertyEx(param_1,1,0x103,local_34);
    if (local_18 == 0) {
      piVar1 = props_getApiContext((int *)local_34);
      if (piVar1 != (int *)0x0) {
        local_18 = media_findCastMemberByName(param_2,piVar1,local_44);
      }
      props_getApiState((int *)local_34);
      props_releaseAndClear(local_1c,(int *)local_34);
      *local_24 = local_38;
    }
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_resetXtraState (FUN_680ad730)
// Address: 680ad730
// Size: 22 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resetXtraState(int *param_1,int *param_2)
{
  media_getNextKeyframe(param_1,0,param_2);
  return 0;
}



// ============================================================
// Function: media_getXtraMemberData (FUN_680ad750)
// Address: 680ad750
// Size: 501 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraMemberData(int *param_1,int param_2)
{
  short sVar1;
  undefined2 extraout_var;
  HGLOBAL pvVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  LPVOID pvVar6;
  SIZE_T SVar7;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 uVar8;
  int iVar9;
  UINT uFlags;
  int local_44;
  int local_40;
  HGLOBAL local_3c;
  int local_2c;
  int local_28;
  int local_24;
  int *local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar9 = 0;
  *(undefined4 *)(param_2 + 8) = 0;
  local_2c = param_1[1];
  local_24 = param_2;
  local_28 = *param_1;
  if ((local_28 == 0) &&
     (lingo_resolveContext(&local_28,(int *)0x0,(int *)0x0,&local_2c,(int *)0x0,(int *)0x0,(int *)0x0),
     local_28 == 0)) {
    local_20 = (int *)0x0;
  }
  else {
    local_20 = *(int **)(local_28 + 0x20);
  }
  piVar3 = local_20;
  local_1c = 0;
  if ((local_20 != (int *)0x0) && (local_20[1] != 0)) {
    iVar9 = *(int *)(local_20[1] + 8);
    local_1c = local_28;
    if (local_28 == 0) {
      local_1c = *local_20;
    }
    Ordinal_2330();
    local_14 = local_1c;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  local_18 = (HGLOBAL)CONCAT22((short)param_1[4],(short)param_1[3]);
  pvVar2 = local_18;
  if (param_1[2] == 0) {
    if (piVar3 == (int *)0x0) {
      return 0;
    }
    sVar1 = scoreEngine_getChannelData((int)piVar3,(short)param_1[3]);
    pvVar2 = (HGLOBAL)CONCAT22(extraout_var,sVar1);
  }
  piVar3 = (int *)rendering_resolveState(iVar9,pvVar2);
  iVar9 = local_24;
  piVar4 = (int *)media_mapMediaTypeToIndex();
  uVar8 = extraout_ECX;
  if ((piVar3 != (int *)0x0) && (piVar3[2] != 0)) {
    rendering_resolveMemberData(*(undefined4 **)(local_1c + 0x20),piVar3,piVar4,0);
    uVar8 = extraout_ECX_00;
  }
  if (local_44 == 4) {
    if (local_3c != (HGLOBAL)0x0) goto LAB_680ad8b7;
    media_renderScoreFrame(*(int *)(local_1c + 0x20),piVar3,(int)&local_44);
    uVar8 = extraout_ECX_01;
  }
  if ((((local_44 == 1) && (local_40 == 0)) && (local_3c != (HGLOBAL)0x0)) &&
     (iVar5 = media_copyToGlobalAlloc(local_3c,&local_18), uVar8 = extraout_ECX_02, iVar5 == 0)) {
    local_3c = local_18;
  }
LAB_680ad8b7:
  pvVar2 = local_3c;
  if (((*(int *)(iVar9 + 4) == 0x29b) && (local_3c != (HGLOBAL)0x0)) &&
     (pvVar6 = GlobalLock(local_3c), uVar8 = extraout_ECX_03, pvVar6 != (LPVOID)0x0)) {
    SVar7 = GlobalSize(pvVar2);
    Ordinal_1128(pvVar6,(int)pvVar6 + 0xe,SVar7 - 0xe);
    GlobalUnlock(pvVar2);
    uFlags = 2;
    SVar7 = GlobalSize(pvVar2);
    local_3c = GlobalReAlloc(pvVar2,SVar7 - 0xe,uFlags);
    uVar8 = extraout_ECX_04;
  }
  media_mapIndexToMediaType(uVar8,&local_44);
  media_getMediaErrorCode();
  if (local_20 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_readXtraScoreSlot (FUN_680ad950)
// Address: 680ad950
// Size: 52 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_readXtraScoreSlot(int *param_1,int param_2)

{
  int iVar1;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 8) == 0)) {
    iVar1 = -0x7ffbffff;
  }
  else {
    iVar1 = media_getChannelMediaInfo(param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = media_readScoreSlot(param_2);
      return iVar1;
    }
  }
  return iVar1;
}



// ============================================================
// Function: media_resetXtraVtable (FUN_680ad990)
// Address: 680ad990
// Size: 54 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_resetXtraVtable(undefined4 *param_1)

{
  undefined4 uVar1;
  
  media_flushSpriteOps((int)param_1);
  uVar1 = media_getVtableFunc((int *)param_1[1]);
  uVar1 = Ordinal_1112(uVar1);
  *param_1 = uVar1;
  media_getScorePlayState(param_1 + 1);
  Ordinal_1113(param_1);
  return 0;
}



// ============================================================
// Function: media_dispatchXtraVtable (FUN_680ad9d0)
// Address: 680ad9d0
// Size: 54 bytes
// Params: int * param_1, undefined4 param_2, int param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_dispatchXtraVtable(int *param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    return 0x80040001;
  }
  if (param_3 != 0) {
    uVar1 = (**(code **)(*param_1 + 0x10))();
    return uVar1;
  }
  uVar1 = (**(code **)(*param_1 + 0xc))(param_1,param_2,param_4);
  return uVar1;
}



// ============================================================
// Function: media_invokeXtraHandler (FUN_680ada10)
// Address: 680ada10
// Size: 52 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_invokeXtraHandler(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    return 0x80040001;
  }
  uVar1 = (**(code **)(*param_1 + 0x30))
                    (param_1,*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0x14),
                     *(undefined4 *)(param_2 + 0x18),param_2 + 0xc);
  return uVar1;
}



// ============================================================
// Function: media_invokeXtraMethod (FUN_680ada50)
// Address: 680ada50
// Size: 39 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_invokeXtraMethod(int *param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    return 0x80040001;
  }
  uVar1 = (**(code **)(*param_1 + 0x2c))(param_1,param_2,param_3);
  return uVar1;
}



// ============================================================
// Function: media_invokeXtraNotify (FUN_680ada80)
// Address: 680ada80
// Size: 35 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_invokeXtraNotify(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 == (int *)0x0) {
    return 0x80040001;
  }
  uVar1 = (**(code **)(*param_1 + 0x34))(param_1,param_2);
  return uVar1;
}



// ============================================================
// Function: media_getXtraCallbackRef (FUN_680adab0)
// Address: 680adab0
// Size: 39 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getXtraCallbackRef(int *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (param_2 != 0)) {
    uVar1 = (**(code **)(*param_1 + 0x20))(param_1,param_2);
    return uVar1;
  }
  return 0x80040001;
}



// ============================================================
// Function: media_setXtraCallback (FUN_680adae0)
// Address: 680adae0
// Size: 222 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_setXtraCallback(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 local_34 [10];
  int *local_c;
  int local_8;
  
  piVar1 = param_1;
  local_8 = 0;
  local_c = (int *)0x0;
  if (param_1 == (int *)0x0) {
    return -0x7ffbffff;
  }
  iVar3 = (**(code **)(*param_1 + 0x20))(param_1,&local_8);
  if (param_3 < local_8) {
    iVar3 = -0x7ffbffff;
  }
  else {
    param_1 = (int *)stage_createBytecodeBlock(0x20,0x1c,local_8);
    if (param_1 != (int *)0x0) {
      strings_createMediaStream(local_34,param_1,*(undefined4 *)(*param_1 + 0x10));
      iVar3 = media_queryXtraMethod(local_34,0xffffffff,local_8,&local_c);
      if (iVar3 == 0) {
        iVar3 = (**(code **)(*piVar1 + 0x18))(piVar1,local_c);
      }
      uVar2 = param_2;
      uVar4 = Ordinal_1114(param_2);
      Ordinal_1129(uVar4,(int)*(short *)(*param_1 + 0x18) + *param_1,local_8);
      Ordinal_1115(uVar2);
      stage_getBytecodeSize(param_1);
      Ordinal_1113(&param_1);
    }
  }
  if (local_c != (int *)0x0) {
    (**(code **)(*local_c + 8))(local_c);
  }
  return iVar3;
}



// ============================================================
// Function: media_getXtraCallback (FUN_680adbc0)
// Address: 680adbc0
// Size: 119 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getXtraCallback(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 local_30 [10];
  int *local_8;
  
  local_8 = (int *)0x0;
  if (param_1 == (int *)0x0) {
    return -0x7ffbffff;
  }
  strings_writeMediaData(local_30,param_2,0x79f,0,param_3);
  iVar1 = media_queryXtraMethod(local_30,0xffffffff,param_3,&local_8);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*param_1 + 0x1c))(param_1,local_8);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar1;
}



// ============================================================
// Function: media_copyXtraCallback (FUN_680adc40)
// Address: 680adc40
// Size: 144 bytes
// Params: int * param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_copyXtraCallback(int *param_1,int *param_2)

{
  int iVar1;
  int local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  if ((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) {
    iVar1 = (**(code **)(*param_1 + 0x20))(param_1,&local_8);
    if (iVar1 == 0) {
      local_c = cast_allocHandle(local_8,1);
      if (local_c == 0) {
        return 0;
      }
      iVar1 = media_setXtraCallback(param_1,local_c,local_8);
      if (iVar1 == 0) {
        iVar1 = media_getXtraCallback(param_2,local_c,local_8);
      }
    }
    if (local_c != 0) {
      Ordinal_1113(&local_c);
    }
    return iVar1;
  }
  return -0x7ffbffff;
}



// ============================================================
// Function: media_createXtraInstance (FUN_680adcd0)
// Address: 680adcd0
// Size: 203 bytes
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * media_createXtraInstance(void)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int *unaff_EBX;
  int unaff_EDI;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  int *local_8;
  
  *in_EAX = 0;
  local_8 = (int *)0x0;
  *unaff_EBX = 0;
  piVar4 = local_c;
  if (unaff_EDI != 0) {
    Ordinal_1689();
    iVar2 = Ordinal_1600();
    *in_EAX = iVar2;
    if (iVar2 != 0) {
      Ordinal_1604(iVar2);
    }
    Ordinal_2040(*in_EAX);
    piVar1 = (int *)*unaff_EBX;
    piVar4 = local_c;
    if (piVar1 != (int *)0x0) {
      if (*piVar1 == 2) {
        local_20 = 2;
        local_1c = piVar1[4];
        local_18 = piVar1[7];
        local_14 = piVar1[6];
        local_10 = piVar1[1];
      }
      uVar3 = Ordinal_1038();
      piVar4 = (int *)Ordinal_2075(uVar3);
      iVar2 = (**(code **)*piVar4)(piVar4,&DAT_68175d18,&local_8);
      if (iVar2 == 0) {
        (**(code **)(*local_8 + 0x74))(local_8,&local_20,&local_c);
      }
    }
  }
  if (piVar4 != (int *)0x0) {
    (**(code **)(*piVar4 + 8))(piVar4);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return local_c;
}



// ============================================================
// Function: media_destroyXtraInstance (FUN_680adda0)
// Address: 680adda0
// Size: 44 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_destroyXtraInstance(void)
{
  int *in_EAX;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (*in_EAX != 0) {
    Ordinal_2041();
  }
  if (*unaff_ESI != 0) {
    Ordinal_1604(*unaff_ESI,0);
    Ordinal_1601();
  }
  if (unaff_EDI != (int *)0x0) {
    (**(code **)(*unaff_EDI + 8))();
  }
  return 0;
}



// ============================================================
// Function: media_callXtraWithInstance (FUN_680addd0)
// Address: 680addd0
// Size: 82 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_callXtraWithInstance(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  undefined4 local_10;
  
  local_10 = 0;
  piVar1 = media_createXtraInstance();
  if (piVar1 != (int *)0x0) {
    local_10 = (**(code **)(*param_1 + 0x14))(param_1,piVar1,param_3);
  }
  media_destroyXtraInstance();
  return local_10;
}



// ============================================================
// Function: media_dispatchXtraEvent (FUN_680ade30)
// Address: 680ade30
// Size: 120 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_dispatchXtraEvent(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  local_8 = (int *)0x0;
  uVar1 = Ordinal_1038(&DAT_681764d8,&DAT_68175c48,param_1);
  Ordinal_2063(uVar1);
  iVar2 = (*(code *)**(undefined4 **)*param_1)((undefined4 *)*param_1,&DAT_68175c38,&local_8);
  if (iVar2 == 0) {
    local_10 = param_3;
    local_c = param_4;
    local_14 = param_2;
    (**(code **)(*local_8 + 0xc))(local_8,&local_14);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar2;
}



// ============================================================
// Function: media_createXtraPlugin (FUN_680adeb0)
// Address: 680adeb0
// Size: 352 bytes
// Params: int param_1, int param_2, undefined4 * param_3, undefined4 * param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_createXtraPlugin(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4,undefined4 param_5
                 )
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int iVar5;
  int *local_24;
  undefined4 *local_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  *param_3 = 0;
  local_1c = (int *)0x0;
  iVar5 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_20 = param_3;
  if ((iVar5 != 0) && (iVar2 = *(int *)(iVar5 + 0x20), iVar2 != 0)) {
    iVar1 = *(int *)(iVar2 + 8);
    iVar2 = scoreEngine_setScoreContext(iVar2,param_2);
    if (((iVar2 != 0) &&
        (((piVar3 = (int *)lingo_getGlobalRef(iVar1), piVar3 != (int *)0x0 &&
          (iVar2 = media_setVtableEntry(piVar3,param_2), 0 < iVar2)) &&
         (iVar2 = mediaPlayback_getSlotData(piVar3,iVar2,&local_24), iVar2 == 0)))) && (local_24 != (int *)0x0))
    {
      if (param_4 != (undefined4 *)0x0) {
        iVar2 = (**(code **)(*local_24 + 0x14))(local_24,7,&local_18,0x10,"ClassID");
        if (iVar2 != 0) goto LAB_680adffc;
        *param_4 = local_18;
        param_4[1] = local_14;
        param_4[2] = local_10;
        param_4[3] = local_c;
      }
      uVar4 = Ordinal_1038();
      piVar3 = (int *)Ordinal_2068(uVar4);
      if (piVar3 != (int *)0x0) {
        iVar2 = (**(code **)(*piVar3 + 0x24))(piVar3,local_24,&DAT_68175c58,local_20);
        (**(code **)(*piVar3 + 8))(piVar3);
        if (iVar2 != 0) goto LAB_680adffc;
      }
      iVar5 = media_dispatchXtraEvent(&local_1c,*(undefined4 *)(iVar5 + 0x20),*(undefined4 *)(iVar5 + 0x28),
                           param_5);
      if (iVar5 == 0) {
        (**(code **)(*(int *)*local_20 + 0x38))((int *)*local_20,local_1c);
        (**(code **)(*local_1c + 8))(local_1c);
      }
    }
  }
LAB_680adffc:
  return 0;
}



// ============================================================
// Function: media_createXtraPluginEx (FUN_680ae010)
// Address: 680ae010
// Size: 268 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 * param_6, undefined4 * param_7, undefined4 param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_createXtraPluginEx(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 *param_6,undefined4 *param_7,undefined4 param_8)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_2;
  local_10 = param_4;
  local_14 = param_3;
  local_c = param_5;
  local_1c = (int *)0x0;
  iVar4 = *(int *)(*(int *)(param_1 + 8) + 4);
  if ((iVar4 != 0) && (*(int *)(iVar4 + 0x20) != 0)) {
    piVar1 = (int *)lingo_getGlobalRef(*(int *)(*(int *)(iVar4 + 0x20) + 8));
    if (piVar1 != (int *)0x0) {
      iVar2 = media_findSpriteEntry(piVar1,&local_18);
      if (0 < iVar2) {
        iVar2 = mediaPlayback_getSlotValue(piVar1,iVar2,param_7);
        if (iVar2 == 0) {
          uVar3 = Ordinal_1038(&local_18,&DAT_68175c58,param_6);
          iVar2 = Ordinal_2063(uVar3);
          if (iVar2 == 0) {
            iVar4 = media_dispatchXtraEvent(&local_1c,*(undefined4 *)(iVar4 + 0x20),
                                 *(undefined4 *)(iVar4 + 0x28),param_8);
            if (iVar4 == 0) {
              (**(code **)(*(int *)*param_6 + 0x38))((int *)*param_6,local_1c);
              (**(code **)(*local_1c + 8))(local_1c);
            }
          }
        }
        return 0;
      }
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: media_initXtraDispatch (FUN_680ae120)
// Address: 680ae120
// Size: 1095 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_initXtraDispatch(int param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(0x6c,1);
  *(int **)(param_1 + 0x364) = piVar2;
  if (piVar2 != (int *)0x0) {
    *(undefined4 *)(*piVar2 + 0x68) = 0xffffffff;
    piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
    *(int **)**(undefined4 **)(param_1 + 0x364) = piVar2;
    if (piVar2 != (int *)0x0) {
      *(undefined4 *)(**(int **)**(undefined4 **)(param_1 + 0x364) + 0x20) = 0;
      piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
      *(int **)(**(int **)(param_1 + 0x364) + 4) = piVar2;
      if (piVar2 != (int *)0x0) {
        *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 4) + 0x20) = 0;
        piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
        *(int **)(**(int **)(param_1 + 0x364) + 8) = piVar2;
        if (piVar2 != (int *)0x0) {
          *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 8) + 0x20) = 0;
          piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
          *(int **)(**(int **)(param_1 + 0x364) + 0xc) = piVar2;
          if (piVar2 != (int *)0x0) {
            *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 0xc) + 0x20) = 0;
            piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
            *(int **)(**(int **)(param_1 + 0x364) + 0x10) = piVar2;
            if (piVar2 != (int *)0x0) {
              *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 0x10) + 0x20) = 0;
              piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
              *(int **)(**(int **)(param_1 + 0x364) + 0x14) = piVar2;
              if (piVar2 != (int *)0x0) {
                *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 0x14) + 0x20) = 0;
                piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                *(int **)(**(int **)(param_1 + 0x364) + 0x18) = piVar2;
                if (piVar2 != (int *)0x0) {
                  *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 0x18) + 0x20) = 0;
                  piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                  *(int **)(**(int **)(param_1 + 0x364) + 0x1c) = piVar2;
                  if (piVar2 != (int *)0x0) {
                    *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 0x1c) + 0x20) = 0;
                    piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                    *(int **)(**(int **)(param_1 + 0x364) + 0x20) = piVar2;
                    if (piVar2 != (int *)0x0) {
                      *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 0x20) + 0x20) = 0;
                      piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                      *(int **)(**(int **)(param_1 + 0x364) + 0x24) = piVar2;
                      if (piVar2 != (int *)0x0) {
                        *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 0x24) + 0x20) = 0;
                        piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                        *(int **)(**(int **)(param_1 + 0x364) + 0x28) = piVar2;
                        if (piVar2 != (int *)0x0) {
                          *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 0x28) + 0x20) = 0
                          ;
                          piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                          *(int **)(**(int **)(param_1 + 0x364) + 0x2c) = piVar2;
                          if (piVar2 != (int *)0x0) {
                            *(undefined4 *)(**(int **)(**(int **)(param_1 + 0x364) + 0x2c) + 0x20) =
                                 0;
                            piVar2 = stage_allocDispatchEntry(0x28,0x20,8,5);
                            *(int **)(**(int **)(param_1 + 0x364) + 0x50) = piVar2;
                            if (piVar2 != (int *)0x0) {
                              piVar2 = stage_allocDispatchEntry(0x28,0x20,8,5);
                              *(int **)(**(int **)(param_1 + 0x364) + 0x54) = piVar2;
                              if (piVar2 != (int *)0x0) {
                                piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                                *(int **)(**(int **)(param_1 + 0x364) + 0x30) = piVar2;
                                if (piVar2 != (int *)0x0) {
                                  *(undefined4 *)
                                   (**(int **)(**(int **)(param_1 + 0x364) + 0x30) + 0x20) = 0;
                                  piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                                  *(int **)(**(int **)(param_1 + 0x364) + 0x34) = piVar2;
                                  if (piVar2 != (int *)0x0) {
                                    *(undefined4 *)
                                     (**(int **)(**(int **)(param_1 + 0x364) + 0x34) + 0x20) = 0;
                                    piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                                    *(int **)(**(int **)(param_1 + 0x364) + 0x38) = piVar2;
                                    if (piVar2 != (int *)0x0) {
                                      piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                                      *(int **)(**(int **)(param_1 + 0x364) + 0x3c) = piVar2;
                                      if (piVar2 != (int *)0x0) {
                                        piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                                        *(int **)(**(int **)(param_1 + 0x364) + 0x40) = piVar2;
                                        if (piVar2 != (int *)0x0) {
                                          piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                                          *(int **)(**(int **)(param_1 + 0x364) + 0x44) = piVar2;
                                          if (piVar2 != (int *)0x0) {
                                            piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                                            *(int **)(**(int **)(param_1 + 0x364) + 0x48) = piVar2;
                                            if (piVar2 != (int *)0x0) {
                                              piVar2 = stage_allocDispatchEntry(0x44,0x24,0x20,5);
                                              *(int **)(**(int **)(param_1 + 0x364) + 0x4c) = piVar2
                                              ;
                                              if (piVar2 != (int *)0x0) {
                                                Ordinal_2063(param_2,&DAT_68176368,&DAT_68175fc8,
                                                             **(int **)(param_1 + 0x364) + 0x58);
                                                puVar1 = *(undefined4 **)
                                                          (**(int **)(param_1 + 0x364) + 0x58);
                                                (**(code **)*puVar1)
                                                          (puVar1,&DAT_68176378,
                                                           **(int **)(param_1 + 0x364) + 0x5c);
                                                Ordinal_2063(param_2,&DAT_68176418,&DAT_68175f68,
                                                             **(int **)(param_1 + 0x364) + 0x60);
                                                puVar1 = *(undefined4 **)
                                                          (**(int **)(param_1 + 0x364) + 0x60);
                                                (**(code **)*puVar1)
                                                          (puVar1,&DAT_68176428,
                                                           **(int **)(param_1 + 0x364) + 100);
                                                return 0;
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0x80040002;
}



// ============================================================
// Function: media_destroyXtraDispatch (FUN_680ae570)
// Address: 680ae570
// Size: 253 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_destroyXtraDispatch(int param_1)
{
  int *piVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int local_8;
  
  if (*(undefined4 **)(param_1 + 0x364) != (undefined4 *)0x0) {
    puVar2 = (undefined4 *)**(undefined4 **)(param_1 + 0x364);
    local_8 = 0x14;
    do {
      iVar4 = *(int *)(*(int *)*puVar2 + 0x10);
      piVar3 = (int *)(*(int *)*puVar2 + 0x24);
      if (0 < iVar4) {
        do {
          piVar1 = (int *)*piVar3;
          if (piVar1 != (int *)0x0) {
            (**(code **)(*piVar1 + 8))(piVar1);
          }
          piVar3 = piVar3 + 8;
          iVar4 = iVar4 + -1;
        } while (iVar4 != 0);
      }
      cast_freeHandle(*puVar2);
      puVar2 = puVar2 + 1;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
    cast_freeHandle(*(undefined4 *)(**(int **)(param_1 + 0x364) + 0x54));
    cast_freeHandle(*(undefined4 *)(**(int **)(param_1 + 0x364) + 0x50));
    if (*(int *)(**(int **)(param_1 + 0x364) + 0x58) != 0) {
      piVar3 = *(int **)(**(int **)(param_1 + 0x364) + 0x58);
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    if (*(int *)(**(int **)(param_1 + 0x364) + 0x5c) != 0) {
      piVar3 = *(int **)(**(int **)(param_1 + 0x364) + 0x5c);
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    if (*(int *)(**(int **)(param_1 + 0x364) + 0x60) != 0) {
      piVar3 = *(int **)(**(int **)(param_1 + 0x364) + 0x60);
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    if (*(int *)(**(int **)(param_1 + 0x364) + 100) != 0) {
      piVar3 = *(int **)(**(int **)(param_1 + 0x364) + 100);
      (**(code **)(*piVar3 + 8))(piVar3);
    }
    cast_freeHandle(*(undefined4 *)(param_1 + 0x364));
    *(undefined4 *)(param_1 + 0x364) = 0;
  }
  return 0;
}



// ============================================================
// Function: media_getXtraSlotIndex (FUN_680ae670)
// Address: 680ae670
// Size: 102 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getXtraSlotIndex(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    return 1;
  case 1:
    return 2;
  case 2:
    return 3;
  case 3:
    return 4;
  case 4:
    return 5;
  case 5:
    return 6;
  case 6:
    return 7;
  case 7:
    return 8;
  case 8:
    return 9;
  case 9:
    return 10;
  case 10:
    return 0xb;
  case 0xb:
    return 0xc;
  case 0xc:
    return 0xd;
  case 0xd:
    return 0xe;
  default:
    return 0xffff;
  }
}



// ============================================================
// Function: media_initXtraCallback (FUN_680ae710)
// Address: 680ae710
// Size: 273 bytes
// Params: int param_1, undefined2 param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall media_initXtraCallback(int param_1,undefined2 param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  switch(param_2) {
  case 1:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x1c);
  case 2:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x18);
  case 3:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x14);
  case 4:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x10);
  case 5:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0xc);
  case 6:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 8);
  case 7:
    return *(undefined4 *)**(undefined4 **)(param_1 + 0x364);
  case 8:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 4);
  case 9:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x20);
  case 10:
  case 0x10:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x24);
  case 0xb:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x28);
  case 0xc:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x2c);
  case 0xd:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x30);
  case 0xe:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x34);
  case 0xf:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x24);
  case 0x11:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x38);
  case 0x12:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x3c);
  case 0x13:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x40);
  case 0x14:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x44);
  case 0x15:
    return *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x48);
  case 0x16:
    uVar1 = *(undefined4 *)(**(int **)(param_1 + 0x364) + 0x4c);
  }
  return uVar1;
}



// ============================================================
// Function: media_getNextXtraSlot (FUN_680ae880)
// Address: 680ae880
// Size: 20 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getNextXtraSlot(void)

{
  int in_EAX;
  undefined4 uVar1;
  int extraout_ECX;
  
  if (in_EAX == 0x14) {
    return 0;
  }
  uVar1 = media_getXtraSlotIndex();
  uVar1 = media_initXtraCallback(extraout_ECX,(short)uVar1);
  return uVar1;
}



// ============================================================
// Function: media_resolveXtraEventType (FUN_680ae8a0)
// Address: 680ae8a0
// Size: 400 bytes
// Return: char
// Calling convention: __stdcall
// ============================================================

char media_resolveXtraEventType(void)

{
  int iVar1;
  
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x01';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x02';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x03';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x04';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x05';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x06';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\a';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\b';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\t';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\v';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\f';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\r';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x0e';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x11';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x12';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x13';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x14';
  }
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    return '\x15';
  }
  iVar1 = Ordinal_2066();
  return (-(iVar1 != 0) & 0xcU) + 10;
}



// ============================================================
// Function: media_getXtraEventName (FUN_680aea30)
// Address: 680aea30
// Size: 149 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

undefined * media_getXtraEventName(void)

{
  undefined2 in_AX;
  
  switch(in_AX) {
  case 1:
    return &DAT_68176228;
  case 2:
    return &DAT_68175e58;
  case 3:
    return &DAT_68175e68;
  case 4:
    return &DAT_68175e78;
  case 5:
    return &DAT_68175e88;
  case 6:
    return &DAT_68175ea8;
  case 7:
    return &DAT_68175eb8;
  case 8:
    return &DAT_68175ec8;
  case 9:
    return &DAT_68175e98;
  default:
    return (undefined *)0x0;
  case 0xb:
    return &DAT_68175ed8;
  case 0xc:
    return &DAT_68175ee8;
  case 0xd:
    return &DAT_681761f8;
  case 0xe:
    return &DAT_68176208;
  case 0xf:
    return &DAT_68175db8;
  case 0x10:
    return &DAT_68175ef8;
  case 0x11:
    return &DAT_68175f08;
  case 0x12:
    return &DAT_68175f18;
  case 0x13:
    return &DAT_68175f28;
  case 0x14:
    return &DAT_68175f38;
  case 0x15:
    return &DAT_68175f48;
  case 0x16:
    return &DAT_68175f58;
  }
}



// ============================================================
// Function: media_registerXtraEvent (FUN_680aeb20)
// Address: 680aeb20
// Size: 414 bytes
// Params: void * this, int * param_1, int * param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall media_registerXtraEvent(void *this,int *param_1,int *param_2,undefined4 param_3)

{
  char cVar1;
  uint *in_EAX;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  int *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int *local_10;
  int local_c;
  undefined4 local_8;
  
  local_30 = (int *)0x0;
  local_2c = 0;
  local_28 = 0;
  local_24 = (int *)0x0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_c = *(int *)(*(int *)(*(int *)this + 0x14) + 0x14);
  local_8 = 0;
  if (*(int *)((int)this + 0x364) == 0) {
    return 0x80040014;
  }
  cVar1 = media_resolveXtraEventType();
  local_10 = (int *)media_initXtraCallback((int)this,(short)CONCAT31(extraout_var,cVar1));
  iVar3 = local_c;
  if (local_10 == (int *)0x0) {
    return 0x80040bc8;
  }
  local_28 = param_3;
  local_30 = param_2;
  local_2c = 0;
  switch(CONCAT31(extraout_var,cVar1) & 0xffff) {
  case 2:
    if (in_EAX != (uint *)0x0) {
      (**(code **)*in_EAX)();
      goto LAB_680aebdc;
    }
    goto LAB_680aec13;
  case 7:
    if (in_EAX == (uint *)0x0) {
      local_24 = (int *)0xffffffff;
      break;
    }
    (**(code **)*in_EAX)();
LAB_680aebdc:
    if (param_1 == (int *)0x0) {
      return 0x80040001;
    }
    (**(code **)(*param_1 + 0xc))(param_1,&local_24);
    (**(code **)(*param_1 + 8))(param_1);
    break;
  case 8:
    if (in_EAX != (uint *)0x0) {
      local_24 = (int *)*in_EAX;
      if (local_24 != (int *)0x0) {
        local_20 = Ordinal_1541();
      }
      break;
    }
LAB_680aec13:
    local_24 = (int *)0x0;
    break;
  case 9:
    if (in_EAX == (uint *)0x0) {
      local_24 = (int *)((uint)local_24 & 0xffff0000);
    }
    else {
      iVar2 = cast_setXtraPropertyEx(local_c,in_EAX,(undefined2 *)&local_24);
      if (iVar2 != 0) {
        iVar3 = cast_getFormatProperty(iVar3,in_EAX,(undefined2 *)&local_24);
        if (iVar3 != 0) {
          return 0x80040001;
        }
        local_24 = (int *)CONCAT22((*(unsigned short *)((char *)&local_24 + 2)),-(short)local_24);
      }
    }
    break;
  case 10:
    local_24 = param_1;
  }
  iVar3 = stage_lookupSymbolId(local_10,&local_30);
  if (-1 < iVar3) {
    (**(code **)(*param_2 + 4))(param_2);
    return local_8;
  }
  return 0x80040014;
}



// ============================================================
// Function: media_adjustXtraIndices (FUN_680aecf0)
// Address: 680aecf0
// Size: 33 bytes
// Params: undefined4 param_1, uint param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_adjustXtraIndices(undefined4 param_1,uint param_2)
{
  uint *puVar1;
  int *in_EAX;
  
  for (puVar1 = *(uint **)(*in_EAX + 0x20); puVar1 != (uint *)0x0; puVar1 = (uint *)puVar1[1]) {
    if (param_2 <= *puVar1) {
      *puVar1 = *puVar1 - 1;
    }
  }
  return 0;
}



// ============================================================
// Function: media_unregisterXtraEvent (FUN_680aed20)
// Address: 680aed20
// Size: 501 bytes
// Params: int * param_1, int * param_2, int * param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_unregisterXtraEvent(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  uint *puVar1;
  char cVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_ECX;
  int *piVar6;
  int *piVar7;
  uint uVar8;
  undefined *puVar9;
  int *local_28 [3];
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  undefined4 local_8;
  
  local_14 = *(int *)(*(int *)(*param_1 + 0x14) + 0x14);
  local_8 = 0;
  local_c = 0x14;
  if (param_1[0xd9] == 0) {
    return 0x80040014;
  }
  if (param_2 == (int *)0x0) {
    piVar3 = (int *)media_getNextXtraSlot();
    local_c = 1;
    uVar8 = local_10;
  }
  else {
    cVar2 = media_resolveXtraEventType();
    uVar8 = CONCAT31(extraout_var,cVar2) & 0xffff;
    local_10 = uVar8;
    piVar3 = (int *)media_initXtraCallback((int)param_1,(short)CONCAT31(extraout_var,cVar2));
    if (piVar3 == (int *)0x0) {
      return 0x80040bc8;
    }
  }
  iVar5 = local_14;
  puVar1 = param_4;
  if (param_4 == (uint *)0x0) goto switchD_680aedbd_caseD_3;
  switch(uVar8 & 0xffff) {
  case 2:
    puVar9 = &DAT_68176428;
    goto LAB_680aedcd;
  case 7:
    puVar9 = &DAT_68176378;
LAB_680aedcd:
    (**(code **)*param_4)(param_4,puVar9,&param_2);
    if (param_2 == (int *)0x0) {
      return 0x80040001;
    }
    (**(code **)(*param_2 + 0xc))(param_2,local_28);
    (**(code **)(*param_2 + 8))(param_2);
    break;
  case 8:
    piVar6 = (int *)*param_4;
    goto joined_r0x680aee52;
  case 9:
    iVar4 = cast_setXtraPropertyEx(local_14,param_4,(undefined2 *)local_28);
    if (iVar4 != 0) {
      iVar5 = cast_getFormatProperty(iVar5,puVar1,(undefined2 *)local_28);
      if (iVar5 != 0) {
        return 0x80040001;
      }
      /* FIXUP(C2224: left of '._2_2_' must have struct/union type): local_28[0] = (int *)CONCAT22(local_28[0]._2_2_,-(short)local_28[0]); */
    }
    break;
  case 10:
    local_28[0] = param_2;
  }
switchD_680aedbd_caseD_3:
  piVar6 = local_28[0];
joined_r0x680aee52:
  do {
    if (0x14 < local_c) {
      return local_8;
    }
    param_2 = *(int **)(*piVar3 + 0x10);
    uVar8 = 0;
    piVar7 = (int *)(*piVar3 + 0x24);
    local_28[0] = piVar6;
    if (0 < (int)param_2) {
      do {
        if ((int *)*piVar7 != param_3) goto LAB_680aeeea;
        if (param_4 == (uint *)0x0) goto switchD_680aee8d_caseD_3;
        switch(local_10 & 0xffff) {
        case 2:
          if (((piVar6 == (int *)piVar7[3]) && (local_1c == piVar7[6])) && (local_18 == piVar7[7]))
          break;
          goto LAB_680aeeea;
        case 7:
        case 8:
          if (piVar6 != (int *)piVar7[3]) goto LAB_680aeeea;
          break;
        case 9:
          if ((short)local_28[0] != (short)piVar7[3]) goto LAB_680aeeea;
          break;
        case 10:
          iVar5 = Ordinal_2066(piVar6,piVar7[3]);
          piVar6 = local_28[0];
          if (iVar5 == 0) goto LAB_680aeeea;
        }
switchD_680aee8d_caseD_3:
        stage_emitPushRef(piVar3,uVar8);
        (**(code **)(*param_3 + 8))(param_3);
        media_adjustXtraIndices(extraout_ECX,uVar8);
        piVar6 = local_28[0];
LAB_680aeeea:
        uVar8 = uVar8 + 1;
        piVar7 = piVar7 + 8;
      } while ((int)uVar8 < (int)param_2);
    }
    iVar5 = local_c;
    piVar3 = (int *)media_getNextXtraSlot();
    local_c = iVar5 + 1;
    piVar6 = local_28[0];
  } while( true );
}



// ============================================================
// Function: media_dispatchXtraNotify (FUN_680aef70)
// Address: 680aef70
// Size: 852 bytes
// Params: undefined4 param_1, ushort param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_dispatchXtraNotify(undefined4 param_1,ushort param_2,int param_3,uint *param_4)
{
  undefined4 *puVar1;
  short sVar2;
  int *piVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 local_88;
  int local_84;
  undefined4 local_80;
  int local_7c;
  int local_78;
  uint local_74 [2];
  uint local_6c;
  uint local_68;
  uint local_64;
  undefined4 local_60;
  int *local_5c;
  undefined4 local_58;
  int local_54;
  uint *local_50;
  uint local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 *local_40;
  undefined4 local_3c;
  uint local_38 [2];
  uint local_30;
  undefined4 local_2c;
  char local_28 [32];
  uint local_8;
  
  iVar4 = *(int *)(param_3 + 8);
  local_4c = (uint)param_2;
  local_50 = param_4;
  local_48 = param_3;
  local_54 = 0;
  local_58 = param_1;
  if ((*(int *)(iVar4 + 0x364) != 0) &&
     (local_5c = (int *)media_initXtraCallback(iVar4,param_2), local_5c != (int *)0x0)) {
    puVar5 = (uint *)0x0;
    switch(local_4c & 0xffff) {
    case 2:
      if (*(undefined4 **)(local_48 + 0x20) == (undefined4 *)0x0) {
        local_88 = 0;
      }
      else {
        local_88 = **(undefined4 **)(local_48 + 0x20);
      }
      local_80 = 0;
      local_7c = (int)(short)*param_4;
      local_78 = (int)*(short *)((int)param_4 + 2);
      piVar3 = *(int **)(**(int **)(iVar4 + 0x364) + 100);
      local_84 = iVar4;
      (**(code **)(*piVar3 + 0x10))(piVar3,&local_88);
      puVar5 = *(uint **)(**(int **)(iVar4 + 0x364) + 0x60);
      break;
    case 6:
      puVar5 = local_74;
      break;
    case 7:
      piVar3 = *(int **)(**(int **)(iVar4 + 0x364) + 0x5c);
      (**(code **)(*piVar3 + 0x10))(piVar3,&local_50);
      puVar5 = *(uint **)(**(int **)(iVar4 + 0x364) + 0x58);
      break;
    case 8:
      puVar5 = &local_68;
      break;
    case 9:
      sVar2 = (short)*param_4;
      if (sVar2 < 0) {
        cast_resolveMediaProperty(*(int *)(*(int *)(*(int *)(local_48 + 0x20) + 8) + 0xc),-sVar2,(int *)local_38)
        ;
      }
      else {
        cast_resolveScriptProperty(*(int *)(*(int *)(*(int *)(local_48 + 0x20) + 8) + 0xc),sVar2,(int *)local_38);
      }
      local_30 = param_4[1];
      strncpy(local_28,(char *)param_4[2],0x20);
      local_2c = 0;
      local_6c = (uint)(ushort)*param_4;
      puVar5 = local_38;
      break;
    case 10:
    case 0xf:
    case 0x10:
      local_4c = 10;
    case 0xd:
    case 0xe:
    case 0x11:
      puVar5 = param_4;
      break;
    case 0xb:
    case 0xc:
      piVar3 = *(int **)(**(int **)(iVar4 + 0x364) + 0x5c);
      (**(code **)(*piVar3 + 0x10))(piVar3,param_4);
      puVar5 = *(uint **)(**(int **)(iVar4 + 0x364) + 0x58);
    }
    local_60 = *(undefined4 *)(*local_5c + 0x20);
    *(uint **)(*local_5c + 0x20) = &local_64;
    local_64 = 0;
    iVar4 = *local_5c;
    if (*(int *)(iVar4 + 0x10) != 0) {
      do {
        puVar1 = (undefined4 *)(local_64 * 0x20 + 0x24 + iVar4);
        if (*(int *)(local_64 * 0x20 + 0x24 + iVar4) != 0) {
          uVar6 = local_4c & 0xffff;
          switch(uVar6) {
          case 2:
            if (puVar1[3] != 0) {
              if (*(int **)(local_48 + 0x20) == (int *)0x0) {
                iVar4 = 0;
              }
              else {
                iVar4 = **(int **)(local_48 + 0x20);
              }
              if (((puVar1[3] != iVar4) || (puVar1[6] != (int)(short)*local_50)) ||
                 (puVar1[7] != (int)*(short *)((int)local_50 + 2))) goto LAB_680af259;
            }
            break;
          case 6:
            cast_getScoreXtraData(*(int *)(*(int *)(*(int *)(local_48 + 0x20) + 8) + 0xc),(short *)local_50);
            break;
          case 7:
            if (((int)puVar1[3] < 1) || ((uint *)puVar1[3] == local_50)) break;
            goto LAB_680af259;
          case 8:
            if (local_54 == 0) {
              local_54 = Ordinal_1541();
            }
            iVar4 = puVar1[4];
            if ((uint)(local_54 - iVar4) < (uint)puVar1[3]) goto LAB_680af259;
            puVar1[4] = local_54;
            local_68 = local_54 - iVar4;
            break;
          case 9:
            if ((*(short *)(puVar1 + 3) != 0) && (*(short *)(puVar1 + 3) != (short)local_6c))
            goto LAB_680af259;
            break;
          case 10:
            iVar4 = Ordinal_2066(local_58,puVar1[3]);
            if (iVar4 == 0) goto LAB_680af259;
          }
          Ordinal_2330();
          if (*(undefined4 **)(local_48 + 0x20) == (undefined4 *)0x0) {
            local_44 = 0;
          }
          else {
            local_44 = **(undefined4 **)(local_48 + 0x20);
          }
          local_3c = 0;
          local_40 = DAT_68196374;
          DAT_68196374 = &local_44;
          if (puVar1[1] == 0) {
            (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,local_58,puVar5,puVar1[2]);
          }
          else {
            (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,uVar6,puVar5);
          }
          DAT_68196374 = local_40;
          Ordinal_2331();
LAB_680af259:
          if (uVar6 == 6) {
            props_releaseAndClear(*(undefined4 *)(*(int *)(*(int *)(local_48 + 0x20) + 8) + 0xc),
                         (int *)local_74);
          }
        }
        local_64 = local_64 + 1;
        iVar4 = *local_5c;
      } while (local_64 < *(uint *)(iVar4 + 0x10));
    }
    *(undefined4 *)(*local_5c + 0x20) = *(undefined4 *)(*(int *)(*local_5c + 0x20) + 4);
    if ((short)local_4c == 9) {
      props_releaseAndClear(*(undefined4 *)(*(int *)(*(int *)(local_48 + 0x20) + 8) + 0xc),(int *)local_38);
    }
  }
  return 0;
}



// ============================================================
// Function: media_notifyXtraProperty (FUN_680af330)
// Address: 680af330
// Size: 292 bytes
// Params: ushort param_1, undefined4 param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_notifyXtraProperty(ushort param_1,undefined4 param_2,uint *param_3)
{
  int iVar1;
  bool bVar2;
  int in_EAX;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint local_10;
  undefined4 local_c;
  int local_8;
  
  bVar2 = false;
  if (in_EAX != 0) {
    local_8 = *(int *)(in_EAX + 8);
    if ((*(int **)(local_8 + 0x364) != (int *)0x0) &&
       (((uint)(*(int *)(**(int **)(local_8 + 0x364) + 0x68) == 0) &
        1 << ((char)param_1 - 1U & 0x1f)) == 0)) {
      Ordinal_1130(&local_10,8);
      if (param_1 == 2) {
        local_10 = *param_3;
        if (*(undefined4 **)(in_EAX + 0x20) == (undefined4 *)0x0) {
          local_c = 0;
        }
        else {
          local_c = **(undefined4 **)(in_EAX + 0x20);
        }
        piVar6 = *(int **)(**(int **)(local_8 + 0x364) + 0x50);
        bVar2 = true;
      }
      else {
        if (param_1 != 3) {
          media_dispatchXtraNotify(param_2,param_1,in_EAX,param_3);
          return 0;
        }
        piVar6 = *(int **)(**(int **)(local_8 + 0x364) + 0x54);
      }
      iVar1 = *(int *)(*piVar6 + 0x10);
      if (bVar2) {
        piVar5 = (int *)(*piVar6 + 0x20);
        if (0 < iVar1) {
          iVar7 = (int)&local_10 - (int)piVar5;
          iVar8 = 0;
          do {
            uVar4 = 8;
            piVar3 = piVar5;
            while( true ) {
              if (uVar4 < 4) {
                return 0;
              }
              if (*(int *)(iVar7 + (int)piVar3) != *piVar3) break;
              uVar4 = uVar4 - 4;
              piVar3 = piVar3 + 1;
            }
            iVar8 = iVar8 + 1;
            piVar5 = piVar5 + 2;
            iVar7 = iVar7 + -8;
          } while (iVar8 < iVar1);
          stage_lookupSymbolId(piVar6,&local_10);
          return 0;
        }
      }
      else if (iVar1 != 0) {
        return 0;
      }
      stage_lookupSymbolId(piVar6,&local_10);
    }
  }
  return 0;
}



// ============================================================
// Function: media_fireAllXtraEvents (FUN_680af460)
// Address: 680af460
// Size: 254 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_fireAllXtraEvents(int param_1)
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  int local_18;
  uint local_14;
  uint *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar5 = *(int *)(param_1 + 8);
  piVar1 = *(int **)(iVar5 + 0x364);
  if (piVar1 != (int *)0x0) {
    piVar1 = *(int **)(*piVar1 + 0x50);
    iVar2 = *piVar1;
    local_18 = *(int *)(iVar2 + 0x10);
    puVar4 = (uint *)(iVar2 + 0x20);
    if (0 < local_18) {
      do {
        uVar3 = puVar4[1];
        if (uVar3 != 0) {
          iVar2 = *(int *)(uVar3 + 0x20);
          if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
            Ordinal_2330();
            local_c = 0;
            local_10 = DAT_68196374;
            DAT_68196374 = &local_14;
            local_14 = uVar3;
          }
          media_dispatchXtraNotify(&DAT_68175e58,2,param_1,puVar4);
          if (iVar2 != 0) {
            DAT_68196374 = local_10;
            Ordinal_2331();
          }
        }
        puVar4 = puVar4 + 2;
        local_18 = local_18 + -1;
      } while (local_18 != 0);
    }
    stage_resetBytecodeCount(piVar1);
    piVar1 = *(int **)(**(int **)(iVar5 + 0x364) + 0x54);
    iVar5 = *(int *)(*piVar1 + 0x10);
    if (0 < iVar5) {
      do {
        media_dispatchXtraNotify(&DAT_68175e68,3,param_1,(uint *)0x0);
        iVar5 = iVar5 + -1;
      } while (iVar5 != 0);
    }
    stage_resetBytecodeCount(piVar1);
  }
  return 0;
}



// ============================================================
// Function: media_clearXtraSlot (FUN_680af560)
// Address: 680af560
// Size: 56 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_clearXtraSlot(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  if (*(int **)(param_1 + 0x364) != (int *)0x0) {
    iVar1 = **(int **)(**(int **)(param_1 + 0x364) + 0x50);
    iVar3 = *(int *)(iVar1 + 0x10);
    if (0 < iVar3) {
      piVar2 = (int *)(iVar1 + 0x24);
      do {
        if (*piVar2 == param_2) {
          *piVar2 = 0;
        }
        piVar2 = piVar2 + 2;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return 0;
}



// ============================================================
// Function: media_queryXtraMethod (FUN_680af5a0)
// Address: 680af5a0
// Size: 118 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_queryXtraMethod(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  int *local_8;
  
  local_8 = (int *)0x0;
  uVar1 = Ordinal_1038(&DAT_68176438,&DAT_68175c68,param_4);
  iVar2 = Ordinal_2063(uVar1);
  if (iVar2 == 0) {
    iVar2 = (*(code *)**(undefined4 **)*param_4)((undefined4 *)*param_4,&DAT_68176448,&local_8);
    if (iVar2 == 0) {
      iVar2 = (**(code **)(*local_8 + 0xc))(local_8,param_1,param_2,param_3);
    }
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return iVar2;
}



// ============================================================
// Function: media_initXtraDispatchWrapper (FUN_680af620)
// Address: 680af620
// Size: 20 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_initXtraDispatchWrapper(int param_1,undefined4 param_2)
{
  media_initXtraDispatch(param_1,param_2);
  return 0;
}



// ============================================================
// Function: media_destroyXtraDispatchWrapper (FUN_680af640)
// Address: 680af640
// Size: 16 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_destroyXtraDispatchWrapper(int param_1)
{
  media_destroyXtraDispatch(param_1);
  return 0;
}



// ============================================================
// Function: media_queryXtraService (FUN_680af650)
// Address: 680af650
// Size: 78 bytes
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 media_queryXtraService(void)

{
  undefined1 uVar1;
  undefined4 uVar2;
  int iVar3;
  int *local_8;
  
  uVar1 = 0;
  local_8 = (int *)0x0;
  uVar2 = Ordinal_1038(&DAT_68176598,&DAT_68176588,&local_8);
  iVar3 = Ordinal_2063(uVar2);
  if (iVar3 == 0) {
    uVar1 = (**(code **)(*local_8 + 0xc))(local_8);
  }
  if (local_8 != (int *)0x0) {
    (**(code **)(*local_8 + 8))(local_8);
  }
  return uVar1;
}



// ============================================================
// Function: rendering_onPause (FUN_680af6a0)
// Address: 680af6a0
// Size: 209 bytes
// Params: int param_1, ushort param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_onPause(int param_1,ushort param_2)
{
  int local_c;
  int iVar1;
  int iVar2;
  int *piVar3;
  double dVar4;
  int iVar5;
  int iVar6;
  /* FIXUP(C2040: 'local_c': 'int): int local_c [2]; */
  
  iVar1 = *(int *)(*(int *)(**(int **)(param_1 + 0x18) + 0x14) + 0x14);
  dVar4 = (double)((int)(uint)param_2 >> 8) + (double)(param_2 & 0xff) * 0.00390625;
  if (dVar4 != 0.0) {
    dVar4 = 1.0 / dVar4;
  }
  props_storeFloatDirect(iVar1,dVar4,local_c);
  iVar5 = *(int *)(param_1 + 0x124);
  if (*(int *)(param_1 + 0x120) <= iVar5) {
    iVar6 = iVar5 * 400;
    do {
      iVar2 = *(int *)(*(int *)(param_1 + 0x34) + 0x60 + iVar6);
      if (((iVar2 != 0) && (iVar2 == 10)) &&
         (piVar3 = *(int **)(*(int *)(param_1 + 0x34) + 0x148 + iVar6), piVar3 != (int *)0x0)) {
        (**(code **)(*piVar3 + 0x10))(piVar3,899,local_c);
      }
      iVar5 = iVar5 + -1;
      iVar6 = iVar6 + -400;
    } while (*(int *)(param_1 + 0x120) <= iVar5);
  }
  props_releaseAndClear(iVar1,local_c);
  return 0;
}



// ============================================================
// Function: media_registerXtraDefault (FUN_680af780)
// Address: 680af780
// Size: 66 bytes
// Params: void * param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_registerXtraDefault(void *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  if ((param_1 != (void *)0x0) && (*(int *)((int)param_1 + 0x364) != 0)) {
    if (param_2 == 1) {
      uVar1 = media_registerXtraEvent(param_1,(int *)&DAT_68176228,param_3,0);
      return uVar1;
    }
    return 0x80040bc8;
  }
  return 0x80040014;
}



// ============================================================
// Function: media_registerXtraEventEx (FUN_680af7d0)
// Address: 680af7d0
// Size: 52 bytes
// Params: void * param_1, int * param_2, int * param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
media_registerXtraEventEx(void *param_1,int *param_2,int *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if ((param_1 != (void *)0x0) && (*(int *)((int)param_1 + 0x364) != 0)) {
    uVar1 = media_registerXtraEvent(param_1,param_2,param_3,param_5);
    return uVar1;
  }
  return 0x80040014;
}



// ============================================================
// Function: media_unregisterXtraDefault (FUN_680af810)
// Address: 680af810
// Size: 64 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_unregisterXtraDefault(int *param_1,int param_2,int *param_3)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (param_1[0xd9] != 0)) {
    if (param_2 == 1) {
      uVar1 = media_unregisterXtraEvent(param_1,(int *)&DAT_68176228,param_3,(uint *)0x0);
      return uVar1;
    }
    return 0x80040bc8;
  }
  return 0x80040014;
}



// ============================================================
// Function: media_unregisterXtraEventEx (FUN_680af850)
// Address: 680af850
// Size: 50 bytes
// Params: int * param_1, int * param_2, int * param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_unregisterXtraEventEx(int *param_1,int *param_2,int *param_3,uint *param_4)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (param_1[0xd9] != 0)) {
    uVar1 = media_unregisterXtraEvent(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  return 0x80040014;
}



// ============================================================
// Function: media_queryXtraProperty (FUN_680af890)
// Address: 680af890
// Size: 31 bytes
// Params: undefined4 param_1, undefined4 param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_queryXtraProperty(undefined4 param_1,undefined4 param_2,uint *param_3)
{
  undefined *puVar1;
  ushort extraout_CX;
  
  puVar1 = media_getXtraEventName();
  media_notifyXtraProperty(extraout_CX,puVar1,param_3);
  return 0;
}



// ============================================================
// Function: media_queryXtraPropertyEx (FUN_680af8b0)
// Address: 680af8b0
// Size: 34 bytes
// Params: undefined4 param_1, undefined4 param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_queryXtraPropertyEx(undefined4 param_1,undefined4 param_2,uint *param_3)
{
  char cVar1;
  undefined3 extraout_var;
  
  cVar1 = media_resolveXtraEventType();
  media_notifyXtraProperty((ushort)CONCAT31(extraout_var,cVar1),param_2,param_3);
  return 0;
}



// ============================================================
// Function: media_getXtraMovieState (FUN_680af8e0)
// Address: 680af8e0
// Size: 19 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraMovieState(int param_1)
{
  crt_getMovieApiState((undefined4 *)(param_1 + 0x18));
  return 0;
}



// ============================================================
// Function: media_getXtraImageRect (FUN_680af900)
// Address: 680af900
// Size: 26 bytes
// Params: int param_1, LONG * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraImageRect(int param_1,LONG *param_2)
{
  crt_getImageRect((undefined4 *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_getXtraImageDepth (FUN_680af920)
// Address: 680af920
// Size: 26 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraImageDepth(int param_1,uint *param_2)
{
  crt_getImageDepth((undefined4 *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_copyXtraMovieFields (FUN_680af940)
// Address: 680af940
// Size: 26 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_copyXtraMovieFields(int param_1,undefined4 *param_2)
{
  crt_copyMovieFields((undefined4 *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_updateXtraMovieState (FUN_680af960)
// Address: 680af960
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_updateXtraMovieState(int param_1,int *param_2)
{
  crt_updateMovieState((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_queryXtraInterface (FUN_680af980)
// Address: 680af980
// Size: 129 bytes
// Params: int param_1, undefined4 * param_2, int * param_3, undefined4 * param_4, undefined4 param_5, undefined4 * param_6, undefined4 param_7
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_queryXtraInterface(int param_1,undefined4 *param_2,int *param_3,undefined4 *param_4,undefined4 param_5
                ,undefined4 *param_6,undefined4 param_7)

{
  int iVar1;
  int local_20 [7];
  
  if (param_3 == (int *)0x0) {
    iVar1 = -0x7ffbffff;
  }
  else {
    iVar1 = (**(code **)*param_3)(param_3,&DAT_68176468,&param_3);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*param_3 + 0xc))(param_3,local_20);
      if (iVar1 == 0) {
        iVar1 = media_renderTransfer(local_20,(undefined4 *)(*(int *)(param_1 + 4) + 0x18),param_4,param_2,
                             param_5,param_6,0,(int *)0x0,param_7);
      }
      (**(code **)(*param_3 + 8))(param_3);
      return iVar1;
    }
  }
  return iVar1;
}



// ============================================================
// Function: media_queryXtraInterfaceEx (FUN_680afa10)
// Address: 680afa10
// Size: 224 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4, undefined4 param_5, undefined4 * param_6, undefined4 param_7, int * param_8, undefined4 param_9
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_queryXtraInterfaceEx(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 param_5,undefined4 *param_6,undefined4 param_7,int *param_8,
                undefined4 param_9)

{
  int iVar1;
  int *piVar2;
  int local_3c [7];
  int local_20 [7];
  
  local_20[1] = 0;
  local_20[2] = 0;
  local_20[3] = 0;
  local_20[4] = 0;
  local_20[5] = 0;
  local_20[6] = 0;
  piVar2 = (int *)0x0;
  local_20[0] = 0;
  if (param_8 != (int *)0x0) {
    iVar1 = (**(code **)*param_8)(param_8,&DAT_68176468,&param_8);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*param_8 + 0xc))(param_8,local_20);
      if (iVar1 == 0) {
        piVar2 = local_20;
      }
      (**(code **)(*param_8 + 8))(param_8);
    }
  }
  if (param_3 == (undefined4 *)0x0) {
    iVar1 = -0x7ffbffff;
  }
  else {
    iVar1 = (**(code **)*param_3)(param_3,&DAT_68176468,&param_8);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*param_8 + 0xc))(param_8,local_3c);
      if (iVar1 == 0) {
        iVar1 = media_renderTransfer(local_3c,(undefined4 *)(*(int *)(param_1 + 4) + 0x18),param_4,param_2,
                             param_5,param_6,param_7,piVar2,param_9);
      }
      (**(code **)(*param_8 + 8))(param_8);
      return iVar1;
    }
  }
  return iVar1;
}



// ============================================================
// Function: media_getXtraMovieData (FUN_680afaf0)
// Address: 680afaf0
// Size: 32 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getXtraMovieData(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return 0;
}



// ============================================================
// Function: media_setXtraMovieData (FUN_680afb10)
// Address: 680afb10
// Size: 32 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_setXtraMovieData(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// ============================================================
// Function: media_getXtraMovieStateEx (FUN_680afb30)
// Address: 680afb30
// Size: 24 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getXtraMovieStateEx(int param_1)

{
  crt_getMovieApiState((undefined4 *)(*(int *)(param_1 + 4) + 0x18));
  return 0;
}



// ============================================================
// Function: media_resetXtraFields (FUN_680afb50)
// Address: 680afb50
// Size: 20 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_resetXtraFields(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return 0;
}



// ============================================================
// Function: media_checkXtraDirty (FUN_680afb70)
// Address: 680afb70
// Size: 44 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_checkXtraDirty(int param_1,undefined4 *param_2)

{
  char cVar1;
  
  cVar1 = media_updateSpriteStage(param_2,*(undefined4 **)(*(int *)(param_1 + 4) + 0x18));
  if (cVar1 != '\0') {
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x1c) = 1;
  }
  return 0;
}



// ============================================================
// Function: media_setXtraValue (FUN_680afba0)
// Address: 680afba0
// Size: 21 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_setXtraValue(int param_1,undefined4 param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x18) = param_2;
  return 0;
}



// ============================================================
// Function: media_getXtraValue (FUN_680afbc0)
// Address: 680afbc0
// Size: 23 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getXtraValue(int param_1,undefined4 *param_2)

{
  *param_2 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x18);
  return 0;
}



// ============================================================
// Function: media_setXtraFlag (FUN_680afbe0)
// Address: 680afbe0
// Size: 21 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_setXtraFlag(int param_1,undefined4 param_2)

{
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x1c) = param_2;
  return 0;
}



// ============================================================
// Function: media_getXtraFlag (FUN_680afc00)
// Address: 680afc00
// Size: 23 bytes
// Params: int param_1, undefined1 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getXtraFlag(int param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)(*(int *)(param_1 + 4) + 0x1c);
  return 0;
}



// ============================================================
// Function: media_addRef (media_addRef)
// Address: 680afc20
// Size: 33 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_addRef(int param_1)
{
  (**(code **)(**(int **)(param_1 + 4) + 4))(*(int **)(param_1 + 4));
  InterlockedIncrement((LONG *)(param_1 + 8));
  return 0;
}



// ============================================================
// Function: media_getXtraPixelData (FUN_680afc50)
// Address: 680afc50
// Size: 26 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraPixelData(int param_1,uint *param_2)
{
  media_getChannelStateFlags((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_setXtraPixelByte (FUN_680afc70)
// Address: 680afc70
// Size: 26 bytes
// Params: int param_1, byte param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setXtraPixelByte(int param_1,byte param_2)
{
  media_setChannelStateFlags((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_setXtraPixelData (FUN_680afc90)
// Address: 680afc90
// Size: 30 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setXtraPixelData(int param_1,undefined4 param_2,undefined4 param_3)
{
  media_findSpriteInChannel((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3);
  return 0;
}



// ============================================================
// Function: media_resetXtraPixel (FUN_680afcb0)
// Address: 680afcb0
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resetXtraPixel(int param_1)
{
  media_clearChannelMemberFlag((int *)(*(int *)(param_1 + 4) + 0x18));
  return 0;
}



// ============================================================
// Function: media_flushXtraPixel (FUN_680afcd0)
// Address: 680afcd0
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_flushXtraPixel(int param_1)
{
  media_blendChannelMedia((int *)(*(int *)(param_1 + 4) + 0x18));
  return 0;
}



// ============================================================
// Function: media_commitXtraPixel (FUN_680afcf0)
// Address: 680afcf0
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_commitXtraPixel(int param_1)
{
  media_getChannelMediaFormat((int *)(*(int *)(param_1 + 4) + 0x18));
  return 0;
}



// ============================================================
// Function: media_getXtraPixelBlock (FUN_680afd10)
// Address: 680afd10
// Size: 32 bytes
// Params: int param_1, uint param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraPixelBlock(int param_1,uint param_2,uint *param_3)
{
  media_dispatchChannelProperty((int *)(*(int *)(param_1 + 4) + 0x18),0,param_2,param_3);
  return 0;
}



// ============================================================
// Function: media_getXtraTransform (FUN_680afd30)
// Address: 680afd30
// Size: 28 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getXtraTransform(int param_1,int *param_2)

{
  media_resolveChannelRef(*(int *)(param_1 + 4) + 0x18,param_2);
  return 0;
}



// ============================================================
// Function: media_setXtraTransform (FUN_680afd50)
// Address: 680afd50
// Size: 47 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_setXtraTransform(int param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x18) = *param_2;
  *(undefined4 *)(iVar1 + 0x1c) = param_2[1];
  *(undefined4 *)(iVar1 + 0x20) = param_2[2];
  *(undefined4 *)(iVar1 + 0x24) = param_2[3];
  *(undefined4 *)(iVar1 + 0x28) = param_2[4];
  return 0;
}



// ============================================================
// Function: media_getXtraPixelRegion (FUN_680afd80)
// Address: 680afd80
// Size: 34 bytes
// Params: int param_1, int * param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraPixelRegion(int param_1,int *param_2,int param_3,int *param_4)
{
  media_writeChannelData((int *)(*(int *)(param_1 + 4) + 0x18),param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: media_getXtraPixelMap (FUN_680afdb0)
// Address: 680afdb0
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraPixelMap(int param_1,int *param_2)
{
  media_importChannelAsset((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_getXtraPixelPalette (FUN_680afdd0)
// Address: 680afdd0
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraPixelPalette(int param_1,int *param_2)
{
  media_getChannelUpdateData((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_getXtraPixelFormat (FUN_680afdf0)
// Address: 680afdf0
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraPixelFormat(int param_1,int *param_2)
{
  media_updateChannelMedia((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_setXtraPixelFormat (FUN_680afe10)
// Address: 680afe10
// Size: 26 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setXtraPixelFormat(int param_1,int param_2)
{
  media_toggleChannelState((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_finalizeXtraPixel (FUN_680afe30)
// Address: 680afe30
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_finalizeXtraPixel(int param_1)
{
  media_getChannelFrameCount((int *)(*(int *)(param_1 + 4) + 0x18));
  return 0;
}



// ============================================================
// Function: media_getXtraPixelState (FUN_680afe50)
// Address: 680afe50
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraPixelState(int param_1,int *param_2)
{
  media_updateChannelMemberMedia((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_resetXtraPixelState (FUN_680afe70)
// Address: 680afe70
// Size: 38 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resetXtraPixelState(int param_1)
{
  media_resolveChannelState((int *)(*(int *)(param_1 + 4) + 0x18));
  return 0;
}



// ============================================================
// Function: media_setXtraPixelState (FUN_680afea0)
// Address: 680afea0
// Size: 26 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setXtraPixelState(int param_1,int param_2)
{
  media_setChannelVisibility((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_clearXtraPixelState (FUN_680afec0)
// Address: 680afec0
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_clearXtraPixelState(int param_1)
{
  media_getChannelVisibility((int *)(*(int *)(param_1 + 4) + 0x18));
  return 0;
}



// ============================================================
// Function: media_getXtraDataRef (FUN_680afee0)
// Address: 680afee0
// Size: 26 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraDataRef(int param_1,int *param_2)
{
  media_getCastMemberCount((int *)(*(int *)(param_1 + 4) + 0x18),param_2);
  return 0;
}



// ============================================================
// Function: media_createXtraFactory (FUN_680aff00)
// Address: 680aff00
// Size: 131 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_createXtraFactory(undefined4 param_1)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *unaff_EDI;
  int *local_8;
  
  local_8 = (int *)0x0;
  *unaff_EDI = 0;
  uVar2 = Ordinal_1038(&DAT_681763f8,&DAT_68175f78);
  iVar3 = Ordinal_2063(uVar2);
  if ((iVar3 == 0) &&
     (iVar3 = (*(code *)**(undefined4 **)*unaff_EDI)
                        ((undefined4 *)*unaff_EDI,&DAT_68176408,&local_8), iVar3 == 0)) {
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
// Function: media_createXtraFromData (FUN_680aff90)
// Address: 680aff90
// Size: 53 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_createXtraFromData(int param_1,int param_2)
{
  int local_14;
  int iVar1;
  /* FIXUP(C2040: 'local_14': 'int): int local_14 [4]; */
  
  iVar1 = media_getCastMemberByNum((int *)(*(int *)(param_1 + 4) + 0x18),param_2,local_14);
  if (iVar1 == 0) {
    media_createXtraFactory(local_14);
  }
  return 0;
}



// ============================================================
// Function: media_createXtraFromRef (FUN_680affd0)
// Address: 680affd0
// Size: 53 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_createXtraFromRef(int param_1,undefined4 param_2)
{
  int iVar1;
  int local_14 [4];
  
  iVar1 = media_findCastMemberByName((int *)(*(int *)(param_1 + 4) + 0x18),param_2,local_14);
  if (iVar1 == 0) {
    media_createXtraFactory(local_14);
  }
  return 0;
}
