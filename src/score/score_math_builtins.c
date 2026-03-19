// Module: score
// Topic: Math builtins (trig, comparison, value operations)
// Address range: 0x68040050 - 0x68040a30
// Functions (19):
//   score_charToNum (FUN_68040050)
//   score_charsSubstring (FUN_680400b0)
//   score_returnNothing (FUN_68040180)
//   score_returnSpace (FUN_680401b0)
//   score_getTheResult (FUN_680401e0)
//   score_resolveExpression (FUN_68040220)
//   score_evalExpression (FUN_680402d0)
//   score_execLingo (FUN_680404d0)
//   score_toString (FUN_68040520)
//   score_sin (FUN_68040570)
//   score_cos (FUN_680405d0)
//   score_tan (FUN_68040630)
//   score_atan (FUN_68040690)
//   score_sqrt (FUN_68040790)
//   score_exp (FUN_680407f0)
//   score_power (FUN_68040850)
//   score_returnPi (FUN_680408e0)
//   score_minMax (FUN_68040920)
//   score_getParam (FUN_68040a30)

// ============================================================
// Function: score_charToNum (FUN_68040050)
// Address: 68040050
// Size: 84 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_charToNum(int param_1)
{
  int local_18;
  int *piVar1;
  int iVar2;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  local_14 = *piVar1;
  local_10 = piVar1[1];
  local_c = piVar1[2];
  local_8 = piVar1[3];
  iVar2 = props_findSubstring(param_1,&local_14,&local_c);
  props_normalizeType(param_1,4,iVar2 + 1);
  return 0;
}


// ============================================================
// Function: score_charsSubstring (FUN_680400b0)
// Address: 680400b0
// Size: 181 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_charsSubstring(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 local_20 [2];
  uint local_18 [2];
  int local_10;
  uint local_c;
  uint local_8;
  
  iVar1 = props_getValueDirect(param_1,1,1,local_18);
  if (((iVar1 != 0) && (iVar1 = props_getTypedValue(param_1,2,4,&local_8), iVar1 != 0)) &&
     (iVar1 = props_getTypedValue(param_1,3,4,&local_c), iVar1 != 0)) {
    if ((int)local_8 < 1) {
      local_8 = 1;
    }
    props_getStringData((int *)local_18,&local_10);
    iVar1 = stage_getStringAllocState();
    iVar2 = stage_getStringAllocState();
    props_createStringFromData(param_1,iVar1,iVar2 - iVar1,local_20);
    props_unlockString((int *)local_18);
    props_popArgs(param_1,local_20);
  }
  return 0;
}


// ============================================================
// Function: score_returnNothing (FUN_68040180)
// Address: 68040180
// Size: 39 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_returnNothing(int param_1)
{
  undefined4 local_c;
  undefined4 local_8;
  
  local_c = 2;
  local_8 = 0;
  props_popArgs(param_1,&local_c);
  return 0;
}


// ============================================================
// Function: score_returnSpace (FUN_680401b0)
// Address: 680401b0
// Size: 47 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_returnSpace(int param_1)
{
  undefined4 local_10 [2];
  byte local_8 [4];
  
  local_8[0] = 1;
  local_8[1] = 0x20;
  props_readPascalString(param_1,local_8,local_10);
  props_popArgs(param_1,local_10);
  return 0;
}


// ============================================================
// Function: score_getTheResult (FUN_680401e0)
// Address: 680401e0
// Size: 55 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getTheResult(int param_1)
{
  uint local_c;
  undefined4 local_8;
  
  local_c = *(uint *)(param_1 + 0xac);
  local_8 = *(undefined4 *)(param_1 + 0xb0);
  props_retainValue(param_1,&local_c);
  props_popArgs(param_1,&local_c);
  return 0;
}


// ============================================================
// Function: score_resolveExpression (FUN_68040220)
// Address: 68040220
// Size: 176 bytes
// Params: void * param_1, uint param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_resolveExpression(void *param_1,uint param_2,undefined4 param_3)
{
  int local_468;
  undefined4 local_464 [279];
  uint local_8;
  
  props_parseToken(local_464,param_3);
  stage_compileHandlerScope(param_1,local_464,-1,param_2 | 0xa8,0,0,&local_468);
  if (local_468 == 0) {
    if ((param_2 & 0x40) == 0) {
      props_setError((int)param_1,0);
    }
    return 0;
  }
  *(int *)((int)param_1 + 0x9c) = local_468;
  *(undefined4 *)((int)param_1 + 0xa0) = 0;
  *(undefined4 *)((int)param_1 + 0xa8) = 0;
  *(undefined4 *)((int)param_1 + 0x74) = 2;
  return 0;
}


// ============================================================
// Function: score_evalExpression (FUN_680402d0)
// Address: 680402d0
// Size: 463 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_evalExpression(void *param_1)
{
  undefined4 *puVar1;
  int iVar2;
  int local_47c;
  int *local_478;
  uint local_474;
  uint local_470;
  uint local_46c;
  int *local_468;
  undefined4 local_464 [279];
  uint local_8;
  
  _DAT_68197764 =
       (uint *)(**(int **)((int)param_1 + 0x10) + *(int *)((int)param_1 + 0x20) * -8 +
               *(int *)((int)param_1 + 0x18));
  local_470 = DAT_6819776c;
  local_474 = DAT_68197768;
  if (_DAT_68197764 != (uint *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_470 = ((int *)(size_t)_DAT_68197764)[1];
    local_474 = *(int *)(size_t)_DAT_68197764;
  }
  if (((local_474 != 1) && (local_474 != 0x40)) && (local_474 != 0x43)) {
    local_46c = local_474;
    local_468 = (int *)local_470;
    props_retainValue(param_1,&local_46c);
    props_popArgs((int)param_1,&local_46c);
    return 0;
  }
  local_46c = 2;
  puVar1 = props_copyString((int *)&local_474);
  props_parseToken(local_464,puVar1);
  props_setParserState(param_1,local_464,0);
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
    props_setParserState(param_1,local_464,0);
    if (local_47c == 0) {
      switch(local_46c) {
      case 0:
        local_46c = 4;
        local_468 = (int *)0x0;
      case 4:
      case 9:
      case 0x20:
      case 0x23:
        if (puVar1 != (undefined4 *)0x0) {
          props_freeStringCallback(&local_474,puVar1);
        }
        props_popArgs((int)param_1,&local_46c);
        return 0;
      }
    }
    props_releaseValue(param_1,(byte)local_46c,local_468);
    props_releaseValue(param_1,(byte)local_47c,local_478);
  }
  iVar2 = score_resolveExpression(param_1,0x840,puVar1);
  if (iVar2 == 0) {
    props_normalizeType((int)param_1,2,0);
  }
  props_freeStringCallback(&local_474,puVar1);
  return 0;
}


// ============================================================
// Function: score_execLingo (FUN_680404d0)
// Address: 680404d0
// Size: 67 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_execLingo(void *param_1)
{
  int iVar1;
  undefined4 *puVar2;
  uint local_c [2];
  
  iVar1 = props_getValueDirect((int)param_1,1,1,local_c);
  if (iVar1 != 0) {
    puVar2 = props_copyString((int *)local_c);
    score_resolveExpression(param_1,0,puVar2);
    props_freeStringCallback(local_c,puVar2);
  }
  return 0;
}


// ============================================================
// Function: score_toString (FUN_68040520)
// Address: 68040520
// Size: 74 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_toString(int param_1)
{
  int *piVar1;
  int local_c;
  int local_8;
  
  piVar1 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  local_c = *piVar1;
  local_8 = piVar1[1];
  *piVar1 = 0;
  props_getStringRef(param_1,&local_c);
  props_popArgs(param_1,&local_c);
  return 0;
}


// ============================================================
// Function: score_sin (FUN_68040570)
// Address: 68040570
// Size: 91 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_sin(int param_1)
{
  int iVar1;
  float10 fVar2;
  double dVar3;
  undefined4 local_14 [2];
  uint local_c;
  int *local_8;
  
  iVar1 = props_getValueDirect(param_1,1,9,&local_c);
  if (iVar1 != 0) {
    if (local_c != 0x20) {
      /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_8 = (int *)(float)*(double *)(*local_8 + 8); */
    }
    dVar3 = (double)(float)(size_t)local_8;
    fVar2 = (float10)Ordinal_1528(dVar3,local_14);
    props_storeNumber(param_1,(double)fVar2,SUB84(dVar3,0));
    props_popArgs(param_1,local_14);
  }
  return 0;
}


// ============================================================
// Function: score_cos (FUN_680405d0)
// Address: 680405d0
// Size: 91 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_cos(int param_1)
{
  int iVar1;
  float10 fVar2;
  double dVar3;
  undefined4 local_14 [2];
  uint local_c;
  int *local_8;
  
  iVar1 = props_getValueDirect(param_1,1,9,&local_c);
  if (iVar1 != 0) {
    if (local_c != 0x20) {
      /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_8 = (int *)(float)*(double *)(*local_8 + 8); */
    }
    dVar3 = (double)(float)(size_t)local_8;
    fVar2 = (float10)Ordinal_1527(dVar3,local_14);
    props_storeNumber(param_1,(double)fVar2,SUB84(dVar3,0));
    props_popArgs(param_1,local_14);
  }
  return 0;
}


// ============================================================
// Function: score_tan (FUN_68040630)
// Address: 68040630
// Size: 91 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_tan(int param_1)
{
  int iVar1;
  float10 fVar2;
  double dVar3;
  undefined4 local_14 [2];
  uint local_c;
  int *local_8;
  
  iVar1 = props_getValueDirect(param_1,1,9,&local_c);
  if (iVar1 != 0) {
    if (local_c != 0x20) {
      /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_8 = (int *)(float)*(double *)(*local_8 + 8); */
    }
    dVar3 = (double)(float)(size_t)local_8;
    fVar2 = (float10)Ordinal_1529(dVar3,local_14);
    props_storeNumber(param_1,(double)fVar2,SUB84(dVar3,0));
    props_popArgs(param_1,local_14);
  }
  return 0;
}


// ============================================================
// Function: score_atan (FUN_68040690)
// Address: 68040690
// Size: 253 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_atan(int param_1)
{
  int iVar1;
  float10 fVar2;
  double dVar3;
  undefined4 local_1c [2];
  uint local_14;
  int *local_10;
  uint local_c;
  int *local_8;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 == 1) {
    iVar1 = props_getValueDirect(param_1,1,9,&local_c);
    if (iVar1 != 0) {
      if (local_c != 0x20) {
        /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_8 = (int *)(float)*(double *)(*local_8 + 8); */
      }
      dVar3 = (double)(float)(size_t)local_8;
      fVar2 = (float10)Ordinal_1530(dVar3,local_1c);
      props_storeNumber(param_1,(double)fVar2,SUB84(dVar3,0));
      props_popArgs(param_1,local_1c);
      return 0;
    }
  }
  else if (iVar1 == 2) {
    iVar1 = props_getValueDirect(param_1,1,9,&local_c);
    if ((iVar1 != 0) && (iVar1 = props_getValueDirect(param_1,2,9,&local_14), iVar1 != 0)) {
      if (local_14 != 0x20) {
        /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_10 = (int *)(float)*(double *)(*local_10 + 8); */
      }
      if (local_c != 0x20) {
        /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_8 = (int *)(float)*(double *)(*local_8 + 8); */
      }
      dVar3 = (double)(float)(size_t)local_8;
      fVar2 = (float10)Ordinal_1531(dVar3,(double)(float)(size_t)local_10,local_1c);
      props_storeNumber(param_1,(double)fVar2,SUB84(dVar3,0));
      props_popArgs(param_1,local_1c);
      return 0;
    }
  }
  else {
    props_setError(param_1,0x19);
  }
  return 0;
}


// ============================================================
// Function: score_sqrt (FUN_68040790)
// Address: 68040790
// Size: 91 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_sqrt(int param_1)
{
  int iVar1;
  float10 fVar2;
  double dVar3;
  undefined4 local_14 [2];
  uint local_c;
  int *local_8;
  
  iVar1 = props_getValueDirect(param_1,1,9,&local_c);
  if (iVar1 != 0) {
    if (local_c != 0x20) {
      /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_8 = (int *)(float)*(double *)(*local_8 + 8); */
    }
    dVar3 = (double)(float)(size_t)local_8;
    fVar2 = (float10)Ordinal_1526(dVar3,local_14);
    props_storeNumber(param_1,(double)fVar2,SUB84(dVar3,0));
    props_popArgs(param_1,local_14);
  }
  return 0;
}


// ============================================================
// Function: score_exp (FUN_680407f0)
// Address: 680407f0
// Size: 91 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_exp(int param_1)
{
  int iVar1;
  float10 fVar2;
  double dVar3;
  undefined4 local_14 [2];
  uint local_c;
  int *local_8;
  
  iVar1 = props_getValueDirect(param_1,1,9,&local_c);
  if (iVar1 != 0) {
    if (local_c != 0x20) {
      /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_8 = (int *)(float)*(double *)(*local_8 + 8); */
    }
    dVar3 = (double)(float)(size_t)local_8;
    fVar2 = (float10)Ordinal_1525(dVar3,local_14);
    props_storeNumber(param_1,(double)fVar2,SUB84(dVar3,0));
    props_popArgs(param_1,local_14);
  }
  return 0;
}


// ============================================================
// Function: score_power (FUN_68040850)
// Address: 68040850
// Size: 137 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_power(int param_1)
{
  int iVar1;
  float10 fVar2;
  double dVar3;
  undefined4 local_1c [2];
  uint local_14;
  int *local_10;
  uint local_c;
  int *local_8;
  
  iVar1 = props_getValueDirect(param_1,1,9,&local_14);
  if ((iVar1 != 0) && (iVar1 = props_getValueDirect(param_1,2,9,&local_c), iVar1 != 0)) {
    if (local_c != 0x20) {
      /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_8 = (int *)(float)*(double *)(*local_8 + 8); */
    }
    if (local_14 != 0x20) {
      /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): local_10 = (int *)(float)*(double *)(*local_10 + 8); */
    }
    dVar3 = (double)(float)(size_t)local_10;
    fVar2 = (float10)Ordinal_1524(dVar3,(double)(float)(size_t)local_8,local_1c);
    props_storeNumber(param_1,(double)fVar2,SUB84(dVar3,0));
    props_popArgs(param_1,local_1c);
  }
  return 0;
}


// ============================================================
// Function: score_returnPi (FUN_680408e0)
// Address: 680408e0
// Size: 49 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_returnPi(int param_1)
{
  undefined4 local_c [2];
  
  props_storeNumber(param_1,3.141592653589793,local_c);
  props_popArgs(param_1,local_c);
  return 0;
}


// ============================================================
// Function: score_minMax (FUN_68040920)
// Address: 68040920
// Size: 260 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_minMax(int param_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  iVar1 = param_1;
  local_8 = *(int *)(param_1 + 0xb4);
  local_c = props_getInt(param_1);
  if (0 < local_c) {
    _DAT_68197764 =
         (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                 *(int *)(param_1 + 0x18));
    local_10 = DAT_6819776c;
    local_14 = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_10 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_14 = *(int *)(size_t)_DAT_68197764;
    }
    param_1 = 2;
    if (1 < local_c) {
      do {
        _DAT_68197764 =
             (uint *)(**(int **)(iVar1 + 0x10) + -8 + (param_1 - *(int *)(iVar1 + 0x20)) * 8 +
                     *(int *)(iVar1 + 0x18));
        uVar3 = DAT_68197768;
        piVar4 = DAT_6819776c;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = (int *)0x0;
          DAT_68197768 = 0;
          uVar3 = *(int *)(size_t)_DAT_68197764;
          piVar4 = (int *)((int *)(size_t)_DAT_68197764)[1];
        }
        iVar2 = props_compareValues(iVar1,local_14,local_10,uVar3,piVar4);
        if (iVar2 != local_8) {
          local_14 = uVar3;
          local_10 = piVar4;
        }
        param_1 = param_1 + 1;
      } while (param_1 <= local_c);
    }
    props_retainValue(iVar1,&local_14);
    props_popArgs(iVar1,&local_14);
    return 0;
  }
  props_normalizeType(param_1,4,0);
  return 0;
}


// ============================================================
// Function: score_getParam (FUN_68040a30)
// Address: 68040a30
// Size: 225 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getParam(int param_1)
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint local_10;
  uint local_c;
  int local_8;
  
  iVar4 = param_1;
  local_10 = 0;
  local_c = 0;
  iVar5 = props_requireInt(param_1,(int *)(*(int *)(param_1 + 0x18) + *(int *)(param_1 + 0x20) * -8 +
                                      **(int **)(param_1 + 0x10)),&param_1);
  if (iVar5 != 0) {
    if ((0 < param_1) && (param_1 <= *(int *)(iVar4 + 0x5c))) {
      uVar1 = param_1 * 8 - 8;
      if (-1 < (int)uVar1) {
        uVar3 = *(uint *)(iVar4 + 0x44);
        local_8 = (int)uVar3 >> 0x1f;
        uVar6 = local_8 + ((int)uVar1 >> 0x1f) + (uint)CARRY4(uVar3,uVar1);
        if ((((-2 < (int)uVar6) &&
             (((uVar6 < 0x80000000 || (0x80000000 < uVar3 + uVar1)) && ((int)uVar6 < 1)))) &&
            ((((int)uVar6 < 0 || (uVar3 + uVar1 < 0x80000000)) &&
             ((int)((uVar3 - 8) + param_1 * 8) < *(int *)(iVar4 + 0x40))))) &&
           (puVar2 = (uint *)(**(int **)(iVar4 + 0x10) + uVar3 + -8 + param_1 * 8),
           puVar2 != (uint *)0x0)) {
          local_10 = *puVar2;
          local_c = puVar2[1];
        }
      }
      props_retainValue(iVar4,&local_10);
      props_popArgs(iVar4,&local_10);
      return 0;
    }
    props_normalizeType(iVar4,4,0);
  }
  return 0;
}


