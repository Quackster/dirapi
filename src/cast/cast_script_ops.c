// Module: cast
// Topic: Script stack and value operations
// Address range: 0x68025D60 - 0x68025FF0
// Functions (6):
//   cast_assignStackValue (FUN_68025d60)
//   cast_storeStackValue (FUN_68025dd0)
//   cast_resetStackValue (FUN_68025e10)
//   cast_evalStackProperty (FUN_68025e50)
//   cast_dispatchScriptOp (FUN_68025eb0)
//   cast_executeScriptHandler (FUN_68025ff0)

// ============================================================
// Function: cast_assignStackValue (FUN_68025d60)
// Address: 68025d60
// Size: 105 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_assignStackValue(undefined4 param_1,int param_2,int *param_3)
{
  int iVar1;
  int unaff_ESI;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  int *local_8;
  
  local_c = *(undefined4 *)(unaff_ESI + 0x1c);
  local_8 = *(int **)(unaff_ESI + 0x20);
  *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
  iVar1 = **(int **)(unaff_ESI + 0x10);
  local_14 = *(undefined4 *)(iVar1 + *(int *)(unaff_ESI + 0x18));
  *(undefined4 *)(unaff_ESI + 0x1c) = local_14;
  local_10 = *(undefined4 *)(iVar1 + 4 + *(int *)(unaff_ESI + 0x18));
  *(undefined4 *)(unaff_ESI + 0x20) = local_10;
  core_convertAndAccessValue(&local_14,param_1,unaff_ESI,(int)&local_14,&local_c,param_1,param_2,param_3);
  props_popValue(unaff_ESI);
  props_releaseValue(unaff_ESI,(byte)local_c,local_8);
  return 0;
}



// ============================================================
// Function: cast_storeStackValue (FUN_68025dd0)
// Address: 68025dd0
// Size: 49 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_storeStackValue(undefined4 param_1,int *param_2,int param_3,int param_4)
{
  int unaff_ESI;
  int local_c;
  undefined4 local_8;
  
  local_c = *(int *)(unaff_ESI + 0x1c);
  local_8 = *(undefined4 *)(unaff_ESI + 0x20);
  core_accessScoreChannelType(unaff_ESI,&local_c,param_3,param_4,param_2);
  props_popValue(unaff_ESI);
  return 0;
}



// ============================================================
// Function: cast_resetStackValue (FUN_68025e10)
// Address: 68025e10
// Size: 49 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resetStackValue(void)
{
  int unaff_ESI;
  
  core_resetScriptResult();
  props_popValue(unaff_ESI);
  return 0;
}



// ============================================================
// Function: cast_evalStackProperty (FUN_68025e50)
// Address: 68025e50
// Size: 85 bytes
// Params: int param_1, uint param_2, uint * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_evalStackProperty(int param_1,uint param_2,uint *param_3)
{
  int iVar1;
  double *unaff_ESI;
  int local_c;
  int *local_8;
  
  local_c = *(int *)((int)unaff_ESI + 0x1c);
  local_8 = *(int **)(unaff_ESI + 4);
  *(int *)(unaff_ESI + 3) = *(int *)(unaff_ESI + 3) + -8;
  iVar1 = **(int **)(unaff_ESI + 2);
  *(undefined4 *)((int)unaff_ESI + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(unaff_ESI + 3));
  *(undefined4 *)(unaff_ESI + 4) = *(undefined4 *)(iVar1 + 4 + *(int *)(unaff_ESI + 3));
  core_dispatchChannelProp(unaff_ESI,&local_c,param_1,param_2,param_3);
  props_releaseValue(unaff_ESI,(byte)local_c,local_8);
  return 0;
}



// ============================================================
// Function: cast_dispatchScriptOp (FUN_68025eb0)
// Address: 68025eb0
// Size: 241 bytes
// Params: uint param_1, undefined4 param_2, int param_3, uint param_4, uint * param_5, int param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchScriptOp(uint param_1,undefined4 param_2,int param_3,uint param_4,uint *param_5,int param_6
                 )
{
  switch(param_2) {
  case 2:
    cast_evalUnaryOp(param_4,param_5,param_3,param_4);
    return 0;
  case 3:
    cast_assignStackValue(param_3,param_4,(int *)param_5);
    return 0;
  case 4:
    cast_storeStackValue(param_3,(int *)param_5,param_3,param_4);
    return 0;
  case 5:
    cast_resetStackValue();
    return 0;
  case 6:
    cast_evalStackProperty(param_3,param_4,param_5);
    return 0;
  case 7:
    core_accessChannelData(param_1,param_3,param_4,param_5);
    return 0;
  case 8:
    core_dispatchChannelAccess(param_4,param_3,param_1,param_3,param_4,(int)param_5,param_6);
    break;
  case 9:
  case 10:
  case 0xb:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
  case 0x12:
  case 0x13:
  case 0x14:
  case 0x15:
    cast_evalBinaryOp(param_2,param_3,param_4,param_5,param_6);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: cast_executeScriptHandler (FUN_68025ff0)
// Address: 68025ff0
// Size: 340 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_executeScriptHandler(int param_1)
{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar2 = param_1;
  local_8 = -1;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  if (DAT_68196314 == (code *)0x0) {
    uVar3 = stage_compileHandlerBody(param_1,1);
    events_getMiawMoviePath(param_1,*(undefined4 *)(param_1 + 0x50),uVar3,&local_8);
    if (local_8 < 0) {
      props_setError(param_1,0x5b);
      return 0;
    }
    props_executeOpcode(param_1,local_8);
    return 0;
  }
  iVar4 = stage_compileHandlerBody(param_1,1);
  crt_executePlatformOp(param_1,*(int **)(param_1 + 0x50),(short)*(undefined4 *)(param_1 + 0x54),iVar4,
               &local_10,&local_c,&local_14,(undefined1 *)0x0);
  if (local_c != 0) {
    cast_freeHandle(local_10);
  }
  piVar1 = (int *)(param_1 + 0xc);
  iVar6 = *(int *)(*(int *)(param_1 + 8) + 4);
  param_1 = iVar6;
  if (*piVar1 != 0) {
    param_1 = *(int *)(*piVar1 + 4);
  }
  uVar3 = lingo_initLifecycle(*(int *)(iVar6 + 0x20));
  uVar5 = lingo_initLifecycle(*(int *)(param_1 + 0x20));
  iVar6 = ((code *)(size_t)DAT_68196314)(uVar3,uVar5,*(undefined4 *)(iVar2 + 0x50),iVar4,local_14,0);
  if (iVar6 != 0) {
    events_getMiawMoviePath(iVar2,*(undefined4 *)(iVar2 + 0x50),iVar4,&local_8);
    if (*(code **)(iVar2 + 0x90) != (code *)0x0) {
      *(int *)(iVar2 + 0x98) = iVar4;
      uVar3 = (**(code **)(iVar2 + 0x90))
                        (iVar2,*(undefined4 *)(iVar2 + 0x74),*(undefined4 *)(iVar2 + 0x50),
                         *(undefined4 *)(iVar2 + 0x54),iVar4);
      *(undefined4 *)(iVar2 + 0x74) = uVar3;
    }
  }
  if (*(int *)(iVar2 + 0x74) < 8) {
    if (local_8 == -1) {
      events_getMiawMoviePath(iVar2,*(undefined4 *)(iVar2 + 0x50),iVar4,&local_8);
    }
    if (-1 < local_8) {
      props_executeOpcode(iVar2,local_8);
      return 0;
    }
    props_setError(iVar2,0x5b);
  }
  return 0;
}



