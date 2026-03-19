// Module: score
// Topic: PropList dispatch and handler operations
// Address range: 0x68044440 - 0x68044f80
// Functions (12):
//   score_getProplistByIndex
//   score_addProplistEntry
//   score_copyProplist
//   score_resolveProplist
//   score_initProplistDispatch
//   score_dispatchProplist
//   score_compareProplist
//   score_modifyProplist
//   score_removeProplistEntry
//   score_handleProplistCommand
//   score_destroyProplistNode
//   score_formatProplist

// ============================================================
// Function: score_getProplistByIndex (FUN_68044440)
// Address: 68044440
// Size: 247 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_getProplistByIndex(int param_1,int *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int local_c;
  int local_8;
  
  iVar3 = param_1;
  iVar2 = props_getInt(param_1);
  if (iVar2 < 2) {
    props_setError(iVar3,0x16);
    return 1;
  }
  _DAT_68197764 =
       (int *)(**(int **)(iVar3 + 0x10) + *(int *)(iVar3 + 0x20) * -8 + 8 + *(int *)(iVar3 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  iVar2 = props_coerceToInt(iVar3,&local_c,&param_1);
  puVar1 = param_3;
  if (iVar2 == 0) {
    iVar3 = score_getValueByKey(iVar3,param_2,param_3);
    if (iVar3 == 0) {
      *puVar1 = 2;
      puVar1[1] = 0;
    }
    return 1;
  }
  if ((0 < param_1) && (iVar2 = *param_2, param_1 <= *(int *)(iVar2 + 0x10))) {
    *param_3 = *(undefined4 *)(iVar2 + (param_1 + 2) * 0x10);
    param_3[1] = *(undefined4 *)(iVar2 + 4 + (param_1 + 2) * 0x10);
    return 1;
  }
  props_setError(iVar3,0x3c);
  return 0;
}


// ============================================================
// Function: score_addProplistEntry (FUN_68044540)
// Address: 68044540
// Size: 42 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_addProplistEntry(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = props_getInt(param_1);
  score_insertProplistEntry(param_1,param_2,(uint)(1 < iVar1));
  return 1;
}


// ============================================================
// Function: score_copyProplist (FUN_68044570)
// Address: 68044570
// Size: 369 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_copyProplist(int param_1,int *param_2,undefined4 *param_3)
{
  uint *puVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint local_18;
  uint local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  iVar3 = props_getInt(param_1);
  if (iVar3 == 1) {
    bVar2 = js_isGCActive();
    if (CONCAT31(extraout_var,bVar2) == 0) {
      iVar3 = *(int *)(*param_2 + 0x10);
      piVar4 = (int *)score_deleteProplistEntry(param_1,iVar3);
      if (piVar4 != (int *)0x0) {
        iVar6 = *piVar4;
        *(undefined4 *)(iVar6 + 4) = 0;
        *(int *)(iVar6 + 0x10) = iVar3;
        *(undefined4 *)(iVar6 + 0x20) = *(undefined4 *)(*param_2 + 0x20);
        *(undefined4 *)(iVar6 + 0x24) = *(undefined4 *)(*param_2 + 0x24);
        if (0 < iVar3) {
          iVar6 = 0;
          do {
            local_18 = *(uint *)(*param_2 + 0x28 + iVar6);
            iVar5 = *param_2 + 0x28 + iVar6;
            local_14 = *(uint *)(iVar5 + 4);
            local_10 = *(uint *)(iVar5 + 8);
            local_c = *(int **)(iVar5 + 0xc);
            iVar5 = props_setRectField(param_1,(int *)&local_10);
            if (iVar5 == 0) {
              iVar5 = score_getProplistValue(param_1,(int *)&local_10);
              if (iVar5 != 0) {
                score_resolveProplist(param_1,local_c,&local_10);
              }
            }
            else {
              props_cloneRectAndReturn(param_1,local_c,&local_10);
            }
            props_retainValue(param_1,&local_18);
            props_retainValue(param_1,&local_10);
            puVar1 = (uint *)(*piVar4 + 0x28 + iVar6);
            *puVar1 = local_18;
            puVar1[1] = local_14;
            puVar1[2] = local_10;
            iVar6 = iVar6 + 0x10;
            iVar3 = iVar3 + -1;
            puVar1[3] = (uint)local_c;
          } while (iVar3 != 0);
        }
        param_3[1] = piVar4;
        *param_3 = 3;
        return 0;
      }
      props_setError(param_1,2);
      return 0;
    }
    props_setError(param_1,0x70);
  }
  return 0;
}


// ============================================================
// Function: score_resolveProplist (FUN_680446f0)
// Address: 680446f0
// Size: 9 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_resolveProplist(int param_1,int *param_2,undefined4 *param_3)
{
  score_copyProplist(param_1,param_2,param_3);
  return 0;
}


// ============================================================
// Function: score_initProplistDispatch (FUN_68044700)
// Address: 68044700
// Size: 420 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_initProplistDispatch(int param_1)
{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  undefined4 local_2c;
  int *local_28;
  int *local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar1 = props_getInt(param_1);
  if (*(int *)(param_1 + 0x18) < iVar1 * 8) {
    props_setError(param_1,0x33);
    return 0;
  }
  uVar2 = props_getInt(param_1);
  local_20 = uVar2;
  if ((uVar2 & 1) == 0) {
    local_24 = (int *)score_deleteProplistEntry(param_1,(int)uVar2 >> 1);
    if (local_24 != (int *)0x0) {
      *(int *)(*local_24 + 0x10) = (int)uVar2 >> 1;
      if (0 < (int)uVar2) {
        local_1c = 0;
        iVar1 = 0;
        do {
          puVar3 = (uint *)(**(int **)(param_1 + 0x10) + -8 +
                            ((iVar1 + 1) - *(int *)(param_1 + 0x20)) * 8 + *(int *)(param_1 + 0x18))
          ;
          local_14 = DAT_6819776c;
          local_18 = DAT_68197768;
          if (puVar3 != (uint *)0x0) {
            DAT_6819776c = 0;
            DAT_68197768 = 0;
            local_14 = puVar3[1];
            local_18 = *puVar3;
          }
          iVar1 = iVar1 + 2;
          _DAT_68197764 =
               (uint *)(**(int **)(param_1 + 0x10) + -8 + (iVar1 - *(int *)(param_1 + 0x20)) * 8 +
                       *(int *)(param_1 + 0x18));
          local_c = DAT_6819776c;
          local_10 = DAT_68197768;
          if (_DAT_68197764 != (uint *)0x0) {
            DAT_6819776c = 0;
            DAT_68197768 = 0;
            local_c = ((int *)(size_t)_DAT_68197764)[1];
            local_10 = *(int *)(size_t)_DAT_68197764;
          }
          if ((local_18 & 1) != 0) {
            props_retainValue(param_1,&local_18);
          }
          if ((local_10 & 1) != 0) {
            props_retainValue(param_1,&local_10);
          }
          puVar3 = (uint *)(*local_24 + 0x28 + local_1c);
          *puVar3 = local_18;
          puVar3[1] = local_14;
          puVar3[2] = local_10;
          local_1c = local_1c + 0x10;
          puVar3[3] = local_c;
        } while (iVar1 < (int)local_20);
      }
      local_2c = 3;
      local_28 = local_24;
      props_popArgs(param_1,&local_2c);
      return 0;
    }
    props_setError(param_1,2);
    return 0;
  }
  props_reportError(param_1,0x45);
  return 0;
}


// ============================================================
// Function: score_dispatchProplist (FUN_680448b0)
// Address: 680448b0
// Size: 85 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_dispatchProplist(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x1c) = 4;
  *(undefined4 *)(param_1 + 0x20) = 0x80000000;
  score_initProplistDispatch(param_1);
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
// Function: score_compareProplist (FUN_68044910)
// Address: 68044910
// Size: 1036 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_compareProplist(int param_1,int *param_2,int param_3)

{
  uint *puVar1;
  int iVar2;
  bool bVar3;
  undefined3 extraout_var;
  int iVar4;
  int *extraout_EDX;
  int *extraout_EDX_00;
  int *piVar5;
  int iVar6;
  uint local_30;
  int *local_2c;
  uint local_28;
  int *local_24;
  int local_20;
  uint local_1c;
  code *local_18;
  uint local_14;
  int *local_10;
  int local_c;
  uint local_8;
  
  iVar2 = param_1;
  iVar6 = 0;
  local_8 = 0;
  local_c = 2;
  local_20 = 0;
  switch(param_3) {
  case 0xc:
    local_8 = 0;
    goto LAB_68044973;
  case 0xd:
    local_c = 1;
    local_8 = 1;
    break;
  case 0xe:
    local_c = 0;
    local_8 = 1;
    break;
  case 0xf:
    local_c = 0;
    local_8 = 0;
    break;
  case 0x10:
    local_c = 1;
    local_8 = 0;
    break;
  case 0x11:
    local_8 = 1;
LAB_68044973:
    local_c = -1;
    break;
  default:
    goto switchD_68044933_default;
  }
  param_3 = 0x24;
switchD_68044933_default:
  local_18 = *(code **)(*(int *)(**(int **)(param_1 + 8) + 0x4e0) + param_3 * 4);
  _DAT_68197764 = (uint *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  if (_DAT_68197764 == (uint *)0x0) {
    local_28 = DAT_68197768;
    local_24 = DAT_6819776c;
  }
  else {
    DAT_6819776c = (int *)0x0;
    DAT_68197768 = 0;
    local_28 = *(int *)(size_t)_DAT_68197764;
    local_24 = (int *)((int *)(size_t)_DAT_68197764)[1];
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -0x10;
  local_30 = *(uint *)(param_1 + 0x1c);
  puVar1 = (uint *)(param_1 + 0x1c);
  local_14 = local_28;
  local_2c = *(int **)(param_1 + 0x20);
  local_10 = local_24;
  iVar4 = **(int **)(param_1 + 0x10);
  *puVar1 = *(uint *)(iVar4 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar4 + 4 + *(int *)(param_1 + 0x18));
  bVar3 = js_isGCActive();
  if (CONCAT31(extraout_var,bVar3) != 0) {
    props_setError(param_1,0x70);
    goto LAB_68044cf2;
  }
  if ((local_30 == 3) && (local_2c == param_2)) {
    iVar4 = score_getProplistValue(param_1,(int *)&local_14);
    piVar5 = extraout_EDX;
    if (iVar4 == 0) {
      param_2 = *(int **)(*extraout_EDX + 0x10);
      local_10 = (int *)0x1;
      local_20 = 1;
      param_1 = 0;
      if (0 < (int)param_2) {
        do {
          props_pushValue(iVar2);
          iVar4 = *local_2c;
          *puVar1 = *(uint *)(iVar6 + 0x28 + iVar4);
          *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar6 + 0x2c + iVar4);
          props_retainValue(iVar2,puVar1);
          props_pushValue(iVar2);
          *puVar1 = local_28;
          *(int **)(iVar2 + 0x20) = local_24;
          props_retainValue(iVar2,puVar1);
          props_pushValue(iVar2);
          iVar4 = *local_2c;
          *puVar1 = *(uint *)(iVar6 + 0x30 + iVar4);
          *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar6 + 0x34 + iVar4);
          props_retainValue(iVar2,puVar1);
          (*local_18)(iVar2,0);
          if (*(int *)(iVar2 + 0x7c) != 0) goto LAB_68044cf2;
          param_1 = param_1 + 1;
          iVar6 = iVar6 + 0x10;
        } while (param_1 < (int)param_2);
      }
    }
    else {
LAB_68044af3:
      param_2 = *(int **)(*local_24 + 0x10);
      piVar5 = *(int **)(*piVar5 + 0x10);
      local_10 = (int *)((int)param_2 - (int)piVar5);
      if ((int)piVar5 < (int)param_2) {
        param_2 = piVar5;
      }
      param_1 = 0;
      if (0 < (int)param_2) {
        iVar6 = 0x30;
        do {
          props_pushValue(iVar2);
          iVar4 = *local_24;
          *puVar1 = *(uint *)(iVar6 + -8 + iVar4);
          *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar6 + -4 + iVar4);
          props_retainValue(iVar2,puVar1);
          props_pushValue(iVar2);
          iVar4 = *local_24;
          *puVar1 = *(uint *)(iVar6 + iVar4);
          *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar6 + 4 + iVar4);
          props_retainValue(iVar2,puVar1);
          props_pushValue(iVar2);
          iVar4 = *local_2c;
          *puVar1 = *(uint *)(iVar6 + iVar4);
          *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar6 + 4 + iVar4);
          props_retainValue(iVar2,puVar1);
          (*local_18)(iVar2,0);
          if (*(int *)(iVar2 + 0x7c) != 0) goto LAB_68044cf2;
          param_1 = param_1 + 1;
          iVar6 = iVar6 + 0x10;
        } while (param_1 < (int)param_2);
      }
    }
  }
  else {
    iVar4 = score_getProplistValue(param_1,(int *)&local_30);
    piVar5 = extraout_EDX_00;
    if (iVar4 != 0) goto LAB_68044af3;
    param_2 = *(int **)(*local_24 + 0x10);
    local_10 = (int *)0x1;
    local_20 = 1;
    param_1 = 0;
    if (0 < (int)param_2) {
      do {
        props_pushValue(iVar2);
        iVar4 = *local_24;
        *puVar1 = *(uint *)(iVar6 + 0x28 + iVar4);
        *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar6 + 0x2c + iVar4);
        props_retainValue(iVar2,puVar1);
        props_pushValue(iVar2);
        iVar4 = *local_24;
        *puVar1 = *(uint *)(iVar6 + 0x30 + iVar4);
        *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar6 + 0x34 + iVar4);
        props_retainValue(iVar2,puVar1);
        props_pushValue(iVar2);
        *puVar1 = local_30;
        *(int **)(iVar2 + 0x20) = local_2c;
        props_retainValue(iVar2,puVar1);
        (*local_18)(iVar2,0);
        if (*(int *)(iVar2 + 0x7c) != 0) goto LAB_68044cf2;
        param_1 = param_1 + 1;
        iVar6 = iVar6 + 0x10;
      } while (param_1 < (int)param_2);
    }
  }
  props_pushValue(iVar2);
  *puVar1 = 4;
  *(uint *)(iVar2 + 0x20) = (int)param_2 * 2 | 0x80000000;
  score_initProplistDispatch(iVar2);
  iVar6 = local_c;
  if ((*(int *)(iVar2 + 0x7c) != 0) || ((param_3 != 0x24 && (param_3 != 0x25)))) goto LAB_68044cf2;
  local_1c = *puVar1;
  local_18 = *(code **)(iVar2 + 0x20);
  *puVar1 = 4;
  if (local_c == 0) {
    if (local_10 == (int *)0x0) {
LAB_68044cc8:
      iVar4 = score_findProplistInt();
      *(int *)(iVar2 + 0x20) = iVar4;
      if (iVar6 != 2) {
        *(uint *)(iVar2 + 0x20) = iVar4 == iVar6 ^ local_8;
      }
    }
    else {
      *(uint *)(iVar2 + 0x20) = local_8;
    }
  }
  else {
    if ((local_10 == (int *)0x0) || (local_20 != 0)) goto LAB_68044cc8;
    iVar6 = (uint)(-1 < (int)local_10) * 2 + -1;
    *(int *)(iVar2 + 0x20) = iVar6;
    if (local_c != 2) {
      *(uint *)(iVar2 + 0x20) = iVar6 == local_c ^ local_8;
    }
  }
  props_releaseValue(iVar2,(byte)local_1c,(int *)local_18);
LAB_68044cf2:
  props_releaseValue(iVar2,(byte)local_28,local_24);
  props_releaseValue(iVar2,(byte)local_30,local_2c);
  return 1;
}


// ============================================================
// Function: score_modifyProplist (FUN_68044d40)
// Address: 68044d40
// Size: 266 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_modifyProplist(void)
{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  uint local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  local_c = (int *)sprites_getNetMimeType(unaff_ESI);
  iVar2 = props_getInt(unaff_ESI);
  iVar3 = props_getTypedValue(unaff_ESI,2,4,&local_8);
  if (iVar3 != 0) {
    *(uint *)(*in_EAX + 0x18) = local_8;
    iVar3 = props_getTypedValue(unaff_ESI,3,8,&local_8);
    if (iVar3 != 0) {
      *(uint *)(*in_EAX + 0x28) = local_8;
      if (3 < iVar2) {
        _DAT_68197764 =
             (uint *)(**(int **)(unaff_ESI + 0x10) + (3 - *(int *)(unaff_ESI + 0x20)) * 8 +
                     *(int *)(unaff_ESI + 0x18));
        local_10 = DAT_6819776c;
        local_14 = DAT_68197768;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          local_10 = ((int *)(size_t)_DAT_68197764)[1];
          local_14 = *(int *)(size_t)_DAT_68197764;
        }
        props_releaseValue(unaff_ESI,(byte)*(undefined4 *)(*in_EAX + 0x20),*(int **)(*in_EAX + 0x24));
        props_retainValue(unaff_ESI,&local_14);
        iVar2 = *in_EAX;
        *(uint *)(iVar2 + 0x20) = local_14;
        *(uint *)(iVar2 + 0x24) = local_10;
      }
      iVar2 = *in_EAX;
      if (*(int *)(iVar2 + 0x18) != 0) {
        iVar3 = sprites_getMovieRef(unaff_ESI);
        *(int *)(iVar2 + 0x1c) = iVar3 + *(int *)(iVar2 + 0x18);
      }
      piVar1 = local_c;
      local_14 = 3;
      local_8 = props_getListRange(unaff_ESI,local_c,(int *)&local_14);
      if ((int)local_8 < 0) {
        props_setListEntry(unaff_ESI,piVar1,&local_14);
      }
    }
  }
  return 0;
}


// ============================================================
// Function: score_removeProplistEntry (FUN_68044e50)
// Address: 68044e50
// Size: 58 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_removeProplistEntry(undefined4 param_1)
{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  int local_c;
  undefined4 local_8;
  
  piVar1 = (int *)sprites_getNetMimeType(unaff_ESI);
  local_c = 3;
  local_8 = param_1;
  iVar2 = props_getListRange(unaff_ESI,piVar1,&local_c);
  if (-1 < iVar2) {
    props_setListRange(unaff_ESI,piVar1,iVar2);
  }
  return 0;
}


// ============================================================
// Function: score_handleProplistCommand (FUN_68044e90)
// Address: 68044e90
// Size: 141 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_handleProplistCommand(uint param_1,int *param_2,int param_3)

{
  undefined4 local_c;
  int *local_8;
  
  if (param_3 == 0x82) {
    score_modifyProplist();
    local_8 = param_2;
    local_c = 3;
    *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
    props_popArgs(param_1,&local_c);
    return 1;
  }
  if (param_3 != 0xe3) {
    if (param_3 != 0x10c) {
      return 0;
    }
    score_removeProplistEntry(param_2);
    props_popArgs(param_1,(undefined4 *)0x0);
    return 1;
  }
  score_resolveType(param_1);
  return 1;
}


// ============================================================
// Function: score_destroyProplistNode (FUN_68044f20)
// Address: 68044f20
// Size: 87 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_destroyProplistNode(int param_1,int *param_2)
{
  props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x10),*(int **)(*param_2 + 0x14));
  props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x20),*(int **)(*param_2 + 0x24));
  *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
  *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + -1;
  return 0;
}


// ============================================================
// Function: score_formatProplist (FUN_68044f80)
// Address: 68044f80
// Size: 130 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatProplist(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  int local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_410 = *(int *)(*param_2 + 0x10);
  local_40c = *(undefined4 *)(*param_2 + 0x14);
  props_toPascalString(&local_410,local_408);
  cast_loadPascalString(&DAT_68197780,0x898,0x42);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}


