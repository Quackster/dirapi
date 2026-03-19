// Module: media
// Topic: Cast member operations, properties, and member access
// Address range: 0x680a3880 - 0x680a5280
// Functions (40):
//   media_getCastCount
//   media_getCastMemberType
//   media_getCastTypeCount
//   media_getCastTypeById
//   media_findCastTypeIndex
//   media_getCastTypeName
//   media_getCastGlobalCount
//   media_getCastGlobalEntry
//   media_getCastGlobalData
//   media_getPixelFilterRef
//   media_validateCastMember
//   media_applyPixelFilterEx
//   media_applyPixelFilter
//   media_hasCastScript
//   media_getCastMemberCount
//   media_getCastMemberByNum
//   media_findCastMemberByName
//   media_getCastMemberPosition
//   media_initCastSlot
//   media_getCastProperty
//   media_getCastPropertyData
//   media_setCastProperty
//   media_findCastByName
//   media_findCastByNameEx
//   media_deleteCastMember
//   media_saveCastMember
//   media_findCastByGuid
//   media_getCastStreamGuid
//   media_convertCastPoint
//   media_getCastPropertyPair
//   media_getCastSoundRef
//   media_setCastSoundRef
//   media_setCastDataEntry
//   media_getMediaTypeRef
//   media_setCastChannelField
//   media_convertCastToStage
//   media_convertStageToCast
//   media_getMediaTypeData
//   media_setCastScriptFlag
//   media_setCastPreloadFlag

// ============================================================
// Function: media_getCastCount (FUN_680a3880)
// Address: 680a3880
// Size: 29 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getCastCount(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = Ordinal_1154(*(undefined4 *)(param_1 + 800));
  *param_2 = uVar1;
  return 0;
}



// ============================================================
// Function: media_getCastMemberType (FUN_680a38a0)
// Address: 680a38a0
// Size: 119 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getCastMemberType(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2;
  *param_3 = 0;
  if (0 < param_2) {
    iVar2 = Ordinal_1154(*(undefined4 *)(param_1 + 800));
    if (iVar1 <= iVar2) {
      param_2 = 0;
      Ordinal_1155(*(undefined4 *)(param_1 + 800),iVar1 + -1,&param_2);
      if (param_2 != 0) {
        if (*(int *)(param_2 + 0x20) != 0) {
          *param_3 = **(undefined4 **)(param_2 + 0x20);
          return 0;
        }
        *param_3 = 0;
        return 0;
      }
    }
  }
  return 0x800407d8;
}



// ============================================================
// Function: media_getCastTypeCount (FUN_680a3920)
// Address: 680a3920
// Size: 18 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getCastTypeCount(undefined4 *param_1)

{
  *param_1 = 0xe;
  return 0;
}



// ============================================================
// Function: media_getCastTypeById (FUN_680a3940)
// Address: 680a3940
// Size: 41 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getCastTypeById(int param_1,undefined4 *param_2)

{
  if (param_1 - 1U < 0xe) {
    *param_2 = *(undefined4 *)(&DAT_6818e484 + param_1 * 4);
    return 0;
  }
  return 0x800407d8;
}



// ============================================================
// Function: media_findCastTypeIndex (FUN_680a3970)
// Address: 680a3970
// Size: 65 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_findCastTypeIndex(int param_1,int *param_2)

{
  short sVar1;
  
  sVar1 = 0;
  do {
    if (param_1 == (&DAT_6818e488)[sVar1]) {
      *param_2 = sVar1 + 1;
      return 0;
    }
    sVar1 = sVar1 + 1;
  } while (sVar1 < 0xe);
  *param_2 = 0;
  return 0x800407d3;
}



// ============================================================
// Function: media_getCastTypeName (FUN_680a39c0)
// Address: 680a39c0
// Size: 91 bytes
// Params: int param_1, undefined1 * param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getCastTypeName(int param_1,undefined1 *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  iVar1 = media_findCastTypeIndex(param_1,&local_8);
  if ((iVar1 == 0) &&
     (iVar2 = Ordinal_1517(DAT_681956e0,local_8 + 0x13eb,param_2,param_3), iVar2 == 0)) {
    *param_2 = 0;
    return -0x7ffbffec;
  }
  return iVar1;
}



// ============================================================
// Function: media_getCastGlobalCount (FUN_680a3a20)
// Address: 680a3a20
// Size: 29 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getCastGlobalCount(int param_1,undefined4 *param_2)

{
  int *piVar1;
  undefined4 uVar2;
  
  piVar1 = (int *)lingo_getGlobalRef(param_1);
  uVar2 = mediaPlayback_getEntryCount(piVar1);
  *param_2 = uVar2;
  return 0;
}



// ============================================================
// Function: media_getCastGlobalEntry (FUN_680a3a40)
// Address: 680a3a40
// Size: 30 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getCastGlobalEntry(int param_1,int param_2,undefined4 *param_3)
{
  int *piVar1;
  
  piVar1 = (int *)lingo_getGlobalRef(param_1);
  mediaPlayback_getSlotValue(piVar1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: media_getCastGlobalData (FUN_680a3a60)
// Address: 680a3a60
// Size: 34 bytes
// Params: int param_1, int param_2, undefined1 * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getCastGlobalData(int param_1,int param_2,undefined1 *param_3,undefined4 param_4)
{
  int *piVar1;
  
  piVar1 = (int *)lingo_getGlobalRef(param_1);
  media_getDisplayName(piVar1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: media_getPixelFilterRef (FUN_680a3a90)
// Address: 680a3a90
// Size: 251 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getPixelFilterRef(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  int iVar1;
  undefined1 *local_424;
  undefined1 local_420 [1048];
  uint local_8;
  
  local_424 = local_420;
  if ((0x3fc < param_5) &&
     (local_424 = (undefined1 *)Ordinal_1124(param_5 + 0x1d), local_424 == (undefined1 *)0x0)) {
    return 0;
  }
  Ordinal_1309(local_424,param_5,param_3,2);
  if (*param_1 == 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = *(int *)(*param_1 + 0x20);
  }
  iVar1 = scoreEngine_writeChannelData(iVar1,0,local_424,param_2,0,0,0);
  if (iVar1 != 0) {
    Ordinal_1310(local_424,param_4,param_5);
  }
  if ((local_424 != (undefined1 *)0x0) && (local_424 != local_420)) {
    Ordinal_1125(&local_424);
  }
  return 0;
}



// ============================================================
// Function: media_validateCastMember (FUN_680a3b90)
// Address: 680a3b90
// Size: 56 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_validateCastMember(int *param_1,undefined4 param_2)

{
  int iVar1;
  
  if ((*param_1 != 0) && (iVar1 = *(int *)(*param_1 + 0x20), iVar1 != 0)) {
    iVar1 = Ordinal_1332(param_2,*(undefined4 *)(iVar1 + 4));
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 0x80040001;
}



// ============================================================
// Function: media_applyPixelFilterEx (FUN_680a3bd0)
// Address: 680a3bd0
// Size: 61 bytes
// Params: int * param_1, undefined1 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_applyPixelFilterEx(int *param_1,undefined1 *param_2)

{
  int iVar1;
  undefined1 uVar2;
  
  iVar1 = (**(code **)(*param_1 + 0x14))(param_1,6,(int)&param_1 + 3,1,"safeForShockwave");
  if ((iVar1 == 0) && ((*(unsigned char *)((char *)&param_1 + 3)) != '\0')) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  *param_2 = uVar2;
  if (iVar1 == -0x7ffbffd6) {
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: media_applyPixelFilter (FUN_680a3c10)
// Address: 680a3c10
// Size: 173 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_applyPixelFilter(int param_1)
{
  char *pcVar1;
  int iVar2;
  code *pcVar3;
  char *pcVar4;
  char *pcVar5;
  char local_6c [100];
  uint local_8;
  
  if (((param_1 == 0) ||
      (iVar2 = **(int **)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 4), iVar2 == 0)) ||
     (pcVar3 = *(code **)(iVar2 + 0x74), pcVar3 == (code *)0x0)) {
    return 0;
  }
  (*pcVar3)(local_6c,100);
  pcVar5 = "Author";
  pcVar4 = local_6c;
  do {
    if (*pcVar4 != *pcVar5) {
LAB_680a3c8d:
      return 0;
    }
    if (*pcVar4 == '\0') break;
    pcVar1 = pcVar4 + 1;
    if (*pcVar1 != pcVar5[1]) goto LAB_680a3c8d;
    pcVar4 = pcVar4 + 2;
    pcVar5 = pcVar5 + 2;
  } while (*pcVar1 != '\0');
  return 0;
}



// ============================================================
// Function: media_hasCastScript (FUN_680a3cc0)
// Address: 680a3cc0
// Size: 53 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_hasCastScript(int param_1)

{
  int iVar1;
  uint uVar2;
  uint in_EAX;
  uint3 uVar3;
  
  uVar2 = in_EAX >> 8;
  if (param_1 != 0) {
    iVar1 = **(int **)(*(int *)(**(int **)(param_1 + 8) + 0x51c) + 4);
    uVar3 = (uint3)((uint)iVar1 >> 8);
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x1c4) != 0)) {
      return CONCAT31(uVar3,1);
    }
    uVar2 = (uint)uVar3;
  }
  return uVar2 << 8;
}



// ============================================================
// Function: media_getCastMemberCount (FUN_680a3d00)
// Address: 680a3d00
// Size: 125 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getCastMemberCount(int *param_1,int *param_2)
{
  uint uVar1;
  int iVar2;
  undefined4 local_10;
  
  if (*param_1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(*param_1 + 0x20);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
      Ordinal_2330();
      local_10 = DAT_68196374;
    }
  }
  *param_2 = (int)*(short *)(iVar2 + 0x478);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: media_getCastMemberByNum (FUN_680a3d80)
// Address: 680a3d80
// Size: 197 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getCastMemberByNum(int *param_1,int param_2,int *param_3)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar3 = *param_1;
  iVar1 = 0;
  if (iVar3 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar3 + 0x20);
  }
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar1 = *(int *)(piVar2[1] + 8);
    if (iVar3 == 0) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_10 = DAT_68196374;
    local_c = 0;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  if (((0 < param_2) && (param_2 <= (short)piVar2[0x11e])) || (0x4000 < param_2)) {
    param_3[3] = param_2;
    *param_3 = *param_1;
    param_3[1] = iVar1;
    param_3[2] = 0;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_findCastMemberByName (FUN_680a3e50)
// Address: 680a3e50
// Size: 307 bytes
// Params: int * param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_findCastMemberByName(int *param_1,undefined4 param_2,int *param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  local_20 = 0;
  local_18 = (int *)0x0;
  if (iVar1 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar1 + 0x20);
  }
  local_1c = 0;
  if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
    local_1c = *(int *)(piVar4[1] + 8);
    if (iVar1 == 0) {
      iVar1 = *piVar4;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  local_18 = scoreEngine_getFrameDataPtr((int)piVar4);
  if (local_18 == (int *)0x0) {
    local_20 = -0x7ffbffec;
  }
  else {
    iVar1 = scoreEngine_getFrameSize((int)local_18);
    while (iVar1 != 0) {
      if (*(int *)(iVar1 + 4) != 0) {
        uVar2 = Ordinal_1114(*(int *)(iVar1 + 4));
        iVar3 = Ordinal_1255(param_2,uVar2);
        if (iVar3 == 0) {
          param_3[3] = (int)*(short *)(iVar1 + 0xc);
          Ordinal_1115(*(undefined4 *)(iVar1 + 4));
          goto LAB_680a3f22;
        }
        Ordinal_1115(*(undefined4 *)(iVar1 + 4));
      }
      iVar1 = scoreEngine_getFrameSize((int)local_18);
    }
    local_20 = -0x7ffbf43c;
  }
LAB_680a3f22:
  if (piVar4 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  rendering_getDispatchState((int *)&local_18);
  *param_3 = *param_1;
  param_3[1] = local_1c;
  param_3[2] = 0;
  if (local_20 != 0) {
    param_3[3] = 1;
  }
  return 0;
}



// ============================================================
// Function: media_getCastMemberPosition (FUN_680a3f90)
// Address: 680a3f90
// Size: 192 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getCastMemberPosition(int *param_1,int param_2,int *param_3)
{
  short sVar1;
  int iVar2;
  short extraout_var;
  int *piVar3;
  int iVar4;
  short local_18 [2];
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(iVar2 + 0x20);
  }
  iVar4 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    if (iVar2 == 0) {
      iVar2 = *piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar4 = iVar2;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  iVar2 = rendering_getMemberDataBlock(iVar4,0,param_2,-1,(undefined4 *)local_18);
  if (iVar2 != 0) {
    sVar1 = scoreEngine_getChannelCount((int)piVar3,local_18[0]);
    *param_3 = (int)sVar1;
    param_3[1] = (int)extraout_var;
  }
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_initCastSlot (FUN_680a4050)
// Address: 680a4050
// Size: 53 bytes
// Params: undefined4 * param_1, short * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_initCastSlot(undefined4 *param_1,short *param_2,int param_3)

{
  Ordinal_1130(param_3,0x14);
  *(int *)(param_3 + 0x10) = (int)param_2[1];
  *(int *)(param_3 + 0xc) = (int)*param_2;
  *(undefined4 *)(param_3 + 4) = *param_1;
  *(undefined4 *)(param_3 + 8) = 1;
  return 0;
}



// ============================================================
// Function: media_getCastProperty (FUN_680a4090)
// Address: 680a4090
// Size: 160 bytes
// Params: int * param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getCastProperty(int *param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar1 + 0x20);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  uVar2 = Ordinal_603(*(int *)(*(int *)(iVar3 + 8) + 0x20),0,param_2);
  *param_3 = uVar2;
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: media_getCastPropertyData (FUN_680a4130)
// Address: 680a4130
// Size: 228 bytes
// Params: int * param_1, int param_2, undefined1 * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getCastPropertyData(int *param_1,int param_2,undefined1 *param_3,int param_4)
{
  int iVar1;
  int iVar2;
  undefined4 local_24;
  int *local_20;
  undefined4 local_1c;
  short local_18 [2];
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  local_1c = 0;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x20);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  Ordinal_601(*(int *)(*(int *)(iVar2 + 8) + 0x20),0,local_18,&local_20,&local_24);
  iVar1 = Ordinal_605(*(undefined4 **)(*(int *)(iVar2 + 8) + 0x20),0,(int)(short)param_2);
  if ((local_18[0] < iVar1) || (*(short *)(*local_20 + -4 + iVar1 * 4) != param_2)) {
    *param_3 = 0;
  }
  else {
    Ordinal_604(*(int *)(*(int *)(iVar2 + 8) + 0x20),0,iVar1,param_3,param_4);
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: media_setCastProperty (FUN_680a4220)
// Address: 680a4220
// Size: 208 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setCastProperty(int *param_1,int param_2,int param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar2 = *param_1;
  if (iVar2 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar2 + 0x20);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  if (param_3 == 0) {
    Ordinal_607(*(undefined4 **)(*(int *)(iVar4 + 8) + 0x20),(int *)0x0,(int)(short)param_2,
                (int)(short)param_2);
  }
  else {
    iVar2 = Ordinal_609(*(undefined4 **)(*(int *)(iVar4 + 8) + 0x20),0,param_2);
    iVar3 = Ordinal_1201(param_3);
    if (iVar3 < 0x7fff) {
      sVar1 = Ordinal_1201(param_3);
    }
    else {
      sVar1 = 0x7fff;
    }
    Ordinal_608(*(int *)(*(int *)(iVar4 + 8) + 0x20),0,iVar2,param_3,(int)sVar1);
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: media_findCastByName (FUN_680a42f0)
// Address: 680a42f0
// Size: 180 bytes
// Params: int * param_1, undefined1 * param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_findCastByName(int *param_1,undefined1 *param_2,int param_3,int *param_4)
{
  int iVar1;
  short sVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar1 + 0x20);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  sVar2 = Ordinal_349(*(int *)(iVar3 + 4),param_2,param_3,(undefined4 *)0x0);
  Ordinal_135(*(int *)(iVar3 + 4));
  *param_4 = (int)sVar2;
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: media_findCastByNameEx (FUN_680a43b0)
// Address: 680a43b0
// Size: 273 bytes
// Params: int * param_1, undefined1 * param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_findCastByNameEx(int *param_1,undefined1 *param_2,undefined4 param_3,int *param_4)
{
  int iVar1;
  short sVar2;
  int iVar3;
  int local_42c;
  int *local_428;
  undefined4 local_424;
  undefined4 local_420;
  undefined1 local_41c [1044];
  uint local_8;
  
  local_420 = 0;
  memset(local_41c,0,0x414);
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = *(int *)(iVar1 + 0x20);
    if ((iVar3 != 0) && (*(int *)(iVar3 + 4) != 0)) {
      Ordinal_2330();
      local_424 = 0;
      local_428 = DAT_68196374;
      DAT_68196374 = &local_42c;
      local_42c = iVar1;
    }
  }
  Ordinal_1309(&local_420,0x400,param_3,2);
  sVar2 = Ordinal_349(*(int *)(iVar3 + 4),param_2,1,&local_420);
  Ordinal_135(*(int *)(iVar3 + 4));
  *param_4 = (int)sVar2;
  DAT_68196374 = local_428;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: media_deleteCastMember (FUN_680a44d0)
// Address: 680a44d0
// Size: 131 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_deleteCastMember(int *param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x20);
    if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  scoreEngine_deleteFrame(piVar2,param_2);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_saveCastMember (FUN_680a4560)
// Address: 680a4560
// Size: 205 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_saveCastMember(int *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int local_42c;
  int *local_428;
  undefined4 local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    iVar2 = 0;
  }
  else {
    iVar2 = *(int *)(iVar1 + 0x20);
    if ((iVar2 != 0) && (*(int *)(iVar2 + 4) != 0)) {
      Ordinal_2330();
      local_424 = 0;
      local_428 = DAT_68196374;
      DAT_68196374 = &local_42c;
      local_42c = iVar1;
    }
  }
  Ordinal_1309(local_420,0x400,param_2,2);
  rendering_saveCastMember(iVar2,local_420,param_3,(void *)0x0);
  if (iVar2 != 0) {
    DAT_68196374 = local_428;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_findCastByGuid (FUN_680a4630)
// Address: 680a4630
// Size: 254 bytes
// Params: int * param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_findCastByGuid(int *param_1,undefined4 param_2,int *param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  short extraout_var;
  int iVar4;
  undefined4 uVar5;
  int *local_28;
  int local_24;
  int *local_20;
  undefined4 local_1c;
  undefined4 local_18 [4];
  uint local_8;
  
  iVar2 = *param_1;
  local_28 = (int *)0x0;
  uVar5 = 0;
  if (iVar2 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = *(int *)(iVar2 + 0x20);
    if ((iVar4 != 0) && (*(int *)(iVar4 + 4) != 0)) {
      Ordinal_2330();
      local_1c = 0;
      local_20 = DAT_68196374;
      DAT_68196374 = &local_24;
      local_24 = iVar2;
    }
  }
  local_28 = scoreEngine_getScoreIterator(iVar4);
  if (local_28 != (int *)0x0) {
    iVar2 = scoreEngine_getScoreState((int)local_28);
    while (iVar2 != 0) {
      iVar3 = display_getStreamGuid(iVar2,local_18,0);
      if ((iVar3 != 0) && (iVar3 = display_releaseStreamRef(), iVar3 != 0)) {
        sVar1 = scoreEngine_getChannelCount(iVar4,(short)*(undefined4 *)(iVar2 + 4));
        *param_3 = (int)sVar1;
        param_3[1] = (int)extraout_var;
        goto LAB_680a46dd;
      }
      iVar2 = scoreEngine_getScoreState((int)local_28);
    }
    uVar5 = 0x80040001;
  }
LAB_680a46dd:
  if (iVar4 != 0) {
    DAT_68196374 = local_20;
    Ordinal_2331(param_2,uVar5);
  }
  scoreEngine_resetScore((int *)&local_28);
  return 0;
}



// ============================================================
// Function: media_getCastStreamGuid (FUN_680a4730)
// Address: 680a4730
// Size: 184 bytes
// Params: int * param_1, undefined2 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getCastStreamGuid(int *param_1,undefined2 *param_2,undefined4 *param_3)
{
  int iVar1;
  uint uVar2;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = *(uint *)(iVar1 + 0x20);
    if ((uVar2 != 0) && (*(int *)(uVar2 + 4) != 0)) {
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  local_18 = CONCAT22(param_2[2],*param_2);
  iVar1 = scoreEngine_setChannelField(uVar2,local_18);
  if (iVar1 != 0) {
    display_getStreamGuid(iVar1,param_3,1);
  }
  if (uVar2 != 0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_convertCastPoint (FUN_680a47f0)
// Address: 680a47f0
// Size: 279 bytes
// Params: int * param_1, undefined2 * param_2, undefined2 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_convertCastPoint(int *param_1,undefined2 *param_2,undefined2 *param_3)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  undefined2 local_24;
  undefined2 local_22;
  int local_20;
  undefined2 local_1c;
  undefined2 local_1a;
  undefined2 *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar3 = *param_1;
  iVar4 = 0;
  local_18 = param_2;
  if (iVar3 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(iVar3 + 0x20);
  }
  local_20 = 0;
  if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
    local_20 = *(int *)(piVar5[1] + 8);
    if (iVar3 == 0) {
      iVar3 = *piVar5;
    }
    iVar4 = piVar5[2];
    Ordinal_2330();
    local_10 = DAT_68196374;
    local_c = 0;
    param_2 = local_18;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  local_18 = (undefined2 *)**(int **)(local_20 + 4);
  if ((local_18 != (undefined2 *)0x0) && (*(int *)((int)local_18 + 0xf8) != 0)) {
    local_24 = *param_2;
    local_22 = param_2[2];
    local_1c = *param_3;
    local_1a = param_3[2];
    uVar1 = Ordinal_362(*(int *)(iVar4 + 0x20),*(int *)(iVar4 + 0x28),(undefined4 *)&local_24);
    uVar2 = Ordinal_362(*(int *)(iVar4 + 0x20),*(int *)(iVar4 + 0x28),(undefined4 *)&local_1c);
    (**(code **)((int)local_18 + 0xf8))(*(undefined4 *)(piVar5[1] + 4),uVar1,uVar2);
  }
  if (piVar5 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getCastPropertyPair (FUN_680a4910)
// Address: 680a4910
// Size: 189 bytes
// Params: int * param_1, uint param_2, uint param_3, uint * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getCastPropertyPair(int *param_1,uint param_2,uint param_3,uint *param_4,int *param_5)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if ((iVar1 != 0) && (iVar2 = *(int *)(iVar1 + 0x20), iVar2 != 0)) {
    if (*(int *)(iVar2 + 4) != 0) {
      iVar2 = *(int *)(iVar2 + 8);
      if (iVar2 == 0) {
        iVar3 = 0;
      }
      else {
        iVar3 = *(int *)(iVar2 + 0xc);
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      if ((iVar2 != 0) && (*(int *)(iVar2 + 0x1c8) != 0)) {
        param_2 = param_2 | 0x80000000;
      }
      local_14 = iVar1;
      if (iVar3 != 0) {
        DAT_68196374 = &local_14;
        cast_getPropertyPair(iVar3,param_2,param_3,param_4,param_5);
      }
    }
    DAT_68196374 = (int *)local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getCastSoundRef (FUN_680a49d0)
// Address: 680a49d0
// Size: 211 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getCastSoundRef(int *param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  iVar2 = 0;
  uVar4 = 0;
  if (iVar1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(iVar1 + 0x20);
  }
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    if (iVar1 == 0) {
      iVar1 = *piVar3;
    }
    if (piVar3[2] != 0) {
      iVar2 = *(int *)(piVar3[2] + 0xc);
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if ((*param_2 == 0x285) || (*param_2 == 0x290)) {
    if (param_2[1] == 0x293) {
      iVar1 = events_getScoreSoundRef(iVar2);
      param_2[2] = iVar1;
      if (iVar1 == 0) {
        uVar4 = 0x80040002;
      }
    }
    else {
      uVar4 = 0x80040bbc;
    }
  }
  else {
    uVar4 = 0x80040bbb;
  }
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_2,uVar4);
  }
  return 0;
}



// ============================================================
// Function: media_setCastSoundRef (FUN_680a4ab0)
// Address: 680a4ab0
// Size: 212 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setCastSoundRef(int *param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar3 = *param_1;
  iVar1 = 0;
  uVar4 = 0;
  if (iVar3 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar3 + 0x20);
  }
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if (iVar3 == 0) {
      iVar3 = *piVar2;
    }
    if (piVar2[2] != 0) {
      iVar1 = *(int *)(piVar2[2] + 0xc);
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  if ((*param_2 == 0x285) || (*param_2 == 0x290)) {
    if (param_2[1] == 0x293) {
      if (param_2[2] == 0) {
        uVar4 = 0x80040bbe;
      }
      else {
        events_setScoreSoundRef(iVar1,param_2[2]);
      }
    }
    else {
      uVar4 = 0x80040bbc;
    }
  }
  else {
    uVar4 = 0x80040bbb;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_2,uVar4);
  }
  return 0;
}



// ============================================================
// Function: media_setCastDataEntry (FUN_680a4b90)
// Address: 680a4b90
// Size: 152 bytes
// Params: void * this, short param_1, undefined4 param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall media_setCastDataEntry(void *this,short param_1,undefined4 param_2)
{
  uint uVar1;
  int iVar2;
  int unaff_EDI;
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  Ordinal_1233(&local_408,param_2);
  if (local_408 == 0xff) {
    uVar1 = Ordinal_1201(local_407);
  }
  else {
    uVar1 = (uint)local_408;
  }
  iVar2 = Ordinal_37((undefined4 *)((int)this + 0x46c),param_1,&local_408,uVar1 + 2);
  if (iVar2 == 0) {
    return 0;
  }
  rendering_getChannelProperty(unaff_EDI,5,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: media_getMediaTypeRef (FUN_680a4c30)
// Address: 680a4c30
// Size: 98 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall media_getMediaTypeRef(int param_1,int *param_2)

{
  int param_4;
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  int unaff_EDI;
  undefined4 *local_c;
  char local_5;
  
  puVar1 = (undefined4 *)cast_lookupDataEntry(*(int *)(param_1 + 0x46c),in_EAX,1);
  local_c = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    local_5 = '\0';
    props_loadStringValue(unaff_EDI,&local_5,param_2);
  }
  else {
    iVar2 = Ordinal_1114();
    props_loadStringValue(unaff_EDI,(char *)(iVar2 + 1),puVar1);
    Ordinal_1113(&local_c);
  }
  if ((*param_2 == 0x40) || (uVar3 = 0x80040002, *param_2 == 0x43)) {
    uVar3 = 0;
  }
  return uVar3;
}



// ============================================================
// Function: media_setCastChannelField (FUN_680a4ca0)
// Address: 680a4ca0
// Size: 108 bytes
// Params: uint param_1, int param_2, short * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_setCastChannelField(uint param_1,int param_2,short *param_3)

{
  int iVar1;
  
  if ((*param_3 != -1) || (-1 < param_3[1])) {
    iVar1 = scoreEngine_setChannelField(param_1,*(undefined4 *)param_3);
    if ((iVar1 == 0) || (*(int *)(iVar1 + 8) != 4)) {
      return 0x80040001;
    }
  }
  if ((*param_3 == -1) && (param_3[1] < 0)) {
    param_3[1] = param_3[1] + -1;
  }
  *(undefined4 *)(param_1 + 0x4d8) = *(undefined4 *)param_3;
  rendering_getChannelProperty(param_2,5,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: media_convertCastToStage (FUN_680a4d10)
// Address: 680a4d10
// Size: 214 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_convertCastToStage(int *param_1,undefined4 *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  iVar1 = *param_1;
  iVar3 = 0;
  local_38 = 0;
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x20);
  }
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if (iVar1 == 0) {
      iVar1 = *piVar2;
    }
    iVar3 = piVar2[2];
    Ordinal_2330();
    local_2c = 0;
    local_30 = DAT_68196374;
    DAT_68196374 = &local_34;
    local_34 = iVar1;
  }
  local_40 = param_2[1];
  local_3c = *param_2;
  iVar1 = Ordinal_184(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),local_18,local_28);
  if (iVar1 == 0) {
    local_38 = 0x80040001;
  }
  else {
    Ordinal_1072(&local_40,local_18,local_28);
    param_2[1] = local_40;
    *param_2 = local_3c;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_30;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_convertStageToCast (FUN_680a4df0)
// Address: 680a4df0
// Size: 214 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_convertStageToCast(int *param_1,undefined4 *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  int local_34;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28 [4];
  undefined4 local_18 [4];
  uint local_8;
  
  iVar1 = *param_1;
  iVar3 = 0;
  local_38 = 0;
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x20);
  }
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if (iVar1 == 0) {
      iVar1 = *piVar2;
    }
    iVar3 = piVar2[2];
    Ordinal_2330();
    local_2c = 0;
    local_30 = DAT_68196374;
    DAT_68196374 = &local_34;
    local_34 = iVar1;
  }
  local_40 = param_2[1];
  local_3c = *param_2;
  iVar1 = Ordinal_184(*(int *)(iVar3 + 0x20),*(int *)(iVar3 + 0x28),local_28,local_18);
  if (iVar1 == 0) {
    local_38 = 0x80040001;
  }
  else {
    Ordinal_1072(&local_40,local_18,local_28);
    param_2[1] = local_40;
    *param_2 = local_3c;
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_30;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_getMediaTypeData (FUN_680a4ed0)
// Address: 680a4ed0
// Size: 761 bytes
// Params: undefined4 param_1, int * param_2, int param_3, undefined2 * param_4, int * param_5, uint param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getMediaTypeData(undefined4 param_1,int *param_2,int param_3,undefined2 *param_4,int *param_5,
                 uint param_6)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int local_34;
  int *local_30;
  int *local_2c;
  undefined4 local_24;
  int local_20;
  int *local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_2;
  uVar5 = 0;
  local_34 = 0;
  local_30 = (int *)0x0;
  if (iVar1 == 0) {
    local_2c = (int *)0x0;
  }
  else {
    local_2c = *(int **)(iVar1 + 0x20);
  }
  piVar3 = (int *)0x0;
  if ((local_2c != (int *)0x0) && (local_2c[1] != 0)) {
    local_24 = *(int **)(local_2c[1] + 8);
    if (iVar1 == 0) {
      iVar1 = *local_2c;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    piVar3 = local_24;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  if (param_3 == 0) {
    if (local_2c != (int *)0x0) {
      local_34 = local_2c[4];
    }
  }
  else {
    iVar1 = scoreEngine_getChannelField((int)local_2c,*(short *)(param_3 + 0xc));
    if ((iVar1 != 0) && (*(int *)(iVar1 + 0x14) == 0)) {
      local_34 = *(int *)(iVar1 + 0x24);
    }
  }
  if (param_4 != (undefined2 *)0x0) {
    local_24 = (int *)CONCAT22(param_4[2],*param_4);
    local_30 = (int *)scoreEngine_setChannelField((uint)local_2c,local_24);
  }
  switch(param_1) {
  case 0x17:
    if (param_6 == 4) {
      if (local_34 == 0) {
        *param_5 = 0;
      }
      else {
        iVar1 = js_initAtomTable(local_34);
        *param_5 = iVar1;
      }
      goto LAB_680a5130;
    }
    break;
  case 0x18:
    if ((local_30 != (int *)0x0) && (param_6 == 4)) {
      *param_5 = local_30[3];
      goto LAB_680a5130;
    }
    break;
  case 0x19:
    iVar1 = rendering_getMemberProperty(local_30,0,&local_24);
    if ((uint)(iVar1 * 4) <= param_6) {
      piVar3 = (int *)Ordinal_1114(local_24);
      iVar4 = 0;
      if (param_6 >> 2 != 0) {
        do {
          *param_5 = 0;
          if (iVar4 < iVar1) {
            *param_5 = *piVar3;
            piVar3 = piVar3 + 1;
          }
          iVar4 = iVar4 + 1;
          param_5 = param_5 + 1;
        } while (iVar4 < (int)(param_6 >> 2));
      }
    }
    Ordinal_1113(&local_24);
    goto LAB_680a5130;
  case 0x1a:
    local_24 = (int *)0x0;
    if (local_30 != (int *)0x0) {
      iVar1 = rendering_getMemberProperty(local_30,0,&local_24);
      if ((uint)(iVar1 * 4) <= param_6) {
        iVar4 = 0;
        if (param_6 >> 2 != 0) {
          do {
            if ((iVar4 < iVar1) && (0 < local_30[3])) {
              iVar2 = strings_openMediaStream(local_34,*(int *)(*(unsigned int *)(size_t)local_24 /* FIXUP(C2100): cast for dereference */ + iVar4 * 4),local_30[3]);
              param_5[iVar4] = iVar2;
            }
            else {
              param_5[iVar4] = -1;
            }
            iVar4 = iVar4 + 1;
          } while (iVar4 < (int)(param_6 >> 2));
        }
        Ordinal_1113(&local_24);
        goto LAB_680a5130;
      }
      Ordinal_1113(&local_24);
    }
    break;
  case 0x1b:
    if (param_6 == 4) {
      *param_5 = local_34;
      goto LAB_680a5130;
    }
    break;
  case 0x1c:
    iVar1 = *(int *)(*(int *)(*piVar3 + 0x18) + 0xc);
    if ((iVar1 == 0) || (piVar3 = *(int **)(iVar1 + 0x20), piVar3 == (int *)0x0)) {
      iVar1 = 0;
LAB_680a4fea:
      piVar3 = (int *)0x0;
    }
    else {
      iVar1 = *piVar3;
      if (iVar1 == 0) goto LAB_680a4fea;
      piVar3 = *(int **)(iVar1 + 0x20);
    }
    iVar4 = 0;
    if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
      if (iVar1 == 0) {
        iVar1 = *piVar3;
      }
      Ordinal_2330();
      local_18 = 0;
      local_1c = DAT_68196374;
      iVar4 = iVar1;
      DAT_68196374 = &local_20;
      local_20 = iVar1;
    }
    iVar1 = media_getVtableFunc(*(int **)(iVar4 + 0x28));
    *param_5 = iVar1;
    if (piVar3 != (int *)0x0) {
      DAT_68196374 = local_1c;
      Ordinal_2331();
    }
    goto LAB_680a5130;
  case 0x1d:
    if (param_6 == 4) {
      *param_5 = *param_2;
      goto LAB_680a5130;
    }
  }
  uVar5 = 0x80040001;
LAB_680a5130:
  if (local_2c != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331(param_2,uVar5);
  }
  return 0;
}



// ============================================================
// Function: media_setCastScriptFlag (FUN_680a51f0)
// Address: 680a51f0
// Size: 135 bytes
// Params: int * param_1, byte param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setCastScriptFlag(int *param_1,byte param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x20);
  }
  iVar3 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if (iVar1 == 0) {
      iVar1 = *piVar2;
    }
    iVar3 = piVar2[2];
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  *(uint *)(iVar3 + 0x1c4) = (uint)param_2;
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_setCastPreloadFlag (FUN_680a5280)
// Address: 680a5280
// Size: 135 bytes
// Params: int * param_1, byte param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setCastPreloadFlag(int *param_1,byte param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar1 = *param_1;
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(iVar1 + 0x20);
  }
  iVar3 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if (iVar1 == 0) {
      iVar1 = *piVar2;
    }
    iVar3 = piVar2[2];
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  *(uint *)(iVar3 + 0x1c8) = (uint)param_2;
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}
