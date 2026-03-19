// Module: score
// Topic: PropList core operations (set/get/find/delete/sort)
// Address range: 0x68042830 - 0x680433a0
// Functions (17):
//   score_updateEntry (FUN_68042830)
//   score_setExisting (FUN_680429b0)
//   score_setOrAdd (FUN_68042a00)
//   score_deleteByIndex (FUN_68042a60)
//   score_clearAllEntries (FUN_68042b00)
//   score_deleteByFormat (FUN_68042b80)
//   score_deleteByMatch (FUN_68042c90)
//   score_getKeyByIndex (FUN_68042d70)
//   score_findKeyPosition (FUN_68042dd0)
//   score_getKeyByKey (FUN_68042e70)
//   score_getValueByKey (FUN_68042f20)
//   score_getValueOrDefault (FUN_68042fe0)
//   score_getLastValue (FUN_680430e0)
//   score_setByIndex (FUN_68043130)
//   score_resolveKeyIndex (FUN_68043290)
//   score_findEntryIndex (FUN_68043320)
//   score_quickSortEntries (FUN_680433a0)

// ============================================================
// Function: score_updateEntry (FUN_68042830)
// Address: 68042830
// Size: 382 bytes
// Params: void * this, uint * param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall score_updateEntry(void *this,uint *param_1,int param_2)
{
  int iVar1;
  uint *puVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int *unaff_EBX;
  int unaff_ESI;
  int local_20;
  int local_1c;
  uint local_18;
  int *local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  local_18 = *param_1;
  local_14 = (int *)param_1[1];
  local_10 = *(uint *)this;
  local_c = *(int **)((int)this + 4);
  if ((local_18 & 1) != 0) {
    props_retainValue(unaff_ESI,&local_18);
  }
  if ((local_10 & 1) != 0) {
    props_retainValue(unaff_ESI,&local_10);
  }
  if (*(int *)(*unaff_EBX + 0x20) == 0) {
    local_1c = score_formatValue(unaff_ESI,unaff_EBX,&local_20);
    if (local_1c == 0) {
      if (param_2 != 0) {
        stage_lookupSymbolId(unaff_EBX,&local_18);
        props_checkReentrant(unaff_ESI);
        return 0;
      }
      goto LAB_68042977;
    }
  }
  else {
    local_1c = score_formatString(unaff_ESI,unaff_EBX,&local_18,&local_20);
    if (local_1c == 0) {
      if (param_2 != 0) {
        stage_emitStoreProperty(unaff_EBX,local_20,&local_18);
        props_checkReentrant(unaff_ESI);
        return 0;
      }
LAB_68042977:
      local_1c = 0;
      if ((local_18 & 1) != 0) {
        props_releaseValue(unaff_ESI,(byte)local_18,local_14);
      }
      if ((local_10 & 1) != 0) {
        props_releaseValue(unaff_ESI,(byte)local_10,local_c);
      }
      return 0;
    }
  }
  iVar3 = *unaff_EBX;
  iVar1 = iVar3 + 0x28 + local_20 * 0x10;
  uVar4 = *(undefined4 *)(iVar1 + 8);
  piVar5 = *(int **)(iVar1 + 0xc);
  props_releaseValue(unaff_ESI,(byte)*(undefined4 *)(iVar3 + 0x28 + local_20 * 0x10),
               *(int **)(iVar3 + 0x2c + local_20 * 0x10));
  props_releaseValue(unaff_ESI,(byte)uVar4,piVar5);
  puVar2 = (uint *)(*unaff_EBX + 0x28 + local_20 * 0x10);
  *puVar2 = local_18;
  puVar2[1] = (uint)local_14;
  puVar2[2] = local_10;
  puVar2[3] = (uint)local_c;
  return 0;
}


// ============================================================
// Function: score_setExisting (FUN_680429b0)
// Address: 680429b0
// Size: 80 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_setExisting(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 != 3) {
    return 0;
  }
  uVar2 = score_updateEntry((void *)(*(int *)(param_1 + 0x18) + (2 - *(int *)(param_1 + 0x20)) * 8 +
                               **(int **)(param_1 + 0x10)),
                       (uint *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20) * -8 + 8 +
                               **(int **)(param_1 + 0x10)),0);
  return uVar2;
}


// ============================================================
// Function: score_setOrAdd (FUN_68042a00)
// Address: 68042a00
// Size: 91 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_setOrAdd(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 != 3) {
    props_setError(param_1,0x17);
    return 1;
  }
  uVar2 = score_updateEntry((void *)(*(int *)(param_1 + 0x18) + (2 - *(int *)(param_1 + 0x20)) * 8 +
                               **(int **)(param_1 + 0x10)),
                       (uint *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20) * -8 + 8 +
                               **(int **)(param_1 + 0x10)),1);
  return uVar2;
}


// ============================================================
// Function: score_deleteByIndex (FUN_68042a60)
// Address: 68042a60
// Size: 158 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_deleteByIndex(int param_1,int *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  uint local_8;
  
  iVar4 = props_getTypedValue(param_1,2,4,&local_8);
  if (iVar4 == 0) {
    return 0;
  }
  if (0 < (int)local_8) {
    iVar4 = *param_2;
    if ((int)local_8 <= *(int *)(iVar4 + 0x10)) {
      local_8 = local_8 - 1;
      uVar2 = *(undefined4 *)(iVar4 + 0x30 + local_8 * 0x10);
      puVar1 = (undefined4 *)(iVar4 + 0x28 + local_8 * 0x10);
      piVar3 = (int *)puVar1[3];
      props_releaseValue(param_1,(byte)*puVar1,*(int **)(iVar4 + 0x2c + local_8 * 0x10));
      props_releaseValue(param_1,(byte)uVar2,piVar3);
      stage_emitPushRef(param_2,local_8);
      if (*(int *)(*param_2 + 0x10) <= *(int *)(*param_2 + 0x14) >> 1) {
        stage_emitPopVar(param_2);
      }
      return 1;
    }
  }
  props_setError(param_1,0x3c);
  return 0;
}


// ============================================================
// Function: score_clearAllEntries (FUN_68042b00)
// Address: 68042b00
// Size: 109 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_clearAllEntries(undefined4 param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 local_8;
  
  local_8 = *(int *)(*param_2 + 0x10);
  if (0 < local_8) {
    iVar4 = 0;
    do {
      iVar1 = *param_2;
      uVar2 = *(undefined4 *)(iVar1 + 0x30 + iVar4);
      piVar3 = *(int **)(iVar1 + 0x34 + iVar4);
      props_releaseValue(param_1,(byte)*(undefined4 *)(iVar1 + 0x28 + iVar4),
                   *(int **)(iVar1 + iVar4 + 0x2c));
      props_releaseValue(param_1,(byte)uVar2,piVar3);
      iVar4 = iVar4 + 0x10;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  *(undefined4 *)(*param_2 + 0x10) = 0;
  stage_emitPopVar(param_2);
  return 1;
}


// ============================================================
// Function: score_deleteByFormat (FUN_68042b80)
// Address: 68042b80
// Size: 262 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_deleteByFormat(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_10;
  int *local_c;
  int local_8;
  
  local_8 = 0;
  iVar1 = props_getInt(param_1);
  if (iVar1 != 2) {
    props_setError(param_1,0x16);
    return 0;
  }
  _DAT_68197764 =
       (undefined4 *)
       (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 + *(int *)(param_1 + 0x18));
  local_c = (int *)DAT_6819776c;
  local_10 = DAT_68197768;
  if (_DAT_68197764 != (undefined4 *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_c = (int *)((int *)(size_t)_DAT_68197764)[1];
    local_10 = *(int *)(size_t)_DAT_68197764;
  }
  if (*(int *)(*param_2 + 0x20) == 0) {
    iVar2 = score_formatValue(param_1,param_2,&local_8);
    iVar1 = local_8;
  }
  else {
    iVar2 = score_formatString(param_1,param_2,&local_10,&local_8);
    iVar1 = local_8;
  }
  if (iVar2 != 0) {
    iVar2 = *param_2 + 0x28 + iVar1 * 0x10;
    local_10 = *(undefined4 *)(iVar2 + 8);
    local_c = *(int **)(iVar2 + 0xc);
    local_8 = iVar1;
    props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x28 + iVar1 * 0x10),*(int **)(iVar2 + 4))
    ;
    props_releaseValue(param_1,(byte)local_10,local_c);
    stage_emitPushRef(param_2,iVar1);
    *(undefined4 *)(param_3 + 4) = 1;
    return 1;
  }
  return 1;
}


// ============================================================
// Function: score_deleteByMatch (FUN_68042c90)
// Address: 68042c90
// Size: 222 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_deleteByMatch(int param_1,int *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 local_c;
  int *local_8;
  
  iVar2 = param_1;
  iVar4 = props_getInt(param_1);
  piVar3 = param_2;
  if (iVar4 == 2) {
    _DAT_68197764 =
         (undefined4 *)
         (**(int **)(iVar2 + 0x10) + *(int *)(iVar2 + 0x20) * -8 + 8 + *(int *)(iVar2 + 0x18));
    local_8 = (int *)DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (undefined4 *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    iVar5 = score_findMatchIndex(iVar2,param_2,&local_c,&param_1);
    iVar4 = param_1;
    if (iVar5 != 0) {
      iVar5 = *piVar3;
      puVar1 = (undefined4 *)(iVar5 + 0x28 + param_1 * 0x10);
      local_c = puVar1[2];
      local_8 = (int *)puVar1[3];
      props_releaseValue(iVar2,(byte)*puVar1,*(int **)(iVar5 + 0x2c + param_1 * 0x10));
      props_releaseValue(iVar2,(byte)local_c,local_8);
      stage_emitPushRef(piVar3,iVar4);
      *(undefined4 *)(param_3 + 4) = 1;
    }
    return 1;
  }
  props_setError(iVar2,0x16);
  return 0;
}


// ============================================================
// Function: score_getKeyByIndex (FUN_68042d70)
// Address: 68042d70
// Size: 86 bytes
// Params: uint param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getKeyByIndex(uint param_1,int *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1;
  iVar2 = props_getTypedValue(param_1,2,4,&param_1);
  if (iVar2 != 0) {
    if (((int)param_1 < 1) || (iVar2 = *param_2, *(int *)(iVar2 + 0x10) < (int)param_1)) {
      props_setError(uVar1,0x3c);
      return 0;
    }
    *param_3 = *(undefined4 *)(iVar2 + 0x18 + param_1 * 0x10);
    param_3[1] = *(undefined4 *)(iVar2 + 0x1c + param_1 * 0x10);
  }
  return 1;
}


// ============================================================
// Function: score_findKeyPosition (FUN_68042dd0)
// Address: 68042dd0
// Size: 155 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_findKeyPosition(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 local_c;
  undefined4 local_8;
  
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
    piVar2 = (int *)(param_3 + 4);
    iVar1 = score_findMatchIndex(param_1,param_2,&local_c,piVar2);
    if (iVar1 == 0) {
      *piVar2 = -1;
    }
    *piVar2 = *piVar2 + 1;
    return 1;
  }
  props_setError(param_1,0x16);
  return 0;
}


// ============================================================
// Function: score_getKeyByKey (FUN_68042e70)
// Address: 68042e70
// Size: 167 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_getKeyByKey(int param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = param_1;
  iVar2 = props_getInt(param_1);
  piVar1 = param_2;
  if (iVar2 == 2) {
    _DAT_68197764 =
         (undefined4 *)
         (**(int **)(iVar3 + 0x10) + *(int *)(iVar3 + 0x20) * -8 + 8 + *(int *)(iVar3 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (undefined4 *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    iVar3 = score_findMatchIndex(iVar3,param_2,&local_c,&param_1);
    if (iVar3 != 0) {
      iVar3 = *piVar1;
      *param_3 = *(undefined4 *)(iVar3 + 0x28 + param_1 * 0x10);
      param_3[1] = *(undefined4 *)(iVar3 + 0x2c + param_1 * 0x10);
    }
    return 1;
  }
  props_setError(iVar3,0x16);
  return 0;
}


// ============================================================
// Function: score_getValueByKey (FUN_68042f20)
// Address: 68042f20
// Size: 186 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_getValueByKey(int param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = param_1;
  iVar2 = props_getInt(param_1);
  piVar1 = param_2;
  if (iVar2 == 2) {
    _DAT_68197764 =
         (undefined4 *)
         (**(int **)(iVar3 + 0x10) + *(int *)(iVar3 + 0x20) * -8 + 8 + *(int *)(iVar3 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (undefined4 *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    if (*(int *)(*param_2 + 0x20) == 0) {
      iVar3 = score_formatValue(iVar3,param_2,&param_1);
    }
    else {
      iVar3 = score_formatString(iVar3,param_2,&local_c,&param_1);
    }
    if (iVar3 != 0) {
      iVar2 = *piVar1;
      *param_3 = *(undefined4 *)(iVar2 + (param_1 + 3) * 0x10);
      param_3[1] = *(undefined4 *)(iVar2 + 4 + (param_1 + 3) * 0x10);
    }
    return iVar3;
  }
  return 0;
}


// ============================================================
// Function: score_getValueOrDefault (FUN_68042fe0)
// Address: 68042fe0
// Size: 241 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_getValueOrDefault(int param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar3 = param_1;
  iVar2 = props_getInt(param_1);
  piVar1 = param_2;
  if (iVar2 != 2) {
    props_setError(iVar3,0x16);
    *param_3 = 2;
    param_3[1] = 0;
    return 1;
  }
  _DAT_68197764 =
       (undefined4 *)
       (**(int **)(iVar3 + 0x10) + *(int *)(iVar3 + 0x20) * -8 + 8 + *(int *)(iVar3 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (undefined4 *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  if (*(int *)(*param_2 + 0x20) == 0) {
    iVar3 = score_formatValue(iVar3,param_2,&param_1);
  }
  else {
    iVar3 = score_formatString(iVar3,param_2,&local_c,&param_1);
  }
  if (iVar3 == 0) {
    param_3[1] = 0;
    *param_3 = 2;
    return 1;
  }
  iVar3 = *piVar1;
  *param_3 = *(undefined4 *)(iVar3 + (param_1 + 3) * 0x10);
  param_3[1] = *(undefined4 *)(iVar3 + 4 + (param_1 + 3) * 0x10);
  return 1;
}


// ============================================================
// Function: score_getLastValue (FUN_680430e0)
// Address: 680430e0
// Size: 65 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getLastValue(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *param_2;
  if (-1 < *(int *)(iVar1 + 0x10) + -1) {
    iVar3 = *(int *)(iVar1 + 0x10) + 2;
    uVar2 = *(undefined4 *)(iVar1 + iVar3 * 0x10);
    param_3[1] = *(undefined4 *)(iVar1 + 4 + iVar3 * 0x10);
    *param_3 = uVar2;
    return 1;
  }
  param_3[1] = 0;
  *param_3 = 2;
  return 1;
}


// ============================================================
// Function: score_setByIndex (FUN_68043130)
// Address: 68043130
// Size: 348 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_setByIndex(int param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar2 = param_1;
  iVar4 = props_getInt(param_1);
  if (iVar4 != 3) {
    props_setError(iVar2,0x17);
    return 0;
  }
  _DAT_68197764 =
       (uint *)(**(int **)(iVar2 + 0x10) + *(int *)(iVar2 + 0x20) * -8 + 8 + *(int *)(iVar2 + 0x18))
  ;
  local_10 = DAT_6819776c;
  local_14 = DAT_68197768;
  if (_DAT_68197764 != (uint *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_10 = ((int *)(size_t)_DAT_68197764)[1];
    local_14 = *(int *)(size_t)_DAT_68197764;
  }
  iVar4 = props_coerceToInt(iVar2,(int *)&local_14,&param_1);
  piVar3 = param_2;
  if (iVar4 == 0) {
    uVar5 = score_setOrAdd(iVar2);
    return uVar5;
  }
  if ((0 < param_1) && (param_1 <= *(int *)(*param_2 + 0x10))) {
    param_1 = param_1 + -1;
    _DAT_68197764 =
         (uint *)(**(int **)(iVar2 + 0x10) + (2 - *(int *)(iVar2 + 0x20)) * 8 +
                 *(int *)(iVar2 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    if ((local_c & 1) != 0) {
      props_retainValue(iVar2,&local_c);
    }
    iVar1 = *piVar3;
    iVar4 = param_1 + 3;
    if ((*(byte *)(iVar1 + iVar4 * 0x10) & 1) != 0) {
      props_releaseValue(iVar2,(byte)*(undefined4 *)(iVar1 + iVar4 * 0x10),
                   *(int **)(iVar1 + 4 + iVar4 * 0x10));
    }
    iVar2 = *piVar3;
    *(uint *)(iVar2 + (param_1 + 3) * 0x10) = local_c;
    *(uint *)(iVar2 + 4 + (param_1 + 3) * 0x10) = local_8;
    return 1;
  }
  props_setError(iVar2,0x3c);
  return 0;
}


// ============================================================
// Function: score_resolveKeyIndex (FUN_68043290)
// Address: 68043290
// Size: 136 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_resolveKeyIndex(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 != 2) {
    props_setError(param_1,0x16);
    return 0;
  }
  piVar2 = param_3 + 1;
  if (*(int *)(*param_2 + 0x20) == 0) {
    iVar1 = score_formatValue(param_1,param_2,piVar2);
  }
  else {
    iVar1 = score_formatString(param_1,param_2,
                         (undefined4 *)
                         (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                         *(int *)(param_1 + 0x18)),piVar2);
  }
  *piVar2 = *piVar2 + 1;
  if (iVar1 == 0) {
    *param_3 = 2;
    *piVar2 = 0;
  }
  return 1;
}


// ============================================================
// Function: score_findEntryIndex (FUN_68043320)
// Address: 68043320
// Size: 128 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_findEntryIndex(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 != 2) {
    props_setError(param_1,0x16);
    return 0;
  }
  piVar2 = (int *)(param_3 + 4);
  if (*(int *)(*param_2 + 0x20) != 0) {
    score_formatString(param_1,param_2,
                 (undefined4 *)
                 (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                 *(int *)(param_1 + 0x18)),piVar2);
    *piVar2 = *piVar2 + 1;
    return 1;
  }
  score_formatValue(param_1,param_2,piVar2);
  *piVar2 = *piVar2 + 1;
  return 1;
}


// ============================================================
// Function: score_quickSortEntries (FUN_680433a0)
// Address: 680433a0
// Size: 775 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_quickSortEntries(undefined4 param_1,int *param_2,int param_3,int param_4)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int *piVar9;
  bool bVar10;
  undefined3 extraout_var;
  int iVar11;
  int iVar12;
  int *piVar13;
  bool bVar14;
  code *local_8;
  
  piVar9 = param_2;
  local_8 = *(code **)(*param_2 + 0x24);
  iVar12 = (param_4 - param_3) + 1;
  if (iVar12 < 2) {
    return 0;
  }
  do {
    if ((iVar12 < 10) || (bVar10 = js_isGCActive(), CONCAT31(extraout_var,bVar10) != 0)) {
      do {
        bVar10 = false;
        if (param_4 <= param_3) {
          return 0;
        }
        iVar12 = param_3 << 4;
        param_2 = (int *)(param_4 - param_3);
        do {
          iVar11 = *piVar9;
          iVar11 = (*local_8)(param_1,*(undefined4 *)(iVar11 + iVar12 + 0x28),
                              *(undefined4 *)(iVar11 + iVar12 + 0x2c),
                              *(undefined4 *)(iVar11 + 0x38 + iVar12),
                              *(undefined4 *)(iVar11 + 0x3c + iVar12));
          if (0 < iVar11) {
            iVar11 = *piVar9;
            uVar3 = *(undefined4 *)(iVar11 + 0x30 + iVar12);
            uVar4 = *(undefined4 *)(iVar11 + 0x28 + iVar12);
            uVar5 = *(undefined4 *)(iVar11 + 0x2c + iVar12);
            iVar11 = iVar11 + iVar12;
            uVar6 = *(undefined4 *)(iVar11 + 0x34);
            *(undefined4 *)(iVar11 + 0x28) = *(undefined4 *)(iVar11 + 0x38);
            *(undefined4 *)(iVar11 + 0x2c) = *(undefined4 *)(iVar11 + 0x3c);
            *(undefined4 *)(iVar11 + 0x30) = *(undefined4 *)(iVar11 + 0x40);
            *(undefined4 *)(iVar11 + 0x34) = *(undefined4 *)(iVar11 + 0x44);
            *(undefined4 *)(iVar11 + 0x38) = uVar4;
            *(undefined4 *)(iVar11 + 0x3c) = uVar5;
            *(undefined4 *)(iVar11 + 0x40) = uVar3;
            *(undefined4 *)(iVar11 + 0x44) = uVar6;
            bVar10 = true;
          }
          iVar12 = iVar12 + 0x10;
          param_2 = (int *)((int)param_2 + -1);
        } while (param_2 != (int *)0x0);
      } while (bVar10);
      return 0;
    }
    iVar12 = (iVar12 >> 1) + param_3;
    uVar3 = *(undefined4 *)(*piVar9 + 0x28 + iVar12 * 0x10);
    uVar4 = *(undefined4 *)(*piVar9 + 0x2c + iVar12 * 0x10);
    piVar13 = (int *)param_3;
    param_2 = (int *)param_4;
    if (param_4 < param_3) {
LAB_68043521:
      iVar12 = (int)piVar13 * 0x10;
      iVar11 = (*local_8)(param_1,*(undefined4 *)(*piVar9 + 0x28 + iVar12),
                          *(undefined4 *)(*piVar9 + 0x2c + iVar12),uVar3,uVar4);
      while (iVar11 != 0) {
        puVar1 = (undefined4 *)(*piVar9 + 0x3c + iVar12);
        puVar2 = (undefined4 *)(*piVar9 + 0x38 + iVar12);
        iVar12 = iVar12 + 0x10;
        piVar13 = (int *)((int)piVar13 + 1);
        iVar11 = (*local_8)(param_1,*puVar2,*puVar1,uVar3,uVar4);
      }
      iVar12 = *piVar9;
      uVar3 = *(undefined4 *)(iVar12 + 0x2c + param_3 * 0x10);
      puVar1 = (undefined4 *)(iVar12 + 0x28 + param_3 * 0x10);
      uVar4 = puVar1[2];
      uVar5 = puVar1[3];
      puVar2 = (undefined4 *)(iVar12 + 0x28 + (int)piVar13 * 0x10);
      uVar6 = *puVar1;
      *puVar1 = *puVar2;
      puVar1[1] = puVar2[1];
      puVar1[2] = puVar2[2];
      puVar1[3] = puVar2[3];
      *puVar2 = uVar6;
      puVar2[1] = uVar3;
      puVar2[2] = uVar4;
      puVar2[3] = uVar5;
    }
    else {
      do {
        iVar12 = (int)param_2 * 0x10;
        iVar11 = (*local_8)(param_1,*(undefined4 *)(*piVar9 + 0x28 + iVar12),
                            *(undefined4 *)(*piVar9 + 0x2c + iVar12),uVar3,uVar4);
        for (; (-1 < iVar11 && (param_3 <= (int)param_2)); param_2 = (int *)((int)param_2 + -1)) {
          puVar1 = (undefined4 *)(*piVar9 + 0x1c + iVar12);
          puVar2 = (undefined4 *)(*piVar9 + 0x18 + iVar12);
          iVar12 = iVar12 + -0x10;
          iVar11 = (*local_8)(param_1,*puVar2,*puVar1,uVar3,uVar4);
        }
        iVar12 = (int)piVar13 * 0x10;
        iVar11 = (*local_8)(param_1,*(undefined4 *)(*piVar9 + 0x28 + iVar12),
                            *(undefined4 *)(*piVar9 + 0x2c + iVar12),uVar3,uVar4);
        for (; (iVar11 < 0 && ((int)piVar13 <= param_4)); piVar13 = (int *)((int)piVar13 + 1)) {
          puVar1 = (undefined4 *)(*piVar9 + 0x3c + iVar12);
          puVar2 = (undefined4 *)(*piVar9 + 0x38 + iVar12);
          iVar12 = iVar12 + 0x10;
          iVar11 = (*local_8)(param_1,*puVar2,*puVar1,uVar3,uVar4);
        }
        bVar14 = SBORROW4((int)piVar13,(int)param_2);
        iVar12 = (int)piVar13 - (int)param_2;
        bVar10 = piVar13 == param_2;
        if ((int)piVar13 < (int)param_2) {
          puVar1 = (undefined4 *)(*piVar9 + 0x28 + (int)piVar13 * 0x10);
          puVar2 = (undefined4 *)(*piVar9 + 0x28 + (int)param_2 * 0x10);
          uVar5 = *puVar1;
          uVar6 = puVar1[1];
          uVar7 = puVar1[2];
          uVar8 = puVar1[3];
          *puVar1 = *puVar2;
          puVar1[1] = puVar2[1];
          puVar1[2] = puVar2[2];
          puVar1[3] = puVar2[3];
          *puVar2 = uVar5;
          puVar2[1] = uVar6;
          puVar2[2] = uVar7;
          param_2 = (int *)((int)param_2 + -1);
          piVar13 = (int *)((int)piVar13 + 1);
          puVar2[3] = uVar8;
          bVar14 = SBORROW4((int)piVar13,(int)param_2);
          iVar12 = (int)piVar13 - (int)param_2;
          bVar10 = piVar13 == param_2;
        }
      } while (bVar10 || bVar14 != iVar12 < 0);
      if (piVar13 == (int *)param_3) goto LAB_68043521;
      score_quickSortEntries(param_1,piVar9,param_3,(int)piVar13 + -1);
      param_3 = (int)param_2;
    }
    param_3 = param_3 + 1;
    local_8 = *(code **)(*piVar9 + 0x24);
    iVar12 = (param_4 - param_3) + 1;
    if (iVar12 < 2) {
      return 0;
    }
  } while( true );
}


