// Module: stage
// Topic: Comparison and relational operators
// Address range: 0x68050020 - 0x68050610
// Functions (10):
//   stage_compareValues (stage_compareValues)
//   stage_compareStrings (FUN_680501A0)
//   stage_compareLessThan (FUN_68050210)
//   stage_compareLessOrEqual (FUN_680502A0)
//   stage_compareNotEqual (FUN_68050330)
//   stage_compareEqual (FUN_680503C0)
//   stage_compareGreaterThan (FUN_68050450)
//   stage_compareGreaterOrEqual (FUN_680504E0)
//   stage_compareContains (FUN_68050570)
//   stage_compareStartsWith (FUN_68050610)

// ============================================================
// Function: stage_compareValues (FUN_68050020)
// Address: 68050020
// Size: 369 bytes
// Params: int param_1, int * param_2, int param_3, uint param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_compareValues(int param_1,int *param_2,int param_3,uint param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int extraout_EDX;
  int iVar4;
  int unaff_ESI;
  float10 fVar5;
  float10 fVar6;
  ulonglong uVar7;
  
  piVar1 = param_2;
  iVar4 = param_1;
  if (((param_1 != 0x40) && (param_1 != 0x43)) ||
     ((*(int *)(unaff_ESI + 0x1c) != 0x40 && (*(int *)(unaff_ESI + 0x1c) != 0x43)))) {
    iVar2 = props_getStringRef(unaff_ESI,&param_1);
    if ((iVar2 != 0) && (iVar2 = props_getStringRef(unaff_ESI,(int *)(unaff_ESI + 0x1c)), iVar2 != 0)) {
      if (param_1 == 0x20) {
        fVar5 = (float10)(float)(size_t)param_2;
        iVar4 = extraout_EDX;
      }
      else {
        iVar4 = *param_2;
        fVar5 = (float10)*(double *)(iVar4 + 8);
      }
      if (*(int *)(unaff_ESI + 0x1c) == 0x20) {
        fVar6 = (float10)*(float *)(unaff_ESI + 0x20);
      }
      else {
        fVar6 = (float10)*(double *)(**(int **)(unaff_ESI + 0x20) + 8);
      }
      fVar5 = fVar5 - fVar6;
      if (param_3 == 0) {
        fVar5 = (float10)Ordinal_1520((double)fVar5);
        if (fVar5 < (float10)1e-13) {
          fVar5 = (float10)0;
        }
      }
      else {
        if ((float10)0 <= fVar5) {
          if ((float10)0 < fVar5) {
            fVar5 = (float10)1;
          }
        }
        else {
          fVar5 = (float10)-1.0;
        }
        if (param_3 == 2) {
          uVar7 = strings_floatToUint64(2,iVar4);
          uVar3 = (uint)uVar7;
          goto LAB_6805015f;
        }
      }
      uVar3 = param_4;
      if ((float10)param_3 == fVar5) {
        uVar3 = param_4 ^ 1;
      }
      goto LAB_6805015f;
    }
    if (param_3 == 0) {
      if ((iVar4 == 2) || (*(int *)(unaff_ESI + 0x1c) == 2)) {
        uVar3 = piVar1 == *(int **)(unaff_ESI + 0x20) ^ param_4;
      }
      else {
        uVar3 = (piVar1 == *(int **)(unaff_ESI + 0x20) && iVar4 == *(int *)(unaff_ESI + 0x1c)) ^
                param_4;
      }
      goto LAB_6805015f;
    }
  }
  uVar3 = props_compareStrings(unaff_ESI,&param_1,(int *)(unaff_ESI + 0x1c),param_3,param_4);
LAB_6805015f:
  props_releaseValue(unaff_ESI,(byte)param_1,param_2);
  props_releaseValue(unaff_ESI,(byte)*(undefined4 *)(unaff_ESI + 0x1c),*(int **)(unaff_ESI + 0x20));
  *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
  *(uint *)(unaff_ESI + 0x20) = uVar3;
  *(undefined4 *)(unaff_ESI + 0x1c) = 4;
  return 0;
}



// ============================================================
// Function: stage_compareStrings (FUN_680501a0)
// Address: 680501a0
// Size: 104 bytes
// Params: int param_1, int param_2, int param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareStrings(int param_1,int param_2,int param_3,uint param_4)
{
  int *piVar1;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(param_2);
      return 0;
    }
    if (*piVar1 == 3) {
      score_dispatchFileOp(param_2);
      return 0;
    }
    stage_compareValues(*piVar1,(int *)piVar1[1],param_3,param_4);
  }
  return 0;
}



// ============================================================
// Function: stage_compareLessThan (FUN_68050210)
// Address: 68050210
// Size: 131 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareLessThan(int param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar2 = *piVar1;
    if ((iVar2 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      iVar2 = piVar1[1];
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(uint *)(param_1 + 0x20) = (uint)(iVar2 < *(int *)(param_1 + 0x20));
      return 0;
    }
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(0xc);
      return 0;
    }
    if (iVar2 == 3) {
      score_dispatchFileOp(0xc);
      return 0;
    }
    stage_compareValues(iVar2,(int *)piVar1[1],-1,0);
  }
  return 0;
}



// ============================================================
// Function: stage_compareLessOrEqual (FUN_680502a0)
// Address: 680502a0
// Size: 131 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareLessOrEqual(int param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar2 = *piVar1;
    if ((iVar2 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      iVar2 = piVar1[1];
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(uint *)(param_1 + 0x20) = (uint)(iVar2 <= *(int *)(param_1 + 0x20));
      return 0;
    }
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(0xd);
      return 0;
    }
    if (iVar2 == 3) {
      score_dispatchFileOp(0xd);
      return 0;
    }
    stage_compareValues(iVar2,(int *)piVar1[1],1,1);
  }
  return 0;
}



// ============================================================
// Function: stage_compareNotEqual (FUN_68050330)
// Address: 68050330
// Size: 131 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareNotEqual(int param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar2 = *piVar1;
    if ((iVar2 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      iVar2 = piVar1[1];
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(uint *)(param_1 + 0x20) = (uint)(iVar2 != *(int *)(param_1 + 0x20));
      return 0;
    }
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(0xe);
      return 0;
    }
    if (iVar2 == 3) {
      score_dispatchFileOp(0xe);
      return 0;
    }
    stage_compareValues(iVar2,(int *)piVar1[1],0,1);
  }
  return 0;
}



// ============================================================
// Function: stage_compareEqual (FUN_680503c0)
// Address: 680503c0
// Size: 131 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareEqual(int param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar2 = *piVar1;
    if ((iVar2 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      iVar2 = piVar1[1];
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(uint *)(param_1 + 0x20) = (uint)(iVar2 == *(int *)(param_1 + 0x20));
      return 0;
    }
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(0xf);
      return 0;
    }
    if (iVar2 == 3) {
      score_dispatchFileOp(0xf);
      return 0;
    }
    stage_compareValues(iVar2,(int *)piVar1[1],0,0);
  }
  return 0;
}



// ============================================================
// Function: stage_compareGreaterThan (FUN_68050450)
// Address: 68050450
// Size: 131 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareGreaterThan(int param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar2 = *piVar1;
    if ((iVar2 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      iVar2 = piVar1[1];
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(uint *)(param_1 + 0x20) = (uint)(*(int *)(param_1 + 0x20) < iVar2);
      return 0;
    }
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(0x10);
      return 0;
    }
    if (iVar2 == 3) {
      score_dispatchFileOp(0x10);
      return 0;
    }
    stage_compareValues(iVar2,(int *)piVar1[1],1,0);
  }
  return 0;
}



// ============================================================
// Function: stage_compareGreaterOrEqual (FUN_680504e0)
// Address: 680504e0
// Size: 131 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareGreaterOrEqual(int param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar2 = *piVar1;
    if ((iVar2 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      iVar2 = piVar1[1];
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(uint *)(param_1 + 0x20) = (uint)(*(int *)(param_1 + 0x20) <= iVar2);
      return 0;
    }
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(0x11);
      return 0;
    }
    if (iVar2 == 3) {
      score_dispatchFileOp(0x11);
      return 0;
    }
    stage_compareValues(iVar2,(int *)piVar1[1],-1,1);
  }
  return 0;
}



// ============================================================
// Function: stage_compareContains (FUN_68050570)
// Address: 68050570
// Size: 154 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareContains(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    iVar2 = *(int *)(param_1 + 0x18);
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + iVar2);
    iVar3 = *piVar1;
    if ((iVar3 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      if (*(int *)(param_1 + 0x20) < piVar1[1]) {
        *(undefined4 *)(param_1 + 0x20) = 1;
        *(int *)(param_1 + 0x18) = iVar2 + -8;
        return 0;
      }
      *(uint *)(param_1 + 0x20) = -(uint)(piVar1[1] != *(int *)(param_1 + 0x20));
      *(int *)(param_1 + 0x18) = iVar2 + -8;
      return 0;
    }
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(0x24);
      return 0;
    }
    if (iVar3 == 3) {
      score_dispatchFileOp(0x24);
      return 0;
    }
    stage_compareValues(iVar3,(int *)piVar1[1],2,0);
  }
  return 0;
}



// ============================================================
// Function: stage_compareStartsWith (FUN_68050610)
// Address: 68050610
// Size: 154 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareStartsWith(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    iVar2 = *(int *)(param_1 + 0x18);
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + iVar2);
    iVar3 = *piVar1;
    if ((iVar3 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      if (*(int *)(param_1 + 0x20) < piVar1[1]) {
        *(undefined4 *)(param_1 + 0x20) = 1;
        *(int *)(param_1 + 0x18) = iVar2 + -8;
        return 0;
      }
      *(uint *)(param_1 + 0x20) = -(uint)(piVar1[1] != *(int *)(param_1 + 0x20));
      *(int *)(param_1 + 0x18) = iVar2 + -8;
      return 0;
    }
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(0x25);
      return 0;
    }
    if (iVar3 == 3) {
      score_dispatchFileOp(0x25);
      return 0;
    }
    stage_compareValues(iVar3,(int *)piVar1[1],2,0);
  }
  return 0;
}



