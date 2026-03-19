// Module: score
// Topic: Date/time object operations and calculations
// Address range: 0x68046e50 - 0x680475b0
// Functions (12):
//   score_getDateProperty
//   score_formatDateString
//   score_dateToInt
//   score_serializeDate
//   score_compareDates
//   score_isDateObject
//   score_setDateProperty
//   score_dispatchDateCallback
//   score_invokeDateHandler
//   score_sendDateMessage
//   score_dispatchDateEvent
//   score_sendDateEvent

// ============================================================
// Function: score_getDateProperty (FUN_68046e50)
// Address: 68046e50
// Size: 485 bytes
// Params: int param_1, int * param_2, int param_3, undefined4 param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_getDateProperty(int param_1,int *param_2,int param_3,undefined4 param_4,int *param_5)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int local_c;
  void *local_8;
  
  piVar1 = param_5;
  iVar3 = param_3;
  if ((param_3 != 0) && (iVar2 = props_requireInt(param_1,param_5,(int *)&local_8), iVar2 == 0)) {
    return 0;
  }
  iVar2 = *param_2;
  score_dateFromDayCount(*(undefined4 *)(iVar2 + 0xc),(uint *)&param_5,&param_3,&local_c);
  switch(param_4) {
  case 0xf1:
    if (iVar3 != 0) {
      iVar3 = score_getColorValue(local_8,local_c);
      *(int *)(iVar2 + 0xc) = iVar3;
      return 1;
    }
    piVar1[1] = (int)param_5;
    *piVar1 = 4;
    return 1;
  case 0xf2:
    break;
  case 0xf3:
    if (iVar3 == 0) {
      *piVar1 = 4;
      piVar1[1] = local_c;
      return 1;
    }
    if ((0 < (int)local_8) && (iVar3 = score_getDaysInMonth((uint)param_5), (int)local_8 <= iVar3)) {
      iVar3 = score_getColorValue(param_5,(int)local_8);
      *(int *)(iVar2 + 0xc) = iVar3;
      return 1;
    }
    props_setErrorAndReturn(param_1,0x3d);
    return 1;
  default:
    return 0;
  case 0x130:
    if (iVar3 == 0) {
      *piVar1 = 4;
      piVar1[1] = *(int *)(*param_2 + 8);
      return 1;
    }
    if (local_8 < (void *)0x15180) {
      *(void **)(iVar2 + 8) = local_8;
      return 1;
    }
    props_setErrorAndReturn(param_1,0x3d);
    return 1;
  }
  if (iVar3 == 0) {
    piVar1[1] = param_3;
    *piVar1 = 4;
    return 1;
  }
  if ((int)local_8 - 1U < 0xc) {
    iVar3 = score_getColorValue(param_5,local_c);
    *(int *)(iVar2 + 0xc) = iVar3;
    return 1;
  }
  props_setErrorAndReturn(param_1,0x3d);
  return 1;
}


// ============================================================
// Function: score_formatDateString (FUN_680470a0)
// Address: 680470a0
// Size: 92 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_formatDateString(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  uint local_c;
  int local_8;
  
  score_dateFromDayCount(*(undefined4 *)(*param_2 + 0xc),&local_c,&local_8,(int *)&param_2);
  cast_loadPascalString(&DAT_68197780,0x898,0x3b);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}


// ============================================================
// Function: score_dateToInt (FUN_68047100)
// Address: 68047100
// Size: 63 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_dateToInt(undefined4 param_1,int *param_2,int *param_3)

{
  int local_c;
  int local_8;
  
  score_dateFromDayCount(*(undefined4 *)(*param_2 + 0xc),(uint *)&param_2,&local_8,&local_c);
  *param_3 = ((int)param_2 * 100 + local_8) * 100 + local_c;
  return 1;
}


// ============================================================
// Function: score_serializeDate (FUN_68047140)
// Address: 68047140
// Size: 93 bytes
// Params: undefined4 * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_serializeDate(undefined4 *param_1,int *param_2)
{
  bool bVar1;
  uint uVar2;
  undefined3 extraout_var;
  int local_c;
  undefined4 local_8;
  
  uVar2 = stage_serializeData(param_1,param_2,0,0x10,2);
  if (uVar2 == 0) {
    local_c = 4;
    local_8 = *(undefined4 *)(*param_2 + 0xc);
    bVar1 = stage_serializeFloat(param_1,&local_c);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      local_c = 4;
      local_8 = *(undefined4 *)(*param_2 + 8);
      stage_serializeFloat(param_1,&local_c);
    }
  }
  return 0;
}


// ============================================================
// Function: score_compareDates (FUN_680471a0)
// Address: 680471a0
// Size: 358 bytes
// Params: int * param_1, int * param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall score_compareDates(int *param_1,int *param_2,undefined4 param_3)

{
  undefined4 *in_EAX;
  int iVar1;
  int iVar2;
  
  switch(param_3) {
  case 6:
    iVar2 = *(int *)(*param_2 + 0xc) - *(int *)(*param_1 + 0xc);
    iVar1 = *(int *)(*param_2 + 8) - *(int *)(*param_1 + 8);
    if ((iVar1 < 0) && (0x15180 < iVar1)) {
      iVar2 = iVar2 + -1;
    }
    in_EAX[1] = iVar2;
    *in_EAX = 4;
    return 1;
  default:
    return 0;
  case 0xc:
    *in_EAX = 4;
    in_EAX[1] = (uint)(*(int *)(*param_2 + 0xc) < *(int *)(*param_1 + 0xc));
    return 1;
  case 0xd:
    *in_EAX = 4;
    in_EAX[1] = (uint)(*(int *)(*param_2 + 0xc) <= *(int *)(*param_1 + 0xc));
    return 1;
  case 0xe:
    *in_EAX = 4;
    in_EAX[1] = (uint)(*(int *)(*param_2 + 0xc) != *(int *)(*param_1 + 0xc));
    return 1;
  case 0xf:
    *in_EAX = 4;
    in_EAX[1] = (uint)(*(int *)(*param_2 + 0xc) == *(int *)(*param_1 + 0xc));
    return 1;
  case 0x10:
    *in_EAX = 4;
    in_EAX[1] = (uint)(*(int *)(*param_1 + 0xc) < *(int *)(*param_2 + 0xc));
    return 1;
  case 0x11:
    *in_EAX = 4;
    in_EAX[1] = (uint)(*(int *)(*param_1 + 0xc) <= *(int *)(*param_2 + 0xc));
    return 1;
  case 0x24:
  case 0x25:
    break;
  }
  *in_EAX = 4;
  if (*(int *)(*param_2 + 0xc) < *(int *)(*param_1 + 0xc)) {
    in_EAX[1] = 0xffffffff;
    return 1;
  }
  in_EAX[1] = (uint)(*(int *)(*param_2 + 0xc) != *(int *)(*param_1 + 0xc));
  return 1;
}


// ============================================================
// Function: score_isDateObject (FUN_68047350)
// Address: 68047350
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_isDateObject(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d6a0)) {
    return 1;
  }
  return 0;
}


// ============================================================
// Function: score_setDateProperty (FUN_68047380)
// Address: 68047380
// Size: 65 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_setDateProperty(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(0x10,1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + 1;
  *(int *)(*piVar2 + 4) = *(int *)(*piVar2 + 4) + 1;
  puVar1 = (undefined4 *)*piVar2;
  puVar1[3] = param_2;
  *puVar1 = &PTR_LAB_6818d6a0;
  puVar1[1] = 1;
  puVar1[2] = param_3;
  return 0;
}


// ============================================================
// Function: score_dispatchDateCallback (FUN_680473d0)
// Address: 680473d0
// Size: 42 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispatchDateCallback(undefined4 *param_1)
{
  (**(code **)(*(int *)*param_1 + 0x24))
            ((int *)*param_1,param_1 + 2,param_1[4],param_1[5],param_1 + 6,param_1[1]);
  return 0;
}


// ============================================================
// Function: score_invokeDateHandler (FUN_68047400)
// Address: 68047400
// Size: 231 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_invokeDateHandler(undefined4 param_1)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  undefined4 local_30 [2];
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_30[0] = param_1;
  local_1c = 0;
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 < 2) {
    props_setError(unaff_ESI,0x16);
    return 0;
  }
  puVar2 = (undefined4 *)
           (**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 +
           *(int *)(unaff_ESI + 0x18));
  local_28 = *puVar2;
  local_24 = puVar2[1];
  local_20 = puVar2[3];
  puVar3 = puVar2 + 4;
  if (puVar2[2] != 8) {
    props_setError(unaff_ESI,0xb);
    return 0;
  }
  if (2 < iVar1) {
    local_1c = local_1c + 1;
    local_18 = *puVar3;
    local_14 = puVar2[5];
    puVar3 = puVar2 + 6;
  }
  if (3 < iVar1) {
    local_1c = local_1c + 1;
    local_10 = *puVar3;
    local_c = puVar3[1];
  }
  sprites_sendMessage(unaff_ESI,score_dispatchDateCallback,local_30);
  return 0;
}


// ============================================================
// Function: score_sendDateMessage (FUN_680474f0)
// Address: 680474f0
// Size: 151 bytes
// Params: int param_1, int * param_2, undefined4 param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_sendDateMessage(int param_1,int *param_2,undefined4 param_3,uint *param_4)
{
  int iVar1;
  undefined4 local_30;
  uint *local_2c;
  undefined4 local_28;
  int *local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_8;
  
  *param_4 = 0;
  param_4[1] = 0;
  local_20 = param_3;
  local_30 = *(undefined4 *)(*param_2 + 8);
  local_2c = param_4;
  local_1c = 0;
  local_28 = 3;
  local_24 = param_2;
  iVar1 = sprites_sendMessage(param_1,score_dispatchDateCallback,&local_30);
  if (iVar1 == 0) {
    if (*param_4 == 0) {
      *param_4 = 3;
      param_4[1] = (uint)param_2;
      props_retainValue(param_1,param_4);
    }
  }
  else {
    props_mapErrorCode(param_1,iVar1,param_3);
  }
  return 0;
}


// ============================================================
// Function: score_dispatchDateEvent (FUN_68047590)
// Address: 68047590
// Size: 30 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_dispatchDateEvent(undefined4 *param_1)
{
  (**(code **)(*(int *)*param_1 + 0x28))((int *)*param_1,param_1 + 2,param_1[1]);
  return 0;
}


// ============================================================
// Function: score_sendDateEvent (FUN_680475b0)
// Address: 680475b0
// Size: 96 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall score_sendDateEvent(int param_1,undefined4 param_2)
{
  undefined1 local_14 [4];
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  _DAT_68197764 =
       (undefined4 *)
       (**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18));
  local_8 = DAT_6819776c;
  local_c = DAT_68197768;
  if (_DAT_68197764 != (undefined4 *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_8 = ((int *)(size_t)_DAT_68197764)[1];
    local_c = *(int *)(size_t)_DAT_68197764;
  }
  local_10 = param_2;
  sprites_sendMessage(param_1,score_dispatchDateEvent,local_14);
  return 0;
}


