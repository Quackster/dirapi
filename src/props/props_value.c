// Module: props
// Topic: Value retain, release, coerce, store, compare
// Address range: 0x68030b90 - 0x6803adf0
// Functions (24):
//   props_floatToLongLong (FUN_68030b90)
//   props_coerceToInt (FUN_68030bd0)
//   props_coerceToFloat (FUN_68030ca0)
//   props_getReturnTarget (FUN_680312c0)
//   props_freeHandleAndDeref (FUN_680312e0)
//   props_setVoidValue (FUN_680313c0)
//   props_releaseObject (FUN_68031440)
//   props_releaseValue (FUN_68031470)
//   props_clearValue (FUN_680314c0)
//   props_retainValue (FUN_680314f0)
//   props_retainObject (FUN_68031640)
//   props_setReturnValue (FUN_68031d20)
//   props_isIntegerFloat (FUN_68037bb0)
//   props_storeNumber (FUN_68037be0)
//   props_returnWithValue (FUN_68037c30)
//   props_returnSymbol (FUN_68037c50)
//   props_retainValueCallback (FUN_68038150)
//   props_isRefCounted (FUN_68038170)
//   props_releaseAndClear (FUN_68038180)
//   props_zeroValue (FUN_680381c0)
//   props_convertValue
//   props_compareValues (FUN_6803a6a0)
//   props_binarySearch (FUN_6803ad30)
//   props_linearSearch (FUN_6803adf0)



// ============================================================
// Function: props_floatToLongLong
// Address: 68030b90
// Size: 49 bytes
// Params: undefined4 param_1, undefined4 param_2, double param_3
// Return: ulonglong
// Calling convention: __fastcall
// ============================================================

ulonglong __fastcall props_floatToLongLong(undefined4 param_1,undefined4 param_2,double param_3)

{
  ulonglong uVar1;
  
  if (0.0 <= param_3) {
    uVar1 = strings_floatToUint64(param_1,param_2);
    return uVar1;
  }
  uVar1 = strings_floatToUint64(param_1,param_2);
  return uVar1;
}



// ============================================================
// Function: props_coerceToInt
// Address: 68030bd0
// Size: 208 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceToInt(int param_1,int *param_2,int *param_3)

{
  float fVar1;
  int iVar2;
  ulonglong uVar3;
  
  iVar2 = *param_2;
  if (iVar2 == 4) {
    *param_3 = param_2[1];
    return 1;
  }
  if ((iVar2 != 0x20) && (iVar2 != 0x23)) {
    if (iVar2 == 2) {
      *param_3 = 0;
      return 1;
    }
    if ((iVar2 == 3) &&
       (iVar2 = (**(code **)(**(int **)param_2[1] + 0x14))(param_1,(undefined4 *)param_2[1],param_3)
       , iVar2 != 0)) {
      return 1;
    }
    return 0;
  }
  if (-1 < *(int *)(param_1 + 0xd4)) {
    if (iVar2 == 0x20) {
      fVar1 = (float)(size_t)param_2[1];
    }
    else {
      param_2 = *(int **)param_2[1];
      fVar1 = (float)*(double *)(param_2 + 2);
    }
    uVar3 = props_floatToLongLong(param_2,param_1,(double)fVar1);
    *param_3 = (int)uVar3;
    return 1;
  }
  if (iVar2 != 0x20) {
    uVar3 = strings_floatToUint64(*(undefined4 *)param_2[1],param_1);
    *param_3 = (int)uVar3;
    return 1;
  }
  uVar3 = strings_floatToUint64(param_2,param_1);
  *param_3 = (int)uVar3;
  return 1;
}



// ============================================================
// Function: props_coerceToFloat
// Address: 68030ca0
// Size: 153 bytes
// Params: undefined4 param_1, int * param_2, double * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceToFloat(undefined4 param_1,int *param_2,double *param_3)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (iVar1 == 4) {
    *param_3 = (double)param_2[1];
    return 1;
  }
  if (iVar1 == 0x20) {
    *param_3 = (double)(float)(size_t)param_2[1];
    return 1;
  }
  if (iVar1 == 0x23) {
    *param_3 = *(double *)(*(int *)param_2[1] + 8);
    return 1;
  }
  if (iVar1 == 2) {
    *param_3 = 0.0;
    return 1;
  }
  if (iVar1 == 3) {
    iVar1 = (**(code **)(**(int **)param_2[1] + 0x14))(param_1,(undefined4 *)param_2[1],&param_2);
    if (iVar1 != 0) {
      *param_3 = (double)(int)param_2;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: props_getReturnTarget
// Address: 680312c0
// Size: 20 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getReturnTarget(int param_1)

{
  *(undefined4 *)(param_1 + 0x74) = 3;
  return *(undefined4 *)(param_1 + 0x40);
}



// ============================================================
// Function: props_freeHandleAndDeref (FUN_680312e0)
// Address: 680312e0
// Size: 29 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_freeHandleAndDeref(int param_1,undefined4 param_2)
{
  int local_c;
  cast_freeHandle(param_2);
  if (param_1 != 0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  }
  return 0;
}



// ============================================================
// Function: props_setVoidValue (FUN_680313c0)
// Address: 680313c0
// Size: 39 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_setVoidValue(undefined4 *param_1)
{
  int local_c [2];
  
  local_c[0] = 2;
  local_c[1] = 0;
  stage_serializeFloat(param_1,local_c);
  return 0;
}



// ============================================================
// Function: props_releaseObject (FUN_68031440)
// Address: 68031440
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_releaseObject(undefined4 param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  
  if ((param_2 != (int *)0x0) &&
     (iVar2 = *param_2, piVar1 = (int *)(iVar2 + 4), *piVar1 = *piVar1 + -1, *(int *)(iVar2 + 4) < 1
     )) {
    (**(code **)(*(int *)*param_2 + 0xc))(param_1,param_2);
  }
  return 0;
}



// ============================================================
// Function: props_releaseValue (FUN_68031470)
// Address: 68031470
// Size: 69 bytes
// Params: undefined4 ctx, byte typeTag, int *valuePtr
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_releaseValue(undefined4 ctx,byte typeTag,int *valuePtr)
{
  int *refCountPtr;
  int objHeader;

  if (valuePtr == NULL) return 0;

  if ((typeTag & 0x1f) == 3) {
    /* Object type � decrement refcount, destroy if zero */
    objHeader = *valuePtr;
    refCountPtr = (int *)(objHeader + 4);
    *refCountPtr = *refCountPtr - 1;
    if (*(int *)(objHeader + 4) < 1) {
      (**(code **)(*(int *)*valuePtr + 0xc))(ctx, valuePtr);
      return 0;
    }
  }
  else if ((typeTag & 1) != 0) {
    /* Handle type � free the handle */
    cast_freeHandle(valuePtr);
  }

  return 0;
}



// ============================================================
// Function: props_clearValue (FUN_680314c0)
// Address: 680314c0
// Size: 34 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_clearValue(undefined4 param_1,undefined4 *param_2)
{
  props_releaseValue(param_1,(byte)*param_2,(int *)param_2[1]);
  *param_2 = 0;
  return 0;
}



// ============================================================
// Function: props_retainValue (FUN_680314f0)
// Address: 680314f0
// Size: 82 bytes
// Params: int ctx, uint *valuePair
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_retainValue(int ctx,uint *valuePair)
{
  int *objPtr;
  uint copiedHandle;

  if (valuePair == NULL) return 0;

  objPtr = (int *)valuePair[1];
  if (objPtr == NULL) return 0;

  if (((byte)*valuePair & 0x1f) == 3) {
    /* Object type � increment refcount */
    *(int *)(*objPtr + 4) = *(int *)(*objPtr + 4) + 1;
    return 0;
  }

  if ((*valuePair & 1) != 0) {
    /* Handle type � duplicate the handle */
    copiedHandle = Ordinal_1120(objPtr, 0);
    valuePair[1] = copiedHandle;
    if (copiedHandle == 0) {
      *valuePair = 2;
      props_setError(ctx, 2);
    }
  }

  return 0;
}



// ============================================================
// Function: props_retainObject (FUN_68031640)
// Address: 68031640
// Size: 15 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_retainObject(undefined4 param_1,int *param_2)
{
  *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
  return 0;
}



// ============================================================
// Function: props_setReturnValue (FUN_68031d20)
// Address: 68031d20
// Size: 72 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_setReturnValue(int param_1,uint *param_2)
{
  if ((param_2 != (uint *)0x0) && (*(int *)(param_1 + 0x7c) != 2)) {
    props_releaseValue(param_1,(byte)*(undefined4 *)(param_1 + 0x80),*(int **)(param_1 + 0x84));
    *(uint *)(param_1 + 0x80) = *param_2;
    *(uint *)(param_1 + 0x84) = param_2[1];
    props_retainValue(param_1,(uint *)(param_1 + 0x80));
  }
  return 0;
}



// ============================================================
// Function: props_isIntegerFloat
// Address: 68037bb0
// Size: 33 bytes
// Params: float param_1, double param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_isIntegerFloat(float param_1,double param_2)

{
  if ((float)(size_t)param_2 == param_1) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_storeNumber
// Address: 68037be0
// Size: 78 bytes
// Params: int param_1, double param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_storeNumber(int param_1,double param_2,undefined4 *param_3)
{
  float fVar1;
  int iVar2;
  
  fVar1 = (float)(size_t)param_2;
  iVar2 = props_isIntegerFloat(fVar1,(double)fVar1);
  if (iVar2 != 0) {
    *param_3 = 0x20;
    param_3[1] = fVar1;
    return 0;
  }
  stage_allocNumberHandle(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_returnWithValue
// Address: 68037c30
// Size: 27 bytes
// Params: int param_1, undefined4 param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_returnWithValue(int param_1,undefined4 param_2,uint *param_3)

{
  if (param_3 != (uint *)0x0) {
    props_setReturnValue(param_1,param_3);
  }
  return param_2;
}



// ============================================================
// Function: props_returnSymbol
// Address: 68037c50
// Size: 41 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_returnSymbol(int param_1,undefined4 param_2,undefined4 param_3)

{
  uint local_c;
  undefined4 local_8;
  
  local_c = 8;
  local_8 = param_3;
  props_setReturnValue(param_1,&local_c);
  return param_2;
}



// ============================================================
// Function: props_retainValueCallback
// Address: 68038150
// Size: 22 bytes
// Params: undefined4 param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_retainValueCallback(undefined4 param_1,uint *param_2)

{
  props_retainValue(param_1,param_2);
  return 0;
}



// ============================================================
// Function: props_isRefCounted
// Address: 68038170
// Size: 9 bytes
// Params: int * param_1
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall props_isRefCounted(int *param_1)

{
  return *param_1 < 0x72;
}



// ============================================================
// Function: props_releaseAndClear
// Address: 68038180
// Size: 54 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_releaseAndClear(undefined4 param_1,int *param_2)

{
  bool bVar1;
  
  bVar1 = props_isRefCounted(param_2);
  if (bVar1) {
    props_releaseValue(param_1,(byte)*param_2,(int *)param_2[1]);
    *param_2 = 0;
    param_2[1] = 0;
  }
  return 0;
}



// ============================================================
// Function: props_zeroValue
// Address: 680381c0
// Size: 25 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_zeroValue(undefined4 param_1,undefined4 *param_2)

{
  *param_2 = 0;
  param_2[1] = 0;
  return 0;
}



// ============================================================
// Function: props_convertValue (FUN_6803a520)
// Address: 6803a520
// Size: 289 bytes
// Params: undefined4 param_1, int param_2, int * param_3, int param_4, int * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint props_convertValue(undefined4 param_1,int param_2,int *param_3,int param_4,int *param_5)

{
  double dVar1;
  double dVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int local_c;
  int local_8;
  
  if (param_2 == param_4) {
    if (param_3 == param_5) {
      return 0;
    }
    switch(param_2) {
    case 1:
    case 0x40:
    case 0x43:
      piVar3 = props_getStringData(&param_2,&local_8);
      piVar4 = props_getStringData(&param_4,&local_c);
      uVar6 = local_8 - local_c;
      if ((uVar6 == 0) && (0 < local_8)) {
        iVar5 = (int)piVar4 - (int)piVar3;
        do {
          if (uVar6 != 0) break;
          local_8 = local_8 + -1;
          uVar6 = (int)(char)*piVar3 - (int)*(char *)(iVar5 + (int)piVar3);
          piVar3 = (int *)((int)piVar3 + 1);
        } while (0 < local_8);
      }
      props_unlockString(&param_2);
      props_unlockString(&param_4);
      break;
    default:
      if ((int)param_3 < (int)param_5) {
        return 0xffffffff;
      }
      uVar6 = (uint)((int)param_5 < (int)param_3);
      break;
    case 9:
    case 0x20:
    case 0x23:
      if (param_2 == 0x20) {
        dVar1 = (double)(float)(size_t)param_3; /* FIXUP(C2440): int* reinterpreted as float via size_t */
      }
      else {
        dVar1 = *(double *)(*param_3 + 8);
      }
      if (param_4 == 0x20) {
        dVar2 = (double)(float)(size_t)param_5; /* FIXUP(C2440): int* reinterpreted as float via size_t */
      }
      else {
        dVar2 = *(double *)(*param_5 + 8);
      }
      if (0.0 <= dVar1 - dVar2) {
        if (dVar1 - dVar2 <= 0.0) {
          return 0;
        }
        return 1;
      }
      return 0xffffffff;
    }
  }
  else {
    uVar6 = (int)param_3 - (int)param_5;
  }
  if ((int)uVar6 < 0) {
    return 0xffffffff;
  }
  if (0 < (int)uVar6) {
    uVar6 = 1;
  }
  return uVar6;
}



// ============================================================
// Function: props_compareValues
// Address: 6803a6a0
// Size: 1226 bytes
// Params: int param_1, uint param_2, int * param_3, uint param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_compareValues(int param_1,uint param_2,int *param_3,uint param_4,int *param_5)
{
  uint *puVar1;
  double dVar2;
  double dVar3;
  ushort uVar4;
  ushort uVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  int local_820;
  int local_81c;
  uint local_818;
  int *local_814;
  uint local_810;
  int *local_80c;
  byte local_808;
  undefined1 local_807 [1023];
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_818 = param_2;
  local_814 = param_3;
  local_810 = param_4;
  local_80c = param_5;
  switch(param_2) {
  case 1:
  case 0x40:
  case 0x43:
    switch(param_4) {
    case 1:
    case 0x40:
    case 0x43:
      piVar6 = props_getStringData((int *)&local_818,&local_81c);
      piVar7 = props_getStringData((int *)&local_810,&local_820);
      Ordinal_967((int)piVar6,(int)piVar7,local_81c,local_820);
      props_unlockString((int *)&local_818);
      props_unlockString((int *)&local_810);
      return 0;
    default:
      goto switchD_6803a6f0_caseD_2;
    case 4:
      props_toPascalString((int *)&local_818,&local_808);
      Ordinal_951(local_80c,&local_408);
      break;
    case 8:
      props_toPascalString((int *)&local_818,&local_808);
LAB_6803a98e:
      score_lookupSymbol(DAT_68196304,(int)local_80c,(int)&local_408);
      break;
    case 9:
    case 0x20:
    case 0x23:
      props_toPascalString((int *)&local_818,&local_808);
      piVar6 = local_80c;
      if (local_810 != 0x20) {
        /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): piVar6 = (int *)(float)*(double *)(*local_80c + 8); */
      }
      props_formatDouble(param_1,(double)(float)(size_t)piVar6,&local_408);
    }
LAB_6803a993:
    if (local_408 == 0xff) {
      uVar4 = Ordinal_1201(local_407);
    }
    else {
      uVar4 = (ushort)local_408;
    }
    if (local_808 == 0xff) {
      uVar5 = Ordinal_1201(local_807);
    }
    else {
      uVar5 = (ushort)local_808;
    }
    Ordinal_967((int)local_807,(int)local_407,(int)(short)uVar5,(int)(short)uVar4);
    return 0;
  case 4:
    switch(param_4) {
    case 1:
    case 0x40:
    case 0x43:
      Ordinal_951(param_3,&local_808);
      props_toPascalString((int *)&local_810,&local_408);
      goto LAB_6803a993;
    default:
      break;
    case 4:
      goto switchD_6803a70a_caseD_4;
    case 8:
      Ordinal_951(param_3,&local_808);
      goto LAB_6803a98e;
    case 9:
    case 0x20:
    case 0x23:
      dVar2 = (double)(int)param_3;
switchD_6803a780_caseD_9:
      if (param_4 == 0x20) {
        dVar3 = (double)(float)(size_t)param_5;
      }
      else {
        dVar3 = *(double *)(*param_5 + 8);
      }
LAB_6803a794:
      if (0.0 <= dVar2 - dVar3) {
        if (0.0 < dVar2 - dVar3) {
          return 0;
        }
        return 0;
      }
      goto LAB_6803a7a5;
    }
  case 8:
    score_lookupSymbol(DAT_68196304,(int)param_3,(int)&local_808);
    switch(local_810) {
    case 1:
    case 0x40:
    case 0x43:
      props_toPascalString((int *)&local_810,&local_408);
      break;
    default:
      goto switchD_6803a6f0_caseD_2;
    case 4:
      Ordinal_951(local_80c,&local_408);
      break;
    case 8:
      goto LAB_6803a98e;
    case 9:
    case 0x20:
    case 0x23:
      piVar6 = local_80c;
      if (local_810 != 0x20) {
        /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): piVar6 = (int *)(float)*(double *)(*local_80c + 8); */
      }
      props_formatDouble(param_1,(double)(float)(size_t)piVar6,&local_408);
    }
    goto LAB_6803a993;
  case 9:
  case 0x20:
  case 0x23:
    if (param_2 == 0x20) {
      dVar2 = (double)(float)(size_t)param_3;
    }
    else {
      dVar2 = *(double *)(*param_3 + 8);
    }
    switch(param_4) {
    case 1:
    case 0x40:
    case 0x43:
      props_formatDouble(param_1,dVar2,&local_808);
      props_toPascalString((int *)&local_810,&local_408);
      goto LAB_6803a993;
    default:
      break;
    case 4:
      dVar3 = (double)(int)param_5;
      goto LAB_6803a794;
    case 8:
      props_formatDouble(param_1,dVar2,&local_808);
      goto LAB_6803a98e;
    case 9:
    case 0x20:
    case 0x23:
      goto switchD_6803a780_caseD_9;
    }
  }
switchD_6803a6f0_caseD_2:
  if (local_818 != local_810) {
    return 0;
  }
  iVar8 = stage_isContextType(param_1,(int *)&local_818);
  if ((iVar8 == 0) || (iVar8 = stage_isContextType(param_1,(int *)&local_810), iVar8 == 0)) {
    props_pushValue(param_1);
    puVar1 = (uint *)(param_1 + 0x1c);
    *puVar1 = local_818;
    *(int **)(param_1 + 0x20) = local_814;
    if ((local_818 & 1) != 0) {
      props_retainValue(param_1,puVar1);
    }
    props_pushValue(param_1);
    *puVar1 = local_810;
    *(int **)(param_1 + 0x20) = local_80c;
    if ((local_810 & 1) != 0) {
      props_retainValue(param_1,puVar1);
    }
    stage_compareContains(param_1);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    iVar8 = **(int **)(param_1 + 0x10);
    *puVar1 = *(uint *)(iVar8 + *(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar8 + 4 + *(int *)(param_1 + 0x18));
    return 0;
  }
switchD_6803a70a_caseD_4:
  if ((int)local_80c <= (int)local_814) {
    return 0;
  }
LAB_6803a7a5:
  return 0;
}



// ============================================================
// Function: props_binarySearch
// Address: 6803ad30
// Size: 183 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_binarySearch(undefined4 param_1,int *param_2,undefined4 *param_3,int *param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_8;
  
  pcVar1 = *(code **)(*param_2 + 0x24);
  iVar3 = 0;
  iVar5 = *(int *)(*param_2 + 0x10) + -1;
  local_8 = 0;
  iVar4 = -1;
  if (-1 < iVar5) {
    do {
      iVar4 = (iVar5 - iVar3 >> 1) + iVar3;
      iVar2 = (*pcVar1)(param_1,*param_3,param_3[1],*(undefined4 *)(*param_2 + 0x28 + iVar4 * 8),
                        *(undefined4 *)(*param_2 + 0x2c + iVar4 * 8));
      if (iVar2 == 0) {
        local_8 = 1;
        if (iVar4 < 1) goto LAB_6803ad91;
        iVar3 = iVar4 * 8 + 0x20;
        goto LAB_6803adc0;
      }
      if (iVar2 < 1) {
        iVar5 = iVar4 + -1;
      }
      else {
        iVar3 = iVar4 + 1;
      }
    } while (iVar3 <= iVar5);
    if (iVar2 < 1) goto LAB_6803ad91;
  }
  iVar4 = iVar4 + 1;
  goto LAB_6803ad91;
  while( true ) {
    iVar4 = iVar4 + -1;
    iVar3 = iVar3 + -8;
    if (iVar4 < 1) break;
LAB_6803adc0:
    iVar5 = (*pcVar1)(param_1,*param_3,param_3[1],*(undefined4 *)(*param_2 + iVar3),
                      *(undefined4 *)(*param_2 + 4 + iVar3));
    if (iVar5 != 0) break;
  }
LAB_6803ad91:
  if (param_4 != (int *)0x0) {
    *param_4 = iVar4;
  }
  return local_8;
}



// ============================================================
// Function: props_linearSearch
// Address: 6803adf0
// Size: 193 bytes
// Params: undefined4 param_1, int * param_2, byte * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_linearSearch(undefined4 param_1,int *param_2,byte *param_3,int *param_4)

{
  code *pcVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = 0;
  if ((*param_3 & 1) != 0) {
    iVar3 = stage_isContextType(param_1,(int *)param_3);
    bVar2 = false;
    if (iVar3 == 0) goto LAB_6803ae1b;
  }
  bVar2 = true;
LAB_6803ae1b:
  pcVar1 = *(code **)(*param_2 + 0x24);
  iVar3 = *(int *)(*param_2 + 0x10);
  if (0 < iVar3) {
    iVar5 = 0x28;
    do {
      iVar4 = *param_2;
      if ((bVar2) && (*(int *)param_3 == *(int *)(iVar4 + iVar5))) {
        if (*(int *)(param_3 + 4) == *(int *)(iVar4 + 4 + iVar5)) {
          *param_4 = iVar6;
          return 1;
        }
      }
      else {
        iVar4 = (*pcVar1)(param_1,*(undefined4 *)(iVar4 + iVar5),((undefined4 *)(iVar4 + iVar5))[1],
                          *(undefined4 *)param_3,*(undefined4 *)(param_3 + 4));
        if (iVar4 == 0) {
          *param_4 = iVar6;
          return 1;
        }
      }
      iVar6 = iVar6 + 1;
      iVar5 = iVar5 + 8;
    } while (iVar6 < iVar3);
  }
  *param_4 = -1;
  return 0;
}


