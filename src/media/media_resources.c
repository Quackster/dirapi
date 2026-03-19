// Module: media
// Topic: Resource management, file handling, and path operations
// Address range: 0x680a16b0 - 0x680a2360
// Functions (32):
//   media_queryResourceInterface (FUN_680a16b0)
//   media_releaseResourceRef (FUN_680a1700)
//   media_allocResourceBlock (FUN_680a1720)
//   media_getResourceVtable (FUN_680a1740)
//   media_createResourceObject (FUN_680a1790)
//   media_truncatePath (FUN_680a17b0)
//   media_getResourceRef
//   media_resolvePathType (FUN_680a1970)
//   media_matchResourcePath (FUN_680a19b0)
//   media_notifyResourcePath (FUN_680a1a60)
//   media_processResourceCallback (FUN_680a1ab0)
//   media_enumerateResource (FUN_680a1bf0)
//   media_dispatchResourceCmd (FUN_680a1c30)
//   media_findResourcePath (FUN_680a1cc0)
//   media_processResourceDispatch (FUN_680a1d20)
//   media_collectResourceFiles (FUN_680a1d80)
//   media_organizeResources (FUN_680a1e90)
//   media_getDataSize
//   media_getDataOffset
//   media_getDataPtr
//   media_getResourceSlot (FUN_680a21f0)
//   media_setResourceSlot (FUN_680a2220)
//   media_clearResourceSlots (FUN_680a2250)
//   media_readDword (FUN_680a2280)
//   media_writeDword (FUN_680a2290)
//   media_skipDword (FUN_680a22b0)
//   media_readTriple (FUN_680a22c0)
//   media_writeTriple (FUN_680a22f0)
//   media_skipTriple (FUN_680a2320)
//   media_readWord (FUN_680a2330)
//   media_writeWord (FUN_680a2340)
//   media_skipWord (FUN_680a2360)

// ============================================================
// Function: media_queryResourceInterface (FUN_680a16b0)
// Address: 680a16b0
// Size: 66 bytes
// Params: int * param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_queryResourceInterface(int *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  
  *param_3 = 0;
  iVar1 = Ordinal_2066(param_2,&DAT_68175b78);
  if (iVar1 != 0) {
    *param_3 = param_1;
    (**(code **)(*param_1 + 4))(param_1);
    return 0;
  }
  return 0x80040004;
}



// ============================================================
// Function: media_releaseResourceRef (FUN_680a1700)
// Address: 680a1700
// Size: 22 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_releaseResourceRef(undefined4 param_1,int param_2)
{
  if (param_2 != 0) {
    Ordinal_1125(&param_2);
  }
  return 0;
}



// ============================================================
// Function: media_allocResourceBlock (FUN_680a1720)
// Address: 680a1720
// Size: 26 bytes
// Params: undefined4 param_1, uint param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_allocResourceBlock(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (param_2 < 0x7fffffff) {
    uVar1 = Ordinal_1124(param_2);
  }
  return uVar1;
}



// ============================================================
// Function: media_getResourceVtable (FUN_680a1740)
// Address: 680a1740
// Size: 72 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * media_getResourceVtable(void)

{
  if (DAT_681963a0 == '\0') {
    DAT_681963a0 = '\x01';
    _DAT_681984e0 = media_queryResourceInterface;
    _DAT_681984e4 = crt_addStreamRef;
    _DAT_681984e8 = crt_releaseStreamRef;
    _DAT_681984ec = media_allocResourceBlock;
    _DAT_681984f0 = media_releaseResourceRef;
  }
  return &DAT_681984e0;
}



// ============================================================
// Function: media_createResourceObject (FUN_680a1790)
// Address: 680a1790
// Size: 31 bytes
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * media_createResourceObject(void)

{
  undefined4 *puVar1;
  undefined *puVar2;
  
  puVar1 = (undefined4 *)Ordinal_1124(8);
  if (puVar1 != (undefined4 *)0x0) {
    puVar2 = media_getResourceVtable();
    *puVar1 = puVar2;
    (**(code **)(puVar2 + 4))(puVar1);
  }
  return puVar1;
}



// ============================================================
// Function: media_truncatePath (FUN_680a17b0)
// Address: 680a17b0
// Size: 128 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_truncatePath(int param_1)

{
  char *pcVar1;
  char cVar2;
  char *in_EAX;
  undefined4 uVar3;
  uint extraout_EDX;
  int iVar4;
  int local_10;
  int local_c;
  char *local_8;
  
  iVar4 = 0;
  cVar2 = *in_EAX;
  local_10 = 0;
  local_8 = in_EAX;
  while (cVar2 != '\0') {
    uVar3 = Ordinal_1252(in_EAX + iVar4,&local_c);
    iVar4 = iVar4 + local_c;
    Ordinal_1253(uVar3);
    if ((extraout_EDX & 0x42000000) != 0) {
      local_10 = local_10 + local_c;
      if (param_1 <= local_10) break;
      local_8 = (char *)Ordinal_1247(local_8,uVar3);
    }
    cVar2 = in_EAX[iVar4];
  }
  *local_8 = '\0';
  pcVar1 = in_EAX + 1;
  do {
    cVar2 = *in_EAX;
    in_EAX = in_EAX + 1;
  } while (cVar2 != '\0');
  return in_EAX != pcVar1;
}



// ============================================================
// Function: media_getResourceRef (FUN_680a1830)
// Address: 680a1830
// Size: 307 bytes
// Params: int param_1, undefined4 param_2, char * param_3, char * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getResourceRef(int param_1,undefined4 param_2,char *param_3,char *param_4,int param_5)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  char local_408 [1024];
  uint local_8;
  
  iVar2 = crt_writeFormatError(param_1,param_2);
  if ((iVar2 != 0) && (param_5 != 0)) {
    iVar3 = Ordinal_1517(DAT_681956e0,0xfa3,local_408,0x3ff);
    iVar2 = 0;
    if (iVar3 != 0) {
      iVar2 = Ordinal_1317(param_2,local_408);
    }
  }
  iVar3 = crt_getMaxChannels();
  if (iVar2 != 0) {
    if (param_3 != (char *)0x0) {
      strncpy(local_408,param_3,0x3fe);
      bVar1 = media_truncatePath(iVar3);
      if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_680a1950;
      iVar2 = Ordinal_1317(param_2,local_408);
    }
    if ((iVar2 != 0) && (param_4 != (char *)0x0)) {
      strncpy(local_408,param_4,0x3fe);
      bVar1 = media_truncatePath(iVar3);
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        Ordinal_1317(param_2,local_408);
        return 0;
      }
    }
  }
LAB_680a1950:
  return 0;
}



// ============================================================
// Function: media_resolvePathType (FUN_680a1970)
// Address: 680a1970
// Size: 62 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_resolvePathType(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = param_1;
  iVar1 = Ordinal_1351(param_1);
  if (iVar1 == 0) {
    uVar2 = Ordinal_1357(uVar2);
    return uVar2;
  }
  iVar1 = Ordinal_1359(uVar2,4,&param_1);
  if (iVar1 != 0) {
    return param_1;
  }
  return 1;
}



// ============================================================
// Function: media_matchResourcePath (FUN_680a19b0)
// Address: 680a19b0
// Size: 168 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_matchResourcePath(undefined4 param_1,int param_2)
{
  int iVar1;
  undefined4 *in_stack_00000018;
  undefined1 local_420 [1048];
  uint local_8;
  
  if (param_2 != 0) {
    iVar1 = Ordinal_1329(in_stack_00000018[1],param_2);
    if (iVar1 != 0) {
      iVar1 = Ordinal_1326(local_420,0x400,in_stack_00000018[1]);
      if (iVar1 != 0) {
        iVar1 = Ordinal_1316(local_420);
        if (iVar1 != 0) {
          iVar1 = Ordinal_1317(local_420,*in_stack_00000018);
          if (iVar1 != 0) {
            iVar1 = Ordinal_1319(local_420,in_stack_00000018[1]);
            if (iVar1 != 0) {
              in_stack_00000018[2] = 1;
              return 0;
            }
          }
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: media_notifyResourcePath (FUN_680a1a60)
// Address: 680a1a60
// Size: 77 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_notifyResourcePath(undefined4 param_1)
{
  int iVar1;
  int unaff_ESI;
  undefined1 local_424 [1048];
  undefined4 local_c;
  uint local_8;
  
  iVar1 = Ordinal_1329(local_424,param_1);
  if (iVar1 != 0) {
    local_c = *(undefined4 *)(unaff_ESI + 0x10);
    Ordinal_1152(*(undefined4 *)(unaff_ESI + 8),local_424);
  }
  return 0;
}



// ============================================================
// Function: media_processResourceCallback (FUN_680a1ab0)
// Address: 680a1ab0
// Size: 307 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x680a1b32) */

int media_processResourceCallback(undefined4 param_1,undefined4 param_2)
{
  int iVar1;
  int *in_stack_0000001c;
  undefined4 *in_stack_00000028;
  undefined4 local_38;
  int local_30;
  undefined4 *local_2c;
  uint local_8;
  
  local_2c = in_stack_00000028;
  iVar1 = Ordinal_2066();
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*in_stack_0000001c + 0x28))();
    if (iVar1 == 0) {
      (**(code **)(*in_stack_0000001c + 0x14))();
    }
    else {
      iVar1 = Ordinal_2066();
      if (((iVar1 != 0) && (iVar1 = (**(code **)(*in_stack_0000001c + 0x28))(), iVar1 == 0)) &&
         (local_30 = Ordinal_1124(local_38), local_30 != 0)) {
        (**(code **)(*in_stack_0000001c + 0x14))();
        iVar1 = 0;
        do {
          *(undefined1 *)(iVar1 + local_30) = 0x20;
          iVar1 = iVar1 + 1;
        } while (iVar1 < 4);
        media_getScoreSlotRef(*local_2c,local_30,local_2c + 4);
        Ordinal_1125(&local_30);
      }
    }
    media_notifyResourcePath(param_2);
  }
  return 0;
}



// ============================================================
// Function: media_enumerateResource (FUN_680a1bf0)
// Address: 680a1bf0
// Size: 60 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_enumerateResource(undefined4 param_1,undefined4 param_2)
{
  undefined4 uVar1;
  int *piVar2;
  int unaff_EDI;
  
  uVar1 = Ordinal_1038();
  piVar2 = (int *)Ordinal_2068(uVar1);
  if (piVar2 != (int *)0x0) {
    *(undefined4 *)(unaff_EDI + 0xc) = param_1;
    (**(code **)(*piVar2 + 0x28))(piVar2,param_2,1,media_processResourceCallback);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return 0;
}



// ============================================================
// Function: media_dispatchResourceCmd (FUN_680a1c30)
// Address: 680a1c30
// Size: 142 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_dispatchResourceCmd(undefined4 param_1,int param_2)

{
  int iVar1;
  int in_stack_00000018;
  
  if ((param_2 != 0) && (iVar1 = crt_checkUrlSuffix(param_2), iVar1 != 0)) {
    iVar1 = *(int *)(in_stack_00000018 + 4);
    *(undefined4 *)(in_stack_00000018 + 0x10) = 0;
    if (iVar1 < 0x62d) {
      if (iVar1 == 0x62c) {
        media_enumerateResource(&DAT_68176108,param_2);
        return 0;
      }
      if (iVar1 == 0x36a) {
        media_notifyResourcePath(param_2);
        return 0;
      }
      if (iVar1 == 0x62b) {
        media_enumerateResource(&DAT_68176138,param_2);
        return 0;
      }
    }
    else if (iVar1 == 0x62e) {
      media_enumerateResource(&DAT_68176128,param_2);
    }
  }
  return 0;
}



// ============================================================
// Function: media_findResourcePath (FUN_680a1cc0)
// Address: 680a1cc0
// Size: 94 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_findResourcePath(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  
  uVar1 = Ordinal_1038();
  piVar2 = (int *)Ordinal_2068(uVar1);
  if (piVar2 != (int *)0x0) {
    local_10 = param_1;
    local_c = param_2;
    local_8 = 0;
    (**(code **)(*piVar2 + 0xc))(piVar2,media_matchResourcePath,&local_10);
    (**(code **)(*piVar2 + 8))(piVar2);
    return local_8 == 1;
  }
  return false;
}



// ============================================================
// Function: media_processResourceDispatch (FUN_680a1d20)
// Address: 680a1d20
// Size: 88 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_processResourceDispatch(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  
  uVar1 = Ordinal_1038();
  piVar2 = (int *)Ordinal_2068(uVar1);
  local_18 = param_1;
  local_14 = param_2;
  local_10 = Ordinal_1150(10,2,0x41c);
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 0xc))(piVar2,media_dispatchResourceCmd,&local_18);
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  return local_10;
}



// ============================================================
// Function: media_collectResourceFiles (FUN_680a1d80)
// Address: 680a1d80
// Size: 263 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_collectResourceFiles(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined1 local_820 [1048];
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar3 = 0;
  uVar1 = Ordinal_1355(local_820,param_1,0);
  while (uVar1 != 0) {
    iVar2 = Ordinal_1319(param_2,local_820);
    if (iVar2 == 0) {
      if ((uVar1 & 2) == 0) {
        iVar2 = Ordinal_1314(local_820,local_408,0x3ff);
        if ((iVar2 != 0) && (iVar2 = Ordinal_1255(param_3,local_408), iVar2 == 0)) {
          Ordinal_1352(local_820);
        }
      }
      else {
        media_collectResourceFiles(local_820,param_2,param_3);
      }
    }
    iVar3 = iVar3 + 1;
    uVar1 = Ordinal_1355(local_820,param_1,iVar3);
  }
  return 0;
}



// ============================================================
// Function: media_organizeResources (FUN_680a1e90)
// Address: 680a1e90
// Size: 805 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_organizeResources(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int local_420;
  int local_414;
  int local_410;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_40c = 0;
  iVar4 = Ordinal_1126(0x20c0,0);
  local_410 = iVar4;
  if (iVar4 != 0) {
    iVar1 = iVar4 + 0x418;
    iVar2 = iVar4 + 0x830;
    iVar5 = media_getResourceRef(param_1,iVar4,(char *)0x0,(char *)0x0,1);
    if ((((iVar5 != 0) &&
         (iVar5 = media_getResourceRef(param_1,iVar1,(char *)0x0,(char *)0x0,0), iVar5 != 0)) &&
        (iVar5 = Ordinal_1326(iVar2,0x3ff,iVar1), iVar5 != 0)) &&
       (iVar5 = Ordinal_1316(iVar2), iVar5 != 0)) {
      iVar5 = 0;
      iVar9 = local_410 + 0xc48;
      local_40c = 0;
      iVar6 = Ordinal_1355(iVar9,iVar4,0);
      while (iVar6 != 0) {
        iVar6 = local_410 + 0x1060;
        local_420 = 0;
        iVar7 = Ordinal_1355(iVar6,iVar9,0);
        while (iVar7 != 0) {
          iVar5 = local_410 + 0x1ca8;
          local_414 = 0;
          iVar7 = local_410 + 0x1478;
          iVar3 = local_410 + 0x1890;
          iVar8 = Ordinal_1355(iVar5,iVar6,0);
          while (iVar8 != 0) {
            iVar8 = Ordinal_1304(iVar4,iVar5,local_408,0x3ff);
            if (((((iVar8 != 0) && (iVar8 = Ordinal_1326(iVar7,0x3ff,iVar1), iVar8 != 0)) &&
                 ((iVar8 = Ordinal_1318(iVar7,local_408), iVar8 != 0 &&
                  ((iVar8 = Ordinal_1326(iVar3,0x3ff,iVar7), iVar8 != 0 &&
                   (iVar8 = Ordinal_1316(iVar3), iVar8 != 0)))))) &&
                (iVar8 = media_resolvePathType(iVar3), iVar8 != 0)) &&
               (iVar8 = Ordinal_1314(iVar5,local_408,0x3ff), iVar8 != 0)) {
              media_collectResourceFiles(iVar2,iVar5,local_408);
              iVar8 = Ordinal_1356(iVar3,0,1);
              if (iVar8 != 0) {
                iVar8 = Ordinal_1354(iVar3,iVar5);
                if (iVar8 == 0) {
                  Ordinal_1352(iVar3);
                }
                else {
                  iVar8 = Ordinal_1353(iVar3,iVar7);
                  if (iVar8 == 0) {
                    Ordinal_1352(iVar3);
                  }
                  iVar8 = Ordinal_1352(iVar5);
                  if (iVar8 != 0) {
                    local_414 = local_414 + -1;
                  }
                }
              }
            }
            local_414 = local_414 + 1;
            iVar8 = Ordinal_1355(iVar5,iVar6,local_414);
          }
          Ordinal_1355(iVar6,iVar9,local_420);
          iVar5 = Ordinal_1358(iVar6);
          if (iVar5 != 0) {
            local_420 = local_420 + -1;
          }
          local_420 = local_420 + 1;
          iVar7 = Ordinal_1355(iVar6,iVar9,local_420);
          iVar5 = local_40c;
        }
        Ordinal_1355(iVar9,iVar4,iVar5);
        iVar6 = Ordinal_1358(iVar9);
        if (iVar6 != 0) {
          iVar5 = iVar5 + -1;
        }
        iVar5 = iVar5 + 1;
        local_40c = iVar5;
        iVar6 = Ordinal_1355(iVar9,iVar4,iVar5);
      }
      Ordinal_1326(iVar2,0x400,iVar4);
      Ordinal_1316(iVar2);
      Ordinal_1355(iVar9,iVar2,0);
      Ordinal_1358(iVar4);
      local_40c = 1;
    }
  }
  Ordinal_1127(&local_410);
  return 0;
}



// ============================================================
// Function: media_getDataSize (FUN_680a21c0)
// Address: 680a21c0
// Size: 16 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getDataSize(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x18) = param_2;
  return 0;
}



// ============================================================
// Function: media_getDataOffset (FUN_680a21d0)
// Address: 680a21d0
// Size: 13 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getDataOffset(int param_1)

{
  return *(undefined4 *)(param_1 + 0x18);
}



// ============================================================
// Function: media_getDataPtr (FUN_680a21e0)
// Address: 680a21e0
// Size: 15 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getDataPtr(int *param_1)

{
  return *param_1 + 0x1c;
}



// ============================================================
// Function: media_getResourceSlot (FUN_680a21f0)
// Address: 680a21f0
// Size: 38 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getResourceSlot(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_2 < 8) && (iVar1 = *(int *)(param_1 + 100 + param_2 * 4), iVar1 != 0)) {
    Ordinal_1651(iVar1);
  }
  return iVar1;
}



// ============================================================
// Function: media_setResourceSlot (FUN_680a2220)
// Address: 680a2220
// Size: 41 bytes
// Params: int param_1, uint param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setResourceSlot(int param_1,uint param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  
  if (param_2 < 8) {
    puVar1 = (undefined4 *)(param_1 + 100 + param_2 * 4);
    Ordinal_1653(puVar1);
    *puVar1 = param_3;
    Ordinal_1651(param_3);
  }
  return 0;
}



// ============================================================
// Function: media_clearResourceSlots (FUN_680a2250)
// Address: 680a2250
// Size: 34 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_clearResourceSlots(int param_1)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1 + 100;
  iVar2 = 8;
  do {
    Ordinal_1653(iVar1);
    iVar1 = iVar1 + 4;
    iVar2 = iVar2 + -1;
  } while (iVar2 != 0);
  return 0;
}



// ============================================================
// Function: media_readDword (FUN_680a2280)
// Address: 680a2280
// Size: 15 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_readDword(int param_1)

{
  return **(undefined4 **)(param_1 + 0x60);
}



// ============================================================
// Function: media_writeDword (FUN_680a2290)
// Address: 680a2290
// Size: 22 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeDword(int param_1,undefined4 param_2)
{
  **(undefined4 **)(param_1 + 0x60) = param_2;
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 4;
  return 0;
}



// ============================================================
// Function: media_skipDword (FUN_680a22b0)
// Address: 680a22b0
// Size: 14 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_skipDword(int param_1)
{
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 4;
  return 0;
}



// ============================================================
// Function: media_readTriple (FUN_680a22c0)
// Address: 680a22c0
// Size: 34 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_readTriple(int param_1)

{
  return (uint)**(uint3 **)(param_1 + 0x60);
}



// ============================================================
// Function: media_writeTriple (FUN_680a22f0)
// Address: 680a22f0
// Size: 47 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeTriple(int param_1,undefined4 param_2)
{
  **(undefined1 **)(param_1 + 0x60) = (char)param_2;
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  **(undefined1 **)(param_1 + 0x60) = (char)((uint)param_2 >> 8);
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  **(undefined1 **)(param_1 + 0x60) = (char)((uint)param_2 >> 0x10);
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 1;
  return 0;
}



// ============================================================
// Function: media_skipTriple (FUN_680a2320)
// Address: 680a2320
// Size: 14 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_skipTriple(int param_1)
{
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 3;
  return 0;
}



// ============================================================
// Function: media_readWord (FUN_680a2330)
// Address: 680a2330
// Size: 16 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 media_readWord(int param_1)

{
  return **(undefined2 **)(param_1 + 0x60);
}



// ============================================================
// Function: media_writeWord (FUN_680a2340)
// Address: 680a2340
// Size: 24 bytes
// Params: int param_1, undefined2 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeWord(int param_1,undefined2 param_2)
{
  **(undefined2 **)(param_1 + 0x60) = param_2;
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 2;
  return 0;
}



// ============================================================
// Function: media_skipWord (FUN_680a2360)
// Address: 680a2360
// Size: 14 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_skipWord(int param_1)
{
  *(int *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) + 2;
  return 0;
}
