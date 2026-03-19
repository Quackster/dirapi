// Module: stage
// Topic: Code generation utilities and token helpers
// Address range: 0x680533B0 - 0x68053F70
// Functions (36):
//   stage_parseCondition (FUN_680533B0)
//   props_searchSymbolTable (FUN_680533f0)
//   stage_resolveSymbol (FUN_68053410)
//   stage_parseAssignment (stage_parseAssignment)
//   stage_checkLiteralType (FUN_68053460)
//   stage_checkConditionType (FUN_680534C0)
//   stage_emitLoadConst (stage_emitLoadConst)
//   stage_resolveAndLookup (FUN_68053560)
//   stage_parseAndResolve (FUN_680535A0)
//   stage_resolveIdentifier (FUN_680535C0)
//   stage_emitPushIfNeeded (stage_emitPushIfNeeded)
//   stage_emitOpcode (stage_emitOpcode)
//   stage_emitReturnOpcode (FUN_680536E0)
//   stage_emitInstruction (stage_emitInstruction)
//   stage_emitExtendedBranch (FUN_680537A0)
//   stage_emitBranchCond (FUN_680537E0)
//   stage_emitLongImmediate (FUN_68053810)
//   stage_emitBranch (stage_emitBranch)
//   stage_emitString (FUN_680538F0)
//   stage_emitJump (stage_emitJump)
//   stage_emitJumpTarget (FUN_680539E0)
//   stage_emitConditionalJump (FUN_68053A20)
//   stage_checkIsEndToken (FUN_68053A50)
//   stage_getCodegenState (FUN_68053A70)
//   stage_checkIsConstOrEnd (FUN_68053AA0)
//   stage_checkIsEndOrProperty (FUN_68053AD0)
//   stage_compileRepeatHeader (FUN_68053B00)
//   stage_compileParameterList (FUN_68053BF0)
//   stage_freeSymbolTables (FUN_68053D50)
//   stage_freeCodegenContext (FUN_68053DE0)
//   stage_allocDispatchLarge (FUN_68053F10)
//   stage_allocDispatchMedium (FUN_68053F20)
//   stage_allocDispatchSmall (FUN_68053F30)
//   stage_allocSmallBytecode (FUN_68053F40)
//   stage_emitSingleByte (FUN_68053F50)
//   stage_emitMultiByte (FUN_68053F70)

// ============================================================
// Function: stage_parseCondition (FUN_680533b0)
// Address: 680533b0
// Size: 51 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_parseCondition(int param_1,int *param_2,int *param_3)

{
  *param_3 = -1;
  stage_pushCurrentScope(param_1);
  if (*param_2 == 8) {
    *param_3 = param_2[1];
  }
  return *param_3 != -1;
}



// ============================================================
// Function: props_searchSymbolTable (FUN_680533f0)
// Address: 680533f0
// Size: 26 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_searchSymbolTable(undefined4 param_1,undefined4 param_2)
{
  props_setParserState(param_1,param_2,0);
  return 0;
}



// ============================================================
// Function: stage_resolveSymbol (FUN_68053410)
// Address: 68053410
// Size: 31 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_resolveSymbol(int param_1,undefined4 *param_2)
{
  props_pushTokenEntry(*(int *)(**(int **)(param_1 + 8) + 0x420),param_2);
  return 0;
}



// ============================================================
// Function: stage_parseAssignment (FUN_68053430)
// Address: 68053430
// Size: 35 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_parseAssignment(int param_1,int *param_2,int *param_3)

{
  stage_parseCondition(param_1,param_2,(int *)&param_2);
  return param_2 == param_3;
}



// ============================================================
// Function: stage_checkLiteralType (FUN_68053460)
// Address: 68053460
// Size: 82 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_checkLiteralType(int param_1)

{
  undefined4 local_c;
  undefined4 local_8;
  
  stage_pushCurrentScope(param_1);
  if ((local_c == 8) && ((local_8 == (int *)0x30 || (local_8 == (int *)0x15)))) {
    return 1;
  }
  stage_emitPushLiteral(param_1,10);
  props_releaseValue(param_1,(byte)local_c,local_8);
  return 0;
}



// ============================================================
// Function: stage_checkConditionType (FUN_680534c0)
// Address: 680534c0
// Size: 59 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_checkConditionType(int param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int local_c [2];
  
  bVar1 = stage_parseCondition(param_1,local_c,&param_1);
  if ((CONCAT31(extraout_var,bVar1) != 0) && ((param_1 == 0x3e || (param_1 == 0x5f)))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_emitLoadConst (FUN_68053500)
// Address: 68053500
// Size: 81 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitLoadConst(int param_1,uint param_2)
{
  undefined1 *puVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar4 = **(int **)(**(int **)(param_1 + 8) + 0x498);
  iVar5 = *(int *)(iVar4 + 0x10);
  while (param_2 != 0) {
    uVar2 = *(undefined1 *)(iVar4 + 2 + param_2);
    iVar6 = iVar5 - param_2;
    puVar1 = (undefined1 *)(iVar4 + 1 + param_2);
    uVar3 = *puVar1;
    *puVar1 = (char)((uint)iVar6 >> 8);
    *(char *)(iVar4 + 2 + param_2) = (char)iVar6;
    param_2 = (uint)CONCAT11(uVar3,uVar2);
  }
  return 0;
}



// ============================================================
// Function: stage_resolveAndLookup (FUN_68053560)
// Address: 68053560
// Size: 52 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_resolveAndLookup(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  
  puVar1 = param_2;
  props_parseExpression(param_1,param_2);
  score_resolveSymbolName(**(int **)(param_1 + 8),DAT_68196304,(byte *)(puVar1 + 7),(uint *)&param_2,0);
  return 0;
}



// ============================================================
// Function: stage_parseAndResolve (FUN_680535a0)
// Address: 680535a0
// Size: 32 bytes
// Params: int param_1, int * param_2, byte * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_parseAndResolve(int param_1,int *param_2,byte *param_3)
{
  props_parseIdentifier(param_2,param_3);
  stage_resolveAndLookup(param_1,param_2);
  return 0;
}



// ============================================================
// Function: stage_resolveIdentifier (FUN_680535c0)
// Address: 680535c0
// Size: 132 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_resolveIdentifier(int param_1,int *param_2)
{
  int iVar1;
  int local_864 [279];
  byte local_408 [1024];
  uint local_8;
  
  if ((*param_2 != 0x40) && (*param_2 != 0x43)) {
    return 0;
  }
  props_toPascalString(param_2,local_408);
  *param_2 = 8;
  iVar1 = stage_parseAndResolve(param_1,local_864,local_408);
  param_2[1] = iVar1;
  return 0;
}



// ============================================================
// Function: stage_emitPushIfNeeded (FUN_68053650)
// Address: 68053650
// Size: 38 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_emitPushIfNeeded(int param_1)

{
  if (DAT_68195a8c == 0) {
    return 1;
  }
  stage_emitPushLiteral(param_1,1);
  return 0;
}



// ============================================================
// Function: stage_emitOpcode (FUN_68053680)
// Address: 68053680
// Size: 88 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitOpcode(int param_1,undefined4 param_2,int param_3)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(**(int **)(param_1 + 8) + 0x4c8);
  *piVar1 = *piVar1 + param_3;
  iVar2 = **(int **)(param_1 + 8);
  if (*(int *)(iVar2 + 0x4c4) < *(int *)(iVar2 + 0x4c8)) {
    *(undefined4 *)(iVar2 + 0x4c4) = *(undefined4 *)(iVar2 + 0x4c8);
  }
  stage_emitBytecode(*(int **)(**(int **)(param_1 + 8) + 0x498),(undefined1 *)&param_2,1);
  stage_emitPushIfNeeded(param_1);
  return 0;
}



// ============================================================
// Function: stage_emitReturnOpcode (FUN_680536e0)
// Address: 680536e0
// Size: 51 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitReturnOpcode(int param_1)
{
  if ((*(byte *)(**(int **)(**(int **)(param_1 + 8) + 0x428) + 0x54) & 0x10) != 0) {
    stage_emitOpcode(param_1,2,0);
    return 0;
  }
  stage_emitOpcode(param_1,1,0);
  return 0;
}



// ============================================================
// Function: stage_emitInstruction (stage_emitInstruction)
// Address: 68053720
// Size: 126 bytes
// Params: int param_1, int param_2, uint param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitInstruction(int param_1,int param_2,uint param_3,int param_4)
{
  uint uVar1;
  
  if ((param_3 & 0xff) != param_3) {
    if ((param_3 & 0xffff) == param_3) {
      uVar1 = (uint)(byte)((char)param_2 + 0x40);
    }
    else {
      stage_emitOpcode(param_1,(uint)(byte)((char)param_2 + 0x80),param_4);
      stage_emitOpcode(param_1,(int)param_3 >> 0x18,0);
      param_4 = 0;
      uVar1 = (int)param_3 >> 0x10;
    }
    stage_emitOpcode(param_1,uVar1,param_4);
    param_4 = 0;
    param_2 = (int)param_3 >> 8;
  }
  stage_emitOpcode(param_1,param_2,param_4);
  stage_emitOpcode(param_1,param_3,0);
  return 0;
}



// ============================================================
// Function: stage_emitExtendedBranch (FUN_680537a0)
// Address: 680537a0
// Size: 60 bytes
// Params: int param_1, char param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitExtendedBranch(int param_1,char param_2,int param_3,int param_4)
{
  stage_emitOpcode(param_1,(uint)(byte)(param_2 + 0x40),param_4);
  stage_emitOpcode(param_1,param_3 >> 8,0);
  stage_emitOpcode(param_1,param_3,0);
  return 0;
}



// ============================================================
// Function: stage_emitBranchCond (FUN_680537e0)
// Address: 680537e0
// Size: 33 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitBranchCond(int param_1,uint param_2)
{
  uint uVar1;
  int iVar2;
  
  iVar2 = 1;
  uVar1 = props_resolveSymbol(param_1,param_2);
  stage_emitInstruction(param_1,0x45,uVar1,iVar2);
  return 0;
}



// ============================================================
// Function: stage_emitLongImmediate (FUN_68053810)
// Address: 68053810
// Size: 81 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitLongImmediate(int param_1,int param_2)
{
  stage_emitOpcode(param_1,0xf1,1);
  stage_emitOpcode(param_1,param_2 >> 0x18,0);
  stage_emitOpcode(param_1,param_2 >> 0x10,0);
  stage_emitOpcode(param_1,param_2 >> 8,0);
  stage_emitOpcode(param_1,param_2,0);
  return 0;
}



// ============================================================
// Function: stage_emitBranch (FUN_68053870)
// Address: 68053870
// Size: 128 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitBranch(int param_1,int param_2)
{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  if (param_2 == 0) {
    stage_emitOpcode(param_1,3,1);
    return 0;
  }
  iVar3 = 1;
  if ((char)param_2 == param_2) {
    iVar2 = 0x41;
  }
  else {
    bVar1 = (short)param_2 != param_2;
    if (bVar1) {
      stage_emitOpcode(param_1,0xef,1);
      stage_emitOpcode(param_1,param_2 >> 0x18,0);
      iVar3 = param_2 >> 0x10;
    }
    else {
      iVar3 = 0xae;
    }
    stage_emitOpcode(param_1,iVar3,(uint)!bVar1);
    iVar3 = 0;
    iVar2 = param_2 >> 8;
  }
  stage_emitOpcode(param_1,iVar2,iVar3);
  stage_emitOpcode(param_1,param_2,0);
  return 0;
}



// ============================================================
// Function: stage_emitString (FUN_680538f0)
// Address: 680538f0
// Size: 94 bytes
// Params: int param_1, int * param_2, undefined1 * param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitString(int param_1,int *param_2,undefined1 *param_3,uint param_4)
{
  int iVar1;
  undefined4 local_8;
  
  local_8 = 0;
  stage_emitBytecode(param_2,param_3,param_4);
  iVar1 = stage_emitPushIfNeeded(param_1);
  if (iVar1 != 0) {
    if ((param_4 & 3) != 0) {
      stage_emitBytecode(param_2,(undefined1 *)&local_8,4 - (param_4 & 3));
      iVar1 = stage_emitPushIfNeeded(param_1);
      if (iVar1 == 0) {
        return 0;
      }
    }
    stage_emitPushIfNeeded(param_1);
  }
  return 0;
}



// ============================================================
// Function: stage_emitJump (FUN_68053950)
// Address: 68053950
// Size: 137 bytes
// Params: int param_1, int * param_2, int * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitJump(int param_1,int *param_2,int *param_3,int param_4)
{
  int local_18;
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 *puVar7;
  
  iVar1 = *(int *)(*param_2 + 0x10);
  stage_emitPushVar(param_2,iVar1 + param_4 * 4);
  iVar4 = stage_emitPushIfNeeded(param_1);
  if (iVar4 != 0) {
    puVar7 = (undefined4 *)(*param_2 + iVar1);
    if (0 < param_4) {
      for (; param_4 != 0; param_4 = param_4 + -1) {
        *puVar7 = 0xffffffff;
        puVar7 = puVar7 + 1;
      }
    }
    iVar4 = *(int *)(*param_3 + 0x14) + -1;
    if (-1 < iVar4) {
      iVar6 = iVar4 * 0x10;
      do {
        uVar2 = *(uint *)(*param_3 + 0x24 + iVar6);
        if (uVar2 != 0xffffffff) {
          iVar3 = *(int *)(*param_3 + iVar6 + 0x30);
          uVar5 = props_resolveSymbol(param_1,uVar2);
          *(undefined4 *)(*param_2 + iVar3 * 4 + iVar1) = uVar5;
        }
        iVar6 = iVar6 + -0x10;
        iVar4 = iVar4 + -1;
      } while (-1 < iVar4);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_emitJumpTarget (FUN_680539e0)
// Address: 680539e0
// Size: 58 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitJumpTarget(int param_1,int param_2,int *param_3)
{
  int iVar1;
  
  iVar1 = *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x498) + 0x10);
  stage_emitExtendedBranch(param_1,(char)param_2,*param_3,(param_2 != 0x55) - 1);
  *param_3 = iVar1;
  return 0;
}



// ============================================================
// Function: stage_emitConditionalJump (FUN_68053a20)
// Address: 68053a20
// Size: 47 bytes
// Params: int param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitConditionalJump(int param_1,int param_2,uint param_3)
{
  if (param_2 < 4) {
    stage_emitInstruction(param_1,0x46,param_3,1);
    return 0;
  }
  stage_emitBranch(param_1,param_3);
  return 0;
}



// ============================================================
// Function: stage_checkIsEndToken (FUN_68053a50)
// Address: 68053a50
// Size: 32 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_checkIsEndToken(int *param_1)

{
  if ((*param_1 == 8) && (param_1[1] == 0x3e)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_getCodegenState (FUN_68053a70)
// Address: 68053a70
// Size: 39 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_getCodegenState(int *param_1)

{
  if ((*param_1 == 8) && ((param_1[1] == 0x30 || (param_1[1] == 0x15)))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_checkIsConstOrEnd (FUN_68053aa0)
// Address: 68053aa0
// Size: 39 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_checkIsConstOrEnd(int *param_1)

{
  if ((*param_1 == 8) && ((param_1[1] == 0x30 || (param_1[1] == 0x3e)))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_checkIsEndOrProperty (FUN_68053ad0)
// Address: 68053ad0
// Size: 39 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_checkIsEndOrProperty(int *param_1)

{
  if ((*param_1 == 8) && ((param_1[1] == 0x3e || (param_1[1] == 0x5f)))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_compileRepeatHeader (FUN_68053b00)
// Address: 68053b00
// Size: 228 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_compileRepeatHeader(int param_1)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  int local_18 [2];
  int local_10 [2];
  int local_8;
  
  iVar1 = param_1;
  bVar2 = stage_parseCondition(param_1,local_10,&param_1);
  if ((CONCAT31(extraout_var,bVar2) != 0) && (param_1 == 0x69)) {
    bVar2 = stage_parseCondition(iVar1,local_18,&local_8);
    if ((CONCAT31(extraout_var_00,bVar2) != 0) && (local_8 - 0x20U < 4)) {
      bVar2 = stage_parseCondition(iVar1,local_10,&param_1);
      if ((CONCAT31(extraout_var_01,bVar2) != 0) && (param_1 == 0x3e)) {
        stage_emitBranch(iVar1,-0x7510 - local_8);
        stage_emitBranch(iVar1,0);
        stage_emitBranch(iVar1,0);
        stage_emitBranch(iVar1,0);
        stage_emitBranch(iVar1,0);
        stage_emitBranch(iVar1,0);
        stage_emitBranch(iVar1,0);
        stage_emitBranch(iVar1,0);
        return 1;
      }
      stage_emitPushLiteral(iVar1,0x12);
      return 0;
    }
    stage_resolveSymbol(iVar1,local_18);
  }
  stage_resolveSymbol(iVar1,local_10);
  return 0;
}



// ============================================================
// Function: stage_compileParameterList (FUN_68053bf0)
// Address: 68053bf0
// Size: 337 bytes
// Params: int param_1, int * param_2, uint param_3, int param_4, int param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x68053d05) */
/* WARNING: Removing unreachable block (ram,0x68053d0b) */

uint stage_compileParameterList(int param_1,int *param_2,uint param_3,int param_4,int param_5)

{
  bool bVar1;
  uint *puVar2;
  uint uVar3;
  int local_10;
  uint local_c;
  
  bVar1 = false;
  stage_pushCurrentScope(param_1);
  uVar3 = param_3;
  if (local_10 == 0) {
    return param_3;
  }
  do {
    if ((local_10 == 8) && (0x2e < (int)local_c)) {
      puVar2 = score_lookupProperty(param_2,local_c,1,(uint *)0x0);
      if (puVar2 == (uint *)0x0) {
        stage_emitPushLiteral(param_1,1);
        return uVar3;
      }
      if ((*puVar2 != 2) && (param_4 == 0)) {
        stage_emitPushLiteral(param_1,6);
        return uVar3;
      }
      puVar2[1] = uVar3;
      *puVar2 = 4;
      uVar3 = uVar3 + 1;
      stage_pushCurrentScope(param_1);
      if (local_c != 3) {
        if ((bVar1) && (local_c == 5)) {
          return uVar3;
        }
        stage_emitPushLiteral(param_1,5);
        return uVar3;
      }
    }
    else {
      if ((uVar3 != param_3) || (((param_5 == 0 || (local_10 != 8)) || (local_c != 4)))) {
        if (((bVar1) && (local_10 == 8)) && (local_c == 5)) {
          return uVar3;
        }
        stage_emitPushLiteral(param_1,3);
        return uVar3;
      }
      bVar1 = true;
    }
    stage_pushCurrentScope(param_1);
    if (local_10 == 0) {
      return uVar3;
    }
  } while( true );
}



// ============================================================
// Function: stage_freeSymbolTables (FUN_68053d50)
// Address: 68053d50
// Size: 141 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_freeSymbolTables(void)
{
  undefined4 uVar1;
  int unaff_ESI;
  
  uVar1 = score_freePropertyHandle(*(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x48c));
  *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x48c) = uVar1;
  uVar1 = score_freePropertyHandle(*(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x490));
  *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x490) = uVar1;
  uVar1 = score_freePropertyHandle(*(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x494));
  *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x494) = uVar1;
  uVar1 = cast_freeHandle(*(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x498));
  *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x498) = uVar1;
  uVar1 = cast_freeHandle(*(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x49c));
  *(undefined4 *)(**(int **)(unaff_ESI + 8) + 0x49c) = uVar1;
  return 0;
}



// ============================================================
// Function: stage_freeCodegenContext (FUN_68053de0)
// Address: 68053de0
// Size: 293 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_freeCodegenContext(uint param_1)
{
  undefined4 uVar1;
  
  if (*(int *)(**(int **)(param_1 + 8) + 0x428) != 0) {
    *(undefined4 *)(**(int **)(**(int **)(param_1 + 8) + 0x428) + 4) = 1;
    props_releaseContext(param_1,*(int **)(**(int **)(param_1 + 8) + 0x428));
  }
  uVar1 = score_freePropertyHandle(*(undefined4 *)(**(int **)(param_1 + 8) + 0x42c));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x42c) = uVar1;
  uVar1 = cast_freeHandle(*(undefined4 *)(**(int **)(param_1 + 8) + 0x430));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x430) = uVar1;
  uVar1 = cast_freeHandle(*(undefined4 *)(**(int **)(param_1 + 8) + 0x438));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x438) = uVar1;
  props_releaseObject(param_1,*(int **)(**(int **)(param_1 + 8) + 0x434));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x434) = 0;
  uVar1 = cast_freeHandle(*(undefined4 *)(**(int **)(param_1 + 8) + 0x43c));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x43c) = uVar1;
  uVar1 = score_freePropertyHandle(*(undefined4 *)(**(int **)(param_1 + 8) + 0x440));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x440) = uVar1;
  uVar1 = score_freePropertyHandle(*(undefined4 *)(**(int **)(param_1 + 8) + 0x444));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x444) = uVar1;
  uVar1 = cast_freeHandle(*(undefined4 *)(**(int **)(param_1 + 8) + 0x448));
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x448) = uVar1;
  stage_freeSymbolTables();
  return 0;
}



// ============================================================
// Function: stage_allocDispatchLarge (FUN_68053f10)
// Address: 68053f10
// Size: 14 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_allocDispatchLarge(void)
{
  stage_allocDispatchEntry(0x5c,0x20,0x3c,0x14);
  return 0;
}



// ============================================================
// Function: stage_allocDispatchMedium (FUN_68053f20)
// Address: 68053f20
// Size: 14 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_allocDispatchMedium(void)
{
  stage_allocDispatchEntry(0x28,0x20,8,0x32);
  return 0;
}



// ============================================================
// Function: stage_allocDispatchSmall (FUN_68053f30)
// Address: 68053f30
// Size: 14 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_allocDispatchSmall(void)
{
  stage_allocDispatchEntry(0x28,0x20,8,0x14);
  return 0;
}



// ============================================================
// Function: stage_allocSmallBytecode (FUN_68053f40)
// Address: 68053f40
// Size: 12 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_allocSmallBytecode(void)
{
  stage_createBytecodeBlock(0x20,0x1c,0x32);
  return 0;
}



// ============================================================
// Function: stage_emitSingleByte (FUN_68053f50)
// Address: 68053f50
// Size: 19 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_emitSingleByte(int *param_1)
{
  stage_emitBytecode(param_1,&stack0x00000004,1);
  return 0;
}



// ============================================================
// Function: stage_emitMultiByte (FUN_68053f70)
// Address: 68053f70
// Size: 66 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitMultiByte(void)
{
  int in_EAX;
  int unaff_EBX;
  int *unaff_EDI;
  
  DAT_681962c0 = *(undefined4 *)(*unaff_EDI + 0x10);
  if (0x7f < unaff_EBX) {
    stage_emitSingleByte(unaff_EDI);
  }
  stage_emitSingleByte(unaff_EDI);
  for (; 0 < in_EAX; in_EAX = in_EAX + -1) {
    stage_emitSingleByte(unaff_EDI);
  }
  return 0;
}



