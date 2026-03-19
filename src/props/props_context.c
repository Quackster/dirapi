// Module: props
// Topic: Context management, lifecycle, script selection
// Address range: 0x68031340 - 0x68032e10
// Functions (19):
//   props_relinkContext (FUN_68031340)
//   props_clearDirtyFlag (FUN_680313a0)
//   props_getTableEntry (FUN_68031890)
//   props_storeTableEntry (FUN_680318e0)
//   props_getContextSlot (FUN_68031910)
//   props_releaseLocals (FUN_68031940)
//   props_suspendContext (FUN_680319a0)
//   props_selectScript (FUN_68031a10)
//   props_allocHandlerTable (FUN_68031a70)
//   props_freeHandle (FUN_68031a80)
//   props_allocContext (FUN_68031a90)
//   props_freeTableEntry (FUN_68031b40)
//   props_freeTable (FUN_68031f80)
//   props_killContextsByScript (FUN_68032740)
//   props_destroyContext (FUN_680327a0)
//   props_unregisterContext (FUN_68032870)
//   props_releaseContext (FUN_68032930)
//   props_restoreScript (FUN_68032980)
//   props_checkReentrant (FUN_68032e10)



// ============================================================
// Function: props_relinkContext (FUN_68031340)
// Address: 68031340
// Size: 83 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_relinkContext(undefined4 param_1,int *param_2,int param_3)
{
  *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
  *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
  *(undefined4 *)(*param_2 + 8) = *(undefined4 *)(**(int **)(param_3 + 4) + 8);
  *(undefined4 *)(*param_2 + 0xc) = *(undefined4 *)(param_3 + 4);
  *(int **)(**(int **)(**(int **)(param_3 + 4) + 8) + 0xc) = param_2;
  *(int **)(**(int **)(param_3 + 4) + 8) = param_2;
  return 0;
}



// ============================================================
// Function: props_clearDirtyFlag (FUN_680313a0)
// Address: 680313a0
// Size: 31 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_clearDirtyFlag(undefined4 param_1,int *param_2)
{
  uint uVar1;
  
  uVar1 = *(uint *)(*param_2 + 4);
  *(uint *)(*param_2 + 4) = (uVar1 - 1 ^ uVar1) & 0x7fffffff ^ uVar1;
  return 0;
}



// ============================================================
// Function: props_getTableEntry (FUN_68031890)
// Address: 68031890
// Size: 70 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getTableEntry(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x4f4);
  if ((-1 < param_2) && (param_2 < *(int *)(iVar1 + 0x14))) {
    iVar1 = **(int **)(iVar1 + 0x28 + param_2 * 0x18);
    if ((-1 < param_3) && (param_3 < *(int *)(iVar1 + 0x14))) {
      return *(undefined4 *)(iVar1 + 0x24 + param_3 * 0x18);
    }
  }
  return 0xffffffff;
}



// ============================================================
// Function: props_storeTableEntry (FUN_680318e0)
// Address: 680318e0
// Size: 41 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_storeTableEntry(int param_1,int param_2,int param_3,int param_4)
{
  int iVar1;
  
  iVar1 = props_getTableEntry(param_1,param_2,param_3);
  score_lookupSymbol(DAT_68196304,iVar1,param_4);
  return 0;
}



// ============================================================
// Function: props_getContextSlot (FUN_68031910)
// Address: 68031910
// Size: 47 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_getContextSlot(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = *param_2;
  if (*(int *)(iVar1 + 0x80) <= param_3) {
    return 0;
  }
  return *(int *)(iVar1 + 0x84) + param_3 * 0x3c + iVar1;
}



// ============================================================
// Function: props_releaseLocals (FUN_68031940)
// Address: 68031940
// Size: 84 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_releaseLocals(undefined4 param_1,int *param_2)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(*param_2 + 0x8c);
  for (iVar4 = *(int *)(*param_2 + 0x88); 0 < iVar4; iVar4 = iVar4 + -1) {
    uVar1 = *(uint *)(*param_2 + iVar3);
    uVar2 = uVar1 & 0xff;
    if (((uVar2 == 3) || (uVar2 == 0x23)) || (uVar2 == 0x43)) {
      props_releaseValue(param_1,(byte)uVar1,*(int **)(*param_2 + 4 + iVar3));
    }
    iVar3 = iVar3 + 8;
  }
  return 0;
}



// ============================================================
// Function: props_suspendContext (FUN_680319a0)
// Address: 680319a0
// Size: 109 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_suspendContext(int param_1,int *param_2)
{
  int iVar1;
  
  *(uint *)(*param_2 + 0x54) = *(uint *)(*param_2 + 0x54) | 0x80;
  *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
  *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
  iVar1 = **(int **)(param_1 + 8);
  *(undefined4 *)(*param_2 + 8) = *(undefined4 *)(**(int **)(iVar1 + 0x564) + 8);
  *(undefined4 *)(*param_2 + 0xc) = *(undefined4 *)(iVar1 + 0x564);
  *(int **)(**(int **)(**(int **)(iVar1 + 0x564) + 8) + 0xc) = param_2;
  *(int **)(**(int **)(iVar1 + 0x564) + 8) = param_2;
  return 0;
}



// ============================================================
// Function: props_selectScript (FUN_68031a10)
// Address: 68031a10
// Size: 88 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_selectScript(int param_1,int param_2)
{
  undefined4 *puVar1;
  
  if (param_2 < *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x4f4) + 0x10)) {
    *(int *)(param_1 + 0x3c) = param_2;
    puVar1 = (undefined4 *)(**(int **)(**(int **)(param_1 + 8) + 0x4f4) + 0x24 + param_2 * 0x18);
    *(undefined4 *)(param_1 + 0x24) = *puVar1;
    *(undefined4 *)(param_1 + 0x28) = puVar1[1];
    *(undefined4 *)(param_1 + 0x2c) = puVar1[2];
    *(undefined4 *)(param_1 + 0x30) = puVar1[3];
    *(undefined4 *)(param_1 + 0x34) = puVar1[4];
    *(undefined4 *)(param_1 + 0x38) = puVar1[5];
  }
  return 0;
}



// ============================================================
// Function: props_allocHandlerTable (FUN_68031a70)
// Address: 68031a70
// Size: 14 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_allocHandlerTable(void)
{
  stage_allocDispatchEntry(0x38,0x20,0x18,100);
  return 0;
}



// ============================================================
// Function: props_freeHandle (FUN_68031a80)
// Address: 68031a80
// Size: 7 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_freeHandle(void)
{
  undefined4 in_EAX;
  
  cast_freeHandle(in_EAX);
  return 0;
}



// ============================================================
// Function: props_allocContext (FUN_68031a90)
// Address: 68031a90
// Size: 169 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_allocContext(void)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = stage_allocDispatchEntry(0xb8,0xa8,0x10,0x32);
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    *(undefined4 *)(iVar1 + 0x20) = 0;
    *(undefined4 *)(iVar1 + 0x24) = 0;
    *(undefined4 *)(iVar1 + 0x28) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x2c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x30) = 0;
    *(undefined4 *)(iVar1 + 0x34) = 0;
    *(undefined4 *)(iVar1 + 0x38) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x3c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x40) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x44) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x48) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x4c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x50) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x54) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x58) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x5c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x60) = 0xffffffff;
    *(undefined4 *)(iVar1 + 100) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x68) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x6c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x70) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x74) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x78) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x7c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x80) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x84) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x88) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x8c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x90) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x94) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x98) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0x9c) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0xa0) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0xa4) = 0xffffffff;
  }
  return 0;
}



// ============================================================
// Function: props_freeTableEntry (FUN_68031b40)
// Address: 68031b40
// Size: 157 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_freeTableEntry(int param_1,int *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  
  iVar2 = param_3 * 0x18;
  iVar1 = *param_2 + 0x24 + iVar2;
  uVar3 = *(undefined4 *)(iVar1 + 8);
  uVar4 = *(undefined4 *)(iVar1 + 0xc);
  uVar5 = *(undefined4 *)(iVar1 + 0x10);
  score_freePropertyHandle(*(undefined4 *)(*param_2 + 0x24 + iVar2));
  props_freeHandle();
  cast_freeHandle(uVar3);
  score_freePropertyHandle(uVar4);
  cast_freeHandle(uVar5);
  iVar2 = *param_2 + 0x24 + iVar2;
  Ordinal_1130(iVar2,0x18);
  *(undefined4 *)(iVar2 + 0x14) = *(undefined4 *)(*param_2 + 0x20);
  *(int *)(*param_2 + 0x20) = param_3;
  if (*(int *)(param_1 + 0x3c) == param_3) {
    *(undefined4 *)(param_1 + 0x3c) = 0xffffffff;
  }
  return 0;
}



// ============================================================
// Function: props_freeTable (FUN_68031f80)
// Address: 68031f80
// Size: 81 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_freeTable(undefined4 param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 != (int *)0x0) {
    iVar3 = *(int *)(*param_2 + 0x14);
    if (0 < iVar3) {
      iVar2 = 0;
      do {
        iVar1 = iVar2 + 0x24 + *param_2;
        if (*(int *)(iVar2 + 0x24 + *param_2) != -1) {
          props_releaseValue(param_1,(byte)*(undefined4 *)(iVar1 + 8),*(int **)(iVar1 + 0xc));
        }
        iVar2 = iVar2 + 0x10;
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
    score_freePropertyHandle(param_2);
  }
  return 0;
}



// ============================================================
// Function: props_killContextsByScript (FUN_68032740)
// Address: 68032740
// Size: 88 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// Suspends and releases all child contexts matching a script id
// ============================================================

int props_killContextsByScript(int *param_1,int param_2)
{
  int *piVar1;
  uint unaff_EBX;
  int iVar2;
  int local_8;
  
  local_8 = *(int *)(*param_1 + 0x10);
  if (0 < local_8) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(*param_1 + 0xa8 + iVar2);
      if ((piVar1 != (int *)0x0) && (*(int *)(*piVar1 + 0x24) == param_2)) {
        *(undefined4 *)(*piVar1 + 0x24) = 0xffffffff;
        props_suspendContext(unaff_EBX,piVar1);
        props_releaseContext(unaff_EBX,piVar1);
      }
      iVar2 = iVar2 + 0x10;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return 0;
}



// ============================================================
// Function: props_destroyContext (FUN_680327a0)
// Address: 680327a0
// Size: 198 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// Destroys a context: unlinks from list, releases locals and values, frees handle
// ============================================================

int props_destroyContext(int param_1,int *param_2,int param_3)
{
  int *piVar1;
  
  *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
  *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
  props_releaseLocals(param_1,param_2);
  props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x3c),*(int **)(*param_2 + 0x40));
  props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x44),*(int **)(*param_2 + 0x48));
  props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x4c),*(int **)(*param_2 + 0x50));
  if (*(int *)(*param_2 + 0x30) != 0) {
    score_freePropertyHandle(*(int *)(*param_2 + 0x30));
  }
  piVar1 = *(int **)(*param_2 + 0x34);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(**(int **)(*piVar1 + 8) + 0xc) = *(undefined4 *)(*piVar1 + 0xc);
    *(undefined4 *)(**(int **)(*piVar1 + 0xc) + 8) = *(undefined4 *)(*piVar1 + 8);
    if (param_3 == 0) {
      score_freePropertyHandle(piVar1);
    }
    else {
      props_freeTable(param_1,piVar1);
    }
    *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + -1;
  }
  if ((*(byte *)(*param_2 + 0x54) & 1) != 0) {
    cast_freeHandle(*(undefined4 *)(*param_2 + 0x2c));
  }
  core_applyInheritance(param_1,param_2);
  return 0;
}



// ============================================================
// Function: props_unregisterContext (FUN_68032870)
// Address: 68032870
// Size: 178 bytes
// Params: uint param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// Unregisters a context from its handler slot and cleans up references
// ============================================================

int props_unregisterContext(uint param_1,int *param_2)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int extraout_ECX;
  int iVar6;
  
  piVar2 = *(int **)(**(int **)(param_1 + 8) + 0x4f4);
  iVar5 = *param_2;
  iVar3 = *(int *)(iVar5 + 0x20);
  if (-1 < *(int *)(iVar5 + 0x28)) {
    stage_freeAllocSlot(param_1,*(int **)(*piVar2 + (iVar3 * 3 + 6) * 8),*(int *)(iVar5 + 0x28));
    iVar5 = *param_2;
  }
  if ((*(byte *)(iVar5 + 0x54) & 2) != 0) {
    props_removeHandlers(param_1,param_2,0);
    iVar5 = *param_2;
  }
  iVar6 = iVar3 * 3;
  piVar4 = *(int **)(*piVar2 + 0x2c + iVar3 * 0x18);
  if ((*(uint *)(iVar5 + 0x54) & 0x100) != 0) {
    props_killContextsByScript(piVar4,*(int *)(iVar5 + 0x1c));
    iVar5 = *param_2;
    iVar6 = extraout_ECX;
  }
  props_resetHandlerSlot(iVar6,*(int *)(iVar5 + 0x1c));
  if ((*(byte *)(*piVar4 + 0x34) & 8) != 0) {
    props_refreshHandlers(param_1);
  }
  iVar5 = *piVar4;
  piVar1 = (int *)(iVar5 + 0x30);
  *piVar1 = *piVar1 + -1;
  if ((*(int *)(iVar5 + 0x30) < 1) && ((*(byte *)(*piVar4 + 0x34) & 2) != 0)) {
    props_freeTableEntry(param_1,piVar2,iVar3);
  }
  return 0;
}



// ============================================================
// Function: props_releaseContext (FUN_68032930)
// Address: 68032930
// Size: 75 bytes
// Params: uint param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// Decrements context refcount and destroys it if count reaches zero
// ============================================================

undefined4 props_releaseContext(uint param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 != (int *)0x0) {
    iVar2 = *param_2;
    piVar1 = (int *)(iVar2 + 4);
    *piVar1 = *piVar1 + -1;
    iVar2 = *(int *)(iVar2 + 4);
    if (iVar2 < 1) {
      if (-1 < iVar2) {
        props_destroyContext(param_1,param_2,1);
        props_unregisterContext(param_1,param_2);
        cast_freeHandle(param_2);
        *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + -1;
      }
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: props_restoreScript (FUN_68032980)
// Address: 68032980
// Size: 25 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// Restores the previously active script if it differs from current
// ============================================================

int props_restoreScript(int param_1)
{
  if (*(int *)(param_1 + 0x58) != *(int *)(param_1 + 0x3c)) {
    props_selectScript(param_1,*(int *)(param_1 + 0x58));
  }
  return 0;
}



// ============================================================
// Function: props_checkReentrant (FUN_68032e10)
// Address: 68032e10
// Size: 38 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// Checks if the system is not in a re-entrant state
// ============================================================

undefined4 props_checkReentrant(int param_1)

{
  if (DAT_68195a8c == 0) {
    return 1;
  }
  props_setError(param_1,2);
  return 0;
}


