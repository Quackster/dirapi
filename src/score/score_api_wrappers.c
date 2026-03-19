// Module: score
// Topic: External API wrappers (value get/set/call)
// Address range: 0x6804a980 - 0x6804b280
// Functions (43):
//   score_setPropertyAndDispatch
//   score_wrapFormatValue1
//   score_wrapFormatValue2
//   score_wrapFormatValue3
//   score_wrapFormatValue4
//   score_wrapFormatValue5
//   score_resolveSymbolByName
//   score_getSymbolStringNext
//   score_getSymbolString
//   score_getValueType
//   score_retainValueWithCallback
//   score_releaseValue
//   score_coerceToInt
//   score_coerceToFloat
//   score_coerceToDouble
//   score_getComponentCount
//   score_coerceToStringNext
//   score_coerceToString
//   score_getApiContext
//   score_getApiState
//   score_getContextState
//   score_createRect
//   score_storeIntValue
//   score_storeObjectRef
//   score_storeFloatDirect
//   score_loadStringValue
//   score_getExtPair
//   score_coerceAndStore
//   score_storeFloatValue
//   score_computeValue
//   score_convertDateToTime
//   score_storeSymbolRef
//   score_queryInterface
//   score_getPropertyIndexBA
//   score_dispatchMethodByCE
//   score_resolveRefByDD
//   score_validateBounds
//   score_callMethodByD3
//   score_callMethodChecked
//   score_storeByIndexDA
//   score_getPropertyIndexBB
//   score_dispatchTripleByCD
//   score_getPropertyByD4

// ============================================================
// Function: score_setPropertyAndDispatch (FUN_6804a980)
// Address: 6804a980
// Size: 111 bytes
// Params: uint param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_setPropertyAndDispatch(uint param_1,uint param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  uint *puVar3;
  uint local_c;
  uint local_8;
  
  local_c = *param_3;
  local_8 = param_3[1];
  props_retainValue(param_1,&local_c);
  puVar3 = score_lookupProperty(*(int **)(**(int **)(param_1 + 8) + 0x4e4),param_2,1,(uint *)0x0);
  if (puVar3 != (uint *)0x0) {
    piVar1 = (int *)puVar3[1];
    uVar2 = *puVar3;
    *puVar3 = local_c;
    puVar3[1] = local_8;
    props_releaseValue(param_1,(byte)uVar2,piVar1);
  }
  core_dispatchAsync(param_1,param_2,&local_c);
  return 0;
}


// ============================================================
// Function: score_wrapFormatValue1 (FUN_6804a9f0)
// Address: 6804a9f0
// Size: 25 bytes
// Params: int param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_wrapFormatValue1(int param_1,byte *param_2)

{
  props_formatValue(param_1,param_2);
  return 0;
}


// ============================================================
// Function: score_wrapFormatValue2 (FUN_6804aa10)
// Address: 6804aa10
// Size: 29 bytes
// Params: int param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_wrapFormatValue2(int param_1,byte *param_2)

{
  props_formatValue(param_1,param_2);
  return 0;
}


// ============================================================
// Function: score_wrapFormatValue3 (FUN_6804aa30)
// Address: 6804aa30
// Size: 33 bytes
// Params: int param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_wrapFormatValue3(int param_1,byte *param_2)

{
  props_formatValue(param_1,param_2);
  return 0;
}


// ============================================================
// Function: score_wrapFormatValue4 (FUN_6804aa60)
// Address: 6804aa60
// Size: 37 bytes
// Params: int param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_wrapFormatValue4(int param_1,byte *param_2)

{
  props_formatValue(param_1,param_2);
  return 0;
}


// ============================================================
// Function: score_wrapFormatValue5 (FUN_6804aa90)
// Address: 6804aa90
// Size: 41 bytes
// Params: int param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_wrapFormatValue5(int param_1,byte *param_2)

{
  props_formatValue(param_1,param_2);
  return 0;
}


// ============================================================
// Function: score_resolveSymbolByName (FUN_6804aac0)
// Address: 6804aac0
// Size: 84 bytes
// Params: int param_1, char * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_resolveSymbolByName(int param_1,char *param_2,int *param_3)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  if (param_1 == 0) {
    *param_3 = -1;
    return 0x80040001;
  }
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = props_lookupSymbol(param_1,param_2,(int)pcVar2 - (int)(param_2 + 1));
  *param_3 = iVar3;
  if (iVar3 == -1) {
    return 0x80040001;
  }
  return 0;
}


// ============================================================
// Function: score_getSymbolStringNext (FUN_6804ab20)
// Address: 6804ab20
// Size: 27 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getSymbolStringNext(undefined4 param_1,int param_2,int param_3,int param_4)

{
  props_getSymbolString(param_2,param_3,param_4 + 1);
  return 0;
}


// ============================================================
// Function: score_getSymbolString (FUN_6804ab40)
// Address: 6804ab40
// Size: 26 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getSymbolString(undefined4 param_1,int param_2,int param_3,int param_4)

{
  props_getSymbolString(param_2,param_3,param_4);
  return 0;
}


// ============================================================
// Function: score_getValueType (FUN_6804ab60)
// Address: 6804ab60
// Size: 9 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getValueType(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  props_mapTypeCode(param_1,param_2,param_3);
  return 0;
}


// ============================================================
// Function: score_retainValueWithCallback (FUN_6804ab70)
// Address: 6804ab70
// Size: 61 bytes
// Params: int param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_retainValueWithCallback(int param_1,uint *param_2)

{
  undefined4 uVar1;
  
  uVar1 = props_retainValueCallback(param_1,param_2);
  if (*param_2 == 3) {
    (**(code **)(**(int **)param_2[1] + 0x30))
              (param_1,(undefined4 *)param_2[1],**(int **)(param_1 + 8) + 0x558);
  }
  return uVar1;
}


// ============================================================
// Function: score_releaseValue (FUN_6804abb0)
// Address: 6804abb0
// Size: 9 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_releaseValue(undefined4 param_1,int *param_2)
{
  props_releaseAndClear(param_1,param_2);
  return 0;
}


// ============================================================
// Function: score_coerceToInt (FUN_6804abc0)
// Address: 6804abc0
// Size: 36 bytes
// Params: int param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_coerceToInt(int param_1,uint *param_2,int *param_3)

{
  undefined4 extraout_EDX;
  
  props_coerceAndReturnInt(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_coerceToFloat (FUN_6804abf0)
// Address: 6804abf0
// Size: 36 bytes
// Params: int param_1, uint * param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_coerceToFloat(int param_1,uint *param_2,uint *param_3)

{
  undefined4 extraout_EDX;
  
  props_coerceAndReturnFloat(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_coerceToDouble (FUN_6804ac20)
// Address: 6804ac20
// Size: 36 bytes
// Params: int param_1, uint * param_2, double * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_coerceToDouble(int param_1,uint *param_2,double *param_3)

{
  undefined4 extraout_EDX;
  
  props_coerceAndReturnDouble(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_getComponentCount (FUN_6804ac50)
// Address: 6804ac50
// Size: 36 bytes
// Params: int param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getComponentCount(int param_1,uint *param_2,int *param_3)

{
  undefined4 extraout_EDX;
  
  props_getStringCharCount(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_coerceToStringNext (FUN_6804ac80)
// Address: 6804ac80
// Size: 41 bytes
// Params: int param_1, uint * param_2, undefined1 * param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_coerceToStringNext(int param_1,uint *param_2,undefined1 *param_3,int param_4)

{
  undefined4 extraout_EDX;
  
  props_coerceAndReturnString(param_1,param_2,param_3,param_4 + 1);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_coerceToString (FUN_6804acb0)
// Address: 6804acb0
// Size: 40 bytes
// Params: int param_1, uint * param_2, undefined1 * param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_coerceToString(int param_1,uint *param_2,undefined1 *param_3,int param_4)

{
  undefined4 extraout_EDX;
  
  props_coerceAndReturnString(param_1,param_2,param_3,param_4);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_getApiContext (FUN_6804ace0)
// Address: 6804ace0
// Size: 70 bytes
// Params: int param_1, uint * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getApiContext(int param_1,uint *param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  
  piVar1 = props_getApiContext((int *)param_2);
  *param_3 = piVar1;
  if (piVar1 != (int *)0x0) {
    score_resetPropertyCache(param_1);
    return extraout_EDX;
  }
  props_returnWithValue(param_1,0x800407dc,param_2);
  score_resetPropertyCache(param_1);
  return extraout_EDX_00;
}


// ============================================================
// Function: score_getApiState (FUN_6804ad30)
// Address: 6804ad30
// Size: 29 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getApiState(int param_1,int *param_2)

{
  undefined4 extraout_EDX;
  
  props_getApiState(param_2);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_getContextState (FUN_6804ad50)
// Address: 6804ad50
// Size: 36 bytes
// Params: int param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getContextState(int param_1,uint *param_2)

{
  undefined4 extraout_EDX;
  
  props_getContextState(param_1,param_2);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_createRect (FUN_6804ad80)
// Address: 6804ad80
// Size: 36 bytes
// Params: int param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_createRect(int param_1,uint *param_2)

{
  undefined4 extraout_EDX;
  
  props_createRectFromValue(param_1,param_2);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_storeIntValue (FUN_6804adb0)
// Address: 6804adb0
// Size: 36 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_storeIntValue(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 extraout_EDX;
  
  props_storeIntValue(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_storeObjectRef (FUN_6804ade0)
// Address: 6804ade0
// Size: 36 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_storeObjectRef(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 extraout_EDX;
  
  props_storeObjectRef(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_storeFloatDirect (FUN_6804ae10)
// Address: 6804ae10
// Size: 41 bytes
// Params: int param_1, double param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_storeFloatDirect(int param_1,double param_2,int *param_3)

{
  undefined4 extraout_EDX;
  
  props_storeFloatDirect(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_loadStringValue (FUN_6804ae40)
// Address: 6804ae40
// Size: 36 bytes
// Params: int param_1, char * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_loadStringValue(int param_1,char *param_2,undefined4 *param_3)

{
  undefined4 extraout_EDX;
  
  props_loadStringValue(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_getExtPair (FUN_6804ae70)
// Address: 6804ae70
// Size: 36 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getExtPair(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 extraout_EDX;
  
  props_getExtPair(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_coerceAndStore (FUN_6804aea0)
// Address: 6804aea0
// Size: 36 bytes
// Params: int param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_coerceAndStore(int param_1,uint *param_2,int *param_3)

{
  undefined4 extraout_EDX;
  
  props_coerceAndStore(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_storeFloatValue (FUN_6804aed0)
// Address: 6804aed0
// Size: 36 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_storeFloatValue(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 extraout_EDX;
  
  props_storeFloatValue(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_computeValue (FUN_6804af00)
// Address: 6804af00
// Size: 40 bytes
// Params: int param_1, uint param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_computeValue(int param_1,uint param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 extraout_EDX;
  
  props_convertTimestampToDate(param_3,param_2,param_1,param_2,param_3,param_4);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_convertDateToTime (FUN_6804af30)
// Address: 6804af30
// Size: 36 bytes
// Params: int param_1, uint * param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_convertDateToTime(int param_1,uint *param_2,uint *param_3)

{
  undefined4 extraout_EDX;
  
  props_convertDateToTimestamp(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_storeSymbolRef (FUN_6804af60)
// Address: 6804af60
// Size: 36 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_storeSymbolRef(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 extraout_EDX;
  
  props_storeSymbolRef(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_queryInterface (FUN_6804af90)
// Address: 6804af90
// Size: 36 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_queryInterface(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 extraout_EDX;
  
  props_storeRectOp(param_1,param_2,param_3);
  score_resetPropertyCache(param_1);
  return extraout_EDX;
}


// ============================================================
// Function: score_getPropertyIndexBA (FUN_6804afc0)
// Address: 6804afc0
// Size: 53 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getPropertyIndexBA(undefined4 param_1,int *param_2)
{
  uint local_c [2];
  
  local_c[0] = 2;
  local_c[1] = 0;
  score_getPropertyByIndex(0xba,0,local_c,param_2,1);
  return 0;
}


// ============================================================
// Function: score_dispatchMethodByCE (FUN_6804b000)
// Address: 6804b000
// Size: 65 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispatchMethodByCE(undefined4 param_1,uint *param_2,undefined4 *param_3)
{
  uint local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = *param_2;
  local_10 = param_2[1];
  local_c = *param_3;
  local_8 = param_3[1];
  score_getPropertyByIndex(0xce,2,&local_14,(int *)0x0,0);
  return 0;
}


// ============================================================
// Function: score_resolveRefByDD (FUN_6804b050)
// Address: 6804b050
// Size: 84 bytes
// Params: undefined4 param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_resolveRefByDD(undefined4 param_1,uint *param_2)

{
  int iVar1;
  int local_14;
  undefined4 local_10;
  uint local_c;
  uint local_8;
  
  local_c = *param_2;
  local_8 = param_2[1];
  iVar1 = score_getPropertyByIndex(0xdd,1,&local_c,&local_14,0);
  if (iVar1 == 0) {
    props_releaseAndClear(param_1,&local_14);
    return local_10;
  }
  return 0xffffffff;
}


// ============================================================
// Function: score_validateBounds (FUN_6804b0b0)
// Address: 6804b0b0
// Size: 25 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall score_validateBounds(undefined4 param_1)

{
  uint *in_EAX;
  int iVar1;
  int unaff_ESI;
  
  if (0 < unaff_ESI) {
    iVar1 = score_resolveRefByDD(param_1,in_EAX);
    if (unaff_ESI <= iVar1) {
      return 0;
    }
  }
  return 0x800407d8;
}


// ============================================================
// Function: score_callMethodByD3 (FUN_6804b0d0)
// Address: 6804b0d0
// Size: 66 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_callMethodByD3(undefined4 param_1,uint *param_2,undefined4 param_3,int *param_4)
{
  uint local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_14 = *param_2;
  local_10 = param_2[1];
  local_c = 4;
  local_8 = param_3;
  score_getPropertyByIndex(0xd3,2,&local_14,param_4,0);
  return 0;
}


// ============================================================
// Function: score_callMethodChecked (FUN_6804b120)
// Address: 6804b120
// Size: 47 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_callMethodChecked(undefined4 param_1,uint *param_2,undefined4 param_3,int *param_4)
{
  int iVar1;
  
  iVar1 = score_validateBounds(param_1);
  if (iVar1 == 0) {
    score_callMethodByD3(param_1,param_2,param_3,param_4);
  }
  return 0;
}


// ============================================================
// Function: score_storeByIndexDA (FUN_6804b150)
// Address: 6804b150
// Size: 127 bytes
// Params: undefined4 param_1, uint * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_storeByIndexDA(undefined4 param_1,uint *param_2,int param_3,undefined4 *param_4)
{
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_3 < 1) {
    return 0;
  }
  local_20 = *param_2;
  local_1c = param_2[1];
  local_c = param_4[1];
  local_14 = param_3;
  local_10 = *param_4;
  local_18 = 4;
  score_getPropertyByIndex(0xda,3,&local_20,(int *)0x0,0);
  return 0;
}


// ============================================================
// Function: score_getPropertyIndexBB (FUN_6804b1d0)
// Address: 6804b1d0
// Size: 53 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getPropertyIndexBB(undefined4 param_1,int *param_2)
{
  uint local_c [2];
  
  local_c[0] = 2;
  local_c[1] = 0;
  score_getPropertyByIndex(0xbb,0,local_c,param_2,1);
  return 0;
}


// ============================================================
// Function: score_dispatchTripleByCD (FUN_6804b210)
// Address: 6804b210
// Size: 101 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispatchTripleByCD(undefined4 param_1,uint *param_2,undefined4 *param_3,undefined4 *param_4)
{
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = *param_3;
  local_14 = param_3[1];
  local_10 = *param_4;
  local_c = param_4[1];
  score_getPropertyByIndex(0xcd,3,&local_20,(int *)0x0,0);
  return 0;
}


// ============================================================
// Function: score_getPropertyByD4 (FUN_6804b280)
// Address: 6804b280
// Size: 89 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getPropertyByD4(undefined4 param_1,uint *param_2,undefined4 *param_3,int *param_4)
{
  uint local_20;
  uint local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_8;
  
  local_20 = *param_2;
  local_1c = param_2[1];
  local_18 = *param_3;
  local_14 = param_3[1];
  score_getPropertyByIndex(0xd4,2,&local_20,param_4,0);
  return 0;
}


