// Module: props
// Topic: Extended API helpers: data conversion, points, objects
// Address range: 0x68038db0 - 0x680392d0
// Functions (15):
//   props_getPointFromObject (FUN_68038db0)
//   props_createPointObject (FUN_68038e50)
//   props_validateMediaRef (FUN_68038f10)
//   props_storeMediaRef (FUN_68038f50)
//   props_getValuePair
//   props_readPascalString
//   props_loadCString
//   props_getExtPair
//   props_loadStringValue
//   props_getPointsFromObject (FUN_680390b0)
//   props_createPolygonObject (FUN_68039140)
//   props_appendStringRange (FUN_680391c0)
//   props_getExtValue
//   props_advanceParserOffset (FUN_680392c0)
//   props_dispatchExtMethod



// ============================================================
// Function: props_getPointFromObject (FUN_68038db0)
// Address: 68038db0
// Size: 149 bytes
// Params: int param_1, uint * param_2, double * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_getPointFromObject(int param_1,uint *param_2,double *param_3)

{
  int local_c;
  int iVar1;
  double local_14;
  /* FIXUP(C2040: 'local_c': 'uint): uint local_c [2]; */
  
  ((int *)(size_t)local_c)[ /* FIXUP(C2109): cast to pointer for subscript */0] = 0;
  ((int *)(size_t)local_c)[ /* FIXUP(C2109): cast to pointer for subscript */1] = 0;
  iVar1 = props_callMethodDirect(param_1,param_2,1,(int *)local_c);
  if (iVar1 == 0) {
    iVar1 = props_coerceAndReturnDouble(param_1,local_c,&local_14);
    if (iVar1 == 0) {
      props_releaseAndClear(param_1,(int *)local_c);
      *param_3 = local_14;
      iVar1 = props_callMethodDirect(param_1,param_2,2,(int *)local_c);
      if (iVar1 == 0) {
        iVar1 = props_coerceAndReturnDouble(param_1,local_c,&local_14);
        if (iVar1 == 0) {
          param_3[1] = local_14;
        }
      }
    }
  }
  props_releaseAndClear(param_1,(int *)local_c);
  return iVar1;
}



// ============================================================
// Function: props_createPointObject (FUN_68038e50)
// Address: 68038e50
// Size: 181 bytes
// Params: int param_1, double * param_2, uint * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_createPointObject(int param_1,double *param_2,uint *param_3)

{
  int iVar1;
  int local_c [2];
  
  local_c[0] = 0;
  local_c[1] = 0;
  *param_3 = 0;
  iVar1 = props_getContextRef(param_1,(int *)param_3);
  if (iVar1 == 0) {
    iVar1 = props_storeFloatDirect(param_1,*param_2,local_c);
    if (iVar1 == 0) {
      iVar1 = props_dispatchMethod(param_1,param_3,local_c);
      if (iVar1 == 0) {
        props_releaseAndClear(param_1,local_c);
        iVar1 = props_storeFloatDirect(param_1,param_2[1],local_c);
        if (iVar1 == 0) {
          iVar1 = props_dispatchMethod(param_1,param_3,local_c);
        }
      }
    }
  }
  props_releaseAndClear(param_1,local_c);
  if (iVar1 != 0) {
    props_releaseAndClear(param_1,(int *)param_3);
    return iVar1;
  }
  props_convertToPoint(param_1,(int *)param_3);
  return 0;
}



// ============================================================
// Function: props_validateMediaRef (FUN_68038f10)
// Address: 68038f10
// Size: 60 bytes
// Params: int param_1, uint * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_validateMediaRef(int param_1,uint *param_2,undefined4 *param_3)

{
  uint *puVar1;
  bool bVar2;
  undefined3 extraout_var;
  undefined4 uVar3;
  
  puVar1 = param_2;
  bVar2 = score_isMediaValid(param_1,(int *)param_2,(int *)&param_2);
  if (CONCAT31(extraout_var,bVar2) == 0) {
    uVar3 = props_returnWithValue(param_1,0x80040bb9,puVar1);
    return uVar3;
  }
  *param_3 = param_2;
  return 0;
}



// ============================================================
// Function: props_storeMediaRef (FUN_68038f50)
// Address: 68038f50
// Size: 40 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_storeMediaRef(int param_1,int *param_2,undefined4 *param_3)

{
  param_3[1] = param_2;
  if (param_2 != (int *)0x0) {
    score_getMediaRef(param_1,param_2);
    *param_3 = 3;
  }
  return 0;
}



// ============================================================
// Function: props_getValuePair (FUN_68038f80)
// Address: 68038f80
// Size: 81 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getValuePair(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  undefined4 uVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 != (undefined4 *)0x0) {
    uVar1 = Ordinal_1114(param_2);
    puVar3 = param_2;
    iVar2 = Ordinal_1116(param_2,param_3);
    props_createStringFromData(param_1,uVar1,iVar2 + -1,puVar3);
    Ordinal_1115(param_2);
    cast_freeHandle(param_2);
    return 0;
  }
  *param_3 = 2;
  param_3[1] = 0;
  return 0;
}



// ============================================================
// Function: props_readPascalString (FUN_68038fe0)
// Address: 68038fe0
// Size: 51 bytes
// Params: int param_1, byte * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_readPascalString(int param_1,byte *param_2,undefined4 *param_3)
{
  ushort uVar1;
  
  if (*param_2 == 0xff) {
    uVar1 = Ordinal_1201(param_2 + 1);
  }
  else {
    uVar1 = (ushort)*param_2;
  }
  props_createStringFromData(param_1,param_2 + 1,(int)(short)uVar1,param_3);
  return 0;
}



// ============================================================
// Function: props_loadCString (FUN_68039020)
// Address: 68039020
// Size: 65 bytes
// Params: int param_1, char * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_loadCString(int param_1,char *param_2,undefined4 *param_3)
{
  char cVar1;
  char *pcVar2;
  
  if (param_2 != (char *)0x0) {
    pcVar2 = param_2;
    do {
      cVar1 = *pcVar2;
      pcVar2 = pcVar2 + 1;
    } while (cVar1 != '\0');
    props_createStringFromData(param_1,param_2,(int)pcVar2 - (int)(param_2 + 1),param_3);
    return 0;
  }
  *param_3 = 2;
  param_3[1] = 0;
  return 0;
}



// ============================================================
// Function: props_getExtPair (FUN_68039070)
// Address: 68039070
// Size: 26 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getExtPair(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  props_getValuePair(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_loadStringValue (FUN_68039090)
// Address: 68039090
// Size: 26 bytes
// Params: int param_1, char * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_loadStringValue(int param_1,char *param_2,undefined4 *param_3)

{
  props_loadCString(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: props_getPointsFromObject (FUN_680390b0)
// Address: 680390b0
// Size: 140 bytes
// Params: int param_1, uint * param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_getPointsFromObject(int param_1,uint *param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  uint local_c [2];
  
  iVar1 = 0;
  local_c[0] = 0;
  local_c[1] = 0;
  do {
    iVar1 = iVar1 + 1;
    iVar2 = props_callMethodDirect(param_1,param_2,iVar1,(int *)local_c);
    if (iVar2 != 0) break;
    iVar2 = props_getPointFromObject(param_1,local_c,(double *)&local_1c);
    if (iVar2 != 0) break;
    props_releaseAndClear(param_1,(int *)local_c);
    *param_3 = local_1c;
    param_3[1] = local_18;
    param_3[2] = local_14;
    param_3[3] = local_10;
    param_3 = param_3 + 4;
  } while (iVar1 < 4);
  props_releaseAndClear(param_1,(int *)local_c);
  return iVar2;
}



// ============================================================
// Function: props_createPolygonObject (FUN_68039140)
// Address: 68039140
// Size: 128 bytes
// Params: double * param_1, double * param_2, uint * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_createPolygonObject(double *param_1,double *param_2,uint *param_3)

{
  double *pdVar1;
  int iVar2;
  int iVar3;
  uint local_c [2];
  
  pdVar1 = param_1;
  *param_3 = 0;
  props_getContextRef((int)param_1,(int *)param_3);
  iVar3 = 0;
  param_1 = param_2;
  while( true ) {
    iVar2 = props_createPointObject((int)pdVar1,param_1,local_c);
    if (iVar2 != 0) break;
    iVar2 = props_dispatchMethod(pdVar1,param_3,local_c);
    if (iVar2 != 0) break;
    props_releaseAndClear(pdVar1,(int *)local_c);
    param_1 = param_1 + 2;
    iVar3 = iVar3 + 1;
    if (3 < iVar3) {
      return 0;
    }
  }
  props_releaseAndClear(pdVar1,(int *)param_3);
  return iVar2;
}



// ============================================================
// Function: props_appendStringRange (FUN_680391c0)
// Address: 680391c0
// Size: 166 bytes
// Params: int * param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_appendStringRange(int *param_1,int *param_2,int param_3)
{
  int in_EAX;
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint *unaff_EBX;
  int iVar6;
  int iVar7;
  
  iVar1 = in_EAX - *param_2;
  iVar7 = *param_1 - *param_2;
  iVar6 = iVar7 - iVar1;
  if (*unaff_EBX == 0) {
    puVar2 = (undefined4 *)cast_allocHandle(iVar6 + param_3,0);
    *unaff_EBX = (uint)puVar2;
    if (puVar2 == (undefined4 *)0x0) {
      return 0;
    }
    Ordinal_1129(*puVar2,*param_2 + iVar1,iVar6);
    iVar4 = iVar6;
  }
  else {
    iVar3 = Ordinal_1116(*unaff_EBX);
    iVar4 = iVar3 + iVar6;
    uVar5 = cast_resizeHandle(*unaff_EBX,iVar4 + param_3,0);
    if (uVar5 == 0) {
      return 0;
    }
    Ordinal_1129(*(int *)*unaff_EBX + iVar3,*param_2 + iVar1,iVar6);
  }
  *param_1 = *param_2 + iVar7;
  if (param_3 != 0) {
    *(undefined1 *)(iVar4 + *(int *)*unaff_EBX) = 0;
  }
  return 0;
}



// ============================================================
// Function: props_getExtValue (FUN_68039270)
// Address: 68039270
// Size: 65 bytes
// Params: undefined4 * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getExtValue(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  
  if (unaff_ESI[3] != 0) {
    uVar2 = stage_readAllocValue(*(int *)*unaff_ESI + unaff_ESI[1],unaff_ESI + 6);
    *param_1 = uVar2;
    iVar1 = unaff_ESI[6];
    if (iVar1 <= (int)unaff_ESI[3]) {
      unaff_ESI[1] = unaff_ESI[1] + iVar1;
      unaff_ESI[3] = unaff_ESI[3] - iVar1;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: props_advanceParserOffset (FUN_680392c0)
// Address: 680392c0
// Size: 10 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_advanceParserOffset(void)
{
  int in_EAX;
  
  *(int *)(in_EAX + 0xc) = *(int *)(in_EAX + 0xc) + *(int *)(in_EAX + 0x18);
  *(int *)(in_EAX + 4) = *(int *)(in_EAX + 4) - *(int *)(in_EAX + 0x18);
  return 0;
}



// ============================================================
// Function: props_dispatchExtMethod (FUN_680392d0)
// Address: 680392d0
// Size: 66 bytes
// Params: undefined4 param_1, undefined4 * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_dispatchExtMethod(undefined4 param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  iVar1 = stage_readAllocValue(*(int *)*param_2 + param_2[1],param_2 + 6);
  if (iVar1 == param_3) {
    iVar1 = param_2[6];
    if (iVar1 <= (int)param_2[3]) {
      param_2[1] = param_2[1] + iVar1;
      param_2[3] = param_2[3] - iVar1;
      return 1;
    }
  }
  return 0;
}


