// Module: bitmap
// Topic: RTF style run data structures, paragraph operations, byte-swapping, style management
// Address range: 0x680ece80 - 0x680effe0
// Functions (74):
//   bitmap_dispatchRtfEvent
//   bitmap_initRtfParser
//   bitmap_clearRtfStyle
//   bitmap_getRtfData
//   bitmap_readRtfInt
//   bitmap_getRtfCapacity
//   bitmap_resizeRtfBlock
//   bitmap_patchRtfDefaults
//   bitmap_readRtfHeader
//   bitmap_readRtfValue
//   bitmap_readRtfTag
//   bitmap_readRtfField
//   bitmap_getRtfPairValue
//   bitmap_readRtfPair
//   bitmap_getRtfFieldPtr
//   bitmap_readRtfEntry
//   bitmap_resolveRtfField
//   bitmap_getRtfFieldPair
//   bitmap_setRtfTagValue
//   bitmap_findRtfEntry
//   bitmap_getRtfEntryData
//   bitmap_shiftRtfOffsets
//   bitmap_findRtfByRange
//   bitmap_getRtfBlockFlag
//   bitmap_setRtfBlockFlag
//   bitmap_readRtfBlock
//   bitmap_getRtfStyleAttrs
//   bitmap_setRtfStyleAttrs
//   bitmap_resetRtfDefaults
//   bitmap_getRtfNodeData
//   bitmap_writeRtfTag
//   bitmap_writeRtfEntry
//   bitmap_allocRtfNode
//   bitmap_swapRtfFields
//   bitmap_updateRtfFieldRef
//   bitmap_writeRtfFieldData
//   bitmap_writeRtfFieldHandle
//   bitmap_removeRtfField
//   bitmap_writeRtfName
//   bitmap_readRtfName
//   bitmap_searchRtfByName
//   bitmap_markRtfDirty
//   bitmap_getRtfIndexValue
//   bitmap_parseRtfNode
//   bitmap_byteSwapRtfNode
//   bitmap_insertRtfSorted
//   bitmap_reorderRtfEntry
//   bitmap_removeRtfByIndex
//   bitmap_appendRtfField
//   bitmap_populateRtfFields
//   bitmap_readRtfSequence
//   bitmap_mergeRtfEntries
//   bitmap_getRtfByte
//   bitmap_writeRtfRange
//   bitmap_setRtfProperty
//   bitmap_isRtfValid
//   bitmap_validateRtfRange
//   bitmap_setRtfValue
//   bitmap_readRtfRange
//   bitmap_readRtfSection
//   bitmap_compactRtfData
//   bitmap_expandRtfData
//   bitmap_writeRtfChunk
//   bitmap_serializeRtfNode
//   bitmap_readRtfChunk
//   bitmap_writeRtfBlock
//   bitmap_deserializeRtfNode
//   bitmap_copyRtfToBuffer
//   bitmap_pasteRtfFromBuffer
//   bitmap_duplicateRtfNode
//   bitmap_deleteRtfRange
//   bitmap_splitRtfNode
//   bitmap_validateRtfNode
//   bitmap_repairRtfData

// ============================================================
// Function: bitmap_dispatchRtfEvent (FUN_680ece80)
// Address: 680ece80
// Size: 1274 bytes
// Params: void * this, undefined4 * param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 * __thiscall bitmap_dispatchRtfEvent(void *this,undefined4 *param_1)

{
  undefined4 *puVar1;
  short sVar2;
  int *piVar3;
  int *piVar4;
  undefined4 *puVar5;
  bool bVar6;
  int iVar7;
  undefined3 extraout_var;
  uint uVar8;
  int iVar9;
  void *local_8;
  
  puVar5 = param_1;
  puVar1 = param_1 + 2;
  piVar3 = (int *)*param_1;
  param_1 = (undefined4 *)0x0;
  local_8 = this;
  switch(*puVar1) {
  case 0:
    iVar7 = bitmap_processTextEvent();
    if (iVar7 == 0) {
      return (undefined4 *)0;
    }
    break;
  case 3:
    if (piVar3[0x15] != 0) {
      iVar7 = xtra_getBufferSize(piVar3[0x15]);
      iVar7 = xtra_insertIntoBuffer(piVar3[0x15],0,iVar7);
      Ordinal_1130(piVar3 + 0x25,0xc);
      piVar3[0x15] = 0;
      bitmap_getTextFieldSize((int)piVar3,iVar7);
      iVar7 = piVar3[0x15];
      goto LAB_680eceb4;
    }
    goto LAB_680eceb6;
  case 5:
    iVar7 = bitmap_dispatchTextMsg();
    goto LAB_680eceb4;
  case 6:
    iVar7 = bitmap_importTextData((void *)puVar5[4],puVar5[6],puVar5[3]);
    goto LAB_680eceb4;
  case 7:
    if (puVar5[5] != FOURCC_STXT) break;
    bVar6 = bitmap_loadTextMemberData(puVar5[4],(int *)puVar5[6],puVar5[3]);
    iVar7 = CONCAT31(extraout_var,bVar6);
    goto LAB_680eceb4;
  case 8:
    bitmap_clearTextField(puVar5[1]);
    return (undefined4 *)1;
  case 9:
    iVar7 = xtra_calculateBufferSize(piVar3[0x15]);
    puVar5[3] = iVar7;
    break;
  case 10:
    rendering_updateMemberState(piVar3,FOURCC_STXT,puVar5 + 3,(undefined4 *)0x0,(int *)0x0);
    return (undefined4 *)1;
  case 0xb:
    iVar7 = bitmap_copyTextToClipboard();
    goto LAB_680eceb4;
  case 0xc:
    iVar7 = core_returnTrue();
    goto LAB_680eceb4;
  case 0xf:
    if (piVar3[2] == 3) {
      puVar5[3] = 7;
      return (undefined4 *)1;
    }
    sVar2 = (short)piVar3[0x20];
    if (sVar2 != 1) {
      if (sVar2 == 2) {
        puVar5[3] = 9;
        return (undefined4 *)1;
      }
      if (sVar2 == 3) {
        puVar5[3] = 10;
        return (undefined4 *)1;
      }
    }
    puVar5[3] = 8;
    return (undefined4 *)1;
  case 0x10:
    bitmap_readTextProps();
    return (undefined4 *)1;
  case 0x11:
    bitmap_writeTextProps();
    return (undefined4 *)1;
  case 0x12:
    puVar5[3] = 1;
    return (undefined4 *)1;
  case 0x13:
    iVar7 = crt_negotiateFormat(puVar5 + 4,puVar5[3],FOURCC_STXT);
    puVar5[3] = iVar7;
    return (undefined4 *)1;
  case 0x17:
    piVar4 = (int *)puVar5[3];
    if (*piVar4 == 6) {
      if (piVar4[1] == 0) {
        iVar7 = xtra_setBufferPos(piVar3[0x15],1);
        if (iVar7 == 0) {
          iVar7 = Ordinal_1111(1,1);
          piVar4[2] = iVar7;
          puVar5[4] = 0;
          return (undefined4 *)1;
        }
        iVar7 = Ordinal_1120(iVar7,0);
        piVar4[2] = iVar7;
        puVar5[4] = 0;
        return (undefined4 *)1;
      }
      goto LAB_680ed209;
    }
    if (*piVar4 != 7) {
LAB_680ed122:
      puVar5[4] = 2;
      return (undefined4 *)0;
    }
    if (piVar4[1] != 1) goto LAB_680ed209;
    uVar8 = scoreEngine_getChannelRange(*(int *)(puVar5[1] + 0x20),(short)piVar3[1],0);
    iVar7 = scoreEngine_getFrameData(*(int *)(puVar5[1] + 0x20),(short)uVar8);
    if (iVar7 == 0) {
      iVar7 = scoreEngine_getFrameData(*(int *)(puVar5[1] + 0x20),1);
    }
    iVar7 = bitmap_buildFontRunMap(&local_8,(int)piVar3,iVar7 + 0x14);
    if (iVar7 != 0) {
      piVar4[2] = (int)local_8;
      puVar5[4] = 0;
      return (undefined4 *)1;
    }
    break;
  case 0x18:
    piVar4 = (int *)puVar5[3];
    if (*piVar4 == 6) {
      if (piVar4[1] == 0) {
        bitmap_setTextContent(puVar5[1],piVar3,piVar4[2]);
        puVar5[4] = 0;
        return (undefined4 *)1;
      }
    }
    else {
      if (*piVar4 != 7) goto LAB_680ed122;
      if (piVar4[1] == 1) {
        iVar7 = bitmap_applyTextImport(puVar5[1],(int)piVar3,piVar4[2]);
        if (iVar7 == 0) {
          return (undefined4 *)0;
        }
        puVar5[4] = 0;
        return (undefined4 *)1;
      }
    }
LAB_680ed209:
    puVar5[4] = 3;
    return (undefined4 *)0;
  case 0x19:
    iVar7 = bitmap_getTextProperty(puVar5);
    if (iVar7 != 0) {
      return (undefined4 *)1;
    }
    break;
  case 0x1a:
    iVar7 = bitmap_setTextProperty(puVar5);
    if (iVar7 != 0) {
      return (undefined4 *)1;
    }
    break;
  case 0x1b:
    bitmap_updateTextMember(puVar5[1],puVar5[3],puVar5[4],puVar5[5]);
    return (undefined4 *)1;
  case 0x1d:
    iVar7 = puVar5[3];
    if ((((((char)piVar3[0x16] == *(char *)(iVar7 + 0x58)) &&
          (*(char *)((int)piVar3 + 0x59) == *(char *)(iVar7 + 0x59))) &&
         (*(char *)((int)piVar3 + 0x5a) == *(char *)(iVar7 + 0x5a))) &&
        (((*(char *)((int)piVar3 + 0x5b) == *(char *)(iVar7 + 0x5b) &&
          ((short)piVar3[0x17] == *(short *)(iVar7 + 0x5c))) &&
         ((iVar9 = Ordinal_1079((int)piVar3 + 0x5e,iVar7 + 0x5e), iVar9 != 0 &&
          ((piVar3[0x19] == *(int *)(iVar7 + 100) &&
           (iVar9 = Ordinal_1063(piVar3 + 0x1a,iVar7 + 0x68), iVar9 != 0)))))))) &&
       ((piVar3[0x1e] == *(int *)(iVar7 + 0x78) &&
        ((((((char)piVar3[0x1f] == *(char *)(iVar7 + 0x7c) &&
            (*(char *)((int)piVar3 + 0x7d) == *(char *)(iVar7 + 0x7d))) &&
           (*(short *)((int)piVar3 + 0x7e) == *(short *)(iVar7 + 0x7e))) &&
          ((piVar3[2] != 7 || ((short)piVar3[0x20] == *(short *)(iVar7 + 0x80))))) &&
         (iVar7 = xtra_compareTextBlocks(piVar3[0x15],*(undefined4 *)(iVar7 + 0x54)), iVar7 != 0)))))) {
      puVar5[4] = 1;
      return (undefined4 *)1;
    }
    goto LAB_680eceb6;
  }
  iVar7 = rendering_validateState(puVar5);
LAB_680eceb4:
  if (iVar7 != 0) {
LAB_680eceb6:
    param_1 = (undefined4 *)0x1;
  }
  return param_1;
}



// ============================================================
// Function: bitmap_initRtfParser (FUN_680ed400)
// Address: 680ed400
// Size: 45 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_initRtfParser(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0:
    in_EAX = 5;
    break;
  case 1:
    return 0;
  case 2:
    return 2;
  case 3:
    return 4;
  case 4:
    return 3;
  case 5:
    return 1;
  }
  return in_EAX;
}



// ============================================================
// Function: bitmap_clearRtfStyle (FUN_680ed450)
// Address: 680ed450
// Size: 17 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_clearRtfStyle(void)
{
  undefined4 *in_EAX;
  
  *in_EAX = 0;
  in_EAX[1] = 0;
  in_EAX[2] = 0;
  in_EAX[3] = 0;
  in_EAX[4] = 0;
  return 0;
}



// ============================================================
// Function: bitmap_getRtfData (FUN_680ed470)
// Address: 680ed470
// Size: 59 bytes
// Params: undefined4 * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint bitmap_getRtfData(undefined4 *param_1)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = xtra_readSerializedBlock(param_1,1);
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  puVar2 = (uint *)xtra_writeValue(param_1,1);
  return *puVar2 & ((int)(uVar1 >> 2) <= (int)*puVar2) - 1;
}



// ============================================================
// Function: bitmap_readRtfInt (FUN_680ed4b0)
// Address: 680ed4b0
// Size: 55 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readRtfInt(undefined4 *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = bitmap_getRtfData(param_1);
    if ((param_2 <= (int)uVar1) && (0 < param_2)) {
      iVar2 = xtra_writeValue(param_1,1);
      return *(undefined4 *)(iVar2 + param_2 * 4);
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_getRtfCapacity (FUN_680ed4f0)
// Address: 680ed4f0
// Size: 31 bytes
// Params: undefined4 * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint bitmap_getRtfCapacity(undefined4 *param_1)

{
  uint uVar1;
  
  if (param_1 != (undefined4 *)0x0) {
    uVar1 = xtra_readSerializedBlock(param_1,1);
    return uVar1 >> 2;
  }
  return 0;
}



// ============================================================
// Function: bitmap_resizeRtfBlock (FUN_680ed510)
// Address: 680ed510
// Size: 49 bytes
// Params: int * param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_resizeRtfBlock(int *param_1,int param_2)

{
  uint uVar1;
  
  if (param_1 != (int *)0x0) {
    uVar1 = xtra_readChunkBlock(param_1,1,param_2 * 4);
    return (short)uVar1 == 0;
  }
  return false;
}



// ============================================================
// Function: bitmap_patchRtfDefaults (FUN_680ed550)
// Address: 680ed550
// Size: 73 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_patchRtfDefaults(undefined4 *param_1,undefined4 param_2)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = bitmap_getRtfData(param_1);
  iVar2 = xtra_writeValue(param_1,1);
  iVar4 = 1;
  if (0 < (int)uVar1) {
    do {
      iVar3 = xtra_writeValue(param_1,*(int *)(iVar2 + iVar4 * 4));
      if (*(int *)(iVar3 + 4) == -9) {
        *(undefined4 *)(iVar3 + 4) = param_2;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= (int)uVar1);
  }
  return 0;
}



// ============================================================
// Function: bitmap_readRtfHeader (FUN_680ed5a0)
// Address: 680ed5a0
// Size: 37 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readRtfHeader(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    puVar1 = (undefined4 *)xtra_writeValue(param_1,param_2);
    return *puVar1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_readRtfValue (FUN_680ed5d0)
// Address: 680ed5d0
// Size: 42 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readRtfValue(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    iVar1 = xtra_writeValue(param_1,param_2);
    if (iVar1 != 0) {
      return *(undefined4 *)(iVar1 + 4);
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_readRtfTag (FUN_680ed600)
// Address: 680ed600
// Size: 46 bytes
// Params: undefined4 * param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint bitmap_readRtfTag(undefined4 *param_1,int param_2)

{
  uint uVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    uVar1 = xtra_readSerializedBlock(param_1,param_2);
    if (0x2b < uVar1) {
      return uVar1 - 0x28 >> 2;
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_readRtfField (FUN_680ed630)
// Address: 680ed630
// Size: 39 bytes
// Params: undefined4 * param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint bitmap_readRtfField(undefined4 *param_1,int param_2)

{
  uint uVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    uVar1 = xtra_readSerializedBlock(param_1,param_2 + 1);
    return uVar1 >> 3;
  }
  return 0;
}



// ============================================================
// Function: bitmap_getRtfPairValue (FUN_680ed660)
// Address: 680ed660
// Size: 87 bytes
// Params: undefined4 * param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_getRtfPairValue(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    uVar1 = bitmap_readRtfField(param_1,param_2);
    if ((int)uVar1 <= param_3) {
      return 0;
    }
    iVar2 = xtra_writeValue(param_1,param_2 + 1);
    *param_4 = *(undefined4 *)(iVar2 + param_3 * 8);
    param_4[1] = *(undefined4 *)(iVar2 + 4 + param_3 * 8);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_readRtfPair (FUN_680ed6c0)
// Address: 680ed6c0
// Size: 79 bytes
// Params: undefined4 * param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readRtfPair(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    uVar1 = bitmap_readRtfField(param_1,param_2);
    if (param_3 < (int)uVar1) {
      iVar2 = xtra_writeValue(param_1,param_2 + 1);
      *param_4 = *(undefined4 *)(iVar2 + param_3 * 8);
      return 1;
    }
  }
  *param_4 = 0;
  return 0;
}



// ============================================================
// Function: bitmap_getRtfFieldPtr (FUN_680ed710)
// Address: 680ed710
// Size: 46 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_getRtfFieldPtr(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    uVar1 = xtra_writeValue(param_1,param_2 + 1);
    *param_3 = uVar1;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_readRtfEntry (FUN_680ed740)
// Address: 680ed740
// Size: 105 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readRtfEntry(int *param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    uVar1 = bitmap_readRtfField(param_1,param_2);
    iVar2 = xtra_writeValue(param_1,param_2 + 1);
    if (0 < (int)uVar1) {
      piVar3 = (int *)(iVar2 + 4);
      do {
        if (*piVar3 != 0) {
          xtra_readChunk(param_1,*piVar3,0,0);
        }
        piVar3 = piVar3 + 2;
        uVar1 = uVar1 - 1;
      } while (uVar1 != 0);
    }
    xtra_readChunk(param_1,param_2 + 1,0,0);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_resolveRtfField (FUN_680ed7b0)
// Address: 680ed7b0
// Size: 102 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * bitmap_resolveRtfField(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  
  iVar1 = xtra_writeValue(param_1,param_2 + 1);
  if ((param_1 != (int *)0x0) && (-1 < param_2)) {
    iVar2 = xtra_getCurrentValue(param_1);
    if (param_2 < iVar2) {
      uVar3 = bitmap_readRtfField(param_1,param_2);
      if ((param_3 < (int)uVar3) && (iVar2 = *(int *)(iVar1 + 4 + param_3 * 8), iVar2 != 0)) {
        iVar2 = xtra_readSerializedBlock(param_1,iVar2);
        if (iVar2 != 0) {
          puVar4 = xtra_readSerializedPtr(param_1,*(int *)(iVar1 + 4 + param_3 * 8));
          return puVar4;
        }
      }
    }
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: bitmap_getRtfFieldPair (FUN_680ed820)
// Address: 680ed820
// Size: 51 bytes
// Params: int * param_1, int param_2, int param_3, short * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_getRtfFieldPair(int *param_1,int param_2,int param_3,short *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  
  puVar1 = (undefined4 *)media_getVtableFunc(param_1);
  uVar2 = bitmap_getRtfPairValue(puVar1,param_2,param_3,(undefined4 *)param_4);
  media_resolveScoreSprite(param_1,param_4);
  return uVar2;
}



// ============================================================
// Function: bitmap_setRtfTagValue (FUN_680ed860)
// Address: 680ed860
// Size: 30 bytes
// Params: void * this, undefined4 param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall bitmap_setRtfTagValue(void *this,undefined4 param_1)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  
  iVar1 = xtra_writeValue(this,in_EAX);
  if (0 < unaff_ESI) {
    *(undefined4 *)(iVar1 + 0x28 + unaff_ESI * 4) = param_1;
  }
  return 1;
}



// ============================================================
// Function: bitmap_findRtfEntry (FUN_680ed880)
// Address: 680ed880
// Size: 186 bytes
// Params: undefined4 * param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint bitmap_findRtfEntry(undefined4 *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  short extraout_DX;
  uint uVar7;
  uint uVar8;
  
  uVar3 = bitmap_getRtfData(param_1);
  if (uVar3 == 0) {
    return 0;
  }
  uVar7 = 1;
  iVar4 = xtra_writeValue(param_1,1);
  piVar5 = (int *)xtra_writeValue(param_1,param_2);
  iVar1 = *piVar5;
  uVar8 = uVar3 + 1;
  if (1 < (int)(uVar3 + 1)) {
    do {
      uVar3 = (int)(uVar8 + uVar7) / 2;
      iVar2 = *(int *)(iVar4 + uVar3 * 4);
      if (iVar2 == param_2) {
        return uVar3;
      }
      piVar5 = (int *)xtra_writeValue(param_1,iVar2);
      if (*piVar5 <= iVar1) {
        if (*piVar5 == iVar1) {
          bitmap_initRtfParser();
          uVar6 = bitmap_initRtfParser();
          if ((short)uVar6 < extraout_DX) goto LAB_680ed911;
        }
        uVar7 = uVar3 + 1;
        uVar3 = uVar8;
      }
LAB_680ed911:
      uVar8 = uVar3;
    } while ((int)uVar7 < (int)uVar3);
  }
  return (*(int *)(iVar4 + uVar7 * 4) != param_2) - 1 & uVar7;
}



// ============================================================
// Function: bitmap_getRtfEntryData (FUN_680ed940)
// Address: 680ed940
// Size: 60 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_getRtfEntryData(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = xtra_writeValue(param_1,1);
  iVar1 = *(int *)(iVar1 + param_2 * 4);
  puVar2 = (undefined4 *)xtra_writeValue(param_1,iVar1);
  *param_3 = *puVar2;
  *param_4 = puVar2[1];
  *param_5 = puVar2[4];
  return iVar1;
}



// ============================================================
// Function: bitmap_shiftRtfOffsets (FUN_680ed980)
// Address: 680ed980
// Size: 118 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_shiftRtfOffsets(undefined4 *param_1,int param_2,int param_3)
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  uVar1 = bitmap_getRtfData(param_1);
  iVar2 = xtra_writeValue(param_1,1);
  if ((param_3 != 0) && (iVar4 = 1, 0 < (int)uVar1)) {
    while (piVar3 = (int *)xtra_writeValue(param_1,*(int *)(iVar2 + iVar4 * 4)), *piVar3 < param_2) {
      iVar4 = iVar4 + 1;
      if ((int)uVar1 < iVar4) {
        return 0;
      }
    }
    if (0 < iVar4) {
      for (; iVar4 <= (int)uVar1; iVar4 = iVar4 + 1) {
        piVar3 = (int *)xtra_writeValue(param_1,*(int *)(iVar2 + iVar4 * 4));
        *piVar3 = *piVar3 + param_3;
        piVar3[1] = piVar3[1] + param_3;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_findRtfByRange (FUN_680eda00)
// Address: 680eda00
// Size: 110 bytes
// Params: undefined4 * param_1, int param_2, int param_3, int param_4, int param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_findRtfByRange(undefined4 *param_1,int param_2,int param_3,int param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  
  uVar1 = bitmap_getRtfData(param_1);
  if (uVar1 == 0) {
    return 0;
  }
  iVar2 = xtra_writeValue(param_1,1);
  iVar4 = 1;
  if (0 < (int)uVar1) {
    do {
      piVar3 = (int *)xtra_writeValue(param_1,*(int *)(iVar2 + iVar4 * 4));
      if ((((*piVar3 <= param_3) && (param_2 <= piVar3[1])) && (piVar3[4] <= param_4)) &&
         (param_5 <= piVar3[4])) {
        return iVar4;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= (int)uVar1);
  }
  return 0;
}



// ============================================================
// Function: bitmap_getRtfBlockFlag (FUN_680eda70)
// Address: 680eda70
// Size: 38 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_getRtfBlockFlag(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    iVar1 = xtra_writeValue(param_1,param_2);
    return *(undefined4 *)(iVar1 + 0xc);
  }
  return 0;
}



// ============================================================
// Function: bitmap_setRtfBlockFlag (FUN_680edaa0)
// Address: 680edaa0
// Size: 46 bytes
// Params: undefined4 * param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_setRtfBlockFlag(undefined4 *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    iVar1 = xtra_writeValue(param_1,param_2);
    *(undefined4 *)(iVar1 + 0xc) = param_3;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_readRtfBlock (FUN_680edad0)
// Address: 680edad0
// Size: 38 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readRtfBlock(undefined4 *param_1,int param_2)

{
  int iVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    iVar1 = xtra_writeValue(param_1,param_2);
    return *(undefined4 *)(iVar1 + 0x10);
  }
  return 0;
}



// ============================================================
// Function: bitmap_getRtfStyleAttrs (FUN_680edb00)
// Address: 680edb00
// Size: 66 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_getRtfStyleAttrs(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    iVar1 = xtra_writeValue(param_1,param_2);
    *param_3 = *(undefined4 *)(iVar1 + 0x14);
    param_3[1] = *(undefined4 *)(iVar1 + 0x18);
    param_3[2] = *(undefined4 *)(iVar1 + 0x1c);
    param_3[3] = *(undefined4 *)(iVar1 + 0x20);
    param_3[4] = *(undefined4 *)(iVar1 + 0x24);
  }
  return 1;
}



// ============================================================
// Function: bitmap_setRtfStyleAttrs (FUN_680edb50)
// Address: 680edb50
// Size: 93 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_setRtfStyleAttrs(undefined4 *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    iVar1 = xtra_writeValue(param_1,param_2);
    if (param_3 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar1 + 0x14) = *param_3;
      *(undefined4 *)(iVar1 + 0x18) = param_3[1];
      *(undefined4 *)(iVar1 + 0x1c) = param_3[2];
      *(undefined4 *)(iVar1 + 0x20) = param_3[3];
      *(undefined4 *)(iVar1 + 0x24) = param_3[4];
      return 1;
    }
    bitmap_clearRtfStyle();
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_resetRtfDefaults (FUN_680edbb0)
// Address: 680edbb0
// Size: 57 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_resetRtfDefaults(undefined4 *param_1,int param_2)

{
  int extraout_EDX;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    xtra_writeValue(param_1,param_2);
    bitmap_clearRtfStyle();
    *(undefined4 *)(extraout_EDX + 0x18) = 0xfe1fd;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_getRtfNodeData (FUN_680edbf0)
// Address: 680edbf0
// Size: 83 bytes
// Params: undefined4 * param_1, int param_2, undefined4 * param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_getRtfNodeData(undefined4 *param_1,int param_2,undefined4 *param_3,undefined4 *param_4,
                 undefined4 *param_5)
{
  undefined4 *puVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    puVar1 = (undefined4 *)xtra_writeValue(param_1,param_2);
    *param_3 = *puVar1;
    *param_4 = puVar1[1];
    *param_5 = puVar1[4];
    return 0;
  }
  *param_3 = 0;
  *param_4 = 0;
  *param_5 = 0;
  return 0;
}



// ============================================================
// Function: bitmap_writeRtfTag (FUN_680edc50)
// Address: 680edc50
// Size: 76 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_writeRtfTag(undefined4 *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    iVar1 = param_3 * 4 + 0x28;
    iVar2 = xtra_readSerializedBlock(param_1,param_2);
    if (iVar2 < iVar1) {
      return 0;
    }
    iVar2 = xtra_writeValue(param_1,param_2);
    return *(undefined4 *)(iVar1 + iVar2);
  }
  return 0;
}



// ============================================================
// Function: bitmap_writeRtfEntry (FUN_680edca0)
// Address: 680edca0
// Size: 144 bytes
// Params: int * param_1, int param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_writeRtfEntry(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = bitmap_readRtfTag(param_1,param_2);
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    if (param_3 == -1) {
      return true;
    }
    iVar2 = xtra_writeValue(param_1,param_2);
    if ((param_3 != 0) && (param_3 < (int)uVar1)) {
      if (param_3 < (int)(uVar1 - 1)) {
        Ordinal_1129(iVar2 + 0x28 + param_3 * 4,iVar2 + 0x2c + param_3 * 4,
                     (uVar1 - param_3) * 4 + -4);
      }
      uVar1 = xtra_readChunkBlock(param_1,param_2,uVar1 * 4 + 0x24);
      return (short)uVar1 == 0;
    }
  }
  return false;
}



// ============================================================
// Function: bitmap_allocRtfNode (FUN_680edd30)
// Address: 680edd30
// Size: 32 bytes
// Params: int * param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_allocRtfNode(int *param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = xtra_readChunkBlock(param_1,param_2,0x2c);
  return (short)uVar1 == 0;
}



// ============================================================
// Function: bitmap_swapRtfFields (FUN_680edd50)
// Address: 680edd50
// Size: 128 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_swapRtfFields(int *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    iVar3 = xtra_getCurrentValue(param_1);
    if (param_2 < iVar3) {
      uVar4 = bitmap_readRtfField(param_1,param_2);
      if ((((param_3 < (int)uVar4) && (param_4 < (int)uVar4)) && (-1 < param_3)) && (-1 < param_4))
      {
        iVar3 = xtra_writeValue(param_1,param_2 + 1);
        uVar1 = *(undefined4 *)(iVar3 + param_3 * 8);
        uVar2 = *(undefined4 *)(iVar3 + 4 + param_3 * 8);
        *(undefined4 *)(iVar3 + param_3 * 8) = *(undefined4 *)(iVar3 + param_4 * 8);
        *(undefined4 *)(iVar3 + 4 + param_3 * 8) = *(undefined4 *)(iVar3 + 4 + param_4 * 8);
        *(undefined4 *)(iVar3 + param_4 * 8) = uVar1;
        *(undefined4 *)(iVar3 + 4 + param_4 * 8) = uVar2;
        return 1;
      }
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_updateRtfFieldRef (FUN_680eddd0)
// Address: 680eddd0
// Size: 353 bytes
// Params: int * param_1, int param_2, int param_3, uint param_4, undefined4 param_5
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_updateRtfFieldRef(int *param_1,int param_2,int param_3,uint param_4,undefined4 param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  undefined4 *puVar7;
  undefined4 uVar8;
  
  iVar2 = xtra_writeValue(param_1,param_2 + 1);
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    iVar3 = xtra_getCurrentValue(param_1);
    if ((param_2 < iVar3) && ((*(unsigned short *)((char *)&param_5 + 2)) != 0)) {
      uVar4 = bitmap_readRtfField(param_1,param_2);
      if (param_3 < (int)uVar4) {
        if ((*(short *)(iVar2 + param_3 * 8) == (short)param_5) &&
           (*(short *)(iVar2 + 2 + param_3 * 8) == (*(unsigned short *)((char *)&param_5 + 2)))) {
          return true;
        }
        *(undefined4 *)(iVar2 + param_3 * 8) = param_5;
        iVar3 = scoreEngine_setChannelField(param_4,param_5);
        if (iVar3 == 0) {
          iVar3 = 0;
        }
        else {
          iVar3 = scoreEngine_getScoreContext(iVar3);
        }
        iVar5 = bitmap_readRtfBlock(param_1,param_2);
        piVar6 = (int *)stage_collectPropertiesAtFrame(*(int *)(param_4 + 8),iVar3,iVar5 - 5);
        if (piVar6 != (int *)0x0) {
          puVar7 = (undefined4 *)stage_processEventData(*(int *)(param_4 + 8),piVar6);
          if (puVar7 != (undefined4 *)0x0) {
            piVar6 = (int *)(iVar2 + 4 + param_3 * 8);
            if (*(int *)(iVar2 + 4 + param_3 * 8) == 0) {
              iVar2 = xtra_getCurrentValue(param_1);
              *piVar6 = iVar2;
            }
            uVar8 = xtra_readSerializedValue(param_1,*piVar6,puVar7);
            cast_freeHandle(puVar7);
            return (short)uVar8 == 0;
          }
          events_updateMovieNav(*(int *)(param_4 + 8),piVar6);
        }
        iVar2 = *(int *)(iVar2 + 4 + param_3 * 8);
        if (iVar2 != 0) {
          sVar1 = xtra_readChunk(param_1,iVar2,0,0);
          return sVar1 == 0;
        }
        return true;
      }
    }
  }
  return false;
}



// ============================================================
// Function: bitmap_writeRtfFieldData (FUN_680edf40)
// Address: 680edf40
// Size: 166 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 param_4, uint param_5
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_writeRtfFieldData(int *param_1,int param_2,int param_3,undefined4 param_4,uint param_5)

{
  short sVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = xtra_writeValue(param_1,param_2 + 1);
  if (2 < param_2) {
    iVar3 = xtra_getCurrentValue(param_1);
    if (param_2 < iVar3) {
      uVar4 = bitmap_readRtfField(param_1,param_2);
      if (param_3 < (int)uVar4) {
        iVar2 = *(int *)(iVar2 + 4 + param_3 * 8);
        if (iVar2 != 0) {
          sVar1 = xtra_readChunk(param_1,iVar2,param_4,param_5);
          return sVar1 == 0;
        }
        iVar2 = xtra_getCurrentValue(param_1);
        sVar1 = xtra_readChunk(param_1,iVar2,param_4,param_5);
        if (sVar1 == 0) {
          iVar3 = xtra_writeValue(param_1,param_2 + 1);
          *(int *)(iVar3 + 4 + param_3 * 8) = iVar2;
          return true;
        }
      }
    }
  }
  return false;
}



// ============================================================
// Function: bitmap_writeRtfFieldHandle (FUN_680edff0)
// Address: 680edff0
// Size: 57 bytes
// Params: int * param_1, int param_2, int param_3, undefined4 * param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_writeRtfFieldHandle(int *param_1,int param_2,int param_3,undefined4 *param_4)

{
  bool bVar1;
  uint uVar2;
  
  Ordinal_1114(param_4);
  uVar2 = Ordinal_1116(param_4);
  bVar1 = bitmap_writeRtfFieldData(param_1,param_2,param_3,*param_4,uVar2);
  Ordinal_1115(param_4);
  return bVar1;
}



// ============================================================
// Function: bitmap_removeRtfField (FUN_680ee030)
// Address: 680ee030
// Size: 179 bytes
// Params: int * param_1, int param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_removeRtfField(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    iVar1 = xtra_getCurrentValue(param_1);
    if (param_2 < iVar1) {
      uVar2 = bitmap_readRtfField(param_1,param_2);
      if ((int)uVar2 <= param_3) {
        return false;
      }
      iVar3 = param_2 + 1;
      iVar1 = xtra_writeValue(param_1,iVar3);
      iVar1 = *(int *)(iVar1 + 4 + param_3 * 8);
      if (iVar1 != 0) {
        xtra_readChunk(param_1,iVar1,0,0);
      }
      iVar1 = xtra_writeValue(param_1,iVar3);
      if (param_3 < (int)(uVar2 - 1)) {
        iVar1 = iVar1 + param_3 * 8;
        Ordinal_1129(iVar1,iVar1 + 8,(uVar2 - param_3) * 8 + -8);
      }
      uVar2 = xtra_readChunkBlock(param_1,iVar3,uVar2 * 8 - 8);
      return (short)uVar2 == 0;
    }
  }
  return false;
}



// ============================================================
// Function: bitmap_writeRtfName (FUN_680ee0f0)
// Address: 680ee0f0
// Size: 96 bytes
// Params: int * param_1, int param_2, byte * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_writeRtfName(int *param_1,int param_2,byte *param_3)

{
  ushort uVar1;
  short sVar2;
  int iVar3;
  
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    iVar3 = xtra_getCurrentValue(param_1);
    if (param_2 < iVar3) {
      if (*param_3 == 0xff) {
        uVar1 = Ordinal_1201(param_3 + 1);
      }
      else {
        uVar1 = (ushort)*param_3;
      }
      sVar2 = xtra_readChunk(param_1,param_2 + 2,param_3 + 1,(int)(short)uVar1);
      return sVar2 == 0;
    }
  }
  return false;
}



// ============================================================
// Function: bitmap_readRtfName (FUN_680ee150)
// Address: 680ee150
// Size: 147 bytes
// Params: int * param_1, int param_2, undefined1 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readRtfName(int *param_1,int param_2,undefined1 *param_3)

{
  undefined1 *puVar1;
  undefined1 uVar2;
  int iVar3;
  
  puVar1 = param_3 + 1;
  *puVar1 = 0;
  *param_3 = 0;
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    iVar3 = xtra_getCurrentValue(param_1);
    if (param_2 < iVar3) {
      iVar3 = xtra_readChunkData(param_1,param_2 + 2,puVar1,0x3fe);
      param_3[iVar3 + 1] = 0;
      if (iVar3 < 0xff) {
        *param_3 = (char)iVar3;
      }
      else {
        *param_3 = 0xff;
      }
      iVar3 = Ordinal_1201(puVar1);
      param_3[iVar3 + 1] = 0;
      iVar3 = Ordinal_1201(puVar1);
      if (iVar3 < 0xff) {
        uVar2 = Ordinal_1201(puVar1);
        *param_3 = uVar2;
        return 1;
      }
      *param_3 = 0xff;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_searchRtfByName (FUN_680ee1f0)
// Address: 680ee1f0
// Size: 242 bytes
// Params: int * param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_searchRtfByName(int *param_1,int param_2,undefined4 param_3)
{
  short sVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined1 local_408 [1024];
  uint local_8;
  
  uVar2 = bitmap_getRtfData(param_1);
  if (uVar2 == 0) {
    return 0;
  }
  iVar3 = xtra_writeValue(param_1,1);
  iVar6 = 1;
  if (0 < (int)uVar2) {
    do {
      piVar4 = (int *)xtra_writeValue(param_1,*(int *)(iVar3 + iVar6 * 4));
      if (param_2 < *piVar4) break;
      if (param_2 <= piVar4[1]) {
        iVar5 = xtra_readChunkData(param_1,*(int *)(iVar3 + iVar6 * 4) + 2,local_408,0x3fe);
        local_408[iVar5] = 0;
        sVar1 = Ordinal_1208(local_408,param_3);
        if (sVar1 == 0) {
          return 0;
        }
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 <= (int)uVar2);
  }
  return 0;
}



// ============================================================
// Function: bitmap_markRtfDirty (FUN_680ee2f0)
// Address: 680ee2f0
// Size: 82 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_markRtfDirty(undefined4 *param_1)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = bitmap_getRtfData(param_1);
  iVar2 = xtra_writeValue(param_1,1);
  iVar4 = 1;
  if (0 < (int)uVar1) {
    do {
      iVar3 = xtra_writeValue(param_1,*(int *)(iVar2 + iVar4 * 4));
      if ((iVar3 != 0) && ((*(uint *)(iVar3 + 0x18) & 1) != 0)) {
        *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) | 0x180;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 <= (int)uVar1);
  }
  return 0;
}



// ============================================================
// Function: bitmap_getRtfIndexValue (FUN_680ee350)
// Address: 680ee350
// Size: 21 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_getRtfIndexValue(int param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  
  iVar1 = xtra_writeValue(in_EAX,1);
  return *(undefined4 *)(iVar1 + param_1 * 4);
}



// ============================================================
// Function: bitmap_parseRtfNode (FUN_680ee370)
// Address: 680ee370
// Size: 587 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_parseRtfNode(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *unaff_EBX;
  int *piVar6;
  uint local_10;
  uint local_c;
  
  if (unaff_EBX == (undefined4 *)0x0) {
    return 0;
  }
  piVar1 = (int *)xtra_getChunkDataPtr(unaff_EBX,param_2,0x2c);
  if (piVar1 != (int *)0x0) {
    iVar2 = cast_freeIfNonNull(piVar1[2]);
    piVar1[2] = iVar2;
    iVar2 = cast_freeIfNonNull(piVar1[3]);
    piVar1[3] = iVar2;
    iVar2 = cast_freeIfNonNull(piVar1[4]);
    piVar1[4] = iVar2;
    local_10 = bitmap_readRtfField(unaff_EBX,param_2);
    iVar2 = xtra_getChunkDataPtr(unaff_EBX,param_2 + 1,8);
    if (((-1 < (int)local_10) && (-1 < piVar1[4])) && ((iVar2 != 0 || ((int)local_10 < 1)))) {
      local_c = bitmap_readRtfTag(unaff_EBX,param_2);
      iVar3 = cast_freeIfNonNull(*piVar1);
      *piVar1 = iVar3;
      iVar3 = cast_freeIfNonNull(piVar1[1]);
      piVar1[1] = iVar3;
      if ((((0 < (int)local_c) && (-1 < *piVar1)) && (-1 < iVar3)) && (*piVar1 <= iVar3)) {
        if (0 < (int)local_c) {
          piVar6 = piVar1 + 10;
          do {
            iVar3 = cast_freeIfNonNull(*piVar6);
            *piVar6 = iVar3;
            piVar6 = piVar6 + 1;
            local_c = local_c - 1;
          } while (local_c != 0);
        }
        if (0 < (int)local_10) {
          piVar6 = (int *)(iVar2 + 4);
          do {
            uVar4 = cast_allocSmallBlock((uint3)*(ushort *)((int)piVar6 + -2));
            *(short *)((int)piVar6 + -2) = (short)uVar4;
            uVar4 = cast_allocSmallBlock((uint3)*(ushort *)(piVar6 + -1));
            *(short *)(piVar6 + -1) = (short)uVar4;
            iVar2 = cast_freeIfNonNull(*piVar6);
            *piVar6 = iVar2;
            if (iVar2 != 0) {
              uVar5 = xtra_writeValue(unaff_EBX,iVar2);
              iVar2 = xtra_readSerializedBlock(unaff_EBX,*piVar6);
              if ((param_1 != (int *)0x0) &&
                 (uVar4 = rendering_updateChannelState((int)(param_1 + 0x123)), uVar4 < 0x1100)) {
                playback_renderSpriteEx(*(int *)(*param_1 + 0x18),(int)(param_1 + 0x143),uVar5,iVar2);
              }
            }
            piVar6 = piVar6 + 2;
            local_10 = local_10 - 1;
          } while (local_10 != 0);
        }
        uVar5 = xtra_writeValue(unaff_EBX,param_2 + 2);
        iVar2 = xtra_readSerializedBlock(unaff_EBX,param_2 + 2);
        if ((param_1 != (int *)0x0) &&
           (uVar4 = rendering_updateChannelState((int)(param_1 + 0x123)), uVar4 < 0x1100)) {
          playback_renderSpriteEx(*(int *)(*param_1 + 0x18),(int)(param_1 + 0x143),uVar5,iVar2);
        }
        iVar2 = cast_freeIfNonNull(piVar1[5]);
        piVar1[5] = iVar2;
        iVar2 = cast_freeIfNonNull(piVar1[6]);
        piVar1[6] = iVar2;
        iVar2 = cast_freeIfNonNull(piVar1[7]);
        piVar1[7] = iVar2;
        iVar2 = cast_freeIfNonNull(piVar1[8]);
        piVar1[8] = iVar2;
        iVar2 = cast_freeIfNonNull(piVar1[9]);
        piVar1[9] = iVar2;
        if (param_3 != 0) {
          bitmap_validateRtfNode(unaff_EBX,param_2,1);
        }
        return 1;
      }
      *piVar1 = 0;
      piVar1[1] = 0;
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_byteSwapRtfNode (FUN_680ee5c0)
// Address: 680ee5c0
// Size: 298 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_byteSwapRtfNode(undefined4 *param_1,int param_2)
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  int *piVar7;
  
  if (param_1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)xtra_writeValue(param_1,param_2);
    uVar2 = bitmap_readRtfField(param_1,param_2);
    iVar3 = xtra_writeValue(param_1,param_2 + 1);
    uVar4 = bitmap_readRtfTag(param_1,param_2);
    uVar5 = cast_freeIfNonNull(*puVar1);
    *puVar1 = uVar5;
    uVar5 = cast_freeIfNonNull(puVar1[1]);
    puVar1[1] = uVar5;
    if (0 < (int)uVar4) {
      puVar6 = puVar1 + 10;
      do {
        uVar5 = cast_freeIfNonNull(*puVar6);
        *puVar6 = uVar5;
        puVar6 = puVar6 + 1;
        uVar4 = uVar4 - 1;
      } while (uVar4 != 0);
    }
    if (0 < (int)uVar2) {
      piVar7 = (int *)(iVar3 + 4);
      do {
        uVar4 = cast_allocSmallBlock((uint3)*(ushort *)((int)piVar7 + -2));
        *(short *)((int)piVar7 + -2) = (short)uVar4;
        uVar4 = cast_allocSmallBlock((uint3)*(ushort *)(piVar7 + -1));
        *(short *)(piVar7 + -1) = (short)uVar4;
        if (*piVar7 != 0) {
          iVar3 = cast_freeIfNonNull(*piVar7);
          *piVar7 = iVar3;
        }
        piVar7 = piVar7 + 2;
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    uVar5 = cast_freeIfNonNull(puVar1[5]);
    puVar1[5] = uVar5;
    uVar5 = cast_freeIfNonNull(puVar1[6]);
    puVar1[6] = uVar5;
    uVar5 = cast_freeIfNonNull(puVar1[7]);
    puVar1[7] = uVar5;
    uVar5 = cast_freeIfNonNull(puVar1[8]);
    puVar1[8] = uVar5;
    uVar5 = cast_freeIfNonNull(puVar1[9]);
    puVar1[9] = uVar5;
    uVar5 = cast_freeIfNonNull(puVar1[4]);
    puVar1[4] = uVar5;
    uVar5 = cast_freeIfNonNull(puVar1[3]);
    puVar1[3] = uVar5;
    uVar5 = cast_freeIfNonNull(puVar1[2]);
    puVar1[2] = uVar5;
    bitmap_validateRtfNode(param_1,param_2,0);
  }
  return 0;
}



// ============================================================
// Function: bitmap_insertRtfSorted (FUN_680ee6f0)
// Address: 680ee6f0
// Size: 219 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_insertRtfSorted(int *param_1,int param_2,int param_3)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  undefined3 extraout_var;
  int *piVar4;
  int *piVar5;
  undefined4 uVar6;
  short extraout_DX;
  int iVar7;
  int iVar8;
  int local_8;
  
  uVar2 = bitmap_getRtfCapacity(param_1);
  uVar3 = bitmap_getRtfData(param_1);
  if (((int)uVar2 <= (int)(uVar3 + 1)) &&
     (bVar1 = bitmap_resizeRtfBlock(param_1,uVar2 + 0x200), CONCAT31(extraout_var,bVar1) == 0)) {
    return 0;
  }
  piVar4 = (int *)xtra_writeValue(param_1,1);
  *piVar4 = *piVar4 + 1;
  local_8 = uVar3 + 1;
  iVar8 = 1;
  if (1 < local_8) {
    do {
      iVar7 = (local_8 + iVar8) / 2;
      piVar5 = (int *)xtra_writeValue(param_1,piVar4[iVar7]);
      if (*piVar5 <= param_3) {
        if (*piVar5 == param_3) {
          bitmap_initRtfParser();
          uVar6 = bitmap_initRtfParser();
          if ((short)uVar6 < extraout_DX) goto LAB_680ee794;
        }
        iVar8 = iVar7 + 1;
        iVar7 = local_8;
      }
LAB_680ee794:
      local_8 = iVar7;
    } while (iVar8 < local_8);
  }
  if (iVar8 < (int)(uVar3 + 1)) {
    Ordinal_1129(piVar4 + iVar8 + 1,piVar4 + iVar8,(uVar3 - iVar8) * 4 + 4);
  }
  piVar4[iVar8] = param_2;
  return 1;
}



// ============================================================
// Function: bitmap_reorderRtfEntry (FUN_680ee7d0)
// Address: 680ee7d0
// Size: 297 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_reorderRtfEntry(undefined4 *param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  short extraout_CX;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar5 = -9;
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    uVar1 = bitmap_getRtfData(param_1);
    if (uVar1 == 1) {
      return 1;
    }
    iVar2 = xtra_writeValue(param_1,1);
    iVar6 = 1;
    iVar7 = -9;
    if (0 < (int)uVar1) {
      do {
        piVar3 = (int *)xtra_writeValue(param_1,*(int *)(iVar2 + iVar6 * 4));
        iVar8 = iVar6;
        if ((*(int *)(iVar2 + iVar6 * 4) != param_2) && (iVar8 = iVar7, iVar5 == -9)) {
          if (param_3 < *piVar3) {
LAB_680ee867:
            iVar5 = iVar6;
          }
          else if (*piVar3 == param_3) {
            bitmap_initRtfParser();
            uVar4 = bitmap_initRtfParser();
            if ((short)uVar4 < extraout_CX) goto LAB_680ee867;
          }
        }
      } while (((iVar8 == -9) || (iVar5 == -9)) &&
              (iVar6 = iVar6 + 1, iVar7 = iVar8, iVar6 <= (int)uVar1));
      if (iVar8 != -9) {
        if (iVar5 == -9) {
          iVar5 = iVar6;
        }
        if (iVar8 == iVar5 + -1) {
          return 1;
        }
        if (iVar5 <= iVar8) {
          piVar3 = (int *)(iVar2 + iVar5 * 4);
          Ordinal_1129(piVar3 + 1,piVar3,(iVar8 - iVar5) * 4);
          *piVar3 = param_2;
          return 1;
        }
        iVar7 = iVar2 + iVar8 * 4;
        Ordinal_1129(iVar7,iVar7 + 4,(iVar5 - iVar8) * 4 + -4);
        *(int *)(iVar2 + -4 + iVar5 * 4) = param_2;
        return 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_removeRtfByIndex (FUN_680ee900)
// Address: 680ee900
// Size: 81 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_removeRtfByIndex(void)

{
  undefined4 *in_EAX;
  uint uVar1;
  int *piVar2;
  uint uVar3;
  int unaff_EBX;
  
  uVar1 = bitmap_getRtfData(in_EAX);
  piVar2 = (int *)xtra_writeValue(in_EAX,1);
  uVar3 = 1;
  if (0 < (int)uVar1) {
    do {
      if (piVar2[uVar3] == unaff_EBX) {
        if (uVar3 != uVar1) {
          Ordinal_1129(piVar2 + uVar3,piVar2 + uVar3 + 1,(uVar1 - uVar3) * 4);
        }
        *piVar2 = *piVar2 + -1;
        return 1;
      }
      uVar3 = uVar3 + 1;
    } while ((int)uVar3 <= (int)uVar1);
  }
  return 0;
}



// ============================================================
// Function: bitmap_appendRtfField (FUN_680ee960)
// Address: 680ee960
// Size: 194 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_appendRtfField(undefined4 param_1,undefined4 *param_2)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined4 uVar5;
  int *unaff_ESI;
  bool bVar6;
  
  if (((unaff_ESI != (int *)0x0) && ((short)((uint)param_1 >> 0x10) != 0)) && (2 < in_EAX)) {
    iVar2 = xtra_getCurrentValue(unaff_ESI);
    if (in_EAX < iVar2) {
      uVar3 = bitmap_readRtfField(unaff_ESI,in_EAX);
      uVar4 = xtra_readChunkBlock(unaff_ESI,in_EAX + 1,uVar3 * 8 + 8);
      bVar6 = (short)uVar4 == 0;
      if (!bVar6) {
        return bVar6;
      }
      iVar2 = xtra_writeValue(unaff_ESI,in_EAX + 1);
      *(undefined4 *)(iVar2 + uVar3 * 8) = param_1;
      piVar1 = (int *)(iVar2 + 4 + uVar3 * 8);
      *piVar1 = 0;
      if (param_2 != (undefined4 *)0x0) {
        iVar2 = xtra_getCurrentValue(unaff_ESI);
        *piVar1 = iVar2;
        uVar5 = xtra_readSerializedValue(unaff_ESI,iVar2,param_2);
        return (short)uVar5 == 0;
      }
      *piVar1 = 0;
      return bVar6;
    }
  }
  return false;
}



// ============================================================
// Function: bitmap_populateRtfFields (FUN_680eea30)
// Address: 680eea30
// Size: 236 bytes
// Params: int * param_1, int param_2, int param_3, int param_4, int * param_5
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_populateRtfFields(int *param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  bool bVar9;
  
  piVar1 = param_1;
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    iVar2 = xtra_getCurrentValue(param_1);
    if (param_2 < iVar2) {
      bitmap_readRtfEntry(param_1,param_2);
      iVar2 = param_2 + 1;
      uVar3 = xtra_readChunkBlock(param_1,iVar2,param_3 * 8);
      bVar9 = (short)uVar3 == 0;
      if (!bVar9) {
        return bVar9;
      }
      piVar4 = (int *)xtra_writeValue(param_1,iVar2);
      iVar8 = 0;
      if (0 < param_3) {
        iVar7 = param_4 - (int)param_5;
        param_1 = piVar4;
        do {
          piVar4[iVar8 * 2] = *(int *)(iVar7 + (int)param_5);
          if ((*param_5 == 0) || (!bVar9)) {
            piVar4[iVar8 * 2 + 1] = 0;
          }
          else {
            iVar5 = xtra_getCurrentValue(piVar1);
            param_1[iVar8 * 2 + 1] = iVar5;
            uVar6 = xtra_readSerializedValue(piVar1,iVar5,(undefined4 *)*param_5);
            bVar9 = (short)uVar6 == 0;
            piVar4 = (int *)xtra_writeValue(piVar1,iVar2);
            param_1 = piVar4;
          }
          iVar8 = iVar8 + 1;
          param_5 = param_5 + 1;
        } while (iVar8 < param_3);
      }
      return bVar9;
    }
  }
  return false;
}



// ============================================================
// Function: bitmap_readRtfSequence (FUN_680eeb20)
// Address: 680eeb20
// Size: 156 bytes
// Params: undefined4 * param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readRtfSequence(undefined4 *param_1,int *param_2,int param_3)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  puVar1 = (uint *)xtra_writeValue(param_1,1);
  if (puVar1 == (uint *)0x0) {
    return 0;
  }
  uVar2 = cast_freeIfNonNull(*puVar1);
  *puVar1 = uVar2;
  iVar3 = xtra_readSerializedBlock(param_1,1);
  if (3 < iVar3) {
    uVar5 = iVar3 - 4U >> 2;
  }
  if ((-1 < (int)uVar2) && ((int)uVar2 <= (int)uVar5)) {
    iVar3 = 1;
    if (0 < (int)uVar2) {
      do {
        uVar5 = cast_freeIfNonNull(puVar1[iVar3]);
        puVar1[iVar3] = uVar5;
        iVar4 = bitmap_parseRtfNode(param_2,uVar5,param_3);
        if (iVar4 == 0) {
          return 0;
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 <= (int)uVar2);
    }
    return 1;
  }
  *puVar1 = uVar5;
  return 0;
}



// ============================================================
// Function: bitmap_mergeRtfEntries (FUN_680eebd0)
// Address: 680eebd0
// Size: 75 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_mergeRtfEntries(undefined4 *param_1)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  piVar2 = (int *)xtra_writeValue(param_1,1);
  iVar1 = *piVar2;
  iVar3 = cast_freeIfNonNull(iVar1);
  iVar4 = 1;
  *piVar2 = iVar3;
  if (0 < iVar1) {
    do {
      bitmap_byteSwapRtfNode(param_1,piVar2[iVar4]);
      iVar3 = cast_freeIfNonNull(piVar2[iVar4]);
      piVar2[iVar4] = iVar3;
      iVar4 = iVar4 + 1;
    } while (iVar4 <= iVar1);
  }
  return 0;
}



// ============================================================
// Function: bitmap_getRtfByte (FUN_680eec20)
// Address: 680eec20
// Size: 188 bytes
// Params: int * param_1, int param_2
// Return: byte
// Calling convention: __stdcall
// ============================================================

byte bitmap_getRtfByte(int *param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  short sVar3;
  short sVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  
  iVar1 = param_2;
  uVar5 = bitmap_readRtfField(param_1,param_2);
  sVar3 = xtra_readChunk(param_1,param_2,0,0);
  bVar7 = sVar3 == 0;
  param_2 = 0;
  if (0 < (int)uVar5) {
    do {
      iVar6 = xtra_writeValue(param_1,iVar1 + 1);
      iVar6 = *(int *)(iVar6 + 4 + param_2 * 8);
      if (iVar6 != 0) {
        sVar3 = xtra_readChunk(param_1,iVar6,0,0);
        bVar7 = sVar3 == 0;
      }
      param_2 = param_2 + 1;
    } while (param_2 < (int)uVar5);
  }
  sVar3 = xtra_readChunk(param_1,iVar1 + 1,0,0);
  sVar4 = xtra_readChunk(param_1,iVar1 + 2,0,0);
  bVar2 = bitmap_splitRtfNode(param_1,iVar1);
  bitmap_removeRtfByIndex();
  return bVar7 & sVar3 == 0 & sVar4 == 0 & bVar2;
}



// ============================================================
// Function: bitmap_writeRtfRange (FUN_680eece0)
// Address: 680eece0
// Size: 212 bytes
// Params: undefined4 * param_1, int param_2, short * param_3, int param_4, int param_5, int param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
bitmap_writeRtfRange(undefined4 *param_1,int param_2,short *param_3,int param_4,int param_5,int param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  short *psVar5;
  short *local_c;
  undefined4 local_8;
  
  puVar1 = param_1;
  uVar2 = bitmap_getRtfData(param_1);
  local_8 = 0;
  Ordinal_1114(param_1);
  param_1 = (undefined4 *)0x1;
  if (0 < (int)uVar2) {
    do {
      iVar3 = bitmap_readRtfInt(puVar1,(int)param_1);
      uVar4 = bitmap_readRtfField(puVar1,iVar3);
      if ((0 < (int)uVar4) &&
         (bitmap_getRtfFieldPtr(puVar1,iVar3,&local_c), psVar5 = local_c, 0 < (int)uVar4)) {
        do {
          if (psVar5[1] != 0) {
            if (param_6 == 0) {
              rendering_resolveChannelHeight(psVar5,param_5);
            }
            else if (param_6 == 1) {
              rendering_setChannelRect(param_2,param_3,param_5,*psVar5);
            }
            else if (param_6 == 2) {
              rendering_getChannelIndex(param_4,*psVar5);
            }
            local_8 = 1;
          }
          uVar4 = uVar4 - 1;
          psVar5 = psVar5 + 4;
        } while (uVar4 != 0);
      }
      param_1 = (undefined4 *)((int)param_1 + 1);
    } while ((int)param_1 <= (int)uVar2);
  }
  Ordinal_1115(puVar1);
  return local_8;
}



// ============================================================
// Function: bitmap_setRtfProperty (FUN_680eedc0)
// Address: 680eedc0
// Size: 73 bytes
// Params: undefined4 * param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_setRtfProperty(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  int *piVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    piVar1 = (int *)xtra_writeValue(param_1,param_2);
    *piVar1 = param_3;
    piVar1[4] = param_4;
    piVar1[10] = 0;
    bitmap_reorderRtfEntry(param_1,param_2,param_3);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_isRtfValid (FUN_680eee10)
// Address: 680eee10
// Size: 151 bytes
// Params: int * param_1, int param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_isRtfValid(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  iVar1 = param_2;
  uVar2 = bitmap_readRtfTag(param_1,param_2);
  (*(unsigned char *)((char *)&param_2 + 0)) = true;
  if ((param_1 != (int *)0x0) && (2 < iVar1)) {
    piVar3 = (int *)xtra_writeValue(param_1,iVar1);
    if (*piVar3 <= param_3) {
      piVar3[1] = param_3;
      if (uVar2 == 1) {
        return true;
      }
      iVar5 = 1;
      if (1 < (int)uVar2) {
        piVar4 = piVar3 + 0xb;
        while (*piVar4 <= param_3 - *piVar3) {
          iVar5 = iVar5 + 1;
          piVar4 = piVar4 + 1;
          if ((int)uVar2 <= iVar5) {
            return true;
          }
        }
        uVar2 = xtra_readChunkBlock(param_1,iVar1,iVar5 * 4 + 0x28);
        (*(unsigned char *)((char *)&param_2 + 0)) = (short)uVar2 == 0;
      }
      return (*(unsigned char *)((char *)&param_2 + 0));
    }
  }
  return false;
}



// ============================================================
// Function: bitmap_validateRtfRange (FUN_680eeeb0)
// Address: 680eeeb0
// Size: 256 bytes
// Params: int * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_validateRtfRange(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  int *piVar7;
  
  piVar1 = param_1;
  uVar3 = bitmap_readRtfTag(param_1,param_2);
  param_1 = (int *)0xffffffff;
  if ((piVar1 != (int *)0x0) && (2 < param_2)) {
    if (param_3 < 1) {
      return 0;
    }
    iVar4 = xtra_writeValue(piVar1,param_2);
    piVar7 = (int *)0x1;
    if (1 < (int)uVar3) {
      piVar6 = (int *)(iVar4 + 0x2c);
      do {
        iVar2 = *piVar6;
        if (iVar2 == -9) {
          *(int *)(iVar4 + 0x28 + (int)piVar7 * 4) = param_3;
          return (int)piVar7;
        }
        if (iVar2 == param_3) {
          return (int)piVar7;
        }
        if (param_3 <= iVar2) {
          uVar5 = xtra_readChunkBlock(piVar1,param_2,uVar3 * 4 + 0x2c);
          if ((short)uVar5 != 0) {
            return -1;
          }
          iVar4 = xtra_writeValue(piVar1,param_2);
          piVar1 = (int *)(iVar4 + 0x28 + (int)piVar7 * 4);
          Ordinal_1129(iVar4 + 0x2c + (int)piVar7 * 4,piVar1,(uVar3 - (int)piVar7) * 4);
          *piVar1 = param_3;
          return (int)piVar7;
        }
        piVar7 = (int *)((int)piVar7 + 1);
        piVar6 = piVar6 + 1;
      } while ((int)piVar7 < (int)uVar3);
    }
    uVar3 = xtra_readChunkBlock(piVar1,param_2,uVar3 * 4 + 0x2c);
    if ((short)uVar3 == 0) {
      iVar4 = xtra_writeValue(piVar1,param_2);
      *(int *)(iVar4 + 0x28 + (int)piVar7 * 4) = param_3;
      param_1 = piVar7;
    }
  }
  return (int)param_1;
}



// ============================================================
// Function: bitmap_setRtfValue (FUN_680eefb0)
// Address: 680eefb0
// Size: 273 bytes
// Params: undefined4 * param_1, int param_2, int param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_setRtfValue(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = (undefined4 *)0x0;
  if (param_3 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(param_3 + 0x20);
    if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
      if ((piVar4 == (int *)0x0) || (iVar1 = *piVar4, iVar1 == 0)) {
        iVar1 = *piVar4;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  iVar1 = scoreEngine_setChannelField((uint)piVar4,param_4);
  if (iVar1 == 0) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    if ((*(int **)(iVar1 + 0x4c) != (int *)0x0) &&
       (iVar3 = *(int *)(**(int **)(iVar1 + 0x4c) + 4), iVar3 < 0)) {
      iVar3 = 0;
    }
  }
  iVar1 = bitmap_readRtfBlock(param_1,param_2);
  if ((4 < iVar1) && (piVar2 = (int *)stage_collectPropertiesAtFrame(piVar4[2],iVar3,iVar1 - 5), piVar2 != (int *)0x0)
     ) {
    local_18 = (undefined4 *)stage_processEventData(piVar4[2],piVar2);
    events_updateMovieNav(piVar4[2],piVar2);
  }
  bitmap_appendRtfField(param_4,local_18);
  if (local_18 != (undefined4 *)0x0) {
    cast_freeHandle(local_18);
  }
  if (piVar4 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: bitmap_readRtfRange (FUN_680ef0d0)
// Address: 680ef0d0
// Size: 386 bytes
// Params: int * param_1, int param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_readRtfRange(int *param_1,int param_2,int *param_3,int param_4)
{
  bool bVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined3 extraout_var;
  undefined4 local_420;
  uint local_41c;
  int local_418;
  int local_414;
  int local_410;
  int *local_40c;
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  local_418 = param_2;
  local_40c = param_3;
  local_410 = param_4;
  iVar3 = xtra_writeValue(param_1,param_2);
  iVar4 = xtra_writeValue(local_40c,local_410);
  *(undefined4 *)(iVar4 + 0xc) = *(undefined4 *)(iVar3 + 0xc);
  *(undefined4 *)(iVar4 + 0x14) = *(undefined4 *)(iVar3 + 0x14);
  *(undefined4 *)(iVar4 + 0x18) = *(undefined4 *)(iVar3 + 0x18);
  *(undefined4 *)(iVar4 + 0x1c) = *(undefined4 *)(iVar3 + 0x1c);
  *(undefined4 *)(iVar4 + 0x20) = *(undefined4 *)(iVar3 + 0x20);
  *(undefined4 *)(iVar4 + 0x24) = *(undefined4 *)(iVar3 + 0x24);
  *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar3 + 8);
  local_41c = bitmap_readRtfField(param_1,param_2);
  if ((0 < (int)local_41c) && (local_414 = 0, 0 < (int)local_41c)) {
    do {
      iVar3 = local_414;
      iVar4 = bitmap_readRtfPair(param_1,param_2,local_414,&local_420);
      if (iVar4 == 0) {
        puVar5 = (undefined4 *)0x0;
      }
      else {
        puVar5 = bitmap_resolveRtfField(param_1,param_2,iVar3);
      }
      bVar1 = bitmap_appendRtfField(local_420,puVar5);
      if (puVar5 != (undefined4 *)0x0) {
        cast_freeHandle(puVar5);
      }
      param_2 = local_418;
    } while ((CONCAT31(extraout_var,bVar1) != 0) &&
            (local_414 = local_414 + 1, local_414 < (int)local_41c));
  }
  iVar3 = bitmap_readRtfName(param_1,param_2,&local_408);
  if (iVar3 != 0) {
    if (local_408 == 0xff) {
      uVar2 = Ordinal_1201(local_407);
    }
    else {
      uVar2 = (ushort)local_408;
    }
    if (0 < (short)uVar2) {
      bitmap_writeRtfName(local_40c,local_410,&local_408);
    }
  }
  bitmap_repairRtfData(param_1,param_2,local_40c,local_410);
  return 0;
}



// ============================================================
// Function: bitmap_readRtfSection (FUN_680ef260)
// Address: 680ef260
// Size: 152 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_readRtfSection(int *param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar2 = bitmap_readRtfHeader(param_1,param_2);
  iVar1 = iVar2 + param_3;
  uVar3 = bitmap_readRtfTag(param_1,param_2);
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    iVar4 = bitmap_readRtfBlock(param_1,param_2);
    bitmap_setRtfProperty(param_1,param_2,iVar1,iVar4);
    while (uVar3 = uVar3 - 1, 0 < (int)uVar3) {
      iVar4 = bitmap_writeRtfTag(param_1,param_2,uVar3);
      if (iVar1 < iVar4 + iVar2) {
        bitmap_setRtfTagValue(param_1,iVar4 + (iVar2 - iVar1));
      }
      else {
        bitmap_writeRtfEntry(param_1,param_2,uVar3);
      }
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_compactRtfData (FUN_680ef300)
// Address: 680ef300
// Size: 246 bytes
// Params: int * param_1, int param_2, int param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int bitmap_compactRtfData(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int local_8;
  
  local_8 = -1;
  if (param_3 != -1) {
    if (param_3 < 1) {
      bitmap_readRtfSection(param_1,param_2,param_4);
      local_8 = 0;
    }
    else {
      iVar3 = bitmap_writeRtfTag(param_1,param_2,param_3);
      if ((iVar3 != param_4) && (0 < param_4)) {
        uVar4 = bitmap_readRtfTag(param_1,param_2);
        if (param_3 == uVar4 - 1) {
          piVar5 = (int *)xtra_writeValue(param_1,param_2);
          iVar1 = *piVar5;
          iVar2 = piVar5[param_3 + 10];
          iVar3 = piVar5[1];
          uVar4 = xtra_readChunkBlock(param_1,param_2,param_3 * 4 + 0x28);
          if ((short)uVar4 != 0) {
            return -1;
          }
          if (iVar2 + iVar1 == iVar3) {
            bitmap_isRtfValid(param_1,param_2,iVar1 + param_4);
            iVar3 = bitmap_validateRtfRange(param_1,param_2,param_4);
            return iVar3;
          }
        }
        else {
          bitmap_writeRtfEntry(param_1,param_2,param_3);
        }
        iVar3 = bitmap_validateRtfRange(param_1,param_2,param_4);
        return iVar3;
      }
    }
  }
  return local_8;
}



// ============================================================
// Function: bitmap_expandRtfData (FUN_680ef400)
// Address: 680ef400
// Size: 522 bytes
// Params: int * param_1, int param_2, uint param_3, int param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_expandRtfData(int *param_1,int param_2,uint param_3,int param_4,undefined4 param_5)
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  undefined4 *puVar6;
  int *piVar7;
  int local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if ((((param_1 != (int *)0x0) && ((short)((uint)param_5 >> 0x10) != 0)) && (2 < param_2)) &&
     (iVar2 = xtra_getCurrentValue(param_1), param_2 < iVar2)) {
    uVar3 = bitmap_readRtfField(param_1,param_2);
    if ((uVar3 != 0) && (param_3 != uVar3)) {
      if ((int)param_3 < (int)uVar3) {
        uVar4 = xtra_readChunkBlock(param_1,param_2 + 1,uVar3 * 8 + 8);
        if ((short)uVar4 == 0) {
          iVar2 = xtra_writeValue(param_1,param_2 + 1);
          puVar1 = (undefined4 *)(iVar2 + param_3 * 8);
          Ordinal_1129(puVar1 + 2,puVar1,(uVar3 - param_3) * 8);
          *puVar1 = param_5;
          if (param_4 == 0) {
            piVar7 = (int *)0x0;
          }
          else {
            piVar7 = *(int **)(param_4 + 0x20);
            if ((piVar7 != (int *)0x0) && (piVar7[1] != 0)) {
              if ((piVar7 == (int *)0x0) || (local_18 = *piVar7, local_18 == 0)) {
                local_18 = *piVar7;
              }
              Ordinal_2330();
              local_14 = local_18;
              local_c = 0;
              local_10 = DAT_68196374;
              DAT_68196374 = &local_14;
            }
          }
          iVar2 = scoreEngine_setChannelField((uint)piVar7,param_5);
          if (iVar2 == 0) {
            local_1c = 0;
          }
          else {
            local_1c = scoreEngine_getScoreContext(iVar2);
          }
          iVar2 = bitmap_readRtfBlock(param_1,param_2);
          piVar5 = (int *)stage_collectPropertiesAtFrame(piVar7[2],local_1c,iVar2 - 5);
          if (piVar5 == (int *)0x0) {
            puVar1[1] = 0;
          }
          else {
            puVar6 = (undefined4 *)stage_processEventData(piVar7[2],piVar5);
            if (puVar6 != (undefined4 *)0x0) {
              iVar2 = xtra_getCurrentValue(param_1);
              puVar1[1] = iVar2;
              xtra_readSerializedValue(param_1,iVar2,puVar6);
              cast_freeHandle(puVar6);
            }
            events_updateMovieNav(piVar7[2],piVar5);
          }
          DAT_68196374 = local_10;
          Ordinal_2331();
          return 0;
        }
      }
      return 0;
    }
    bitmap_setRtfValue(param_1,param_2,param_4,param_5);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: bitmap_writeRtfChunk (FUN_680ef610)
// Address: 680ef610
// Size: 314 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_writeRtfChunk(int *param_1,undefined4 param_2,int param_3)
{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 local_38;
  int local_34 [10];
  undefined4 local_c;
  uint local_8;
  
  local_38 = 0xffffffff;
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar2 = xtra_getCurrentValue(param_1);
  iVar3 = xtra_getCurrentValue(param_1);
  iVar4 = xtra_getCurrentValue(param_1);
  iVar5 = xtra_getCurrentValue(param_1);
  local_34[3] = 0;
  local_34[2] = 0;
  local_c = 0;
  local_34[4] = param_2;
  local_34[0] = param_3;
  local_34[1] = 0xfffffff7;
  bitmap_clearRtfStyle();
  sVar1 = xtra_readChunk(param_1,iVar2,local_34,0x2c);
  if (sVar1 == 0) {
    sVar1 = xtra_readChunk(param_1,iVar3 + 1,&local_38,4);
    if (sVar1 == 0) {
      sVar1 = xtra_readChunk(param_1,iVar4 + 2,&local_38,4);
      if (sVar1 == 0) {
        sVar1 = xtra_readChunk(param_1,iVar5 + 3,&local_38,4);
        if (sVar1 == 0) {
          xtra_readChunk(param_1,iVar5 + 3,0,0);
          xtra_readChunk(param_1,iVar3 + 1,0,0);
          xtra_readChunk(param_1,iVar4 + 2,0,0);
          iVar3 = bitmap_insertRtfSorted(param_1,iVar2,param_3);
          if (iVar3 != 0) {
            return 0;
          }
          bitmap_getRtfByte(param_1,iVar2);
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_serializeRtfNode (FUN_680ef750)
// Address: 680ef750
// Size: 712 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_serializeRtfNode(int *param_1,int *param_2,undefined4 *param_3)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  int iVar11;
  int iVar12;
  int local_18;
  undefined4 local_8;
  
  piVar1 = param_1;
  local_8 = 0;
  param_1 = xtra_readSerializedPtr(param_1,0);
  piVar2 = param_2;
  if (param_1 != (int *)0x0) {
    xtra_readSerializedValue(param_2,0,param_1);
    Ordinal_1113(&param_1);
  }
  xtra_readChunk(piVar2,1,&local_8,4);
  bitmap_resizeRtfBlock(piVar2,0x200);
  puVar3 = (undefined4 *)xtra_writeValue(piVar2,1);
  if (puVar3 != (undefined4 *)0x0) {
    *puVar3 = 0;
  }
  xtra_readChunk(piVar2,2,&local_8,4);
  param_1 = xtra_readSerializedPtr(piVar1,2);
  if (param_1 != (int *)0x0) {
    xtra_readSerializedValue(piVar2,2,param_1);
    Ordinal_1113(&param_1);
  }
  uVar4 = bitmap_getRtfData(piVar1);
  local_18 = 1;
  if ((int)uVar4 < 1) {
    return 1;
  }
  param_3 = param_3 + 1;
  while( true ) {
    param_1 = (int *)bitmap_getRtfIndexValue(local_18);
    piVar5 = (int *)xtra_writeValue(piVar1,(int)param_1);
    if (piVar5 != (int *)0x0) break;
LAB_680ef9ce:
    param_3 = param_3 + 2;
    local_18 = local_18 + 1;
    if ((int)uVar4 < local_18) {
      return 1;
    }
  }
  do {
    iVar6 = xtra_getCurrentValue(piVar2);
    iVar11 = 1;
    while (iVar7 = bitmap_getRtfIndexValue(iVar11), iVar6 != iVar7) {
      iVar11 = iVar11 + 1;
      if ((int)uVar4 < iVar11) {
        param_2 = (int *)bitmap_writeRtfChunk(piVar2,piVar5[4],*piVar5);
        uVar8 = xtra_readSerializedBlock(piVar1,(int)param_1);
        xtra_readChunk(piVar2,(int)param_2,piVar5,uVar8);
        uVar8 = xtra_readSerializedBlock(piVar1,(int)param_1 + 1);
        uVar9 = xtra_writeValue(piVar1,(int)param_1 + 1);
        xtra_readChunk(piVar2,(int)param_2 + 1,uVar9,uVar8);
        uVar8 = bitmap_readRtfField(piVar1,(int)param_1);
        iVar6 = 0;
        if (0 < (int)uVar8) {
          do {
            iVar11 = xtra_writeValue(piVar1,(int)param_1 + 1);
            if (*(int *)(iVar11 + 4 + iVar6 * 8) != 0) {
              iVar7 = xtra_writeValue(piVar2,(int)param_2 + 1);
              uVar9 = xtra_getCurrentValue(piVar2);
              *(undefined4 *)(iVar7 + 4 + iVar6 * 8) = uVar9;
              puVar3 = xtra_readSerializedPtr(piVar1,*(int *)(iVar11 + 4 + iVar6 * 8));
              iVar12 = 0;
              iVar11 = xtra_readSerializedBlock(piVar1,*(int *)(iVar11 + 4 + iVar6 * 8));
              puVar10 = (undefined4 *)playback_mapFont((int)puVar3,0,iVar11,iVar12);
              if (puVar10 != (undefined4 *)0x0) {
                xtra_readSerializedValue(piVar2,*(int *)(iVar7 + 4 + iVar6 * 8),puVar10);
                cast_freeHandle(puVar10);
              }
              if (puVar3 != (undefined4 *)0x0) {
                cast_freeHandle(puVar3);
              }
            }
            iVar6 = iVar6 + 1;
          } while (iVar6 < (int)uVar8);
        }
        puVar3 = xtra_readSerializedPtr(piVar1,(int)param_1 + 2);
        iVar11 = 0;
        iVar6 = xtra_readSerializedBlock(piVar1,(int)param_1 + 2);
        iVar6 = playback_mapFont((int)puVar3,0,iVar6,iVar11);
        if ((iVar6 != 0) && (iVar11 = Ordinal_1114(iVar6), iVar11 != 0)) {
          uVar8 = Ordinal_1201(iVar11);
          xtra_readChunk(piVar2,(int)param_2 + 2,iVar11,uVar8);
          Ordinal_1115(iVar6);
          cast_freeHandle(iVar6);
        }
        if (puVar3 != (undefined4 *)0x0) {
          cast_freeHandle(puVar3);
        }
        uVar9 = xtra_readBE32Ptr((undefined1 *)&param_1);
        puVar3 = param_3;
        param_3[-1] = uVar9;
        uVar9 = xtra_readBE32Ptr((undefined1 *)&param_2);
        *puVar3 = uVar9;
        goto LAB_680ef9ce;
      }
    }
    xtra_readChunk(piVar2,iVar6,&local_8,4);
    xtra_readChunk(piVar2,iVar6,0,0);
  } while( true );
}



// ============================================================
// Function: bitmap_readRtfChunk (FUN_680efa20)
// Address: 680efa20
// Size: 41 bytes
// Params: undefined4 * param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint bitmap_readRtfChunk(undefined4 *param_1,int param_2)

{
  uint uVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    uVar1 = xtra_readSerializedBlock(param_1,param_2 + 3);
    return uVar1 >> 2;
  }
  return 0;
}



// ============================================================
// Function: bitmap_writeRtfBlock (FUN_680efa50)
// Address: 680efa50
// Size: 260 bytes
// Params: undefined4 * param_1, int param_2, int param_3, undefined4 * param_4, undefined4 * param_5, undefined4 * param_6, int * param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
bitmap_writeRtfBlock(undefined4 *param_1,int param_2,int param_3,undefined4 *param_4,undefined4 *param_5,
            undefined4 *param_6,int *param_7)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  if ((((((param_1 != (undefined4 *)0x0) && (2 < param_2)) && (param_4 != (undefined4 *)0x0)) &&
       ((param_5 != (undefined4 *)0x0 && (param_6 != (undefined4 *)0x0)))) &&
      ((param_7 != (int *)0x0 &&
       ((uVar1 = bitmap_readRtfChunk(param_1,param_2), param_3 <= (int)uVar1 &&
        (iVar2 = xtra_writeValue(param_1,param_2 + 3), iVar2 != 0)))))) &&
     ((iVar3 = xtra_writeValue(param_1,*(int *)(iVar2 + param_3 * 4)), iVar3 != 0 &&
      (uVar1 = xtra_readSerializedBlock(param_1,*(int *)(iVar2 + param_3 * 4)), *(uint *)(iVar3 + 0x18) <= uVar1
      )))) {
    *param_4 = *(undefined4 *)(iVar3 + 8);
    param_4[1] = *(undefined4 *)(iVar3 + 0xc);
    param_4[2] = *(undefined4 *)(iVar3 + 0x10);
    param_4[3] = *(undefined4 *)(iVar3 + 0x14);
    *param_5 = *(undefined4 *)(iVar3 + 4);
    *param_6 = *(undefined4 *)(iVar3 + 0x18);
    if (*(int *)(iVar3 + 0x18) != 0) {
      iVar2 = Ordinal_1111(*(undefined4 *)(iVar3 + 0x18),1);
      *param_7 = iVar2;
      if (iVar2 == 0) {
        return 0;
      }
      uVar4 = Ordinal_1114(iVar2);
      Ordinal_1129(uVar4,iVar3 + 0x1c,*(undefined4 *)(iVar3 + 0x18));
      Ordinal_1115(*param_7);
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_deserializeRtfNode (FUN_680efb60)
// Address: 680efb60
// Size: 142 bytes
// Params: int * param_1, int param_2, int param_3, int param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_deserializeRtfNode(int *param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (((param_1 != (int *)0x0) && (2 < param_2)) && (param_4 != 0)) {
    uVar1 = bitmap_readRtfChunk(param_1,param_2);
    if (param_3 <= (int)uVar1) {
      iVar2 = xtra_writeValue(param_1,param_2 + 3);
      if (iVar2 != 0) {
        iVar2 = *(int *)(iVar2 + param_3 * 4);
        xtra_readChunkBlock(param_1,iVar2,param_4 + 0x1f);
        iVar2 = xtra_writeValue(param_1,iVar2);
        if (iVar2 != 0) {
          uVar3 = Ordinal_1114(param_5);
          Ordinal_1129(iVar2 + 0x1c,uVar3,param_4);
          Ordinal_1115(param_5);
          return 1;
        }
      }
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: bitmap_copyRtfToBuffer (FUN_680efbf0)
// Address: 680efbf0
// Size: 98 bytes
// Params: undefined4 * param_1, int param_2, int param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_copyRtfToBuffer(undefined4 *param_1,int param_2,int param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    uVar1 = bitmap_readRtfChunk(param_1,param_2);
    if (param_3 <= (int)uVar1) {
      iVar2 = xtra_writeValue(param_1,param_2 + 3);
      if (iVar2 != 0) {
        iVar2 = xtra_writeValue(param_1,*(int *)(iVar2 + param_3 * 4));
        if (iVar2 != 0) {
          *(undefined4 *)(iVar2 + 4) = param_4;
          return 1;
        }
      }
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: bitmap_pasteRtfFromBuffer (FUN_680efc60)
// Address: 680efc60
// Size: 243 bytes
// Params: int * param_1, int param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5, undefined4 param_6, int param_7, undefined4 param_8
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_pasteRtfFromBuffer(int *param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
                 undefined4 param_6,int param_7,undefined4 param_8)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_8;
  
  local_8 = 0;
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    uVar1 = bitmap_readRtfChunk(param_1,param_2);
    iVar6 = param_2 + 3;
    iVar2 = xtra_readSerializedBlock(param_1,iVar6);
    uVar3 = xtra_readChunkBlock(param_1,iVar6,iVar2 + 4);
    iVar2 = xtra_writeValue(param_1,iVar6);
    if (iVar2 == 0) {
      return false;
    }
    iVar6 = xtra_getCurrentValue(param_1);
    *(int *)(iVar2 + uVar1 * 4) = iVar6;
    xtra_readChunk(param_1,iVar6,&local_8,4);
    xtra_readChunkBlock(param_1,iVar6,param_7 + 0x1f);
    puVar4 = (undefined4 *)xtra_writeValue(param_1,iVar6);
    *puVar4 = FOURCC_BITF;
    puVar4[1] = 1;
    puVar4[2] = param_3;
    puVar4[3] = param_4;
    puVar4[4] = param_5;
    puVar4[5] = param_6;
    puVar4[6] = param_7;
    if (param_7 != 0) {
      uVar5 = Ordinal_1114(param_8);
      Ordinal_1129(puVar4 + 7,uVar5,param_7);
      Ordinal_1115(param_8);
    }
    return (short)uVar3 == 0;
  }
  return false;
}



// ============================================================
// Function: bitmap_duplicateRtfNode (FUN_680efd60)
// Address: 680efd60
// Size: 107 bytes
// Params: undefined4 * param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_duplicateRtfNode(undefined4 *param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_1 != (undefined4 *)0x0) && (2 < param_2)) {
    uVar2 = bitmap_readRtfChunk(param_1,param_2);
    if ((((param_3 <= (int)uVar2) && (-1 < param_3)) && (param_4 <= (int)uVar2)) && (-1 < param_4))
    {
      iVar3 = xtra_writeValue(param_1,param_2 + 3);
      if (iVar3 != 0) {
        uVar1 = *(undefined4 *)(iVar3 + param_3 * 4);
        *(undefined4 *)(iVar3 + param_3 * 4) = *(undefined4 *)(iVar3 + param_4 * 4);
        *(undefined4 *)(iVar3 + param_4 * 4) = uVar1;
        return 1;
      }
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: bitmap_deleteRtfRange (FUN_680efdd0)
// Address: 680efdd0
// Size: 172 bytes
// Params: int * param_1, int param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool bitmap_deleteRtfRange(int *param_1,int param_2,int param_3)

{
  int iVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    uVar3 = bitmap_readRtfChunk(param_1,param_2);
    if (param_3 <= (int)uVar3) {
      iVar4 = xtra_writeValue(param_1,param_2 + 3);
      if (iVar4 != 0) {
        iVar1 = iVar4 + param_3 * 4;
        sVar2 = xtra_readChunk(param_1,*(int *)(iVar4 + param_3 * 4),0,0);
        Ordinal_1129(iVar1,iVar1 + 4,(uVar3 - param_3) * 4 + -4);
        uVar3 = xtra_readChunkBlock(param_1,param_2 + 3,uVar3 * 4 - 4);
        return (short)uVar3 == 0 && sVar2 == 0;
      }
    }
    return false;
  }
  return false;
}



// ============================================================
// Function: bitmap_splitRtfNode (FUN_680efe80)
// Address: 680efe80
// Size: 157 bytes
// Params: int * param_1, int param_2
// Return: byte
// Calling convention: __stdcall
// ============================================================

byte bitmap_splitRtfNode(int *param_1,int param_2)

{
  byte bVar1;
  short sVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  
  bVar1 = 1;
  if ((param_1 != (int *)0x0) && (2 < param_2)) {
    uVar3 = bitmap_readRtfChunk(param_1,param_2);
    iVar4 = xtra_writeValue(param_1,param_2 + 3);
    if (iVar4 != 0) {
      iVar5 = 0;
      if (0 < (int)uVar3) {
        do {
          sVar2 = xtra_readChunk(param_1,*(int *)(iVar4 + iVar5 * 4),0,0);
          iVar5 = iVar5 + 1;
          bVar1 = bVar1 & sVar2 == 0;
        } while (iVar5 < (int)uVar3);
      }
      sVar2 = xtra_readChunk(param_1,param_2 + 3,0,0);
      return sVar2 == 0 & bVar1;
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: bitmap_validateRtfNode (FUN_680eff20)
// Address: 680eff20
// Size: 179 bytes
// Params: undefined4 * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int bitmap_validateRtfNode(undefined4 *param_1,int param_2,int param_3)
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (((param_1 != (undefined4 *)0x0) && (2 < param_2)) &&
     (uVar1 = bitmap_readRtfChunk(param_1,param_2), 0 < (int)uVar1)) {
    iVar2 = xtra_writeValue(param_1,param_2 + 3);
    iVar5 = 0;
    if (0 < (int)uVar1) {
      do {
        if (param_3 != 0) {
          uVar3 = cast_freeIfNonNull(*(undefined4 *)(iVar2 + iVar5 * 4));
          *(undefined4 *)(iVar2 + iVar5 * 4) = uVar3;
        }
        iVar4 = xtra_writeValue(param_1,*(int *)(iVar2 + iVar5 * 4));
        if (iVar4 == 0) {
          return 0;
        }
        uVar3 = cast_freeIfNonNull(*(undefined4 *)(iVar4 + 4));
        *(undefined4 *)(iVar4 + 4) = uVar3;
        uVar3 = cast_freeIfNonNull(*(undefined4 *)(iVar4 + 0x18));
        *(undefined4 *)(iVar4 + 0x18) = uVar3;
        cast_copyPascalString((ushort *)(iVar4 + 8),"42211111111",0x10,0x10);
        if (param_3 == 0) {
          uVar3 = cast_freeIfNonNull(*(undefined4 *)(iVar2 + iVar5 * 4));
          *(undefined4 *)(iVar2 + iVar5 * 4) = uVar3;
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 < (int)uVar1);
    }
  }
  return 0;
}



// ============================================================
// Function: bitmap_repairRtfData (FUN_680effe0)
// Address: 680effe0
// Size: 235 bytes
// Params: undefined4 * param_1, int param_2, int * param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 bitmap_repairRtfData(undefined4 *param_1,int param_2,int *param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  undefined4 local_8;
  
  local_8 = 0;
  if ((((param_1 != (undefined4 *)0x0) && (param_3 != (int *)0x0)) && (2 < param_2)) &&
     (2 < param_4)) {
    iVar7 = param_4 + 3;
    xtra_readChunk(param_3,iVar7,&local_8,4);
    uVar1 = xtra_readSerializedBlock(param_1,param_2 + 3);
    xtra_readChunkBlock(param_3,iVar7,uVar1);
    uVar1 = bitmap_readRtfChunk(param_1,param_2);
    iVar8 = 0;
    if (0 < (int)uVar1) {
      do {
        iVar2 = xtra_writeValue(param_3,iVar7);
        iVar3 = xtra_writeValue(param_1,param_2 + 3);
        iVar3 = *(int *)(iVar3 + iVar8 * 4);
        iVar4 = xtra_getCurrentValue(param_3);
        *(int *)(iVar2 + iVar8 * 4) = iVar4;
        uVar5 = xtra_readSerializedBlock(param_1,iVar3);
        uVar6 = xtra_writeValue(param_1,iVar3);
        xtra_readChunk(param_3,iVar4,uVar6,uVar5);
        iVar8 = iVar8 + 1;
      } while (iVar8 < (int)uVar1);
    }
    return 1;
  }
  return 0;
}



