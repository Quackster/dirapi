// Module: crypto
// Topic: Expression parsing, operator precedence, and function compilation
// Address range: 0x68144C00 - 0x68147870
// Functions (22):
//   crypto_parseForIn
//   crypto_parseFuncDef
//   crypto_parseExprList
//   crypto_parseEquality
//   crypto_parseStrictEquality
//   crypto_parseBitwiseAnd
//   crypto_parseBitwiseXor
//   crypto_parseBitwiseOr
//   crypto_parseLogicalAnd
//   crypto_parseLogicalOr
//   crypto_parseTernary
//   crypto_parseAssignExpr
//   crypto_parseCommaExpr
//   crypto_parseCondExpr
//   crypto_parseUnary
//   crypto_parseStatementBody
//   crypto_parseExprPrimary
//   crypto_compileFunction
//   crypto_compileVarDecl
//   crypto_compileScript
//   crypto_compileExpression
//   crypto_compileExprFast

// ============================================================
// Function: crypto_parseForIn (FUN_68144c00)
// Address: 68144c00
// Size: 265 bytes
// Params: uint * param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * crypto_parseForIn(uint *param_1)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int unaff_EBX;
  uint *unaff_ESI;
  
  iVar3 = strings_parseExpression(unaff_ESI,unaff_EBX);
  if (iVar3 != 0x1b) {
    strings_scanToken(unaff_ESI,unaff_EBX,0,0,0x4a);
    return (int *)0x0;
  }
  piVar4 = crypto_parseTokenList(unaff_EBX,param_1);
  if (piVar4 != (int *)0x0) {
    iVar3 = strings_parseExpression(unaff_ESI,unaff_EBX);
    if (iVar3 == 0x1c) {
      if (((*piVar4 == 4) && (piVar4[3] == 0)) && (0xc < *(int *)piVar4[7])) {
        if ((unaff_ESI[3] == 0) || (0x81 < (int)unaff_ESI[3])) {
          bVar2 = false;
        }
        else {
          bVar2 = true;
        }
        uVar5 = strings_scanToken(unaff_ESI,unaff_EBX,0,5,0x70);
        if (uVar5 == 0) {
          return (int *)0x0;
        }
        if (bVar2) {
          iVar3 = piVar4[6];
          *piVar4 = 0xc;
          piVar4[3] = (uint)(byte)unaff_ESI[4];
          iVar1 = *(int *)(iVar3 + 0xc);
          if (iVar1 == 0x36) {
            *(undefined4 *)(iVar3 + 0xc) = 0x35;
          }
          else {
            if (iVar1 == 0x38) {
              *(undefined4 *)(iVar3 + 0xc) = 0x37;
              return piVar4;
            }
            if (iVar1 == 0x6d) {
              *(undefined4 *)(iVar3 + 0xc) = 0x3b;
              return piVar4;
            }
          }
        }
      }
      return piVar4;
    }
    strings_scanToken(unaff_ESI,unaff_EBX,0,0,0x4b);
  }
  return (int *)0x0;
}



// ============================================================
// Function: crypto_parseFuncDef (FUN_68144d10)
// Address: 68144d10
// Size: 502 bytes
// Params: uint * param_1
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * crypto_parseFuncDef(uint *param_1)

{
  bool bVar1;
  uint *in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined3 extraout_var;
  int *piVar4;
  int unaff_EBX;
  undefined4 uVar5;
  undefined4 *local_8;
  
  iVar2 = strings_parseExpression(in_EAX,unaff_EBX);
  if (iVar2 != 0x1d) {
    strings_scanToken(in_EAX,unaff_EBX,0,0,0x4c);
    return (undefined4 *)0x0;
  }
  local_8 = crypto_createNode(param_1,0xffffffff);
  if (local_8 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  local_8[3] = 0x3b;
  local_8[6] = *(undefined4 *)(unaff_EBX + 0x14 + *(int *)(unaff_EBX + 0x60) * 0x18);
  local_8[7] = 0;
  local_8[8] = 0xffffffff;
  local_8[9] = 0;
LAB_68144d82:
  do {
    *(uint *)(unaff_EBX + 0x7c) = *(uint *)(unaff_EBX + 0x7c) | 8;
    iVar2 = strings_parseExpression(in_EAX,unaff_EBX);
    if ((iVar2 != 0x16) && (iVar2 != 0x17)) {
      *(uint *)(unaff_EBX + 0x7c) = *(uint *)(unaff_EBX + 0x7c) & 0xfffffff7;
      if (iVar2 == -1) {
        return (undefined4 *)0x0;
      }
      strings_resetScanner(unaff_EBX);
      iVar2 = local_8[3];
      if (iVar2 == 0x35) {
        local_8[3] = 0x4e;
        return local_8;
      }
      if (iVar2 == 0x37) {
        local_8[3] = 0x4f;
        return local_8;
      }
      if (iVar2 == 0x4d) {
        return local_8;
      }
LAB_68144ec2:
      uVar5 = 0x71;
      goto LAB_68144eee;
    }
    *(uint *)(unaff_EBX + 0x7c) = *(uint *)(unaff_EBX + 0x7c) & 0xfffffff7;
    if (local_8[3] == 0x4d) goto LAB_68144ec2;
    if (iVar2 != 0x16) {
      puVar3 = crypto_createNode(param_1,2);
      if (puVar3 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      piVar4 = crypto_parseTokenList(unaff_EBX,param_1);
      if (piVar4 == (int *)0x0) {
        return (undefined4 *)0x0;
      }
      iVar2 = strings_parseExpression(in_EAX,unaff_EBX);
      if (iVar2 != 0x18) {
        uVar5 = 0x4e;
LAB_68144eee:
        strings_scanToken(in_EAX,unaff_EBX,0,0,uVar5);
        return (undefined4 *)0x0;
      }
      puVar3[1] = local_8[1];
      uVar5 = *(undefined4 *)(unaff_EBX + 8 + *(int *)(unaff_EBX + 0x60) * 0x18);
      puVar3[6] = local_8;
      puVar3[3] = 0x37;
      puVar3[7] = piVar4;
      puVar3[2] = uVar5;
      local_8 = puVar3;
      goto LAB_68144d82;
    }
    puVar3 = crypto_createNode(param_1,0xffffffff);
    if (puVar3 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    bVar1 = strings_compareRange(in_EAX,unaff_EBX,0x11);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      iVar2 = strings_parseExpression(in_EAX,unaff_EBX);
      if (iVar2 != 0x1d) {
        uVar5 = 0x4d;
        goto LAB_68144eee;
      }
      puVar3[3] = 0x35;
      puVar3[6] = *(undefined4 *)(unaff_EBX + 0x14 + *(int *)(unaff_EBX + 0x60) * 0x18);
      puVar3[8] = 0xffffffff;
      puVar3[9] = 0;
    }
    else {
      puVar3[3] = 0x4d;
      puVar3[6] = 0;
    }
    puVar3[7] = local_8;
    puVar3[1] = local_8[1];
    puVar3[2] = *(undefined4 *)(unaff_EBX + 8 + *(int *)(unaff_EBX + 0x60) * 0x18);
    local_8 = puVar3;
  } while( true );
}



// ============================================================
// Function: crypto_parseExprList (FUN_68144f10)
// Address: 68144f10
// Size: 486 bytes
// Params: uint * param_1, uint param_2, uint * param_3
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * crypto_parseExprList(uint *param_1,uint param_2,uint *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 8;
  uVar1 = strings_parseExpression(param_1,param_2);
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xfffffff7;
  switch(uVar1) {
  default:
    strings_resetScanner(param_2);
    puVar3 = crypto_parsePostfixExpr(param_1,param_2,param_3,1);
    if (puVar3 != (undefined4 *)0x0) {
      if (((uint)*(ushort *)((int)puVar3 + 10) != *(uint *)(param_2 + 0x68)) ||
         ((iVar4 = strings_beginParse(param_1,param_2), iVar4 != 0x14 && (iVar4 != 0x15)))) {
        return puVar3;
      }
      strings_parseExpression(param_1,param_2);
      puVar5 = crypto_createNode(param_3,1);
      if ((puVar5 != (undefined4 *)0x0) &&
         (iVar4 = crypto_resolveAssignOpcode(param_2,param_3,(int)puVar5), iVar4 != 0)) {
        puVar5[1] = puVar3[1];
        return puVar5;
      }
    }
    break;
  case 0xf:
  case 0x10:
  case 0x13:
    puVar3 = crypto_createNode(param_3,1);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0x13;
      puVar3[3] = *(undefined4 *)(param_2 + 0x10 + *(int *)(param_2 + 0x60) * 0x18);
      puVar5 = crypto_parseExprList(param_1,param_2,param_3);
      if (puVar5 != (undefined4 *)0x0) {
        uVar1 = puVar5[2];
        puVar3[6] = puVar5;
        puVar3[2] = uVar1;
        return puVar3;
      }
    }
    break;
  case 0x14:
  case 0x15:
    puVar3 = crypto_createNode(param_3,1);
    if (((puVar3 != (undefined4 *)0x0) &&
        (puVar5 = crypto_parsePostfixExpr(param_1,param_2,param_3,1), puVar5 != (undefined4 *)0x0)) &&
       (iVar4 = crypto_resolveAssignOpcode(param_2,param_3,(int)puVar3), iVar4 != 0)) {
      puVar3[2] = puVar5[2];
      return puVar3;
    }
    break;
  case 0x34:
    puVar3 = crypto_createNode(param_3,1);
    if ((puVar3 != (undefined4 *)0x0) &&
       (piVar2 = crypto_parseExprList(param_1,param_2,param_3), piVar2 != (int *)0x0)) {
      puVar3[2] = piVar2[2];
      iVar4 = *piVar2;
      while (iVar4 == 0x1c) {
        piVar2 = (int *)piVar2[6];
        iVar4 = *piVar2;
      }
      puVar3[6] = piVar2;
      return puVar3;
    }
    break;
  case 0xffffffff:
    break;
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: crypto_parseEquality (FUN_68145150)
// Address: 68145150
// Size: 114 bytes
// Return: undefined
// Calling convention: unknown
// ============================================================

int * crypto_parseEquality(uint *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int *piVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint *unaff_EBX;
  uint unaff_EDI;
  
  piVar4 = crypto_parseExprList(unaff_EBX,unaff_EDI,param_1);
  while ((piVar4 != (int *)0x0 &&
         ((bVar3 = strings_compareRange(unaff_EBX,unaff_EDI,0x11), CONCAT31(extraout_var,bVar3) != 0 ||
          (bVar3 = strings_compareRange(unaff_EBX,unaff_EDI,0x12), CONCAT31(extraout_var_00,bVar3) != 0)))))
  {
    iVar1 = *(int *)(unaff_EDI + *(int *)(unaff_EDI + 0x60) * 0x18);
    iVar2 = *(int *)(unaff_EDI + *(int *)(unaff_EDI + 0x60) * 0x18 + 0x10);
    crypto_parseExprList(unaff_EBX,unaff_EDI,param_1);
    piVar4 = crypto_createBinaryNode(param_1,unaff_EBX,iVar1,iVar2);
  }
  return piVar4;
}



// ============================================================
// Function: crypto_parseStrictEquality (FUN_681451d0)
// Address: 681451d0
// Size: 121 bytes
// Return: undefined
// Calling convention: unknown
// ============================================================

int * crypto_parseStrictEquality(void *param_1)

{
  int iVar1;
  bool bVar2;
  int in_EAX;
  int *piVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint *in_ECX;
  
  piVar3 = (int *)crypto_parseEquality(param_1);
  while ((piVar3 != (int *)0x0 &&
         ((bVar2 = strings_compareRange(in_ECX,in_EAX,0xf), CONCAT31(extraout_var,bVar2) != 0 ||
          (bVar2 = strings_compareRange(in_ECX,in_EAX,0x10), CONCAT31(extraout_var_00,bVar2) != 0))))) {
    iVar1 = *(int *)(in_EAX + *(int *)(in_EAX + 0x60) * 0x18);
    crypto_parseEquality(param_1);
    piVar3 = crypto_createBinaryNode(param_1,in_ECX,iVar1,(iVar1 != 0xf) + 0x1b);
  }
  return piVar3;
}



// ============================================================
// Function: crypto_parseBitwiseAnd (FUN_68145250)
// Address: 68145250
// Size: 93 bytes
// Return: undefined
// Calling convention: unknown
// ============================================================

int * crypto_parseBitwiseAnd(void *param_1)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  undefined3 extraout_var;
  uint *unaff_EBX;
  int unaff_EDI;
  
  piVar3 = (int *)crypto_parseStrictEquality(param_1);
  while ((piVar3 != (int *)0x0 &&
         (bVar2 = strings_compareRange(unaff_EBX,unaff_EDI,0xe), CONCAT31(extraout_var,bVar2) != 0))) {
    iVar1 = *(int *)(unaff_EDI + 0x10 + *(int *)(unaff_EDI + 0x60) * 0x18);
    crypto_parseStrictEquality(param_1);
    piVar3 = crypto_createBinaryNode(param_1,unaff_EBX,0xe,iVar1);
  }
  return piVar3;
}



// ============================================================
// Function: crypto_parseBitwiseXor (FUN_681452b0)
// Address: 681452b0
// Size: 181 bytes
// Params: void * this, uint * param_1
// Return: int *
// Calling convention: __thiscall
// ============================================================

int * __thiscall crypto_parseBitwiseXor(void *this,uint *param_1)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  int in_EAX;
  int *piVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint uVar5;
  
  uVar5 = *param_1 & 0x10;
  *param_1 = *param_1 & 0xffffffef;
  piVar4 = (int *)crypto_parseBitwiseAnd(param_1);
  if (piVar4 == (int *)0x0) {
    *param_1 = *param_1 | uVar5;
    return (int *)0x0;
  }
  do {
    bVar3 = strings_compareRange(this,in_EAX,0xd);
    if ((CONCAT31(extraout_var,bVar3) == 0) &&
       (((uVar5 != 0 ||
         (bVar3 = strings_compareRange(this,in_EAX,0x2f), CONCAT31(extraout_var_00,bVar3) == 0)) &&
        (bVar3 = strings_compareRange(this,in_EAX,0x3b), CONCAT31(extraout_var_01,bVar3) == 0)))) break;
    iVar1 = *(int *)(in_EAX + *(int *)(in_EAX + 0x60) * 0x18);
    iVar2 = *(int *)(in_EAX + 0x10 + *(int *)(in_EAX + 0x60) * 0x18);
    crypto_parseBitwiseAnd(param_1);
    piVar4 = crypto_createBinaryNode(param_1,this,iVar1,iVar2);
  } while (piVar4 != (int *)0x0);
  *param_1 = *param_1 | uVar5;
  return piVar4;
}



// ============================================================
// Function: crypto_parseBitwiseOr (FUN_68145370)
// Address: 68145370
// Size: 93 bytes
// Return: undefined
// Calling convention: unknown
// ============================================================

int * crypto_parseBitwiseOr(uint *param_1)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  undefined3 extraout_var;
  uint *unaff_EBX;
  int unaff_EDI;
  
  piVar3 = crypto_parseBitwiseXor(unaff_EBX,param_1);
  while ((piVar3 != (int *)0x0 &&
         (bVar2 = strings_compareRange(unaff_EBX,unaff_EDI,0xc), CONCAT31(extraout_var,bVar2) != 0))) {
    iVar1 = *(int *)(unaff_EDI + 0x10 + *(int *)(unaff_EDI + 0x60) * 0x18);
    crypto_parseBitwiseXor(unaff_EBX,param_1);
    piVar3 = crypto_createBinaryNode(param_1,unaff_EBX,0xc,iVar1);
  }
  return piVar3;
}



// ============================================================
// Function: crypto_parseLogicalAnd (FUN_681453d0)
// Address: 681453d0
// Size: 82 bytes
// Return: undefined
// Calling convention: unknown
// ============================================================

int * crypto_parseLogicalAnd(void *param_1)

{
  bool bVar1;
  int in_EAX;
  int *piVar2;
  undefined3 extraout_var;
  uint *in_ECX;
  
  piVar2 = (int *)crypto_parseBitwiseOr(param_1);
  while ((piVar2 != (int *)0x0 &&
         (bVar1 = strings_compareRange(in_ECX,in_EAX,0xb), CONCAT31(extraout_var,bVar1) != 0))) {
    crypto_parseBitwiseOr(param_1);
    piVar2 = crypto_createBinaryNode(param_1,in_ECX,0xb,0x11);
  }
  return piVar2;
}



// ============================================================
// Function: crypto_parseLogicalOr (FUN_68145430)
// Address: 68145430
// Size: 73 bytes
// Return: undefined
// Calling convention: unknown
// ============================================================

int * crypto_parseLogicalOr(int param_1)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  void *unaff_EBX;
  uint *unaff_EDI;
  
  piVar2 = (int *)crypto_parseLogicalAnd(unaff_EBX);
  while ((piVar2 != (int *)0x0 &&
         (bVar1 = strings_compareRange(unaff_EDI,param_1,10), CONCAT31(extraout_var,bVar1) != 0))) {
    crypto_parseLogicalAnd(unaff_EBX);
    piVar2 = crypto_createBinaryNode(unaff_EBX,unaff_EDI,10,0x10);
  }
  return piVar2;
}



// ============================================================
// Function: crypto_parseTernary (FUN_68145480)
// Address: 68145480
// Size: 84 bytes
// Return: undefined
// Calling convention: unknown
// ============================================================

int * crypto_parseTernary(int param_1)

{
  bool bVar1;
  void *in_EAX;
  int *piVar2;
  undefined3 extraout_var;
  uint *in_ECX;
  
  piVar2 = (int *)crypto_parseLogicalOr(param_1);
  while ((piVar2 != (int *)0x0 &&
         (bVar1 = strings_compareRange(in_ECX,param_1,9), CONCAT31(extraout_var,bVar1) != 0))) {
    crypto_parseLogicalOr(param_1);
    piVar2 = crypto_createBinaryNode(in_EAX,in_ECX,9,0xf);
  }
  return piVar2;
}



// ============================================================
// Function: crypto_parseAssignExpr (FUN_681454e0)
// Address: 681454e0
// Size: 86 bytes
// Params: uint * param_1, int param_2, void * param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * crypto_parseAssignExpr(uint *param_1,int param_2,void *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  
  piVar2 = (int *)crypto_parseTernary(param_2);
  if ((piVar2 != (int *)0x0) &&
     (bVar1 = strings_compareRange(param_1,param_2,8), CONCAT31(extraout_var,bVar1) != 0)) {
    crypto_parseAssignExpr(param_1,param_2,param_3);
    piVar2 = crypto_createBinaryNode(param_3,param_1,8,0x45);
    return piVar2;
  }
  return piVar2;
}



// ============================================================
// Function: crypto_parseCommaExpr (FUN_68145540)
// Address: 68145540
// Size: 84 bytes
// Params: uint * param_1, int param_2, void * param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * crypto_parseCommaExpr(uint *param_1,int param_2,void *param_3)

{
  bool bVar1;
  int *piVar2;
  undefined3 extraout_var;
  
  piVar2 = crypto_parseAssignExpr(param_1,param_2,param_3);
  if ((piVar2 != (int *)0x0) &&
     (bVar1 = strings_compareRange(param_1,param_2,7), CONCAT31(extraout_var,bVar1) != 0)) {
    crypto_parseCommaExpr(param_1,param_2,param_3);
    piVar2 = crypto_createBinaryNode(param_3,param_1,7,0x44);
    return piVar2;
  }
  return piVar2;
}



// ============================================================
// Function: crypto_parseCondExpr (FUN_681455a0)
// Address: 681455a0
// Size: 218 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * crypto_parseCondExpr(int param_1)

{
  uint uVar1;
  bool bVar2;
  uint *in_EAX;
  int *piVar3;
  undefined3 extraout_var;
  int *piVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  uint *unaff_EBX;
  
  piVar3 = crypto_parseCommaExpr(in_EAX,param_1,unaff_EBX);
  if ((piVar3 != (int *)0x0) &&
     (bVar2 = strings_compareRange(in_EAX,param_1,5), CONCAT31(extraout_var,bVar2) != 0)) {
    piVar4 = crypto_createNode(unaff_EBX,3);
    if (piVar4 != (int *)0x0) {
      uVar1 = *unaff_EBX;
      *unaff_EBX = uVar1 & 0xffffffef;
      piVar5 = crypto_parseUnary(in_EAX,param_1,unaff_EBX);
      *unaff_EBX = *unaff_EBX & 0xe0 | uVar1;
      if (piVar5 != (int *)0x0) {
        iVar6 = strings_parseExpression(in_EAX,param_1);
        if (iVar6 == 6) {
          piVar7 = crypto_parseUnary(in_EAX,param_1,unaff_EBX);
          if (piVar7 != (int *)0x0) {
            piVar4[1] = piVar3[1];
            iVar6 = piVar7[2];
            piVar4[6] = (int)piVar3;
            piVar4[2] = iVar6;
            piVar4[7] = (int)piVar5;
            piVar4[8] = (int)piVar7;
            return piVar4;
          }
        }
        else {
          strings_scanToken(in_EAX,param_1,0,0,0x67);
        }
      }
    }
    return (int *)0x0;
  }
  return piVar3;
}



// ============================================================
// Function: crypto_parseUnary (FUN_68145680)
// Address: 68145680
// Size: 244 bytes
// Params: uint * param_1, int param_2, uint * param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * crypto_parseUnary(uint *param_1,int param_2,uint *param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = crypto_parseCondExpr(param_2);
  if ((piVar2 != (int *)0x0) &&
     ((iVar3 = strings_parseExpression(param_1,param_2), iVar3 != 0x1d ||
      (iVar3 = crypto_consumeToken(4), iVar3 != -1)))) {
    if (iVar3 == 4) {
      iVar3 = *(int *)(param_2 + 0x10 + *(int *)(param_2 + 0x60) * 0x18);
      iVar1 = *piVar2;
      while (iVar1 == 0x1c) {
        piVar2 = (int *)piVar2[6];
        iVar1 = *piVar2;
      }
      switch(*piVar2) {
      case 0x16:
        piVar2[3] = 0x36;
        break;
      case 0x17:
        piVar2[3] = 0x38;
        break;
      default:
        strings_scanToken(param_1,param_2,0,0,0x81);
        return (int *)0x0;
      case 0x1b:
        piVar2[3] = 0x84;
        break;
      case 0x1d:
        piVar2[3] = 0x6d;
        if (piVar2[6] == *(int *)(param_1[5] + 0xd8)) {
          *param_3 = *param_3 | 0x80;
        }
      }
      crypto_parseUnary(param_1,param_2,param_3);
      piVar2 = crypto_createBinaryNode(param_3,param_1,4,iVar3);
      return piVar2;
    }
    strings_resetScanner(param_2);
    return piVar2;
  }
  return (int *)0x0;
}



// ============================================================
// Function: crypto_parseStatementBody (FUN_681457a0)
// Address: 681457a0
// Size: 1298 bytes
// Params: int param_1, uint * param_2
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * crypto_parseStatementBody(int param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined **ppuVar5;
  code *pcVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint *puVar10;
  bool bVar11;
  uint *in_EAX;
  undefined4 *puVar12;
  int iVar13;
  int *piVar14;
  uint *puVar15;
  undefined4 *puVar16;
  uint uVar17;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined **ppuVar18;
  code *pcVar19;
  code *pcVar20;
  int *local_3c;
  uint local_34;
  code *local_2c;
  code *local_24;
  uint *local_20;
  code *local_1c;
  code *local_14;
  uint local_c;
  
  puVar12 = crypto_createNode(param_2,0xfffffffe);
  if (puVar12 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar12[3] = *(undefined4 *)(param_1 + 0x10 + *(int *)(param_1 + 0x60) * 0x18);
  puVar12[9] = 0;
  puVar12[6] = 0;
  puVar12[7] = puVar12 + 6;
  puVar12[8] = 0;
  bVar1 = *(byte *)(in_EAX[0xd] + 0x4c);
  uVar8 = in_EAX[0xd];
  while (((bVar1 & 0xc) != 0 && (uVar2 = *(uint *)(uVar8 + 0x2c), uVar2 != 0))) {
    bVar1 = *(byte *)(uVar2 + 0x4c);
    uVar8 = uVar2;
  }
  piVar3 = *(int **)(uVar8 + 8);
  iVar4 = *(int *)(uVar8 + 0x10);
  ppuVar18 = (undefined **)(*(uint *)(piVar3[1] + 8) & 0xfffffffe);
  if (iVar4 != 0) {
    if (ppuVar18 == &PTR_s_Function_681928b8) {
      local_14 = certs_initVerifier;
      local_24 = certs_validatePath;
      goto LAB_6814585f;
    }
    if (ppuVar18 == &PTR_DAT_68192810) {
      local_14 = runtime_createObject;
      local_24 = runtime_deletePrototypeProperty;
      goto LAB_6814585f;
    }
  }
  local_14 = (code *)ppuVar18[4];
  local_24 = (code *)ppuVar18[5];
LAB_6814585f:
  local_c = 1;
  do {
    local_1c = local_14;
    local_2c = local_24;
    iVar13 = strings_parseExpression(in_EAX,param_1);
    if (iVar13 != 0x1d) {
      strings_scanToken(in_EAX,param_1,0,0,0x66);
      return (undefined4 *)0x0;
    }
    uVar2 = *(uint *)(param_1 + 0x14 + *(int *)(param_1 + 0x60) * 0x18);
    if ((int *)param_2[4] == (int *)0x0) {
      puVar10 = (uint *)param_2[3];
      puVar9 = param_2 + 3;
      while (puVar15 = puVar10, puVar15 != (uint *)0x0) {
        if (puVar15[2] == uVar2) {
          *puVar9 = *puVar15;
          *puVar15 = param_2[3];
          param_2[3] = (uint)puVar15;
          goto LAB_681459fe;
        }
        puVar9 = puVar15;
        puVar10 = (uint *)*puVar15;
      }
LAB_681458af:
      puVar15 = js_createAtom((int)in_EAX,uVar2,param_2 + 3);
      if (puVar15 == (uint *)0x0) {
        return (undefined4 *)0x0;
      }
    }
    else {
      piVar14 = crypto_findHashEntry((int *)param_2[4],*(int *)(uVar2 + 0x14),uVar2);
      puVar15 = (uint *)*piVar14;
      if (puVar15 == (uint *)0x0) goto LAB_681458af;
LAB_681459fe:
      if (puVar15 == (uint *)0x0) goto LAB_681458af;
      uVar7 = puVar15[3];
      if ((((in_EAX[0x59] & 1) != 0) || (puVar12[3] == 0x7e)) || (uVar7 == 0x7e)) {
        if ((puVar12[3] == 0x7e) || (local_34 = 5, uVar7 == 0x7e)) {
          local_34 = 0;
        }
        xtra_getStringValue((uint *)(*(uint *)(uVar2 + 8) & 0xfffffff8));
        uVar17 = strings_scanToken(in_EAX,param_1,0,local_34,0x9b);
        if (uVar17 == 0) {
          return (undefined4 *)0x0;
        }
      }
      if ((puVar12[3] == 0x7f) && (uVar7 == 0x4a)) {
        *param_2 = *param_2 | 0x20;
      }
    }
    puVar15[3] = puVar12[3];
    puVar16 = crypto_createNode(param_2,0xffffffff);
    if (puVar16 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar16[3] = 0x3b;
    puVar16[6] = uVar2;
    puVar16[7] = 0;
    puVar16[8] = 0xffffffff;
    puVar16[9] = (uint)(puVar12[3] == 0x7e) * 2 + 5;
    *(undefined4 **)puVar12[7] = puVar16;
    puVar12[8] = puVar12[8] + 1;
    puVar12[7] = puVar16 + 10;
    iVar13 = (**(code **)(*(int *)(*piVar3 + 4) + 8))();
    if (iVar13 == 0) {
      return (undefined4 *)0x0;
    }
    if ((local_3c == piVar3) &&
       ((ppuVar5 = *(undefined ***)(*local_3c + 4), ppuVar5 == &PTR_FUN_68192948 ||
        ((ppuVar5 != (undefined **)0x0 && (*ppuVar5 == PTR_FUN_68192948)))))) {
      if (local_20 == (uint *)0x0) goto LAB_68145b57;
      pcVar6 = (code *)local_20[1];
      if (pcVar6 == certs_executeVerify) {
        if (puVar12[3] == 0x7e) {
          xtra_getStringValue((uint *)(*(uint *)(uVar2 + 8) & 0xfffffff8));
          strings_scanToken(in_EAX,param_1,0,0,0xa4);
          local_c = 0;
        }
        else {
          xtra_getStringValue((uint *)(*(uint *)(uVar2 + 8) & 0xfffffff8));
          local_c = strings_scanToken(in_EAX,param_1,0,5,0x7f);
        }
      }
      else if (iVar4 != 0) {
        pcVar19 = local_14;
        pcVar20 = local_24;
        if (((ppuVar18 != &PTR_s_Function_681928b8) && (ppuVar18 == &PTR_DAT_68192810)) &&
           (pcVar6 != runtime_createObject)) {
          pcVar19 = pcVar6;
          pcVar20 = (code *)local_20[2];
        }
        iVar13 = runtime_setPropertyValue((uint)in_EAX,piVar3,local_20,0,(uint)(byte)local_20[4],pcVar19,pcVar20
                             );
        if (iVar13 == 0) {
          local_c = 0;
        }
      }
    }
    else {
      if (local_20 != (uint *)0x0) {
        pcVar6 = *(code **)(*(int *)(*local_3c + 4) + 0x34);
        if (pcVar6 != (code *)0x0) {
          (*pcVar6)();
        }
        local_20 = (uint *)0x0;
      }
LAB_68145b57:
      if (local_14 == runtime_createObject) {
        local_1c = (code *)ppuVar18[4];
        local_2c = (code *)ppuVar18[5];
      }
      if ((((local_1c == certs_initVerifier) && (uVar2 != *(uint *)(in_EAX[5] + 0xd8))) &&
          (*(int **)(uVar8 + 0x34) == piVar3)) && (iVar13 = javascript_objectStoreSlotDirect((int)param_2), iVar13 == 0)
         ) {
        iVar13 = runtime_callPropertyEx((uint)in_EAX,piVar3,uVar2,certs_initVerifier,local_2c,-1,puVar16[9] | 0x40,8
                              ,(uint)*(ushort *)(iVar4 + 0x14));
        if (iVar13 == 0) {
          local_c = 0;
        }
        *(short *)(iVar4 + 0x14) = *(short *)(iVar4 + 0x14) + 1;
      }
    }
    bVar11 = strings_compareRange(in_EAX,param_1,4);
    if (CONCAT31(extraout_var,bVar11) != 0) {
      if (*(int *)(param_1 + 0x10 + *(int *)(param_1 + 0x60) * 0x18) == 0) {
        piVar14 = crypto_parseUnary(in_EAX,param_1,param_2);
        puVar16[7] = piVar14;
        if (piVar14 == (int *)0x0) {
          local_c = 0;
        }
        else {
          puVar16[3] = (-(uint)(puVar12[3] != 0x7e) & 0x5f) + 0xe;
          if (uVar2 == *(uint *)(in_EAX[5] + 0xd8)) {
            *param_2 = *param_2 | 0x80;
          }
        }
      }
      else {
        strings_scanToken(in_EAX,param_1,0,0,0x80);
        local_c = 0;
      }
    }
    if ((local_20 != (uint *)0x0) &&
       (pcVar6 = *(code **)(*(int *)(*local_3c + 4) + 0x34), pcVar6 != (code *)0x0)) {
      (*pcVar6)();
    }
    if (local_c == 0) {
      return (undefined4 *)0x0;
    }
    bVar11 = strings_compareRange(in_EAX,param_1,3);
    if (CONCAT31(extraout_var_00,bVar11) == 0) {
      puVar12[2] = *(undefined4 *)(puVar12[7] + -0x20);
      return puVar12;
    }
  } while( true );
}



// ============================================================
// Function: crypto_parseExprPrimary (FUN_68147030)
// Address: 68147030
// Size: 339 bytes
// Params: uint * param_1, int * param_2, uint * param_3
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * crypto_parseExprPrimary(uint *param_1,int *param_2,uint *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint extraout_ECX;
  uint extraout_ECX_00;
  uint uVar4;
  int *extraout_EDX;
  int *extraout_EDX_00;
  int *piVar5;
  
  puVar1 = crypto_createNode(param_3,0xfffffffe);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1[6] = 0;
    puVar1[7] = puVar1 + 6;
    puVar1[8] = 0;
    param_2[0x1f] = param_2[0x1f] | 8;
    iVar2 = strings_initParser(param_1,(int)param_2);
    while( true ) {
      if ((iVar2 < 1) || (iVar2 == 0x1a)) goto LAB_6814715e;
      param_2[0x1f] = param_2[0x1f] & 0xfffffff7;
      piVar3 = crypto_bigMultiply(param_1,param_2,param_3);
      if (piVar3 == (int *)0x0) {
        return (undefined4 *)0x0;
      }
      param_2[0x1f] = param_2[0x1f] | 8;
      if ((param_3[2] == 0) && (uVar4 = *param_3, (uVar4 & 1) != 0)) break;
      *(int **)puVar1[7] = piVar3;
      puVar1[8] = puVar1[8] + 1;
      puVar1[7] = piVar3 + 10;
LAB_68147144:
      iVar2 = strings_initParser(param_1,(int)param_2);
    }
    piVar5 = (int *)param_1[0xd];
    if ((piVar5[4] == 0) || (((param_1[0x59] & 1) == 0 || ((uVar4 & 4) == 0)))) {
LAB_68147101:
      iVar2 = crypto_parsePrimary(uVar4,piVar5,(uint)param_1,piVar3,(int)param_3);
      if (((iVar2 != 0) && (iVar2 = javascript_objectSetParent((int)param_1,(int)param_3), iVar2 != 0)) &&
         (iVar2 = crypto_bigEval(param_1,param_3,piVar3), iVar2 != 0)) {
        crypto_advanceParser((int)param_3);
        goto LAB_68147144;
      }
    }
    else {
      iVar2 = strings_initParser(param_1,(int)param_2);
      if (((iVar2 != 0) && (uVar4 = extraout_ECX, piVar5 = extraout_EDX, iVar2 != 0x1a)) ||
         (iVar2 = crypto_validateToken(), uVar4 = extraout_ECX_00, piVar5 = extraout_EDX_00, iVar2 != 0)) {
        *param_3 = *param_3 & 0xfffffffb;
        goto LAB_68147101;
      }
    }
    iVar2 = -1;
LAB_6814715e:
    param_2[0x1f] = param_2[0x1f] & 0xfffffff7;
    if (iVar2 != -1) {
      puVar1[2] = param_2[param_2[0x18] * 6 + 2];
      return puVar1;
    }
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: crypto_compileFunction (FUN_68147190)
// Address: 68147190
// Size: 197 bytes
// Params: uint * param_1, int * param_2, int * param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_compileFunction(uint *param_1,int *param_2,int *param_3,uint *param_4)

{
  uint uVar1;
  int *piVar2;
  bool bVar3;
  int *piVar4;
  undefined4 *puVar5;
  undefined3 extraout_var;
  undefined1 local_5c [8];
  int *local_54;
  uint local_30;
  int *local_28;
  
  uVar1 = param_1[0xd];
  if (((uVar1 == 0) || (*(int *)(uVar1 + 8) == 0)) || (*(int **)(uVar1 + 0x34) != param_2)) {
    memset(local_5c,0,0x58);
    local_28 = param_2;
    local_54 = param_2;
    piVar2 = local_54;
    if ((param_1[0x59] & 4) != 0) {
      piVar4 = xtraRuntime_getObjectPointer(param_1,(int)param_2);
      piVar2 = local_54;
      while (local_54 = piVar4, local_54 != (int *)0x0) {
        piVar4 = xtraRuntime_getObjectPointer(param_1,(int)local_54);
        piVar2 = local_54;
      }
    }
    local_54 = piVar2;
    param_1[0xd] = (uint)local_5c;
    local_30 = uVar1;
  }
  *(int *)(param_1[5] + 0x48) = *(int *)(param_1[5] + 0x48) + 1;
  puVar5 = crypto_parseExprPrimary(param_1,param_3,param_4);
  if (puVar5 != (undefined4 *)0x0) {
    bVar3 = strings_compareRange(param_1,(int)param_3,0);
    if (CONCAT31(extraout_var,bVar3) != 0) {
      *(int *)(param_1[5] + 0x48) = *(int *)(param_1[5] + 0x48) + -1;
      param_1[0xd] = uVar1;
      return 1;
    }
    strings_scanToken(param_1,(int)param_3,0,0,0x85);
  }
  *(int *)(param_1[5] + 0x48) = *(int *)(param_1[5] + 0x48) + -1;
  param_1[0xd] = uVar1;
  return 0;
}



// ============================================================
// Function: crypto_compileVarDecl (FUN_68147260)
// Address: 68147260
// Size: 170 bytes
// Params: undefined4 param_1, int param_2, uint * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crypto_compileVarDecl(int *param_1,int param_2,uint *param_3)

{
  uint uVar1;
  uint *in_EAX;
  undefined4 *puVar2;
  int iVar3;
  undefined1 local_60 [8];
  int local_58;
  int local_50;
  uint local_34;
  int local_2c;
  uint local_8;
  
  uVar1 = in_EAX[0xd];
  iVar3 = *(int *)(param_2 + 4);
  if ((((uVar1 == 0) || (*(int *)(uVar1 + 0x10) != param_2)) || (*(int *)(uVar1 + 8) != iVar3)) ||
     (*(int *)(uVar1 + 0x34) != iVar3)) {
    memset(local_60,0,0x58);
    local_50 = param_2;
    in_EAX[0xd] = (uint)local_60;
    local_58 = iVar3;
    local_34 = uVar1;
    local_2c = iVar3;
  }
  local_8 = *param_3;
  *param_3 = local_8 & 0xfffffff3 | 2;
  puVar2 = crypto_parseExprPrimary(in_EAX,param_1,param_3);
  if (((puVar2 != (undefined4 *)0x0) && ((in_EAX[0x59] & 1) != 0)) &&
     (((*param_3 & 4) != 0 && (iVar3 = crypto_validateToken(), iVar3 == 0)))) {
    puVar2 = (undefined4 *)0x0;
  }
  in_EAX[0xd] = uVar1;
  *param_3 = *param_3 & 0xe0 | local_8;
  return (int)puVar2;
}



// ============================================================
// Function: crypto_compileScript (FUN_68147310)
// Address: 68147310
// Size: 228 bytes
// Params: uint param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_compileScript(uint param_1,int param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  byte local_f8 [156];
  undefined1 local_5c [8];
  undefined4 local_54;
  int local_4c;
  undefined4 local_30;
  undefined4 local_28;
  
  iVar2 = javascript_hashTableInsert(param_1,(undefined4 *)local_f8,*(undefined4 *)(param_2 + 0xac),
                       *(undefined4 *)(param_2 + 0x68),*(undefined4 *)(param_2 + 0xb4));
  if (iVar2 == 0) {
    return 0;
  }
  piVar3 = (int *)(*(int *)(param_1 + 0x14) + 0x48);
  *piVar3 = *piVar3 + 1;
  uVar1 = *(undefined4 *)(param_1 + 0x34);
  memset(local_5c,0,0x58);
  local_54 = *(undefined4 *)(param_3 + 4);
  *(undefined1 **)(param_1 + 0x34) = local_5c;
  local_4c = param_3;
  *(undefined4 *)(param_2 + *(int *)(param_2 + 0x60) * 0x18) = 0x19;
  local_30 = uVar1;
  local_28 = local_54;
  iVar2 = crypto_compileVarDecl(param_2,param_3,(uint *)local_f8);
  if (iVar2 != 0) {
    piVar3 = runtime_loadExternalScript(param_1,(int)local_f8,param_3);
    *(int **)(param_3 + 0xc) = piVar3;
    if (piVar3 != (int *)0x0) {
      if ((local_f8[0] & 0x80) != 0) {
        *(byte *)(param_3 + 0x16) = *(byte *)(param_3 + 0x16) | 0x80;
      }
      uVar4 = 1;
      goto LAB_681473d0;
    }
  }
  uVar4 = 0;
LAB_681473d0:
  *(undefined4 *)(param_1 + 0x34) = uVar1;
  piVar3 = (int *)(*(int *)(param_1 + 0x14) + 0x48);
  *piVar3 = *piVar3 + -1;
  javascript_hashTableLookup(param_1,(int)local_f8);
  return uVar4;
}



// ============================================================
// Function: crypto_compileExpression (FUN_68147400)
// Address: 68147400
// Size: 1123 bytes
// Params: uint * param_1, uint param_2, uint * param_3, int param_4
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * crypto_compileExpression(uint *param_1,uint param_2,uint *param_3,int param_4)

{
  short *psVar1;
  code *pcVar2;
  uint *puVar3;
  uint *puVar4;
  bool bVar5;
  undefined3 extraout_var;
  int *piVar6;
  int iVar7;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int *piVar8;
  uint *puVar9;
  uint uVar10;
  uint uVar11;
  undefined4 uVar12;
  uint local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_18;
  uint local_14;
  undefined4 *local_10;
  uint local_c;
  int *local_8;
  
  uVar10 = param_2;
  local_10 = crypto_createNode(param_3,0xfffffffd);
  if (local_10 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  local_18 = *(uint *)(param_2 + 0x10 + *(int *)(param_2 + 0x60) * 0x18);
  bVar5 = strings_compareRange(param_1,param_2,0x1d);
  if (CONCAT31(extraout_var,bVar5) == 0) {
    param_2 = 0;
  }
  else {
    param_2 = *(uint *)(param_2 + 0x14 + *(int *)(param_2 + 0x60) * 0x18);
  }
  piVar6 = runtime_createFunction((int)param_1,(int *)0x0,0,0,-(param_4 != 0) & 8,*(uint *)(param_1[0xd] + 8),
                        param_2);
  if (piVar6 == (int *)0x0) {
    return (undefined4 *)0x0;
  }
  if (local_18 != 0) {
    *(byte *)((int)piVar6 + 0x16) =
         *(byte *)((int)piVar6 + 0x16) | ((local_18 != 0x7b) - 1U & 0xf0) + 0x20;
  }
  iVar7 = strings_parseExpression(param_1,uVar10);
  if (iVar7 != 0x1b) {
    uVar12 = 0x45;
LAB_681474ac:
    strings_scanToken(param_1,uVar10,0,0,uVar12);
    return (undefined4 *)0x0;
  }
  bVar5 = strings_compareRange(param_1,uVar10,0x1c);
  if (CONCAT31(extraout_var_00,bVar5) == 0) {
    do {
      iVar7 = strings_parseExpression(param_1,uVar10);
      if (iVar7 != 0x1d) {
        uVar12 = 0x46;
        goto LAB_681474ac;
      }
      local_18 = *(uint *)(uVar10 + 0x14 + *(int *)(uVar10 + 0x60) * 0x18);
      local_8 = (int *)0x0;
      iVar7 = runtime_getProperty((uint)param_1,(int *)piVar6[1],local_18,&local_8,&local_c);
      if (iVar7 == 0) {
        return (undefined4 *)0x0;
      }
      uVar11 = 0;
      if (local_c != 0) {
        local_14 = 1;
        if ((local_8 == (int *)piVar6[1]) && (*(code **)(local_c + 4) == certs_executeVerify)) {
          xtra_getStringValue((uint *)(*(uint *)(local_18 + 8) & 0xfffffff8));
          local_14 = strings_scanToken(param_1,uVar10,0,5,0x6f);
          uVar11 = 2;
        }
        pcVar2 = *(code **)(*(int *)(*local_8 + 4) + 0x34);
        if (pcVar2 != (code *)0x0) {
          (*pcVar2)(param_1,local_8,local_c);
        }
        if (local_14 == 0) {
          return (undefined4 *)0x0;
        }
        local_c = 0;
      }
      iVar7 = runtime_callPropertyEx((uint)param_1,(undefined4 *)piVar6[1],local_18,certs_executeVerify,certs_verifyExtension,
                           -1,0x45,uVar11 | 8,(uint)*(ushort *)(piVar6 + 4));
      if (iVar7 == 0) {
        return (undefined4 *)0x0;
      }
      *(short *)(piVar6 + 4) = (short)piVar6[4] + 1;
      bVar5 = strings_compareRange(param_1,uVar10,3);
    } while (CONCAT31(extraout_var_01,bVar5) != 0);
    iVar7 = strings_parseExpression(param_1,uVar10);
    if (iVar7 != 0x1c) {
      uVar12 = 0x47;
      goto LAB_681474ac;
    }
  }
  iVar7 = strings_parseExpression(param_1,uVar10);
  if (iVar7 != 0x19) {
    uVar12 = 0x48;
    goto LAB_681474ac;
  }
  local_10[1] = *(undefined4 *)(uVar10 + 4 + *(int *)(uVar10 + 0x60) * 0x18);
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_14 = crypto_compileVarDecl(uVar10,(int)piVar6,&local_34);
  if (local_14 == 0) {
    return (undefined4 *)0x0;
  }
  iVar7 = strings_parseExpression(param_1,uVar10);
  if (iVar7 != 0x1a) {
    uVar12 = 0x49;
    goto LAB_681474ac;
  }
  local_10[2] = *(undefined4 *)(uVar10 + 8 + *(int *)(uVar10 + 0x60) * 0x18);
  if ((local_34 & 0x80) == 0) {
    if ((((param_4 == 0) && (param_2 != 0)) && (param_3[2] != 0)) || ((local_34 & 0x40) != 0)) {
      *param_3 = *param_3 | 0x80;
    }
  }
  else {
    *(byte *)((int)piVar6 + 0x16) = *(byte *)((int)piVar6 + 0x16) | 0x80;
    *param_3 = *param_3 | 0x80;
  }
  if ((param_4 != 0) || (param_2 == 0)) {
    uVar10 = (piVar6[6] != 0) + 0x80;
    goto LAB_6814783c;
  }
  if ((int *)param_3[4] == (int *)0x0) {
    puVar4 = (uint *)param_3[3];
    puVar3 = param_3 + 3;
    while (puVar9 = puVar4, puVar9 != (uint *)0x0) {
      if (puVar9[2] == param_2) {
        *puVar3 = *puVar9;
        *puVar9 = param_3[3];
        param_3[3] = (uint)puVar9;
        goto LAB_68147791;
      }
      puVar3 = puVar9;
      puVar4 = (uint *)*puVar9;
    }
LAB_681476d1:
    puVar9 = js_createAtom((int)param_1,param_2,param_3 + 3);
    if (puVar9 == (uint *)0x0) {
      return (undefined4 *)0x0;
    }
  }
  else {
    piVar8 = crypto_findHashEntry((int *)param_3[4],*(int *)(param_2 + 0x14),param_2);
    puVar9 = (uint *)*piVar8;
    if (puVar9 == (uint *)0x0) goto LAB_681476d1;
LAB_68147791:
    if (puVar9 == (uint *)0x0) goto LAB_681476d1;
    local_18 = puVar9[3];
    if (((param_1[0x59] & 1) != 0) || (local_18 == 0x7e)) {
      xtra_getStringValue((uint *)(*(uint *)(param_2 + 8) & 0xfffffff8));
      uVar10 = strings_scanToken(param_1,uVar10,0,-(uint)(local_18 != 0x7e) & 5,0x9b);
      if (uVar10 == 0) {
        return (undefined4 *)0x0;
      }
    }
    if ((param_3[2] != 0) && (local_18 == 0x7f)) {
      *param_3 = *param_3 | 0x20;
    }
  }
  puVar9[3] = (-(uint)(param_3[2] != 0) & 0xffffffcd) + 0x7d;
  if ((param_3[2] == 0) && ((*param_3 & 2) != 0)) {
    uVar10 = param_1[0xd];
    iVar7 = runtime_invokeMethod((uint)param_1,*(int **)(uVar10 + 8),param_2,piVar6[1],0x681541c0,0x681541f0
                         ,1,8,(uint)*(ushort *)(*(int *)(uVar10 + 0x10) + 0x14),(undefined4 *)0x0);
    if (iVar7 == 0) {
      return (undefined4 *)0x0;
    }
    psVar1 = (short *)(*(int *)(uVar10 + 0x10) + 0x14);
    *psVar1 = *psVar1 + 1;
  }
  uVar10 = -(uint)(param_3[2] != 0) & 0x4a;
LAB_6814783c:
  local_10[3] = uVar10;
  local_10[6] = piVar6;
  local_10[7] = local_14;
  local_10[8] = local_34 & 0xe0;
  local_10[9] = local_30;
  return local_10;
}



// ============================================================
// Function: crypto_compileExprFast (FUN_68147870)
// Address: 68147870
// Size: 11 bytes
// Params: uint param_1, uint * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall crypto_compileExprFast(uint param_1,uint *param_2)
{
  uint *in_EAX;
  
  crypto_compileExpression(param_2,param_1,in_EAX,1);
  return 0;
}



