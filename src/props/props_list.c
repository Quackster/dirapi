// Module: props
// Topic: List object operations
// Address range: 0x6803b180 - 0x6803b6e0
// Functions (10):
//   props_listAppend (FUN_6803b180)
//   props_listDeleteAt (FUN_6803b240)
//   props_listClear (FUN_6803b2f0)
//   props_listDeleteValue (FUN_6803b340)
//   props_listGetAt (FUN_6803b430)
//   props_listFindValue (FUN_6803b4c0)
//   props_listGetLast (FUN_6803b590)
//   props_listSetProperty (FUN_6803b5d0)
//   props_listFindPosition (FUN_6803b610)
//   props_listGetPosition (FUN_6803b6e0)



// ============================================================
// Function: props_listAppend
// Address: 6803b180
// Size: 190 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 props_listAppend(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint local_c;
  uint local_8;
  
  iVar1 = *(int *)(*param_2 + 0x20);
  iVar2 = props_getInt(param_1);
  if (iVar2 == 2) {
    if (iVar1 == 1) {
      *(undefined4 *)(*param_2 + 0x20) = 0;
      *(undefined ***)*param_2 = &PTR_LAB_6818d268;
    }
    _DAT_68197764 =
         (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                 *(int *)(param_1 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    if ((local_c & 1) != 0) {
      props_retainValue(param_1,&local_c);
    }
    stage_lookupSymbolId(param_2,&local_c);
    props_checkReentrant(param_1);
    return 1;
  }
  props_setError(param_1,0x16);
  return 0;
}



// ============================================================
// Function: props_listDeleteAt
// Address: 6803b240
// Size: 166 bytes
// Params: uint param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_listDeleteAt(uint param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_1;
  piVar1 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                  *(int *)(param_1 + 0x18));
  iVar3 = props_getInt(param_1);
  if ((iVar3 == 2) && (*piVar1 == 4)) {
    param_1 = piVar1[1];
  }
  else {
    iVar3 = props_getTypedValue(uVar2,2,4,&param_1);
    if (iVar3 == 0) {
      return 0;
    }
  }
  piVar1 = param_2;
  if ((0 < (int)param_1) && (iVar3 = *param_2, (int)param_1 <= *(int *)(iVar3 + 0x10))) {
    param_1 = param_1 - 1;
    props_releaseValue(uVar2,(byte)*(undefined4 *)(iVar3 + 0x28 + param_1 * 8),
                 *(int **)(iVar3 + 0x2c + param_1 * 8));
    stage_emitPushRef(piVar1,param_1);
    if (*(int *)(*piVar1 + 0x10) <= *(int *)(*piVar1 + 0x14) >> 1) {
      stage_emitPopVar(piVar1);
    }
    return 1;
  }
  props_setError(uVar2,0x3c);
  return 0;
}



// ============================================================
// Function: props_listClear
// Address: 6803b2f0
// Size: 76 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_listClear(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(*param_2 + 0x10);
  if (0 < iVar1) {
    iVar2 = 0x28;
    do {
      props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + iVar2),*(int **)(*param_2 + 4 + iVar2));
      iVar2 = iVar2 + 8;
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  *(undefined4 *)(*param_2 + 0x10) = 0;
  stage_emitPopVar(param_2);
  return 1;
}



// ============================================================
// Function: props_listDeleteValue
// Address: 6803b340
// Size: 228 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 props_listDeleteValue(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  piVar1 = param_2;
  param_2 = (int *)(uint)(*(int *)(*param_2 + 0x20) == 1);
  *(undefined4 *)(param_3 + 4) = 0;
  iVar3 = props_getInt(param_1);
  if (iVar3 == 2) {
    _DAT_68197764 =
         (undefined4 *)
         (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 + *(int *)(param_1 + 0x18))
    ;
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (undefined4 *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    if (param_2 == (int *)0x0) {
      iVar3 = props_linearSearch(param_1,piVar1,(byte *)&local_c,(int *)&param_2);
    }
    else {
      iVar3 = props_binarySearch(param_1,piVar1,&local_c,(int *)&param_2);
    }
    piVar2 = param_2;
    if (iVar3 != 0) {
      props_releaseValue(param_1,(byte)*(undefined4 *)(*piVar1 + 0x28 + (int)param_2 * 8),
                   *(int **)(*piVar1 + 0x2c + (int)param_2 * 8));
      stage_emitPushRef(piVar1,(int)piVar2);
      *(undefined4 *)(param_3 + 4) = 1;
    }
    return 1;
  }
  props_setError(param_1,0x16);
  return 0;
}



// ============================================================
// Function: props_listGetAt
// Address: 6803b430
// Size: 134 bytes
// Params: uint param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_listGetAt(uint param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = param_1;
  piVar1 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                  *(int *)(param_1 + 0x18));
  iVar3 = props_getInt(param_1);
  if ((iVar3 == 2) && (*piVar1 == 4)) {
    param_1 = piVar1[1];
  }
  else {
    iVar3 = props_getTypedValue(uVar2,2,4,&param_1);
    if (iVar3 == 0) {
      return 0;
    }
  }
  if ((0 < (int)param_1) && (iVar3 = *param_2, (int)param_1 <= *(int *)(iVar3 + 0x10))) {
    *param_3 = *(undefined4 *)(iVar3 + 0x20 + param_1 * 8);
    param_3[1] = *(undefined4 *)(iVar3 + 0x24 + param_1 * 8);
    return 1;
  }
  props_setError(uVar2,0x3c);
  return 0;
}



// ============================================================
// Function: props_listFindValue
// Address: 6803b4c0
// Size: 207 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 props_listFindValue(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = *(int *)(*param_2 + 0x20);
  iVar1 = props_getInt(param_1);
  if (iVar1 != 2) {
    props_setError(param_1,0x16);
    return 0;
  }
  _DAT_68197764 =
       (undefined4 *)
       (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 + *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (undefined4 *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  if (iVar2 == 1) {
    piVar3 = (int *)(param_3 + 4);
    iVar2 = props_binarySearch(param_1,param_2,&local_c,piVar3);
    if (iVar2 == 0) {
      *piVar3 = -1;
      *piVar3 = *piVar3 + 1;
      return 1;
    }
  }
  else {
    props_linearSearch(param_1,param_2,(byte *)&local_c,(int *)(param_3 + 4));
  }
  *(int *)(param_3 + 4) = *(int *)(param_3 + 4) + 1;
  return 1;
}



// ============================================================
// Function: props_listGetLast
// Address: 6803b590
// Size: 61 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_listGetLast(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *param_2;
  iVar3 = *(int *)(iVar1 + 0x10) + -1;
  if (-1 < iVar3) {
    uVar2 = *(undefined4 *)(iVar1 + 0x28 + iVar3 * 8);
    param_3[1] = *(undefined4 *)(iVar1 + 0x2c + iVar3 * 8);
    *param_3 = uVar2;
    return 1;
  }
  param_3[1] = 0;
  *param_3 = 2;
  return 1;
}



// ============================================================
// Function: props_listSetProperty
// Address: 6803b5d0
// Size: 59 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_listSetProperty(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 != 3) {
    props_setError(param_1,0x17);
    return 0;
  }
  *(undefined4 *)(param_3 + 4) = 1;
  uVar2 = props_setProperty(param_1,param_2,param_3);
  return uVar2;
}



// ============================================================
// Function: props_listFindPosition
// Address: 6803b610
// Size: 199 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 props_listFindPosition(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = *(int *)(*param_2 + 0x20);
  iVar1 = props_getInt(param_1);
  if (iVar1 == 2) {
    _DAT_68197764 =
         (undefined4 *)
         (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 + *(int *)(param_1 + 0x18))
    ;
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (undefined4 *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    if (iVar2 == 1) {
      props_binarySearch(param_1,param_2,&local_c,(int *)(param_3 + 4));
      iVar2 = 1;
    }
    else {
      iVar2 = props_linearSearch(param_1,param_2,(byte *)&local_c,(int *)(param_3 + 4));
    }
    piVar3 = (int *)(param_3 + 4);
    *piVar3 = *piVar3 + 1;
    if (iVar2 == 0) {
      *piVar3 = 0;
    }
    return 1;
  }
  props_setError(param_1,0x16);
  return 0;
}



// ============================================================
// Function: props_listGetPosition
// Address: 6803b6e0
// Size: 189 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 props_listGetPosition(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar2 = *(int *)(*param_2 + 0x20);
  iVar1 = props_getInt(param_1);
  if (iVar1 == 2) {
    _DAT_68197764 =
         (undefined4 *)
         (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 + *(int *)(param_1 + 0x18))
    ;
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (undefined4 *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    if (iVar2 == 1) {
      iVar2 = props_binarySearch(param_1,param_2,&local_c,(int *)(param_3 + 4));
    }
    else {
      iVar2 = props_linearSearch(param_1,param_2,(byte *)&local_c,(int *)(param_3 + 4));
    }
    piVar3 = (int *)(param_3 + 4);
    *piVar3 = *piVar3 + 1;
    if (iVar2 == 0) {
      *piVar3 = 0;
    }
    return 1;
  }
  props_setError(param_1,0x16);
  return 0;
}


