// Module: lingo
// Topic: Score/movie object lifecycle (create, destroy, init, cleanup)
// Address range: 0x68090B30 - 0x6809B960
// Functions (15):
//   lingo_initGlobalState
//   lingo_getMutateData
//   lingo_createLifecycleNode
//   lingo_advanceLifecycle
//   score_dispose (FUN_68090d50)
//   lingo_destroyLifecycle
//   lingo_initLifecycle
//   lingo_releaseObjectRef
//   score_create (FUN_68096950)
//   Ordinal_112
//   score_createLinked (FUN_68096a30)
//   lingo_cleanupDisplay (FUN_6809ae10)
//   lingo_initLifecycleData
//   lingo_initPlaybackDefaults
//   lingo_destroyPlaybackRefs


// ============================================================
// Function: lingo_initGlobalState (FUN_68090b30)
// Address: 68090b30
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_initGlobalState(void)
{
  bitmap_registerCastLib();
  return 0;
}



// ============================================================
// Function: lingo_getMutateData (FUN_68090b40)
// Address: 68090b40
// Size: 38 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_getMutateData(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  *(undefined4 *)(param_1 + 0x14) = 0;
  param_1 = iVar1;
  bitmap_destroyCastLib(iVar1);
  Ordinal_1125(&param_1);
  return 0;
}



// ============================================================
// Function: lingo_createLifecycleNode (FUN_68090c80)
// Address: 68090c80
// Size: 52 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * lingo_createLifecycleNode(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = Ordinal_1111(0xc,0);
  if (iVar1 != 0) {
    piVar2 = (int *)Ordinal_1114(iVar1);
    piVar2[2] = 0;
    *piVar2 = iVar1;
    piVar2[1] = param_1;
    return piVar2;
  }
  return (int *)0x0;
}



// ============================================================
// Function: lingo_advanceLifecycle (FUN_68090cc0)
// Address: 68090cc0
// Size: 142 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_advanceLifecycle(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = 0;
  if ((param_1 != 0) && (*(int *)(*(int *)(param_1 + 4) + 0x10) != 0)) {
    puVar1 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x10);
    Ordinal_2330();
    local_14 = *puVar1;
    local_10 = DAT_68196374;
    local_c = 1;
    DAT_68196374 = &local_14;
    iVar2 = Ordinal_1155(puVar1[200],*(undefined4 *)(param_1 + 8),&local_18);
    if (iVar2 == 0) {
      local_18 = 0;
    }
    else {
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
    }
    DAT_68196374 = (undefined4 *)local_10;
    Ordinal_2331();
  }
  return 0;
}



// ============================================================
// Function: lingo_destroyLifecycle (FUN_68090e90)
// Address: 68090e90
// Size: 139 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_destroyLifecycle(int param_1)
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
// Function: lingo_initLifecycle (FUN_68090f20)
// Address: 68090f20
// Size: 127 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_initLifecycle(int param_1)
{
  undefined4 local_10;
  
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
// Function: lingo_releaseObjectRef (FUN_68091680)
// Address: 68091680
// Size: 36 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_releaseObjectRef(int *param_1)
{
  int *piVar1;
  
  if ((param_1 != (int *)0x0) && (piVar1 = (int *)*param_1, piVar1 != (int *)0x0)) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *param_1 = 0;
  }
  return 0;
}



// ============================================================
// Function: Ordinal_112
// Address: 680969c0
// Size: 112 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * Ordinal_112(int param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 local_8;
  
                    /* 0x969c0  112   */
  local_8 = 0;
  piVar1 = (int *)Ordinal_1124(0x38c);
  if (piVar1 == (int *)0x0) {
    lingo_formatDebugMsg((int *)0x0,-0x7a);
    Ordinal_1113(&local_8);
    return (int *)0x0;
  }
  piVar1[1] = *(int *)(*(int *)(param_1 + 0xc) + 0x14);
  *(int **)(param_1 + 0x10) = piVar1;
  *piVar1 = param_1;
  iVar2 = bitmap_initCastData(piVar1);
  if (iVar2 == 0) {
    Ordinal_113(param_1,0);
    Ordinal_1113(&local_8);
  }
  return piVar1;
}



// ============================================================
// Function: lingo_initLifecycleData (FUN_6809af80)
// Address: 6809af80
// Size: 469 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int lingo_initLifecycleData(int *param_1,int param_2)

{
  void *pvVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  
  puVar2 = (undefined4 *)Ordinal_1124(0x28);
  param_1[0xd7] = (int)puVar2;
  *puVar2 = 0;
  *(undefined4 *)(param_1[0xd7] + 8) = 0;
  *(undefined4 *)(param_1[0xd7] + 4) = 0;
  *(undefined4 *)(param_1[0xd7] + 0x10) = 0;
  *(undefined4 *)(param_1[0xd7] + 0xc) = 0;
  *(undefined4 *)(param_1[0xd7] + 0x18) = 0;
  *(undefined4 *)(param_1[0xd7] + 0x14) = 0;
  *(undefined4 *)(param_1[0xd7] + 0x20) = 0;
  *(undefined4 *)(param_1[0xd7] + 0x24) = 0;
  uVar3 = Ordinal_1038(param_2);
  iVar4 = media_initXtraDispatchWrapper((int)param_1,uVar3);
  if (iVar4 == 0) {
    if (param_2 != 0) {
      uVar3 = Ordinal_1038();
      piVar5 = (int *)Ordinal_2068(uVar3);
      if (piVar5 != (int *)0x0) {
        (**(code **)(*piVar5 + 0x14))(piVar5,lingo_resolveGlobalPair,piVar5);
        (**(code **)(*piVar5 + 8))(piVar5);
      }
    }
    uVar3 = Ordinal_1038(&DAT_68176458,&DAT_68175ca8,param_1[0xd7] + 8);
    Ordinal_2063(uVar3);
    uVar3 = Ordinal_1038(&DAT_68176458,&DAT_68175ca8,param_1[0xd7] + 0x10);
    Ordinal_2063(uVar3);
    puVar2 = *(undefined4 **)(param_1[0xd7] + 8);
    (**(code **)*puVar2)(puVar2,&DAT_68176468,param_1[0xd7] + 4);
    puVar2 = *(undefined4 **)(param_1[0xd7] + 0x10);
    (**(code **)*puVar2)(puVar2,&DAT_68176468,param_1[0xd7] + 0xc);
    uVar3 = Ordinal_1038(&DAT_68176478,&DAT_68175cc8,param_1[0xd7] + 0x18);
    Ordinal_2063(uVar3);
    puVar2 = *(undefined4 **)(param_1[0xd7] + 0x18);
    (**(code **)*puVar2)(puVar2,&DAT_68176488,param_1[0xd7] + 0x14);
    pvVar1 = *(void **)(*(int *)(*param_1 + 0x14) + 0x14);
    iVar4 = media_initCastRegistry(pvVar1,(int *)param_1[0xd7],&DAT_68196370);
    iVar6 = media_applyPixelFilter((int)pvVar1);
    if ((iVar6 != 0) && (DAT_68196370 == 0)) {
      uVar3 = Ordinal_1038();
      iVar6 = Ordinal_2062(uVar3);
      if (iVar6 == -0x7ffbffea) {
        media_readScoreEntry(1,0,0);
        DAT_68196370 = 1;
      }
    }
    media_registerScriptThread(pvVar1);
    iVar6 = Ordinal_1541();
    param_1[0xdf] = iVar6;
    param_1[0xde] = 0xff;
    if (iVar4 != 0) {
      lingo_cleanupDisplay((int)param_1,param_2);
    }
  }
  return iVar4;
}



// ============================================================
// Function: lingo_initPlaybackDefaults (FUN_6809b930)
// Address: 6809b930
// Size: 47 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 lingo_initPlaybackDefaults(int param_1)

{
  *(undefined4 *)(param_1 + 0x18) = 0;
  *(undefined4 *)(param_1 + 0x1c) = 0;
  *(undefined4 *)(param_1 + 0x20) = 0;
  *(undefined4 *)(param_1 + 0x24) = 0;
  *(undefined4 *)(param_1 + 0x30) = 1;
  *(undefined4 *)(param_1 + 0x28) = 0xc8000;
  *(undefined4 *)(param_1 + 0x2c) = 0x3e800;
  return 0;
}



// ============================================================
// Function: lingo_destroyPlaybackRefs (FUN_6809b960)
// Address: 6809b960
// Size: 80 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int lingo_destroyPlaybackRefs(int param_1)
{
  if (*(int *)(param_1 + 0x18) != 0) {
    (**(code **)(**(int **)(param_1 + 0x18) + 8))(*(int **)(param_1 + 0x18));
  }
  if (*(int *)(param_1 + 0x1c) != 0) {
    (**(code **)(**(int **)(param_1 + 0x1c) + 8))(*(int **)(param_1 + 0x1c));
  }
  if (*(int *)(param_1 + 0x20) != 0) {
    (**(code **)(**(int **)(param_1 + 0x20) + 8))(*(int **)(param_1 + 0x20));
  }
  if (*(int *)(param_1 + 0x24) != 0) {
    (**(code **)(**(int **)(param_1 + 0x24) + 8))(*(int **)(param_1 + 0x24));
  }
  return 0;
}


