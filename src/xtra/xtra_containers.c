// Module: xtra
// Topic: Container and list objects, data items, array management
// Address range: 0x68105170 - 0x68106180
// Functions (27):
//   xtra_initContainerVtable
//   xtra_resetContainerItem
//   xtra_findContainerItem
//   xtra_addContainerItem
//   xtra_getContainerEncoded
//   xtra_processContainerChainItem
//   xtra_attachCryptoKey
//   xtra_resolveEncryptAlgorithm
//   xtra_destroyContainer
//   xtra_getContainerRef
//   xtra_addContainerData
//   xtra_getContainerData
//   xtra_getContainerLastItem
//   xtra_queryContainerEx
//   xtra_createCertListBlock
//   xtra_getEncodedCount
//   xtra_getEncodedEntry
//   xtra_queryContainer
//   xtra_removeEncodedEntry
//   xtra_initCertChainInfo
//   xtra_addCertChainEntry
//   xtra_verifyCertChain
//   xtra_buildCertChainEntry
//   xtra_insertDefaultCertEntry
//   xtra_initContainer
//   xtra_getCertChainInfo
//   xtra_getCertListEntry

// ============================================================
// Function: xtra_initContainerVtable (FUN_68105170)
// Address: 68105170
// Size: 36 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initContainerVtable(undefined4 *param_1)
{
  if ((param_1 == (undefined4 *)0x0) && (param_1 = xtra_allocZeroedBlock(0x28), param_1 == (undefined4 *)0x0)
     ) {
    return 0;
  }
  *param_1 = &PTR_FUN_6818f200;
  param_1[1] = 0x7cc;
  return 0;
}



// ============================================================
// Function: xtra_resetContainerItem (FUN_681051a0)
// Address: 681051a0
// Size: 35 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_resetContainerItem(int param_1)
{
  xtra_allocObjectBlock((int *)(param_1 + 8),*(size_t *)(param_1 + 0xc));
  xtra_freeAttributeList(param_1 + 0x10);
  return 0;
}



// ============================================================
// Function: xtra_findContainerItem (FUN_681051d0)
// Address: 681051d0
// Size: 85 bytes
// Params: int param_1, byte * param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_findContainerItem(int param_1,byte *param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar1 = 0;
  do {
    do {
      uVar4 = uVar1;
      iVar2 = xtra_getAttributeByIndex(param_1 + 0x10,uVar4);
      if (iVar2 == 0) {
        return 300;
      }
      uVar1 = uVar4 + 1;
    } while (*(uint *)(iVar2 + 0x10) != param_3);
    uVar3 = display_decodeFormat(*(byte **)(iVar2 + 0xc),param_2,param_3);
  } while (uVar3 != 0);
  *param_4 = uVar4;
  return 0;
}



// ============================================================
// Function: xtra_addContainerItem (FUN_68105230)
// Address: 68105230
// Size: 450 bytes
// Params: int param_1, uint * param_2, byte * param_3, uint param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_addContainerItem(int param_1,uint *param_2,byte *param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *local_34;
  uint local_30;
  int local_2c;
  int local_28;
  undefined1 local_24 [4];
  byte **local_20;
  undefined4 *local_1c;
  undefined4 *local_18;
  byte *local_14;
  uint local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  local_34 = (undefined4 *)0x0;
  display_fillMemory(&local_14,0,0x14);
  display_fillMemory(local_24,0,0x10);
  local_20 = &local_14;
  local_1c = &local_c;
  local_18 = &local_8;
  iVar1 = xtra_writeCertData((uint *)0x0,(uint *)&DAT_6818f208,(int)local_24,param_3,param_4);
  if (iVar1 != 0) goto LAB_681053a2;
  iVar2 = xtra_findContainerItem(param_1,local_14,local_10,&local_30);
  if (iVar2 == 0) {
    local_34 = (undefined4 *)xtra_getAttributeByIndex(param_1 + 0x10,local_30);
    local_28 = local_4;
    local_2c = xtra_allocAndCopyBlock(local_8,local_4);
    if (local_2c == 0) goto LAB_68105399;
    xtra_allocObjectBlock(local_34 + 6,local_34[7]);
    local_34[6] = local_2c;
    local_34[7] = local_28;
    local_34[5] = local_c;
  }
  else {
    local_34 = xtra_createAttributeNode((undefined4 *)0x0,local_c,local_14,local_10);
    if (local_34 != (undefined4 *)0x0) {
      iVar2 = xtra_allocAndCopyBlock(local_8,local_4);
      local_34[6] = iVar2;
      if (local_34[6] != 0) {
        local_34[7] = local_4;
        local_30 = xtra_addAttributeToList(param_1 + 0x10,local_34);
        if (local_30 != 0xffff) goto LAB_6810539e;
      }
    }
LAB_68105399:
    iVar1 = 0x100;
  }
LAB_6810539e:
  if (iVar1 == 0) {
    local_34[1] = param_3;
    local_34[2] = param_4;
    local_34[8] = 1;
    local_34[9] = 1;
    if (param_2 != (uint *)0x0) {
      *param_2 = local_30;
    }
    return 0;
  }
LAB_681053a2:
  xtra_initObjectBlock((int *)&local_34);
  return iVar1;
}



// ============================================================
// Function: xtra_getContainerEncoded (FUN_68105400)
// Address: 68105400
// Size: 184 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getContainerEncoded(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  int local_c;
  int local_8;
  int local_4;
  
  if ((*(int *)(param_1 + 0x20) == 0) || (*(int *)(param_1 + 4) == 0)) {
    display_fillMemory(&local_18,0,8);
    display_fillMemory(local_10,0,0x10);
    local_c = param_1 + 0xc;
    local_8 = param_1 + 0x14;
    local_4 = param_1 + 0x18;
    iVar1 = xtra_writeBERSequenceEx(&local_18,(uint *)&DAT_6818f208,(int)local_10);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)(param_1 + 0x24) == 0) {
      xtra_allocObjectBlock((int *)(param_1 + 4),*(size_t *)(param_1 + 8));
    }
    *(undefined4 *)(param_1 + 0x24) = 0;
    *(undefined4 *)(param_1 + 4) = local_18;
    *(undefined4 *)(param_1 + 0x20) = 1;
    *(undefined4 *)(param_1 + 8) = local_14;
  }
  *param_2 = *(undefined4 *)(param_1 + 4);
  *param_3 = *(undefined4 *)(param_1 + 8);
  return 0;
}



// ============================================================
// Function: xtra_processContainerChainItem (FUN_68105590)
// Address: 68105590
// Size: 87 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_processContainerChainItem(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  undefined4 local_8;
  uint local_4;
  
  iVar1 = xtra_getContainerEncodedEntry(&local_8,*param_4,param_4[1]);
  if (iVar1 == 0) {
    iVar1 = xtra_processCertChain(param_1,local_8,local_4,0x1b,0);
    if (iVar1 != 0) {
      iVar1 = xtra_getBERLength(iVar1);
      return iVar1;
    }
    iVar1 = 0;
    param_4[1] = param_4[1] + 1;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_attachCryptoKey (FUN_681055f0)
// Address: 681055f0
// Size: 52 bytes
// Params: int * param_1, undefined4 * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_attachCryptoKey(int *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)
{
  int iVar1;
  
  iVar1 = display_initContainerFormat(param_1,param_2,param_4);
  if (iVar1 != 0) {
    *param_1 = 0;
    return 0;
  }
  xtra_writeBERTag(param_1,param_3);
  return 0;
}



// ============================================================
// Function: xtra_resolveEncryptAlgorithm (FUN_68105630)
// Address: 68105630
// Size: 108 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_resolveEncryptAlgorithm(undefined4 *param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int *local_4;
  
  local_4 = (int *)0x0;
  iVar1 = display_getNetSecurityState(&local_4);
  if (iVar1 == 0) {
    iVar1 = xtra_loadEncryptAlgorithm((int)local_4,param_2,param_3);
    if (iVar1 == 0) {
      iVar1 = xtra_getEncryptAlgorithmInfo(param_1,local_4,param_3);
    }
  }
  else {
    iVar1 = 0x100;
  }
  display_initNetworkSecurity(&local_4);
  return iVar1;
}



// ============================================================
// Function: xtra_destroyContainer (FUN_681056a0)
// Address: 681056a0
// Size: 20 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_destroyContainer(int *param_1)
{
  xtra_writeBERBlock(param_1,(int *)0x0,8,0);
  return 0;
}



// ============================================================
// Function: xtra_getContainerRef (FUN_681056c0)
// Address: 681056c0
// Size: 54 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_getContainerRef(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_2,0);
  if (iVar1 != 0) {
    return 0x123;
  }
  *param_1 = *local_4;
  return 0;
}



// ============================================================
// Function: xtra_addContainerData (FUN_68105700)
// Address: 68105700
// Size: 82 bytes
// Params: undefined4 * param_1, undefined4 param_2, uint param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_addContainerData(undefined4 *param_1,undefined4 param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int local_4;
  
  if (0x7fff < param_3) {
    return 0x131;
  }
  iVar1 = xtra_writeBERContent(&local_4,param_2,param_3,(int)param_1);
  if (iVar1 == 0) {
    iVar1 = xtra_getContainerData(param_1,local_4,param_3,param_4);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_getContainerData (FUN_68105760)
// Address: 68105760
// Size: 145 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_getContainerData(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_1,0);
  if (iVar1 != 0) {
    return 0x123;
  }
  iVar1 = xtra_writeBERInt(local_4 + 1,(*local_4 * 3 + 3) * 4,(int)param_1);
  if (iVar1 == 0) {
    *(undefined4 *)(local_4[1] + *local_4 * 0xc) = param_2;
    *(undefined4 *)(local_4[1] + 4 + *local_4 * 0xc) = param_3;
    *(undefined4 *)(local_4[1] + 8 + *local_4 * 0xc) = param_4;
    iVar1 = 0;
    *local_4 = *local_4 + 1;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_getContainerLastItem (FUN_68105800)
// Address: 68105800
// Size: 134 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_getContainerLastItem(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_4,0);
  if (iVar1 != 0) {
    return 0x123;
  }
  if (*local_4 == 0) {
    return 0x123;
  }
  *param_1 = *(undefined4 *)(local_4[1] + -0xc + *local_4 * 0xc);
  *param_2 = *(undefined4 *)(local_4[1] + -8 + *local_4 * 0xc);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = *(undefined4 *)(local_4[1] + -4 + *local_4 * 0xc);
  }
  return 0;
}



// ============================================================
// Function: xtra_queryContainerEx (FUN_68105890)
// Address: 68105890
// Size: 123 bytes
// Params: undefined4 * param_1, undefined4 * param_2, uint param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_queryContainerEx(undefined4 *param_1,undefined4 *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  uint *local_4;
  
  iVar2 = xtra_encodeBER(&local_4,param_4,0);
  if (iVar2 != 0) {
    return 0x123;
  }
  if (*local_4 <= param_3) {
    return 0x11f;
  }
  puVar3 = (undefined4 *)(local_4[1] + param_3 * 0xc);
  uVar1 = puVar3[1];
  *param_1 = *puVar3;
  param_1[1] = uVar1;
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(local_4[1] + 8 + param_3 * 0xc);
  }
  return 0;
}



// ============================================================
// Function: xtra_createCertListBlock (FUN_68105910)
// Address: 68105910
// Size: 23 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_createCertListBlock(int *param_1,int param_2)
{
  xtra_writeBERBlock(param_1,(int *)0x0,8,param_2);
  return 0;
}



// ============================================================
// Function: xtra_getEncodedCount (FUN_68105930)
// Address: 68105930
// Size: 48 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getEncodedCount(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  undefined4 *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = 0;
    *param_1 = *local_4;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_getEncodedEntry (FUN_68105960)
// Address: 68105960
// Size: 98 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, uint param_4, int param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_getEncodedEntry(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,uint param_4,int param_5)

{
  int iVar1;
  uint *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_3,param_5);
  if (iVar1 == 0) {
    if (*local_4 <= param_4) {
      return 0x11f;
    }
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = *(undefined4 *)(local_4[1] + param_4 * 8);
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(local_4[1] + 4 + param_4 * 8);
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_queryContainer (FUN_681059d0)
// Address: 681059d0
// Size: 162 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, undefined4 * param_4, int param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_queryContainer(int *param_1,int *param_2,undefined4 param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  int *local_4;
  
  iVar1 = xtra_writeBERTag(param_2,(int)param_4);
  if (iVar1 == 0) {
    iVar1 = xtra_encodeBER(&local_4,param_4,param_5);
    if ((iVar1 == 0) &&
       (iVar1 = xtra_resizeBEREntry(local_4 + 1,*local_4 * 8 + 8,(int)param_4), iVar1 == 0)) {
      *(int *)(local_4[1] + *local_4 * 8) = *param_2;
      *(undefined4 *)(local_4[1] + 4 + *local_4 * 8) = param_3;
      if (param_1 != (int *)0x0) {
        *param_1 = *local_4;
      }
      *local_4 = *local_4 + 1;
    }
    else {
      xtra_detachBERNode(param_2,(int)param_4);
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_removeEncodedEntry (FUN_68105a80)
// Address: 68105a80
// Size: 140 bytes
// Params: undefined4 * param_1, uint param_2, int param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_removeEncodedEntry(undefined4 *param_1,uint param_2,int param_3)

{
  int iVar1;
  undefined4 *puVar2;
  uint *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_1,param_3);
  if (iVar1 == 0) {
    if (*local_4 <= param_2) {
      return 0x11f;
    }
    iVar1 = param_2 * 8;
    xtra_detachBERNode((int *)(local_4[1] + iVar1),(int)param_1);
    *local_4 = *local_4 - 1;
    if (param_2 < *local_4) {
      do {
        param_2 = param_2 + 1;
        puVar2 = (undefined4 *)(local_4[1] + iVar1);
        iVar1 = iVar1 + 8;
        *puVar2 = puVar2[2];
        puVar2[1] = puVar2[3];
      } while (param_2 < *local_4);
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_initCertChainInfo (FUN_68105b10)
// Address: 68105b10
// Size: 28 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initCertChainInfo(undefined4 *param_1)
{
  *param_1 = 8;
  display_fillMemory(param_1 + 1,0,0x10);
  return 0;
}



// ============================================================
// Function: xtra_addCertChainEntry (FUN_68105b30)
// Address: 68105b30
// Size: 198 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, int param_7
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_addCertChainEntry(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,int param_7)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 8);
  iVar2 = xtra_writeBERInt(piVar1,(*(int *)(param_1 + 4) * 4 + 4) * 5,param_7);
  if (iVar2 == 0) {
    *(undefined4 *)(*(int *)(param_1 + 4) * 0x14 + 8 + *piVar1) = param_4;
    iVar2 = *(int *)(param_1 + 4) * 0x14 + *piVar1;
    iVar2 = xtra_writeBERContent((int *)(iVar2 + 4),param_3,*(int *)(iVar2 + 8),param_7);
    if (iVar2 == 0) {
      *(undefined4 *)(*(int *)(param_1 + 4) * 0x14 + 0x10 + *piVar1) = param_6;
      iVar2 = *(int *)(param_1 + 4) * 0x14 + *piVar1;
      iVar2 = xtra_writeBERContent((int *)(iVar2 + 0xc),param_5,*(int *)(iVar2 + 0x10),param_7);
      if (iVar2 == 0) {
        *(undefined4 *)(*(int *)(param_1 + 4) * 0x14 + *piVar1) = 8;
        if (param_2 != (undefined4 *)0x0) {
          *param_2 = *(undefined4 *)(param_1 + 4);
        }
        iVar2 = 0;
        *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + 1;
      }
    }
  }
  return iVar2;
}



// ============================================================
// Function: xtra_verifyCertChain (FUN_68105c00)
// Address: 68105c00
// Size: 477 bytes
// Params: int param_1, int * param_2, undefined4 * param_3, uint param_4, undefined4 * param_5, undefined4 param_6, uint * param_7, int param_8, int param_9, undefined4 * param_10, undefined4 param_11
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_verifyCertChain(int param_1,int *param_2,undefined4 *param_3,uint param_4,undefined4 *param_5,
            undefined4 param_6,uint *param_7,int param_8,int param_9,undefined4 *param_10,
            undefined4 param_11)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 *local_14;
  int local_10;
  undefined4 *local_c;
  uint local_8;
  undefined4 local_4;
  
  uVar3 = 0;
  local_14 = (undefined4 *)0x0;
  if (param_7[1] != 0) {
    iVar4 = 0;
    do {
      iVar1 = xtra_compareCertFields(param_5,(undefined4 *)(param_7[2] + iVar4 + 4));
      if (iVar1 != 0) {
        puVar2 = (uint *)(uVar3 * 0x14 + param_7[2]);
        if (*puVar2 <= param_4) {
          return 0x10c;
        }
        if ((param_1 != 0) &&
           (iVar4 = xtra_verifyCertExt(param_1,param_2,puVar2 + 3,param_10), iVar4 != 0)) {
          iVar4 = xtra_decodeBERDirect("decoding TLCA public key",iVar4,0x10c,param_10);
          return iVar4;
        }
        return 0;
      }
      iVar4 = iVar4 + 0x14;
      uVar3 = uVar3 + 1;
    } while (uVar3 < param_7[1]);
  }
  if (param_4 < *param_7) {
    iVar4 = xtra_clearCertList((int *)&local_14);
    if ((((iVar4 == 0) && (iVar4 = xtra_addCertsFromStore(local_14,param_5,param_9,param_10), iVar4 == 0)) &&
        ((param_8 == 0 || (iVar4 = xtra_removeDuplicateCert(local_14,param_8,param_10), iVar4 == 0)))) &&
       ((((iVar4 = xtra_selectCertChain(&local_8,param_3,param_4,local_14,param_6,param_7,param_9,param_10,
                                param_11), iVar4 == 0 && (param_1 != 0)) &&
         (iVar4 = strftime(&local_c,&local_4,local_14,local_8), iVar4 == 0)) &&
        ((iVar4 = display_decryptFormatData(&local_10,local_c,param_10), iVar4 == 0 &&
         (iVar1 = xtra_verifyCertExt(param_1,param_2,local_10 + 0x2c,param_10), iVar1 != 0)))))) {
      iVar4 = xtra_decodeBERDirect("decoding chain certificate public key",iVar1,0x10c,param_10);
    }
    xtra_initCryptoContext((int *)&local_14);
    return iVar4;
  }
  return 0x10c;
}



// ============================================================
// Function: xtra_buildCertChainEntry (FUN_68105de0)
// Address: 68105de0
// Size: 711 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3, uint param_4, uint param_5, uint * param_6, undefined4 * param_7, undefined4 * param_8, undefined4 param_9
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_buildCertChainEntry(undefined4 *param_1,int param_2,undefined4 *param_3,uint param_4,uint param_5,
            uint *param_6,undefined4 *param_7,undefined4 *param_8,undefined4 param_9)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  char *pcVar4;
  int local_20;
  int local_1c;
  int local_18;
  undefined4 *local_14;
  uint local_10;
  undefined4 *local_c;
  int local_8 [2];
  
  local_18 = 0;
  local_14 = (undefined4 *)0x0;
  iVar1 = display_freeNetSecurity(&local_18);
  if (iVar1 != 0) {
    iVar2 = 0x100;
    goto LAB_68106083;
  }
  iVar1 = display_decryptFormatData(&local_20,param_3,param_8);
  if (iVar1 == 0) {
    iVar2 = xtra_verifyCertChain(local_18,(int *)0x0,param_1,param_2 + 1,(undefined4 *)(local_20 + 0x14),
                         param_5,param_6,local_20,(int)param_7,param_8,param_9);
    if (iVar2 != 0) goto LAB_68106083;
    if ((param_4 & 1) == 0) {
      iVar1 = display_getObjectExtension(&local_c,param_3,param_8);
      if (iVar1 == 0) {
        iVar1 = display_getObjectBlockData(local_8,param_3,param_8);
        if (iVar1 == 0) {
          iVar1 = xtra_setupCryptoMode(local_8,local_c,local_20 + 0xc,local_18,param_8,param_9);
          if (iVar1 == 0) goto LAB_68105eea;
        }
      }
      pcVar4 = "verifying certificate signature";
    }
    else {
LAB_68105eea:
      iVar1 = xtra_createContainerEx(param_3,param_4,param_7,param_8);
      if (iVar1 != 0) {
        iVar2 = xtra_readBERValue("inserting selected certificate",iVar1,param_8);
        if (iVar2 != 0) goto LAB_68106083;
      }
      iVar2 = xtra_createCryptoReader((int *)&local_14);
      if (iVar2 != 0) goto LAB_68106083;
      if (*(uint *)(local_20 + 0x20) < param_5) {
        iVar2 = xtra_selectCRL(&local_1c,&local_10,(undefined4 *)(local_20 + 0x14),
                             (undefined4 *)(local_20 + 4),local_18,*(uint *)(local_20 + 0x20),
                             local_14,(int)param_7,param_8,param_9);
        if (iVar2 != 0) goto LAB_68106083;
        bVar3 = local_1c != 5;
        if (local_1c != 6) {
          local_1c = 3;
LAB_68106013:
          local_10 = *(uint *)(local_20 + 0x20);
        }
      }
      else {
        iVar2 = xtra_selectCRL(&local_1c,&local_10,(undefined4 *)(local_20 + 0x14),
                             (undefined4 *)(local_20 + 4),local_18,param_5,local_14,(int)param_7,
                             param_8,param_9);
        if (iVar2 != 0) goto LAB_68106083;
        bVar3 = local_1c != 5;
        if (local_1c != 6) {
          if (param_5 < *(uint *)(local_20 + 0x1c)) {
            local_1c = 2;
            local_10 = *(uint *)(local_20 + 0x1c);
          }
          else if ((local_1c == 5) || (local_1c == 1)) goto LAB_68106013;
        }
      }
      iVar2 = xtra_insertCertEntry(param_1,param_3,local_1c,local_10,
                           (undefined4 *)(!bVar3 - 1 & (uint)local_14),param_8);
      if (iVar2 != 0) goto LAB_68106083;
      if ((code *)param_6[3] == (code *)0x0) goto LAB_68106083;
      iVar1 = (*(code *)param_6[3])(param_1,param_6[4],param_8);
      iVar2 = 0;
      if (iVar1 == 0) goto LAB_68106083;
      pcVar4 = "checking certificate constraint";
    }
  }
  else {
    pcVar4 = "reading chain certificate";
  }
  iVar2 = xtra_decodeBER(pcVar4,iVar1,0x10c,param_8);
LAB_68106083:
  xtra_initCryptoContext((int *)&local_14);
  display_releaseNetSecurity(&local_18);
  return iVar2;
}



// ============================================================
// Function: xtra_insertDefaultCertEntry (FUN_681060b0)
// Address: 681060b0
// Size: 49 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_insertDefaultCertEntry(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)
{
  uint local_4;
  
  display_freeFormatState((int *)&local_4);
  xtra_insertCertEntry(param_1,param_2,1,local_4,(undefined4 *)0x0,param_3);
  return 0;
}



// ============================================================
// Function: xtra_initContainer (FUN_681060f0)
// Address: 681060f0
// Size: 23 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initContainer(int *param_1)
{
  xtra_writeBERBlock(param_1,(int *)0x0,0x10,0x68106b20);
  return 0;
}



// ============================================================
// Function: xtra_getCertChainInfo (FUN_68106110)
// Address: 68106110
// Size: 111 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getCertChainInfo(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_3,0x68106b20);
  if (iVar1 == 0) {
    if (param_1 != (int *)0x0) {
      if (*local_4 == 0) {
        *param_1 = 1;
      }
      else {
        *param_1 = local_4[1];
      }
    }
    if (param_2 != (int *)0x0) {
      if (*local_4 == 0) {
        display_freeFormatState(param_2);
        return 0;
      }
      *param_2 = local_4[2];
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_getCertListEntry (FUN_68106180)
// Address: 68106180
// Size: 82 bytes
// Params: undefined4 * param_1, undefined4 * param_2, uint param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getCertListEntry(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_2,0x68106b20);
  if (iVar1 == 0) {
    if (*local_4 <= param_3) {
      return 0x11f;
    }
    *param_1 = *(undefined4 *)(local_4[3] + param_3 * 0x1c);
    iVar1 = 0;
  }
  return iVar1;
}



