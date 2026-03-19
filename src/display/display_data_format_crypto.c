// Module: display
// Topic: Data format codec, crypto, hash, and low-level utility functions
// Address range: 0x680fc5b0 - 0x680ff940
// Functions (96):
//   display_loadFormatData
//   display_processNetSecurityOp
//   display_initFormatContext
//   display_getFormatRef
//   display_dispatchCryptoOp
//   display_dispatchCryptoOpEx
//   display_buildCertSequence
//   display_initContainerFormat
//   display_resolveEncoder
//   display_decryptBlock
//   display_writeBerContent
//   display_encryptBlock
//   display_decryptBlockEx
//   display_registerHandler
//   display_lookupHandler
//   display_resolveOrCreateFormat
//   display_addFormatEntry
//   display_processFieldEntry
//   display_matchFormatEncoding
//   display_fillMemory
//   display_checkAndFree
//   display_allocFormatBlock
//   display_decodeFormat
//   display_allocBlock
//   display_freeIfNonNull
//   display_freeFormatState
//   display_freeFormatBlock
//   display_resetFormatState
//   display_copyFormatData
//   display_copyAndCreateObject
//   display_buildObjectBlock
//   display_getObjectBlockData
//   display_decryptFormatData
//   display_getObjectExtension
//   display_getObjectUserData
//   display_processFormatEx
//   display_initCryptoState
//   display_getEncodedPair
//   display_dispatchFormatOp
//   display_createDecryptBlock
//   display_allocCertChain
//   display_findCertByField
//   display_releaseFormatData
//   display_selectCertEntry
//   display_getEncodedCount
//   display_getCertChainCount
//   display_getEncodedEntry
//   display_getCertChainEntry
//   display_removeAllCertEntries
//   display_buildCertChainVerified
//   display_setCertExtensions
//   display_parseFormatBlock
//   display_createCertBlock
//   display_addDefaultCertEntry
//   display_freeCertBlockInner
//   display_freeCertBlockFull
//   display_resetCertCryptoCtx
//   display_addCertChainData
//   display_readStreamLine
//   display_writeCryptoStream (FUN_680fe620)
//   display_readCryptoBlock (FUN_680fe680)
//   display_writeStreamBlock
//   display_seekStreamStart
//   display_initCryptoVtable (FUN_680fe740)
//   display_getFormatInfo
//   display_hashCryptoBlock
//   display_searchFormatList
//   display_copyToFixedBuffer
//   display_extractKeyFromChain
//   display_addFormatListEntry
//   display_addContainerListItem
//   display_searchSubList
//   display_addSubListEntry
//   display_addContainerSubItem
//   display_searchExtList
//   display_addExtListEntry
//   display_replaceExtListEntry
//   display_getContainerPayload
//   display_collectContainerData
//   display_getSubListData
//   display_readExtListData
//   display_initContainerVtable
//   display_freeAllLists
//   display_getListItemData
//   display_processPKCS7Envelope
//   display_initMD5State
//   display_updateMD5
//   display_finalizeMD5
//   display_encodeLE32
//   display_resetMD2State
//   display_updateMD2
//   display_finalizeMD2
//   display_md2Transform
//   display_initMD5Context
//   display_updateMD5Context
//   display_finalizeMD5Context


// ============================================================
// Function: display_loadFormatData (FUN_680fc5b0)
// Address: 680fc5b0
// Size: 71 bytes
// Params: int param_1, undefined * param_2, undefined4 param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_loadFormatData(int param_1,undefined *param_2,undefined4 param_3)

{
  int local_14;
  int iVar1;
  undefined **local_4;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    iVar1 = (*(code *)param_2)(&local_4);
    if (iVar1 != 0) {
      return 0x213;
    }
    iVar1 = xtra_bindCertHandler(param_1,local_4,param_3);
  }
  return iVar1;
}



// ============================================================
// Function: display_processNetSecurityOp (FUN_680fc600)
// Address: 680fc600
// Size: 71 bytes
// Params: int * param_1, int * param_2, undefined * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_processNetSecurityOp(int *param_1,int *param_2,undefined *param_3)

{
  int iVar1;
  int *local_4;
  
  iVar1 = display_initFormatContext((int)param_2);
  if (iVar1 == 0) {
    iVar1 = (*(code *)param_3)(&local_4);
    if (iVar1 != 0) {
      return 0x213;
    }
    iVar1 = xtra_readCertChainCached(param_2,param_1,local_4);
  }
  return iVar1;
}



// ============================================================
// Function: display_initFormatContext (FUN_680fc650)
// Address: 680fc650
// Size: 31 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_initFormatContext(int param_1)

{
  if (((param_1 != 0) && (*(int *)(param_1 + 0x20) == param_1)) &&
     (*(undefined **)(param_1 + 0x1c) == &DAT_6818ea14)) {
    return 0;
  }
  return 0x204;
}



// ============================================================
// Function: display_getFormatRef (FUN_680fc670)
// Address: 680fc670
// Size: 37 bytes
// Params: int param_1
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl display_getFormatRef(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = display_initFormatContext(param_1);
  return (iVar1 == 0) - 1 & 0x21b;
}



// ============================================================
// Function: display_dispatchCryptoOp (FUN_680fc6a0)
// Address: 680fc6a0
// Size: 44 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_dispatchCryptoOp(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    xtra_dispatchCryptoOp3(param_1,param_2,param_3,param_4);
  }
  return 0;
}



// ============================================================
// Function: display_dispatchCryptoOpEx (FUN_680fc6d0)
// Address: 680fc6d0
// Size: 64 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_dispatchCryptoOpEx(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    uVar2 = display_getFormatRef(param_4);
    if (uVar2 == 0) {
      xtra_dispatchCryptoOp4(param_1,param_2,param_3,param_4,param_5);
    }
  }
  return 0;
}



// ============================================================
// Function: display_buildCertSequence (FUN_680fc7e0)
// Address: 680fc7e0
// Size: 200 bytes
// Params: int * param_1, int * param_2
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl display_buildCertSequence(int *param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int local_18;
  int local_14 [2];
  undefined1 local_c [4];
  int local_8;
  int local_4;
  
  uVar2 = xtra_readCertChain(param_2,&local_18,0x6818efd8);
  if (uVar2 == 0) {
    uVar2 = xtra_readCertBlock(param_2,param_1,8);
    if (uVar2 == 0) {
      piVar1 = (int *)*param_1;
      local_14[0] = 0;
      display_fillMemory(local_c,0,0xc);
      local_8 = local_18;
      local_4 = local_18 + 8;
      uVar2 = xtra_writeBERSequence(local_14,(uint *)&DAT_6818ea20,(int)local_c);
      if (uVar2 == 0) {
        uVar2 = xtra_writeBERPair(piVar1,&PTR_DAT_6818ea78,&PTR_DAT_6818eff0,local_14);
        if (uVar2 == 0) {
          uVar2 = xtra_readCertBlockEx(param_2,piVar1,piVar1[1]);
        }
      }
      display_freeIfNonNull(local_14[0]);
    }
  }
  return uVar2;
}



// ============================================================
// Function: display_initContainerFormat (FUN_680fc8c0)
// Address: 680fc8c0
// Size: 60 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_initContainerFormat(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = xtra_initContainer(param_1);
  if ((iVar1 == 0) && (iVar1 = display_writeBerContent((undefined4 *)*param_1,param_2,param_3), iVar1 != 0)) {
    display_releaseFormatData(param_1);
  }
  return iVar1;
}



// ============================================================
// Function: display_resolveEncoder (FUN_680fc900)
// Address: 680fc900
// Size: 207 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_resolveEncoder(int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *local_c;
  int local_8;
  int iStack_4;
  
  iVar1 = xtra_encodeBER(&local_c,param_3,0x68106b20);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x12a,param_4);
    return iVar1;
  }
  iVar1 = 0;
  if ((*local_c == 0) && (uVar3 = 0, local_c[2] != 0)) {
    do {
      iVar2 = (**(code **)(local_c[3] + iVar1))
                        (&local_8,((undefined4 *)(local_c[3] + iVar1))[1],param_3,param_4);
      if (iVar2 == 0) {
        *local_c = local_8;
        local_c[1] = iStack_4;
        break;
      }
      if (iVar2 != 0x12e) {
        return iVar2;
      }
      iVar1 = iVar1 + 8;
      uVar3 = uVar3 + 1;
    } while (uVar3 < (uint)local_c[2]);
  }
  if (*local_c != 0) {
    *param_1 = *local_c;
    *param_2 = local_c[1];
    return 0;
  }
  return 0x12a;
}



// ============================================================
// Function: display_decryptBlock (FUN_680fc9d0)
// Address: 680fc9d0
// Size: 155 bytes
// Params: undefined4 * param_1, byte * param_2, uint param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_decryptBlock(undefined4 *param_1,byte *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int *local_c;
  int local_8;
  size_t local_4;
  
  iVar1 = xtra_encodeBER(&local_c,param_1,0x68106b20);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x12a,param_4);
    return iVar1;
  }
  iVar1 = xtra_readCertFieldEx(&local_8,(uint *)&DAT_6818ea90,0,param_2,param_3);
  if (iVar1 == 0) {
    iVar1 = xtra_writeBERBytes(&local_8,local_4,(int)param_1);
    if (iVar1 == 0) {
      xtra_freeObjectBlock(param_1,local_8);
      *local_c = local_8;
      local_c[1] = local_4;
      iVar1 = 0;
    }
  }
  return iVar1;
}



// ============================================================
// Function: display_writeBerContent (FUN_680fca70)
// Address: 680fca70
// Size: 133 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_writeBerContent(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int *local_8;
  int local_4;
  
  iVar1 = xtra_encodeBER(&local_8,param_1,0x68106b20);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x12a,param_3);
    return iVar1;
  }
  iVar1 = xtra_writeBERContent(&local_4,*param_2,param_2[1],(int)param_1);
  if (iVar1 == 0) {
    xtra_freeObjectBlock(param_1,local_4);
    *local_8 = local_4;
    iVar1 = 0;
    local_8[1] = param_2[1];
  }
  return iVar1;
}



// ============================================================
// Function: display_encryptBlock (FUN_680fcb00)
// Address: 680fcb00
// Size: 77 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_encryptBlock(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *local_8;
  undefined4 *local_4;
  
  iVar1 = display_resolveOrCreateFormat((int *)&local_4,param_2,0,param_3);
  if (iVar1 == 0) {
    iVar1 = xtra_encodeBER(&local_8,local_4,0x68106b20);
    if (iVar1 == 0) {
      iVar1 = 0;
      *param_1 = *local_8;
    }
  }
  return iVar1;
}



// ============================================================
// Function: display_decryptBlockEx (FUN_680fcb50)
// Address: 680fcb50
// Size: 181 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5, undefined4 * param_6, undefined4 * param_7, uint param_8, undefined4 * param_9
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_decryptBlockEx(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 *param_7,uint param_8,
            undefined4 *param_9)

{
  int iVar1;
  uint *local_8;
  undefined4 *local_4;
  
  iVar1 = display_resolveOrCreateFormat((int *)&local_4,param_7,0,param_9);
  if (iVar1 == 0) {
    iVar1 = xtra_encodeBER(&local_8,local_4,0x68106b20);
    if (iVar1 == 0) {
      if (*local_8 <= param_8) {
        return 0x11f;
      }
      local_8 = local_8 + 1;
      iVar1 = param_8 * 0x18;
      *param_1 = *(undefined4 *)(*local_8 + iVar1);
      *param_2 = *(undefined4 *)(*local_8 + 4 + iVar1);
      *param_3 = *(undefined4 *)(*local_8 + 8 + iVar1);
      *param_4 = *(undefined4 *)(*local_8 + 0xc + iVar1);
      *param_5 = *(undefined4 *)(*local_8 + 0x10 + iVar1);
      *param_6 = *(undefined4 *)(*local_8 + 0x14 + iVar1);
      iVar1 = 0;
    }
  }
  return iVar1;
}



// ============================================================
// Function: display_registerHandler (FUN_680fcc10)
// Address: 680fcc10
// Size: 156 bytes
// Params: undefined4 * param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_registerHandler(undefined4 *param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int local_4;
  
  iVar2 = xtra_encodeBER(&local_4,param_1,0x68106b20);
  if (iVar2 == 0) {
    uVar4 = 0;
    uVar1 = *(uint *)(local_4 + 8);
    if (uVar1 != 0) {
      piVar3 = *(int **)(local_4 + 0xc);
      do {
        if (*piVar3 == param_2) {
          return 0x12a;
        }
        piVar3 = piVar3 + 2;
        uVar4 = uVar4 + 1;
      } while (uVar4 < uVar1);
    }
    iVar2 = xtra_writeBERInt((int *)(local_4 + 0xc),uVar1 * 8 + 8,(int)param_1);
    if (iVar2 == 0) {
      *(int *)(*(int *)(local_4 + 0xc) + *(int *)(local_4 + 8) * 8) = param_2;
      *(undefined4 *)(*(int *)(local_4 + 0xc) + 4 + *(int *)(local_4 + 8) * 8) = param_3;
      *(int *)(local_4 + 8) = *(int *)(local_4 + 8) + 1;
      iVar2 = 0;
    }
  }
  return iVar2;
}



// ============================================================
// Function: display_lookupHandler (FUN_680fccb0)
// Address: 680fccb0
// Size: 125 bytes
// Params: int * param_1, undefined4 * param_2, int param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_lookupHandler(int *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_2,0x68106b20);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x12a,param_4);
    return iVar1;
  }
  uVar3 = 0;
  if (*(uint *)(local_4 + 8) != 0) {
    piVar2 = *(int **)(local_4 + 0xc);
    do {
      if (*piVar2 == param_3) {
        *param_1 = (*(int **)(local_4 + 0xc))[uVar3 * 2 + 1];
        return 0;
      }
      piVar2 = piVar2 + 2;
      uVar3 = uVar3 + 1;
    } while (uVar3 < *(uint *)(local_4 + 8));
  }
  return 300;
}




// ============================================================
// Function: display_resolveOrCreateFormat (FUN_680fcdd0)
// Address: 680fcdd0
// Size: 342 bytes
// Params: int * param_1, undefined4 * param_2, int param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int __cdecl display_resolveOrCreateFormat(int *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  /* FIXUP: removed duplicate local_18 and local_2c */
  int iVar1;
  byte *local_38;
  uint local_34;
  int local_30;
  uint local_2c [2];
  undefined1 local_24 [8];
  int local_1c;
  undefined1 local_18 [8];
  uint *local_10;
  uint *local_c;
  undefined1 *local_8;
  uint *local_4;
  
  iVar1 = display_lookupHandler(param_1,param_2,0x680fcd30,param_4);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else if (iVar1 == 300) {
    iVar1 = display_resolveEncoder(&local_30,(int *)local_2c,param_2,param_4);
    if (iVar1 == 0) {
      iVar1 = xtra_writeBERData(param_1,(int *)0x0,8,(int)param_2,0x68106b20);
      if (iVar1 == 0) {
        local_34 = local_2c[0];
        iVar1 = xtra_writeBERContent((int *)&local_38,local_30,local_2c[0],*param_1);
        if (iVar1 == 0) {
          display_fillMemory(local_18,0,0x18);
          local_10 = local_2c + 1;
          local_1c = *param_1;
          local_8 = local_24;
          local_2c[1] = 1;
          local_c = local_10;
          local_4 = local_10;
          iVar1 = xtra_writeCertData((uint *)0x0,(uint *)&DAT_6818ea90,(int)local_18,local_38,local_34);
          if (iVar1 == 0) {
            iVar1 = display_registerHandler(param_2,0x680fcd30,*param_1);
            return iVar1;
          }
        }
      }
    }
    else if ((iVar1 == 0x12a) && (param_3 != 0)) {
      xtra_resetBERReader(param_2);
      iVar1 = xtra_writeBERData(param_1,(int *)0x0,8,(int)param_2,0x68106b20);
      if (iVar1 == 0) {
        iVar1 = display_registerHandler(param_2,0x680fcd30,*param_1);
        return iVar1;
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: display_addFormatEntry (FUN_680fcf30)
// Address: 680fcf30
// Size: 292 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, int param_5, int param_6, uint param_7, undefined4 param_8
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_addFormatEntry(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,int param_5,
            int param_6,uint param_7,undefined4 param_8)

{
  int iVar1;
  int *local_4;
  
  if ((param_5 == 0x13) && (iVar1 = xtra_validatePrintableString(param_6,param_7), iVar1 == 0)) {
    return 0x107;
  }
  iVar1 = xtra_encodeBER(&local_4,param_2,0x68106b20);
  if ((iVar1 == 0) &&
     (iVar1 = xtra_writeBERInt(local_4 + 1,(*local_4 * 3 + 3) * 8,(int)param_2), iVar1 == 0)) {
    *(undefined4 *)(local_4[1] + *local_4 * 0x18) = param_3;
    *(undefined4 *)(local_4[1] + 4 + *local_4 * 0x18) = param_4;
    *(int *)(local_4[1] + 8 + *local_4 * 0x18) = param_5;
    *(int *)(local_4[1] + 0xc + *local_4 * 0x18) = param_6;
    *(uint *)(local_4[1] + 0x10 + *local_4 * 0x18) = param_7;
    if (*local_4 == 0) {
      *(undefined4 *)(local_4[1] + 0x14) = 1;
    }
    else {
      *(undefined4 *)(local_4[1] + 0x14 + *local_4 * 0x18) = param_8;
    }
    if (param_1 != (int *)0x0) {
      *param_1 = *local_4;
    }
    *local_4 = *local_4 + 1;
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: display_processFieldEntry (FUN_680fd080)
// Address: 680fd080
// Size: 102 bytes
// Params: uint * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_processFieldEntry(uint *param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 local_4;
  
  iVar1 = display_matchFormatEncoding(&local_4,(byte *)param_2[1],param_2[2],*param_1,param_1[3]);
  if (iVar1 != 0) {
    if (iVar1 != 300) {
      return 0;
    }
    local_4 = param_2[1];
  }
  display_addFormatEntry((int *)0x0,(undefined4 *)param_2[3],local_4,param_2[2],*param_1,param_1[2],param_1[3]
               ,*param_2);
  return 0;
}



// ============================================================
// Function: display_matchFormatEncoding (FUN_680fd1e0)
// Address: 680fd1e0
// Size: 244 bytes
// Params: undefined4 * param_1, byte * param_2, uint param_3, uint param_4, uint param_5
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
display_matchFormatEncoding(undefined4 *param_1,byte *param_2,uint param_3,uint param_4,uint param_5)

{
  undefined *puVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  
  if ((param_4 == 0x1f) || ((param_4 & 0x20) != 0)) {
    return 0x105;
  }
  uVar4 = 0;
  if (DAT_6818eba0 != 0) {
    puVar3 = &DAT_6818eb2c;
    do {
      if (*puVar3 == param_3) {
        uVar2 = display_decodeFormat(param_2,(byte *)puVar3[-1],param_3);
        if (uVar2 == 0) {
          puVar1 = (&PTR_DAT_6818eb28)[uVar4 * 3];
          *param_1 = puVar1;
          if (puVar1 == &DAT_6818eaf0) {
            if (param_4 != 0x13) {
              return 0x105;
            }
            if (param_5 != 2) {
              return 0x108;
            }
          }
          else if (puVar1 == &DAT_6818eb18) {
            if (param_4 != 0x16) {
              return 0x105;
            }
          }
          else {
            if ((param_4 != 0x13) && (param_4 != 0x14)) {
              return 0x105;
            }
            if ((param_5 == 0) || ((uint)(&DAT_6818eb30)[uVar4 * 3] < param_5)) {
              return 0x108;
            }
          }
          return 0;
        }
      }
      puVar3 = puVar3 + 3;
      uVar4 = uVar4 + 1;
    } while (uVar4 < DAT_6818eba0);
  }
  return 300;
}



// ============================================================
// Function: display_fillMemory (FUN_680fd2e0)
// Address: 680fd2e0
// Size: 29 bytes
// Params: void *dest, int value, size_t size
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_fillMemory(void *dest,int value,size_t size)
{
  if (size != 0) {
    memset(dest, value, size);
  }
  return 0;
}



// ============================================================
// Function: display_checkAndFree (FUN_680fd300)
// Address: 680fd300
// Size: 26 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_checkAndFree(undefined4 param_1,undefined4 param_2,int param_3)
{
  if (param_3 != 0) {
    Ordinal_1128(param_1,param_2,param_3);
  }
  return 0;
}



// ============================================================
// Function: display_allocFormatBlock (FUN_680fd320)
// Address: 680fd320
// Size: 26 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_allocFormatBlock(undefined4 param_1,undefined4 param_2,int param_3)
{
  if (param_3 != 0) {
    Ordinal_1129(param_1,param_2,param_3);
  }
  return 0;
}



// ============================================================
// Function: display_decodeFormat (FUN_680fd340)
// Address: 680fd340
// Size: 131 bytes
// Params: byte * param_1, byte * param_2, uint param_3
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl display_decodeFormat(byte *param_1,byte *param_2,uint param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    return 0;
  }
  for (; 3 < param_3; param_3 = param_3 - 4) {
    if (*(int *)param_1 != *(int *)param_2) goto LAB_680fd378;
    param_2 = param_2 + 4;
    param_1 = param_1 + 4;
  }
  if (param_3 == 0) {
    return 0;
  }
LAB_680fd378:
  iVar1 = (uint)*param_1 - (uint)*param_2;
  if (iVar1 == 0) {
    if (param_3 < 2) {
      return 0;
    }
    iVar1 = (uint)param_1[1] - (uint)param_2[1];
    if (iVar1 == 0) {
      if (param_3 < 3) {
        return 0;
      }
      iVar1 = (uint)param_1[2] - (uint)param_2[2];
      if (iVar1 == 0) {
        if (param_3 < 4) {
          return 0;
        }
        iVar1 = (uint)param_1[3] - (uint)param_2[3];
      }
    }
  }
  return iVar1 >> 0x1f | 1;
}



// ============================================================
// Function: display_allocBlock (display_allocBlock)
// Address: 680fd3d0
// Size: 14 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_allocBlock(undefined4 param_1)
{
  Ordinal_1124(param_1);
  return 0;
}



// ============================================================
// Function: display_freeIfNonNull (FUN_680fd3e0)
// Address: 680fd3e0
// Size: 24 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_freeIfNonNull(int param_1)
{
  if (param_1 != 0) {
    Ordinal_1125(&param_1);
  }
  return 0;
}



// ============================================================
// Function: display_freeFormatState (FUN_680fd400)
// Address: 680fd400
// Size: 20 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_freeFormatState(int *param_1)
{
  int iVar1;
  
  iVar1 = Ordinal_1542();
  *param_1 = iVar1 + 0x7c543000;
  return 0;
}



// ============================================================
// Function: display_freeFormatBlock (FUN_680fd420)
// Address: 680fd420
// Size: 85 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_freeFormatBlock(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    iVar1 = display_allocBlock(param_2);
    return iVar1;
  }
  iVar1 = display_allocBlock(param_2);
  if (iVar1 != 0) {
    uVar2 = Ordinal_1137(param_1);
    if (param_2 <= uVar2) {
      uVar2 = param_2;
    }
    display_checkAndFree(iVar1,param_1,uVar2);
  }
  display_freeIfNonNull(param_1);
  return iVar1;
}



// ============================================================
// Function: display_resetFormatState (FUN_680fd480)
// Address: 680fd480
// Size: 19 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_resetFormatState(int *param_1)
{
  xtra_createObjectDataBlock(param_1,(int *)&PTR_FUN_6818ee70);
  return 0;
}



// ============================================================
// Function: display_copyFormatData (FUN_680fd4a0)
// Address: 680fd4a0
// Size: 145 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_copyFormatData(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int local_44 [2];
  undefined1 local_3c [8];
  undefined *local_34;
  
  display_fillMemory(local_3c,0,0x3c);
  local_34 = &DAT_6818eba8;
  iVar1 = xtra_readCertFieldEx(local_44,(uint *)&DAT_6818ebb0,(int)local_3c,(byte *)*param_2,param_2[1]);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x10d,param_3);
    return iVar1;
  }
  iVar1 = xtra_createObjectBlock(param_1,local_44,(int *)&PTR_FUN_6818ee70,param_3);
  if (iVar1 != 0) {
    iVar1 = display_processFormatEx(iVar1,param_3);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: display_copyAndCreateObject (FUN_680fd540)
// Address: 680fd540
// Size: 116 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_copyAndCreateObject(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_8;
  int local_4;
  
  local_8 = display_allocBlock(param_2[1]);
  if (local_8 == 0) {
    return 0x100;
  }
  local_4 = param_2[1];
  display_checkAndFree(local_8,*param_2,local_4);
  iVar1 = xtra_createObjectBlock(param_1,&local_8,(int *)&PTR_FUN_6818ee70,param_3);
  if (iVar1 != 0) {
    uVar2 = display_processFormatEx(iVar1,param_3);
    return uVar2;
  }
  return 0;
}




// ============================================================
// Function: display_buildObjectBlock (FUN_680fd5c0)
// Address: 680fd5c0
// Size: 49 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_buildObjectBlock(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_buildObjectBlock(param_1,param_2,(int *)&PTR_FUN_6818ee70,param_3);
  if (iVar1 != 0) {
    uVar2 = display_processFormatEx(iVar1,param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: display_getObjectBlockData (FUN_680fd600)
// Address: 680fd600
// Size: 49 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_getObjectBlockData(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_getObjectBlockData(param_1,param_2,(int *)&PTR_FUN_6818ee70,param_3);
  if (iVar1 != 0) {
    uVar2 = display_processFormatEx(iVar1,param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: display_decryptFormatData (FUN_680fd640)
// Address: 680fd640
// Size: 49 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_decryptFormatData(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_getObjectDerivedData(param_1,param_2,(int *)&PTR_FUN_6818ee70,param_3);
  if (iVar1 != 0) {
    uVar2 = display_processFormatEx(iVar1,param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: display_getObjectExtension (FUN_680fd680)
// Address: 680fd680
// Size: 45 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_getObjectExtension(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_getObjectExtension(param_1,param_2,(int *)&PTR_FUN_6818ee70);
  if (iVar1 != 0) {
    uVar2 = display_processFormatEx(iVar1,param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: display_getObjectUserData (FUN_680fd6b0)
// Address: 680fd6b0
// Size: 45 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_getObjectUserData(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_getObjectUserData(param_1,param_2,(int *)&PTR_FUN_6818ee70);
  if (iVar1 != 0) {
    uVar2 = display_processFormatEx(iVar1,param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: display_processFormatEx (FUN_680fd6e0)
// Address: 680fd6e0
// Size: 56 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_processFormatEx(int param_1,undefined4 *param_2)
{
  if (param_1 == 0x124) {
    xtra_decodeBER(&DAT_6818eba4,0x124,0x10e,param_2);
    return 0;
  }
  xtra_decodeBER(&DAT_6818eba4,param_1,0x10d,param_2);
  return 0;
}



// ============================================================
// Function: display_initCryptoState (FUN_680fd920)
// Address: 680fd920
// Size: 706 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_initCryptoState(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *local_c;
  undefined2 *local_8;
  int *local_4;
  
  iVar1 = display_getObjectUserData((int *)&local_4,param_2,param_3);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*local_4 == 0) {
    iVar1 = display_decryptFormatData(&local_8,param_2,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = xtra_writeBERData(local_4,(int *)&local_c,0x44,(int)param_2,0x680fdbf0);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = xtra_createContainerInstance(local_c + 0x10);
    if (iVar1 != 0) {
      return iVar1;
    }
    *(undefined2 *)local_c = *local_8;
    local_c[2] = *(undefined4 *)(local_8 + 4);
    iVar1 = xtra_writeBERContent(local_c + 1,*(undefined4 *)(local_8 + 2),local_c[2],*local_4);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = xtra_resolveEncryptAlgorithm(local_c + 3,local_8 + 6,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = xtra_attachCryptoKey(local_c + 4,(undefined4 *)(local_8 + 10),*local_4,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    local_c[5] = *(undefined4 *)(local_8 + 0xe);
    local_c[6] = *(undefined4 *)(local_8 + 0x10);
    iVar1 = xtra_attachCryptoKey(local_c + 7,(undefined4 *)(local_8 + 0x12),*local_4,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    local_c[9] = *(undefined4 *)(local_8 + 0x18);
    iVar1 = xtra_writeBERContent(local_c + 8,*(undefined4 *)(local_8 + 0x16),local_c[9],*local_4);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (*(int *)(local_8 + 0x1a) == 0) {
      local_c[10] = 0;
      local_c[0xb] = 0;
      local_c[0xc] = 0;
    }
    else {
      local_c[0xb] = *(undefined4 *)(local_8 + 0x1c);
      iVar1 = xtra_writeBERContent(local_c + 10,*(undefined4 *)(local_8 + 0x1a),local_c[0xb],*local_4);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    if (*(int *)(local_8 + 0x20) == 0) {
      local_c[0xd] = 0;
      local_c[0xe] = 0;
      local_c[0xf] = 0;
    }
    else {
      local_c[0xe] = *(undefined4 *)(local_8 + 0x22);
      iVar1 = xtra_writeBERContent(local_c + 0xd,*(undefined4 *)(local_8 + 0x20),local_c[0xe],*local_4);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    if ((*(int *)(local_8 + 0x26) != 0) &&
       (iVar1 = xtra_insertContainerData(local_c[0x10],(undefined4 *)(local_8 + 0x26)), iVar1 != 0)) {
      return iVar1;
    }
  }
  iVar1 = xtra_encodeBER(&local_c,(undefined4 *)*local_4,0x680fdbf0);
  if (iVar1 == 0) {
    for (iVar1 = 0x11; iVar1 != 0; iVar1 = iVar1 + -1) {
      *param_1 = *local_c;
      local_c = local_c + 1;
      param_1 = param_1 + 1;
    }
    return 0;
  }
  iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x10e,param_3);
  return iVar1;
}



// ============================================================
// Function: display_getEncodedPair (FUN_680fdc10)
// Address: 680fdc10
// Size: 67 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_getEncodedPair(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_3,0x68106b20);
  if (iVar1 != 0) {
    return 0x10f;
  }
  *param_1 = *(undefined4 *)(local_4 + 8);
  *param_2 = *(undefined4 *)(local_4 + 0xc);
  return 0;
}



// ============================================================
// Function: display_dispatchFormatOp (FUN_680fdc60)
// Address: 680fdc60
// Size: 288 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_dispatchFormatOp(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *local_10;
  code *local_c;
  undefined4 local_8;
  int local_4;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  iVar1 = display_getEncodedPair(&local_c,&local_8,param_1);
  if (iVar1 == 0) {
    if (local_c == (code *)0x0) {
      iVar1 = display_createDecryptBlock(&local_4,param_2,param_3,param_4);
      if (iVar1 == 0) {
        iVar1 = xtra_queryContainer((int *)0x0,&local_4,0,param_1,0x68106b20);
        if (iVar1 != 0) {
          iVar2 = 0x10f;
          if (iVar1 != 0x124) {
            iVar2 = iVar1;
          }
          return iVar2;
        }
        return 0;
      }
    }
    else {
      local_10 = (undefined4 *)0x0;
      iVar1 = xtra_initContainer((int *)&local_10);
      if (iVar1 == 0) {
        iVar1 = display_decryptBlock(local_10,(byte *)*param_2,param_2[1],param_4);
        if (iVar1 == 0) {
          iVar2 = (*local_c)(local_10,*param_3,param_3[1],local_8,param_4);
          iVar1 = 0;
          if (iVar2 != 0) {
            iVar1 = xtra_decodeBER("calling co set log function",iVar2,0x10f,param_4);
          }
        }
      }
      display_releaseFormatData((int *)&local_10);
    }
  }
  return iVar1;
}



// ============================================================
// Function: display_createDecryptBlock (FUN_680fdd80)
// Address: 680fdd80
// Size: 195 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_createDecryptBlock(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int *local_4;
  
  iVar1 = xtra_writeBERBlock(param_1,(int *)&local_4,0xc,0);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = xtra_initContainer(local_4);
  if (iVar1 == 0) {
    iVar1 = display_decryptBlock((undefined4 *)*local_4,(byte *)*param_2,param_2[1],param_4);
    if (iVar1 == 0) {
      iVar1 = xtra_writeBERTag(local_4,*param_1);
      if (iVar1 != 0) goto LAB_680fde32;
      local_4[2] = param_3[1];
      iVar1 = xtra_writeBERContent(local_4 + 1,*param_3,local_4[2],*param_1);
    }
    else {
      display_releaseFormatData(local_4);
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
LAB_680fde32:
  xtra_resetBER(param_1);
  return iVar1;
}



// ============================================================
// Function: display_allocCertChain (FUN_680fde50)
// Address: 680fde50
// Size: 54 bytes
// Params: int * param_1
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_allocCertChain(int *param_1)

{
  int iVar1;
  int local_4;
  
  iVar1 = xtra_writeBERBlock(param_1,&local_4,0x34,0x680fe500);
  if (iVar1 == 0) {
    xtra_initCertChainInfo((undefined4 *)(local_4 + 8));
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: display_findCertByField (FUN_680fde90)
// Address: 680fde90
// Size: 218 bytes
// Params: uint * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl
display_findCertByField(uint *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  undefined4 *local_1c;
  undefined4 *local_18;
  uint local_14;
  undefined4 local_10;
  undefined4 local_c;
  int local_8;
  int local_4;
  
  uVar1 = display_getEncodedCount(&local_14,param_2);
  if (uVar1 == 0) {
    uVar1 = 0;
    if (local_14 != 0) {
      do {
        uVar2 = display_getEncodedEntry(&local_18,param_2,uVar1);
        if (uVar2 != 0) {
          return uVar2;
        }
        uVar2 = xtra_getCertEntry(&local_1c,&local_10,&local_c,(undefined4 *)*local_18,0,param_5);
        if (uVar2 != 0) {
          return uVar2;
        }
        uVar2 = display_resolveEncoder(&local_8,&local_4,local_1c,param_5);
        if (uVar2 != 0) {
          return uVar2;
        }
        iVar3 = xtra_compareCertFields(param_3,&local_8);
        if ((iVar3 != 0) && (iVar3 = xtra_compareCertFields(param_4,&local_10), iVar3 != 0)) {
          *param_1 = uVar1;
          return 0;
        }
        uVar1 = uVar1 + 1;
      } while (uVar1 < local_14);
    }
    uVar1 = 300;
  }
  return uVar1;
}



// ============================================================
// Function: display_releaseFormatData (FUN_680fdf70)
// Address: 680fdf70
// Size: 14 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_releaseFormatData(int *param_1)
{
  xtra_resetBER(param_1);
  return 0;
}




// ============================================================
// Function: display_selectCertEntry (FUN_680fdf80)
// Address: 680fdf80
// Size: 166 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5, undefined4 * param_6, undefined4 param_7
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_selectCertEntry(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *local_8;
  uint local_4;
  
  iVar1 = display_resetFormatState((int *)&local_8);
  if (iVar1 == 0) {
    iVar1 = xtra_lookupCertBySubject(local_8,&local_4,param_3,(byte *)*param_4,param_4[1],(int)param_5,param_6);
    if (iVar1 == 0) {
      iVar1 = display_buildCertChainVerified(param_1,param_2,local_8,local_4,param_5,param_6,param_7);
    }
    else if (iVar1 != 300) {
      iVar1 = xtra_decodeBER("selecting certificate",iVar1,0x10c,param_6);
    }
    xtra_initCryptoContext((int *)&local_8);
  }
  return iVar1;
}



// ============================================================
// Function: display_getEncodedCount (FUN_680fe030)
// Address: 680fe030
// Size: 40 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl display_getEncodedCount(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = xtra_getEncodedCount(param_1,param_2,0x68106b20);
  return (iVar1 == 0) - 1 & 0x126;
}



// ============================================================
// Function: display_getCertChainCount (FUN_680fe060)
// Address: 680fe060
// Size: 40 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl display_getCertChainCount(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = xtra_getEncodedCount(param_1,param_2,0x680fe500);
  return (iVar1 == 0) - 1 & 0x147;
}



// ============================================================
// Function: display_getEncodedEntry (FUN_680fe090)
// Address: 680fe090
// Size: 80 bytes
// Params: undefined4 * param_1, undefined4 * param_2, uint param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_getEncodedEntry(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  undefined4 *local_4;
  
  iVar1 = xtra_getEncodedEntry(&local_4,(undefined4 *)0x0,param_2,param_3,0x68106b20);
  if (iVar1 == 0) {
    iVar1 = xtra_encodeBER(param_1,local_4,0x680fe4e0);
  }
  else if (iVar1 != 0x11f) {
    return 0x126;
  }
  return iVar1;
}



// ============================================================
// Function: display_getCertChainEntry (FUN_680fe0e0)
// Address: 680fe0e0
// Size: 80 bytes
// Params: undefined4 * param_1, undefined4 * param_2, uint param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_getCertChainEntry(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  undefined4 *local_4;
  
  iVar1 = xtra_getEncodedEntry(&local_4,(undefined4 *)0x0,param_2,param_3,0x680fe500);
  if (iVar1 == 0) {
    iVar1 = xtra_encodeBER(param_1,local_4,0x680fe4c0);
  }
  else if (iVar1 != 0x11f) {
    return 0x147;
  }
  return iVar1;
}



// ============================================================
// Function: display_removeAllCertEntries (FUN_680fe130)
// Address: 680fe130
// Size: 32 bytes
// Params: undefined4 * param_1, uint param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_removeAllCertEntries(undefined4 *param_1,uint param_2)
{
  int iVar1;
  
  do {
    iVar1 = xtra_removeEncodedEntry(param_1,param_2,0x680fe500);
  } while (iVar1 == 0);
  return 0;
}



// ============================================================
// Function: display_buildCertChainVerified (FUN_680fe150)
// Address: 680fe150
// Size: 274 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3, uint param_4, undefined4 * param_5, undefined4 * param_6, undefined4 param_7
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_buildCertChainVerified(int *param_1,undefined4 *param_2,undefined4 *param_3,uint param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 *local_14;
  int local_10;
  int local_c;
  uint local_8;
  uint *local_4;
  
  iVar1 = display_parseFormatBlock((int *)&local_4,param_2);
  if (((iVar1 == 0) && (iVar1 = display_decryptFormatData(&local_c,param_3,param_6), iVar1 == 0)) &&
     (iVar1 = display_createCertBlock(&local_10,(int *)&local_14,(undefined4 *)(local_c + 0x24),param_6),
     iVar1 == 0)) {
    display_freeFormatState((int *)&local_8);
    iVar1 = xtra_buildCertChainEntry((undefined4 *)*local_14,0,param_3,param_4,local_8,local_4,param_5,param_6,
                         param_7);
    if (iVar1 == 0) {
      iVar1 = xtra_verifyCertExt(local_14[3],local_14 + 4,local_c + 0x2c,param_6);
      if (iVar1 == 0) {
        iVar1 = xtra_queryContainer(param_1,&local_10,0,param_2,0x680fe500);
      }
      else {
        iVar1 = xtra_decodeBER("decoding public key",iVar1,0x10c,param_6);
      }
      if (iVar1 == 0) {
        return 0;
      }
    }
    xtra_resetBER(&local_10);
  }
  return iVar1;
}



// ============================================================
// Function: display_setCertExtensions (FUN_680fe270)
// Address: 680fe270
// Size: 121 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
display_setCertExtensions(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  int iVar1;
  int local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_1,0x680fe500);
  if (iVar1 != 0) {
    return 0x147;
  }
  xtra_initCryptoContext((int *)(local_4 + 0x24));
  xtra_initCryptoContext((int *)(local_4 + 0x28));
  *(undefined4 *)(local_4 + 0x24) = param_2;
  *(undefined4 *)(local_4 + 0x28) = param_3;
  *(undefined4 *)(local_4 + 0x2c) = param_4;
  *(undefined4 *)(local_4 + 0x30) = param_5;
  return 0;
}



// ============================================================
// Function: display_parseFormatBlock (FUN_680fe2f0)
// Address: 680fe2f0
// Size: 58 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_parseFormatBlock(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_2,0x680fe500);
  if (iVar1 != 0) {
    return 0x147;
  }
  *param_1 = local_4 + 8;
  return 0;
}



// ============================================================
// Function: display_createCertBlock (FUN_680fe330)
// Address: 680fe330
// Size: 162 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_createCertBlock(int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = xtra_writeBERBlock(param_1,param_2,0x14,0x680fe4c0);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = xtra_initContainer((int *)*param_2);
  if ((iVar1 == 0) && (iVar1 = xtra_writeBERTag((int *)*param_2,*param_1), iVar1 == 0)) {
    iVar1 = display_freeNetSecurity((undefined4 *)(*param_2 + 0xc));
    if (iVar1 == 0) {
      iVar1 = display_initContainerFormat((int *)(*param_2 + 4),param_3,param_4);
      if (iVar1 != 0) goto LAB_680fe3c3;
      iVar1 = xtra_writeBERTag((int *)(*param_2 + 4),*param_1);
    }
    else {
      iVar1 = 0x100;
    }
    if (iVar1 == 0) {
      return 0;
    }
  }
LAB_680fe3c3:
  xtra_resetBER(param_1);
  return iVar1;
}



// ============================================================
// Function: display_addDefaultCertEntry (FUN_680fe3e0)
// Address: 680fe3e0
// Size: 210 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_addDefaultCertEntry(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *local_c;
  int local_8;
  int local_4;
  
  iVar1 = display_decryptFormatData(&local_4,param_3,param_4);
  if ((iVar1 == 0) &&
     (iVar1 = display_createCertBlock(&local_8,(int *)&local_c,(undefined4 *)(local_4 + 0x24),param_4),
     iVar1 == 0)) {
    iVar1 = xtra_insertDefaultCertEntry((undefined4 *)*local_c,param_3,param_4);
    if (iVar1 == 0) {
      iVar1 = xtra_verifyCertExt(local_c[3],local_c + 4,local_4 + 0x2c,param_4);
      if (iVar1 == 0) {
        iVar1 = xtra_queryContainer(param_1,&local_8,0,param_2,0x680fe500);
      }
      else {
        iVar1 = xtra_decodeBER("decoding public key",iVar1,0x10c,param_4);
      }
      if (iVar1 == 0) {
        return 0;
      }
    }
    xtra_resetBER(&local_8);
  }
  return iVar1;
}



// ============================================================
// Function: display_freeCertBlockInner (FUN_680fe4c0)
// Address: 680fe4c0
// Size: 31 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_freeCertBlockInner(int param_1)
{
  display_releaseNetSecurity((undefined4 *)(param_1 + 0xc));
  display_freeIfNonNull(*(int *)(param_1 + 8));
  return 0;
}



// ============================================================
// Function: display_freeCertBlockFull (FUN_680fe4e0)
// Address: 680fe4e0
// Size: 28 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_freeCertBlockFull(int param_1)
{
  display_freeCertBlockInner(param_1);
  display_releaseNetSecurity((undefined4 *)(param_1 + 0x20));
  return 0;
}



// ============================================================
// Function: display_resetCertCryptoCtx (FUN_680fe500)
// Address: 680fe500
// Size: 31 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_resetCertCryptoCtx(int param_1)
{
  xtra_initCryptoContext((int *)(param_1 + 0x24));
  xtra_initCryptoContext((int *)(param_1 + 0x28));
  return 0;
}



// ============================================================
// Function: display_addCertChainData (FUN_680fe520)
// Address: 680fe520
// Size: 70 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_addCertChainData(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)
{
  int iVar1;
  int local_4;
  
  iVar1 = display_parseFormatBlock(&local_4,param_2);
  if (iVar1 == 0) {
    xtra_addCertChainEntry(local_4,param_1,param_3,param_4,param_5,param_6,(int)param_2);
  }
  return 0;
}



// ============================================================
// Function: display_readStreamLine (FUN_680fe570)
// Address: 680fe570
// Size: 167 bytes
// Params: char * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_readStreamLine(char *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  
  iVar2 = param_3;
  pcVar5 = param_1;
  if (param_3 == 0) {
    return 0x118;
  }
  iVar3 = Ordinal_1435(param_3);
  iVar4 = Ordinal_1433(iVar2);
  if (iVar3 <= iVar4) {
    return 0x118;
  }
  iVar1 = iVar3 - iVar4;
  if (param_2 + -1 < iVar3 - iVar4) {
    iVar1 = param_2 + -1;
  }
  while( true ) {
    if (iVar1 < 1) {
      pcVar5[1] = '\0';
      return 0;
    }
    iVar3 = Ordinal_1409(iVar2,pcVar5,1);
    if (iVar3 == 0) break;
    if ((*pcVar5 == '\n') || (*pcVar5 == '\r')) {
      iVar3 = Ordinal_1409(iVar2,(int)&param_1 + 3,1);
      if ((iVar3 == 1) && (((*(unsigned char *)((char *)&param_1 + 3)) != '\n' && ((*(unsigned char *)((char *)&param_1 + 3)) != '\r')))) {
        Ordinal_1432(iVar2,0xffffffff,1);
      }
      *pcVar5 = '\0';
      return 0;
    }
    pcVar5 = pcVar5 + 1;
    iVar1 = iVar1 + -1;
  }
  return 0x122;
}




// ============================================================
// Function: display_writeCryptoStream (FUN_680fe620)
// Address: 680fe620
// Size: 87 bytes
// Params: undefined4 param_1, int param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_writeCryptoStream(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined1 local_5;
  
  if (param_2 == 0) {
    return 0;
  }
  uVar1 = Ordinal_1201(param_1);
  iVar2 = Ordinal_1420(param_2,param_1,uVar1);
  if (iVar2 == 0) {
    return 0x122;
  }
  iVar2 = Ordinal_1420(param_2,&local_5,1);
  return (-(uint)(iVar2 != 0) & 0xfffffede) + 0x122;
}



// ============================================================
// Function: display_readCryptoBlock (FUN_680fe680)
// Address: 680fe680
// Size: 93 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl display_readCryptoBlock(undefined4 param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_4 == 0) {
    return 0x118;
  }
  iVar1 = Ordinal_1435(param_4);
  iVar2 = Ordinal_1433(param_4);
  if (iVar1 <= iVar2) {
    return 0x118;
  }
  iVar3 = iVar1 - iVar2;
  if (param_3 < iVar1 - iVar2) {
    iVar3 = param_3;
  }
  iVar1 = Ordinal_1409(param_4,param_1,iVar3);
  if (iVar1 != 0) {
    *param_2 = iVar3;
    return 0;
  }
  return 0x122;
}



// ============================================================
// Function: display_writeStreamBlock (FUN_680fe6e0)
// Address: 680fe6e0
// Size: 42 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_writeStreamBlock(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    return 0;
  }
  iVar1 = Ordinal_1420(param_3,param_1,param_2);
  return (-(uint)(iVar1 != 0) & 0xfffffede) + 0x122;
}



// ============================================================
// Function: display_seekStreamStart (FUN_680fe710)
// Address: 680fe710
// Size: 38 bytes
// Params: int param_1
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl display_seekStreamStart(int param_1)

{
  int iVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar1 = Ordinal_1432(param_1,0,0);
  return (-(uint)(iVar1 != 0) & 0xfffffede) + 0x122;
}



// ============================================================
// Function: display_initCryptoVtable (FUN_680fe740)
// Address: 680fe740
// Size: 57 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_initCryptoVtable(undefined4 *param_1,undefined4 param_2)
{
  *param_1 = display_readStreamLine;
  param_1[1] = display_writeCryptoStream;
  param_1[2] = display_readCryptoBlock;
  param_1[4] = display_writeStreamBlock;
  param_1[3] = display_seekStreamStart;
  param_1[5] = param_2;
  param_1[6] = 0;
  return 0;
}



// ============================================================
// Function: display_getFormatInfo (FUN_680fe780)
// Address: 680fe780
// Size: 105 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_getFormatInfo(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  undefined1 local_c [4];
  int local_8;
  
  local_8 = 0;
  uVar1 = xtra_initCryptoSecurity(&local_8,5);
  if (uVar1 == 0) {
    uVar1 = xtra_decryptWithReport(local_8,param_2,param_3,(undefined4 *)0x0);
    if (uVar1 == 0) {
      uVar1 = xtra_encryptWithReport(param_1,local_c,local_8,(undefined4 *)0x0);
    }
  }
  xtra_destroyCryptoSecurity(&local_8);
  return uVar1;
}



// ============================================================
// Function: display_hashCryptoBlock (FUN_680fe7f0)
// Address: 680fe7f0
// Size: 132 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint display_hashCryptoBlock(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  uint uVar1;
  undefined1 local_c [4];
  int local_8;
  
  local_8 = 0;
  uVar1 = xtra_initCryptoSecurity(&local_8,5);
  if (uVar1 == 0) {
    uVar1 = xtra_decryptWithReport(local_8,param_2,param_3,(undefined4 *)0x0);
    if (uVar1 == 0) {
      uVar1 = xtra_decryptWithReport(local_8,param_4,param_5,(undefined4 *)0x0);
      if (uVar1 == 0) {
        uVar1 = xtra_encryptWithReport(param_1,local_c,local_8,(undefined4 *)0x0);
      }
    }
  }
  xtra_destroyCryptoSecurity(&local_8);
  return uVar1;
}



// ============================================================
// Function: display_searchFormatList (FUN_680fe880)
// Address: 680fe880
// Size: 64 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_searchFormatList(void)

{
  int iVar1;
  int *in_EAX;
  uint uVar2;
  byte *unaff_EBX;
  int *unaff_ESI;
  int *unaff_EDI;
  
  *unaff_EDI = 0;
  iVar1 = *in_EAX;
  *unaff_ESI = iVar1;
  while( true ) {
    if (iVar1 == 0) {
      return 300;
    }
    uVar2 = display_decodeFormat((byte *)(*unaff_ESI + 0x10),unaff_EBX,0x10);
    if (uVar2 == 0) break;
    *unaff_EDI = *unaff_ESI;
    iVar1 = *(int *)(*unaff_ESI + 0xf0);
    *unaff_ESI = iVar1;
  }
  return 0;
}



// ============================================================
// Function: display_copyToFixedBuffer (FUN_680fe8c0)
// Address: 680fe8c0
// Size: 45 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_copyToFixedBuffer(undefined4 param_1)
{
  uint in_EAX;
  void *unaff_EDI;
  
  if (0x40 < in_EAX) {
    in_EAX = 0x40;
  }
  display_fillMemory(unaff_EDI,0,0x40);
  display_checkAndFree(unaff_EDI,param_1,in_EAX);
  return 0;
}



// ============================================================
// Function: display_extractKeyFromChain (FUN_680fe8f0)
// Address: 680fe8f0
// Size: 154 bytes
// Params: void * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int display_extractKeyFromChain(void *param_1)

{
  int iVar1;
  undefined4 *unaff_EBX;
  uint uVar2;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined *local_c;
  uint local_8;
  
  iVar1 = display_encryptBlock(&local_8,unaff_EBX,(undefined4 *)0x0);
  if (iVar1 == 0) {
    uVar2 = 1;
    if (local_8 != 0) {
      do {
        iVar1 = display_decryptBlockEx(&local_c,&local_20,&local_1c,&local_10,&local_14,&local_18,unaff_EBX,
                             local_8 - uVar2,(undefined4 *)0x0);
        if (iVar1 != 0) {
          return iVar1;
        }
        if (local_c == &DAT_6818eb04) {
          display_copyToFixedBuffer(local_10);
          return 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 <= local_8);
    }
    display_fillMemory(param_1,0,0x40);
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: display_addFormatListEntry (FUN_680fe990)
// Address: 680fe990
// Size: 524 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4, byte * param_5, uint param_6, undefined4 param_7, int param_8, int * param_9
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
display_addFormatListEntry(int param_1,undefined4 param_2,undefined4 param_3,int param_4,byte *param_5,
            uint param_6,undefined4 param_7,int param_8,int *param_9)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int local_38;
  int local_24;
  undefined4 *local_1c;
  undefined1 local_18 [16];
  uint local_8;
  
  local_1c = (undefined4 *)0x0;
  uVar1 = display_hashCryptoBlock(local_18,param_3,param_1,param_2,param_4);
  if (uVar1 != 0) {
    return 0;
  }
  iVar2 = display_searchFormatList();
  if (iVar2 == 0) {
    if (local_24 == 0) {
      *param_9 = *(int *)(local_38 + 0xf0);
    }
    else {
      *(undefined4 *)(local_24 + 0xf0) = *(undefined4 *)(local_38 + 0xf0);
    }
    display_freeIfNonNull(local_38);
  }
  iVar2 = param_8 + param_6 + param_1;
  iVar3 = display_allocBlock(iVar2 + 0xf4 + param_4);
  if (iVar3 != 0) {
    uVar1 = display_getFormatInfo(iVar3,param_5,param_6);
    if (uVar1 == 0) {
      display_checkAndFree(iVar3 + 0x10,local_18,0x10);
      uVar1 = xtra_initContainer((int *)&local_1c);
      if (uVar1 == 0) {
        uVar1 = display_decryptBlock(local_1c,param_5,param_6,(undefined4 *)0x0);
        if (uVar1 == 0) {
          uVar1 = display_extractKeyFromChain((void *)(iVar3 + 0x20));
          if (uVar1 == 0) {
            *(int *)(iVar3 + 0xe0) = param_8;
            display_checkAndFree(iVar3 + 0xf4,param_7,param_8);
            *(uint *)(iVar3 + 0xe4) = param_6;
            display_checkAndFree(param_8 + 0xf4 + iVar3,param_5,param_6);
            *(int *)(iVar3 + 0xe8) = param_1;
            display_checkAndFree(param_8 + param_6 + 0xf4 + iVar3,param_3,param_1);
            *(int *)(iVar3 + 0xec) = param_4;
            display_checkAndFree(iVar2 + 0xf4 + iVar3,param_2,param_4);
          }
        }
      }
    }
    display_releaseFormatData((int *)&local_1c);
    if (uVar1 == 0) {
      *(int *)(iVar3 + 0xf0) = *param_9;
      *param_9 = iVar3;
      return 0;
    }
    display_freeIfNonNull(iVar3);
  }
  return 0;
}



// ============================================================
// Function: display_addContainerListItem (FUN_680feba0)
// Address: 680feba0
// Size: 87 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, int param_4, byte * param_5, uint param_6, undefined4 * param_7, int * param_8
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_addContainerListItem(undefined4 param_1,int param_2,undefined4 param_3,int param_4,byte *param_5,
            uint param_6,undefined4 *param_7,int *param_8)
{
  int iVar1;
  undefined4 local_10;
  int local_c;
  byte local_8 [4];
  
  iVar1 = xtra_getContainerLastItem(&local_10,&local_c,(undefined4 *)local_8,param_7);
  if (iVar1 == 0) {
    if ((local_8[0] & 2) != 0) {
      return 0;
    }
    display_addFormatListEntry(param_2,param_3,param_1,param_4,param_5,param_6,local_10,local_c,param_8);
  }
  return 0;
}



// ============================================================
// Function: display_searchSubList (FUN_680fec00)
// Address: 680fec00
// Size: 150 bytes
// Params: byte * param_1, uint param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_searchSubList(byte *param_1,uint param_2,int param_3)

{
  int iVar1;
  int in_EAX;
  uint uVar2;
  uint uVar3;
  int *unaff_ESI;
  int *unaff_EDI;
  int local_c;
  int local_8;
  
  local_8 = 0;
  *unaff_EDI = 0;
  iVar1 = *(int *)(in_EAX + 4);
  uVar3 = 0;
  local_c = 0;
  *unaff_ESI = iVar1;
  while (iVar1 != 0) {
    uVar2 = display_decodeFormat((byte *)*unaff_ESI,param_1,0x10);
    if (uVar2 == 0) {
      if (param_3 == 0) {
        uVar2 = *(uint *)(*unaff_ESI + 0x10);
        if ((uVar2 <= param_2) && (uVar3 < uVar2)) {
          local_c = *unaff_EDI;
          uVar3 = uVar2;
          local_8 = *unaff_ESI;
        }
      }
      else if (*(uint *)(*unaff_ESI + 0x10) == param_2) {
        return 0;
      }
    }
    *unaff_EDI = *unaff_ESI;
    iVar1 = *(int *)(*unaff_ESI + 0x1c);
    *unaff_ESI = iVar1;
  }
  if ((param_3 == 0) && (local_8 != 0)) {
    *unaff_ESI = local_8;
    *unaff_EDI = local_c;
    return 0;
  }
  return 300;
}



int display_addContainerListItem(); /* FIXUP: forward declaration */

// ============================================================
// Function: display_addSubListEntry (FUN_680feca0)
// Address: 680feca0
// Size: 268 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, int param_4, uint param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
display_addSubListEntry(undefined4 param_1,int param_2,undefined4 param_3,int param_4,uint param_5)
{
  /* FIXUP: removed duplicate local_18 */
  uint uVar1;
  int iVar2;
  int unaff_EBX;
  int local_24;
  int local_20;
  byte local_18 [16];
  uint local_8;
  
  uVar1 = display_getFormatInfo(local_18,param_3,param_4);
  if (uVar1 != 0) {
    return 0;
  }
  iVar2 = display_searchSubList(local_18,param_5,1);
  if (iVar2 == 0) {
    if (local_24 == 0) {
      *(undefined4 *)(param_2 + 4) = *(undefined4 *)(local_20 + 0x1c);
    }
    else {
      *(undefined4 *)(local_24 + 0x1c) = *(undefined4 *)(local_20 + 0x1c);
    }
    display_freeIfNonNull(local_20);
  }
  iVar2 = display_allocBlock(unaff_EBX + 0x20 + param_4);
  if (iVar2 == 0) {
    return 0;
  }
  display_checkAndFree(iVar2,local_18,0x10);
  *(uint *)(iVar2 + 0x10) = param_5;
  *(int *)(iVar2 + 0x14) = unaff_EBX;
  display_checkAndFree(iVar2 + 0x20,param_1,unaff_EBX);
  *(int *)(iVar2 + 0x18) = param_4;
  display_checkAndFree(unaff_EBX + 0x20 + iVar2,param_3,param_4);
  *(undefined4 *)(iVar2 + 0x1c) = *(undefined4 *)(param_2 + 4);
  *(int *)(param_2 + 4) = iVar2;
  return 0;
}



// ============================================================
// Function: display_addContainerSubItem (FUN_680fedb0)
// Address: 680fedb0
// Size: 76 bytes
// Params: undefined4 param_1, int param_2, uint param_3, undefined4 * param_4, int param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_addContainerSubItem(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4,int param_5)
{
  int iVar1;
  undefined4 local_10;
  undefined4 local_c;
  byte local_8 [4];
  
  iVar1 = xtra_getContainerLastItem(&local_10,&local_c,(undefined4 *)local_8,param_4);
  if (iVar1 == 0) {
    if ((local_8[0] & 2) != 0) {
      return 0;
    }
    display_addSubListEntry(local_10,param_5,param_1,param_2,param_3);
  }
  return 0;
}



// ============================================================
// Function: display_searchExtList (FUN_680fee00)
// Address: 680fee00
// Size: 158 bytes
// Params: void * this, undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall display_searchExtList(void *this,undefined4 param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  int *unaff_ESI;
  int *unaff_EDI;
  byte local_18 [16];
  uint local_8;
  
  *unaff_EDI = 0;
  uVar2 = display_getFormatInfo(local_18,param_1,this);
  if (uVar2 != 0) {
    return 0;
  }
  iVar1 = *(int *)(param_2 + 8);
  *unaff_ESI = iVar1;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = display_decodeFormat((byte *)*unaff_ESI,local_18,0x10);
    if (uVar2 == 0) break;
    *unaff_EDI = *unaff_ESI;
    iVar1 = *(int *)(*unaff_ESI + 0x524);
    *unaff_ESI = iVar1;
  }
  return 0;
}



// ============================================================
// Function: display_addExtListEntry (FUN_680feea0)
// Address: 680feea0
// Size: 208 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall display_addExtListEntry(undefined4 param_1,int param_2,undefined4 param_3)
{
  uint uVar1;
  int iVar2;
  uint unaff_EBX;
  int unaff_EDI;
  undefined1 local_18 [16];
  uint local_8;
  
  if (unaff_EBX < 0x50a) {
    uVar1 = display_getFormatInfo(local_18,param_3,unaff_EDI);
    if (uVar1 == 0) {
      iVar2 = display_allocBlock(unaff_EDI + 0x528);
      if (iVar2 == 0) {
        return 0;
      }
      display_checkAndFree(iVar2,local_18,0x10);
      *(uint *)(iVar2 + 0x51c) = unaff_EBX;
      display_checkAndFree(iVar2 + 0x10,param_1,unaff_EBX);
      *(int *)(iVar2 + 0x520) = unaff_EDI;
      display_checkAndFree(iVar2 + 0x528,param_3,unaff_EDI);
      *(undefined4 *)(iVar2 + 0x524) = *(undefined4 *)(param_2 + 8);
      *(int *)(param_2 + 8) = iVar2;
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: display_replaceExtListEntry (FUN_680fef70)
// Address: 680fef70
// Size: 102 bytes
// Params: void * this, undefined4 param_1, void * param_2, undefined4 param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall
display_replaceExtListEntry(void *this,undefined4 param_1,void *param_2,undefined4 param_3,undefined4 param_4,
            int param_5)
{
  int iVar1;
  
  iVar1 = display_searchExtList(param_2,param_1,param_5);
  if (iVar1 == 0) {
    if (this == (void *)0x0) {
      *(undefined4 *)(param_5 + 8) = *(undefined4 *)(param_5 + 0x524);
    }
    else {
      *(undefined4 *)((int)this + 0x524) = *(undefined4 *)(param_5 + 0x524);
    }
    display_freeIfNonNull(param_5);
  }
  display_addExtListEntry(param_3,param_5,param_1);
  return 0;
}



// ============================================================
// Function: display_getContainerPayload (FUN_680fefe0)
// Address: 680fefe0
// Size: 157 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_getContainerPayload(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)
{
  uint uVar1;
  int iVar2;
  int local_20;
  undefined1 local_18 [16];
  uint local_8;
  
  uVar1 = display_hashCryptoBlock(local_18,param_2,param_3,param_4,param_5);
  if (uVar1 != 0) {
    return 0;
  }
  iVar2 = display_searchFormatList();
  if (iVar2 != 0) {
    return 0;
  }
  xtra_addContainerData(param_1,local_20 + 0xf4,*(uint *)(local_20 + 0xe0),1);
  return 0;
}



// ============================================================
// Function: display_collectContainerData (FUN_680ff080)
// Address: 680ff080
// Size: 148 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
display_collectContainerData(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)
{
  byte *pbVar1;
  uint uVar2;
  int iVar3;
  byte local_18 [16];
  uint local_8;
  
  uVar2 = display_getFormatInfo(local_18,param_2,param_3);
  if (uVar2 == 0) {
    pbVar1 = (byte *)*param_4;
    while ((pbVar1 != (byte *)0x0 &&
           ((uVar2 = display_decodeFormat(pbVar1,local_18,0x10), uVar2 != 0 ||
            (iVar3 = xtra_addContainerData(param_1,pbVar1 + 0xf4,*(uint *)(pbVar1 + 0xe0),1), iVar3 == 0)))))
    {
      pbVar1 = *(byte **)(pbVar1 + 0xf0);
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: display_getSubListData (FUN_680ff120)
// Address: 680ff120
// Size: 147 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, uint param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_getSubListData(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4)
{
  uint uVar1;
  int iVar2;
  int local_1c;
  byte local_18 [16];
  uint local_8;
  
  uVar1 = display_getFormatInfo(local_18,param_2,param_3);
  if (uVar1 != 0) {
    return 0;
  }
  iVar2 = display_searchSubList(local_18,param_4,0);
  if (iVar2 != 0) {
    return 0;
  }
  xtra_addContainerData(param_1,local_1c + 0x20,*(uint *)(local_1c + 0x14),1);
  return 0;
}



// ============================================================
// Function: display_readExtListData (FUN_680ff1c0)
// Address: 680ff1c0
// Size: 80 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, void * param_4, int param_5
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
display_readExtListData(undefined4 param_1,int *param_2,undefined4 param_3,void *param_4,int param_5)

{
  int iVar1;
  
  iVar1 = display_searchExtList(param_4,param_3,param_5);
  if (iVar1 != 0) {
    return 300;
  }
  iVar1 = *(int *)(param_5 + 0x51c);
  *param_2 = iVar1;
  display_checkAndFree(param_1,param_5 + 0x10,iVar1);
  return 0;
}



// ============================================================
// Function: display_initContainerVtable (FUN_680ff210)
// Address: 680ff210
// Size: 101 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_initContainerVtable(undefined4 *param_1)

{
  undefined4 *puVar1;
  
  *param_1 = display_addContainerListItem;
  param_1[1] = display_addContainerSubItem;
  param_1[2] = display_replaceExtListEntry;
  param_1[3] = display_getContainerPayload;
  param_1[4] = display_collectContainerData;
  param_1[5] = display_getSubListData;
  param_1[6] = display_readExtListData;
  puVar1 = (undefined4 *)display_allocBlock(0xc);
  param_1[7] = puVar1;
  param_1[8] = 0;
  if (puVar1 == (undefined4 *)0x0) {
    return 0x100;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  return 0;
}



// ============================================================
// Function: display_freeAllLists (FUN_680ff280)
// Address: 680ff280
// Size: 133 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int display_freeAllLists(int param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  piVar1 = *(int **)(param_1 + 0x1c);
  iVar3 = *piVar1;
  while (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 0xf0);
    display_freeIfNonNull(iVar3);
    iVar3 = iVar2;
  }
  iVar3 = piVar1[1];
  while (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 0x1c);
    display_freeIfNonNull(iVar3);
    iVar3 = iVar2;
  }
  iVar3 = piVar1[2];
  while (iVar3 != 0) {
    iVar2 = *(int *)(iVar3 + 0x524);
    display_freeIfNonNull(iVar3);
    iVar3 = iVar2;
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    display_freeIfNonNull(*(int *)(param_1 + 0x1c));
  }
  *(undefined4 *)(param_1 + 0x1c) = 0;
  return 0;
}



// ============================================================
// Function: display_getListItemData (FUN_680ff310)
// Address: 680ff310
// Size: 134 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 display_getListItemData(int param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = *(int **)(param_1 + 0x1c);
  *param_3 = 0;
  iVar2 = *piVar1;
  iVar3 = 0;
  while( true ) {
    if (iVar2 == 0) {
      return 300;
    }
    if (iVar3 == param_2) break;
    iVar2 = *(int *)(iVar2 + 0xf0);
    iVar3 = iVar3 + 1;
  }
  iVar3 = Ordinal_1111(*(undefined4 *)(iVar2 + 0xe0),0);
  *param_3 = iVar3;
  if (iVar3 == 0) {
    return 0x100;
  }
  uVar4 = Ordinal_1114(iVar3);
  display_checkAndFree(uVar4,iVar2 + 0xf4,*(int *)(iVar2 + 0xe0));
  Ordinal_1115(*param_3);
  return 0;
}




// ============================================================
// Function: display_processPKCS7Envelope (FUN_680ff3a0)
// Address: 680ff3a0
// Size: 410 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, undefined4 * param_5, uint * param_6, int param_7, undefined4 * param_8, undefined4 param_9, undefined4 param_10, undefined4 param_11, undefined4 param_12, undefined4 param_13, undefined4 * param_14, undefined4 * param_15, undefined4 param_16
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl
display_processPKCS7Envelope(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 *param_5,uint *param_6,int param_7,undefined4 *param_8,undefined4 param_9,
            undefined4 param_10,undefined4 param_11,undefined4 param_12,undefined4 param_13,
            undefined4 *param_14,undefined4 *param_15,undefined4 param_16)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *local_5c;
  int *local_58;
  int *local_54;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  xtra_initPKCS7Defaults(&local_5c);
  local_30 = param_13;
  local_24 = param_4;
  local_28 = param_3;
  local_8 = param_9;
  local_c = param_10;
  uVar1 = xtra_processPKCS7Message(&local_5c,0,param_1,param_11,param_12,param_14,param_15,param_16);
  if (uVar1 != 0) {
    if (uVar1 == 0x13b) {
      uVar2 = xtra_decodeBER(&DAT_6818eba4,0x13b,0x10a,param_15);
      goto LAB_680ff524;
    }
    uVar2 = uVar1;
    if (uVar1 != 0x143) goto LAB_680ff524;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = local_18;
  }
  uVar3 = (local_14 == 0) - 1 & 4;
  if (local_1c == 2) {
    if (local_5c == (int *)0x0) {
      uVar3 = 0x10;
    }
    else if (local_10 == 0) {
      uVar3 = uVar3 | 2;
    }
    else {
      uVar3 = 8;
    }
  }
  else if (local_1c == 4) {
    uVar3 = uVar3 | 3;
  }
  else {
    if (local_1c != 3) {
      uVar2 = 0x10a;
      goto LAB_680ff524;
    }
    uVar3 = uVar3 | 1;
  }
  if (param_6 != (uint *)0x0) {
    *param_6 = uVar3;
  }
  if ((((param_8 == (undefined4 *)0x0) || ((uVar3 & 10) == 0)) ||
      (uVar2 = xtra_getHashAlgorithmInfo(param_8,local_5c,param_15), uVar2 == 0)) &&
     (uVar2 = uVar1, (uVar3 & 1) != 0)) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = local_2c;
    }
    if ((param_7 != 0) && (uVar3 = xtra_setupDEKAlgorithm(param_7,local_54,local_58,param_15), uVar3 != 0)) {
      uVar2 = uVar3;
    }
  }
LAB_680ff524:
  xtra_freePKCS7State(&local_5c);
  return uVar2;
}



// ============================================================
// Function: display_initMD5State (FUN_680ff550)
// Address: 680ff550
// Size: 40 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_initMD5State(undefined4 *param_1)
{
  int param_4;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[1] = 0xefcdab89;
  param_1[2] = 0x98badcfe;
  param_1[3] = 0x10325476;
  *param_1 = 0x67452301;
  return 0;
}



// ============================================================
// Function: display_updateMD5 (FUN_680ff580)
// Address: 680ff580
// Size: 177 bytes
// Params: int * param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_updateMD5(int *param_1,int param_2,uint param_3)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = param_1[4];
  uVar3 = param_3 * 8;
  uVar1 = uVar2 + uVar3;
  param_1[4] = uVar1;
  uVar2 = (uVar2 & 0x1f8) >> 3;
  if (uVar1 <= uVar3 && uVar3 - uVar1 != 0) {
    param_1[5] = param_1[5] + 1;
  }
  uVar3 = 0x40 - uVar2;
  param_1[5] = param_1[5] + (param_3 >> 0x1d);
  if (param_3 < uVar3) {
    uVar3 = 0;
  }
  else {
    if (uVar3 < 0x40) {
      display_checkAndFree((int)param_1 + uVar2 + 0x18,param_2,uVar3);
      xtra_md5Transform(param_1,param_1 + 6);
    }
    else {
      uVar3 = 0;
    }
    uVar2 = uVar3 + 0x3f;
    while (uVar2 < param_3) {
      xtra_md5Transform(param_1,(int *)(param_2 + uVar3));
      uVar2 = uVar3 + 0x7f;
      uVar3 = uVar3 + 0x40;
    }
    uVar2 = 0;
  }
  display_checkAndFree((int)param_1 + uVar2 + 0x18,param_2 + uVar3,param_3 - uVar3);
  return 0;
}



// ============================================================
// Function: display_finalizeMD5 (FUN_680ff640)
// Address: 680ff640
// Size: 140 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_finalizeMD5(int *param_1,int param_2)
{
  uint uVar1;
  int iVar2;
  size_t sVar3;
  undefined1 local_48 [8];
  undefined1 local_40 [64];
  
  display_encodeLE32((int)local_48,param_1 + 4,8);
  uVar1 = (param_1[4] & 0x1f8U) >> 3;
  if (uVar1 < 0x38) {
    iVar2 = 0x38;
  }
  else {
    iVar2 = 0x78;
  }
  sVar3 = iVar2 - uVar1;
  display_fillMemory(local_40,0,sVar3);
  local_40[0] = 0x80;
  display_updateMD5(param_1,(int)local_40,sVar3);
  display_updateMD5(param_1,(int)local_48,8);
  display_encodeLE32(param_2,param_1,0x10);
  display_initMD5State(param_1);
  return 0;
}



// ============================================================
// Function: display_encodeLE32 (FUN_680ff6d0)
// Address: 680ff6d0
// Size: 66 bytes
// Params: int param_1, undefined4 * param_2, uint param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_encodeLE32(int param_1,undefined4 *param_2,uint param_3)
{
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_3 != 0) {
    do {
      puVar1 = (undefined1 *)(uVar2 + param_1);
      uVar2 = uVar2 + 4;
      *puVar1 = *(undefined1 *)param_2;
      puVar1[1] = (char)((uint)*param_2 >> 8);
      puVar1[2] = (char)((uint)*param_2 >> 0x10);
      puVar1[3] = (char)((uint)*param_2 >> 0x18);
      param_2 = param_2 + 1;
    } while (uVar2 < param_3);
  }
  return 0;
}



// ============================================================
// Function: display_resetMD2State (FUN_680ff730)
// Address: 680ff730
// Size: 18 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_resetMD2State(void *param_1)
{
  display_fillMemory(param_1,0,0x34);
  return 0;
}



// ============================================================
// Function: display_updateMD2 (FUN_680ff750)
// Address: 680ff750
// Size: 143 bytes
// Params: int param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_updateMD2(int param_1,int param_2,uint param_3)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x20);
  uVar3 = -iVar2 + 0x10;
  *(uint *)(param_1 + 0x20) = param_3 + iVar2 & 0xf;
  if (param_3 < uVar3) {
    uVar4 = 0;
  }
  else {
    display_checkAndFree(param_1 + iVar2 + 0x24,param_2,uVar3);
    display_md2Transform(param_1,param_1 + 0x10,param_1 + 0x24);
    uVar1 = -iVar2;
    while (uVar4 = uVar3, uVar1 + 0x1f < param_3) {
      display_md2Transform(param_1,param_1 + 0x10,param_2 + uVar4);
      uVar3 = uVar4 + 0x10;
      uVar1 = uVar4;
    }
    iVar2 = 0;
  }
  display_checkAndFree(param_1 + iVar2 + 0x24,param_2 + uVar4,param_3 - uVar4);
  return 0;
}



// ============================================================
// Function: display_finalizeMD2 (FUN_680ff7e0)
// Address: 680ff7e0
// Size: 93 bytes
// Params: void * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_finalizeMD2(void *param_1,undefined4 param_2)
{
  uint uVar1;
  undefined1 local_10 [16];
  
  uVar1 = 0x10 - *(int *)((int)param_1 + 0x20);
  display_fillMemory(local_10,uVar1,uVar1);
  display_updateMD2((int)param_1,(int)local_10,uVar1);
  display_updateMD2((int)param_1,(int)param_1 + 0x10,0x10);
  display_checkAndFree(param_2,param_1,0x10);
  display_resetMD2State(param_1);
  return 0;
}



// ============================================================
// Function: display_md2Transform (FUN_680ff840)
// Address: 680ff840
// Size: 192 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_md2Transform(int param_1,int param_2,int param_3)
{
  byte *pbVar1;
  byte *pbVar2;
  uint uVar3;
  byte bVar4;
  uint uVar5;
  uint uVar6;
  byte local_30 [48];
  
  display_checkAndFree(local_30,param_1,0x10);
  display_checkAndFree(local_30 + 0x10,param_3,0x10);
  uVar5 = 0;
  do {
    uVar3 = uVar5 + 1;
    local_30[uVar5 + 0x20] = *(byte *)(param_3 + uVar5) ^ *(byte *)(param_1 + uVar5);
    uVar5 = uVar3;
  } while (uVar3 < 0x10);
  uVar5 = 0;
  uVar3 = 0;
  do {
    uVar6 = 0;
    do {
      pbVar1 = local_30 + uVar6;
      uVar6 = uVar6 + 1;
      bVar4 = (&DAT_6818eed0)[uVar5] ^ *pbVar1;
      *pbVar1 = bVar4;
      uVar5 = (uint)bVar4;
    } while (uVar6 < 0x30);
    uVar5 = uVar5 + uVar3;
    uVar3 = uVar3 + 1;
    uVar5 = uVar5 & 0xff;
  } while (uVar3 < 0x12);
  display_checkAndFree(param_1,local_30,0x10);
  uVar5 = 0;
  bVar4 = *(byte *)(param_2 + 0xf);
  do {
    pbVar1 = (byte *)(param_3 + uVar5);
    pbVar2 = (byte *)(param_2 + uVar5);
    uVar5 = uVar5 + 1;
    bVar4 = (&DAT_6818eed0)[*pbVar1 ^ bVar4] ^ *pbVar2;
    *pbVar2 = bVar4;
  } while (uVar5 < 0x10);
  display_fillMemory(local_30,0,0x30);
  return 0;
}



// ============================================================
// Function: display_initMD5Context (FUN_680ff910)
// Address: 680ff910
// Size: 14 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_initMD5Context(undefined4 *param_1)
{
  xtra_initMD5Context(param_1);
  return 0;
}



// ============================================================
// Function: display_updateMD5Context (FUN_680ff920)
// Address: 680ff920
// Size: 29 bytes
// Params: int param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_updateMD5Context(int param_1,int param_2,uint param_3)
{
  xtra_updateMD5(param_1,param_2,param_3,&LAB_680ff960);
  return 0;
}



// ============================================================
// Function: display_finalizeMD5Context (FUN_680ff940)
// Address: 680ff940
// Size: 24 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl display_finalizeMD5Context(undefined4 *param_1,int param_2)
{
  xtra_finalizeMD5(param_1,param_2,&LAB_680ff960);
  return 0;
}



