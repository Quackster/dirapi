// Module: cast
// Topic: Handler execution and script compilation
// Address range: 0x6802EDA0 - 0x6802F340
// Functions (15):
//   cast_compileHandler
//   cast_dispatchPrev
//   cast_dispatchNext
//   cast_dispatchReturn
//   cast_invokeHandlerEx
//   cast_lookupEventId
//   cast_resolveHandler
//   cast_executeHandler
//   cast_checkHandlerArgs
//   cast_getHandlerFlags
//   cast_getResultString
//   cast_teardownHandler
//   cast_getHandlerOffset
//   cast_setHandlerOffset
//   cast_getHandlerArgValue

// ============================================================
// Function: cast_compileHandler (FUN_6802eda0)
// Address: 6802eda0
// Size: 201 bytes
// Params: int * param_1, uint param_2, uint param_3, int * param_4, void * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint cast_compileHandler(int *param_1,uint param_2,uint param_3,int *param_4,void *param_5)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar3 = strings_openCastContext(param_1,param_2,param_3,(int *)&param_5,param_5);
  if (uVar3 == 0) {
    *param_4 = (int)param_5 + 1;
    iVar4 = events_getScoreProperty((int)param_1);
    param_1[0x35] = ((0x6ff < iVar4) - 1 & 0xffffffd1) + 0x2e;
    param_1[0x36] = ((0x7ff < iVar4) - 1 & 0xffffffa3) + 0x5c;
    if (0x10ff < iVar4) {
      return 0;
    }
    piVar1 = *(int **)(**(int **)(*(int *)param_1[2] + 0x4f4) + 0x2c + (int)param_5 * 0x18);
    iVar4 = *piVar1;
    iVar5 = 0;
    iVar6 = 0;
    if (*(int *)(iVar4 + 0x10) < 1) {
      return 0;
    }
    do {
      piVar2 = *(int **)(iVar6 + 0xa8 + iVar4);
      if (piVar2 != (int *)0x0) {
        props_reconvertStrings(*piVar2);
      }
      iVar4 = *piVar1;
      iVar5 = iVar5 + 1;
      iVar6 = iVar6 + 0x10;
    } while (iVar5 < *(int *)(iVar4 + 0x10));
  }
  return uVar3;
}



// ============================================================
// Function: cast_dispatchPrev (FUN_6802ee70)
// Address: 6802ee70
// Size: 41 bytes
// Params: int param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchPrev(int param_1,int param_2,int param_3,int param_4,int param_5)
{
  if (param_2 == 0) {
    return 0;
  }
  strings_saveCastContext(param_1,param_2 + -1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_dispatchNext (FUN_6802eea0)
// Address: 6802eea0
// Size: 37 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchNext(int param_1,int param_2,undefined4 param_3,int param_4,int param_5)
{
  if (param_2 != 0) {
    strings_clearCastBreakpoints(param_1,param_2 + -1,param_3,param_4,param_5);
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchReturn (FUN_6802eed0)
// Address: 6802eed0
// Size: 37 bytes
// Params: int param_1, int param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchReturn(int param_1,int param_2,int param_3,int param_4)
{
  if (param_2 == 0) {
    return 0;
  }
  strings_assignCastResources(param_1,param_2 + -1,param_3,param_4);
  return 0;
}



// ============================================================
// Function: cast_invokeHandlerEx (FUN_6802ef00)
// Address: 6802ef00
// Size: 317 bytes
// Params: void * param_1, int param_2, undefined4 param_3, uint param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_invokeHandlerEx(void *param_1,int param_2,undefined4 param_3,uint param_4,undefined4 param_5)
{
  int iVar1;
  uint uVar2;
  int local_46c;
  int *local_468;
  undefined4 local_464 [279];
  uint local_8;
  
  uVar2 = 0;
  local_46c = -1;
  if (param_2 == 0) {
    return 0;
  }
  iVar1 = *(int *)((int)param_1 + 0x3c);
  *(undefined4 *)((int)param_1 + 0xd4) = 0x2e;
  *(undefined4 *)((int)param_1 + 0xd8) = 0x5c;
  if (param_2 + -1 != iVar1) {
    props_selectScript((int)param_1,param_2 + -1);
    local_46c = iVar1;
  }
  props_parseToken(local_464,param_3);
  iVar1 = 99;
  switch(param_4 & 0xff) {
  case 0:
    uVar2 = 0x85;
    iVar1 = -1;
    break;
  case 1:
    uVar2 = 0x604;
    break;
  case 3:
    uVar2 = 2;
    break;
  case 4:
  case 7:
    uVar2 = 0;
    break;
  case 5:
    uVar2 = 0x803;
    break;
  case 6:
    uVar2 = 0x89;
    iVar1 = -1;
  }
  if ((param_4 & 0x100) != 0) {
    uVar2 = uVar2 | 1;
  }
  if ((param_4 & 0x200) != 0) {
    uVar2 = uVar2 | 0x4000;
  }
  stage_compileHandlerScope(param_1,local_464,iVar1,uVar2,0,param_5,&local_468);
  if ((local_468 != (int *)0x0) && ((*(byte *)(*local_468 + 0x54) & 0x80) == 0)) {
    props_retainObject(param_1,local_468);
  }
  if (local_46c != -1) {
    props_selectScript((int)param_1,local_46c);
  }
  return 0;
}



// ============================================================
// Function: cast_lookupEventId (FUN_6802f060)
// Address: 6802f060
// Size: 28 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_lookupEventId(undefined4 param_1,int param_2)

{
  if (param_2 < 0x1a) {
    return *(undefined4 *)(&DAT_6818d1f0 + param_2 * 4);
  }
  return 0;
}



// ============================================================
// Function: cast_resolveHandler (FUN_6802f080)
// Address: 6802f080
// Size: 117 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_resolveHandler(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  bool bVar3;
  uint uVar4;
  undefined3 extraout_var;
  
  piVar2 = param_2;
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (param_3 < 1) {
    uVar4 = -param_3;
  }
  else if (param_3 < 0x1a) {
    iVar1 = *param_2;
    if ((*(uint *)(iVar1 + 0x6c) & 1 << ((byte)(param_3 + -1) & 0x1f)) == 0) {
      return 0;
    }
    uVar4 = *(uint *)(*(int *)(iVar1 + 0x68) + (param_3 + -1) * 4 + iVar1);
  }
  else {
    uVar4 = props_lookupVariable(param_1,param_2,*(uint *)(&DAT_6818d1f0 + param_3 * 4));
    if ((int)uVar4 < 0) {
      return 0;
    }
  }
  bVar3 = props_executeHandler((int *)param_1,*(int **)(param_1 + 0xe8),piVar2,uVar4,(int *)&param_2);
  return CONCAT31(extraout_var,bVar3);
}



// ============================================================
// Function: cast_executeHandler (FUN_6802f100)
// Address: 6802f100
// Size: 317 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 param_3, uint param_4, uint * param_5, int * param_6, int * param_7
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool cast_executeHandler(int *param_1,undefined4 *param_2,undefined4 param_3,uint param_4,uint *param_5,
                 int *param_6,int *param_7)

{
  uint *puVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  bool bVar5;
  int iVar6;
  uint *puVar7;
  
  piVar3 = param_1;
  *param_7 = 0;
  if (param_2 == (undefined4 *)0x0) {
    return false;
  }
  if (0 < (int)param_4) {
    puVar1 = (uint *)(param_1 + 7);
    param_1 = (int *)param_4;
    puVar7 = param_5;
    do {
      props_pushValue((int)piVar3);
      *puVar1 = *puVar7;
      piVar3[8] = puVar7[1];
      props_retainValue(piVar3,puVar1);
      puVar7 = puVar7 + 2;
      param_1 = (int *)((int)param_1 + -1);
    } while (param_1 != (int *)0x0);
  }
  props_pushValue((int)piVar3);
  piVar4 = param_6;
  piVar3[8] = param_4;
  if (param_6 != (int *)0x0) {
    piVar3[8] = param_4 | 0x80000000;
  }
  uVar2 = piVar3[0x1d];
  iVar6 = (**(code **)(*(int *)*param_2 + 4))(piVar3,param_2,param_3);
  if (iVar6 == 0) {
LAB_6802f210:
    if (-1 < (int)param_4) {
      iVar6 = param_4 + 1;
      do {
        props_popValue((int)piVar3);
        iVar6 = iVar6 + -1;
      } while (iVar6 != 0);
    }
    if ((piVar4 != (int *)0x0) && (*piVar4 != 0)) {
      *piVar4 = 2;
      piVar4[1] = 0;
    }
    return false;
  }
  iVar6 = piVar3[0x1f];
  *param_7 = iVar6;
  if (iVar6 != 0) goto LAB_6802f210;
  bVar5 = true;
  param_4 = uVar2;
  if (piVar3[0x1d] == 2) {
    bVar5 = props_executeHandler(piVar3,(int *)0x2,0,0,(int *)&param_5);
    if (param_5 == (uint *)0x8) {
      *param_7 = piVar3[0x1f];
    }
    else if (param_5 == (uint *)0x3) {
      if (piVar4 == (int *)0x0) goto LAB_6802f201;
      props_popFrame((uint)piVar3);
      param_4 = 9;
    }
  }
  if (piVar4 != (int *)0x0) {
    *piVar4 = piVar3[7];
    piVar4[1] = piVar3[8];
    piVar3[6] = piVar3[6] + -8;
    iVar6 = *(int *)piVar3[4];
    piVar3[7] = *(int *)(iVar6 + piVar3[6]);
    piVar3[8] = *(int *)(iVar6 + 4 + piVar3[6]);
  }
LAB_6802f201:
  piVar3[0x1d] = param_4;
  return bVar5;
}



// ============================================================
// Function: cast_checkHandlerArgs (FUN_6802f240)
// Address: 6802f240
// Size: 32 bytes
// Params: undefined4 param_1, int * param_2, uint param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool cast_checkHandlerArgs(undefined4 param_1,int *param_2,uint param_3)

{
  if (param_2 == (int *)0x0) {
    return false;
  }
  return (*(uint *)(*param_2 + 0x6c) & param_3) != 0;
}



// ============================================================
// Function: cast_getHandlerFlags (FUN_6802f260)
// Address: 6802f260
// Size: 23 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getHandlerFlags(undefined4 param_1,int *param_2)

{
  if (param_2 == (int *)0x0) {
    return 0;
  }
  return *(undefined4 *)(*param_2 + 0x6c);
}



// ============================================================
// Function: cast_getResultString (FUN_6802f280)
// Address: 6802f280
// Size: 79 bytes
// Params: int param_1
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * cast_getResultString(int param_1)

{
  undefined4 *puVar1;
  uint local_c;
  undefined4 local_8;
  
  local_c = *(uint *)(param_1 + 0xac);
  local_8 = *(undefined4 *)(param_1 + 0xb0);
  if (local_c != 2) {
    props_retainValue(param_1,&local_c);
    props_getStringLength(param_1,(int *)&local_c);
    puVar1 = props_detachString(param_1,(int *)&local_c);
    return puVar1;
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: cast_teardownHandler (FUN_6802f2d0)
// Address: 6802f2d0
// Size: 61 bytes
// Params: uint param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_teardownHandler(uint param_1,int *param_2)
{
  if (((param_2 != (int *)0x0) && (**(int **)(param_1 + 8) != 0)) &&
     (*(int *)(**(int **)(param_1 + 8) + 0x4f4) != 0)) {
    props_invalidateHandler(param_1,param_2);
    props_suspendContext(param_1,param_2);
    props_releaseContext(param_1,param_2);
  }
  return 0;
}



// ============================================================
// Function: cast_getHandlerOffset (FUN_6802f310)
// Address: 6802f310
// Size: 15 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getHandlerOffset(undefined4 param_1,int *param_2)

{
  return *(undefined4 *)(*param_2 + 0x5c);
}



// ============================================================
// Function: cast_setHandlerOffset (FUN_6802f320)
// Address: 6802f320
// Size: 18 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_setHandlerOffset(undefined4 param_1,int *param_2,undefined4 param_3)
{
  *(undefined4 *)(*param_2 + 0x5c) = param_3;
  return 0;
}



// ============================================================
// Function: cast_getHandlerArgValue (FUN_6802f340)
// Address: 6802f340
// Size: 73 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getHandlerArgValue(int param_1,int param_2,int param_3)

{
  int iVar1;
  
  if ((param_2 != 0) && (param_3 != 0)) {
    if ((-1 < param_3 + -1) &&
       (iVar1 = **(int **)(**(int **)(**(int **)(param_1 + 8) + 0x4f4) + 0x14 + param_2 * 0x18),
       param_3 + -1 < *(int *)(iVar1 + 0x10))) {
      return *(undefined4 *)(iVar1 + 0x98 + param_3 * 0x10);
    }
  }
  return 0;
}



