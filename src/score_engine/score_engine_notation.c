// Module: score_engine
// Topic: Notation - keyframes, animation data, score file prefs, path sanitization
// Address range: 0x68082550 - 0x68083360
// Functions (22):
//   scoreEngine_beginNotationEdit (scoreEngine_beginNotationEdit)
//   scoreEngine_writeNotation
//   scoreEngine_drawNotationBorder (scoreEngine_drawNotationBorder)
//   scoreEngine_getNotationState
//   scoreEngine_animateTransition (scoreEngine_animateTransition)
//   scoreEngine_getKeyframeSize (scoreEngine_getKeyframeSize)
//   scoreEngine_calcKeyframeSize (scoreEngine_calcKeyframeSize)
//   scoreEngine_createKeyframe (scoreEngine_createKeyframe)
//   scoreEngine_swapKeyframeBytes (scoreEngine_swapKeyframeBytes)
//   scoreEngine_findKeyframeIndex (scoreEngine_findKeyframeIndex)
//   scoreEngine_insertKeyframe (scoreEngine_insertKeyframe)
//   scoreEngine_removeKeyframe (scoreEngine_removeKeyframe)
//   scoreEngine_getKeyframeFlags (scoreEngine_getKeyframeFlags)
//   scoreEngine_applyKeyframeData (scoreEngine_applyKeyframeData)
//   scoreEngine_mergeKeyframes (scoreEngine_mergeKeyframes)
//   scoreEngine_readKeyframeProps (scoreEngine_readKeyframeProps)
//   scoreEngine_sanitizePath (scoreEngine_sanitizePath)
//   scoreEngine_checkPrefsFile (scoreEngine_checkPrefsFile)
//   scoreEngine_checkMediaFile (scoreEngine_checkMediaFile)
//   scoreEngine_resolveFilePath (scoreEngine_resolveFilePath)
//   scoreEngine_syncPrefsData (scoreEngine_syncPrefsData)
//   scoreEngine_storeDeferredAsset (scoreEngine_storeDeferredAsset)

// ============================================================
// Function: scoreEngine_beginNotationEdit (scoreEngine_beginNotationEdit)
// Address: 68082550
// Size: 362 bytes
// Params: void * this, int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall scoreEngine_beginNotationEdit(void *this,int param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  void *pvVar2;
  byte *unaff_EBX;
  uint local_20;
  int local_1c;
  int local_14 [4];
  
  iVar1 = media_lookupAsset(*(int *)((int)this + 0x20),unaff_EBX,param_2);
  media_resolveAsset(*(int *)((int)this + 0x20),(int)unaff_EBX,*(int *)((int)this + 0x7c),iVar1,0);
  if (*(int *)((int)this + 0x78) != 0) {
    sprites_buildEditMenu();
  }
  sprites_setTextBounds(param_2,unaff_EBX);
  local_14[1] = 0;
  local_14[2] = 0;
  *(int *)((int)this + 0x7c) = param_1;
  *(undefined4 *)((int)this + 0x78) = 2;
  *(byte **)((int)this + 0x80) = unaff_EBX;
  local_14[0] = 1;
  events_getWindowInfo(*(int *)((int)this + 0xc),param_1,local_14);
  if (param_3 == 0) {
    if (iVar1 < 0) {
      media_registerAsset(*(int *)((int)this + 0x20),unaff_EBX,param_2,0);
    }
    else {
      media_resolveAsset(*(int *)((int)this + 0x20),(int)unaff_EBX,*(int *)((int)this + 0x7c),iVar1,1);
    }
  }
  else {
    iVar1 = Ordinal_294(*(int *)((int)this + 0x20),(int)unaff_EBX,param_2,0x70,&local_20);
    if (iVar1 != 0) {
      iVar1 = xtra_getBufferSize(local_1c);
      iVar1 = xtra_insertIntoBuffer(local_1c,0,iVar1);
      pvVar2 = (void *)xtra_getBufferSize(local_20);
      if (pvVar2 == (void *)0x0) {
        media_resolveAsset(*(int *)((int)this + 0x20),(int)unaff_EBX,param_1,0,1);
      }
      *(undefined4 *)((int)this + 0x8c) = 0;
      *(void **)((int)this + 0x90) = pvVar2;
      media_registerAssetWithData(*(int *)((int)this + 0x20),unaff_EBX,param_2,(void *)0x0,pvVar2);
      media_registerAsset(*(int *)((int)this + 0x20),unaff_EBX,param_2,(int)pvVar2);
      xtra_resetBuffer(iVar1);
    }
  }
  *(code **)((int)this + 0x84) = scoreEngine_stepPlayback;
  sprites_getTextInfo(param_2);
  return 0;
}



// ============================================================
// Function: scoreEngine_writeNotation (FUN_680826c0)
// Address: 680826c0
// Size: 339 bytes
// Params: int * param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_writeNotation(int *param_1,int param_2,int param_3,int param_4,int param_5)
{
  int iVar1;
  undefined4 uVar2;
  short sVar3;
  short local_78 [8];
  undefined4 local_68;
  undefined4 local_64;
  int local_60 [16];
  uint local_20 [6];
  uint local_8;
  
  local_64 = 0;
  Ordinal_374(param_1[8],param_2,param_3,2,(double *)local_60);
  iVar1 = local_60[0];
  local_68 = local_60[0];
  sVar3 = (short)local_60[0];
  if ((param_1[0x1e] == 2) && (param_1[0x1f] == param_3)) {
    uVar2 = Ordinal_362(param_1[8],param_1[0x20],param_1 + 0x26);
    if (((short)uVar2 == sVar3) && ((short)((uint)uVar2 >> 0x10) == (*(unsigned short *)((char *)&local_68 + 2))))
    goto LAB_680827ca;
    param_4 = 1;
  }
  if ((0 < param_3) && (param_3 <= *(int *)(param_1[3] + 0xf4))) {
    Ordinal_374(param_1[8],param_2,param_3,0x15,(double *)local_60);
    if (local_60[0] == 0) {
LAB_680827ca:
      return 0;
    }
    Ordinal_294(param_1[8],param_2,iVar1,2,local_20);
    Ordinal_347(*(int *)(*param_1 + 8),sVar3,3,(uint *)local_78);
    if ((0 < (*(unsigned short *)((char *)&local_68 + 2))) && ((*(unsigned short *)((char *)&local_68 + 2)) <= local_78[0])) {
      local_64 = 1;
      if (param_5 == 2) {
        if ((local_20[0] == 3) || (local_20[0] == 7)) {
          scoreEngine_beginNotationEdit(param_1,param_3,iVar1,param_4);
        }
      }
      else if (param_5 == 3) {
        sprites_getEditMenuState(param_3,iVar1);
      }
      Ordinal_108(param_1[8],0x1d,(undefined4 *)0x0);
    }
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_drawNotationBorder (scoreEngine_drawNotationBorder)
// Address: 68082820
// Size: 180 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_drawNotationBorder(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined1 local_18 [16];
  uint local_8;
  
  iVar1 = *param_1;
  iVar2 = param_1[1];
  iVar3 = param_1[3];
  iVar4 = param_1[2];
  iVar5 = iVar3 + -1;
  Ordinal_1060(local_18,iVar1,iVar2,iVar1 + 1,iVar5);
  Ordinal_1621();
  Ordinal_1060(local_18,iVar1,iVar5,iVar4,iVar3);
  Ordinal_1621();
  Ordinal_1060(local_18,iVar4 + -1,iVar2,iVar4,iVar5);
  Ordinal_1621();
  Ordinal_1060(local_18,iVar4 + -1,iVar2,iVar1 + 1,iVar2 + 1);
  Ordinal_1621();
  return 0;
}



// ============================================================
// Function: scoreEngine_getNotationState (FUN_680828e0)
// Address: 680828e0
// Size: 93 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getNotationState(void)
{
  short in_AX;
  int iVar1;
  uint uVar2;
  int unaff_ESI;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar1 = (int)in_AX;
  local_10 = *(int *)(unaff_ESI + 0x28) * iVar1 + *(int *)(unaff_ESI + 0x18);
  local_8 = *(int *)(unaff_ESI + 0x24) * iVar1 + *(int *)(unaff_ESI + 0x20);
  local_c = *(int *)(unaff_ESI + 0x30) * iVar1 + *(int *)(unaff_ESI + 0x1c);
  local_14 = *(int *)(unaff_ESI + 0x2c) * iVar1 + *(int *)(unaff_ESI + 0x14);
  scoreEngine_drawNotationBorder(&local_14);
  do {
    uVar2 = Ordinal_1541();
  } while (uVar2 < *(uint *)(unaff_ESI + 0x34));
  iVar1 = Ordinal_1541();
  *(int *)(unaff_ESI + 0x34) = iVar1 + *(int *)(unaff_ESI + 0x38);
  return 0;
}



// ============================================================
// Function: scoreEngine_animateTransition (scoreEngine_animateTransition)
// Address: 68082940
// Size: 429 bytes
// Params: int param_1, int * param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_animateTransition(int param_1,int *param_2,int *param_3,int param_4)
{
  int iVar1;
  short sVar2;
  int local_48;
  undefined4 local_44;
  int local_40;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  uint local_8;
  
  local_48 = 0;
  if (param_1 != 0) {
    local_44 = Ordinal_1824(param_1);
    iVar1 = Ordinal_1610(local_44);
    if (iVar1 == 0) {
      local_48 = Ordinal_1730(0x100);
      if (local_48 == 0) goto LAB_68082ada;
      Ordinal_1609(local_44,local_48);
    }
    local_3c = param_3[1];
    local_c = (param_4 * 1000) / 0x3c;
    local_40 = *param_3;
    local_38 = param_3[2];
    local_34 = param_3[3];
    local_30 = *param_2;
    local_2c = param_2[1];
    local_28 = param_2[2];
    local_24 = param_2[3];
    local_10 = Ordinal_1541();
    sVar2 = 1;
    local_14 = (int)((local_38 - local_28) + (local_38 - local_28 >> 0x1f & 7U)) >> 3;
    local_18 = (int)((local_40 - local_30) + (local_40 - local_30 >> 0x1f & 7U)) >> 3;
    local_1c = (int)((local_3c - local_2c) + (local_3c - local_2c >> 0x1f & 7U)) >> 3;
    local_20 = (int)((local_34 - local_24) + (local_34 - local_24 >> 0x1f & 7U)) >> 3;
    do {
      scoreEngine_getNotationState();
      sVar2 = sVar2 + 1;
    } while (sVar2 < 5);
    scoreEngine_getNotationState();
    scoreEngine_getNotationState();
    scoreEngine_getNotationState();
    scoreEngine_getNotationState();
    scoreEngine_getNotationState();
    scoreEngine_getNotationState();
    scoreEngine_getNotationState();
    scoreEngine_getNotationState();
    sVar2 = 5;
    do {
      scoreEngine_getNotationState();
      sVar2 = sVar2 + 1;
    } while (sVar2 < 9);
    Ordinal_1825(param_1,&local_44);
    if (local_48 != 0) {
      Ordinal_1609(local_44,0);
      Ordinal_1733(&local_48);
    }
  }
LAB_68082ada:
  return 0;
}



// ============================================================
// Function: scoreEngine_getKeyframeSize (scoreEngine_getKeyframeSize)
// Address: 68082af0
// Size: 11 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_getKeyframeSize(void)

{
  int in_EAX;
  
  return in_EAX * 0x14 + 2;
}



// ============================================================
// Function: scoreEngine_calcKeyframeSize (scoreEngine_calcKeyframeSize)
// Address: 68082b00
// Size: 10 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_calcKeyframeSize(void)
{
  scoreEngine_getKeyframeSize();
  return 0;
}



// ============================================================
// Function: scoreEngine_createKeyframe (scoreEngine_createKeyframe)
// Address: 68082b10
// Size: 110 bytes
// Params: undefined2 * param_1, undefined2 param_2, undefined2 param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * scoreEngine_createKeyframe(undefined2 *param_1,undefined2 param_2,undefined2 param_3)

{
  int iVar1;
  int *piVar2;
  undefined4 uVar3;
  
  uVar3 = 1;
  iVar1 = scoreEngine_getKeyframeSize();
  piVar2 = (int *)cast_allocHandle(iVar1,uVar3);
  if (piVar2 != (int *)0x0) {
    *(undefined2 *)*piVar2 = 1;
    iVar1 = *piVar2;
    *(undefined4 *)(iVar1 + 2) = 0;
    *(undefined2 *)(iVar1 + 10) = *param_1;
    *(undefined1 *)(iVar1 + 0xc) = *(undefined1 *)(param_1 + 1);
    *(undefined2 *)(iVar1 + 0xe) = param_1[2];
    *(undefined4 *)(iVar1 + 0x10) = *(undefined4 *)(param_1 + 3);
    *(undefined2 *)(iVar1 + 0x14) = param_1[5];
    *(undefined2 *)(iVar1 + 8) = param_3;
    *(undefined2 *)(iVar1 + 6) = param_2;
  }
  return piVar2;
}



// ============================================================
// Function: scoreEngine_swapKeyframeBytes (scoreEngine_swapKeyframeBytes)
// Address: 68082b80
// Size: 193 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_swapKeyframeBytes(int *param_1,int param_2)
{
  undefined4 *puVar1;
  undefined2 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != (int *)0x0) {
    Ordinal_1114(param_1);
    iVar5 = param_2;
    if ((char)param_2 == '\0') {
      iVar5 = (int)*(short *)*param_1;
    }
    uVar2 = xtra_readBE16((undefined1 *)*param_1);
    *(undefined2 *)*param_1 = uVar2;
    if ((char)param_2 != '\0') {
      iVar5 = (int)*(short *)*param_1;
    }
    if (0 < iVar5) {
      iVar4 = 0;
      param_2 = iVar5;
      do {
        puVar1 = (undefined4 *)(*param_1 + 2 + iVar4);
        uVar3 = xtra_readBE32Ptr((undefined1 *)puVar1);
        *puVar1 = uVar3;
        uVar2 = xtra_readBE16((undefined1 *)(puVar1 + 1));
        *(undefined2 *)(puVar1 + 1) = uVar2;
        uVar2 = xtra_readBE16((undefined1 *)((int)puVar1 + 6));
        *(undefined2 *)((int)puVar1 + 6) = uVar2;
        uVar2 = xtra_readBE16((undefined1 *)(puVar1 + 2));
        *(undefined2 *)(puVar1 + 2) = uVar2;
        uVar2 = xtra_readBE16((undefined1 *)(puVar1 + 3));
        *(undefined2 *)(puVar1 + 3) = uVar2;
        uVar2 = xtra_readBE16((undefined1 *)((int)puVar1 + 0xe));
        *(undefined2 *)((int)puVar1 + 0xe) = uVar2;
        uVar2 = xtra_readBE16((undefined1 *)(puVar1 + 4));
        *(undefined2 *)(puVar1 + 4) = uVar2;
        uVar2 = xtra_readBE16((undefined1 *)((int)puVar1 + 0x12));
        iVar4 = iVar4 + 0x14;
        param_2 = param_2 + -1;
        *(undefined2 *)((int)puVar1 + 0x12) = uVar2;
      } while (param_2 != 0);
    }
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_findKeyframeIndex (scoreEngine_findKeyframeIndex)
// Address: 68082c50
// Size: 37 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int scoreEngine_findKeyframeIndex(void)

{
  undefined4 *in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int unaff_EDI;
  
  iVar2 = (int)*(short *)*in_EAX;
  iVar3 = 0;
  piVar4 = (int *)((short *)*in_EAX + 1);
  iVar1 = iVar2 + -1;
  if (0 < iVar2) {
    while (*piVar4 <= unaff_EDI) {
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 5;
      if (iVar2 <= iVar3) {
        return iVar1;
      }
    }
    iVar1 = iVar3 + -1;
  }
  return iVar1;
}



// ============================================================
// Function: scoreEngine_insertKeyframe (scoreEngine_insertKeyframe)
// Address: 68082c80
// Size: 77 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_insertKeyframe(undefined4 param_1)
{
  short *psVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int *unaff_EDI;
  undefined4 uVar3;
  
  *(short *)*unaff_EDI = *(short *)*unaff_EDI + 1;
  uVar3 = 0;
  uVar2 = scoreEngine_calcKeyframeSize();
  cast_resizeHandle((uint)unaff_EDI,uVar2,uVar3);
  psVar1 = (short *)*unaff_EDI;
  Ordinal_1129(psVar1 + unaff_EBX * 10 + 0xb,psVar1 + unaff_EBX * 10 + 1,
               ((*psVar1 - unaff_EBX) * 5 + -5) * 4);
  *(undefined4 *)(*unaff_EDI + 0x16 + unaff_EBX * 0x14) = param_1;
  return 0;
}



// ============================================================
// Function: scoreEngine_removeKeyframe (scoreEngine_removeKeyframe)
// Address: 68082cd0
// Size: 66 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall scoreEngine_removeKeyframe(int param_1)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int _param_4;
  short *psVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  undefined4 uVar3;
  
  psVar1 = (short *)*unaff_ESI;
  if (param_1 + 2 < (int)*psVar1) {
    Ordinal_1129(psVar1 + param_1 * 10 + 0xb,psVar1 + param_1 * 10 + 0x15,
                 ((*psVar1 - param_1) * 5 + -5) * 4);
  }
  *(short *)*unaff_ESI = *(short *)*unaff_ESI + -1;
  uVar3 = 0;
  uVar2 = scoreEngine_calcKeyframeSize();
  cast_resizeHandle((uint)unaff_ESI,uVar2,uVar3);
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: scoreEngine_getKeyframeFlags (scoreEngine_getKeyframeFlags)
// Address: 68082d20
// Size: 51 bytes
// Params: void * this, int * param_1, byte param_2
// Return: byte
// Calling convention: __thiscall
// ============================================================

byte __thiscall scoreEngine_getKeyframeFlags(void *this,int *param_1,byte param_2)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  byte bVar1;
  int in_EAX;
  int iVar2;
  byte *pbVar3;
  int unaff_ESI;
  
  if ((param_2 & 0x20) == 0) {
    bVar1 = 0;
  }
  else {
    bVar1 = *(byte *)(in_EAX + 2);
    pbVar3 = (byte *)(*param_1 + 0xc + unaff_ESI * 0x14);
    if (unaff_ESI <= (int)this) {
      iVar2 = (int)this + (1 - unaff_ESI);
      do {
        bVar1 = bVar1 & *pbVar3;
        pbVar3 = pbVar3 + 0x14;
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      return bVar1;
    }
  }
  return bVar1;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: scoreEngine_applyKeyframeData (scoreEngine_applyKeyframeData)
// Address: 68082d60
// Size: 121 bytes
// Params: byte param_1, byte param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall scoreEngine_applyKeyframeData(byte param_1,byte param_2)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int in_EAX;
  undefined2 *unaff_ESI;
  undefined2 uVar1;
  
  if ((param_2 & 0x10) == 0) {
    if ((param_2 & 4) == 0) goto LAB_68082d8f;
    uVar1 = unaff_ESI[2];
  }
  else {
    *(short *)(in_EAX + 0xc) = *(short *)(in_EAX + 0xc) + unaff_ESI[2];
    if (0 < *(short *)(in_EAX + 0xc)) goto LAB_68082d8f;
    uVar1 = 1;
  }
  *(undefined2 *)(in_EAX + 0xc) = uVar1;
LAB_68082d8f:
  if ((param_2 & 1) != 0) {
    *(undefined2 *)(in_EAX + 8) = *unaff_ESI;
  }
  if ((param_2 & 2) != 0) {
    if (*(char *)(unaff_ESI + 1) == '\0') {
      *(undefined1 *)(in_EAX + 10) = 0;
    }
    else {
      if (param_1 != 0) {
        *(byte *)(in_EAX + 10) = *(byte *)(in_EAX + 10) & ~param_1;
      }
      *(byte *)(in_EAX + 10) = *(byte *)(in_EAX + 10) | ~param_1 & *(byte *)(unaff_ESI + 1);
    }
  }
  if ((param_2 & 8) != 0) {
    *(undefined4 *)(in_EAX + 0xe) = *(undefined4 *)(unaff_ESI + 3);
    *(undefined2 *)(in_EAX + 0x12) = unaff_ESI[5];
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: scoreEngine_mergeKeyframes (scoreEngine_mergeKeyframes)
// Address: 68082de0
// Size: 293 bytes
// Params: int * param_1, int param_2, int param_3, byte param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_mergeKeyframes(int *param_1,int param_2,int param_3,byte param_4)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
                  int _param_4; /* FIXUP(C2065): missing Ghidra variable declaration */
                /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '/'): /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '/'): /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '/'): /* FIXUP(C2086: 'int _param_4': redefinition): int _param_4; /* FIXUP(C2065): missing Ghidra variable declaration */ */ */ */ */
              /* FIXUP(C2086: 'int _param_4': redefinition): int _param_4; /* FIXUP(C2065): missing Ghidra variable declaration */ */
            /* FIXUP(C2086: 'int _param_4': redefinition): int _param_4; /* FIXUP(C2065): missing Ghidra variable declaration */ */
          /* FIXUP(C2086: 'int _param_4': redefinition): int _param_4; /* FIXUP(C2065): missing Ghidra variable declaration */ */
        /* FIXUP(C2086: 'int _param_4': redefinition): int _param_4; /* FIXUP(C2065): missing Ghidra variable declaration */ */
      /* FIXUP(C2086: 'int _param_4': redefinition): int _param_4; /* FIXUP(C2065): missing Ghidra variable declaration */ */
    /* FIXUP(C2086: 'int _param_4': redefinition): int _param_4; /* FIXUP(C2065): missing Ghidra variable declaration */ */
  byte bVar1;
  void *this;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int iStack00000014;
  int local_8;
  
  local_8 = scoreEngine_findKeyframeIndex();
  if (*(int *)(*param_1 + 2 + local_8 * 0x14) < param_2) {
    scoreEngine_insertKeyframe(param_2);
    local_8 = local_8 + 1;
  }
  this = (void *)scoreEngine_findKeyframeIndex();
  if ((*(short *)*param_1 + -1 <= (int)this) ||
     (param_3 + 1 < *(int *)((short *)*param_1 + (int)this * 10 + 0xb))) {
    scoreEngine_insertKeyframe(param_3 + 1);
  }
  /* FIXUP(C2065: undeclared 'bVar1'): bVar1 = scoreEngine_getKeyframeFlags(this,param_1,param_4); */
  Ordinal_1114(param_1);
  if (local_8 <= (int)this) {
    param_3 = (int)this + (1 - local_8);
    do {
      /* FIXUP(C2065: undeclared 'bVar1'): scoreEngine_applyKeyframeData(bVar1,param_4); */
      param_3 = param_3 + -1;
    } while (param_3 != 0);
  }
  Ordinal_1115(param_1);
  uVar5 = local_8 - 1U & ((int)(local_8 - 1U) < 1) - 1;
  _param_4 = *(short *)*param_1 + -1;
  if ((int)this + 1 < *(short *)*param_1 + -1) {
    _param_4 = (int)this + 1;
  }
  _param_4 = _param_4 + -1;
  if ((int)uVar5 <= _param_4) {
    iVar4 = uVar5 * 0x14;
    do {
      piVar2 = (int *)(*param_1 + iVar4 + 0x16);
      iStack00000014 = ((*param_1 + iVar4) - (int)piVar2) + 2;
      uVar3 = 0x14;
      do {
        if (*(int *)(iStack00000014 + (int)piVar2) != *piVar2) goto LAB_68082ef6;
        uVar3 = uVar3 - 4;
        piVar2 = piVar2 + 1;
      } while (3 < uVar3);
      scoreEngine_removeKeyframe(uVar5);
      uVar5 = uVar5 - 1;
      iVar4 = iVar4 + -0x14;
      _param_4 = _param_4 + -1;
LAB_68082ef6:
      uVar5 = uVar5 + 1;
      iVar4 = iVar4 + 0x14;
    } while ((int)uVar5 <= _param_4);
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: scoreEngine_readKeyframeProps (scoreEngine_readKeyframeProps)
// Address: 68082f10
// Size: 103 bytes
// Params: int * param_1, undefined4 param_2, undefined2 * param_3, undefined2 * param_4, undefined2 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_readKeyframeProps(int *param_1,undefined4 param_2,undefined2 *param_3,undefined2 *param_4,
                 undefined2 *param_5)
{
  int iVar1;
  
  iVar1 = scoreEngine_findKeyframeIndex();
  iVar1 = *param_1 + 2 + iVar1 * 0x14;
  if (param_3 != (undefined2 *)0x0) {
    *param_3 = *(undefined2 *)(iVar1 + 8);
    *(undefined1 *)(param_3 + 1) = *(undefined1 *)(iVar1 + 10);
    param_3[2] = *(undefined2 *)(iVar1 + 0xc);
    *(undefined4 *)(param_3 + 3) = *(undefined4 *)(iVar1 + 0xe);
    param_3[5] = *(undefined2 *)(iVar1 + 0x12);
  }
  if (param_4 != (undefined2 *)0x0) {
    *param_4 = *(undefined2 *)(iVar1 + 4);
  }
  if (param_5 != (undefined2 *)0x0) {
    *param_5 = *(undefined2 *)(iVar1 + 6);
  }
  return 0;
}



// ============================================================
// Function: scoreEngine_sanitizePath (scoreEngine_sanitizePath)
// Address: 68082f80
// Size: 33 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_sanitizePath(void)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  char cVar1;
  int in_EAX;
  char *pcVar2;
  
  pcVar2 = (char *)(in_EAX + 1);
  cVar1 = *pcVar2;
  while (cVar1 != '\0') {
    cVar1 = *pcVar2;
    if (((cVar1 == ':') || (cVar1 == '\\')) || (cVar1 == '/')) {
      *pcVar2 = '_';
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: scoreEngine_checkPrefsFile (scoreEngine_checkPrefsFile)
// Address: 68082fb0
// Size: 63 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_checkPrefsFile(undefined4 param_1)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_68196330 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x68082fc1. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = ((code *)(size_t)DAT_68196330)();
    return uVar1;
  }
  iVar2 = Ordinal_1334(param_1,2);
  if ((iVar2 != 0) && (iVar2 = Ordinal_1317(param_1,"Prefs"), iVar2 != 0)) {
    return 1;
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: scoreEngine_checkMediaFile (scoreEngine_checkMediaFile)
// Address: 68082ff0
// Size: 78 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_checkMediaFile(undefined4 param_1)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_6819632c != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x68083001. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    uVar1 = ((code *)(size_t)DAT_6819632c)();
    return uVar1;
  }
  iVar2 = Ordinal_1320(param_1,DAT_681956e0);
  if (((iVar2 != 0) && (iVar2 = Ordinal_1316(param_1), iVar2 != 0)) &&
     (iVar2 = Ordinal_1317(param_1,"dswMedia"), iVar2 != 0)) {
    return 1;
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: scoreEngine_resolveFilePath (scoreEngine_resolveFilePath)
// Address: 68083040
// Size: 305 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 scoreEngine_resolveFilePath(int param_1,int param_2,undefined4 param_3)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  undefined4 uVar1;
  char cVar2;
  short sVar3;
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  char *pcVar7;
  undefined4 local_8;
  
  uVar1 = param_3;
  local_8 = 0;
  pcVar6 = (char *)0x0;
  iVar4 = scoreEngine_checkPrefsFile(param_3);
  if ((iVar4 == 0) ||
     ((iVar4 = Ordinal_1351(uVar1), iVar4 == 0 && (iVar4 = Ordinal_1357(uVar1), iVar4 == 0))))
  goto LAB_68083113;
  pcVar6 = (char *)Ordinal_1114(param_2);
  if (pcVar6 == (char *)0x0) {
    props_setError(param_1,0x67);
    goto LAB_68083113;
  }
  scoreEngine_sanitizePath();
  Ordinal_1317(uVar1,pcVar6);
  cVar2 = *pcVar6;
  pcVar7 = pcVar6;
  if (cVar2 == '\0') {
LAB_6808312f:
    if (*pcVar7 == '\0') goto LAB_680830bc;
    sVar3 = Ordinal_1208(pcVar7,&DAT_6817c6b4);
    if (((sVar3 != 0) && (sVar3 = Ordinal_1208(pcVar7,&DAT_6817c6ac), sVar3 != 0)) &&
       (sVar3 = Ordinal_1208(pcVar7,&DAT_6817c6a4), sVar3 != 0)) {
      props_setError(param_1,0x67);
      goto LAB_68083113;
    }
  }
  else {
    do {
      if (cVar2 == '.') goto LAB_6808312f;
      cVar2 = pcVar7[1];
      pcVar7 = pcVar7 + 1;
    } while (cVar2 != '\0');
LAB_680830bc:
    param_1 = 0;
    iVar4 = Ordinal_1201(pcVar6,0);
    param_1 = Ordinal_1111(iVar4 + 5);
    if (param_1 == 0) goto LAB_68083113;
    uVar5 = Ordinal_1114(param_1);
    Ordinal_1202(uVar5,pcVar6);
    Ordinal_1204(uVar5,&DAT_6817c6b4);
    Ordinal_1316(uVar1);
    Ordinal_1317(uVar1,uVar5);
    Ordinal_1113(&param_1);
  }
  local_8 = 1;
LAB_68083113:
  if ((param_2 != 0) && (pcVar6 != (char *)0x0)) {
    Ordinal_1115(param_2);
  }
  return local_8;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: scoreEngine_syncPrefsData (scoreEngine_syncPrefsData)
// Address: 68083180
// Size: 475 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_syncPrefsData(undefined4 param_1,undefined4 param_2)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int iVar1;
  int iVar2;
  int local_82c;
  int local_828;
  int local_824;
  undefined1 local_820 [1048];
  undefined1 local_408 [1024];
  uint local_8;
  
  local_824 = 0;
  local_828 = 0;
  local_82c = 0;
  Ordinal_1130(local_820,0x418);
  if (((DAT_68196358 != (code *)0x0) && (iVar1 = ((code *)(size_t)DAT_68196358)(param_1,local_820), iVar1 != 0)) &&
     (iVar1 = Ordinal_1314(param_2,local_408,0x3fe), iVar1 != 0)) {
    Ordinal_1317(local_820,local_408);
    iVar1 = Ordinal_1402(&local_824,local_820,1);
    if (iVar1 != 0) {
      iVar1 = Ordinal_1435(local_824);
      local_828 = Ordinal_1124(iVar1 + 1);
      if ((local_828 != 0) && (iVar2 = Ordinal_1409(local_824,local_828,iVar1), iVar2 != 0)) {
        *(undefined1 *)(iVar1 + local_828) = 0;
        Ordinal_1407(&local_824);
        iVar2 = Ordinal_1274(local_828,iVar1,0,0);
        if ((0 < iVar2) &&
           ((local_82c = Ordinal_1124(iVar2 + 1), local_82c != 0 &&
            (iVar1 = Ordinal_1274(local_828,iVar1,local_82c,iVar2), 0 < iVar1)))) {
          *(undefined1 *)(iVar2 + local_82c) = 0;
          iVar1 = Ordinal_1401(&local_824,param_2,7);
          if (iVar1 != 0) {
            Ordinal_1420(local_824,local_82c,iVar2);
            Ordinal_1407(&local_824);
          }
        }
      }
    }
  }
  if (local_824 != 0) {
    Ordinal_1407(&local_824);
  }
  if (local_82c != 0) {
    Ordinal_1125(&local_82c);
  }
  if (local_828 != 0) {
    Ordinal_1125(&local_828);
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: scoreEngine_storeDeferredAsset (scoreEngine_storeDeferredAsset)
// Address: 68083360
// Size: 101 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int scoreEngine_storeDeferredAsset(int param_1,undefined4 *param_2,undefined4 param_3)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int iVar1;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int *)(param_1 + 0x358) == 0) {
    iVar1 = Ordinal_1150(1,1,8);
    *(int *)(param_1 + 0x358) = iVar1;
    if (iVar1 == 0) {
      *param_2 = 0;
      return 0;
    }
  }
  local_c = *param_2;
  local_8 = param_3;
  Ordinal_1152(*(undefined4 *)(param_1 + 0x358),&local_c);
  *param_2 = 0;
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



