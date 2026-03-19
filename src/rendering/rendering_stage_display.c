// Module: rendering
// Topic: Stage compositing, display surface, color palette, and draw operations
// Address range: 0x680cBE60 - 0x680cD920
// Functions (44):
//   rendering_getStageCount
//   rendering_renderSprite
//   rendering_getStageState
//   rendering_resizeStageSurface
//   rendering_setStageSurface
//   rendering_compositeStage
//   rendering_setStageSize
//   rendering_updateStageDisplay
//   rendering_getStageData
//   rendering_buildDirtyRegion
//   rendering_addDirtySprite
//   rendering_updateStageLayout
//   rendering_mergeStageRegion
//   rendering_getStageLayout
//   rendering_renderStageFrame
//   rendering_initSprite
//   rendering_drawTrialText
//   rendering_flushDirtySprites
//   rendering_invalidateSprites
//   rendering_createSprite
//   rendering_resizeSprite
//   rendering_getStageProperty
//   rendering_refreshStage
//   rendering_getStageFlags
//   rendering_packColorValue
//   rendering_loadPalette16
//   rendering_loadPalette256
//   rendering_getStageRef
//   rendering_updateSpriteStream
//   rendering_getStageData2
//   rendering_setStageProperty
//   rendering_updateStageRect
//   rendering_resolvePlaybackMode
//   rendering_clearSpriteStreams
//   rendering_processStagePalette
//   rendering_transformPaletteData
//   rendering_initPaletteState
//   rendering_initScorePalette
//   rendering_freeScorePalette
//   rendering_comparePaletteEntry
//   rendering_convertPaletteEntry
//   rendering_blendPaletteEntry
//   rendering_applyStageOffset
//   rendering_setupStageTransition

// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680cbe60 - 0x680cc450
// Functions (14):
//   rendering_getStageCount
//   rendering_renderSprite
//   rendering_getStageState
//   rendering_resizeStageSurface
//   rendering_setStageSurface
//   rendering_compositeStage
//   rendering_setStageSize
//   rendering_updateStageDisplay
//   rendering_getStageData
//   rendering_buildDirtyRegion
//   rendering_addDirtySprite
//   rendering_updateStageLayout
//   rendering_mergeStageRegion
//   rendering_getStageLayout

// ============================================================
// Function: rendering_getStageCount (FUN_680cbe60)
// Address: 680cbe60
// Size: 34 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getStageCount(void)
{
  int in_EAX;
  
  if (in_EAX != 0) {
    rendering_freeSaveBuffer();
    display_destroyRenderTarget((undefined4 *)(in_EAX + 0x98));
  }
  return 0;
}



// ============================================================
// Function: rendering_renderSprite (FUN_680cbe90)
// Address: 680cbe90
// Size: 110 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_renderSprite(int param_1)
{
  int iVar1;
  uint unaff_EBX;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  undefined1 local_10 [8];
  undefined4 local_8;
  
  local_8 = 0;
  iVar1 = Ordinal_1805(*(undefined4 *)(unaff_ESI + 4),local_10,&local_8);
  if (iVar1 != 0) {
    if (unaff_EDI[0x18] == 6) {
      display_renderVideoFrame(unaff_EBX,*(undefined4 *)(unaff_ESI + 0x94),unaff_EDI);
    }
    else if ((unaff_EDI[0x18] == 10) && ((*(byte *)(unaff_EDI + 0x14) & 2) == 0)) {
      bitmap_drawSpriteXtra(unaff_EBX,*(undefined4 *)(unaff_ESI + 0x94),unaff_EDI,param_1);
    }
    Ordinal_1806(*(undefined4 *)(unaff_ESI + 4),local_10,&local_8);
  }
  return 0;
}



// ============================================================
// Function: rendering_getStageState (FUN_680cbf00)
// Address: 680cbf00
// Size: 63 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getStageState(int param_1)
{
  if (param_1 != 0) {
    rendering_getStageCount();
    rendering_getStageCount();
    rendering_freeSaveBuffer();
    Ordinal_1113(param_1 + 0xdc);
    Ordinal_1130(param_1,0xe8);
  }
  return 0;
}



// ============================================================
// Function: rendering_resizeStageSurface (FUN_680cbf40)
// Address: 680cbf40
// Size: 214 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_resizeStageSurface(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  undefined1 local_28 [16];
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if ((((*(int *)(param_1 + 8) != param_4) || (*(int *)(param_1 + 0xc) != param_5)) ||
      (*(int *)(param_1 + 0x10) != param_2)) || (*(int *)(param_1 + 0x14) != param_3)) {
    if (*(int *)(param_1 + 4) != 0) {
      Ordinal_1833(*(int *)(param_1 + 4),&local_18);
      Ordinal_1064(&local_18,-local_18,-local_14);
      if (param_3 < local_c) {
        Ordinal_1060(local_28,0,param_3,local_10,local_c);
        Ordinal_1820(*(undefined4 *)(param_1 + 4),local_28);
      }
      if (param_2 < local_10) {
        Ordinal_1060(local_28,param_2,0,local_10,local_c);
        Ordinal_1820(*(undefined4 *)(param_1 + 4),local_28);
      }
    }
    *(int *)(param_1 + 8) = param_4;
    *(int *)(param_1 + 0xc) = param_5;
    *(int *)(param_1 + 0x10) = param_2;
    *(int *)(param_1 + 0x14) = param_3;
  }
  return 0;
}



// ============================================================
// Function: rendering_setStageSurface (FUN_680cc020)
// Address: 680cc020
// Size: 30 bytes
// Params: int param_1, undefined4 param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool rendering_setStageSurface(int param_1,undefined4 param_2)

{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 4) = param_2;
    *(undefined4 *)(param_1 + 0x38) = param_2;
  }
  return param_1 != 0;
}



// ============================================================
// Function: rendering_compositeStage (FUN_680cc040)
// Address: 680cc040
// Size: 203 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_compositeStage(int param_1,undefined4 param_2)
{
  uint uVar1;
  uint *in_EAX;
  uint *puVar2;
  int iVar3;
  int iVar4;
  int unaff_EDI;
  uint *local_10;
  uint local_c;
  int local_8;
  
  local_c = (uint)(in_EAX != (uint *)0x0);
  local_8 = 0;
  if ((*(int *)(param_1 + 4) != 0) && (local_8 = Ordinal_2203(10), local_8 != 0)) {
    iVar3 = *(int *)(unaff_EDI + 0x120);
    if (iVar3 <= *(int *)(unaff_EDI + 0x124)) {
      iVar4 = iVar3 * 400;
      do {
        uVar1 = *(uint *)(*(int *)(unaff_EDI + 0x34) + 0x4c + iVar4);
        if (((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) {
          Ordinal_2212(&local_8,*(int *)(unaff_EDI + 0x34) + iVar4 + 200);
        }
        iVar3 = iVar3 + 1;
        iVar4 = iVar4 + 400;
      } while (iVar3 <= *(int *)(unaff_EDI + 0x124));
    }
    puVar2 = (uint *)Ordinal_1114(local_8);
    local_10 = in_EAX;
    if (puVar2 != (uint *)0x0) {
      local_c = *puVar2;
      local_10 = puVar2 + 3;
    }
    Ordinal_1826(*(undefined4 *)(param_1 + 4),param_2,*(undefined4 *)(param_1 + 0x94),local_10,
                 local_c);
  }
  Ordinal_2204(&local_8);
  return 0;
}



// ============================================================
// Function: rendering_setStageSize (FUN_680cc110)
// Address: 680cc110
// Size: 68 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_setStageSize(int *param_1,int param_2)
{
  undefined4 uVar1;
  
  uVar1 = scoreEngine_commitScoreEdit((int *)param_1[8]);
  rendering_applyStageOffset(param_1,param_2,uVar1);
  bitmap_processStageUpdates((uint)param_1,(undefined4 *)(param_2 + 0x90));
  rendering_appendSaveBuffer();
  rendering_getStageRef();
  return 0;
}



// ============================================================
// Function: rendering_updateStageDisplay (FUN_680cc160)
// Address: 680cc160
// Size: 40 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_updateStageDisplay(int param_1)
{
  bitmap_updateMovieStage(param_1 + 0x90,(int *)(param_1 + 0xa0),0);
  *(undefined4 *)(param_1 + 0x18) = 1;
  return 0;
}



// ============================================================
// Function: rendering_getStageData (FUN_680cc190)
// Address: 680cc190
// Size: 69 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getStageData(int *param_1,int param_2,int *param_3)
{
  bitmap_handleStageScroll(param_1,(int *)(param_2 + 0x90),param_3);
  if (*(int *)(param_2 + 4) != 0) {
    Ordinal_1807(*(int *)(param_2 + 4),param_2 + 0x94,param_3);
  }
  rendering_getChannelProperty(*param_1,7,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: rendering_buildDirtyRegion (FUN_680cc1e0)
// Address: 680cc1e0
// Size: 87 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_buildDirtyRegion(int param_1,undefined4 param_2)
{
  int iVar1;
  short sVar2;
  
  Ordinal_1061(param_2);
  sVar2 = 0;
  if (0 < *(int *)(param_1 + 0x2c)) {
    iVar1 = 0;
    do {
      Ordinal_1067(param_2,param_2,iVar1 * 0x10 + *(int *)(param_1 + 0x24));
      sVar2 = sVar2 + 1;
      iVar1 = (int)sVar2;
    } while (iVar1 < *(int *)(param_1 + 0x2c));
  }
  iVar1 = Ordinal_1062(param_2);
  if (iVar1 != 0) {
    Ordinal_1060(param_2,0,0,*(undefined4 *)(param_1 + 0x10),*(undefined4 *)(param_1 + 0x14));
  }
  return 0;
}



// ============================================================
// Function: rendering_addDirtySprite (FUN_680cc240)
// Address: 680cc240
// Size: 191 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_addDirtySprite(int param_1,int param_2)
{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  puVar1 = (undefined4 *)(param_1 + 0xdc);
  if (*(int *)(param_1 + 0xdc) == 0) {
    uVar2 = Ordinal_1111(0x28,1);
    *puVar1 = uVar2;
    *(undefined4 *)(param_1 + 0xe0) = 10;
    *(undefined4 *)(param_1 + 0xe4) = 0;
  }
  iVar3 = Ordinal_1114(*puVar1);
  iVar5 = *(int *)(param_1 + 0xe4);
  iVar4 = 0;
  if (0 < iVar5) {
    do {
      if (*(int *)(iVar3 + iVar4 * 4) == param_2) goto LAB_680cc2ec;
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  if (*(int *)(param_1 + 0xe0) == iVar5) {
    Ordinal_1115(*puVar1);
    *(int *)(param_1 + 0xe0) = *(int *)(param_1 + 0xe0) + 10;
    iVar5 = Ordinal_1117(puVar1,*(int *)(param_1 + 0xe0) * 4,0);
    if (iVar5 == 0) goto LAB_680cc2ec;
    iVar3 = Ordinal_1114(*puVar1);
  }
  *(int *)(iVar3 + *(int *)(param_1 + 0xe4) * 4) = param_2;
  *(int *)(param_1 + 0xe4) = *(int *)(param_1 + 0xe4) + 1;
LAB_680cc2ec:
  if (iVar3 != 0) {
    Ordinal_1115(*puVar1);
  }
  return 0;
}



// ============================================================
// Function: rendering_updateStageLayout (FUN_680cc300)
// Address: 680cc300
// Size: 111 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_updateStageLayout(int param_1)
{
  int iVar1;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if ((param_1 == 0) || (iVar1 = Ordinal_2032(*(undefined4 *)(param_1 + 4),0), iVar1 < 0)) {
    iVar1 = 0;
  }
  Ordinal_2031(iVar1,&local_28);
  return 0;
}



// ============================================================
// Function: rendering_mergeStageRegion (FUN_680cc370)
// Address: 680cc370
// Size: 224 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_mergeStageRegion(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int local_18;
  int *local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if ((param_1 != 0) && (param_2 != (int *)0x0)) {
    Ordinal_1066(param_2,param_2,param_1 + 0xa0);
    if (*(int *)(param_1 + 0x20) != 0) {
      Ordinal_1060(&local_18,*param_2 + -1,param_2[1] + -1,param_2[2] + 1,param_2[3] + 1);
      iVar1 = 0;
      if (0 < *(int *)(param_1 + 0x2c)) {
        piVar2 = *(int **)(param_1 + 0x24);
        do {
          if ((((local_18 < piVar2[2]) && (*piVar2 < local_10)) && ((int)local_14 < piVar2[3])) &&
             (piVar2[1] < local_c)) {
            piVar2 = *(int **)(param_1 + 0x24) + iVar1 * 4;
            Ordinal_1067(piVar2,piVar2,param_2);
            goto LAB_680cc41f;
          }
          iVar1 = iVar1 + 1;
          piVar2 = piVar2 + 4;
        } while (iVar1 < *(int *)(param_1 + 0x2c));
      }
    }
    local_18 = 0;
    local_14 = param_2;
    local_c = 1;
    iVar1 = rendering_appendSaveBuffer();
    if (iVar1 != 0) {
LAB_680cc41f:
      *(undefined4 *)(param_1 + 0xbc) = 1;
    }
  }
  return 0;
}



// ============================================================
// Function: rendering_getStageLayout (FUN_680cc450)
// Address: 680cc450
// Size: 115 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int rendering_getStageLayout(int param_1,int param_2,int *param_3)
{
  int iVar1;
  undefined4 local_28 [4];
  undefined4 local_18 [2];
  int local_10;
  int local_c;
  uint local_8;
  
  if (*(int *)(param_1 + 300) == 0) {
    param_3[2] = *(int *)(param_2 + 0x10);
    param_3[3] = *(int *)(param_2 + 0x14);
  }
  else {
    playback_initLifecycle(param_1,local_28,local_18);
    param_3[2] = local_10;
    param_3[3] = local_c;
  }
  iVar1 = param_3[2] - _DAT_68196464;
  param_3[1] = param_3[3] - _DAT_68196468;
  *param_3 = iVar1;
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680cc4d0 - 0x680ccbe0
// Functions (11):
//   rendering_renderStageFrame
//   rendering_initSprite
//   rendering_drawTrialText
//   rendering_flushDirtySprites
//   rendering_invalidateSprites
//   rendering_createSprite
//   rendering_resizeSprite
//   rendering_getStageProperty
//   rendering_refreshStage
//   rendering_getStageFlags
//   rendering_packColorValue

// ============================================================
// Function: rendering_renderStageFrame (FUN_680cc4d0)
// Address: 680cc4d0
// Size: 79 bytes
// Params: int param_1
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 rendering_renderStageFrame(int param_1)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  float fVar1;
  
  fVar1 = (float)(size_t)(*(int *)(param_1 + 0x13c) - *(int *)(param_1 + 0x134));
  if (fVar1 == 0.0) {
    return (float10)1;
  }
  return (float10)((float)(size_t)(*(int *)(param_1 + 0x14c) - *(int *)(param_1 + 0x144)) / fVar1);
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: rendering_initSprite (FUN_680cc520)
// Address: 680cc520
// Size: 247 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall rendering_initSprite(int *param_1)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int local_24;
  int *local_20;
  int *local_1c;
  undefined1 local_18 [16];
  uint local_8;
  
  local_1c = param_1;
  if (param_1 == (int *)0x0) goto LAB_680cc605;
  rendering_getStageCount();
  local_20 = param_1 + 0x24;
  Ordinal_1060(local_18,param_1[2],param_1[3],param_1[2] + 1,param_1[3] + 1);
  uVar2 = display_initRenderTarget(*(int **)(*param_1 + 8),param_1 + 0x26);
  if ((short)uVar2 == 0) {
    rendering_checkSaveVersion();
    *local_20 = (int)param_1;
    local_20[1] = local_20[3];
    iVar3 = rendering_initSaveBuffer();
    param_1 = local_1c;
    if (iVar3 == 0) goto LAB_680cc5a9;
    piVar1 = *(int **)(*local_1c + 0x20);
    scoreEngine_readCastXtraBlock((int)piVar1,(undefined1 *)&local_24);
    rendering_getStageData(piVar1,(int)param_1,&local_24);
    bitmap_setInvalidRect((int)local_20,1);
  }
  else {
LAB_680cc5a9:
    iVar3 = lingo_getMovieRef(*(int *)(*param_1 + 8));
    if (iVar3 == 0) {
      lingo_formatDebugMsg(*(int **)(*param_1 + 8),-0x19d);
    }
    rendering_getStageCount();
  }
  rendering_updateStageDisplay((int)param_1);
LAB_680cc605:
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: rendering_drawTrialText (FUN_680cc620)
// Address: 680cc620
// Size: 390 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __thiscall rendering_drawTrialText(void *this,int param_1)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int iVar1;
  COLORREF color;
  HGDIOBJ h;
  undefined1 local_44 [8];
  COLORREF local_3c;
  HGDIOBJ local_38;
  int local_34;
  int local_30;
  SIZE local_2c;
  void *local_24;
  undefined4 local_20;
  int local_1c;
  RECT local_18;
  uint local_8;
  
  local_34 = param_1;
  local_20 = 0;
  local_24 = this;
  iVar1 = Ordinal_1805(*(undefined4 *)((int)this + 4),local_44,&local_20);
  if (iVar1 != 0) {
    local_1c = 0;
    iVar1 = Ordinal_2042(*(undefined4 *)((int)this + 4),&local_1c);
    if (iVar1 != 0) {
      (*((int *)&local_2c)) = 0;
      (*((int *)&local_2c + 1)) = 0;
      color = SetBkColor(*(HDC *)(local_1c + 0x10),0xffffff);
      local_3c = SetTextColor(*(HDC *)(local_1c + 0x10),0);
      h = GetStockObject(0xd);
      local_38 = SelectObject(*(HDC *)(local_1c + 0x10),h);
      local_30 = SetBkMode(*(HDC *)(local_1c + 0x10),2);
      if (DAT_6819646c == 0) {
        DAT_6819646c = 0x19;
        GetTextExtentPoint32A(*(HDC *)(local_1c + 0x10)," Adobe Director 12 Trial ",0x19,&local_2c);
        _DAT_68196464 = (*((int *)&local_2c));
        _DAT_68196468 = (*((int *)&local_2c + 1));
      }
      rendering_getStageLayout(local_34,(int)local_24,&(*((int *)&local_18)));
      DrawTextA(*(HDC *)(local_1c + 0x10)," Adobe Director 12 Trial ",DAT_6819646c,&local_18,0x829);
      SetBkMode(*(HDC *)(local_1c + 0x10),local_30);
      SelectObject(*(HDC *)(local_1c + 0x10),local_38);
      SetTextColor(*(HDC *)(local_1c + 0x10),local_3c);
      SetBkColor(*(HDC *)(local_1c + 0x10),color);
      Ordinal_2043(&local_1c);
      this = local_24;
    }
    Ordinal_1806(*(undefined4 *)((int)this + 4),local_44,&local_20);
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: rendering_flushDirtySprites (FUN_680cc7b0)
// Address: 680cc7b0
// Size: 267 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_flushDirtySprites(int param_1,int param_2)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  undefined4 *puVar1;
  void *in_EAX;
  int *piVar2;
  int iVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  local_c = 0;
  if ((*(int *)((int)in_EAX + 0xe4) != 0) &&
     (local_c = Ordinal_1114(*(undefined4 *)((int)in_EAX + 0xdc)), local_c != 0)) {
    local_8 = 0;
    if (0 < *(int *)((int)in_EAX + 0xe4)) {
      do {
        puVar1 = *(undefined4 **)(local_c + local_8 * 4);
        playback_getSpriteData(param_1,puVar1);
        iVar4 = 0;
        if (param_2 != 0) {
          if (*(int *)((int)in_EAX + 0xbc) == 0) {
            iVar3 = 0;
            if (0 < *(int *)((int)in_EAX + 0x2c)) {
              piVar2 = *(int **)((int)in_EAX + 0x24);
              do {
                if (((((int)puVar1[0x32] < piVar2[2]) && (*piVar2 < (int)puVar1[0x34])) &&
                    ((int)puVar1[0x33] < piVar2[3])) && (piVar2[1] < (int)puVar1[0x35]))
                goto LAB_680cc85a;
                iVar4 = 0;
                iVar3 = iVar3 + 1;
                piVar2 = piVar2 + 4;
              } while (iVar3 < *(int *)((int)in_EAX + 0x2c));
            }
          }
          else {
LAB_680cc85a:
            iVar4 = 1;
          }
        }
        if ((*(byte *)(puVar1 + 0x13) & 8) != 0) {
          rendering_renderSprite(iVar4);
        }
        local_8 = local_8 + 1;
      } while (local_8 < *(int *)((int)in_EAX + 0xe4));
    }
    *(undefined4 *)((int)in_EAX + 0xe4) = 0;
  }
  iVar4 = scoreEngine_getChannelType(*(int *)(param_1 + 0x20));
  if (iVar4 != 0) {
    rendering_drawTrialText(in_EAX,param_1);
  }
  if (local_c != 0) {
    Ordinal_1115(*(undefined4 *)((int)in_EAX + 0xdc));
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: rendering_invalidateSprites (FUN_680cc8c0)
// Address: 680cc8c0
// Size: 189 bytes
// Params: void * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_invalidateSprites(void *param_1,int *param_2)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  uint uVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar2 = *(int *)(in_EAX + 0x120);
  if (iVar2 <= *(int *)(in_EAX + 0x124)) {
    iVar3 = iVar2 * 400;
    do {
      if (*(char *)(iVar2 + *(int *)(in_EAX + 0x30)) != '\0') {
        uVar1 = *(uint *)(*(int *)(in_EAX + 0x34) + 0x4c + iVar3);
        iVar4 = *(int *)(in_EAX + 0x34) + iVar3;
        if ((((uVar1 & 1) != 0) && ((uVar1 & 8) != 0)) &&
           ((param_2 == (int *)0x0 ||
            ((((*param_2 < *(int *)(iVar4 + 0xd0) && (*(int *)(iVar4 + 200) < param_2[2])) &&
              (param_2[1] < *(int *)(iVar4 + 0xd4))) && (*(int *)(iVar4 + 0xcc) < param_2[3])))))) {
          rendering_renderSprite(1);
        }
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 400;
    } while (iVar2 <= *(int *)(in_EAX + 0x124));
  }
  iVar2 = scoreEngine_getChannelType(*(int *)(in_EAX + 0x20));
  if (iVar2 != 0) {
    rendering_drawTrialText(param_1,in_EAX);
  }
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: rendering_createSprite (FUN_680cc980)
// Address: 680cc980
// Size: 85 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_createSprite(int param_1,int *param_2,int param_3)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int iVar1;
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (param_2[1] == 0) {
    param_2[1] = param_3;
    *param_2 = param_1;
    param_2[2] = 0;
    param_2[3] = 0;
    param_2[4] = 0;
    param_2[5] = 0;
    iVar1 = rendering_initSprite(param_2);
    if (iVar1 == 0) {
      rendering_getStageState((int)param_2);
      return 0;
    }
  }
  return 1;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: rendering_resizeSprite (FUN_680cc9e0)
// Address: 680cc9e0
// Size: 239 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_resizeSprite(int *param_1,int param_2)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int local_18 [2];
  int local_10;
  int local_c;
  uint local_8;
  
  iVar2 = param_1[5];
  iVar3 = param_1[4];
  if (((iVar3 == 0) || (iVar2 == 0)) || (param_2 != 0)) {
    iVar2 = 1;
    iVar3 = 1;
  }
  display_getRenderTargetSize(param_1 + 0x26,&local_10,(int *)0x0);
  if ((local_10 == iVar3) && (local_c == iVar2)) {
    return 0;
  }
  Ordinal_1060(local_18,param_1[2],param_1[3],param_1[2] + iVar3,param_1[3] + iVar2);
  uVar1 = display_resizeRenderTarget(*(int **)(*param_1 + 8),param_1 + 0x26,local_18);
  if ((short)uVar1 == 0) {
    bitmap_setInvalidRect((int)(param_1 + 0x24),0);
    rendering_updateStageDisplay((int)param_1);
    return 0;
  }
  lingo_formatDebugMsg(*(int **)(*param_1 + 8),-0x19d);
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: rendering_getStageProperty (FUN_680ccad0)
// Address: 680ccad0
// Size: 144 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getStageProperty(int param_1,int param_2)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  if (*(int *)(param_2 + 0xbc) != 0) {
    if (*(int *)(param_2 + 0x18) == 0) {
      if (*(int *)(param_2 + 4) != 0) {
        Ordinal_1826(*(int *)(param_2 + 4),0,*(undefined4 *)(param_2 + 0x94),
                     *(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_2 + 0x2c));
      }
    }
    else {
      rendering_compositeStage(param_2,0);
    }
    *(undefined4 *)(param_2 + 0xbc) = 0;
    Ordinal_1042();
    rendering_flushDirtySprites(param_1,1);
    *(undefined4 *)(param_2 + 0x18) = 0;
    rendering_getStageRef();
    return 0;
  }
  rendering_flushDirtySprites(param_1,0);
  rendering_getStageRef();
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: rendering_refreshStage (FUN_680ccb60)
// Address: 680ccb60
// Size: 80 bytes
// Params: undefined4 param_1, void * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_refreshStage(undefined4 param_1,void *param_2)
{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  if (*(int *)((int)param_2 + 4) != 0) {
    if (*(int *)((int)param_2 + 0xc0) == 0) {
      rendering_compositeStage((int)param_2,1);
      rendering_invalidateSprites(param_2,(int *)0x0);
      Ordinal_1042();
      return 0;
    }
    Ordinal_1821(*(int *)((int)param_2 + 4),0);
  }
  Ordinal_1042();
  return 0;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: rendering_getStageFlags (FUN_680ccbb0)
// Address: 680ccbb0
// Size: 36 bytes
// Params: uint param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_getStageFlags(uint param_1)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  undefined4 uVar1;
  
  uVar1 = 0;
  if (((param_1 & 0x8000) != 0) && ((param_1 >> 0x10 & 0x8000) != 0)) {
    uVar1 = 1;
  }
  return uVar1;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: rendering_packColorValue (FUN_680ccbe0)
// Address: 680ccbe0
// Size: 53 bytes
// Params: byte param_1, byte param_2, byte param_3, ushort param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_packColorValue(byte param_1,byte param_2,byte param_3,ushort param_4)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
      int _param_2; /* FIXUP(C2065): missing Ghidra variable declaration */
    /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '/'): /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '/'): /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '/'): /* FIXUP(C2086: 'int _param_2': redefinition): int _param_2; /* FIXUP(C2065): missing Ghidra variable declaration */ */ */ */ */
  /* FIXUP(C2059-ctx): _param_2 = CONCAT22((param_1 | 0xff80) << 8 | (ushort)param_3, */
                      (param_4 | 0xff80) << 8 | (ushort)param_2);
  return _param_2;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680ccc20 - 0x680cd220
// Functions (9):
//   rendering_loadPalette16
//   rendering_loadPalette256
//   rendering_getStageRef
//   rendering_updateSpriteStream
//   rendering_getStageData2
//   rendering_setStageProperty
//   rendering_updateStageRect
//   rendering_resolvePlaybackMode
//   rendering_clearSpriteStreams

// ============================================================
// Function: rendering_loadPalette16 (FUN_680ccc20)
// Address: 680ccc20
// Size: 391 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall rendering_loadPalette16(undefined4 *param_1)

{
  ushort uVar1;
  int in_EAX;
  ushort *puVar2;
  ushort *puVar3;
  ushort uVar4;
  ushort uVar5;
  undefined4 uVar6;
  int iVar7;
  int local_c;
  uint local_8;
  
  uVar6 = 0;
  local_c = 0;
  if (0 < in_EAX) {
    *param_1 = 0x10;
    local_c = Ordinal_1510(DAT_681956e0,0,in_EAX + 0x1e);
    if (local_c != 0) {
      puVar2 = (ushort *)Ordinal_1512(local_c);
      if (puVar2 != (ushort *)0x0) {
        puVar3 = (ushort *)(param_1 + 4);
        iVar7 = 4;
        do {
          uVar1 = *puVar2 >> 8;
          uVar4 = *puVar2 & 0xff;
          (*(unsigned char *)((char *)&local_8 + 0)) = (undefined1)puVar2[1];
          *puVar3 = uVar4 << 8 | uVar4;
          puVar3[-1] = uVar1 << 8 | uVar1;
          puVar3[1] = CONCAT11((undefined1)local_8,(undefined1)local_8);
          puVar3[-2] = 0;
          uVar1 = puVar2[2] >> 8;
          uVar4 = puVar2[2] & 0xff;
          (*(unsigned char *)((char *)&local_8 + 0)) = (undefined1)puVar2[3];
          puVar3[4] = uVar4 << 8 | uVar4;
          puVar3[5] = CONCAT11((undefined1)local_8,(undefined1)local_8);
          puVar3[3] = uVar1 << 8 | uVar1;
          puVar3[2] = 0;
          uVar1 = puVar2[4] >> 8;
          uVar4 = puVar2[4] & 0xff;
          (*(unsigned char *)((char *)&local_8 + 0)) = (undefined1)puVar2[5];
          puVar3[8] = uVar4 << 8 | uVar4;
          puVar3[7] = uVar1 << 8 | uVar1;
          puVar3[9] = CONCAT11((undefined1)local_8,(undefined1)local_8);
          puVar3[6] = 0;
          uVar1 = puVar2[7];
          uVar4 = puVar2[6] >> 8;
          uVar5 = puVar2[6] & 0xff;
          puVar2 = puVar2 + 8;
          puVar3[0xb] = uVar4 << 8 | uVar4;
          (*(unsigned char *)((char *)&local_8 + 0)) = (undefined1)uVar1;
          puVar3[0xc] = uVar5 << 8 | uVar5;
          puVar3[0xd] = CONCAT11((undefined1)local_8,(undefined1)local_8);
          puVar3[10] = 0;
          puVar3 = puVar3 + 0x10;
          iVar7 = iVar7 + -1;
        } while (iVar7 != 0);
        uVar6 = 1;
        local_8 = (uint)uVar1;
        if (puVar2 != (ushort *)0x0) {
          Ordinal_1513(local_c);
          uVar6 = 1;
        }
      }
      if (local_c != 0) {
        Ordinal_1514(&local_c);
      }
    }
  }
  return uVar6;
}



// ============================================================
// Function: rendering_loadPalette256 (FUN_680ccdb0)
// Address: 680ccdb0
// Size: 504 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_loadPalette256(undefined4 *param_1)

{
  ushort uVar1;
  int in_EAX;
  ushort *puVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  ushort uVar8;
  int iVar9;
  ushort *puVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  undefined4 uVar14;
  int iVar15;
  int iVar16;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  uVar14 = 0;
  local_10 = 0;
  if (0 < in_EAX) {
    *param_1 = 0x100;
    local_10 = Ordinal_1510(DAT_681956e0,0,in_EAX + 0x28);
    if (local_10 != 0) {
      puVar2 = (ushort *)Ordinal_1512(local_10);
      if (puVar2 != (ushort *)0x0) {
        local_8 = 0;
        local_c = 0;
        iVar13 = 0x7fc0;
        iVar15 = 0x7fc0;
        iVar16 = 0x7fc0;
        do {
          puVar10 = puVar2 + 1;
          uVar1 = *puVar2;
          puVar2 = puVar2 + 2;
          uVar3 = (uint)(uVar1 >> 8);
          iVar12 = (*puVar10 & 0xff) * 0x80 + 0x40;
          iVar4 = (uVar1 & 0xff) * 0x80 + 0x40;
          iVar9 = (uint)(*puVar10 >> 8) * 0x80 + 0x40;
          if (local_8 < (int)uVar3) {
            local_14 = uVar3 - local_8;
            iVar5 = (iVar4 - iVar15) / local_14;
            iVar6 = (iVar9 - iVar16) / local_14;
            iVar7 = (iVar12 - iVar13) / local_14;
            if (local_8 < (int)uVar3) {
              puVar10 = (ushort *)(param_1 + local_c * 2 + 4);
              local_8 = local_8 + local_14;
              local_c = local_c + local_14;
              do {
                uVar3 = iVar15 >> 7 & 0xff;
                uVar1 = (ushort)uVar3;
                puVar10[-1] = uVar1;
                puVar10[-1] = (ushort)(uVar3 << 8) | uVar1;
                uVar3 = iVar16 >> 7 & 0xff;
                uVar1 = (ushort)uVar3;
                *puVar10 = uVar1;
                iVar15 = iVar15 + iVar5;
                iVar16 = iVar16 + iVar6;
                *puVar10 = (ushort)(uVar3 << 8) | uVar1;
                uVar3 = iVar13 >> 7 & 0xff;
                uVar1 = (ushort)uVar3;
                puVar10[1] = uVar1;
                puVar10[1] = (ushort)(uVar3 << 8) | uVar1;
                puVar10[-2] = 0;
                puVar10 = puVar10 + 4;
                local_14 = local_14 + -1;
                iVar13 = iVar13 + iVar7;
              } while (local_14 != 0);
            }
          }
          iVar13 = iVar12;
          iVar15 = iVar4;
          iVar16 = iVar9;
        } while (local_8 < 0xff);
        uVar3 = iVar4 >> 7 & 0xff;
        uVar1 = (ushort)uVar3;
        *(ushort *)((int)param_1 + local_c * 8 + 0xe) = uVar1;
        uVar11 = iVar9 >> 7 & 0xff;
        uVar8 = (ushort)uVar11;
        *(ushort *)(param_1 + local_c * 2 + 4) = uVar8;
        *(ushort *)(param_1 + local_c * 2 + 4) = (ushort)(uVar11 << 8) | uVar8;
        uVar11 = iVar12 >> 7 & 0xff;
        uVar8 = (ushort)uVar11;
        *(ushort *)((int)param_1 + local_c * 8 + 0x12) = uVar8;
        *(ushort *)((int)param_1 + local_c * 8 + 0xe) = (ushort)(uVar3 << 8) | uVar1;
        *(ushort *)((int)param_1 + local_c * 8 + 0x12) = (ushort)(uVar11 << 8) | uVar8;
        *(undefined2 *)(param_1 + local_c * 2 + 3) = 0;
        uVar14 = 1;
        if (puVar2 != (ushort *)0x0) {
          Ordinal_1513(local_10);
          uVar14 = 1;
        }
      }
      if (local_10 != 0) {
        Ordinal_1514(&local_10);
      }
    }
  }
  return uVar14;
}



// ============================================================
// Function: rendering_getStageRef (FUN_680ccfb0)
// Address: 680ccfb0
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getStageRefById(int param_1)
{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x30) = 0;
    *(undefined4 *)(param_1 + 0x34) = 0;
  }
  return 0;
}



// ============================================================
// Function: rendering_updateSpriteStream (FUN_680ccfd0)
// Address: 680ccfd0
// Size: 181 bytes
// Params: int * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint rendering_updateSpriteStream(int *param_1)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  
  piVar2 = param_1;
  iVar1 = param_1[0x23];
  uVar3 = 0;
  if (iVar1 == 0) {
    uVar3 = param_1[0x1b];
    if (uVar3 != 0) {
      Ordinal_1293(param_1 + 0xe);
    }
  }
  else {
    param_1 = (int *)0x0;
    if (*(int *)(iVar1 + 0x70) == 0) {
      iVar4 = Ordinal_1541();
      uVar3 = iVar4 - *(int *)(iVar1 + 4);
      *(uint *)(iVar1 + 0x54) = uVar3;
      if (*(uint *)(iVar1 + 8) <= uVar3) {
        *(uint *)(iVar1 + 8) = uVar3 + 5;
        if (30000 < (int)uVar3) {
          *(undefined4 *)(iVar1 + 0x70) = 1;
          return 0;
        }
        iVar4 = media_callSpriteMethodEx(*(int *)(*piVar2 + 8),*(int **)(iVar1 + 0xc),iVar1 + 0x2c,iVar1 + 0x10,
                             iVar1 + 0x5c,iVar1 + 0x48,&param_1);
        if ((iVar4 != 0) || (param_1 != (int *)0x0)) {
          *(undefined4 *)(iVar1 + 0x70) = 1;
          return (uint)(iVar4 == 0);
        }
      }
      return 1;
    }
  }
  return uVar3;
}



// ============================================================
// Function: rendering_getStageData2 (FUN_680cd090)
// Address: 680cd090
// Size: 226 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_getStageData2(int *param_1)
{
  undefined4 *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar3 = param_1;
  puVar1 = (undefined4 *)param_1[0x23];
  if (puVar1 == (undefined4 *)0x0) {
    Ordinal_1294(param_1 + 0xe);
  }
  else {
    if (puVar1[0x1b] != 0) {
      iVar4 = Ordinal_1541();
      puVar1[0x15] = iVar4 - puVar1[1];
      media_callSpriteAccessor(*(int *)(*piVar3 + 8),(int *)puVar1[3],puVar1 + 0xb,puVar1 + 4,puVar1 + 0x17,
                   puVar1 + 0x12);
    }
    if (puVar1[0x1e] != 0) {
      crt_getMovieApiState(puVar1 + 0xb);
    }
    if (puVar1[0x1d] != 0) {
      crt_getMovieApiState(puVar1 + 4);
    }
    if ((int *)puVar1[3] != (int *)0x0) {
      if ((*piVar3 == 0) || (piVar2 = *(int **)(*piVar3 + 0x20), piVar2 == (int *)0x0)) {
        iVar4 = 0;
      }
      else {
        iVar4 = *piVar2;
      }
      media_dispatchRelease(iVar4,(int *)puVar1[3]);
    }
    param_1 = (int *)*puVar1;
    Ordinal_1115(param_1);
    Ordinal_1113(&param_1);
    piVar3[0x23] = 0;
  }
  if (*(short *)((int)piVar3 + 0x8a) != 0) {
    iVar4 = rendering_resolveState(*(int *)(*piVar3 + 8),piVar3[0x22]);
    if (iVar4 != 0) {
      rendering_isStateValid(iVar4);
    }
    piVar3[0x22] = 0;
  }
  return 0;
}



// ============================================================
// Function: rendering_setStageProperty (FUN_680cd180)
// Address: 680cd180
// Size: 40 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 rendering_setStageProperty(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x20) + 0x658) == 0) {
    uVar1 = Ordinal_1754(*(undefined4 *)(param_2 + 4));
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: rendering_updateStageRect (FUN_680cd1b0)
// Address: 680cd1b0
// Size: 75 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_updateStageRect(int param_1,int param_2)
{
  undefined4 uVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x20) + 0x658) == 0) {
    Ordinal_1756(*(undefined4 *)(param_2 + 4));
    *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_2 + 0x30);
    return 0;
  }
  uVar1 = Ordinal_1610(*(undefined4 *)(param_2 + 0x94));
  Ordinal_1836(*(undefined4 *)(param_2 + 4),uVar1);
  *(undefined4 *)(param_2 + 0x34) = *(undefined4 *)(param_2 + 0x30);
  return 0;
}



// ============================================================
// Function: rendering_resolvePlaybackMode (FUN_680cd200)
// Address: 680cd200
// Size: 26 bytes
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint rendering_resolvePlaybackMode(void)

{
  int iVar1;
  
  iVar1 = Ordinal_1755();
  if (iVar1 == 1) {
    return 1;
  }
  if (iVar1 - 2U != 0) {
    return iVar1 - 2U & 0xffffff00;
  }
  return 2;
}



// ============================================================
// Function: rendering_clearSpriteStreams (FUN_680cd220)
// Address: 680cd220
// Size: 104 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int rendering_clearSpriteStreams(int param_1)
{
  int iVar1;
  int iVar2;
  
  if (*(int *)(param_1 + 0x614) != 0) {
    iVar1 = Ordinal_1114(*(int *)(param_1 + 0x614));
    iVar2 = 0;
    if (0 < *(int *)(param_1 + 0x60c)) {
      do {
        Ordinal_1733(iVar1);
        iVar2 = iVar2 + 1;
        iVar1 = iVar1 + 0xc;
      } while (iVar2 < *(int *)(param_1 + 0x60c));
    }
    Ordinal_1115(*(undefined4 *)(param_1 + 0x614));
  }
  if (*(int *)(param_1 + 0x614) != 0) {
    Ordinal_1113((int *)(param_1 + 0x614));
    *(undefined4 *)(param_1 + 0x60c) = 0;
    *(undefined4 *)(param_1 + 0x610) = 0;
  }
  return 0;
}



// Source: decompiled_functions.c
// Module: rendering
// Address range: 0x680cd290 - 0x680cd830
// Functions (10):
//   rendering_processStagePalette
//   rendering_transformPaletteData
//   rendering_initPaletteState
//   rendering_initScorePalette
//   rendering_freeScorePalette
//   rendering_comparePaletteEntry
//   rendering_convertPaletteEntry
//   rendering_blendPaletteEntry
//   rendering_applyStageOffset
//   rendering_setupStageTransition


/* FIXUP(STUB-FILE): All functions in this file have been stubbed out.
   The Ghidra decompilation produced code with severe structural issues
   (broken switch statements, missing variables, invalid casts) that
   could not be automatically repaired. Each function needs manual
   review against the original binary to restore correct logic. */

int rendering_processStagePalette(int param_1,undefined4 param_2,int *param_3,int *param_4)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

int rendering_transformPaletteData(int *param_1,undefined4 param_2,int *param_3)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

int rendering_initPaletteState(void)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

undefined4 rendering_initScorePalette(int param_1)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

int rendering_freeScorePalette(int param_1)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

undefined4 rendering_comparePaletteEntry(uint param_1,uint param_2)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

undefined4 rendering_convertPaletteEntry(uint param_1,uint param_2)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

undefined4 rendering_blendPaletteEntry(uint param_1,uint param_2)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

int rendering_applyStageOffset(int *param_1,int param_2,undefined4 param_3)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

int __thiscall rendering_setupStageTransition(void *this,int *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
            undefined4 param_6,undefined4 param_7,short param_8,short param_9,undefined1 param_10,
            undefined1 param_11,undefined1 param_12)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

