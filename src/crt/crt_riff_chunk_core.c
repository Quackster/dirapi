// Module: crt
// Topic: RIFF chunk management, free lists, allocation, chunk handlers
// Address range: 0x68001930 - 0x68003CD0
// Functions (63):
//   crt_validateStreamSize - crt_updateListHead (chunk list operations)
//   crt_coalesceChunks - crt_deleteSlotEntry (chunk merge/allocate, Ordinal_19/21)
//   crt_mergeChunks - crt_resetChunkState (chunk write/read, data operations)
//   crt_resetSlotFlags - crt_readRifxHeader (chunk reset, Ordinal_20/13, copy, parse, indexing)
//   crt_lockRifx - crt_getChunkShortField (lock/unlock, chunk handlers, Ordinal_10/11, validation, search)

// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68001930 - 0x68001c40
// Functions (16):
//   crt_validateStreamSize
//   crt_writeChunkAndSeek
//   crt_initPascalString
//   crt_writeImapData
//   crt_storeSlotData
//   crt_lockSlotHandle
//   crt_getChunkListRef
//   crt_advanceChunkList
//   crt_rewindChunkList
//   crt_initFreeChunk
//   crt_getChunkListEntry
//   crt_popFreeEntry
//   crt_getSlotNext
//   crt_setSlotNext
//   crt_linkSlotNext
//   crt_updateListHead

// ============================================================
// Function: crt_validateStreamSize (FUN_68001930)
// Address: 68001930
// Size: 54 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_validateStreamSize(void)

{
  int iVar1;
  int *unaff_ESI;
  uint local_c;
  uint local_8;
  
  iVar1 = crt_computeChunkTotal(unaff_ESI,&local_c);
  if (iVar1 == 0) {
    iVar1 = crt_getStreamSize(unaff_ESI[1],&local_8);
    if ((iVar1 == 0) && (local_8 < local_c)) {
      iVar1 = 0x1f6;
    }
  }
  return iVar1;
}



// ============================================================
// Function: crt_writeChunkAndSeek (FUN_68001970)
// Address: 68001970
// Size: 57 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_writeChunkAndSeek(void)
{
  int iVar1;
  int iVar2;
  ushort *unaff_ESI;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 4);
  iVar2 = crt_writeChunkData(unaff_EDI,unaff_ESI,0);
  if (iVar2 == 0) {
    iVar2 = crt_streamSeek(iVar1,*(int *)(unaff_ESI + 2) + 1U & 0xfffffffe);
    if (iVar2 == 0) {
      iVar2 = crt_writeChunkData(unaff_EDI,unaff_ESI,0);
      if (iVar2 == 0) {
        crt_streamSeek(iVar1,0xfffffff8);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: crt_initPascalString (FUN_680019b0)
// Address: 680019b0
// Size: 16 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_initPascalString(void)
{
  ushort *in_EAX;
  
  cast_copyPascalString(in_EAX,"444444",0x18,0x18);
  return 0;
}



// ============================================================
// Function: crt_writeImapData (FUN_680019c0)
// Address: 680019c0
// Size: 140 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_writeImapData(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int local_c [2];
  
  iVar2 = *(int *)(in_EAX + 4);
  iVar1 = crt_writeChunkAndRewind(in_EAX,(ushort *)local_c);
  while( true ) {
    if (iVar1 != 0) {
      return iVar1;
    }
    if (local_c[0] == FOURCC_imap) break;
    iVar1 = crt_writeChunkAndSeek();
  }
  iVar1 = crt_streamSeek(iVar2,8);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = crt_writeStreamData(iVar2,param_1,0x18);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*(int *)(in_EAX + 0x14) != 0) {
    crt_initPascalString();
  }
  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != -1) && (iVar1 != 0)) {
    iVar2 = crt_streamRead(iVar2,iVar1);
    return iVar2;
  }
  return 0xcf;
}



// ============================================================
// Function: crt_storeSlotData (FUN_68001a50)
// Address: 68001a50
// Size: 110 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_storeSlotData(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  *(undefined4 *)(param_1 + 0x2c) = 1;
  iVar2 = crt_getSlotEntry(param_1,2);
  *(undefined4 *)(param_1 + 0x30) = *(undefined4 *)(iVar2 + 8);
  iVar2 = crt_getSlotEntry(param_1,1);
  uVar1 = *(undefined4 *)(iVar2 + 0x10);
  puVar3 = (undefined4 *)Ordinal_1114(uVar1);
  *puVar3 = *(undefined4 *)(param_1 + 0x2c);
  puVar3[1] = *(undefined4 *)(param_1 + 0x30);
  puVar3[2] = *(undefined4 *)(param_1 + 0x34);
  puVar3[3] = *(undefined4 *)(param_1 + 0x38);
  puVar3[4] = *(undefined4 *)(param_1 + 0x3c);
  puVar3[5] = *(undefined4 *)(param_1 + 0x40);
  puVar3[2] = param_2;
  if (*(int *)(param_1 + 0x14) != 0) {
    crt_initPascalString();
  }
  Ordinal_1115(uVar1);
  return 0;
}



// ============================================================
// Function: crt_lockSlotHandle (FUN_68001ac0)
// Address: 68001ac0
// Size: 37 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_lockSlotHandle(void)
{
  undefined4 uVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar2 = crt_getSlotEntry(unaff_EDI,1);
  uVar1 = *(undefined4 *)(iVar2 + 0x10);
  Ordinal_1114(uVar1);
  if (*(int *)(unaff_EDI + 0x14) != 0) {
    crt_initPascalString();
  }
  Ordinal_1115(uVar1);
  return 0;
}



// ============================================================
// Function: crt_getChunkListRef (FUN_68001af0)
// Address: 68001af0
// Size: 30 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getChunkListRef(int param_1)

{
  int iVar1;
  
  iVar1 = crt_getSlotEntry(param_1,0);
  return *(int *)(iVar1 + 4) + 8 + *(int *)(param_1 + 0x44);
}



// ============================================================
// Function: crt_advanceChunkList (FUN_68001b10)
// Address: 68001b10
// Size: 36 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_advanceChunkList(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = crt_getSlotEntry(param_1,0);
  *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + (param_2 + 1U & 0xfffffffe) + 8;
  *(ushort *)(iVar1 + 0xc) = *(ushort *)(iVar1 + 0xc) | 1;
  return 0;
}



// ============================================================
// Function: crt_rewindChunkList (FUN_68001b40)
// Address: 68001b40
// Size: 37 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_rewindChunkList(int param_1)
{
  int in_EAX;
  int iVar1;
  
  iVar1 = crt_getSlotEntry(in_EAX,0);
  *(int *)(iVar1 + 4) = *(int *)(iVar1 + 4) + (-8 - (param_1 + 1U & 0xfffffffe));
  *(ushort *)(iVar1 + 0xc) = *(ushort *)(iVar1 + 0xc) | 1;
  return 0;
}



// ============================================================
// Function: crt_initFreeChunk (FUN_68001b70)
// Address: 68001b70
// Size: 29 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_initFreeChunk(void)
{
  undefined4 *in_EAX;
  
  *in_EAX = FOURCC_free;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[4] = 0xffffffff;
  in_EAX[3] = 0xc;
  return 0;
}



// ============================================================
// Function: crt_getChunkListEntry (FUN_68001b90)
// Address: 68001b90
// Size: 33 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_getChunkListEntry(void)
{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  crt_getSlotEntry(unaff_EDI,unaff_ESI);
  iVar1 = crt_initFreeChunk();
  if (2 < unaff_ESI) {
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(*(int *)(unaff_EDI + 0x20) + 0x14);
    *(int *)(*(int *)(unaff_EDI + 0x20) + 0x14) = unaff_ESI;
  }
  return 0;
}



// ============================================================
// Function: crt_popFreeEntry (FUN_68001bc0)
// Address: 68001bc0
// Size: 32 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_popFreeEntry(void)

{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  
  iVar1 = *(int *)(*(int *)(unaff_EDI + 0x20) + 0x14);
  if (iVar1 != -1) {
    iVar2 = crt_getSlotEntry(unaff_EDI,iVar1);
    *(undefined4 *)(*(int *)(unaff_EDI + 0x20) + 0x14) = *(undefined4 *)(iVar2 + 0x10);
  }
  return iVar1;
}



// ============================================================
// Function: crt_getSlotNext (FUN_68001be0)
// Address: 68001be0
// Size: 23 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall crt_getSlotNext(int param_1)

{
  int in_EAX;
  int iVar1;
  
  if (in_EAX == -1) {
    return *(undefined4 *)(*(int *)(param_1 + 0x20) + 0x10);
  }
  iVar1 = crt_getSlotEntry(param_1,in_EAX);
  return *(undefined4 *)(iVar1 + 0x10);
}



// ============================================================
// Function: crt_setSlotNext (FUN_68001c00)
// Address: 68001c00
// Size: 29 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall crt_setSlotNext(void *this,undefined4 param_1)
{
  int in_EAX;
  int iVar1;
  
  iVar1 = crt_getSlotEntry((int)this,in_EAX);
  if ((*(ushort *)(iVar1 + 0xc) & 0xc) != 0) {
    *(undefined4 *)(iVar1 + 0x10) = param_1;
  }
  return 0;
}



// ============================================================
// Function: crt_linkSlotNext (FUN_68001c20)
// Address: 68001c20
// Size: 30 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_linkSlotNext(void)
{
  undefined4 uVar1;
  void *unaff_ESI;
  int unaff_EDI;

  uVar1 = crt_getSlotNext((int)unaff_ESI);
  if (unaff_EDI == -1) {
    *(undefined4 *)(*(int *)((int)unaff_ESI + 0x20) + 0x10) = uVar1;
    return 0;
  }
  crt_setSlotNext(unaff_ESI,uVar1);
  return 0;
}



// ============================================================
// Function: crt_updateListHead (FUN_68001c40)
// Address: 68001c40
// Size: 43 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_updateListHead(void)
{
  undefined4 unaff_EBX;
  void *unaff_ESI;
  int unaff_EDI;

  crt_setSlotNext(unaff_ESI,unaff_EDI);
  if (unaff_EDI == *(int *)(*(int *)((int)unaff_ESI + 0x20) + 0x10)) {
    *(undefined4 *)(*(int *)((int)unaff_ESI + 0x20) + 0x10) = unaff_EBX;
    return 0;
  }
  crt_setSlotNext(unaff_ESI,unaff_EBX);
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68001c70 - 0x68002280
// Functions (12):
//   crt_coalesceChunks
//   crt_markSlotJunk
//   crt_allocSlotIndex
//   crt_allocSlot
//   crt_popJunkEntry
//   crt_allocFreeSpace
//   Ordinal_19
//   crt_ensureSlot
//   crt_freeSlotAlloc
//   crt_resizeSlotAlloc
//   Ordinal_21
//   crt_deleteSlotEntry

// ============================================================
// Function: crt_coalesceChunks (FUN_68001c70)
// Address: 68001c70
// Size: 352 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_coalesceChunks(int param_1,int param_2)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  
  iVar4 = crt_getSlotEntry(param_1,param_2);
  uVar5 = *(int *)(iVar4 + 4) + 1U & 0xfffffffe;
  *(uint *)(iVar4 + 4) = uVar5;
  uVar5 = *(int *)(iVar4 + 8) + 8 + uVar5;
  uVar1 = *(uint *)(*(int *)(param_1 + 0x20) + 0x10);
  do {
    uVar3 = uVar1;
    if (0x7fffffff < uVar3) break;
    if (*(int *)(*(int *)(param_1 + 0x20) + 8) < (int)uVar3) {
      return 0;
    }
    iVar6 = crt_getSlotEntry(param_1,uVar3);
    uVar1 = *(uint *)(iVar6 + 0x10);
    if ((uVar1 == 0xffffffff) && (uVar7 = crt_getChunkListRef(param_1), uVar5 == uVar7)) {
      crt_rewindChunkList(*(int *)(iVar4 + 4));
      crt_getChunkListEntry();
      return 0;
    }
    uVar7 = *(uint *)(iVar6 + 8);
    uVar2 = *(uint *)(iVar4 + 8);
    if (uVar5 == uVar7) {
      *(uint *)(iVar6 + 8) = uVar2;
      iVar4 = *(int *)(iVar4 + 4);
      *(ushort *)(iVar6 + 0xc) = *(ushort *)(iVar6 + 0xc) | 1;
      *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + iVar4 + 8;
      crt_getChunkListEntry();
      return 0;
    }
    if (uVar2 == *(int *)(iVar6 + 4) + 8 + uVar7) {
      iVar4 = *(int *)(iVar4 + 4);
      *(ushort *)(iVar6 + 0xc) = *(ushort *)(iVar6 + 0xc) | 1;
      *(int *)(iVar6 + 4) = *(int *)(iVar6 + 4) + iVar4 + 8;
      crt_getChunkListEntry();
      if (uVar1 == 0xffffffff) {
        return 0;
      }
      iVar4 = crt_getSlotEntry(param_1,uVar1);
      if (iVar4 == 0) {
        return 0;
      }
      if (*(int *)(iVar4 + 8) != *(int *)(iVar6 + 8) + 8 + *(int *)(iVar6 + 4)) {
        return 0;
      }
      *(int *)(iVar6 + 4) = *(int *)(iVar4 + 4) + 8 + *(int *)(iVar6 + 4);
      *(undefined4 *)(iVar6 + 0x10) = *(undefined4 *)(iVar4 + 0x10);
      crt_getChunkListEntry();
      return 0;
    }
  } while (uVar7 <= uVar2);
  *(ushort *)(iVar4 + 0xc) = *(ushort *)(iVar4 + 0xc) | 1;
  if (uVar3 != 0xffffffff) {
    crt_updateListHead();
  }
  return 0;
}



// ============================================================
// Function: crt_markSlotJunk (FUN_68001dd0)
// Address: 68001dd0
// Size: 36 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_markSlotJunk(void)
{
  undefined4 *puVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  puVar1 = (undefined4 *)crt_getSlotEntry(unaff_ESI,unaff_EDI);
  *puVar1 = FOURCC_junk;
  puVar1[3] = 4;
  puVar1[4] = *(undefined4 *)(*(int *)(unaff_ESI + 0x20) + 0xc);
  *(int *)(*(int *)(unaff_ESI + 0x20) + 0xc) = unaff_EDI;
  return 0;
}



// ============================================================
// Function: crt_allocSlotIndex (FUN_68001e00)
// Address: 68001e00
// Size: 71 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_allocSlotIndex(void)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = crt_popFreeEntry();
  if (iVar1 == -1) {
    if (*(int *)(*(int *)(in_EAX + 0x20) + 8) == *(int *)(*(int *)(in_EAX + 0x20) + 4)) {
      iVar1 = crt_growMmapCapacity(in_EAX,0);
      if ((iVar1 != 0) != 0) {
        *(uint *)(in_EAX + 8) = (uint)(iVar1 != 0);
        return -1;
      }
    }
    iVar1 = *(int *)(*(int *)(in_EAX + 0x20) + 8);
    *(int *)(*(int *)(in_EAX + 0x20) + 8) = iVar1 + 1;
  }
  *(undefined4 *)(in_EAX + 8) = 0;
  return iVar1;
}



// ============================================================
// Function: crt_allocSlot (FUN_68001e50)
// Address: 68001e50
// Size: 53 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_allocSlot(undefined4 param_1,undefined4 param_2)

{
  int in_EAX;
  int iVar1;
  
  iVar1 = crt_allocSlotIndex();
  if (*(int *)(in_EAX + 8) == 0) {
    iVar1 = crt_getSlotEntry(in_EAX,iVar1);
    *(undefined4 *)(iVar1 + 8) = param_1;
    *(undefined4 *)(iVar1 + 4) = param_2;
    crt_markSlotJunk();
  }
  return *(undefined4 *)(in_EAX + 8);
}



// ============================================================
// Function: crt_popJunkEntry (FUN_68001e90)
// Address: 68001e90
// Size: 93 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_popJunkEntry(void)

{
  int iVar1;
  int iVar2;
  int unaff_ESI;
  
  iVar2 = *(int *)(unaff_ESI + 0x20);
  iVar1 = *(int *)(iVar2 + 0xc);
  if (iVar1 != -1) {
    if ((iVar1 < 3) || (*(int *)(iVar2 + 8) <= iVar1)) {
      *(undefined4 *)(iVar2 + 0xc) = 0xffffffff;
      *(undefined4 *)(unaff_ESI + 8) = 0xd0;
      return -1;
    }
    iVar2 = crt_getSlotEntry(unaff_ESI,iVar1);
    iVar2 = *(int *)(iVar2 + 0x10);
    if ((iVar2 != -1) && ((iVar2 < 3 || (*(int *)(*(int *)(unaff_ESI + 0x20) + 8) <= iVar2)))) {
      *(undefined4 *)(*(int *)(unaff_ESI + 0x20) + 0xc) = 0xffffffff;
      *(undefined4 *)(unaff_ESI + 8) = 0xd0;
      return -1;
    }
    *(int *)(*(int *)(unaff_ESI + 0x20) + 0xc) = iVar2;
  }
  return iVar1;
}



// ============================================================
// Function: crt_allocFreeSpace (FUN_68001ef0)
// Address: 68001ef0
// Size: 252 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_allocFreeSpace(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_14;
  
  iVar2 = crt_getChunkListRef(param_1);
  uVar3 = param_2 + 1U & 0xfffffffe;
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 0x10);
  do {
    local_14 = iVar2;
    if (iVar1 == -1) {
LAB_68001f24:
      crt_advanceChunkList(param_1,param_2);
      return local_14;
    }
    iVar4 = crt_getSlotEntry(param_1,iVar1);
    iVar1 = *(int *)(iVar4 + 0x10);
    local_14 = *(int *)(iVar4 + 8);
    uVar5 = *(int *)(iVar4 + 4) + 1U & 0xfffffffe;
    if ((iVar1 == -1) && (local_14 + 8 + uVar5 == iVar2)) {
      crt_linkSlotNext();
      crt_getChunkListEntry();
      crt_rewindChunkList(uVar5);
      goto LAB_68001f24;
    }
    if (uVar3 == uVar5) {
      crt_linkSlotNext();
      crt_getChunkListEntry();
      return local_14;
    }
    if (uVar3 + 8 <= uVar5) {
      *(int *)(iVar4 + 8) = *(int *)(iVar4 + 8) + uVar3 + 8;
      *(int *)(iVar4 + 4) = *(int *)(iVar4 + 4) + (-8 - uVar3);
      *(ushort *)(iVar4 + 0xc) = *(ushort *)(iVar4 + 0xc) | 1;
      return local_14;
    }
  } while( true );
}



// ============================================================
// Function: Ordinal_19
// Address: 68002000
// Size: 103 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_19(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
                    /* 0x2000  19   */
  crt_lockRifx(param_1);
  iVar2 = crt_allocSlotIndex();
  iVar1 = *(int *)(param_1 + 8);
  if (iVar1 == 0) {
    puVar3 = (undefined4 *)crt_getSlotEntry(param_1,iVar2);
    *puVar3 = param_2;
    puVar3[1] = 0;
    puVar3[2] = 0xffffffff;
    puVar3[4] = 0;
    puVar3[3] = 1;
    iVar4 = crt_getSlotEntry(param_1,2);
    *(ushort *)(iVar4 + 0xc) = *(ushort *)(iVar4 + 0xc) | 1;
  }
  *(int *)(param_1 + 8) = iVar1;
  if (iVar1 != 0) {
    iVar2 = -1;
  }
  crt_unlockRifx(param_1);
  return iVar2;
}



// ============================================================
// Function: crt_ensureSlot (FUN_68002070)
// Address: 68002070
// Size: 215 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_ensureSlot(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  iVar4 = -1;
  crt_lockRifx(param_1);
  iVar1 = crt_validateSlot(param_1,param_2,4);
  if (iVar1 == 0) {
    piVar2 = (int *)crt_getSlotEntry(param_1,param_2);
    if (*piVar2 != 0xcb) {
      local_8 = 0xcb;
      goto LAB_6800212f;
    }
  }
  else {
    iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 8);
    while (iVar1 <= param_2) {
      iVar4 = crt_allocSlotIndex();
      local_8 = *(int *)(param_1 + 8);
      if (local_8 != 0) goto LAB_6800212f;
      puVar3 = (undefined4 *)crt_getSlotEntry(param_1,iVar4);
      *puVar3 = 0xcb;
      puVar3[1] = 0;
      puVar3[2] = 0xffffffff;
      puVar3[4] = 0;
      puVar3[3] = 1;
      iVar1 = crt_getSlotEntry(param_1,2);
      *(ushort *)(iVar1 + 0xc) = *(ushort *)(iVar1 + 0xc) | 1;
      if (iVar4 == param_2) goto LAB_6800211c;
      iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 8);
    }
    if (iVar4 != param_2) {
      local_8 = 0xcb;
      goto LAB_6800212f;
    }
  }
LAB_6800211c:
  puVar3 = (undefined4 *)crt_getSlotEntry(param_1,param_2);
  *puVar3 = param_3;
  local_c = 1;
LAB_6800212f:
  *(int *)(param_1 + 8) = local_8;
  crt_unlockRifx(param_1);
  return local_c;
}



// ============================================================
// Function: crt_freeSlotAlloc (FUN_68002150)
// Address: 68002150
// Size: 127 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_freeSlotAlloc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;

  crt_lockRifx(param_1);
  iVar1 = crt_validateSlot(param_1,param_2,4);
  if (iVar1 == 0) {
    iVar2 = crt_getSlotEntry(param_1,param_2);
    if ((*(int *)(iVar2 + 8) != -1) && ((*(ushort *)(iVar2 + 0xc) & 0x8000) == 0)) {
      iVar1 = crt_allocSlot(*(int *)(iVar2 + 8),*(undefined4 *)(iVar2 + 4));
      if (iVar1 == 0) {
        iVar2 = crt_getSlotEntry(param_1,param_2);
        *(ushort *)(iVar2 + 0xc) = *(ushort *)(iVar2 + 0xc) | 1;
        *(undefined4 *)(iVar2 + 8) = 0xffffffff;
        iVar2 = crt_getSlotEntry(param_1,2);
        *(ushort *)(iVar2 + 0xc) = *(ushort *)(iVar2 + 0xc) | 1;
      }
    }
  }
  *(int *)(param_1 + 8) = iVar1;
  crt_unlockRifx(param_1);
  return iVar1;
}



// ============================================================
// Function: crt_resizeSlotAlloc (FUN_680021d0)
// Address: 680021d0
// Size: 105 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_resizeSlotAlloc(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;

  crt_lockRifx(param_1);
  iVar1 = crt_validateSlot(param_1,param_2,4);
  if (iVar1 == 0) {
    iVar1 = crt_freeSlotAlloc(param_1,param_2);
    if (iVar1 == 0) {
      iVar2 = crt_allocFreeSpace(param_1,param_3);
      iVar3 = crt_getSlotEntry(param_1,param_2);
      *(int *)(iVar3 + 8) = iVar2;
      *(ushort *)(iVar3 + 0xc) = *(ushort *)(iVar3 + 0xc) | 0x8000;
      *(int *)(iVar3 + 4) = param_3;
    }
  }
  crt_unlockRifx(param_1);
  *(int *)(param_1 + 8) = iVar1;
  return iVar1;
}



// ============================================================
// Function: Ordinal_21
// Address: 68002240
// Size: 54 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_21(int param_1)

{
  int iVar1;
  
                    /* 0x2240  21   */
  crt_lockRifx(param_1);
  iVar1 = crt_getMediaFrameSize(param_1);
  iVar1 = crt_resizeSlotAlloc(param_1,2,iVar1);
  crt_unlockRifx(param_1);
  *(int *)(param_1 + 8) = iVar1;
  return iVar1;
}



// ============================================================
// Function: crt_deleteSlotEntry (FUN_68002280)
// Address: 68002280
// Size: 96 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_deleteSlotEntry(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int unaff_EBX;

  crt_lockRifx(unaff_EBX);
  iVar1 = crt_validateSlot(unaff_EBX,in_EAX,4);
  if (iVar1 == 0) {
    iVar2 = crt_getSlotEntry(unaff_EBX,in_EAX);
    if (*(int *)(iVar2 + 8) == -1) {
      crt_getChunkListEntry();
    }
    else {
      crt_markSlotJunk();
    }
    iVar2 = crt_getSlotEntry(unaff_EBX,2);
    *(ushort *)(iVar2 + 0xc) = *(ushort *)(iVar2 + 0xc) | 1;
  }
  *(int *)(unaff_EBX + 8) = iVar1;
  crt_unlockRifx(unaff_EBX);
  return iVar1;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x680022e0 - 0x68002880
// Functions (12):
//   crt_mergeChunks
//   crt_initRifxStruct
//   crt_createRifx
//   crt_flushSlot
//   crt_beginWriteChunk
//   crt_writeChunkHeader
//   crt_setWriteLimit
//   crt_getChunkDataSize
//   crt_writeChunkStream
//   crt_writeChunkBlock
//   crt_finalizeStreamWrite
//   crt_resetChunkState

// ============================================================
// Function: crt_mergeChunks (FUN_680022e0)
// Address: 680022e0
// Size: 73 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_mergeChunks(int param_1,int param_2)

{
  int iVar1;
  
  crt_lockRifx(param_1);
  iVar1 = crt_validateSlot(param_1,param_2,4);
  if (iVar1 == 0) {
    iVar1 = crt_releaseChunkHandler(param_1,param_2);
    if (iVar1 == 0) {
      iVar1 = crt_deleteSlotEntry();
    }
  }
  *(int *)(param_1 + 8) = iVar1;
  crt_unlockRifx(param_1);
  return iVar1;
}



// ============================================================
// Function: crt_initRifxStruct (FUN_68002330)
// Address: 68002330
// Size: 249 bytes
// Params: void * this, undefined4 param_1
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall crt_initRifxStruct(void *this,undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  crt_lockRifx((int)this);
  *(int *)((int)this + 4) = in_EAX;
  crt_initRifxSlots((int)this);
  *(undefined4 *)((int)this + 0x14) = param_1;
  iVar1 = crt_growMmapCapacity((int)this,0);
  if (iVar1 == 0) {
    *(undefined4 *)((int)this + 0x48) = 0x2c;
    *(undefined4 *)(*(int *)((int)this + 0x20) + 8) = 3;
    puVar2 = (undefined4 *)crt_getSlotEntry((int)this,0);
    puVar2[4] = 0;
    *puVar2 = FOURCC_RIFX;
    puVar2[1] = *(int *)((int)this + 0x48) + -8;
    puVar2[2] = *(undefined4 *)((int)this + 0x44);
    puVar2[3] = 1;
    puVar2 = (undefined4 *)crt_getSlotEntry((int)this,1);
    uVar3 = cast_allocHandle(0x18,1);
    puVar2[4] = uVar3;
    *puVar2 = FOURCC_imap;
    puVar2[1] = 0x18;
    puVar2[2] = *(int *)((int)this + 0x44) + 0xc;
    puVar2[3] = 1;
    puVar2 = (undefined4 *)crt_getSlotEntry((int)this,2);
    puVar2[4] = *(undefined4 *)((int)this + 0x1c);
    *puVar2 = FOURCC_mmap;
    puVar2[1] = 0;
    puVar2[2] = 0xffffffff;
    puVar2[3] = 1;
    if (in_EAX != 0) {
      iVar1 = crt_writeRifxHeader();
      *(int *)((int)this + 8) = iVar1;
      crt_unlockRifx((int)this);
      return iVar1;
    }
  }
  *(int *)((int)this + 8) = iVar1;
  crt_unlockRifx((int)this);
  return iVar1;
}



// ============================================================
// Function: crt_createRifx (FUN_68002430)
// Address: 68002430
// Size: 35 bytes
// Params: void * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_createRifx(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;

  *(undefined4 *)((int)param_1 + 0x44) = param_3;
  iVar1 = crt_initRifxStruct(param_1,param_4);
  *(int *)((int)param_1 + 8) = iVar1;
  return 0;
}



// ============================================================
// Function: crt_flushSlot (FUN_68002460)
// Address: 68002460
// Size: 281 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_flushSlot(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  undefined **ppuVar5;
  int iVar6;
  int iVar7;
  int local_10;
  
  iVar2 = param_1;
  crt_lockRifx(param_1);
  if (*(int *)(param_1 + 4) == 0) {
    param_1 = 0xca;
    iVar3 = param_1;
  }
  else {
    iVar3 = crt_validateSlot(param_1,param_2,0);
    if (iVar3 == 0) {
      piVar4 = (int *)crt_getSlotEntry(param_1,param_2);
      if ((*(ushort *)(piVar4 + 3) & 1) != 0) {
        iVar7 = piVar4[4];
        *(ushort *)(piVar4 + 3) = *(ushort *)(piVar4 + 3) & 0x7ffe;
        ppuVar5 = core_getChunkHandler(*piVar4);
        iVar1 = piVar4[2];
        iVar6 = param_2;
        if (iVar1 == -1) {
          iVar6 = (*(code *)ppuVar5[2])(param_1,iVar7,*piVar4);
          local_10 = crt_allocFreeSpace(param_1,iVar6);
          piVar4[2] = local_10;
          piVar4[1] = iVar6;
        }
        iVar3 = (*(code *)ppuVar5[4])(param_1,iVar7,*piVar4,piVar4[1],piVar4[2]);
        if (iVar3 == 0) {
          if ((iVar7 != 0) && (0 < param_2)) {
            crt_seekToChunkEnd(param_1,piVar4[1] + 8);
          }
        }
        else {
          *(ushort *)(piVar4 + 3) = *(ushort *)(piVar4 + 3) | 1;
          if (iVar1 == -1) {
            iVar7 = crt_getChunkListRef(param_1);
            if (local_10 + 8 + iVar6 == iVar7) {
              crt_rewindChunkList(iVar6);
            }
            piVar4[2] = -1;
          }
        }
      }
    }
  }
  param_1 = iVar3;
  *(int *)(iVar2 + 8) = param_1;
  crt_unlockRifx(iVar2);
  return param_1;
}



// ============================================================
// Function: crt_beginWriteChunk (FUN_68002580)
// Address: 68002580
// Size: 202 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_beginWriteChunk(int param_1)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_ESI;

  crt_lockRifx(unaff_ESI);
  *(int *)(unaff_ESI + 0x7c) = in_EAX;
  *(uint *)(unaff_ESI + 0x80) = (uint)(in_EAX < 0);
  iVar1 = crt_getSlotEntry(unaff_ESI,param_1);
  if ((*(ushort *)(iVar1 + 0xc) & 0x8000) == 0) {
    if (*(int *)(unaff_ESI + 0x80) == 0) {
      iVar2 = crt_allocFreeSpace(unaff_ESI,in_EAX);
    }
    else {
      iVar2 = crt_getChunkListRef(unaff_ESI);
    }
    iVar1 = crt_freeSlotAlloc(unaff_ESI,param_1);
    if (iVar1 != 0) goto LAB_6800262e;
  }
  else {
    iVar2 = *(int *)(iVar1 + 8);
    *(ushort *)(iVar1 + 0xc) = *(ushort *)(iVar1 + 0xc) & 0x7fff;
  }
  puVar3 = (undefined4 *)crt_getSlotEntry(unaff_ESI,param_1);
  *(ushort *)(puVar3 + 3) = *(ushort *)(puVar3 + 3) & 0xfffe;
  puVar3[2] = iVar2;
  puVar3[1] = 0;
  iVar1 = crt_writeStreamBlock(unaff_ESI,*puVar3,0,iVar2);
  if (iVar1 == 0) {
    *(int *)(unaff_ESI + 0x74) = param_1;
    *(undefined4 *)(unaff_ESI + 0x78) = 0xffffffff;
    iVar2 = crt_getSlotEntry(unaff_ESI,2);
    *(ushort *)(iVar2 + 0xc) = *(ushort *)(iVar2 + 0xc) | 1;
  }
LAB_6800262e:
  crt_unlockRifx(unaff_ESI);
  *(int *)(unaff_ESI + 8) = iVar1;
  if (iVar1 != 0) {
    *(undefined4 *)(unaff_ESI + 0x74) = 0xffffffff;
  }
  return iVar1;
}



// ============================================================
// Function: crt_writeChunkHeader (FUN_68002650)
// Address: 68002650
// Size: 24 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_writeChunkHeader(undefined4 param_1,int param_2)
{
  crt_beginWriteChunk(param_2);
  return 0;
}



// ============================================================
// Function: crt_setWriteLimit (FUN_68002670)
// Address: 68002670
// Size: 18 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_setWriteLimit(int param_1,undefined4 param_2)

{
  *(undefined4 *)(param_1 + 0x78) = param_2;
  return 0;
}



// ============================================================
// Function: crt_getChunkDataSize (FUN_68002690)
// Address: 68002690
// Size: 49 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getChunkDataSize(int param_1)

{
  int iVar1;
  
  crt_lockRifx(param_1);
  iVar1 = *(int *)(param_1 + 0x78);
  if (iVar1 == -1) {
    iVar1 = crt_getSlotEntry(param_1,*(int *)(param_1 + 0x74));
    iVar1 = *(int *)(iVar1 + 4);
  }
  crt_unlockRifx(param_1);
  return iVar1;
}



// ============================================================
// Function: crt_writeChunkStream (FUN_680026d0)
// Address: 680026d0
// Size: 231 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_writeChunkStream(undefined4 param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int unaff_ESI;
  bool bVar5;
  int local_8;
  
  iVar1 = *(int *)(unaff_ESI + 4);
  iVar3 = crt_getSlotEntry(unaff_ESI,*(int *)(unaff_ESI + 0x74));
  iVar4 = *(int *)(unaff_ESI + 0x78);
  iVar2 = *(int *)(iVar3 + 8);
  bVar5 = iVar4 == -1;
  if (bVar5) {
    if ((*(uint *)(unaff_ESI + 0x7c) != 0) &&
       (*(uint *)(unaff_ESI + 0x7c) < (uint)(*(int *)(iVar3 + 4) + param_2))) goto LAB_6800276f;
    iVar4 = *(int *)(iVar3 + 4);
LAB_68002730:
    local_8 = crt_streamRead(iVar1,iVar2 + 8 + iVar4);
    if ((local_8 == 0) && (local_8 = crt_streamWrite(iVar1,param_1,param_2), local_8 == 0)) {
      if (bVar5) {
        *(int *)(iVar3 + 4) = *(int *)(iVar3 + 4) + param_2;
        *(undefined4 *)(unaff_ESI + 8) = 0;
        return 0;
      }
      goto LAB_680027a9;
    }
  }
  else {
    if ((*(uint *)(unaff_ESI + 0x7c) == 0) ||
       ((uint)(param_2 + iVar4) <= *(uint *)(unaff_ESI + 0x7c))) goto LAB_68002730;
LAB_6800276f:
    local_8 = 0xd2;
  }
  if ((*(int *)(unaff_ESI + 0x74) != -1) && (*(int *)(unaff_ESI + 0x80) != 0)) {
    iVar4 = crt_getSlotEntry(unaff_ESI,0);
    *(ushort *)(iVar4 + 0xc) = *(ushort *)(iVar4 + 0xc) | 1;
    *(int *)(iVar4 + 4) = iVar2 + -8;
    *(undefined4 *)(unaff_ESI + 0x74) = 0xffffffff;
    crt_streamTruncate(iVar1,iVar2);
  }
LAB_680027a9:
  *(int *)(unaff_ESI + 8) = local_8;
  return 0;
}



// ============================================================
// Function: crt_writeChunkBlock (FUN_680027c0)
// Address: 680027c0
// Size: 74 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_writeChunkBlock(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  
  crt_lockRifx(param_1);
  if (*(int *)(param_1 + 0x74) == -1) {
    *(undefined4 *)(param_1 + 8) = 0xcb;
    crt_unlockRifx(param_1);
    return 0xcb;
  }
  uVar1 = crt_writeChunkStream(param_2,param_3);
  *(undefined4 *)(param_1 + 8) = uVar1;
  crt_unlockRifx(param_1);
  return uVar1;
}



// ============================================================
// Function: crt_finalizeStreamWrite (FUN_68002810)
// Address: 68002810
// Size: 102 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_finalizeStreamWrite(int param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_1 + 4);
  iVar2 = crt_streamFlush(iVar1);
  if (((iVar2 != 0) && (*(int *)(param_1 + 0x74) != -1)) && (*(int *)(param_1 + 0x80) != 0)) {
    iVar3 = crt_getSlotEntry(param_1,*(int *)(param_1 + 0x74));
    iVar3 = *(int *)(iVar3 + 8);
    iVar4 = crt_getSlotEntry(param_1,0);
    *(ushort *)(iVar4 + 0xc) = *(ushort *)(iVar4 + 0xc) | 1;
    *(int *)(iVar4 + 4) = iVar3 + -8;
    *(undefined4 *)(param_1 + 0x74) = 0xffffffff;
    crt_streamTruncate(iVar1,iVar3);
  }
  *(int *)(param_1 + 8) = iVar2;
  return iVar2;
}



// ============================================================
// Function: crt_resetChunkState (FUN_68002880)
// Address: 68002880
// Size: 116 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_resetChunkState(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = 0;
  crt_lockRifx(param_1);
  if (*(int *)(param_1 + 0x74) != -1) {
    puVar1 = (undefined4 *)crt_getSlotEntry(param_1,*(int *)(param_1 + 0x74));
    iVar2 = crt_writeStreamBlock(param_1,*puVar1,puVar1[1],puVar1[2]);
    if (iVar2 == 0) {
      if (*(int *)(param_1 + 0x80) == 0) {
        if (*(int *)(param_1 + 0x7c) != puVar1[1]) {
          iVar2 = 0xd2;
        }
      }
      else {
        crt_advanceChunkList(param_1,puVar1[1]);
      }
      *(undefined4 *)(param_1 + 0x74) = 0xffffffff;
    }
  }
  *(int *)(param_1 + 8) = iVar2;
  crt_unlockRifx(param_1);
  return *(undefined4 *)(param_1 + 8);
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68002900 - 0x68002fe0
// Functions (9):
//   crt_resetSlotFlags
//   Ordinal_20
//   Ordinal_13
//   crt_copyChunkBetween
//   crt_parseRifxFile
//   crt_checkMulOverflow
//   crt_checkAddOverflow
//   crt_getSlotEntry
//   crt_readRifxHeader

// ============================================================
// Function: crt_resetSlotFlags (FUN_68002900)
// Address: 68002900
// Size: 146 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_resetSlotFlags(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_2) {
    do {
      piVar1 = (int *)crt_getSlotEntry(param_1,iVar2);
      *(ushort *)(piVar1 + 3) = *(ushort *)(piVar1 + 3) & 0x7f1f;
      if (iVar2 < 3) {
        if (*piVar1 == FOURCC_RIFX) {
          *(int *)(param_1 + 0x48) = piVar1[1] + 8;
        }
        piVar1[4] = 0;
      }
      else {
        if ((*(ushort *)(piVar1 + 3) & 4) == 0) {
          piVar1[4] = 0;
        }
        if (piVar1[1] == -1) {
          piVar1[1] = 0;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_2);
  }
  iVar2 = crt_popJunkEntry();
  while (iVar2 != -1) {
    crt_coalesceChunks(param_1,iVar2);
    iVar2 = crt_popJunkEntry();
  }
  if (*(int *)(param_1 + 8) == 0) {
    *(undefined4 *)(param_1 + 8) = 0;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_20
// Address: 680029a0
// Size: 117 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_20(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
                    /* 0x29a0  20   */
  crt_lockRifx(param_1);
  iVar1 = crt_validateSlot(param_1,param_2,4);
  if (iVar1 != 0) {
    *(int *)(param_1 + 8) = iVar1;
    return iVar1;
  }
  iVar1 = Ordinal_1116(param_3);
  iVar2 = crt_beginWriteChunk(param_2);
  if (iVar2 == 0) {
    uVar3 = Ordinal_1114(param_3);
    iVar1 = crt_writeChunkBlock(param_1,uVar3,iVar1);
    Ordinal_1115(param_3);
    if (iVar1 != 0) {
      *(int *)(param_1 + 8) = iVar1;
      return iVar1;
    }
    iVar2 = crt_resetChunkState(param_1);
  }
  *(int *)(param_1 + 8) = iVar2;
  return iVar2;
}



// ============================================================
// Function: Ordinal_13
// Address: 68002a20
// Size: 346 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_13(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
                    /* 0x2a20  13   */
  crt_lockRifx(param_1);
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 8) = 0xca;
    crt_unlockRifx(param_1);
    return 0xca;
  }
  iVar1 = crt_getSlotEntry(param_1,2);
  iVar2 = 0;
  if (((*(byte *)(iVar1 + 0xc) & 1) != 0) &&
     ((*(int *)(param_1 + 0x10) != 0 || (iVar2 = crt_writeRifxHeader(), iVar2 == 0)))) {
    iVar1 = 3;
    if (3 < *(int *)(*(int *)(param_1 + 0x20) + 8)) {
      do {
        piVar3 = (int *)crt_getSlotEntry(param_1,iVar1);
        if ((*(byte *)(piVar3 + 3) & 1) != 0) {
          if (((piVar3[1] == 0) && (piVar3[4] == 0)) && (*piVar3 != FOURCC_snd)) {
            iVar2 = crt_mergeChunks(param_1,iVar1);
          }
          else {
            iVar2 = crt_flushSlot(param_1,iVar1);
          }
          if (iVar2 != 0) goto LAB_68002b69;
        }
        iVar1 = iVar1 + 1;
      } while (iVar1 < *(int *)(*(int *)(param_1 + 0x20) + 8));
    }
    iVar2 = crt_freeSlotAlloc(param_1,2);
    if ((iVar2 == 0) && (iVar2 = crt_flushSlot(param_1,2), iVar2 == 0)) {
      crt_storeSlotData(param_1,param_2);
      iVar2 = crt_getSlotEntry(param_1,1);
      *(ushort *)(iVar2 + 0xc) = *(ushort *)(iVar2 + 0xc) | 1;
      iVar2 = crt_flushSlot(param_1,1);
      if (*(int *)(param_1 + 0x14) != 0) {
        crt_lockSlotHandle();
      }
      if ((iVar2 == 0) && (iVar2 = crt_flushSlot(param_1,0), iVar2 == 0)) {
        iVar2 = crt_getSlotEntry(param_1,0);
        *(int *)(param_1 + 0x48) = *(int *)(iVar2 + 4) + 8;
        iVar2 = crt_streamFlush(*(int *)(param_1 + 4));
        if (iVar2 == 0) {
          iVar2 = crt_popJunkEntry();
          while (iVar2 != -1) {
            crt_coalesceChunks(param_1,iVar2);
            iVar2 = crt_popJunkEntry();
          }
          iVar2 = *(int *)(param_1 + 8);
        }
      }
    }
  }
LAB_68002b69:
  *(int *)(param_1 + 8) = iVar2;
  crt_unlockRifx(param_1);
  return iVar2;
}



// ============================================================
// Function: crt_copyChunkBetween (FUN_68002b80)
// Address: 68002b80
// Size: 238 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_copyChunkBetween(int *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *local_c;
  int local_8;
  
  piVar1 = param_1;
  local_8 = 0;
  local_c = (int *)0x0;
  crt_lockRifx((int)param_1);
  iVar2 = param_3;
  crt_lockRifx(param_3);
  iVar3 = crt_validateSlot((int)piVar1,param_2,4);
  if (iVar3 == 0) {
    iVar3 = crt_validateSlot(iVar2,param_4,4);
    if (iVar3 == 0) {
      uVar4 = crt_writeChunkHeader(iVar2,param_4);
      *(undefined4 *)(iVar2 + 8) = uVar4;
      crt_setReadSlot(piVar1,param_2);
      crt_allocStreamBuffer(piVar1[1],&local_8,(int *)&local_c);
      param_4 = Ordinal_1114(local_8);
      do {
        param_1 = local_c;
        iVar3 = crt_readChunkAtOffset(piVar1,param_4,(int *)&param_1,1);
        if (iVar3 != 0) goto LAB_68002c3e;
        iVar3 = crt_writeChunkBlock(iVar2,param_4,(int)param_1);
        if (iVar3 != 0) goto LAB_68002c3e;
      } while (0 < (int)param_1);
      iVar3 = crt_resetChunkState(iVar2);
    }
  }
LAB_68002c3e:
  if (local_8 != 0) {
    Ordinal_1115(local_8);
  }
  crt_freeStreamBuffer(piVar1[1]);
  crt_unlockRifx((int)piVar1);
  crt_unlockRifx(iVar2);
  piVar1[2] = iVar3;
  return iVar3;
}



// ============================================================
// Function: crt_parseRifxFile (FUN_68002c70)
// Address: 68002c70
// Size: 715 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_parseRifxFile(int *param_1,int param_2)
{
  short *psVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int *piVar6;
  ushort local_30 [2];
  uint local_2c;
  uint local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  iVar3 = param_1[6];
  local_30[0] = 0;
  local_30[1] = 0;
  local_2c = 0;
  local_20 = 0;
  local_24 = 0;
  if (iVar3 == 0) {
LAB_68002cdd:
    if (param_2 != *param_1) goto LAB_68002f28;
    if (iVar3 != 0) {
      iVar3 = crt_getStreamSize(param_1[1],&local_24);
      if (iVar3 != 0) goto LAB_68002f28;
      if (local_24 < 100) goto LAB_68002d0f;
    }
    iVar3 = crt_writeImapData((int)&local_20);
    if ((((iVar3 != 0) || (iVar3 = crt_writeChunkData((int)param_1,local_30,1), iVar3 != 0)) ||
        (crt_streamReadAt(param_1[1],&local_24), local_24 < local_2c)) || (local_2c == 0))
    goto LAB_68002f28;
    if (param_1[6] != 0) {
      iVar3 = crt_getStreamSize(param_1[1],&local_24);
      if (iVar3 != 0) goto LAB_68002f28;
      iVar3 = crt_streamGetPos(param_1[1]);
      if (local_24 < iVar3 + local_2c) {
        iVar3 = crt_streamReadAt(param_1[1],&local_28);
        if ((iVar3 == 0) && (local_28 == local_24)) {
LAB_68002cc8:
          return 0;
        }
LAB_68002d0f:
        return 0;
      }
    }
    iVar3 = crt_loadAllSlots((int)param_1);
    if (iVar3 != 0) goto LAB_68002f28;
    *(undefined4 *)(param_1[8] + 8) = 1;
    Ordinal_1115(param_1[7]);
    cast_resizeHandle(param_1[7],0x2c,1);
    iVar3 = Ordinal_1114(param_1[7]);
    param_1[8] = iVar3;
    puVar4 = (undefined4 *)crt_getSlotEntry((int)param_1,0);
    *puVar4 = FOURCC_mmap;
    puVar4[1] = local_2c;
    puVar4[2] = local_1c;
    puVar4[4] = 0;
    *(undefined2 *)(puVar4 + 3) = 0;
    uVar5 = crt_loadChunkData((int)param_1,0);
    local_28 = uVar5;
    iVar3 = Ordinal_1116(uVar5);
    if (iVar3 < 0x2c) {
      param_1[2] = 0xd0;
    }
    if ((uVar5 == 0) || (param_1[2] != 0)) goto LAB_68002f28;
    crt_replaceChunkHandle((int)param_1,uVar5);
    piVar6 = (int *)cast_allocHandle(0x18,1);
    puVar4 = (undefined4 *)*piVar6;
    *puVar4 = local_20;
    puVar4[1] = local_1c;
    puVar4[2] = local_18;
    puVar4[3] = local_14;
    puVar4[4] = local_10;
    puVar4[5] = local_c;
    iVar3 = crt_loadImapHeader((int)param_1,piVar6);
    psVar1 = (short *)param_1[8];
    if ((*psVar1 < 1) ||
       (((psVar1[1] < 1 || (iVar2 = *(int *)(psVar1 + 4), iVar2 < 0)) ||
        (*(int *)(psVar1 + 2) < iVar2)))) {
      psVar1[4] = 0;
      psVar1[5] = 0;
      crt_resetSlotFlags((int)param_1,*(int *)(param_1[8] + 8));
      goto LAB_68002f28;
    }
    if (iVar3 != 0) {
      crt_resetSlotFlags((int)param_1,*(int *)(param_1[8] + 8));
      goto LAB_68002f28;
    }
    iVar3 = crt_resetSlotFlags((int)param_1,iVar2);
    if (iVar3 != 0) goto LAB_68002f28;
    iVar3 = crt_getSlotEntry((int)param_1,2);
    *(uint *)(iVar3 + 0x10) = local_28;
    iVar3 = crt_getSlotEntry((int)param_1,1);
    *(int **)(iVar3 + 0x10) = piVar6;
  }
  else if (param_1[0x2a] != 1) {
    if ((iVar3 != 0) && (param_1[0x2a] == 5)) goto LAB_68002cc8;
    goto LAB_68002cdd;
  }
  if ((param_1[6] == 0) || (iVar3 = crt_validateStreamSize(), iVar3 == 0)) {
    param_1[0x2a] = 5;
  }
LAB_68002f28:
  return 0;
}



// ============================================================
// Function: crt_checkMulOverflow (FUN_68002f40)
// Address: 68002f40
// Size: 40 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_checkMulOverflow(int param_1)

{
  longlong lVar1;
  int in_EAX;
  
  lVar1 = (longlong)in_EAX * (longlong)param_1 + 0x7fffffff;
  if (((int)((ulonglong)lVar1 >> 0x20) == 0) && ((int)lVar1 != -1)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: crt_checkAddOverflow (FUN_68002f70)
// Address: 68002f70
// Size: 53 bytes
// Params: uint param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_checkAddOverflow(uint param_1)

{
  uint in_EAX;
  
  if ((((int)in_EAX >> 0x1f) + ((int)param_1 >> 0x1f) + (uint)CARRY4(in_EAX,param_1) +
       (uint)(0x80000000 < in_EAX + param_1) == 0) && (in_EAX + param_1 != 0x80000000)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: crt_getSlotEntry (FUN_68002fb0)
// Address: 68002fb0
// Size: 47 bytes
// Params: RifxFile *rifx, int slotIndex
// Return: pointer to slot entry, or 0 if out of range
// Calling convention: __stdcall
// Returns the address of a slot entry in the mmap. Each entry is at
// offset 0x18 + (entrySize * index) from the mmap base.
// ============================================================

int crt_getSlotEntry(int param_1,int param_2)
{
  RifxFile *rifx = (RifxFile *)param_1;
  int slotIndex = param_2;

  if (slotIndex < 0) return 0;
  if (slotIndex != 0 && slotIndex >= *(int *)((int)rifx->mmapData + 4)) return 0;

  short entrySize = *(short *)((int)rifx->mmapData + 2);
  return (int)rifx->mmapData + 0x18 + entrySize * slotIndex;
}



// ============================================================
// Function: crt_readRifxHeader (FUN_68002fe0)
// Address: 68002fe0
// Size: 242 bytes
// Params: int * param_1, undefined4 param_2, undefined4 * param_3, undefined4 * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_readRifxHeader(int *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,
                 int *param_5)
{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar3 = 0;
  if (param_5 != (int *)0x0) {
    *param_5 = 0;
  }
  bVar1 = crt_streamIsOpen((int)param_1);
  if ((((CONCAT31(extraout_var,bVar1) != 0) || (iVar2 = crt_flushStream(param_1), iVar2 == 0)) &&
      (iVar2 = crt_streamRead((int)param_1,param_2), iVar2 == 0)) &&
     (iVar2 = crt_writeStreamData((int)param_1,&local_14,0xc), iVar2 == 0)) {
    if (local_14 != FOURCC_RIFX) {
      iVar3 = cast_freeIfNonNull(local_14);
      if (iVar3 != FOURCC_RIFX) {
        return 0;
      }
      iVar3 = 1;
    }
    if (param_3 != (undefined4 *)0x0) {
      if (iVar3 != 0) {
        local_10 = cast_freeIfNonNull(local_10);
      }
      *param_3 = local_10;
    }
    if (param_4 != (undefined4 *)0x0) {
      if (iVar3 != 0) {
        local_c = cast_freeIfNonNull(local_c);
      }
      *param_4 = local_c;
    }
    if (param_5 != (int *)0x0) {
      *param_5 = iVar3;
    }
  }
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x680030e0 - 0x680036d0
// Functions (14):
//   crt_lockRifx
//   crt_unlockRifx
//   crt_writeChunkAndRewind
//   crt_initRifxSlots
//   core_getChunkHandler
//   Ordinal_10
//   Ordinal_11
//   crt_validateSlot
//   crt_computeChunkTotal
//   crt_loadImapHeader
//   crt_growMmapCapacity
//   crt_getChunkSize
//   crt_getChunkRef
//   crt_finalizeResource

// ============================================================
// Function: crt_lockRifx (FUN_680030e0)
// Address: 680030e0
// Size: 33 bytes
// Params: RifxFile *rifx
// Return: int (always 0)
// Calling convention: __stdcall
// Increments lock count; on first lock, locks the mmap handle to get a pointer.
// ============================================================

int crt_lockRifx(int param_1)
{
  RifxFile *rifx = (RifxFile *)param_1;

  rifx->lockCount++;
  if (rifx->lockCount == 1) {
    rifx->mmapData = (void *)Ordinal_1114((undefined4)rifx->mmapHandle);
  }
  return 0;
}



// ============================================================
// Function: crt_unlockRifx (FUN_68003110)
// Address: 68003110
// Size: 28 bytes
// Params: RifxFile *rifx
// Return: int (always 0)
// Calling convention: __stdcall
// Decrements lock count; when it reaches zero, unlocks the mmap handle.
// ============================================================

int crt_unlockRifx(int param_1)
{
  RifxFile *rifx = (RifxFile *)param_1;

  rifx->lockCount--;
  if (rifx->lockCount < 1) {
    Ordinal_1115((undefined4)rifx->mmapHandle);
  }
  return 0;
}



// ============================================================
// Function: crt_writeChunkAndRewind (FUN_68003130)
// Address: 68003130
// Size: 39 bytes
// Params: RifxFile *rifx, ushort *chunkData
// Return: int (always 0)
// Calling convention: __stdcall
// Writes a chunk, then rewinds the stream by 8 bytes (chunk header size).
// ============================================================

int crt_writeChunkAndRewind(int param_1,ushort *param_2)
{
  RifxFile *rifx = (RifxFile *)param_1;
  int err;

  err = crt_writeChunkData(param_1, param_2, 0);
  if (err == 0) {
    crt_streamSeek((int)rifx->streamHandle, -8);
  }
  return 0;
}



// ============================================================
// Function: crt_initRifxSlots (FUN_68003160)
// Address: 68003160
// Size: 116 bytes
// Params: RifxFile *rifx
// Return: int (always 0)
// Calling convention: __stdcall
// Initializes the memory map with default slot table layout.
// ============================================================

int crt_initRifxSlots(int param_1)
{
  RifxFile *rifx = (RifxFile *)param_1;
  undefined2 *mmap;

  Ordinal_1115((undefined4)rifx->mmapHandle);
  cast_resizeHandle(*(uint *)&rifx->mmapHandle, 0x18, 1);
  mmap = (undefined2 *)Ordinal_1114((undefined4)rifx->mmapHandle);
  rifx->mmapData = mmap;

  /* Initialize mmap header: total=0x18, usable=0x14, 0 entries */
  *mmap = 0x18;
  *(undefined2 *)((int)rifx->mmapData + 2) = 0x14;
  *(undefined4 *)((int)rifx->mmapData + 4) = 0;
  *(undefined4 *)((int)rifx->mmapData + 8) = 0;
  *(undefined4 *)((int)rifx->mmapData + 0xc) = 0xffffffff;
  *(undefined4 *)((int)rifx->mmapData + 0x14) = 0xffffffff;
  *(undefined4 *)((int)rifx->mmapData + 0x10) = 0xffffffff;

  rifx->totalFileSize = 0xffffffff;
  rifx->field_0x54 = 0xffffffff;
  rifx->field_0x74 = 0xffffffff;
  rifx->field_0x58 = 0;
  rifx->field_0x14 = 0;
  return 0;
}



// ============================================================
// Function: core_getChunkHandler (FUN_680031e0)
// Address: 680031e0
// Size: 63 bytes
// Params: int param_1
// Return: undefined * *
// Calling convention: __stdcall
// ============================================================

undefined ** core_getChunkHandler(int param_1)

{
  if (param_1 == FOURCC_RIFX) {
    return &PTR_FUN_68188084;
  }
  if (param_1 != FOURCC_junk) {
    if (param_1 != FOURCC_mmap) {
      return &PTR_FUN_68188048;
    }
    return &PTR_FUN_68188070;
  }
  return &PTR_FUN_6818805c;
}



// ============================================================
// Function: Ordinal_10
// Address: 68003220
// Size: 252 bytes
// Params: undefined4 *param_1, undefined4 param_2, int param_3
// Return: int (always 0)
// Calling convention: __stdcall
// Creates a new RIFX file object (0xB4 bytes). Allocates the struct,
// initializes the memory map handle, and sets up the slot table.
// ============================================================

int Ordinal_10(undefined4 *param_1,undefined4 param_2,int param_3)
{
  undefined4 prevContext;
  undefined4 contextEntry;
  undefined4 contextFlag;
  RifxFile *rifx;

  Ordinal_2330();

  /* Push onto context chain */
  contextEntry = *param_1;
  contextFlag = 1;
  prevContext = DAT_68196374;
  if (param_3 < 3) {
    param_3 = 3;
  }
  DAT_68196374 = &contextEntry;

  /* Allocate RifxFile struct */
  rifx = (RifxFile *)Ordinal_1124(0xb4);
  if (rifx != NULL) {
    /* Allocate memory map handle */
    int mmapHandle = Ordinal_1111(0x18, 1);
    if (mmapHandle != 0) {
      rifx->fileReference = (void *)param_2;
      rifx->slotCapacity = param_3;
      rifx->mmapHandle = (void *)mmapHandle;
      rifx->mmapData = (void *)Ordinal_1114(mmapHandle);
      rifx->lockCount = 1;
      rifx->streamHandle = NULL;
      rifx->field_0x10 = 0;
      rifx->callerContext = (void *)param_1;

      crt_initRifxSlots((int)rifx);
      crt_unlockRifx((int)rifx);

      /* Pop context chain (only on success) */
      DAT_68196374 = (undefined4 *)prevContext;
      Ordinal_2331();
      return 0;
    }
    Ordinal_1125(&rifx);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_11
// Address: 68003320
// Size: 55 bytes
// Params: RifxFile *rifx
// Return: int (always 0)
// Calling convention: __stdcall
// Destroys a RIFX file object: closes the stream, frees the mmap handle,
// and frees the struct memory.
// ============================================================

int Ordinal_11(int param_1)
{
  RifxFile *rifx = (RifxFile *)param_1;

  if (rifx->streamHandle != NULL) {
    crt_streamClose((int)rifx->streamHandle);
  }
  if (rifx->mmapHandle != NULL) {
    cast_freeHandle((undefined4)rifx->mmapHandle);
  }
  Ordinal_1125(&param_1);
  return 0;
}



// ============================================================
// Function: crt_validateSlot (FUN_68003360)
// Address: 68003360
// Size: 99 bytes
// Params: RifxFile *rifx, int slotIndex, ushort requiredFlags
// Return: int (always 0, sets rifx->errorStatus)
// Calling convention: __stdcall
// Validates that a slot index is in range and has the required flags.
// Error codes: 0x00=ok, 0xCB=invalid(-1), 0xCC=out of range, 0xCD=flags mismatch.
// ============================================================

int crt_validateSlot(int param_1,int param_2,ushort param_3)
{
  RifxFile *rifx = (RifxFile *)param_1;
  int slotIndex = param_2;
  ushort requiredFlags = param_3;

  if (slotIndex == -1) {
    rifx->errorStatus = 0xcb;
    return 0;
  }
  if (slotIndex >= 0 && slotIndex < *(int *)((int)rifx->mmapData + 8)) {
    int slotEntry = crt_getSlotEntry(param_1, slotIndex);
    if (slotEntry != 0 && (*(ushort *)(slotEntry + 0xc) & requiredFlags) == 0) {
      rifx->errorStatus = 0;
      return 0;
    }
    rifx->errorStatus = 0xcd;
    return 0;
  }
  rifx->errorStatus = 0xcc;
  return 0;
}



// ============================================================
// Function: crt_computeChunkTotal (FUN_680033d0)
// Address: 680033d0
// Size: 192 bytes
// Params: int * param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_computeChunkTotal(int *param_1,uint *param_2)

{
  undefined4 uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint local_8;
  
  local_8 = 0;
  if (((param_1 == (int *)0x0) || ((*param_1 != FOURCC_FGDM && (*param_1 != FOURCC_FGDC)))) &&
     (param_1[0xd] < 0x578)) {
    uVar1 = crt_streamReadAt(param_1[1],param_2);
    return uVar1;
  }
  crt_lockRifx((int)param_1);
  iVar5 = 3;
  uVar4 = 0;
  if (3 < *(int *)(param_1[8] + 8)) {
    do {
      piVar2 = (int *)crt_getSlotEntry((int)param_1,iVar5);
      if (((((*(byte *)(piVar2 + 3) & 4) == 0) && (iVar3 = crt_isKnownChunkType(*piVar2), iVar3 != 0)) &&
          (piVar2[1] != 0)) &&
         ((piVar2[2] != -1 && (uVar4 = piVar2[1] + piVar2[2], local_8 < uVar4)))) {
        local_8 = uVar4;
      }
      iVar5 = iVar5 + 1;
      uVar4 = local_8;
    } while (iVar5 < *(int *)(param_1[8] + 8));
  }
  if ((*param_1 == FOURCC_FGDM) || (*param_1 == FOURCC_FGDC)) {
    uVar4 = uVar4 + param_1[0x24];
  }
  crt_unlockRifx((int)param_1);
  *param_2 = uVar4;
  return 0;
}



// ============================================================
// Function: crt_loadImapHeader (FUN_68003490)
// Address: 68003490
// Size: 71 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_loadImapHeader(int param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  piVar3 = (int *)(param_1 + 0x2c);
  Ordinal_1130(piVar3,0x14);
  iVar1 = Ordinal_1116(param_2);
  if (0x18 < iVar1) {
    iVar1 = 0x18;
  }
  Ordinal_1129(piVar3,*param_2,iVar1);
  uVar2 = 0;
  if (*piVar3 < 1) {
    uVar2 = 0xcf;
  }
  return uVar2;
}



// ============================================================
// Function: crt_growMmapCapacity (FUN_680034e0)
// Address: 680034e0
// Size: 271 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_growMmapCapacity(int param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  iVar3 = param_1;
  iVar4 = Ordinal_2045(*(undefined4 *)(param_1 + 0x1c));
  iVar9 = param_2;
  if (param_2 == 0) {
    iVar9 = *(int *)(*(int *)(param_1 + 0x20) + 8);
    param_2 = iVar9 + 1;
    iVar7 = *(int *)(*(int *)(param_1 + 0x20) + 4) >> 1;
    if (iVar7 < *(int *)(param_1 + 0x24)) {
      iVar7 = *(int *)(param_1 + 0x24);
    }
    iVar9 = iVar9 + iVar7;
  }
  if (iVar9 < *(int *)(param_1 + 0x24)) {
    iVar9 = *(int *)(param_1 + 0x24);
  }
  iVar8 = iVar9 - *(int *)(*(int *)(param_1 + 0x20) + 4);
  iVar7 = iVar4;
  if (iVar8 < 1) {
    *(undefined4 *)(param_1 + 8) = 0;
    return 0;
  }
  for (; 0 < iVar7; iVar7 = iVar7 + -1) {
    Ordinal_1115(*(undefined4 *)(param_1 + 0x1c));
  }
  bVar1 = false;
  param_1 = iVar8;
  while( true ) {
    if (bVar1) {
      Ordinal_1115(*(undefined4 *)(iVar3 + 0x1c));
    }
    uVar5 = cast_resizeHandle(*(uint *)(iVar3 + 0x1c),iVar9 * 0x14 + 0x18,1);
    uVar2 = DAT_68195a8c;
    iVar7 = Ordinal_1114(*(undefined4 *)(iVar3 + 0x1c));
    *(int *)(iVar3 + 0x20) = iVar7;
    bVar1 = true;
    if (uVar5 != 0) break;
    if (param_1 < 1) goto LAB_680035b1;
    param_1 = param_1 >> 1;
    iVar9 = *(int *)(iVar7 + 4) + param_1;
    if (iVar9 < param_2) {
      iVar9 = param_2;
    }
  }
  *(int *)(iVar7 + 4) = iVar9;
LAB_680035b1:
  Ordinal_1115(*(undefined4 *)(iVar3 + 0x1c));
  for (; 0 < iVar4; iVar4 = iVar4 + -1) {
    uVar6 = Ordinal_1114(*(undefined4 *)(iVar3 + 0x1c));
    *(undefined4 *)(iVar3 + 0x20) = uVar6;
  }
  *(undefined4 *)(iVar3 + 8) = uVar2;
  return uVar2;
}



// ============================================================
// Function: crt_getChunkSize (FUN_680035f0)
// Address: 680035f0
// Size: 184 bytes
// Params: int * param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crt_getChunkSize(int *param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  piVar1 = param_1;
  if (param_1[6] == 0) {
    return 1;
  }
  if ((*param_1 != FOURCC_FGDM) && (*param_1 != FOURCC_FGDC)) {
    crt_lockRifx((int)param_1);
    iVar4 = param_2;
    iVar3 = crt_validateSlot((int)piVar1,param_2,4);
    if (iVar3 == 0) {
      iVar4 = crt_getSlotEntry((int)piVar1,iVar4);
      if ((*(int *)(iVar4 + 8) != -1) && (*(int *)(iVar4 + 4) != 0)) {
        if (piVar1[1] == 0) {
          crt_unlockRifx((int)piVar1);
          return 0;
        }
        iVar3 = crt_getStreamSize(piVar1[1],&param_1);
        if ((iVar3 == 0) && (param_1 < (int *)(*(int *)(iVar4 + 8) + *(int *)(iVar4 + 4)))) {
          iVar3 = 0x1f6;
        }
      }
    }
    crt_unlockRifx((int)piVar1);
    return (uint)(iVar3 == 0);
  }
  uVar2 = crt_checkMxfSlotReady((uint)param_1,param_2);
  return uVar2;
}



// ============================================================
// Function: crt_getChunkRef (FUN_680036b0)
// Address: 680036b0
// Size: 21 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getChunkRef(int param_1)

{
  if (param_1 == 0) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 0x18);
}



// ============================================================
// Function: crt_finalizeResource (FUN_680036d0)
// Address: 680036d0
// Size: 96 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_finalizeResource(int *param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != (int *)0x0) && ((*param_1 == FOURCC_FGDM || (*param_1 == FOURCC_FGDC)))) {
    uVar1 = crt_validateCodecSlots((int)param_1,(short)param_1[0x25],param_1[0x26],param_1[0x27]);
    if (param_1[0x27] != 0) {
      cast_freeHandle(param_1[0x27]);
      param_1[0x27] = 0;
    }
  }
  return uVar1;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68003730 - 0x68003c90
// Functions (15):
//   crt_openAndParse
//   crt_openAtOffset
//   crt_releaseChunkHandler
//   Ordinal_15
//   crt_setFormatContext
//   crt_getExtendedState
//   crt_cleanupResources
//   crt_getSlotTag
//   crt_searchChunkByType
//   crt_getChunkSizeEx
//   crt_getSlotOffset
//   crt_readChunkRange
//   Ordinal_17
//   crt_findNextChunk
//   crt_seekToChunkEnd

// ============================================================
// Function: crt_openAndParse (FUN_68003730)
// Address: 68003730
// Size: 240 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_openAndParse(int *param_1,int *param_2)
{
  int iVar1;
  int local_42c;
  int *local_428;
  int local_424;
  undefined4 local_420 [262];
  uint local_8;
  
  crt_lockRifx((int)param_1);
  if (param_1[1] == 0) {
    param_1[1] = (int)param_2;
    iVar1 = crt_flushStream(param_2);
    if (iVar1 != 0) goto LAB_680037fc;
    crt_copyStreamContext((undefined4 *)param_1[1],local_420);
    iVar1 = Ordinal_1313(local_420);
    param_1[6] = (uint)(iVar1 == 4);
  }
  iVar1 = crt_readRifxHeader((int *)param_1[1],param_1[0x11],&local_428,&local_42c,&local_424);
  if (iVar1 == 0) {
    if (*param_1 == 0) {
      *param_1 = local_42c;
    }
    param_1[5] = (uint)(local_424 != 0);
    if ((*param_1 == FOURCC_FGDM) || (*param_1 == FOURCC_FGDC)) {
      iVar1 = crt_openMxfMedia(param_1,local_42c,local_428);
    }
    else {
      iVar1 = crt_parseRifxFile(param_1,local_42c);
    }
  }
LAB_680037fc:
  param_1[4] = 1;
  param_1[2] = iVar1;
  crt_unlockRifx((int)param_1);
  return 0;
}



// ============================================================
// Function: crt_openAtOffset (FUN_68003820)
// Address: 68003820
// Size: 31 bytes
// Params: int * param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_openAtOffset(int *param_1,int *param_2,int param_3)
{
  int iVar1;

  param_1[0x11] = param_3;
  iVar1 = crt_openAndParse(param_1,param_2);
  param_1[2] = iVar1;
  return 0;
}



// ============================================================
// Function: crt_releaseChunkHandler (FUN_68003840)
// Address: 68003840
// Size: 83 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_releaseChunkHandler(int param_1,int param_2)

{
  int *piVar1;
  undefined **ppuVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  piVar1 = (int *)crt_getSlotEntry(param_1,param_2);
  if ((piVar1[4] == 0) || ((*(ushort *)(piVar1 + 3) & 0xc) != 0)) {
    iVar3 = 0;
  }
  else {
    ppuVar2 = core_getChunkHandler(*piVar1);
    iVar3 = (*(code *)ppuVar2[1])(param_1,extraout_EDX,extraout_ECX);
    if ((iVar3 == 0) && (param_2 != 2)) {
      piVar1[4] = 0;
      return 0;
    }
  }
  return iVar3;
}



// ============================================================
// Function: Ordinal_15
// Address: 680038a0
// Size: 21 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_15(int param_1)

{
                    /* 0x38a0  15   */
  if (param_1 == 0) {
    return 0;
  }
  return *(undefined4 *)(param_1 + 8);
}



// ============================================================
// Function: crt_setFormatContext (FUN_680038c0)
// Address: 680038c0
// Size: 52 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_setFormatContext(int *param_1,int *param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != (int *)0x0) && ((*param_1 == FOURCC_FGDM || (*param_1 == FOURCC_FGDC)))) {
    uVar1 = crt_seekMxfMedia(param_1,param_2);
    return uVar1;
  }
  param_1[0x16] = (int)param_2;
  return 0;
}



// ============================================================
// Function: crt_getExtendedState (FUN_68003900)
// Address: 68003900
// Size: 31 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getExtendedState(int param_1)

{
  undefined4 uVar1;
  
  crt_lockRifx(param_1);
  uVar1 = *(undefined4 *)(param_1 + 0x58);
  crt_unlockRifx(param_1);
  return uVar1;
}



// ============================================================
// Function: crt_cleanupResources (FUN_68003920)
// Address: 68003920
// Size: 129 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_cleanupResources(int param_1)

{
  int *piVar1;
  undefined4 uVar2;
  
  crt_lockRifx(param_1);
  piVar1 = *(int **)(param_1 + 0x5c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x5c) = 0;
  }
  piVar1 = *(int **)(param_1 + 0x60);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x60) = 0;
  }
  *(undefined4 *)(param_1 + 100) = 0;
  if (*(int *)(param_1 + 0x68) != 0) {
    cast_freeHandle(*(int *)(param_1 + 0x68));
    *(undefined4 *)(param_1 + 0x68) = 0;
  }
  *(undefined4 *)(param_1 + 0x6c) = 0;
  *(undefined4 *)(param_1 + 0x70) = 0;
  if (*(int *)(param_1 + 0x54) == -1) {
    crt_unlockRifx(param_1);
    return 0xcb;
  }
  uVar2 = crt_validateSlot(param_1,*(int *)(param_1 + 0x54),4);
  crt_unlockRifx(param_1);
  return uVar2;
}



// ============================================================
// Function: crt_getSlotTag (FUN_680039b0)
// Address: 680039b0
// Size: 70 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getSlotTag(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  
  crt_lockRifx(param_1);
  iVar1 = crt_validateSlot(param_1,param_2,4);
  if (iVar1 == 0) {
    piVar2 = (int *)crt_getSlotEntry(param_1,param_2);
    iVar1 = *piVar2;
    crt_unlockRifx(param_1);
    return iVar1;
  }
  crt_unlockRifx(param_1);
  return param_1;
}



// ============================================================
// Function: crt_searchChunkByType (FUN_68003a00)
// Address: 68003a00
// Size: 108 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_searchChunkByType(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined **ppuVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  int iVar4;
  
  iVar4 = 0;
  if (param_1 != 0) {
    crt_lockRifx(param_1);
    iVar1 = crt_validateSlot(param_1,param_2,4);
    if (iVar1 == 0) {
      piVar2 = (int *)crt_getSlotEntry(param_1,param_2);
      if (((*(byte *)(piVar2 + 3) & 1) != 0) && (piVar2[4] != 0)) {
        ppuVar3 = core_getChunkHandler(*piVar2);
        iVar4 = (*(code *)ppuVar3[2])(param_1,extraout_EDX,extraout_ECX);
        crt_unlockRifx(param_1);
        return iVar4;
      }
      iVar4 = piVar2[1];
    }
    crt_unlockRifx(param_1);
  }
  return iVar4;
}



// ============================================================
// Function: crt_getChunkSizeEx (FUN_68003a70)
// Address: 68003a70
// Size: 151 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getChunkSizeEx(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined **ppuVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  if ((param_1 != (int *)0x0) && ((*param_1 == FOURCC_FGDM || (*param_1 == FOURCC_FGDC)))) {
    iVar1 = crt_getCodecEntryOffset((int)param_1,param_2);
    return iVar1;
  }
  crt_lockRifx((int)param_1);
  iVar1 = crt_validateSlot((int)param_1,param_2,4);
  if (iVar1 != 0) {
    crt_unlockRifx((int)param_1);
    return param_2;
  }
  piVar2 = (int *)crt_getSlotEntry((int)param_1,param_2);
  if (((*(byte *)(piVar2 + 3) & 1) != 0) && (piVar2[4] != 0)) {
    ppuVar3 = core_getChunkHandler(*piVar2);
    iVar1 = (*(code *)ppuVar3[2])(param_1,extraout_EDX,extraout_ECX);
    crt_unlockRifx((int)param_1);
    return iVar1;
  }
  iVar1 = piVar2[1];
  crt_unlockRifx((int)param_1);
  return iVar1;
}



// ============================================================
// Function: crt_getSlotOffset (FUN_68003b10)
// Address: 68003b10
// Size: 71 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getSlotOffset(int param_1,int param_2)

{
  int iVar1;

  crt_lockRifx(param_1);
  iVar1 = crt_validateSlot(param_1,param_2,4);
  if (iVar1 == 0) {
    iVar1 = crt_getSlotEntry(param_1,param_2);
    iVar1 = *(int *)(iVar1 + 8);
    crt_unlockRifx(param_1);
    return iVar1;
  }
  crt_unlockRifx(param_1);
  return param_1;
}



// ============================================================
// Function: crt_readChunkRange (FUN_68003b60)
// Address: 68003b60
// Size: 123 bytes
// Params: int param_1, int param_2, int * param_3, int * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_readChunkRange(int param_1,int param_2,int *param_3,int *param_4)

{
  int iVar1;
  int iVar2;
  
  crt_lockRifx(param_1);
  iVar1 = crt_validateSlot(param_1,param_2,4);
  if (iVar1 == 0) {
    if (param_3 != (int *)0x0) {
      iVar2 = crt_getSlotTag(param_1,param_2);
      *param_3 = iVar2;
    }
    if (param_4 != (int *)0x0) {
      iVar2 = crt_searchChunkByType(param_1,param_2);
      *param_4 = iVar2;
    }
  }
  else {
    if (param_3 != (int *)0x0) {
      *param_3 = 0;
    }
    if (param_4 != (int *)0x0) {
      *param_4 = 0;
      crt_unlockRifx(param_1);
      return iVar1;
    }
  }
  crt_unlockRifx(param_1);
  return iVar1;
}



// ============================================================
// Function: Ordinal_17
// Address: 68003be0
// Size: 81 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_17(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
                    /* 0x3be0  17   */
  crt_lockRifx(param_1);
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 8);
  iVar3 = 3;
  if (3 < iVar1) {
    do {
      piVar2 = (int *)crt_getSlotEntry(param_1,iVar3);
      if (((param_2 == 0) && ((*(byte *)(piVar2 + 3) & 4) == 0)) || (*piVar2 == param_2))
      goto LAB_68003c22;
      iVar3 = iVar3 + 1;
    } while (iVar3 < iVar1);
  }
  iVar3 = -1;
LAB_68003c22:
  crt_unlockRifx(param_1);
  return iVar3;
}



// ============================================================
// Function: crt_findNextChunk (FUN_68003c40)
// Address: 68003c40
// Size: 79 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_findNextChunk(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  
  crt_lockRifx(param_1);
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 8);
  while (param_3 = param_3 + 1, param_3 < iVar1) {
    piVar2 = (int *)crt_getSlotEntry(param_1,param_3);
    if (((param_2 == 0) && ((*(byte *)(piVar2 + 3) & 4) == 0)) || (*piVar2 == param_2))
    goto LAB_68003c80;
  }
  param_3 = 0;
LAB_68003c80:
  crt_unlockRifx(param_1);
  return param_3;
}



// ============================================================
// Function: crt_seekToChunkEnd (FUN_68003c90)
// Address: 68003c90
// Size: 52 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_seekToChunkEnd(int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0xb0) + 0x350);
  if (*piVar1 != 0) {
    (*(code *)*piVar1)();
  }
  *(int *)(param_1 + 0x50) = *(int *)(param_1 + 0x50) + param_2;
  if (*(code **)(param_1 + 0x4c) != (code *)0x0) {
    (**(code **)(param_1 + 0x4c))(*(undefined4 *)(param_1 + 0x50));
  }
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68003cd0 - 0x68004310
// Functions (13):
//   crt_getChunkShortField
//   crt_getChunkCount
//   crt_setChunkCount
//   crt_getMovieStateDirect
//   crt_setMovieState
//   crt_getFileEndOffset
//   crt_getJunkTotalSize
//   crt_readFormatEntry
//   crt_insertChunk
//   crt_findChunkByTag
//   crt_loadChunkDataEx
//   crt_allocFormatList
//   crt_freeFormatList

// ============================================================
// Function: crt_getChunkShortField (FUN_68003cd0)
// Address: 68003cd0
// Size: 14 bytes
// Params: int param_1
// Return: undefined2
// Calling convention: __stdcall
// ============================================================

undefined2 crt_getChunkShortField(int param_1)

{
  return *(undefined2 *)(param_1 + 0x34);
}



// ============================================================
// Function: crt_getChunkCount (FUN_68003ce0)
// Address: 68003ce0
// Size: 23 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getChunkCount(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0xc);
  }
  return 0;
}



// ============================================================
// Function: crt_setChunkCount (FUN_68003d00)
// Address: 68003d00
// Size: 16 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_setChunkCount(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return 0;
}



// ============================================================
// Function: crt_getMovieStateDirect (FUN_68003d10)
// Address: 68003d10
// Size: 31 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getMovieStateDirect(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0xac);
  }
  return *(undefined4 *)(param_1 + 0xa8);
}



// ============================================================
// Function: crt_setMovieState (FUN_68003d30)
// Address: 68003d30
// Size: 28 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_setMovieState(int param_1,undefined4 param_2,undefined4 param_3)
{
  *(undefined4 *)(param_1 + 0xa8) = param_2;
  *(undefined4 *)(param_1 + 0xac) = param_3;
  return 0;
}



// ============================================================
// Function: crt_getFileEndOffset (FUN_68003d50)
// Address: 68003d50
// Size: 90 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getFileEndOffset(int *param_1)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  iVar2 = 0;
  if (param_1 != (int *)0x0) {
    if ((*param_1 == FOURCC_FGDM) || (*param_1 == FOURCC_FGDC)) {
      iVar1 = crt_streamReadAt(param_1[1],&local_8);
      iVar2 = local_8;
      if (iVar1 != 0) {
        return 0;
      }
    }
    else {
      crt_lockRifx((int)param_1);
      local_8 = crt_getChunkListRef((int)param_1);
      crt_unlockRifx((int)param_1);
      iVar2 = local_8;
    }
  }
  return iVar2;
}



// ============================================================
// Function: crt_getJunkTotalSize (FUN_68003db0)
// Address: 68003db0
// Size: 108 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getJunkTotalSize(int *param_1)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_8;
  
  iVar1 = 0;
  local_8 = 0;
  if (((param_1 != (int *)0x0) && (*param_1 != FOURCC_FGDM)) && (*param_1 != FOURCC_FGDC)) {
    crt_lockRifx((int)param_1);
    iVar1 = *(int *)(param_1[8] + 8);
    iVar3 = 3;
    if (3 < iVar1) {
      do {
        piVar2 = (int *)crt_getSlotEntry((int)param_1,iVar3);
        if (*piVar2 == FOURCC_junk) {
          local_8 = local_8 + piVar2[1];
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < iVar1);
    }
    crt_unlockRifx((int)param_1);
    iVar1 = local_8;
  }
  return iVar1;
}



// ============================================================
// Function: crt_readFormatEntry (FUN_68003e20)
// Address: 68003e20
// Size: 162 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_readFormatEntry(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *unaff_EDI;
  int local_8;
  
  iVar2 = unaff_EDI[0x2c];
  local_8 = 0;
  crt_lockRifx((int)unaff_EDI);
  iVar3 = crt_getSlotEntry((int)unaff_EDI,param_2);
  if (*(int *)(iVar3 + 8) != -1) {
    if ((*(byte *)(iVar3 + 0xc) & 0x20) != 0) {
      iVar4 = crt_findChunkByTag(unaff_EDI,param_2,iVar3,1);
      *(ushort *)(iVar3 + 0xc) = *(ushort *)(iVar3 + 0xc) & 0xffdf;
      *(undefined4 *)(*(int *)(iVar2 + 0x350) + 0xc) = 0xffffffff;
      crt_unlockRifx((int)unaff_EDI);
      return iVar4;
    }
    local_8 = crt_getFormatState(*(int **)(*(int *)(iVar2 + 0x350) + 4),param_1);
    if ((local_8 == 0) && (*(int *)(*(int *)(iVar2 + 0x350) + 0xc) != -1)) {
      piVar1 = (int *)(*(int *)(iVar2 + 0x350) + 0xc);
      *piVar1 = *piVar1 + -1;
    }
  }
  crt_unlockRifx((int)unaff_EDI);
  return local_8;
}



// ============================================================
// Function: crt_insertChunk (FUN_68003ed0)
// Address: 68003ed0
// Size: 188 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_insertChunk(undefined4 *param_1,int param_2,int param_3)
{
  int iVar1;
  undefined4 local_24;
  int local_20;
  int local_1c;
  uint local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  Ordinal_2330();
  local_14 = *param_1;
  local_18 = (uint)(param_3 == -1);
  local_10 = DAT_68196374;
  local_c = 1;
  DAT_68196374 = &local_14;
  iVar1 = crt_getFormatCount(*(int **)(param_1[0xd4] + 4));
  while (iVar1 = iVar1 + -1, -1 < iVar1) {
    crt_formatError(*(int **)(param_1[0xd4] + 4),iVar1,&local_1c,&local_24,&local_20);
    if ((local_20 == param_2) && ((local_1c == param_3 || (local_18 != 0)))) {
      crt_readFormatEntry(iVar1,local_1c);
    }
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_findChunkByTag (FUN_68003f90)
// Address: 68003f90
// Size: 461 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_findChunkByTag(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  puVar1 = (undefined4 *)param_1[0x2c];
  iVar2 = **(int **)(param_3 + 0x10);
  piVar4 = (int *)0x0;
  if ((*(ushort *)(param_3 + 0xc) & 0x20) != 0) {
    if ((*(ushort *)(param_3 + 0xc) & 0x100) == 0) {
      if ((*param_1 == FOURCC_FGDM) || (*param_1 == FOURCC_FGDC)) {
        iVar5 = crt_getCodecEntryOffset((int)param_1,param_2);
      }
      else {
        iVar5 = *(int *)(param_3 + 4);
      }
      iVar6 = puVar1[0xd4];
      iVar3 = *(int *)(iVar6 + 8);
      if (iVar3 != iVar5) {
        if (param_4 == 0) {
          if (iVar5 - *(int *)(iVar6 + 8) < *(int *)(iVar6 + 0x1c)) {
            iVar5 = iVar5 - iVar3;
          }
          else {
            iVar5 = *(int *)(iVar6 + 0x1c);
          }
        }
        else {
          iVar5 = iVar5 - iVar3;
        }
        if ((*param_1 == FOURCC_FGDM) || (*param_1 == FOURCC_FGDC)) {
          iVar6 = 0;
        }
        else {
          iVar6 = 8;
        }
        iVar6 = crt_streamRead(param_1[1],iVar3 + param_1[0x24] + *(int *)(param_3 + 8) + iVar6);
        if (iVar6 != 0) {
          return iVar6;
        }
        iVar6 = crt_writeStreamData(param_1[1],*(int *)(puVar1[0xd4] + 8) + iVar2,iVar5);
        if (iVar6 != 0) {
          return iVar6;
        }
        *(int *)(puVar1[0xd4] + 8) = *(int *)(puVar1[0xd4] + 8) + iVar5;
        if (param_4 == 0) {
          return 0;
        }
      }
      piVar4 = (int *)lingo_noop();
      if ((iVar5 == 0) || ((*param_1 != FOURCC_FGDM && (*param_1 != FOURCC_FGDC)))) {
        Ordinal_1115(*(undefined4 *)(param_3 + 0x10));
        *(ushort *)(param_3 + 0xc) = *(ushort *)(param_3 + 0xc) & 0xffdf | 0x40;
        crt_insertChunk(puVar1,(int)param_1,param_2);
        *(undefined4 *)(puVar1[0xd4] + 0xc) = 0xffffffff;
      }
      else {
        *(ushort *)(param_3 + 0xc) = *(ushort *)(param_3 + 0xc) | 0x100;
        if ((param_4 != 0) &&
           (piVar4 = (int *)crt_decodeStreamFrames(param_1,param_2,param_3,iVar2,param_4),
           (*(byte *)(param_3 + 0xc) & 0x40) != 0)) {
          *(undefined4 *)(puVar1[0xd4] + 0xc) = 0xffffffff;
        }
      }
      param_1 = piVar4;
      *(undefined4 *)(puVar1[0xd4] + 8) = 0;
      piVar4 = param_1;
    }
    else {
      piVar4 = (int *)crt_decodeStreamFrames(param_1,param_2,param_3,iVar2,1);
      if ((*(byte *)(param_3 + 0xc) & 0x40) != 0) {
        *(undefined4 *)(puVar1[0xd4] + 0xc) = 0xffffffff;
        return (int)piVar4;
      }
    }
  }
  return (int)piVar4;
}



// ============================================================
// Function: crt_loadChunkDataEx (FUN_68004160)
// Address: 68004160
// Size: 300 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_loadChunkDataEx(int param_1,int param_2)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined **ppuVar3;
  int iVar4;
  int *unaff_EDI;
  int local_8;
  
  puVar1 = (undefined4 *)unaff_EDI[0x2c];
  iVar4 = 0;
  local_8 = 0;
  crt_lockRifx((int)unaff_EDI);
  piVar2 = (int *)crt_getSlotEntry((int)unaff_EDI,param_1);
  if (piVar2[2] == -1) goto LAB_680041d1;
  if ((*(ushort *)(piVar2 + 3) & 0xc0) == 0) {
    if ((*(ushort *)(piVar2 + 3) & 0x20) == 0) {
      if (unaff_EDI[1] == 0) {
        iVar4 = 0xca;
      }
      else {
        ppuVar3 = core_getChunkHandler(*piVar2);
        if ((*unaff_EDI == FOURCC_FGDM) || (*unaff_EDI == FOURCC_FGDC)) {
          crt_getCodecEntryOffset((int)unaff_EDI,param_1);
        }
        local_8 = (*(code *)*ppuVar3)();
        if (local_8 != 0) {
          piVar2[4] = local_8;
          Ordinal_1114(local_8);
          iVar4 = crt_streamRead(unaff_EDI[1],piVar2[2] + 8);
          *(ushort *)(piVar2 + 3) = *(ushort *)(piVar2 + 3) | 0x20;
          *(undefined4 *)(puVar1[0xd4] + 8) = 0;
          if (param_2 != 0) goto LAB_680041a2;
          goto LAB_680041af;
        }
        iVar4 = DAT_68195a8c;
        if (DAT_68195a8c == 0) {
          iVar4 = 0xd1;
        }
      }
    }
    else {
LAB_680041a2:
      iVar4 = crt_findChunkByTag(unaff_EDI,param_1,(int)piVar2,param_2);
LAB_680041af:
      if (iVar4 == 0) goto LAB_680041d1;
    }
    cast_freeHandle(local_8);
    piVar2[4] = 0;
  }
  crt_insertChunk(puVar1,(int)unaff_EDI,param_1);
LAB_680041d1:
  unaff_EDI[2] = iVar4;
  crt_unlockRifx((int)unaff_EDI);
  return iVar4;
}



// ============================================================
// Function: crt_allocFormatList (FUN_68004290)
// Address: 68004290
// Size: 122 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_allocFormatList(undefined4 *param_1)
{
  undefined4 uVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  uVar1 = crt_allocSortedArray(0);
  *(undefined4 *)(param_1[0xd4] + 4) = uVar1;
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_freeFormatList (FUN_68004310)
// Address: 68004310
// Size: 101 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_freeFormatList(undefined4 *param_1)
{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  score_freePropertyHandle(*(undefined4 *)(param_1[0xd4] + 4));
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



