// Module: props
// Topic: Stack and frame management
// Address range: 0x68032540 - 0x68034700
// Functions (20):
//   props_growStack (FUN_68032540)
//   props_releaseStackRange (FUN_680325a0)
//   props_pushValue (FUN_680325d0)
//   props_popValue (FUN_68032620)
//   props_unwindStack (FUN_68032e40)
//   props_popFrame (FUN_68032e80)
//   props_unwindToFrame (FUN_68032fe0)
//   props_trimFrames (FUN_68033030)
//   props_allocHandlerSlot (FUN_68033100)
//   props_allocScriptEntry (FUN_68033190)
//   props_popArgs (FUN_680332d0)
//   props_normalizeType
//   props_getTypedValue (FUN_68033410)
//   props_tryGetTypedValue (FUN_68033560)
//   props_getTypedProperty
//   props_getValueDirect
//   props_getOptionalValue (FUN_68033750)
//   props_getStackDepth
//   props_pushFrame (FUN_68034520)
//   props_copyHandle (FUN_68034700)



// ============================================================
// Function: props_growStack (FUN_68032540)
// Address: 68032540
// Size: 87 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// Grows the VM stack buffer to accommodate additional bytes
// ============================================================

undefined4 props_growStack(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (*(int *)(param_1 + 0x18) + param_2 < iVar1) {
    return 1;
  }
  iVar2 = (iVar1 >> 1) + iVar1 + param_2;
  iVar1 = Ordinal_1117(param_1 + 0x10,iVar2,1);
  if (iVar1 != 0) {
    *(int *)(param_1 + 0x14) = iVar2;
    return 1;
  }
  props_setError(param_1,2);
  return 0;
}



// ============================================================
// Function: props_releaseStackRange (FUN_680325a0)
// Address: 680325a0
// Size: 47 bytes
// Return: undefined
// Calling convention: __stdcall
// Releases all values in a range on the VM stack
// ============================================================

int props_releaseStackRange(void)
{
  int in_EAX;
  int unaff_EBX;
  int iVar1;
  int unaff_EDI;
  
  if (in_EAX < 0) {
    iVar1 = 0;
  }
  else {
    iVar1 = in_EAX + 0x34;
  }
  for (; iVar1 < unaff_EBX; iVar1 = iVar1 + 8) {
    props_releaseValue(unaff_EDI,(byte)*(undefined4 *)(**(int **)(unaff_EDI + 0x10) + iVar1),
                 *(int **)(**(int **)(unaff_EDI + 0x10) + 4 + iVar1));
  }
  return 0;
}



// ============================================================
// Function: props_pushValue (FUN_680325d0)
// Address: 680325d0
// Size: 67 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// Pushes the current accumulator value onto the VM stack
// ============================================================

int props_pushValue(int param_1)
{
  int iVar1;
  int iVar2;
  
  if ((*(int *)(param_1 + 0x14) <= *(int *)(param_1 + 0x18) + 8) &&
     (iVar2 = props_growStack(param_1,8), iVar2 == 0)) {
    return 0;
  }
  iVar2 = **(int **)(param_1 + 0x10);
  iVar1 = *(int *)(param_1 + 0x18);
  *(undefined4 *)(iVar2 + iVar1) = *(undefined4 *)(param_1 + 0x1c);
  *(undefined4 *)(iVar2 + 4 + iVar1) = *(undefined4 *)(param_1 + 0x20);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 8;
  *(undefined4 *)(param_1 + 0x1c) = 4;
  return 0;
}



// ============================================================
// Function: props_popValue (FUN_68032620)
// Address: 68032620
// Size: 57 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// Pops the top value from the VM stack into the accumulator
// ============================================================

int props_popValue(int param_1)
{
  int iVar1;
  
  if ((*(byte *)(param_1 + 0x1c) & 1) != 0) {
    props_releaseValue(param_1,(byte)*(undefined4 *)(param_1 + 0x1c),*(int **)(param_1 + 0x20));
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar1 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  return 0;
}



// ============================================================
// Function: props_unwindStack (FUN_68032e40)
// Address: 68032e40
// Size: 62 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// Unwinds the stack down to the current frame boundary
// ============================================================

int props_unwindStack(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x40) + 0x34 < iVar1) {
    do {
      if (*(int *)(param_1 + 0x8c) == iVar1) {
        stage_iterateNext(param_1);
      }
      else {
        props_popValue(param_1);
      }
      iVar1 = *(int *)(param_1 + 0x18);
    } while (*(int *)(param_1 + 0x40) + 0x34 < iVar1);
  }
  return 0;
}



// ============================================================
// Function: props_popFrame (FUN_68032e80)
// Address: 68032e80
// Size: 352 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// Pops a stack frame, restoring saved context state (lcr_stk_PopFrame)
// ============================================================

int props_popFrame(uint param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  
  piVar5 = (int *)(param_1 + 0x40);
  if (-1 < *(int *)(param_1 + 0x40)) {
    if (*(int *)(param_1 + 0x40) + 0x34 == *(int *)(param_1 + 0x18)) {
      if (((byte)*(undefined4 *)(param_1 + 0x1c) & 0x1f) == 3) {
        piVar4 = (int *)(**(int **)(param_1 + 0x20) + 4);
        *piVar4 = *piVar4 + 1;
      }
      iVar3 = *(int *)(param_1 + 0x44);
      if (iVar3 < *piVar5) {
        do {
          props_releaseValue(param_1,(byte)*(undefined4 *)(**(int **)(param_1 + 0x10) + iVar3),
                       *(int **)(**(int **)(param_1 + 0x10) + 4 + iVar3));
          iVar3 = iVar3 + 8;
        } while (iVar3 < *piVar5);
      }
      if (((byte)*(undefined4 *)(param_1 + 0x1c) & 0x1f) == 3) {
        piVar4 = (int *)(**(int **)(param_1 + 0x20) + 4);
        *piVar4 = *piVar4 + -1;
      }
      props_releaseContext(param_1,*(int **)(param_1 + 0x50));
      if ((*(int **)(param_1 + 0x60) != (int *)0x0) && ((*(byte *)(param_1 + 0x68) & 0x20) != 0)) {
        props_freeTable(param_1,*(int **)(param_1 + 0x60));
      }
      iVar3 = *(int *)(param_1 + 0x6c);
      *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(param_1 + 0x44);
      iVar1 = *(int *)(param_1 + 0x74);
      piVar4 = (int *)(**(int **)(param_1 + 0x10) + *piVar5);
      for (iVar2 = 0xd; iVar2 != 0; iVar2 = iVar2 + -1) {
        *piVar5 = *piVar4;
        piVar4 = piVar4 + 1;
        piVar5 = piVar5 + 1;
      }
      if (iVar1 < 8) {
        iVar1 = *(int *)(param_1 + 0x78);
        if (1 < iVar1 - 4U) {
          iVar1 = *(int *)(param_1 + 100);
        }
        *(int *)(param_1 + 0x74) = iVar1;
      }
      if (*(int *)(param_1 + 0x58) != *(int *)(param_1 + 0x3c)) {
        props_selectScript(param_1,*(int *)(param_1 + 0x58));
      }
      if (iVar3 != 0) {
        if (*(int *)(param_1 + 0x1c) == 0) {
          *(undefined4 *)(param_1 + 0x1c) = 2;
        }
        return 0;
      }
      if (*(int *)(param_1 + 0x1c) != 0) {
        props_releaseValue(param_1,(byte)*(undefined4 *)(param_1 + 0xac),*(int **)(param_1 + 0xb0));
        *(undefined4 *)(param_1 + 0xac) = *(undefined4 *)(param_1 + 0x1c);
        *(undefined4 *)(param_1 + 0xb0) = *(undefined4 *)(param_1 + 0x20);
      }
      *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
      iVar3 = **(int **)(param_1 + 0x10);
      *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x18));
      *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x18));
      return 0;
    }
    stage_logScriptError("lcr_stk_PopFrame: unbalanced stk");
    props_formatValue(param_1,(byte *)" lcr_stk_PopFrame: unbalanced stk prev=%ld top=%ld\n");
    props_setError(param_1,0x33);
  }
  *(undefined4 *)(param_1 + 0x70) = 1;
  return 0;
}



// ============================================================
// Function: props_unwindToFrame (FUN_68032fe0)
// Address: 68032fe0
// Size: 80 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// Unwinds to a specific frame by repeatedly popping frames
// ============================================================

int props_unwindToFrame(uint param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x40);
  while( true ) {
    if (iVar1 == param_2) {
      if (*(int *)(param_1 + 0x58) != *(int *)(param_1 + 0x3c)) {
        props_selectScript(param_1,*(int *)(param_1 + 0x58));
      }
      *(undefined4 *)(param_1 + 0x74) = 7;
      return 0;
    }
    if (*(int *)(param_1 + 0x40) < 0) break;
    props_unwindStack(param_1);
    props_popFrame(param_1);
    iVar1 = *(int *)(param_1 + 0x40);
  }
  *(undefined4 *)(param_1 + 0x74) = 9;
  return 0;
}



// ============================================================
// Function: props_trimFrames (FUN_68033030)
// Address: 68033030
// Size: 204 bytes
// Params: uint param_1, int param_2
// Return: int
// Calling convention: __stdcall
// Trims frames from the bottom of the stack, adjusting offsets
// ============================================================

int props_trimFrames(uint param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(param_1 + 0x40);
  piVar1 = (int *)(param_1 + 0x40);
  iVar3 = 0;
  if (iVar2 != param_2) {
    do {
      iVar3 = piVar1[1];
      piVar1 = (int *)(**(int **)(param_1 + 0x10) + iVar2);
      iVar2 = *piVar1;
      if (iVar2 == -1) {
        return -8;
      }
    } while (iVar2 != param_2);
  }
  iVar3 = iVar3 + -8;
  while( true ) {
    iVar2 = *piVar1;
    if ((int *)piVar1[4] != (int *)0x0) {
      props_releaseContext(param_1,(int *)piVar1[4]);
    }
    props_releaseStackRange();
    if (iVar2 < 0) break;
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + iVar2);
  }
  piVar1 = (int *)(param_1 + 0x40);
  iVar2 = *(int *)(param_1 + 0x40);
  while (iVar2 != param_2) {
    iVar2 = *piVar1;
    piVar1[1] = piVar1[1] - iVar3;
    piVar1[2] = piVar1[2] - iVar3;
    *piVar1 = iVar2 - iVar3;
    piVar1 = (int *)(**(int **)(param_1 + 0x10) + iVar2);
    iVar2 = *piVar1;
  }
  piVar1[4] = 0;
  *piVar1 = -1;
  iVar2 = *(int *)(param_1 + 0x3c);
  piVar1[0xb] = 0;
  piVar1[6] = iVar2;
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) - iVar3;
  Ordinal_1129(**(int **)(param_1 + 0x10),**(int **)(param_1 + 0x10) + iVar3,
               *(undefined4 *)(param_1 + 0x18));
  return iVar3;
}



// ============================================================
// Function: props_allocHandlerSlot (FUN_68033100)
// Address: 68033100
// Size: 131 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_allocHandlerSlot(int param_1,int *param_2,int *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *param_2;
  iVar4 = *(int *)(iVar3 + 0x38);
  if (iVar4 < 0) {
    iVar4 = *(int *)(iVar3 + 0x10);
    stage_emitStoreVar(param_2,iVar4);
    iVar3 = props_checkReentrant(param_1);
    if (iVar3 == 0) {
      return -1;
    }
    iVar3 = *param_2;
  }
  else {
    *(undefined4 *)(iVar3 + 0x38) = *(undefined4 *)(iVar3 + 0xb4 + iVar4 * 0x10);
  }
  iVar2 = *param_3;
  *(int *)(iVar2 + 0x1c) = iVar4;
  *(undefined4 *)(iVar2 + 4) = 0;
  *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(param_1 + 0x3c);
  *(int *)(iVar3 + 0x30) = *(int *)(iVar3 + 0x30) + 1;
  *(uint *)(iVar3 + 0x34) = *(uint *)(iVar3 + 0x34) | 1;
  puVar1 = (undefined4 *)(iVar3 + 0xa8 + iVar4 * 0x10);
  puVar1[2] = 0;
  *puVar1 = param_3;
  puVar1[1] = 0xffffffff;
  return iVar4;
}



// ============================================================
// Function: props_allocScriptEntry (FUN_68033190)
// Address: 68033190
// Size: 318 bytes
// Params: int param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_allocScriptEntry(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  Ordinal_1130(&local_1c,0x18);
  local_1c = score_getSymbolName(0x7f,0xc0);
  if (param_1 != 0) {
    iVar2 = props_checkReentrant(param_1);
    if (iVar2 == 0) goto LAB_68033296;
  }
  local_18 = props_allocHandlerTable();
  if (param_1 != 0) {
    iVar2 = props_checkReentrant(param_1);
    if (iVar2 == 0) goto LAB_68033296;
  }
  local_14 = props_allocContext();
  if (param_1 != 0) {
    iVar2 = props_checkReentrant(param_1);
    if (iVar2 == 0) goto LAB_68033296;
  }
  local_10 = score_createPropertyTable();
  if (param_1 != 0) {
    iVar2 = props_checkReentrant(param_1);
    if (iVar2 == 0) goto LAB_68033296;
  }
  local_c = Ordinal_1111(0x14,1);
  if ((param_1 != 0) && (local_c == 0)) {
LAB_68033296:
    score_freePropertyHandle(local_1c);
    props_freeHandle();
    cast_freeHandle(local_14);
    score_freePropertyHandle(local_10);
    cast_freeHandle(local_c);
    return -1;
  }
  iVar2 = *param_2;
  local_8 = 0xffffffff;
  iVar3 = *(int *)(iVar2 + 0x20);
  if (iVar3 < 0) {
    iVar3 = *(int *)(iVar2 + 0x10);
    stage_emitStoreVar(param_2,iVar3);
    if (param_1 != 0) {
      iVar2 = props_checkReentrant(param_1);
      if (iVar2 == 0) goto LAB_68033296;
    }
  }
  else {
    *(undefined4 *)(iVar2 + 0x20) = *(undefined4 *)(iVar2 + 0x38 + iVar3 * 0x18);
  }
  puVar1 = (undefined4 *)(*param_2 + 0x24 + iVar3 * 0x18);
  *puVar1 = local_1c;
  puVar1[1] = local_18;
  puVar1[2] = local_14;
  puVar1[3] = local_10;
  puVar1[4] = local_c;
  puVar1[5] = local_8;
  return iVar3;
}



// ============================================================
// Function: props_popArgs (FUN_680332d0)
// Address: 680332d0
// Size: 242 bytes
// Params: int ctx, undefined4 *returnValue
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_popArgs(int param_1,undefined4 *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  if (*(int *)(param_1 + 0x7c) == 0) {
    iVar2 = props_getInt(param_1);
    iVar3 = *(int *)(param_1 + 0x18);
    for (; 0 < iVar2; iVar2 = iVar2 + -1) {
      iVar1 = **(int **)(param_1 + 0x10);
      iVar3 = iVar3 + -8;
      if (((*(int *)(param_1 + 0x40) == -1) || (*(int *)(param_1 + 0x40) + 0x34 < iVar3)) &&
         ((*(byte *)(iVar1 + iVar3) & 1) != 0)) {
        props_releaseValue(param_1,(byte)*(undefined4 *)(iVar1 + iVar3),*(int **)(iVar1 + 4 + iVar3));
      }
    }
    if ((*(int *)(param_1 + 0x40) == -1) || (*(int *)(param_1 + 0x40) + 0x34 <= iVar3)) {
      *(int *)(param_1 + 0x18) = iVar3;
    }
    else {
      props_setError(param_1,0x33);
    }
    if ((*(uint *)(param_1 + 0x20) & 0x80000000) != 0) {
      if (param_2 == (undefined4 *)0x0) {
        *(undefined4 *)(param_1 + 0x1c) = 2;
        *(undefined4 *)(param_1 + 0x20) = 0;
        return 0;
      }
      *(undefined4 *)(param_1 + 0x1c) = *param_2;
      *(undefined4 *)(param_1 + 0x20) = param_2[1];
      return 0;
    }
    if (param_2 != (undefined4 *)0x0) {
      props_releaseValue(param_1,(byte)*(undefined4 *)(param_1 + 0xac),*(int **)(param_1 + 0xb0));
      *(undefined4 *)(param_1 + 0xac) = *param_2;
      *(undefined4 *)(param_1 + 0xb0) = param_2[1];
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    iVar3 = **(int **)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x18));
  }
  return 0;
}



// ============================================================
// Function: props_normalizeType (FUN_680333d0)
// Address: 680333d0
// Size: 53 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_normalizeType(int param_1,int param_2,int param_3)
{
  int local_c;
  int local_8;
  
  if ((param_3 == 0) && ((param_2 == 1 || (param_2 == 9)))) {
    param_2 = 0;
  }
  local_8 = param_3;
  local_c = param_2;
  props_popArgs(param_1,&local_c);
  return 0;
}



// ============================================================
// Function: props_getTypedValue (FUN_68033410)
// Address: 68033410
// Size: 330 bytes
// Params: int param_1, int param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getTypedValue(int param_1,int param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint local_c;
  uint local_8;
  
  iVar3 = props_getInt(param_1);
  if (iVar3 < param_2) {
    if (param_2 < 5) {
      props_setError(param_1,param_2 + 0x14);
      return 0;
    }
    props_setError(param_1,0x19);
    return 0;
  }
  puVar4 = (uint *)(**(int **)(param_1 + 0x10) + -8 + (param_2 - *(int *)(param_1 + 0x20)) * 8 +
                   *(int *)(param_1 + 0x18));
  uVar1 = *puVar4;
  if (uVar1 == param_3) {
    *param_4 = puVar4[1];
    return 1;
  }
  if (param_3 == 4) {
    iVar3 = props_coerceToInt(param_1,(int *)puVar4,(int *)param_4);
    if (iVar3 != 0) {
      return 1;
    }
  }
  else if (param_3 == 9) {
    if (uVar1 == 4) {
      props_storeNumber(param_1,(double)(int)puVar4[1],&local_c);
      puVar4 = (uint *)(**(int **)(param_1 + 0x10) + -8 + (param_2 - *(int *)(param_1 + 0x20)) * 8 +
                       *(int *)(param_1 + 0x18));
      *puVar4 = local_c;
      puVar4[1] = local_8;
      *param_4 = local_8;
      return 1;
    }
  }
  else if ((param_3 == 8) && ((uVar1 == 0x40 || (uVar1 == 0x43)))) {
    local_8 = puVar4[1];
    local_c = uVar1;
    props_resolveValue(param_1,&local_c);
    iVar2 = *(int *)(param_1 + 0x18);
    iVar3 = **(int **)(param_1 + 0x10) + -8 + (param_2 - *(int *)(param_1 + 0x20)) * 8;
    *(uint *)(iVar3 + iVar2) = local_c;
    *(uint *)(iVar3 + 4 + iVar2) = local_8;
    *param_4 = local_8;
    return 1;
  }
  props_setTypeError(param_1,param_3);
  return 0;
}



// ============================================================
// Function: props_tryGetTypedValue (FUN_68033560)
// Address: 68033560
// Size: 397 bytes
// Params: int param_1, int param_2, int param_3, uint param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_tryGetTypedValue(int param_1,int param_2,int param_3,uint param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint local_c;
  uint local_8;
  
  iVar3 = props_getInt(param_1);
  if (iVar3 < param_3) {
    if (param_2 != 0) {
      if (param_3 < 5) {
        props_setError(param_1,param_3 + 0x14);
        return 0;
      }
      props_setError(param_1,0x19);
    }
    return 0;
  }
  puVar4 = (uint *)(**(int **)(param_1 + 0x10) + -8 + (param_3 - *(int *)(param_1 + 0x20)) * 8 +
                   *(int *)(param_1 + 0x18));
  uVar1 = *puVar4;
  if (uVar1 == param_4) {
LAB_680335aa:
    *param_5 = uVar1;
    param_5[1] = puVar4[1];
    return 1;
  }
  if (param_4 == 1) {
    if ((uVar1 == 0x40) || (uVar1 == 0x43)) goto LAB_680335aa;
  }
  else if (param_4 == 9) {
    if ((uVar1 == 0x20) || (uVar1 == 0x23)) goto LAB_680335aa;
    if (uVar1 == 4) {
      props_storeNumber(param_1,(double)(int)puVar4[1],&local_c);
      iVar2 = *(int *)(param_1 + 0x18);
      iVar3 = **(int **)(param_1 + 0x10) + -8 + (param_3 - *(int *)(param_1 + 0x20)) * 8;
      *(uint *)(iVar3 + iVar2) = local_c;
      *(uint *)(iVar3 + 4 + iVar2) = local_8;
      *param_5 = local_c;
      param_5[1] = local_8;
      return 1;
    }
  }
  else if (param_4 == 4) {
    *param_5 = 4;
    iVar3 = props_coerceToInt(param_1,(int *)puVar4,(int *)(param_5 + 1));
    if (iVar3 != 0) {
      return 1;
    }
  }
  else if ((param_4 == 8) && ((uVar1 == 0x40 || (uVar1 == 0x43)))) {
    local_8 = puVar4[1];
    local_c = uVar1;
    props_resolveValue(param_1,&local_c);
    iVar2 = *(int *)(param_1 + 0x18);
    iVar3 = **(int **)(param_1 + 0x10) + -8 + (param_3 - *(int *)(param_1 + 0x20)) * 8;
    *(uint *)(iVar3 + iVar2) = local_c;
    *(uint *)(iVar3 + 4 + iVar2) = local_8;
    *param_5 = local_c;
    param_5[1] = local_8;
    return 1;
  }
  if (param_2 != 0) {
    props_setTypeError(param_1,param_4);
  }
  return 0;
}



// ============================================================
// Function: props_getTypedProperty (FUN_680336f0)
// Address: 680336f0
// Size: 50 bytes
// Params: int param_1, int param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getTypedProperty(int param_1,int param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = props_getInt(param_1);
  if (param_2 <= iVar1) {
    uVar2 = props_getTypedValue(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return 1;
}



// ============================================================
// Function: props_getValueDirect (FUN_68033730)
// Address: 68033730
// Size: 30 bytes
// Params: int param_1, int param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getValueDirect(int param_1,int param_2,uint param_3,uint *param_4)
{
  props_tryGetTypedValue(param_1,1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: props_getOptionalValue (FUN_68033750)
// Address: 68033750
// Size: 66 bytes
// Params: int param_1, int param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getOptionalValue(int param_1,int param_2,uint param_3,uint *param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  *param_4 = 0;
  param_4[1] = 0;
  iVar1 = props_getInt(param_1);
  if (param_2 <= iVar1) {
    uVar2 = props_getValueDirect(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  return 1;
}



// ============================================================
// Function: props_getStackDepth (FUN_680337a0)
// Address: 680337a0
// Size: 113 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getStackDepth(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = **(int **)(param_1 + 0x28);
  iVar2 = *(int *)(param_1 + 0xa4);
  if ((iVar2 < 0) || (*(int *)(iVar1 + 0x14) <= iVar2)) {
    *(undefined4 *)(param_1 + 0x9c) = 0;
    props_setError(param_1,0x33);
  }
  else {
    uVar3 = props_getHandlerValue(param_1,*(int *)(iVar1 + 0x2c + iVar2 * 0x18));
    *(undefined4 *)(param_1 + 0x9c) = uVar3;
    *(undefined4 *)(param_1 + 0xa0) = *(undefined4 *)(iVar1 + iVar2 * 0x18 + 0x30);
    *(undefined4 *)(param_1 + 0xa8) = 0;
  }
  if (*(int *)(param_1 + 0x9c) != 0) {
    *(undefined4 *)(param_1 + 0x74) = 2;
  }
  return 0;
}



// ============================================================
// Function: props_pushFrame (FUN_68034520)
// Address: 68034520
// Size: 470 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// Pushes a new stack frame for handler execution
// ============================================================

int props_pushFrame(int param_1,undefined4 param_2,undefined4 param_3)
{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  undefined4 *puVar12;
  
  iVar5 = *(int *)(**(int **)(param_1 + 0x9c) + 0x20);
  if (iVar5 != *(int *)(param_1 + 0x3c)) {
    props_selectScript(param_1,iVar5);
  }
  uVar2 = *(uint *)(param_1 + 0x20);
  iVar5 = props_getInt(param_1);
  if (-1 < iVar5) {
    iVar3 = *(int *)(param_1 + 0x18);
    iVar8 = iVar3 + iVar5 * -8;
    if ((-1 < iVar8) && (iVar8 <= iVar3)) {
      iVar7 = **(int **)(param_1 + 0x9c);
      if (*(int *)(param_1 + 0xa0) < *(int *)(iVar7 + 0x80)) {
        iVar9 = *(int *)(iVar7 + 0x84) + *(int *)(param_1 + 0xa0) * 0x3c;
        iVar11 = *(int *)(iVar9 + 0x18 + iVar7);
        iVar9 = iVar9 + iVar7;
        uVar4 = *(undefined4 *)(iVar9 + 0xc);
        iVar7 = *(int *)(iVar9 + 0x38);
        uVar10 = *(int *)(iVar9 + 0x10) - iVar5;
        if (0 < (int)uVar10) {
          if (0xfffffff < uVar10) {
            return 0;
          }
          if ((*(int *)(param_1 + 0x14) <= (int)(iVar3 + uVar10 * 8)) &&
             (iVar9 = props_growStack(param_1,uVar10 * 8), iVar9 == 0)) {
            return 0;
          }
          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + uVar10 * 8;
          puVar6 = (undefined4 *)(**(int **)(param_1 + 0x10) + iVar3);
          do {
            uVar10 = uVar10 - 1;
            *puVar6 = 2;
            puVar6[1] = 0;
            puVar6 = puVar6 + 2;
          } while (0 < (int)uVar10);
        }
        iVar9 = *(int *)(param_1 + 0x18);
        iVar3 = iVar11 * 8;
        if ((iVar9 + iVar7 * 8 + 0x34 + iVar3 < *(int *)(param_1 + 0x14)) ||
           (iVar7 = props_growStack(param_1,iVar3 + 0x34 + iVar7 * 8), iVar7 != 0)) {
          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + iVar3;
          puVar6 = (undefined4 *)(**(int **)(param_1 + 0x10) + iVar9);
          for (; 0 < iVar11; iVar11 = iVar11 + -1) {
            *puVar6 = 2;
            puVar6[1] = 0;
            puVar6 = puVar6 + 2;
          }
          iVar3 = *(int *)(param_1 + 0x18);
          *(undefined4 *)(param_1 + 100) = param_2;
          *(undefined4 *)(param_1 + 0x70) = param_3;
          puVar6 = (undefined4 *)(param_1 + 0x40);
          puVar12 = (undefined4 *)(**(int **)(param_1 + 0x10) + iVar3);
          for (iVar7 = 0xd; iVar7 != 0; iVar7 = iVar7 + -1) {
            *puVar12 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar12 = puVar12 + 1;
          }
          *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + 0x34;
          piVar1 = (int *)(**(int **)(param_1 + 0x9c) + 4);
          *piVar1 = *piVar1 + 1;
          *(int *)(param_1 + 0x40) = iVar3;
          *(int *)(param_1 + 0x44) = iVar8;
          *(int *)(param_1 + 0x48) = iVar9;
          *(undefined4 *)(param_1 + 0x54) = *(undefined4 *)(param_1 + 0xa0);
          *(undefined4 *)(param_1 + 0x4c) = uVar4;
          *(int **)(param_1 + 0x50) = *(int **)(param_1 + 0x9c);
          *(undefined4 *)(param_1 + 0x60) = *(undefined4 *)(param_1 + 0xa8);
          *(undefined4 *)(param_1 + 0x58) = *(undefined4 *)(param_1 + 0x3c);
          *(undefined4 *)(param_1 + 0x68) = *(undefined4 *)(**(int **)(param_1 + 0x9c) + 0x54);
          *(int *)(param_1 + 0x5c) = iVar5;
          *(uint *)(param_1 + 0x6c) = uVar2 >> 0x1f;
          *(undefined4 *)(param_1 + 0xa8) = 0;
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: props_copyHandle (FUN_68034700)
// Address: 68034700
// Size: 36 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// Copies a handle, setting error if allocation fails
// ============================================================

int props_copyHandle(int param_1)

{
  int iVar1;
  
  iVar1 = Ordinal_1120();
  if (iVar1 == 0) {
    props_setError(param_1,2);
  }
  return iVar1;
}


