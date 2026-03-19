// Module: props
// Topic: Rectangle/point construction and operations
// Address range: 0x6803cf80 - 0x6803dfc0
// Functions (22):
//   props_parseRectOp
//   props_dispatchRectOp
//   props_sortRectList
//   props_cloneRectList
//   props_cloneRectIfSingle
//   props_cloneRectAndReturn
//   props_getRectOpsCount
//   props_buildRectFilterList
//   props_getRectCount
//   props_assignRectVtable
//   props_coerceAndBuildRect
//   props_buildRectFromInts
//   props_computeRectOp
//   props_extractRectAndBuild
//   props_buildPointFromInts
//   props_transformRect
//   props_assignPointVtable
//   props_compareRectLists
//   props_buildRectOffset
//   props_buildRectInset
//   props_buildRectIntersect
//   props_buildRectUnion



// ============================================================
// Function: props_parseRectOp (FUN_6803cf80)
// Address: 6803cf80
// Size: 244 bytes
// Params: int * param_1, undefined * * param_2, int param_3, undefined4 * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_parseRectOp(int *param_1,undefined **param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar4 = *param_1;
  if (param_2 == (undefined **)0xa) {
    param_2 = &PTR_LAB_6818d3c0;
  }
  else if (param_2 == (undefined **)0xb) {
    param_2 = &PTR_LAB_6818d410;
  }
  else {
    param_2 = &PTR_LAB_6818d268;
  }
  local_8 = stage_allocString(param_1,&local_10);
  uVar2 = local_c;
  if (local_8 == 0) {
    iVar5 = param_3 + -1;
    piVar3 = (int *)props_allocList(iVar4,iVar5);
    if (piVar3 == (int *)0x0) {
      return DAT_68195a8c;
    }
    *(undefined ***)*piVar3 = param_2;
    *(uint *)(*piVar3 + 0x20) = uVar2 & 1;
    if ((uVar2 & 2) == 0) {
      *(code **)(*piVar3 + 0x24) = props_compareValues;
    }
    else {
      *(code **)(*piVar3 + 0x24) = props_convertValue;
    }
    *param_4 = 3;
    param_4[1] = piVar3;
    stage_createFactory((int)param_1,-1,param_4);
    iVar4 = 0;
    if (0 < iVar5) {
      iVar6 = 0x28;
      uVar2 = local_8;
      do {
        local_8 = uVar2;
        local_8 = stage_allocString(param_1,&local_10);
        if (local_8 != 0) break;
        iVar1 = *piVar3;
        *(uint *)(iVar1 + iVar6) = local_10;
        *(uint *)(iVar1 + 4 + iVar6) = local_c;
        iVar4 = iVar4 + 1;
        iVar6 = iVar6 + 8;
        uVar2 = 0;
      } while (iVar4 < iVar5);
    }
    *(int *)(*piVar3 + 0x10) = iVar4;
  }
  return local_8;
}



// ============================================================
// Function: props_dispatchRectOp (FUN_6803d080)
// Address: 6803d080
// Size: 400 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_dispatchRectOp(int param_1,int param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  
  piVar7 = (int *)0x0;
  switch(param_3) {
  case 0xcb:
  case 0xcc:
  case 0xda:
  case 0xdc:
    iVar3 = props_getInt(param_1);
    if (iVar3 == 2) {
      piVar6 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                      *(int *)(param_1 + 0x18));
    }
    else {
      if (iVar3 != 3) break;
      piVar6 = (int *)(**(int **)(param_1 + 0x10) + (2 - *(int *)(param_1 + 0x20)) * 8 +
                      *(int *)(param_1 + 0x18));
    }
    if (*piVar6 == 3) {
      piVar1 = (int *)piVar6[1];
      bVar2 = cast_hasXtraProperty(param_1,piVar1);
      if (CONCAT31(extraout_var,bVar2) != 0) {
        piVar7 = cast_cloneXtraProperty(param_1,piVar1);
        if (piVar7 == (int *)0x0) {
          return 1;
        }
        *(int *)(*piVar1 + 4) = *(int *)(*piVar1 + 4) + -1;
        piVar6[1] = (int)piVar7;
        break;
      }
    }
LAB_6803d0e7:
    props_setError(param_1,0x13);
    props_normalizeType(param_1,2,0);
    return 0;
  default:
    break;
  case 0xce:
    iVar3 = props_getInt(param_1);
    if (iVar3 == 2) {
      iVar5 = **(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8;
      iVar3 = iVar5 + 8 + *(int *)(param_1 + 0x18);
      if (*(int *)(iVar5 + 8 + *(int *)(param_1 + 0x18)) == 3) {
        piVar6 = *(int **)(iVar3 + 4);
        bVar2 = cast_hasXtraProperty(param_1,piVar6);
        if (CONCAT31(extraout_var_00,bVar2) != 0) {
          piVar7 = cast_cloneXtraProperty(param_1,piVar6);
          if (piVar7 == (int *)0x0) {
            return 1;
          }
          *(int *)(*piVar6 + 4) = *(int *)(*piVar6 + 4) + -1;
          *(int **)(iVar3 + 4) = piVar7;
          break;
        }
      }
      goto LAB_6803d0e7;
    }
  }
  iVar3 = props_createList(param_1,param_2,param_3);
  if (iVar3 != 0) {
    switch(param_3) {
    case 0xcb:
    case 0xcc:
    case 0xce:
    case 0xda:
    case 0xdb:
    case 0xdc:
      uVar4 = sprites_checkCallbackState(param_1,param_2);
      cast_setXtraModifiedFlag(param_1,piVar7,uVar4);
      return iVar3;
    case 0xcf:
    case 0xd0:
    case 0xd1:
    case 0xd2:
      sprites_checkCallbackState(param_1,param_2);
    }
  }
  return iVar3;
}



// ============================================================
// Function: props_sortRectList (FUN_6803d250)
// Address: 6803d250
// Size: 42 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_sortRectList(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = props_getInt(param_1);
  props_sortListEntries(param_1,param_2,(uint)(1 < iVar1));
  return 1;
}



// ============================================================
// Function: props_cloneRectList (FUN_6803d280)
// Address: 6803d280
// Size: 270 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_cloneRectList(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  int *piVar3;
  int iVar4;
  int *extraout_EDX;
  int iVar5;
  uint local_10;
  int *local_c;
  int local_8;
  
  bVar2 = js_isGCActive();
  if (CONCAT31(extraout_var,bVar2) != 0) {
    props_setError(param_1,0x70);
    return 0;
  }
  iVar4 = *(int *)(*param_2 + 0x10);
  piVar3 = (int *)props_allocList(param_1,iVar4);
  if (piVar3 == (int *)0x0) {
    props_setError(param_1,2);
    return 0;
  }
  puVar1 = (undefined4 *)*piVar3;
  *puVar1 = *(undefined4 *)*param_2;
  puVar1[1] = 0;
  puVar1[4] = iVar4;
  puVar1[8] = *(undefined4 *)(*param_2 + 0x20);
  puVar1[9] = *(undefined4 *)(*param_2 + 0x24);
  if (0 < iVar4) {
    iVar5 = 0x28;
    local_8 = iVar4;
    do {
      local_10 = *(uint *)(*param_2 + iVar5);
      local_c = *(int **)(*param_2 + 4 + iVar5);
      iVar4 = props_setRectField(param_1,(int *)&local_10);
      if (iVar4 == 0) {
        iVar4 = score_getProplistValue(param_1,(int *)&local_10);
        if (iVar4 != 0) {
          score_resolveProplist(param_1,local_c,&local_10);
        }
      }
      else {
        props_cloneRectAndReturn(param_1,extraout_EDX,&local_10);
      }
      if ((local_10 & 1) != 0) {
        props_retainValue(param_1,&local_10);
      }
      iVar4 = *piVar3;
      *(uint *)(iVar4 + iVar5) = local_10;
      *(int **)(iVar4 + 4 + iVar5) = local_c;
      iVar5 = iVar5 + 8;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  param_3[1] = piVar3;
  *param_3 = 3;
  return 1;
}



// ============================================================
// Function: props_cloneRectIfSingle (FUN_6803d390)
// Address: 6803d390
// Size: 44 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_cloneRectIfSingle(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 != 1) {
    return 0;
  }
  uVar2 = props_cloneRectList(param_1,param_2,param_3);
  return uVar2;
}



// ============================================================
// Function: props_cloneRectAndReturn (FUN_6803d3c0)
// Address: 6803d3c0
// Size: 9 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_cloneRectAndReturn(int param_1,int *param_2,undefined4 *param_3)
{
  props_cloneRectList(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_getRectOpsCount (FUN_6803d3d0)
// Address: 6803d3d0
// Size: 260 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int props_getRectOpsCount(int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint local_10;
  int *local_c;
  int local_8;
  
  iVar2 = props_getInt(param_1);
  local_8 = iVar2;
  if ((0 < *(int *)(param_1 + 0x40)) &&
     (*(int *)(param_1 + 0x18) + iVar2 * -8 < *(int *)(param_1 + 0x40) + 0x34)) {
    *(undefined4 *)(param_1 + 0x138) = 1;
    props_setError(param_1,0x33);
    return 0;
  }
  piVar3 = (int *)props_allocList(param_1,iVar2);
  if (piVar3 != (int *)0x0) {
    iVar4 = 0;
    *(int *)(*piVar3 + 0x10) = iVar2;
    if (0 < iVar2) {
      iVar2 = 0x28;
      do {
        _DAT_68197764 =
             (uint *)(**(int **)(param_1 + 0x10) + (iVar4 - *(int *)(param_1 + 0x20)) * 8 +
                     *(int *)(param_1 + 0x18));
        local_c = (int *)DAT_6819776c;
        local_10 = DAT_68197768;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          local_c = (int *)((int *)(size_t)_DAT_68197764)[1];
          local_10 = *(int *)(size_t)_DAT_68197764;
        }
        if ((local_10 & 1) != 0) {
          props_retainValue(param_1,&local_10);
        }
        iVar1 = *piVar3;
        *(uint *)(iVar1 + iVar2) = local_10;
        *(int **)(iVar1 + 4 + iVar2) = local_c;
        iVar4 = iVar4 + 1;
        iVar2 = iVar2 + 8;
      } while (iVar4 < local_8);
    }
    local_10 = 3;
    local_c = piVar3;
    props_popArgs(param_1,&local_10);
    return 0;
  }
  props_setError(param_1,2);
  return 0;
}



// ============================================================
// Function: props_buildRectFilterList (FUN_6803d4e0)
// Address: 6803d4e0
// Size: 196 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_buildRectFilterList(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  iVar2 = *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x4e4) + 0x14);
  iVar5 = 0;
  local_10 = (int *)props_allocList(param_1,iVar2);
  if (local_10 == (int *)0x0) {
    props_popArgs(param_1,(undefined4 *)0x0);
    return 0;
  }
  if (0 < iVar2) {
    local_8 = 0;
    iVar4 = 0x28;
    local_c = iVar2;
    do {
      piVar1 = (int *)(**(int **)(**(int **)(param_1 + 8) + 0x4e4) + 0x24 + local_8);
      iVar2 = *piVar1;
      if ((iVar2 != -1) && (piVar1[2] != 2)) {
        iVar3 = *local_10;
        *(undefined4 *)(iVar3 + iVar4) = 8;
        *(int *)(iVar3 + 4 + iVar4) = iVar2;
        iVar5 = iVar5 + 1;
        iVar4 = iVar4 + 8;
        *(int *)(*local_10 + 0x10) = iVar5;
      }
      local_8 = local_8 + 0x10;
      local_c = local_c + -1;
    } while (local_c != 0);
  }
  local_14 = 3;
  props_popArgs(param_1,&local_14);
  return 0;
}



// ============================================================
// Function: props_getRectCount (FUN_6803d5b0)
// Address: 6803d5b0
// Size: 85 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getRectCount(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x1c) = 4;
  *(undefined4 *)(param_1 + 0x20) = 0x80000000;
  props_getRectOpsCount(param_1);
  if (*(int *)(param_1 + 0x1c) == 3) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    iVar1 = **(int **)(param_1 + 0x10);
    uVar2 = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: props_assignRectVtable (FUN_6803d610)
// Address: 6803d610
// Size: 28 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_assignRectVtable(int param_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)props_getRectCount(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined ***)*puVar1 = &PTR_LAB_6818d320;
  }
  return 0;
}



// ============================================================
// Function: props_coerceAndBuildRect (FUN_6803d630)
// Address: 6803d630
// Size: 253 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall props_coerceAndBuildRect(void *this,undefined4 param_1)
{
  int local_18;
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int unaff_EBX;
  int unaff_ESI;
  int iVar4;
  void *local_8;
  
  local_8 = this;
  if (0 < unaff_EBX) {
    iVar4 = 1;
    do {
      iVar1 = props_coerceToInt(unaff_ESI,
                           (int *)(**(int **)(unaff_ESI + 0x10) + -8 +
                                   (iVar4 - *(int *)(unaff_ESI + 0x20)) * 8 +
                                  *(int *)(unaff_ESI + 0x18)),(int *)&local_8);
      if (iVar1 == 0) {
        _DAT_68197764 =
             **(int **)(unaff_ESI + 0x10) + -8 + (iVar4 - *(int *)(unaff_ESI + 0x20)) * 8 +
             *(int *)(unaff_ESI + 0x18);
        if (_DAT_68197764 != 0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          props_setErrorAndReturn(unaff_ESI,7);
          return 0;
        }
        props_setErrorAndReturn(unaff_ESI,7);
        return 0;
      }
      piVar2 = (int *)(**(int **)(unaff_ESI + 0x10) + -8 + (iVar4 - *(int *)(unaff_ESI + 0x20)) * 8
                      + *(int *)(unaff_ESI + 0x18));
      iVar1 = *piVar2;
      if ((((iVar1 != 4) && (iVar1 != 0x20)) && (iVar1 != 0x23)) || (*(int *)(unaff_ESI + 0xd4) < 0)
         ) {
        props_releaseValue(unaff_ESI,(byte)iVar1,(int *)piVar2[1]);
        puVar3 = (undefined4 *)
                 (**(int **)(unaff_ESI + 0x10) + -8 + (iVar4 - *(int *)(unaff_ESI + 0x20)) * 8 +
                 *(int *)(unaff_ESI + 0x18));
        *puVar3 = 4;
        puVar3[1] = local_8;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= unaff_EBX);
  }
  props_getRectOpsCount(unaff_ESI);
  if (*(int *)(unaff_ESI + 0x7c) == 0) {
    *(undefined4 *)**(undefined4 **)(unaff_ESI + 0x20) = param_1;
  }
  return 0;
}



// ============================================================
// Function: props_buildRectFromInts (FUN_6803d730)
// Address: 6803d730
// Size: 29 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall props_buildRectFromInts(void *param_1)
{
  props_coerceAndBuildRect(param_1,&PTR_LAB_6818d410);
  return 0;
}



// ============================================================
// Function: props_computeRectOp (FUN_6803d750)
// Address: 6803d750
// Size: 141 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_computeRectOp(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x20) = param_2[1];
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x20) = *param_2;
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x20) = param_2[3];
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x20) = param_2[2];
  props_pushValue(param_1);
  *(undefined1 **)(param_1 + 0x20) = &DAT_80000004;
  props_getRectOpsCount(param_1);
  if (*(int *)(param_1 + 0x7c) == 0) {
    *(undefined ***)**(undefined4 **)(param_1 + 0x20) = &PTR_LAB_6818d410;
    *param_3 = *(undefined4 *)(param_1 + 0x1c);
    param_3[1] = *(undefined4 *)(param_1 + 0x20);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    iVar1 = **(int **)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  }
  return 0;
}



// ============================================================
// Function: props_extractRectAndBuild (FUN_6803d7e0)
// Address: 6803d7e0
// Size: 239 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int props_extractRectAndBuild(void)
{
  int iVar1;
  int unaff_ESI;
  undefined4 local_30 [2];
  undefined4 local_28 [2];
  int local_20;
  int local_1c;
  undefined4 local_18 [4];
  uint local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 != 2) {
    props_setError(unaff_ESI,0x16);
    return 0;
  }
  _DAT_68197764 =
       (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
              *(int *)(unaff_ESI + 0x18));
  local_1c = DAT_6819776c;
  local_20 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_1c = ((int *)(size_t)_DAT_68197764)[1];
    local_20 = *(int *)(size_t)_DAT_68197764;
  }
  iVar1 = props_getRectField(unaff_ESI,&local_20);
  if (iVar1 != 0) {
    props_extractRectOrigin(unaff_ESI);
    props_composeRect(unaff_ESI,local_30,local_28,local_18);
    props_computeRectOp(unaff_ESI,local_18,&local_20);
    props_popArgs(unaff_ESI,&local_20);
    return 0;
  }
  props_setErrorAndReturn(unaff_ESI,0xf);
  return 0;
}



// ============================================================
// Function: props_buildPointFromInts (FUN_6803d8d0)
// Address: 6803d8d0
// Size: 29 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall props_buildPointFromInts(void *param_1)
{
  props_coerceAndBuildRect(param_1,&PTR_LAB_6818d3c0);
  return 0;
}



// ============================================================
// Function: props_transformRect (FUN_6803d8f0)
// Address: 6803d8f0
// Size: 117 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_transformRect(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x20) = param_2[1];
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x20) = *param_2;
  props_pushValue(param_1);
  *(undefined1 **)(param_1 + 0x20) = &DAT_80000002;
  props_getRectOpsCount(param_1);
  if (*(int *)(param_1 + 0x7c) == 0) {
    *(undefined ***)**(undefined4 **)(param_1 + 0x20) = &PTR_LAB_6818d3c0;
    *param_3 = *(undefined4 *)(param_1 + 0x1c);
    param_3[1] = *(undefined4 *)(param_1 + 0x20);
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    iVar1 = **(int **)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  }
  return 0;
}



// ============================================================
// Function: props_assignPointVtable (FUN_6803d970)
// Address: 6803d970
// Size: 28 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_assignPointVtable(int param_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)props_getRectCount(param_1);
  if (puVar1 != (undefined4 *)0x0) {
    *(undefined ***)*puVar1 = &PTR_LAB_6818d478;
  }
  return 0;
}



// ============================================================
// Function: props_compareRectLists (FUN_6803d990)
// Address: 6803d990
// Size: 1027 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 props_compareRectLists(int param_1,int *param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  undefined3 extraout_var;
  int iVar5;
  int iVar6;
  int *extraout_EDX;
  int *extraout_EDX_00;
  int *piVar7;
  uint local_34;
  int *local_30;
  uint local_2c;
  int *local_28;
  uint local_24;
  code *local_20;
  int local_1c;
  uint local_18;
  int *local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  iVar3 = param_1;
  local_1c = 0;
  local_8 = 0;
  local_10 = 2;
  switch(param_3) {
  case 0xc:
    local_8 = 0;
    goto LAB_6803d9f3;
  case 0xd:
    local_10 = 1;
    local_8 = 1;
    break;
  case 0xe:
    local_10 = 0;
    local_8 = 1;
    break;
  case 0xf:
    local_10 = 0;
    local_8 = 0;
    break;
  case 0x10:
    local_10 = 1;
    local_8 = 0;
    break;
  case 0x11:
    local_8 = 1;
LAB_6803d9f3:
    local_10 = -1;
    break;
  default:
    goto switchD_6803d9b3_default;
  }
  param_3 = 0x24;
switchD_6803d9b3_default:
  local_20 = *(code **)(*(int *)(**(int **)(param_1 + 8) + 0x4e0) + param_3 * 4);
  _DAT_68197764 = (uint *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  if (_DAT_68197764 == (uint *)0x0) {
    local_2c = DAT_68197768;
    local_28 = DAT_6819776c;
  }
  else {
    DAT_6819776c = (int *)0x0;
    DAT_68197768 = 0;
    local_2c = *(int *)(size_t)_DAT_68197764;
    local_28 = (int *)((int *)(size_t)_DAT_68197764)[1];
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -0x10;
  local_34 = *(uint *)(param_1 + 0x1c);
  puVar1 = (uint *)(param_1 + 0x1c);
  local_18 = local_2c;
  local_30 = *(int **)(param_1 + 0x20);
  local_14 = local_28;
  iVar5 = **(int **)(param_1 + 0x10);
  *puVar1 = *(uint *)(iVar5 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar5 + 4 + *(int *)(param_1 + 0x18));
  bVar4 = js_isGCActive();
  if (CONCAT31(extraout_var,bVar4) != 0) {
    props_setError(param_1,0x70);
    goto LAB_6803dd69;
  }
  if ((local_34 == 3) && (local_30 == param_2)) {
    iVar5 = props_setRectField(param_1,(int *)&local_18);
    piVar7 = extraout_EDX;
    if (iVar5 == 0) {
      local_14 = (int *)0x1;
      local_1c = 1;
      local_c = *(uint *)(*extraout_EDX + 0x10);
      param_1 = 0;
      if (0 < (int)local_c) {
        iVar5 = 0x28;
        do {
          props_pushValue(iVar3);
          *puVar1 = local_2c;
          *(int **)(iVar3 + 0x20) = local_28;
          if ((local_2c & 1) != 0) {
            props_retainValue(iVar3,puVar1);
          }
          props_pushValue(iVar3);
          iVar6 = *local_30;
          uVar2 = *(uint *)(iVar5 + iVar6);
          *puVar1 = uVar2;
          *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar5 + 4 + iVar6);
          if ((uVar2 & 1) != 0) {
            props_retainValue(iVar3,puVar1);
          }
          (*local_20)(iVar3,0);
          if (*(int *)(iVar3 + 0x7c) != 0) goto LAB_6803dd69;
          param_1 = param_1 + 1;
          iVar5 = iVar5 + 8;
        } while (param_1 < (int)local_c);
      }
    }
    else {
LAB_6803db65:
      local_c = *(uint *)(*local_28 + 0x10);
      uVar2 = *(uint *)(*piVar7 + 0x10);
      local_14 = (int *)(local_c - uVar2);
      if ((int)uVar2 < (int)local_c) {
        local_c = uVar2;
      }
      param_1 = 0;
      if (0 < (int)local_c) {
        iVar5 = 0x28;
        do {
          props_pushValue(iVar3);
          iVar6 = *local_28;
          uVar2 = *(uint *)(iVar5 + iVar6);
          *puVar1 = uVar2;
          *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar5 + 4 + iVar6);
          if ((uVar2 & 1) != 0) {
            props_retainValue(iVar3,puVar1);
          }
          props_pushValue(iVar3);
          iVar6 = *local_30;
          uVar2 = *(uint *)(iVar5 + iVar6);
          *puVar1 = uVar2;
          *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar5 + 4 + iVar6);
          if ((uVar2 & 1) != 0) {
            props_retainValue(iVar3,puVar1);
          }
          (*local_20)(iVar3,0);
          if (*(int *)(iVar3 + 0x7c) != 0) goto LAB_6803dd69;
          param_1 = param_1 + 1;
          iVar5 = iVar5 + 8;
        } while (param_1 < (int)local_c);
      }
    }
  }
  else {
    iVar5 = props_setRectField(param_1,(int *)&local_34);
    piVar7 = extraout_EDX_00;
    if (iVar5 != 0) goto LAB_6803db65;
    local_14 = (int *)0x1;
    local_1c = 1;
    local_c = *(uint *)(*local_28 + 0x10);
    param_1 = 0;
    if (0 < (int)local_c) {
      iVar5 = 0x28;
      do {
        props_pushValue(iVar3);
        iVar6 = *local_28;
        uVar2 = *(uint *)(iVar5 + iVar6);
        *puVar1 = uVar2;
        *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar5 + 4 + iVar6);
        if ((uVar2 & 1) != 0) {
          props_retainValue(iVar3,puVar1);
        }
        props_pushValue(iVar3);
        *puVar1 = local_34;
        *(int **)(iVar3 + 0x20) = local_30;
        if ((local_34 & 1) != 0) {
          props_retainValue(iVar3,puVar1);
        }
        (*local_20)(iVar3,0);
        if (*(int *)(iVar3 + 0x7c) != 0) goto LAB_6803dd69;
        param_1 = param_1 + 1;
        iVar5 = iVar5 + 8;
      } while (param_1 < (int)local_c);
    }
  }
  props_pushValue(iVar3);
  *puVar1 = 4;
  *(uint *)(iVar3 + 0x20) = local_c | 0x80000000;
  props_getRectOpsCount(iVar3);
  iVar5 = local_10;
  if (*(int *)(iVar3 + 0x7c) != 0) goto LAB_6803dd69;
  if ((((undefined4 *)*param_2)[8] == 0) && ((local_1c != 0 || (local_14 == (int *)0x0)))) {
    *(undefined4 *)**(undefined4 **)(iVar3 + 0x20) = *(undefined4 *)*param_2;
  }
  if (param_3 != 0x24) goto LAB_6803dd69;
  local_24 = *puVar1;
  local_20 = *(code **)(iVar3 + 0x20);
  *puVar1 = 4;
  if (local_10 == 0) {
    if (local_14 == (int *)0x0) {
LAB_6803dd26:
      iVar6 = props_findListHandle();
      *(int *)(iVar3 + 0x20) = iVar6;
      if (((iVar6 == 0) && (*(int *)(*(int *)local_20 + 0x10) == 0)) && (local_14 != (int *)0x0)) {
        *(undefined4 *)(iVar3 + 0x20) = 1;
      }
      if (iVar5 != 2) {
        iVar6 = *(int *)(iVar3 + 0x20);
        goto LAB_6803dd52;
      }
    }
    else {
      *(uint *)(iVar3 + 0x20) = local_8;
    }
  }
  else {
    if ((local_14 == (int *)0x0) || (local_1c != 0)) goto LAB_6803dd26;
    iVar6 = (uint)(-1 < (int)local_14) * 2 + -1;
    *(int *)(iVar3 + 0x20) = iVar6;
    if (local_10 == 2) goto LAB_6803dd5b;
LAB_6803dd52:
    *(uint *)(iVar3 + 0x20) = iVar6 == iVar5 ^ local_8;
  }
LAB_6803dd5b:
  props_releaseValue(iVar3,(byte)local_24,(int *)local_20);
LAB_6803dd69:
  props_releaseValue(iVar3,(byte)local_2c,local_28);
  props_releaseValue(iVar3,(byte)local_34,local_30);
  return 1;
}



// ============================================================
// Function: props_buildRectOffset (FUN_6803ddb0)
// Address: 6803ddb0
// Size: 122 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall props_buildRectOffset(int param_1)
{
  int iVar1;
  int *unaff_ESI;
  undefined4 local_28 [2];
  uint local_20;
  uint local_1c;
  int local_18 [4];
  uint local_8;
  
  iVar1 = props_getTypedValue(param_1,2,4,&local_1c);
  if (iVar1 != 0) {
    iVar1 = props_getTypedValue(param_1,3,4,&local_20);
    if (iVar1 != 0) {
      props_getListCount(unaff_ESI);
      props_offsetRect(param_1,local_18,local_1c,local_20);
      props_computeRectOp(param_1,local_18,local_28);
      props_popArgs(param_1,local_28);
    }
  }
  return 0;
}



// ============================================================
// Function: props_buildRectInset (FUN_6803de30)
// Address: 6803de30
// Size: 122 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall props_buildRectInset(int param_1)
{
  int iVar1;
  int *unaff_ESI;
  undefined4 local_28 [2];
  uint local_20;
  uint local_1c;
  int local_18 [4];
  uint local_8;
  
  iVar1 = props_getTypedValue(param_1,2,4,&local_1c);
  if (iVar1 != 0) {
    iVar1 = props_getTypedValue(param_1,3,4,&local_20);
    if (iVar1 != 0) {
      props_getListCount(unaff_ESI);
      props_insetRect(param_1,local_18,local_1c,local_20);
      props_computeRectOp(param_1,local_18,local_28);
      props_popArgs(param_1,local_28);
    }
  }
  return 0;
}



// ============================================================
// Function: props_buildRectIntersect (FUN_6803deb0)
// Address: 6803deb0
// Size: 238 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall props_buildRectIntersect(int param_1)
{
  int iVar1;
  int *unaff_ESI;
  int local_30;
  int local_2c;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 != 2) {
    props_setError(param_1,0x16);
    return 0;
  }
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
              *(int *)(param_1 + 0x18));
  local_2c = DAT_6819776c;
  local_30 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_2c = ((int *)(size_t)_DAT_68197764)[1];
    local_30 = *(int *)(size_t)_DAT_68197764;
  }
  iVar1 = props_createRect(param_1,&local_30);
  if (iVar1 != 0) {
    props_getListCount(unaff_ESI);
    props_intersectTwoRects(param_1,local_18,local_28,local_18);
    props_computeRectOp(param_1,local_18,&local_30);
    props_popArgs(param_1,&local_30);
    return 0;
  }
  props_setErrorAndReturn(param_1,0xe);
  return 0;
}



// ============================================================
// Function: props_buildRectUnion (FUN_6803dfc0)
// Address: 6803dfc0
// Size: 238 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall props_buildRectUnion(int param_1)
{
  int iVar1;
  int *unaff_ESI;
  int local_30;
  int local_2c;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 != 2) {
    props_setError(param_1,0x16);
    return 0;
  }
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
              *(int *)(param_1 + 0x18));
  local_2c = DAT_6819776c;
  local_30 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_2c = ((int *)(size_t)_DAT_68197764)[1];
    local_30 = *(int *)(size_t)_DAT_68197764;
  }
  iVar1 = props_createRect(param_1,&local_30);
  if (iVar1 != 0) {
    props_getListCount(unaff_ESI);
    props_unionTwoRects(param_1,local_18,local_28,local_18);
    props_computeRectOp(param_1,local_18,&local_30);
    props_popArgs(param_1,&local_30);
    return 0;
  }
  props_setErrorAndReturn(param_1,0xe);
  return 0;
}


