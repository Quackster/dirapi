// Module: score
// Topic: Type checking, bitwise ops, random, iteration
// Address range: 0x68040b20 - 0x68041320
// Functions (19):
//   score_getTypeField
//   score_randomRange
//   score_returnVoid
//   score_returnValue
//   score_getTypeInfo
//   score_isListType
//   score_isObjectOfType
//   score_getValueOrProplist
//   score_iterateList
//   score_iterateListForward
//   score_iterateListReverse
//   score_checkType
//   score_resolveType
//   score_bitwiseAnd
//   score_bitwiseOr
//   score_bitwiseXor
//   score_bitwiseNot
//   score_getChannelRef
//   score_getTimestamp

// ============================================================
// Function: score_getTypeField (FUN_68040b20)
// Address: 68040b20
// Size: 13 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getTypeField(int param_1)

{
  return *(undefined4 *)(param_1 + 0x5c);
}


// ============================================================
// Function: score_randomRange (FUN_68040b30)
// Address: 68040b30
// Size: 118 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_randomRange(uint param_1)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint local_8;
  
  uVar1 = param_1;
  local_8 = 0;
  iVar2 = props_getTypedValue(param_1,1,4,&param_1);
  if (iVar2 != 0) {
    local_8 = param_1;
    iVar2 = props_getTypedProperty(uVar1,2,4,&local_8);
    if (iVar2 != 0) {
      if ((int)param_1 < (int)local_8) {
        uVar3 = cast_getRandomValue((local_8 - param_1) + 1);
        props_normalizeType(uVar1,4,uVar3 + param_1);
        return 0;
      }
      uVar3 = cast_getRandomValue(param_1);
      props_normalizeType(uVar1,4,uVar3 + 1);
    }
  }
  return 0;
}


// ============================================================
// Function: score_returnVoid (FUN_68040bb0)
// Address: 68040bb0
// Size: 33 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_returnVoid(int param_1)
{
  *(undefined4 *)(param_1 + 0x74) = 9;
  props_popArgs(param_1,(undefined4 *)0x0);
  props_unwindStack(param_1);
  return 0;
}


// ============================================================
// Function: score_returnValue (FUN_68040be0)
// Address: 68040be0
// Size: 33 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_returnValue(int param_1)
{
  *(undefined4 *)(param_1 + 0x74) = 10;
  props_popArgs(param_1,(undefined4 *)0x0);
  props_unwindStack(param_1);
  return 0;
}


// ============================================================
// Function: score_getTypeInfo (FUN_68040c10)
// Address: 68040c10
// Size: 125 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getTypeInfo(int param_1)
{
  int iVar1;
  int *piVar2;
  bool bVar3;
  
  iVar1 = *(int *)(param_1 + 0xb4);
  piVar2 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  if (iVar1 == 1) {
    if (*piVar2 == 0x40) goto LAB_68040c7a;
    bVar3 = *piVar2 == 0x43;
  }
  else {
    if (iVar1 != 9) {
      props_normalizeType(param_1,4,(uint)(*piVar2 == iVar1));
      return 0;
    }
    if (*piVar2 == 0x20) goto LAB_68040c7a;
    bVar3 = *piVar2 == 0x23;
  }
  if (!bVar3) {
    props_normalizeType(param_1,4,0);
    return 0;
  }
LAB_68040c7a:
  props_normalizeType(param_1,4,1);
  return 0;
}


// ============================================================
// Function: score_isListType (FUN_68040c90)
// Address: 68040c90
// Size: 71 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_isListType(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  if ((iVar1 != 6) && (iVar1 != 3)) {
    props_normalizeType(param_1,4,0);
    return 0;
  }
  props_normalizeType(param_1,4,1);
  return 0;
}


// ============================================================
// Function: score_isObjectOfType (FUN_68040ce0)
// Address: 68040ce0
// Size: 76 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_isObjectOfType(int param_1)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  iVar4 = 0;
  if (*piVar2 == 3) {
    puVar1 = (undefined4 *)piVar2[1];
    iVar3 = (*(code *)**(undefined4 **)*puVar1)(param_1,puVar1);
    if (iVar3 == *(int *)(param_1 + 0xb4)) {
      iVar4 = 1;
    }
  }
  props_normalizeType(param_1,4,iVar4);
  return 0;
}


// ============================================================
// Function: score_getValueOrProplist (FUN_68040d30)
// Address: 68040d30
// Size: 141 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_getValueOrProplist(int param_1)
{
  int iVar1;
  int local_c;
  int local_8;
  
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18)
              );
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  iVar1 = props_setRectField(param_1,&local_c);
  if (iVar1 == 0) {
    iVar1 = score_getProplistValue(param_1,&local_c);
    local_8 = 0;
    if (iVar1 == 0) goto LAB_68040da2;
  }
  local_8 = 1;
LAB_68040da2:
  local_c = 4;
  props_popArgs(param_1,&local_c);
  return 0;
}


// ============================================================
// Function: score_iterateList (FUN_68040dc0)
// Address: 68040dc0
// Size: 645 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_iterateList(int param_1)
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  int *unaff_ESI;
  int iVar5;
  uint local_4c;
  int *local_48;
  int local_44;
  undefined4 local_40;
  uint local_3c;
  int *local_38;
  uint local_34;
  int *local_30;
  uint local_2c;
  int local_28;
  int local_24;
  uint local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  iVar2 = props_getTypedValue((int)unaff_ESI,1,8,&local_14);
  if ((iVar2 != 0) && (iVar2 = props_getTypedValue((int)unaff_ESI,2,3,(uint *)&local_8), iVar2 != 0)) {
    iVar5 = *(int *)unaff_ESI[4] + unaff_ESI[8] * -8 + unaff_ESI[6];
    iVar2 = props_getInt((int)unaff_ESI);
    local_44 = *(int *)(iVar5 + 8);
    local_40 = *(undefined4 *)(iVar5 + 0xc);
    unaff_ESI[6] = unaff_ESI[6] + -8;
    uVar3 = iVar2 - 1;
    local_20 = unaff_ESI[8] & 0x80000000;
    local_2c = local_20 | uVar3;
    unaff_ESI[8] = local_2c;
    local_18 = uVar3;
    Ordinal_1129(iVar5,iVar5 + 8,uVar3 * 8);
    iVar2 = props_setRectField(unaff_ESI,&local_44);
    local_24 = iVar2;
    if ((iVar2 == 0) && (iVar5 = score_getProplistValue(unaff_ESI,&local_44), iVar5 == 0)) {
      if (param_1 == 0) {
        pcVar4 = *(code **)(*(int *)*local_8 + 4);
      }
      else {
        pcVar4 = *(code **)(*(int *)*local_8 + 8);
      }
      iVar2 = (*pcVar4)();
      if (iVar2 == 0) {
        props_setError((int)unaff_ESI,4);
        return 0;
      }
    }
    else {
      local_28 = unaff_ESI[6] + uVar3 * -8;
      local_3c = 0;
      if (iVar2 == 0) {
        local_c = props_getListLength(unaff_ESI,local_8);
      }
      else {
        local_c = props_getListLength(unaff_ESI,local_8);
      }
      local_1c = 0;
      if (0 < local_c) {
        do {
          if (iVar2 == 0) {
            score_setProplistValue(unaff_ESI,local_8,local_1c,&local_4c,&local_34);
            props_releaseValue(unaff_ESI,(byte)local_4c,local_48);
          }
          else {
            props_getListEntry(unaff_ESI,local_8,local_1c,&local_34);
          }
          if (local_34 == 3) {
            props_pushValue((int)unaff_ESI);
            puVar1 = (uint *)(unaff_ESI + 7);
            *puVar1 = local_34;
            unaff_ESI[8] = (int)local_30;
            props_retainValue(unaff_ESI,puVar1);
            if (1 < (int)local_18) {
              local_10 = local_18 - 1;
              iVar2 = local_28;
              do {
                iVar2 = iVar2 + 8;
                props_pushValue((int)unaff_ESI);
                iVar5 = *(int *)unaff_ESI[4];
                *puVar1 = *(uint *)(iVar5 + iVar2);
                unaff_ESI[8] = *(int *)(iVar5 + 4 + iVar2);
                props_retainValue(unaff_ESI,puVar1);
                local_10 = local_10 + -1;
              } while (local_10 != 0);
            }
            props_pushValue((int)unaff_ESI);
            unaff_ESI[8] = local_2c;
            if (param_1 == 0) {
              pcVar4 = *(code **)(*(int *)*local_30 + 4);
            }
            else {
              pcVar4 = *(code **)(*(int *)*local_30 + 8);
            }
            iVar2 = (*pcVar4)();
            if (iVar2 == 0) {
              if (-1 < (int)local_18) {
                iVar2 = local_18 + 1;
                do {
                  props_popValue((int)unaff_ESI);
                  iVar2 = iVar2 + -1;
                } while (iVar2 != 0);
              }
            }
            else {
              if ((unaff_ESI[0x1d] == 2) &&
                 (props_dispatchOpcode(unaff_ESI,(int *)0x2,0,0), unaff_ESI[0x1d] == 8)) break;
              if (local_20 != 0) {
                props_releaseValue(unaff_ESI,(byte)local_3c,local_38);
                local_3c = *puVar1;
                local_38 = (int *)unaff_ESI[8];
                unaff_ESI[6] = unaff_ESI[6] + -8;
                iVar2 = *(int *)unaff_ESI[4];
                *puVar1 = *(uint *)(iVar2 + unaff_ESI[6]);
                unaff_ESI[8] = *(int *)(iVar2 + 4 + unaff_ESI[6]);
              }
            }
          }
          props_releaseValue(unaff_ESI,(byte)local_34,local_30);
          local_1c = local_1c + 1;
          iVar2 = local_24;
        } while (local_1c < local_c);
      }
      if (local_20 != 0) {
        props_popArgs((int)unaff_ESI,&local_3c);
        return 0;
      }
      props_popArgs((int)unaff_ESI,(undefined4 *)0x0);
    }
  }
  return 0;
}


// ============================================================
// Function: score_iterateListForward (FUN_68041050)
// Address: 68041050
// Size: 19 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_iterateListForward(void)
{
  score_iterateList(0);
  return 0;
}


// ============================================================
// Function: score_iterateListReverse (FUN_68041070)
// Address: 68041070
// Size: 19 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_iterateListReverse(void)
{
  score_iterateList(1);
  return 0;
}


// ============================================================
// Function: score_checkType (FUN_68041090)
// Address: 68041090
// Size: 102 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_checkType(undefined4 param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  switch(*param_2) {
  case 1:
  case 0x40:
  case 0x43:
    return 0x8b;
  default:
    return 0x7e;
  case 3:
    uVar1 = (**(code **)**(undefined4 **)param_2[1])(param_1,(undefined4 *)param_2[1]);
    return uVar1;
  case 4:
    return 0x95;
  case 6:
    return 0xa8;
  case 8:
    return 0x8c;
  case 9:
  case 0x20:
  case 0x23:
    return 0x97;
  }
}


// ============================================================
// Function: score_resolveType (FUN_68041160)
// Address: 68041160
// Size: 259 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_resolveType(uint param_1)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  bool bVar6;
  
  uVar1 = param_1;
  uVar5 = 0;
  iVar2 = props_getInt(param_1);
  if (iVar2 == 1) {
    iVar2 = score_checkType(uVar1,(undefined4 *)
                               (**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 +
                               *(int *)(uVar1 + 0x18)));
    props_normalizeType(uVar1,8,iVar2);
    return 0;
  }
  iVar2 = props_getTypedValue(uVar1,2,8,&param_1);
  if (iVar2 == 0) {
    return 0;
  }
  puVar4 = (undefined4 *)
           (*(int *)(uVar1 + 0x18) + **(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8);
  switch(*puVar4) {
  case 1:
  case 0x40:
  case 0x43:
    bVar6 = param_1 == 0x8b;
    break;
  case 2:
    bVar6 = param_1 == 0x7e;
    break;
  case 3:
    bVar6 = param_1 == 0xa8;
    break;
  case 4:
    bVar6 = param_1 == 0x95;
    goto LAB_680411ef;
  default:
    goto switchD_680411d8_caseD_5;
  case 6:
    uVar5 = (uint)(param_1 == 0xa8);
    goto LAB_6804123f;
  case 8:
    uVar5 = (uint)(param_1 == 0x8c);
    goto LAB_6804123f;
  case 9:
  case 0x20:
  case 0x23:
    bVar6 = param_1 == 0x97;
LAB_680411ef:
    if ((!bVar6) && (param_1 != 0xaa)) {
      uVar5 = 0;
      goto switchD_680411d8_caseD_5;
    }
    goto LAB_6804124f;
  }
  uVar5 = (uint)bVar6;
LAB_6804123f:
  if (uVar5 == 0) {
switchD_680411d8_caseD_5:
    uVar3 = score_checkType(uVar1,puVar4);
    if (param_1 == uVar3) {
LAB_6804124f:
      uVar5 = 1;
    }
  }
  props_normalizeType(uVar1,4,uVar5);
  return 0;
}


// ============================================================
// Function: score_bitwiseAnd (FUN_680412d0)
// Address: 680412d0
// Size: 13 bytes
// Params: undefined4 param_1, uint param_2, uint param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint score_bitwiseAnd(undefined4 param_1,uint param_2,uint param_3)

{
  return param_2 & param_3;
}


// ============================================================
// Function: score_bitwiseOr (FUN_680412e0)
// Address: 680412e0
// Size: 13 bytes
// Params: undefined4 param_1, uint param_2, uint param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint score_bitwiseOr(undefined4 param_1,uint param_2,uint param_3)

{
  return param_2 | param_3;
}


// ============================================================
// Function: score_bitwiseXor (FUN_680412f0)
// Address: 680412f0
// Size: 13 bytes
// Params: undefined4 param_1, uint param_2, uint param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint score_bitwiseXor(undefined4 param_1,uint param_2,uint param_3)

{
  return param_2 ^ param_3;
}


// ============================================================
// Function: score_bitwiseNot (FUN_68041300)
// Address: 68041300
// Size: 12 bytes
// Params: undefined4 param_1, uint param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint score_bitwiseNot(undefined4 param_1,uint param_2)

{
  return ~param_2;
}


// ============================================================
// Function: score_getChannelRef (FUN_68041310)
// Address: 68041310
// Size: 9 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getChannelRef(int param_1)
{
  sprites_getChannelRef(param_1);
  return 0;
}


// ============================================================
// Function: score_getTimestamp (FUN_68041320)
// Address: 68041320
// Size: 118 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getTimestamp(int param_1)
{
  double dVar1;
  undefined4 local_c;
  uint local_8;
  
  local_8 = Ordinal_1106();
  if (local_8 == 0x7fffffff) {
    local_8 = 0x80000000;
  }
  else if (local_8 < 0x80000000) {
    local_c = 4;
    props_popArgs(param_1,&local_c);
    return 0;
  }
  dVar1 = (double)(int)local_8;
  if ((int)local_8 < 0) {
    dVar1 = dVar1 + 4294967296.0;
  }
  if (local_8 == 0xffffffff) {
    dVar1 = dVar1 + 1.0;
  }
  props_storeNumber(param_1,dVar1,&local_c);
  props_popArgs(param_1,&local_c);
  return 0;
}


