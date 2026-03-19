// Module: props
// Topic: Property access, variable resolution, dispatch
// Address range: 0x68030b60 - 0x6803aec0
// Functions (10):
//   props_extractObject (FUN_68030b60)
//   props_getProperty (FUN_68031fe0)
//   props_getLocalProperty (FUN_680320a0)
//   props_ensureProperty (FUN_680320f0)
//   props_resolveVariable (FUN_68032140)
//   props_dispatchVariable (FUN_68032320)
//   props_lookupVariable (FUN_68032660)
//   props_accessProperty (FUN_68032cc0)
//   props_getInt (FUN_68032de0)
//   props_setProperty (FUN_6803aec0)



// ============================================================
// Function: props_extractObject (FUN_68030b60)
// Address: 68030b60
// Size: 34 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// Extracts an object pointer from a value pair if type is object (3)
// ============================================================

undefined4 props_extractObject(undefined4 param_1,int *param_2,int *param_3)

{
  if (*param_2 == 3) {
    *param_3 = param_2[1];
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_getProperty (FUN_68031fe0)
// Address: 68031fe0
// Size: 181 bytes
// Params: int param_1, uint param_2, int param_3, undefined4 * param_4
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * props_getProperty(int param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  
  if (((int)param_2 < 0) ||
     (iVar1 = **(int **)(param_1 + 0x28), *(int *)(iVar1 + 0x14) <= (int)param_2)) {
    props_setError(param_1,0x33);
    return (uint *)0x0;
  }
  iVar2 = param_2 * 0x18;
  if (param_4 != (undefined4 *)0x0) {
    *param_4 = *(undefined4 *)(iVar2 + 0x24 + iVar1);
  }
  param_2 = *(uint *)(iVar2 + 0x28 + iVar1);
  if ((int)param_2 < 0) {
    puVar3 = score_lookupProperty(*(int **)(**(int **)(param_1 + 8) + 0x4e4),*(uint *)(iVar2 + 0x24 + iVar1)
                          ,param_3,&param_2);
    if (puVar3 == (uint *)0x0) {
      return (uint *)0x0;
    }
    *(uint *)(**(int **)(param_1 + 0x28) + 0x28 + iVar2) = param_2;
    *(uint *)(param_1 + 0xb8) = param_2;
    return puVar3;
  }
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x4e4);
  *(uint *)(param_1 + 0xb8) = param_2;
  return (uint *)(iVar1 + 0x2c + param_2 * 0x10);
}



// ============================================================
// Function: props_getLocalProperty (FUN_680320a0)
// Address: 680320a0
// Size: 78 bytes
// Params: int param_1, int param_2, int param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * props_getLocalProperty(int param_1,int param_2,int param_3)

{
  uint uVar1;
  uint *puVar2;
  
  if (*(int *)(param_1 + 0x60) == 0) {
    return (uint *)0x0;
  }
  uVar1 = props_getSymbolId(param_1,param_2);
  if ((param_3 != 0) && (uVar1 == 0xfd)) {
    sprites_resetChannel();
  }
  puVar2 = score_lookupProperty(*(int **)(param_1 + 0x60),uVar1,1,(uint *)0x0);
  return puVar2;
}



// ============================================================
// Function: props_ensureProperty (FUN_680320f0)
// Address: 680320f0
// Size: 76 bytes
// Params: int param_1, uint param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_ensureProperty(int param_1,uint param_2,int param_3)
{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  
  puVar1 = props_getProperty(param_1,param_2,param_3,(undefined4 *)0x0);
  if (puVar1 == (uint *)0x0) {
    if (param_3 != 0) {
      return 0;
    }
    puVar1 = (uint *)0x0;
    iVar3 = 0;
    uVar2 = props_getSymbolId(param_1,param_2);
    score_lookupProperty(*(int **)(**(int **)(param_1 + 8) + 0x4e8),uVar2,iVar3,puVar1);
  }
  return 0;
}



// ============================================================
// Function: props_resolveVariable (FUN_68032140)
// Address: 68032140
// Size: 471 bytes
// Params: int param_1, uint param_2, int param_3, int param_4
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * props_resolveVariable(int param_1,uint param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  
  piVar1 = *(int **)(param_1 + 0x60);
  if (piVar1 != (int *)0x0) {
    puVar8 = (uint *)0x0;
    iVar7 = 0;
    uVar3 = props_getSymbolId(param_1,param_2);
    puVar8 = score_lookupProperty(piVar1,uVar3,iVar7,puVar8);
    if (puVar8 != (uint *)0x0) {
      return puVar8;
    }
  }
  if (param_4 == 0) {
    iVar7 = **(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x40);
  }
  else {
    iVar7 = param_1 + 0x40;
  }
  if (*(int **)(iVar7 + 0x10) != (int *)0x0) {
    iVar2 = **(int **)(iVar7 + 0x10);
    iVar6 = *(int *)(iVar2 + 0x84) + *(int *)(iVar7 + 0x14) * 0x3c;
    iVar4 = iVar6 + iVar2;
    puVar8 = (uint *)(*(int *)(iVar7 + 8) + **(int **)(param_1 + 0x10));
    puVar5 = (uint *)(*(int *)(iVar6 + 0x1c + iVar2) + iVar2);
    for (iVar6 = *(int *)(iVar4 + 0x18); 0 < iVar6; iVar6 = iVar6 + -1) {
      if (*puVar5 == param_2) {
        return puVar8;
      }
      puVar5 = puVar5 + 1;
      puVar8 = puVar8 + 2;
    }
    puVar8 = (uint *)(*(int *)(iVar7 + 4) + **(int **)(param_1 + 0x10));
    puVar5 = (uint *)(*(int *)(iVar4 + 0x14) + iVar2);
    for (iVar6 = *(int *)(iVar4 + 0x10); 0 < iVar6; iVar6 = iVar6 + -1) {
      if (*puVar5 == param_2) {
        return puVar8;
      }
      puVar5 = puVar5 + 1;
      puVar8 = puVar8 + 2;
    }
    puVar8 = (uint *)(*(int *)(iVar2 + 0x74) + iVar2);
    for (iVar6 = *(int *)(iVar2 + 0x70); 0 < iVar6; iVar6 = iVar6 + -1) {
      if (*puVar8 == param_2) {
        piVar1 = *(int **)(iVar7 + 0x20);
        if (piVar1 == (int *)0x0) {
          return (uint *)0x0;
        }
        puVar8 = (uint *)0x0;
        iVar7 = 1;
        uVar3 = props_getSymbolId(param_1,param_2);
        puVar8 = score_lookupProperty(piVar1,uVar3,iVar7,puVar8);
        return puVar8;
      }
      puVar8 = puVar8 + 1;
    }
    puVar8 = (uint *)(*(int *)(iVar4 + 0x24) + iVar2);
    for (iVar6 = *(int *)(iVar4 + 0x20); 0 < iVar6; iVar6 = iVar6 + -1) {
      if (*puVar8 == param_2) {
        puVar8 = props_getProperty(param_1,param_2,1,(undefined4 *)0x0);
        return puVar8;
      }
      puVar8 = puVar8 + 1;
    }
  }
  if (param_3 == 0) {
    puVar8 = props_getProperty(param_1,param_2,0,(undefined4 *)0x0);
    if (puVar8 == (uint *)0x0) {
      puVar5 = puVar8;
      uVar3 = props_getSymbolId(param_1,param_2);
      puVar8 = score_lookupProperty(*(int **)(**(int **)(param_1 + 8) + 0x4e8),uVar3,(int)puVar8,puVar5);
    }
    return puVar8;
  }
  if ((*(byte *)(iVar7 + 0x28) & 4) != 0) {
    puVar8 = props_getProperty(param_1,param_2,1,(undefined4 *)0x0);
    return puVar8;
  }
  if (*(int *)(param_1 + 0x60) == 0) {
    iVar7 = score_getSymbolName(0xf,0x18);
    *(int *)(param_1 + 0x60) = iVar7;
    if (iVar7 == 0) {
      return (uint *)0x0;
    }
  }
  puVar8 = (uint *)0x0;
  iVar7 = 1;
  uVar3 = props_getSymbolId(param_1,param_2);
  puVar8 = score_lookupProperty(*(int **)(param_1 + 0x60),uVar3,iVar7,puVar8);
  return puVar8;
}



// ============================================================
// Function: props_dispatchVariable (FUN_68032320)
// Address: 68032320
// Size: 253 bytes
// Params: int param_1, undefined4 param_2, uint param_3, int param_4
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * props_dispatchVariable(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  switch(param_2) {
  case 0:
    puVar1 = props_resolveVariable(param_1,param_3,param_4,0);
    return puVar1;
  case 1:
    puVar1 = (uint *)props_ensureProperty(param_1,param_3,param_4);
    return puVar1;
  case 2:
    puVar1 = props_getProperty(param_1,param_3,param_4,(undefined4 *)0x0);
    return puVar1;
  case 3:
    puVar1 = props_getLocalProperty(param_1,param_3,param_4);
    return puVar1;
  case 4:
    if ((int)(param_3 * 8) < 0) {
      return (uint *)0x0;
    }
    uVar4 = *(uint *)(param_1 + 0x44);
    break;
  case 5:
    if ((int)(param_3 * 8) < 0) {
      return (uint *)0x0;
    }
    uVar4 = *(uint *)(param_1 + 0x48);
    break;
  default:
    props_setError(param_1,0x33);
    return (uint *)0x0;
  }
  uVar3 = param_3 * 8;
  uVar2 = ((int)uVar4 >> 0x1f) + ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar4,uVar3);
  if (((-2 < (int)uVar2) &&
      (((uVar2 < 0x80000000 || (0x80000000 < uVar4 + uVar3)) && ((int)uVar2 < 1)))) &&
     ((((int)uVar2 < 0 || (uVar4 + uVar3 < 0x80000000)) &&
      ((int)(uVar4 + uVar3) < *(int *)(param_1 + 0x40))))) {
    return (uint *)(**(int **)(param_1 + 0x10) + uVar4 + uVar3);
  }
  return (uint *)0x0;
}



// ============================================================
// Function: props_lookupVariable (FUN_68032660)
// Address: 68032660
// Size: 222 bytes
// Params: int param_1, int * param_2, uint param_3
// Return: uint
// Calling convention: __stdcall
// Looks up a variable by symbol hash in a context's variable table
// ============================================================

uint props_lookupVariable(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int *piVar5;
  uint uVar6;
  uint uVar7;
  
  piVar3 = *(int **)(*param_2 + 0x30);
  if (piVar3 == (int *)0x0) {
    iVar1 = *(int *)(*param_2 + 0x80);
    piVar3 = (int *)score_initTableCapacity(iVar1);
    if (piVar3 == (int *)0x0) {
      return 0xffffffff;
    }
    *(int **)(*param_2 + 0x30) = piVar3;
    iVar2 = *(int *)(*param_2 + 0x20);
    if ((*(uint *)(*param_2 + 0x54) & 0x200) != 0) {
      puVar4 = score_lookupProperty(piVar3,0x39,1,(uint *)0x0);
      if (puVar4 != (uint *)0x0) {
        puVar4[1] = 0;
      }
      puVar4 = score_lookupProperty(piVar3,0x6c,1,(uint *)0x0);
      if (puVar4 != (uint *)0x0) {
        puVar4[1] = 0;
      }
    }
    uVar7 = 0;
    if (0 < iVar1) {
      do {
        piVar5 = (int *)props_getContextSlot(param_1,param_2,uVar7);
        if (-1 < *piVar5) {
          uVar6 = props_getTableEntry(param_1,iVar2,*piVar5);
          puVar4 = score_lookupProperty(piVar3,uVar6,1,(uint *)0x0);
          if (puVar4 == (uint *)0x0) break;
          puVar4[1] = uVar7;
        }
        uVar7 = uVar7 + 1;
      } while ((int)uVar7 < iVar1);
    }
  }
  puVar4 = score_lookupProperty(piVar3,param_3,0,(uint *)0x0);
  if (puVar4 == (uint *)0x0) {
    return 0xffffffff;
  }
  return puVar4[1];
}



// ============================================================
// Function: props_accessProperty (FUN_68032cc0)
// Address: 68032cc0
// Size: 276 bytes
// Params: int param_1, undefined4 * param_2, int param_3, undefined4 param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// Calls a get/set property method on an object through its vtable
// ============================================================

int props_accessProperty(int param_1,undefined4 *param_2,int param_3,undefined4 param_4,uint *param_5)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  local_8 = 0;
  props_pushValue(param_1);
  puVar1 = (uint *)(param_1 + 0x1c);
  *puVar1 = 3;
  *(undefined4 **)(param_1 + 0x20) = param_2;
  props_retainValue(param_1,puVar1);
  props_pushValue(param_1);
  *puVar1 = 8;
  *(undefined4 *)(param_1 + 0x20) = param_4;
  props_pushValue(param_1);
  if (param_3 == 0) {
    *puVar1 = 4;
    *(undefined1 **)(param_1 + 0x20) = &DAT_80000002;
    iVar3 = (**(code **)(*(int *)*param_2 + 4))(param_1,param_2,0xd4);
    if (*(int *)(param_1 + 0x7c) != 0) {
      return 0;
    }
    if (iVar3 == 0) {
      local_8 = 3;
    }
    else {
      *param_5 = *puVar1;
      param_5[1] = *(uint *)(param_1 + 0x20);
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      iVar2 = **(int **)(param_1 + 0x10);
      *puVar1 = *(uint *)(iVar2 + *(int *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar2 + 4 + *(int *)(param_1 + 0x18));
    }
  }
  else {
    *puVar1 = *param_5;
    *(uint *)(param_1 + 0x20) = param_5[1];
    props_retainValue(param_1,puVar1);
    props_pushValue(param_1);
    *puVar1 = 4;
    *(undefined4 *)(param_1 + 0x20) = 3;
    iVar3 = (**(code **)(*(int *)*param_2 + 4))(param_1,param_2,0xdb);
    if (iVar3 == 0) {
      local_8 = 4;
    }
  }
  for (; local_8 != 0; local_8 = local_8 + -1) {
    props_popValue(param_1);
  }
  return iVar3;
}



// ============================================================
// Function: props_getInt (FUN_68032de0)
// Address: 68032de0
// Size: 35 bytes
// Params: int ctx
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_getInt(int ctx)
{
  if (*(int *)(ctx + 0x1c) == 4) {
    return (int)*(short *)(ctx + 0x20);
  }
  props_setError(ctx, 0x33);
  return -1;
}



// ============================================================
// Function: props_setProperty
// Address: 6803aec0
// Size: 679 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 props_setProperty(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint local_c;
  uint local_8;
  
  piVar1 = param_2;
  param_3 = *(int *)(param_3 + 4);
  iVar4 = *(int *)(*param_2 + 0x20);
  iVar2 = props_getInt(param_1);
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (iVar4 == 1) {
    if (iVar2 < 3) {
      if (1 < iVar2) {
        _DAT_68197764 =
             (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                     *(int *)(param_1 + 0x18));
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          local_8 = ((int *)(size_t)_DAT_68197764)[1];
          local_c = *(int *)(size_t)_DAT_68197764;
        }
        if ((local_c & 1) != 0) {
          props_retainValue(param_1,&local_c);
        }
        props_binarySearch(param_1,piVar1,&local_c,(int *)&param_2);
        stage_emitStoreProperty(piVar1,(int)param_2,&local_c);
        return 1;
      }
LAB_6803af0c:
      props_setError(param_1,0x3a);
      return 0;
    }
    *(undefined4 *)(*piVar1 + 0x20) = 0;
    *(undefined ***)*piVar1 = &PTR_LAB_6818d268;
  }
  else {
    if (iVar2 == 2) {
      param_2 = *(int **)(*piVar1 + 0x10);
      _DAT_68197764 =
           (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                   *(int *)(param_1 + 0x18));
      if (_DAT_68197764 != (uint *)0x0) {
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        local_8 = ((int *)(size_t)_DAT_68197764)[1];
        local_c = *(int *)(size_t)_DAT_68197764;
      }
      goto LAB_6803b088;
    }
    if (iVar2 != 3) goto LAB_6803af0c;
  }
  iVar4 = **(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8;
  if (*(int *)(iVar4 + 8 + *(int *)(param_1 + 0x18)) == 4) {
    param_2 = *(int **)(iVar4 + *(int *)(param_1 + 0x18) + 0xc);
  }
  else {
    iVar4 = props_getTypedValue(param_1,2,4,(uint *)&param_2);
    if (iVar4 == 0) {
      return 0;
    }
  }
  if ((int)param_2 < 1) {
    props_reportError(param_1,0x3b);
    return 0;
  }
  param_2 = (int *)((int)param_2 + -1);
  _DAT_68197764 =
       (uint *)(**(int **)(param_1 + 0x10) + (2 - *(int *)(param_1 + 0x20)) * 8 +
               *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (uint *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
LAB_6803b088:
  iVar4 = *(int *)(*piVar1 + 0x10);
  if ((local_c & 1) != 0) {
    props_retainValue(param_1,&local_c);
  }
  if ((param_3 != 0) && ((int)param_2 < iVar4)) {
    props_releaseValue(param_1,(byte)*(undefined4 *)(*piVar1 + 0x28 + (int)param_2 * 8),
                 *(int **)(*piVar1 + 0x2c + (int)param_2 * 8));
    iVar4 = *piVar1;
    *(uint *)(iVar4 + 0x28 + (int)param_2 * 8) = local_c;
    *(uint *)(iVar4 + 0x2c + (int)param_2 * 8) = local_8;
    return 1;
  }
  if ((int *)0xfffffff < param_2) {
    props_reportError(param_1,0x35);
    return 0;
  }
  stage_emitStoreVar(piVar1,(int)param_2 + -1);
  iVar2 = props_checkReentrant(param_1);
  if (iVar2 != 0) {
    stage_emitStoreProperty(piVar1,(int)param_2,&local_c);
    iVar2 = props_checkReentrant(param_1);
    if (iVar2 != 0) {
      iVar2 = *(int *)(*piVar1 + 0x10) + -1;
      puVar3 = (undefined4 *)(*piVar1 + 0x28 + iVar4 * 8);
      if (iVar4 < iVar2) {
        iVar2 = iVar2 - iVar4;
        do {
          *puVar3 = 4;
          puVar3[1] = 0;
          puVar3 = puVar3 + 2;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
      }
      return 1;
    }
  }
  return 0;
}


