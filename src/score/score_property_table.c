// Module: score
// Topic: Property table and event dispatch
// Address range: 0x6804a400 - 0x6804a900
// Functions (13):
//   score_createPropertyTable
//   score_lookupProperty
//   score_invalidateEntries
//   score_clearPropertyTable
//   score_findEntryByIndex
//   score_iterateProperties
//   score_freePropertyHandle
//   score_initTableCapacity
//   score_getValueByIndex
//   score_resetPropertyCache
//   score_getPropertyByIndex
//   score_getPropertyPair
//   score_getPropertyValue

// ============================================================
// Function: score_createPropertyTable (FUN_6804a400)
// Address: 6804a400
// Size: 13 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_createPropertyTable(void)
{
  score_getSymbolName(0x7f,0x9d);
  return 0;
}


// ============================================================
// Function: score_lookupProperty (FUN_6804a410)
// Address: 6804a410
// Size: 269 bytes
// Params: int * param_1, uint param_2, int param_3, uint * param_4
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * score_lookupProperty(int *param_1,uint param_2,int param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  int iVar9;
  
  if (param_1 == (int *)0x0) {
    return (uint *)0x0;
  }
  iVar5 = *param_1;
  uVar7 = *(uint *)(iVar5 + 0x20) & param_2;
  puVar4 = (uint *)(iVar5 + 0x24 + uVar7 * 0x10);
  uVar3 = *(uint *)(iVar5 + 0x24 + uVar7 * 0x10);
  while (uVar3 != 0xffffffff) {
    if (uVar3 == param_2) goto LAB_6804a50a;
    uVar1 = puVar4[1];
    if ((int)uVar1 < 0) break;
    puVar4 = (uint *)(iVar5 + 0x24 + uVar1 * 0x10);
    uVar7 = uVar1;
    uVar3 = *puVar4;
  }
  if (param_3 == 0) {
LAB_6804a49a:
    if (param_4 != (uint *)0x0) {
      *param_4 = 0xffffffff;
    }
    return (uint *)0x0;
  }
  if (*puVar4 != 0xffffffff) {
    if (*(int *)(iVar5 + 0x18) <= *(int *)(iVar5 + 0x14)) {
      iVar9 = (*(int *)(iVar5 + 0x18) >> 1) + *(int *)(iVar5 + 0x18);
      if (iVar9 < 0) {
        iVar9 = 0x7fff;
      }
      uVar3 = cast_resizeHandle((uint)param_1,iVar9 * 0x10 + 0x24,1);
      if (uVar3 == 0) goto LAB_6804a49a;
      iVar5 = *param_1;
      iVar2 = *(int *)(iVar5 + 0x18);
      puVar4 = (uint *)(iVar5 + 0x24 + uVar7 * 0x10);
      if (iVar2 < iVar9) {
        iVar8 = iVar9 - iVar2;
        puVar6 = (undefined4 *)(iVar5 + 0x24 + iVar2 * 0x10);
        do {
          *puVar6 = 0xffffffff;
          puVar6 = puVar6 + 4;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      *(int *)(iVar5 + 0x18) = iVar9;
    }
    uVar7 = *(uint *)(iVar5 + 0x14);
    puVar4[1] = uVar7;
    *(int *)(iVar5 + 0x14) = *(int *)(iVar5 + 0x14) + 1;
  }
  puVar4 = (uint *)(iVar5 + 0x24 + uVar7 * 0x10);
  *puVar4 = param_2;
  puVar4[1] = 0xffffffff;
  puVar4[2] = 2;
  puVar4[3] = 0;
LAB_6804a50a:
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar7;
  }
  return puVar4 + 2;
}


// ============================================================
// Function: score_invalidateEntries (FUN_6804a520)
// Address: 6804a520
// Size: 40 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_invalidateEntries(int *param_1)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x14);
  puVar3 = (undefined4 *)(iVar1 + 0x24);
  while (iVar2 = iVar2 + -1, -1 < iVar2) {
    *puVar3 = 0xffffffff;
    puVar3 = puVar3 + 4;
  }
  *(int *)(iVar1 + 0x14) = *(int *)(iVar1 + 0x20) + 1;
  return 0;
}


// ============================================================
// Function: score_clearPropertyTable (FUN_6804a550)
// Address: 6804a550
// Size: 35 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_clearPropertyTable(int *param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)(*param_1 + 0x24);
  iVar1 = *(int *)(*param_1 + 0x14);
  iVar2 = 0;
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    if (*piVar3 != -1) {
      iVar2 = iVar2 + 1;
    }
    piVar3 = piVar3 + 4;
  }
  return iVar2;
}


// ============================================================
// Function: score_findEntryByIndex (FUN_6804a580)
// Address: 6804a580
// Size: 68 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * score_findEntryByIndex(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(*param_1 + 0x14);
  iVar4 = 0;
  piVar2 = (int *)(*param_1 + 0x24);
  iVar3 = 0;
  if (0 < iVar1) {
    do {
      if (*piVar2 != -1) {
        if (param_3 != (int *)0x0) {
          *param_3 = *piVar2;
        }
        if (iVar4 == param_2) {
          return piVar2;
        }
        iVar4 = iVar4 + 1;
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 4;
    } while (iVar3 < iVar1);
  }
  return (int *)0x0;
}


// ============================================================
// Function: score_iterateProperties (FUN_6804a5d0)
// Address: 6804a5d0
// Size: 96 bytes
// Params: int * param_1, int * param_2, int * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_iterateProperties(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)(*param_1 + 0x14);
  iVar2 = *param_2;
  if (iVar2 < iVar1) {
    piVar3 = (int *)(*param_1 + 0x24 + iVar2 * 0x10);
    do {
      if (*piVar3 != -1) {
        if (param_3 != (int *)0x0) {
          *param_3 = *piVar3;
        }
        if (param_4 != (int *)0x0) {
          *param_4 = piVar3[2];
          param_4[1] = piVar3[3];
        }
        *param_2 = iVar2 + 1;
        return 1;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 4;
    } while (iVar2 < iVar1);
  }
  return 0;
}


// ============================================================
// Function: score_freePropertyHandle (FUN_6804a630)
// Address: 6804a630
// Size: 9 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_freePropertyHandle(undefined4 param_1)
{
  cast_freeHandle(param_1);
  return 0;
}


// ============================================================
// Function: score_initTableCapacity (FUN_6804a640)
// Address: 6804a640
// Size: 54 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_initTableCapacity(int param_1)
{
  int iVar1;
  
  if (param_1 < 3) {
    param_1 = 3;
  }
  iVar1 = 1;
  if (0 < param_1) {
    do {
      iVar1 = iVar1 * 2;
    } while (iVar1 <= param_1);
  }
  score_getSymbolName(iVar1 + -1,(param_1 >> 1) + iVar1 + -1);
  return 0;
}


// ============================================================
// Function: score_getValueByIndex (FUN_6804a680)
// Address: 6804a680
// Size: 37 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * score_getValueByIndex(int *param_1,int param_2,int *param_3)

{
  int *piVar1;
  
  piVar1 = score_findEntryByIndex(param_1,param_2,param_3);
  if (piVar1 != (int *)0x0) {
    return piVar1 + 2;
  }
  return (int *)0x0;
}


// ============================================================
// Function: score_resetPropertyCache (FUN_6804a6b0)
// Address: 6804a6b0
// Size: 33 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_resetPropertyCache(int param_1)
{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x7c) != 0)) {
    *(undefined4 *)(param_1 + 0x7c) = 0;
    *(undefined4 *)(param_1 + 0x74) = *(undefined4 *)(param_1 + 0x78);
  }
  return 0;
}


// ============================================================
// Function: score_getPropertyByIndex (FUN_6804a6e0)
// Address: 6804a6e0
// Size: 481 bytes
// Params: uint param_1, uint param_2, uint * param_3, int * param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_getPropertyByIndex(uint param_1,uint param_2,uint *param_3,int *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  uint *puVar5;
  undefined3 extraout_var;
  int *unaff_ESI;
  bool bVar6;
  undefined4 local_14;
  int local_8;
  
  puVar5 = param_3;
  iVar1 = unaff_ESI[6];
  local_8 = 0;
  bVar6 = (int)param_1 < 0;
  if (bVar6) {
    param_1 = param_1 & 0x7fffffff;
  }
  *(int *)(*(int *)unaff_ESI[2] + 0x504) = *(int *)(*(int *)unaff_ESI[2] + 0x504) + 1;
  if (!bVar6) {
    local_14 = *(undefined4 *)(*(int *)unaff_ESI[2] + 0x4f8);
    *(undefined4 *)(*(int *)unaff_ESI[2] + 0x4f8) = 0;
  }
  if ((int)param_1 < 0) {
    props_setError((int)unaff_ESI,0xb);
    local_8 = -0x7ffbf826;
    goto LAB_6804a86b;
  }
  if (0 < (int)param_2) {
    param_3 = (uint *)param_2;
    do {
      props_pushValue((int)unaff_ESI);
      unaff_ESI[7] = *puVar5;
      unaff_ESI[8] = puVar5[1];
      props_retainValue(unaff_ESI,(uint *)(unaff_ESI + 7));
      puVar5 = puVar5 + 2;
      param_3 = (uint *)((int)param_3 + -1);
    } while (param_3 != (uint *)0x0);
  }
  props_pushValue((int)unaff_ESI);
  unaff_ESI[8] = param_2;
  if (param_4 != (int *)0x0) {
    unaff_ESI[8] = param_2 | 0x80000000;
  }
  iVar2 = unaff_ESI[0x1d];
  unaff_ESI[0x1d] = 1;
  if (param_5 == 0) {
    bVar4 = props_dispatchMessage((int)unaff_ESI,param_1);
    if (CONCAT31(extraout_var,bVar4) != 0) {
      if ((unaff_ESI[0x1d] == 2) && (props_dispatchOpcode(unaff_ESI,(int *)0x2,0,0), unaff_ESI[0x1d] == 8))
      {
        local_8 = -0x7ffbffff;
      }
      goto LAB_6804a801;
    }
LAB_6804a840:
    iVar3 = unaff_ESI[6];
    while (iVar1 < iVar3) {
      props_popValue((int)unaff_ESI);
      iVar3 = unaff_ESI[6];
    }
    local_8 = -0x7ffbf437;
  }
  else {
    puVar5 = score_lookupProperty(*(int **)(*(int *)unaff_ESI[2] + 0x4ec),param_1,0,(uint *)0x0);
    if (puVar5 == (uint *)0x0) goto LAB_6804a840;
    props_callNative((int)unaff_ESI,(int)(short)puVar5[1]);
LAB_6804a801:
    if (param_4 != (int *)0x0) {
      *param_4 = unaff_ESI[7];
      param_4[1] = unaff_ESI[8];
      unaff_ESI[6] = unaff_ESI[6] + -8;
      iVar3 = *(int *)unaff_ESI[4];
      unaff_ESI[7] = *(int *)(iVar3 + unaff_ESI[6]);
      unaff_ESI[8] = *(int *)(iVar3 + 4 + unaff_ESI[6]);
    }
    iVar3 = unaff_ESI[6];
    while (iVar1 < iVar3) {
      props_popValue((int)unaff_ESI);
      iVar3 = unaff_ESI[6];
    }
  }
  unaff_ESI[0x1d] = iVar2;
LAB_6804a86b:
  score_resetPropertyCache((int)unaff_ESI);
  if (!bVar6) {
    *(undefined4 *)(*(int *)unaff_ESI[2] + 0x4f8) = local_14;
  }
  *(int *)(*(int *)unaff_ESI[2] + 0x504) = *(int *)(*(int *)unaff_ESI[2] + 0x504) + -1;
  if (((local_8 == 0) && (param_4 != (int *)0x0)) && (*param_4 == 3)) {
    (**(code **)(**(int **)param_4[1] + 0x30))();
  }
  return local_8;
}


// ============================================================
// Function: score_getPropertyPair (FUN_6804a8d0)
// Address: 6804a8d0
// Size: 35 bytes
// Params: undefined4 param_1, uint param_2, uint param_3, uint * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getPropertyPair(undefined4 param_1,uint param_2,uint param_3,uint *param_4,int *param_5)
{
  score_getPropertyByIndex(param_2,param_3,param_4,param_5,0);
  return 0;
}


// ============================================================
// Function: score_getPropertyValue (FUN_6804a900)
// Address: 6804a900
// Size: 118 bytes
// Params: int param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getPropertyValue(int param_1,uint param_2,uint *param_3)

{
  uint *puVar1;
  
  puVar1 = score_lookupProperty(*(int **)(**(int **)(param_1 + 8) + 0x4e4),param_2,0,(uint *)0x0);
  if (puVar1 != (uint *)0x0) {
    *param_3 = *puVar1;
    param_3[1] = puVar1[1];
    props_retainValue(param_1,param_3);
    if (*param_3 == 3) {
      (**(code **)(**(int **)param_3[1] + 0x30))
                (param_1,(undefined4 *)param_3[1],**(int **)(param_1 + 8) + 0x558);
    }
    return 0;
  }
  *param_3 = 2;
  param_3[1] = 0;
  return 0;
}


