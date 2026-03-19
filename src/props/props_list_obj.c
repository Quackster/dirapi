// Module: props
// Topic: List object vtable, sort, and dispatch
// Address range: 0x6803b7a0 - 0x6803c360
// Functions (29):
//   props_sortList
//   props_findListExtreme
//   props_getListMin
//   props_getListMax
//   props_checkListType
//   props_getListSortedCount
//   props_createList
//   props_destroyList
//   props_listToString
//   props_printList
//   props_isListType
//   props_getListProp
//   props_listNoOp
//   props_findListHandle
//   props_createListAndNotify
//   props_createListScript
//   props_getListPropScript
//   props_getListEntryAsInt
//   props_getListEntry
//   props_getListEntryRaw
//   props_getListLength
//   props_sortListEntries
//   props_allocList
//   props_setListVtable
//   props_setListSortVtable
//   props_getListRange
//   props_setListEntry
//   props_setListRange
//   props_getListCount



// ============================================================
// Function: props_sortList (FUN_6803b7a0)
// Address: 6803b7a0
// Size: 638 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_sortList(undefined4 param_1,int *param_2,int param_3,int param_4)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int *piVar7;
  bool bVar8;
  undefined3 extraout_var;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *local_10;
  int local_c;
  code *local_8;
  
  piVar7 = param_2;
  local_8 = *(code **)(*param_2 + 0x24);
  if (param_3 < param_4) {
    while ((6 < param_4 - param_3 && (bVar8 = js_isGCActive(), CONCAT31(extraout_var,bVar8) == 0))) {
      iVar12 = *piVar7;
      iVar9 = (param_3 + param_4) / 2;
      uVar3 = *(undefined4 *)(iVar12 + 0x28 + iVar9 * 8);
      puVar2 = (undefined4 *)(iVar12 + 0x28 + iVar9 * 8);
      uVar4 = puVar2[1];
      local_c = param_4 + 5;
      iVar9 = local_c * 8;
      *puVar2 = *(undefined4 *)(iVar9 + iVar12);
      puVar2[1] = *(undefined4 *)(iVar9 + 4 + iVar12);
      iVar12 = *piVar7;
      *(undefined4 *)(iVar12 + iVar9) = uVar3;
      *(undefined4 *)(iVar12 + 4 + iVar9) = uVar4;
      iVar12 = param_3;
      param_2 = (int *)param_4;
      if (param_3 < param_4) {
        do {
          iVar10 = (*local_8)(param_1,*(undefined4 *)(*piVar7 + 0x28 + iVar12 * 8),
                              *(undefined4 *)(*piVar7 + 0x2c + iVar12 * 8),uVar3,uVar4);
          if (iVar10 < 1) {
            iVar10 = iVar12 * 8 + 0x28;
            do {
              if ((int)param_2 <= iVar12) break;
              iVar11 = iVar10 + 0xc;
              iVar1 = iVar10 + 8;
              iVar10 = iVar10 + 8;
              iVar12 = iVar12 + 1;
              iVar11 = (*local_8)(param_1,*(undefined4 *)(iVar1 + *piVar7),
                                  *(undefined4 *)(iVar11 + *piVar7),uVar3,uVar4);
            } while (iVar11 < 1);
          }
          local_c = local_c * 8;
          for (iVar10 = (*local_8)(param_1,uVar3,uVar4,*(undefined4 *)(*piVar7 + local_c),
                                   *(undefined4 *)(*piVar7 + 4 + local_c)); iVar10 < 1;
              iVar10 = (*local_8)(param_1,uVar3,uVar4,*(undefined4 *)(iVar11 + *piVar7),
                                  *(undefined4 *)(iVar10 + *piVar7))) {
            if ((int)param_2 <= iVar12) goto LAB_6803b938;
            iVar10 = local_c + -4;
            iVar11 = local_c + -8;
            param_2 = (int *)((int)param_2 + -1);
            local_c = local_c + -8;
          }
          if ((int)param_2 <= iVar12) break;
          iVar10 = *piVar7;
          uVar5 = *(undefined4 *)(iVar10 + 0x28 + iVar12 * 8);
          uVar6 = *(undefined4 *)(iVar10 + 0x2c + iVar12 * 8);
          local_c = (int)param_2 + 5;
          *(undefined4 *)(iVar10 + 0x28 + iVar12 * 8) = *(undefined4 *)(iVar10 + local_c * 8);
          *(undefined4 *)(iVar10 + 0x2c + iVar12 * 8) = *(undefined4 *)(iVar10 + 4 + local_c * 8);
          iVar10 = *piVar7;
          *(undefined4 *)(iVar10 + local_c * 8) = uVar5;
          *(undefined4 *)(iVar10 + 4 + local_c * 8) = uVar6;
        } while( true );
      }
LAB_6803b938:
      iVar10 = *piVar7;
      *(undefined4 *)(iVar9 + iVar10) = *(undefined4 *)(iVar10 + 0x28 + (int)param_2 * 8);
      *(undefined4 *)(iVar9 + 4 + iVar10) = *(undefined4 *)(iVar10 + 0x2c + (int)param_2 * 8);
      iVar9 = *piVar7;
      *(undefined4 *)(iVar9 + 0x28 + (int)param_2 * 8) = uVar3;
      *(undefined4 *)(iVar9 + 0x2c + (int)param_2 * 8) = uVar4;
      props_sortList(param_1,piVar7,param_3,iVar12 + -1);
      local_8 = *(code **)(*piVar7 + 0x24);
      param_3 = (int)param_2 + 1;
      if (param_4 <= param_3) {
        return 0;
      }
    }
    if (param_3 < param_4) {
      param_2 = (int *)(param_4 - param_3);
      do {
        bVar8 = false;
        if (param_4 <= param_3) {
          return 0;
        }
        iVar12 = param_3 * 8 + 0x30;
        local_10 = param_2;
        do {
          iVar9 = *piVar7;
          iVar9 = (*local_8)(param_1,*(undefined4 *)(iVar12 + -8 + iVar9),
                             *(undefined4 *)(iVar12 + -4 + iVar9),*(undefined4 *)(iVar12 + iVar9),
                             *(undefined4 *)(iVar12 + 4 + iVar9));
          if (0 < iVar9) {
            iVar9 = *piVar7;
            uVar3 = *(undefined4 *)(iVar12 + -8 + iVar9);
            uVar4 = *(undefined4 *)(iVar12 + -4 + iVar9);
            *(undefined4 *)(iVar12 + -8 + iVar9) = *(undefined4 *)(iVar12 + iVar9);
            *(undefined4 *)(iVar12 + -4 + iVar9) = *(undefined4 *)(iVar12 + 4 + iVar9);
            iVar9 = *piVar7;
            *(undefined4 *)(iVar12 + iVar9) = uVar3;
            *(undefined4 *)(iVar12 + 4 + iVar9) = uVar4;
            bVar8 = true;
          }
          iVar12 = iVar12 + 8;
          local_10 = (int *)((int)local_10 + -1);
        } while (local_10 != (int *)0x0);
        if (!bVar8) {
          return 0;
        }
        param_2 = (int *)((int)param_2 + -1);
        param_4 = param_4 + -1;
      } while (param_3 < param_4);
    }
  }
  return 0;
}



// ============================================================
// Function: props_findListExtreme (FUN_6803ba30)
// Address: 6803ba30
// Size: 158 bytes
// Params: undefined4 param_1, int * param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_findListExtreme(undefined4 param_1,int *param_2,int param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_c;
  int local_8;
  
  iVar4 = *param_2;
  pcVar1 = *(code **)(iVar4 + 0x24);
  local_c = *(int *)(iVar4 + 0x10);
  if (0 < local_c) {
    if (*(int *)(iVar4 + 0x20) == 1) {
      if (param_3 == -1) {
        uVar5 = *(undefined4 *)(iVar4 + 0x28);
        uVar6 = *(undefined4 *)(iVar4 + 0x2c);
      }
      else {
        uVar5 = *(undefined4 *)(iVar4 + 0x20 + local_c * 8);
        uVar6 = *(undefined4 *)(iVar4 + 0x24 + local_c * 8);
      }
    }
    else {
      uVar5 = *(undefined4 *)(iVar4 + 0x28);
      uVar6 = *(undefined4 *)(iVar4 + 0x2c);
      if (1 < local_c) {
        local_c = local_c + -1;
        local_8 = 0x30;
        do {
          uVar2 = *(undefined4 *)(*param_2 + 4 + local_8);
          uVar3 = *(undefined4 *)(*param_2 + local_8);
          iVar4 = (*pcVar1)(param_1,uVar5,uVar6,uVar3,uVar2);
          if (iVar4 != param_3) {
            uVar5 = uVar3;
            uVar6 = uVar2;
          }
          local_8 = local_8 + 8;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
    }
    param_4[1] = uVar6;
    *param_4 = uVar5;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_getListMin (FUN_6803bad0)
// Address: 6803bad0
// Size: 26 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getListMin(undefined4 param_1,int *param_2,undefined4 *param_3)
{
  props_findListExtreme(param_1,param_2,-1,param_3);
  return 0;
}



// ============================================================
// Function: props_getListMax (FUN_6803baf0)
// Address: 6803baf0
// Size: 26 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getListMax(undefined4 param_1,int *param_2,undefined4 *param_3)
{
  props_findListExtreme(param_1,param_2,1,param_3);
  return 0;
}



// ============================================================
// Function: props_checkListType (FUN_6803bb10)
// Address: 6803bb10
// Size: 102 bytes
// Params: uint param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_checkListType(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1;
  iVar2 = props_getInt(param_1);
  if (iVar2 == 1) {
    *param_3 = 8;
    param_3[1] = 0xba;
    return 1;
  }
  iVar2 = props_getTypedValue(uVar1,2,8,&param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if ((param_1 == 0xba) || (param_1 == 0xc9)) {
    param_3[1] = 1;
  }
  return 1;
}



// ============================================================
// Function: props_getListSortedCount (FUN_6803bb80)
// Address: 6803bb80
// Size: 55 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getListSortedCount(int param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if (-1 < *(int *)(param_1 + 0xd4)) {
    iVar1 = props_getInt(param_1);
    if (iVar1 != 1) {
      return 0;
    }
  }
  *(undefined4 *)(param_3 + 4) = *(undefined4 *)(*param_2 + 0x10);
  return 1;
}



// ============================================================
// Function: props_createList (FUN_6803bbc0)
// Address: 6803bbc0
// Size: 113 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_createList(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint local_c [2];
  
  if (0x19 < param_3 - 0xcbU) {
    return 0;
  }
  local_c[0] = 4;
  local_c[1] = 0;
  iVar1 = (**(code **)(&DAT_6818cf8c + param_3 * 4))(param_1,param_2,local_c);
  if (iVar1 == 0) {
    return 0;
  }
  if ((local_c[0] & 1) != 0) {
    props_retainValue(param_1,local_c);
  }
  props_popArgs(param_1,local_c);
  return 1;
}



// ============================================================
// Function: props_destroyList (FUN_6803bc40)
// Address: 6803bc40
// Size: 102 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_destroyList(int param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_2;
  param_2 = *(int **)(*param_2 + 0x10);
  if (0 < (int)param_2) {
    iVar2 = 0x28;
    do {
      props_releaseValue(param_1,(byte)*(undefined4 *)(iVar2 + *piVar1),*(int **)(iVar2 + 4 + *piVar1));
      iVar2 = iVar2 + 8;
      param_2 = (int *)((int)param_2 + -1);
    } while (param_2 != (int *)0x0);
  }
  *(undefined4 *)(**(int **)(*piVar1 + 8) + 0xc) = *(undefined4 *)(*piVar1 + 0xc);
  *(undefined4 *)(**(int **)(*piVar1 + 0xc) + 8) = *(undefined4 *)(*piVar1 + 8);
  cast_freeHandle(piVar1);
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + -1;
  return 0;
}



// ============================================================
// Function: props_listToString (FUN_6803bcb0)
// Address: 6803bcb0
// Size: 256 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_listToString(int *param_1,int param_2,int param_3,int param_4)
{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  undefined4 unaff_EBX;
  code *unaff_ESI;
  int unaff_EDI;
  int local_2c;
  undefined4 local_28;
  int local_24;
  int *local_20;
  int local_1c;
  int local_18;
  undefined1 local_14;
  byte local_13 [11];
  uint local_8;
  
  local_20 = param_1;
  bVar1 = js_isGCActive();
  if (CONCAT31(extraout_var,bVar1) == 0) {
    cast_loadPascalString(&local_14,0x898,param_3);
    cast_loadPascalString(&DAT_68197780,0x898,param_2);
    props_formatString(unaff_EDI,unaff_ESI,unaff_EBX,&DAT_68197781);
    local_24 = *(int *)(*local_20 + 0x10);
    local_1c = 0;
    if (0 < local_24) {
      local_18 = 0x28;
      do {
        local_2c = *(int *)(*local_20 + local_18);
        local_28 = *(undefined4 *)(*local_20 + 4 + local_18);
        props_valueToString(unaff_EDI,&local_2c,unaff_ESI,unaff_EBX);
        if (local_1c != local_24 + -1) {
          props_formatString(unaff_EDI,unaff_ESI,unaff_EBX,local_13);
        }
        iVar2 = (*unaff_ESI)();
        if (iVar2 == 0) goto LAB_6803bda5;
        local_18 = local_18 + 8;
        local_1c = local_1c + 1;
      } while (local_1c < local_24);
    }
  }
  else {
    param_4 = 0x2c;
  }
  cast_loadPascalString(&DAT_68197780,0x898,param_4);
  props_formatString(unaff_EDI,unaff_ESI,unaff_EBX,&DAT_68197781);
LAB_6803bda5:
  return 0;
}



// ============================================================
// Function: props_printList (FUN_6803bdc0)
// Address: 6803bdc0
// Size: 37 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_printList(undefined4 param_1,int *param_2)
{
  props_listToString(param_2,0x1e,0x20,0x1f);
  return 0;
}



// ============================================================
// Function: props_isListType (FUN_6803bdf0)
// Address: 6803bdf0
// Size: 43 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_isListType(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  switch(param_3) {
  default:
    return 0;
  case 0xffffffff:
  case 0xcb:
  case 0xcc:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
  case 0xd3:
  case 0xd5:
  case 0xd7:
  case 0xd8:
  case 0xd9:
  case 0xda:
  case 0xdc:
  case 0xdd:
  case 0xde:
  case 0xdf:
  case 0xe0:
  case 0xe1:
  case 0xe2:
  case 0xe3:
  case 0xe4:
    return 1;
  }
}



// ============================================================
// Function: props_getListProp (FUN_6803bf10)
// Address: 6803bf10
// Size: 53 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getListProp(undefined4 param_1,int *param_2,int param_3,int param_4,undefined4 *param_5)

{
  if ((param_4 == 0xdd) && (param_3 == 0)) {
    *param_5 = 4;
    param_5[1] = *(undefined4 *)(*param_2 + 0x10);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_listNoOp (FUN_6803bf50)
// Address: 6803bf50
// Size: 5 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_listNoOp(void)

{
  return 0;
}



// ============================================================
// Function: props_findListHandle (FUN_6803bf60)
// Address: 6803bf60
// Size: 41 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_findListHandle(void)

{
  int iVar1;
  int *in_EAX;
  int *piVar2;
  int iVar3;
  
  iVar1 = *(int *)(*in_EAX + 0x10);
  iVar3 = 0;
  if (0 < iVar1) {
    piVar2 = (int *)(*in_EAX + 0x28);
    do {
      if ((*piVar2 == 4) && (piVar2[1] != 0)) {
        return piVar2[1];
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 2;
    } while (iVar3 < iVar1);
  }
  return 0;
}



// ============================================================
// Function: props_createListAndNotify (FUN_6803bfa0)
// Address: 6803bfa0
// Size: 68 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_createListAndNotify(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  
  uVar1 = props_createList(param_1,param_2,param_3);
  switch(param_3) {
  case 0xcb:
  case 0xcc:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
  case 0xda:
  case 0xdb:
  case 0xdc:
    sprites_updateMemberCallback(param_1,param_2);
  }
  return uVar1;
}



// ============================================================
// Function: props_createListScript (FUN_6803c000)
// Address: 6803c000
// Size: 35 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_createListScript(int param_1,int *param_2,int param_3)
{
  crt_setScriptProperty(param_1,param_2);
  props_createList(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_getListPropScript (FUN_6803c030)
// Address: 6803c030
// Size: 43 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getListPropScript(int param_1,int *param_2,int param_3,int param_4,undefined4 *param_5)
{
  crt_setScriptProperty(param_1,param_2);
  props_getListProp(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: props_getListEntryAsInt (FUN_6803c060)
// Address: 6803c060
// Size: 128 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 * param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getListEntryAsInt(int param_1,int *param_2,int param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  if ((-1 < param_3) && (iVar2 = *param_2, param_3 < *(int *)(iVar2 + 0x10))) {
    local_c = *(int *)(iVar2 + 0x28 + param_3 * 8);
    local_8 = *(undefined4 *)(iVar2 + 0x2c + param_3 * 8);
    iVar2 = props_coerceToInt(param_1,&local_c,&param_1);
    if (iVar2 == 0) {
      props_setError(iVar1,0x3e);
      return 0;
    }
    *param_4 = 4;
    param_4[1] = param_1;
    return 1;
  }
  if (param_5 == 0) {
    props_setError(param_1,0x3f);
  }
  return 0;
}



// ============================================================
// Function: props_getListEntry (FUN_6803c0e0)
// Address: 6803c0e0
// Size: 77 bytes
// Params: undefined4 param_1, int * param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getListEntry(undefined4 param_1,int *param_2,int param_3,uint *param_4)
{
  int iVar1;
  
  if ((param_3 < 0) || (iVar1 = *param_2, *(int *)(iVar1 + 0x10) <= param_3)) {
    *param_4 = 2;
    param_4[1] = 0;
  }
  else {
    *param_4 = *(uint *)(iVar1 + 0x28 + param_3 * 8);
    param_4[1] = *(uint *)(iVar1 + 0x2c + param_3 * 8);
    if ((*param_4 & 1) != 0) {
      props_retainValue(param_1,param_4);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: props_getListEntryRaw (FUN_6803c130)
// Address: 6803c130
// Size: 62 bytes
// Params: undefined4 param_1, int * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getListEntryRaw(undefined4 param_1,int *param_2,int param_3,undefined4 *param_4)
{
  int iVar1;
  
  if ((-1 < param_3) && (iVar1 = *param_2, param_3 < *(int *)(iVar1 + 0x10))) {
    *param_4 = *(undefined4 *)(iVar1 + 0x28 + param_3 * 8);
    param_4[1] = *(undefined4 *)(iVar1 + 0x2c + param_3 * 8);
    return 0;
  }
  *param_4 = 2;
  param_4[1] = 0;
  return 0;
}



// ============================================================
// Function: props_getListLength (FUN_6803c170)
// Address: 6803c170
// Size: 15 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getListLength(undefined4 param_1,int *param_2)

{
  return *(undefined4 *)(*param_2 + 0x10);
}



// ============================================================
// Function: props_sortListEntries (FUN_6803c180)
// Address: 6803c180
// Size: 59 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_sortListEntries(undefined4 param_1,int *param_2,int param_3)
{
  if (*(int *)(*param_2 + 0x20) == 0) {
    *(undefined4 *)(*param_2 + 0x20) = 1;
    if (param_3 != 0) {
      *(code **)(*param_2 + 0x24) = props_convertValue;
    }
    props_sortList(param_1,param_2,0,*(int *)(*param_2 + 0x10) + -1);
  }
  return 0;
}



// ============================================================
// Function: props_allocList (FUN_6803c1c0)
// Address: 6803c1c0
// Size: 130 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_allocList(int param_1,int param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = stage_allocDispatchEntry(0x30,0x28,8,param_2);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
  puVar1 = (undefined4 *)*piVar3;
  puVar1[1] = 1;
  *puVar1 = &PTR_LAB_6818d268;
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
// Function: props_setListVtable (FUN_6803c250)
// Address: 6803c250
// Size: 30 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_setListVtable(undefined4 param_1,undefined4 *param_2)
{
  if ((param_2 != (undefined4 *)0x0) && (*(undefined ***)*param_2 == &PTR_LAB_6818d268)) {
    *(undefined ***)*param_2 = &PTR_LAB_6818d320;
  }
  return 0;
}



// ============================================================
// Function: props_setListSortVtable (FUN_6803c270)
// Address: 6803c270
// Size: 30 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_setListSortVtable(undefined4 param_1,undefined4 *param_2)
{
  if ((param_2 != (undefined4 *)0x0) && (*(undefined ***)*param_2 == &PTR_LAB_6818d268)) {
    *(undefined ***)*param_2 = &PTR_LAB_6818d370;
  }
  return 0;
}



// ============================================================
// Function: props_getListRange (FUN_6803c290)
// Address: 6803c290
// Size: 62 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_getListRange(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)(*param_2 + 0x10);
  iVar2 = 0;
  if (0 < iVar1) {
    piVar3 = (int *)(*param_2 + 0x28);
    do {
      if ((*piVar3 == *param_3) && (piVar3[1] == param_3[1])) {
        return iVar2;
      }
      iVar2 = iVar2 + 1;
      piVar3 = piVar3 + 2;
    } while (iVar2 < iVar1);
  }
  return -1;
}



// ============================================================
// Function: props_setListEntry (FUN_6803c2d0)
// Address: 6803c2d0
// Size: 65 bytes
// Params: int param_1, int * param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_setListEntry(int param_1,int *param_2,uint *param_3)
{
  uint local_c;
  uint local_8;
  
  local_c = *param_3;
  local_8 = param_3[1];
  if ((local_c & 1) != 0) {
    props_retainValue(param_1,&local_c);
  }
  stage_lookupSymbolId(param_2,&local_c);
  props_checkReentrant(param_1);
  return 0;
}



// ============================================================
// Function: props_setListRange (FUN_6803c320)
// Address: 6803c320
// Size: 54 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_setListRange(undefined4 param_1,int *param_2,int param_3)
{
  int iVar1;
  
  if ((-1 < param_3) && (iVar1 = *param_2, param_3 < *(int *)(iVar1 + 0x10))) {
    props_releaseValue(param_1,(byte)*(undefined4 *)(iVar1 + 0x28 + param_3 * 8),
                 *(int **)(iVar1 + 0x2c + param_3 * 8));
    stage_emitPushRef(param_2,param_3);
  }
  return 0;
}



// ============================================================
// Function: props_getListCount (FUN_6803c360)
// Address: 6803c360
// Size: 153 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall props_getListCount(int *param_1)
{
  int *in_EAX;
  int iVar1;
  int unaff_EBX;
  int local_c;
  undefined4 local_8;
  
  local_c = *(int *)(*param_1 + 0x28);
  local_8 = *(undefined4 *)(*param_1 + 0x2c);
  iVar1 = props_coerceToInt(unaff_EBX,&local_c,in_EAX + 1);
  if (iVar1 == 0) {
    in_EAX[1] = 0;
  }
  local_c = *(int *)(*param_1 + 0x30);
  local_8 = *(undefined4 *)(*param_1 + 0x34);
  iVar1 = props_coerceToInt(unaff_EBX,&local_c,in_EAX);
  if (iVar1 == 0) {
    *in_EAX = 0;
  }
  local_c = *(int *)(*param_1 + 0x38);
  local_8 = *(undefined4 *)(*param_1 + 0x3c);
  iVar1 = props_coerceToInt(unaff_EBX,&local_c,in_EAX + 3);
  if (iVar1 == 0) {
    in_EAX[3] = 0;
  }
  local_c = *(int *)(*param_1 + 0x40);
  local_8 = *(undefined4 *)(*param_1 + 0x44);
  iVar1 = props_coerceToInt(unaff_EBX,&local_c,in_EAX + 2);
  if (iVar1 == 0) {
    in_EAX[2] = 0;
  }
  return 0;
}


