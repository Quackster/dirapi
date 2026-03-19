// Module: stage
// Topic: Context data serialization and lifecycle
// Address range: 0x68057CE0 - 0x68058570
// Functions (13):
//   stage_deserializeContextData (FUN_68057CE0)
//   stage_deserializeScriptData (FUN_68057E60)
//   stage_registerContextNode (FUN_680580E0)
//   stage_unregisterContextNode (FUN_68058140)
//   stage_formatDataError (FUN_68058190)
//   stage_delegatePropertyAccess (FUN_68058250)
//   stage_propagateInvalidation (FUN_68058280)
//   stage_propagateCleanup (FUN_68058320)
//   stage_serializePropertyTable (FUN_680583A0)
//   stage_initDataNode (FUN_68058430)
//   stage_isContextType (FUN_68058510)
//   stage_isDataNode (FUN_68058540)
//   stage_getDataNodeParam (FUN_68058570)

// ============================================================
// Function: stage_deserializeContextData (FUN_68057CE0)
// Address: 68057ce0
// Size: 384 bytes
// Params: undefined4 * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_deserializeContextData(undefined4 *param_1,int *param_2)
{
  int local_18;
  int *piVar1;
  int iVar2;
  bool bVar3;
  uint uVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int local_c10;
  undefined4 local_c0c;
  byte local_c08 [1024];
  byte local_808 [1024];
  byte local_408 [1024];
  uint local_8;
  
  piVar1 = (int *)*param_1;
  local_c10 = 0;
  events_getWindowStyle(piVar1,*(int *)(*param_2 + 0x20) + 1,param_2,(undefined2 *)local_c08,
               (undefined2 *)local_808,(undefined2 *)local_408);
  uVar4 = stage_serializeData(param_1,param_2,0,0xd,4);
  if (uVar4 == 0) {
    local_c10 = 4;
    local_c0c = *(undefined4 *)(*param_2 + 0x5c);
    bVar3 = stage_serializeFloat(param_1,&local_c10);
    if (CONCAT31(extraout_var,bVar3) == 0) {
      props_readPascalString((int)piVar1,local_408,&local_c10);
      bVar3 = stage_serializeFloat(param_1,&local_c10);
      if (CONCAT31(extraout_var_00,bVar3) == 0) {
        props_releaseValue(piVar1,(byte)*(undefined4 *)(*param_2 + 0x3c),*(int **)(*param_2 + 0x40));
        iVar2 = *param_2;
        *(int *)(iVar2 + 0x3c) = local_c10;
        *(undefined4 *)(iVar2 + 0x40) = local_c0c;
        props_readPascalString((int)piVar1,local_808,&local_c10);
        bVar3 = stage_serializeFloat(param_1,&local_c10);
        if (CONCAT31(extraout_var_01,bVar3) == 0) {
          props_releaseValue(piVar1,(byte)*(undefined4 *)(*param_2 + 0x44),*(int **)(*param_2 + 0x48));
          iVar2 = *param_2;
          *(int *)(iVar2 + 0x44) = local_c10;
          *(undefined4 *)(iVar2 + 0x48) = local_c0c;
          props_readPascalString((int)piVar1,local_c08,&local_c10);
          bVar3 = stage_serializeFloat(param_1,&local_c10);
          if (CONCAT31(extraout_var_02,bVar3) == 0) {
            props_releaseValue(piVar1,(byte)*(undefined4 *)(*param_2 + 0x4c),*(int **)(*param_2 + 0x50));
            iVar2 = *param_2;
            *(int *)(iVar2 + 0x4c) = local_c10;
            *(undefined4 *)(iVar2 + 0x50) = local_c0c;
          }
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: stage_deserializeScriptData (FUN_68057E60)
// Address: 68057e60
// Size: 637 bytes
// Params: int * param_1, undefined4 param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_deserializeScriptData(int *param_1,undefined4 param_2,int param_3,uint *param_4)
{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *piVar5;
  int *piVar6;
  int iVar7;
  int local_c28;
  undefined4 local_c24;
  uint local_c20;
  undefined4 local_c1c;
  uint *local_c18;
  int *local_c14;
  uint local_c10;
  undefined4 local_c0c;
  undefined1 local_c08 [1024];
  undefined1 local_808 [1024];
  undefined1 local_408 [1024];
  uint local_8;
  
  iVar7 = *param_1;
  local_c14 = param_1;
  local_c18 = param_4;
  iVar2 = stage_allocFactorySlot((int)param_1,&local_c28);
  if (((iVar2 == 0) && (3 < param_3)) && (uVar3 = stage_allocString(param_1,&local_c10), uVar3 == 0)) {
    local_c24 = local_c0c;
    uVar3 = stage_allocString(param_1,&local_c10);
    if ((uVar3 == 0) && ((local_c10 == 0x40 || (local_c10 == 0x43)))) {
      props_toPascalString((int *)&local_c10,local_c08);
      local_c20 = local_c10;
      local_c1c = local_c0c;
      uVar3 = stage_allocString(param_1,&local_c10);
      if ((uVar3 == 0) && ((local_c10 == 0x40 || (local_c10 == 0x43)))) {
        props_toPascalString((int *)&local_c10,local_408);
        uVar1 = local_c0c;
        uVar3 = local_c10;
        uVar4 = stage_allocString(param_1,&local_c10);
        if ((uVar4 == 0) && ((local_c10 == 0x40 || (local_c10 == 0x43)))) {
          props_toPascalString((int *)&local_c10,local_808);
          piVar5 = (int *)events_setWindowStyle(iVar7,local_408,local_808,(int)local_c08,local_c24);
          piVar6 = local_c14;
          if (piVar5 != (int *)0x0) {
            props_releaseValue(iVar7,(byte)*(undefined4 *)(*piVar5 + 0x3c),*(int **)(*piVar5 + 0x40));
            iVar2 = *piVar5;
            *(uint *)(iVar2 + 0x3c) = local_c20;
            *(undefined4 *)(iVar2 + 0x40) = local_c1c;
            props_releaseValue(iVar7,(byte)*(undefined4 *)(*piVar5 + 0x44),*(int **)(*piVar5 + 0x48));
            iVar2 = *piVar5;
            *(uint *)(iVar2 + 0x44) = uVar3;
            *(undefined4 *)(iVar2 + 0x48) = uVar1;
            props_releaseValue(iVar7,(byte)*(undefined4 *)(*piVar5 + 0x4c),*(int **)(*piVar5 + 0x50));
            iVar2 = *piVar5;
            *(uint *)(iVar2 + 0x4c) = local_c10;
            *(undefined4 *)(iVar2 + 0x50) = local_c0c;
            local_c18[1] = (uint)piVar5;
            *local_c18 = 3;
            props_retainValue(iVar7,local_c18);
            piVar6 = local_c14;
            stage_createFactory((int)local_c14,local_c28,local_c18);
          }
          iVar7 = param_3 + -4;
          while ((0 < iVar7 && (uVar3 = stage_allocString(piVar6,&local_c10), uVar3 == 0))) {
            iVar7 = iVar7 + -1;
          }
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: stage_registerContextNode (FUN_680580E0)
// Address: 680580e0
// Size: 90 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_registerContextNode(int param_1,int *param_2)
{
  int iVar1;
  
  *(undefined ***)*param_2 = &PTR_LAB_6818d9a8;
  iVar1 = **(int **)(param_1 + 8);
  *(undefined4 *)(*param_2 + 8) = *(undefined4 *)(**(int **)(iVar1 + 0x55c) + 8);
  *(undefined4 *)(*param_2 + 0xc) = *(undefined4 *)(iVar1 + 0x55c);
  *(int **)(**(int **)(**(int **)(iVar1 + 0x55c) + 8) + 0xc) = param_2;
  *(int **)(**(int **)(iVar1 + 0x55c) + 8) = param_2;
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
  return 0;
}



// ============================================================
// Function: stage_unregisterContextNode (FUN_68058140)
// Address: 68058140
// Size: 72 bytes
// Params: uint param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_unregisterContextNode(uint param_1,int *param_2)
{
  if (*(int **)(*param_2 + 0x10) != (int *)0x0) {
    props_releaseContext(param_1,*(int **)(*param_2 + 0x10));
  }
  *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
  *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
  props_freeTable(param_1,param_2);
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + -1;
  return 0;
}



// ============================================================
// Function: stage_formatDataError (FUN_68058190)
// Address: 68058190
// Size: 189 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_formatDataError(int *param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  int *piVar1;
  undefined2 local_408 [512];
  uint local_8;
  
  piVar1 = *(int **)(*param_2 + 0x10);
  if (piVar1 != (int *)0x0) {
    events_getWindowStyle(param_1,*(int *)(*piVar1 + 0x20) + 1,piVar1,(undefined2 *)0x0,(undefined2 *)0x0,
                 local_408);
    cast_loadPascalString(&DAT_68197780,0x898,0x2a);
    props_formatString(param_1,param_3,param_4,&DAT_68197781);
    return 0;
  }
  cast_loadPascalString(&DAT_68197780,0x898,0x3e);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: stage_delegatePropertyAccess (FUN_68058250)
// Address: 68058250
// Size: 33 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_delegatePropertyAccess(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)
{
  stage_accessProperty(param_1,param_4);
  return 0;
}



// ============================================================
// Function: stage_propagateInvalidation (FUN_68058280)
// Address: 68058280
// Size: 147 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_propagateInvalidation(undefined4 param_1,int *param_2)
{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  int local_10;
  int *local_c;
  int local_8;
  
  piVar4 = param_2;
  local_8 = 0;
  piVar2 = *(int **)(*param_2 + 0x10);
  puVar1 = (uint *)(*param_2 + 4);
  *puVar1 = *puVar1 | 0x80000000;
  if (piVar2 != (int *)0x0) {
    uVar3 = *(uint *)(*piVar2 + 4);
    if (-1 < (int)uVar3) {
      *(uint *)(*piVar2 + 4) = uVar3 | 0x80000000;
      (**(code **)(*(int *)*piVar2 + 0x34))(param_1,piVar2);
    }
  }
  iVar5 = score_iterateProperties(piVar4,&local_8,(int *)&param_2,&local_10);
  while (iVar5 != 0) {
    if ((local_10 == 3) && ((((int *)*local_c)[1] & 0x80000000U) == 0)) {
      (**(code **)(*(int *)*local_c + 0x34))(param_1,local_c);
    }
    iVar5 = score_iterateProperties(piVar4,&local_8,(int *)&param_2,&local_10);
  }
  return 0;
}



// ============================================================
// Function: stage_propagateCleanup (FUN_68058320)
// Address: 68058320
// Size: 119 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_propagateCleanup(undefined4 param_1,int *param_2)
{
  undefined4 *puVar1;
  int *piVar2;
  int iVar3;
  int local_10;
  undefined4 *local_c;
  int local_8;
  
  piVar2 = param_2;
  local_8 = 0;
  puVar1 = *(undefined4 **)(*param_2 + 0x10);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)(*(int *)*puVar1 + 0x3c))(param_1,puVar1);
  }
  iVar3 = score_iterateProperties(piVar2,&local_8,(int *)&param_2,&local_10);
  while (iVar3 != 0) {
    if (((byte)local_10 & 0x1f) == 3) {
      (**(code **)(*(int *)*local_c + 0x3c))(param_1,local_c);
    }
    iVar3 = score_iterateProperties(piVar2,&local_8,(int *)&param_2,&local_10);
  }
  return 0;
}



// ============================================================
// Function: stage_serializePropertyTable (FUN_680583A0)
// Address: 680583a0
// Size: 144 bytes
// Params: undefined4 * param_1, int * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint stage_serializePropertyTable(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  int local_18 [2];
  int local_10;
  int local_c;
  int local_8;
  
  local_8 = 0;
  iVar2 = score_clearPropertyTable(param_2);
  uVar3 = stage_serializeData(param_1,param_2,*(int *)(*param_2 + 0x10),0,iVar2 * 2);
  if (uVar3 == 0) {
    local_10 = 8;
    iVar2 = score_iterateProperties(param_2,&local_8,&local_c,local_18);
    while (iVar2 != 0) {
      bVar1 = stage_serializeFloat(param_1,&local_10);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        return CONCAT31(extraout_var,bVar1);
      }
      bVar1 = stage_serializeFloat(param_1,local_18);
      if (CONCAT31(extraout_var_00,bVar1) != 0) {
        return CONCAT31(extraout_var_00,bVar1);
      }
      iVar2 = score_iterateProperties(param_2,&local_8,&local_c,local_18);
      uVar3 = 0;
    }
  }
  return uVar3;
}



// ============================================================
// Function: stage_initDataNode (FUN_68058430)
// Address: 68058430
// Size: 223 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_initDataNode(int param_1,int *param_2,int param_3)
{
  int iVar1;
  
  *(undefined ***)*param_2 = &PTR_LAB_6818d9f8;
  *(undefined4 *)(*param_2 + 4) = 1;
  *(int *)(*param_2 + 0x10) = param_3;
  if (param_3 != 0) {
    iVar1 = **(int **)(param_1 + 8);
    *(undefined4 *)(*param_2 + 8) = *(undefined4 *)(**(int **)(iVar1 + 0x564) + 8);
    *(undefined4 *)(*param_2 + 0xc) = *(undefined4 *)(iVar1 + 0x564);
    *(int **)(**(int **)(**(int **)(iVar1 + 0x564) + 8) + 0xc) = param_2;
    *(int **)(**(int **)(iVar1 + 0x564) + 8) = param_2;
    *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
    return 0;
  }
  iVar1 = **(int **)(param_1 + 8);
  *(undefined4 *)(**(int **)(iVar1 + 0x4e4) + 8) = *(undefined4 *)(**(int **)(iVar1 + 0x55c) + 8);
  *(undefined4 *)(**(int **)(**(int **)(param_1 + 8) + 0x4e4) + 0xc) =
       *(undefined4 *)(iVar1 + 0x55c);
  *(undefined4 *)(**(int **)(**(int **)(iVar1 + 0x55c) + 8) + 0xc) =
       *(undefined4 *)(**(int **)(param_1 + 8) + 0x4e4);
  *(undefined4 *)(**(int **)(iVar1 + 0x55c) + 8) = *(undefined4 *)(**(int **)(param_1 + 8) + 0x4e4);
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
  return 0;
}



// ============================================================
// Function: stage_isContextType (FUN_68058510)
// Address: 68058510
// Size: 47 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_isContextType(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) &&
     (((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d9a8 ||
      ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d9f8)))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_isDataNode (FUN_68058540)
// Address: 68058540
// Size: 35 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_isDataNode(undefined4 param_1,undefined4 *param_2)

{
  if ((param_2 != (undefined4 *)0x0) && (*(undefined ***)*param_2 == &PTR_LAB_6818d9f8)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: stage_getDataNodeParam (FUN_68058570)
// Address: 68058570
// Size: 33 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_getDataNodeParam(int *param_1)

{
  if ((param_1 != (int *)0x0) && (*(undefined ***)*param_1 == &PTR_LAB_6818d9f8)) {
    return ((int *)*param_1)[4];
  }
  return 0;
}



