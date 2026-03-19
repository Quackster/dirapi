// Module: globals
// Topic: Lingo global property getter/setter dispatch wrappers
// Address range: 0x68170030 - 0x68170CD0
// Functions (34):
//   globals_dispatchMediaValue
//   globals_dispatchExtractVector
//   globals_dispatchStoreVector
//   globals_dispatchSetVectorProp
//   globals_dispatchRegisterVector
//   globals_dispatchGetVectorPtr
//   globals_dispatchReleaseVector
//   globals_dispatchReset
//   globals_dispatchGetVectorRef
//   globals_dispatchDestroyVector
//   globals_dispatchGetProperty
//   globals_dispatchGetCount
//   globals_dispatchGetSymbol
//   globals_dispatchGetInt
//   globals_dispatchGetBool
//   globals_dispatchGetString
//   globals_dispatchGetFloat
//   globals_dispatchGetPairByIndex
//   globals_dispatchGetPair
//   globals_dispatchSetSymbol
//   globals_dispatchSetBool
//   globals_dispatchSetFloat
//   globals_dispatchSetString
//   globals_dispatchSetInt
//   globals_dispatchSetProperty
//   globals_dispatchGetRef
//   globals_dispatchDelete
//   globals_dispatchCreate
//   globals_dispatchGetName
//   globals_dispatchGetHandlerCount
//   globals_dispatchCount
//   globals_dispatchCallMethod
//   globals_dispatchSetMethod
//   globals_dispatchNoop

// ============================================================
// Function: globals_dispatchMediaValue (FUN_68170030)
// Address: 68170030
// Size: 51 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchMediaValue(undefined4 param_1,int *param_2)
{
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  score_dispatchMediaValue(local_8,param_2);
  return 0;
}



// ============================================================
// Function: globals_dispatchExtractVector (FUN_68170070)
// Address: 68170070
// Size: 60 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_dispatchExtractVector(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = cast_extractVectorData(local_8,param_2,param_3);
  uVar2 = 0x800407f5;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: globals_dispatchStoreVector (FUN_681700b0)
// Address: 681700b0
// Size: 57 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_dispatchStoreVector(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  cast_storeVectorValue(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: globals_dispatchSetVectorProp (FUN_681700f0)
// Address: 681700f0
// Size: 60 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_dispatchSetVectorProp(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = cast_setMediaVectorProp(local_8,param_2,param_3);
  uVar2 = 0x800407f6;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: globals_dispatchRegisterVector (FUN_68170130)
// Address: 68170130
// Size: 57 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_dispatchRegisterVector(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  cast_registerVectorMedia(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: globals_dispatchGetVectorPtr (FUN_68170170)
// Address: 68170170
// Size: 60 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_dispatchGetVectorPtr(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = cast_getVectorPointer(local_8,param_2,param_3);
  uVar2 = 0x800407f5;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: globals_dispatchReleaseVector (FUN_681701b0)
// Address: 681701b0
// Size: 60 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_dispatchReleaseVector(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = cast_releaseVector(local_8,param_2,param_3);
  uVar2 = 0x800407f5;
  if (iVar1 != 0) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: globals_dispatchReset (FUN_681701f0)
// Address: 681701f0
// Size: 43 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_dispatchReset(void)

{
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  return 0x800407d0;
}



// ============================================================
// Function: globals_dispatchGetVectorRef (FUN_68170220)
// Address: 68170220
// Size: 51 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetVectorRef(undefined4 param_1,int *param_2)
{
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  cast_getVectorRef(local_8,param_2);
  return 0;
}



// ============================================================
// Function: globals_dispatchDestroyVector (FUN_68170260)
// Address: 68170260
// Size: 51 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchDestroyVector(undefined4 param_1,int *param_2)
{
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  cast_destroyMediaVector(local_8,param_2);
  return 0;
}



// ============================================================
// Function: globals_dispatchGetProperty (FUN_681702a0)
// Address: 681702a0
// Size: 165 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5, undefined4 * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetProperty(undefined4 param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5,undefined4 *param_6)
{
  uint uVar1;
  int local_34;
  uint local_30;
  uint local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_34 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_34,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_30 = *param_2;
  local_2c = param_2[1];
  local_28 = *param_3;
  local_24 = param_3[1];
  local_20 = *param_4;
  local_1c = param_4[1];
  local_18 = *param_5;
  local_14 = param_5[1];
  uVar1 = 4;
  if (param_6 != (undefined4 *)0x0) {
    local_10 = *param_6;
    local_c = param_6[1];
    uVar1 = 5;
  }
  score_getPropertyPair(local_34,0x387,uVar1,&local_30,(int *)0x0);
  return 0;
}



// ============================================================
// Function: globals_dispatchGetCount (FUN_68170350)
// Address: 68170350
// Size: 78 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetCount(undefined4 param_1,uint *param_2,int *param_3)
{
  uint local_10;
  uint local_c;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_10 = *param_2;
  local_c = param_2[1];
  score_getPropertyPair(local_8,0xe4,1,&local_10,param_3);
  return 0;
}



// ============================================================
// Function: globals_dispatchGetSymbol (FUN_681703a0)
// Address: 681703a0
// Size: 92 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetSymbol(undefined4 param_1,uint *param_2,undefined4 *param_3,int *param_4)
{
  uint local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_18 = *param_2;
  local_14 = param_2[1];
  local_10 = *param_3;
  local_c = param_3[1];
  score_getPropertyPair(local_8,0x244,2,&local_18,param_4);
  return 0;
}



// ============================================================
// Function: globals_dispatchGetInt (FUN_68170400)
// Address: 68170400
// Size: 125 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 param_3, undefined4 param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetInt(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4,
                 int *param_5)
{
  int local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_24 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = 4;
  local_10 = 4;
  local_14 = param_3;
  local_c = param_4;
  score_getPropertyPair(local_24,0x36f,3,&local_20,param_5);
  return 0;
}



// ============================================================
// Function: globals_dispatchGetBool (FUN_68170480)
// Address: 68170480
// Size: 136 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetBool(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)
{
  int local_2c;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_2c = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_2c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_28 = *param_2;
  local_24 = param_2[1];
  local_1c = param_3;
  local_10 = *param_5;
  local_14 = param_4;
  local_c = param_5[1];
  local_20 = 4;
  local_18 = 4;
  score_getPropertyPair(local_2c,0x370,4,&local_28,(int *)0x0);
  return 0;
}



// ============================================================
// Function: globals_dispatchGetString (FUN_68170510)
// Address: 68170510
// Size: 150 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetString(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 *param_5)
{
  int local_34;
  undefined4 local_30;
  int local_2c;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_2c = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_2c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_28 = *param_2;
  local_24 = param_2[1];
  local_1c = param_3;
  local_14 = param_4;
  local_20 = 4;
  local_18 = 4;
  local_10 = 8;
  local_c = 0x95;
  score_getPropertyPair(local_2c,0x36f,4,&local_28,&local_34);
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = local_30;
  }
  return 0;
}



// ============================================================
// Function: globals_dispatchGetFloat (FUN_681705b0)
// Address: 681705b0
// Size: 129 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetFloat(undefined4 param_1,uint *param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)
{
  int local_2c;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_2c = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_2c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_24 = param_2[1];
  local_28 = *param_2;
  local_14 = param_4;
  local_20 = 4;
  local_18 = 4;
  local_10 = 4;
  local_1c = param_3;
  local_c = param_5;
  score_getPropertyPair(local_2c,0x370,4,&local_28,(int *)0x0);
  return 0;
}



// ============================================================
// Function: globals_dispatchGetPairByIndex (FUN_68170640)
// Address: 68170640
// Size: 137 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetPairByIndex(undefined4 param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)
{
  uint uVar1;
  int local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_24 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = *param_3;
  local_14 = param_3[1];
  uVar1 = 2;
  if (param_4 != (undefined4 *)0x0) {
    local_10 = *param_4;
    local_c = param_4[1];
    uVar1 = 3;
  }
  score_getPropertyPair(local_24,0x38d,uVar1,&local_20,(int *)0x0);
  return 0;
}



// ============================================================
// Function: globals_dispatchGetPair (FUN_681706d0)
// Address: 681706d0
// Size: 137 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetPair(undefined4 param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)
{
  uint uVar1;
  int local_24;
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_24 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_24,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = *param_3;
  local_14 = param_3[1];
  uVar1 = 2;
  if (param_4 != (undefined4 *)0x0) {
    local_10 = *param_4;
    local_c = param_4[1];
    uVar1 = 3;
  }
  score_getPropertyPair(local_24,0x388,uVar1,&local_20,(int *)0x0);
  return 0;
}



// ============================================================
// Function: globals_dispatchSetSymbol (FUN_68170760)
// Address: 68170760
// Size: 78 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchSetSymbol(undefined4 param_1,uint *param_2,int *param_3)
{
  uint local_10;
  uint local_c;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_10 = *param_2;
  local_c = param_2[1];
  score_getPropertyPair(local_8,0x389,1,&local_10,param_3);
  return 0;
}



// ============================================================
// Function: globals_dispatchSetBool (FUN_681707b0)
// Address: 681707b0
// Size: 78 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchSetBool(undefined4 param_1,uint *param_2,int *param_3)
{
  uint local_10;
  uint local_c;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_10 = *param_2;
  local_c = param_2[1];
  score_getPropertyPair(local_8,0x3b4,1,&local_10,param_3);
  return 0;
}



// ============================================================
// Function: globals_dispatchSetFloat (FUN_68170800)
// Address: 68170800
// Size: 78 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchSetFloat(undefined4 param_1,uint *param_2,int *param_3)
{
  uint local_10;
  uint local_c;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_10 = *param_2;
  local_c = param_2[1];
  score_getPropertyPair(local_8,0x38a,1,&local_10,param_3);
  return 0;
}



// ============================================================
// Function: globals_dispatchSetString (FUN_68170850)
// Address: 68170850
// Size: 90 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchSetString(undefined4 param_1,uint *param_2,undefined4 *param_3)
{
  uint local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_18 = *param_2;
  local_14 = param_2[1];
  local_10 = *param_3;
  local_c = param_3[1];
  score_getPropertyPair(local_8,0x38c,2,&local_18,(int *)0x0);
  return 0;
}



// ============================================================
// Function: globals_dispatchSetInt (FUN_681708b0)
// Address: 681708b0
// Size: 78 bytes
// Params: undefined4 param_1, uint * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchSetInt(undefined4 param_1,uint *param_2,int *param_3)
{
  uint local_10;
  uint local_c;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_10 = *param_2;
  local_c = param_2[1];
  score_getPropertyPair(local_8,0x38b,1,&local_10,param_3);
  return 0;
}



// ============================================================
// Function: globals_dispatchSetProperty (FUN_68170900)
// Address: 68170900
// Size: 149 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 * param_6, int * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchSetProperty(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5,undefined4 *param_6,int *param_7)
{
  uint uVar1;
  int local_34 [3];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_34[0] = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,local_34,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  local_34[2] = param_2;
  uVar1 = 4;
  local_1c = param_4;
  local_24 = param_3;
  local_34[1] = 4;
  local_28 = 4;
  local_20 = 4;
  local_18 = 4;
  local_14 = param_5;
  if (param_6 != (undefined4 *)0x0) {
    local_10 = *param_6;
    local_c = param_6[1];
    uVar1 = 5;
  }
  score_getPropertyPair(local_34[0],0x291,uVar1,(uint *)(local_34 + 1),param_7);
  return 0;
}



// ============================================================
// Function: globals_dispatchGetRef (FUN_681709a0)
// Address: 681709a0
// Size: 55 bytes
// Params: undefined4 param_1, void * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchGetRef(undefined4 param_1,void *param_2,undefined4 *param_3)
{
  void *local_8;

  local_8 = (void *)0x0;
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  cast_acquireXtraBitmap(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: globals_dispatchDelete (FUN_681709e0)
// Address: 681709e0
// Size: 51 bytes
// Params: undefined4 param_1, void * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchDelete(undefined4 param_1,void *param_2)
{
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  cast_releaseXtraBitmap(local_8,param_2);
  return 0;
}



// ============================================================
// Function: globals_dispatchCreate (FUN_68170a20)
// Address: 68170a20
// Size: 113 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_dispatchCreate(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  undefined4 local_8;

  local_8 = 0;
  local_c = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  iVar1 = Ordinal_1405(&local_8,param_2,1,0);
  if (iVar1 != 0) {
    uVar2 = cast_createFromPalette(local_c,local_8);
    Ordinal_1407(&local_8);
    return uVar2;
  }
  return 0x80040014;
}



// ============================================================
// Function: globals_dispatchGetName (FUN_68170aa0)
// Address: 68170aa0
// Size: 43 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_dispatchGetName(void)

{
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  return 0x80004001;
}



// ============================================================
// Function: globals_dispatchGetHandlerCount (FUN_68170ad0)
// Address: 68170ad0
// Size: 43 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 globals_dispatchGetHandlerCount(void)

{
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  return 0x80004001;
}



// ============================================================
// Function: globals_dispatchCount (FUN_68170b00)
// Address: 68170b00
// Size: 180 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int globals_dispatchCount(undefined4 param_1,int *param_2)
{
  int iVar1;
  int local_202c;
  undefined1 local_2028 [4124];
  undefined1 local_100c [4100];
  uint local_8;

  local_202c = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_202c,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  iVar1 = (**(code **)(*param_2 + 0x4c))(param_2,local_100c,0x1002);
  if (iVar1 == 0) {
    iVar1 = Ordinal_1309(local_2028,0x1002,local_100c,2);
    if (iVar1 == 0) {
      return 0;
    }
    cast_createFromFile(local_202c,local_2028);
  }
  return 0;
}



// ============================================================
// Function: globals_dispatchCallMethod (FUN_68170bc0)
// Address: 68170bc0
// Size: 55 bytes
// Params: undefined4 param_1, void * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchCallMethod(undefined4 param_1,void *param_2,undefined4 *param_3)
{
  void *local_8;

  local_8 = (void *)0x0;
  lingo_resolveContext((int *)0x0,(int *)0x0,(int *)&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  cast_getXtraBitmapInfo(local_8,param_2,param_3);
  return 0;
}



// ============================================================
// Function: globals_dispatchSetMethod (FUN_68170c00)
// Address: 68170c00
// Size: 199 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4, int param_5, undefined4 * param_6, byte param_7, int * param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchSetMethod(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,
                 undefined4 *param_6,byte param_7,int *param_8)
{
  uint uVar1;
  int local_34 [3];
  undefined4 local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;

  local_34[0] = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,local_34,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  if ((param_7 & 1) != 0) {
    if ((param_4 == 0x20) && (param_5 == 8)) {
      cast_createBlankBitmap(local_34[0],param_2,param_3,param_8);
    }
    return 0;
  }
  local_34[2] = param_2;
  uVar1 = 4;
  local_1c = param_4;
  local_24 = param_3;
  local_34[1] = 4;
  local_28 = 4;
  local_20 = 4;
  local_18 = 4;
  local_14 = param_5;
  if (param_6 != (undefined4 *)0x0) {
    local_10 = *param_6;
    local_c = param_6[1];
    uVar1 = 5;
  }
  score_getPropertyPair(local_34[0],0x291,uVar1,(uint *)(local_34 + 1),param_8);
  return 0;
}



// ============================================================
// Function: globals_dispatchNoop (FUN_68170cd0)
// Address: 68170cd0
// Size: 55 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int globals_dispatchNoop(void)
{
  int param_4;
  int local_8;

  local_8 = 0;
  lingo_resolveContext((int *)0x0,(int *)0x0,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  core_returnZeroStub();
  return 0;
}


