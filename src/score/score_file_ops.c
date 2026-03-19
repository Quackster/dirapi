// Module: score
// Topic: File I/O and media file operations
// Address range: 0x6804de40 - 0x6804e220
// Functions (7):
//   score_truncateString (FUN_6804de40)
//   score_openFileWithProps (FUN_6804dea0)
//   score_buildFilePath (FUN_6804dfa0)
//   score_serializeFileData (FUN_6804e040)
//   score_readFileToString (FUN_6804e140)
//   score_advanceFilePos (FUN_6804e1f0)
//   score_getFileStatus (FUN_6804e220)

// ============================================================
// Function: score_truncateString (FUN_6804de40)
// Address: 6804de40
// Size: 82 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool score_truncateString(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int *unaff_EDI;
  bool bVar4;
  
  *unaff_EDI = 2;
  iVar1 = Ordinal_1324();
  if (0 < iVar1) {
    iVar1 = iVar1 + -1;
  }
  iVar2 = stage_resolveString(param_1,iVar1,unaff_EDI);
  bVar4 = iVar2 == 0;
  if (!bVar4) {
    piVar3 = props_getStringData(unaff_EDI,(int *)0x0);
    *(undefined1 *)((int)piVar3 + iVar1) = 0;
    iVar1 = Ordinal_1310();
    bVar4 = iVar1 == 0;
    props_unlockString(unaff_EDI);
  }
  return bVar4;
}


// ============================================================
// Function: score_openFileWithProps (FUN_6804dea0)
// Address: 6804dea0
// Size: 244 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint score_openFileWithProps(int param_1,undefined4 param_2,uint param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 *unaff_ESI;
  uint local_14 [2];
  uint local_c;
  int *local_8;
  uint uVar3;
  
  if (param_3 != 0) {
    iVar2 = score_deleteProplistEntry(param_1,3);
    uVar3 = (uint)(iVar2 == 0);
    unaff_ESI[1] = iVar2;
    if (uVar3 == 0) {
      *unaff_ESI = 3;
      bVar1 = score_truncateString(param_1);
      uVar3 = CONCAT31(extraout_var,bVar1);
      if (uVar3 == 0) {
        local_14[0] = 8;
        local_14[1] = 0x103;
        score_updateProplistRange(param_1,(int *)unaff_ESI[1],local_14,&local_c);
        props_releaseValue(param_1,(byte)local_c,local_8);
        local_8 = (int *)(param_3 >> 1 & 1);
        local_c = 4;
        local_14[0] = 8;
        local_14[1] = 0x14f;
        score_updateProplistRange(param_1,(int *)unaff_ESI[1],local_14,&local_c);
        local_8 = (int *)(~(param_3 >> 2) & 1);
        local_14[0] = 8;
        local_14[1] = 0x150;
        score_updateProplistRange(param_1,(int *)unaff_ESI[1],local_14,&local_c);
      }
    }
    return uVar3;
  }
  *unaff_ESI = 2;
  unaff_ESI[1] = 0;
  return 0;
}


// ============================================================
// Function: score_buildFilePath (FUN_6804dfa0)
// Address: 6804dfa0
// Size: 155 bytes
// Params: uint * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint score_buildFilePath(uint *param_1)

{
  int in_EAX;
  int iVar1;
  uint uVar2;
  int local_30 [8];
  int local_10;
  uint local_c;
  uint local_8;
  
  *param_1 = 2;
  param_1[1] = 0;
  local_c = 4;
  local_8 = 0x10;
  iVar1 = props_getTypedProperty(in_EAX,2,4,&local_c);
  uVar2 = (uint)(iVar1 == 0);
  if (uVar2 == 0) {
    iVar1 = props_getTypedProperty(in_EAX,3,4,&local_8);
    uVar2 = (uint)(iVar1 == 0);
    if (uVar2 == 0) {
      uVar2 = score_getXtraState(0);
      if (uVar2 == 0) {
        uVar2 = stage_initFactoryCopied(in_EAX,local_30,local_10,local_c,local_8);
        if (uVar2 == 0) {
          uVar2 = stage_allocString(local_30,param_1);
          stage_destroyFactoryContext(local_30);
        }
      }
    }
  }
  return uVar2;
}


// ============================================================
// Function: score_serializeFileData (FUN_6804e040)
// Address: 6804e040
// Size: 244 bytes
// Return: uint
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint score_serializeFileData(void)

{
  bool bVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  undefined3 extraout_var;
  int local_38 [8];
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_c = 4;
  local_8 = 0x10;
  iVar2 = props_getInt(in_EAX);
  if (iVar2 < 2 == 0) {
    _DAT_68197764 =
         (int *)(**(int **)(in_EAX + 0x10) + *(int *)(in_EAX + 0x20) * -8 + 8 +
                *(int *)(in_EAX + 0x18));
    local_14 = DAT_6819776c;
    local_18 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_14 = ((int *)(size_t)_DAT_68197764)[1];
      local_18 = *(int *)(size_t)_DAT_68197764;
    }
    uVar3 = score_getXtraState(3);
    if (uVar3 == 0) {
      iVar2 = props_getTypedProperty(in_EAX,3,4,&local_c);
      uVar3 = (uint)(iVar2 == 0);
      if (uVar3 == 0) {
        iVar2 = props_getTypedProperty(in_EAX,4,4,&local_8);
        uVar3 = (uint)(iVar2 == 0);
        if ((uVar3 == 0) &&
           (uVar3 = stage_initFactoryShared(in_EAX,local_38,local_10,local_c,local_8), uVar3 == 0)) {
          bVar1 = stage_serializeFloat(local_38,&local_18);
          uVar3 = CONCAT31(extraout_var,bVar1);
          stage_destroyFactoryContext(local_38);
        }
      }
    }
    return uVar3;
  }
  props_setError(in_EAX,0x16);
  return (uint)(iVar2 < 2);
}


// ============================================================
// Function: score_readFileToString (FUN_6804e140)
// Address: 6804e140
// Size: 161 bytes
// Params: void * this, int param_1, int param_2
// Return: uint
// Calling convention: __thiscall
// ============================================================

uint __thiscall score_readFileToString(void *this,int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *unaff_ESI;
  
  *unaff_ESI = 2;
  unaff_ESI[1] = 0;
  uVar1 = score_getXtraState(0);
  if (uVar1 == 0) {
    iVar2 = Ordinal_1435(this);
    iVar3 = Ordinal_1433(this);
    if ((param_2 < 0) || (iVar2 - iVar3 < param_2)) {
      param_2 = iVar2 - iVar3;
    }
    iVar2 = stage_resolveString(param_1,param_2,unaff_ESI);
    uVar1 = (uint)(iVar2 == 0);
    if (uVar1 == 0) {
      piVar4 = props_getStringData(unaff_ESI,(int *)0x0);
      *(undefined1 *)((int)piVar4 + param_2) = 0;
      iVar2 = Ordinal_1409(this,piVar4,param_2);
      uVar1 = (uint)(iVar2 == 0);
      props_unlockString(unaff_ESI);
      if (uVar1 != 0) {
        props_releaseValue(param_1,(byte)*unaff_ESI,(int *)unaff_ESI[1]);
        *unaff_ESI = 2;
        unaff_ESI[1] = 0;
      }
    }
  }
  return uVar1;
}


// ============================================================
// Function: score_advanceFilePos (FUN_6804e1f0)
// Address: 6804e1f0
// Size: 44 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool score_advanceFilePos(void)

{
  char cVar1;
  int iVar2;
  int *unaff_ESI;
  int local_8;
  
  local_8 = *(int *)(*unaff_ESI + 0x10);
  cVar1 = '\0';
  if (local_8 != 0) {
    iVar2 = Ordinal_1407(&local_8);
    cVar1 = '\x01' - (iVar2 != 0);
    *(int *)(*unaff_ESI + 0x10) = local_8;
  }
  return (bool)cVar1;
}


// ============================================================
// Function: score_getFileStatus (FUN_6804e220)
// Address: 6804e220
// Size: 413 bytes
// Params: int * param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool score_getFileStatus(int *param_1)

{
  int iVar1;
  int unaff_EDI;
  bool bVar2;
  int local_20;
  int *local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_10 [2];
  int local_8;
  
  bVar2 = false;
  local_10[0] = 0;
  *param_1 = 0;
  iVar1 = props_getInt(unaff_EDI);
  if (1 < iVar1) {
    _DAT_68197764 =
         (int *)(**(int **)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x20) * -8 + 8 +
                *(int *)(unaff_EDI + 0x18));
    local_1c = DAT_6819776c;
    local_20 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_1c = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_20 = *(int *)(size_t)_DAT_68197764;
    }
    iVar1 = score_getProplistValue(unaff_EDI,&local_20);
    if (iVar1 == 0) {
      props_setError(unaff_EDI,0x13);
      props_clearValue(unaff_EDI,local_10);
      return true;
    }
    local_18 = 8;
    local_14 = 0x144;
    iVar1 = score_updateProplist(unaff_EDI,local_1c,&local_18,local_10);
    bVar2 = false;
    if (iVar1 != 0) {
      iVar1 = props_requireInt(unaff_EDI,(int *)local_10,&local_8);
      bVar2 = iVar1 == 0;
      if (bVar2) goto LAB_6804e3aa;
      if (local_8 != 0) {
        *param_1 = 1;
      }
      props_clearValue(unaff_EDI,local_10);
    }
    local_14 = 0x143;
    iVar1 = score_updateProplist(unaff_EDI,local_1c,&local_18,local_10);
    if (iVar1 != 0) {
      iVar1 = props_requireInt(unaff_EDI,(int *)local_10,&local_8);
      bVar2 = iVar1 == 0;
      if (bVar2) goto LAB_6804e3aa;
      if (local_8 != 0) {
        *param_1 = (-(uint)(*param_1 != 1) & 0xfffffffe) + 2;
      }
      props_clearValue(unaff_EDI,local_10);
    }
    local_14 = 0x14c;
    iVar1 = score_updateProplist(unaff_EDI,local_1c,&local_18,local_10);
    if (iVar1 != 0) {
      iVar1 = props_requireInt(unaff_EDI,(int *)local_10,&local_8);
      bVar2 = iVar1 == 0;
      if (!bVar2) {
        if (local_8 != 0) {
          *param_1 = 3;
        }
        props_clearValue(unaff_EDI,local_10);
      }
    }
  }
LAB_6804e3aa:
  props_clearValue(unaff_EDI,local_10);
  return bVar2;
}


