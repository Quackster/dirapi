// Module: cast
// Topic: Score/Xtra dispatch and interop layer
// Address range: 0x68028960 - 0x68029880
// Functions (20):
//   cast_resolveIdentifierFlag
//   cast_getScoreXtraData
//   cast_setXtraFormatCode
//   cast_applyXtraFormatCode
//   cast_executeScoreXtra
//   cast_handleScoreXtraAccess
//   cast_releaseXtraHandle
//   cast_createXtraHandle
//   cast_getXtraHandleValue
//   cast_invokeXtraMethodEx
//   cast_resolveXtraPropertyId
//   cast_registerXtraSymbol
//   cast_dispatchScoreXtra
//   cast_readScoreXtraData
//   cast_resolveXtraByName
//   cast_getScoreXtraValue
//   cast_storeScoreXtraValue
//   cast_writeScoreXtra
//   cast_readScoreXtraEx
//   cast_dispatchScoreOp

// ============================================================
// Function: cast_resolveIdentifierFlag (FUN_68028960)
// Address: 68028960
// Size: 169 bytes
// Params: int param_1, uint * param_2, ushort * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveIdentifierFlag(int param_1,uint *param_2,ushort *param_3)
{
  int *piVar1;
  ushort uVar2;
  int local_864 [279];
  byte local_408 [1024];
  uint local_8;
  
  if ((*param_2 != 0x40) && (*param_2 != 0x43)) {
    props_returnWithValue(param_1,0x800407dc,param_2);
    return 0;
  }
  props_toPascalString((int *)param_2,local_408);
  props_parseIdentifier(local_864,local_408);
  piVar1 = cast_parseNextToken(local_864);
  if (piVar1 == (int *)0x47) {
    uVar2 = 0;
  }
  else if (piVar1 == (int *)0x50) {
    uVar2 = 0xffff;
  }
  else {
    uVar2 = (ushort)(piVar1 == (int *)0x17e);
  }
  *param_3 = uVar2;
  return 0;
}



// ============================================================
// Function: cast_getScoreXtraData (FUN_68028a10)
// Address: 68028a10
// Size: 23 bytes
// Params: int param_1, short * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getScoreXtraData(int param_1,short *param_2)
{
  thunk_FUN_680285c0(param_2,param_1);
  return 0;
}



// ============================================================
// Function: cast_setXtraFormatCode (FUN_68028a30)
// Address: 68028a30
// Size: 93 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_setXtraFormatCode(void)

{
  int iVar1;
  undefined4 uVar2;
  int extraout_ECX;
  int unaff_EBX;
  int *unaff_ESI;
  uint *unaff_EDI;
  uint local_8;
  
  iVar1 = cast_getXtraProperty(unaff_EBX,unaff_EDI,unaff_ESI);
  if (iVar1 == 0) {
    if (*(short *)((int)unaff_ESI + 2) != -1) {
      return 0;
    }
    if ((short)*unaff_ESI != 1) {
      return 0;
    }
  }
  else {
    iVar1 = props_coerceAndReturnFloat(unaff_EBX,unaff_EDI,&local_8);
    if (iVar1 != 0) {
      return iVar1;
    }
    uVar2 = cast_convertFormatCode(local_8);
    if ((short)uVar2 != -200) {
      *(short *)((int)unaff_ESI + 2) = (short)uVar2;
      *(undefined2 *)unaff_ESI = 0xffff;
      return extraout_ECX;
    }
  }
  return -0x7ffbffff;
}



// ============================================================
// Function: cast_applyXtraFormatCode (FUN_68028a90)
// Address: 68028a90
// Size: 27 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_applyXtraFormatCode(void)
{
  cast_setXtraFormatCode();
  return 0;
}



// ============================================================
// Function: cast_executeScoreXtra (FUN_68028ab0)
// Address: 68028ab0
// Size: 923 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cast_executeScoreXtra(uint param_1,int *param_2,int param_3)
{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined3 extraout_var;
  int iVar4;
  int local_434;
  uint local_430;
  uint local_42c;
  uint local_428;
  uint local_424;
  uint *local_420;
  int *local_41c;
  int *local_418;
  int local_414;
  uint local_410;
  uint *local_40c;
  undefined1 local_408;
  char local_407 [1023];
  uint local_8;
  
  local_41c = param_2;
  local_410 = 0x80000001;
  local_414 = props_getInt(param_1);
  if (param_3 == 0xe3) {
    score_resolveType(param_1);
    return 0;
  }
  uVar2 = core_getAsyncState(param_1);
  if (uVar2 == 0) {
    return 0;
  }
  local_418 = (int *)**(undefined4 **)(*local_41c + 8);
  if (param_3 == 0x82) {
    param_3 = 0xfe;
  }
  if (param_3 == 0xd3) {
    iVar3 = props_getTypedValue(param_1,2,4,&local_430);
    if (iVar3 == 0) goto LAB_68028e2f;
    iVar3 = xtraRuntime_setPropertyByIndex(uVar2,local_418,local_430,&local_410);
  }
  else if (param_3 == 0xda) {
    iVar3 = props_getTypedValue(param_1,2,4,&local_430);
    if (iVar3 == 0) goto LAB_68028e2f;
    if (local_414 != 3) {
      props_setError(param_1,0x3a);
      goto LAB_68028e2f;
    }
    _DAT_68197764 =
         (uint *)(**(int **)(param_1 + 0x10) + (2 - *(int *)(param_1 + 0x20)) * 8 +
                 *(int *)(param_1 + 0x18));
    local_424 = DAT_6819776c;
    local_428 = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_424 = ((int *)(size_t)_DAT_68197764)[1];
      local_428 = *(int *)(size_t)_DAT_68197764;
    }
    iVar3 = cast_readScoreXtraData(param_1,uVar2,&local_428,&local_410);
    if (iVar3 == 0) goto LAB_68028e2f;
    iVar3 = xtra_resolvePathDir(uVar2,local_418,local_430,&local_410);
    local_428 = 2;
    local_424 = 0;
  }
  else {
    local_42c = 0x80000001;
    score_lookupSymbol(DAT_68196304,param_3,(int)&local_408);
    iVar3 = xtra_parsePath(uVar2,local_418,local_407,&local_42c);
    if (((iVar3 == 0) || ((local_42c & 7) != 0)) ||
       (bVar1 = xtra_isFunction(uVar2,local_42c & 0xfffffff8), CONCAT31(extraout_var,bVar1) == 0))
    goto LAB_68028e2f;
    local_41c = (int *)(local_414 + -1);
    if ((int)local_41c < 1) {
      local_41c = (int *)0x0;
      local_420 = (uint *)0x0;
    }
    else {
      local_420 = (uint *)xtra_getPropertyById(uVar2,(int)local_41c * 4);
      if (local_420 == (uint *)0x0) goto LAB_68028e2f;
    }
    local_434 = 1;
    if (1 < local_414) {
      local_40c = local_420;
      do {
        _DAT_68197764 =
             (uint *)(**(int **)(param_1 + 0x10) + (local_434 - *(int *)(param_1 + 0x20)) * 8 +
                     *(int *)(param_1 + 0x18));
        local_424 = DAT_6819776c;
        local_428 = DAT_68197768;
        if (_DAT_68197764 != (uint *)0x0) {
          DAT_6819776c = 0;
          DAT_68197768 = 0;
          local_424 = ((int *)(size_t)_DAT_68197764)[1];
          local_428 = *(int *)(size_t)_DAT_68197764;
        }
        iVar4 = cast_readScoreXtraData(param_1,uVar2,&local_428,local_40c);
        iVar3 = 0;
        if (iVar4 == 0) goto LAB_68028cfa;
        local_40c = local_40c + 1;
        local_434 = local_434 + 1;
      } while (local_434 < local_414);
    }
    local_40c = *(uint **)(param_1 + 0x74);
    iVar3 = xtra_validateExtension(uVar2,(int)local_418,local_42c,(uint)local_41c,(int)local_420,
                         (int *)&local_410);
    if ((iVar3 == 0) && (*(int *)(param_1 + 0x74) == 9)) {
      iVar3 = 1;
    }
    *(uint **)(param_1 + 0x74) = local_40c;
LAB_68028cfa:
    xtra_checkAndFlush(uVar2,(int)local_420);
  }
  if (iVar3 != 0) {
    cast_dispatchScoreXtra(param_1,uVar2,local_410,&local_428);
    props_popArgs(param_1,&local_428);
  }
LAB_68028e2f:
  core_dispatchScript(param_1,uVar2);
  return 0;
}



// ============================================================
// Function: cast_handleScoreXtraAccess (FUN_68028e50)
// Address: 68028e50
// Size: 253 bytes
// Params: uint param_1, int * param_2, int param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_handleScoreXtraAccess(uint param_1,int *param_2,int param_3,int param_4,uint *param_5)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint local_40c;
  undefined1 local_408;
  char local_407 [1023];
  uint local_8;
  
  iVar2 = core_getAsyncState(param_1);
  if (iVar2 != 0) {
    piVar1 = (int *)**(undefined4 **)(*param_2 + 8);
    score_lookupSymbol(DAT_68196304,param_4,(int)&local_408);
    if (param_3 == 0) {
      iVar3 = xtra_parsePath(iVar2,piVar1,local_407,&local_40c);
      if ((iVar3 != 0) && (local_40c != 0x80000001)) {
        cast_dispatchScoreXtra(param_1,iVar2,local_40c,param_5);
      }
    }
    else {
      iVar3 = cast_readScoreXtraData(param_1,iVar2,param_5,&local_40c);
      if (iVar3 != 0) {
        xtra_parsePathEx(iVar2,piVar1,local_407,&local_40c);
      }
    }
    core_dispatchScript(param_1,iVar2);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: cast_releaseXtraHandle (FUN_68028f60)
// Address: 68028f60
// Size: 94 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_releaseXtraHandle(int param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_2;
  param_2 = *(int **)(*param_2 + 8);
  if ((*(int *)(**(int **)(param_1 + 8) + 0x580) != 0) &&
     (iVar2 = core_getAsyncState(param_1), iVar2 != 0)) {
    xtraRuntime_markAtomDirect(*(int *)(iVar2 + 0x14),param_2);
    core_dispatchScript(param_1,iVar2);
  }
  Ordinal_1125(&param_2);
  cast_freeHandle(piVar1);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}



// ============================================================
// Function: cast_createXtraHandle (FUN_68028fc0)
// Address: 68028fc0
// Size: 132 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_createXtraHandle(int param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)Ordinal_1124(4);
  if (local_8 != (undefined4 *)0x0) {
    *local_8 = param_3;
    piVar2 = (int *)cast_allocHandle(0xc,0);
    if (piVar2 != (int *)0x0) {
      *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
      puVar1 = (undefined4 *)*piVar2;
      *puVar1 = &PTR_LAB_6818bad8;
      puVar1[1] = 1;
      puVar1[2] = local_8;
      xtraRuntime_addAtomRef(*(int *)(param_2 + 0x14),(uint)local_8,0x68176ce0);
      param_4[1] = piVar2;
      *param_4 = 3;
      return 1;
    }
    Ordinal_1125(&local_8);
  }
  return 0;
}



// ============================================================
// Function: cast_getXtraHandleValue (FUN_68029050)
// Address: 68029050
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getXtraHandleValue(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818bad8)) {
    return *(undefined4 *)(*(int **)param_2[1])[2];
  }
  return 0;
}



// ============================================================
// Function: cast_invokeXtraMethodEx (FUN_68029080)
// Address: 68029080
// Size: 226 bytes
// Params: int * param_1, uint param_2, undefined4 * param_3, undefined4 param_4, uint param_5, int * param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_invokeXtraMethodEx(int *param_1,uint param_2,undefined4 *param_3,undefined4 param_4,uint param_5,
                int *param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_1[0x1d];
  param_1[0x1d] = 1;
  props_pushValue((int)param_1);
  param_1[7] = 4;
  param_1[8] = param_5;
  if (param_6 != (int *)0x0) {
    param_1[8] = param_5 | 0x80000000;
  }
  iVar3 = (**(code **)(*(int *)*param_3 + 4))(param_1,param_3,param_4);
  if (iVar3 == 0) {
    if (param_1[0x1f] == 0) {
      props_reportError((int)param_1,4);
    }
  }
  else if (param_1[0x1f] == 0) {
    if (param_1[0x1d] == 2) {
      props_dispatchOpcode(param_1,(int *)0x2,0,0);
    }
    if (param_1[0x1d] != 8) {
      if (param_6 != (int *)0x0) {
        *param_6 = param_1[7];
        param_6[1] = param_1[8];
        param_1[6] = param_1[6] + -8;
        iVar2 = *(int *)param_1[4];
        param_1[7] = *(int *)(iVar2 + param_1[6]);
        param_1[8] = *(int *)(iVar2 + 4 + param_1[6]);
      }
      param_1[0x1d] = iVar1;
      return iVar3;
    }
    return 0;
  }
  core_getScriptState(param_2);
  return 0;
}



// ============================================================
// Function: cast_resolveXtraPropertyId (FUN_68029170)
// Address: 68029170
// Size: 77 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_resolveXtraPropertyId(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = -1;
  if (param_3 != 0) {
    iVar1 = xtraRuntime_callFunction(param_2);
    if ((iVar1 != 0) && (iVar4 = *(int *)(iVar1 + 0x20), iVar4 == 0)) {
      puVar2 = (uint *)xtra_getGlobalFlags(iVar1);
      if (puVar2 != (uint *)0x0) {
        pcVar3 = xtra_getStringValue(puVar2);
        if (pcVar3 != (char *)0x0) {
          iVar4 = props_resolvePropertyId(param_1,pcVar3);
          return iVar4;
        }
      }
    }
  }
  return iVar4;
}



// ============================================================
// Function: cast_registerXtraSymbol (FUN_680291c0)
// Address: 680291c0
// Size: 46 bytes
// Params: int param_1, int param_2, undefined2 param_3, byte param_4, uint param_5, char * param_6, undefined4 param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_registerXtraSymbol(int param_1,int param_2,undefined2 param_3,byte param_4,uint param_5,char *param_6
                 ,undefined4 param_7)
{
  int iVar1;
  
  iVar1 = xtra_registerNamedFunction(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x20) = param_7;
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchScoreXtra (FUN_680291f0)
// Address: 680291f0
// Size: 412 bytes
// Params: int param_1, int param_2, uint param_3, uint * param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool cast_dispatchScoreXtra(int param_1,int param_2,uint param_3,uint *param_4)

{
  undefined **ppuVar1;
  uint *puVar2;
  char *pcVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = 0;
  if (((param_3 & 1) != 0) && (param_3 != 0x80000001)) {
    iVar5 = props_storeIntValue(param_1,(int)param_3 >> 1,param_4);
    return iVar5 == 0;
  }
  uVar4 = param_3 & 7;
  if (uVar4 == 2) {
    props_storeFloatDirect(param_1,*(double *)(param_3 & 0xfffffff8),(int *)param_4);
    return true;
  }
  if (uVar4 == 6) {
    iVar5 = props_storeIntValue(param_1,(int)param_3 >> 3,param_4);
    return iVar5 == 0;
  }
  if (param_3 == 0x80000001) {
    param_4[1] = 0;
    *param_4 = 2;
    return true;
  }
  if (param_3 == 0) {
    *param_4 = 0;
    param_4[1] = 0;
    return true;
  }
  if ((uVar4 == 4) || (uVar4 != 0)) {
    puVar2 = (uint *)xtra_lookupHash(param_2,param_3);
    if (puVar2 != (uint *)0x0) {
      pcVar3 = xtra_getStringValue(puVar2);
      iVar5 = props_loadStringValue(param_1,pcVar3,param_4);
    }
  }
  else {
    uVar4 = param_3 & 0xfffffff8;
    ppuVar1 = (undefined **)xtraRuntime_getClassPointer(uVar4);
    if (ppuVar1 != &PTR_s__generic_6818bdb0) {
      ppuVar1 = (undefined **)xtraRuntime_getClassPointer(uVar4);
      if (ppuVar1 == &PTR_s__symbol_6818bd08) {
        uVar4 = xtra_getObjectTag(param_2,uVar4);
        param_4[1] = (int)uVar4 >> 1;
        *param_4 = 8;
        return true;
      }
      cast_createXtraHandle(param_1,param_2,uVar4,param_4);
      return true;
    }
    uVar4 = xtra_getObjectTag(param_2,uVar4);
    param_4[1] = uVar4;
    if (uVar4 != 0) {
      *param_4 = 3;
      props_retainValue(param_1,param_4);
      return true;
    }
  }
  return iVar5 == 0;
}



// ============================================================
// Function: cast_readScoreXtraData (FUN_68029390)
// Address: 68029390
// Size: 386 bytes
// Params: uint param_1, int param_2, uint * param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_readScoreXtraData(uint param_1,int param_2,uint *param_3,uint *param_4)

{
  double dVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int *piVar5;
  uint *puVar6;
  
  puVar3 = param_3;
  switch(*param_3) {
  default:
    *param_4 = 0;
    return 1;
  case 1:
  case 0x40:
  case 0x43:
    piVar5 = props_getStringData((int *)param_3,(int *)&param_1);
    puVar6 = xtra_allocHashEntry(param_2,piVar5,param_1);
    if (puVar6 != (uint *)0x0) {
      *param_4 = (uint)puVar6 | 4;
      props_unlockString((int *)puVar3);
      return 1;
    }
    *param_4 = 0;
    props_unlockString((int *)puVar3);
    return 1;
  case 2:
    *param_4 = 0x80000001;
    return 1;
  case 3:
    uVar4 = cast_getXtraHandleValue(param_1,(int *)param_3);
    iVar2 = param_2;
    if (uVar4 == 0) {
      uVar4 = cast_loadGenericResource(param_2);
      if (uVar4 != 0) {
        props_retainValue(param_1,puVar3);
        xtra_getResourceById(iVar2,uVar4,puVar3[1]);
        *param_4 = uVar4;
        return 1;
      }
      *param_4 = 0;
      return 1;
    }
    goto LAB_680293f2;
  case 4:
    param_1 = param_3[1];
    if (param_1 + 0x3fffffff < 0x7fffffff) {
      *param_4 = param_1 * 2 | 1;
      return 1;
    }
    dVar1 = (double)(int)param_1;
    break;
  case 8:
    uVar4 = cast_loadSymbolResource(param_2,param_3[1]);
    *param_4 = uVar4;
    return 1;
  case 9:
  case 0x20:
  case 0x23:
    if (*param_3 == 0x20) {
      dVar1 = (double)(float)(size_t)param_3[1];
    }
    else {
      dVar1 = *(double *)(*(int *)param_3[1] + 8);
    }
  }
  uVar4 = xtraRuntime_storeFloat(param_2,dVar1);
  uVar4 = uVar4 | 2;
LAB_680293f2:
  *param_4 = uVar4;
  return 1;
}



// ============================================================
// Function: cast_resolveXtraByName (FUN_68029580)
// Address: 68029580
// Size: 147 bytes
// Params: char * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_resolveXtraByName(char *param_1)
{
  char cVar1;
  char *pcVar2;
  undefined4 unaff_ESI;
  int local_46c;
  int *local_468;
  int local_464 [3];
  int local_458;
  uint local_8;
  
  pcVar2 = param_1;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  props_hashSymbol(local_464,param_1,(int)pcVar2 - (int)(param_1 + 1));
  props_searchSymbolTable(unaff_ESI,local_464);
  if ((local_46c == 8) && (local_458 == 0)) {
    return 0;
  }
  props_releaseValue(unaff_ESI,(byte)local_46c,local_468);
  return 0;
}



// ============================================================
// Function: cast_getScoreXtraValue (FUN_68029620)
// Address: 68029620
// Size: 72 bytes
// Params: undefined4 param_1, int param_2, uint param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getScoreXtraValue(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint *puVar1;
  char *pcVar2;
  undefined4 uVar3;
  
  if (((byte)param_3 & 7) == 4) {
    puVar1 = (uint *)xtra_lookupHash(param_2,param_3);
    if (puVar1 != (uint *)0x0) {
      pcVar2 = xtra_getStringValue(puVar1);
      if (pcVar2 != (char *)0x0) {
        if (param_4 != (undefined4 *)0x0) {
          *param_4 = pcVar2;
        }
        uVar3 = cast_resolveXtraByName(pcVar2);
        return uVar3;
      }
    }
  }
  return 0xffffffff;
}



// ============================================================
// Function: cast_storeScoreXtraValue (FUN_68029670)
// Address: 68029670
// Size: 110 bytes
// Params: int param_1, int param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_storeScoreXtraValue(int param_1,int param_2,uint param_3,uint *param_4)
{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  uint *puVar4;
  uint local_c;
  uint local_8;
  
  bVar2 = cast_dispatchScoreXtra(param_1,param_2,*param_4,&local_c);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    uVar3 = cast_getScoreXtraValue(param_1,param_2,param_3,(undefined4 *)0x0);
    if (-1 < (int)uVar3) {
      puVar4 = score_lookupProperty(*(int **)(**(int **)(param_1 + 8) + 0x4e4),uVar3,1,(uint *)0x0);
      if (puVar4 != (uint *)0x0) {
        piVar1 = (int *)puVar4[1];
        uVar3 = *puVar4;
        *puVar4 = local_c;
        puVar4[1] = local_8;
        props_releaseValue(param_1,(byte)uVar3,piVar1);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: cast_writeScoreXtra (FUN_680296e0)
// Address: 680296e0
// Size: 139 bytes
// Params: int param_1, uint param_2, uint * param_3, int param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_writeScoreXtra(int param_1,uint param_2,uint *param_3,int param_4,int param_5)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined3 extraout_var;
  uint local_c;
  int *local_8;
  
  uVar2 = xtra_getPlatformData(param_1);
  if (((((param_2 & 1) != 0) && (param_2 != 0x80000001)) && (iVar3 = (int)param_2 >> 1, -1 < iVar3))
     && ((iVar3 < param_4 && (*(int *)(param_5 + 4 + iVar3 * 8) == 0)))) {
    local_c = 0;
    bVar1 = cast_dispatchScoreXtra(uVar2,param_1,*param_3,&local_c);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      return 0;
    }
    props_accessGlobalProps(uVar2,1,*(int *)(param_5 + iVar3 * 8),&local_c);
    props_releaseValue(uVar2,(byte)local_c,local_8);
  }
  return 1;
}



// ============================================================
// Function: cast_readScoreXtraEx (FUN_68029770)
// Address: 68029770
// Size: 260 bytes
// Params: int param_1, uint param_2, uint * param_3, int param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_readScoreXtraEx(int param_1,uint param_2,uint *param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint local_c;
  int *local_8;
  
  uVar1 = xtra_getPlatformData(param_1);
  if (((((param_2 & 1) == 0) || (param_2 == 0x80000001)) || (iVar2 = (int)param_2 >> 1, iVar2 < 0))
     || (param_4 <= iVar2)) {
    return 1;
  }
  if (*(int *)(param_5 + 4 + iVar2 * 8) == 0) {
    local_c = 4;
    local_8 = (int *)0x0;
    props_accessGlobalProps(uVar1,0,*(int *)(param_5 + iVar2 * 8),&local_c);
    cast_readScoreXtraData(uVar1,param_1,&local_c,param_3);
    props_releaseValue(uVar1,(byte)local_c,local_8);
    return 1;
  }
  *(undefined4 *)(uVar1 + 0x7c) = 0;
  props_pushValue(uVar1);
  *(undefined4 *)(uVar1 + 0x1c) = 4;
  *(undefined4 *)(uVar1 + 0x20) = 0x80000000;
  puVar3 = score_lookupProperty(*(int **)(**(int **)(uVar1 + 8) + 0x4ec),*(uint *)(param_5 + iVar2 * 8),0,
                        (uint *)0x0);
  if ((puVar3 != (uint *)0x0) && (props_callNative(uVar1,puVar3[1]), *(int *)(uVar1 + 0x7c) == 0)) {
    cast_readScoreXtraData(uVar1,param_1,(uint *)(uVar1 + 0x1c),param_3);
    props_popValue(uVar1);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchScoreOp (FUN_68029880)
// Address: 68029880
// Size: 84 bytes
// Params: int param_1, int param_2, undefined4 param_3, uint * param_4, char * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_dispatchScoreOp(int param_1,int param_2,undefined4 param_3,uint *param_4,char *param_5)

{
  char cVar1;
  char *pcVar2;
  uint *puVar3;
  
  if (param_2 != 0) {
    return 0;
  }
  pcVar2 = param_5;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  puVar3 = xtra_allocHashEntry(param_1,param_5,(int)pcVar2 - (int)(param_5 + 1));
  if (puVar3 != (uint *)0x0) {
    *param_4 = (uint)puVar3 | 4;
    return 1;
  }
  *param_4 = 0;
  return 1;
}



