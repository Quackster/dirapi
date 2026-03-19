// Module: cast
// Topic: Xtra properties, lifecycle, and native bridge
// Address range: 0x68027500 - 0x68028230
// Functions (18):
//   cast_compareXtraOperands
//   cast_buildColorVector
//   cast_buildRgbVector
//   cast_invokeXtraMethod
//   cast_releaseXtraProperty
//   cast_formatXtraError
//   cast_getSetXtraField
//   cast_hasXtraProperty
//   cast_allocXtraProperty
//   cast_createXtraProperty
//   cast_applyXtraProplist
//   cast_setXtraTransform
//   cast_findXtraPropertyRef
//   cast_setXtraModifiedFlag
//   cast_cloneXtraProperty
//   cast_newXtraInstance
//   cast_getXtraProperty
//   cast_setXtraPropertyEx

// ============================================================
// Function: cast_compareXtraOperands (FUN_68027500)
// Address: 68027500
// Size: 442 bytes
// Params: int param_1, int * param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cast_compareXtraOperands(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int *extraout_EDX;
  int iVar3;
  int *piVar4;
  double local_28;
  int local_20;
  undefined4 local_18;
  uint local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  local_8 = 0;
  iVar1 = DAT_68197768;
  piVar2 = DAT_6819776c;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = (int *)0x0;
    DAT_68197768 = 0;
    iVar1 = *(int *)(size_t)_DAT_68197764;
    piVar2 = (int *)((int *)(size_t)_DAT_68197764)[1];
  }
  local_10 = *(int *)(param_1 + 0x1c);
  local_c = *(int **)(param_1 + 0x20);
  piVar4 = piVar2;
  local_20 = iVar1;
  if ((local_10 == 3) && (local_c == param_2)) {
    piVar4 = *(int **)(param_1 + 0x20);
    local_8 = 1;
    local_20 = 3;
    local_10 = iVar1;
    local_c = piVar2;
  }
  iVar1 = cast_getVectorRef(param_1,&local_10);
  if (iVar1 == 0) {
    iVar1 = score_getMediaValue(param_1,&local_10);
    if ((iVar1 != 0) && (param_3 == 4)) {
      iVar1 = cast_destroyMediaVector(param_1,&local_10);
      if (iVar1 != 0) {
        props_setError(param_1,5);
        return 1;
      }
      iVar1 = (**(code **)(*(int *)*local_c + 0x28))(param_1,local_c,4);
      return iVar1;
    }
    iVar1 = props_coerceToFloat(param_1,&local_10,&local_28);
    if (iVar1 == 0) {
      if ((param_3 != 0xf) && (param_3 != 0xe)) {
        return 0;
      }
      local_14 = (uint)(param_3 == 0xe);
      local_18 = 4;
      iVar1 = 1;
      goto LAB_680275a5;
    }
    iVar1 = cast_scalarVectorOp((float *)(*piVar4 + 8),local_8,param_3,(float)(size_t)local_28);
  }
  else {
    if (local_8 == 0) {
      iVar1 = *extraout_EDX;
      iVar3 = *piVar4;
    }
    else {
      iVar1 = *piVar4;
      iVar3 = *extraout_EDX;
    }
    iVar1 = cast_binaryVectorOp((float *)(iVar1 + 8),(float *)(iVar3 + 8),param_3);
  }
  if (iVar1 == 0) {
    return 0;
  }
LAB_680275a5:
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -0x10;
  iVar3 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar3 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar3 + 4 + *(int *)(param_1 + 0x18));
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x1c) = local_18;
  *(uint *)(param_1 + 0x20) = local_14;
  props_releaseValue(param_1,(byte)local_20,piVar4);
  props_releaseValue(param_1,(byte)local_10,local_c);
  return iVar1;
}



// ============================================================
// Function: cast_buildColorVector (FUN_680276c0)
// Address: 680276c0
// Size: 484 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cast_buildColorVector(int param_1)
{
  int iVar1;
  int iVar2;
  float *pfVar3;
  undefined4 local_30 [4];
  double local_20;
  float local_18;
  float local_14 [3];
  uint local_8;
  
  iVar1 = props_getInt(param_1);
  iVar2 = props_getInt(param_1);
  if (iVar2 == 0) {
    local_18 = (float)cast_getRandomValue(0x7fffffff);
    local_14[0] = (float)(int)local_18 * 4.656613e-10;
    local_18 = (float)cast_getRandomValue(0x7fffffff);
    local_14[1] = (float)(int)local_18 * 4.656613e-10;
    local_18 = (float)cast_getRandomValue(0x7fffffff);
    local_14[2] = (float)(int)local_18 * 4.656613e-10;
    cast_randomSpherePoint(1.0);
    iVar1 = cast_getVectorData(param_1,local_30);
    props_normalizeType(param_1,3,iVar1);
    return 0;
  }
  if (iVar1 != 4) {
    props_setError(param_1,0x18);
    return 0;
  }
  iVar1 = 1;
  pfVar3 = local_14;
  do {
    iVar2 = props_coerceToFloat(param_1,(int *)(**(int **)(param_1 + 0x10) + -8 +
                                         (iVar1 - *(int *)(param_1 + 0x20)) * 8 +
                                        *(int *)(param_1 + 0x18)),&local_20);
    if (iVar2 == 0) {
      _DAT_68197764 = **(int **)(param_1 + 0x10) + -8 + (iVar1 - *(int *)(param_1 + 0x20)) * 8;
      goto LAB_680277f7;
    }
    iVar1 = iVar1 + 1;
    *pfVar3 = (float)(size_t)local_20;
    pfVar3 = pfVar3 + 1;
  } while (iVar1 < 4);
  iVar1 = props_coerceToFloat(param_1,(int *)(**(int **)(param_1 + 0x10) +
                                       (3 - *(int *)(param_1 + 0x20)) * 8 + *(int *)(param_1 + 0x18)
                                      ),&local_20);
  if (iVar1 != 0) {
    local_18 = (float)(size_t)local_20;
    cast_randomSpherePoint(local_18);
    iVar1 = cast_getVectorData(param_1,local_30);
    props_normalizeType(param_1,3,iVar1);
    return 0;
  }
  _DAT_68197764 = **(int **)(param_1 + 0x10) + (3 - *(int *)(param_1 + 0x20)) * 8;
LAB_680277f7:
  _DAT_68197764 = _DAT_68197764 + *(int *)(param_1 + 0x18);
  if (_DAT_68197764 != 0) {
    DAT_6819776c = 0;
    DAT_68197768 = 0;
    props_setErrorAndReturn(param_1,8);
    return 0;
  }
  props_setErrorAndReturn(param_1,8);
  return 0;
}



// ============================================================
// Function: cast_buildRgbVector (FUN_680278b0)
// Address: 680278b0
// Size: 312 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cast_buildRgbVector(int param_1)
{
  int iVar1;
  int iVar2;
  float *pfVar3;
  double local_20;
  float local_18 [4];
  uint local_8;
  
  iVar1 = props_getInt(param_1);
  iVar2 = props_getInt(param_1);
  if (iVar2 == 0) {
    iVar1 = cast_getVectorData(param_1,(undefined4 *)0x0);
    props_normalizeType(param_1,3,iVar1);
    return 0;
  }
  if (iVar1 != 3) {
    props_setError(param_1,0x17);
    return 0;
  }
  local_18[3] = 1.0;
  iVar1 = 1;
  pfVar3 = local_18;
  do {
    iVar2 = props_coerceToFloat(param_1,(int *)(**(int **)(param_1 + 0x10) + -8 +
                                         (iVar1 - *(int *)(param_1 + 0x20)) * 8 +
                                        *(int *)(param_1 + 0x18)),&local_20);
    if (iVar2 == 0) {
      _DAT_68197764 =
           **(int **)(param_1 + 0x10) + -8 + (iVar1 - *(int *)(param_1 + 0x20)) * 8 +
           *(int *)(param_1 + 0x18);
      if (_DAT_68197764 != 0) {
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        props_setErrorAndReturn(param_1,8);
        return 0;
      }
      props_setErrorAndReturn(param_1,8);
      return 0;
    }
    iVar1 = iVar1 + 1;
    *pfVar3 = (float)(size_t)local_20;
    pfVar3 = pfVar3 + 1;
  } while (iVar1 < 4);
  iVar1 = cast_getVectorData(param_1,local_18);
  props_normalizeType(param_1,3,iVar1);
  return 0;
}



// ============================================================
// Function: cast_invokeXtraMethod (FUN_680279f0)
// Address: 680279f0
// Size: 507 bytes
// Params: uint param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cast_invokeXtraMethod(uint param_1,undefined4 param_2,int param_3)
{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_78;
  undefined4 local_74;
  int local_70;
  undefined4 local_6c;
  int local_68;
  int local_64;
  undefined1 *local_60;
  int local_5c;
  int local_58;
  undefined4 local_54;
  int local_50 [2];
  undefined1 local_48 [64];
  uint local_8;
  
  local_50[1] = 1;
  local_54 = 4;
  local_50[0] = 0;
  iVar1 = Ordinal_1114(param_2);
  local_58 = iVar1;
  if (iVar1 != 0) {
    if (param_3 == 0xe3) {
      score_resolveType(param_1);
      goto LAB_68027bcc;
    }
    local_64 = props_getInt(param_1);
    if (local_64 < 9) {
      local_60 = local_48;
      iVar3 = 1;
      local_5c = 0;
      if (0 < local_64) {
        do {
          _DAT_68197764 =
               (int *)(**(int **)(param_1 + 0x10) + -8 + (iVar3 - *(int *)(param_1 + 0x20)) * 8 +
                      *(int *)(param_1 + 0x18));
          iVar1 = DAT_6819776c;
          iVar4 = DAT_68197768;
          if (_DAT_68197764 != (int *)0x0) {
            DAT_6819776c = 0;
            DAT_68197768 = 0;
            iVar1 = ((int *)(size_t)_DAT_68197764)[1];
            iVar4 = *(int *)(size_t)_DAT_68197764;
          }
          local_50[iVar3 * 2] = iVar4;
          *(int *)(local_48 + iVar3 * 8 + -4) = iVar1;
          iVar3 = iVar3 + 1;
        } while (iVar3 <= local_64);
        goto LAB_68027aab;
      }
    }
    else {
      local_5c = cast_allocHandle(local_64 * 8,0);
      if (local_5c == 0) {
        local_60 = (undefined1 *)0x0;
        local_50[1] = 0;
        goto LAB_68027bcc;
      }
      local_60 = (undefined1 *)Ordinal_1114(local_5c);
      iVar1 = 1;
      if (0 < local_64) {
        do {
          _DAT_68197764 =
               (int *)(**(int **)(param_1 + 0x10) + -8 + (iVar1 - *(int *)(param_1 + 0x20)) * 8 +
                      *(int *)(param_1 + 0x18));
          iVar3 = DAT_6819776c;
          iVar4 = DAT_68197768;
          if (_DAT_68197764 != (int *)0x0) {
            DAT_6819776c = 0;
            DAT_68197768 = 0;
            iVar3 = ((int *)(size_t)_DAT_68197764)[1];
            iVar4 = *(int *)(size_t)_DAT_68197764;
          }
          *(int *)(local_60 + iVar1 * 8 + -8) = iVar4;
          *(int *)(local_60 + iVar1 * 8 + -4) = iVar3;
          iVar1 = iVar1 + 1;
        } while (iVar1 <= local_64);
      }
LAB_68027aab:
      iVar1 = local_58;
      if (local_60 == (undefined1 *)0x0) goto LAB_68027ba5;
    }
    local_70 = param_3;
    local_78 = 0;
    local_74 = 0;
    local_6c = local_54;
    local_68 = local_50[0];
    iVar1 = media_invokeXtraHandler(*(int **)(iVar1 + 0x10),(int)&local_78);
    if (iVar1 == 0) {
      local_54 = local_6c;
      local_50[0] = local_68;
    }
    else {
      uVar2 = props_translateError(iVar1);
      local_50[0] = (int)(short)uVar2;
    }
    if (local_5c != 0) {
      cast_freeHandle(local_5c);
    }
    if (iVar1 == 0) {
      props_popArgs(param_1,&local_54);
      if (-1 < *(int *)(local_58 + 0x14)) {
        sprites_clearCallbackState(param_1,*(int *)(local_58 + 0x14));
      }
      goto LAB_68027bcc;
    }
    if (iVar1 != -0x7ffbf821) goto LAB_68027bcc;
    local_50[0] = 0x1c;
  }
LAB_68027ba5:
  local_50[1] = 0;
LAB_68027bcc:
  Ordinal_1115(param_2);
  return 0;
}



// ============================================================
// Function: cast_releaseXtraProperty (FUN_68027bf0)
// Address: 68027bf0
// Size: 56 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_releaseXtraProperty(int param_1,undefined4 param_2)
{
  int iVar1;
  
  iVar1 = Ordinal_1114(param_2);
  if (iVar1 != 0) {
    mediaPlayback_releaseObject(*(int **)(iVar1 + 0x10));
    Ordinal_1115(param_2);
    Ordinal_1113(&param_2);
    *(int *)(param_1 + 0xf8) = *(int *)(param_1 + 0xf8) + -1;
  }
  return 0;
}



// ============================================================
// Function: cast_formatXtraError (FUN_68027c30)
// Address: 68027c30
// Size: 104 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_formatXtraError(undefined4 param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  undefined1 local_6c [100];
  uint local_8;
  
  cast_loadPascalString(&DAT_68197780,0x898,0x4f);
  props_getSymbolString(*(int *)(*param_2 + 8),(int)local_6c,100);
  props_formatString(param_1,param_3,param_4,&DAT_68197781);
  return 0;
}



// ============================================================
// Function: cast_getSetXtraField (FUN_68027ca0)
// Address: 68027ca0
// Size: 254 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getSetXtraField(int param_1,int *param_2,int param_3,int param_4,uint *param_5)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  undefined4 local_8;
  
  local_8 = 1;
  iVar4 = 0;
  iVar1 = Ordinal_1114(param_2);
  if (iVar1 == 0) {
    return 0;
  }
  if (param_4 == 0x1a1) {
    if (param_3 == 0) {
      iVar4 = props_storeIntValue(param_1,*(undefined4 *)(*param_2 + 0xc),param_5);
    }
    else {
      iVar4 = props_coerceAndReturnInt(param_1,param_5,(int *)(*param_2 + 0xc));
    }
    if (iVar4 != 0) {
LAB_68027d57:
      props_setError(param_1,0x13);
LAB_68027d5f:
      if (iVar4 != 0) {
        uVar2 = props_translateError(iVar4);
        iVar3 = (int)(short)uVar2;
        goto LAB_68027d6b;
      }
    }
  }
  else if (param_4 == 0x63d) {
    if (param_3 == 0) {
      iVar4 = props_storeObjectRef(param_1,*(int *)(*param_2 + 8),param_5);
      if (iVar4 == 0) goto LAB_68027d89;
      goto LAB_68027d57;
    }
    iVar3 = 0x39;
LAB_68027d6b:
    props_setError(param_1,iVar3);
  }
  else {
    iVar4 = media_dispatchXtraVtable(*(int **)(iVar1 + 0x10),param_4,param_3,param_5);
    if (iVar4 != -0x7ffbf82b) goto LAB_68027d5f;
    local_8 = 0;
  }
  if (((param_3 != 0) && (-1 < *(int *)(iVar1 + 0x14))) && (iVar4 == 0)) {
    sprites_clearCallbackState(param_1,*(int *)(iVar1 + 0x14));
  }
LAB_68027d89:
  Ordinal_1115(param_2);
  return local_8;
}



// ============================================================
// Function: cast_hasXtraProperty (FUN_68027db0)
// Address: 68027db0
// Size: 35 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool cast_hasXtraProperty(undefined4 param_1,undefined4 *param_2)

{
  int iVar1;
  
  iVar1 = (*(code *)**(undefined4 **)*param_2)(param_1,param_2);
  return iVar1 == 0x63a;
}



// ============================================================
// Function: cast_allocXtraProperty (FUN_68027de0)
// Address: 68027de0
// Size: 30 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_allocXtraProperty(void)
{
  undefined4 *puVar1;
  int *piVar2;
  
  piVar2 = (int *)cast_allocHandle(0x18,1);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  puVar1 = (undefined4 *)*piVar2;
  *puVar1 = &PTR_LAB_6818ba88;
  puVar1[1] = 1;
  return 0;
}



// ============================================================
// Function: cast_createXtraProperty (FUN_68027e00)
// Address: 68027e00
// Size: 121 bytes
// Params: int param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * cast_createXtraProperty(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 uVar4;
  
  piVar2 = (int *)cast_allocXtraProperty();
  if (piVar2 == (int *)0x0) {
    props_setError(param_1,2);
    return (int *)0x0;
  }
  iVar1 = *piVar2;
  iVar3 = media_createXtraPlugin(param_1,param_2,(undefined4 *)(iVar1 + 0x10),(undefined4 *)0x0,param_4);
  if (iVar3 != 0) {
    uVar4 = props_translateError(iVar3);
    props_setError(param_1,(int)(short)uVar4);
    cast_releaseXtraProperty(param_1,piVar2);
    return (int *)0x0;
  }
  *(undefined4 *)(iVar1 + 0x14) = param_4;
  *(int *)(iVar1 + 8) = param_2;
  *(undefined4 *)(iVar1 + 0xc) = param_3;
  return piVar2;
}



// ============================================================
// Function: cast_applyXtraProplist (FUN_68027e80)
// Address: 68027e80
// Size: 174 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_applyXtraProplist(int *param_1)

{
  int *in_EAX;
  undefined4 uVar1;
  int iVar2;
  int unaff_ESI;
  int iVar3;
  uint local_1c;
  int *local_18;
  uint local_14;
  int *local_10;
  int local_c;
  int local_8;
  
  local_8 = *in_EAX;
  iVar3 = 0;
  if (local_8 == 0) {
    return 0;
  }
  local_c = props_getListLength(unaff_ESI,param_1);
  if (0 < local_c) {
    iVar2 = 0;
    while( true ) {
      score_setProplistValue(unaff_ESI,param_1,iVar2,&local_14,&local_1c);
      iVar3 = media_dispatchXtraVtable(*(int **)(local_8 + 0x10),local_10,1,&local_1c);
      props_releaseValue(unaff_ESI,(byte)local_14,local_10);
      props_releaseValue(unaff_ESI,(byte)local_1c,local_18);
      if (iVar3 != 0) break;
      iVar2 = iVar2 + 1;
      if (local_c <= iVar2) {
        return 0;
      }
    }
    uVar1 = props_translateError(iVar3);
    props_setError(unaff_ESI,(int)(short)uVar1);
  }
  return iVar3;
}



// ============================================================
// Function: cast_setXtraTransform (FUN_68027f30)
// Address: 68027f30
// Size: 121 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_setXtraTransform(int param_1,int *param_2,undefined4 param_3,undefined4 *param_4)
{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  if (*(int *)(*param_2 + 0xc) != 0) {
    local_18 = *param_4;
    local_1c = 0x3f800000;
    local_14 = param_4[1];
    local_10 = param_4[2];
    local_c = param_4[3];
    iVar1 = media_callXtraWithInstance(*(int **)(*param_2 + 0x10),param_3,&local_1c);
    if (iVar1 != 0) {
      uVar2 = props_translateError(iVar1);
      props_setError(param_1,(int)(short)uVar2);
    }
  }
  return 0;
}



// ============================================================
// Function: cast_findXtraPropertyRef (FUN_68027fb0)
// Address: 68027fb0
// Size: 90 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_findXtraPropertyRef(undefined4 param_1,int *param_2,int param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  int local_c;
  int *local_8;
  
  iVar2 = props_getListLength(param_1,param_2);
  if ((-1 < param_3) && (param_3 <= iVar2)) {
    props_getListEntryRaw(param_1,param_2,param_3,&local_c);
    if (local_c == 3) {
      bVar1 = cast_hasXtraProperty(param_1,local_8);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        return *local_8 + 8;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: cast_setXtraModifiedFlag (FUN_68028010)
// Address: 68028010
// Size: 38 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_setXtraModifiedFlag(undefined4 param_1,int *param_2,undefined4 param_3)
{
  bool bVar1;
  undefined3 extraout_var;
  
  if (param_2 != (int *)0x0) {
    bVar1 = cast_hasXtraProperty(param_1,param_2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      *(undefined4 *)(*param_2 + 0x14) = param_3;
    }
  }
  return 0;
}



// ============================================================
// Function: cast_cloneXtraProperty (FUN_68028040)
// Address: 68028040
// Size: 91 bytes
// Params: int param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * cast_cloneXtraProperty(int param_1,int *param_2)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  
  if (param_2 != (int *)0x0) {
    bVar1 = cast_hasXtraProperty(param_1,param_2);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      piVar2 = cast_createXtraProperty(param_1,*(int *)(*param_2 + 8),1,0xffffffff);
      if (piVar2 != (int *)0x0) {
        *(undefined4 *)(*piVar2 + 0xc) = *(undefined4 *)(*param_2 + 0xc);
        media_copyXtraCallback(*(int **)(*param_2 + 0x10),*(int **)(*piVar2 + 0x10));
        return piVar2;
      }
    }
  }
  return (int *)0x0;
}



// ============================================================
// Function: cast_newXtraInstance (FUN_680280a0)
// Address: 680280a0
// Size: 334 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int cast_newXtraInstance(int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_c;
  int *local_8;
  
  iVar1 = param_1;
  iVar2 = props_getInt(param_1);
  if ((iVar2 == 1) || (iVar2 == 2)) {
    _DAT_68197764 =
         (int *)(**(int **)(iVar1 + 0x10) + *(int *)(iVar1 + 0x20) * -8 + *(int *)(iVar1 + 0x18));
    local_8 = DAT_6819776c;
    local_c = DAT_68197768;
    if (_DAT_68197764 != (int *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_8 = (int *)((int *)(size_t)_DAT_68197764)[1];
      local_c = *(int *)(size_t)_DAT_68197764;
    }
    iVar3 = props_requireSymbolId(iVar1,&local_c,&param_1);
    if (iVar3 == 0) {
      iVar2 = 0xb;
    }
    else {
      if (iVar2 == 1) {
        piVar4 = cast_createXtraProperty(iVar1,param_1,1,0xffffffff);
LAB_68028136:
        props_normalizeType(iVar1,3,(int)piVar4);
        return 0;
      }
      piVar4 = cast_createXtraProperty(iVar1,param_1,1,0xffffffff);
      if (piVar4 != (int *)0x0) {
        _DAT_68197764 =
             (int *)(**(int **)(iVar1 + 0x10) + *(int *)(iVar1 + 0x20) * -8 + 8 +
                    *(int *)(iVar1 + 0x18));
        local_8 = DAT_6819776c;
        local_c = DAT_68197768;
        if (_DAT_68197764 != (int *)0x0) {
          DAT_6819776c = (int *)0x0;
          DAT_68197768 = 0;
          local_8 = (int *)((int *)(size_t)_DAT_68197764)[1];
          local_c = *(int *)(size_t)_DAT_68197764;
        }
        iVar2 = score_getProplistValue(iVar1,&local_c);
        if (iVar2 != 0) {
          iVar2 = cast_applyXtraProplist(local_8);
          if (iVar2 != 0) {
            cast_releaseXtraProperty(iVar1,piVar4);
            return 0;
          }
          goto LAB_68028136;
        }
        cast_releaseXtraProperty(iVar1,piVar4);
      }
      iVar2 = 0x13;
    }
  }
  else {
    iVar2 = 0x19;
  }
  props_setError(iVar1,iVar2);
  props_popArgs(iVar1,&local_c);
  return 0;
}



// ============================================================
// Function: cast_getXtraProperty (FUN_680281f0)
// Address: 680281f0
// Size: 52 bytes
// Params: int param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getXtraProperty(int param_1,uint *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = core_setFieldValue(param_1,(int *)param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = props_returnWithValue(param_1,0x80040bb8,param_2);
    return uVar2;
  }
  return 0;
}



// ============================================================
// Function: cast_setXtraPropertyEx (FUN_68028230)
// Address: 68028230
// Size: 52 bytes
// Params: int param_1, uint * param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_setXtraPropertyEx(int param_1,uint *param_2,undefined2 *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = crt_extractChannelRef(param_1,(int *)param_2,param_3);
  if (iVar1 == 0) {
    uVar2 = props_returnWithValue(param_1,0x80040bcb,param_2);
    return uVar2;
  }
  return 0;
}



