// Module: cast
// Topic: Symbol and generic type system management
// Address range: 0x6802B390 - 0x6802C040
// Functions (33):
//   cast_loadSymbolResource (FUN_6802b390)
//   cast_createSymbolObject (FUN_6802b3e0)
//   cast_getSymbolCount (FUN_6802b430)
//   cast_resolveSymbolType (FUN_6802b450)
//   cast_setSymbolProperty (FUN_6802b520)
//   cast_dispatchSymbolAccess (FUN_6802b660)
//   cast_createSymbolFromXtra (FUN_6802b850)
//   cast_registerDynamicSymbol (FUN_6802b8f0)
//   cast_getSymbolProperty (FUN_6802ba30)
//   cast_releaseSymbolObject (FUN_6802bba0)
//   cast_getSymbolPropertyEx (FUN_6802bbd0)
//   cast_setSymbolPropertyEx (FUN_6802bc30)
//   cast_getSymbolRuntimeProperty (FUN_6802bc70)
//   cast_getSymbolTypeId (FUN_6802bc90)
//   cast_getGenericTypeId (FUN_6802bcb0)
//   cast_resolveSymbolTypeEx (FUN_6802bcd0)
//   cast_getSymbolParamInfo (FUN_6802bcf0)
//   cast_validateSymbolAccess (FUN_6802bd40)
//   cast_setSymbolBounds (FUN_6802bd60)
//   cast_loadGenericResource (FUN_6802bda0)
//   cast_createGenericObject (FUN_6802bde0)
//   cast_callGenericMethod (FUN_6802be30)
//   cast_getGenericItemCount (FUN_6802be90)
//   cast_accessGenericData (FUN_6802bec0)
//   cast_getGenericId (FUN_6802bf00)
//   cast_getGenericNext (FUN_6802bf20)
//   cast_getGenericStart (FUN_6802bf40)
//   cast_getGenericEnd (FUN_6802bf60)
//   cast_dispatchGenericSystemOp (FUN_6802bf80)
//   cast_resolveGenericMember85 (FUN_6802bfb0)
//   cast_resolveGenericMember1cf (FUN_6802bfe0)
//   cast_resolveGenericMember1d0 (FUN_6802c010)
//   cast_resolveGenericMember12b (FUN_6802c040)

// ============================================================
// Function: cast_loadSymbolResource (FUN_6802b390)
// Address: 6802b390
// Size: 72 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_loadSymbolResource(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;

  iVar2 = xtra_getPlatformData(param_1);
  puVar1 = *(undefined4 **)(**(int **)(iVar2 + 8) + 0x5a8);
  uVar3 = xtra_getPlatformFlags(param_1);
  iVar2 = xtra_loadResource(param_1,&PTR_s__symbol_6818bd08,puVar1,uVar3);
  if (iVar2 != 0) {
    xtra_getResourceById(param_1,iVar2,param_2 * 2);
  }
  return iVar2;
}



// ============================================================
// Function: cast_createSymbolObject (FUN_6802b3e0)
// Address: 6802b3e0
// Size: 70 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_createSymbolObject(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;

  iVar1 = xtra_getPlatformData(param_1);
  piVar2 = xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_s__symbol_6818bd08,0x6802a150,1,
                        (int *)0x0,(int *)&PTR_DAT_6818bcd8,(int *)0x0,(int *)0x0);
  *(int **)(**(int **)(iVar1 + 8) + 0x5a8) = piVar2;
  return 0;
}



// ============================================================
// Function: cast_getSymbolCount (FUN_6802b430)
// Address: 6802b430
// Size: 31 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getSymbolCount(int param_1)

{
  int iVar1;
  int *in_stack_00000014;

  iVar1 = cast_loadSymbolResource(param_1,0x8c);
  *in_stack_00000014 = iVar1;
  return 1;
}



// ============================================================
// Function: cast_resolveSymbolType (FUN_6802b450)
// Address: 6802b450
// Size: 206 bytes
// Params: int param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_resolveSymbolType(int param_1,uint *param_2)

{
  char cVar1;
  uint in_EAX;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  uint *puVar5;
  uint unaff_EBX;
  uint local_c;
  int *local_8;

  iVar2 = xtra_getPlatformData(unaff_EBX);
  if (param_1 == 3) {
    local_8 = (int *)xtra_getObjectTag(unaff_EBX,in_EAX);
    if (local_8 != (int *)0x0) {
      local_c = 3;
      props_retainValue(iVar2,&local_c);
      props_getStringLength(iVar2,(int *)&local_c);
      if ((local_c == 0x40) || (local_c == 0x43)) {
        props_getStringData((int *)&local_c,(int *)0x0);
        pcVar3 = (char *)runtime_strlen("<%s>");
        props_unlockString((int *)&local_c);
        props_releaseValue(iVar2,(byte)local_c,local_8);
        if (pcVar3 != (char *)0x0) {
          pcVar4 = pcVar3;
          do {
            cVar1 = *pcVar4;
            pcVar4 = pcVar4 + 1;
          } while (cVar1 != '\0');
          puVar5 = xtra_getScriptContextEx(unaff_EBX,(int)pcVar3,(int)pcVar4 - (int)(pcVar3 + 1));
          if (puVar5 != (uint *)0x0) {
            in_EAX = (uint)puVar5 | 4;
            goto LAB_6802b50c;
          }
          xtra_checkAndFlush(unaff_EBX,(int)pcVar3);
        }
        return 0;
      }
    }
  }
LAB_6802b50c:
  *param_2 = in_EAX;
  return 1;
}



// ============================================================
// Function: cast_setSymbolProperty (FUN_6802b520)
// Address: 6802b520
// Size: 310 bytes
// Params: uint param_1, int param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_setSymbolProperty(uint param_1,int param_2,uint param_3,uint *param_4)

{
  uint *puVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  uint local_c;
  int *local_8;

  piVar3 = (int *)xtra_getPlatformData(param_1);
  puVar4 = (undefined4 *)xtra_getObjectTag(param_1,param_2);
  if (puVar4 == (undefined4 *)0x0) {
    return 0;
  }
  iVar5 = cast_getScoreXtraValue(piVar3,param_1,param_3,(undefined4 *)0x0);
  if (iVar5 < 0) {
    props_pushValue((int)piVar3);
    puVar1 = (uint *)(piVar3 + 7);
    *puVar1 = 3;
    piVar3[8] = (int)puVar4;
    props_retainValue(piVar3,puVar1);
    props_pushValue((int)piVar3);
    bVar2 = cast_dispatchScoreXtra((int)piVar3,param_1,param_3,puVar1);
    if (CONCAT31(extraout_var,bVar2) == 0) {
      return 0;
    }
    props_pushValue((int)piVar3);
    bVar2 = cast_dispatchScoreXtra((int)piVar3,param_1,*param_4,puVar1);
    if (CONCAT31(extraout_var_00,bVar2) == 0) {
      return 0;
    }
    param_3 = cast_invokeXtraMethodEx(piVar3,param_1,puVar4,0xda,3,(int *)0x0);
  }
  else {
    local_c = 0;
    bVar2 = cast_dispatchScoreXtra((int)piVar3,param_1,*param_4,&local_c);
    if (CONCAT31(extraout_var_01,bVar2) == 0) {
      return 0;
    }
    param_3 = (**(code **)(*(int *)*puVar4 + 0x18))(piVar3,puVar4,1,iVar5,&local_c);
    if (param_3 == 0) {
      if (piVar3[0x1f] == 0) {
        props_reportError((int)piVar3,0x37);
      }
      core_getScriptState(param_1);
    }
    else if (piVar3[0x1f] != 0) {
      core_getScriptState(param_1);
      param_3 = 0;
    }
    props_releaseValue(piVar3,(byte)local_c,local_8);
  }
  if (param_3 == 0) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: cast_dispatchSymbolAccess (FUN_6802b660)
// Address: 6802b660
// Size: 379 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_dispatchSymbolAccess(uint param_1,undefined4 param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  int iVar5;
  undefined3 extraout_var;
  uint uVar6;
  byte local_10 [4];
  int *local_c;
  uint local_8;

  uVar1 = param_1;
  piVar3 = (int *)xtra_getPlatformData(param_1);
  local_8 = 0;
  param_1 = cast_resolveXtraPropertyId(piVar3,param_1,param_4[-2]);
  if (param_1 != 0xffffffff) {
    if ((int)param_1 < 0x616) {
      if (param_1 == 0x615) {
        param_1 = 0x82;
      }
      else {
        switch(param_1) {
        case 0x81:
        case 0xd4:
        case 0xdb:
        case 0xdd:
          local_8 = 1;
        }
      }
    }
    else if (param_1 == 0x616) {
      param_1 = 0x102;
    }
    else if ((param_1 == 0x617) || (param_1 == 0x620)) {
      cast_resolveSymbolType(3,param_5);
      return 1;
    }
    if (((param_4[-1] & 0xfffffff8) != 0) &&
       (puVar4 = (undefined4 *)xtra_getObjectTag(uVar1,param_4[-1] & 0xfffffff8),
       puVar4 != (undefined4 *)0x0)) {
      props_pushValue((int)piVar3);
      piVar3[7] = 3;
      piVar3[8] = (int)puVar4;
      props_retainValue(piVar3,(uint *)(piVar3 + 7));
      uVar6 = 0;
      if (param_3 != 0) {
        do {
          props_pushValue((int)piVar3);
          if (((uVar6 == 0) && (local_8 != 0)) &&
             (local_8 = uVar6, iVar5 = cast_getScoreXtraValue(piVar3,uVar1,*param_4,(undefined4 *)0x0),
             iVar5 != -1)) {
            piVar3[7] = 8;
            piVar3[8] = iVar5;
          }
          else {
            bVar2 = cast_dispatchScoreXtra((int)piVar3,uVar1,param_4[uVar6],(uint *)(piVar3 + 7));
            if (CONCAT31(extraout_var,bVar2) == 0) {
              return 0;
            }
          }
          uVar6 = uVar6 + 1;
        } while (uVar6 < param_3);
      }
      iVar5 = cast_invokeXtraMethodEx(piVar3,uVar1,puVar4,param_1 & 0x7fffffff,param_3 + 1,(int *)local_10);
      if (iVar5 != 0) {
        iVar5 = cast_readScoreXtraData((uint)piVar3,uVar1,(uint *)local_10,param_5);
        props_releaseValue(piVar3,local_10[0],local_c);
        if (iVar5 != 0) {
          return 1;
        }
      }
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: cast_createSymbolFromXtra (FUN_6802b850)
// Address: 6802b850
// Size: 157 bytes
// Params: undefined4 param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_createSymbolFromXtra(undefined4 param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int unaff_ESI;
  int unaff_EDI;
  char *pcVar4;
  undefined1 local_408;
  char local_407 [1023];
  uint local_8;

  if (((unaff_ESI == 0x617) || (unaff_ESI == 0x620)) ||
     (iVar1 = (**(code **)(*(int *)*param_3 + 0x48))(param_1,param_3), iVar1 != 0)) {
    score_lookupSymbol(DAT_68196304,unaff_ESI,(int)&local_408);
    pcVar4 = local_407;
    uVar2 = xtra_getPlatformFlags(unaff_EDI);
    iVar1 = cast_registerXtraSymbol(unaff_EDI,0x6802b660,0,0,uVar2,pcVar4,unaff_ESI);
    if (iVar1 != 0) {
      uVar3 = xtra_getScriptContext(iVar1);
      *param_2 = uVar3;
    }
  }
  return 0;
}



// ============================================================
// Function: cast_registerDynamicSymbol (FUN_6802b8f0)
// Address: 6802b8f0
// Size: 307 bytes
// Params: uint param_1, undefined4 * param_2, int param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_registerDynamicSymbol(uint param_1,undefined4 *param_2,int param_3)
{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int *unaff_EBX;
  int unaff_ESI;
  uint uVar5;
  char *pcVar6;
  undefined1 local_408;
  char local_407 [1023];
  uint local_8;

  props_pushValue(unaff_ESI);
  puVar1 = (uint *)(unaff_ESI + 0x1c);
  *puVar1 = 3;
  *(int **)(unaff_ESI + 0x20) = unaff_EBX;
  props_retainValue(unaff_ESI,puVar1);
  props_pushValue(unaff_ESI);
  *puVar1 = 4;
  *(undefined4 *)(unaff_ESI + 0x20) = 0x80000001;
  iVar2 = (**(code **)(*(int *)*unaff_EBX + 4))();
  if (iVar2 == 0) {
    props_popValue(unaff_ESI);
    props_popValue(unaff_ESI);
    return 0;
  }
  if ((*puVar1 == 4) && (*(int *)(unaff_ESI + 0x20) != 0)) {
    score_lookupSymbol(DAT_68196304,param_1,(int)&local_408);
    uVar5 = param_1 | 0x80000000;
    pcVar6 = local_407;
    uVar3 = xtra_getPlatformFlags(param_3);
    iVar2 = cast_registerXtraSymbol(param_3,0x6802b660,0,0,uVar3,pcVar6,uVar5);
    if (iVar2 != 0) {
      uVar4 = xtra_getScriptContext(iVar2);
      *param_2 = uVar4;
    }
    props_releaseObject(unaff_ESI,unaff_EBX);
  }
  props_popValue(unaff_ESI);
  return 0;
}



// ============================================================
// Function: cast_getSymbolProperty (FUN_6802ba30)
// Address: 6802ba30
// Size: 356 bytes
// Params: uint param_1, int param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getSymbolProperty(uint param_1,int param_2,uint param_3,uint *param_4)

{
  int *piVar1;
  bool bVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined3 extraout_var;
  uint local_10;
  int *local_c;
  int *local_8;

  piVar3 = (int *)xtra_getPlatformData(param_1);
  local_8 = piVar3;
  puVar4 = (undefined4 *)xtra_getObjectTag(param_1,param_2);
  if (puVar4 == (undefined4 *)0x0) {
    return 0;
  }
  uVar5 = cast_getScoreXtraValue(piVar3,param_1,param_3,(undefined4 *)0x0);
  if (((int)uVar5 < 0) ||
     ((uVar5 != 0xdd &&
      (iVar6 = (**(code **)(*(int *)*puVar4 + 0x48))(piVar3,puVar4,0xffffffff), iVar6 == 0)))) {
    props_pushValue((int)piVar3);
    piVar3[7] = 3;
    piVar3[8] = (int)puVar4;
    props_retainValue(piVar3,(uint *)(piVar3 + 7));
    props_pushValue((int)piVar3);
    bVar2 = cast_dispatchScoreXtra((int)piVar3,param_1,param_3,(uint *)(piVar3 + 7));
    if (CONCAT31(extraout_var,bVar2) == 0) {
      return 0;
    }
    iVar6 = cast_invokeXtraMethodEx(piVar3,param_1,puVar4,0xd3,2,(int *)&local_10);
    if (iVar6 == 0) {
      return 0;
    }
  }
  else {
    local_10 = 4;
    local_c = (int *)0x0;
    iVar6 = (**(code **)(*(int *)*puVar4 + 0x18))(piVar3,puVar4,0,uVar5,&local_10);
    if ((iVar6 == 0) || (piVar3[0x1f] != 0)) {
      piVar3[0x1f] = 0;
      piVar3[0x1d] = 0;
      iVar6 = cast_createSymbolFromXtra(piVar3,param_4,puVar4);
      if (iVar6 != 0) {
        return 1;
      }
      return 0;
    }
    if (((local_10 == 3) &&
        (iVar6 = (*(code *)**(undefined4 **)*local_c)(piVar3,local_c), piVar1 = local_8,
        iVar6 == 0x635)) &&
       (iVar6 = cast_registerDynamicSymbol(uVar5,param_4,param_1), piVar3 = piVar1, iVar6 != 0)) {
      return 1;
    }
  }
  cast_readScoreXtraData((uint)piVar3,param_1,&local_10,param_4);
  props_releaseValue(piVar3,(byte)local_10,local_c);
  return 1;
}



// ============================================================
// Function: cast_releaseSymbolObject (FUN_6802bba0)
// Address: 6802bba0
// Size: 43 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_releaseSymbolObject(int param_1,int param_2)
{
  undefined4 uVar1;
  int *piVar2;

  uVar1 = xtra_getPlatformData(param_1);
  piVar2 = (int *)xtra_getObjectTag(param_1,param_2);
  if (piVar2 != (int *)0x0) {
    props_releaseObject(uVar1,piVar2);
  }
  return 0;
}



// ============================================================
// Function: cast_getSymbolPropertyEx (FUN_6802bbd0)
// Address: 6802bbd0
// Size: 89 bytes
// Params: uint param_1, int param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getSymbolPropertyEx(uint param_1,int param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  uint local_8;

  local_8 = 0x80000001;
  xtra_getResourceDataEx(param_1,param_3,&local_8);
  if (param_3 == *(uint *)(*(int *)(param_1 + 0x14) + 0xec)) {
    *param_4 = 0x80000001;
    return 1;
  }
  uVar1 = cast_getSymbolProperty(param_1,param_2,local_8,param_4);
  return uVar1;
}



// ============================================================
// Function: cast_setSymbolPropertyEx (FUN_6802bc30)
// Address: 6802bc30
// Size: 54 bytes
// Params: uint param_1, int param_2, uint param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_setSymbolPropertyEx(uint param_1,int param_2,uint param_3,uint *param_4)
{
  uint local_8;

  local_8 = 0x80000001;
  xtra_getResourceDataEx(param_1,param_3,&local_8);
  cast_setSymbolProperty(param_1,param_2,local_8,param_4);
  return 0;
}



// ============================================================
// Function: cast_getSymbolRuntimeProperty (FUN_6802bc70)
// Address: 6802bc70
// Size: 9 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_getSymbolRuntimeProperty(uint param_1,int *param_2,uint param_3,undefined4 *param_4,uint *param_5)
{
  runtime_getProperty(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_getSymbolTypeId (FUN_6802bc90)
// Address: 6802bc90
// Size: 21 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getSymbolTypeId(void)

{
  undefined4 *in_stack_00000014;

  *in_stack_00000014 = 5;
  return 1;
}



// ============================================================
// Function: cast_getGenericTypeId (FUN_6802bcb0)
// Address: 6802bcb0
// Size: 21 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getGenericTypeId(void)

{
  undefined4 *in_stack_00000010;

  *in_stack_00000010 = 6;
  return 1;
}



// ============================================================
// Function: cast_resolveSymbolTypeEx (FUN_6802bcd0)
// Address: 6802bcd0
// Size: 28 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveSymbolTypeEx(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4)
{
  cast_resolveSymbolType(param_3,param_4);
  return 0;
}



// ============================================================
// Function: cast_getSymbolParamInfo (FUN_6802bcf0)
// Address: 6802bcf0
// Size: 72 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, undefined4 * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
cast_getSymbolParamInfo(undefined4 param_1,undefined4 param_2,int param_3,undefined4 *param_4,
            undefined4 *param_5)

{
  if (param_3 == 0) {
    *param_4 = 0;
    if (param_5 != (undefined4 *)0x0) {
      *param_5 = 1;
    }
    return 1;
  }
  if ((0 < param_3) && (param_3 < 3)) {
    *param_4 = 0;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: cast_validateSymbolAccess (FUN_6802bd40)
// Address: 6802bd40
// Size: 29 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_validateSymbolAccess(void)

{
  int in_stack_00000010;

  if ((in_stack_00000010 != 2) && (in_stack_00000010 != 3)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: cast_setSymbolBounds (FUN_6802bd60)
// Address: 6802bd60
// Size: 44 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_setSymbolBounds(int param_1,undefined4 param_2,undefined4 param_3)
{
  undefined4 *puVar1;

  puVar1 = (undefined4 *)xtra_getPropertyById(param_1,0x10);
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = param_2;
    puVar1[1] = param_3;
    puVar1[2] = 4;
    puVar1[3] = 4;
  }
  return 0;
}



// ============================================================
// Function: cast_loadGenericResource (FUN_6802bda0)
// Address: 6802bda0
// Size: 50 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_loadGenericResource(int param_1)
{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;

  iVar2 = xtra_getPlatformData(param_1);
  puVar1 = *(undefined4 **)(**(int **)(iVar2 + 8) + 0x5a4);
  uVar3 = xtra_getPlatformFlags(param_1);
  xtra_loadResource(param_1,&PTR_s__generic_6818bdb0,puVar1,uVar3);
  return 0;
}



// ============================================================
// Function: cast_createGenericObject (FUN_6802bde0)
// Address: 6802bde0
// Size: 67 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_createGenericObject(int param_1,int *param_2)

{
  int iVar1;
  int *piVar2;

  iVar1 = xtra_getPlatformData(param_1);
  piVar2 = xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_s__generic_6818bdb0,0x6802a150,1,
                        (int *)0x0,(int *)0x0,(int *)0x0,(int *)0x0);
  *(int **)(**(int **)(iVar1 + 8) + 0x5a4) = piVar2;
  return 0;
}



// ============================================================
// Function: cast_callGenericMethod (FUN_6802be30)
// Address: 6802be30
// Size: 84 bytes
// Params: int param_1, undefined4 param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_callGenericMethod(int param_1,undefined4 param_2,int param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;

  if (((param_3 != 0) && (uVar1 = *param_4, (uVar1 & 1) != 0)) && (uVar1 != 0x80000001)) {
    iVar2 = xtra_setPlatformRef(param_1,(int)uVar1 >> 1);
    *param_5 = iVar2 * 2 | 1;
    return 1;
  }
  iVar2 = xtraRuntime_getPlatformRef(param_1);
  *param_5 = iVar2 * 2 | 1;
  return 1;
}



// ============================================================
// Function: cast_getGenericItemCount (FUN_6802be90)
// Address: 6802be90
// Size: 47 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getGenericItemCount(int param_1)

{
  int iVar1;
  uint *in_stack_00000014;

  iVar1 = *(int *)(*(int *)(param_1 + 0x14) + 0x4c);
  xtra_getPlatformSize(param_1);
  *in_stack_00000014 = (iVar1 - *(int *)(*(int *)(param_1 + 0x14) + 0x4c)) * 2 | 1;
  return 1;
}



// ============================================================
// Function: cast_accessGenericData (FUN_6802bec0)
// Address: 6802bec0
// Size: 50 bytes
// Params: int param_1, undefined4 param_2, int param_3, int * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_accessGenericData(int param_1,undefined4 param_2,int param_3,int *param_4,uint *param_5)

{
  *param_5 = *(int *)(*(int *)(param_1 + 0x14) + 0x54) * 2 | 1;
  if (param_3 != 0) {
    *(int *)(*(int *)(param_1 + 0x14) + 0x54) = *param_4 >> 1;
  }
  return 1;
}



// ============================================================
// Function: cast_getGenericId (FUN_6802bf00)
// Address: 6802bf00
// Size: 31 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getGenericId(int param_1)

{
  uint *in_stack_00000014;

  *in_stack_00000014 = *(int *)(*(int *)(param_1 + 0x14) + 0x68) * 2 | 1;
  return 1;
}



// ============================================================
// Function: cast_getGenericNext (FUN_6802bf20)
// Address: 6802bf20
// Size: 31 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getGenericNext(int param_1)

{
  uint *in_stack_00000014;

  *in_stack_00000014 = *(int *)(*(int *)(param_1 + 0x14) + 0x4c) * 2 | 1;
  return 1;
}



// ============================================================
// Function: cast_getGenericStart (FUN_6802bf40)
// Address: 6802bf40
// Size: 31 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getGenericStart(int param_1)

{
  uint *in_stack_00000014;

  *in_stack_00000014 = *(int *)(*(int *)(param_1 + 0x14) + 0x50) * 2 | 1;
  return 1;
}



// ============================================================
// Function: cast_getGenericEnd (FUN_6802bf60)
// Address: 6802bf60
// Size: 31 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_getGenericEnd(int param_1)

{
  uint *in_stack_00000014;

  *in_stack_00000014 = *(int *)(*(int *)(param_1 + 0x14) + 0x5c) * 2 | 1;
  return 1;
}



// ============================================================
// Function: cast_dispatchGenericSystemOp (FUN_6802bf80)
// Address: 6802bf80
// Size: 33 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_dispatchGenericSystemOp(int param_1,undefined4 param_2,int param_3,undefined4 param_4,uint *param_5)
{
  cast_dispatchScoreOp(param_1,param_3,param_4,param_5,"_system");
  return 0;
}



// ============================================================
// Function: cast_resolveGenericMember85 (FUN_6802bfb0)
// Address: 6802bfb0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveGenericMember85(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x85,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveGenericMember1cf (FUN_6802bfe0)
// Address: 6802bfe0
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveGenericMember1cf(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1cf,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveGenericMember1d0 (FUN_6802c010)
// Address: 6802c010
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveGenericMember1d0(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(0x1d0,param_1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveGenericMember12b (FUN_6802c040)
// Address: 6802c040
// Size: 33 bytes
// Params: uint param_1, undefined4 param_2, uint param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveGenericMember12b(uint param_1,undefined4 param_2,uint param_3,int param_4,uint *param_5)
{
  cast_resolveMember(299,param_1,param_3,param_4,param_5);
  return 0;
}



