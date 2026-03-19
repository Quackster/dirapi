// Module: props
// Topic: Rectangle geometry helpers
// Address range: 0x6803e0b0 - 0x6803e8f0
// Functions (10):
//   props_remapRectCoords
//   props_dispatchRectGeom
//   props_handleTwoRectTransform
//   props_dispatchPointGeom
//   props_mapPointToRect
//   props_intersectTwoRects
//   props_unionTwoRects
//   props_remapRectPoints
//   props_offsetRect
//   props_insetRect



// ============================================================
// Function: props_remapRectCoords (FUN_6803e0b0)
// Address: 6803e0b0
// Size: 354 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int __fastcall props_remapRectCoords(int param_1)
{
  int iVar1;
  int *unaff_EDI;
  int local_40;
  int local_3c;
  int local_38 [8];
  int local_18 [4];
  uint local_8;
  
  iVar1 = props_getInt(param_1);
  if (iVar1 != 3) {
    props_setError(param_1,0x17);
    return 0;
  }
  _DAT_68197764 =
       (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 + 8 +
              *(int *)(param_1 + 0x18));
  local_3c = DAT_6819776c;
  local_40 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_3c = ((int *)(size_t)_DAT_68197764)[1];
    local_40 = *(int *)(size_t)_DAT_68197764;
  }
  iVar1 = props_createRect(param_1,&local_40);
  if (iVar1 != 0) {
    _DAT_68197764 =
         (int *)(**(int **)(param_1 + 0x10) + (2 - *(int *)(param_1 + 0x20)) * 8 +
                *(int *)(param_1 + 0x18));
    local_3c = DAT_6819776c;
    local_40 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_3c = ((int *)(size_t)_DAT_68197764)[1];
      local_40 = *(int *)(size_t)_DAT_68197764;
    }
    iVar1 = props_createRect(param_1,&local_40);
    if (iVar1 != 0) {
      props_getListCount(unaff_EDI);
      props_remapRectPoints(param_1,local_18,local_38);
      props_computeRectOp(param_1,local_18,&local_40);
      props_popArgs(param_1,&local_40);
      return 0;
    }
    props_setErrorAndReturn(param_1,0xe);
    return 0;
  }
  props_setErrorAndReturn(param_1,0xe);
  return 0;
}



// ============================================================
// Function: props_dispatchRectGeom (FUN_6803e220)
// Address: 6803e220
// Size: 296 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_dispatchRectGeom(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  
  switch(param_3) {
  case 0xb2:
    props_buildRectOffset(param_1);
    return 1;
  default:
    uVar1 = props_createList(param_1,param_2,param_3);
    return uVar1;
  case 0xcb:
  case 0xcc:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xe0:
    props_normalizeType(param_1,2,0);
    return 1;
  case 0xd5:
    props_getRectFieldByName(param_2,4,(int *)&DAT_6818d45c);
    return 1;
  case 0xd6:
    props_getRectFieldByIndex(4,0x6818d45c);
    return 1;
  case 0xdc:
    props_setRectFieldByName(param_2,4,(int *)&DAT_6818d45c);
    return 1;
  case 0xe3:
    props_checkRectType();
    return 1;
  case 0xe5:
    props_buildRectInset(param_1);
    return 1;
  case 0xe6:
    props_buildRectIntersect(param_1);
    return 1;
  case 0xe7:
    props_buildRectUnion(param_1);
    return 1;
  case 0xe8:
    props_remapRectCoords(param_1);
    return 1;
  }
}



// ============================================================
// Function: props_handleTwoRectTransform (FUN_6803e3b0)
// Address: 6803e3b0
// Size: 351 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int props_handleTwoRectTransform(void)
{
  int iVar1;
  int unaff_ESI;
  int local_38 [2];
  int local_30;
  int local_2c;
  int local_28 [8];
  uint local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 != 3) {
    props_setError(unaff_ESI,0x17);
    return 0;
  }
  _DAT_68197764 =
       (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
              *(int *)(unaff_ESI + 0x18));
  local_2c = DAT_6819776c;
  local_30 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_2c = ((int *)(size_t)_DAT_68197764)[1];
    local_30 = *(int *)(size_t)_DAT_68197764;
  }
  iVar1 = props_createRect(unaff_ESI,&local_30);
  if (iVar1 != 0) {
    _DAT_68197764 =
         (int *)(**(int **)(unaff_ESI + 0x10) + (2 - *(int *)(unaff_ESI + 0x20)) * 8 +
                *(int *)(unaff_ESI + 0x18));
    local_2c = DAT_6819776c;
    local_30 = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_2c = ((int *)(size_t)_DAT_68197764)[1];
      local_30 = *(int *)(size_t)_DAT_68197764;
    }
    iVar1 = props_createRect(unaff_ESI,&local_30);
    if (iVar1 != 0) {
      props_extractRectOrigin(unaff_ESI);
      props_equalizeRect(unaff_ESI,local_38,local_28);
      props_transformRect(unaff_ESI,local_38,&local_30);
      props_popArgs(unaff_ESI,&local_30);
      return 0;
    }
    props_setErrorAndReturn(unaff_ESI,0xe);
    return 0;
  }
  props_setErrorAndReturn(unaff_ESI,0xe);
  return 0;
}



// ============================================================
// Function: props_dispatchPointGeom (FUN_6803e510)
// Address: 6803e510
// Size: 252 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_dispatchPointGeom(int param_1,int *param_2,int param_3)

{
  undefined4 uVar1;
  
  switch(param_3) {
  case 0xbc:
    props_extractRectAndBuild();
    return 1;
  default:
    uVar1 = props_createList(param_1,param_2,param_3);
    return uVar1;
  case 0xcb:
  case 0xcc:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xe0:
    props_normalizeType(param_1,2,0);
    return 1;
  case 0xd5:
    props_getRectFieldByName(param_2,2,(int *)&DAT_6818d46c);
    return 1;
  case 0xd6:
    props_getRectFieldByIndex(2,0x6818d46c);
    return 1;
  case 0xdc:
    props_setRectFieldByName(param_2,2,(int *)&DAT_6818d46c);
    return 1;
  case 0xe3:
    props_checkPointType();
    return 1;
  case 0xe8:
    props_handleTwoRectTransform();
    return 1;
  case 0xe9:
    props_intersectRectOp();
    return 1;
  }
}



// ============================================================
// Function: props_mapPointToRect (FUN_6803e660)
// Address: 6803e660
// Size: 181 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_mapPointToRect(int *param_1,int *param_2)
{
  int *in_EAX;
  int iVar1;
  
  iVar1 = param_2[3] - param_2[1];
  if (iVar1 == 0) {
    param_1[1] = 0;
  }
  else {
    iVar1 = ((in_EAX[3] - in_EAX[1]) * (param_1[1] - param_2[1])) / iVar1 + in_EAX[1];
    if (iVar1 < -0x8000) {
      param_1[1] = -0x8000;
    }
    else {
      if (0x7fff < iVar1) {
        iVar1 = 0x7fff;
      }
      param_1[1] = iVar1;
    }
  }
  iVar1 = param_2[2] - *param_2;
  if (iVar1 != 0) {
    iVar1 = ((in_EAX[2] - *in_EAX) * (*param_1 - *param_2)) / iVar1 + *in_EAX;
    if (iVar1 < -0x8000) {
      *param_1 = -0x8000;
      return 0;
    }
    if (0x7fff < iVar1) {
      iVar1 = 0x7fff;
    }
    *param_1 = iVar1;
    return 0;
  }
  *param_1 = 0;
  return 0;
}



// ============================================================
// Function: props_intersectTwoRects (FUN_6803e720)
// Address: 6803e720
// Size: 153 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_intersectTwoRects(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)
{
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_2[1];
  local_14 = *param_2;
  local_10 = param_2[3];
  local_c = param_2[2];
  local_28 = param_3[1];
  local_24 = *param_3;
  local_20 = param_3[3];
  local_1c = param_3[2];
  Ordinal_1066(&local_38,&local_18,&local_28);
  param_4[1] = local_38;
  *param_4 = local_34;
  param_4[3] = local_30;
  param_4[2] = local_2c;
  if ((local_30 <= local_38) || (local_2c <= local_34)) {
    Ordinal_1130(param_4,0x10);
  }
  return 0;
}



// ============================================================
// Function: props_unionTwoRects (FUN_6803e7c0)
// Address: 6803e7c0
// Size: 147 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_unionTwoRects(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int *param_4)
{
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_18 = param_2[1];
  local_14 = *param_2;
  local_10 = param_2[3];
  local_c = param_2[2];
  local_28 = param_3[1];
  local_24 = *param_3;
  local_20 = param_3[3];
  local_1c = param_3[2];
  Ordinal_1067(&local_38,&local_18,&local_28);
  param_4[1] = local_38;
  *param_4 = local_34;
  param_4[3] = local_30;
  param_4[2] = local_2c;
  if ((local_30 <= local_38) || (local_2c <= local_34)) {
    Ordinal_1130(param_4,0x10);
  }
  return 0;
}



// ============================================================
// Function: props_remapRectPoints (FUN_6803e860)
// Address: 6803e860
// Size: 97 bytes
// Params: undefined4 param_1, int * param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_remapRectPoints(undefined4 param_1,int *param_2,int *param_3)
{
  int local_c;
  int local_8;
  
  local_c = *param_2;
  local_8 = param_2[1];
  props_mapPointToRect(&local_c,param_3);
  *param_2 = local_c;
  param_2[1] = local_8;
  local_c = param_2[2];
  local_8 = param_2[3];
  props_mapPointToRect(&local_c,param_3);
  param_2[2] = local_c;
  param_2[3] = local_8;
  return 0;
}



// ============================================================
// Function: props_offsetRect (FUN_6803e8d0)
// Address: 6803e8d0
// Size: 27 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_offsetRect(undefined4 param_1,int *param_2,int param_3,int param_4)
{
  param_2[1] = param_2[1] + param_3;
  param_2[3] = param_2[3] + param_3;
  *param_2 = *param_2 + param_4;
  param_2[2] = param_2[2] + param_4;
  return 0;
}



// ============================================================
// Function: props_insetRect (FUN_6803e8f0)
// Address: 6803e8f0
// Size: 27 bytes
// Params: undefined4 param_1, int * param_2, int param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_insetRect(undefined4 param_1,int *param_2,int param_3,int param_4)
{
  param_2[1] = param_2[1] - param_3;
  param_2[3] = param_2[3] + param_3;
  *param_2 = *param_2 - param_4;
  param_2[2] = param_2[2] + param_4;
  return 0;
}


