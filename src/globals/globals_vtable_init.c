// Module: globals
// Topic: Vtable initializers, reference counting, and object factory functions
// Address range: 0x68170D10 - 0x68171E20
// Functions (24):
//   globals_initFullVtable
//   globals_initStreamVtable
//   globals_initMediaVtable
//   globals_initHandlerVtable
//   globals_initBuildInfoVtable
//   globals_initDialogVtable
//   globals_initTimerVtable
//   globals_initStringIoVtable
//   globals_initByteIoVtable
//   globals_initPropertyVtable
//   globals_initPairVtable
//   globals_initAccessorVtable
//   globals_release (FUN_681715b0)
//   globals_initReadWriteVtable
//   globals_initMediaDispatchVtable
//   globals_initVectorVtable
//   globals_initExtPropertyVtable
//   globals_createFullObject
//   globals_createStreamObject
//   globals_createMediaObject
//   globals_createHandlerObject
//   globals_createBuildInfoObject
//   globals_createDialogObject
//   globals_createTimerObject

int strings_xtraShowDialog(); /* FIXUP: forward declaration */
int strings_xtraCreateTimer(); /* FIXUP: forward declaration */
int globals_dispatchGetProperty(); /* FIXUP: forward declaration */
int globals_dispatchGetInt(); /* FIXUP: forward declaration */
int globals_dispatchGetBool(); /* FIXUP: forward declaration */
int globals_dispatchGetString(); /* FIXUP: forward declaration */
int globals_dispatchGetFloat(); /* FIXUP: forward declaration */
int globals_dispatchSetProperty(); /* FIXUP: forward declaration */
int globals_dispatchSetMethod(); /* FIXUP: forward declaration */

// ============================================================
// Function: globals_initFullVtable (FUN_68170d10)
// Address: 68170d10
// Size: 506 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initFullVtable(void)

{
  if (DAT_68196a3c == '\0') {
    DAT_68196a3c = '\x01';
    _DAT_68197680 = media_invokeCallback;
    _DAT_68197684 = media_addRef;
    _DAT_68197688 = globals_release;
    _DAT_6819768c = strings_wrapFormatValue1;
    _DAT_68197690 = strings_wrapFormatValue2;
    _DAT_68197694 = strings_wrapFormatValue3;
    _DAT_68197698 = strings_wrapFormatValue4;
    _DAT_6819769c = strings_wrapFormatValue5;
    _DAT_681976a0 = strings_wrapResolveSymbol;
    _DAT_681976a4 = strings_wrapGetSymbolNext;
    _DAT_681976a8 = strings_wrapGetValueType;
    _DAT_681976ac = strings_wrapRetainValue;
    _DAT_681976b0 = strings_wrapReleaseValue;
    _DAT_681976b4 = strings_wrapCoerceToInt;
    _DAT_681976b8 = strings_wrapCoerceToFloat;
    _DAT_681976bc = strings_wrapCoerceToDouble;
    _DAT_681976c0 = strings_wrapGetComponentCount;
    _DAT_681976c4 = strings_wrapCoerceToStringNext;
    _DAT_681976c8 = strings_wrapGetApiContext;
    _DAT_681976cc = strings_wrapGetApiState;
    _DAT_681976d0 = strings_wrapGetContextState;
    _DAT_681976d4 = strings_wrapCreateRect;
    _DAT_681976d8 = strings_wrapStoreIntValue;
    _DAT_681976dc = strings_wrapStoreObjectRef;
    _DAT_681976e0 = strings_wrapStoreFloatDirect;
    _DAT_681976e4 = strings_wrapLoadStringValue;
    _DAT_681976e8 = strings_wrapGetExtPair;
    _DAT_681976ec = strings_wrapStoreSymbolRef;
    _DAT_681976f0 = strings_xtraQueryInterface;
    _DAT_681976f4 = strings_xtraSetProperty;
    _DAT_681976f8 = strings_xtraGetBuildInfo;
    _DAT_681976fc = strings_getXtraVersion;
    _DAT_68197700 = strings_xtraGetEncoding;
    _DAT_68197704 = strings_getXtraVersion;
    _DAT_68197708 = strings_xtraGetOS;
    _DAT_6819770c = strings_xtraGetPlatform;
    _DAT_68197710 = strings_xtraGetAppInfo;
    _DAT_68197714 = &LAB_6816f590;
    _DAT_68197718 = strings_xtraGetAppInfo;
    _DAT_6819771c = strings_xtraGetAppInfo;
    _DAT_68197720 = strings_xtraGetAppInfo;
    _DAT_68197724 = strings_xtraShowDialogW;
    _DAT_68197728 = strings_xtraGetValue;
    _DAT_6819772c = strings_xtraReadByte;
    _DAT_68197730 = strings_xtraWriteByte;
    _DAT_68197734 = strings_xtraShowDialog;
    _DAT_68197738 = strings_xtraSetCallback;
    _DAT_6819773c = strings_xtraGetVersion;
  }
  return &DAT_68197680;
}



// ============================================================
// Function: globals_initStreamVtable (FUN_68170f10)
// Address: 68170f10
// Size: 132 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initStreamVtable(void)

{
  if (DAT_68196a3d == '\0') {
    DAT_68196a3d = '\x01';
    _DAT_68197380 = media_invokeCallback;
    _DAT_68197384 = media_addRef;
    _DAT_68197388 = globals_release;
    _DAT_6819738c = strings_wrapFormatValue1;
    _DAT_68197390 = strings_wrapFormatValue2;
    _DAT_68197394 = strings_wrapFormatValue3;
    _DAT_68197398 = strings_wrapFormatValue4;
    _DAT_6819739c = strings_wrapFormatValue5;
    _DAT_681973a0 = strings_xtraSetProperty;
    _DAT_681973a4 = strings_xtraReadByte;
    _DAT_681973a8 = strings_xtraWriteByte;
  }
  return &DAT_68197380;
}



// ============================================================
// Function: globals_initMediaVtable (FUN_68170fa0)
// Address: 68170fa0
// Size: 266 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initMediaVtable(void)

{
  if (DAT_68196a3e == '\0') {
    DAT_68196a3e = '\x01';
    _DAT_68197620 = media_invokeCallback;
    _DAT_68197624 = media_addRef;
    _DAT_68197628 = globals_release;
    _DAT_6819762c = strings_wrapResolveSymbol;
    _DAT_68197630 = strings_wrapGetSymbolString;
    _DAT_68197634 = strings_wrapGetValueType;
    _DAT_68197638 = strings_wrapRetainValue;
    _DAT_6819763c = strings_wrapReleaseValue;
    _DAT_68197640 = strings_wrapCoerceToInt;
    _DAT_68197644 = strings_wrapCoerceToFloat;
    _DAT_68197648 = strings_wrapCoerceToDouble;
    _DAT_6819764c = strings_wrapGetComponentCount;
    _DAT_68197650 = strings_wrapCoerceToString;
    _DAT_68197654 = strings_wrapGetApiContext;
    _DAT_68197658 = strings_wrapGetApiState;
    _DAT_6819765c = strings_wrapGetContextState;
    _DAT_68197660 = strings_wrapCreateRect;
    _DAT_68197664 = strings_wrapStoreIntValue;
    _DAT_68197668 = strings_wrapStoreObjectRef;
    _DAT_6819766c = strings_wrapStoreFloatDirect;
    _DAT_68197670 = strings_wrapLoadStringValue;
    _DAT_68197674 = strings_wrapGetExtPair;
    _DAT_68197678 = strings_wrapStoreSymbolRef;
    _DAT_6819767c = strings_xtraQueryInterface;
  }
  return &DAT_68197620;
}



// ============================================================
// Function: globals_initHandlerVtable (FUN_681710b0)
// Address: 681710b0
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initHandlerVtable(void)

{
  if (DAT_68196a3f == '\0') {
    DAT_68196a3f = '\x01';
    _DAT_681973e0 = media_invokeCallback;
    _DAT_681973e4 = media_addRef;
    _DAT_681973e8 = globals_release;
    _DAT_681973ec = strings_wrapGetMediaRef;
    _DAT_681973f0 = strings_wrapSetMediaRef;
    _DAT_681973f4 = strings_wrapGetMediaFormat;
    _DAT_681973f8 = strings_wrapCreateListValue;
  }
  return &DAT_681973e0;
}



// ============================================================
// Function: globals_initBuildInfoVtable (FUN_68171110)
// Address: 68171110
// Size: 166 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initBuildInfoVtable(void)

{
  if (DAT_68196a40 == '\0') {
    DAT_68196a40 = '\x01';
    _DAT_68197440 = media_invokeCallback;
    _DAT_68197444 = media_addRef;
    _DAT_68197448 = globals_release;
    _DAT_6819744c = strings_xtraGetBuildInfo;
    _DAT_68197450 = strings_getXtraVersion;
    _DAT_68197454 = strings_xtraGetEncoding;
    _DAT_68197458 = strings_getXtraVersion;
    _DAT_6819745c = strings_xtraGetOS;
    _DAT_68197460 = strings_xtraGetPlatform;
    _DAT_68197464 = strings_xtraGetAppInfo;
    _DAT_68197468 = &LAB_6816f590;
    _DAT_6819746c = strings_xtraGetAppInfo;
    _DAT_68197470 = strings_xtraGetAppInfo;
    _DAT_68197474 = strings_xtraGetAppInfo;
  }
  return &DAT_68197440;
}



// ============================================================
// Function: globals_initDialogVtable (FUN_681711c0)
// Address: 681711c0
// Size: 102 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initDialogVtable(void)

{
  if (DAT_68196a41 == '\0') {
    DAT_68196a41 = '\x01';
    _DAT_68197740 = media_invokeCallback;
    _DAT_68197744 = media_addRef;
    _DAT_68197748 = globals_release;
    _DAT_6819774c = strings_xtraShowDialogW;
    _DAT_68197750 = strings_xtraGetValue;
    _DAT_68197754 = strings_xtraShowDialog;
    _DAT_68197758 = strings_xtraSetCallback;
    _DAT_6819775c = strings_xtraGetVersion;
  }
  return &DAT_68197740;
}



// ============================================================
// Function: globals_initTimerVtable (FUN_68171230)
// Address: 68171230
// Size: 122 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initTimerVtable(void)

{
  if (DAT_68196a42 == '\0') {
    DAT_68196a42 = '\x01';
    _DAT_68197560 = media_invokeCallback;
    _DAT_68197564 = media_addRef;
    _DAT_68197568 = globals_release;
    _DAT_6819756c = strings_xtraGetProperty;
    _DAT_68197570 = strings_xtraGetText;
    _DAT_68197574 = strings_xtraCreateTimer;
    _DAT_68197578 = strings_wrapReadScoreSlot;
    _DAT_6819757c = strings_wrapGetCastInfo;
    _DAT_68197580 = strings_wrapGetCastProperty;
    _DAT_68197584 = strings_wrapSetCastProperty;
  }
  return &DAT_68197560;
}



// ============================================================
// Function: globals_initStringIoVtable (FUN_681712b0)
// Address: 681712b0
// Size: 132 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initStringIoVtable(void)

{
  if (DAT_68196a43 == '\0') {
    DAT_68196a43 = '\x01';
    _DAT_68197500 = media_invokeCallback;
    _DAT_68197504 = media_addRef;
    _DAT_68197508 = globals_release;
    _DAT_6819750c = strings_xtraGetProperty;
    _DAT_68197510 = strings_xtraGetText;
    _DAT_68197514 = strings_wrapSetXtraProperty;
    _DAT_68197518 = strings_wrapResolveScript;
    _DAT_6819751c = strings_wrapGetScriptFormat;
    _DAT_68197520 = strings_wrapResolveFormat;
    _DAT_68197524 = strings_wrapGetFormatProperty;
    _DAT_68197528 = strings_wrapResolveMedia;
  }
  return &DAT_68197500;
}



// ============================================================
// Function: globals_initByteIoVtable (FUN_68171340)
// Address: 68171340
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initByteIoVtable(void)

{
  if (DAT_68196a44 == '\0') {
    DAT_68196a44 = '\x01';
    _DAT_68197540 = media_invokeCallback;
    _DAT_68197544 = media_addRef;
    _DAT_68197548 = globals_release;
    _DAT_6819754c = strings_wrapCoerceAndStore;
    _DAT_68197550 = strings_wrapStoreFloatValue;
    _DAT_68197554 = strings_xtraReadByte;
    _DAT_68197558 = strings_xtraWriteByte;
  }
  return &DAT_68197540;
}



// ============================================================
// Function: globals_initPropertyVtable (FUN_681713a0)
// Address: 681713a0
// Size: 276 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initPropertyVtable(void)

{
  if (DAT_68196a45 == '\0') {
    DAT_68196a45 = '\x01';
    _DAT_681975a0 = media_invokeCallback;
    _DAT_681975a4 = media_addRef;
    _DAT_681975a8 = globals_release;
    _DAT_681975ac = globals_dispatchGetProperty;
    _DAT_681975b0 = globals_dispatchGetCount;
    _DAT_681975b4 = globals_dispatchGetSymbol;
    _DAT_681975b8 = globals_dispatchGetInt;
    _DAT_681975bc = globals_dispatchGetBool;
    _DAT_681975c0 = globals_dispatchGetString;
    _DAT_681975c4 = globals_dispatchGetFloat;
    _DAT_681975c8 = globals_dispatchGetPairByIndex;
    _DAT_681975cc = globals_dispatchGetPair;
    _DAT_681975d0 = globals_dispatchSetSymbol;
    _DAT_681975d4 = globals_dispatchSetBool;
    _DAT_681975d8 = globals_dispatchSetFloat;
    _DAT_681975dc = globals_dispatchSetString;
    _DAT_681975e0 = globals_dispatchSetInt;
    _DAT_681975e4 = globals_dispatchSetProperty;
    _DAT_681975e8 = globals_dispatchGetRef;
    _DAT_681975ec = globals_dispatchDelete;
    _DAT_681975f0 = globals_dispatchCreate;
    _DAT_681975f4 = globals_dispatchGetName;
    _DAT_681975f8 = globals_dispatchGetHandlerCount;
    _DAT_681975fc = globals_dispatchCallMethod;
    _DAT_68197600 = globals_dispatchCount;
  }
  return &DAT_681975a0;
}



// ============================================================
// Function: globals_initPairVtable (FUN_681714c0)
// Address: 681714c0
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initPairVtable(void)

{
  if (DAT_68196a46 == '\0') {
    DAT_68196a46 = '\x01';
    _DAT_681973c0 = media_invokeCallback;
    _DAT_681973c4 = media_addRef;
    _DAT_681973c8 = globals_release;
    _DAT_681973cc = strings_wrapComputeValue;
    _DAT_681973d0 = strings_wrapConvertDate;
  }
  return &DAT_681973c0;
}



// ============================================================
// Function: globals_initAccessorVtable (FUN_68171510)
// Address: 68171510
// Size: 156 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initAccessorVtable(void)

{
  if (DAT_68196a47 == '\0') {
    DAT_68196a47 = '\x01';
    _DAT_68197400 = media_invokeCallback;
    _DAT_68197404 = media_addRef;
    _DAT_68197408 = globals_release;
    _DAT_6819740c = strings_wrapPopScoreSlot;
    _DAT_68197410 = strings_wrapGetScoreContext;
    _DAT_68197414 = strings_wrapSetScoreContext;
    _DAT_68197418 = strings_wrapGetListEntry;
    _DAT_6819741c = strings_wrapSetListEntry;
    _DAT_68197420 = strings_wrapGetListCount;
    _DAT_68197424 = strings_wrapAppendListEntry;
    _DAT_68197428 = strings_wrapInsertListEntry;
    _DAT_6819742c = strings_wrapDeleteListEntry;
    _DAT_68197430 = strings_wrapFindListEntry;
  }
  return &DAT_68197400;
}



// ============================================================
// Function: globals_release (FUN_681715b0)
// Address: 681715b0
// Size: 71 bytes
// Params: int param_1
// Return: LONG
// Calling convention: __stdcall
// ============================================================

LONG globals_release(int param_1)

{
  int *piVar1;
  LONG LVar2;

  LVar2 = InterlockedDecrement((LONG *)(param_1 + 8));
  piVar1 = *(int **)(param_1 + 4);
  if (LVar2 == 0) {
    (**(code **)(*(int *)piVar1[3] + 0x10))((int *)piVar1[3],param_1);
    DAT_6819639c = DAT_6819639c + -1;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*piVar1 + 8))(piVar1);
  return LVar2;
}



// ============================================================
// Function: globals_initReadWriteVtable (FUN_68171600)
// Address: 68171600
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initReadWriteVtable(void)

{
  if (DAT_68196a48 == '\0') {
    DAT_68196a48 = '\x01';
    _DAT_681974e0 = media_invokeCallback;
    _DAT_681974e4 = media_addRef;
    _DAT_681974e8 = globals_release;
    _DAT_681974ec = strings_wrapSortList;
    _DAT_681974f0 = strings_wrapGetListProperty;
  }
  return &DAT_681974e0;
}



// ============================================================
// Function: globals_initMediaDispatchVtable (FUN_68171650)
// Address: 68171650
// Size: 82 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initMediaDispatchVtable(void)

{
  if (DAT_68196a49 == '\0') {
    DAT_68196a49 = '\x01';
    _DAT_681974c0 = media_invokeCallback;
    _DAT_681974c4 = media_addRef;
    _DAT_681974c8 = globals_release;
    _DAT_681974cc = strings_wrapSetListProperty;
    _DAT_681974d0 = strings_wrapGetPropListEntry;
    _DAT_681974d4 = globals_dispatchMediaValue;
  }
  return &DAT_681974c0;
}



// ============================================================
// Function: globals_initVectorVtable (FUN_681716b0)
// Address: 681716b0
// Size: 156 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initVectorVtable(void)

{
  if (DAT_68196a4a == '\0') {
    DAT_68196a4a = '\x01';
    _DAT_68197480 = media_invokeCallback;
    _DAT_68197484 = media_addRef;
    _DAT_68197488 = globals_release;
    _DAT_6819748c = globals_dispatchExtractVector;
    _DAT_68197490 = globals_dispatchStoreVector;
    _DAT_68197494 = globals_dispatchGetVectorPtr;
    _DAT_68197498 = globals_dispatchReleaseVector;
    _DAT_6819749c = globals_dispatchGetVectorRef;
    _DAT_681974a0 = globals_dispatchSetVectorProp;
    _DAT_681974a4 = globals_dispatchRegisterVector;
    _DAT_681974a8 = globals_dispatchReset;
    _DAT_681974ac = globals_dispatchReset;
    _DAT_681974b0 = globals_dispatchDestroyVector;
  }
  return &DAT_68197480;
}



// ============================================================
// Function: globals_initExtPropertyVtable (FUN_68171750)
// Address: 68171750
// Size: 296 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * globals_initExtPropertyVtable(void)

{
  if (DAT_68196a4b == '\0') {
    DAT_68196a4b = '\x01';
    _DAT_68197300 = media_invokeCallback;
    _DAT_68197304 = media_addRef;
    _DAT_68197308 = globals_release;
    _DAT_6819730c = globals_dispatchGetProperty;
    _DAT_68197310 = globals_dispatchGetCount;
    _DAT_68197314 = globals_dispatchGetSymbol;
    _DAT_68197318 = globals_dispatchGetInt;
    _DAT_6819731c = globals_dispatchGetBool;
    _DAT_68197320 = globals_dispatchGetString;
    _DAT_68197324 = globals_dispatchGetFloat;
    _DAT_68197328 = globals_dispatchGetPairByIndex;
    _DAT_6819732c = globals_dispatchGetPair;
    _DAT_68197330 = globals_dispatchSetSymbol;
    _DAT_68197334 = globals_dispatchSetBool;
    _DAT_68197338 = globals_dispatchSetFloat;
    _DAT_6819733c = globals_dispatchSetString;
    _DAT_68197340 = globals_dispatchSetInt;
    _DAT_68197344 = globals_dispatchSetProperty;
    _DAT_68197348 = globals_dispatchGetRef;
    _DAT_6819734c = globals_dispatchDelete;
    _DAT_68197350 = globals_dispatchCreate;
    _DAT_68197354 = globals_dispatchGetName;
    _DAT_68197358 = globals_dispatchGetHandlerCount;
    _DAT_6819735c = globals_dispatchCallMethod;
    _DAT_68197360 = globals_dispatchCount;
    _DAT_68197364 = globals_dispatchSetMethod;
    _DAT_68197368 = globals_dispatchNoop;
  }
  return &DAT_68197300;
}



// ============================================================
// Function: globals_createFullObject (FUN_68171880)
// Address: 68171880
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createFullObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initFullVtable();
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
// Function: globals_createStreamObject (FUN_681718e0)
// Address: 681718e0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createStreamObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initStreamVtable();
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
// Function: globals_createMediaObject (FUN_68171940)
// Address: 68171940
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createMediaObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initMediaVtable();
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
// Function: globals_createHandlerObject (FUN_681719a0)
// Address: 681719a0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createHandlerObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initHandlerVtable();
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
// Function: globals_createBuildInfoObject (FUN_68171a00)
// Address: 68171a00
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createBuildInfoObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initBuildInfoVtable();
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
// Function: globals_createDialogObject (FUN_68171a60)
// Address: 68171a60
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createDialogObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initDialogVtable();
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
// Function: globals_createTimerObject (FUN_68171ac0)
// Address: 68171ac0
// Size: 90 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int globals_createTimerObject(int *param_1,undefined4 *param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int local_8;

  piVar2 = &local_8;
  local_8 = 0;
  puVar1 = globals_initTimerVtable();
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


