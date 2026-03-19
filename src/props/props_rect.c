// Module: props
// Topic: Rectangle/point object operations
// Address range: 0x6803c400 - 0x6803cf60
// Functions (26):
//   props_checkRectType (FUN_6803c400)
//   props_getSetRectField (FUN_6803c470)
//   props_findFieldIndex (FUN_6803c530)
//   props_getRectFieldByName (FUN_6803c570)
//   props_setRectFieldByName (FUN_6803c600)
//   props_getRectFieldByIndex (FUN_6803c710)
//   props_checkRectPropType (FUN_6803c790)
//   props_handleRectProp (FUN_6803c810)
//   props_initRectLayout (FUN_6803c980)
//   props_createRect
//   props_extractRectOrigin (FUN_6803ca00)
//   props_intersectRectOp (FUN_6803ca60)
//   props_checkPointType (FUN_6803cb50)
//   props_checkPointPropType (FUN_6803cbc0)
//   props_handlePointProp (FUN_6803cc40)
//   props_initPointLayout (FUN_6803cc80)
//   props_convertToPoint (FUN_6803ccc0)
//   props_getRectField
//   props_checkIsList (FUN_6803cd40)
//   props_setRectField
//   props_markRectDirty (FUN_6803cdc0)
//   props_releaseRectFields (FUN_6803ce20)
//   props_serializeRectData (FUN_6803ce70)
//   props_serializeRectType10 (FUN_6803cf20)
//   props_serializeRectType11 (FUN_6803cf40)
//   props_serializeRectType9 (FUN_6803cf60)



// ============================================================
// Function: props_checkRectType (FUN_6803c400)
// Address: 6803c400
// Size: 104 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_checkRectType(void)
{
  int iVar1;
  int unaff_ESI;
  uint local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 == 1) {
    props_normalizeType(unaff_ESI,8,0xbc);
    return 0;
  }
  iVar1 = props_getTypedValue(unaff_ESI,2,8,&local_8);
  if (iVar1 != 0) {
    if ((local_8 != 0xba) && (local_8 != 0xbc)) {
      local_8 = 0;
      props_normalizeType(unaff_ESI,4,0);
      return 0;
    }
    local_8 = 1;
    props_normalizeType(unaff_ESI,4,1);
  }
  return 0;
}



// ============================================================
// Function: props_getSetRectField (FUN_6803c470)
// Address: 6803c470
// Size: 185 bytes
// Params: int * param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getSetRectField(int *param_1,uint param_2)
{
  uint *puVar1;
  int *piVar2;
  uint uVar3;
  uint *in_EAX;
  int iVar4;
  int unaff_EBX;
  int unaff_EDI;
  uint local_c;
  uint local_8;
  
  if (param_2 == 0) {
    iVar4 = *param_1;
    uVar3 = *(uint *)(iVar4 + 0x28 + unaff_EBX * 8);
    *in_EAX = uVar3;
    in_EAX[1] = *(uint *)(iVar4 + 0x2c + unaff_EBX * 8);
    if ((uVar3 & 1) != 0) {
      props_retainValue(unaff_EDI,in_EAX);
    }
    return 0;
  }
  iVar4 = props_coerceToInt(unaff_EDI,(int *)in_EAX,(int *)&param_2);
  if (iVar4 == 0) {
    props_setErrorAndReturn(unaff_EDI,7);
    return 0;
  }
  if (*(int *)(unaff_EDI + 0xd4) < 0) {
    local_c = 4;
    local_8 = param_2;
  }
  else {
    local_c = *in_EAX;
    local_8 = in_EAX[1];
    if ((local_c & 1) != 0) {
      props_retainValue(unaff_EDI,&local_c);
    }
  }
  piVar2 = *(int **)(*param_1 + 0x2c + unaff_EBX * 8);
  puVar1 = (uint *)(*param_1 + 0x28 + unaff_EBX * 8);
  uVar3 = *puVar1;
  *puVar1 = local_c;
  puVar1[1] = local_8;
  props_releaseValue(unaff_EDI,(byte)uVar3,piVar2);
  return 0;
}



// ============================================================
// Function: props_findFieldIndex (FUN_6803c530)
// Address: 6803c530
// Size: 50 bytes
// Params: int param_1, int * param_2, int param_3
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall props_findFieldIndex(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int unaff_ESI;
  
  iVar1 = 0;
  while( true ) {
    if (param_1 < 1) {
      props_reportError(param_3,0x37);
      return -1;
    }
    if (*param_2 == unaff_ESI) break;
    param_1 = param_1 + -1;
    iVar1 = iVar1 + 1;
    param_2 = param_2 + 1;
  }
  return iVar1;
}



// ============================================================
// Function: props_getRectFieldByName (FUN_6803c570)
// Address: 6803c570
// Size: 142 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getRectFieldByName(int *param_1,int param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  uint local_10;
  undefined4 local_c;
  uint local_8;
  
  piVar1 = (int *)(**(int **)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x20) * -8 + 8 +
                  *(int *)(unaff_EDI + 0x18));
  iVar2 = props_getInt(unaff_EDI);
  if ((iVar2 == 2) && (*piVar1 == 8)) {
    local_8 = piVar1[1];
  }
  else {
    iVar2 = props_getTypedValue(unaff_EDI,2,8,&local_8);
    if (iVar2 == 0) {
      return 0;
    }
  }
  iVar2 = props_findFieldIndex(param_2,param_3,unaff_EDI);
  if (-1 < iVar2) {
    local_10 = *(uint *)(*param_1 + 0x28 + iVar2 * 8);
    local_c = *(undefined4 *)(*param_1 + 0x2c + iVar2 * 8);
    if ((local_10 & 1) != 0) {
      props_retainValue(unaff_EDI,&local_10);
    }
    props_popArgs(unaff_EDI,&local_10);
  }
  return 0;
}



// ============================================================
// Function: props_setRectFieldByName (FUN_6803c600)
// Address: 6803c600
// Size: 259 bytes
// Params: int * param_1, int param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int props_setRectFieldByName(int *param_1,int param_2,int *param_3)
{
  int iVar1;
  int iVar2;
  int unaff_EDI;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar2 = props_getInt(unaff_EDI);
  if (iVar2 != 3) {
    props_setError(unaff_EDI,0x17);
    return 0;
  }
  iVar2 = **(int **)(unaff_EDI + 0x10) + *(int *)(unaff_EDI + 0x20) * -8;
  if (*(int *)(iVar2 + 8 + *(int *)(unaff_EDI + 0x18)) == 8) {
    local_8 = *(uint *)(iVar2 + *(int *)(unaff_EDI + 0x18) + 0xc);
  }
  else {
    iVar2 = props_getTypedValue(unaff_EDI,2,8,&local_8);
    if (iVar2 == 0) {
      return 0;
    }
  }
  iVar2 = props_findFieldIndex(param_2,param_3,unaff_EDI);
  if (-1 < iVar2) {
    _DAT_68197764 =
         (uint *)(**(int **)(unaff_EDI + 0x10) + (2 - *(int *)(unaff_EDI + 0x20)) * 8 +
                 *(int *)(unaff_EDI + 0x18));
    local_c = DAT_6819776c;
    local_10 = DAT_68197768;
    if (_DAT_68197764 != (uint *)0x0) {
      DAT_6819776c = 0;
      DAT_68197768 = 0;
      local_c = ((int *)(size_t)_DAT_68197764)[1];
      local_10 = *(int *)(size_t)_DAT_68197764;
    }
    if ((local_10 & 1) != 0) {
      props_retainValue(unaff_EDI,&local_10);
    }
    props_releaseValue(unaff_EDI,(byte)*(undefined4 *)(*param_1 + 0x28 + iVar2 * 8),
                 *(int **)(*param_1 + 0x2c + iVar2 * 8));
    iVar1 = *param_1;
    *(uint *)(iVar1 + 0x28 + iVar2 * 8) = local_10;
    *(uint *)(iVar1 + 0x2c + iVar2 * 8) = local_c;
    props_normalizeType(unaff_EDI,4,0);
  }
  return 0;
}



// ============================================================
// Function: props_getRectFieldByIndex (FUN_6803c710)
// Address: 6803c710
// Size: 123 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getRectFieldByIndex(int param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int unaff_ESI;
  uint local_8;
  
  piVar1 = (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
                  *(int *)(unaff_ESI + 0x18));
  iVar2 = props_getInt(unaff_ESI);
  if ((iVar2 == 2) && (*piVar1 == 4)) {
    local_8 = piVar1[1];
  }
  else {
    iVar2 = props_getTypedValue(unaff_ESI,2,4,&local_8);
    if (iVar2 == 0) {
      return 0;
    }
  }
  if ((-1 < (int)local_8) && ((int)local_8 <= param_1)) {
    props_normalizeType(unaff_ESI,8,*(int *)(param_2 + -4 + local_8 * 4));
    return 0;
  }
  props_reportError(unaff_ESI,0x3c);
  return 0;
}



// ============================================================
// Function: props_checkRectPropType (FUN_6803c790)
// Address: 6803c790
// Size: 58 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_checkRectPropType(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  switch(param_3) {
  case 0xb2:
  case 0xcb:
  case 0xcc:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd5:
  case 0xd6:
  case 0xdc:
  case 0xe0:
  case 0xe3:
  case 0xe5:
  case 0xe6:
  case 0xe7:
  case 0xe8:
    return 1;
  default:
    uVar1 = props_isListType(param_1,param_2,param_3);
    return uVar1;
  }
}



// ============================================================
// Function: props_handleRectProp (FUN_6803c810)
// Address: 6803c810
// Size: 314 bytes
// Params: int param_1, int * param_2, uint param_3, int param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_handleRectProp(int param_1,int *param_2,uint param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  int local_14;
  undefined4 local_10;
  int local_c;
  undefined4 local_8;
  
  switch(param_4) {
  case 0x46:
    break;
  case 0x47:
    break;
  case 0x48:
    if (param_3 != 0) {
      return 0;
    }
    iVar1 = *param_2;
    param_4 = 0;
    param_3 = 0;
    local_c = *(int *)(iVar1 + 0x28);
    local_8 = *(undefined4 *)(iVar1 + 0x2c);
    local_14 = *(int *)(iVar1 + 0x38);
    local_10 = *(undefined4 *)(iVar1 + 0x3c);
    iVar1 = props_coerceToInt(param_1,&local_c,&param_4);
    if ((iVar1 != 0) && (iVar1 = props_coerceToInt(param_1,&local_14,(int *)&param_3), iVar1 != 0)) {
      iVar1 = param_3 - param_4;
      goto LAB_6803c8cc;
    }
    goto LAB_6803c8c4;
  case 0x49:
    if (param_3 != 0) {
      return 0;
    }
    iVar1 = *param_2;
    param_4 = 0;
    param_3 = 0;
    local_14 = *(int *)(iVar1 + 0x30);
    local_10 = *(undefined4 *)(iVar1 + 0x34);
    local_c = *(int *)(iVar1 + 0x40);
    local_8 = *(undefined4 *)(iVar1 + 0x44);
    iVar1 = props_coerceToInt(param_1,&local_14,&param_4);
    if ((iVar1 != 0) && (iVar1 = props_coerceToInt(param_1,&local_c,(int *)&param_3), iVar1 != 0)) {
      iVar1 = param_3 - param_4;
      goto LAB_6803c8cc;
    }
LAB_6803c8c4:
    iVar1 = 0;
    props_setError(param_1,8);
LAB_6803c8cc:
    param_5[1] = iVar1;
    *param_5 = 4;
    return 1;
  default:
    return 0;
  case 0x50:
    break;
  /* FIXUP(C2143-ctx): case 0x51: */
  } /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */;
  props_getSetRectField(param_2,param_3);
  return 1;
}



// ============================================================
// Function: props_initRectLayout (FUN_6803c980)
// Address: 6803c980
// Size: 37 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_initRectLayout(undefined4 param_1,int *param_2)
{
  props_listToString(param_2,0x21,0x20,0x22);
  return 0;
}



// ============================================================
// Function: props_createRect (FUN_6803c9c0)
// Address: 6803c9c0
// Size: 52 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_createRect(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d410)) {
    props_getListCount((int *)param_2[1]);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_extractRectOrigin (FUN_6803ca00)
// Address: 6803ca00
// Size: 85 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_extractRectOrigin(int param_1)
{
  int iVar1;
  int *unaff_EBX;
  int *unaff_EDI;
  int local_c;
  undefined4 local_8;
  
  local_c = *(int *)(*unaff_EBX + 0x28);
  local_8 = *(undefined4 *)(*unaff_EBX + 0x2c);
  iVar1 = props_coerceToInt(param_1,&local_c,unaff_EDI + 1);
  if (iVar1 == 0) {
    unaff_EDI[1] = 0;
  }
  local_c = *(int *)(*unaff_EBX + 0x30);
  local_8 = *(undefined4 *)(*unaff_EBX + 0x34);
  iVar1 = props_coerceToInt(param_1,&local_c,unaff_EDI);
  if (iVar1 == 0) {
    *unaff_EDI = 0;
  }
  return 0;
}



// ============================================================
// Function: props_intersectRectOp (FUN_6803ca60)
// Address: 6803ca60
// Size: 231 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int props_intersectRectOp(void)
{
  int local_18;
  int iVar1;
  int unaff_ESI;
  undefined4 local_28 [2];
  int local_20;
  int local_1c;
  /* FIXUP(C2040: 'local_18': 'undefined4): undefined4 local_18 [4]; */
  uint local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 != 2) {
    props_setError(unaff_ESI,0x16);
    return 0;
  }
  _DAT_68197764 =
       (int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
              *(int *)(unaff_ESI + 0x18));
  local_1c = DAT_6819776c;
  local_20 = DAT_68197768;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    local_1c = ((int *)(size_t)_DAT_68197764)[1];
    local_20 = *(int *)(size_t)_DAT_68197764;
  }
  iVar1 = props_createRect(unaff_ESI,&local_20);
  if (iVar1 != 0) {
    props_extractRectOrigin(unaff_ESI);
    local_20 = 4;
    local_1c = props_intersectRect(unaff_ESI,local_28,local_18);
    props_popArgs(unaff_ESI,&local_20);
    return 0;
  }
  props_setErrorAndReturn(unaff_ESI,0xe);
  return 0;
}



// ============================================================
// Function: props_checkPointType (FUN_6803cb50)
// Address: 6803cb50
// Size: 104 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_checkPointType(void)
{
  int iVar1;
  int unaff_ESI;
  uint local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if (iVar1 == 1) {
    props_normalizeType(unaff_ESI,8,0xbd);
    return 0;
  }
  iVar1 = props_getTypedValue(unaff_ESI,2,8,&local_8);
  if (iVar1 != 0) {
    if ((local_8 != 0xba) && (local_8 != 0xbd)) {
      local_8 = 0;
      props_normalizeType(unaff_ESI,4,0);
      return 0;
    }
    local_8 = 1;
    props_normalizeType(unaff_ESI,4,1);
  }
  return 0;
}



// ============================================================
// Function: props_checkPointPropType (FUN_6803cbc0)
// Address: 6803cbc0
// Size: 58 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_checkPointPropType(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  switch(param_3) {
  case 0xbc:
  case 0xcb:
  case 0xcc:
  case 0xce:
  case 0xcf:
  case 0xd0:
  case 0xd1:
  case 0xd5:
  case 0xd6:
  case 0xdc:
  case 0xe0:
  case 0xe3:
  case 0xe8:
  case 0xe9:
    return 1;
  default:
    uVar1 = props_isListType(param_1,param_2,param_3);
    return uVar1;
  }
}



// ============================================================
// Function: props_handlePointProp (FUN_6803cc40)
// Address: 6803cc40
// Size: 62 bytes
// Params: undefined4 param_1, int * param_2, uint param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_handlePointProp(undefined4 param_1,int *param_2,uint param_3,int param_4)

{
  if ((param_4 != 0x52) && (param_4 != 0x53)) {
    return 0;
  }
  props_getSetRectField(param_2,param_3);
  return 1;
}



// ============================================================
// Function: props_initPointLayout (FUN_6803cc80)
// Address: 6803cc80
// Size: 37 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_initPointLayout(undefined4 param_1,int *param_2)
{
  props_listToString(param_2,0x23,0x20,0x22);
  return 0;
}



// ============================================================
// Function: props_convertToPoint (FUN_6803ccc0)
// Address: 6803ccc0
// Size: 59 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_convertToPoint(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d268)) {
    stage_emitPopVar((int *)param_2[1]);
    **(undefined4 **)param_2[1] = &PTR_LAB_6818d3c0;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_getRectField (FUN_6803cd00)
// Address: 6803cd00
// Size: 56 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getRectField(int param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d3c0)) {
    props_extractRectOrigin(param_1);
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_checkIsList (FUN_6803cd40)
// Address: 6803cd40
// Size: 39 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_checkIsList(undefined4 param_1,int *param_2)

{
  if ((*param_2 == 3) && ((undefined **)**(int **)param_2[1] == &PTR_LAB_6818d268)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_setRectField (FUN_6803cd70)
// Address: 6803cd70
// Size: 68 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_setRectField(undefined4 param_1,int *param_2)

{
  undefined **ppuVar1;
  
  if ((*param_2 == 3) &&
     ((((ppuVar1 = (undefined **)**(int **)param_2[1], ppuVar1 == &PTR_LAB_6818d268 ||
        (ppuVar1 == &PTR_LAB_6818d410)) || (ppuVar1 == &PTR_LAB_6818d3c0)) ||
      ((ppuVar1 == &PTR_LAB_6818d320 || (ppuVar1 == &PTR_LAB_6818d370)))))) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_markRectDirty (FUN_6803cdc0)
// Address: 6803cdc0
// Size: 84 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_markRectDirty(undefined4 param_1,int *param_2)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  
  *(uint *)(*param_2 + 4) = *(uint *)(*param_2 + 4) | 0x80000000;
  iVar3 = *(int *)(*param_2 + 0x10);
  if (0 < iVar3) {
    iVar4 = 0x28;
    do {
      piVar1 = *(int **)(iVar4 + 4 + *param_2);
      if ((*(int *)(iVar4 + *param_2) == 3) &&
         (piVar2 = (int *)*piVar1, (piVar2[1] & 0x80000000U) == 0)) {
        (**(code **)(*piVar2 + 0x34))(param_1,piVar1);
      }
      iVar4 = iVar4 + 8;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return 0;
}



// ============================================================
// Function: props_releaseRectFields (FUN_6803ce20)
// Address: 6803ce20
// Size: 76 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_releaseRectFields(undefined4 param_1,int *param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(*param_2 + 0x10);
  if (0 < iVar2) {
    iVar3 = 0x28;
    do {
      puVar1 = *(undefined4 **)(iVar3 + 4 + *param_2);
      if (((byte)*(undefined4 *)(iVar3 + *param_2) & 0x1f) == 3) {
        (**(code **)(*(int *)*puVar1 + 0x3c))(param_1,puVar1);
      }
      iVar3 = iVar3 + 8;
      iVar2 = iVar2 + -1;
    } while (iVar2 != 0);
  }
  return 0;
}



// ============================================================
// Function: props_serializeRectData (FUN_6803ce70)
// Address: 6803ce70
// Size: 167 bytes
// Params: undefined4 param_1, uint param_2, undefined4 * param_3
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall props_serializeRectData(undefined4 param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  bool bVar2;
  undefined3 extraout_var;
  uint uVar3;
  int iVar4;
  int *unaff_EDI;
  int local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  iVar1 = *(int *)(*unaff_EDI + 0x10);
  local_c = stage_serializeData(param_3,unaff_EDI,0,param_2,iVar1 + 1);
  uVar3 = local_c;
  if (local_c == 0) {
    local_14 = 4;
    local_10 = (uint)(*(code **)(*unaff_EDI + 0x24) == props_convertValue) * 2 |
               (uint)(*(int *)(*unaff_EDI + 0x20) != 0);
    stage_serializeFloat(param_3,&local_14);
    local_8 = 0;
    uVar3 = local_c;
    if (0 < iVar1) {
      iVar4 = 0x28;
      while( true ) {
        local_14 = *(int *)(*unaff_EDI + iVar4);
        local_10 = *(undefined4 *)(*unaff_EDI + 4 + iVar4);
        bVar2 = stage_serializeFloat(param_3,&local_14);
        uVar3 = CONCAT31(extraout_var,bVar2);
        if (CONCAT31(extraout_var,bVar2) != 0) break;
        local_8 = local_8 + 1;
        iVar4 = iVar4 + 8;
        if (iVar1 <= local_8) {
          return 0;
        }
      }
    }
  }
  return uVar3;
}



// ============================================================
// Function: props_serializeRectType10 (FUN_6803cf20)
// Address: 6803cf20
// Size: 26 bytes
// Params: void * this, undefined4 * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall props_serializeRectType10(void *this,undefined4 *param_1)
{
  props_serializeRectData(this,10,param_1);
  return 0;
}



// ============================================================
// Function: props_serializeRectType11 (FUN_6803cf40)
// Address: 6803cf40
// Size: 26 bytes
// Params: void * this, undefined4 * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall props_serializeRectType11(void *this,undefined4 *param_1)
{
  props_serializeRectData(this,0xb,param_1);
  return 0;
}



// ============================================================
// Function: props_serializeRectType9 (FUN_6803cf60)
// Address: 6803cf60
// Size: 26 bytes
// Params: void * this, undefined4 * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall props_serializeRectType9(void *this,undefined4 *param_1)
{
  props_serializeRectData(this,9,param_1);
  return 0;
}


