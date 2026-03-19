// Module: score
// Topic: Cast member method dispatching and callbacks
// Address range: 0x68047610 - 0x68047c90
// Functions (13):
//   score_dispatchCastMethod (FUN_68047610)
//   score_sendCastMethod (FUN_68047680)
//   score_setCastProperty (FUN_68047710)
//   score_sendSetCastProperty (FUN_68047740)
//   score_sendCastQuery (FUN_68047830)
//   score_invokeCastCallback (FUN_680478a0)
//   score_sendCastCallback (FUN_680478c0)
//   score_dispatchCastAction (FUN_68047910)
//   score_dispatchCastMember (FUN_68047930)
//   score_notifyCastMember (FUN_68047c10)
//   score_releaseCastHandle (FUN_68047c30)
//   score_getCastName (FUN_68047c70)
//   score_formatCastName (FUN_68047c90)

// ============================================================
// Function: score_dispatchCastMethod (FUN_68047610)
// Address: 68047610
// Size: 94 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_dispatchCastMethod(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  switch(param_1[3]) {
  case 1:
    uVar1 = (**(code **)(*(int *)*param_1 + 0x2c))((int *)*param_1,param_1 + 1);
    return uVar1;
  case 2:
    uVar1 = (**(code **)(*(int *)*param_1 + 0x30))((int *)*param_1,param_1 + 1);
    return uVar1;
  case 3:
    uVar1 = (**(code **)(*(int *)*param_1 + 0x34))((int *)*param_1,param_1 + 1);
    return uVar1;
  case 4:
    uVar1 = (**(code **)(*(int *)*param_1 + 0x2c))((int *)*param_1,0);
  }
  return uVar1;
}


// ============================================================
// Function: score_sendCastMethod (FUN_68047680)
// Address: 68047680
// Size: 143 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_sendCastMethod(void)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined1 local_14 [4];
  undefined4 local_10;
  undefined4 local_c;
  
  local_10 = 0;
  local_c = 0;
  if (in_EAX != 4) {
    iVar1 = props_getInt(unaff_ESI);
    if (iVar1 < 2) {
      props_setError(unaff_ESI,0x16);
      return 0x800407e2;
    }
    _DAT_68197764 =
         (undefined4 *)
         (**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
         *(int *)(unaff_ESI + 0x18));
    local_10 = DAT_68197768;
    local_c = DAT_6819776c;
    if (_DAT_68197764 != (undefined4 *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_10 = *(int *)(size_t)_DAT_68197764;
      local_c = ((int *)(size_t)_DAT_68197764)[1];
    }
  }
  uVar2 = sprites_sendMessage(unaff_ESI,score_dispatchCastMethod,local_14);
  return uVar2;
}


// ============================================================
// Function: score_setCastProperty (FUN_68047710)
// Address: 68047710
// Size: 42 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_setCastProperty(undefined4 *param_1)
{
  (**(code **)(*(int *)*param_1 + 0x1c))
            ((int *)*param_1,param_1 + 2,param_1[4],param_1[5],param_1 + 6,param_1[1]);
  return 0;
}


// ============================================================
// Function: score_sendSetCastProperty (FUN_68047740)
// Address: 68047740
// Size: 231 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_sendSetCastProperty(undefined4 param_1)
{
  int iVar1;
  undefined4 *puVar2;
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
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 < 2) {
    props_setError(unaff_ESI,0x16);
    return 0;
  }
  puVar2 = (undefined4 *)
           (**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
           *(int *)(unaff_ESI + 0x18));
  local_28 = *puVar2;
  local_24 = puVar2[1];
  local_20 = puVar2[3];
  puVar3 = puVar2 + 4;
  if (puVar2[2] != 8) {
    props_setError(unaff_ESI,0xb);
    return 0;
  }
  if (2 < iVar1) {
    local_1c = local_1c + 1;
    local_18 = *puVar3;
    local_14 = puVar2[5];
    puVar3 = puVar2 + 6;
  }
  if (3 < iVar1) {
    local_1c = local_1c + 1;
    local_10 = *puVar3;
    local_c = puVar3[1];
  }
  sprites_sendMessage(unaff_ESI,score_setCastProperty,local_30);
  return 0;
}


// ============================================================
// Function: score_sendCastQuery (FUN_68047830)
// Address: 68047830
// Size: 112 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_sendCastQuery(void)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_ESI;
  undefined1 local_10 [8];
  int local_8;
  
  iVar2 = props_getInt(unaff_ESI);
  if (iVar2 < 2) {
    props_setError(unaff_ESI,0x16);
    return 0x800407da;
  }
  piVar1 = (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
                  *(int *)(unaff_ESI + 0x18));
  local_8 = piVar1[1];
  if (*piVar1 != 8) {
    props_setError(unaff_ESI,0xb);
    return 0x800407da;
  }
  uVar3 = sprites_sendMessage(unaff_ESI,score_setXtraProperty,local_10);
  return uVar3;
}


// ============================================================
// Function: score_invokeCastCallback (FUN_680478a0)
// Address: 680478a0
// Size: 24 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_invokeCastCallback(undefined4 *param_1)
{
  (**(code **)(*(int *)*param_1 + 0x44))((int *)*param_1,param_1 + 1);
  return 0;
}


// ============================================================
// Function: score_sendCastCallback (FUN_680478c0)
// Address: 680478c0
// Size: 73 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_sendCastCallback(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = *(undefined4 *)(*param_2 + 8);
  local_8 = 0xeb;
  iVar1 = sprites_sendMessage(param_1,score_invokeCastCallback,&local_c);
  if (iVar1 != 0) {
    uVar2 = props_translateError(iVar1);
    props_setError(param_1,(int)(short)uVar2);
  }
  return local_8;
}


// ============================================================
// Function: score_dispatchCastAction (FUN_68047910)
// Address: 68047910
// Size: 24 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispatchCastAction(undefined4 *param_1)
{
  (**(code **)(*(int *)*param_1 + 0x38))((int *)*param_1,param_1 + 1);
  return 0;
}


// ============================================================
// Function: score_dispatchCastMember (FUN_68047930)
// Address: 68047930
// Size: 542 bytes
// Params: uint param_1, uint * param_2, undefined4 param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool score_dispatchCastMember(uint param_1,uint *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  int iVar3;
  uint local_c;
  uint *local_8;
  
  puVar2 = param_2;
  uVar1 = *(undefined4 *)(*param_2 + 8);
  param_2 = (uint *)0x0;
  local_c = 0;
  local_8 = (uint *)0x0;
  switch(param_3) {
  case 0x57:
    break;
  default:
    iVar3 = score_buildCastArgs(&local_c,param_1,uVar1,param_3);
    goto LAB_68047a49;
  case 0x5b:
    break;
  case 0x5c:
  case 0xca:
    break;
  case 0x5d:
  case 0xce:
    break;
  case 0x81:
    local_c = 0;
    local_8 = (uint *)0x0;
    iVar3 = score_invokeDateHandler(uVar1);
    if (iVar3 == 0) {
      if (local_c == 0) {
        local_c = 3;
        local_8 = puVar2;
        props_retainValue(param_1,&local_c);
      }
      props_popArgs(param_1,&local_c);
      return true;
    }
    _DAT_68197764 =
         **(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 + *(int *)(param_1 + 0x18);
    if (_DAT_68197764 != 0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      props_setErrorAndReturn(param_1,0x37);
      return false;
    }
    props_setErrorAndReturn(param_1,0x37);
    return false;
  case 0xd4:
  case 0xd5:
    iVar3 = score_sendSetCastProperty(uVar1);
    if (iVar3 == 0) {
      param_2 = &local_c;
      goto LAB_68047a8b;
    }
    goto LAB_68047b23;
  case 0xdb:
  case 0xdc:
    iVar3 = score_sendXtraMethod(uVar1);
    goto LAB_68047a81;
  case 0xdd:
    iVar3 = score_sendCastQuery();
    if (iVar3 != 0) {
      return false;
    }
    param_2 = &local_c;
    goto LAB_68047a8b;
  case 0xe3:
    score_resolveType(param_1);
    return true;
  case 0xea:
    iVar3 = score_sendDateEvent(param_1,&local_c);
LAB_68047a49:
    if (iVar3 == 0) {
      props_popArgs(param_1,&local_c);
      return true;
    }
    goto LAB_68047b23;
  }
  iVar3 = score_sendCastMethod();
LAB_68047a81:
  if (iVar3 == 0) {
LAB_68047a8b:
    props_popArgs(param_1,param_2);
    return true;
  }
LAB_68047b23:
  if ((iVar3 != -0x7ffbf821) && (iVar3 != -0x7ffbf830)) {
    props_mapErrorCode(param_1,iVar3,param_3);
  }
  return iVar3 == 0;
}


// ============================================================
// Function: score_notifyCastMember (FUN_68047c10)
// Address: 68047c10
// Size: 20 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_notifyCastMember(int *param_1)

{
  (**(code **)(*param_1 + 8))(param_1);
  return 0;
}


// ============================================================
// Function: score_releaseCastHandle (FUN_68047c30)
// Address: 68047c30
// Size: 54 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_releaseCastHandle(int param_1,int *param_2)
{
  if (*(int *)(*param_2 + 8) != 0) {
    sprites_sendMessage(param_1,score_notifyCastMember,*(int *)(*param_2 + 8));
  }
  cast_freeHandle(param_2);
  if (param_1 != 0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  }
  return 0;
}


// ============================================================
// Function: score_getCastName (FUN_68047c70)
// Address: 68047c70
// Size: 24 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getCastName(undefined4 *param_1)
{
  (**(code **)(*(int *)*param_1 + 0x40))((int *)*param_1,param_1 + 1);
  return 0;
}


// ============================================================
// Function: score_formatCastName (FUN_68047c90)
// Address: 68047c90
// Size: 366 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatCastName(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  undefined4 uVar5;
  byte *pbVar6;
  byte *pbVar7;
  int iVar8;
  undefined4 local_14;
  int local_10;
  int *local_c;
  byte *local_8;
  
  local_14 = *(undefined4 *)(*param_2 + 8);
  iVar8 = 0;
  local_c = (int *)0x0;
  iVar2 = sprites_sendMessage(param_1,score_getCastName,&local_14);
  if (iVar2 == 0) {
    if ((local_10 != 0x40) && (local_10 != 0x43)) {
      if (local_10 == 2) {
        cast_loadPascalString(&DAT_68197780,0x898,2);
        props_formatString(param_1,param_3,param_4,&DAT_68197781);
        return 0;
      }
      cast_loadPascalString(&DAT_68197780,0x898,0x3a);
      props_formatString(param_1,param_3,param_4,&DAT_68197781);
      return 0;
    }
    param_2 = (int *)0x0;
    pbVar3 = (byte *)props_getStringData(&local_10,(int *)&param_2);
    local_8 = (byte *)0x0;
    iVar2 = Ordinal_1205(pbVar3,0x25);
    pbVar4 = pbVar3;
    if (iVar2 != 0) {
      pbVar4 = (byte *)Ordinal_1124((int)param_2 * 2);
      pbVar6 = pbVar3;
      pbVar7 = pbVar4;
      do {
        bVar1 = *pbVar6;
        *pbVar7 = bVar1;
        pbVar6 = pbVar6 + 1;
        pbVar7 = pbVar7 + 1;
      } while (bVar1 != 0);
      iVar2 = 0;
      if (0 < (int)param_2) {
        do {
          if (pbVar3[iVar2] == 0x25) {
            pbVar4[iVar8] = 0x5c;
            iVar8 = iVar8 + 1;
          }
          pbVar4[iVar8] = pbVar3[iVar2];
          iVar2 = iVar2 + 1;
          iVar8 = iVar8 + 1;
        } while (iVar2 < (int)param_2);
      }
      pbVar4[iVar8] = 0;
      local_8 = pbVar4;
    }
    props_formatString(param_1,param_3,param_4,pbVar4);
    props_unlockString(&local_10);
    props_releaseValue(param_1,(byte)local_10,local_c);
    if (local_8 != (byte *)0x0) {
      Ordinal_1125(&local_8);
      return 0;
    }
  }
  else {
    uVar5 = props_translateError(iVar2);
    props_setError(param_1,(int)(short)uVar5);
  }
  return 0;
}


