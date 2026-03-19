// Module: props
// Topic: External API bridge and type marshaling functions
// Address range: 0x680381e0 - 0x68038d40
// Functions (33):
//   props_mapTypeCode (FUN_680381e0)
//   props_coerceAndReturnInt (FUN_680384d0)
//   props_coerceAndReturnBool (FUN_68038510)
//   props_coerceAndReturnFloat
//   props_coerceAndReturnDouble
//   props_coerceAndReturnSymbol
//   props_freeStringAndReturn (FUN_68038610)
//   props_coerceAndReturnString
//   props_getStringCharCount (FUN_680386a0)
//   props_getApiContext
//   props_getApiState
//   props_getContextState
//   props_coerceAndStore
//   props_convertDateToTimestamp (FUN_680387e0)
//   props_convertTimestampToDate (FUN_68038920)
//   props_createRectFromValue (FUN_680389f0)
//   props_storeIntValue (FUN_68038a30)
//   props_storeObjectRef
//   props_storeFloatDirect
//   props_storeFloatValue
//   props_storeSymbolRef
//   props_storeRectOp (FUN_68038af0)
//   props_coerceToShort
//   props_storeSymbolValue
//   props_coerceToType
//   props_coerceToContextState (FUN_68038be0)
//   props_coerceToRect (FUN_68038c40)
//   props_getContextRef
//   props_dispatchMethod
//   props_resolveRef
//   props_callMethodDirect
//   props_callBuiltinDirect (FUN_68038d00)
//   props_resolveValue



// ============================================================
// Function: props_mapTypeCode (FUN_680381e0)
// Address: 680381e0
// Size: 447 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_mapTypeCode(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = score_checkType(param_1,param_2);
  if (iVar1 < 0x133) {
    if (iVar1 == 0x132) {
      *param_3 = 0x16;
      return 0;
    }
    switch(iVar1) {
    case 0x2e:
      *param_3 = 0x10;
      return 0;
    case 0x54:
      *param_3 = 0x11;
      return 0;
    case 0x58:
      *param_3 = 0xb;
      return 0;
    case 0x68:
      *param_3 = 0xc;
      return 0;
    case 0x7b:
      *param_3 = 0xd;
      return 0;
    case 0x7d:
      *param_3 = 0xf;
      return 0;
    case 0x7e:
    case 0xff:
      *param_3 = 0;
      return 0;
    case 0x85:
      *param_3 = 0x13;
      return 0;
    case 0x8b:
      *param_3 = 3;
      return 0;
    case 0x8c:
      *param_3 = 2;
      return 0;
    case 0x95:
      *param_3 = 1;
      return 0;
    case 0x97:
      *param_3 = 6;
      return 0;
    case 0xa8:
      *param_3 = 4;
      return 0;
    case 0xa9:
      *param_3 = 5;
      return 0;
    case 0xba:
      *param_3 = 7;
      return 0;
    case 0xbb:
      *param_3 = 10;
      return 0;
    case 0xbc:
      *param_3 = 9;
      return 0;
    case 0xbd:
      *param_3 = 8;
      return 0;
    case 0xbe:
      *param_3 = 0x12;
      return 0;
    case 0xeb:
      *param_3 = 0xe;
      return 0;
    case 0x100:
      *param_3 = 0x14;
      return 0;
    }
  }
  else if (iVar1 == 0x133) {
    *param_3 = 0x17;
    return 0;
  }
  *param_3 = 0x15;
  return 0;
}



// ============================================================
// Function: props_coerceAndReturnInt (FUN_680384d0)
// Address: 680384d0
// Size: 52 bytes
// Params: int param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceAndReturnInt(int param_1,uint *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = props_coerceToInt(param_1,(int *)param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = props_returnWithValue(param_1,0x800407d9,param_2);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: props_coerceAndReturnBool (FUN_68038510)
// Address: 68038510
// Size: 64 bytes
// Params: int param_1, uint * param_2, undefined1 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceAndReturnBool(int param_1,uint *param_2,undefined1 *param_3)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  puVar1 = param_2;
  iVar2 = props_coerceToInt(param_1,(int *)param_2,(int *)&param_2);
  if (iVar2 == 0) {
    uVar3 = props_returnWithValue(param_1,0x800407d9,puVar1);
    return uVar3;
  }
  param_3[3] = 0;
  *param_3 = (*(unsigned char *)((char *)&param_2 + 0));
  return 0;
}



// ============================================================
// Function: props_coerceAndReturnFloat (FUN_68038550)
// Address: 68038550
// Size: 44 bytes
// Params: int param_1, uint * param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceAndReturnFloat(int param_1,uint *param_2,uint *param_3)

{
  undefined4 uVar1;
  
  if (*param_2 != 8) {
    uVar1 = props_returnWithValue(param_1,0x800407da,param_2);
    return uVar1;
  }
  *param_3 = param_2[1];
  return 0;
}



// ============================================================
// Function: props_coerceAndReturnDouble (FUN_68038580)
// Address: 68038580
// Size: 67 bytes
// Params: int param_1, uint * param_2, double * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceAndReturnDouble(int param_1,uint *param_2,double *param_3)

{
  int iVar1;
  undefined4 uVar2;
  double local_c;
  
  iVar1 = props_coerceToFloat(param_1,(int *)param_2,&local_c);
  if (iVar1 == 0) {
    uVar2 = props_returnWithValue(param_1,0x800407db,param_2);
    return uVar2;
  }
  *param_3 = local_c;
  return 0;
}



// ============================================================
// Function: props_coerceAndReturnSymbol (FUN_680385d0)
// Address: 680385d0
// Size: 54 bytes
// Params: int param_1, uint * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceAndReturnSymbol(int param_1,uint *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if ((*param_2 != 0x40) && (*param_2 != 0x43)) {
    uVar1 = props_returnWithValue(param_1,0x800407dc,param_2);
    return uVar1;
  }
  puVar2 = props_copyString((int *)param_2);
  *param_3 = puVar2;
  return 0;
}



// ============================================================
// Function: props_freeStringAndReturn (FUN_68038610)
// Address: 68038610
// Size: 22 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_freeStringAndReturn(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  props_freeStringCallback(param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_coerceAndReturnString (FUN_68038630)
// Address: 68038630
// Size: 106 bytes
// Params: int param_1, uint * param_2, undefined1 * param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceAndReturnString(int param_1,uint *param_2,undefined1 *param_3,int param_4)

{
  uint *puVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  int *piVar4;
  uint *puVar5;
  
  puVar1 = param_2;
  if ((*param_2 != 0x40) && (*param_2 != 0x43)) {
    if (0 < param_4) {
      *param_3 = 0;
    }
    uVar3 = props_returnWithValue(param_1,0x800407dc,param_2);
    return uVar3;
  }
  piVar4 = props_getStringData((int *)param_2,(int *)&param_2);
  puVar2 = param_3;
  puVar5 = param_2;
  if (param_4 <= (int)param_2) {
    puVar5 = (uint *)(param_4 + -1);
  }
  Ordinal_1128(param_3,piVar4,puVar5);
  *(undefined1 *)((int)puVar5 + (int)puVar2) = 0;
  props_unlockString((int *)puVar1);
  return 0;
}



// ============================================================
// Function: props_getStringCharCount (FUN_680386a0)
// Address: 680386a0
// Size: 109 bytes
// Params: int param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getStringCharCount(int param_1,uint *param_2,int *param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  if (*param_2 == 0x40) {
    *param_3 = (uint)((char)param_2[1] != '\0') +
               (uint)(*(char *)((int)param_2 + 6) != '\0') +
               (uint)(*(char *)((int)param_2 + 5) != '\0');
    return 0;
  }
  if (*param_2 != 0x43) {
    *param_3 = 0;
    uVar1 = props_returnWithValue(param_1,0x800407dc,param_2);
    return uVar1;
  }
  iVar2 = Ordinal_1116(param_2[1]);
  *param_3 = iVar2 + -9;
  return 0;
}



// ============================================================
// Function: props_getApiContext (FUN_68038710)
// Address: 68038710
// Size: 36 bytes
// Params: int * param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * props_getApiContext(int *param_1)

{
  int *piVar1;
  
  if ((*param_1 != 0x40) && (*param_1 != 0x43)) {
    return (int *)0x0;
  }
  piVar1 = props_getStringData(param_1,(int *)0x0);
  return piVar1;
}



// ============================================================
// Function: props_getApiState (FUN_68038740)
// Address: 68038740
// Size: 30 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getApiState(int *param_1)

{
  if ((*param_1 == 0x40) || (*param_1 == 0x43)) {
    props_unlockString(param_1);
  }
  return 0;
}



// ============================================================
// Function: props_getContextState (FUN_68038760)
// Address: 68038760
// Size: 52 bytes
// Params: int param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getContextState(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = props_getRectField(param_1,(int *)param_2);
  if (iVar1 == 0) {
    uVar2 = props_returnWithValue(param_1,0x800407dd,param_2);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: props_coerceAndStore (FUN_680387a0)
// Address: 680387a0
// Size: 57 bytes
// Params: int param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceAndStore(int param_1,uint *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = score_getColorFromObject(param_1,(int *)param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = props_returnWithValue(param_1,0x800407f0,param_2);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: props_convertDateToTimestamp (FUN_680387e0)
// Address: 680387e0
// Size: 308 bytes
// Params: int param_1, uint * param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_convertDateToTimestamp(int param_1,uint *param_2,uint *param_3)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  puVar2 = param_2;
  iVar7 = param_1;
  iVar4 = score_extractDateParts(param_1,(int *)param_2,&param_2,&param_1);
  puVar3 = param_3;
  puVar6 = param_2;
  if (iVar4 != 0) {
    if ((int)param_2 + 0x6117U < 0xc22f) {
      *param_3 = 0;
      *param_3 = (int)param_2 * 0x15180;
      param_3[1] = (-1 < (int)param_2 * 0x15180) - 1;
    }
    else {
      *param_3 = 0;
      param_3[1] = 0;
      param_2 = (uint *)0x1;
      if ((int)puVar6 < 0) {
        puVar6 = (uint *)-(int)puVar6;
        param_2 = (uint *)0xffffffff;
      }
      if (1000 < (int)puVar6) {
        iVar7 = ((int)puVar6 - 0x3e9U) / 1000 + 1;
        puVar6 = puVar6 + iVar7 * -0xfa;
        param_3 = (uint *)0x0;
        do {
          param_3 = (uint *)((int)param_3 + ((-1 < (int)param_2 * 86400000) - 1));
          uVar8 = *puVar3;
          uVar9 = uVar8 + (int)param_2 * 86400000;
          *puVar3 = uVar9;
          if (uVar9 < uVar8) {
            param_3 = (uint *)((int)param_3 + 1);
          }
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        puVar3[1] = (uint)param_3;
      }
      if (0 < (int)puVar6) {
        uVar9 = puVar3[1];
        do {
          uVar1 = *puVar3;
          uVar9 = uVar9 + ((-1 < (int)param_2 * 0x15180) - 1);
          uVar8 = uVar1 + (int)param_2 * 0x15180;
          *puVar3 = uVar8;
          if (uVar8 < uVar1) {
            uVar9 = uVar9 + 1;
          }
          puVar6 = (uint *)((int)puVar6 + -1);
        } while (puVar6 != (uint *)0x0);
        puVar3[1] = uVar9;
      }
    }
    uVar9 = *puVar3;
    uVar8 = param_1 + uVar9;
    *puVar3 = uVar8;
    if (uVar8 < uVar9) {
      puVar3[1] = puVar3[1] + 1;
    }
    return 0;
  }
  uVar5 = props_returnWithValue(iVar7,0x800407d2,puVar2);
  return uVar5;
}



// ============================================================
// Function: props_convertTimestampToDate (FUN_68038920)
// Address: 68038920
// Size: 197 bytes
// Params: undefined4 param_1, uint param_2, int param_3, uint param_4, int param_5, undefined4 * param_6
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
props_convertTimestampToDate(undefined4 param_1,uint param_2,int param_3,uint param_4,int param_5,
            undefined4 *param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  float10 extraout_ST0;
  ulonglong uVar6;
  undefined4 local_10;
  int local_8;
  
  iVar4 = 0;
  local_8 = 0;
  iVar3 = -0x5fb4;
  iVar5 = 0x7e2bce00;
  if ((-1 < param_5) && (param_4 != 0)) {
    iVar4 = -1;
    iVar5 = -0x7e2bce00;
    iVar3 = 0x5fb4;
  }
  do {
    uVar1 = param_4;
    if (param_5 == 0) {
      if (-1 < (int)uVar1) goto LAB_6803895b;
    }
    else if ((param_5 == -1) && ((int)uVar1 < 0)) {
LAB_6803895b:
      uVar6 = strings_floatToUint64(param_5,param_2);
      *param_6 = 3;
      local_10 = (undefined4)
                 (longlong)
                 ROUND((float10)60.0 * (extraout_ST0 - (float10)(int)uVar6) * (float10)60.0 *
                       (float10)24.0);
      uVar2 = score_setDateProperty(param_3,(int)uVar6 + local_8,local_10);
      param_6[1] = uVar2;
      return 0;
    }
    param_5 = param_5 + iVar4;
    if (uVar1 + iVar5 < uVar1) {
      param_5 = param_5 + 1;
    }
    local_8 = local_8 + iVar3;
    param_4 = uVar1 + iVar5;
    param_2 = uVar1;
  } while( true );
}



// ============================================================
// Function: props_createRectFromValue (FUN_680389f0)
// Address: 680389f0
// Size: 52 bytes
// Params: int param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_createRectFromValue(int param_1,uint *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = props_createRect(param_1,(int *)param_2);
  if (iVar1 == 0) {
    uVar2 = props_returnWithValue(param_1,0x800407de,param_2);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: props_storeIntValue (FUN_68038a30)
// Address: 68038a30
// Size: 24 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_storeIntValue(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

{
  *param_3 = 4;
  param_3[1] = param_2;
  return 0;
}



// ============================================================
// Function: props_storeObjectRef (FUN_68038a50)
// Address: 68038a50
// Size: 28 bytes
// Params: undefined4 param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_storeObjectRef(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if (param_2 != 0) {
    *param_3 = 8;
    param_3[1] = param_2;
  }
  return 0;
}



// ============================================================
// Function: props_storeFloatDirect (FUN_68038a70)
// Address: 68038a70
// Size: 51 bytes
// Params: int param_1, double param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_storeFloatDirect(int param_1,double param_2,int *param_3)

{
  props_storeNumber(param_1,param_2,param_3);
  if ((*param_3 != 0x20) && (*param_3 != 0x23)) {
    *param_3 = 2;
  }
  return 0;
}



// ============================================================
// Function: props_storeFloatValue (FUN_68038ab0)
// Address: 68038ab0
// Size: 26 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_storeFloatValue(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  score_wrapColorObject(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_storeSymbolRef (FUN_68038ad0)
// Address: 68038ad0
// Size: 26 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_storeSymbolRef(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  props_transformRect(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_storeRectOp (FUN_68038af0)
// Address: 68038af0
// Size: 26 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_storeRectOp(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  props_computeRectOp(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_coerceToShort (FUN_68038b10)
// Address: 68038b10
// Size: 52 bytes
// Params: int param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceToShort(int param_1,uint *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = stage_unwrapHandle(param_1,(int *)param_2,param_3);
  if (iVar1 != 0) {
    return 0;
  }
  uVar2 = props_returnWithValue(param_1,0x80040bba,param_2);
  return uVar2;
}



// ============================================================
// Function: props_storeSymbolValue (FUN_68038b50)
// Address: 68038b50
// Size: 38 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_storeSymbolValue(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = stage_wrapHandle(param_1,param_2,param_3);
  return (-(uint)(iVar1 != 0) & 0x7ffbfffe) + 0x80040002;
}



// ============================================================
// Function: props_coerceToType (FUN_68038b80)
// Address: 68038b80
// Size: 81 bytes
// Params: int param_1, int param_2, short param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_coerceToType(int param_1,int param_2,short param_3,int *param_4)
{
  int iVar1;
  uint local_c;
  undefined4 local_8;
  
  iVar1 = (int)param_3;
  if (*(int *)(param_2 + 0x14) < iVar1) {
    props_returnWithValue(param_1,iVar1 + -0x7ffbf820,(uint *)0x0);
    return 0;
  }
  local_c = *(uint *)(*(int *)(param_2 + 0x18) + -8 + iVar1 * 8);
  local_8 = *(undefined4 *)(*(int *)(param_2 + 0x18) + -4 + iVar1 * 8);
  props_coerceAndReturnInt(param_1,&local_c,param_4);
  return 0;
}



// ============================================================
// Function: props_coerceToContextState (FUN_68038be0)
// Address: 68038be0
// Size: 81 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_coerceToContextState(int param_1,int param_2,short param_3)
{
  int iVar1;
  uint local_c;
  undefined4 local_8;
  
  iVar1 = (int)param_3;
  if (*(int *)(param_2 + 0x14) < iVar1) {
    props_returnWithValue(param_1,iVar1 + -0x7ffbf820,(uint *)0x0);
    return 0;
  }
  local_c = *(uint *)(*(int *)(param_2 + 0x18) + -8 + iVar1 * 8);
  local_8 = *(undefined4 *)(*(int *)(param_2 + 0x18) + -4 + iVar1 * 8);
  props_getContextState(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: props_coerceToRect (FUN_68038c40)
// Address: 68038c40
// Size: 81 bytes
// Params: int param_1, int param_2, short param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_coerceToRect(int param_1,int param_2,short param_3)
{
  int iVar1;
  uint local_c;
  undefined4 local_8;
  
  iVar1 = (int)param_3;
  if (*(int *)(param_2 + 0x14) < iVar1) {
    props_returnWithValue(param_1,iVar1 + -0x7ffbf820,(uint *)0x0);
    return 0;
  }
  local_c = *(uint *)(*(int *)(param_2 + 0x18) + -8 + iVar1 * 8);
  local_8 = *(undefined4 *)(*(int *)(param_2 + 0x18) + -4 + iVar1 * 8);
  props_createRectFromValue(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: props_getContextRef (FUN_68038ca0)
// Address: 68038ca0
// Size: 36 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getContextRef(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = cast_getContextRef(param_1);
  param_2[1] = iVar1;
  *param_2 = (iVar1 != 0) + 2;
  return 0;
}



// ============================================================
// Function: props_dispatchMethod (FUN_68038cd0)
// Address: 68038cd0
// Size: 9 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_dispatchMethod(undefined4 param_1,uint *param_2,undefined4 *param_3)
{
  score_dispatchMethodByCE(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_resolveRef (FUN_68038ce0)
// Address: 68038ce0
// Size: 9 bytes
// Params: undefined4 param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_resolveRef(undefined4 param_1,uint *param_2)
{
  score_resolveRefByDD(param_1,param_2);
  return 0;
}



// ============================================================
// Function: props_callMethodDirect (FUN_68038cf0)
// Address: 68038cf0
// Size: 9 bytes
// Params: undefined4 param_1, uint * param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_callMethodDirect(undefined4 param_1,uint *param_2,undefined4 param_3,int *param_4)
{
  score_callMethodByD3(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: props_callBuiltinDirect (FUN_68038d00)
// Address: 68038d00
// Size: 9 bytes
// Params: undefined4 param_1, int param_2, int param_3, byte * param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall props_callBuiltinDirect(undefined4 param_1,int param_2,int param_3,byte *param_4)
{
  props_callBuiltinMethod(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: props_resolveValue (FUN_68038d40)
// Address: 68038d40
// Size: 103 bytes
// Params: int param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_resolveValue(int param_1,uint *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int local_8;
  
  local_8 = 0;
  if ((*param_2 != 0x40) && (*param_2 != 0x43)) {
    return 0;
  }
  piVar1 = props_getApiContext((int *)param_2);
  props_getStringCharCount(param_1,param_2,&local_8);
  iVar2 = props_lookupSymbol(param_1,piVar1,local_8);
  props_getApiState((int *)param_2);
  props_releaseAndClear(param_1,(int *)param_2);
  uVar3 = props_storeObjectRef(param_1,iVar2,param_2);
  return uVar3;
}


