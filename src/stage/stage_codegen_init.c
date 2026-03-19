// Module: stage
// Topic: Code generation initialization and setup
// Address range: 0x68053FC0 - 0x68054430
// Functions (9):
//   stage_addBytecodeOffset (FUN_68053FC0)
//   stage_createLargeBytecodeBlock (FUN_68054040)
//   stage_createSmallBytecodeBlock (FUN_68054050)
//   stage_initSymbolTables (FUN_68054060)
//   stage_initCodegenContext (FUN_68054100)
//   stage_resolveSymbolIndex (FUN_68054240)
//   stage_updateSymbolEntry (FUN_680542A0)
//   stage_resetCodegenState (FUN_680542E0)
//   stage_finalizeCodegen (FUN_68054430)

// ============================================================
// Function: stage_addBytecodeOffset (FUN_68053FC0)
// Address: 68053fc0
// Size: 127 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_addBytecodeOffset(int param_1)
{
  byte bVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *unaff_ESI;
  
  iVar2 = *unaff_ESI;
  bVar1 = *(byte *)(iVar2 + DAT_681962c0);
  uVar3 = (uint)bVar1;
  if ((char)bVar1 < '\0') {
    uVar3 = (uVar3 & 0xffffff7f) << 8 | (uint)*(byte *)(iVar2 + 1 + DAT_681962c0);
  }
  iVar4 = uVar3 + param_1;
  if (0x7f < iVar4) {
    if ((char)bVar1 >= '\0') {
      stage_emitSingleByte(unaff_ESI);
      iVar2 = *unaff_ESI + DAT_681962c0;
      Ordinal_1129(iVar2 + 1,iVar2,(*(int *)(*unaff_ESI + 0x10) - DAT_681962c0) + -1);
    }
    iVar2 = DAT_681962c0;
    *(byte *)(DAT_681962c0 + *unaff_ESI) = (byte)((uint)iVar4 >> 8) | 0x80;
    *(char *)(*unaff_ESI + 1 + iVar2) = (char)iVar4;
    return 0;
  }
  *(char *)(iVar2 + DAT_681962c0) = (char)iVar4;
  return 0;
}



// ============================================================
// Function: stage_createLargeBytecodeBlock (FUN_68054040)
// Address: 68054040
// Size: 15 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_createLargeBytecodeBlock(void)
{
  stage_createBytecodeBlock(0x20,0x1c,0x400);
  return 0;
}



// ============================================================
// Function: stage_createSmallBytecodeBlock (FUN_68054050)
// Address: 68054050
// Size: 15 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_createSmallBytecodeBlock(void)
{
  stage_createBytecodeBlock(0x20,0x1c,0x200);
  return 0;
}



// ============================================================
// Function: stage_initSymbolTables (FUN_68054060)
// Address: 68054060
// Size: 148 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_initSymbolTables(void)

{
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  
  uVar1 = score_getSymbolName(0xf,0x18);
  *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x48c) = uVar1;
  iVar2 = stage_emitPushIfNeeded(unaff_ESI);
  if (iVar2 != 0) {
    uVar1 = score_getSymbolName(0xf,0x18);
    *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x490) = uVar1;
    iVar2 = stage_emitPushIfNeeded(unaff_ESI);
    if (iVar2 != 0) {
      uVar1 = score_getSymbolName(0xf,0x18);
      *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x494) = uVar1;
      iVar2 = stage_emitPushIfNeeded(unaff_ESI);
      if (iVar2 != 0) {
        uVar1 = stage_createLargeBytecodeBlock();
        *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x498) = uVar1;
        iVar2 = stage_emitPushIfNeeded(unaff_ESI);
        if (iVar2 != 0) {
          uVar1 = stage_allocSmallBytecode();
          *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x49c) = uVar1;
          iVar2 = stage_emitPushIfNeeded(unaff_ESI);
          return iVar2 != 0;
        }
      }
    }
  }
  return false;
}



// ============================================================
// Function: stage_initCodegenContext (FUN_68054100)
// Address: 68054100
// Size: 318 bytes
// Params: int param_1
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_initCodegenContext(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar2 = stage_allocObject(param_1);
  *(int **)(**(int **)(param_1 + 8) + 0x428) = piVar2;
  iVar3 = stage_emitPushIfNeeded(param_1);
  if (iVar3 != 0) {
    uVar4 = score_getSymbolName(0xf,0x18);
    *(undefined4 *)(**(int **)(param_1 + 8) + 0x42c) = uVar4;
    iVar3 = stage_emitPushIfNeeded(param_1);
    if (iVar3 != 0) {
      uVar4 = stage_allocDispatchLarge();
      *(undefined4 *)(**(int **)(param_1 + 8) + 0x430) = uVar4;
      if (*(int *)(**(int **)(param_1 + 8) + 0x430) != 0) {
        uVar4 = score_deleteProplistEntry(param_1,0x32);
        *(undefined4 *)(**(int **)(param_1 + 8) + 0x434) = uVar4;
        iVar3 = stage_emitPushIfNeeded(param_1);
        if (iVar3 != 0) {
          score_insertProplistEntry(param_1,*(int **)(**(int **)(param_1 + 8) + 0x434),1);
          uVar4 = stage_allocDispatchMedium();
          *(undefined4 *)(**(int **)(param_1 + 8) + 0x438) = uVar4;
          iVar3 = stage_emitPushIfNeeded(param_1);
          if (iVar3 != 0) {
            uVar4 = stage_createSmallBytecodeBlock();
            *(undefined4 *)(**(int **)(param_1 + 8) + 0x43c) = uVar4;
            iVar3 = stage_emitPushIfNeeded(param_1);
            if (iVar3 != 0) {
              uVar4 = score_getSymbolName(0xf,0x18);
              *(undefined4 *)(**(int **)(param_1 + 8) + 0x440) = uVar4;
              iVar3 = stage_emitPushIfNeeded(param_1);
              if (iVar3 != 0) {
                uVar4 = score_getSymbolName(0xf,0x18);
                *(undefined4 *)(**(int **)(param_1 + 8) + 0x444) = uVar4;
                iVar3 = stage_emitPushIfNeeded(param_1);
                if (iVar3 != 0) {
                  uVar4 = stage_allocDispatchSmall();
                  *(undefined4 *)(**(int **)(param_1 + 8) + 0x448) = uVar4;
                  iVar3 = stage_emitPushIfNeeded(param_1);
                  if (iVar3 != 0) {
                    bVar1 = stage_initSymbolTables();
                    return bVar1;
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return false;
}



// ============================================================
// Function: stage_resolveSymbolIndex (FUN_68054240)
// Address: 68054240
// Size: 89 bytes
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint stage_resolveSymbolIndex(void)

{
  uint *puVar1;
  uint uVar2;
  int unaff_ESI;
  uint unaff_EDI;
  uint *puVar3;
  
  puVar1 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x494),unaff_EDI,0,(uint *)0x0);
  if (puVar1 == (uint *)0x0) {
    puVar1 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x444),unaff_EDI,0,(uint *)0x0);
    if (puVar1 == (uint *)0x0) {
      puVar3 = puVar1;
      uVar2 = props_resolveSymbol(unaff_ESI,unaff_EDI);
      puVar1 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x42c),uVar2,(int)puVar1,puVar3);
      if (puVar1 != (uint *)0x0) {
        return puVar1[1];
      }
    }
  }
  return 0xffffffff;
}



// ============================================================
// Function: stage_updateSymbolEntry (FUN_680542A0)
// Address: 680542a0
// Size: 62 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_updateSymbolEntry(uint param_1)
{
  uint in_EAX;
  uint *puVar1;
  int unaff_ESI;
  
  puVar1 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x42c),in_EAX,1,(uint *)0x0);
  if (puVar1 != (uint *)0x0) {
    if (*puVar1 == 4) {
      stage_emitPushLiteral(unaff_ESI,0x1f);
      return 0;
    }
    *puVar1 = 4;
    puVar1[1] = param_1;
  }
  return 0;
}



// ============================================================
// Function: stage_resetCodegenState (FUN_680542E0)
// Address: 680542e0
// Size: 336 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_resetCodegenState(int param_1,uint param_2)
{
  int *piVar1;
  undefined4 uVar2;
  
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4c8) = 0;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4c4) = 0;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x44c) =
       *(undefined4 *)(**(int **)(param_1 + 8) + 0x424);
  piVar1 = (int *)(**(int **)(param_1 + 8) + 0x424);
  *piVar1 = *piVar1 + 1;
  uVar2 = props_resolveSymbol(param_1,param_2);
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x450) = uVar2;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x454) = 0xffffffff;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x458) = 0;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x45c) = 0xffffffff;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x460) = 0;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x464) = 0xffffffff;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x468) = 0;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x46c) = 0xffffffff;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x470) = 0;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x474) = 0xffffffff;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x478) =
       *(undefined4 *)(*(int *)(**(int **)(param_1 + 8) + 0x420) + 4);
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x47c) =
       *(undefined4 *)(*(int *)(**(int **)(param_1 + 8) + 0x420) + 0x14);
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x480) = 0;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x484) = 0xffffffff;
  score_invalidateEntries(*(int **)(**(int **)(param_1 + 8) + 0x48c));
  score_invalidateEntries(*(int **)(**(int **)(param_1 + 8) + 0x490));
  score_invalidateEntries(*(int **)(**(int **)(param_1 + 8) + 0x494));
  stage_resetBytecodeOffset(*(int **)(**(int **)(param_1 + 8) + 0x498));
  stage_resetBytecodeOffset(*(int **)(**(int **)(param_1 + 8) + 0x49c));
  return 0;
}



// ============================================================
// Function: stage_finalizeCodegen (FUN_68054430)
// Address: 68054430
// Size: 519 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_finalizeCodegen(int param_1)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  iVar2 = **(int **)(param_1 + 8);
  if (*(int *)(iVar2 + 0x41c) == 0) {
    *(undefined4 *)(iVar2 + 0x488) = *(undefined4 *)(iVar2 + 0x4c4);
    uVar1 = stage_getBytecodeRef(*(int **)(**(int **)(param_1 + 8) + 0x498));
    *(uint *)(**(int **)(param_1 + 8) + 0x458) = uVar1;
    *(undefined4 *)(**(int **)(param_1 + 8) + 0x45c) =
         *(undefined4 *)(**(int **)(**(int **)(param_1 + 8) + 0x428) + 0x10);
    Ordinal_1114(*(undefined4 *)(**(int **)(param_1 + 8) + 0x498));
    stage_emitString(param_1,*(int **)(**(int **)(param_1 + 8) + 0x428),
                 (undefined1 *)(**(int **)(**(int **)(param_1 + 8) + 0x498) + 0x1c),uVar1);
    Ordinal_1115(*(undefined4 *)(**(int **)(param_1 + 8) + 0x498));
    *(undefined4 *)(**(int **)(param_1 + 8) + 0x464) =
         *(undefined4 *)(**(int **)(**(int **)(param_1 + 8) + 0x428) + 0x10);
    iVar2 = **(int **)(param_1 + 8);
    stage_emitJump(param_1,*(int **)(iVar2 + 0x428),*(int **)(iVar2 + 0x48c),*(int *)(iVar2 + 0x460));
    *(undefined4 *)(**(int **)(param_1 + 8) + 0x46c) =
         *(undefined4 *)(**(int **)(**(int **)(param_1 + 8) + 0x428) + 0x10);
    iVar2 = **(int **)(param_1 + 8);
    stage_emitJump(param_1,*(int **)(iVar2 + 0x428),*(int **)(iVar2 + 0x490),*(int *)(iVar2 + 0x468));
    *(undefined4 *)(**(int **)(param_1 + 8) + 0x474) =
         *(undefined4 *)(**(int **)(**(int **)(param_1 + 8) + 0x428) + 0x10);
    iVar2 = **(int **)(param_1 + 8);
    stage_emitJump(param_1,*(int **)(iVar2 + 0x428),*(int **)(iVar2 + 0x494),*(int *)(iVar2 + 0x470));
    uVar1 = stage_getBytecodeRef(*(int **)(**(int **)(param_1 + 8) + 0x49c));
    *(uint *)(**(int **)(param_1 + 8) + 0x480) = uVar1;
    *(undefined4 *)(**(int **)(param_1 + 8) + 0x484) =
         *(undefined4 *)(**(int **)(**(int **)(param_1 + 8) + 0x428) + 0x10);
    Ordinal_1114(*(undefined4 *)(**(int **)(param_1 + 8) + 0x49c));
    stage_emitString(param_1,*(int **)(**(int **)(param_1 + 8) + 0x428),
                 (undefined1 *)(**(int **)(**(int **)(param_1 + 8) + 0x49c) + 0x1c),uVar1);
    Ordinal_1115(*(undefined4 *)(**(int **)(param_1 + 8) + 0x49c));
    stage_emitStoreVar(*(int **)(**(int **)(param_1 + 8) + 0x430),
                 *(int *)(**(int **)(param_1 + 8) + 0x44c));
    iVar2 = stage_emitPushIfNeeded(param_1);
    if (iVar2 != 0) {
      iVar2 = **(int **)(param_1 + 8);
      puVar4 = (undefined4 *)(iVar2 + 0x450);
      puVar5 = (undefined4 *)(**(int **)(iVar2 + 0x430) + 0x20 + *(int *)(iVar2 + 0x44c) * 0x3c);
      for (iVar3 = 0xf; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar5 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar5 = puVar5 + 1;
      }
    }
  }
  return 0;
}



