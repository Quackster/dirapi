// Module: stage
// Topic: String and number allocation
// Address range: 0x6805A710 - 0x6805AD60
// Functions (17):
//   stage_dispatchAllocType (FUN_6805A710)
//   stage_allocString (FUN_6805A7C0)
//   stage_removePropertyRef (FUN_6805AA00)
//   stage_checkCallbackOwner (FUN_6805AA60)
//   stage_freeAllocSlot (FUN_6805AAB0)
//   stage_freeAllAllocSlots (FUN_6805AB20)
//   stage_resolveString (FUN_6805AB80)
//   stage_initStringLabel (FUN_6805ABD0)
//   stage_formatAllocError (FUN_6805AC10)
//   stage_allocNumberHandle (FUN_6805AC50)
//   stage_convertToShort (FUN_6805ACA0)
//   stage_initDateGlobals (FUN_6805ACC0)
//   stage_endDateScope (FUN_6805AD10)
//   stage_readAllocValue (FUN_6805AD20)
//   stage_endParseScope (FUN_6805AD40)
//   stage_getDateState (FUN_6805AD50)
//   stage_getStringAllocState (FUN_6805AD60)

// ============================================================
// Function: stage_dispatchAllocType (FUN_6805A710)
// Address: 6805a710
// Size: 133 bytes
// Params: undefined4 param_1, int * param_2, uint * param_3
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_dispatchAllocType(undefined4 param_1,int *param_2,uint *param_3)

{
  int in_EAX;
  int iVar1;
  
  switch(param_1) {
  case 0:
    iVar1 = stage_readIndexedProperty(param_3);
    return iVar1;
  default:
    return 1;
  case 2:
    iVar1 = stage_readRawValue((int)param_2);
    return iVar1;
  case 3:
    iVar1 = stage_storeSymbolValue();
    return iVar1;
  case 4:
    iVar1 = stage_storeNumberValue();
    return iVar1;
  case 5:
    iVar1 = stage_readFloatValue(in_EAX);
    return iVar1;
  case 6:
    iVar1 = stage_storeStringValue(param_2);
    return iVar1;
  case 8:
    iVar1 = score_createDateFromData(param_2,8,in_EAX,param_3);
    return iVar1;
  }
}



// ============================================================
// Function: stage_allocString (FUN_6805a7c0)
// Address: 6805a7c0
// Size: 528 bytes
// Params: int * param_1, uint * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint stage_allocString(int *param_1,uint *param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = *param_1;
  while( true ) {
    *param_2 = 0;
    param_2[1] = 0;
    uVar3 = Ordinal_1413(param_1[1]);
    uVar4 = (uint)((uVar3 & 0xffff) == 0);
    if (uVar4 != 0) {
      return uVar4;
    }
    if ((uVar3 & 0x8000) != 0) {
      uVar3 = stage_dispatchPropertyRead(param_1,param_2);
      return uVar3;
    }
    if ((uVar3 & 0x4000) != 0) {
      Ordinal_1414(param_1[1]);
      uVar3 = stage_dispatchPropertyRead(param_1,param_2);
      return uVar3;
    }
    if ((uVar3 & 0x2000) != 0) {
      uVar3 = stage_dispatchAllocType(uVar3 & 0x3f,param_1,param_2);
      return uVar3;
    }
    if ((uVar3 & 0x1000) != 0) {
      uVar4 = uVar3 & 0xfff;
      *param_2 = 4;
      if ((uVar3 & 0x800) != 0) {
        uVar4 = uVar4 | 0xfffff000;
      }
      param_2[1] = uVar4;
      return 0;
    }
    if ((uVar3 & 0x800) != 0) break;
    if ((uVar3 & 0xff00) == 0x700) {
      Ordinal_1414(param_1[1]);
      uVar3 = stage_dispatchAllocType(uVar3 & 0xff,param_1,param_2);
      return uVar3;
    }
    switch(uVar3 & 0xffff) {
    case 0x100:
      uVar3 = stage_appendAllocVar();
      if (uVar3 != 0) {
        return uVar3;
      }
      break;
    case 0x101:
    case 0x103:
      return 0;
    case 0x102:
      *param_2 = 2;
      return 0;
    case 0x104:
      props_storeNumber(iVar1,0.0,param_2);
      return 0;
    case 0x105:
      props_storeNumber(iVar1,1.0,param_2);
      return 0;
    default:
      goto switchD_6805a866_caseD_101;
    }
  }
  iVar2 = *(int *)param_1[6];
  uVar3 = uVar3 & 0x7ff;
  if ((int)uVar3 < *(int *)(iVar2 + 0x10)) {
    *param_2 = *(uint *)(iVar2 + 0x20 + uVar3 * 8);
    param_2[1] = *(uint *)(iVar2 + 0x24 + uVar3 * 8);
    props_retainValue(iVar1,param_2);
    return 0;
  }
switchD_6805a866_caseD_101:
  return 1;
}



// ============================================================
// Function: stage_removePropertyRef (FUN_6805AA00)
// Address: 6805aa00
// Size: 82 bytes
// Params: uint param_1, uint param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_removePropertyRef(uint param_1,uint param_2,int *param_3)
{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  
  uVar3 = param_1;
  piVar1 = *(int **)(**(int **)(param_1 + 8) + 0x4e8);
  if (piVar1 != (int *)0x0) {
    puVar4 = score_lookupProperty(piVar1,param_2,0,&param_1);
    if (puVar4 != (uint *)0x0) {
      piVar1 = (int *)puVar4[1];
      uVar2 = *puVar4;
      if (piVar1 == param_3) {
        *puVar4 = 0;
        puVar4[1] = 0;
        if (uVar2 == 3) {
          props_releaseObject(uVar3,piVar1);
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: stage_checkCallbackOwner (FUN_6805AA60)
// Address: 6805aa60
// Size: 65 bytes
// Params: int param_1, undefined4 * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool stage_checkCallbackOwner(int param_1,undefined4 *param_2)

{
  *(undefined4 *)(**(int **)(param_1 + 8) + 0x508) = 0;
  (**(code **)*param_2)(param_1,0,0,0xff42,param_2);
  return *(undefined4 **)(**(int **)(param_1 + 8) + 0x508) == param_2;
}



// ============================================================
// Function: stage_freeAllocSlot (FUN_6805AAB0)
// Address: 6805aab0
// Size: 106 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_freeAllocSlot(uint param_1,int *param_2,int param_3)
{
  int iVar1;
  int *piVar2;
  
  if ((-1 < param_3) && (param_3 < *(int *)(*param_2 + 0x18))) {
    piVar2 = *(int **)(*param_2 + (param_3 + 3) * 0x10);
    if (piVar2 != (int *)0x0) {
      stage_removePropertyRef(param_1,*(uint *)(*piVar2 + 0x10),piVar2);
      props_freeTable(param_1,*(int **)(*piVar2 + 0xc));
      score_freePropertyHandle(*(undefined4 *)(*piVar2 + 8));
      cast_freeHandle(piVar2);
    }
    iVar1 = *param_2 + 0x24 + param_3 * 0x10;
    *(undefined4 *)(iVar1 + 8) = 0;
    *(undefined4 *)(iVar1 + 0xc) = 0;
  }
  return 0;
}



// ============================================================
// Function: stage_freeAllAllocSlots (FUN_6805AB20)
// Address: 6805ab20
// Size: 80 bytes
// Params: uint param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_freeAllAllocSlots(uint param_1,int *param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *(int *)(*param_2 + 0x14);
  iVar2 = 0;
  if (0 < iVar1) {
    iVar3 = 0;
    do {
      if ((*(int *)(iVar3 + 0x24 + *param_2) != -1) && (*(int *)(iVar3 + *param_2 + 0x2c) == 6)) {
        stage_freeAllocSlot(param_1,param_2,iVar2);
      }
      iVar2 = iVar2 + 1;
      iVar3 = iVar3 + 0x10;
    } while (iVar2 < iVar1);
  }
  return 0;
}



// ============================================================
// Function: stage_resolveString (FUN_6805ab80)
// Address: 6805ab80
// Size: 72 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_resolveString(int param_1,int param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(param_2 + 9,0);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  if (param_1 != 0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  }
  puVar1 = (undefined4 *)*piVar2;
  *puVar1 = &PTR_LAB_6818e018;
  puVar1[1] = 1;
  param_3[1] = piVar2;
  *param_3 = 0x43;
  return 1;
}



// ============================================================
// Function: stage_initStringLabel (FUN_6805ABD0)
// Address: 6805abd0
// Size: 33 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_initStringLabel(int param_1,undefined4 *param_2)
{
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  *param_2 = &PTR_LAB_6818e018;
  param_2[1] = 1;
  return 0;
}



// ============================================================
// Function: stage_formatAllocError (FUN_6805AC10)
// Address: 6805ac10
// Size: 59 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_formatAllocError(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x3f);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: stage_allocNumberHandle (FUN_6805AC50)
// Address: 6805ac50
// Size: 80 bytes
// Params: int param_1, undefined8 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_allocNumberHandle(int param_1,undefined8 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)Ordinal_1111(0x10,8);
  if (piVar2 == (int *)0x0) {
    *param_3 = 2;
    return 0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  puVar1 = (undefined4 *)*piVar2;
  *(undefined8 *)(puVar1 + 2) = param_2;
  *puVar1 = &PTR_LAB_6818e068;
  puVar1[1] = 1;
  param_3[1] = piVar2;
  *param_3 = 0x23;
  return 1;
}



// ============================================================
// Function: stage_convertToShort (FUN_6805ACA0)
// Address: 6805aca0
// Size: 30 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined2 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_convertToShort(undefined4 param_1,undefined4 param_2,undefined2 *param_3)
{
  Ordinal_1252(param_1,&param_1);
  *param_3 = (undefined2)param_1;
  return 0;
}



// ============================================================
// Function: stage_initDateGlobals (FUN_6805ACC0)
// Address: 6805acc0
// Size: 65 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int stage_initDateGlobals(void)
{
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  Ordinal_1245(&local_14);
  DAT_6818e0b4 = local_10;
  _DAT_681962c4 = local_c;
  DAT_681962c8 = local_14;
  return 0;
}



// ============================================================
// Function: stage_endDateScope (FUN_6805AD10)
// Address: 6805ad10
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_endDateScope(void)
{
  Ordinal_1246();
  return 0;
}



// ============================================================
// Function: stage_readAllocValue (FUN_6805AD20)
// Address: 6805ad20
// Size: 28 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_readAllocValue(undefined4 param_1,undefined4 *param_2)
{
  Ordinal_1252(param_1,&param_1);
  *param_2 = param_1;
  return 0;
}



// ============================================================
// Function: stage_endParseScope (FUN_6805AD40)
// Address: 6805ad40
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_endParseScope(void)
{
  Ordinal_1253();
  return 0;
}



// ============================================================
// Function: stage_getDateState (FUN_6805AD50)
// Address: 6805ad50
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getDateState(void)
{
  Ordinal_1248();
  return 0;
}



// ============================================================
// Function: stage_getStringAllocState (FUN_6805ad60)
// Address: 6805ad60
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_getStringAllocState(void)
{
  Ordinal_1250();
  return 0;
}



