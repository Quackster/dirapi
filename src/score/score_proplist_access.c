// Module: score
// Topic: PropList access, iteration, min/max, check
// Address range: 0x680436c0 - 0x68043d80
// Functions (13):
//   score_compareProplistEntries
//   score_findProplistMin
//   score_findProplistMax
//   score_checkProplistKind
//   score_dispatchProplistOp
//   score_freeProplist
//   score_formatProplistString
//   score_isProplistOp
//   score_resolveProplistValue
//   score_findProplistInt
//   score_getProplistValue
//   score_lookupProplistEntry
//   score_storeProplistProperty

// ============================================================
// Function: score_compareProplistEntries (FUN_680436c0)
// Address: 680436c0
// Size: 144 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_compareProplistEntries(int param_1,int *param_2,int param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  int local_c;
  int local_8;
  
  pcVar1 = *(code **)(*param_2 + 0x24);
  iVar4 = props_getInt(param_1);
  if (iVar4 == 1) {
    iVar4 = *param_2;
    local_c = *(int *)(iVar4 + 0x10);
    if (0 < local_c) {
      uVar5 = *(undefined4 *)(iVar4 + 0x30);
      uVar6 = *(undefined4 *)(iVar4 + 0x34);
      if (1 < local_c) {
        local_c = local_c + -1;
        local_8 = 0x40;
        do {
          uVar2 = *(undefined4 *)(*param_2 + 4 + local_8);
          uVar3 = *(undefined4 *)(*param_2 + local_8);
          iVar4 = (*pcVar1)(param_1,uVar5,uVar6,uVar3,uVar2);
          if (iVar4 != param_3) {
            uVar5 = uVar3;
            uVar6 = uVar2;
          }
          local_8 = local_8 + 0x10;
          local_c = local_c + -1;
        } while (local_c != 0);
      }
      param_4[1] = uVar6;
      *param_4 = uVar5;
    }
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_findProplistMin (FUN_68043760)
// Address: 68043760
// Size: 26 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_findProplistMin(int param_1,int *param_2,undefined4 *param_3)
{
  score_compareProplistEntries(param_1,param_2,1,param_3);
  return 0;
}


// ============================================================
// Function: score_findProplistMax (FUN_68043780)
// Address: 68043780
// Size: 26 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_findProplistMax(int param_1,int *param_2,undefined4 *param_3)
{
  score_compareProplistEntries(param_1,param_2,-1,param_3);
  return 0;
}


// ============================================================
// Function: score_checkProplistKind (FUN_680437a0)
// Address: 680437a0
// Size: 104 bytes
// Params: uint param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_checkProplistKind(uint param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_1;
  iVar2 = props_getInt(param_1);
  if (iVar2 == 1) {
    *param_3 = 8;
    param_3[1] = 0xbb;
    return 1;
  }
  iVar2 = props_getTypedValue(uVar1,2,8,&param_1);
  if (iVar2 == 0) {
    return 0;
  }
  if ((0xb9 < (int)param_1) && ((int)param_1 < 0xbc)) {
    param_3[1] = 1;
  }
  return 1;
}


// ============================================================
// Function: score_dispatchProplistOp (FUN_68043820)
// Address: 68043820
// Size: 113 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_dispatchProplistOp(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint local_c [2];
  
  if (0x19 < param_3 - 0xcbU) {
    return 0;
  }
  local_c[0] = 4;
  local_c[1] = 0;
  iVar1 = (**(code **)(&DAT_6818d1ec + param_3 * 4))(param_1,param_2,local_c);
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
// Function: score_freeProplist (FUN_680438a0)
// Address: 680438a0
// Size: 132 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_freeProplist(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = param_1;
  param_1 = *(int *)(*param_2 + 0x10);
  if (0 < param_1) {
    iVar6 = 0;
    do {
      iVar2 = *param_2;
      uVar3 = *(undefined4 *)(iVar6 + 0x30 + iVar2);
      iVar1 = iVar6 + 0x28 + iVar2;
      piVar4 = *(int **)(iVar1 + 0xc);
      props_releaseValue(iVar5,(byte)*(undefined4 *)(iVar6 + 0x28 + iVar2),*(int **)(iVar1 + 4));
      props_releaseValue(iVar5,(byte)uVar3,piVar4);
      iVar6 = iVar6 + 0x10;
      param_1 = param_1 + -1;
    } while (param_1 != 0);
  }
  *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
  *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
  cast_freeHandle(param_2);
  *(int *)(iVar5 + 0xf8) = *(int *)(iVar5 + 0xf8) + -1;
  return 0;
}


// ============================================================
// Function: score_formatProplistString (FUN_68043930)
// Address: 68043930
// Size: 398 bytes
// Params: int param_1, int * param_2, undefined * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatProplistString(int param_1,int *param_2,undefined *param_3,undefined4 param_4)
{
  int *piVar1;
  int iVar2;
  bool bVar3;
  undefined3 extraout_var;
  int iVar4;
  int local_24;
  int local_20;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  bVar3 = js_isGCActive();
  if (CONCAT31(extraout_var,bVar3) == 0) {
    iVar2 = *(int *)(*param_2 + 0x10);
    if (iVar2 == 0) {
      cast_loadPascalString(&DAT_68197780,0x898,0x24);
    }
    else {
      cast_loadPascalString(&DAT_68197780,0x898,0x1e);
      props_formatString(param_1,param_3,param_4,&DAT_68197781);
      if (DAT_681962b4 == '\0') {
        cast_loadPascalString(&DAT_681962b4,0x898,0x25);
      }
      if (DAT_681962a8 == '\0') {
        cast_loadPascalString(&DAT_681962a8,0x898,0x20);
      }
      local_24 = 0;
      if (0 < iVar2) {
        local_20 = 0;
        do {
          piVar1 = (int *)(*param_2 + 0x28 + local_20);
          local_18 = *piVar1;
          local_14 = piVar1[1];
          local_10 = piVar1[2];
          local_c = piVar1[3];
          props_valueToString(param_1,&local_18,param_3,param_4);
          props_formatString(param_1,param_3,param_4,&DAT_681962b5);
          props_valueToString(param_1,&local_10,param_3,param_4);
          if (local_24 != iVar2 + -1) {
            props_formatString(param_1,param_3,param_4,&DAT_681962a9);
          }
          iVar4 = (*(code *)param_3)(param_4,0);
          if (iVar4 == 0) goto LAB_68043aae;
          local_20 = local_20 + 0x10;
          local_24 = local_24 + 1;
        } while (local_24 < iVar2);
      }
      cast_loadPascalString(&DAT_68197780,0x898,0x1f);
    }
  }
  else {
    cast_loadPascalString(&DAT_68197780,0x898,0x2c);
  }
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
LAB_68043aae:
  return 0;
}


// ============================================================
// Function: score_isProplistOp (FUN_68043ad0)
// Address: 68043ad0
// Size: 43 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_isProplistOp(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  switch(param_3) {
  default:
    return 0;
  case 0xffffffff:
  case 0xcd:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
  case 0xd3:
  case 0xd4:
  case 0xd5:
  case 0xd6:
  case 0xd7:
  case 0xd8:
  case 0xd9:
  case 0xda:
  case 0xdb:
  case 0xdc:
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
// Function: score_resolveProplistValue (FUN_68043bf0)
// Address: 68043bf0
// Size: 198 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_resolveProplistValue(undefined4 param_1,int *param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint local_c;
  int local_8;
  
  piVar2 = param_2;
  local_c = 8;
  local_8 = param_4;
  if (param_3 != 0) {
    iVar3 = score_updateEntry(param_5,&local_c,0);
    return iVar3;
  }
  if (*(int *)(*param_2 + 0x20) == 0) {
    iVar3 = score_formatValue(param_1,param_2,(int *)&param_2);
  }
  else {
    iVar3 = score_formatString(param_1,param_2,&local_c,(int *)&param_2);
  }
  if (iVar3 != 0) {
    iVar1 = *piVar2;
    *param_5 = *(uint *)(iVar1 + ((int)param_2 + 3) * 0x10);
    param_5[1] = *(uint *)(iVar1 + 4 + ((int)param_2 + 3) * 0x10);
    if (iVar3 != 0) {
      if ((*param_5 & 1) == 0) {
        return iVar3;
      }
      props_retainValue(param_1,param_5);
      return iVar3;
    }
  }
  if (param_4 != 0xdd) {
    return iVar3;
  }
  *param_5 = 4;
  param_5[1] = *(uint *)(*piVar2 + 0x10);
  return 1;
}


// ============================================================
// Function: score_findProplistInt (FUN_68043cc0)
// Address: 68043cc0
// Size: 41 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_findProplistInt(void)

{
  int iVar1;
  int *in_EAX;
  int *piVar2;
  int iVar3;
  
  iVar1 = *(int *)(*in_EAX + 0x10);
  iVar3 = 0;
  if (0 < iVar1) {
    piVar2 = (int *)(*in_EAX + 0x30);
    do {
      if ((*piVar2 == 4) && (piVar2[1] != 0)) {
        return piVar2[1];
      }
      iVar3 = iVar3 + 1;
      piVar2 = piVar2 + 4;
    } while (iVar3 < iVar1);
  }
  return 0;
}


// ============================================================
// Function: score_getProplistValue (FUN_68043cf0)
// Address: 68043cf0
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getProplistValue(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d4c8)) {
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_lookupProplistEntry (FUN_68043d20)
// Address: 68043d20
// Size: 85 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3, undefined4 * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_lookupProplistEntry(undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,
                 int *param_5)
{
  int iVar1;
  int iVar2;
  
  if (*(int *)(*param_2 + 0x20) == 0) {
    iVar2 = score_formatValue(param_1,param_2,param_5);
  }
  else {
    iVar2 = score_formatString(param_1,param_2,param_3,param_5);
  }
  if (iVar2 != 0) {
    iVar2 = *param_5;
    iVar1 = *param_2;
    *param_4 = *(undefined4 *)(iVar1 + (iVar2 + 3) * 0x10);
    param_4[1] = *(undefined4 *)(iVar1 + 4 + (iVar2 + 3) * 0x10);
  }
  return 0;
}


// ============================================================
// Function: score_storeProplistProperty (FUN_68043d80)
// Address: 68043d80
// Size: 115 bytes
// Params: undefined4 param_1, int * param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_storeProplistProperty(undefined4 param_1,int *param_2,int param_3,uint *param_4,uint *param_5)
{
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_18 = *param_4;
  local_14 = param_4[1];
  local_10 = *param_5;
  local_c = param_5[1];
  if ((local_18 & 1) != 0) {
    props_retainValue(param_1,&local_18);
  }
  if ((local_10 & 1) != 0) {
    props_retainValue(param_1,&local_10);
  }
  stage_emitStoreProperty(param_2,param_3,&local_18);
  return 0;
}


