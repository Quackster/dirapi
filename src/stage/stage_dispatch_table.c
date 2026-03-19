// Module: stage
// Topic: Opcode dispatch table initialization
// Address range: 0x68052530 - 0x68052D00
// Functions (13):
//   stage_popValues (FUN_68052530)
//   stage_pushIntValue (FUN_68052560)
//   stage_clearError (FUN_68052580)
//   stage_executeScript (FUN_680525A0)
//   stage_swapValues (FUN_680525B0)
//   stage_enableTrace (FUN_680525E0)
//   stage_disableTrace (FUN_68052600)
//   stage_initDispatchTable (FUN_68052620)
//   stage_formatDebugString (FUN_68052BF0)
//   stage_freeDispatchEntry (FUN_68052C30)
//   stage_wrapHandle (FUN_68052C60)
//   stage_unwrapHandle (FUN_68052CC0)
//   stage_allocDispatchEntry (FUN_68052D00)

// ============================================================
// Function: stage_popValues (FUN_68052530)
// Address: 68052530
// Size: 33 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_popValues(int param_1,int param_2)
{
  for (; 0 < param_2; param_2 = param_2 + -1) {
    props_popValue(param_1);
  }
  return 0;
}



// ============================================================
// Function: stage_pushIntValue (FUN_68052560)
// Address: 68052560
// Size: 31 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_pushIntValue(int param_1,undefined4 param_2)
{
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x1c) = 0x20;
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return 0;
}



// ============================================================
// Function: stage_clearError (FUN_68052580)
// Address: 68052580
// Size: 18 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_clearError(int param_1)
{
  props_setError(param_1,0);
  return 0;
}



// ============================================================
// Function: stage_executeScript (FUN_680525A0)
// Address: 680525a0
// Size: 16 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_executeScript(int param_1)
{
  cast_executeScriptHandler(param_1);
  return 0;
}



// ============================================================
// Function: stage_swapValues (FUN_680525B0)
// Address: 680525b0
// Size: 48 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_swapValues(int param_1)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  puVar1 = (undefined4 *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  uVar3 = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(param_1 + 0x1c) = *puVar1;
  *(undefined4 *)(param_1 + 0x20) = puVar1[1];
  puVar1[1] = uVar2;
  *puVar1 = uVar3;
  return 0;
}



// ============================================================
// Function: stage_enableTrace (FUN_680525E0)
// Address: 680525e0
// Size: 20 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_enableTrace(int param_1)
{
  *(undefined4 *)(param_1 + 0xe4) = 1;
  return 0;
}



// ============================================================
// Function: stage_disableTrace (FUN_68052600)
// Address: 68052600
// Size: 20 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_disableTrace(int param_1)
{
  *(undefined4 *)(param_1 + 0xe4) = 0;
  return 0;
}



// ============================================================
// Function: stage_initDispatchTable (FUN_68052620)
// Address: 68052620
// Size: 1464 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_initDispatchTable(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0x4e0);
  puVar3 = puVar1;
  for (iVar2 = 0x100; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = stage_clearError;
    puVar3 = puVar3 + 1;
  }
  puVar1[0x41] = stage_pushByteValue;
  puVar1[0x81] = stage_pushByteValue;
  puVar1[0xc1] = stage_pushByteValue;
  puVar1[0x6e] = stage_pushShortValue;
  puVar1[0xae] = stage_pushShortValue;
  puVar1[0xee] = stage_pushShortValue;
  puVar1[0x6f] = stage_getOpcodeAccess;
  puVar1[0xaf] = stage_getOpcodeAccess;
  puVar1[0xef] = stage_getOpcodeAccess;
  puVar1[0x42] = stage_getOpcodeAccess;
  puVar1[0x82] = stage_getOpcodeAccess;
  puVar1[0xc2] = stage_getOpcodeAccess;
  puVar1[0x43] = stage_pushGlobalRef;
  puVar1[0x83] = stage_pushGlobalRef;
  puVar1[0xc3] = stage_pushGlobalRef;
  puVar1[0x46] = stage_getOpcodeAccess;
  puVar1[0x86] = stage_getOpcodeAccess;
  puVar1[0xc6] = stage_getOpcodeAccess;
  puVar1[0x44] = stage_loadPropertyValue;
  puVar1[0x84] = stage_loadPropertyValue;
  puVar1[0xc4] = stage_loadPropertyValue;
  puVar1[0x47] = stage_resolveVariable;
  puVar1[0x87] = stage_resolveVariable;
  puVar1[199] = stage_resolveVariable;
  puVar1[1] = score_resetFileState;
  puVar1[2] = score_initFileFromProplist;
  puVar1[3] = score_pushFileValue;
  puVar1[4] = score_multiply;
  puVar1[5] = score_add;
  puVar1[6] = score_subtract;
  puVar1[7] = score_divide;
  puVar1[8] = score_modulo;
  puVar1[9] = score_negate;
  puVar1[10] = score_stringConcat;
  puVar1[0xb] = score_stringConcatSpace;
  puVar1[0xc] = stage_compareLessThan;
  puVar1[0xd] = stage_compareLessOrEqual;
  puVar1[0xe] = stage_compareNotEqual;
  puVar1[0xf] = stage_compareEqual;
  puVar1[0x10] = stage_compareGreaterThan;
  puVar1[0x11] = stage_compareGreaterOrEqual;
  puVar1[0x12] = score_logicalAnd;
  puVar1[0x13] = score_logicalOr;
  puVar1[0x14] = score_logicalNot;
  puVar1[0x15] = stage_compareStackGreaterEqual;
  puVar1[0x16] = stage_compareStackEqual;
  puVar1[0x17] = stage_extractChunkSubstring;
  puVar1[0x18] = stage_hiliteChunk;
  puVar1[0x19] = stage_putChunkValue;
  puVar1[0x1a] = stage_putChunkValueAfter;
  puVar1[0x1b] = stage_evalChunkAndPush;
  puVar1[0x1c] = stage_iterateInit;
  puVar1[0x1d] = stage_iterateNext;
  puVar1[0x1e] = props_getRectOpsCount;
  puVar1[0x1f] = score_initProplistDispatch;
  puVar1[0x20] = stage_executeScript;
  puVar1[0x21] = stage_swapValues;
  puVar1[0x24] = stage_compareContains;
  puVar1[0x25] = stage_compareStartsWith;
  puVar1[0x45] = stage_loadArgValue;
  puVar1[0x85] = stage_loadArgValue;
  puVar1[0xc5] = stage_loadArgValue;
  puVar1[0x48] = stage_ensureProperty;
  puVar1[0x88] = stage_ensureProperty;
  puVar1[200] = stage_ensureProperty;
  puVar1[0x49] = stage_getProperty;
  puVar1[0x89] = stage_getProperty;
  puVar1[0xc9] = stage_getProperty;
  puVar1[0x4a] = stage_getLocalProperty;
  puVar1[0x8a] = stage_getLocalProperty;
  puVar1[0xca] = stage_getLocalProperty;
  puVar1[0x4b] = stage_loadLocalValue;
  puVar1[0x8b] = stage_loadLocalValue;
  puVar1[0xcb] = stage_loadLocalValue;
  puVar1[0x4c] = stage_loadTempValue;
  puVar1[0x8c] = stage_loadTempValue;
  puVar1[0xcc] = stage_loadTempValue;
  puVar1[0x4d] = stage_setVariable;
  puVar1[0x8d] = stage_setVariable;
  puVar1[0xcd] = stage_setVariable;
  puVar1[0x4e] = stage_setEnsuredProp;
  puVar1[0x8e] = stage_setEnsuredProp;
  puVar1[0xce] = stage_setEnsuredProp;
  puVar1[0x4f] = stage_setProperty;
  puVar1[0x8f] = stage_setProperty;
  puVar1[0xcf] = stage_setProperty;
  puVar1[0x50] = stage_setLocalPropertyValue;
  puVar1[0x90] = stage_setLocalPropertyValue;
  puVar1[0xd0] = stage_setLocalPropertyValue;
  puVar1[0x51] = stage_setLocalProp;
  puVar1[0x91] = stage_setLocalProp;
  puVar1[0xd1] = stage_setLocalProp;
  puVar1[0x52] = stage_setGlobalProp;
  puVar1[0x92] = stage_setGlobalProp;
  puVar1[0xd2] = stage_setGlobalProp;
  puVar1[0x53] = stage_adjustProgramCounter;
  puVar1[0x93] = stage_adjustProgramCounter;
  puVar1[0xd3] = stage_adjustProgramCounter;
  puVar1[0x54] = stage_adjustProgramCounterFail;
  puVar1[0x94] = stage_adjustProgramCounterFail;
  puVar1[0xd4] = stage_adjustProgramCounterFail;
  puVar1[0x55] = stage_branchIfFalse;
  puVar1[0x95] = stage_branchIfFalse;
  puVar1[0xd5] = stage_branchIfFalse;
  puVar1[0x56] = props_enterHandler;
  puVar1[0x96] = props_enterHandler;
  puVar1[0xd6] = props_enterHandler;
  puVar1[0x57] = props_invokeHandler;
  puVar1[0x97] = props_invokeHandler;
  puVar1[0xd7] = props_invokeHandler;
  puVar1[0x58] = props_callMethod;
  puVar1[0x98] = props_callMethod;
  puVar1[0xd8] = props_callMethod;
  puVar1[0x59] = stage_formatChunkString;
  puVar1[0x99] = stage_formatChunkString;
  puVar1[0xd9] = stage_formatChunkString;
  puVar1[0x5a] = stage_formatChunkStringEx;
  puVar1[0x9a] = stage_formatChunkStringEx;
  puVar1[0xda] = stage_formatChunkStringEx;
  puVar1[0x5b] = stage_deleteChunkRange;
  puVar1[0x9b] = stage_deleteChunkRange;
  puVar1[0xdb] = stage_deleteChunkRange;
  puVar1[0x5c] = stage_dispatchGetProp;
  puVar1[0x9c] = stage_dispatchGetProp;
  puVar1[0xdc] = stage_dispatchGetProp;
  puVar1[0x5d] = stage_dispatchSetProp;
  puVar1[0x9d] = stage_dispatchSetProp;
  puVar1[0xdd] = stage_dispatchSetProp;
  puVar1[0x68] = stage_formatChunkStringPersist;
  puVar1[0xa8] = stage_formatChunkStringPersist;
  puVar1[0xe8] = stage_formatChunkStringPersist;
  puVar1[0x69] = stage_formatStackString;
  puVar1[0xa9] = stage_formatStackString;
  puVar1[0xe9] = stage_formatStackString;
  puVar1[0x6a] = stage_deleteStackRange;
  puVar1[0xaa] = stage_deleteStackRange;
  puVar1[0xea] = stage_deleteStackRange;
  puVar1[0x6b] = stage_dispatchGetMovieProp;
  puVar1[0xab] = stage_dispatchGetMovieProp;
  puVar1[0xeb] = stage_dispatchGetMovieProp;
  puVar1[0x6c] = stage_dispatchSetMovieProp;
  puVar1[0xac] = stage_dispatchSetMovieProp;
  puVar1[0xec] = stage_dispatchSetMovieProp;
  puVar1[0x22] = stage_putStackValue;
  puVar1[0x23] = stage_getStackValue;
  puVar1[0x5f] = stage_getSymbolProp;
  puVar1[0x9f] = stage_getSymbolProp;
  puVar1[0xdf] = stage_getSymbolProp;
  puVar1[0x60] = stage_setSymbolProp;
  puVar1[0xa0] = stage_setSymbolProp;
  puVar1[0xe0] = stage_setSymbolProp;
  puVar1[0x61] = stage_getPropFromObject;
  puVar1[0xa1] = stage_getPropFromObject;
  puVar1[0xe1] = stage_getPropFromObject;
  puVar1[0x70] = stage_dispatchPropCall;
  puVar1[0xb0] = stage_dispatchPropCall;
  puVar1[0xf0] = stage_dispatchPropCall;
  puVar1[0x62] = stage_dispatchPropSet;
  puVar1[0xa2] = stage_dispatchPropSet;
  puVar1[0xe2] = stage_dispatchPropSet;
  puVar1[99] = stage_dispatchPropGet;
  puVar1[0xa3] = stage_dispatchPropGet;
  puVar1[0xe3] = stage_dispatchPropGet;
  puVar1[100] = stage_loadPropRef;
  puVar1[0xa4] = stage_loadPropRef;
  puVar1[0xe4] = stage_loadPropRef;
  puVar1[0x65] = stage_popValues;
  puVar1[0xa5] = stage_popValues;
  puVar1[0xe5] = stage_popValues;
  puVar1[0x66] = props_callPropertyHandler;
  puVar1[0xa6] = props_callPropertyHandler;
  puVar1[0xe6] = props_callPropertyHandler;
  puVar1[0x67] = props_dispatchPropertyAccess;
  puVar1[0xa7] = props_dispatchPropertyAccess;
  puVar1[0xe7] = props_dispatchPropertyAccess;
  puVar1[0x6d] = stage_getChunkProperty;
  puVar1[0xad] = stage_getChunkProperty;
  puVar1[0xed] = stage_getChunkProperty;
  puVar1[0x71] = stage_pushIntValue;
  puVar1[0xb1] = stage_pushIntValue;
  puVar1[0xf1] = stage_pushIntValue;
  puVar1[0x26] = core_dispatchExternalCall;
  puVar1[0x72] = core_resolveClassProperty;
  puVar1[0xb2] = core_resolveClassProperty;
  puVar1[0xf2] = core_resolveClassProperty;
  puVar1[0x73] = core_dispatchPropertyAccess;
  puVar1[0xb3] = core_dispatchPropertyAccess;
  puVar1[0xf3] = core_dispatchPropertyAccess;
  return 0;
}



// ============================================================
// Function: stage_formatDebugString (FUN_68052BF0)
// Address: 68052bf0
// Size: 53 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_formatDebugString(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x33);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: stage_freeDispatchEntry (FUN_68052C30)
// Address: 68052c30
// Size: 38 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_freeDispatchEntry(int param_1,int *param_2)
{
  cast_freeHandle(*(undefined4 *)(*param_2 + 8));
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}



// ============================================================
// Function: stage_wrapHandle (FUN_68052C60)
// Address: 68052c60
// Size: 91 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_wrapHandle(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(0xc,0);
  if (piVar2 == (int *)0x0) {
    cast_freeHandle(param_2);
    *param_3 = 0;
    return 0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  puVar1 = (undefined4 *)*piVar2;
  puVar1[2] = param_2;
  *puVar1 = &PTR_LAB_6818d958;
  puVar1[1] = 1;
  param_3[1] = piVar2;
  *param_3 = 3;
  return 1;
}



// ============================================================
// Function: stage_unwrapHandle (FUN_68052CC0)
// Address: 68052cc0
// Size: 51 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_unwrapHandle(undefined4 param_1,int *param_2,int *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d958)) {
    if (param_3 != (int *)0x0) {
      *param_3 = (*(int **)param_2[1])[2];
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_allocDispatchEntry (FUN_68052d00)
// Address: 68052d00
// Size: 175 bytes
// Params: short param_1, short param_2, short param_3, int param_4
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * stage_allocDispatchEntry(short param_1,short param_2,short param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  short sVar3;
  int iVar4;
  
  if (param_4 < 0) {
    param_4 = 0;
  }
  sVar3 = param_1 - param_3;
  if ((((param_3 < 0) || (iVar4 = (int)param_3, (int)(0x7fffffff / (longlong)iVar4) < param_4)) ||
      (0x7fffffff - iVar4 * param_4 < (int)param_2)) ||
     (((iVar2 = (int)param_2 + iVar4 * param_4, iVar2 < 0 || (iVar2 < param_4)) ||
      ((iVar2 < iVar4 || (iVar2 < param_2)))))) {
    DAT_68195a8c = 1;
  }
  else {
    if (iVar2 < sVar3) {
      iVar2 = (int)sVar3;
    }
    piVar1 = (int *)Ordinal_1111(iVar2,1);
    if (piVar1 != (int *)0x0) {
      *(undefined4 *)(*piVar1 + 0x10) = 0;
      *(int *)(*piVar1 + 0x14) = param_4;
      *(short *)(*piVar1 + 0x18) = param_2;
      *(short *)(*piVar1 + 0x1a) = sVar3;
      *(short *)(*piVar1 + 0x1e) = param_3;
      return piVar1;
    }
  }
  return (int *)0x0;
}



