// Module: score
// Topic: PropList create, copy, serialize, modify
// Address range: 0x68043e00 - 0x680443d0
// Functions (13):
//   score_setProplistValue
//   score_getProplistRaw
//   score_updateProplist
//   score_setPropertyValue
//   score_insertProplistEntry
//   score_deleteProplistEntry
//   score_updateProplistRange
//   score_extractProplistString
//   score_markProplistDirty
//   score_releaseProplistEntries
//   score_serializeProplist
//   score_deserializeProplist
//   score_resolveProplistEntry

// ============================================================
// Function: score_setProplistValue (FUN_68043e00)
// Address: 68043e00
// Size: 79 bytes
// Params: undefined4 param_1, int * param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_setProplistValue(undefined4 param_1,int *param_2,int param_3,uint *param_4,uint *param_5)
{
  uint *puVar1;
  
  puVar1 = (uint *)(*param_2 + 0x28 + param_3 * 0x10);
  *param_4 = *puVar1;
  param_4[1] = puVar1[1];
  *param_5 = puVar1[2];
  param_5[1] = puVar1[3];
  if ((*param_4 & 1) != 0) {
    props_retainValue(param_1,param_4);
  }
  if ((*param_5 & 1) != 0) {
    props_retainValue(param_1,param_5);
  }
  return 0;
}


// ============================================================
// Function: score_getProplistRaw (score_getProplistRaw)
// Address: 68043e50
// Size: 48 bytes
// Params: undefined4 param_1, int * param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getProplistRaw(undefined4 param_1,int *param_2,int param_3,undefined4 *param_4,
                 undefined4 *param_5)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)(*param_2 + 0x28 + param_3 * 0x10);
  *param_4 = *puVar1;
  param_4[1] = puVar1[1];
  *param_5 = puVar1[2];
  param_5[1] = puVar1[3];
  return 0;
}


// ============================================================
// Function: score_updateProplist (FUN_68043e80)
// Address: 68043e80
// Size: 103 bytes
// Params: int param_1, int * param_2, undefined4 * param_3, uint * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_updateProplist(int param_1,int *param_2,undefined4 *param_3,uint *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = param_2;
  iVar2 = param_1;
  if (*(int *)(*param_2 + 0x20) == 0) {
    iVar4 = score_formatValue(param_1,param_2,&param_1);
  }
  else {
    iVar4 = score_formatString(param_1,param_2,param_3,&param_1);
  }
  if (iVar4 != 0) {
    iVar1 = *piVar3;
    *param_4 = *(uint *)(iVar1 + (param_1 + 3) * 0x10);
    param_4[1] = *(uint *)(iVar1 + 4 + (param_1 + 3) * 0x10);
    if ((*param_4 & 1) != 0) {
      props_retainValue(iVar2,param_4);
    }
  }
  return iVar4;
}


// ============================================================
// Function: score_setPropertyValue (FUN_68043ef0)
// Address: 68043ef0
// Size: 33 bytes
// Params: undefined4 param_1, undefined4 param_2, uint * param_3, void * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_setPropertyValue(undefined4 param_1,undefined4 param_2,uint *param_3,void *param_4,int param_5)
{
  score_updateEntry(param_4,param_3,param_5);
  return 0;
}


// ============================================================
// Function: score_insertProplistEntry (FUN_68043f20)
// Address: 68043f20
// Size: 59 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_insertProplistEntry(undefined4 param_1,int *param_2,int param_3)
{
  if (*(int *)(*param_2 + 0x20) == 0) {
    *(undefined4 *)(*param_2 + 0x20) = 1;
    if (param_3 != 0) {
      *(code **)(*param_2 + 0x24) = props_convertValue;
    }
    score_quickSortEntries(param_1,param_2,0,*(int *)(*param_2 + 0x10) + -1);
  }
  return 0;
}


// ============================================================
// Function: score_deleteProplistEntry (FUN_68043f60)
// Address: 68043f60
// Size: 130 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_deleteProplistEntry(int param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = stage_allocDispatchEntry(0x38,0x28,0x10,param_2);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
  puVar1 = (undefined4 *)*piVar3;
  puVar1[1] = 1;
  *puVar1 = &PTR_LAB_6818d4c8;
  puVar1[4] = 0;
  puVar1[9] = props_compareValues;
  iVar2 = **(int **)(param_1 + 8);
  *(undefined4 *)(*piVar3 + 8) = *(undefined4 *)(**(int **)(iVar2 + 0x564) + 8);
  *(undefined4 *)(*piVar3 + 0xc) = *(undefined4 *)(iVar2 + 0x564);
  *(int **)(**(int **)(**(int **)(iVar2 + 0x564) + 8) + 0xc) = piVar3;
  *(int **)(**(int **)(iVar2 + 0x564) + 8) = piVar3;
  return 0;
}


// ============================================================
// Function: score_updateProplistRange (FUN_68043ff0)
// Address: 68043ff0
// Size: 117 bytes
// Params: int param_1, int * param_2, uint * param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_updateProplistRange(int param_1,int *param_2,uint *param_3,uint *param_4)
{
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_18 = *param_3;
  local_14 = param_3[1];
  local_10 = *param_4;
  local_c = param_4[1];
  if ((local_18 & 1) != 0) {
    props_retainValue(param_1,&local_18);
  }
  if ((local_10 & 1) != 0) {
    props_retainValue(param_1,&local_10);
  }
  stage_lookupSymbolId(param_2,&local_18);
  props_checkReentrant(param_1);
  return 0;
}


// ============================================================
// Function: score_extractProplistString (score_extractProplistString)
// Address: 68044070
// Size: 93 bytes
// Params: int param_1, int * param_2
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * score_extractProplistString(int param_1,int *param_2)

{
  undefined4 *puVar1;
  uint local_c;
  int *local_8;
  
  local_c = 3;
  local_8 = param_2;
  props_retainValue(param_1,&local_c);
  props_getStringLength(param_1,(int *)&local_c);
  if ((local_c != 0x40) && (local_c != 0x43)) {
    props_releaseValue(param_1,(byte)local_c,local_8);
    return (undefined4 *)0x0;
  }
  puVar1 = props_detachString(param_1,(int *)&local_c);
  return puVar1;
}


// ============================================================
// Function: score_markProplistDirty (score_markProplistDirty)
// Address: 680440d0
// Size: 131 bytes
// Params: undefined4 param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * score_markProplistDirty(undefined4 param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int *piVar5;
  int iVar6;
  int *local_8;
  
  *(uint *)(*param_2 + 4) = *(uint *)(*param_2 + 4) | 0x80000000;
  piVar5 = *(int **)(*param_2 + 0x10);
  if (0 < (int)piVar5) {
    iVar6 = 0;
    local_8 = piVar5;
    do {
      iVar1 = *param_2;
      piVar2 = *(int **)(iVar1 + 0x2c + iVar6);
      iVar3 = *(int *)(iVar1 + 0x30 + iVar6);
      puVar4 = *(undefined4 **)(iVar1 + 0x34 + iVar6);
      piVar5 = (int *)(iVar1 + 0x28 + iVar6);
      if ((*(int *)(iVar1 + 0x28 + iVar6) == 3) &&
         (piVar5 = (int *)*piVar2, (piVar5[1] & 0x80000000U) == 0)) {
        piVar5 = (int *)(**(code **)(*piVar5 + 0x34))(param_1,piVar2);
      }
      if ((iVar3 == 3) && (piVar5 = (int *)*puVar4, (piVar5[1] & 0x80000000U) == 0)) {
        piVar5 = (int *)(**(code **)(*piVar5 + 0x34))(param_1,puVar4);
      }
      iVar6 = iVar6 + 0x10;
      local_8 = (int *)((int)local_8 + -1);
    } while (local_8 != (int *)0x0);
  }
  return piVar5;
}


// ============================================================
// Function: score_releaseProplistEntries (score_releaseProplistEntries)
// Address: 68044160
// Size: 113 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_releaseProplistEntries(undefined4 param_1,int *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined4 local_8;
  
  local_8 = *(int *)(*param_2 + 0x10);
  if (0 < local_8) {
    iVar5 = 0;
    do {
      iVar1 = *param_2;
      puVar2 = *(undefined4 **)(iVar1 + 0x2c + iVar5);
      uVar3 = *(undefined4 *)(iVar1 + 0x30 + iVar5);
      puVar4 = *(undefined4 **)(iVar1 + 0x34 + iVar5);
      if (((byte)*(undefined4 *)(iVar1 + 0x28 + iVar5) & 0x1f) == 3) {
        (**(code **)(*(int *)*puVar2 + 0x3c))(param_1,puVar2);
      }
      if (((byte)uVar3 & 0x1f) == 3) {
        (**(code **)(*(int *)*puVar4 + 0x3c))(param_1,puVar4);
      }
      iVar5 = iVar5 + 0x10;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return 0;
}


// ============================================================
// Function: score_serializeProplist (score_serializeProplist)
// Address: 680441e0
// Size: 195 bytes
// Params: undefined4 * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_serializeProplist(undefined4 *param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int local_28;
  uint local_24;
  uint local_20;
  int local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = *(int *)(*param_2 + 0x10);
  local_20 = stage_serializeData(param_1,param_2,0,0xc,local_1c * 2 + 1);
  if (local_20 == 0) {
    local_28 = 4;
    local_24 = (uint)(*(code **)(*param_2 + 0x24) == props_convertValue) * 2 |
               (uint)(*(int *)(*param_2 + 0x20) != 0);
    stage_serializeFloat(param_1,&local_28);
    if (0 < local_1c) {
      iVar2 = 0;
      do {
        local_18 = *(int *)(*param_2 + 0x28 + iVar2);
        iVar1 = *param_2 + 0x28 + iVar2;
        local_14 = *(undefined4 *)(iVar1 + 4);
        local_10 = *(int *)(iVar1 + 8);
        local_c = *(undefined4 *)(iVar1 + 0xc);
        stage_serializeFloat(param_1,&local_18);
        stage_serializeFloat(param_1,&local_10);
        iVar2 = iVar2 + 0x10;
        local_1c = local_1c + -1;
      } while (local_1c != 0);
    }
  }
  return 0;
}


// ============================================================
// Function: score_deserializeProplist (score_deserializeProplist)
// Address: 680442b0
// Size: 283 bytes
// Params: int * param_1, undefined4 param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_deserializeProplist(int *param_1,undefined4 param_2,int param_3,undefined4 *param_4)
{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint local_30;
  uint local_2c;
  undefined4 *local_28;
  int *local_24;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar4 = *param_1;
  local_24 = param_1;
  local_28 = param_4;
  local_20 = stage_allocString(param_1,&local_30);
  if (local_20 == 0) {
    local_1c = local_2c;
    iVar5 = (param_3 + -1) / 2;
    piVar2 = (int *)score_deleteProplistEntry(iVar4,iVar5);
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    *(uint *)(*piVar2 + 0x20) = local_1c & 1;
    if ((local_1c & 2) == 0) {
      *(code **)(*piVar2 + 0x24) = props_compareValues;
    }
    else {
      *(code **)(*piVar2 + 0x24) = props_convertValue;
    }
    *local_28 = 3;
    local_28[1] = piVar2;
    stage_createFactory((int)param_1,-1,local_28);
    iVar4 = 0;
    if (0 < iVar5) {
      local_1c = 0;
      do {
        uVar3 = stage_allocString(local_24,&local_18);
        if ((uVar3 != 0) || (local_20 = stage_allocString(local_24,&local_10), local_20 != 0)) break;
        puVar1 = (uint *)(*piVar2 + 0x28 + local_1c);
        *puVar1 = local_18;
        puVar1[1] = local_14;
        puVar1[2] = local_10;
        iVar4 = iVar4 + 1;
        local_1c = local_1c + 0x10;
        puVar1[3] = local_c;
      } while (iVar4 < iVar5);
    }
    *(int *)(*piVar2 + 0x10) = iVar4;
  }
  return 0;
}


// ============================================================
// Function: score_resolveProplistEntry (score_resolveProplistEntry)
// Address: 680443d0
// Size: 101 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_resolveProplistEntry(int param_1,int param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_EDX;
  int local_c;
  int local_8;
  
  piVar1 = (int *)(**(int **)(param_1 + 0x10) + -8 + (param_2 - *(int *)(param_1 + 0x20)) * 8 +
                  *(int *)(param_1 + 0x18));
  local_c = 0;
  local_8 = 0;
  if (piVar1 != (int *)0x0) {
    local_c = *piVar1;
    local_8 = piVar1[1];
  }
  iVar2 = score_getProplistValue(param_1,&local_c);
  if (iVar2 != 0) {
    *param_3 = extraout_EDX;
    return 1;
  }
  *param_3 = 0;
  return 0;
}


