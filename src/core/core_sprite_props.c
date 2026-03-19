// Module: core
// Topic: Sprite property iteration, creation, and compound objects
// Address range: 0x6801EE80 - 0x6801F560
// Functions (11):
//   core_getSpritePropByIndex (0x6801EE80)
//   core_getSpritePropByKey (0x6801EFC0)
//   core_createSpriteProps (0x6801F0B0)
//   core_newSpriteMember (0x6801F130)
//   core_dispatchSpriteMemberOp (0x6801F1B0)
//   core_newSpriteMemberRef (0x6801F270)
//   core_dispatchMemberRefOp (0x6801F2F0)
//   core_cloneSpriteProps (0x6801F3B0)
//   core_dispatchSpritePropsOp (0x6801F470)
//   core_lookupSpritePropSymbol (0x6801F530)
//   core_resolveSpritePropDefault (0x6801F560)

// ============================================================
// Function: core_getSpritePropByIndex (FUN_6801ee80)
// Address: 6801ee80
// Size: 283 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_getSpritePropByIndex(int *param_1)

{
  int _local_8;
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 local_20 [2];
  undefined4 local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = *(int **)(*param_1 + 8);
  iVar2 = props_getInt(unaff_ESI);
  if (iVar2 != 3) {
    props_setError(unaff_ESI,0x17);
    return 0;
  }
  _DAT_68197764 =
       (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
              *(int *)(unaff_ESI + 0x18));
  local_c = DAT_6819776c;
  local_10 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_c = ((int *)(size_t)_DAT_68197764)[1];
    local_10 = *(int *)(size_t)_DAT_68197764;
  }
  iVar2 = props_coerceToInt(unaff_ESI,&local_10,&local_8);
  if (iVar2 != 0) {
    iVar2 = props_getListLength(unaff_ESI,piVar1);
    if ((local_8 < 1) || (iVar2 < local_8)) {
      props_setError(unaff_ESI,0x3c);
      return 0;
    }
    _DAT_68197764 =
         (int *)(**(int **)(unaff_ESI + 0x10) + (2 - *(int *)(unaff_ESI + 0x20)) * 8 +
                *(int *)(unaff_ESI + 0x18));
    local_c = DAT_6819776c;
    local_10 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_c = ((int *)(size_t)_DAT_68197764)[1];
      local_10 = *(int *)(size_t)_DAT_68197764;
    }
    local_8 = local_8 + -1;
    score_getProplistRaw(unaff_ESI,piVar1,local_8,&local_18,local_20);
    core_getSetSpriteProp(unaff_ESI,param_1,1,local_14,&local_10);
  }
  return 1;
}



// ============================================================
// Function: core_getSpritePropByKey (FUN_6801efc0)
// Address: 6801efc0
// Size: 228 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_getSpritePropByKey(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  int local_c;
  int local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 != 3) {
    props_setError(unaff_ESI,0x17);
    return 0;
  }
  iVar1 = **(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
          *(int *)(unaff_ESI + 0x18);
  iVar2 = DAT_6819776c;
  if (iVar1 != 0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    iVar2 = *(int *)(iVar1 + 4);
  }
  _DAT_68197764 =
       (int *)(**(int **)(unaff_ESI + 0x10) + (2 - *(int *)(unaff_ESI + 0x20)) * 8 +
              *(int *)(unaff_ESI + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  if (param_2 != 0xdb) {
    core_getSetSpriteProp(unaff_ESI,param_1,1,iVar2,&local_c);
    return 1;
  }
  uVar3 = core_getSetSpriteProp(unaff_ESI,param_1,1,iVar2,&local_c);
  return uVar3;
}



// ============================================================
// Function: core_createSpriteProps (FUN_6801f0b0)
// Address: 6801f0b0
// Size: 115 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * core_createSpriteProps(int param_1)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int *piVar5;
  
  piVar2 = (int *)cast_allocHandle(0x14,1);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  uVar3 = score_dispatchProplist(param_1);
  piVar4 = core_allocSpriteMember(param_1,0,0);
  piVar5 = core_allocSpriteMemberRef(param_1,0,0);
  *(int *)(*piVar2 + 4) = *(int *)(*piVar2 + 4) + 1;
  puVar1 = (undefined4 *)*piVar2;
  puVar1[1] = 1;
  *puVar1 = &PTR_LAB_6818b8f8;
  puVar1[2] = uVar3;
  puVar1[3] = piVar4;
  puVar1[4] = piVar5;
  core_syncSpritePropsData(param_1,piVar2);
  return piVar2;
}



// ============================================================
// Function: core_newSpriteMember (FUN_6801f130)
// Address: 6801f130
// Size: 119 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_newSpriteMember(undefined4 *param_1)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  undefined3 uStack_7;
  int _local_8; /* FIXUP: undeclared identifier */

  piVar1 = *(int **)(*in_EAX + 0xc);
  _local_8 = CONCAT31(uStack_7,*(undefined1 *)(*in_EAX + 0x10));
  iVar2 = props_getInt(unaff_EDI);
  if (iVar2 != 1) {
    return 0x80040001;
  }
  piVar3 = core_allocSpriteMember(unaff_EDI,(char)_local_8,0);
  if (piVar3 == (int *)0x0) {
    props_setError(unaff_EDI,2);
    return 0;
  }
  score_resolveProplist(unaff_EDI,piVar1,&local_10);
  *(undefined4 *)(*piVar3 + 0xc) = local_c;
  param_1[1] = piVar3;
  *param_1 = 3;
  return 0;
}



// ============================================================
// Function: core_dispatchSpriteMemberOp (FUN_6801f1b0)
// Address: 6801f1b0
// Size: 139 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchSpriteMemberOp(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c [2];
  
  core_setSpriteMemberData(param_1,param_2);
  switch(param_3) {
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
    goto switchD_6801f1da_caseD_cd;
  default:
    uVar2 = score_dispatchProplistOp(param_1,*(undefined4 *)(*param_2 + 0xc),param_3);
    return uVar2;
  case 0xda:
    uVar2 = core_getMemberPropByIndex(param_2);
    return uVar2;
  case 0xdb:
  case 0xdc:
    uVar2 = core_getMemberPropByKey(param_2,param_3);
    return uVar2;
  case 0xe4:
    iVar1 = core_newSpriteMember(local_c);
    if (iVar1 == 0) {
      props_popArgs(param_1,local_c);
    }
switchD_6801f1da_caseD_cd:
    return 1;
  }
}



// ============================================================
// Function: core_newSpriteMemberRef (FUN_6801f270)
// Address: 6801f270
// Size: 119 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_newSpriteMemberRef(undefined4 *param_1)

{
  int *piVar1;
  int *in_EAX;
  int iVar2;
  int *piVar3;
  int unaff_EDI;
  undefined4 local_10;
  undefined4 local_c;
  undefined1 local_8;
  undefined3 uStack_7;
  int _local_8; /* FIXUP: undeclared identifier */

  piVar1 = *(int **)(*in_EAX + 0xc);
  _local_8 = CONCAT31(uStack_7,*(undefined1 *)(*in_EAX + 0x14));
  iVar2 = props_getInt(unaff_EDI);
  if (iVar2 != 1) {
    return 0x80040001;
  }
  piVar3 = core_allocSpriteMemberRef(unaff_EDI,(char)_local_8,0);
  if (piVar3 == (int *)0x0) {
    props_setError(unaff_EDI,2);
    return 0;
  }
  score_resolveProplist(unaff_EDI,piVar1,&local_10);
  *(undefined4 *)(*piVar3 + 0xc) = local_c;
  param_1[1] = piVar3;
  *param_1 = 3;
  return 0;
}



// ============================================================
// Function: core_dispatchMemberRefOp (FUN_6801f2f0)
// Address: 6801f2f0
// Size: 139 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchMemberRefOp(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c [2];
  
  core_getSpriteMemberData(param_1,param_2);
  switch(param_3) {
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
    goto switchD_6801f31a_caseD_cd;
  default:
    uVar2 = score_dispatchProplistOp(param_1,*(undefined4 *)(*param_2 + 0xc),param_3);
    return uVar2;
  case 0xda:
    uVar2 = core_getMemberRefPropByIndex(param_2);
    return uVar2;
  case 0xdb:
  case 0xdc:
    uVar2 = core_getMemberRefPropByKey(param_2,param_3);
    return uVar2;
  case 0xe4:
    iVar1 = core_newSpriteMemberRef(local_c);
    if (iVar1 == 0) {
      props_popArgs(param_1,local_c);
    }
switchD_6801f31a_caseD_cd:
    return 1;
  }
}



// ============================================================
// Function: core_cloneSpriteProps (FUN_6801f3b0)
// Address: 6801f3b0
// Size: 182 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall core_cloneSpriteProps(int param_1)

{
  undefined4 *puVar1;
  int *in_EAX;
  int iVar2;
  int *piVar3;
  undefined4 *unaff_EBX;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  iVar2 = *in_EAX;
  local_c = *(undefined4 *)(iVar2 + 0xc);
  local_8 = *(int **)(iVar2 + 8);
  local_14 = *(undefined4 *)(iVar2 + 0x10);
  iVar2 = props_getInt(param_1);
  if (iVar2 != 1) {
    return 0x80040001;
  }
  piVar3 = (int *)cast_allocHandle(0x14,1);
  if (piVar3 == (int *)0x0) {
    props_setError(param_1,2);
    return 0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  score_resolveProplist(param_1,local_8,&local_20);
  core_newSpriteMember(&local_10);
  core_newSpriteMemberRef(&local_18);
  *(int *)(*piVar3 + 4) = *(int *)(*piVar3 + 4) + 1;
  puVar1 = (undefined4 *)*piVar3;
  puVar1[1] = 1;
  *puVar1 = &PTR_LAB_6818b8f8;
  puVar1[2] = local_1c;
  puVar1[3] = local_c;
  puVar1[4] = local_14;
  unaff_EBX[1] = piVar3;
  *unaff_EBX = 3;
  return 0;
}



// ============================================================
// Function: core_dispatchSpritePropsOp (FUN_6801f470)
// Address: 6801f470
// Size: 144 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_dispatchSpritePropsOp(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c [2];
  
  switch(param_3) {
  case 0xcd:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd2:
    goto switchD_6801f48c_caseD_cd;
  default:
    uVar2 = score_dispatchProplistOp(param_1,*(undefined4 *)(*param_2 + 8),param_3);
    return uVar2;
  case 0xda:
    uVar2 = core_getSpritePropByIndex(param_2);
    return uVar2;
  case 0xdb:
  case 0xdc:
    uVar2 = core_getSpritePropByKey(param_2,param_3);
    return uVar2;
  case 0xe4:
    iVar1 = core_cloneSpriteProps(param_1);
    if (iVar1 == 0) {
      props_popArgs(param_1,local_c);
    }
switchD_6801f48c_caseD_cd:
    return 1;
  }
}



// ============================================================
// Function: core_lookupSpritePropSymbol (FUN_6801f530)
// Address: 6801f530
// Size: 47 bytes
// Params: undefined4 * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint core_lookupSpritePropSymbol(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  
  piVar1 = *(int **)(**(int **)(unaff_ESI + 8) + 0x438);
  uVar2 = *(uint *)(*piVar1 + 0x10);
  stage_lookupSymbolId(piVar1,param_1);
  iVar3 = stage_emitPushIfNeeded(unaff_ESI);
  return -(uint)(iVar3 != 0) & uVar2;
}



// ============================================================
// Function: core_resolveSpritePropDefault (FUN_6801f560)
// Address: 6801f560
// Size: 29 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resolveSpritePropDefault(void)
{
  undefined4 local_c [2];

  local_c[0] = 0;
  core_lookupSpritePropSymbol(local_c);
  return 0;
}


