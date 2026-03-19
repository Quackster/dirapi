// Module: lingo
// Topic: Vtable initialization and factory functions
// Address range: 0x6809EC10 - 0x6809FFE0
// Functions (48):
//   lingo_createObject (lingo_createObject)
//   lingo_createVtableObject
//   lingo_setVtableSlot
//   lingo_createObjectEx
//   lingo_ioOpenStream
//   lingo_ioCloseStream
//   lingo_ioReadStream
//   lingo_ioWriteStream
//   lingo_ioSeekStream
//   lingo_ioGetStreamPos
//   lingo_ioGetStreamSize
//   lingo_ioFlushStream
//   lingo_ioReadLine
//   lingo_ioWriteLine
//   lingo_ioGetStatus
//   lingo_ioSetPosition
//   lingo_getImageVtable
//   lingo_getStringVtable
//   lingo_getPropertyVtable
//   lingo_getPixelSetVtable
//   lingo_ioGetProperty
//   lingo_getDrawVtable
//   lingo_getPropValueVtable
//   lingo_getTextVtable
//   lingo_getDialogVtable
//   lingo_getByteIoVtable
//   lingo_getTimerVtable
//   lingo_getXtraApiVtable
//   lingo_getScriptApiVtable
//   lingo_getStreamApiVtable
//   lingo_getInsertVtable
//   lingo_flushStreamState
//   lingo_getListApiVtable
//   lingo_getCloneVtable
//   lingo_getMergeVtable
//   lingo_getStreamReadVtable
//   lingo_createOpenStreamObj
//   lingo_createCloseStreamObj
//   lingo_createReadStreamObj
//   lingo_createWriteStreamObj
//   lingo_createSeekStreamObj
//   lingo_createGetPosObj
//   lingo_vtableDispatchF
//   lingo_vtableDispatchE
//   lingo_vtableDispatchD
//   lingo_vtableDispatchC
//   lingo_vtableDispatchB
//   lingo_vtableDispatchA


// ============================================================
// Function: lingo_createObject (lingo_createObject)
// Address: 6809ec10
// Size: 98 bytes
// Params: int * param_1, undefined4 param_2, undefined * param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 *
lingo_createObject(int *param_1,undefined4 param_2,undefined *param_3,undefined4 param_4,
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
    DAT_6819639c = DAT_6819639c + 1;
    uVar2 = (*(code *)param_3)(puVar1);
    *param_5 = uVar2;
    return puVar1;
  }
  *param_5 = 0x80040002;
  return (undefined4 *)0x0;
}



// ============================================================
// Function: lingo_createVtableObject (FUN_6809ec90)
// Address: 6809ec90
// Size: 42 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_createVtableObject(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 *param_6)

{
  *(undefined4 *)*param_6 = param_3;
  *(undefined4 *)param_6[1] = param_4;
  *(undefined4 *)param_6[2] = param_5;
  *(undefined1 *)(param_6 + 3) = 1;
  return 1;
}



// ============================================================
// Function: lingo_setVtableSlot (FUN_6809ecc0)
// Address: 6809ecc0
// Size: 110 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_setVtableSlot(undefined4 *param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *in_stack_00000018;
  
  puVar1 = (undefined4 *)in_stack_00000018[1];
  *in_stack_00000018 = *in_stack_00000018 + 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    puVar1[2] = param_1[2];
    puVar1[3] = param_1[3];
    *(undefined4 *)(in_stack_00000018[1] + 0x10) = param_2;
    iVar2 = in_stack_00000018[1];
    *(undefined4 *)(iVar2 + 0x14) = 1;
    *(undefined4 *)(iVar2 + 0x18) = 0;
    *(undefined4 *)(iVar2 + 0x1c) = 0xc0;
    *(undefined4 *)(iVar2 + 0x20) = 0x46000000;
    *(undefined4 *)(in_stack_00000018[1] + 0x24) = 1;
    in_stack_00000018[1] = in_stack_00000018[1] + 0x28;
  }
  return 0;
}



// ============================================================
// Function: lingo_createObjectEx (FUN_6809ed30)
// Address: 6809ed30
// Size: 99 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 * param_3, undefined4 param_4, undefined4 param_5, int * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
lingo_createObjectEx(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5,int *param_6)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)param_6[1];
  *param_6 = *param_6 + 1;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = *param_1;
    puVar1[1] = param_1[1];
    puVar1[2] = param_1[2];
    puVar1[3] = param_1[3];
    *(undefined4 *)(param_6[1] + 0x10) = param_2;
    iVar2 = param_6[1];
    *(undefined4 *)(iVar2 + 0x14) = *param_3;
    *(undefined4 *)(iVar2 + 0x18) = param_3[1];
    *(undefined4 *)(iVar2 + 0x1c) = param_3[2];
    *(undefined4 *)(iVar2 + 0x20) = param_3[3];
    *(undefined4 *)(param_6[1] + 0x24) = param_4;
    param_6[1] = param_6[1] + 0x28;
  }
  return 0;
}



// ============================================================
// Function: lingo_ioOpenStream (FUN_6809eda0)
// Address: 6809eda0
// Size: 276 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioOpenStream(void)

{
  if (DAT_6819637c == '\0') {
    DAT_6819637c = '\x01';
    _DAT_68198960 = media_invokeCallback;
    _DAT_68198964 = media_addRef;
    _DAT_68198968 = globals_release;
    _DAT_6819896c = lingo_closeXtra;
    _DAT_68198970 = lingo_openXtra;
    _DAT_68198974 = lingo_getXtraInfo;
    _DAT_68198978 = lingo_getNetData;
    _DAT_6819897c = lingo_getNetStatus;
    _DAT_68198980 = lingo_getNetResult;
    _DAT_68198984 = lingo_getXtraList;
    _DAT_68198988 = lingo_dispatchNetOp;
    _DAT_6819898c = lingo_setCallArgs;
    _DAT_68198990 = lingo_resolveXtraInterface;
    _DAT_68198994 = lingo_getCallArgs;
    _DAT_68198998 = lingo_getCallResult;
    _DAT_6819899c = lingo_dispatchCallEx;
    _DAT_681989a0 = lingo_apiCallFunc;
    _DAT_681989a4 = lingo_apiAlloc;
    _DAT_681989a8 = lingo_apiFree;
    _DAT_681989ac = lingo_apiDebugPrint;
    _DAT_681989b0 = lingo_apiBreak;
    _DAT_681989b4 = lingo_apiResume;
    _DAT_681989b8 = lingo_apiGetSymbol;
    _DAT_681989bc = lingo_apiSetSymbol;
    _DAT_681989c0 = lingo_apiGetGlobal;
  }
  return &DAT_68198960;
}



// ============================================================
// Function: lingo_ioCloseStream (FUN_6809eec0)
// Address: 6809eec0
// Size: 122 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioCloseStream(void)

{
  if (DAT_6819637d == '\0') {
    DAT_6819637d = '\x01';
    _DAT_68198520 = media_invokeCallback;
    _DAT_68198524 = media_addRef;
    _DAT_68198528 = globals_release;
    _DAT_6819852c = lingo_apiSetGlobal;
    _DAT_68198530 = lingo_apiGetLocal;
    _DAT_68198534 = lingo_apiSetLocal;
    _DAT_68198538 = lingo_apiGetMember;
    _DAT_6819853c = lingo_apiSetMember;
    _DAT_68198540 = lingo_apiDeleteMember;
    _DAT_68198544 = lingo_apiGetHandler;
  }
  return &DAT_68198520;
}



// ============================================================
// Function: lingo_ioReadStream (FUN_6809ef40)
// Address: 6809ef40
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioReadStream(void)

{
  if (DAT_6819637e == '\0') {
    DAT_6819637e = '\x01';
    _DAT_681985e0 = media_invokeCallback;
    _DAT_681985e4 = media_addRef;
    _DAT_681985e8 = globals_release;
    _DAT_681985ec = lingo_apiRegisterHandler;
    _DAT_681985f0 = lingo_apiGetCast;
    _DAT_681985f4 = lingo_apiSetCast;
    _DAT_681985f8 = lingo_apiDeleteCast;
  }
  return &DAT_681985e0;
}



// ============================================================
// Function: lingo_ioWriteStream (FUN_6809efa0)
// Address: 6809efa0
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioWriteStream(void)

{
  if (DAT_6819637f == '\0') {
    DAT_6819637f = '\x01';
    _DAT_68198500 = media_invokeCallback;
    _DAT_68198504 = media_addRef;
    _DAT_68198508 = globals_release;
    _DAT_6819850c = lingo_apiGetSprite;
    _DAT_68198510 = lingo_apiSetSprite;
    _DAT_68198514 = &LAB_6809c5e0;
    _DAT_68198518 = lingo_apiGetChannel;
  }
  return &DAT_68198500;
}



// ============================================================
// Function: lingo_ioSeekStream (FUN_6809f000)
// Address: 6809f000
// Size: 132 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioSeekStream(void)

{
  if (DAT_68196380 == '\0') {
    DAT_68196380 = '\x01';
    _DAT_681988c0 = media_invokeCallback;
    _DAT_681988c4 = media_addRef;
    _DAT_681988c8 = globals_release;
    _DAT_681988cc = lingo_apiSetChannel;
    _DAT_681988d0 = lingo_apiGetFrame;
    _DAT_681988d4 = lingo_apiSetFrame;
    _DAT_681988d8 = lingo_apiGetScore;
    _DAT_681988dc = lingo_apiSetScore;
    _DAT_681988e0 = lingo_apiGetMovie;
    _DAT_681988e4 = lingo_apiSetMovie;
    _DAT_681988e8 = &LAB_6809c790;
  }
  return &DAT_681988c0;
}



// ============================================================
// Function: lingo_ioGetStreamPos (FUN_6809f090)
// Address: 6809f090
// Size: 102 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioGetStreamPos(void)

{
  if (DAT_68196381 == '\0') {
    DAT_68196381 = '\x01';
    _DAT_68198940 = media_invokeCallback;
    _DAT_68198944 = media_addRef;
    _DAT_68198948 = globals_release;
    _DAT_6819894c = lingo_apiGetAppInfo;
    _DAT_68198950 = lingo_apiGetBuildInfo;
    _DAT_68198954 = lingo_apiGetEncoding;
    _DAT_68198958 = lingo_apiGetOS;
    _DAT_6819895c = sprites_initEventContext;
  }
  return &DAT_68198940;
}



// ============================================================
// Function: lingo_ioGetStreamSize (FUN_6809f100)
// Address: 6809f100
// Size: 176 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioGetStreamSize(void)

{
  if (DAT_68196382 == '\0') {
    DAT_68196382 = '\x01';
    _DAT_68198880 = media_invokeCallback;
    _DAT_68198884 = media_addRef;
    _DAT_68198888 = globals_release;
    _DAT_6819888c = lingo_cmdGetProperty2;
    _DAT_68198890 = lingo_cmdSetProperty2;
    _DAT_68198894 = strings_wrapGetPropertyPair;
    _DAT_68198898 = lingo_cmdCallMethod2;
    _DAT_6819889c = lingo_cmdGetCount2;
    _DAT_681988a0 = lingo_cmdGetByIndex2;
    _DAT_681988a4 = lingo_cmdSetByIndex2;
    _DAT_681988a8 = lingo_vtableGetProp;
    _DAT_681988ac = lingo_vtableSetProp;
    _DAT_681988b0 = lingo_vtableSetPropStr;
    _DAT_681988b4 = strings_wrapGetPropertyValue;
    _DAT_681988b8 = strings_wrapSetPropertyValue;
  }
  return &DAT_68198880;
}



// ============================================================
// Function: lingo_ioFlushStream (FUN_6809f1b0)
// Address: 6809f1b0
// Size: 82 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioFlushStream(void)

{
  if (DAT_68196383 == '\0') {
    DAT_68196383 = '\x01';
    _DAT_68198860 = media_invokeCallback;
    _DAT_68198864 = media_addRef;
    _DAT_68198868 = globals_release;
    _DAT_6819886c = lingo_cmdCount;
    _DAT_68198870 = lingo_cmdGetAt;
    _DAT_68198874 = lingo_cmdSetAt;
  }
  return &DAT_68198860;
}



// ============================================================
// Function: lingo_ioReadLine (FUN_6809f210)
// Address: 6809f210
// Size: 82 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioReadLine(void)

{
  if (DAT_68196384 == '\0') {
    DAT_68196384 = '\x01';
    _DAT_68198720 = media_invokeCallback;
    _DAT_68198724 = media_addRef;
    _DAT_68198728 = globals_release;
    _DAT_6819872c = lingo_cmdDeleteAt;
    _DAT_68198730 = lingo_cmdAddProp;
    _DAT_68198734 = lingo_cmdFindPos;
  }
  return &DAT_68198720;
}



// ============================================================
// Function: lingo_ioWriteLine (FUN_6809f270)
// Address: 6809f270
// Size: 132 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioWriteLine(void)

{
  if (DAT_68196385 == '\0') {
    DAT_68196385 = '\x01';
    _DAT_68198620 = media_invokeCallback;
    _DAT_68198624 = media_addRef;
    _DAT_68198628 = globals_release;
    _DAT_6819862c = lingo_getVtablePtr;
    _DAT_68198630 = lingo_setVtableRef;
    _DAT_68198634 = lingo_getVtableList;
    _DAT_68198638 = lingo_callVtableMethodEx;
    _DAT_6819863c = lingo_callVtableMethod;
    _DAT_68198640 = lingo_getVtableRef;
    _DAT_68198644 = lingo_setVtableFlag;
    _DAT_68198648 = lingo_getVtableValue;
  }
  return &DAT_68198620;
}



// ============================================================
// Function: lingo_ioGetStatus (FUN_6809f300)
// Address: 6809f300
// Size: 142 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioGetStatus(void)

{
  if (DAT_68196386 == '\0') {
    DAT_68196386 = '\x01';
    _DAT_681986e0 = media_invokeCallback;
    _DAT_681986e4 = media_addRef;
    _DAT_681986e8 = globals_release;
    _DAT_681986ec = lingo_getVtablePtr;
    _DAT_681986f0 = lingo_setVtableRef;
    _DAT_681986f4 = lingo_getVtableList;
    _DAT_681986f8 = lingo_callVtableMethodEx;
    _DAT_681986fc = lingo_callVtableMethod;
    _DAT_68198700 = lingo_getVtableRef;
    _DAT_68198704 = lingo_setVtableFlag;
    _DAT_68198708 = lingo_getVtableValue;
    _DAT_6819870c = lingo_setVtableValue;
  }
  return &DAT_681986e0;
}



// ============================================================
// Function: lingo_ioSetPosition (FUN_6809f390)
// Address: 6809f390
// Size: 166 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_ioSetPosition(void)

{
  if (DAT_68196387 == '\0') {
    DAT_68196387 = '\x01';
    _DAT_68198760 = media_invokeCallback;
    _DAT_68198764 = media_addRef;
    _DAT_68198768 = globals_release;
    _DAT_6819876c = lingo_getVtablePtr;
    _DAT_68198770 = lingo_setVtableRef;
    _DAT_68198774 = lingo_getVtableList;
    _DAT_68198778 = lingo_callVtableMethodEx;
    _DAT_6819877c = lingo_callVtableMethod;
    _DAT_68198780 = lingo_getVtableRef;
    _DAT_68198784 = lingo_setVtableFlag;
    _DAT_68198788 = lingo_getVtableValue;
    _DAT_6819878c = lingo_setVtableValue;
    _DAT_68198790 = lingo_cmdGetAlpha;
    _DAT_68198794 = lingo_cmdCreateMask;
  }
  return &DAT_68198760;
}



// ============================================================
// Function: lingo_getImageVtable (FUN_6809f440)
// Address: 6809f440
// Size: 246 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getImageVtable(void)

{
  if (DAT_68196388 == '\0') {
    DAT_68196388 = '\x01';
    _DAT_68198560 = media_invokeCallback;
    _DAT_68198564 = media_addRef;
    _DAT_68198568 = globals_release;
    _DAT_6819856c = lingo_cmdCreateMatte;
    _DAT_68198570 = lingo_cmdTrimWhitespace;
    _DAT_68198574 = lingo_cmdExtract;
    _DAT_68198578 = lingo_cmdFilter;
    _DAT_6819857c = lingo_cmdRotate;
    _DAT_68198580 = lingo_cmdCrop;
    _DAT_68198584 = lingo_cmdMap;
    _DAT_68198588 = lingo_cmdSetSize;
    _DAT_6819858c = lingo_cmdMediaReady;
    _DAT_68198590 = lingo_cmdGetImage;
    _DAT_68198598 = sprites_getEventContext;
    _DAT_6819859c = sprites_getEventContext;
    _DAT_681985a0 = lingo_cmdGetUseAlpha;
    _DAT_681985a4 = lingo_cmdGetBits;
    _DAT_681985a8 = &LAB_6809de10;
    _DAT_68198594 = lingo_cmdSetImage;
    _DAT_681985ac = lingo_cmdPurge;
    _DAT_681985b0 = lingo_cmdGetMovieRef;
    _DAT_681985b4 = lingo_cmdSetMovieRef;
  }
  return &DAT_68198560;
}



// ============================================================
// Function: lingo_getStringVtable (FUN_6809f540)
// Address: 6809f540
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getStringVtable(void)

{
  if (DAT_68196389 == '\0') {
    DAT_68196389 = '\x01';
    _DAT_68198600 = media_invokeCallback;
    _DAT_68198604 = media_addRef;
    _DAT_68198608 = globals_release;
    _DAT_6819860c = lingo_cmdWriteString;
    _DAT_68198610 = lingo_cmdReadString;
  }
  return &DAT_68198600;
}



// ============================================================
// Function: lingo_getPropertyVtable (FUN_6809f590)
// Address: 6809f590
// Size: 82 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getPropertyVtable(void)

{
  if (DAT_6819638a == '\0') {
    DAT_6819638a = '\x01';
    _DAT_68198660 = media_invokeCallback;
    _DAT_68198664 = media_addRef;
    _DAT_68198668 = globals_release;
    _DAT_6819866c = lingo_cmdGetProp;
    _DAT_68198670 = lingo_cmdSetProp;
    _DAT_68198674 = lingo_cmdGetPixel;
  }
  return &DAT_68198660;
}



// ============================================================
// Function: lingo_getPixelSetVtable (FUN_6809f5f0)
// Address: 6809f5f0
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getPixelSetVtable(void)

{
  if (DAT_6819638b == '\0') {
    DAT_6819638b = '\x01';
    _DAT_68198650 = media_invokeCallback;
    _DAT_68198654 = media_addRef;
    _DAT_68198658 = globals_release;
    _DAT_6819865c = lingo_cmdSetPixel;
  }
  return &DAT_68198650;
}



// ============================================================
// Function: lingo_ioGetProperty (FUN_6809f630)
// Address: 6809f630
// Size: 77 bytes
// Params: int * param_1
// Return: LONG
// Calling convention: __stdcall
// ============================================================

LONG lingo_ioGetProperty(int *param_1)

{
  int *piVar1;
  LONG LVar2;
  
  LVar2 = InterlockedDecrement(param_1 + 2);
  piVar1 = (int *)param_1[1];
  if (LVar2 == 0) {
    lingo_cmdGetRect(param_1);
    (**(code **)(*(int *)piVar1[3] + 0x10))((int *)piVar1[3],param_1);
    DAT_6819639c = DAT_6819639c + -1;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*piVar1 + 8))(piVar1);
  return LVar2;
}



// ============================================================
// Function: lingo_getDrawVtable (FUN_6809f680)
// Address: 6809f680
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getDrawVtable(void)

{
  if (DAT_6819638c == '\0') {
    DAT_6819638c = '\x01';
    _DAT_68198900 = media_invokeCallback;
    _DAT_68198904 = media_addRef;
    _DAT_68198908 = lingo_ioGetProperty;
    _DAT_6819890c = &LAB_6809d5e0;
    _DAT_68198910 = lingo_cmdDraw;
    _DAT_68198914 = lingo_cmdFill;
    _DAT_68198918 = lingo_cmdSetAlpha;
  }
  return &DAT_68198900;
}



// ============================================================
// Function: lingo_getPropValueVtable (FUN_6809f6e0)
// Address: 6809f6e0
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getPropValueVtable(void)

{
  if (DAT_6819638d == '\0') {
    DAT_6819638d = '\x01';
    _DAT_681989e0 = media_invokeCallback;
    _DAT_681989e4 = media_addRef;
    _DAT_681989e8 = globals_release;
    _DAT_681989ec = lingo_apiSetPropValue;
  }
  return &DAT_681989e0;
}



// ============================================================
// Function: lingo_getTextVtable (FUN_6809f720)
// Address: 6809f720
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getTextVtable(void)

{
  if (DAT_6819638e == '\0') {
    DAT_6819638e = '\x01';
    _DAT_68198920 = media_invokeCallback;
    _DAT_68198924 = media_addRef;
    _DAT_68198928 = globals_release;
    _DAT_6819892c = lingo_apiGetPropValue;
    _DAT_68198930 = lingo_apiGetText;
  }
  return &DAT_68198920;
}



// ============================================================
// Function: lingo_getDialogVtable (FUN_6809f770)
// Address: 6809f770
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getDialogVtable(void)

{
  if (DAT_68196390 == '\0') {
    DAT_68196390 = '\x01';
    _DAT_68198680 = media_invokeCallback;
    _DAT_68198684 = media_addRef;
    _DAT_68198688 = globals_release;
    _DAT_6819868c = lingo_apiShowDialogW;
    _DAT_68198690 = lingo_apiShowDialog;
  }
  return &DAT_68198680;
}



// ============================================================
// Function: lingo_getByteIoVtable (FUN_6809f7c0)
// Address: 6809f7c0
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getByteIoVtable(void)

{
  if (DAT_68196391 == '\0') {
    DAT_68196391 = '\x01';
    _DAT_681986a0 = media_invokeCallback;
    _DAT_681986a4 = media_addRef;
    _DAT_681986a8 = globals_release;
    _DAT_681986ac = lingo_apiWriteByte;
    _DAT_681986b0 = lingo_apiReadByte;
  }
  return &DAT_681986a0;
}



// ============================================================
// Function: lingo_getTimerVtable (FUN_6809f810)
// Address: 6809f810
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getTimerVtable(void)

{
  if (DAT_68196392 == '\0') {
    DAT_68196392 = '\x01';
    _DAT_681989d0 = media_invokeCallback;
    _DAT_681989d4 = media_addRef;
    _DAT_681989d8 = globals_release;
    _DAT_681989dc = lingo_apiCreateTimer;
  }
  return &DAT_681989d0;
}



// ============================================================
// Function: lingo_getXtraApiVtable (FUN_6809f850)
// Address: 6809f850
// Size: 102 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getXtraApiVtable(void)

{
  if (DAT_68196393 == '\0') {
    DAT_68196393 = '\x01';
    _DAT_681987a0 = media_invokeCallback;
    _DAT_681987a4 = media_addRef;
    _DAT_681987a8 = globals_release;
    _DAT_681987ac = lingo_apiSetProperty;
    _DAT_681987b0 = lingo_apiGetProperty;
    _DAT_681987b4 = lingo_apiGetPlatform;
    _DAT_681987b8 = lingo_apiSetCallback;
    _DAT_681987bc = lingo_apiQueryInterface;
  }
  return &DAT_681987a0;
}



// ============================================================
// Function: lingo_getScriptApiVtable (FUN_6809f8c0)
// Address: 6809f8c0
// Size: 176 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getScriptApiVtable(void)

{
  if (DAT_68196394 == '\0') {
    DAT_68196394 = '\x01';
    _DAT_68198820 = media_invokeCallback;
    _DAT_68198824 = media_addRef;
    _DAT_68198828 = globals_release;
    _DAT_6819882c = lingo_apiGetValue;
    _DAT_68198830 = lingo_apiTranscodeStrEx;
    _DAT_68198834 = lingo_apiTranscodeStr;
    _DAT_68198838 = lingo_apiConvertMulti;
    _DAT_6819883c = lingo_apiConvertWide;
    _DAT_68198840 = lingo_apiMultiToWide;
    _DAT_68198844 = lingo_apiWideToMulti;
    _DAT_68198848 = lingo_apiIsType;
    _DAT_6819884c = lingo_apiCreateObject;
    _DAT_68198850 = lingo_cmdCompare;
    _DAT_68198854 = lingo_cmdGetType;
    _DAT_68198858 = lingo_cmdIlk;
  }
  return &DAT_68198820;
}



// ============================================================
// Function: lingo_getStreamApiVtable (FUN_6809f970)
// Address: 6809f970
// Size: 156 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getStreamApiVtable(void)

{
  if (DAT_68196395 == '\0') {
    DAT_68196395 = '\x01';
    _DAT_681987e0 = media_invokeCallback;
    _DAT_681987e4 = media_addRef;
    _DAT_681987e8 = globals_release;
    _DAT_681987ec = lingo_vtableCallHandler;
    _DAT_681987f0 = lingo_vtableFlush;
    _DAT_681987f4 = lingo_vtableGetValue;
    _DAT_681987f8 = lingo_vtableSetValue;
    _DAT_681987fc = lingo_vtableGetCount2;
    _DAT_68198800 = lingo_vtableGetByIndex;
    _DAT_68198804 = lingo_vtableSetByIndex;
    _DAT_68198808 = lingo_vtableAppend;
    _DAT_6819880c = lingo_vtableGetNext;
    _DAT_68198810 = lingo_vtableDeleteByIndex;
  }
  return &DAT_681987e0;
}



// ============================================================
// Function: lingo_getInsertVtable (FUN_6809fa10)
// Address: 6809fa10
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getInsertVtable(void)

{
  if (DAT_68196396 == '\0') {
    DAT_68196396 = '\x01';
    _DAT_681986c0 = media_invokeCallback;
    _DAT_681986c4 = media_addRef;
    _DAT_681986c8 = globals_release;
    _DAT_681986cc = lingo_vtableInsert;
  }
  return &DAT_681986c0;
}



// ============================================================
// Function: lingo_flushStreamState (FUN_6809fa50)
// Address: 6809fa50
// Size: 17 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_flushStreamState(void)
{
  lingo_getStreamState();
  return 0;
}



// ============================================================
// Function: lingo_getListApiVtable (FUN_6809fa70)
// Address: 6809fa70
// Size: 82 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getListApiVtable(void)

{
  if (DAT_68196397 == '\0') {
    DAT_68196397 = '\x01';
    _DAT_681987c0 = media_invokeCallback;
    _DAT_681987c4 = media_addRef;
    _DAT_681987c8 = globals_release;
    _DAT_681987cc = lingo_vtableContains;
    _DAT_681987d0 = lingo_vtableSort;
    _DAT_681987d4 = lingo_vtableDelete;
  }
  return &DAT_681987c0;
}



// ============================================================
// Function: lingo_getCloneVtable (FUN_6809fad0)
// Address: 6809fad0
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getCloneVtable(void)

{
  if (DAT_68196398 == '\0') {
    DAT_68196398 = '\x01';
    _DAT_68198710 = media_invokeCallback;
    _DAT_68198714 = media_addRef;
    _DAT_68198718 = globals_release;
    _DAT_6819871c = lingo_vtableClone;
  }
  return &DAT_68198710;
}



// ============================================================
// Function: lingo_getMergeVtable (FUN_6809fb10)
// Address: 6809fb10
// Size: 82 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getMergeVtable(void)

{
  if (DAT_68196399 == '\0') {
    DAT_68196399 = '\x01';
    _DAT_681985c0 = media_invokeCallback;
    _DAT_681985c4 = media_addRef;
    _DAT_681985c8 = globals_release;
    _DAT_681985cc = lingo_vtableMerge;
    _DAT_681985d0 = lingo_vtableGetPropList;
    _DAT_681985d4 = lingo_vtableToString;
  }
  return &DAT_681985c0;
}



// ============================================================
// Function: lingo_getStreamReadVtable (FUN_6809fb70)
// Address: 6809fb70
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * lingo_getStreamReadVtable(void)

{
  if (DAT_6819639a == '\0') {
    DAT_6819639a = '\x01';
    _DAT_68198740 = media_invokeCallback;
    _DAT_68198744 = media_addRef;
    _DAT_68198748 = globals_release;
    _DAT_6819874c = lingo_readStream;
    _DAT_68198750 = media_getInterfaceRef;
  }
  return &DAT_68198740;
}



// ============================================================
// Function: lingo_createOpenStreamObj (FUN_6809fbc0)
// Address: 6809fbc0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_createOpenStreamObj(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioOpenStream();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_createCloseStreamObj (FUN_6809fc20)
// Address: 6809fc20
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_createCloseStreamObj(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioCloseStream();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_createReadStreamObj (FUN_6809fc80)
// Address: 6809fc80
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_createReadStreamObj(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioReadStream();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_createWriteStreamObj (FUN_6809fce0)
// Address: 6809fce0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_createWriteStreamObj(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioWriteStream();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_createSeekStreamObj (FUN_6809fd40)
// Address: 6809fd40
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_createSeekStreamObj(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioSeekStream();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_createGetPosObj (FUN_6809fda0)
// Address: 6809fda0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_createGetPosObj(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioGetStreamPos();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_vtableDispatchF (FUN_6809fe00)
// Address: 6809fe00
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_vtableDispatchF(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioGetStreamSize();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_vtableDispatchE (FUN_6809fe60)
// Address: 6809fe60
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_vtableDispatchE(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioFlushStream();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_vtableDispatchD (FUN_6809fec0)
// Address: 6809fec0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_vtableDispatchD(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioReadLine();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_vtableDispatchC (FUN_6809ff20)
// Address: 6809ff20
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_vtableDispatchC(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioWriteLine();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_vtableDispatchB (FUN_6809ff80)
// Address: 6809ff80
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_vtableDispatchB(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioGetStatus();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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
// Function: lingo_vtableDispatchA (FUN_6809ffe0)
// Address: 6809ffe0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_vtableDispatchA(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = lingo_ioSetPosition();
  piVar3 = lingo_createObject(param_1,0xc,lingo_noop,puVar2,piVar3);
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


