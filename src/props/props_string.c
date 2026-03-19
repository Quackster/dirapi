// Module: props
// Topic: String handling, pascal strings, serialization
// Address range: 0x68030e90 - 0x6803ef40
// Functions (23):
//   props_formatDouble (FUN_68030e90)
//   props_formatFloat (FUN_68030ec0)
//   props_valueToString (FUN_68030ef0)
//   props_writePascalString (FUN_68031160)
//   props_serializeValue (FUN_680311a0)
//   props_cStringToPascal (FUN_68031220)
//   props_pascalToHandle (FUN_68031270)
//   props_createStringHandle (FUN_68031be0)
//   props_getSymbolString (FUN_68031c20)
//   props_resolveAndStore (FUN_680324b0)
//   props_setupCallback (FUN_680324f0)
//   props_uniquifyString (FUN_680378f0)
//   props_createStringFromData (FUN_680379c0)
//   props_getStringData (FUN_68037a10)
//   props_unlockString (FUN_68037a80)
//   props_copyString (FUN_68037aa0)
//   props_freeStringCallback (FUN_68037af0)
//   props_detachString (FUN_68037b00)
//   props_toPascalString (FUN_68037b50)
//   props_getStringRef
//   props_coerceStringPair (FUN_6803ed30)
//   props_getStringLength
//   props_compareStrings (FUN_6803ef40)



// ============================================================
// Function: props_formatDouble
// Address: 68030e90
// Size: 40 bytes
// Params: int param_1, undefined8 param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_formatDouble(int param_1,undefined8 param_2,undefined1 *param_3)
{
  cast_formatDouble(param_2,*(undefined4 *)(**(int **)(param_1 + 8) + 0x4fc),param_3);
  return 0;
}



// ============================================================
// Function: props_formatFloat
// Address: 68030ec0
// Size: 38 bytes
// Params: int param_1, float param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_formatFloat(int param_1,float param_2,undefined1 *param_3)
{
  cast_formatFloat(param_2,*(undefined4 *)(**(int **)(param_1 + 8) + 0x4fc),param_3);
  return 0;
}



// ============================================================
// Function: props_valueToString
// Address: 68030ef0
// Size: 513 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_valueToString(int param_1,int *param_2,undefined4 param_3,undefined4 param_4)
{
  float fVar1;
  int iVar2;
  undefined1 local_408;
  byte local_407 [1023];
  uint local_8;
  
  switch(*param_2) {
  case 0:
    iVar2 = 1;
    break;
  case 1:
  case 0x40:
  case 0x43:
    props_getStringData(param_2,(int *)0x0);
    props_formatString(param_1,param_3,param_4,&DAT_6817c390);
    props_unlockString(param_2);
    return 0;
  case 2:
    iVar2 = 2;
    break;
  case 3:
    if (param_2[1] != 0) {
      (**(code **)(**(int **)param_2[1] + 0x10))(param_1,(undefined4 *)param_2[1],param_3,param_4);
      return 0;
    }
    goto LAB_680310de;
  case 4:
    props_formatString(param_1,param_3,param_4,&DAT_6817c38c);
    return 0;
  default:
    props_formatString(param_1,param_3,param_4,(byte *)"<%d %x>");
LAB_680310de:
    return 0;
  case 6:
    cast_loadPascalString(&local_408,0x898,3);
    props_formatString(param_1,param_3,param_4,local_407);
    return 0;
  case 8:
    score_lookupSymbol(DAT_68196304,param_2[1],(int)&local_408);
    props_formatString(param_1,param_3,param_4,&DAT_6817c384);
    return 0;
  case 9:
  case 0x20:
  case 0x23:
    if (*param_2 == 0x20) {
      fVar1 = (float)(size_t)param_2[1];
    }
    else {
      fVar1 = (float)*(double *)(*(int *)param_2[1] + 8);
    }
    props_formatDouble(param_1,(double)fVar1,&local_408);
    props_formatString(param_1,param_3,param_4,&DAT_6817c388);
    return 0;
  }
  cast_loadPascalString(&local_408,0x898,iVar2);
  props_formatString(param_1,param_3,param_4,local_407);
  return 0;
}



// ============================================================
// Function: props_writePascalString
// Address: 68031160
// Size: 56 bytes
// Params: undefined4 param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_writePascalString(undefined4 param_1,byte *param_2)

{
  ushort uVar1;
  
  if (param_2 != (byte *)0x0) {
    if (*param_2 == 0xff) {
      uVar1 = Ordinal_1201(param_2 + 1);
    }
    else {
      uVar1 = (ushort)*param_2;
    }
    Ordinal_1420(param_1,param_2 + 1,(int)(short)uVar1);
  }
  return 1;
}



// ============================================================
// Function: props_serializeValue
// Address: 680311a0
// Size: 124 bytes
// Params: int param_1, int * param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_serializeValue(int param_1,int *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int local_8;
  
  local_8 = 0;
  iVar1 = Ordinal_1111(0,0);
  if (iVar1 != 0) {
    iVar2 = Ordinal_1404(&local_8,iVar1,3);
    if (iVar2 != 0) {
      if (param_3 != 0) {
        Ordinal_1420(local_8,param_3,8);
      }
      props_valueToString(param_1,param_2,props_writePascalString,local_8);
      Ordinal_1420(local_8,&DAT_6817a914,1);
    }
  }
  if (local_8 != 0) {
    Ordinal_1407(&local_8);
  }
  return iVar1;
}



// ============================================================
// Function: props_cStringToPascal
// Address: 68031220
// Size: 66 bytes
// Params: undefined4 * param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_cStringToPascal(undefined4 *param_1,undefined1 *param_2)
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = (char *)*param_1;
  iVar3 = 0;
  cVar1 = *pcVar2;
  while ((cVar1 != '\0' && (iVar3 < 0x3fe))) {
    param_2[iVar3 + 1] = pcVar2[iVar3];
    iVar3 = iVar3 + 1;
    cVar1 = pcVar2[iVar3];
  }
  param_2[iVar3 + 1] = 0;
  if (0xfe < iVar3) {
    *param_2 = 0xff;
    return 0;
  }
  *param_2 = (char)iVar3;
  return 0;
}



// ============================================================
// Function: props_pascalToHandle
// Address: 68031270
// Size: 75 bytes
// Params: byte * param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * props_pascalToHandle(byte *param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  
  if (*param_1 == 0xff) {
    uVar1 = Ordinal_1201(param_1 + 1);
  }
  else {
    uVar1 = (ushort)*param_1;
  }
  iVar3 = (int)(short)uVar1;
  piVar2 = (int *)Ordinal_1111(iVar3 + 1,0);
  if (piVar2 != (int *)0x0) {
    Ordinal_1128(*piVar2,param_1 + 1,iVar3);
    *(undefined1 *)(iVar3 + *piVar2) = 0;
  }
  return piVar2;
}



// ============================================================
// Function: props_createStringHandle (FUN_68031be0)
// Address: 68031be0
// Size: 63 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_createStringHandle(int param_1,int *param_2,undefined4 *param_3)
{
  undefined4 *puVar1;
  
  if (param_2 == (int *)0x0) {
    puVar1 = (undefined4 *)Ordinal_1111(1,0);
    if (puVar1 == (undefined4 *)0x0) {
      return 0;
    }
    *(undefined1 *)*puVar1 = 0;
  }
  else {
    puVar1 = (undefined4 *)Ordinal_1120(*(undefined4 *)(*param_2 + 0x2c));
  }
  if (puVar1 != (undefined4 *)0x0) {
    props_getValuePair(param_1,puVar1,param_3);
  }
  return 0;
}



// ============================================================
// Function: props_getSymbolString (FUN_68031c20)
// Address: 68031c20
// Size: 123 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getSymbolString(int param_1,int param_2,int param_3)
{
  ushort uVar1;
  int iVar2;
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  score_lookupSymbol(DAT_68196304,param_1,(int)&local_408);
  if (local_408 == 0xff) {
    uVar1 = Ordinal_1201(local_407);
  }
  else {
    uVar1 = (ushort)local_408;
  }
  iVar2 = (int)(short)uVar1;
  if (param_3 <= iVar2) {
    iVar2 = param_3 + -1;
  }
  Ordinal_1129(param_2,local_407,iVar2);
  *(undefined1 *)(param_2 + iVar2) = 0;
  return 0;
}



// ============================================================
// Function: props_resolveAndStore (FUN_680324b0)
// Address: 680324b0
// Size: 53 bytes
// Params: int param_1, int * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// Resolves a symbol name and stores it in the given location
// ============================================================

int props_resolveAndStore(int param_1,int *param_2,undefined4 param_3)
{
  undefined4 local_c [2];
  
  sprites_getNetResult(param_1,&param_3,param_3,local_c);
  props_valueToString(param_1,param_2,param_3,local_c);
  return 0;
}



// ============================================================
// Function: props_setupCallback (FUN_680324f0)
// Address: 680324f0
// Size: 68 bytes
// Params: undefined * param_1, int * param_2, undefined2 * param_3
// Return: undefined
// Calling convention: __stdcall
// Sets up a callback handler with optional error string
// ============================================================

int props_setupCallback(undefined *param_1,int *param_2,undefined2 *param_3)
{
  undefined *puVar1;
  
  puVar1 = param_1;
  if (param_3 == (undefined2 *)0x0) {
    sprites_getNetResultString(param_1,&param_1,&param_3);
  }
  else {
    *param_3 = 0;
    param_1 = props_checkBufferSpace;
  }
  props_valueToString((int)puVar1,param_2,param_1,param_3);
  return 0;
}



// ============================================================
// Function: props_uniquifyString
// Address: 680378f0
// Size: 201 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_uniquifyString(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int **ppiVar4;
  int iVar5;
  int *local_8;
  
  if ((*param_2 != 0x43) || (uVar2 = 1, *(int *)(*(int *)param_2[1] + 4) != 1)) {
    iVar1 = *param_2;
    local_8 = (int *)param_2[1];
    if (iVar1 == 0x40) {
      iVar5 = (uint)((char)((uint)local_8 >> 8) != '\0') +
              (uint)((char)((uint)local_8 >> 0x10) != '\0') + (uint)((char)local_8 != '\0');
    }
    else {
      iVar5 = Ordinal_1116(local_8);
      iVar5 = iVar5 + -9;
    }
    iVar3 = stage_resolveString(param_1,iVar5,param_2);
    if (iVar3 != 0) {
      if (iVar1 == 0x40) {
        ppiVar4 = &local_8;
      }
      else {
        ppiVar4 = (int **)(*local_8 + 8);
      }
      Ordinal_1128(*(int *)param_2[1] + 8,ppiVar4,iVar5 + 1);
      if (iVar1 == 0x43) {
        *(int *)(*local_8 + 4) = *(int *)(*local_8 + 4) + -1;
      }
      return 1;
    }
    *param_2 = 2;
    param_2[1] = 0;
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: props_createStringFromData
// Address: 680379c0
// Size: 74 bytes
// Params: int param_1, undefined4 param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_createStringFromData(int param_1,undefined4 param_2,int param_3,undefined4 *param_4)
{
  int iVar1;
  
  iVar1 = stage_resolveString(param_1,param_3,param_4);
  if (iVar1 != 0) {
    iVar1 = *(int *)param_4[1];
    Ordinal_1128(iVar1 + 8,param_2,param_3);
    *(undefined1 *)(iVar1 + 8 + param_3) = 0;
    return 0;
  }
  *param_4 = 2;
  param_4[1] = 0;
  return 0;
}



// ============================================================
// Function: props_getStringData
// Address: 68037a10
// Size: 97 bytes
// Params: int * param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * props_getStringData(int *param_1,int *param_2)

{
  int iVar1;
  
  if (*param_1 == 0x40) {
    if (param_2 != (int *)0x0) {
      *param_2 = (uint)(*(char *)((int)param_1 + 6) != '\0') +
                 (uint)(*(char *)((int)param_1 + 5) != '\0') + (uint)((char)param_1[1] != '\0');
    }
    return param_1 + 1;
  }
  if (param_2 != (int *)0x0) {
    iVar1 = Ordinal_1116(param_1[1]);
    *param_2 = iVar1 + -9;
  }
  iVar1 = Ordinal_1114(param_1[1]);
  return (int *)(iVar1 + 8);
}



// ============================================================
// Function: props_unlockString
// Address: 68037a80
// Size: 28 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_unlockString(int *param_1)
{
  if ((*param_1 != 0x40) && (param_1[1] != 0)) {
    Ordinal_1115(param_1[1]);
  }
  return 0;
}



// ============================================================
// Function: props_copyString
// Address: 68037aa0
// Size: 70 bytes
// Params: int * param_1
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * props_copyString(int *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  int local_8;
  
  piVar1 = props_getStringData(param_1,&local_8);
  puVar2 = (undefined4 *)cast_allocHandle(local_8 + 1,0);
  if (puVar2 != (undefined4 *)0x0) {
    Ordinal_1128(*puVar2,piVar1,local_8 + 1);
  }
  props_unlockString(param_1);
  return puVar2;
}



// ============================================================
// Function: props_freeStringCallback
// Address: 68037af0
// Size: 16 bytes
// Params: undefined4 param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_freeStringCallback(undefined4 param_1,undefined4 param_2)
{
  cast_freeHandle(param_2);
  return 0;
}



// ============================================================
// Function: props_detachString
// Address: 68037b00
// Size: 74 bytes
// Params: int param_1, int * param_2
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * props_detachString(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  
  puVar3 = props_copyString(param_2);
  if ((*param_2 == 0x43) &&
     (iVar2 = *(int *)param_2[1], piVar1 = (int *)(iVar2 + 4), *piVar1 = *piVar1 + -1,
     *(int *)(iVar2 + 4) < 1)) {
    cast_freeHandle(param_2[1]);
    *(int *)(param_1 + 0xfc) = *(int *)(param_1 + 0xfc) + -1;
  }
  *param_2 = 0;
  param_2[1] = 0;
  return puVar3;
}



// ============================================================
// Function: props_toPascalString
// Address: 68037b50
// Size: 87 bytes
// Params: int * param_1, undefined1 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_toPascalString(int *param_1,undefined1 *param_2)
{
  int *piVar1;
  undefined1 *puVar2;
  int *piVar3;
  int *piVar4;
  
  piVar1 = param_1;
  piVar3 = props_getStringData(param_1,(int *)&param_1);
  puVar2 = param_2;
  piVar4 = param_1;
  if (0x3fe < (int)param_1) {
    piVar4 = (int *)0x3fe;
  }
  Ordinal_1128(param_2 + 1,piVar3,piVar4);
  props_unlockString(piVar1);
  puVar2[(int)piVar4 + 1] = 0;
  if ((int)piVar4 < 0xff) {
    *puVar2 = (char)piVar4;
    return 0;
  }
  *puVar2 = 0xff;
  return 0;
}



// ============================================================
// Function: props_getStringRef (FUN_6803ec80)
// Address: 6803ec80
// Size: 89 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_getStringRef(int param_1,int *param_2)

{
  switch(*param_2) {
  case 1:
  case 0x40:
  case 0x43:
    props_parseStringConstant();
    break;
  case 4:
    props_storeNumber(param_1,(double)param_2[1],param_2);
  }
  if ((*param_2 != 0x20) && (*param_2 != 0x23)) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: props_coerceStringPair (FUN_6803ed30)
// Address: 6803ed30
// Size: 63 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 props_coerceStringPair(int param_1,int *param_2,int *param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if ((*param_2 != 2) && (*param_3 != 2)) {
    iVar1 = props_getStringRef(param_1,param_2);
    if (iVar1 != 0) {
      uVar2 = props_getStringRef(param_1,param_3);
      return uVar2;
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: props_getStringLength (FUN_6803ed70)
// Address: 6803ed70
// Size: 365 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_getStringLength(int param_1,int *param_2)
{
  float fVar1;
  int iVar2;
  double local_410;
  byte local_408 [1024];
  uint local_8;
  
  iVar2 = *param_2;
  switch(iVar2) {
  case 1:
  case 0x40:
  case 0x43:
    goto switchD_6803eda0_caseD_1;
  case 2:
    props_releaseValue(param_1,(byte)iVar2,(int *)param_2[1]);
    props_createStringFromData(param_1,"",0,param_2);
    return 0;
  default:
    stage_initStringLabel(param_1,(undefined4 *)&local_410);
    iVar2 = props_serializeValue(param_1,param_2,(int)&local_410);
    props_releaseValue(param_1,(byte)*param_2,(int *)param_2[1]);
    param_2[1] = iVar2;
    *param_2 = 0x43;
switchD_6803eda0_caseD_1:
    return 0;
  case 4:
    Ordinal_951(param_2[1],local_408);
    props_readPascalString(param_1,local_408,param_2);
    return 0;
  case 8:
    score_lookupSymbol(DAT_68196304,param_2[1],(int)local_408);
    props_readPascalString(param_1,local_408,param_2);
    return 0;
  case 9:
  case 0x20:
  case 0x23:
    if (iVar2 == 0x20) {
      fVar1 = (float)(size_t)param_2[1];
    }
    else {
      fVar1 = (float)*(double *)(*(int *)param_2[1] + 8);
    }
    local_410 = (double)fVar1;
    props_releaseValue(param_1,(byte)*param_2,(int *)param_2[1]);
    props_formatDouble(param_1,local_410,local_408);
    props_readPascalString(param_1,local_408,param_2);
    return 0;
  }
}



// ============================================================
// Function: props_compareStrings (FUN_6803ef40)
// Address: 6803ef40
// Size: 230 bytes
// Params: int param_1, int * param_2, int * param_3, int param_4, uint param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint props_compareStrings(int param_1,int *param_2,int *param_3,int param_4,uint param_5)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  int *piVar4;
  int *piVar5;
  undefined3 extraout_var;
  uint uVar6;
  int iVar7;
  
  piVar1 = param_2;
  iVar7 = param_1;
  props_getStringLength(param_1,param_2);
  piVar2 = param_3;
  props_getStringLength(iVar7,param_3);
  if (((*piVar1 == 0x40) || (*piVar1 == 0x43)) && ((*piVar2 == 0x40 || (*piVar2 == 0x43)))) {
    piVar4 = props_getStringData(piVar1,&param_1);
    piVar5 = props_getStringData(piVar2,(int *)&param_2);
    if (param_4 == 0) {
      bVar3 = Ordinal_966(piVar4,piVar5,param_1,param_2);
      uVar6 = (uint)(CONCAT31(extraout_var,bVar3) == 0);
    }
    else if (param_4 == 2) {
      uVar6 = Ordinal_967((int)piVar4,(int)piVar5,param_1,(int)param_2);
    }
    else {
      iVar7 = Ordinal_967((int)piVar4,(int)piVar5,param_1,(int)param_2);
      uVar6 = (uint)(param_4 == iVar7);
    }
    props_unlockString(piVar1);
    props_unlockString(piVar2);
    return uVar6 ^ param_5;
  }
  if (param_4 != 2) {
    return param_5;
  }
  if (piVar2[1] < piVar1[1]) {
    return param_5 ^ 1;
  }
  return -(uint)(piVar1[1] != piVar2[1]) ^ param_5;
}


