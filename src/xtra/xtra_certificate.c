// Module: xtra
// Topic: Certificate chain, CRL operations, algorithm identification, signature verification
// Address range: 0x68106180 - 0x6810A280
// Functions (45):
//   xtra_getCertEntry
//   xtra_resetCertReader
//   xtra_compareCertOrder
//   xtra_removeDuplicateCert
//   xtra_selectCertChain
//   xtra_selectCRL
//   xtra_compareCertChains
//   xtra_copyCertEntries
//   xtra_insertCertEntry
//   xtra_certNoOp
//   xtra_createContainerEx
//   xtra_insertCRLEntry
//   xtra_lookupCertBySubject
//   xtra_addCertsFromStore
//   xtra_selectCRLFromStore
//   xtra_decodeCertPublicKey
//   xtra_verifyCRLSignature
//   xtra_compareCertFields
//   xtra_verifySelfSignedCert
//   xtra_compareDistinguishedNames
//   xtra_compareCaseInsensitive
//   xtra_verifyCertExt
//   xtra_lookupHashAlgorithm
//   xtra_loadEncryptAlgorithm
//   xtra_getEncryptAlgorithmInfo
//   xtra_loadHashAlgorithmById
//   xtra_getHashAlgorithmInfo
//   xtra_setupDEKAlgorithm
//   xtra_loadAlgorithmByOID
//   xtra_encodeAlgorithmByOID
//   xtra_findAlgorithmById
//   xtra_parseCertBlock
//   xtra_setupDESCBC
//   xtra_setupRC2CBC
//   xtra_setupDESEDE3CBC
//   xtra_setupRC5CBC
//   xtra_clearCertList
//   xtra_parseCertificate
//   xtra_addCertByEncKey
//   xtra_addCertByCopy
//   xtra_removeCertByIndex
//   xtra_initCryptoSecurity
//   xtra_decryptWithReport
//   xtra_encryptWithReport
//   xtra_destroyCryptoSecurity

// ============================================================
// Function: xtra_getCertEntry (FUN_681061e0)
// Address: 681061e0
// Size: 265 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4, uint param_5, undefined4 * param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_getCertEntry(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            uint param_5,undefined4 *param_6)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *local_8;
  int local_4;
  
  iVar3 = xtra_encodeBER(&local_8,param_4,0x68106b20);
  if (iVar3 != 0) {
    return iVar3;
  }
  if (*local_8 <= param_5) {
    return 0x11f;
  }
  iVar3 = param_5 * 0x1c;
  if (((undefined4 *)(local_8[3] + iVar3))[4] == 0) {
    iVar4 = display_decryptFormatData(&local_4,*(undefined4 **)(local_8[3] + iVar3),param_6);
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = display_initContainerFormat((int *)(local_8[3] + iVar3 + 0x10),(undefined4 *)(local_4 + 0x14),param_6);
    if (iVar4 != 0) {
      return iVar4;
    }
    iVar4 = xtra_writeBERTag((int *)(local_8[3] + iVar3 + 0x10),(int)param_4);
    if (iVar4 != 0) {
      return iVar4;
    }
    uVar1 = *(undefined4 *)(local_4 + 8);
    uVar2 = local_8[3];
    *(undefined4 *)(uVar2 + iVar3 + 0x14) = *(undefined4 *)(local_4 + 4);
    *(undefined4 *)(uVar2 + iVar3 + 0x18) = uVar1;
  }
  *param_1 = *(undefined4 *)(local_8[3] + 0x10 + iVar3);
  *param_2 = *(undefined4 *)(local_8[3] + 0x14 + iVar3);
  *param_3 = *(undefined4 *)(local_8[3] + 0x18 + iVar3);
  return 0;
}



// ============================================================
// Function: xtra_resetCertReader (FUN_681062f0)
// Address: 681062f0
// Size: 14 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_resetCertReader(undefined4 *param_1)
{
  xtra_resetBERReader(param_1);
  return 0;
}



// ============================================================
// Function: xtra_compareCertOrder (FUN_68106300)
// Address: 68106300
// Size: 64 bytes
// Params: int param_1, uint param_2, int param_3, uint param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_compareCertOrder(int param_1,uint param_2,int param_3,uint param_4)

{
  if (param_1 < param_3) {
    return 1;
  }
  if (param_3 < param_1) {
    return -1;
  }
  if (param_4 == param_2) {
    return 0;
  }
  if (param_1 == 2) {
    return (-(uint)(param_2 < param_4) & 2) - 1;
  }
  return (-(uint)(param_4 < param_2) & 2) - 1;
}



// ============================================================
// Function: xtra_removeDuplicateCert (FUN_68106340)
// Address: 68106340
// Size: 170 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_removeDuplicateCert(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int local_c;
  undefined4 *local_8;
  uint local_4;
  
  iVar1 = xtra_parseCertificate(&local_4,param_1);
  uVar2 = local_4;
  if (iVar1 == 0) {
    while (uVar2 != 0) {
      uVar2 = uVar2 - 1;
      iVar1 = strftime(&local_8,(undefined4 *)0x0,param_1,uVar2);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = display_decryptFormatData(&local_c,local_8,param_3);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = xtra_compareCertFields((undefined4 *)(param_2 + 0x14),(undefined4 *)(local_c + 0x14));
      if (((iVar1 != 0) &&
          (iVar1 = xtra_compareCertFields((undefined4 *)(param_2 + 4),(undefined4 *)(local_c + 4)), iVar1 != 0
          )) && (iVar1 = xtra_removeCertByIndex(param_1,uVar2), iVar1 != 0)) {
        return iVar1;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_selectCertChain (FUN_681063f0)
// Address: 681063f0
// Size: 488 bytes
// Params: uint * param_1, undefined4 * param_2, undefined4 param_3, undefined4 * param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 * param_8, undefined4 param_9
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_selectCertChain(uint *param_1,undefined4 *param_2,int param_3,undefined4 *param_4,uint param_5,
            uint *param_6,undefined4 *param_7,undefined4 *param_8,undefined4 param_9)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  undefined4 *local_18;
  int local_14;
  undefined4 *local_10;
  uint local_c;
  undefined4 *local_8;
  uint local_4;
  
  iVar1 = xtra_parseCertificate(&local_4,param_4);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER("reading certificate list object",iVar1,0x10c,param_8);
    return iVar1;
  }
  if (local_4 == 0) {
    iVar1 = xtra_decodeBER("selecting certificate chain",300,0x10c,param_8);
    return iVar1;
  }
  iVar1 = xtra_initContainer((int *)&local_8);
  if (iVar1 != 0) {
    return iVar1;
  }
  uVar4 = 0;
  local_18 = (undefined4 *)0x0;
  iVar1 = 0;
  puVar2 = param_2;
  if (local_4 != 0) {
    do {
      iVar1 = strftime(&local_10,&local_c,param_4,uVar4);
      puVar3 = puVar2;
      if (iVar1 == 0) {
        xtra_resetCertReader(puVar2);
        iVar1 = xtra_buildCertChainEntry(puVar2,param_3,local_10,local_c | 2,param_5,param_6,param_7,param_8,
                             param_9);
        if (iVar1 == 0) {
          if (local_18 == (undefined4 *)0x0) {
            local_18 = param_2;
            *param_1 = uVar4;
            puVar3 = local_8;
          }
          else {
            iVar1 = xtra_compareCertChains(&local_14,puVar2,local_18);
            if (iVar1 != 0) {
              iVar1 = xtra_readBERValue("reading certificate chain object",iVar1,param_8);
              goto joined_r0x6810655d;
            }
            iVar1 = 0;
            if (0 < local_14) {
              *param_1 = uVar4;
              puVar3 = local_18;
              local_18 = puVar2;
            }
          }
        }
        else {
          if (iVar1 != 0x10c) break;
          iVar1 = 0;
        }
      }
      else {
        iVar1 = xtra_readBERValue("reading certificate list object",iVar1,param_8);
joined_r0x6810655d:
        if (iVar1 != 0) break;
      }
      uVar4 = uVar4 + 1;
      puVar2 = puVar3;
    } while (uVar4 < local_4);
  }
  if (iVar1 == 0) {
    if (local_18 == (undefined4 *)0x0) {
      iVar1 = 0x10c;
    }
    else if (local_18 == local_8) {
      xtra_resetCertReader(param_2);
      iVar1 = xtra_copyCertEntries(param_2,local_8,param_8);
    }
  }
  display_releaseFormatData((int *)&local_8);
  return iVar1;
}



// ============================================================
// Function: xtra_selectCRL (FUN_681065e0)
// Address: 681065e0
// Size: 407 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4, int param_5, uint param_6, undefined4 * param_7, int param_8, undefined4 * param_9, undefined4 param_10
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_selectCRL(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            int param_5,uint param_6,undefined4 *param_7,int param_8,undefined4 *param_9,
            undefined4 param_10)

{
  int iVar1;
  int local_14;
  undefined4 *local_10;
  byte local_c [4];
  int local_8 [2];
  
  *param_1 = 5;
  iVar1 = xtra_selectCRLFromStore(param_7,(undefined4 *)local_c,param_3,param_6,param_8,param_9);
  if (iVar1 != 0) {
    iVar1 = xtra_readBERValue("selecting CRL",iVar1,param_9);
    return iVar1;
  }
  iVar1 = xtra_finalizeCrypto(&local_14,param_7,param_9);
  if (iVar1 != 0) {
    iVar1 = xtra_readBERValue("reading CRL",iVar1,param_9);
    return iVar1;
  }
  if (((local_c[0] & 1) == 0) &&
     (((iVar1 = xtra_extractCertPublicKey(&local_10,param_7,param_9), iVar1 != 0 ||
       (iVar1 = xtra_extractPublicKeyData(local_8,param_7,param_9), iVar1 != 0)) ||
      (iVar1 = xtra_setupCryptoMode(local_8,local_10,local_14,param_5,param_9,param_10), iVar1 != 0)))) {
    iVar1 = xtra_readBERValue("verifying CRL signature",iVar1,param_9);
    return iVar1;
  }
  iVar1 = xtra_insertCRLEntry(param_7,2,param_8,param_9);
  if ((iVar1 == 0) || (iVar1 = xtra_readBERValue("inserting CRL",iVar1,param_9), iVar1 == 0)) {
    iVar1 = xtra_lookupCRLByIssuer(param_2,param_7,(char *)*param_4,param_4[1],param_9);
    if (iVar1 == 0) {
      *param_1 = 6;
    }
    else {
      if (iVar1 == 300) {
        if (param_6 <= *(uint *)(local_14 + 0x14)) {
          *param_1 = 1;
          return 0;
        }
        *param_1 = 4;
        *param_2 = *(undefined4 *)(local_14 + 0x10);
        return 0;
      }
      if (iVar1 == 0x110) {
        iVar1 = xtra_readBERValue("decoding CRL entries",0x110,param_9);
        return iVar1;
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_compareCertChains (FUN_68106780)
// Address: 68106780
// Size: 264 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_compareCertChains(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint *local_c;
  uint *local_8;
  uint local_4;
  
  iVar3 = xtra_encodeBER(&local_c,param_2,0x68106b20);
  if ((iVar3 == 0) && (iVar3 = xtra_encodeBER(&local_8,param_3,0x68106b20), iVar3 == 0)) {
    uVar1 = *local_8;
    uVar2 = *local_c;
    local_4 = uVar1;
    if (uVar2 <= uVar1) {
      local_4 = uVar2;
    }
    uVar6 = 0;
    if (local_4 != 0) {
      iVar3 = (uVar2 - 1) * 0x1c;
      iVar5 = (uVar1 - 1) * 0x1c;
      do {
        iVar4 = xtra_compareCertOrder(*(int *)(local_c[3] + iVar3 + 4),*(uint *)(local_c[3] + iVar3 + 8),
                             *(int *)(local_8[3] + iVar5 + 4),*(uint *)(local_8[3] + iVar5 + 8));
        *param_1 = iVar4;
        if (iVar4 != 0) {
          return 0;
        }
        iVar3 = iVar3 + -0x1c;
        iVar5 = iVar5 + -0x1c;
        uVar6 = uVar6 + 1;
      } while (uVar6 < local_4);
    }
    if (*local_c == *local_8) {
      *param_1 = 0;
      return 0;
    }
    *param_1 = (-(uint)(*local_c < *local_8) & 2) - 1;
    iVar3 = 0;
  }
  return iVar3;
}



// ============================================================
// Function: xtra_copyCertEntries (FUN_68106890)
// Address: 68106890
// Size: 136 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_copyCertEntries(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int *local_4;
  
  if (param_2 == param_1) {
    return 0x124;
  }
  iVar1 = xtra_encodeBER(&local_4,param_2,0x68106b20);
  if (iVar1 == 0) {
    if (*local_4 != 0) {
      iVar1 = *local_4 * 0x1c;
      do {
        iVar2 = local_4[3] + iVar1;
        iVar2 = xtra_insertCertEntry(param_1,*(undefined4 **)(iVar2 + -0x1c),*(int *)(iVar2 + -0x18),
                             *(uint *)(iVar2 + -0x14),*(undefined4 **)(iVar2 + -0x10),param_3);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar1 = iVar1 + -0x1c;
      } while (iVar1 != 0);
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_insertCertEntry (FUN_68106920)
// Address: 68106920
// Size: 507 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int param_3, uint param_4, undefined4 * param_5, undefined4 * param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_insertCertEntry(undefined4 *param_1,undefined4 *param_2,int param_3,uint param_4,undefined4 *param_5,
            undefined4 *param_6)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int *local_1c;
  undefined4 *local_18;
  undefined4 *local_14;
  int local_10 [2];
  undefined4 local_8;
  undefined4 local_4;
  
  local_18 = (undefined4 *)0x0;
  iVar1 = xtra_encodeBER(&local_1c,param_1,0x68106b20);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = xtra_resizeBEREntry(local_1c + 3,(*local_1c + 1) * 0x1c,(int)param_1);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = display_buildObjectBlock(local_10,param_2,param_6);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = display_resetFormatState((int *)&local_14);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = xtra_writeBERTag((int *)&local_14,(int)param_1);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = display_copyAndCreateObject(local_14,local_10,param_6);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (param_5 != (undefined4 *)0x0) {
    iVar1 = xtra_extractSignatureData(local_10,param_5,param_6);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = xtra_createCryptoReader((int *)&local_18);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = xtra_writeBERTag((int *)&local_18,(int)param_1);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = xtra_storeCryptoFromCert(local_18,local_10,param_6);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  local_8 = 0;
  if (*local_1c != 0) {
    uVar2 = *local_1c * 0x1c;
    do {
      puVar4 = (undefined4 *)(local_1c[3] + uVar2);
      uVar2 = uVar2 - 0x1c;
      puVar3 = puVar4 + -7;
      for (iVar1 = 7; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar4 = *puVar3;
        puVar3 = puVar3 + 1;
        puVar4 = puVar4 + 1;
      }
    } while (0x1b < uVar2);
  }
  *(undefined4 **)local_1c[3] = local_14;
  *(int *)(local_1c[3] + 4) = param_3;
  *(uint *)(local_1c[3] + 8) = param_4;
  *(undefined4 **)(local_1c[3] + 0xc) = local_18;
  *(undefined4 *)(local_1c[3] + 0x10) = 0;
  iVar1 = local_1c[3];
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = local_4;
  if ((*local_1c == 0) || (iVar1 = xtra_compareCertOrder(param_3,param_4,local_1c[1],local_1c[2]), iVar1 < 0)
     ) {
    local_1c[1] = param_3;
    local_1c[2] = param_4;
  }
  *local_1c = *local_1c + 1;
  return 0;
}



// ============================================================
// Function: xtra_certNoOp (FUN_68106b20)
// Address: 68106b20
// Size: 1 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_certNoOp(void)
{
  return 0;
}



// ============================================================
// Function: xtra_createContainerEx (FUN_68106b30)
// Address: 68106b30
// Size: 182 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 * param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_createContainerEx(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int local_10;
  undefined4 *local_c;
  int local_8;
  undefined4 local_4;
  
  iVar1 = display_buildObjectBlock(&local_8,param_1,param_4);
  if (iVar1 == 0) {
    iVar1 = display_decryptFormatData(&local_10,param_1,param_4);
    if (iVar1 == 0) {
      iVar1 = xtra_destroyContainer((int *)&local_c);
      if (iVar1 == 0) {
        iVar1 = xtra_getContainerData(local_c,local_8,local_4,param_2);
        if (iVar1 == 0) {
          iVar2 = (*(code *)*param_3)(*(undefined4 *)(local_10 + 0x14),
                                      *(undefined4 *)(local_10 + 0x18),*(undefined4 *)(local_10 + 4)
                                      ,*(undefined4 *)(local_10 + 8),
                                      *(undefined4 *)(local_10 + 0x24),
                                      *(undefined4 *)(local_10 + 0x28),local_c,param_3[7]);
          if (iVar2 != 0) {
            iVar1 = 0x113;
          }
        }
        display_releaseFormatData((int *)&local_c);
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_insertCRLEntry (FUN_68106bf0)
// Address: 68106bf0
// Size: 171 bytes
// Params: undefined4 * param_1, undefined4 param_2, int param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_insertCRLEntry(undefined4 *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  iVar1 = xtra_extractSignatureData(&local_8,param_1,param_4);
  if (iVar1 == 0) {
    iVar1 = xtra_finalizeCrypto(&local_c,param_1,param_4);
    if (iVar1 == 0) {
      iVar1 = xtra_destroyContainer((int *)&local_10);
      if (iVar1 == 0) {
        iVar1 = xtra_getContainerData(local_10,local_8,local_4,param_2);
        if (iVar1 == 0) {
          iVar2 = (**(code **)(param_3 + 4))
                            (*(undefined4 *)(local_c + 8),*(undefined4 *)(local_c + 0xc),
                             *(undefined4 *)(local_c + 0x10),local_10,
                             *(undefined4 *)(param_3 + 0x1c));
          if (iVar2 != 0) {
            iVar1 = 0x113;
          }
        }
        display_releaseFormatData((int *)&local_10);
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_lookupCertBySubject (FUN_68106ca0)
// Address: 68106ca0
// Size: 301 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, byte * param_4, uint param_5, int param_6, undefined4 * param_7
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_lookupCertBySubject(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,byte *param_4,uint param_5,
            int param_6,undefined4 *param_7)

{
  int iVar1;
  uint uVar2;
  undefined4 *local_14;
  int iStack_10;
  int iStack_c;
  undefined4 auStack_8 [2];
  
  iVar1 = xtra_destroyContainer((int *)&local_14);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = (**(code **)(param_6 + 0xc))
                    (local_14,*param_3,param_3[1],param_4,param_5,*(undefined4 *)(param_6 + 0x1c));
  if (iVar1 == 0) {
    iVar1 = xtra_getContainerRef(&iStack_c,local_14);
    if (iVar1 == 0) {
      if (iStack_c != 0) {
        iVar1 = xtra_queryContainerEx(auStack_8,param_2,0,local_14);
        if (((iVar1 != 0) || (iVar1 = display_copyFormatData(param_1,auStack_8,param_7), iVar1 != 0)) ||
           (iVar1 = display_decryptFormatData(&iStack_10,param_1,param_7), iVar1 != 0)) goto LAB_68106db6;
        if ((*(uint *)(iStack_10 + 8) == param_5) &&
           (uVar2 = display_decodeFormat(param_4,*(byte **)(iStack_10 + 4),param_5), uVar2 == 0)) {
          iVar1 = xtra_compareDistinguishedNames(param_3,(undefined4 *)(iStack_10 + 0x14),param_7);
          goto LAB_68106db6;
        }
      }
      iVar1 = 300;
    }
  }
  else if (iVar1 != 0x100) {
    iVar1 = 0x113;
  }
LAB_68106db6:
  xtra_resetBER((int *)&local_14);
  return iVar1;
}



// ============================================================
// Function: xtra_addCertsFromStore (FUN_68106dd0)
// Address: 68106dd0
// Size: 390 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_addCertsFromStore(undefined4 *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uStack_20;
  undefined4 *local_1c;
  int iStack_18;
  undefined4 *puStack_14;
  undefined4 uStack_10;
  uint uStack_c;
  int aiStack_8 [2];
  
  iVar1 = xtra_destroyContainer((int *)&local_1c);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_3 + 0x10))
                      (local_1c,*param_2,param_2[1],*(undefined4 *)(param_3 + 0x1c));
    if (iVar1 == 0) {
      iVar1 = xtra_getContainerRef(&uStack_c,local_1c);
      if ((iVar1 == 0) && (uVar3 = 0, uStack_c != 0)) {
        do {
          iVar1 = xtra_queryContainerEx(aiStack_8,&uStack_10,uVar3,local_1c);
          if (iVar1 != 0) break;
          iVar1 = xtra_addCertByCopy((int *)&uStack_20,param_1,aiStack_8,uStack_10,param_4);
          if (iVar1 == 0) {
            iVar2 = strftime(&puStack_14,(undefined4 *)0x0,param_1,uStack_20);
            if ((iVar2 == 0) && (iVar2 = display_decryptFormatData(&iStack_18,puStack_14,param_4), iVar2 == 0)) {
              iVar2 = xtra_compareDistinguishedNames(param_2,(undefined4 *)(iStack_18 + 0x24),param_4);
              iVar1 = 0;
              if (iVar2 == 0) goto LAB_68106f22;
            }
            iVar1 = xtra_readBERValue("adding certificate to list object",iVar2,param_4);
            if (iVar1 != 0) break;
            xtra_removeCertByIndex(param_1,uStack_20);
          }
          else {
            iVar1 = xtra_readBERValue("adding certificate to list object",iVar1,param_4);
            if (iVar1 != 0) break;
          }
LAB_68106f22:
          uVar3 = uVar3 + 1;
          xtra_freeBERContent(aiStack_8,(int)local_1c);
        } while (uVar3 < uStack_c);
      }
    }
    else if (iVar1 != 0x100) {
      iVar1 = 0x113;
    }
    xtra_resetBER((int *)&local_1c);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_selectCRLFromStore (FUN_68106f60)
// Address: 68106f60
// Size: 275 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, uint param_4, int param_5, undefined4 * param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_selectCRLFromStore(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,uint param_4,int param_5,
            undefined4 *param_6)

{
  int iVar1;
  undefined4 *local_14;
  int iStack_10;
  int iStack_c;
  undefined4 auStack_8 [2];
  
  iVar1 = xtra_destroyContainer((int *)&local_14);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(param_5 + 0x14))
                      (local_14,*param_3,param_3[1],param_4,*(undefined4 *)(param_5 + 0x1c));
    if (iVar1 == 0) {
      iVar1 = xtra_getContainerRef(&iStack_c,local_14);
      if (iVar1 == 0) {
        if (iStack_c == 0) {
          iVar1 = 300;
        }
        else {
          iVar1 = xtra_queryContainerEx(auStack_8,param_2,0,local_14);
          if (iVar1 == 0) {
            iVar1 = xtra_loadCryptoFromCert(param_1,auStack_8,param_6);
            if (iVar1 == 0) {
              iVar1 = xtra_finalizeCrypto(&iStack_10,param_1,param_6);
              if ((iVar1 == 0) && (iVar1 = 300, *(uint *)(iStack_10 + 0x10) <= param_4)) {
                iVar1 = xtra_compareDistinguishedNames(param_3,(undefined4 *)(iStack_10 + 8),param_6);
              }
            }
          }
        }
      }
    }
    else if (iVar1 != 0x100) {
      iVar1 = 0x113;
    }
    xtra_resetBER((int *)&local_14);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_decodeCertPublicKey (FUN_68107080)
// Address: 68107080
// Size: 119 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3, uint param_4, uint * param_5, undefined4 * param_6, undefined4 * param_7, undefined4 param_8
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_decodeCertPublicKey(int *param_1,int *param_2,undefined4 *param_3,uint param_4,uint *param_5,
            undefined4 *param_6,undefined4 *param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 *local_4;
  
  iVar1 = xtra_initContainer((int *)&local_4);
  if (iVar1 == 0) {
    iVar1 = xtra_buildCertChainEntry(local_4,0,param_3,0,param_4,param_5,param_6,param_7,param_8);
    if (iVar1 == 0) {
      iVar1 = xtra_getCertChainInfo(param_1,param_2,local_4);
    }
    display_releaseFormatData((int *)&local_4);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_verifyCRLSignature (FUN_68107100)
// Address: 68107100
// Size: 295 bytes
// Params: undefined4 * param_1, undefined4 param_2, uint * param_3, int param_4, undefined4 * param_5, undefined4 param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_verifyCRLSignature(undefined4 *param_1,undefined4 param_2,uint *param_3,int param_4,undefined4 *param_5,
            undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int local_18;
  undefined4 *local_14;
  int local_10;
  undefined4 *local_c;
  int local_8 [2];
  
  local_18 = 0;
  local_14 = (undefined4 *)0x0;
  iVar1 = display_freeNetSecurity(&local_18);
  if (iVar1 == 0) {
    iVar1 = xtra_initContainer((int *)&local_14);
    if (iVar1 == 0) {
      iVar1 = xtra_finalizeCrypto(&local_10,param_1,param_5);
      if (iVar1 == 0) {
        iVar1 = xtra_verifyCertChain(local_18,(int *)0x0,local_14,0,(undefined4 *)(local_10 + 8),param_2,
                             param_3,0,param_4,param_5,param_6);
        if (iVar1 == 0) {
          iVar1 = xtra_extractPublicKeyData(local_8,param_1,param_5);
          if (iVar1 == 0) {
            iVar1 = xtra_extractCertPublicKey(&local_c,param_1,param_5);
            if (iVar1 == 0) {
              iVar2 = xtra_setupCryptoMode(local_8,local_c,local_10,local_18,param_5,param_6);
              iVar1 = 0;
              if (iVar2 != 0) {
                iVar1 = xtra_decodeBER("verifying CRL signature",iVar2,0x10c,param_5);
              }
            }
          }
        }
      }
    }
  }
  else {
    iVar1 = 0x100;
  }
  display_releaseNetSecurity(&local_18);
  display_releaseFormatData((int *)&local_14);
  return iVar1;
}



// ============================================================
// Function: xtra_compareCertFields (FUN_68107230)
// Address: 68107230
// Size: 44 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_compareCertFields(undefined4 *param_1,undefined4 *param_2)

{
  uint uVar1;
  
  if (param_2[1] == param_1[1]) {
    uVar1 = display_decodeFormat((byte *)*param_1,(byte *)*param_2,param_1[1]);
    if (uVar1 == 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_verifySelfSignedCert (FUN_68107260)
// Address: 68107260
// Size: 305 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_verifySelfSignedCert(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  int local_14;
  int local_10;
  undefined4 *local_c;
  int local_8 [2];
  
  local_14 = 0;
  *param_1 = 0;
  iVar1 = display_decryptFormatData(&local_10,param_2,param_3);
  if ((iVar1 == 0) &&
     (iVar2 = xtra_compareCertFields((undefined4 *)(local_10 + 0x14),(undefined4 *)(local_10 + 0x24)),
     iVar2 != 0)) {
    iVar1 = display_freeNetSecurity(&local_14);
    if (iVar1 == 0) {
      iVar1 = xtra_verifyCertExt(local_14,(int *)0x0,local_10 + 0x2c,param_3);
      if (iVar1 == 0) {
        iVar1 = display_getObjectExtension(&local_c,param_2,param_3);
        if (((iVar1 == 0) && (iVar1 = display_getObjectBlockData(local_8,param_2,param_3), iVar1 == 0)) &&
           (iVar1 = xtra_setupCryptoMode(local_8,local_c,local_10 + 0xc,local_14,param_3,param_4),
           iVar1 == 0)) {
          *param_1 = 1;
        }
      }
      else {
        iVar1 = xtra_decodeBER("setting self-signed cert public key",iVar1,0x10d,param_3);
      }
    }
    else {
      iVar1 = 0x100;
    }
  }
  display_releaseNetSecurity(&local_14);
  if ((iVar1 != 0) &&
     (iVar1 = xtra_readBERValue("verifying self-signed cert signature",iVar1,param_3), iVar1 != 0))
  {
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: xtra_compareDistinguishedNames (FUN_681073a0)
// Address: 681073a0
// Size: 652 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_compareDistinguishedNames(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint local_40;
  byte *local_3c;
  byte *local_38;
  int local_34;
  uint local_30;
  undefined4 *local_2c;
  undefined4 *local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  byte *local_14;
  byte *local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  local_28 = (undefined4 *)0x0;
  local_2c = (undefined4 *)0x0;
  if (param_2[1] != param_1[1]) {
    return 300;
  }
  uVar1 = display_decodeFormat((byte *)*param_1,(byte *)*param_2,param_1[1]);
  if (uVar1 == 0) {
    return 0;
  }
  iVar2 = xtra_initContainer((int *)&local_28);
  if ((((iVar2 == 0) &&
       (iVar2 = display_decryptBlock(local_28,(byte *)*param_1,param_1[1],param_3), iVar2 == 0)) &&
      (iVar2 = xtra_initContainer((int *)&local_2c), iVar2 == 0)) &&
     (iVar2 = display_decryptBlock(local_2c,(byte *)*param_2,param_2[1],param_3), iVar2 == 0)) {
    iVar2 = display_encryptBlock(&local_8,local_28,param_3);
    if (iVar2 == 0) {
      iVar2 = display_encryptBlock(&local_4,local_2c,param_3);
      if (iVar2 == 0) {
        if (local_4 == local_8) {
          uVar1 = 0;
          iVar2 = 0;
          if (local_8 != 0) {
            do {
              iVar2 = display_decryptBlockEx(&local_14,&local_30,&local_34,&local_3c,&local_40,&local_20,
                                   local_28,uVar1,param_3);
              if (iVar2 != 0) {
                iVar2 = xtra_decodeBER("checking case ignore names",iVar2,0x10a,param_3);
                goto LAB_68107608;
              }
              iVar2 = display_decryptBlockEx(&local_10,&local_c,&local_18,&local_38,&local_1c,&local_24,
                                   local_2c,uVar1,param_3);
              if (iVar2 != 0) {
                iVar2 = xtra_decodeBER("checking case ignore names",iVar2,0x10a,param_3);
                goto LAB_68107608;
              }
              if (((local_30 != local_c) ||
                  (uVar3 = display_decodeFormat(local_14,local_10,local_30), uVar3 != 0)) ||
                 ((local_18 != local_34 || ((local_40 != local_1c || (local_24 != local_20))))))
              goto LAB_68107603;
              if (local_34 == 0x13) {
                iVar2 = xtra_compareCaseInsensitive(local_3c,local_38,local_40);
                if (iVar2 == 0) goto LAB_68107603;
              }
              else {
                uVar3 = display_decodeFormat(local_3c,local_38,local_40);
                if (uVar3 != 0) goto LAB_68107603;
              }
              uVar1 = uVar1 + 1;
            } while (uVar1 < local_8);
            iVar2 = 0;
          }
        }
        else {
LAB_68107603:
          iVar2 = 300;
        }
      }
      else {
        iVar2 = xtra_decodeBER("checking case ignore names",iVar2,0x10a,param_3);
      }
    }
    else {
      iVar2 = xtra_decodeBER("checking case ignore names",iVar2,0x10a,param_3);
    }
  }
LAB_68107608:
  display_releaseFormatData((int *)&local_28);
  display_releaseFormatData((int *)&local_2c);
  return iVar2;
}



// ============================================================
// Function: xtra_compareCaseInsensitive (FUN_68107630)
// Address: 68107630
// Size: 95 bytes
// Params: byte * param_1, byte * param_2, int param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_compareCaseInsensitive(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  
  while( true ) {
    if (param_3 == 0) {
      return 1;
    }
    param_3 = param_3 + -1;
    bVar1 = *param_1;
    if ((bVar1 < 0x61) || (0x7a < bVar1)) {
      uVar3 = (uint)bVar1;
    }
    else {
      uVar3 = bVar1 - 0x20;
    }
    bVar1 = *param_2;
    if ((bVar1 < 0x61) || (0x7a < bVar1)) {
      uVar2 = (uint)bVar1;
    }
    else {
      uVar2 = bVar1 - 0x20;
    }
    if (uVar3 != uVar2) break;
    param_1 = param_1 + 1;
    param_2 = param_2 + 1;
  }
  return 0;
}



// ============================================================
// Function: xtra_verifyCertExt (FUN_68107690)
// Address: 68107690
// Size: 115 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_verifyCertExt(int param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined **ppuVar4;
  
  ppuVar4 = &PTR_DAT_6818f518;
  puVar1 = PTR_DAT_6818f518;
  while( true ) {
    if (puVar1 == (undefined *)0x0) {
      return 0x12e;
    }
    iVar2 = display_loadNetSecurityData(param_1,*(undefined **)(*ppuVar4 + 4),param_3);
    if (iVar2 == 0) break;
    if (iVar2 != 0x21e) {
      uVar3 = xtra_decodeBERDirect("setting public key",iVar2,0x10a,param_4);
      return uVar3;
    }
    ppuVar4 = ppuVar4 + 1;
    puVar1 = *ppuVar4;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = (int)*ppuVar4;
  }
  return 0;
}



// ============================================================
// Function: xtra_lookupHashAlgorithm (FUN_68107710)
// Address: 68107710
// Size: 52 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_lookupHashAlgorithm(int *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = xtra_encodeAlgorithmByOID(param_1,param_2,(int *)&PTR_DAT_6818f590,param_3);
  if (iVar1 != 0) {
    iVar2 = 0x127;
    if (iVar1 != 300) {
      iVar2 = iVar1;
    }
    return iVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_loadEncryptAlgorithm (FUN_68107750)
// Address: 68107750
// Size: 52 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_loadEncryptAlgorithm(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = xtra_loadAlgorithmByOID(param_1,param_2,(int *)&PTR_DAT_6818f550,param_3);
  if (iVar1 != 0) {
    iVar2 = 0x13f;
    if (iVar1 != 0x12e) {
      iVar2 = iVar1;
    }
    return iVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_getEncryptAlgorithmInfo (FUN_68107790)
// Address: 68107790
// Size: 80 bytes
// Params: undefined4 * param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getEncryptAlgorithmInfo(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  iVar1 = xtra_parseCertBlock(&local_4,param_2,(int *)&PTR_DAT_6818f550,param_3);
  if (iVar1 != 0) {
    iVar2 = 0x13f;
    if (iVar1 != 300) {
      iVar2 = iVar1;
    }
    return iVar2;
  }
  *param_1 = *(undefined4 *)(&PTR_DAT_6818f550)[local_4];
  return 0;
}



// ============================================================
// Function: xtra_loadHashAlgorithmById (FUN_681077e0)
// Address: 681077e0
// Size: 89 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_loadHashAlgorithmById(int param_1,int param_2)

{
  int iVar1;
  int local_4;
  
  iVar1 = xtra_findAlgorithmById(&local_4,param_2,(int *)&PTR_DAT_6818f590);
  if (iVar1 != 0) {
    return 0x128;
  }
  iVar1 = display_loadFormatData(param_1,*(undefined **)((&PTR_DAT_6818f590)[local_4] + 4),0);
  return (iVar1 == 0) - 1 & 0x100;
}



// ============================================================
// Function: xtra_getHashAlgorithmInfo (FUN_681078a0)
// Address: 681078a0
// Size: 80 bytes
// Params: undefined4 * param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getHashAlgorithmInfo(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  iVar1 = xtra_parseCertBlock(&local_4,param_2,(int *)&PTR_DAT_6818f590,param_3);
  if (iVar1 != 0) {
    iVar2 = 0x128;
    if (iVar1 != 300) {
      iVar2 = iVar1;
    }
    return iVar2;
  }
  *param_1 = *(undefined4 *)(&PTR_DAT_6818f590)[local_4];
  return 0;
}



// ============================================================
// Function: xtra_setupDEKAlgorithm (FUN_681078f0)
// Address: 681078f0
// Size: 211 bytes
// Params: undefined4 param_1, int * param_2, int * param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_setupDEKAlgorithm(undefined4 param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  int local_4;
  
  iVar1 = xtra_parseCertBlock(&local_c,param_2,(int *)&PTR_DAT_6818f5e0,param_4);
  if (iVar1 != 0) {
    iVar2 = 0x115;
    if (iVar1 != 300) {
      iVar2 = iVar1;
    }
    return iVar2;
  }
  iVar1 = display_processNetSecurityOp(&local_8,param_2,*(undefined **)((&PTR_DAT_6818f5e0)[local_c] + 4));
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBERDirect("reading DEK algorithm ID",iVar1,0x112,param_4);
    return iVar1;
  }
  iVar1 = display_loadCertChainData(&local_4,param_3,&LAB_6810d0b0);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBERDirect("reading DEK Key data",iVar1,0x112,param_4);
    return iVar1;
  }
  (**(code **)((&PTR_DAT_6818f5e0)[local_c] + 0xc))(param_1,local_8,local_4);
  return 0;
}



// ============================================================
// Function: xtra_loadAlgorithmByOID (FUN_681079d0)
// Address: 681079d0
// Size: 98 bytes
// Params: int param_1, undefined4 param_2, int * param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_loadAlgorithmByOID(int param_1,undefined4 param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = *param_3;
  while( true ) {
    if (iVar1 == 0) {
      return 0x12e;
    }
    iVar1 = display_loadFormatData(param_1,*(undefined **)(*param_3 + 8),param_2);
    if (iVar1 == 0) break;
    if (iVar1 != 0x21d) {
      uVar2 = xtra_decodeBERDirect("decoding algorithm ID",iVar1,0x10a,param_4);
      return uVar2;
    }
    param_3 = param_3 + 1;
    iVar1 = *param_3;
  }
  return 0;
}



// ============================================================
// Function: xtra_encodeAlgorithmByOID (FUN_68107a40)
// Address: 68107a40
// Size: 103 bytes
// Params: int * param_1, int * param_2, int * param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_encodeAlgorithmByOID(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  int local_4;
  
  iVar1 = xtra_parseCertBlock(&local_4,param_2,param_3,param_4);
  if (iVar1 == 0) {
    iVar1 = display_processNetSecurityOp(param_1,param_2,*(undefined **)(param_3[local_4] + 8));
    if (iVar1 != 0) {
      iVar1 = xtra_decodeBERDirect("encoding BER algorithm ID",iVar1,0x124,param_4);
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_findAlgorithmById (FUN_68107ab0)
// Address: 68107ab0
// Size: 51 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_findAlgorithmById(int *param_1,int param_2,int *param_3)

{
  int local_8;
  int local_18;
  int iVar1;
  
  *param_1 = 0;
  iVar1 = *param_3;
  while( true ) {
    if (iVar1 == 0) {
      return 300;
    }
    if (*(int *)*param_3 == param_2) break;
    param_3 = param_3 + 1;
    *param_1 = *param_1 + 1;
    iVar1 = *param_3;
  }
  return 0;
}



// ============================================================
// Function: xtra_parseCertBlock (FUN_68107af0)
// Address: 68107af0
// Size: 126 bytes
// Params: int * param_1, int * param_2, int * param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_parseCertBlock(int *param_1,int *param_2,int *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  int local_4;
  
  *param_1 = 0;
  iVar1 = *param_3;
  while( true ) {
    if (iVar1 == 0) {
      return 300;
    }
    iVar1 = display_processNetSecurityOp(&local_4,param_2,*(undefined **)(param_3[*param_1] + 4));
    if (iVar1 == 0) break;
    if (iVar1 != 0x21d) {
      uVar2 = xtra_decodeBERDirect("getting algorithm info by object",iVar1,0x124,param_4);
      return uVar2;
    }
    iVar1 = *param_1;
    *param_1 = iVar1 + 1;
    iVar1 = param_3[iVar1 + 1];
  }
  return 0;
}



// ============================================================
// Function: xtra_setupDESCBC (FUN_68107b70)
// Address: 68107b70
// Size: 203 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, undefined4 * param_5, undefined4 param_6
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_setupDESCBC(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5,
            undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_10 [8];
  undefined1 local_8 [8];
  
  uVar1 = xtra_encryptData(param_4,local_8,8,param_6);
  if ((uVar1 == 0) && (uVar1 = display_loadFormatData(param_1,&LAB_6810fb50,local_8), uVar1 == 0)) {
    do {
      uVar1 = xtra_encryptData(param_4,local_10,8,param_6);
      if (uVar1 != 0) break;
      uVar1 = display_loadNetSecurityData(param_2,&LAB_6810fe70,local_10);
    } while (uVar1 == 0x222);
  }
  display_fillMemory(local_10,0,8);
  display_fillMemory(local_8,0,8);
  if (uVar1 == 0) {
    return 0;
  }
  uVar2 = xtra_decodeBERDirect("setting DES-CBC algorithm",uVar1,0x112,param_5);
  return uVar2;
}



// ============================================================
// Function: xtra_setupRC2CBC (FUN_68107c40)
// Address: 68107c40
// Size: 233 bytes
// Params: int param_1, int param_2, uint param_3, int param_4, undefined4 * param_5, undefined4 param_6
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_setupRC2CBC(int param_1,int param_2,uint param_3,int param_4,undefined4 *param_5,undefined4 param_6
            )

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_28 [8];
  uint local_20;
  undefined1 *local_1c;
  undefined1 local_18 [24];
  
  uVar1 = xtra_encryptData(param_4,local_28,8,param_6);
  if (uVar1 == 0) {
    uVar1 = xtra_encryptData(param_4,local_18,0x18,param_6);
    if (uVar1 == 0) {
      uVar1 = display_loadNetSecurityData(param_2,&LAB_6810ffb0,local_18);
      if (uVar1 == 0) {
        local_1c = local_28;
        local_20 = ((param_3 & 0x3fc0) >> 6) + 0x20 & 0xff;
        uVar1 = display_loadFormatData(param_1,&LAB_6810fb00,&local_20);
      }
    }
  }
  display_fillMemory(local_18,0,0x18);
  display_fillMemory(local_28,0,8);
  if (uVar1 != 0) {
    uVar2 = xtra_decodeBERDirect("setting RC2-CBC algorithm",uVar1,0x112,param_5);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_setupDESEDE3CBC (FUN_68107d30)
// Address: 68107d30
// Size: 203 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, undefined4 * param_5, undefined4 param_6
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_setupDESEDE3CBC(int param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5,
            undefined4 param_6)

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_20 [8];
  undefined1 local_18 [24];
  
  uVar1 = xtra_encryptData(param_4,local_20,8,param_6);
  if ((uVar1 == 0) && (uVar1 = display_loadFormatData(param_1,&LAB_6810fab0,local_20), uVar1 == 0)) {
    do {
      uVar1 = xtra_encryptData(param_4,local_18,0x18,param_6);
      if (uVar1 != 0) break;
      uVar1 = display_loadNetSecurityData(param_2,&LAB_68110060,local_18);
    } while (uVar1 == 0x222);
  }
  display_fillMemory(local_18,0,0x18);
  display_fillMemory(local_20,0,8);
  if (uVar1 == 0) {
    return 0;
  }
  uVar2 = xtra_decodeBERDirect("setting DES-EDE3-CBC algorithm",uVar1,0x112,param_5);
  return uVar2;
}



// ============================================================
// Function: xtra_setupRC5CBC (FUN_68107e00)
// Address: 68107e00
// Size: 260 bytes
// Params: int param_1, int param_2, uint param_3, int param_4, undefined4 * param_5, undefined4 param_6
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_setupRC5CBC(int param_1,int param_2,uint param_3,int param_4,undefined4 *param_5,undefined4 param_6
            )

{
  uint uVar1;
  undefined4 uVar2;
  undefined1 local_40 [8];
  undefined1 *local_38;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined1 *local_24;
  undefined1 local_20 [32];
  
  uVar1 = xtra_encryptData(param_4,local_40,8,param_6);
  if (uVar1 == 0) {
    uVar1 = xtra_encryptData(param_4,local_20,0x20,param_6);
    if (uVar1 == 0) {
      local_38 = local_20;
      local_34 = (((param_3 & 0xfc0) >> 6) + 5) % 0x21;
      uVar1 = display_loadNetSecurityData(param_2,&LAB_6810d0b0,&local_38);
      if (uVar1 == 0) {
        local_24 = local_40;
        local_30 = 0x10;
        local_2c = 0x10;
        local_28 = 0x20;
        uVar1 = display_loadFormatData(param_1,&LAB_6810fa60,&local_30);
      }
    }
  }
  display_fillMemory(local_20,0,0x20);
  display_fillMemory(local_40,0,8);
  if (uVar1 != 0) {
    uVar2 = xtra_decodeBERDirect("setting RC5-CBC algorithm",uVar1,0x112,param_5);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_clearCertList (FUN_68108160)
// Address: 68108160
// Size: 16 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_clearCertList(int *param_1)
{
  xtra_createCertListBlock(param_1,0);
  return 0;
}



// ============================================================
// Function: xtra_parseCertificate (FUN_68108170)
// Address: 68108170
// Size: 21 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_parseCertificate(undefined4 *param_1,undefined4 *param_2)
{
  xtra_getEncodedCount(param_1,param_2,0);
  return 0;
}



// ============================================================
// Function: xtra_addCertByEncKey (FUN_68108190)
// Address: 68108190
// Size: 116 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 param_4, undefined4 * param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_addCertByEncKey(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  undefined4 *local_4;
  
  local_4 = (undefined4 *)0x0;
  iVar1 = xtra_createCryptoReader((int *)&local_4);
  if (((iVar1 == 0) && (iVar1 = xtra_loadCryptoFromCert(local_4,param_3,param_5), iVar1 == 0)) &&
     (iVar1 = xtra_queryContainer(param_1,(int *)&local_4,param_4,param_2,0), iVar1 == 0)) {
    return 0;
  }
  xtra_initCryptoContext((int *)&local_4);
  return iVar1;
}



// ============================================================
// Function: strftime
// Address: 68108210
// Size: 31 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, uint param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

/* Library Function - Single Match
    _strftime
   
   Library: Visual Studio 1998 Release */

/* FIXUP(C2371: 'strftime': redefinition; different basic types): void __cdecl strftime(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,uint param_4) */

/* FIXUP(C2449: found '{' at file scope (missing function header?)): { */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'constant'): xtra_getEncodedEntry(param_1,param_2,param_3,param_4,0); */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return 0; */
/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */



// ============================================================
// Function: xtra_addCertByCopy (FUN_68108230)
// Address: 68108230
// Size: 116 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 param_4, undefined4 * param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_addCertByCopy(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  int iVar1;
  undefined4 *local_4;
  
  local_4 = (undefined4 *)0x0;
  iVar1 = display_resetFormatState((int *)&local_4);
  if (((iVar1 == 0) && (iVar1 = display_copyFormatData(local_4,param_3,param_5), iVar1 == 0)) &&
     (iVar1 = xtra_queryContainer(param_1,(int *)&local_4,param_4,param_2,0), iVar1 == 0)) {
    return 0;
  }
  xtra_initCryptoContext((int *)&local_4);
  return iVar1;
}



// ============================================================
// Function: xtra_removeCertByIndex (FUN_681082d0)
// Address: 681082d0
// Size: 21 bytes
// Params: undefined4 * param_1, uint param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_removeCertByIndex(undefined4 *param_1,uint param_2)
{
  xtra_removeEncodedEntry(param_1,param_2,0);
  return 0;
}



// ============================================================
// Function: xtra_initCryptoSecurity (FUN_681082f0)
// Address: 681082f0
// Size: 113 bytes
// Params: int * param_1, int param_2
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_initCryptoSecurity(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = display_getNetSecurityState(param_1);
  if (iVar1 != 0) {
    return 0x100;
  }
  uVar2 = xtra_loadHashAlgorithmById(*param_1,param_2);
  if (uVar2 == 0) {
    iVar1 = xtra_loadCryptoProvider(*param_1,0,&PTR_PTR_6818f7d0,0);
    if (iVar1 == 0) {
      return 0;
    }
    uVar2 = (-(uint)(iVar1 == 0x206) & 0xffffffe3) + 0x11d;
    if (uVar2 == 0) {
      return 0;
    }
  }
  display_initNetworkSecurity(param_1);
  return uVar2;
}



// ============================================================
// Function: xtra_decryptWithReport (FUN_68108370)
// Address: 68108370
// Size: 57 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_decryptWithReport(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_decryptData(param_1,param_2,param_3,0);
  if (iVar1 != 0) {
    uVar2 = xtra_decodeBERDirect(&DAT_6818eba4,iVar1,0x116,param_4);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_encryptWithReport (FUN_681083b0)
// Address: 681083b0
// Size: 59 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_encryptWithReport(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_encryptDataEx(param_3,param_1,param_2,0x14,0);
  if (iVar1 != 0) {
    uVar2 = xtra_decodeBERDirect(&DAT_6818eba4,iVar1,0x116,param_4);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_destroyCryptoSecurity (FUN_681083f0)
// Address: 681083f0
// Size: 14 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_destroyCryptoSecurity(undefined4 *param_1)
{
  display_initNetworkSecurity(param_1);
  return 0;
}



