// Module: score
// Topic: Date arithmetic and comparison operations
// Address range: 0x680499c0 - 0x68049d90
// Functions (6):
//   score_extractDateParts (FUN_680499c0)
//   score_allocDateValue (FUN_68049a00)
//   score_offsetDate (FUN_68049ab0)
//   score_evalDateArith (FUN_68049b00)
//   score_compareDateBytes (FUN_68049c50)
//   score_createDateFromData (FUN_68049d90)

// ============================================================
// Function: score_extractDateParts (FUN_680499c0)
// Address: 680499c0
// Size: 58 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_extractDateParts(undefined4 param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  int extraout_EDX;
  
  iVar2 = score_isDateObject(param_1,param_2);
  if (iVar2 != 0) {
    piVar1 = *(int **)(extraout_EDX + 4);
    *param_3 = *(undefined4 *)(*piVar1 + 0xc);
    *param_4 = *(undefined4 *)(*piVar1 + 8);
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_allocDateValue (FUN_68049a00)
// Address: 68049a00
// Size: 161 bytes
// Params: int * param_1, undefined4 param_2, int param_3, undefined4 * param_4
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint score_allocDateValue(int *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint local_c;
  int *local_8;
  
  piVar1 = param_1;
  uVar2 = stage_allocFactorySlot((int)param_1,(int *)&param_1);
  if (uVar2 == 0) {
    piVar4 = param_1;
    iVar3 = param_3;
    if (param_3 == 2) {
      uVar2 = stage_allocString(piVar1,&local_c);
      piVar4 = local_8;
      if ((uVar2 == 0) && (uVar2 = stage_allocString(piVar1,&local_c), uVar2 == 0)) {
LAB_68049a69:
        iVar3 = score_setDateProperty(*piVar1,piVar4,local_8);
        uVar2 = (uint)(iVar3 == 0);
        param_4[1] = iVar3;
        if (uVar2 == 0) {
          *param_4 = 3;
          stage_createFactory((int)piVar1,(int)param_1,param_4);
        }
      }
    }
    else {
      do {
        local_8 = piVar4;
        piVar4 = local_8;
        param_1 = local_8;
        if (iVar3 < 1) goto LAB_68049a69;
        iVar3 = iVar3 + -1;
        uVar2 = stage_allocString(piVar1,&local_c);
        piVar4 = param_1;
      } while (uVar2 == 0);
    }
  }
  return uVar2;
}


// ============================================================
// Function: score_offsetDate (FUN_68049ab0)
// Address: 68049ab0
// Size: 77 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall score_offsetDate(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  if (param_3 == 5) {
    iVar2 = *param_1;
    iVar1 = *(int *)(iVar2 + 0xc) + param_2;
  }
  else {
    if (param_3 != 6) {
      return 0;
    }
    iVar2 = *param_1;
    iVar1 = *(int *)(iVar2 + 0xc) - param_2;
  }
  iVar2 = score_setDateProperty(unaff_ESI,iVar1,*(undefined4 *)(iVar2 + 8));
  if (iVar2 == 0) {
    props_setError(unaff_ESI,2);
    return 0;
  }
  unaff_EDI[1] = iVar2;
  *unaff_EDI = 3;
  return 1;
}


// ============================================================
// Function: score_evalDateArith (FUN_68049b00)
// Address: 68049b00
// Size: 335 bytes
// Params: int param_1, int * param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_evalDateArith(int param_1,int *param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *extraout_EDX;
  int *piVar6;
  int *piVar7;
  int local_1c;
  undefined4 local_14;
  uint local_10;
  int local_c;
  int *local_8;
  
  iVar3 = param_1;
  _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  bVar2 = false;
  iVar4 = DAT_68197768;
  piVar5 = DAT_6819776c;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = (int *)0x0;
    DAT_68197768 = 0;
    iVar4 = *(int *)(size_t)_DAT_68197764;
    piVar5 = (int *)((int *)(size_t)_DAT_68197764)[1];
  }
  local_c = *(int *)(param_1 + 0x1c);
  local_8 = *(int **)(param_1 + 0x20);
  piVar7 = piVar5;
  local_1c = iVar4;
  if ((local_c == 3) && (local_8 == param_2)) {
    local_1c = *(int *)(param_1 + 0x1c);
    piVar7 = *(int **)(param_1 + 0x20);
    bVar2 = true;
    local_c = iVar4;
    local_8 = piVar5;
  }
  iVar4 = score_isDateObject(param_1,&local_c);
  if (iVar4 == 0) {
    iVar4 = props_coerceToInt(iVar3,&local_c,&param_1);
    if (iVar4 == 0) {
      if ((param_3 != 0xf) && (param_3 != 0xe)) {
        return 0;
      }
      local_10 = (uint)(param_3 == 0xe);
      local_14 = 4;
      iVar4 = 1;
      goto LAB_68049b9a;
    }
    iVar4 = score_offsetDate(piVar7,param_1,param_3);
  }
  else {
    piVar5 = extraout_EDX;
    piVar6 = piVar7;
    if (bVar2) {
      piVar5 = piVar7;
      piVar6 = extraout_EDX;
    }
    iVar4 = score_compareDateBytes(piVar5,piVar6,param_3);
  }
  if (iVar4 == 0) {
    return 0;
  }
LAB_68049b9a:
  *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + -0x10;
  iVar1 = **(int **)(iVar3 + 0x10);
  *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(iVar3 + 0x18));
  *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(iVar3 + 0x18));
  props_pushValue(iVar3);
  *(undefined4 *)(iVar3 + 0x1c) = local_14;
  *(uint *)(iVar3 + 0x20) = local_10;
  props_releaseValue(iVar3,(byte)local_1c,piVar7);
  props_releaseValue(iVar3,(byte)local_c,local_8);
  return iVar4;
}


// ============================================================
// Function: score_compareDateBytes (FUN_68049c50)
// Address: 68049c50
// Size: 318 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_compareDateBytes(int *param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  int iVar4;
  char *pcVar5;
  uint uVar6;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  piVar1 = param_1;
  if (((param_3 != 0xf) && (param_3 != 0x24)) && (param_3 != 0x25)) {
    return 0;
  }
  _DAT_68197764 = (int *)(*(int *)param_1[4] + -8 + param_1[6]);
  local_c = DAT_6819776c;
  local_10 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_c = ((int *)(size_t)_DAT_68197764)[1];
    local_10 = *(int *)(size_t)_DAT_68197764;
  }
  local_18 = param_1[7];
  local_14 = param_1[8];
  bVar2 = score_isMediaValid(param_1,&local_10,(int *)&param_1);
  if ((CONCAT31(extraout_var,bVar2) == 0) ||
     (bVar2 = score_isMediaValid(piVar1,&local_18,(int *)&local_8), CONCAT31(extraout_var_00,bVar2) == 0))
  {
    return 0;
  }
  iVar3 = Ordinal_1116(param_1);
  iVar4 = Ordinal_1116(local_8);
  uVar6 = iVar3 - iVar4;
  if (uVar6 == 0) {
    iVar3 = iVar3 + -0x1c;
    pcVar5 = (char *)(*param_1 + 0x1c);
    if (0 < iVar3) {
      iVar4 = (*local_8 + 0x1c) - (int)pcVar5;
      do {
        if (uVar6 != 0) break;
        iVar3 = iVar3 + -1;
        uVar6 = (int)*pcVar5 - (int)pcVar5[iVar4];
        pcVar5 = pcVar5 + 1;
      } while (0 < iVar3);
    }
  }
  if ((param_3 == 0x24) || (param_3 == 0x25)) {
    if ((int)uVar6 < 0) {
      uVar6 = 0xffffffff;
    }
    else if (0 < (int)uVar6) {
      uVar6 = 1;
    }
  }
  else {
    uVar6 = (uint)(uVar6 == 0);
  }
  props_popValue((int)piVar1);
  props_popValue((int)piVar1);
  props_pushValue((int)piVar1);
  piVar1[8] = uVar6;
  piVar1[7] = 4;
  return 1;
}


// ============================================================
// Function: score_createDateFromData (FUN_68049d90)
// Address: 68049d90
// Size: 134 bytes
// Params: int * param_1, undefined4 param_2, int param_3, undefined4 * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_createDateFromData(int *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined3 extraout_var;
  
  if (param_3 < 0) {
    return 1;
  }
  piVar2 = (int *)cast_allocHandle(param_3 + 8,0);
  if (piVar2 == (int *)0x0) {
    return 1;
  }
  iVar3 = Ordinal_1114(piVar2);
  bVar1 = stage_compareScriptRef((int)param_1,iVar3 + 8,param_3);
  Ordinal_1115(piVar2);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    cast_freeHandle(piVar2);
    return CONCAT31(extraout_var,bVar1);
  }
  score_getMediaRef(*param_1,piVar2);
  *param_4 = 3;
  param_4[1] = piVar2;
  stage_createFactory((int)param_1,-1,param_4);
  return 0;
}


