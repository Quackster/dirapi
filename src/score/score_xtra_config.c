// Module: score
// Topic: Xtra configuration and regex dispatch
// Address range: 0x6804cd80 - 0x6804d5f0
// Functions (9):
//   score_createXtraConfig (FUN_6804cd80)
//   score_dumpXtraList (FUN_6804ce00)
//   score_ensureXtraFactory (FUN_6804cf00)
//   score_resolveXtraString (FUN_6804cf40)
//   score_setXtraConfigValue (FUN_6804cfc0)
//   score_applyXtraPattern (FUN_6804d210)
//   score_formatXtraString (FUN_6804d320)
//   score_dispatchXtraRegex (FUN_6804d420)
//   score_deleteXtraMatch (FUN_6804d5f0)

// ============================================================
// Function: score_createXtraConfig (FUN_6804cd80)
// Address: 6804cd80
// Size: 128 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * score_createXtraConfig(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(0x38,1);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
  iVar1 = **(int **)(param_1 + 8);
  *(undefined4 *)(*piVar2 + 8) = *(undefined4 *)(**(int **)(iVar1 + 0x564) + 8);
  *(undefined4 *)(*piVar2 + 0xc) = *(undefined4 *)(iVar1 + 0x564);
  *(int **)(**(int **)(**(int **)(iVar1 + 0x564) + 8) + 0xc) = piVar2;
  *(int **)(**(int **)(iVar1 + 0x564) + 8) = piVar2;
  score_initXtraConfig(param_2,param_3,param_4);
  score_registerInstance(piVar2);
  return piVar2;
}


// ============================================================
// Function: score_dumpXtraList (FUN_6804ce00)
// Address: 6804ce00
// Size: 248 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dumpXtraList(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_418;
  undefined4 local_414;
  uint local_410;
  int *local_40c;
  undefined2 local_408 [512];
  uint local_8;
  
  piVar1 = *(int **)(**(int **)(param_1 + 8) + 0x514);
  if (piVar1 != (int *)0x0) {
    iVar2 = props_getListLength(param_1,piVar1);
    iVar4 = 0;
    if (0 < iVar2) {
      do {
        props_getListEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x514),iVar4,&local_410);
        iVar3 = score_isXtraInstance();
        if ((iVar3 != 0) && (iVar3 = *local_40c, *(int *)(iVar3 + 0x20) == param_2)) {
          local_418 = *(int *)(iVar3 + 0x18);
          local_414 = *(undefined4 *)(iVar3 + 0x1c);
          if ((local_418 == 0x40) || (local_418 == 0x43)) {
            props_toPascalString(&local_418,(undefined1 *)local_408);
          }
          else {
            local_408[0] = 0;
          }
          props_formatValue(param_1,(byte *)"--   Xtra: %p\n");
        }
        props_releaseValue(param_1,(byte)local_410,local_40c);
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
  }
  return 0;
}


// ============================================================
// Function: score_ensureXtraFactory (FUN_6804cf00)
// Address: 6804cf00
// Size: 61 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_ensureXtraFactory(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *in_stack_00000014;
  
  piVar1 = score_allocScriptObject(*param_1);
  if (piVar1 == (int *)0x0) {
    *in_stack_00000014 = 3;
    in_stack_00000014[1] = 0;
    iVar2 = stage_createFactory((int)param_1,-1,in_stack_00000014);
    return iVar2;
  }
  return 0;
}


// ============================================================
// Function: score_resolveXtraString (FUN_6804cf40)
// Address: 6804cf40
// Size: 124 bytes
// Params: int param_1, undefined4 param_2, int param_3, uint * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_resolveXtraString(int param_1,undefined4 param_2,int param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint local_c;
  undefined4 local_8;
  
  local_c = 0;
  uVar1 = stage_allocString((int *)param_1,&local_c);
  iVar2 = score_findInstanceByName(local_c,local_8,param_4);
  if (iVar2 == 0) {
    *param_4 = 2;
    param_4[1] = 0;
  }
  else {
    stage_createFactory(param_1,-1,param_4);
    iVar2 = param_3 + -1;
    if (0 < iVar2) {
      while (uVar1 = stage_allocString((int *)param_1,&local_c), uVar1 == 0) {
        iVar2 = iVar2 + -1;
        if (iVar2 < 1) {
          return 0;
        }
      }
    }
  }
  return uVar1;
}


// ============================================================
// Function: score_setXtraConfigValue (FUN_6804cfc0)
// Address: 6804cfc0
// Size: 313 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_setXtraConfigValue(int *param_1)
{
  uint uVar1;
  int in_EAX;
  int iVar2;
  uint *unaff_EBX;
  int unaff_ESI;
  uint local_10;
  uint local_c;
  uint local_8;
  
  local_8 = 0;
  local_c = 0;
  if (in_EAX < 2) {
    props_setError(unaff_ESI,0x19);
    return 0;
  }
  iVar2 = props_getTypedValue(unaff_ESI,2,8,&local_10);
  if (((iVar2 != 0) && ((in_EAX < 3 || (iVar2 = props_getTypedValue(unaff_ESI,3,4,&local_8), iVar2 != 0))))
     && ((in_EAX < 4 || (iVar2 = props_getTypedValue(unaff_ESI,4,4,&local_c), iVar2 != 0)))) {
    switch(local_10) {
    case 0x20:
      iVar2 = 0;
      break;
    case 0x21:
      iVar2 = 1;
      break;
    case 0x22:
      iVar2 = 2;
      break;
    case 0x23:
    case 0x112:
      iVar2 = 3;
      break;
    default:
      props_reportError(unaff_ESI,0x37);
      return 0;
    }
    *(uint *)(*param_1 + (iVar2 * 3 + 6) * 4) = local_8;
    *(uint *)(*param_1 + 0x1c + iVar2 * 0xc) = local_c;
    uVar1 = DAT_6819776c;
    if (unaff_EBX != (uint *)0x0) {
      _DAT_68197764 =
           (uint *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
                   *(int *)(unaff_ESI + 0x18));
      if (_DAT_68197764 == (uint *)0x0) {
        *unaff_EBX = DAT_68197768;
        unaff_EBX[1] = uVar1;
        props_retainValue(unaff_ESI,unaff_EBX);
        return 0;
      }
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      uVar1 = ((int *)(size_t)_DAT_68197764)[1];
      *unaff_EBX = *(int *)(size_t)_DAT_68197764;
      unaff_EBX[1] = uVar1;
      props_retainValue(unaff_ESI,unaff_EBX);
      return 0;
    }
  }
  return 0;
}


// ============================================================
// Function: score_applyXtraPattern (FUN_6804d210)
// Address: 6804d210
// Size: 268 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_applyXtraPattern(int *param_1)
{
  uint *puVar1;
  int iVar2;
  int unaff_ESI;
  undefined4 local_48;
  int *local_44;
  uint local_40;
  int *local_3c;
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
  
  iVar2 = *param_1;
  local_38 = *(int *)(iVar2 + 0x18);
  local_34 = *(undefined4 *)(iVar2 + 0x1c);
  local_30 = *(undefined4 *)(iVar2 + 0x20);
  local_2c = *(undefined4 *)(iVar2 + 0x24);
  local_28 = *(undefined4 *)(iVar2 + 0x28);
  local_24 = *(undefined4 *)(iVar2 + 0x2c);
  local_20 = *(undefined4 *)(iVar2 + 0x30);
  local_1c = *(undefined4 *)(iVar2 + 0x34);
  local_18 = *(undefined4 *)(iVar2 + 0x38);
  local_14 = *(undefined4 *)(iVar2 + 0x3c);
  local_10 = *(undefined4 *)(iVar2 + 0x40);
  local_c = *(undefined4 *)(iVar2 + 0x44);
  local_48 = *(undefined4 *)(iVar2 + 0x10);
  local_40 = *(uint *)(iVar2 + 8);
  local_3c = *(int **)(iVar2 + 0xc);
  if (local_40 == 0) {
    if (*(int *)(iVar2 + 0x14) == 6) {
      core_getMemberValuePair(unaff_ESI,&local_48,&local_40);
    }
    else {
      puVar1 = props_dispatchVariable(unaff_ESI,*(int *)(iVar2 + 0x14),(int)(short)local_48,0);
      if (puVar1 == (uint *)0x0) goto LAB_6804d2fc;
      local_40 = *puVar1;
      local_3c = (int *)puVar1[1];
      props_retainValue(unaff_ESI,&local_40);
    }
  }
  else {
    *(undefined4 *)(iVar2 + 8) = 0;
  }
  if (*(int *)(unaff_ESI + 0x7c) == 0) {
    iVar2 = props_validateString(unaff_ESI,(int *)&local_40);
    if (iVar2 != 0) {
      score_extractSubstring(unaff_ESI,&local_38,(int *)&local_40,local_44);
    }
  }
LAB_6804d2fc:
  props_releaseValue(unaff_ESI,(byte)local_40,local_3c);
  return 0;
}


// ============================================================
// Function: score_formatXtraString (FUN_6804d320)
// Address: 6804d320
// Size: 249 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall score_formatXtraString(void *this,int param_1)
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int *unaff_EBX;
  int unaff_ESI;
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
  
  if (*(int *)(*unaff_EBX + 8) != 0) {
    props_setError(unaff_ESI,0x13);
    return 0;
  }
  if (1 < (int)this) {
    iVar2 = props_getInt(unaff_ESI);
    if ((int)this <= iVar2) {
      puVar3 = (uint *)(**(int **)(unaff_ESI + 0x10) + -8 +
                        ((int)this - *(int *)(unaff_ESI + 0x20)) * 8 + *(int *)(unaff_ESI + 0x18));
      uVar1 = *puVar3;
      *puVar3 = 0;
      iVar2 = *unaff_EBX;
      local_38 = *(int *)(iVar2 + 0x18);
      local_34 = *(undefined4 *)(iVar2 + 0x1c);
      local_30 = *(undefined4 *)(iVar2 + 0x20);
      local_2c = *(undefined4 *)(iVar2 + 0x24);
      local_28 = *(undefined4 *)(iVar2 + 0x28);
      local_24 = *(undefined4 *)(iVar2 + 0x2c);
      local_20 = *(undefined4 *)(iVar2 + 0x30);
      local_1c = *(undefined4 *)(iVar2 + 0x34);
      local_18 = *(undefined4 *)(iVar2 + 0x38);
      local_14 = *(undefined4 *)(iVar2 + 0x3c);
      local_10 = *(undefined4 *)(iVar2 + 0x40);
      local_c = *(undefined4 *)(iVar2 + 0x44);
      local_3c = *(undefined4 *)(iVar2 + 0x10);
      score_formatStringEx(unaff_ESI,*(int *)(iVar2 + 0x14) + param_1,&local_38,&local_3c,uVar1,
                   (int *)puVar3[1]);
      return 0;
    }
  }
  props_reportError(unaff_ESI,0x19);
  return 0;
}


// ============================================================
// Function: score_dispatchXtraRegex (FUN_6804d420)
// Address: 6804d420
// Size: 182 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispatchXtraRegex(int *param_1)
{
  int in_EAX;
  int iVar1;
  byte *pbVar2;
  undefined4 *unaff_EBX;
  byte local_10 [4];
  int *local_c;
  uint local_8;
  
  iVar1 = props_getTypedValue(in_EAX,2,8,&local_8);
  if (iVar1 != 0) {
    switch(local_8) {
    case 0x20:
    case 0x114:
      iVar1 = 1;
      break;
    case 0x21:
    case 0x115:
      iVar1 = 2;
      break;
    case 0x22:
    case 0x116:
      iVar1 = 3;
      break;
    case 0x23:
    case 0x112:
    case 0x113:
    case 0x117:
      iVar1 = 4;
      break;
    default:
      props_setError(in_EAX,5);
      return 0;
    }
    score_applyXtraPattern(param_1);
    if (*(int *)(in_EAX + 0x7c) == 0) {
      *unaff_EBX = 4;
      pbVar2 = (byte *)props_getStringData((int *)local_10,(int *)&param_1);
      props_invokeBuiltin(in_EAX,iVar1,(int)unaff_EBX,pbVar2,(int)param_1);
      props_unlockString((int *)local_10);
      props_releaseValue(in_EAX,local_10[0],local_c);
      return 0;
    }
  }
  return 0;
}


// ============================================================
// Function: score_deleteXtraMatch (FUN_6804d5f0)
// Address: 6804d5f0
// Size: 163 bytes
// Params: void * this, int * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall score_deleteXtraMatch(void *this,int *param_1)
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
  score_deleteMatchedRange((int)this,*(uint *)(iVar1 + 0x14),&local_38,&local_3c);
  return 0;
}


