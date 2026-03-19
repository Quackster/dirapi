// Module: stage
// Topic: Rendering, frame management, and plugins
// Address range: 0x6805ED10 - 0x6805F1A0
// Functions (18):
//   stage_renderFrame (FUN_6805ED10)
//   stage_refreshDisplay (FUN_6805ED50)
//   stage_renderSprites (FUN_6805ED70)
//   stage_drawScore (FUN_6805ED90)
//   stage_updateChannels (FUN_6805EDD0)
//   stage_renderSpritesAtFrame (FUN_6805EDF0)
//   stage_drawScoreAtFrame (FUN_6805EE40)
//   stage_updateChannelsAtFrame (FUN_6805EEA0)
//   stage_dispatchEvent (FUN_6805EF00)
//   stage_swapFrameData (FUN_6805EF20)
//   stage_bindMovie (FUN_6805F010)
//   stage_releaseCastObjects (FUN_6805F030)
//   stage_detachSprite (FUN_6805F070)
//   Ordinal_77 (FUN_6805F0D0)
//   stage_handleBehaviorEvent (FUN_6805F100)
//   stage_syncPalette (FUN_6805F150)
//   stage_checkPlugins (FUN_6805f180)
//   stage_updatePluginCount (FUN_6805F1A0)

// ============================================================
// Function: stage_renderFrame (FUN_6805ed10)
// Address: 6805ed10
// Size: 56 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_renderFrame(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  
  if (param_1 != 0) {
    events_handleWindowResize(param_1);
    events_processMovieEvent(param_1);
    events_requestMovieAction(param_1);
    if (param_2 != (undefined4 *)0x0) {
      puVar2 = (undefined4 *)(param_1 + 0x1fc);
      for (iVar1 = 0x106; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar2 = *param_2;
        param_2 = param_2 + 1;
        puVar2 = puVar2 + 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: stage_refreshDisplay (FUN_6805ed50)
// Address: 6805ed50
// Size: 20 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_refreshDisplay(int param_1)
{
  if (param_1 != 0) {
    events_processMovieEvent(param_1);
  }
  return 0;
}



// ============================================================
// Function: stage_renderSprites (FUN_6805ed70)
// Address: 6805ed70
// Size: 24 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_renderSprites(int *param_1)
{
  events_notifyWindowClose(param_1);
  events_notifyFocusChange(param_1);
  return 0;
}



// ============================================================
// Function: stage_drawScore (FUN_6805ed90)
// Address: 6805ed90
// Size: 63 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_drawScore(int param_1)
{
  if (param_1 != 0) {
    if (*(int **)(param_1 + 0x71c) != (int *)0x0) {
      cast_wrapApiCall(*(undefined4 *)(param_1 + 0xc),*(int **)(param_1 + 0x71c),0x36);
    }
    sprites_handleEditCommand(param_1,0xc);
    scoreEngine_writePropertyBlock(*(int *)(param_1 + 0x20),*(int *)(param_1 + 0x24),0x10,0);
  }
  return 0;
}



// ============================================================
// Function: stage_updateChannels (FUN_6805edd0)
// Address: 6805edd0
// Size: 20 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_updateChannels(int param_1)
{
  if (param_1 != 0) {
    events_handleIdleEvent(param_1);
  }
  return 0;
}



// ============================================================
// Function: stage_renderSpritesAtFrame (FUN_6805edf0)
// Address: 6805edf0
// Size: 77 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_renderSpritesAtFrame(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar1 = param_1[10];
  iVar2 = param_1[9];
  param_1[9] = param_2;
  iVar4 = scoreEngine_accessProperty(param_1[8],param_2);
  param_1[10] = iVar4;
  iVar4 = param_1[3];
  uVar3 = *(undefined4 *)(iVar4 + 8);
  *(undefined4 *)(iVar4 + 8) = *(undefined4 *)(iVar4 + 0xc);
  stage_renderSprites(param_1);
  param_1[9] = iVar2;
  param_1[10] = iVar1;
  *(undefined4 *)(param_1[3] + 8) = uVar3;
  return 0;
}



// ============================================================
// Function: stage_drawScoreAtFrame (FUN_6805ee40)
// Address: 6805ee40
// Size: 81 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_drawScoreAtFrame(int param_1,int param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x28);
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    *(int *)(param_1 + 0x24) = param_2;
    uVar4 = scoreEngine_accessProperty(*(int *)(param_1 + 0x20),param_2);
    *(undefined4 *)(param_1 + 0x28) = uVar4;
    iVar3 = *(int *)(param_1 + 0xc);
    uVar4 = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0xc);
    stage_drawScore(param_1);
    *(undefined4 *)(param_1 + 0x24) = uVar2;
    *(undefined4 *)(param_1 + 0x28) = uVar1;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 8) = uVar4;
  }
  return 0;
}



// ============================================================
// Function: stage_updateChannelsAtFrame (FUN_6805eea0)
// Address: 6805eea0
// Size: 81 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_updateChannelsAtFrame(int param_1,int param_2)
{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  if (param_1 != 0) {
    uVar1 = *(undefined4 *)(param_1 + 0x28);
    uVar2 = *(undefined4 *)(param_1 + 0x24);
    *(int *)(param_1 + 0x24) = param_2;
    uVar4 = scoreEngine_accessProperty(*(int *)(param_1 + 0x20),param_2);
    *(undefined4 *)(param_1 + 0x28) = uVar4;
    iVar3 = *(int *)(param_1 + 0xc);
    uVar4 = *(undefined4 *)(iVar3 + 8);
    *(undefined4 *)(iVar3 + 8) = *(undefined4 *)(iVar3 + 0xc);
    stage_updateChannels(param_1);
    *(undefined4 *)(param_1 + 0x24) = uVar2;
    *(undefined4 *)(param_1 + 0x28) = uVar1;
    *(undefined4 *)(*(int *)(param_1 + 0xc) + 8) = uVar4;
  }
  return 0;
}



// ============================================================
// Function: stage_dispatchEvent (FUN_6805ef00)
// Address: 6805ef00
// Size: 28 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchEvent(int param_1,undefined4 param_2,int param_3,undefined4 param_4)
{
  events_resolveScriptHandler(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: stage_swapFrameData (FUN_6805ef20)
// Address: 6805ef20
// Size: 232 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_swapFrameData(int param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  
  if ((param_2 != 0) && (param_1 != 0)) {
    iVar4 = *(int *)(param_2 + 0xc);
    iVar1 = *(int *)(param_1 + 0xc);
    *(undefined4 *)(param_1 + 0x714) = *(undefined4 *)(param_2 + 0x714);
    *(undefined4 *)(param_2 + 0x714) = 0;
    *(undefined4 *)(param_1 + 0x718) = *(undefined4 *)(param_2 + 0x718);
    *(undefined4 *)(param_2 + 0x718) = 0;
    if ((iVar4 != 0) && (iVar1 != 0)) {
      uVar2 = *(undefined4 *)(iVar1 + 200);
      uVar3 = *(undefined4 *)(iVar1 + 0xcc);
      *(undefined4 *)(iVar1 + 0xbc) = *(undefined4 *)(iVar4 + 0xbc);
      *(undefined4 *)(iVar1 + 0xc0) = *(undefined4 *)(iVar4 + 0xc0);
      *(undefined4 *)(iVar1 + 0xc4) = *(undefined4 *)(iVar4 + 0xc4);
      *(undefined4 *)(iVar1 + 200) = *(undefined4 *)(iVar4 + 200);
      *(undefined4 *)(iVar1 + 0xcc) = *(undefined4 *)(iVar4 + 0xcc);
      *(undefined4 *)(iVar1 + 0xd0) = *(undefined4 *)(iVar4 + 0xd0);
      *(undefined4 *)(iVar4 + 200) = uVar2;
      *(undefined4 *)(iVar4 + 0xcc) = uVar3;
      iVar4 = 0;
      if (0 < *(int *)(iVar1 + 0xbc)) {
        iVar5 = 0;
        do {
          *(undefined4 *)(**(int **)(iVar1 + 200) + 0x20 + iVar5) = 0xffffffff;
          iVar4 = iVar4 + 1;
          iVar5 = iVar5 + 0xc;
        } while (iVar4 < *(int *)(iVar1 + 0xbc));
      }
    }
  }
  return 0;
}



// ============================================================
// Function: stage_bindMovie (FUN_6805f010)
// Address: 6805f010
// Size: 26 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_bindMovie(int param_1,int param_2)
{
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(param_2 + 0xc);
    *(int *)(param_1 + 0x2c) = param_2;
  }
  return 0;
}



// ============================================================
// Function: stage_releaseCastObjects (FUN_6805f030)
// Address: 6805f030
// Size: 51 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_releaseCastObjects(int param_1)
{
  int iVar1;
  
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0xc), iVar1 != 0)) {
    cast_releaseObject(iVar1,*(int **)(param_1 + 0x714));
    cast_releaseObject(iVar1,*(int **)(param_1 + 0x71c));
  }
  return 0;
}



// ============================================================
// Function: stage_detachSprite (FUN_6805f070)
// Address: 6805f070
// Size: 92 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_detachSprite(int param_1,int param_2)
{
  undefined4 uVar1;
  
  Ordinal_1473(param_2);
  if (param_1 != 0) {
    uVar1 = scoreEngine_setPropertyAccess(*(int *)(param_1 + 0x20));
    if (*(int *)(param_1 + 0x28) == param_2) {
      *(undefined4 *)(param_1 + 0x28) = uVar1;
    }
    if (*(int *)(param_1 + 0x24) == param_2) {
      *(undefined4 *)(param_1 + 0x24) = 0;
    }
    if (*(int *)(param_1 + 0x80) == param_2) {
      *(undefined4 *)(param_1 + 0x80) = 0;
    }
    if (*(int *)(param_1 + 0x3c) == param_2) {
      *(undefined4 *)(param_1 + 0x3c) = 0;
    }
    if (*(int *)(param_1 + 0x73c) == param_2) {
      *(undefined4 *)(param_1 + 0x73c) = 0;
    }
  }
  return 0;
}



// ============================================================
// Function: Ordinal_77
// Address: 6805f0d0
// Size: 33 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_77(int *param_1,int *param_2)
{
                    /* 0x5f0d0  77   */
  if ((param_1 != (int *)0x0) && (*(int *)(*param_1 + 0x50) != 0)) {
    sprites_dispatchBehavior(*param_1,param_2);
  }
  return 0;
}



// ============================================================
// Function: stage_handleBehaviorEvent (FUN_6805f100)
// Address: 6805f100
// Size: 77 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_handleBehaviorEvent(int *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = *param_1;
  sprites_dispatchBehavior(iVar1,param_2);
  if ((*(int *)(iVar1 + 0x50) != 0) && (*param_2 == 0x18)) {
    uVar2 = sprites_refreshTextDisplay(*(int **)(iVar1 + 0x4c),param_2[6],param_2[7]);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: stage_syncPalette (FUN_6805f150)
// Address: 6805f150
// Size: 34 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_syncPalette(int param_1)
{
  if (param_1 != 0) {
    Ordinal_215(*(int *)(param_1 + 0x20),param_1 + 0x1e8,0,1);
  }
  return 0;
}



// ============================================================
// Function: stage_checkPlugins (FUN_6805f180)
// Address: 6805f180
// Size: 18 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_checkPlugins(int param_1)

{
  return 0 < *(int *)(param_1 + 0x5c);
}



// ============================================================
// Function: stage_updatePluginCount (FUN_6805f1a0)
// Address: 6805f1a0
// Size: 30 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_updatePluginCount(int param_1,int param_2)
{
  if (param_1 != 0) {
    if (param_2 != 0) {
      *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + 1;
      return 0;
    }
    *(int *)(param_1 + 0x5c) = *(int *)(param_1 + 0x5c) + -1;
  }
  return 0;
}



