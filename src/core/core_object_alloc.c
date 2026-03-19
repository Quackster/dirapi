// Module: core
// Topic: Object allocation, creation, destruction and type checking
// Address range: 0x68010090 - 0x68018F20
// Functions (24):
//   core_getExtPairOrEmpty (0x68010090)
//   core_accessToggleState (0x680100D0)
//   core_accessScriptObjFlags (0x68010160)
//   core_applyInheritance (0x680101E0)
//   core_resetChannelEntry (0x68010200)
//   core_formatPascalError (0x68010270)
//   core_getObjectOffset (0x680102B0)
//   core_getSpriteRefNumber (0x68010430)
//   core_createSpriteRef (0x68010460)
//   core_createDefaultSpriteRef (0x680104A0)
//   core_createTypedRef (0x68010580)
//   core_checkRefValid (0x680105E0)
//   core_getColorRefNumber (0x68010610)
//   core_createColorRef (0x68010650)
//   core_createDefaultColorRef (0x680106A0)
//   core_handleNewColorRefEnabled (0x680106F0)
//   core_handleNewColorRef (0x68010810)
//   core_resolveAndSetScript (0x68010B20)
//   core_handleNewTypedRef (0x680111D0)
//   core_findObjectById (0x68011230)
//   core_getObjectRefById (0x68011310)
//   core_getObjectRefByIdAlt (0x68011330)
//   core_resolveAndCreateSpriteRef (0x68011350)
//   core_handleNewSpriteRef (0x68018F20)

// ============================================================
// Function: core_getExtPairOrEmpty (FUN_68010090)
// Address: 68010090
// Size: 49 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getExtPairOrEmpty(void)
{
  int local_c;
  int iVar1;
  undefined4 *puVar2;
  int unaff_ESI;
  undefined4 *unaff_EDI;

  iVar1 = crt_getScriptObjectValue(unaff_ESI);
  if ((iVar1 != 0) && (*(code **)(iVar1 + 0x1a8) != (code *)0x0)) {
    puVar2 = (undefined4 *)(**(code **)(iVar1 + 0x1a8))();
    if (puVar2 != (undefined4 *)0x0) {
      props_getExtPair(unaff_ESI,puVar2,unaff_EDI);
      return 0;
    }
  }
  props_loadStringValue(unaff_ESI,"",unaff_EDI);
  return 0;
}



// ============================================================
// Function: core_accessToggleState (FUN_680100d0)
// Address: 680100d0
// Size: 144 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_accessToggleState(int *param_1)
{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int extraout_EDX;
  int unaff_EBX;
  int local_8;

  iVar2 = crt_getScriptObjectType(unaff_EBX);
  if (((iVar2 == 0) || (*(int *)(iVar2 + 0xc) == 0)) ||
     (pcVar1 = *(code **)(*(int *)(iVar2 + 0xc) + 0x1bc), pcVar1 == (code *)0x0)) {
    if (extraout_EDX == 0) {
      props_storeIntValue(unaff_EBX,0,param_1);
    }
  }
  else {
    if (extraout_EDX == 0) {
      iVar2 = (*pcVar1)(*(undefined4 *)(iVar2 + 0x24),3);
      props_storeIntValue(unaff_EBX,(uint)(iVar2 != 0),param_1);
      return 0;
    }
    iVar3 = props_requireInt(unaff_EBX,param_1,&local_8);
    if (iVar3 != 0) {
      (*pcVar1)(*(undefined4 *)(iVar2 + 0x24),(-(uint)(local_8 != 0) & 0xfffffffe) + 2);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: core_accessScriptObjFlags (FUN_68010160)
// Address: 68010160
// Size: 116 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_accessScriptObjFlags(int param_1,int *param_2,int param_3,int param_4,undefined4 *param_5)

{
  undefined4 uVar1;

  if ((param_3 == 0) && (*(int *)(param_1 + 0xe0) != 0)) {
    if (param_4 == 300) {
      *param_5 = 4;
      param_5[1] = -(uint)((*(uint *)(*param_2 + 0x54) & 0x8000) != 0) & 100;
      return 1;
    }
    if (param_4 == 0x142) {
      *param_5 = 4;
      uVar1 = Ordinal_1116(param_2);
      param_5[1] = uVar1;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: core_applyInheritance (FUN_680101e0)
// Address: 680101e0
// Size: 31 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_applyInheritance(int param_1,int *param_2)
{
  if ((*(uint *)(*param_2 + 0x54) & 0x4000) != 0) {
    core_inheritMethods(param_1,param_2);
  }
  return 0;
}



// ============================================================
// Function: core_resetChannelEntry (FUN_68010200)
// Address: 68010200
// Size: 97 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall core_resetChannelEntry(int param_1)
{
  int in_EAX;
  int iVar1;
  int local_8;

  iVar1 = *(int *)(*(int *)(in_EAX + 8) + 4);
  local_8 = param_1;
  crt_dispatchPlatformOp(in_EAX,param_1,0x12);
  iVar1 = Ordinal_165(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),&local_8);
  if ((((param_1 <= local_8) && (-1 < param_1)) &&
      (iVar1 = iVar1 + param_1 * 0x34, *(int *)(iVar1 + 0xc) == -1)) &&
     ((*(int *)(iVar1 + 4) == 1 && (*(int *)(iVar1 + 8) == 0x7fff)))) {
    *(undefined4 *)(iVar1 + 4) = 0;
    *(undefined4 *)(iVar1 + 8) = 0;
  }
  return 0;
}



// ============================================================
// Function: core_formatPascalError (FUN_68010270)
// Address: 68010270
// Size: 58 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_formatPascalError(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x47);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: core_getObjectOffset (FUN_680102b0)
// Address: 680102b0
// Size: 25 bytes
// Params: undefined4 param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getObjectOffset(undefined4 param_1,int *param_2,undefined4 *param_3)

{
  *param_3 = *(undefined4 *)(*param_2 + 8);
  return 1;
}



// ============================================================
// Function: core_getSpriteRefNumber (FUN_68010430)
// Address: 68010430
// Size: 47 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getSpriteRefNumber(undefined4 param_1,int *param_2,int *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_68189650)) {
    *param_3 = (*(int **)param_2[1])[2];
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_createSpriteRef (FUN_68010460)
// Address: 68010460
// Size: 64 bytes
// Params: int param_1, short param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_createSpriteRef(int param_1,short param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  int *piVar2;

  piVar2 = (int *)Ordinal_1111(0xc,8);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar2;
    puVar1[1] = 1;
    *puVar1 = &PTR_LAB_68189650;
    puVar1[2] = (int)param_2;
    *param_3 = 3;
    param_3[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: core_createDefaultSpriteRef (FUN_680104a0)
// Address: 680104a0
// Size: 64 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_createDefaultSpriteRef(int param_1,undefined4 *param_2)
{
  undefined4 *puVar1;
  int *piVar2;

  piVar2 = (int *)Ordinal_1111(0xc,8);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar2;
    *puVar1 = &PTR_LAB_68189650;
    puVar1[1] = 1;
    puVar1[2] = 0xffffffff;
    *param_2 = 3;
    param_2[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: core_createTypedRef (FUN_68010580)
// Address: 68010580
// Size: 84 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_createTypedRef(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;

  iVar2 = props_getInt(param_1);
  if (iVar2 == 0) {
    piVar3 = (int *)Ordinal_1111(0xc,8);
    if (piVar3 != (int *)0x0) {
      *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
      puVar1 = (undefined4 *)*piVar3;
      puVar1[2] = param_2;
      *puVar1 = &PTR_LAB_681896a0;
      puVar1[1] = 1;
      param_3[1] = piVar3;
      *param_3 = 3;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: core_checkRefValid (FUN_680105e0)
// Address: 680105e0
// Size: 35 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool core_checkRefValid(undefined4 param_1,int *param_2,int param_3)

{
  if (param_3 < 0) {
    return 0 < *(int *)(*param_2 + 8);
  }
  return true;
}



// ============================================================
// Function: core_getColorRefNumber (FUN_68010610)
// Address: 68010610
// Size: 49 bytes
// Params: undefined4 param_1, int * param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 core_getColorRefNumber(undefined4 param_1,int *param_2,undefined2 *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_681896f0)) {
    *param_3 = (short)(*(int **)param_2[1])[2];
    return 1;
  }
  return 0;
}



// ============================================================
// Function: core_createColorRef (FUN_68010650)
// Address: 68010650
// Size: 70 bytes
// Params: int param_1, short param_2, undefined4 * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_createColorRef(int param_1,short param_2,undefined4 *param_3,undefined4 param_4)
{
  undefined4 *puVar1;
  int *piVar2;

  piVar2 = (int *)Ordinal_1111(0x10,8);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar2;
    puVar1[1] = 1;
    puVar1[3] = param_4;
    *puVar1 = &PTR_LAB_681896f0;
    puVar1[2] = (int)param_2;
    *param_3 = 3;
    param_3[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: core_createDefaultColorRef (FUN_680106a0)
// Address: 680106a0
// Size: 70 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_createDefaultColorRef(int param_1,undefined4 *param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  int *piVar2;

  piVar2 = (int *)Ordinal_1111(0x10,8);
  if (piVar2 != (int *)0x0) {
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
    puVar1 = (undefined4 *)*piVar2;
    puVar1[1] = 1;
    *puVar1 = &PTR_LAB_681896f0;
    puVar1[2] = 0xffffffff;
    puVar1[3] = param_3;
    *param_2 = 3;
    param_2[1] = piVar2;
  }
  return 0;
}



// ============================================================
// Function: core_handleNewColorRefEnabled (FUN_680106f0)
// Address: 680106f0
// Size: 275 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_handleNewColorRefEnabled(int param_1)
{
  int iVar1;
  int local_414;
  int local_410;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;

  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18)
              );
  local_40c = DAT_6819776c;
  local_410 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_40c = ((int *)(size_t)_DAT_68197764)[1];
    local_410 = *(int *)(size_t)_DAT_68197764;
  }
  if ((local_410 == 0x40) || (local_410 == 0x43)) {
    props_toPascalString(&local_410,local_408);
    local_414 = props_listNoOp();
    if (0 < local_414) goto LAB_6801077c;
    if (*(int *)(param_1 + 0xe0) == 0) {
      local_414 = 1;
      goto LAB_6801077c;
    }
    local_410 = 2;
    local_40c = 0;
  }
  else {
    iVar1 = props_requireInt(param_1,&local_410,&local_414);
    if (iVar1 == 0) goto LAB_68010799;
LAB_6801077c:
    core_createColorRef(param_1,(short)local_414,&local_410,1);
  }
  props_popArgs(param_1,&local_410);
LAB_68010799:
  return 0;
}



// ============================================================
// Function: core_handleNewColorRef (FUN_68010810)
// Address: 68010810
// Size: 275 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_handleNewColorRef(int param_1)
{
  int iVar1;
  int local_414;
  int local_410;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;

  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18)
              );
  local_40c = DAT_6819776c;
  local_410 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_40c = ((int *)(size_t)_DAT_68197764)[1];
    local_410 = *(int *)(size_t)_DAT_68197764;
  }
  if ((local_410 == 0x40) || (local_410 == 0x43)) {
    props_toPascalString(&local_410,local_408);
    local_414 = props_listNoOp();
    if (0 < local_414) goto LAB_6801089c;
    if (*(int *)(param_1 + 0xe0) == 0) {
      local_414 = 1;
      goto LAB_6801089c;
    }
    local_410 = 2;
    local_40c = 0;
  }
  else {
    iVar1 = props_requireInt(param_1,&local_410,&local_414);
    if (iVar1 == 0) goto LAB_680108b9;
LAB_6801089c:
    core_createColorRef(param_1,(short)local_414,&local_410,0);
  }
  props_popArgs(param_1,&local_410);
LAB_680108b9:
  return 0;
}



// ============================================================
// Function: core_resolveAndSetScript (FUN_68010b20)
// Address: 68010b20
// Size: 139 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resolveAndSetScript(int param_1)
{
  int iVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;

  *unaff_ESI = 2;
  unaff_ESI[1] = 0;
  if ((param_1 == 0x40) || (param_1 == 0x43)) {
    props_toPascalString(&param_1,local_408);
    local_40c = sprites_processEvent(unaff_EDI,(int)local_408,1);
  }
  else {
    iVar1 = props_requireInt(unaff_EDI,&param_1,&local_40c);
    if (iVar1 == 0) goto LAB_68010b74;
  }
  if (0 < local_40c) {
    crt_setScriptPropertyEx(unaff_EDI,(short)local_40c,unaff_ESI);
  }
LAB_68010b74:
  return 0;
}



// ============================================================
// Function: core_handleNewTypedRef (FUN_680111d0)
// Address: 680111d0
// Size: 81 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_handleNewTypedRef(int param_1)
{
  int iVar1;
  uint local_c [2];

  local_c[0] = 2;
  local_c[1] = 0;
  iVar1 = core_createTypedRef(param_1,0x7c,local_c);
  if ((iVar1 == 0) &&
     (iVar1 = crt_resolveBehaviorRef(param_1,(uint)(*(int *)(param_1 + 0xe0) == 0),local_c), iVar1 == 0)) {
    return 0;
  }
  props_popArgs(param_1,local_c);
  return 0;
}



// ============================================================
// Function: core_findObjectById (FUN_68011230)
// Address: 68011230
// Size: 221 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_findObjectById(int param_1,uint *param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  int unaff_ESI;
  int iVar4;
  uint local_c;
  int *local_8;

  *param_2 = 2;
  param_2[1] = 0;
  piVar1 = *(int **)(**(int **)(unaff_ESI + 8) + 0x510);
  if (piVar1 != (int *)0x0) {
    iVar2 = props_getListLength(unaff_ESI,piVar1);
    iVar4 = 0;
    if (0 < iVar2) {
      do {
        props_getListEntry(unaff_ESI,*(int **)(**(int **)(unaff_ESI + 8) + 0x510),iVar4,&local_c);
        iVar3 = crt_isBehaviorObject();
        if ((iVar3 != 0) &&
           (iVar3 = events_setWindowFlags(unaff_ESI,*(undefined4 **)(*local_8 + 8)), iVar3 == param_1)) {
          *param_2 = local_c;
          param_2[1] = (uint)local_8;
          return 0;
        }
        props_releaseValue(unaff_ESI,(byte)local_c,local_8);
        iVar4 = iVar4 + 1;
      } while (iVar4 < iVar2);
    }
  }
  crt_getScriptInstance(unaff_ESI,&local_c);
  iVar2 = events_setWindowFlags(unaff_ESI,*(undefined4 **)(*local_8 + 8));
  if (iVar2 != param_1) {
    props_releaseValue(unaff_ESI,(byte)local_c,local_8);
    return 0;
  }
  *param_2 = local_c;
  param_2[1] = (uint)local_8;
  return 0;
}



// ============================================================
// Function: core_getObjectRefById (FUN_68011310)
// Address: 68011310
// Size: 28 bytes
// Params: int param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_getObjectRefById(int param_1,uint *param_2)
{
  int iVar1;

  iVar1 = events_getStageWindowRef(param_1);
  core_findObjectById(iVar1,param_2);
  return 0;
}



// ============================================================
// Function: core_getObjectRefByIdAlt (FUN_68011330)
// Address: 68011330
// Size: 18 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall core_getObjectRefByIdAlt(int param_1)
{
  uint *in_EAX;
  int iVar1;

  iVar1 = events_getParentStageRef(param_1);
  core_findObjectById(iVar1,in_EAX);
  return 0;
}



// ============================================================
// Function: core_resolveAndCreateSpriteRef (FUN_68011350)
// Address: 68011350
// Size: 139 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int core_resolveAndCreateSpriteRef(int param_1)
{
  int iVar1;
  undefined4 *unaff_ESI;
  int unaff_EDI;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;

  *unaff_ESI = 2;
  unaff_ESI[1] = 0;
  if ((param_1 == 0x40) || (param_1 == 0x43)) {
    props_toPascalString(&param_1,local_408);
    local_40c = sprites_processEvent(unaff_EDI,(int)local_408,0);
  }
  else {
    iVar1 = props_requireInt(unaff_EDI,&param_1,&local_40c);
    if (iVar1 == 0) goto LAB_680113a4;
  }
  if (0 < local_40c) {
    core_createSpriteRef(unaff_EDI,(short)local_40c,unaff_ESI);
  }
LAB_680113a4:
  return 0;
}



// ============================================================
// Function: core_handleNewSpriteRef (FUN_68018f20)
// Address: 68018f20
// Size: 250 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int core_handleNewSpriteRef(int param_1)
{
  int local_2c;
  int iVar1;
  int local_414;
  int local_410;
  int local_40c;
  undefined1 local_408 [1024];
  uint local_8;

  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18)
              );
  local_40c = DAT_6819776c;
  local_410 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_40c = ((int *)(size_t)_DAT_68197764)[1];
    local_410 = *(int *)(size_t)_DAT_68197764;
  }
  if ((local_410 == 0x40) || (local_410 == 0x43)) {
    props_toPascalString(&local_410,local_408);
    local_414 = sprites_processEvent(param_1,(int)local_408,0);
    if (0 < local_414) goto LAB_68018fac;
    local_410 = 2;
    local_40c = 0;
  }
  else {
    iVar1 = props_requireInt(param_1,&local_410,&local_414);
    if (iVar1 == 0) goto LAB_68018fc7;
LAB_68018fac:
    core_createSpriteRef(param_1,(short)local_414,&local_410);
  }
  props_popArgs(param_1,&local_410);
LAB_68018fc7:
  return 0;
}


