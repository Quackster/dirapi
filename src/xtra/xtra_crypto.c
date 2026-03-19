// Module: xtra
// Topic: Hash algorithms, bignum math, BER TLV parsing, attribute store, CRL API, crypto wrappers
// Address range: 0x6810B754 - 0x6810FF70
// Functions (84):
//   xtra_md5Transform
//   xtra_initMD5Context
//   xtra_updateMD5
//   xtra_finalizeMD5
//   xtra_initHashContext
//   xtra_finalizeHashContext
//   xtra_processDHParams
//   xtra_decodeDHKeyParams
//   xtra_encodeDHKeyParams
//   xtra_getCryptoState
//   xtra_destroyCryptoKey
//   xtra_initCryptoKey
//   xtra_convertBignumToBytes
//   xtra_initCryptoBuffer
//   xtra_clearContext
//   xtra_freeContext
//   xtra_getCryptoKeyData
//   xtra_growCryptoBuffer
//   xtra_performRSAOperation
//   xtra_insertBitValue
//   xtra_encodeBERLength
//   xtra_decodeBERTagByte
//   xtra_getBERHeaderSize
//   xtra_parseBERTLV
//   xtra_writeBERTLVHeader
//   xtra_encodeBERTLV
//   xtra_storeCryptoSessionData
//   xtra_processCryptoOp
//   xtra_processCryptoData
//   xtra_readBERConstructed
//   xtra_readBERExplicitTag
//   xtra_readBEROptionalField
//   xtra_readBERSequenceItems
//   xtra_addBERAttributeValue
//   xtra_freeBERAttributeStore
//   xtra_initBERAttributeWriter
//   xtra_writeBERAttributeSet
//   xtra_freeAttributeList
//   xtra_getAttributeByIndex
//   xtra_setAttributeValue
//   xtra_addAttributeToList
//   xtra_removeAttributeByIndex
//   xtra_growAttributeList
//   xtra_insertAttributeAtIndex
//   xtra_createAttributeNode
//   xtra_getAttributeCount
//   xtra_resetAttributeIterator
//   xtra_decryptBlockData
//   xtra_copyBERContent
//   xtra_readBEREnvelopedData
//   xtra_writeBEREnvelopedData
//   xtra_extractBERSignedData
//   xtra_buildCRLEntry
//   xtra_parseCRLEntry
//   xtra_addCRLEntryToList
//   xtra_encodeCRLAttributes
//   xtra_decodeCRLAttributes
//   xtra_buildCRLDistributionPoint
//   xtra_parseCRLDistributionPoint
//   xtra_openCryptoSession
//   xtra_readCRLExtensions
//   xtra_writeCRLExtensions
//   xtra_attachCryptoToReader
//   xtra_createSignedContent
//   xtra_finalizeSignedContent
//   xtra_createCryptoReader
//   xtra_loadCryptoFromCert
//   xtra_storeCryptoFromCert
//   xtra_extractSignatureData
//   xtra_extractPublicKeyData
//   xtra_finalizeCrypto
//   xtra_extractCertPublicKey
//   xtra_lookupCRLByIssuer
//   xtra_initCryptoContext
//   xtra_updateCryptoState
//   xtra_verifyCertSignature
//   xtra_setupCryptoMode
//   xtra_computeDigestValue
//   xtra_verifyDigestSignature
//   xtra_loadCryptoProvider
//   xtra_decryptData
//   xtra_encryptDataEx
//   xtra_generateRandomBytes
//   xtra_encryptData

// ============================================================
// Function: xtra_md5Transform (FUN_6810b754)
// Address: 6810b754
// Size: 1884 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_md5Transform(int *param_1,int *param_2)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  
  uVar4 = param_1[1];
  uVar2 = param_1[2];
  uVar1 = *param_1 + *param_2 + -0x28955b88 + (uVar2 & uVar4) + ((uVar4 ^ 0xffffffff) & param_1[3]);
  uVar1 = (uVar1 * 0x80 | uVar1 >> 0x19) + uVar4;
  uVar3 = param_1[3] + param_2[1] + -0x173848aa + (uVar4 & uVar1) + ((uVar1 ^ 0xffffffff) & uVar2);
  uVar3 = (uVar3 * 0x1000 | uVar3 >> 0x14) + uVar1;
  uVar2 = uVar2 + param_2[2] + 0x242070db + (uVar1 & uVar3) + ((uVar3 ^ 0xffffffff) & uVar4);
  uVar2 = (uVar2 * 0x20000 | uVar2 >> 0xf) + uVar3;
  uVar4 = uVar4 + param_2[3] + -0x3e423112 + (uVar3 & uVar2) + ((uVar2 ^ 0xffffffff) & uVar1);
  uVar5 = (uVar4 * 0x400000 | uVar4 >> 10) + uVar2;
  uVar4 = uVar1 + param_2[4] + -0xa83f051 + (uVar2 & uVar5) + ((uVar5 ^ 0xffffffff) & uVar3);
  uVar4 = (uVar4 * 0x80 | uVar4 >> 0x19) + uVar5;
  uVar1 = uVar3 + param_2[5] + 0x4787c62a + (uVar5 & uVar4) + ((uVar4 ^ 0xffffffff) & uVar2);
  uVar1 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar4;
  uVar2 = uVar2 + param_2[6] + -0x57cfb9ed + (uVar4 & uVar1) + ((uVar1 ^ 0xffffffff) & uVar5);
  uVar2 = (uVar2 * 0x20000 | uVar2 >> 0xf) + uVar1;
  uVar3 = uVar5 + param_2[7] + -0x2b96aff + (uVar1 & uVar2) + ((uVar2 ^ 0xffffffff) & uVar4);
  uVar3 = (uVar3 * 0x400000 | uVar3 >> 10) + uVar2;
  uVar4 = uVar4 + param_2[8] + 0x698098d8 + (uVar2 & uVar3) + ((uVar3 ^ 0xffffffff) & uVar1);
  uVar4 = (uVar4 * 0x80 | uVar4 >> 0x19) + uVar3;
  uVar1 = uVar1 + param_2[9] + -0x74bb0851 + (uVar3 & uVar4) + ((uVar4 ^ 0xffffffff) & uVar2);
  uVar1 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar4;
  uVar2 = uVar2 + param_2[10] + -0xa44f + (uVar4 & uVar1) + ((uVar1 ^ 0xffffffff) & uVar3);
  uVar2 = (uVar2 * 0x20000 | uVar2 >> 0xf) + uVar1;
  uVar3 = uVar3 + param_2[0xb] + -0x76a32842 + (uVar1 & uVar2) + ((uVar2 ^ 0xffffffff) & uVar4);
  uVar3 = (uVar3 * 0x400000 | uVar3 >> 10) + uVar2;
  uVar4 = uVar4 + param_2[0xc] + 0x6b901122 + (uVar2 & uVar3) + ((uVar3 ^ 0xffffffff) & uVar1);
  uVar4 = (uVar4 * 0x80 | uVar4 >> 0x19) + uVar3;
  uVar1 = uVar1 + param_2[0xd] + -0x2678e6d + (uVar3 & uVar4) + ((uVar4 ^ 0xffffffff) & uVar2);
  uVar1 = (uVar1 * 0x1000 | uVar1 >> 0x14) + uVar4;
  uVar2 = uVar2 + param_2[0xe] + -0x5986bc72 + (uVar4 & uVar1) + ((uVar1 ^ 0xffffffff) & uVar3);
  uVar2 = (uVar2 * 0x20000 | uVar2 >> 0xf) + uVar1;
  uVar3 = uVar3 + param_2[0xf] + 0x49b40821 + (uVar1 & uVar2) + ((uVar2 ^ 0xffffffff) & uVar4);
  uVar3 = (uVar3 * 0x400000 | uVar3 >> 10) + uVar2;
  uVar4 = uVar4 + param_2[1] + -0x9e1da9e + (uVar1 & uVar3) + ((uVar1 ^ 0xffffffff) & uVar2);
  uVar4 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar3;
  uVar1 = uVar1 + param_2[6] + -0x3fbf4cc0 + (uVar2 & uVar4) + ((uVar2 ^ 0xffffffff) & uVar3);
  uVar1 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar4;
  uVar2 = uVar2 + param_2[0xb] + 0x265e5a51 + (uVar3 & uVar1) + ((uVar3 ^ 0xffffffff) & uVar4);
  uVar2 = (uVar2 * 0x4000 | uVar2 >> 0x12) + uVar1;
  uVar3 = uVar3 + *param_2 + -0x16493856 + (uVar4 & uVar2) + ((uVar4 ^ 0xffffffff) & uVar1);
  uVar3 = (uVar3 * 0x100000 | uVar3 >> 0xc) + uVar2;
  uVar4 = uVar4 + param_2[5] + -0x29d0efa3 + (uVar1 & uVar3) + ((uVar1 ^ 0xffffffff) & uVar2);
  uVar4 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar3;
  uVar1 = uVar1 + param_2[10] + 0x2441453 + (uVar2 & uVar4) + ((uVar2 ^ 0xffffffff) & uVar3);
  uVar1 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar4;
  uVar2 = uVar2 + param_2[0xf] + -0x275e197f + (uVar3 & uVar1) + ((uVar3 ^ 0xffffffff) & uVar4);
  uVar2 = (uVar2 * 0x4000 | uVar2 >> 0x12) + uVar1;
  uVar3 = uVar3 + param_2[4] + -0x182c0438 + (uVar4 & uVar2) + ((uVar4 ^ 0xffffffff) & uVar1);
  uVar3 = (uVar3 * 0x100000 | uVar3 >> 0xc) + uVar2;
  uVar4 = uVar4 + param_2[9] + 0x21e1cde6 + (uVar1 & uVar3) + ((uVar1 ^ 0xffffffff) & uVar2);
  uVar4 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar3;
  uVar1 = uVar1 + param_2[0xe] + -0x3cc8f82a + (uVar2 & uVar4) + ((uVar2 ^ 0xffffffff) & uVar3);
  uVar1 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar4;
  uVar2 = uVar2 + param_2[3] + -0xb2af279 + (uVar3 & uVar1) + ((uVar3 ^ 0xffffffff) & uVar4);
  uVar2 = (uVar2 * 0x4000 | uVar2 >> 0x12) + uVar1;
  uVar3 = uVar3 + param_2[8] + 0x455a14ed + (uVar4 & uVar2) + ((uVar4 ^ 0xffffffff) & uVar1);
  uVar3 = (uVar3 * 0x100000 | uVar3 >> 0xc) + uVar2;
  uVar4 = uVar4 + param_2[0xd] + -0x561c16fb + (uVar1 & uVar3) + ((uVar1 ^ 0xffffffff) & uVar2);
  uVar4 = (uVar4 * 0x20 | uVar4 >> 0x1b) + uVar3;
  uVar1 = uVar1 + param_2[2] + -0x3105c08 + (uVar2 & uVar4) + ((uVar2 ^ 0xffffffff) & uVar3);
  uVar1 = (uVar1 * 0x200 | uVar1 >> 0x17) + uVar4;
  uVar2 = uVar2 + param_2[7] + 0x676f02d9 + (uVar3 & uVar1) + ((uVar3 ^ 0xffffffff) & uVar4);
  uVar2 = (uVar2 * 0x4000 | uVar2 >> 0x12) + uVar1;
  uVar3 = uVar3 + param_2[0xc] + -0x72d5b376 + (uVar4 & uVar2) + ((uVar4 ^ 0xffffffff) & uVar1);
  uVar3 = (uVar3 * 0x100000 | uVar3 >> 0xc) + uVar2;
  uVar4 = uVar4 + param_2[5] + -0x5c6be + (uVar2 ^ uVar1 ^ uVar3);
  uVar4 = (uVar4 * 0x10 | uVar4 >> 0x1c) + uVar3;
  uVar1 = uVar1 + param_2[8] + -0x788e097f + (uVar3 ^ uVar2 ^ uVar4);
  uVar1 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar4;
  uVar2 = uVar2 + param_2[0xb] + 0x6d9d6122 + (uVar4 ^ uVar3 ^ uVar1);
  uVar2 = (uVar2 * 0x10000 | uVar2 >> 0x10) + uVar1;
  uVar3 = uVar3 + param_2[0xe] + -0x21ac7f4 + (uVar1 ^ uVar4 ^ uVar2);
  uVar3 = (uVar3 * 0x800000 | uVar3 >> 9) + uVar2;
  uVar4 = uVar4 + param_2[1] + -0x5b4115bc + (uVar2 ^ uVar1 ^ uVar3);
  uVar4 = (uVar4 * 0x10 | uVar4 >> 0x1c) + uVar3;
  uVar1 = uVar1 + param_2[4] + 0x4bdecfa9 + (uVar3 ^ uVar2 ^ uVar4);
  uVar1 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar4;
  uVar2 = uVar2 + param_2[7] + -0x944b4a0 + (uVar4 ^ uVar3 ^ uVar1);
  uVar2 = (uVar2 * 0x10000 | uVar2 >> 0x10) + uVar1;
  uVar3 = uVar3 + param_2[10] + -0x41404390 + (uVar1 ^ uVar4 ^ uVar2);
  uVar3 = (uVar3 * 0x800000 | uVar3 >> 9) + uVar2;
  uVar4 = uVar4 + param_2[0xd] + 0x289b7ec6 + (uVar2 ^ uVar1 ^ uVar3);
  uVar4 = (uVar4 * 0x10 | uVar4 >> 0x1c) + uVar3;
  uVar1 = uVar1 + *param_2 + -0x155ed806 + (uVar3 ^ uVar2 ^ uVar4);
  uVar1 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar4;
  uVar2 = uVar2 + param_2[3] + -0x2b10cf7b + (uVar4 ^ uVar3 ^ uVar1);
  uVar2 = (uVar2 * 0x10000 | uVar2 >> 0x10) + uVar1;
  uVar3 = uVar3 + param_2[6] + 0x4881d05 + (uVar1 ^ uVar4 ^ uVar2);
  uVar3 = (uVar3 * 0x800000 | uVar3 >> 9) + uVar2;
  uVar4 = uVar4 + param_2[9] + -0x262b2fc7 + (uVar2 ^ uVar1 ^ uVar3);
  uVar4 = (uVar4 * 0x10 | uVar4 >> 0x1c) + uVar3;
  uVar1 = uVar1 + param_2[0xc] + -0x1924661b + (uVar3 ^ uVar2 ^ uVar4);
  uVar1 = (uVar1 * 0x800 | uVar1 >> 0x15) + uVar4;
  uVar2 = uVar2 + param_2[0xf] + 0x1fa27cf8 + (uVar4 ^ uVar3 ^ uVar1);
  uVar2 = (uVar2 * 0x10000 | uVar2 >> 0x10) + uVar1;
  uVar3 = uVar3 + param_2[2] + -0x3b53a99b + (uVar1 ^ uVar4 ^ uVar2);
  uVar3 = (uVar3 * 0x800000 | uVar3 >> 9) + uVar2;
  uVar4 = uVar4 + *param_2 + -0xbd6ddbc + ((uVar1 ^ 0xffffffff | uVar3) ^ uVar2);
  uVar4 = (uVar4 * 0x40 | uVar4 >> 0x1a) + uVar3;
  uVar1 = uVar1 + param_2[7] + 0x432aff97 + ((uVar2 ^ 0xffffffff | uVar4) ^ uVar3);
  uVar1 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar4;
  uVar2 = uVar2 + param_2[0xe] + -0x546bdc59 + ((uVar3 ^ 0xffffffff | uVar1) ^ uVar4);
  uVar2 = (uVar2 * 0x8000 | uVar2 >> 0x11) + uVar1;
  uVar3 = uVar3 + param_2[5] + -0x36c5fc7 + ((uVar4 ^ 0xffffffff | uVar2) ^ uVar1);
  uVar3 = (uVar3 * 0x200000 | uVar3 >> 0xb) + uVar2;
  uVar4 = uVar4 + param_2[0xc] + 0x655b59c3 + ((uVar1 ^ 0xffffffff | uVar3) ^ uVar2);
  uVar4 = (uVar4 * 0x40 | uVar4 >> 0x1a) + uVar3;
  uVar1 = uVar1 + param_2[3] + -0x70f3336e + ((uVar2 ^ 0xffffffff | uVar4) ^ uVar3);
  uVar1 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar4;
  uVar2 = uVar2 + param_2[10] + -0x100b83 + ((uVar3 ^ 0xffffffff | uVar1) ^ uVar4);
  uVar2 = (uVar2 * 0x8000 | uVar2 >> 0x11) + uVar1;
  uVar3 = uVar3 + param_2[1] + -0x7a7ba22f + ((uVar4 ^ 0xffffffff | uVar2) ^ uVar1);
  uVar3 = (uVar3 * 0x200000 | uVar3 >> 0xb) + uVar2;
  uVar4 = uVar4 + param_2[8] + 0x6fa87e4f + ((uVar1 ^ 0xffffffff | uVar3) ^ uVar2);
  uVar4 = (uVar4 * 0x40 | uVar4 >> 0x1a) + uVar3;
  uVar1 = uVar1 + param_2[0xf] + -0x1d31920 + ((uVar2 ^ 0xffffffff | uVar4) ^ uVar3);
  uVar1 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar4;
  uVar2 = uVar2 + param_2[6] + -0x5cfebcec + ((uVar3 ^ 0xffffffff | uVar1) ^ uVar4);
  uVar2 = (uVar2 * 0x8000 | uVar2 >> 0x11) + uVar1;
  uVar3 = uVar3 + param_2[0xd] + 0x4e0811a1 + ((uVar4 ^ 0xffffffff | uVar2) ^ uVar1);
  uVar3 = (uVar3 * 0x200000 | uVar3 >> 0xb) + uVar2;
  uVar4 = uVar4 + param_2[4] + -0x8ac817e + ((uVar1 ^ 0xffffffff | uVar3) ^ uVar2);
  uVar4 = (uVar4 * 0x40 | uVar4 >> 0x1a) + uVar3;
  uVar1 = uVar1 + param_2[0xb] + -0x42c50dcb + ((uVar2 ^ 0xffffffff | uVar4) ^ uVar3);
  uVar1 = (uVar1 * 0x400 | uVar1 >> 0x16) + uVar4;
  uVar2 = uVar2 + param_2[2] + 0x2ad7d2bb + ((uVar3 ^ 0xffffffff | uVar1) ^ uVar4);
  uVar2 = (uVar2 * 0x8000 | uVar2 >> 0x11) + uVar1;
  uVar3 = uVar3 + param_2[9] + -0x14792c6f + ((uVar4 ^ 0xffffffff | uVar2) ^ uVar1);
  param_1[3] = param_1[3] + uVar1;
  param_1[2] = param_1[2] + uVar2;
  param_1[1] = param_1[1] + (uVar3 * 0x200000 | uVar3 >> 0xb) + uVar2;
  *param_1 = *param_1 + uVar4;
  return 0;
}



// ============================================================
// Function: xtra_initMD5Context (FUN_6810beb0)
// Address: 6810beb0
// Size: 47 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initMD5Context(undefined4 *param_1)
{
  param_1[6] = 0;
  param_1[5] = 0;
  param_1[1] = 0xefcdab89;
  param_1[2] = 0x98badcfe;
  param_1[3] = 0x10325476;
  param_1[4] = 0xc3d2e1f0;
  *param_1 = 0x67452301;
  return 0;
}



// ============================================================
// Function: xtra_updateMD5 (FUN_6810bee0)
// Address: 6810bee0
// Size: 171 bytes
// Params: int param_1, int param_2, uint param_3, undefined * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_updateMD5(int param_1,int param_2,uint param_3,undefined *param_4)
{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = *(uint *)(param_1 + 0x18) + param_3;
  uVar3 = *(uint *)(param_1 + 0x18) & 0x3f;
  *(uint *)(param_1 + 0x18) = uVar1;
  if (uVar1 < param_3) {
    *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
  }
  if ((uVar3 != 0) && (0x3f < param_3 + uVar3)) {
    iVar2 = param_2 - uVar3;
    param_3 = (param_3 + uVar3) - 0x40;
    display_checkAndFree(param_1 + uVar3 + 0x1c,param_2,0x40 - uVar3);
    uVar3 = 0;
    (*(code *)param_4)(param_1,param_1 + 0x1c);
    param_2 = iVar2 + 0x40;
  }
  if (0x3f < param_3) {
    uVar1 = param_3 >> 6;
    param_3 = param_3 + uVar1 * -0x40;
    iVar2 = param_2;
    do {
      param_2 = iVar2 + 0x40;
      (*(code *)param_4)(param_1,iVar2);
      uVar1 = uVar1 - 1;
      iVar2 = param_2;
    } while (uVar1 != 0);
  }
  display_checkAndFree(param_1 + uVar3 + 0x1c,param_2,param_3);
  return 0;
}



// ============================================================
// Function: xtra_finalizeMD5 (FUN_6810bf90)
// Address: 6810bf90
// Size: 152 bytes
// Params: undefined4 * param_1, int param_2, undefined * param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_finalizeMD5(undefined4 *param_1,int param_2,undefined *param_3)
{
  uint uVar1;
  uint local_50;
  int local_4c;
  undefined1 local_48;
  undefined1 local_47 [71];
  
  uVar1 = -(param_1[6] & 0x3f) + 0x40;
  if (uVar1 < 9) {
    uVar1 = -(param_1[6] & 0x3f) + 0x80;
  }
  local_48 = 0x80;
  display_fillMemory(local_47,0,uVar1 - 7);
  local_4c = param_1[6] << 3;
  local_50 = param_1[5] << 3 | (uint)param_1[6] >> 0x1d;
  xtra_initHashContext((int)&local_50 + uVar1,&local_50,2);
  xtra_updateMD5((int)param_1,(int)&local_48,uVar1,param_3);
  xtra_initHashContext(param_2,param_1,5);
  xtra_initMD5Context(param_1);
  return 0;
}



// ============================================================
// Function: xtra_initHashContext (FUN_6810c030)
// Address: 6810c030
// Size: 65 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initHashContext(int param_1,undefined4 *param_2,int param_3)
{
  undefined1 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  for (; param_3 != 0; param_3 = param_3 + -1) {
    puVar1 = (undefined1 *)(param_1 + iVar2);
    iVar2 = iVar2 + 4;
    *puVar1 = (char)((uint)*param_2 >> 0x18);
    puVar1[1] = (char)((uint)*param_2 >> 0x10);
    puVar1[2] = (char)((uint)*param_2 >> 8);
    puVar1[3] = *(undefined1 *)param_2;
    param_2 = param_2 + 1;
  }
  return 0;
}



// ============================================================
// Function: xtra_finalizeHashContext (FUN_6810c080)
// Address: 6810c080
// Size: 77 bytes
// Params: uint * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_finalizeHashContext(uint *param_1,int param_2,int param_3)
{
  byte *pbVar1;
  int iVar2;
  
  iVar2 = 0;
  for (; param_2 != 0; param_2 = param_2 + -1) {
    pbVar1 = (byte *)(param_3 + iVar2);
    iVar2 = iVar2 + 4;
    *param_1 = ((uint)pbVar1[2] | (uint)*pbVar1 << 0x10) << 8 | (uint)pbVar1[1] << 0x10 |
               (uint)pbVar1[3];
    param_1 = param_1 + 1;
  }
  return 0;
}



// ============================================================
// Function: xtra_processDHParams (FUN_6810c0d0)
// Address: 6810c0d0
// Size: 118 bytes
// Params: int param_1, int param_2, int param_3, int * param_4, uint param_5, int * param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_processDHParams(int param_1,int param_2,int param_3,int *param_4,uint param_5,int *param_6)

{
  undefined4 *puVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  size_t sVar5;
  uint uVar6;
  
  uVar6 = 0;
  if (param_5 != 0) {
    do {
      puVar1 = (undefined4 *)((*param_4 - param_3) + param_2);
      sVar5 = puVar1[1];
      piVar2 = (int *)((*param_4 - param_3) + param_1);
      for (pcVar3 = (char *)*puVar1; (sVar5 != 0 && (*pcVar3 == '\0')); pcVar3 = pcVar3 + 1) {
        sVar5 = sVar5 - 1;
      }
      piVar2[1] = sVar5;
      iVar4 = xtra_copyCertData(param_6,piVar2,pcVar3,sVar5);
      if (iVar4 != 0) {
        return iVar4;
      }
      param_4 = param_4 + 1;
      uVar6 = uVar6 + 1;
    } while (uVar6 < param_5);
  }
  return 0;
}



// ============================================================
// Function: xtra_decodeDHKeyParams (FUN_6810c150)
// Address: 6810c150
// Size: 309 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5, undefined4 * param_6, undefined4 * param_7
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_decodeDHKeyParams(int *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,
            undefined4 *param_5,undefined4 *param_6,undefined4 *param_7)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *local_4;
  
  iVar2 = xtra_readCertBlock(param_1,(int *)&local_4,0x40);
  if (iVar2 == 0) {
    display_fillMemory(local_4,0,0x40);
    if (param_2 != (undefined4 *)0x0) {
      uVar1 = param_2[1];
      *local_4 = *param_2;
      local_4[1] = uVar1;
    }
    if (param_5 != (undefined4 *)0x0) {
      uVar1 = param_5[1];
      local_4[6] = *param_5;
      local_4[7] = uVar1;
      uVar1 = param_5[3];
      local_4[8] = param_5[2];
      local_4[9] = uVar1;
    }
    if (param_6 != (undefined4 *)0x0) {
      uVar1 = param_6[1];
      local_4[10] = *param_6;
      local_4[0xb] = uVar1;
      uVar1 = param_6[3];
      local_4[0xc] = param_6[2];
      local_4[0xd] = uVar1;
    }
    if (param_7 != (undefined4 *)0x0) {
      uVar1 = param_7[1];
      local_4[0xe] = *param_7;
      local_4[0xf] = uVar1;
    }
    if (param_3 == (undefined4 *)0x0) {
      iVar2 = xtra_computeDHSharedKey((int)local_4,param_1);
      if (iVar2 != 0) {
        return 0;
      }
    }
    else {
      uVar1 = param_3[1];
      local_4[2] = *param_3;
      local_4[3] = uVar1;
    }
    if (param_4 == (undefined4 *)0x0) {
      iVar2 = xtra_computeDHKeyPair((int)local_4,param_1);
      if (iVar2 != 0) {
        return 0;
      }
    }
    else {
      uVar1 = param_4[1];
      local_4[4] = *param_4;
      local_4[5] = uVar1;
    }
    xtra_writeCertBlock(param_1,&PTR_LAB_681900e0,local_4);
  }
  return 0;
}



// ============================================================
// Function: xtra_encodeDHKeyParams (FUN_6810c290)
// Address: 6810c290
// Size: 335 bytes
// Params: int * param_1, int * param_2, int * param_3, int * param_4, int * param_5, int * param_6, int * param_7
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_encodeDHKeyParams(int *param_1,int *param_2,int *param_3,int *param_4,int *param_5,int *param_6,
            int *param_7)

{
  int iVar1;
  int *local_4;
  
  iVar1 = xtra_readCertChain(param_7,(int *)&local_4,0x681900e0);
  if (iVar1 == 0) {
    if (param_1 != (int *)0x0) {
      if (*local_4 == 0) {
        return 0x21e;
      }
      iVar1 = local_4[1];
      *param_1 = *local_4;
      param_1[1] = iVar1;
    }
    if (param_2 != (int *)0x0) {
      if (local_4[2] == 0) {
        return 0x21e;
      }
      iVar1 = local_4[3];
      *param_2 = local_4[2];
      param_2[1] = iVar1;
    }
    if (param_3 != (int *)0x0) {
      if (local_4[4] == 0) {
        return 0x21e;
      }
      iVar1 = local_4[5];
      *param_3 = local_4[4];
      param_3[1] = iVar1;
    }
    if (param_4 != (int *)0x0) {
      if (local_4[6] == 0) {
        return 0x21e;
      }
      if (local_4[8] == 0) {
        return 0x21e;
      }
      iVar1 = local_4[7];
      *param_4 = local_4[6];
      param_4[1] = iVar1;
      iVar1 = local_4[9];
      param_4[2] = local_4[8];
      param_4[3] = iVar1;
    }
    if (param_5 != (int *)0x0) {
      if (local_4[10] == 0) {
        return 0x21e;
      }
      if (local_4[0xc] == 0) {
        return 0x21e;
      }
      iVar1 = local_4[0xb];
      *param_5 = local_4[10];
      param_5[1] = iVar1;
      iVar1 = local_4[0xd];
      param_5[2] = local_4[0xc];
      param_5[3] = iVar1;
    }
    if (param_6 != (int *)0x0) {
      if (local_4[0xe] == 0) {
        return 0x21e;
      }
      iVar1 = local_4[0xf];
      *param_6 = local_4[0xe];
      param_6[1] = iVar1;
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_getCryptoState (FUN_6810c3f0)
// Address: 6810c3f0
// Size: 82 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_getCryptoState(undefined4 param_1)

{
  switch(param_1) {
  case 0x100:
    return 0x80;
  case 0x101:
  case 0x102:
  case 0x103:
  case 0x104:
    return 5;
  case 0x105:
    return 5;
  case 0x106:
    return 5;
  case 0x107:
    return 7;
  case 0x108:
    return 5;
  case 0x109:
    return 5;
  case 0x10a:
    return 5;
  case 0x10b:
    return 5;
  case 0x10c:
    param_1 = 10;
  }
  return param_1;
}



// ============================================================
// Function: xtra_destroyCryptoKey (FUN_6810c480)
// Address: 6810c480
// Size: 49 bytes
// Params: int param_1
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_destroyCryptoKey(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 8) == 0) {
    return 0;
  }
  iVar2 = 1;
  uVar1 = *(uint *)(*(int *)(param_1 + 8) + -4 + *(int *)(param_1 + 4) * 4);
  while (uVar1 = uVar1 >> 1, uVar1 != 0) {
    iVar2 = iVar2 + 1;
  }
  return (*(int *)(param_1 + 4) + -1) * 0x20 + iVar2;
}



// ============================================================
// Function: xtra_initCryptoKey (FUN_6810c4c0)
// Address: 6810c4c0
// Size: 233 bytes
// Params: int param_1, uint param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initCryptoKey(int param_1,uint param_2,int *param_3)

{
  int iVar1;
  char cVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  byte *pbVar7;
  uint uVar8;
  int iVar9;
  
  uVar3 = param_2 >> 2;
  uVar6 = param_2 + 3 >> 2;
  if (((int)uVar6 <= *param_3) || (iVar4 = xtra_growCryptoBuffer(uVar6 + 1,param_3), iVar4 == 0)) {
    puVar5 = (uint *)param_3[2];
    param_3[1] = uVar6;
    pbVar7 = (byte *)(param_1 + -1 + param_2);
    for (uVar6 = uVar3; uVar6 != 0; uVar6 = uVar6 - 1) {
      uVar8 = 1;
      *puVar5 = (uint)*pbVar7;
      do {
        cVar2 = (char)uVar8;
        iVar4 = -uVar8;
        uVar8 = uVar8 + 1;
        *puVar5 = *puVar5 | (uint)pbVar7[iVar4] << (cVar2 * '\b' & 0x1fU);
      } while (uVar8 < 4);
      pbVar7 = pbVar7 + -4;
      puVar5 = puVar5 + 1;
    }
    if ((int)(uVar3 * 4) < (int)param_2) {
      iVar4 = 1;
      iVar9 = param_2 + uVar3 * -4;
      *puVar5 = (uint)*pbVar7;
      if (1 < iVar9) {
        do {
          cVar2 = (char)iVar4;
          iVar1 = -iVar4;
          iVar4 = iVar4 + 1;
          *puVar5 = *puVar5 | (uint)pbVar7[iVar1] << (cVar2 * '\b' & 0x1fU);
        } while (iVar4 < iVar9);
      }
    }
    iVar4 = *(int *)(param_3[2] + -4 + param_3[1] * 4);
    while ((iVar4 == 0 && (1 < param_3[1]))) {
      iVar4 = param_3[1] + -1;
      param_3[1] = iVar4;
      iVar4 = *(int *)(param_3[2] + -4 + iVar4 * 4);
    }
    iVar4 = 0;
  }
  return iVar4;
}



// ============================================================
// Function: xtra_convertBignumToBytes (FUN_6810c5b0)
// Address: 6810c5b0
// Size: 182 bytes
// Params: int param_1, uint param_2, uint param_3, uint * param_4, char * param_5
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_convertBignumToBytes(int param_1,uint param_2,uint param_3,uint *param_4,char *param_5)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  char *pcVar6;
  uint local_4;
  
  if (param_3 < param_2) {
    return 0x10c;
  }
  iVar1 = xtra_destroyCryptoKey(param_1);
  local_4 = (int)(iVar1 + 7 + (iVar1 + 7 >> 0x1f & 7U)) >> 3;
  if (local_4 <= param_2) {
    if (param_2 <= local_4) {
      uVar2 = xtra_initCryptoBuffer(param_1,param_3,param_4,param_5);
      return uVar2;
    }
    uVar5 = param_2 - local_4;
    uVar3 = 0;
    if (0 < (int)uVar5) {
      pcVar6 = param_5;
      for (uVar3 = uVar5 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
        pcVar6[0] = '\0';
        pcVar6[1] = '\0';
        pcVar6[2] = '\0';
        pcVar6[3] = '\0';
        pcVar6 = pcVar6 + 4;
      }
      for (uVar4 = uVar5 & 3; uVar3 = uVar5, uVar4 != 0; uVar4 = uVar4 - 1) {
        *pcVar6 = '\0';
        pcVar6 = pcVar6 + 1;
      }
    }
    *param_4 = param_2;
    uVar2 = xtra_initCryptoBuffer(param_1,param_3,&local_4,param_5 + uVar3);
    return uVar2;
  }
  return 0x10c;
}



// ============================================================
// Function: xtra_initCryptoBuffer (FUN_6810c670)
// Address: 6810c670
// Size: 210 bytes
// Params: int param_1, uint param_2, uint * param_3, char * param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_initCryptoBuffer(int param_1,uint param_2,uint *param_3,char *param_4)

{
  char *pcVar1;
  char *pcVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  char cVar6;
  uint uVar7;
  int iVar8;
  uint *puVar9;
  
  iVar5 = *(int *)(param_1 + 4);
  *param_3 = iVar5 * 4;
  iVar8 = 3;
  puVar9 = (uint *)(*(int *)(param_1 + 8) + -4 + iVar5 * 4);
  bVar3 = 0x18;
  uVar4 = *puVar9;
  uVar7 = uVar4 >> 0x18;
  do {
    cVar6 = (char)uVar7;
    if (cVar6 != '\0') goto LAB_6810c6e5;
    iVar8 = iVar8 + -1;
    bVar3 = bVar3 - 8;
    *param_3 = *param_3 - 1;
    uVar7 = uVar4 >> (bVar3 & 0x1f);
    cVar6 = (char)uVar7;
  } while (0 < iVar8);
  if (cVar6 == '\0') {
    if (*param_3 != 1) {
      return 0x104;
    }
    if (param_2 == 0) {
      return 0x105;
    }
    *param_4 = '\0';
    return 0;
  }
LAB_6810c6e5:
  if (param_2 < *param_3) {
    return 0x105;
  }
  *param_4 = cVar6;
  pcVar1 = param_4 + 1;
  iVar8 = iVar8 + -1;
  if (-1 < iVar8) {
    uVar7 = iVar8 * 8;
    pcVar2 = pcVar1;
    do {
      pcVar1 = pcVar2 + 1;
      bVar3 = (byte)uVar7;
      uVar7 = (uint)(byte)(bVar3 - 8);
      *pcVar2 = (char)(uVar4 >> (bVar3 & 0x1f));
      iVar8 = iVar8 + -1;
      pcVar2 = pcVar1;
    } while (-1 < iVar8);
  }
  if (1 < iVar5) {
    iVar5 = iVar5 + -1;
    do {
      puVar9 = puVar9 + -1;
      uVar4 = *puVar9;
      iVar8 = 3;
      do {
        pcVar1[iVar8] = (char)uVar4;
        uVar4 = uVar4 >> 8;
        iVar8 = iVar8 + -1;
      } while (-1 < iVar8);
      pcVar1 = pcVar1 + 4;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  return 0;
}



// ============================================================
// Function: xtra_clearContext (FUN_6810c750)
// Address: 6810c750
// Size: 15 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_clearContext(undefined4 *param_1)
{
  *param_1 = 0;
  param_1[1] = 0;
  param_1[2] = 0;
  return 0;
}



// ============================================================
// Function: xtra_freeContext (FUN_6810c760)
// Address: 6810c760
// Size: 63 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freeContext(int *param_1)
{
  if ((void *)param_1[2] != (void *)0x0) {
    display_fillMemory((void *)param_1[2],0,*param_1 << 2);
    display_freeIfNonNull(param_1[2]);
    param_1[2] = 0;
  }
  param_1[1] = 0;
  *param_1 = 0;
  return 0;
}



// ============================================================
// Function: xtra_getCryptoKeyData (FUN_6810c7a0)
// Address: 6810c7a0
// Size: 212 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_getCryptoKeyData(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 <= *param_2) {
    return 0;
  }
  if (param_2[2] == 0) {
    *param_2 = param_1;
    iVar1 = display_allocBlock(param_1 * 4);
    param_2[2] = iVar1;
    if (iVar1 != 0) {
      return 0;
    }
    *param_2 = 0;
    return 0x100;
  }
  iVar1 = display_allocBlock(param_1 * 4);
  if (iVar1 != 0) {
    display_checkAndFree(iVar1,param_2[2],param_2[1] << 2);
    display_fillMemory((void *)param_2[2],0,*param_2 << 2);
    display_freeIfNonNull(param_2[2]);
    *param_2 = param_1;
    param_2[2] = iVar1;
    return 0;
  }
  display_fillMemory((void *)param_2[2],0,*param_2 << 2);
  display_freeIfNonNull(param_2[2]);
  param_2[1] = 0;
  *param_2 = 0;
  param_2[2] = 0;
  return 0x100;
}



// ============================================================
// Function: xtra_growCryptoBuffer (FUN_6810c880)
// Address: 6810c880
// Size: 197 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_growCryptoBuffer(int param_1,int *param_2)

{
  int iVar1;
  
  if (param_1 <= *param_2) {
    return 0;
  }
  if (param_2[2] == 0) {
    *param_2 = param_1;
    iVar1 = display_allocBlock(param_1 * 4);
    param_2[2] = iVar1;
    if (iVar1 != 0) {
      return 0;
    }
    *param_2 = 0;
    return 0x100;
  }
  iVar1 = display_allocBlock(param_1 * 4);
  if (iVar1 != 0) {
    display_fillMemory((void *)param_2[2],0,*param_2 << 2);
    display_freeIfNonNull(param_2[2]);
    *param_2 = param_1;
    param_2[2] = iVar1;
    param_2[1] = 0;
    return 0;
  }
  display_fillMemory((void *)param_2[2],0,*param_2 << 2);
  display_freeIfNonNull(param_2[2]);
  param_2[1] = 0;
  *param_2 = 0;
  param_2[2] = 0;
  return 0x100;
}



// ============================================================
// Function: xtra_performRSAOperation (FUN_6810c950)
// Address: 6810c950
// Size: 638 bytes
// Params: int param_1, int param_2, int * param_3, int * param_4, undefined4 * param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_performRSAOperation(int param_1,int param_2,int *param_3,int *param_4,undefined4 *param_5)

{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined3 extraout_var_00;
  int iVar5;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c [3];
  
  local_10 = 0;
  local_14 = 0;
  xtra_clearContext(local_c);
  bVar1 = xtra_checkCryptoCallback(param_5);
  iVar2 = CONCAT31(extraout_var,bVar1);
  if ((iVar2 == 0) && (iVar2 = xtra_computeModInverse((int)param_3,&local_18), iVar2 == 0)) {
    local_1c = xtra_destroyCryptoKey(param_2);
    uVar3 = xtra_getBERHeaderSize(local_1c);
    local_1c = local_1c - 1;
    iVar2 = xtra_parseBERTLV(uVar3,param_3,local_18,param_1,&local_14,&local_10,param_5);
    local_c[0] = uVar3;
    if ((iVar2 == 0) &&
       (((uVar4 = xtra_encodeBERLength(param_2,&local_1c,uVar3), *(int *)(local_14 + uVar4 * 4) != 0 ||
         (iVar2 = xtra_encodeBERTLV((int)param_3,local_18,uVar4,local_14,local_10), iVar2 == 0)) &&
        (iVar2 = xtra_decryptBlock(uVar4 * 0xc + local_10,param_4), iVar2 == 0)))) {
      do {
        do {
          if ((int)local_1c < 0) goto LAB_6810cb6c;
          bVar1 = xtra_checkCryptoCallback(param_5);
          iVar2 = CONCAT31(extraout_var_00,bVar1);
          if (iVar2 != 0) goto LAB_6810cba4;
          iVar5 = 1;
          uVar4 = local_1c + 1;
          if ((int)uVar3 <= (int)(local_1c + 1)) {
            uVar4 = uVar3;
          }
          if (0 < (int)uVar4) {
            do {
              iVar2 = xtra_squareAndReduceMod((int)param_4,(int)param_3,local_18,local_c);
              if ((iVar2 != 0) || (iVar2 = xtra_decryptBlock((int)local_c,param_4), iVar2 != 0))
              goto LAB_6810cb6c;
              iVar5 = iVar5 + 1;
              uVar4 = local_1c + 1;
              if ((int)uVar3 <= (int)(local_1c + 1)) {
                uVar4 = uVar3;
              }
            } while (iVar5 <= (int)uVar4);
          }
          if (iVar2 != 0) goto LAB_6810cba4;
          uVar4 = xtra_encodeBERLength(param_2,&local_1c,uVar3);
        } while (uVar4 == 0);
        if (((*(int *)(local_14 + uVar4 * 4) == 0) &&
            (iVar2 = xtra_encodeBERTLV((int)param_3,local_18,uVar4,local_14,local_10), iVar2 != 0)) ||
           (iVar2 = xtra_initCryptoSession(uVar4 * 0xc + local_10,(int)param_4,(int)param_3,local_18,local_c),
           iVar2 != 0)) goto LAB_6810cba4;
        iVar2 = xtra_decryptBlock((int)local_c,param_4);
      } while (iVar2 == 0);
LAB_6810cb6c:
      if ((iVar2 == 0) &&
         (iVar2 = xtra_modExp((int)param_4,(int)param_3,local_18,local_c), iVar2 == 0)) {
        iVar2 = xtra_decryptBlock((int)local_c,param_4);
      }
    }
  }
LAB_6810cba4:
  xtra_writeBERTLVHeader((byte)local_c[0],&local_14,&local_10);
  xtra_freeContext((int *)local_c);
  return iVar2;
}



// ============================================================
// Function: xtra_insertBitValue (FUN_6810cbd0)
// Address: 6810cbd0
// Size: 34 bytes
// Params: uint param_1, char param_2, byte param_3
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_insertBitValue(uint param_1,char param_2,byte param_3)

{
  return param_1 >> ((param_2 - param_3) + 1 & 0x1f) & ~(-1 << (param_3 & 0x1f));
}



// ============================================================
// Function: xtra_encodeBERLength (FUN_6810cc00)
// Address: 6810cc00
// Size: 141 bytes
// Params: int param_1, uint * param_2, int param_3
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_encodeBERLength(int param_1,uint *param_2,int param_3)

{
  byte bVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  uint uVar5;
  
  uVar2 = *param_2;
  iVar4 = uVar2 + 1;
  if (param_3 <= (int)(uVar2 + 1)) {
    iVar4 = param_3;
  }
  uVar5 = uVar2 >> 5;
  *param_2 = uVar2 - iVar4;
  bVar1 = (byte)iVar4;
  cVar3 = (char)(uVar2 & 0x1f);
  if (iVar4 + -1 <= (int)(uVar2 & 0x1f)) {
    uVar2 = xtra_insertBitValue(*(uint *)(*(int *)(param_1 + 8) + uVar5 * 4),cVar3,bVar1);
    return uVar2;
  }
  uVar2 = xtra_insertBitValue(*(uint *)(*(int *)(param_1 + 8) + uVar5 * 4),cVar3,cVar3 + 1);
  uVar5 = xtra_insertBitValue(*(uint *)(*(int *)(param_1 + 8) + -4 + uVar5 * 4),'\x1f',(bVar1 - cVar3) - 1)
  ;
  return uVar2 << ((bVar1 - cVar3) - 1 & 0x1f) | uVar5;
}



// ============================================================
// Function: xtra_decodeBERTagByte (FUN_6810cc90)
// Address: 6810cc90
// Size: 33 bytes
// Params: uint param_1
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_decodeBERTagByte(uint param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = 1;
    while (param_1 = param_1 >> 1, param_1 != 0) {
      iVar1 = iVar1 * 2;
    }
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: xtra_getBERHeaderSize (FUN_6810ccc0)
// Address: 6810ccc0
// Size: 42 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_getBERHeaderSize(int param_1)

{
  undefined4 uVar1;
  
  if (0x3f < param_1) {
    return 4;
  }
  if (0xf < param_1) {
    return 3;
  }
  uVar1 = 2;
  if (param_1 < 4) {
    uVar1 = 1;
  }
  return uVar1;
}



// ============================================================
// Function: xtra_parseBERTLV (FUN_6810ccf0)
// Address: 6810ccf0
// Size: 414 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, int * param_5, int * param_6, undefined4 * param_7
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_parseBERTLV(int param_1,int *param_2,int param_3,int param_4,int *param_5,int *param_6,
            undefined4 *param_7)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  int local_c [2];
  undefined4 *local_4;
  
  if ((*param_5 != 0) || (*param_6 != 0)) {
    return 0x104;
  }
  iVar5 = 1 << ((byte)param_1 & 0x1f);
  xtra_clearContext(local_c);
  iVar2 = display_allocBlock(iVar5 * 4);
  *param_5 = iVar2;
  if (iVar2 == 0) {
    iVar2 = 0x100;
  }
  else {
    iVar2 = display_allocBlock(iVar5 * 0xc);
    *param_6 = iVar2;
    if (iVar2 == 0) {
      iVar2 = 0x100;
    }
    else {
      iVar2 = 0;
      if (0 < iVar5) {
        iVar4 = 0;
        do {
          *(undefined4 *)(*param_5 + iVar4) = 0;
          iVar4 = iVar4 + 4;
          puVar3 = (undefined4 *)(*param_6 + iVar2);
          iVar2 = iVar2 + 0xc;
          xtra_clearContext(puVar3);
          iVar5 = iVar5 + -1;
        } while (iVar5 != 0);
      }
      iVar5 = 1;
      iVar2 = xtra_growCryptoBuffer(1,local_c);
      if (iVar2 == 0) {
        local_c[1] = 1;
        *local_4 = 1;
        iVar2 = xtra_modReduce((int)local_c,param_2,(int *)*param_6);
        if (iVar2 == 0) {
          *(undefined4 *)*param_5 = 1;
          iVar2 = xtra_modReduce(param_4,param_2,(int *)(*param_6 + 0xc));
          if (iVar2 == 0) {
            *(undefined4 *)(*param_5 + 4) = 1;
            bVar1 = xtra_checkCryptoCallback(param_7);
            iVar2 = CONCAT31(extraout_var,bVar1);
            if ((iVar2 == 0) && (iVar4 = 1, 1 < param_1)) {
              do {
                iVar2 = xtra_squareAndReduceMod(*param_6 + iVar4 * 0xc,(int)param_2,param_3,
                                     (uint *)(*param_6 + iVar4 * 0x18));
                if (iVar2 != 0) break;
                iVar5 = iVar5 + 1;
                *(undefined4 *)(*param_5 + iVar4 * 8) = 1;
                iVar4 = iVar4 * 2;
              } while (iVar5 < param_1);
            }
          }
        }
      }
    }
  }
  xtra_freeContext(local_c);
  return iVar2;
}



// ============================================================
// Function: xtra_writeBERTLVHeader (FUN_6810ce90)
// Address: 6810ce90
// Size: 139 bytes
// Params: byte param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_writeBERTLVHeader(byte param_1,int *param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 1 << (param_1 & 0x1f);
  if ((void *)*param_2 != (void *)0x0) {
    display_fillMemory((void *)*param_2,0,iVar4 * 4);
    display_freeIfNonNull(*param_2);
    *param_2 = 0;
  }
  if (*param_3 != 0) {
    if (0 < iVar4) {
      iVar3 = 0;
      iVar2 = iVar4;
      do {
        piVar1 = (int *)(*param_3 + iVar3);
        iVar3 = iVar3 + 0xc;
        xtra_freeContext(piVar1);
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
    }
    display_fillMemory((void *)*param_3,0,iVar4 * 0xc);
    display_freeIfNonNull(*param_3);
    *param_3 = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_encodeBERTLV (FUN_6810cf20)
// Address: 6810cf20
// Size: 390 bytes
// Params: int param_1, int param_2, uint param_3, int param_4, int param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_encodeBERTLV(int param_1,int param_2,uint param_3,int param_4,int param_5)

{
  uint *puVar1;
  int *piVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint local_8;
  
  local_8 = 0;
  *(undefined4 *)(param_4 + param_3 * 4) = 1;
  puVar1 = (uint *)(param_5 + param_3 * 0xc);
  uVar7 = 1;
  uVar4 = xtra_decodeBERTagByte(param_3);
  uVar6 = param_3;
  do {
    if (uVar6 == 0) {
      return 0;
    }
    for (; uVar7 <= uVar6 >> 1; uVar7 = uVar7 + 1) {
      if ((*(int *)(param_4 + uVar7 * 4) != 0) && (*(int *)(param_4 + (uVar6 - uVar7) * 4) != 0)) {
        *(undefined4 *)(param_4 + uVar6 * 4) = 1;
        if (param_3 == uVar6) {
          iVar5 = xtra_initCryptoSession(param_5 + uVar7 * 0xc,param_5 + (uVar6 - uVar7) * 0xc,param_1,param_2
                               ,puVar1);
          return iVar5;
        }
        puVar3 = (uint *)(param_5 + uVar6 * 0xc);
        iVar5 = xtra_initCryptoSession(param_5 + uVar7 * 0xc,param_5 + (uVar6 - uVar7) * 0xc,param_1,param_2,
                             puVar3);
        if (iVar5 != 0) {
          return iVar5;
        }
        iVar5 = xtra_initCryptoSession((int)puVar3,param_5 + local_8 * 0xc,param_1,param_2,puVar1);
        return iVar5;
      }
    }
    if (param_3 != uVar6) {
      piVar2 = (int *)(param_4 + (local_8 | uVar4) * 4);
      if (*piVar2 == 0) {
        *piVar2 = 1;
        iVar5 = xtra_initCryptoSession(param_5 + uVar4 * 0xc,param_5 + local_8 * 0xc,param_1,param_2,
                             (uint *)(param_5 + (local_8 | uVar4) * 0xc));
        if (iVar5 != 0) {
          return iVar5;
        }
      }
    }
    uVar7 = 0;
    local_8 = local_8 | uVar4;
    uVar6 = uVar6 & ~uVar4;
    uVar4 = xtra_decodeBERTagByte(uVar6);
  } while( true );
}



// ============================================================
// Function: xtra_storeCryptoSessionData (FUN_6810d100)
// Address: 6810d100
// Size: 50 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_storeCryptoSessionData(undefined4 param_1,int param_2,undefined4 param_3)

{
  if ((*(byte *)(param_2 + 0x18) & 2) == 0) {
    return 0x203;
  }
  display_checkAndFree(*(int *)(param_2 + 0x14) + 0x2c,param_3,8);
  *(int *)(*(int *)(param_2 + 0x14) + 0x28) = param_2;
  return 0;
}



// ============================================================
// Function: xtra_processCryptoOp (FUN_6810d140)
// Address: 6810d140
// Size: 329 bytes
// Params: uint * param_1, uint * param_2, int * param_3, undefined4 * param_4, byte * param_5, uint param_6
// Return: byte
// Calling convention: __cdecl
// ============================================================

byte __cdecl
xtra_processCryptoOp(uint *param_1,uint *param_2,int *param_3,undefined4 *param_4,byte *param_5,uint param_6
            )

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  byte *pbVar4;
  
  if (param_6 == 0) {
    return 6;
  }
  *param_2 = (uint)*param_5;
  *param_3 = 0;
  if (((byte)*param_2 & 0x1f) == 0x1f) {
    do {
      iVar3 = *param_3;
      if (param_6 < iVar3 + 2U) {
        return 6;
      }
      *param_3 = iVar3 + 1;
    } while ((param_5[iVar3 + 1] & 0x80) != 0);
  }
  iVar3 = *param_3;
  if (param_6 < iVar3 + 2U) {
    return 6;
  }
  pbVar4 = param_5 + iVar3 + 1;
  bVar1 = *pbVar4;
  if (bVar1 < 0x80) {
    pbVar4 = pbVar4 + 1;
    param_4[1] = (uint)bVar1;
    *param_1 = *param_3 + (uint)bVar1 + 2;
  }
  else {
    if (bVar1 == 0x80) {
      if ((*param_2 & 0x20) == 0) {
        return 5;
      }
      *param_4 = pbVar4 + 1;
      param_4[1] = 0;
      *param_1 = 0;
      goto LAB_6810d273;
    }
    if (bVar1 == 0x81) {
      if (param_6 < iVar3 + 3U) {
        return 6;
      }
      bVar1 = pbVar4[1];
      pbVar4 = pbVar4 + 2;
      param_4[1] = (uint)bVar1;
      *param_1 = *param_3 + (uint)bVar1 + 3;
    }
    else {
      if (bVar1 != 0x82) {
        return 5;
      }
      if (param_6 < iVar3 + 4U) {
        return 6;
      }
      bVar1 = pbVar4[1];
      bVar2 = pbVar4[2];
      pbVar4 = pbVar4 + 3;
      param_4[1] = (uint)CONCAT11(bVar1,bVar2);
      *param_1 = *param_3 + (uint)CONCAT11(bVar1,bVar2) + 4;
    }
  }
  *param_4 = pbVar4;
LAB_6810d273:
  return -(param_6 < *param_1) & 6;
}



// ============================================================
// Function: xtra_processCryptoData (FUN_6810d290)
// Address: 6810d290
// Size: 203 bytes
// Params: byte * param_1, uint * param_2, uint param_3, byte param_4, byte * param_5, int param_6, uint param_7
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_processCryptoData(byte *param_1,uint *param_2,uint param_3,byte param_4,byte *param_5,int param_6,
            uint param_7)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  
  iVar4 = 0;
  if ((param_4 & 0x1f) == 0x1f) {
    bVar1 = *param_5;
    while ((bVar1 & 0x80) != 0) {
      iVar4 = iVar4 + 1;
      bVar1 = param_5[iVar4];
    }
    iVar4 = iVar4 + 1;
  }
  uVar2 = 1;
  if (0x7f < param_7) {
    uVar2 = (uint)(byte)((0xff < param_7) + 2);
  }
  uVar2 = uVar2 + 1 + iVar4;
  *param_2 = uVar2;
  if (param_6 != 0) {
    *param_2 = uVar2 + param_7;
  }
  if (param_1 != (byte *)0x0) {
    if (*param_2 <= param_3) {
      pbVar3 = param_1 + 1;
      *param_1 = param_4;
      if ((param_4 & 0x1f) == 0x1f) {
        display_checkAndFree(pbVar3,param_5,iVar4);
        pbVar3 = pbVar3 + iVar4;
      }
      if (0x7f < param_7) {
        if (param_7 < 0x100) {
          *pbVar3 = 0x81;
        }
        else {
          *pbVar3 = 0x82;
          pbVar3[1] = (byte)(param_7 >> 8);
          pbVar3 = pbVar3 + 1;
        }
        pbVar3 = pbVar3 + 1;
      }
      *pbVar3 = (byte)param_7;
      if (param_6 != 0) {
        display_checkAndFree(pbVar3 + 1,param_6,param_7);
      }
      return 0;
    }
    return 10;
  }
  return 0;
}



// ============================================================
// Function: xtra_readBERConstructed (FUN_6810d360)
// Address: 6810d360
// Size: 197 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readBERConstructed(int param_1,int *param_2,undefined4 *param_3)

{
  int local_8;
  int local_14;
  int local_c;
  int iVar1;
  int iVar2;
  uint uVar3;
  int local_4;
  
  if (*(int *)(param_1 + 4) == 0) {
    iVar1 = display_allocBlock(0x800);
    *(int *)(param_1 + 4) = iVar1;
    if (iVar1 == 0) {
      return 0x206;
    }
    *param_2 = iVar1 + 0x800;
    *(undefined4 *)(param_1 + 0x10) = 0x800;
    *(undefined4 *)(param_1 + 0xc) = 0x800;
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
      if (uVar3 < 0x800) {
        *(undefined4 *)(param_1 + 8) = 1;
      }
    }
  }
  *param_2 = *(int *)(param_1 + 4);
  *param_3 = *(undefined4 *)(param_1 + 0x10);
  return 0;
}



// ============================================================
// Function: xtra_readBERExplicitTag (FUN_6810d430)
// Address: 6810d430
// Size: 184 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readBERExplicitTag(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int local_4;
  
  if (*(int *)(param_1 + 0xc) == 32000) {
    return 0;
  }
  iVar1 = display_allocBlock(32000);
  if (iVar1 != 0) {
    display_checkAndFree(iVar1,*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 0x10));
    display_freeIfNonNull(*(int *)(param_1 + 4));
    *(int *)(param_1 + 4) = iVar1;
    *(undefined4 *)(param_1 + 0xc) = 32000;
    if (*(int *)(param_1 + 8) == 0) {
      iVar1 = (**(code **)(**(int **)(param_1 + 0x14) + 4))
                        (*(int **)(param_1 + 0x14),iVar1 + *(int *)(param_1 + 0x10),&local_4,
                         32000 - *(int *)(param_1 + 0x10));
      if (iVar1 != 0) {
        return iVar1;
      }
      uVar2 = *(int *)(param_1 + 0x10) + local_4;
      *(uint *)(param_1 + 0x10) = uVar2;
      if (uVar2 < *(uint *)(param_1 + 0xc)) {
        *(undefined4 *)(param_1 + 8) = 1;
      }
    }
    *param_2 = *(undefined4 *)(param_1 + 4);
    *param_3 = *(undefined4 *)(param_1 + 0x10);
    return 0;
  }
  return 0x206;
}



// ============================================================
// Function: xtra_readBEROptionalField (FUN_6810d5b0)
// Address: 6810d5b0
// Size: 141 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readBEROptionalField(int param_1,undefined4 param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  byte *local_1c;
  uint local_18;
  undefined1 local_14 [8];
  undefined1 local_c [4];
  byte **local_8;
  undefined1 *local_4;
  
  display_fillMemory(local_c,0,0xc);
  local_8 = &local_1c;
  local_4 = local_14;
  iVar1 = xtra_readCertField((uint *)0x0,(uint *)&DAT_68190130,(int)local_c,(byte *)*param_3,param_3[1]);
  if (iVar1 == 0) {
    if (*(uint *)(param_1 + 8) == local_18) {
      uVar2 = display_decodeFormat(local_1c,*(byte **)(param_1 + 4),local_18);
      if (uVar2 == 0) {
        iVar1 = (*(code *)**(undefined4 **)(param_1 + 0xc))(param_1,param_2,local_14);
        return iVar1;
      }
    }
    iVar1 = 0x21d;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_readBERSequenceItems (FUN_6810d660)
// Address: 6810d660
// Size: 165 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_readBERSequenceItems(int param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int local_14 [2];
  undefined1 auStack_c [4];
  int iStack_8;
  int *piStack_4;
  
  local_14[0] = 0;
  uVar1 = (**(code **)(*(int *)(param_1 + 0xc) + 4))(param_1,local_14,param_3);
  if (uVar1 == 0) {
    display_fillMemory(auStack_c,0,0xc);
    piStack_4 = local_14;
    iStack_8 = param_1 + 4;
    uVar1 = xtra_readCertBlock(param_3,param_2,8);
    if (uVar1 == 0) {
      uVar1 = xtra_writeBERSequence((undefined4 *)*param_2,(uint *)&DAT_68190130,(int)auStack_c);
      if (uVar1 == 0) {
        uVar1 = xtra_readCertBlockEx(param_3,(int *)*param_2,((int *)*param_2)[1]);
      }
    }
  }
  display_freeIfNonNull(local_14[0]);
  return uVar1;
}



// ============================================================
// Function: xtra_addBERAttributeValue (FUN_6810d740)
// Address: 6810d740
// Size: 105 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl xtra_addBERAttributeValue(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  if (param_1 == (undefined4 *)0x0) {
    param_1 = (undefined4 *)display_allocBlock(0xa8);
    if (param_1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  xtra_finalizeCryptoKey(param_1);
  xtra_allocCryptoContext(param_1 + 2,param_2,0);
  xtra_allocDSAContext(param_1 + 0xb);
  xtra_allocRSAContext(param_1 + 0x1a);
  param_1[0x29] = param_3;
  param_1[1] = &PTR_FUN_68190170;
  return param_1;
}



// ============================================================
// Function: xtra_freeBERAttributeStore (FUN_6810d7b0)
// Address: 6810d7b0
// Size: 43 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freeBERAttributeStore(int param_1)
{
  xtra_destroySymKeyBuffer(param_1 + 8);
  xtra_destroyKeyContext(param_1 + 0x2c);
  xtra_destroyKeyContext(param_1 + 0x68);
  return 0;
}



// ============================================================
// Function: xtra_initBERAttributeWriter (FUN_6810db20)
// Address: 6810db20
// Size: 38 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_initBERAttributeWriter(undefined4 *param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4)
{
  param_1[1] = param_2;
  param_1[3] = param_4;
  param_1[2] = param_3;
  *param_3 = 0;
  *param_1 = &PTR_LAB_68190190;
  return 0;
}



// ============================================================
// Function: xtra_writeBERAttributeSet (FUN_6810db50)
// Address: 6810db50
// Size: 95 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 param_3, uint * param_4, int param_5
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl
xtra_writeBERAttributeSet(undefined4 param_1,undefined4 *param_2,undefined4 param_3,uint *param_4,int param_5)

{
  uint uVar1;
  undefined4 local_34 [4];
  int local_24 [9];
  
  xtra_initBERAttributeWriter(local_34,param_1,param_2,param_3);
  xtra_initBEREncoder(local_24,local_34);
  uVar1 = xtra_parseBERField(local_24,param_4,param_5);
  xtra_freeBEREncoder(local_24);
  return uVar1;
}



// ============================================================
// Function: xtra_freeAttributeList (FUN_6810dbf0)
// Address: 6810dbf0
// Size: 44 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freeAttributeList(int param_1)
{
  xtra_removeAttributeByIndex(param_1,1);
  display_freeIfNonNull(*(int *)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = 0;
  *(undefined4 *)(param_1 + 0xc) = 0;
  return 0;
}



// ============================================================
// Function: xtra_getAttributeByIndex (FUN_6810dc20)
// Address: 6810dc20
// Size: 27 bytes
// Params: int param_1, uint param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_getAttributeByIndex(int param_1,uint param_2)

{
  if ((*(int *)(param_1 + 4) != 0) && (param_2 < *(uint *)(param_1 + 8))) {
    return *(undefined4 *)(*(int *)(param_1 + 4) + param_2 * 4);
  }
  return 0;
}



// ============================================================
// Function: xtra_setAttributeValue (FUN_6810dc40)
// Address: 6810dc40
// Size: 71 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_setAttributeValue(int param_1,undefined4 param_2,uint param_3)

{
  uint uVar1;
  
  if ((*(int *)(param_1 + 0xc) == *(int *)(param_1 + 8)) &&
     (uVar1 = xtra_growAttributeList(param_1,*(int *)(param_1 + 8) + 1), uVar1 != 0)) {
    return uVar1;
  }
  if (*(uint *)(param_1 + 8) < param_3) {
    param_3 = *(uint *)(param_1 + 8);
  }
  xtra_insertAttributeAtIndex(param_1,param_3,param_3 + 1);
  *(undefined4 *)(*(int *)(param_1 + 4) + param_3 * 4) = param_2;
  return param_3;
}



// ============================================================
// Function: xtra_addAttributeToList (FUN_6810dc90)
// Address: 6810dc90
// Size: 23 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_addAttributeToList(int param_1,undefined4 param_2)
{
  xtra_setAttributeValue(param_1,param_2,*(uint *)(param_1 + 8));
  return 0;
}



// ============================================================
// Function: xtra_removeAttributeByIndex (FUN_6810dcb0)
// Address: 6810dcb0
// Size: 76 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_removeAttributeByIndex(int param_1,int param_2)
{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (*(int *)(param_1 + 4) != 0) {
    if (*(int *)(param_1 + 8) != 0) {
      iVar2 = 0;
      do {
        if (param_2 != 0) {
          xtra_initObjectBlock((int *)(*(int *)(param_1 + 4) + iVar2));
        }
        iVar2 = iVar2 + 4;
        uVar1 = uVar1 + 1;
        *(undefined4 *)(*(int *)(param_1 + 4) + -4 + iVar2) = 0;
      } while (uVar1 < *(uint *)(param_1 + 8));
    }
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_growAttributeList (FUN_6810dd00)
// Address: 6810dd00
// Size: 135 bytes
// Params: int param_1, uint param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_growAttributeList(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  
  if (param_2 < *(uint *)(param_1 + 8)) {
    param_2 = *(uint *)(param_1 + 8);
  }
  uVar2 = param_2 + 7 & 0xfffffff8;
  if (*(uint *)(param_1 + 0xc) < uVar2) {
    iVar1 = display_allocBlock(uVar2 * 4);
    if (iVar1 == 0) {
      return 0xffff;
    }
    if (*(int *)(param_1 + 8) != 0) {
      display_checkAndFree(iVar1,*(undefined4 *)(param_1 + 4),*(int *)(param_1 + 8) << 2);
    }
    display_fillMemory((void *)(iVar1 + *(int *)(param_1 + 8) * 4),0,(uVar2 - *(int *)(param_1 + 8)) * 4);
    display_freeIfNonNull(*(int *)(param_1 + 4));
    *(int *)(param_1 + 4) = iVar1;
    *(uint *)(param_1 + 0xc) = uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_insertAttributeAtIndex (FUN_6810dd90)
// Address: 6810dd90
// Size: 80 bytes
// Params: int param_1, uint param_2, uint param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_insertAttributeAtIndex(int param_1,uint param_2,uint param_3)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8) - param_2;
  uVar2 = param_3;
  if (param_3 <= param_2) {
    uVar2 = param_2;
  }
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) && (uVar2 + iVar3 <= *(uint *)(param_1 + 0xc))) {
    if (iVar3 != 0) {
      display_allocFormatBlock(iVar1 + param_3 * 4,iVar1 + param_2 * 4,iVar3 * 4);
    }
    *(uint *)(param_1 + 8) = param_3 + iVar3;
  }
  return 0;
}



// ============================================================
// Function: xtra_createAttributeNode (FUN_6810dde0)
// Address: 6810dde0
// Size: 122 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, int param_4
// Return: undefined4 *
// Calling convention: __cdecl
// ============================================================

undefined4 * __cdecl
xtra_createAttributeNode(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != (undefined4 *)0x0) || (param_1 = xtra_allocZeroedBlock(0x28), param_1 != (undefined4 *)0x0)
     ) {
    iVar1 = param_4;
    *param_1 = &PTR_FUN_6819019c;
    iVar2 = xtra_allocAndCopyBlock(param_3,param_4);
    param_1[3] = iVar2;
    if (param_1[3] == 0) {
      xtra_initObjectBlock((int *)&param_1);
    }
    else {
      param_1[4] = iVar1;
      param_1[5] = param_2;
    }
  }
  return param_1;
}



// ============================================================
// Function: xtra_getAttributeCount (FUN_6810de60)
// Address: 6810de60
// Size: 65 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getAttributeCount(int param_1)
{
  if (param_1 != 0) {
    xtra_allocObjectBlock((int *)(param_1 + 0x18),*(size_t *)(param_1 + 0x1c));
    xtra_allocObjectBlock((int *)(param_1 + 0xc),*(size_t *)(param_1 + 0x10));
    if (*(int *)(param_1 + 0x24) == 0) {
      xtra_allocObjectBlock((int *)(param_1 + 4),*(size_t *)(param_1 + 8));
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_resetAttributeIterator (FUN_6810deb0)
// Address: 6810deb0
// Size: 23 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_resetAttributeIterator(int *param_1)
{
  xtra_writeBERBlock(param_1,(int *)0x0,0xc,0x68106b20);
  return 0;
}



// ============================================================
// Function: xtra_decryptBlockData (FUN_6810ded0)
// Address: 6810ded0
// Size: 155 bytes
// Params: undefined4 * param_1, byte * param_2, uint param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_decryptBlockData(undefined4 *param_1,byte *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  int *local_c;
  int local_8;
  size_t local_4;
  
  iVar1 = xtra_encodeBER(&local_c,param_1,0x68106b20);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x102,param_4);
    return iVar1;
  }
  iVar1 = xtra_readCertFieldEx(&local_8,(uint *)&DAT_681901a0,0,param_2,param_3);
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
// Function: xtra_copyBERContent (FUN_6810df70)
// Address: 6810df70
// Size: 133 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_copyBERContent(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int *local_8;
  int local_4;
  
  iVar1 = xtra_encodeBER(&local_8,param_1,0x68106b20);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x102,param_3);
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
// Function: xtra_readBEREnvelopedData (FUN_6810e000)
// Address: 6810e000
// Size: 104 bytes
// Params: undefined4 * param_1, int * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readBEREnvelopedData(undefined4 *param_1,int *param_2,undefined4 *param_3)

{
  int iVar1;
  byte *local_8;
  uint local_4;
  
  iVar1 = xtra_encodeBERRawEx(&local_8,*param_2,param_2[1],0x31);
  if (iVar1 == 0) {
    iVar1 = xtra_decryptBlockData(param_1,local_8,local_4,param_3);
    display_fillMemory(local_8,0,local_4);
    display_freeIfNonNull((int)local_8);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_writeBEREnvelopedData (FUN_6810e070)
// Address: 6810e070
// Size: 138 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_writeBEREnvelopedData(int *param_1,int *param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  int *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_3,0x68106b20);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x102,param_4);
    return iVar1;
  }
  if (*local_4 == 0) {
    if ((undefined4 *)local_4[2] == (undefined4 *)0x0) {
      return 0x102;
    }
    iVar1 = xtra_readCRLExtensions(local_4,(undefined4 *)local_4[2],(int)param_3,param_4);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  *param_1 = *local_4;
  *param_2 = local_4[1];
  return 0;
}



// ============================================================
// Function: xtra_extractBERSignedData (FUN_6810e100)
// Address: 6810e100
// Size: 59 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_extractBERSignedData(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  int local_8;
  int local_4;
  
  iVar1 = xtra_writeBEREnvelopedData(&local_8,&local_4,param_2,param_3);
  if (iVar1 == 0) {
    xtra_validateBERTagEx(param_1,0x31,&local_8);
  }
  return 0;
}



// ============================================================
// Function: xtra_buildCRLEntry (FUN_6810e140)
// Address: 6810e140
// Size: 72 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3, byte * param_4, uint param_5, uint param_6, undefined4 * param_7
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_buildCRLEntry(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3,byte *param_4,uint param_5,
            uint param_6,undefined4 *param_7)

{
  int iVar1;
  undefined4 *local_4;
  
  iVar1 = xtra_parseCRLDistributionPoint((int *)&local_4,param_3,param_4,param_5,param_6,param_7);
  if (iVar1 == 0) {
    *param_1 = *local_4;
    iVar1 = 0;
    *param_2 = local_4[1];
  }
  return iVar1;
}



// ============================================================
// Function: xtra_parseCRLEntry (FUN_6810e190)
// Address: 6810e190
// Size: 198 bytes
// Params: undefined4 * param_1, byte * param_2, uint param_3, uint * param_4, undefined4 * param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_parseCRLEntry(undefined4 *param_1,byte *param_2,uint param_3,uint *param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *local_c;
  int local_8;
  undefined4 *local_4;
  
  local_8 = xtra_openCryptoSession((int *)&local_4,param_1,1,param_5);
  if (local_8 == 0) {
    iVar1 = xtra_encodeBER(&local_c,local_4,0x68106b20);
    if (iVar1 != 0) {
      iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x102,param_5);
      return iVar1;
    }
    iVar1 = 0;
    uVar3 = 0;
    local_8 = 300;
    if (*local_c != 0) {
      do {
        if ((((undefined4 *)(local_c[1] + iVar1))[1] == param_3) &&
           (uVar2 = display_decodeFormat(*(byte **)(local_c[1] + iVar1),param_2,param_3), uVar2 == 0)) {
          if (param_4 == (uint *)0x0) {
            return 0;
          }
          *param_4 = uVar3;
          return 0;
        }
        iVar1 = iVar1 + 0x10;
        uVar3 = uVar3 + 1;
      } while (uVar3 < *local_c);
    }
  }
  return local_8;
}



// ============================================================
// Function: xtra_addCRLEntryToList (FUN_6810e260)
// Address: 6810e260
// Size: 239 bytes
// Params: undefined4 * param_1, byte * param_2, uint param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_addCRLEntryToList(undefined4 *param_1,byte *param_2,uint param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint local_c;
  uint *local_8;
  undefined4 *local_4;
  
  iVar1 = xtra_openCryptoSession((int *)&local_4,param_1,1,param_4);
  if (iVar1 == 0) {
    iVar1 = xtra_encodeBER(&local_8,local_4,0x68106b20);
    if (iVar1 != 0) {
      iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x102,param_4);
      return iVar1;
    }
    iVar1 = xtra_parseCRLEntry(param_1,param_2,param_3,&local_c,param_4);
    if (iVar1 == 300) {
      return 0;
    }
    *local_8 = *local_8 - 1;
    if (local_c < *local_8) {
      do {
        puVar2 = (undefined4 *)(local_8[1] + local_c * 0x10);
        *puVar2 = puVar2[4];
        puVar2[1] = puVar2[5];
        puVar2[2] = puVar2[6];
        puVar2[3] = puVar2[7];
        local_c = local_c + 1;
      } while (local_c < *local_8);
    }
    xtra_resetBERKeepChild(param_1,(int)local_4);
    iVar1 = xtra_attachCryptoToReader(param_1,local_4);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_encodeCRLAttributes (FUN_6810e350)
// Address: 6810e350
// Size: 236 bytes
// Params: undefined4 * param_1, byte * param_2, uint param_3, undefined4 param_4, int param_5, undefined4 * param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_encodeCRLAttributes(undefined4 *param_1,byte *param_2,uint param_3,undefined4 param_4,int param_5,
            undefined4 *param_6)
{
  int iVar1;
  undefined4 *local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar1 = xtra_openCryptoSession((int *)&local_10,param_1,1,param_6);
  if (iVar1 != 0) {
    return 0;
  }
  iVar1 = xtra_writeCRLExtensions(&local_c,local_10,param_2,param_3);
  if (iVar1 != 0) {
    if (iVar1 != 0x104) {
      return 0;
    }
    iVar1 = xtra_writeBERContent(&local_4,param_2,param_3,(int)local_10);
    if (iVar1 != 0) {
      return 0;
    }
    iVar1 = xtra_createSignedContent(&local_c,local_10,local_4,param_3);
    if (iVar1 != 0) {
      return 0;
    }
  }
  iVar1 = xtra_writeBERContent(&local_8,param_4,param_5,(int)local_10);
  if ((iVar1 == 0) && (iVar1 = xtra_finalizeSignedContent((int)local_10,local_c,local_8,param_5), iVar1 == 0)) {
    xtra_resetBERKeepChild(param_1,(int)local_10);
    xtra_attachCryptoToReader(param_1,local_10);
  }
  return 0;
}



// ============================================================
// Function: xtra_decodeCRLAttributes (FUN_6810e440)
// Address: 6810e440
// Size: 131 bytes
// Params: undefined4 * param_1, byte * param_2, uint param_3, int param_4, int param_5, uint param_6, undefined4 * param_7
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_decodeCRLAttributes(undefined4 *param_1,byte *param_2,uint param_3,int param_4,int param_5,uint param_6,
            undefined4 *param_7)

{
  int iVar1;
  void *local_8;
  size_t local_4;
  
  if (param_4 == 0x1f) {
    return 0x105;
  }
  iVar1 = xtra_encodeBERRawEx(&local_8,param_5,param_6,(byte)param_4);
  if (iVar1 == 0) {
    iVar1 = xtra_encodeCRLAttributes(param_1,param_2,param_3,local_8,local_4,param_7);
    display_fillMemory(local_8,0,local_4);
    display_freeIfNonNull((int)local_8);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_buildCRLDistributionPoint (FUN_6810e4d0)
// Address: 6810e4d0
// Size: 150 bytes
// Params: uint * param_1, undefined4 * param_2, undefined4 * param_3, undefined4 * param_4, byte * param_5, uint param_6, uint param_7, undefined4 * param_8
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_buildCRLDistributionPoint(uint *param_1,undefined4 *param_2,undefined4 *param_3,undefined4 *param_4,byte *param_5
            ,uint param_6,uint param_7,undefined4 *param_8)

{
  int iVar1;
  int local_18;
  uint local_14;
  byte *local_10;
  uint local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  iVar1 = xtra_buildCRLEntry(&local_10,&local_c,param_4,param_5,param_6,param_7,param_8);
  if (iVar1 == 0) {
    iVar1 = xtra_parseBERCryptoHeader(&local_14,param_1,&local_18,&local_8,local_10,local_c);
    if (iVar1 == 0) {
      if (local_14 == 0) {
        return 0x107;
      }
      if (local_18 != 0) {
        return 0x105;
      }
      *param_2 = local_8;
      iVar1 = 0;
      *param_3 = local_4;
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_parseCRLDistributionPoint (FUN_6810e570)
// Address: 6810e570
// Size: 111 bytes
// Params: int * param_1, undefined4 * param_2, byte * param_3, uint param_4, uint param_5, undefined4 * param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_parseCRLDistributionPoint(int *param_1,undefined4 *param_2,byte *param_3,uint param_4,uint param_5,
            undefined4 *param_6)

{
  int iVar1;
  int local_8;
  undefined4 *local_4;
  
  iVar1 = xtra_openCryptoSession((int *)&local_4,param_2,0,param_6);
  if (iVar1 == 0) {
    iVar1 = xtra_writeCRLExtensions(&local_8,local_4,param_3,param_4);
    if (iVar1 == 0) {
      if (*(uint *)(local_8 + 8) <= param_5) {
        return 0x11f;
      }
      iVar1 = 0;
      *param_1 = param_5 * 0xc + *(int *)(local_8 + 0xc);
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_openCryptoSession (FUN_6810e5e0)
// Address: 6810e5e0
// Size: 349 bytes
// Params: int * param_1, undefined4 * param_2, int param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_openCryptoSession(int *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  int *local_2c;
  byte *local_28;
  uint local_24;
  undefined1 local_20 [4];
  int local_1c;
  undefined1 local_18 [8];
  undefined1 *local_10;
  undefined1 *local_c;
  undefined1 *local_4;
  
  iVar1 = xtra_encodeBER(&local_2c,param_2,0x68106b20);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x102,param_4);
    return iVar1;
  }
  iVar1 = local_2c[2];
  *param_1 = iVar1;
  if (iVar1 != 0) {
    return 0;
  }
  if (*local_2c == 0) {
    if (param_3 == 0) {
      return 0x104;
    }
    xtra_resetBERReader(param_2);
    iVar1 = xtra_writeBERData(param_1,(int *)0x0,8,(int)param_2,0x68106b20);
    if (iVar1 == 0) {
      local_2c[2] = *param_1;
      return 0;
    }
  }
  else {
    iVar1 = xtra_writeBERData(param_1,(int *)0x0,8,(int)param_2,0x68106b20);
    if (iVar1 == 0) {
      local_24 = local_2c[1];
      iVar1 = xtra_writeBERContent((int *)&local_28,*local_2c,local_24,*param_1);
      if (iVar1 == 0) {
        local_1c = *param_1;
        display_fillMemory(local_18,0,0x18);
        local_10 = local_20;
        local_c = local_10;
        local_4 = local_10;
        iVar1 = xtra_writeCertData((uint *)0x0,(uint *)&DAT_681901a0,(int)local_18,local_28,local_24);
        if (iVar1 != 0) {
          iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x102,param_4);
          return iVar1;
        }
        local_2c[2] = *param_1;
        iVar1 = 0;
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_readCRLExtensions (FUN_6810e740)
// Address: 6810e740
// Size: 155 bytes
// Params: int * param_1, undefined4 * param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readCRLExtensions(int *param_1,undefined4 *param_2,int param_3,undefined4 *param_4)
{
  int iVar1;
  undefined4 local_24 [2];
  undefined4 local_1c;
  undefined1 local_18 [4];
  undefined4 *local_14;
  undefined4 *local_c;
  undefined4 *local_8;
  undefined4 *local_4;
  
  local_24[0] = 0;
  iVar1 = xtra_encodeBER(&local_1c,param_2,0x68106b20);
  if (iVar1 != 0) {
    xtra_decodeBER(&DAT_6818eba4,iVar1,0x102,param_4);
    return 0;
  }
  display_fillMemory(local_18,0,0x18);
  local_14 = local_24;
  local_c = local_14;
  local_8 = local_14;
  local_4 = local_14;
  iVar1 = xtra_writeBERSequenceEx(param_1,(uint *)&DAT_681901a0,(int)local_18);
  if (iVar1 == 0) {
    xtra_writeBERBytes(param_1,param_1[1],param_3);
  }
  return 0;
}



// ============================================================
// Function: xtra_writeCRLExtensions (FUN_6810e7e0)
// Address: 6810e7e0
// Size: 126 bytes
// Params: undefined4 * param_1, undefined4 * param_2, byte * param_3, uint param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_writeCRLExtensions(undefined4 *param_1,undefined4 *param_2,byte *param_3,uint param_4)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  uint uVar4;
  uint *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_2,0x68106b20);
  if (iVar1 == 0) {
    iVar1 = 0;
    uVar4 = 0;
    if (*local_4 != 0) {
      do {
        puVar2 = (undefined4 *)(local_4[1] + iVar1);
        *param_1 = puVar2;
        if ((puVar2[1] == param_4) &&
           (uVar3 = display_decodeFormat((byte *)*puVar2,param_3,param_4), uVar3 == 0)) {
          return 0;
        }
        iVar1 = iVar1 + 0x10;
        uVar4 = uVar4 + 1;
      } while (uVar4 < *local_4);
    }
    iVar1 = 0x104;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_attachCryptoToReader (FUN_6810e860)
// Address: 6810e860
// Size: 56 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_attachCryptoToReader(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  int local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_1,0x68106b20);
  if (iVar1 != 0) {
    return 0x102;
  }
  *(undefined4 *)(local_4 + 8) = param_2;
  return 0;
}



// ============================================================
// Function: xtra_createSignedContent (FUN_6810e8a0)
// Address: 6810e8a0
// Size: 121 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_createSignedContent(int *param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 *puVar2;
  int *local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_2,0x68106b20);
  if (iVar1 == 0) {
    iVar1 = xtra_writeBERInt(local_4 + 1,(*local_4 + 1) * 0x10,(int)param_2);
    if (iVar1 == 0) {
      puVar2 = (undefined4 *)(*local_4 * 0x10 + local_4[1]);
      *param_1 = (int)puVar2;
      *puVar2 = param_3;
      *(undefined4 *)(*param_1 + 4) = param_4;
      *(undefined4 *)(*param_1 + 8) = 0;
      *(undefined4 *)(*param_1 + 0xc) = 0;
      iVar1 = 0;
      *local_4 = *local_4 + 1;
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_finalizeSignedContent (FUN_6810e920)
// Address: 6810e920
// Size: 108 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_finalizeSignedContent(int param_1,int param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  
  if (param_4 == 0) {
    return 0x108;
  }
  piVar1 = (int *)(param_2 + 0xc);
  iVar2 = xtra_writeBERInt(piVar1,(*(int *)(param_2 + 8) * 3 + 3) * 4,param_1);
  if (iVar2 == 0) {
    *(undefined4 *)(*piVar1 + *(int *)(param_2 + 8) * 0xc) = param_3;
    *(int *)(*piVar1 + 4 + *(int *)(param_2 + 8) * 0xc) = param_4;
    *(undefined4 *)(*piVar1 + 8 + *(int *)(param_2 + 8) * 0xc) = 0;
    iVar2 = 0;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
  }
  return iVar2;
}



// ============================================================
// Function: xtra_createCryptoReader (FUN_6810ec20)
// Address: 6810ec20
// Size: 19 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_createCryptoReader(int *param_1)
{
  xtra_createObjectDataBlock(param_1,(int *)&PTR_FUN_68190460);
  return 0;
}



// ============================================================
// Function: xtra_loadCryptoFromCert (FUN_6810ec40)
// Address: 6810ec40
// Size: 145 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_loadCryptoFromCert(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  int local_24 [2];
  undefined1 local_1c [24];
  undefined *local_4;
  
  display_fillMemory(local_1c,0,0x1c);
  local_4 = &DAT_68190458;
  iVar1 = xtra_readCertFieldEx(local_24,(uint *)&DAT_68190268,(int)local_1c,(byte *)*param_2,param_2[1]);
  if (iVar1 != 0) {
    iVar1 = xtra_decodeBER(&DAT_6818eba4,iVar1,0x110,param_3);
    return iVar1;
  }
  iVar1 = xtra_createObjectBlock(param_1,local_24,(int *)&PTR_FUN_68190460,param_3);
  if (iVar1 != 0) {
    iVar1 = xtra_updateCryptoState(iVar1,param_3);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: xtra_storeCryptoFromCert (FUN_6810ece0)
// Address: 6810ece0
// Size: 116 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_storeCryptoFromCert(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

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
  iVar1 = xtra_createObjectBlock(param_1,&local_8,(int *)&PTR_FUN_68190460,param_3);
  if (iVar1 != 0) {
    uVar2 = xtra_updateCryptoState(iVar1,param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_extractSignatureData (FUN_6810ed60)
// Address: 6810ed60
// Size: 49 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_extractSignatureData(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_buildObjectBlock(param_1,param_2,(int *)&PTR_FUN_68190460,param_3);
  if (iVar1 != 0) {
    uVar2 = xtra_updateCryptoState(iVar1,param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_extractPublicKeyData (FUN_6810eda0)
// Address: 6810eda0
// Size: 49 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_extractPublicKeyData(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_getObjectBlockData(param_1,param_2,(int *)&PTR_FUN_68190460,param_3);
  if (iVar1 != 0) {
    uVar2 = xtra_updateCryptoState(iVar1,param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_finalizeCrypto (FUN_6810ede0)
// Address: 6810ede0
// Size: 49 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_finalizeCrypto(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_getObjectDerivedData(param_1,param_2,(int *)&PTR_FUN_68190460,param_3);
  if (iVar1 != 0) {
    uVar2 = xtra_updateCryptoState(iVar1,param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_extractCertPublicKey (FUN_6810ee20)
// Address: 6810ee20
// Size: 45 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_extractCertPublicKey(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = xtra_getObjectExtension(param_1,param_2,(int *)&PTR_FUN_68190460);
  if (iVar1 != 0) {
    uVar2 = xtra_updateCryptoState(iVar1,param_3);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_lookupCRLByIssuer (FUN_6810ee50)
// Address: 6810ee50
// Size: 238 bytes
// Params: undefined4 param_1, undefined4 * param_2, char * param_3, int param_4, undefined4 * param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_lookupCRLByIssuer(undefined4 param_1,undefined4 *param_2,char *param_3,int param_4,undefined4 *param_5)

{
  char cVar1;
  int iVar2;
  int local_24;
  undefined1 local_20 [4];
  char **local_1c;
  char **local_18;
  char *local_14;
  int local_10;
  undefined4 local_c;
  undefined4 local_8;
  int local_4;
  
  iVar2 = xtra_finalizeCrypto(&local_24,param_2,param_5);
  if (iVar2 == 0) {
    if (*(int *)(local_24 + 0x1c) == 0) {
      return 300;
    }
    cVar1 = *param_3;
    for (; (cVar1 == '\0' && (param_4 != 0)); param_4 = param_4 + -1) {
      param_3 = param_3 + 1;
      cVar1 = *param_3;
    }
    display_fillMemory(local_20,0,0xc);
    local_c = 0;
    local_1c = &local_14;
    local_8 = param_1;
    local_4 = 0;
    local_18 = local_1c;
    local_14 = param_3;
    local_10 = param_4;
    iVar2 = xtra_writeCertData((uint *)0x0,(uint *)&DAT_68190408,(int)local_20,*(byte **)(local_24 + 0x18)
                         ,*(uint *)(local_24 + 0x1c));
    if (iVar2 != 0) {
      if ((iVar2 == 0x112) && (local_4 != 0)) {
        return 0;
      }
      iVar2 = xtra_decodeBER(&DAT_6818eba4,iVar2,0x110,param_5);
      return iVar2;
    }
    iVar2 = 300;
  }
  return iVar2;
}



// ============================================================
// Function: xtra_initCryptoContext (FUN_6810ef40)
// Address: 6810ef40
// Size: 14 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initCryptoContext(int *param_1)
{
  display_releaseFormatData(param_1);
  return 0;
}



// ============================================================
// Function: xtra_updateCryptoState (FUN_6810ef50)
// Address: 6810ef50
// Size: 56 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_updateCryptoState(int param_1,undefined4 *param_2)
{
  if (param_1 == 0x124) {
    xtra_decodeBER(&DAT_6818eba4,0x124,0x111,param_2);
    return 0;
  }
  xtra_decodeBER(&DAT_6818eba4,param_1,0x110,param_2);
  return 0;
}



// ============================================================
// Function: xtra_verifyCertSignature (FUN_6810f130)
// Address: 6810f130
// Size: 233 bytes
// Params: int param_1, int param_2, int * param_3, int param_4, undefined4 param_5, undefined4 param_6, int * param_7, int param_8, undefined4 * param_9, undefined4 param_10
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_verifyCertSignature(int param_1,int param_2,int *param_3,int param_4,undefined4 param_5,undefined4 param_6,
            int *param_7,int param_8,undefined4 *param_9,undefined4 param_10)

{
  int iVar1;
  int iVar2;
  undefined4 local_108;
  int local_104;
  undefined1 local_100 [256];
  
  iVar2 = 0;
  iVar1 = xtra_lookupHashAlgorithm(&local_104,param_7,param_9);
  if (iVar1 == 0) {
    iVar2 = xtra_writeCipherAttribs(local_100,&local_108,0x100,local_104,param_5,param_6);
    if (iVar2 == 0) {
      iVar1 = xtra_verifyDigestSignature(param_1,param_8,param_2,param_3,param_4,local_100,local_108,0,param_9,
                           param_10);
    }
  }
  display_fillMemory(local_100,0,0x100);
  if (iVar2 != 0) {
    iVar1 = xtra_decodeBERDirect(&DAT_6818eba4,iVar2,0x112,param_9);
    return iVar1;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_setupCryptoMode (FUN_6810f3a0)
// Address: 6810f3a0
// Size: 312 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 param_3, int param_4, undefined4 * param_5, undefined4 param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_setupCryptoMode(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,int param_4,
            undefined4 *param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int local_4;
  
  local_4 = 0;
  if (param_2[2] != 0) {
    return 0x101;
  }
  iVar1 = display_getNetSecurityState(&local_4);
  iVar2 = local_4;
  if ((iVar1 == 0) && (iVar2 = xtra_loadEncryptAlgorithm(local_4,param_3,param_5), iVar2 == 0)) {
    iVar3 = xtra_initSecureFormat(local_4,param_4,&PTR_PTR_6818e92c,param_6);
    if (iVar3 == 0) {
      iVar1 = display_dispatchCryptoOp(local_4,*param_1,param_1[1],param_6);
      if (((iVar1 == 0) && (iVar1 = display_dispatchCryptoOpEx(local_4,*param_2,param_2[1],0,param_6), iVar1 != 0)
          ) && ((iVar1 == 0x21c || ((iVar1 == 0x20c || (iVar1 == 0x20d)))))) {
        iVar1 = 0;
        iVar2 = 0x101;
      }
    }
    else {
      iVar1 = 0;
      iVar2 = xtra_decodeBERDirect(&DAT_6818eba4,iVar3,0x13e,param_5);
    }
  }
  display_initNetworkSecurity(&local_4);
  if (iVar1 == 0) {
    return iVar2;
  }
  iVar2 = xtra_decodeBERDirect(&DAT_6818eba4,iVar1,0x112,param_5);
  return iVar2;
}



// ============================================================
// Function: xtra_computeDigestValue (FUN_6810f4e0)
// Address: 6810f4e0
// Size: 167 bytes
// Params: int param_1, int param_2, int * param_3, int param_4, undefined4 param_5, undefined4 param_6, int param_7, undefined4 * param_8, undefined4 param_9
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_computeDigestValue(int param_1,int param_2,int *param_3,int param_4,undefined4 param_5,undefined4 param_6,
            int param_7,undefined4 *param_8,undefined4 param_9)

{
  int iVar1;
  undefined4 uVar2;
  int local_4;
  
  iVar1 = xtra_dispatchEncrypt8(param_1,param_2,param_3,param_4,param_5,param_6,param_7,param_9);
  if ((iVar1 == 0) &&
     (iVar1 = xtra_dispatchEncrypt6(param_1,param_2 + *param_3,&local_4,param_4 - *param_3,param_7,param_9),
     iVar1 == 0)) {
    *param_3 = *param_3 + local_4;
    return 0;
  }
  if (iVar1 != 0x218) {
    uVar2 = xtra_decodeBERDirect(&DAT_6818eba4,iVar1,0x112,param_8);
    return uVar2;
  }
  return 0x12f;
}



// ============================================================
// Function: xtra_verifyDigestSignature (FUN_6810f640)
// Address: 6810f640
// Size: 109 bytes
// Params: int param_1, int param_2, int param_3, int * param_4, int param_5, undefined4 param_6, undefined4 param_7, int param_8, undefined4 * param_9, undefined4 param_10
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_verifyDigestSignature(int param_1,int param_2,int param_3,int *param_4,int param_5,undefined4 param_6,
            undefined4 param_7,int param_8,undefined4 *param_9,undefined4 param_10)
{
  int iVar1;
  
  iVar1 = xtra_initSecureFormat(param_1,param_2,&PTR_PTR_6818e92c,param_10);
  if (iVar1 != 0) {
    xtra_decodeBERDirect(&DAT_6818eba4,iVar1,0x12e,param_9);
    return 0;
  }
  xtra_computeDigestValue(param_1,param_3,param_4,param_5,param_6,param_7,param_8,param_9,param_10);
  return 0;
}



// ============================================================
// Function: xtra_loadCryptoProvider (FUN_6810f910)
// Address: 6810f910
// Size: 59 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_loadCryptoProvider(int param_1,int param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    iVar1 = display_checkNetSecurity(param_2);
    if (iVar1 == 0) {
      xtra_importSymmetricKey(param_1,param_2,param_3,param_4);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_decryptData (FUN_6810f950)
// Address: 6810f950
// Size: 44 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_decryptData(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    xtra_exportSymmetricKey(param_1,param_2,param_3,param_4);
  }
  return 0;
}



// ============================================================
// Function: xtra_encryptDataEx (FUN_6810f980)
// Address: 6810f980
// Size: 49 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_encryptDataEx(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  int iVar1;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 == 0) {
    xtra_generateRandomKey(param_1,param_2,param_3,param_4,param_5);
  }
  return 0;
}



// ============================================================
// Function: xtra_generateRandomBytes (FUN_6810fd50)
// Address: 6810fd50
// Size: 274 bytes
// Params: int * param_1, int * param_2
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_generateRandomBytes(int *param_1,int *param_2)

{
  int *piVar1;
  uint uVar2;
  int local_34;
  int local_30 [2];
  undefined1 local_28 [4];
  undefined *local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  uVar2 = xtra_readCertChain(param_2,&local_34,0x68190850);
  if (uVar2 == 0) {
    uVar2 = xtra_readCertBlock(param_2,param_1,8);
    if (uVar2 == 0) {
      piVar1 = (int *)*param_1;
      local_30[0] = 0;
      display_fillMemory(local_28,0,0x28);
      local_24 = &DAT_68190810;
      local_20 = local_34;
      local_1c = local_34 + 8;
      local_18 = local_34 + 0x10;
      local_14 = local_34 + 0x18;
      local_10 = local_34 + 0x20;
      local_c = local_34 + 0x28;
      local_8 = local_34 + 0x30;
      local_4 = local_34 + 0x38;
      uVar2 = xtra_writeBERSequence(local_30,(uint *)&DAT_68190760,(int)local_28);
      if (uVar2 == 0) {
        uVar2 = xtra_writeBERField(piVar1,&PTR_DAT_68190828,&PTR_DAT_6818eff0,local_30);
        if (uVar2 == 0) {
          uVar2 = xtra_readCertBlockEx(param_2,piVar1,piVar1[1]);
        }
      }
      display_freeIfNonNull(local_30[0]);
    }
  }
  return uVar2;
}



// ============================================================
// Function: xtra_encryptData (FUN_6810ff70)
// Address: 6810ff70
// Size: 51 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_encryptData(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = display_initFormatContext(param_1);
  if (iVar1 != 0) {
    return 0x21b;
  }
  uVar2 = xtra_generateRandom(param_1,param_2,param_3,param_4);
  return uVar2;
}



