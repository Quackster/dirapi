// Module: core
// Topic: Field/point object operations - creation, access, conversion, formatting
// Address range: 0x68017160 - 0x68017D60
// Functions (14):
//   core_collectFieldEntries (0x68017160)
//   core_checkFieldValid (0x68017320)
//   core_formatFieldString (0x68017350)
//   core_getFieldPoint (0x68017390)
//   core_resolveFieldProperty (0x680173C0)
//   core_getFieldTypeChar (0x68017650)
//   core_getFieldValue (0x68017670)
//   core_createEmptyField (0x680176C0)
//   core_setFieldValue (0x68017710)
//   core_accessFieldMember (0x68017770)
//   core_handleGetField (0x68017890)
//   core_handleFieldOfMember (0x68017900)
//   core_dispatchFieldAction (0x68017AB0)
//   core_accessFieldProperty (0x68017D60)

// ============================================================
// Function: core_collectFieldEntries (FUN_68017160)
// Address: 68017160
// Size: 433 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_collectFieldEntries(undefined4 param_1,undefined4 param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int **ppiVar5;
  int unaff_ESI;
  undefined4 local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  int local_54;
  int **local_50;
  int local_4c;
  int *local_48;
  int local_44 [15];
  uint local_8;
  
  puVar1 = param_3;
  local_54 = props_getInt(unaff_ESI);
  if (local_54 < 9) {
    local_50 = &local_48;
    iVar4 = 1;
    local_4c = 0;
    if (0 < local_54) {
      do {
        _DAT_68197764 =
             (undefined4 *)
             (**(int **)(unaff_ESI + 0x10) + -8 + (iVar4 - *(int *)(unaff_ESI + 0x20)) * 8 +
             *(int *)(unaff_ESI + 0x18));
        piVar2 = DAT_6819776c;
        ppiVar5 = DAT_68197768;
        if (_DAT_68197764 != (undefined4 *)0x0) {
          DAT_6819776c = (int *)0x0;
          DAT_68197768 = (int **)0x0;
          piVar2 = (int *)((int *)(size_t)_DAT_68197764)[1];
          ppiVar5 = (int **)*(int *)(size_t)_DAT_68197764;
        }
        (&local_50)[iVar4 * 2] = ppiVar5;
        (&local_4c)[iVar4 * 2] = (int)piVar2;
        iVar4 = iVar4 + 1;
      } while (iVar4 <= local_54);
      goto LAB_68017263;
    }
  }
  else {
    local_4c = cast_allocHandle(local_54 * 8,0);
    if (local_4c == 0) goto LAB_680172fd;
    local_50 = (int **)Ordinal_1114(local_4c);
    iVar4 = 1;
    if (0 < local_54) {
      do {
        _DAT_68197764 =
             (undefined4 *)
             (**(int **)(unaff_ESI + 0x10) + -8 + (iVar4 - *(int *)(unaff_ESI + 0x20)) * 8 +
             *(int *)(unaff_ESI + 0x18));
        piVar2 = DAT_6819776c;
        ppiVar5 = DAT_68197768;
        if (_DAT_68197764 != (undefined4 *)0x0) {
          DAT_6819776c = (int *)0x0;
          DAT_68197768 = (int **)0x0;
          piVar2 = (int *)((int *)(size_t)_DAT_68197764)[1];
          ppiVar5 = (int **)*(int *)(size_t)_DAT_68197764;
        }
        local_50[iVar4 * 2 + -2] = (int *)ppiVar5;
        local_50[iVar4 * 2 + -1] = piVar2;
        iVar4 = iVar4 + 1;
      } while (iVar4 <= local_54);
    }
LAB_68017263:
    if (local_50 == (int **)0x0) goto LAB_680172fd;
  }
  local_68 = 0;
  local_64 = 0;
  local_60 = param_2;
  local_5c = 2;
  local_58 = 0;
  iVar4 = sprites_dispatchMemberFlags(unaff_ESI,&param_1,&local_68);
  if (local_4c != 0) {
    cast_freeHandle(local_4c);
  }
  if (iVar4 == 0) {
    *puVar1 = local_5c;
    puVar1[1] = local_58;
    return 0;
  }
  if ((iVar4 != -0x7ffbf821) && (iVar4 != 0x10)) {
    uVar3 = props_translateError(iVar4);
    props_reportError(unaff_ESI,(int)(short)uVar3);
    return 0;
  }
LAB_680172fd:
  return 0;
}



// ============================================================
// Function: core_checkFieldValid (FUN_68017320)
// Address: 68017320
// Size: 36 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool core_checkFieldValid(undefined4 param_1,int *param_2,int param_3)

{
  if (param_3 < 0) {
    return 0 < *(short *)(*param_2 + 10);
  }
  return true;
}



// ============================================================
// Function: core_formatFieldString (FUN_68017350)
// Address: 68017350
// Size: 64 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_formatFieldString(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x28);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: core_getFieldPoint (FUN_68017390)
// Address: 68017390
// Size: 35 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getFieldPoint(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  *param_3 = CONCAT22(*(undefined2 *)(*param_2 + 8),*(undefined2 *)(*param_2 + 10));
  return 1;
}



// ============================================================
// Function: core_resolveFieldProperty (FUN_680173c0)
// Address: 680173c0
// Size: 651 bytes
// Params: void * param_1, int * param_2, int param_3, uint param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_resolveFieldProperty(void *param_1,int *param_2,int param_3,uint param_4,uint *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint *puVar5;
  undefined4 local_8;
  
  local_8 = *(undefined4 *)(*param_2 + 8);
  iVar1 = crt_getPlatformValue((int)param_1,(short *)&local_8);
  if (iVar1 == 0) {
    if ((int)param_4 < 0x104) {
      if (param_4 == 0x103) {
        if (param_3 != 0) {
          return 1;
        }
        props_loadCString((int)param_1,"",param_5);
        return 1;
      }
      if (param_4 != 0xaa) {
        if (param_4 != 0xdd) goto LAB_6801747a;
        if (param_3 == 0) {
          *param_5 = 4;
          uVar2 = sprites_getMemberByChannel((int)param_1,(short)local_8);
          param_5[1] = uVar2;
          return 1;
        }
        goto LAB_68017614;
      }
      goto LAB_68017548;
    }
    if (param_4 != 0x139) {
      if (((int)param_4 < 0x2d8) || (0x2d9 < (int)param_4)) {
LAB_6801747a:
        iVar1 = *(int *)(*(int *)((int)param_1 + 8) + 4);
        if (param_3 != 0) {
          if ((iVar1 != 0) && (*(int *)(iVar1 + 500) == 0x800)) {
            return 1;
          }
          props_setError((int)param_1,0x23);
          return 1;
        }
        if ((iVar1 != 0) && (0x9ff < *(uint *)(iVar1 + 500))) {
          if ((int)param_4 < 0x1e1) {
            if (param_4 == 0x1e0) {
              return 0;
            }
            if (param_4 == 0xe4) {
              return 0;
            }
            if (param_4 == 0x1d9) {
              return 0;
            }
            if (param_4 == 0x1dc) {
              return 0;
            }
          }
          else if (0x1ef < (int)param_4) {
            if ((int)param_4 < 0x1f5) {
              return 0;
            }
            if (param_4 == 0x208) {
              return 0;
            }
          }
        }
        *param_5 = 2;
        param_5[1] = 0;
        return 1;
      }
      goto LAB_68017548;
    }
  }
  else {
LAB_68017548:
    if (param_4 == 0x2d8) {
      if (param_3 == 0) {
        param_5[1] = (int)(*(unsigned short *)((char *)&local_8 + 2));
        *param_5 = 4;
        return 1;
      }
      goto LAB_68017614;
    }
    if (param_4 == 0x2d9) {
      if (param_3 == 0) {
        param_5[1] = (int)(short)local_8;
        *param_5 = 4;
        return 1;
      }
      goto LAB_68017614;
    }
    iVar1 = param_3;
    uVar2 = param_4;
    puVar5 = param_5;
    iVar3 = sprites_getMemberInfo((int)param_1,&local_8);
    iVar1 = sprites_dispatchPropertyEx(param_1,iVar3,iVar1,uVar2,puVar5);
    if (iVar1 == 0) {
      return 1;
    }
    if ((param_4 != 0x139) && (param_4 != 0x1ff)) {
      if (iVar1 != -0x7ffbf82a) {
        if (iVar1 == -0x7ffbf82b) {
          return 0;
        }
        uVar4 = props_translateError(iVar1);
        if ((short)uVar4 == 0x61) {
          props_reportError((int)param_1,0x61);
          return 1;
        }
        props_reportError((int)param_1,(int)(short)uVar4);
        return 1;
      }
      goto LAB_68017614;
    }
  }
  if (param_3 == 0) {
    *param_5 = 8;
    param_5[1] = 0x2c;
    return 1;
  }
LAB_68017614:
  props_reportError((int)param_1,0x39);
  return 1;
}



// ============================================================
// Function: core_getFieldTypeChar (FUN_68017650)
// Address: 68017650
// Size: 29 bytes
// Params: undefined4 param_1, int * param_2
// Return: char
// Calling convention: __stdcall
// ============================================================

char core_getFieldTypeChar(undefined4 param_1,int *param_2)

{
  return ((*(short *)(*param_2 + 8) != -1) - 1U & 0x34) + 0x58;
}



// ============================================================
// Function: core_getFieldValue (FUN_68017670)
// Address: 68017670
// Size: 65 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getFieldValue(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)Ordinal_1111(0xc,8);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar2;
    puVar1[1] = 1;
    *puVar1 = &PTR_FUN_6818b808;
    puVar1[2] = *param_2;
    *param_3 = 3;
    param_3[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: core_createEmptyField (FUN_680176c0)
// Address: 680176c0
// Size: 70 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_createEmptyField(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)Ordinal_1111(0xc,8);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar2;
    puVar1[1] = 1;
    *(undefined2 *)(puVar1 + 2) = 0;
    *puVar1 = &PTR_FUN_6818b808;
    *(undefined2 *)((int)puVar1 + 10) = 0xffff;
    *param_2 = 3;
    param_2[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: core_setFieldValue (FUN_68017710)
// Address: 68017710
// Size: 83 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_setFieldValue(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_c [2];
  
  while ((*param_2 != 3 || ((undefined **)**(int **)param_2[1] != &PTR_FUN_6818b808))) {
    iVar1 = core_unwrapMember(param_1,param_2,local_c);
    if (iVar1 == 0) {
      return 0;
    }
    param_2 = local_c;
  }
  *param_3 = (*(int **)param_2[1])[2];
  return 1;
}



// ============================================================
// Function: core_accessFieldMember (FUN_68017770)
// Address: 68017770
// Size: 288 bytes
// Params: uint param_1, short * param_2, undefined * param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_accessFieldMember(uint param_1,short *param_2,undefined *param_3,int param_4)

{
  short sVar1;
  int iVar2;
  undefined4 uVar3;
  int local_c;
  int local_8;
  
  iVar2 = props_getInt(param_1);
  if (iVar2 == 1) {
    *param_2 = 0;
  }
  else {
    if (iVar2 != 2) {
      props_setError(param_1,0x19);
      return 0;
    }
    iVar2 = **(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8;
    _DAT_68197764 = (int *)(iVar2 + 8 + *(int *)(param_1 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    sVar1 = cast_bridgeXtraCall(&local_c,iVar2,param_1,&local_c);
    *param_2 = sVar1;
    if (*(int *)(param_1 + 0x7c) != 0) {
      return 0;
    }
  }
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18)
              );
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  if (param_4 != 0) {
    uVar3 = crt_executePlatformSet(param_1,&local_c,param_3,param_2,param_4);
    return uVar3;
  }
  crt_executePlatformQuery(param_1,&local_c,sprites_resetMember,param_2);
  sprites_checkBounds(param_1,param_2);
  return 1;
}



// ============================================================
// Function: core_handleGetField (FUN_68017890)
// Address: 68017890
// Size: 112 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_handleGetField(uint param_1)
{
  uint uVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = param_1;
  core_accessFieldMember(param_1,(short *)&param_1,sprites_resetMember,0);
  if ((0x7fff < (*(unsigned short *)((char *)&param_1 + 2))) && (*(int *)(uVar1 + 0xe0) != 0)) {
    local_c = 2;
    local_8 = 0;
    props_popArgs(uVar1,&local_c);
    return 0;
  }
  local_c = 2;
  core_getFieldValue(uVar1,&param_1,&local_c);
  props_popArgs(uVar1,&local_c);
  return 0;
}



// ============================================================
// Function: core_handleFieldOfMember (FUN_68017900)
// Address: 68017900
// Size: 424 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_handleFieldOfMember(uint param_1)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_10;
  int *local_c;
  int local_8;
  
  uVar2 = param_1;
  iVar3 = props_getInt(param_1);
  if (iVar3 < 1) {
    props_setError(uVar2,0x19);
    return 0;
  }
  _DAT_68197764 =
       (int *)(**(int **)(uVar2 + 0x10) + *(int *)(uVar2 + 0x20) * -8 + *(int *)(uVar2 + 0x18));
  local_c = DAT_6819776c;
  local_10 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = (int *)0x0;
    DAT_68197768 = 0;
    local_c = (int *)((int *)(size_t)_DAT_68197764)[1];
    local_10 = *(int *)(size_t)_DAT_68197764;
  }
  iVar4 = props_requireSymbolId(uVar2,&local_10,&local_8);
  if (iVar4 != 0) {
    if (iVar3 < 2) {
      param_1 = 0x10000;
      sprites_checkBounds(uVar2,(short *)&param_1);
      uVar5 = sprites_getMemberCastIndex(uVar2,&param_1);
      param_1 = CONCAT22((short)uVar5,(undefined2)param_1);
      goto LAB_68017a3e;
    }
    _DAT_68197764 =
         (int *)(**(int **)(uVar2 + 0x10) + *(int *)(uVar2 + 0x20) * -8 + 8 + *(int *)(uVar2 + 0x18)
                );
    local_c = DAT_6819776c;
    local_10 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_c = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_10 = *(int *)(size_t)_DAT_68197764;
    }
    if (local_10 == 3) {
      piVar1 = (int *)*local_c;
      if ((undefined **)*piVar1 == &PTR_LAB_6818b7b8) {
        param_1 = CONCAT22(1,(short)piVar1[2]);
        sprites_checkBounds(uVar2,(short *)&param_1);
        uVar5 = sprites_getMemberCastIndex(uVar2,&param_1);
        param_1 = CONCAT22((short)uVar5,(undefined2)param_1);
LAB_68017a3e:
        iVar3 = sprites_getMemberInfo(uVar2,&param_1);
        iVar3 = sprites_importMemberFromFile(uVar2,iVar3,local_8);
        if (iVar3 == 0) {
          core_getFieldValue(uVar2,&param_1,&local_10);
          props_popArgs(uVar2,&local_10);
          return 0;
        }
        local_10 = 4;
        local_c = (int *)(size_t)iVar3;
        props_popArgs(uVar2,&local_10);
        return 0;
      }
      if ((undefined **)*piVar1 == &PTR_FUN_6818b808) {
        param_1 = piVar1[2];
        goto LAB_68017a3e;
      }
    }
    props_setErrorAndReturn(uVar2,0x13);
  }
  return 0;
}



// ============================================================
// Function: core_dispatchFieldAction (FUN_68017ab0)
// Address: 68017ab0
// Size: 684 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_dispatchFieldAction(uint param_1,int *param_2,int param_3)
{
  ushort uVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int local_41c;
  undefined4 local_418;
  uint local_414;
  int local_410;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  uVar1 = *(ushort *)(*param_2 + 8);
  local_414 = (uint)uVar1;
  puVar5 = (undefined1 *)0x0;
  local_410 = 4;
  local_40c = 0;
  if (param_3 < 0x1f5) {
    if (param_3 == 500) {
      local_418 = CONCAT22(1,uVar1);
      iVar3 = props_getInt(param_1);
      if (1 < iVar3) {
        _DAT_68197764 =
             (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                    *(int *)(param_1 + 0x18));
        local_40c = DAT_6819776c;
        local_410 = DAT_68197768;
        if (_DAT_68197764 != (int *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          local_40c = ((int *)(size_t)_DAT_68197764)[1];
          local_410 = *(int *)(size_t)_DAT_68197764;
        }
        iVar3 = props_coerceToInt(param_1,&local_410,(int *)&local_414);
        if (iVar3 != 0) {
          local_418 = CONCAT22((undefined2)local_414,(undefined2)local_418);
        }
      }
      local_410 = 4;
      uVar4 = sprites_getMemberCastIndex(param_1,&local_418);
      local_40c = (int)(short)uVar4;
    }
    else {
      if (param_3 != 0xd3) {
        if (param_3 == 0xe3) {
          score_resolveType(param_1);
          goto LAB_68017d44;
        }
LAB_68017c71:
        return 0;
      }
      iVar3 = props_getInt(param_1);
      if ((iVar3 != 2) || (0 < (short)uVar1)) goto LAB_68017c71;
      _DAT_68197764 =
           (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                  *(int *)(param_1 + 0x18));
      local_40c = DAT_6819776c;
      local_410 = DAT_68197768;
      if (_DAT_68197764 != (int *)0x0) {
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        local_40c = ((int *)(size_t)_DAT_68197764)[1];
        local_410 = *(int *)(size_t)_DAT_68197764;
      }
      sVar2 = cast_bridgeXtraCall(local_410,&local_410,param_1,&local_410);
      local_410 = 2;
      local_40c = 0;
      if (0 < sVar2) {
        core_createMemberRef(param_1,sVar2,&local_410);
      }
    }
  }
  else {
    if (param_3 != 0x268) goto LAB_68017c71;
    iVar3 = sprites_getStageRef(param_1);
    if (iVar3 != 0) {
      props_reportError(param_1,0x66);
      goto LAB_68017d44;
    }
    iVar3 = props_getInt(param_1);
    if (1 < iVar3) {
      _DAT_68197764 =
           (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
                  *(int *)(param_1 + 0x18));
      local_418 = DAT_6819776c;
      local_41c = DAT_68197768;
      if (_DAT_68197764 != (int *)0x0) {
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        local_418 = ((int *)(size_t)_DAT_68197764)[1];
        local_41c = *(int *)(size_t)_DAT_68197764;
      }
      iVar3 = props_validateString(param_1,&local_41c);
      if (iVar3 == 0) goto LAB_68017d44;
      props_toPascalString(&local_41c,local_408);
      puVar5 = local_408;
    }
    local_40c = sprites_setMemberScript(param_1,(short)local_414,(int)puVar5);
  }
  props_popArgs(param_1,&local_410);
LAB_68017d44:
  return 0;
}



// ============================================================
// Function: core_accessFieldProperty (FUN_68017d60)
// Address: 68017d60
// Size: 494 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessFieldProperty(int param_1,int *param_2,int param_3,int param_4,uint *param_5)
{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  int local_410;
  ushort local_40c [2];
  byte local_408 [1024];
  uint local_8;
  
  uVar1 = *(ushort *)(*param_2 + 8);
  if (param_4 < 0xfd) {
    if (param_4 != 0xfc) {
      if (param_4 == 0x58) {
        if (param_3 == 0) {
          local_40c[1] = 0xffff;
          local_40c[0] = uVar1;
          core_getFieldValue(param_1,(undefined4 *)local_40c,param_5);
          goto LAB_68017f36;
        }
      }
      else if (param_4 == 0xaa) {
        if (param_3 == 0) {
          *param_5 = 4;
          param_5[1] = (int)(short)uVar1;
          goto LAB_68017f36;
        }
      }
      else {
        if (param_4 != 0xdd) goto LAB_68017e85;
        if (param_3 == 0) {
          *param_5 = 4;
          uVar2 = sprites_getMemberCount(param_1);
          param_5[1] = (int)(short)uVar2;
          goto LAB_68017f36;
        }
      }
      props_reportError(param_1,0x39);
      goto LAB_68017f36;
    }
    if (param_3 != 0) {
      iVar3 = props_validateString(param_1,(int *)param_5);
      if (iVar3 != 0) {
        props_toPascalString((int *)param_5,local_408);
        sprites_setMemberComment(param_1,uVar1,local_408);
      }
      goto LAB_68017f36;
    }
    sprites_getMemberComment(param_1,uVar1,local_408);
    sprites_getCastRef(param_1,local_408);
  }
  else {
    if (param_4 != 0x103) {
      if (param_4 == 0x1b1) {
        if (param_3 == 0) {
          sprites_getNetworkErrorString(param_1,(uint)uVar1,param_5);
        }
        else {
          sprites_setAlertHook(param_1,(uint)uVar1,param_5);
        }
      }
      else {
        if (param_4 != 0x267) {
LAB_68017e85:
          return 0;
        }
        if (param_3 == 0) {
          *param_5 = 4;
          uVar2 = sprites_getMemberFlag(param_1,uVar1);
          param_5[1] = uVar2;
        }
        else {
          iVar3 = props_requireInt(param_1,(int *)param_5,&local_410);
          if (iVar3 != 0) {
            sprites_setMemberFlag(param_1,uVar1,param_5[1]);
          }
        }
      }
      goto LAB_68017f36;
    }
    if (param_3 != 0) {
      iVar3 = props_validateString(param_1,(int *)param_5);
      if (iVar3 != 0) {
        props_toPascalString((int *)param_5,local_408);
        sprites_setMemberName(param_1,uVar1,local_408);
      }
      goto LAB_68017f36;
    }
    sprites_getMemberName(param_1,uVar1,local_408);
  }
  props_readPascalString(param_1,local_408,param_5);
LAB_68017f36:
  return 0;
}


