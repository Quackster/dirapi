// Module: score
// Topic: Script object lifecycle and dispatch
// Address range: 0x6804b900 - 0x6804c030
// Functions (16):
//   score_routeScriptCommand (FUN_6804b900)
//   score_dispatchPropertyCommand (FUN_6804b9f0)
//   score_dispatchXtraCommand (FUN_6804ba30)
//   score_destroyScriptObject (FUN_6804ba50)
//   score_formatScriptName (FUN_6804bb20)
//   score_accessScriptProperty (FUN_6804bbb0)
//   score_invalidateScriptObject (FUN_6804bbc0)
//   score_reattachScriptObject (FUN_6804bbf0)
//   score_serializeScriptObject (FUN_6804bc20)
//   score_allocScriptObject (FUN_6804bc40)
//   score_createScriptInstance (FUN_6804bce0)
//   score_handleScriptDispatch (FUN_6804bd90)
//   score_releaseScriptResources (FUN_6804bee0)
//   score_removeScriptObject (FUN_6804bf40)
//   score_formatScriptValue (FUN_6804bfa0)
//   score_getScriptProperty (FUN_6804c030)

// ============================================================
// Function: score_routeScriptCommand (FUN_6804b900)
// Address: 6804b900
// Size: 128 bytes
// Params: int param_1, int * param_2, uint param_3
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall score_routeScriptCommand(int param_1,int *param_2,uint param_3)

{
  uint uVar1;
  int in_EAX;
  int iVar2;
  undefined4 *puVar3;
  int unaff_EDI;
  
  uVar1 = param_3;
  if (-1 < param_1) {
    iVar2 = score_dispatchScriptCall(param_1,param_2,in_EAX);
    return iVar2;
  }
  if (unaff_EDI - 0x81U < 99) {
    switch(unaff_EDI) {
    case 0x81:
    case 0xd4:
    case 0xdb:
    case 0xdd:
      param_3 = 0;
      puVar3 = (undefined4 *)score_initFrameSprite((uint)*(byte *)(unaff_EDI + 0x6804b90b),uVar1);
      if (puVar3 != (undefined4 *)0x0) {
        (**(code **)*puVar3)(puVar3,&DAT_681762e8,&param_3);
        if (param_3 != 0) {
          iVar2 = score_dispatchXtraCall(uVar1,param_3,unaff_EDI);
          return iVar2;
        }
      }
      break;
    case 0xe3:
      score_resolveType(param_3);
      return 1;
    }
  }
  return 0;
}


// ============================================================
// Function: score_dispatchPropertyCommand (FUN_6804b9f0)
// Address: 6804b9f0
// Size: 50 bytes
// Params: void * this, uint param_1, int * param_2, uint param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall score_dispatchPropertyCommand(void *this,uint param_1,int *param_2,uint param_3)
{
  int *piVar1;
  uint uVar2;

  piVar1 = *(int **)(*param_2 + 0x10);
  uVar2 = score_lookupPropertyValue(this,param_1,param_3);
  score_routeScriptCommand(uVar2,piVar1,param_1);
  return 0;
}


// ============================================================
// Function: score_dispatchXtraCommand (FUN_6804ba30)
// Address: 6804ba30
// Size: 32 bytes
// Params: uint param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispatchXtraCommand(uint param_1,int *param_2)
{
  score_routeScriptCommand(-1,*(int **)(*param_2 + 0x10),param_1);
  return 0;
}


// ============================================================
// Function: score_destroyScriptObject (FUN_6804ba50)
// Address: 6804ba50
// Size: 194 bytes
// Params: uint param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_destroyScriptObject(uint param_1,int *param_2)
{
  int *piVar1;
  int iVar2;
  void *this;
  uint local_c;
  int *local_8;
  
  *(undefined4 *)(*param_2 + 4) = 2;
  if (*(int *)(**(int **)(*param_2 + 0x10) + 0x24) != 0) {
    local_c = 3;
    local_8 = param_2;
    props_retainValue(param_1,&local_c);
    props_pushValue(param_1);
    *(uint *)(param_1 + 0x1c) = local_c;
    *(int **)(param_1 + 0x20) = local_8;
    props_pushValue(param_1);
    *(undefined4 *)(param_1 + 0x20) = 1;
    iVar2 = score_dispatchPropertyCommand(this,param_1,param_2,0x10c);
    if (iVar2 == 0) {
      props_popValue(param_1);
      props_popValue(param_1);
    }
    score_attachSprite(param_1);
  }
  piVar1 = (int *)(**(int **)(*param_2 + 0x10) + 0x14);
  *piVar1 = *piVar1 + -1;
  props_releaseObject(param_1,*(int **)(*param_2 + 0x10));
  *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
  *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + -1;
  return 0;
}


// ============================================================
// Function: score_formatScriptName (FUN_6804bb20)
// Address: 6804bb20
// Size: 144 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatScriptName(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  int local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  uint local_8;
  
  local_410 = *(int *)(**(int **)(*param_2 + 0x10) + 0x18);
  local_40c = *(undefined4 *)(**(int **)(*param_2 + 0x10) + 0x1c);
  props_toPascalString(&local_410,local_408);
  cast_loadPascalString(&DAT_68197780,0x898,0x2d);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}


// ============================================================
// Function: score_accessScriptProperty (FUN_6804bbb0)
// Address: 6804bbb0
// Size: 9 bytes
// Params: int param_1, undefined4 * param_2, int param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_accessScriptProperty(int param_1,undefined4 *param_2,int param_3,undefined4 param_4,uint *param_5)
{
  props_accessProperty(param_1,param_2,param_3,param_4,param_5);
  return 0;
}


// ============================================================
// Function: score_invalidateScriptObject (FUN_6804bbc0)
// Address: 6804bbc0
// Size: 42 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_invalidateScriptObject(undefined4 param_1,int *param_2)
{
  undefined4 *puVar1;
  
  *(uint *)(*param_2 + 4) = *(uint *)(*param_2 + 4) | 0x80000000;
  puVar1 = *(undefined4 **)(*param_2 + 0x10);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)(*(int *)*puVar1 + 0x34))(param_1,puVar1);
  }
  return 0;
}


// ============================================================
// Function: score_reattachScriptObject (FUN_6804bbf0)
// Address: 6804bbf0
// Size: 48 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_reattachScriptObject(int param_1,int *param_2)
{
  undefined4 *puVar1;
  
  puVar1 = *(undefined4 **)(*param_2 + 0x10);
  if (puVar1 != (undefined4 *)0x0) {
    (**(code **)(*(int *)*puVar1 + 0x3c))(param_1,puVar1);
  }
  score_attachSprite(param_1);
  return 0;
}


// ============================================================
// Function: score_serializeScriptObject (FUN_6804bc20)
// Address: 6804bc20
// Size: 30 bytes
// Params: undefined4 * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_serializeScriptObject(undefined4 *param_1,int *param_2)
{
  stage_serializeData(param_1,param_2,*(int *)(*param_2 + 0x10),0,0);
  return 0;
}


// ============================================================
// Function: score_allocScriptObject (FUN_6804bc40)
// Address: 6804bc40
// Size: 147 bytes
// Params: int param_1
// Return: int *
// Calling convention: __fastcall
// ============================================================

int * __fastcall score_allocScriptObject(int param_1)

{
  undefined4 *puVar1;
  int *in_EAX;
  int iVar2;
  int *piVar3;
  
  iVar2 = score_getFrameSprite(param_1);
  if (iVar2 != 0) {
    piVar3 = (int *)cast_allocHandle(0x18,0);
    if (piVar3 != (int *)0x0) {
      *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + 1;
      puVar1 = (undefined4 *)*piVar3;
      puVar1[4] = in_EAX;
      puVar1[5] = iVar2;
      *puVar1 = &PTR_LAB_6818d818;
      puVar1[1] = 1;
      *(int *)(*in_EAX + 4) = *(int *)(*in_EAX + 4) + 1;
      *(int *)(*in_EAX + 0x14) = *(int *)(*in_EAX + 0x14) + 1;
      iVar2 = **(int **)(param_1 + 8);
      *(undefined4 *)(*piVar3 + 8) = *(undefined4 *)(**(int **)(iVar2 + 0x564) + 8);
      *(undefined4 *)(*piVar3 + 0xc) = *(undefined4 *)(iVar2 + 0x564);
      *(int **)(**(int **)(**(int **)(iVar2 + 0x564) + 8) + 0xc) = piVar3;
      *(int **)(**(int **)(iVar2 + 0x564) + 8) = piVar3;
      return piVar3;
    }
    score_attachSprite(param_1);
  }
  return (int *)0x0;
}


// ============================================================
// Function: score_createScriptInstance (FUN_6804bce0)
// Address: 6804bce0
// Size: 163 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_createScriptInstance(void)
{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  void *this;
  uint unaff_ESI;
  undefined4 local_c;
  int *local_8;
  
  piVar1 = score_allocScriptObject(unaff_ESI);
  if (piVar1 == (int *)0x0) {
    local_c = 0;
    local_8 = (int *)0x0;
    props_popArgs(unaff_ESI,&local_c);
    return 0;
  }
  puVar2 = (undefined4 *)
           (**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
           *(int *)(unaff_ESI + 0x18));
  local_c = *puVar2;
  local_8 = (int *)puVar2[1];
  *puVar2 = 3;
  puVar2[1] = piVar1;
  props_releaseValue(unaff_ESI,(byte)local_c,local_8);
  *(int *)(*piVar1 + 4) = *(int *)(*piVar1 + 4) + 1;
  iVar3 = score_dispatchPropertyCommand(this,unaff_ESI,piVar1,0x82);
  if (iVar3 == 0) {
    local_c = 3;
    local_8 = piVar1;
    props_popArgs(unaff_ESI,&local_c);
  }
  else if (*(int *)(unaff_ESI + 0x1c) == 2) {
    *(int **)(unaff_ESI + 0x20) = piVar1;
    *(undefined4 *)(unaff_ESI + 0x1c) = 3;
    return 0;
  }
  return 0;
}


// ============================================================
// Function: score_handleScriptDispatch (FUN_6804bd90)
// Address: 6804bd90
// Size: 175 bytes
// Params: void * this, uint param_1, int * param_2, uint param_3
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall score_handleScriptDispatch(void *this,uint param_1,int *param_2,uint param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  undefined4 local_c [2];
  
  switch(param_3) {
  case 0x82:
    score_createScriptInstance();
    return 1;
  default:
    uVar2 = score_lookupPropertyValue(this,param_1,param_3);
    iVar3 = score_routeScriptCommand(uVar2,param_2,param_1);
    return iVar3;
  case 0xe3:
    score_resolveType(param_1);
    return 1;
  case 0x101:
  case 0x102:
    puVar1 = (undefined4 *)Ordinal_1120(*(undefined4 *)(*param_2 + 0x28),0);
    props_getValuePair(param_1,puVar1,local_c);
    props_popArgs(param_1,local_c);
    return 1;
  }
}


// ============================================================
// Function: score_releaseScriptResources (FUN_6804bee0)
// Address: 6804bee0
// Size: 88 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_releaseScriptResources(int param_1)
{
  int *piVar1;
  int *unaff_ESI;
  
  score_freePropertyHandle(*(undefined4 *)(*unaff_ESI + 0x24));
  *(undefined4 *)(*unaff_ESI + 0x24) = 0;
  cast_freeHandle(*(undefined4 *)(*unaff_ESI + 0x28));
  *(undefined4 *)(*unaff_ESI + 0x28) = 0;
  cast_freeHandle(*(undefined4 *)(*unaff_ESI + 0x2c));
  *(undefined4 *)(*unaff_ESI + 0x2c) = 0;
  piVar1 = *(int **)(*unaff_ESI + 0x30);
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
    *(undefined4 *)(*unaff_ESI + 0x30) = 0;
  }
  score_attachSprite(param_1);
  return 0;
}


// ============================================================
// Function: score_removeScriptObject (FUN_6804bf40)
// Address: 6804bf40
// Size: 85 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_removeScriptObject(int param_1,int *param_2)
{
  if (*(int *)(*param_2 + 0x24) != 0) {
    score_releaseScriptResources(param_1);
  }
  props_releaseValue(param_1,(byte)*(undefined4 *)(*param_2 + 0x18),*(int **)(*param_2 + 0x1c));
  *(undefined4 *)(**(int **)(*param_2 + 8) + 0xc) = *(undefined4 *)(*param_2 + 0xc);
  *(undefined4 *)(**(int **)(*param_2 + 0xc) + 8) = *(undefined4 *)(*param_2 + 8);
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + -1;
  return 0;
}


// ============================================================
// Function: score_formatScriptValue (FUN_6804bfa0)
// Address: 6804bfa0
// Size: 139 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatScriptValue(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  int local_410;
  undefined4 local_40c;
  undefined1 local_408 [1024];
  uint local_8;

  local_410 = *(int *)(*param_2 + 0x18);
  local_40c = *(undefined4 *)(*param_2 + 0x1c);
  props_toPascalString(&local_410,local_408);
  cast_loadPascalString(&DAT_68197780,0x898,0x2e);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}


// ============================================================
// Function: score_getScriptProperty (FUN_6804c030)
// Address: 6804c030
// Size: 62 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getScriptProperty(undefined4 param_1,int *param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  
  if ((param_4 == 0x103) && (param_3 == 0)) {
    iVar1 = *param_2;
    *param_5 = *(uint *)(iVar1 + 0x18);
    param_5[1] = *(uint *)(iVar1 + 0x1c);
    props_retainValue(param_1,param_5);
    return 1;
  }
  return 0;
}


