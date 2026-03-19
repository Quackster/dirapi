// Module: stage
// Topic: If/then/else control flow compilation
// Address range: 0x6805BC50 - 0x6805C450
// Functions (11):
//   stage_compileIfThenElse (FUN_6805BC50)
//   stage_saveLoopState (FUN_6805BE00)
//   stage_parseRangeAssignment (FUN_6805BE80)
//   stage_compileLoopConditions (FUN_6805BED0)
//   stage_restoreLoopState (FUN_6805BF50)
//   stage_compileRepeatWithIn (FUN_6805BFC0)
//   stage_isRangeKeyword (FUN_6805C130)
//   stage_compileRepeatControl (FUN_6805C160)
//   stage_emitCleanupReturn (FUN_6805C380)
//   stage_compileNextRepeat (FUN_6805C3C0)
//   stage_compileRepeatWhile (FUN_6805C450)

// ============================================================
// Function: stage_compileIfThenElse (FUN_6805BC50)
// Address: 6805bc50
// Size: 429 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileIfThenElse(void *param_1)
{
  int local_18;
  void *pvVar1;
  int iVar2;
  int local_10;
  int local_c;
  uint local_8;
  
  pvVar1 = param_1;
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
    local_8 = 0;
    param_1 = (void *)0x0;
    stage_compileHandler(pvVar1,lingo_noop);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) == 0) {
      while( true ) {
        stage_emitJumpTarget((int)pvVar1,0x55,(int *)&param_1);
        stage_pushCurrentScope((int)pvVar1);
        if ((local_10 != 8) || (local_c != 0x1d)) break;
        stage_pushCurrentScope((int)pvVar1);
        if (local_10 == 0) {
          iVar2 = stage_compileRepeatBody();
          if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
            return 0;
          }
        }
        else {
          stage_resolveSymbol((int)pvVar1,&local_10);
          iVar2 = stage_compileCommand(pvVar1);
          if (iVar2 == 0) {
            stage_emitPushLiteral((int)pvVar1,0x10);
            return 0;
          }
          if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
            return 0;
          }
          iVar2 = stage_tryParseRepeatBlock();
        }
        if (iVar2 == 0) {
          stage_emitLoadConst((int)pvVar1,(uint)param_1);
LAB_6805bd8c:
          stage_emitLoadConst((int)pvVar1,local_8);
          return 0;
        }
        stage_emitJumpTarget((int)pvVar1,0x53,(int *)&local_8);
        stage_emitParseOffset((int)pvVar1);
        stage_emitLoadConst((int)pvVar1,(uint)param_1);
        stage_pushCurrentScope((int)pvVar1);
        if (local_10 == 0) {
          iVar2 = stage_compileRepeatBody();
          if (iVar2 != 0) {
            stage_emitPushLiteral((int)pvVar1,0x11);
            return 0;
          }
          stage_emitLoadConst((int)pvVar1,local_8);
          return 0;
        }
        if ((local_10 != 8) || (local_c != 0x31)) {
          stage_resolveSymbol((int)pvVar1,&local_10);
          iVar2 = stage_compileCommand(pvVar1);
          if (iVar2 == 0) {
            stage_emitPushLiteral((int)pvVar1,0x10);
            return 0;
          }
          goto LAB_6805bd8c;
        }
        param_1 = (void *)0x0;
        stage_compileHandler(pvVar1,lingo_noop);
        if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
          return 0;
        }
      }
      stage_emitPushLiteral((int)pvVar1,0xf);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_saveLoopState (FUN_6805BE00)
// Address: 6805be00
// Size: 124 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_saveLoopState(int param_1,undefined4 *param_2)
{
  int iVar1;
  
  iVar1 = **(int **)(param_1 + 8);
  *param_2 = *(undefined4 *)(iVar1 + 0x4a8);
  param_2[1] = *(undefined4 *)(iVar1 + 0x4ac);
  param_2[2] = *(undefined4 *)(iVar1 + 0x4b0);
  param_2[3] = *(undefined4 *)(iVar1 + 0x4b4);
  param_2[4] = *(undefined4 *)(iVar1 + 0x4b8);
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4a8) =
       *(undefined4 *)(**(int **)(**(int **)(param_1 + 8) + 0x498) + 0x10);
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4ac) = 0;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4b0) = 0;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4b4) = 0;
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4b8) = 1;
  return 0;
}



// ============================================================
// Function: stage_parseRangeAssignment (FUN_6805BE80)
// Address: 6805be80
// Size: 73 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_parseRangeAssignment(void)

{
  bool bVar1;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int unaff_ESI;
  int local_14 [2];
  int local_c [2];
  
  bVar1 = stage_parseAssignment(unaff_ESI,local_14,(int *)0x44);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    bVar1 = stage_parseAssignment(unaff_ESI,local_c,(int *)0x43);
    if (CONCAT31(extraout_var_00,bVar1) != 0) {
      return 1;
    }
    stage_resolveSymbol(unaff_ESI,local_c);
  }
  stage_resolveSymbol(unaff_ESI,local_14);
  return 0;
}



// ============================================================
// Function: stage_compileLoopConditions (FUN_6805BED0)
// Address: 6805bed0
// Size: 116 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileLoopConditions(void)
{
  bool bVar1;
  void *in_EAX;
  undefined3 extraout_var;
  int iVar2;
  undefined3 extraout_var_00;
  
  stage_getParseState();
  props_getCurrentToken();
  bVar1 = props_isParserReady(*(int *)(**(int **)((int)in_EAX + 8) + 0x420));
  iVar2 = CONCAT31(extraout_var,bVar1);
  while (iVar2 == 0) {
    iVar2 = stage_parseRangeAssignment();
    if (iVar2 != 0) {
      return 0;
    }
    iVar2 = stage_compileStatement(in_EAX);
    if (iVar2 == 0) break;
    props_getCurrentToken();
    bVar1 = props_isParserReady(*(int *)(**(int **)((int)in_EAX + 8) + 0x420));
    iVar2 = CONCAT31(extraout_var_00,bVar1);
  }
  stage_emitPushLiteral((int)in_EAX,0xc);
  return 0;
}



// ============================================================
// Function: stage_restoreLoopState (FUN_6805BF50)
// Address: 6805bf50
// Size: 101 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_restoreLoopState(void)
{
  int iVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  
  stage_emitInstruction(unaff_EDI,0x54,
               *(int *)(**(int **)(**(int **)(unaff_EDI + 8) + 0x498) + 0x10) -
               *(int *)(**(int **)(unaff_EDI + 8) + 0x4a8),0);
  stage_emitLoadConst(unaff_EDI,*(uint *)(**(int **)(unaff_EDI + 8) + 0x4ac));
  iVar1 = **(int **)(unaff_EDI + 8);
  *(undefined4 *)(iVar1 + 0x4a8) = *unaff_ESI;
  *(undefined4 *)(iVar1 + 0x4ac) = unaff_ESI[1];
  *(undefined4 *)(iVar1 + 0x4b0) = unaff_ESI[2];
  *(undefined4 *)(iVar1 + 0x4b4) = unaff_ESI[3];
  *(undefined4 *)(iVar1 + 0x4b8) = unaff_ESI[4];
  return 0;
}



// ============================================================
// Function: stage_compileRepeatWithIn (FUN_6805BFC0)
// Address: 6805bfc0
// Size: 359 bytes
// Params: char param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileRepeatWithIn(char param_1,uint param_2)
{
  void *in_EAX;
  uint uVar1;
  int iVar2;
  undefined4 local_18 [5];
  
  stage_compileHandler(in_EAX,lingo_noop);
  if (*(int *)(**(int **)((int)in_EAX + 8) + 0x41c) == 0) {
    stage_emitInstruction((int)in_EAX,100,0,1);
    stage_emitInstruction((int)in_EAX,0x43,1,1);
    iVar2 = -1;
    uVar1 = props_resolveSymbol((int)in_EAX,0xdd);
    stage_emitInstruction((int)in_EAX,(uint)*(byte *)(**(int **)((int)in_EAX + 8) + 0x418),uVar1,iVar2);
    stage_emitInstruction((int)in_EAX,0x41,1,1);
    stage_saveLoopState((int)in_EAX,local_18);
    stage_emitInstruction((int)in_EAX,100,0,1);
    stage_emitInstruction((int)in_EAX,100,2,1);
    stage_emitOpcode((int)in_EAX,0xd,-1);
    stage_emitJumpTarget((int)in_EAX,0x55,(int *)(**(int **)((int)in_EAX + 8) + 0x4ac));
    stage_emitInstruction((int)in_EAX,100,2,1);
    stage_emitInstruction((int)in_EAX,100,1,1);
    stage_emitInstruction((int)in_EAX,0x43,2,1);
    iVar2 = -2;
    uVar1 = props_resolveSymbol((int)in_EAX,0xd3);
    stage_emitInstruction((int)in_EAX,(uint)*(byte *)(**(int **)((int)in_EAX + 8) + 0x418),uVar1,iVar2);
    stage_emitInstruction((int)in_EAX,(uint)(byte)(param_1 + 0x4d),param_2,-1);
    stage_compileLoopConditions();
    if (*(int *)(**(int **)((int)in_EAX + 8) + 0x41c) == 0) {
      stage_parseDeclaration((int)in_EAX);
      stage_emitLoadConst((int)in_EAX,*(uint *)(**(int **)((int)in_EAX + 8) + 0x4b0));
      stage_emitInstruction((int)in_EAX,0x41,1,1);
      stage_emitOpcode((int)in_EAX,5,-1);
      stage_restoreLoopState();
      stage_emitInstruction((int)in_EAX,0x65,3,-3);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_isRangeKeyword (FUN_6805C130)
// Address: 6805c130
// Size: 39 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_isRangeKeyword(int *param_1)

{
  if ((*param_1 == 8) && ((param_1[1] == 0x30 || (param_1[1] == 0x5e)))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_compileRepeatControl (FUN_6805C160)
// Address: 6805c160
// Size: 538 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileRepeatControl(void)
{
  bool bVar1;
  void *in_EAX;
  undefined4 uVar2;
  int iVar3;
  undefined4 local_28 [5];
  int local_14;
  int local_10;
  char local_c [4];
  uint local_8;
  
  bVar1 = false;
  stage_pushCurrentScope((int)in_EAX);
  if ((local_14 == 8) && (0x2e < local_10)) {
    stage_declareVariable(in_EAX,local_10,(undefined4 *)local_c,&local_8,1);
    if (*(int *)(**(int **)((int)in_EAX + 8) + 0x41c) == 0) {
      stage_pushCurrentScope((int)in_EAX);
      if (local_14 == 8) {
        if (local_10 == 0x15) {
          stage_compileHandler(in_EAX,stage_isRangeKeyword);
          if (*(int *)(**(int **)((int)in_EAX + 8) + 0x41c) != 0) {
            return 0;
          }
          stage_emitInstruction((int)in_EAX,(uint)(byte)(local_c[0] + 0x4d),local_8,-1);
          stage_pushCurrentScope((int)in_EAX);
          if (local_14 == 8) {
            if (local_10 != 0x30) {
              if (((local_10 != 0x5e) || (stage_pushCurrentScope((int)in_EAX), local_14 != 8)) ||
                 (local_10 != 0x30)) goto LAB_6805c332;
              bVar1 = true;
            }
            stage_saveLoopState((int)in_EAX,local_28);
            stage_emitInstruction((int)in_EAX,(uint)(byte)(local_c[0] + 0x47),local_8,1);
            stage_compileHandler(in_EAX,lingo_noop);
            if (*(int *)(**(int **)((int)in_EAX + 8) + 0x41c) != 0) {
              return 0;
            }
            if (bVar1) {
              uVar2 = 0x11;
            }
            else {
              uVar2 = 0xd;
            }
            stage_emitOpcode((int)in_EAX,uVar2,-1);
            stage_emitJumpTarget((int)in_EAX,0x55,(int *)(**(int **)((int)in_EAX + 8) + 0x4ac));
            stage_compileLoopConditions();
            if (*(int *)(**(int **)((int)in_EAX + 8) + 0x41c) != 0) {
              return 0;
            }
            stage_parseDeclaration((int)in_EAX);
            stage_emitLoadConst((int)in_EAX,*(uint *)(**(int **)((int)in_EAX + 8) + 0x4b0));
            if (bVar1) {
              iVar3 = -1;
            }
            else {
              iVar3 = 1;
            }
            stage_emitBranch((int)in_EAX,iVar3);
            stage_emitInstruction((int)in_EAX,(uint)(byte)(local_c[0] + 0x47),local_8,1);
            stage_emitOpcode((int)in_EAX,5,-1);
            stage_emitInstruction((int)in_EAX,(uint)(byte)(local_c[0] + 0x4d),local_8,-1);
            stage_restoreLoopState();
            return 0;
          }
LAB_6805c332:
          stage_emitPushLiteral((int)in_EAX,0xe);
          return 0;
        }
        if (local_10 == 0x5f) {
          stage_compileRepeatWithIn(local_c[0],local_8);
          return 0;
        }
      }
      stage_emitPushLiteral((int)in_EAX,0xd);
      return 0;
    }
  }
  else {
    stage_emitPushLiteral((int)in_EAX,3);
  }
  return 0;
}



// ============================================================
// Function: stage_emitCleanupReturn (FUN_6805C380)
// Address: 6805c380
// Size: 54 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitCleanupReturn(int param_1)
{
  if (0 < *(int *)(**(int **)(param_1 + 8) + 0x4b4)) {
    stage_emitInstruction(param_1,0x65,(int)*(short *)(**(int **)(param_1 + 8) + 0x4b4),0);
  }
  stage_emitReturn();
  return 0;
}



// ============================================================
// Function: stage_compileNextRepeat (FUN_6805C3C0)
// Address: 6805c3c0
// Size: 142 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileNextRepeat(int param_1)
{
  int iVar1;
  int local_c;
  int local_8;
  
  stage_pushCurrentScope(param_1);
  if ((local_c == 8) && (local_8 == 0x43)) {
    iVar1 = **(int **)(param_1 + 8);
    if (*(int *)(iVar1 + 0x4b8) == 0) {
      stage_emitPushLiteral(param_1,0x18);
      return 0;
    }
    if (0 < *(int *)(iVar1 + 0x4b4)) {
      stage_emitInstruction(param_1,0x65,(int)*(short *)(iVar1 + 0x4b4),0);
    }
    stage_emitJumpTarget(param_1,0x53,(int *)(**(int **)(param_1 + 8) + 0x4b0));
    return 0;
  }
  stage_resolveSymbol(param_1,&local_c);
  stage_emitReturn();
  return 0;
}



// ============================================================
// Function: stage_compileRepeatWhile (FUN_6805C450)
// Address: 6805c450
// Size: 118 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileRepeatWhile(void)
{
  void *in_EAX;
  undefined4 local_18 [5];
  
  stage_saveLoopState((int)in_EAX,local_18);
  stage_compileHandler(in_EAX,lingo_noop);
  if (*(int *)(**(int **)((int)in_EAX + 8) + 0x41c) == 0) {
    stage_emitJumpTarget((int)in_EAX,0x55,(int *)(**(int **)((int)in_EAX + 8) + 0x4ac));
    stage_compileLoopConditions();
    if (*(int *)(**(int **)((int)in_EAX + 8) + 0x41c) == 0) {
      stage_parseDeclaration((int)in_EAX);
      stage_emitLoadConst((int)in_EAX,*(uint *)(**(int **)((int)in_EAX + 8) + 0x4b0));
      stage_restoreLoopState();
    }
  }
  return 0;
}



