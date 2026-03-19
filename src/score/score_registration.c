// Module: score
// Topic: Function registration, debug output, initialization
// Address range: 0x680413c0 - 0x68042040
// Functions (10):
//   score_traceArgs (FUN_680413c0)
//   score_retryOnSync (FUN_68041540)
//   score_dumpPropertyList (FUN_680415d0)
//   score_dumpVariables (FUN_68041690)
//   score_resetVariables (FUN_680417c0)
//   score_wrapGetRectOps (FUN_68041880)
//   score_wrapInitProplist (FUN_680418a0)
//   score_registerHandler (FUN_680418c0)
//   score_registerBuiltins (FUN_68041950)
//   score_registerAllHandlers

// ============================================================
// Function: score_traceArgs (FUN_680413c0)
// Address: 680413c0
// Size: 382 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_traceArgs(int param_1)
{
  int iVar1;
  int iVar2;
  int local_1814;
  int local_1810;
  undefined4 local_180c;
  undefined2 local_1808;
  undefined1 local_1806 [4094];
  undefined2 local_808;
  undefined1 local_806;
  undefined1 local_805 [1021];
  undefined2 local_408;
  undefined1 local_406;
  undefined1 local_405 [1021];
  uint local_8;
  
  local_180c = 0x2d2d2004;
  local_1808 = 0x20;
  memset(local_1806,0,0xffc);
  local_408 = 0x2001;
  local_406 = 0;
  memset(local_405,0,0x3fd);
  local_808 = 0xa01;
  local_806 = 0;
  memset(local_805,0,0x3fd);
  iVar1 = props_getInt(param_1);
  if (0 < iVar1) {
    iVar2 = iVar1 * 8;
    do {
      _DAT_68197764 = (int *)((**(int **)(param_1 + 0x10) - iVar2) + *(int *)(param_1 + 0x18));
      local_1810 = DAT_6819776c;
      local_1814 = DAT_68197768;
      if (_DAT_68197764 != (int *)0x0) {
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        local_1810 = ((int *)(size_t)_DAT_68197764)[1];
        local_1814 = *(int *)(size_t)_DAT_68197764;
      }
      props_resolveAndStore(param_1,&local_1814,&local_180c);
      if (iVar1 != 1) {
        Ordinal_1237(&local_180c,&local_408,0x1000);
      }
      iVar1 = iVar1 + -1;
      iVar2 = iVar2 + -8;
    } while (0 < iVar1);
  }
  Ordinal_1237(&local_180c,&local_808,0x1000);
  props_formatValue(param_1,&DAT_6817c418);
  props_popArgs(param_1,(undefined4 *)0x0);
  return 0;
}


// ============================================================
// Function: score_retryOnSync (FUN_68041540)
// Address: 68041540
// Size: 130 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_retryOnSync(int param_1)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint local_8;
  
  iVar4 = 1;
  local_8 = 1;
  iVar2 = props_getTypedProperty(param_1,1,4,&local_8);
  if (iVar2 != 0) {
    if ((int)local_8 < 0) {
      local_8 = 1;
    }
    iVar2 = cast_waitForSync();
    if (0 < (int)local_8) {
      do {
        Ordinal_965();
        if ((iVar2 == 0) && (iVar3 = cast_waitForSync(), iVar3 != 0)) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        iVar3 = sprites_resolveTextChannel(param_1);
      } while ((iVar3 == 0 && !bVar1) && (iVar4 = iVar4 + 1, iVar4 <= (int)local_8));
    }
    props_popArgs(param_1,(undefined4 *)0x0);
  }
  return 0;
}


// ============================================================
// Function: score_dumpPropertyList (FUN_680415d0)
// Address: 680415d0
// Size: 191 bytes
// Params: undefined * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dumpPropertyList(undefined *param_1)
{
  int iVar1;
  int local_80c;
  undefined2 local_808 [512];
  undefined2 local_408;
  uint local_8;
  
  local_80c = 0;
  cast_loadPascalString((undefined1 *)&local_408,0x898,7);
  props_formatValue((int)param_1,(byte *)((int)&local_408 + 1));
  stage_getScopeEntry((int)param_1,0,&local_408,&local_80c);
  iVar1 = 0;
  if (0 < local_80c) {
    do {
      stage_getContextValue(param_1,0,iVar1,(undefined1 *)&local_408,local_808,(undefined4 *)0x0,(int *)0x0);
      props_formatValue((int)param_1,(byte *)"%p = %p\n");
      iVar1 = iVar1 + 1;
    } while (iVar1 < local_80c);
  }
  props_popArgs((int)param_1,(undefined4 *)0x0);
  return 0;
}


// ============================================================
// Function: score_dumpVariables (FUN_68041690)
// Address: 68041690
// Size: 298 bytes
// Params: undefined * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dumpVariables(undefined *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_410;
  undefined4 local_40c;
  undefined1 local_408;
  byte local_407 [1023];
  uint local_8;
  
  iVar3 = props_getInt((int)param_1);
  if (iVar3 < 3) {
    cast_loadPascalString(&local_408,0x898,4);
    props_formatValue((int)param_1,local_407);
    iVar3 = *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x4e4) + 0x14);
    if (0 < iVar3) {
      iVar4 = 0;
      do {
        iVar2 = *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x4e4) + 0x24 + iVar4);
        iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x4e4) + 0x24 + iVar4;
        local_410 = *(int *)(iVar1 + 8);
        local_40c = *(undefined4 *)(iVar1 + 0xc);
        if ((iVar2 != -1) && (local_410 != 2)) {
          score_lookupSymbol(DAT_68196304,iVar2,(int)&local_408);
          props_formatValue((int)param_1,(byte *)"%p = ");
          props_setupCallback(param_1,&local_410,(undefined2 *)0x0);
          props_formatValue((int)param_1,&DAT_6817c158);
        }
        iVar4 = iVar4 + 0x10;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    props_popArgs((int)param_1,(undefined4 *)0x0);
    return 0;
  }
  props_buildRectFilterList((int)param_1);
  return 0;
}


// ============================================================
// Function: score_resetVariables (FUN_680417c0)
// Address: 680417c0
// Size: 179 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_resetVariables(uint param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_c;
  undefined4 local_8;
  
  uVar4 = param_1;
  iVar5 = 0;
  events_setContextRef(param_1,(int *)0x0);
  local_c = 2;
  local_8 = 0;
  param_1 = *(uint *)(**(int **)(**(int **)(param_1 + 8) + 0x4e4) + 0x14);
  if (0 < (int)param_1) {
    do {
      iVar1 = **(int **)(**(int **)(uVar4 + 8) + 0x4e4);
      iVar2 = *(int *)(iVar1 + 0x24 + iVar5);
      iVar1 = iVar1 + 0x24 + iVar5;
      iVar3 = *(int *)(iVar1 + 8);
      if (((iVar2 != -1) && (iVar2 != 300)) && (iVar3 != 6)) {
        props_releaseValue(uVar4,(byte)iVar3,*(int **)(iVar1 + 0xc));
        iVar1 = **(int **)(**(int **)(uVar4 + 8) + 0x4e4);
        *(uint *)(iVar1 + 0x2c + iVar5) = local_c;
        *(undefined4 *)(iVar1 + 0x30 + iVar5) = local_8;
        core_dispatchAsync(uVar4,iVar2,&local_c);
      }
      iVar5 = iVar5 + 0x10;
      param_1 = param_1 - 1;
    } while (param_1 != 0);
  }
  props_popArgs(uVar4,(undefined4 *)0x0);
  return 0;
}


// ============================================================
// Function: score_wrapGetRectOps (FUN_68041880)
// Address: 68041880
// Size: 18 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_wrapGetRectOps(int param_1)
{
  props_getRectOpsCount(param_1);
  return 0;
}


// ============================================================
// Function: score_wrapInitProplist (FUN_680418a0)
// Address: 680418a0
// Size: 18 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_wrapInitProplist(int param_1)
{
  score_initProplistDispatch(param_1);
  return 0;
}


// ============================================================
// Function: score_registerHandler (FUN_680418c0)
// Address: 680418c0
// Size: 133 bytes
// Params: int param_1, uint param_2, undefined4 param_3, undefined4 param_4, char * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_registerHandler(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,char *param_5)
{
  char cVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 local_18;
  undefined4 local_14;
  char local_10 [8];
  uint local_8;
  
  Ordinal_1130(&local_18,0x10);
  local_18 = param_3;
  local_14 = param_4;
  iVar2 = -(int)param_5;
  do {
    cVar1 = *param_5;
    param_5[(int)(local_10 + iVar2)] = cVar1;
    param_5 = param_5 + 1;
  } while (cVar1 != '\0');
  uVar3 = stage_lookupSymbolId(*(int **)(param_1 + 0x4f0),&local_18);
  puVar4 = score_lookupProperty(*(int **)(param_1 + 0x4ec),param_2,1,(uint *)0x0);
  if (puVar4 != (uint *)0x0) {
    *puVar4 = 4;
    puVar4[1] = uVar3;
  }
  return 0;
}


// ============================================================
// Function: score_registerBuiltins (FUN_68041950)
// Address: 68041950
// Size: 1771 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_registerBuiltins(int param_1)
{
  score_registerHandler(param_1,0x124,score_retryOnSync,0,"-");
  score_registerHandler(param_1,0x2f,score_traceArgs,0,"-");
  score_registerHandler(param_1,0xab,strings_executeLingo,0,"-0");
  score_registerHandler(param_1,0x27,props_builtinReturn,0,"-");
  score_registerHandler(param_1,0xac,score_execLingo,0,"-1");
  score_registerHandler(param_1,0xad,score_returnVoid,0,"-0");
  score_registerHandler(param_1,0xae,score_returnValue,0,"-0");
  score_registerHandler(param_1,0x12d,stage_attachScript,0,"-");
  score_registerHandler(param_1,0x12e,stage_detachScript,0,"-");
  score_registerHandler(param_1,0x12f,stage_dumpScriptList,0,"-");
  score_registerHandler(param_1,0x125,score_dumpPropertyList,0,"-");
  score_registerHandler(param_1,0x126,score_dumpVariables,0,"-");
  score_registerHandler(param_1,0x127,score_resetVariables,0,"-");
  score_registerHandler(param_1,0x128,score_getTimestamp,0,"x0");
  score_registerHandler(param_1,0x129,&LAB_680413a0,0,"d0");
  score_registerHandler(param_1,0x12a,&LAB_680413b0,0,"d0");
  score_registerHandler(param_1,0x86,&LAB_68040170,0,"d0");
  score_registerHandler(param_1,0x85,props_handleDateBuiltin,0,"x");
  score_registerHandler(param_1,0x84,props_handleTimeBuiltin,0,"x0");
  score_registerHandler(param_1,0x88,score_getTheResult,0,"x0");
  score_registerHandler(param_1,0x7f,score_returnSpace,0,"x0");
  score_registerHandler(param_1,0x7e,score_returnNothing,0,"x0");
  score_registerHandler(param_1,299,score_getChannelRef,0,"d0");
  score_registerHandler(param_1,0x89,props_builtinAbs,0,"x1");
  score_registerHandler(param_1,0x8a,props_builtinCharCount,0,"x1");
  score_registerHandler(param_1,0x8b,props_builtinStringify,0,"x1");
  score_registerHandler(param_1,0x8c,props_builtinIdentify,0,"x1");
  score_registerHandler(param_1,0x8d,props_builtinIntToChar,0,"x1");
  score_registerHandler(param_1,0x8e,props_builtinFloatValue,0,"x1");
  score_registerHandler(param_1,0x92,props_builtinCharToInt,0,"x1");
  score_registerHandler(param_1,0x41,props_builtinResolveScript,0,"x1");
  score_registerHandler(param_1,0x95,props_builtinParseValue,0,"x1");
  score_registerHandler(param_1,0x96,score_evalExpression,0,"x1");
  score_registerHandler(param_1,0x97,score_toString,0,"x1");
  score_registerHandler(param_1,0x9c,score_randomRange,0,"x");
  score_registerHandler(param_1,0x8f,score_getTypeInfo,4,"x1");
  score_registerHandler(param_1,0x90,score_getTypeInfo,1,"x1");
  score_registerHandler(param_1,0x93,score_isListType,0,"x1");
  score_registerHandler(param_1,0x94,score_getTypeInfo,9,"x1");
  score_registerHandler(param_1,0xaf,score_getTypeInfo,8,"x1");
  score_registerHandler(param_1,0xb0,score_getTypeInfo,2,"x1");
  score_registerHandler(param_1,0x98,score_isObjectOfType,0xa9,"x1");
  score_registerHandler(param_1,0x91,score_isObjectOfType,0x132,"x1");
  score_registerHandler(param_1,0xb1,score_getValueOrProplist,0,"x1");
  score_registerHandler(param_1,0xb2,score_charToNum,0,"x2");
  score_registerHandler(param_1,0x114,score_charsSubstring,0,"x3");
  score_registerHandler(param_1,0xe1,score_minMax,0xffffffff,"x");
  score_registerHandler(param_1,0xe2,score_minMax,1,"x");
  score_registerHandler(param_1,0xb3,score_sin,0,"x1");
  score_registerHandler(param_1,0xb4,score_cos,0,"x1");
  score_registerHandler(param_1,0xb5,score_tan,0,"x1");
  score_registerHandler(param_1,0xb6,score_atan,0,"x");
  score_registerHandler(param_1,0xb7,score_sqrt,0,"x1");
  score_registerHandler(param_1,0xb8,score_exp,0,"x1");
  score_registerHandler(param_1,0xb9,score_power,0,"x2");
  score_registerHandler(param_1,0x80,score_returnPi,0,"x0");
  score_registerHandler(param_1,0x9b,score_getParam,0,"x1");
  score_registerHandler(param_1,0x9a,score_getTypeField,0,"d0");
  score_registerHandler(param_1,0xba,score_wrapGetRectOps,0,"x");
  score_registerHandler(param_1,0xbb,score_wrapInitProplist,0,"x");
  score_registerHandler(param_1,0xbc,props_buildRectFromInts,0,"x4");
  score_registerHandler(param_1,0xbd,props_buildPointFromInts,0,"x2");
  score_registerHandler(param_1,0xbe,score_colorFromArgs,0,"x");
  score_registerHandler(param_1,0xbf,score_parseMediaColor,0,"x");
  score_registerHandler(param_1,0xc0,score_colorFromInt,0,"x1");
  score_registerHandler(param_1,0x87,score_dateFromArgs,0,"x");
  score_registerHandler(param_1,0xc1,score_iterateListForward,0,"*");
  score_registerHandler(param_1,0xc2,score_iterateListReverse,0,"*");
  score_registerHandler(param_1,0xe3,score_resolveType,0,"x");
  score_registerHandler(param_1,0xc3,score_iterateListForward,0,"*");
  score_registerHandler(param_1,0xc4,score_iterateListReverse,0,"*");
  score_registerHandler(param_1,0xc5,score_bitwiseAnd,0,"d2dd");
  score_registerHandler(param_1,0xc6,score_bitwiseOr,0,"d2dd");
  score_registerHandler(param_1,199,score_bitwiseXor,0,"d2dd");
  score_registerHandler(param_1,200,score_bitwiseNot,0,"d1d");
  score_registerHandler(param_1,0x56,score_handleTimerOp,0,"x");
  score_registerHandler(param_1,0x134,stage_createGcObject,0,"*");
  return 0;
}


// ============================================================
// Function: score_registerAllHandlers (FUN_68042040)
// Address: 68042040
// Size: 269 bytes
// Params: int param_1, int * param_2, int * param_3, int * param_4, byte * param_5, int * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_registerAllHandlers(int param_1,int *param_2,int *param_3,int *param_4,byte *param_5,int *param_6)
{
  int iVar1;
  int iVar2;
  undefined1 local_c [4];
  int local_8;
  
  if (*param_2 + 0x7533U < 4) {
    iVar1 = -*param_2;
    props_invokeBuiltin(param_1,iVar1 + -29999,(int)local_c,param_5,*param_6);
    Ordinal_1130(param_2,0x30);
    param_2[(iVar1 + -30000) * 3] = local_8;
    (param_2 + (iVar1 + -30000) * 3)[1] = local_8;
  }
  props_splitString(param_1,3,param_2 + 9,param_3,param_4,(int)param_5,param_6);
  props_splitString(param_1,2,param_2 + 6,param_3,param_4,(int)param_5,param_6);
  props_splitString(param_1,1,param_2 + 3,param_3,param_4,(int)param_5,param_6);
  if (0 < *param_2) {
    iVar1 = stage_getStringAllocState();
    iVar2 = stage_getStringAllocState();
    param_2[2] = ((iVar1 - (int)param_5) - *param_3) + 1;
    *param_3 = iVar1 - (int)param_5;
    *param_6 = *param_4;
    *param_4 = iVar2 - (int)param_5;
  }
  return 0;
}


