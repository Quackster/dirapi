// Module: props
// Topic: Symbol lookup, hashing, resolution
// Address range: 0x68030d40 - 0x68039820
// Functions (10):
//   props_varRefToSymRef (FUN_68030d40)
//   props_resolveSymbol (FUN_680313f0)
//   props_getSymbolId (FUN_68031410)
//   props_lookupSymbol (FUN_68031ca0)
//   props_resolveSymbolId (FUN_68031e20)
//   props_requireSymbolId (FUN_68031ec0)
//   props_requireInt (FUN_68031f00)
//   props_requireFloat (FUN_68031f40)
//   props_resolvePropertyId (FUN_68038d10)
//   props_hashSymbol (FUN_68039820)



// ============================================================
// Function: props_varRefToSymRef
// Address: 68030d40
// Size: 142 bytes
// Params: int param_1, int param_2, uint param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint props_varRefToSymRef(int param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_3 >> 3;
  if (param_2 < 4) {
    return param_3;
  }
  iVar1 = *(int *)(**(int **)(param_1 + 0x50) + 0x84) + *(int *)(param_1 + 0x54) * 0x3c +
          **(int **)(param_1 + 0x50);
  if (param_2 == 4) {
    if ((int)uVar2 < *(int *)(iVar1 + 0x10)) {
      return *(uint *)(**(int **)(param_1 + 0x50) + uVar2 * 4 + *(int *)(iVar1 + 0x14));
    }
  }
  else {
    if (param_2 != 5) {
      return 0xffffffff;
    }
    if ((int)uVar2 < *(int *)(iVar1 + 0x18)) {
      return *(uint *)(**(int **)(param_1 + 0x50) + uVar2 * 4 + *(int *)(iVar1 + 0x1c));
    }
  }
  stage_logScriptError("Invalid varRef value in lcr_VarRefToSymRef. File may be corrupted");
  return 0xffffffff;
}



// ============================================================
// Function: props_resolveSymbol (FUN_680313f0)
// Address: 680313f0
// Size: 22 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_resolveSymbol(int param_1,uint param_2)
{
  props_resolveHandler(param_1,param_2,1);
  return 0;
}



// ============================================================
// Function: props_getSymbolId (FUN_68031410)
// Address: 68031410
// Size: 41 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getSymbolId(int param_1,int param_2)

{
  if ((-1 < param_2) && (param_2 < *(int *)(**(int **)(param_1 + 0x28) + 0x14))) {
    return *(undefined4 *)(**(int **)(param_1 + 0x28) + 0x24 + param_2 * 0x18);
  }
  return 0xffffffff;
}



// ============================================================
// Function: props_lookupSymbol (FUN_68031ca0)
// Address: 68031ca0
// Size: 114 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_lookupSymbol(undefined4 param_1,undefined4 param_2,int param_3)
{
  int local_46c;
  int local_464 [279];
  uint local_8;
  
  props_hashSymbol(local_464,param_2,param_3);
  props_searchSymbolTable(param_1,local_464);
  if (local_46c == 8) {
    return 0;
  }
  return 0;
}



// ============================================================
// Function: props_resolveSymbolId (FUN_68031e20)
// Address: 68031e20
// Size: 152 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_resolveSymbolId(undefined4 param_1,int *param_2,int *param_3)
{
  ushort uVar1;
  int iVar2;
  byte local_408;
  undefined1 local_407 [1023];
  
  iVar2 = *param_2;
  if (iVar2 == 8) {
    iVar2 = param_2[1];
  }
  else {
    if ((iVar2 != 0x40) && (iVar2 != 0x43)) {
      return 0;
    }
    props_toPascalString(param_2,&local_408);
    if (local_408 == 0xff) {
      uVar1 = Ordinal_1201(local_407);
    }
    else {
      uVar1 = (ushort)local_408;
    }
    iVar2 = props_lookupSymbol(param_1,local_407,(int)(short)uVar1);
  }
  *param_3 = iVar2;
  return 0;
}



// ============================================================
// Function: props_requireSymbolId (FUN_68031ec0)
// Address: 68031ec0
// Size: 60 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_requireSymbolId(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = props_resolveSymbolId(param_1,param_2,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  props_setErrorAndReturn(param_1,0xb);
  return 0;
}



// ============================================================
// Function: props_requireInt (FUN_68031f00)
// Address: 68031f00
// Size: 60 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_requireInt(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = props_coerceToInt(param_1,param_2,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  props_setErrorAndReturn(param_1,7);
  return 0;
}



// ============================================================
// Function: props_requireFloat (FUN_68031f40)
// Address: 68031f40
// Size: 60 bytes
// Params: int param_1, int * param_2, double * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_requireFloat(int param_1,int *param_2,double *param_3)

{
  int iVar1;
  
  iVar1 = props_coerceToFloat(param_1,param_2,param_3);
  if (iVar1 != 0) {
    return 1;
  }
  props_setErrorAndReturn(param_1,9);
  return 0;
}



// ============================================================
// Function: props_resolvePropertyId (FUN_68038d10)
// Address: 68038d10
// Size: 41 bytes
// Params: undefined4 param_1, char * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_resolvePropertyId(undefined4 param_1,char *param_2)
{
  char cVar1;
  char *pcVar2;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  props_lookupSymbol(param_1,param_2,(int)pcVar2 - (int)(param_2 + 1));
  return 0;
}



// ============================================================
// Function: props_hashSymbol (FUN_68039820)
// Address: 68039820
// Size: 42 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_hashSymbol(int *param_1,int param_2,int param_3)
{
  param_1[2] = param_2;
  *param_1 = (int)(param_1 + 2);
  param_1[0x10d] = 0;
  param_1[3] = param_3;
  param_1[1] = 0;
  param_1[5] = 0;
  return 0;
}


