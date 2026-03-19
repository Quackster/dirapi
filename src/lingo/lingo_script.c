// Module: lingo
// Topic: Lingo script execution and mode management
// Address range: 0x68090B70 - 0x68092B70
// Functions (20):
//   Ordinal_113
//   lingo_initLifecycleWrapped
//   Ordinal_118
//   Ordinal_132
//   Ordinal_119
//   Ordinal_120
//   lingo_compileScript
//   lingo_getScriptRef
//   lingo_removeScriptRef
//   lingo_enterScriptMode (FUN_680924b0)
//   lingo_setScriptProperty
//   lingo_enterScriptContext
//   lingo_setScriptMode
//   lingo_resolveScriptRef
//   lingo_reloadScriptMedia
//   lingo_executeScriptOp
//   lingo_drawScoreView
//   lingo_runScript (FUN_68092a20)
//   lingo_runScriptWithResult (FUN_68092ac0)
//   lingo_getScriptData


// ============================================================
// Function: Ordinal_113
// Address: 68090b70
// Size: 131 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_113(int param_1,int param_2)
{
  undefined4 uVar1;
  undefined4 *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x90b70  113   */
  local_18 = *(undefined4 **)(param_1 + 0x10);
  uVar1 = *(undefined4 *)(param_1 + 0xc);
  *(undefined4 *)(param_1 + 0x10) = 0;
  if (local_18 != (undefined4 *)0x0) {
    bitmap_destroyCastData(local_18);
    Ordinal_2330();
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_c = 2;
    local_14 = uVar1;
    lingo_cleanupDisplay((int)local_18,param_2);
    DAT_68196374 = (undefined4 *)local_10;
    Ordinal_2331();
    Ordinal_1125(&local_18);
  }
  return 0;
}



// ============================================================
// Function: lingo_initLifecycleWrapped (FUN_68090c10)
// Address: 68090c10
// Size: 104 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_initLifecycleWrapped(int param_1,int param_2)
{
  int *piVar1;
  int local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x10);
  Ordinal_2330();
  local_14 = *piVar1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  lingo_initLifecycleData(piVar1,param_2);
  DAT_68196374 = (int *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_118
// Address: 680916b0
// Size: 139 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_118(int param_1)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x916b0  118   */
  if (param_1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = *(int **)(param_1 + 0x20);
  }
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
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_132
// Address: 68091740
// Size: 148 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_132(int param_1)
{
  int iVar1;
  int *piVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x91740  132   */
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
  stage_getSpriteDataOffset(*(int *)(*(int *)(iVar1 + 0x20) + 8));
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: Ordinal_119
// Address: 68091810
// Size: 129 bytes
// Params: undefined4 * param_1, undefined1 * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_119(undefined4 *param_1,undefined1 *param_2,undefined4 param_3)
{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x91810  119   */
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  if (param_2 != (undefined1 *)0x0) {
    DAT_68196374 = &local_14;
    *param_2 = 0;
    Ordinal_1203(param_2,param_1 + 0x44,param_3);
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: Ordinal_120
// Address: 680918a0
// Size: 166 bytes
// Params: undefined4 * param_1, undefined1 * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int Ordinal_120(undefined4 *param_1,undefined1 *param_2,undefined4 param_3)
{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
                    /* 0x918a0  120   */
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  if (param_2 != (undefined1 *)0x0) {
    *param_2 = 0;
  }
  iVar1 = param_1[0x84];
  if (param_2 != (undefined1 *)0x0) {
    Ordinal_1203(param_2,param_1 + 0x85,param_3);
  }
  if ((iVar1 == 0) && (param_2 != (undefined1 *)0x0)) {
    Ordinal_1203(param_2,param_1 + 3,param_3);
  }
  lingo_flushState((int)param_1);
  lingo_updateState((int)param_1);
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_compileScript (FUN_68092320)
// Address: 68092320
// Size: 129 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_compileScript(undefined4 *param_1,int param_2)
{
  int iVar1;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  if (param_2 != 0) {
    DAT_68196374 = &local_14;
    iVar1 = lingo_setPropertyValue(param_2,1);
    if (iVar1 != 0) {
      lingo_getMutateState();
    }
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_getScriptRef (FUN_680923b0)
// Address: 680923b0
// Size: 36 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool lingo_getScriptRef(int param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_1114();
  iVar1 = *(int *)(iVar1 + 4);
  Ordinal_1115();
  return iVar1 == param_1;
}



// ============================================================
// Function: lingo_removeScriptRef (FUN_680923e0)
// Address: 680923e0
// Size: 194 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_removeScriptRef(undefined4 *param_1,int param_2)
{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar3;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  Ordinal_2330();
  local_14 = *param_1;
  local_c = 1;
  local_10 = DAT_68196374;
  local_18 = 0;
  if (param_1[0xd3] != 0) {
    DAT_68196374 = &local_14;
    iVar2 = Ordinal_1154(param_1[0xd3]);
    iVar3 = iVar2;
    for (; iVar2 != 0; iVar2 = iVar2 + -1) {
      iVar3 = iVar3 + -1;
      Ordinal_1155(param_1[0xd3],iVar3,&local_18);
      bVar1 = lingo_getScriptRef(param_2);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        Ordinal_1160(param_1[0xd3],iVar3);
        lingo_getMutateState();
      }
    }
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: lingo_setScriptProperty (FUN_68092560)
// Address: 68092560
// Size: 126 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setScriptProperty(int param_1,int param_2,undefined4 param_3)
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
  *(undefined4 *)(*(int *)(iVar2 + 0x20) + 0x484) = param_3;
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_enterScriptContext (FUN_680925e0)
// Address: 680925e0
// Size: 124 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_enterScriptContext(int param_1,int param_2)
{
  int *piVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_setScriptMode (FUN_68092660)
// Address: 68092660
// Size: 150 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_setScriptMode(int param_1,int param_2,undefined4 param_3)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  iVar2 = 0;
  iVar3 = 0;
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    iVar2 = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    iVar3 = param_2;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  *(undefined4 *)(*(int *)(iVar3 + 0x20) + 0x440) = param_3;
  lingo_getMovieRef(iVar2);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_resolveScriptRef (FUN_68092700)
// Address: 68092700
// Size: 144 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_resolveScriptRef(int param_1,int param_2)
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
    iVar2 = *(int *)(piVar1[1] + 8);
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  lingo_getMovieRef(iVar2);
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_reloadScriptMedia (FUN_68092790)
// Address: 68092790
// Size: 174 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_reloadScriptMedia(int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  if (param_1 == 0) {
    piVar3 = (int *)0x0;
  }
  else {
    piVar3 = *(int **)(param_1 + 0x20);
  }
  iVar2 = 0;
  iVar1 = 0;
  if ((piVar3 != (int *)0x0) && (piVar3[1] != 0)) {
    iVar1 = *(int *)(piVar3[1] + 8);
    if ((param_1 == 0) ||
       ((*(int **)(param_1 + 0x20) == (int *)0x0 || (iVar2 = **(int **)(param_1 + 0x20), iVar2 == 0)
        ))) {
      iVar2 = *piVar3;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = iVar2;
  }
  lingo_getMovieRef(iVar1);
  playback_loadMediaBlock(*(int **)(iVar2 + 0x20),1,0);
  lingo_getMovieRef(iVar1);
  if (piVar3 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_executeScriptOp (FUN_68092910)
// Address: 68092910
// Size: 128 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_executeScriptOp(int param_1,int param_2)
{
  int *piVar1;
  int local_14;
  int *local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = *(int **)(param_1 + 0x20);
  if ((piVar1 != (int *)0x0) && (piVar1[1] != 0)) {
    if (param_2 == 0) {
      param_2 = *piVar1;
    }
    Ordinal_2330();
    local_c = 0;
    local_10 = DAT_68196374;
    DAT_68196374 = &local_14;
    local_14 = param_2;
  }
  if (piVar1 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_drawScoreView (FUN_68092990)
// Address: 68092990
// Size: 144 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_drawScoreView(int param_1)
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
  stage_drawScore(*(int *)(*(int *)(iVar1 + 0x20) + 8));
  if (piVar2 != (int *)0x0) {
    DAT_68196374 = local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_getScriptData (FUN_68092b70)
// Address: 68092b70
// Size: 151 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getScriptData(int param_1,int *param_2,undefined4 *param_3)
{
  int *piVar1;
  int iVar2;
  int local_14;
  int *local_10;
  undefined4 local_c;
  
  if (param_1 != 0) {
    piVar1 = *(int **)(param_1 + 0x20);
    iVar2 = 0;
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
    bitmap_dispatchStageEvent(*(int **)(iVar2 + 0x20),param_2,param_3);
    if (piVar1 != (int *)0x0) {
      DAT_68196374 = local_10;
      Ordinal_2331();
    }
  }
  return 0;
}


