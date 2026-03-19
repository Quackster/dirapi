// Module: stage
// Topic: Parser: expression compilation
// Address range: 0x68055D30 - 0x68056590
// Functions (6):
//   stage_compileBinaryExpr (FUN_68055D30)
//   stage_compileUnaryExpr (FUN_68055E90)
//   stage_tryCompileSpecialExpr (FUN_68055F10)
//   stage_compileExprOp (FUN_68055FA0)
//   stage_compileExprBlock (stage_compileExprBlock)
//   stage_compileExpression (stage_compileExpression)

// ============================================================
// Function: stage_compileBinaryExpr (FUN_68055d30)
// Address: 68055d30
// Size: 348 bytes
// Params: void * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileBinaryExpr(void *param_1,int param_2)
{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int iVar3;
  int local_c [2];
  
  iVar3 = param_2 + -0x20;
  iVar2 = iVar3;
  if (0 < iVar3) {
    do {
      stage_emitBranch((int)param_1,0);
      stage_emitBranch((int)param_1,0);
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  stage_compileHandler(param_1,stage_checkIsConstOrEnd);
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
    while( true ) {
      stage_parseCondition((int)param_1,local_c,&param_2);
      if (param_2 == 0x30) {
        stage_compileHandler(param_1,stage_checkIsConstOrEnd);
        if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
          return 0;
        }
        stage_parseCondition((int)param_1,local_c,&param_2);
      }
      else {
        stage_emitBranch((int)param_1,0);
      }
      if (param_2 != 0x3e) {
        stage_emitPushLiteral((int)param_1,0x12);
        return 0;
      }
      bVar1 = stage_parseCondition((int)param_1,local_c,&param_2);
      if ((CONCAT31(extraout_var,bVar1) == 0) || (iVar2 = param_2 + -0x20, 3 < iVar2)) break;
      if (iVar2 <= iVar3) {
        if (-1 < iVar2) {
          stage_emitPushLiteral((int)param_1,0x23);
          return 0;
        }
        break;
      }
      if (iVar3 + 1 < iVar2) {
        iVar3 = iVar2 - (iVar3 + 1);
        do {
          stage_emitBranch((int)param_1,0);
          stage_emitBranch((int)param_1,0);
          iVar3 = iVar3 + -1;
        } while (iVar3 != 0);
      }
      stage_compileHandler(param_1,stage_checkIsConstOrEnd);
      iVar3 = iVar2;
      if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
        return 0;
      }
    }
    stage_resolveSymbol((int)param_1,local_c);
    if (iVar3 < 3) {
      iVar3 = 3 - iVar3;
      do {
        stage_emitBranch((int)param_1,0);
        stage_emitBranch((int)param_1,0);
        iVar3 = iVar3 + -1;
      } while (iVar3 != 0);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_compileUnaryExpr (FUN_68055e90)
// Address: 68055e90
// Size: 128 bytes
// Params: int param_1, undefined * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_compileUnaryExpr(int param_1,undefined *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int local_c [2];
  
  bVar1 = stage_parseAssignment(param_1,local_c,(int *)0x3e);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    stage_resolveSymbol(param_1,local_c);
    return 0;
  }
  bVar1 = stage_parseAssignment(param_1,local_c,(int *)0x68);
  if (CONCAT31(extraout_var_00,bVar1) == 0) {
    stage_emitPushLiteral(param_1,3);
    return 0;
  }
  if ((code *)param_2 == stage_getCodegenState) {
    stage_compileHandler((void *)param_1,stage_getCodegenState);
    return 1;
  }
  stage_compileExpression((void *)param_1,param_2,0);
  return 1;
}



// ============================================================
// Function: stage_tryCompileSpecialExpr (FUN_68055f10)
// Address: 68055f10
// Size: 134 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_tryCompileSpecialExpr(int param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int *in_EAX;
  int unaff_ESI;
  int local_c;
  int local_8;
  
  if (((param_1 == 0x82) && (*in_EAX == 8)) &&
     ((iVar2 = in_EAX[1], iVar2 == 0x7c || (((iVar2 == 0x56 || (iVar2 == 0x7b)) || (iVar2 == 0x7d)))
      ))) {
    stage_pushCurrentScope(unaff_ESI);
    if ((local_c == 8) && (local_8 == 4)) {
      stage_emitReturnEx(1,param_2,1);
    }
    else {
      stage_emitPushLiteral(unaff_ESI,0x34);
    }
    puVar1 = (uint *)(**(int **)(**(int **)(unaff_ESI + 8) + 0x428) + 0x54);
    *puVar1 = *puVar1 | 0x8000;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_compileExprOp (FUN_68055fa0)
// Address: 68055fa0
// Size: 337 bytes
// Params: int param_1, undefined * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileExprOp(int param_1,undefined *param_2,uint param_3)
{
  int iVar1;
  uint uVar2;
  int local_c;
  int local_8;
  
  stage_pushCurrentScope(param_1);
  iVar1 = stage_tryCompileSpecialExpr(param_3,1);
  if (iVar1 == 0) {
    if ((local_c == 8) && (local_8 == 4)) {
      stage_emitReturnEx(0,1,1);
      return 0;
    }
    iVar1 = stage_isChunkOpSymbol();
    if (iVar1 != 0) {
      stage_resolveSymbol(param_1,&local_c);
      stage_emitInstruction(param_1,0x43,0,1);
      iVar1 = 0;
      uVar2 = props_resolveSymbol(param_1,param_3);
      stage_emitInstruction(param_1,(uint)*(byte *)(**(int **)(param_1 + 8) + 0x418),uVar2,iVar1);
      return 0;
    }
    iVar1 = stage_isCommandSymbol();
    if (iVar1 != 0) {
      iVar1 = stage_checkVarType(&local_c,param_1);
      if (iVar1 == 0) {
        iVar1 = (*(code *)param_2)(&local_c);
        if (iVar1 == 0) {
          uVar2 = 1;
          stage_resolveSymbol(param_1,&local_c);
          if ((code *)param_2 == stage_getCodegenState) {
            stage_compileHandler((void *)param_1,stage_getCodegenState);
          }
          else {
            stage_compileExpression((void *)param_1,param_2,0);
          }
          iVar1 = stage_isMultiArgSymbol();
          if (iVar1 != 0) {
            iVar1 = stage_compileUnaryExpr(param_1,param_2);
            if (iVar1 != 0) {
              uVar2 = 2;
            }
          }
          stage_emitInstruction(param_1,0x43,uVar2,1);
          iVar1 = -uVar2;
          uVar2 = props_resolveSymbol(param_1,param_3);
          stage_emitInstruction(param_1,(uint)*(byte *)(**(int **)(param_1 + 8) + 0x418),uVar2,iVar1);
          return 0;
        }
      }
    }
    stage_resolveSymbol(param_1,&local_c);
    stage_compileVarRef();
  }
  return 0;
}



// ============================================================
// Function: stage_compileExprBlock (FUN_68056100)
// Address: 68056100
// Size: 1156 bytes
// Params: uint param_1, undefined4 param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileExprBlock(uint param_1,undefined *param_2,int param_3,int param_4,int param_5)
{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  uVar1 = param_1;
LAB_68056111:
  do {
    stage_pushCurrentScope(uVar1);
    if (local_c != 8) {
LAB_68056563:
      if (param_3 != 0) {
        stage_emitPushLiteral(uVar1,0xd);
      }
      stage_resolveSymbol(uVar1,&local_c);
      return 0;
    }
    if (local_8 == 1) {
      stage_pushCurrentScope(uVar1);
      uVar2 = local_8;
      if ((local_c == 8) && (0x1c < (int)local_8)) {
        stage_pushCurrentScope(uVar1);
        if (local_c == 8) {
          if (local_8 == 4) {
            props_skipMatchingBlock(uVar1,*(int *)(**(int **)(uVar1 + 8) + 0x420),&local_14);
            if ((local_14 != 8) || (((local_10 != 1 && (local_10 != 4)) && (local_10 != 6)))) {
              stage_compileArgList((uint)(param_3 == 0),1,&param_1);
              iVar3 = -param_1;
              uVar2 = props_resolveSymbol(uVar1,uVar2);
              stage_emitInstruction(uVar1,0x67,uVar2,iVar3);
              return 0;
            }
            stage_compileArgList(1,1,&param_1);
            iVar3 = -param_1;
            uVar2 = props_resolveSymbol(uVar1,uVar2);
            stage_emitInstruction(uVar1,0x67,uVar2,iVar3);
            goto LAB_68056111;
          }
          if (local_8 == 6) {
            stage_emitBranchCond(uVar1,uVar2);
            stage_compileHandler((void *)(size_t)uVar1,lingo_noop);
            stage_pushCurrentScope(uVar1);
            if (local_c == 8) {
              if (local_8 == 7) {
                uVar2 = 3;
              }
              else {
                if (local_8 != 2) goto LAB_6805629c;
                stage_compileHandler((void *)(size_t)uVar1,lingo_noop);
                uVar2 = 4;
                stage_pushCurrentScope(uVar1);
                if ((local_c != 8) || (local_8 != 7)) {
                  stage_emitPushLiteral(uVar1,0x31);
                  return 0;
                }
              }
              stage_pushCurrentScope(uVar1);
              if (param_4 == 0) {
                if ((local_c != 8) || ((local_8 != 6 && (local_8 != 1)))) {
                  if ((param_3 != 0) &&
                     (((local_c == 8 && (local_8 == 0x15)) ||
                      ((param_5 != 0 && ((local_c == 8 && (local_8 == 0x30)))))))) {
                    stage_compileHandler((void *)(size_t)uVar1,param_2);
                    stage_emitInstruction(uVar1,0x42,uVar2 + 1,1);
                    iVar3 = -2 - uVar2;
                    uVar2 = props_resolveSymbol(uVar1,0xdb);
                    stage_emitInstruction(uVar1,0x67,uVar2,iVar3);
                    return 0;
                  }
                  stage_resolveSymbol(uVar1,&local_c);
                  stage_emitInstruction(uVar1,0x43,uVar2,1);
                  iVar3 = -uVar2;
                  uVar2 = props_resolveSymbol(uVar1,0xd4);
                  stage_emitInstruction(uVar1,0x67,uVar2,iVar3);
                  return 0;
                }
              }
              stage_resolveSymbol(uVar1,&local_c);
              stage_emitInstruction(uVar1,0x43,uVar2,1);
              iVar3 = -uVar2;
              uVar2 = props_resolveSymbol(uVar1,0x81);
              stage_emitInstruction(uVar1,0x67,uVar2,iVar3);
            }
            else {
LAB_6805629c:
              stage_emitPushLiteral(uVar1,0x31);
            }
            goto LAB_68056111;
          }
          if (local_8 == 1) {
            stage_pushCurrentScope(uVar1);
            if ((local_14 == 8) && (local_10 == 0xdd)) {
              stage_emitBranchCond(uVar1,uVar2);
              stage_emitInstruction(uVar1,0x43,2,1);
              iVar3 = -2;
              uVar2 = props_resolveSymbol(uVar1,0xdd);
              stage_emitInstruction(uVar1,0x67,uVar2,iVar3);
            }
            else {
              stage_resolveSymbol(uVar1,&local_14);
              stage_resolveSymbol(uVar1,&local_c);
              iVar3 = 0;
              uVar2 = props_resolveSymbol(uVar1,uVar2);
              stage_emitInstruction(uVar1,0x70,uVar2,iVar3);
            }
            goto LAB_68056111;
          }
        }
        if (param_3 != 0) {
          if (local_c == 8) {
            if ((local_8 == 1) || (local_8 == 6)) goto LAB_6805633b;
            if (local_8 == 0x15) goto LAB_680564e4;
          }
          if (((param_5 != 0) && (local_c == 8)) && (local_8 == 0x30)) {
LAB_680564e4:
            stage_compileHandler((void *)(size_t)uVar1,param_2);
            iVar3 = -2;
            uVar2 = props_resolveSymbol(uVar1,uVar2);
            stage_emitInstruction(uVar1,0x62,uVar2,iVar3);
            return 0;
          }
LAB_68056509:
          stage_emitPushLiteral(uVar1,0xd);
          return 0;
        }
LAB_6805633b:
        stage_resolveSymbol(uVar1,&local_c);
        iVar3 = 0;
        uVar2 = props_resolveSymbol(uVar1,uVar2);
        stage_emitInstruction(uVar1,0x61,uVar2,iVar3);
      }
      else {
        stage_emitPushLiteral(uVar1,2);
      }
      goto LAB_68056111;
    }
    if (local_8 != 6) goto LAB_68056563;
    stage_compileHandler((void *)(size_t)uVar1,lingo_noop);
    stage_pushCurrentScope(uVar1);
    if ((local_c != 8) || (local_8 != 7)) {
      stage_emitPushLiteral(uVar1,0x31);
    }
    stage_pushCurrentScope(uVar1);
    if (param_3 != 0) {
      if (local_c == 8) {
        if ((local_8 == 1) || (local_8 == 6)) goto LAB_680563c6;
        if (local_8 == 0x15) goto LAB_6805652e;
      }
      if (((param_5 != 0) && (local_c == 8)) && (local_8 == 0x30)) {
LAB_6805652e:
        stage_compileHandler((void *)(size_t)uVar1,param_2);
        stage_emitInstruction(uVar1,0x42,3,1);
        iVar3 = -4;
        uVar2 = props_resolveSymbol(uVar1,0xda);
        stage_emitInstruction(uVar1,0x67,uVar2,iVar3);
        return 0;
      }
      goto LAB_68056509;
    }
LAB_680563c6:
    stage_resolveSymbol(uVar1,&local_c);
    stage_emitInstruction(uVar1,0x43,2,1);
    iVar3 = -2;
    uVar2 = props_resolveSymbol(uVar1,0xd3);
    stage_emitInstruction(uVar1,0x67,uVar2,iVar3);
  } while( true );
}



// ============================================================
// Function: stage_compileExpression (FUN_68056590)
// Address: 68056590
// Size: 145 bytes
// Params: void * param_1, undefined * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileExpression(void *param_1,undefined *param_2,int param_3)
{
  uint local_c;
  uint local_8;
  
  stage_pushCurrentScope((int)param_1);
  switch(local_c) {
  case 1:
  case 0x40:
  case 0x43:
    stage_compileBlock(param_1,&local_c);
    stage_compileExprBlock((uint)param_1,param_2,0,param_3,0);
    return 0;
  default:
    stage_compileBlock(param_1,&local_c);
    return 0;
  case 8:
    break;
  }
  if ((int)local_8 < 0x2f) {
    stage_compileBuiltinOp((int)param_1,param_2,local_8);
  }
  else {
    stage_compileExprOp((int)param_1,param_2,local_8);
  }
  stage_compileExprBlock((uint)param_1,param_2,0,param_3,0);
  return 0;
}



