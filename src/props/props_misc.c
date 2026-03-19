// Module: props
// Topic: Miscellaneous global property handlers and builtins
// Address range: 0x6803e910 - 0x6803ec40
// Functions (9):
//   props_intersectRect (FUN_6803e910)
//   props_composeRect (FUN_6803e970)
//   props_equalizeRect (FUN_6803e9a0)
//   props_accessGlobalProps (FUN_6803e9c0)
//   props_formatTimeString (FUN_6803eb30)
//   props_formatDateString (FUN_6803eb80)
//   props_handleDateBuiltin (FUN_6803ebd0)
//   props_handleTimeBuiltin (FUN_6803ec10)
//   props_parseStringConstant (FUN_6803ec40)



// ============================================================
// Function: props_intersectRect (FUN_6803e910)
// Address: 6803e910
// Size: 85 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_intersectRect(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_3[1];
  local_14 = *param_3;
  local_10 = param_3[3];
  local_c = param_3[2];
  local_20 = param_2[1];
  local_1c = *param_2;
  Ordinal_1070(&local_18,&local_20);
  return 0;
}



// ============================================================
// Function: props_composeRect (FUN_6803e970)
// Address: 6803e970
// Size: 37 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_composeRect(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)
{
  param_4[1] = param_2[1];
  *param_4 = *param_2;
  param_4[3] = param_3[1];
  param_4[2] = *param_3;
  return 0;
}



// ============================================================
// Function: props_equalizeRect (FUN_6803e9a0)
// Address: 6803e9a0
// Size: 23 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_equalizeRect(undefined4 param_1,int *param_2,int *param_3)
{
  props_mapPointToRect(param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_accessGlobalProps (FUN_6803e9c0)
// Address: 6803e9c0
// Size: 344 bytes
// Params: uint param_1, uint param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_accessGlobalProps(uint param_1,uint param_2,int param_3,uint *param_4)
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int local_14;
  byte local_10 [8];
  uint local_8;
  
  switch(param_3) {
  case 0x10d:
    if (param_2 == 0) {
      param_4[1] = DAT_6818e0b4;
    }
    else {
      iVar2 = props_requireInt(param_1,(int *)param_4,&local_14);
      if (iVar2 != 0) {
        DAT_6818e0b4 = (uint)(local_14 != 0);
      }
    }
    break;
  case 0x10e:
    if (param_2 == 0) {
      uVar1 = cast_getGlobalData();
      param_4[1] = uVar1;
    }
    else {
      iVar2 = props_requireInt(param_1,(int *)param_4,&local_14);
      if (iVar2 != 0) {
        cast_seedRandom(local_14);
      }
    }
    break;
  case 0x10f:
    if (param_2 == 0) {
      local_10[1] = 0;
      local_10[2] = 0;
      local_10[3] = 0;
      local_10[4] = 0;
      local_10[5] = 0;
      local_10[0] = 0;
      Ordinal_1246(local_10,*(undefined4 *)(**(int **)(param_1 + 8) + 0x500));
      props_readPascalString(param_1,local_10,param_4);
    }
    else {
      iVar2 = props_validateString(param_1,(int *)param_4);
      if (iVar2 != 0) {
        piVar3 = props_getStringData((int *)param_4,(int *)0x0);
        uVar4 = Ordinal_1252(piVar3,local_10);
        *(undefined4 *)(**(int **)(param_1 + 8) + 0x500) = uVar4;
        props_unlockString((int *)param_4);
      }
    }
    break;
  case 0x110:
    if (param_2 == 0) {
      *param_4 = 3;
      param_4[1] = *(uint *)(**(int **)(param_1 + 8) + 0x4e4);
      props_retainValue(param_1,param_4);
    }
    else {
      props_reportError(param_1,0x39);
    }
    break;
  default:
    core_accessGlobalAll(param_1,param_2,param_3,param_4);
  }
  return 0;
}



// ============================================================
// Function: props_formatTimeString (FUN_6803eb30)
// Address: 6803eb30
// Size: 75 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_formatTimeString(int param_1,int param_2,undefined4 *param_3)
{
  byte local_408 [1024];
  uint local_8;
  
  cast_formatTime(param_2,local_408);
  props_readPascalString(param_1,local_408,param_3);
  return 0;
}



// ============================================================
// Function: props_formatDateString (FUN_6803eb80)
// Address: 6803eb80
// Size: 75 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_formatDateString(int param_1,int param_2,undefined4 *param_3)
{
  byte local_408 [1024];
  uint local_8;
  
  cast_formatDate(param_2,local_408);
  props_readPascalString(param_1,local_408,param_3);
  return 0;
}



// ============================================================
// Function: props_handleDateBuiltin (FUN_6803ebd0)
// Address: 6803ebd0
// Size: 62 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_handleDateBuiltin(int param_1)
{
  int iVar1;
  undefined4 local_c [2];
  
  iVar1 = props_getInt(param_1);
  if (iVar1 == 0) {
    props_formatDateString(param_1,0,local_c);
    props_popArgs(param_1,local_c);
    return 0;
  }
  score_dateFromArgs(param_1);
  return 0;
}



// ============================================================
// Function: props_handleTimeBuiltin (FUN_6803ec10)
// Address: 6803ec10
// Size: 39 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_handleTimeBuiltin(int param_1)
{
  undefined4 local_c [2];
  
  props_formatTimeString(param_1,0,local_c);
  props_popArgs(param_1,local_c);
  return 0;
}



// ============================================================
// Function: props_parseStringConstant (FUN_6803ec40)
// Address: 6803ec40
// Size: 60 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_parseStringConstant(void)
{
  byte *unaff_ESI;
  int unaff_EDI;
  byte local_408 [1024];
  
  props_toPascalString((int *)unaff_ESI,local_408);
  props_parseConstant(unaff_EDI,local_408,unaff_ESI);
  return 0;
}


