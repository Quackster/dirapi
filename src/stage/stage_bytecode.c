// Module: stage
// Topic: Bytecode buffer management and error reporting
// Address range: 0x68052DB0 - 0x68053380
// Functions (15):
//   stage_emitStoreVar (FUN_68052DB0)
//   stage_lookupSymbolId (FUN_68052E40)
//   stage_emitStoreProperty (FUN_68052ED0)
//   stage_emitPushRef (FUN_68052F40)
//   stage_resetBytecodeCount (FUN_68052F90)
//   stage_emitPopVar (FUN_68052FB0)
//   stage_createBytecodeBlock (FUN_68052FF0)
//   stage_emitPushVar (stage_emitPushVar)
//   stage_resetBytecodeOffset (FUN_680530B0)
//   stage_getBytecodeRef (FUN_680530D0)
//   stage_getBytecodeSize (FUN_680530F0)
//   stage_emitBytecode (stage_emitBytecode)
//   stage_reportBytecodeError (FUN_68053200)
//   stage_emitPushLiteral (FUN_680532E0)
//   stage_pushCurrentScope (FUN_68053380)

// ============================================================
// Function: stage_emitStoreVar (FUN_68052db0)
// Address: 68052db0
// Size: 133 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_emitStoreVar(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x14);
  iVar4 = param_2 + 1;
  if (iVar2 < iVar4) {
    if (iVar2 < 2) {
      iVar2 = 2;
    }
    iVar2 = iVar4 + (iVar2 >> 1);
    if (iVar2 < iVar4) {
      iVar2 = iVar4;
    }
    uVar3 = cast_resizeHandle((uint)param_1,
                         *(short *)(iVar1 + 0x1e) * iVar2 + (int)*(short *)(iVar1 + 0x18),1);
    if (uVar3 == 0) {
      uVar3 = cast_resizeHandle((uint)param_1,
                           *(short *)(*param_1 + 0x1e) * iVar4 + (int)*(short *)(*param_1 + 0x18),0)
      ;
      iVar2 = iVar4;
      if (uVar3 == 0) {
        return 0;
      }
    }
    *(int *)(*param_1 + 0x14) = iVar2;
  }
  if (*(int *)(*param_1 + 0x10) < iVar4) {
    *(int *)(*param_1 + 0x10) = iVar4;
  }
  return 1;
}



// ============================================================
// Function: stage_lookupSymbolId (FUN_68052e40)
// Address: 68052e40
// Size: 137 bytes
// Params: int * param_1, undefined4 * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_lookupSymbolId(int *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  
  iVar1 = *(int *)(*param_1 + 0x10);
  iVar4 = (int)*(short *)(*param_1 + 0x1e);
  iVar2 = stage_emitStoreVar(param_1,iVar1);
  if (iVar2 == 0) {
    return -1;
  }
  puVar3 = (undefined4 *)(iVar1 * iVar4 + (int)*(short *)(*param_1 + 0x18) + *param_1);
  if (iVar4 == 1) {
    *(undefined1 *)puVar3 = *(undefined1 *)param_2;
    return iVar1;
  }
  if (iVar4 == 2) {
    *(undefined2 *)puVar3 = *(undefined2 *)param_2;
    return iVar1;
  }
  if (iVar4 != 4) {
    Ordinal_1129(puVar3,param_2,iVar4);
    return iVar1;
  }
  *puVar3 = *param_2;
  return iVar1;
}



// ============================================================
// Function: stage_emitStoreProperty (FUN_68052ed0)
// Address: 68052ed0
// Size: 98 bytes
// Params: int * param_1, int param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_emitStoreProperty(int *param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = (int)*(short *)(*param_1 + 0x1e);
  iVar1 = *(int *)(*param_1 + 0x10);
  iVar3 = (iVar1 - param_2) * iVar2;
  iVar1 = stage_emitStoreVar(param_1,iVar1);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = iVar2 * param_2 + (int)*(short *)(*param_1 + 0x18) + *param_1;
  if (0 < iVar3) {
    Ordinal_1129(iVar1 + iVar2,iVar1,iVar3);
  }
  Ordinal_1129(iVar1,param_3,iVar2);
  return 1;
}



// ============================================================
// Function: stage_emitPushRef (FUN_68052f40)
// Address: 68052f40
// Size: 66 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitPushRef(int *param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar3 = (int)*(short *)(iVar1 + 0x1e);
  iVar2 = ((*(int *)(iVar1 + 0x10) - param_2) + -1) * iVar3;
  if (0 < iVar2) {
    iVar1 = iVar3 * param_2 + *(short *)(iVar1 + 0x18) + iVar1;
    Ordinal_1129(iVar1,iVar1 + iVar3,iVar2);
  }
  *(int *)(*param_1 + 0x10) = *(int *)(*param_1 + 0x10) + -1;
  return 0;
}



// ============================================================
// Function: stage_resetBytecodeCount (FUN_68052f90)
// Address: 68052f90
// Size: 19 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_resetBytecodeCount(int *param_1)
{
  *(undefined4 *)(*param_1 + 0x10) = 0;
  return 0;
}



// ============================================================
// Function: stage_emitPopVar (FUN_68052fb0)
// Address: 68052fb0
// Size: 56 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitPopVar(int *param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar2 = *(int *)(iVar1 + 0x10);
  iVar3 = *(short *)(iVar1 + 0x1e) * iVar2 + (int)*(short *)(iVar1 + 0x18);
  if (iVar3 < *(short *)(iVar1 + 0x1a)) {
    iVar3 = (int)*(short *)(iVar1 + 0x1a);
  }
  cast_resizeHandle((uint)param_1,iVar3,0);
  *(int *)(*param_1 + 0x14) = iVar2;
  return 0;
}



// ============================================================
// Function: stage_createBytecodeBlock (FUN_68052ff0)
// Address: 68052ff0
// Size: 79 bytes
// Params: short param_1, short param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_createBytecodeBlock(short param_1,short param_2,int param_3)
{
  short sVar1;
  int *piVar2;
  int iVar3;
  
  sVar1 = param_1 + -2;
  iVar3 = param_2 + param_3;
  if (iVar3 < sVar1) {
    iVar3 = (int)sVar1;
  }
  piVar2 = (int *)cast_allocHandle(iVar3,1);
  if (piVar2 != (int *)0x0) {
    *(int *)(*piVar2 + 0x10) = (int)param_2;
    *(int *)(*piVar2 + 0x14) = iVar3;
    *(short *)(*piVar2 + 0x18) = param_2;
    *(short *)(*piVar2 + 0x1a) = sVar1;
  }
  return 0;
}



// ============================================================
// Function: stage_emitPushVar (FUN_68053040)
// Address: 68053040
// Size: 105 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_emitPushVar(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = *(int *)(*param_1 + 0x14);
  if (param_2 <= iVar1) goto LAB_68053098;
  if (iVar1 < 2) {
    iVar1 = 2;
  }
  iVar1 = (iVar1 >> 1) + param_2;
  if (iVar1 < 0) {
LAB_68053074:
    iVar1 = param_2;
    if (param_2 < 0) {
      iVar1 = 0x7fffffff;
    }
    uVar2 = cast_resizeHandle((uint)param_1,iVar1,0);
    if (uVar2 == 0) {
      return 0;
    }
  }
  else {
    uVar2 = cast_resizeHandle((uint)param_1,iVar1,0);
    if (uVar2 == 0) goto LAB_68053074;
  }
  *(int *)(*param_1 + 0x14) = iVar1;
LAB_68053098:
  *(int *)(*param_1 + 0x10) = param_2;
  return 1;
}



// ============================================================
// Function: stage_resetBytecodeOffset (FUN_680530b0)
// Address: 680530b0
// Size: 19 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_resetBytecodeOffset(int *param_1)
{
  *(int *)(*param_1 + 0x10) = (int)*(short *)(*param_1 + 0x18);
  return 0;
}



// ============================================================
// Function: stage_getBytecodeRef (FUN_680530d0)
// Address: 680530d0
// Size: 21 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_getBytecodeRef(int *param_1)

{
  return *(int *)(*param_1 + 0x10) - (int)*(short *)(*param_1 + 0x18);
}



// ============================================================
// Function: stage_getBytecodeSize (FUN_680530f0)
// Address: 680530f0
// Size: 43 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getBytecodeSize(int *param_1)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(*param_1 + 0x10);
  iVar1 = (int)*(short *)(*param_1 + 0x1a);
  if (iVar2 < iVar1) {
    iVar2 = iVar1;
  }
  cast_resizeHandle((uint)param_1,iVar2,0);
  *(int *)(*param_1 + 0x14) = iVar2;
  return 0;
}



// ============================================================
// Function: stage_emitBytecode (FUN_68053120)
// Address: 68053120
// Size: 197 bytes
// Params: int * param_1, undefined1 * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_emitBytecode(int *param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  undefined1 *puVar3;
  
  iVar1 = *(int *)(*param_1 + 0x10);
  iVar2 = stage_emitPushVar(param_1,iVar1 + param_3);
  if (iVar2 != 0) {
    puVar3 = (undefined1 *)(*param_1 + iVar1);
    switch(param_3) {
    case 1:
      *puVar3 = *param_2;
      return 1;
    case 2:
      *puVar3 = *param_2;
      puVar3[1] = param_2[1];
      return 1;
    case 3:
      *puVar3 = *param_2;
      puVar3[1] = param_2[1];
      puVar3[2] = param_2[2];
      return 1;
    case 4:
      *puVar3 = *param_2;
      puVar3[1] = param_2[1];
      puVar3[2] = param_2[2];
      puVar3[3] = param_2[3];
      return 1;
    default:
      Ordinal_1129(puVar3,param_2,param_3);
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_reportBytecodeError (FUN_68053200)
// Address: 68053200
// Size: 215 bytes
// Params: int param_1, int param_2, undefined4 * param_3, int param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_reportBytecodeError(int param_1,int param_2,undefined4 *param_3,int param_4,int *param_5)
{
  int iVar1;
  int local_410;
  int local_40c;
  undefined1 local_408 [1024];
  
  if (param_4 == 0) {
    return 0;
  }
  *param_5 = param_3[1];
  iVar1 = param_3[5];
  props_resetParserPosition((int)param_3,0);
  props_parseBlock(param_1,(int)param_3,iVar1,&local_40c,&local_410);
  Ordinal_1234(local_408,*param_3,local_40c,local_410 - local_40c);
  props_formatError(param_1,param_2,0xa28,param_4,(int)local_408,*param_5 - local_40c,0x6817a914,1,
               local_40c);
  return 0;
}



// ============================================================
// Function: stage_emitPushLiteral (FUN_680532e0)
// Address: 680532e0
// Size: 148 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_emitPushLiteral(int param_1,int param_2)
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (*(int *)(**(int **)(param_1 + 8) + 0x41c) == 0) {
    *(int *)(**(int **)(param_1 + 8) + 0x41c) = param_2;
    *(undefined4 *)(**(int **)(param_1 + 8) + 0x4cc) = 0;
    if (param_2 == 1) {
      rendering_updateDisplay();
      return 0;
    }
    piVar1 = (int *)**(int **)(param_1 + 8);
    if (((*piVar1 != 0) && (piVar1 = (int *)piVar1[0x10a], piVar1 != (int *)0x0)) &&
       ((*(byte *)(*piVar1 + 0x54) & 0x40) == 0)) {
      puVar2 = (undefined4 *)**(int **)(param_1 + 8);
      iVar3 = (*(code *)*puVar2)(param_1,puVar2[0x10a],puVar2[0x113],puVar2[0x108],puVar2[0x107]);
      *(uint *)(**(int **)(param_1 + 8) + 0x4cc) = (uint)(iVar3 == 0);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_pushCurrentScope (FUN_68053380)
// Address: 68053380
// Size: 34 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_pushCurrentScope(int param_1)
{
  props_setParserState(param_1,*(undefined4 *)(**(int **)(param_1 + 8) + 0x420),1);
  return 0;
}



