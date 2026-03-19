// Module: stage
// Topic: Variable resolution during compilation
// Address range: 0x68054640 - 0x68054F30
// Functions (12):
//   stage_mapSymbolToSlot (FUN_68054640)
//   stage_buildVarMap (FUN_680547B0)
//   stage_emitHandlerData (FUN_680548E0)
//   stage_resolveVarScope (FUN_68054B40)
//   stage_declareVariable (FUN_68054D20)
//   stage_compileVarRef (FUN_68054D50)
//   stage_tryInlineCallback (FUN_68054DD0)
//   stage_checkVarType (FUN_68054E40)
//   stage_isMultiArgSymbol (FUN_68054E90)
//   stage_isCommandSymbol (FUN_68054EB0)
//   stage_isChunkOpSymbol (FUN_68054F10)
//   stage_emitLabelRef (FUN_68054F30)

// ============================================================
// Function: stage_mapSymbolToSlot (FUN_68054640)
// Address: 68054640
// Size: 177 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_mapSymbolToSlot(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0x35:
    return 10;
  case 0x36:
    return 0xb;
  case 0x37:
    return 0xc;
  case 0x38:
    return 0xd;
  case 0x39:
    return 1;
  case 0x3a:
    return 0;
  default:
    return 0xffffffff;
  case 0x4a:
    return 2;
  case 0x56:
    return 4;
  case 0x6a:
    return 3;
  case 0x6b:
    return 0xe;
  case 0x6c:
    return 0xf;
  case 0x6d:
    return 0x10;
  case 0x6e:
    return 0x11;
  case 0x6f:
    return 0x13;
  case 0x70:
    return 0x12;
  case 0x71:
    return 0x14;
  case 0x72:
    return 0x15;
  case 0x73:
    return 0x16;
  case 0x74:
    return 7;
  case 0x75:
    return 8;
  case 0x76:
    return 6;
  case 0x77:
    return 9;
  case 0x78:
    return 0x17;
  case 0x79:
    return 0x18;
  case 0x7a:
    return 5;
  }
}



// ============================================================
// Function: stage_buildVarMap (FUN_680547B0)
// Address: 680547b0
// Size: 290 bytes
// Params: int param_1, int * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_buildVarMap(int param_1,int *param_2)

{
  int param_4;
  int iVar1;
  int iVar2;
  uint *unaff_EBX;
  undefined4 *unaff_ESI;
  int iVar3;
  int local_c;
  
  *unaff_ESI = 0xffffffff;
  unaff_ESI[1] = 0xffffffff;
  unaff_ESI[2] = 0xffffffff;
  unaff_ESI[3] = 0xffffffff;
  unaff_ESI[4] = 0xffffffff;
  unaff_ESI[5] = 0xffffffff;
  unaff_ESI[6] = 0xffffffff;
  unaff_ESI[7] = 0xffffffff;
  unaff_ESI[8] = 0xffffffff;
  unaff_ESI[9] = 0xffffffff;
  unaff_ESI[10] = 0xffffffff;
  unaff_ESI[0xb] = 0xffffffff;
  unaff_ESI[0xc] = 0xffffffff;
  unaff_ESI[0xd] = 0xffffffff;
  unaff_ESI[0xe] = 0xffffffff;
  unaff_ESI[0xf] = 0xffffffff;
  unaff_ESI[0x10] = 0xffffffff;
  unaff_ESI[0x11] = 0xffffffff;
  unaff_ESI[0x12] = 0xffffffff;
  unaff_ESI[0x13] = 0xffffffff;
  unaff_ESI[0x14] = 0xffffffff;
  unaff_ESI[0x15] = 0xffffffff;
  unaff_ESI[0x16] = 0xffffffff;
  unaff_ESI[0x17] = 0xffffffff;
  unaff_ESI[0x18] = 0xffffffff;
  *unaff_EBX = 0;
  if ((*(uint *)(**(int **)(**(int **)(param_1 + 8) + 0x428) + 0x54) & 0x200) == 0) {
    local_c = 0;
  }
  else {
    unaff_ESI[1] = 0;
    unaff_ESI[0xf] = 0;
    *unaff_EBX = *unaff_EBX | 0x8002;
    local_c = 0x10;
  }
  iVar3 = *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x430) + 0x10) + -1;
  if (-1 < iVar3) {
    iVar2 = iVar3 * 0x3c;
    do {
      props_getSymbolId(param_1,*(int *)(**(int **)(**(int **)(param_1 + 8) + 0x430) + 0x20 + iVar2));
      iVar1 = stage_mapSymbolToSlot();
      *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x430) + 0x24 + iVar2) = iVar1;
      if (-1 < iVar1) {
        unaff_ESI[iVar1] = iVar3;
        *unaff_EBX = *unaff_EBX | 1 << ((byte)iVar1 & 0x1f);
        if (local_c < iVar1 + 1) {
          local_c = iVar1 + 1;
        }
      }
      iVar2 = iVar2 + -0x3c;
      iVar3 = iVar3 + -1;
    } while (-1 < iVar3);
  }
  *param_2 = local_c;
  return 0 < local_c;
}



// ============================================================
// Function: stage_emitHandlerData (FUN_680548E0)
// Address: 680548e0
// Size: 601 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitHandlerData(int param_1)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  bool bVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined4 local_78;
  int local_74;
  undefined1 local_70 [104];
  uint local_8;
  
  bVar4 = stage_buildVarMap(param_1,&local_74);
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x428);
  *(undefined4 *)(iVar1 + 0x74) = *(undefined4 *)(iVar1 + 0x10);
  stage_emitJump(param_1,*(int **)(**(int **)(param_1 + 8) + 0x428),
               *(int **)(**(int **)(param_1 + 8) + 0x440),*(int *)(iVar1 + 0x70));
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x428);
  *(undefined4 *)(iVar1 + 0x7c) = *(undefined4 *)(iVar1 + 0x10);
  stage_emitJump(param_1,*(int **)(**(int **)(param_1 + 8) + 0x428),
               *(int **)(**(int **)(param_1 + 8) + 0x444),*(int *)(iVar1 + 0x78));
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x428);
  iVar2 = *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x430) + 0x10);
  *(int *)(iVar1 + 0x80) = iVar2;
  *(undefined4 *)(iVar1 + 0x84) = *(undefined4 *)(iVar1 + 0x10);
  Ordinal_1114(*(undefined4 *)(**(int **)(param_1 + 8) + 0x430));
  stage_emitString(param_1,*(int **)(**(int **)(param_1 + 8) + 0x428),
               (undefined1 *)(**(int **)(**(int **)(param_1 + 8) + 0x430) + 0x20),iVar2 * 0x3c);
  Ordinal_1115(*(undefined4 *)(**(int **)(param_1 + 8) + 0x430));
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x428);
  iVar2 = *(int *)(**(int **)(**(int **)(param_1 + 8) + 0x438) + 0x10);
  *(int *)(iVar1 + 0x88) = iVar2;
  *(undefined4 *)(iVar1 + 0x8c) = *(undefined4 *)(iVar1 + 0x10);
  Ordinal_1114(*(undefined4 *)(**(int **)(param_1 + 8) + 0x438));
  stage_emitString(param_1,*(int **)(**(int **)(param_1 + 8) + 0x428),
               (undefined1 *)(**(int **)(**(int **)(param_1 + 8) + 0x438) + 0x20),iVar2 * 8);
  Ordinal_1115(*(undefined4 *)(**(int **)(param_1 + 8) + 0x438));
  uVar5 = stage_getBytecodeRef(*(int **)(**(int **)(param_1 + 8) + 0x43c));
  iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x428);
  *(uint *)(iVar1 + 0x90) = uVar5;
  *(undefined4 *)(iVar1 + 0x94) = *(undefined4 *)(iVar1 + 0x10);
  Ordinal_1114(*(undefined4 *)(**(int **)(param_1 + 8) + 0x43c));
  stage_emitString(param_1,*(int **)(**(int **)(param_1 + 8) + 0x428),
               (undefined1 *)(**(int **)(**(int **)(param_1 + 8) + 0x43c) + 0x1c),uVar5);
  Ordinal_1115(*(undefined4 *)(**(int **)(param_1 + 8) + 0x43c));
  if (CONCAT31(extraout_var,bVar4) != 0) {
    iVar1 = **(int **)(**(int **)(param_1 + 8) + 0x428);
    *(undefined4 *)(iVar1 + 0x6c) = local_78;
    *(int *)(iVar1 + 100) = local_74;
    *(undefined4 *)(iVar1 + 0x68) = *(undefined4 *)(iVar1 + 0x10);
    stage_emitString(param_1,*(int **)(**(int **)(param_1 + 8) + 0x428),local_70,local_74 * 4);
  }
  stage_getBytecodeSize(*(int **)(**(int **)(param_1 + 8) + 0x428));
  piVar3 = *(int **)(**(int **)(param_1 + 8) + 0x428);
  if ((*(byte *)(*piVar3 + 0x54) & 2) != 0) {
    props_installHandlers(param_1,piVar3);
  }
  return 0;
}



// ============================================================
// Function: stage_resolveVarScope (FUN_68054B40)
// Address: 68054b40
// Size: 479 bytes
// Params: int param_1, undefined4 * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_resolveVarScope(int param_1,undefined4 *param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *unaff_EBX;
  int unaff_ESI;
  uint unaff_EDI;
  
  puVar3 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x440),unaff_EDI,0,(uint *)0x0);
  if (puVar3 != (uint *)0x0) {
    *param_2 = 3;
    uVar4 = props_resolveSymbol(unaff_ESI,unaff_EDI);
    *unaff_EBX = uVar4;
    return 0;
  }
  puVar3 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x494),unaff_EDI,0,(uint *)0x0);
  if (puVar3 != (uint *)0x0) {
    *param_2 = 2;
    uVar4 = props_resolveSymbol(unaff_ESI,unaff_EDI);
    *unaff_EBX = uVar4;
    return 0;
  }
  puVar3 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x444),unaff_EDI,0,(uint *)0x0);
  if (puVar3 != (uint *)0x0) {
    *param_2 = 2;
    uVar4 = props_resolveSymbol(unaff_ESI,unaff_EDI);
    *unaff_EBX = uVar4;
    return 0;
  }
  puVar3 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x48c),unaff_EDI,0,(uint *)0x0);
  if (puVar3 != (uint *)0x0) {
    *param_2 = 4;
    *unaff_EBX = puVar3[1];
    return 0;
  }
  puVar3 = score_lookupProperty(*(int **)(**(int **)(unaff_ESI + 8) + 0x490),unaff_EDI,0,(uint *)0x0);
  if (puVar3 == (uint *)0x0) {
    iVar2 = **(int **)(unaff_ESI + 8);
    uVar4 = *(uint *)(**(int **)(iVar2 + 0x428) + 0x54);
    if ((uVar4 & 4) != 0) {
      *param_2 = 1;
      uVar4 = props_resolveSymbol(unaff_ESI,unaff_EDI);
      *unaff_EBX = uVar4;
      return 1;
    }
    if ((uVar4 & 8) != 0) {
      *param_2 = 0;
      uVar4 = props_resolveSymbol(unaff_ESI,unaff_EDI);
      *unaff_EBX = uVar4;
      return 1;
    }
    if (param_1 != 0) {
      *param_2 = 1;
      uVar4 = props_resolveSymbol(unaff_ESI,unaff_EDI);
      *unaff_EBX = uVar4;
      return 1;
    }
    iVar5 = 1;
    if (*(int *)(iVar2 + 0x4d0) == 0) {
      iVar5 = param_3;
    }
    if (iVar5 == 0) {
      stage_emitPushLiteral(unaff_ESI,0x1a);
    }
    else {
      if (iVar5 == 1) {
        puVar3 = score_lookupProperty(*(int **)(iVar2 + 0x490),unaff_EDI,1,(uint *)0x0);
        if (puVar3 == (uint *)0x0) {
          stage_emitPushLiteral(unaff_ESI,1);
          return 0;
        }
        *puVar3 = 4;
        puVar3[1] = *(uint *)(**(int **)(unaff_ESI + 8) + 0x468);
        piVar1 = (int *)(**(int **)(unaff_ESI + 8) + 0x468);
        *piVar1 = *piVar1 + 1;
        goto LAB_68054cfd;
      }
      if (iVar5 == 3) {
        return 1;
      }
    }
    return 0;
  }
LAB_68054cfd:
  *param_2 = 5;
  *unaff_EBX = puVar3[1];
  return 0;
}



// ============================================================
// Function: stage_declareVariable (FUN_68054d20)
// Address: 68054d20
// Size: 37 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_declareVariable(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 param_4,
                 int param_5)
{
  stage_resolveVarScope(0,param_3,param_5);
  return 0;
}



// ============================================================
// Function: stage_compileVarRef (FUN_68054D50)
// Address: 68054d50
// Size: 116 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compileVarRef(void)
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  uint unaff_EDI;
  char local_c [4];
  uint local_8;
  
  iVar2 = core_isClassProperty(unaff_ESI,unaff_EDI);
  if (iVar2 != 0) {
    iVar2 = 1;
    uVar3 = props_resolveSymbol(unaff_ESI,unaff_EDI);
    stage_emitInstruction(unaff_ESI,0x72,uVar3,iVar2);
    puVar1 = (uint *)(**(int **)(**(int **)(unaff_ESI + 8) + 0x428) + 0x54);
    *puVar1 = *puVar1 | 0x8000;
    return 0;
  }
  stage_declareVariable(unaff_ESI,unaff_EDI,(undefined4 *)local_c,&local_8,0);
  if (*(int *)(**(int **)(unaff_ESI + 8) + 0x41c) == 0) {
    stage_emitInstruction(unaff_ESI,(uint)(byte)(local_c[0] + 0x47),local_8,1);
  }
  return 0;
}



// ============================================================
// Function: stage_tryInlineCallback (FUN_68054DD0)
// Address: 68054dd0
// Size: 103 bytes
// Params: undefined * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_tryInlineCallback(undefined *param_1)

{
  int iVar1;
  int *piVar2;
  int unaff_ESI;
  int *unaff_EDI;
  int local_c;
  int local_8;
  
  stage_pushCurrentScope(unaff_ESI);
  if ((local_c == 8) && (local_8 < 0x2f)) {
    iVar1 = (*(code *)param_1)(&local_c);
    if ((iVar1 == 0) &&
       (piVar2 = (int *)((local_8 + 2) * 0x10 + **(int **)(**(int **)(unaff_ESI + 8) + 0xc)),
       *piVar2 == 2)) {
      *unaff_EDI = piVar2[1];
      unaff_EDI[1] = piVar2[2];
      return 1;
    }
  }
  stage_resolveSymbol(unaff_ESI,&local_c);
  return 0;
}



// ============================================================
// Function: stage_checkVarType (FUN_68054E40)
// Address: 68054e40
// Size: 68 bytes
// Params: void * this, int param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall stage_checkVarType(void *this,int param_1)

{
  int iVar1;
  
  if ((*(int *)this != 0) &&
     (((*(int *)this != 8 || (0x2e < *(int *)((int)this + 4))) ||
      ((iVar1 = *(int *)((*(int *)((int)this + 4) + 2) * 0x10 +
                        **(int **)(**(int **)(param_1 + 8) + 0xc)), iVar1 != 2 && (iVar1 != 4))))))
  {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: stage_isMultiArgSymbol (FUN_68054E90)
// Address: 68054e90
// Size: 24 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_isMultiArgSymbol(void)

{
  int in_EAX;
  
  if ((0x57 < in_EAX) && ((in_EAX < 0x5a || (in_EAX == 0x7b)))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_isCommandSymbol (FUN_68054EB0)
// Address: 68054eb0
// Size: 31 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_isCommandSymbol(void)

{
  undefined4 in_EAX;
  
  switch(in_EAX) {
  case 0x54:
  case 0x58:
  case 0x59:
  case 0x68:
  case 0x7b:
  case 0x7c:
  case 0x7d:
    return 1;
  default:
    return 0;
  }
}



// ============================================================
// Function: stage_isChunkOpSymbol (FUN_68054F10)
// Address: 68054f10
// Size: 21 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_isChunkOpSymbol(void)

{
  int in_EAX;
  
  if ((0x7d < in_EAX) && (in_EAX < 0x81)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_emitLabelRef (FUN_68054F30)
// Address: 68054f30
// Size: 63 bytes
// Params: undefined4 * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint stage_emitLabelRef(undefined4 *param_1)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int unaff_ESI;
  
  piVar1 = *(int **)(**(int **)(unaff_ESI + 8) + 0x438);
  uVar2 = *(uint *)(*piVar1 + 0x10);
  stage_lookupSymbolId(piVar1,param_1);
  iVar3 = stage_emitPushIfNeeded(unaff_ESI);
  if (iVar3 == 0) {
    return 0;
  }
  stage_emitInstruction(unaff_ESI,0x44,uVar2,1);
  return uVar2;
}



