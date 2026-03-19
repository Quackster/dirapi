// Module: score
// Topic: Media/picture/sound object operations
// Address range: 0x68047e00 - 0x68048270
// Functions (13):
//   score_sendMediaMessage
//   score_transferMediaData
//   score_allocMediaObject
//   score_setMediaProperty
//   score_getMediaProperty
//   score_getMediaValue
//   score_freeMediaObject
//   score_formatMediaString
//   score_handleMediaAccess
//   score_loadMediaData
//   score_getMediaRef
//   score_isMediaValid
//   score_parseMediaColor

// ============================================================
// Function: score_sendMediaMessage (FUN_68047e00)
// Address: 68047e00
// Size: 150 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_sendMediaMessage(int param_1,int *param_2,int param_3,undefined4 param_4,undefined4 *param_5)
{
  int iVar1;
  code *pcVar2;
  undefined4 **ppuVar3;
  undefined4 *local_30;
  undefined4 *local_2c;
  undefined4 local_28;
  int *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_8;
  
  local_20 = param_4;
  if (param_3 == 0) {
    local_30 = *(undefined4 **)(*param_2 + 8);
    ppuVar3 = &local_30;
    local_2c = param_5;
    local_28 = 3;
    pcVar2 = score_setCastProperty;
  }
  else {
    local_2c = *(undefined4 **)(*param_2 + 8);
    param_2 = (int *)param_5[1];
    local_28 = *param_5;
    ppuVar3 = &local_2c;
    pcVar2 = score_invokeXtraCallback;
  }
  local_1c = 0;
  local_24 = param_2;
  iVar1 = sprites_sendMessage(param_1,pcVar2,ppuVar3);
  if (iVar1 != 0) {
    props_mapErrorCode(param_1,iVar1,param_4);
  }
  return 0;
}


// ============================================================
// Function: score_transferMediaData (FUN_68047ea0)
// Address: 68047ea0
// Size: 360 bytes
// Params: int param_1, int * param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

bool score_transferMediaData(int param_1,int *param_2,int param_3)

{
  int iVar1;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined *local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  int *local_10;
  undefined4 local_c;
  int *local_8;
  
  local_34 = *(undefined4 *)(*param_2 + 8);
  if (param_2 == *(int **)(param_1 + 0x20)) {
    _DAT_68197764 = (undefined4 *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (undefined4 *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_8 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    local_14 = *(undefined4 *)(param_1 + 0x1c);
    local_10 = *(int **)(param_1 + 0x20);
  }
  else {
    _DAT_68197764 = (undefined4 *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
    local_10 = DAT_6819776c;
    local_14 = DAT_68197768;
    if (_DAT_68197764 != (undefined4 *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_10 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_14 = *(int *)(size_t)_DAT_68197764;
    }
    local_8 = *(int **)(param_1 + 0x20);
    local_c = *(undefined4 *)(param_1 + 0x1c);
  }
  local_28 = (&PTR_FUN_6818d6d4)[param_3 * 2];
  local_18 = &local_14;
  local_30 = 0;
  local_2c = 0;
  local_1c = 2;
  local_24 = 2;
  local_20 = 0;
  iVar1 = sprites_sendMessage(param_1,score_dispatchCastAction,&local_34);
  if (iVar1 != 0) {
    if ((iVar1 != -0x7ffbf821) && (iVar1 != -0x7ffbf830)) {
      props_mapErrorCode(param_1,iVar1,local_28);
    }
    return iVar1 == 0;
  }
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -0x10;
  iVar1 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x1c) = local_24;
  *(undefined4 *)(param_1 + 0x20) = local_20;
  props_releaseValue(param_1,(byte)local_14,local_10);
  props_releaseValue(param_1,(byte)local_c,local_8);
  return true;
}


// ============================================================
// Function: score_allocMediaObject (FUN_68048010)
// Address: 68048010
// Size: 54 bytes
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * score_allocMediaObject(void)

{
  undefined4 *puVar1;
  int *piVar2;
  int *unaff_EBX;
  int unaff_ESI;
  
  piVar2 = (int *)cast_allocHandle(0xc,1);
  if (piVar2 == (int *)0x0) {
    (**(code **)(*unaff_EBX + 8))();
    return (int *)0x0;
  }
  *(int *)(unaff_ESI + 0xfc) = *(int *)(unaff_ESI + 0xfc) + 1;
  *(int *)(*piVar2 + 4) = *(int *)(*piVar2 + 4) + 1;
  puVar1 = (undefined4 *)*piVar2;
  *puVar1 = &PTR_FUN_6818d778;
  puVar1[1] = 1;
  puVar1[2] = unaff_EBX;
  return piVar2;
}


// ============================================================
// Function: score_setMediaProperty (FUN_68048050)
// Address: 68048050
// Size: 38 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_setMediaProperty(undefined4 param_1,undefined4 param_2,undefined4 *param_3)
{
  int *piVar1;
  
  piVar1 = score_allocMediaObject();
  param_3[1] = piVar1;
  if (piVar1 != (int *)0x0) {
    *param_3 = 3;
  }
  return 0;
}


// ============================================================
// Function: score_getMediaProperty (FUN_68048080)
// Address: 68048080
// Size: 47 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getMediaProperty(undefined4 param_1,int *param_2,int *param_3)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_FUN_6818d778)) {
    *param_3 = (*(int **)param_2[1])[2];
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_getMediaValue (FUN_680480b0)
// Address: 680480b0
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getMediaValue(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_FUN_6818d778)) {
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_freeMediaObject (FUN_680480e0)
// Address: 680480e0
// Size: 25 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_freeMediaObject(int param_1,undefined4 param_2)
{
  cast_freeHandle(param_2);
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  return 0;
}


// ============================================================
// Function: score_formatMediaString (FUN_68048100)
// Address: 68048100
// Size: 53 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatMediaString(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  cast_loadPascalString(&DAT_68197780,0x898,0x30);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}


// ============================================================
// Function: score_handleMediaAccess (FUN_68048140)
// Address: 68048140
// Size: 88 bytes
// Params: int param_1, undefined4 * param_2, int param_3, int param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_handleMediaAccess(int param_1,undefined4 *param_2,int param_3,int param_4,undefined4 param_5)

{
  undefined4 uVar1;
  
  if (param_4 != 0x8a) {
    return 0;
  }
  if (param_3 != 0) {
    props_reportError(param_1,0x39);
    return 1;
  }
  uVar1 = Ordinal_1116(param_2,param_5);
  props_storeIntValue(param_1,uVar1,param_2);
  return 1;
}


// ============================================================
// Function: score_loadMediaData (FUN_680481a0)
// Address: 680481a0
// Size: 69 bytes
// Params: int param_1, undefined4 param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint score_loadMediaData(int param_1,undefined4 param_2)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int iVar4;
  undefined3 extraout_var_00;
  uint uVar3;
  
  iVar2 = Ordinal_1116(param_2);
  bVar1 = stage_writeFactoryEntry(param_1,param_2,8,iVar2 - 8U);
  uVar3 = CONCAT31(extraout_var,bVar1);
  if (uVar3 == 0) {
    iVar4 = Ordinal_1114(param_2);
    bVar1 = stage_compareScriptRefByIndex(param_1,iVar4 + 8,iVar2 - 8U);
    uVar3 = CONCAT31(extraout_var_00,bVar1);
    Ordinal_1115(param_2);
  }
  return uVar3;
}


// ============================================================
// Function: score_getMediaRef (FUN_68048200)
// Address: 68048200
// Size: 37 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getMediaRef(int param_1,int *param_2)
{
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  *(undefined ***)*param_2 = &PTR_LAB_6818d7c8;
  *(undefined4 *)(*param_2 + 4) = 1;
  return 0;
}


// ============================================================
// Function: score_isMediaValid (FUN_68048230)
// Address: 68048230
// Size: 52 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool score_isMediaValid(undefined4 param_1,int *param_2,int *param_3)

{
  int iVar1;
  
  iVar1 = props_extractObject(param_1,param_2,param_3);
  if (iVar1 == 0) {
    return false;
  }
  return (undefined **)**(int **)*param_3 == &PTR_LAB_6818d7c8;
}


// ============================================================
// Function: score_parseMediaColor (FUN_68048270)
// Address: 68048270
// Size: 611 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_parseMediaColor(int param_1)
{
  int iVar1;
  char *_Str;
  ulong uVar2;
  int iVar3;
  int *piVar4;
  int local_420;
  int local_41c;
  undefined1 local_418;
  undefined1 local_417;
  undefined1 local_416;
  undefined1 local_415;
  int local_414;
  undefined1 local_410;
  undefined1 local_40c;
  undefined1 local_408;
  char local_407;
  char local_406 [1022];
  uint local_8;
  
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18)
              );
  if (_DAT_68197764 == (int *)0x0) {
    local_41c = DAT_6819776c;
    iVar3 = DAT_68197768;
  }
  else {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_41c = ((int *)(size_t)_DAT_68197764)[1];
    iVar3 = *(int *)(size_t)_DAT_68197764;
  }
  local_415 = 1;
  iVar1 = props_getInt(param_1);
  if ((iVar1 == 1) && ((iVar3 == 0x40 || (iVar3 == 0x43)))) {
    Ordinal_1130(&local_408,0x400);
    _DAT_68197764 =
         (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                *(int *)(param_1 + 0x18));
    local_41c = DAT_6819776c;
    local_420 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_41c = ((int *)(size_t)_DAT_68197764)[1];
      local_420 = *(int *)(size_t)_DAT_68197764;
    }
    props_toPascalString(&local_420,&local_408);
    _Str = &local_407;
    if (local_407 == '#') {
      _Str = local_406;
    }
    uVar2 = strtoul(_Str,(char **)0x0,0x10);
    local_418 = (undefined1)(uVar2 >> 0x10);
    local_410 = (undefined1)(uVar2 >> 8);
    local_416 = (undefined1)uVar2;
  }
  else {
    iVar3 = props_getInt(param_1);
    if (iVar3 != 3) {
      props_setError(param_1,0x17);
      return 0;
    }
    iVar3 = 1;
    piVar4 = &local_414;
    do {
      iVar1 = props_coerceToInt(param_1,(int *)(**(int **)(param_1 + 0x10) + -8 +
                                           (iVar3 - *(int *)(param_1 + 0x20)) * 8 +
                                          *(int *)(param_1 + 0x18)),&local_41c);
      if (iVar1 == 0) {
        _DAT_68197764 =
             (int *)(**(int **)(param_1 + 0x10) + -8 + (iVar3 - *(int *)(param_1 + 0x20)) * 8 +
                    *(int *)(param_1 + 0x18));
        if (_DAT_68197764 == (int *)0x0) {
          props_setErrorAndReturn(param_1,7);
          return 0;
        }
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        props_setErrorAndReturn(param_1,7);
        return 0;
      }
      if (local_41c < 0) {
        iVar1 = 0;
      }
      else {
        iVar1 = local_41c;
        if (0xff < local_41c) {
          iVar1 = 0xff;
        }
      }
      *piVar4 = iVar1;
      iVar3 = iVar3 + 1;
      piVar4 = piVar4 + 1;
    } while (iVar3 < 4);
    local_418 = (undefined1)local_414;
    local_416 = local_40c;
  }
  local_417 = local_410;
  iVar3 = score_createColorObject(param_1,(undefined4 *)&local_418);
  props_normalizeType(param_1,3,iVar3);
  return 0;
}


