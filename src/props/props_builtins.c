// Module: props
// Topic: Built-in function handlers (math, string ops, conversion)
// Address range: 0x6803f030 - 0x6803fe70
// Functions (17):
//   props_findSubstring (FUN_6803f030)
//   props_splitString (FUN_6803f0e0)
//   props_padString (FUN_6803f2b0)
//   props_accessStringVar (FUN_6803f330)
//   props_skipDelimiter (FUN_6803f4e0)
//   props_invokeBuiltin
//   props_builtinReturn (FUN_6803f6f0)
//   props_builtinAbs (FUN_6803f770)
//   props_builtinCharCount (FUN_6803f860)
//   props_builtinStringify (FUN_6803f8e0)
//   props_builtinIdentify (FUN_6803f950)
//   props_builtinCharToInt (FUN_6803f9d0)
//   props_builtinIntToChar (FUN_6803fa20)
//   props_builtinFloatValue (FUN_6803faa0)
//   props_builtinResolveScript (FUN_6803fbc0)
//   props_callBuiltinMethod
//   props_builtinParseValue (FUN_6803fe70)



// ============================================================
// Function: props_findSubstring (FUN_6803f030)
// Address: 6803f030
// Size: 173 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_findSubstring(undefined4 param_1,int *param_2,int *param_3)

{
  bool bVar1;
  int *piVar2;
  int *piVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 1;
  if (((*param_2 != 0x40) && (*param_2 != 0x43)) || ((*param_3 != 0x40 && (*param_3 != 0x43)))) {
    return -1;
  }
  piVar2 = props_getStringData(param_2,&local_c);
  piVar3 = props_getStringData(param_3,&local_10);
  iVar5 = 0;
  iVar4 = 0;
  if (local_c <= local_10) {
    do {
      bVar1 = Ordinal_966(piVar2,piVar3,local_c,local_c);
      if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_6803f0c0;
      stage_readAllocValue(piVar3,&local_8);
      iVar5 = iVar5 + local_8;
      piVar3 = (int *)((int)piVar3 + local_8);
      iVar4 = iVar4 + 1;
    } while (iVar5 + local_c <= local_10);
  }
  iVar4 = -1;
LAB_6803f0c0:
  props_unlockString(param_2);
  props_unlockString(param_3);
  return iVar4;
}



// ============================================================
// Function: props_splitString (FUN_6803f0e0)
// Address: 6803f0e0
// Size: 455 bytes
// Params: int param_1, int param_2, int * param_3, int * param_4, int * param_5, int param_6, int * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_splitString(int param_1,int param_2,int *param_3,int *param_4,int *param_5,int param_6,
                 int *param_7)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  local_14 = 1;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  if (0 < *param_3) {
    iVar4 = *param_4;
    iVar1 = *param_5;
    if (param_2 == 1) {
      local_10 = 0;
      local_c = 0x20;
      local_8 = 1;
    }
    else if (param_2 == 2) {
      local_10 = *(undefined4 *)(**(int **)(param_1 + 8) + 0x500);
      local_8 = 0;
      local_c = local_10;
    }
    else if (param_2 == 3) {
      local_10 = 0xd;
      local_c = 0xd;
      local_8 = 0;
    }
    pbVar5 = (byte *)(iVar4 + param_6);
    if (local_8 != 0) {
      for (; (iVar4 < iVar1 && (*pbVar5 < 0x21)); pbVar5 = pbVar5 + 1) {
        iVar4 = iVar4 + 1;
      }
    }
    param_2 = 1;
    param_3[2] = 1;
    if (1 < *param_3) {
      do {
        if (iVar1 <= iVar4) {
          param_2 = *param_3;
          break;
        }
        iVar2 = Ordinal_1244(pbVar5,local_10,local_c,iVar1 - iVar4);
        iVar4 = iVar1;
        if (iVar2 != 0) {
          param_3[2] = param_2 + 1;
          iVar4 = iVar2 - param_6;
        }
        pbVar5 = (byte *)(iVar4 + param_6);
        if (local_8 == 0) {
          if ((iVar2 != 0) && (iVar4 < iVar1)) {
            Ordinal_1252(pbVar5,&local_14);
            iVar4 = iVar4 + local_14;
            pbVar5 = pbVar5 + local_14;
          }
        }
        else {
          for (; (iVar4 < iVar1 && (*pbVar5 < 0x21)); pbVar5 = pbVar5 + 1) {
            iVar4 = iVar4 + 1;
          }
        }
        param_2 = param_2 + 1;
      } while (param_2 < *param_3);
    }
    iVar2 = iVar4;
    if (param_3[1] < 1) {
      param_3[1] = *param_3;
    }
    while( true ) {
      if (iVar2 < iVar1) {
        iVar3 = Ordinal_1244(pbVar5,local_10,local_c,iVar1 - iVar2);
        iVar2 = iVar1;
        if (iVar3 != 0) {
          iVar2 = iVar3 - param_6;
        }
        pbVar5 = (byte *)(iVar2 + param_6);
      }
      param_2 = param_2 + 1;
      if ((param_3[1] < param_2) || (iVar1 <= iVar2)) break;
      iVar3 = stage_getStringAllocState();
      iVar3 = iVar3 - (int)pbVar5;
      pbVar5 = pbVar5 + iVar3;
      iVar2 = iVar2 + iVar3;
      if (local_8 != 0) {
        for (; (iVar2 < iVar1 && (*pbVar5 < 0x21)); pbVar5 = pbVar5 + 1) {
          iVar2 = iVar2 + 1;
        }
      }
    }
    *param_4 = iVar4;
    *param_7 = *param_5;
    *param_5 = iVar2;
  }
  return 0;
}



// ============================================================
// Function: props_padString (FUN_6803f2b0)
// Address: 6803f2b0
// Size: 115 bytes
// Params: void * this, int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall props_padString(void *this,int param_1,undefined4 param_2)
{
  int *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *in_EAX - in_EAX[2];
  if ((0 < iVar3) && (iVar1 = props_uniquifyString(param_1,this), iVar1 != 0)) {
    param_1 = *(int *)((int)this + 4);
    iVar1 = Ordinal_1116(param_1);
    iVar2 = Ordinal_1117(&param_1,iVar1 + iVar3,0);
    if (iVar2 != 0) {
      iVar2 = **(int **)((int)this + 4) + 8;
      Ordinal_1129(iVar2 + iVar3,iVar2,iVar1 + -8);
      do {
        iVar1 = Ordinal_1247(iVar2,param_2);
        iVar3 = iVar3 + (iVar2 - iVar1);
        iVar2 = iVar1;
      } while (0 < iVar3);
    }
  }
  return 0;
}



// ============================================================
// Function: props_accessStringVar (FUN_6803f330)
// Address: 6803f330
// Size: 418 bytes
// Params: void * this, int param_1, int param_2, uint * param_3, undefined4 * param_4
// Return: int *
// Calling convention: __thiscall
// ============================================================

int * __thiscall props_accessStringVar(void *this,int param_1,int param_2,uint *param_3,undefined4 *param_4)

{
  int iVar1;
  short *in_EAX;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  int unaff_ESI;
  uint local_10;
  int *local_c;
  uint local_8;
  
  *param_4 = 0;
  if (param_1 == 6) {
    piVar2 = (int *)crt_getMemberCursor(unaff_ESI,(undefined4 *)in_EAX);
    return piVar2;
  }
  local_8 = (uint)*in_EAX;
  puVar3 = props_dispatchVariable(unaff_ESI,param_1,local_8,1);
  if (puVar3 == (uint *)0x0) {
    return (int *)0x0;
  }
  local_10 = *puVar3;
  piVar2 = (int *)puVar3[1];
  local_c = piVar2;
  if ((this == (void *)0x10) && (param_2 == 0)) {
    *puVar3 = *param_3;
    puVar3[1] = param_3[1];
    props_releaseValue(unaff_ESI,(byte)local_10,piVar2);
    return (int *)0x0;
  }
  if (local_10 == 3) {
    if (((this == (void *)0x20) || (this == (void *)0x30)) && (param_2 == 0)) {
      props_pushValue(unaff_ESI);
      puVar3 = (uint *)(unaff_ESI + 0x1c);
      *puVar3 = local_10;
      *(int **)(unaff_ESI + 0x20) = local_c;
      props_retainValue(unaff_ESI,puVar3);
      props_pushValue(unaff_ESI);
      *puVar3 = *param_3;
      *(uint *)(unaff_ESI + 0x20) = param_3[1];
      props_pushValue(unaff_ESI);
      *puVar3 = 4;
      *(undefined4 *)(unaff_ESI + 0x20) = 2;
      iVar4 = (**(code **)(*(int *)*piVar2 + 4))();
      if (iVar4 != 0) {
        return (int *)0x0;
      }
      *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
      iVar4 = *(int *)(unaff_ESI + 0x18);
      iVar1 = **(int **)(unaff_ESI + 0x10);
      *puVar3 = *(uint *)(iVar1 + iVar4);
      iVar5 = iVar4 + -8;
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(iVar1 + 4 + iVar4);
      *(int *)(unaff_ESI + 0x18) = iVar5;
      iVar4 = **(int **)(unaff_ESI + 0x10);
      *puVar3 = *(uint *)(iVar4 + iVar5);
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(iVar4 + 4 + iVar5);
      props_popValue(unaff_ESI);
    }
  }
  else if ((local_10 == 0x40) || (local_10 == 0x43)) goto LAB_6803f490;
  props_getStringLength(unaff_ESI,(int *)&local_10);
LAB_6803f490:
  iVar4 = props_uniquifyString(unaff_ESI,(int *)&local_10);
  if (iVar4 == 0) {
    return (int *)0x0;
  }
  puVar3 = props_dispatchVariable(unaff_ESI,param_1,local_8,0);
  if (puVar3 != (uint *)0x0) {
    *puVar3 = local_10;
    puVar3[1] = (uint)local_c;
  }
  *param_4 = 8;
  return local_c;
}



// ============================================================
// Function: props_skipDelimiter (FUN_6803f4e0)
// Address: 6803f4e0
// Size: 199 bytes
// Params: int param_1, int * param_2, int param_3, int * param_4, int * param_5, int param_6
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
props_skipDelimiter(int param_1,int *param_2,int param_3,int *param_4,int *param_5,int param_6)

{
  bool bVar1;
  int *piVar2;
  undefined4 in_EAX;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  piVar2 = param_5;
  bVar1 = false;
  iVar6 = 0;
  if (*param_2 < 1) {
    return 0;
  }
  switch(in_EAX) {
  case 0:
    goto switchD_6803f501_caseD_0;
  case 1:
    bVar1 = true;
    break;
  case 2:
    iVar6 = *(int *)(**(int **)(param_3 + 8) + 0x500);
    bVar1 = false;
    break;
  case 3:
    iVar6 = 0xd;
    bVar1 = false;
  }
  pbVar3 = (byte *)(param_6 + *param_5);
  if (bVar1) {
    if (*param_5 < param_1) {
      while (*pbVar3 < 0x21) {
        *param_5 = *param_5 + 1;
        pbVar3 = pbVar3 + 1;
        if (param_1 <= *param_5) {
          return 1;
        }
      }
    }
  }
  else {
    iVar4 = Ordinal_1252(pbVar3,&param_5);
    iVar5 = *piVar2;
    if ((iVar5 < (param_1 - (int)param_5) + 1) && (iVar4 == iVar6)) {
      *piVar2 = iVar5 + (int)param_5;
      return 1;
    }
    if (0 < *param_4) {
      iVar5 = *param_4 + -1;
      *param_4 = iVar5;
      iVar5 = Ordinal_1252(iVar5 + param_6,&param_5);
      if (iVar5 != iVar6) {
        *param_4 = *param_4 + (int)param_5;
      }
    }
  }
switchD_6803f501_caseD_0:
  return 1;
}



// ============================================================
// Function: props_invokeBuiltin (FUN_6803f5c0)
// Address: 6803f5c0
// Size: 288 bytes
// Params: int param_1, int param_2, int param_3, byte * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_invokeBuiltin(int param_1,int param_2,int param_3,byte *param_4,int param_5)
{
  int iVar1;
  byte *pbVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  byte *pbVar7;
  
  iVar1 = param_5;
  switch(param_2) {
  case 2:
    param_2 = 0x20;
    break;
  case 3:
    param_2 = *(int *)(**(int **)(param_1 + 8) + 0x500);
    if (param_2 != 0) break;
  default:
    uVar3 = stage_getDateState();
    *(undefined4 *)(param_3 + 4) = uVar3;
    return 0;
  case 4:
    param_2 = 0xd;
  }
  iVar5 = 0;
  pbVar6 = param_4;
  if (param_2 != 0x20) {
LAB_6803f659:
    param_4 = (byte *)0x1;
  }
  else if (param_5 < 1) {
LAB_6803f650:
    param_4 = (byte *)0x0;
  }
  else {
    do {
      if (0x20 < *param_4) {
        pbVar6 = param_4;
        if (iVar5 < param_5) goto LAB_6803f659;
        goto LAB_6803f650;
      }
      iVar5 = iVar5 + 1;
      pbVar6 = param_4 + 1;
      param_4 = pbVar6;
    } while (iVar5 < param_5);
    param_4 = (byte *)0x0;
  }
  pbVar2 = param_4;
  if (param_5 <= iVar5) {
    *(byte **)(param_3 + 4) = param_4;
    return 0;
  }
LAB_6803f670:
  do {
    param_4 = pbVar2;
    if (param_2 != 0x20) {
      iVar4 = Ordinal_1252(pbVar6,&param_5);
      if (iVar4 == param_2) {
        param_4 = param_4 + 1;
      }
      pbVar7 = pbVar6 + param_5;
      iVar5 = iVar5 + param_5;
    }
    else {
      pbVar7 = pbVar6 + 1;
      iVar5 = iVar5 + 1;
      if (*pbVar6 < 0x21) {
        for (; iVar5 < iVar1; iVar5 = iVar5 + 1) {
          if (0x20 < *pbVar7) {
            pbVar6 = pbVar7;
            pbVar2 = param_4 + 1;
            if (iVar5 < iVar1) goto LAB_6803f670;
            break;
          }
          pbVar7 = pbVar7 + 1;
        }
      }
    }
    pbVar6 = pbVar7;
    pbVar2 = param_4;
    if (iVar1 <= iVar5) {
      *(byte **)(param_3 + 4) = param_4;
      return 0;
    }
  } while( true );
}



// ============================================================
// Function: props_builtinReturn (FUN_6803f6f0)
// Address: 6803f6f0
// Size: 126 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_builtinReturn(int param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = props_getInt(param_1);
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    if (iVar3 != 1) {
      props_setError(param_1,0x15);
      return 0;
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    iVar3 = **(int **)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x18));
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  if (*(int *)(param_1 + 0x40) + 0x34 < *(int *)(param_1 + 0x18)) {
    uVar1 = *(undefined4 *)(param_1 + 0x1c);
    uVar2 = *(undefined4 *)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x1c) = 2;
    props_unwindStack(param_1);
    *(undefined4 *)(param_1 + 0x20) = uVar2;
    *(undefined4 *)(param_1 + 0x1c) = uVar1;
  }
  *(undefined4 *)(param_1 + 0x74) = 1;
  return 0;
}



// ============================================================
// Function: props_builtinAbs (FUN_6803f770)
// Address: 6803f770
// Size: 182 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_builtinAbs(int param_1)
{
  float fVar1;
  int *piVar2;
  float10 fVar3;
  double dVar4;
  int local_c;
  int local_8;
  
  piVar2 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  local_c = *piVar2;
  switch(local_c) {
  case 4:
    local_8 = piVar2[1];
    if (local_8 < 0) {
      local_8 = -local_8;
      props_popArgs(param_1,&local_c);
      return 0;
    }
    break;
  default:
    local_c = 4;
    local_8 = 0;
    break;
  case 9:
  case 0x20:
  case 0x23:
    if (local_c == 0x20) {
      fVar1 = (float)(size_t)piVar2[1];
    }
    else {
      fVar1 = (float)*(double *)(*(int *)piVar2[1] + 8);
    }
    dVar4 = (double)fVar1;
    fVar3 = (float10)Ordinal_1520(dVar4,&local_c);
    props_storeNumber(param_1,(double)fVar3,SUB84(dVar4,0));
    props_popArgs(param_1,&local_c);
    return 0;
  }
  props_popArgs(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: props_builtinCharCount (FUN_6803f860)
// Address: 6803f860
// Size: 119 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_builtinCharCount(int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_1;
  local_14 = 4;
  local_10 = 0;
  piVar3 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  iVar1 = *piVar3;
  if ((iVar1 == 0x40) || (iVar1 == 0x43)) {
    local_8 = piVar3[1];
    local_c = iVar1;
    props_getStringData(&local_c,&param_1);
    local_10 = stage_getDateState();
    props_unlockString(&local_c);
  }
  props_popArgs(iVar2,&local_14);
  return 0;
}



// ============================================================
// Function: props_builtinStringify (FUN_6803f8e0)
// Address: 6803f8e0
// Size: 112 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int props_builtinStringify(int param_1)
{
  uint local_c;
  uint local_8;
  
  _DAT_68197764 =
       (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
               *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (uint *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  props_retainValue(param_1,&local_c);
  props_getStringLength(param_1,(int *)&local_c);
  props_popArgs(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: props_builtinIdentify (FUN_6803f950)
// Address: 6803f950
// Size: 122 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int props_builtinIdentify(int param_1)
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
  iVar1 = stage_resolveIdentifier(param_1,&local_c);
  if (iVar1 == 0) {
    local_c = 2;
    local_8 = 0;
  }
  props_popArgs(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: props_builtinCharToInt (FUN_6803f9d0)
// Address: 6803f9d0
// Size: 76 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_builtinCharToInt(int param_1)
{
  int iVar1;
  int *piVar2;
  uint local_c [2];
  
  iVar1 = props_getValueDirect(param_1,1,1,local_c);
  if (iVar1 != 0) {
    piVar2 = props_getStringData((int *)local_c,(int *)0x0);
    iVar1 = Ordinal_1283(piVar2,0xffffffff);
    props_unlockString((int *)local_c);
    props_normalizeType(param_1,4,iVar1);
  }
  return 0;
}



// ============================================================
// Function: props_builtinIntToChar (FUN_6803fa20)
// Address: 6803fa20
// Size: 124 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_builtinIntToChar(int param_1)
{
  undefined4 local_410 [2];
  byte local_408 [1024];
  uint local_8;
  
  local_408[0] = 0;
  local_408[1] = 0;
  Ordinal_1284(*(undefined4 *)
                (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                 *(int *)(param_1 + 0x18) + 4));
  stage_endDateScope();
  props_readPascalString(param_1,local_408,local_410);
  props_popArgs(param_1,local_410);
  return 0;
}



// ============================================================
// Function: props_builtinFloatValue (FUN_6803faa0)
// Address: 6803faa0
// Size: 274 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_builtinFloatValue(int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined4 extraout_ECX;
  float10 fVar6;
  undefined8 uVar7;
  ulonglong uVar8;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int *local_8;
  
  piVar3 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  iVar1 = *piVar3;
  if (iVar1 != 4) {
    local_c = *piVar3;
    local_8 = (int *)piVar3[1];
    iVar4 = props_getStringRef(param_1,&local_c);
    iVar5 = **(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8;
    iVar2 = *(int *)(param_1 + 0x18);
    *(int *)(iVar5 + iVar2) = local_c;
    *(int **)(iVar5 + 4 + iVar2) = local_8;
    if (iVar4 == 0) {
      props_setErrorAndReturn(param_1,8);
      return 0;
    }
    piVar3 = local_8;
    if (local_c != 0x20) {
      /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): piVar3 = (int *)(float)*(double *)(*local_8 + 8); */
    }
  }
  else {
    /* FIXUP(C2440: 'type cast': cannot convert from 'float' to 'int *'): piVar3 = (int *)(float)(size_t)piVar3[1]; */
  }
  fVar6 = (float10)Ordinal_1522((double)(float)(size_t)piVar3);
  uVar7 = Ordinal_1523((double)fVar6);
  if (((int)uVar7 == 0) && (iVar1 == 4)) {
    local_14 = 4;
    uVar8 = props_floatToLongLong(extraout_ECX,(int)((ulonglong)uVar7 >> 0x20),(double)fVar6);
    local_10 = (undefined4)uVar8;
    props_popArgs(param_1,&local_14);
    return 0;
  }
  props_storeNumber(param_1,(double)fVar6,&local_14);
  props_popArgs(param_1,&local_14);
  return 0;
}



// ============================================================
// Function: props_builtinResolveScript (FUN_6803fbc0)
// Address: 6803fbc0
// Size: 178 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int props_builtinResolveScript(int param_1)
{
  uint *puVar1;
  uint local_14;
  uint local_10;
  int local_c;
  uint local_8;
  
  local_14 = 4;
  local_10 = 0;
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
  stage_resolveIdentifier(param_1,&local_c);
  if ((((local_c == 8) && (0x2e < (int)local_8)) &&
      (puVar1 = score_lookupProperty(*(int **)(**(int **)(param_1 + 8) + 0x4e8),local_8,0,(uint *)0x0),
      puVar1 != (uint *)0x0)) && (*puVar1 == 6)) {
    local_14 = *puVar1;
    local_10 = puVar1[1];
  }
  props_popArgs(param_1,&local_14);
  return 0;
}



// ============================================================
// Function: props_callBuiltinMethod (FUN_6803fc80)
// Address: 6803fc80
// Size: 496 bytes
// Params: undefined4 param_1, int param_2, int param_3, byte * param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall props_callBuiltinMethod(undefined4 param_1,int param_2,int param_3,byte *param_4)
{
  float fVar1;
  int iVar2;
  bool bVar3;
  ushort uVar4;
  int *piVar5;
  ulonglong uVar6;
  int local_86c;
  int local_868;
  int local_864 [4];
  int local_854;
  byte local_848;
  char local_847;
  byte local_408 [1024];
  uint local_8;
  
  iVar2 = *(int *)param_4;
  bVar3 = false;
  piVar5 = (int *)0x80040014;
  local_86c = 0;
  local_868 = 0;
  if ((iVar2 == 0x20) || (iVar2 == 0x23)) {
    local_86c = 4;
    if (iVar2 == 0x20) {
      fVar1 = *(float *)(param_4 + 4);
    }
    else {
      piVar5 = *(int **)(param_4 + 4);
      param_2 = *piVar5;
      fVar1 = (float)*(double *)(param_2 + 8);
    }
    uVar6 = props_floatToLongLong(piVar5,param_2,(double)fVar1);
    local_868 = (int)uVar6;
  }
  else {
    if ((iVar2 != 0x40) && (iVar2 != 0x43)) {
      if (iVar2 == 4) {
        return 0;
      }
      return 0;
    }
    props_toPascalString((int *)param_4,local_408);
    if (local_408[0] == 0xff) {
      uVar4 = Ordinal_1201();
    }
    else {
      uVar4 = (ushort)local_408[0];
    }
    if (uVar4 != 0) {
      props_parseIdentifier(local_864,local_408);
      props_parseExpression(param_3,local_864);
      if (local_848 == 0xff) {
        uVar4 = Ordinal_1201();
      }
      else {
        uVar4 = (ushort)local_848;
      }
      if ((uVar4 == 1) && (local_847 == '-')) {
        bVar3 = true;
        props_parseExpression(param_3,local_864);
        if (local_848 == 0xff) {
          uVar4 = Ordinal_1201();
        }
        else {
          uVar4 = (ushort)local_848;
        }
      }
      if ((short)uVar4 == local_854) {
        Ordinal_950((int)&local_848,&local_868);
        local_86c = 4;
        if (bVar3) {
          local_868 = -local_868;
        }
        goto LAB_6803fe0b;
      }
    }
  }
  if (local_86c != 4) {
    return 0;
  }
LAB_6803fe0b:
  if ((*param_4 & 1) != 0) {
    props_releaseValue(param_3,(byte)*(undefined4 *)param_4,*(int **)(param_4 + 4));
  }
  *(int *)param_4 = local_86c;
  *(int *)(param_4 + 4) = local_868;
  return 0;
}



// ============================================================
// Function: props_builtinParseValue (FUN_6803fe70)
// Address: 6803fe70
// Size: 465 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_builtinParseValue(int param_1)
{
  float fVar1;
  bool bVar2;
  ushort uVar3;
  int *piVar4;
  int iVar5;
  ulonglong uVar6;
  undefined4 local_86c;
  int local_868;
  int local_864 [4];
  int local_854;
  byte local_848;
  char local_847;
  byte local_408 [1024];
  uint local_8;
  
  local_86c = 4;
  piVar4 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  iVar5 = *piVar4;
  if (iVar5 == 4) {
    local_868 = piVar4[1];
  }
  else {
    if (iVar5 == 0x20) {
      fVar1 = (float)(size_t)piVar4[1];
      iVar5 = 0x20;
    }
    else {
      if (iVar5 != 0x23) {
        if ((iVar5 == 0x40) || (iVar5 == 0x43)) {
          bVar2 = false;
          local_86c = 2;
          local_868 = 0;
          props_toPascalString(piVar4,local_408);
          if (local_408[0] == 0xff) {
            uVar3 = Ordinal_1201();
          }
          else {
            uVar3 = (ushort)local_408[0];
          }
          if (uVar3 != 0) {
            props_parseIdentifier(local_864,local_408);
            props_parseExpression(param_1,local_864);
            if (local_848 == 0xff) {
              uVar3 = Ordinal_1201();
            }
            else {
              uVar3 = (ushort)local_848;
            }
            iVar5 = (int)(short)uVar3;
            if ((iVar5 == 1) && (local_847 == '-')) {
              props_parseExpression(param_1,local_864);
              if (local_848 == 0xff) {
                uVar3 = Ordinal_1201();
              }
              else {
                uVar3 = (ushort)local_848;
              }
              iVar5 = (int)(short)uVar3;
              bVar2 = true;
            }
            if (iVar5 == local_854) {
              Ordinal_950((int)&local_848,&local_868);
              local_86c = 4;
              if (bVar2) {
                local_868 = -local_868;
              }
            }
          }
        }
        else if (iVar5 == 3) {
          local_86c = 4;
          (**(code **)(**(int **)piVar4[1] + 0x14))(param_1,(undefined4 *)piVar4[1]);
        }
        else {
          local_86c = 2;
          local_868 = 0;
        }
        goto LAB_68040022;
      }
      iVar5 = *(int *)piVar4[1];
      fVar1 = (float)*(double *)(iVar5 + 8);
    }
    uVar6 = props_floatToLongLong(iVar5,*(int **)(param_1 + 0x10),(double)fVar1);
    local_868 = (int)uVar6;
  }
LAB_68040022:
  props_popArgs(param_1,&local_86c);
  return 0;
}


