// Module: stage
// Topic: Handler compilation and execution
// Address range: 0x68056F50 - 0x68057610
// Functions (10):
//   stage_compileStatement (FUN_68056F50)
//   stage_compileStatementBlock (FUN_68056FD0)
//   stage_compileHandlerEntry (FUN_680570F0)
//   stage_compileHandlerScope (FUN_680571A0)
//   stage_resolveLineOffset (FUN_680574B0)
//   stage_compileHandlerBody (stage_compileHandlerBody)
//   stage_countScopes (FUN_68057580)
//   stage_getScopeAtIndex (FUN_680575B0)
//   stage_hasClosureScope (FUN_680575F0)
//   stage_computeSlotCount (FUN_68057610)

// ============================================================
// Function: stage_compileStatement (FUN_68056F50)
// Address: 68056f50
// Size: 127 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileStatement(void *param_1)
{
  int param_4;
  undefined4 *puVar1;
  int iVar2;
  undefined1 local_408 [1024];
  uint local_8;
  
  stage_parseDeclaration((int)param_1);
  iVar2 = stage_compileCommand(param_1);
  puVar1 = *(undefined4 **)(**(int **)((int)param_1 + 8) + 0x420);
  if (((1 < (int)puVar1[3]) && (*(char *)(puVar1[1] + *(int *)*puVar1) == '-')) &&
     (((char *)(puVar1[1] + *(int *)*puVar1))[1] == '-')) {
    props_extractWordToken((int)param_1,*(undefined4 **)(**(int **)((int)param_1 + 8) + 0x420),local_408);
  }
  if (iVar2 != 0) {
    stage_getParseState();
  }
  return 0;
}



// ============================================================
// Function: stage_compileStatementBlock (FUN_68056FD0)
// Address: 68056fd0
// Size: 269 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileStatementBlock(void)
{
  int iVar1;
  bool bVar2;
  uint uVar3;
  undefined3 extraout_var;
  int unaff_EBX;
  void *unaff_ESI;
  int iVar4;
  
  iVar4 = **(int **)((int)unaff_ESI + 8);
  if ((*(byte *)(**(int **)(iVar4 + 0x428) + 0x54) & 0x40) == 0) {
    iVar1 = *(int *)(iVar4 + 0x41c);
    while (((iVar1 == 0 &&
            (bVar2 = props_isParserReady(*(int *)(iVar4 + 0x420)), CONCAT31(extraout_var,bVar2) == 0)) &&
           (iVar4 = stage_compileStatement(unaff_ESI), iVar4 != 0))) {
      *(undefined4 *)(**(int **)((int)unaff_ESI + 8) + 0x4c8) = 0;
      iVar4 = **(int **)((int)unaff_ESI + 8);
      if ((*(int *)(iVar4 + 0x41c) != 0) && (*(int *)(iVar4 + 0x4cc) != 0)) {
        *(undefined4 *)(**(int **)(iVar4 + 0x498) + 0x10) = *(undefined4 *)(iVar4 + 0x4a0);
        *(undefined4 *)(**(int **)((int)unaff_ESI + 8) + 0x41c) = 0;
      }
      if (unaff_EBX == 0) break;
      if (*(int *)(**(int **)((int)unaff_ESI + 8) + 0x41c) == 0) {
        props_getCurrentToken();
      }
      iVar4 = **(int **)((int)unaff_ESI + 8);
      iVar1 = *(int *)(iVar4 + 0x41c);
    }
    stage_emitReturnOpcode((int)unaff_ESI);
    stage_finalizeCodegen((int)unaff_ESI);
  }
  else {
    stage_compileHandler(unaff_ESI,lingo_noop);
    if (*(int *)(**(int **)((int)unaff_ESI + 8) + 0x41c) == 0) {
      stage_emitInstruction((int)unaff_ESI,0x42,1,1);
      iVar4 = -2;
      uVar3 = props_resolveSymbol((int)unaff_ESI,0x27);
      stage_emitInstruction((int)unaff_ESI,(uint)*(byte *)(**(int **)((int)unaff_ESI + 8) + 0x418),uVar3,
                   iVar4);
      stage_emitReturnOpcode((int)unaff_ESI);
      stage_finalizeCodegen((int)unaff_ESI);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_compileHandlerEntry (FUN_680570F0)
// Address: 680570f0
// Size: 166 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileHandlerEntry(void)
{
  int in_EAX;
  uint uVar1;
  int unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  
  if (unaff_EDI == 0) {
    local_8 = (int *)0xffffffff;
  }
  else {
    stage_pushCurrentScope(in_EAX);
    if ((local_c != 8) || ((int)local_8 < 0x2f)) {
      stage_emitPushLiteral(in_EAX,2);
      props_releaseValue(in_EAX,(byte)local_c,local_8);
      return 0;
    }
  }
  stage_resetCodegenState(in_EAX,(uint)local_8);
  if (unaff_EDI != 0) {
    uVar1 = stage_compileParameterList(in_EAX,*(int **)(**(int **)(in_EAX + 8) + 0x48c),
                         *(uint *)(**(int **)(in_EAX + 8) + 0x460),0,1);
    *(uint *)(**(int **)(in_EAX + 8) + 0x460) = uVar1;
    props_getCurrentToken();
    *(undefined4 *)(**(int **)(in_EAX + 8) + 0x47c) =
         *(undefined4 *)(*(int *)(**(int **)(in_EAX + 8) + 0x420) + 0x14);
  }
  stage_compileStatementBlock();
  return 0;
}



// ============================================================
// Function: stage_compileHandlerScope (FUN_680571A0)
// Address: 680571a0
// Size: 771 bytes
// Params: void * param_1, undefined4 * param_2, int param_3, uint param_4, undefined4 param_5, undefined4 param_6, undefined4 * param_7
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
stage_compileHandlerScope(void *param_1,undefined4 *param_2,int param_3,uint param_4,undefined4 param_5,
            undefined4 param_6,undefined4 *param_7)

{
  uint *puVar1;
  undefined4 uVar2;
  bool bVar3;
  undefined4 *puVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined3 extraout_var_00;
  int iVar6;
  int *extraout_ECX;
  int *piVar7;
  int extraout_EDX;
  undefined4 *puVar8;
  undefined4 *puVar9;
  undefined4 local_cc [48];
  int local_c;
  int *local_8;
  
  *param_7 = 0;
  puVar4 = (undefined4 *)(**(int **)((int)param_1 + 8) + 0x41c);
  puVar8 = puVar4;
  puVar9 = local_cc;
  for (iVar6 = 0x30; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  Ordinal_1130(puVar4,0xc0);
  *(undefined4 **)(**(int **)((int)param_1 + 8) + 0x420) = param_2;
  bVar3 = stage_initCodegenContext((int)param_1);
  if (CONCAT31(extraout_var,bVar3) == 0) {
    stage_emitPushLiteral((int)param_1,1);
  }
  else {
    *(undefined4 *)(**(int **)((int)param_1 + 8) + 0x4d0) = 0;
    iVar6 = **(int **)(**(int **)((int)param_1 + 8) + 0x428);
    *(undefined4 *)(iVar6 + 0x58) = param_5;
    *(undefined4 *)(iVar6 + 0x60) = 0xffffffff;
    *(undefined4 *)(iVar6 + 0x5c) = param_6;
    *(uint *)(iVar6 + 0x54) = param_4;
    *(undefined4 *)(iVar6 + 0x24) = 0xffffffff;
    *(undefined4 *)(iVar6 + 0x28) = 0xffffffff;
    if ((param_4 & 1) != 0) {
      *(undefined4 *)(iVar6 + 0x2c) = *param_2;
    }
    props_allocHandlerSlot((int)param_1,*(int **)((int)param_1 + 0x2c),
                 *(int **)(**(int **)((int)param_1 + 8) + 0x428));
    uVar5 = *(uint *)(**(int **)(**(int **)((int)param_1 + 8) + 0x428) + 0x54);
    if ((uVar5 & 0x4000) == 0) {
      *(uint *)(**(int **)((int)param_1 + 8) + 0x4d8) = uVar5 >> 0xb & 1;
      uVar5 = *(uint *)(**(int **)(**(int **)((int)param_1 + 8) + 0x428) + 0x54);
      if (param_3 == -1) {
        stage_compileHandlerEntry();
      }
      else {
        stage_collectLocalVars(param_1,param_3);
        if ((uVar5 >> 10 & 1) != 0) {
          stage_compileHandlerEntry();
          puVar1 = (uint *)(**(int **)(**(int **)((int)param_1 + 8) + 0x428) + 0x54);
          *puVar1 = *puVar1 & 0xfffffffd;
        }
        iVar6 = *(int *)(**(int **)((int)param_1 + 8) + 0x41c);
        while (iVar6 == 0) {
          stage_pushCurrentScope((int)param_1);
          if (local_c == 0) {
LAB_680573f2:
            props_getCurrentToken();
            bVar3 = props_isParserReady(*(int *)(**(int **)((int)param_1 + 8) + 0x420));
            if (CONCAT31(extraout_var_00,bVar3) != 0) break;
          }
          else {
            piVar7 = local_8;
            iVar6 = local_c;
            if ((local_c != 8) || ((int)local_8 < 0x2f)) {
LAB_680573d4:
              props_releaseValue(param_1,(byte)iVar6,piVar7);
              if (*(int *)(**(int **)((int)param_1 + 8) + 0x4d0) == 0) {
                stage_emitPushLiteral((int)param_1,4);
              }
              goto LAB_680573f2;
            }
            iVar6 = stage_matchTokenType(param_3);
            if (iVar6 == 0) {
              if (extraout_ECX != (int *)0x44) {
                if (extraout_ECX == (int *)0x64) {
                  uVar5 = stage_compileParameterList((int)param_1,*(int **)(**(int **)((int)param_1 + 8) + 0x444),
                                       *(uint *)(**(int **)(**(int **)((int)param_1 + 8) + 0x428) +
                                                0x78),0,0);
                  *(uint *)(**(int **)(**(int **)((int)param_1 + 8) + 0x428) + 0x78) = uVar5;
                }
                else {
                  piVar7 = extraout_ECX;
                  iVar6 = extraout_EDX;
                  if (extraout_ECX != (int *)0x83) goto LAB_680573d4;
                  uVar5 = stage_compileParameterList((int)param_1,*(int **)(**(int **)((int)param_1 + 8) + 0x440),
                                       *(uint *)(**(int **)(**(int **)((int)param_1 + 8) + 0x428) +
                                                0x70),0,0);
                  *(uint *)(**(int **)(**(int **)((int)param_1 + 8) + 0x428) + 0x70) = uVar5;
                }
              }
              goto LAB_680573f2;
            }
            stage_compileHandlerEntry();
          }
          iVar6 = *(int *)(**(int **)((int)param_1 + 8) + 0x41c);
        }
      }
    }
    else {
      core_loadExternalScripts(param_1);
    }
    if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
      stage_emitHandlerData((int)param_1);
      if (*(int *)(**(int **)((int)param_1 + 8) + 0x41c) == 0) {
        piVar7 = *(int **)(**(int **)((int)param_1 + 8) + 0x428);
        *param_7 = piVar7;
        if ((*(byte *)(*piVar7 + 0x54) & 0x80) != 0) {
          props_suspendContext((int)param_1,piVar7);
        }
        *(undefined4 *)(**(int **)((int)param_1 + 8) + 0x428) = 0;
      }
    }
  }
  stage_freeCodegenContext((uint)param_1);
  uVar2 = *(undefined4 *)(**(int **)((int)param_1 + 8) + 0x41c);
  puVar8 = local_cc;
  puVar9 = (undefined4 *)(**(int **)((int)param_1 + 8) + 0x41c);
  for (iVar6 = 0x30; iVar6 != 0; iVar6 = iVar6 + -1) {
    *puVar9 = *puVar8;
    puVar8 = puVar8 + 1;
    puVar9 = puVar9 + 1;
  }
  return uVar2;
}



// ============================================================
// Function: stage_resolveLineOffset (FUN_680574B0)
// Address: 680574b0
// Size: 163 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_resolveLineOffset(undefined4 param_1,int param_2,int param_3)

{
  int iVar1;
  byte *pbVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  uVar5 = 0;
  iVar7 = *(int *)(param_3 + 0xc);
  if (param_2 != 0) {
    iVar7 = iVar7 + -1;
  }
  if (*(int **)(param_3 + 0x10) == (int *)0x0) {
    return 0;
  }
  iVar6 = **(int **)(param_3 + 0x10);
  iVar1 = *(int *)(iVar6 + 0x84) + *(int *)(param_3 + 0x14) * 0x3c;
  iVar4 = iVar1 + iVar6;
  pbVar2 = (byte *)(*(int *)(iVar1 + 0x34 + iVar6) + iVar6);
  iVar7 = iVar7 - *(int *)(iVar4 + 0xc);
  iVar1 = *(int *)(iVar4 + 0x2c);
  iVar6 = *(int *)(iVar4 + 0x30);
  pbVar3 = pbVar2;
  iVar4 = iVar6;
  if (-1 < iVar7) {
    while (pbVar3 = pbVar2, iVar4 = iVar6, 0 < iVar6) {
      uVar5 = (uint)*pbVar2;
      pbVar3 = pbVar2 + 1;
      iVar4 = iVar6 + -1;
      if ((char)*pbVar2 < '\0') {
        uVar5 = (uVar5 & 0xffffff7f) << 8 | (uint)*pbVar3;
        pbVar3 = pbVar2 + 2;
        iVar4 = iVar6 + -2;
      }
      iVar7 = iVar7 - uVar5;
      if (iVar7 < 0) break;
      iVar1 = iVar1 + 1;
      pbVar2 = pbVar3;
      iVar6 = iVar4;
    }
    if (uVar5 != 0) {
      return iVar1;
    }
  }
  while( true ) {
    if (iVar4 < 1) {
      return iVar1;
    }
    uVar5 = (uint)*pbVar3;
    pbVar2 = pbVar3 + 1;
    iVar7 = iVar4 + -1;
    if ((char)*pbVar3 < '\0') {
      uVar5 = (uVar5 & 0xffffff7f) << 8 | (uint)pbVar3[1];
      pbVar2 = pbVar3 + 2;
      iVar7 = iVar4 + -2;
    }
    iVar4 = iVar7;
    pbVar3 = pbVar2;
    if (uVar5 != 0) break;
    iVar1 = iVar1 + 1;
  }
  return iVar1;
}



// ============================================================
// Function: stage_compileHandlerBody (FUN_68057560)
// Address: 68057560
// Size: 24 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileHandlerBody(int param_1,int param_2)
{
  stage_resolveLineOffset(param_1,param_2,param_1 + 0x40);
  return 0;
}



// ============================================================
// Function: stage_countScopes (FUN_68057580)
// Address: 68057580
// Size: 46 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_countScopes(int param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  
  iVar1 = *(int *)(param_1 + 0x40);
  iVar2 = 0;
  if (-1 < iVar1) {
    do {
      iVar1 = *(int *)(**(int **)(param_1 + 0x10) + iVar1);
      iVar2 = iVar2 + 1;
    } while (-1 < iVar1);
    *param_2 = iVar2;
    return 0;
  }
  *param_2 = 0;
  return 0;
}



// ============================================================
// Function: stage_getScopeAtIndex (FUN_680575B0)
// Address: 680575b0
// Size: 62 bytes
// Params: int param_1, int param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * stage_getScopeAtIndex(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)(param_1 + 0x40);
  if (*(int *)(param_1 + 0x40) < 0) {
    return (int *)0x0;
  }
  iVar2 = 0;
  if (0 < param_2) {
    while (piVar1 = (int *)(*piVar1 + **(int **)(param_1 + 0x10)), -1 < *piVar1) {
      iVar2 = iVar2 + 1;
      if (param_2 <= iVar2) {
        return piVar1;
      }
    }
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



// ============================================================
// Function: stage_hasClosureScope (FUN_680575F0)
// Address: 680575f0
// Size: 23 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_hasClosureScope(void)

{
  int *in_EAX;
  
  if (((*(byte *)(*in_EAX + 0x54) & 0x10) == 0) && (*(int *)(*in_EAX + 0x70) < 1)) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: stage_computeSlotCount (FUN_68057610)
// Address: 68057610
// Size: 76 bytes
// Params: undefined4 param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_computeSlotCount(undefined4 param_1)

{
  int iVar1;
  int iVar2;
  int *in_stack_00000018;
  int in_stack_0000001c;
  int *in_stack_00000028;
  
  iVar1 = props_getContextSlot(param_1,in_stack_00000018,in_stack_0000001c);
  iVar2 = *(int *)(*in_stack_00000018 + 0x78) + *(int *)(iVar1 + 0x20) + *(int *)(iVar1 + 0x18) +
          *(int *)(iVar1 + 0x10);
  iVar1 = stage_hasClosureScope();
  if ((iVar1 != 0) && (in_stack_00000028 != (int *)0x0)) {
    iVar1 = score_clearPropertyTable(in_stack_00000028);
    return iVar1 + iVar2;
  }
  return iVar2;
}



