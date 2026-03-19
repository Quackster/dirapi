int xtra_getCryptoBlockSize(); /* FIXUP(C2065): missing forward declaration */
int xtra_initCipherFromKey(); /* FIXUP(C2065): missing forward declaration */
// Module: xtra_runtime
// Topic: Crypto, bignum arithmetic, cipher operations, key management, ASN.1 parsing
// Address range: 0x68110220 - 0x681167a0
// Functions (142):
//   xtra_decodeDHCertBlock
//   xtra_encodeDHCertBlock
//   xtra_parseCipherParams
//   xtra_decodeCipherType
//   xtra_lookupCipherOID
//   xtra_initCipherOIDRef
//   xtra_readCryptoStream
//   xtra_initSecureFormat
//   xtra_dispatchEncrypt8
//   xtra_dispatchEncrypt6
//   xtra_dispatchDecrypt8
//   xtra_dispatchDecrypt6
//   xtra_allocCryptoContext
//   xtra_bindCryptoHandler
//   xtra_invokeCryptoOp
//   xtra_getCryptoBlockSize
//   xtra_computeDHSharedKey
//   xtra_computeDHKeyPair
//   xtra_computeHash
//   xtra_shiftBignumLeft
//   xtra_computeMAC
//   xtra_encryptBlock
//   xtra_hashData
//   xtra_trimBignumLeading
//   xtra_countLeadingZeros
//   xtra_decryptBlock
//   xtra_verifySignature
//   xtra_addBignum
//   xtra_addBignumScalar
//   xtra_generateKey
//   xtra_initCryptoKey
//   xtra_modReduce
//   xtra_modExp
//   xtra_computeModInverse
//   xtra_initCryptoSession
//   xtra_squareAndReduceMod
//   xtra_checkCryptoCallback
//   xtra_verifyCert
//   xtra_verifyCertChainEx
//   xtra_signData
//   xtra_prependBignumWord
//   xtra_divBignumEstimate
//   xtra_divDouble
//   xtra_divSingle
//   xtra_computeGCD
//   xtra_extendedGCD
//   xtra_stepExtendedGCD
//   xtra_absSubtract
//   xtra_modInverseFull
//   xtra_multiplyAndReduce
//   xtra_signDataEx
//   xtra_allocRSAContext
//   xtra_allocDSAContext
//   xtra_padPKCS1
//   xtra_initKeyContext
//   xtra_destroyKeyContext
//   xtra_initEncryptKey
//   xtra_initDecryptKey
//   xtra_appendCipherData
//   xtra_transformCipher
//   xtra_finalizeCipher
//   xtra_allocCipherBuffer
//   xtra_writeCipherAttribs
//   xtra_readCipherAttribs
//   xtra_encryptCBC
//   xtra_finalizeCBC
//   xtra_setInitVector
//   xtra_computeMACCBC
//   xtra_resetCBCState
//   xtra_setKeyAndIV
//   xtra_encryptCBCEx
//   xtra_finalizeCBCEx
//   xtra_setKeyAndIVEx
//   xtra_computeMACCBCEx
//   xtra_importSymmetricKey
//   xtra_exportSymmetricKey
//   xtra_generateRandomKey
//   xtra_storeCipherOID
//   xtra_storeCipherParams
//   xtra_allocHashContext
//   xtra_initEncryptKeyEx
//   xtra_finalizePadded
//   xtra_storePublicKey
//   xtra_checkWeakDESKey
//   xtra_fixDESParity
//   xtra_validateDESParity
//   xtra_generateRandom
//   xtra_initCipherState
//   xtra_parseCertAndBind
//   xtra_destroyCipherState
//   xtra_fillCryptoBuffer
//   xtra_finalizeCryptoKey
//   xtra_importKey
//   xtra_dispatchEncryptFull
//   xtra_dispatchDecryptFull
//   xtra_dispatchEncryptShort
//   xtra_dispatchDecryptShort
//   xtra_clearCryptoState
//   xtra_destroyCryptoBuffer
//   xtra_resizeCryptoBuffer
//   xtra_selectCipher
//   xtra_getCryptoKeySize
//   xtra_allocSymKeyContext
//   xtra_destroySymKeyBuffer
//   xtra_getBlockSize
//   xtra_selectEncryptCipher
//   xtra_selectDecryptCipher
//   xtra_updateCipherBlock
//   xtra_finalizeCipherBlock
//   xtra_initCipherFromKey
//   xtra_processCryptoBlock
//   xtra_resetCipherIV
//   xtra_setCipherIV
//   xtra_copyCipherIV
//   xtra_expandKeySchedule
//   xtra_encryptCFB
//   xtra_finalizeCFB
//   xtra_computeMACCFB
//   xtra_resetCFBState
//   xtra_initDESEncrypt
//   xtra_computeDESSchedule
//   xtra_parseCipherFieldSet
//   xtra_writeCipherFieldSet
//   xtra_allocRC2Context
//   xtra_storeCipherKeyData
//   xtra_allocDESContext
//   xtra_allocStreamContext
//   xtra_selectEncryptStream
//   xtra_selectDecryptStream
//   xtra_finalizeStreamBlock
//   xtra_flushStreamCipher
//   xtra_initMD5Digest
//   xtra_feedHashData
//   xtra_finalizeHash
//   xtra_parseBERCert
//   xtra_parseBERCertChunked
//   xtra_initHashKeyContext
//   xtra_bindDecryptHandler
//   xtra_deriveSessionKey
//   xtra_initHashState
//   xtra_updateHashState
//   xtra_finalizeHashState

// ============================================================
// Function: xtra_decodeDHCertBlock (FUN_68110220)
// Address: 68110220
// Size: 216 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_decodeDHCertBlock(int *param_1,int param_2)
{
  int local_2c;
  int iVar1;
  undefined4 *local_64;
  undefined1 *local_60;
  undefined1 *local_5c;
  undefined1 *local_58;
  undefined1 *local_54;
  undefined1 *local_50;
  undefined1 *local_4c;
  undefined1 *local_48;
  undefined1 *local_44;
  undefined1 local_40 [8];
  undefined1 local_38 [8];
  undefined1 local_30 [8];
  undefined1 local_28 [8];
  undefined1 local_20 [8];
  undefined1 local_18 [8];
  undefined1 local_10 [8];
  undefined1 local_8 [8];
  
  iVar1 = xtra_readCertBlock(param_1,(int *)&local_64,0x40);
  if (iVar1 == 0) {
    local_60 = local_40;
    local_5c = local_38;
    local_58 = local_30;
    local_54 = local_28;
    local_50 = local_20;
    local_4c = local_18;
    local_48 = local_10;
    local_44 = local_8;
    iVar1 = xtra_processDHParams((int)local_64,param_2,(int)local_40,(int *)&local_60,8,param_1);
    if (iVar1 == 0) {
      iVar1 = xtra_decodeDHKeyParams(param_1,local_64,local_64 + 2,local_64 + 4,local_64 + 6,local_64 + 10,
                           local_64 + 0xe);
      if (iVar1 == 0) {
        xtra_writeCertBlock(param_1,&PTR_FUN_68190850,local_64);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_encodeDHCertBlock (FUN_68110300)
// Address: 68110300
// Size: 93 bytes
// Params: int * param_1, int * param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_encodeDHCertBlock(int *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int local_40 [4];
  int local_30 [2];
  int local_28 [4];
  int local_18 [4];
  int local_8 [2];
  
  iVar1 = xtra_encodeDHKeyParams(local_40,local_40 + 2,local_30,local_28,local_18,local_8,param_2);
  if (iVar1 == 0) {
    iVar1 = xtra_readCertBlock(param_2,param_1,0x40);
    if (iVar1 == 0) {
      piVar2 = local_40;
      piVar3 = (int *)*param_1;
      for (iVar1 = 0x10; iVar1 != 0; iVar1 = iVar1 + -1) {
        *piVar3 = *piVar2;
        piVar2 = piVar2 + 1;
        piVar3 = piVar3 + 1;
      }
      iVar1 = 0;
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_parseCipherParams (FUN_68110390)
// Address: 68110390
// Size: 217 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_parseCipherParams(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  ushort local_3a;
  undefined4 local_38;
  undefined1 *local_34;
  int local_30;
  undefined1 local_2c [8];
  uint local_24;
  uint local_20;
  uint local_1c;
  undefined1 *local_18;
  undefined1 local_14 [4];
  int local_10;
  undefined4 *local_c;
  ushort *local_8;
  undefined1 **local_4;
  
  display_fillMemory(local_14,0,0x14);
  local_10 = (int)&local_38 + 2;
  local_c = &local_38;
  local_8 = &local_3a;
  display_fillMemory(local_2c,0,8);
  local_34 = local_2c;
  local_4 = &local_34;
  local_30 = 8;
  iVar1 = xtra_readCertField((uint *)0x0,(uint *)&DAT_681908b8,(int)local_14,(byte *)*param_3,param_3[1]);
  if (iVar1 == 0) {
    if (local_30 != 8) {
      return 0x201;
    }
    local_24 = local_38 >> 0x10;
    local_20 = local_38 & 0xffff;
    local_1c = (uint)(local_3a >> 1);
    local_18 = local_34;
    iVar1 = xtra_storeCipherParams(&PTR_PTR_6819062c,param_2,&local_24);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_decodeCipherType (FUN_68110670)
// Address: 68110670
// Size: 161 bytes
// Params: uint * param_1, undefined4 * param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_decodeCipherType(uint *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  ushort local_16;
  uint local_14;
  int local_10;
  undefined1 local_c [4];
  ushort *local_8;
  uint *local_4;
  
  display_fillMemory(local_c,0,0xc);
  local_8 = &local_16;
  local_4 = &local_14;
  iVar1 = xtra_readCertField((uint *)0x0,(uint *)&DAT_68190960,(int)local_c,(byte *)*param_2,param_2[1]);
  if (iVar1 == 0) {
    if (local_10 != 8) {
      return 0x20c;
    }
    param_1[1] = local_14;
    if (local_16 < 0x100) {
      uVar2 = 0;
      do {
        if ((&DAT_68190bc8)[uVar2] == (char)local_16) {
          *param_1 = uVar2;
          return 0;
        }
        uVar2 = uVar2 + 1;
      } while (uVar2 < 0x100);
      return 0x20c;
    }
    *param_1 = (uint)local_16;
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_lookupCipherOID (FUN_68110730)
// Address: 68110730
// Size: 64 bytes
// Params: uint * param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_lookupCipherOID(uint *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 local_8 [2];
  
  xtra_initCipherOIDRef(local_8,param_3);
  iVar1 = xtra_parseCertAndBind(param_1,param_2,local_8);
  if (iVar1 != 0) {
    iVar1 = xtra_getBERLength(iVar1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: xtra_initCipherOIDRef (FUN_68110770)
// Address: 68110770
// Size: 18 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initCipherOIDRef(undefined4 *param_1,undefined4 param_2)
{
  param_1[1] = param_2;
  *param_1 = &PTR_LAB_681909d8;
  return 0;
}



// ============================================================
// Function: xtra_readCryptoStream (FUN_681107c0)
// Address: 681107c0
// Size: 116 bytes
// Params: int param_1, int param_2, uint * param_3, uint param_4
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_readCryptoStream(int param_1,int param_2,uint *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int local_4;
  
  *param_3 = 0;
  if (param_4 != 0) {
    do {
      iVar2 = (**(code **)(*(int *)(param_1 + 4) + 8))
                        (*param_3 + param_2,&local_4,param_4 - *param_3,
                         *(undefined4 *)(*(int *)(param_1 + 4) + 0x14));
      if (iVar2 != 0) {
        return (iVar2 == 0x118) - 1 & 0x122;
      }
      uVar1 = *param_3;
      *param_3 = uVar1 + local_4;
    } while (uVar1 + local_4 < param_4);
  }
  return 0;
}



// ============================================================
// Function: xtra_initSecureFormat (FUN_68110840)
// Address: 68110840
// Size: 59 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initSecureFormat(int param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    iVar1 = display_checkNetSecurity(param_2);
    if (iVar1 == 0) {
      xtra_importKey(param_1,param_2,param_3,param_4);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_dispatchEncrypt8 (FUN_68110880)
// Address: 68110880
// Size: 79 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, int param_7, undefined4 param_8
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_dispatchEncrypt8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,int param_7,undefined4 param_8)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    uVar2 = display_getFormatRef(param_7);
    if (uVar2 == 0) {
      xtra_dispatchEncryptFull(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_dispatchEncrypt6 (FUN_681108d0)
// Address: 681108d0
// Size: 69 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5, undefined4 param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_dispatchEncrypt6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
            undefined4 param_6)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    uVar2 = display_getFormatRef(param_5);
    if (uVar2 == 0) {
      xtra_dispatchEncryptShort(param_1,param_2,param_3,param_4,param_5,param_6);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_dispatchDecrypt8 (FUN_68110960)
// Address: 68110960
// Size: 79 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, int param_7, undefined4 param_8
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_dispatchDecrypt8(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,int param_7,undefined4 param_8)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    uVar2 = display_getFormatRef(param_7);
    if (uVar2 == 0) {
      xtra_dispatchDecryptFull(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_8);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_dispatchDecrypt6 (FUN_681109b0)
// Address: 681109b0
// Size: 69 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5, undefined4 param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_dispatchDecrypt6(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5,
            undefined4 param_6)
{
  int iVar1;
  uint uVar2;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    uVar2 = display_getFormatRef(param_5);
    if (uVar2 == 0) {
      xtra_dispatchDecryptShort(param_1,param_2,param_3,param_4,param_5,param_6);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_allocCryptoContext (FUN_68110a00)
// Address: 68110a00
// Size: 82 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl xtra_allocCryptoContext(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)display_allocBlock(0x24);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  xtra_finalizeCryptoKey(param_1);
  xtra_clearCryptoState(param_1 + 6);
  param_1[5] = xtra_getCryptoBlockSize;
  param_1[3] = param_2;
  param_1[4] = param_3;
  param_1[1] = &PTR_FUN_681909e0;
  return param_1;
}



// ============================================================
// Function: xtra_bindCryptoHandler (FUN_68110a60)
// Address: 68110a60
// Size: 36 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_bindCryptoHandler(int param_1,int *param_2,int *param_3,undefined4 param_4)
{
  xtra_selectCipher((undefined4 *)(param_1 + 8),0,param_2,0,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_invokeCryptoOp (FUN_68110a90)
// Address: 68110a90
// Size: 54 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_invokeCryptoOp(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0xc))
                    (*(undefined4 *)(param_1 + 0x18),param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    uVar2 = xtra_getCryptoKeySize(iVar1);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_getCryptoBlockSize (FUN_68110ad0)
// Address: 68110ad0
// Size: 122 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_getCryptoBlockSize(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int local_18;
  int iVar1;
  uint local_4;
  
  iVar1 = (*(code *)**(undefined4 **)(param_4 + 0xc))(&local_4,*(undefined4 *)(param_1 + 8));
  if (iVar1 != 0) {
    iVar1 = xtra_getCryptoKeySize(iVar1);
    return iVar1;
  }
  iVar1 = xtra_resizeCryptoBuffer((int *)(param_1 + 0x10),local_4);
  if (iVar1 == 0) {
    iVar1 = (**(code **)(*(int *)(param_4 + 0xc) + 4))
                      (*(int *)(param_1 + 0x10),*(undefined4 *)(param_1 + 8),param_5);
    if (iVar1 != 0) {
      iVar1 = xtra_getCryptoKeySize(iVar1);
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_computeDHSharedKey (FUN_68110b60)
// Address: 68110b60
// Size: 836 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_computeDHSharedKey(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int local_54 [3];
  int local_48 [3];
  int local_3c [3];
  int local_30 [3];
  int local_24 [3];
  int local_18 [3];
  int local_c [3];
  
  xtra_clearContext(local_48);
  xtra_clearContext(local_30);
  xtra_clearContext(local_54);
  xtra_clearContext(local_3c);
  xtra_clearContext(local_18);
  xtra_clearContext(local_24);
  xtra_clearContext(local_c);
  iVar1 = xtra_initCryptoKey(*(int *)(param_1 + 0x18),*(uint *)(param_1 + 0x1c),local_48);
  if (iVar1 == 0) {
    iVar1 = xtra_initCryptoKey(*(int *)(param_1 + 0x20),*(uint *)(param_1 + 0x24),local_30);
    if (iVar1 == 0) {
      iVar1 = xtra_deriveKey(1,(int)local_48);
      if (iVar1 == 0) {
        iVar1 = xtra_deriveKey(1,(int)local_30);
        if (iVar1 == 0) {
          iVar1 = xtra_computeGCD((int)local_48,(int)local_30,local_54);
          if (iVar1 == 0) {
            iVar1 = xtra_verifyCertChainEx(local_48,local_54,local_18,local_3c);
            if (iVar1 == 0) {
              iVar1 = xtra_initCryptoKey(*(int *)(param_1 + 0x28),*(uint *)(param_1 + 0x2c),local_3c);
              if (iVar1 == 0) {
                iVar1 = xtra_signData(local_3c,local_18,local_48);
                if (iVar1 == 0) {
                  iVar1 = xtra_initCryptoKey(*(int *)(param_1 + 0x30),*(uint *)(param_1 + 0x34),local_54);
                  if (iVar1 == 0) {
                    iVar1 = xtra_signDataEx(local_48,local_18,local_3c);
                    if (iVar1 == 0) {
                      iVar1 = xtra_signDataEx(local_54,local_30,local_24);
                      if (iVar1 == 0) {
                        iVar2 = xtra_verifySignature((int)local_3c,(int)local_24);
                        if (iVar2 != 0) {
                          iVar1 = xtra_signDataEx(local_18,local_30,local_48);
                          if (iVar1 != 0) goto LAB_68110e2a;
                          iVar1 = xtra_modInverseFull((int)local_24,(int)local_3c,local_30,local_54);
                          if (iVar1 != 0) goto LAB_68110e2a;
                          iVar1 = xtra_multiplyAndReduce((int)local_54,(int)local_48,local_30,local_c);
                          if (iVar1 != 0) goto LAB_68110e2a;
                          iVar1 = xtra_verifyCert((int)local_c,(int)local_18,local_54);
                          if (iVar1 != 0) goto LAB_68110e2a;
                          iVar1 = xtra_addBignum((int)local_54,(int)local_3c,local_24);
                        }
                        if (iVar1 == 0) {
                          iVar1 = xtra_destroyCryptoKey((int)local_24);
                          uVar3 = (int)(iVar1 + 7 + (iVar1 + 7 >> 0x1f & 7U)) >> 3;
                          iVar1 = xtra_readCertBlock(param_2,(int *)(param_1 + 8),uVar3);
                          if (iVar1 == 0) {
                            iVar1 = xtra_initCryptoBuffer((int)local_24,uVar3,(uint *)(param_1 + 0xc),
                                                 *(char **)(param_1 + 8));
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
LAB_68110e2a:
  xtra_freeContext(local_48);
  xtra_freeContext(local_30);
  xtra_freeContext(local_54);
  xtra_freeContext(local_3c);
  xtra_freeContext(local_18);
  xtra_freeContext(local_24);
  xtra_freeContext(local_c);
  if (iVar1 != 0) {
    uVar4 = xtra_getCryptoState(iVar1);
    return uVar4;
  }
  return 0;
}



// ============================================================
// Function: xtra_computeDHKeyPair (FUN_68110eb0)
// Address: 68110eb0
// Size: 444 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_computeDHKeyPair(int param_1,int *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int local_30 [3];
  int local_24 [3];
  int local_18 [3];
  int local_c [3];
  
  xtra_clearContext(local_30);
  xtra_clearContext(local_18);
  xtra_clearContext(local_c);
  xtra_clearContext(local_24);
  if (*(int *)(param_1 + 8) == 0) {
    iVar1 = xtra_computeDHSharedKey(param_1,param_2);
    if (iVar1 != 0) goto LAB_68111019;
  }
  iVar1 = xtra_initCryptoKey(*(int *)(param_1 + 0x18),*(uint *)(param_1 + 0x1c),local_30);
  if (iVar1 == 0) {
    iVar1 = xtra_initCryptoKey(*(int *)(param_1 + 0x20),*(uint *)(param_1 + 0x24),local_18);
    if (iVar1 == 0) {
      iVar1 = xtra_deriveKey(1,(int)local_30);
      if (iVar1 == 0) {
        iVar1 = xtra_deriveKey(1,(int)local_18);
        if (iVar1 == 0) {
          iVar1 = xtra_verifyCert((int)local_30,(int)local_18,local_c);
          if (iVar1 == 0) {
            iVar1 = xtra_initCryptoKey(*(int *)(param_1 + 8),*(uint *)(param_1 + 0xc),local_30);
            if (iVar1 == 0) {
              iVar1 = xtra_signDataEx(local_30,local_c,local_24);
              if (iVar1 == 0) {
                iVar1 = xtra_destroyCryptoKey((int)local_24);
                uVar2 = (int)(iVar1 + 7 + (iVar1 + 7 >> 0x1f & 7U)) >> 3;
                iVar1 = xtra_readCertBlock(param_2,(int *)(param_1 + 0x10),uVar2);
                if (iVar1 == 0) {
                  iVar1 = xtra_initCryptoBuffer((int)local_24,uVar2,(uint *)(param_1 + 0x14),
                                       *(char **)(param_1 + 0x10));
                }
              }
            }
          }
        }
      }
    }
  }
LAB_68111019:
  xtra_freeContext(local_30);
  xtra_freeContext(local_18);
  xtra_freeContext(local_c);
  xtra_freeContext(local_24);
  if (iVar1 != 0) {
    uVar3 = xtra_getCryptoState(iVar1);
    return uVar3;
  }
  return 0;
}



// ============================================================
// Function: xtra_computeHash (FUN_681110b0)
// Address: 681110b0
// Size: 230 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_computeHash(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint *puVar8;
  uint *puVar9;
  uint *puVar10;
  int local_c;
  
  puVar1 = *(uint **)(param_2 + 8);
  iVar5 = *(int *)(param_2 + 4);
  piVar6 = *(int **)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 4);
  if (iVar5 < iVar2) {
    return 0x109;
  }
  local_c = 0;
  puVar9 = puVar1;
  puVar10 = puVar1;
  if (0 < iVar2) {
    do {
      uVar3 = *puVar9;
      uVar4 = uVar3 - *piVar6;
      *puVar9 = uVar4;
      puVar10 = (uint *)(uint)(uVar3 < uVar4);
      if ((puVar10 != (uint *)0x0) && (iVar7 = local_c + 1, iVar7 < iVar5)) {
        puVar8 = puVar1 + iVar7;
        do {
          uVar4 = *puVar8;
          uVar3 = uVar4 - 1;
          *puVar8 = uVar3;
          puVar10 = (uint *)(uint)(uVar4 < uVar3);
          if (puVar10 == (uint *)0x0) break;
          puVar8 = puVar8 + 1;
          iVar7 = iVar7 + 1;
        } while (iVar7 < iVar5);
      }
      piVar6 = piVar6 + 1;
      local_c = local_c + 1;
      puVar9 = puVar9 + 1;
    } while (local_c < iVar2);
  }
  if (puVar10 == (uint *)0x0) {
    iVar5 = *(int *)(*(int *)(param_2 + 8) + -4 + *(int *)(param_2 + 4) * 4);
    while ((iVar5 == 0 && (1 < *(int *)(param_2 + 4)))) {
      iVar5 = *(int *)(param_2 + 4) + -1;
      *(int *)(param_2 + 4) = iVar5;
      iVar5 = *(int *)(*(int *)(param_2 + 8) + -4 + iVar5 * 4);
    }
    return 0;
  }
  return 0x109;
}



// ============================================================
// Function: xtra_shiftBignumLeft (FUN_681111a0)
// Address: 681111a0
// Size: 276 bytes
// Params: int param_1, int * param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_shiftBignumLeft(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int local_10;
  int local_c [2];
  undefined4 local_4;
  
  if (param_1 < 1) {
    return 0;
  }
  iVar1 = param_2[1];
  iVar2 = param_1 + iVar1;
  if (*param_2 < iVar2) {
    xtra_clearContext(local_c);
    local_10 = xtra_decryptBlock((int)param_2,local_c);
    if ((local_10 == 0) && (local_10 = xtra_growCryptoBuffer(iVar2 + 1,param_2), local_10 == 0)) {
      display_fillMemory((void *)param_2[2],0,param_1 * 4);
      display_checkAndFree(param_1 * 4 + param_2[2],local_4,iVar1 << 2);
      iVar1 = *(int *)(param_2[2] + -4 + iVar2 * 4);
      while ((iVar1 == 0 && (1 < iVar2))) {
        iVar2 = iVar2 + -1;
        iVar1 = *(int *)(param_2[2] + -4 + iVar2 * 4);
      }
      param_2[1] = iVar2;
    }
    xtra_freeContext(local_c);
    return local_10;
  }
  display_allocFormatBlock(param_2[2] + param_1 * 4,param_2[2],iVar1 << 2);
  display_fillMemory((void *)param_2[2],0,param_1 << 2);
  iVar1 = *(int *)(param_2[2] + -4 + iVar2 * 4);
  while ((iVar1 == 0 && (1 < iVar2))) {
    iVar2 = iVar2 + -1;
    iVar1 = *(int *)(param_2[2] + -4 + iVar2 * 4);
  }
  param_2[1] = iVar2;
  return 0;
}



// ============================================================
// Function: xtra_computeMAC (FUN_681112c0)
// Address: 681112c0
// Size: 202 bytes
// Params: uint param_1, int * param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_computeMAC(uint param_1,int *param_2)

{
  int *piVar1;
  bool bVar2;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint *puVar6;
  uint uVar7;
  
  if ((int)param_1 < 1) {
    return 0;
  }
  if (0x1f < param_1) {
    iVar4 = xtra_shiftBignumLeft(param_1 >> 5,param_2);
    if (iVar4 != 0) {
      return iVar4;
    }
    param_1 = param_1 & 0x1f;
    if (param_1 == 0) {
      return 0;
    }
  }
  iVar4 = param_2[1];
  bVar3 = (byte)param_1;
  uVar7 = *(uint *)(param_2[2] + -4 + iVar4 * 4) >> (0x20 - bVar3 & 0x1f);
  if (uVar7 != 0) {
    if ((*param_2 < iVar4 + 1) && (iVar5 = xtra_getCryptoKeyData(iVar4 + 2,param_2), iVar5 != 0)) {
      return iVar5;
    }
    *(uint *)(param_2[2] + iVar4 * 4) = uVar7;
    param_2[1] = param_2[1] + 1;
  }
  piVar1 = (int *)param_2[2];
  iVar5 = iVar4 + -1;
  if (iVar5 != 0) {
    piVar1[iVar5] = piVar1[iVar5] << (bVar3 & 0x1f);
    if (0 < iVar5) {
      puVar6 = (uint *)(piVar1 + iVar4 + -2);
      iVar4 = iVar4 + -2;
      do {
        puVar6[1] = puVar6[1] | *puVar6 >> (0x20 - bVar3 & 0x1f);
        *puVar6 = *puVar6 << (bVar3 & 0x1f);
        puVar6 = puVar6 + -1;
        bVar2 = 0 < iVar4;
        iVar4 = iVar4 + -1;
      } while (bVar2);
    }
    return 0;
  }
  *piVar1 = *piVar1 << (bVar3 & 0x1f);
  return 0;
}



// ============================================================
// Function: xtra_encryptBlock (FUN_68111390)
// Address: 68111390
// Size: 65 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_encryptBlock(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = *(int *)(param_2 + 4) - param_1;
  *(int *)(param_2 + 4) = iVar1;
  if (0 < iVar1) {
    display_allocFormatBlock(*(int *)(param_2 + 8),*(int *)(param_2 + 8) + param_1 * 4,iVar1 * 4);
    return 0;
  }
  *(undefined4 *)(param_2 + 4) = 1;
  **(undefined4 **)(param_2 + 8) = 0;
  return 0;
}



// ============================================================
// Function: xtra_hashData (FUN_681113e0)
// Address: 681113e0
// Size: 175 bytes
// Params: uint param_1, int param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_hashData(uint param_1,int param_2)

{
  uint *puVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  
  if ((int)param_1 < 1) {
    return 0;
  }
  if (0x1f < param_1) {
    iVar3 = xtra_encryptBlock(param_1 >> 5,param_2);
    if (iVar3 != 0) {
      return iVar3;
    }
    param_1 = param_1 & 0x1f;
    if (param_1 == 0) {
      return 0;
    }
  }
  bVar2 = (byte)param_1;
  puVar1 = *(uint **)(param_2 + 8);
  iVar4 = *(int *)(param_2 + 4) + -1;
  puVar5 = puVar1;
  iVar3 = iVar4;
  if (0 < iVar4) {
    do {
      iVar3 = iVar3 + -1;
      *puVar5 = puVar5[1] << (0x20 - bVar2 & 0x1f) | *puVar5 >> (bVar2 & 0x1f);
      puVar5 = puVar5 + 1;
    } while (iVar3 != 0);
  }
  puVar1 = puVar1 + iVar4;
  uVar6 = *puVar1 >> (bVar2 & 0x1f);
  *puVar1 = uVar6;
  if ((uVar6 == 0) && (iVar4 != 0)) {
    *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + -1;
  }
  return 0;
}



// ============================================================
// Function: xtra_trimBignumLeading (FUN_68111490)
// Address: 68111490
// Size: 39 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_trimBignumLeading(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)(*(int *)(param_2 + 8) + param_1 * 4);
  iVar1 = *piVar2;
  for (; (iVar1 == 0 && (0 < param_1)); param_1 = param_1 + -1) {
    piVar2 = piVar2 + -1;
    iVar1 = *piVar2;
  }
  *(int *)(param_2 + 4) = param_1 + 1;
  return 0;
}



// ============================================================
// Function: xtra_countLeadingZeros (FUN_681114c0)
// Address: 681114c0
// Size: 59 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_countLeadingZeros(int param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  uVar1 = *(uint *)(*(int *)(param_1 + 8) + -4 + *(int *)(param_1 + 4) * 4);
  if (uVar1 == 0) {
    *param_2 = 0x20;
    return 0;
  }
  for (; (uVar1 & 0x80000000) == 0; uVar1 = uVar1 * 2) {
    iVar2 = iVar2 + 1;
  }
  *param_2 = iVar2;
  return 0;
}



// ============================================================
// Function: xtra_decryptBlock (FUN_68111500)
// Address: 68111500
// Size: 65 bytes
// Params: int param_1, int * param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_decryptBlock(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 4);
  if ((*param_2 < iVar1) && (iVar2 = xtra_growCryptoBuffer(iVar1,param_2), iVar2 != 0)) {
    return iVar2;
  }
  display_checkAndFree(param_2[2],*(undefined4 *)(param_1 + 8),iVar1 * 4);
  param_2[1] = iVar1;
  return 0;
}



// ============================================================
// Function: xtra_verifySignature (FUN_68111550)
// Address: 68111550
// Size: 93 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_verifySignature(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 4);
  if (*(int *)(param_2 + 4) != iVar4) {
    iVar2 = 1;
    if (iVar4 <= *(int *)(param_2 + 4)) {
      iVar2 = -1;
    }
    return iVar2;
  }
  iVar4 = iVar4 + -1;
  if (-1 < iVar4) {
    piVar3 = (int *)(*(int *)(param_1 + 8) + iVar4 * 4);
    piVar1 = (int *)(*(int *)(param_2 + 8) + iVar4 * 4);
    do {
      if (*piVar1 != *piVar3) break;
      piVar3 = piVar3 + -1;
      piVar1 = piVar1 + -1;
      iVar4 = iVar4 + -1;
    } while (-1 < iVar4);
  }
  if (iVar4 < 0) {
    return 0;
  }
  return (-(uint)(*(uint *)(*(int *)(param_2 + 8) + iVar4 * 4) <
                 *(uint *)(*(int *)(param_1 + 8) + iVar4 * 4)) & 2) - 1;
}



// ============================================================
// Function: xtra_addBignum (FUN_681115b0)
// Address: 681115b0
// Size: 255 bytes
// Params: int param_1, int param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_addBignum(int param_1,int param_2,int *param_3)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  int local_4;
  
  iVar1 = *(int *)(param_1 + 4);
  local_4 = *(int *)(param_2 + 4);
  if (iVar1 < local_4) {
    puVar8 = *(uint **)(param_2 + 8);
    puVar7 = *(uint **)(param_1 + 8);
    iVar6 = iVar1;
  }
  else {
    puVar8 = *(uint **)(param_1 + 8);
    puVar7 = *(uint **)(param_2 + 8);
    iVar6 = local_4;
    local_4 = iVar1;
  }
  if ((local_4 <= *param_3) || (iVar1 = xtra_growCryptoBuffer(local_4 + 1,param_3), iVar1 == 0)) {
    uVar4 = 0;
    puVar3 = (uint *)param_3[2];
    iVar1 = iVar6;
    iVar9 = 0;
    if (0 < iVar6) {
      do {
        uVar2 = *puVar7 + *puVar8;
        uVar5 = uVar4 + uVar2;
        *puVar3 = uVar5;
        if ((uVar2 < *puVar7) || (uVar4 = 0, uVar5 < uVar2)) {
          uVar4 = 1;
        }
        puVar8 = puVar8 + 1;
        puVar7 = puVar7 + 1;
        puVar3 = puVar3 + 1;
        iVar1 = iVar1 + -1;
        iVar9 = iVar6;
      } while (iVar1 != 0);
    }
    if (iVar9 < local_4) {
      iVar1 = local_4 - iVar9;
      iVar9 = iVar9 + iVar1;
      do {
        uVar2 = *puVar8;
        *puVar3 = uVar2 + uVar4;
        uVar4 = (uint)(uVar2 + uVar4 < *puVar8);
        puVar3 = puVar3 + 1;
        puVar8 = puVar8 + 1;
        iVar1 = iVar1 + -1;
      } while (iVar1 != 0);
    }
    param_3[1] = iVar9;
    if (uVar4 == 0) {
      return 0;
    }
    iVar9 = iVar9 + 1;
    if ((iVar9 <= *param_3) || (iVar1 = xtra_getCryptoKeyData(iVar9,param_3), iVar1 == 0)) {
      param_3[1] = iVar9;
      iVar1 = 0;
      *(undefined4 *)(param_3[2] + local_4 * 4) = 1;
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_addBignumScalar (FUN_681116b0)
// Address: 681116b0
// Size: 107 bytes
// Params: uint param_1, int * param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_addBignumScalar(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  
  puVar4 = (uint *)param_2[2];
  uVar1 = *puVar4;
  *puVar4 = uVar1 + param_1;
  if (param_1 <= uVar1 + param_1) {
    return 0;
  }
  iVar2 = param_2[1];
  iVar5 = 1;
  if (1 < iVar2) {
    do {
      puVar4 = puVar4 + 1;
      uVar1 = *puVar4;
      *puVar4 = uVar1 + 1;
      if (uVar1 + 1 != 0) {
        return 0;
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar2);
  }
  if ((iVar2 + 1 <= *param_2) || (iVar3 = xtra_getCryptoKeyData(iVar2 + 2,param_2), iVar3 == 0)) {
    *(undefined4 *)(param_2[2] + iVar5 * 4) = 1;
    iVar3 = 0;
    param_2[1] = iVar2 + 1;
  }
  return iVar3;
}



// ============================================================
// Function: xtra_generateKey (FUN_68111720)
// Address: 68111720
// Size: 395 bytes
// Params: int param_1, int param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_generateKey(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint *puVar4;
  uint *puVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  bool bVar11;
  int local_c;
  
  iVar1 = *(int *)(param_2 + 4);
  piVar10 = *(int **)(param_2 + 8);
  puVar7 = *(uint **)(param_1 + 8);
  iVar9 = *(int *)(param_1 + 4);
  if (iVar9 < iVar1) {
    return 0x109;
  }
  if ((iVar9 <= *param_3) || (iVar2 = xtra_growCryptoBuffer(iVar9 + 1,param_3), iVar2 == 0)) {
    puVar5 = (uint *)param_3[2];
    uVar8 = *puVar7;
    local_c = 1;
    iVar2 = *piVar10;
    *puVar5 = uVar8 - iVar2;
    uVar8 = (uint)(*puVar7 < uVar8 - iVar2);
    if (1 < iVar1) {
      iVar2 = iVar1 + -1;
      puVar6 = puVar7;
      puVar4 = puVar5;
      do {
        puVar4 = puVar4 + 1;
        piVar10 = piVar10 + 1;
        puVar6 = puVar6 + 1;
        uVar3 = *puVar6 - *piVar10;
        *puVar4 = uVar3;
        if (uVar8 == 0) {
          bVar11 = *puVar6 < uVar3;
        }
        else {
          *puVar4 = uVar3 - 1;
          bVar11 = *puVar6 <= uVar3 - 1;
        }
        uVar8 = (uint)bVar11;
        iVar2 = iVar2 + -1;
        local_c = iVar1;
      } while (iVar2 != 0);
    }
    if (local_c == iVar9) {
      if (uVar8 != 0) {
        return 0x109;
      }
      param_3[1] = iVar9;
      return 0;
    }
    if (uVar8 == 0) {
      display_checkAndFree(puVar5 + local_c,puVar7 + local_c,(iVar9 - local_c) * 4);
      param_3[1] = iVar9;
      return 0;
    }
    if (local_c < iVar9) {
      puVar7 = puVar7 + local_c;
      puVar5 = puVar5 + local_c;
      local_c = iVar9 - local_c;
      do {
        uVar3 = *puVar7;
        *puVar5 = uVar3 - uVar8;
        uVar8 = (uint)(*puVar7 < uVar3 - uVar8);
        puVar7 = puVar7 + 1;
        puVar5 = puVar5 + 1;
        local_c = local_c + -1;
      } while (local_c != 0);
    }
    if (uVar8 != 0) {
      return 0x109;
    }
    iVar1 = *(int *)(param_3[2] + -4 + iVar9 * 4);
    while ((iVar1 == 0 && (1 < iVar9))) {
      iVar9 = iVar9 + -1;
      iVar1 = *(int *)(param_3[2] + -4 + iVar9 * 4);
    }
    param_3[1] = iVar9;
    iVar2 = 0;
  }
  return iVar2;
}



// ============================================================
// Function: xtra_deriveKey (FUN_681118b0)
// Address: 681118b0
// Size: 106 bytes
// Params: uint param_1, int param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_deriveKey(uint param_1,int param_2)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  
  puVar1 = *(uint **)(param_2 + 8);
  uVar2 = *puVar1;
  if (param_1 <= uVar2) {
    *puVar1 = uVar2 - param_1;
    return 0;
  }
  *puVar1 = uVar2 - param_1;
  iVar3 = 1;
  iVar4 = *(int *)(param_2 + 4) + -1;
  puVar5 = puVar1;
  if (0 < iVar4) {
    do {
      puVar5 = puVar5 + 1;
      uVar2 = *puVar5;
      *puVar5 = uVar2 - 1;
      if (uVar2 - 1 != 0xffffffff) break;
      iVar3 = iVar3 + 1;
    } while (iVar3 <= iVar4);
    if (iVar3 < iVar4) {
      return 0;
    }
  }
  if (iVar3 <= iVar4) {
    if (puVar1[iVar3] == 0) {
      *(int *)(param_2 + 4) = *(int *)(param_2 + 4) + -1;
    }
    return 0;
  }
  return 0x109;
}



// ============================================================
// Function: xtra_modReduce (FUN_68111920)
// Address: 68111920
// Size: 247 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_modReduce(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int local_c [3];
  
  iVar1 = param_2[1];
  if (iVar1 < *(int *)(param_1 + 4)) {
    return 0x108;
  }
  if (*(int *)(param_1 + 4) != iVar1) {
LAB_68111997:
    xtra_clearContext(local_c);
    iVar3 = xtra_growCryptoBuffer(iVar1 * 2 + 1,local_c);
    if (iVar3 == 0) {
      iVar3 = xtra_decryptBlock(param_1,local_c);
      if (iVar3 == 0) {
        iVar3 = xtra_shiftBignumLeft(iVar1,local_c);
        if (iVar3 == 0) {
          iVar3 = xtra_signData(local_c,param_2,param_3);
        }
      }
    }
    xtra_freeContext(local_c);
    return iVar3;
  }
  iVar3 = iVar1 + -1;
  if (-1 < iVar3) {
    piVar4 = (int *)(*(int *)(param_1 + 8) + iVar3 * 4);
    piVar2 = (int *)(param_2[2] + iVar3 * 4);
    do {
      if (*piVar2 != *piVar4) break;
      piVar4 = piVar4 + -1;
      piVar2 = piVar2 + -1;
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
    if (-1 < iVar3) {
      if (*(uint *)(param_2[2] + iVar3 * 4) < *(uint *)(*(int *)(param_1 + 8) + iVar3 * 4)) {
        return 0x108;
      }
      goto LAB_68111997;
    }
  }
  return 0x108;
}



// ============================================================
// Function: xtra_modExp (FUN_68111a20)
// Address: 68111a20
// Size: 111 bytes
// Params: int param_1, int param_2, int param_3, uint * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_modExp(int param_1,int param_2,int param_3,uint *param_4)

{
  int local_c;
  int iVar1;
  /* FIXUP(C2040: 'local_c': 'int): int local_c [2]; */
  undefined4 *local_4;
  
  xtra_clearContext(local_c);
  iVar1 = xtra_growCryptoBuffer(1,local_c);
  if (iVar1 == 0) {
    *local_4 = 1;
    ((int *)(size_t)local_c)[ /* FIXUP(C2109): cast to pointer for subscript */1] = 1;
    iVar1 = xtra_initCryptoSession(param_1,(int)local_c,param_2,param_3,param_4);
  }
  xtra_freeContext(local_c);
  return iVar1;
}



// ============================================================
// Function: xtra_computeModInverse (FUN_68111a90)
// Address: 68111a90
// Size: 94 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_computeModInverse(int param_1,int *param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = **(uint **)(param_1 + 8);
  if ((uVar1 & 1) == 0) {
    return 0x107;
  }
  uVar5 = 1;
  uVar2 = 2;
  uVar4 = 3;
  if (2 < ((byte)uVar1 & 3)) {
    uVar5 = 3;
  }
  iVar3 = 0x1e;
  do {
    uVar2 = uVar2 * 2;
    uVar4 = uVar4 | uVar2;
    if (uVar2 < (uVar5 * uVar1 & uVar4)) {
      uVar5 = uVar5 + uVar2;
    }
    iVar3 = iVar3 + -1;
  } while (iVar3 != 0);
  *param_2 = ~uVar5 + 1;
  return 0;
}



// ============================================================
// Function: xtra_initCryptoSession (FUN_68111af0)
// Address: 68111af0
// Size: 318 bytes
// Params: int param_1, int param_2, int param_3, int param_4, uint * param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initCryptoSession(int param_1,int param_2,int param_3,int param_4,uint *param_5)

{
  uint uVar1;
  int *piVar2;
  uint *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  
  uVar5 = *(uint *)(param_3 + 4);
  uVar1 = uVar5 * 2 + 3;
  if ((uVar1 <= *param_5) || (iVar7 = xtra_growCryptoBuffer(uVar1,(int *)param_5), iVar7 == 0)) {
    puVar4 = (undefined4 *)param_5[2];
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    param_5[1] = 1;
    piVar2 = (int *)param_5[2];
    uVar10 = 0;
    iVar7 = 0;
    uVar1 = *(uint *)(param_1 + 4);
    puVar3 = *(uint **)(param_1 + 8);
    puVar9 = param_5;
    do {
      uVar11 = uVar10;
      xtra_processCryptoBlock(*puVar3,param_2,iVar7,*(int *)(param_2 + 4),(int)puVar9,uVar10);
      iVar6 = param_3;
      uVar8 = uVar5;
      xtra_processCryptoBlock(*piVar2 * param_4,param_3,iVar7,uVar5,(int)puVar9,uVar11);
      uVar10 = uVar10 + 1;
      piVar2 = piVar2 + 1;
      puVar3 = puVar3 + 1;
    } while (uVar10 < uVar1);
    for (; uVar10 < uVar5; uVar10 = uVar10 + 1) {
      xtra_processCryptoBlock(*piVar2 * param_4,iVar6,iVar7,uVar8,(int)puVar9,uVar10);
      piVar2 = piVar2 + 1;
    }
    param_5[1] = uVar5 * 2 + 1;
    puVar3 = param_5;
    xtra_encryptBlock(uVar5,(int)param_5);
    xtra_trimBignumLeading(uVar5,(int)puVar3);
    iVar7 = xtra_verifySignature(param_3,(int)puVar3);
    if (iVar7 == 0) {
      param_5[1] = 1;
      iVar7 = 0;
      *(undefined4 *)param_5[2] = 0;
    }
    else if (iVar7 < 0) {
      iVar7 = xtra_computeHash(param_3,(int)puVar3);
    }
    else {
      iVar7 = 0;
    }
  }
  return iVar7;
}



// ============================================================
// Function: xtra_squareAndReduceMod (FUN_68111c30)
// Address: 68111c30
// Size: 412 bytes
// Params: int param_1, int param_2, int param_3, uint * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_squareAndReduceMod(int param_1,int param_2,int param_3,uint *param_4)

{
  uint uVar1;
  longlong lVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  uint uVar8;
  uint *puVar9;
  undefined4 *puVar10;
  uint uVar11;
  uint *puVar12;
  bool bVar13;
  uint uVar14;
  int iVar15;
  
  uVar14 = *(uint *)(param_2 + 4);
  iVar3 = uVar14 * 2;
  if ((iVar3 + 3U <= *param_4) || (iVar4 = xtra_growCryptoBuffer(iVar3 + 3U,(int *)param_4), iVar4 == 0)) {
    puVar10 = (undefined4 *)param_4[2];
    for (iVar4 = iVar3 + 3; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar10 = 0;
      puVar10 = puVar10 + 1;
    }
    param_4[1] = 1;
    uVar11 = 0;
    iVar4 = *(int *)(param_1 + 8);
    uVar8 = *(int *)(param_1 + 4) - 1;
    iVar15 = param_1;
    puVar9 = param_4;
    if (uVar8 != 0) {
      do {
        xtra_processCryptoBlock(*(uint *)(iVar4 + uVar11 * 4),iVar15,uVar11 + 1,uVar8 - uVar11,(int)puVar9,
                     uVar11 * 2 + 1);
        uVar11 = uVar11 + 1;
      } while (uVar11 < uVar8);
      puVar9 = param_4;
      xtra_trimBignumLeading(iVar3,(int)param_4);
      xtra_computeMAC(1,(int *)puVar9);
    }
    iVar4 = *(int *)(param_1 + 4);
    puVar9 = *(uint **)(param_1 + 8);
    puVar12 = (uint *)param_4[2];
    do {
      lVar2 = (ulonglong)*puVar9 * (ulonglong)*puVar9;
      uVar5 = (uint)((ulonglong)lVar2 >> 0x20);
      uVar11 = (uint)lVar2;
      uVar8 = *puVar12;
      *puVar12 = *puVar12 + uVar11;
      puVar6 = puVar12 + 1;
      uVar11 = (uint)CARRY4(uVar8,uVar11);
      uVar8 = *puVar6;
      uVar1 = *puVar6 + uVar5;
      *puVar6 = uVar1 + uVar11;
      if (CARRY4(uVar8,uVar5) || CARRY4(uVar1,uVar11)) {
        puVar6 = puVar12 + 2;
        bVar13 = true;
        while( true ) {
          uVar8 = (uint)bVar13;
          bVar13 = CARRY4(*puVar6,uVar8);
          *puVar6 = *puVar6 + uVar8;
          if (!bVar13) break;
          puVar6 = puVar6 + 1;
        }
      }
      puVar9 = puVar9 + 1;
      puVar12 = puVar12 + 2;
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
    piVar7 = (int *)param_4[2];
    iVar15 = 0;
    uVar11 = 0;
    iVar4 = param_2;
    uVar8 = uVar14;
    puVar9 = param_4;
    do {
      xtra_processCryptoBlock(*piVar7 * param_3,iVar4,iVar15,uVar8,(int)puVar9,uVar11);
      uVar11 = uVar11 + 1;
      piVar7 = piVar7 + 1;
    } while (uVar11 < uVar14);
    param_4[1] = iVar3 + 1;
    puVar9 = param_4;
    xtra_encryptBlock(uVar14,(int)param_4);
    xtra_trimBignumLeading(uVar14,(int)puVar9);
    iVar3 = xtra_verifySignature(param_2,(int)puVar9);
    if (iVar3 == 0) {
      param_4[1] = 1;
      iVar4 = 0;
      *(undefined4 *)param_4[2] = 0;
    }
    else if (iVar3 < 0) {
      iVar4 = xtra_computeHash(param_2,(int)puVar9);
    }
    else {
      iVar4 = 0;
    }
  }
  return iVar4;
}



// ============================================================
// Function: xtra_checkCryptoCallback (FUN_68111dd0)
// Address: 68111dd0
// Size: 27 bytes
// Params: undefined4 * param_1
// Return: bool
// Calling convention: __cdecl
// ============================================================

bool __cdecl xtra_checkCryptoCallback(undefined4 *param_1)

{
  int iVar1;
  
  if (param_1 == (undefined4 *)0x0) {
    return false;
  }
  iVar1 = (*(code *)*param_1)(param_1[1]);
  return (bool)('\x01' - (iVar1 == 0));
}



// ============================================================
// Function: xtra_verifyCert (FUN_68111df0)
// Address: 68111df0
// Size: 155 bytes
// Params: int param_1, int param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_verifyCert(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  void *pvVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_2 + 4);
  iVar6 = iVar1 + iVar2;
  if ((*param_3 < iVar6) && (iVar4 = xtra_growCryptoBuffer(iVar6,param_3), iVar4 != 0)) {
    return iVar4;
  }
  pvVar3 = (void *)param_3[2];
  display_fillMemory(pvVar3,0,iVar6 * 4);
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      iVar7 = iVar4 + 1;
      xtra_processCryptoBlock(*(uint *)(*(int *)(param_2 + 8) + -4 + iVar7 * 4),param_1,0,iVar1,(int)param_3,
                   iVar4);
      iVar4 = iVar7;
    } while (iVar7 < iVar2);
  }
  piVar5 = (int *)((int)pvVar3 + iVar6 * 4);
  do {
    if (iVar6 < 1) break;
    piVar5 = piVar5 + -1;
    iVar6 = iVar6 + -1;
  } while (*piVar5 == 0);
  param_3[1] = iVar6 + 1;
  return 0;
}



// ============================================================
// Function: xtra_verifyCertChainEx (FUN_68111e90)
// Address: 68111e90
// Size: 822 bytes
// Params: int * param_1, int * param_2, int * param_3, int * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_verifyCertChainEx(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_20;
  int local_1c;
  int local_18 [3];
  int local_c [2];
  uint *local_4;
  
  xtra_clearContext(local_c);
  xtra_clearContext(local_18);
  if ((0 < *param_3) || (iVar1 = xtra_growCryptoBuffer(2,param_3), iVar1 == 0)) {
    *(undefined4 *)param_3[2] = 0;
    param_3[1] = 1;
    iVar1 = xtra_verifySignature((int)param_1,(int)param_2);
    if (iVar1 < 0) {
      iVar1 = xtra_decryptBlock((int)param_1,param_4);
    }
    else {
      iVar1 = xtra_countLeadingZeros((int)param_2,(int *)&local_20);
      if (iVar1 == 0) {
        if (local_20 == 0x20) {
          iVar1 = 0x106;
        }
        else if (((int)local_20 < 1) ||
                ((iVar1 = xtra_computeMAC(local_20,param_2), iVar1 == 0 &&
                 (iVar1 = xtra_computeMAC(local_20,param_1), iVar1 == 0)))) {
          local_1c = param_2[1];
          iVar3 = param_1[1];
          iVar1 = xtra_decryptBlock((int)param_1,param_4);
          if (iVar1 == 0) {
            if (local_1c < iVar3) {
              iVar1 = xtra_encryptBlock(iVar3 - local_1c,(int)param_4);
            }
            else {
              *(undefined4 *)param_3[2] = 1;
              param_3[1] = 1;
              iVar1 = xtra_computeHash((int)param_2,(int)param_4);
            }
            if (((iVar1 == 0) && (iVar1 = xtra_growCryptoBuffer(iVar3,local_18), iVar1 == 0)) &&
               (iVar1 = xtra_growCryptoBuffer(2,local_c), iVar1 == 0)) {
              iVar3 = (iVar3 - local_1c) + -1;
              if (-1 < iVar3) {
                iVar3 = iVar3 * 4;
                do {
                  iVar1 = xtra_verifySignature((int)param_4,(int)param_2);
                  if ((((-1 < iVar1) &&
                       ((iVar1 = xtra_computeHash((int)param_2,(int)param_4), iVar1 != 0 ||
                        (iVar1 = xtra_addBignumScalar(1,param_3), iVar1 != 0)))) ||
                      (iVar1 = xtra_prependBignumWord(*(undefined4 *)(param_1[2] + iVar3),param_4), iVar1 != 0
                      )) || (iVar1 = xtra_shiftBignumLeft(1,param_3), iVar1 != 0)) goto LAB_681121a2;
                  if (local_1c < param_4[1]) {
                    iVar1 = xtra_divBignumEstimate((int)param_4,(int)param_2,local_c,local_18);
                    if (iVar1 != 0) goto LAB_681121a2;
                    do {
                      iVar2 = xtra_verifySignature((int)local_18,(int)param_4);
                      if (iVar2 < 1) break;
                      iVar1 = xtra_deriveKey(1,(int)local_c);
                      if (iVar1 != 0) goto LAB_6811213a;
                      iVar1 = xtra_computeHash((int)param_2,(int)local_18);
                    } while (iVar1 == 0);
                    if (((iVar1 != 0) || (iVar1 = xtra_addBignumScalar(*local_4,param_3), iVar1 != 0)) ||
                       (iVar1 = xtra_computeHash((int)local_18,(int)param_4), iVar1 != 0))
                    goto LAB_681121a2;
                  }
                  iVar3 = iVar3 + -4;
                } while (-1 < iVar3);
              }
LAB_6811213a:
              if (iVar1 == 0) {
                if (0 < (int)local_20) {
                  xtra_hashData(local_20,(int)param_4);
                  xtra_hashData(local_20,(int)param_1);
                  xtra_hashData(local_20,(int)param_2);
                }
                iVar3 = xtra_verifySignature((int)param_4,(int)param_2);
                if ((-1 < iVar3) && (iVar1 = xtra_computeHash((int)param_2,(int)param_4), iVar1 == 0)) {
                  iVar1 = xtra_addBignumScalar(1,param_3);
                }
              }
            }
          }
        }
      }
    }
  }
LAB_681121a2:
  xtra_freeContext(local_c);
  xtra_freeContext(local_18);
  return iVar1;
}



// ============================================================
// Function: xtra_signData (FUN_681121d0)
// Address: 681121d0
// Size: 621 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_signData(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_20;
  int local_1c;
  int local_18 [3];
  int local_c [3];
  
  xtra_clearContext(local_c);
  xtra_clearContext(local_18);
  iVar1 = xtra_verifySignature((int)param_1,(int)param_2);
  if (iVar1 < 0) {
    iVar1 = xtra_decryptBlock((int)param_1,param_3);
  }
  else {
    iVar1 = xtra_countLeadingZeros((int)param_2,(int *)&local_20);
    if (iVar1 == 0) {
      if (local_20 == 0x20) {
        iVar1 = 0x107;
      }
      else if (((int)local_20 < 1) ||
              ((iVar1 = xtra_computeMAC(local_20,param_2), iVar1 == 0 &&
               (iVar1 = xtra_computeMAC(local_20,param_1), iVar1 == 0)))) {
        local_1c = param_2[1];
        iVar3 = param_1[1];
        iVar1 = xtra_decryptBlock((int)param_1,param_3);
        if (iVar1 == 0) {
          if (local_1c < iVar3) {
            iVar1 = xtra_encryptBlock(iVar3 - local_1c,(int)param_3);
          }
          else {
            iVar1 = xtra_computeHash((int)param_2,(int)param_3);
          }
          if (((iVar1 == 0) && (iVar1 = xtra_growCryptoBuffer(iVar3,local_18), iVar1 == 0)) &&
             (iVar1 = xtra_growCryptoBuffer(2,local_c), iVar1 == 0)) {
            iVar3 = (iVar3 - local_1c) + -1;
            if (-1 < iVar3) {
              iVar3 = iVar3 * 4;
              do {
                iVar1 = xtra_verifySignature((int)param_3,(int)param_2);
                if (((-1 < iVar1) && (iVar1 = xtra_computeHash((int)param_2,(int)param_3), iVar1 != 0))
                   || (iVar1 = xtra_prependBignumWord(*(undefined4 *)(param_1[2] + iVar3),param_3), iVar1 != 0
                      )) goto LAB_68112419;
                if (local_1c < param_3[1]) {
                  iVar1 = xtra_divBignumEstimate((int)param_3,(int)param_2,local_c,local_18);
                  if (iVar1 != 0) goto LAB_68112419;
                  do {
                    iVar2 = xtra_verifySignature((int)local_18,(int)param_3);
                    if (iVar2 < 1) break;
                    iVar1 = xtra_computeHash((int)param_2,(int)local_18);
                  } while (iVar1 == 0);
                  if ((iVar1 != 0) || (iVar1 = xtra_computeHash((int)local_18,(int)param_3), iVar1 != 0)
                     ) goto LAB_68112419;
                }
                iVar3 = iVar3 + -4;
              } while (-1 < iVar3);
            }
            if (iVar1 == 0) {
              if (0 < (int)local_20) {
                xtra_hashData(local_20,(int)param_3);
                xtra_hashData(local_20,(int)param_1);
                xtra_hashData(local_20,(int)param_2);
              }
              iVar3 = xtra_verifySignature((int)param_3,(int)param_2);
              if (-1 < iVar3) {
                iVar1 = xtra_computeHash((int)param_2,(int)param_3);
              }
            }
          }
        }
      }
    }
  }
LAB_68112419:
  xtra_freeContext(local_c);
  xtra_freeContext(local_18);
  return iVar1;
}



// ============================================================
// Function: xtra_prependBignumWord (FUN_68112440)
// Address: 68112440
// Size: 98 bytes
// Params: undefined4 param_1, int * param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_prependBignumWord(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = param_2[1];
  if (((undefined4 *)param_2[2])[iVar1 + -1] == 0) {
    *(undefined4 *)param_2[2] = param_1;
    param_2[1] = 1;
    return 0;
  }
  if ((*param_2 < iVar1 + 1) && (iVar2 = xtra_getCryptoKeyData(iVar1 + 2,param_2), iVar2 != 0)) {
    return iVar2;
  }
  display_allocFormatBlock(param_2[2] + 4,param_2[2],iVar1 << 2);
  *(undefined4 *)param_2[2] = param_1;
  param_2[1] = param_2[1] + 1;
  return 0;
}



// ============================================================
// Function: xtra_divBignumEstimate (FUN_681124b0)
// Address: 681124b0
// Size: 365 bytes
// Params: int param_1, int param_2, int * param_3, int * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_divBignumEstimate(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  xtra_clearContext(&local_c);
  xtra_clearContext(&local_18);
  iVar2 = *(int *)(param_2 + 4);
  iVar3 = *(int *)(param_1 + 4);
  if (iVar2 < iVar3) {
    iVar1 = xtra_decryptBlock(param_1,&local_c);
    if (iVar1 == 0) {
      iVar1 = xtra_decryptBlock(param_2,&local_18);
      if (iVar1 == 0) {
        iVar3 = iVar3 + -3;
        if (iVar3 < 1) {
          iVar3 = 0;
        }
        iVar2 = iVar2 + -2;
        xtra_encryptBlock(iVar3,(int)&local_c);
        if (iVar2 < 1) {
          iVar2 = 0;
        }
        xtra_encryptBlock(iVar2,(int)&local_18);
        local_4 = local_8 * 4 + local_4;
        xtra_divDouble(*(uint *)(local_10 + -4 + local_14 * 4),*(uint *)(local_4 + -4),
                     *(uint *)(local_4 + -8),&local_20,&local_1c);
        *(int *)param_3[2] = local_20;
        param_3[1] = 1;
        xtra_verifyCert((int)param_3,param_2,param_4);
      }
    }
  }
  else {
    if (*param_4 < 1) {
      iVar1 = xtra_growCryptoBuffer(2,param_4);
      if (iVar1 != 0) goto LAB_681125f9;
    }
    *(undefined4 *)param_4[2] = 0;
    param_4[1] = 1;
    if (*param_3 < 1) {
      iVar1 = xtra_growCryptoBuffer(2,param_3);
      if (iVar1 != 0) goto LAB_681125f9;
    }
    iVar1 = 0;
    *(undefined4 *)param_3[2] = 0;
    param_3[1] = 1;
  }
LAB_681125f9:
  xtra_freeContext(&local_c);
  xtra_freeContext(&local_18);
  return iVar1;
}



// ============================================================
// Function: xtra_divDouble (FUN_68112620)
// Address: 68112620
// Size: 129 bytes
// Params: uint param_1, uint param_2, uint param_3, int * param_4, int * param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_divDouble(uint param_1,uint param_2,uint param_3,int *param_4,int *param_5)
{
  int local_10;
  uint local_c;
  uint local_8;
  uint local_4;
  
  if (param_2 < param_1) {
    xtra_divSingle(param_1,param_2,param_3,&local_8,(int *)&local_4);
    xtra_divSingle(param_1,local_4,param_3 << 0x10,&local_c,&local_10);
    *param_4 = local_8 * 0x10000 + local_c;
    *param_5 = local_10;
    return 0;
  }
  *param_4 = -1;
  *param_5 = 0;
  return 0;
}



// ============================================================
// Function: xtra_divSingle (FUN_681126b0)
// Address: 681126b0
// Size: 201 bytes
// Params: uint param_1, uint param_2, uint param_3, uint * param_4, int * param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_divSingle(uint param_1,uint param_2,uint param_3,uint *param_4,int *param_5)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_2 << 0x10 | param_3 >> 0x10;
  uVar2 = param_1 >> 0x10;
  uVar1 = param_2 / uVar2;
  uVar3 = (uVar1 & 0xffff) * uVar2;
  uVar5 = (param_1 & 0xffff) * (uVar1 >> 0x10) + uVar3;
  iVar4 = (uVar1 >> 0x10) * uVar2;
  if (uVar5 < uVar3) {
    iVar4 = iVar4 + 0x10000;
  }
  uVar3 = iVar4 + (uVar5 >> 0x10);
  uVar2 = (param_1 & 0xffff) * (uVar1 & 0xffff) + uVar5 * 0x10000;
  if (uVar2 < uVar5 * 0x10000) {
    uVar3 = uVar3 + 1;
  }
  do {
    if (uVar3 <= param_2 >> 0x10) {
      if (uVar3 != param_2 >> 0x10) {
        if (uVar6 < uVar2) {
          *param_5 = ~(uVar2 - uVar6) + 1;
          goto LAB_6811276b;
        }
LAB_68112756:
        *param_5 = uVar6 - uVar2;
LAB_6811276b:
        *param_4 = uVar1;
        return 0;
      }
      if (uVar2 <= uVar6) goto LAB_68112756;
    }
    uVar1 = uVar1 - 1;
    if (uVar2 < param_1) {
      uVar3 = uVar3 - 1;
      uVar2 = ~(param_1 - uVar2) + 1;
    }
    else {
      uVar2 = uVar2 - param_1;
    }
  } while( true );
}



// ============================================================
// Function: xtra_computeGCD (FUN_68112780)
// Address: 68112780
// Size: 406 bytes
// Params: int param_1, int param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_computeGCD(int param_1,int param_2,int *param_3)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  xtra_clearContext(&local_18);
  xtra_clearContext(&local_c);
  iVar2 = xtra_verifySignature(param_1,param_2);
  if (iVar2 < 0) {
    iVar2 = xtra_decryptBlock(param_2,&local_18);
    if (iVar2 != 0) goto LAB_681128f2;
    iVar2 = xtra_decryptBlock(param_1,param_3);
  }
  else {
    iVar2 = xtra_decryptBlock(param_1,&local_18);
    if (iVar2 != 0) goto LAB_681128f2;
    iVar2 = xtra_decryptBlock(param_2,param_3);
  }
  if (iVar2 != 0) goto LAB_681128f2;
  iVar4 = 3;
  iVar1 = *(int *)(param_3[2] + -4 + param_3[1] * 4);
  while (iVar1 != 0) {
    iVar2 = xtra_signData(&local_18,param_3,&local_c);
    if (iVar2 != 0) goto LAB_681128f2;
    iVar4 = 0;
    if (((*(int *)(local_4 + -4 + local_8 * 4) == 0) ||
        (iVar2 = xtra_signData(param_3,&local_c,&local_18), iVar2 != 0)) ||
       (iVar4 = 2, *(int *)(local_10 + -4 + local_14 * 4) == 0)) break;
    iVar2 = xtra_signData(&local_c,&local_18,param_3);
    if (iVar2 != 0) goto LAB_681128f2;
    iVar4 = 1;
    iVar1 = *(int *)(param_3[2] + -4 + param_3[1] * 4);
  }
  if (iVar2 != 0) goto LAB_681128f2;
  if (iVar4 == 1) {
LAB_681128e2:
    piVar3 = &local_18;
  }
  else {
    if (iVar4 != 2) {
      if ((iVar4 != 3) || (iVar2 = 0x10a, *(int *)(local_10 + -4 + local_14 * 4) == 0))
      goto LAB_681128f2;
      goto LAB_681128e2;
    }
    piVar3 = &local_c;
  }
  iVar2 = xtra_decryptBlock((int)piVar3,param_3);
LAB_681128f2:
  xtra_freeContext(&local_18);
  xtra_freeContext(&local_c);
  return iVar2;
}



// ============================================================
// Function: xtra_extendedGCD (FUN_68112920)
// Address: 68112920
// Size: 1221 bytes
// Params: int * param_1, int * param_2, int * param_3, int * param_4, int * param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_extendedGCD(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5)

{
  int iVar1;
  int *piVar2;
  int local_54;
  int local_50;
  int local_4c;
  int *local_48;
  int *local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24 [3];
  int local_18 [3];
  int local_c;
  undefined4 local_8;
  undefined4 *local_4;
  
  local_54 = 1;
  local_4c = 1;
  xtra_clearContext(&local_30);
  xtra_clearContext(&local_3c);
  xtra_clearContext(&local_c);
  xtra_clearContext(local_18);
  xtra_clearContext(local_24);
  iVar1 = xtra_verifySignature((int)param_1,(int)param_2);
  if (iVar1 < 0) {
    local_44 = param_2;
    local_48 = param_1;
    iVar1 = xtra_decryptBlock((int)param_2,&local_30);
    if ((iVar1 != 0) || (iVar1 = xtra_decryptBlock((int)param_1,&local_3c), iVar1 != 0))
    goto LAB_68112d5b;
    local_40 = 0;
  }
  else {
    local_44 = param_1;
    local_48 = param_2;
    iVar1 = xtra_decryptBlock((int)param_1,&local_30);
    if ((iVar1 != 0) || (iVar1 = xtra_decryptBlock((int)param_2,&local_3c), iVar1 != 0))
    goto LAB_68112d5b;
    local_40 = 1;
  }
  iVar1 = xtra_growCryptoBuffer(1,&local_c);
  if (iVar1 != 0) goto LAB_68112d5b;
  local_8 = 1;
  *local_4 = 1;
  if ((*param_3 < 1) && (iVar1 = xtra_growCryptoBuffer(1,param_3), iVar1 != 0)) goto LAB_68112d5b;
  param_3[1] = 1;
  *(undefined4 *)param_3[2] = 0;
  if (*(int *)(local_48[2] + -4 + local_48[1] * 4) == 0) {
    if (*(int *)(local_44[2] + -4 + local_44[1] * 4) == 0) {
      iVar1 = 0x10a;
    }
    else {
      iVar1 = xtra_decryptBlock((int)local_44,param_5);
      if ((iVar1 == 0) && ((0 < *param_4 || (iVar1 = xtra_growCryptoBuffer(1,param_4), iVar1 == 0)))) {
        param_4[1] = 1;
        *(undefined4 *)param_4[2] = 1;
      }
    }
    goto LAB_68112d5b;
  }
  iVar1 = xtra_verifyCertChainEx(&local_30,&local_3c,param_4,param_5);
  if (iVar1 != 0) goto LAB_68112d5b;
  if (*(int *)(param_5[2] + -4 + param_5[1] * 4) == 0) {
    param_4[1] = 1;
    *(undefined4 *)param_4[2] = 1;
    iVar1 = xtra_decryptBlock((int)local_48,param_5);
    goto LAB_68112d5b;
  }
  do {
    iVar1 = xtra_stepExtendedGCD(local_18,local_24,(int)param_4,&local_4c,&local_54,&local_c,param_3);
    if ((iVar1 != 0) || (iVar1 = xtra_verifyCertChainEx(&local_3c,param_5,param_4,&local_30), iVar1 != 0))
    goto LAB_68112d5b;
    local_50 = 1;
    if (*(int *)(local_28 + -4 + local_2c * 4) == 0) break;
    iVar1 = xtra_stepExtendedGCD(local_18,local_24,(int)param_4,&local_4c,&local_54,&local_c,param_3);
    if ((iVar1 != 0) || (iVar1 = xtra_verifyCertChainEx(param_5,&local_30,param_4,&local_3c), iVar1 != 0))
    goto LAB_68112d5b;
    local_50 = 2;
    if (*(int *)(local_34 + -4 + local_38 * 4) == 0) break;
    iVar1 = xtra_stepExtendedGCD(local_18,local_24,(int)param_4,&local_4c,&local_54,&local_c,param_3);
    if ((iVar1 != 0) || (iVar1 = xtra_verifyCertChainEx(&local_30,&local_3c,param_4,param_5), iVar1 != 0))
    goto LAB_68112d5b;
    local_50 = 0;
  } while (*(int *)(param_5[2] + -4 + param_5[1] * 4) != 0);
  if (iVar1 != 0) goto LAB_68112d5b;
  if (local_50 == 0) {
    piVar2 = &local_3c;
LAB_68112c84:
    xtra_decryptBlock((int)piVar2,param_5);
  }
  else if (local_50 == 2) {
    piVar2 = &local_30;
    goto LAB_68112c84;
  }
  iVar1 = xtra_verifyCert((int)param_3,(int)local_44,local_18);
  if (iVar1 == 0) {
    if (local_54 < 1) {
      iVar1 = xtra_addBignum((int)local_18,(int)param_5,local_24);
    }
    else {
      iVar1 = xtra_generateKey((int)local_18,(int)param_5,local_24);
    }
    if ((iVar1 == 0) && (iVar1 = xtra_verifyCertChainEx(local_24,local_48,param_4,local_18), iVar1 == 0)) {
      if (local_54 < 1) {
        iVar1 = xtra_generateKey((int)local_48,(int)param_3,local_24);
        if (iVar1 == 0) {
          iVar1 = xtra_decryptBlock((int)local_24,param_3);
        }
      }
      else {
        iVar1 = xtra_generateKey((int)local_44,(int)param_4,local_24);
        if (iVar1 == 0) {
          iVar1 = xtra_decryptBlock((int)local_24,param_4);
        }
      }
    }
  }
LAB_68112d5b:
  if ((((local_40 == 0) && (iVar1 == 0)) &&
      (iVar1 = xtra_decryptBlock((int)param_3,local_18), iVar1 == 0)) &&
     (iVar1 = xtra_decryptBlock((int)param_4,param_3), iVar1 == 0)) {
    iVar1 = xtra_decryptBlock((int)local_18,param_4);
  }
  xtra_freeContext(&local_30);
  xtra_freeContext(&local_3c);
  xtra_freeContext(&local_c);
  xtra_freeContext(local_18);
  xtra_freeContext(local_24);
  return iVar1;
}



// ============================================================
// Function: xtra_stepExtendedGCD (FUN_68112df0)
// Address: 68112df0
// Size: 163 bytes
// Params: int * param_1, int * param_2, int param_3, int * param_4, int * param_5, int * param_6, int * param_7
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_stepExtendedGCD(int *param_1,int *param_2,int param_3,int *param_4,int *param_5,int *param_6,
            int *param_7)

{
  int iVar1;
  int iVar2;
  int local_4;
  
  iVar2 = *param_4;
  *param_4 = *param_5;
  iVar1 = xtra_verifyCert(param_3,(int)param_7,param_2);
  if (iVar1 == 0) {
    if (*param_5 == iVar2) {
      iVar2 = xtra_absSubtract((int)param_6,(int)param_2,&local_4,param_1);
      if (iVar2 != 0) {
        return 0;
      }
      local_4 = *param_5 * local_4;
    }
    else {
      iVar2 = xtra_addBignum((int)param_6,(int)param_2,param_1);
      if (iVar2 != 0) {
        return iVar2;
      }
      local_4 = -*param_5;
    }
    *param_5 = local_4;
    iVar1 = xtra_decryptBlock((int)param_7,param_6);
    if (iVar1 == 0) {
      iVar1 = xtra_decryptBlock((int)param_1,param_7);
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_absSubtract (FUN_68112ea0)
// Address: 68112ea0
// Size: 76 bytes
// Params: int param_1, int param_2, undefined4 * param_3, int * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_absSubtract(int param_1,int param_2,undefined4 *param_3,int *param_4)
{
  int iVar1;
  
  iVar1 = xtra_verifySignature(param_1,param_2);
  if (-1 < iVar1) {
    *param_3 = 1;
    xtra_generateKey(param_1,param_2,param_4);
    return 0;
  }
  *param_3 = 0xffffffff;
  xtra_generateKey(param_2,param_1,param_4);
  return 0;
}



// ============================================================
// Function: xtra_modInverseFull (FUN_68112ef0)
// Address: 68112ef0
// Size: 293 bytes
// Params: int param_1, int param_2, int * param_3, int * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_modInverseFull(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  int local_c;
  int local_8;
  int *local_4;
  
  xtra_clearContext(&local_c);
  iVar1 = xtra_verifySignature(param_1,param_2);
  if (iVar1 < 0) {
    iVar1 = xtra_generateKey(param_2,param_1,&local_c);
    if (iVar1 == 0) {
      iVar1 = xtra_verifySignature((int)&local_c,(int)param_3);
      if (0 < iVar1) {
        iVar1 = xtra_decryptBlock((int)&local_c,param_4);
        if ((iVar1 != 0) || (iVar1 = xtra_signData(param_4,param_3,&local_c), iVar1 != 0))
        goto LAB_68112fff;
        if ((local_8 == 1) && (*local_4 == 0)) {
          param_4[1] = 1;
          *(undefined4 *)param_4[2] = 0;
          goto LAB_68112fff;
        }
      }
      iVar1 = xtra_generateKey((int)param_3,(int)&local_c,param_4);
    }
  }
  else {
    iVar1 = xtra_generateKey(param_1,param_2,param_4);
    if (((iVar1 == 0) && (iVar2 = xtra_verifySignature((int)param_4,(int)param_3), -1 < iVar2)) &&
       (iVar1 = xtra_signData(param_4,param_3,&local_c), iVar1 == 0)) {
      iVar1 = xtra_decryptBlock((int)&local_c,param_4);
    }
  }
LAB_68112fff:
  xtra_freeContext(&local_c);
  return iVar1;
}



// ============================================================
// Function: xtra_multiplyAndReduce (FUN_68113020)
// Address: 68113020
// Size: 91 bytes
// Params: int param_1, int param_2, int * param_3, int * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_multiplyAndReduce(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int local_c [3];
  
  xtra_clearContext(local_c);
  iVar1 = xtra_verifyCert(param_1,param_2,local_c);
  if (iVar1 == 0) {
    iVar1 = xtra_signData(local_c,param_3,param_4);
  }
  xtra_freeContext(local_c);
  return iVar1;
}



// ============================================================
// Function: xtra_signDataEx (FUN_68113080)
// Address: 68113080
// Size: 160 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_signDataEx(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  int local_18;
  int local_14;
  int *local_10;
  int local_c [3];
  
  xtra_clearContext(local_c);
  xtra_clearContext(&local_18);
  iVar1 = xtra_verifySignature((int)param_1,(int)param_2);
  if (iVar1 < 0) {
    iVar1 = xtra_extendedGCD(param_1,param_2,param_3,local_c,&local_18);
    if ((iVar1 == 0) && ((local_14 != 1 || (*local_10 != 1)))) {
      iVar1 = 0x10b;
    }
  }
  else {
    iVar1 = 0x108 - (uint)(*(int *)(param_2[2] + -4 + param_2[1] * 4) == 0);
  }
  xtra_freeContext(local_c);
  xtra_freeContext(&local_18);
  return iVar1;
}



// ============================================================
// Function: xtra_allocRSAContext (FUN_68113120)
// Address: 68113120
// Size: 54 bytes
// Params: undefined4 * param_1
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl xtra_allocRSAContext(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)display_allocBlock(0x3c);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  xtra_initKeyContext(param_1,&PTR_PTR_68190cf0);
  param_1[0xe] = &PTR_LAB_681909f0;
  return param_1;
}



// ============================================================
// Function: xtra_allocDSAContext (FUN_68113230)
// Address: 68113230
// Size: 54 bytes
// Params: undefined4 * param_1
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl xtra_allocDSAContext(undefined4 *param_1)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)display_allocBlock(0x3c);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  xtra_initKeyContext(param_1,&PTR_PTR_6818efe0);
  param_1[0xe] = &PTR_FUN_681909f8;
  return param_1;
}



// ============================================================
// Function: xtra_padPKCS1 (FUN_68113270)
// Address: 68113270
// Size: 171 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_padPKCS1(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  char local_9;
  uint local_8;
  int local_4;
  
  iVar1 = *(int *)(param_1 + 0x30);
  if (*(uint *)(param_1 + 0x2c) < iVar1 + 3U) {
    return 0x20d;
  }
  local_4 = (*(uint *)(param_1 + 0x2c) - iVar1) + -3;
  uVar3 = 2;
  display_allocFormatBlock(*(int *)(param_1 + 0x28) + local_4 + 3,*(int *)(param_1 + 0x28),iVar1);
  **(undefined1 **)(param_1 + 0x28) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x28) + 1) = 2;
  local_8 = local_4 + 2;
  do {
    if (local_8 <= uVar3) {
      *(undefined1 *)(*(int *)(param_1 + 0x28) + 2 + local_4) = 0;
      return 0;
    }
    do {
      uVar2 = xtra_generateRandom(param_2,&local_9,1,param_3);
      if (uVar2 != 0) {
        return uVar2;
      }
    } while (local_9 == '\0');
    *(char *)(*(int *)(param_1 + 0x28) + uVar3) = local_9;
    uVar3 = uVar3 + 1;
  } while( true );
}



// ============================================================
// Function: xtra_initKeyContext (FUN_68113380)
// Address: 68113380
// Size: 46 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initKeyContext(undefined4 *param_1,undefined4 param_2)
{
  xtra_allocSymKeyContext(param_1,param_2,0);
  display_fillMemory(param_1 + 10,0,8);
  param_1[1] = &PTR_FUN_68190a00;
  return 0;
}



// ============================================================
// Function: xtra_destroyKeyContext (FUN_681133b0)
// Address: 681133b0
// Size: 46 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_destroyKeyContext(int param_1)
{
  display_fillMemory(*(void **)(param_1 + 0x28),0,*(size_t *)(param_1 + 0x2c));
  display_freeIfNonNull(*(int *)(param_1 + 0x28));
  xtra_destroySymKeyBuffer(param_1);
  return 0;
}



// ============================================================
// Function: xtra_initEncryptKey (FUN_681133f0)
// Address: 681133f0
// Size: 46 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initEncryptKey(int param_1,int *param_2,int *param_3,undefined4 param_4)
{
  int iVar1;
  
  iVar1 = xtra_selectEncryptCipher(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    xtra_allocCipherBuffer(param_1,1);
  }
  return 0;
}



// ============================================================
// Function: xtra_initDecryptKey (FUN_68113420)
// Address: 68113420
// Size: 46 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initDecryptKey(int param_1,int *param_2,int *param_3,undefined4 param_4)
{
  int local_c;
  int iVar1;
  
  iVar1 = xtra_selectDecryptCipher(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    xtra_allocCipherBuffer(param_1,0);
  }
  return 0;
}



// ============================================================
// Function: xtra_appendCipherData (FUN_68113450)
// Address: 68113450
// Size: 67 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3, undefined4 param_4, undefined4 param_5, int param_6
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_appendCipherData(int param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5,int param_6)

{
  *param_3 = 0;
  if (*(uint *)(param_1 + 0x34) < (uint)(*(int *)(param_1 + 0x30) + param_6)) {
    return 0x20d;
  }
  display_checkAndFree(*(int *)(param_1 + 0x28) + *(int *)(param_1 + 0x30),param_5,param_6);
  *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + param_6;
  return 0;
}



// ============================================================
// Function: xtra_transformCipher (FUN_681134a0)
// Address: 681134a0
// Size: 111 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_transformCipher(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  undefined1 auStack_4 [4];
  
  iVar1 = (*(code *)**(undefined4 **)(param_1 + 0x38))(param_1,param_5,param_6);
  if (iVar1 == 0) {
    iVar1 = xtra_updateCipherBlock(param_1,param_2,param_3,param_4,*(undefined4 *)(param_1 + 0x28),
                         *(undefined4 *)(param_1 + 0x2c),0,param_6);
    if (iVar1 == 0) {
      iVar1 = xtra_finalizeCipherBlock(param_1,0,auStack_4,0,0,param_6);
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x30) = 0;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_finalizeCipher (FUN_68113510)
// Address: 68113510
// Size: 188 bytes
// Params: int param_1, undefined4 param_2, uint * param_3, uint param_4, undefined4 param_5, undefined4 param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_finalizeCipher(int param_1,undefined4 param_2,uint *param_3,uint param_4,undefined4 param_5,
            undefined4 param_6)

{
  int iVar1;
  undefined4 local_10;
  undefined1 local_c [4];
  undefined4 local_8;
  uint uStack_4;
  
  iVar1 = xtra_updateCipherBlock(param_1,*(undefined4 *)(param_1 + 0x28),&local_10,
                       *(undefined4 *)(param_1 + 0x2c),*(undefined4 *)(param_1 + 0x28),
                       *(undefined4 *)(param_1 + 0x30),0,param_6);
  if (iVar1 == 0) {
    iVar1 = xtra_finalizeCipherBlock(param_1,0,local_c,0,0,param_6);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x30) = 0;
      iVar1 = (**(code **)(*(int *)(param_1 + 0x38) + 4))(param_1,&local_8,local_10);
      if (iVar1 == 0) {
        if (*(int *)(param_1 + 0x2c) - 0xbU < uStack_4) {
          return 0x20c;
        }
        *param_3 = uStack_4;
        if (param_4 < uStack_4) {
          return 0x218;
        }
        display_checkAndFree(param_2,local_8,uStack_4);
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_allocCipherBuffer (FUN_681135d0)
// Address: 681135d0
// Size: 140 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_allocCipherBuffer(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  uint local_4;
  
  iVar1 = xtra_getBlockSize(param_1,&local_4);
  if (iVar1 == 0) {
    if (local_4 < 0xc) {
      return 0x217;
    }
    uVar2 = local_4;
    if (param_2 != 0) {
      uVar2 = local_4 - 0xb;
    }
    *(uint *)(param_1 + 0x34) = uVar2;
    *(undefined4 *)(param_1 + 0x30) = 0;
    display_fillMemory(*(void **)(param_1 + 0x28),0,*(size_t *)(param_1 + 0x2c));
    iVar1 = display_freeFormatBlock(*(int *)(param_1 + 0x28),local_4);
    *(int *)(param_1 + 0x28) = iVar1;
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x2c) = 0;
      return 0x206;
    }
    *(uint *)(param_1 + 0x2c) = local_4;
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_writeCipherAttribs (FUN_68113660)
// Address: 68113660
// Size: 86 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_writeCipherAttribs(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6)
{
  undefined4 local_14;
  undefined4 local_10;
  undefined1 local_c [4];
  undefined4 local_8;
  undefined4 *local_4;
  
  display_fillMemory(local_c,0,0xc);
  local_8 = param_4;
  local_14 = param_5;
  local_4 = &local_14;
  local_10 = param_6;
  xtra_writeBERAttributeSet(param_1,param_2,param_3,(uint *)&DAT_68190a20,(int)local_c);
  return 0;
}



// ============================================================
// Function: xtra_readCipherAttribs (FUN_681136c0)
// Address: 681136c0
// Size: 67 bytes
// Params: undefined4 param_1, undefined4 param_2, byte * param_3, uint param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readCipherAttribs(undefined4 param_1,undefined4 param_2,byte *param_3,uint param_4)
{
  undefined1 local_c [4];
  undefined4 local_8;
  undefined4 local_4;
  
  display_fillMemory(local_c,0,0xc);
  local_8 = param_1;
  local_4 = param_2;
  xtra_readCertField((uint *)0x0,(uint *)&DAT_68190a20,(int)local_c,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_encryptCBC (FUN_68113710)
// Address: 68113710
// Size: 48 bytes
// Params: int param_1, uint * param_2, uint * param_3, uint param_4, undefined4 * param_5, uint param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_encryptCBC(int param_1,uint *param_2,uint *param_3,uint param_4,undefined4 *param_5,uint param_6)
{
  xtra_encryptCFB(param_1,param_1 + 0x28,&LAB_68115221,param_2,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: xtra_finalizeCBC (FUN_68113740)
// Address: 68113740
// Size: 38 bytes
// Params: int param_1, uint * param_2, uint * param_3, uint param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_finalizeCBC(int param_1,uint *param_2,uint *param_3,uint param_4)
{
  xtra_finalizeCFB(param_1,param_1 + 0x28,&LAB_68115221,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_setInitVector (FUN_68113770)
// Address: 68113770
// Size: 57 bytes
// Params: int param_1, undefined4 * param_2, uint * param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_setInitVector(int param_1,undefined4 *param_2,uint *param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = xtra_expandKeySchedule((int *)(param_1 + 0x28),param_2,*param_3);
  if (iVar1 == 0) {
    xtra_setCipherIV(param_1,param_3[1],param_4);
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_computeMACCBC (FUN_681137b0)
// Address: 681137b0
// Size: 48 bytes
// Params: int param_1, uint * param_2, uint * param_3, uint param_4, undefined1 * param_5, int param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_computeMACCBC(int param_1,uint *param_2,uint *param_3,uint param_4,undefined1 *param_5,int param_6)
{
  xtra_computeMACCFB(param_1,param_1 + 0x28,&LAB_681150fc,param_2,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: xtra_resetCBCState (FUN_681137e0)
// Address: 681137e0
// Size: 14 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_resetCBCState(int param_1)
{
  xtra_resetCFBState(param_1);
  return 0;
}



// ============================================================
// Function: xtra_setKeyAndIV (FUN_68113890)
// Address: 68113890
// Size: 43 bytes
// Params: int param_1, uint * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_setKeyAndIV(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4)
{
  xtra_initDESEncrypt((uint *)(param_1 + 0x28),param_2);
  xtra_setCipherIV(param_1,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_encryptCBCEx (FUN_681138c0)
// Address: 681138c0
// Size: 48 bytes
// Params: int param_1, uint * param_2, uint * param_3, uint param_4, undefined4 * param_5, uint param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_encryptCBCEx(int param_1,uint *param_2,uint *param_3,uint param_4,undefined4 *param_5,uint param_6)
{
  xtra_encryptCFB(param_1,param_1 + 0x28,&LAB_68115740,param_2,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: xtra_finalizeCBCEx (FUN_681138f0)
// Address: 681138f0
// Size: 38 bytes
// Params: int param_1, uint * param_2, uint * param_3, uint param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_finalizeCBCEx(int param_1,uint *param_2,uint *param_3,uint param_4)
{
  xtra_finalizeCFB(param_1,param_1 + 0x28,&LAB_68115740,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_setKeyAndIVEx (FUN_68113920)
// Address: 68113920
// Size: 43 bytes
// Params: int param_1, uint * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_setKeyAndIVEx(int param_1,uint *param_2,undefined4 param_3,undefined4 param_4)
{
  xtra_computeDESSchedule((uint *)(param_1 + 0x28),param_2);
  xtra_setCipherIV(param_1,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_computeMACCBCEx (FUN_68113950)
// Address: 68113950
// Size: 48 bytes
// Params: int param_1, uint * param_2, uint * param_3, uint param_4, undefined1 * param_5, int param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_computeMACCBCEx(int param_1,uint *param_2,uint *param_3,uint param_4,undefined1 *param_5,int param_6)
{
  xtra_computeMACCFB(param_1,param_1 + 0x28,&LAB_68115740,param_2,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: xtra_importSymmetricKey (FUN_68113980)
// Address: 68113980
// Size: 63 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_importSymmetricKey(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = xtra_validateCertTag(param_1,0x681146c0);
  if (uVar1 == 0) {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 4))
                      (*(int *)(param_1 + 0x14),param_2,param_3,param_4);
    if (uVar1 == 0) {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}



// ============================================================
// Function: xtra_exportSymmetricKey (FUN_681139c0)
// Address: 681139c0
// Size: 53 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_exportSymmetricKey(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  uint uVar1;
  
  uVar1 = xtra_validateCert(param_1,0x681146c0);
  if (uVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 8))
              (*(int *)(param_1 + 0x14),param_2,param_3,param_4);
  }
  return 0;
}



// ============================================================
// Function: xtra_generateRandomKey (FUN_68113a00)
// Address: 68113a00
// Size: 58 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_generateRandomKey(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  uint uVar1;
  
  uVar1 = xtra_validateCert(param_1,0x681146c0);
  if (uVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 0xc))
              (*(int *)(param_1 + 0x14),param_2,param_3,param_4,param_5);
  }
  return 0;
}



// ============================================================
// Function: xtra_storeCipherOID (FUN_68113b30)
// Address: 68113b30
// Size: 103 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_storeCipherOID(undefined4 param_1,int *param_2,undefined4 *param_3)
{
  int local_8;
  int local_c;
  int local_18;
  int iVar1;
  undefined4 *local_4;
  
  iVar1 = xtra_readCertBlock(param_2,(int *)&local_4,0xc);
  if (iVar1 == 0) {
    iVar1 = xtra_copyCertData(param_2,local_4 + 1,param_3[1],8);
    if (iVar1 == 0) {
      *local_4 = *param_3;
      local_4[2] = param_3[2];
      xtra_writeCertBlock(param_2,param_1,local_4);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_storeCipherParams (FUN_68113cb0)
// Address: 68113cb0
// Size: 148 bytes
// Params: undefined4 param_1, int * param_2, uint * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_storeCipherParams(undefined4 param_1,int *param_2,uint *param_3)

{
  int iVar1;
  uint *local_4;
  
  if (((*param_3 < 0x11) && (param_3[1] < 0x100)) && (param_3[2] == 0x20)) {
    iVar1 = xtra_readCertBlock(param_2,(int *)&local_4,0x10);
    if (iVar1 == 0) {
      iVar1 = xtra_copyCertData(param_2,(int *)(local_4 + 3),param_3[3],8);
      if (iVar1 == 0) {
        *local_4 = *param_3;
        local_4[1] = param_3[1];
        local_4[2] = param_3[2];
        param_2[6] = param_2[6] | 2;
        iVar1 = xtra_writeCertBlock(param_2,param_1,local_4);
        return iVar1;
      }
    }
  }
  else {
    iVar1 = 0x21d;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_allocHashContext (FUN_68113d90)
// Address: 68113d90
// Size: 76 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl
xtra_allocHashContext(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)display_allocBlock(0x40);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  xtra_allocStreamContext(param_1,param_2,param_3,param_4,param_5);
  param_1[9] = 1;
  param_1[1] = &PTR_FUN_68190ac8;
  return param_1;
}



// ============================================================
// Function: xtra_initEncryptKeyEx (FUN_68113de0)
// Address: 68113de0
// Size: 36 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initEncryptKeyEx(int param_1,int *param_2,int *param_3,undefined4 param_4)
{
  *(undefined4 *)(param_1 + 0x3c) = 0;
  xtra_selectEncryptStream(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_finalizePadded (FUN_68113e50)
// Address: 68113e50
// Size: 117 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_finalizePadded(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  undefined1 local_c [4];
  undefined1 local_8 [8];
  
  iVar1 = 8 - *(int *)(param_1 + 0x3c);
  display_fillMemory(local_8,iVar1,iVar1);
  iVar1 = xtra_updateCipherBlock(param_1,param_2,param_3,param_4,local_8,iVar1,param_5,param_6);
  if (iVar1 == 0) {
    iVar1 = xtra_finalizeStreamBlock(param_1,0,local_c,0,0,0);
    if (iVar1 == 0) {
      *(undefined4 *)(param_1 + 0x3c) = 0;
      iVar1 = 0;
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_storePublicKey (FUN_68114020)
// Address: 68114020
// Size: 116 bytes
// Params: undefined4 param_1, int * param_2, uint * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_storePublicKey(undefined4 param_1,int *param_2,uint *param_3)

{
  int iVar1;
  uint *local_4;
  
  if (0x400 < *param_3) {
    return 0x201;
  }
  iVar1 = xtra_readCertBlock(param_2,(int *)&local_4,8);
  if (iVar1 == 0) {
    iVar1 = xtra_copyCertData(param_2,(int *)(local_4 + 1),param_3[1],8);
    if (iVar1 == 0) {
      *local_4 = *param_3;
      param_2[6] = param_2[6] | 2;
      iVar1 = xtra_writeCertBlock(param_2,param_1,local_4);
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_checkWeakDESKey (FUN_68114130)
// Address: 68114130
// Size: 51 bytes
// Params: byte * param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_checkWeakDESKey(byte *param_1)

{
  uint uVar1;
  undefined **ppuVar2;
  
  ppuVar2 = (undefined **)&DAT_68190b38;
  do {
    uVar1 = display_decodeFormat((byte *)ppuVar2,param_1,8);
    if (uVar1 == 0) {
      return 0x222;
    }
    ppuVar2 = ppuVar2 + 2;
  } while (ppuVar2 < &PTR_LAB_68190bb8);
  return 0;
}



// ============================================================
// Function: xtra_fixDESParity (FUN_68114170)
// Address: 68114170
// Size: 59 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_fixDESParity(int param_1)
{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  bool bVar5;
  
  uVar4 = 0;
  do {
    pbVar1 = (byte *)(param_1 + uVar4);
    bVar5 = false;
    bVar3 = 0x80;
    bVar2 = *pbVar1;
    do {
      if ((bVar3 & bVar2) != 0) {
        bVar5 = (bool)(bVar5 ^ 1);
      }
      bVar3 = bVar3 >> 1;
    } while (1 < bVar3);
    if (bVar5) {
      bVar2 = bVar2 & 0xfe;
    }
    else {
      bVar2 = bVar2 | 1;
    }
    uVar4 = uVar4 + 1;
    *pbVar1 = bVar2;
  } while (uVar4 < 8);
  return 0;
}



// ============================================================
// Function: xtra_validateDESParity (FUN_681141b0)
// Address: 681141b0
// Size: 94 bytes
// Params: byte * param_1
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_validateDESParity(byte *param_1)

{
  uint uVar1;
  byte local_8 [8];
  
  display_checkAndFree(local_8,param_1,8);
  xtra_fixDESParity((int)local_8);
  uVar1 = display_decodeFormat(local_8,param_1,8);
  display_fillMemory(local_8,0,8);
  return (uVar1 == 0) - 1 & 0x21e;
}



// ============================================================
// Function: xtra_generateRandom (FUN_681142a0)
// Address: 681142a0
// Size: 82 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_generateRandom(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == 0) {
    return 0x21b;
  }
  uVar1 = xtra_validateCert(param_1,0x681146c0);
  if (uVar1 != 0) {
    uVar2 = 0x21a;
    if (uVar1 != 0x202) {
      uVar2 = uVar1;
    }
    return uVar2;
  }
  uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 0xc))
                    (*(int *)(param_1 + 0x14),param_2,param_3,param_4);
  return uVar1;
}



// ============================================================
// Function: xtra_initCipherState (FUN_68114390)
// Address: 68114390
// Size: 36 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initCipherState(undefined4 *param_1,undefined4 param_2)
{
  param_1[5] = param_2;
  display_fillMemory(param_1 + 1,0,8);
  *param_1 = &PTR_FUN_68190cc8;
  return 0;
}



// ============================================================
// Function: xtra_parseCertAndBind (FUN_681143c0)
// Address: 681143c0
// Size: 76 bytes
// Params: uint * param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_parseCertAndBind(uint *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  uint local_1c;
  undefined4 local_18 [6];
  
  xtra_initCipherState(local_18,param_3);
  iVar1 = xtra_parseBERCert(&local_1c,param_1,param_2,(byte *)0x0,0,local_18);
  xtra_destroyCipherState((int)local_18);
  return iVar1;
}



// ============================================================
// Function: xtra_destroyCipherState (FUN_68114410)
// Address: 68114410
// Size: 41 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_destroyCipherState(int param_1)
{
  if (*(void **)(param_1 + 4) != (void *)0x0) {
    display_fillMemory(*(void **)(param_1 + 4),0,*(size_t *)(param_1 + 0xc));
    display_freeIfNonNull(*(int *)(param_1 + 4));
  }
  return 0;
}



// ============================================================
// Function: xtra_fillCryptoBuffer (FUN_68114440)
// Address: 68114440
// Size: 197 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_fillCryptoBuffer(int param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_4;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = display_allocBlock(0x7fff);
    *(int *)(param_1 + 4) = iVar1;
    if (iVar1 == 0) {
      return 0x206;
    }
    *param_2 = iVar1 + 0x7fff;
    *(undefined4 *)(param_1 + 0x10) = 0x7fff;
    *(undefined4 *)(param_1 + 0xc) = 0x7fff;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 != *param_2) {
    iVar2 = (iVar1 - *param_2) + *(int *)(param_1 + 0x10);
    *(int *)(param_1 + 0x10) = iVar2;
    display_allocFormatBlock(iVar1,*param_2,iVar2);
    if (*(int *)(param_1 + 8) == 0) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x14) + 4))
                        (*(int **)(param_1 + 0x14),*(int *)(param_1 + 4) + *(int *)(param_1 + 0x10),
                         &local_4,*(int *)(param_1 + 0xc) - *(int *)(param_1 + 0x10));
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar3 = *(int *)(param_1 + 0x10) + local_4;
      *(uint *)(param_1 + 0x10) = uVar3;
      if (uVar3 < 0x7fff) {
        *(undefined4 *)(param_1 + 8) = 1;
      }
    }
  }
  *param_2 = *(int *)(param_1 + 4);
  *param_3 = *(undefined4 *)(param_1 + 0x10);
  return 0;
}



// ============================================================
// Function: xtra_finalizeCryptoKey (FUN_68114510)
// Address: 68114510
// Size: 11 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_finalizeCryptoKey(undefined4 *param_1)
{
  *param_1 = &LAB_681146c0;
  return 0;
}



// ============================================================
// Function: xtra_importKey (FUN_68114520)
// Address: 68114520
// Size: 63 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_importKey(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = xtra_validateCertTag(param_1,0x681146c0);
  if (uVar1 == 0) {
    uVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 8))
                      (*(int *)(param_1 + 0x14),param_2,param_3,param_4);
    if (uVar1 == 0) {
      *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) | 1;
      uVar1 = 0;
    }
  }
  return uVar1;
}



// ============================================================
// Function: xtra_dispatchEncryptFull (FUN_681145a0)
// Address: 681145a0
// Size: 73 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_dispatchEncryptFull(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  uint uVar1;
  
  uVar1 = xtra_validateCert(param_1,0x681146c0);
  if (uVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 0x10))
              (*(int *)(param_1 + 0x14),param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return 0;
}



// ============================================================
// Function: xtra_dispatchDecryptFull (FUN_681145f0)
// Address: 681145f0
// Size: 73 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_dispatchDecryptFull(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)
{
  uint uVar1;
  
  uVar1 = xtra_validateCert(param_1,0x681146c0);
  if (uVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 0x14))
              (*(int *)(param_1 + 0x14),param_2,param_3,param_4,param_5,param_6,param_7,param_8);
  }
  return 0;
}



// ============================================================
// Function: xtra_dispatchEncryptShort (FUN_68114640)
// Address: 68114640
// Size: 63 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_dispatchEncryptShort(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)
{
  uint uVar1;
  
  uVar1 = xtra_validateCert(param_1,0x681146c0);
  if (uVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 0x18))
              (*(int *)(param_1 + 0x14),param_2,param_3,param_4,param_5,param_6);
  }
  return 0;
}



// ============================================================
// Function: xtra_dispatchDecryptShort (FUN_68114680)
// Address: 68114680
// Size: 63 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_dispatchDecryptShort(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)
{
  uint uVar1;
  
  uVar1 = xtra_validateCert(param_1,0x681146c0);
  if (uVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 0x1c))
              (*(int *)(param_1 + 0x14),param_2,param_3,param_4,param_5,param_6);
  }
  return 0;
}



// ============================================================
// Function: xtra_clearCryptoState (FUN_681146d0)
// Address: 681146d0
// Size: 25 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_clearCryptoState(void *param_1)
{
  *(undefined4 *)((int)param_1 + 8) = 0;
  display_fillMemory(param_1,0,0xc);
  return 0;
}



// ============================================================
// Function: xtra_destroyCryptoBuffer (FUN_681146f0)
// Address: 681146f0
// Size: 50 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_destroyCryptoBuffer(int *param_1)
{
  if ((code *)param_1[2] != (code *)0x0) {
    (*(code *)param_1[2])(*param_1);
  }
  display_fillMemory((void *)*param_1,0,param_1[1]);
  display_freeIfNonNull(*param_1);
  return 0;
}



// ============================================================
// Function: xtra_resizeCryptoBuffer (FUN_68114730)
// Address: 68114730
// Size: 92 bytes
// Params: int * param_1, uint param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_resizeCryptoBuffer(int *param_1,uint param_2)

{
  int iVar1;
  
  if ((code *)param_1[2] != (code *)0x0) {
    (*(code *)param_1[2])(*param_1);
  }
  if (param_2 == param_1[1]) {
    return 0;
  }
  display_fillMemory((void *)*param_1,0,param_1[1]);
  iVar1 = display_freeFormatBlock(*param_1,param_2);
  *param_1 = iVar1;
  if (iVar1 == 0) {
    param_1[1] = 0;
    return 0x206;
  }
  param_1[1] = param_2;
  return 0;
}



// ============================================================
// Function: xtra_selectCipher (FUN_68114790)
// Address: 68114790
// Size: 200 bytes
// Params: undefined4 * param_1, int param_2, int * param_3, undefined4 param_4, int * param_5, undefined4 param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_selectCipher(undefined4 *param_1,int param_2,int *param_3,undefined4 param_4,int *param_5,
            undefined4 param_6)

{
  int *piVar1;
  int iVar2;
  int local_4;
  
  iVar2 = 0x221;
  if (*param_5 == 0) {
    return 0x221;
  }
  do {
    piVar1 = (int *)*param_5;
    if ((param_1[1] == *piVar1) && (piVar1[1] == param_2)) {
      if (piVar1[2] == 0) {
        local_4 = 0;
      }
      else {
        iVar2 = xtra_readCertChain(param_3,&local_4,piVar1[2]);
        if (iVar2 != 0) {
          if (iVar2 == 0x206) {
            return 0x206;
          }
          if (iVar2 == 0x20b) {
            return 0x20b;
          }
          if (iVar2 == 0x207) {
            return 0x207;
          }
          goto LAB_68114831;
        }
      }
      iVar2 = (*(code *)param_1[3])(param_1,local_4,param_4,*param_5,param_6);
      if (iVar2 == 0) {
        *param_1 = *(undefined4 *)(*param_5 + 0xc);
        return 0;
      }
      if (iVar2 == 0x206) {
        return 0x206;
      }
      if (iVar2 == 0x20b) {
        return 0x20b;
      }
      if (iVar2 == 0x207) {
        return 0x207;
      }
    }
LAB_68114831:
    param_5 = param_5 + 1;
    if (*param_5 == 0) {
      return iVar2;
    }
  } while( true );
}



// ============================================================
// Function: xtra_getCryptoKeySize (FUN_68114860)
// Address: 68114860
// Size: 115 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_getCryptoKeySize(undefined4 param_1)

{
  switch(param_1) {
  case 1:
    return 0x207;
  case 2:
    return 0x208;
  case 3:
    return 0x209;
  case 4:
    return 0x20a;
  case 5:
    return 0x20c;
  case 6:
    return 0x20d;
  case 7:
    return 0x215;
  default:
    return 0x208;
  case 9:
    return 0x217;
  case 10:
    return 0x218;
  case 0xb:
    return 0x216;
  case 0xc:
    return 0x210;
  case 0xd:
    return 0x20f;
  case 0xf:
    return 0x201;
  case 0x80:
    return 0x206;
  }
}



// ============================================================
// Function: xtra_allocSymKeyContext (FUN_68114990)
// Address: 68114990
// Size: 89 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl xtra_allocSymKeyContext(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)display_allocBlock(0x28);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  xtra_finalizeCryptoKey(param_1);
  xtra_clearCryptoState(param_1 + 6);
  param_1[5] = xtra_initCipherFromKey;
  param_1[1] = &PTR_FUN_68190cd0;
  param_1[3] = param_2;
  param_1[4] = param_3;
  param_1[9] = 0;
  return param_1;
}



// ============================================================
// Function: xtra_destroySymKeyBuffer (FUN_681149f0)
// Address: 681149f0
// Size: 17 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_destroySymKeyBuffer(int param_1)
{
  xtra_destroyCryptoBuffer((int *)(param_1 + 0x18));
  return 0;
}



// ============================================================
// Function: xtra_getBlockSize (FUN_68114a10)
// Address: 68114a10
// Size: 39 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_getBlockSize(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0x14))(*(undefined4 *)(param_1 + 0x18),param_2);
  if (iVar1 != 0) {
    uVar2 = xtra_getCryptoKeySize(iVar1);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_selectEncryptCipher (FUN_68114a40)
// Address: 68114a40
// Size: 38 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_selectEncryptCipher(int param_1,int *param_2,int *param_3,undefined4 param_4)
{
  xtra_selectCipher((undefined4 *)(param_1 + 8),1,param_2,*(undefined4 *)(param_1 + 0x24),param_3,param_4
              );
  return 0;
}



// ============================================================
// Function: xtra_selectDecryptCipher (FUN_68114a70)
// Address: 68114a70
// Size: 38 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_selectDecryptCipher(int param_1,int *param_2,int *param_3,undefined4 param_4)
{
  xtra_selectCipher((undefined4 *)(param_1 + 8),0,param_2,*(undefined4 *)(param_1 + 0x24),param_3,param_4
              );
  return 0;
}



// ============================================================
// Function: xtra_updateCipherBlock (FUN_68114aa0)
// Address: 68114aa0
// Size: 64 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7, undefined4 param_8
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_updateCipherBlock(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7,undefined4 param_8)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 8))
                    (*(undefined4 *)(param_1 + 0x18),param_2,param_3,param_4,param_5,param_6,param_8
                    );
  if (iVar1 != 0) {
    uVar2 = xtra_getCryptoKeySize(iVar1);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_finalizeCipherBlock (FUN_68114ae0)
// Address: 68114ae0
// Size: 54 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_finalizeCipherBlock(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = (**(code **)(*(int *)(param_1 + 8) + 0xc))
                    (*(undefined4 *)(param_1 + 0x18),param_2,param_3,param_4,param_6);
  if (iVar1 != 0) {
    uVar2 = xtra_getCryptoKeySize(iVar1);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_initCipherFromKey (FUN_68114b20)
// Address: 68114b20
// Size: 175 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_initCipherFromKey(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)

{
  int *piVar1;
  code *pcVar2;
  int iVar3;
  uint local_4;
  
  iVar3 = (*(code *)**(undefined4 **)(param_4 + 0xc))(&local_4,param_2,*(undefined4 *)(param_1 + 8))
  ;
  if (iVar3 != 0) {
    iVar3 = xtra_getCryptoKeySize(iVar3);
    return iVar3;
  }
  piVar1 = (int *)(param_1 + 0x10);
  iVar3 = xtra_resizeCryptoBuffer(piVar1,local_4);
  if (iVar3 == 0) {
    pcVar2 = *(code **)(*(int *)(param_4 + 0xc) + 0x18);
    if (pcVar2 != (code *)0x0) {
      iVar3 = (*pcVar2)(piVar1);
      if (iVar3 != 0) {
        iVar3 = xtra_getCryptoKeySize(iVar3);
        return iVar3;
      }
    }
    iVar3 = (**(code **)(*(int *)(param_4 + 0xc) + 4))
                      (*piVar1,param_2,*(undefined4 *)(param_1 + 8),param_3,param_5);
    if (iVar3 != 0) {
      iVar3 = xtra_getCryptoKeySize(iVar3);
      return iVar3;
    }
    iVar3 = 0;
  }
  return iVar3;
}



// ============================================================
// Function: xtra_processCryptoBlock (FUN_68114bd0)
// Address: 68114bd0
// Size: 145 bytes
// Params: uint param_1, int param_2, int param_3, int param_4, int param_5, int param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_processCryptoBlock(uint param_1,int param_2,int param_3,int param_4,int param_5,int param_6)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  
  puVar5 = (uint *)(*(int *)(param_5 + 8) + param_6 * 4);
  puVar6 = (uint *)(*(int *)(param_2 + 8) + param_3 * 4);
  uVar4 = 0;
  if (param_4 != 0) {
    do {
      uVar1 = (uint)((ulonglong)*puVar6 * (ulonglong)param_1);
      uVar2 = uVar1 + *puVar5;
      uVar3 = uVar2 + uVar4;
      uVar4 = (int)((ulonglong)*puVar6 * (ulonglong)param_1 >> 0x20) + (uint)CARRY4(uVar1,*puVar5) +
              (uint)CARRY4(uVar2,uVar4);
      *puVar5 = uVar3;
      puVar6 = puVar6 + 1;
      puVar5 = puVar5 + 1;
      param_4 = param_4 + -1;
    } while (param_4 != 0);
    uVar1 = *puVar5;
    *puVar5 = uVar1 + uVar4;
    if (CARRY4(uVar1,uVar4)) {
      do {
        puVar5 = puVar5 + 1;
        uVar4 = *puVar5;
        *puVar5 = uVar4 + 1;
      } while (0xfffffffe < uVar4);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_resetCipherIV (FUN_68114c70)
// Address: 68114c70
// Size: 29 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_resetCipherIV(int param_1)
{
  display_checkAndFree(param_1 + 8,param_1,8);
  *(undefined4 *)(param_1 + 0x20) = 0;
  return 0;
}



// ============================================================
// Function: xtra_setCipherIV (FUN_68114c90)
// Address: 68114c90
// Size: 54 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_setCipherIV(int param_1,undefined4 param_2,undefined4 param_3)
{
  display_checkAndFree(param_1,param_2,8);
  display_checkAndFree(param_1 + 8,param_2,8);
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = param_3;
  return 0;
}



// ============================================================
// Function: xtra_copyCipherIV (FUN_68114cd0)
// Address: 68114cd0
// Size: 21 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_copyCipherIV(undefined4 param_1,undefined4 param_2)
{
  display_checkAndFree(param_1,param_2,8);
  return 0;
}



// ============================================================
// Function: xtra_expandKeySchedule (FUN_68114cf0)
// Address: 68114cf0
// Size: 328 bytes
// Params: int * param_1, undefined4 * param_2, uint param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_expandKeySchedule(int *param_1,undefined4 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_80;
  
  uVar2 = param_2[1];
  if ((uVar2 == 0) || (0x80 < uVar2)) {
    return 9;
  }
  if ((param_3 != 0) && (param_3 < 0x401)) {
    display_checkAndFree(&local_80,*param_2,uVar2);
    iVar1 = param_2[1];
    for (iVar3 = iVar1; iVar3 < 0x80; iVar3 = iVar3 + 1) {
      *(undefined *)((int)&local_80 + iVar3) =
           (&DAT_68190cf8)
           [(uint)*(byte *)((int)&local_80 + (iVar3 - iVar1)) +
            (uint)(byte)(&stack0xffffff7f)[iVar3] & 0xff];
    }
    uVar2 = param_3 + 7 >> 3;
    (&stack0x00000000)[-uVar2] =
         (&DAT_68190cf8)
         [(byte)(0xff >> (7 - ((char)param_3 - 1U & 7) & 0x1f)) & (&stack0x00000000)[-uVar2]];
    for (iVar1 = 0x7f - uVar2; -1 < iVar1; iVar1 = iVar1 + -1) {
      *(undefined *)((int)&local_80 + iVar1) =
           (&DAT_68190cf8)
           [*(byte *)((int)&local_80 + iVar1 + uVar2) ^ *(byte *)((int)&local_80 + iVar1 + 1)];
    }
    iVar3 = 0x40;
    iVar1 = 0;
    do {
      iVar3 = iVar3 + -1;
      *param_1 = (uint)*(byte *)((int)&local_80 + iVar1 + 1) * 0x100 +
                 (*(uint *)((int)&local_80 + iVar1) & 0xff);
      param_1 = param_1 + 1;
      iVar1 = iVar1 + 2;
    } while (iVar3 != 0);
    display_fillMemory(&local_80,0,0x80);
    return 0;
  }
  return 9;
}



// ============================================================
// Function: xtra_encryptCFB (FUN_68114e40)
// Address: 68114e40
// Size: 498 bytes
// Params: int param_1, undefined4 param_2, undefined * param_3, uint * param_4, uint * param_5, uint param_6, undefined4 * param_7, uint param_8
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_encryptCFB(int param_1,undefined4 param_2,undefined *param_3,uint *param_4,uint *param_5,
            uint param_6,undefined4 *param_7,uint param_8)

{
  uint uVar1;
  undefined1 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  undefined4 *puVar7;
  int iVar8;
  uint local_10;
  uint uStack_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar8 = *(int *)(param_1 + 0x24);
  if (iVar8 == 0) {
    uVar5 = 0;
  }
  else if (iVar8 == 1) {
    uVar5 = 1;
  }
  else {
    if (iVar8 != 2) {
      *param_5 = 0;
      return 0xb;
    }
    uVar5 = 9;
  }
  uVar1 = uVar5 + 7;
  uVar3 = *(int *)(param_1 + 0x20) + param_8;
  if (uVar3 < uVar5) {
    *param_5 = 0;
  }
  else {
    *param_5 = uVar3 - uVar5 & 0xfffffff8;
  }
  if (*param_5 <= param_6) {
    if (param_8 != 0) {
      iVar8 = *(int *)(param_1 + 0x20);
      while ((iVar8 != 0 && (uVar5 = *(uint *)(param_1 + 0x20), uVar1 < param_8 + uVar5))) {
        if (uVar5 < 8) {
          iVar4 = -uVar5 + 8;
          puVar6 = (undefined1 *)(uVar5 + 0x10 + param_1);
          puVar7 = param_7;
          for (iVar8 = -uVar5 + 7; -1 < iVar8; iVar8 = iVar8 + -1) {
            uVar2 = *(undefined1 *)puVar7;
            puVar7 = (undefined4 *)((int)puVar7 + 1);
            *puVar6 = uVar2;
            puVar6 = puVar6 + 1;
          }
          param_7 = (undefined4 *)((int)param_7 + iVar4);
          *(undefined4 *)(param_1 + 0x20) = 8;
          param_8 = param_8 - iVar4;
        }
        puVar7 = (undefined4 *)(param_1 + 0x10);
        (*(code *)param_3)(param_2,&local_10,puVar7);
        local_10 = local_10 ^ *(uint *)(param_1 + 8);
        uStack_c = uStack_c ^ *(uint *)(param_1 + 0xc);
        *param_4 = local_10;
        param_4[1] = uStack_c;
        *(undefined4 *)(param_1 + 8) = *puVar7;
        *(undefined4 *)(param_1 + 0xc) = *(undefined4 *)(param_1 + 0x14);
        *puVar7 = *(undefined4 *)(param_1 + 0x18);
        iVar8 = *(int *)(param_1 + 0x20) + -8;
        *(int *)(param_1 + 0x20) = iVar8;
        *(int *)(param_1 + 0x14) = iVar8;
        param_4 = param_4 + 2;
      }
      if (uVar1 < param_8) {
        uVar5 = (param_8 - uVar1) + 7 >> 3;
        param_8 = param_8 + uVar5 * -8;
        puVar7 = param_7;
        do {
          local_8 = *puVar7;
          param_7 = puVar7 + 2;
          local_4 = puVar7[1];
          (*(code *)param_3)(param_2,&local_10,&local_8);
          local_10 = local_10 ^ *(uint *)(param_1 + 8);
          uStack_c = uStack_c ^ *(uint *)(param_1 + 0xc);
          uVar5 = uVar5 - 1;
          *param_4 = local_10;
          param_4[1] = uStack_c;
          *(undefined4 *)(param_1 + 8) = local_8;
          *(undefined4 *)(param_1 + 0xc) = local_4;
          param_4 = param_4 + 2;
          puVar7 = param_7;
        } while (uVar5 != 0);
      }
      puVar6 = (undefined1 *)(*(int *)(param_1 + 0x20) + 0x10 + param_1);
      uVar5 = param_8;
      while (uVar5 = uVar5 - 1, -1 < (int)uVar5) {
        uVar2 = *(undefined1 *)param_7;
        param_7 = (undefined4 *)((int)param_7 + 1);
        *puVar6 = uVar2;
        puVar6 = puVar6 + 1;
      }
      *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + param_8;
      return 0;
    }
    return 0;
  }
  *param_5 = 0;
  return 10;
}



// ============================================================
// Function: xtra_finalizeCFB (FUN_68115040)
// Address: 68115040
// Size: 187 bytes
// Params: int param_1, undefined4 param_2, undefined * param_3, uint * param_4, uint * param_5, uint param_6
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_finalizeCFB(int param_1,undefined4 param_2,undefined *param_3,uint *param_4,uint *param_5,
            uint param_6)

{
  uint uVar1;
  undefined4 uVar2;
  uint local_8;
  uint uStack_4;
  
  uVar2 = 0;
  *param_5 = 0;
  uVar1 = *(uint *)(param_1 + 0x20);
  if (uVar1 != 0) {
    if (param_6 < uVar1) {
      uVar2 = 10;
    }
    else if ((uVar1 == 8) || (uVar1 == 0x10)) {
      *param_5 = uVar1;
      (*(code *)param_3)(param_2,&local_8,param_1 + 0x10);
      local_8 = local_8 ^ *(uint *)(param_1 + 8);
      uStack_4 = uStack_4 ^ *(uint *)(param_1 + 0xc);
      *param_4 = local_8;
      param_4[1] = uStack_4;
      if (*(int *)(param_1 + 0x20) == 0x10) {
        (*(code *)param_3)(param_2,&local_8,param_1 + 0x18);
        local_8 = local_8 ^ *(uint *)(param_1 + 0x10);
        uStack_4 = uStack_4 ^ *(uint *)(param_1 + 0x14);
        param_4[2] = local_8;
        param_4[3] = uStack_4;
      }
    }
    else {
      uVar2 = 6;
    }
  }
  xtra_resetCipherIV(param_1);
  return uVar2;
}



// ============================================================
// Function: xtra_computeMACCFB (FUN_68115350)
// Address: 68115350
// Size: 361 bytes
// Params: int param_1, undefined4 param_2, undefined * param_3, uint * param_4, uint * param_5, uint param_6, undefined1 * param_7, int param_8
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_computeMACCFB(int param_1,undefined4 param_2,undefined *param_3,uint *param_4,uint *param_5,
            uint param_6,undefined1 *param_7,int param_8)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 *puVar7;
  undefined1 *puVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  int iVar12;
  uint local_c;
  uint local_8;
  uint uStack_4;
  
  uVar5 = *(int *)(param_1 + 0x20) + param_8;
  *param_5 = uVar5 & 0xfffffff8;
  if (param_6 < (uVar5 & 0xfffffff8)) {
    return 10;
  }
  iVar2 = *(int *)(param_1 + 0x20);
  if (7 < uVar5) {
    puVar7 = (undefined1 *)(iVar2 + 0x10 + param_1);
    iVar11 = -iVar2 + 8;
    iVar2 = -iVar2 + 7;
    puVar8 = param_7;
    iVar12 = iVar11;
    while (iVar3 = iVar2, 0 < iVar12) {
      uVar1 = *puVar8;
      puVar8 = puVar8 + 1;
      *puVar7 = uVar1;
      puVar7 = puVar7 + 1;
      iVar2 = iVar3 + -1;
      iVar12 = iVar3;
    }
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) ^ *(uint *)(param_1 + 8);
    *(uint *)(param_1 + 0x14) = *(uint *)(param_1 + 0x14) ^ *(uint *)(param_1 + 0xc);
    (*(code *)param_3)(param_2,&local_8,param_1 + 0x10);
    *(uint *)(param_1 + 8) = local_8;
    *(uint *)(param_1 + 0xc) = uStack_4;
    *param_4 = local_8;
    puVar9 = (uint *)(param_7 + iVar11);
    uVar5 = param_8 - iVar11;
    param_4[1] = uStack_4;
    *(undefined4 *)(param_1 + 0x20) = 0;
    if (7 < uVar5) {
      local_c = uVar5 >> 3;
      uVar5 = uVar5 + local_c * -8;
      puVar10 = puVar9;
      do {
        puVar9 = puVar10 + 2;
        local_8 = *puVar10 ^ *(uint *)(param_1 + 8);
        uStack_4 = puVar10[1] ^ *(uint *)(param_1 + 0xc);
        (*(code *)param_3)(param_2,&local_8,&local_8);
        *(uint *)(param_1 + 8) = local_8;
        *(uint *)(param_1 + 0xc) = uStack_4;
        local_c = local_c - 1;
        param_4[2] = local_8;
        param_4[3] = uStack_4;
        puVar10 = puVar9;
        param_4 = param_4 + 2;
      } while (local_c != 0);
    }
    puVar7 = (undefined1 *)(param_1 + 0x10);
    for (uVar6 = uVar5; 0 < (int)uVar6; uVar6 = uVar6 - 1) {
      uVar4 = *puVar9;
      puVar9 = (uint *)((int)puVar9 + 1);
      *puVar7 = (char)uVar4;
      puVar7 = puVar7 + 1;
    }
    *(uint *)(param_1 + 0x20) = uVar5;
    return 0;
  }
  puVar7 = (undefined1 *)(iVar2 + 0x10 + param_1);
  for (; 0 < param_8; param_8 = param_8 + -1) {
    uVar1 = *param_7;
    param_7 = param_7 + 1;
    *puVar7 = uVar1;
    puVar7 = puVar7 + 1;
  }
  *(uint *)(param_1 + 0x20) = uVar5;
  return 0;
}



// ============================================================
// Function: xtra_resetCFBState (FUN_681154c0)
// Address: 681154c0
// Size: 30 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_resetCFBState(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 0x20) != 0) {
    uVar1 = 6;
  }
  xtra_resetCipherIV(param_1);
  return uVar1;
}



// ============================================================
// Function: xtra_initDESEncrypt (FUN_681154e0)
// Address: 681154e0
// Size: 58 bytes
// Params: uint * param_1, uint * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initDESEncrypt(uint *param_1,uint *param_2)
{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  
  xtra_computeDESSchedule(param_1,param_2);
  puVar2 = param_1 + 0x1e;
  if (param_1 < param_1 + 0x1e) {
    do {
      uVar1 = *param_1;
      *param_1 = *puVar2;
      puVar4 = param_1 + 2;
      *puVar2 = uVar1;
      puVar3 = puVar2 + -2;
      uVar1 = param_1[1];
      param_1[1] = puVar2[1];
      puVar2[1] = uVar1;
      puVar2 = puVar3;
      param_1 = puVar4;
    } while (puVar4 < puVar3);
  }
  return 0;
}



// ============================================================
// Function: xtra_computeDESSchedule (FUN_68115520)
// Address: 68115520
// Size: 536 bytes
// Params: uint * param_1, uint * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_computeDESSchedule(uint *param_1,uint *param_2)
{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int local_4;
  
  uVar2 = (param_2[1] >> 4 ^ *param_2) & 0xf0f0f0f;
  uVar4 = *param_2 ^ uVar2;
  uVar5 = param_2[1] ^ uVar2 << 4;
  uVar2 = (uVar4 << 0x12 ^ uVar4) & 0xcccc0000;
  uVar4 = uVar4 ^ uVar2 >> 0x12 ^ uVar2;
  uVar2 = (uVar5 << 0x12 ^ uVar5) & 0xcccc0000;
  uVar5 = uVar5 ^ uVar2 >> 0x12 ^ uVar2;
  uVar2 = (uVar5 >> 1 ^ uVar4) & 0x55555555;
  uVar4 = uVar4 ^ uVar2;
  uVar5 = uVar5 ^ uVar2 * 2;
  uVar2 = (uVar4 >> 8 ^ uVar5) & 0xff00ff;
  uVar5 = uVar5 ^ uVar2;
  uVar4 = uVar4 ^ uVar2 << 8;
  uVar2 = (uVar5 >> 1 ^ uVar4) & 0x55555555;
  uVar4 = uVar4 ^ uVar2;
  uVar5 = uVar5 ^ uVar2 * 2;
  local_4 = 0;
  uVar2 = (uVar5 & 0xff0000) >> 0x10 | (uVar4 & 0xf000000f) >> 4 | (uVar5 & 0xff) << 0x10 |
          uVar5 & 0xff00;
  do {
    uVar4 = uVar4 & 0xfffffff;
    if ((&DAT_68191df8)[local_4] == '\0') {
      uVar4 = uVar4 >> 1 | uVar4 << 0x1b;
      iVar1 = 1;
      uVar5 = uVar2 << 0x1b;
    }
    else {
      uVar4 = uVar4 >> 2 | uVar4 << 0x1a;
      iVar1 = 2;
      uVar5 = uVar2 << 0x1a;
    }
    uVar3 = uVar2 >> iVar1;
    uVar2 = (uVar3 | uVar5) & 0xfffffff;
    uVar6 = *(uint *)(&DAT_681918f8 +
                     ((uVar4 & 0x100000) >> 0x14 | (uVar4 & 0xc00000) >> 0x15 |
                     (uVar4 & 0xe000000) >> 0x16) * 4) |
            *(uint *)(&DAT_681917f8 + (((uVar4 & 0xc0000) >> 1 | uVar4 & 0x1e000) >> 0xd) * 4) |
            *(uint *)(&DAT_681916f8 + (((uVar4 & 0x1e00) >> 1 | uVar4 & 0xc0) >> 6) * 4) |
            *(uint *)(&DAT_681915f8 + (uVar4 & 0x3f) * 4);
    uVar5 = *(uint *)(&DAT_68191cf8 +
                     (((uVar3 | uVar5) & 0xc000000) >> 0x16 | (uVar3 & 0x1e00000) >> 0x15) * 4) |
            *(uint *)(&DAT_68191af8 + (((uVar3 & 0x3c00) >> 1 | uVar3 & 0x180) >> 7) * 4) |
            *(uint *)(&DAT_68191bf8 + ((uVar3 & 0x1f8000) >> 0xf) * 4) |
            *(uint *)(&DAT_681919f8 + (uVar3 & 0x3f) * 4);
    local_4 = local_4 + 1;
    *param_1 = uVar5 << 0x10 | uVar6 & 0xffff;
    param_1[1] = (uVar6 >> 0x10 | uVar5 & 0xffff0000) << 4 | uVar5 >> 0x1c;
    param_1 = param_1 + 2;
  } while (local_4 < 0x10);
  return 0;
}



// ============================================================
// Function: xtra_parseCipherFieldSet (FUN_68115960)
// Address: 68115960
// Size: 197 bytes
// Params: uint * param_1, undefined4 * param_2, undefined4 * param_3, uint * param_4, undefined4 * param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_parseCipherFieldSet(uint *param_1,undefined4 *param_2,undefined4 *param_3,uint *param_4,undefined4 *param_5
            )

{
  int iVar1;
  ushort local_22;
  int local_20;
  uint local_1c;
  undefined4 local_18;
  int local_14;
  undefined1 local_10 [4];
  int *local_c;
  undefined4 *local_8;
  ushort *local_4;
  
  local_20 = 0;
  display_fillMemory(local_10,0,0x10);
  local_c = &local_20;
  local_8 = &local_18;
  local_4 = &local_22;
  iVar1 = xtra_readCertField((uint *)0x0,(uint *)&DAT_68191e08,(int)local_10,(byte *)*param_5,param_5[1]);
  if (iVar1 == 0) {
    if (local_20 == 0) {
      if (param_1 != (uint *)0x0) {
        *param_2 = 0;
      }
    }
    else {
      if (param_1 == (uint *)0x0) {
        return 0x20c;
      }
      *param_2 = 1;
      *param_1 = local_1c & 0xffff;
    }
    if (local_14 != 8) {
      return 0x20c;
    }
    *param_3 = local_18;
    iVar1 = 0;
    *param_4 = (uint)local_22;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_writeCipherFieldSet (FUN_68115a30)
// Address: 68115a30
// Size: 109 bytes
// Params: undefined4 * param_1, undefined2 param_2, int param_3, undefined4 param_4, undefined2 param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_writeCipherFieldSet(undefined4 *param_1,undefined2 param_2,int param_3,undefined4 param_4,
            undefined2 param_5)
{
  undefined2 local_1c;
  undefined2 local_1a;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  undefined2 *local_c;
  undefined4 *local_8;
  undefined1 *local_4;
  
  display_fillMemory(local_10,0,0x10);
  local_4 = (undefined1 *)&local_1c;
  if (param_3 != 0) {
    local_1a = param_2;
    local_c = &local_1a;
  }
  local_1c = param_5;
  local_18 = param_4;
  local_8 = &local_18;
  local_14 = 8;
  xtra_writeBERSequence(param_1,(uint *)&DAT_68191e08,(int)local_10);
  return 0;
}



// ============================================================
// Function: xtra_allocRC2Context (FUN_68115ac0)
// Address: 68115ac0
// Size: 83 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 param_3
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl xtra_allocRC2Context(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)display_allocBlock(0x6c);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  param_1[0x19] = *param_2;
  param_1[0x1a] = param_1 + 0x12;
  xtra_initHashKeyContext(param_1,&PTR_PTR_68190a70,param_1 + 0x19,param_3,param_2[1],param_2[2],
               &PTR_LAB_68190a78);
  return param_1;
}



// ============================================================
// Function: xtra_storeCipherKeyData (FUN_68115b20)
// Address: 68115b20
// Size: 91 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_storeCipherKeyData(undefined4 param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  int *local_4;
  
  iVar1 = xtra_readCertBlock(param_2,(int *)&local_4,8);
  if (iVar1 == 0) {
    iVar1 = xtra_copyCertData(param_2,local_4,*param_3,8);
    if (iVar1 == 0) {
      local_4[1] = param_3[1];
      xtra_writeCertBlock(param_2,param_1,local_4);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_allocDESContext (FUN_68115b80)
// Address: 68115b80
// Size: 72 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 param_3
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl xtra_allocDESContext(undefined4 *param_1,undefined4 *param_2,undefined4 param_3)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)display_allocBlock(100);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  xtra_initHashKeyContext(param_1,&PTR_PTR_68190a80,param_1 + 0x12,param_3,*param_2,param_2[1],
               &PTR_LAB_68190bb8);
  return param_1;
}



// ============================================================
// Function: xtra_allocStreamContext (FUN_68115bd0)
// Address: 68115bd0
// Size: 80 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl
xtra_allocStreamContext(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)display_allocBlock(0x3c);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  xtra_allocSymKeyContext(param_1,param_2,param_3);
  param_1[10] = 0;
  param_1[0xe] = param_4;
  param_1[0xd] = param_5;
  param_1[1] = &PTR_FUN_68191e58;
  return param_1;
}



// ============================================================
// Function: xtra_selectEncryptStream (FUN_68115c20)
// Address: 68115c20
// Size: 56 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_selectEncryptStream(int param_1,int *param_2,int *param_3,undefined4 param_4)
{
  int iVar1;
  
  if (((*(int *)(param_1 + 0x28) != 0) && (*(int *)(param_1 + 0x38) != 0)) &&
     (iVar1 = xtra_flushStreamCipher(param_1), iVar1 != 0)) {
    return 0;
  }
  xtra_selectEncryptCipher(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_selectDecryptStream (FUN_68115c60)
// Address: 68115c60
// Size: 56 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_selectDecryptStream(int param_1,int *param_2,int *param_3,undefined4 param_4)
{
  int iVar1;
  
  if (((*(int *)(param_1 + 0x28) != 0) && (*(int *)(param_1 + 0x38) != 0)) &&
     (iVar1 = xtra_flushStreamCipher(param_1), iVar1 != 0)) {
    return 0;
  }
  xtra_selectDecryptCipher(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_finalizeStreamBlock (FUN_68115ca0)
// Address: 68115ca0
// Size: 98 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_finalizeStreamBlock(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0x28) != 0) && (*(int *)(param_1 + 0x38) != 0)) {
    xtra_copyCipherIV(*(undefined4 *)(param_1 + 0x18),param_1 + 0x2c);
  }
  iVar1 = xtra_finalizeCipherBlock(param_1,param_2,param_3,param_4,param_5,param_6);
  if (iVar1 == 0) {
    if ((*(int *)(param_1 + 0x28) != 0) && (*(int *)(param_1 + 0x38) != 0)) {
      iVar1 = xtra_flushStreamCipher(param_1);
      return iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_flushStreamCipher (FUN_68115d10)
// Address: 68115d10
// Size: 175 bytes
// Params: int param_1
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_flushStreamCipher(int param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined1 local_18 [4];
  int local_14;
  undefined1 local_10 [12];
  int local_4;
  
  iVar1 = *(int *)(param_1 + 0x38);
  if (iVar1 == 1) {
    puVar2 = (undefined1 *)(param_1 + 0x2c);
  }
  else if (iVar1 == 2) {
    puVar2 = local_18;
    display_checkAndFree(local_18,*(undefined4 *)(param_1 + 0x10),8);
    local_14 = param_1 + 0x2c;
  }
  else {
    if (iVar1 != 3) {
      return 0;
    }
    puVar2 = local_10;
    display_checkAndFree(local_10,*(undefined4 *)(param_1 + 0x10),0x10);
    local_4 = param_1 + 0x2c;
  }
  xtra_clearCertBlockTags(*(int **)(param_1 + 0x28));
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 0x34))
                    (*(undefined4 **)(param_1 + 0x34),*(undefined4 *)(param_1 + 0x28),puVar2);
  if (iVar1 == 0) {
    xtra_lookupCertBlockEntry(*(int *)(param_1 + 0x28),(int *)(param_1 + 0x10),*(int *)(param_1 + 0x34));
    iVar1 = 0;
    *(undefined4 *)(param_1 + 0x28) = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_initMD5Digest (FUN_68115dc0)
// Address: 68115dc0
// Size: 41 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initMD5Digest(undefined4 *param_1)
{
  xtra_initHashState(param_1,0x10,param_1 + 8);
  display_initMD5State(param_1 + 0x14);
  param_1[7] = &PTR_LAB_68191e78;
  return 0;
}



// ============================================================
// Function: xtra_feedHashData (FUN_68115df0)
// Address: 68115df0
// Size: 24 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_feedHashData(int *param_1,undefined4 param_2,undefined4 param_3)
{
  xtra_updateHashState(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: xtra_finalizeHash (FUN_68115e10)
// Address: 68115e10
// Size: 24 bytes
// Params: int * param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_finalizeHash(int *param_1,int param_2,uint param_3)
{
  xtra_finalizeHashState(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: xtra_parseBERCert (FUN_68115e90)
// Address: 68115e90
// Size: 1155 bytes
// Params: uint * param_1, uint * param_2, int param_3, byte * param_4, uint param_5, undefined4 * param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_parseBERCert(uint *param_1,uint *param_2,int param_3,byte *param_4,uint param_5,undefined4 *param_6)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  undefined3 extraout_var;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  uint uStack_40;
  uint local_3c;
  uint *puStack_38;
  int iStack_34;
  uint uStack_30;
  uint uStack_2c;
  int iStack_28;
  int iStack_24;
  byte *pbStack_20;
  uint uStack_1c;
  uint uStack_18;
  byte *pbStack_14;
  byte *pbStack_10;
  uint uStack_c;
  byte *pbStack_8;
  uint uStack_4;
  
  local_3c = (*param_2 | 0x100) - 0x100;
  if (param_6 != (undefined4 *)0x0) {
    iVar3 = (**(code **)*param_6)(param_6,&param_4,&param_5);
    if (iVar3 != 0) {
      return iVar3;
    }
    if ((*(int *)(param_3 + param_2[3] * 4) != 0) && ((local_3c & 0x2400) == 0)) {
      param_6 = (undefined4 *)0x0;
    }
  }
  if (*(undefined **)(param_3 + param_2[3] * 4) == &DAT_6818eff8) {
    *param_1 = 0;
    return 0;
  }
  bVar2 = xtra_processCryptoOp(param_1,&uStack_2c,&iStack_24,&pbStack_20,param_4,param_5);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    if ((CONCAT31(extraout_var,bVar2) == 6) && ((local_3c & 0x400) != 0)) {
      iVar3 = xtra_parseBERCertChunked(param_1,(int *)param_2,param_3,(int)param_4,param_5,param_6,uStack_2c,
                           (int *)&pbStack_20);
      return iVar3;
    }
    return 0x20c;
  }
  uVar6 = *param_1;
  if (uVar6 == 0) {
    iStack_28 = iStack_24 + 4;
  }
  else {
    param_6 = (undefined4 *)0x0;
  }
  if ((local_3c & 0xff) == 0x1d) {
    if (uVar6 != 0) goto LAB_68116299;
    iVar3 = xtra_readBERData(param_1,param_4,param_5);
  }
  else {
    if (uStack_2c != (local_3c & 0xff)) {
      if ((((local_3c & 0x2220) == 0) || ((param_2[4] & 0x20) != 0)) ||
         ((local_3c & 0xdf) != uStack_2c)) {
        if ((*param_2 & 0x100) == 0) {
          return 0x20c;
        }
        *param_1 = 0;
        return 0;
      }
      iVar3 = xtra_parseBERCert(&uStack_30,param_2 + 4,param_3,param_4,uVar6,(undefined4 *)0x0);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    if ((uStack_2c & 0x20) == 0) goto LAB_68116299;
    xtra_readCertData((int *)&uStack_40,param_2);
    uVar6 = 1;
    puVar4 = param_2;
    if (1 < uStack_40) {
      do {
        if ((puVar4[4] != 0x1e) && (*(int *)(param_3 + puVar4[7] * 4) != 0)) break;
        uVar6 = uVar6 + 1;
        puVar4 = puVar4 + 4;
      } while (uVar6 < uStack_40);
      if (uVar6 < uStack_40) {
        if (*param_1 == 0) {
          uStack_1c = param_5 - iStack_28;
        }
        if (((local_3c & 0xc0) == 0) || (iStack_34 = 1, (local_3c & 0x800) != 0)) {
          iStack_34 = 0;
        }
        uVar6 = 0;
        if (param_6 != (undefined4 *)0x0) {
          uVar6 = iStack_24 + 2;
          pbStack_20 = param_4;
        }
        iVar3 = 1;
LAB_681160f0:
        if (iStack_34 == 0) {
          if (((local_3c & 0x200) == 0) && (param_2[iVar3 * 4] == 0x1e)) goto LAB_68116133;
          if (*param_1 == 0) {
            if ((pbStack_20[uVar6] == 0) && ((pbStack_20 + uVar6)[1] == 0)) goto LAB_68116133;
          }
          else if (uStack_1c <= uVar6) goto LAB_68116133;
        }
        puStack_38 = param_2 + iVar3 * 4;
        iVar5 = xtra_parseBERCert(&uStack_30,puStack_38,param_3,pbStack_20 + uVar6,uStack_1c - uVar6,
                             param_6);
        if (iVar5 != 0) {
          return iVar5;
        }
        if (param_6 != (undefined4 *)0x0) {
          uVar6 = 0;
        }
        uVar6 = uVar6 + uStack_30;
        if (iStack_34 != 0) goto LAB_68116133;
        if ((local_3c & 0x200) == 0) {
          xtra_readCertData((int *)&uStack_40,puStack_38);
          iVar3 = iVar3 + uStack_40;
        }
        goto LAB_681160f0;
      }
    }
    if (*param_1 != 0) goto LAB_68116299;
    iVar3 = xtra_readBERData(param_1,param_4,param_5);
  }
  if (iVar3 != 0) {
    return iVar3;
  }
  uStack_1c = *param_1 - iStack_28;
LAB_68116299:
  puVar1 = *(undefined4 **)(param_3 + param_2[3] * 4);
  if (puVar1 != (undefined4 *)0x0) {
    if ((code *)param_2[1] == (code *)0x0) {
      *puVar1 = param_4;
      *(uint *)(*(int *)(param_3 + param_2[3] * 4) + 4) = *param_1;
    }
    else {
      uStack_18 = uStack_2c;
      pbStack_14 = param_4 + 1;
      uStack_4 = *param_1;
      pbStack_8 = param_4;
      pbStack_10 = pbStack_20;
      uStack_c = uStack_1c;
      iVar3 = (*(code *)param_2[1])(&uStack_18,puVar1);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
  }
  return 0;
LAB_68116133:
  if (*param_1 == 0) {
    if (param_6 != (undefined4 *)0x0) {
      iStack_28 = 2;
    }
    *param_1 = iStack_28 + uVar6;
    uStack_1c = uVar6;
  }
  else if (uVar6 != uStack_1c) {
    return 0x20c;
  }
  if ((iStack_34 == 0) && ((local_3c & 0x200) == 0)) {
    uVar6 = param_2[iVar3 * 4];
    while (uVar6 != 0x1e) {
      puVar4 = param_2 + iVar3 * 4;
      if (((*puVar4 & 0x100) == 0) && (*(undefined **)(param_3 + puVar4[3] * 4) != &DAT_6818eff8)) {
        return 0x20c;
      }
      xtra_readCertData((int *)&uStack_40,puVar4);
      iVar3 = iVar3 + uStack_40;
      uVar6 = param_2[iVar3 * 4];
    }
  }
  goto LAB_68116299;
}



// ============================================================
// Function: xtra_parseBERCertChunked (FUN_68116320)
// Address: 68116320
// Size: 275 bytes
// Params: uint * param_1, int * param_2, int param_3, int param_4, uint param_5, undefined4 * param_6, uint param_7, int * param_8
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_parseBERCertChunked(uint *param_1,int *param_2,int param_3,int param_4,uint param_5,undefined4 *param_6,
            uint param_7,int *param_8)

{
  undefined4 *puVar1;
  int iVar2;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  uint local_4;
  
  puVar1 = param_6;
  if (param_6 == (undefined4 *)0x0) {
    return 0x20c;
  }
  if (((*param_2 == 0x41d) && (*(int *)(param_3 + param_2[3] * 4) != 0)) && (param_2[1] != 0)) {
    local_18 = param_7 | 0x400;
    local_4 = param_5;
    local_14 = param_4 + 1;
    local_8 = param_4;
    local_10 = *param_8;
    local_c = (param_4 - local_10) + param_5;
    while (param_4 = local_8,
          iVar2 = (*(code *)param_2[1])(&local_18,*(undefined4 *)(param_3 + param_2[3] * 4)),
          iVar2 == 0) {
      if ((local_18 & 0x400) == 0) {
        return 0;
      }
      *param_1 = *param_1 - param_5;
      param_4 = param_4 + param_5;
      iVar2 = (**(code **)*puVar1)(puVar1,&param_4,&param_5);
      if (iVar2 != 0) {
        return iVar2;
      }
      local_8 = param_4;
      local_10 = param_4;
      local_c = *param_1;
      if (param_5 < local_c) {
        local_4 = param_5;
        local_c = param_5;
      }
      else {
        local_18 = local_18 - 0x400;
        local_4 = local_c;
      }
    }
  }
  else {
    iVar2 = 0x208;
  }
  return iVar2;
}



// ============================================================
// Function: xtra_initHashKeyContext (FUN_68116440)
// Address: 68116440
// Size: 65 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, undefined4 param_7
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_initHashKeyContext(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 param_6,undefined4 param_7)
{
  xtra_allocHashContext(param_1,param_2,param_3,0,0);
  param_1[0x15] = param_4;
  param_1[0x16] = param_5;
  param_1[0x17] = param_6;
  param_1[1] = &PTR_LAB_68191e90;
  param_1[0x18] = param_7;
  return 0;
}



// ============================================================
// Function: xtra_bindDecryptHandler (FUN_68116520)
// Address: 68116520
// Size: 100 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_bindDecryptHandler(int param_1,int *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int local_14 [5];
  
  xtra_clearBERHeader(local_14);
  iVar1 = xtra_deriveSessionKey(param_1,param_2,(int)local_14,param_3,param_4);
  if (iVar1 == 0) {
    iVar1 = xtra_selectDecryptCipher(param_1,local_14,param_3,param_4);
  }
  xtra_readCertBlockData(local_14);
  return iVar1;
}



// ============================================================
// Function: xtra_deriveSessionKey (FUN_68116590)
// Address: 68116590
// Size: 334 bytes
// Params: int param_1, int * param_2, int param_3, int * param_4, undefined4 param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_deriveSessionKey(int param_1,int *param_2,int param_3,int *param_4,undefined4 param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 local_2c;
  undefined4 *local_28;
  undefined4 local_24 [9];
  
  xtra_allocCryptoContext(local_24,*(undefined4 *)(param_1 + 0x54),0);
  iVar1 = xtra_readCertChain(param_2,(int *)&local_28,0x681900f8);
  if ((((iVar1 == 0) && (iVar1 = xtra_bindCryptoHandler((int)local_24,(int *)0x0,param_4,param_5), iVar1 == 0)
       ) && (iVar1 = xtra_createTextObject((int)local_24,*local_28,local_28[1],param_5), iVar1 == 0)) &&
     (iVar1 = xtra_createTextObject((int)local_24,*(undefined4 *)(param_1 + 0x58),8,param_5), iVar1 == 0)) {
    iVar3 = param_1 + 0x40;
    iVar1 = xtra_invokeCryptoOp((int)local_24,iVar3,&local_2c,0x14,param_5);
    if (iVar1 == 0) {
      iVar2 = *(int *)(param_1 + 0x5c);
      if (iVar2 == 0) {
        iVar1 = 0x20c;
      }
      else {
        do {
          iVar2 = iVar2 + -1;
          if (iVar2 == 0) break;
          iVar1 = xtra_createTextObject((int)local_24,iVar3,local_2c,param_5);
          if (iVar1 != 0) goto LAB_681166c7;
          iVar1 = xtra_invokeCryptoOp((int)local_24,iVar3,&local_2c,0x14,param_5);
        } while (iVar1 == 0);
        if (iVar1 == 0) {
          iVar1 = xtra_invokeCertHandler(param_3,*(undefined4 **)(param_1 + 0x60),iVar3);
        }
      }
    }
  }
LAB_681166c7:
  xtra_destroySymKeyBuffer((int)local_24);
  return iVar1;
}



// ============================================================
// Function: xtra_initHashState (FUN_681166e0)
// Address: 681166e0
// Size: 64 bytes
// Params: undefined4 * param_1, size_t param_2, void * param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initHashState(undefined4 *param_1,size_t param_2,void *param_3)
{
  param_1[2] = param_2;
  *param_1 = 0;
  param_1[3] = param_3;
  param_1[5] = param_2 + (int)param_3;
  param_1[4] = param_2 + (int)param_3 + param_2;
  param_1[6] = 0;
  param_1[1] = 2;
  display_fillMemory(param_3,0,param_2);
  return 0;
}



// ============================================================
// Function: xtra_updateHashState (FUN_68116720)
// Address: 68116720
// Size: 115 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_updateHashState(int *param_1,undefined4 param_2,undefined4 param_3)
{
  byte *pbVar1;
  
  if (param_1[1] == 2) {
    (**(code **)param_1[7])(param_1,0,0);
    (**(code **)(param_1[7] + 4))(param_1,param_1[4]);
    pbVar1 = (byte *)(param_1[2] + -1 + param_1[4]);
    *pbVar1 = *pbVar1 | 1;
  }
  if (param_1[1] != 0) {
    param_1[1] = param_1[1] + -1;
  }
  if ((param_1[1] == 0) && (*param_1 == 0)) {
    (**(code **)param_1[7])(param_1,param_1[3],param_1[2]);
  }
  (**(code **)param_1[7])(param_1,param_2,param_3);
  *param_1 = 1;
  return 0;
}



// ============================================================
// Function: xtra_finalizeHashState (FUN_681167a0)
// Address: 681167a0
// Size: 248 bytes
// Params: int * param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_finalizeHashState(int *param_1,int param_2,uint param_3)
{
  char *pcVar1;
  char cVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  if (*param_1 != 0) {
    *param_1 = 0;
    param_1[6] = 0;
    (**(code **)(param_1[7] + 4))(param_1,param_1[3]);
  }
  uVar5 = param_1[6];
  if (uVar5 < param_3) {
    do {
      display_checkAndFree(param_2,(param_1[2] - uVar5) + param_1[5],uVar5);
      param_2 = param_2 + uVar5;
      param_3 = param_3 - uVar5;
      (**(code **)param_1[7])(param_1,param_1[3],param_1[2]);
      (**(code **)(param_1[7] + 4))(param_1,param_1[5]);
      uVar5 = param_1[2];
      if (param_1[1] == 0) {
        uVar4 = 0;
        uVar3 = uVar5;
        while (uVar3 = uVar3 - 1, -1 < (int)uVar3) {
          uVar4 = (uVar4 >> 8) +
                  (uint)*(byte *)(param_1[4] + uVar3) + (uint)*(byte *)(param_1[3] + uVar3);
          *(byte *)(param_1[3] + uVar3) = (byte)uVar4;
        }
      }
      else {
        uVar4 = 0;
        if (uVar5 != 0) {
          do {
            pcVar1 = (char *)((param_1[2] - uVar4) + -1 + param_1[3]);
            cVar2 = *pcVar1;
            *pcVar1 = cVar2 + '\x01';
            if (cVar2 != '\0') break;
            uVar4 = uVar4 + 1;
          } while (uVar4 < (uint)param_1[2]);
        }
      }
    } while (uVar5 < param_3);
  }
  display_checkAndFree(param_2,(param_1[2] + param_1[5]) - uVar5,param_3);
  param_1[6] = uVar5 - param_3;
  return 0;
}



