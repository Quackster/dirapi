// Module: core
// Topic: Sprite member objects - cast member wrappers, property sync, destroy/create
// Address range: 0x6801D7A0 - 0x6801E1D0
// Functions (13):
//   core_destroySpriteMember (0x6801D7A0)
//   core_setSpriteMemberData (0x6801D7E0)
//   core_formatSpriteMemberString (0x6801D9E0)
//   core_returnZeroStub (0x6801DA10)
//   core_getSetMemberProp (0x6801DA20)
//   core_getMemberPropByIndex (0x6801DCC0)
//   core_getMemberPropByKey (0x6801DDE0)
//   core_allocSpriteMember (0x6801DED0)
//   core_isSpriteMember (0x6801DF30)
//   core_destroySpriteMemberRef (0x6801DF60)
//   core_getSpriteMemberData (0x6801DFA0)
//   core_formatMemberRefString (0x6801E1A0)
//   core_getSetMemberRefProp (0x6801E1D0)

// ============================================================
// Function: core_destroySpriteMember (FUN_6801d7a0)
// Address: 6801d7a0
// Size: 59 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_destroySpriteMember(int param_1,int *param_2)
{
  if (*(int **)(*param_2 + 8) != (int *)0x0) {
    *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = 0;
  }
  score_freeProplist(param_1,*(int **)(*param_2 + 0xc));
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}



// ============================================================
// Function: core_setSpriteMemberData (FUN_6801d7e0)
// Address: 6801d7e0
// Size: 497 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_setSpriteMemberData(int param_1,int *param_2)
{
  char cVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined4 uVar5;
  uint local_18 [4];
  undefined4 local_8;
  
  local_8 = 0;
  iVar2 = *param_2;
  cVar1 = *(char *)(iVar2 + 0x10);
  iVar3 = *(int *)(iVar2 + 0xc);
  local_18[0] = 8;
  if (iVar3 != 0) {
    if (cVar1 == '\0') {
      events_getScoreLoopStart(param_1,&local_8);
    }
    else {
      if (*(int **)(iVar2 + 8) == (int *)0x0) {
        return 0;
      }
      param_2 = *(int **)(**(int **)(iVar2 + 8) + 8);
      events_setWindowMessageData(param_1,param_2,&local_8);
    }
    core_getFieldValue(param_1,&local_8,local_18 + 2);
    local_18[1] = 0x21c;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
    if (cVar1 == '\0') {
      uVar5 = events_editChannel(param_1,0x40);
    }
    else {
      bVar4 = events_checkPermission(param_1,param_2,0x40);
      uVar5 = CONCAT31(extraout_var,bVar4);
    }
    props_storeIntValue(param_1,uVar5,local_18 + 2);
    local_18[1] = 0x150;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
    if (cVar1 == '\0') {
      uVar5 = events_editChannel(param_1,8);
    }
    else {
      bVar4 = events_checkPermission(param_1,param_2,8);
      uVar5 = CONCAT31(extraout_var_00,bVar4);
    }
    props_storeIntValue(param_1,uVar5,local_18 + 2);
    local_18[1] = 0x21d;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
    if (cVar1 == '\0') {
      uVar5 = events_editChannel(param_1,0x20);
    }
    else {
      bVar4 = events_checkPermission(param_1,param_2,0x20);
      uVar5 = CONCAT31(extraout_var_01,bVar4);
    }
    props_storeIntValue(param_1,uVar5,local_18 + 2);
    local_18[1] = 0x21f;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
    if (cVar1 == '\0') {
      uVar5 = events_editChannel(param_1,0x10);
    }
    else {
      bVar4 = events_checkPermission(param_1,param_2,0x10);
      uVar5 = CONCAT31(extraout_var_02,bVar4);
    }
    props_storeIntValue(param_1,uVar5,local_18 + 2);
    local_18[1] = 0x21e;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
    if (cVar1 == '\0') {
      uVar5 = events_editChannel(param_1,0x400);
    }
    else {
      bVar4 = events_checkPermission(param_1,param_2,0x400);
      uVar5 = CONCAT31(extraout_var_03,bVar4);
    }
    props_storeIntValue(param_1,uVar5,local_18 + 2);
    local_18[1] = 0x220;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
  }
  return 0;
}



// ============================================================
// Function: core_formatSpriteMemberString (FUN_6801d9e0)
// Address: 6801d9e0
// Size: 44 bytes
// Params: int param_1, int * param_2, undefined * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_formatSpriteMemberString(int param_1,int *param_2,undefined *param_3,undefined4 param_4)
{
  core_setSpriteMemberData(param_1,param_2);
  score_formatProplistString(param_1,*(int **)(*param_2 + 0xc),param_3,param_4);
  return 0;
}



// ============================================================
// Function: core_returnZeroStub (FUN_6801da10)
// Address: 6801da10
// Size: 5 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_returnZeroStub(void)

{
  return 0;
}



// ============================================================
// Function: core_getSetMemberProp (FUN_6801da20)
// Address: 6801da20
// Size: 429 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getSetMemberProp(int param_1,int *param_2,int param_3,undefined4 param_4,int *param_5)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  uint uVar4;
  int *piVar5;
  
  cVar1 = *(char *)(*param_2 + 0x10);
  piVar5 = (int *)0x0;
  if (cVar1 != '\0') {
    iVar3 = **(int **)(*param_2 + 8);
    if (iVar3 == 0) {
      return 1;
    }
    piVar5 = *(int **)(iVar3 + 8);
  }
  switch(param_4) {
  case 0x150:
    uVar4 = 0x40;
    break;
  default:
    return 0;
  case 0x21c:
    param_2 = (int *)0x0;
    if (param_3 == 0) {
      if (cVar1 == '\0') {
        events_getScoreLoopStart(param_1,&param_2);
        core_getFieldValue(param_1,&param_2,param_5);
        return 1;
      }
      events_setWindowMessageData(param_1,piVar5,&param_2);
      core_getFieldValue(param_1,&param_2,param_5);
      return 1;
    }
    iVar3 = core_setFieldValue(param_1,param_5,(int *)&param_2);
    if (iVar3 == 0) {
      return 1;
    }
    if (cVar1 == '\0') {
      events_getScoreLoopEnd(param_1,&param_2);
      return 1;
    }
    events_setMiawRect(param_1,piVar5,&param_2);
    return 1;
  case 0x21d:
    uVar4 = 8;
    break;
  case 0x21e:
    uVar4 = 0x10;
    break;
  case 0x21f:
    uVar4 = 0x20;
    break;
  case 0x220:
    uVar4 = 0x400;
  }
  if (param_3 == 0) {
    *param_5 = 4;
    if (cVar1 != '\0') {
      bVar2 = events_checkPermission(param_1,piVar5,uVar4);
      param_5[1] = CONCAT31(extraout_var,bVar2);
      return 1;
    }
    iVar3 = events_editChannel(param_1,uVar4);
    param_5[1] = iVar3;
  }
  else {
    iVar3 = props_requireInt(param_1,param_5,&param_3);
    if (iVar3 != 0) {
      if (cVar1 == '\0') {
        events_editChannelData(param_1,uVar4,param_3);
        return 1;
      }
      events_processWindowEvent(param_1,piVar5,uVar4,param_3);
      return 1;
    }
  }
  return 1;
}



// ============================================================
// Function: core_getMemberPropByIndex (FUN_6801dcc0)
// Address: 6801dcc0
// Size: 283 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_getMemberPropByIndex(int *param_1)

{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 local_20 [2];
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = *(int **)(*param_1 + 0xc);
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
    core_getSetMemberProp(unaff_ESI,param_1,1,local_14,&local_10);
  }
  return 1;
}



// ============================================================
// Function: core_getMemberPropByKey (FUN_6801dde0)
// Address: 6801dde0
// Size: 228 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 core_getMemberPropByKey(int *param_1,int param_2)

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
    core_getSetMemberProp(unaff_ESI,param_1,1,iVar2,&local_c);
    return 1;
  }
  uVar3 = core_getSetMemberProp(unaff_ESI,param_1,1,iVar2,&local_c);
  return uVar3;
}



// ============================================================
// Function: core_allocSpriteMember (FUN_6801ded0)
// Address: 6801ded0
// Size: 81 bytes
// Params: int param_1, undefined1 param_2, undefined4 param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * core_allocSpriteMember(int param_1,undefined1 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  
  piVar2 = (int *)cast_allocHandle(0x14,1);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  uVar3 = score_dispatchProplist(param_1);
  *(int *)(*piVar2 + 4) = *(int *)(*piVar2 + 4) + 1;
  puVar1 = (undefined4 *)*piVar2;
  puVar1[2] = param_3;
  puVar1[3] = uVar3;
  *puVar1 = &PTR_LAB_6818b858;
  puVar1[1] = 1;
  *(undefined1 *)(puVar1 + 4) = param_2;
  return piVar2;
}



// ============================================================
// Function: core_isSpriteMember (FUN_6801df30)
// Address: 6801df30
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_isSpriteMember(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818b858)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_destroySpriteMemberRef (FUN_6801df60)
// Address: 6801df60
// Size: 59 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_destroySpriteMemberRef(int param_1,int *param_2)
{
  if (*(int **)(*param_2 + 8) != (int *)0x0) {
    *(undefined4 *)(**(int **)(*param_2 + 8) + 0x10) = 0;
  }
  score_freeProplist(param_1,*(int **)(*param_2 + 0xc));
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}



// ============================================================
// Function: core_getSpriteMemberData (FUN_6801dfa0)
// Address: 6801dfa0
// Size: 510 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getSpriteMemberData(int param_1,int *param_2)
{
  char cVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int *piVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 uVar6;
  uint local_18 [4];
  undefined4 local_8;
  
  local_8 = 0;
  iVar2 = *param_2;
  cVar1 = *(char *)(iVar2 + 0x14);
  iVar3 = *(int *)(iVar2 + 0xc);
  local_18[0] = 8;
  if (iVar3 != 0) {
    if (cVar1 == '\0') {
      events_getChannelProp2D(param_1,&local_8);
    }
    else {
      if (*(int **)(iVar2 + 8) == (int *)0x0) {
        return 0;
      }
      param_2 = *(int **)(**(int **)(iVar2 + 8) + 8);
      events_setWindowVisible(param_1,param_2,&local_8);
    }
    core_getFieldValue(param_1,&local_8,local_18 + 2);
    local_18[1] = 0x3a9;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
    if (cVar1 == '\0') {
      piVar5 = (int *)events_getChannelProp2E(param_1);
    }
    else {
      piVar5 = events_getWindowVisible(param_1,param_2);
    }
    props_storeObjectRef(param_1,(int)piVar5,local_18 + 2);
    local_18[1] = 0x26c;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
    if (cVar1 == '\0') {
      uVar6 = events_editChannel(param_1,0x800);
    }
    else {
      bVar4 = events_checkPermission(param_1,param_2,0x800);
      uVar6 = CONCAT31(extraout_var,bVar4);
    }
    props_storeIntValue(param_1,uVar6,local_18 + 2);
    local_18[1] = 0x222;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
    if (cVar1 == '\0') {
      events_getChannelProp2F(param_1,&local_8);
    }
    else {
      events_getWindowTitle(param_1,param_2,&local_8);
    }
    core_getFieldValue(param_1,&local_8,local_18 + 2);
    local_18[1] = 0x61e;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
    if (cVar1 == '\0') {
      uVar6 = events_editChannel(param_1,0x100);
    }
    else {
      bVar4 = events_checkPermission(param_1,param_2,0x100);
      uVar6 = CONCAT31(extraout_var_00,bVar4);
    }
    props_storeIntValue(param_1,uVar6,local_18 + 2);
    local_18[1] = 0x184;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
    if (cVar1 == '\0') {
      uVar6 = events_editChannel(param_1,0x200);
    }
    else {
      bVar4 = events_checkPermission(param_1,param_2,0x200);
      uVar6 = CONCAT31(extraout_var_01,bVar4);
    }
    props_storeIntValue(param_1,uVar6,local_18 + 2);
    local_18[1] = 0x223;
    score_setPropertyValue(param_1,iVar3,local_18,local_18 + 2,1);
    props_releaseAndClear(param_1,(int *)(local_18 + 2));
  }
  return 0;
}



// ============================================================
// Function: core_formatMemberRefString (FUN_6801e1a0)
// Address: 6801e1a0
// Size: 44 bytes
// Params: int param_1, int * param_2, undefined * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_formatMemberRefString(int param_1,int *param_2,undefined *param_3,undefined4 param_4)
{
  core_getSpriteMemberData(param_1,param_2);
  score_formatProplistString(param_1,*(int **)(*param_2 + 0xc),param_3,param_4);
  return 0;
}



// ============================================================
// Function: core_getSetMemberRefProp (FUN_6801e1d0)
// Address: 6801e1d0
// Size: 805 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getSetMemberRefProp(int param_1,int *param_2,int param_3,int param_4,int *param_5)

{
  char cVar1;
  int iVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  undefined3 extraout_var;
  uint uVar6;
  
  iVar2 = param_1;
  iVar4 = *param_2;
  cVar1 = *(char *)(iVar4 + 0x14);
  param_2 = (int *)0x0;
  if (cVar1 != '\0') {
    iVar4 = **(int **)(iVar4 + 8);
    if (iVar4 == 0) {
      return 1;
    }
    param_2 = *(int **)(iVar4 + 8);
  }
  piVar5 = param_2;
  if (param_4 < 0x224) {
    if (param_4 == 0x223) {
      uVar6 = 0x200;
    }
    else if (param_4 == 0x184) {
      uVar6 = 0x100;
    }
    else if (param_4 == 0x220) {
      uVar6 = 0x400;
    }
    else {
      if (param_4 != 0x222) {
        return 0;
      }
      uVar6 = 0x800;
    }
    if (param_3 == 0) {
      *param_5 = 4;
      if (cVar1 != '\0') {
        bVar3 = events_checkPermission(param_1,param_2,uVar6);
        param_5[1] = CONCAT31(extraout_var,bVar3);
        return 1;
      }
      iVar4 = events_editChannel(param_1,uVar6);
      param_5[1] = iVar4;
    }
    else {
      iVar4 = props_requireInt(param_1,param_5,&param_1);
      if (iVar4 != 0) {
        if (cVar1 == '\0') {
          events_editChannelData(iVar2,uVar6,param_1);
          return 1;
        }
        events_processWindowEvent(iVar2,param_2,uVar6,param_1);
        return 1;
      }
    }
  }
  else if (param_4 == 0x26c) {
    if (param_3 == 0) {
      if (cVar1 == '\0') {
        iVar4 = events_getChannelProp2E(param_1);
        param_5[1] = iVar4;
        *param_5 = 8;
        return 1;
      }
      piVar5 = events_getWindowVisible(param_1,param_2);
      param_5[1] = (int)piVar5;
      *param_5 = 8;
      return 1;
    }
    iVar4 = props_requireSymbolId(param_1,param_5,&param_1);
    if (iVar4 != 0) {
      if (cVar1 == '\0') {
        iVar4 = events_setChannelProp2E(iVar2,param_1);
      }
      else {
        iVar4 = events_getMiawDrawRect(iVar2,piVar5,param_1);
      }
      if (iVar4 == 0) {
        props_setErrorAndReturn(iVar2,0x13);
        return 1;
      }
    }
  }
  else if (param_4 == 0x3a9) {
    param_2 = (int *)0x0;
    if (param_3 == 0) {
      if (cVar1 == '\0') {
        events_getChannelProp2D(param_1,&param_2);
        core_getFieldValue(iVar2,&param_2,param_5);
        return 1;
      }
      events_setWindowVisible(param_1,piVar5,&param_2);
      core_getFieldValue(iVar2,&param_2,param_5);
      return 1;
    }
    iVar4 = core_setFieldValue(param_1,param_5,(int *)&param_2);
    if (iVar4 != 0) {
      if (cVar1 == '\0') {
        events_setChannelProp2D(iVar2,&param_2);
        return 1;
      }
      events_setMiawDrawRect(iVar2,piVar5,&param_2);
      return 1;
    }
  }
  else {
    if (param_4 != 0x61e) {
      return 0;
    }
    param_2 = (int *)0x0;
    if (param_3 == 0) {
      if (cVar1 == '\0') {
        events_getChannelProp2F(param_1,&param_2);
        core_getFieldValue(iVar2,&param_2,param_5);
        return 1;
      }
      events_getWindowTitle(param_1,piVar5,&param_2);
      core_getFieldValue(iVar2,&param_2,param_5);
      return 1;
    }
    iVar4 = core_setFieldValue(param_1,param_5,(int *)&param_2);
    if (iVar4 != 0) {
      if (cVar1 == '\0') {
        events_setChannelProp2F(iVar2,&param_2);
        return 1;
      }
      events_getMiawVisible(iVar2,piVar5,&param_2);
      return 1;
    }
  }
  return 1;
}


