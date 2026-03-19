// Module: stage
// Topic: Property method dispatch and iteration
// Address range: 0x68051EE0 - 0x680524B0
// Functions (8):
//   stage_resolvePropAccess (FUN_68051EE0)
//   stage_dispatchPropCall (stage_dispatchPropCall)
//   stage_getPropFromObject (FUN_680521A0)
//   stage_dispatchPropSet (stage_dispatchPropSet)
//   stage_iterateInit (FUN_680522D0)
//   stage_iterateNext (FUN_68052360)
//   stage_dispatchPropGet (stage_dispatchPropGet)
//   stage_loadPropRef (FUN_680524B0)

// ============================================================
// Function: stage_resolvePropAccess (FUN_68051EE0)
// Address: 68051ee0
// Size: 323 bytes
// Params: int param_1, uint param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_resolvePropAccess(int param_1,uint param_2,uint *param_3)
{
  uint *puVar1;
  int iVar2;
  uint *in_EAX;
  int iVar3;
  int unaff_ESI;
  
  iVar2 = **(int **)(unaff_ESI + 0x28);
  if (-1 < (int)param_2) {
    if (*in_EAX == 3) {
      iVar3 = (**(code **)(**(int **)in_EAX[1] + 0x18))();
      if (iVar3 != 0) {
        if (param_1 != 0) {
          return 0;
        }
        if (param_2 != 0xfc) {
          return 0;
        }
        if ((*param_3 != 0x40) && (*param_3 != 0x43)) {
          return 0;
        }
        sprites_getCastRefByName(unaff_ESI,(int *)param_3);
        return 0;
      }
      if ((*(int *)(unaff_ESI + 0x7c) != 0) &&
         (iVar3 = score_getMediaValue(unaff_ESI,(int *)in_EAX), iVar3 != 0)) {
        return 0;
      }
    }
    if (param_1 != 0) {
      props_reportError(unaff_ESI,0x37);
      return 0;
    }
    props_pushValue(unaff_ESI);
    puVar1 = (uint *)(unaff_ESI + 0x1c);
    *puVar1 = *in_EAX;
    *(uint *)(unaff_ESI + 0x20) = in_EAX[1];
    props_retainValue(unaff_ESI,puVar1);
    props_pushValue(unaff_ESI);
    *(undefined4 *)(unaff_ESI + 0x20) = 0x80000001;
    iVar3 = props_resolveSymbol(unaff_ESI,param_2);
    *(int *)(unaff_ESI + 0xa4) = iVar3;
    if ((iVar3 < 0) || (*(int *)(iVar2 + 0x14) <= iVar3)) {
      *(undefined4 *)(unaff_ESI + 0x7c) = 0x33;
    }
    else {
      (**(code **)(iVar2 + 0x20 + iVar3 * 0x18))();
    }
    if (*(int *)(unaff_ESI + 0x7c) == 0) {
      *param_3 = *puVar1;
      param_3[1] = *(uint *)(unaff_ESI + 0x20);
      *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
      iVar2 = **(int **)(unaff_ESI + 0x10);
      *puVar1 = *(uint *)(iVar2 + *(int *)(unaff_ESI + 0x18));
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(iVar2 + 4 + *(int *)(unaff_ESI + 0x18));
    }
    else if (*(int *)(unaff_ESI + 0x7c) == 4) {
      props_reportError(unaff_ESI,0x37);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_dispatchPropCall (FUN_68052030)
// Address: 68052030
// Size: 354 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchPropCall(int param_1,int param_2)
{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  uint local_c;
  undefined4 local_8;
  
  uVar4 = props_getSymbolId(param_1,param_2);
  iVar5 = *(int *)(param_1 + 0x1c);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  piVar2 = *(int **)(param_1 + 0x20);
  puVar1 = (uint *)(param_1 + 0x1c);
  iVar3 = **(int **)(param_1 + 0x10);
  *puVar1 = *(uint *)(iVar3 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x18));
  local_c = 4;
  local_8 = 0;
  if (iVar5 != 3) {
    props_setErrorAndReturn(param_1,0xc);
    return 0;
  }
  iVar5 = (**(code **)(*(int *)*piVar2 + 0x2c))(param_1,piVar2,uVar4,&local_c);
  if (*(int *)(param_1 + 0x7c) == 0) {
    if (iVar5 == 0) {
      props_pushValue(param_1);
      *puVar1 = 3;
      *(int **)(param_1 + 0x20) = piVar2;
      props_retainValue(param_1,puVar1);
      props_pushValue(param_1);
      *(undefined4 *)(param_1 + 0x20) = 0x80000001;
      iVar5 = **(int **)(param_1 + 0x28);
      if ((param_2 < 0) || (*(int *)(iVar5 + 0x14) <= param_2)) {
        *(undefined4 *)(param_1 + 0xa4) = 0;
        *(undefined4 *)(param_1 + 0x7c) = 0x33;
      }
      else {
        *(int *)(param_1 + 0xa4) = param_2;
        (**(code **)(iVar5 + 0x20 + param_2 * 0x18))(param_1);
      }
      if (*(int *)(param_1 + 0x7c) != 0) {
        if (*(int *)(param_1 + 0x7c) != 4) {
          return 0;
        }
        props_reportError(param_1,0x37);
        return 0;
      }
      local_c = *puVar1;
      local_8 = *(undefined4 *)(param_1 + 0x20);
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      iVar5 = **(int **)(param_1 + 0x10);
      *puVar1 = *(uint *)(iVar5 + *(int *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar5 + 4 + *(int *)(param_1 + 0x18));
    }
    props_releaseValue(param_1,3,piVar2);
    if (*(int *)(param_1 + 0x7c) == 0) {
      props_pushValue(param_1);
      *puVar1 = local_c;
      *(undefined4 *)(param_1 + 0x20) = local_8;
    }
    return 0;
  }
  props_releaseValue(param_1,3,piVar2);
  return 0;
}



// ============================================================
// Function: stage_getPropFromObject (FUN_680521A0)
// Address: 680521a0
// Size: 131 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getPropFromObject(int param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  local_c = *(undefined4 *)(param_1 + 0x1c);
  local_8 = *(int **)(param_1 + 0x20);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar1 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
  puVar3 = &local_14;
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  local_14 = 4;
  local_10 = 0;
  uVar2 = props_getSymbolId(param_1,param_2);
  stage_resolvePropAccess(0,uVar2,puVar3);
  props_releaseValue(param_1,(byte)local_c,local_8);
  if (*(int *)(param_1 + 0x7c) == 0) {
    props_pushValue(param_1);
    *(uint *)(param_1 + 0x1c) = local_14;
    *(undefined4 *)(param_1 + 0x20) = local_10;
  }
  return 0;
}



// ============================================================
// Function: stage_dispatchPropSet (FUN_68052230)
// Address: 68052230
// Size: 147 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchPropSet(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint local_14;
  int *local_10;
  undefined4 local_c;
  int *local_8;
  
  local_10 = *(int **)(param_1 + 0x20);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  local_14 = *(uint *)(param_1 + 0x1c);
  iVar1 = **(int **)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x18);
  local_c = *(undefined4 *)(iVar2 + iVar1);
  *(undefined4 *)(param_1 + 0x1c) = local_c;
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar2 + 4 + iVar1);
  local_8 = *(int **)(param_1 + 0x20);
  *(int *)(param_1 + 0x18) = iVar2 + -8;
  iVar1 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar2 + -8 + iVar1);
  puVar4 = &local_14;
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar2 + -4 + iVar1);
  uVar3 = props_getSymbolId(param_1,param_2);
  stage_resolvePropAccess(1,uVar3,puVar4);
  props_releaseValue(param_1,(byte)local_c,local_8);
  if (*(int *)(param_1 + 0x7c) == 0) {
    props_releaseValue(param_1,(byte)local_14,local_10);
  }
  return 0;
}



// ============================================================
// Function: stage_iterateInit (FUN_680522D0)
// Address: 680522d0
// Size: 135 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_iterateInit(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar2 = props_growStack(param_1,0x10);
  if (iVar2 != 0) {
    if (*(int *)(param_1 + 0x1c) != 3) {
      props_setErrorAndReturn(param_1,0x38);
      return 0;
    }
    puVar1 = *(undefined4 **)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x88);
    *(undefined4 **)(param_1 + 0x88) = puVar1;
    props_pushValue(param_1);
    uVar3 = (**(code **)(*(int *)*puVar1 + 0x1c))(param_1,puVar1);
    *(undefined4 *)(param_1 + 0x1c) = 4;
    *(undefined4 *)(param_1 + 0x20) = uVar3;
    props_pushValue(param_1);
    *(undefined4 **)(param_1 + 0x88) = puVar1;
    *(undefined4 *)(param_1 + 0x1c) = 4;
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_1 + 0x8c);
    *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x18);
  }
  return 0;
}



// ============================================================
// Function: stage_iterateNext (FUN_68052360)
// Address: 68052360
// Size: 147 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_iterateNext(int param_1)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  piVar1 = *(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x8c) = *(undefined4 *)(param_1 + 0x20);
  iVar2 = *piVar1;
  iVar7 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar2 + iVar7);
  uVar3 = *(undefined4 *)(iVar2 + 4 + iVar7);
  *(undefined4 *)(param_1 + 0x20) = uVar3;
  iVar6 = iVar7 + -8;
  *(int *)(param_1 + 0x18) = iVar6;
  iVar2 = *piVar1;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar2 + iVar6);
  uVar4 = *(undefined4 *)(iVar2 + 4 + iVar6);
  iVar7 = iVar7 + -0x10;
  *(undefined4 *)(param_1 + 0x20) = uVar4;
  piVar5 = *(int **)(param_1 + 0x88);
  *(undefined4 *)(param_1 + 0x88) = uVar4;
  *(int *)(param_1 + 0x18) = iVar7;
  iVar2 = *piVar1;
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar2 + iVar7);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar2 + 4 + iVar7);
  if (piVar5 != (int *)0x0) {
    iVar2 = ((int *)*piVar5)[1];
    (**(code **)(*(int *)*piVar5 + 0x20))(param_1,piVar5,uVar3);
    if (0 < iVar2) {
      props_releaseValue(param_1,3,piVar5);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_dispatchPropGet (FUN_68052400)
// Address: 68052400
// Size: 161 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchPropGet(int param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  
  iVar2 = props_getInt(param_1);
  if ((0 < iVar2) &&
     (piVar3 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                      *(int *)(param_1 + 0x18)), *piVar3 == 3)) {
    if ((param_2 < 0) || (*(int *)(**(int **)(param_1 + 0x28) + 0x14) <= param_2)) {
      *(undefined4 *)(param_1 + 0x7c) = 0x33;
    }
    else {
      puVar1 = (undefined4 *)piVar3[1];
      iVar2 = (**(code **)(*(int *)*puVar1 + 4))
                        (param_1,puVar1,
                         *(undefined4 *)(**(int **)(param_1 + 0x28) + 0x24 + param_2 * 0x18));
      if (iVar2 != 0) {
        return 0;
      }
    }
  }
  puVar1 = *(undefined4 **)(param_1 + 0x88);
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = *(int *)*puVar1;
    uVar4 = props_getSymbolId(param_1,param_2);
    iVar2 = (**(code **)(iVar2 + 0x24))(param_1,puVar1,uVar4);
    if (iVar2 == 0) {
      props_getSymbolId(param_1,param_2);
      props_reportError(param_1,4);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_loadPropRef (FUN_680524B0)
// Address: 680524b0
// Size: 127 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int stage_loadPropRef(int param_1,int param_2)
{
  uint local_c;
  uint local_8;
  
  if (param_2 == 0) {
    local_c = *(uint *)(param_1 + 0x1c);
    local_8 = *(uint *)(param_1 + 0x20);
  }
  else {
    _DAT_68197764 = (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x18) + param_2 * -8);
    local_c = DAT_68197768;
    local_8 = DAT_6819776c;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_c = *(int *)(size_t)_DAT_68197764;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
    }
  }
  props_retainValue(param_1,&local_c);
  props_pushValue(param_1);
  *(uint *)(param_1 + 0x1c) = local_c;
  *(uint *)(param_1 + 0x20) = local_8;
  return 0;
}



