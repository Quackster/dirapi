// Module: media_playback
// Topic: Score state management, channel tracking, frame navigation, and playback control
// Address range: 0x680BCAE0 - 0x680BFC40
// Functions (86):
//   media_validateScoreChannels
//   media_removeScoreFrame
//   media_insertScoreFrame
//   media_initScoreBlocks
//   media_addScoreRef
//   media_lockScoreData
//   media_unlockScoreData
//   media_refreshScoreFormat
//   media_refreshScoreVersion
//   media_isScoreLocked
//   media_getScoreState
//   media_getScoreReadRef
//   media_setScoreReadRef
//   media_getScoreCompositeRef
//   media_isScoreReady
//   media_getScoreVersionInfo
//   media_getScoreHandle
//   media_getScoreReadState
//   media_getScoreContext
//   media_setScoreContext
//   media_getScoreChannelByte
//   media_writeScoreBlockEx
//   media_copyScoreData
//   media_writeScoreBlock
//   media_validateScoreFrameData
//   media_getScoreSlotFlags
//   media_getScoreSlotRef2
//   media_setScoreSlot
//   media_getScoreStatePtr
//   media_isScoreBufferValid
//   media_getVtableFunc (media_getVtableFunc)
//   media_copyScoreState
//   media_loadScoreData
//   media_deleteScoreFrame
//   media_insertScoreFrameEx
//   media_incrementEditCount
//   media_resetScoreBlocks
//   media_setScorePosition
//   media_isScoreWritable
//   media_isScoreModified
//   media_releaseScoreData
//   media_setScoreChannelRef
//   media_setScorePositionEx
//   media_resolveScoreSprite
//   media_mergeScoreEntries
//   media_updateScoreProperty
//   media_getPlaybackRef
//   media_isScoreSizeValid
//   media_getPlaybackFlags
//   media_getPlaybackState
//   media_isPlaybackReady
//   media_seekPlaybackFrame
//   media_getScoreFlags
//   media_buildPlaybackIndex
//   media_advancePlaybackChunk
//   media_scanPlaybackToEnd
//   media_countPlaybackFrames
//   media_getPlaybackData
//   media_initPlayback
//   media_processPlayback
//   media_processPlaybackEx
//   media_stepPlayback
//   media_processPlaybackBlock
//   media_advancePlaybackFrames
//   media_editScoreFrames
//   media_readScoreChannels
//   media_buildScoreLayout
//   media_convertScoreData
//   media_writePlaybackChannel
//   media_writePlaybackData
//   media_getScorePlayState
//   media_getPlaybackPosition
//   media_isPlaybackActive
//   media_readPlaybackData
//   media_setScoreTempo
//   media_setScoreChannelCount
//   media_getPlaybackByte
//   media_cloneScoreState
//   media_readPlaybackBlock
//   media_readPlaybackBlockEx
//   media_stepPlaybackLocked
//   media_applyScoreEdit
//   media_loadScoreResource
//   media_readPlaybackEntry
//   media_compareScoreChannelData
//   media_readPlaybackField

// ============================================================
// Function: media_validateScoreChannels (FUN_680bcae0)
// Address: 680bcae0
// Size: 75 bytes
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_validateScoreChannels(void)

{
  bool bVar1;
  int in_EAX;
  undefined3 extraout_var;
  uint uVar2;
  uint uVar3;
  
  if ((*(int *)(in_EAX + 0x87c) != 0) &&
     (bVar1 = media_hasModifiedScoreSlots(in_EAX), CONCAT31(extraout_var,bVar1) != 0)) {
    uVar3 = 0;
    do {
      uVar2 = media_commitModifiedScoreSlot(uVar3,0);
      if (uVar2 == 0) {
        return 0;
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 < 0x3ee);
    return uVar2;
  }
  return 1;
}



// ============================================================
// Function: media_removeScoreFrame (FUN_680bcb30)
// Address: 680bcb30
// Size: 188 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_removeScoreFrame(void)
{
  int *piVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint local_c;
  int local_8;
  
  piVar1 = *(int **)(in_EAX + 0x18);
  iVar6 = *(int *)(in_EAX + 0x1078);
  iVar2 = *(int *)(in_EAX + 0x70);
  memset((void *)(in_EAX + 0xc87),0,0x3ee);
  local_c = bitmap_getRtfData(piVar1);
  local_8 = 1;
  if (0 < (int)local_c) {
    iVar6 = iVar6 + iVar2 + -1;
    do {
      iVar2 = bitmap_readRtfInt(piVar1,local_8);
      iVar3 = bitmap_readRtfHeader(piVar1,iVar2);
      iVar4 = bitmap_readRtfValue(piVar1,iVar2);
      if (iVar6 <= iVar4) {
        if ((iVar3 == iVar6) && (iVar3 == iVar4)) {
          bitmap_getRtfByte(piVar1,iVar2);
          local_c = local_c - 1;
          local_8 = local_8 + -1;
        }
        else {
          if (iVar6 < iVar3) {
            iVar5 = bitmap_readRtfBlock(piVar1,iVar2);
            bitmap_setRtfProperty(piVar1,iVar2,iVar3 + -1,iVar5);
          }
          bitmap_isRtfValid(piVar1,iVar2,iVar4 + -1);
        }
      }
      local_8 = local_8 + 1;
    } while (local_8 <= (int)local_c);
  }
  return 0;
}



// ============================================================
// Function: media_insertScoreFrame (FUN_680bcbf0)
// Address: 680bcbf0
// Size: 115 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_insertScoreFrame(void)
{
  int *piVar1;
  int in_EAX;
  uint uVar2;
  int iVar3;
  int local_14;
  short local_10 [2];
  int local_c;
  int local_8;
  
  local_8 = *(int *)(in_EAX + 0x1078) + *(int *)(in_EAX + 0x70);
  piVar1 = *(int **)(in_EAX + 0x18);
  for (uVar2 = bitmap_getRtfData(piVar1); 0 < (int)uVar2; uVar2 = uVar2 - 1) {
    iVar3 = bitmap_readRtfInt(piVar1,uVar2);
    bitmap_getRtfNodeData(piVar1,iVar3,&local_c,&local_14,(undefined4 *)local_10);
    if (local_8 < local_c) {
      bitmap_setRtfProperty(piVar1,iVar3,local_c + 1,(int)local_10[0]);
    }
    if (local_8 <= local_14) {
      bitmap_isRtfValid(piVar1,iVar3,local_14 + 1);
    }
  }
  return 0;
}



// ============================================================
// Function: media_initScoreBlocks (FUN_680bcc70)
// Address: 680bcc70
// Size: 180 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_initScoreBlocks(void)
{
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  undefined4 local_c;
  undefined4 local_8;
  
  **(undefined4 **)(unaff_ESI + 0x54) = 0;
  media_readScoreBlock(unaff_ESI,0);
  iVar1 = *(int *)(unaff_ESI + 0x54);
  *(undefined1 *)(iVar1 + 0x36) = 0;
  *(undefined2 *)(iVar1 + 0x34) = 0;
  media_readScoreBlock(unaff_ESI,1);
  *(undefined4 *)(*(int *)(unaff_ESI + 0x54) + 0x60) = 0;
  media_readScoreBlock(unaff_ESI,2);
  *(undefined4 *)(*(int *)(unaff_ESI + 0x54) + 0x90) = 0;
  media_readScoreBlock(unaff_ESI,3);
  *(undefined4 *)(*(int *)(unaff_ESI + 0x54) + 0xc0) = 0;
  media_readScoreBlock(unaff_ESI,4);
  *(undefined4 *)(*(int *)(unaff_ESI + 0x54) + 0xf0) = 0;
  media_readScoreBlock(unaff_ESI,5);
  uVar2 = 6;
  local_8 = 0x120;
  local_c = 1000;
  do {
    if (((int)uVar2 < 0) || (0x3ed < (int)uVar2)) {
      iVar1 = 0;
    }
    else {
      iVar1 = *(int *)(unaff_ESI + 0x54) + local_8;
    }
    *(undefined4 *)(iVar1 + 4) = 0;
    media_readScoreBlock(unaff_ESI,uVar2);
    local_8 = local_8 + 0x30;
    uVar2 = uVar2 + 1;
    local_c = local_c + -1;
  } while (local_c != 0);
  return 0;
}



// ============================================================
// Function: media_addScoreRef (FUN_680bcd30)
// Address: 680bcd30
// Size: 18 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_addScoreRef(undefined4 *param_1)
{
  if (param_1 != (undefined4 *)0x0) {
    *(int *)*param_1 = *(int *)*param_1 + 1;
  }
  return 0;
}



// ============================================================
// Function: media_lockScoreData (FUN_680bcd50)
// Address: 680bcd50
// Size: 78 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_lockScoreData(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != (int *)0x0) {
    *(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) + 1;
    iVar1 = *param_1;
    if (*(int *)(iVar1 + 4) == 1) {
      iVar1 = Ordinal_1114(param_1);
      media_getScoreFrameData();
    }
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(iVar1 + 0x54);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(iVar1 + 100);
    }
    iVar1 = *(int *)(iVar1 + 0x40) + -6;
  }
  return iVar1;
}



// ============================================================
// Function: media_unlockScoreData (FUN_680bcda0)
// Address: 680bcda0
// Size: 68 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_unlockScoreData(int *param_1,undefined4 *param_2,undefined4 *param_3)
{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = 0;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 0;
  }
  if ((param_1 != (int *)0x0) &&
     (*(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) + -1, *(int *)(*param_1 + 4) == 0)) {
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_refreshScoreFormat (FUN_680bcdf0)
// Address: 680bcdf0
// Size: 54 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_refreshScoreFormat(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    media_getScoreFormat(*(undefined4 *)(iVar1 + 0x54));
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_refreshScoreVersion (FUN_680bce30)
// Address: 680bce30
// Size: 63 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_refreshScoreVersion(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    media_getScoreVersion(*(undefined4 *)(iVar1 + 0x54));
    *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(iVar1 + 0x70);
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_isScoreLocked (FUN_680bce70)
// Address: 680bce70
// Size: 25 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_isScoreLocked(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *(undefined4 *)(*param_1 + 0x38);
  }
  return 0;
}



// ============================================================
// Function: media_getScoreState (FUN_680bce90)
// Address: 680bce90
// Size: 25 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreState(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *(undefined4 *)(*param_1 + 0x70);
  }
  return 0;
}



// ============================================================
// Function: media_getScoreReadRef (FUN_680bceb0)
// Address: 680bceb0
// Size: 50 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreReadRef(int *param_1,undefined4 *param_2)

{
  if (param_1 != (int *)0x0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(*param_1 + 0x7c);
    }
    return *(undefined4 *)(*param_1 + 0x78);
  }
  return 0;
}



// ============================================================
// Function: media_setScoreReadRef (FUN_680bcef0)
// Address: 680bcef0
// Size: 54 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setScoreReadRef(int param_1,undefined4 param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(iVar1 + 0x78);
    *(undefined4 *)(iVar1 + 0x78) = param_2;
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_getScoreCompositeRef (FUN_680bcf30)
// Address: 680bcf30
// Size: 29 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreCompositeRef(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + 0x80));
  }
  return 0;
}



// ============================================================
// Function: media_isScoreReady (FUN_680bcf50)
// Address: 680bcf50
// Size: 25 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_isScoreReady(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *(undefined4 *)(*param_1 + 0x3c);
  }
  return 0;
}



// ============================================================
// Function: media_getScoreVersionInfo (FUN_680bcf70)
// Address: 680bcf70
// Size: 42 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getScoreVersionInfo(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = media_getScoreVersion2();
    iVar1 = media_getScoreChannelCount(iVar1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: media_getScoreHandle (FUN_680bcfa0)
// Address: 680bcfa0
// Size: 28 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreHandle(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *(undefined4 *)(*param_1 + 0x87c);
  }
  return 0;
}




// ============================================================
// Function: media_getScoreReadState (FUN_680bcfc0)
// Address: 680bcfc0
// Size: 40 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreReadState(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  if (param_1 != (int *)0x0) {
    uVar1 = rendering_getChannelProperty(*(int *)(*param_1 + 0x878),param_2,(undefined4 *)0x0);
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: media_getScoreContext (FUN_680bcff0)
// Address: 680bcff0
// Size: 28 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreContext(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *(undefined4 *)(*param_1 + 0x874);
  }
  return 0;
}



// ============================================================
// Function: media_setScoreContext (FUN_680bd010)
// Address: 680bd010
// Size: 25 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setScoreContext(int *param_1,undefined4 param_2)
{
  if (param_1 != (int *)0x0) {
    *(undefined4 *)(*param_1 + 0x874) = param_2;
  }
  return 0;
}



// ============================================================
// Function: media_getScoreChannelByte (FUN_680bd030)
// Address: 680bd030
// Size: 33 bytes
// Params: int * param_1, int param_2
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 media_getScoreChannelByte(int *param_1,int param_2)

{
  if (param_1 != (int *)0x0) {
    return *(undefined1 *)(*param_1 + 0x9c + param_2);
  }
  return 0;
}



// ============================================================
// Function: media_writeScoreBlockEx (FUN_680bd060)
// Address: 680bd060
// Size: 44 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeScoreBlockEx(int *param_1,int param_2,int param_3)
{
  if ((param_1 != (int *)0x0) &&
     (*(char *)(*param_1 + 0x9c + param_2) = (char)param_3, param_3 == 0)) {
    media_copyScoreSlot();
  }
  return 0;
}



// ============================================================
// Function: media_copyScoreData (FUN_680bd090)
// Address: 680bd090
// Size: 88 bytes
// Params: int * param_1, int param_2, int param_3, size_t param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_copyScoreData(int *param_1,int param_2,int param_3,size_t param_4)
{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = param_2 + 6;
    if ((iVar1 < 0) || (0x3ed < iVar1)) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 * 0x30 + *(int *)(*param_1 + 0x8c);
    }
    if (0 < (int)param_4) {
      memset((void *)(iVar1 + param_3),0xff,param_4);
    }
    *(undefined1 *)(*param_1 + 0x484 + param_2) = 1;
  }
  return 0;
}



// ============================================================
// Function: media_writeScoreBlock (FUN_680bd0f0)
// Address: 680bd0f0
// Size: 69 bytes
// Params: int * param_1, int param_2, int param_3, byte param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_writeScoreBlock(int *param_1,int param_2,int param_3,byte param_4)
{
  int iVar1;
  
  if (param_1 != (int *)0x0) {
    iVar1 = param_2 + 6;
    if ((iVar1 < 0) || (0x3ed < iVar1)) {
      iVar1 = 0;
    }
    else {
      iVar1 = iVar1 * 0x30 + *(int *)(*param_1 + 0x8c);
    }
    *(byte *)(iVar1 + param_3) = *(byte *)(iVar1 + param_3) | param_4;
    *(undefined1 *)(*param_1 + 0x484 + param_2) = 1;
  }
  return 0;
}



// ============================================================
// Function: media_validateScoreFrameData (FUN_680bd140)
// Address: 680bd140
// Size: 227 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_validateScoreFrameData(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int local_8;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    if (0 < *(int *)(iVar1 + 0x3c)) {
      local_8 = 0x120;
      iVar4 = 6;
      do {
        if (*(char *)(iVar1 + 0x47e + iVar4) != '\0') {
          if ((iVar4 < 0) || (0x3ed < iVar4)) {
            iVar2 = 0;
          }
          else {
            iVar2 = *(int *)(iVar1 + 0x54) + local_8;
          }
          iVar2 = xtra_readBE32Ptr((undefined1 *)(iVar2 + 8));
          if (iVar2 == 0) {
            if (((*(char *)(iVar4 + 0x96 + iVar1) == '\0') &&
                (iVar2 = bitmap_findRtfByRange(*(undefined4 **)(iVar1 + 0x18),param_2,param_2,iVar4,iVar4),
                0 < iVar2)) &&
               (iVar2 = bitmap_readRtfInt(*(undefined4 **)(iVar1 + 0x18),iVar2), iVar2 != 0))
            goto LAB_680bd1f6;
          }
          else {
            iVar3 = bitmap_readRtfValue(*(undefined4 **)(iVar1 + 0x18),iVar2);
            if ((iVar3 < param_2) ||
               (iVar2 = bitmap_readRtfHeader(*(undefined4 **)(iVar1 + 0x18),iVar2), param_2 < iVar2)) {
LAB_680bd1f6:
              media_copyScoreSlot();
            }
          }
        }
        local_8 = local_8 + 0x30;
        iVar2 = iVar4 + -5;
        iVar4 = iVar4 + 1;
      } while (iVar2 < *(int *)(iVar1 + 0x3c));
    }
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_getScoreSlotFlags (FUN_680bd230)
// Address: 680bd230
// Size: 28 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreSlotFlags(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *(undefined4 *)(*param_1 + 0x84);
  }
  return 0;
}



// ============================================================
// Function: media_getScoreSlotRef2 (FUN_680bd250)
// Address: 680bd250
// Size: 25 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScoreSlotRef2(int *param_1,uint param_2)
{
  if (param_1 != (int *)0x0) {
    *(uint *)(*param_1 + 0x84) = *(uint *)(*param_1 + 0x84) | param_2;
  }
  return 0;
}



// ============================================================
// Function: media_setScoreSlot (FUN_680bd270)
// Address: 680bd270
// Size: 27 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setScoreSlot(int *param_1,uint param_2)
{
  if (param_1 != (int *)0x0) {
    *(uint *)(*param_1 + 0x84) = *(uint *)(*param_1 + 0x84) & ~param_2;
  }
  return 0;
}



// ============================================================
// Function: media_getScoreStatePtr (FUN_680bd290)
// Address: 680bd290
// Size: 51 bytes
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * media_getScoreStatePtr(void)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = media_getScoreDataSize();
  if (iVar1 != 0) {
    piVar2 = media_readScoreLayoutEntry();
    return piVar2;
  }
  return (int *)0x0;
}



// ============================================================
// Function: media_isScoreBufferValid (FUN_680bd2d0)
// Address: 680bd2d0
// Size: 44 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_isScoreBufferValid(int param_1)

{
  uint uVar1;
  
  if (param_1 != 0) {
    media_getScoreVersion2();
    uVar1 = media_getScoreBufferRef();
    if (0x14 < uVar1) {
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: media_getVtableFunc (media_getVtableFunc)
// Address: 680bd300
// Size: 25 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getVtableFunc(int *param_1)

{
  if (param_1 != (int *)0x0) {
    return *(undefined4 *)(*param_1 + 0x18);
  }
  return 0;
}



// ============================================================
// Function: media_copyScoreState (FUN_680bd320)
// Address: 680bd320
// Size: 101 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_copyScoreState(int param_1,int param_2)
{
  void *_Dst;
  void *_Src;
  
  if (param_1 != 0) {
    _Dst = (void *)Ordinal_1114(param_1);
    media_getScoreFrameData();
    if (param_2 != 0) {
      _Src = (void *)Ordinal_1114(param_2);
      media_getScoreBufferSize();
      memcpy(_Dst,_Src,0x1088);
      Ordinal_1115(param_2);
      Ordinal_1113(&param_2);
    }
    if (_Dst != (void *)0x0) {
      media_getScoreSlotData();
      Ordinal_1115(param_1);
    }
  }
  return 0;
}



// ============================================================
// Function: media_loadScoreData (FUN_680bd390)
// Address: 680bd390
// Size: 165 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_loadScoreData(int param_1)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  
  uVar3 = 1;
  if (param_1 == 0) {
    return 1;
  }
  iVar2 = Ordinal_1114(param_1);
  media_getScoreFrameData();
  if ((*(int *)(iVar2 + 0x1084) != 0) || (*(int *)(iVar2 + 0x87c) == 0)) goto LAB_680bd421;
  if (*(int *)(iVar2 + 0x888) == 0) {
LAB_680bd40d:
    uVar3 = media_encodeScoreLayout();
  }
  else {
    bVar1 = media_hasModifiedScoreSlots(iVar2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      uVar3 = media_validateScoreChannels();
      media_refreshScoreVersion(param_1);
    }
    if (*(int *)(iVar2 + 0x107c) == 1) {
      media_getScoreFormat(*(undefined4 *)(iVar2 + 0x894));
      *(undefined4 *)(iVar2 + 0x107c) = 0;
    }
    bVar1 = uVar3 != 0;
    uVar3 = 0;
    if (bVar1) goto LAB_680bd40d;
  }
  *(uint *)(iVar2 + 0x1084) = (uint)(uVar3 == 0);
LAB_680bd421:
  media_getScoreSlotData();
  Ordinal_1115(param_1);
  return uVar3;
}



// ============================================================
// Function: media_deleteScoreFrame (FUN_680bd440)
// Address: 680bd440
// Size: 122 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_deleteScoreFrame(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  if (param_1 != 0) {
    iVar2 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    if ((*(int *)(iVar2 + 0x1084) == 0) && (*(int *)(iVar2 + 0x87c) != 0)) {
      puVar1 = *(undefined4 **)(*(int *)(**(int **)(iVar2 + 8) + 0x18) + 0xc);
      media_removeScoreFrame();
      iVar3 = *(int *)(iVar2 + 0x70) + *(int *)(iVar2 + 0x1078);
      Ordinal_607(puVar1,(int *)0x0,iVar3 + -1,iVar3);
      lingo_getTextFieldData((int)puVar1,0,iVar3,-1);
      *(int *)(iVar2 + 0x1078) = *(int *)(iVar2 + 0x1078) + -1;
    }
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}




// ============================================================
// Function: media_insertScoreFrameEx (FUN_680bd4c0)
// Address: 680bd4c0
// Size: 112 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_insertScoreFrameEx(int param_1)
{
  int iVar1;
  int iVar2;
  
  media_loadScoreData(param_1);
  if (param_1 != 0) {
    iVar2 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    if ((*(int *)(iVar2 + 0x1084) == 0) && (*(int *)(iVar2 + 0x87c) != 0)) {
      iVar1 = *(int *)(*(int *)(**(int **)(iVar2 + 8) + 0x18) + 0xc);
      media_insertScoreFrame();
      lingo_getTextFieldData(iVar1,0,*(int *)(iVar2 + 0x70) + *(int *)(iVar2 + 0x1078),1);
      *(int *)(iVar2 + 0x1078) = *(int *)(iVar2 + 0x1078) + 1;
    }
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_incrementEditCount (FUN_680bd530)
// Address: 680bd530
// Size: 48 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_incrementEditCount(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    *(int *)(iVar1 + 0x1080) = *(int *)(iVar1 + 0x1080) + 1;
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_resetScoreBlocks (FUN_680bd560)
// Address: 680bd560
// Size: 77 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resetScoreBlocks(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    if ((*(int *)(iVar1 + 0x1084) == 0) && (*(int *)(iVar1 + 0x87c) != 0)) {
      media_initScoreBlocks();
      media_getScoreFormat(*(undefined4 *)(iVar1 + 0x54));
    }
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_setScorePosition (FUN_680bd5b0)
// Address: 680bd5b0
// Size: 70 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setScorePosition(int param_1,int param_2)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    if ((*(int *)(iVar1 + 0x1084) == 0) && (*(int *)(iVar1 + 0x87c) != 0)) {
      media_markScoreSlotModified(param_2);
    }
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_isScoreWritable (FUN_680bd600)
// Address: 680bd600
// Size: 61 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_isScoreWritable(int param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (param_1 != 0) {
    iVar2 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    bVar1 = media_hasChangedScoreSlots(iVar2);
    if (iVar2 != 0) {
      media_getScoreSlotData();
      Ordinal_1115(param_1);
    }
  }
  return bVar1;
}



// ============================================================
// Function: media_isScoreModified (FUN_680bd640)
// Address: 680bd640
// Size: 60 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_isScoreModified(int param_1)

{
  bool bVar1;
  int iVar2;
  
  bVar1 = false;
  if (param_1 != 0) {
    iVar2 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    bVar1 = media_processChangedScoreSlots(iVar2);
    if (iVar2 != 0) {
      media_getScoreSlotData();
      Ordinal_1115(param_1);
    }
  }
  return bVar1;
}



// ============================================================
// Function: media_releaseScoreData (FUN_680bd680)
// Address: 680bd680
// Size: 53 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_releaseScoreData(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    media_freeScoreLayoutState();
    if (iVar1 != 0) {
      media_getScoreSlotData();
      Ordinal_1115(param_1);
    }
  }
  return 0;
}



// ============================================================
// Function: media_setScoreChannelRef (FUN_680bd6c0)
// Address: 680bd6c0
// Size: 32 bytes
// Params: int * param_1, undefined4 param_2, undefined2 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setScoreChannelRef(int *param_1,undefined4 param_2,undefined2 param_3)
{
  if (param_1 != (int *)0x0) {
    *(undefined4 *)(*param_1 + 0x10) = param_2;
    *(undefined2 *)(*param_1 + 0xc) = param_3;
  }
  return 0;
}



// ============================================================
// Function: media_setScorePositionEx (FUN_680bd6e0)
// Address: 680bd6e0
// Size: 54 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_setScorePositionEx(int *param_1,undefined4 *param_2,undefined4 *param_3)

{
  if (param_1 != (int *)0x0) {
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = *(undefined4 *)(*param_1 + 8);
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = *(undefined4 *)(*param_1 + 0x10);
    }
    return CONCAT22((short)((uint)*param_1 >> 0x10),*(undefined2 *)(*param_1 + 0xc));
  }
  return 0;
}



// ============================================================
// Function: media_resolveScoreSprite (FUN_680bd720)
// Address: 680bd720
// Size: 91 bytes
// Params: int * param_1, short * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_resolveScoreSprite(int *param_1,short *param_2)
{
  short sVar1;
  undefined4 *puVar2;
  undefined2 *local_8;
  
  local_8 = (undefined2 *)0x0;
  if (param_1 != (int *)0x0) {
    sVar1 = *(short *)(*param_1 + 0xc);
    if (sVar1 != 0) {
      puVar2 = (undefined4 *)rendering_getChannelSprite(*(int *)(*param_1 + 8),sVar1);
      if (puVar2 != (undefined4 *)0x0) {
        local_8 = rendering_getChannelSlot(puVar2,4,*(int *)(*param_1 + 0x10));
        if (local_8 != (undefined2 *)0x0) {
          rendering_resolveChannelHeight(param_2,(int)local_8);
        }
      }
    }
  }
  rendering_processChannelEvent((int *)&local_8);
  return 0;
}



// ============================================================
// Function: media_mergeScoreEntries (FUN_680bd780)
// Address: 680bd780
// Size: 179 bytes
// Params: int * param_1, int param_2, undefined4 * param_3, int * param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_mergeScoreEntries(int *param_1,int param_2,undefined4 *param_3,int *param_4,int param_5)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  piVar2 = param_4;
  uVar5 = 0;
  bVar1 = false;
  if (param_5 != 0) {
    param_1 = (int *)Ordinal_1120(param_1,0);
    bVar1 = true;
    iVar3 = media_saveScoreViaChannel(param_1);
    if (iVar3 == 0) goto LAB_680bd81f;
  }
  bitmap_mergeRtfEntries(param_1);
  xtra_byteSwapEndian(param_1);
  uVar5 = Ordinal_1114(param_1);
  uVar4 = Ordinal_1116(param_1);
  if (param_2 != 0) {
    Ordinal_1420(param_2,uVar5,uVar4);
  }
  Ordinal_1115(param_1);
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = uVar4;
  }
  xtra_getWriteValue(param_1);
  uVar5 = bitmap_readRtfSequence(param_1,piVar2,1);
  if (!bVar1) {
    return uVar5;
  }
LAB_680bd81f:
  Ordinal_1113(&param_1);
  return uVar5;
}



// ============================================================
// Function: media_updateScoreProperty (FUN_680bd840)
// Address: 680bd840
// Size: 16 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_updateScoreProperty(int param_1)
{
  undefined4 in_EAX;
  
  rendering_getChannelProperty(*(int *)(param_1 + 0x878),in_EAX,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: media_getPlaybackRef (FUN_680bd850)
// Address: 680bd850
// Size: 4 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall media_getPlaybackRef(int param_1)
{
  undefined4 in_EAX;
  
  *(undefined4 *)(param_1 + 0x70) = in_EAX;
  return 0;
}



// ============================================================
// Function: media_isScoreSizeValid (FUN_680bd860)
// Address: 680bd860
// Size: 59 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_isScoreSizeValid(int param_1)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = false;
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    bVar2 = *(uint *)(iVar1 + 0x14) < 0x1000;
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return bVar2;
}



// ============================================================
// Function: media_getPlaybackFlags (FUN_680bd8a0)
// Address: 680bd8a0
// Size: 340 bytes
// Params: int param_1
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 media_getPlaybackFlags(int param_1)

{
  int *piVar1;
  bool bVar2;
  int in_EAX;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  bool bVar8;
  bool bVar9;
  bool bVar10;
  bool bVar11;
  bool bVar12;
  
  iVar5 = *(int *)(in_EAX + 0x44);
  bVar2 = false;
  if (param_1 == 0) {
    iVar6 = *(int *)(in_EAX + 0x3c);
    if (iVar6 < 1) goto LAB_680bd9e5;
  }
  else {
    iVar6 = 1000;
  }
  iVar6 = iVar6 + 6;
  if (iVar6 == *(int *)(in_EAX + 0x40)) {
    return 1;
  }
  iVar7 = iVar5;
  if (0 < iVar5) {
    do {
      media_getScoreSlotData();
      iVar7 = iVar7 + -1;
    } while (iVar7 != 0);
  }
  bVar8 = *(int *)(in_EAX + 0x50) == 0;
  piVar1 = (int *)(in_EAX + 0x50);
  iVar7 = iVar6 * 0x30;
  if (bVar8) {
    iVar3 = Ordinal_1111();
    *piVar1 = iVar3;
    uVar4 = Ordinal_1111(iVar7,1);
    *(undefined4 *)(in_EAX + 0x58) = uVar4;
    uVar4 = Ordinal_1111(iVar7,1);
    *(undefined4 *)(in_EAX + 0x60) = uVar4;
    uVar4 = Ordinal_1111(iVar7,1);
    *(undefined4 *)(in_EAX + 0x88) = uVar4;
    uVar4 = Ordinal_1111(iVar7,1);
    *(undefined4 *)(in_EAX + 0x90) = uVar4;
  }
  else {
    Ordinal_1117(piVar1,iVar7,1);
    Ordinal_1117(in_EAX + 0x58,iVar7,1);
    Ordinal_1117(in_EAX + 0x60,iVar7,1);
    Ordinal_1117(in_EAX + 0x88,iVar7,1);
    Ordinal_1117(in_EAX + 0x90,iVar7,1);
  }
  iVar7 = *piVar1;
  bVar9 = *(int *)(in_EAX + 0x58) != 0;
  bVar10 = *(int *)(in_EAX + 0x60) != 0;
  bVar11 = *(int *)(in_EAX + 0x88) != 0;
  bVar12 = *(int *)(in_EAX + 0x90) != 0;
  bVar2 = bVar12 && (bVar11 && (bVar10 && (bVar9 && iVar7 != 0)));
  if (0 < iVar5) {
    do {
      media_getScoreFrameData();
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  if (bVar8) {
    media_getScoreFrameData();
  }
  *(int *)(in_EAX + 0x40) = iVar6;
  if (bVar12 && (bVar11 && (bVar10 && (bVar9 && iVar7 != 0)))) {
    return bVar2;
  }
LAB_680bd9e5:
  media_getScoreBufferSize();
  return bVar2;
}




// ============================================================
// Function: media_getPlaybackState (FUN_680bda00)
// Address: 680bda00
// Size: 63 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getPlaybackState(void)
{
  int unaff_ESI;
  
  if ((*(int *)(unaff_ESI + 0x5c) != 0) && (*(int *)(unaff_ESI + 0x54) != 0)) {
    media_getPlaybackRef(unaff_ESI);
    media_getScoreFormat(*(undefined4 *)(unaff_ESI + 0x5c));
    media_getScoreFormat(*(undefined4 *)(unaff_ESI + 0x54));
    *(undefined4 *)(unaff_ESI + 0x78) = 0;
    *(undefined4 *)(unaff_ESI + 0x68) = *(undefined4 *)(unaff_ESI + 0x28);
    *(undefined4 *)(unaff_ESI + 0x6c) = *(undefined4 *)(unaff_ESI + 0x2c);
  }
  return 0;
}



// ============================================================
// Function: media_isPlaybackReady (FUN_680bda40)
// Address: 680bda40
// Size: 486 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_isPlaybackReady(int param_1)

{
  short sVar1;
  short sVar2;
  undefined2 uVar3;
  int in_EAX;
  int iVar4;
  undefined1 *puVar5;
  int iVar6;
  bool bVar7;
  undefined4 local_c;
  
  iVar6 = 0;
  iVar4 = media_lockScoreBuffer();
  if (iVar4 == 0) {
    return false;
  }
  if (param_1 != 0) {
    iVar6 = *(int *)(in_EAX + 0x94);
    *(undefined4 *)(in_EAX + 0x98) = 1;
  }
  if (*(int *)(in_EAX + 0x1c) == 0) {
    media_getScoreFormat(*(undefined4 *)(in_EAX + 0x5c));
    media_getScoreFormat(*(undefined4 *)(in_EAX + 0x54));
    if (*(int *)(in_EAX + 0x87c) == 0) {
      bVar7 = *(int *)(in_EAX + 0x70) == 0;
      media_getPlaybackRef(in_EAX);
    }
    else {
      bVar7 = true;
      media_getPlaybackRef(in_EAX);
    }
  }
  else {
    if ((param_1 != 0) && (*(int *)(in_EAX + 0x87c) == 0)) {
      media_copyScoreChannels(iVar6);
    }
    media_getPlaybackRef(in_EAX);
    puVar5 = *(undefined1 **)(in_EAX + 0x68);
    if (*(undefined1 **)(in_EAX + 0x30) <= puVar5) {
      media_getScoreFormat(*(undefined4 *)(in_EAX + 0x5c));
      media_getScoreFormat(*(undefined4 *)(in_EAX + 0x54));
      bVar7 = *(int *)(in_EAX + 0x87c) != 0;
      if ((param_1 != 0) && (*(int *)(in_EAX + 0x87c) == 0)) {
        media_applyScoreDelta(in_EAX,iVar6);
      }
      goto LAB_680bdbf9;
    }
    if ((*(int *)(in_EAX + 0x10) == 0) || (*(short *)(in_EAX + 0xc) == 0)) {
      if (*(int *)(in_EAX + 0x87c) == 0) {
        puVar5 = media_getScoreSlotPtr(*(int *)(in_EAX + 0x54),*(int *)(in_EAX + 0x40) * 0x30);
        *(undefined1 **)(in_EAX + 0x68) = puVar5;
      }
      else {
        media_applyScoreSlotData();
      }
    }
    else {
      media_applyScoreSlotData();
      media_dispatchScoreChannelWrite();
    }
    if ((param_1 != 0) && (*(int *)(in_EAX + 0x87c) == 0)) {
      media_applyScoreDelta(in_EAX,iVar6);
    }
    bVar7 = puVar5 != (undefined1 *)0x0;
  }
  iVar6 = *(int *)(in_EAX + 0x54);
  *(undefined4 *)(in_EAX + 0x7c) = *(undefined4 *)(in_EAX + 0x78);
  sVar1 = xtra_readBE16((undefined1 *)(iVar6 + 0xf0));
  sVar2 = xtra_readBE16((undefined1 *)(iVar6 + 0xf2));
  local_c = CONCAT22(sVar2,sVar1);
  if ((sVar1 != 0) && (sVar2 != 0)) {
    *(undefined4 *)(in_EAX + 0x78) = local_c;
  }
  if (*(char *)(iVar6 + 0x36) == -10) {
    uVar3 = xtra_readBE16((undefined1 *)(iVar6 + 0x34));
    *(undefined2 *)(in_EAX + 0x80) = uVar3;
  }
LAB_680bdbf9:
  media_unlockScoreBuffer();
  if (param_1 == 0) {
    return bVar7;
  }
  *(undefined4 *)(in_EAX + 0x98) = 0;
  return bVar7;
}



// ============================================================
// Function: media_seekPlaybackFrame (FUN_680bdc30)
// Address: 680bdc30
// Size: 176 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_seekPlaybackFrame(int param_1)
{
  int in_EAX;
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = media_lockScoreBuffer();
  if (iVar1 != 0) {
    if ((*(int *)(in_EAX + 0x48) != 0) && (*(int *)(in_EAX + 0x4c) != 0)) {
      iVar2 = Ordinal_1157(*(int *)(in_EAX + 0x4c));
      iVar1 = *(int *)(in_EAX + 0x48);
      do {
        iVar1 = iVar1 + -1;
        if ((iVar1 < 0) ||
           (piVar3 = (int *)Ordinal_1156(*(undefined4 *)(in_EAX + 0x4c),iVar2,iVar1),
           piVar3 == (int *)0x0)) goto LAB_680bdcc0;
      } while (param_1 < *piVar3);
      media_getScoreVersion(piVar3 + 1);
      media_getScoreVersion(piVar3 + 1);
      media_getPlaybackRef(in_EAX);
      *(int *)(in_EAX + 0x68) = piVar3[0x2f29] + *(int *)(in_EAX + 0x1c);
      *(int *)(in_EAX + 0x78) = piVar3[0x2f2a];
LAB_680bdcc0:
      if (iVar2 != 0) {
        Ordinal_1158(*(undefined4 *)(in_EAX + 0x4c),iVar2);
      }
    }
    media_unlockScoreBuffer();
  }
  return 0;
}



// ============================================================
// Function: media_getScoreFlags (FUN_680bdce0)
// Address: 680bdce0
// Size: 175 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_getScoreFlags(int param_1)

{
  int iVar1;
  bool bVar2;
  int in_EAX;
  undefined3 extraout_var;
  int iVar3;
  int unaff_EDI;
  undefined4 local_8;
  
  iVar3 = 0;
  local_8 = 1;
  if (*(int *)(in_EAX + 0x18) == 0) {
    return 0;
  }
  if (param_1 != 0) {
    iVar3 = *(int *)(in_EAX + 0x94);
    *(undefined4 *)(in_EAX + 0x98) = 1;
    if (*(int *)(in_EAX + 0x87c) == 0) {
      media_copyScoreChannels(iVar3);
    }
  }
  if ((unaff_EDI < *(int *)(in_EAX + 0x70)) || (unaff_EDI == 0)) {
    media_getPlaybackState();
  }
  media_seekPlaybackFrame(unaff_EDI);
  iVar1 = *(int *)(in_EAX + 0x70);
  while (iVar1 < unaff_EDI) {
    bVar2 = media_isPlaybackReady(0);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      local_8 = 0;
    }
    iVar1 = *(int *)(in_EAX + 0x70);
  }
  if ((param_1 != 0) && (*(int *)(in_EAX + 0x87c) == 0)) {
    media_applyScoreDelta(in_EAX,iVar3);
  }
  media_getPlaybackRef(in_EAX);
  if (param_1 != 0) {
    *(undefined4 *)(in_EAX + 0x98) = 0;
  }
  return local_8;
}



// ============================================================
// Function: media_buildPlaybackIndex (FUN_680bdd90)
// Address: 680bdd90
// Size: 349 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_buildPlaybackIndex(void)
{
  bool bVar1;
  int in_EAX;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  uint uVar4;
  int local_c;
  undefined4 *local_8;
  
  iVar3 = 0;
  local_8 = (undefined4 *)0x0;
  iVar2 = media_lockScoreBuffer();
  if (iVar2 == 0) {
    return 0;
  }
  local_8 = (undefined4 *)Ordinal_1124(0xbcb0);
  if ((local_8 != (undefined4 *)0x0) && (media_getScoreDataInfo(), 0x31 < *(int *)(in_EAX + 0x38))) {
    iVar2 = Ordinal_1150(10,1,0xbcb0);
    *(int *)(in_EAX + 0x4c) = iVar2;
    if (iVar2 != 0) {
      media_getPlaybackState();
      uVar4 = *(uint *)(in_EAX + 0x1c);
      iVar2 = *(int *)(in_EAX + 0x38) / 2;
      local_c = 0x32;
      if (iVar2 < 0x33) {
        local_c = iVar2;
      }
      Ordinal_1130(local_8 + 1,0xbca0);
      bVar1 = media_isPlaybackReady(0);
      iVar2 = CONCAT31(extraout_var,bVar1);
      while (iVar2 != 0) {
        if (((uVar4 <= *(uint *)(in_EAX + 0x68)) && (iVar3 < 10)) &&
           (local_c < *(int *)(in_EAX + 0x70))) {
          media_getScoreVersion(*(undefined4 *)(in_EAX + 0x54));
          *local_8 = *(undefined4 *)(in_EAX + 0x70);
          local_8[0x2f29] = *(int *)(in_EAX + 0x68) - *(int *)(in_EAX + 0x1c);
          local_8[0x2f2a] = *(undefined4 *)(in_EAX + 0x78);
          *(undefined2 *)(local_8 + 0x2f2b) = *(undefined2 *)(in_EAX + 0x80);
          iVar2 = Ordinal_1152(*(undefined4 *)(in_EAX + 0x4c),local_8);
          if (iVar2 == 0) goto LAB_680bdec9;
          iVar3 = iVar3 + 1;
          uVar4 = (uint)(*(int *)(in_EAX + 0x24) * iVar3) / 0xb + *(int *)(in_EAX + 0x1c);
          local_c = local_c + 0x32;
        }
        bVar1 = media_isPlaybackReady(0);
        iVar2 = CONCAT31(extraout_var_00,bVar1);
      }
      *(int *)(in_EAX + 0x48) = iVar3;
      goto LAB_680bdece;
    }
  }
LAB_680bdec9:
  media_getScoreDataInfo();
LAB_680bdece:
  media_getScoreFlags(0);
  media_unlockScoreBuffer();
  Ordinal_1125(&local_8);
  return 0;
}



// ============================================================
// Function: media_advancePlaybackChunk (FUN_680bdef0)
// Address: 680bdef0
// Size: 57 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_advancePlaybackChunk(void)

{
  ushort uVar1;
  undefined4 uVar2;
  int unaff_ESI;
  
  uVar2 = 0;
  if (*(uint *)(unaff_ESI + 0x68) < *(uint *)(unaff_ESI + 0x30)) {
    media_getPlaybackRef(unaff_ESI);
    uVar1 = xtra_readBE16(*(undefined1 **)(unaff_ESI + 0x68));
    if (uVar1 < 0x17941) {
      *(int *)(unaff_ESI + 0x68) = *(int *)(unaff_ESI + 0x68) + (uint)uVar1;
      return 1;
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}



// ============================================================
// Function: media_scanPlaybackToEnd (FUN_680bdf30)
// Address: 680bdf30
// Size: 31 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_scanPlaybackToEnd(void)
{
  int in_EAX;
  int iVar1;
  
  media_getPlaybackState();
  do {
    iVar1 = media_advancePlaybackChunk();
  } while (iVar1 == 1);
  *(undefined4 *)(in_EAX + 0x38) = *(undefined4 *)(in_EAX + 0x70);
  media_getPlaybackState();
  return 0;
}



// ============================================================
// Function: media_countPlaybackFrames (FUN_680bdf50)
// Address: 680bdf50
// Size: 157 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_countPlaybackFrames(undefined4 param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 uVar4;
  int local_1c;
  int local_18;
  int local_8;
  
  uVar4 = 0;
  iVar3 = 0;
  local_8 = 0;
  local_8 = Ordinal_1111(0x1088,1);
  if (local_8 != 0) {
    iVar2 = Ordinal_1114(local_8);
    uVar1 = media_getPlaybackFlags(1);
    if (CONCAT31(extraout_var,uVar1) != 0) {
      iVar3 = Ordinal_1114(param_1);
      iVar3 = iVar3 + param_2;
      media_getScoreBuffer();
      *(int *)(iVar2 + 0x28) = local_18 + iVar3;
      *(int *)(iVar2 + 0x68) = local_18 + iVar3;
      *(int *)(iVar2 + 0x1c) = iVar3;
      *(int *)(iVar2 + 0x30) = local_1c + iVar3;
      media_scanPlaybackToEnd();
      uVar4 = *(undefined4 *)(iVar2 + 0x38);
      media_getScoreBufferSize();
    }
    Ordinal_1115(local_8);
    Ordinal_1113(&local_8);
    if (iVar3 != 0) {
      Ordinal_1115(param_1);
    }
  }
  return uVar4;
}



// ============================================================
// Function: media_getPlaybackData (FUN_680bdff0)
// Address: 680bdff0
// Size: 95 bytes
// Params: undefined2 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_getPlaybackData(undefined2 param_1)

{
  undefined1 uVar1;
  undefined3 extraout_var;
  int local_8;
  
  local_8 = Ordinal_1111(0x1088,1);
  if (local_8 != 0) {
    Ordinal_1114(local_8);
    media_setScoreHeaderType(param_1);
    uVar1 = media_getPlaybackFlags(1);
    if (CONCAT31(extraout_var,uVar1) == 0) {
      media_getScoreBufferSize();
    }
    Ordinal_1115(local_8);
    if (CONCAT31(extraout_var,uVar1) == 0) {
      Ordinal_1113(&local_8);
    }
  }
  return local_8;
}



// ============================================================
// Function: media_initPlayback (FUN_680be050)
// Address: 680be050
// Size: 52 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_initPlayback(void)
{
  int in_EAX;
  
  media_freeScoreLayoutState();
  if (*(int *)(in_EAX + 0x18) != 0) {
    score_freePropertyHandle(*(int *)(in_EAX + 0x18));
  }
  Ordinal_1113(in_EAX + 0x880);
  media_getScoreDataInfo();
  media_getScoreBufferSize();
  media_setScoreHeaderType(0);
  return 0;
}




// ============================================================
// Function: media_processPlayback (FUN_680be090)
// Address: 680be090
// Size: 393 bytes
// Params: void * this, int param_1, int param_2
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall media_processPlayback(void *this,int param_1,int param_2)

{
  int param_4;
  undefined1 uVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined3 extraout_var;
  int unaff_EBX;
  int local_1c;
  int local_18;
  undefined4 local_14;
  short local_10;
  short local_e;
  short local_c;
  short local_a;
  undefined4 local_8;
  
  local_8 = 0;
  if (((this == (void *)0x0) || (*(int *)this == 0)) && (in_EAX == 0)) {
    local_8 = 1;
  }
  else {
    if (this == (void *)0x0) {
      if (in_EAX != 0) {
        *(int *)(unaff_EBX + 0x18) = in_EAX;
      }
    }
    else {
      iVar2 = Ordinal_1116(*(undefined4 *)this);
      if (iVar2 == 0) {
        iVar2 = media_getScoreDataSize();
        if (iVar2 == 0) goto LAB_680be1fa;
        Ordinal_1113(this);
        *(int *)this = iVar2;
      }
      if (*(int **)(unaff_EBX + 0x18) == (int *)0x0) {
        piVar3 = media_readScoreLayoutEntry();
        *(int **)(unaff_EBX + 0x18) = piVar3;
        if (piVar3 == (int *)0x0) goto LAB_680be1fa;
      }
      else {
        xtra_readSerializedValue(*(int **)(unaff_EBX + 0x18),0,*(undefined4 **)this);
        Ordinal_1113(this);
      }
    }
    if (param_2 != 0) {
      media_getScoreLayoutData(*(int **)(unaff_EBX + 0x18));
    }
    *(undefined4 *)(unaff_EBX + 0x20) = 0;
    local_8 = 1;
    iVar2 = media_getScoreVersion2();
    iVar4 = Ordinal_1114(*(undefined4 *)(unaff_EBX + 0x18));
    iVar2 = iVar2 + iVar4;
    media_getScoreBuffer();
    *(undefined4 *)(unaff_EBX + 0x38) = local_14;
    *(int *)(unaff_EBX + 0x24) = local_1c;
    iVar4 = local_18 + iVar2;
    *(int *)(unaff_EBX + 0x3c) = (int)local_a;
    *(int *)(unaff_EBX + 0x30) = local_1c + iVar2;
    *(int *)(unaff_EBX + 0x28) = iVar4;
    *(int *)(unaff_EBX + 0x68) = iVar4;
    *(int *)(unaff_EBX + 0x1c) = iVar2;
    *(int *)(unaff_EBX + 0x2c) = iVar4 - iVar2;
    *(int *)(unaff_EBX + 0x34) = (local_1c + iVar2) - iVar2;
    *(int *)(unaff_EBX + 0x6c) = iVar4 - iVar2;
    Ordinal_1115(*(undefined4 *)(unaff_EBX + 0x18));
    *(undefined4 *)(unaff_EBX + 0x1c) = 0;
    *(undefined4 *)(unaff_EBX + 0x28) = 0;
    *(undefined4 *)(unaff_EBX + 0x30) = 0;
    *(undefined4 *)(unaff_EBX + 0x68) = 0;
    if ((*(int *)(unaff_EBX + 0x3c) + 6 <= *(int *)(unaff_EBX + 0x40)) ||
       (uVar1 = media_getPlaybackFlags(0), CONCAT31(extraout_var,uVar1) != 0)) {
      media_getPlaybackState();
      if ((local_10 < 5) || ((local_10 < 0xc && (local_e != 0x30)))) {
        local_8 = 0;
      }
      if (((0x3ee < local_c) || (local_a < 0)) || (local_c < local_a)) {
        local_8 = 0;
      }
    }
  }
LAB_680be1fa:
  media_getScoreDataInfo();
  if (param_1 != 0) {
    media_buildPlaybackIndex();
  }
  return local_8;
}



// ============================================================
// Function: media_processPlaybackEx (FUN_680be220)
// Address: 680be220
// Size: 164 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_processPlaybackEx(void)

{
  undefined1 uVar1;
  int in_EAX;
  int iVar2;
  undefined3 extraout_var;
  
  if (*(int *)(in_EAX + 0x87c) != 0) {
    return 1;
  }
  Ordinal_1130((undefined4 *)(in_EAX + 0x87c),0x80c);
  iVar2 = media_getScoreDataSize();
  *(int *)(in_EAX + 0x880) = iVar2;
  if (iVar2 != 0) {
    *(undefined4 *)(in_EAX + 0x884) = *(undefined4 *)(in_EAX + 0x70);
    *(undefined4 *)(in_EAX + 0x87c) = 1;
    uVar1 = media_getPlaybackFlags(1);
    if (CONCAT31(extraout_var,uVar1) != 0) {
      iVar2 = Ordinal_1124(0xbca0);
      *(int *)(in_EAX + 0x894) = iVar2;
      if (iVar2 != 0) {
        media_getScoreVersion(*(undefined4 *)(in_EAX + 0x54));
        *(undefined4 *)(in_EAX + 0x890) = 0x14;
        *(undefined4 *)(in_EAX + 0x1080) = 0;
        return 1;
      }
    }
  }
  media_getScoreBufferSize();
  Ordinal_1125(in_EAX + 0x894);
  return 0;
}



// ============================================================
// Function: media_stepPlayback (FUN_680be2d0)
// Address: 680be2d0
// Size: 49 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_stepPlayback(void)
{
  int in_EAX;
  int iVar1;
  
  if (*(int *)(in_EAX + 0x87c) != 0) {
    iVar1 = media_encodeScoreLayout();
    if (iVar1 == 0) {
      *(undefined4 *)(in_EAX + 0x1084) = 1;
    }
    *(int *)(in_EAX + 0x1080) = *(int *)(in_EAX + 0x1080) + 1;
  }
  media_isPlaybackReady(0);
  return 0;
}



// ============================================================
// Function: media_processPlaybackBlock (FUN_680be310)
// Address: 680be310
// Size: 85 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_processPlaybackBlock(int param_1)

{
  undefined4 uVar1;
  int unaff_EDI;
  
  uVar1 = 0;
  if ((*(int *)(unaff_EDI + 0x87c) != 0) && (*(int *)(unaff_EDI + 0x1084) == 0)) {
    if (param_1 != 0) {
      media_stepPlayback();
    }
    media_getScoreLayoutSize();
    uVar1 = *(undefined4 *)(unaff_EDI + 0x880);
    *(undefined4 *)(unaff_EDI + 0x880) = 0;
  }
  media_freeScoreLayoutState();
  return uVar1;
}



// ============================================================
// Function: media_advancePlaybackFrames (FUN_680be370)
// Address: 680be370
// Size: 426 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_advancePlaybackFrames(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *local_14;
  int local_10;
  undefined4 local_c;
  int local_8;
  
  iVar4 = 0;
  local_c = 0;
  local_10 = 0;
  local_8 = 0;
  if (param_2 < 1) {
    local_c = 1;
    Ordinal_1113(&local_10);
    return local_c;
  }
  local_10 = media_getPlaybackData(0);
  if (local_10 != 0) {
    iVar4 = Ordinal_1114(local_10);
    local_14 = xtra_readSerializedPtr((int *)param_1[6],0);
    iVar2 = media_processPlayback(&local_14,0,0);
    if (iVar2 != 0) {
      media_getScoreFlags(0);
      iVar2 = media_processPlaybackEx();
      if (iVar2 != 0) {
        media_getScoreVersion(*(undefined4 *)(iVar4 + 0x54));
        media_getScoreFormat(*(undefined4 *)(iVar4 + 0x54));
        iVar3 = media_getScoreLayout((undefined4 *)(iVar4 + 0x880),(int *)(iVar4 + 0x890),
                             (int *)(iVar4 + 0x88c),*(short **)(iVar4 + 0x54),
                             *(short **)(iVar4 + 100),*(int *)(iVar4 + 0x3c),1);
        iVar2 = param_2;
        if (iVar3 != 0) {
          media_getScoreFormat(*(undefined4 *)(iVar4 + 100));
          do {
            iVar2 = iVar2 + -1;
            if (iVar2 < 1) {
              local_8 = media_processPlaybackBlock(0);
              local_8 = media_getScoreLayoutBlock(local_8);
              puVar1 = param_1;
              param_1 = xtra_readSerializedPtr((int *)param_1[6],0);
              iVar2 = media_getScoreLayoutRef(0x7fffffff,local_8,param_2);
              if (iVar2 != 0) {
                xtra_readSerializedValue((int *)puVar1[6],0,param_1);
                Ordinal_1113(&param_1);
                local_c = 1;
              }
              break;
            }
            iVar3 = media_getScoreLayout((undefined4 *)(iVar4 + 0x880),(int *)(iVar4 + 0x890),
                                 (int *)(iVar4 + 0x88c),*(short **)(iVar4 + 0x54),
                                 *(short **)(iVar4 + 100),*(int *)(iVar4 + 0x3c),1);
          } while (iVar3 != 0);
        }
      }
    }
  }
  if (local_8 != 0) {
    Ordinal_1113(&local_8);
  }
  if (iVar4 != 0) {
    media_initPlayback();
  }
  Ordinal_1113(&local_10);
  return local_c;
}



// ============================================================
// Function: media_editScoreFrames (FUN_680be520)
// Address: 680be520
// Size: 1155 bytes
// Params: undefined4 * param_1, int param_2, int param_3, undefined4 * param_4, int param_5, int param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
media_editScoreFrames(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4,int param_5,int param_6
            )

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  int iVar7;
  int iVar8;
  short *psVar9;
  short *psVar10;
  int local_30;
  undefined4 local_24;
  int local_20;
  undefined4 *local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar8 = 0;
  local_24 = 0;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  local_18 = 0;
  local_8 = 0;
  iVar7 = 0;
  Ordinal_1114(*param_4);
  media_getScoreBuffer();
  Ordinal_1115(*param_4);
  iVar4 = param_2;
  local_20 = local_30;
  if (param_1[0xe] + 1 < param_2) {
    iVar7 = (param_2 - param_1[0xe]) + -1;
    iVar3 = media_advancePlaybackFrames(param_1,iVar7);
    if (iVar3 == 0) goto LAB_680be953;
  }
  if ((local_30 != 0) || (param_5 == 0)) {
    if (param_5 == 0) {
      iVar4 = (param_1[0xe] + iVar7) - iVar4;
      if (param_3 == 0) {
        if (iVar4 < local_30) {
          param_3 = iVar4 + 1;
        }
        else {
          param_3 = local_30;
        }
      }
      else if (iVar4 < param_3) {
        param_3 = iVar4 + 1;
      }
    }
    else {
      param_3 = 0;
    }
    local_14 = media_getPlaybackData(0);
    if ((local_14 == 0) || (local_18 = media_getPlaybackData(0), local_18 == 0)) goto LAB_680be953;
    iVar8 = Ordinal_1114(local_14);
    local_8 = Ordinal_1114(local_18);
    local_1c = xtra_readSerializedPtr((int *)param_1[6],0);
    iVar4 = media_processPlayback(&local_1c,0,0);
    puVar1 = param_4;
    if (iVar4 == 0) goto LAB_680be953;
    local_1c = (undefined4 *)Ordinal_1112(*param_4);
    iVar4 = media_processPlayback(puVar1,0,0);
    *param_4 = local_1c;
    if (iVar4 == 0) goto LAB_680be953;
    if (local_30 < 1) {
      media_getScoreFlags(0);
      media_getScoreVersion(*(undefined4 *)(iVar8 + 0x54));
      local_1c = (undefined4 *)(param_3 + param_2);
      media_getScoreFlags(0);
      iVar4 = media_processPlaybackEx();
      if (iVar4 == 0) goto LAB_680be953;
      iVar4 = *(int *)(iVar8 + 0x3c);
      psVar10 = *(short **)(iVar8 + 100);
      psVar9 = *(short **)(iVar8 + 0x54);
LAB_680be784:
      iVar4 = media_getScoreLayout((undefined4 *)(iVar8 + 0x880),(int *)(iVar8 + 0x890),
                           (int *)(iVar8 + 0x88c),psVar9,psVar10,iVar4,1);
      if (iVar4 == 0) goto LAB_680be953;
      local_c = media_processPlaybackBlock(0);
      local_c = media_getScoreLayoutBlock(local_c);
    }
    else {
      media_getScoreFlags(0);
      media_getScoreFlags(0);
      iVar4 = media_processPlaybackEx();
      if ((iVar4 == 0) ||
         (iVar4 = media_getScoreLayout((undefined4 *)(iVar8 + 0x880),(int *)(iVar8 + 0x890),
                               (int *)(iVar8 + 0x88c),*(short **)(local_8 + 0x54),
                               *(short **)(iVar8 + 0x54),*(int *)(iVar8 + 0x3c),1), iVar4 == 0))
      goto LAB_680be953;
      local_10 = media_processPlaybackBlock(0);
      local_10 = media_getScoreLayoutBlock(local_10);
      local_1c = (undefined4 *)(param_3 + param_2);
      if ((int)local_1c <= (int)param_1[0xe]) {
        media_getScoreFlags(0);
        media_getScoreFlags(0);
        iVar4 = media_processPlaybackEx();
        if (iVar4 == 0) goto LAB_680be953;
        iVar4 = *(int *)(iVar8 + 0x3c);
        psVar10 = *(short **)(local_8 + 0x54);
        psVar9 = *(short **)(iVar8 + 0x54);
        goto LAB_680be784;
      }
    }
    iVar4 = media_processPlayback((void *)0x0,0,0);
    if ((iVar4 == 0) || (iVar4 = media_processPlayback((void *)0x0,0,0), iVar4 == 0)) goto LAB_680be953;
    if (local_10 != 0) {
      media_removeScoreFrames(extraout_ECX,1,1);
      iVar4 = media_getScoreLayoutRef(1,local_10,1);
      if (iVar4 == 0) goto LAB_680be953;
    }
    if ((local_c != 0) && (iVar4 = media_getScoreLayoutRef(0x7fffffff,local_c,1), iVar4 == 0))
    goto LAB_680be953;
    puVar2 = param_4;
    uVar5 = media_getScoreLayoutBlock(*param_4);
    puVar1 = param_1;
    *puVar2 = uVar5;
    if (local_c != 0) {
      param_1 = xtra_readSerializedPtr((int *)param_1[6],0);
      media_removeScoreFrames(extraout_ECX_00,(int)local_1c,1);
      uVar5 = xtra_readSerializedValue((int *)puVar1[6],0,param_1);
      Ordinal_1113(&param_1);
      if ((short)uVar5 != 0) goto LAB_680be953;
      local_20 = local_30 + 1;
    }
    if (param_5 == 0) {
      param_1 = xtra_readSerializedPtr((int *)puVar1[6],0);
      media_removeScoreFrames(extraout_ECX_01,param_2,param_3);
      uVar5 = xtra_readSerializedValue((int *)puVar1[6],0,param_1);
      Ordinal_1113(&param_1);
      if ((short)uVar5 != 0) goto LAB_680be953;
    }
    param_1 = xtra_readSerializedPtr((int *)puVar1[6],0);
    uVar6 = media_getScoreLayoutRef(param_2,*param_4,local_20);
    uVar5 = xtra_readSerializedValue((int *)puVar1[6],0,param_1);
    Ordinal_1113(&param_1);
    if ((uVar6 & (short)uVar5 == 0) == 0) goto LAB_680be953;
    param_1 = xtra_readSerializedPtr((int *)puVar1[6],0);
    iVar4 = media_processPlayback(&param_1,(uint)(puVar1[0x13] != 0),param_6);
    if (iVar4 == 0) goto LAB_680be953;
  }
  local_24 = 1;
LAB_680be953:
  Ordinal_1113(&local_10);
  Ordinal_1113(&local_c);
  Ordinal_1113(param_4);
  if (iVar8 != 0) {
    media_initPlayback();
  }
  if (local_8 != 0) {
    media_initPlayback();
  }
  Ordinal_1113(&local_14);
  Ordinal_1113(&local_18);
  return local_24;
}




// ============================================================
// Function: media_readScoreChannels (FUN_680be9b0)
// Address: 680be9b0
// Size: 664 bytes
// Params: void * this, undefined4 param_1, undefined4 param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall
media_readScoreChannels(void *this,undefined4 param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  undefined2 uVar2;
  undefined2 uVar3;
  int in_EAX;
  uint uVar4;
  int iVar5;
  undefined4 local_10;
  int local_8;
  
  iVar1 = *(int *)(in_EAX + 4);
  uVar2 = xtra_readBE16(this);
  uVar3 = xtra_readBE16((undefined1 *)((int)this + 2));
  local_10 = CONCAT22(uVar3,uVar2);
  uVar4 = media_readScoreRange(iVar1,local_10,0,param_4,0);
  if (uVar4 == 0) {
    if (DAT_681963d4 == 0) {
      Ordinal_1032();
    }
    DAT_681963d4 = DAT_681963d4 + 1;
    return 0;
  }
  uVar4 = media_readScoreRange(iVar1,0,1,param_4,0);
  if (uVar4 == 0) {
    if (DAT_681963d8 == 0) {
      Ordinal_1032();
    }
    DAT_681963d8 = DAT_681963d8 + 1;
    return 0;
  }
  uVar4 = media_readScoreRange(iVar1,0,2,param_4,0);
  if (uVar4 == 0) {
    if (DAT_681963dc == 0) {
      Ordinal_1032();
    }
    DAT_681963dc = DAT_681963dc + 1;
    return 0;
  }
  uVar4 = media_readScoreRange(iVar1,0,4,param_4,0);
  if (uVar4 == 0) {
    if (DAT_681963e0 == 0) {
      Ordinal_1032();
    }
    DAT_681963e0 = DAT_681963e0 + 1;
    return 0;
  }
  uVar4 = media_readScoreRange(iVar1,0,3,param_4,0);
  if (uVar4 == 0) {
    if (DAT_681963e4 == 0) {
      Ordinal_1032();
    }
    DAT_681963e4 = DAT_681963e4 + 1;
    return 0;
  }
  uVar4 = media_readScoreRange(iVar1,0,5,param_4,0);
  if (uVar4 == 0) {
    if (DAT_681963e8 == 0) {
      Ordinal_1032();
    }
    DAT_681963e8 = DAT_681963e8 + 1;
    return 0;
  }
  param_3 = param_3 + 0x30;
  local_8 = 6;
  while( true ) {
    iVar5 = 0;
    if ((-1 < local_8 + -4) && (local_8 + -4 < 0x3ee)) {
      iVar5 = param_3;
    }
    uVar2 = xtra_readBE16((undefined1 *)(iVar5 + 6));
    uVar3 = xtra_readBE16((undefined1 *)(iVar5 + 8));
    local_10 = CONCAT22(uVar3,uVar2);
    uVar4 = media_readScoreRange(iVar1,local_10,local_8,param_4,0);
    if (uVar4 == 0) break;
    param_3 = param_3 + 0x18;
    iVar5 = local_8 + -5;
    local_8 = local_8 + 1;
    if (999 < iVar5) {
      return 1;
    }
  }
  if (DAT_681963ec == 0) {
    Ordinal_1032();
  }
  DAT_681963ec = DAT_681963ec + 1;
  return 0;
}



// ============================================================
// Function: media_buildScoreLayout (FUN_680bec50)
// Address: 680bec50
// Size: 742 bytes
// Params: undefined4 param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * media_buildScoreLayout(undefined4 param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  void *_Src;
  void *_Dst;
  short *this;
  undefined1 *puVar4;
  int iVar5;
  undefined4 uVar6;
  int local_50;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  short *local_14;
  int local_10;
  int *local_c;
  undefined4 *local_8;
  
  bVar1 = false;
  local_c = (int *)0x0;
  local_8 = (undefined4 *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_2c = 0;
  local_28 = 0;
  iVar3 = media_getScoreBufferState();
  if (-1 < iVar3) {
    local_c = media_readScoreLayoutEntry();
    if (local_c == (int *)0x0) {
      if (DAT_681963f0 == 0) {
        Ordinal_1032();
      }
      DAT_681963f0 = DAT_681963f0 + 1;
    }
    else {
      local_8 = (undefined4 *)media_getScoreDataSize();
      if (local_8 == (undefined4 *)0x0) {
        if (DAT_681963f4 == 0) {
          Ordinal_1032();
        }
        DAT_681963f4 = DAT_681963f4 + 1;
      }
      else {
        local_24 = Ordinal_1111(0x5e50,1);
        if (local_24 == 0) {
          if (DAT_681963f8 == 0) {
            Ordinal_1032();
          }
          DAT_681963f8 = DAT_681963f8 + 1;
        }
        else {
          _Src = (void *)Ordinal_1114(local_24);
          local_20 = Ordinal_1111(0x5e50,1);
          if (local_20 == 0) {
            if (DAT_681963fc == 0) {
              Ordinal_1032();
            }
            DAT_681963fc = DAT_681963fc + 1;
          }
          else {
            _Dst = (void *)Ordinal_1114(local_20);
            local_2c = Ordinal_1111(0x5e50,1);
            if (local_2c == 0) {
              if (DAT_68196400 == 0) {
                Ordinal_1032();
              }
              DAT_68196400 = DAT_68196400 + 1;
            }
            else {
              this = (short *)Ordinal_1114(local_2c);
              local_28 = Ordinal_1111(0x5e50,1);
              if (local_28 == 0) {
                if (DAT_68196404 == 0) {
                  Ordinal_1032();
                }
                DAT_68196404 = DAT_68196404 + 1;
              }
              else {
                local_14 = (short *)Ordinal_1114(local_28);
                local_1c = 0x14;
                local_10 = 0;
                local_18 = 0;
                iVar3 = Ordinal_1114(param_1);
                puVar4 = media_getScoreBuffer();
                while (puVar4 < (undefined1 *)(local_50 + iVar3)) {
                  puVar4 = media_getScoreSlotPtr((int)_Src,0x5e50);
                  if (puVar4 == (undefined1 *)0x0) goto LAB_680beee3;
                  local_10 = local_10 + 1;
                  media_convertScoreNewToOld((undefined4 *)this);
                  iVar5 = media_readScoreChannels(this,local_c,local_14,(int)_Src,local_10);
                  if (iVar5 == 0) {
                    if (DAT_68196408 == 0) {
                      Ordinal_1032();
                    }
                    DAT_68196408 = DAT_68196408 + 1;
                    goto LAB_680beee3;
                  }
                  iVar5 = media_encodeScoreDelta(this,local_14,&local_8,&local_1c,&local_18);
                  if (iVar5 == 0) {
                    if (DAT_6819640c == 0) {
                      Ordinal_1032();
                    }
                    DAT_6819640c = DAT_6819640c + 1;
                    goto LAB_680beee3;
                  }
                  memcpy(_Dst,_Src,0x5e50);
                  memcpy(local_14,this,0x5e50);
                }
                media_getScoreLayoutSize();
                piVar2 = local_c;
                bitmap_patchRtfDefaults(local_c,local_10);
                uVar6 = xtra_readSerializedValue(piVar2,0,local_8);
                if ((short)uVar6 == 0) {
                  bVar1 = true;
                }
                else {
                  if (DAT_68196410 == 0) {
                    Ordinal_1032();
                  }
                  DAT_68196410 = DAT_68196410 + 1;
                }
              }
            }
          }
        }
      }
    }
  }
LAB_680beee3:
  Ordinal_1113(&local_20);
  Ordinal_1113(&local_24);
  Ordinal_1113(&local_28);
  Ordinal_1113(&local_2c);
  Ordinal_1113(&param_1);
  Ordinal_1113(&local_8);
  if ((!bVar1) && (local_c != (int *)0x0)) {
    score_freePropertyHandle(local_c);
    local_c = (int *)0x0;
  }
  return local_c;
}



// ============================================================
// Function: media_convertScoreData (FUN_680bef40)
// Address: 680bef40
// Size: 688 bytes
// Params: undefined4 param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * media_convertScoreData(undefined4 param_1,int *param_2)

{
  bool bVar1;
  int *in_EAX;
  int iVar2;
  undefined3 extraout_var;
  undefined4 *puVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  short local_18;
  undefined4 *local_10;
  undefined4 *local_c;
  int local_8;
  
  local_8 = 0;
  media_getScoreBuffer();
  iVar2 = media_validateScoreBuffer();
  if (iVar2 == 0) {
    iVar2 = xtra_getWriteValue(in_EAX);
    if (iVar2 == 0) {
      lingo_formatDebugMsg(*(int **)(param_2[1] + 8),-0x78);
      goto LAB_680bf06c;
    }
    bVar1 = xtra_validateChunkHandle(in_EAX,0);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      lingo_formatDebugMsg(*(int **)(param_2[1] + 8),-0x78);
      goto LAB_680bf06c;
    }
    Ordinal_1114();
    iVar2 = media_getScoreVersion2();
    media_getScoreBuffer();
    local_8 = bitmap_readRtfSequence(in_EAX,param_2,(uint)(0xd < local_18));
    if (local_8 == 0) goto LAB_680bf06c;
    Ordinal_1115();
    if (2 < (ushort)(local_18 - 8U)) {
      if (local_18 < 0xc) {
        param_2 = (int *)Ordinal_1114();
        media_countPlaybackFrames(in_EAX,iVar2);
        media_getScoreBufferEx();
        Ordinal_1115();
      }
      goto LAB_680bf0b5;
    }
    lingo_formatDebugMsg(*(int **)(param_2[1] + 8),-0x6f);
  }
  else {
    if (local_18 < 8) {
      Ordinal_1114();
      media_countPlaybackFrames(in_EAX,0);
      media_getScoreBufferEx();
      Ordinal_1115();
    }
    if (local_18 < 5) {
      in_EAX = (int *)media_convertScoreFromOldFormat(in_EAX,param_1);
    }
    if (7 < local_18) {
      return (int *)0x0;
    }
    in_EAX = media_buildScoreLayout(in_EAX);
LAB_680bf0b5:
    if (in_EAX != (int *)0x0) {
      Ordinal_1114(in_EAX);
      media_getScoreVersion2();
      media_getScoreBuffer();
      Ordinal_1115(in_EAX);
      if (local_18 < 0xc) {
        puVar3 = xtra_readSerializedPtr(in_EAX,0);
        if ((puVar3 != (undefined4 *)0x0) &&
           (param_2 = (int *)media_convertScoreToNewFormat(puVar3), param_2 != (int *)0x0)) {
          uVar4 = xtra_readSerializedValue(in_EAX,0,param_2);
          Ordinal_1113(&param_2);
          if ((short)uVar4 == 0) {
            bitmap_markRtfDirty(in_EAX);
            goto LAB_680bf126;
          }
        }
      }
      else {
LAB_680bf126:
        if (0xd < local_18) {
          return in_EAX;
        }
        piVar5 = (int *)xtra_allocChunkStorage(0xc,0,0,-3);
        uVar6 = bitmap_getRtfData(in_EAX);
        param_2 = (int *)Ordinal_1111(uVar6 * 8,1);
        puVar3 = (undefined4 *)Ordinal_1114(param_2);
        iVar2 = bitmap_serializeRtfNode(in_EAX,piVar5,puVar3);
        if (((iVar2 != 0) && (local_c = xtra_readSerializedPtr(piVar5,0), local_c != (undefined4 *)0x0)) &&
           (local_10 = (undefined4 *)media_convertScoreWithRefs((int)local_c,puVar3,uVar6),
           local_10 != (undefined4 *)0x0)) {
          uVar4 = xtra_readSerializedValue(piVar5,0,local_10);
          Ordinal_1113(&local_c);
          Ordinal_1113(&local_10);
          if ((short)uVar4 == 0) {
            Ordinal_1115(param_2);
            Ordinal_1113(&param_2);
            score_freePropertyHandle(in_EAX);
            return piVar5;
          }
        }
      }
    }
  }
  if (local_8 != 0) {
    return in_EAX;
  }
LAB_680bf06c:
  if (in_EAX == (int *)0x0) {
    return (int *)0x0;
  }
  score_freePropertyHandle(in_EAX);
  return (int *)0x0;
}




// ============================================================
// Function: media_writePlaybackChannel (FUN_680bf1f0)
// Address: 680bf1f0
// Size: 871 bytes
// Params: int param_1, uint param_2, undefined4 param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint media_writePlaybackChannel(int param_1,uint param_2,int param_3)

{
  int *piVar1;
  bool bVar2;
  uint uVar3;
  undefined4 uVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar5;
  int iVar6;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined4 local_30;
  undefined4 local_2c;
  int local_28;
  int local_24;
  int local_20;
  undefined1 *local_1c;
  char *local_18;
  undefined2 local_14;
  undefined2 local_12;
  int local_10;
  int local_c;
  int local_8;
  
  local_c = *(int *)(param_1 + 0x1078) + *(int *)(param_1 + 0x70);
  piVar1 = *(int **)(param_1 + 0x18);
  local_20 = *(int *)(*(int *)(**(int **)(param_1 + 8) + 0x18) + 0xc);
  if ((*(int *)(param_1 + 0x87c) == 0) || (local_20 == 0)) {
    return 1;
  }
  if (param_2 < 0x3ee) {
    local_18 = (char *)(param_2 * 0x30 + *(int *)(param_1 + 0x54));
    local_1c = (undefined1 *)(param_2 * 0x30 + *(int *)(param_1 + 0x894));
  }
  else {
    local_18 = (char *)0x0;
    local_1c = (undefined1 *)0x0;
  }
  uVar3 = media_commitModifiedScoreSlot(param_2,param_3);
  if (uVar3 == 0) {
    return 0;
  }
  media_extractScoreChannelProps(local_18,param_2,&local_8,&local_10,(int *)&local_1c,&local_30,&local_2c);
  iVar5 = local_10;
  if (local_10 == 0) {
    return uVar3;
  }
  bitmap_readRtfPair(piVar1,local_10,0,(undefined4 *)&local_14);
  local_24 = bitmap_readRtfHeader(piVar1,iVar5);
  local_28 = bitmap_readRtfValue(piVar1,iVar5);
  iVar5 = local_c;
  if (param_3 == CONCAT22(local_12,local_14)) {
    return uVar3;
  }
  uVar4 = media_compareScoreFrameRange(local_24,local_28);
  switch(uVar4) {
  case 1:
    iVar5 = local_10;
    goto LAB_680bf520;
  case 2:
    bitmap_readRtfPair(piVar1,local_8,0,(undefined4 *)&local_14);
    if ((local_8 != 0) && (param_3 == CONCAT22(local_12,local_14))) {
      iVar6 = bitmap_readRtfSection(piVar1,local_10,1);
      if (iVar6 == 0) {
        return 0;
      }
      xtra_skipBytes(local_1c);
      bVar2 = bitmap_isRtfValid(piVar1,local_8,iVar5);
      return CONCAT31(extraout_var,bVar2);
    }
    local_8 = local_10;
    iVar5 = bitmap_writeRtfChunk(piVar1,param_2,iVar5);
    if (iVar5 == 0) goto LAB_680bf386;
    xtra_skipBytes(local_1c);
    if (5 < (int)param_2) {
      local_18[0x16] = local_18[0x16] & 0x7f;
    }
    iVar6 = bitmap_readRtfSection(piVar1,local_8,1);
    if (iVar6 == 0) {
      return 0;
    }
    break;
  case 3:
    local_8 = local_10;
    iVar5 = bitmap_writeRtfChunk(piVar1,param_2,iVar5);
    if (iVar5 != 0) {
      xtra_skipBytes(local_1c);
      if (5 < (int)param_2) {
        local_18[0x16] = local_18[0x16] & 0x7f;
      }
      bVar2 = bitmap_isRtfValid(piVar1,local_8,local_c + -1);
      if (CONCAT31(extraout_var_00,bVar2) == 0) {
        return 0;
      }
      iVar6 = bitmap_readRtfRange(piVar1,local_8,piVar1,iVar5);
      if (iVar6 == 0) {
        return 0;
      }
      bVar2 = bitmap_isRtfValid(piVar1,iVar5,local_c);
      if (CONCAT31(extraout_var_01,bVar2) == 0) {
        return 0;
      }
      bitmap_readRtfEntry(piVar1,iVar5);
      if ((*(unsigned short *)((char *)&param_3 + 2)) == 0) {
        return CONCAT31(extraout_var_01,bVar2);
      }
      uVar3 = bitmap_setRtfValue(piVar1,iVar5,local_20,param_3);
      return uVar3;
    }
LAB_680bf386:
    return (uint)(DAT_68195a8c == 0);
  default:
    goto switchD_680bf2f9_caseD_4;
  case 5:
    media_markScoreSlotChanged(param_2);
    local_8 = local_10;
    iVar5 = bitmap_writeRtfChunk(piVar1,param_2,iVar5 + 1);
    if (iVar5 == 0) {
LAB_680bf492:
      return (uint)(DAT_68195a8c == 0);
    }
    iVar6 = bitmap_readRtfRange(piVar1,local_8,piVar1,iVar5);
    if ((iVar6 != 0) &&
       (bVar2 = bitmap_isRtfValid(piVar1,local_8,local_c + -1), CONCAT31(extraout_var_02,bVar2) != 0)) {
      bitmap_isRtfValid(piVar1,iVar5,local_28);
    }
    iVar5 = bitmap_writeRtfChunk(piVar1,param_2,local_c);
    if (iVar5 == 0) goto LAB_680bf492;
    xtra_skipBytes(local_1c);
    if (5 < (int)param_2) {
      local_18[0x16] = local_18[0x16] & 0x7f;
    }
  }
  iVar6 = bitmap_readRtfRange(piVar1,local_8,piVar1,iVar5);
  uVar3 = 0;
  if (iVar6 != 0) {
    bVar2 = bitmap_isRtfValid(piVar1,iVar5,local_c);
    uVar3 = CONCAT31(extraout_var_03,bVar2);
    if (uVar3 != 0) {
LAB_680bf520:
      bitmap_readRtfEntry(piVar1,iVar5);
      if ((*(unsigned short *)((char *)&param_3 + 2)) != 0) {
        uVar3 = bitmap_setRtfValue(piVar1,iVar5,local_20,param_3);
      }
    }
  }
switchD_680bf2f9_caseD_4:
  return uVar3;
}



// ============================================================
// Function: media_writePlaybackData (FUN_680bf570)
// Address: 680bf570
// Size: 73 bytes
// Params: undefined4 param_1, undefined2 param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_writePlaybackData(undefined4 param_1,undefined2 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = media_getPlaybackData(param_2);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)Ordinal_1114(iVar1);
    media_getScoreFrameData();
    puVar2[0x21e] = param_3;
    *puVar2 = 1;
    puVar2[2] = param_1;
    media_getScoreSlotData();
    Ordinal_1115(iVar1);
  }
  return iVar1;
}



// ============================================================
// Function: media_getScorePlayState (FUN_680bf5c0)
// Address: 680bf5c0
// Size: 89 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getScorePlayState(int *param_1)
{
  int *piVar1;
  int iVar2;
  
  if ((undefined4 *)*param_1 != (undefined4 *)0x0) {
    piVar1 = *(int **)*param_1;
    *piVar1 = *piVar1 + -1;
    if (0 < *piVar1) {
      *param_1 = 0;
      return 0;
    }
    if (*param_1 != 0) {
      iVar2 = Ordinal_1114(*param_1);
      media_getScoreFrameData();
      media_initPlayback();
      if (iVar2 != 0) {
        media_getScoreSlotData();
        Ordinal_1115(*param_1);
      }
    }
    Ordinal_1113(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_getPlaybackPosition (FUN_680bf620)
// Address: 680bf620
// Size: 51 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_getPlaybackPosition(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    media_getPlaybackState();
    if (iVar1 != 0) {
      media_getScoreSlotData();
      Ordinal_1115(param_1);
    }
  }
  return 0;
}



// ============================================================
// Function: media_isPlaybackActive (FUN_680bf660)
// Address: 680bf660
// Size: 71 bytes
// Params: int param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool media_isPlaybackActive(int param_1,int param_2)

{
  bool bVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    bVar1 = media_isPlaybackReady(param_2);
    if (iVar2 != 0) {
      media_getScoreSlotData();
      Ordinal_1115(param_1);
    }
    return bVar1;
  }
  return false;
}



// ============================================================
// Function: media_readPlaybackData (FUN_680bf6b0)
// Address: 680bf6b0
// Size: 68 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_readPlaybackData(int param_1,undefined4 param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if (param_1 != 0) {
    iVar2 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    uVar1 = media_getScoreFlags(param_3);
    if (iVar2 != 0) {
      media_getScoreSlotData();
      Ordinal_1115(param_1);
    }
  }
  return uVar1;
}



// ============================================================
// Function: media_setScoreTempo (FUN_680bf700)
// Address: 680bf700
// Size: 39 bytes
// Params: int * param_1, undefined2 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_setScoreTempo(int *param_1,undefined2 param_2)
{
  if (param_1 != (int *)0x0) {
    *(undefined2 *)(*param_1 + 0x80) = param_2;
    media_updateScoreProperty(*param_1);
  }
  return 0;
}



// ============================================================
// Function: media_setScoreChannelCount (FUN_680bf730)
// Address: 680bf730
// Size: 121 bytes
// Params: int * param_1, int param_2
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 media_setScoreChannelCount(int *param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  
  uVar1 = 1;
  if (param_2 < 1) {
    param_2 = 1;
  }
  else if (1000 < param_2) {
    param_2 = 1000;
  }
  if (param_1 != (int *)0x0) {
    iVar2 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    *(int *)(iVar2 + 0x3c) = param_2;
    media_getScoreVersion2();
    media_readScoreBufferDirect();
    uVar1 = media_getPlaybackFlags(0);
    media_getScoreSlotData();
    Ordinal_1115(param_1);
    media_getScoreReadState(param_1,0xf);
  }
  return uVar1;
}



// ============================================================
// Function: media_getPlaybackByte (FUN_680bf7b0)
// Address: 680bf7b0
// Size: 125 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 media_getPlaybackByte(int param_1,int param_2,int param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  int iVar3;
  
  uVar1 = 0;
  if (param_1 != 0) {
    iVar2 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    iVar3 = media_processPlayback((void *)0x0,param_4,0);
    if (iVar3 != 0) {
      if (param_3 == 0) {
        param_3 = rendering_resolveChannelType(0x79f);
      }
      *(int *)(iVar2 + 0x14) = param_3;
      uVar1 = 1;
      if (param_2 != 0) {
        uVar1 = media_getPlaybackFlags(0);
      }
    }
    if (iVar2 != 0) {
      media_getScoreSlotData();
      Ordinal_1115(param_1);
    }
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: media_cloneScoreState (FUN_680bf830)
// Address: 680bf830
// Size: 148 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int media_cloneScoreState(int param_1)

{
  undefined1 uVar1;
  void *_Src;
  undefined3 extraout_var;
  void *_Dst;
  int iVar2;
  
  iVar2 = 0;
  _Dst = (void *)0x0;
  if (param_1 != 0) {
    _Src = (void *)Ordinal_1114(param_1);
    media_getScoreFrameData();
    if (*(int *)((int)_Src + 0x87c) == 0) {
      iVar2 = Ordinal_1111(0x1088,0);
      if (iVar2 != 0) {
        _Dst = (void *)Ordinal_1114(iVar2);
        memcpy(_Dst,_Src,0x1088);
        media_initScoreFields();
        uVar1 = media_getPlaybackFlags(0);
        if (CONCAT31(extraout_var,uVar1) == 0) {
          media_copyScoreState(param_1,iVar2);
          iVar2 = 0;
          _Dst = (void *)0x0;
        }
        media_getPlaybackState();
      }
    }
    media_getScoreSlotData();
    Ordinal_1115(param_1);
    if (_Dst != (void *)0x0) {
      Ordinal_1115(iVar2);
    }
  }
  return iVar2;
}




// ============================================================
// Function: media_readPlaybackBlock (FUN_680bf8d0)
// Address: 680bf8d0
// Size: 182 bytes
// Params: void * this, int param_1, int param_2
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

void * __thiscall media_readPlaybackBlock(void *this,int param_1,int param_2)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  void *local_8;
  
  local_8 = this;
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    local_8 = (void *)media_processPlaybackEx();
    *(undefined4 *)(iVar1 + 0x888) = 0;
    if (param_2 != 0) {
      *(undefined4 *)(iVar1 + 0x888) = 1;
      puVar2 = (undefined1 *)(iVar1 + 0xc87);
      iVar3 = 0x3ee;
      do {
        puVar2[-0x3ef] = 0;
        *puVar2 = 0;
        puVar2 = puVar2 + 1;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
      *(undefined1 *)(iVar1 + 0x1075) = 0;
      *(undefined1 *)(iVar1 + 0xc86) = 0;
      *(undefined4 *)(iVar1 + 0x1078) = 0;
      *(undefined4 *)(iVar1 + 0x107c) = 1;
      media_getScoreFlags(0);
      media_getScoreVersion(*(undefined4 *)(iVar1 + 0x54));
      media_isPlaybackReady(0);
    }
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return local_8;
}



// ============================================================
// Function: media_readPlaybackBlockEx (FUN_680bf990)
// Address: 680bf990
// Size: 80 bytes
// Params: int param_1, uint param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_readPlaybackBlockEx(int param_1,uint param_2,undefined4 param_3)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    if ((*(int *)(iVar1 + 0x1084) == 0) && (*(int *)(iVar1 + 0x87c) != 0)) {
      media_processChangedScoreSlots(iVar1);
      media_writePlaybackChannel(iVar1,param_2,param_3);
    }
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: media_stepPlaybackLocked (FUN_680bf9e0)
// Address: 680bf9e0
// Size: 53 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_stepPlaybackLocked(int param_1)
{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = Ordinal_1114(param_1);
    media_getScoreFrameData();
    media_stepPlayback();
    if (iVar1 != 0) {
      media_getScoreSlotData();
      Ordinal_1115(param_1);
    }
  }
  return 0;
}



// ============================================================
// Function: media_applyScoreEdit (FUN_680bfa20)
// Address: 680bfa20
// Size: 182 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_applyScoreEdit(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_8;
  
  uVar3 = 0;
  local_8 = 0;
  if (param_1 != 0) {
    puVar2 = (undefined4 *)Ordinal_1114(param_1);
    media_getScoreFrameData();
    if (puVar2[0x21f] == 0) {
      uVar3 = 1;
    }
    else if (puVar2[0x421] == 0) {
      iVar1 = puVar2[0x221];
      if (param_5 == -1) {
        param_5 = (uint)(param_2 != 0) + puVar2[0x420];
      }
      local_8 = media_processPlaybackBlock(param_2);
      uVar3 = media_editScoreFrames(puVar2,iVar1,param_5,&local_8,param_3,param_4);
      media_getScoreFlags(1);
    }
    media_getScoreSlotData();
    Ordinal_1115(param_1);
  }
  Ordinal_1113(&local_8);
  return uVar3;
}



// ============================================================
// Function: media_loadScoreResource (FUN_680bfae0)
// Address: 680bfae0
// Size: 104 bytes
// Params: undefined4 param_1, uint param_2, int * param_3, int param_4, short * param_5
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * media_loadScoreResource(undefined4 param_1,uint param_2,int *param_3,int param_4,short *param_5)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)0x0;
  if ((param_2 != 0) && (0xb < param_2)) {
    iVar2 = Ordinal_1439(param_1,param_2,0);
    piVar1 = (int *)0x0;
    if ((iVar2 != 0) &&
       (((piVar1 = media_convertScoreData((uint)(param_5 != (short *)0x0),param_3), piVar1 != (int *)0x0 &&
         (param_4 != 0)) && (iVar2 = media_saveScoreData((int)param_3,param_5), iVar2 == 0)))) {
      score_freePropertyHandle(piVar1);
      return (int *)0x0;
    }
  }
  return piVar1;
}



// ============================================================
// Function: media_readPlaybackEntry (FUN_680bfb50)
// Address: 680bfb50
// Size: 141 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int media_readPlaybackEntry(void)
{
  int iVar1;
  undefined4 uVar2;
  int unaff_ESI;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_34 = 0;
  iVar1 = Ordinal_1656(*(undefined4 *)(unaff_ESI + 0x54),&local_34);
  if ((iVar1 != 0) && (local_20 == 0x20)) {
    uVar2 = 0;
    if ((*(byte *)(unaff_ESI + 0x9c) & 0x10) != 0) {
      uVar2 = 8;
    }
    Ordinal_1657(*(undefined4 *)(unaff_ESI + 0x54),0x20,uVar2,0);
  }
  return 0;
}



// ============================================================
// Function: media_compareScoreChannelData (FUN_680bfbe0)
// Address: 680bfbe0
// Size: 90 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 media_compareScoreChannelData(int param_1)

{
  int in_EAX;
  undefined4 uVar1;
  short *psVar2;
  short *psVar3;
  int iVar4;
  int unaff_EDI;
  
  iVar4 = 0;
  uVar1 = 1;
  if (0 < unaff_EDI) {
    psVar3 = (short *)(in_EAX + 6);
    psVar2 = (short *)(param_1 + 2);
    while (((*(short *)((in_EAX - param_1) + (int)psVar2) == *psVar2 && (psVar3[-1] == psVar2[1]))
           && (*psVar3 == psVar2[2]))) {
      iVar4 = iVar4 + 1;
      psVar3 = psVar3 + 4;
      psVar2 = psVar2 + 4;
      if (unaff_EDI <= iVar4) {
        return 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



// ============================================================
// Function: media_readPlaybackField (FUN_680bfc40)
// Address: 680bfc40
// Size: 1023 bytes
// Params: undefined4 param_1, int param_2, int param_3, undefined4 param_4, uint param_5, int param_6
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
media_readPlaybackField(int param_1,int param_2,int param_3,undefined4 param_4,uint param_5,int param_6)
{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  int iVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint local_868;
  int local_864;
  undefined4 local_860;
  int local_85c;
  undefined4 local_858;
  undefined4 local_854;
  undefined4 local_850;
  undefined4 local_84c;
  undefined4 local_848;
  undefined4 local_844;
  int local_840;
  undefined4 local_83c;
  undefined4 local_838;
  undefined4 local_834;
  undefined4 local_830;
  undefined4 local_82c [5];
  undefined1 local_818 [16];
  undefined1 local_808 [2048];
  uint local_8;
  
  local_860 = param_4;
  local_868 = param_5;
  local_85c = param_1;
  uVar1 = lingo_isValidRef(param_3);
  uVar2 = lingo_getObjectFlags(param_3);
  local_864 = 0;
  local_858 = 0;
  local_854 = 0;
  local_850 = 0;
  local_84c = 0;
  local_848 = 0;
  local_844 = 0;
  local_840 = 0;
  local_83c = 0;
  local_838 = 0;
  local_834 = 0;
  local_830 = 0;
  uVar14 = 0;
  uVar3 = Ordinal_1605(uVar2);
  uVar4 = Ordinal_1605(uVar1);
  uVar5 = Ordinal_1610(uVar2);
  uVar6 = Ordinal_1610(uVar1);
  uVar7 = Ordinal_1612(uVar2);
  iVar8 = events_setMiawBgColor();
  if (iVar8 != 0) {
    if (local_868 == param_5) {
      iVar8 = Ordinal_1656(local_860,&local_858);
      if (iVar8 != 0) {
        local_864 = Ordinal_1650(param_5,0,0,local_854,local_858,1);
        if (local_864 != 0) {
          if ((local_840 != 0) && (param_5 != 0x20)) {
            Ordinal_1665(local_864,0);
          }
          iVar8 = Ordinal_1604(uVar1,local_860);
          if (iVar8 != 0) {
            if (local_85c != 0) {
              iVar8 = Ordinal_1609(uVar1,local_85c);
              if (iVar8 == 0) goto LAB_680bffd5;
            }
            iVar8 = Ordinal_1604(uVar2,local_864);
            if (iVar8 != 0) {
              if (param_2 != 0) {
                iVar8 = Ordinal_1613(uVar2,param_2,0);
                if (iVar8 == 0) goto LAB_680bffd5;
              }
              Ordinal_1060(local_818,0,0,local_854,local_858);
              local_82c[0] = 0;
              if ((param_5 < 8) && (param_6 != 0)) {
                local_85c = Ordinal_1600();
                if (local_85c != 0) {
                  local_860 = Ordinal_1730(0x100);
                  uVar9 = Ordinal_1610(uVar2);
                  uVar10 = Ordinal_1734(uVar9);
                  uVar14 = Ordinal_1736(uVar9,0,local_808,uVar10);
                  uVar11 = Ordinal_1737(local_860,0,local_808,uVar10);
                  uVar12 = Ordinal_1613(local_85c,local_860,0);
                  local_868 = Ordinal_1650(8,0,0,local_854,local_858,0);
                  uVar13 = Ordinal_1604(local_85c,local_868);
                  uVar13 = uVar14 & 1 & uVar11 & uVar12 & uVar13;
                  uVar14 = 0;
                  if (uVar13 != 0) {
                    Ordinal_1665(local_868,0);
                    uVar11 = Ordinal_1616(local_85c,local_818,uVar1,local_818,0,0,local_82c,0,1);
                    uVar14 = Ordinal_1616(uVar2,local_818,local_85c,local_818,0,0,local_82c,0,0);
                    uVar14 = uVar13 & uVar11 & uVar14;
                  }
                  Ordinal_1604(local_85c,0);
                  Ordinal_1653(&local_868);
                  Ordinal_1733(&local_860);
                  Ordinal_1601(&local_85c);
                }
              }
              else {
                uVar14 = Ordinal_1616(uVar2,local_818,uVar1,local_818,0,0,local_82c,0,param_6 != 0);
              }
            }
          }
        }
      }
    }
    else {
      Ordinal_1040(0x73);
    }
  }
LAB_680bffd5:
  Ordinal_1604(uVar2,uVar3);
  Ordinal_1604(uVar1,uVar4);
  Ordinal_1609(uVar2,uVar5);
  Ordinal_1609(uVar1,uVar6);
  Ordinal_1611(uVar2,uVar7);
  if (uVar14 == 0) {
    Ordinal_1653(&local_864);
  }
  return 0;
}



