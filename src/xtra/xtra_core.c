// Module: xtra
// Topic: Core infrastructure - memory management, stack/context, BER/DER primitive encoding/decoding
// Address range: 0x68100980 - 0x68101DF0
// Functions (44):
//   xtra_expandSHASchedule
//   xtra_initCipherDH
//   xtra_initCryptoFromParams
//   xtra_countBits
//   xtra_initRSAKeyPair
//   xtra_processBlockCipher
//   xtra_checkContextInit
//   xtra_transformCipherBlock
//   xtra_destroyKeyPairContext
//   xtra_clearBERHeader
//   xtra_writeCertBlock
//   xtra_lookupCertBlockEntry
//   xtra_clearCertBlockTags
//   xtra_clearCertBlockHeader
//   xtra_readCertBlockData
//   xtra_freeCertBlockItems
//   xtra_readCertBlock
//   xtra_copyCertData
//   xtra_readCertBlockEx
//   xtra_addCertBlockItem
//   xtra_reallocCertBlock
//   xtra_findCertBlockItem
//   xtra_invokeCertHandler
//   xtra_readCertChain
//   xtra_storeCertBlockPair
//   xtra_countSignificantBits
//   xtra_clearBERHeaderEx
//   xtra_freeCertBlockFull
//   xtra_validateCertTag
//   xtra_validateCert
//   xtra_bindCertHandler
//   xtra_readCertChainCached
//   xtra_dispatchCryptoOp3
//   xtra_dispatchCryptoOp4
//   xtra_readCertField
//   xtra_validateBERTag
//   xtra_encodeBERRaw
//   xtra_processCommand
//   xtra_processCertChain
//   xtra_writeBERBitString
//   xtra_readCertData
//   xtra_readCertChainEx
//   xtra_readCertSequence
//   xtra_readCertRange

// ============================================================
// Function: xtra_expandSHASchedule (FUN_68100980)
// Address: 68100980
// Size: 44 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_expandSHASchedule(int param_1)
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  
  iVar2 = 0x40;
  puVar3 = (uint *)(param_1 + 8);
  do {
    uVar1 = puVar3[6] ^ puVar3[-2] ^ puVar3[0xb] ^ *puVar3;
    iVar2 = iVar2 + -1;
    puVar3[0xe] = uVar1 >> 0x1f | uVar1 * 2;
    puVar3 = puVar3 + 1;
  } while (iVar2 != 0);
  return 0;
}



// ============================================================
// Function: xtra_initCipherDH (FUN_681009c0)
// Address: 681009c0
// Size: 103 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initCipherDH(int *param_1,int param_2)
{
  int iVar1;
  int local_1c;
  undefined1 *local_18;
  undefined1 *local_14;
  undefined1 local_10 [8];
  undefined1 local_8 [8];
  
  iVar1 = xtra_readCertBlock(param_1,&local_1c,0x10);
  if (iVar1 == 0) {
    local_18 = local_10;
    local_14 = local_8;
    iVar1 = xtra_processDHParams(local_1c,param_2,(int)local_10,(int *)&local_18,2,param_1);
    if (iVar1 == 0) {
      xtra_writeCertBlock(param_1,&PTR_FUN_6818efd8,local_1c);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_initCryptoFromParams (FUN_68100a30)
// Address: 68100a30
// Size: 96 bytes
// Params: int * param_1, int * param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initCryptoFromParams(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int local_10;
  int local_c;
  int local_8;
  int local_4;
  
  iVar2 = xtra_encodeDHKeyParams(&local_10,&local_8,(int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0,param_2);
  if (iVar2 == 0) {
    iVar2 = xtra_readCertBlock(param_2,param_1,0x10);
    if (iVar2 == 0) {
      piVar1 = (int *)*param_1;
      *piVar1 = local_10;
      piVar1[1] = local_c;
      piVar1[2] = local_8;
      piVar1[3] = local_4;
      iVar2 = 0;
    }
  }
  return iVar2;
}



// ============================================================
// Function: xtra_countBits (FUN_68100a90)
// Address: 68100a90
// Size: 67 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_countBits(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (param_2 != 0) {
    do {
      if (*(char *)(uVar4 + param_1) != '\0') break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_2);
  }
  if (param_2 != uVar4) {
    iVar2 = 8;
    bVar3 = 0x80;
    bVar1 = *(byte *)(uVar4 + param_1) & 0x80;
    while (bVar1 == 0) {
      bVar3 = bVar3 >> 1;
      iVar2 = iVar2 + -1;
      bVar1 = bVar3 & *(byte *)(uVar4 + param_1);
    }
    return iVar2 + (param_2 - (uVar4 + 1)) * 8;
  }
  return 0;
}



// ============================================================
// Function: xtra_initRSAKeyPair (FUN_68100ae0)
// Address: 68100ae0
// Size: 170 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_initRSAKeyPair(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar1 = param_1 + 3;
  xtra_clearContext(piVar1);
  xtra_clearContext(param_1 + 6);
  param_1[1] = 0;
  iVar2 = xtra_initCryptoKey(*param_2,param_2[1],piVar1);
  if (iVar2 == 0) {
    iVar2 = xtra_initCryptoKey(param_2[2],param_2[3],param_1 + 6);
    if (iVar2 == 0) {
      iVar3 = xtra_destroyCryptoKey((int)piVar1);
      iVar3 = (int)(iVar3 + 7 + (iVar3 + 7 >> 0x1f & 7U)) >> 3;
      *param_1 = iVar3;
      iVar3 = display_allocBlock(iVar3);
      param_1[1] = iVar3;
      if (iVar3 == 0) {
        iVar2 = 0x80;
      }
      else {
        param_1[2] = 0;
      }
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  uVar4 = xtra_getCryptoState(iVar2);
  return uVar4;
}



// ============================================================
// Function: xtra_processBlockCipher (FUN_68100b90)
// Address: 68100b90
// Size: 288 bytes
// Params: uint * param_1, char * param_2, int * param_3, uint param_4, int param_5, uint param_6, undefined4 * param_7
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_processBlockCipher(uint *param_1,char *param_2,int *param_3,uint param_4,int param_5,uint param_6,
            undefined4 *param_7)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  uint local_4;
  
  *param_3 = 0;
  uVar1 = param_1[2];
  if (param_6 + uVar1 < *param_1) {
    display_checkAndFree(param_1[1] + uVar1,param_5,param_6);
    param_1[2] = param_1[2] + param_6;
    return 0;
  }
  if (uVar1 != 0) {
    iVar3 = *param_1 - uVar1;
    param_6 = param_6 - iVar3;
    display_checkAndFree(param_1[1] + uVar1,param_5,iVar3);
    param_5 = param_5 + iVar3;
    iVar3 = xtra_transformCipherBlock(param_1,param_2,&local_4,param_4,param_1[1],param_7);
    if (iVar3 != 0) {
      uVar2 = xtra_getCryptoState(iVar3);
      return uVar2;
    }
    param_2 = param_2 + local_4;
    param_4 = param_4 - local_4;
    *param_3 = *param_3 + local_4;
  }
  if (*param_1 <= param_6) {
    do {
      iVar3 = xtra_transformCipherBlock(param_1,param_2,&local_4,param_4,param_5,param_7);
      if (iVar3 != 0) {
        uVar2 = xtra_getCryptoState(iVar3);
        return uVar2;
      }
      param_6 = param_6 - *param_1;
      param_2 = param_2 + local_4;
      param_4 = param_4 - local_4;
      param_5 = param_5 + *param_1;
      *param_3 = *param_3 + local_4;
    } while (*param_1 <= param_6);
  }
  param_1[2] = param_6;
  display_checkAndFree(param_1[1],param_5,param_6);
  return 0;
}



// ============================================================
// Function: xtra_checkContextInit (FUN_68100cb0)
// Address: 68100cb0
// Size: 26 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_checkContextInit(int param_1)

{
  if (*(int *)(param_1 + 8) != 0) {
    return 6;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  return 0;
}



// ============================================================
// Function: xtra_transformCipherBlock (FUN_68100cd0)
// Address: 68100cd0
// Size: 230 bytes
// Params: uint * param_1, char * param_2, uint * param_3, uint param_4, int param_5, undefined4 * param_6
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_transformCipherBlock(uint *param_1,char *param_2,uint *param_3,uint param_4,int param_5,undefined4 *param_6)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  int local_18 [3];
  int local_c [3];
  
  xtra_clearContext(local_18);
  xtra_clearContext(local_c);
  uVar1 = *param_1;
  *param_3 = uVar1;
  if (param_4 < uVar1) {
    iVar3 = 10;
  }
  else {
    iVar3 = xtra_initCryptoKey(param_5,*param_1,local_c);
    if (iVar3 == 0) {
      iVar3 = xtra_performRSAOperation((int)local_c,(int)(param_1 + 6),(int *)(param_1 + 3),local_18,param_6);
      if (iVar3 == 0) {
        iVar3 = xtra_destroyCryptoKey((int)(param_1 + 3));
        iVar3 = xtra_convertBignumToBytes((int)local_18,(int)(iVar3 + 7 + (iVar3 + 7 >> 0x1f & 7U)) >> 3,param_4,
                             param_3,param_2);
      }
    }
  }
  xtra_freeContext(local_c);
  xtra_freeContext(local_18);
  if (iVar3 == 0) {
    return 0;
  }
  uVar2 = xtra_getCryptoState(iVar3);
  return uVar2;
}



// ============================================================
// Function: xtra_destroyKeyPairContext (FUN_68100dc0)
// Address: 68100dc0
// Size: 64 bytes
// Params: size_t * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_destroyKeyPairContext(size_t *param_1)
{
  xtra_freeContext((int *)(param_1 + 3));
  xtra_freeContext((int *)(param_1 + 6));
  if ((void *)param_1[1] != (void *)0x0) {
    display_fillMemory((void *)param_1[1],0,*param_1);
    display_freeIfNonNull(param_1[1]);
  }
  return 0;
}



// ============================================================
// Function: xtra_clearBERHeader (FUN_68100e00)
// Address: 68100e00
// Size: 32 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_clearBERHeader(void *param_1)
{
  xtra_clearCertBlockHeader(param_1);
  display_fillMemory((void *)((int)param_1 + 0xc),0,8);
  return 0;
}



// ============================================================
// Function: xtra_writeCertBlock (FUN_68100e20)
// Address: 68100e20
// Size: 67 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_writeCertBlock(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = param_1 + 4;
  iVar2 = xtra_reallocCertBlock(param_1,piVar1,param_1[3] * 8 + 8);
  if (iVar2 == 0) {
    *(undefined4 *)(*piVar1 + param_1[3] * 8) = param_2;
    *(undefined4 *)(*piVar1 + 4 + param_1[3] * 8) = param_3;
    iVar2 = 0;
    param_1[3] = param_1[3] + 1;
  }
  return iVar2;
}



// ============================================================
// Function: xtra_lookupCertBlockEntry (FUN_68100e70)
// Address: 68100e70
// Size: 59 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_lookupCertBlockEntry(int param_1,int *param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (*(uint *)(param_1 + 0xc) != 0) {
    piVar1 = *(int **)(param_1 + 0x10);
    do {
      if (*piVar1 == param_3) {
        *param_2 = (*(int **)(param_1 + 0x10))[uVar2 * 2 + 1];
        return 0;
      }
      piVar1 = piVar1 + 2;
      uVar2 = uVar2 + 1;
    } while (uVar2 < *(uint *)(param_1 + 0xc));
  }
  return 0x217;
}



// ============================================================
// Function: xtra_clearCertBlockTags (FUN_68100eb0)
// Address: 68100eb0
// Size: 32 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_clearCertBlockTags(int *param_1)
{
  xtra_freeCertBlockItems(param_1);
  display_fillMemory(param_1 + 3,0,8);
  return 0;
}



// ============================================================
// Function: xtra_clearCertBlockHeader (FUN_68100ed0)
// Address: 68100ed0
// Size: 18 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_clearCertBlockHeader(void *param_1)
{
  display_fillMemory(param_1,0,0xc);
  return 0;
}



// ============================================================
// Function: xtra_readCertBlockData (FUN_68100ef0)
// Address: 68100ef0
// Size: 28 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readCertBlockData(int *param_1)
{
  xtra_freeCertBlockItems(param_1);
  display_freeIfNonNull(param_1[2]);
  return 0;
}



// ============================================================
// Function: xtra_freeCertBlockItems (FUN_68100f10)
// Address: 68100f10
// Size: 89 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freeCertBlockItems(int *param_1)
{
  void *pvVar1;
  int iVar2;
  int *piVar3;
  
  iVar2 = *param_1;
  piVar3 = (int *)param_1[2];
  while (iVar2 != 0) {
    iVar2 = iVar2 + -1;
    pvVar1 = (void *)*piVar3;
    if (pvVar1 != (void *)0x0) {
      if ((code *)piVar3[2] == (code *)0x0) {
        display_fillMemory(pvVar1,0,piVar3[1]);
        display_freeIfNonNull(*piVar3);
      }
      else {
        (*(code *)piVar3[2])(pvVar1);
      }
      *piVar3 = 0;
    }
    piVar3 = piVar3 + 3;
  }
  *param_1 = 0;
  return 0;
}



// ============================================================
// Function: xtra_readCertBlock (FUN_68100f70)
// Address: 68100f70
// Size: 48 bytes
// Params: int * param_1, int * param_2, size_t param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readCertBlock(int *param_1,int *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = display_allocBlock(param_3);
  *param_2 = iVar1;
  if (iVar1 == 0) {
    return 0x206;
  }
  iVar1 = xtra_readCertBlockEx(param_1,param_2,param_3);
  return iVar1;
}



// ============================================================
// Function: xtra_copyCertData (FUN_68100fa0)
// Address: 68100fa0
// Size: 51 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, size_t param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_copyCertData(int *param_1,int *param_2,undefined4 param_3,size_t param_4)

{
  int iVar1;
  
  iVar1 = xtra_readCertBlock(param_1,param_2,param_4);
  if (iVar1 == 0) {
    display_checkAndFree(*param_2,param_3,param_4);
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_readCertBlockEx (FUN_68100fe0)
// Address: 68100fe0
// Size: 79 bytes
// Params: int * param_1, int * param_2, size_t param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readCertBlockEx(int *param_1,int *param_2,size_t param_3)

{
  int iVar1;
  
  iVar1 = xtra_addCertBlockItem(param_1,*param_2,param_3,0);
  if (iVar1 != 0) {
    display_fillMemory((void *)*param_2,0,param_3);
    display_freeIfNonNull(*param_2);
    *param_2 = 0;
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: xtra_addCertBlockItem (FUN_68101030)
// Address: 68101030
// Size: 146 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl
xtra_addCertBlockItem(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *param_1;
  if ((uint)param_1[1] < iVar1 + 1U) {
    iVar2 = display_allocBlock((iVar1 * 3 + 0x1e) * 4);
    if (iVar2 == 0) {
      return 0x206;
    }
    display_checkAndFree(iVar2,param_1[2],*param_1 * 0xc);
    display_freeIfNonNull(param_1[2]);
    param_1[2] = iVar2;
    param_1[1] = iVar1 + 10;
  }
  *(undefined4 *)(param_1[2] + *param_1 * 0xc) = param_2;
  *(undefined4 *)(param_1[2] + 4 + *param_1 * 0xc) = param_3;
  *(undefined4 *)(param_1[2] + 8 + *param_1 * 0xc) = param_4;
  *param_1 = *param_1 + 1;
  return 0;
}



// ============================================================
// Function: xtra_reallocCertBlock (FUN_681010d0)
// Address: 681010d0
// Size: 102 bytes
// Params: int * param_1, int * param_2, uint param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_reallocCertBlock(int *param_1,int *param_2,uint param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = xtra_findCertBlockItem(param_1,*param_2);
  iVar2 = display_freeFormatBlock(*param_2,param_3);
  *param_2 = iVar2;
  if (iVar2 == 0) {
    if (piVar1 != (int *)0x0) {
      *piVar1 = 0;
    }
    return 0x206;
  }
  if (piVar1 == (int *)0x0) {
    iVar2 = xtra_readCertBlockEx(param_1,param_2,param_3);
    return iVar2;
  }
  *piVar1 = iVar2;
  piVar1[1] = param_3;
  return 0;
}



// ============================================================
// Function: xtra_findCertBlockItem (FUN_68101140)
// Address: 68101140
// Size: 47 bytes
// Params: int * param_1, int param_2
// Return: int *
// Calling convention: __cdecl
// ============================================================

/* FIXUP(C2040: 'xtra_findCertBlockItem': 'int *(int *,int)' differs in levels of indirection from 'int ()'): int * __cdecl xtra_findCertBlockItem(int *param_1,int param_2) */

/* FIXUP(C2449: found '{' at file scope (missing function header?)): { */
  int *piVar1;
  int iVar2;
  
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'if'): if (param_2 == 0) { */
    /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return (int *)0x0; */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */
  /* FIXUP(C2065: undeclared 'param_1'): iVar2 = *param_1; */
  /* FIXUP(C2040: 'piVar1': 'int' differs in levels of indirection from 'int *'): piVar1 = (int *)param_1[2]; */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'while'): while( true ) { */
    /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'if'): if (iVar2 == 0) { */
      /* FIXUP(C2059): return (int *)0x0; */
    /* FIXUP(C2059): } */
    /* FIXUP(C2099): iVar2 = iVar2 + -1; */
    /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'if'): if (*piVar1 == param_2) break; */
    /* FIXUP(C2040: 'piVar1': 'int' differs in levels of indirection from 'int *'): piVar1 = piVar1 + 3; */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return piVar1; */
/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */



// ============================================================
// Function: xtra_invokeCertHandler (FUN_68101170)
// Address: 68101170
// Size: 42 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_invokeCertHandler(int param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    return 0x212;
  }
  if (*(int *)(param_1 + 0xc) != 0) {
    return 0x20e;
  }
  uVar1 = (*(code *)*param_2)(param_1,param_3);
  return uVar1;
}



// ============================================================
// Function: xtra_readCertChain (FUN_681011a0)
// Address: 681011a0
// Size: 93 bytes
// Params: int * param_1, int * param_2, int param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readCertChain(int *param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    return 0x212;
  }
  if (param_1[3] == 0) {
    return 0x211;
  }
  iVar1 = xtra_lookupCertBlockEntry((int)param_1,param_2,param_3);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(param_3 + 4))(param_2,param_1);
  if (iVar1 == 0) {
    iVar1 = xtra_writeCertBlock(param_1,param_3,*param_2);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_storeCertBlockPair (FUN_68101200)
// Address: 68101200
// Size: 73 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_storeCertBlockPair(int *param_1,undefined4 param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 *local_4;
  
  iVar1 = xtra_readCertBlock(param_1,(int *)&local_4,8);
  if (iVar1 == 0) {
    *local_4 = param_2;
    local_4[1] = param_3;
    xtra_writeCertBlock(param_1,&PTR_LAB_681900f8,local_4);
  }
  return 0;
}



// ============================================================
// Function: xtra_countSignificantBits (FUN_68101250)
// Address: 68101250
// Size: 67 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_countSignificantBits(int param_1,uint param_2)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  
  uVar4 = 0;
  if (param_2 != 0) {
    do {
      if (*(char *)(uVar4 + param_1) != '\0') break;
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_2);
  }
  if (uVar4 != param_2) {
    iVar2 = 8;
    bVar3 = 0x80;
    bVar1 = *(byte *)(uVar4 + param_1) & 0x80;
    while (bVar1 == 0) {
      bVar3 = bVar3 >> 1;
      iVar2 = iVar2 + -1;
      bVar1 = bVar3 & *(byte *)(uVar4 + param_1);
    }
    return iVar2 + (param_2 - (uVar4 + 1)) * 8;
  }
  return 0;
}



// ============================================================
// Function: xtra_clearBERHeaderEx (FUN_681012a0)
// Address: 681012a0
// Size: 32 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_clearBERHeaderEx(void *param_1)
{
  xtra_clearBERHeader(param_1);
  display_fillMemory((void *)((int)param_1 + 0x14),0,8);
  return 0;
}



// ============================================================
// Function: xtra_freeCertBlockFull (FUN_681012c0)
// Address: 681012c0
// Size: 41 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freeCertBlockFull(int *param_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)param_1[5];
  if (puVar1 != (undefined4 *)0x0) {
    (*(code *)*puVar1)(puVar1);
    display_freeIfNonNull(param_1[5]);
  }
  xtra_readCertBlockData(param_1);
  return 0;
}



// ============================================================
// Function: xtra_validateCertTag (FUN_681012f0)
// Address: 681012f0
// Size: 40 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_validateCertTag(int param_1,int param_2)

{
  if (*(int **)(param_1 + 0x14) == (int *)0x0) {
    return 0x203;
  }
  return (**(int **)(param_1 + 0x14) == param_2) - 1 & 0x205;
}



// ============================================================
// Function: xtra_validateCert (FUN_68101320)
// Address: 68101320
// Size: 41 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_validateCert(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = xtra_validateCertTag(param_1,param_2);
  if (uVar1 == 0) {
    uVar1 = -(uint)((*(uint *)(param_1 + 0x18) & 1) == 0) & 0x202;
  }
  return uVar1;
}



// ============================================================
// Function: xtra_bindCertHandler (FUN_68101350)
// Address: 68101350
// Size: 96 bytes
// Params: int param_1, undefined * * param_2, undefined4 param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_bindCertHandler(int param_1,undefined **param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((*(int *)(param_1 + 0xc) != 0) &&
     (((*(byte *)(param_1 + 0x18) & 2) == 0 || (param_2 != &PTR_PTR_6819010c)))) {
    return 0x200;
  }
  iVar1 = (**(code **)*param_2)(param_2,param_1,param_3);
  if (iVar1 == 0) {
    if (*(code **)(*param_2 + 4) != (code *)0x0) {
      iVar1 = (**(code **)(*param_2 + 4))(param_2,param_1);
      *(int *)(param_1 + 0x14) = iVar1;
      if (iVar1 == 0) {
        return 0x206;
      }
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_readCertChainCached (FUN_681013b0)
// Address: 681013b0
// Size: 83 bytes
// Params: int * param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readCertChainCached(int *param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  if (param_1[3] == 0) {
    return 0x203;
  }
  iVar1 = xtra_lookupCertBlockEntry((int)param_1,param_2,(int)param_3);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = (**(code **)(*param_3 + 8))(param_3,param_2,param_1);
  if (iVar1 == 0) {
    iVar1 = xtra_writeCertBlock(param_1,param_3,*param_2);
  }
  return iVar1;
}




/* Restored from original Ghidra decompilation (was damaged by fixup passes) */
// ============================================================

int * __cdecl xtra_findCertBlockItem(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == 0) {
    return (int *)0x0;
  }
  iVar2 = *param_1;
  piVar1 = (int *)param_1[2];
  while( true ) {
    if (iVar2 == 0) {
      return (int *)0x0;
    }
    iVar2 = iVar2 + -1;
    if (*piVar1 == param_2) break;
    piVar1 = piVar1 + 3;
  }
  return piVar1;
}
// ============================================================
// Function: xtra_dispatchCryptoOp3 (FUN_68101410)
// Address: 68101410
// Size: 53 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_dispatchCryptoOp3(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  uint uVar1;
  
  uVar1 = xtra_validateCert(param_1,0x681146c0);
  if (uVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 0x10))
              (*(int *)(param_1 + 0x14),param_2,param_3,param_4);
  }
  return 0;
}



// ============================================================
// Function: xtra_dispatchCryptoOp4 (FUN_68101450)
// Address: 68101450
// Size: 58 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_dispatchCryptoOp4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )
{
  uint uVar1;
  
  uVar1 = xtra_validateCert(param_1,0x681146c0);
  if (uVar1 == 0) {
    (**(code **)(*(int *)(*(int *)(param_1 + 0x14) + 4) + 0x18))
              (*(int *)(param_1 + 0x14),param_2,param_3,param_4,param_5);
  }
  return 0;
}



// ============================================================
// Function: xtra_readCertField (FUN_68101490)
// Address: 68101490
// Size: 62 bytes
// Params: uint * param_1, uint * param_2, int param_3, byte * param_4, uint param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readCertField(uint *param_1,uint *param_2,int param_3,byte *param_4,uint param_5)

{
  int iVar1;
  uint local_4;
  
  iVar1 = xtra_readBERField(&local_4,param_2,param_3,param_4,param_5,(undefined4 *)0x0);
  if (iVar1 == 0) {
    if (param_1 != (uint *)0x0) {
      *param_1 = local_4;
    }
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_validateBERTag (FUN_681014d0)
// Address: 681014d0
// Size: 87 bytes
// Params: undefined4 * param_1, uint param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_validateBERTag(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  byte bVar1;
  undefined3 extraout_var;
  uint local_c;
  uint local_8;
  int local_4;
  
  bVar1 = xtra_processCryptoOp(&local_c,&local_8,&local_4,param_1,(byte *)*param_3,param_3[1]);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return 0x20c;
  }
  if ((param_2 == local_8) && (local_c != 0)) {
    return 0;
  }
  return 0x20c;
}



// ============================================================
// Function: xtra_encodeBERRaw (FUN_68101530)
// Address: 68101530
// Size: 100 bytes
// Params: undefined4 * param_1, int param_2, uint param_3, byte param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_encodeBERRaw(undefined4 *param_1,int param_2,uint param_3,byte param_4)

{
  byte *pbVar1;
  
  xtra_processCryptoData((byte *)0x0,param_1 + 1,0,param_4,(byte *)0x0,param_2,param_3);
  pbVar1 = (byte *)display_allocBlock(param_1[1]);
  *param_1 = pbVar1;
  if (pbVar1 == (byte *)0x0) {
    return 0x206;
  }
  xtra_processCryptoData(pbVar1,param_1 + 1,param_1[1],param_4,(byte *)0x0,param_2,param_3);
  return 0;
}



// ============================================================
// Function: xtra_processCommand (FUN_681015a0)
// Address: 681015a0
// Size: 86 bytes
// Params: int * param_1, int param_2, uint param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_processCommand(int *param_1,int param_2,uint param_3,int param_4,int param_5)
{
  int iVar1;
  int local_4;
  
  if (param_3 == 0) {
    local_4 = param_2;
  }
  else {
    iVar1 = xtra_copyCertData(param_1,&local_4,param_2,param_3);
    if (iVar1 != 0) {
      return 0;
    }
  }
  xtra_processCertChain((int)param_1,local_4,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: xtra_processCertChain (FUN_68101600)
// Address: 68101600
// Size: 240 bytes
// Params: int param_1, undefined4 param_2, uint param_3, int param_4, int param_5
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_processCertChain(int param_1,undefined4 param_2,uint param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  if ((param_4 == 0x1f) && (param_5 == 0)) {
    return 0x208;
  }
  if (0x7fff < param_3) {
    return 0x219;
  }
  uVar1 = *(uint *)(param_1 + 0x10);
  if (uVar1 <= *(uint *)(param_1 + 0xc)) {
    uVar4 = uVar1 * 4 + 0x28;
    if (0x7fff < uVar4) {
      return 0x219;
    }
    iVar2 = display_freeFormatBlock(*(int *)(param_1 + 0x14),uVar4);
    *(int *)(param_1 + 0x14) = iVar2;
    if (iVar2 == 0) {
      return 0x206;
    }
    uVar4 = *(uint *)(param_1 + 0x10);
    while (uVar4 < uVar1 + 10) {
      uVar3 = display_allocBlock(0x10);
      *(undefined4 *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x10) * 4) = uVar3;
      if (*(int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0x10) * 4) == 0) {
        return 0x206;
      }
      uVar4 = *(int *)(param_1 + 0x10) + 1;
      *(uint *)(param_1 + 0x10) = uVar4;
    }
  }
  **(undefined4 **)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc) * 4) = param_2;
  *(uint *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc) * 4) + 4) = param_3;
  *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc) * 4) + 8) = param_4;
  *(int *)(*(int *)(*(int *)(param_1 + 0x14) + *(int *)(param_1 + 0xc) * 4) + 0xc) = param_5;
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  return 0;
}



// ============================================================
// Function: xtra_writeBERBitString (FUN_68101890)
// Address: 68101890
// Size: 199 bytes
// Params: int * param_1, uint param_2, int param_3, int * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_writeBERBitString(int *param_1,uint param_2,int param_3,int *param_4)

{
  int iVar1;
  byte local_2;
  char local_1;
  
  local_2 = *(byte *)(param_4 + 2);
  if ((local_2 != 0) && ((7 < local_2 || (param_4[1] == 0)))) {
    return 0x208;
  }
  iVar1 = xtra_processCommand(param_1,(int)&local_2,1,param_2 | 0x400,param_3);
  if (iVar1 == 0) {
    if (local_2 != 0) {
      if ((1 < (uint)param_4[1]) &&
         (iVar1 = xtra_processCommand(param_1,*param_4,param_4[1] - 1,param_2 | 0x400,param_3), iVar1 != 0)
         ) {
        return iVar1;
      }
      local_1 = *(char *)(param_4[1] + -1 + *param_4) << (local_2 & 0x1f);
      iVar1 = xtra_processCommand(param_1,(int)&local_1,1,param_2,param_3);
      return iVar1;
    }
    iVar1 = xtra_processCommand(param_1,*param_4,param_4[1],param_2,param_3);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_readCertData (FUN_68101a60)
// Address: 68101a60
// Size: 80 bytes
// Params: int * param_1, uint * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readCertData(int *param_1,uint *param_2)
{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  *param_1 = 0;
  do {
    while( true ) {
      uVar1 = *param_2;
      param_2 = param_2 + 4;
      *param_1 = *param_1 + 1;
      uVar1 = (uVar1 | 0x100) - 0x100;
      if ((uVar1 & 0x20) == 0) break;
      if ((((uVar1 == 0x30) || (uVar1 == 0x31)) ||
          (((uVar1 & 0x800) != 0 && ((uVar1 & 0x200) == 0)))) && (iVar2 = iVar2 + 1, iVar2 == 0)) {
        return 0;
      }
    }
    if (uVar1 == 0x1e) {
      iVar2 = iVar2 + -1;
    }
  } while (iVar2 != 0);
  return 0;
}



// ============================================================
// Function: xtra_readCertChainEx (FUN_68101ab0)
// Address: 68101ab0
// Size: 330 bytes
// Params: uint * param_1, int * param_2, int * param_3
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_readCertChainEx(uint *param_1,int *param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  uint local_8;
  int local_4;
  
  *param_1 = 0;
  if (*(undefined **)*param_3 == &DAT_6818f000) {
    iVar4 = 1;
    iVar3 = *(int *)(param_3[1] + 8);
    while (iVar3 != 0x1e) {
      uVar2 = xtra_readCertChainEx(&local_8,&local_4,param_3 + iVar4);
      if (uVar2 != 0) {
        return uVar2;
      }
      uVar2 = *param_1;
      *param_1 = uVar2 + local_8;
      if (0x7fff < uVar2 + local_8) {
        return 0x219;
      }
      iVar4 = iVar4 + local_4;
      iVar3 = *(int *)(param_3[iVar4] + 8);
    }
    *param_2 = iVar4 + 1;
  }
  else {
    iVar3 = 0;
    uVar2 = ((undefined4 *)*param_3)[2];
    piVar5 = param_3;
    while ((uVar2 & 0x400) != 0) {
      uVar2 = *(int *)(*piVar5 + 4) + *param_1;
      *param_1 = uVar2;
      if (0x7fff < uVar2) {
        return 0x219;
      }
      piVar1 = piVar5 + 1;
      piVar5 = piVar5 + 1;
      iVar3 = iVar3 + 1;
      uVar2 = *(uint *)(*piVar1 + 8);
    }
    uVar2 = *(int *)(param_3[iVar3] + 4) + *param_1;
    *param_1 = uVar2;
    if (0x7fff < uVar2) {
      return 0x219;
    }
    *param_2 = iVar3 + 1;
    if (*(char *)(param_3[iVar3] + 8) == '\x1b') {
      return 0;
    }
  }
  if (*param_1 < 0x8000) {
    xtra_processCryptoData((byte *)0x0,&local_8,0,(byte)*(undefined4 *)(*param_3 + 8),
                 *(byte **)(*param_3 + 0xc),0,*param_1);
    uVar2 = *param_1;
    *param_1 = uVar2 + local_8;
    return -(uint)(0x7fff < uVar2 + local_8) & 0x219;
  }
  return 0x219;
}



// ============================================================
// Function: xtra_readCertSequence (FUN_68101c00)
// Address: 68101c00
// Size: 496 bytes
// Params: int param_1, uint * param_2, int param_3, int * param_4, int param_5, int param_6
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_readCertSequence(int param_1,uint *param_2,int param_3,int *param_4,int param_5,int param_6)
{
  int *piVar1;
  undefined4 *puVar2;
  undefined *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint local_c;
  uint local_8;
  int local_4;
  
  piVar5 = (int *)(param_5 + param_6 * 4);
  *param_2 = 0;
  puVar2 = (undefined4 *)*piVar5;
  if (puVar2[2] == 0x1e) {
    iVar6 = param_6 + -1;
    puVar3 = (undefined *)**(undefined4 **)(param_5 + -4 + param_6 * 4);
    while (puVar3 != &DAT_6818f000) {
      xtra_readCertSequence(param_1,&local_c,param_3 - *param_2,&local_4,param_5,iVar6);
      if ((*(undefined **)*piVar5 == &DAT_6818f004) &&
         (iVar4 = param_3 - *param_2,
         xtra_readCertRange(&local_8,(byte *)((param_1 - local_c) + iVar4),local_c,iVar4 + param_1,
                      *param_2), local_8 != 0)) {
        display_allocFormatBlock((param_1 - local_c) + (param_3 - *param_2),(param_3 - *param_2) + param_1,
                     local_8);
        xtra_readCertSequence(((param_3 - *param_2) - local_c) + param_1 + local_8,&local_c,local_c,&local_4,
                     param_5,iVar6);
      }
      iVar6 = iVar6 - local_4;
      *param_2 = *param_2 + local_c;
      puVar3 = (undefined *)**(undefined4 **)(param_5 + iVar6 * 4);
    }
    *param_4 = (param_6 - iVar6) + 1;
  }
  else {
    display_checkAndFree((param_3 - puVar2[1]) + param_1,*puVar2,puVar2[1]);
    *param_2 = *param_2 + *(int *)(*piVar5 + 4);
    iVar6 = param_6;
    while ((iVar6 != 0 && ((*(byte *)(piVar5[-1] + 9) & 4) != 0))) {
      piVar1 = piVar5 + -1;
      piVar5 = piVar5 + -1;
      iVar6 = iVar6 + -1;
      iVar4 = ((undefined4 *)*piVar1)[1];
      display_checkAndFree(((param_3 - *param_2) - iVar4) + param_1,*(undefined4 *)*piVar1,iVar4);
      *param_2 = *param_2 + *(int *)(*piVar5 + 4);
    }
    *param_4 = (param_6 - iVar6) + 1;
    if (*(char *)(*(int *)(param_5 + iVar6 * 4) + 8) == '\x1b') {
      return 0;
    }
  }
  piVar5 = (int *)(param_5 + iVar6 * 4);
  iVar6 = *piVar5;
  xtra_processCryptoData((byte *)0x0,&local_c,0,(byte)*(undefined4 *)(iVar6 + 8),*(byte **)(iVar6 + 0xc),0,
               *param_2);
  iVar6 = *piVar5;
  xtra_processCryptoData((byte *)(((param_3 - *param_2) - local_c) + param_1),&local_c,local_c,
               (byte)*(undefined4 *)(iVar6 + 8),*(byte **)(iVar6 + 0xc),0,*param_2);
  *param_2 = *param_2 + local_c;
  return 0;
}



// ============================================================
// Function: xtra_readCertRange (FUN_68101df0)
// Address: 68101df0
// Size: 167 bytes
// Params: uint * param_1, byte * param_2, uint param_3, int param_4, uint param_5
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_readCertRange(uint *param_1,byte *param_2,uint param_3,int param_4,uint param_5)

{
  byte bVar1;
  undefined3 extraout_var;
  uint uVar2;
  uint uVar3;
  uint local_18;
  byte *local_14;
  int local_10;
  uint local_c;
  undefined4 local_8 [2];
  
  uVar3 = 0;
  if (param_5 != 0) {
    do {
      local_14 = (byte *)(param_4 + uVar3);
      bVar1 = xtra_processCryptoOp(&local_18,&local_c,&local_10,local_8,local_14,param_5 - uVar3);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        return 0x20c;
      }
      uVar2 = local_18;
      if (param_3 <= local_18) {
        uVar2 = param_3;
      }
      uVar2 = display_decodeFormat(param_2,local_14,uVar2);
      if (((int)uVar2 < 0) || ((uVar2 == 0 && (param_3 < local_18)))) {
        *param_1 = uVar3;
        return 0;
      }
      uVar3 = uVar3 + local_18;
    } while (uVar3 < param_5);
  }
  *param_1 = param_5;
  return 0;
}



