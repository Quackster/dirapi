// Module: playback
// Topic: Cast member operations, file loading, score creation, media import
// Address range: 0x680d3900 - 0x680d5f10
// Functions (29):
//   playback_dispatchMemberOp, playback_loadScoreOrFontMap, playback_getMediaFileInfo, playback_resolveFilePath, playback_initScoreChannelState
//   playback_validateMediaFormat, playback_isMediaLoaded, playback_processScoreUpdate, playback_processLoadedChannels, playback_initMediaChannels
//   playback_readMediaHeader, playback_validateMediaHeader, playback_loadFontMapData, playback_initCastMembers, playback_loadCastData
//   playback_processMediaChannelData, playback_applyLoadedScoreData, playback_resolveMediaDependencies, playback_processMediaImport, playback_buildMediaTable
//   playback_indexMediaEntries, playback_resolveMediaPath, playback_createMediaBuffer, playback_loadMediaBlock, playback_processLoadedMedia
//   playback_initMediaLoadState, playback_loadMediaData, playback_resolveExternalMedia, playback_finalizeMediaLoad

// ============================================================
// Function: playback_dispatchMemberOp (playback_dispatchMemberOp)
// Address: 680d3900
// Size: 831 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_dispatchMemberOp(int *param_1)

{
  int param_4;
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int *piVar3;
  undefined3 extraout_var_00;
  int *piVar4;
  undefined4 local_8;
  
  iVar2 = param_1[1];
  piVar3 = (int *)*param_1;
  local_8 = 0;
  if (iVar2 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(iVar2 + 0x20);
  }
  switch(param_1[2]) {
  case 0:
    iVar2 = playback_applyMemberImport(iVar2);
    goto LAB_680d393c;
  case 1:
    if (param_1[9] == 0) {
      iVar2 = playback_openMemberStream(iVar2);
    }
    else {
      iVar2 = playback_readMemberStream(iVar2);
    }
    break;
  case 2:
    iVar2 = playback_detachMember();
    if (iVar2 != 0) {
      return 0;
    }
    return 1;
  case 3:
    iVar2 = playback_reattachMember();
    if (iVar2 != 0) {
      return 0;
    }
    return 1;
  case 4:
    iVar2 = playback_reassignMember((int)piVar3,iVar2);
LAB_680d393c:
    if (iVar2 == 0) {
      return 0;
    }
    goto switchD_680d392d_caseD_d;
  case 5:
    iVar2 = playback_saveMemberData(iVar2,piVar3);
    break;
  case 6:
    iVar2 = playback_writeMemberStream(param_1 + 4,piVar4,(int)piVar3,0);
    if (iVar2 != 0) {
      return 0;
    }
    return 1;
  case 7:
    if (param_1[5] != FOURCC_XMED) goto switchD_680d392d_caseD_d;
    iVar2 = playback_dispatchMemberRead(piVar4,param_1[4],(int *)param_1[6]);
    break;
  case 8:
    playback_discardMemberChanges();
    return 1;
  case 9:
    if ((piVar3[0xb] & 0x200U) != 0) goto switchD_680d392d_caseD_a;
    param_1[3] = 0;
    goto switchD_680d392d_caseD_d;
  case 10:
switchD_680d392d_caseD_a:
    iVar2 = playback_getMemberDataSize();
    param_1[3] = iVar2;
    return 1;
  case 0xb:
    iVar2 = playback_exportMemberData(piVar4);
    break;
  case 0xc:
    bVar1 = playback_importMemberFromClipboard(iVar2);
    iVar2 = CONCAT31(extraout_var,bVar1);
    break;
  default:
    goto switchD_680d392d_caseD_d;
  case 0xe:
    iVar2 = piVar3[0x17];
    piVar3 = (int *)lingo_getGlobalRef(*piVar3);
    iVar2 = media_getModifiedTime(piVar3,iVar2);
    param_1[3] = iVar2;
    return 1;
  case 0xf:
    param_1[3] = 0x15;
    return 1;
  case 0x10:
    playback_loadMemberFromScore(iVar2,(int)piVar3,param_1[3]);
    return 1;
  case 0x11:
    playback_writeMemberToStream(piVar4);
    return 1;
  case 0x12:
    param_1[3] = 1;
    return 1;
  case 0x13:
    iVar2 = crt_negotiateFormat(param_1 + 4,param_1[3],FOURCC_XMED);
    param_1[3] = iVar2;
    return 1;
  case 0x14:
    iVar2 = playback_navigateFrame(param_1[3],param_1[4],(uint *)param_1[5]);
    param_1[6] = iVar2;
    if (iVar2 != 0) {
      return 0;
    }
    return 1;
  case 0x15:
    iVar2 = media_initVtable(iVar2,(int *)piVar3[0x15],param_1[3]);
    param_1[4] = iVar2;
    if (iVar2 == -0x7ffbf830) {
      param_1[4] = -0x7ffbf821;
      return 1;
    }
    goto LAB_680d394a;
  case 0x19:
    iVar2 = playback_getMemberProperty(param_1);
    if (iVar2 != 0) {
      return 1;
    }
    goto switchD_680d392d_caseD_d;
  case 0x1a:
    iVar2 = playback_setMemberBoundsProperty();
    if (iVar2 != 0) {
      return 1;
    }
switchD_680d392d_caseD_d:
    iVar2 = rendering_validateState(param_1);
    break;
  case 0x1d:
    bVar1 = media_compareScoreEntries(iVar2,(int)piVar3,param_1[3]);
    param_1[4] = CONCAT31(extraout_var_00,bVar1);
    return 1;
  case 0x1e:
    iVar2 = playback_createMemberInstance((int)param_1);
    break;
  case 0x1f:
    playback_updateMemberChannelRef();
    return 1;
  }
  if (iVar2 != 0) {
LAB_680d394a:
    local_8 = 1;
  }
  return local_8;
}



// ============================================================
// Function: playback_loadScoreOrFontMap (playback_loadScoreOrFontMap)
// Address: 680d3cc0
// Size: 77 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4, int * param_5, undefined4 * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
playback_loadScoreOrFontMap(undefined4 param_1,int param_2,int param_3,int param_4,int *param_5,undefined4 *param_6
            )

{
  int iVar1;
  
  if (param_6 == (undefined4 *)0x0) {
    playback_loadScoreDataDirect(param_2,param_3,param_4,param_5);
  }
  else {
    iVar1 = playback_openScore(param_2,param_3,param_4,param_5,param_6);
    if (iVar1 != 0) {
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: playback_getMediaFileInfo (playback_getMediaFileInfo)
// Address: 680d3d10
// Size: 121 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_getMediaFileInfo(undefined4 *param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  local_8 = 0;
  bVar1 = false;
  iVar2 = Ordinal_1403(&local_8,param_2);
  if (iVar2 != 0) {
    uVar3 = Ordinal_1433(*param_1,param_2);
    iVar2 = Ordinal_1431(local_8,0,*param_1,uVar3);
    if (iVar2 != 0) {
      iVar2 = Ordinal_1432(local_8,0,0);
      if (iVar2 != 0) {
        Ordinal_1407(param_1);
        bVar1 = true;
      }
    }
  }
  iVar2 = Ordinal_1042();
  if ((iVar2 != 0) || (!bVar1)) {
    Ordinal_1407(&local_8);
  }
  return local_8;
}



// ============================================================
// Function: playback_resolveFilePath (playback_resolveFilePath)
// Address: 680d3d90
// Size: 17 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool playback_resolveFilePath(void)

{
  short in_AX;
  
  return (bool)('\x01' - ((int)in_AX % 0x17 != 0));
}



// ============================================================
// Function: playback_initScoreChannelState (playback_initScoreChannelState)
// Address: 680d3db0
// Size: 376 bytes
// Params: int * param_1, undefined2 * param_2, int param_3, undefined4 param_4, undefined4 * param_5
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool playback_initScoreChannelState(int *param_1,undefined2 *param_2,int param_3,undefined4 param_4,
                 undefined4 *param_5)

{
  short sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined3 extraout_var;
  bool bVar5;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  local_10 = 0;
  local_c = 0;
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  iVar3 = playback_openScore(param_3,FOURCC_DRCF,0x400,&local_c,&local_8);
  if ((local_8 == 0) && (iVar3 == 7)) {
    iVar3 = playback_openScore(param_3,FOURCC_VWCF,0x400,&local_c,&local_8);
  }
  bVar5 = false;
  if (local_8 != 0) {
    local_10 = playback_getMediaFileInfo(&local_8,local_c);
    bVar5 = local_10 != 0;
    iVar4 = bitmap_readScoreHeader(param_1,param_2,local_10,local_c,param_4);
    bVar5 = iVar4 != 0 && bVar5;
    Ordinal_1407(&local_8);
    Ordinal_1407(&local_10);
  }
  if (iVar3 != 0) {
    if (iVar3 == 3) {
      iVar3 = -0x74;
    }
    else {
      if (iVar3 != 6) goto LAB_680d3ea0;
      iVar3 = -0x7a;
    }
    lingo_formatDebugMsg(param_1,iVar3);
  }
LAB_680d3ea0:
  if (bVar5) {
    sVar1 = param_2[1];
    if ((0x458 < sVar1) &&
       (((bVar2 = playback_resolveFilePath(), CONCAT31(extraout_var,bVar2) != 0 || (sVar1 == 0x163c)) ||
        (iVar3 = crt_isMediaFormat(*(int **)(param_3 + 4)), iVar3 != 0)))) {
      if (param_5 != (undefined4 *)0x0) {
        *param_5 = 1;
      }
      param_2[1] = param_2[0x12];
    }
  }
  else {
    iVar3 = lingo_getMovieRef((int)param_1);
    if (iVar3 == 0) {
      lingo_formatDebugMsg(param_1,-0x1ad);
      return false;
    }
  }
  return bVar5;
}



// ============================================================
// Function: playback_validateMediaFormat (playback_validateMediaFormat)
// Address: 680d3f30
// Size: 419 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall playback_validateMediaFormat(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  uint unaff_EDI;
  int local_8;
  
  iVar3 = *(int *)(param_2 + 0x18);
  uVar4 = 0;
  local_8 = 0;
  if (in_EAX < FOURCC_SCVX) {
    if (in_EAX == FOURCC_SCVW) {
LAB_680d4057:
      bitmap_readAltStyleRunStream(*(int *)(param_2 + 0x20),*param_1,unaff_EDI);
      goto LAB_680d4082;
    }
    if (FOURCC_Fmap < in_EAX) {
      if (in_EAX != FOURCC_Gmap) {
        if (in_EAX == FOURCC_MCsL) {
          bitmap_importCastMembers(*(int *)(param_2 + 0x20),*param_1,unaff_EDI);
          goto LAB_680d4082;
        }
        if (in_EAX != FOURCC_PICT) goto LAB_680d4090;
      }
      goto LAB_680d4057;
    }
    if (in_EAX == FOURCC_Fmap) goto LAB_680d4057;
    if (in_EAX < FOURCC_Chao) {
      if (((in_EAX == FOURCC_Chan) || (in_EAX == FOURCC_BITD)) || (in_EAX == FOURCC_CLUT))
      goto LAB_680d4057;
    }
    else if (in_EAX == FOURCC_FXmp) goto LAB_680d4057;
  }
  else {
    if (in_EAX < FOURCC_VWSD) {
      if (in_EAX == FOURCC_VWSC) {
        bitmap_readScoreData(*(int **)(param_2 + 0x20),*param_1,unaff_EDI);
      }
      else if (in_EAX < FOURCC_VWFJ) {
        if (in_EAX == FOURCC_VWFI) {
          bitmap_readCastFlags(*(uint *)(param_2 + 0x20),*param_1,unaff_EDI);
        }
        else {
          if (in_EAX == FOURCC_STXT) goto LAB_680d4057;
          if (in_EAX != FOURCC_Sord) goto LAB_680d4090;
          local_8 = playback_getMediaFileInfo(param_1,unaff_EDI);
          if (local_8 == 0) goto LAB_680d4095;
          bitmap_readPaletteMap(*(int *)(param_2 + 0x20),local_8,unaff_EDI);
        }
      }
      else {
        if (in_EAX != FOURCC_VWLB) goto LAB_680d4090;
        bitmap_readStyleRunStream(*(int *)(param_2 + 0x20),*param_1,unaff_EDI);
      }
    }
    else if (in_EAX == FOURCC_VWTL) {
      bitmap_readRegPoints(*(int *)(param_2 + 0x20),*param_1,unaff_EDI);
    }
    else {
      if (in_EAX != FOURCC_VWtc) {
        if (in_EAX != FOURCC_snd) goto LAB_680d4090;
        goto LAB_680d4057;
      }
      bitmap_readMemberBuffer(*(int **)(param_2 + 0x20),*param_1,unaff_EDI);
    }
LAB_680d4082:
    if (local_8 != 0) {
      Ordinal_1407(&local_8);
    }
  }
LAB_680d4090:
  uVar4 = 1;
LAB_680d4095:
  iVar2 = Ordinal_1042();
  if (iVar2 != 0) {
    piVar1 = *(int **)(param_2 + 0x18);
    iVar2 = lingo_getMovieRef((int)piVar1);
    if (iVar2 == 0) {
      lingo_formatDebugMsg(piVar1,-0x74);
    }
  }
  iVar3 = lingo_getMovieRef(iVar3);
  if (iVar3 == 0) {
    return uVar4;
  }
  return 0;
}



// ============================================================
// Function: playback_isMediaLoaded (FUN_680d40e0)
// Address: 680d40e0
// Size: 127 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall playback_isMediaLoaded(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  int unaff_EBX;
  bool bVar2;
  undefined4 local_c;
  int local_8;
  
  local_8 = 0;
  iVar1 = playback_openScore(param_2,unaff_EBX,0x400,&local_c,&local_8);
  bVar2 = local_8 != 0;
  if (bVar2) {
    playback_validateMediaFormat(&local_8,param_3);
  }
  if (iVar1 != 0) {
    if (iVar1 == 3) {
      iVar1 = -0x74;
    }
    else {
      if (iVar1 != 6) goto LAB_680d414c;
      iVar1 = -0x7a;
    }
    lingo_formatDebugMsg(*(int **)(param_3 + 0x18),iVar1);
  }
LAB_680d414c:
  Ordinal_1407(&local_8);
  return bVar2;
}



// ============================================================
// Function: playback_processScoreUpdate (playback_processScoreUpdate)
// Address: 680d4160
// Size: 185 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_processScoreUpdate(int param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
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
  
  uVar4 = 0;
  piVar2 = (int *)(param_1 + 0x5d4);
  iVar3 = param_1 + 0x532;
  do {
    *(undefined4 *)(iVar3 + -2) = 1;
    iVar1 = media_getResourceSlot(*(int *)(*(int *)(*(int *)(param_1 + 4) + 8) + 4),uVar4);
    if (iVar1 != 0) {
      local_34 = 0;
      local_30 = 0;
      local_2c = 0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = 0;
      local_c = 0;
      *piVar2 = iVar1;
      Ordinal_1656(iVar1,&local_34);
      Ordinal_1060(iVar3 + 2,0,0,local_30,local_34);
    }
    uVar4 = uVar4 + 1;
    piVar2 = piVar2 + 1;
    iVar3 = iVar3 + 0x14;
  } while ((int)uVar4 < 8);
  return 0;
}



// ============================================================
// Function: playback_processLoadedChannels (playback_processLoadedChannels)
// Address: 680d4220
// Size: 815 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_processLoadedChannels(int *param_1)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int local_884;
  undefined4 local_880;
  int local_87c;
  int local_878;
  uint local_874;
  int local_870;
  int *local_86c;
  int local_868;
  int local_864 [3];
  undefined1 local_858 [2048];
  undefined4 local_58;
  undefined4 local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c [5];
  undefined1 local_18 [16];
  uint local_8;
  
  local_870 = 0;
  iVar3 = *(int *)(param_1[8] + 4);
  local_868 = -0x640001;
  local_86c = param_1;
  uVar1 = lingo_isValidRef(iVar3);
  uVar2 = lingo_getObjectFlags(iVar3);
  *(undefined2 *)(param_1[8] + 0x524) = 0;
  iVar3 = playback_processScoreUpdate(param_1[8]);
  if ((((iVar3 != 1) && (iVar3 = rendering_transformPaletteData(param_1,local_868,local_864), iVar3 != 0)) &&
      (local_870 = Ordinal_1730(local_864[0]), local_870 != 0)) &&
     (iVar3 = Ordinal_1737(local_870,0,local_858,local_864[0]), iVar3 != 0)) {
    uVar4 = Ordinal_1605(uVar2);
    local_880 = Ordinal_1605(uVar1);
    uVar5 = Ordinal_1610(uVar2);
    uVar6 = Ordinal_1610(uVar1);
    uVar7 = Ordinal_1612(uVar2);
    Ordinal_1613(uVar2,local_870,0);
    local_874 = 0;
    local_868 = 0;
    local_878 = 0x5d4;
    do {
      local_87c = 0;
      local_58 = 0;
      local_54 = 0;
      local_50 = 0;
      local_4c = 0;
      local_48 = 0;
      local_44 = 0;
      local_40 = 0;
      local_3c = 0;
      local_38 = 0;
      local_34 = 0;
      local_30 = 0;
      if ((*(int *)(local_878 + param_1[8]) == 0) &&
         (iVar3 = Ordinal_1661(DAT_681956e0,local_874 + 0x14,local_870,&local_87c,0),
         param_1 = local_86c, iVar3 != 0)) {
        Ordinal_1656(iVar3,&local_58);
        local_884 = iVar3;
        Ordinal_1130(local_2c,0x14);
        uVar8 = Ordinal_1650(local_44,local_40,local_3c,local_54,local_58,1);
        Ordinal_1604(uVar1,local_884);
        if (local_87c != 0) {
          Ordinal_1609(uVar1,local_87c);
        }
        Ordinal_1604(uVar2,uVar8);
        Ordinal_1060(local_18,0,0,local_54,local_58);
        local_2c[0] = 0;
        Ordinal_1616(uVar2,local_18,uVar1,local_18,0,0,local_2c,0,0);
        Ordinal_1604(uVar1,local_880);
        Ordinal_1653(&local_884);
        Ordinal_1733(&local_87c);
        *(undefined4 *)(local_878 + local_86c[8]) = uVar8;
        Ordinal_1060(local_868 + 0x534 + local_86c[8],0,0,local_54,local_58);
        media_setResourceSlot(*(int *)(local_86c[6] + 4),local_874,uVar8);
        param_1 = local_86c;
      }
      local_874 = local_874 + 1;
      local_868 = local_868 + 0x14;
      local_878 = local_878 + 4;
    } while (local_878 < 0x5f4);
    Ordinal_1604(uVar2,uVar4);
    Ordinal_1604(uVar1,local_880);
    Ordinal_1609(uVar2,uVar5);
    Ordinal_1609(uVar1,uVar6);
    Ordinal_1611(uVar2,uVar7);
  }
  Ordinal_1733(&local_870);
  return 0;
}



// ============================================================
// Function: playback_initMediaChannels (playback_initMediaChannels)
// Address: 680d4550
// Size: 194 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_initMediaChannels(void)

{
  int iVar1;
  int unaff_EBX;
  int *unaff_ESI;
  undefined4 unaff_EDI;
  undefined4 local_8;
  
  local_8 = 0;
  if (unaff_EBX == 0) {
    local_8 = 1;
  }
  else {
    iVar1 = lingo_getMovieRef((int)unaff_ESI);
    if (iVar1 == 0) {
      switch(unaff_EBX) {
      case 2:
      case 0xc:
      case 0xd:
      case 0xf:
        lingo_callMethodEx(unaff_ESI,-0x72,unaff_EDI);
        return 0;
      default:
        lingo_formatDebugMsg(unaff_ESI,-0x74);
        return 0;
      case 5:
        lingo_callMethodEx(unaff_ESI,-0x71,unaff_EDI);
        return 0;
      case 6:
        lingo_formatDebugMsg(unaff_ESI,-0x7a);
        return 0;
      case 8:
        lingo_callMethodEx(unaff_ESI,-0x73,unaff_EDI);
        return 0;
      case 10:
        lingo_callMethodEx(unaff_ESI,-0x6f,unaff_EDI);
        return 0;
      case 0xb:
        lingo_callMethodEx(unaff_ESI,-0x70,unaff_EDI);
        return 0;
      case 0xe:
        lingo_callMethodEx(unaff_ESI,-0x7a,unaff_EDI);
        return 0;
      }
    }
  }
  return local_8;
}



// ============================================================
// Function: playback_readMediaHeader (playback_readMediaHeader)
// Address: 680d4650
// Size: 104 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_readMediaHeader(int *param_1,int param_2)

{
  if (param_2 == 0) {
    return 1;
  }
  if (param_2 != 3) {
    if (param_2 != 7) {
      lingo_formatDebugMsg(param_1,-0x7a);
      return 0;
    }
    lingo_formatDebugMsg(param_1,-0x1ad);
    return 0;
  }
  lingo_formatDebugMsg(param_1,-0x74);
  return 0;
}



// ============================================================
// Function: playback_validateMediaHeader (playback_validateMediaHeader)
// Address: 680d46c0
// Size: 291 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_validateMediaHeader(int param_1)

{
  int iVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  uint uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined3 extraout_var;
  int *unaff_ESI;
  uint local_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  iVar4 = rendering_getChannelDepth((int)unaff_ESI);
  if ((unaff_ESI == (int *)0x0) || (unaff_ESI[0x12] != 0)) {
    return 1;
  }
  if (unaff_ESI[5] == 0) {
    piVar5 = unaff_ESI + 0x1a;
  }
  else {
    piVar5 = (int *)(unaff_ESI[7] + 0x48c);
  }
  pvVar6 = (void *)rendering_updateChannelState((int)piVar5);
  uVar7 = strings_openMediaStream(*(int *)(iVar4 + 4),
                       (-(uint)((void *)0x800 < pvVar6) & 0xffffffe0) + FOURCC_Lctx,unaff_ESI[0xf]);
  if (uVar7 == 0xffffffff) {
    unaff_ESI[0x12] = 0;
  }
  else {
    bVar2 = stage_compileSpriteHandler(param_1,(int)(short)unaff_ESI[1],uVar7,unaff_ESI + 0x12,&local_c,pvVar6);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      lingo_formatDebugMsgEx(*unaff_ESI,-0x7e);
      local_8 = 0;
      goto LAB_680d4738;
    }
  }
  local_8 = 1;
LAB_680d4738:
  param_1 = CONCAT22((short)unaff_ESI[0x1d],(short)unaff_ESI[1]);
  if ((short)unaff_ESI[0x1d] <= *(short *)((int)unaff_ESI + 0x76)) {
    do {
      iVar4 = rendering_resolveState(*unaff_ESI,param_1);
      if (((iVar4 != 0) && (*(int *)(iVar4 + 0x4c) != 0)) && (iVar1 != 0)) {
        iVar8 = rendering_getDispatchSize(iVar4);
        uVar9 = stage_getSpriteHandlerArg(iVar1,unaff_ESI[0x12],iVar8);
        rendering_setDispatchRef(iVar4,uVar9);
      }
      sVar3 = (*(unsigned short *)((char *)&param_1 + 2)) + 1;
      param_1 = CONCAT22(sVar3,(undefined2)param_1);
    } while (sVar3 <= *(short *)((int)unaff_ESI + 0x76));
  }
  return local_8;
}



// ============================================================
// Function: playback_loadFontMapData (playback_loadFontMapData)
// Address: 680d47f0
// Size: 67 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_loadFontMapData(int *param_1,undefined4 param_2,int param_3)

{
  int in_EAX;
  uint uVar1;
  int iVar2;
  
  uVar1 = rendering_updateChannelState(in_EAX);
  if (uVar1 < 0x400) {
    iVar2 = -0x6f;
  }
  else {
    if (param_3 == 0) {
      return 0;
    }
    iVar2 = -0x67;
  }
  lingo_callMethodEx(param_1,iVar2,param_2);
  return 1;
}



// ============================================================
// Function: playback_initCastMembers (playback_initCastMembers)
// Address: 680d4840
// Size: 263 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_initCastMembers(int param_1,int param_2)

{
  int *piVar1;
  short sVar2;
  int in_EAX;
  ushort *puVar3;
  int iVar4;
  int local_8;
  
  local_8 = 0;
  if ((param_1 != 0) && (local_8 = Ordinal_1150(0,0,2), local_8 == 0)) {
    return 0;
  }
  sVar2 = 1;
  if (0 < *(short *)(in_EAX + 0x478)) {
    do {
      puVar3 = (ushort *)scoreEngine_getFrameData(in_EAX,sVar2);
      if (puVar3 != (ushort *)0x0) {
        piVar1 = *(int **)(*(int *)(in_EAX + 4) + 8);
        Ordinal_1113(puVar3 + 2);
        playback_getFontMapState((undefined4 *)(puVar3 + 10));
        iVar4 = rendering_getChannelSprite((int)piVar1,*puVar3);
        if (((iVar4 == 0) || (*(int *)(iVar4 + 0x14) != 0)) || (param_1 == 0)) {
          rendering_setChannelProperty(piVar1,(uint)*puVar3,param_2);
        }
        else {
          iVar4 = Ordinal_1152(local_8,puVar3);
          if (iVar4 == 0) {
            return local_8;
          }
        }
      }
      sVar2 = sVar2 + 1;
    } while (sVar2 <= *(short *)(in_EAX + 0x478));
  }
  if (*(int *)(in_EAX + 0x470) != 0) {
    if (*(int *)(in_EAX + 0x474) != 0) {
      Ordinal_1158(*(int *)(in_EAX + 0x470),*(int *)(in_EAX + 0x474));
      *(undefined4 *)(in_EAX + 0x474) = 0;
    }
    Ordinal_1163(in_EAX + 0x470);
  }
  playback_resetPaletteState();
  Ordinal_1163(in_EAX + 0x480);
  return local_8;
}



// ============================================================
// Function: playback_loadCastData (playback_loadCastData)
// Address: 680d4950
// Size: 78 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_loadCastData(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = Ordinal_1205();
  if (iVar2 == 0) {
    return 0;
  }
  do {
    iVar3 = iVar2;
    iVar2 = Ordinal_1205(iVar3 + 1,0x2e);
  } while (iVar2 != 0);
  if (iVar3 != 0) {
    Ordinal_1217(iVar3,4);
    sVar1 = Ordinal_1207(iVar3,&DAT_6817ce5c,4);
    if (sVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: playback_processMediaChannelData (playback_processMediaChannelData)
// Address: 680d49a0
// Size: 1278 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_processMediaChannelData(int param_1,int param_2)
{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  int iVar9;
  int *piVar10;
  int local_88c;
  int local_888;
  int local_884;
  int local_880 [2];
  undefined1 *local_878 [6];
  undefined1 *local_860;
  undefined4 local_85c;
  int local_848;
  int local_844;
  undefined4 local_840;
  undefined4 local_83c;
  undefined4 local_838;
  int *local_834;
  undefined4 local_830;
  undefined4 local_82c;
  undefined4 local_828;
  undefined4 local_824;
  undefined4 local_820 [262];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_844 = 0;
  local_840 = 0;
  local_83c = 0;
  local_838 = 0;
  local_834 = (int *)0x0;
  local_830 = 0;
  local_82c = 0;
  local_828 = 0;
  local_824 = 0;
  piVar1 = *(int **)(param_2 + 0x18);
  local_860 = local_408;
  local_888 = 0;
  local_848 = 0;
  local_88c = 0;
  local_408[0] = 0;
  local_85c = 0x400;
  local_884 = 0;
  Ordinal_294(*(int *)(*(int *)(param_2 + 0x20) + 4),param_2,*(undefined4 *)(param_1 + 4),1,
              (uint *)&local_860);
  iVar3 = rendering_dispatchUpdate(0,(int *)param_1,local_820,0);
  if (iVar3 != 0) {
    iVar3 = Ordinal_1324(local_820);
    local_888 = Ordinal_1124(iVar3 + 1);
    if (local_888 == 0) goto LAB_680d4e51;
    iVar3 = Ordinal_1310(local_820,local_888,iVar3);
    if (iVar3 != 0) {
      iVar3 = playback_loadCastData();
      if (iVar3 == 0) {
        uVar5 = *(uint *)(param_1 + 100);
        if (*(int *)(param_1 + 0x4c) != 0) {
          local_88c = Ordinal_1112(*(int *)(param_1 + 0x4c));
        }
        uVar2 = *(undefined4 *)(param_1 + 0xc);
        piVar10 = (int *)0x0;
        iVar9 = 2;
        uVar8 = 0;
        uVar7 = 0;
        puVar6 = local_820;
        iVar3 = local_88c;
        iVar4 = rendering_getDispatchFlags(0x344);
        iVar3 = rendering_blitMedia((byte *)param_2,(int)piVar1,*(int *)(param_1 + 4),iVar4,puVar6,uVar7,
                             uVar8,iVar9,piVar10,iVar3);
        if (iVar3 == 0) {
          local_884 = 1;
        }
        else {
          *(undefined4 *)(param_1 + 0xc) = uVar2;
          iVar3 = rendering_getStatePair(param_1,local_820);
          if (iVar3 != 0) {
            local_878[0] = local_408;
            Ordinal_293(*(int *)(*(int *)(param_2 + 0x20) + 4),param_2,*(undefined4 *)(param_1 + 4),
                        1,(uint *)local_878);
            uVar2 = *(undefined4 *)(*(int *)(*(int *)(param_2 + 0x20) + 8) + 0xc);
            local_834 = local_880;
            local_840 = 0x14;
            local_83c = 1;
            local_848 = param_1;
            local_844 = param_2;
            iVar3 = props_storeIntValue(uVar2,uVar5 & 1,local_834);
            if (iVar3 == 0) {
              local_838 = 0x17e;
              rendering_initState(&local_848);
              props_releaseAndClear(uVar2,local_880);
              iVar3 = props_storeIntValue(uVar2,~(uVar5 >> 1) & 1,local_880);
              if (iVar3 == 0) {
                local_838 = 0x244;
                rendering_initState(&local_848);
                props_releaseAndClear(uVar2,local_880);
                iVar3 = props_storeIntValue(uVar2,uVar5 >> 3 & 1,local_880);
                if (iVar3 == 0) {
                  local_838 = 0x54;
                  rendering_initState(&local_848);
                  props_releaseAndClear(uVar2,local_880);
                  iVar3 = props_storeIntValue(uVar2,uVar5 >> 4 & 1,local_880);
                  if (iVar3 == 0) {
                    local_838 = 0x160;
                    rendering_initState(&local_848);
                    props_releaseAndClear(uVar2,local_880);
                    iVar3 = props_storeIntValue(uVar2,uVar5 >> 5 & 1,local_880);
                    if (iVar3 == 0) {
                      local_838 = 0x1e5;
                      rendering_initState(&local_848);
                      props_releaseAndClear(uVar2,local_880);
                      iVar3 = props_storeIntValue(uVar2,uVar5 >> 6 & 1,local_880);
                      if (iVar3 == 0) {
                        local_838 = 0x1e4;
                        rendering_initState(&local_848);
                        props_releaseAndClear(uVar2,local_880);
                        iVar3 = props_storeIntValue(uVar2,uVar5 >> 8 & 1,local_880);
                        if (iVar3 == 0) {
                          local_838 = 0x233;
                          rendering_initState(&local_848);
                          props_releaseAndClear(uVar2,local_880);
                          iVar3 = props_storeIntValue(uVar2,uVar5 >> 10 & 1,local_880);
                          if (iVar3 == 0) {
                            local_838 = 0x1dc;
                            rendering_initState(&local_848);
                            props_releaseAndClear(uVar2,local_880);
                            iVar3 = props_storeIntValue(uVar2,~(uVar5 >> 9) & 1,local_880);
                            if (iVar3 == 0) {
                              local_838 = 0x234;
                              rendering_initState(&local_848);
                              props_releaseAndClear(uVar2,local_880);
                              if ((uVar5 & 0x800) == 0) {
                                uVar5 = 0;
                              }
                              else if ((uVar5 & 0x1000) == 0) {
                                if ((uVar5 & 0x2000) == 0) {
                                  uVar5 = 0xffffffff;
                                }
                                else {
                                  uVar5 = uVar5 >> 0x18;
                                }
                              }
                              else {
                                uVar5 = 0xfffffffe;
                              }
                              iVar3 = props_storeIntValue(uVar2,uVar5,local_880);
                              if (iVar3 == 0) {
                                local_838 = 0x231;
                                rendering_initState(&local_848);
                                props_releaseAndClear(uVar2,local_880);
                                local_884 = 1;
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
      else {
        local_884 = 1;
      }
    }
  }
  if (local_888 != 0) {
    Ordinal_1125(&local_888);
  }
LAB_680d4e51:
  if (local_88c != 0) {
    Ordinal_1113(&local_88c);
  }
  if (local_884 == 0) {
    iVar3 = lingo_getMovieRef((int)piVar1);
    if (iVar3 == 0) {
      lingo_formatDebugMsg(piVar1,-0x79);
    }
  }
  return 0;
}



// ============================================================
// Function: playback_applyLoadedScoreData (playback_applyLoadedScoreData)
// Address: 680d4ea0
// Size: 107 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall playback_applyLoadedScoreData(int param_1)

{
  int iVar1;
  int unaff_ESI;
  undefined4 uVar2;
  int *local_8;
  
  uVar2 = 0;
  local_8 = (int *)0x0;
  local_8 = rendering_getDispatchByChannel(*(int *)(unaff_ESI + 0x18),*(short *)(param_1 + 4));
  if (local_8 != (int *)0x0) {
    iVar1 = rendering_getMemberCache((int)local_8);
    while (iVar1 != 0) {
      if ((*(int *)(iVar1 + 8) == 10) && (iVar1 = playback_processMediaChannelData(iVar1,unaff_ESI), iVar1 == 0))
      goto LAB_680d4ef5;
      iVar1 = rendering_getMemberCache((int)local_8);
    }
    uVar2 = 1;
LAB_680d4ef5:
    if (local_8 != (int *)0x0) {
      rendering_getDispatchState((int *)&local_8);
    }
  }
  return uVar2;
}



// ============================================================
// Function: playback_resolveMediaDependencies (playback_resolveMediaDependencies)
// Address: 680d4f10
// Size: 885 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall playback_resolveMediaDependencies(undefined4 param_1,int param_2)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  int iVar5;
  int *unaff_EBX;
  int *piVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  int iVar10;
  int *piVar11;
  int local_a0 [8];
  byte local_80;
  char local_7f;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  int local_50;
  byte *local_4c;
  int *local_48;
  int local_44;
  int local_40;
  int local_3c;
  int local_38 [2];
  
  local_48 = *(int **)(param_2 + 0x18);
  local_50 = 0;
  local_44 = 0;
  local_3c = 0;
  piVar11 = unaff_EBX + 0x15;
  piVar6 = local_a0;
  local_4c = (byte *)param_2;
  for (iVar5 = 0x14; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar6 = *piVar11;
    piVar11 = piVar11 + 1;
    piVar6 = piVar6 + 1;
  }
  iVar2 = rendering_getMemberData(param_2,unaff_EBX);
  iVar5 = local_50;
  if (iVar2 != 0) {
    local_40 = unaff_EBX[0x23];
    if ((local_40 != 0) && (iVar5 = Ordinal_1116(local_40), 0x200 < iVar5)) {
      local_3c = 1;
    }
    rendering_isStateValid((int)unaff_EBX);
    Ordinal_1112(local_40);
    local_44 = unaff_EBX[0x13];
    Ordinal_1112(local_44);
    iVar2 = unaff_EBX[3];
    piVar11 = (int *)0x0;
    iVar10 = 0;
    uVar9 = 0;
    uVar8 = 0;
    uVar7 = 0;
    iVar5 = local_44;
    iVar3 = rendering_getDispatchFlags(0xfb);
    pbVar4 = local_4c;
    iVar3 = rendering_blitMedia(local_4c,(int)local_48,unaff_EBX[1],iVar3,uVar7,uVar8,uVar9,iVar10,piVar11,
                         iVar5);
    iVar5 = local_50;
    if (iVar3 != 0) {
      unaff_EBX[3] = iVar2;
      uVar7 = *(undefined4 *)(*(int *)(*(int *)(pbVar4 + 0x20) + 8) + 0xc);
      if (local_3c != 0) {
        local_3c = 0;
        iVar2 = Ordinal_1404(&local_3c,local_40,1);
        iVar5 = local_50;
        if (iVar2 == 0) goto LAB_680d524e;
        Ordinal_1116(local_40);
        iVar2 = rendering_initState((int *)&stack0xffffffd0);
        iVar5 = local_50;
        if (iVar2 == 0) goto LAB_680d524e;
        Ordinal_1407(&local_3c);
        Ordinal_1113(&local_40);
      }
      if (local_7f == '\0') {
        pbVar4 = (byte *)0x287;
      }
      else if (local_7f == '\x01') {
        pbVar4 = (byte *)0x26e;
      }
      else {
        pbVar4 = (byte *)0x288;
        if (local_7f != '\x02') {
          pbVar4 = local_4c;
        }
      }
      iVar2 = props_storeObjectRef(uVar7,(int)pbVar4,local_38);
      iVar5 = local_50;
      if (iVar2 == 0) {
        rendering_initState((int *)&stack0xffffffd0);
        props_releaseAndClear(uVar7,local_38);
        iVar2 = props_storeIntValue(uVar7,local_a0[2] - local_a0[0],local_38);
        iVar5 = local_50;
        if (iVar2 == 0) {
          rendering_initState((int *)&stack0xffffffd0);
          props_releaseAndClear(uVar7,local_38);
          iVar2 = props_storeIntValue(uVar7,local_74,local_38);
          iVar5 = local_50;
          if (iVar2 == 0) {
            rendering_initState((int *)&stack0xffffffd0);
            props_releaseAndClear(uVar7,local_38);
            iVar2 = props_storeIntValue(uVar7,(uint)local_80,local_38);
            iVar5 = local_50;
            if (iVar2 == 0) {
              rendering_initState((int *)&stack0xffffffd0);
              props_releaseAndClear(uVar7,local_38);
              iVar2 = props_storeIntValue(uVar7,local_78,local_38);
              iVar5 = local_50;
              if (iVar2 == 0) {
                props_resolvePropertyId(uVar7,"antiAliasThreshold");
                rendering_initState((int *)&stack0xffffffd0);
                props_releaseAndClear(uVar7,local_38);
                iVar2 = props_storeIntValue(uVar7,local_7c,local_38);
                iVar5 = local_50;
                if (iVar2 == 0) {
                  rendering_initState((int *)&stack0xffffffd0);
                  props_releaseAndClear(uVar7,local_38);
                  iVar2 = props_storeIntValue(uVar7,0,local_38);
                  iVar5 = local_50;
                  if (iVar2 == 0) {
                    rendering_initState((int *)&stack0xffffffd0);
                    props_releaseAndClear(uVar7,local_38);
                    iVar2 = props_storeIntValue(uVar7,0,local_38);
                    iVar5 = local_50;
                    if (iVar2 == 0) {
                      rendering_initState((int *)&stack0xffffffd0);
                      props_releaseAndClear(uVar7,local_38);
                      iVar2 = props_storeIntValue(uVar7,0,local_38);
                      iVar5 = local_50;
                      if (iVar2 == 0) {
                        rendering_initState((int *)&stack0xffffffd0);
                        props_releaseAndClear(uVar7,local_38);
                        iVar5 = 1;
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_680d524e:
  Ordinal_1113(&local_44);
  piVar11 = local_48;
  if ((iVar5 == 0) && (iVar5 = lingo_getMovieRef((int)local_48), iVar5 == 0)) {
    lingo_formatDebugMsg(piVar11,-0x79);
  }
  return 0;
}



// ============================================================
// Function: playback_processMediaImport (playback_processMediaImport)
// Address: 680d5290
// Size: 108 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall playback_processMediaImport(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int unaff_ESI;
  undefined4 uVar3;
  int *local_8;
  
  uVar3 = 0;
  local_8 = (int *)0x0;
  local_8 = rendering_getDispatchByChannel(*(int *)(unaff_ESI + 0x18),*(short *)(param_1 + 4));
  if (local_8 != (int *)0x0) {
    iVar2 = rendering_getMemberCache((int)local_8);
    uVar1 = extraout_ECX;
    while (iVar2 != 0) {
      if ((*(int *)(iVar2 + 8) == 0xc) && (iVar2 = playback_resolveMediaDependencies(uVar1,unaff_ESI), iVar2 == 0))
      goto LAB_680d52e5;
      iVar2 = rendering_getMemberCache((int)local_8);
      uVar1 = extraout_ECX_00;
    }
    uVar3 = 1;
LAB_680d52e5:
    if (local_8 != (int *)0x0) {
      rendering_getDispatchState((int *)&local_8);
    }
  }
  return uVar3;
}



// ============================================================
// Function: playback_buildMediaTable (playback_buildMediaTable)
// Address: 680d5300
// Size: 71 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_buildMediaTable(int param_1)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int *unaff_ESI;
  int *unaff_EDI;
  
  iVar2 = *(int *)(unaff_EBX + 0x18);
  iVar1 = bitmap_openCastInfo(unaff_EDI);
  if (iVar1 != 0) {
    iVar1 = display_loadScoreCastMembers(unaff_EBX,unaff_EDI,param_1,unaff_ESI);
    if (iVar1 != 0) {
      iVar2 = lingo_getMovieRef(iVar2);
      if (iVar2 == 0) {
        return 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: playback_indexMediaEntries (playback_indexMediaEntries)
// Address: 680d5350
// Size: 281 bytes
// Params: int param_1, int param_2, int param_3, int param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_indexMediaEntries(int param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 *unaff_EBX;
  undefined4 local_8;
  
  piVar1 = *(int **)(param_1 + 0x18);
  local_8 = 0;
  display_validateChannelMembers(param_1,(int)unaff_EBX);
  iVar2 = lingo_getMovieRef((int)piVar1);
  if (iVar2 == 0) {
    playback_initFontMapEx();
    iVar2 = playback_applySpriteInk(piVar1,param_2,unaff_EBX[0xf],*(uint *)(param_4 + 4));
    unaff_EBX[0x13] = iVar2;
    iVar2 = lingo_getMovieRef((int)piVar1);
    if (iVar2 == 0) {
      iVar2 = playback_validateMediaHeader(param_3);
      if (iVar2 == 0) {
        lingo_formatDebugMsg(piVar1,-0x78);
        return 0;
      }
      if (0x4ff < *(uint *)(param_4 + 4)) {
        bitmap_openLinkedCastLib(unaff_EBX);
        iVar2 = lingo_getMovieRef((int)piVar1);
        if (iVar2 != 0) {
          return 0;
        }
      }
      iVar2 = playback_applyLoadedScoreData((int)unaff_EBX);
      if (((iVar2 != 0) && (iVar2 = lingo_getMovieRef((int)piVar1), iVar2 == 0)) &&
         (((*(int *)(*(int *)(param_1 + 0x20) + 0x680) != 0 ||
           ((*(byte *)(*piVar1 + 0x1c) & 0x20) != 0)) ||
          ((iVar2 = playback_processMediaImport((int)unaff_EBX), iVar2 != 0 &&
           (iVar2 = lingo_getMovieRef((int)piVar1), iVar2 == 0)))))) {
        iVar2 = media_getDataPtr(*(int **)(*(int *)(param_1 + 0x18) + 4));
        if (*(code **)(iVar2 + 0xa8) != (code *)0x0) {
          (**(code **)(iVar2 + 0xa8))
                    (*(undefined4 *)(*(int *)(*(int *)(param_1 + 0x20) + 4) + 4),
                     *(undefined2 *)(unaff_EBX + 1),param_5);
        }
        local_8 = 1;
      }
    }
  }
  return local_8;
}



// ============================================================
// Function: playback_resolveMediaPath (playback_resolveMediaPath)
// Address: 680d5470
// Size: 34 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resolveMediaPath(undefined4 *param_1)
{
  int in_EAX;
  undefined4 *puVar1;
  
  if (*(int *)(in_EAX + 4) != 0) {
    puVar1 = (undefined4 *)xtra_getScriptContext(*(int *)(in_EAX + 4));
    if (puVar1 != (undefined4 *)0x0) {
      crt_copyStreamContext(puVar1,param_1);
    }
  }
  return 0;
}



// ============================================================
// Function: playback_createMediaBuffer (playback_createMediaBuffer)
// Address: 680d54a0
// Size: 68 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_createMediaBuffer(int param_1,int param_2)
{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  uVar1 = *(uint *)(param_1 + 0x20);
  if (*(int *)(uVar1 + 0x480) != 0) {
    scoreEngine_stopSoundChannel(uVar1,param_2);
    return 0;
  }
  iVar3 = 0;
  uVar2 = scoreEngine_getLastFrameKey(uVar1);
  scoreEngine_insertScoreFrame(*(int *)(param_1 + 0x20),0x10001,(short)uVar2,iVar3);
  return 0;
}



// ============================================================
// Function: playback_loadMediaBlock (FUN_680d54f0)
// Address: 680d54f0
// Size: 283 bytes
// Params: int * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int playback_loadMediaBlock(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  scoreEngine_checkPausedChannels(param_1);
  rendering_getChannelProperty(*param_1,9,(undefined4 *)0x0);
  scoreEngine_markDirty((int)param_1,0);
  playback_resetAllState((byte *)*param_1);
  iVar1 = playback_initCastMembers((uint)(param_2 == 0),param_3);
  playback_goToFrame((void *)*param_1,(void *)*param_1,0,0,0);
  piVar3 = param_1 + 0x175;
  iVar2 = 8;
  do {
    if (*piVar3 != 0) {
      Ordinal_1653(piVar3);
    }
    piVar3 = piVar3 + 1;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  *(undefined1 *)(param_1 + 0x174) = 0;
  playback_openScoreEx(param_1 + 3);
  bitmap_getTextFieldRef((int)param_1);
  bitmap_clearAltStyleRun((int)param_1);
  playback_destroyFontMapData(param_1 + 0x143);
  media_releaseCastLib(param_1,param_1 + 0x114);
  Ordinal_36(param_1 + 0x11b);
  if (param_1[0x141] != 0) {
    param_1[0x141] = 0;
    Ordinal_1352(param_1 + 10);
  }
  Ordinal_1309(param_1 + 10,0x400,"",0);
  rendering_clearSpriteStreams((int)param_1);
  param_1[0x111] = 0;
  param_1[0x116] = 0;
  param_1[0x19b] = 0;
  param_1[0x199] = 0;
  param_1[0x117] = 0;
  param_1[0x1a3] = 1;
  *(undefined1 *)(param_1 + 0x127) = 0;
  return iVar1;
}



// ============================================================
// Function: playback_processLoadedMedia (playback_processLoadedMedia)
// Address: 680d5610
// Size: 211 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_processLoadedMedia(int *param_1)

{
  bool bVar1;
  short sVar2;
  undefined2 uVar3;
  undefined3 extraout_var;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  
  uVar6 = 0;
  playback_loadMediaBlock(param_1,1,0);
  bVar1 = bitmap_createCastEntry((int)param_1);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar4 = scoreEngine_initScoreDefaults(param_1);
    if (iVar4 != 0) {
      sVar2 = scoreEngine_createThumbnail((int)param_1,(undefined1 *)0x0);
      if (sVar2 != 0) {
        piVar5 = media_getScoreStatePtr();
        if (piVar5 != (int *)0x0) {
          iVar4 = 0;
          uVar3 = scoreEngine_getChannelFlags((int)param_1);
          iVar4 = playback_goToFrame((void *)*param_1,(void *)*param_1,(int)piVar5,uVar3,iVar4);
          if (iVar4 != 0) {
            playback_processLoadedChannels((int *)*param_1);
            uVar6 = 1;
            param_1[0x111] = 1;
            *(undefined2 *)((int)param_1 + 0x48e) = 0x79f;
            *(undefined2 *)(param_1 + 300) = 0x79f;
            iVar4 = rendering_updateChannelState((int)(param_1 + 0x123));
            param_1[0x140] = iVar4;
            stage_getSpriteApiRef(param_1[2],param_1[0x111]);
            scoreEngine_invokeCallback(param_1[1],1);
            goto LAB_680d56ce;
          }
        }
      }
    }
  }
  playback_loadMediaBlock(param_1,1,0);
LAB_680d56ce:
  rendering_getChannelProperty(*param_1,8,(undefined4 *)0x0);
  return uVar6;
}



// ============================================================
// Function: playback_initMediaLoadState (playback_initMediaLoadState)
// Address: 680d56f0
// Size: 390 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_initMediaLoadState(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 local_8;
  
  piVar1 = *(int **)(param_1 + 0x18);
  local_8 = 0;
  Ordinal_1130(param_3,0x1464);
  playback_createScoreContext((int)piVar1,(int *)(*(int *)(param_1 + 0x20) + 0xc),param_2,0,(void *)0x2);
  iVar2 = playback_initMediaChannels();
  if (iVar2 != 0) {
    iVar2 = *(int *)(param_1 + 0x20);
    playback_initScoreChannelState(piVar1,(undefined2 *)(iVar2 + 0x48c),iVar2 + 0xc,param_2,
                 (undefined4 *)(iVar2 + 0x680));
    iVar2 = lingo_getMovieRef((int)piVar1);
    if (iVar2 == 0) {
      playback_isMediaLoaded(extraout_ECX,*(int *)(param_1 + 0x20) + 0xc,param_1);
      iVar2 = lingo_getMovieRef((int)piVar1);
      if (iVar2 == 0) {
        playback_isMediaLoaded(extraout_ECX_00,*(int *)(param_1 + 0x20) + 0xc,param_1);
        iVar2 = lingo_getMovieRef((int)piVar1);
        if (iVar2 == 0) {
          *param_3 = *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x500);
          uVar3 = media_isScoreLocked(*(int **)(param_1 + 0x28));
          param_3[2] = uVar3;
          param_3[5] = (int)*(short *)(*(int *)(param_1 + 0x20) + 0x492);
          param_3[6] = (int)*(short *)(*(int *)(param_1 + 0x20) + 0x490);
          param_3[7] = (int)*(short *)(*(int *)(param_1 + 0x20) + 0x496);
          param_3[8] = (int)*(short *)(*(int *)(param_1 + 0x20) + 0x494);
          param_3[0x111] = ~(uint)(*(byte *)(*(int *)(param_1 + 0x20) + 0x49d) >> 3) & 1;
          Ordinal_38(*(int *)(*(int *)(param_1 + 0x20) + 0x46c),7,param_3 + 0x112,0x400);
          Ordinal_38(*(int *)(*(int *)(param_1 + 0x20) + 0x46c),8,param_3 + 0x212,0x400);
          param_3[9] = 0;
          local_8 = 1;
        }
      }
    }
  }
  playback_openScoreEx((int *)(*(int *)(param_1 + 0x20) + 0xc));
  return local_8;
}



// ============================================================
// Function: playback_loadMediaData (FUN_680d5880)
// Address: 680d5880
// Size: 1187 bytes
// Params: int * param_1, int * param_2, void * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_loadMediaData(int *param_1,int *param_2,void *param_3)
{
  short sVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *piVar5;
  undefined1 *puVar6;
  int local_43c;
  int local_438;
  int *local_434;
  undefined4 local_430;
  int local_42c;
  int local_428;
  int local_424;
  uint local_420;
  int *local_41c;
  int *local_418;
  int local_414;
  undefined4 *local_410;
  int *local_40c;
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  piVar5 = (int *)*param_2;
  local_420 = (uint)param_3 & 1;
  local_41c = param_1;
  local_418 = param_2;
  local_414 = 0;
  local_424 = 0;
  local_438 = 0;
  local_40c = piVar5;
  iVar2 = lingo_getMovieRef((int)piVar5);
  if (iVar2 != 0) {
    lingo_updateState((int)piVar5);
  }
  local_410 = (undefined4 *)Ordinal_1114(param_2[0xc]);
  if ((param_1 == (int *)0x0) || (local_410 == (undefined4 *)0x0)) goto LAB_680d5c87;
  if (param_2[3] != 0) goto LAB_680d5cf8;
  if ((param_2[4] == 0) && (local_420 != 0)) {
    param_2[4] = 1;
  }
  if (param_2[4] < 2) {
    iVar2 = playback_createScoreContext((int)piVar5,param_2 + 8,local_410,param_2[0xe],param_3);
    if ((iVar2 == 0xc) && (local_420 != 0)) {
      local_414 = 2;
      goto LAB_680d5cf8;
    }
    iVar2 = playback_initMediaChannels();
    piVar5 = local_40c;
    param_2 = local_418;
    param_1 = local_41c;
    if (iVar2 != 0) {
      if (1 < local_418[4]) goto LAB_680d5b7c;
      playback_initScoreChannelState(local_40c,(undefined2 *)(local_418 + 0x1a),(int)(local_418 + 8),local_410,
                   local_418 + 0x33);
      iVar2 = lingo_getMovieRef((int)piVar5);
      if (iVar2 == 0) {
        if ((param_2[0x33] == 0) || (((uint)param_3 & 0x10) == 0)) {
          iVar2 = 0;
        }
        else {
          iVar2 = 1;
        }
        iVar2 = playback_loadFontMapData(piVar5,local_410,iVar2);
        if (iVar2 == 0) {
          uVar3 = rendering_updateChannelState((int)(param_1 + 0x123));
          if ((((0x10ff < uVar3) && (uVar3 = rendering_updateChannelState((int)(param_2 + 0x1a)), uVar3 < 0x1100))
              && (local_424 = media_getDataPtr((int *)piVar5[1]), param_2[0x33] == 0)) &&
             ((((uint)param_3 & 2) == 0 && (*(int *)(local_424 + 0x180) != 0)))) {
            local_43c = 0;
            local_408 = 0;
            memset(local_407,0,0x3fe);
            Ordinal_1310(local_410,&local_408,0x3ff);
            uVar3 = rendering_updateChannelState((int)(param_2 + 0x1a));
            if (uVar3 < 0x1100) {
              puVar6 = &local_408;
              piVar5 = &local_43c;
              uVar4 = rendering_updateChannelState((int)(param_2 + 0x1a));
              (**(code **)(local_424 + 0x180))(uVar4,piVar5,puVar6);
              if (local_43c == -0x1ca) {
                param_3 = (void *)((uint)param_3 | 2);
              }
              local_438 = 1;
            }
          }
          local_430 = 0;
          local_42c = 0;
          local_428 = 0;
          local_434 = param_1 + 0x143;
          local_430 = rendering_updateChannelState((int)(param_2 + 0x1a));
          local_42c = rendering_refreshChannel((int)(param_2 + 0x1a));
          local_428 = param_1[0x120];
          if (param_1[9] == 0) {
            iVar2 = Ordinal_1150(0,1,4);
            param_1[9] = iVar2;
          }
          iVar2 = playback_buildMediaTable((int)(param_2 + 8));
          piVar5 = local_40c;
          param_1 = local_41c;
          param_2 = local_418;
          if (iVar2 != 0) {
            if (local_420 != 0) {
              local_418[4] = 2;
            }
            goto LAB_680d5b7c;
          }
        }
      }
    }
LAB_680d5c87:
    if (param_1[9] != 0) {
      Ordinal_1163(param_1 + 9);
      param_1[9] = 0;
    }
    param_2[4] = 0;
    if (local_414 == 1) {
      param_2[3] = 1;
    }
    else if (local_414 == 0) {
      local_410 = (undefined4 *)0x0;
      rendering_resetChannelSprite((int)piVar5,param_1,(int)param_2);
      rendering_getChannelFormat((int)param_2);
    }
  }
  else {
LAB_680d5b7c:
    if (2 < param_2[4]) {
LAB_680d5c5f:
      iVar2 = lingo_getMovieRef((int)piVar5);
      if (iVar2 == 0) {
        local_414 = 1;
      }
      goto LAB_680d5c87;
    }
    if ((local_420 == 0) || (iVar2 = display_checkChannelSlots(*param_1,(int)param_2), iVar2 != 0)) {
      local_434 = param_1 + 0x143;
      local_430 = 0;
      local_42c = 0;
      local_428 = 0;
      local_430 = rendering_updateChannelState((int)(param_2 + 0x1a));
      local_42c = rendering_refreshChannel((int)(param_2 + 0x1a));
      local_428 = param_1[0x120];
      iVar2 = playback_indexMediaEntries(*param_1,(int)(param_2 + 8),param_1[2],(int)&local_434,param_3);
      piVar5 = local_40c;
      if (iVar2 == 0) goto LAB_680d5c87;
      iVar2 = Ordinal_1314(local_410,&local_408,0x3ff);
      piVar5 = local_40c;
      if ((iVar2 != 0) &&
         (sVar1 = Ordinal_1208(&local_408,"shared.cst"), piVar5 = local_40c, sVar1 == 0)) {
        param_1[0x118] = (int)(short)param_2[1];
        param_1[0x11a] = (int)(short)param_2[0x1d];
      }
      goto LAB_680d5c5f;
    }
    local_414 = 2;
  }
  if (local_438 != 0) {
    if (param_2[3] != 0) {
      rendering_validateChannelMembers(*param_1,(int)param_2);
    }
    if ((local_424 != 0) && (*(code **)(local_424 + 0x184) != (code *)0x0)) {
      (**(code **)(local_424 + 0x184))();
    }
  }
LAB_680d5cf8:
  if (local_410 != (undefined4 *)0x0) {
    Ordinal_1115(param_2[0xc]);
  }
  return 0;
}



// ============================================================
// Function: playback_resolveExternalMedia (playback_resolveExternalMedia)
// Address: 680d5d30
// Size: 479 bytes
// Params: int param_1, ushort * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int playback_resolveExternalMedia(int param_1,ushort *param_2,undefined4 param_3)
{
  int *piVar1;
  int iVar2;
  ushort local_84c [4];
  uint local_844;
  undefined4 local_840;
  int *local_83c;
  undefined4 local_838;
  undefined1 local_834 [1044];
  undefined4 local_420;
  undefined1 local_41c [1044];
  uint local_8;
  
  local_840 = param_3;
  local_420 = 0;
  memset(local_41c,0,0x414);
  local_844 = (uint)*param_2;
  piVar1 = *(int **)(param_1 + 0x18);
  Ordinal_1309(&local_420,0x400,local_840,2);
  local_83c = (int *)(uint)(*(int *)(*piVar1 + 0x20) == 0);
  local_838 = 0;
  memset(local_834,0,0x414);
  local_840 = 0;
  iVar2 = media_getDataPtr(*(int **)(*(int *)(param_1 + 0x18) + 4));
  if (*(code **)(iVar2 + 8) == (code *)0x0) {
LAB_680d5e07:
    iVar2 = scoreEngine_writeChannelData(*(int *)(param_1 + 0x20),0,&local_420,0x16,1,(int)local_83c,1);
    if (iVar2 == 0) goto LAB_680d5e8d;
  }
  else {
    iVar2 = (**(code **)(iVar2 + 8))(&local_420,&local_838,&local_840,1,0);
    if (iVar2 == 0) goto LAB_680d5e07;
  }
  iVar2 = rendering_getChannelRect((int)piVar1,&local_420);
  if (iVar2 == 0) {
    local_83c = (int *)rendering_getChannelDataEx((int)piVar1,1,&local_420,*(int *)(param_1 + 0x20));
    if (local_83c != (int *)0x0) {
      *param_2 = *(ushort *)(local_83c + 1);
      iVar2 = playback_loadMediaData(*(int **)(param_1 + 0x20),local_83c,(void *)0x0);
      if (iVar2 == 1) goto LAB_680d5ea9;
      rendering_setChannelProperty(piVar1,(uint)*(ushort *)(local_83c + 1),0);
      *param_2 = (ushort)local_844;
    }
LAB_680d5e8d:
    return 0;
  }
  *param_2 = *(ushort *)(iVar2 + 4);
LAB_680d5ea9:
  lingo_getDebugState(piVar1);
  playback_getFontMapState((undefined4 *)(param_2 + 10));
  scoreEngine_resetThumbnails(*(int **)(param_1 + 0x20),(void *)0x0);
  playback_processSpriteCallback(param_1,(uint)param_2[6]);
  rendering_setChannelProperty(piVar1,local_844,0);
  local_84c[0] = param_2[6];
  rendering_getChannelProperty(param_1,0x19,(undefined4 *)local_84c);
  return 0;
}



// ============================================================
// Function: playback_finalizeMediaLoad (playback_finalizeMediaLoad)
// Address: 680d5f10
// Size: 110 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 playback_finalizeMediaLoad(void)

{
  short *psVar1;
  int iVar2;
  int unaff_ESI;
  short sVar3;
  
  if (((unaff_ESI != 0) && (iVar2 = *(int *)(unaff_ESI + 0x20), iVar2 != 0)) &&
     (*(int *)(unaff_ESI + 0x18) != 0)) {
    sVar3 = 1;
    if (0 < *(short *)(iVar2 + 0x478)) {
      do {
        psVar1 = (short *)scoreEngine_getFrameData(iVar2,sVar3);
        if (psVar1 != (short *)0x0) {
          iVar2 = rendering_getChannelSprite(*(int *)(unaff_ESI + 0x18),*psVar1);
          if ((iVar2 != 0) && (*(int *)(iVar2 + 0x14) != 0)) {
            iVar2 = rendering_validateChannelMembers(unaff_ESI,iVar2);
            if (iVar2 == 0) {
              return 0;
            }
          }
        }
        iVar2 = *(int *)(unaff_ESI + 0x20);
        sVar3 = sVar3 + 1;
      } while (sVar3 <= *(short *)(iVar2 + 0x478));
    }
    return 1;
  }
  return 0;
}



