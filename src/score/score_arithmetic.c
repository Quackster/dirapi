// Module: score
// Topic: Core arithmetic dispatch (mul/add/sub/div/mod/neg)
// Address range: 0x6804f3e0 - 0x6804f9e0
// Functions (9):
//   score_computeArithmetic
//   score_multiply
//   score_add
//   score_subtract
//   score_divide
//   score_moduloCoerce
//   score_modulo
//   score_negateValue
//   score_negate

// ============================================================
// Function: score_computeArithmetic (FUN_6804f3e0)
// Address: 6804f3e0
// Size: 475 bytes
// Params: int param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_computeArithmetic(int param_1,int param_2,int param_3,int *param_4)
{
  int *piVar1;
  double dVar2;
  double dVar3;
  int iVar4;
  
  if (param_3 == 3) {
    score_dispatchFileOp(param_2);
    return 0;
  }
  piVar1 = (int *)(param_1 + 0x1c);
  if (*(int *)(param_1 + 0x1c) == 3) {
    score_dispatchFileOp(param_2);
    return 0;
  }
  iVar4 = props_coerceStringPair(param_1,&param_3,piVar1);
  if (iVar4 == 0) {
    props_releaseValue(param_1,(byte)param_3,param_4);
    props_releaseValue(param_1,(byte)*piVar1,*(int **)(param_1 + 0x20));
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    *piVar1 = 4;
    switch(param_2) {
    case 4:
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) * (int)param_4;
      return 0;
    case 5:
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + (int)param_4;
      return 0;
    case 6:
      *(int *)(param_1 + 0x20) = (int)param_4 - *(int *)(param_1 + 0x20);
      return 0;
    case 7:
      if (*(int *)(param_1 + 0x20) == 0) {
        props_setError(param_1,6);
        return 0;
      }
      *(int *)(param_1 + 0x20) = (int)param_4 / *(int *)(param_1 + 0x20);
    }
    return 0;
  }
  switch(param_2) {
  case 4:
    if (param_3 == 0x20) {
      dVar3 = (double)(float)(size_t)param_4;
    }
    else {
      dVar3 = *(double *)(*param_4 + 8);
    }
    if (*piVar1 == 0x20) {
      dVar3 = (double)*(float *)(param_1 + 0x20) * dVar3;
    }
    else {
      dVar3 = *(double *)(**(int **)(param_1 + 0x20) + 8) * dVar3;
    }
    break;
  case 5:
    if (param_3 == 0x20) {
      dVar3 = (double)(float)(size_t)param_4;
    }
    else {
      dVar3 = *(double *)(*param_4 + 8);
    }
    if (*piVar1 == 0x20) {
      dVar3 = (double)*(float *)(param_1 + 0x20) + dVar3;
    }
    else {
      dVar3 = *(double *)(**(int **)(param_1 + 0x20) + 8) + dVar3;
    }
    break;
  case 6:
    if (param_3 == 0x20) {
      dVar3 = (double)(float)(size_t)param_4;
    }
    else {
      dVar3 = *(double *)(*param_4 + 8);
    }
    if (*piVar1 == 0x20) {
      dVar3 = dVar3 - (double)*(float *)(param_1 + 0x20);
    }
    else {
      dVar3 = dVar3 - *(double *)(**(int **)(param_1 + 0x20) + 8);
    }
    break;
  case 7:
    if (*piVar1 == 0x20) {
      dVar2 = (double)*(float *)(param_1 + 0x20);
    }
    else {
      dVar2 = *(double *)(**(int **)(param_1 + 0x20) + 8);
    }
    if (dVar2 == 0.0) {
      props_setError(param_1,6);
      goto switchD_6804f447_default;
    }
    if (param_3 == 0x20) {
      dVar3 = (double)(float)(size_t)param_4;
    }
    else {
      dVar3 = *(double *)(*param_4 + 8);
    }
    dVar3 = dVar3 / dVar2;
    break;
  default:
    goto switchD_6804f447_default;
  }
  score_storeNumericResult(dVar3);
switchD_6804f447_default:
  if (param_3 != 0x20) {
    props_releaseValue(param_1,(byte)param_3,param_4);
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  return 0;
}


// ============================================================
// Function: score_multiply (FUN_6804f5e0)
// Address: 6804f5e0
// Size: 85 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_multiply(int param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    iVar2 = *(int *)(param_1 + 0x18);
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + iVar2);
    if ((*(int *)(**(int **)(param_1 + 0x10) + -8 + iVar2) == 4) && (*(int *)(param_1 + 0x1c) == 4))
    {
      *(int *)(param_1 + 0x20) = piVar1[1] * *(int *)(param_1 + 0x20);
      *(int *)(param_1 + 0x18) = iVar2 + -8;
      return 0;
    }
    score_computeArithmetic(param_1,4,*piVar1,(int *)piVar1[1]);
  }
  return 0;
}


// ============================================================
// Function: score_add (FUN_6804f640)
// Address: 6804f640
// Size: 88 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_add(int param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    iVar2 = *(int *)(param_1 + 0x18);
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + iVar2);
    if ((*(int *)(**(int **)(param_1 + 0x10) + -8 + iVar2) == 4) && (*(int *)(param_1 + 0x1c) == 4))
    {
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + piVar1[1];
      *(undefined4 *)(param_1 + 0x1c) = 4;
      *(int *)(param_1 + 0x18) = iVar2 + -8;
      return 0;
    }
    score_computeArithmetic(param_1,5,*piVar1,(int *)piVar1[1]);
  }
  return 0;
}


// ============================================================
// Function: score_subtract (FUN_6804f6a0)
// Address: 6804f6a0
// Size: 84 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_subtract(int param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    iVar2 = *(int *)(param_1 + 0x18);
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + iVar2);
    if ((*(int *)(**(int **)(param_1 + 0x10) + -8 + iVar2) == 4) && (*(int *)(param_1 + 0x1c) == 4))
    {
      *(int *)(param_1 + 0x20) = piVar1[1] - *(int *)(param_1 + 0x20);
      *(int *)(param_1 + 0x18) = iVar2 + -8;
      return 0;
    }
    score_computeArithmetic(param_1,6,*piVar1,(int *)piVar1[1]);
  }
  return 0;
}


// ============================================================
// Function: score_divide (FUN_6804f700)
// Address: 6804f700
// Size: 109 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_divide(int param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    if ((*(int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18)) == 4) &&
       (*(int *)(param_1 + 0x1c) == 4)) {
      if (*(int *)(param_1 + 0x20) == 0) {
        props_setError(param_1,6);
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
        return 0;
      }
      iVar2 = piVar1[1];
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(int *)(param_1 + 0x20) = iVar2 / *(int *)(param_1 + 0x20);
      return 0;
    }
    score_computeArithmetic(param_1,7,*piVar1,(int *)piVar1[1]);
  }
  return 0;
}


// ============================================================
// Function: score_moduloCoerce (FUN_6804f770)
// Address: 6804f770
// Size: 293 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_moduloCoerce(int param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar4 = param_1;
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (iVar3 = *(int *)(param_1 + 0x40) + 0x34, iVar3 <= *(int *)(param_1 + 0x18))) {
    _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    local_c = DAT_6819776c;
    local_10 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_c = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_10 = *(int *)(size_t)_DAT_68197764;
    }
    piVar1 = (int *)(param_1 + 0x1c);
    if (*(int *)(param_1 + 0x1c) == 3) {
      iVar4 = score_dispatchFileOp(8);
      return iVar4;
    }
    if (local_10 == 3) {
      iVar4 = score_dispatchFileOp(8);
      return iVar4;
    }
    iVar3 = props_coerceToInt(param_1,&local_10,&local_8);
    if ((iVar3 != 0) && (iVar3 = props_coerceToInt(iVar4,piVar1,&param_1), iVar3 != 0)) {
      props_popValue(iVar4);
      props_popValue(iVar4);
      iVar3 = props_pushValue(iVar4);
      if (param_1 == 0) {
        *(undefined4 *)(iVar4 + 0x20) = 0;
        return iVar3;
      }
      *(int *)(iVar4 + 0x20) = local_8 % param_1;
      return local_8 / param_1;
    }
    props_releaseValue(iVar4,(byte)local_10,local_c);
    iVar3 = props_releaseValue(iVar4,(byte)*piVar1,*(int **)(iVar4 + 0x20));
    iVar2 = *(int *)(iVar4 + 0x20);
    *piVar1 = 4;
    if (iVar2 != 0) {
      iVar3 = (int)local_c / iVar2;
      *(int *)(iVar4 + 0x20) = (int)local_c % iVar2;
    }
    *(int *)(iVar4 + 0x18) = *(int *)(iVar4 + 0x18) + -8;
  }
  return iVar3;
}


// ============================================================
// Function: score_modulo (FUN_6804f8a0)
// Address: 6804f8a0
// Size: 123 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_modulo(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (iVar1 = *(int *)(param_1 + 0x40) + 0x34, iVar1 <= *(int *)(param_1 + 0x18))) {
    _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar1 = DAT_6819776c;
    iVar3 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      iVar1 = ((int *)(size_t)_DAT_68197764)[1];
      iVar3 = *(int *)(size_t)_DAT_68197764;
    }
    if ((iVar3 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      iVar3 = *(int *)(param_1 + 0x20);
      iVar2 = iVar1;
      if (iVar3 != 0) {
        iVar2 = iVar1 / iVar3;
        *(int *)(param_1 + 0x20) = iVar1 % iVar3;
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      return iVar2;
    }
    iVar1 = score_moduloCoerce(param_1);
  }
  return iVar1;
}


// ============================================================
// Function: score_negateValue (FUN_6804f920)
// Address: 6804f920
// Size: 186 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_negateValue(int param_1)
{
  byte *pbVar1;
  undefined4 uVar2;
  int iVar3;
  
  pbVar1 = (byte *)(param_1 + 0x1c);
  if (*(int *)(param_1 + 0x1c) == 3) {
    uVar2 = *(undefined4 *)(param_1 + 0x20);
    iVar3 = *(int *)pbVar1;
    pbVar1[0] = 4;
    pbVar1[1] = 0;
    pbVar1[2] = 0;
    pbVar1[3] = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
    props_pushValue(param_1);
    *(undefined4 *)(param_1 + 0x20) = uVar2;
    *(int *)pbVar1 = iVar3;
    score_dispatchFileOp(6);
    return 0;
  }
  iVar3 = props_getStringRef(param_1,(int *)pbVar1);
  if (iVar3 != 0) {
    if (*(int *)pbVar1 == 0x20) {
      score_storeNumericResult((double)-*(float *)(param_1 + 0x20));
      return 0;
    }
    score_storeNumericResult(-*(double *)(**(int **)(param_1 + 0x20) + 8));
    return 0;
  }
  if ((*pbVar1 & 1) != 0) {
    props_releaseValue(param_1,(byte)*(int *)pbVar1,*(int **)(param_1 + 0x20));
  }
  *(int *)(param_1 + 0x20) = -*(int *)(param_1 + 0x20);
  pbVar1[0] = 4;
  pbVar1[1] = 0;
  pbVar1[2] = 0;
  pbVar1[3] = 0;
  return 0;
}


// ============================================================
// Function: score_negate (FUN_6804f9e0)
// Address: 6804f9e0
// Size: 34 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_negate(int param_1)
{
  if (*(int *)(param_1 + 0x1c) == 4) {
    *(int *)(param_1 + 0x20) = -*(int *)(param_1 + 0x20);
    return 0;
  }
  score_negateValue(param_1);
  return 0;
}


