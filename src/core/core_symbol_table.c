// Module: core
// Topic: Symbol/class table management - vtable creation, lookup, property resolution
// Address range: 0x68016790 - 0x68016D60
// Functions (9):
//   core_lookupSymbolById (0x68016790)
//   core_initSymbolLookups (0x680167D0)
//   core_getSymbolTableSize (0x680168B0)
//   core_clearSymbolLookups (0x680168C0)
//   core_isClassProperty (0x68016950)
//   core_resolveClassProperty (0x68016A00)
//   core_dispatchPropertyAccess (0x68016BA0)
//   core_invokeClassMember (0x68016CA0)
//   core_getClassMemberProperty (0x68016D60)

// ============================================================
// Function: core_lookupSymbolById (FUN_68016790)
// Address: 68016790
// Size: 50 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_lookupSymbolById(undefined4 param_1)
{
  undefined4 *puVar1;
  int in_EAX;
  int *piVar2;
  
  piVar2 = (int *)Ordinal_1111(8,8);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  *(int *)(in_EAX + 0xfc) = *(int *)(in_EAX + 0xfc) + 1;
  puVar1 = (undefined4 *)*piVar2;
  *puVar1 = param_1;
  puVar1[1] = 1;
  return 0;
}



// ============================================================
// Function: core_initSymbolLookups (FUN_680167d0)
// Address: 680167d0
// Size: 217 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_initSymbolLookups(int param_1)
{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = **(int **)(param_1 + 8);
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b3f8);
  *(undefined4 *)(iVar1 + 0x5ac) = uVar2;
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b448);
  *(undefined4 *)(iVar1 + 0x5b0) = uVar2;
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b538);
  *(undefined4 *)(iVar1 + 0x5b4) = uVar2;
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b588);
  *(undefined4 *)(iVar1 + 0x5b8) = uVar2;
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b5d8);
  *(undefined4 *)(iVar1 + 0x5bc) = uVar2;
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b6c8);
  *(undefined4 *)(iVar1 + 0x5c0) = uVar2;
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b718);
  *(undefined4 *)(iVar1 + 0x5c4) = uVar2;
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b768);
  *(undefined4 *)(iVar1 + 0x5c8) = uVar2;
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b628);
  *(undefined4 *)(iVar1 + 0x5cc) = uVar2;
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b498);
  *(undefined4 *)(iVar1 + 0x5d0) = uVar2;
  uVar2 = core_lookupSymbolById(&PTR_LAB_6818b678);
  *(undefined4 *)(iVar1 + 0x5d4) = uVar2;
  return 0;
}



// ============================================================
// Function: core_getSymbolTableSize (FUN_680168b0)
// Address: 680168b0
// Size: 13 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getSymbolTableSize(void)
{
  undefined4 in_EAX;
  int unaff_ESI;
  
  cast_freeHandle(in_EAX);
  *(int *)(unaff_ESI + 0xfc) = *(int *)(unaff_ESI + 0xfc) + -1;
  return 0;
}



// ============================================================
// Function: core_clearSymbolLookups (FUN_680168c0)
// Address: 680168c0
// Size: 140 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_clearSymbolLookups(void)
{
  core_getSymbolTableSize();
  core_getSymbolTableSize();
  core_getSymbolTableSize();
  core_getSymbolTableSize();
  core_getSymbolTableSize();
  core_getSymbolTableSize();
  core_getSymbolTableSize();
  core_getSymbolTableSize();
  core_getSymbolTableSize();
  core_getSymbolTableSize();
  core_getSymbolTableSize();
  return 0;
}



// ============================================================
// Function: core_isClassProperty (FUN_68016950)
// Address: 68016950
// Size: 45 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_isClassProperty(undefined4 param_1,undefined4 param_2)

{
  switch(param_2) {
  case 0x601:
  case 0x602:
  case 0x603:
  case 0x604:
  case 0x605:
  case 0x606:
  case 0x607:
  case 0x608:
  case 0x65f:
  case 0x660:
  case 0x671:
    return 1;
  default:
    return 0;
  }
}



// ============================================================
// Function: core_resolveClassProperty (FUN_68016a00)
// Address: 68016a00
// Size: 246 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resolveClassProperty(int param_1,int param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint local_c;
  int local_8;
  
  iVar1 = **(int **)(param_1 + 8);
  uVar2 = props_getSymbolId(param_1,param_2);
  local_c = 0;
  local_8 = 0;
  switch(uVar2) {
  case 0x601:
    local_8 = *(int *)(iVar1 + 0x5ac);
    break;
  case 0x602:
    local_8 = *(int *)(iVar1 + 0x5b0);
    break;
  case 0x603:
    local_8 = *(int *)(iVar1 + 0x5b4);
    break;
  case 0x604:
    local_8 = *(int *)(iVar1 + 0x5b8);
    break;
  case 0x605:
    local_8 = *(int *)(iVar1 + 0x5bc);
    break;
  case 0x606:
    local_8 = *(int *)(iVar1 + 0x5c0);
    break;
  case 0x607:
    local_8 = *(int *)(iVar1 + 0x5c4);
    break;
  case 0x608:
    local_8 = *(int *)(iVar1 + 0x5c8);
    break;
  default:
    props_setError(param_1,0);
    break;
  case 0x65f:
    local_8 = *(int *)(iVar1 + 0x5cc);
    break;
  case 0x660:
    local_8 = *(int *)(iVar1 + 0x5d0);
    break;
  case 0x671:
    local_8 = *(int *)(iVar1 + 0x5d4);
  }
  if (local_8 != 0) {
    local_c = 3;
  }
  props_retainValue(param_1,&local_c);
  props_pushValue(param_1);
  *(uint *)(param_1 + 0x1c) = local_c;
  *(int *)(param_1 + 0x20) = local_8;
  return 0;
}



// ============================================================
// Function: core_dispatchPropertyAccess (FUN_68016ba0)
// Address: 68016ba0
// Size: 182 bytes
// Params: uint param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_dispatchPropertyAccess(uint param_1,int param_2)
{
  uint local_c [2];
  
  if ((param_2 < 0) || (*(int *)(**(int **)(param_1 + 0x28) + 0x14) <= param_2)) {
    props_setError(param_1,0x33);
  }
  else {
    *(int *)(param_1 + 0xa4) = param_2;
    switch(*(undefined4 *)(**(int **)(param_1 + 0x28) + 0x24 + param_2 * 0x18)) {
    case 0x56:
      score_resolveTimer(param_1,1,1,local_c);
      break;
    default:
      props_reportError(param_1,4);
      return 0;
    case 0x7b:
      crt_invokeMemberMethod(param_1);
      return 0;
    case 0x7c:
      crt_resolveBehaviorRef(param_1,1,local_c);
      break;
    case 0x7d:
      score_setInstanceValue(param_1);
      return 0;
    }
    if (*(int *)(param_1 + 0x7c) == 0) {
      props_popArgs(param_1,local_c);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_invokeClassMember (FUN_68016ca0)
// Address: 68016ca0
// Size: 185 bytes
// Params: int * param_1, int * param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int core_invokeClassMember(int *param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  iVar1 = param_1[8];
  *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
  puVar2 = *(undefined4 **)(*param_2 + 0xc);
  piVar3 = *(int **)(*param_2 + 8);
  local_8 = (**(code **)(*(int *)*piVar3 + 0x1c))(param_1,piVar3);
  iVar4 = (**(code **)(*(int *)*puVar2 + 4))(param_1,puVar2,param_3);
  if (iVar4 != 0) {
    if (param_1[0x1d] == 2) {
      props_dispatchOpcode(param_1,(int *)0x2,0,0);
    }
    if (((iVar1 < 0) && (param_1[0x1d] != 8)) && (param_1[7] == 3)) {
      core_wrapMember((int)param_1,piVar3,(int *)param_1[8],&local_10);
      props_releaseValue(param_1,(byte)param_1[7],(int *)param_1[8]);
      param_1[7] = local_10;
      param_1[8] = local_c;
    }
  }
  (**(code **)(*(int *)*piVar3 + 0x20))(param_1,piVar3,local_8);
  props_releaseObject(param_1,param_2);
  return iVar4;
}



// ============================================================
// Function: core_getClassMemberProperty (FUN_68016d60)
// Address: 68016d60
// Size: 160 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, int * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int core_getClassMemberProperty(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,int *param_5)

{
  undefined4 *puVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  int local_c;
  int local_8;
  
  *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
  puVar1 = *(undefined4 **)(*param_2 + 0xc);
  piVar2 = *(int **)(*param_2 + 8);
  uVar3 = (**(code **)(*(int *)*piVar2 + 0x1c))(param_1,piVar2);
  iVar4 = (**(code **)(*(int *)*puVar1 + 0x18))(param_1,puVar1,param_3,param_4,param_5);
  if ((iVar4 != 0) && (*param_5 == 3)) {
    core_wrapMember(param_1,piVar2,(int *)param_5[1],&local_c);
    props_releaseValue(param_1,(byte)*param_5,(int *)param_5[1]);
    *param_5 = local_c;
    param_5[1] = local_8;
  }
  (**(code **)(*(int *)*piVar2 + 0x20))(param_1,piVar2,uVar3);
  props_releaseObject(param_1,param_2);
  return iVar4;
}


