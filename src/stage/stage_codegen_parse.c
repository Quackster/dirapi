// Module: stage
// Topic: Parser: statements and tokenization
// Address range: 0x68055670 - 0x68055CC0
// Functions (12):
//   stage_parseDeclaration (stage_parseDeclaration)
//   stage_advanceParser (FUN_680556B0)
//   stage_getParseState (FUN_680556F0)
//   stage_emitParseOffset (FUN_68055710)
//   stage_parseConditionalBranch (FUN_68055750)
//   stage_matchTokenType (FUN_68055930)
//   stage_collectLocalVars (FUN_68055950)
//   stage_destroyParseContext (FUN_68055A70)
//   stage_allocParseDispatch (FUN_68055AA0)
//   stage_storeProperty (FUN_68055AB0)
//   stage_initCharacterTable (FUN_68055AE0)
//   stage_initParserModule (FUN_68055CC0)

// ============================================================
// Function: stage_parseDeclaration (FUN_68055670)
// Address: 68055670
// Size: 52 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_parseDeclaration(int param_1)
{
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4a0) =
       *(undefined4 *)(**(int **)(**(int **)(param_1 + 8) + 0x498) + 0x10);
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x4a4) =
       *(undefined4 *)(*(int *)(**(int **)(param_1 + 8) + 0x420) + 0x14);
  return 0;
}



// ============================================================
// Function: stage_advanceParser (FUN_680556B0)
// Address: 680556b0
// Size: 56 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_advanceParser(void)
{
  stage_emitMultiByte();
  return 0;
}



// ============================================================
// Function: stage_getParseState (FUN_680556f0)
// Address: 680556f0
// Size: 31 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getParseState(void)
{
  stage_advanceParser();
  return 0;
}



// ============================================================
// Function: stage_emitParseOffset (FUN_68055710)
// Address: 68055710
// Size: 61 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitParseOffset(int param_1)
{
  int *piVar1;
  int iVar2;
  
  iVar2 = *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x498) + 0x10) -
          *(int *)(**(int **)(param_1 + 8) + 0x4a0);
  stage_addBytecodeOffset(iVar2);
  piVar1 = (int *)(**(int **)(param_1 + 8) + 0x4a0);
  *piVar1 = *piVar1 + iVar2;
  return 0;
}



// ============================================================
// Function: stage_parseConditionalBranch (FUN_68055750)
// Address: 68055750
// Size: 390 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_parseConditionalBranch(void *param_1)
{
  undefined4 *puVar1;
  void *this;
  bool bVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  uint uVar6;
  int local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  this = param_1;
  bVar2 = stage_parseCondition((int)param_1,&local_14,&local_8);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    stage_emitPushLiteral((int)param_1,3);
    return 0;
  }
  switch(local_8) {
  case 0x39:
    param_1 = (void *)0x2;
    break;
  case 0x3a:
    param_1 = (void *)0x1;
    break;
  default:
    stage_emitPushLiteral((int)param_1,0x21);
    return 0;
  case 0x4a:
    param_1 = (void *)0x3;
    break;
  case 0x56:
    param_1 = (void *)0x5;
    break;
  case 0x6a:
    param_1 = (void *)0x4;
  }
  bVar2 = stage_parseCondition((int)this,&local_14,&local_c);
  if ((CONCAT31(extraout_var_00,bVar2) != 0) && (local_c == 0x1d)) {
    iVar3 = props_peekNextOffset();
    uVar6 = iVar3 - *(int *)(*(int *)(**(int **)((int)this + 8) + 0x420) + 4);
    piVar4 = (int *)cast_allocHandle(uVar6 + 1,0);
    if (piVar4 != (int *)0x0) {
      puVar1 = *(undefined4 **)(**(int **)((int)this + 8) + 0x420);
      Ordinal_1129(*piVar4,puVar1[1] + *(int *)*puVar1,uVar6);
      *(undefined1 *)(uVar6 + *piVar4) = 0;
      puVar5 = (undefined1 *)Ordinal_1114(piVar4);
      stage_emitConstant(this,uVar6,puVar5);
      Ordinal_1115(piVar4);
      if (*(int *)(**(int **)((int)this + 8) + 0x41c) == 0) {
        stage_emitBranch((int)this,(int)param_1);
        stage_emitInstruction((int)this,0x5d,0,-2);
      }
      cast_freeHandle(piVar4);
      stage_pushCurrentScope((int)this);
      while (local_14 != 0) {
        props_releaseValue(this,(byte)local_14,local_10);
        stage_pushCurrentScope((int)this);
      }
    }
    return 0;
  }
  stage_emitPushLiteral((int)this,0xf);
  return 0;
}



// ============================================================
// Function: stage_matchTokenType (FUN_68055930)
// Address: 68055930
// Size: 28 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_matchTokenType(int param_1)

{
  int in_EAX;
  
  if ((in_EAX != param_1) && (in_EAX != 99)) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: stage_collectLocalVars (FUN_68055950)
// Address: 68055950
// Size: 280 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall stage_collectLocalVars(void *this,int param_1)
{
  int iVar1;
  bool bVar2;
  uint in_EAX;
  undefined3 extraout_var;
  int iVar3;
  undefined3 extraout_var_00;
  uint uVar4;
  int local_14;
  int *local_10;
  undefined4 local_c;
  int local_8;
  
  iVar1 = *(int *)(**(int **)((int)this + 8) + 0x420);
  local_c = *(undefined4 *)(iVar1 + 0x14);
  iVar1 = *(int *)(iVar1 + 4);
  bVar2 = props_isParserReady(*(int *)(**(int **)((int)this + 8) + 0x420));
  iVar3 = CONCAT31(extraout_var,bVar2);
  do {
    if ((iVar3 != 0) || (*(int *)(**(int **)((int)this + 8) + 0x41c) != 0)) {
      props_resetParserPosition(*(int *)(**(int **)((int)this + 8) + 0x420),iVar1);
      *(undefined4 *)(*(int *)(**(int **)((int)this + 8) + 0x420) + 0x14) = local_c;
      return 0;
    }
    stage_parseCondition((int)this,&local_14,&local_8);
    iVar3 = stage_matchTokenType(param_1);
    if (iVar3 == 0) {
      props_releaseValue(this,(byte)local_14,local_10);
    }
    else {
      stage_pushCurrentScope((int)this);
      if ((local_14 != 8) || ((int)local_10 < 0x2f)) {
        stage_emitPushLiteral((int)this,2);
        props_releaseValue(this,(byte)local_14,local_10);
        return 0;
      }
      uVar4 = in_EAX;
      props_resolveSymbol((int)this,(uint)local_10);
      stage_updateSymbolEntry(uVar4);
      in_EAX = in_EAX + 1;
    }
    props_getCurrentToken();
    bVar2 = props_isParserReady(*(int *)(**(int **)((int)this + 8) + 0x420));
    iVar3 = CONCAT31(extraout_var_00,bVar2);
  } while( true );
}



// ============================================================
// Function: stage_destroyParseContext (FUN_68055A70)
// Address: 68055a70
// Size: 45 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_destroyParseContext(int param_1)
{
  score_freePropertyHandle(*(undefined4 *)(param_1 + 0x10));
  cast_freeHandle(*(undefined4 *)(param_1 + 0xc));
  score_freePropertyHandle(*(undefined4 *)(param_1 + 8));
  props_destroyRuntime(param_1);
  return 0;
}



// ============================================================
// Function: stage_allocParseDispatch (FUN_68055AA0)
// Address: 68055aa0
// Size: 14 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_allocParseDispatch(void)
{
  stage_allocDispatchEntry(0x30,0x20,0x10,0x32);
  return 0;
}



// ============================================================
// Function: stage_storeProperty (FUN_68055ab0)
// Address: 68055ab0
// Size: 43 bytes
// Params: int param_1, uint param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_storeProperty(int param_1,uint param_2,uint param_3)
{
  uint *puVar1;
  
  puVar1 = score_lookupProperty(*(int **)(param_1 + 0x10),param_2,1,(uint *)0x0);
  if (puVar1 != (uint *)0x0) {
    *puVar1 = 4;
    puVar1[1] = param_3;
  }
  return 0;
}



// ============================================================
// Function: stage_initCharacterTable (FUN_68055AE0)
// Address: 68055ae0
// Size: 460 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_initCharacterTable(void)
{
  byte *pbVar1;
  ushort uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  int unaff_ESI;
  int local_40c;
  byte local_408 [1024];
  uint local_8;
  
  iVar3 = sprites_getNetDoneFlag(unaff_ESI,&local_40c);
  if (iVar3 == 0) {
    uVar4 = 0;
    puVar6 = (uint *)(unaff_ESI + 0x14);
    do {
      *puVar6 = uVar4 | 0x2000;
      uVar4 = uVar4 + 1;
      puVar6 = puVar6 + 1;
    } while ((int)uVar4 < 0x21);
    uVar4 = 0x21;
    puVar6 = (uint *)(unaff_ESI + 0x98);
    do {
      *puVar6 = uVar4 | 0x8000;
      uVar4 = uVar4 + 1;
      puVar6 = puVar6 + 1;
    } while ((int)uVar4 < 0x100);
    *(undefined4 *)(unaff_ESI + 0x48) = 0x1000;
    *(undefined4 *)(unaff_ESI + 0xd4) = 0x4030;
    *(undefined4 *)(unaff_ESI + 0xd8) = 0x4031;
    *(undefined4 *)(unaff_ESI + 0xdc) = 0x4032;
    *(undefined4 *)(unaff_ESI + 0xe0) = 0x4033;
    *(undefined4 *)(unaff_ESI + 0xe4) = 0x4034;
    *(undefined4 *)(unaff_ESI + 0xe8) = 0x4035;
    *(undefined4 *)(unaff_ESI + 0xec) = 0x4036;
    *(undefined4 *)(unaff_ESI + 0xf0) = 0x4037;
    *(undefined4 *)(unaff_ESI + 0xf4) = 0x4038;
    *(undefined4 *)(unaff_ESI + 0xf8) = 0x4039;
    cast_loadPascalString(local_408,0x960,1);
    if (local_408[0] == 0xff) {
      uVar2 = Ordinal_1201(local_408 + 1);
    }
    else {
      uVar2 = (ushort)local_408[0];
    }
    if ((short)uVar2 < 1) {
      Ordinal_1233(local_408,"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz__..");
    }
    if (local_408[0] == 0xff) {
      uVar2 = Ordinal_1201(local_408 + 1);
    }
    else {
      uVar2 = (ushort)local_408[0];
    }
    iVar3 = 1;
    if (1 < (short)uVar2) {
      do {
        uVar4 = (uint)local_408[iVar3 + 1];
        pbVar1 = local_408 + iVar3;
        iVar3 = iVar3 + 2;
        *(uint *)(unaff_ESI + 0x14 + (uint)*pbVar1 * 4) = uVar4;
        *(uint *)(unaff_ESI + 0x14 + uVar4 * 4) = uVar4;
      } while (iVar3 < (short)uVar2);
    }
  }
  else {
    iVar5 = 0;
    puVar6 = (uint *)(unaff_ESI + 0x14);
    do {
      *puVar6 = *(ushort *)(iVar3 + iVar5 * 2) & 0xf0ff;
      iVar5 = iVar5 + 1;
      puVar6 = puVar6 + 1;
    } while (iVar5 < 0x100);
    sprites_getNetState(unaff_ESI,&local_40c);
  }
  uVar4 = 0xc2;
  DAT_68197760 = 0xc2;
  if (DAT_681962c8 == 0) {
    uVar4 = 0xac;
    DAT_68197760 = 0xac;
  }
  *(uint *)(unaff_ESI + 0x14 + uVar4 * 4) = uVar4 | 0x2000;
  return 0;
}



// ============================================================
// Function: stage_initParserModule (FUN_68055CC0)
// Address: 68055cc0
// Size: 101 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_initParserModule(void *param_1)
{
  undefined4 uVar1;
  
  *(undefined1 *)((int)param_1 + 0x418) = 0x57;
  stage_initCharacterTable();
  props_initRuntime((int)param_1);
  stage_allocObjectDispatch((int)param_1);
  uVar1 = score_getSymbolName(0x7f,0xc0);
  *(undefined4 *)((int)param_1 + 8) = uVar1;
  uVar1 = stage_allocParseDispatch();
  *(undefined4 *)((int)param_1 + 0xc) = uVar1;
  uVar1 = score_createPropertyTable();
  *(undefined4 *)((int)param_1 + 0x10) = uVar1;
  stage_registerScoreProperties((int)param_1);
  strings_registerProperties((int)param_1);
  stage_populateOperatorTable(param_1);
  stage_registerBlockHandlers((int)param_1);
  strings_registerCodeBlocks((int)param_1);
  return 0;
}



