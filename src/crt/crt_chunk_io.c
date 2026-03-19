// Module: crt
// Topic: Chunk I/O, file stream operations, error translation, data reading/writing
// Address range: 0x68004380 - 0x68005D20
// Functions (52):
//   crt_insertAndClearSlot - crt_chunkNoop (chunk flush, status, callbacks, Ordinal_12/22/23/18)
//   crt_loadAllSlots - crt_seekFormatEntry (chunk load, Ordinal_16, data copy, iterate)
//   Ordinal_14 - crt_getStreamSize (close, seek, error translation, stream I/O wrappers)
//   crt_streamTruncate - crt_writeChunkData (stream truncate/flush/open, file byte-swap, seek helpers)

// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68004380 - 0x680049e0
// Functions (14):
//   crt_insertAndClearSlot (FUN_68004380)
//   crt_getSlotDirtyFlag (FUN_680043e0)
//   crt_getSlotModifiedFlag (FUN_68004420)
//   crt_queueChunkCallback (FUN_68004460)
//   crt_flushFormatEntries (FUN_680044e0)
//   crt_loadFormatChunk (FUN_680045a0)
//   crt_initFormatCursor (FUN_680046a0)
//   crt_setChunkCallback (FUN_680047b0)
//   crt_chunkNoop (FUN_68004820)
//   crt_isMediaFormat (FUN_68004880)
//   Ordinal_12
//   Ordinal_22
//   Ordinal_23
//   Ordinal_18

// ============================================================
// Function: crt_insertAndClearSlot (FUN_68004380)
// Address: 68004380
// Size: 91 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_insertAndClearSlot(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  puVar1 = *(undefined4 **)(param_1 + 0xb0);
  crt_lockRifx(param_1);
  iVar2 = crt_insertChunk(puVar1,param_1,param_2);
  if (iVar2 == 0) {
    iVar3 = crt_getSlotEntry(param_1,param_2);
    if ((*(int *)(iVar3 + 8) != -1) && ((*(byte *)(iVar3 + 0xc) & 0x40) != 0)) {
      Ordinal_1113(iVar3 + 0x10);
      *(ushort *)(iVar3 + 0xc) = *(ushort *)(iVar3 + 0xc) & 0xffbf;
    }
  }
  crt_unlockRifx(param_1);
  return iVar2;
}



// ============================================================
// Function: crt_getSlotDirtyFlag (FUN_680043e0)
// Address: 680043e0
// Size: 56 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crt_getSlotDirtyFlag(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  crt_lockRifx(param_1);
  iVar1 = crt_getSlotEntry(param_1,param_2);
  if (*(int *)(iVar1 + 8) != -1) {
    uVar2 = ((int)*(short *)(iVar1 + 0xc) & 0x40U) >> 6;
  }
  crt_unlockRifx(param_1);
  return uVar2;
}



// ============================================================
// Function: crt_getSlotModifiedFlag (FUN_68004420)
// Address: 68004420
// Size: 56 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crt_getSlotModifiedFlag(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  crt_lockRifx(param_1);
  iVar1 = crt_getSlotEntry(param_1,param_2);
  if (*(int *)(iVar1 + 8) != -1) {
    uVar2 = ((int)*(short *)(iVar1 + 0xc) & 0x20U) >> 5;
  }
  crt_unlockRifx(param_1);
  return uVar2;
}



// ============================================================
// Function: crt_queueChunkCallback (FUN_68004460)
// Address: 68004460
// Size: 121 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_queueChunkCallback(int param_1,int param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(param_1 + 0xb0);
  iVar4 = 0;
  crt_lockRifx(param_1);
  iVar3 = crt_getSlotEntry(param_1,param_2);
  if ((*(int *)(iVar3 + 8) != -1) && ((*(ushort *)(iVar3 + 0xc) & 0x60) == 0)) {
    *(ushort *)(iVar3 + 0xc) = *(ushort *)(iVar3 + 0xc) & 0xff7f;
    iVar4 = crt_insertSortedEntry(*(int **)(*(int *)(iVar2 + 0x350) + 4),0,param_2,param_3,param_1);
    if ((iVar4 == 0) && (iVar2 = *(int *)(iVar2 + 0x350), *(int *)(iVar2 + 0xc) != -1)) {
      piVar1 = (int *)(iVar2 + 0xc);
      *piVar1 = *piVar1 + 1;
    }
  }
  crt_unlockRifx(param_1);
  return iVar4;
}



// ============================================================
// Function: crt_flushFormatEntries (FUN_680044e0)
// Address: 680044e0
// Size: 182 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_flushFormatEntries(undefined4 *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  iVar2 = crt_getFormatCount(*(int **)(param_1[0xd4] + 4));
  iVar1 = 0;
  while (iVar2 = iVar2 + -1, -1 < iVar2) {
    crt_formatError(*(int **)(param_1[0xd4] + 4),iVar2,&local_24,&local_20,&local_18);
    if (param_2 == local_20) {
      local_1c = 1;
      crt_readFormatEntry(iVar2,local_24);
      iVar1 = local_1c;
    }
    else {
      if (iVar1 != 0) break;
      iVar1 = 0;
    }
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_loadFormatChunk (FUN_680045a0)
// Address: 680045a0
// Size: 245 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_loadFormatChunk(undefined4 *param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  int local_20;
  int local_1c;
  int *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar3 = 0;
  Ordinal_2330();
  local_14 = *param_1;
  iVar1 = param_1[0xd4];
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  if (*(int *)(iVar1 + 0xc) != -1) {
    crt_formatError(*(int **)(iVar1 + 4),*(int *)(iVar1 + 0xc),&local_1c,&local_20,&local_18);
    iVar3 = crt_loadChunkDataEx(local_1c,1);
  }
  do {
    iVar1 = crt_getFormatCount(*(int **)(param_1[0xd4] + 4));
    do {
      iVar1 = iVar1 + -1;
      if (iVar1 < 0) goto LAB_68004672;
      crt_formatError(*(int **)(param_1[0xd4] + 4),iVar1,&local_1c,&local_20,&local_18);
    } while (param_2 != local_20);
    uVar2 = crt_getChunkSize(local_18,local_1c);
    if (uVar2 != 0) {
      iVar3 = crt_loadChunkDataEx(local_1c,1);
    }
  } while (iVar3 == 0);
LAB_68004672:
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_initFormatCursor (FUN_680046a0)
// Address: 680046a0
// Size: 256 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_initFormatCursor(undefined4 *param_1)
{
  int iVar1;
  uint uVar2;
  undefined4 local_20;
  int local_1c;
  int *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  iVar1 = crt_getFormatCount(*(int **)(param_1[0xd4] + 4));
  if (0 < iVar1) {
    if (*(int *)(param_1[0xd4] + 0xc) == -1) {
      while ((iVar1 = iVar1 + -1, -1 < iVar1 && (*(int *)(param_1[0xd4] + 0xc) == -1))) {
        crt_formatError(*(int **)(param_1[0xd4] + 4),iVar1,&local_1c,&local_20,&local_18);
        uVar2 = crt_getChunkSize(local_18,local_1c);
        if (uVar2 != 0) {
          *(int *)(param_1[0xd4] + 0xc) = iVar1;
        }
      }
    }
    iVar1 = param_1[0xd4];
    if (*(int *)(iVar1 + 0xc) != -1) {
      crt_formatError(*(int **)(iVar1 + 4),*(int *)(iVar1 + 0xc),&local_1c,&local_20,&local_18);
      crt_loadChunkDataEx(local_1c,0);
    }
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_setChunkCallback (FUN_680047b0)
// Address: 680047b0
// Size: 98 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_setChunkCallback(int param_1,undefined4 param_2)
{
  uint uVar1;
  
  Ordinal_2330();
  *(undefined4 *)(*(int *)(param_1 + 0x350) + 0x1c) = param_2;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_chunkNoop (FUN_68004820)
// Address: 68004820
// Size: 94 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_chunkNoop(void)
{
  uint uVar1;
  
  Ordinal_2330();
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: crt_isMediaFormat (FUN_68004880)
// Address: 68004880
// Size: 41 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_isMediaFormat(int *param_1)

{
  if ((param_1 != (int *)0x0) && ((*param_1 == FOURCC_FGDM || (*param_1 == FOURCC_FGDC)))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_12
// Address: 680048b0
// Size: 61 bytes
// Params: int * param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_12(int *param_1,int *param_2,int param_3,int param_4)
{
  int iVar1;
  
                    /* 0x48b0  12   */
  iVar1 = crt_openStreamForRead(param_2,&param_2);
  if (iVar1 == 0) {
    if (param_4 != 0) {
      crt_createRifx(param_1,param_2,param_3,0);
      return 0;
    }
    crt_openAtOffset(param_1,param_2,param_3);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_22
// Address: 680048f0
// Size: 123 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_22(uint param_1,int param_2)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* 0x48f0  22   */
  uVar1 = param_1;
  iVar3 = xtra_getScriptContext(param_1);
  iVar5 = param_2;
  iVar4 = crt_validateSlot(uVar1,param_2,4);
  if ((iVar4 == 0) && (iVar4 = crt_streamReadAt(iVar3,&param_1), uVar2 = param_1, iVar4 == 0)) {
    if ((param_1 & 1) != 0) {
      param_1 = param_1 + 1;
      iVar4 = crt_streamRead(iVar3,uVar2);
      if (iVar4 != 0) {
        return 0;
      }
      iVar4 = crt_streamWrite(iVar3,&param_1,1);
      if (iVar4 != 0) {
        return 0;
      }
    }
    crt_lockRifx(uVar1);
    iVar5 = crt_getSlotEntry(uVar1,iVar5);
    *(uint *)(iVar5 + 8) = param_1;
    crt_unlockRifx(uVar1);
    crt_resetStreamState(iVar3);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_23
// Address: 68004970
// Size: 110 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_23(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
                    /* 0x4970  23   */
  iVar1 = param_1;
  piVar2 = (int *)xtra_getScriptContext(param_1);
  iVar4 = param_2;
  iVar3 = crt_validateSlot(iVar1,param_2,4);
  if (iVar3 == 0) {
    iVar3 = crt_flushStream(piVar2);
    if (iVar3 == 0) {
      iVar3 = crt_streamReadAt((int)piVar2,&param_1);
      if (iVar3 == 0) {
        crt_lockRifx(iVar1);
        iVar4 = crt_getSlotEntry(iVar1,iVar4);
        iVar5 = param_1 - *(int *)(iVar4 + 8);
        *(int *)(iVar4 + 4) = iVar5;
        crt_advanceChunkList(iVar1,iVar5);
        *(ushort *)(iVar4 + 0xc) = *(ushort *)(iVar4 + 0xc) & 0xfffe;
        crt_unlockRifx(iVar1);
      }
    }
  }
  return iVar3;
}



// ============================================================
// Function: Ordinal_18
// Address: 680049e0
// Size: 62 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_18(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
                    /* 0x49e0  18   */
  iVar2 = 0;
  crt_lockRifx(param_1);
  iVar1 = crt_getSlotEntry(param_1,param_2);
  if (iVar1 != 0) {
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(iVar1 + 4);
    }
    iVar2 = *(int *)(iVar1 + 8) + 8;
  }
  crt_unlockRifx(param_1);
  return iVar2;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68004a20 - 0x68005080
// Functions (8):
//   crt_loadAllSlots (FUN_68004a20)
//   crt_replaceChunkHandle (FUN_68004a80)
//   Ordinal_16
//   crt_loadChunkData (FUN_68004c90)
//   crt_readChunkAtOffset (FUN_68004d70)
//   crt_readSlotData (FUN_68004ee0)
//   crt_getStreamInfo
//   crt_seekFormatEntry (FUN_68005080)

// ============================================================
// Function: crt_loadAllSlots (FUN_68004a20)
// Address: 68004a20
// Size: 85 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_loadAllSlots(int param_1)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) {
    iVar2 = 3;
    if (3 < *(int *)(*(int *)(param_1 + 0x20) + 8)) {
      do {
        iVar1 = crt_releaseChunkHandler(param_1,iVar2);
        if (iVar1 != 0) {
          return iVar1;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < *(int *)(*(int *)(param_1 + 0x20) + 8));
    }
    iVar2 = 0;
    if (1 < *(int *)(*(int *)(param_1 + 0x20) + 8)) {
      iVar2 = crt_releaseChunkHandler(param_1,1);
    }
    return iVar2;
  }
  return 2;
}



// ============================================================
// Function: crt_replaceChunkHandle (FUN_68004a80)
// Address: 68004a80
// Size: 155 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_replaceChunkHandle(int param_1,undefined4 param_2)
{
  short *psVar1;
  undefined4 uVar2;
  int iVar3;
  int extraout_ECX;
  int iVar4;
  
  Ordinal_1115(*(undefined4 *)(param_1 + 0x1c));
  cast_freeHandle(*(undefined4 *)(param_1 + 0x1c));
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  if (0 < *(int *)(param_1 + 0x28)) {
    uVar2 = Ordinal_1114(param_2);
    *(undefined4 *)(param_1 + 0x20) = uVar2;
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    iVar3 = Ordinal_1116(param_2);
    psVar1 = *(short **)(param_1 + 0x20);
    iVar4 = *(int *)(psVar1 + 4) * (int)psVar1[1] + (int)*psVar1;
    uVar2 = crt_checkMulOverflow((int)psVar1[1]);
    if (((short)uVar2 == 0) ||
       (uVar2 = crt_checkAddOverflow((int)*(short *)(extraout_ECX + 2) * *(int *)(extraout_ECX + 8)),
       (short)uVar2 == 0)) {
      *(undefined4 *)(param_1 + 8) = 0xd0;
      crt_initRifxSlots(param_1);
    }
    if ((iVar4 < 0) || (iVar3 < iVar4)) {
      *(undefined4 *)(param_1 + 8) = 0xd0;
      crt_initRifxSlots(param_1);
    }
  }
  return 0;
}



// ============================================================
// Function: Ordinal_16
// Address: 68004b20
// Size: 360 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_16(int *param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  undefined **ppuVar3;
  undefined4 extraout_ECX;
  int local_8;
  
                    /* 0x4b20  16   */
  local_8 = 0;
  crt_lockRifx((int)param_1);
  iVar1 = crt_validateSlot((int)param_1,param_2,4);
  if (iVar1 != 0) goto LAB_68004c52;
  piVar2 = (int *)crt_getSlotEntry((int)param_1,param_2);
  if ((piVar2[2] != -1) ||
     ((param_1 != (int *)0x0 && ((*param_1 == FOURCC_FGDM || (*param_1 == FOURCC_FGDC)))))) {
    if (param_1[1] == 0) {
      cast_freeHandle(0);
      param_1[2] = 0xca;
      crt_unlockRifx((int)param_1);
      return 0;
    }
    if (piVar2[4] == 0) {
      *(ushort *)(piVar2 + 3) = *(ushort *)(piVar2 + 3) | 0x80;
      ppuVar3 = core_getChunkHandler(*piVar2);
      local_8 = (*(code *)*ppuVar3)(param_1,extraout_ECX,piVar2[1]);
      if (local_8 == 0) {
        iVar1 = DAT_68195a8c;
        if (DAT_68195a8c == 0) {
          cast_freeHandle(0);
          param_1[2] = 0xd1;
          crt_unlockRifx((int)param_1);
          return 0;
        }
        goto LAB_68004c52;
      }
      iVar1 = (*(code *)ppuVar3[3])(param_1,local_8,param_2,piVar2[1],piVar2[2]);
      if (iVar1 != 0) goto LAB_68004c52;
    }
    else {
      iVar1 = 0;
      if ((*(byte *)(piVar2 + 3) & 0x20) != 0) {
        iVar1 = crt_findChunkByTag(param_1,param_2,(int)piVar2,1);
      }
      local_8 = piVar2[4];
      *(ushort *)(piVar2 + 3) = *(ushort *)(piVar2 + 3) & 0xffbf;
      piVar2[4] = 0;
    }
    crt_seekToChunkEnd((int)param_1,piVar2[1] + 8);
    if (iVar1 != 0) {
LAB_68004c52:
      cast_freeHandle(local_8);
      param_1[2] = iVar1;
      crt_unlockRifx((int)param_1);
      return 0;
    }
  }
  param_1[2] = 0;
  crt_unlockRifx((int)param_1);
  return local_8;
}



// ============================================================
// Function: crt_loadChunkData (FUN_68004c90)
// Address: 68004c90
// Size: 221 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_loadChunkData(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  undefined **ppuVar7;
  undefined4 extraout_ECX;
  int iVar8;
  
  iVar4 = param_1;
  crt_lockRifx(param_1);
  iVar5 = crt_validateSlot(param_1,param_2,4);
  if (iVar5 == 0) {
    piVar6 = (int *)crt_getSlotEntry(param_1,param_2);
    iVar8 = piVar6[4];
    if ((iVar8 != 0) || (iVar1 = piVar6[2], iVar1 == -1)) goto LAB_68004d56;
    if (*(int *)(param_1 + 4) == 0) {
      param_1 = 0xca;
      iVar5 = param_1;
    }
    else {
      iVar2 = *piVar6;
      iVar3 = piVar6[1];
      ppuVar7 = core_getChunkHandler(iVar2);
      iVar8 = (*(code *)*ppuVar7)(param_1,extraout_ECX,iVar3);
      if (iVar8 == 0) {
        param_1 = DAT_68195a8c;
        iVar5 = param_1;
        if (DAT_68195a8c == 0) {
          param_1 = 0xd1;
          iVar5 = param_1;
        }
      }
      else {
        iVar5 = (*(code *)ppuVar7[3])(param_1,iVar8,param_2,iVar3,iVar1);
        if (iVar5 == 0) {
          piVar6[4] = iVar8;
          crt_seekToChunkEnd(param_1,iVar3 + 8);
          goto LAB_68004d56;
        }
        (*(code *)ppuVar7[1])(param_1,iVar8,iVar2);
      }
    }
  }
  param_1 = iVar5;
  iVar8 = 0;
  iVar5 = param_1;
LAB_68004d56:
  param_1 = iVar5;
  *(int *)(iVar4 + 8) = param_1;
  crt_unlockRifx(iVar4);
  return iVar8;
}



// ============================================================
// Function: crt_readChunkAtOffset (FUN_68004d70)
// Address: 68004d70
// Size: 354 bytes
// Params: int * param_1, undefined4 param_2, int * param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_readChunkAtOffset(int *param_1,undefined4 param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar7 = param_1[1];
  iVar1 = param_1[0x2c];
  iVar8 = 0;
  if ((*param_1 == FOURCC_FGDM) || (*param_1 == FOURCC_FGDC)) {
    return 0xcb;
  }
  crt_lockRifx((int)param_1);
  iVar2 = param_1[0x15];
  iVar3 = param_1[0x16];
  iVar6 = crt_getSlotEntry((int)param_1,iVar2);
  if ((iVar6 == 0) || (iVar4 = *(int *)(iVar6 + 8), iVar4 == -1)) {
    if (param_4 != 0) {
      *param_3 = 0;
      param_1[2] = 0;
      crt_unlockRifx((int)param_1);
      return 0;
    }
LAB_68004df0:
    iVar8 = 0xce;
  }
  else {
    iVar5 = *(int *)(iVar6 + 0x10);
    if (*(uint *)(iVar6 + 4) < (uint)(*param_3 + iVar3)) {
      if (param_4 == 0) goto LAB_68004df0;
      *param_3 = *(uint *)(iVar6 + 4) - iVar3;
    }
    if (*param_3 < 1) goto LAB_68004ebe;
    if (iVar5 == 0) {
      iVar8 = crt_streamRead(iVar7,iVar4 + 8 + iVar3);
      if ((iVar8 != 0) || (iVar8 = crt_writeStreamData(iVar7,param_2,*param_3), iVar8 != 0))
      goto LAB_68004eb7;
    }
    else {
      if (((*(byte *)(iVar6 + 0xc) & 0x20) != 0) &&
         (*(uint *)(*(int *)(iVar1 + 0x350) + 8) < (uint)(*param_3 + iVar3))) {
        iVar8 = crt_findChunkByTag(param_1,iVar2,iVar6,1);
      }
      iVar7 = Ordinal_1114(iVar5);
      Ordinal_1129(param_2,iVar7 + iVar3,*param_3);
      Ordinal_1115(iVar5);
    }
    param_1[0x16] = param_1[0x16] + *param_3;
    crt_seekToChunkEnd((int)param_1,*param_3);
    if (iVar8 == 0) goto LAB_68004ebe;
  }
LAB_68004eb7:
  param_1[0x15] = -1;
LAB_68004ebe:
  param_1[2] = iVar8;
  crt_unlockRifx((int)param_1);
  return iVar8;
}



// ============================================================
// Function: crt_readSlotData (FUN_68004ee0)
// Address: 68004ee0
// Size: 288 bytes
// Params: int * param_1, int param_2, int * param_3, undefined4 param_4, int * param_5, int param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_readSlotData(int *param_1,int param_2,int *param_3,undefined4 param_4,int *param_5,int param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  piVar2 = param_1;
  iVar5 = param_1[1];
  param_1 = (int *)0x0;
  crt_lockRifx((int)piVar2);
  iVar1 = *param_3;
  iVar3 = crt_getSlotEntry((int)piVar2,param_2);
  if (*(int *)(iVar3 + 8) == -1) {
    if (param_6 != 0) {
      *param_5 = 0;
    }
LAB_68004f27:
    param_1 = (int *)0xce;
  }
  else {
    iVar6 = piVar2[0x24] + *(int *)(iVar3 + 8);
    uVar4 = crt_getChunkSizeEx(piVar2,param_2);
    iVar3 = *(int *)(iVar3 + 0x10);
    if (uVar4 < (uint)(*param_5 + iVar1)) {
      if (param_6 == 0) goto LAB_68004f27;
      *param_5 = uVar4 - iVar1;
      if ((int)(uVar4 - iVar1) < 1) {
        param_1 = (int *)0xce;
        goto LAB_68004f6e;
      }
    }
    else {
LAB_68004f6e:
      if (*param_5 < 1) goto LAB_68004fe9;
    }
    if (iVar3 == 0) {
      if ((*piVar2 != FOURCC_FGDM) && (*piVar2 != FOURCC_FGDC)) {
        iVar6 = iVar6 + 8;
      }
      param_1 = (int *)crt_streamRead(iVar5,iVar6 + iVar1);
      if ((param_1 != (int *)0x0) ||
         (param_1 = (int *)crt_writeStreamData(iVar5,param_4,*param_5), param_1 != (int *)0x0))
      goto LAB_68004fe9;
    }
    else {
      iVar5 = Ordinal_1114(iVar3);
      Ordinal_1129(param_4,iVar5 + iVar1,*param_5);
      Ordinal_1115(iVar3);
    }
    *param_3 = *param_3 + *param_5;
    crt_seekToChunkEnd((int)piVar2,*param_5);
  }
LAB_68004fe9:
  piVar2[2] = (int)param_1;
  crt_unlockRifx((int)piVar2);
  return (int)param_1;
}



// ============================================================
// Function: crt_getStreamInfo (FUN_68005000)
// Address: 68005000
// Size: 128 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getStreamInfo(int *param_1)

{
  int iVar1;
  int iVar2;
  
  crt_lockRifx((int)param_1);
  if ((param_1 == (int *)0x0) || ((*param_1 != FOURCC_FGDM && (*param_1 != FOURCC_FGDC)))) {
    iVar1 = crt_cleanupResources((int)param_1);
  }
  else {
    iVar1 = crt_resetMxfCodec(param_1);
  }
  if ((iVar1 == 0) && (iVar2 = crt_getSlotEntry((int)param_1,param_1[0x15]), *(int *)(iVar2 + 8) != -1))
  {
    if ((*(ushort *)(iVar2 + 0xc) & 0x40) == 0) {
      *(ushort *)(iVar2 + 0xc) = *(ushort *)(iVar2 + 0xc) | 0x80;
    }
    else {
      Ordinal_1113(iVar2 + 0x10);
      *(ushort *)(iVar2 + 0xc) = *(ushort *)(iVar2 + 0xc) & 0xffbf;
    }
    param_1[0x15] = -1;
  }
  crt_unlockRifx((int)param_1);
  return iVar1;
}



// ============================================================
// Function: crt_seekFormatEntry (FUN_68005080)
// Address: 68005080
// Size: 182 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_seekFormatEntry(undefined4 *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c [3];
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_1c[1] = 1;
  Ordinal_2330();
  local_1c[2] = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = local_1c + 2;
  crt_initFormatCursor(param_1);
  iVar1 = crt_getFormatCount(*(int **)(param_1[0xd4] + 4));
  iVar2 = 0;
  if (0 < iVar1) {
    do {
      crt_formatError(*(int **)(param_1[0xd4] + 4),iVar2,&local_24,local_1c,&local_20);
      if (param_2 == local_1c[0]) {
        local_1c[1] = 0;
        break;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar1);
  }
  DAT_68196374 = (int *)local_10;
  Ordinal_2331();
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68005140 - 0x68005740
// Functions (15):
//   Ordinal_14
//   crt_setReadSlot (FUN_680051f0)
//   crt_readChunkData (FUN_68005280)
//   core_translateErrorCode
//   crt_writeStreamData
//   crt_readStreamData
//   crt_streamWrite (FUN_68005580)
//   crt_streamRead (FUN_680055c0)
//   crt_streamSeek (FUN_680055f0)
//   crt_streamGetPos (FUN_68005630)
//   crt_streamIsOpen (FUN_68005660)
//   crt_allocStreamBuffer (FUN_68005680)
//   crt_freeStreamBuffer (FUN_680056d0)
//   crt_streamReadAt (FUN_680056f0)
//   crt_getStreamSize

// ============================================================
// Function: Ordinal_14
// Address: 68005140
// Size: 164 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int Ordinal_14(int *param_1)

{
  int iVar1;
  
                    /* 0x5140  14   */
  crt_insertChunk((undefined4 *)param_1[0x2c],(int)param_1,-1);
  iVar1 = param_1[1];
  crt_getStreamInfo(param_1);
  crt_lockRifx((int)param_1);
  if (param_1[4] != 0) {
    iVar1 = crt_resetStreamState(iVar1);
    if (iVar1 != 0) goto LAB_680051d3;
    param_1[4] = 0;
  }
  iVar1 = crt_loadAllSlots((int)param_1);
  if (iVar1 == 0) {
    if ((*param_1 == FOURCC_FGDM) || (*param_1 == FOURCC_FGDC)) {
      crt_freeMediaCodecHandles((int)param_1);
      lingo_noop();
      crt_releaseCodecArray((short *)(param_1 + 0x25),param_1 + 0x26,param_1 + 0x27);
      if (param_1[0x28] != 0) {
        cast_freeHandle(param_1[0x28]);
      }
    }
    crt_initRifxSlots((int)param_1);
  }
LAB_680051d3:
  param_1[2] = iVar1;
  crt_unlockRifx((int)param_1);
  return iVar1;
}



// ============================================================
// Function: crt_setReadSlot (FUN_680051f0)
// Address: 680051f0
// Size: 131 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_setReadSlot(int *param_1,int param_2)

{
  int iVar1;
  
  crt_lockRifx((int)param_1);
  iVar1 = crt_validateSlot((int)param_1,param_2,4);
  if (iVar1 == 0) {
    if (param_1[0x17] != 0) {
      crt_unlockRifx((int)param_1);
      return 0xd4;
    }
    if (param_1[0x15] != -1) {
      crt_getStreamInfo(param_1);
    }
    param_1[0x15] = param_2;
    param_1[0x16] = 0;
    if ((*param_1 == FOURCC_FGDM) || (*param_1 == FOURCC_FGDC)) {
      iVar1 = crt_prepareMxfCodec(param_1);
      if (iVar1 != 0) goto LAB_68005264;
    }
    crt_seekToChunkEnd((int)param_1,8);
  }
LAB_68005264:
  crt_unlockRifx((int)param_1);
  return iVar1;
}



// ============================================================
// Function: crt_readChunkData (FUN_68005280)
// Address: 68005280
// Size: 123 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_readChunkData(int *param_1,int param_2,int *param_3)

{
  int iVar1;
  
  if ((param_1 != (int *)0x0) && ((*param_1 == FOURCC_FGDM || (*param_1 == FOURCC_FGDC)))) {
    if (param_1[0x17] == 0) {
      return 0xcb;
    }
    iVar1 = crt_readMxfStream(param_1,param_2,(int *)*param_3,param_3);
    param_1[0x16] = param_1[0x16] + *param_3;
    return iVar1;
  }
  iVar1 = crt_readChunkAtOffset(param_1,param_2,param_3,1);
  if (iVar1 == 0x1f6) {
    return 0;
  }
  if ((iVar1 == 0) && (*param_3 < 1)) {
    iVar1 = 0xce;
  }
  return iVar1;
}



// ============================================================
// Function: core_translateErrorCode (FUN_68005300)
// Address: 68005300
// Size: 333 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int core_translateErrorCode(int param_1)

{
  if (param_1 < -0x7ffbfc7b) {
    if (param_1 == -0x7ffbfc7c) {
      return -0x3b;
    }
    switch(param_1) {
    case -0x7ffbffff:
      return -0x32;
    case -0x7ffbfffe:
      return -0x6c;
    case -0x7ffbfffd:
      return 0x1f8;
    case -0x7ffbfffc:
      return 0x1f9;
    case -0x7ffbfffb:
      return 0x1fa;
    case -0x7ffbfffa:
      return -0x2b;
    case -0x7ffbfff9:
      return 0x1fb;
    case -0x7ffbfff8:
      return 0x1fc;
    case -0x7ffbfff7:
      return 0x1fd;
    case -0x7ffbfff6:
      return 0x1fe;
    case -0x7ffbffb0:
      return -0x26;
    case -0x7ffbffaf:
      return -0x31;
    case -0x7ffbffad:
    case -0x7ffbffaa:
      return -0x24;
    case -0x7ffbffac:
      return -0x27;
    case -0x7ffbffab:
      return -0x36;
    }
  }
  else if (param_1 < -0x7ffbed2f) {
    if (param_1 == -0x7ffbed30) {
      return -0x2d;
    }
    switch(param_1) {
    case -0x7ffbfc7a:
      return -0x30;
    case -0x7ffbfc79:
      return -0x22;
    case -0x7ffbfc78:
      return -0x2f;
    case -0x7ffbfc77:
      return -0x25;
    }
  }
  else if (param_1 < -0x7ffbed1b) {
    if (param_1 == -0x7ffbed1c) {
      return 0x1ff;
    }
    if (param_1 == -0x7ffbed20) {
      return 0x1f6;
    }
    if (param_1 == -0x7ffbed1f) {
      return 0x1f7;
    }
  }
  else if (param_1 == 0) {
    return 0;
  }
  return (int)(short)param_1;
}



// ============================================================
// Function: crt_writeStreamData (FUN_68005500)
// Address: 68005500
// Size: 53 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_writeStreamData(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 == (int *)0x0) {
    return 0x1f5;
  }
  iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,param_2,param_3,0);
  iVar2 = core_translateErrorCode(iVar2);
  return iVar2;
}



// ============================================================
// Function: crt_readStreamData (FUN_68005540)
// Address: 68005540
// Size: 53 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_readStreamData(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 == (int *)0x0) {
    return 0x1f5;
  }
  iVar2 = (**(code **)(*piVar1 + 0x18))(piVar1,param_2,param_3,0);
  iVar2 = core_translateErrorCode(iVar2);
  return iVar2;
}



// ============================================================
// Function: crt_streamWrite (FUN_68005580)
// Address: 68005580
// Size: 53 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_streamWrite(int param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 == (int *)0x0) {
    return 0x1f5;
  }
  iVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_2,param_3,0);
  iVar2 = core_translateErrorCode(iVar2);
  return iVar2;
}



// ============================================================
// Function: crt_streamRead (FUN_680055c0)
// Address: 680055c0
// Size: 47 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_streamRead(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 == (int *)0x0) {
    return 0x1f5;
  }
  iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,param_2);
  iVar2 = core_translateErrorCode(iVar2);
  return iVar2;
}



// ============================================================
// Function: crt_streamSeek (FUN_680055f0)
// Address: 680055f0
// Size: 49 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_streamSeek(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 == (int *)0x0) {
    return 0x1f5;
  }
  iVar2 = (**(code **)(*piVar1 + 0x34))(piVar1,param_2,1);
  iVar2 = core_translateErrorCode(iVar2);
  return iVar2;
}



// ============================================================
// Function: crt_streamGetPos (FUN_68005630)
// Address: 68005630
// Size: 42 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_streamGetPos(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 == (int *)0x0) {
    return -1;
  }
  (**(code **)(*piVar1 + 0x20))(piVar1,&param_1);
  return param_1;
}



// ============================================================
// Function: crt_streamIsOpen (FUN_68005660)
// Address: 68005660
// Size: 31 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool crt_streamIsOpen(int param_1)

{
  if (param_1 == 0) {
    return false;
  }
  return *(int *)(param_1 + 0x41c) != 0;
}



// ============================================================
// Function: crt_allocStreamBuffer (FUN_68005680)
// Address: 68005680
// Size: 69 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_allocStreamBuffer(int param_1,int *param_2,int *param_3)
{
  int iVar1;
  
  if (param_1 != 0) {
    *param_3 = 0x8000;
    do {
      iVar1 = cast_allocHandle(*param_3,1);
      *param_2 = iVar1;
      if (iVar1 != 0) break;
      *param_3 = *param_3 >> 1;
    } while (0 < *param_3);
    *(int *)(param_1 + 0x424) = *param_2;
  }
  return 0;
}



// ============================================================
// Function: crt_freeStreamBuffer (FUN_680056d0)
// Address: 680056d0
// Size: 30 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_freeStreamBuffer(int param_1)
{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x424) != 0)) {
    Ordinal_1113((int *)(param_1 + 0x424));
  }
  return 0;
}



// ============================================================
// Function: crt_streamReadAt (FUN_680056f0)
// Address: 680056f0
// Size: 66 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_streamReadAt(int param_1,undefined4 param_2)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x28))(piVar1,param_2);
    core_translateErrorCode(iVar2);
    return 0;
  }
  iVar2 = (**(code **)(**(int **)(param_1 + 0x418) + 0x1c))(*(int **)(param_1 + 0x418),param_2);
  core_translateErrorCode(iVar2);
  return 0;
}



// ============================================================
// Function: crt_getStreamSize (FUN_68005740)
// Address: 68005740
// Size: 47 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getStreamSize(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 == (int *)0x0) {
    return 0x1f5;
  }
  iVar2 = (**(code **)(*piVar1 + 0x3c))(piVar1,param_2);
  iVar2 = core_translateErrorCode(iVar2);
  return iVar2;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68005770 - 0x68005d20
// Functions (15):
//   crt_streamTruncate (FUN_68005770)
//   crt_streamFlush (FUN_680057a0)
//   crt_flushStream
//   crt_resetStreamState
//   crt_setByteOrder (FUN_68005900)
//   crt_commitStream (FUN_68005970)
//   crt_copyStreamContext (FUN_680059c0)
//   crt_restoreStreamContext (FUN_68005aa0)
//   crt_getStreamRef (FUN_68005b10)
//   crt_streamClose (FUN_68005b50)
//   crt_seekAndTruncate (FUN_68005b90)
//   crt_openStreamForRead
//   crt_copyByteSwapData (FUN_68005c80)
//   crt_writeStreamBlock
//   crt_writeChunkData (FUN_68005d20)

// ============================================================
// Function: crt_streamTruncate (FUN_68005770)
// Address: 68005770
// Size: 47 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_streamTruncate(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 == (int *)0x0) {
    return 0x1f5;
  }
  iVar2 = (**(code **)(*piVar1 + 0x38))(piVar1,param_2);
  iVar2 = core_translateErrorCode(iVar2);
  return iVar2;
}



// ============================================================
// Function: crt_streamFlush (FUN_680057a0)
// Address: 680057a0
// Size: 43 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_streamFlush(int param_1)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 == (int *)0x0) {
    return 0x1f5;
  }
  iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1);
  iVar2 = core_translateErrorCode(iVar2);
  return iVar2;
}



// ============================================================
// Function: crt_flushStream (FUN_680057d0)
// Address: 680057d0
// Size: 208 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_flushStream(int *param_1)
{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  
  piVar3 = param_1;
  if (param_1 == (int *)0x0) {
    core_translateErrorCode(-0x7ffbfffa);
    return 0;
  }
  piVar2 = (int *)param_1[0x106];
  piVar1 = param_1 + 0x107;
  if (param_1[0x107] != 0) {
    param_1 = piVar2;
    core_translateErrorCode(0);
    return 0;
  }
  param_1 = piVar2;
  iVar4 = (**(code **)(*piVar2 + 0x18))(piVar2,0,piVar1);
  if (iVar4 == 0) {
    iVar4 = piVar3[0x108];
    if (iVar4 == -1) {
      iVar4 = 1;
    }
    iVar5 = Ordinal_1313(piVar3);
    iVar4 = (**(code **)(*(int *)*piVar1 + 0xc))((int *)*piVar1,iVar4,(iVar5 != 4) + '\x01');
    if (iVar4 == 0) goto LAB_68005893;
    if (piVar3[0x108] == -1) {
      (**(code **)(*param_1 + 0x1c))(param_1,&param_1);
      iVar4 = (**(code **)(*(int *)*piVar1 + 0xc))((int *)*piVar1,0,1);
    }
    if (iVar4 == 0) goto LAB_68005893;
  }
  piVar3 = (int *)*piVar1;
  if (piVar3 != (int *)0x0) {
    (**(code **)(*piVar3 + 8))(piVar3);
    *piVar1 = 0;
  }
LAB_68005893:
  core_translateErrorCode(iVar4);
  return 0;
}



// ============================================================
// Function: crt_resetStreamState (FUN_680058a0)
// Address: 680058a0
// Size: 85 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_resetStreamState(int param_1)

{
  int *piVar1;
  int iVar2;
  
  if (param_1 == 0) {
    return 0x1f5;
  }
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 == (int *)0x0) {
    return 0x1f5;
  }
  iVar2 = (**(code **)(*piVar1 + 0x10))(piVar1);
  (**(code **)(*piVar1 + 8))(piVar1);
  *(undefined4 *)(param_1 + 0x41c) = 0;
  iVar2 = core_translateErrorCode(iVar2);
  return iVar2;
}



// ============================================================
// Function: crt_setByteOrder (FUN_68005900)
// Address: 68005900
// Size: 82 bytes
// Params: int param_1, undefined1 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_setByteOrder(int param_1,undefined1 param_2)
{
  if (param_1 != 0) {
    switch(param_2) {
    case 0:
      *(undefined4 *)(param_1 + 0x420) = 0xffffffff;
      return 0;
    case 1:
      *(undefined4 *)(param_1 + 0x420) = 0;
      return 0;
    case 2:
      *(undefined4 *)(param_1 + 0x420) = 2;
      return 0;
    case 3:
    case 4:
      *(undefined4 *)(param_1 + 0x420) = 1;
    }
  }
  return 0;
}



// ============================================================
// Function: crt_commitStream (FUN_68005970)
// Address: 68005970
// Size: 66 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_commitStream(int *param_1)
{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    core_translateErrorCode(-0x7ffbfffa);
    return 0;
  }
  iVar1 = (**(code **)(*(int *)param_1[0x106] + 0x48))((int *)param_1[0x106]);
  if (iVar1 != 0) {
    core_translateErrorCode(iVar1);
    return 0;
  }
  crt_flushStream(param_1);
  return 0;
}



// ============================================================
// Function: crt_copyStreamContext (FUN_680059c0)
// Address: 680059c0
// Size: 219 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Function: __alloca_probe replaced with injection: alloca_probe */

int crt_copyStreamContext(undefined4 *param_1,undefined4 *param_2)
{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 *puVar3;
  int *local_100c;
  undefined1 local_1008;
  undefined1 local_1007 [4095];
  uint local_8;
  
  if (param_1 != (undefined4 *)0x0) {
    iVar2 = Ordinal_1313(param_1);
    puVar3 = param_1;
    if (((iVar2 == 4) && (bVar1 = crt_streamIsOpen((int)param_1), CONCAT31(extraout_var,bVar1) != 0)) &&
       (iVar2 = (**(code **)(*(int *)param_1[0x107] + 0x44))((int *)param_1[0x107],&local_100c),
       iVar2 == 0)) {
      iVar2 = (**(code **)(*local_100c + 0x14))(local_100c,9,&local_1008,0x1000,"mmkey-realurl");
      (**(code **)(*local_100c + 8))(local_100c);
      if (iVar2 == 0) {
        Ordinal_1238(&local_1008,&local_1008,0x1000);
        Ordinal_1309(param_2,0x400,local_1007,4);
        puVar3 = param_2;
        param_2 = param_1;
      }
    }
    for (iVar2 = 0x106; iVar2 != 0; iVar2 = iVar2 + -1) {
      *param_2 = *puVar3;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
  }
  return 0;
}



// ============================================================
// Function: crt_restoreStreamContext (FUN_68005aa0)
// Address: 68005aa0
// Size: 103 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_restoreStreamContext(undefined4 *param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined1 local_407 [1023];
  uint local_8;
  
  puVar2 = param_2;
  puVar3 = param_1;
  for (iVar1 = 0x106; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *puVar2;
    puVar2 = puVar2 + 1;
    puVar3 = puVar3 + 1;
  }
  Ordinal_1310(param_2,local_407,0x3fe);
  iVar1 = (**(code **)(*(int *)param_1[0x106] + 0xc))((int *)param_1[0x106],local_407);
  core_translateErrorCode(iVar1);
  return 0;
}



// ============================================================
// Function: crt_getStreamRef (FUN_68005b10)
// Address: 68005b10
// Size: 53 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getStreamRef(int param_1,int *param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 0x41c);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 4))(piVar1);
    *param_2 = (int)piVar1;
    return 0;
  }
  *param_2 = 0;
  return 0;
}



// ============================================================
// Function: crt_streamClose (FUN_68005b50)
// Address: 68005b50
// Size: 61 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_streamClose(int param_1)
{
  int *piVar1;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0x418);
    crt_resetStreamState(param_1);
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(param_1 + 0x418) = 0;
    Ordinal_1125(&param_1);
  }
  return 0;
}



// ============================================================
// Function: crt_seekAndTruncate (FUN_68005b90)
// Address: 68005b90
// Size: 46 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_seekAndTruncate(int param_1,int param_2)
{
  int iVar1;
  int iVar2;

  iVar1 = param_1;
  crt_streamReadAt(param_1,&param_1);
  iVar2 = param_2;
  if (param_1 <= param_2) {
    crt_streamTruncate(iVar1,param_2);
  }
  crt_streamRead(iVar1,iVar2);
  return 0;
}



// ============================================================
// Function: crt_openStreamForRead (FUN_68005bc0)
// Address: 68005bc0
// Size: 189 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_openStreamForRead(undefined4 *param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  
  puVar1 = param_2;
  *param_2 = 0;
  iVar2 = Ordinal_1313(param_1);
  puVar4 = &DAT_681761b8;
  if (iVar2 != 4) {
    puVar4 = &DAT_681761a8;
  }
  param_2 = (undefined4 *)Ordinal_1124(0x428);
  if (param_2 == (undefined4 *)0x0) {
    core_translateErrorCode(-0x6c);
    return 0;
  }
  param_2[0x107] = 0;
  param_2[0x108] = 0xffffffff;
  uVar3 = Ordinal_1038(puVar4,&DAT_68176198,param_2 + 0x106);
  iVar2 = Ordinal_2063(uVar3);
  if (iVar2 != 0) {
    param_2[0x106] = 0;
    Ordinal_1125(&param_2);
    core_translateErrorCode(iVar2);
    return 0;
  }
  crt_restoreStreamContext(param_2,param_1);
  *puVar1 = param_2;
  core_translateErrorCode(0);
  return 0;
}



// ============================================================
// Function: crt_copyByteSwapData (FUN_68005c80)
// Address: 68005c80
// Size: 55 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_copyByteSwapData(int param_1,int param_2)
{
  ushort *in_EAX;
  
  if (param_2 != 0) {
    cast_copyPascalString(in_EAX,"2244444",0x18,0x18);
    cast_copyPascalString(in_EAX + 0xc,"444224",0x14,param_1 + -0x18);
  }
  return 0;
}



// ============================================================
// Function: crt_writeStreamBlock (FUN_68005cc0)
// Address: 68005cc0
// Size: 85 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_writeStreamBlock(int param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = crt_seekAndTruncate(*(int *)(param_1 + 4),param_4);
  if (iVar1 == 0) {
    local_c = param_2;
    local_8 = param_3;
    if (*(int *)(param_1 + 0x14) != 0) {
      cast_copyPascalString((ushort *)&local_c,"44",8,8);
    }
    crt_streamWrite(*(int *)(param_1 + 4),&local_c,8);
  }
  return 0;
}



// ============================================================
// Function: crt_writeChunkData (FUN_68005d20)
// Address: 68005d20
// Size: 84 bytes
// Params: int param_1, ushort * param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_writeChunkData(int param_1,ushort *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 == 0) {
    iVar1 = crt_writeStreamData(*(int *)(param_1 + 4),param_2,8);
  }
  else {
    iVar1 = crt_readStreamData(*(int *)(param_1 + 4),param_2,8);
  }
  if (((iVar1 != 0x1f6) && (iVar1 == 0)) && (*(int *)(param_1 + 0x14) != 0)) {
    cast_copyPascalString(param_2,"44",8,8);
  }
  return iVar1;
}



