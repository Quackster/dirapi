// Module: bitmap
// Topic: File import/export, thumbnailing, printing, trace logging, score format I/O
// Address range: 0x680e3b20 - 0x680e5b90
// Functions (23):
//   bitmap_importMemberFromSource
//   bitmap_createSnapshot
//   bitmap_importMediaFile
//   bitmap_exportMediaFile
//   bitmap_printThumbnails
//   bitmap_initExportPath
//   bitmap_cleanupExportState
//   bitmap_getExportPath
//   FUN_680e4be0
//   bitmap_setTraceLevel
//   bitmap_importData
//   bitmap_exportData
//   bitmap_openTraceLog
//   bitmap_recordFilePos
//   bitmap_writeTraceEntry
//   bitmap_logString
//   bitmap_readScoreHeader
//   bitmap_writeScoreHeader
//   bitmap_writeScoreHeaderEx
//   bitmap_writeScoreHeaderAlt
//   bitmap_readScoreData
//   bitmap_applyScoreLayout
//   bitmap_readPaletteMap

// ============================================================
// Function: bitmap_importMemberFromSource (FUN_680e3b20)
// Address: 680e3b20
// Size: 483 bytes
// Params: byte * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_importMemberFromSource(byte *param_1,int param_2)
{
  int iVar1;
  int *this;
  int iVar2;
  uint local_54;
  int *local_50;
  int local_4c;
  int local_48;
  int local_44;
  int local_40;
  undefined4 local_3c;
  int local_38;
  int local_34;
  int *local_30;
  byte *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar2 = *(int *)(param_1 + 0x18);
  local_38 = param_2;
  local_30 = (int *)0x0;
  local_2c = (byte *)0x0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_34 = 0;
  local_40 = 0;
  local_44 = 0;
  local_3c = 0;
  iVar1 = Ordinal_2000();
  if ((iVar1 == 0) || (this = rendering_getDispatchEntry(iVar2,param_2,&local_34), this == (int *)0x0))
  goto LAB_680e3ccc;
  local_40 = Ordinal_2002(1000);
  if (local_40 == 0) {
    local_48 = Ordinal_2006(&local_54,&local_4c,&local_50);
    if (local_48 == 0) {
      iVar2 = bitmap_createFromDC(param_1);
      if (iVar2 != 0) goto LAB_680e3c66;
      iVar2 = bitmap_exportLinkedMedia(param_1,local_38);
      goto joined_r0x680e3cb6;
    }
    iVar1 = rendering_blitMedia(param_1,iVar2,local_38,6,0,local_48,0,local_4c,local_50,0);
    if (iVar1 == 0) {
      Ordinal_1113(&local_48);
      goto LAB_680e3cbf;
    }
    iVar2 = rendering_resolveState(iVar2,local_38);
    rendering_getMediaRef(iVar2,local_54);
LAB_680e3cb8:
    local_3c = 1;
  }
  else {
    iVar2 = bitmap_receiveSpriteData(this,*(void **)(param_1 + 0x20),local_34);
    if (iVar2 != 0) {
      if (((this[2] == 2) || (local_44 = Ordinal_2002(0x3ef), local_44 == 0)) ||
         (iVar2 = rendering_importMemberData(*(undefined4 **)(param_1 + 0x20),(int)this,local_44), iVar2 != 0)) {
        local_2c = param_1;
        local_28 = 0xc;
        local_30 = this;
        iVar2 = rendering_initState((int *)&local_30);
        if (iVar2 == 0) goto LAB_680e3cbf;
      }
LAB_680e3c66:
      iVar2 = rendering_getFrameCount((int)this);
      if ((iVar2 == 0) || (this[2] == 0xb)) {
        this[0xb] = this[0xb] | 0x200;
      }
      else {
        this[0xb] = this[0xb] & 0xfffffdff;
      }
      this = (int *)rendering_getDispatchCount();
      iVar2 = rendering_loadMediaBlock(param_1,local_38,&local_34,(int *)0x1,1);
joined_r0x680e3cb6:
      if (iVar2 != 0) goto LAB_680e3cb8;
    }
  }
LAB_680e3cbf:
  if (this != (int *)0x0) {
    rendering_getDispatchCount();
  }
LAB_680e3ccc:
  rendering_loadMediaData(param_1,&local_34);
  Ordinal_1113(&local_40);
  Ordinal_1113(&local_44);
  Ordinal_2001();
  return 0;
}



// ============================================================
// Function: bitmap_createSnapshot (FUN_680e3d10)
// Address: 680e3d10
// Size: 132 bytes
// Params: void * this, undefined4 param_1, undefined4 param_2, undefined4 param_3, byte param_4
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall
bitmap_createSnapshot(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,byte param_4)

{
  int *piVar1;
  int iVar2;
  int *unaff_EBX;
  int iVar3;
  int local_8;
  
  iVar3 = 0;
  local_8 = 0;
  iVar2 = *(int *)(*(int *)((int)this + 0x20) + 4);
  piVar1 = *(int **)(iVar2 + 0xd8);
  if ((((8 < (int)piVar1) ||
       (iVar3 = rendering_dispatchChannelOp((int)this,*(int *)(iVar2 + 0x54),piVar1), iVar3 != 0)) &&
      (local_8 = Ordinal_1658(param_1,param_3,param_2,0,iVar3), local_8 != 0)) &&
     ((param_4 & 4) != 0)) {
    iVar2 = *unaff_EBX;
    if (*unaff_EBX == 0) {
      iVar2 = iVar3;
    }
    iVar2 = Ordinal_1663(&local_8,iVar2,0);
    if (iVar2 == 0) {
      Ordinal_1653(&local_8);
    }
  }
  return local_8;
}



// ============================================================
// Function: bitmap_importMediaFile (FUN_680e3da0)
// Address: 680e3da0
// Size: 625 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_importMediaFile(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)
{
  bool bVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int *local_68;
  undefined4 local_64;
  int local_60;
  int local_5c;
  int *local_58;
  int local_54;
  int local_50;
  int *local_4c;
  int local_48;
  byte *local_44;
  int local_40;
  byte *local_3c;
  byte **local_38;
  undefined4 local_34;
  int local_30;
  byte *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar5 = 0;
  local_64 = param_3;
  bVar1 = false;
  local_50 = 0;
  local_4c = (int *)0x0;
  local_60 = 0;
  local_68 = (int *)0x0;
  local_5c = 0;
  local_40 = 0;
  local_48 = 1;
  if (param_1 == 0) {
    local_58 = (int *)0x0;
  }
  else {
    local_58 = *(int **)(param_1 + 0x20);
  }
  local_44 = (byte *)0x0;
  local_54 = 0;
  if ((local_58 != (int *)0x0) && (local_58[1] != 0)) {
    local_54 = *(int *)(local_58[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (local_44 = (byte *)**(int **)(param_1 + 0x20), local_44 == (byte *)0x0)))) {
      local_44 = (byte *)*local_58;
    }
    Ordinal_2330();
    local_3c = local_44;
    local_34 = 0;
    local_38 = DAT_68196374;
    DAT_68196374 = &local_3c;
  }
  iVar2 = Ordinal_1405(&local_40,local_64,1,3);
  if (iVar2 != 0) {
    uVar3 = Ordinal_1435(local_40);
    switch(param_4) {
    case 2:
    case 8:
    case 0xc:
    case 0xd:
    case 0xe:
      iVar2 = bitmap_createSnapshot(local_44,local_40,param_5,uVar3,5);
      local_60 = iVar2;
      if (iVar2 == 0) goto LAB_680e3fc2;
      local_4c = (int *)0x5;
      iVar5 = local_50;
      break;
    case 3:
      local_48 = 4;
      iVar2 = Ordinal_1739(local_40,param_5,uVar3);
      local_50 = iVar2;
      if (iVar2 == 0) goto LAB_680e3fc2;
      break;
    case 4:
      local_48 = 6;
      iVar2 = Ordinal_1927(local_40,param_5,uVar3,&local_5c,&local_68);
      if (iVar2 == 0) goto LAB_680e3fc2;
      local_4c = local_68;
      iVar5 = local_5c;
      break;
    default:
      local_48 = Ordinal_1388(param_4);
      if (local_48 == 0) goto LAB_680e3fc2;
      iVar2 = 0;
      local_4c = (int *)0x0;
      iVar5 = 0;
      break;
    case 0xb:
      local_48 = 10;
      iVar2 = 0;
      break;
    case 0x15:
      local_48 = 9;
      iVar2 = 0;
    }
    Ordinal_1407(&local_40);
    iVar4 = rendering_blitMedia(local_44,local_54,param_2,local_48,0,iVar2,0,iVar5,local_4c,0);
    if (iVar4 != 0) {
      local_2c = (byte *)0x0;
      local_28 = 0;
      local_24 = 0;
      local_20 = 0;
      local_1c = 0;
      local_18 = 0;
      local_14 = 0;
      local_10 = (int *)0x0;
      local_c = 0;
      local_30 = rendering_resolveState(local_54,param_2);
      local_2c = local_44;
      local_28 = 1;
      local_1c = 0;
      local_18 = 0;
      local_10 = local_4c;
      local_c = local_64;
      local_20 = iVar2;
      local_14 = iVar5;
      iVar5 = rendering_initState(&local_30);
      if (iVar5 != 0) {
        bVar1 = true;
      }
    }
  }
LAB_680e3fc2:
  if (local_58 != (int *)0x0) {
    DAT_68196374 = local_38;
    Ordinal_2331();
  }
  if (!bVar1) {
    Ordinal_1733(&local_50);
    Ordinal_1653(&local_60);
  }
  if (local_40 != 0) {
    Ordinal_1407(&local_40);
  }
  return 0;
}



// ============================================================
// Function: bitmap_exportMediaFile (FUN_680e4040)
// Address: 680e4040
// Size: 1405 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_exportMediaFile(int param_1,int param_2,undefined4 param_3,int param_4,int *param_5)
{
  bool bVar1;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int *piVar6;
  int local_89c;
  int local_898;
  int local_894;
  int *local_890;
  int local_88c;
  int local_888;
  int local_884;
  int local_880;
  int *local_87c;
  int local_878;
  int *local_874;
  int *local_870;
  int local_86c;
  uint local_868;
  int local_864;
  byte *local_860;
  int local_85c;
  undefined4 local_858;
  byte *local_854;
  byte **local_850;
  undefined4 local_84c;
  int *local_848;
  byte *local_844;
  undefined4 local_840;
  undefined4 local_83c;
  int local_838;
  undefined1 *local_834;
  int local_830;
  int local_82c;
  int *local_828;
  undefined4 local_824;
  undefined1 local_820 [1048];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_890 = param_5;
  local_894 = 0;
  local_858 = 0;
  local_878 = 0;
  local_89c = 0;
  local_88c = 0;
  local_87c = (int *)0x0;
  local_888 = 0;
  local_85c = 0;
  local_86c = 0;
  local_870 = (int *)0x0;
  local_864 = 0;
  if (param_1 == 0) {
    local_874 = (int *)0x0;
  }
  else {
    local_874 = *(int **)(param_1 + 0x20);
  }
  local_860 = (byte *)0x0;
  local_898 = 0;
  if ((local_874 != (int *)0x0) && (local_874[1] != 0)) {
    local_898 = *(int *)(local_874[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (local_860 = (byte *)**(int **)(param_1 + 0x20), local_860 == (byte *)0x0)))) {
      local_860 = (byte *)*local_874;
    }
    Ordinal_2330();
    local_854 = local_860;
    local_84c = 0;
    local_850 = DAT_68196374;
    DAT_68196374 = &local_854;
  }
  Ordinal_1309(local_820,0x400,param_3,2);
  iVar3 = Ordinal_1322(local_820);
  local_884 = iVar3;
  iVar4 = scoreEngine_writeChannelData(*(int *)(local_860 + 0x20),0,local_820,iVar3,0,0,0);
  if (iVar4 == 0) goto LAB_680e4549;
  if (iVar3 == 0) {
    local_884 = Ordinal_1322(local_820);
  }
  iVar3 = media_getDataPtr(*(int **)(local_898 + 4));
  if ((*(code **)(iVar3 + 0x7c) != (code *)0x0) &&
     (local_864 = (**(code **)(iVar3 + 0x7c))
                            (*(undefined4 *)(local_874[1] + 4),param_2,local_820,param_4,local_890),
     local_864 != 0)) goto LAB_680e4549;
  local_868 = Ordinal_1330(local_820);
  iVar3 = lingo_setPlaybackProperty(param_1,local_820,&local_894);
  bVar1 = true;
  local_880 = 1;
  if (iVar3 == 0) {
    local_864 = 0;
    goto LAB_680e4549;
  }
  if (iVar3 == 2) {
    if (param_4 == 0) {
      local_864 = 0;
      goto LAB_680e4549;
    }
    local_880 = 0;
    bVar1 = false;
  }
  if (local_894 == 0) {
    iVar3 = Ordinal_1402(&local_858,local_820,1);
LAB_680e4270:
    if (iVar3 == 0) goto LAB_680e4549;
  }
  else if (bVar1) {
    iVar3 = Ordinal_1405(&local_858,local_894,1,3);
    goto LAB_680e4270;
  }
  uVar5 = Ordinal_1435(local_858);
  iVar3 = local_85c;
  switch(local_884) {
  case 2:
  case 8:
  case 0xc:
  case 0xd:
  case 0xe:
    iVar4 = 1;
    if (bVar1) {
      local_89c = bitmap_createSnapshot(local_860,local_858,local_868,uVar5,(byte)local_890);
      if (local_89c == 0) goto LAB_680e4549;
      local_86c = local_878;
      local_870 = local_890;
      iVar3 = local_89c;
    }
    break;
  case 3:
    iVar4 = 4;
    if ((bVar1) &&
       (local_878 = Ordinal_1739(local_858,local_868,uVar5), iVar3 = local_878, local_878 == 0))
    goto LAB_680e4549;
    break;
  case 4:
    iVar4 = 6;
    if (bVar1) {
      if (param_4 == 0) {
        iVar3 = Ordinal_1927(local_858,local_868,uVar5,&local_888,&local_87c);
        local_88c = iVar3;
      }
      else {
        iVar3 = Ordinal_1926(local_858,local_868,&local_888,&local_87c);
      }
      if (iVar3 == 0) goto LAB_680e4549;
    }
    local_85c = local_88c;
    local_86c = local_888;
    local_870 = local_87c;
    iVar3 = local_85c;
    break;
  default:
    iVar4 = Ordinal_1388(local_884);
    if (iVar4 == 0) goto LAB_680e4549;
    local_86c = 0;
    local_870 = (int *)0x0;
    goto LAB_680e43f6;
  case 0xb:
    iVar4 = 10;
    goto LAB_680e43f6;
  case 0x15:
    iVar4 = 9;
LAB_680e43f6:
    local_85c = 0;
    iVar3 = local_85c;
  }
  local_85c = iVar3;
  Ordinal_1407(&local_858);
  iVar3 = local_898;
  iVar4 = rendering_blitMedia(local_860,local_898,param_2,iVar4,local_820,local_85c,param_4,local_86c,
                       local_870,0);
  if (iVar4 != 0) {
    piVar6 = (int *)rendering_resolveState(iVar3,param_2);
    pbVar2 = local_860;
    local_83c = 0;
    local_824 = 0;
    local_834 = local_820;
    local_830 = param_4;
    local_838 = local_85c;
    local_844 = local_860;
    local_840 = 1;
    local_82c = local_86c;
    local_828 = local_870;
    local_848 = piVar6;
    iVar3 = rendering_initState((int *)&local_848);
    if (iVar3 != 0) {
      iVar3 = Ordinal_1379(local_884,local_820,local_408);
      if (iVar3 != 0) {
        rendering_blendMediaEx(piVar6,(int)local_408,0);
      }
      rendering_getMediaRef((int)piVar6,local_868);
      if (local_880 == 0) {
        rendering_compositeMedia(*(int **)(pbVar2 + 0x20),piVar6,1);
      }
      local_864 = 1;
    }
  }
LAB_680e4549:
  Ordinal_1407(&local_858);
  lingo_releaseObjectRef(&local_894);
  if (local_864 == 0) {
    Ordinal_1733(&local_878);
    Ordinal_1653(&local_89c);
    Ordinal_1113(&local_88c);
  }
  if (local_874 != (int *)0x0) {
    DAT_68196374 = local_850;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: bitmap_printThumbnails (FUN_680e45f0)
// Address: 680e45f0
// Size: 1305 bytes
// Params: byte * param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int bitmap_printThumbnails(byte *param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  uint *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  int local_1654 [58];
  undefined4 local_156c;
  undefined4 local_1568;
  int local_1560;
  int local_155c;
  int local_1558;
  int local_1554;
  int local_1550;
  int *local_154c;
  int local_1548;
  int local_1544;
  int local_1540;
  int local_153c;
  uint *local_1538;
  int local_1534;
  undefined4 local_1530;
  int local_152c;
  int local_1528;
  int local_1524;
  int *local_1520;
  int local_151c;
  int local_1518;
  undefined4 local_1514 [10];
  undefined1 local_14ec [5180];
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  undefined1 local_88 [128];
  uint local_8;
  
  local_153c = 0;
  local_151c = 0;
  local_1530 = 0;
  local_1520 = (int *)0x0;
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 4);
  local_154c = (int *)(iVar1 + 0x24);
  piVar6 = local_154c;
  piVar3 = local_1654;
  for (iVar5 = 0x3a; iVar5 != 0; iVar5 = iVar5 + -1) {
    *piVar3 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar3 = piVar3 + 1;
  }
  local_1518 = iVar1;
  iVar1 = playback_setTempo(param_1,(int)&local_98);
  if (iVar1 != 0) {
    Ordinal_1064(&local_98,-local_98,-local_94);
    local_153c = Ordinal_1111(0x18c,1);
    if (local_153c != 0) {
      puVar2 = (uint *)Ordinal_1114(local_153c);
      local_1538 = puVar2;
      if (puVar2 != (uint *)0x0) {
        Ordinal_1128(puVar2,param_1,0x18c);
        piVar6 = local_154c;
        local_1520 = local_154c;
        Ordinal_1130(local_154c,0xe8);
        piVar3 = (int *)rendering_createSprite(local_1518,piVar6,0);
        if (piVar3 == (int *)0x0) {
          local_1520 = piVar3;
        }
        else {
          iVar1 = playback_dispatchLifecycle(puVar2,(uint)piVar6);
          if (iVar1 != 0) {
            iVar1 = Ordinal_56(*(int *)(*(int *)(local_1518 + 4) + 0xc),param_1,local_1514);
            if ((iVar1 == 0) || (iVar1 = Ordinal_1314(local_14ec,local_88,0x80), iVar1 == 0)) {
              Ordinal_1202(local_88,"Director");
            }
            local_151c = Ordinal_2020(local_88);
            if (local_151c == 0) goto LAB_680e4ab9;
            iVar1 = Ordinal_2025(local_151c,&local_b0);
            if (iVar1 != 0) {
              local_156c = 0;
              local_1568 = 0;
              if ((param_4 != 0x19) && (param_4 != 0x32)) {
                param_4 = 100;
              }
              iVar1 = (((local_90 * local_a8) / 0x48) * param_4) / 100;
              iVar5 = (((local_8c * local_a4) / 0x48) * param_4) / 100;
              if (local_b0 <= iVar1) {
                iVar5 = ((local_b0 + -1) * iVar5) / iVar1;
                iVar1 = local_b0 + -1;
              }
              iVar7 = iVar5;
              if (local_ac <= iVar5) {
                iVar7 = local_ac + -1;
                iVar1 = (iVar7 * iVar1) / iVar5;
              }
              local_152c = (local_b0 + -0x12) / (iVar1 + 0x12);
              local_1540 = (local_ac + -0x12) / (iVar7 + 0x12);
              local_1524 = local_1540 + -1;
              if (local_152c < 2) {
                local_1534 = local_b0 - iVar1 >> 1;
                local_152c = 1;
              }
              else {
                local_1528 = local_152c * iVar1;
                local_1534 = (local_b0 - local_1528) / (local_152c + 1);
                local_1558 = local_1534 + iVar1;
              }
              if (local_1524 < 2) {
                local_1524 = 1;
                local_1540 = 0x12;
                local_1544 = 0;
              }
              else {
                local_1540 = (local_ac - local_1524 * iVar7) / local_1540;
                local_1544 = local_1540 + iVar7;
              }
              iVar5 = local_1524;
              if (param_3 == 0) {
                param_3 = 0;
              }
              local_1518 = param_2;
              iVar4 = playback_setFrameRange((byte *)local_1538,&local_98,0);
              if (iVar4 != 0) {
                local_155c = local_1540 + iVar7;
                local_1554 = iVar1;
                do {
                  local_1560 = local_155c;
                  local_1528 = 0;
                  if (0 < iVar5) {
                    local_1550 = local_1554 + local_1534;
                    iVar1 = local_1540;
                    do {
                      local_1548 = 0;
                      iVar5 = local_1534;
                      iVar7 = local_1550;
                      if (0 < local_152c) {
                        do {
                          iVar4 = playback_setLifecycleFlags((byte *)local_1538,local_1518);
                          if (iVar4 == 0) goto LAB_680e4aa4;
                          rendering_setStageSize((int *)local_1538,(int)local_1520);
                          iVar4 = Ordinal_2023(local_151c,local_1520[0x25],iVar5,iVar1,iVar7,
                                               local_1560);
                          if ((iVar4 == 0) ||
                             (iVar4 = Ordinal_2024(local_151c,iVar5,iVar1,iVar7,local_1560),
                             iVar4 == 0)) goto LAB_680e4aa4;
                          local_1518 = local_1518 + 1;
                          if (param_3 < local_1518) {
                            local_1530 = 1;
                            goto LAB_680e4aa4;
                          }
                          iVar5 = iVar5 + local_1558;
                          iVar7 = iVar7 + local_1558;
                          local_1548 = local_1548 + 1;
                        } while (local_1548 < local_152c);
                      }
                      local_1560 = local_1560 + local_1544;
                      iVar1 = iVar1 + local_1544;
                      local_1528 = local_1528 + 1;
                      iVar5 = local_1524;
                    } while (local_1528 < local_1524);
                  }
                  iVar1 = Ordinal_2022(local_151c);
                } while (iVar1 != 0);
              }
            }
          }
        }
      }
    }
  }
LAB_680e4aa4:
  if (local_151c != 0) {
    Ordinal_2021(&local_151c);
  }
LAB_680e4ab9:
  if (local_1520 != (int *)0x0) {
    rendering_getStageState((int)local_1520);
  }
  piVar6 = local_1654;
  piVar3 = local_154c;
  for (iVar1 = 0x3a; iVar1 != 0; iVar1 = iVar1 + -1) {
    *piVar3 = *piVar6;
    piVar6 = piVar6 + 1;
    piVar3 = piVar3 + 1;
  }
  if (local_153c != 0) {
    Ordinal_1115(local_153c);
    Ordinal_1113(&local_153c);
  }
  return 0;
}



// ============================================================
// Function: bitmap_initExportPath (FUN_680e4b20)
// Address: 680e4b20
// Size: 89 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_initExportPath(undefined4 *param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 == (undefined4 *)0x0) {
    Ordinal_1309(&DAT_681964b0,0x400,"",2);
    DAT_681964ac = param_1;
    DAT_681968d4 = param_1;
    return 0;
  }
  puVar2 = &DAT_681964b0;
  for (iVar1 = 0x106; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_1;
    param_1 = param_1 + 1;
    puVar2 = puVar2 + 1;
  }
  DAT_681964ac = (undefined4 *)0x1;
  DAT_681968d4 = (undefined4 *)0x0;
  return 0;
}



// ============================================================
// Function: bitmap_cleanupExportState (FUN_680e4b80)
// Address: 680e4b80
// Size: 50 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_cleanupExportState(void)
{
  if (DAT_681968c8 != 0) {
    Ordinal_1407(&DAT_681968c8);
  }
  DAT_681968cc = 0;
  DAT_681964ac = 0;
  DAT_681968d4 = 0;
  return 0;
}



// ============================================================
// Function: bitmap_getExportPath (FUN_680e4bc0)
// Address: 680e4bc0
// Size: 26 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getExportPath(undefined4 *param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_681964b0;
  for (iVar1 = 0x106; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_1 = *puVar2;
    puVar2 = puVar2 + 1;
    param_1 = param_1 + 1;
  }
  return 0;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: bitmap_setTraceLevel (FUN_680e4bf0)
// Address: 680e4bf0
// Size: 38 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_setTraceLevel(int param_1)
{
  if ((DAT_681964a8 == 0) || (param_1 == 0)) {
    DAT_681968d4 = 0;
  }
  DAT_681964a8 = param_1;
  return 0;
}



// ============================================================
// Function: bitmap_importData (FUN_680e4c20)
// Address: 680e4c20
// Size: 53 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_importData(int *param_1)
{
  undefined4 *puVar1;
  
  if (DAT_681968c8 != 0) {
    Ordinal_1201();
    Ordinal_1420(DAT_681968c8);
  }
  puVar1 = (undefined4 *)media_getDataPtr(param_1);
  if ((code *)*puVar1 != (code *)0x0) {
    (*(code *)*puVar1)();
  }
  return 0;
}



// ============================================================
// Function: bitmap_exportData (FUN_680e4c60)
// Address: 680e4c60
// Size: 65 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_exportData(int *param_1)
{
  undefined4 uVar1;
  undefined4 *puVar2;
  
  if (DAT_681968c8 != 0) {
    uVar1 = Ordinal_1201(&DAT_6817cec0);
    Ordinal_1420(DAT_681968c8,&DAT_6817cec0,uVar1);
  }
  puVar2 = (undefined4 *)media_getDataPtr(param_1);
  if ((code *)*puVar2 != (code *)0x0) {
    (*(code *)*puVar2)(&DAT_6817c158);
  }
  return 0;
}



// ============================================================
// Function: bitmap_openTraceLog (FUN_680e4cb0)
// Address: 680e4cb0
// Size: 28 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_openTraceLog(void)
{
  Ordinal_1401(&DAT_681968c8,&DAT_681964b0,7);
  DAT_681968cc = 1;
  return 0;
}



// ============================================================
// Function: bitmap_recordFilePos (FUN_680e4cd0)
// Address: 680e4cd0
// Size: 82 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_recordFilePos(int param_1,int *param_2)
{
  int iVar1;
  
  if ((((1 < DAT_681964a8) && (DAT_681968d0 = 0, param_2 != (int *)0x0)) && (param_1 != 0)) &&
     (((iVar1 = rendering_getFrameCount((int)param_2), iVar1 == 0 &&
       (iVar1 = rendering_validateState(param_2), iVar1 != 0)) && (*(int *)(iVar1 + 4) != 0)))) {
    DAT_681968d0 = crt_streamGetPos(*(int *)(*(int *)(iVar1 + 4) + 4));
  }
  return 0;
}



// ============================================================
// Function: bitmap_writeTraceEntry (FUN_680e4d30)
// Address: 680e4d30
// Size: 1771 bytes
// Params: byte * param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int bitmap_writeTraceEntry(byte *param_1,int *param_2,undefined4 param_3)
{
  short sVar1;
  int *piVar2;
  short sVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  short extraout_var;
  int iVar7;
  int *piVar8;
  undefined4 *puVar9;
  undefined4 *puVar10;
  undefined8 uVar11;
  char *pcVar12;
  int local_a5c;
  undefined4 *local_a58;
  int *local_a54;
  int local_a50;
  int local_a4c;
  byte *local_a48;
  undefined4 local_a44;
  undefined1 local_a40 [1044];
  undefined1 local_62c [36];
  char local_608 [1024];
  undefined1 local_208 [256];
  undefined1 local_108 [256];
  uint local_8;
  
  local_a48 = param_1;
  local_a54 = param_2;
  local_a58 = (undefined4 *)0x0;
  if ((DAT_681964a8 == 0) || ((param_2 == (int *)0x0 && (param_1 == (byte *)0x0))))
  goto LAB_680e5409;
  iVar4 = Ordinal_1042();
  if (param_2 == (int *)0x0) {
    piVar8 = *(int **)(*(int *)(param_1 + 0x18) + 4);
  }
  else {
    piVar8 = *(int **)(*param_2 + 4);
  }
  if (((DAT_681968c8 == 0) && (DAT_681968cc == 0)) && (DAT_681964ac != 0)) {
    bitmap_openTraceLog();
  }
  if (DAT_681968d4 == 0) {
    bitmap_exportData(piVar8);
    Ordinal_1219(local_208,"Director TraceLog output started: ");
    bitmap_importData(piVar8);
    uVar11 = Ordinal_1542();
    Ordinal_1543(local_62c,uVar11);
    Ordinal_1256(local_208,0x100,local_62c,0);
    bitmap_importData(piVar8);
    Ordinal_1219(local_208,&DAT_6817d158);
    bitmap_importData(piVar8);
    Ordinal_1257(local_208,0x100,local_62c,1);
    bitmap_importData(piVar8);
    bitmap_exportData(piVar8);
    Ordinal_1219(local_208,"---------------------------------");
    bitmap_importData(piVar8);
    bitmap_exportData(piVar8);
    DAT_681968d4 = Ordinal_1541();
    param_1 = local_a48;
  }
  if ((param_1 != (byte *)0x0) && (1 < DAT_681964a8)) {
    iVar5 = Ordinal_1541();
    iVar5 = iVar5 - DAT_681968d4;
    iVar7 = iVar5 - _DAT_681968dc;
    _DAT_681968dc = iVar5;
    Ordinal_1219(local_108,"Time = %lu msec (%lu msec later).",iVar5,iVar7);
    bitmap_importData(piVar8);
    bitmap_exportData(piVar8);
    Ordinal_1314(*(int *)(local_a48 + 0x20) + 0x28,local_608 + 1,0x3ff);
    iVar5 = Ordinal_1201(local_608 + 1);
    do {
      iVar7 = iVar5;
      if (iVar7 + -1 < 1) goto LAB_680e4f1b;
      iVar5 = iVar7 + -1;
    } while (local_608[iVar7] != '.');
    local_608[iVar7] = '\0';
LAB_680e4f1b:
    iVar7 = Ordinal_1107();
    iVar5 = iVar7;
    uVar6 = playback_getCurrentFrame(local_a48);
    Ordinal_1219(local_108,"Movie \"%s\" is on frame %ld (freeBytes = %ld",local_608 + 1,uVar6,iVar5
                );
    bitmap_importData(piVar8);
    if (DAT_681968d8 != 0) {
      iVar5 = iVar7 - DAT_681968d8;
      if (iVar5 < 0) {
        Ordinal_1219(local_108,", %ld bytes consumed).",-iVar5);
      }
      else if (iVar5 < 1) {
        Ordinal_1219(local_108,", unchanged).");
      }
      else {
        Ordinal_1219(local_108,", %ld bytes released).",iVar5);
      }
    }
    bitmap_importData(piVar8);
    DAT_681968d8 = iVar7;
    bitmap_exportData(piVar8);
    param_1 = local_a48;
    param_2 = local_a54;
  }
  if (param_2 == (int *)0x0) {
LAB_680e50db:
    if ((param_1 != (byte *)0x0) && (1 < DAT_681964a8)) {
      local_a44 = 0;
      memset(local_a40,0,0x414);
      local_a50 = 0;
      local_a5c = 0;
      local_a4c = 0;
      Ordinal_1219(local_108,"Member is in ");
      bitmap_importData(piVar8);
      piVar2 = local_a54;
      iVar5 = rendering_getFrameCount((int)local_a54);
      if (iVar5 == 0) {
        iVar5 = rendering_getChannelState(piVar2);
        if (*(int *)(iVar5 + 0x14) == 0) {
          Ordinal_1219(local_108,"external castLib ");
          puVar9 = (undefined4 *)**(undefined4 **)(iVar5 + 0x30);
        }
        else {
          Ordinal_1219(local_108,"movie ");
          puVar9 = (undefined4 *)(*(int *)(local_a48 + 0x20) + 0x28);
        }
        puVar10 = &local_a44;
        for (iVar5 = 0x106; iVar5 != 0; iVar5 = iVar5 + -1) {
          *puVar10 = *puVar9;
          puVar9 = puVar9 + 1;
          puVar10 = puVar10 + 1;
        }
        local_a50 = rendering_validateState(local_a54);
        iVar5 = local_a4c;
        if (local_a50 != 0) {
          iVar5 = *(int *)(local_a50 + 4);
          local_a4c = iVar5;
        }
      }
      else {
        Ordinal_1219(local_108,"linked file ");
        rendering_dispatchUpdate(*(int *)(local_a48 + 0x20),piVar2,&local_a44,0);
        iVar5 = 0;
      }
      bitmap_importData(piVar8);
      Ordinal_1310(&local_a44,local_608 + 1,0x3ff);
      Ordinal_1219(local_108,"\"%s\" ",local_608 + 1);
      bitmap_importData(piVar8);
      if ((local_a50 != 0) && (iVar7 = Ordinal_1313(&local_a44), iVar7 == 4)) {
        local_a4c = 0;
        local_a48 = (byte *)0x0;
        crt_streamReadAt(*(int *)(iVar5 + 4),&local_a4c);
        crt_getStreamSize(*(int *)(iVar5 + 4),&local_a48);
        Ordinal_1219(local_108,"(Downloaded %ld out of %ld bytes)",local_a48,local_a4c);
        bitmap_importData(piVar8);
      }
      bitmap_exportData(piVar8);
      Ordinal_1219(local_108,"File seek info: ");
      bitmap_importData(piVar8);
      if ((local_a50 == 0) || (local_a50 != DAT_681968e0)) {
        Ordinal_1219(local_108,"Seeked between files!  ",local_608 + 1);
        bitmap_importData(piVar8);
      }
      piVar2 = local_a54;
      if (local_a50 != 0) {
        local_a4c = 0;
        iVar7 = rendering_getMemberProperty(local_a54,0,(int *)&local_a58);
        if (0 < iVar7) {
          iVar7 = strings_openMediaStream(iVar5,*(int *)*local_a58,piVar2[3]);
          local_a5c = crt_getSlotOffset(iVar5,iVar7);
        }
        iVar7 = crt_streamGetPos(*(int *)(iVar5 + 4));
        iVar5 = iVar7 - local_a5c;
        if (iVar7 - local_a5c < 1) {
          iVar5 = local_a4c;
        }
        if (iVar7 == DAT_681968d0) {
          Ordinal_1219(local_108,"No file access occurred.");
        }
        else {
          Ordinal_1219(local_108,"Seeked %ld to find member at file pos %ld.  Read in %ld bytes.",
                       local_a5c - DAT_681968d0,local_a5c,iVar5);
        }
        bitmap_importData(piVar8);
      }
      DAT_681968e0 = local_a50;
      bitmap_exportData(piVar8);
      bitmap_exportData(piVar8);
    }
  }
  else if (param_1 != (byte *)0x0) {
    sVar3 = scoreEngine_getChannelCount(*(int *)(param_1 + 0x20),(short)param_2[1]);
    if (sVar3 == 0) {
      sVar3 = (short)param_2[1];
      sVar1 = *(short *)((int)param_2 + 6);
      pcVar12 = "member %ld of \'floating\' castLib %ld ";
    }
    else {
      pcVar12 = "member %ld of castLib %ld ";
      sVar1 = extraout_var;
    }
    Ordinal_1219(local_108,pcVar12,(int)sVar1,(int)sVar3);
    bitmap_importData(piVar8);
    iVar5 = Ordinal_38(param_2[0x13],1,local_608,0x3ff);
    if (iVar5 != 0) {
      iVar5 = iVar5 + -1;
    }
    local_608[iVar5 + 1] = '\0';
    local_608[0] = (char)iVar5;
    if (0xfe < iVar5) {
      local_608[0] = -1;
    }
    if (0 < iVar5) {
      Ordinal_1219(local_108,"(\"%s\") ",local_608 + 1);
      bitmap_importData(piVar8);
    }
    switch(param_3) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    default:
      goto switchD_680e50a1_default;
    }
    bitmap_importData(piVar8);
switchD_680e50a1_default:
    bitmap_exportData(piVar8);
    param_1 = local_a48;
    goto LAB_680e50db;
  }
  Ordinal_1113(&local_a58);
  Ordinal_1408(DAT_681968c8);
  Ordinal_1042();
  if (iVar4 != 0) {
    Ordinal_1040(iVar4);
  }
LAB_680e5409:
  return 0;
}



// ============================================================
// Function: bitmap_logString (FUN_680e5430)
// Address: 680e5430
// Size: 82 bytes
// Params: int * param_1, char * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_logString(int *param_1,char *param_2)
{
  int iVar1;
  
  iVar1 = Ordinal_1042();
  if (((DAT_681968c8 == 0) && (DAT_681968cc == 0)) && (DAT_681964ac != 0)) {
    bitmap_openTraceLog();
  }
  if (*param_2 != '\0') {
    bitmap_importData(param_1);
  }
  Ordinal_1042();
  if (iVar1 != 0) {
    Ordinal_1040(iVar1);
  }
  return 0;
}



// ============================================================
// Function: bitmap_readScoreHeader (FUN_680e5490)
// Address: 680e5490
// Size: 845 bytes
// Params: int * param_1, undefined2 * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
bitmap_readScoreHeader(int *param_1,undefined2 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined1 uVar1;
  undefined2 uVar2;
  short sVar3;
  undefined4 uVar4;
  
  Ordinal_1130(param_2,100);
  uVar2 = Ordinal_1412(param_3);
  *param_2 = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[1] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[2] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[3] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[4] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[5] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[6] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[7] = uVar2;
  uVar1 = Ordinal_1410(param_3);
  *(undefined1 *)(param_2 + 8) = uVar1;
  if ((short)param_2[1] < 0x4c8) {
    *(undefined1 *)(param_2 + 8) = 1;
  }
  uVar1 = Ordinal_1410(param_3);
  *(undefined1 *)((int)param_2 + 0x11) = uVar1;
  if ((short)param_2[1] < 0x4c8) {
    *(undefined1 *)((int)param_2 + 0x11) = 0;
  }
  uVar1 = Ordinal_1410(param_3);
  *(undefined1 *)(param_2 + 9) = uVar1;
  uVar1 = Ordinal_1410(param_3);
  *(undefined1 *)((int)param_2 + 0x13) = uVar1;
  if ((short)param_2[1] < 0x4c8) {
    param_2[9] = 0;
  }
  uVar2 = Ordinal_1412(param_3);
  param_2[10] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[0xb] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[0xc] = uVar2;
  if ((short)param_2[1] < 0x4c7) {
    param_2[0xc] = 0;
  }
  uVar1 = Ordinal_1410(param_3);
  *(undefined1 *)(param_2 + 0xd) = uVar1;
  uVar1 = Ordinal_1410(param_3);
  *(undefined1 *)((int)param_2 + 0x1b) = uVar1;
  uVar2 = Ordinal_1412(param_3);
  param_2[0xe] = uVar2;
  uVar1 = Ordinal_1411(param_3);
  *(undefined1 *)(param_2 + 0xf) = uVar1;
  if ((short)param_2[1] < 0x582) {
    *(undefined1 *)(param_2 + 0xf) = 0xfe;
  }
  uVar1 = Ordinal_1410(param_3);
  *(undefined1 *)((int)param_2 + 0x1f) = uVar1;
  uVar4 = Ordinal_1414(param_3);
  *(undefined4 *)(param_2 + 0x10) = uVar4;
  uVar2 = Ordinal_1412(param_3);
  param_2[0x12] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[0x13] = uVar2;
  uVar4 = Ordinal_1414(param_3);
  *(undefined4 *)(param_2 + 0x14) = uVar4;
  if ((short)param_2[1] < 0x6a4) {
    *(undefined4 *)(param_2 + 0x14) = 0;
  }
  uVar4 = Ordinal_1414(param_3);
  *(undefined4 *)(param_2 + 0x16) = uVar4;
  if ((short)param_2[1] < 0x73b) {
    *(undefined4 *)(param_2 + 0x16) = 1;
  }
  uVar4 = Ordinal_1414(param_3);
  *(undefined4 *)(param_2 + 0x18) = uVar4;
  if ((short)param_2[1] < 0x4c8) {
    *(undefined4 *)(param_2 + 0x18) = 0;
  }
  uVar1 = Ordinal_1410(param_3);
  *(undefined1 *)(param_2 + 0x1a) = uVar1;
  if ((short)param_2[1] < 0x743) {
    *(undefined1 *)(param_2 + 0x1a) = 0;
  }
  uVar1 = Ordinal_1410(param_3);
  *(undefined1 *)((int)param_2 + 0x35) = uVar1;
  if ((short)param_2[1] < 0x4c8) {
    *(undefined1 *)((int)param_2 + 0x35) = 0x50;
  }
  uVar2 = Ordinal_1412(param_3);
  param_2[0x1b] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[0x1c] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[0x1d] = uVar2;
  uVar4 = Ordinal_1414(param_3);
  *(undefined4 *)(param_2 + 0x1e) = uVar4;
  uVar4 = Ordinal_1414(param_3);
  *(undefined4 *)(param_2 + 0x20) = uVar4;
  uVar2 = Ordinal_1412(param_3);
  param_2[0x22] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[0x23] = uVar2;
  uVar4 = Ordinal_1414(param_3);
  *(undefined4 *)(param_2 + 0x24) = uVar4;
  if ((short)param_2[1] < 0x4c1) {
    *(undefined4 *)(param_2 + 0x24) = 0x400;
  }
  uVar2 = Ordinal_1412(param_3);
  param_2[0x26] = uVar2;
  uVar2 = Ordinal_1412(param_3);
  param_2[0x27] = uVar2;
  if ((short)param_2[0x12] < 0x579) {
    sVar3 = Ordinal_1412();
    if (sVar3 == 1) {
      param_2[0x28] = 0;
    }
    else if (sVar3 == 2) {
      param_2[0x28] = 0x100;
    }
    else {
      param_2[0x28] = 1;
    }
  }
  else {
    uVar1 = Ordinal_1410(param_3);
    *(undefined1 *)(param_2 + 0x28) = uVar1;
    uVar1 = Ordinal_1410(param_3);
    *(undefined1 *)((int)param_2 + 0x51) = uVar1;
  }
  uVar2 = Ordinal_1412(param_3);
  param_2[0x29] = uVar2;
  if ((short)param_2[1] < 0x73b) {
    *(undefined4 *)(param_2 + 0x2a) = 0x5a;
    uVar2 = Ordinal_1412();
    param_2[0x2c] = uVar2;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x2d] = uVar2;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x2e] = uVar2;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x2f] = uVar2;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x2e] = uVar2;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x2f] = uVar2;
  }
  else {
    uVar4 = Ordinal_1414(param_3);
    *(undefined4 *)(param_2 + 0x2a) = uVar4;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x2c] = uVar2;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x2d] = uVar2;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x2e] = uVar2;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x2f] = uVar2;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x30] = uVar2;
    uVar2 = Ordinal_1412(param_3);
    param_2[0x31] = uVar2;
  }
  if ((short)param_2[0x12] < 0x45e) {
    param_2[0x26] = 0xffff;
    param_2[0x27] = param_2[0x23];
  }
  if (0x7b6 < (short)param_2[0x12]) {
    lingo_callMethodEx(param_1,-0x70,param_5);
  }
  Ordinal_1042();
  return 1;
}



// ============================================================
// Function: bitmap_writeScoreHeader (FUN_680e57e0)
// Address: 680e57e0
// Size: 565 bytes
// Params: undefined4 * param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_writeScoreHeader(undefined4 *param_1)

{
  int param_4;
  int iVar1;
  int unaff_ESI;
  
  if (unaff_ESI != 0) {
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1421();
    Ordinal_1421();
    Ordinal_1421();
    Ordinal_1421();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1421();
    Ordinal_1421();
    Ordinal_1423();
    Ordinal_1422();
    Ordinal_1421();
    Ordinal_1425();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1425();
    Ordinal_1425();
    Ordinal_1425();
    Ordinal_1421();
    Ordinal_1421();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1425();
    Ordinal_1425();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1425();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1421();
    Ordinal_1421();
    Ordinal_1423();
    Ordinal_1425();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
    Ordinal_1423();
  }
  iVar1 = Ordinal_1042();
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 100;
  }
  return iVar1 == 0;
}



// ============================================================
// Function: bitmap_writeScoreHeaderEx (FUN_680e5a20)
// Address: 680e5a20
// Size: 32 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_writeScoreHeaderEx(undefined4 param_1,undefined4 param_2,undefined4 *param_3)
{
  bitmap_writeScoreHeader(param_3);
  return 0;
}



// ============================================================
// Function: bitmap_writeScoreHeaderAlt (FUN_680e5a40)
// Address: 680e5a40
// Size: 29 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_writeScoreHeaderAlt(void)
{
  undefined4 *in_stack_00000010;
  
  bitmap_writeScoreHeader(in_stack_00000010);
  return 0;
}



// ============================================================
// Function: bitmap_readScoreData (FUN_680e5a60)
// Address: 680e5a60
// Size: 97 bytes
// Params: int * param_1, undefined4 param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readScoreData(int *param_1,undefined4 param_2,uint param_3)

{
  uint *puVar1;
  undefined2 uVar2;
  int *piVar3;
  void *this;
  int iVar4;
  
  piVar3 = media_loadScoreResource(param_2,param_3,param_1,0,(short *)0x0);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  puVar1 = (uint *)*param_1;
  iVar4 = 1;
  uVar2 = scoreEngine_getChannelFlags((int)param_1);
  iVar4 = playback_goToFrame(this,puVar1,(int)piVar3,uVar2,iVar4);
  if (iVar4 != 0) {
    iVar4 = Ordinal_1042();
    if (iVar4 != 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_applyScoreLayout (FUN_680e5ad0)
// Address: 680e5ad0
// Size: 181 bytes
// Params: int * param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_applyScoreLayout(int *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_8;
  
  iVar1 = *param_1;
  iVar5 = 0;
  local_8 = 1;
  piVar2 = (int *)media_getVtableFunc(*(int **)(iVar1 + 0x28));
  if (piVar2 != (int *)0x0) {
    iVar3 = playback_getLifecycleState(iVar1);
    if (iVar3 == 0) {
      local_8 = media_getScoreState(*(int **)(iVar1 + 0x28));
      iVar5 = media_getScoreLayoutData(piVar2);
    }
    uVar4 = media_mergeScoreEntries(piVar2,param_2,param_3,param_1,0);
    if (iVar5 != 0) {
      media_getPlaybackByte(*(int *)(iVar1 + 0x28),(int)piVar2,param_1[0x140],1);
      playback_resetScoreSlots(iVar1);
      media_readPlaybackData(*(int *)(iVar1 + 0x28),local_8,0);
      media_getScoreReadState(*(int **)(iVar1 + 0x28),0xf);
    }
    Ordinal_1042();
    return uVar4;
  }
  return 0;
}



// ============================================================
// Function: bitmap_readPaletteMap (FUN_680e5b90)
// Address: 680e5b90
// Size: 258 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readPaletteMap(int param_1,undefined4 param_2,int param_3)

{
  short sVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  uint uVar6;
  undefined4 local_8;
  
  piVar5 = (int *)(param_1 + 0x480);
  if (*piVar5 != 0) {
    Ordinal_1163(piVar5);
  }
  Ordinal_1432(param_2,0x14,1);
  uVar6 = param_3 - 0x14;
  iVar3 = Ordinal_1150(uVar6 >> 2,10,4);
  *piVar5 = iVar3;
  if (iVar3 == 0) {
LAB_680e5c73:
    lingo_formatDebugMsg(*(int **)(*(int *)(param_1 + 4) + 8),-0x7a);
  }
  else {
    uVar4 = rendering_updateChannelState(param_1 + 0x48c);
    if (uVar4 < 0x500) {
      local_8 = CONCAT22((*(unsigned short *)((char *)&local_8 + 2)),1);
      for (; 0 < (int)uVar6; uVar6 = uVar6 - 2) {
        sVar1 = Ordinal_1412(param_2);
        local_8 = CONCAT22(sVar1,(undefined2)local_8);
        if ((0 < sVar1) && (iVar3 = Ordinal_1152(*piVar5,&local_8), iVar3 == 0)) goto LAB_680e5c73;
      }
    }
    else {
      for (; 0 < (int)uVar6; uVar6 = uVar6 - 4) {
        uVar2 = Ordinal_1412(param_2);
        local_8 = CONCAT22((*(unsigned short *)((char *)&local_8 + 2)),uVar2);
        sVar1 = Ordinal_1412(param_2);
        local_8 = CONCAT22(sVar1,(undefined2)local_8);
        if ((0 < sVar1) && (iVar3 = Ordinal_1152(*piVar5,&local_8), iVar3 == 0)) goto LAB_680e5c73;
      }
    }
    iVar3 = Ordinal_1042();
    if (iVar3 == 0) {
      return 1;
    }
  }
  return 0;
}



