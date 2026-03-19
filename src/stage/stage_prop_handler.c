// Module: stage
// Topic: Property handler dispatch and string ops
// Address range: 0x68051820 - 0x68051E80
// Functions (13):
//   stage_coerceObject (FUN_68051820)
//   stage_processStringProp (FUN_68051870)
//   stage_handleProperty (stage_handleProperty)
//   stage_invokeStringOp (FUN_68051A90)
//   stage_dispatchGetProp (FUN_68051AF0)
//   stage_dispatchSetProp (FUN_68051B80)
//   stage_dispatchGetMovieProp (FUN_68051C20)
//   stage_dispatchSetMovieProp (FUN_68051CB0)
//   stage_adjustProgramCounter (FUN_68051D50)
//   stage_adjustProgramCounterFail (FUN_68051D80)
//   stage_branchIfFalse (FUN_68051DC0)
//   stage_getSymbolProp (FUN_68051E30)
//   stage_setSymbolProp (FUN_68051E80)

// ============================================================
// Function: stage_coerceObject (FUN_68051820)
// Address: 68051820
// Size: 79 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_coerceObject(void)
{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  int unaff_ESI;
  undefined4 local_c;
  undefined4 local_8;
  
  bVar1 = stage_checkObjectType(unaff_ESI);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = (**(code **)(*(int *)**(undefined4 **)(unaff_ESI + 0x20) + 0x18))();
    if (iVar2 != 0) {
      props_popValue(unaff_ESI);
      props_pushValue(unaff_ESI);
      *(undefined4 *)(unaff_ESI + 0x1c) = local_c;
      *(undefined4 *)(unaff_ESI + 0x20) = local_8;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_processStringProp (FUN_68051870)
// Address: 68051870
// Size: 159 bytes
// Params: void * this, int * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall stage_processStringProp(void *this,int *param_1)
{
  int *piVar1;
  bool bVar2;
  undefined3 extraout_var;
  int iVar3;
  byte *pbVar4;
  int unaff_EBX;
  undefined1 local_48 [4];
  int local_44;
  int local_40;
  int *local_3c;
  int local_38 [12];
  uint local_8;
  
  local_3c = param_1;
  piVar1 = (int *)((int)this + 0x1c);
  bVar2 = stage_checkObjectType(this);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    stage_coerceObject();
  }
  iVar3 = props_validateString((int)this,piVar1);
  if (iVar3 != 0) {
    pbVar4 = (byte *)props_getStringData(piVar1,&local_40);
    props_invokeBuiltin((int)this,unaff_EBX + 1,(int)local_48,pbVar4,local_40);
    props_unlockString(piVar1);
    Ordinal_1130(local_38,0x30);
    local_38[unaff_EBX * 3] = local_44;
    local_38[unaff_EBX * 3 + 1] = local_44;
    score_extractSubstring((int)this,local_38,piVar1,local_3c);
    props_popValue((int)this);
  }
  return 0;
}



// ============================================================
// Function: stage_handleProperty (FUN_68051910)
// Address: 68051910
// Size: 344 bytes
// Params: int param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_handleProperty(int param_1,int param_2,int *param_3)
{
  uint uVar1;
  int iVar2;
  int *piVar3;
  void *unaff_ESI;
  int iVar4;
  int local_c;
  int local_8;
  
  switch(param_1) {
  case 0:
    if (param_2 == 0) {
      param_3[1] = *(int *)(**(int **)((int)unaff_ESI + 8) + 0x4fc);
      return 0;
    }
    iVar4 = props_requireInt((int)unaff_ESI,param_3,&local_c);
    if (iVar4 != 0) {
      *(int *)(**(int **)((int)unaff_ESI + 8) + 0x4fc) = local_c;
      return 0;
    }
    break;
  case 1:
  case 2:
  case 3:
  case 4:
  case 5:
    piVar3 = *(int **)((int)unaff_ESI + 0x34);
    local_8 = 0;
    uVar1 = events_navigateToFrame((int)unaff_ESI,1);
    iVar4 = uVar1 - 1;
    if ((iVar4 < 0) || (iVar4 == *(int *)((int)unaff_ESI + 0x3c))) {
      iVar4 = -1;
    }
    else {
      piVar3 = *(int **)(**(int **)(**(int **)((int)unaff_ESI + 8) + 0x4f4) + 0x34 + iVar4 * 0x18);
    }
    if (param_2 == 0) {
      props_createStringHandle((int)unaff_ESI,*(int **)(*piVar3 + -4 + param_1 * 4),param_3);
      return 0;
    }
    iVar2 = props_validateString((int)unaff_ESI,param_3);
    if (iVar2 != 0) {
      if (-1 < iVar4) {
        local_8 = *(int *)((int)unaff_ESI + 0x3c);
        props_selectScript((int)unaff_ESI,iVar4);
      }
      props_setHandlerSlot(unaff_ESI,piVar3,param_1 + -1,param_3);
      if (-1 < iVar4) {
        props_selectScript((int)unaff_ESI,local_8);
      }
    }
    break;
  case 6:
  case 7:
  case 8:
    if (param_2 == 0) {
      props_formatTimeString((int)unaff_ESI,param_1 + -6,param_3);
      return 0;
    }
    break;
  case 9:
  case 10:
  case 0xb:
    if (param_2 == 0) {
      props_formatDateString((int)unaff_ESI,param_1 + -9,param_3);
      return 0;
    }
    break;
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
    if (param_2 == 0) {
      stage_processStringProp(unaff_ESI,param_3);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_invokeStringOp (FUN_68051a90)
// Address: 68051a90
// Size: 89 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_invokeStringOp(int param_1,int param_2)
{
  int *piVar1;
  bool bVar2;
  int in_EAX;
  undefined3 extraout_var;
  int iVar3;
  byte *pbVar4;
  int local_8;
  
  piVar1 = (int *)(in_EAX + 0x1c);
  bVar2 = stage_checkObjectType(in_EAX);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    stage_coerceObject();
  }
  iVar3 = props_validateString(in_EAX,piVar1);
  if (iVar3 != 0) {
    pbVar4 = (byte *)props_getStringData(piVar1,&local_8);
    props_invokeBuiltin(in_EAX,param_1,param_2,pbVar4,local_8);
    props_unlockString(piVar1);
    props_popValue(in_EAX);
  }
  return 0;
}



// ============================================================
// Function: stage_dispatchGetProp (FUN_68051af0)
// Address: 68051af0
// Size: 135 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchGetProp(uint param_1,int param_2)
{
  int iVar1;
  int iVar2;
  uint local_c;
  undefined4 local_8;
  
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar1 = **(int **)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  local_c = 4;
  if (param_2 == 0) {
    stage_handleProperty(iVar2,0,(int *)&local_c);
  }
  else if (param_2 == 1) {
    stage_invokeStringOp(iVar2,(int)&local_c);
  }
  else {
    cast_dispatchScriptOp(param_1,param_2,iVar2,0,&local_c,0);
  }
  if (*(int *)(param_1 + 0x7c) == 0) {
    props_pushValue(param_1);
    *(uint *)(param_1 + 0x1c) = local_c;
    *(undefined4 *)(param_1 + 0x20) = local_8;
  }
  return 0;
}



// ============================================================
// Function: stage_dispatchSetProp (FUN_68051b80)
// Address: 68051b80
// Size: 152 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchSetProp(uint param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_c;
  int *local_8;
  
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar3 = *(int *)(param_1 + 0x18);
  iVar1 = **(int **)(param_1 + 0x10);
  local_c = *(uint *)(iVar1 + iVar3);
  *(uint *)(param_1 + 0x1c) = local_c;
  iVar2 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + iVar3);
  local_8 = *(int **)(param_1 + 0x20);
  iVar3 = iVar3 + -8;
  *(int *)(param_1 + 0x18) = iVar3;
  iVar1 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + iVar3);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + iVar3);
  if (param_2 == 0) {
    stage_handleProperty(iVar2,1,(int *)&local_c);
  }
  else if (param_2 == 1) {
    stage_invokeStringOp(iVar2,(int)&local_c);
  }
  else {
    cast_dispatchScriptOp(param_1,param_2,iVar2,1,&local_c,0);
  }
  props_releaseValue(param_1,(byte)local_c,local_8);
  return 0;
}



// ============================================================
// Function: stage_dispatchGetMovieProp (FUN_68051c20)
// Address: 68051c20
// Size: 135 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchGetMovieProp(uint param_1,int param_2)
{
  int iVar1;
  int iVar2;
  uint local_c;
  undefined4 local_8;
  
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar1 = **(int **)(param_1 + 0x10);
  iVar2 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  local_c = 4;
  if (param_2 == 0) {
    stage_handleProperty(iVar2,0,(int *)&local_c);
  }
  else if (param_2 == 1) {
    stage_invokeStringOp(iVar2,(int)&local_c);
  }
  else {
    cast_dispatchScriptOp(param_1,param_2,iVar2,0,&local_c,1);
  }
  if (*(int *)(param_1 + 0x7c) == 0) {
    props_pushValue(param_1);
    *(uint *)(param_1 + 0x1c) = local_c;
    *(undefined4 *)(param_1 + 0x20) = local_8;
  }
  return 0;
}



// ============================================================
// Function: stage_dispatchSetMovieProp (FUN_68051cb0)
// Address: 68051cb0
// Size: 152 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_dispatchSetMovieProp(uint param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  uint local_c;
  int *local_8;
  
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar3 = *(int *)(param_1 + 0x18);
  iVar1 = **(int **)(param_1 + 0x10);
  local_c = *(uint *)(iVar1 + iVar3);
  *(uint *)(param_1 + 0x1c) = local_c;
  iVar2 = *(int *)(param_1 + 0x20);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + iVar3);
  local_8 = *(int **)(param_1 + 0x20);
  iVar3 = iVar3 + -8;
  *(int *)(param_1 + 0x18) = iVar3;
  iVar1 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + iVar3);
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + iVar3);
  if (param_2 == 0) {
    stage_handleProperty(iVar2,1,(int *)&local_c);
  }
  else if (param_2 == 1) {
    stage_invokeStringOp(iVar2,(int)&local_c);
  }
  else {
    cast_dispatchScriptOp(param_1,param_2,iVar2,1,&local_c,1);
  }
  props_releaseValue(param_1,(byte)local_c,local_8);
  return 0;
}



// ============================================================
// Function: stage_adjustProgramCounter (FUN_68051d50)
// Address: 68051d50
// Size: 38 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_adjustProgramCounter(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x104) >> 6;
  if (iVar1 == 3) {
    iVar1 = 4;
  }
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + (param_2 - iVar1) + -1;
  return 0;
}



// ============================================================
// Function: stage_adjustProgramCounterFail (FUN_68051d80)
// Address: 68051d80
// Size: 54 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_adjustProgramCounterFail(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_1 + 0x104) >> 6;
  if (iVar2 == 3) {
    iVar2 = 4;
  }
  iVar1 = cast_getRuntimeRef(param_1);
  if (iVar1 == 0) {
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + ((-1 - iVar2) - param_2);
  }
  return 0;
}



// ============================================================
// Function: stage_branchIfFalse (FUN_68051dc0)
// Address: 68051dc0
// Size: 101 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_branchIfFalse(int param_1,int param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x104) >> 6;
  if (iVar1 == 3) {
    iVar1 = 4;
  }
  if ((*(int *)(param_1 + 0x1c) != 4) && (*(int *)(param_1 + 0x1c) != 2)) {
    props_setErrorAndReturn(param_1,7);
    return 0;
  }
  if (*(int *)(param_1 + 0x20) == 0) {
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + (param_2 - iVar1) + -1;
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar1 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  return 0;
}



// ============================================================
// Function: stage_getSymbolProp (FUN_68051e30)
// Address: 68051e30
// Size: 78 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getSymbolProp(uint param_1,int param_2)
{
  int iVar1;
  uint *puVar2;
  uint local_c;
  undefined4 local_8;
  
  puVar2 = &local_c;
  local_c = 4;
  local_8 = 0;
  iVar1 = props_getSymbolId(param_1,param_2);
  props_accessGlobalProps(param_1,0,iVar1,puVar2);
  if (*(int *)(param_1 + 0x7c) == 0) {
    props_pushValue(param_1);
    *(uint *)(param_1 + 0x1c) = local_c;
    *(undefined4 *)(param_1 + 0x20) = local_8;
  }
  return 0;
}



// ============================================================
// Function: stage_setSymbolProp (FUN_68051e80)
// Address: 68051e80
// Size: 91 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setSymbolProp(uint param_1,int param_2)
{
  int iVar1;
  uint *puVar2;
  uint local_c;
  int *local_8;
  
  local_c = *(uint *)(param_1 + 0x1c);
  local_8 = *(int **)(param_1 + 0x20);
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar1 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
  puVar2 = &local_c;
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  iVar1 = props_getSymbolId(param_1,param_2);
  props_accessGlobalProps(param_1,1,iVar1,puVar2);
  props_releaseValue(param_1,(byte)local_c,local_8);
  return 0;
}



