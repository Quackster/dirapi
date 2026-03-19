// Module: runtime
// Topic: Stream I/O, bytecode serialization, and script deserialization
// Address range: 0x68120d00 - 0x68121eb0
// Functions (32):
//   runtime_checkWatchStates
//   runtime_checkAllWatchStates
//   runtime_readStreamDword
//   runtime_writeStreamDword
//   runtime_readStreamBlock
//   runtime_writeStreamBlock
//   runtime_reserveStreamSpace
//   runtime_seekStream
//   runtime_getStreamPosition
//   runtime_closeStream
//   runtime_initStream
//   runtime_getSerializedEntry
//   runtime_validateStream
//   runtime_writeSerializedData
//   runtime_beginSerialization
//   runtime_serializeValue
//   runtime_serializeString
//   runtime_deserializeValue
//   runtime_serializeOptionalString
//   runtime_serializeWideString
//   runtime_serializeOptionalWideString
//   runtime_serializeDouble
//   runtime_serializeTaggedValue
//   runtime_addSerializationEntry
//   runtime_lookupSerializationEntry
//   runtime_getSerializationEntryByIndex
//   runtime_serializeByte
//   runtime_serializeShort
//   runtime_serializeScriptSource
//   runtime_getScriptString
//   runtime_evaluateScript
//   runtime_serializeCompiledValue

// ============================================================
// Function: runtime_checkWatchStates (FUN_68120d00)
// Address: 68120d00
// Size: 81 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_checkWatchStates(int param_1,int param_2)

{
  int local_14;
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  
  puVar4 = (undefined4 *)(*(int *)(param_1 + 0x14) + 0x240);
  puVar3 = (undefined4 *)*puVar4;
  do {
    if (puVar3 == puVar4) {
      return 1;
    }
    puVar2 = (undefined4 *)*puVar3;
    piVar1 = puVar3 + 2;
    puVar3 = puVar2;
  } while ((*piVar1 != param_2) || (iVar5 = runtime_getBreakpointState(), iVar5 != 0));
  return 0;
}



// ============================================================
// Function: runtime_checkAllWatchStates (FUN_68120d60)
// Address: 68120d60
// Size: 71 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_checkAllWatchStates(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  
  puVar2 = (undefined4 *)(*(int *)(param_1 + 0x14) + 0x240);
  puVar1 = (undefined4 *)*puVar2;
  do {
    if (puVar1 == puVar2) {
      return 1;
    }
    puVar1 = (undefined4 *)*puVar1;
    iVar3 = runtime_getBreakpointState();
  } while (iVar3 != 0);
  return 0;
}



// ============================================================
// Function: runtime_readStreamDword (FUN_68120db0)
// Address: 68120db0
// Size: 76 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_readStreamDword(int *param_1,undefined4 *param_2)

{
  if ((*param_1 == 1) && ((uint)param_1[10] < param_1[9] + 4U)) {
    xtra_invokeMethod(param_1[2],xtra_getErrorString,0,0x3f);
    return 0;
  }
  *param_2 = *(undefined4 *)(param_1[8] + param_1[9]);
  param_1[9] = param_1[9] + 4;
  return 1;
}



// ============================================================
// Function: runtime_writeStreamDword (FUN_68120e00)
// Address: 68120e00
// Size: 141 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_writeStreamDword(int *param_1,undefined4 *param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*param_1 == 0) {
    if ((param_1[10] != 0) && ((uint)param_1[10] < param_1[9] + 4U)) {
      uVar2 = param_1[9] + 0x2003U & 0xffffe000;
      iVar1 = xtra_allocJSString(param_1[2],param_1[8],uVar2);
      if (iVar1 == 0) {
        return 0;
      }
      param_1[8] = iVar1;
      param_1[10] = uVar2;
    }
  }
  else if ((*param_1 == 1) && ((uint)param_1[10] < param_1[9] + 4U)) {
    xtra_invokeMethod(param_1[2],xtra_getErrorString,0,0x3f);
    return 0;
  }
  *(undefined4 *)(param_1[8] + param_1[9]) = *param_2;
  param_1[9] = param_1[9] + 4;
  return 1;
}



// ============================================================
// Function: runtime_readStreamBlock (FUN_68120e90)
// Address: 68120e90
// Size: 91 bytes
// Params: int * param_1, undefined4 * param_2, size_t param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_readStreamBlock(int *param_1,undefined4 *param_2,size_t param_3)

{
  if ((*param_1 == 1) && ((uint)param_1[10] < param_1[9] + param_3)) {
    xtra_invokeMethod(param_1[2],xtra_getErrorString,0,0x3f);
    return 0;
  }
  memcpy((void *)*param_2,(void *)(param_1[8] + param_1[9]),param_3);
  param_1[9] = param_1[9] + param_3;
  return 1;
}



// ============================================================
// Function: runtime_writeStreamBlock (FUN_68120ef0)
// Address: 68120ef0
// Size: 152 bytes
// Params: int * param_1, undefined4 * param_2, size_t param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_writeStreamBlock(int *param_1,undefined4 *param_2,size_t param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*param_1 == 0) {
    if ((param_1[10] != 0) && ((uint)param_1[10] < param_1[9] + param_3)) {
      uVar2 = param_1[9] + param_3 + 0x1fff & 0xffffe000;
      iVar1 = xtra_allocJSString(param_1[2],param_1[8],uVar2);
      if (iVar1 == 0) {
        return 0;
      }
      param_1[8] = iVar1;
      param_1[10] = uVar2;
    }
  }
  else if ((*param_1 == 1) && ((uint)param_1[10] < param_1[9] + param_3)) {
    xtra_invokeMethod(param_1[2],xtra_getErrorString,0,0x3f);
    return 0;
  }
  memcpy((void *)(param_1[8] + param_1[9]),(void *)*param_2,param_3);
  param_1[9] = param_1[9] + param_3;
  return 1;
}



// ============================================================
// Function: runtime_reserveStreamSpace (FUN_68120f90)
// Address: 68120f90
// Size: 135 bytes
// Params: int * param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_reserveStreamSpace(int *param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  if (*param_1 == 0) {
    if ((param_1[10] != 0) && ((uint)param_1[10] < (uint)(param_1[9] + param_2))) {
      uVar2 = param_1[9] + param_2 + 0x1fffU & 0xffffe000;
      iVar1 = xtra_allocJSString(param_1[2],param_1[8],uVar2);
      if (iVar1 == 0) {
        return 0;
      }
      param_1[8] = iVar1;
      param_1[10] = uVar2;
    }
  }
  else if ((*param_1 == 1) && ((uint)param_1[10] < (uint)(param_1[9] + param_2))) {
    xtra_invokeMethod(param_1[2],xtra_getErrorString,0,0x3f);
    return 0;
  }
  iVar1 = param_1[9];
  param_1[9] = iVar1 + param_2;
  return param_1[8] + iVar1;
}



// ============================================================
// Function: runtime_seekStream (FUN_68121020)
// Address: 68121020
// Size: 437 bytes
// Params: int * param_1, uint param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_seekStream(int *param_1,uint param_2,int param_3)
{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 local_14 [12];
  uint local_8;
  
  if (param_3 == 0) {
    if (-1 < (int)param_2) {
      if (*param_1 == 0) {
        if ((((uint)param_1[9] < param_2) && (param_1[10] != 0)) && ((uint)param_1[10] < param_2)) {
          uVar1 = param_2 + 0x1fff & 0xffffe000;
          iVar2 = xtra_allocJSString(param_1[2],param_1[8],uVar1);
          if (iVar2 == 0) goto LAB_681210ef;
          param_1[8] = iVar2;
          param_1[10] = uVar1;
        }
      }
      else if ((uint)param_1[10] < param_2) {
        uVar1 = param_1[2];
        uVar3 = 0x41;
        goto LAB_681210e7;
      }
      param_1[9] = param_2;
LAB_681211a6:
      return 0;
    }
    uVar1 = param_1[2];
    uVar3 = 0x40;
  }
  else {
    if (param_3 != 1) {
      if (param_3 != 2) {
        runtime_snprintf(local_14,0xc,"%d");
        xtra_invokeMethod(param_1[2],xtra_getErrorString,0,0x43);
        return 0;
      }
      if (((-1 < (int)param_2) || (*param_1 == 0)) || ((int)(param_2 + param_1[10]) < 0)) {
        xtra_invokeMethod(param_1[2],xtra_getErrorString,0,0x42);
        return 0;
      }
      param_1[9] = param_2 + param_1[10];
      goto LAB_681211a6;
    }
    uVar1 = param_1[9] + param_2;
    if (-1 < (int)uVar1) {
      if (0 < (int)param_2) {
        if (*param_1 == 0) {
          if ((param_1[10] != 0) && ((uint)param_1[10] < uVar1)) {
            uVar1 = uVar1 + 0x1fff & 0xffffe000;
            iVar2 = xtra_allocJSString(param_1[2],param_1[8],uVar1);
            if (iVar2 == 0) goto LAB_681210ef;
            param_1[8] = iVar2;
            param_1[10] = uVar1;
          }
        }
        else if ((*param_1 == 1) && ((uint)param_1[10] < uVar1)) {
          uVar3 = 0x3f;
          goto LAB_681210dc;
        }
      }
      param_1[9] = param_1[9] + param_2;
      goto LAB_681211a6;
    }
    uVar3 = 0x40;
LAB_681210dc:
    uVar1 = param_1[2];
  }
LAB_681210e7:
  xtra_invokeMethod(uVar1,xtra_getErrorString,0,uVar3);
LAB_681210ef:
  return 0;
}



// ============================================================
// Function: runtime_getStreamPosition (FUN_681211e0)
// Address: 681211e0
// Size: 13 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getStreamPosition(int param_1)

{
  return *(undefined4 *)(param_1 + 0x24);
}



// ============================================================
// Function: runtime_closeStream (FUN_681211f0)
// Address: 681211f0
// Size: 23 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_closeStream(int param_1)
{
  xtra_checkAndFlush(*(undefined4 *)(param_1 + 8),*(int *)(param_1 + 0x20));
  return 0;
}



// ============================================================
// Function: runtime_initStream (FUN_68121210)
// Address: 68121210
// Size: 38 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_initStream(undefined4 *param_1,undefined4 param_2,undefined4 param_3)
{
  *param_1 = param_2;
  param_1[2] = param_3;
  param_1[3] = 0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  param_1[7] = 0;
  return 0;
}



// ============================================================
// Function: runtime_getSerializedEntry (FUN_68121240)
// Address: 68121240
// Size: 108 bytes
// Params: int param_1, int param_2
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * runtime_getSerializedEntry(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)xtra_getPropertyById(param_1,0x2c);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  runtime_initStream(puVar1,param_2,param_1);
  if (param_2 == 0) {
    iVar2 = xtra_getPropertyById(param_1,0x2000);
    puVar1[8] = iVar2;
    if (iVar2 == 0) {
      xtra_checkAndFlush(param_1,(int)puVar1);
      return (undefined4 *)0x0;
    }
  }
  else {
    puVar1[8] = 0;
  }
  puVar1[1] = &PTR_FUN_681926b8;
  puVar1[9] = 0;
  puVar1[10] = 0x2000;
  return puVar1;
}



// ============================================================
// Function: runtime_validateStream (FUN_681212b0)
// Address: 681212b0
// Size: 36 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_validateStream(int param_1,undefined4 *param_2)

{
  if (*(undefined ***)(param_1 + 4) != &PTR_FUN_681926b8) {
    return 0;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x24);
  return *(undefined4 *)(param_1 + 0x20);
}



// ============================================================
// Function: runtime_writeSerializedData (FUN_681212e0)
// Address: 681212e0
// Size: 38 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_writeSerializedData(int param_1,undefined4 param_2,undefined4 param_3)
{
  if (*(undefined ***)(param_1 + 4) == &PTR_FUN_681926b8) {
    *(undefined4 *)(param_1 + 0x28) = param_3;
    *(undefined4 *)(param_1 + 0x20) = param_2;
    *(undefined4 *)(param_1 + 0x24) = 0;
  }
  return 0;
}



// ============================================================
// Function: runtime_beginSerialization (FUN_68121310)
// Address: 68121310
// Size: 60 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_beginSerialization(int param_1)
{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 8);
  (**(code **)(*(int *)(param_1 + 4) + 0x1c))(param_1);
  if (*(int *)(param_1 + 0xc) != 0) {
    xtra_checkAndFlush(uVar1,*(int *)(param_1 + 0xc));
    if (*(int **)(param_1 + 0x18) != (int *)0x0) {
      javascript_hashTableDestroy(*(int **)(param_1 + 0x18));
    }
  }
  xtra_checkAndFlush(uVar1,param_1);
  return 0;
}



// ============================================================
// Function: runtime_serializeValue (FUN_68121350)
// Address: 68121350
// Size: 63 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeValue(int *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = 1;
  if (*param_1 == 0) {
    param_2 = (undefined4 *)*param_2;
    uVar1 = (**(code **)(param_1[1] + 4))(param_1,&param_2);
    return uVar1;
  }
  if (*param_1 == 1) {
    uVar1 = (**(code **)param_1[1])(param_1,param_2);
  }
  return uVar1;
}



// ============================================================
// Function: runtime_serializeString (FUN_68121390)
// Address: 68121390
// Size: 142 bytes
// Params: int * param_1, undefined4 param_2, undefined * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeString(int *param_1,undefined4 param_2,undefined *param_3)

{
  int iVar1;
  uint uVar2;
  
  if (*param_1 == 0) {
    iVar1 = (**(code **)(param_1[1] + 0xc))(param_1,param_2,param_3);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    iVar1 = (**(code **)(param_1[1] + 8))(param_1,param_2,param_3);
    if (iVar1 == 0) {
      return 0;
    }
  }
  uVar2 = (**(code **)(param_1[1] + 0x18))(param_1);
  if ((uVar2 & 3) != 0) {
    iVar1 = 4 - (uVar2 & 3);
    if (*param_1 == 0) {
      param_3 = &DAT_68196970;
      iVar1 = (**(code **)(param_1[1] + 0xc))(param_1,&param_3,iVar1);
      if (iVar1 == 0) {
        return 0;
      }
    }
    else {
      iVar1 = (**(code **)(param_1[1] + 0x14))(param_1,iVar1,1);
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
  return 1;
}



// ============================================================
// Function: runtime_deserializeValue (FUN_68121420)
// Address: 68121420
// Size: 169 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_deserializeValue(int *param_1,int *param_2)

{
  char *pcVar1;
  char cVar2;
  int *piVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  
  piVar4 = param_2;
  piVar3 = param_1;
  if (*param_1 == 0) {
    pcVar5 = (char *)*param_2;
    pcVar1 = pcVar5 + 1;
    do {
      cVar2 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar2 != '\0');
    param_1 = (int *)(pcVar5 + -(int)pcVar1);
  }
  runtime_serializeValue(piVar3,&param_1);
  if (*piVar3 == 1) {
    iVar6 = xtra_getPropertyById(piVar3[2],(int)param_1 + 1);
    *piVar4 = iVar6;
    if (iVar6 == 0) {
      return 0;
    }
  }
  iVar6 = runtime_serializeString(piVar3,piVar4,(undefined *)param_1);
  if (iVar6 == 0) {
    if (*piVar3 == 1) {
      xtra_checkAndFlush(piVar3[2],*piVar4);
    }
    return 0;
  }
  if (*piVar3 != 1) {
    if (*piVar3 == 2) {
      xtra_checkAndFlush(piVar3[2],*piVar4);
      *piVar4 = 0;
    }
    return 1;
  }
  *(undefined1 *)((int)param_1 + *piVar4) = 0;
  return 1;
}



// ============================================================
// Function: runtime_serializeOptionalString (FUN_681214d0)
// Address: 681214d0
// Size: 77 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeOptionalString(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = param_2;
  param_2 = (int *)(uint)(*param_2 == 0);
  iVar2 = runtime_serializeValue(param_1,&param_2);
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != (int *)0x0) {
    *piVar1 = 0;
    return 1;
  }
  uVar3 = runtime_deserializeValue(param_1,piVar1);
  return uVar3;
}



// ============================================================
// Function: runtime_serializeWideString (FUN_68121520)
// Address: 68121520
// Size: 457 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeWideString(int *param_1,int *param_2)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  ushort *puVar4;
  undefined2 *puVar5;
  undefined2 *puVar6;
  ushort *puVar7;
  uint uVar8;
  uint uVar9;
  size_t local_c;
  uint local_8;
  
  if ((*param_1 == 0) && (local_8 = *(uint *)*param_2, (local_8 & 0x40000000) != 0)) {
    local_8 = (-(uint)((local_8 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & local_8;
  }
  iVar3 = runtime_serializeValue(param_1,&local_8);
  if (iVar3 == 0) {
    return 0;
  }
  uVar9 = local_8 * 2;
  if (*param_1 == 1) {
    puVar4 = (ushort *)xtra_getPropertyById(param_1[2],uVar9 + 2);
    if (puVar4 == (ushort *)0x0) {
      return 0;
    }
  }
  else {
    puVar1 = (uint *)*param_2;
    uVar8 = *puVar1;
    if ((uVar8 & 0x40000000) == 0) {
      puVar4 = (ushort *)puVar1[1];
    }
    else {
      puVar2 = (uint *)puVar1[1];
      if ((*puVar2 & 0x40000000) == 0) {
        if ((int)uVar8 < 0) {
          puVar4 = (ushort *)puVar2[1];
        }
        else {
          puVar4 = (ushort *)(puVar2[1] + (uVar8 >> 0xf & 0x7fff) * 2);
        }
      }
      else {
        puVar4 = (ushort *)crypto_getStringLen(puVar1);
      }
    }
  }
  local_c = uVar9 & 3;
  if (local_c != 0) {
    local_c = 4 - local_c;
    uVar9 = uVar9 + local_c;
  }
  puVar5 = (undefined2 *)(**(code **)(param_1[1] + 0x10))(param_1,uVar9);
  if (puVar5 == (undefined2 *)0x0) {
LAB_681216cf:
    if (*param_1 == 1) {
      xtra_checkAndFlush(param_1[2],(int)puVar4);
    }
    return 0;
  }
  if (*param_1 == 0) {
    javascript_delegateToHost(param_1[2],puVar4,local_8,0);
    uVar8 = 0;
    if (local_8 != 0) {
      puVar6 = puVar5;
      do {
        *puVar6 = *(undefined2 *)(((int)puVar4 - (int)puVar5) + (int)puVar6);
        uVar8 = uVar8 + 1;
        puVar6 = puVar6 + 1;
      } while (uVar8 < local_8);
    }
    if (local_c != 0) {
      memset((void *)((int)puVar5 + (uVar9 - local_c)),0,local_c);
    }
    javascript_delegateToHost(param_1[2],puVar4,local_8,1);
  }
  else if (*param_1 == 1) {
    uVar9 = 0;
    if (local_8 != 0) {
      puVar7 = puVar4;
      do {
        *puVar7 = *(ushort *)(((int)puVar5 - (int)puVar4) + (int)puVar7);
        uVar9 = uVar9 + 1;
        puVar7 = puVar7 + 1;
      } while (uVar9 < local_8);
    }
    puVar4[local_8] = 0;
    javascript_delegateToHost(param_1[2],puVar4,local_8,1);
    iVar3 = xtra_allocHashEntryDirect(param_1[2],(uint)puVar4,local_8);
    *param_2 = iVar3;
    if (iVar3 == 0) goto LAB_681216cf;
  }
  return 1;
}



// ============================================================
// Function: runtime_serializeOptionalWideString (FUN_681216f0)
// Address: 681216f0
// Size: 77 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeOptionalWideString(int *param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  
  piVar1 = param_2;
  param_2 = (int *)(uint)(*param_2 == 0);
  iVar2 = runtime_serializeValue(param_1,&param_2);
  if (iVar2 == 0) {
    return 0;
  }
  if (param_2 != (int *)0x0) {
    *piVar1 = 0;
    return 1;
  }
  uVar3 = runtime_serializeWideString(param_1,piVar1);
  return uVar3;
}



// ============================================================
// Function: runtime_serializeDouble (FUN_68121740)
// Address: 68121740
// Size: 106 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeDouble(int *param_1,int *param_2)

{
  int iVar1;
  undefined8 local_c;
  
  if (*param_1 == 0) {
    local_c = *(undefined8 *)*param_2;
  }
  iVar1 = runtime_serializeValue(param_1,(undefined4 *)&local_c);
  if ((iVar1 != 0) && (iVar1 = runtime_serializeValue(param_1,(undefined4 *)((int)&local_c + 4)), iVar1 != 0))
  {
    if (*param_1 == 1) {
      iVar1 = xtraRuntime_storeFloat(param_1[2],local_c);
      *param_2 = iVar1;
      if (iVar1 == 0) {
        return 0;
      }
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: runtime_serializeTaggedValue (FUN_681217b0)
// Address: 681217b0
// Size: 413 bytes
// Params: int * param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeTaggedValue(int *param_1,uint *param_2)

{
  uint uVar1;
  int *piVar2;
  uint *puVar3;
  int iVar4;
  
  puVar3 = param_2;
  piVar2 = param_1;
  if (*param_1 == 0) {
    uVar1 = *param_2;
    if (uVar1 == 0) {
      param_1 = (int *)0x8;
    }
    else if (uVar1 == 0x80000001) {
      param_1 = (int *)0xa;
    }
    else {
      param_1 = (int *)(uVar1 & 7);
    }
  }
  iVar4 = runtime_serializeValue(piVar2,&param_1);
  if (iVar4 == 0) {
    return 0;
  }
  switch ((int)(size_t)param_1) { /* FIXUP(C2050): cast non-integral switch to int */
  case (int *)0x0:
    if (*piVar2 == 0) {
      param_2 = (uint *)(*puVar3 & 0xfffffff8);
    }
    iVar4 = runtime_serializeObjectRef(piVar2,(int *)&param_2);
    if (iVar4 == 0) {
      return 0;
    }
    if (*piVar2 == 1) {
      *puVar3 = (uint)param_2;
      return 1;
    }
    break;
  default:
    if (*piVar2 == 0) {
      param_2 = (uint *)((int)*puVar3 >> 1);
    }
    iVar4 = runtime_serializeValue(piVar2,&param_2);
    if (iVar4 == 0) {
      return 0;
    }
    if (*piVar2 == 1) {
      *puVar3 = (int)param_2 * 2 | 1;
    }
    break;
  case (int *)0x2:
    if (*piVar2 == 0) {
      param_2 = (uint *)(*puVar3 & 0xfffffff8);
    }
    iVar4 = runtime_serializeDouble(piVar2,(int *)&param_2);
    if (iVar4 == 0) {
      return 0;
    }
    if (*piVar2 == 1) {
      *puVar3 = (uint)param_2 | 2;
      return 1;
    }
    break;
  case (int *)0x4:
    if (*piVar2 == 0) {
      param_2 = (uint *)(*puVar3 & 0xfffffff8);
    }
    iVar4 = runtime_serializeWideString(piVar2,(int *)&param_2);
    if (iVar4 == 0) {
      return 0;
    }
    if (*piVar2 == 1) {
      *puVar3 = (uint)param_2 | 4;
      return 1;
    }
    break;
  case (int *)0x6:
    if (*piVar2 == 0) {
      param_2 = (uint *)((int)*puVar3 >> 3);
    }
    iVar4 = runtime_serializeValue(piVar2,&param_2);
    if (iVar4 == 0) {
      return 0;
    }
    if (*piVar2 == 1) {
      *puVar3 = (int)param_2 * 8 | 6;
      return 1;
    }
    break;
  case (int *)0x8:
    *puVar3 = 0;
    return 1;
  case (int *)0xa:
    *puVar3 = 0x80000001;
    return 1;
  }
  return 1;
}



// ============================================================
// Function: runtime_addSerializationEntry (FUN_68121980)
// Address: 68121980
// Size: 145 bytes
// Params: int param_1, uint * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_addSerializationEntry(int param_1,uint *param_2,int *param_3)

{
  int local_18;
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  int iVar5;
  
  uVar1 = *(uint *)(param_1 + 0x10);
  uVar2 = *(uint *)(param_1 + 0x14);
  if (uVar1 == uVar2) {
    if (uVar2 == 0) {
      iVar5 = 8;
    }
    else {
      iVar5 = uVar2 * 2;
    }
    iVar3 = xtra_allocJSString(*(int *)(param_1 + 8),*(int *)(param_1 + 0xc),iVar5 * 4);
    if (iVar3 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0xc) = iVar3;
    *(int *)(param_1 + 0x14) = iVar5;
  }
  else {
    iVar3 = *(int *)(param_1 + 0xc);
  }
  *(uint **)(iVar3 + uVar1 * 4) = param_2;
  if (*(int **)(param_1 + 0x18) != (int *)0x0) {
    puVar4 = js_getPropertySlot(*(int **)(param_1 + 0x18),*param_2,1);
    if (puVar4 == (uint *)0x0) {
      xtra_reportError(*(int *)(param_1 + 8));
      return 0;
    }
    puVar4[1] = *param_2;
    puVar4[2] = uVar1;
  }
  *param_3 = uVar1 + 1;
  *(uint *)(param_1 + 0x10) = uVar1 + 1;
  return 1;
}



// ============================================================
// Function: runtime_lookupSerializationEntry (FUN_68121a20)
// Address: 68121a20
// Size: 212 bytes
// Params: int param_1, byte * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_lookupSerializationEntry(int param_1,byte *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  undefined **ppuVar4;
  undefined4 *puVar5;
  uint *puVar6;
  uint *puVar7;
  byte *pbVar8;
  byte *pbVar9;
  uint uVar10;
  bool bVar11;
  undefined4 uVar12;
  int iVar13;
  
  uVar2 = *(uint *)(param_1 + 0x10);
  if (9 < uVar2) {
    if (*(int *)(param_1 + 0x18) == 0) {
      iVar13 = 0xc;
      uVar12 = 0;
      uVar10 = uVar2;
      ppuVar4 = javascript_getDefaultAllocator();
      puVar5 = javascript_hashTableCreate(ppuVar4,uVar12,iVar13,uVar10);
      *(undefined4 **)(param_1 + 0x18) = puVar5;
      if ((puVar5 != (undefined4 *)0x0) && (uVar10 = 0, uVar2 != 0)) {
        do {
          puVar7 = *(uint **)(*(int *)(param_1 + 0xc) + uVar10 * 4);
          puVar6 = js_getPropertySlot(*(int **)(param_1 + 0x18),*puVar7,1);
          uVar3 = *puVar7;
          puVar6[2] = uVar10;
          uVar10 = uVar10 + 1;
          puVar6[1] = uVar3;
        } while (uVar10 < uVar2);
      }
    }
    if ((*(int **)(param_1 + 0x18) != (int *)0x0) &&
       (puVar7 = js_getPropertySlot(*(int **)(param_1 + 0x18),param_2,0), *puVar7 != 0)) {
      return puVar7[2] + 1;
    }
  }
  uVar10 = 0;
  if (uVar2 != 0) {
    puVar5 = *(undefined4 **)(param_1 + 0xc);
    do {
      pbVar9 = *(byte **)*puVar5;
      pbVar8 = param_2;
      do {
        bVar1 = *pbVar8;
        bVar11 = bVar1 < *pbVar9;
        if (bVar1 != *pbVar9) {
LAB_68121ad0:
          iVar13 = (1 - (uint)bVar11) - (uint)(bVar11 != 0);
          goto LAB_68121ad5;
        }
        if (bVar1 == 0) break;
        bVar1 = pbVar8[1];
        bVar11 = bVar1 < pbVar9[1];
        if (bVar1 != pbVar9[1]) goto LAB_68121ad0;
        pbVar8 = pbVar8 + 2;
        pbVar9 = pbVar9 + 2;
      } while (bVar1 != 0);
      iVar13 = 0;
LAB_68121ad5:
      if (iVar13 == 0) {
        return uVar10 + 1;
      }
      uVar10 = uVar10 + 1;
      puVar5 = puVar5 + 1;
    } while (uVar10 < uVar2);
  }
  return 0;
}



// ============================================================
// Function: runtime_getSerializationEntryByIndex (FUN_68121b00)
// Address: 68121b00
// Size: 31 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getSerializationEntryByIndex(int param_1,int param_2)

{
  if (*(uint *)(param_1 + 0x10) <= param_2 - 1U) {
    return 0;
  }
  return *(undefined4 *)(*(int *)(param_1 + 0xc) + (param_2 - 1U) * 4);
}



// ============================================================
// Function: runtime_serializeByte (FUN_68121b20)
// Address: 68121b20
// Size: 50 bytes
// Params: int * param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeByte(int *param_1,byte *param_2)

{
  byte *pbVar1;
  int iVar2;
  
  pbVar1 = param_2;
  param_2 = (byte *)(uint)*param_2;
  iVar2 = runtime_serializeValue(param_1,&param_2);
  if (iVar2 == 0) {
    return 0;
  }
  *pbVar1 = (byte)param_2;
  return 1;
}



// ============================================================
// Function: runtime_serializeShort (FUN_68121b60)
// Address: 68121b60
// Size: 52 bytes
// Params: int * param_1, ushort * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeShort(int *param_1,ushort *param_2)

{
  ushort *puVar1;
  int iVar2;
  
  puVar1 = param_2;
  param_2 = (ushort *)(uint)*param_2;
  iVar2 = runtime_serializeValue(param_1,&param_2);
  if (iVar2 == 0) {
    return 0;
  }
  *puVar1 = (ushort)param_2;
  return 1;
}



// ============================================================
// Function: runtime_serializeScriptSource (FUN_68121ba0)
// Address: 68121ba0
// Size: 455 bytes
// Params: uint * param_1, int param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_serializeScriptSource(uint *param_1,int param_2,int param_3,uint *param_4,uint *param_5)
{
  uint *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_24;
  uint *local_20;
  uint local_1c;
  char local_18 [16];
  uint local_8;
  
  local_20 = param_1;
  iVar2 = xtra_callMethod(param_1,param_2,&PTR_s_Script_68192738,(int)param_4);
  if (iVar2 == 0) {
LAB_68121d3a:
    return 0;
  }
  puVar3 = (undefined4 *)xtra_getObjectTag(param_1,param_2);
  uVar4 = runtime_snprintf(local_18,0x10,"(new %s(");
  local_1c = uVar4 + 2;
  if (puVar3 == (undefined4 *)0x0) {
    uVar9 = 0;
    uVar8 = 0;
  }
  else {
    local_24 = 0;
    if ((((param_3 != 0) && (iVar2 = runtime_parseFloat((ushort *)param_1,*param_4,&local_24), iVar2 == 0)
         ) || (puVar5 = xtra_createProperty((int)param_1,puVar3,"Script.prototype.toSource",local_24),
              puVar5 == (uint *)0x0)) ||
       (puVar5 = crypto_createUnaryOp(param_1,puVar5,0x27), puVar5 == (uint *)0x0)) goto LAB_68121d3a;
    uVar8 = *puVar5;
    if ((uVar8 & 0x40000000) == 0) {
      uVar8 = puVar5[1];
    }
    else {
      puVar1 = (uint *)puVar5[1];
      if ((*puVar1 & 0x40000000) == 0) {
        if ((int)uVar8 < 0) {
          uVar8 = puVar1[1];
        }
        else {
          uVar8 = puVar1[1] + (uVar8 >> 0xf & 0x7fff) * 2;
        }
      }
      else {
        uVar8 = crypto_getStringLen(puVar5);
      }
    }
    uVar9 = *puVar5;
    if ((uVar9 & 0x40000000) != 0) {
      uVar9 = (-(uint)((uVar9 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar9;
    }
    local_1c = local_1c + uVar9;
  }
  uVar6 = xtra_getPropertyById((int)local_20,local_1c * 2 + 2);
  puVar5 = local_20;
  uVar7 = 0;
  if (uVar6 != 0) {
    if (uVar4 != 0) {
      do {
        *(short *)(uVar6 + uVar7 * 2) = (short)local_18[uVar7];
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar4);
    }
    uVar4 = 0;
    if (uVar9 != 0) {
      do {
        *(undefined2 *)(uVar6 + uVar7 * 2) = *(undefined2 *)(uVar8 + uVar4 * 2);
        uVar4 = uVar4 + 1;
        uVar7 = uVar7 + 1;
      } while (uVar4 < uVar9);
    }
    *(undefined4 *)(uVar6 + uVar7 * 2) = 0x290029;
    *(undefined2 *)(uVar6 + 4 + uVar7 * 2) = 0;
    uVar4 = xtra_allocHashEntryDirect((int)local_20,uVar6,local_1c);
    if (uVar4 == 0) {
      xtra_checkAndFlush(puVar5,uVar6);
      goto LAB_68121d3a;
    }
    *param_5 = uVar4 | 4;
  }
  return 0;
}



// ============================================================
// Function: runtime_getScriptString (FUN_68121d70)
// Address: 68121d70
// Size: 151 bytes
// Params: ushort * param_1, int param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getScriptString(ushort *param_1,int param_2,int param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  uint *puVar3;
  
  puVar3 = param_4;
  iVar1 = xtra_callMethod(param_1,param_2,&PTR_s_Script_68192738,(int)param_4);
  if (iVar1 != 0) {
    puVar2 = (undefined4 *)xtra_getObjectTag(param_1,param_2);
    if (puVar2 == (undefined4 *)0x0) {
      *param_5 = *(uint *)(*(int *)(param_1 + 10) + 0x1dc) | 4;
      return 1;
    }
    param_4 = (uint *)0x0;
    if ((param_3 != 0) && (iVar1 = runtime_parseFloat(param_1,*puVar3,&param_4), iVar1 == 0)) {
      return 0;
    }
    puVar3 = xtra_createProperty((int)param_1,puVar2,"Script.prototype.toString",(uint)param_4);
    if (puVar3 != (uint *)0x0) {
      *param_5 = (uint)puVar3 | 4;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_evaluateScript (FUN_68121e10)
// Address: 68121e10
// Size: 149 bytes
// Params: uint param_1, int param_2, int param_3, uint * param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_evaluateScript(uint param_1,int param_2,int param_3,uint *param_4,undefined4 param_5)

{
  int iVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  
  puVar2 = param_4;
  iVar3 = xtra_callMethod(param_1,param_2,&PTR_s_Script_68192738,(int)param_4);
  if (iVar3 == 0) {
    return 0;
  }
  uVar4 = xtra_getObjectTag(param_1,param_2);
  if (uVar4 != 0) {
    param_4 = (uint *)0x0;
    if (param_3 != 0) {
      iVar3 = runtime_deleteProperty(param_1,*puVar2,(uint *)&param_4);
      if (iVar3 == 0) {
        return 0;
      }
      *puVar2 = (uint)param_4;
    }
    iVar3 = *(int *)(param_1 + 0x34);
    iVar1 = *(int *)(iVar3 + 0x2c);
    if (param_4 == (uint *)0x0) {
      param_4 = *(uint **)(iVar1 + 0x34);
    }
    *(undefined4 *)(iVar3 + 0x14) = *(undefined4 *)(iVar1 + 0x14);
    *(undefined4 *)(iVar3 + 0x48) = *(undefined4 *)(iVar1 + 0x48);
    uVar5 = certs_processExtension(param_1,(uint)param_4,uVar4,iVar3,0,param_5);
    return uVar5;
  }
  return 1;
}



// ============================================================
// Function: runtime_serializeCompiledValue (FUN_68121eb0)
// Address: 68121eb0
// Size: 102 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeCompiledValue(void)

{
  int iVar1;
  int *unaff_ESI;
  int unaff_EDI;
  uint local_c;
  undefined4 local_8;
  
  if (*unaff_ESI == 0) {
    local_c = *(uint *)(*(int *)(unaff_EDI + 8) + 8);
  }
  local_8 = *(undefined4 *)(unaff_EDI + 0xc);
  iVar1 = runtime_serializeValue(unaff_ESI,&local_8);
  if (iVar1 != 0) {
    *(undefined4 *)(unaff_EDI + 0xc) = local_8;
    iVar1 = runtime_serializeTaggedValue(unaff_ESI,&local_c);
    if (iVar1 != 0) {
      if (*unaff_ESI == 1) {
        iVar1 = javascript_gcSweepValue(unaff_ESI[2],local_c,0);
        *(int *)(unaff_EDI + 8) = iVar1;
        if (iVar1 == 0) {
          return 0;
        }
      }
      return 1;
    }
  }
  return 0;
}



