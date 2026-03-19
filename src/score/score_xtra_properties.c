// Module: score
// Topic: Xtra property access, string ops, file naming
// Address range: 0x6804d6a0 - 0x6804dd00
// Functions (10):
//   score_setXtraData
//   score_dispatchXtraOp
//   score_releaseXtraValue
//   score_accessXtraProperty
//   score_checkXtraError
//   score_getXtraProperty
//   score_matchXtraName
//   score_isXtraLoaded
//   score_getXtraState
//   score_queryXtraStatus

// ============================================================
// Function: score_setXtraData (FUN_6804d6a0)
// Address: 6804d6a0
// Size: 159 bytes
// Params: void * this, int * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall score_setXtraData(void *this,int *param_1)
{
  int iVar1;
  undefined4 local_3c;
  int local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (*(int *)(iVar1 + 8) != 0) {
    props_setError((int)this,0x13);
    return 0;
  }
  local_38 = *(int *)(iVar1 + 0x18);
  local_34 = *(undefined4 *)(iVar1 + 0x1c);
  local_30 = *(undefined4 *)(iVar1 + 0x20);
  local_2c = *(undefined4 *)(iVar1 + 0x24);
  local_28 = *(undefined4 *)(iVar1 + 0x28);
  local_24 = *(undefined4 *)(iVar1 + 0x2c);
  local_20 = *(undefined4 *)(iVar1 + 0x30);
  local_1c = *(undefined4 *)(iVar1 + 0x34);
  local_18 = *(undefined4 *)(iVar1 + 0x38);
  local_14 = *(undefined4 *)(iVar1 + 0x3c);
  local_10 = *(undefined4 *)(iVar1 + 0x40);
  local_c = *(undefined4 *)(iVar1 + 0x44);
  local_3c = *(undefined4 *)(iVar1 + 0x10);
  core_registerFieldHandlers(this,&local_38,&local_3c);
  return 0;
}


// ============================================================
// Function: score_dispatchXtraOp (FUN_6804d740)
// Address: 6804d740
// Size: 401 bytes
// Params: void * param_1, int * param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_dispatchXtraOp(void *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  void *this;
  uint local_14 [2];
  int local_c;
  uint *local_8;
  
  local_c = 1;
  local_8 = (uint *)0x0;
  this = (void *)props_getInt((int)param_1);
  local_14[0] = 0;
  switch(param_3) {
  case 0x57:
    score_deleteXtraMatch(param_1,param_2);
    break;
  default:
    local_c = 0;
    break;
  case 0x5b:
    score_formatXtraString((void *)0x2,0x10);
    break;
  case 0x5c:
  case 0xca:
    score_formatXtraString((void *)0x2,0x30);
    break;
  case 0x5d:
  case 0xce:
    score_formatXtraString((void *)0x2,0x20);
    break;
  case 0x81:
    score_setXtraConfigValue(param_2);
    iVar1 = *(int *)((int)param_1 + 0x7c);
    goto joined_r0x6804d881;
  case 0xd4:
  case 0xd5:
    if (this == (void *)0x2) {
      local_8 = local_14;
      sprites_dispatchSoundMedia((int)param_1,param_2,local_8);
    }
    else {
      score_setXtraConfigValue(param_2);
      if ((*(int *)((int)param_1 + 0x7c) == 0) &&
         (score_applyXtraPattern(param_2), *(int *)((int)param_1 + 0x7c) == 0)) {
        local_8 = local_14;
      }
    }
    break;
  case 0xdb:
  case 0xdc:
    if (this == (void *)0x3) {
      sprites_dispatchShapeColor((int)param_1,param_2);
    }
    else {
      score_setXtraConfigValue(param_2);
      if (*(int *)((int)param_1 + 0x7c) == 0) {
        score_formatXtraString(this,0x10);
      }
    }
    break;
  case 0xdd:
    score_dispatchXtraRegex(param_2);
    iVar1 = *(int *)((int)param_1 + 0x7c);
joined_r0x6804d881:
    local_8 = local_14;
    if (iVar1 != 0) {
      return 1;
    }
    break;
  case 0xe3:
    score_resolveType((uint)param_1);
    return 1;
  case 0x118:
    score_setXtraData(param_1,param_2);
  }
  iVar1 = local_c;
  if (*(int *)((int)param_1 + 0x7c) != 0) {
    return 1;
  }
  if (local_c != 0) {
    props_popArgs((int)param_1,local_8);
  }
  return iVar1;
}


// ============================================================
// Function: score_releaseXtraValue (FUN_6804d9d0)
// Address: 6804d9d0
// Size: 45 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_releaseXtraValue(int param_1,int *param_2)
{
  props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 8),*(int **)(*param_2 + 0xc));
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}


// ============================================================
// Function: score_accessXtraProperty (FUN_6804da00)
// Address: 6804da00
// Size: 156 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_accessXtraProperty(int param_1,int *param_2,int param_3,int param_4,uint *param_5)

{
  uint *puVar1;
  byte *pbVar2;
  int iVar3;
  byte local_c [4];
  int *local_8;
  
  if ((param_3 == 0) && (param_4 == 0x8a)) {
    score_applyXtraPattern(param_2);
    puVar1 = param_5;
    if (*(int *)(param_1 + 0x7c) != 0) {
      return 1;
    }
    *param_5 = 4;
    pbVar2 = (byte *)props_getStringData((int *)local_c,(int *)&param_5);
    props_invokeBuiltin(param_1,1,(int)puVar1,pbVar2,(int)param_5);
    props_unlockString((int *)local_c);
    props_releaseValue(param_1,local_c[0],local_8);
    return 1;
  }
  iVar3 = props_accessProperty(param_1,param_2,param_3,param_4,param_5);
  return iVar3;
}


// ============================================================
// Function: score_checkXtraError (FUN_6804daa0)
// Address: 6804daa0
// Size: 25 bytes
// Params: undefined4 param_1, int * param_2
// Return: char
// Calling convention: __stdcall
// ============================================================

char score_checkXtraError(undefined4 param_1,int *param_2)

{
  return (-(*(int *)(*param_2 + 8) != 0) & 0x5eU) + 0x2d;
}


// ============================================================
// Function: score_getXtraProperty (FUN_6804dac0)
// Address: 6804dac0
// Size: 165 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
score_getXtraProperty(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(0x48,0);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  puVar1 = (undefined4 *)*piVar2;
  *puVar1 = &PTR_FUN_6818d8b8;
  puVar1[1] = 1;
  if (param_4 == (undefined4 *)0x0) {
    *(undefined2 *)((int)puVar1 + 0x12) = 0xffff;
    *(undefined2 *)(puVar1 + 4) = 0;
  }
  else {
    puVar1[4] = *param_4;
  }
  puVar1[5] = param_3;
  if (param_2 == (undefined4 *)0x0) {
    puVar1[2] = 0;
  }
  else {
    puVar1[2] = *param_2;
    puVar1[3] = param_2[1];
  }
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  puVar1[9] = 0;
  puVar1[10] = 0;
  puVar1[0xb] = 0;
  puVar1[0xc] = 0;
  puVar1[0xd] = 0;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0x10] = 0;
  puVar1[0x11] = 0;
  param_5[1] = piVar2;
  *param_5 = 3;
  return 1;
}


// ============================================================
// Function: score_matchXtraName (FUN_6804db70)
// Address: 6804db70
// Size: 102 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall score_matchXtraName(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  uint local_c [2];
  
  iVar1 = props_getValueDirect(param_2,param_1,1,local_c);
  bVar3 = iVar1 == 0;
  if (!bVar3) {
    if ((local_c[0] != 0x40) && (local_c[0] != 0x43)) {
      return true;
    }
    piVar2 = props_getStringData((int *)local_c,(int *)0x0);
    iVar1 = Ordinal_1309(param_3,0x400,piVar2,2);
    bVar3 = iVar1 == 0;
    props_unlockString((int *)local_c);
  }
  return bVar3;
}


// ============================================================
// Function: score_isXtraLoaded (FUN_6804dbe0)
// Address: 6804dbe0
// Size: 93 bytes
// Params: undefined4 param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool score_isXtraLoaded(undefined4 param_1)

{
  int *in_EAX;
  int *piVar1;
  int iVar2;
  int local_c;
  undefined4 local_8;
  
  local_c = *(int *)(*in_EAX + 8);
  local_8 = *(undefined4 *)(*in_EAX + 0xc);
  if ((local_c != 0x40) && (local_c != 0x43)) {
    return true;
  }
  piVar1 = props_getStringData(&local_c,(int *)0x0);
  iVar2 = Ordinal_1309(param_1,0x400,piVar1,2);
  props_unlockString(&local_c);
  return (bool)('\x01' - (iVar2 != 0));
}


// ============================================================
// Function: score_getXtraState (FUN_6804dc40)
// Address: 6804dc40
// Size: 161 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getXtraState(undefined4 param_1)
{
  int iVar1;
  int *unaff_EBX;
  int *unaff_EDI;
  undefined1 local_420 [1048];
  uint local_8;
  
  iVar1 = *(int *)(*unaff_EBX + 0x10);
  *unaff_EDI = iVar1;
  if (iVar1 == 0) {
    score_isXtraLoaded(local_420);
    switch(param_1) {
    case 0:
      Ordinal_1402();
      break;
    case 1:
      Ordinal_1402();
      break;
    case 2:
      Ordinal_1402();
      break;
    case 3:
      Ordinal_1401();
    }
    *(int *)(*unaff_EBX + 0x10) = *unaff_EDI;
  }
  return 0;
}


// ============================================================
// Function: score_queryXtraStatus (FUN_6804dd00)
// Address: 6804dd00
// Size: 313 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, uint * param_4, uint * param_5
// Return: uint
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall
score_queryXtraStatus(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4,uint *param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar3;
  int unaff_EDI;
  uint local_1c [2];
  int local_14;
  int *local_10;
  undefined4 local_c;
  undefined4 local_8;
  uint uVar2;
  
  *param_4 = 2;
  local_1c[0] = 0;
  *param_5 = 1;
  bVar1 = score_isXtraLoaded(param_2);
  uVar2 = CONCAT31(extraout_var,bVar1);
  if ((uVar2 == 0) && (iVar3 = props_getInt(unaff_EDI), 1 < iVar3)) {
    _DAT_68197764 =
         (int *)(**(int **)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x20) * -8 + 8 +
                *(int *)(unaff_EDI + 0x18));
    local_10 = DAT_6819776c;
    local_14 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_68197768 = 0;
      DAT_6819776c = (int *)0x0;
      local_10 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_14 = *(int *)(size_t)_DAT_68197764;
    }
    iVar3 = score_getProplistValue(unaff_EDI,&local_14);
    if ((iVar3 == 0) != 0) {
      props_setError(unaff_EDI,0x13);
      props_clearValue(unaff_EDI,local_1c);
      return (uint)(iVar3 == 0);
    }
    local_c = 8;
    local_8 = 0x151;
    score_updateProplist(unaff_EDI,local_10,&local_c,param_4);
    local_c = 8;
    local_8 = 0x14c;
    iVar3 = score_updateProplist(unaff_EDI,local_10,&local_c,local_1c);
    uVar2 = 0;
    if (iVar3 != 0) {
      iVar3 = props_requireInt(unaff_EDI,(int *)local_1c,&param_3);
      uVar2 = (uint)(iVar3 == 0);
      if (uVar2 == 0) {
        *param_5 = (uint)(param_3 != 0);
        props_clearValue(unaff_EDI,local_1c);
      }
    }
  }
  props_clearValue(unaff_EDI,local_1c);
  return uVar2;
}


