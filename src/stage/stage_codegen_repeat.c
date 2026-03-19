// Module: stage
// Topic: Repeat/while loop compilation
// Address range: 0x6805B3E0 - 0x6805BB60
// Functions (7):
//   stage_compileRepeat (FUN_6805B3E0)
//   stage_compileExitRepeat (FUN_6805B6D0)
//   stage_isRepeatKeyword (FUN_6805B780)
//   stage_compileRepeatWith (FUN_6805B7B0)
//   stage_reportRepeatError (FUN_6805BAC0)
//   stage_tryParseRepeatBlock (FUN_6805BAE0)
//   stage_compileRepeatBody (FUN_6805BB60)

// ============================================================
// Function: stage_compileRepeat (FUN_6805B3E0)
// Address: 6805b3e0
// Size: 662 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileRepeat(void *param_1)
{
  void *pvVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  pvVar1 = param_1;
  bVar2 = stage_parseCondition((int)param_1,&local_1c,&local_8);
  if (CONCAT31(extraout_var,bVar2) == 0) {
LAB_6805b65b:
    stage_resolveSymbol((int)pvVar1,&local_1c);
    stage_emitReturn();
    return 0;
  }
  switch(local_8) {
  case 0x1f:
    iVar4 = stage_compileRepeatHeader((int)pvVar1);
    if (iVar4 == 0) {
      if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
        return 0;
      }
      goto LAB_6805b65b;
    }
    break;
  case 0x20:
  case 0x21:
  case 0x22:
  case 0x23:
    stage_compileBinaryExpr(pvVar1,local_8);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
      return 0;
    }
    break;
  default:
    stage_pushCurrentScope((int)pvVar1);
    if ((local_14 == 8) && (local_10 == 1)) {
      stage_resolveSymbol((int)pvVar1,&local_14);
      stage_declareVariable(pvVar1,local_8,&param_1,&local_c,0);
      stage_emitConditionalJump((int)pvVar1,(int)param_1,local_c);
      stage_emitInstruction((int)pvVar1,0x6d,(uint)param_1,0);
      stage_compileExprBlock((uint)pvVar1,lingo_noop,0,1,0);
LAB_6805b48b:
      stage_emitInstruction((int)pvVar1,0x42,1,1);
      iVar4 = -2;
      uVar3 = props_resolveSymbol((int)pvVar1,0x57);
      stage_emitInstruction((int)pvVar1,0x67,uVar3,iVar4);
      return 0;
    }
    stage_resolveSymbol((int)pvVar1,&local_14);
    goto LAB_6805b65b;
  case 0x2d:
  case 0x59:
    goto switchD_6805b416_caseD_2d;
  case 0x58:
    stage_pushCurrentScope((int)pvVar1);
    if ((local_14 == 8) && (local_10 == 4)) {
      stage_resolveSymbol((int)pvVar1,&local_14);
      stage_resolveSymbol((int)pvVar1,&local_1c);
      stage_compileExpression(pvVar1,lingo_noop,1);
      if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
        return 0;
      }
      goto LAB_6805b48b;
    }
    goto switchD_6805b416_caseD_2d;
  }
  stage_parseCondition((int)pvVar1,&local_1c,&local_8);
LAB_6805b51d:
  if ((local_8 == 0x2d) || ((0x57 < local_8 && (local_8 < 0x5a)))) {
    stage_compileHandler(pvVar1,lingo_noop);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) == 0) {
      iVar4 = stage_compileUnaryExpr((int)pvVar1,lingo_noop);
      if (iVar4 == 0) {
        stage_emitBranch((int)pvVar1,0);
      }
      param_1 = (void *)0x6;
      stage_emitInstruction((int)pvVar1,0x5b,6,-10);
      return 0;
    }
  }
  else {
    if ((local_1c != 8) || (local_18 < 0x2f)) {
      stage_emitPushLiteral((int)pvVar1,0x22);
      return 0;
    }
    stage_declareVariable(pvVar1,local_8,&param_1,&local_c,0);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) == 0) {
      stage_emitConditionalJump((int)pvVar1,(int)param_1,local_c);
      stage_emitInstruction((int)pvVar1,0x5b,(uint)param_1,-9);
      return 0;
    }
  }
  return 0;
switchD_6805b416_caseD_2d:
  stage_emitBranch((int)pvVar1,0);
  stage_emitBranch((int)pvVar1,0);
  stage_emitBranch((int)pvVar1,0);
  stage_emitBranch((int)pvVar1,0);
  stage_emitBranch((int)pvVar1,0);
  stage_emitBranch((int)pvVar1,0);
  stage_emitBranch((int)pvVar1,0);
  stage_emitBranch((int)pvVar1,0x7fff);
  goto LAB_6805b51d;
}



// ============================================================
// Function: stage_compileExitRepeat (FUN_6805B6D0)
// Address: 6805b6d0
// Size: 173 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileExitRepeat(int param_1)
{
  undefined4 local_c;
  undefined4 local_8;
  
  stage_pushCurrentScope(param_1);
  if (local_c == 0) {
    stage_emitReturnOpcode(param_1);
    return 0;
  }
  if (local_c == 8) {
    if (local_8 == 0x43) {
      if (*(int *)(**(int **)(param_1 + 8) + 0x4b8) == 0) {
        stage_emitPushLiteral(param_1,0x17);
        return 0;
      }
      stage_emitJumpTarget(param_1,0x53,(int *)(**(int **)(param_1 + 8) + 0x4ac));
      return 0;
    }
    if (local_8 == 0x5a) {
      if (*(int *)(**(int **)(param_1 + 8) + 0x4c0) == 0) {
        stage_emitPushLiteral(param_1,0x2a);
        return 0;
      }
      stage_emitJumpTarget(param_1,0x53,(int *)(**(int **)(param_1 + 8) + 0x4bc));
      return 0;
    }
  }
  stage_emitPushLiteral(param_1,0x27);
  return 0;
}



// ============================================================
// Function: stage_isRepeatKeyword (FUN_6805B780)
// Address: 6805b780
// Size: 44 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_isRepeatKeyword(int *param_1)

{
  int iVar1;
  
  if ((*param_1 == 8) &&
     (((iVar1 = param_1[1], iVar1 == 0x32 || (iVar1 == 0x33)) || (iVar1 == 0x34)))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_compileRepeatWith (FUN_6805B7B0)
// Address: 6805b7b0
// Size: 771 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileRepeatWith(void *param_1)
{
  void *pvVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  int iVar5;
  void *pvVar6;
  int local_20 [2];
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  pvVar1 = param_1;
  local_8 = CONCAT31((*(unsigned int *)((char *)&local_8 + 1)),0x59);
  iVar5 = 1;
  stage_pushCurrentScope((int)param_1);
  if (local_18 == 0) {
    stage_emitReturn();
    return 0;
  }
  stage_resolveSymbol((int)pvVar1,&local_18);
  stage_compileHandler(pvVar1,stage_isRepeatKeyword);
  if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
    return 0;
  }
  stage_pushCurrentScope((int)pvVar1);
  if (local_18 == 0) {
    stage_emitReturn();
    return 0;
  }
  if ((local_18 != 8) || (local_14 < 0x2f)) {
LAB_6805ba96:
    stage_resolveSymbol((int)pvVar1,&local_18);
    stage_emitReturn();
    return 0;
  }
  if (local_14 == 0x32) {
    uVar3 = 0x10;
  }
  else if (local_14 == 0x33) {
    uVar3 = 0x30;
  }
  else {
    if (local_14 != 0x34) goto LAB_6805ba96;
    uVar3 = 0x20;
  }
  bVar2 = stage_parseCondition((int)pvVar1,&local_18,(int *)&param_1);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    if (((int)param_1 < 0x20) || (0x23 < (int)param_1)) {
      local_8 = CONCAT31((*(unsigned int *)((char *)&local_8 + 1)),0x59);
    }
    else {
      stage_compileBinaryExpr(pvVar1,(int)param_1);
      if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
        return 0;
      }
      local_8 = CONCAT31((*(unsigned int *)((char *)&local_8 + 1)),0x5a);
      stage_parseCondition((int)pvVar1,&local_18,(int *)&param_1);
      iVar5 = 9;
    }
  }
  if (param_1 == (void *)0x2d) {
LAB_6805ba4a:
    stage_compileHandler(pvVar1,lingo_noop);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) == 0) {
      iVar4 = stage_compileUnaryExpr((int)pvVar1,lingo_noop);
      if (iVar4 == 0) {
        stage_emitBranch((int)pvVar1,0);
      }
      stage_emitInstruction((int)pvVar1,local_8,uVar3 | 6,-(iVar5 + 2));
      return 0;
    }
  }
  else {
    if (param_1 == (void *)0x58) {
      if ((char)local_8 != 'Y') goto LAB_6805ba4a;
      pvVar6 = (void *)0x0;
    }
    else {
      if (param_1 == (void *)0x59) goto LAB_6805ba4a;
      pvVar6 = param_1;
      if ((local_18 == 8) && (0x2e < local_14)) {
        stage_pushCurrentScope((int)pvVar1);
        if (local_20[0] == 0) {
          stage_declareVariable(pvVar1,param_1,&local_c,&local_10,(uint)(uVar3 == 0x10));
          if ((uVar3 == 0x10) && ((char)local_8 == 'Y')) {
            local_8 = CONCAT31((*(unsigned int *)((char *)&local_8 + 1)),(char)local_c + 'M');
            stage_emitInstruction((int)pvVar1,local_8,local_10,-iVar5);
            return 0;
          }
          stage_emitConditionalJump((int)pvVar1,local_c,local_10);
          stage_emitInstruction((int)pvVar1,local_8,uVar3 | local_c,-(iVar5 + 1));
          return 0;
        }
        stage_resolveSymbol((int)pvVar1,local_20);
        stage_declareVariable(pvVar1,param_1,&local_c,&local_10,0);
        stage_emitConditionalJump((int)pvVar1,local_c,local_10);
        stage_emitInstruction((int)pvVar1,0x6d,local_c,0);
        stage_compileExprBlock((uint)pvVar1,lingo_noop,0,1,0);
        pvVar6 = param_1;
        goto LAB_6805b9f9;
      }
    }
    stage_resolveSymbol((int)pvVar1,&local_18);
    stage_compileExpression(pvVar1,lingo_noop,1);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) == 0) {
LAB_6805b9f9:
      if (uVar3 == 0x10) {
        pvVar6 = (void *)0x5b;
      }
      else if (uVar3 == 0x20) {
        pvVar6 = (void *)0x5d;
      }
      else if (uVar3 == 0x30) {
        pvVar6 = (void *)0x5c;
      }
      stage_emitOpcode((int)pvVar1,0x21,0);
      stage_emitInstruction((int)pvVar1,0x42,2,1);
      iVar5 = -3;
      uVar3 = props_resolveSymbol((int)pvVar1,(uint)pvVar6);
      stage_emitInstruction((int)pvVar1,0x67,uVar3,iVar5);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_reportRepeatError (FUN_6805BAC0)
// Address: 6805bac0
// Size: 18 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_reportRepeatError(int param_1)
{
  stage_emitPushLiteral(param_1,0x11);
  return 0;
}



// ============================================================
// Function: stage_tryParseRepeatBlock (FUN_6805BAE0)
// Address: 6805bae0
// Size: 128 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_tryParseRepeatBlock(void)

{
  undefined4 uVar1;
  int unaff_ESI;
  undefined4 local_c;
  undefined4 local_8;
  
  props_saveParserState(*(int *)(**(int **)(unaff_ESI + 8) + 0x420));
  uVar1 = *(undefined4 *)(*(int *)(**(int **)(unaff_ESI + 8) + 0x420) + 0x14);
  props_getCurrentToken();
  stage_pushCurrentScope(unaff_ESI);
  if ((local_c == 8) && (local_8 == 0x1e)) {
    stage_advanceParser();
    stage_parseDeclaration(unaff_ESI);
    return 1;
  }
  props_restoreParserState(*(int *)(**(int **)(unaff_ESI + 8) + 0x420));
  *(undefined4 *)(*(int *)(**(int **)(unaff_ESI + 8) + 0x420) + 0x14) = uVar1;
  return 0;
}



// ============================================================
// Function: stage_compileRepeatBody (FUN_6805BB60)
// Address: 6805bb60
// Size: 231 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_compileRepeatBody(void)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar2;
  undefined3 extraout_var_02;
  void *unaff_ESI;
  int local_14 [2];
  int local_c;
  int local_8;
  
  stage_getParseState();
  props_getCurrentToken();
  bVar1 = props_isParserReady(*(int *)(**(int **)((int)unaff_ESI + 8) + 0x420));
  iVar2 = CONCAT31(extraout_var,bVar1);
  while( true ) {
    if (iVar2 != 0) {
      stage_emitPushLiteral((int)unaff_ESI,0x10);
      return 0;
    }
    stage_parseDeclaration((int)unaff_ESI);
    bVar1 = stage_parseAssignment((int)unaff_ESI,&local_c,(int *)0x44);
    if (CONCAT31(extraout_var_00,bVar1) == 0) {
      if ((local_c == 8) && (local_8 == 0x1e)) {
        return 1;
      }
    }
    else {
      bVar1 = stage_parseAssignment((int)unaff_ESI,local_14,(int *)0x31);
      if (CONCAT31(extraout_var_01,bVar1) != 0) {
        return 0;
      }
      stage_resolveSymbol((int)unaff_ESI,local_14);
    }
    stage_resolveSymbol((int)unaff_ESI,&local_c);
    iVar2 = stage_compileCommand(unaff_ESI);
    if (iVar2 == 0) {
      stage_emitPushLiteral((int)unaff_ESI,0x10);
    }
    if (*(int *)(**(int **)((int)unaff_ESI + 8) + 0x41c) != 0) break;
    stage_getParseState();
    props_getCurrentToken();
    bVar1 = props_isParserReady(*(int *)(**(int **)((int)unaff_ESI + 8) + 0x420));
    iVar2 = CONCAT31(extraout_var_02,bVar1);
  }
  return 0;
}



