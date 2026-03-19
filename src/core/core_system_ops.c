// Module: core
// Topic: System operations - font lists, user info, environment queries, scripting
// Address range: 0x68019C40 - 0x6801A860
// Functions (9):
//   core_createFileRef (0x68019C40)
//   core_getFontList (0x68019CA0)
//   core_getUserName (0x68019D40)
//   core_checkEnvironment (0x68019DA0)
//   core_openUrl (0x68019E60)
//   core_setMovieScript (0x68019EE0)
//   core_accessShortProperty (0x6801A6C0)
//   core_accessStringProperty (0x6801A760)
//   core_accessIntProperty (0x6801A860)

// ============================================================
// Function: core_createFileRef (FUN_68019c40)
// Address: 68019c40
// Size: 82 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_createFileRef(int param_1)
{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 local_c [2];
  
  iVar2 = sprites_getStageRef(param_1);
  if ((iVar2 == 0) && (bVar1 = core_checkIsAuthor(), CONCAT31(extraout_var,bVar1) != 0)) {
    iVar2 = score_createFileObject(param_1,local_c);
    if (iVar2 == 0) {
      return 0;
    }
    props_popArgs(param_1,local_c);
    return 0;
  }
  props_reportError(param_1,0x66);
  return 0;
}



// ============================================================
// Function: core_getFontList (FUN_68019ca0)
// Address: 68019ca0
// Size: 156 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getFontList(int param_1)
{
  int iVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  uint local_1c [2];
  undefined4 local_14;
  int *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = Ordinal_1286();
  local_c = Ordinal_1157(local_8);
  iVar1 = Ordinal_1154(local_8);
  piVar2 = (int *)props_getRectCount(param_1);
  iVar4 = 0;
  local_14 = 3;
  local_10 = piVar2;
  if (0 < iVar1) {
    do {
      pcVar3 = (char *)Ordinal_1156(local_8,local_c,iVar4);
      if (*(int *)(pcVar3 + 0x38) != 0) {
        props_loadStringValue(param_1,pcVar3,local_1c);
        props_setListEntry(param_1,piVar2,local_1c);
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar1);
  }
  Ordinal_1158(local_8,local_c);
  Ordinal_1163(&local_8);
  props_popArgs(param_1,&local_14);
  return 0;
}



// ============================================================
// Function: core_getUserName (FUN_68019d40)
// Address: 68019d40
// Size: 88 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getUserName(int param_1)
{
  undefined4 local_44 [2];
  char local_3c [52];
  uint local_8;
  
  memset(local_3c,0,0x32);
  Ordinal_1287(local_3c,0x32);
  props_loadStringValue(param_1,local_3c,local_44);
  props_popArgs(param_1,local_44);
  return 0;
}



// ============================================================
// Function: core_checkEnvironment (FUN_68019da0)
// Address: 68019da0
// Size: 188 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_checkEnvironment(int param_1)
{
  int iVar1;
  uint *puVar2;
  uint local_9c [2];
  undefined4 local_94;
  uint local_90 [2];
  undefined1 local_88 [128];
  uint local_8;
  
  local_90[0] = 0;
  local_90[1] = 0;
  iVar1 = props_getValueDirect(param_1,1,1,local_9c);
  if (iVar1 == 0) {
    props_returnWithValue(param_1,0x800407dc,local_90);
  }
  else {
    local_94 = 0;
    props_coerceAndReturnString(param_1,local_9c,local_88,0x80);
    puVar2 = local_90;
    iVar1 = Ordinal_1289(local_88,&local_94);
    props_storeIntValue(param_1,(uint)(iVar1 != 0),puVar2);
  }
  props_popArgs(param_1,local_90);
  return 0;
}



// ============================================================
// Function: core_openUrl (FUN_68019e60)
// Address: 68019e60
// Size: 128 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_openUrl(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  uint local_210 [2];
  char local_208 [512];
  uint local_8;
  
  iVar1 = props_getValueDirect(param_1,1,1,local_210);
  if (iVar1 != 0) {
    props_coerceAndReturnString(param_1,local_210,local_208,0x200);
    iVar1 = scoreEngine_importScoreData(local_208);
    if (iVar1 < 0) {
      uVar2 = props_translateError(iVar1);
      props_setError(param_1,(int)(short)uVar2);
    }
  }
  props_normalizeType(param_1,2,0);
  return 0;
}



// ============================================================
// Function: core_setMovieScript (FUN_68019ee0)
// Address: 68019ee0
// Size: 122 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_setMovieScript(int param_1)
{
  int iVar1;
  uint *puVar2;
  uint local_410;
  uint local_40c;
  byte local_408 [1024];
  uint local_8;
  
  iVar1 = **(int **)(param_1 + 8);
  sprites_openUrl(iVar1,local_408);
  props_readPascalString(param_1,local_408,&local_410);
  puVar2 = score_lookupProperty(*(int **)(iVar1 + 0x4e4),300,1,(uint *)0x0);
  if (puVar2 != (uint *)0x0) {
    *puVar2 = local_410;
    puVar2[1] = local_40c;
  }
  return 0;
}



// ============================================================
// Function: core_accessShortProperty (FUN_6801a6c0)
// Address: 6801a6c0
// Size: 159 bytes
// Params: undefined4 * param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessShortProperty(undefined4 *param_1,int param_2,int param_3,int param_4)
{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  byte bVar4;
  int unaff_EBX;
  void *unaff_ESI;
  uint *unaff_EDI;
  
  if (param_2 == 0) {
    if (param_4 != 0) {
      uVar3 = sprites_getMemberInfo((int)unaff_ESI,param_1);
      uVar1 = sprites_dispatchShapeProperty(unaff_ESI,uVar3,unaff_EBX);
      cast_buildFormatString((int)unaff_ESI,uVar1,unaff_EDI);
      return 0;
    }
    uVar3 = sprites_getMemberInfo((int)unaff_ESI,param_1);
    uVar1 = sprites_getMemberFlags((int)unaff_ESI,uVar3,unaff_EBX);
    cast_buildFormatString((int)unaff_ESI,uVar1,unaff_EDI);
    return 0;
  }
  iVar2 = cast_parseFormatFlags((int)unaff_ESI,unaff_EDI,(short *)&param_2);
  if (iVar2 != 0) {
    uVar3 = props_translateError(iVar2);
    props_setErrorAndReturn((int)unaff_ESI,(int)(short)uVar3);
    return 0;
  }
  bVar4 = (byte)param_2;
  iVar2 = param_3;
  uVar3 = sprites_getMemberInfo((int)unaff_ESI,param_1);
  if (param_4 != 0) {
    sprites_dispatchButtonProperty(unaff_ESI,uVar3,bVar4,unaff_EBX,iVar2);
    return 0;
  }
  sprites_setMemberFlags((int)unaff_ESI,uVar3,bVar4,unaff_EBX,iVar2);
  return 0;
}



// ============================================================
// Function: core_accessStringProperty (FUN_6801a760)
// Address: 6801a760
// Size: 242 bytes
// Params: int param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessStringProperty(int param_1,int *param_2,int param_3,int param_4)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  void *unaff_ESI;
  short *unaff_EDI;
  byte *pbVar3;
  short sVar4;
  byte local_408 [1024];
  uint local_8;
  
  if (param_1 == 0) {
    if (param_4 == 0) {
      pbVar3 = local_408;
      uVar2 = sprites_getMemberInfo((int)unaff_ESI,(undefined4 *)unaff_EDI);
      sprites_getMemberString((int)unaff_ESI,uVar2,pbVar3,unaff_EBX);
    }
    else {
      sVar4 = *unaff_EDI;
      pbVar3 = local_408;
      uVar2 = sprites_getMemberInfo((int)unaff_ESI,(undefined4 *)unaff_EDI);
      sprites_dispatchMovieProperty(unaff_ESI,uVar2,pbVar3,unaff_EBX,sVar4);
    }
    props_readPascalString((int)unaff_ESI,local_408,param_2);
  }
  else {
    iVar1 = crt_getPlatformData((int)unaff_ESI,param_2,local_408);
    if (iVar1 != 0) {
      if (param_4 != 0) {
        sVar4 = *unaff_EDI;
        pbVar3 = local_408;
        uVar2 = sprites_getMemberInfo((int)unaff_ESI,(undefined4 *)unaff_EDI);
        sprites_dispatchScriptProperty((int)unaff_ESI,uVar2,(int)pbVar3,unaff_EBX,param_3,sVar4);
        return 0;
      }
      pbVar3 = local_408;
      uVar2 = sprites_getMemberInfo((int)unaff_ESI,(undefined4 *)unaff_EDI);
      sprites_setMemberString((int)unaff_ESI,uVar2,(int)pbVar3,unaff_EBX,param_3);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessIntProperty (FUN_6801a860)
// Address: 6801a860
// Size: 133 bytes
// Params: uint param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessIntProperty(uint param_1,int *param_2,int param_3,int param_4)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_EBX;
  void *unaff_ESI;
  int unaff_EDI;
  uint uVar3;
  
  if (param_1 == 0) {
    uVar2 = sprites_getMemberInfo((int)unaff_ESI,unaff_EBX);
    if (param_4 != 0) {
      iVar1 = sprites_dispatchFieldProperty(unaff_ESI,uVar2,unaff_EDI);
      param_2[1] = iVar1;
      return 0;
    }
    iVar1 = sprites_getMemberMediaData((int)unaff_ESI,uVar2,unaff_EDI);
    param_2[1] = iVar1;
  }
  else {
    iVar1 = props_requireInt((int)unaff_ESI,param_2,(int *)&param_1);
    if (iVar1 != 0) {
      if (param_4 != 0) {
        uVar3 = param_1;
        iVar1 = param_3;
        uVar2 = sprites_getMemberInfo((int)unaff_ESI,unaff_EBX);
        sprites_dispatchSoundProperty(unaff_ESI,uVar2,(short)uVar3,unaff_EDI,iVar1);
        return 0;
      }
      uVar3 = param_1;
      iVar1 = param_3;
      uVar2 = sprites_getMemberInfo((int)unaff_ESI,unaff_EBX);
      sprites_setMemberMediaData((int)unaff_ESI,uVar2,uVar3,unaff_EDI,iVar1);
      return 0;
    }
  }
  return 0;
}


