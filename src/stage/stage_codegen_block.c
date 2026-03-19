// Module: stage
// Topic: Block statement compilation
// Address range: 0x6805C4D0 - 0x6805CD00
// Functions (9):
//   stage_compileBlockCase (FUN_6805C4D0)
//   stage_compileBlockExpr (FUN_6805C530)
//   stage_emitLoopBlock (FUN_6805C710)
//   stage_isRepeatToken (FUN_6805C750)
//   stage_compileRepeatBlock (FUN_6805C770)
//   stage_isCaseToken (FUN_6805C940)
//   stage_compileCaseBlock (FUN_6805C960)
//   stage_emitCodeBlock (FUN_6805CCD0)
//   stage_registerBlockHandlers (FUN_6805CD00)

// ============================================================
// Function: stage_compileBlockCase (FUN_6805C4D0)
// Address: 6805c4d0
// Size: 87 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileBlockCase(int param_1)
{
  undefined4 local_c;
  undefined4 local_8;
  
  stage_pushCurrentScope(param_1);
  if ((local_c == 8) && (0x2e < local_8)) {
    if (local_8 == 0x42) {
      stage_compileRepeatWhile();
      return 0;
    }
    if (local_8 == 0x45) {
      stage_compileRepeatControl();
      return 0;
    }
  }
  stage_emitPushLiteral(param_1,0xb);
  return 0;
}



// ============================================================
// Function: stage_compileBlockExpr (FUN_6805C530)
// Address: 6805c530
// Size: 465 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileBlockExpr(void *param_1)
{
  void *pvVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint *puVar3;
  int local_28;
  int local_24;
  int local_20;
  uint local_1c;
  int local_18;
  int *local_14;
  uint local_10;
  char local_c [4];
  uint local_8;
  
  pvVar1 = param_1;
  stage_pushCurrentScope((int)param_1);
  if (local_20 != 8) {
LAB_6805c6f2:
    stage_emitPushLiteral((int)pvVar1,0x22);
    return 0;
  }
  if ((int)local_1c < 0x2f) {
    if (local_1c != 0x1f) {
      if (local_1c == 4) {
        stage_resolveSymbol((int)pvVar1,&local_20);
        stage_compileCommand(pvVar1);
        return 0;
      }
      goto LAB_6805c6f2;
    }
    bVar2 = stage_parseCondition((int)pvVar1,&local_18,(int *)&param_1);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      props_releaseValue(pvVar1,(byte)local_18,local_14);
      stage_emitPushLiteral((int)pvVar1,0x13);
      return 0;
    }
    stage_pushCurrentScope((int)pvVar1);
    stage_resolveSymbol((int)pvVar1,&local_28);
    if ((local_28 != 8) || (local_24 != 6)) {
      puVar3 = score_lookupProperty(*(int **)(**(int **)((int)pvVar1 + 8) + 0x10),(uint)param_1,0,&local_10)
      ;
      if (puVar3 == (uint *)0x0) {
        stage_compilePropertyOp(pvVar1,lingo_noop,(uint)param_1,1);
        return 0;
      }
      stage_compilePropertyCmd(pvVar1,lingo_noop,(uint)param_1,(uint *)puVar3[1],1);
      return 0;
    }
    stage_resolveSymbol((int)pvVar1,&local_18);
    stage_compileBuiltinOp((int)pvVar1,lingo_noop,local_1c);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
      return 0;
    }
  }
  else {
    stage_declareVariable(pvVar1,local_1c,(undefined4 *)local_c,&local_8,1);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
      return 0;
    }
    stage_pushCurrentScope((int)pvVar1);
    if ((local_18 == 8) && ((local_14 == (int *)0x30 || (local_14 == (int *)0x15)))) {
      stage_compileHandler(pvVar1,lingo_noop);
      if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
        return 0;
      }
      stage_emitInstruction((int)pvVar1,(uint)(byte)(local_c[0] + 0x4d),local_8,-1);
      return 0;
    }
    stage_resolveSymbol((int)pvVar1,&local_18);
    stage_compileExprOp((int)pvVar1,lingo_noop,local_1c);
  }
  stage_compileExprBlock((uint)pvVar1,lingo_noop,1,0,1);
  return 0;
}



// ============================================================
// Function: stage_emitLoopBlock (FUN_6805C710)
// Address: 6805c710
// Size: 52 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitLoopBlock(int param_1)
{
  uint uVar1;
  
  uVar1 = stage_compileParameterList(param_1,*(int **)(**(int **)(param_1 + 8) + 0x494),
                       *(uint *)(**(int **)(param_1 + 8) + 0x470),1,0);
  *(uint *)(**(int **)(param_1 + 8) + 0x470) = uVar1;
  return 0;
}



// ============================================================
// Function: stage_isRepeatToken (FUN_6805C750)
// Address: 6805c750
// Size: 32 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_isRepeatToken(int *param_1)

{
  if ((*param_1 == 8) && (param_1[1] == 0x30)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_compileRepeatBlock (FUN_6805C770)
// Address: 6805c770
// Size: 454 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileRepeatBlock(void *param_1)
{
  undefined1 uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  bool bVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int iVar5;
  undefined3 extraout_var_02;
  int local_14 [2];
  int local_c;
  int local_8;
  
  stage_compileHandler(param_1,stage_isRepeatToken);
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
    return 0;
  }
  stage_emitOpcode((int)param_1,0x1c,2);
  uVar1 = *(undefined1 *)(**(int **)((int)param_1 + 8) + 0x418);
  *(undefined1 *)(**(int **)((int)param_1 + 8) + 0x418) = 99;
  stage_pushCurrentScope((int)param_1);
  if (local_c == 8) {
    if (local_8 == 0x30) {
      stage_compileCommand(param_1);
      if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
LAB_6805c918:
        stage_emitOpcode((int)param_1,0x1d,-3);
      }
      goto LAB_6805c922;
    }
  }
  else if (local_c == 0) {
    iVar5 = **(int **)((int)param_1 + 8);
    uVar2 = *(undefined4 *)(iVar5 + 0x4bc);
    uVar3 = *(undefined4 *)(iVar5 + 0x4c0);
    *(undefined4 *)(iVar5 + 0x4c0) = 1;
    *(undefined4 *)(**(int **)((int)param_1 + 8) + 0x4bc) = 0;
    stage_getParseState();
    props_getCurrentToken();
    bVar4 = props_isParserReady(*(int *)(**(int **)((int)param_1 + 8) + 0x420));
    iVar5 = CONCAT31(extraout_var,bVar4);
    while (iVar5 == 0) {
      stage_parseDeclaration((int)param_1);
      bVar4 = stage_parseAssignment((int)param_1,&local_c,(int *)0x44);
      if (CONCAT31(extraout_var_00,bVar4) != 0) {
        bVar4 = stage_parseAssignment((int)param_1,local_14,(int *)0x5a);
        if (CONCAT31(extraout_var_01,bVar4) != 0) {
          stage_emitLoadConst((int)param_1,*(uint *)(**(int **)((int)param_1 + 8) + 0x4bc));
          iVar5 = **(int **)((int)param_1 + 8);
          *(undefined4 *)(iVar5 + 0x4bc) = uVar2;
          *(undefined4 *)(iVar5 + 0x4c0) = uVar3;
          goto LAB_6805c918;
        }
        stage_resolveSymbol((int)param_1,local_14);
      }
      stage_resolveSymbol((int)param_1,&local_c);
      iVar5 = stage_compileCommand(param_1);
      if (iVar5 == 0) {
        stage_emitPushLiteral((int)param_1,0x29);
      }
      if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) goto LAB_6805c922;
      stage_getParseState();
      props_getCurrentToken();
      bVar4 = props_isParserReady(*(int *)(**(int **)((int)param_1 + 8) + 0x420));
      iVar5 = CONCAT31(extraout_var_02,bVar4);
    }
    stage_emitPushLiteral((int)param_1,0x29);
    goto LAB_6805c922;
  }
  stage_emitPushLiteral((int)param_1,0x27);
LAB_6805c922:
  *(undefined1 *)(**(int **)((int)param_1 + 8) + 0x418) = uVar1;
  return 0;
}



// ============================================================
// Function: stage_isCaseToken (FUN_6805C940)
// Address: 6805c940
// Size: 32 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_isCaseToken(int *param_1)

{
  if ((*param_1 == 8) && (param_1[1] == 10)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_compileCaseBlock (FUN_6805C960)
// Address: 6805c960
// Size: 875 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileCaseBlock(void *param_1)
{
  int *piVar1;
  void *pvVar2;
  bool bVar3;
  undefined3 extraout_var;
  int iVar4;
  undefined3 extraout_var_00;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  pvVar2 = param_1;
  stage_compileHandler(param_1,stage_checkIsEndToken);
  if (*(int *)(**(int **)((int)pvVar2 + 8) + 0x41c) == 0) {
    stage_pushCurrentScope((int)pvVar2);
    if ((local_18 == 8) && (local_14 == 0x3e)) {
      param_1 = (void *)0x0;
      local_c = 0;
      local_10 = 0;
      piVar1 = (int *)(**(int **)((int)pvVar2 + 8) + 0x4b4);
      *piVar1 = *piVar1 + 1;
      local_8 = 0;
      stage_getParseState();
      props_getCurrentToken();
      bVar3 = props_isParserReady(*(int *)(**(int **)((int)pvVar2 + 8) + 0x420));
      iVar4 = CONCAT31(extraout_var,bVar3);
      do {
        if (iVar4 != 0) {
LAB_6805cc41:
          iVar4 = 0x2e;
LAB_6805cc94:
          stage_emitPushLiteral((int)pvVar2,iVar4);
LAB_6805cc9a:
          piVar1 = (int *)(**(int **)((int)pvVar2 + 8) + 0x4b4);
          *piVar1 = *piVar1 + -1;
          return 0;
        }
        stage_parseDeclaration((int)pvVar2);
        stage_pushCurrentScope((int)pvVar2);
        if (local_18 != 0) {
          if (local_18 == 8) {
            if (local_14 == 4) {
              props_skipMatchingBlock(pvVar2,*(int *)(**(int **)((int)pvVar2 + 8) + 0x420),&local_20);
              if ((local_20 != 8) || ((local_1c != 10 && (local_1c != 3)))) goto LAB_6805ca6a;
              stage_resolveSymbol((int)pvVar2,&local_18);
            }
            else {
              if (((local_14 != 0xb) && (local_14 != 0xc)) && (local_14 != 0x24)) goto LAB_6805ca6a;
              stage_resolveSymbol((int)pvVar2,&local_18);
            }
LAB_6805cac2:
            if (local_8 != 0) goto LAB_6805cc41;
            if (param_1 != (void *)0x0) {
              stage_emitJumpTarget((int)pvVar2,0x53,(int *)&local_10);
              stage_emitParseOffset((int)pvVar2);
              stage_emitLoadConst((int)pvVar2,(uint)param_1);
              param_1 = (void *)0x0;
            }
            while( true ) {
              stage_emitInstruction((int)pvVar2,100,0,1);
              stage_compileHandler(pvVar2,stage_isCaseToken);
              if (*(int *)(**(int **)((int)pvVar2 + 8) + 0x41c) != 0) {
                return 0;
              }
              stage_pushCurrentScope((int)pvVar2);
              if (local_18 != 8) goto LAB_6805cc45;
              if (local_14 != 3) break;
              stage_emitOpcode((int)pvVar2,0xe,-1);
              stage_emitJumpTarget((int)pvVar2,0x55,(int *)&local_c);
            }
            if (local_14 != 10) {
LAB_6805cc45:
              iVar4 = 0x30;
              goto LAB_6805cc94;
            }
            stage_emitOpcode((int)pvVar2,0xf,-1);
            stage_emitJumpTarget((int)pvVar2,0x55,(int *)&param_1);
            stage_emitLoadConst((int)pvVar2,local_c);
            local_c = 0;
          }
          else {
LAB_6805ca6a:
            stage_pushCurrentScope((int)pvVar2);
            if ((local_20 == 8) &&
               (((local_1c == 10 || (local_1c == 3)) &&
                ((local_18 != 8 || ((local_14 != 0x62 && (local_14 != 4)))))))) {
              bVar3 = true;
            }
            else {
              bVar3 = false;
            }
            stage_resolveSymbol((int)pvVar2,&local_20);
            if (bVar3) {
              stage_resolveSymbol((int)pvVar2,&local_18);
              goto LAB_6805cac2;
            }
            if (local_18 == 8) {
              if (local_14 != 0x62) {
                if (local_14 != 0x44) goto LAB_6805cbd5;
                stage_pushCurrentScope((int)pvVar2);
                if ((local_18 == 8) && (local_14 == 0x61)) {
                  stage_emitLoadConst((int)pvVar2,(uint)param_1);
                  stage_emitLoadConst((int)pvVar2,local_10);
                  stage_emitInstruction((int)pvVar2,0x65,1,-1);
                  piVar1 = (int *)(**(int **)((int)pvVar2 + 8) + 0x4b4);
                  *piVar1 = *piVar1 + -1;
                  return 0;
                }
                goto LAB_6805cc41;
              }
              if (local_8 != 0) goto LAB_6805cc41;
              stage_emitJumpTarget((int)pvVar2,0x53,(int *)&local_10);
              stage_emitParseOffset((int)pvVar2);
              stage_emitLoadConst((int)pvVar2,(uint)param_1);
              param_1 = (void *)0x0;
              local_8 = 1;
              stage_pushCurrentScope((int)pvVar2);
              if ((local_18 != 8) || (local_14 != 10)) goto LAB_6805cbe3;
            }
            else {
LAB_6805cbd5:
              if ((param_1 == (void *)0x0) && (local_8 == 0)) {
                iVar4 = 0x2f;
                goto LAB_6805cc94;
              }
LAB_6805cbe3:
              stage_resolveSymbol((int)pvVar2,&local_18);
            }
          }
          iVar4 = stage_compileCommand(pvVar2);
          if (iVar4 == 0) {
            stage_emitPushLiteral((int)pvVar2,0x2e);
          }
          if (*(int *)(**(int **)((int)pvVar2 + 8) + 0x41c) != 0) goto LAB_6805cc9a;
        }
        stage_getParseState();
        props_getCurrentToken();
        bVar3 = props_isParserReady(*(int *)(**(int **)((int)pvVar2 + 8) + 0x420));
        iVar4 = CONCAT31(extraout_var_00,bVar3);
      } while( true );
    }
    stage_resolveSymbol((int)pvVar2,&local_18);
    stage_emitReturn();
  }
  return 0;
}



// ============================================================
// Function: stage_emitCodeBlock (FUN_6805ccd0)
// Address: 6805ccd0
// Size: 41 bytes
// Params: int param_1, uint param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitCodeBlock(int param_1,uint param_2,uint param_3)
{
  uint *puVar1;
  
  puVar1 = score_lookupProperty(*(int **)(param_1 + 8),param_2,1,&param_2);
  *puVar1 = 4;
  puVar1[1] = param_3;
  return 0;
}



// ============================================================
// Function: stage_registerBlockHandlers (FUN_6805CD00)
// Address: 6805cd00
// Size: 201 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_registerBlockHandlers(int param_1)
{
  stage_emitCodeBlock(param_1,99,0);
  stage_emitCodeBlock(param_1,0x44,0);
  stage_emitCodeBlock(param_1,100,0x6805c710);
  stage_emitCodeBlock(param_1,0x65,0x6805c530);
  stage_emitCodeBlock(param_1,0x43,0x6805c4d0);
  stage_emitCodeBlock(param_1,0x31,0x6805bc50);
  stage_emitCodeBlock(param_1,0x1e,0x6805bac0);
  stage_emitCodeBlock(param_1,0x2f,0x6805b7b0);
  stage_emitCodeBlock(param_1,0x66,0x6805b6d0);
  stage_emitCodeBlock(param_1,0x67,0x68055750);
  stage_emitCodeBlock(param_1,0x57,0x6805b3e0);
  stage_emitCodeBlock(param_1,0x5a,0x6805c770);
  stage_emitCodeBlock(param_1,0x60,0x6805c3c0);
  stage_emitCodeBlock(param_1,0x61,0x6805c960);
  stage_emitCodeBlock(param_1,0x27,0x6805c380);
  return 0;
}



