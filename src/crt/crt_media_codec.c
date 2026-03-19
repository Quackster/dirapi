// Module: crt
// Topic: Media codec/format handling, MXF/FGD parsing, compression, decompression
// Address range: 0x68005D80 - 0x680081C0
// Functions (51):
//   crt_readAndWriteStream - crt_freeMediaCodecHandles (data write, format helpers, chunk known-types, codec init)
//   crt_decodeCodecFrame - crt_decodeStreamFrames (codec decode, variable-length read, streaming decode)
//   crt_parseFgdIndex - crt_checkMxfSlotReady (FGD/MXF index parse, chunk version scan, validity check)
//   crt_readMxfChunk - crt_readMxfStream (MXF chunk read, palette decode, MXF open/seek/read)
//   crt_seekMxfMedia - crt_allocCodecBlock (MXF seek, format negotiation, codec factory, error map)

// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68005d80 - 0x68006200
// Functions (17):
//   crt_readAndWriteStream
//   crt_getHandleSize
//   crt_freeMediaHandle
//   crt_readMediaData
//   crt_writeMediaEncoded
//   crt_writeMediaDirect
//   crt_getMediaFrameSize
//   crt_allocMediaHandle
//   crt_writeMediaFrame
//   crt_readAndDecodeMedia
//   crt_writeMediaRef
//   crt_isKnownChunkType
//   crt_initCodecStreams
//   crt_dispatchCodecOp
//   crt_finalizeCodecOp
//   crt_codecNoOp
//   crt_freeMediaCodecHandles

// ============================================================
// Function: crt_readAndWriteStream (FUN_68005d80)
// Address: 68005d80
// Size: 46 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_readAndWriteStream(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  int iVar1;
  
  iVar1 = crt_streamRead(*(int *)(param_1 + 4),param_4);
  if (iVar1 == 0) {
    crt_streamWrite(*(int *)(param_1 + 4),param_2,param_3);
  }
  return 0;
}



// ============================================================
// Function: crt_getHandleSize (FUN_68005db0)
// Address: 68005db0
// Size: 26 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getHandleSize(undefined4 param_1,int param_2)

{
  undefined4 uVar1;
  
  if (param_2 != 0) {
    uVar1 = Ordinal_1116(param_2);
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: crt_freeMediaHandle (FUN_68005dd0)
// Address: 68005dd0
// Size: 18 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_freeMediaHandle(undefined4 param_1,undefined4 param_2)

{
  cast_freeHandle(param_2);
  return 0;
}



// ============================================================
// Function: crt_readMediaData (FUN_68005df0)
// Address: 68005df0
// Size: 119 bytes
// Params: int * param_1, undefined4 param_2, int param_3, undefined4 param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_readMediaData(int *param_1,undefined4 param_2,int param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((param_1 != (int *)0x0) && ((*param_1 == FOURCC_FGDM || (*param_1 == FOURCC_FGDC)))) {
    iVar1 = crt_readMxfChunk((uint)param_1,param_3,param_2,param_4);
    return iVar1;
  }
  uVar2 = Ordinal_1114(param_2);
  iVar1 = crt_streamRead(param_1[1],param_5 + 8);
  if (iVar1 == 0) {
    iVar1 = crt_writeStreamData(param_1[1],uVar2,param_4);
  }
  Ordinal_1115(param_2);
  return iVar1;
}



// ============================================================
// Function: crt_writeMediaEncoded (FUN_68005e70)
// Address: 68005e70
// Size: 111 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_writeMediaEncoded(int param_1,int param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = param_2;
  iVar2 = crt_getHandleSize(param_1,param_2);
  if (param_2 != 0) {
    param_2 = Ordinal_1114(param_2);
  }
  iVar3 = crt_writeStreamBlock(param_1,param_3,iVar2,param_5);
  if ((iVar3 == 0) && (iVar2 != 0)) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar3 = crt_readAndWriteStream(param_1,param_2,param_4,param_5 + 8);
  }
  if (iVar1 != 0) {
    Ordinal_1115(iVar1);
  }
  return iVar3;
}



// ============================================================
// Function: crt_writeMediaDirect (FUN_68005ee0)
// Address: 68005ee0
// Size: 28 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_writeMediaDirect(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,int param_5)
{
  crt_writeStreamBlock(param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: crt_getMediaFrameSize (FUN_68005f00)
// Address: 68005f00
// Size: 24 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_getMediaFrameSize(int param_1)

{
  return (int)*(short *)(*(int *)(param_1 + 0x20) + 2) * *(int *)(*(int *)(param_1 + 0x20) + 4) +
         0x18;
}



// ============================================================
// Function: crt_allocMediaHandle (FUN_68005f20)
// Address: 68005f20
// Size: 18 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_allocMediaHandle(undefined4 param_1,undefined4 param_2,undefined4 param_3)
{
  cast_allocHandle(param_3,1);
  return 0;
}



// ============================================================
// Function: crt_writeMediaFrame (FUN_68005f40)
// Address: 68005f40
// Size: 83 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_writeMediaFrame(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  int iVar1;
  
  iVar1 = crt_writeStreamBlock(param_1,param_3,param_4,param_5);
  if (iVar1 == 0) {
    crt_copyByteSwapData(param_4,*(int *)(param_1 + 0x14));
    iVar1 = crt_readAndWriteStream(param_1,*(undefined4 *)(param_1 + 0x20),param_4,param_5 + 8);
    crt_copyByteSwapData(param_4,*(int *)(param_1 + 0x14));
  }
  return iVar1;
}



// ============================================================
// Function: crt_readAndDecodeMedia (FUN_68005fa0)
// Address: 68005fa0
// Size: 95 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_readAndDecodeMedia(int param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = Ordinal_1114(param_2);
  iVar2 = crt_streamRead(*(int *)(param_1 + 4),param_5 + 8);
  if (iVar2 == 0) {
    iVar2 = crt_writeStreamData(*(int *)(param_1 + 4),uVar1,param_4);
    if (iVar2 == 0) {
      crt_copyByteSwapData(param_4,*(int *)(param_1 + 0x14));
    }
  }
  Ordinal_1115(param_2);
  return iVar2;
}



// ============================================================
// Function: crt_writeMediaRef (FUN_68006010)
// Address: 68006010
// Size: 74 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_writeMediaRef(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 int param_5)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = param_5;
  puVar1 = param_1;
  param_1 = (undefined4 *)*param_1;
  iVar3 = crt_writeStreamBlock((int)puVar1,param_3,param_4,param_5);
  if (iVar3 == 0) {
    if (puVar1[5] != 0) {
      param_1 = (undefined4 *)cast_freeIfNonNull(param_1);
    }
    crt_readAndWriteStream((int)puVar1,&param_1,4,iVar2 + 8);
  }
  return 0;
}



// ============================================================
// Function: crt_isKnownChunkType (FUN_68006060)
// Address: 68006060
// Size: 42 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_isKnownChunkType(int param_1)

{
  int iVar1;
  char *pcVar2;
  
  pcVar2 = "*YEKFCRDFCWVlRTXdroS*SACtSACxtcLXtcLmanLCSWVrcsLpamFBLWVLTWVMFWVIFWVLsCMfniC lccnahC";
  iVar1 = FOURCC_KEYx;
  do {
    pcVar2 = (char *)((int)pcVar2 + 4);
    if (iVar1 == param_1) {
      return 1;
    }
    iVar1 = *(int *)pcVar2;
  } while (iVar1 != 0);
  return 0;
}



// ============================================================
// Function: crt_initCodecStreams (FUN_68006090)
// Address: 68006090
// Size: 164 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_initCodecStreams(int *param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  int *unaff_EBX;
  int *unaff_EDI;
  
  bVar1 = false;
  iVar2 = (**(code **)(*unaff_EDI + 0xc))();
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = (**(code **)(*unaff_EBX + 0xc))();
  if (iVar2 == 0) {
    bVar1 = true;
    if (*(int *)(param_2 + 4) == 0) {
      iVar2 = (**(code **)(*param_1 + 0xc))(param_1);
    }
    else {
      if (*(int *)(param_2 + 4) != 1) {
        iVar2 = 0xd0;
        goto LAB_68006115;
      }
      iVar2 = (**(code **)(*param_1 + 0xc))(param_1);
    }
    if (iVar2 == 0) {
      return 0;
    }
  }
LAB_68006115:
  (**(code **)(*unaff_EDI + 0x10))();
  if (bVar1) {
    (**(code **)(*unaff_EBX + 0x10))();
  }
  return iVar2;
}



// ============================================================
// Function: crt_dispatchCodecOp (FUN_68006140)
// Address: 68006140
// Size: 58 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall crt_dispatchCodecOp(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int in_EAX;
  undefined4 uVar1;
  
  if (in_EAX == 0) {
    uVar1 = (**(code **)(*param_3 + 0x10))(param_3,param_2,param_1);
    return uVar1;
  }
  if (in_EAX != 1) {
    return 0xd0;
  }
  uVar1 = (**(code **)(*param_3 + 0x10))(param_3,param_2,param_1);
  return uVar1;
}



// ============================================================
// Function: crt_finalizeCodecOp (FUN_68006180)
// Address: 68006180
// Size: 107 bytes
// Params: void * this, int * param_1, int param_2
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall crt_finalizeCodecOp(void *this,int *param_1,int param_2)

{
  int in_EAX;
  void *pvVar1;
  int *unaff_EBX;
  int *unaff_EDI;
  
  if ((in_EAX == 0) || (in_EAX == 1)) {
    if (this == (void *)0x8004044c) {
      this = (void *)(**(code **)(*param_1 + 0x14))(param_1);
    }
    else {
      (**(code **)(*param_1 + 0x18))(param_1);
    }
    if ((this == (void *)0x0) && (param_2 != 0)) {
      this = (void *)(**(code **)(*unaff_EDI + 0x20))();
    }
  }
  else {
    this = (void *)0xd0;
  }
  pvVar1 = (void *)(**(code **)(*unaff_EBX + 0x10))();
  if (this == (void *)0x0) {
    this = pvVar1;
  }
  pvVar1 = (void *)(**(code **)(*unaff_EDI + 0x10))();
  if (this != (void *)0x0) {
    pvVar1 = this;
  }
  return (int)pvVar1;
}



// ============================================================
// Function: crt_codecNoOp (FUN_680061f0)
// Address: 680061f0
// Size: 3 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_codecNoOp(void)

{
  return 0;
}



// ============================================================
// Function: crt_freeMediaCodecHandles (FUN_68006200)
// Address: 68006200
// Size: 104 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_freeMediaCodecHandles(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x88) != 0) {
    iVar2 = Ordinal_1114(*(int *)(param_1 + 0x88));
    iVar3 = 0;
    if (0 < *(int *)(param_1 + 0x8c)) {
      do {
        iVar1 = *(int *)(iVar2 + iVar3 * 4);
        if (iVar1 != 0) {
          cast_freeHandle(iVar1);
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < *(int *)(param_1 + 0x8c));
    }
    Ordinal_1115(*(undefined4 *)(param_1 + 0x88));
    cast_freeHandle(*(undefined4 *)(param_1 + 0x88));
    *(undefined4 *)(param_1 + 0x8c) = 0;
    *(undefined4 *)(param_1 + 0x88) = 0;
  }
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68006270 - 0x68006770
// Functions (9):
//   crt_decodeCodecFrame
//   crt_getCodecEntryOffset
//   crt_decodeMediaChunk
//   crt_decodeMediaBlock
//   crt_getMediaSlotHandle
//   crt_freeMediaSlotHandle
//   crt_initCodecDecoder
//   crt_closeCodecDecoder
//   crt_decodeStreamFrames

// ============================================================
// Function: crt_decodeCodecFrame (FUN_68006270)
// Address: 68006270
// Size: 333 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, short param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall crt_decodeCodecFrame(undefined4 param_1,int param_2,undefined4 param_3,short param_4)
{
  void *this;
  int iVar1;
  undefined4 *puVar2;
  int **ppiVar3;
  undefined1 local_38 [4];
  uint local_34;
  int *local_30;
  int *local_2c;
  int *local_28;
  int local_24;
  uint local_8;
  
  local_30 = (int *)0x0;
  local_2c = (int *)0x0;
  if ((-1 < param_4) && (param_4 < *(short *)(param_2 + 0x94))) {
    puVar2 = (undefined4 *)(**(int **)(param_2 + 0x98) + param_4 * 0x20);
    ppiVar3 = &local_28;
    for (iVar1 = 8; iVar1 != 0; iVar1 = iVar1 + -1) {
      *ppiVar3 = (int *)*puVar2;
      puVar2 = puVar2 + 1;
      ppiVar3 = ppiVar3 + 1;
    }
    iVar1 = crt_createReadStream(param_2,param_3,(int *)&local_30);
    if (iVar1 == 0) {
      if (local_24 == 2) {
        Ordinal_1116(param_1);
        Ordinal_1114(param_1);
        iVar1 = crt_codecNoOp();
        Ordinal_1115(param_1);
      }
      else {
        local_34 = Ordinal_1116(param_1);
        iVar1 = Ordinal_1446(param_1,0xffffffff,2,&local_2c);
        if (iVar1 == 0) {
          iVar1 = -0x7ffbffec;
        }
        else {
          iVar1 = crt_initCodecStreams(local_28,(int)&local_28);
          if (iVar1 == 0) {
            do {
              this = (void *)crt_dispatchCodecOp(local_2c,local_30,local_28);
              if (0x7800 < local_34) {
                Ordinal_1013();
              }
            } while (this == (void *)0x0);
            iVar1 = crt_finalizeCodecOp(this,local_28,(int)local_38);
          }
        }
      }
    }
    if (local_30 != (int *)0x0) {
      (**(code **)(*local_30 + 8))(local_30);
    }
    if (local_2c != (int *)0x0) {
      (**(code **)(*local_2c + 8))(local_2c);
    }
    crt_releaseCodec(iVar1);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: crt_getCodecEntryOffset (FUN_680063c0)
// Address: 680063c0
// Size: 28 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_getCodecEntryOffset(int param_1,int param_2)

{
  return *(undefined4 *)(**(int **)(param_1 + 0xa0) + 8 + param_2 * 0xc);
}



// ============================================================
// Function: crt_decodeMediaChunk (FUN_680063e0)
// Address: 680063e0
// Size: 80 bytes
// Params: undefined4 param_1, byte * param_2, undefined4 * param_3
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall crt_decodeMediaChunk(undefined4 param_1,byte *param_2,undefined4 *param_3)

{
  byte bVar1;
  int in_EAX;
  uint uVar2;
  int *unaff_EDI;
  
  uVar2 = 0;
  do {
    if (in_EAX < 1) {
      if (unaff_EDI == (int *)0x0) {
        return uVar2;
      }
      if (in_EAX == 0) {
        in_EAX = -1;
      }
      *unaff_EDI = in_EAX;
      return uVar2;
    }
    bVar1 = *param_2;
    uVar2 = uVar2 << 7 | bVar1 & 0x7f;
    in_EAX = in_EAX + -1;
    param_2 = param_2 + 1;
  } while ((bVar1 & 0x80) != 0);
  if (unaff_EDI != (int *)0x0) {
    *unaff_EDI = in_EAX;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = param_2;
  }
  return uVar2;
}



// ============================================================
// Function: crt_decodeMediaBlock (FUN_68006430)
// Address: 68006430
// Size: 150 bytes
// Params: void * this, undefined4 * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall crt_decodeMediaBlock(void *this,undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  short sVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  
  crt_lockRifx((int)this);
  iVar2 = crt_validateSlot((int)this,in_EAX,4);
  if (iVar2 != 0) {
    crt_unlockRifx((int)this);
    return iVar2;
  }
  puVar3 = (undefined4 *)crt_getSlotEntry((int)this,in_EAX);
  *param_3 = *puVar3;
  crt_unlockRifx((int)this);
  sVar1 = *(short *)(**(int **)((int)this + 0xa0) + 4 + in_EAX * 0xc);
  if (*(short *)((int)this + 0x94) <= sVar1) {
    iVar2 = crt_allocCodecBlock(0xd0);
    return iVar2;
  }
  puVar3 = (undefined4 *)(**(int **)((int)this + 0x98) + sVar1 * 0x20);
  puVar4 = param_1;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar4 = *puVar3;
    puVar3 = puVar3 + 1;
    puVar4 = puVar4 + 1;
  }
  *param_2 = *param_1;
  return 0;
}



// ============================================================
// Function: crt_getMediaSlotHandle (FUN_680064d0)
// Address: 680064d0
// Size: 54 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_getMediaSlotHandle(int param_1,int param_2,undefined4 *param_3)
{
  if ((*(int **)(param_1 + 0x88) != (int *)0x0) && (param_2 < *(int *)(param_1 + 0x8c))) {
    *param_3 = *(undefined4 *)(**(int **)(param_1 + 0x88) + param_2 * 4);
    return 0;
  }
  *param_3 = 0;
  return 0;
}



// ============================================================
// Function: crt_freeMediaSlotHandle (FUN_68006510)
// Address: 68006510
// Size: 80 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_freeMediaSlotHandle(int param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  int *piVar3;
  
  crt_lockRifx(param_1);
  piVar3 = (int *)crt_getSlotEntry(param_1,param_2);
  iVar1 = *piVar3;
  crt_unlockRifx(param_1);
  if ((iVar1 != FOURCC_DRCF) && (iVar1 != FOURCC_VWCF)) {
    uVar2 = *(undefined4 *)(**(int **)(param_1 + 0x88) + param_2 * 4);
    *(undefined4 *)(**(int **)(param_1 + 0x88) + param_2 * 4) = 0;
    cast_freeHandle(uVar2);
  }
  return 0;
}



// ============================================================
// Function: crt_initCodecDecoder (FUN_68006560)
// Address: 68006560
// Size: 342 bytes
// Params: void * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall crt_initCodecDecoder(void *param_1,int param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_34;
  int local_30;
  int *local_2c;
  undefined4 local_28;
  int local_24;
  uint local_8;
  
  iVar1 = *(int *)((int)param_1 + 0xb0);
  local_30 = crt_searchChunkByType((int)param_1,param_3);
  uVar2 = cast_allocHandle(local_30,1);
  *(undefined4 *)(*(int *)(iVar1 + 0x350) + 0x30) = uVar2;
  if (*(int *)(*(int *)(iVar1 + 0x350) + 0x30) == 0) {
    return 0;
  }
  Ordinal_1114(*(undefined4 *)(*(int *)(iVar1 + 0x350) + 0x30));
  iVar3 = Ordinal_1446(*(undefined4 *)(param_2 + 0x10),0xffffffff,1,*(int *)(iVar1 + 0x350) + 0x34);
  if (iVar3 == 0) {
    return 0;
  }
  iVar3 = crt_createWriteStream((int *)(*(int *)(iVar1 + 0x350) + 0x38),
                       (int *)(*(int *)(iVar1 + 0x350) + 0x3c));
  if (iVar3 == 0) {
    iVar3 = crt_decodeMediaBlock(param_1,&local_28,&local_2c,&local_34);
    if (iVar3 == 0) {
      if (local_24 == 2) {
        *(undefined4 *)(*(int *)(iVar1 + 0x350) + 0x3c) = 0;
        crt_codecNoOp();
        return 0;
      }
      iVar3 = crt_initCodecStreams(local_2c,(int)&local_28);
      if (iVar3 == 0) {
        **(undefined4 **)(*(int *)(iVar1 + 0x350) + 0x3c) =
             **(undefined4 **)(*(int *)(iVar1 + 0x350) + 0x30);
        *(undefined4 *)(*(int *)(*(int *)(iVar1 + 0x350) + 0x3c) + 4) = 0;
        *(int *)(*(int *)(*(int *)(iVar1 + 0x350) + 0x3c) + 8) = local_30;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: crt_closeCodecDecoder (FUN_680066c0)
// Address: 680066c0
// Size: 175 bytes
// Params: void * this, undefined4 param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall crt_closeCodecDecoder(void *this,int param_1)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int in_EAX;
  
  puVar1 = *(undefined4 **)((int)this + 0xb0);
  *(ushort *)(in_EAX + 0xc) = *(ushort *)(in_EAX + 0xc) & 0xfedf | 0x40;
  crt_insertChunk(puVar1,(int)this,param_1);
  if (*(int *)(puVar1[0xd4] + 0x34) != 0) {
    piVar2 = *(int **)(puVar1[0xd4] + 0x34);
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(puVar1[0xd4] + 0x34) = 0;
  }
  if (*(int *)(puVar1[0xd4] + 0x38) != 0) {
    piVar2 = *(int **)(puVar1[0xd4] + 0x38);
    (**(code **)(*piVar2 + 8))(piVar2);
    *(undefined4 *)(puVar1[0xd4] + 0x38) = 0;
  }
  iVar3 = *(int *)(puVar1[0xd4] + 0x30);
  if (iVar3 != 0) {
    Ordinal_1115(iVar3);
    cast_freeHandle(*(undefined4 *)(puVar1[0xd4] + 0x30));
    *(undefined4 *)(puVar1[0xd4] + 0x30) = 0;
    *(undefined4 *)(puVar1[0xd4] + 0x3c) = 0;
    return 0;
  }
  *(undefined4 *)(puVar1[0xd4] + 0x3c) = 0;
  return 0;
}



// ============================================================
// Function: crt_decodeStreamFrames (FUN_68006770)
// Address: 68006770
// Size: 448 bytes
// Params: void * param_1, int param_2, int param_3, undefined4 param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_decodeStreamFrames(void *param_1,int param_2,int param_3,undefined4 param_4,int param_5)

{
  undefined4 uVar1;
  void *this;
  int iVar2;
  uint uVar3;
  undefined4 local_2c [8];
  uint local_c;
  int *local_8;
  
  iVar2 = *(int *)((int)param_1 + 0xb0);
  if (*(int *)(*(int *)(iVar2 + 0x350) + 0x34) == 0) {
    this = (void *)crt_initCodecDecoder(param_1,param_3,param_2);
    if (this != (void *)0x0) goto LAB_680068dd;
    if (param_5 == 0) {
      return 0;
    }
  }
  if (*(int *)(*(int *)(iVar2 + 0x350) + 0x3c) != 0) {
    this = (void *)crt_decodeMediaBlock(param_1,local_2c,&local_8,&local_c);
    local_c = crt_searchChunkByType((int)param_1,param_2);
    uVar3 = *(uint *)(*(int *)(*(int *)(iVar2 + 0x350) + 0x3c) + 4);
    if (uVar3 < local_c) {
      uVar3 = local_c - uVar3;
      do {
        this = (void *)crt_dispatchCodecOp(*(undefined4 *)(*(int *)(iVar2 + 0x350) + 0x38),
                                    *(undefined4 *)(*(int *)(iVar2 + 0x350) + 0x34),local_8);
        if (uVar3 < 0x7800) {
          Ordinal_1013();
        }
        if (param_5 == 0) {
          if (this == (void *)0x0) {
            return 0;
          }
LAB_6800684a:
          if (this != (void *)0x8004044c) goto LAB_680068dd;
          break;
        }
        if (this != (void *)0x0) goto LAB_6800684a;
      } while (*(uint *)(*(int *)(*(int *)(iVar2 + 0x350) + 0x3c) + 4) < local_c);
      if (param_5 == 0) {
        return 0;
      }
    }
    this = (void *)crt_finalizeCodecOp(this,local_8,0);
    *(undefined4 *)(*(int *)(iVar2 + 0x350) + 0x3c) = 0;
    if (this != (void *)0x0) {
LAB_680068dd:
      if (*(int *)(*(int *)(iVar2 + 0x350) + 0x3c) != 0) {
        this = (void *)crt_finalizeCodecOp(this,local_8,0);
        *(undefined4 *)(*(int *)(iVar2 + 0x350) + 0x3c) = 0;
      }
      crt_closeCodecDecoder(param_1,param_2);
      iVar2 = crt_releaseCodec((int)this);
      return iVar2;
    }
  }
  Ordinal_1115(*(undefined4 *)(param_3 + 0x10));
  cast_freeHandle(*(undefined4 *)(param_3 + 0x10));
  uVar1 = *(undefined4 *)(*(int *)(iVar2 + 0x350) + 0x30);
  *(undefined4 *)(param_3 + 0x10) = uVar1;
  Ordinal_1115(uVar1);
  *(undefined4 *)(*(int *)(iVar2 + 0x350) + 0x30) = 0;
  crt_closeCodecDecoder(param_1,param_2);
  return 0;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68006930 - 0x680071d0
// Functions (6):
//   crt_parseFgdIndex
//   crt_scanFgdChunks
//   crt_seekToFgdIndex
//   crt_parseFgdVersion
//   crt_parseMxfDirectory
//   crt_checkMxfSlotReady

// ============================================================
// Function: crt_parseFgdIndex (FUN_68006930)
// Address: 68006930
// Size: 629 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_parseFgdIndex(undefined4 param_1,undefined4 *param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  undefined4 uVar7;
  uint *puVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int unaff_EBX;
  int local_14;
  int local_c;
  byte *local_8;
  
  local_8 = (byte *)Ordinal_1114(param_1);
  local_c = Ordinal_1116(param_1);
  if (((2 < local_c) && (uVar1 = crt_decodeMediaChunk(&local_8,local_8,&local_8), 1 < local_c)) &&
     (uVar2 = crt_decodeMediaChunk(extraout_ECX,local_8,&local_8), 0 < local_c)) {
    uVar3 = crt_decodeMediaChunk(&local_8,local_8,&local_8);
    iVar4 = crt_growMmapCapacity(unaff_EBX,uVar2 + 1);
    if (iVar4 != 0) goto LAB_68006b7c;
    iVar4 = *(int *)(*(int *)(unaff_EBX + 0x20) + 8);
    if (iVar4 < *(int *)(*(int *)(unaff_EBX + 0x20) + 4)) {
      do {
        puVar5 = (undefined4 *)crt_getSlotEntry(unaff_EBX,iVar4);
        *puVar5 = FOURCC_free;
        puVar5[1] = 0;
        puVar5[2] = 0;
        puVar5[3] = 0xc;
        puVar5[4] = 0xffffffff;
        iVar4 = iVar4 + 1;
      } while (iVar4 < *(int *)(*(int *)(unaff_EBX + 0x20) + 4));
    }
    *(undefined4 *)(*(int *)(unaff_EBX + 0x20) + 8) =
         *(undefined4 *)(*(int *)(unaff_EBX + 0x20) + 4);
    puVar5 = (undefined4 *)cast_allocHandle(*(int *)(*(int *)(unaff_EBX + 0x20) + 4) * 0xc,1);
    *(undefined4 **)(unaff_EBX + 0xa0) = puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      iVar4 = 0xd1;
      goto LAB_68006b7c;
    }
    Ordinal_1130(*puVar5,*(int *)(*(int *)(unaff_EBX + 0x20) + 4) * 0xc);
    local_14 = 0;
    if (0 < (int)uVar3) {
      do {
        if (((local_c < 1) || (uVar2 = crt_decodeMediaChunk(&local_8,local_8,&local_8), (int)uVar2 < 0)) ||
           (*(int *)(*(int *)(unaff_EBX + 0x20) + 8) <= (int)uVar2)) goto LAB_68006b77;
        puVar5 = (undefined4 *)crt_getSlotEntry(unaff_EBX,uVar2);
        uVar6 = crt_decodeMediaChunk(extraout_ECX_00,local_8,&local_8);
        puVar5[2] = uVar6;
        iVar4 = **(int **)(unaff_EBX + 0xa0) + uVar2 * 0xc;
        uVar2 = crt_decodeMediaChunk(iVar4,local_8,&local_8);
        *(uint *)(iVar4 + 8) = uVar2;
        uVar2 = crt_decodeMediaChunk(iVar4,local_8,&local_8);
        puVar5[1] = uVar2;
        uVar2 = crt_decodeMediaChunk(extraout_ECX_01,local_8,&local_8);
        *(short *)(iVar4 + 4) = (short)uVar2;
        uVar7 = *(undefined4 *)local_8;
        *puVar5 = uVar7;
        if (*(int *)(unaff_EBX + 0x14) != 0) {
          uVar7 = cast_freeIfNonNull(uVar7);
          *puVar5 = uVar7;
        }
        local_8 = local_8 + 4;
        puVar5[3] = 0;
        puVar5[4] = 0;
        local_14 = local_14 + 1;
        local_c = local_c + -4;
      } while (local_14 < (int)uVar3);
    }
    if (local_c == 0) {
      Ordinal_1115(param_1);
      puVar5 = (undefined4 *)cast_allocHandle(0x18,1);
      if (puVar5 == (undefined4 *)0x0) {
        return 0xd1;
      }
      puVar8 = (uint *)Ordinal_1114(puVar5);
      *puVar8 = uVar1;
      puVar8[1] = 0xffffffff;
      Ordinal_1115(puVar5);
      iVar4 = crt_loadImapHeader(unaff_EBX,puVar5);
      if (iVar4 != 0) {
        cast_freeHandle(puVar5);
        return iVar4;
      }
      *param_2 = puVar5;
      return 0;
    }
  }
LAB_68006b77:
  iVar4 = 0xd0;
LAB_68006b7c:
  if (local_8 == (byte *)0x0) {
    return iVar4;
  }
  Ordinal_1115(param_1);
  return iVar4;
}



// ============================================================
// Function: crt_scanFgdChunks (FUN_68006bb0)
// Address: 68006bb0
// Size: 241 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_scanFgdChunks(int param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 uVar4;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int *unaff_EBX;
  int unaff_ESI;
  int local_2c;
  int local_28;
  byte local_24 [28];
  uint local_8;
  
  iVar1 = crt_readStreamData(*(int *)(unaff_ESI + 4),&local_28,0x20);
  uVar4 = extraout_ECX;
  if (iVar1 != 0) {
LAB_68006c90:
    return 0;
  }
  do {
    iVar1 = local_28;
    if (*(int *)(unaff_ESI + 0x14) != 0) {
      iVar1 = cast_freeIfNonNull(local_28);
      uVar4 = extraout_ECX_00;
    }
    *unaff_EBX = iVar1;
    uVar2 = crt_decodeMediaChunk(uVar4,local_24,(undefined4 *)0x0);
    unaff_EBX[1] = uVar2;
    if (local_2c < 1) {
LAB_68006c78:
      return 0;
    }
    crt_streamSeek(*(int *)(unaff_ESI + 4),0x20 - local_2c);
    if ((param_1 == 0) || (*unaff_EBX == param_1)) goto LAB_68006c90;
    if (*unaff_EBX == FOURCC_FGEI) goto LAB_68006c78;
    iVar1 = unaff_EBX[1];
    iVar3 = crt_streamGetPos(*(int *)(unaff_ESI + 4));
    if (param_2 <= iVar3 + iVar1) goto LAB_68006c78;
    iVar1 = crt_streamSeek(*(int *)(unaff_ESI + 4),iVar1);
    if (iVar1 != 0) goto LAB_68006c90;
    iVar1 = crt_readStreamData(*(int *)(unaff_ESI + 4),&local_28,0x20);
    uVar4 = extraout_ECX_01;
    if (iVar1 != 0) {
      return 0;
    }
  } while( true );
}



// ============================================================
// Function: crt_seekToFgdIndex (FUN_68006cb0)
// Address: 68006cb0
// Size: 51 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall crt_seekToFgdIndex(int param_1)
{
  int in_EAX;
  int iVar1;
  undefined4 local_8;
  
  iVar1 = crt_scanFgdChunks(FOURCC_FGEI,in_EAX);
  if ((iVar1 == 0) && (local_8 != 0)) {
    crt_streamSeek(*(int *)(param_1 + 4),local_8);
  }
  return 0;
}



// ============================================================
// Function: crt_parseFgdVersion (FUN_68006cf0)
// Address: 68006cf0
// Size: 448 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall crt_parseFgdVersion(int param_1,int param_2,int param_3)
{
  int iVar1;
  uint uVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int local_3c;
  byte *local_38;
  uint local_34;
  byte *local_30;
  byte *local_2c;
  byte local_28 [32];
  uint local_8;
  
  if ((param_3 != FOURCC_FGDM) && (param_3 != FOURCC_FGDC)) {
    return 0;
  }
  iVar1 = crt_streamReadAt(*(int *)(param_2 + 4),&local_34);
  if (iVar1 != 0x1f6) {
    if (iVar1 != 0) goto LAB_68006e9e;
    if (local_34 < param_1 + 8U) {
      return 0;
    }
  }
  local_34 = param_1 + 8;
  iVar1 = crt_scanFgdChunks(0,local_34);
  if (iVar1 != 0) {
LAB_68006e9e:
    return 0;
  }
  if (local_3c == FOURCC_Fver) {
    local_2c = local_38;
    if ((byte *)0x20 < local_38) {
      local_2c = (byte *)0x20;
    }
    iVar1 = crt_readStreamData(*(int *)(param_2 + 4),local_28,local_2c);
    if (iVar1 != 0) goto LAB_68006e9e;
    uVar2 = crt_decodeMediaChunk(extraout_ECX,local_28,&local_30);
    if (-1 < (int)local_2c) {
      if ((int)uVar2 < 0x300) {
        return 0;
      }
      if ((0x501 < (int)uVar2) && ((uVar2 & 0xffffff00) != 0x500)) {
        return 0;
      }
      if (0x400 < (int)uVar2) {
        if ((local_30 == (byte *)0x0) ||
           (crt_decodeMediaChunk(&local_30,local_30,&local_30), local_30 == (byte *)0x0)) goto LAB_68006e78;
        crt_decodeMediaChunk(extraout_ECX_00,local_30,&local_30);
      }
      if (((int)uVar2 < 0x501) ||
         (((local_30 != (byte *)0x0 && (0 < (int)local_2c)) &&
          (local_30 + ((uint)*local_30 - (int)local_28) + 1 <= local_38)))) {
        crt_streamSeek(*(int *)(param_2 + 4),local_38);
        goto LAB_68006e9e;
      }
    }
  }
LAB_68006e78:
  return 0;
}



// ============================================================
// Function: crt_parseMxfDirectory (FUN_68006eb0)
// Address: 68006eb0
// Size: 797 bytes
// Params: int param_1, int param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_parseMxfDirectory(int param_1,int param_2,int param_3,int *param_4)
{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  int iVar7;
  undefined4 *puVar8;
  byte *local_44;
  uint local_40 [2];
  int local_38;
  int local_34;
  int *local_30;
  int local_2c;
  byte local_28 [32];
  uint local_8;
  
  local_30 = param_4;
  *param_4 = 0;
  if (*(int *)(param_1 + 0x18) == 0) goto LAB_68006f1e;
  if (*(int *)(param_1 + 0xa8) == 1) {
LAB_68006f3f:
    iVar7 = param_3 + 8;
    local_34 = iVar7;
    if (*(int *)(param_1 + 0x18) != 0) {
      iVar2 = crt_seekToFgdIndex(param_1);
      if (iVar2 != 0) goto LAB_68007191;
      crt_streamRead(*(int *)(param_1 + 4),0xc);
    }
    iVar2 = crt_scanFgdChunks(FOURCC_Fcdr,iVar7);
    iVar7 = local_38;
    if (iVar2 == 0) {
      puVar3 = (undefined4 *)cast_allocHandle(local_38,1);
      if (puVar3 == (undefined4 *)0x0) {
        iVar2 = 0xd1;
      }
      else {
        puVar8 = puVar3;
        uVar4 = Ordinal_1114(puVar3,iVar7);
        iVar2 = crt_writeStreamData(*(int *)(param_1 + 4),uVar4,puVar8);
        Ordinal_1115(puVar3);
        if (iVar2 == 0) {
          iVar2 = crt_buildFormatTable(param_1,puVar3,*(short **)(param_1 + 0x14),
                               (undefined2 *)(param_1 + 0x94),(undefined4 *)(param_1 + 0x98),
                               (undefined4 *)(param_1 + 0x9c));
          iVar2 = crt_releaseCodec(iVar2);
          if (iVar2 == 0) {
            cast_freeHandle(puVar3);
            iVar2 = crt_scanFgdChunks(FOURCC_ABMP,local_34);
            if (iVar2 == 0) {
              *(undefined4 *)(param_1 + 0x90) = 0;
              iVar2 = crt_readStreamData(*(int *)(param_1 + 4),local_28,0x20);
              if (iVar2 == 0) {
                uVar5 = crt_decodeMediaChunk(extraout_ECX,local_28,&local_44);
                uVar6 = crt_decodeMediaChunk(uVar5 & 0xffff,local_44,(undefined4 *)0x0);
                if (local_2c < 1) {
                  iVar2 = 0xd0;
                }
                else if ((int)uVar6 < 1) {
                  iVar2 = 0xd0;
                }
                else {
                  iVar2 = crt_streamSeek(*(int *)(param_1 + 4),0x20 - local_2c);
                  if (iVar2 == 0) {
                    local_38 = local_38 + -0x20 + local_2c;
                    iVar2 = cast_allocHandle(uVar6,1);
                    *local_30 = iVar2;
                    if (iVar2 == 0) {
                      iVar2 = 0xd1;
                    }
                    else {
                      *(undefined4 *)(*(int *)(param_1 + 0x20) + 8) = 1;
                      Ordinal_1115(*(undefined4 *)(param_1 + 0x1c));
                      cast_resizeHandle(*(uint *)(param_1 + 0x1c),0x2c,1);
                      uVar4 = Ordinal_1114(*(undefined4 *)(param_1 + 0x1c));
                      *(undefined4 *)(param_1 + 0x20) = uVar4;
                      puVar3 = (undefined4 *)crt_getSlotEntry(param_1,0);
                      *puVar3 = FOURCC_ABMP;
                      puVar3[1] = uVar6;
                      iVar2 = crt_streamGetPos(*(int *)(param_1 + 4));
                      puVar3[2] = iVar2;
                      puVar3[4] = 0;
                      *(undefined2 *)(puVar3 + 3) = 0;
                      puVar3 = (undefined4 *)cast_allocHandle(0xc,1);
                      *(undefined4 **)(param_1 + 0xa0) = puVar3;
                      if (puVar3 == (undefined4 *)0x0) {
                        iVar2 = 0xd1;
                      }
                      else {
                        puVar3 = (undefined4 *)*puVar3;
                        *puVar3 = 0;
                        puVar3[2] = local_38;
                        *(short *)(puVar3 + 1) = (short)uVar5;
                        iVar2 = crt_decodeCodecFrame(*local_30,param_1,0,(short)uVar5);
                        cast_freeHandle(*(undefined4 *)(param_1 + 0xa0));
                        *(undefined4 *)(param_1 + 0xa0) = 0;
                        if (iVar2 == 0) {
                          iVar2 = crt_seekToFgdIndex(param_1);
                          if (iVar2 == 0) {
                            iVar2 = crt_streamGetPos(*(int *)(param_1 + 4));
                            *(int *)(param_1 + 0x90) = iVar2;
                            goto LAB_680071b8;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            goto LAB_68007191;
          }
        }
        cast_freeHandle(puVar3);
        if (iVar2 == 0) goto LAB_680071b8;
      }
    }
  }
  else if (*(int *)(param_1 + 0x18) == 0) {
LAB_68006f1e:
    iVar2 = crt_parseFgdVersion(param_3,param_1,param_2);
    if (iVar2 == 0) {
      *(undefined4 *)(param_1 + 0xa8) = 1;
      goto LAB_68006f3f;
    }
  }
  else {
    iVar2 = crt_getStreamSize(*(int *)(param_1 + 4),local_40);
    if (iVar2 == 0) {
      if (local_40[0] < 100) {
        return 0;
      }
      goto LAB_68006f1e;
    }
  }
LAB_68007191:
  piVar1 = local_30;
  if (*local_30 != 0) {
    cast_freeHandle(*local_30);
    *piVar1 = 0;
  }
  if (iVar2 != 0x1f6) {
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
LAB_680071b8:
  return 0;
}



// ============================================================
// Function: crt_checkMxfSlotReady (FUN_680071d0)
// Address: 680071d0
// Size: 147 bytes
// Params: uint param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_checkMxfSlotReady(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 local_8;
  
  iVar4 = param_2;
  uVar1 = param_1;
  local_8 = 0;
  if (*(int *)(param_1 + 0x18) == 0) {
    return 1;
  }
  if ((*(int **)(param_1 + 0x88) != (int *)0x0) &&
     (*(int *)(**(int **)(param_1 + 0x88) + param_2 * 4) != 0)) {
    return 1;
  }
  crt_lockRifx(param_1);
  iVar2 = crt_getSlotEntry(uVar1,iVar4);
  iVar3 = crt_getStreamSize(*(int *)(uVar1 + 4),&param_1);
  if (iVar3 == 0) {
    iVar4 = crt_getCodecEntryOffset(uVar1,iVar4);
    uVar5 = 1;
    if ((uint)(iVar4 + *(int *)(uVar1 + 0x90) + *(int *)(iVar2 + 8)) <= param_1) goto LAB_68007252;
  }
  uVar5 = local_8;
LAB_68007252:
  crt_unlockRifx(uVar1);
  return uVar5;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68007270 - 0x68007920
// Functions (6):
//   crt_readMxfChunk
//   crt_decodeMxfPalette
//   crt_openMxfMedia
//   crt_prepareMxfCodec
//   crt_resetMxfCodec
//   crt_readMxfStream

// ============================================================
// Function: crt_readMxfChunk (FUN_68007270)
// Address: 68007270
// Size: 233 bytes
// Params: uint param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crt_readMxfChunk(uint param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  
  if ((*(int **)(param_1 + 0x88) != (int *)0x0) &&
     (iVar3 = *(int *)(**(int **)(param_1 + 0x88) + param_2 * 4), iVar3 != 0)) {
    uVar2 = Ordinal_1114(iVar3,param_4);
    uVar2 = Ordinal_1114(param_3,uVar2);
    Ordinal_1129(uVar2);
    Ordinal_1115(param_3);
    Ordinal_1115(iVar3);
    crt_freeMediaSlotHandle(param_1,param_2);
    return 0;
  }
  crt_lockRifx(param_1);
  iVar3 = crt_getSlotEntry(param_1,param_2);
  iVar3 = *(int *)(iVar3 + 8);
  sVar1 = *(short *)(**(int **)(param_1 + 0xa0) + 4 + param_2 * 0xc);
  crt_unlockRifx(param_1);
  if (*(int *)(param_1 + 0x18) != 0) {
    iVar4 = crt_checkMxfSlotReady(param_1,param_2);
    if (iVar4 == 0) {
      return 0x1f6;
    }
  }
  if (iVar3 == -1) {
    return 0xd0;
  }
  uVar2 = crt_decodeCodecFrame(param_3,param_1,param_2,sVar1);
  return uVar2;
}



// ============================================================
// Function: crt_decodeMxfPalette (FUN_68007360)
// Address: 68007360
// Size: 311 bytes
// Params: int param_1, undefined4 param_2, byte * param_3
// Return: byte
// Calling convention: __stdcall
// ============================================================

byte crt_decodeMxfPalette(int param_1,undefined4 param_2,byte *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  byte bVar6;
  byte *pbVar7;
  
  pbVar7 = param_3;
  crt_freeMediaCodecHandles(param_1);
  crt_lockRifx(param_1);
  iVar1 = *(int *)(*(int *)(param_1 + 0x20) + 4);
  *(int *)(param_1 + 0x8c) = iVar1;
  iVar1 = cast_allocHandle(iVar1 * 4,1);
  *(int *)(param_1 + 0x88) = iVar1;
  if (iVar1 == 0) {
    *(undefined4 *)(param_1 + 0x8c) = 0;
    bVar6 = 0xd1;
  }
  else {
    iVar1 = Ordinal_1114(iVar1);
    param_3 = (byte *)Ordinal_1114(param_2);
    uVar5 = extraout_ECX;
    while ((0 < (int)pbVar7 &&
           (uVar2 = crt_decodeMediaChunk(uVar5,param_3,&param_3), (int)uVar2 < *(int *)(param_1 + 0x8c)))) {
      iVar3 = crt_getSlotEntry(param_1,uVar2);
      if (pbVar7 < *(byte **)(iVar3 + 4)) break;
      iVar4 = cast_allocHandle(*(byte **)(iVar3 + 4),1);
      *(int *)(iVar1 + uVar2 * 4) = iVar4;
      if (iVar4 == 0) {
        bVar6 = 0xd1;
        goto LAB_6800745b;
      }
      uVar5 = Ordinal_1114(iVar4,param_3,*(undefined4 *)(iVar3 + 4));
      Ordinal_1129(uVar5);
      Ordinal_1115(iVar4);
      param_3 = param_3 + *(int *)(iVar3 + 4);
      pbVar7 = pbVar7 + -*(int *)(iVar3 + 4);
      uVar5 = extraout_ECX_00;
    }
    bVar6 = -(pbVar7 != (byte *)0x0) & 0xd0;
LAB_6800745b:
    if (param_3 != (byte *)0x0) {
      Ordinal_1115(param_2);
    }
    if (iVar1 != 0) {
      Ordinal_1115(*(undefined4 *)(param_1 + 0x88));
    }
    if (bVar6 == 0) goto LAB_68007487;
  }
  crt_freeMediaCodecHandles(param_1);
LAB_68007487:
  crt_unlockRifx(param_1);
  return bVar6;
}



// ============================================================
// Function: crt_openMxfMedia (FUN_680074a0)
// Address: 680074a0
// Size: 496 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_openMxfMedia(int *param_1,int param_2,int *param_3)

{
  byte *pbVar1;
  int iVar2;
  int *piVar3;
  byte bVar4;
  int iVar5;
  undefined3 extraout_var;
  undefined4 *puVar6;
  int local_10;
  int local_c;
  int local_8;
  
  piVar3 = param_1;
  local_c = 0;
  local_8 = 0;
  local_10 = 0;
  if (param_1[0x2a] != 2) {
    iVar5 = crt_parseMxfDirectory((int)param_1,param_2,(int)param_3,&local_c);
    if ((iVar5 == 0) && (iVar5 = crt_parseFgdIndex(local_c,&local_8), iVar5 == 0)) {
      cast_freeHandle(local_c);
      piVar3[0x2b] = local_8;
      piVar3[0x2a] = 2;
      goto LAB_6800751d;
    }
    goto LAB_68007637;
  }
  local_8 = param_1[0x2b];
LAB_6800751d:
  local_c = 0;
  crt_lockRifx((int)piVar3);
  iVar5 = crt_getSlotEntry((int)piVar3,2);
  pbVar1 = *(byte **)(iVar5 + 4);
  crt_unlockRifx((int)piVar3);
  if (pbVar1 == (byte *)0x0) {
    iVar5 = 0xd0;
    goto LAB_68007659;
  }
  if (piVar3[6] != 0) {
    iVar5 = crt_checkMxfSlotReady((uint)piVar3,2);
    if (iVar5 == 0) {
      return 0x1f6;
    }
    iVar5 = crt_getStreamSize(piVar3[1],&param_1);
    if ((iVar5 != 0) || (iVar5 = crt_computeChunkTotal(piVar3,(uint *)&param_3), iVar5 != 0))
    goto LAB_68007637;
    if (param_1 < param_3) {
      return 0x1f6;
    }
  }
  local_10 = cast_allocHandle(pbVar1,1);
  if (local_10 == 0) {
    iVar5 = 0xd1;
    goto LAB_68007659;
  }
  iVar5 = crt_readMxfChunk((uint)piVar3,2,local_10,pbVar1);
  if (iVar5 == 0) {
    bVar4 = crt_decodeMxfPalette((int)piVar3,local_10,pbVar1);
    iVar5 = CONCAT31(extraout_var,bVar4);
    if (iVar5 != 0) goto LAB_68007637;
    puVar6 = (undefined4 *)crt_getSlotEntry((int)piVar3,2);
    *puVar6 = FOURCC_mmap;
    puVar6[1] = 0;
    puVar6[2] = 0xffffffff;
    puVar6[3] = 0;
    puVar6[4] = piVar3[7];
    puVar6 = (undefined4 *)crt_getSlotEntry((int)piVar3,1);
    puVar6[3] = 0;
    *puVar6 = FOURCC_imap;
    puVar6[1] = 0;
    puVar6[2] = 0xffffffff;
    puVar6[4] = local_8;
    iVar2 = *(int *)piVar3[0x28];
    *(undefined4 *)(iVar2 + 0x14) = 0;
    *(undefined2 *)(iVar2 + 0x10) = 0;
    local_8 = 0;
    if (piVar3[0xb] < 1) {
      iVar5 = 0xcf;
    }
  }
  else {
LAB_68007637:
    if (iVar5 == 0x1f6) {
      return 0x1f6;
    }
  }
  if (local_10 != 0) {
    cast_freeHandle(local_10);
  }
  if (local_c != 0) {
    cast_freeHandle(local_c);
  }
LAB_68007659:
  if (local_8 != 0) {
    cast_freeHandle(local_8);
  }
  if (iVar5 != 0) {
    return iVar5;
  }
  piVar3[0x2b] = 0;
  piVar3[0x2a] = 5;
  return 0;
}



// ============================================================
// Function: crt_prepareMxfCodec (FUN_68007690)
// Address: 68007690
// Size: 500 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_prepareMxfCodec(int *param_1)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *local_30;
  int local_2c;
  undefined4 local_28;
  int local_24;
  uint local_8;
  
  crt_lockRifx((int)param_1);
  iVar2 = crt_validateSlot((int)param_1,param_1[0x15],4);
  iVar3 = crt_getSlotEntry((int)param_1,param_1[0x15]);
  crt_unlockRifx((int)param_1);
  if (iVar2 != 0) {
    return 0;
  }
  iVar2 = param_1[0x15];
  crt_getMediaSlotHandle((int)param_1,iVar2,&local_2c);
  if (local_2c == 0) {
    if (*(int *)(iVar3 + 0x10) != 0) {
      if ((*(byte *)(iVar3 + 0xc) & 0x20) != 0) {
        crt_findChunkByTag(param_1,iVar2,iVar3,1);
      }
      local_2c = *(int *)(iVar3 + 0x10);
      if (local_2c != 0) goto LAB_68007716;
    }
    iVar2 = crt_createReadStream(param_1,param_1[0x15],param_1 + 0x17);
    if (((iVar2 == 0) && (iVar2 = crt_createWriteStream(param_1 + 0x18,param_1 + 0x19), iVar2 == 0)) &&
       (iVar2 = crt_decodeMediaBlock(param_1,&local_28,&local_30,&local_2c), iVar2 == 0)) {
      if (local_24 == 2) {
        iVar3 = crt_searchChunkByType((int)param_1,param_1[0x15]);
        iVar2 = cast_allocHandle(iVar3,1);
        param_1[0x1a] = iVar2;
        if (iVar2 == 0) {
          iVar2 = -0x7ffbfffe;
        }
        else {
          Ordinal_1114(iVar2);
          iVar2 = crt_codecNoOp();
          Ordinal_1115(param_1[0x1a]);
          if (iVar2 == 0) {
            param_1[0x1b] = iVar3;
            goto LAB_6800786f;
          }
        }
      }
      else {
        iVar2 = crt_initCodecStreams(local_30,(int)&local_28);
        if (iVar2 == 0) {
          param_1[0x21] = 1;
LAB_6800786f:
          return 0;
        }
      }
    }
  }
  else {
LAB_68007716:
    iVar2 = Ordinal_1446(local_2c,0xffffffff,1,param_1 + 0x17);
    if (iVar2 == 0) {
      iVar2 = -0x7ffbffec;
    }
    else {
      piVar1 = (int *)param_1[0x17];
      iVar2 = (**(code **)(*piVar1 + 0xc))(piVar1,0,0);
      if (iVar2 == 0) goto LAB_6800786f;
    }
  }
  piVar1 = (int *)param_1[0x17];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0x17] = 0;
  }
  piVar1 = (int *)param_1[0x18];
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    param_1[0x18] = 0;
  }
  param_1[0x19] = 0;
  if (param_1[0x1a] != 0) {
    cast_freeHandle(param_1[0x1a]);
    param_1[0x1a] = 0;
  }
  param_1[0x1b] = 0;
  param_1[0x1c] = 0;
  param_1[0x21] = 0;
  param_1[0x15] = -1;
  crt_releaseCodec(iVar2);
  return 0;
}



// ============================================================
// Function: crt_resetMxfCodec (FUN_68007890)
// Address: 68007890
// Size: 129 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_resetMxfCodec(int *param_1)
{
  int *piVar1;
  int iVar2;
  undefined4 local_2c [8];
  undefined1 local_c [4];
  undefined4 local_8;
  
  piVar1 = param_1;
  iVar2 = 0;
  if (param_1[0x18] == 0) {
    if (param_1[0x15] != -1) {
      crt_freeMediaSlotHandle((int)param_1,param_1[0x15]);
    }
  }
  else if (param_1[0x21] != 0) {
    param_1[0x21] = 0;
    iVar2 = crt_decodeMediaBlock(param_1,local_2c,&param_1,&local_8);
    if (iVar2 == 0) {
      iVar2 = crt_finalizeCodecOp((void *)0x0,param_1,(int)local_c);
    }
  }
  crt_cleanupResources((int)piVar1);
  if (iVar2 != 0) {
    crt_releaseCodec(iVar2);
  }
  return 0;
}



// ============================================================
// Function: crt_readMxfStream (FUN_68007920)
// Address: 68007920
// Size: 378 bytes
// Params: void * param_1, int param_2, int * param_3, int * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_readMxfStream(void *param_1,int param_2,int *param_3,int *param_4)

{
  void *this;
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  undefined4 local_24;
  int local_20;
  
  this = param_1;
  if (param_4 != (int *)0x0) {
    *param_4 = 0;
  }
  iVar2 = *(int *)((int)param_1 + 0x70);
  if (iVar2 == 0) {
    if (*(int *)((int)param_1 + 0x60) != 0) {
      piVar3 = param_3;
      if (*(int *)((int)param_1 + 0x6c) != 0) {
        iVar2 = Ordinal_1116(*(undefined4 *)((int)param_1 + 0x68));
        piVar1 = param_3;
        piVar3 = *(int **)((int)this + 0x6c);
        piVar4 = piVar3;
        if ((int)param_3 < (int)piVar3) {
          piVar4 = param_3;
        }
        Ordinal_1129(param_2,(**(int **)((int)this + 0x68) - (int)piVar3) + iVar2,piVar4);
        param_2 = param_2 + (int)piVar4;
        piVar3 = (int *)((int)piVar1 - (int)piVar4);
        if (param_4 != (int *)0x0) {
          *param_4 = *param_4 + (int)piVar4;
        }
      }
      if ((int)piVar3 < 1) {
        return 0;
      }
      iVar2 = crt_decodeMediaBlock(this,&local_24,&param_3,&param_1);
      if (iVar2 != 0) {
        *(int *)((int)this + 0x70) = iVar2;
        iVar2 = crt_releaseCodec(iVar2);
        return iVar2;
      }
      if (local_20 != 2) {
        **(int **)((int)this + 100) = param_2;
        *(undefined4 *)(*(int *)((int)this + 100) + 4) = 0;
        *(int **)(*(int *)((int)this + 100) + 8) = piVar3;
        do {
          iVar2 = crt_dispatchCodecOp(*(undefined4 *)((int)this + 0x60),*(undefined4 *)((int)this + 0x5c),
                               param_3);
          if (0x7800 < (int)piVar3) {
            Ordinal_1013();
          }
        } while ((iVar2 == 0) && (*(int *)(*(int *)((int)this + 100) + 4) < (int)piVar3));
        if (param_4 != (int *)0x0) {
          *param_4 = *param_4 + *(int *)(*(int *)((int)this + 100) + 4);
        }
        if (iVar2 == -0x7ffbfbb4) {
          iVar2 = (-(uint)(*(int *)(*(int *)((int)this + 100) + 4) != 0) & 0x7ffbffac) + 0x80040054;
        }
        iVar2 = crt_releaseCodec(iVar2);
        return iVar2;
      }
      *(undefined4 *)((int)this + 0x70) = 0x80040054;
      return 0xce;
    }
    iVar2 = (**(code **)(**(int **)((int)param_1 + 0x5c) + 0x14))
                      (*(int **)((int)param_1 + 0x5c),param_2,param_3,param_4);
    *(int *)((int)this + 0x70) = iVar2;
  }
  else if (iVar2 == -0x7ffbffac) {
    return 0xce;
  }
  iVar2 = crt_releaseCodec(iVar2);
  return iVar2;
}




// Source: decompiled_functions.c
// Module: crt
// Address range: 0x68007aa0 - 0x68008160
// Functions (8):
//   crt_seekMxfMedia
//   crt_queryFormats
//   crt_matchCodecFormat
//   crt_matchCodecDirect
//   crt_initCodecFactory
//   crt_releaseCodecFactory
//   crt_releaseCodec
//   crt_allocCodecBlock

// ============================================================
// Function: crt_seekMxfMedia (FUN_68007aa0)
// Address: 68007aa0
// Size: 511 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_seekMxfMedia(int *param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  undefined4 local_434 [8];
  undefined4 local_414;
  int *local_410;
  int *local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  piVar5 = (int *)((int)param_2 - param_1[0x16]);
  local_410 = (int *)0x0;
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  iVar2 = param_1[0x1c];
  if ((iVar2 != 0) && (iVar2 != -0x7ffbffac)) {
    crt_releaseCodec(iVar2);
    return 0;
  }
  if (param_1[0x18] == 0) {
    iVar2 = (**(code **)(*(int *)param_1[0x17] + 0x24))((int *)param_1[0x17],param_2);
    piVar3 = (int *)crt_releaseCodec(iVar2);
    param_1[0x16] = (int)param_2;
  }
  else {
    piVar3 = (int *)crt_decodeMediaBlock(param_1,local_434,&local_40c,&local_414);
    if (piVar3 == (int *)0x0) {
      piVar3 = (int *)(**(code **)*local_40c)(local_40c,&DAT_68175e38,&local_410);
      if (piVar3 == (int *)0x0) {
        local_40c = piVar3;
        iVar2 = (**(code **)(*local_410 + 0xc))
                          (local_410,param_1[0x17],param_1[0x18],param_2,&local_40c);
        if (iVar2 == 0) {
          param_1[0x16] = (int)param_2;
          piVar3 = (int *)0x0;
          piVar5 = local_40c;
        }
        else {
          piVar3 = (int *)0x0;
        }
      }
      if ((int)piVar5 < 0) {
        local_40c = (int *)param_1[0x15];
        if (param_1[0x1a] != 0) {
          iVar2 = Ordinal_1116(param_1[0x1a]);
          if (-(int)piVar5 < iVar2 - param_1[0x1b]) {
            param_1[0x1b] = param_1[0x1b] + (int)piVar5;
            param_1[0x16] = (int)param_2;
            goto LAB_68007c6f;
          }
        }
        piVar3 = (int *)crt_getStreamInfo(param_1);
        if ((piVar3 != (int *)0x0) ||
           (piVar3 = (int *)crt_setReadSlot(param_1,(int)local_40c), piVar3 != (int *)0x0))
        goto LAB_68007c6f;
        param_1[0x16] = 0;
        piVar5 = param_2;
      }
      piVar1 = (int *)param_1[0x1b];
      if (piVar1 != (int *)0x0) {
        piVar4 = piVar5;
        if ((int)piVar1 <= (int)piVar5) {
          piVar4 = piVar1;
        }
        param_1[0x16] = param_1[0x16] + (int)piVar4;
        param_1[0x1b] = (int)piVar1 - (int)piVar4;
        piVar5 = (int *)((int)piVar5 - (int)piVar4);
      }
      do {
        if (piVar5 == (int *)0x0) break;
        local_40c = piVar5;
        if (0x3ff < (int)piVar5) {
          local_40c = (int *)0x400;
        }
        piVar3 = (int *)crt_readMxfStream(param_1,(int)local_408,local_40c,(int *)&local_40c);
        param_1[0x16] = param_1[0x16] + (int)local_40c;
        piVar5 = (int *)((int)piVar5 - (int)local_40c);
      } while (piVar3 == (int *)0x0);
    }
  }
LAB_68007c6f:
  if (local_410 != (int *)0x0) {
    (**(code **)(*local_410 + 8))(local_410);
  }
  iVar2 = crt_allocCodecBlock((int)piVar3);
  param_1[0x1c] = iVar2;
  return 0;
}



// ============================================================
// Function: crt_queryFormats (FUN_68007ca0)
// Address: 68007ca0
// Size: 150 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_queryFormats(int *param_1)

{
  int *in_EAX;
  int iVar1;
  int iVar2;
  undefined4 *unaff_EBX;
  
  *param_1 = 0;
  *unaff_EBX = 0;
  iVar1 = (**(code **)(*in_EAX + 0x28))();
  if (iVar1 == 0) {
    iVar1 = cast_allocHandle(*unaff_EBX,1);
    if (iVar1 == 0) {
      return -0x7ffbfffe;
    }
    iVar2 = *in_EAX;
    Ordinal_1114(iVar1,*unaff_EBX,"Formats");
    iVar2 = (**(code **)(iVar2 + 0x14))();
    Ordinal_1115(iVar1);
    if (iVar2 != 0) {
      cast_freeHandle(iVar1);
      return iVar2;
    }
    *param_1 = iVar1;
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: crt_matchCodecFormat (FUN_68007d40)
// Address: 68007d40
// Size: 527 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_matchCodecFormat(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)
{
  int iVar1;
  short *psVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  undefined4 *puVar6;
  int local_48;
  short *local_44;
  undefined4 local_40;
  short *local_3c;
  int *local_38;
  int *local_34;
  int local_30;
  int local_2c;
  int local_28;
  undefined4 *local_24;
  uint local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  local_38 = param_1;
  local_40 = param_2;
  local_24 = param_4;
  piVar5 = (int *)0x0;
  iVar1 = Ordinal_2066(param_3,&DAT_68175e08);
  if (iVar1 == 0) {
    iVar1 = Ordinal_2066(param_3,&DAT_68175e18);
    if (iVar1 == 0) {
      iVar1 = Ordinal_2066(param_3,&DAT_68175e28);
      if (iVar1 == 0) goto LAB_68007f3c;
      local_2c = 1;
    }
    else {
      local_2c = 2;
    }
  }
  else {
    local_2c = 0;
  }
  iVar1 = crt_queryFormats((int *)&local_34);
  if (iVar1 == 0) {
    psVar2 = (short *)Ordinal_1114(param_4[1]);
    puVar6 = param_4;
    local_44 = psVar2;
    if (0xf < local_20) {
      local_1c = 0;
      do {
        piVar3 = (int *)(*local_34 + local_1c);
        iVar1 = 0;
        local_18 = *piVar3;
        local_14 = piVar3[1];
        local_10 = piVar3[2];
        local_c = piVar3[3];
        local_3c = psVar2 + 1;
        if (0 < *psVar2) {
          local_28 = 0;
          do {
            iVar4 = Ordinal_2066(&local_18,local_3c);
            if (iVar4 != 0) {
              iVar4 = (**(code **)(*local_38 + 0x14))(local_38,3,&local_30,4,"Speed");
              puVar6 = local_24;
              if (iVar4 != 0) goto LAB_68007f06;
              iVar4 = Ordinal_1114(local_24[2]);
              piVar5 = (int *)(iVar4 + local_28);
              if ((*piVar5 == 0) || (piVar5[6] < local_30)) {
                iVar4 = Ordinal_2063(*puVar6,local_40,param_3,&local_48);
                puVar6 = local_24;
                if (iVar4 != 0) goto LAB_68007f06;
                piVar3 = (int *)*piVar5;
                if (piVar3 != (int *)0x0) {
                  (**(code **)(*piVar3 + 8))(piVar3);
                }
                *piVar5 = local_48;
                piVar5[1] = local_2c;
                piVar5[2] = local_18;
                piVar5[3] = local_14;
                piVar5[4] = local_10;
                piVar5[5] = local_c;
                piVar5[6] = local_30;
                piVar5[7] = 0;
              }
            }
            local_28 = local_28 + 0x20;
            iVar1 = iVar1 + 1;
            local_3c = local_3c + 8;
            psVar2 = local_44;
          } while (iVar1 < *local_44);
        }
        local_1c = local_1c + 0x10;
        local_20 = local_20 - 0x10;
        puVar6 = local_24;
      } while (0xf < local_20);
    }
LAB_68007f06:
    if (piVar5 != (int *)0x0) {
      Ordinal_1115(puVar6[2]);
    }
    Ordinal_1115(puVar6[1]);
    cast_freeHandle(local_34);
    return 0;
  }
LAB_68007f3c:
  return 0;
}



// ============================================================
// Function: crt_matchCodecDirect (FUN_68007f50)
// Address: 68007f50
// Size: 225 bytes
// Params: int * param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_matchCodecDirect(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  undefined4 local_14;
  int local_10;
  int *local_c;
  uint local_8;
  
  local_c = (int *)0x0;
  iVar2 = Ordinal_2066(param_3,&DAT_68175e08);
  if (iVar2 == 0) {
    return 0;
  }
  iVar2 = (**(code **)(*param_1 + 0x14))(param_1,3,&local_10,4,"Speed");
  if (iVar2 == 0) {
    if ((param_4[1] == 0) || ((int)param_4[2] < local_10)) {
      iVar2 = crt_queryFormats((int *)&local_c);
      piVar1 = local_c;
      if (iVar2 != 0) {
        return iVar2;
      }
      Ordinal_1114(local_c);
      iVar2 = *piVar1;
      for (; 0xf < local_8; local_8 = local_8 - 0x10) {
        iVar3 = Ordinal_2066(iVar2,&DAT_68175df8);
        if (iVar3 != 0) {
          iVar2 = Ordinal_2063(*param_4,param_2,param_3,&local_14);
          if (iVar2 == 0) {
            param_4[1] = local_14;
            param_4[2] = local_10;
            cast_freeHandle(piVar1);
          }
          return iVar2;
        }
        iVar2 = iVar2 + 0x10;
      }
      cast_freeHandle(piVar1);
    }
    iVar2 = 0;
  }
  return iVar2;
}



// ============================================================
// Function: crt_initCodecFactory (FUN_68008040)
// Address: 68008040
// Size: 116 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_initCodecFactory(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  DAT_68195a58 = param_1;
  piVar1 = (int *)Ordinal_2068(param_1);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  local_10 = DAT_68195a58;
  local_c = 0;
  local_8 = 0;
  iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,crt_matchCodecDirect,&local_10);
  (**(code **)(*piVar1 + 8))(piVar1);
  if (iVar2 != 0) {
    return iVar2;
  }
  DAT_68195a60 = local_c;
  return 0;
}



// ============================================================
// Function: crt_releaseCodecFactory (FUN_680080c0)
// Address: 680080c0
// Size: 28 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crt_releaseCodecFactory(void)
{
  if (DAT_68195a60 != (int *)0x0) {
    (**(code **)(*(int *)(size_t)DAT_68195a60 + 8))(DAT_68195a60);
  }
  DAT_68195a60 = (int *)0x0;
  return 0;
}



// ============================================================
// Function: crt_releaseCodec (FUN_680080e0)
// Address: 680080e0
// Size: 128 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_releaseCodec(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if (param_1 == -0x7ffbffa8) {
    return 0xd2;
  }
  if (param_1 == -0x7ffbffac) {
    return 0xce;
  }
  if ((param_1 >> 0x10 != 0) && (param_1 >> 0x10 != 0xffff)) {
    uVar1 = DAT_68195a64 & 0x8000000f;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffff0) + 1;
    }
    *(int *)(&DAT_68195a18 + uVar1 * 4) = param_1;
    uVar1 = DAT_68195a64 & 0x800001ff;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffe00) + 1;
    }
    DAT_68195a64 = DAT_68195a64 + 1;
    return uVar1 + 10000;
  }
  return (int)(short)param_1;
}



// ============================================================
// Function: crt_allocCodecBlock (FUN_68008160)
// Address: 68008160
// Size: 94 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crt_allocCodecBlock(int param_1)

{
  uint uVar1;
  
  if (param_1 == 0) {
    return 0;
  }
  if (param_1 == 0xce) {
    return -0x7ffbffac;
  }
  if (param_1 - 10000U < 0x200) {
    if ((int)(param_1 - 10000U) < DAT_68195a64 + -0x10) {
      return -0x7ffbfc11;
    }
    uVar1 = param_1 - 10000U & 0x8000000f;
    if ((int)uVar1 < 0) {
      uVar1 = (uVar1 - 1 | 0xfffffff0) + 1;
    }
    param_1 = *(int *)(&DAT_68195a18 + uVar1 * 4);
  }
  return param_1;
}



