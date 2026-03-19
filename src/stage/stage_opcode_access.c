// Module: stage
// Topic: Opcode handlers: memory access and call setup
// Address range: 0x68050CA0 - 0x680511B0
// Functions (15):
//   stage_formatStackString (FUN_68050CA0)
//   stage_deleteStackRange (FUN_68050D20)
//   stage_putStackValue (FUN_68050D70)
//   stage_getStackValue (FUN_68050DE0)
//   stage_putChunkValue (FUN_68050E30)
//   stage_putChunkValueAfter (FUN_68050EC0)
//   stage_pushByteValue (FUN_68050F50)
//   stage_pushShortValue (FUN_68050F70)
//   stage_getOpcodeAccess (FUN_68050F90)
//   stage_pushGlobalRef (FUN_68050FB0)
//   stage_resolveConstValue (FUN_68050FD0)
//   stage_loadPropertyValue (FUN_68051090)
//   stage_loadArgValue (FUN_680510E0)
//   stage_loadLocalValue (FUN_68051130)
//   stage_loadTempValue (FUN_680511B0)

// ============================================================
// Function: stage_formatStackString (FUN_68050ca0)
// Address: 68050ca0
// Size: 114 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_formatStackString(int param_1,uint param_2)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  short local_3c [2];
  int local_38 [12];
  uint local_8;
  
  iVar3 = stage_pushStackValue((int)local_38,local_3c,1);
  if (iVar3 != 0) {
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    iVar3 = **(int **)(param_1 + 0x10);
    uVar1 = *(uint *)(param_1 + 0x1c);
    piVar2 = *(int **)(param_1 + 0x20);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x18));
    score_formatStringEx(param_1,param_2,local_38,(undefined4 *)local_3c,uVar1,piVar2);
  }
  return 0;
}



// ============================================================
// Function: stage_deleteStackRange (FUN_68050d20)
// Address: 68050d20
// Size: 78 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_deleteStackRange(int param_1,uint param_2)
{
  int iVar1;
  short local_3c [2];
  int local_38 [12];
  uint local_8;
  
  iVar1 = stage_pushStackValue((int)local_38,local_3c,1);
  if (iVar1 != 0) {
    score_deleteMatchedRange(param_1,param_2,local_38,(undefined4 *)local_3c);
  }
  return 0;
}



// ============================================================
// Function: stage_putStackValue (FUN_68050d70)
// Address: 68050d70
// Size: 103 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_putStackValue(void *param_1)
{
  int iVar1;
  short local_3c [2];
  int local_38;
  undefined1 local_34 [44];
  uint local_8;
  
  local_38 = 0;
  memset(local_34,0,0x2c);
  local_3c[0] = 0;
  local_3c[1] = 0;
  iVar1 = stage_pushStackValue((int)&local_38,local_3c,1);
  if (iVar1 != 0) {
    core_registerFieldHandlers(param_1,&local_38,(undefined4 *)local_3c);
  }
  return 0;
}



// ============================================================
// Function: stage_getStackValue (FUN_68050de0)
// Address: 68050de0
// Size: 77 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getStackValue(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  iVar2 = stage_pushStackValue(0,(short *)&param_1,1);
  if (iVar2 != 0) {
    core_getMemberValuePair(iVar1,&param_1,&local_c);
    if (*(int *)(iVar1 + 0x7c) == 0) {
      props_pushValue(iVar1);
      *(undefined4 *)(iVar1 + 0x1c) = local_c;
      *(undefined4 *)(iVar1 + 0x20) = local_8;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_putChunkValue (FUN_68050e30)
// Address: 68050e30
// Size: 131 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_putChunkValue(int param_1)
{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  local_14 = *(int *)(param_1 + 0x1c);
  local_10 = *(int **)(param_1 + 0x20);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  local_1c = 4;
  iVar1 = **(int **)(param_1 + 0x10);
  local_c = *(int *)(iVar1 + *(int *)(param_1 + 0x18));
  *(int *)(param_1 + 0x1c) = local_c;
  local_8 = *(int **)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  *(int **)(param_1 + 0x20) = local_8;
  core_resolveChunkValue(param_1,1,&local_c,&local_14,(int)&local_1c);
  props_releaseValue(param_1,(byte)local_c,local_8);
  props_releaseValue(param_1,(byte)local_14,local_10);
  *(undefined4 *)(param_1 + 0x1c) = local_1c;
  *(undefined4 *)(param_1 + 0x20) = local_18;
  return 0;
}



// ============================================================
// Function: stage_putChunkValueAfter (FUN_68050ec0)
// Address: 68050ec0
// Size: 131 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_putChunkValueAfter(int param_1)
{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  int *local_10;
  int local_c;
  int *local_8;
  
  local_14 = *(int *)(param_1 + 0x1c);
  local_10 = *(int **)(param_1 + 0x20);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  local_1c = 4;
  iVar1 = **(int **)(param_1 + 0x10);
  local_c = *(int *)(iVar1 + *(int *)(param_1 + 0x18));
  *(int *)(param_1 + 0x1c) = local_c;
  local_8 = *(int **)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  *(int **)(param_1 + 0x20) = local_8;
  core_resolveChunkValue(param_1,0,&local_c,&local_14,(int)&local_1c);
  props_releaseValue(param_1,(byte)local_c,local_8);
  props_releaseValue(param_1,(byte)local_14,local_10);
  *(undefined4 *)(param_1 + 0x1c) = local_1c;
  *(undefined4 *)(param_1 + 0x20) = local_18;
  return 0;
}



// ============================================================
// Function: stage_pushByteValue (FUN_68050f50)
// Address: 68050f50
// Size: 25 bytes
// Params: int param_1, char param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_pushByteValue(int param_1,char param_2)
{
  props_pushValue(param_1);
  *(int *)(param_1 + 0x20) = (int)param_2;
  return 0;
}



// ============================================================
// Function: stage_pushShortValue (FUN_68050f70)
// Address: 68050f70
// Size: 25 bytes
// Params: int param_1, short param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_pushShortValue(int param_1,short param_2)
{
  props_pushValue(param_1);
  *(int *)(param_1 + 0x20) = (int)param_2;
  return 0;
}



// ============================================================
// Function: stage_getOpcodeAccess (FUN_68050f90)
// Address: 68050f90
// Size: 24 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getOpcodeAccess(int param_1,undefined4 param_2)
{
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x20) = param_2;
  return 0;
}



// ============================================================
// Function: stage_pushGlobalRef (FUN_68050fb0)
// Address: 68050fb0
// Size: 29 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_pushGlobalRef(int param_1,uint param_2)
{
  props_pushValue(param_1);
  *(uint *)(param_1 + 0x20) = param_2 | 0x80000000;
  return 0;
}



// ============================================================
// Function: stage_resolveConstValue (FUN_68050fd0)
// Address: 68050fd0
// Size: 183 bytes
// Params: int param_1, uint * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_resolveConstValue(int param_1,uint *param_2,int param_3)
{
  int iVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  
  *param_2 = *param_2 & 0xff;
  if (*param_2 == 1) {
    iVar4 = *(int *)(**(int **)(param_1 + 0x50) + 0x94) + param_2[1];
    iVar1 = *(int *)(**(int **)(param_1 + 0x50) + iVar4);
    iVar2 = stage_resolveString(param_1,iVar1 + -1,param_2);
    if (iVar2 == 0) {
      props_setError(param_1,2);
      *param_2 = 4;
      return 0;
    }
    Ordinal_1128(*(int *)param_2[1] + 8,**(int **)(param_1 + 0x50) + 4 + iVar4,iVar1);
  }
  else {
    if (*param_2 != 9) goto LAB_68051064;
    props_storeNumber(param_1,*(double *)
                          (*(int *)(**(int **)(param_1 + 0x50) + 0x94) + **(int **)(param_1 + 0x50)
                           + 4 + param_2[1]),param_2);
  }
  puVar3 = (uint *)(**(int **)(param_1 + 0x50) + param_3);
  *puVar3 = puVar3[1] << 8 | *param_2;
  puVar3[1] = param_2[1];
LAB_68051064:
  props_retainValue(param_1,param_2);
  return 0;
}



// ============================================================
// Function: stage_loadPropertyValue (FUN_68051090)
// Address: 68051090
// Size: 65 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_loadPropertyValue(int param_1,int param_2)
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  
  props_pushValue(param_1);
  iVar3 = **(int **)(param_1 + 0x50);
  iVar2 = *(int *)(iVar3 + 0x8c) + param_2 * 8;
  puVar1 = (uint *)(param_1 + 0x1c);
  *puVar1 = *(uint *)(iVar3 + iVar2);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 4 + iVar2);
  if ((*(byte *)puVar1 & 1) != 0) {
    stage_resolveConstValue(param_1,puVar1,iVar2);
  }
  return 0;
}



// ============================================================
// Function: stage_loadArgValue (FUN_680510e0)
// Address: 680510e0
// Size: 67 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_loadArgValue(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = **(int **)(param_1 + 0x28);
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x1c) = 8;
  if ((-1 < param_2) && (param_2 < *(int *)(iVar1 + 0x14))) {
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 0x24 + param_2 * 0x18);
    return 0;
  }
  *(undefined4 *)(param_1 + 0x20) = 0;
  return 0;
}



// ============================================================
// Function: stage_loadLocalValue (FUN_68051130)
// Address: 68051130
// Size: 126 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_loadLocalValue(int param_1,int param_2)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;

  props_pushValue(param_1);
  uVar2 = param_2 * 8;
  if (-1 < (int)uVar2) {
    uVar1 = *(uint *)(param_1 + 0x44);
    uVar3 = ((int)uVar1 >> 0x1f) + ((int)uVar2 >> 0x1f) + (uint)CARRY4(uVar1,uVar2);
    if ((((-2 < (int)uVar3) &&
         (((uVar3 < 0x80000000 || (0x80000000 < uVar1 + uVar2)) && ((int)uVar3 < 1)))) &&
        ((((int)uVar3 < 0 || (uVar1 + uVar2 < 0x80000000)) &&
         ((int)(*(int *)(param_1 + 0x44) + uVar2) < *(int *)(param_1 + 0x40))))) &&
       (puVar4 = (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x44) + uVar2),
       puVar4 != (uint *)0x0)) {
      uVar2 = *puVar4;
      *(uint *)(param_1 + 0x1c) = uVar2;
      *(uint *)(param_1 + 0x20) = puVar4[1];
      if ((uVar2 & 1) != 0) {
        props_retainValue(param_1,(uint *)(param_1 + 0x1c));
      }
    }
  }
  return 0;
}



// ============================================================
// Function: stage_loadTempValue (FUN_680511b0)
// Address: 680511b0
// Size: 126 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_loadTempValue(int param_1,int param_2)
{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;

  props_pushValue(param_1);
  uVar2 = param_2 * 8;
  if (-1 < (int)uVar2) {
    uVar1 = *(uint *)(param_1 + 0x48);
    uVar3 = ((int)uVar1 >> 0x1f) + ((int)uVar2 >> 0x1f) + (uint)CARRY4(uVar1,uVar2);
    if ((((-2 < (int)uVar3) &&
         (((uVar3 < 0x80000000 || (0x80000000 < uVar1 + uVar2)) && ((int)uVar3 < 1)))) &&
        ((((int)uVar3 < 0 || (uVar1 + uVar2 < 0x80000000)) &&
         ((int)(*(int *)(param_1 + 0x48) + uVar2) < *(int *)(param_1 + 0x40))))) &&
       (puVar4 = (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x48) + uVar2),
       puVar4 != (uint *)0x0)) {
      uVar2 = *puVar4;
      *(uint *)(param_1 + 0x1c) = uVar2;
      *(uint *)(param_1 + 0x20) = puVar4[1];
      if ((uVar2 & 1) != 0) {
        props_retainValue(param_1,(uint *)(param_1 + 0x1c));
      }
    }
  }
  return 0;
}



