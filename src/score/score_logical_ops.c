// Module: score
// Topic: Logical/comparison operations (and/or/not/concat)
// Address range: 0x6804fa10 - 0x6804fe90
// Functions (7):
//   score_logicalAndCoerce (FUN_6804fa10)
//   score_logicalAnd (FUN_6804fae0)
//   score_logicalOrCoerce (FUN_6804fb70)
//   score_logicalOr (FUN_6804fc40)
//   score_logicalNot (FUN_6804fcd0)
//   score_stringConcat (FUN_6804fd10)
//   score_stringConcatSpace (FUN_6804fe90)

// ============================================================
// Function: score_logicalAndCoerce (FUN_6804fa10)
// Address: 6804fa10
// Size: 201 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_logicalAndCoerce(int param_1)
{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar1 = DAT_68197768;
    piVar2 = DAT_6819776c;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      iVar1 = *(int *)(size_t)_DAT_68197764;
      piVar2 = (int *)((int *)(size_t)_DAT_68197764)[1];
    }
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(0x12);
      return 0;
    }
    if (iVar1 == 3) {
      score_dispatchFileOp(0x12);
      return 0;
    }
    props_releaseValue(param_1,(byte)iVar1,piVar2);
    props_releaseValue(param_1,(byte)*(undefined4 *)(param_1 + 0x1c),*(int **)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x1c) = 4;
    if ((piVar2 != (int *)0x0) && (*(int *)(param_1 + 0x20) != 0)) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(undefined4 *)(param_1 + 0x20) = 1;
      return 0;
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return 0;
}


// ============================================================
// Function: score_logicalAnd (FUN_6804fae0)
// Address: 6804fae0
// Size: 141 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_logicalAnd(int param_1)
{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar1 = DAT_6819776c;
    iVar2 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      iVar1 = ((int *)(size_t)_DAT_68197764)[1];
      iVar2 = *(int *)(size_t)_DAT_68197764;
    }
    if ((iVar2 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      if ((iVar1 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
        *(undefined4 *)(param_1 + 0x20) = 1;
        return 0;
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(undefined4 *)(param_1 + 0x20) = 0;
      return 0;
    }
    score_logicalAndCoerce(param_1);
  }
  return 0;
}


// ============================================================
// Function: score_logicalOrCoerce (FUN_6804fb70)
// Address: 6804fb70
// Size: 200 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_logicalOrCoerce(int param_1)
{
  int iVar1;
  int *piVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar1 = DAT_68197768;
    piVar2 = DAT_6819776c;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      iVar1 = *(int *)(size_t)_DAT_68197764;
      piVar2 = (int *)((int *)(size_t)_DAT_68197764)[1];
    }
    if (*(int *)(param_1 + 0x1c) == 3) {
      score_dispatchFileOp(0x13);
      return 0;
    }
    if (iVar1 == 3) {
      score_dispatchFileOp(0x13);
      return 0;
    }
    props_releaseValue(param_1,(byte)iVar1,piVar2);
    props_releaseValue(param_1,(byte)*(undefined4 *)(param_1 + 0x1c),*(int **)(param_1 + 0x20));
    *(undefined4 *)(param_1 + 0x1c) = 4;
    if ((piVar2 == (int *)0x0) && (*(int *)(param_1 + 0x20) == 0)) {
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(undefined4 *)(param_1 + 0x20) = 0;
      return 0;
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    *(undefined4 *)(param_1 + 0x20) = 1;
  }
  return 0;
}


// ============================================================
// Function: score_logicalOr (FUN_6804fc40)
// Address: 6804fc40
// Size: 138 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_logicalOr(int param_1)
{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    iVar1 = DAT_6819776c;
    iVar2 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      iVar1 = ((int *)(size_t)_DAT_68197764)[1];
      iVar2 = *(int *)(size_t)_DAT_68197764;
    }
    if ((iVar2 == 4) && (*(int *)(param_1 + 0x1c) == 4)) {
      if ((iVar1 == 0) && (*(int *)(param_1 + 0x20) == 0)) {
        *(undefined4 *)(param_1 + 0x20) = 0;
        *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
        return 0;
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      *(undefined4 *)(param_1 + 0x20) = 1;
      return 0;
    }
    score_logicalOrCoerce(param_1);
  }
  return 0;
}


// ============================================================
// Function: score_logicalNot (FUN_6804fcd0)
// Address: 6804fcd0
// Size: 50 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_logicalNot(int param_1)
{
  if ((*(byte *)(param_1 + 0x1c) & 1) != 0) {
    props_releaseValue(param_1,(byte)*(undefined4 *)(param_1 + 0x1c),*(int **)(param_1 + 0x20));
  }
  *(undefined4 *)(param_1 + 0x1c) = 4;
  *(uint *)(param_1 + 0x20) = (uint)(*(int *)(param_1 + 0x20) == 0);
  return 0;
}


// ============================================================
// Function: score_stringConcat (FUN_6804fd10)
// Address: 6804fd10
// Size: 371 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_stringConcat(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int **ppiVar4;
  int local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  iVar2 = param_1;
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    local_14 = DAT_6819776c;
    local_18 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_14 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_18 = *(int *)(size_t)_DAT_68197764;
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    props_getStringLength(param_1,&local_18);
    piVar1 = (int *)(iVar2 + 0x1c);
    props_getStringLength(iVar2,piVar1);
    if (((local_18 != 0x40) && (local_18 != 0x43)) || ((*piVar1 != 0x40 && (*piVar1 != 0x43)))) {
      props_releaseValue(iVar2,(byte)local_18,local_14);
      props_setError(iVar2,10);
      return 0;
    }
    local_c = props_getStringData(&local_18,&param_1);
    local_10 = props_getStringData(piVar1,&local_8);
    iVar3 = stage_resolveString(iVar2,local_8 + param_1,&local_20);
    if (iVar3 != 0) {
      if (local_20 == 0x40) {
        ppiVar4 = &local_1c;
      }
      else {
        ppiVar4 = (int **)(*local_1c + 8);
      }
      Ordinal_1128(ppiVar4,local_c,param_1);
      Ordinal_1128((int)ppiVar4 + param_1,local_10,local_8);
      *(undefined1 *)((int)ppiVar4 + param_1 + local_8) = 0;
      props_unlockString(&local_18);
      props_unlockString(piVar1);
      props_releaseValue(iVar2,(byte)local_18,local_14);
      props_releaseValue(iVar2,(byte)*piVar1,*(int **)(iVar2 + 0x20));
      *piVar1 = local_20;
      *(int **)(iVar2 + 0x20) = local_1c;
      return 0;
    }
    props_releaseValue(iVar2,(byte)local_18,local_14);
    props_setError(iVar2,3);
  }
  return 0;
}


// ============================================================
// Function: score_stringConcatSpace (FUN_6804fe90)
// Address: 6804fe90
// Size: 388 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_stringConcatSpace(int param_1)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int **ppiVar5;
  int local_20;
  int *local_1c;
  int local_18;
  int *local_14;
  int *local_10;
  int *local_c;
  int local_8;
  
  iVar2 = param_1;
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    local_14 = DAT_6819776c;
    local_18 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_14 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_18 = *(int *)(size_t)_DAT_68197764;
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    props_getStringLength(param_1,&local_18);
    piVar1 = (int *)(iVar2 + 0x1c);
    props_getStringLength(iVar2,piVar1);
    if (((local_18 != 0x40) && (local_18 != 0x43)) || ((*piVar1 != 0x40 && (*piVar1 != 0x43)))) {
      props_releaseValue(iVar2,(byte)local_18,local_14);
      props_setError(iVar2,10);
      return 0;
    }
    local_c = props_getStringData(&local_18,&param_1);
    local_10 = props_getStringData(piVar1,&local_8);
    iVar4 = stage_resolveString(iVar2,local_8 + 1 + param_1,&local_20);
    if (iVar4 != 0) {
      if (local_20 == 0x40) {
        ppiVar5 = &local_1c;
      }
      else {
        ppiVar5 = (int **)(*local_1c + 8);
      }
      Ordinal_1128(ppiVar5,local_c,param_1);
      piVar3 = local_10;
      *(undefined1 *)((int)ppiVar5 + param_1) = 0x20;
      Ordinal_1128((int)ppiVar5 + param_1 + 1,piVar3,local_8);
      *(undefined1 *)((int)ppiVar5 + param_1 + local_8 + 1) = 0;
      props_unlockString(&local_18);
      props_unlockString(piVar1);
      props_releaseValue(iVar2,(byte)local_18,local_14);
      props_releaseValue(iVar2,(byte)*piVar1,*(int **)(iVar2 + 0x20));
      *piVar1 = local_20;
      *(int **)(iVar2 + 0x20) = local_1c;
      return 0;
    }
    props_releaseValue(iVar2,(byte)local_18,local_14);
    props_setError(iVar2,3);
  }
  return 0;
}


