// Module: stage
// Topic: Code emission and constant encoding
// Address range: 0x68054F70 - 0x680555F0
// Functions (14):
//   stage_emitConstant (FUN_68054F70)
//   stage_emitConstantFixed (FUN_68055030)
//   stage_emitConstantVar (FUN_68055050)
//   stage_compileBlock (stage_compileBlock)
//   stage_emitSymbol (FUN_680551F0)
//   stage_popSymbol (FUN_68055210)
//   stage_peekSymbol (FUN_68055230)
//   stage_getSymbolDepth (FUN_68055250)
//   stage_flushSymbols (FUN_68055270)
//   stage_compileHandler (FUN_680552C0)
//   stage_compileArgList (FUN_68055370)
//   stage_emitReturnEx (stage_emitReturnEx)
//   stage_emitReturn (FUN_680555D0)
//   stage_resolveBinding (FUN_680555F0)

// ============================================================
// Function: stage_emitConstant (FUN_68054F70)
// Address: 68054f70
// Size: 179 bytes
// Params: void * this, uint param_1, undefined1 * param_2
// Return: uint
// Calling convention: __thiscall
// ============================================================

uint __thiscall stage_emitConstant(void *this,uint param_1,undefined1 *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = stage_getBytecodeRef(*(int **)(**(int **)((int)this + 8) + 0x43c));
  stage_emitBytecode(*(int **)(**(int **)((int)this + 8) + 0x43c),(undefined1 *)&param_1,4);
  iVar1 = stage_emitPushIfNeeded((int)this);
  if (iVar1 != 0) {
    stage_emitBytecode(*(int **)(**(int **)((int)this + 8) + 0x43c),param_2,param_1);
    iVar1 = stage_emitPushIfNeeded((int)this);
    if (iVar1 != 0) {
      if ((param_1 & 3) != 0) {
        stage_emitBytecode(*(int **)(**(int **)((int)this + 8) + 0x43c),(undefined1 *)&local_8,
                     4 - (param_1 & 3));
        iVar1 = stage_emitPushIfNeeded((int)this);
        if (iVar1 == 0) {
          return 0;
        }
      }
      uVar2 = stage_emitLabelRef(&local_10);
      return uVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_emitConstantFixed (FUN_68055030)
// Address: 68055030
// Size: 23 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_emitConstantFixed(void *param_1)
{
  stage_emitConstant(param_1,8,&stack0x00000004);
  return 0;
}



// ============================================================
// Function: stage_emitConstantVar (FUN_68055050)
// Address: 68055050
// Size: 22 bytes
// Params: void * this, void * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall stage_emitConstantVar(void *this,void *param_1)
{
  undefined1 *in_EAX;

  stage_emitConstant(param_1,(uint)this,in_EAX);
  return 0;
}



// ============================================================
// Function: stage_compileBlock (FUN_68055070)
// Address: 68055070
// Size: 292 bytes
// Params: void * param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileBlock(void *param_1,uint *param_2)
{
  uint uVar1;
  void *pvVar2;
  uint *puVar3;
  int iVar4;
  uint local_c;
  uint local_8;
  
  puVar3 = param_2;
  pvVar2 = param_1;
  uVar1 = *param_2;
  if (uVar1 == 4) {
    stage_emitBranch((int)param_1,param_2[1]);
  }
  else if (uVar1 == 8) {
    stage_emitBranchCond((int)param_1,param_2[1]);
  }
  else if (uVar1 == 0x20) {
    param_2 = (uint *)param_2[1];
    stage_emitLongImmediate((int)param_1,(int)param_2);
  }
  else {
    iVar4 = score_lookupProplistEntry(param_1,*(int **)(**(int **)((int)param_1 + 8) + 0x434),param_2,&local_c,
                         (int *)&param_2);
    if (iVar4 == 0) {
      switch(*puVar3) {
      case 1:
      case 0x40:
      case 0x43:
        props_getStringData((int *)puVar3,(int *)&param_1);
        local_8 = stage_emitConstantVar((void *)((int)param_1 + 1),pvVar2);
        props_unlockString((int *)puVar3);
        break;
      default:
        stage_emitPushLiteral((int)pvVar2,0x26);
        goto LAB_6805517f;
      case 9:
      case 0x23:
        local_8 = stage_emitConstantFixed(pvVar2);
      }
      local_c = 4;
      score_storeProplistProperty(pvVar2,*(int **)(**(int **)((int)pvVar2 + 8) + 0x434),(int)param_2,puVar3,
                   &local_c);
    }
    else {
      stage_emitInstruction((int)pvVar2,0x44,local_8,1);
    }
  }
LAB_6805517f:
  props_releaseValue(pvVar2,(byte)*puVar3,(int *)puVar3[1]);
  return 0;
}



// ============================================================
// Function: stage_emitSymbol (FUN_680551F0)
// Address: 680551f0
// Size: 25 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitSymbol(void)
{
  undefined4 *in_EAX;
  int unaff_ESI;
  
  stage_lookupSymbolId(*(int **)(**(int **)(unaff_ESI + 8) + 0x448),in_EAX);
  stage_emitPushIfNeeded(unaff_ESI);
  return 0;
}



// ============================================================
// Function: stage_popSymbol (FUN_68055210)
// Address: 68055210
// Size: 25 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_popSymbol(void)

{
  int iVar1;
  undefined4 uVar2;
  int in_EAX;
  
  iVar1 = **(int **)(**(int **)(in_EAX + 8) + 0x448);
  uVar2 = *(undefined4 *)(iVar1 + 0x1c + *(int *)(iVar1 + 0x10) * 8);
  *(int *)(iVar1 + 0x10) = *(int *)(iVar1 + 0x10) + -1;
  return uVar2;
}



// ============================================================
// Function: stage_peekSymbol (FUN_68055230)
// Address: 68055230
// Size: 21 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_peekSymbol(void)

{
  int iVar1;
  int in_EAX;
  
  iVar1 = **(int **)(**(int **)(in_EAX + 8) + 0x448);
  return *(undefined4 *)(iVar1 + 0x18 + *(int *)(iVar1 + 0x10) * 8);
}



// ============================================================
// Function: stage_getSymbolDepth (FUN_68055250)
// Address: 68055250
// Size: 17 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_getSymbolDepth(void)

{
  int in_EAX;
  
  return *(undefined4 *)(**(int **)(**(int **)(in_EAX + 8) + 0x448) + 0x10);
}



// ============================================================
// Function: stage_flushSymbols (FUN_68055270)
// Address: 68055270
// Size: 71 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_flushSymbols(void)
{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  int *unaff_EDI;

  iVar1 = stage_getSymbolDepth();
  while ((unaff_EBX < iVar1 &&
         ((unaff_EDI == (int *)0x0 || (iVar1 = stage_peekSymbol(), *unaff_EDI <= iVar1))))) {
    iVar1 = -1;
    uVar2 = stage_popSymbol();
    stage_emitOpcode(in_EAX,uVar2,iVar1);
    iVar1 = stage_getSymbolDepth();
  }
  if (unaff_EDI != (int *)0x0) {
    stage_emitSymbol();
  }
  return 0;
}



// ============================================================
// Function: stage_compileHandler (FUN_680552c0)
// Address: 680552c0
// Size: 174 bytes
// Params: void * param_1, undefined * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileHandler(void *param_1,undefined *param_2)
{
  int iVar1;
  
  stage_compileExpression(param_1,param_2,0);
  if ((*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) &&
     (iVar1 = stage_tryInlineCallback(param_2), iVar1 != 0)) {
    stage_getSymbolDepth();
    stage_emitSymbol();
    stage_compileExpression(param_1,param_2,0);
    if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
      while (iVar1 = stage_tryInlineCallback(param_2), iVar1 != 0) {
        stage_flushSymbols();
        stage_compileExpression(param_1,param_2,0);
        if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
          return 0;
        }
      }
      stage_flushSymbols();
    }
  }
  return 0;
}



// ============================================================
// Function: stage_compileArgList (FUN_68055370)
// Address: 68055370
// Size: 464 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_compileArgList(int param_1,int param_2,uint *param_3)

{
  uint in_EAX;
  void *unaff_ESI;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  if ((in_EAX == 0) && (param_1 == 0)) {
    stage_pushCurrentScope((int)unaff_ESI);
    if ((local_14 == 8) && (local_10 == 4)) {
      stage_pushCurrentScope((int)unaff_ESI);
      if ((local_c == 8) && (local_8 == 5)) {
LAB_680554d3:
        stage_emitInstruction((int)unaff_ESI,0x42,in_EAX,1);
        *param_3 = in_EAX + 1;
        return 0;
      }
      stage_resolveSymbol((int)unaff_ESI,&local_c);
    }
    stage_resolveSymbol((int)unaff_ESI,&local_14);
  }
  if (param_2 == 0) {
    local_c = 0;
    local_8 = 0;
  }
  else {
    local_c = 8;
    local_8 = 5;
  }
  if (0 < (int)in_EAX) goto LAB_68055445;
LAB_680553f7:
  while ((stage_pushCurrentScope((int)unaff_ESI), local_14 != local_c || (local_10 != local_8))) {
    if (local_14 == 0) {
      stage_emitPushLiteral((int)unaff_ESI,0x28);
      return 0;
    }
    stage_resolveSymbol((int)unaff_ESI,&local_14);
    stage_compileHandler(unaff_ESI,lingo_noop);
    if (*(int *)(**(int **)((int)unaff_ESI + 8) + 0x41c) != 0) {
      return 0;
    }
    in_EAX = in_EAX + 1;
LAB_68055445:
    stage_pushCurrentScope((int)unaff_ESI);
    if ((local_14 != 8) || (0x2e < local_10)) goto LAB_68055487;
    if (local_10 != 0) goto LAB_6805547e;
    if (param_1 != 0) {
      stage_emitPushLiteral((int)unaff_ESI,0x24);
      return 0;
    }
    local_c = 8;
    local_8 = 5;
  }
  if (param_1 != 0) {
    stage_emitInstruction((int)unaff_ESI,0x43,in_EAX,1);
    *param_3 = in_EAX;
    return 0;
  }
  goto LAB_680554d3;
LAB_6805547e:
  if (local_10 != 3) {
LAB_68055487:
    if ((*(int *)(**(int **)((int)unaff_ESI + 8) + 0x4d0) == 0) &&
       (((local_14 != local_c || (local_10 != local_8)) && (in_EAX != 1)))) {
      if ((local_14 == 8) && (local_10 == 0x68)) {
        stage_emitPushLiteral((int)unaff_ESI,0x33);
        return 0;
      }
      stage_emitPushLiteral((int)unaff_ESI,5);
      return 0;
    }
    stage_resolveSymbol((int)unaff_ESI,&local_14);
  }
  goto LAB_680553f7;
}



// ============================================================
// Function: stage_emitReturnEx (FUN_68055540)
// Address: 68055540
// Size: 138 bytes
// Params: int param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitReturnEx(int param_1,int param_2,uint param_3)
{
  int in_EAX;
  uint uVar1;
  int iVar2;
  uint unaff_EBX;
  
  uVar1 = stage_resolveSymbolIndex();
  stage_compileArgList(param_2,param_3,&param_3);
  if (*(int *)(**(int **)(in_EAX + 8) + 0x41c) == 0) {
    if (((-1 < (int)uVar1) && (unaff_EBX != 0x82)) && (param_1 == 0)) {
      stage_emitInstruction(in_EAX,0x56,uVar1,-param_3);
      return 0;
    }
    (*(unsigned char *)((char *)&param_2 + 0)) = *(undefined1 *)(**(int **)(in_EAX + 8) + 0x418);
    if (param_1 != 0) {
      (*(unsigned char *)((char *)&param_2 + 0)) = 0x73;
    }
    iVar2 = -param_3;
    uVar1 = props_resolveSymbol(in_EAX,unaff_EBX);
    stage_emitInstruction(in_EAX,param_2,uVar1,iVar2);
  }
  return 0;
}



// ============================================================
// Function: stage_emitReturn (FUN_680555d0)
// Address: 680555d0
// Size: 30 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitReturn(void)
{
  stage_emitReturnEx(0,0,0);
  return 0;
}



// ============================================================
// Function: stage_resolveBinding (FUN_680555F0)
// Address: 680555f0
// Size: 127 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_resolveBinding(int param_1)
{
  uint in_EAX;
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint local_c;
  undefined4 local_8;
  
  iVar1 = stage_resolveVarScope(0,&local_8,3);
  if (iVar1 == 0) {
    return 0;
  }
  uVar3 = *(uint *)(**(int **)(**(int **)(param_1 + 8) + 0x428) + 0x54);
  if ((uVar3 & 4) == 0) {
    if ((uVar3 & 8) == 0) goto LAB_68055661;
    iVar4 = 1;
    iVar1 = 0;
    uVar3 = props_resolveSymbol(param_1,in_EAX);
    puVar2 = props_resolveVariable(param_1,uVar3,iVar1,iVar4);
  }
  else {
    puVar2 = score_lookupProperty(*(int **)(**(int **)(param_1 + 8) + 0x4e4),in_EAX,0,&local_c);
  }
  if (puVar2 != (uint *)0x0) {
    return 0;
  }
LAB_68055661:
  core_isClassProperty(param_1,in_EAX);
  return 0;
}



