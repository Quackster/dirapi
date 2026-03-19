// Module: score
// Topic: File dispatch, properties, creation
// Address range: 0x6804e3c0 - 0x6804f330
// Functions (13):
//   score_handleFileCommand
//   score_releaseFileHandle
//   score_formatFileString
//   score_setFileDates
//   score_decodeStringToInt
//   score_encodeIntToString
//   score_getSetFileProperty
//   score_createFileObject
//   score_resetFileState
//   score_initFileFromProplist
//   score_pushFileValue
//   score_dispatchFileOp
//   score_storeNumericResult

// ============================================================
// Function: score_handleFileCommand (FUN_6804e3c0)
// Address: 6804e3c0
// Size: 1277 bytes
// Params: uint param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_handleFileCommand(uint param_1,int *param_2,undefined4 param_3)
{
  int local_14;
  uint uVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  undefined3 extraout_var_10;
  int iVar2;
  undefined3 extraout_var_11;
  void *this;
  int *piVar3;
  bool bVar4;
  int local_858;
  int local_854;
  uint local_850;
  uint local_84c;
  uint local_848;
  int *local_844;
  uint local_840;
  uint local_83c;
  undefined1 local_838 [1048];
  undefined1 local_420 [1048];
  uint local_8;
  
  local_83c = param_1;
  switch(param_3) {
  case 0x57:
    bVar4 = score_isXtraLoaded(local_420);
    uVar1 = CONCAT31(extraout_var,bVar4);
    if (uVar1 != 0) break;
    iVar2 = Ordinal_1352(local_420);
    uVar1 = (uint)(iVar2 == 0);
    bVar4 = uVar1 == 0;
    goto LAB_6804e85d;
  default:
    return 0;
  case 0xd3:
    iVar2 = props_getTypedValue(param_1,2,4,&local_840);
    uVar1 = (uint)(iVar2 == 0);
    if (uVar1 == 0) {
      bVar4 = score_isXtraLoaded(local_420);
      uVar1 = CONCAT31(extraout_var_06,bVar4);
      if (uVar1 == 0) {
        uVar1 = Ordinal_1355(local_838,local_420,local_840 - 1);
        uVar1 = score_openFileWithProps(param_1,local_838,uVar1);
        goto LAB_6804e76b;
      }
    }
    break;
  case 0xe3:
    score_resolveType(param_1);
    goto LAB_6804e407;
  case 0x143:
    local_840 = 0xffffffff;
    iVar2 = props_getTypedProperty(param_1,2,4,&local_840);
    uVar1 = (uint)(iVar2 == 0);
    if (uVar1 == 0) {
      uVar1 = score_readFileToString(this,param_1,local_840);
      goto LAB_6804e76b;
    }
    break;
  case 0x144:
    uVar1 = score_getXtraState(3);
    param_1 = local_83c;
    if (uVar1 == 0) {
      iVar2 = props_getValueDirect(local_83c,2,1,&local_848);
      uVar1 = (uint)(iVar2 == 0);
      param_1 = local_83c;
      if (uVar1 == 0) {
        piVar3 = props_getStringData((int *)&local_848,&local_858);
        iVar2 = Ordinal_1420(local_854,piVar3,local_858);
        uVar1 = (uint)(iVar2 == 0);
        props_unlockString((int *)&local_848);
        param_1 = local_83c;
      }
    }
    break;
  case 0x145:
    bVar4 = score_isXtraLoaded(local_420);
    uVar1 = CONCAT31(extraout_var_00,bVar4);
    if (uVar1 == 0) {
      bVar4 = score_matchXtraName(2,param_1,local_838);
      uVar1 = CONCAT31(extraout_var_01,bVar4);
      if (uVar1 == 0) {
        iVar2 = Ordinal_1353(local_420,local_838);
        uVar1 = (uint)(iVar2 == 0);
        bVar4 = uVar1 == 0;
        goto LAB_6804e85d;
      }
    }
    break;
  case 0x146:
    bVar4 = score_isXtraLoaded(local_420);
    uVar1 = CONCAT31(extraout_var_02,bVar4);
    if (uVar1 == 0) {
      bVar4 = score_matchXtraName(2,param_1,local_838);
      uVar1 = CONCAT31(extraout_var_03,bVar4);
      if (uVar1 == 0) {
        iVar2 = Ordinal_1354(local_420,local_838);
        uVar1 = (uint)(iVar2 == 0);
        bVar4 = uVar1 == 0;
        goto LAB_6804e85d;
      }
    }
    break;
  case 0x147:
    uVar1 = score_queryXtraStatus(&local_848,local_420,(int)param_2,&local_848,&local_840);
    param_1 = local_83c;
    if (uVar1 == 0) {
      if ((local_848 == 0x40) || (local_848 == 0x43)) {
        piVar3 = props_getStringData((int *)&local_848,(int *)0x0);
      }
      else {
        piVar3 = (int *)0x0;
      }
      iVar2 = Ordinal_1356(local_420,piVar3,local_840);
      uVar1 = (uint)(iVar2 == 0);
      if (piVar3 != (int *)0x0) {
        props_unlockString((int *)&local_848);
      }
      if (uVar1 == 0) {
        score_truncateString(local_83c);
      }
      props_releaseValue(local_83c,(byte)local_848,local_844);
      param_1 = local_83c;
      if (uVar1 == 0) {
        props_popArgs(local_83c,&local_850);
        return 0;
      }
    }
    break;
  case 0x148:
    bVar4 = score_isXtraLoaded(local_420);
    uVar1 = CONCAT31(extraout_var_04,bVar4);
    if (uVar1 == 0) {
      bVar4 = score_matchXtraName(2,param_1,local_838);
      uVar1 = CONCAT31(extraout_var_05,bVar4);
      if (uVar1 == 0) {
        iVar2 = Ordinal_1361(local_420,local_838);
        uVar1 = (uint)(iVar2 == 0);
        bVar4 = uVar1 == 0;
        goto LAB_6804e85d;
      }
    }
    break;
  case 0x149:
    bVar4 = score_isXtraLoaded(local_420);
    uVar1 = CONCAT31(extraout_var_07,bVar4);
    if (uVar1 == 0) {
      iVar2 = Ordinal_1357(local_420);
      uVar1 = (uint)(iVar2 == 0);
      bVar4 = uVar1 == 0;
      goto LAB_6804e85d;
    }
    break;
  case 0x14a:
    bVar4 = score_isXtraLoaded(local_420);
    uVar1 = CONCAT31(extraout_var_08,bVar4);
    if (uVar1 == 0) {
      iVar2 = Ordinal_1358(local_420);
      uVar1 = (uint)(iVar2 == 0);
      bVar4 = uVar1 == 0;
      goto LAB_6804e85d;
    }
    break;
  case 0x14b:
    bVar4 = score_getFileStatus((int *)&local_840);
    uVar1 = CONCAT31(extraout_var_09,bVar4);
    if (uVar1 == 0) {
      bVar4 = score_advanceFilePos();
      uVar1 = CONCAT31(extraout_var_10,bVar4);
      param_1 = local_83c;
      if (uVar1 == 0) {
        uVar1 = score_getXtraState(local_840);
        param_1 = local_83c;
      }
    }
    break;
  case 0x14d:
    local_854 = *(int *)(*param_2 + 0x10);
    if (local_854 != 0) {
      iVar2 = Ordinal_1408(local_854);
      uVar1 = (uint)(iVar2 == 0);
      bVar4 = uVar1 == 0;
      goto LAB_6804e85d;
    }
    goto LAB_6804e85f;
  case 0x14e:
    bVar4 = score_advanceFilePos();
    uVar1 = CONCAT31(extraout_var_11,bVar4);
    goto LAB_6804e859;
  case 0x152:
    uVar1 = score_buildFilePath(&local_850);
LAB_6804e76b:
    if (uVar1 == 0) {
      props_popArgs(param_1,&local_850);
      return 0;
    }
    break;
  case 0x153:
    uVar1 = score_serializeFileData();
LAB_6804e859:
    bVar4 = uVar1 == 0;
LAB_6804e85d:
    if (bVar4) {
LAB_6804e85f:
      uVar1 = 0;
    }
  }
  if (*(int *)(param_1 + 0x7c) == 0) {
    local_850 = 4;
    local_84c = uVar1;
    props_popArgs(param_1,&local_850);
    return 0;
  }
LAB_6804e407:
  return 0;
}


// ============================================================
// Function: score_releaseFileHandle (FUN_6804ea10)
// Address: 6804ea10
// Size: 62 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_releaseFileHandle(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = param_2;
  param_2 = *(int **)(*param_2 + 0x10);
  Ordinal_1407(&param_2);
  iVar1 = *piVar2;
  props_releaseValue(param_1,(byte)*(undefined4 *)(iVar1 + 8),*(int **)(iVar1 + 0xc));
  cast_freeHandle(piVar2);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}


// ============================================================
// Function: score_formatFileString (FUN_6804ea50)
// Address: 6804ea50
// Size: 59 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatFileString(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x3f);
  props_formatString(param_1,param_3,param_4,(byte *)"<file %ld %lx>");
  return 0;
}


// ============================================================
// Function: score_setFileDates (FUN_6804ea90)
// Address: 6804ea90
// Size: 136 bytes
// Params: undefined4 * param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool score_setFileDates(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  uint local_14 [4];
  
  piVar1 = (int *)score_deleteProplistEntry(unaff_EDI,2);
  unaff_ESI[1] = piVar1;
  if (piVar1 != (int *)0x0) {
    *unaff_ESI = 3;
    local_14[3] = *param_1;
    local_14[0] = 8;
    local_14[1] = 0x13d;
    local_14[2] = 4;
    score_updateProplistRange(unaff_EDI,piVar1,local_14,local_14 + 2);
    local_14[3] = param_1[1];
    local_14[0] = 8;
    local_14[1] = 0x13e;
    local_14[2] = 4;
    score_updateProplistRange(unaff_EDI,(int *)unaff_ESI[1],local_14,local_14 + 2);
  }
  return piVar1 == (int *)0x0;
}


// ============================================================
// Function: score_decodeStringToInt (FUN_6804eb20)
// Address: 6804eb20
// Size: 151 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool score_decodeStringToInt(void)

{
  bool bVar1;
  int in_EAX;
  int iVar2;
  byte *pbVar3;
  int *unaff_EBX;
  uint *unaff_EDI;
  int local_8;
  
  iVar2 = props_validateString(in_EAX,unaff_EBX);
  bVar1 = iVar2 == 0;
  if (iVar2 != 0) {
    pbVar3 = (byte *)props_getStringData(unaff_EBX,&local_8);
    *unaff_EDI = 0;
    if (local_8 < 1) {
      *unaff_EDI = *unaff_EDI << 8;
    }
    else {
      *unaff_EDI = (uint)*pbVar3;
    }
    if (local_8 < 2) {
      *unaff_EDI = *unaff_EDI << 8;
    }
    else {
      *unaff_EDI = (uint)pbVar3[1] | *unaff_EDI << 8;
    }
    if (local_8 < 3) {
      *unaff_EDI = *unaff_EDI << 8;
    }
    else {
      *unaff_EDI = (uint)pbVar3[2] | *unaff_EDI << 8;
    }
    if (3 < local_8) {
      *unaff_EDI = (uint)pbVar3[3] | *unaff_EDI << 8;
      props_unlockString(unaff_EBX);
      return bVar1;
    }
    *unaff_EDI = *unaff_EDI << 8;
    props_unlockString(unaff_EBX);
  }
  return bVar1;
}


// ============================================================
// Function: score_encodeIntToString (FUN_6804ebc0)
// Address: 6804ebc0
// Size: 159 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall score_encodeIntToString(undefined4 param_1,int param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  uint unaff_EBX;
  uint uVar3;
  
  *param_3 = 2;
  if ((unaff_EBX & 0xff000000) == 0) {
    uVar3 = 0;
  }
  else if ((unaff_EBX & 0xff0000) == 0) {
    uVar3 = 1;
  }
  else if ((unaff_EBX & 0xff00) == 0) {
    uVar3 = 2;
  }
  else {
    uVar3 = ((char)unaff_EBX != '\0') + 3;
  }
  iVar1 = stage_resolveString(param_2,uVar3,param_3);
  if (iVar1 != 0) {
    piVar2 = props_getStringData(param_3,(int *)0x0);
    if (uVar3 != 0) {
      *(char *)piVar2 = (char)(unaff_EBX >> 0x18);
    }
    if (1 < uVar3) {
      *(char *)((int)piVar2 + 1) = (char)(unaff_EBX >> 0x10);
    }
    if (2 < uVar3) {
      *(char *)((int)piVar2 + 2) = (char)(unaff_EBX >> 8);
    }
    if (3 < uVar3) {
      *(char *)((int)piVar2 + 3) = (char)unaff_EBX;
    }
    *(undefined1 *)((int)piVar2 + uVar3) = 0;
    props_unlockString(param_3);
  }
  return iVar1 == 0;
}


// ============================================================
// Function: score_getSetFileProperty (FUN_6804ec60)
// Address: 6804ec60
// Size: 1034 bytes
// Params: int param_1, undefined4 param_2, int param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getSetFileProperty(int param_1,undefined4 param_2,int param_3,int param_4,int *param_5)
{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 uVar3;
  undefined4 local_43c [2];
  int local_434;
  undefined4 local_430;
  int local_42c;
  uint local_428;
  undefined4 local_424;
  undefined1 local_420 [1048];
  uint local_8;
  
  local_424 = param_1;
  switch ((int)(size_t)(void *)(param_4 + -0x139)) { /* FIXUP(C2050): cast non-integral switch to int */
  case (void *)0x0:
    score_isXtraLoaded(local_420);
    if (param_3 == 0) {
      uVar3 = 2;
LAB_6804ee1e:
      Ordinal_1359(local_420,uVar3,&local_42c);
      score_encodeIntToString(extraout_ECX,param_1,param_5);
      return 0;
    }
    bVar1 = score_decodeStringToInt();
    if (CONCAT31(extraout_var_01,bVar1) == 0) {
      Ordinal_1360(local_420,2,&local_428);
      return 0;
    }
    break;
  case (void *)0x1:
    if (param_3 == 0) {
      (*(unsigned short *)((char *)&local_424 + 2)) = (undefined2)((uint)param_1 >> 0x10);
      (*(unsigned short *)((char *)&local_424 + 0)) = (ushort)*(byte *)(**(int **)(param_1 + 8) + 0x53c);
      props_loadCString(param_1,(char *)&local_424,param_5);
      return 0;
    }
    break;
  case (void *)0x2:
    if (param_3 == 0) {
      bVar1 = score_isXtraLoaded(local_420);
      *param_5 = 4;
      if (CONCAT31(extraout_var,bVar1) == 0) {
        iVar2 = Ordinal_1351(local_420);
        param_5[1] = iVar2;
        return 0;
      }
LAB_6804ef60:
      param_5[1] = 0;
      return 0;
    }
    break;
  case (void *)0x3:
    if (param_3 == 0) {
      bVar1 = score_isXtraLoaded(local_420);
      if ((CONCAT31(extraout_var_00,bVar1) == 0) &&
         (iVar2 = Ordinal_1350(local_420,local_43c), iVar2 != 0)) {
        score_setFileDates(local_43c);
        return 0;
      }
LAB_6804f03d:
      return 0;
    }
    break;
  case (void *)0x6:
    score_isXtraLoaded(local_420);
    if (param_3 == 0) {
      uVar3 = 3;
      goto LAB_6804ee1e;
    }
    bVar1 = score_decodeStringToInt();
    if (CONCAT31(extraout_var_02,bVar1) == 0) {
      Ordinal_1360(local_420,3,&local_428);
      return 0;
    }
    break;
  case (void *)0x7:
    score_isXtraLoaded(local_420);
    if (param_3 == 0) {
      iVar2 = Ordinal_1359(local_420,1,&local_42c);
      if (iVar2 != 0) {
        *param_5 = 4;
        param_5[1] = local_42c;
        return 0;
      }
      *param_5 = 2;
      goto LAB_6804ef60;
    }
    iVar2 = props_requireInt(param_1,param_5,&local_434);
    if (iVar2 != 0) {
      local_428 = (uint)(local_434 != 0);
      Ordinal_1360(local_420,1,&local_428);
      return 0;
    }
    break;
  case (void *)0x8:
    score_getXtraState(0);
    if (param_3 == 0) {
      iVar2 = Ordinal_1433(local_430);
      param_5[1] = iVar2;
      *param_5 = 4;
      return 0;
    }
    iVar2 = props_requireInt(local_424,param_5,&local_434);
    if (iVar2 != 0) {
      Ordinal_1432(local_430,local_434,0);
      return 0;
    }
    break;
  case (void *)0x9:
    score_getXtraState(-(uint)(param_3 != 0) & 2);
    if (param_3 == 0) {
      iVar2 = Ordinal_1435(local_430);
      *param_5 = 4;
      param_5[1] = iVar2;
      goto LAB_6804f03d;
    }
    break;
  case (void *)0xa:
    if (param_3 == 0) {
      score_readFileToString((void *)(param_4 + -0x139),param_1,-1);
      return 0;
    }
  }
  return 0;
}


// ============================================================
// Function: score_createFileObject (FUN_6804f0b0)
// Address: 6804f0b0
// Size: 234 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 score_createFileObject(int param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint local_c;
  int *local_8;
  
  local_c = 2;
  local_8 = (int *)0x0;
  iVar2 = props_getInt(param_1);
  if (0 < iVar2) {
    _DAT_68197764 =
         (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                 *(int *)(param_1 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_8 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    if ((local_c != 0x40) && (local_c != 0x43)) {
      props_setErrorAndReturn(param_1,10);
      return 0;
    }
  }
  props_retainValue(param_1,&local_c);
  piVar3 = (int *)cast_allocHandle(0x14,0);
  if (piVar3 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar3;
    *puVar1 = &PTR_LAB_6818d908;
    puVar1[1] = 1;
    puVar1[2] = local_c;
    puVar1[4] = 0;
    puVar1[3] = local_8;
    param_2[1] = piVar3;
    *param_2 = 3;
    return 1;
  }
  props_releaseValue(param_1,(byte)local_c,local_8);
  return 0;
}


// ============================================================
// Function: score_resetFileState (FUN_6804f1a0)
// Address: 6804f1a0
// Size: 31 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_resetFileState(int param_1)
{
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x74) = 1;
  props_unwindStack(param_1);
  return 0;
}


// ============================================================
// Function: score_initFileFromProplist (FUN_6804f1c0)
// Address: 6804f1c0
// Size: 84 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_initFileFromProplist(int param_1)
{
  uint *puVar1;
  
  if (*(int **)(param_1 + 0x60) == (int *)0x0) {
    *(undefined4 *)(param_1 + 0x1c) = 0;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    puVar1 = score_lookupProperty(*(int **)(param_1 + 0x60),0x3f,0,(uint *)0x0);
    if ((puVar1 != (uint *)0x0) && (*puVar1 == 6)) {
      *(uint *)(param_1 + 0x1c) = *puVar1;
      *(uint *)(param_1 + 0x20) = puVar1[1];
      *(undefined4 *)(param_1 + 0x74) = 1;
      return 0;
    }
  }
  *(undefined4 *)(param_1 + 0x74) = 1;
  return 0;
}


// ============================================================
// Function: score_pushFileValue (FUN_6804f220)
// Address: 6804f220
// Size: 25 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_pushFileValue(int param_1)
{
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x20) = 0;
  return 0;
}


// ============================================================
// Function: score_dispatchFileOp (FUN_6804f240)
// Address: 6804f240
// Size: 233 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispatchFileOp(int param_1)
{
  undefined4 *in_EAX;
  int iVar1;
  int unaff_ESI;
  uint uVar2;
  
  uVar2 = 0;
  iVar1 = (**(code **)(*(int *)*in_EAX + 0x28))();
  if (iVar1 == 0) {
    if (param_1 == 0xf) {
      iVar1 = **(int **)(unaff_ESI + 0x10) + -8 + *(int *)(unaff_ESI + 0x18);
      if (iVar1 == 0) {
        stage_logScriptError("lcr_StkLoc() returned NULL, lingo script may be corrupted");
        return 0;
      }
      uVar2 = (uint)(*(int *)(unaff_ESI + 0x20) == *(int *)(iVar1 + 4));
    }
    else if (param_1 == 0xe) {
      iVar1 = (**(code **)(*(int *)*in_EAX + 0x28))();
      if (iVar1 != 0) {
        *(uint *)(unaff_ESI + 0x20) = (uint)(*(int *)(unaff_ESI + 0x20) == 0);
        return 0;
      }
      uVar2 = (uint)(*(int *)(unaff_ESI + 0x20) !=
                    *(int *)(**(int **)(unaff_ESI + 0x10) + -4 + *(int *)(unaff_ESI + 0x18)));
    }
    else if ((param_1 == 0x24) || (param_1 == 0x25)) {
      uVar2 = *(int *)(unaff_ESI + 0x1c) -
              *(int *)(**(int **)(unaff_ESI + 0x10) + -8 + *(int *)(unaff_ESI + 0x18));
      if (uVar2 == 0) {
        uVar2 = *(int *)(unaff_ESI + 0x20) -
                *(int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x18) + -4);
      }
      if ((int)uVar2 < 0) {
        uVar2 = 0xffffffff;
      }
      else if (0 < (int)uVar2) {
        uVar2 = 1;
      }
    }
    props_popValue(unaff_ESI);
    props_popValue(unaff_ESI);
    props_pushValue(unaff_ESI);
    *(uint *)(unaff_ESI + 0x20) = uVar2;
  }
  return 0;
}


// ============================================================
// Function: score_storeNumericResult (FUN_6804f330)
// Address: 6804f330
// Size: 173 bytes
// Params: double param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_storeNumericResult(double param_1)
{
  int *piVar1;
  float fVar2;
  int iVar3;
  int *unaff_ESI;
  int unaff_EDI;
  float local_8;
  
  if (*unaff_ESI == 0x20) {
    iVar3 = props_isIntegerFloat((float)(size_t)param_1,(double)(float)(size_t)param_1);
    if (iVar3 == 0) {
      stage_allocNumberHandle(unaff_EDI,param_1,unaff_ESI);
      return 0;
    }
LAB_6804f3a8:
    local_8 = (float)(size_t)param_1;
    unaff_ESI[1] = (int)local_8;
    return 0;
  }
  if (*unaff_ESI == 0x23) {
    fVar2 = (float)(size_t)param_1;
    if (*(int *)(*(int *)unaff_ESI[1] + 4) == 1) {
      iVar3 = props_isIntegerFloat(fVar2,(double)fVar2);
      if (iVar3 == 0) {
        *(double *)(*(int *)unaff_ESI[1] + 8) = param_1;
        return 0;
      }
      cast_freeHandle(unaff_ESI[1]);
      *unaff_ESI = 0x20;
      goto LAB_6804f3a8;
    }
    piVar1 = (int *)(*(int *)unaff_ESI[1] + 4);
    *piVar1 = *piVar1 + -1;
    props_storeNumber(unaff_EDI,(double)fVar2,unaff_ESI);
  }
  return 0;
}


