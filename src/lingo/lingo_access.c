// Module: lingo
// Topic: Score property getters and query functions
// Address range: 0x68090C00 - 0x6809B8B0
// Functions (36):
//   lingo_destroyLifecycleData
//   lingo_getLifecycleRef
//   Ordinal_45
//   lingo_getPlaybackSize
//   lingo_getMovieInfoWrapped
//   Ordinal_54
//   Ordinal_56
//   lingo_setDisplayFlag
//   lingo_getDisplayFlag
//   Ordinal_60
//   lingo_loadMovieData
//   lingo_getDebugDataWrapped
//   Ordinal_164
//   Ordinal_163
//   Ordinal_106
//   lingo_copyToClipboard
//   Ordinal_70
//   lingo_checkObjectValid
//   lingo_isValidObject
//   lingo_isValidRef
//   lingo_getObjectFlags
//   lingo_getObjectField114
//   lingo_getObjectField118
//   lingo_getMovieRef
//   lingo_executeMethod
//   lingo_dispatchMethod
//   lingo_isScriptReady
//   lingo_getMovieInfo
//   score_dispose
//   score_saveMovie
//   score_setProperty
//   score_create
//   score_createLinked
//   score_loadMovie
//   score_onPaused
//   lingo_noop


// ============================================================
// Function: lingo_destroyLifecycleData (FUN_68090c00)
// Address: 68090c00
// Size: 13 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_destroyLifecycleData(int param_1)

{
  return *(undefined4 *)(param_1 + 0x1c);
}



// ============================================================
// Function: lingo_getLifecycleRef (FUN_680917e0)
// Address: 680917e0
// Size: 33 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getLifecycleRef(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(*(int *)(param_1 + 0x20) + 8);
  }
  return *(undefined4 *)(iRam00000020 + 8);
}



// ============================================================
// Function: Ordinal_45
// Address: 68092840
// Size: 196 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_45(int param_1,undefined4 *param_2)
{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int *local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x92840  45   */
  iVar2 = 0;
  if (param_1 == 0) {
    local_18 = (int *)0x0;
  }
  else {
    local_18 = *(int **)(param_1 + 0x20);
  }
  if ((local_18 != (int *)0x0) && (local_18[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *local_18;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  if (param_2 != (undefined4 *)0x0) {
    if (*(int *)(*(int *)(iVar2 + 0x20) + 0x444) == 0) {
      Ordinal_1130(param_2,0x418);
    }
    else {
      puVar3 = (undefined4 *)(*(int *)(iVar2 + 0x20) + 0x28);
      for (iVar1 = 0x106; iVar1 != 0; iVar1 = iVar1 + -1) {
        *param_2 = *puVar3;
        puVar3 = puVar3 + 1;
        param_2 = param_2 + 1;
      }
    }
  }
  if (local_18 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_getPlaybackSize (FUN_68093fa0)
// Address: 68093fa0
// Size: 144 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getPlaybackSize(int param_1)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  playback_getLifecycleSize(iVar1);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_getMovieInfoWrapped (FUN_68094030)
// Address: 68094030
// Size: 95 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getMovieInfoWrapped(undefined4 *param_1)
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
  lingo_getMovieInfo((int)param_1);
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_54
// Address: 68094970
// Size: 174 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_54(int param_1,undefined4 *param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x94970  54   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    iVar1 = *(int *)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  if ((piVar2[1] != -0x24) && (param_2 != (undefined4 *)0x0)) {
    *param_2 = *(undefined4 *)(piVar2[1] + 0x28);
  }
  lingo_getMovieRef(iVar1);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_56
// Address: 68094cb0
// Size: 600 bytes
// Params: int param_1, byte * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_56(int param_1,byte *param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  short sVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  int local_1c;
  byte *local_18;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x94cb0  56   */
  if (param_3 == (undefined4 *)0x0) {
    return 0;
  }
  puVar1 = *(undefined4 **)(param_1 + 0x20);
  local_18 = (byte *)0x0;
  local_1c = 0;
  if ((puVar1 != (undefined4 *)0x0) && (puVar1[1] != 0)) {
    local_1c = *(int *)(puVar1[1] + 8);
    if (param_2 == (byte *)0x0) {
      local_18 = (byte *)*puVar1;
    }
    else {
      local_18 = param_2;
    }
    Ordinal_2330();
    local_c = 0;
    local_14 = local_18;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
  }
  iVar4 = Ordinal_45(param_1,(undefined4 *)0x0);
  if (iVar4 == 0) {
    Ordinal_1130(param_3,0x1464);
    *param_3 = *(undefined4 *)(*(int *)(local_18 + 0x20) + 0x500);
    Ordinal_1309(param_3 + 10,0x400,"",2);
  }
  else {
    param_3[8] = (int)*(short *)(*(int *)(local_18 + 0x20) + 0x494);
    param_3[7] = (int)*(short *)(*(int *)(local_18 + 0x20) + 0x496);
    param_3[5] = (int)*(short *)(*(int *)(local_18 + 0x20) + 0x492);
    param_3[6] = (int)*(short *)(*(int *)(local_18 + 0x20) + 0x490);
    uVar5 = playback_getMaxFrame(local_18);
    param_3[2] = uVar5;
    *param_3 = *(undefined4 *)(*(int *)(local_18 + 0x20) + 0x500);
    sVar2 = rendering_getChannelType(*(int *)(local_18 + 0x20) + 0x48c);
    *(short *)(param_3 + 1) = sVar2;
    param_3[3] = 0;
    *(undefined2 *)(param_3 + 4) = 0;
    *(undefined2 *)(param_3 + 9) = 0;
    uVar3 = scoreEngine_getCastVersion(*(int *)(local_18 + 0x20));
    *(undefined2 *)((int)param_3 + 0x26) = uVar3;
    puVar6 = (undefined4 *)(*(int *)(local_18 + 0x20) + 0x28);
    puVar7 = param_3 + 10;
    for (iVar4 = 0x106; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar7 = *puVar6;
      puVar6 = puVar6 + 1;
      puVar7 = puVar7 + 1;
    }
    param_3[0x110] = *(undefined4 *)(*(int *)(local_18 + 0x20) + 0x1c);
    param_3[0x312] = *(undefined4 *)(*(int *)(local_18 + 0x20) + 0x4e0);
    param_3[0x313] = *(undefined4 *)(*(int *)(local_18 + 0x20) + 0x4b8);
    param_3[0x314] = *(undefined4 *)(*(int *)(local_18 + 0x20) + 0x4bc);
    param_3[0x315] = *(undefined4 *)(*(int *)(local_18 + 0x20) + 0x4e4);
    param_3[0x316] = *(undefined4 *)(*(int *)(local_18 + 0x20) + 0x4e8);
    param_3[0x317] = *(undefined4 *)(*(int *)(local_18 + 0x20) + 0x4ec);
    if (*(int *)(*(int *)(local_18 + 0x20) + 0x46c) != 0) {
      iVar4 = Ordinal_38(*(int *)(*(int *)(local_18 + 0x20) + 0x46c),9,param_3 + 0x318,0x3ff);
      if (iVar4 == 0) {
        *(undefined1 *)((int)param_3 + 0xc61) = 0;
        *(undefined1 *)(param_3 + 0x318) = 0;
      }
      iVar4 = Ordinal_38(*(int *)(*(int *)(local_18 + 0x20) + 0x46c),10,
                         (undefined1 *)((int)param_3 + 0x105f),0x3fe);
      if (iVar4 == 0) {
        *(undefined1 *)(param_3 + 0x418) = 0;
        *(undefined1 *)((int)param_3 + 0x105f) = 0;
      }
    }
    param_3[0x518] = (int)*(char *)(*(int *)(local_18 + 0x20) + 0x4c0);
  }
  lingo_getMovieRef(local_1c);
  if (puVar1 != (undefined4 *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_setDisplayFlag (FUN_68094f10)
// Address: 68094f10
// Size: 139 bytes
// Params: int param_1, int param_2, undefined1 * param_3, byte param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setDisplayFlag(int param_1,int param_2,undefined1 *param_3,byte param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((param_4 & 2) != 0) {
    *(undefined1 *)(*(int *)(iVar2 + 0x20) + 0x5f9) = *param_3;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_getDisplayFlag (FUN_68094fa0)
// Address: 68094fa0
// Size: 140 bytes
// Params: int param_1, int param_2, undefined1 * param_3, byte param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getDisplayFlag(int param_1,int param_2,undefined1 *param_3,byte param_4)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar2 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if ((param_4 & 2) != 0) {
    *param_3 = *(undefined1 *)(*(int *)(iVar2 + 0x20) + 0x5f9);
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_60
// Address: 680955a0
// Size: 226 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_60(int param_1,undefined4 *param_2)
{
  int local_2c;
  BITMAPINFO *lpbmi;
  int iVar1;
  int *piVar2;
  int local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x955a0  60   */
  local_18 = 1;
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
    if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
      if ((piVar2 == (int *)0x0) || (iVar1 = *piVar2, iVar1 == 0)) {
        iVar1 = *piVar2;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar1;
    }
  }
  iVar1 = Ordinal_2040(*(undefined4 *)(piVar2[1] + 0xb8),&local_1c);
  if (iVar1 == 0) {
    local_18 = 0;
  }
  else {
    lpbmi = *(BITMAPINFO **)(local_1c + 0x1c);
    StretchDIBits((HDC)*param_2,param_2[1],param_2[2],param_2[3],param_2[4],0,0,
                  (lpbmi->bmiHeader).biWidth,(lpbmi->bmiHeader).biHeight,*(void **)(local_1c + 0x18)
                  ,lpbmi,0,0xcc0020);
    Ordinal_2041(&local_1c);
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_loadMovieData (FUN_68095690)
// Address: 68095690
// Size: 136 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_loadMovieData(int param_1,undefined4 *param_2)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  lingo_getDebugContext(piVar1[1],param_2);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_getDebugDataWrapped (FUN_68095720)
// Address: 68095720
// Size: 136 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getDebugDataWrapped(int param_1,undefined4 *param_2)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
  }
  lingo_getDebugData(piVar1[1],param_2);
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_164
// Address: 680957b0
// Size: 150 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_164(int param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x957b0  164   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  scoreEngine_getChannelRect(*(int *)(iVar1 + 0x20),param_2);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_163
// Address: 68095850
// Size: 146 bytes
// Params: int param_1, undefined2 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_163(int param_1,undefined2 *param_2)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x95850  163   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  iVar1 = 0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar1 = **(int **)(param_1 + 0x20), iVar1 == 0)
        ))) {
      iVar1 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar1;
  }
  scoreEngine_setChannelRect(*(int *)(iVar1 + 0x20),param_2);
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_106
// Address: 680958f0
// Size: 202 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_106(int param_1,undefined4 *param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x958f0  106   */
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  if (param_1 == 0) {
    piVar1 = (int *)0x0;
  }
  else {
    piVar1 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar2 = *(int *)(piVar1[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar1;
    }
    Ordinal_2330();
    local_10 = DAT_68196374;
    local_c = 0;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  if (piVar1[1] != -0x24) {
    *param_2 = *(undefined4 *)(piVar1[1] + 0xb8);
    lingo_getMovieRef(iVar2);
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_copyToClipboard (FUN_680959c0)
// Address: 680959c0
// Size: 540 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_copyToClipboard(int param_1)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int local_74;
  undefined4 local_70;
  int local_6c;
  int local_68;
  undefined4 local_64;
  undefined4 local_60;
  undefined4 local_5c;
  undefined4 local_58;
  undefined4 local_54;
  int local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  int local_38;
  int *local_34;
  undefined4 local_30;
  undefined4 local_2c [5];
  undefined1 local_18 [8];
  undefined4 local_10;
  uint local_8;
  
  local_74 = 0;
  local_70 = 0;
  bVar1 = false;
  local_64 = 0;
  local_60 = 0;
  local_5c = 0;
  local_58 = 0;
  local_54 = 0;
  local_50 = 0;
  local_4c = 0;
  local_48 = 0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_6c = 0;
  local_68 = 0;
  if (param_1 == 0) {
    piVar5 = (int *)0x0;
  }
  else {
    piVar5 = *(int **)(param_1 + 0x20);
    if ((piVar5 != (int *)0x0) && (piVar5[1] != 0)) {
      if ((piVar5 == (int *)0x0) || (iVar4 = *piVar5, iVar4 == 0)) {
        iVar4 = *piVar5;
      }
      Ordinal_2330();
      local_30 = 0;
      local_34 = DAT_68196374;
      DAT_68196374 = &local_38;
      local_38 = iVar4;
    }
  }
  iVar4 = piVar5[1];
  local_74 = Ordinal_1111(0,0);
  if (local_74 != 0) {
    iVar2 = Ordinal_1404(&local_70,local_74,3);
    if (iVar2 != 0) {
      iVar2 = Ordinal_1610(*(undefined4 *)(iVar4 + 0xc0));
      if (iVar2 != 0) {
        iVar3 = Ordinal_1656(*(undefined4 *)(iVar4 + 0xd4),&local_64);
        if (iVar3 != 0) {
          if (local_50 == 0x18) {
            local_10 = 0;
            local_68 = Ordinal_1600();
            local_6c = Ordinal_1650(0x20,0,0,local_60,local_64,1);
            if (local_6c == 0) goto LAB_68095b86;
            Ordinal_1604(local_68,local_6c);
            Ordinal_1060(local_18,0,0,local_60,local_64);
            local_2c[0] = 0;
            iVar4 = Ordinal_1616(local_68,local_18,*(undefined4 *)(iVar4 + 0xc0),local_18,0,0,
                                 local_2c,0,0);
            if (iVar4 == 0) goto LAB_68095b86;
            Ordinal_1604(local_68,0);
            iVar4 = local_6c;
          }
          else {
            if (local_50 == 0x20) {
              iVar3 = Ordinal_1684(*(undefined4 *)(iVar4 + 0xd4),0xff);
              if (iVar3 == 0) goto LAB_68095b86;
            }
            iVar4 = *(int *)(iVar4 + 0xd4);
          }
          iVar4 = Ordinal_1660(local_70,iVar4,iVar2,FOURCC_PICH,0);
          if (iVar4 != 0) {
            bVar1 = true;
          }
        }
      }
    }
  }
LAB_68095b86:
  Ordinal_1407(&local_70);
  if (local_68 != 0) {
    Ordinal_1601(&local_68);
  }
  if (local_6c != 0) {
    Ordinal_1653(&local_6c);
  }
  if (!bVar1) {
    Ordinal_1113(&local_74);
  }
  DAT_68196374 = local_34;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_70
// Address: 68095be0
// Size: 127 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_70(int param_1)
{
  undefined4 local_10;
  
                    /* 0x95be0  70   */
  if (((param_1 != 0) && (*(int *)(param_1 + 0x20) != 0)) &&
     (*(int *)(*(int *)(param_1 + 0x20) + 4) != 0)) {
    Ordinal_2330();
    local_10 = DAT_68196374;
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_checkObjectValid (FUN_6809b160)
// Address: 6809b160
// Size: 36 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_checkObjectValid(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 != 0) && (iVar1 = *(int *)(param_1 + 0x110), iVar1 != 0)) {
    *(undefined4 *)(param_1 + 0x110) = 0;
  }
  return iVar1;
}



// ============================================================
// Function: lingo_isValidObject (FUN_6809b190)
// Address: 6809b190
// Size: 23 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_isValidObject(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x14);
  }
  return 0;
}



// ============================================================
// Function: lingo_isValidRef (FUN_6809b1b0)
// Address: 6809b1b0
// Size: 23 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_isValidRef(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x18);
  }
  return 0;
}



// ============================================================
// Function: lingo_getObjectFlags (FUN_6809b1d0)
// Address: 6809b1d0
// Size: 23 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getObjectFlags(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x1c);
  }
  return 0;
}



// ============================================================
// Function: lingo_getObjectField114 (FUN_6809b1f0)
// Address: 6809b1f0
// Size: 26 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getObjectField114(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x114);
  }
  return 0;
}



// ============================================================
// Function: lingo_getObjectField118 (FUN_6809b210)
// Address: 6809b210
// Size: 26 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getObjectField118(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x118);
  }
  return 0;
}



// ============================================================
// Function: lingo_getMovieRef
// Address: 6809b370
// Size: 16 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getMovieRef(int param_1)

{
  return *(undefined4 *)(param_1 + 0x10c);
}



// ============================================================
// Function: lingo_executeMethod (FUN_6809b540)
// Address: 6809b540
// Size: 27 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_executeMethod(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 8);
  for (iVar1 = 0xc4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return 0;
}



// ============================================================
// Function: lingo_dispatchMethod (FUN_6809b560)
// Address: 6809b560
// Size: 27 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_dispatchMethod(int param_1,undefined4 *param_2)
{
  int iVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)(param_1 + 8);
  for (iVar1 = 0xc4; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = *param_2;
    param_2 = param_2 + 1;
    puVar2 = puVar2 + 1;
  }
  return 0;
}



// ============================================================
// Function: lingo_isScriptReady (FUN_6809b7e0)
// Address: 6809b7e0
// Size: 30 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool lingo_isScriptReady(int param_1)

{
  return *(int *)(**(int **)(param_1 + 8) + 0x18) == *(int *)(param_1 + 4);
}



// ============================================================
// Function: lingo_getMovieInfo (FUN_6809b8b0)
// Address: 6809b8b0
// Size: 16 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_getMovieInfo(int param_1)

{
  return *(undefined4 *)(param_1 + 0x380);
}


// ============================================================
// Function: score_dispose (FUN_68090d50)
// Address: 68090d50
// Size: 311 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispose(int param_1)
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;

  local_18 = param_1;
  local_1c = 0;
  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {
    piVar1 = *(int **)(param_1 + 0x20);
    iVar4 = 0;
    if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
      iVar4 = *(int *)(piVar1[1] + 8);
      if ((piVar1 == (int *)0x0) || (iVar2 = *piVar1, iVar2 == 0)) {
        iVar2 = *piVar1;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = iVar2;
    }
    bitmap_closeMovieStage(local_18);
    if (iVar4 != 0) {
      iVar2 = lingo_getMovieRef(iVar4);
      local_1c = (uint)(iVar2 == 0);
    }
    Ordinal_1125(local_18 + 0x20);
    uVar5 = 0;
    iVar2 = Ordinal_1154(*(undefined4 *)(iVar4 + 800));
    if (iVar2 != 0) {
      do {
        Ordinal_1155(*(undefined4 *)(iVar4 + 800),uVar5,&local_20);
        if (local_20 == local_18) {
          Ordinal_1160(*(undefined4 *)(iVar4 + 800),uVar5);
        }
        uVar5 = uVar5 + 1;
        uVar3 = Ordinal_1154(*(undefined4 *)(iVar4 + 800));
      } while (uVar5 < uVar3);
    }
    Ordinal_1130(local_18,0x128);
    Ordinal_1125(&local_18);
    if (piVar1 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
    return 0;
  }
  return 0;
}


// ============================================================
// Function: score_saveMovie (FUN_68091db0)
// Address: 68091db0
// Size: 242 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_saveMovie(int param_1)
{
  int iVar1;
  byte *pbVar2;
  int *piVar3;
  byte *local_14;
  byte **local_10;
  undefined4 local_c;
  uint local_8;

  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  pbVar2 = (byte *)0x0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pbVar2 = (byte *)**(int **)(param_1 + 0x20), pbVar2 == (byte *)0x0)))) {
      pbVar2 = (byte *)*piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pbVar2;
  }
  *(undefined4 *)(*(int *)(pbVar2 + 0x20) + 0x440) = 0;
  playback_processLoadedMedia(*(int **)(pbVar2 + 0x20));
  scoreEngine_resetThumbnails(*(int **)(pbVar2 + 0x20),(void *)0x0);
  playback_setSoundProperty(pbVar2,(uint)(*(int *)(*(int *)(pbVar2 + 0x20) + 0x678) == 0));
  playback_setLifecycleState((int)pbVar2,0);
  playback_getLifecycleCount((int)pbVar2);
  scoreEngine_markDirty(*(int *)(pbVar2 + 0x20),1);
  *(uint *)(*(int *)(pbVar2 + 0x20) + 0x20) = *(uint *)(*(int *)(pbVar2 + 0x20) + 0x20) | 0x10;
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}


// ============================================================
// Function: score_setProperty (FUN_68094890)
// Address: 68094890
// Size: 211 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_setProperty(int param_1,undefined4 param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;

  iVar3 = 0;
  if (param_1 == 0) {
    piVar4 = (int *)0x0;
  }
  else {
    piVar4 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
    iVar2 = *(int *)(piVar4[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar4;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  rendering_setStageSurface(piVar4[1] + 0x24,param_2);
  iVar1 = lingo_getMovieRef(iVar2);
  if (iVar1 == 0) {
    iVar1 = scoreEngine_getCastLibrary(*(int *)(iVar3 + 0x20));
    if (iVar1 != 0) {
      playback_updateAllSprites(iVar3);
    }
    lingo_getMovieRef(iVar2);
  }
  DAT_68196374 = local_10;
  Ordinal_2331();
  return 0;
}


// ============================================================
// Function: score_create (FUN_68096950)
// Address: 68096950
// Size: 98 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_create(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_8;

  local_8 = 0;
  piVar1 = (int *)Ordinal_1124(0x90);
  if (piVar1 != (int *)0x0) {
    *(int **)(param_1 + 0x14) = piVar1;
    *piVar1 = param_1;
    if (DAT_681956e0 == 0) {
      DAT_681956e0 = *(int *)(param_1 + 8);
    }
    iVar2 = bitmap_initCastLib((int)piVar1);
    if (iVar2 != 0) {
      return 1;
    }
    lingo_getMutateData(param_1);
  }
  Ordinal_1113(&local_8);
  return 0;
}


// ============================================================
// Function: score_createLinked (FUN_68096a30)
// Address: 68096a30
// Size: 199 bytes
// Params: uint param_1, int param_2, int param_3, uint param_4
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * score_createLinked(uint param_1,int param_2,int param_3,uint param_4)

{
  int *piVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint *puVar5;
  uint *local_8;

  piVar1 = *(int **)(param_2 + 0x10);
  puVar5 = (uint *)0x0;
  local_8 = (uint *)0x0;
  *(int *)(param_1 + 8) = param_2;
  local_8 = (uint *)Ordinal_1124(0x128);
  if (local_8 != (uint *)0x0) {
    uVar2 = Ordinal_1154(piVar1[200]);
    Ordinal_1151(piVar1[200],uVar2,&local_8);
    puVar5 = local_8;
    local_8[2] = (uint)piVar1;
    local_8[1] = param_1;
    *(uint **)(param_1 + 0xc) = local_8;
    uVar3 = Ordinal_1124(0xbb0);
    local_8[8] = uVar3;
    if (local_8[8] != 0) {
      uVar3 = bitmap_openMovieStage((int)local_8,param_3,param_4);
      *local_8 = uVar3;
      iVar4 = lingo_getMovieRef((int)piVar1);
      if ((uVar3 & iVar4 == 0) != 0) {
        return puVar5;
      }
    }
  }
  iVar4 = lingo_getMovieRef((int)piVar1);
  if (iVar4 == 0) {
    lingo_formatDebugMsg(piVar1,-0x7a);
  }
  if (puVar5 != (uint *)0x0) {
    score_dispose((int)puVar5);
  }
  return (uint *)0x0;
}


// ============================================================
// Function: score_loadMovie (FUN_68096b00)
// Address: 68096b00
// Size: 420 bytes
// Params: int param_1, int * param_2, int param_3, void * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_loadMovie(int param_1,int *param_2,int param_3,void *param_4)
{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  void *pvVar3;
  int *piVar4;
  int *local_20;
  int local_18;
  void *local_14;
  void **local_10;
  undefined4 local_c;
  uint local_8;

  pvVar3 = (void *)0x0;
  local_18 = 0;
  if (param_1 == 0) {
    local_20 = (int *)0x0;
  }
  else {
    local_20 = *(int **)(param_1 + 0x20);
  }
  if ((local_20 != (int *)0x0) && (local_20[1] != 0)) {
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
        (pvVar3 = (void *)**(int **)(param_1 + 0x20), pvVar3 == (void *)0x0)))) {
      pvVar3 = (void *)*local_20;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = pvVar3;
  }
  iVar2 = *(int *)((int)pvVar3 + 0x20);
  if (*(int *)(iVar2 + 0x44c) == 0) {
    if ((*(int *)(iVar2 + 0x444) != 0) && (*(int *)(iVar2 + 0x440) != 0)) {
      bVar1 = rendering_saveCastMember(iVar2,(undefined4 *)0x0,1,(void *)0x0);
      if (CONCAT31(extraout_var,bVar1) == 0) goto LAB_68096c09;
      *(undefined4 *)(iVar2 + 0x440) = 0;
    }
    iVar2 = lingo_loadAndPlayMovie(param_2,param_1,(uint)param_4 & 0x20);
    if (iVar2 != 0) {
      local_18 = 1;
      goto LAB_68096c09;
    }
  }
  local_18 = playback_loadMediaChunk(pvVar3,param_2,param_3,0,param_4);
  if ((local_18 != 0) && (local_18 != 2)) {
    iVar2 = lingo_getMutateContext();
    if (iVar2 == 0) {
      local_18 = 0;
    }
    else if (((uint)param_4 & 8) == 0) {
      playback_createMediaBuffer((int)pvVar3,2);
    }
  }
LAB_68096c09:
  if (local_20 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  if (local_18 == 1) {
    if (param_1 == 0) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = *(int **)(param_1 + 0x20);
    }
    pvVar3 = (void *)0x0;
    if ((piVar4 != (int *)0x0) && (piVar4[1] != 0)) {
      if ((param_1 == 0) ||
         ((*(int **)(param_1 + 0x20) == (int *)0x0 ||
          (pvVar3 = (void *)**(int **)(param_1 + 0x20), pvVar3 == (void *)0x0)))) {
        pvVar3 = (void *)*piVar4;
      }
      Ordinal_2330();
      local_c = 0;
      local_10 = DAT_68196374;
      DAT_68196374 = &local_14;
      local_14 = pvVar3;
    }
    rendering_getChannelProperty((int)pvVar3,8,(undefined4 *)0x0);
    if (piVar4 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
  }
  return 0;
}


// ============================================================
// Function: score_onPaused (FUN_68096240)
// Address: 68096240
// Size: 161 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_onPaused(int param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;

  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
  piVar1 = (int *)0x0;
  if ((piVar2 != (int *)0x0) && (piVar2[1] != 0)) {
    piVar1 = *(int **)(piVar2[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar3 = **(int **)(param_1 + 0x20), iVar3 == 0)
        ))) {
      iVar3 = *piVar2;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar3;
  }
  if ((*(byte *)(*piVar1 + 0x1c) & 0x80) != 0) {
    Ordinal_1759(*(undefined4 *)(piVar2[1] + 0x28),4);
  }
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}


// ============================================================
// Function: lingo_noop (FUN_6809cb50)
// Address: 6809cb50
// Size: 5 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_noop(void)
{
  return 0;
}


