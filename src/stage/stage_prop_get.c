// Module: stage
// Topic: Property get/set by type (local, global, ensure)
// Address range: 0x68051230 - 0x68051800
// Functions (13):
//   stage_getProperty (FUN_68051230)
//   stage_resolveVariable (FUN_68051280)
//   stage_ensureProperty (FUN_680512D0)
//   stage_getLocalProperty (FUN_68051320)
//   stage_getPropertyRef (stage_getPropertyRef)
//   stage_lookupPropRef (FUN_68051400)
//   stage_setGlobalProp (FUN_68051450)
//   stage_setLocalProp (FUN_68051520)
//   stage_setProperty (FUN_680515F0)
//   stage_setVariable (FUN_68051680)
//   stage_setEnsuredProp (FUN_68051700)
//   stage_setLocalPropertyValue (FUN_68051780)
//   stage_checkObjectType (FUN_68051800)

// ============================================================
// Function: stage_getProperty (FUN_68051230)
// Address: 68051230
// Size: 80 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getProperty(int param_1,uint param_2)
{
  uint uVar1;
  uint *puVar2;
  
  props_pushValue(param_1);
  puVar2 = props_getProperty(param_1,param_2,0,(undefined4 *)0x0);
  if (puVar2 == (uint *)0x0) {
    *(undefined4 *)(param_1 + 0x1c) = 2;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    uVar1 = *puVar2;
    *(uint *)(param_1 + 0x1c) = uVar1;
    *(uint *)(param_1 + 0x20) = puVar2[1];
    if ((uVar1 & 1) != 0) {
      props_retainValue(param_1,(uint *)(param_1 + 0x1c));
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_resolveVariable (FUN_68051280)
// Address: 68051280
// Size: 80 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_resolveVariable(int param_1,uint param_2)
{
  uint uVar1;
  uint *puVar2;
  
  props_pushValue(param_1);
  puVar2 = props_resolveVariable(param_1,param_2,0,0);
  if (puVar2 == (uint *)0x0) {
    *(undefined4 *)(param_1 + 0x1c) = 2;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    uVar1 = *puVar2;
    *(uint *)(param_1 + 0x1c) = uVar1;
    *(uint *)(param_1 + 0x20) = puVar2[1];
    if ((uVar1 & 1) != 0) {
      props_retainValue(param_1,(uint *)(param_1 + 0x1c));
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_ensureProperty (FUN_680512d0)
// Address: 680512d0
// Size: 78 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_ensureProperty(int param_1,uint param_2)
{
  uint uVar1;
  uint *puVar2;
  
  props_pushValue(param_1);
  puVar2 = (uint *)props_ensureProperty(param_1,param_2,0);
  if (puVar2 == (uint *)0x0) {
    *(undefined4 *)(param_1 + 0x1c) = 2;
    *(undefined4 *)(param_1 + 0x20) = 0;
  }
  else {
    uVar1 = *puVar2;
    *(uint *)(param_1 + 0x1c) = uVar1;
    *(uint *)(param_1 + 0x20) = puVar2[1];
    if ((uVar1 & 1) != 0) {
      props_retainValue(param_1,(uint *)(param_1 + 0x1c));
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: stage_getLocalProperty (FUN_68051320)
// Address: 68051320
// Size: 59 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getLocalProperty(int param_1,int param_2)
{
  uint uVar1;
  uint *puVar2;
  
  props_pushValue(param_1);
  puVar2 = props_getLocalProperty(param_1,param_2,0);
  if (puVar2 != (uint *)0x0) {
    uVar1 = *puVar2;
    *(uint *)(param_1 + 0x1c) = uVar1;
    *(uint *)(param_1 + 0x20) = puVar2[1];
    if ((uVar1 & 1) != 0) {
      props_retainValue(param_1,(uint *)(param_1 + 0x1c));
    }
  }
  return 0;
}



// ============================================================
// Function: stage_getPropertyRef (FUN_68051360)
// Address: 68051360
// Size: 150 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_getPropertyRef(int param_1)
{
  bool bVar1;
  undefined3 extraout_var;
  int *unaff_EBX;
  undefined *unaff_ESI;
  int *unaff_EDI;
  undefined1 local_408 [1024];
  
  props_storeTableEntry((int)unaff_ESI,*(int *)(unaff_ESI + 0x3c),param_1,(int)local_408);
  bVar1 = cast_isContextValid((int)unaff_ESI);
  if (2 < CONCAT31(extraout_var,bVar1)) {
    props_formatValue((int)unaff_ESI,(byte *)0x6817c4d8);
    props_setupCallback(unaff_ESI,unaff_EDI,(undefined2 *)0x0);
    props_formatValue((int)unaff_ESI,&DAT_6817c158);
  }
  props_formatValue((int)unaff_ESI,(byte *)0x6817c4d8);
  props_setupCallback(unaff_ESI,unaff_EBX,(undefined2 *)0x0);
  props_formatValue((int)unaff_ESI,&DAT_6817c158);
  return 0;
}



// ============================================================
// Function: stage_lookupPropRef (FUN_68051400)
// Address: 68051400
// Size: 69 bytes
// Params: undefined4 param_1, uint param_2, int param_3
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall stage_lookupPropRef(undefined4 param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int in_EAX;
  
  iVar2 = **(int **)(in_EAX + 0x50);
  iVar1 = *(int *)(iVar2 + 0x84) + *(int *)(in_EAX + 0x54) * 0x3c;
  if (param_3 != 0) {
    return *(undefined4 *)(iVar2 + (param_2 >> 3) * 4 + *(int *)(iVar1 + 0x1c + iVar2));
  }
  return *(undefined4 *)(iVar2 + (param_2 >> 3) * 4 + *(int *)(iVar1 + 0x14 + iVar2));
}



// ============================================================
// Function: stage_setGlobalProp (FUN_68051450)
// Address: 68051450
// Size: 199 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setGlobalProp(int param_1,int param_2)
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  uVar3 = param_2 * 8;
  if (-1 < (int)uVar3) {
    uVar1 = *(uint *)(param_1 + 0x48);
    uVar4 = ((int)uVar1 >> 0x1f) + ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar1,uVar3);
    if (((-2 < (int)uVar4) &&
        (((uVar4 < 0x80000000 || (0x80000000 < uVar1 + uVar3)) && ((int)uVar4 < 1)))) &&
       ((((int)uVar4 < 0 || (uVar1 + uVar3 < 0x80000000)) &&
        ((int)(*(int *)(param_1 + 0x48) + uVar3) < *(int *)(param_1 + 0x40))))) {
      puVar5 = (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x48) + uVar3);
      goto LAB_680514ad;
    }
  }
  puVar5 = (uint *)0x0;
LAB_680514ad:
  uVar1 = *puVar5;
  piVar2 = (int *)puVar5[1];
  *puVar5 = *(uint *)(param_1 + 0x1c);
  puVar5[1] = *(uint *)(param_1 + 0x20);
  if (*(int *)(param_1 + 0xe4) != 0) {
    iVar6 = stage_lookupPropRef(uVar3,uVar3,1);
    stage_getPropertyRef(iVar6);
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar6 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar6 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar6 + 4 + *(int *)(param_1 + 0x18));
  if ((uVar1 & 1) != 0) {
    props_releaseValue(param_1,(byte)uVar1,piVar2);
  }
  return 0;
}



// ============================================================
// Function: stage_setLocalProp (FUN_68051520)
// Address: 68051520
// Size: 199 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setLocalProp(int param_1,int param_2)
{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  
  uVar3 = param_2 * 8;
  if (-1 < (int)uVar3) {
    uVar1 = *(uint *)(param_1 + 0x44);
    uVar4 = ((int)uVar1 >> 0x1f) + ((int)uVar3 >> 0x1f) + (uint)CARRY4(uVar1,uVar3);
    if (((-2 < (int)uVar4) &&
        (((uVar4 < 0x80000000 || (0x80000000 < uVar1 + uVar3)) && ((int)uVar4 < 1)))) &&
       ((((int)uVar4 < 0 || (uVar1 + uVar3 < 0x80000000)) &&
        ((int)(*(int *)(param_1 + 0x44) + uVar3) < *(int *)(param_1 + 0x40))))) {
      puVar5 = (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x44) + uVar3);
      goto LAB_6805157d;
    }
  }
  puVar5 = (uint *)0x0;
LAB_6805157d:
  uVar1 = *puVar5;
  piVar2 = (int *)puVar5[1];
  *puVar5 = *(uint *)(param_1 + 0x1c);
  puVar5[1] = *(uint *)(param_1 + 0x20);
  if (*(int *)(param_1 + 0xe4) != 0) {
    iVar6 = stage_lookupPropRef(uVar3,uVar3,0);
    stage_getPropertyRef(iVar6);
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
  iVar6 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar6 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar6 + 4 + *(int *)(param_1 + 0x18));
  if ((uVar1 & 1) != 0) {
    props_releaseValue(param_1,(byte)uVar1,piVar2);
  }
  return 0;
}



// ============================================================
// Function: stage_setProperty (FUN_680515f0)
// Address: 680515f0
// Size: 139 bytes
// Params: uint param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setProperty(uint param_1,uint param_2)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar4 = param_1;
  puVar5 = props_getProperty(param_1,param_2,1,&param_1);
  if (puVar5 != (uint *)0x0) {
    uVar1 = *puVar5;
    piVar2 = (int *)puVar5[1];
    *puVar5 = *(uint *)(uVar4 + 0x1c);
    puVar5[1] = *(uint *)(uVar4 + 0x20);
    core_dispatchAsync(uVar4,param_1,(uint *)(uVar4 + 0x1c));
    if (*(int *)(uVar4 + 0xe4) != 0) {
      stage_getPropertyRef(param_2);
    }
    *(int *)(uVar4 + 0x18) = *(int *)(uVar4 + 0x18) + -8;
    iVar3 = **(int **)(uVar4 + 0x10);
    *(uint *)(uVar4 + 0x1c) = *(uint *)(iVar3 + *(int *)(uVar4 + 0x18));
    *(undefined4 *)(uVar4 + 0x20) = *(undefined4 *)(iVar3 + 4 + *(int *)(uVar4 + 0x18));
    if ((uVar1 & 1) != 0) {
      props_releaseValue(uVar4,(byte)uVar1,piVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_setVariable (FUN_68051680)
// Address: 68051680
// Size: 126 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setVariable(int param_1,uint param_2)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  
  puVar4 = props_resolveVariable(param_1,param_2,1,0);
  if (puVar4 != (uint *)0x0) {
    uVar1 = *puVar4;
    piVar2 = (int *)puVar4[1];
    *puVar4 = *(uint *)(param_1 + 0x1c);
    puVar4[1] = *(uint *)(param_1 + 0x20);
    if (*(int *)(param_1 + 0xe4) != 0) {
      stage_getPropertyRef(param_2);
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    iVar3 = **(int **)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x18));
    if ((uVar1 & 1) != 0) {
      props_releaseValue(param_1,(byte)uVar1,piVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_setEnsuredProp (FUN_68051700)
// Address: 68051700
// Size: 124 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setEnsuredProp(int param_1,uint param_2)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  
  puVar4 = (uint *)props_ensureProperty(param_1,param_2,1);
  if (puVar4 != (uint *)0x0) {
    uVar1 = *puVar4;
    piVar2 = (int *)puVar4[1];
    *puVar4 = *(uint *)(param_1 + 0x1c);
    puVar4[1] = *(uint *)(param_1 + 0x20);
    if (*(int *)(param_1 + 0xe4) != 0) {
      stage_getPropertyRef(param_2);
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    iVar3 = **(int **)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x18));
    if ((uVar1 & 1) != 0) {
      props_releaseValue(param_1,(byte)uVar1,piVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_setLocalPropertyValue (FUN_68051780)
// Address: 68051780
// Size: 124 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_setLocalPropertyValue(int param_1,int param_2)
{
  uint uVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  
  puVar4 = props_getLocalProperty(param_1,param_2,1);
  if (puVar4 != (uint *)0x0) {
    uVar1 = *puVar4;
    piVar2 = (int *)puVar4[1];
    *puVar4 = *(uint *)(param_1 + 0x1c);
    puVar4[1] = *(uint *)(param_1 + 0x20);
    if (*(int *)(param_1 + 0xe4) != 0) {
      stage_getPropertyRef(param_2);
    }
    *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -8;
    iVar3 = **(int **)(param_1 + 0x10);
    *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x18));
    *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x18));
    if ((uVar1 & 1) != 0) {
      props_releaseValue(param_1,(byte)uVar1,piVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: stage_checkObjectType (FUN_68051800)
// Address: 68051800
// Size: 18 bytes
// Params: undefined4 param_1
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall stage_checkObjectType(undefined4 param_1)

{
  undefined4 *in_EAX;
  int iVar1;
  
  iVar1 = score_checkType(param_1,in_EAX);
  return iVar1 == 0x7b;
}



