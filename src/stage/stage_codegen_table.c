// Module: stage
// Topic: Operator and command table setup
// Address range: 0x6805CDD0 - 0x6805D400
// Functions (11):
//   stage_compileConditionLookup (FUN_6805CDD0)
//   stage_compileReturnStmt (FUN_6805CE50)
//   stage_compileSwitchBlock (FUN_6805CEC0)
//   stage_compileBlockScope (FUN_6805D0E0)
//   stage_writeTableData (FUN_6805D110)
//   stage_compileStringOp (FUN_6805D170)
//   stage_compileDeleteOp (FUN_6805D1C0)
//   stage_isContainsOp (FUN_6805D2A0)
//   stage_compilePutOp (FUN_6805D2D0)
//   stage_addTableEntry (FUN_6805D3D0)
//   stage_populateOperatorTable (FUN_6805D400)

// ============================================================
// Function: stage_compileConditionLookup (FUN_6805CDD0)
// Address: 6805cdd0
// Size: 113 bytes
// Params: void * param_1, undefined * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileConditionLookup(void *param_1,undefined *param_2)
{
  void *pvVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint *puVar3;
  int local_10 [2];
  uint local_8;
  
  pvVar1 = param_1;
  bVar2 = stage_parseCondition((int)param_1,local_10,(int *)&param_1);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    stage_emitPushLiteral((int)pvVar1,0x13);
    return 0;
  }
  puVar3 = score_lookupProperty(*(int **)(**(int **)((int)pvVar1 + 8) + 0x10),(uint)param_1,0,&local_8);
  if (puVar3 == (uint *)0x0) {
    stage_compilePropertyOp(pvVar1,param_2,(uint)param_1,0);
    return 0;
  }
  stage_compilePropertyCmd(pvVar1,param_2,(uint)param_1,(uint *)puVar3[1],0);
  return 0;
}



// ============================================================
// Function: stage_compileReturnStmt (FUN_6805CE50)
// Address: 6805ce50
// Size: 103 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileReturnStmt(void *param_1)
{
  int local_c;
  int local_8;
  
  stage_compileHandler(param_1,lingo_noop);
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
    stage_pushCurrentScope((int)param_1);
    if (local_c == 8) {
      if (local_8 == 5) {
        return 0;
      }
      if (local_8 == 3) {
        local_8 = 0;
        stage_resolveSymbol((int)param_1,&local_c);
        return 0;
      }
    }
    stage_emitPushLiteral((int)param_1,8);
  }
  return 0;
}



// ============================================================
// Function: stage_compileSwitchBlock (FUN_6805CEC0)
// Address: 6805cec0
// Size: 536 bytes
// Params: void * param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileSwitchBlock(void *param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  uint local_20 [2];
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  local_8 = (uint)(param_3 != 7) * 2 + 6;
  uVar3 = 0;
  bVar2 = false;
  stage_pushCurrentScope((int)param_1);
  if (local_10 == 8) {
    if (local_c == param_3) goto LAB_6805d082;
    if (local_c == 10) {
      stage_pushCurrentScope((int)param_1);
      if ((local_10 != 8) || (local_c != param_3)) {
        stage_emitPushLiteral((int)param_1,0x2c);
        return 0;
      }
      bVar2 = true;
      goto LAB_6805d082;
    }
  }
  stage_resolveSymbol((int)param_1,&local_10);
  do {
    stage_pushCurrentScope((int)param_1);
    uVar4 = uVar3;
    if (local_10 == 8) {
      if (local_c == 0x24) {
        stage_pushCurrentScope((int)param_1);
        stage_pushCurrentScope((int)param_1);
        if ((local_18 == 8) && (local_14 == 10)) {
          if (!bVar2) {
            if (uVar3 != 0) goto LAB_6805d0a5;
            bVar2 = true;
          }
          stage_compileBlock(param_1,local_20);
          iVar1 = *(int *)(**(int **)((int)param_1 + 8) + 0x41c);
          goto joined_r0x6805d01a;
        }
        stage_resolveSymbol((int)param_1,&local_18);
        stage_resolveSymbol((int)param_1,local_20);
        stage_resolveSymbol((int)param_1,&local_10);
      }
      else {
        if (local_c != local_8) goto LAB_6805cfde;
        stage_resolveSymbol((int)param_1,&local_10);
      }
    }
    else {
LAB_6805cfde:
      stage_pushCurrentScope((int)param_1);
      if ((local_18 == 8) && (local_14 == 10)) {
        if (!bVar2) {
          if (uVar3 != 0) {
LAB_6805d0a5:
            stage_emitPushLiteral((int)param_1,0x2b);
            return 0;
          }
          bVar2 = true;
        }
        stage_compileBlock(param_1,&local_10);
        iVar1 = *(int *)(**(int **)((int)param_1 + 8) + 0x41c);
joined_r0x6805d01a:
        uVar4 = uVar3 + 1;
        if (iVar1 != 0) {
          return 0;
        }
      }
      else {
        stage_resolveSymbol((int)param_1,&local_18);
        stage_resolveSymbol((int)param_1,&local_10);
        if (bVar2) {
          uVar4 = uVar3 + 1;
          stage_emitBranch((int)param_1,(int)(uVar3 + 2) >> 1);
        }
      }
    }
    uVar3 = uVar4 + 1;
    stage_compileHandler(param_1,lingo_noop);
    if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
      return 0;
    }
    stage_pushCurrentScope((int)param_1);
    if (local_10 != 8) goto LAB_6805d0c7;
  } while (local_c == 3);
  if (local_c != param_3) {
LAB_6805d0c7:
    stage_emitPushLiteral((int)param_1,5);
    return 0;
  }
LAB_6805d082:
  stage_emitInstruction((int)param_1,0x43,uVar3,1);
  if (!bVar2) {
    stage_emitOpcode((int)param_1,0x1e,-uVar3);
    return 0;
  }
  stage_emitOpcode((int)param_1,0x1f,-uVar3);
  return 0;
}



// ============================================================
// Function: stage_compileBlockScope (FUN_6805D0E0)
// Address: 6805d0e0
// Size: 37 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileBlockScope(void *param_1)
{
  uint local_c [2];
  
  stage_pushCurrentScope((int)param_1);
  stage_compileBlock(param_1,local_c);
  return 0;
}



// ============================================================
// Function: stage_writeTableData (FUN_6805d110)
// Address: 6805d110
// Size: 87 bytes
// Params: void * param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_writeTableData(void *param_1,undefined4 param_2,uint param_3)
{
  byte bVar1;
  uint local_c [2];
  
  bVar1 = (byte)param_3;
  if ((param_3 & 0x8000) != 0) {
    if (bVar1 == 0) {
      param_3 = param_3 & 0xffffff00;
    }
    else {
      (*(unsigned short *)((char *)&param_3 + 0)) = (ushort)bVar1;
    }
    props_loadCString((int)param_1,(char *)&param_3,local_c);
    stage_compileBlock(param_1,local_c);
    return 0;
  }
  stage_emitBranch((int)param_1,(int)(char)bVar1);
  return 0;
}



// ============================================================
// Function: stage_compileStringOp (FUN_6805D170)
// Address: 6805d170
// Size: 72 bytes
// Params: void * param_1, undefined * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileStringOp(void *param_1,undefined *param_2,int param_3)
{
  stage_compileBinaryExpr(param_1,param_3);
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
    stage_compileExpression(param_1,param_2,0);
    if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
      stage_emitOpcode((int)param_1,0x17,-8);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_compileDeleteOp (FUN_6805D1C0)
// Address: 6805d1c0
// Size: 224 bytes
// Params: void * param_1, undefined * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileDeleteOp(void *param_1,undefined *param_2)
{
  int iVar1;
  int local_c;
  int local_8;
  
  stage_pushCurrentScope((int)param_1);
  if ((local_c == 8) && (local_8 == 4)) {
    stage_compileHandler(param_1,param_2);
    if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
      return 0;
    }
    stage_pushCurrentScope((int)param_1);
    if ((local_c == 8) && (local_8 == 3)) {
      stage_compileHandler(param_1,param_2);
      if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) != 0) {
        return 0;
      }
      stage_pushCurrentScope((int)param_1);
    }
    else {
      stage_emitBranch((int)param_1,0);
    }
    if ((local_c != 8) || (local_8 != 5)) {
      stage_emitPushLiteral((int)param_1,0x28);
      return 0;
    }
  }
  else {
    stage_resolveSymbol((int)param_1,&local_c);
    stage_compileExpression(param_1,param_2,0);
    iVar1 = stage_compileUnaryExpr((int)param_1,param_2);
    if (iVar1 == 0) {
      stage_emitBranch((int)param_1,0);
    }
  }
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
    stage_emitOpcode((int)param_1,0x1b,-1);
  }
  return 0;
}



// ============================================================
// Function: stage_isContainsOp (FUN_6805D2A0)
// Address: 6805d2a0
// Size: 44 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_isContainsOp(int *param_1)

{
  int iVar1;
  
  if ((*param_1 == 8) &&
     (((iVar1 = param_1[1], iVar1 == 0x4b || (iVar1 == 0x4c)) || (iVar1 == 0x15)))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_compilePutOp (FUN_6805D2D0)
// Address: 6805d2d0
// Size: 246 bytes
// Params: void * param_1, undefined * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compilePutOp(void *param_1,undefined *param_2)
{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  int local_10;
  int local_c;
  int local_8;
  
  pvVar1 = param_1;
  stage_pushCurrentScope((int)param_1);
  stage_resolveSymbol((int)param_1,&local_10);
  if ((local_10 == 8) && (local_c == 4)) {
    stage_compileExprOp((int)param_1,param_2,0x2e);
    stage_compileExprBlock((uint)param_1,param_2,0,0,0);
    return 0;
  }
  stage_compileExpression(param_1,stage_isContainsOp,0);
  if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
    stage_parseCondition((int)param_1,&local_10,&local_8);
    if (local_8 == 0x4b) {
      param_1 = (void *)CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),0x1a);
    }
    else {
      if (local_8 != 0x4c) {
        stage_resolveSymbol((int)param_1,&local_10);
        stage_emitInstruction((int)param_1,0x43,1,1);
        iVar3 = -1;
        uVar2 = props_resolveSymbol((int)param_1,0x2e);
        stage_emitInstruction((int)param_1,(uint)*(byte *)(**(int **)((int)param_1 + 8) + 0x418),uVar2,iVar3)
        ;
        return 0;
      }
      param_1 = (void *)CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),0x19);
    }
    stage_compileExpression(pvVar1,param_2,0);
    if (*(int *)(**(int **)((int)pvVar1 + 8) + 0x41c) == 0) {
      stage_emitOpcode((int)pvVar1,param_1,-1);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_addTableEntry (FUN_6805d3d0)
// Address: 6805d3d0
// Size: 41 bytes
// Params: void * this, undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall
stage_addTableEntry(void *this,undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  int in_EAX;
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)((in_EAX + 2) * 0x10 + **(int **)((int)this + 0xc));
  *puVar1 = param_1;
  puVar1[1] = param_2;
  puVar1[2] = param_4;
  puVar1[3] = param_3;
  return 0;
}



// ============================================================
// Function: stage_populateOperatorTable (FUN_6805D400)
// Address: 6805d400
// Size: 984 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_populateOperatorTable(void *param_1)
{
  stage_addTableEntry(param_1,4,0,0,0);
  stage_addTableEntry(param_1,4,0,0,0);
  stage_addTableEntry(param_1,4,0,0,0);
  stage_addTableEntry(param_1,3,0,stage_compileReturnStmt,0);
  stage_addTableEntry(param_1,4,0,0,0);
  stage_addTableEntry(param_1,3,0,stage_compileSwitchBlock,7);
  stage_addTableEntry(param_1,4,0,0,0);
  stage_addTableEntry(param_1,3,0,stage_compileSwitchBlock,9);
  stage_addTableEntry(param_1,4,0,0,0);
  stage_addTableEntry(param_1,2,0xfffffffb,0,6);
  stage_addTableEntry(param_1,2,0xfffffffb,0,5);
  stage_addTableEntry(param_1,1,0xfffffffe,0,0x14);
  stage_addTableEntry(param_1,2,0xfffffffc,0,4);
  stage_addTableEntry(param_1,2,0xfffffffc,0,7);
  stage_addTableEntry(param_1,2,0xfffffffc,0,8);
  stage_addTableEntry(param_1,2,0xfffffff9,0,0x15);
  stage_addTableEntry(param_1,2,0xfffffff9,0,0x16);
  stage_addTableEntry(param_1,2,0xfffffff7,0,0x12);
  stage_addTableEntry(param_1,2,0xfffffff6,0,0x13);
  stage_addTableEntry(param_1,2,0xfffffff8,0,0xf);
  stage_addTableEntry(param_1,2,0xfffffff9,0,0xc);
  stage_addTableEntry(param_1,2,0xfffffff9,0,0xe);
  stage_addTableEntry(param_1,2,0xfffffff9,0,0xd);
  stage_addTableEntry(param_1,2,0xfffffff9,0,0x10);
  stage_addTableEntry(param_1,2,0xfffffff9,0,0x11);
  stage_addTableEntry(param_1,2,0xfffffffa,0,10);
  stage_addTableEntry(param_1,2,0xfffffffa,0,0xb);
  stage_addTableEntry(param_1,4,0,0,0);
  stage_addTableEntry(param_1,4,0,0,0);
  stage_addTableEntry(param_1,3,0,stage_compileConditionLookup,0);
  stage_addTableEntry(param_1,3,0,stage_compileStringOp,0x20);
  stage_addTableEntry(param_1,3,0,stage_compileStringOp,0x21);
  stage_addTableEntry(param_1,3,0,stage_compileStringOp,0x22);
  stage_addTableEntry(param_1,3,0,stage_compileStringOp,0x23);
  stage_addTableEntry(param_1,3,0,stage_compileBlockScope,0);
  stage_addTableEntry(param_1,3,0,stage_writeTableData,1);
  stage_addTableEntry(param_1,3,0,stage_writeTableData,0);
  stage_addTableEntry(param_1,3,0,stage_writeTableData,0xffff800d);
  stage_addTableEntry(param_1,3,0,stage_writeTableData,0xffff8003);
  stage_addTableEntry(param_1,3,0,stage_writeTableData,0xffff8009);
  stage_addTableEntry(param_1,3,0,stage_writeTableData,0xffff8008);
  stage_addTableEntry(param_1,3,0,stage_writeTableData,0xffff8022);
  stage_addTableEntry(param_1,3,0,stage_writeTableData,0xffff8000);
  stage_addTableEntry(param_1,3,0,stage_compileDeleteOp,0);
  stage_addTableEntry(param_1,3,0,stage_compilePutOp,0);
  return 0;
}



