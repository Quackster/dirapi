// Module: score
// Topic: Timer and sprite object lifecycle and events
// Address range: 0x68045010 - 0x68045860
// Functions (9):
//   score_getTimerProperty (FUN_68045010)
//   score_disposeTimer (FUN_68045380)
//   score_cloneTimerRefs (FUN_680453e0)
//   score_createTimer (FUN_68045430)
//   score_isTimerObject (FUN_680454e0)
//   score_findOrCreateTimer (FUN_68045500)
//   score_resolveTimer (FUN_68045680)
//   score_handleTimerOp (FUN_68045800)
//   score_fireTimerEvents (FUN_68045860)

// ============================================================
// Function: score_getTimerProperty (FUN_68045010)
// Address: 68045010
// Size: 663 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getTimerProperty(int param_1,int *param_2,int param_3,undefined4 param_4,uint *param_5)

{
  uint *puVar1;
  int iVar2;
  uint local_c;
  uint local_8;
  
  puVar1 = param_5;
  switch(param_4) {
  case 0x84:
    if (param_3 == 0) {
      *param_5 = 4;
      param_5[1] = *(uint *)(*param_2 + 0x1c);
      return 1;
    }
    iVar2 = props_requireInt(param_1,(int *)param_5,(int *)&param_5);
    if (iVar2 != 0) {
      *(uint **)(*param_2 + 0x1c) = param_5;
      return 1;
    }
    break;
  default:
    return 0;
  case 0x103:
    if (param_3 == 0) {
      iVar2 = *param_2;
      *param_5 = *(uint *)(iVar2 + 0x10);
      param_5[1] = *(uint *)(iVar2 + 0x14);
      props_retainValue(param_1,param_5);
      return 1;
    }
    iVar2 = props_validateString(param_1,(int *)param_5);
    if (iVar2 != 0) {
      props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x10),*(int **)(*param_2 + 0x14));
      local_c = *puVar1;
      local_8 = puVar1[1];
      props_retainValue(param_1,&local_c);
      iVar2 = *param_2;
      *(uint *)(iVar2 + 0x10) = local_c;
      *(uint *)(iVar2 + 0x14) = local_8;
      return 1;
    }
    break;
  case 0x11c:
    if (param_3 == 0) {
      *param_5 = 4;
      param_5[1] = *(uint *)(*param_2 + 0x18);
      return 1;
    }
    iVar2 = props_requireInt(param_1,(int *)param_5,(int *)&param_5);
    if (iVar2 != 0) {
      *(uint **)(*param_2 + 0x18) = param_5;
      iVar2 = sprites_getMovieRef(param_1);
      *(int *)(*param_2 + 0x1c) = iVar2 + (int)param_5;
      return 1;
    }
    break;
  case 0x121:
    if (param_3 == 0) {
      *param_5 = 4;
      param_5[1] = *(uint *)(*param_2 + 0x2c);
    }
    else {
      iVar2 = props_requireInt(param_1,(int *)param_5,(int *)&param_5);
      if (iVar2 != 0) {
        *(uint **)(*param_2 + 0x2c) = param_5;
        return 1;
      }
    }
    break;
  case 0x122:
    if (param_3 == 0) {
      *param_5 = 8;
      param_5[1] = *(uint *)(*param_2 + 0x28);
      return 1;
    }
    iVar2 = props_requireSymbolId(param_1,(int *)param_5,(int *)&param_5);
    if (iVar2 != 0) {
      *(uint **)(*param_2 + 0x28) = param_5;
      return 1;
    }
    break;
  case 0x123:
    if (param_3 != 0) {
      props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x20),*(int **)(*param_2 + 0x24));
      local_c = *param_5;
      local_8 = param_5[1];
      props_retainValue(param_1,&local_c);
      iVar2 = *param_2;
      *(uint *)(iVar2 + 0x20) = local_c;
      *(uint *)(iVar2 + 0x24) = local_8;
      return 1;
    }
    iVar2 = *param_2;
    *param_5 = *(uint *)(iVar2 + 0x20);
    param_5[1] = *(uint *)(iVar2 + 0x24);
    props_retainValue(param_1,param_5);
    return 1;
  }
  return 1;
}


// ============================================================
// Function: score_disposeTimer (FUN_68045380)
// Address: 68045380
// Size: 92 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_disposeTimer(undefined4 param_1,int *param_2)
{
  int *piVar1;
  int *piVar2;
  
  *(uint *)(*param_2 + 4) = *(uint *)(*param_2 + 4) | 0x80000000;
  piVar1 = *(int **)(*param_2 + 0x14);
  if ((*(int *)(*param_2 + 0x10) == 3) && (piVar2 = (int *)*piVar1, (piVar2[1] & 0x80000000U) == 0))
  {
    (**(code **)(*piVar2 + 0x34))(param_1,piVar1);
  }
  piVar1 = *(int **)(*param_2 + 0x24);
  if ((*(int *)(*param_2 + 0x20) == 3) && (piVar2 = (int *)*piVar1, (piVar2[1] & 0x80000000U) == 0))
  {
    (**(code **)(*piVar2 + 0x34))(param_1,piVar1);
  }
  return 0;
}


// ============================================================
// Function: score_cloneTimerRefs (FUN_680453e0)
// Address: 680453e0
// Size: 71 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_cloneTimerRefs(undefined4 param_1,int *param_2)
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*param_2 + 0x14);
  if (((byte)*(undefined4 *)(*param_2 + 0x10) & 0x1f) == 3) {
    (**(code **)(*(int *)*puVar1 + 0x3c))(param_1,puVar1);
  }
  puVar1 = *(undefined4 **)(*param_2 + 0x24);
  if (((byte)*(undefined4 *)(*param_2 + 0x20) & 0x1f) == 3) {
    (**(code **)(*(int *)*puVar1 + 0x3c))(param_1,puVar1);
  }
  return 0;
}


// ============================================================
// Function: score_createTimer (FUN_68045430)
// Address: 68045430
// Size: 169 bytes
// Params: uint param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_createTimer(uint param_1,undefined4 param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int in_EAX;
  int *piVar3;
  undefined4 *unaff_EDI;
  
  props_retainValue(in_EAX,&param_1);
  piVar3 = (int *)cast_allocHandle(0x30,0);
  if (piVar3 != (int *)0x0) {
    *(int *)(in_EAX + 0xf8) = *(int *)(in_EAX + 0xf8) + 1;
    puVar1 = (undefined4 *)*piVar3;
    *puVar1 = &PTR_LAB_6818d580;
    puVar1[1] = 1;
    puVar1[4] = param_1;
    puVar1[5] = param_2;
    puVar1[6] = 0;
    puVar1[7] = 0;
    puVar1[8] = 2;
    puVar1[9] = 0;
    puVar1[10] = 0x56;
    puVar1[0xb] = 0;
    iVar2 = **(int **)(in_EAX + 8);
    *(undefined4 *)(*piVar3 + 8) = *(undefined4 *)(**(int **)(iVar2 + 0x564) + 8);
    *(undefined4 *)(*piVar3 + 0xc) = *(undefined4 *)(iVar2 + 0x564);
    *(int **)(**(int **)(**(int **)(iVar2 + 0x564) + 8) + 0xc) = piVar3;
    *(int **)(**(int **)(iVar2 + 0x564) + 8) = piVar3;
    *unaff_EDI = 3;
    unaff_EDI[1] = piVar3;
  }
  return 0;
}


// ============================================================
// Function: score_isTimerObject (FUN_680454e0)
// Address: 680454e0
// Size: 27 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_isTimerObject(void)

{
  int *in_EAX;
  
  if ((*in_EAX == 3) && ((undefined **)**(int **)in_EAX[1] == &PTR_LAB_6818d580)) {
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_findOrCreateTimer (FUN_68045500)
// Address: 68045500
// Size: 384 bytes
// Params: undefined4 param_1, int * param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall score_findOrCreateTimer(uint *param_1,int *param_2,int param_3,uint *param_4)
{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  int iVar5;
  undefined4 unaff_ESI;
  int local_828;
  undefined4 local_824;
  int *local_820;
  uint *local_81c;
  uint *local_818;
  uint local_814;
  uint local_810;
  int *local_80c;
  byte local_808;
  undefined1 local_807 [1023];
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_81c = param_4;
  local_820 = param_2;
  local_818 = param_1;
  props_toPascalString((int *)param_4,&local_808);
  iVar3 = props_getListLength(unaff_ESI,param_2);
  iVar5 = 0;
  if (0 < iVar3) {
    do {
      props_getListEntry(unaff_ESI,local_820,iVar5,&local_810);
      iVar4 = score_isTimerObject();
      if (iVar4 != 0) {
        local_828 = *(int *)(*local_80c + 0x10);
        local_824 = *(undefined4 *)(*local_80c + 0x14);
        props_toPascalString(&local_828,&local_408);
        if (local_808 == 0xff) {
          local_814 = Ordinal_1201(local_807);
        }
        else {
          local_814 = (uint)local_808;
        }
        if (local_408 == 0xff) {
          uVar2 = Ordinal_1201(local_407);
        }
        else {
          uVar2 = (ushort)local_408;
        }
        bVar1 = Ordinal_966(local_407,local_807,(int)(short)uVar2,(int)(short)local_814);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          local_818[1] = (uint)local_80c;
          *local_818 = local_810;
          return 0;
        }
      }
      props_releaseValue(unaff_ESI,(byte)local_810,local_80c);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar3);
  }
  if (param_3 != 0) {
    score_createTimer(*local_81c,local_81c[1]);
  }
  return 0;
}


// ============================================================
// Function: score_resolveTimer (FUN_68045680)
// Address: 68045680
// Size: 302 bytes
// Params: int param_1, int param_2, int param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_resolveTimer(int param_1,int param_2,int param_3,uint *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint local_c;
  uint local_8;
  
  piVar1 = (int *)sprites_getNetMimeType(param_1);
  *param_4 = 2;
  param_4[1] = 0;
  if (piVar1 != (int *)0x0) {
    iVar2 = props_getInt(param_1);
    if (param_3 == 0) {
      if (iVar2 != 1) goto LAB_680456bd;
    }
    else if (iVar2 < 1) {
LAB_680456bd:
      props_setError(param_1,0x19);
      return 0;
    }
    _DAT_68197764 =
         (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                 *(int *)(param_1 + 0x18));
    local_c = DAT_68197768;
    local_8 = DAT_6819776c;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_c = *(int *)(size_t)_DAT_68197764;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
    }
    switch(local_c) {
    case 1:
    case 0x40:
    case 0x43:
      score_findOrCreateTimer(param_4,piVar1,param_2,&local_c);
      break;
    default:
      props_setErrorAndReturn(param_1,10);
      return 0;
    case 4:
      iVar2 = local_8 - 1;
      if ((iVar2 < 0) || (iVar3 = props_getListLength(param_1,piVar1), iVar3 <= iVar2)) {
        props_setErrorAndReturn(param_1,0x3c);
        return 0;
      }
      props_getListEntry(param_1,piVar1,iVar2,param_4);
    }
    if ((param_3 != 0) && (param_4[1] != 0)) {
      score_modifyProplist();
    }
  }
  return 1;
}


// ============================================================
// Function: score_handleTimerOp (FUN_68045800)
// Address: 68045800
// Size: 83 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_handleTimerOp(int param_1)
{
  int iVar1;
  uint local_c [2];
  
  local_c[0] = 2;
  local_c[1] = 0;
  iVar1 = core_createTypedRef(param_1,0x56,local_c);
  if ((iVar1 == 0) &&
     (iVar1 = score_resolveTimer(param_1,(uint)(*(int *)(param_1 + 0xe0) == 0),0,local_c), iVar1 == 0)) {
    return 0;
  }
  props_popArgs(param_1,local_c);
  return 0;
}


// ============================================================
// Function: score_fireTimerEvents (FUN_68045860)
// Address: 68045860
// Size: 213 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_fireTimerEvents(int param_1,int *param_2)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  int *local_10;
  uint local_c;
  int *local_8;
  
  uVar2 = sprites_getMovieRef(param_1);
  *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
  iVar3 = props_getListLength(param_1,param_2);
  while (((iVar3 = iVar3 + -1, -1 < iVar3 && (iVar4 = props_getListLength(param_1,param_2), iVar3 < iVar4))
         && (1 < *(int *)(*param_2 + 4)))) {
    props_getListEntry(param_1,param_2,iVar3,&local_c);
    iVar4 = score_isTimerObject();
    piVar1 = local_8;
    if (((iVar4 != 0) && (iVar4 = *local_8, *(int *)(iVar4 + 0x18) != 0)) &&
       (*(uint *)(iVar4 + 0x1c) <= uVar2)) {
      local_1c = *(uint *)(iVar4 + 0x20);
      local_18 = *(undefined4 *)(iVar4 + 0x24);
      local_10 = local_8;
      local_14 = local_c;
      score_getPropertyPair(param_1,*(uint *)(*local_8 + 0x28) | 0x80000000,2,&local_1c,(int *)0x0);
      *(uint *)(*piVar1 + 0x1c) = *(int *)(*piVar1 + 0x18) + uVar2;
    }
    props_releaseValue(param_1,(byte)local_c,local_8);
  }
  props_releaseObject(param_1,param_2);
  return 0;
}


