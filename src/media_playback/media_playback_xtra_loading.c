// Module: media_playback
// Topic: Xtra plugin loading, network resource discovery, and cast library management
// Address range: 0x680B66F0 - 0x680B9220
// Functions (46):
//   media_allocCastNode
//   media_allocCastNodeLocked
//   media_loadXtraBlock
//   media_getCastMemberRef
//   media_processXtraLoadEx
//   media_processXtraLoad
//   media_readGuid
//   media_parseCastStream
//   media_initCastPair
//   media_openXtraBlock
//   media_releaseXtraResources
//   media_openXtraRiffStream
//   media_readStreamEntries
//   media_validateXtraSignature
//   media_queryXtraInfo
//   media_discoverNetworkXtra
//   media_extractPluginPath
//   media_buildXtraDownloadUrl
//   media_releasePluginRefs
//   media_searchXtraPlugin
//   media_loadXtraList
//   media_getXtraDownloadStats
//   media_validateCastStream
//   media_serializeCastLib
//   media_releaseAllPlugins
//   media_queryXtraInterfaces
//   media_destroyXtraNode
//   media_validateXtraPath
//   media_registerXtraSession
//   media_validateXtraVersion
//   media_loadXtraPlugin
//   media_loadBuiltinXtras
//   media_resolveXtraFilename
//   media_registerCoreXtras
//   media_processXtraEntries
//   media_releaseCastLib
//   media_scanXtraPaths
//   media_assignCastData
//   media_assignCastDataLocked
//   media_loadXtraOrchestrator
//   media_getScoreDataEntry
//   media_processXtraLoadEntry
//   media_getPlatformXtraFlag
//   media_findScoreDataIndex
//   media_processXtraNotify
//   media_isKnownPlatform

// ============================================================
// Function: media_allocCastNode (FUN_680b66f0)
// Address: 680b66f0
// Size: 134 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_allocCastNode(int param_1,int *param_2,int param_3)

{
  int local_18;
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  undefined4 *extraout_ECX;
  
  if (param_1 == 0) {
    return 0x80040001;
  }
  if (param_2 == (int *)0x0) {
    return 0x80040001;
  }
  puVar1 = (undefined4 *)Ordinal_1114(*(undefined4 *)(param_1 + 0x450));
  if (puVar1 != (undefined4 *)0x0) {
    piVar2 = (int *)*puVar1;
    Ordinal_1115(*(undefined4 *)(param_1 + 0x450));
    if (piVar2 != (int *)0x0) {
      piVar2 = media_cloneAssetContainer(piVar2);
      if (piVar2 == (int *)0x0) {
        return 0x80040002;
      }
      goto LAB_680b675d;
    }
  }
  piVar2 = (int *)media_allocAssetContainer(8);
  if (piVar2 == (int *)0x0) {
    return 0x80040002;
  }
LAB_680b675d:
  *param_2 = (int)piVar2;
  if (param_3 != 0) {
    uVar3 = media_findAssetRef();
    *extraout_ECX = uVar3;
  }
  return 0;
}



// ============================================================
// Function: media_allocCastNodeLocked (FUN_680b6780)
// Address: 680b6780
// Size: 143 bytes
// Params: int param_1, int param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_allocCastNodeLocked(int param_1,int param_2,int *param_3,int param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  media_allocCastNode(*(int *)(iVar2 + 0x20),param_3,param_4);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_loadXtraBlock (FUN_680b6810)
// Address: 680b6810
// Size: 78 bytes
// Params: int * param_1, int param_2, int param_3, uint param_4, int param_5, byte * param_6, int * param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
media_loadXtraBlock(int *param_1,int param_2,int param_3,uint param_4,int param_5,byte *param_6,
            int *param_7)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && (param_6 != (byte *)0x0)) {
    if (param_3 == 0) {
      uVar1 = media_findAssetEntry(param_7,param_2,param_1,param_4,param_5);
      return uVar1;
    }
    uVar1 = media_loadAssetBlock(param_1,param_6,param_2,param_4,param_5);
    return uVar1;
  }
  return 0x80040001;
}



// ============================================================
// Function: media_getCastMemberRef (FUN_680b6860)
// Address: 680b6860
// Size: 88 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getCastMemberRef(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = param_2;
  piVar1 = param_1;
  if (param_1 == (int *)0x0) {
    return 0x80040001;
  }
  if ((-1 < param_2) && (param_2 < *(int *)(*param_1 + 0x10))) {
    param_1 = *(int **)(*param_1 + 0x24 + param_2 * 4);
    if (param_1 != (int *)0x0) {
      Ordinal_36((int *)&param_1);
    }
    stage_emitPushRef(piVar1,iVar2);
    return 0;
  }
  return 0x80040c1e;
}



// ============================================================
// Function: media_processXtraLoadEx (FUN_680b68c0)
// Address: 680b68c0
// Size: 109 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_processXtraLoadEx(int *param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = param_2;
  piVar1 = param_1;
  if ((param_1 == (int *)0x0) || (param_2 == (int *)0x0)) {
    return 0x80040001;
  }
  param_1 = (int *)Ordinal_35(0x18);
  if (param_1 == (int *)0x0) {
    return 0x80040002;
  }
  iVar3 = stage_lookupSymbolId(piVar1,&param_1);
  if (iVar3 == -1) {
    Ordinal_36((int *)&param_1);
    return 0x80040002;
  }
  *piVar2 = iVar3;
  return 0;
}



// ============================================================
// Function: media_processXtraLoad (FUN_680b6930)
// Address: 680b6930
// Size: 35 bytes
// Params: int * param_1, int param_2, uint param_3, int param_4, undefined4 param_5, int * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_processXtraLoad(int *param_1,int param_2,uint param_3,int param_4,undefined4 param_5,int *param_6)
{
  media_findAssetEntry(param_6,param_2,param_1,param_3,param_4);
  return 0;
}



// ============================================================
// Function: media_readGuid (FUN_680b6960)
// Address: 680b6960
// Size: 87 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_readGuid(void)
{
  undefined1 uVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  undefined4 *unaff_EBX;
  int iVar4;
  
  Ordinal_1433();
  Ordinal_1432();
  uVar3 = Ordinal_1415();
  *unaff_EBX = uVar3;
  uVar2 = Ordinal_1413();
  *(undefined2 *)(unaff_EBX + 1) = uVar2;
  uVar2 = Ordinal_1413();
  *(undefined2 *)((int)unaff_EBX + 6) = uVar2;
  iVar4 = 0;
  do {
    uVar1 = Ordinal_1411();
    *(undefined1 *)((int)unaff_EBX + iVar4 + 8) = uVar1;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 8);
  Ordinal_1432();
  return 0;
}



// ============================================================
// Function: media_parseCastStream (FUN_680b69c0)
// Address: 680b69c0
// Size: 449 bytes
// Params: int param_1, int param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_parseCastStream(int param_1,int param_2,int *param_3,int param_4)
{
  int *piVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int *local_38;
  char local_33;
  int local_30;
  int local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  int *local_1c;
  undefined1 local_18 [16];
  uint local_8;
  
  local_28 = param_3;
  local_1c = (int *)0x0;
  if (param_2 == 0) {
    iVar4 = 0x65;
  }
  else {
    cVar2 = Ordinal_1410(param_2);
    local_33 = Ordinal_1410(param_2);
    Ordinal_1410(param_2);
    Ordinal_1410(param_2);
    iVar4 = Ordinal_1414(param_2);
    local_30 = iVar4;
    iVar3 = Ordinal_1041();
    if (iVar3 == 0) {
      if ((param_4 != 0) && (local_33 == '\0')) goto LAB_680b6a03;
      local_1c = (int *)media_allocAssetContainer((int)cVar2);
      if (local_1c != (int *)0x0) {
        local_24 = 0;
        if (0 < iVar4) {
          do {
            local_2c = Ordinal_1414(param_2);
            if (local_2c < 1) break;
            media_readGuid();
            iVar4 = Ordinal_1041();
            if (iVar4 != 0) goto LAB_680b6a4e;
            local_20 = (int *)cast_writeDataEntry(param_2,local_2c,0);
            if (local_20 == (int *)0x0) {
              iVar4 = 0x66;
              media_initAssetLoader(&local_1c,(int *)&local_1c);
              local_1c = (int *)0x0;
              goto LAB_680b69ec;
            }
            iVar4 = Ordinal_1114(local_20);
            Ordinal_1128(iVar4 + 8,local_18,0x10);
            Ordinal_1115(local_20);
            iVar4 = Ordinal_39(local_20);
            iVar3 = 0;
            if (0 < iVar4) {
              do {
                display_loadCastDataEntry((int)local_28,(int *)&local_20,iVar3,param_1 + 0x50c,1,3);
                iVar3 = iVar3 + 1;
              } while ((short)iVar3 < iVar4);
            }
            local_38 = local_20;
            iVar4 = stage_lookupSymbolId(local_1c,&local_38);
            if (iVar4 == -1) {
              return 0;
            }
            local_24 = local_24 + 1;
          } while (local_24 < local_30);
        }
        goto LAB_680b6a03;
      }
      iVar4 = -0x7a;
    }
    else {
LAB_680b6a4e:
      iVar4 = -0x74;
    }
  }
LAB_680b69ec:
  piVar1 = local_28;
  iVar3 = lingo_getMovieRef((int)local_28);
  if (iVar3 == 0) {
    lingo_formatDebugMsg(piVar1,iVar4);
  }
LAB_680b6a03:
  return 0;
}



// ============================================================
// Function: media_initCastPair (FUN_680b6b90)
// Address: 680b6b90
// Size: 23 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_initCastPair(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  return 0;
}



// ============================================================
// Function: media_openXtraBlock (FUN_680b6bb0)
// Address: 680b6bb0
// Size: 179 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall media_openXtraBlock(undefined4 param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 *unaff_ESI;
  int *unaff_EDI;
  int local_c;
  int local_8;
  
  uVar4 = 0;
  local_8 = 0;
  *unaff_ESI = 0;
  iVar1 = playback_openScore(param_2,FOURCC_XTRl,0x400,&local_c,&local_8);
  if (iVar1 == 0xc) {
    Ordinal_1407(&local_8);
    return 2;
  }
  if ((iVar1 != 7) && (local_c != 0)) {
    if (iVar1 != 0) {
      iVar3 = -0x74;
      if (iVar1 == 6) {
        iVar3 = -0x7a;
      }
      lingo_formatDebugMsg(unaff_EDI,iVar3);
      Ordinal_1407(&local_8);
      return 0;
    }
    if (local_8 == 0) goto LAB_680b6c51;
    uVar2 = media_parseCastStream(param_3,local_8,unaff_EDI,param_4);
    *unaff_ESI = uVar2;
    iVar1 = lingo_getMovieRef((int)unaff_EDI);
    if (iVar1 != 0) goto LAB_680b6c51;
  }
  uVar4 = 1;
LAB_680b6c51:
  Ordinal_1407(&local_8);
  return uVar4;
}



// ============================================================
// Function: media_releaseXtraResources (FUN_680b6c70)
// Address: 680b6c70
// Size: 133 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_releaseXtraResources(void)
{
  int *piVar1;
  int *piVar2;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 0x4c);
  piVar2 = *(int **)(unaff_ESI + 0x48);
  if (*(int *)(unaff_ESI + 0x54) != 0) {
    (**(code **)(*piVar2 + 0x14))(piVar2,*(int *)(unaff_ESI + 0x54));
    *(undefined4 *)(unaff_ESI + 0x54) = 0;
  }
  if (*(int *)(unaff_ESI + 0x58) != 0) {
    (**(code **)(*piVar2 + 0x14))(piVar2,*(int *)(unaff_ESI + 0x58));
    *(undefined4 *)(unaff_ESI + 0x58) = 0;
  }
  Ordinal_1113(unaff_ESI + 0x5c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  *(undefined4 *)(unaff_ESI + 0x2c) = 0;
  *(undefined4 *)(unaff_ESI + 0x30) = 0;
  *(undefined4 *)(unaff_ESI + 0x34) = 0;
  *(undefined4 *)(unaff_ESI + 0x38) = 0;
  *(undefined4 *)(unaff_ESI + 0x3c) = 0;
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  *(undefined4 *)(unaff_ESI + 0x4c) = 0;
  *(undefined4 *)(unaff_ESI + 0x50) = 0;
  return 0;
}




// ============================================================
// Function: media_openXtraRiffStream (FUN_680b6d00)
// Address: 680b6d00
// Size: 837 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_openXtraRiffStream(int param_1)
{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  void *this;
  int local_4c;
  undefined4 local_48;
  int local_44;
  int local_40;
  uint *local_3c;
  int local_38;
  uint local_34;
  int local_30;
  int local_2c [3];
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  uint local_8;
  
  puVar1 = (uint *)(param_1 + 0x2c);
  *puVar1 = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x34) = 0;
  *(undefined4 *)(param_1 + 0x38) = 0;
  *(undefined4 *)(param_1 + 0x3c) = 0;
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x44) = 0;
  *(undefined4 *)(param_1 + 0x48) = 0;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  local_38 = 0;
  local_3c = (uint *)0x0;
  *(undefined4 *)(param_1 + 0x50) = 0;
  local_38 = Ordinal_1126(0x408,0);
  local_3c = (uint *)Ordinal_1126(0x408,0);
  if ((local_38 != 0) && (local_3c != (uint *)0x0)) {
    local_30 = Ordinal_1038();
    piVar2 = (int *)Ordinal_2075(local_30);
    if (piVar2 != (int *)0x0) {
      (**(code **)*piVar2)(piVar2,&DAT_68175b98,param_1 + 0x48);
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    Ordinal_2063(local_30,&DAT_68175dd8,&DAT_68175e08,(int *)(param_1 + 0x4c));
    if ((*(int *)(param_1 + 0x48) != 0) && (*(int *)(param_1 + 0x4c) != 0)) {
      *(undefined4 *)(param_1 + 0x40) = *(undefined4 *)(param_1 + 0x18);
      iVar3 = display_openRiffStream(this,puVar1);
      if ((iVar3 == 0) &&
         ((uVar4 = display_readInfoBlock((int)puVar1,&local_20,(int *)(param_1 + 0x54)), uVar4 == 0 &&
          (uVar4 = display_readFileListBlock((int)puVar1,&local_4c,(int *)(param_1 + 0x58)), uVar4 == 0)))) {
        *(undefined4 *)(param_1 + 0x20) = local_14;
        *(undefined4 *)(param_1 + 0x1c) = local_18;
        *(undefined4 *)(param_1 + 0x24) = local_48;
        *(int *)(param_1 + 0x28) = local_1c;
        if (2 < local_1c) {
          uVar4 = display_readSignBlock((int)puVar1,&local_30);
          local_44 = *(int *)(param_1 + 0x30) + 8;
          local_40 = *(int *)(param_1 + 0x38) + local_44;
          if (uVar4 == 0) {
            local_34 = (**(code **)(**(int **)(param_1 + 0x48) + 0x20))
                                 (*(int **)(param_1 + 0x48),local_30);
            uVar5 = (**(code **)(**(int **)(param_1 + 0x48) + 0x18))
                              (*(int **)(param_1 + 0x48),local_30);
            *(undefined4 *)(local_38 + 0x400) = uVar5;
            if (*(int *)(local_38 + 0x400) < 0x400) {
              Ordinal_1128(local_38,local_34,*(int *)(local_38 + 0x400));
              *(undefined4 *)(local_38 + 0x404) = 1;
              iVar3 = 0;
            }
            else {
              iVar3 = 0x125;
            }
            (**(code **)(**(int **)(param_1 + 0x48) + 0x14))(*(int **)(param_1 + 0x48),local_30);
            if ((iVar3 == 0) &&
               (local_30 = iVar3, uVar4 = display_readCertBlock((int)puVar1,local_2c,&local_30), uVar4 == 0))
            {
              uVar5 = (**(code **)(**(int **)(param_1 + 0x48) + 0x18))
                                (*(int **)(param_1 + 0x48),local_30);
              local_34 = Ordinal_1111(uVar5,0);
              if (local_34 == 0) {
                iVar3 = -0x7ffbfffe;
              }
              else {
                uVar5 = (**(code **)(**(int **)(param_1 + 0x48) + 0x20))
                                  (*(int **)(param_1 + 0x48),local_30,uVar5);
                uVar5 = Ordinal_1114(local_34,uVar5);
                Ordinal_1128(uVar5);
                Ordinal_1115(local_34);
                iVar3 = display_createStreamConnection(local_34,(int *)(param_1 + 0x5c));
                if ((iVar3 != 0) && (iVar3 != 0x146)) {
                  iVar3 = 0x144;
                }
                Ordinal_1113(&local_34);
              }
              (**(code **)(**(int **)(param_1 + 0x48) + 0x14))(*(int **)(param_1 + 0x48),local_30);
              if (((iVar3 == 0) &&
                  (iVar3 = display_readStreamRange(*(int *)(param_1 + 0x5c),8,local_3c), iVar3 == 0)) &&
                 (iVar3 = (**(code **)(**(int **)(param_1 + 0x18) + 0x20))
                                    (*(int **)(param_1 + 0x18),&local_34), iVar3 == 0)) {
                local_30 = iVar3;
                iVar3 = Ordinal_1405(&local_30,*(undefined4 *)(param_1 + 0x18),1,0);
                if ((iVar3 == 0) || (iVar3 = Ordinal_1432(local_30,0,0), iVar3 == 0)) {
                  Ordinal_1042();
                }
                else {
                  display_writeEncryptedStream(local_30,&local_44,local_38,(int)local_3c);
                }
                Ordinal_1407(&local_30);
                (**(code **)(**(int **)(param_1 + 0x18) + 0x24))(*(int **)(param_1 + 0x18),local_34)
                ;
              }
            }
          }
        }
      }
    }
  }
  Ordinal_1127(&local_3c);
  Ordinal_1127(&local_38);
  return 0;
}



// ============================================================
// Function: media_readStreamEntries (FUN_680b7050)
// Address: 680b7050
// Size: 242 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_readStreamEntries(int *param_1,int param_2,int param_3)
{
  int iVar1;
  int unaff_EBX;
  int iVar2;
  int local_418;
  int local_414;
  uint local_410 [256];
  int local_10;
  uint local_8;
  
  local_418 = 0;
  local_414 = 0;
  iVar2 = 1;
  do {
    iVar1 = display_readStreamRange(param_3,iVar2,local_410);
    if ((local_414 == 0) && (local_418 = local_418 + 1 + local_10, iVar1 = local_414, param_2 != 0))
    {
      Ordinal_1202(param_2,local_410);
      switch(iVar2) {
      case 1:
        *(int *)(unaff_EBX + 4) = param_2;
        break;
      case 2:
        *(int *)(unaff_EBX + 0xc) = param_2;
        break;
      case 3:
        *(int *)(unaff_EBX + 0x10) = param_2;
        break;
      case 4:
        *(int *)(unaff_EBX + 0x14) = param_2;
        break;
      case 5:
        *(int *)(unaff_EBX + 0x18) = param_2;
        break;
      case 6:
        *(int *)(unaff_EBX + 0x1c) = param_2;
      }
      param_2 = param_2 + 1 + local_10;
    }
    local_414 = iVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  if (param_1 != (int *)0x0) {
    *param_1 = local_418;
  }
  return 0;
}



// ============================================================
// Function: media_validateXtraSignature (FUN_680b7160)
// Address: 680b7160
// Size: 589 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_validateXtraSignature(void)

{
  char *pcVar1;
  short sVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  undefined1 **ppuVar5;
  int iVar6;
  undefined1 *local_48 [9];
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  char *local_10;
  int local_c;
  undefined1 local_5;
  
  local_48[1] = (undefined1 *)0x0;
  local_48[2] = (undefined1 *)0x0;
  local_48[3] = (undefined1 *)0x0;
  local_48[4] = (undefined1 *)0x0;
  local_48[5] = (undefined1 *)0x0;
  local_48[6] = (undefined1 *)0x0;
  local_48[7] = (undefined1 *)0x0;
  local_48[8] = (undefined1 *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_48[0] = (undefined1 *)0x0;
  local_14 = 0;
  local_5 = 0;
  iVar6 = 0;
  local_18 = 0;
  local_1c = media_getDataPtr(*(int **)(*(int *)(in_EAX + 4) + 4));
  if ((*(int *)(local_1c + 0x18) == 0) || (DAT_681963d0 != 0)) goto LAB_680b7273;
  iVar3 = media_openXtraRiffStream(in_EAX);
  local_18 = 1;
  if (iVar3 == -1) goto LAB_680b7273;
  if (iVar3 != 0) goto LAB_680b71e1;
  local_48[0] = (undefined1 *)
                (**(code **)(**(int **)(in_EAX + 0x48) + 0x20))
                          (*(int **)(in_EAX + 0x48),*(undefined4 *)(in_EAX + 0x54));
  if (local_48[0] == (undefined1 *)0x0) {
    local_24 = 0x132;
LAB_680b71e8:
    local_48[0] = &local_5;
  }
  else {
    ppuVar5 = local_48;
    local_c = 7;
    do {
      iVar6 = Ordinal_1201(*ppuVar5);
      if ((iVar6 < 0x100) &&
         (iVar3 = (**(code **)(**(int **)(in_EAX + 0x48) + 0x18))
                            (*(int **)(in_EAX + 0x48),*(undefined4 *)(in_EAX + 0x54)), iVar6 < iVar3
         )) {
        ppuVar5[1] = *ppuVar5 + iVar6 + 1;
      }
      ppuVar5 = ppuVar5 + 1;
      local_c = local_c + -1;
    } while ((char *)local_c != (char *)0x0);
    media_readStreamEntries(&local_c,0,*(int *)(in_EAX + 0x5c));
    if ((char *)local_c == (char *)0x0) {
LAB_680b736e:
      local_10 = "Macromedia, Inc.";
      local_c = 0x6817ca3c;
      iVar6 = 1;
      do {
        pcVar1 = (&local_10)[iVar6];
        uVar4 = Ordinal_1201(pcVar1);
        sVar2 = Ordinal_1207(pcVar1,local_48[1],uVar4);
        if (sVar2 == 0) {
          iVar6 = 1;
          goto LAB_680b7273;
        }
        iVar6 = iVar6 + -1;
        iVar3 = local_24;
      } while (-1 < iVar6);
    }
    else {
      local_14 = Ordinal_1111(local_c,0);
      if (local_14 == 0) {
        local_24 = -0x7a;
        iVar3 = local_24;
      }
      else {
        iVar6 = Ordinal_1114(local_14);
        iVar6 = media_readStreamEntries(&local_c,iVar6,*(int *)(in_EAX + 0x5c));
        if (iVar6 == 0) goto LAB_680b736e;
        local_20 = 0x142;
        iVar3 = local_24;
      }
    }
LAB_680b71e1:
    local_24 = iVar3;
    if (local_48[0] == (undefined1 *)0x0) goto LAB_680b71e8;
  }
  if (local_48[1] == (undefined1 *)0x0) {
    local_48[1] = &local_5;
  }
  if (local_48[2] == (undefined1 *)0x0) {
    local_48[2] = &local_5;
  }
  if (local_48[3] == (undefined1 *)0x0) {
    local_48[3] = &local_5;
  }
  if (local_48[4] == (undefined1 *)0x0) {
    local_48[4] = &local_5;
  }
  if (local_48[5] == (undefined1 *)0x0) {
    local_48[5] = &local_5;
  }
  if (local_48[6] == (undefined1 *)0x0) {
    local_48[6] = &local_5;
  }
  if (local_48[7] == (undefined1 *)0x0) {
    local_48[7] = &local_5;
  }
  if (local_48[8] == (undefined1 *)0x0) {
    local_48[8] = &local_5;
  }
  DAT_681963d0 = 1;
  iVar6 = (**(code **)(local_1c + 0x18))
                    (*(undefined4 *)(**(int **)(*(int *)(*(int *)(in_EAX + 8) + 4) + 8) + 0x24),
                     local_48);
  DAT_681963d0 = 0;
LAB_680b7273:
  Ordinal_1113(&local_14);
  if ((local_48[0] != (undefined1 *)0x0) && (local_48[0] != &local_5)) {
    (**(code **)(**(int **)(in_EAX + 0x48) + 0x24))
              (*(int **)(in_EAX + 0x48),*(undefined4 *)(in_EAX + 0x54));
  }
  if ((local_18 != 0) && (iVar6 == 0)) {
    media_releaseXtraResources();
  }
  return iVar6;
}



// ============================================================
// Function: media_queryXtraInfo (FUN_680b73b0)
// Address: 680b73b0
// Size: 256 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall media_queryXtraInfo(void *this,int param_1)
{
  int iVar1;
  int *piVar2;
  undefined *puVar3;
  int *piVar4;
  int unaff_EDI;
  uint local_6c;
  uint local_68;
  int *local_64;
  undefined1 local_60 [88];
  uint local_8;
  
  piVar4 = *(int **)(unaff_EDI + 8);
  *(undefined4 *)this = 0;
  local_64 = (int *)0x0;
  iVar1 = (**(code **)(*piVar4 + 0x28))(piVar4,&local_6c);
  if (iVar1 == 0) {
    *(uint *)(unaff_EDI + 0xc) = local_6c;
    iVar1 = (**(code **)(*piVar4 + 0x3c))(piVar4,&local_68);
    if (iVar1 == 0) {
      if (local_68 < local_6c) {
        *(uint *)(unaff_EDI + 0x10) = local_68;
        piVar4 = local_64;
      }
      else {
        local_68 = local_6c;
        *(uint *)(unaff_EDI + 0x10) = local_6c;
        piVar4 = (int *)0x1;
      }
      goto LAB_680b7434;
    }
  }
  piVar4 = local_64;
  if (iVar1 != -0x7ffbed20) {
    local_64 = (int *)0x1;
    *(int *)this = iVar1;
    piVar4 = local_64;
  }
LAB_680b7434:
  iVar1 = Ordinal_1517(DAT_681956e0,0xfa4,local_60,0x58);
  if ((iVar1 != 0) && (piVar2 = (int *)lingo_getGlobalState(param_1), piVar2 != (int *)0x0)) {
    (**(code **)*piVar2)(piVar2,&DAT_681765a8,&local_64);
    (**(code **)(*piVar2 + 8))(piVar2);
    if (local_64 != (int *)0x0) {
      puVar3 = "";
      if (piVar4 == (int *)0x0) {
        puVar3 = local_60;
      }
      (**(code **)(*local_64 + 0x18))(local_64,puVar3);
      (**(code **)(*local_64 + 8))(local_64);
    }
  }
  return 0;
}




// ============================================================
// Function: media_discoverNetworkXtra (FUN_680b74b0)
// Address: 680b74b0
// Size: 777 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_discoverNetworkXtra(void)
{
  char *pcVar1;
  char cVar2;
  int *piVar3;
  bool bVar4;
  bool bVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined3 extraout_var;
  char *pcVar10;
  int iVar11;
  undefined4 uVar12;
  uint uVar13;
  int unaff_ESI;
  int local_40;
  int local_3c;
  int *local_30;
  int *local_28;
  int local_24 [7];
  uint local_8;
  
  piVar3 = *(int **)(unaff_ESI + 0x48);
  pcVar6 = (char *)(**(code **)(*piVar3 + 0x20))(piVar3,*(undefined4 *)(unaff_ESI + 0x54));
  if (pcVar6 != (char *)0x0) {
    iVar7 = Ordinal_1201(pcVar6);
    iVar8 = (**(code **)(*piVar3 + 0x20))(piVar3,*(undefined4 *)(unaff_ESI + 0x58));
    if (iVar8 != 0) {
      iVar9 = media_getResourceRef(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 8) + 4) + 4) + 8
                                            ) + 0xc),unaff_ESI + 0x60,pcVar6 + iVar7 + 1,pcVar6,0);
      if (((iVar9 != 0) && (iVar9 = media_resolvePathType(unaff_ESI + 0x60), iVar9 != 0)) &&
         (local_40 = 0, 0 < *(int *)(unaff_ESI + 0x24))) {
        do {
          bVar4 = false;
          local_28 = (int *)0x0;
          local_3c = unaff_ESI + 0x60;
          local_30 = (int *)0x1;
          bVar5 = media_findResourcePath(iVar8,unaff_ESI + 0x890);
          if (CONCAT31(extraout_var,bVar5) == 0) {
LAB_680b7639:
            iVar9 = unaff_ESI + 0xca8;
            iVar11 = Ordinal_1326(iVar9,0x400,local_3c);
            if ((iVar11 == 0) || (iVar11 = Ordinal_1317(iVar9,iVar8), iVar11 == 0)) break;
            iVar9 = Ordinal_1310(iVar9,unaff_ESI + 0x10c0,0x400);
            if (iVar9 == 0) break;
            uVar12 = Ordinal_1038(&DAT_681761a8,&DAT_68176198,&local_28);
            Ordinal_2063(uVar12);
            if (local_28 == (int *)0x0) break;
            uVar13 = (**(code **)(*local_28 + 0xc))(local_28,unaff_ESI + 0x10c0);
            if ((uVar13 == 0) && (uVar13 = (**(code **)(*local_28 + 0x48))(local_28), uVar13 == 0))
            goto LAB_680b76e8;
            iVar9 = (**(code **)(*local_28 + 0x40))(local_28);
            if (iVar9 == 0) {
              (**(code **)(*local_28 + 8))(local_28);
              break;
            }
            bVar4 = true;
            local_30 = (int *)0x0;
            if (uVar13 == 0) goto LAB_680b76e8;
          }
          else {
            iVar9 = Ordinal_1201(iVar8);
            pcVar1 = (char *)(iVar9 + 1 + iVar8);
            pcVar10 = pcVar1;
            do {
              cVar2 = *pcVar10;
              pcVar10 = pcVar10 + 1;
            } while (cVar2 != '\0');
            local_30 = (int *)(uint)(pcVar10 != pcVar1 + 1);
            crt_getFileVersion(unaff_ESI + 0x890,(LPCSTR)(unaff_ESI + 0x1cc0),0x400);
            bVar5 = media_compareScoreVersion(pcVar1,(LPCSTR)(unaff_ESI + 0x1cc0));
            if (bVar5) {
              local_30 = (int *)0x0;
            }
            else if (local_30 != (int *)0x0) {
              local_3c = unaff_ESI + 0x478;
              iVar9 = media_getResourceRef(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(unaff_ESI + 8) + 4)
                                                             + 4) + 8) + 0xc),local_3c,
                                   pcVar6 + iVar7 + 1,pcVar6,1);
              if ((iVar9 != 0) && (iVar9 = media_resolvePathType(local_3c), iVar9 != 0)) goto LAB_680b7639;
              break;
            }
            iVar9 = Ordinal_1326(unaff_ESI + 0xca8,0x400,local_3c);
            if (iVar9 != 0) {
              bVar4 = true;
            }
LAB_680b76e8:
            uVar13 = display_readFileBlock(unaff_ESI + 0x2c,local_24,local_28,local_30);
          }
          if (local_28 != (int *)0x0) {
            if (uVar13 != 0) {
              (**(code **)(*local_28 + 0x50))(local_28);
            }
            (**(code **)(*local_28 + 8))(local_28);
            local_28 = (int *)0x0;
          }
          if (uVar13 != 0) break;
          if ((local_30 != (int *)0x0) || (bVar4)) {
            iVar9 = lingo_resolveRefEx(*(int **)(unaff_ESI + 4),unaff_ESI + 0xca8,1);
            if (iVar9 != 0) break;
            *(undefined4 *)(unaff_ESI + 0x20c8) = 1;
          }
          iVar9 = Ordinal_1201(iVar8);
          iVar9 = iVar8 + 1 + iVar9;
          iVar8 = Ordinal_1201(iVar9);
          iVar8 = iVar9 + 1 + iVar8;
          local_40 = local_40 + 1;
        } while (local_40 < *(int *)(unaff_ESI + 0x24));
      }
      if (iVar8 != 0) {
        (**(code **)(*piVar3 + 0x24))(piVar3,*(undefined4 *)(unaff_ESI + 0x58));
      }
    }
    (**(code **)(*piVar3 + 0x24))(piVar3,*(undefined4 *)(unaff_ESI + 0x54));
  }
  return 0;
}



// ============================================================
// Function: media_extractPluginPath (FUN_680b77c0)
// Address: 680b77c0
// Size: 115 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_extractPluginPath(void)

{
  short sVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  undefined4 unaff_EBX;
  
  iVar2 = Ordinal_1201();
  while( true ) {
    if (iVar2 < 1) {
      return 0;
    }
    if (*(char *)(iVar2 + in_EAX) == '/') break;
    iVar2 = iVar2 + -1;
  }
  iVar3 = Ordinal_1201(iVar2 + in_EAX);
  if (iVar3 < 0x40) {
    Ordinal_1202();
    iVar3 = 0;
    do {
      sVar1 = Ordinal_1206((&PTR_DAT_6818e4cc)[iVar3],iVar2 + in_EAX);
      if (sVar1 == 0) {
        Ordinal_1202();
        return unaff_EBX;
      }
      iVar3 = iVar3 + 2;
    } while (iVar3 < 9);
    return unaff_EBX;
  }
  return 0;
}



// ============================================================
// Function: media_buildXtraDownloadUrl (FUN_680b7840)
// Address: 680b7840
// Size: 129 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_buildXtraDownloadUrl(void)
{
  short sVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  Ordinal_1201(PTR_s_https___download_macromedia_com__6818e4c4);
  sVar1 = Ordinal_1209();
  if ((sVar1 == 0) && (iVar3 = media_extractPluginPath(), iVar3 != 0)) {
    iVar4 = Ordinal_1201(PTR_s_https___download_macromedia_com__6818e4c8);
    iVar3 = Ordinal_1201(iVar3);
    if (iVar4 + iVar3 < 0x191) {
      Ordinal_1202();
      Ordinal_1204();
    }
  }
  return 0;
}



// ============================================================
// Function: media_releasePluginRefs (FUN_680b78d0)
// Address: 680b78d0
// Size: 56 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_releasePluginRefs(void)
{
  int *piVar1;
  int unaff_ESI;
  
  piVar1 = *(int **)(unaff_ESI + 8);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 0x10))(piVar1);
    (**(code **)(**(int **)(unaff_ESI + 8) + 8))(*(int **)(unaff_ESI + 8));
    *(undefined4 *)(unaff_ESI + 8) = 0;
  }
  piVar1 = *(int **)(unaff_ESI + 4);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(unaff_ESI + 4) = 0;
  }
  return 0;
}



// ============================================================
// Function: media_searchXtraPlugin (FUN_680b7910)
// Address: 680b7910
// Size: 545 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_searchXtraPlugin(int *param_1)

{
  char *pcVar1;
  char cVar2;
  bool bVar3;
  int iVar4;
  int iVar5;
  undefined3 extraout_var;
  char *pcVar6;
  undefined *puVar7;
  undefined4 uVar8;
  int *piVar9;
  undefined4 *unaff_EDI;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 local_34;
  int *local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_1c;
  int *local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  piVar9 = (int *)*unaff_EDI;
  iVar5 = unaff_EDI[3];
  local_14 = 0;
  local_18 = piVar9;
  do {
    local_c = iVar5;
    if (iVar5 < 1) {
      local_14 = (unaff_EDI[0x830] != 0) + 1;
      if (local_14 == 0) {
LAB_680b7b0b:
        lingo_formatDebugMsg(param_1,-0x7a);
      }
      return local_14;
    }
    iVar4 = media_lookupScoreDataIndex((int)piVar9,iVar5);
    unaff_EDI[4] = iVar4;
    if (-1 < iVar4) {
      crt_getPlatformId();
      local_1c = media_getScoreChannelData(piVar9,unaff_EDI[4]);
      if ((0 < local_1c) && (local_8 = 1, 0 < local_1c)) {
        do {
          uVar11 = 0x400;
          iVar4 = 1;
          puVar10 = unaff_EDI + 0x430;
          iVar5 = crt_getPlatformId();
          iVar5 = media_loadScoreChannelXtra(piVar9,unaff_EDI[4],local_8,iVar5,iVar4,(int)puVar10,uVar11);
          if (iVar5 == 0) {
            bVar3 = media_findResourcePath(unaff_EDI + 0x430,unaff_EDI + 0x224);
            if (CONCAT31(extraout_var,bVar3) == 0) {
LAB_680b7a15:
              puVar10 = unaff_EDI + 0x530;
              iVar5 = media_loadScoreXtraData(piVar9,unaff_EDI[4],1,(int)puVar10,0x400);
              if (iVar5 == 0) {
                media_buildXtraDownloadUrl();
                iVar5 = Ordinal_1201(puVar10);
                if (iVar5 != 0) {
                  puVar7 = crt_getConstantDataRef();
                  Ordinal_1204(puVar10,puVar7);
                  if (unaff_EDI[0x830] == 0) {
                    iVar5 = Ordinal_1150(unaff_EDI[3],1,0x14);
                    unaff_EDI[0x830] = iVar5;
                    if (iVar5 == 0) goto LAB_680b7b0b;
                  }
                  uVar8 = Ordinal_1038(&DAT_681761b8,&DAT_68176198,&local_10);
                  iVar5 = Ordinal_2063(uVar8);
                  if (iVar5 == 0) {
                    iVar5 = (**(code **)(*local_10 + 0xc))(local_10,unaff_EDI + 0x530);
                    if (iVar5 == 0) {
                      local_34 = unaff_EDI[4];
                      local_30 = local_10;
                      local_2c = 0;
                      local_28 = 0x38400;
                      local_24 = 0;
                      iVar4 = Ordinal_1152(unaff_EDI[0x830],&local_34);
                      iVar5 = local_c;
                      if (iVar4 != 0) break;
                    }
                    (**(code **)(*local_10 + 8))(local_10);
                    goto LAB_680b7b0b;
                  }
                }
              }
            }
            else {
              uVar11 = 0x400;
              pcVar1 = (char *)(unaff_EDI + 0x630);
              iVar4 = 2;
              pcVar6 = pcVar1;
              iVar5 = crt_getPlatformId();
              iVar5 = media_loadScoreChannelXtra(piVar9,unaff_EDI[4],local_8,iVar5,iVar4,(int)pcVar6,uVar11);
              if (iVar5 == 0) {
                pcVar6 = pcVar1;
                do {
                  cVar2 = *pcVar6;
                  pcVar6 = pcVar6 + 1;
                } while (cVar2 != '\0');
                if (pcVar6 != (char *)((int)unaff_EDI + 0x18c1)) {
                  crt_getFileVersion(unaff_EDI + 0x224,(LPCSTR)(unaff_EDI + 0x730),0x400);
                  bVar3 = media_compareScoreVersion(pcVar1,(char *)(unaff_EDI + 0x730));
                  piVar9 = local_18;
                  if (!bVar3) goto LAB_680b7a15;
                }
              }
            }
          }
          local_8 = local_8 + 1;
          iVar5 = local_c;
        } while (local_8 <= local_1c);
      }
    }
    iVar5 = iVar5 + -1;
  } while( true );
}



// ============================================================
// Function: media_loadXtraList (FUN_680b7b40)
// Address: 680b7b40
// Size: 286 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_loadXtraList(int param_1)

{
  undefined4 *puVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined4 uVar7;
  int unaff_EBX;
  int local_8;
  
  bVar2 = false;
  iVar3 = Ordinal_1157(*(undefined4 *)(unaff_EBX + 0x20c0));
  if (iVar3 == 0) {
    return 1;
  }
  iVar4 = Ordinal_1154(*(undefined4 *)(unaff_EBX + 0x20c0));
  do {
    while( true ) {
      do {
        iVar4 = iVar4 + -1;
        if (iVar4 < 0) {
          Ordinal_1158(*(undefined4 *)(unaff_EBX + 0x20c0),iVar3);
          uVar7 = 2;
          if (!bVar2) {
            uVar7 = 1;
          }
          return uVar7;
        }
        puVar5 = (undefined4 *)Ordinal_1156(*(undefined4 *)(unaff_EBX + 0x20c0),iVar3,iVar4);
      } while ((puVar5 == (undefined4 *)0x0) || (puVar5[1] == 0));
      puVar1 = puVar5 + 2;
      if ((puVar5[2] != 0) ||
         ((local_8 = (**(code **)(*(int *)puVar5[1] + 0x18))((int *)puVar5[1],0,puVar1),
          local_8 == 0 &&
          (local_8 = (**(code **)(*(int *)*puVar1 + 0xc))((int *)*puVar1,0,0), local_8 == 0))))
      break;
LAB_680b7c22:
      media_releasePluginRefs();
    }
    iVar6 = media_queryXtraInfo(&local_8,param_1);
    if (iVar6 != 0) {
      if (local_8 == 0) {
        *(undefined4 *)(unaff_EBX + 0x18) = *puVar1;
        *(undefined4 *)(unaff_EBX + 0x14) = puVar5[1];
        *(undefined4 *)(unaff_EBX + 0x10) = *puVar5;
        iVar6 = media_validateXtraSignature();
        if (iVar6 != 0) {
          local_8 = media_discoverNetworkXtra();
          media_releaseXtraResources();
        }
      }
      goto LAB_680b7c22;
    }
    bVar2 = true;
  } while( true );
}




// ============================================================
// Function: media_getXtraDownloadStats (FUN_680b7c60)
// Address: 680b7c60
// Size: 223 bytes
// Params: undefined4 * param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getXtraDownloadStats(undefined4 *param_1,int *param_2,int *param_3)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_c;
  int local_8;
  
  iVar5 = 0;
  local_8 = 0;
  local_c = 0;
  if (param_1[1] == 4) {
    *param_2 = 0;
    *param_3 = 0;
    return 0;
  }
  iVar2 = Ordinal_1116(*param_1);
  if (iVar2 != 0x20cc) {
    *param_2 = 0;
    *param_3 = 0;
    return 0;
  }
  iVar2 = Ordinal_1114(*param_1);
  if (iVar2 == 0) {
    *param_2 = 0;
    *param_3 = 0;
    return 0;
  }
  uVar1 = *(undefined4 *)(iVar2 + 0x20c0);
  iVar2 = Ordinal_1157(uVar1);
  if (iVar2 != 0) {
    iVar3 = Ordinal_1154(uVar1);
    iVar5 = local_8;
    while (iVar3 = iVar3 + -1, -1 < iVar3) {
      iVar4 = Ordinal_1156(uVar1,iVar2,iVar3);
      if (iVar4 != 0) {
        iVar5 = iVar5 + *(int *)(iVar4 + 0xc);
        local_c = local_c + *(int *)(iVar4 + 0x10);
      }
    }
    Ordinal_1158(uVar1,iVar2);
  }
  Ordinal_1115(*param_1);
  *param_2 = iVar5;
  *param_3 = local_c;
  return 0;
}



// ============================================================
// Function: media_validateCastStream (FUN_680b7d40)
// Address: 680b7d40
// Size: 157 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_validateCastStream(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 local_8;
  
  iVar2 = 0;
  local_8 = 0;
  Ordinal_1433();
  iVar1 = Ordinal_1114(param_2);
  if (iVar1 != 0) {
    Ordinal_1432();
    iVar1 = Ordinal_1426();
    if (iVar1 != 0) {
      iVar1 = Ordinal_1424();
      if (iVar1 != 0) {
        iVar1 = Ordinal_1424();
        if (iVar1 != 0) {
          do {
            iVar1 = Ordinal_1422();
            if (iVar1 == 0) goto LAB_680b7dbd;
            iVar2 = iVar2 + 1;
          } while (iVar2 < 8);
          local_8 = 1;
        }
      }
    }
LAB_680b7dbd:
    Ordinal_1115(param_2);
  }
  Ordinal_1432();
  return local_8;
}



// ============================================================
// Function: media_serializeCastLib (FUN_680b7de0)
// Address: 680b7de0
// Size: 446 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_serializeCastLib(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  local_18 = 0;
  local_8 = 0;
  local_c = 0;
  puVar2 = (undefined4 *)Ordinal_1114(*(undefined4 *)(param_1 + 0x450));
  if (puVar2 == (undefined4 *)0x0) {
    local_18 = 1;
    goto LAB_680b7f84;
  }
  piVar1 = (int *)*puVar2;
  Ordinal_1115(*(undefined4 *)(param_1 + 0x450));
  iVar3 = media_findAssetRef();
  if (param_2 != 0) {
    iVar4 = Ordinal_1421(param_2,8);
    if (iVar4 == 0) goto LAB_680b7f84;
    iVar4 = media_countScoreDataEntries(piVar1);
    iVar4 = Ordinal_1421(param_2,iVar4);
    if ((((iVar4 == 0) || (iVar4 = Ordinal_1421(param_2,0), iVar4 == 0)) ||
        (iVar4 = Ordinal_1421(param_2,0), iVar4 == 0)) ||
       (iVar4 = Ordinal_1425(param_2,iVar3), iVar4 == 0)) goto LAB_680b7f84;
  }
  local_c = 8;
  local_1c = 0;
  if (0 < iVar3) {
    local_14 = 0x24;
    do {
      local_10 = *(int **)(local_14 + *piVar1);
      iVar4 = Ordinal_39(local_10);
      iVar6 = 0;
      local_8 = 0;
      if (0 < iVar4) {
        do {
          display_loadCastDataEntry(*(int *)(*(int *)(param_1 + 4) + 8),(int *)&local_10,iVar6,param_1 + 0x50c,0,
                       3);
          iVar6 = iVar6 + 1;
        } while ((short)iVar6 < iVar4);
      }
      iVar4 = Ordinal_1403(&local_8,0x200);
      if (iVar4 != 0) {
        iVar4 = cast_readDataEntry((int)local_10,local_8,0);
        if ((iVar4 == 0) || ((param_2 != 0 && (iVar6 = Ordinal_1425(param_2,iVar4), iVar6 == 0))))
        goto LAB_680b7f84;
        local_c = local_c + 4;
        media_validateCastStream(0,local_10);
        if (param_2 != 0) {
          uVar5 = Ordinal_1433(param_2,local_8,0,iVar4);
          Ordinal_1431(param_2,uVar5);
        }
        local_c = local_c + iVar4;
        Ordinal_1407(&local_8);
      }
      local_14 = local_14 + 4;
      local_1c = local_1c + 1;
    } while (local_1c < iVar3);
  }
  local_18 = 1;
LAB_680b7f84:
  if (param_3 != (int *)0x0) {
    *param_3 = local_c;
  }
  Ordinal_1407(&local_8);
  return local_18;
}



// ============================================================
// Function: media_releaseAllPlugins (FUN_680b7fb0)
// Address: 680b7fb0
// Size: 86 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_releaseAllPlugins(void)

{
  int iVar1;
  int iVar2;
  
  iVar1 = Ordinal_1157();
  if (iVar1 != 0) {
    iVar1 = Ordinal_1154();
    while (iVar1 = iVar1 + -1, -1 < iVar1) {
      iVar2 = Ordinal_1156();
      if (iVar2 != 0) {
        media_releasePluginRefs();
      }
    }
    Ordinal_1158();
    Ordinal_1163(&stack0xfffffff4);
  }
  return 0;
}



// ============================================================
// Function: media_queryXtraInterfaces (FUN_680b8010)
// Address: 680b8010
// Size: 91 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_queryXtraInterfaces(void)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 *puVar2;
  int iVar3;
  
  uVar1 = Ordinal_1038();
  puVar2 = (undefined4 *)Ordinal_2075(uVar1);
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = (**(code **)*puVar2)(puVar2,&DAT_68175d18);
    if (iVar3 == 0) {
      iVar3 = (**(code **)*puVar2)(puVar2,&DAT_68175d28,in_EAX + 4);
      if (iVar3 == 0) {
        iVar3 = (**(code **)*puVar2)(puVar2,&DAT_68175ff8,in_EAX + 8);
        if (iVar3 == 0) {
          return 1;
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: media_destroyXtraNode (FUN_680b8070)
// Address: 680b8070
// Size: 119 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_destroyXtraNode(void)

{
  void *this;
  int iVar1;
  int *piVar2;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (unaff_ESI != (int *)0x0) {
    this = (void *)unaff_ESI[0x131];
    if (this != (void *)0x0) {
      if (unaff_EDI != (int *)0x0) {
        iVar1 = *unaff_EDI;
        *unaff_EDI = (int)this;
        unaff_ESI[0x131] = iVar1;
      }
      media_initAssetLoader(this,unaff_ESI + 0x131);
    }
    piVar2 = (int *)*unaff_ESI;
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 0x30))(piVar2,unaff_ESI + 0x12f);
      (**(code **)(*(int *)*unaff_ESI + 8))((int *)*unaff_ESI);
    }
    piVar2 = (int *)unaff_ESI[1];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    piVar2 = (int *)unaff_ESI[2];
    if (piVar2 != (int *)0x0) {
      (**(code **)(*piVar2 + 8))(piVar2);
    }
    Ordinal_1125(&stack0xfffffff8);
  }
  return 0;
}



// ============================================================
// Function: media_validateXtraPath (FUN_680b80f0)
// Address: 680b80f0
// Size: 187 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_validateXtraPath(void)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_EBX;
  int *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar1 = Ordinal_1317();
  if (((iVar1 != 0) && (iVar1 = Ordinal_1351(), iVar1 != 0)) && (iVar1 = Ordinal_1310(), iVar1 != 0)
     ) {
    uVar2 = Ordinal_1038(&DAT_681761a8,&DAT_68176198,&local_40c);
    iVar1 = Ordinal_2063(uVar2);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*local_40c + 0xc))(local_40c,local_408);
      if ((iVar1 == 0) && (iVar1 = (**(code **)(*local_40c + 0x1c))(local_40c), iVar1 != 0)) {
        *unaff_EBX = 0;
      }
      (**(code **)(*local_40c + 8))(local_40c);
    }
  }
  return 0;
}



// ============================================================
// Function: media_registerXtraSession (FUN_680b81b0)
// Address: 680b81b0
// Size: 112 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_registerXtraSession(undefined4 param_1,int param_2)
{
  int iVar1;
  int unaff_ESI;
  undefined8 uVar2;
  int local_c;
  undefined4 local_8;
  
  iVar1 = Ordinal_1402(&local_8);
  if (iVar1 != 0) {
    local_c = Ordinal_1439(local_8,param_1,1);
    if (local_c != 0) {
      uVar2 = Ordinal_910(*(int *)(param_2 + 8),&local_c);
      *(undefined8 *)(unaff_ESI + 0x4bc) = uVar2;
      if ((int)uVar2 != 0) {
        iVar1 = media_queryXtraInterfaces();
        if (iVar1 == 0) {
          *(undefined4 *)(unaff_ESI + 0x8e4) = 1;
        }
      }
    }
    Ordinal_1407(&local_8);
  }
  return 0;
}



// ============================================================
// Function: media_validateXtraVersion (FUN_680b8220)
// Address: 680b8220
// Size: 150 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_validateXtraVersion(int param_1,int param_2)

{
  int *in_EAX;
  int iVar1;
  undefined1 *unaff_EBX;
  int *unaff_EDI;
  
  *unaff_EBX = 0;
  iVar1 = (**(code **)(*in_EAX + 0x28))();
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*unaff_EDI + 0x28))();
    if (iVar1 == 0) {
      if (param_2 == 3) {
        iVar1 = (**(code **)(*unaff_EDI + 0x40))();
        if (iVar1 != 0) goto LAB_680b82a1;
        if (param_1 < 0x18e) {
          iVar1 = (**(code **)(*unaff_EDI + 0x44))();
          goto LAB_680b82a1;
        }
      }
      iVar1 = -0x7ffbffff;
    }
  }
LAB_680b82a1:
  (**(code **)(*unaff_EDI + 0x30))();
  return iVar1;
}



// ============================================================
// Function: media_loadXtraPlugin (FUN_680b82c0)
// Address: 680b82c0
// Size: 96 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_loadXtraPlugin(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *unaff_EBX;
  
  media_findAssetEntry((int *)0x0,0,unaff_EBX,10,0);
  iVar1 = *(int *)(param_1 + 0x32c);
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      return -1;
    }
    iVar2 = media_findAssetEntry((int *)0x0,iVar1,unaff_EBX,6,param_3);
  } while ((iVar2 != 0) || (iVar2 = Ordinal_1255(param_2,param_1 + 0x32d), iVar2 != 0));
  return iVar1;
}




// ============================================================
// Function: media_loadBuiltinXtras (FUN_680b8320)
// Address: 680b8320
// Size: 237 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_loadBuiltinXtras(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  char *pcVar3;
  char *local_50;
  char *local_4c;
  char *local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  char *local_20;
  char *local_1c;
  char *local_18;
  char *local_14;
  undefined4 local_10;
  int local_c;
  char **local_8;
  
  pcVar3 = "Speech.x32";
  local_50 = "Speech.x32";
  local_4c = "swadcmpr.x32";
  local_48 = "SWA Import Export.x32";
  local_44 = "SWASTRM.X32";
  local_40 = "Flash Asset.x32";
  local_3c = "Font Asset.x32";
  local_38 = "Font Xtra.x32";
  local_34 = "Text Asset.x32";
  local_30 = "TextXtra.x32";
  local_2c = "Sound Control.x32";
  local_28 = "Shockwave 3d Asset.x32";
  local_24 = "Multiusr.x32";
  local_20 = "DirectSound.x32";
  local_1c = "MacroMix.x32";
  local_18 = "DVD Asset.x32";
  local_14 = "Windows Media Asset.x32";
  local_10 = 0;
  iVar1 = crt_getPlatformId();
  local_8 = &local_50;
  do {
    iVar2 = media_loadXtraPlugin(param_1,pcVar3,iVar1);
    if (iVar2 == -1) {
      iVar2 = media_processXtraLoadEx(param_2,&local_c);
      if (iVar2 == 0) {
        Ordinal_1233((byte *)(param_1 + 0x32c),pcVar3);
        media_loadAssetBlock(param_2,(byte *)(param_1 + 0x32c),local_c,6,iVar1);
      }
    }
    pcVar3 = local_8[1];
    local_8 = local_8 + 1;
  } while (pcVar3 != (char *)0x0);
  return 0;
}



// ============================================================
// Function: media_resolveXtraFilename (FUN_680b8410)
// Address: 680b8410
// Size: 297 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_resolveXtraFilename(undefined4 param_1)

{
  char *pcVar1;
  short sVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  char **ppcVar6;
  char *local_74 [4];
  char *local_64;
  char *local_60;
  char *local_5c;
  char *local_58;
  char *local_54;
  char *local_50;
  char *local_4c;
  char *local_48;
  char *local_44;
  char *local_40;
  char *local_3c;
  char *local_38;
  char *local_34;
  char *local_30;
  char *local_2c;
  char *local_28;
  char *local_24;
  char *local_20;
  char *local_1c;
  char *local_18;
  char *local_14;
  char *local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar5 = 0;
  local_74[0] = "Speech";
  local_74[1] = "Speech.x32";
  local_74[2] = "SWA Decompression PPC Xtra";
  local_74[3] = "swadcmpr.x32";
  local_64 = "SWA Import Export";
  local_60 = "SWA Import Export.x32";
  local_5c = "SWA Streaming PPC Xtra";
  local_58 = "SWASTRM.X32";
  local_54 = "Flash Asset PPC";
  local_50 = "Flash Asset.x32";
  local_4c = "Font Asset PPC";
  local_48 = "Font Asset.x32";
  local_44 = "Font Xtra PPC";
  local_40 = "Font Xtra.x32";
  local_3c = "TextAsset PPC";
  local_38 = "Text Asset.x32";
  local_34 = "TextXtra PPC";
  local_30 = "TextXtra.x32";
  local_2c = "Sound Control";
  local_28 = "Sound Control.x32";
  local_24 = "Shockwave 3d Asset Xtra";
  local_20 = "Shockwave 3d Asset.x32";
  local_1c = "Multiusr";
  local_18 = "Multiusr.x32";
  local_14 = "DVD Asset";
  local_10 = "DVD Asset.x32";
  local_c = 0;
  local_8 = 0;
  iVar3 = crt_getPlatformId();
  uVar4 = (uint)(iVar3 == 2);
  pcVar1 = local_74[uVar4];
  ppcVar6 = local_74 + uVar4;
  while( true ) {
    if (pcVar1 == (char *)0x0) {
      return 0;
    }
    sVar2 = Ordinal_1208(pcVar1,param_1);
    if (sVar2 == 0) break;
    pcVar1 = ppcVar6[2];
    ppcVar6 = ppcVar6 + 2;
    iVar5 = iVar5 + 2;
  }
  Ordinal_1202(param_1,local_74[(iVar5 - uVar4) + 1]);
  return 1;
}



// ============================================================
// Function: media_registerCoreXtras (FUN_680b8540)
// Address: 680b8540
// Size: 800 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_registerCoreXtras(int *param_1)
{
  char *pcVar1;
  char cVar2;
  undefined1 uVar3;
  short sVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 uVar8;
  uint uVar9;
  int unaff_EDI;
  int iVar10;
  int local_3c;
  byte local_38 [16];
  byte local_28 [16];
  undefined4 local_18;
  char local_14 [12];
  uint local_8;
  
  local_18 = 0x6177730c;
  builtin_strncpy(local_14,"dcmpr.x32",10);
  local_38[0] = 0xc;
  local_38[1] = 0x4d;
  local_38[2] = 0x61;
  local_38[3] = 99;
  local_38[4] = 'r';
  local_38[5] = 'o';
  local_38[6] = 'M';
  local_38[7] = 'i';
  local_38[8] = 'x';
  local_38[9] = '.';
  local_38[10] = 'x';
  local_38[0xb] = '3';
  local_38[0xc] = 0x32;
  local_38[0xd] = 0;
  iVar5 = media_loadXtraPlugin(unaff_EDI,"Flash Asset.x32",5);
  if ((iVar5 != -1) || (iVar5 = media_loadXtraPlugin(unaff_EDI,"Flash Asset PPC",2), iVar5 != -1)) {
    iVar5 = media_loadXtraPlugin(unaff_EDI,(int)&local_18 + 1,5);
    if ((iVar5 == -1) &&
       ((iVar5 = media_loadXtraPlugin(unaff_EDI,"SWA Decompression PPC Xtra",2), iVar5 == -1 &&
        (iVar5 = media_processXtraLoadEx(param_1,&local_3c), iVar5 == 0)))) {
      media_loadAssetBlock(param_1,(byte *)&local_18,local_3c,6,5);
    }
    iVar5 = media_loadXtraPlugin(unaff_EDI,local_38 + 1,5);
    if ((iVar5 == -1) && (iVar5 = media_processXtraLoadEx(param_1,&local_3c), iVar5 == 0)) {
      media_loadAssetBlock(param_1,local_38,local_3c,6,5);
    }
  }
  local_3c = media_loadXtraPlugin(unaff_EDI,"Qt3Asset.x32",5);
  if ((local_3c != -1) || (local_3c = media_loadXtraPlugin(unaff_EDI,"Quicktime Asset",2), local_3c != -1))
  {
    pcVar1 = (char *)(unaff_EDI + 0x32c);
    media_findAssetEntry((int *)0x0,local_3c,param_1,2,0);
    if (*pcVar1 != '\0') {
      iVar5 = media_findAssetEntry((int *)0x0,local_3c,param_1,1,0);
      if (iVar5 == 0) {
        pcVar6 = (char *)(unaff_EDI + 0x32d);
        do {
          cVar2 = *pcVar6;
          pcVar6 = pcVar6 + 1;
        } while (cVar2 != '\0');
        pcVar6 = malloc((size_t)(pcVar6 + (2 - (unaff_EDI + 0x32e))));
        pcVar7 = strstr((char *)(unaff_EDI + 0x32d),"http:");
        if (pcVar7 == (char *)0x0) {
          iVar5 = unaff_EDI + 0x32d;
          pcVar7 = "%s";
        }
        else {
          iVar5 = unaff_EDI + 0x332;
          pcVar7 = "https:%s";
        }
        sprintf(pcVar6,pcVar7,iVar5);
        uVar8 = Ordinal_1201(PTR_s_https___download_macromedia_com__6818e4c4);
        sVar4 = Ordinal_1209(pcVar6,PTR_s_https___download_macromedia_com__6818e4c4,uVar8);
        if (sVar4 != 0) {
          *pcVar1 = '\0';
        }
        free(pcVar6);
      }
      iVar5 = local_3c;
      if (*pcVar1 != '\0') {
        local_28[0] = 0xc;
        local_28[1] = 0x51;
        local_28[2] = 0x54;
        local_28[3] = 0x36;
        local_28[4] = 'A';
        local_28[5] = 's';
        local_28[6] = 's';
        local_28[7] = 'e';
        local_28[8] = 't';
        local_28[9] = '.';
        local_28[10] = 'x';
        local_28[0xb] = '3';
        local_28[0xc] = 0x32;
        local_28[0xd] = 0;
        media_loadAssetBlock(param_1,local_28,local_3c,6,5);
        iVar10 = 5;
        uVar9 = media_getPlatformXtraFlag(5);
        media_loadAssetBlock(param_1,local_28,iVar5,uVar9,iVar10);
        iVar5 = unaff_EDI + 0x19d;
        Ordinal_1202(iVar5,PTR_s_https___download_macromedia_com__6818e4c8);
        Ordinal_1204(iVar5,"/QT6Asset");
        iVar10 = Ordinal_1201(iVar5);
        *(undefined1 *)(iVar10 + 0x19d + unaff_EDI) = 0;
        iVar10 = Ordinal_1201(iVar5);
        if (iVar10 < 0xff) {
          uVar3 = Ordinal_1201(iVar5);
          *(undefined1 *)(unaff_EDI + 0x19c) = uVar3;
        }
        else {
          *(undefined1 *)(unaff_EDI + 0x19c) = 0xff;
        }
        media_loadAssetBlock(param_1,(byte *)(unaff_EDI + 0x19c),local_3c,1,0);
      }
    }
  }
  iVar5 = media_loadXtraPlugin(unaff_EDI,"TextXtra.x32",5);
  if ((iVar5 != -1) || (iVar5 = media_loadXtraPlugin(unaff_EDI,"TextXtra PPC",2), iVar5 != -1)) {
    local_18 = local_18 & 0xffffff00;
    media_loadAssetBlock(param_1,(byte *)&local_18,iVar5,2,0);
  }
  iVar5 = media_loadXtraPlugin(unaff_EDI,"Font Xtra.x32",5);
  if ((iVar5 != -1) || (iVar5 = media_loadXtraPlugin(unaff_EDI,"Font Xtra PPC",2), iVar5 != -1)) {
    local_18 = local_18 & 0xffffff00;
    media_loadAssetBlock(param_1,(byte *)&local_18,iVar5,2,0);
  }
  return 0;
}



// ============================================================
// Function: media_processXtraEntries (FUN_680b8860)
// Address: 680b8860
// Size: 715 bytes
// Params: undefined4 * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_processXtraEntries(undefined4 *param_1,int *param_2)
{
  char cVar1;
  int *piVar2;
  byte bVar3;
  short sVar4;
  int iVar5;
  int iVar6;
  char *pcVar7;
  char *pcVar8;
  undefined4 uVar9;
  byte *pbVar10;
  byte *pbVar11;
  char *_Str;
  undefined4 local_38 [2];
  uint local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 *local_24;
  int local_20;
  int local_1c;
  int *local_18;
  int local_14;
  int local_10;
  byte *local_c;
  int local_8;
  
  local_18 = (int *)*param_1;
  local_28 = param_1[1];
  local_24 = param_1 + 0x12f;
  local_14 = 5;
  if (param_1[0x12f] != 0) {
    iVar5 = crt_getPlatformId();
    local_10 = iVar5;
    local_30 = media_getPlatformXtraFlag(iVar5);
    if (iVar5 == 5) {
      local_14 = 2;
    }
    media_registerCoreXtras(param_2);
    media_findAssetEntry((int *)0x0,0,param_2,10,0);
    local_20 = local_20 + -1;
    if (-1 < local_20) {
      pbVar11 = (byte *)(param_1 + 3);
      local_c = pbVar11;
      do {
        local_8 = local_20;
        iVar5 = media_findAssetEntry((int *)0x0,local_20,param_2,6,local_10);
        if (iVar5 == 0) {
LAB_680b8949:
          local_38[0] = 0;
          Ordinal_1217((int)param_1 + 0xd,(int)(char)*pbVar11);
          iVar5 = (**(code **)(*local_18 + 100))(local_18,(int)param_1 + 0xd,local_38);
          piVar2 = local_18;
          if (iVar5 == 0) {
            local_2c = (int)param_1 + 0x19d;
            iVar6 = media_validateXtraVersion((int)local_24,(int)local_38);
            local_1c = iVar6;
            (**(code **)(*piVar2 + 0x30))(piVar2,local_38);
            iVar5 = local_8;
            pbVar11 = local_c;
            if (iVar6 == 0) {
              pbVar10 = (byte *)(param_1 + 0xcb);
              media_findAssetEntry((int *)0x0,local_8,param_2,2,0);
              if (*pbVar10 != 0) {
                local_1c = media_findAssetEntry((int *)0x0,iVar5,param_2,1,0);
                if (local_1c == 0) {
                  _Str = (char *)((int)param_1 + 0x32d);
                  pcVar7 = _Str;
                  do {
                    cVar1 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  } while (cVar1 != '\0');
                  pcVar7 = malloc((size_t)(pcVar7 + (2 - ((int)param_1 + 0x32e))));
                  pcVar8 = strstr(_Str,"http:");
                  if (pcVar8 == (char *)0x0) {
                    pcVar8 = "%s";
                  }
                  else {
                    _Str = (char *)((int)param_1 + 0x332);
                    pcVar8 = "https:%s";
                  }
                  sprintf(pcVar7,pcVar8,_Str);
                  uVar9 = Ordinal_1201(PTR_s_https___download_macromedia_com__6818e4c4);
                  sVar4 = Ordinal_1209(pcVar7,PTR_s_https___download_macromedia_com__6818e4c4,uVar9)
                  ;
                  if (sVar4 == 0) {
                    *pbVar10 = 0;
                  }
                  free(pcVar7);
                }
                pbVar11 = local_c;
                if (*pbVar10 != 0) goto LAB_680b8b15;
              }
              iVar5 = local_2c;
              pbVar11 = local_c;
              if (local_1c == 0) {
                iVar6 = Ordinal_1201(local_2c);
                *(undefined1 *)(iVar6 + 0x19d + (int)param_1) = 0;
                iVar6 = Ordinal_1201(iVar5);
                pbVar11 = (byte *)(param_1 + 0x67);
                if (iVar6 < 0xff) {
                  bVar3 = Ordinal_1201(iVar5);
                  *pbVar11 = bVar3;
                }
                else {
                  *pbVar11 = 0xff;
                }
                iVar5 = media_loadAssetBlock(param_2,pbVar11,local_8,1,0);
                pbVar11 = local_c;
                if ((iVar5 == 0) &&
                   (iVar6 = media_loadAssetBlock(param_2,local_c,local_8,local_30,local_10), iVar5 = local_8
                   , pbVar11 = local_c, iVar6 == 0)) {
                  *pbVar10 = 1;
                  media_loadAssetBlock(param_2,pbVar10,local_8,0xb,local_10);
                  *pbVar10 = 1;
                  media_loadAssetBlock(param_2,pbVar10,iVar5,2,0);
                  pbVar11 = local_c;
                }
              }
            }
          }
        }
        else {
          iVar5 = media_findAssetEntry((int *)0x0,local_20,param_2,6,local_14);
          if (iVar5 == 0) {
            iVar5 = (int)param_1 + 0xd;
            iVar6 = media_resolveXtraFilename(iVar5);
            if (iVar6 != 0) {
              iVar6 = Ordinal_1201(iVar5);
              *(undefined1 *)(iVar6 + 0xd + (int)param_1) = 0;
              iVar6 = Ordinal_1201(iVar5);
              if (iVar6 < 0xff) {
                bVar3 = Ordinal_1201(iVar5);
                *pbVar11 = bVar3;
              }
              else {
                *pbVar11 = 0xff;
              }
              goto LAB_680b8949;
            }
          }
        }
LAB_680b8b15:
        local_20 = local_8 + -1;
      } while (-1 < local_20);
    }
  }
  return 0;
}




// ============================================================
// Function: media_releaseCastLib (FUN_680b8b30)
// Address: 680b8b30
// Size: 105 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_releaseCastLib(undefined4 param_1,int *param_2)
{
  int local_14;
  int *piVar1;
  uint uVar2;
  int iVar3;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this;
  
  if (*param_2 != 0) {
    piVar1 = (int *)Ordinal_1114(*param_2);
    if (piVar1 != (int *)0x0) {
      uVar2 = Ordinal_1116(*param_2);
      this = extraout_ECX;
      if (0x20cb < uVar2) {
        iVar3 = media_releaseAllPlugins();
        piVar1[0x830] = iVar3;
        iVar3 = media_destroyXtraNode();
        piVar1[0x831] = iVar3;
        this = extraout_ECX_00;
      }
      media_initAssetLoader(this,piVar1);
    }
    Ordinal_1113(param_2);
  }
  param_2[1] = 0;
  return 0;
}



// ============================================================
// Function: media_scanXtraPaths (FUN_680b8ba0)
// Address: 680b8ba0
// Size: 248 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_scanXtraPaths(int param_1,int param_2)
{
  int iVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int local_430;
  undefined1 local_420 [1048];
  uint local_8;
  
  iVar1 = *(int *)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 8) + 0xc);
  iVar4 = 0;
  bVar2 = false;
  while( true ) {
    iVar3 = crt_writeFormatData(iVar1,local_420,iVar4);
    if (iVar3 == 0) goto LAB_680b8c6c;
    iVar3 = media_validateXtraPath();
    if (iVar3 != 0) break;
    iVar4 = iVar4 + 1;
    if (7 < iVar4) {
LAB_680b8c22:
      if (local_430 != 0) {
        media_registerXtraSession(local_430,param_2);
      }
      if (bVar2) {
        *(undefined4 *)(param_1 + 0x8e0) = 1;
        return 0;
      }
LAB_680b8c6c:
      if (*(int *)(param_1 + 0x4bc) == 0) {
        *(undefined4 *)(param_1 + 0x8e4) = 1;
      }
      return 0;
    }
  }
  bVar2 = true;
  goto LAB_680b8c22;
}



// ============================================================
// Function: media_assignCastData (FUN_680b8ca0)
// Address: 680b8ca0
// Size: 170 bytes
// Params: void * this, int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall media_assignCastData(void *this,int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  void *extraout_ECX;
  int iVar3;
  int local_8;
  
  iVar3 = 0;
  local_8 = 0;
  if ((param_1 != 0) && (param_2 != 0)) {
    if (param_3 == 0) {
      local_8 = param_2;
    }
    else {
      iVar1 = media_findAssetRef();
      if (iVar1 == 0) {
        local_8 = param_2;
      }
      else {
        iVar3 = Ordinal_1111(4,1);
        piVar2 = (int *)Ordinal_1114(iVar3);
        if (piVar2 == (int *)0x0) {
          return 0x80040002;
        }
        *piVar2 = param_2;
        Ordinal_1115(iVar3);
      }
      media_releaseCastLib(param_1,(int *)(param_1 + 0x450));
      *(int *)(param_1 + 0x450) = iVar3;
      this = extraout_ECX;
      if (param_3 == 1) {
        *(undefined4 *)(param_1 + 0x458) = 1;
      }
    }
    if (local_8 != 0) {
      media_initAssetLoader(this,&local_8);
    }
    return 0;
  }
  return 0x80040001;
}



// ============================================================
// Function: media_assignCastDataLocked (FUN_680b8d50)
// Address: 680b8d50
// Size: 137 bytes
// Params: int param_1, undefined4 * * * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_assignCastDataLocked(int param_1,undefined4 ***param_2,int param_3,int param_4)
{
  int *piVar1;
  undefined4 ***pppuVar2;
  undefined4 ***local_14;
  undefined4 ****local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  pppuVar2 = (undefined4 ***)0x0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    pppuVar2 = param_2;
    if (param_2 == (undefined4 ***)0x0) {
      pppuVar2 = (undefined4 ***)*piVar1;
    }
    Ordinal_2330();
    param_2 = &local_14;
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = (undefined4 ****)param_2;
    local_14 = pppuVar2;
  }
  media_assignCastData(param_2,(int)pppuVar2[8],param_3,param_4);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: media_loadXtraOrchestrator (FUN_680b8de0)
// Address: 680b8de0
// Size: 692 bytes
// Params: void * this, int * param_1, int * param_2, int * param_3, int param_4, int param_5
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall
media_loadXtraOrchestrator(void *this,int *param_1,int *param_2,int *param_3,int param_4,int param_5)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 uVar5;
  void *extraout_ECX;
  void *extraout_ECX_00;
  void *this_00;
  undefined4 *puVar6;
  uint uVar7;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 2;
  if (0 < param_2[1]) {
    if (2 < param_2[1]) goto LAB_680b9015;
    iVar4 = Ordinal_1114(*param_2);
    if (iVar4 == 0) goto LAB_680b9015;
    if (param_5 == 0) {
      local_8 = 1;
    }
    else {
      local_8 = media_loadXtraList((int)param_1);
    }
    iVar1 = local_8;
    Ordinal_1115(*param_2);
    if (iVar1 != 2) {
      if (iVar1 == 0) goto LAB_680b900e;
      param_2[1] = 4;
      if (*(int *)(iVar4 + 0x20c8) != 0) {
        Ordinal_558(*(int *)(*(int *)(*(int *)(param_4 + 4) + 4) + 0xc));
      }
    }
    goto LAB_680b9008;
  }
  local_8 = media_openXtraBlock(this,(int)param_3,param_4,0);
  if (local_8 == 2) goto LAB_680b9015;
  if (local_8 != 0) {
    if (local_8 == 1) {
      puVar6 = (undefined4 *)0x0;
      local_c = 0;
      if (param_3 != (int *)0x0) {
        uVar7 = *(uint *)(*(int *)(*(int *)(*(int *)(param_4 + 4) + 4) + 8) + 0x1c) >> 9 & 1;
        if ((*(uint *)(param_4 + 0x20) & 0x100) != 0) {
          uVar7 = 1;
        }
        if ((param_5 != 0) || (uVar7 != 0)) {
          puVar6 = (undefined4 *)Ordinal_1124(0x8e8);
          if (puVar6 != (undefined4 *)0x0) {
            media_scanXtraPaths((int)puVar6,param_4);
            if (puVar6[0x239] == 0) {
              piVar2 = media_cloneAssetContainer(param_3);
              puVar6[0x131] = piVar2;
              if (uVar7 != 0) {
                media_loadBuiltinXtras((int)puVar6,param_3);
              }
              media_processXtraEntries(puVar6,param_3);
            }
          }
          if (param_5 != 0) {
            local_c = media_countScoreDataEntries(param_3);
          }
          if ((puVar6 != (undefined4 *)0x0) && ((local_c == 0 || (puVar6[0x239] != 0)))) {
            puVar6 = (undefined4 *)media_destroyXtraNode();
          }
        }
        local_10 = Ordinal_1111((-(uint)(local_c != 0) & 0x20c8) + 4,1);
        puVar3 = (undefined4 *)Ordinal_1114(local_10);
        this_00 = extraout_ECX;
        if (puVar3 == (undefined4 *)0x0) {
          Ordinal_1113(&local_10);
          this_00 = extraout_ECX_00;
        }
        if (local_10 != 0) {
          *param_2 = local_10;
          param_2[1] = 4;
          *puVar3 = param_3;
          if (local_c != 0) {
            puVar3[1] = param_1;
            puVar3[2] = param_4;
            puVar3[3] = local_c;
            puVar3[4] = 0xffffffff;
            puVar3[0x831] = puVar6;
            param_2[1] = 1;
          }
          if (param_2[1] == 1) {
            local_8 = media_searchXtraPlugin(param_1);
            param_2[1] = (uint)(local_8 != 2) * 2 + 2;
          }
          Ordinal_1115(local_10);
          goto LAB_680b9008;
        }
        media_initAssetLoader(this_00,(int *)&param_3);
        local_8 = 0;
        lingo_formatDebugMsg(param_1,-0x7a);
      }
    }
    else {
LAB_680b9008:
      if (local_8 != 0) goto LAB_680b9015;
    }
  }
LAB_680b900e:
  param_2[1] = 4;
LAB_680b9015:
  if (param_2[1] == 4) {
    if (*param_2 != 0) {
      iVar4 = Ordinal_1116(*param_2);
      if (iVar4 == 0x20cc) {
        iVar4 = Ordinal_1114(*param_2);
        if (iVar4 != 0) {
          if (*(int *)(iVar4 + 0x20c4) != 0) {
            uVar5 = media_destroyXtraNode();
            *(undefined4 *)(iVar4 + 0x20c4) = uVar5;
          }
          uVar5 = media_releaseAllPlugins();
          *(undefined4 *)(iVar4 + 0x20c0) = uVar5;
          Ordinal_1115(*param_2);
        }
        Ordinal_1117(param_2,4,0);
      }
    }
    return 1;
  }
  return local_8;
}



// ============================================================
// Function: media_getScoreDataEntry (FUN_680b90a0)
// Address: 680b90a0
// Size: 89 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall media_getScoreDataEntry(void *this,int param_1)
{
  undefined1 local_198 [400];
  uint local_8;
  
  if (5000 < param_1) {
    return 0;
  }
  media_processXtraLoad(this,param_1,0x20,0,local_198,(int *)0x0);
  return 0;
}



// ============================================================
// Function: media_processXtraLoadEntry (FUN_680b9100)
// Address: 680b9100
// Size: 69 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_processXtraLoadEntry(undefined4 param_1,int param_2,int *param_3)
{
  undefined1 local_198 [400];
  uint local_8;
  
  media_processXtraLoad(param_3,param_2,2,0,local_198,(int *)0x0);
  return 0;
}



// ============================================================
// Function: media_getPlatformXtraFlag (FUN_680b9150)
// Address: 680b9150
// Size: 39 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getPlatformXtraFlag(int param_1)

{
  if (param_1 == 2) {
    return 0x21;
  }
  return (-(uint)(param_1 != 5) & 0x87) + 0x41;
}



// ============================================================
// Function: media_findScoreDataIndex (FUN_680b9180)
// Address: 680b9180
// Size: 69 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_findScoreDataIndex(int param_1)

{
  undefined4 uVar1;
  char cVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int *unaff_EBX;
  int iVar3;
  int iVar4;
  
  iVar3 = 0;
  iVar4 = 0;
  cVar2 = media_getScoreDataEntry(unaff_EBX,0);
  uVar1 = extraout_ECX;
  while( true ) {
    if (cVar2 != '\0') {
      return -1;
    }
    cVar2 = media_processXtraLoadEntry(uVar1,iVar3,unaff_EBX);
    if ((cVar2 == '\0') && (iVar4 = iVar4 + 1, iVar4 == param_1)) break;
    iVar3 = iVar3 + 1;
    cVar2 = media_getScoreDataEntry(unaff_EBX,iVar3);
    uVar1 = extraout_ECX_00;
  }
  return iVar3;
}



// ============================================================
// Function: media_processXtraNotify (FUN_680b91d0)
// Address: 680b91d0
// Size: 76 bytes
// Params: undefined4 param_1, int param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_processXtraNotify(undefined4 param_1,int param_2,int *param_3,int param_4)
{
  undefined1 local_198 [400];
  uint local_8;
  
  media_processXtraLoad(param_3,param_4,0xb,param_2,local_198,(int *)0x0);
  return 0;
}



// ============================================================
// Function: media_isKnownPlatform (FUN_680b9220)
// Address: 680b9220
// Size: 16 bytes
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_isKnownPlatform(void)

{
  int in_EAX;
  
  if ((in_EAX != 2) && (in_EAX - 5U != 0)) {
    return in_EAX - 5U & 0xffffff00;
  }
  return 1;
}



