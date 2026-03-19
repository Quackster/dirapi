// Module: bitmap
// Topic: Cast library serialization, format conversion, cast member data I/O, initialization
// Address range: 0x680e5ca0 - 0x680e7500
// Functions (21):
//   bitmap_writePaletteData
//   bitmap_readMemberBuffer
//   bitmap_writeMemberBuffer
//   bitmap_readRegPoints
//   bitmap_writeRegPoints
//   bitmap_readCastFlags
//   bitmap_readCastStreams
//   bitmap_writeCastFlags
//   bitmap_createCastEntry
//   bitmap_updateFileExtension
//   bitmap_resolvePathData
//   bitmap_importCastMembers
//   bitmap_processFontMapping
//   bitmap_writeCastLibData
//   bitmap_openLinkedCastLib
//   bitmap_writeChannelScore
//   bitmap_openCastInfo
//   bitmap_writeLinkedFileData
//   bitmap_initCastLib
//   bitmap_registerCastLib
//   bitmap_destroyCastLib

// ============================================================
// Function: bitmap_writePaletteData (FUN_680e5ca0)
// Address: 680e5ca0
// Size: 228 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_writePaletteData(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined2 local_14;
  undefined2 uStack_12;
  undefined2 uStack_10;
  undefined4 local_c;
  int local_8;
  
  iVar3 = 0;
  local_c = 0;
  local_8 = 0;
  if (*(int *)(param_1 + 0x480) != 0) {
    iVar1 = Ordinal_1154(*(int *)(param_1 + 0x480));
    if (param_2 != 0) {
      Ordinal_1425(param_2,0);
      Ordinal_1425(param_2,0);
      Ordinal_1425(param_2,iVar1);
      Ordinal_1425(param_2,iVar1);
      Ordinal_1423(param_2,0x14);
      Ordinal_1423(param_2,4);
    }
    local_8 = 0x14;
    if (iVar1 != 0) {
      do {
        Ordinal_1155(*(undefined4 *)(param_1 + 0x480),iVar3,&local_14);
        uVar2 = rendering_updateChannelState(param_1 + 0x48c);
        if (0x4ff < uVar2) {
          if (param_2 != 0) {
            Ordinal_1423(param_2,CONCAT22(uStack_12,local_14));
          }
          local_8 = local_8 + 2;
        }
        if (param_2 != 0) {
          Ordinal_1423(param_2,CONCAT22(uStack_10,uStack_12));
        }
        local_8 = local_8 + 2;
        iVar3 = iVar3 + 1;
      } while (iVar3 != iVar1);
    }
    iVar3 = Ordinal_1042();
    if (iVar3 == 0) {
      local_c = 1;
    }
  }
  if (param_3 != (int *)0x0) {
    *param_3 = local_8;
  }
  return local_c;
}



// ============================================================
// Function: bitmap_readMemberBuffer (FUN_680e5d90)
// Address: 680e5d90
// Size: 117 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readMemberBuffer(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar4 = *param_1;
  iVar1 = Ordinal_1439(param_2,param_3,0);
  if ((iVar1 != 0) && (*(int *)(iVar4 + 0x128) == 0)) {
    *(int *)(iVar4 + 0x128) = iVar1;
    puVar2 = (undefined4 *)Ordinal_1114(iVar1);
    if (param_3 != 0) {
      iVar1 = (param_3 - 1U >> 2) + 1;
      do {
        uVar3 = xtra_readBE32Ptr((undefined1 *)puVar2);
        *puVar2 = uVar3;
        puVar2 = puVar2 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    Ordinal_1115(*(undefined4 *)(iVar4 + 0x128));
  }
  iVar4 = Ordinal_1042();
  if (iVar4 == 0) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_writeMemberBuffer (FUN_680e5e10)
// Address: 680e5e10
// Size: 142 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_writeMemberBuffer(int *param_1,int param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_1;
  iVar4 = 0;
  if (*(int *)(iVar3 + 0x128) != 0) {
    puVar1 = (undefined4 *)Ordinal_1114(*(int *)(iVar3 + 0x128));
    iVar2 = Ordinal_1116(*(undefined4 *)(iVar3 + 0x128));
    if (0 < iVar2) {
      iVar2 = (iVar2 - 1U >> 2) + 1;
      iVar4 = iVar2 * 4;
      do {
        if (param_2 != 0) {
          Ordinal_1425(param_2,*puVar1);
        }
        puVar1 = puVar1 + 1;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    Ordinal_1115(*(undefined4 *)(iVar3 + 0x128));
  }
  iVar3 = Ordinal_1042();
  if (param_3 != (int *)0x0) {
    *param_3 = iVar4;
  }
  return iVar3 == 0;
}



// ============================================================
// Function: bitmap_readRegPoints (FUN_680e5ea0)
// Address: 680e5ea0
// Size: 268 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_readRegPoints(int param_1,undefined4 param_2,uint param_3)
{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  char cVar7;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  cVar7 = '\0';
  do {
    if (param_3 < 0xe) break;
    Ordinal_1414(param_2);
    uVar5 = rendering_updateChannelState(param_1 + 0x48c);
    if (uVar5 < 0x500) {
      uVar2 = 1;
    }
    else {
      uVar2 = Ordinal_1412(param_2);
    }
    uVar3 = Ordinal_1412(param_2);
    local_1c = CONCAT22(uVar3,uVar2);
    sVar4 = Ordinal_1412(param_2);
    local_14 = (int)sVar4;
    sVar4 = Ordinal_1412(param_2);
    local_18 = (int)sVar4;
    sVar4 = Ordinal_1412(param_2);
    local_c = (int)sVar4;
    sVar4 = Ordinal_1412(param_2);
    local_10 = (int)sVar4;
    iVar6 = Ordinal_1062(&local_18);
    if (iVar6 == 0) {
      puVar1 = (undefined4 *)(param_1 + 0x530 + cVar7 * 0x14);
      *puVar1 = local_1c;
      puVar1[1] = local_18;
      puVar1[2] = local_14;
      puVar1[3] = local_10;
      puVar1[4] = local_c;
    }
    param_3 = param_3 - 0xe;
    cVar7 = cVar7 + '\x01';
  } while (cVar7 < '\b');
  *(char *)(param_1 + 0x5d0) = cVar7;
  iVar6 = Ordinal_1042();
  if (iVar6 == 0) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: bitmap_writeRegPoints (FUN_680e5fb0)
// Address: 680e5fb0
// Size: 174 bytes
// Params: int param_1, int param_2, int * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_writeRegPoints(int param_1,int param_2,int *param_3)

{
  int iVar1;
  undefined2 *puVar2;
  int local_8;
  
  iVar1 = 0;
  local_8 = 0;
  puVar2 = (undefined2 *)(param_1 + 0x532);
  do {
    if (*(char *)(param_1 + 0x5d0) <= iVar1) break;
    if (param_2 != 0) {
      Ordinal_1425(param_2,0);
      Ordinal_1423(param_2,puVar2[-1]);
      Ordinal_1423(param_2,*puVar2);
      Ordinal_1423(param_2,puVar2[3]);
      Ordinal_1423(param_2,puVar2[1]);
      Ordinal_1423(param_2,puVar2[7]);
      Ordinal_1423(param_2,puVar2[5]);
    }
    local_8 = local_8 + 0x10;
    iVar1 = iVar1 + 1;
    puVar2 = puVar2 + 10;
  } while (iVar1 < 8);
  iVar1 = Ordinal_1042();
  if (param_3 != (int *)0x0) {
    *param_3 = local_8;
  }
  return iVar1 == 0;
}



// ============================================================
// Function: bitmap_readCastFlags (FUN_680e6060)
// Address: 680e6060
// Size: 237 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readCastFlags(uint param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  ushort uVar4;
  int iVar5;
  
  uVar3 = param_1;
  piVar1 = (int *)(param_1 + 0x46c);
  Ordinal_1113(piVar1);
  iVar5 = cast_writeDataEntry(param_2,param_3,0);
  *piVar1 = iVar5;
  if (iVar5 != 0) {
    iVar5 = Ordinal_1114(iVar5);
    if ((*(byte *)(iVar5 + 0xc) & 0x40) != 0) {
      *(undefined4 *)(uVar3 + 0x664) = 1;
    }
    if ((*(uint *)(iVar5 + 0xc) & 0x100) != 0) {
      *(undefined4 *)(uVar3 + 0x66c) = 1;
    }
    if ((*(uint *)(iVar5 + 0xc) & 0x4000) != 0) {
      *(undefined4 *)(uVar3 + 0x688) = 1;
    }
    *(uint *)(uVar3 + 0x68c) = *(uint *)(iVar5 + 0xc) >> 0xf & 1;
    if ((*(uint *)(iVar5 + 0xc) & 0x1000) != 0) {
      iVar2 = *piVar1;
      *(undefined4 *)(uVar3 + 0x45c) = 1;
      Ordinal_38(iVar2,6,&param_1,2);
      uVar4 = xtra_readBE16((undefined1 *)&param_1);
      param_1 = (uint)uVar4;
      *(int *)(uVar3 + 0x464) = (int)(short)uVar4;
    }
    if ((0x73a < *(short *)(uVar3 + 0x4b0)) && (*(short *)(uVar3 + 0x4b0) < 0x742)) {
      *(uint *)(iVar5 + 0xc) = *(uint *)(iVar5 + 0xc) | 0x10000;
    }
    Ordinal_1115(*piVar1);
  }
  iVar5 = Ordinal_1042();
  if (iVar5 == 0) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_readCastStreams (FUN_680e6150)
// Address: 680e6150
// Size: 137 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_readCastStreams(int param_1)
{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  iVar2 = *(int *)(*(int *)(param_1 + 4) + 8);
  uVar3 = rendering_updateChannelState(param_1 + 0x48c);
  if (uVar3 < 0x1100) {
    iVar1 = param_1 + 0x50c;
    piVar4 = (int *)(param_1 + 0x46c);
    display_readStream(iVar2,piVar4,1,iVar1,1);
    display_readStream(iVar2,piVar4,2,iVar1,1);
    display_readStream(iVar2,piVar4,3,iVar1,1);
    display_readStream(iVar2,piVar4,7,iVar1,1);
    display_readStream(iVar2,piVar4,8,iVar1,1);
    display_readStream(iVar2,piVar4,9,iVar1,1);
    display_readStream(iVar2,piVar4,10,iVar1,1);
  }
  return 0;
}



// ============================================================
// Function: bitmap_writeCastFlags (FUN_680e61e0)
// Address: 680e61e0
// Size: 153 bytes
// Params: int param_1, int param_2, int * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_writeCastFlags(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if (*(int *)(param_1 + 0x46c) != 0) {
    iVar2 = Ordinal_1114(*(int *)(param_1 + 0x46c));
    if (*(int *)(param_1 + 0x664) == 1) {
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x40;
    }
    if (*(int *)(param_1 + 0x66c) == 1) {
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x100;
    }
    if (*(int *)(param_1 + 0x688) == 1) {
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x4000;
    }
    if (*(int *)(param_1 + 0x68c) == 1) {
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 0x8000;
    }
    iVar2 = cast_readDataEntry(*(int *)(param_1 + 0x46c),param_2,0);
    Ordinal_1115(*(undefined4 *)(param_1 + 0x46c));
  }
  iVar1 = Ordinal_1042();
  if (param_3 != (int *)0x0) {
    *param_3 = iVar2;
  }
  return iVar1 == 0;
}



// ============================================================
// Function: bitmap_createCastEntry (FUN_680e6280)
// Address: 680e6280
// Size: 65 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_createCastEntry(int param_1)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(param_1 + 0x46c);
  Ordinal_1113(piVar2);
  iVar1 = Ordinal_35(0x14);
  *piVar2 = iVar1;
  iVar1 = Ordinal_1114(iVar1);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0xc) = 0x10000;
  }
  Ordinal_1115(*piVar2);
  return *piVar2 != 0;
}



// ============================================================
// Function: bitmap_updateFileExtension (FUN_680e62d0)
// Address: 680e62d0
// Size: 249 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_updateFileExtension(int param_1,undefined4 param_2)
{
  short sVar1;
  int iVar2;
  undefined *puVar3;
  undefined1 *puVar4;
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar2 = crt_isMediaFormat(*(int **)(param_1 + 0x10));
  if (iVar2 == 0) {
    if (*(int *)(param_1 + 0x680) == 0) goto LAB_680e639c;
    puVar3 = &DAT_6817c724;
  }
  else {
    puVar3 = &DAT_6817c72c;
  }
  iVar2 = Ordinal_1314(param_2,local_408,0x3ff);
  if (iVar2 == 0) goto LAB_680e63b4;
  iVar2 = Ordinal_1201(local_408);
  puVar4 = local_408 + iVar2 + -4;
  sVar1 = Ordinal_1208(puVar4,&DAT_6817d180);
  if (sVar1 == 0) {
LAB_680e6375:
    *puVar4 = 0;
  }
  else {
    sVar1 = Ordinal_1208(puVar4,&DAT_6817c72c);
    if (sVar1 == 0) goto LAB_680e6375;
    sVar1 = Ordinal_1208(puVar4,&DAT_6817c724);
    if (sVar1 == 0) goto LAB_680e6375;
  }
  Ordinal_1204(local_408,puVar3);
  Ordinal_1316(param_2);
  iVar2 = Ordinal_1317(param_2,local_408);
  if (iVar2 != 0) {
LAB_680e639c:
    return 0;
  }
LAB_680e63b4:
  return 0;
}



// ============================================================
// Function: bitmap_resolvePathData (FUN_680e63d0)
// Address: 680e63d0
// Size: 260 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_resolvePathData(int param_1,int param_2,undefined4 *param_3)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_420 [262];
  uint local_8;
  
  iVar1 = *(int *)(param_1 + 4);
  puVar4 = param_3;
  puVar5 = local_420;
  for (iVar3 = 0x106; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  iVar1 = media_getDataPtr(*(int **)(*(int *)(iVar1 + 8) + 4));
  Ordinal_1326(local_420,0x400,param_3);
  bitmap_updateFileExtension(param_1,param_3);
  iVar3 = scoreEngine_writeChannelData(param_1,param_2,param_3,0x16,0,0,1);
  if (iVar3 == 0) {
    iVar3 = **(int **)(*(int *)(param_1 + 4) + 8);
    Ordinal_1326(param_3,0x400,local_420);
    uVar2 = (uint)(*(int *)(iVar1 + 0xa4) == 0);
    if ((*(uint *)(iVar3 + 0x1c) & 0x100) != 0) {
      uVar2 = 0;
    }
    iVar3 = scoreEngine_writeChannelData(param_1,param_2,param_3,0x16,uVar2,0,1);
    if ((iVar3 == 0) && (*(code **)(iVar1 + 0xa4) != (code *)0x0)) {
      (**(code **)(iVar1 + 0xa4))(*(undefined4 *)(*(int *)(param_1 + 4) + 4),param_3);
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_importCastMembers (FUN_680e64e0)
// Address: 680e64e0
// Size: 1558 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int bitmap_importCastMembers(int param_1,undefined4 param_2,int param_3)
{
  short sVar1;
  undefined2 uVar2;
  byte *pbVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined4 *puVar11;
  int *piVar12;
  undefined4 *puVar13;
  int *piVar14;
  int local_558;
  int local_554;
  undefined4 local_550;
  int local_54c;
  int local_548;
  short local_544 [2];
  int local_540;
  int local_53c;
  undefined4 local_538;
  undefined4 local_534;
  undefined4 local_530;
  undefined4 local_52c;
  int local_528;
  undefined4 local_524;
  int local_520;
  int local_51c;
  int local_518;
  int local_514;
  int *local_510;
  int *local_50c;
  int local_508;
  int local_504;
  int *local_500;
  int local_4fc [5];
  int local_4e8;
  int local_4e0;
  int local_4cc [2];
  undefined4 local_4c4;
  undefined4 local_4c0;
  undefined4 local_494 [3];
  undefined4 local_488;
  undefined2 local_45c;
  undefined4 local_420 [262];
  uint local_8;
  
  local_508 = param_1;
  local_51c = 0;
  local_500 = (int *)0x0;
  local_544[0] = 0;
  local_540 = 0;
  local_53c = 0;
  local_538 = 0;
  local_534 = 0;
  local_530 = 0;
  local_52c = 0;
  local_528 = 0;
  local_4fc[0] = 0;
  memset(local_4fc + 1,0,0xd8);
  local_504 = 0;
  local_510 = *(int **)(*(int *)(param_1 + 4) + 8);
  Ordinal_1130(local_544,0x20);
  local_500 = (int *)cast_writeDataEntry(param_2,param_3,1);
  if (local_500 != (int *)0x0) {
    iVar10 = (int)*(short *)(*local_500 + 8);
    local_548 = iVar10;
    local_518 = media_getDataPtr((int *)local_510[1]);
    local_514 = 0;
    if (0 < *(short *)(*local_500 + 6)) {
      do {
        iVar9 = local_514;
        local_520 = 0;
        Ordinal_1130(local_544,0x20);
        Ordinal_1130(local_4fc,0xdc);
        local_50c = (int *)0x0;
        local_528 = local_508;
        if ((0 < iVar10) &&
           (local_558 = cast_lookupDataEntry((int)local_500,iVar10 * iVar9 + 1,0), local_558 != 0)) {
          pbVar3 = (byte *)Ordinal_1114(local_558);
          if (*pbVar3 == 0xff) {
            uVar4 = Ordinal_1201(pbVar3 + 1);
          }
          else {
            uVar4 = (uint)*pbVar3;
          }
          local_540 = Ordinal_1111(uVar4 + 1,1);
          uVar5 = Ordinal_1114(local_540);
          Ordinal_1232(uVar5,pbVar3);
          Ordinal_1115(local_540);
          Ordinal_1113(&local_558);
        }
        if (1 < iVar10) {
          local_54c = cast_lookupDataEntry((int)local_500,iVar10 * iVar9 + 2,0);
          if (local_54c != 0) {
            pbVar3 = (byte *)Ordinal_1114(local_54c);
            if (*pbVar3 == 0xff) {
              uVar4 = Ordinal_1201(pbVar3 + 1);
            }
            else {
              uVar4 = (uint)*pbVar3;
            }
            if (uVar4 != 0) {
              if (*pbVar3 == 0xff) {
                uVar4 = Ordinal_1201(pbVar3 + 1);
              }
              else {
                uVar4 = (uint)*pbVar3;
              }
              local_504 = Ordinal_1111(uVar4 + 1,1);
              uVar5 = Ordinal_1114(local_504);
              Ordinal_1232(uVar5,pbVar3);
              Ordinal_1115(local_504);
            }
            Ordinal_1113(&local_54c);
          }
          if (local_504 == 0) {
            local_4e8 = 1;
            local_4e0 = local_508;
            puVar7 = (undefined4 *)(local_508 + 0x48c);
            puVar11 = local_494;
            for (iVar8 = 0x19; iVar9 = local_514, iVar8 != 0; iVar8 = iVar8 + -1) {
              *puVar11 = *puVar7;
              puVar7 = puVar7 + 1;
              puVar11 = puVar11 + 1;
            }
          }
          else {
            uVar5 = Ordinal_1114(local_504);
            local_4cc[0] = Ordinal_1111(0x418,1);
            if (local_4cc[0] == 0) {
              Ordinal_1115(local_504);
              goto LAB_680e6a41;
            }
            puVar7 = (undefined4 *)Ordinal_1114(local_4cc[0]);
            iVar10 = rendering_refreshChannel(local_508 + 0x48c);
            Ordinal_1309(puVar7,0x400,uVar5,iVar10);
            if (*(int *)(local_518 + 8) == 0) {
LAB_680e67e6:
              bitmap_resolvePathData(local_508,0,puVar7);
            }
            else {
              puVar11 = puVar7;
              puVar13 = local_420;
              for (iVar10 = 0x106; iVar10 != 0; iVar10 = iVar10 + -1) {
                *puVar13 = *puVar11;
                puVar11 = puVar11 + 1;
                puVar13 = puVar13 + 1;
              }
              iVar10 = (**(code **)(local_518 + 8))(puVar7,puVar7,&local_550,1,0);
              if (iVar10 == 0) goto LAB_680e67e6;
              local_520 = 1;
              local_4c4 = local_550;
            }
            Ordinal_1115(local_4cc[0]);
            Ordinal_1115(local_504);
            iVar10 = local_548;
            iVar9 = local_514;
          }
        }
        if (2 < iVar10) {
          local_524 = 0;
          Ordinal_38((int)local_500,(short)iVar10 * (short)iVar9 + 3,&local_524,2);
          sVar1 = xtra_readBE16((undefined1 *)&local_524);
          local_53c = (int)sVar1;
        }
        if ((3 < iVar10) &&
           (local_554 = cast_lookupDataEntry((int)local_500,iVar10 * iVar9 + 4,0), local_554 != 0)) {
          puVar6 = (undefined1 *)Ordinal_1114(local_554);
          uVar2 = xtra_readBE16(puVar6);
          local_488 = CONCAT22((*(unsigned short *)((char *)&local_488 + 2)),uVar2);
          uVar2 = xtra_readBE16(puVar6 + 2);
          local_488 = CONCAT22(uVar2,(short)local_488);
          if ((short)local_488 < 1) {
            local_488 = 1;
          }
          local_534 = xtra_readBE32Ptr(puVar6 + 4);
          if (local_4e8 == 0) {
            local_4c0 = 0x400;
          }
          else {
            local_45c = *(undefined2 *)(local_508 + 0x4c4);
            local_4c0 = local_534;
          }
          Ordinal_1113(&local_554);
        }
        if ((local_4e8 == 0) &&
           (puVar7 = (undefined4 *)Ordinal_1114(local_4cc[0]), puVar7 != (undefined4 *)0x0)) {
          if (local_520 != 0) {
            puVar7 = local_420;
          }
          local_50c = (int *)rendering_getChannelRect((int)local_510,puVar7);
          Ordinal_1115(local_4cc[0]);
          if (local_50c == (int *)0x0) goto LAB_680e699e;
          Ordinal_1113(local_4cc);
          piVar12 = local_50c;
          piVar14 = local_4fc;
          for (iVar9 = 0x37; iVar9 != 0; iVar9 = iVar9 + -1) {
            *piVar14 = *piVar12;
            piVar12 = piVar12 + 1;
            piVar14 = piVar14 + 1;
          }
          local_544[0] = (short)local_50c[1];
          iVar9 = local_514;
        }
        else {
LAB_680e699e:
          uVar4 = rendering_getChannelInfo((int)local_510,local_4fc);
          local_544[0] = (short)uVar4;
          if (local_544[0] == 0) goto LAB_680e6a41;
        }
        sVar1 = scoreEngine_getChannelValue(local_508,(int)local_544);
        if (sVar1 == 0) {
          if (local_50c == (int *)0x0) {
            rendering_setChannelProperty(local_510,local_4fc[1],0);
            Ordinal_1130(local_4fc,0xdc);
          }
          goto LAB_680e6a41;
        }
        if (local_504 != 0) {
          Ordinal_1113(&local_504);
        }
        local_514 = iVar9 + 1;
      } while (local_514 < *(short *)(*local_500 + 6));
    }
    if (*(code **)(local_518 + 0xa4) != (code *)0x0) {
      (**(code **)(local_518 + 0xa4))(*(undefined4 *)(*(int *)(local_508 + 4) + 4),0);
    }
    iVar10 = Ordinal_1042();
    if (iVar10 == 0) {
      local_51c = 1;
    }
  }
LAB_680e6a41:
  if (local_504 != 0) {
    Ordinal_1113(&local_504);
  }
  if (local_51c == 0) {
    if (local_540 != 0) {
      Ordinal_1113(&local_540);
    }
    if (local_4cc[0] != 0) {
      Ordinal_1113(local_4cc);
    }
  }
  if (local_500 != (int *)0x0) {
    Ordinal_36((int *)&local_500);
  }
  return 0;
}



// ============================================================
// Function: bitmap_processFontMapping (FUN_680e6b00)
// Address: 680e6b00
// Size: 307 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_processFontMapping(int param_1)
{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int *local_10;
  short *local_c;
  int local_8;
  
  local_10 = (int *)0x0;
  local_8 = *(int *)(*(int *)(param_1 + 4) + 8);
  uVar2 = rendering_updateChannelState(param_1 + 0x48c);
  if ((uVar2 < 0x1100) && (local_10 = scoreEngine_getFrameDataPtr(param_1), local_10 != (int *)0x0)) {
    local_c = (short *)scoreEngine_getFrameSize((int)local_10);
    while (local_c != (short *)0x0) {
      piVar1 = (int *)(local_c + 2);
      if (*(int *)(local_c + 2) != 0) {
        uVar3 = Ordinal_1114(*(int *)(local_c + 2));
        iVar4 = Ordinal_1201(uVar3);
        playback_renderSpriteEx(local_8,param_1 + 0x50c,uVar3,iVar4);
        Ordinal_1115(*piVar1);
        iVar4 = playback_mapFont(*piVar1,0,iVar4,0);
        if (iVar4 == 0) break;
        Ordinal_1113(piVar1);
        *piVar1 = iVar4;
      }
      iVar4 = rendering_getChannelSprite(local_8,*local_c);
      if (*(int *)(iVar4 + 0x14) == 0) {
        piVar1 = (int *)(iVar4 + 0x30);
        if (*piVar1 != 0) {
          uVar3 = Ordinal_1114(*piVar1);
          iVar4 = Ordinal_1201(uVar3);
          playback_renderSpriteEx(local_8,param_1 + 0x50c,uVar3,iVar4);
          Ordinal_1115(*piVar1);
          iVar4 = playback_convertFontName(*piVar1);
          if (iVar4 == 0) break;
          Ordinal_1113(piVar1);
          *piVar1 = iVar4;
        }
      }
      local_c = (short *)scoreEngine_getFrameSize((int)local_10);
    }
  }
  rendering_getDispatchState((int *)&local_10);
  return 0;
}



// ============================================================
// Function: bitmap_writeCastLibData (FUN_680e6c40)
// Address: 680e6c40
// Size: 946 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_writeCastLibData(int param_1,int param_2,int *param_3)
{
  short sVar1;
  short sVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int iVar9;
  int local_428;
  int local_420;
  int local_41c;
  undefined1 local_418 [4];
  undefined4 local_414;
  int local_410;
  int *local_40c;
  undefined1 local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_40c = (int *)0x0;
  iVar9 = *(int *)(*(int *)(param_1 + 4) + 8);
  local_414 = 0;
  local_428 = 0;
  local_40c = (int *)Ordinal_35(0xc);
  if (local_40c != (int *)0x0) {
    *(undefined4 *)*local_40c = 0xc;
    *(undefined2 *)(*local_40c + 6) = *(undefined2 *)(param_1 + 0x478);
    *(undefined2 *)(*local_40c + 8) = 4;
    sVar1 = *(short *)(*local_40c + 8);
    local_420 = 0;
    iVar3 = Ordinal_1154(*(undefined4 *)(param_1 + 0x470));
    if (0 < iVar3) {
      do {
        sVar2 = (short)local_420;
        psVar4 = (short *)scoreEngine_getFrameData(param_1,sVar2 + 1);
        if ((psVar4 != (short *)0x0) && (iVar3 = rendering_getChannelSprite(iVar9,*psVar4), iVar3 != 0)) {
          if (*(int *)(psVar4 + 2) == 0) {
            iVar5 = cast_formatNumber(&local_40c,sVar2 * sVar1 + 1,0);
            if (iVar5 == 0) goto LAB_680e6faa;
          }
          else {
            iVar5 = Ordinal_1116(*(int *)(psVar4 + 2),1);
            local_410 = Ordinal_1111(iVar5 + 1);
            uVar6 = Ordinal_1114(local_410);
            uVar7 = Ordinal_1114(*(undefined4 *)(psVar4 + 2));
            Ordinal_1233(uVar6,uVar7);
            Ordinal_1115(local_410);
            Ordinal_1115(*(undefined4 *)(psVar4 + 2));
            iVar5 = cast_formatNumber(&local_40c,sVar2 * sVar1 + 1,local_410);
            if (iVar5 == 0) {
              Ordinal_1113(&local_410);
              goto LAB_680e6faa;
            }
            Ordinal_1113(&local_410);
          }
          sVar2 = sVar2 * sVar1;
          if (*(int *)(iVar3 + 0x14) == 0) {
            local_408 = 0;
            memset(local_407,0,0x3ff);
            uVar6 = Ordinal_1114(*(undefined4 *)(iVar3 + 0x30));
            Ordinal_1310(uVar6,local_407,0x3ff);
            iVar5 = Ordinal_1201(local_407);
            local_407[iVar5] = 0;
            local_408 = (undefined1)iVar5;
            if (0xfe < iVar5) {
              local_408 = 0xff;
            }
            Ordinal_1115(*(undefined4 *)(iVar3 + 0x30));
            if (iVar5 < 0xff) {
              iVar5 = iVar5 + 1;
            }
            else {
              iVar5 = iVar5 + 2;
            }
            iVar3 = Ordinal_37(&local_40c,sVar2 + 2,&local_408,iVar5);
          }
          else {
            iVar3 = cast_formatNumber(&local_40c,sVar2 + 2,0);
          }
          if (iVar3 == 0) goto LAB_680e6faa;
          xtra_readBE32(local_418);
          iVar3 = Ordinal_37(&local_40c,sVar2 + 3,local_418,2);
          if ((iVar3 == 0) || (local_41c = Ordinal_1111(8,1), local_41c == 0)) goto LAB_680e6faa;
          puVar8 = (undefined1 *)Ordinal_1114(local_41c);
          xtra_readBE32(puVar8);
          xtra_readBE32(puVar8 + 2);
          xtra_skipBytes(puVar8 + 4);
          iVar3 = cast_formatNumber(&local_40c,sVar2 + 4,local_41c);
          Ordinal_1113(&local_41c);
          if (iVar3 == 0) goto LAB_680e6faa;
        }
        local_420 = local_420 + 1;
        iVar3 = Ordinal_1154(*(undefined4 *)(param_1 + 0x470));
      } while (local_420 < iVar3);
    }
    local_428 = cast_readDataEntry((int)local_40c,param_2,1);
    if ((local_428 != 0) && (iVar9 = Ordinal_1042(), iVar9 == 0)) {
      local_414 = 1;
    }
LAB_680e6faa:
    if (local_40c != (int *)0x0) {
      Ordinal_36((int *)&local_40c);
    }
  }
  if (param_3 != (int *)0x0) {
    *param_3 = local_428;
  }
  return 0;
}



// ============================================================
// Function: bitmap_openLinkedCastLib (FUN_680e7000)
// Address: 680e7000
// Size: 140 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_openLinkedCastLib(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 local_c;
  int local_8;
  
  puVar2 = param_1;
  piVar1 = (int *)*param_1;
  local_8 = 0;
  local_c = 0;
  iVar3 = rendering_getChannelDepth((int)param_1);
  uVar4 = playback_openScore(iVar3,FOURCC_ccl,puVar2[0xf],&param_1,&local_8);
  if (local_8 == 0) {
LAB_680e7053:
    if (uVar4 < 8) goto switchD_680e7058_switchD;
switchD_680e7058_caseD_1:
    iVar3 = -0x74;
  }
  else {
    iVar3 = Ordinal_1439(local_8,param_1,0);
    puVar2[0x19] = iVar3;
    if (iVar3 == 0) goto LAB_680e7053;
switchD_680e7058_switchD:
    switch(uVar4) {
    default:
      local_c = 1;
      goto LAB_680e7077;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      goto switchD_680e7058_caseD_1;
    case 6:
      iVar3 = -0x7a;
    }
  }
  lingo_formatDebugMsg(piVar1,iVar3);
LAB_680e7077:
  Ordinal_1407(&local_8);
  return local_c;
}



// ============================================================
// Function: bitmap_writeChannelScore (FUN_680e70b0)
// Address: 680e70b0
// Size: 82 bytes
// Params: int * param_1, int param_2, undefined4 param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_writeChannelScore(int *param_1,int param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  uVar2 = 0;
  iVar1 = rendering_getChannelLock((int)param_1);
  if ((iVar1 == 0) || (iVar3 = rendering_writeChannelScoreData(*param_1,param_2,iVar1), iVar3 != 0)) {
    uVar2 = 1;
  }
  if (param_4 != (int *)0x0) {
    *param_4 = iVar3;
  }
  return uVar2;
}



// ============================================================
// Function: bitmap_openCastInfo (FUN_680e7110)
// Address: 680e7110
// Size: 313 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_openCastInfo(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int local_14;
  undefined4 local_10;
  int *local_c;
  int local_8;
  
  puVar1 = param_1;
  piVar6 = (int *)*param_1;
  local_10 = 0;
  local_8 = 0;
  local_c = piVar6;
  iVar2 = rendering_getChannelDepth((int)param_1);
  uVar3 = playback_openScore(iVar2,FOURCC_Cinf,puVar1[0xf],&local_14,&local_8);
  if (local_8 == 0) {
    if (uVar3 < 8) goto switchD_680e7215_switchD;
switchD_680e7215_caseD_1:
    iVar2 = -0x74;
  }
  else {
    param_1 = (undefined4 *)0x0;
    iVar2 = cast_writeDataEntry(local_8,local_14,0);
    puVar1[0x34] = iVar2;
    param_1 = (undefined4 *)Ordinal_1126(0x400,0);
    if (param_1 != (undefined4 *)0x0) {
      *(undefined1 *)((int)param_1 + 1) = 0;
      *(undefined1 *)param_1 = 0;
      uVar4 = Ordinal_38(puVar1[0x34],3,param_1,0x400);
      if (1 < uVar4) {
        *(undefined1 *)((uVar4 - 1) + (int)param_1) = 0;
        if (uVar4 - 2 < 0xff) {
          *(char *)param_1 = (char)(uVar4 - 2);
        }
        else {
          *(undefined1 *)param_1 = 0xff;
        }
        iVar2 = Ordinal_1111(0x418,0);
        puVar1[0xd] = iVar2;
        if (iVar2 != 0) {
          iVar2 = Ordinal_1114(iVar2);
          iVar5 = rendering_refreshChannel((int)(puVar1 + 0x1a));
          Ordinal_1309(iVar2,0x400,(int)param_1 + 1,iVar5);
          piVar6 = local_c;
          if (iVar2 != 0) {
            Ordinal_1115(puVar1[0xd]);
            piVar6 = local_c;
          }
        }
      }
    }
    Ordinal_1127(&param_1);
switchD_680e7215_switchD:
    switch(uVar3) {
    default:
      local_10 = 1;
      goto LAB_680e7234;
    case 1:
    case 2:
    case 3:
    case 4:
    case 5:
      goto switchD_680e7215_caseD_1;
    case 6:
      iVar2 = -0x7a;
    }
  }
  lingo_formatDebugMsg(piVar6,iVar2);
LAB_680e7234:
  Ordinal_1407(&local_8);
  return local_10;
}



// ============================================================
// Function: bitmap_writeLinkedFileData (FUN_680e7270)
// Address: 680e7270
// Size: 437 bytes
// Params: int param_1, int param_2, undefined4 param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_writeLinkedFileData(int param_1,int param_2,undefined4 param_3,int *param_4)
{
  int *piVar1;
  byte bVar2;
  int iVar3;
  uint uVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *local_42c;
  int local_428;
  byte *local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  piVar1 = (int *)(param_1 + 0xd0);
  local_428 = 0;
  if (*piVar1 == 0) {
    iVar3 = Ordinal_35(4);
    *piVar1 = iVar3;
  }
  if (*piVar1 == 0) goto LAB_680e73fe;
  local_424 = (byte *)0x0;
  local_42c = (undefined4 *)0x0;
  local_424 = (byte *)Ordinal_1126(0x400,0);
  if (local_424 != (byte *)0x0) {
    local_424[1] = 0;
    if ((*(int *)(param_1 + 0x14) == 0) && (*(int *)(param_1 + 0x30) != 0)) {
      local_42c = (undefined4 *)Ordinal_1114(*(int *)(param_1 + 0x30));
      puVar5 = local_42c;
      puVar6 = local_420;
      for (iVar3 = 0x106; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar6 = *puVar5;
        puVar5 = puVar5 + 1;
        puVar6 = puVar6 + 1;
      }
      Ordinal_1316(local_420);
      iVar3 = Ordinal_1310(local_420,local_424 + 1,0x400);
      if (iVar3 != 0) goto LAB_680e7349;
    }
    else {
LAB_680e7349:
      iVar3 = Ordinal_1201(local_424 + 1);
      local_424[iVar3 + 1] = 0;
      iVar3 = Ordinal_1201(local_424 + 1);
      if (iVar3 < 0xff) {
        bVar2 = Ordinal_1201(local_424 + 1);
        *local_424 = bVar2;
      }
      else {
        *local_424 = 0xff;
      }
      if (*local_424 == 0xff) {
        uVar4 = Ordinal_1201(local_424 + 1);
      }
      else {
        uVar4 = (uint)*local_424;
      }
      iVar3 = Ordinal_37(piVar1,3,local_424,uVar4 + 2);
      if (iVar3 != 0) {
        local_428 = cast_readDataEntry(*piVar1,param_2,0);
      }
    }
    if (local_42c != (undefined4 *)0x0) {
      Ordinal_1115(*(undefined4 *)(param_1 + 0x30));
    }
  }
  Ordinal_1127(&local_424);
LAB_680e73fe:
  if (param_4 != (int *)0x0) {
    *param_4 = local_428;
  }
  return 0;
}



// ============================================================
// Function: bitmap_initCastLib (FUN_680e7430)
// Address: 680e7430
// Size: 99 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_initCastLib(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = param_1;
  *(code **)(param_1 + 0x84) = Ordinal_102;
  *(code **)(param_1 + 0x88) = display_checkUrlAccess;
  Ordinal_1327(display_checkUrlAccess);
  bitmap_initExportPath((undefined4 *)0x0);
  Ordinal_1540(&param_1);
  *(int *)(iVar1 + 4) = param_1;
  uVar2 = Ordinal_1510(DAT_681956e0,0,10);
  *(undefined4 *)(iVar1 + 0x60) = uVar2;
  return 1;
}



// ============================================================
// Function: bitmap_registerCastLib (FUN_680e74a0)
// Address: 680e74a0
// Size: 82 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_registerCastLib(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = Ordinal_1038(&LAB_6811d1e0,xtra_initWriterFail,xtra_initWriterStub,&LAB_6811d1f0,xtra_createWriterContext);
  iVar2 = Ordinal_2071(uVar1);
  if (iVar2 == 0) {
    uVar1 = Ordinal_1038();
    iVar2 = xtra_registerSerializedXtra(uVar1);
    if (iVar2 == 0) {
      uVar1 = Ordinal_1038();
      iVar2 = display_registerSpritePlugin(uVar1);
      if (iVar2 == 0) {
        return 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_destroyCastLib (FUN_680e7500)
// Address: 680e7500
// Size: 84 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_destroyCastLib(int param_1)
{
  media_clearResourceSlots(param_1);
  bitmap_cleanupExportState();
  playback_destroyFontMapData((int *)(param_1 + 8));
  media_freeBlendTable();
  if (*(int *)(param_1 + 0x60) != 0) {
    Ordinal_1514(param_1 + 0x60);
  }
  Ordinal_1327(0);
  *(undefined4 *)(param_1 + 0x88) = 0;
  display_freeSecurityHandles();
  *(undefined4 *)(param_1 + 0x84) = 0;
  return 0;
}



