// Module: strings
// Topic: Media container I/O - key table management, stream read/write/seek
// Address range: 0x68167ad8 - 0x681689d0
// Functions (54):
//   Ordinal_1975
//   Ordinal_1980
//   Ordinal_1981
//   Ordinal_1982
//   Ordinal_1715
//   Ordinal_1635
//   Ordinal_1618
//   Ordinal_1678
//   Ordinal_1672
//   Ordinal_1705
//   Ordinal_1704
//   Ordinal_1607
//   Ordinal_1702
//   Ordinal_1153
//   Ordinal_1266
//   strings_openMediaStream
//   strings_resolveMediaFormat (FUN_68167ba0)
//   strings_dispatchMediaFormat (FUN_68167be0)
//   strings_openMediaContainer (FUN_68167c20)
//   strings_cleanupFormats (FUN_68167cf0)
//   strings_writeKeyTable (FUN_68167d60)
//   strings_readKeyTable (FUN_68167d90)
//   strings_closeMediaStream
//   strings_readMediaChunk
//   strings_readMediaBlock
//   strings_writeMediaChunk (FUN_68167e90)
//   strings_writeOrRemoveBlock (FUN_68167ee0)
//   strings_openMediaResource (FUN_68167f50)
//   strings_searchMediaByType (FUN_68167f90)
//   strings_updateMediaTimer (FUN_68167fd0)
//   strings_getMediaStreamState
//   strings_checkStreamBounds (FUN_681680e0)
//   strings_findCastFile (FUN_68168150)
//   strings_validateMediaContainer (FUN_68168190)
//   strings_loadMediaContainer (FUN_68168250)
//   strings_finalizeMediaStream (FUN_68168370)
//   strings_initMediaWriter (FUN_681683a0)
//   strings_createMediaStream
//   strings_writeMediaData
//   strings_beginWriteChunk (FUN_68168450)
//   strings_writeMediaBytes (FUN_681684e0)
//   strings_flushMediaOutput (FUN_68168580)
//   strings_endWriteChunk (FUN_681685c0)
//   strings_seekMediaOutput (FUN_68168620)
//   strings_getMediaPosition (FUN_68168670)
//   strings_searchKeyTable (FUN_681686e0)
//   strings_seekToKeyEntry (FUN_68168760)
//   strings_readMediaBytes (FUN_681687c0)
//   strings_getMediaStreamInfo (FUN_68168850)
//   strings_seekMediaInput (FUN_68168880)
//   strings_getMediaInputPosition (FUN_681688d0)
//   strings_getMediaChunkSize (FUN_68168930)
//   strings_allocMediaDescriptor (FUN_681689a0)
//   strings_freeMediaDescriptor (FUN_681689d0)

// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// REMOVED: Import thunk - resolved by linker
// ============================================================




// ============================================================
// Function: strings_openMediaStream (FUN_68167b40)
// Address: 68167b40
// Size: 82 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_openMediaStream(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_1;
  iVar4 = -1;
  piVar2 = (int *)crt_getChunkCount(param_1);
  if (piVar2 != (int *)0x0) {
    iVar4 = crt_resolveFormat(piVar2,param_3,param_2,&param_1);
    crt_lockRifx(iVar1);
    if (iVar4 != -1) {
      iVar3 = crt_validateSlot(iVar1,iVar4,4);
      if (iVar3 != 0) {
        iVar4 = -1;
      }
    }
    crt_unlockRifx(iVar1);
  }
  return iVar4;
}



// ============================================================
// Function: strings_resolveMediaFormat (FUN_68167ba0)
// Address: 68167ba0
// Size: 53 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_resolveMediaFormat(int param_1,int param_2)
{
  int in_EAX;
  int *piVar1;
  int iVar2;
  int local_8;
  
  piVar1 = (int *)crt_getChunkCount(in_EAX);
  iVar2 = crt_resolveFormat(piVar1,param_2,param_1,&local_8);
  if (iVar2 != -1) {
    crt_getFormatState(piVar1,local_8);
  }
  return 0;
}



// ============================================================
// Function: strings_dispatchMediaFormat (FUN_68167be0)
// Address: 68167be0
// Size: 58 bytes
// Params: int param_1, undefined4 param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_dispatchMediaFormat(int param_1,undefined4 param_2,int param_3,int param_4)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)crt_getChunkCount(param_1);
  iVar2 = param_4;
  iVar1 = param_3;
  crt_resolveFormat(piVar3,param_4,param_3,&param_1);
  crt_insertSortedEntry(piVar3,param_1,param_2,iVar2,iVar1);
  return 0;
}



// ============================================================
// Function: strings_openMediaContainer (FUN_68167c20)
// Address: 68167c20
// Size: 208 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int * param_3, undefined4 param_4, int param_5
// Return: void *
// Calling convention: __stdcall
// ============================================================

void * strings_openMediaContainer(undefined4 *param_1,undefined4 *param_2,int *param_3,undefined4 param_4,
                   int param_5)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  undefined4 uVar4;
  undefined4 local_8;
  
  uVar4 = 0;
  local_8 = 0;
  iVar2 = crt_openStreamForRead(param_2,&param_2);
  piVar1 = param_3;
  *param_3 = iVar2;
  if (iVar2 == 0) {
    if (param_5 != 0) {
      iVar2 = crt_streamReadAt((int)param_2,&local_8);
      *piVar1 = iVar2;
    }
    if (*piVar1 == 0) {
      pvVar3 = (void *)Ordinal_10(param_1,FOURCC_MV93,0x14);
      if (pvVar3 == (void *)0x0) {
        crt_streamClose((int)param_2);
        *piVar1 = -0x29;
        return (void *)0x0;
      }
      iVar2 = crt_createRifx(pvVar3,param_2,local_8,0);
      *piVar1 = iVar2;
      if (iVar2 != 0) {
        Ordinal_11((int)pvVar3);
        return (void *)0x0;
      }
      iVar2 = Ordinal_19((int)pvVar3,FOURCC_KEYx);
      if (iVar2 != -1) {
        uVar4 = crt_allocSortedArray(0x14);
      }
      crt_setChunkCount((int)pvVar3,uVar4);
      return pvVar3;
    }
    crt_streamClose((int)param_2);
  }
  return (void *)0x0;
}



// ============================================================
// Function: strings_cleanupFormats (FUN_68167cf0)
// Address: 68167cf0
// Size: 110 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_cleanupFormats(void)
{
  int *piVar1;
  int iVar2;
  int unaff_EBX;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  piVar1 = (int *)crt_getChunkCount(unaff_EBX);
  if (piVar1 != (int *)0x0) {
    iVar2 = crt_getFormatCount(piVar1);
    while (iVar2 = iVar2 + -1, -1 < iVar2) {
      crt_formatError(piVar1,iVar2,&local_8,&local_18,&local_14);
      crt_readChunkRange(unaff_EBX,local_8,&local_10,&local_c);
      if ((local_c == 0) && (local_10 != FOURCC_snd)) {
        crt_getFormatState(piVar1,iVar2);
        crt_mergeChunks(unaff_EBX,local_8);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: strings_writeKeyTable (FUN_68167d60)
// Address: 68167d60
// Size: 41 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_writeKeyTable(int param_1)
{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = Ordinal_17(param_1,FOURCC_KEYx);
  puVar2 = (undefined4 *)crt_getChunkCount(param_1);
  crt_writeChunkFormatted(puVar2,param_1,iVar1);
  return 0;
}



// ============================================================
// Function: strings_readKeyTable (FUN_68167d90)
// Address: 68167d90
// Size: 41 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_readKeyTable(int param_1)
{
  int iVar1;
  int *piVar2;
  
  iVar1 = Ordinal_17(param_1,FOURCC_KEYx);
  piVar2 = (int *)crt_getChunkCount(param_1);
  crt_copySortedArray(piVar2,param_1,iVar1);
  return 0;
}



// ============================================================
// Function: strings_closeMediaStream (FUN_68167dc0)
// Address: 68167dc0
// Size: 52 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_closeMediaStream(int *param_1)

{
  int iVar1;
  
  xtra_getScriptContext((int)param_1);
  iVar1 = crt_getChunkCount((int)param_1);
  if (iVar1 != 0) {
    score_freePropertyHandle(iVar1);
  }
  iVar1 = Ordinal_14(param_1);
  Ordinal_11((int)param_1);
  return iVar1;
}



// ============================================================
// Function: strings_readMediaChunk (FUN_68167e00)
// Address: 68167e00
// Size: 63 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_readMediaChunk(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = strings_openMediaStream(param_1,param_2,param_3);
  if ((iVar1 == -1) && (iVar1 = Ordinal_19(param_1,param_2), iVar1 != -1)) {
    strings_dispatchMediaFormat(param_1,iVar1,param_2,param_3);
  }
  return iVar1;
}



// ============================================================
// Function: strings_readMediaBlock (FUN_68167e40)
// Address: 68167e40
// Size: 65 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_readMediaBlock(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = strings_openMediaStream(param_1,param_2,param_3);
  if (iVar1 != -1) {
    strings_resolveMediaFormat(param_2,param_3);
    iVar1 = crt_mergeChunks(param_1,iVar1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: strings_writeMediaChunk (FUN_68167e90)
// Address: 68167e90
// Size: 75 bytes
// Params: int param_1, int param_2, int param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_writeMediaChunk(int param_1,int param_2,int param_3,undefined4 param_4,int param_5)
{
  int iVar1;
  
  iVar1 = strings_readMediaChunk(param_1,param_2,param_3);
  if (((iVar1 != -1) && (iVar1 = crt_writeChunkHeader(param_1,iVar1), iVar1 == 0)) &&
     (iVar1 = crt_writeChunkBlock(param_1,param_4,param_5), iVar1 == 0)) {
    crt_resetChunkState(param_1);
  }
  Ordinal_15(param_1);
  return 0;
}



// ============================================================
// Function: strings_writeOrRemoveBlock (FUN_68167ee0)
// Address: 68167ee0
// Size: 105 bytes
// Params: int param_1, int param_2, int param_3, undefined4 * param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_writeOrRemoveBlock(int param_1,int param_2,int param_3,undefined4 *param_4,int param_5)

{
  int iVar1;
  
  if (param_4 != (undefined4 *)0x0) {
    iVar1 = Ordinal_1116(param_4);
    if (iVar1 != 0) {
      Ordinal_1114(param_4);
      iVar1 = Ordinal_1116(param_4);
      iVar1 = strings_writeMediaChunk(param_1,param_2,param_3,*param_4,iVar1);
      Ordinal_1115(param_4);
      if (param_5 != 0) {
        cast_freeHandle(param_4);
      }
      return iVar1;
    }
  }
  iVar1 = strings_readMediaBlock(param_1,param_2,param_3);
  return iVar1;
}



// ============================================================
// Function: strings_openMediaResource (FUN_68167f50)
// Address: 68167f50
// Size: 50 bytes
// Params: int * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_openMediaResource(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = strings_openMediaStream((int)param_1,param_2,param_3);
  if (iVar1 != -1) {
    iVar1 = Ordinal_16(param_1,iVar1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: strings_searchMediaByType (FUN_68167f90)
// Address: 68167f90
// Size: 49 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_searchMediaByType(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = strings_openMediaStream(param_1,param_2,param_3);
    if (iVar1 != -1) {
      iVar1 = crt_searchChunkByType(param_1,iVar1);
      return iVar1;
    }
  }
  return 0;
}



// ============================================================
// Function: strings_updateMediaTimer (FUN_68167fd0)
// Address: 68167fd0
// Size: 166 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_updateMediaTimer(undefined4 *param_1)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  iVar2 = Ordinal_1546();
  if (*(int *)(param_1[0xd4] + 0x28) < iVar2) {
    uVar3 = Ordinal_1140(0);
    uVar1 = param_1[0xda];
    param_1[0xda] = 1;
    *(int *)(param_1[0xd4] + 0x28) = *(int *)(param_1[0xd4] + 0x24) + iVar2;
    crt_initFormatCursor(param_1);
    param_1[0xda] = uVar1;
    Ordinal_1140(uVar3);
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: strings_getMediaStreamState (FUN_68168080)
// Address: 68168080
// Size: 92 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_getMediaStreamState(void)
{
  uint uVar1;
  
  Ordinal_2330();
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: strings_checkStreamBounds (FUN_681680e0)
// Address: 681680e0
// Size: 97 bytes
// Params: uint param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool strings_checkStreamBounds(uint param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint local_8;
  
  uVar1 = param_1;
  iVar3 = 0;
  if (param_1 != 0) {
    iVar2 = crt_getChunkRef(param_1);
    if (iVar2 != 0) {
      iVar2 = xtra_getScriptContext(uVar1);
      iVar3 = crt_streamReadAt(iVar2,&local_8);
      if (iVar3 == 0) {
        iVar3 = crt_getStreamSize(iVar2,&param_1);
        if ((iVar3 == 0) && (param_1 < local_8)) {
          iVar3 = 0x1f6;
        }
      }
    }
  }
  return iVar3 != 0x1f6;
}



// ============================================================
// Function: strings_findCastFile (FUN_68168150)
// Address: 68168150
// Size: 64 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_findCastFile(void)

{
  int iVar1;
  int iVar2;
  int unaff_EBX;
  int *unaff_ESI;
  
  if (unaff_ESI == (int *)0x0) {
    return 0;
  }
  iVar1 = strings_openMediaResource(unaff_ESI,FOURCC_DRCF,unaff_EBX);
  iVar2 = Ordinal_15((int)unaff_ESI);
  if ((iVar1 == 0) || (iVar2 != 0)) {
    iVar1 = strings_openMediaResource(unaff_ESI,FOURCC_VWCF,unaff_EBX);
    Ordinal_15((int)unaff_ESI);
  }
  return iVar1;
}



// ============================================================
// Function: strings_validateMediaContainer (FUN_68168190)
// Address: 68168190
// Size: 192 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_validateMediaContainer(void)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  uint local_14;
  uint local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  if (in_EAX == 0) {
    return 0;
  }
  iVar1 = crt_getChunkRef(in_EAX);
  if (iVar1 == 0) {
    return 0;
  }
  crt_getMovieStateDirect(in_EAX,&local_c);
  if (local_c == (undefined4 *)0x0) {
    local_8 = (undefined4 *)strings_findCastFile();
    if (local_8 == (undefined4 *)0x0) goto LAB_68168235;
    crt_setMovieState(in_EAX,5,local_8);
  }
  else {
    local_8 = local_c;
  }
  if ((local_8 != (undefined4 *)0x0) &&
     ((*(short *)*local_8 < 0x54 || ((char)((short *)*local_8)[0x28] != '\0')))) {
    iVar1 = xtra_getScriptContext(in_EAX);
    iVar2 = crt_streamReadAt(iVar1,&local_14);
    if (iVar2 != 0) {
      return iVar2;
    }
    iVar1 = crt_getStreamSize(iVar1,&local_10);
    if (iVar1 != 0) {
      return iVar1;
    }
    if (local_10 < local_14) {
      return 0x1f6;
    }
  }
LAB_68168235:
  Ordinal_1113(&local_8);
  crt_setMovieState(in_EAX,6,0);
  return 0;
}



// ============================================================
// Function: strings_loadMediaContainer (FUN_68168250)
// Address: 68168250
// Size: 281 bytes
// Params: undefined4 * param_1, int * param_2, undefined4 * param_3, undefined4 param_4, undefined1 param_5, int param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_loadMediaContainer(undefined4 *param_1,int *param_2,undefined4 *param_3,undefined4 param_4,
                undefined1 param_5,int param_6)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int *local_8;
  
  piVar3 = (int *)*param_2;
  iVar4 = 0;
  local_8 = (int *)0x0;
  if (piVar3 == (int *)0x0) {
    iVar4 = crt_openStreamForRead(param_3,&local_8);
    if (iVar4 != 0) goto LAB_6816833a;
    crt_setByteOrder((int)local_8,param_5);
    piVar3 = (int *)Ordinal_10(param_1,0,0);
    if (piVar3 == (int *)0x0) {
      crt_streamClose((int)local_8);
      iVar4 = -0x6c;
      goto LAB_6816833a;
    }
LAB_6816828b:
    iVar4 = crt_openAtOffset(piVar3,local_8,param_6);
    if (iVar4 == 0) {
      iVar1 = Ordinal_17((int)piVar3,FOURCC_KEYx);
      if ((iVar1 == -1) || (puVar2 = crt_loadChunkFormat(piVar3,iVar1), puVar2 == (undefined4 *)0x0)) {
        iVar4 = 1;
        goto LAB_6816833a;
      }
      crt_setChunkCount((int)piVar3,puVar2);
      goto LAB_68168307;
    }
  }
  else {
    iVar1 = crt_getChunkRef((int)piVar3);
    if (iVar1 == 0) goto LAB_6816828b;
    iVar1 = crt_getMovieStateDirect((int)piVar3,(undefined4 *)0x0);
    if (iVar1 == 6) {
      return 0;
    }
    if (iVar1 != 5) goto LAB_6816828b;
LAB_68168307:
    iVar1 = crt_getChunkRef((int)piVar3);
    if (iVar1 != 0) {
      iVar4 = strings_validateMediaContainer();
    }
  }
  if (piVar3 != (int *)0x0) {
    local_8 = (int *)xtra_getScriptContext((int)piVar3);
  }
  if (local_8 != (int *)0x0) {
    crt_copyStreamContext(local_8,param_3);
  }
LAB_6816833a:
  *param_2 = (int)piVar3;
  if (((piVar3 != (int *)0x0) && (iVar4 != 0)) && (iVar4 != 0x1f6)) {
    Ordinal_14(piVar3);
    Ordinal_11((int)piVar3);
    *param_2 = 0;
  }
  return iVar4;
}



// ============================================================
// Function: strings_finalizeMediaStream (FUN_68168370)
// Address: 68168370
// Size: 38 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_finalizeMediaStream(int param_1)
{
  int iVar1;
  
  strings_cleanupFormats();
  iVar1 = strings_writeKeyTable(param_1);
  if (iVar1 == 0) {
    Ordinal_13(param_1,0x79f);
  }
  return 0;
}



// ============================================================
// Function: strings_initMediaWriter (FUN_681683a0)
// Address: 681683a0
// Size: 29 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_initMediaWriter(undefined4 *param_1,undefined4 param_2,undefined4 param_3)
{
  *param_1 = param_2;
  param_1[3] = param_3;
  param_1[1] = 0;
  param_1[2] = 0;
  return 0;
}



// ============================================================
// Function: strings_createMediaStream (FUN_681683c0)
// Address: 681683c0
// Size: 51 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_createMediaStream(undefined4 *param_1,undefined4 param_2,undefined4 param_3)
{
  param_1[1] = param_2;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  param_1[5] = 0;
  param_1[7] = param_3;
  param_1[8] = 0xffffffff;
  param_1[6] = 0;
  param_1[9] = 0;
  return 0;
}



// ============================================================
// Function: strings_writeMediaData (FUN_68168400)
// Address: 68168400
// Size: 72 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_writeMediaData(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4,int param_5)
{
  param_1[1] = param_2;
  param_1[3] = param_3;
  param_1[5] = param_4 + param_5;
  *param_1 = 0;
  param_1[2] = 0;
  param_1[4] = param_4;
  param_1[7] = param_4;
  param_1[8] = 0;
  param_1[6] = param_5;
  param_1[9] = 0;
  return 0;
}



// ============================================================
// Function: strings_beginWriteChunk (FUN_68168450)
// Address: 68168450
// Size: 143 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_beginWriteChunk(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  int local_c;
  int local_8;
  
  if (param_1[1] == 0) {
    if ((param_1[2] == 0) && (*param_1 != 0)) {
      uVar2 = crt_writeChunkHeader(*param_1,param_2);
      return uVar2;
    }
  }
  else {
    if (param_3 == -1) {
      param_3 = 0;
    }
    param_1[8] = -1;
    local_c = param_2;
    local_8 = param_3;
    local_c = cast_freeIfNonNull(param_2);
    local_8 = cast_freeIfNonNull(local_8);
    iVar1 = stage_emitBytecode((int *)param_1[1],(undefined1 *)&local_c,8);
    if (iVar1 == 0) {
      param_1[9] = DAT_68195a8c;
    }
    param_1[7] = *(int *)(*(int *)param_1[1] + 0x10);
  }
  return 0;
}



// ============================================================
// Function: strings_writeMediaBytes (FUN_681684e0)
// Address: 681684e0
// Size: 157 bytes
// Params: int * param_1, undefined1 * param_2, int param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint strings_writeMediaBytes(int *param_1,undefined1 *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  piVar1 = (int *)param_1[1];
  if (piVar1 != (int *)0x0) {
    if (-1 < param_1[8]) {
      Ordinal_1129(param_1[7] + *piVar1 + param_1[8],param_2,param_3);
      param_1[8] = param_1[8] + param_3;
      return param_1[9];
    }
    iVar2 = stage_emitBytecode(piVar1,param_2,param_3);
    uVar3 = ~-(uint)(iVar2 != 0) & DAT_68195a8c;
    param_1[9] = uVar3;
    return uVar3;
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    iVar2 = (**(code **)(*piVar1 + 0x1c))(piVar1,param_2,param_3,0);
    uVar3 = crt_releaseCodec(iVar2);
    param_1[9] = uVar3;
    return uVar3;
  }
  if (*param_1 != 0) {
    uVar3 = crt_writeChunkBlock(*param_1,param_2,param_3);
    return uVar3;
  }
  return 0;
}



// ============================================================
// Function: strings_flushMediaOutput (FUN_68168580)
// Address: 68168580
// Size: 60 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_flushMediaOutput(int *param_1)
{
  int *piVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x2c))(piVar1);
      iVar2 = crt_releaseCodec(iVar2);
      param_1[9] = iVar2;
      return 0;
    }
    if (*param_1 != 0) {
      crt_finalizeStreamWrite(*param_1);
    }
  }
  return 0;
}



// ============================================================
// Function: strings_endWriteChunk (FUN_681685c0)
// Address: 681685c0
// Size: 83 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_endWriteChunk(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  if ((int *)param_1[1] == (int *)0x0) {
    if ((param_1[2] == 0) && (*param_1 != 0)) {
      uVar3 = crt_resetChunkState(*param_1);
      return uVar3;
    }
  }
  else {
    stage_getBytecodeSize((int *)param_1[1]);
    if (0 < param_1[7]) {
      iVar2 = *(int *)(*(int *)param_1[1] + 0x10) - param_1[7];
      piVar1 = (int *)(param_1[7] + -4 + *(int *)param_1[1]);
      *piVar1 = iVar2;
      iVar2 = cast_freeIfNonNull(iVar2);
      *piVar1 = iVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: strings_seekMediaOutput (FUN_68168620)
// Address: 68168620
// Size: 80 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_seekMediaOutput(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,param_2);
      iVar2 = crt_releaseCodec(iVar2);
      param_1[9] = iVar2;
      return iVar2;
    }
    if (*param_1 != 0) {
      iVar2 = crt_setWriteLimit(*param_1,param_2);
      return iVar2;
    }
  }
  else {
    param_1[8] = param_2;
  }
  return 0;
}



// ============================================================
// Function: strings_getMediaPosition (FUN_68168670)
// Address: 68168670
// Size: 101 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_getMediaPosition(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = param_1;
  if ((int *)param_1[1] == (int *)0x0) {
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      param_1 = (int *)0xffffffff;
      iVar3 = (**(code **)(*piVar1 + 0x20))(piVar1,&param_1);
      iVar3 = crt_releaseCodec(iVar3);
      piVar2[9] = iVar3;
      return (int)param_1;
    }
    if (*param_1 != 0) {
      iVar3 = crt_getChunkDataSize(*param_1);
      return iVar3;
    }
    iVar3 = 0;
  }
  else {
    iVar3 = param_1[8];
    if (iVar3 < 0) {
      return *(int *)(*(int *)param_1[1] + 0x10) - param_1[7];
    }
  }
  return iVar3;
}



// ============================================================
// Function: strings_searchKeyTable (FUN_681686e0)
// Address: 681686e0
// Size: 123 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_searchKeyTable(int *param_1,int *param_2)

{
  int unaff_EBX;
  int iVar1;
  int unaff_EDI;
  int local_c;
  int local_8;
  
  iVar1 = *(int *)(unaff_EDI + 0x10);
  if (iVar1 < *(int *)(unaff_EDI + 0x14)) {
    do {
      Ordinal_1129(&local_c,**(int **)(unaff_EDI + 4) + iVar1,8);
      local_c = cast_freeIfNonNull(local_c);
      local_8 = cast_freeIfNonNull(local_8);
      if (local_c == unaff_EBX) {
        *param_1 = iVar1 + 8;
        *param_2 = local_8;
        return 0;
      }
      iVar1 = iVar1 + 8 + local_8;
    } while (iVar1 < *(int *)(unaff_EDI + 0x14));
  }
  *param_1 = -1;
  *param_2 = -1;
  return 0xffffffff;
}



// ============================================================
// Function: strings_seekToKeyEntry (FUN_68168760)
// Address: 68168760
// Size: 92 bytes
// Params: undefined4 * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_seekToKeyEntry(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = param_1;
  if (param_1[1] == 0) {
    if ((param_1[2] == 0) && ((int *)*param_1 != (int *)0x0)) {
      iVar2 = crt_setReadSlot((int *)*param_1,param_2);
      return iVar2;
    }
    iVar2 = 0;
  }
  else {
    iVar2 = strings_searchKeyTable(&param_2,(int *)&param_1);
    puVar1[9] = iVar2;
    if (iVar2 == 0) {
      puVar1[7] = param_2;
      puVar1[6] = param_1;
      puVar1[8] = 0;
      return 0;
    }
  }
  return iVar2;
}



// ============================================================
// Function: strings_readMediaBytes (FUN_681687c0)
// Address: 681687c0
// Size: 131 bytes
// Params: undefined4 * param_1, int param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_readMediaBytes(undefined4 *param_1,int param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x14))(piVar1,param_2,*param_3,param_3);
      iVar2 = crt_releaseCodec(iVar2);
      param_1[9] = iVar2;
      return iVar2;
    }
    if ((int *)*param_1 != (int *)0x0) {
      iVar2 = crt_readChunkData((int *)*param_1,param_2,param_3);
      return iVar2;
    }
  }
  else {
    if ((int)(param_1[6] - param_1[8]) < *param_3) {
      *param_3 = param_1[6] - param_1[8];
    }
    Ordinal_1129(param_2,param_1[7] + *(int *)param_1[1] + param_1[8],*param_3);
    param_1[8] = param_1[8] + *param_3;
  }
  return 0;
}



// ============================================================
// Function: strings_getMediaStreamInfo (FUN_68168850)
// Address: 68168850
// Size: 40 bytes
// Params: undefined4 * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_getMediaStreamInfo(undefined4 *param_1)

{
  int iVar1;
  
  if (((param_1[1] == 0) && (param_1[2] == 0)) && ((int *)*param_1 != (int *)0x0)) {
    iVar1 = crt_getStreamInfo((int *)*param_1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: strings_seekMediaInput (FUN_68168880)
// Address: 68168880
// Size: 80 bytes
// Params: undefined4 * param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_seekMediaInput(undefined4 *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_1[1] == 0) {
    piVar1 = (int *)param_1[2];
    if (piVar1 != (int *)0x0) {
      iVar2 = (**(code **)(*piVar1 + 0x24))(piVar1,param_2);
      iVar2 = crt_releaseCodec(iVar2);
      param_1[9] = iVar2;
      return iVar2;
    }
    if ((int *)*param_1 != (int *)0x0) {
      iVar2 = crt_setFormatContext((int *)*param_1,param_2);
      return iVar2;
    }
  }
  else {
    param_1[8] = param_2;
  }
  return 0;
}



// ============================================================
// Function: strings_getMediaInputPosition (FUN_681688d0)
// Address: 681688d0
// Size: 88 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_getMediaInputPosition(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = param_1;
  if (param_1[1] != 0) {
    return param_1[8];
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    param_1 = (int *)0xffffffff;
    iVar3 = (**(code **)(*piVar1 + 0x20))(piVar1,&param_1);
    iVar3 = crt_releaseCodec(iVar3);
    piVar2[9] = iVar3;
    return (int)param_1;
  }
  if (*param_1 != 0) {
    iVar3 = crt_getExtendedState(*param_1);
    return iVar3;
  }
  return 0;
}



// ============================================================
// Function: strings_getMediaChunkSize (FUN_68168930)
// Address: 68168930
// Size: 110 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_getMediaChunkSize(int *param_1,int param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = param_1;
  if (param_1[1] != 0) {
    strings_searchKeyTable((int *)&param_1,&param_2);
    return param_2;
  }
  piVar1 = (int *)param_1[2];
  if (piVar1 != (int *)0x0) {
    param_2 = -1;
    iVar3 = (**(code **)(*piVar1 + 0x28))(piVar1,&param_2);
    iVar3 = crt_releaseCodec(iVar3);
    piVar2[9] = iVar3;
    return param_2;
  }
  if (*param_1 != 0) {
    iVar3 = crt_searchChunkByType(*param_1,param_2);
    return iVar3;
  }
  return 0;
}



// ============================================================
// Function: strings_allocMediaDescriptor (FUN_681689a0)
// Address: 681689a0
// Size: 40 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_allocMediaDescriptor(void)

{
  int iVar1;
  
  iVar1 = Ordinal_1124(0x40);
  if (iVar1 != 0) {
    Ordinal_1130(iVar1,0x40);
    *(undefined4 *)(iVar1 + 0xc) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x1c) = 0x8000;
  }
  return iVar1;
}



// ============================================================
// Function: strings_freeMediaDescriptor (FUN_681689d0)
// Address: 681689d0
// Size: 28 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_freeMediaDescriptor(undefined4 *param_1)
{
  if (param_1 != (undefined4 *)0x0) {
    Ordinal_1125(param_1);
    *param_1 = 0;
  }
  return 0;
}



