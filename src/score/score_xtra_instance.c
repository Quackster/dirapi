// Module: score
// Topic: Xtra instance management and configuration
// Address range: 0x6804c080 - 0x6804c820
// Functions (13):
//   score_markInstanceDirty (FUN_6804c080)
//   score_cleanupInstance (FUN_6804c0a0)
//   score_serializeInstance (FUN_6804c0e0)
//   score_isXtraInstance (FUN_6804c120)
//   score_findInstanceByName (FUN_6804c140)
//   score_detachInstanceChannels (FUN_6804c2b0)
//   score_removeInstance (FUN_6804c330)
//   score_resolveInstance (FUN_6804c400)
//   score_getOrCreateInstance (FUN_6804c4e0)
//   score_setInstanceValue (FUN_6804c5b0)
//   score_registerInstance (FUN_6804c6b0)
//   score_setInstanceProperty (FUN_6804c7b0)
//   score_initXtraConfig (FUN_6804c820)

// ============================================================
// Function: score_markInstanceDirty (FUN_6804c080)
// Address: 6804c080
// Size: 19 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_markInstanceDirty(undefined4 param_1,int *param_2)
{
  *(uint *)(*param_2 + 4) = *(uint *)(*param_2 + 4) | 0x80000000;
  return 0;
}


// ============================================================
// Function: score_cleanupInstance (FUN_6804c0a0)
// Address: 6804c0a0
// Size: 56 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_cleanupInstance(int param_1,int *param_2)
{
  if (*(int *)(*param_2 + 0x24) != 0) {
    score_releaseScriptResources(param_1);
  }
  props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x18),*(int **)(*param_2 + 0x1c));
  *(undefined4 *)(*param_2 + 0x18) = 0;
  return 0;
}


// ============================================================
// Function: score_serializeInstance (FUN_6804c0e0)
// Address: 6804c0e0
// Size: 63 bytes
// Params: undefined4 * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_serializeInstance(undefined4 *param_1,int *param_2)
{
  uint uVar1;
  int local_c;
  undefined4 local_8;
  
  uVar1 = stage_serializeData(param_1,param_2,0,0xe,1);
  if (uVar1 == 0) {
    local_c = *(int *)(*param_2 + 0x18);
    local_8 = *(undefined4 *)(*param_2 + 0x1c);
    stage_serializeFloat(param_1,&local_c);
  }
  return 0;
}


// ============================================================
// Function: score_isXtraInstance (FUN_6804c120)
// Address: 6804c120
// Size: 27 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_isXtraInstance(void)

{
  int *in_EAX;
  
  if ((*in_EAX == 3) && ((undefined **)**(int **)in_EAX[1] == &PTR_LAB_6818d868)) {
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_findInstanceByName (FUN_6804c140)
// Address: 6804c140
// Size: 360 bytes
// Params: undefined4 param_1, undefined4 param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_findInstanceByName(undefined4 param_1,undefined4 param_2,uint *param_3)
{
  bool bVar1;
  ushort uVar2;
  ushort uVar3;
  int iVar4;
  int iVar5;
  undefined3 extraout_var;
  int unaff_ESI;
  int local_81c;
  undefined4 local_818;
  uint *local_814;
  uint local_810;
  int *local_80c;
  byte local_808;
  undefined1 local_807 [1023];
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_814 = param_3;
  props_toPascalString(&param_1,&local_408);
  iVar4 = props_getListLength(unaff_ESI,*(int **)(**(int **)(unaff_ESI + 8) + 0x514));
  do {
    iVar4 = iVar4 + -1;
    if (iVar4 < 0) {
      return 0;
    }
    props_getListEntry(unaff_ESI,*(int **)(**(int **)(unaff_ESI + 8) + 0x514),iVar4,&local_810);
    iVar5 = score_isXtraInstance();
    if (iVar5 != 0) {
      local_81c = *(int *)(*local_80c + 0x18);
      local_818 = *(undefined4 *)(*local_80c + 0x1c);
      if ((local_81c == 0x40) || (local_81c == 0x43)) {
        props_toPascalString(&local_81c,&local_808);
        if (local_408 == 0xff) {
          uVar2 = Ordinal_1201(local_407);
        }
        else {
          uVar2 = (ushort)local_408;
        }
        if (local_808 == 0xff) {
          uVar3 = Ordinal_1201(local_807);
        }
        else {
          uVar3 = (ushort)local_808;
        }
        bVar1 = Ordinal_966(local_807,local_407,(int)(short)uVar3,(int)(short)uVar2);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          *local_814 = local_810;
          local_814[1] = (uint)local_80c;
          return 0;
        }
      }
    }
    props_releaseValue(unaff_ESI,(byte)local_810,local_80c);
  } while( true );
}


// ============================================================
// Function: score_detachInstanceChannels (FUN_6804c2b0)
// Address: 6804c2b0
// Size: 115 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_detachInstanceChannels(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int unaff_EDI;
  int local_8;
  
  local_8 = *(int *)(**(int **)(**(int **)(unaff_EDI + 8) + 0x4e8) + 0x14);
  if (-1 < local_8 + -1) {
    iVar3 = 0;
    do {
      iVar1 = **(int **)(**(int **)(unaff_EDI + 8) + 0x4e8);
      iVar2 = *(int *)(iVar1 + 0x24 + iVar3);
      iVar1 = iVar1 + 0x24 + iVar3;
      if (((iVar2 != -1) && (*(int *)(iVar1 + 8) == 3)) && (*(int **)(iVar1 + 0xc) == param_1)) {
        *(undefined4 *)(iVar1 + 8) = 0;
        *(undefined4 *)(iVar1 + 0xc) = 0;
        props_releaseObject(unaff_EDI,param_1);
        core_notifyAsyncXtra(unaff_EDI,(int *)0x0,iVar2,0);
      }
      iVar3 = iVar3 + 0x10;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return 0;
}


// ============================================================
// Function: score_removeInstance (FUN_6804c330)
// Address: 6804c330
// Size: 194 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_removeInstance(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint local_c;
  int *local_8;
  
  piVar1 = *(int **)(**(int **)(param_1 + 8) + 0x514);
  if (piVar1 == (int *)0x0) {
    return 1;
  }
  iVar2 = props_getListLength(param_1,piVar1);
  do {
    iVar2 = iVar2 + -1;
    if (iVar2 < 0) {
      return 1;
    }
    props_getListEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x514),iVar2,&local_c);
    iVar3 = score_isXtraInstance();
    if ((iVar3 != 0) && (iVar3 = *local_8, *(int *)(iVar3 + 0x20) == param_2)) {
      if (0 < *(int *)(iVar3 + 0x14)) {
        props_setError(param_1,0x60);
        return 0;
      }
      if ((*(byte *)(iVar3 + 0x10) & 1) != 0) {
        score_detachInstanceChannels(local_8);
      }
      score_releaseScriptResources(param_1);
      props_setListRange(param_1,*(int **)(**(int **)(param_1 + 8) + 0x514),iVar2);
    }
    props_releaseValue(param_1,(byte)local_c,local_8);
  } while( true );
}


// ============================================================
// Function: score_resolveInstance (FUN_6804c400)
// Address: 6804c400
// Size: 140 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall score_resolveInstance(int param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  int iVar2;
  uint *unaff_EBX;
  
  *unaff_EBX = 2;
  unaff_EBX[1] = 0;
  switch(*in_EAX) {
  case 1:
  case 0x40:
  case 0x43:
    iVar2 = score_findInstanceByName(*in_EAX,in_EAX[1],unaff_EBX);
    if (iVar2 != 0) {
      return 1;
    }
    break;
  default:
    props_setErrorAndReturn(param_1,10);
    break;
  case 4:
    iVar2 = in_EAX[1] + -1;
    if ((-1 < iVar2) &&
       (iVar1 = props_getListLength(param_1,*(int **)(**(int **)(param_1 + 8) + 0x514)), iVar2 < iVar1)) {
      props_getListEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x514),iVar2,unaff_EBX);
      return 1;
    }
  }
  return 0;
}


// ============================================================
// Function: score_getOrCreateInstance (FUN_6804c4e0)
// Address: 6804c4e0
// Size: 205 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_getOrCreateInstance(int param_1)
{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  _DAT_68197764 =
       **(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18);
  if (_DAT_68197764 != 0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
  }
  if ((*(int *)(**(int **)(param_1 + 8) + 0x514) == 0) ||
     (iVar1 = score_resolveInstance(param_1), iVar1 == 0)) {
    if (*(int *)(param_1 + 0xe0) != 0) {
      local_c = 2;
      local_8 = 0;
      props_popArgs(param_1,&local_c);
      return 0;
    }
    if (*(int *)(param_1 + 0x7c) == 0) {
      props_setErrorAndReturn(param_1,0x4b);
      return 0;
    }
  }
  else {
    props_popArgs(param_1,&local_c);
  }
  return 0;
}


// ============================================================
// Function: score_setInstanceValue (FUN_6804c5b0)
// Address: 6804c5b0
// Size: 241 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_setInstanceValue(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_14;
  undefined4 *local_10;
  int *local_8;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 < 1) {
    props_setError(param_1,0x15);
    return 0;
  }
  _DAT_68197764 =
       (undefined4 *)
       (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18));
  if (_DAT_68197764 == (undefined4 *)0x0) {
    local_8 = DAT_6819776c;
    uVar3 = DAT_68197768;
  }
  else {
    DAT_6819776c = (int *)0x0;
    DAT_68197768 = 0;
    local_8 = (int *)((int *)(size_t)_DAT_68197764)[1];
    uVar3 = *(int *)(size_t)_DAT_68197764;
  }
  iVar1 = score_resolveInstance(param_1);
  if (iVar1 == 0) {
    props_setErrorAndReturn(param_1,0x4b);
    return 0;
  }
  props_releaseValue(param_1,(byte)uVar3,local_8);
  puVar2 = (undefined4 *)
           (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18));
  if (puVar2 != (undefined4 *)0x0) {
    *puVar2 = local_14;
    puVar2[1] = local_10;
  }
  iVar1 = (**(code **)(*(int *)*local_10 + 4))(param_1,local_10,0x82);
  if (iVar1 == 0) {
    props_reportError(param_1,5);
  }
  return 0;
}


// ============================================================
// Function: score_registerInstance (FUN_6804c6b0)
// Address: 6804c6b0
// Size: 241 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_registerInstance(undefined4 param_1)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  uint local_c;
  undefined4 local_8;
  
  if (*(int *)(**(int **)(unaff_ESI + 8) + 0x514) == 0) {
    uVar2 = props_getRectCount(unaff_ESI);
    *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x514) = uVar2;
    if (*(int *)(**(int **)(unaff_ESI + 8) + 0x514) != 0) {
      iVar1 = **(int **)(**(int **)(unaff_ESI + 8) + 0x514);
      *(undefined4 *)(**(int **)(iVar1 + 8) + 0xc) = *(undefined4 *)(iVar1 + 0xc);
      iVar1 = **(int **)(**(int **)(unaff_ESI + 8) + 0x514);
      *(undefined4 *)(**(int **)(iVar1 + 0xc) + 8) = *(undefined4 *)(iVar1 + 8);
      iVar1 = **(int **)(unaff_ESI + 8);
      *(undefined4 *)(**(int **)(iVar1 + 0x514) + 8) =
           *(undefined4 *)(**(int **)(iVar1 + 0x55c) + 8);
      *(undefined4 *)(**(int **)(**(int **)(unaff_ESI + 8) + 0x514) + 0xc) =
           *(undefined4 *)(iVar1 + 0x55c);
      *(undefined4 *)(**(int **)(**(int **)(iVar1 + 0x55c) + 8) + 0xc) =
           *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x514);
      *(undefined4 *)(**(int **)(iVar1 + 0x55c) + 8) =
           *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x514);
    }
  }
  local_c = 3;
  local_8 = param_1;
  props_setListEntry(unaff_ESI,*(int **)(**(int **)(unaff_ESI + 8) + 0x514),&local_c);
  return 0;
}


// ============================================================
// Function: score_setInstanceProperty (FUN_6804c7b0)
// Address: 6804c7b0
// Size: 111 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_setInstanceProperty(uint param_1)
{
  uint uVar1;
  int *piVar2;
  uint *puVar3;
  uint *unaff_ESI;
  int unaff_EDI;
  uint local_8;
  
  puVar3 = score_lookupProperty(*(int **)(**(int **)(unaff_EDI + 8) + 0x4e8),param_1,1,&local_8);
  if (puVar3 == (uint *)0x0) {
    props_setError(unaff_EDI,2);
    return 0;
  }
  uVar1 = *puVar3;
  piVar2 = (int *)puVar3[1];
  *puVar3 = *unaff_ESI;
  puVar3[1] = unaff_ESI[1];
  if (uVar1 == 3) {
    props_releaseObject(unaff_EDI,piVar2);
  }
  if (*unaff_ESI == 3) {
    *(int *)(*(int *)unaff_ESI[1] + 4) = *(int *)(*(int *)unaff_ESI[1] + 4) + 1;
  }
  core_notifyAsyncXtra(unaff_EDI,(int *)0x0,param_1,1);
  return 0;
}


// ============================================================
// Function: score_initXtraConfig (FUN_6804c820)
// Address: 6804c820
// Size: 987 bytes
// Return: undefined
// Calling convention: unknown
// ============================================================
/* FIXUP(DECOMPILE-TIMEOUT): Ghidra timed out decompiling this function.
   The function body needs manual reconstruction from the binary at address 0x6804c820 (987 bytes).
   Providing minimal implementation to satisfy linker. */
int score_initXtraConfig(void)
{
  /* FIXUP(DECOMPILE-TIMEOUT): Original function at 0x6804c820 could not be decompiled.
     Reconstruct from binary: 987 bytes starting at offset 0x4c820 in dirapi_original.dll */
  return 0;
}


