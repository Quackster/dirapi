// Module: media_playback
// Topic: Score data encoding, decoding, delta compression, and format conversion
// Address range: 0x680B9230 - 0x680BC970
// Functions (88):
//   media_countScoreDataEntries
//   media_lookupScoreDataIndex
//   media_loadScoreXtraData
//   media_getScoreChannelData
//   media_loadScoreChannelXtra
//   media_getScoreDataBlock
//   media_parseScoreVersion
//   media_compareScoreVersion
//   media_skipScoreVersion
//   media_openScoreStream
//   media_setScoreHeaderType
//   media_getScoreFrameData
//   media_getScoreSlotData
//   media_getScoreBufferSize
//   media_initScoreFields
//   media_lockScoreBuffer
//   media_unlockScoreBuffer
//   media_getScoreBuffer
//   media_getScoreBufferEx
//   media_getScoreBufferRef
//   media_readScoreBufferFull
//   media_getScoreBufferState
//   media_readScoreBufferDirect
//   media_readScoreBufferInfo
//   media_validateScoreBuffer
//   media_getScoreVersion2
//   media_computeScoreSlotOffset
//   media_getScoreFormat
//   media_getScoreVersion
//   media_copyScoreSlot
//   media_copyScoreChannels
//   media_applyScoreDelta
//   media_getScoreSlotPtr
//   media_writeScoreChannelData
//   media_dispatchScoreChannelWrite
//   media_applyScoreSlotData
//   media_getScoreDataInfo
//   media_countScoreSlots
//   media_getScoreChannelCount
//   media_getScoreDataSize
//   media_encodeScoreDelta
//   media_getScoreLayout
//   media_getScoreLayoutSize
//   media_findScoreFrameRange
//   media_removeScoreFrames
//   media_getScoreLayoutRef
//   media_getScoreLayoutBlock
//   media_allocScoreChunk
//   media_readScoreLayoutEntry
//   media_encodeScoreLayout
//   media_freeScoreLayoutState
//   media_computeScoreDataRange
//   media_getScoreLayoutData
//   media_convertScoreOldToNew
//   media_convertScoreFromOldFormat
//   media_mapSpriteInkValue
//   media_convertScoreNewToOld
//   media_packScoreToOldFormat
//   media_convertScoreToNewFormat
//   media_getScoreDataRef
//   media_convertScoreWithRefs
//   media_writeScoreDataLayout
//   media_setScoreChannelRects
//   media_writeScoreRtfRange
//   media_renderScoreToChannel
//   media_dispatchScoreRtfWrite
//   media_saveScoreData
//   media_saveScoreDataEx
//   media_resolveScoreChannelIndices
//   media_buildScoreChannelMap
//   media_buildScoreChannelMapEx
//   media_createScoreFromChannel
//   media_writeScoreToChannel
//   media_saveScoreViaChannel
//   media_markScoreSlotChanged
//   media_unmarkScoreSlotChanged
//   media_isScoreSlotChanged
//   media_markScoreSlotModified
//   media_unmarkScoreSlotModified
//   media_isScoreSlotModified
//   media_hasModifiedScoreSlots
//   media_hasChangedScoreSlots
//   media_compareScoreFrameRange
//   media_extractScoreChannelProps
//   media_readScoreBlock
//   media_readScoreRange
//   media_processChangedScoreSlots
//   media_commitModifiedScoreSlot

// ============================================================
// Function: media_countScoreDataEntries (FUN_680b9230)
// Address: 680b9230
// Size: 67 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_countScoreDataEntries(int *param_1)

{
  undefined4 uVar1;
  char cVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar4;
  
  iVar3 = 0;
  if (param_1 != (int *)0x0) {
    iVar4 = 0;
    cVar2 = media_getScoreDataEntry(param_1,0);
    iVar3 = 0;
    uVar1 = extraout_ECX;
    while (cVar2 == '\0') {
      cVar2 = media_processXtraLoadEntry(uVar1,iVar4,param_1);
      if (cVar2 == '\0') {
        iVar3 = iVar3 + 1;
      }
      iVar4 = iVar4 + 1;
      cVar2 = media_getScoreDataEntry(param_1,iVar4);
      uVar1 = extraout_ECX_00;
    }
  }
  return iVar3;
}



// ============================================================
// Function: media_lookupScoreDataIndex (FUN_680b9280)
// Address: 680b9280
// Size: 40 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_lookupScoreDataIndex(int param_1,int param_2)

{
  int iVar1;
  
  if (((param_1 != 0) && (param_2 != 0)) && (iVar1 = media_findScoreDataIndex(param_2), -1 < iVar1)) {
    return iVar1;
  }
  return -1;
}



// ============================================================
// Function: media_loadScoreXtraData (FUN_680b92b0)
// Address: 680b92b0
// Size: 243 bytes
// Params: int * param_1, int param_2, uint param_3, int param_4, uint param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_loadScoreXtraData(int *param_1,int param_2,uint param_3,int param_4,uint param_5)
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  undefined1 local_198;
  char local_197 [399];
  uint local_8;
  
  if (((param_1 != (int *)0x0) && (-1 < param_2)) && (param_4 != 0)) {
    switch(param_3) {
    case 0:
    case 1:
    case 5:
    case 7:
      goto switchD_680b92f9_caseD_0;
    default:
      return 0;
    }
  }
  return 0;
switchD_680b92f9_caseD_0:
  iVar2 = media_processXtraLoad(param_1,param_2,param_3,0,&local_198,(int *)0x0);
  if (iVar2 == 0) {
    pcVar3 = local_197;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if ((uint)((int)pcVar3 - (int)(local_197 + 1)) < param_5) {
      pcVar3 = local_197;
      iVar2 = param_4 - (int)pcVar3;
      do {
        cVar1 = *pcVar3;
        pcVar3[iVar2] = cVar1;
        pcVar3 = pcVar3 + 1;
      } while (cVar1 != '\0');
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: media_getScoreChannelData (FUN_680b93c0)
// Address: 680b93c0
// Size: 56 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreChannelData(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 extraout_ECX;
  int extraout_EDX;
  
  if ((param_1 != (int *)0x0) && (-1 < param_2)) {
    uVar1 = media_isKnownPlatform();
    if ((char)uVar1 != '\0') {
      uVar2 = media_processXtraNotify(extraout_ECX,extraout_EDX,param_1,extraout_ECX);
      return uVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: media_loadScoreChannelXtra (FUN_680b9400)
// Address: 680b9400
// Size: 298 bytes
// Params: int * param_1, int param_2, int param_3, int param_4, int param_5, int param_6, uint param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_loadScoreChannelXtra(int *param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                 uint param_7)
{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined1 *extraout_ECX;
  int extraout_ECX_00;
  int extraout_EDX;
  undefined1 local_198;
  char local_197 [399];
  uint local_8;
  
  if ((((param_1 != (int *)0x0) && (-1 < param_2)) && (param_6 != 0)) && (0 < param_3)) {
    uVar2 = media_isKnownPlatform();
    if (((char)uVar2 != '\0') && ((param_5 == 1 || (param_5 == 2)))) {
      *extraout_ECX = 0;
      iVar3 = media_processXtraNotify(extraout_ECX,param_4,param_1,extraout_EDX);
      if ((-1 < iVar3) && (param_3 <= iVar3)) {
        iVar3 = media_getPlatformXtraFlag(param_4);
        uVar2 = iVar3 + -2 + extraout_ECX_00 * 2;
        if (param_5 == 2) {
          uVar2 = uVar2 + 1;
        }
        iVar3 = media_processXtraLoad(param_1,param_2,uVar2,param_4,&local_198,(int *)0x0);
        if (iVar3 == 0) {
          pcVar4 = local_197;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          if ((uint)((int)pcVar4 - (int)(local_197 + 1)) < param_7) {
            pcVar4 = local_197;
            iVar3 = param_6 - (int)pcVar4;
            do {
              cVar1 = *pcVar4;
              pcVar4[iVar3] = cVar1;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            return 0;
          }
        }
      }
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: media_getScoreDataBlock (FUN_680b9530)
// Address: 680b9530
// Size: 110 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreDataBlock(int *param_1)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  int *unaff_ESI;
  int iVar4;
  
  iVar4 = 0;
  cVar1 = *(char *)*unaff_ESI;
  while ((cVar1 != '\0' && (iVar2 = isdigit((int)*(char *)*unaff_ESI), iVar2 == 0))) {
    *unaff_ESI = *unaff_ESI + 1;
    cVar1 = *(char *)*unaff_ESI;
  }
  if (*(char *)*unaff_ESI == '\0') {
    return 0;
  }
  do {
    iVar2 = isdigit((int)*(char *)*unaff_ESI);
    if (iVar2 == 0) break;
    cVar1 = *(char *)*unaff_ESI;
    pcVar3 = (char *)*unaff_ESI + 1;
    *unaff_ESI = (int)pcVar3;
    iVar4 = cVar1 + -0x30 + iVar4 * 10;
  } while (*pcVar3 != '\0');
  *param_1 = iVar4;
  return 1;
}



// ============================================================
// Function: media_parseScoreVersion (FUN_680b95b0)
// Address: 680b95b0
// Size: 119 bytes
// Params: char * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_parseScoreVersion(char *param_1)
{
  int iVar1;
  int *unaff_EDI;
  
  unaff_EDI[3] = 0;
  unaff_EDI[2] = 0;
  unaff_EDI[1] = 0;
  *unaff_EDI = 0;
  iVar1 = media_getScoreDataBlock(unaff_EDI);
  if (iVar1 != 0) {
    unaff_EDI[3] = 1;
    if ((*param_1 == '.') || (*param_1 == ',')) {
      iVar1 = media_getScoreDataBlock(unaff_EDI + 1);
      if ((iVar1 != 0) && ((*param_1 == '.' || (*param_1 == ',')))) {
        media_getScoreDataBlock(unaff_EDI + 2);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: media_compareScoreVersion (FUN_680b9630)
// Address: 680b9630
// Size: 99 bytes
// Params: char * param_1, char * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_compareScoreVersion(char *param_1,char *param_2)

{
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  media_parseScoreVersion(param_1);
  media_parseScoreVersion(param_2);
  if (local_8 == 0) {
    return true;
  }
  if ((local_18 == 0) || (local_24 < local_14)) {
    return false;
  }
  if (local_24 <= local_14) {
    if (local_20 < local_10) {
      return false;
    }
    if (local_20 <= local_10) {
      return local_c <= local_1c;
    }
  }
  return true;
}



// ============================================================
// Function: media_skipScoreVersion (FUN_680b96a0)
// Address: 680b96a0
// Size: 111 bytes
// Params: char * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_skipScoreVersion(char *param_1)
{
  int iVar1;
  int local_8;
  
  iVar1 = media_getScoreDataBlock(&local_8);
  if ((iVar1 != 0) && ((*param_1 == '.' || (*param_1 == ',')))) {
    iVar1 = media_getScoreDataBlock(&local_8);
    if (iVar1 == 0) {
      *param_1 = '\0';
      return 0;
    }
    if ((*param_1 == '.') || (*param_1 == ',')) {
      media_getScoreDataBlock(&local_8);
      *param_1 = '\0';
      return 0;
    }
  }
  *param_1 = '\0';
  return 0;
}



// ============================================================
// Function: media_openScoreStream (FUN_680b9710)
// Address: 680b9710
// Size: 226 bytes
// Params: uint * param_1, int param_2, int * param_3, uint param_4, int * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_openScoreStream(uint *param_1,int param_2,int *param_3,uint param_4,int *param_5)

{
  uint *puVar1;
  int *piVar2;
  undefined4 uVar3;
  void *this;
  uint uVar4;
  
  puVar1 = param_1 + 8;
  uVar4 = 0;
  *puVar1 = 0;
  uVar3 = Ordinal_1038(&DAT_68175dd8,&DAT_68175e08,puVar1);
  Ordinal_2063(uVar3);
  if (*puVar1 == 0) {
    uVar4 = 0x8004044d;
  }
  else if (param_2 == FOURCC_RIFF) {
    uVar4 = display_openRiffStream(this,param_1);
  }
  else if (param_2 == FOURCC_INFO) {
    if (param_4 < 0x18) {
      uVar4 = 0x80040001;
    }
    else {
      uVar4 = display_readInfoBlock((int)param_1,param_3,param_5);
    }
  }
  else if (param_2 == FOURCC_FLST) {
    if (param_4 < 8) {
      uVar4 = 0x80040001;
    }
    else {
      uVar4 = display_readFileListBlock((int)param_1,param_3,param_5);
    }
  }
  else if (param_2 == FOURCC_SIGN) {
    uVar4 = display_readSignBlock((int)param_1,param_5);
  }
  else if (param_2 == FOURCC_CERT) {
    if (param_4 < 0xc) {
      uVar4 = 0x80040001;
    }
    else {
      uVar4 = display_readCertBlock((int)param_1,param_3,param_5);
    }
  }
  piVar2 = (int *)*puVar1;
  if (piVar2 != (int *)0x0) {
    (**(code **)(*piVar2 + 8))(piVar2);
  }
  *puVar1 = 0;
  return uVar4;
}



// ============================================================
// Function: media_setScoreHeaderType (FUN_680b9800)
// Address: 680b9800
// Size: 29 bytes
// Params: undefined2 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setScoreHeaderType(undefined2 param_1)
{
  int unaff_ESI;
  
  Ordinal_1130();
  *(undefined2 *)(unaff_ESI + 0x80) = param_1;
  return 0;
}



// ============================================================
// Function: media_getScoreFrameData (FUN_680b9820)
// Address: 680b9820
// Size: 82 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScoreFrameData(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  
  *(int *)(unaff_ESI + 0x44) = *(int *)(unaff_ESI + 0x44) + 1;
  if (*(int *)(unaff_ESI + 0x44) == 1) {
    uVar1 = Ordinal_1114(*(undefined4 *)(unaff_ESI + 0x50));
    *(undefined4 *)(unaff_ESI + 0x54) = uVar1;
    uVar1 = Ordinal_1114(*(undefined4 *)(unaff_ESI + 0x58));
    *(undefined4 *)(unaff_ESI + 0x5c) = uVar1;
    uVar1 = Ordinal_1114(*(undefined4 *)(unaff_ESI + 0x60));
    *(undefined4 *)(unaff_ESI + 100) = uVar1;
    uVar1 = Ordinal_1114(*(undefined4 *)(unaff_ESI + 0x88));
    *(undefined4 *)(unaff_ESI + 0x8c) = uVar1;
    uVar1 = Ordinal_1114(*(undefined4 *)(unaff_ESI + 0x90));
    *(undefined4 *)(unaff_ESI + 0x94) = uVar1;
  }
  return 0;
}




// ============================================================
// Function: media_getScoreSlotData (FUN_680b9880)
// Address: 680b9880
// Size: 92 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScoreSlotData(void)
{
  int iVar1;
  int unaff_ESI;
  
  if ((0 < *(int *)(unaff_ESI + 0x44)) &&
     (iVar1 = *(int *)(unaff_ESI + 0x44) + -1, *(int *)(unaff_ESI + 0x44) = iVar1, iVar1 == 0)) {
    Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x50));
    *(undefined4 *)(unaff_ESI + 0x54) = 0;
    Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x58));
    *(undefined4 *)(unaff_ESI + 0x5c) = 0;
    Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x60));
    *(undefined4 *)(unaff_ESI + 100) = 0;
    Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x88));
    *(undefined4 *)(unaff_ESI + 0x8c) = 0;
    Ordinal_1115(*(undefined4 *)(unaff_ESI + 0x90));
    *(undefined4 *)(unaff_ESI + 0x94) = 0;
  }
  return 0;
}



// ============================================================
// Function: media_getScoreBufferSize (FUN_680b98e0)
// Address: 680b98e0
// Size: 83 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScoreBufferSize(void)
{
  int unaff_ESI;
  
  Ordinal_1113(unaff_ESI + 0x50);
  *(undefined4 *)(unaff_ESI + 0x54) = 0;
  Ordinal_1113(unaff_ESI + 0x58);
  *(undefined4 *)(unaff_ESI + 0x5c) = 0;
  Ordinal_1113(unaff_ESI + 0x60);
  *(undefined4 *)(unaff_ESI + 100) = 0;
  Ordinal_1113(unaff_ESI + 0x88);
  *(undefined4 *)(unaff_ESI + 0x8c) = 0;
  Ordinal_1113(unaff_ESI + 0x90);
  *(undefined4 *)(unaff_ESI + 0x94) = 0;
  *(undefined4 *)(unaff_ESI + 0x40) = 0;
  *(undefined4 *)(unaff_ESI + 0x44) = 0;
  return 0;
}



// ============================================================
// Function: media_initScoreFields (FUN_680b9940)
// Address: 680b9940
// Size: 51 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_initScoreFields(void)
{
  int in_EAX;
  
  *(undefined4 *)(in_EAX + 0x50) = 0;
  *(undefined4 *)(in_EAX + 0x54) = 0;
  *(undefined4 *)(in_EAX + 0x58) = 0;
  *(undefined4 *)(in_EAX + 0x5c) = 0;
  *(undefined4 *)(in_EAX + 0x60) = 0;
  *(undefined4 *)(in_EAX + 100) = 0;
  *(undefined4 *)(in_EAX + 0x88) = 0;
  *(undefined4 *)(in_EAX + 0x8c) = 0;
  *(undefined4 *)(in_EAX + 0x90) = 0;
  *(undefined4 *)(in_EAX + 0x94) = 0;
  *(undefined4 *)(in_EAX + 0x40) = 0;
  *(undefined4 *)(in_EAX + 0x44) = 0;
  return 0;
}



// ============================================================
// Function: media_lockScoreBuffer (FUN_680b9980)
// Address: 680b9980
// Size: 88 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_lockScoreBuffer(void)

{
  int iVar1;
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x18) == 0) {
    return 0;
  }
  Ordinal_1114(*(int *)(unaff_ESI + 0x18));
  iVar1 = xtra_writeValue(*(undefined4 **)(unaff_ESI + 0x18),0);
  *(int *)(unaff_ESI + 0x20) = *(int *)(unaff_ESI + 0x20) + 1;
  *(int *)(unaff_ESI + 0x1c) = iVar1;
  if (*(int *)(unaff_ESI + 0x20) == 1) {
    *(int *)(unaff_ESI + 0x28) = *(int *)(unaff_ESI + 0x2c) + iVar1;
    *(int *)(unaff_ESI + 0x30) = *(int *)(unaff_ESI + 0x34) + iVar1;
    *(int *)(unaff_ESI + 0x68) = *(int *)(unaff_ESI + 0x6c) + iVar1;
    *(undefined4 *)(unaff_ESI + 0x2c) = 0;
    *(undefined4 *)(unaff_ESI + 0x34) = 0;
    *(undefined4 *)(unaff_ESI + 0x6c) = 0;
  }
  return 1;
}



// ============================================================
// Function: media_unlockScoreBuffer (FUN_680b99e0)
// Address: 680b99e0
// Size: 73 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_unlockScoreBuffer(void)
{
  int iVar1;
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x18) != 0) {
    if (*(int *)(in_EAX + 0x20) == 1) {
      iVar1 = *(int *)(in_EAX + 0x1c);
      *(int *)(in_EAX + 0x2c) = *(int *)(in_EAX + 0x28) - iVar1;
      *(int *)(in_EAX + 0x34) = *(int *)(in_EAX + 0x30) - iVar1;
      *(int *)(in_EAX + 0x6c) = *(int *)(in_EAX + 0x68) - iVar1;
      *(undefined4 *)(in_EAX + 0x28) = 0;
      *(undefined4 *)(in_EAX + 0x30) = 0;
      *(undefined4 *)(in_EAX + 0x68) = 0;
      *(undefined4 *)(in_EAX + 0x1c) = 0;
    }
    *(int *)(in_EAX + 0x20) = *(int *)(in_EAX + 0x20) + -1;
    Ordinal_1115(*(int *)(in_EAX + 0x18));
  }
  return 0;
}



// ============================================================
// Function: media_getScoreBuffer (FUN_680b9a30)
// Address: 680b9a30
// Size: 136 bytes
// Return: undefined1 *
// Calling convention: __stdcall
// ============================================================

undefined1 * media_getScoreBuffer(void)

{
  undefined2 uVar1;
  undefined1 *in_EAX;
  undefined4 uVar2;
  undefined4 *unaff_EDI;
  
  uVar2 = xtra_readBE32Ptr(in_EAX);
  *unaff_EDI = uVar2;
  uVar2 = xtra_readBE32Ptr(in_EAX + 4);
  unaff_EDI[1] = uVar2;
  uVar2 = xtra_readBE32Ptr(in_EAX + 8);
  unaff_EDI[2] = uVar2;
  uVar1 = xtra_readBE16(in_EAX + 0xc);
  *(undefined2 *)(unaff_EDI + 3) = uVar1;
  uVar1 = xtra_readBE16(in_EAX + 0xe);
  *(undefined2 *)((int)unaff_EDI + 0xe) = uVar1;
  uVar1 = xtra_readBE16(in_EAX + 0x10);
  *(undefined2 *)(unaff_EDI + 4) = uVar1;
  if (0xc < *(short *)(unaff_EDI + 3)) {
    uVar1 = xtra_readBE16(in_EAX + 0x12);
    *(undefined2 *)((int)unaff_EDI + 0x12) = uVar1;
    return in_EAX + 0x14;
  }
  if (*(short *)(unaff_EDI + 3) < 8) {
    *(undefined2 *)((int)unaff_EDI + 0x12) = 0x30;
    return in_EAX + 0x14;
  }
  *(undefined2 *)((int)unaff_EDI + 0x12) = 0x78;
  return in_EAX + 0x14;
}



// ============================================================
// Function: media_getScoreBufferEx (FUN_680b9ac0)
// Address: 680b9ac0
// Size: 99 bytes
// Return: undefined1 *
// Calling convention: __stdcall
// ============================================================

undefined1 * media_getScoreBufferEx(void)

{
  undefined1 *in_EAX;
  
  xtra_skipBytes(in_EAX);
  xtra_skipBytes(in_EAX + 4);
  xtra_skipBytes(in_EAX + 8);
  xtra_readBE32(in_EAX + 0xc);
  xtra_readBE32(in_EAX + 0xe);
  xtra_readBE32(in_EAX + 0x10);
  xtra_readBE32(in_EAX + 0x12);
  return in_EAX + 0x14;
}



// ============================================================
// Function: media_getScoreBufferRef (FUN_680b9b30)
// Address: 680b9b30
// Size: 40 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreBufferRef(void)

{
  undefined4 local_18;
  
  Ordinal_1114();
  media_getScoreBuffer();
  Ordinal_1115();
  return local_18;
}



// ============================================================
// Function: media_readScoreBufferFull (FUN_680b9b60)
// Address: 680b9b60
// Size: 56 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_readScoreBufferFull(void)
{
  Ordinal_1114();
  media_getScoreBuffer();
  media_getScoreBufferEx();
  Ordinal_1115();
  return 0;
}



// ============================================================
// Function: media_getScoreBufferState (FUN_680b9ba0)
// Address: 680b9ba0
// Size: 41 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getScoreBufferState(void)

{
  undefined2 local_6;
  
  Ordinal_1114();
  media_getScoreBuffer();
  Ordinal_1115();
  return (int)local_6;
}



// ============================================================
// Function: media_readScoreBufferDirect (FUN_680b9bd0)
// Address: 680b9bd0
// Size: 58 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_readScoreBufferDirect(void)
{
  Ordinal_1114();
  media_getScoreBuffer();
  media_getScoreBufferEx();
  Ordinal_1115();
  return 0;
}



// ============================================================
// Function: media_readScoreBufferInfo (FUN_680b9c10)
// Address: 680b9c10
// Size: 56 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_readScoreBufferInfo(void)
{
  Ordinal_1114();
  media_getScoreBuffer();
  media_getScoreBufferEx();
  Ordinal_1115();
  return 0;
}



// ============================================================
// Function: media_validateScoreBuffer (FUN_680b9c50)
// Address: 680b9c50
// Size: 82 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_validateScoreBuffer(void)

{
  uint *in_EAX;
  
  if ((((((0x13 < *in_EAX) && (in_EAX[1] == 0x14)) && ((short)in_EAX[3] < 0xf)) &&
       ((*(ushort *)((int)in_EAX + 0xe) < 0x31 && (0x13 < (short)*(ushort *)((int)in_EAX + 0xe)))))
      && (((short)in_EAX[4] < 0x3ef &&
          ((0x31 < (short)in_EAX[4] && (0 < *(short *)((int)in_EAX + 0x12))))))) &&
     (*(short *)((int)in_EAX + 0x12) < 0x3e9)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: media_getScoreVersion2 (FUN_680b9cb0)
// Address: 680b9cb0
// Size: 16 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getScoreVersion2(void)

{
  int iVar1;
  int *unaff_ESI;
  
  iVar1 = xtra_writeValue(unaff_ESI,0);
  if (iVar1 == 0) {
    return 0;
  }
  return iVar1 - *unaff_ESI;
}



// ============================================================
// Function: media_computeScoreSlotOffset (FUN_680b9cc0)
// Address: 680b9cc0
// Size: 30 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_computeScoreSlotOffset(void)

{
  int in_EAX;
  int iVar1;
  
  if (in_EAX == 0) {
    in_EAX = 1000;
  }
  iVar1 = in_EAX + 6;
  if ((iVar1 < 0) || (0x3ee < iVar1)) {
    iVar1 = 0;
  }
  return iVar1 * 0x30;
}



// ============================================================
// Function: media_getScoreFormat (FUN_680b9ce0)
// Address: 680b9ce0
// Size: 22 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScoreFormat(undefined4 param_1)
{
  int iVar1;
  
  iVar1 = media_computeScoreSlotOffset();
  Ordinal_1130(param_1,iVar1);
  return 0;
}



// ============================================================
// Function: media_getScoreVersion (FUN_680b9d00)
// Address: 680b9d00
// Size: 23 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScoreVersion(undefined4 param_1)
{
  int iVar1;
  undefined4 extraout_ECX;
  
  iVar1 = media_computeScoreSlotOffset();
  Ordinal_1128(extraout_ECX,param_1,iVar1);
  return 0;
}



// ============================================================
// Function: media_copyScoreSlot (FUN_680b9d20)
// Address: 680b9d20
// Size: 64 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_copyScoreSlot(void)
{
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  iVar1 = unaff_EDI + 6;
  if ((-1 < iVar1) && (iVar1 < 0x3ee)) {
    Ordinal_1130(iVar1 * 0x30 + **(int **)(unaff_ESI + 0x88),0x30);
    *(undefined1 *)(unaff_ESI + 0x484 + unaff_EDI) = 0;
    return 0;
  }
  Ordinal_1130(0,0x30);
  *(undefined1 *)(unaff_ESI + 0x484 + unaff_EDI) = 0;
  return 0;
}




// ============================================================
// Function: media_copyScoreChannels (FUN_680b9d60)
// Address: 680b9d60
// Size: 294 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_copyScoreChannels(int param_1)
{
  uint uVar1;
  bool bVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  
  uVar1 = *(uint *)(in_EAX + 0x84);
  uVar4 = 0;
  bVar2 = false;
  *(undefined4 *)(in_EAX + 0x86c) = 0;
  *(undefined4 *)(in_EAX + 0x870) = 0xffffffff;
  if (0 < *(int *)(in_EAX + 0x3c)) {
    iVar5 = 0x120;
    do {
      if ((*(char *)(in_EAX + 0x9c + uVar4) != '\0') || (*(char *)(uVar4 + 0x484 + in_EAX) != '\0'))
      {
        if (uVar4 < 0x3ee) {
          puVar6 = (undefined4 *)(*(int *)(in_EAX + 0x54) + iVar5);
          puVar7 = (undefined4 *)(iVar5 + param_1);
          for (iVar3 = 0xc; iVar3 != 0; iVar3 = iVar3 + -1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
        }
        if (!bVar2) {
          *(uint *)(in_EAX + 0x86c) = uVar4;
          bVar2 = true;
        }
        *(uint *)(in_EAX + 0x870) = uVar4;
      }
      uVar4 = uVar4 + 1;
      iVar5 = iVar5 + 0x30;
    } while ((int)uVar4 < *(int *)(in_EAX + 0x3c));
  }
  if (uVar1 != 0) {
    if ((uVar1 & 1) != 0) {
      puVar6 = (undefined4 *)(*(int *)(in_EAX + 0x54) + 0xf0);
      puVar7 = (undefined4 *)(param_1 + 0xf0);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    if ((uVar1 & 2) != 0) {
      puVar6 = (undefined4 *)(*(int *)(in_EAX + 0x54) + 0xc0);
      puVar7 = (undefined4 *)(param_1 + 0xc0);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    if ((uVar1 & 4) != 0) {
      puVar6 = (undefined4 *)(*(int *)(in_EAX + 0x54) + 0x90);
      puVar7 = (undefined4 *)(param_1 + 0x90);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    if ((uVar1 & 8) != 0) {
      puVar6 = (undefined4 *)(*(int *)(in_EAX + 0x54) + 0x60);
      puVar7 = (undefined4 *)(param_1 + 0x60);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
    if ((uVar1 & 0x10) != 0) {
      puVar6 = (undefined4 *)(*(int *)(in_EAX + 0x54) + 0x30);
      puVar7 = (undefined4 *)(param_1 + 0x30);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar7 = *puVar6;
        puVar6 = puVar6 + 1;
        puVar7 = puVar7 + 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: media_applyScoreDelta (FUN_680b9e90)
// Address: 680b9e90
// Size: 438 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_applyScoreDelta(int param_1,int param_2)
{
  ushort uVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 *puVar11;
  int iVar12;
  int iVar13;
  undefined4 *puVar14;
  
  uVar2 = *(uint *)(param_1 + 0x14);
  iVar5 = *(int *)(param_1 + 0x86c);
  uVar1 = *(ushort *)(param_1 + 0x84);
  if (iVar5 <= *(int *)(param_1 + 0x870)) {
    iVar13 = (iVar5 * 3 + 0x12) * 0x10;
    do {
      if (*(char *)(param_1 + 0x9c + iVar5) == '\0') {
        if ((*(char *)(iVar5 + 0x484 + param_1) != '\0') && (0x5ff < uVar2)) {
          if ((iVar5 < -6) || (999 < iVar5)) {
            iVar6 = 0;
          }
          else {
            iVar6 = iVar13 + param_2;
          }
          if ((iVar5 < -6) || (999 < iVar5)) {
            iVar12 = 0;
          }
          else {
            iVar12 = *(int *)(param_1 + 0x8c) + iVar13;
          }
          if ((iVar5 < -6) || (999 < iVar5)) {
            puVar7 = (uint *)0x0;
          }
          else {
            puVar7 = (uint *)(*(int *)(param_1 + 0x54) + iVar13);
          }
          iVar9 = 0xc;
          puVar8 = puVar7;
          do {
            uVar4 = *(uint *)((iVar12 - (int)puVar7) + (int)puVar8);
            iVar9 = iVar9 + -1;
            *puVar8 = *(uint *)((iVar6 - (int)puVar7) + (int)puVar8) & uVar4 | ~uVar4 & *puVar8;
            puVar8 = puVar8 + 1;
          } while (iVar9 != 0);
        }
      }
      else {
        if ((iVar5 < -6) || (999 < iVar5)) {
          puVar11 = (undefined4 *)0x0;
        }
        else {
          puVar11 = (undefined4 *)(iVar13 + param_2);
        }
        if ((iVar5 < -6) || (999 < iVar5)) {
          puVar10 = (undefined4 *)0x0;
        }
        else {
          puVar10 = (undefined4 *)(*(int *)(param_1 + 0x54) + iVar13);
        }
        uVar3 = puVar10[2];
        puVar14 = puVar10;
        for (iVar6 = 0xc; iVar6 != 0; iVar6 = iVar6 + -1) {
          *puVar14 = *puVar11;
          puVar11 = puVar11 + 1;
          puVar14 = puVar14 + 1;
        }
        puVar10[2] = uVar3;
      }
      iVar5 = iVar5 + 1;
      iVar13 = iVar13 + 0x30;
    } while (iVar5 <= *(int *)(param_1 + 0x870));
  }
  if (uVar1 != 0) {
    if ((uVar1 & 1) != 0) {
      puVar11 = (undefined4 *)(param_2 + 0xf0);
      puVar10 = (undefined4 *)(*(int *)(param_1 + 0x54) + 0xf0);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar10 = puVar10 + 1;
      }
    }
    if ((uVar1 & 2) != 0) {
      puVar11 = (undefined4 *)(param_2 + 0xc0);
      puVar10 = (undefined4 *)(*(int *)(param_1 + 0x54) + 0xc0);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar10 = puVar10 + 1;
      }
    }
    if ((uVar1 & 4) != 0) {
      puVar11 = (undefined4 *)(param_2 + 0x90);
      puVar10 = (undefined4 *)(*(int *)(param_1 + 0x54) + 0x90);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar10 = puVar10 + 1;
      }
    }
    if ((uVar1 & 8) != 0) {
      puVar11 = (undefined4 *)(param_2 + 0x60);
      puVar10 = (undefined4 *)(*(int *)(param_1 + 0x54) + 0x60);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar10 = puVar10 + 1;
      }
    }
    if ((uVar1 & 0x10) != 0) {
      puVar11 = (undefined4 *)(param_2 + 0x30);
      puVar10 = (undefined4 *)(*(int *)(param_1 + 0x54) + 0x30);
      for (iVar5 = 0xc; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar10 = *puVar11;
        puVar11 = puVar11 + 1;
        puVar10 = puVar10 + 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: media_getScoreSlotPtr (FUN_680ba060)
// Address: 680ba060
// Size: 265 bytes
// Params: int param_1, int param_2
// Return: undefined1 *
// Calling convention: __stdcall
// ============================================================

undefined1 * media_getScoreSlotPtr(int param_1,int param_2)

{
  ushort uVar1;
  undefined1 *in_EAX;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 *puVar7;
  
  if ((param_1 != 0) && (in_EAX != (undefined1 *)0x0)) {
    uVar1 = xtra_readBE16(in_EAX);
    if (uVar1 == 0) {
      return (undefined1 *)0x0;
    }
    iVar5 = uVar1 - 2;
    in_EAX = in_EAX + 2;
    if (iVar5 < 1) {
      return in_EAX;
    }
    do {
      uVar3 = (uint)CONCAT11(*in_EAX,in_EAX[1]);
      uVar2 = (uint)CONCAT11(in_EAX[2],in_EAX[3]);
      in_EAX = in_EAX + 4;
      uVar6 = iVar5 - 4;
      if (((((int)uVar6 < 0) || (0x17940 < uVar6)) || (0xbca0 < uVar3)) || (0xbca0 < uVar2)) {
        return in_EAX + uVar6;
      }
      puVar7 = (undefined1 *)(uVar2 + param_1);
      uVar4 = uVar3;
      if (param_2 < (int)(uVar2 + uVar3)) {
        if ((int)uVar2 < param_2) {
          uVar4 = param_2 - uVar2;
          if ((int)uVar3 < (int)(param_2 - uVar2)) {
            uVar4 = uVar3;
          }
          if (0 < (int)uVar4) {
            iVar5 = (int)in_EAX - (int)puVar7;
            do {
              *puVar7 = puVar7[iVar5];
              puVar7 = puVar7 + 1;
              uVar4 = uVar4 - 1;
            } while (uVar4 != 0);
          }
        }
        in_EAX = in_EAX + uVar3;
      }
      else {
        for (; uVar4 != 0; uVar4 = uVar4 - 1) {
          *puVar7 = *in_EAX;
          puVar7 = puVar7 + 1;
          in_EAX = in_EAX + 1;
        }
      }
      iVar5 = uVar6 - uVar3;
    } while (0 < iVar5);
  }
  return in_EAX;
}



// ============================================================
// Function: media_writeScoreChannelData (FUN_680ba170)
// Address: 680ba170
// Size: 242 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeScoreChannelData(int param_1,int param_2)
{
  undefined2 uVar1;
  undefined2 uVar2;
  short sVar3;
  short sVar4;
  undefined1 *in_EAX;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 local_8;
  
  if (*(short *)(in_EAX + 2) != 0) {
    rendering_writeChannelData(in_EAX,param_1);
  }
  uVar1 = xtra_readBE16(in_EAX + 0x60);
  uVar2 = xtra_readBE16(in_EAX + 0x62);
  local_8 = CONCAT22(uVar2,uVar1);
  iVar5 = rendering_getStageFlags(local_8);
  if (iVar5 == 0) {
    rendering_writeChannelData(in_EAX + 0x60,param_1);
  }
  rendering_writeChannelData(in_EAX + 0xc0,param_1);
  rendering_writeChannelData(in_EAX + 0x90,param_1);
  sVar3 = xtra_readBE16(in_EAX + 0xf0);
  sVar4 = xtra_readBE16(in_EAX + 0xf2);
  if ((sVar3 != -1) || (-1 < sVar4)) {
    rendering_writeChannelData(in_EAX + 0xf0,param_1);
  }
  if (param_2 == 0) {
    param_2 = 1000;
  }
  if (-1 < param_2) {
    iVar5 = 6;
    pcVar6 = in_EAX + 0x120;
    do {
      if ((iVar5 < 0) || (pcVar7 = pcVar6, 0x3ed < iVar5)) {
        pcVar7 = (char *)0x0;
      }
      if ((*pcVar7 != '\0') && (rendering_writeChannelData(pcVar7 + 4,param_1), *(short *)(pcVar7 + 6) == 0)) {
        *pcVar7 = '\0';
      }
      pcVar6 = pcVar6 + 0x30;
      iVar5 = iVar5 + 1;
      param_2 = param_2 + -1;
    } while (param_2 != 0);
  }
  return 0;
}



// ============================================================
// Function: media_dispatchScoreChannelWrite (FUN_680ba270)
// Address: 680ba270
// Size: 74 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_dispatchScoreChannelWrite(void)
{
  undefined4 *puVar1;
  int unaff_ESI;
  undefined2 *local_8;
  
  local_8 = (undefined2 *)0x0;
  puVar1 = (undefined4 *)rendering_getChannelSprite(*(int *)(unaff_ESI + 8),*(short *)(unaff_ESI + 0xc));
  if (puVar1 != (undefined4 *)0x0) {
    local_8 = rendering_getChannelSlot(puVar1,4,*(int *)(unaff_ESI + 0x10));
    if (local_8 != (undefined2 *)0x0) {
      media_writeScoreChannelData((int)local_8,*(int *)(unaff_ESI + 0x3c));
    }
  }
  rendering_processChannelEvent((int *)&local_8);
  return 0;
}



// ============================================================
// Function: media_applyScoreSlotData (FUN_680ba2c0)
// Address: 680ba2c0
// Size: 42 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_applyScoreSlotData(void)
{
  undefined1 *puVar1;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  
  puVar1 = media_getScoreSlotPtr(*(int *)(unaff_ESI + 0x5c),*(int *)(unaff_ESI + 0x40) * 0x30);
  *unaff_EDI = puVar1;
  *(undefined1 **)(unaff_ESI + 0x68) = puVar1;
  media_getScoreVersion(*(undefined4 *)(unaff_ESI + 0x5c));
  return 0;
}



// ============================================================
// Function: media_getScoreDataInfo (FUN_680ba2f0)
// Address: 680ba2f0
// Size: 23 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScoreDataInfo(void)
{
  int unaff_ESI;
  
  if (*(int *)(unaff_ESI + 0x4c) != 0) {
    Ordinal_1163(unaff_ESI + 0x4c);
  }
  *(undefined4 *)(unaff_ESI + 0x48) = 0;
  return 0;
}



// ============================================================
// Function: media_countScoreSlots (FUN_680ba310)
// Address: 680ba310
// Size: 105 bytes
// Params: undefined1 * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_countScoreSlots(undefined1 *param_1)

{
  ushort uVar1;
  undefined1 *in_EAX;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  while (in_EAX < param_1) {
    uVar1 = xtra_readBE16(in_EAX);
    in_EAX = in_EAX + 2;
    for (iVar4 = uVar1 - 2; iVar4 != 0; iVar4 = (iVar4 + -4) - uVar2) {
      uVar2 = (uint)CONCAT11(*in_EAX,in_EAX[1]);
      uVar3 = CONCAT11(in_EAX[2],in_EAX[3]) + uVar2;
      if (uVar5 < uVar3) {
        uVar5 = uVar3;
      }
      in_EAX = in_EAX + uVar2 + 4;
    }
  }
  return (uVar5 + 0x2f) / 0x30;
}




// ============================================================
// Function: media_getScoreChannelCount (FUN_680ba380)
// Address: 680ba380
// Size: 77 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getScoreChannelCount(int param_1)

{
  int unaff_EBX;
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_18;
  
  uVar2 = 0;
  iVar1 = 0;
  if (unaff_EBX != 0) {
    iVar1 = Ordinal_1114();
    iVar1 = iVar1 + param_1;
    media_getScoreBuffer();
    uVar2 = media_countScoreSlots((undefined1 *)(local_18 + iVar1));
  }
  iVar3 = uVar2 - 6;
  if (iVar3 < 0) {
    iVar3 = 0;
  }
  if (iVar1 != 0) {
    Ordinal_1115();
  }
  return iVar3;
}



// ============================================================
// Function: media_getScoreDataSize (FUN_680ba3d0)
// Address: 680ba3d0
// Size: 122 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getScoreDataSize(void)

{
  int iVar1;
  
  iVar1 = Ordinal_1111(0x11b0c,1);
  if (iVar1 != 0) {
    Ordinal_1114(iVar1);
    media_getScoreBufferEx();
    Ordinal_1115(iVar1);
  }
  return iVar1;
}



// ============================================================
// Function: media_encodeScoreDelta (FUN_680ba450)
// Address: 680ba450
// Size: 343 bytes
// Params: short * param_1, short * param_2, undefined4 * param_3, int * param_4, int * param_5
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
media_encodeScoreDelta(short *param_1,short *param_2,undefined4 *param_3,int *param_4,int *param_5)

{
  int iVar1;
  short *psVar2;
  short sVar3;
  uint in_EAX;
  int iVar4;
  short *psVar5;
  undefined1 *puVar6;
  short *psVar7;
  short *local_14;
  int local_c;
  uint local_8;
  
  local_8 = in_EAX >> 1;
  iVar4 = Ordinal_1116(*param_3);
  iVar1 = *param_4;
  if (((uint)(iVar4 - iVar1) < 0x11b0c) &&
     (iVar4 = Ordinal_1117(param_3,iVar4 + 0x11b0c,0), iVar4 == 0)) {
    return 0;
  }
  iVar4 = Ordinal_1114(*param_3);
  puVar6 = (undefined1 *)(iVar1 + iVar4);
  local_c = 2;
  psVar2 = (short *)(puVar6 + 2);
  local_14 = param_1;
  do {
    if (local_8 == 0) {
LAB_680ba56c:
      xtra_readBE32(puVar6);
      *param_4 = *param_4 + local_c;
      *param_5 = *param_5 + 1;
      if (iVar4 != 0) {
        Ordinal_1115(*param_3);
      }
      return 1;
    }
    if (*param_2 == *local_14) {
      do {
        local_14 = local_14 + 1;
        param_2 = param_2 + 1;
        local_8 = local_8 - 1;
        if (local_8 == 0) goto LAB_680ba56c;
      } while (*param_2 == *local_14);
    }
    sVar3 = *local_14;
    psVar7 = psVar2 + 2;
    psVar5 = param_2;
    if (*param_2 != sVar3) {
      do {
        *psVar7 = sVar3;
        psVar5 = psVar5 + 1;
        local_14 = local_14 + 1;
        psVar7 = psVar7 + 1;
        local_8 = local_8 - 1;
        if (local_8 == 0) break;
        sVar3 = *local_14;
      } while (*psVar5 != sVar3);
    }
    local_c = (int)psVar5 + ((local_c + 4) - (int)param_2);
    xtra_readBE32((undefined1 *)psVar2);
    xtra_readBE32((undefined1 *)(psVar2 + 1));
    psVar2 = psVar7;
    param_2 = psVar5;
  } while( true );
}



// ============================================================
// Function: media_getScoreLayout (FUN_680ba5c0)
// Address: 680ba5c0
// Size: 325 bytes
// Params: undefined4 * param_1, int * param_2, int * param_3, short * param_4, short * param_5, int param_6, int param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
media_getScoreLayout(undefined4 *param_1,int *param_2,int *param_3,short *param_4,short *param_5,int param_6
            ,int param_7)

{
  undefined4 uVar1;
  int iVar2;
  ushort *puVar3;
  short sVar4;
  int local_14;
  short *local_10;
  uint local_c;
  int local_8;
  
  local_14 = 0;
  local_8 = 0;
  if (6 < param_6 + 6) {
    local_10 = param_5 + 0x90;
    local_c = 6;
    do {
      if (local_c < 0x3ee) {
        iVar2 = ((int)param_4 - (int)param_5) + (int)local_10;
      }
      else {
        iVar2 = 0;
      }
      puVar3 = (ushort *)(~-(uint)(0x3ed < local_c) & (uint)local_10);
      if ((iVar2 == 0) || (puVar3 == (ushort *)0x0)) {
        return 0;
      }
      if ((*(int *)(iVar2 + 8) != 0) && (*(int *)(iVar2 + 8) != *(int *)(puVar3 + 4))) {
        sVar4 = 0x18;
        if ((param_7 != 0) && (local_8 == 0)) {
          local_14 = Ordinal_1111(0xbca0,1);
          if (local_14 == 0) break;
          local_8 = Ordinal_1114(local_14);
          if (local_8 != 0) {
            media_getScoreVersion(param_5);
          }
        }
        iVar2 = iVar2 - (int)puVar3;
        do {
          sVar4 = sVar4 + -1;
          *puVar3 = *(ushort *)(iVar2 + (int)puVar3) ^ 0xff;
          puVar3 = puVar3 + 1;
        } while (sVar4 != 0);
      }
      local_c = local_c + 1;
      local_10 = local_10 + 0x18;
    } while ((int)local_c < param_6 + 6);
  }
  media_computeScoreSlotOffset();
  uVar1 = media_encodeScoreDelta(param_4,param_5,param_1,param_2,param_3);
  if (local_8 != 0) {
    media_getScoreVersion(local_8);
    Ordinal_1113(&local_14);
  }
  return uVar1;
}



// ============================================================
// Function: media_getScoreLayoutSize (FUN_680ba710)
// Address: 680ba710
// Size: 81 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScoreLayoutSize(void)
{
  undefined4 *unaff_ESI;
  
  Ordinal_1117();
  Ordinal_1114(*unaff_ESI);
  media_getScoreBuffer();
  media_getScoreBufferEx();
  Ordinal_1115(*unaff_ESI);
  return 0;
}



// ============================================================
// Function: media_findScoreFrameRange (FUN_680ba770)
// Address: 680ba770
// Size: 168 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4, int * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_findScoreFrameRange(undefined4 param_1,int param_2,int param_3,int param_4,int *param_5)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_8;
  
  local_8 = 0;
  iVar3 = 1;
  iVar2 = Ordinal_1114(param_1);
  media_getScoreBuffer();
  iVar4 = local_18;
  if (local_18 < local_1c) {
    if (param_3 < 1) {
      param_3 = 1;
    }
    while( true ) {
      if (iVar3 == param_3) {
        local_8 = local_18;
      }
      uVar1 = xtra_readBE16((undefined1 *)(iVar2 + param_2 + local_18));
      iVar4 = local_8;
      if ((0x17940 < uVar1) || (param_3 + -1 + param_4 < iVar3)) goto LAB_680ba7f9;
      local_18 = local_18 + (uint)uVar1;
      if (local_1c <= local_18) break;
      iVar3 = iVar3 + 1;
    }
    if (iVar3 < param_3) {
      iVar4 = local_18;
    }
  }
LAB_680ba7f9:
  *param_5 = local_18 - iVar4;
  if (iVar2 + param_2 != 0) {
    Ordinal_1115(param_1);
  }
  return iVar4;
}



// ============================================================
// Function: media_removeScoreFrames (FUN_680ba820)
// Address: 680ba820
// Size: 135 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_removeScoreFrames(undefined4 param_1,int param_2,int param_3)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_EDI;
  int local_8;
  
  iVar1 = media_findScoreFrameRange(*unaff_EDI,0,param_2,param_3,&local_8);
  iVar3 = local_8;
  if (local_8 != 0) {
    iVar2 = media_getScoreBufferRef();
    iVar3 = (iVar2 - iVar3) - iVar1;
    if (iVar3 != 0) {
      iVar2 = Ordinal_1114(*unaff_EDI);
      Ordinal_1128(iVar2 + iVar1,local_8 + iVar2 + iVar1,iVar3);
      Ordinal_1115(*unaff_EDI);
    }
    Ordinal_1117();
    media_readScoreBufferFull();
    media_readScoreBufferInfo();
  }
  return 0;
}



// ============================================================
// Function: media_getScoreLayoutRef (FUN_680ba8b0)
// Address: 680ba8b0
// Size: 277 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreLayoutRef(int param_1,undefined4 param_2,undefined4 param_3)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *unaff_EDI;
  
  iVar1 = Ordinal_1116(param_2);
  iVar2 = media_getScoreBufferRef();
  for (iVar4 = in_EAX; 0 < iVar4; iVar4 = iVar4 + -1) {
    Ordinal_1115(*unaff_EDI);
  }
  iVar4 = Ordinal_1117();
  for (; 0 < in_EAX; in_EAX = in_EAX + -1) {
    Ordinal_1114(*unaff_EDI);
  }
  if (iVar4 != 0) {
    iVar4 = media_findScoreFrameRange(*unaff_EDI,0,param_1,0,&param_1);
    iVar3 = Ordinal_1114(*unaff_EDI);
    param_1 = Ordinal_1114(param_2);
    Ordinal_1129(iVar4 + iVar1 + iVar3,iVar4 + iVar3,iVar2 - iVar4);
    Ordinal_1128(iVar4 + iVar3,param_1,iVar1);
    media_readScoreBufferFull();
    media_readScoreBufferInfo();
    if (iVar3 != 0) {
      Ordinal_1115(*unaff_EDI);
    }
    if (param_1 != 0) {
      Ordinal_1115(param_2);
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: media_getScoreLayoutBlock (FUN_680ba9d0)
// Address: 680ba9d0
// Size: 66 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreLayoutBlock(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = media_getScoreBufferRef();
  iVar2 = Ordinal_1114(param_1);
  Ordinal_1128(iVar2,iVar2 + 0x14,iVar1 + -0x14);
  Ordinal_1115(param_1);
  Ordinal_1117(&param_1,iVar1 + -0x14,0);
  return param_1;
}



// ============================================================
// Function: media_allocScoreChunk (FUN_680baa20)
// Address: 680baa20
// Size: 35 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall media_allocScoreChunk(int param_1)

{
  int *in_EAX;
  uint uVar1;
  
  if ((in_EAX != (int *)0x0) && (uVar1 = xtra_readChunkBlock(in_EAX,1,param_1 * 4), (short)uVar1 == 0)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: media_readScoreLayoutEntry (FUN_680baa50)
// Address: 680baa50
// Size: 176 bytes
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * media_readScoreLayoutEntry(void)

{
  short sVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  
  local_8 = 0;
  piVar2 = (int *)xtra_allocChunkStorage(0xc,0,0,-3);
  if (piVar2 != (int *)0x0) {
    if ((unaff_EDI == (undefined4 *)0x0) || ((undefined4 *)*unaff_EDI == (undefined4 *)0x0)) {
      sVar1 = xtra_readChunk(piVar2,0,&local_8,4);
    }
    else {
      uVar3 = xtra_readSerializedValue(piVar2,0,(undefined4 *)*unaff_EDI);
      sVar1 = (short)uVar3;
    }
    if (sVar1 == 0) {
      local_c = 0;
      sVar1 = xtra_readChunk(piVar2,1,&local_c,4);
      if (sVar1 == 0) {
        iVar4 = media_allocScoreChunk(0x200);
        if (iVar4 != 0) {
          sVar1 = xtra_readChunk(piVar2,2,&local_8,4);
          if (sVar1 == 0) {
            sVar1 = xtra_readChunk(piVar2,2,0,0);
            if (sVar1 == 0) goto LAB_680baaef;
          }
        }
      }
    }
    score_freePropertyHandle(piVar2);
    piVar2 = (int *)0x0;
  }
LAB_680baaef:
  if (unaff_EDI != (undefined4 *)0x0) {
    Ordinal_1113();
  }
  return piVar2;
}




// ============================================================
// Function: media_encodeScoreLayout (FUN_680bab00)
// Address: 680bab00
// Size: 76 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_encodeScoreLayout(void)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = media_getScoreLayout((undefined4 *)(unaff_ESI + 0x880),(int *)(unaff_ESI + 0x890),
                       (int *)(unaff_ESI + 0x88c),*(short **)(unaff_ESI + 0x54),
                       *(short **)(unaff_ESI + 0x894),*(int *)(unaff_ESI + 0x3c),0);
  if (iVar1 != 0) {
    media_getScoreVersion(*(undefined4 *)(unaff_ESI + 0x54));
    return 1;
  }
  return 0;
}



// ============================================================
// Function: media_freeScoreLayoutState (FUN_680bab50)
// Address: 680bab50
// Size: 57 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_freeScoreLayoutState(void)
{
  int in_EAX;
  
  if (*(int *)(in_EAX + 0x87c) != 0) {
    Ordinal_1113(in_EAX + 0x880);
    Ordinal_1125(in_EAX + 0x894);
    Ordinal_1130(in_EAX + 0x87c,0x80c);
  }
  return 0;
}



// ============================================================
// Function: media_computeScoreDataRange (FUN_680bab90)
// Address: 680bab90
// Size: 93 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_computeScoreDataRange(int *param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint local_8;
  
  local_8 = bitmap_getRtfData(in_EAX);
  iVar2 = 0;
  iVar3 = 1;
  if (0 < (int)local_8) {
    do {
      iVar1 = bitmap_readRtfInt(in_EAX,iVar3);
      iVar1 = bitmap_readRtfValue(in_EAX,iVar1);
      if (iVar2 < iVar1) {
        iVar2 = iVar1;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 <= (int)local_8);
  }
  puVar5 = &local_8;
  iVar4 = 0;
  iVar3 = iVar2;
  iVar1 = media_getScoreVersion2();
  iVar3 = media_findScoreFrameRange(in_EAX,iVar1,iVar4,iVar3,(int *)puVar5);
  *param_1 = iVar3 + local_8;
  return iVar2;
}



// ============================================================
// Function: media_getScoreLayoutData (FUN_680babf0)
// Address: 680babf0
// Size: 209 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreLayoutData(int *param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  piVar1 = param_1;
  xtra_writeValue(param_1,0);
  media_getScoreBuffer();
  media_computeScoreDataRange((int *)&param_1);
  iVar3 = xtra_readSerializedBlock(piVar1,0);
  piVar2 = param_1;
  if (iVar3 - (int)param_1 < 4) {
    uVar4 = 0;
  }
  else {
    param_1 = xtra_readSerializedPtr(piVar1,0);
    Ordinal_1117(&param_1,piVar2,0);
    Ordinal_1114(param_1);
    media_getScoreBufferEx();
    Ordinal_1115(param_1);
    uVar4 = xtra_readSerializedValue(piVar1,0,param_1);
    Ordinal_1113(&param_1);
    if ((short)uVar4 != 0) {
      return 0;
    }
    uVar4 = 1;
  }
  uVar5 = bitmap_getRtfData(piVar1);
  bitmap_resizeRtfBlock(piVar1,uVar5 + 1);
  xtra_compactChunk(piVar1);
  return uVar4;
}



// ============================================================
// Function: media_convertScoreOldToNew (FUN_680bacd0)
// Address: 680bacd0
// Size: 558 bytes
// Params: undefined1 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_convertScoreOldToNew(undefined1 *param_1)
{
  int iVar1;
  int in_EAX;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int local_c;
  undefined1 *local_8;
  
  xtra_readBE32(param_1);
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(in_EAX + 0x10);
  xtra_readBE32(param_1 + 4);
  *(undefined2 *)(param_1 + 6) = *(undefined2 *)(in_EAX + 6);
  xtra_readBE32(param_1 + 8);
  *(undefined2 *)(param_1 + 10) = *(undefined2 *)(in_EAX + 8);
  if (*(byte *)(in_EAX + 5) != 0) {
    rendering_packColorValue(*(byte *)(in_EAX + 5),*(byte *)(in_EAX + 2) & 0x7f,*(byte *)(in_EAX + 3),
                 (ushort)(*(byte *)(in_EAX + 2) >> 7));
  }
  xtra_readBE32(param_1 + 0xc);
  xtra_readBE32(param_1 + 0xe);
  param_1[0x15] = *(undefined1 *)(in_EAX + 4);
  param_1[0x10] = *(undefined1 *)(in_EAX + 0xd);
  param_1[0x11] = *(undefined1 *)(in_EAX + 0xe);
  param_1[0x12] = *(undefined1 *)(in_EAX + 0xf);
  param_1[0x13] = *(undefined1 *)(in_EAX + 0x12);
  param_1[0x14] = *(undefined1 *)(in_EAX + 0x13);
  xtra_readBE32(param_1 + 0x18);
  *(undefined2 *)(param_1 + 0x1a) = *(undefined2 *)(in_EAX + 0x14);
  param_1[0x1c] = *(undefined1 *)(in_EAX + 0x19);
  param_1[0x1d] = *(undefined1 *)(in_EAX + 0x18);
  param_1[0x1e] = *(undefined1 *)(in_EAX + 0x16);
  param_1[0x1f] = *(undefined1 *)(in_EAX + 0x17);
  *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(in_EAX + 0x1a);
  *(undefined2 *)(param_1 + 0x22) = *(undefined2 *)(in_EAX + 0x1c);
  param_1[0x24] = *(undefined1 *)(in_EAX + 0x1e);
  param_1[0x25] = *(undefined1 *)(in_EAX + 0x1f);
  local_8 = param_1 + 0x30;
  param_1[0x26] = *(undefined1 *)(in_EAX + 0x20);
  local_c = 2;
  iVar2 = in_EAX + 0x28;
  iVar1 = 0x30;
  do {
    if ((local_c < 0) || (iVar4 = iVar2, 0x3ed < local_c)) {
      iVar4 = 0;
    }
    if ((local_c < 0) || (puVar3 = local_8, 0x3ed < local_c)) {
      puVar3 = (undefined1 *)0x0;
    }
    xtra_readBE32(puVar3 + 2);
    *(undefined2 *)(puVar3 + 4) = *(undefined2 *)(iVar4 + 6);
    xtra_readBE32(puVar3 + 6);
    *(undefined2 *)(puVar3 + 8) = *(undefined2 *)(iVar4 + 0x10);
    *puVar3 = *(undefined1 *)(iVar4 + 1);
    puVar3[1] = *(undefined1 *)(iVar4 + 5);
    local_8 = local_8 + 0x18;
    puVar3[10] = *(undefined1 *)(iVar4 + 2);
    puVar3[0xb] = *(undefined1 *)(iVar4 + 3);
    *(undefined4 *)(puVar3 + 0xc) = *(undefined4 *)(iVar4 + 8);
    *(undefined4 *)(puVar3 + 0x10) = *(undefined4 *)(iVar4 + 0xc);
    puVar3[0x14] = *(undefined1 *)(iVar4 + 0x12);
    puVar3[0x15] = *(undefined1 *)(iVar4 + 0x13);
    local_c = local_c + 1;
    iVar2 = iVar2 + 0x14;
    iVar1 = iVar1 + -1;
    puVar3[0x16] = *(undefined1 *)(iVar4 + 4);
  } while (iVar1 != 0);
  return 0;
}



// ============================================================
// Function: media_convertScoreFromOldFormat (FUN_680baf00)
// Address: 680baf00
// Size: 382 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_convertScoreFromOldFormat(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  short *_Src;
  undefined1 *puVar3;
  int iVar4;
  int local_40;
  int local_24;
  int local_20;
  short *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  bVar1 = false;
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  iVar2 = media_getScoreBufferState();
  if ((((-1 < iVar2) && (local_8 = media_getScoreDataSize(), local_8 != 0)) &&
      (local_c = Ordinal_1111(0x4e98,1), local_c != 0)) &&
     ((local_10 = Ordinal_1111(0x5e50,1), local_10 != 0 &&
      (local_14 = Ordinal_1111(0x5e50,1), local_14 != 0)))) {
    local_18 = Ordinal_1114(local_c);
    local_1c = (short *)Ordinal_1114(local_10);
    _Src = (short *)Ordinal_1114(local_14);
    local_24 = 0x14;
    local_20 = 0;
    iVar2 = Ordinal_1114(param_1);
    puVar3 = media_getScoreBuffer();
    while (puVar3 < (undefined1 *)(local_40 + iVar2)) {
      puVar3 = media_getScoreSlotPtr(local_18,0x4e98);
      media_convertScoreOldToNew((undefined1 *)_Src);
      iVar4 = media_encodeScoreDelta(_Src,local_1c,&local_8,&local_24,&local_20);
      if (iVar4 == 0) goto LAB_680bb041;
      memcpy(local_1c,_Src,0x5e50);
    }
    media_getScoreLayoutSize();
    bVar1 = true;
  }
LAB_680bb041:
  Ordinal_1113(&local_c);
  Ordinal_1113(&local_10);
  Ordinal_1113(&local_14);
  Ordinal_1113(&param_1);
  if (!bVar1) {
    Ordinal_1113(&local_8);
  }
  return local_8;
}



// ============================================================
// Function: media_mapSpriteInkValue (FUN_680bb080)
// Address: 680bb080
// Size: 142 bytes
// Params: short * param_1, short * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_mapSpriteInkValue(short *param_1,short *param_2)
{
  short sVar1;
  
  sVar1 = *param_1;
  if (sVar1 == -0x80) {
    *param_1 = -8;
    return 0;
  }
  if (sVar1 == -0x79) {
    *param_1 = -1;
    *param_2 = -2;
    return 0;
  }
  if (sVar1 == -0x7a) {
    *param_1 = -2;
    *param_2 = -2;
    return 0;
  }
  if (sVar1 < -0x78) {
    if (sVar1 < -0x47) goto LAB_680bb0f8;
  }
  else if (sVar1 < -0x47) {
    *param_1 = sVar1 + 0x79;
    *param_2 = -2;
    return 0;
  }
  if (sVar1 < 0) {
    *param_1 = -9;
    *param_2 = -sVar1;
    return 0;
  }
LAB_680bb0f8:
  if (sVar1 < 1) {
    *param_1 = 0;
    return 0;
  }
  *param_1 = -10;
  *param_2 = sVar1;
  return 0;
}



// ============================================================
// Function: media_convertScoreNewToOld (FUN_680bb110)
// Address: 680bb110
// Size: 727 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_convertScoreNewToOld(undefined4 *param_1)
{
  char cVar1;
  undefined4 *in_EAX;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_c;
  uint local_8;
  
  *param_1 = *in_EAX;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = *(undefined1 *)((int)in_EAX + 0x13);
  cVar1 = *(char *)((int)in_EAX + 0x15);
  param_1[6] = 0;
  local_8 = (int)cVar1 & 0xffff;
  *(undefined1 *)((int)param_1 + 0x1f) = *(undefined1 *)(in_EAX + 4);
  local_c = 0;
  media_mapSpriteInkValue((short *)&local_8,(short *)&local_c);
  *(undefined1 *)((int)param_1 + 0x1e) = (undefined1)local_8;
  xtra_readBE32((undefined1 *)(param_1 + 7));
  param_1[0xc] = in_EAX[3];
  param_1[0xd] = 0;
  *(undefined1 *)(param_1 + 0xe) = *(undefined1 *)(in_EAX + 5);
  param_1[0x12] = in_EAX[2];
  param_1[0x13] = 0;
  *(undefined1 *)(param_1 + 0x14) = *(undefined1 *)((int)in_EAX + 0x12);
  param_1[0x18] = in_EAX[1];
  param_1[0x19] = 0;
  *(undefined1 *)(param_1 + 0x1a) = *(undefined1 *)((int)in_EAX + 0x11);
  param_1[0x1e] = in_EAX[6];
  *(undefined1 *)(param_1 + 0x1f) = *(undefined1 *)(in_EAX + 7);
  *(undefined1 *)((int)param_1 + 0x7d) = *(undefined1 *)((int)in_EAX + 0x1d);
  *(undefined1 *)((int)param_1 + 0x7e) = *(undefined1 *)((int)in_EAX + 0x1e);
  *(undefined1 *)((int)param_1 + 0x7f) = *(undefined1 *)((int)in_EAX + 0x1f);
  *(undefined2 *)(param_1 + 0x20) = *(undefined2 *)(in_EAX + 8);
  *(undefined2 *)((int)param_1 + 0x82) = *(undefined2 *)((int)in_EAX + 0x22);
  *(undefined1 *)(param_1 + 0x21) = *(undefined1 *)(in_EAX + 9);
  *(undefined1 *)((int)param_1 + 0x85) = *(undefined1 *)((int)in_EAX + 0x25);
  *(undefined1 *)((int)param_1 + 0x86) = *(undefined1 *)((int)in_EAX + 0x26);
  *(undefined1 *)((int)param_1 + 0x87) = *(undefined1 *)((int)in_EAX + 0x27);
  param_1[0x22] = 0;
  puVar5 = param_1 + 0x2a;
  iVar4 = 6;
  puVar6 = in_EAX + 0x12;
  local_c = 0xc;
  do {
    if ((iVar4 + -4 < 0) || (0x3ed < iVar4 + -4)) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = puVar6 + -6;
    }
    if ((iVar4 < 0) || (0x3ed < iVar4)) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = puVar5 + -6;
    }
    *(undefined1 *)puVar2 = *(undefined1 *)puVar3;
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)puVar3 + 1);
    puVar2[1] = *(undefined4 *)((int)puVar3 + 2);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar3 + 10);
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar3 + 0xb);
    puVar2[3] = puVar3[3];
    puVar2[4] = puVar3[4];
    *(undefined1 *)(puVar2 + 5) = *(undefined1 *)(puVar3 + 5);
    *(undefined1 *)((int)puVar2 + 0x15) = *(undefined1 *)((int)puVar3 + 0x15);
    *(undefined1 *)((int)puVar2 + 0x16) = *(undefined1 *)((int)puVar3 + 0x16);
    puVar2[2] = 0;
    if ((iVar4 + -3 < 0) || (puVar3 = puVar6, 0x3ed < iVar4 + -3)) {
      puVar3 = (undefined4 *)0x0;
    }
    if ((iVar4 + 1 < 0) || (puVar2 = puVar5, 0x3ed < iVar4 + 1)) {
      puVar2 = (undefined4 *)0x0;
    }
    *(undefined1 *)puVar2 = *(undefined1 *)puVar3;
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)puVar3 + 1);
    puVar2[1] = *(undefined4 *)((int)puVar3 + 2);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar3 + 10);
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar3 + 0xb);
    puVar2[3] = puVar3[3];
    puVar2[4] = puVar3[4];
    *(undefined1 *)(puVar2 + 5) = *(undefined1 *)(puVar3 + 5);
    *(undefined1 *)((int)puVar2 + 0x15) = *(undefined1 *)((int)puVar3 + 0x15);
    *(undefined1 *)((int)puVar2 + 0x16) = *(undefined1 *)((int)puVar3 + 0x16);
    puVar2[2] = 0;
    if ((iVar4 + -2 < 0) || (0x3ed < iVar4 + -2)) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = puVar6 + 6;
    }
    if ((iVar4 + 2 < 0) || (0x3ed < iVar4 + 2)) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = puVar5 + 6;
    }
    *(undefined1 *)puVar2 = *(undefined1 *)puVar3;
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)puVar3 + 1);
    puVar2[1] = *(undefined4 *)((int)puVar3 + 2);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar3 + 10);
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar3 + 0xb);
    puVar2[3] = puVar3[3];
    puVar2[4] = puVar3[4];
    *(undefined1 *)(puVar2 + 5) = *(undefined1 *)(puVar3 + 5);
    *(undefined1 *)((int)puVar2 + 0x15) = *(undefined1 *)((int)puVar3 + 0x15);
    *(undefined1 *)((int)puVar2 + 0x16) = *(undefined1 *)((int)puVar3 + 0x16);
    puVar2[2] = 0;
    if ((iVar4 + -1 < 0) || (0x3ed < iVar4 + -1)) {
      puVar3 = (undefined4 *)0x0;
    }
    else {
      puVar3 = puVar6 + 0xc;
    }
    if ((iVar4 + 3 < 0) || (0x3ed < iVar4 + 3)) {
      puVar2 = (undefined4 *)0x0;
    }
    else {
      puVar2 = puVar5 + 0xc;
    }
    *(undefined1 *)puVar2 = *(undefined1 *)puVar3;
    *(undefined1 *)((int)puVar2 + 1) = *(undefined1 *)((int)puVar3 + 1);
    puVar2[1] = *(undefined4 *)((int)puVar3 + 2);
    *(undefined1 *)((int)puVar2 + 2) = *(undefined1 *)((int)puVar3 + 10);
    *(undefined1 *)((int)puVar2 + 3) = *(undefined1 *)((int)puVar3 + 0xb);
    puVar2[3] = puVar3[3];
    puVar2[4] = puVar3[4];
    *(undefined1 *)(puVar2 + 5) = *(undefined1 *)(puVar3 + 5);
    *(undefined1 *)((int)puVar2 + 0x15) = *(undefined1 *)((int)puVar3 + 0x15);
    puVar6 = puVar6 + 0x18;
    puVar5 = puVar5 + 0x18;
    iVar4 = iVar4 + 4;
    local_c = local_c + -1;
    *(undefined1 *)((int)puVar2 + 0x16) = *(undefined1 *)((int)puVar3 + 0x16);
    puVar2[2] = 0;
  } while (local_c != 0);
  return 0;
}




// ============================================================
// Function: media_packScoreToOldFormat (FUN_680bb3f0)
// Address: 680bb3f0
// Size: 428 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_packScoreToOldFormat(undefined4 *param_1,int param_2)
{
  undefined4 *in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  int local_8;
  
  *in_EAX = *param_1;
  in_EAX[1] = param_1[1];
  *(undefined1 *)(in_EAX + 2) = *(undefined1 *)(param_1 + 2);
  in_EAX[0xc] = param_1[6];
  *(undefined2 *)(in_EAX + 0xd) = *(undefined2 *)(param_1 + 7);
  *(undefined1 *)((int)in_EAX + 0x36) = *(undefined1 *)((int)param_1 + 0x1e);
  *(undefined1 *)((int)in_EAX + 0x37) = *(undefined1 *)((int)param_1 + 0x1f);
  in_EAX[0x18] = param_1[0xc];
  in_EAX[0x19] = param_1[0xd];
  *(undefined1 *)(in_EAX + 0x1a) = *(undefined1 *)(param_1 + 0xe);
  in_EAX[0x24] = param_1[0x12];
  in_EAX[0x25] = param_1[0x13];
  *(undefined1 *)(in_EAX + 0x26) = *(undefined1 *)(param_1 + 0x14);
  in_EAX[0x30] = param_1[0x18];
  in_EAX[0x31] = param_1[0x19];
  *(undefined1 *)(in_EAX + 0x32) = *(undefined1 *)(param_1 + 0x1a);
  in_EAX[0x3c] = param_1[0x1e];
  *(undefined1 *)(in_EAX + 0x3d) = *(undefined1 *)(param_1 + 0x1f);
  *(undefined1 *)((int)in_EAX + 0xf5) = *(undefined1 *)((int)param_1 + 0x7d);
  *(undefined1 *)((int)in_EAX + 0xf6) = *(undefined1 *)((int)param_1 + 0x7e);
  *(undefined1 *)((int)in_EAX + 0xf7) = *(undefined1 *)((int)param_1 + 0x7f);
  *(undefined2 *)(in_EAX + 0x3e) = *(undefined2 *)(param_1 + 0x20);
  *(undefined2 *)((int)in_EAX + 0xfa) = *(undefined2 *)((int)param_1 + 0x82);
  *(undefined1 *)(in_EAX + 0x3f) = *(undefined1 *)(param_1 + 0x21);
  *(undefined1 *)((int)in_EAX + 0xfd) = *(undefined1 *)((int)param_1 + 0x85);
  *(undefined1 *)((int)in_EAX + 0xfe) = *(undefined1 *)((int)param_1 + 0x86);
  *(undefined1 *)((int)in_EAX + 0xff) = *(undefined1 *)((int)param_1 + 0x87);
  in_EAX[0x40] = 0;
  if (0 < param_2) {
    iVar4 = 6;
    puVar3 = in_EAX + 0x48;
    puVar5 = param_1 + 0x24;
    local_8 = param_2;
    do {
      if ((iVar4 < 0) || (puVar2 = puVar5, 0x3ed < iVar4)) {
        puVar2 = (undefined4 *)0x0;
      }
      if ((iVar4 < 0) || (puVar1 = puVar3, 0x3ed < iVar4)) {
        puVar1 = (undefined4 *)0x0;
      }
      *(undefined1 *)puVar1 = *(undefined1 *)puVar2;
      *(undefined1 *)((int)puVar1 + 1) = *(undefined1 *)((int)puVar2 + 1);
      puVar1[1] = puVar2[1];
      *(undefined1 *)((int)puVar1 + 2) = *(undefined1 *)((int)puVar2 + 2);
      *(undefined1 *)((int)puVar1 + 3) = *(undefined1 *)((int)puVar2 + 3);
      puVar1[3] = puVar2[3];
      puVar1[4] = puVar2[4];
      *(byte *)(puVar1 + 5) = *(byte *)(puVar2 + 5) & 0xcf;
      *(undefined1 *)((int)puVar1 + 0x15) = *(undefined1 *)((int)puVar2 + 0x15);
      *(byte *)((int)puVar1 + 0x16) = *(byte *)((int)puVar2 + 0x16) & 0x9f;
      puVar5 = puVar5 + 6;
      puVar3 = puVar3 + 0xc;
      iVar4 = iVar4 + 1;
      local_8 = local_8 + -1;
      puVar1[2] = puVar2[2];
    } while (local_8 != 0);
  }
  return 0;
}



// ============================================================
// Function: media_convertScoreToNewFormat (FUN_680bb5a0)
// Address: 680bb5a0
// Size: 379 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_convertScoreToNewFormat(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  short *psVar3;
  undefined1 *puVar4;
  int iVar5;
  int local_40;
  short local_2e;
  int local_24 [2];
  short *local_1c;
  undefined4 *local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  bVar1 = false;
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  iVar2 = media_getScoreBufferState();
  if ((((-1 < iVar2) && (local_8 = media_getScoreDataSize(), local_8 != 0)) &&
      (local_c = Ordinal_1111(0x5e50,1), local_c != 0)) &&
     ((local_10 = Ordinal_1111(0xbca0,1), local_10 != 0 &&
      (local_14 = Ordinal_1111(0xbca0,1), local_14 != 0)))) {
    local_18 = (undefined4 *)Ordinal_1114(local_c);
    local_1c = (short *)Ordinal_1114(local_10);
    psVar3 = (short *)Ordinal_1114(local_14);
    local_24[0] = 0x14;
    local_24[1] = 0;
    iVar2 = Ordinal_1114(param_1);
    puVar4 = media_getScoreBuffer();
    if (puVar4 < (undefined1 *)(local_40 + iVar2)) {
      do {
        puVar4 = media_getScoreSlotPtr((int)local_18,0x5e50);
        media_packScoreToOldFormat(local_18,(int)local_2e);
        iVar5 = media_getScoreLayout(&local_8,local_24,local_24 + 1,psVar3,local_1c,(int)local_2e,0);
        if (iVar5 == 0) goto LAB_680bb6de;
        media_getScoreVersion(psVar3);
      } while (puVar4 < (undefined1 *)(local_40 + iVar2));
    }
    media_getScoreLayoutSize();
    bVar1 = true;
  }
LAB_680bb6de:
  Ordinal_1113(&local_c);
  Ordinal_1113(&local_10);
  Ordinal_1113(&local_14);
  Ordinal_1113(&param_1);
  if (!bVar1) {
    Ordinal_1113(&local_8);
  }
  return local_8;
}



// ============================================================
// Function: media_getScoreDataRef (FUN_680bb720)
// Address: 680bb720
// Size: 26 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_getScoreDataRef(int param_1)
{
  int iVar1;
  int unaff_ESI;
  int *unaff_EDI;
  
  iVar1 = 0;
  if (0 < param_1) {
    while (*unaff_EDI != *(int *)(unaff_ESI + iVar1 * 8)) {
      iVar1 = iVar1 + 1;
      if (param_1 <= iVar1) {
        return 0;
      }
    }
    *unaff_EDI = *(int *)(unaff_ESI + 4 + iVar1 * 8);
  }
  return 0;
}



// ============================================================
// Function: media_convertScoreWithRefs (FUN_680bb740)
// Address: 680bb740
// Size: 645 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_convertScoreWithRefs(int param_1,undefined4 param_2,int param_3)

{
  bool bVar1;
  short *psVar2;
  int iVar3;
  short *psVar4;
  int iVar5;
  undefined1 *puVar6;
  int iVar7;
  int *piVar8;
  int local_50;
  int local_2c;
  int local_28;
  undefined1 *local_24;
  int local_20;
  uint local_1c;
  int local_18;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  local_18 = 0;
  local_c = 0;
  local_14 = 0;
  local_2c = 0x14;
  local_28 = 0;
  bVar1 = false;
  if (param_1 != 0) {
    local_10 = media_getScoreBufferState();
    if (local_10 < 0) {
      Ordinal_1114(param_1);
    }
    else {
      local_8 = media_getScoreDataSize();
      if ((((local_8 != 0) && (local_18 = Ordinal_1111(0xbca0,1), local_18 != 0)) &&
          (local_c = Ordinal_1111(0xbca0,1), local_c != 0)) &&
         (local_14 = Ordinal_1111(0xbca0,1), local_c != 0)) {
        psVar2 = (short *)Ordinal_1114(local_18);
        iVar3 = Ordinal_1114(local_c);
        psVar4 = (short *)Ordinal_1114(local_14);
        iVar5 = Ordinal_1114(param_1);
        puVar6 = media_getScoreBuffer();
        while (puVar6 < (undefined1 *)(iVar5 + local_50)) {
          local_24 = media_getScoreSlotPtr(iVar3,0xbca0);
          media_getScoreVersion(iVar3);
          if (*(int *)(psVar4 + 2) != 0) {
            media_getScoreDataRef(param_3);
          }
          if (*(int *)(psVar4 + 0x18) != 0) {
            media_getScoreDataRef(param_3);
          }
          if (*(int *)(psVar4 + 0x32) != 0) {
            media_getScoreDataRef(param_3);
          }
          if (*(int *)(psVar4 + 0x4a) != 0) {
            media_getScoreDataRef(param_3);
          }
          if (*(int *)(psVar4 + 0x62) != 0) {
            media_getScoreDataRef(param_3);
          }
          if (*(int *)(psVar4 + 0x80) != 0) {
            media_getScoreDataRef(param_3);
          }
          if (0 < local_10) {
            local_1c = 6;
            piVar8 = (int *)(psVar4 + 0x94);
            local_20 = local_10;
            do {
              if (((local_1c < 0x3ee) && (piVar8 != (int *)0x8)) && (*piVar8 != 0)) {
                media_getScoreDataRef(param_3);
              }
              local_1c = local_1c + 1;
              piVar8 = piVar8 + 0xc;
              local_20 = local_20 + -1;
            } while (local_20 != 0);
            local_20 = 0;
          }
          iVar7 = media_getScoreLayout(&local_8,&local_2c,&local_28,psVar4,psVar2,local_10,0);
          if (iVar7 == 0) goto LAB_680bb969;
          media_getScoreVersion(psVar4);
          puVar6 = local_24;
        }
        media_getScoreLayoutSize();
        bVar1 = true;
      }
    }
  }
LAB_680bb969:
  Ordinal_1115(local_14);
  Ordinal_1113(&local_14);
  Ordinal_1115(local_c);
  Ordinal_1113(&local_c);
  Ordinal_1115(local_18);
  Ordinal_1113(&local_18);
  Ordinal_1115(param_1);
  if ((!bVar1) && (local_8 != 0)) {
    Ordinal_1113(&local_8);
  }
  return local_8;
}



// ============================================================
// Function: media_writeScoreDataLayout (FUN_680bb9d0)
// Address: 680bb9d0
// Size: 384 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_writeScoreDataLayout(int param_1)

{
  bool bVar1;
  int iVar2;
  short *psVar3;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  int local_40;
  int local_24;
  int local_20;
  short *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  bVar1 = false;
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  iVar2 = media_getScoreBufferState();
  if ((((-1 < iVar2) && (local_8 = media_getScoreDataSize(), local_8 != 0)) &&
      (local_c = Ordinal_1111(0xbca0,1), local_c != 0)) &&
     ((local_10 = Ordinal_1111(0xbca0,1), local_10 != 0 &&
      (local_14 = Ordinal_1111(0xbca0,1), local_14 != 0)))) {
    local_1c = (short *)Ordinal_1114(local_c);
    local_18 = Ordinal_1114(local_10);
    psVar3 = (short *)Ordinal_1114(local_14);
    local_24 = 0x14;
    local_20 = 0;
    iVar4 = Ordinal_1114();
    puVar5 = media_getScoreBuffer();
    while (puVar5 < (undefined1 *)(local_40 + iVar4)) {
      puVar5 = media_getScoreSlotPtr(local_18,0xbca0);
      media_getScoreVersion(local_18);
      media_writeScoreChannelData(param_1,iVar2);
      iVar6 = media_getScoreLayout(&local_8,&local_24,&local_20,psVar3,local_1c,iVar2,0);
      if (iVar6 == 0) goto LAB_680bbb1a;
      media_getScoreVersion(psVar3);
    }
    media_getScoreLayoutSize();
    bVar1 = true;
  }
LAB_680bbb1a:
  Ordinal_1113(&local_c);
  Ordinal_1113(&local_10);
  Ordinal_1113(&local_14);
  if (!bVar1) {
    Ordinal_1113(&local_8);
  }
  return local_8;
}



// ============================================================
// Function: media_setScoreChannelRects (FUN_680bbb50)
// Address: 680bbb50
// Size: 274 bytes
// Params: int param_1, short * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setScoreChannelRects(int param_1,short *param_2,int param_3)
{
  short sVar1;
  short *in_EAX;
  short *psVar2;
  int unaff_EBX;
  short *psVar3;
  int iVar4;
  
  if (*in_EAX != 0) {
    sVar1 = xtra_readBE16((undefined1 *)in_EAX);
    rendering_setChannelRect(param_1,param_2,unaff_EBX,sVar1);
  }
  if (in_EAX[0x60] != 0) {
    sVar1 = xtra_readBE16((undefined1 *)(in_EAX + 0x60));
    rendering_setChannelRect(param_1,param_2,unaff_EBX,sVar1);
  }
  if (in_EAX[0x48] != 0) {
    sVar1 = xtra_readBE16((undefined1 *)(in_EAX + 0x48));
    rendering_setChannelRect(param_1,param_2,unaff_EBX,sVar1);
  }
  if (in_EAX[0x78] != 0) {
    sVar1 = xtra_readBE16((undefined1 *)(in_EAX + 0x78));
    rendering_setChannelRect(param_1,param_2,unaff_EBX,sVar1);
  }
  if (in_EAX[0x30] != 0) {
    sVar1 = xtra_readBE16((undefined1 *)(in_EAX + 0x30));
    rendering_setChannelRect(param_1,param_2,unaff_EBX,sVar1);
  }
  if (0 < param_3) {
    iVar4 = 6;
    psVar3 = in_EAX + 0x90;
    do {
      if ((iVar4 < 0) || (psVar2 = psVar3, 0x3ed < iVar4)) {
        psVar2 = (short *)0x0;
      }
      if (psVar2[2] != 0) {
        sVar1 = xtra_readBE16((undefined1 *)(psVar2 + 2));
        rendering_setChannelRect(param_1,param_2,unaff_EBX,sVar1);
      }
      psVar3 = psVar3 + 0x18;
      iVar4 = iVar4 + 1;
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  return 0;
}



// ============================================================
// Function: media_writeScoreRtfRange (FUN_680bbc70)
// Address: 680bbc70
// Size: 23 bytes
// Params: short * param_1, int param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_writeScoreRtfRange(short *param_1,int param_2,undefined4 *param_3)
{
  int in_EAX;
  
  bitmap_writeRtfRange(param_3,param_2,param_1,0,in_EAX,1);
  return 0;
}



// ============================================================
// Function: media_renderScoreToChannel (FUN_680bbc90)
// Address: 680bbc90
// Size: 201 bytes
// Params: undefined4 param_1, int param_2, short * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_renderScoreToChannel(undefined4 param_1,int param_2,short *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined1 *puVar3;
  int iVar4;
  int iVar5;
  int local_24;
  short local_12;
  int local_c;
  undefined2 *local_8;
  
  iVar4 = 0;
  iVar5 = 3;
  local_8 = (undefined2 *)0x0;
  local_c = 0;
  iVar2 = param_2;
  puVar1 = (undefined4 *)rendering_getChannelSprite(*(int *)(*(int *)(param_2 + 4) + 8),*param_3);
  local_8 = rendering_getChannelSlot(puVar1,iVar5,iVar2);
  if ((local_8 != (undefined2 *)0x0) && (local_c = Ordinal_1111(0xbca0,1), local_c != 0)) {
    iVar2 = Ordinal_1114(local_c);
    iVar4 = Ordinal_1114(param_1);
    puVar3 = media_getScoreBuffer();
    while (puVar3 < (undefined1 *)(local_24 + iVar4)) {
      puVar3 = media_getScoreSlotPtr(iVar2,0xbca0);
      media_setScoreChannelRects(param_2,param_3,(int)local_12);
    }
    iVar4 = media_writeScoreDataLayout((int)local_8);
  }
  rendering_processChannelEvent((int *)&local_8);
  Ordinal_1113(&local_c);
  return iVar4;
}




// ============================================================
// Function: media_dispatchScoreRtfWrite (FUN_680bbd60)
// Address: 680bbd60
// Size: 84 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_dispatchScoreRtfWrite(void)

{
  undefined4 *puVar1;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  short *unaff_EDI;
  int iVar2;
  int iVar3;
  undefined2 *local_8;
  
  iVar2 = 3;
  local_8 = (undefined2 *)0x0;
  iVar3 = unaff_ESI;
  puVar1 = (undefined4 *)rendering_getChannelSprite(*(int *)(*(int *)(unaff_ESI + 4) + 8),*unaff_EDI);
  local_8 = rendering_getChannelSlot(puVar1,iVar2,iVar3);
  if (local_8 != (undefined2 *)0x0) {
    media_writeScoreRtfRange(unaff_EDI,unaff_ESI,unaff_EBX);
    bitmap_writeRtfRange(unaff_EBX,unaff_ESI,unaff_EDI,0,(int)local_8,0);
  }
  rendering_processChannelEvent((int *)&local_8);
  return 0;
}



// ============================================================
// Function: media_saveScoreData (FUN_680bbdc0)
// Address: 680bbdc0
// Size: 160 bytes
// Params: int param_1, short * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_saveScoreData(int param_1,short *param_2)

{
  int *in_EAX;
  uint uVar1;
  undefined4 uVar2;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_8 = xtra_readSerializedPtr(in_EAX,0);
  if (local_8 != (undefined4 *)0x0) {
    media_getScoreBufferState();
    uVar1 = Ordinal_1116(local_8);
    if (uVar1 < 0x14) {
      Ordinal_1113(&local_8);
      local_8 = (undefined4 *)media_getScoreDataSize();
      if (local_8 == (undefined4 *)0x0) goto LAB_680bbe41;
    }
    local_c = (undefined4 *)media_renderScoreToChannel(local_8,param_1,param_2);
    if ((local_c != (undefined4 *)0x0) &&
       (uVar2 = xtra_readSerializedValue(in_EAX,0,local_c), (short)uVar2 == 0)) {
      media_dispatchScoreRtfWrite();
    }
  }
LAB_680bbe41:
  Ordinal_1113(&local_8);
  Ordinal_1113(&local_c);
  return 1;
}



// ============================================================
// Function: media_saveScoreData (FUN_680bbdc0)Ex
// Address: 680bbe60
// Size: 178 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_saveScoreDataEx(int *param_1,int param_2)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_8 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_10 = 0;
  local_8 = xtra_readSerializedPtr(param_1,0);
  uVar3 = 0;
  if (local_8 != (undefined4 *)0x0) {
    media_getScoreBufferState();
    uVar1 = Ordinal_1116(local_8);
    uVar3 = local_10;
    if (uVar1 < 0x14) {
      Ordinal_1113(&local_8);
      local_8 = (undefined4 *)media_getScoreDataSize();
      if (local_8 == (undefined4 *)0x0) goto LAB_680bbebf;
    }
    local_c = (undefined4 *)media_writeScoreDataLayout(param_2);
    if ((local_c != (undefined4 *)0x0) &&
       (uVar2 = xtra_readSerializedValue(param_1,0,local_c), (short)uVar2 == 0)) {
      bitmap_writeRtfRange(param_1,0,(short *)0x0,0,param_2,0);
      uVar3 = 1;
    }
  }
LAB_680bbebf:
  Ordinal_1113(&local_c);
  Ordinal_1113(&local_8);
  return uVar3;
}



// ============================================================
// Function: media_resolveScoreChannelIndices (FUN_680bbf20)
// Address: 680bbf20
// Size: 185 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resolveScoreChannelIndices(void)
{
  short sVar1;
  undefined1 *in_EAX;
  undefined1 *puVar2;
  int unaff_EBX;
  int iVar3;
  undefined1 *puVar4;
  int local_8;
  
  sVar1 = xtra_readBE16(in_EAX);
  rendering_getChannelIndex(unaff_EBX,sVar1);
  sVar1 = xtra_readBE16(in_EAX + 0xc0);
  rendering_getChannelIndex(unaff_EBX,sVar1);
  sVar1 = xtra_readBE16(in_EAX + 0x90);
  rendering_getChannelIndex(unaff_EBX,sVar1);
  sVar1 = xtra_readBE16(in_EAX + 0x60);
  rendering_getChannelIndex(unaff_EBX,sVar1);
  sVar1 = xtra_readBE16(in_EAX + 0xf0);
  if (sVar1 != -1) {
    rendering_getChannelIndex(unaff_EBX,sVar1);
  }
  iVar3 = 6;
  puVar4 = in_EAX + 0x120;
  local_8 = 1000;
  do {
    if ((iVar3 < 0) || (puVar2 = puVar4, 0x3ed < iVar3)) {
      puVar2 = (undefined1 *)0x0;
    }
    sVar1 = xtra_readBE16(puVar2 + 4);
    rendering_getChannelIndex(unaff_EBX,sVar1);
    puVar4 = puVar4 + 0x30;
    iVar3 = iVar3 + 1;
    local_8 = local_8 + -1;
  } while (local_8 != 0);
  return 0;
}



// ============================================================
// Function: media_buildScoreChannelMap (FUN_680bbfe0)
// Address: 680bbfe0
// Size: 144 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_buildScoreChannelMap(undefined4 *param_1)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  undefined4 uVar4;
  int local_20;
  int local_8;
  
  uVar4 = 0;
  local_8 = 0;
  local_8 = Ordinal_1111(0xbca0,1);
  if (local_8 != 0) {
    iVar1 = Ordinal_1114(local_8);
    Ordinal_1114(param_1);
    iVar2 = xtra_writeValue(param_1,0);
    puVar3 = media_getScoreBuffer();
    while (puVar3 < (undefined1 *)(iVar2 + local_20)) {
      puVar3 = media_getScoreSlotPtr(iVar1,0xbca0);
      media_resolveScoreChannelIndices();
    }
    Ordinal_1115(param_1);
    uVar4 = 1;
  }
  Ordinal_1113(&local_8);
  return uVar4;
}



// ============================================================
// Function: media_buildScoreChannelMap (FUN_680bbfe0)Ex
// Address: 680bc070
// Size: 56 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_buildScoreChannelMapEx(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  iVar1 = media_buildScoreChannelMap(param_1);
  if (iVar1 != 0) {
    bitmap_writeRtfRange(param_1,0,(short *)0x0,param_2,0,2);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: media_createScoreFromChannel (FUN_680bc0b0)
// Address: 680bc0b0
// Size: 71 bytes
// Params: short * param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall media_createScoreFromChannel(short *param_1)

{
  int in_EAX;
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined2 *local_8;
  
  iVar3 = 4;
  iVar2 = 0;
  local_8 = (undefined2 *)0x0;
  puVar1 = (undefined4 *)rendering_getChannelSprite(*(int *)(*(int *)(in_EAX + 4) + 8),*param_1);
  local_8 = rendering_getChannelSlot(puVar1,iVar3,in_EAX);
  if (local_8 != (undefined2 *)0x0) {
    iVar2 = media_writeScoreDataLayout((int)local_8);
  }
  rendering_processChannelEvent((int *)&local_8);
  return iVar2;
}



// ============================================================
// Function: media_writeScoreToChannel (FUN_680bc100)
// Address: 680bc100
// Size: 79 bytes
// Params: undefined4 * param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_writeScoreToChannel(undefined4 *param_1)

{
  undefined4 *puVar1;
  short *unaff_EBX;
  int unaff_ESI;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined2 *local_8;
  
  iVar3 = 4;
  local_8 = (undefined2 *)0x0;
  iVar4 = unaff_ESI;
  puVar1 = (undefined4 *)rendering_getChannelSprite(*(int *)(*(int *)(unaff_ESI + 4) + 8),*unaff_EBX);
  local_8 = rendering_getChannelSlot(puVar1,iVar3,iVar4);
  bVar2 = local_8 != (undefined2 *)0x0;
  if (bVar2) {
    bitmap_writeRtfRange(param_1,unaff_ESI,unaff_EBX,0,(int)local_8,0);
  }
  rendering_processChannelEvent((int *)&local_8);
  return bVar2;
}



// ============================================================
// Function: media_saveScoreViaChannel (FUN_680bc150)
// Address: 680bc150
// Size: 116 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall media_saveScoreViaChannel(int *param_1)

{
  bool bVar1;
  undefined4 uVar2;
  undefined3 extraout_var;
  short *unaff_EDI;
  undefined4 local_10;
  undefined4 *local_c;
  undefined4 *local_8;
  
  local_10 = 0;
  local_8 = (undefined4 *)0x0;
  local_c = (undefined4 *)0x0;
  local_8 = xtra_readSerializedPtr(param_1,0);
  if (local_8 != (undefined4 *)0x0) {
    local_c = (undefined4 *)media_createScoreFromChannel(unaff_EDI);
    if (local_c != (undefined4 *)0x0) {
      uVar2 = xtra_readSerializedValue(param_1,0,local_c);
      if ((short)uVar2 == 0) {
        bVar1 = media_writeScoreToChannel(param_1);
        uVar2 = 1;
        if (CONCAT31(extraout_var,bVar1) != 0) goto LAB_680bc1aa;
      }
    }
  }
  uVar2 = local_10;
LAB_680bc1aa:
  Ordinal_1113(&local_8);
  Ordinal_1113(&local_c);
  return uVar2;
}



// ============================================================
// Function: media_markScoreSlotChanged (FUN_680bc1d0)
// Address: 680bc1d0
// Size: 35 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_markScoreSlotChanged(int param_1)
{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x898 + param_1) == '\0') {
    *(char *)(in_EAX + 0xc86) = *(char *)(in_EAX + 0xc86) + '\x01';
    *(undefined1 *)(in_EAX + 0x898 + param_1) = 1;
    return 0;
  }
  *(undefined1 *)(in_EAX + 0x898 + param_1) = 1;
  return 0;
}



// ============================================================
// Function: media_unmarkScoreSlotChanged (FUN_680bc200)
// Address: 680bc200
// Size: 25 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_unmarkScoreSlotChanged(int param_1)
{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0x898 + param_1) == '\x01') {
    *(char *)(in_EAX + 0xc86) = *(char *)(in_EAX + 0xc86) + -1;
  }
  *(undefined1 *)(in_EAX + 0x898 + param_1) = 0;
  return 0;
}



// ============================================================
// Function: media_isScoreSlotChanged (FUN_680bc220)
// Address: 680bc220
// Size: 14 bytes
// Params: int param_1, int param_2
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall media_isScoreSlotChanged(int param_1,int param_2)

{
  return *(char *)(param_2 + 0x898 + param_1) == '\x01';
}



// ============================================================
// Function: media_markScoreSlotModified (FUN_680bc230)
// Address: 680bc230
// Size: 35 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_markScoreSlotModified(int param_1)
{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0xc87 + param_1) == '\0') {
    *(char *)(in_EAX + 0x1075) = *(char *)(in_EAX + 0x1075) + '\x01';
    *(undefined1 *)(in_EAX + 0xc87 + param_1) = 1;
    return 0;
  }
  *(undefined1 *)(in_EAX + 0xc87 + param_1) = 1;
  return 0;
}



// ============================================================
// Function: media_unmarkScoreSlotModified (FUN_680bc260)
// Address: 680bc260
// Size: 25 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_unmarkScoreSlotModified(int param_1)
{
  int in_EAX;
  
  if (*(char *)(in_EAX + 0xc87 + param_1) == '\x01') {
    *(char *)(in_EAX + 0x1075) = *(char *)(in_EAX + 0x1075) + -1;
  }
  *(undefined1 *)(in_EAX + 0xc87 + param_1) = 0;
  return 0;
}



// ============================================================
// Function: media_isScoreSlotModified (FUN_680bc280)
// Address: 680bc280
// Size: 14 bytes
// Params: int param_1, int param_2
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall media_isScoreSlotModified(int param_1,int param_2)

{
  return *(char *)(param_2 + 0xc87 + param_1) == '\x01';
}



// ============================================================
// Function: media_hasModifiedScoreSlots (FUN_680bc290)
// Address: 680bc290
// Size: 12 bytes
// Params: int param_1
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall media_hasModifiedScoreSlots(int param_1)

{
  return *(char *)(param_1 + 0x1075) != '\0';
}




// ============================================================
// Function: media_hasChangedScoreSlots (FUN_680bc2a0)
// Address: 680bc2a0
// Size: 12 bytes
// Params: int param_1
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall media_hasChangedScoreSlots(int param_1)

{
  return *(char *)(param_1 + 0xc86) != '\0';
}



// ============================================================
// Function: media_compareScoreFrameRange (FUN_680bc2b0)
// Address: 680bc2b0
// Size: 67 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall media_compareScoreFrameRange(int param_1,int param_2)

{
  int in_EAX;
  int unaff_ESI;
  
  if (((in_EAX <= param_1) || (in_EAX <= param_2)) && (param_1 <= unaff_ESI)) {
    if ((param_1 == in_EAX) && (param_2 == unaff_ESI)) {
      return 1;
    }
    if (in_EAX <= param_1) {
      return 2;
    }
    if ((in_EAX <= param_2) && (param_2 <= unaff_ESI)) {
      return 3;
    }
    if ((param_1 < in_EAX) && (unaff_ESI < param_2)) {
      return 5;
    }
  }
  return 0;
}



// ============================================================
// Function: media_extractScoreChannelProps (FUN_680bc300)
// Address: 680bc300
// Size: 311 bytes
// Params: char * param_1, undefined4 param_2, undefined4 * param_3, undefined4 * param_4, int * param_5, undefined4 * param_6, undefined4 * param_7
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
media_extractScoreChannelProps(char *param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4,int *param_5,
            undefined4 *param_6,undefined4 *param_7)
{
  undefined2 uVar1;
  char *in_EAX;
  undefined4 uVar2;
  
  switch(param_2) {
  case 0:
    *param_5 = (int)(param_1 + 4);
    *param_7 = *(undefined4 *)param_1;
    *param_3 = *(undefined4 *)(in_EAX + 4);
    *param_6 = *(undefined4 *)in_EAX;
    break;
  case 1:
    *param_3 = *(undefined4 *)in_EAX;
    *param_5 = (int)param_1;
    if ((in_EAX[6] == -10) && (*(short *)(in_EAX + 4) == 0)) {
      *param_6 = 0;
    }
    else {
      *(undefined2 *)param_6 = *(undefined2 *)(in_EAX + 4);
      *(short *)((int)param_6 + 2) = (short)in_EAX[6];
    }
    if ((param_1[6] == -10) && (*(short *)(param_1 + 4) == 0)) {
      *param_7 = 0;
    }
    else {
      *(undefined2 *)param_7 = *(undefined2 *)(param_1 + 4);
      *(short *)((int)param_7 + 2) = (short)param_1[6];
    }
    break;
  case 2:
  case 3:
  case 4:
    *param_3 = *(undefined4 *)(in_EAX + 4);
    *param_5 = (int)(param_1 + 4);
    *param_6 = *(undefined4 *)in_EAX;
    *param_7 = *(undefined4 *)param_1;
    break;
  case 5:
    *param_3 = *(undefined4 *)(in_EAX + 0x10);
    *param_5 = (int)(param_1 + 0x10);
    *param_6 = *(undefined4 *)in_EAX;
    *param_7 = *(undefined4 *)param_1;
    break;
  default:
    *param_3 = *(undefined4 *)(in_EAX + 8);
    *param_5 = (int)(param_1 + 8);
    *param_6 = *(undefined4 *)(in_EAX + 4);
    *param_7 = *(undefined4 *)(param_1 + 4);
    if (*in_EAX == '\0') {
      in_EAX[4] = '\0';
      in_EAX[5] = '\0';
      in_EAX[6] = '\0';
      in_EAX[7] = '\0';
    }
    if (*param_1 == '\0') {
      param_1[4] = '\0';
      param_1[5] = '\0';
      param_1[6] = '\0';
      param_1[7] = '\0';
    }
  }
  uVar2 = xtra_readBE32Ptr((undefined1 *)*param_5);
  *param_4 = uVar2;
  uVar2 = xtra_readBE32Ptr((undefined1 *)param_3);
  *param_3 = uVar2;
  uVar1 = xtra_readBE16((undefined1 *)param_7);
  *(undefined2 *)param_7 = uVar1;
  uVar1 = xtra_readBE16((undefined1 *)((int)param_7 + 2));
  *(undefined2 *)((int)param_7 + 2) = uVar1;
  uVar1 = xtra_readBE16((undefined1 *)param_6);
  *(undefined2 *)param_6 = uVar1;
  uVar1 = xtra_readBE16((undefined1 *)((int)param_6 + 2));
  *(undefined2 *)((int)param_6 + 2) = uVar1;
  return 0;
}



// ============================================================
// Function: media_readScoreBlock (FUN_680bc450)
// Address: 680bc450
// Size: 429 bytes
// Params: int param_1, uint param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_readScoreBlock(int param_1,uint param_2)

{
  int *piVar1;
  bool bVar2;
  undefined4 uVar3;
  int iVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  char *pcVar5;
  undefined4 extraout_ECX;
  int iVar6;
  undefined4 local_24;
  int local_20;
  int local_1c;
  undefined4 local_18;
  int local_14;
  uint local_10;
  undefined4 *local_c;
  int local_8;
  
  iVar6 = *(int *)(param_1 + 0x1078) + *(int *)(param_1 + 0x70);
  piVar1 = *(int **)(param_1 + 0x18);
  local_10 = 1;
  if (*(int *)(param_1 + 0x87c) == 0) {
    return 1;
  }
  if (param_2 < 0x3ee) {
    pcVar5 = (char *)(param_2 * 0x30 + *(int *)(param_1 + 0x54));
  }
  else {
    pcVar5 = (char *)0x0;
  }
  media_extractScoreChannelProps(pcVar5,param_2,&local_14,&local_8,(int *)&local_c,&local_24,&local_18);
  iVar4 = local_8;
  if (local_8 != 0) {
    local_1c = bitmap_readRtfHeader(piVar1,local_8);
    local_20 = bitmap_readRtfValue(piVar1,iVar4);
    if ((*(unsigned short *)((char *)&local_18 + 2)) == 0) {
      uVar3 = media_compareScoreFrameRange(local_1c,local_20);
      switch(uVar3) {
      case 1:
        bitmap_getRtfByte(piVar1,local_8);
        *local_c = 0;
        return local_10;
      case 2:
        bitmap_readRtfSection(piVar1,local_8,1);
        *local_c = 0;
        return local_10;
      case 3:
        bitmap_isRtfValid(piVar1,local_8,iVar6 + -1);
        *local_c = 0;
        return local_10;
      case 5:
        media_markScoreSlotChanged(param_2);
        local_14 = local_8;
        *local_c = 0;
        iVar4 = bitmap_writeRtfChunk(piVar1,extraout_ECX,iVar6 + 1);
        if (iVar4 == 0) {
          return (uint)(DAT_68195a8c == 0);
        }
        bVar2 = bitmap_isRtfValid(piVar1,local_14,iVar6 + -1);
        local_10 = CONCAT31(extraout_var,bVar2);
        if ((local_10 != 0) &&
           (local_10 = bitmap_readRtfRange(piVar1,local_14,piVar1,iVar4), local_10 != 0)) {
          bVar2 = bitmap_isRtfValid(piVar1,iVar4,local_20);
          local_10 = CONCAT31(extraout_var_00,bVar2);
        }
      }
    }
    return local_10;
  }
  return 1;
}



// ============================================================
// Function: media_readScoreRange (FUN_680bc620)
// Address: 680bc620
// Size: 513 bytes
// Params: int param_1, undefined4 param_2, int param_3, int param_4, int param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_readScoreRange(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  byte bVar1;
  bool bVar2;
  char *in_EAX;
  int iVar3;
  undefined3 extraout_var;
  uint uVar4;
  int *unaff_EBX;
  char *unaff_ESI;
  undefined1 *local_20;
  int local_1c;
  undefined2 local_18;
  undefined2 local_16;
  short local_14;
  short local_12;
  short local_10;
  short local_e;
  int local_c;
  uint local_8;
  
  local_8 = 1;
  uVar4 = 1;
  if (unaff_EBX != (int *)0x0) {
    media_extractScoreChannelProps(unaff_ESI,param_3,&local_c,&local_1c,(int *)&local_20,(undefined4 *)&local_14,
                 (undefined4 *)&local_10);
    bitmap_readRtfPair(unaff_EBX,local_c,0,(undefined4 *)&local_18);
    if (local_e == 0) {
      return 1;
    }
    if (((local_10 == local_14) && (local_e == local_12)) &&
       (param_2 == CONCAT22(local_16,local_18))) {
      xtra_skipBytes(local_20);
      local_1c = local_c;
      bitmap_isRtfValid(unaff_EBX,local_c,param_4);
      uVar4 = local_8;
      if ((5 < param_3) && ((~((byte)unaff_ESI[0x16] >> 7) & 1) != 0)) {
        if (((((param_5 == 0) &&
              (((*(short *)(unaff_ESI + 4) == *(short *)(in_EAX + 4) &&
                (*(short *)(unaff_ESI + 6) == *(short *)(in_EAX + 6))) && (*unaff_ESI == *in_EAX))))
             && (((*(short *)(unaff_ESI + 0xc) == *(short *)(in_EAX + 0xc) &&
                  (*(short *)(unaff_ESI + 0xe) == *(short *)(in_EAX + 0xe))) &&
                 (*(short *)(unaff_ESI + 0x10) == *(short *)(in_EAX + 0x10))))) &&
            ((*(short *)(unaff_ESI + 0x12) == *(short *)(in_EAX + 0x12) &&
             (unaff_ESI[1] == in_EAX[1])))) &&
           ((unaff_ESI[2] == in_EAX[2] &&
            ((((unaff_ESI[3] == in_EAX[3] && (unaff_ESI[0x14] == in_EAX[0x14])) &&
              (unaff_ESI[0x15] == in_EAX[0x15])) &&
             (bVar1 = unaff_ESI[0x16] | 0x80, bVar1 == (byte)(in_EAX[0x16] | 0x80U))))))) {
          unaff_ESI[0x16] = bVar1;
          return local_8;
        }
        iVar3 = bitmap_readRtfHeader(unaff_EBX,local_1c);
        bitmap_validateRtfRange(unaff_EBX,local_c,param_4 - iVar3);
        return local_8;
      }
    }
    else {
      iVar3 = bitmap_writeRtfChunk(unaff_EBX,param_3,param_4);
      if (iVar3 == 0) {
        local_8 = (uint)(DAT_68195a8c == 0);
      }
      xtra_skipBytes(local_20);
      if (5 < param_3) {
        unaff_ESI[0x16] = unaff_ESI[0x16] & 0x7f;
        if (local_8 == 0) {
          return 0;
        }
        if (*(int *)(unaff_ESI + 8) != 0) {
          bitmap_resetRtfDefaults(unaff_EBX,iVar3);
        }
      }
      uVar4 = 0;
      if (local_8 != 0) {
        bVar2 = bitmap_isRtfValid(unaff_EBX,iVar3,param_4);
        uVar4 = CONCAT31(extraout_var,bVar2);
        if ((uVar4 != 0) && ((*(unsigned short *)((char *)&param_2 + 2)) != 0)) {
          local_8 = uVar4;
          uVar4 = bitmap_setRtfValue(unaff_EBX,iVar3,param_1,param_2);
        }
      }
    }
  }
  return uVar4;
}



// ============================================================
// Function: media_processChangedScoreSlots (FUN_680bc830)
// Address: 680bc830
// Size: 288 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_processChangedScoreSlots(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  int iVar4;
  undefined3 extraout_var_01;
  uint uVar5;
  undefined1 *puVar6;
  
  iVar2 = *(int *)(param_1 + 0x1078) + *(int *)(param_1 + 0x70);
  if ((*(int *)(param_1 + 0x87c) != 0) &&
     (bVar1 = media_hasChangedScoreSlots(param_1), CONCAT31(extraout_var,bVar1) != 0)) {
    uVar5 = 0;
    iVar4 = param_1;
    do {
      bVar1 = media_isScoreSlotChanged(uVar5,iVar4);
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        if (uVar5 < 0x3ee) {
          puVar6 = (undefined1 *)(uVar5 * 0x30 + *(int *)(iVar4 + 0x54));
        }
        else {
          puVar6 = (undefined1 *)0x0;
        }
        iVar3 = bitmap_findRtfByRange(*(undefined4 **)(iVar4 + 0x18),iVar2,iVar2,uVar5,uVar5);
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = bitmap_readRtfInt(*(undefined4 **)(iVar4 + 0x18),iVar3);
        }
        switch(uVar5) {
        case 0:
        case 2:
        case 3:
        case 4:
          xtra_skipBytes(puVar6 + 4);
          break;
        case 1:
          xtra_skipBytes(puVar6);
          break;
        case 5:
          xtra_skipBytes(puVar6 + 0x10);
          break;
        default:
          xtra_skipBytes(puVar6 + 8);
          iVar4 = bitmap_readRtfHeader(*(undefined4 **)(param_1 + 0x18),iVar3);
          if (iVar4 == iVar2) {
            puVar6[0x16] = puVar6[0x16] & 0x7f;
          }
        }
        iVar4 = param_1;
        if ((iVar3 != 0) &&
           (iVar3 = bitmap_readRtfValue(*(undefined4 **)(param_1 + 0x18),iVar3), iVar3 == iVar2)) {
          iVar4 = media_unmarkScoreSlotChanged(uVar5);
        }
      }
      uVar5 = uVar5 + 1;
    } while ((int)uVar5 < 0x3ee);
    bVar1 = media_hasChangedScoreSlots(iVar4);
    return (bool)('\x01' - (CONCAT31(extraout_var_01,bVar1) != 0));
  }
  return true;
}



// ============================================================
// Function: media_commitModifiedScoreSlot (FUN_680bc970)
// Address: 680bc970
// Size: 344 bytes
// Params: uint param_1, undefined4 param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_commitModifiedScoreSlot(uint param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  undefined2 uVar4;
  undefined2 uVar5;
  undefined3 extraout_var;
  uint uVar6;
  int *piVar7;
  int unaff_EDI;
  undefined4 local_14;
  uint local_c;
  int local_8;
  
  local_c = 1;
  bVar3 = media_isScoreSlotModified(param_1,unaff_EDI);
  if (CONCAT31(extraout_var,bVar3) == 0) {
    return 1;
  }
  if (param_1 < 0x3ee) {
    piVar7 = (int *)(param_1 * 0x30 + *(int *)(unaff_EDI + 0x54));
  }
  else {
    piVar7 = (int *)0x0;
  }
  iVar1 = *(int *)(*(int *)(**(int **)(unaff_EDI + 8) + 0x18) + 0xc);
  switch(param_1) {
  case 0:
    local_8 = piVar7[1];
    goto LAB_680bca68;
  case 1:
    local_8 = *piVar7;
    break;
  case 2:
  case 3:
    local_8 = piVar7[1];
    break;
  case 4:
    local_8 = piVar7[1];
    break;
  case 5:
    local_8 = piVar7[4];
    break;
  default:
    local_8 = piVar7[2];
    if (param_1 != 0) break;
LAB_680bca68:
    uVar4 = xtra_readBE16((undefined1 *)piVar7);
    uVar5 = xtra_readBE16((undefined1 *)((int)piVar7 + 2));
    local_14 = CONCAT22(uVar5,uVar4);
    goto LAB_680bc9f9;
  }
  local_14 = param_2;
LAB_680bc9f9:
  if (local_8 != 0) {
    if (param_1 == 0) {
      iVar2 = *piVar7;
      *piVar7 = 0;
      local_c = media_readScoreBlock(unaff_EDI,0);
      local_8 = piVar7[1];
      *piVar7 = iVar2;
    }
    if (local_8 != 0) {
      uVar6 = media_readScoreBlock(unaff_EDI,param_1);
      media_unmarkScoreSlotModified(param_1);
      return local_c & uVar6;
    }
  }
  uVar6 = media_readScoreRange(iVar1,local_14,param_1,
                       *(int *)(unaff_EDI + 0x1078) + *(int *)(unaff_EDI + 0x70),1);
  media_unmarkScoreSlotModified(param_1);
  return local_c & uVar6;
}



