// Module: stage
// Topic: Parser: command compilation
// Address range: 0x68056680 - 0x68056D50
// Functions (6):
//   stage_tryCompileAssignment (FUN_68056680)
//   stage_compilePropertyOp (FUN_680567A0)
//   stage_tryCompileBinaryOp (FUN_68056880)
//   stage_compilePropertyCmd (FUN_680568B0)
//   stage_compileBuiltinOp (FUN_68056C90)
//   stage_compileCommand (FUN_68056D50)

// ============================================================
// Function: stage_tryCompileAssignment (FUN_68056680)
// Address: 68056680
// Size: 273 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_tryCompileAssignment(void)

{
  void *in_EAX;
  int iVar1;
  int extraout_ECX;
  int extraout_EDX;
  int unaff_EDI;
  int local_14;
  int local_10;
  char local_c [4];
  uint local_8;
  
  stage_pushCurrentScope((int)in_EAX);
  if ((local_14 == 8) && (local_10 == 0x15)) {
    stage_declareVariable(in_EAX,*(undefined4 *)(unaff_EDI + 4),(undefined4 *)local_c,&local_8,1);
    stage_compileHandler(in_EAX,lingo_noop);
    if (*(int *)(**(int **)((int)in_EAX + 8) + 0x41c) == 0) {
      stage_emitInstruction((int)in_EAX,(uint)(byte)(local_c[0] + 0x4d),local_8,-1);
    }
    return true;
  }
  iVar1 = stage_tryCompileSpecialExpr(*(int *)(unaff_EDI + 4),0);
  if (iVar1 != 0) {
    return *(int *)(**(int **)((int)in_EAX + 8) + 0x41c) == 0;
  }
  stage_resolveSymbol((int)in_EAX,&local_14);
  iVar1 = stage_resolveBinding((int)in_EAX);
  if (((iVar1 == 0) || (local_14 != 8)) || ((local_10 != 1 && (local_10 != 6)))) {
    iVar1 = stage_isCommandSymbol();
    if ((((iVar1 == 0) && (extraout_ECX != 0x2e)) || (extraout_EDX != 8)) || (local_10 != 4)) {
      return false;
    }
  }
  stage_compileExprOp((int)in_EAX,lingo_noop,*(uint *)(unaff_EDI + 4));
  stage_compileExprBlock((uint)in_EAX,lingo_noop,1,0,0);
  return true;
}



// ============================================================
// Function: stage_compilePropertyOp (FUN_680567a0)
// Address: 680567a0
// Size: 216 bytes
// Params: void * param_1, undefined * param_2, uint param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compilePropertyOp(void *param_1,undefined *param_2,uint param_3,int param_4)
{
  void *pvVar1;
  bool bVar2;
  char cVar3;
  undefined3 extraout_var;
  int iVar4;
  int iVar5;
  uint uVar6;
  int local_10 [2];
  int local_8;
  
  pvVar1 = param_1;
  bVar2 = stage_parseCondition((int)param_1,local_10,&local_8);
  if (((CONCAT31(extraout_var,bVar2) == 0) || (local_8 != 0x3e)) ||
     (iVar4 = (*(code *)param_2)(local_10), iVar4 != 0)) {
    stage_resolveSymbol((int)param_1,local_10);
    cVar3 = '_';
    iVar4 = 1;
  }
  else {
    if (param_4 == 0) {
      stage_compileExpression(param_1,param_2,0);
    }
    else {
      stage_compileHandler(param_1,stage_getCodegenState);
    }
    if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
      return 0;
    }
    cVar3 = 'a';
    iVar4 = 0;
  }
  if (param_4 != 0) {
    cVar3 = cVar3 + '\x01';
    iVar4 = (cVar3 != 'b') - 2;
    iVar5 = stage_checkLiteralType((int)param_1);
    if (iVar5 == 0) {
      stage_emitPushLiteral((int)param_1,0x12);
      return 0;
    }
    stage_compileHandler(param_1,param_2);
    if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
      return 0;
    }
  }
  param_1 = (void *)CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),cVar3);
  uVar6 = props_resolveSymbol((int)pvVar1,param_3);
  stage_emitInstruction((int)pvVar1,(int)param_1,uVar6,iVar4);
  return 0;
}



// ============================================================
// Function: stage_tryCompileBinaryOp (FUN_68056880)
// Address: 68056880
// Size: 48 bytes
// Params: void * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_tryCompileBinaryOp(void *param_1)

{
  int in_EAX;
  
  if ((((in_EAX != 0x20) && (in_EAX != 0x21)) && (in_EAX != 0x22)) && (in_EAX != 0x23)) {
    return 0;
  }
  stage_compileBinaryExpr(param_1,in_EAX);
  return 1;
}



// ============================================================
// Function: stage_compilePropertyCmd (FUN_680568b0)
// Address: 680568b0
// Size: 986 bytes
// Params: void * param_1, undefined * param_2, uint param_3, uint * param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compilePropertyCmd(void *param_1,undefined *param_2,uint param_3,uint *param_4,int param_5)
{
  byte bVar1;
  code *pcVar2;
  void *pvVar3;
  bool bVar4;
  undefined3 extraout_var;
  int iVar5;
  uint uVar6;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  void *pvVar7;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined *puVar8;
  uint *puVar9;
  uint *puVar10;
  code *pcVar11;
  int local_20 [2];
  int local_18 [2];
  int local_10;
  int local_c;
  int local_8;
  
  puVar9 = param_4;
  pvVar3 = param_1;
  uVar6 = *param_4;
  local_c = 0;
  local_10 = 0;
  local_8 = 0;
  if ((uVar6 & 0x40) == 0) {
    pcVar2 = (code *)param_2;
    if ((uVar6 & 0x21) != 0) {
      if (((uVar6 & 1) != 0) && (iVar5 = stage_checkConditionType((int)param_1), iVar5 == 0)) {
LAB_6805694f:
        stage_emitPushLiteral((int)pvVar3,0x12);
        return 0;
      }
      bVar4 = stage_parseCondition((int)pvVar3,local_18,(int *)&param_1);
      if (CONCAT31(extraout_var_00,bVar4) == 0) {
LAB_68056972:
        stage_emitPushLiteral((int)pvVar3,0x15);
        return 0;
      }
      pvVar7 = param_1;
      pcVar2 = (code *)param_2;
      if ((void *)puVar9[1] != param_1) {
        do {
          if (((*puVar9 & 0x100) != 0) && (local_c == 0)) {
            local_c = stage_tryCompileBinaryOp(pvVar3);
            if (*(int *)(**(int **)((int)pvVar3 + 8) + 0x41c) != 0) {
              return 0;
            }
            pvVar7 = param_1;
            if (local_c != 0) {
              local_8 = local_8 + 8;
              bVar4 = stage_parseCondition((int)pvVar3,local_18,(int *)&param_1);
              if (CONCAT31(extraout_var_01,bVar4) == 0) goto LAB_68056972;
              pvVar7 = param_1;
              pcVar2 = (code *)param_2;
              if ((void *)puVar9[1] == param_1) break;
            }
          }
          bVar1 = (byte)*puVar9;
          puVar10 = puVar9;
          while ((bVar1 & 8) != 0) {
            puVar10 = puVar10 + 3;
            bVar1 = (byte)*puVar10;
          }
          if ((*puVar10 & 0x400) != 0) {
            if (((uVar6 & 1) == 0) || (local_c != 0)) goto LAB_68056972;
            stage_resolveSymbol((int)pvVar3,local_18);
            puVar8 = param_2;
            goto LAB_68056a6d;
          }
          puVar9 = puVar10 + 3;
          pcVar2 = (code *)param_2;
        } while ((void *)puVar10[4] != pvVar7);
      }
    }
    do {
      if (((*puVar9 & 2) != 0) && (iVar5 = stage_checkConditionType((int)pvVar3), iVar5 == 0))
      goto LAB_6805694f;
      if ((*puVar9 & 4) != 0) {
        uVar6 = *puVar9 & 8;
        if ((uVar6 == 0) && (param_5 != 0)) {
          stage_compileHandler(pvVar3,stage_getCodegenState);
        }
        else {
          pcVar11 = pcVar2;
          if (uVar6 != 0) {
            pcVar11 = stage_checkIsEndOrProperty;
          }
          stage_compileExpression(pvVar3,pcVar11,0);
        }
        if (*(int *)(**(int **)((int)pvVar3 + 8) + 0x41c) != 0) {
          return 0;
        }
        local_8 = local_8 + 1;
      }
      if ((*puVar9 & 0x200) != 0) {
        local_8 = local_8 + 1;
        bVar4 = stage_parseCondition((int)pvVar3,local_18,(int *)&param_1);
        if ((CONCAT31(extraout_var_02,bVar4) != 0) && (param_1 == (void *)0x3e)) {
          bVar4 = stage_parseCondition((int)pvVar3,local_20,(int *)&param_1);
          if ((CONCAT31(extraout_var_03,bVar4) != 0) && (param_1 == (void *)0x68)) {
            if (param_5 == 0) {
              stage_compileExpression(pvVar3,pcVar2,0);
            }
            else {
              stage_compileHandler(pvVar3,stage_getCodegenState);
            }
            goto LAB_68056baf;
          }
          stage_resolveSymbol((int)pvVar3,local_20);
        }
        stage_resolveSymbol((int)pvVar3,local_18);
        stage_emitBranch((int)pvVar3,0);
      }
LAB_68056baf:
      if (((*puVar9 & 8) == 0) || (local_10 != 0)) {
        if (param_5 == 0) {
          local_8 = local_8 + -1;
          param_5 = 0x5c;
        }
        else {
          if ((*puVar9 & 0x10) == 0) goto LAB_68056c18;
          iVar5 = stage_checkLiteralType((int)pvVar3);
          if (iVar5 == 0) goto LAB_68056a9a;
          stage_compileHandler(pvVar3,pcVar2);
          if (*(int *)(**(int **)((int)pvVar3 + 8) + 0x41c) != 0) {
            return 0;
          }
          local_8 = local_8 + 1;
          param_5 = CONCAT31((*(unsigned int *)((char *)&param_5 + 1)),0x5d);
        }
        stage_emitBranch((int)pvVar3,(uint)(byte)puVar9[2]);
        stage_emitInstruction((int)pvVar3,param_5,
                     (int)(short)((ushort)*(byte *)((int)puVar9 + 9) + (short)local_c),-1 - local_8)
        ;
        return 0;
      }
      iVar5 = stage_checkConditionType((int)pvVar3);
      if (iVar5 == 0) goto LAB_6805694f;
      bVar4 = stage_parseCondition((int)pvVar3,local_18,(int *)&param_1);
      if (CONCAT31(extraout_var_04,bVar4) == 0) goto LAB_68056972;
      pvVar7 = (void *)puVar9[4];
      while (puVar9 = puVar9 + 3, param_1 != pvVar7) {
        if ((*puVar9 & 8) == 0) goto LAB_68056972;
        pvVar7 = (void *)puVar9[4];
      }
      local_10 = 1;
    } while( true );
  }
  bVar4 = stage_parseCondition((int)param_1,local_18,(int *)&param_1);
  puVar8 = param_2;
  if (((CONCAT31(extraout_var,bVar4) == 0) || (param_1 != (void *)0x3e)) ||
     (iVar5 = (*(code *)param_2)(local_18), iVar5 != 0)) {
    if (param_5 == 0) {
      stage_resolveSymbol((int)pvVar3,local_18);
      stage_emitInstruction((int)pvVar3,0x43,0,1);
      iVar5 = 0;
      uVar6 = props_resolveSymbol((int)pvVar3,puVar9[1]);
      stage_emitInstruction((int)pvVar3,0x66,uVar6,iVar5);
      return 0;
    }
LAB_68056c18:
    stage_emitPushLiteral((int)pvVar3,0x14);
    return 0;
  }
LAB_68056a6d:
  if (param_5 == 0) {
    stage_compileExpression(pvVar3,puVar8,0);
    if (*(int *)(**(int **)((int)pvVar3 + 8) + 0x41c) == 0) {
      param_5 = CONCAT31((*(unsigned int *)((char *)&param_5 + 1)),0x61);
      iVar5 = 0;
LAB_68056af0:
      iVar5 = -iVar5;
      uVar6 = props_resolveSymbol((int)pvVar3,param_3);
      stage_emitInstruction((int)pvVar3,param_5,uVar6,iVar5);
      return 0;
    }
  }
  else {
    stage_compileHandler(pvVar3,stage_getCodegenState);
    if (*(int *)(**(int **)((int)pvVar3 + 8) + 0x41c) == 0) {
      iVar5 = stage_checkLiteralType((int)pvVar3);
      if (iVar5 == 0) {
LAB_68056a9a:
        stage_emitPushLiteral((int)pvVar3,0xe);
        return 0;
      }
      stage_compileHandler(pvVar3,puVar8);
      if (*(int *)(**(int **)((int)pvVar3 + 8) + 0x41c) == 0) {
        param_5 = CONCAT31((*(unsigned int *)((char *)&param_5 + 1)),0x62);
        iVar5 = 2;
        goto LAB_68056af0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: stage_compileBuiltinOp (FUN_68056c90)
// Address: 68056c90
// Size: 180 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileBuiltinOp(int param_1,undefined *param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  
  piVar2 = (int *)((param_3 + 2) * 0x10 + **(int **)(**(int **)(param_1 + 8) + 0xc));
  iVar1 = *piVar2;
  if (iVar1 == 1) {
    stage_compileExpression((void *)param_1,param_2,0);
    stage_emitOpcode(param_1,(uint)*(byte *)(piVar2 + 2),0);
  }
  else {
    if (iVar1 != 2) {
      if (iVar1 != 3) {
        stage_emitPushLiteral(param_1,0x25);
        return 0;
      }
      (*(code *)piVar2[3])(param_1,param_2,piVar2[2]);
      return 0;
    }
    if ((param_3 != 0xb) && (param_3 != 0xc)) {
      stage_emitPushLiteral(param_1,0x24);
      return 0;
    }
    stage_compileExpression((void *)param_1,param_2,0);
    if ((*(int *)(**(int **)(param_1 + 8) + 0x41c) == 0) && (param_3 == 0xb)) {
      stage_emitOpcode(param_1,9,0);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_compileCommand (FUN_68056d50)
// Address: 68056d50
// Size: 500 bytes
// Params: void * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_compileCommand(void *param_1)

{
  void *pvVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint *puVar3;
  int iVar4;
  int local_1c;
  int *local_18;
  int local_14;
  int local_10;
  int local_c;
  int *local_8;
  
  pvVar1 = param_1;
  stage_parseCondition((int)param_1,&local_c,(int *)&param_1);
  if (local_c == 0) {
    return 1;
  }
  if (local_c == 8) {
    if (local_8 == (int *)0x1f) {
      stage_resolveSymbol((int)pvVar1,&local_c);
      stage_compileBlockExpr(pvVar1);
      return 1;
    }
    if (local_8 == (int *)0x4) {
      stage_compileBuiltinOp((int)pvVar1,lingo_noop,4);
      if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) != 0) {
        return 0;
      }
      stage_compileExprBlock((uint)pvVar1,lingo_noop,1,0,0);
      return 1;
    }
  }
  if ((int)param_1 < 0) {
    stage_emitPushLiteral((int)pvVar1,7);
    props_releaseValue(pvVar1,(byte)local_c,local_8);
    return 0;
  }
  bVar2 = stage_tryCompileAssignment();
  if (CONCAT31(extraout_var,bVar2) == 0) {
    puVar3 = score_lookupProperty(*(int **)(**(int **)((int)pvVar1 + 8) + 8),(uint)param_1,0,(uint *)0x0);
    if (puVar3 == (uint *)0x0) {
      stage_pushCurrentScope((int)pvVar1);
      if (((local_14 == 8) && (local_10 == 4)) &&
         (iVar4 = props_skipMatchingBlock(pvVar1,*(int *)(**(int **)((int)pvVar1 + 8) + 0x420),&local_1c),
         iVar4 != 0)) {
        if ((local_1c == 8) && (local_18 == (int *)0x1)) {
          stage_resolveSymbol((int)pvVar1,&local_14);
          stage_compileExprOp((int)pvVar1,lingo_noop,(uint)param_1);
          stage_compileExprBlock((uint)pvVar1,lingo_noop,1,0,0);
          goto LAB_68056ed9;
        }
        props_releaseValue(pvVar1,(byte)local_1c,local_18);
      }
      stage_resolveSymbol((int)pvVar1,&local_14);
      stage_emitReturnEx(0,0,0);
    }
    else {
      if ((code *)puVar3[1] == (code *)0x0) {
        stage_resolveSymbol((int)pvVar1,&local_c);
        return 0;
      }
      (*(code *)puVar3[1])(pvVar1);
    }
  }
LAB_68056ed9:
  if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x4d0) != 0) {
    return 1;
  }
  stage_pushCurrentScope((int)pvVar1);
  if (local_c != 0) {
    if (((local_c == 8) && (local_8 == (int *)0x3e)) &&
       ((stage_pushCurrentScope((int)pvVar1), local_c == 8 && (local_8 == (int *)0x68)))) {
      iVar4 = 0x33;
    }
    else {
      iVar4 = 0x27;
    }
    stage_emitPushLiteral((int)pvVar1,iVar4);
    props_releaseValue(pvVar1,(byte)local_c,local_8);
    return 0;
  }
  return 1;
}



