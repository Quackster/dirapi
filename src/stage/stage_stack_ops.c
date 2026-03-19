// Module: stage
// Topic: Stack operations and value manipulation
// Address range: 0x680506B0 - 0x68050C00
// Functions (13):
//   stage_compareStackValue (FUN_680506B0)
//   stage_compareStackGreaterEqual (FUN_68050770)
//   stage_compareStackEqual (FUN_68050790)
//   stage_popChunkParams (FUN_680507B0)
//   stage_extractChunkSubstring (FUN_68050890)
//   stage_pushStackValue (stage_pushStackValue)
//   stage_formatChunkString (FUN_680509D0)
//   stage_formatChunkStringEx (FUN_68050A30)
//   stage_deleteChunkRange (FUN_68050AB0)
//   stage_hiliteChunk (FUN_68050B00)
//   stage_evalChunkAndPush (FUN_68050B50)
//   stage_formatChunkStringPersist (FUN_68050BA0)
//   stage_getChunkProperty (FUN_68050C00)

// ============================================================
// Function: stage_compareStackValue (FUN_680506b0)
// Address: 680506b0
// Size: 187 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int stage_compareStackValue(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int local_c;
  int *local_8;
  
  if ((*(int *)(param_1 + 0x40) < 1) ||
     (*(int *)(param_1 + 0x40) + 0x34 <= *(int *)(param_1 + 0x18))) {
    _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_8 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    piVar1 = (int *)(param_1 + 0x1c);
    iVar2 = props_findSubstring(param_1,piVar1,&local_c);
    props_releaseValue(param_1,(byte)local_c,local_8);
    props_releaseValue(param_1,(byte)*piVar1,*(int **)(param_1 + 0x20));
    *piVar1 = 4;
    if (param_2 != 0) {
      *(uint *)(param_1 + 0x20) = (uint)(-1 < iVar2);
      return 0;
    }
    *(uint *)(param_1 + 0x20) = (uint)(iVar2 == 0);
  }
  return 0;
}



// ============================================================
// Function: stage_compareStackGreaterEqual (FUN_68050770)
// Address: 68050770
// Size: 18 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareStackGreaterEqual(int param_1)
{
  stage_compareStackValue(param_1,1);
  return 0;
}



// ============================================================
// Function: stage_compareStackEqual (FUN_68050790)
// Address: 68050790
// Size: 18 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_compareStackEqual(int param_1)
{
  stage_compareStackValue(param_1,0);
  return 0;
}



// ============================================================
// Function: stage_popChunkParams (FUN_680507b0)
// Address: 680507b0
// Size: 209 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 stage_popChunkParams(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int local_c;
  int local_8;
  
  iVar2 = param_2;
  iVar1 = param_1;
  if ((0 < *(int *)(param_1 + 0x40)) &&
     (*(int *)(param_1 + 0x18) + -0x38 < *(int *)(param_1 + 0x40) + 0x34)) {
    props_setError(param_1,0x33);
    return 0;
  }
  uVar5 = 0;
  param_1 = -0x40;
  while( true ) {
    _DAT_68197764 = (int *)(**(int **)(iVar1 + 0x10) + param_1 + *(int *)(iVar1 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_8 = ((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    iVar3 = props_requireInt(iVar1,&local_c,&param_2);
    if (iVar3 == 0) break;
    iVar3 = (int)uVar5 >> 1;
    uVar4 = uVar5 & 1;
    uVar5 = uVar5 + 1;
    param_1 = param_1 + 8;
    *(int *)(iVar2 + (iVar3 * 3 + uVar4) * 4) = param_2;
    if (-1 < param_1) {
      *(undefined4 *)(iVar2 + 8) = 0;
      *(undefined4 *)(iVar2 + 0x14) = 0;
      *(undefined4 *)(iVar2 + 0x20) = 0;
      *(undefined4 *)(iVar2 + 0x2c) = 0;
      *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -0x40;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_extractChunkSubstring (FUN_68050890)
// Address: 68050890
// Size: 110 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_extractChunkSubstring(int param_1)
{
  int *piVar1;
  int iVar2;
  int local_40;
  undefined4 local_3c;
  int local_38 [12];
  uint local_8;
  
  piVar1 = (int *)(param_1 + 0x1c);
  iVar2 = props_validateString(param_1,piVar1);
  if (iVar2 != 0) {
    iVar2 = stage_popChunkParams(param_1,(int)local_38);
    if (iVar2 != 0) {
      iVar2 = score_extractSubstring(param_1,local_38,piVar1,&local_40);
      if (iVar2 != 0) {
        props_releaseValue(param_1,(byte)*piVar1,*(int **)(param_1 + 0x20));
        *piVar1 = local_40;
        *(undefined4 *)(param_1 + 0x20) = local_3c;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: stage_pushStackValue (FUN_68050900)
// Address: 68050900
// Size: 200 bytes
// Params: int param_1, short * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_pushStackValue(int param_1,short *param_2,int param_3)

{
  int *piVar1;
  uint in_EAX;
  int iVar2;
  undefined4 uVar3;
  uint unaff_ESI;
  undefined4 local_c;
  int *local_8;
  
  if ((in_EAX & 0xf) == 6) {
    if (param_3 == 0) {
      local_c = *(undefined4 *)(unaff_ESI + 0x1c);
      local_8 = *(int **)(unaff_ESI + 0x20);
      *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
      iVar2 = **(int **)(unaff_ESI + 0x10);
      *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(iVar2 + *(int *)(unaff_ESI + 0x18));
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(iVar2 + 4 + *(int *)(unaff_ESI + 0x18));
    }
    else {
      local_c = 4;
      local_8 = (int *)0x0;
    }
  }
  if (param_1 != 0) {
    iVar2 = stage_popChunkParams(unaff_ESI,param_1);
    if (iVar2 == 0) {
      return 0;
    }
  }
  uVar3 = *(undefined4 *)(unaff_ESI + 0x1c);
  *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
  piVar1 = *(int **)(unaff_ESI + 0x20);
  iVar2 = **(int **)(unaff_ESI + 0x10);
  *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(iVar2 + *(int *)(unaff_ESI + 0x18));
  *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(iVar2 + 4 + *(int *)(unaff_ESI + 0x18));
  if ((in_EAX & 0xf) == 6) {
    uVar3 = cast_execBridgeAndSet(local_c,uVar3,unaff_ESI,local_c,local_8,uVar3,piVar1,param_2);
    return uVar3;
  }
  *param_2 = (short)piVar1;
  param_2[1] = -1;
  return 1;
}



// ============================================================
// Function: stage_formatChunkString (FUN_680509d0)
// Address: 680509d0
// Size: 85 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_formatChunkString(int param_1,uint param_2)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1;
  iVar4 = stage_pushStackValue(0,(short *)&param_1,0);
  if (iVar4 != 0) {
    *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + -8;
    iVar4 = **(int **)(iVar3 + 0x10);
    uVar1 = *(uint *)(iVar3 + 0x1c);
    piVar2 = *(int **)(iVar3 + 0x20);
    *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar4 + *(int *)(iVar3 + 0x18));
    *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar4 + 4 + *(int *)(iVar3 + 0x18));
    score_formatStringEx(iVar3,param_2,(int *)0x0,&param_1,uVar1,piVar2);
  }
  return 0;
}



// ============================================================
// Function: stage_formatChunkStringEx (FUN_68050a30)
// Address: 68050a30
// Size: 114 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_formatChunkStringEx(int param_1,uint param_2)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  short local_3c [2];
  int local_38 [12];
  uint local_8;
  
  iVar3 = stage_pushStackValue((int)local_38,local_3c,0);
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
// Function: stage_deleteChunkRange (FUN_68050ab0)
// Address: 68050ab0
// Size: 78 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_deleteChunkRange(int param_1,uint param_2)
{
  int iVar1;
  short local_3c [2];
  int local_38 [12];
  uint local_8;
  
  iVar1 = stage_pushStackValue((int)local_38,local_3c,0);
  if (iVar1 != 0) {
    score_deleteMatchedRange(param_1,param_2,local_38,(undefined4 *)local_3c);
  }
  return 0;
}



// ============================================================
// Function: stage_hiliteChunk (FUN_68050b00)
// Address: 68050b00
// Size: 75 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_hiliteChunk(void *param_1)
{
  int iVar1;
  short local_3c [2];
  int local_38 [12];
  uint local_8;
  
  iVar1 = stage_pushStackValue((int)local_38,local_3c,0);
  if (iVar1 != 0) {
    core_registerFieldHandlers(param_1,local_38,(undefined4 *)local_3c);
  }
  return 0;
}



// ============================================================
// Function: stage_evalChunkAndPush (FUN_68050b50)
// Address: 68050b50
// Size: 77 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_evalChunkAndPush(int param_1)
{
  int iVar1;
  int iVar2;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = param_1;
  iVar2 = stage_pushStackValue(0,(short *)&param_1,0);
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
// Function: stage_formatChunkStringPersist (FUN_68050ba0)
// Address: 68050ba0
// Size: 85 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_formatChunkStringPersist(int param_1,uint param_2)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = param_1;
  iVar4 = stage_pushStackValue(0,(short *)&param_1,1);
  if (iVar4 != 0) {
    *(int *)(iVar3 + 0x18) = *(int *)(iVar3 + 0x18) + -8;
    iVar4 = **(int **)(iVar3 + 0x10);
    uVar1 = *(uint *)(iVar3 + 0x1c);
    piVar2 = *(int **)(iVar3 + 0x20);
    *(undefined4 *)(iVar3 + 0x1c) = *(undefined4 *)(iVar4 + *(int *)(iVar3 + 0x18));
    *(undefined4 *)(iVar3 + 0x20) = *(undefined4 *)(iVar4 + 4 + *(int *)(iVar3 + 0x18));
    score_formatStringEx(iVar3,param_2,(int *)0x0,&param_1,uVar1,piVar2);
  }
  return 0;
}



// ============================================================
// Function: stage_getChunkProperty (FUN_68050c00)
// Address: 68050c00
// Size: 149 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getChunkProperty(int param_1,undefined4 param_2)
{
  undefined4 uVar1;
  int iVar2;
  uint *puVar3;
  undefined4 local_c;
  undefined4 local_8;
  
  uVar1 = param_2;
  iVar2 = stage_pushStackValue(0,(short *)&param_2,0);
  if (iVar2 != 0) {
    puVar3 = props_dispatchVariable(param_1,uVar1,(int)(short)param_2,0);
    if (((puVar3 != (uint *)0x0) && (*puVar3 != 0x40)) && (*puVar3 != 0x43)) {
      props_pushValue(param_1);
      *(uint *)(param_1 + 0x1c) = *puVar3;
      *(uint *)(param_1 + 0x20) = puVar3[1];
      props_retainValue(param_1,(uint *)(param_1 + 0x1c));
      return 0;
    }
    iVar2 = score_getXtraProperty(param_1,(undefined4 *)0x0,uVar1,&param_2,&local_c);
    if (iVar2 != 0) {
      props_pushValue(param_1);
      *(undefined4 *)(param_1 + 0x1c) = local_c;
      *(undefined4 *)(param_1 + 0x20) = local_8;
    }
  }
  return 0;
}



