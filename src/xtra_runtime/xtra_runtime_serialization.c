int lingo_createVtableObject(); /* FIXUP(C2065): missing forward declaration */
int lingo_createObjectEx(); /* FIXUP(C2065): missing forward declaration */
int xtra_matchStreamInterface(); /* FIXUP(C2065): missing forward declaration */
// Module: xtra_runtime
// Topic: Serialization, byte order, record storage, COM stream I/O, xtra registration
// Address range: 0x6811b7f0 - 0x6811d730
// Functions (69):
//   xtra_insertBufferData (FUN_6811b7f0)
//   xtra_reverseBytes (xtra_reverseBytes)
//   xtra_readBE16 (FUN_6811ba10)
//   xtra_readBE32Ptr
//   xtra_readBE32 (FUN_6811ba60)
//   xtra_skipBytes
//   xtra_allocChunkStorage (xtra_allocChunkStorage)
//   xtra_readChunk
//   xtra_readChunkBlock
//   xtra_compactChunk (xtra_compactChunk)
//   xtra_readSerializedValue
//   xtra_readChunkData (xtra_readChunkData)
//   xtra_readSerializedPtr
//   xtra_readSerializedBlock
//   xtra_getChunkDataPtr (xtra_getChunkDataPtr)
//   xtra_writeValue (xtra_writeValue)
//   xtra_getCurrentValue
//   xtra_validateChunkHandle (xtra_validateChunkHandle)
//   xtra_getWriteValue
//   xtra_byteSwapEndian (xtra_byteSwapEndian)
//   xtra_getTickMicroseconds (xtra_getTickMicroseconds)
//   GetCurrentProcessId
//   xtra_detectSimdLevel (xtra_detectSimdLevel)
//   xtra_negotiateSimdFormat (xtra_negotiateSimdFormat)
//   xtra_measureSimdTransfer (xtra_measureSimdTransfer)
//   xtra_getChunkState
//   xtra_writeChunkEx
//   xtra_matchStreamInterface (xtra_matchStreamInterface)
//   xtra_initComStreamLock (xtra_initComStreamLock)
//   xtra_releaseComStreamLock (xtra_releaseComStreamLock)
//   xtra_loadStringResource (xtra_loadStringResource)
//   xtra_readStreamBytes (xtra_readStreamBytes)
//   xtra_registerStreamFormats (xtra_registerStreamFormats)
//   xtra_initStreamAllocator (xtra_initStreamAllocator)
//   xtra_releaseStreamAllocator (xtra_releaseStreamAllocator)
//   xtra_readStreamSize (xtra_readStreamSize)
//   xtra_writeStreamPadded (xtra_writeStreamPadded)
//   xtra_allocReadBuffer (xtra_allocReadBuffer)
//   xtra_flushReadBuffer (xtra_flushReadBuffer)
//   xtra_freeReadBuffer (xtra_freeReadBuffer)
//   xtra_seekReadPosition (xtra_seekReadPosition)
//   xtra_initReaderVtable (xtra_initReaderVtable)
//   xtra_initSeekVtable (xtra_initSeekVtable)
//   xtra_initRegistrationVtable (xtra_initRegistrationVtable)
//   xtra_destroyReadBuffer (xtra_destroyReadBuffer)
//   xtra_createStreamReader (xtra_createStreamReader)
//   xtra_initReaderFullVtable (xtra_initReaderFullVtable)
//   xtra_createStreamSeeker (xtra_createStreamSeeker)
//   xtra_createStreamRegistrar (xtra_createStreamRegistrar)
//   xtra_createStreamReaderFull (xtra_createStreamReaderFull)
//   xtra_initSerializedReader
//   xtra_initSerializedReaderStub (xtra_initSerializedReaderStub)
//   xtra_initSerializedReaderFail (xtra_initSerializedReaderFail)
//   xtra_createSerializedContext (xtra_createSerializedContext)
//   xtra_registerSerializedXtra (xtra_registerSerializedXtra)
//   xtra_writeChunkExDirect (xtra_writeChunkExDirect)
//   xtra_releaseChunkDirect (xtra_releaseChunkDirect)
//   xtra_initWriterVtable (xtra_initWriterVtable)
//   xtra_initWriterSeekVtable (xtra_initWriterSeekVtable)
//   xtra_createWriteStream (xtra_createWriteStream)
//   xtra_createWriteSeekStream (xtra_createWriteSeekStream)
//   xtra_writeSerializedBlock
//   xtra_initWriterStub (xtra_initWriterStub)
//   xtra_initWriterFail (xtra_initWriterFail)
//   xtra_createWriterContext (xtra_createWriterContext)
//   xtra_registerWriterFormats (xtra_registerWriterFormats)
//   xtra_initWriterStreams (xtra_initWriterStreams)
//   xtra_releaseWriterStreams (xtra_releaseWriterStreams)
//   xtra_getSerializedState

// ============================================================
// Function: xtra_insertBufferData (FUN_6811b7f0)
// Address: 6811b7f0
// Size: 488 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_insertBufferData(int param_1,int param_2,int param_3,int param_4)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int *piVar7;
  undefined4 extraout_ECX;
  undefined4 uVar8;
  undefined4 local_ac [41];
  uint local_8;
  
  if (((param_1 != 0) && (param_2 != 0)) && (0 < param_3)) {
    puVar1 = (undefined4 *)Ordinal_1114(param_1);
    if (puVar1[1] == 0) {
      xtra_appendToBuffer(param_1,local_ac,0);
      xtra_replaceBufferRange(param_1,param_2,param_3,local_ac);
      return 0;
    }
    iVar2 = Ordinal_1117(puVar1,puVar1[1] + 1 + param_3);
    if (iVar2 != 0) {
      iVar3 = Ordinal_1114(*puVar1);
      iVar2 = puVar1[1];
      if (iVar2 != 0) {
        if ((-1 < param_4) && (param_4 < iVar2)) {
          Ordinal_1129(iVar3 + param_4 + param_3,iVar3 + param_4,iVar2 - param_4);
          iVar2 = param_4;
        }
        Ordinal_1129(iVar3 + iVar2,param_2,param_3);
        puVar1[1] = puVar1[1] + param_3;
        *(undefined1 *)(puVar1[1] + iVar3) = 0;
        iVar4 = Ordinal_1154(puVar1[0xd]);
        uVar5 = Ordinal_1157(puVar1[0xd]);
        if (iVar2 == 0) {
          uVar8 = puVar1[0xd];
          iVar2 = 0;
        }
        else {
          uVar8 = puVar1[0xd];
          iVar2 = iVar2 + -1;
        }
        iVar2 = xtra_writeToBuffer(uVar8,iVar2);
        iVar6 = Ordinal_1156(puVar1[0xd],uVar5,iVar2);
        *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + param_3;
        while (iVar2 = iVar2 + 1, iVar2 < iVar4) {
          piVar7 = (int *)Ordinal_1156(puVar1[0xd],uVar5,iVar2);
          *piVar7 = *piVar7 + param_3;
        }
        Ordinal_1158(puVar1[0xd],uVar5);
        xtra_renderTextLine(extraout_ECX,param_3,0,0);
      }
      if (iVar3 != 0) {
        Ordinal_1115(*puVar1);
      }
    }
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: xtra_reverseBytes (xtra_reverseBytes)
// Address: 6811b9e0
// Size: 33 bytes
// Params: undefined1 * param_1, ushort param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall xtra_reverseBytes(undefined1 *param_1,ushort param_2)
{
  int in_EAX;
  undefined1 *puVar1;
  uint uVar2;
  
  uVar2 = (uint)param_2;
  puVar1 = (undefined1 *)(in_EAX + -1 + uVar2);
  if (param_2 != 0) {
    do {
      *param_1 = *puVar1;
      param_1 = param_1 + 1;
      puVar1 = puVar1 + -1;
      uVar2 = uVar2 - 1;
    } while (uVar2 != 0);
  }
  return 0;
}



// ============================================================
// Function: xtra_readBE16 (FUN_6811ba10)
// Address: 6811ba10
// Size: 25 bytes
// Params: undefined1 * param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 xtra_readBE16(undefined1 *param_1)

{
  (*(unsigned short *)((char *)&param_1 + 0)) = CONCAT11(*param_1,param_1[1]);
  return (*(unsigned short *)((char *)&param_1 + 0));
}



// ============================================================
// Function: xtra_readBE32Ptr (xtra_readBE32Ptr)
// Address: 6811ba30
// Size: 40 bytes
// Params: undefined1 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined1 * xtra_readBE32Ptr(undefined1 *param_1)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  undefined1 *puVar3;
  undefined1 *puVar4;
  
  puVar4 = param_1;
  puVar1 = param_1 + 3;
  puVar2 = param_1 + 2;
  puVar3 = param_1 + 1;
  param_1 = (undefined1 *)CONCAT13(*puVar4,CONCAT12(*puVar3,CONCAT11(*puVar2,*puVar1)));
  return param_1;
}



// ============================================================
// Function: xtra_readBE32 (FUN_6811ba60)
// Address: 6811ba60
// Size: 23 bytes
// Params: undefined1 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_readBE32(undefined1 *param_1)
{
  xtra_reverseBytes(param_1,2);
  return 0;
}



// ============================================================
// Function: xtra_skipBytes (FUN_6811ba80)
// Address: 6811ba80
// Size: 23 bytes
// Params: undefined1 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_skipBytes(undefined1 *param_1)
{
  xtra_reverseBytes(param_1,4);
  return 0;
}



// ============================================================
// Function: xtra_allocChunkStorage
// Address: 6811baa0
// Size: 107 bytes
// Params: int param_1, int param_2, int param_3, short param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_allocChunkStorage(int param_1,int param_2,int param_3,short param_4)
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  
  if (param_2 == 0) {
    iVar3 = 0x400;
  }
  else {
    iVar3 = param_2 + 1;
  }
  if (param_3 == 0) {
    param_3 = 0x8000;
  }
  iVar4 = param_1 + 0xc + iVar3 * 4 + param_3;
  piVar1 = (int *)cast_allocHandle(iVar4,1);
  if (piVar1 != (int *)0x0) {
    *(int *)*piVar1 = iVar4;
    *(int *)(*piVar1 + 4) = (int)param_4;
    *(int *)(*piVar1 + 8) = param_1;
    puVar2 = (undefined4 *)(*piVar1 + param_1);
    *puVar2 = 0;
    puVar2[1] = iVar3;
    puVar2[2] = param_3;
    puVar2[3] = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_readChunk (FUN_6811bb10)
// Address: 6811bb10
// Size: 540 bytes
// Params: int * param_1, int param_2, undefined4 param_3, uint param_4
// Return: short
// Calling convention: __stdcall
// ============================================================

short xtra_readChunk(int *param_1,int param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  int local_8;
  
  if ((param_4 & 3) == 0) {
    local_8 = 0;
  }
  else {
    local_8 = 4 - (param_4 & 3);
  }
  iVar1 = param_4 + local_8;
  iVar6 = *param_1;
  iVar3 = *(int *)(iVar6 + 8);
  piVar7 = (int *)(iVar6 + iVar3);
  iVar8 = piVar7[*(int *)(iVar6 + iVar3) + 3];
  iVar6 = param_2 + 1;
  if ((piVar7[1] <= iVar6) || (piVar7[2] <= iVar8 + iVar1)) {
    iVar2 = piVar7[2];
    for (iVar5 = piVar7[1]; iVar5 <= iVar6; iVar5 = (iVar5 * 3) / 2 + 1) {
    }
    for (; iVar2 < iVar8 + iVar1; iVar2 = (iVar2 * 3) / 2 + 1) {
    }
    iVar8 = iVar2 + 0xc + iVar5 * 4 + iVar3;
    cast_resizeHandle((uint)param_1,iVar8,1);
    if ((short)DAT_68195a8c != 0) {
      return (short)DAT_68195a8c;
    }
    *(int *)*param_1 = iVar8;
    piVar7 = (int *)(*param_1 + iVar3);
    iVar8 = piVar7[*piVar7 + 3];
    if (0 < iVar8) {
      Ordinal_1129(piVar7 + iVar5 + 3,piVar7 + piVar7[1] + 3,iVar8);
    }
    piVar7[2] = iVar2;
    piVar7[1] = iVar5;
  }
  iVar5 = *piVar7;
  if (param_2 < iVar5) {
    iVar3 = iVar3 + 0xc + piVar7[1] * 4;
    iVar8 = (piVar7[param_2 + 3] - piVar7[param_2 + 4]) + iVar1;
    if (iVar8 != 0) {
      if (param_2 < *piVar7 + -1) {
        iVar5 = *param_1 + piVar7[param_2 + 4] + iVar3;
        Ordinal_1129(iVar5 + iVar8,iVar5,piVar7[*piVar7 + 3] - piVar7[param_2 + 4]);
      }
      if (iVar6 <= *piVar7) {
        piVar4 = piVar7 + param_2 + 4;
        do {
          *piVar4 = *piVar4 + iVar8;
          iVar6 = iVar6 + 1;
          piVar4 = piVar4 + 1;
        } while (iVar6 <= *piVar7);
      }
    }
    iVar3 = piVar7[param_2 + 3] + *param_1 + iVar3;
    if (0 < iVar1) {
      Ordinal_1129(iVar3,param_3,iVar1 - local_8);
      Ordinal_1130((iVar3 - local_8) + iVar1,local_8);
    }
  }
  else {
    iVar2 = iVar5 + 1;
    *piVar7 = iVar6;
    if (iVar2 < iVar6) {
      piVar4 = piVar7 + iVar5 + 4;
      do {
        *piVar4 = iVar8;
        iVar2 = iVar2 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar2 < *piVar7);
    }
    piVar7[*piVar7 + 3] = iVar8 + iVar1;
    if (0 < iVar1) {
      iVar6 = iVar3 + 0xc + piVar7[1] * 4;
      Ordinal_1129(*param_1 + iVar6 + iVar8,param_3,iVar1 - local_8);
      iVar3 = 0;
      if (0 < local_8) {
        do {
          iVar5 = (*param_1 - local_8) + iVar6 + iVar3;
          iVar3 = iVar3 + 1;
          *(undefined1 *)(iVar5 + iVar8 + iVar1) = 0;
        } while (iVar3 < local_8);
        return 0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_readChunkBlock (FUN_6811bd30)
// Address: 6811bd30
// Size: 272 bytes
// Params: int * param_1, int param_2, uint param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtra_readChunkBlock(int *param_1,int param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  if ((param_3 & 3) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 4 - (param_3 & 3);
  }
  iVar7 = *param_1;
  iVar2 = *(int *)(iVar7 + 8);
  piVar6 = (int *)(iVar7 + iVar2);
  if ((*(int *)(iVar7 + iVar2) <= param_2) || (param_2 < 0)) {
    return 0xffffffff;
  }
  iVar1 = piVar6[1] * 4 + 0xc;
  iVar5 = (piVar6[param_2 + 3] - piVar6[param_2 + 4]) + iVar5 + param_3;
  if (iVar5 != 0) {
    if (0 < iVar5) {
      iVar3 = piVar6[2];
      if (iVar3 <= piVar6[*(int *)(iVar7 + iVar2) + 3] + iVar5) {
        for (; iVar3 < piVar6[*(int *)(iVar7 + iVar2) + 3] + iVar5; iVar3 = (iVar3 * 3) / 2 + 1) {
        }
        iVar7 = iVar1 + iVar3 + iVar2;
        cast_resizeHandle((uint)param_1,iVar7,1);
        if ((ushort)DAT_68195a8c != 0) {
          return (uint)(ushort)DAT_68195a8c;
        }
        *(int *)*param_1 = iVar7;
        piVar6 = (int *)(*param_1 + iVar2);
        piVar6[2] = iVar3;
      }
    }
    if (param_2 < *piVar6 + -1) {
      iVar7 = *param_1 + piVar6[param_2 + 4] + iVar1 + iVar2;
      Ordinal_1129(iVar7 + iVar5,iVar7,piVar6[*piVar6 + 3] - piVar6[param_2 + 4]);
    }
    iVar7 = param_2 + 1;
    if (iVar7 <= *piVar6) {
      piVar4 = piVar6 + param_2 + 4;
      do {
        *piVar4 = *piVar4 + iVar5;
        iVar7 = iVar7 + 1;
        piVar4 = piVar4 + 1;
      } while (iVar7 <= *piVar6);
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_compactChunk
// Address: 6811be50
// Size: 133 bytes
// Params: int * param_1
// Return: short
// Calling convention: __stdcall
// ============================================================

short xtra_compactChunk(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  iVar5 = *param_1;
  iVar1 = *(int *)(iVar5 + 8);
  iVar2 = *(int *)(iVar1 + 4 + iVar5);
  piVar4 = (int *)(iVar1 + iVar5);
  iVar3 = piVar4[*piVar4 + 3];
  iVar6 = *piVar4 + 1;
  if ((iVar2 != iVar6) || (piVar4[2] != iVar3 + 1)) {
    Ordinal_1129(piVar4[3] + 0xc + iVar6 * 4 + *(int *)(iVar5 + 8) + iVar5,
                 piVar4[3] + 0xc + iVar2 * 4 + *(int *)(iVar5 + 8) + iVar5,iVar3);
    iVar5 = iVar3 + 0xc + iVar6 * 4 + iVar1;
    cast_resizeHandle((uint)param_1,iVar5,1);
    if ((short)DAT_68195a8c != 0) {
      return (short)DAT_68195a8c;
    }
    *(int *)*param_1 = iVar5;
    iVar5 = *param_1;
    *(int *)(iVar5 + iVar1 + 4) = iVar6;
    *(int *)(iVar5 + iVar1 + 8) = iVar3;
  }
  return 0;
}



// ============================================================
// Function: xtra_readSerializedValue (FUN_6811bee0)
// Address: 6811bee0
// Size: 57 bytes
// Params: int * param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_readSerializedValue(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 in_EAX;
  undefined2 uVar2;
  uint uVar1;
  undefined2 extraout_var;
  
  uVar2 = (undefined2)((uint)in_EAX >> 0x10);
  if (param_3 != (undefined4 *)0x0) {
    Ordinal_1114(param_3);
    uVar1 = Ordinal_1116(param_3);
    xtra_readChunk(param_1,param_2,*param_3,uVar1);
    Ordinal_1115(param_3);
    uVar2 = extraout_var;
  }
  return CONCAT22(uVar2,(undefined2)DAT_68195a8c);
}



// ============================================================
// Function: xtra_readChunkData
// Address: 6811bf20
// Size: 88 bytes
// Params: int * param_1, int param_2, undefined4 param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_readChunkData(int *param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *param_1;
  iVar3 = *(int *)(iVar2 + 8);
  iVar1 = iVar3 + iVar2;
  if ((param_2 < *(int *)(iVar3 + iVar2)) && (-1 < param_2)) {
    iVar4 = *(int *)(iVar1 + 0xc + param_2 * 4);
    iVar5 = *(int *)(iVar1 + 0x10 + param_2 * 4) - iVar4;
    if (iVar5 < param_4) {
      param_4 = iVar5;
    }
    Ordinal_1129(param_3,iVar2 + iVar4 + 0xc + *(int *)(iVar1 + 4) * 4 + iVar3,param_4);
    return param_4;
  }
  return 0;
}



// ============================================================
// Function: xtra_readSerializedPtr (FUN_6811bf80)
// Address: 6811bf80
// Size: 100 bytes
// Params: int * param_1, int param_2
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * xtra_readSerializedPtr(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined4 *puVar5;
  int iVar6;
  
  iVar1 = *(int *)(*param_1 + 8);
  piVar4 = (int *)(*param_1 + iVar1);
  puVar5 = (undefined4 *)0x0;
  if ((param_2 < *piVar4) && (-1 < param_2)) {
    iVar2 = piVar4[param_2 + 3];
    iVar3 = piVar4[1];
    iVar6 = piVar4[param_2 + 4] - iVar2;
    if (0 < iVar6) {
      puVar5 = (undefined4 *)cast_allocHandle(iVar6,1);
      if (puVar5 != (undefined4 *)0x0) {
        Ordinal_1129(*puVar5,*param_1 + iVar2 + 0xc + iVar3 * 4 + iVar1,iVar6);
      }
    }
    return puVar5;
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: xtra_readSerializedBlock (FUN_6811bff0)
// Address: 6811bff0
// Size: 48 bytes
// Params: undefined4 * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_readSerializedBlock(undefined4 *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  
  piVar1 = (int *)*param_1;
  piVar3 = (int *)(piVar1[2] + (int)piVar1);
  if ((((*piVar3 <= param_2) || (param_2 < 0)) ||
      (iVar2 = piVar3[param_2 + 4] - piVar3[param_2 + 3], *piVar1 < iVar2)) || (iVar2 < 0)) {
    iVar2 = 0;
  }
  return iVar2;
}



// ============================================================
// Function: xtra_getChunkDataPtr
// Address: 6811c020
// Size: 80 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_getChunkDataPtr(undefined4 *param_1,int param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  
  puVar1 = (uint *)*param_1;
  piVar2 = (int *)(puVar1[2] + (int)puVar1);
  if ((*piVar2 <= param_2) || (param_2 < 0)) {
    return 0;
  }
  iVar3 = piVar2[param_2 + 4] - piVar2[param_2 + 3];
  if (((param_3 <= iVar3) && (iVar3 <= (int)*puVar1)) &&
     (iVar3 = piVar2[param_2 + 3] + 0xc + piVar2[1] * 4, puVar1[2] + iVar3 < *puVar1)) {
    return (int)piVar2 + iVar3;
  }
  return 0;
}



// ============================================================
// Function: xtra_writeValue (xtra_writeValue)
// Address: 6811c070
// Size: 22 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_writeValue(undefined4 *param_1,int param_2)
{
  xtra_getChunkDataPtr(param_1,param_2,0);
  return 0;
}



// ============================================================
// Function: xtra_getCurrentValue (FUN_6811c090)
// Address: 6811c090
// Size: 18 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getCurrentValue(int *param_1)

{
  return *(undefined4 *)(*param_1 + *(int *)(*param_1 + 8));
}



// ============================================================
// Function: xtra_validateChunkHandle
// Address: 6811c0b0
// Size: 86 bytes
// Params: int * param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool xtra_validateChunkHandle(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = Ordinal_1116(param_1);
  piVar1 = (int *)*param_1;
  iVar2 = *piVar1;
  if ((((-1 < iVar2) && (iVar3 = piVar1[2], -1 < iVar3)) && (iVar2 <= iVar4)) && (iVar3 < iVar4)) {
    if (param_2 == 1) {
      return true;
    }
    iVar4 = *(int *)(iVar3 + (int)piVar1);
    if ((-1 < iVar4) && (iVar4 <= *(int *)(iVar3 + 4 + (int)piVar1))) {
      return *(int *)(iVar3 + 8 + (int)piVar1) + 0x10 + iVar4 * 4 <= iVar2;
    }
  }
  return false;
}



// ============================================================
// Function: xtra_getWriteValue (FUN_6811c110)
// Address: 6811c110
// Size: 204 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getWriteValue(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int local_8;
  
  iVar4 = 0;
  local_8 = 0;
  uVar2 = cast_freeIfNonNull(*(undefined4 *)*param_1);
  *(undefined4 *)*param_1 = uVar2;
  uVar2 = cast_freeIfNonNull(*(undefined4 *)(*param_1 + 8));
  *(undefined4 *)(*param_1 + 8) = uVar2;
  uVar2 = cast_freeIfNonNull(*(undefined4 *)(*param_1 + 4));
  *(undefined4 *)(*param_1 + 4) = uVar2;
  bVar1 = xtra_validateChunkHandle(param_1,1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    return 0;
  }
  piVar5 = (int *)(*(int *)(*param_1 + 8) + *param_1);
  iVar3 = cast_freeIfNonNull(*piVar5);
  *piVar5 = iVar3;
  iVar3 = cast_freeIfNonNull(piVar5[1]);
  piVar5[1] = iVar3;
  iVar3 = cast_freeIfNonNull(piVar5[2]);
  piVar5[2] = iVar3;
  bVar1 = xtra_validateChunkHandle(param_1,0);
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    return 0;
  }
  if (-1 < *piVar5) {
    piVar6 = piVar5 + 3;
    do {
      iVar3 = cast_freeIfNonNull(*piVar6);
      *piVar6 = iVar3;
      if (iVar3 < 0) {
        return 0;
      }
      if (piVar5[2] < iVar3) {
        return 0;
      }
      if (iVar3 < local_8) {
        return 0;
      }
      iVar4 = iVar4 + 1;
      piVar6 = piVar6 + 1;
      local_8 = iVar3;
    } while (iVar4 <= *piVar5);
  }
  return 1;
}



// ============================================================
// Function: xtra_byteSwapEndian
// Address: 6811c1e0
// Size: 140 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_byteSwapEndian(int *param_1)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar4 = (int *)(*(int *)(*param_1 + 8) + *param_1);
  iVar3 = 0;
  if (-1 < *piVar4) {
    piVar5 = piVar4 + 3;
    do {
      iVar1 = cast_freeIfNonNull(*piVar5);
      *piVar5 = iVar1;
      iVar3 = iVar3 + 1;
      piVar5 = piVar5 + 1;
    } while (iVar3 <= *piVar4);
  }
  iVar3 = cast_freeIfNonNull(*piVar4);
  *piVar4 = iVar3;
  iVar3 = cast_freeIfNonNull(piVar4[1]);
  piVar4[1] = iVar3;
  iVar3 = cast_freeIfNonNull(piVar4[2]);
  piVar4[2] = iVar3;
  uVar2 = cast_freeIfNonNull(*(undefined4 *)(*param_1 + 8));
  *(undefined4 *)(*param_1 + 8) = uVar2;
  uVar2 = cast_freeIfNonNull(*(undefined4 *)*param_1);
  *(undefined4 *)*param_1 = uVar2;
  uVar2 = cast_freeIfNonNull(*(undefined4 *)(*param_1 + 4));
  *(undefined4 *)(*param_1 + 4) = uVar2;
  return 0;
}



// ============================================================
// Function: xtra_getTickMicroseconds
// Address: 6811c270
// Size: 36 bytes
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 xtra_getTickMicroseconds(void)

{
  DWORD DVar1;
  float10 fVar2;
  
  DVar1 = GetTickCount();
  fVar2 = (float10)(int)DVar1;
  if ((int)DVar1 < 0) {
    fVar2 = fVar2 + (float10)4294967296.0;
  }
  return fVar2 * (float10)1000.0;
}



// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: xtra_detectSimdLevel
// Address: 6811c2b0
// Size: 133 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_detectSimdLevel(void)

{
  undefined4 uVar1;
  uint extraout_EDX;
  
  Ordinal_1253();
  if ((extraout_EDX & 0x400000) != 0) {
    return 1;
  }
  if ((extraout_EDX & 0x800000) != 0) {
    return 2;
  }
  if ((extraout_EDX & 0x200000) != 0) {
    return 3;
  }
  if ((extraout_EDX & 0x20000000) != 0) {
    return 4;
  }
  uVar1 = 5;
  if ((extraout_EDX & 0x10000000) == 0) {
    uVar1 = 6;
  }
  return uVar1;
}



// ============================================================
// Function: xtra_negotiateSimdFormat
// Address: 6811c340
// Size: 194 bytes
// Params: int param_1, int param_2, undefined4 param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_negotiateSimdFormat(int param_1,int param_2,undefined4 param_3,int *param_4)

{
  int in_EAX;
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int unaff_EBX;
  undefined4 uVar4;
  
  uVar4 = 0;
  uVar1 = Ordinal_1258();
  uVar2 = xtra_getTextLineHeight(param_1,unaff_EBX + in_EAX);
  Ordinal_1259(uVar2);
  Ordinal_1252(param_2 + unaff_EBX + in_EAX,param_3);
  iVar3 = xtra_detectSimdLevel();
  Ordinal_1259(uVar1);
  if ((iVar3 != 5) && (iVar3 != 4)) {
    switch(*param_4) {
    default:
switchD_6811c39a_caseD_0:
      *param_4 = iVar3;
      return 0;
    case 1:
      goto switchD_6811c3e7_switchD;
    case 3:
      switch(iVar3) {
      case 1:
        goto switchD_6811c39a_caseD_0;
      case 2:
      case 3:
      case 6:
        break;
      default:
        goto switchD_6811c3c9_caseD_4;
      }
    case 4:
      switch(iVar3) {
      case 1:
        goto switchD_6811c39a_caseD_0;
      case 2:
      case 3:
      case 6:
        break;
      default:
        goto switchD_6811c3c9_caseD_4;
      }
    case 6:
      switch(iVar3) {
      case 1:
      case 3:
        break;
      case 2:
      case 6:
        goto switchD_6811c39a_caseD_0;
      default:
        goto switchD_6811c3c9_caseD_4;
      }
    }
  }
switchD_6811c3c9_caseD_1:
  uVar4 = 1;
  goto switchD_6811c3c9_caseD_4;
switchD_6811c3e7_switchD:
  switch(iVar3) {
  case 1:
    goto switchD_6811c39a_caseD_0;
  case 2:
  case 3:
  case 6:
    goto switchD_6811c3c9_caseD_1;
  default:
switchD_6811c3c9_caseD_4:
    *param_4 = iVar3;
    return uVar4;
  }
}



// ============================================================
// Function: xtra_measureSimdTransfer
// Address: 6811c480
// Size: 267 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int * param_5, int * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_measureSimdTransfer(int param_1,int param_2,int param_3,int param_4,int *param_5,int *param_6)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_c;
  undefined4 local_8;
  
  iVar5 = param_4;
  iVar4 = 0;
  local_c = 0;
  local_8 = 0;
  if (0 < param_4) {
    do {
      iVar1 = xtra_negotiateSimdFormat(param_1,param_2,&param_4,&local_c);
      if (iVar1 != 0) {
        if (local_c == 5) {
          *param_5 = param_4 + iVar4;
          local_8 = 1;
          break;
        }
        *param_5 = iVar4;
      }
      iVar4 = iVar4 + param_4;
    } while (iVar4 < iVar5);
  }
  iVar5 = *param_5;
  if (iVar5 < 1) {
    *param_6 = iVar5;
    return local_8;
  }
  iVar1 = param_2 + param_3;
  iVar4 = iVar1 + iVar5;
  while( true ) {
    param_5 = (int *)Ordinal_1258();
    uVar2 = xtra_getTextLineHeight(param_1,iVar5 + param_3);
    Ordinal_1259(uVar2);
    Ordinal_1251(iVar1,iVar4,&param_4);
    iVar5 = iVar5 - param_4;
    iVar4 = iVar1 + iVar5;
    Ordinal_1252(iVar4,&param_4);
    Ordinal_1259(param_5);
    iVar3 = xtra_detectSimdLevel();
    if ((iVar3 != 5) && (iVar3 != 4)) break;
    if (iVar5 < 1) {
      *param_6 = iVar5;
      return local_8;
    }
  }
  *param_6 = iVar5 + param_4;
  return local_8;
}



// ============================================================
// Function: xtra_getChunkState (FUN_6811c5a0)
// Address: 6811c5a0
// Size: 71 bytes
// Params: int param_1
// Return: LONG
// Calling convention: __stdcall
// ============================================================

LONG xtra_getChunkState(int param_1)

{
  int *piVar1;
  LONG LVar2;
  
  LVar2 = InterlockedDecrement((LONG *)(param_1 + 8));
  piVar1 = *(int **)(param_1 + 4);
  if (LVar2 == 0) {
    (**(code **)(*(int *)piVar1[3] + 0x10))((int *)piVar1[3],param_1);
    DAT_68196964 = DAT_68196964 + -1;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*piVar1 + 8))(piVar1);
  return LVar2;
}



// ============================================================
// Function: xtra_writeChunkEx (FUN_6811c5f0)
// Address: 6811c5f0
// Size: 98 bytes
// Params: int * param_1, undefined4 param_2, undefined * param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 *
xtra_writeChunkEx(int *param_1,undefined4 param_2,undefined *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)param_1[3] + 0xc))((int *)param_1[3],param_2);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_4;
    puVar1[1] = param_1;
    puVar1[2] = 1;
    (**(code **)(*param_1 + 4))(param_1);
    (**(code **)(*param_1 + 4))(param_1);
    DAT_68196964 = DAT_68196964 + 1;
    uVar2 = (*(code *)param_3)(puVar1);
    *param_5 = uVar2;
    return puVar1;
  }
  *param_5 = 0x80040002;
  return (undefined4 *)0x0;
}



// ============================================================
// Function: xtra_matchStreamInterface
// Address: 6811c670
// Size: 46 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
xtra_matchStreamInterface(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5,undefined4 *param_6)

{
  int iVar1;
  
  iVar1 = Ordinal_2066(param_3,*param_6);
  if (iVar1 != 0) {
    param_6[1] = param_5;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: xtra_initComStreamLock
// Address: 6811c6a0
// Size: 66 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_initComStreamLock(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = Ordinal_1510();
  if (iVar1 != 0) {
    uVar2 = Ordinal_1515();
    *param_2 = uVar2;
    uVar2 = Ordinal_1512(iVar1);
    *param_1 = uVar2;
    *param_3 = iVar1;
    return 0;
  }
  return 0x80040008;
}



// ============================================================
// Function: xtra_releaseComStreamLock
// Address: 6811c6f0
// Size: 30 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_releaseComStreamLock(void)
{
  int in_EAX;
  undefined1 local_8 [4];
  
  if (in_EAX != 0) {
    Ordinal_1513();
    Ordinal_1514(local_8);
  }
  return 0;
}



// ============================================================
// Function: xtra_loadStringResource
// Address: 6811c710
// Size: 16 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall xtra_loadStringResource(undefined4 param_1,undefined4 param_2)
{
  short in_AX;
  
  Ordinal_1517(DAT_681956e0,param_2,param_1,(int)in_AX);
  return 0;
}



// ============================================================
// Function: xtra_readStreamBytes
// Address: 6811c720
// Size: 69 bytes
// Params: uint * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_readStreamBytes(uint *param_1)
{
  int iVar1;
  int *unaff_EBX;
  uint uVar2;
  int iVar3;
  char local_5;
  
  uVar2 = 0;
  iVar3 = 1;
  do {
    iVar1 = (**(code **)(*unaff_EBX + 0x14))();
    if (iVar1 != 0) {
      return 0;
    }
    iVar3 = iVar3 + 1;
    uVar2 = uVar2 >> 8 | (int)local_5 << 0x18;
  } while (iVar3 < 5);
  *param_1 = uVar2;
  return 0;
}



// ============================================================
// Function: xtra_registerStreamFormats
// Address: 6811c770
// Size: 356 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_registerStreamFormats(undefined4 param_1,int *param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 local_54;
  undefined4 local_50;
  int *local_4c;
  undefined1 local_48 [64];
  uint local_8;
  
  local_50 = 0;
  local_54 = FOURCC_FXmp;
  iVar1 = (**(code **)(*param_2 + 0x1c))(param_2,param_3,&DAT_681764e8,&DAT_68175e28,&local_4c);
  if (iVar1 == 0) {
    xtra_loadStringResource(local_48,0x14b4);
    iVar1 = (**(code **)(*local_4c + 0x18))(local_4c,9,local_48,0,&DAT_6817c8e8);
    if (iVar1 == 0) {
      iVar1 = (**(code **)(*local_4c + 0x18))(local_4c,3,&local_50,0,"Speed");
      if (iVar1 == 0) {
        iVar1 = (**(code **)(*local_4c + 0x18))(local_4c,8,&DAT_681764f8,0x10,"Formats");
        if (iVar1 == 0) {
          iVar1 = (**(code **)(*local_4c + 0x18))(local_4c,8,&local_54,4,"DirTypes");
          if (iVar1 == 0) {
            iVar1 = (**(code **)(*param_2 + 0x1c))
                              (param_2,param_3,&DAT_681764e8,&DAT_68175e08,&local_4c);
            if (iVar1 == 0) {
              xtra_loadStringResource(local_48,0x14b5);
              iVar1 = (**(code **)(*local_4c + 0x18))(local_4c,9,local_48,0,&DAT_6817c8e8);
              if (iVar1 == 0) {
                iVar1 = (**(code **)(*local_4c + 0x18))(local_4c,3,&local_50,0,"Speed");
                if (iVar1 == 0) {
                  (**(code **)(*local_4c + 0x18))(local_4c,8,&DAT_68175de8,0x10,"Formats");
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_initStreamAllocator
// Address: 6811c8e0
// Size: 42 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_initStreamAllocator(int param_1)
{
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  (**(code **)**(undefined4 **)(param_1 + 8))
            (*(undefined4 **)(param_1 + 8),&DAT_68175b98,(undefined4 *)(param_1 + 0x20));
  return 0;
}



// ============================================================
// Function: xtra_releaseStreamAllocator
// Address: 6811c910
// Size: 60 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_releaseStreamAllocator(int param_1)
{
  int *piVar1;
  
  if (*(int *)(param_1 + 0x24) != 0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 0x14))
              (*(int **)(param_1 + 0x20),*(int *)(param_1 + 0x24));
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_readStreamSize
// Address: 6811c950
// Size: 39 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_readStreamSize(int param_1)
{
  xtra_readStreamBytes((uint *)(*(int *)(param_1 + 4) + 0x1c));
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x18) = 0;
  return 0;
}



// ============================================================
// Function: xtra_writeStreamPadded
// Address: 6811c980
// Size: 248 bytes
// Params: uint param_1, undefined4 param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_writeStreamPadded(uint param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int local_10;
  int local_c;
  uint local_8;
  
  uVar3 = param_1;
  uVar2 = *(uint *)(*(int *)(param_1 + 4) + 0x18);
  local_c = 0;
  iVar5 = xtra_initComStreamLock(&local_10,&param_1,&local_c);
  piVar4 = param_3;
  if (iVar5 == 0) {
    if (*(uint *)(*(int *)(uVar3 + 4) + 0x18) < param_1) {
      iVar5 = *(int *)(*(int *)(uVar3 + 4) + 0x18);
      param_1 = param_1 - iVar5;
      iVar5 = (**(code **)(*param_3 + 0x1c))(param_3,iVar5 + local_10,param_1,&local_8);
      piVar1 = (int *)(*(int *)(uVar3 + 4) + 0x18);
      *piVar1 = *piVar1 + local_8;
      if ((iVar5 != 0) || (local_8 < param_1)) {
        if (local_8 != 0) {
          iVar5 = 0;
        }
        goto LAB_6811ca52;
      }
    }
    for (param_3 = (int *)(*(int *)(*(int *)(uVar3 + 4) + 0x1c) -
                          *(int *)(*(int *)(uVar3 + 4) + 0x18)); 0 < (int)param_3;
        param_3 = (int *)((int)param_3 + -1)) {
      param_1 = CONCAT13(0x20,(undefined3)param_1);
      iVar5 = (**(code **)(*piVar4 + 0x1c))(piVar4,(int)&param_1 + 3,1,&local_8);
      piVar1 = (int *)(*(int *)(uVar3 + 4) + 0x18);
      *piVar1 = *piVar1 + local_8;
      if ((iVar5 != 0) || (local_8 == 0)) {
        if (uVar2 < *(uint *)(*(int *)(uVar3 + 4) + 0x18)) {
          iVar5 = 0;
        }
        goto LAB_6811ca52;
      }
    }
    iVar5 = -0x7ffbfbb4;
  }
LAB_6811ca52:
  if (local_c != 0) {
    xtra_releaseComStreamLock();
  }
  return iVar5;
}



// ============================================================
// Function: xtra_allocReadBuffer
// Address: 6811ca80
// Size: 58 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_allocReadBuffer(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = *(int *)(param_1 + 4);
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x2c) = 0;
  iVar2 = (**(code **)(**(int **)(iVar1 + 0x20) + 0xc))(*(int **)(iVar1 + 0x20),0x8000);
  *(int *)(iVar1 + 0x24) = iVar2;
  uVar3 = 0x80040002;
  if (iVar2 != 0) {
    uVar3 = 0;
  }
  return uVar3;
}



// ============================================================
// Function: xtra_flushReadBuffer
// Address: 6811cac0
// Size: 194 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_flushReadBuffer(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  iVar2 = *(int *)(param_1 + 4);
  piVar3 = *(int **)(iVar2 + 0x20);
  iVar4 = (**(code **)(*piVar3 + 0x20))(piVar3,*(undefined4 *)(iVar2 + 0x24));
  piVar1 = (int *)(iVar2 + 0x2c);
  do {
    if (*piVar1 != 0) {
      iVar5 = (**(code **)(*param_3 + 0x1c))
                        (param_3,*(int *)(iVar2 + 0x28) + iVar4,*piVar1,&param_1);
      *piVar1 = *piVar1 - param_1;
      *(int *)(iVar2 + 0x28) = *(int *)(iVar2 + 0x28) + param_1;
      if (iVar5 != 0) break;
      if (*piVar1 != 0) goto LAB_6811cb68;
    }
    *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + *(int *)(iVar2 + 0x28);
    *(undefined4 *)(iVar2 + 0x28) = 0;
    iVar5 = (**(code **)(*param_2 + 0x14))(param_2,iVar4,0x8000,piVar1);
  } while (*piVar1 != 0);
  if (iVar5 == -0x7ffbffac) {
    iVar5 = (-(uint)(*piVar1 != 0) & 0x7ffbfbb4) + 0x8004044c;
  }
  else if (iVar5 == -0x7ffbed20) {
    iVar5 = 0;
  }
LAB_6811cb68:
  (**(code **)(*piVar3 + 0x24))(piVar3,*(undefined4 *)(iVar2 + 0x24));
  return iVar5;
}



// ============================================================
// Function: xtra_freeReadBuffer
// Address: 6811cb90
// Size: 42 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_freeReadBuffer(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 0x20);
  (**(code **)(*piVar1 + 0x14))(piVar1,*(undefined4 *)(*(int *)(param_1 + 4) + 0x24));
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x24) = 0;
  return 0;
}



// ============================================================
// Function: xtra_seekReadPosition
// Address: 6811cbc0
// Size: 99 bytes
// Params: int param_1, int * param_2, undefined4 param_3, int param_4, undefined4 * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_seekReadPosition(int param_1,int *param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar1 = param_4 - *(int *)(iVar2 + 0x18);
  if ((uint)(*(int *)(iVar2 + 0x2c) + *(int *)(iVar2 + 0x28)) < uVar1) {
    *(int *)(iVar2 + 0x18) = *(int *)(iVar2 + 0x18) + uVar1;
    iVar2 = (**(code **)(*param_2 + 0x24))(param_2,*(undefined4 *)(*(int *)(param_1 + 4) + 0x18));
    if (iVar2 != 0) {
      return iVar2;
    }
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x28) = 0;
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x2c) = 0;
  }
  else {
    *(int *)(iVar2 + 0x2c) = *(int *)(iVar2 + 0x2c) + (*(int *)(iVar2 + 0x28) - uVar1);
    *(uint *)(*(int *)(param_1 + 4) + 0x28) = uVar1;
  }
  if (param_5 != (undefined4 *)0x0) {
    *param_5 = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_initReaderVtable
// Address: 6811cc30
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * xtra_initReaderVtable(void)

{
  if (DAT_68196960 == '\0') {
    DAT_68196960 = '\x01';
    _DAT_68198a80 = media_invokeCallback;
    _DAT_68198a84 = media_addRef;
    _DAT_68198a88 = xtra_getChunkState;
    _DAT_68198a8c = xtra_readStreamSize;
    _DAT_68198a90 = xtra_writeStreamPadded;
    _DAT_68198a94 = core_returnZeroStub;
    _DAT_68198a98 = lingo_noop;
  }
  return &DAT_68198a80;
}



// ============================================================
// Function: xtra_initSeekVtable
// Address: 6811cc90
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * xtra_initSeekVtable(void)

{
  if (DAT_68196962 == '\0') {
    DAT_68196962 = '\x01';
    _DAT_68198a20 = media_invokeCallback;
    _DAT_68198a24 = media_addRef;
    _DAT_68198a28 = xtra_getChunkState;
    _DAT_68198a2c = xtra_seekReadPosition;
  }
  return &DAT_68198a20;
}



// ============================================================
// Function: xtra_initRegistrationVtable
// Address: 6811ccd0
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * xtra_initRegistrationVtable(void)

{
  if (DAT_68196963 == '\0') {
    DAT_68196963 = '\x01';
    _DAT_68198a60 = media_invokeCallback;
    _DAT_68198a64 = media_addRef;
    _DAT_68198a68 = xtra_getChunkState;
    _DAT_68198a6c = xtra_registerStreamFormats;
  }
  return &DAT_68198a60;
}



// ============================================================
// Function: xtra_destroyReadBuffer
// Address: 6811cd10
// Size: 16 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_destroyReadBuffer(int param_1)
{
  xtra_freeReadBuffer(param_1);
  return 0;
}



// ============================================================
// Function: xtra_createStreamReader
// Address: 6811cd20
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_createStreamReader(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = xtra_initReaderVtable();
  piVar3 = xtra_writeChunkEx(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: xtra_initReaderFullVtable
// Address: 6811cd80
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * xtra_initReaderFullVtable(void)

{
  if (DAT_68196961 == '\0') {
    DAT_68196961 = '\x01';
    _DAT_68198a40 = media_invokeCallback;
    _DAT_68198a44 = media_addRef;
    _DAT_68198a48 = xtra_getChunkState;
    _DAT_68198a4c = xtra_allocReadBuffer;
    _DAT_68198a50 = xtra_flushReadBuffer;
    _DAT_68198a54 = xtra_destroyReadBuffer;
    _DAT_68198a58 = xtra_freeReadBuffer;
  }
  return &DAT_68198a40;
}



// ============================================================
// Function: xtra_createStreamSeeker
// Address: 6811cde0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_createStreamSeeker(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = xtra_initSeekVtable();
  piVar3 = xtra_writeChunkEx(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: xtra_createStreamRegistrar
// Address: 6811ce40
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_createStreamRegistrar(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = xtra_initRegistrationVtable();
  piVar3 = xtra_writeChunkEx(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: xtra_createStreamReaderFull
// Address: 6811cea0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_createStreamReaderFull(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = xtra_initReaderFullVtable();
  piVar3 = xtra_writeChunkEx(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
}



// ============================================================
// Function: xtra_initSerializedReader (FUN_6811cf00)
// Address: 6811cf00
// Size: 197 bytes
// Params: undefined * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_initSerializedReader(undefined *param_1)

{
  int in_EAX;
  int iVar1;
  code *unaff_EBX;
  int iVar2;
  
  iVar2 = 0;
  if ((in_EAX == 0) || (iVar1 = Ordinal_2066(), iVar1 != 0)) {
    if ((param_1 != (undefined *)0x0) &&
       (iVar2 = (*(code *)param_1)(&DAT_681764e8,1,0x30,xtra_initStreamAllocator,xtra_releaseStreamAllocator), iVar2 != 0)) {
      return iVar2;
    }
    iVar2 = 0;
    if ((((unaff_EBX != (code *)0x0) &&
         (iVar2 = (*unaff_EBX)(&DAT_681764e8,1,&DAT_68175bc8,1,xtra_createStreamRegistrar), iVar2 == 0)) &&
        (iVar2 = (*unaff_EBX)(&DAT_681764e8,1,&DAT_68175e28,1,xtra_createStreamReader), iVar2 == 0)) &&
       (iVar2 = (*unaff_EBX)(&DAT_681764e8,1,&DAT_68175e08,1,xtra_createStreamReaderFull), iVar2 == 0)) {
      iVar2 = (*unaff_EBX)(&DAT_681764e8,1,&DAT_68175e38,1,xtra_createStreamSeeker);
    }
  }
  return iVar2;
}



// ============================================================
// Function: xtra_initSerializedReaderStub
// Address: 6811cfd0
// Size: 70 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_initSerializedReaderStub(void)

{
  xtra_initSerializedReader(lingo_createVtableObject);
  return 0x80040005;
}



// ============================================================
// Function: xtra_initSerializedReaderFail
// Address: 6811d020
// Size: 75 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x6811d050) */

undefined4 xtra_initSerializedReaderFail(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  xtra_initSerializedReader((undefined *)0x0);
  return 0x80040004;
}



// ============================================================
// Function: xtra_createSerializedContext
// Address: 6811d070
// Size: 207 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_createSerializedContext(int *param_1,undefined4 *param_2)

{
  undefined4 *puVar1;
  
  xtra_initSerializedReader(lingo_setVtableSlot);
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0xc))(param_1,0x28);
  *param_2 = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0x80040002;
  }
  xtra_initSerializedReader(lingo_setVtableSlot);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  return 0;
}



// ============================================================
// Function: xtra_registerSerializedXtra
// Address: 6811d140
// Size: 41 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_registerSerializedXtra(undefined4 param_1)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  Ordinal_2071(param_1,&LAB_6811d1e0,xtra_initSerializedReaderFail,xtra_initSerializedReaderStub,&LAB_6811c660,xtra_createSerializedContext);
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_writeChunkExDirect
// Address: 6811d170
// Size: 98 bytes
// Params: int * param_1, undefined4 param_2, undefined * param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 *
xtra_writeChunkExDirect(int *param_1,undefined4 param_2,undefined *param_3,undefined4 param_4,
            undefined4 *param_5)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)(**(code **)(*(int *)param_1[3] + 0xc))((int *)param_1[3],param_2);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_4;
    puVar1[1] = param_1;
    puVar1[2] = 1;
    (**(code **)(*param_1 + 4))(param_1);
    (**(code **)(*param_1 + 4))(param_1);
    DAT_6819696c = DAT_6819696c + 1;
    uVar2 = (*(code *)param_3)(puVar1);
    *param_5 = uVar2;
    return puVar1;
  }
  *param_5 = 0x80040002;
  return (undefined4 *)0x0;
}



// ============================================================
// Function: xtra_releaseChunkDirect
// Address: 6811d200
// Size: 71 bytes
// Params: int param_1
// Return: LONG
// Calling convention: __stdcall
// ============================================================

LONG xtra_releaseChunkDirect(int param_1)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int *piVar1;
  LONG LVar2;
  
  LVar2 = InterlockedDecrement((LONG *)(param_1 + 8));
  piVar1 = *(int **)(param_1 + 4);
  if (LVar2 == 0) {
    (**(code **)(*(int *)piVar1[3] + 0x10))((int *)piVar1[3],param_1);
    DAT_6819696c = DAT_6819696c + -1;
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  (**(code **)(*piVar1 + 8))(piVar1);
  return LVar2;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_initWriterVtable
// Address: 6811d250
// Size: 92 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * xtra_initWriterVtable(void)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  if (DAT_68196968 == '\0') {
    DAT_68196968 = '\x01';
    _DAT_68198a00 = media_invokeCallback;
    _DAT_68198a04 = media_addRef;
    _DAT_68198a08 = xtra_releaseChunkDirect;
    _DAT_68198a0c = xtraRuntime_initDecompressor;
    _DAT_68198a10 = xtraRuntime_decompressBlock;
    _DAT_68198a14 = xtraRuntime_cleanupDecompressor;
    _DAT_68198a18 = xtra_getSerializedState;
  }
  return &DAT_68198a00;
#endif
  return (undefined *)0; /* FIXUP(STUB): null return */
}



// ============================================================
// Function: xtra_initWriterSeekVtable
// Address: 6811d2b0
// Size: 62 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined * xtra_initWriterSeekVtable(void)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  if (DAT_68196969 == '\0') {
    DAT_68196969 = '\x01';
    _DAT_681989f0 = media_invokeCallback;
    _DAT_681989f4 = media_addRef;
    _DAT_681989f8 = xtra_releaseChunkDirect;
    _DAT_681989fc = xtra_registerWriterFormats;
  }
  return &DAT_681989f0;
#endif
  return (undefined *)0; /* FIXUP(STUB): null return */
}



// ============================================================
// Function: xtra_createWriteStream
// Address: 6811d2f0
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_createWriteStream(int *param_1,undefined4 *param_2)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = xtra_initWriterVtable();
  piVar3 = xtra_writeChunkExDirect(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_createWriteSeekStream
// Address: 6811d350
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_createWriteSeekStream(int *param_1,undefined4 *param_2)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int iVar1;
  undefined *puVar2;
  int *piVar3;
  int local_8;
  
  piVar3 = &local_8;
  local_8 = 0;
  puVar2 = xtra_initWriterSeekVtable();
  piVar3 = xtra_writeChunkExDirect(param_1,0xc,lingo_noop,puVar2,piVar3);
  iVar1 = local_8;
  if (piVar3 != (int *)0x0) {
    if (local_8 != 0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      piVar3 = (int *)0x0;
    }
    *param_2 = piVar3;
    return iVar1;
  }
  *param_2 = 0;
  return -0x7ffbfffe;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_writeSerializedBlock (FUN_6811d3b0)
// Address: 6811d3b0
// Size: 141 bytes
// Params: void * this, undefined * param_1
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall xtra_writeSerializedBlock(void *this,undefined *param_1)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int in_EAX;
  int iVar1;
  int iVar2;
  /* FIXUP(C2064: term does not evaluate to a function taking 0 arguments):  */
  iVar2 = 0;
  /* FIXUP(C2059-ctx): if ((in_EAX == 0) || (iVar1 = Ordinal_2066(), iVar1 != 0)) { */
    /* FIXUP(C2059-ctx): if ((this != (void *)0x0) && */
       /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: ')'): /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: ')'): /* FIXUP(C2064: term does not evaluate to a function taking 0 arguments): (iVar2 = (*(int *)(size_t)this /* FIXUP(C2100): cast for dereference */)(&DAT_68175dd8,1,0x3c,xtra_initWriterStreams,xtra_releaseWriterStreams), iVar2 != 0)) { */ */ */
      return iVar2;
    }
    iVar2 = 0;
    if ((param_1 != (undefined *)0x0) &&
       (iVar2 = (*(code *)param_1)(&DAT_68175dd8,1,&DAT_68175e08,1,xtra_createWriteStream), iVar2 == 0)) {
      iVar2 = (*(code *)param_1)(&DAT_68175dd8,1,&DAT_68175bc8,1,xtra_createWriteSeekStream);
    }
  }
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return iVar2; */
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_initWriterStub
// Address: 6811d440
// Size: 68 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_initWriterStub(void)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  xtra_writeSerializedBlock(lingo_createVtableObject,(undefined *)0x0);
  return 0x80040005;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_initWriterFail
// Address: 6811d490
// Size: 73 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x6811d4be) */

undefined4 xtra_initWriterFail(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  xtra_writeSerializedBlock((void *)0x0,xtra_matchStreamInterface);
  return 0x80040004;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_createWriterContext
// Address: 6811d4e0
// Size: 204 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_createWriterContext(int *param_1,undefined4 *param_2)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  undefined4 *puVar1;
  
  xtra_writeSerializedBlock(lingo_setVtableSlot,lingo_createObjectEx);
  puVar1 = (undefined4 *)(**(code **)(*param_1 + 0xc))(param_1,0x28);
  *param_2 = puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    return 0x80040002;
  }
  xtra_writeSerializedBlock(lingo_setVtableSlot,lingo_createObjectEx);
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[3] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  puVar1[7] = 0;
  puVar1[8] = 0;
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_registerWriterFormats
// Address: 6811d5b0
// Size: 220 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_registerWriterFormats(int param_1,int *param_2,undefined4 param_3)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_54;
  int *local_50;
  int *local_4c;
  undefined1 local_48 [64];
  uint local_8;
  
  puVar1 = *(undefined4 **)(*(int *)(param_1 + 4) + 8);
  iVar2 = (**(code **)*puVar1)(puVar1,&DAT_68175b98,&local_50);
  if (iVar2 == 0) {
    (**(code **)(*local_50 + 8))(local_50);
  }
  iVar2 = (**(code **)(*param_2 + 0x1c))(param_2,param_3,&DAT_68175dd8,&DAT_68175e08,&local_4c);
  if (iVar2 == 0) {
    Ordinal_1517(DAT_681956e0,2000,local_48,0x40);
    iVar2 = (**(code **)(*local_4c + 0x18))(local_4c,9,local_48,0,&DAT_6817c8e8);
    if (iVar2 == 0) {
      local_54 = 1000;
      iVar2 = (**(code **)(*local_4c + 0x18))(local_4c,3,&local_54,0,"Speed");
      if (iVar2 == 0) {
        (**(code **)(*local_4c + 0x18))(local_4c,8,&DAT_68175df8,0x10,"Formats");
      }
    }
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_initWriterStreams
// Address: 6811d690
// Size: 87 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_initWriterStreams(int param_1)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int iVar1;
  int iVar2;
  
  *(undefined4 *)(param_1 + 0x28) = 0;
  *(undefined4 *)(param_1 + 0x2c) = 0;
  *(undefined4 *)(param_1 + 0x30) = 0;
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  iVar1 = (**(code **)**(undefined4 **)(param_1 + 8))
                    (*(undefined4 **)(param_1 + 8),&DAT_68175b98,(undefined4 *)(param_1 + 0x18));
  if (iVar1 == 0) {
    iVar2 = (**(code **)**(undefined4 **)(param_1 + 8))
                      (*(undefined4 **)(param_1 + 8),&DAT_68175e48,(undefined4 *)(param_1 + 0x20));
    if (iVar2 != 0) {
      *(undefined4 *)(param_1 + 0x20) = 0;
    }
  }
  return iVar1;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_releaseWriterStreams
// Address: 6811d6f0
// Size: 56 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_releaseWriterStreams(int param_1)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x18);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x18) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x20);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: xtra_getSerializedState (FUN_6811d730)
// Address: 6811d730
// Size: 130 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getSerializedState(int param_1)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int iVar1;
  
  Ordinal_983(*(undefined4 *)(*(int *)(param_1 + 4) + 0x30));
  iVar1 = *(int *)(param_1 + 4);
  if (*(int *)(iVar1 + 0x28) != 0) {
    (**(code **)(**(int **)(iVar1 + 0xc) + 0x10))
              (*(int **)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x28));
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x28) = 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (*(int *)(iVar1 + 0x2c) != 0) {
    (**(code **)(**(int **)(iVar1 + 0xc) + 0x10))
              (*(int **)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x2c));
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x2c) = 0;
  }
  iVar1 = *(int *)(param_1 + 4);
  if (*(int *)(iVar1 + 0x30) != 0) {
    (**(code **)(**(int **)(iVar1 + 0xc) + 0x10))
              (*(int **)(iVar1 + 0xc),*(undefined4 *)(iVar1 + 0x30));
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x30) = 0;
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



