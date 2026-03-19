// Module: score
// Topic: Xtra dispatch, lifecycle, and callbacks
// Address range: 0x68045940 - 0x680465f0
// Functions (20):
//   score_processTimerProperties
//   score_removeInactiveTimers
//   score_createXtraInstance
//   score_prepareDateCallback
//   score_invokeXtraCallback
//   score_sendXtraMethod
//   score_setXtraProperty
//   score_buildCastArgs
//   score_dispatchXtraCastCall
//   score_freeXtraHandle
//   score_formatXtraName
//   score_dispatchCastProperty
//   score_allocXtraObject
//   score_createXtraRef
//   score_extractXtraObject
//   score_dispatchXtraCall
//   score_formatColorHex
//   score_dispatchColorMethod
//   score_formatXtraLabel
//   score_accessColorProperty

// ============================================================
// Function: score_processTimerProperties (FUN_68045940)
// Address: 68045940
// Size: 164 bytes
// Params: undefined4 param_1, int * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_processTimerProperties(undefined4 param_1,int *param_2,uint param_3)
{
  int iVar1;
  int iVar2;
  uint local_1c;
  undefined4 local_18;
  uint local_14;
  int *local_10;
  uint local_c;
  int *local_8;
  
  *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
  iVar1 = props_getListLength(param_1,param_2);
  while (((iVar1 = iVar1 + -1, -1 < iVar1 && (iVar2 = props_getListLength(param_1,param_2), iVar1 < iVar2))
         && (1 < *(int *)(*param_2 + 4)))) {
    props_getListEntry(param_1,param_2,iVar1,&local_c);
    iVar2 = score_isTimerObject();
    if ((iVar2 != 0) && (iVar2 = *local_8, *(int *)(iVar2 + 0x20) == 3)) {
      local_1c = *(uint *)(iVar2 + 0x20);
      local_18 = *(undefined4 *)(iVar2 + 0x24);
      local_10 = local_8;
      local_14 = local_c;
      score_getPropertyPair(param_1,param_3 | 0x80000000,2,&local_1c,(int *)0x0);
    }
    props_releaseValue(param_1,(byte)local_c,local_8);
  }
  props_releaseObject(param_1,param_2);
  return 0;
}


// ============================================================
// Function: score_removeInactiveTimers (FUN_680459f0)
// Address: 680459f0
// Size: 127 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_removeInactiveTimers(undefined4 param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  uint local_c;
  int *local_8;
  
  *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
  iVar1 = props_getListLength(param_1,param_2);
  while (((iVar1 = iVar1 + -1, -1 < iVar1 && (iVar2 = props_getListLength(param_1,param_2), iVar1 < iVar2))
         && (1 < *(int *)(*param_2 + 4)))) {
    props_getListEntry(param_1,param_2,iVar1,&local_c);
    iVar2 = score_isTimerObject();
    if ((iVar2 != 0) && (*(int *)(*local_8 + 0x2c) == 0)) {
      props_setListRange(param_1,param_2,iVar1);
    }
    props_releaseValue(param_1,(byte)local_c,local_8);
  }
  props_releaseObject(param_1,param_2);
  return 0;
}


// ============================================================
// Function: score_createXtraInstance (FUN_68045a70)
// Address: 68045a70
// Size: 82 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_createXtraInstance(undefined4 param_1)

{
  int iVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  iVar1 = props_getInt(unaff_EDI);
  if (iVar1 != 1) {
    return 0x80040001;
  }
  *unaff_ESI = 3;
  iVar1 = Ordinal_1120(param_1,0);
  unaff_ESI[1] = iVar1;
  if (iVar1 == 0) {
    *unaff_ESI = 2;
    props_setError(unaff_EDI,2);
    return 0x80040002;
  }
  *(int *)(unaff_EDI + 0xfc) = *(int *)(unaff_EDI + 0xfc) + 1;
  return 0;
}


// ============================================================
// Function: score_prepareDateCallback (FUN_68045ad0)
// Address: 68045ad0
// Size: 220 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_prepareDateCallback(undefined4 param_1)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  undefined4 local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_30[0] = param_1;
  local_1c = 0;
  iVar2 = props_getInt(unaff_ESI);
  if (iVar2 < 3) {
    props_setError(unaff_ESI,0x17);
    return 0;
  }
  puVar3 = (undefined4 *)
           (**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
           *(int *)(unaff_ESI + 0x18));
  local_28 = *puVar3;
  local_24 = puVar3[1];
  local_20 = puVar3[3];
  if (puVar3[2] != 8) {
    props_setError(unaff_ESI,0xb);
    return 0;
  }
  local_18 = puVar3[4];
  local_14 = puVar3[5];
  iVar1 = local_1c + 1;
  if (3 < iVar2) {
    local_10 = puVar3[6];
    local_c = puVar3[7];
    iVar1 = local_1c + 2;
  }
  local_1c = iVar1;
  sprites_sendMessage(unaff_ESI,score_dispatchDateCallback,local_30);
  return 0;
}


// ============================================================
// Function: score_invokeXtraCallback (FUN_68045bb0)
// Address: 68045bb0
// Size: 38 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_invokeXtraCallback(undefined4 *param_1)
{
  (**(code **)(*(int *)*param_1 + 0x20))
            ((int *)*param_1,param_1[3],param_1[4],param_1 + 5,param_1 + 1);
  return 0;
}


// ============================================================
// Function: score_sendXtraMethod (FUN_68045be0)
// Address: 68045be0
// Size: 233 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_sendXtraMethod(undefined4 param_1)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int unaff_ESI;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_2c = param_1;
  local_1c = 0;
  iVar2 = props_getInt(unaff_ESI);
  if (iVar2 < 3) {
    props_setError(unaff_ESI,0x16);
    return 0;
  }
  piVar1 = (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
                  *(int *)(unaff_ESI + 0x18));
  local_20 = piVar1[1];
  piVar3 = piVar1 + 2;
  if (*piVar1 != 8) {
    props_setError(unaff_ESI,0xb);
    return 0;
  }
  if (3 < iVar2) {
    local_1c = local_1c + 1;
    local_18 = *piVar3;
    local_14 = piVar1[3];
    piVar3 = piVar1 + 4;
  }
  if (4 < iVar2) {
    local_1c = local_1c + 1;
    local_10 = *piVar3;
    local_c = piVar3[1];
    piVar3 = piVar3 + 2;
  }
  local_28 = *piVar3;
  local_24 = piVar3[1];
  sprites_sendMessage(unaff_ESI,score_invokeXtraCallback,&local_2c);
  return 0;
}


// ============================================================
// Function: score_setXtraProperty (FUN_68045cd0)
// Address: 68045cd0
// Size: 42 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_setXtraProperty(undefined4 *param_1)
{
  *(undefined4 *)param_1[1] = 4;
  (**(code **)(*(int *)*param_1 + 0x18))((int *)*param_1,param_1[2],param_1[1] + 4);
  return 0;
}


// ============================================================
// Function: score_buildCastArgs (FUN_68045d00)
// Address: 68045d00
// Size: 398 bytes
// Params: undefined4 * param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall score_buildCastArgs(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int **ppiVar4;
  int iVar5;
  undefined4 local_6c;
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
  
  local_6c = param_3;
  iVar1 = props_getInt(param_2);
  local_54 = props_getInt(param_2);
  if (local_54 < 9) {
    iVar3 = 1;
    iVar5 = 0;
    local_50 = &local_48;
    if (local_54 < 1) goto LAB_68045e30;
    do {
      _DAT_68197764 =
           (undefined4 *)
           (**(int **)(param_2 + 0x10) + -8 + (iVar3 - *(int *)(param_2 + 0x20)) * 8 +
           *(int *)(param_2 + 0x18));
      piVar2 = DAT_6819776c;
      ppiVar4 = DAT_68197768;
      if (_DAT_68197764 != (undefined4 *)0x0) {
        DAT_6819776c = (int *)0x0;
        DAT_68197768 = (int **)0x0;
        piVar2 = (int *)((int *)(size_t)_DAT_68197764)[1];
        ppiVar4 = (int **)*(int *)(size_t)_DAT_68197764 /* FIXUP(C2100): cast for dereference */;
      }
      (&local_50)[iVar3 * 2] = ppiVar4;
      (&local_4c)[iVar3 * 2] = (int)piVar2;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= local_54);
    iVar5 = 0;
  }
  else {
    iVar5 = cast_allocHandle(local_54 * 8,0);
    local_4c = iVar5;
    if (iVar5 == 0) goto LAB_68045e1b;
    local_50 = (int **)Ordinal_1114(iVar5);
    iVar3 = 1;
    if (0 < local_54) {
      do {
        _DAT_68197764 =
             (undefined4 *)
             (**(int **)(param_2 + 0x10) + -8 + (iVar3 - *(int *)(param_2 + 0x20)) * 8 +
             *(int *)(param_2 + 0x18));
        piVar2 = DAT_6819776c;
        ppiVar4 = DAT_68197768;
        if (_DAT_68197764 != (undefined4 *)0x0) {
          DAT_6819776c = (int *)0x0;
          DAT_68197768 = (int **)0x0;
          piVar2 = (int *)((int *)(size_t)_DAT_68197764)[1];
          ppiVar4 = (int **)*(int *)(size_t)_DAT_68197764 /* FIXUP(C2100): cast for dereference */;
        }
        local_50[iVar3 * 2 + -2] = (int *)ppiVar4;
        local_50[iVar3 * 2 + -1] = piVar2;
        iVar3 = iVar3 + 1;
        iVar5 = local_4c;
      } while (iVar3 <= local_54);
    }
  }
  if (local_50 != (int **)0x0) {
LAB_68045e30:
    local_68 = 0;
    local_64 = 0;
    local_60 = param_4;
    local_5c = 2;
    local_58 = 0;
    local_54 = iVar1;
    iVar1 = sprites_sendMessage(param_2,score_dispatchCastAction,&local_6c);
    if (iVar1 == 0) {
      *param_1 = local_5c;
      param_1[1] = local_58;
    }
    if (iVar5 != 0) {
      cast_freeHandle(iVar5);
    }
    return 0;
  }
LAB_68045e1b:
  return 0;
}


// ============================================================
// Function: score_dispatchXtraCastCall (FUN_68045e90)
// Address: 68045e90
// Size: 558 bytes
// Params: uint param_1, int * param_2, undefined4 param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool score_dispatchXtraCastCall(uint param_1,int *param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint local_18;
  int *local_14;
  int local_10;
  int *local_c;
  uint *local_8;
  
  puVar1 = *(undefined4 **)(*param_2 + 8);
  local_8 = (uint *)0x0;
  local_10 = 0;
  local_c = (int *)0x0;
  local_18 = 0;
  local_14 = (int *)0x0;
  switch(param_3) {
  case 0x57:
    break;
  default:
    iVar4 = score_buildCastArgs(&local_18,param_1,puVar1,param_3);
    if (iVar4 != 0) {
      return false;
    }
    local_8 = &local_18;
    goto LAB_68045f8c;
  case 0x5b:
    break;
  case 0x5c:
  case 0xca:
    break;
  case 0x5d:
  case 0xce:
    break;
  case 0x81:
    local_18 = 0;
    local_14 = (int *)0x0;
    iVar4 = score_prepareDateCallback(puVar1);
    if (iVar4 == 0) {
      if (local_18 == 0) {
        local_18 = 3;
        local_14 = param_2;
        props_retainValue(param_1,&local_18);
      }
      local_8 = &local_18;
      props_popArgs(param_1,local_8);
      return true;
    }
    goto LAB_68045ff0;
  case 0xd4:
  case 0xd5:
    iVar4 = score_sendSetCastProperty(puVar1);
    if (iVar4 == 0) {
      local_8 = &local_18;
      goto LAB_68045f8c;
    }
    goto LAB_68045ff0;
  case 0xdb:
  case 0xdc:
    iVar4 = score_sendXtraMethod(puVar1);
    if (iVar4 == -0x7ffbf82a) {
      iVar3 = 0x39;
LAB_68045fea:
      props_setError(param_1,iVar3);
      goto LAB_68045ff0;
    }
    if (iVar4 == -0x7ffbf82b) {
      iVar3 = 0x37;
      goto LAB_68045fea;
    }
    goto LAB_68045f88;
  case 0xdd:
    iVar4 = score_sendCastQuery();
    if (iVar4 == 0) {
      local_8 = &local_18;
      goto LAB_68045f8c;
    }
    goto LAB_68045ff0;
  case 0xe3:
    score_resolveType(param_1);
    return true;
  case 0xea:
    iVar4 = score_sendDateEvent(param_1,&local_18);
    if (iVar4 == 0) {
      local_8 = &local_18;
      props_popArgs(param_1,local_8);
      return true;
    }
    goto LAB_68045ff0;
  }
  iVar4 = score_sendCastMethod();
LAB_68045f88:
  if (iVar4 == 0) {
LAB_68045f8c:
    props_popArgs(param_1,local_8);
    return true;
  }
LAB_68045ff0:
  uVar2 = props_resolvePropertyId(param_1,"is3dCastMember");
  (**(code **)*puVar1)(puVar1,&DAT_68176108,&local_c);
  if (local_c != (int *)0x0) {
    iVar3 = (**(code **)(*local_c + 0x14))(local_c,uVar2,0,0,0);
    if (iVar3 == 0) {
      local_10 = 1;
    }
    (**(code **)(*local_c + 8))(local_c);
    if (local_10 != 0) {
      props_mapErrorCode(param_1,iVar4,param_3);
    }
  }
  return iVar4 == 0;
}


// ============================================================
// Function: score_freeXtraHandle (FUN_68046180)
// Address: 68046180
// Size: 44 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_freeXtraHandle(int param_1,int *param_2)
{
  int *piVar1;
  
  piVar1 = *(int **)(*param_2 + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}


// ============================================================
// Function: score_formatXtraName (FUN_680461b0)
// Address: 680461b0
// Size: 59 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatXtraName(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x3a);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}


// ============================================================
// Function: score_dispatchCastProperty (FUN_680461f0)
// Address: 680461f0
// Size: 242 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispatchCastProperty(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 *param_5)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  code *pcVar5;
  undefined4 **ppuVar6;
  int *local_34;
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 local_28;
  int *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_8;
  
  local_34 = (int *)0x0;
  puVar1 = *(undefined4 **)(*param_2 + 8);
  local_1c = 0;
  if (param_3 == 0) {
    ppuVar6 = &local_30;
    local_2c = param_5;
    local_28 = 3;
    local_24 = param_2;
    pcVar5 = score_setCastProperty;
    local_30 = puVar1;
  }
  else {
    local_28 = *param_5;
    local_24 = (int *)param_5[1];
    ppuVar6 = &local_2c;
    pcVar5 = score_invokeXtraCallback;
    local_2c = puVar1;
  }
  local_20 = param_4;
  iVar2 = sprites_sendMessage(param_1,pcVar5,ppuVar6);
  if (iVar2 != 0) {
    uVar3 = props_resolvePropertyId(param_1,"is3dCastMember");
    (**(code **)*puVar1)(puVar1,&DAT_68176108,&local_34);
    if (local_34 != (int *)0x0) {
      iVar4 = (**(code **)(*local_34 + 0x14))(local_34,uVar3,0,0,0);
      (**(code **)(*local_34 + 8))(local_34);
      if (iVar4 == 0) {
        props_mapErrorCode(param_1,iVar2,param_4);
      }
    }
  }
  return 0;
}


// ============================================================
// Function: score_allocXtraObject (FUN_680462f0)
// Address: 680462f0
// Size: 54 bytes
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * score_allocXtraObject(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int *unaff_EBX;
  int unaff_ESI;
  
  piVar2 = (int *)cast_allocHandle(0xc,1);
  if (piVar2 == (int *)0x0) {
    (**(code **)(*unaff_EBX + 8))();
    return (int *)0x0;
  }
  *(int *)(unaff_ESI + 0xfc) = *(int *)(unaff_ESI + 0xfc) + 1;
  *(int *)(*piVar2 + 4) = *(int *)(*piVar2 + 4) + 1;
  puVar1 = (undefined4 *)*piVar2;
  *puVar1 = &PTR_LAB_6818d5d0;
  puVar1[1] = 1;
  puVar1[2] = unaff_EBX;
  return piVar2;
}


// ============================================================
// Function: score_createXtraRef (FUN_68046330)
// Address: 68046330
// Size: 38 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_createXtraRef(undefined4 param_1,undefined4 param_2,undefined4 *param_3)
{
  int *piVar1;
  
  piVar1 = score_allocXtraObject();
  param_3[1] = piVar1;
  if (piVar1 != (int *)0x0) {
    *param_3 = 3;
  }
  return 0;
}


// ============================================================
// Function: score_extractXtraObject (FUN_68046360)
// Address: 68046360
// Size: 47 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_extractXtraObject(undefined4 param_1,int *param_2,int *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d5d0)) {
    *param_3 = (*(int **)param_2[1])[2];
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_dispatchXtraCall (FUN_68046390)
// Address: 68046390
// Size: 148 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_dispatchXtraCall(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  
  piVar4 = score_allocXtraObject();
  if (piVar4 == (int *)0x0) {
    return 0;
  }
  puVar6 = (undefined4 *)
           (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18));
  uVar1 = *puVar6;
  piVar2 = (int *)puVar6[1];
  *puVar6 = 3;
  puVar6[1] = piVar4;
  iVar5 = (**(code **)(*(int *)*piVar4 + 4))(param_1,piVar4,param_3);
  if (iVar5 != 0) {
    props_releaseValue(param_1,(byte)uVar1,piVar2);
    return iVar5;
  }
  puVar6 = (undefined4 *)
           (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18));
  piVar4 = (int *)puVar6[1];
  uVar3 = *puVar6;
  *puVar6 = uVar1;
  puVar6[1] = piVar2;
  props_releaseValue(param_1,(byte)uVar3,piVar4);
  return 0;
}


// ============================================================
// Function: score_formatColorHex (FUN_68046430)
// Address: 68046430
// Size: 110 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatColorHex(int *param_1)
{
  int unaff_ESI;
  undefined4 *unaff_EDI;
  uint local_18;
  char local_14 [12];
  uint local_8;
  
  local_18 = *(uint *)(*param_1 + 8);
  if ((char)(local_18 >> 0x18) != '\x01') {
    events_manageCastMember(unaff_ESI,(undefined2 *)&local_18,1);
  }
  sprintf(local_14,"#%02X%02X%02X",local_18 & 0xff,local_18 >> 8 & 0xff,local_18 >> 0x10 & 0xff);
  props_loadStringValue(unaff_ESI,local_14,unaff_EDI);
  return 0;
}


// ============================================================
// Function: score_dispatchColorMethod (FUN_680464a0)
// Address: 680464a0
// Size: 150 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool score_dispatchColorMethod(uint param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 local_10 [2];
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  if (param_3 == 0xe3) {
    score_resolveType(param_1);
    return true;
  }
  if (param_3 == 0xe4) {
    iVar1 = score_createXtraInstance(param_2);
    if (iVar1 == 0) {
      local_8 = local_10;
    }
  }
  else {
    if (param_3 != 0xec) {
      return false;
    }
    iVar1 = score_formatColorHex(param_2);
    if (iVar1 == 0) {
      local_8 = local_10;
    }
  }
  props_popArgs(param_1,local_8);
  return iVar1 == 0;
}


// ============================================================
// Function: score_formatXtraLabel (FUN_68046540)
// Address: 68046540
// Size: 163 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatXtraLabel(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0xe0) == 0) {
    iVar1 = 0x3c;
    iVar2 = 0x3d;
  }
  else {
    iVar1 = 0x49;
    iVar2 = 0x4a;
  }
  if ((char)((uint)*(undefined4 *)(*param_2 + 8) >> 0x18) == '\0') {
    cast_loadPascalString(&DAT_68197780,0x898,iVar1);
    props_formatString(param_1,param_3,param_4,&DAT_68197781);
    return 0;
  }
  cast_loadPascalString(&DAT_68197780,0x898,iVar2);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}


// ============================================================
// Function: score_accessColorProperty (FUN_680465f0)
// Address: 680465f0
// Size: 664 bytes
// Params: uint param_1, int * param_2, int param_3, uint param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_accessColorProperty(uint param_1,int *param_2,int param_3,uint param_4,int *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  uVar2 = param_4;
  uVar1 = param_1;
  iVar3 = *param_2;
  puVar5 = (uint *)(iVar3 + 8);
  if (param_3 == 0) {
    switch(param_4) {
    case 0xc0:
      param_4 = *puVar5;
      if ((char)(param_4 >> 0x18) != '\0') {
        events_manageCastMember(param_1,(undefined2 *)&param_4,0);
      }
      *param_5 = 4;
      param_5[1] = param_4 & 0xff;
      return 1;
    default:
      return 0;
    case 0xed:
      *param_5 = 8;
      param_5[1] = (*(char *)(iVar3 + 0xb) != '\x01') + 0xbf;
      return 1;
    case 0xee:
    case 0xef:
    case 0xf0:
      goto switchD_680467ad_caseD_ee;
    }
  }
  switch(param_4) {
  case 0xc0:
    iVar4 = props_requireInt(param_1,param_5,(int *)&param_1);
    if (iVar4 == 0) {
      return 0;
    }
    *(undefined1 *)(iVar3 + 0xb) = 0;
    param_1 = param_1 & 0xff;
    break;
  default:
    return 0;
  case 0xed:
    iVar3 = props_requireSymbolId(param_1,param_5,(int *)&param_2);
    if (iVar3 == 0) {
      return 0;
    }
    if ((param_2 != (int *)0xbf) && (param_2 != (int *)0xc0)) {
      props_setErrorAndReturn(uVar1,0x3d);
      return 1;
    }
    events_manageCastMember(uVar1,(undefined2 *)puVar5,(uint)(param_2 == (int *)0xbf));
    return 1;
  case 0xee:
  case 0xef:
  case 0xf0:
    iVar4 = props_requireInt(param_1,param_5,(int *)&param_1);
    if (iVar4 == 0) {
      return 0;
    }
    if (*(char *)(iVar3 + 0xb) != '\x01') {
      events_manageCastMember(uVar1,(undefined2 *)puVar5,1);
    }
    if (uVar2 != 0xee) {
      if (uVar2 == 0xef) {
        if (-1 < (int)param_1) {
          if (0xff < (int)param_1) {
            param_1 = 0xff;
          }
          *(char *)(iVar3 + 9) = (char)param_1;
          return 1;
        }
        *(undefined1 *)(iVar3 + 9) = 0;
        return 1;
      }
      if (uVar2 != 0xf0) {
        return 1;
      }
      if (-1 < (int)param_1) {
        if (0xff < (int)param_1) {
          param_1 = 0xff;
        }
        *(char *)(iVar3 + 10) = (char)param_1;
        return 1;
      }
      *(undefined1 *)(iVar3 + 10) = 0;
      return 1;
    }
    if ((int)param_1 < 0) {
      *(undefined1 *)puVar5 = 0;
      return 1;
    }
    if (0xff < (int)param_1) {
      *(undefined1 *)puVar5 = 0xff;
      return 1;
    }
  }
  *(char *)puVar5 = (char)param_1;
  return 1;
switchD_680467ad_caseD_ee:
  param_4 = *puVar5;
  if ((char)(param_4 >> 0x18) != '\x01') {
    events_manageCastMember(param_1,(undefined2 *)&param_4,1);
  }
  *param_5 = 4;
  if (uVar2 == 0xee) {
    param_5[1] = param_4 & 0xff;
  }
  else {
    if (uVar2 == 0xef) {
      param_5[1] = param_4 >> 8 & 0xff;
      return 1;
    }
    if (uVar2 == 0xf0) {
      param_5[1] = param_4 >> 0x10 & 0xff;
      return 1;
    }
  }
  return 1;
}


