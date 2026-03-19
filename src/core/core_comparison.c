// Module: core
// Topic: Value comparison operators for different types (sprite, color, point, field)
// Address range: 0x68010FD0 - 0x680189B0
// Functions (6):
//   core_compareSprite (0x68010FD0)
//   core_compareColor (0x680110D0)
//   core_comparePoint (0x68011700)
//   core_compareRect (0x68011800)
//   core_compareMember (0x68017F50)
//   core_compareField (0x680189B0)

// ============================================================
// Function: core_compareSprite (FUN_68010fd0)
// Address: 68010fd0
// Size: 245 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_compareSprite(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_3;
  iVar1 = param_1;
  if (((param_3 != 0xf) && (param_3 != 0x24)) && (param_3 != 0x25)) {
    return 0;
  }
  _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  local_14 = *(int *)(param_1 + 0x1c);
  local_10 = *(undefined4 *)(param_1 + 0x20);
  iVar3 = crt_extractChannelRef(param_1,&local_c,(undefined2 *)&param_1);
  if ((iVar3 != 0) && (iVar3 = crt_extractChannelRef(iVar1,&local_14,(undefined2 *)&param_3), iVar3 != 0)) {
    uVar4 = (int)(short)param_1 - (int)(short)param_3;
    if ((iVar2 == 0x24) || (iVar2 == 0x25)) {
      if ((int)uVar4 < 0) {
        uVar4 = 0xffffffff;
      }
      else if (0 < (int)uVar4) {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = (uint)(uVar4 == 0);
    }
    props_popValue(iVar1);
    props_popValue(iVar1);
    props_pushValue(iVar1);
    *(uint *)(iVar1 + 0x20) = uVar4;
    *(undefined4 *)(iVar1 + 0x1c) = 4;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_compareColor (FUN_680110d0)
// Address: 680110d0
// Size: 245 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_compareColor(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_3;
  iVar1 = param_1;
  if (((param_3 != 0xf) && (param_3 != 0x24)) && (param_3 != 0x25)) {
    return 0;
  }
  _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  local_14 = *(int *)(param_1 + 0x1c);
  local_10 = *(undefined4 *)(param_1 + 0x20);
  iVar3 = crt_extractSoundRef(param_1,&local_c,(undefined2 *)&param_1);
  if ((iVar3 != 0) && (iVar3 = crt_extractSoundRef(iVar1,&local_14,(undefined2 *)&param_3), iVar3 != 0)) {
    uVar4 = (int)(short)param_1 - (int)(short)param_3;
    if ((iVar2 == 0x24) || (iVar2 == 0x25)) {
      if ((int)uVar4 < 0) {
        uVar4 = 0xffffffff;
      }
      else if (0 < (int)uVar4) {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = (uint)(uVar4 == 0);
    }
    props_popValue(iVar1);
    props_popValue(iVar1);
    props_pushValue(iVar1);
    *(uint *)(iVar1 + 0x20) = uVar4;
    *(undefined4 *)(iVar1 + 0x1c) = 4;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_comparePoint (FUN_68011700)
// Address: 68011700
// Size: 241 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_comparePoint(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_3;
  iVar1 = param_1;
  if (((param_3 != 0xf) && (param_3 != 0x24)) && (param_3 != 0x25)) {
    return 0;
  }
  _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  local_14 = *(int *)(param_1 + 0x1c);
  local_10 = *(undefined4 *)(param_1 + 0x20);
  iVar3 = core_getSpriteRefNumber(param_1,&local_c,&param_3);
  if ((iVar3 != 0) && (iVar3 = core_getSpriteRefNumber(iVar1,&local_14,&param_1), iVar3 != 0)) {
    uVar4 = param_3 - param_1;
    if ((iVar2 == 0x24) || (iVar2 == 0x25)) {
      if ((int)uVar4 < 0) {
        uVar4 = 0xffffffff;
      }
      else if (0 < (int)uVar4) {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = (uint)(uVar4 == 0);
    }
    props_popValue(iVar1);
    props_popValue(iVar1);
    props_pushValue(iVar1);
    *(uint *)(iVar1 + 0x20) = uVar4;
    *(undefined4 *)(iVar1 + 0x1c) = 4;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_compareRect (FUN_68011800)
// Address: 68011800
// Size: 245 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_compareRect(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_3;
  iVar1 = param_1;
  if (((param_3 != 0xf) && (param_3 != 0x24)) && (param_3 != 0x25)) {
    return 0;
  }
  _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  local_14 = *(int *)(param_1 + 0x1c);
  local_10 = *(undefined4 *)(param_1 + 0x20);
  iVar3 = core_getColorRefNumber(param_1,&local_c,(undefined2 *)&param_1);
  if ((iVar3 != 0) && (iVar3 = core_getColorRefNumber(iVar1,&local_14,(undefined2 *)&param_3), iVar3 != 0)) {
    uVar4 = (int)(short)param_1 - (int)(short)param_3;
    if ((iVar2 == 0x24) || (iVar2 == 0x25)) {
      if ((int)uVar4 < 0) {
        uVar4 = 0xffffffff;
      }
      else if (0 < (int)uVar4) {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = (uint)(uVar4 == 0);
    }
    props_popValue(iVar1);
    props_popValue(iVar1);
    props_pushValue(iVar1);
    *(uint *)(iVar1 + 0x20) = uVar4;
    *(undefined4 *)(iVar1 + 0x1c) = 4;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_compareMember (FUN_68017f50)
// Address: 68017f50
// Size: 245 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_compareMember(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_3;
  iVar1 = param_1;
  if (((param_3 != 0xf) && (param_3 != 0x24)) && (param_3 != 0x25)) {
    return 0;
  }
  _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  local_14 = *(int *)(param_1 + 0x1c);
  local_10 = *(undefined4 *)(param_1 + 0x20);
  iVar3 = core_getMemberRefNumber(param_1,&local_c,(undefined2 *)&param_1);
  if ((iVar3 != 0) && (iVar3 = core_getMemberRefNumber(iVar1,&local_14,(undefined2 *)&param_3), iVar3 != 0)) {
    uVar4 = (int)(short)param_1 - (int)(short)param_3;
    if ((iVar2 == 0x24) || (iVar2 == 0x25)) {
      if ((int)uVar4 < 0) {
        uVar4 = 0xffffffff;
      }
      else if (0 < (int)uVar4) {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = (uint)(uVar4 == 0);
    }
    props_popValue(iVar1);
    props_popValue(iVar1);
    props_pushValue(iVar1);
    *(uint *)(iVar1 + 0x20) = uVar4;
    *(undefined4 *)(iVar1 + 0x1c) = 4;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_compareField (FUN_680189b0)
// Address: 680189b0
// Size: 257 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_compareField(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_3;
  iVar1 = param_1;
  if (((param_3 != 0xf) && (param_3 != 0x24)) && (param_3 != 0x25)) {
    return 0;
  }
  _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  local_14 = *(int *)(param_1 + 0x1c);
  local_10 = *(undefined4 *)(param_1 + 0x20);
  iVar3 = core_setFieldValue(param_1,&local_c,&param_1);
  if ((iVar3 != 0) && (iVar3 = core_setFieldValue(iVar1,&local_14,&param_3), iVar3 != 0)) {
    uVar4 = (int)(short)param_1 - (int)(short)param_3;
    if (uVar4 == 0) {
      uVar4 = (int)(*(unsigned short *)((char *)&param_1 + 2)) - (int)(*(unsigned short *)((char *)&param_3 + 2));
    }
    if ((iVar2 == 0x24) || (iVar2 == 0x25)) {
      if ((int)uVar4 < 0) {
        uVar4 = 0xffffffff;
      }
      else if (0 < (int)uVar4) {
        uVar4 = 1;
      }
    }
    else {
      uVar4 = (uint)(uVar4 == 0);
    }
    props_popValue(iVar1);
    props_popValue(iVar1);
    props_pushValue(iVar1);
    *(uint *)(iVar1 + 0x20) = uVar4;
    *(undefined4 *)(iVar1 + 0x1c) = 4;
    return 1;
  }
  return 0;
}


