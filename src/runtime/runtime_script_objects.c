// Module: runtime
// Topic: Script objects, property operations, prototype chains, and class setup
// Address range: 0x68121f20 - 0x68124660
// Functions (55):
//   runtime_serializeObjectTable
//   runtime_evaluateScriptProperty
//   runtime_allocPropertyBlock
//   runtime_invokeDebugCallback
//   runtime_getObjectPrototype
//   runtime_freeObjectSlots
//   runtime_getObjectSlot
//   runtime_getObjectField
//   runtime_computeObjectSize
//   runtime_constructScript
//   runtime_resolvePrototype
//   runtime_serializeScriptObject
//   runtime_deserializeScriptObject
//   runtime_releaseObjectPrototype
//   runtime_freeObjectSlotsWrapper
//   runtime_constructScriptDefault
//   runtime_deserializeScriptDefault
//   runtime_initScriptPrototype
//   runtime_createPropertyBlockWithData
//   runtime_loadExternalScript
//   runtime_duplicateProperties
//   runtime_isPrototypeOf
//   runtime_enumerateProperties
//   runtime_getOrCreateObjectPrototype
//   runtime_objectValueOf
//   runtime_objectHasOwnProperty
//   runtime_objectPropertyIsEnumerable
//   runtime_objectToString
//   runtime_objectDefaultValue
//   runtime_createPrototypeChain
//   runtime_getPrototypeProperty
//   runtime_setPrototypeProperty
//   runtime_createObject
//   runtime_deletePrototypeProperty
//   runtime_enumerateObject
//   runtime_resolveObjectProperty
//   runtime_hasOwnPropertyCheck
//   runtime_getCallableProperty
//   runtime_convertToObject
//   runtime_freeObjectAndPrototype
//   runtime_resolveCallable
//   runtime_freeObjectCompletely
//   runtime_resolveConstructor
//   runtime_callConstructor
//   runtime_callConstructorNew
//   runtime_applyFunction
//   runtime_callApplyFunction
//   runtime_isValidIdentifier
//   runtime_initArgumentsPrototype
//   runtime_bindPrototype
//   runtime_callObjectMethod
//   runtime_createObjectFromPrototype
//   runtime_initObjectProperties
//   runtime_initObjectInstance
//   runtime_getFunctionProperty

// ============================================================
// Function: runtime_serializeObjectTable (FUN_68121f20)
// Address: 68121f20
// Size: 430 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_serializeObjectTable(int *param_1)

{
  uint uVar1;
  int *in_EAX;
  int iVar2;
  int *piVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  int *local_1c;
  undefined4 local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  int local_8;
  
  if (*in_EAX == 0) {
    local_c = param_1[1];
  }
  iVar2 = runtime_serializeValue(in_EAX,&local_c);
  if (iVar2 == 0) {
    return 0;
  }
  if (*in_EAX != 1) {
    if ((*in_EAX == 0) && (uVar6 = 0, param_1[1] != 0)) {
      do {
        local_18 = *(undefined4 *)(*param_1 + uVar6 * 4);
        local_14 = uVar6;
        iVar2 = runtime_serializeCompiledValue();
        if (iVar2 == 0) {
          return 0;
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < (uint)param_1[1]);
    }
    return 1;
  }
  uVar6 = in_EAX[2];
  local_8 = *(int *)(*(int *)(uVar6 + 0x80) + 0xc);
  local_1c = (int *)0x0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  if (local_c != 0) {
    do {
      iVar2 = *(int *)(uVar6 + 0x80);
      piVar3 = *(int **)(iVar2 + 0xc);
      uVar5 = *(uint *)(uVar6 + 0x88) + 0x10 & ~*(uint *)(uVar6 + 0x88);
      uVar1 = (int)piVar3 + uVar5;
      if (*(uint *)(iVar2 + 8) < uVar1) {
        piVar3 = (int *)js_getSlotIndex(uVar6 + 0x70,uVar5);
      }
      else {
        *(uint *)(iVar2 + 0xc) = uVar1;
      }
      if (piVar3 == (int *)0x0) {
        xtra_reportError(uVar6);
LAB_6812202b:
        piVar3 = *(int **)(uVar6 + 0x80);
        if ((piVar3 != (int *)(uVar6 + 0x70)) &&
           ((uint)(local_8 - piVar3[1]) <= (uint)(piVar3[3] - piVar3[1]))) {
          piVar3[3] = *(uint *)(uVar6 + 0x88) + local_8 & ~*(uint *)(uVar6 + 0x88);
          return 0;
        }
        js_getPrototype((int *)(uVar6 + 0x70),local_8);
        return 0;
      }
      iVar2 = runtime_serializeCompiledValue();
      if (iVar2 == 0) goto LAB_6812202b;
      *piVar3 = (int)local_1c;
      local_14 = local_14 + 1;
      local_10 = local_10 + 1;
      local_1c = piVar3;
    } while (local_10 < local_c);
  }
  uVar4 = javascript_atomTableSerialize(uVar6,param_1,(int *)&local_1c);
  piVar3 = *(int **)(uVar6 + 0x80);
  if ((piVar3 != (int *)(uVar6 + 0x70)) &&
     ((uint)(local_8 - piVar3[1]) <= (uint)(piVar3[3] - piVar3[1]))) {
    piVar3[3] = *(uint *)(uVar6 + 0x88) + local_8 & ~*(uint *)(uVar6 + 0x88);
    return uVar4;
  }
  js_getPrototype((int *)(uVar6 + 0x70),local_8);
  return uVar4;
}



// ============================================================
// Function: runtime_evaluateScriptProperty (FUN_681220e0)
// Address: 681220e0
// Size: 35 bytes
// Params: uint param_1, undefined4 param_2, int param_3, uint * param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_evaluateScriptProperty(uint param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 param_5)
{
  runtime_evaluateScript(param_1,param_4[-2] & 0xfffffff8,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_allocPropertyBlock (FUN_68122110)
// Address: 68122110
// Size: 74 bytes
// Params: int param_1, int param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_allocPropertyBlock(int param_1,int param_2)

{
  int *_Dst;
  
  _Dst = (int *)xtra_getPropertyById(param_1,param_2 + 0x3c);
  if (_Dst == (int *)0x0) {
    return (int *)0x0;
  }
  memset(_Dst,0,0x3c);
  _Dst[2] = (int)(_Dst + 0xf);
  *_Dst = (int)(_Dst + 0xf);
  _Dst[1] = param_2;
  _Dst[3] = *(int *)(param_1 + 0xc);
  return _Dst;
}



// ============================================================
// Function: runtime_invokeDebugCallback (FUN_68122160)
// Address: 68122160
// Size: 97 bytes
// Params: int param_1, int param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_invokeDebugCallback(int param_1,int param_2,undefined4 param_3)
{
  int iVar1;
  code *pcVar2;
  undefined1 local_5c [12];
  int local_50;
  undefined4 local_30;
  
  iVar1 = *(int *)(param_1 + 0x14);
  pcVar2 = *(code **)(iVar1 + 0x1f0);
  if (pcVar2 != (code *)0x0) {
    memset(local_5c,0,0x58);
    local_30 = *(undefined4 *)(param_1 + 0x34);
    *(undefined1 **)(param_1 + 0x34) = local_5c;
    local_50 = param_2;
    (*pcVar2)(param_1,*(undefined4 *)(param_2 + 0x18),*(undefined4 *)(param_2 + 0x1c),param_2,
              param_3,*(undefined4 *)(iVar1 + 500));
    *(undefined4 *)(param_1 + 0x34) = local_30;
  }
  return 0;
}



// ============================================================
// Function: runtime_getObjectPrototype (FUN_681221d0)
// Address: 681221d0
// Size: 119 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_getObjectPrototype(int param_1,int param_2)
{
  int *piVar1;
  code *pcVar2;
  
  pcVar2 = *(code **)(*(int *)(param_1 + 0x14) + 0x1f8);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(param_1,param_2,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x1fc));
  }
  runtime_removeBreakpointsForScript(param_1,param_2);
  javascript_atomTableFree(param_1,(int *)(param_2 + 0x10));
  xtra_checkAndFlush(param_1,*(int *)(param_2 + 0x18));
  xtra_checkAndFlush(param_1,*(int *)(param_2 + 0x24));
  xtra_checkAndFlush(param_1,*(int *)(param_2 + 0x28));
  if (*(int *)(param_2 + 0x2c) != 0) {
    piVar1 = (int *)(*(int *)(param_2 + 0x2c) + 0xc);
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      (**(code **)(*(int *)(param_2 + 0x2c) + 0x10))(param_1,*(int *)(param_2 + 0x2c));
    }
  }
  xtra_checkAndFlush(param_1,param_2);
  return 0;
}



// ============================================================
// Function: runtime_freeObjectSlots (FUN_68122250)
// Address: 68122250
// Size: 56 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_freeObjectSlots(undefined4 param_1,int param_2)
{
  int iVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  iVar1 = *(int *)(param_2 + 0x10);
  uVar2 = *(uint *)(param_2 + 0x14);
  uVar4 = 0;
  if (uVar2 != 0) {
    do {
      iVar3 = *(int *)(iVar1 + uVar4 * 4);
      if ((*(byte *)(iVar3 + 0x10) & 4) == 0) {
        js_allocAtomSlot(param_1,iVar3);
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar2);
  }
  return 0;
}



// ============================================================
// Function: runtime_getObjectSlot (FUN_68122290)
// Address: 68122290
// Size: 158 bytes
// Params: int param_1, int param_2
// Return: byte *
// Calling convention: __stdcall
// ============================================================

byte * runtime_getObjectSlot(int param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  
  pbVar6 = *(byte **)(param_1 + 0x24);
  if (pbVar6 == (byte *)0x0) {
    return (byte *)0x0;
  }
  uVar5 = param_2 - *(int *)(param_1 + 8);
  if (*(uint *)(param_1 + 4) <= uVar5) {
    return (byte *)0x0;
  }
  bVar1 = *pbVar6;
  uVar7 = 0;
  do {
    if (bVar1 == 0) {
      return (byte *)0x0;
    }
    bVar4 = bVar1 >> 3;
    if (bVar4 < 0x18) {
      uVar2 = bVar1 & 7;
    }
    else {
      uVar2 = bVar1 & 0x3f;
    }
    uVar7 = uVar7 + uVar2;
    if (uVar7 == uVar5) {
      if (bVar4 < 0x18) {
        if (bVar1 >> 3 < 0x16) {
          return pbVar6;
        }
        goto LAB_681222ee;
      }
LAB_681222f3:
      uVar2 = 0x18;
    }
    else {
LAB_681222ee:
      if (0x17 < bVar4) goto LAB_681222f3;
      uVar2 = (uint)(bVar1 >> 3);
    }
    if ((&DAT_68193b74)[uVar2 * 8] == '\0') {
      iVar3 = 1;
    }
    else {
      iVar3 = js_getObjectType(pbVar6);
    }
    pbVar6 = pbVar6 + iVar3;
    bVar1 = *pbVar6;
  } while( true );
}



// ============================================================
// Function: runtime_getObjectField (FUN_68122330)
// Address: 68122330
// Size: 185 bytes
// Params: uint param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_getObjectField(uint param_1,int param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  
  pbVar5 = *(byte **)(param_1 + 0x24);
  if (pbVar5 == (byte *)0x0) {
    return 0;
  }
  iVar6 = param_2 - *(int *)(param_1 + 8);
  param_1 = *(uint *)(param_1 + 0x1c);
  bVar1 = *pbVar5;
  iVar4 = 0;
  while( true ) {
    if (bVar1 == 0) {
      return param_1;
    }
    if (bVar1 >> 3 < 0x18) {
      uVar2 = bVar1 & 7;
    }
    else {
      uVar2 = bVar1 & 0x3f;
    }
    iVar4 = iVar4 + uVar2;
    if (bVar1 >> 3 < 0x18) {
      if (bVar1 >> 3 == 0x17) {
        if (iVar6 < iVar4) {
          return param_1;
        }
        param_1 = js_getObjectFlags((int)pbVar5,0);
      }
      else if (bVar1 >> 3 == 0x16) {
        if (iVar6 < iVar4) {
          return param_1;
        }
        param_1 = param_1 + 1;
      }
    }
    if (iVar6 < iVar4) break;
    if ((*pbVar5 & 0xf8) < 0xc0) {
      uVar2 = (uint)(*pbVar5 >> 3);
    }
    else {
      uVar2 = 0x18;
    }
    if ((&DAT_68193b74)[uVar2 * 8] == '\0') {
      iVar3 = 1;
    }
    else {
      iVar3 = js_getObjectType(pbVar5);
    }
    pbVar5 = pbVar5 + iVar3;
    bVar1 = *pbVar5;
  }
  return param_1;
}



// ============================================================
// Function: runtime_computeObjectSize (FUN_681223f0)
// Address: 681223f0
// Size: 166 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_computeObjectSize(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte *pbVar6;
  
  pbVar6 = *(byte **)(param_1 + 0x24);
  if (pbVar6 != (byte *)0x0) {
    uVar3 = *(uint *)(param_1 + 0x1c);
    bVar1 = *pbVar6;
    iVar5 = 0;
    while ((bVar1 != 0 && (uVar3 < param_2))) {
      if (bVar1 >> 3 < 0x18) {
        uVar2 = bVar1 & 7;
      }
      else {
        uVar2 = bVar1 & 0x3f;
      }
      iVar5 = iVar5 + uVar2;
      if (bVar1 >> 3 < 0x18) {
        if (bVar1 >> 3 == 0x17) {
          uVar3 = js_getObjectFlags((int)pbVar6,0);
        }
        else if (bVar1 >> 3 == 0x16) {
          uVar3 = uVar3 + 1;
        }
      }
      if ((*pbVar6 & 0xf8) < 0xc0) {
        uVar2 = (uint)(*pbVar6 >> 3);
      }
      else {
        uVar2 = 0x18;
      }
      if ((&DAT_68193b74)[uVar2 * 8] == '\0') {
        iVar4 = 1;
      }
      else {
        iVar4 = js_getObjectType(pbVar6);
      }
      pbVar6 = pbVar6 + iVar4;
      bVar1 = *pbVar6;
    }
    return *(int *)(param_1 + 8) + iVar5;
  }
  return 0;
}



// ============================================================
// Function: runtime_constructScript (FUN_681224a0)
// Address: 681224a0
// Size: 384 bytes
// Params: uint * param_1, int param_2, uint param_3, uint * param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_constructScript(uint *param_1,int param_2,uint param_3,uint *param_4,int *param_5)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined4 uVar9;
  int local_8;
  
  puVar1 = param_4;
  iVar2 = xtra_callMethod(param_1,param_2,&PTR_s_Script_68192738,(int)param_4);
  if (iVar2 == 0) {
    return 0;
  }
  if (param_3 == 0) goto LAB_6812260a;
  puVar3 = (uint *)certs_hashLookup((int)param_1,*puVar1);
  if (puVar3 == (uint *)0x0) {
    return 0;
  }
  iVar2 = *(int *)(param_1[0xd] + 0x2c);
  param_4 = (uint *)0x0;
  if (param_3 < 2) {
LAB_6812251f:
    param_4 = *(uint **)(iVar2 + 0x34);
  }
  else {
    iVar4 = runtime_deleteProperty((uint)param_1,puVar1[1],(uint *)&param_4);
    if (iVar4 == 0) {
      return 0;
    }
    puVar1[1] = (uint)param_4;
    if (param_4 == (uint *)0x0) goto LAB_6812251f;
  }
  uVar9 = 0;
  if (*(int *)(iVar2 + 0xc) == 0) {
    param_3 = 0;
    local_8 = 0;
  }
  else {
    uVar9 = *(undefined4 *)(*(uint *)(iVar2 + 0xc) + 0x18);
    param_3 = runtime_getObjectField(*(uint *)(iVar2 + 0xc),*(int *)(iVar2 + 0x38));
    local_8 = *(int *)(*(int *)(iVar2 + 0xc) + 0x2c);
  }
  uVar7 = *puVar3;
  if ((uVar7 & 0x40000000) == 0) {
    uVar5 = puVar3[1];
  }
  else {
    uVar8 = (-(uint)((uVar7 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar7;
    puVar1 = (uint *)puVar3[1];
    if ((*puVar1 & 0x40000000) == 0) {
      if ((int)uVar7 < 0) {
        uVar5 = puVar1[1];
        uVar7 = uVar8;
      }
      else {
        uVar5 = puVar1[1] + (uVar7 >> 0xf & 0x7fff) * 2;
        uVar7 = uVar8;
      }
    }
    else {
      uVar5 = crypto_getStringLen(puVar3);
      uVar7 = uVar8;
    }
  }
  piVar6 = xtra_evalScriptBuffer(param_1,(int *)param_4,local_8,uVar5,uVar7,uVar9,param_3);
  if (piVar6 != (int *)0x0) {
    uVar7 = xtra_getObjectTag(param_1,param_2);
    iVar2 = xtra_getResourceById(param_1,param_2,(uint)piVar6);
    if (iVar2 != 0) {
      if (uVar7 != 0) {
        runtime_getObjectPrototype((int)param_1,uVar7);
      }
      piVar6[0xc] = param_2;
LAB_6812260a:
      *param_5 = param_2;
      return 1;
    }
    runtime_getObjectPrototype((int)param_1,(int)piVar6);
  }
  return 0;
}



// ============================================================
// Function: runtime_resolvePrototype (FUN_68122620)
// Address: 68122620
// Size: 972 bytes
// Params: int * param_1, int * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_resolvePrototype(int *param_1,int *param_2,undefined4 *param_3)

{
  undefined4 *puVar1;
  byte bVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  byte *pbVar8;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  byte *local_10;
  undefined *local_c;
  int local_8;
  
  piVar4 = param_1;
  piVar7 = (int *)*param_2;
  local_8 = 0;
  if (*param_1 == 0) {
    param_1 = (int *)0xdead0003;
  }
  iVar5 = runtime_serializeValue(piVar4,&param_1);
  if (iVar5 == 0) {
    return 0;
  }
  if (((param_1 != (int *)0xdead0003) && (param_1 != (int *)0xdead0002)) &&
     (param_1 != (int *)0xdead0001)) {
    if (param_3 == (undefined4 *)0x0) {
      xtra_invokeMethod(piVar4[2],xtra_getErrorString,0,0x44);
      return 0;
    }
    *param_3 = 0;
    return 1;
  }
  if (param_3 != (undefined4 *)0x0) {
    *param_3 = 1;
  }
  if (*piVar4 == 0) {
    local_c = (undefined *)piVar7[1];
    pbVar8 = (byte *)piVar7[9];
    local_18 = piVar7[2] - *piVar7;
    local_1c = piVar7[3];
    local_20 = piVar7[7];
    local_24 = piVar7[8];
    if (piVar7[10] != 0) {
      iVar5 = *(int *)(piVar7[10] + 8 + local_8 * 0xc);
      while (iVar5 != 0) {
        local_8 = local_8 + 1;
        iVar5 = *(int *)(piVar7[10] + 8 + local_8 * 0xc);
      }
      local_8 = local_8 + 1;
    }
    bVar2 = *pbVar8;
    while (bVar2 != 0) {
      if ((bVar2 & 0xf8) < 0xc0) {
        uVar6 = (uint)(bVar2 >> 3);
      }
      else {
        uVar6 = 0x18;
      }
      if ((&DAT_68193b74)[uVar6 * 8] == '\0') {
        iVar5 = 1;
      }
      else {
        iVar5 = js_getObjectType(pbVar8);
      }
      pbVar8 = pbVar8 + iVar5;
      bVar2 = *pbVar8;
    }
    local_10 = pbVar8 + (1 - piVar7[9]);
  }
  iVar5 = runtime_serializeValue(piVar4,&local_c);
  if (iVar5 == 0) {
    return 0;
  }
  if ((int *)0xdead0001 < param_1) {
    iVar5 = runtime_serializeValue(piVar4,&local_18);
    if (iVar5 == 0) {
      return 0;
    }
    iVar5 = runtime_serializeValue(piVar4,&local_1c);
    if (iVar5 == 0) {
      return 0;
    }
  }
  if (*piVar4 == 1) {
    piVar7 = runtime_allocPropertyBlock(piVar4[2],(int)local_c);
    if (piVar7 == (int *)0x0) {
      return 0;
    }
    if ((int *)0xdead0001 < param_1) {
      piVar7[2] = piVar7[2] + local_18;
      piVar7[3] = local_1c;
    }
    *param_2 = (int)piVar7;
  }
  iVar5 = runtime_serializeString(piVar4,piVar7,local_c);
  if (((iVar5 != 0) && (iVar5 = runtime_serializeObjectTable(piVar7 + 4), iVar5 != 0)) &&
     (iVar5 = runtime_serializeValue(piVar4,&local_10), iVar5 != 0)) {
    if (*piVar4 != 0) {
      iVar5 = xtra_getPropertyById(piVar4[2],(int)local_10);
      piVar7[9] = iVar5;
      if (iVar5 == 0) goto LAB_681228c1;
    }
    iVar5 = runtime_serializeString(piVar4,piVar7 + 9,local_10);
    if (((iVar5 != 0) && (iVar5 = runtime_serializeOptionalString(piVar4,piVar7 + 6), iVar5 != 0)) &&
       ((iVar5 = runtime_serializeValue(piVar4,&local_20), iVar5 != 0 &&
        ((iVar5 = runtime_serializeValue(piVar4,&local_24), iVar5 != 0 &&
         (iVar5 = runtime_serializeValue(piVar4,&local_8), iVar5 != 0)))))) {
      if ((int *)0xdead0002 < param_1) {
        if (*piVar4 == 0) {
          local_14 = piVar7[0xb];
          param_3 = (undefined4 *)(uint)(*(int *)(*(int *)(piVar4[2] + 0x14) + 0x2258) != 0);
          iVar5 = runtime_serializeValue(piVar4,&param_3);
          if ((iVar5 == 0) ||
             ((param_3 != (undefined4 *)0x0 &&
              (iVar5 = (**(code **)(*(int *)(piVar4[2] + 0x14) + 0x2258))(piVar4,&local_14),
              iVar5 == 0)))) goto LAB_681228c1;
        }
        else {
          iVar5 = runtime_serializeValue(piVar4,&param_3);
          if (iVar5 == 0) goto LAB_681228c1;
          if (param_3 != (undefined4 *)0x0) {
            pcVar3 = *(code **)(*(int *)(piVar4[2] + 0x14) + 0x2258);
            if (pcVar3 == (code *)0x0) {
              xtra_invokeMethod(piVar4[2],xtra_getErrorString,0,0xa7);
              goto LAB_681228c1;
            }
            iVar5 = (*pcVar3)(piVar4,&local_14);
            if (iVar5 == 0) goto LAB_681228c1;
            piVar7[0xb] = local_14;
          }
        }
      }
      if (*piVar4 == 1) {
        piVar7[7] = local_20;
        piVar7[8] = local_24;
        if (local_8 == 0) {
          piVar7[10] = 0;
        }
        else {
          iVar5 = xtra_getPropertyById(piVar4[2],(local_8 * 3 + 3) * 4);
          piVar7[10] = iVar5;
          if (iVar5 == 0) goto LAB_681228c1;
        }
      }
      while( true ) {
        if (local_8 == 0) {
          return 1;
        }
        param_3 = *(undefined4 **)(piVar7[10] + -0xc + local_8 * 0xc);
        puVar1 = (undefined4 *)(piVar7[10] + -0xc + local_8 * 0xc);
        local_14 = puVar1[1];
        local_28 = puVar1[2];
        iVar5 = runtime_serializeValue(piVar4,&param_3);
        if (((iVar5 == 0) || (iVar5 = runtime_serializeValue(piVar4,&local_14), iVar5 == 0)) ||
           (iVar5 = runtime_serializeValue(piVar4,&local_28), iVar5 == 0)) break;
        *puVar1 = param_3;
        puVar1[1] = local_14;
        puVar1[2] = local_28;
        local_8 = local_8 + -1;
      }
    }
  }
LAB_681228c1:
  if (*piVar4 == 1) {
    runtime_getObjectPrototype(piVar4[2],(int)piVar7);
    *param_2 = 0;
  }
  return 0;
}



// ============================================================
// Function: runtime_serializeScriptObject (FUN_681229f0)
// Address: 681229f0
// Size: 203 bytes
// Params: int param_1, uint param_2, undefined4 param_3, uint param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_serializeScriptObject(int param_1,uint param_2,undefined4 param_3,uint param_4,uint *param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  void *pvVar4;
  uint uVar5;
  
  uVar5 = param_2;
  iVar1 = param_1;
  iVar2 = xtra_callMethod(param_1,param_2,&PTR_s_Script_68192738,param_4);
  if (iVar2 != 0) {
    param_2 = xtra_getObjectTag(iVar1,uVar5);
    if (param_2 == 0) {
      return 1;
    }
    piVar3 = runtime_getSerializedEntry(iVar1,0);
    if (piVar3 != (int *)0x0) {
      iVar2 = runtime_resolvePrototype(piVar3,(int *)&param_2,&param_1);
      if (iVar2 == 0) {
LAB_68122aac:
        runtime_beginSerialization((int)piVar3);
        return iVar2;
      }
      if (param_1 == 0) {
        *param_5 = 0x80000001;
        runtime_beginSerialization((int)piVar3);
        return iVar2;
      }
      pvVar4 = (void *)runtime_validateStream((int)piVar3,&param_4);
      if (pvVar4 != (void *)0x0) {
        param_4 = param_4 >> 1;
        uVar5 = xtra_allocFromPool(iVar1,pvVar4,param_4);
        if (uVar5 != 0) {
          *param_5 = uVar5 | 4;
          goto LAB_68122aac;
        }
      }
      runtime_beginSerialization((int)piVar3);
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_deserializeScriptObject (FUN_68122ac0)
// Address: 68122ac0
// Size: 266 bytes
// Params: uint param_1, int param_2, int param_3, uint * param_4, undefined4 * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_deserializeScriptObject(uint param_1,int param_2,int param_3,uint *param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  
  puVar3 = param_4;
  uVar1 = param_1;
  iVar2 = xtra_callMethod(param_1,param_2,&PTR_s_Script_68192738,(int)param_4);
  if (iVar2 != 0) {
    if (param_3 == 0) {
      return 1;
    }
    puVar3 = (uint *)certs_hashLookup(uVar1,*puVar3);
    if (puVar3 != (uint *)0x0) {
      piVar4 = runtime_getSerializedEntry(uVar1,1);
      if (piVar4 == (int *)0x0) {
        return 0;
      }
      param_4 = (uint *)xtra_getStringData(puVar3);
      uVar5 = xtra_getStringLength(puVar3);
      runtime_writeSerializedData((int)piVar4,param_4,uVar5 * 2);
      iVar6 = runtime_resolvePrototype(piVar4,(int *)&param_4,&param_1);
      iVar2 = param_2;
      if (iVar6 != 0) {
        if (param_1 == 0) {
          *param_5 = 6;
        }
        else {
          param_1 = xtra_getObjectTag(uVar1,param_2);
          iVar6 = xtra_getResourceById(uVar1,iVar2,(uint)param_4);
          if (iVar6 == 0) {
            xtra_checkAndFlush(uVar1,(int)param_4);
          }
          else {
            if (param_1 != 0) {
              runtime_getObjectPrototype(uVar1,param_1);
            }
            param_4[0xc] = param_2;
            runtime_invokeDebugCallback(uVar1,(int)param_4,0);
          }
        }
      }
      runtime_writeSerializedData((int)piVar4,0,0);
      runtime_beginSerialization((int)piVar4);
      *param_5 = 0xe;
      return iVar6;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_releaseObjectPrototype (FUN_68122bd0)
// Address: 68122bd0
// Size: 33 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_releaseObjectPrototype(int param_1,int param_2)
{
  uint uVar1;
  
  uVar1 = xtra_getObjectTag(param_1,param_2);
  if (uVar1 != 0) {
    runtime_getObjectPrototype(param_1,uVar1);
  }
  return 0;
}



// ============================================================
// Function: runtime_freeObjectSlotsWrapper (FUN_68122c00)
// Address: 68122c00
// Size: 39 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_freeObjectSlotsWrapper(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = xtra_getObjectTag(param_1,param_2);
  if (uVar1 != 0) {
    runtime_freeObjectSlots(param_1,uVar1);
  }
  return 0;
}



// ============================================================
// Function: runtime_constructScriptDefault (FUN_68122c30)
// Address: 68122c30
// Size: 67 bytes
// Params: uint * param_1, int * param_2, uint param_3, uint * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_constructScriptDefault(uint *param_1,int *param_2,uint param_3,uint *param_4,int *param_5)
{
  if (((*(byte *)(param_1[0xd] + 0x4c) & 1) == 0) &&
     (param_2 = runtime_setProperty((int)param_1,&PTR_s_Script_68192738,(undefined4 *)0x0,0),
     param_2 == (int *)0x0)) {
    return 0;
  }
  runtime_constructScript(param_1,(int)param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_deserializeScriptDefault (FUN_68122c80)
// Address: 68122c80
// Size: 80 bytes
// Params: uint param_1, undefined4 param_2, int param_3, uint * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_deserializeScriptDefault(uint param_1,undefined4 param_2,int param_3,uint *param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = runtime_setProperty(param_1,&PTR_s_Script_68192738,(undefined4 *)0x0,0);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = runtime_deserializeScriptObject(param_1,(int)piVar1,param_3,param_4,param_5);
  if (iVar2 == 0) {
    return 0;
  }
  *param_5 = piVar1;
  return 1;
}



// ============================================================
// Function: runtime_initScriptPrototype (FUN_68122cd0)
// Address: 68122cd0
// Size: 48 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_initScriptPrototype(int param_1,int *param_2)
{
  xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_s_Script_68192738,0x68122c30,1,(int *)0x0,
               (int *)&PTR_s_toSource_681926e0,(int *)0x0,(int *)&PTR_DAT_68192780);
  return 0;
}



// ============================================================
// Function: runtime_createPropertyBlockWithData (FUN_68122d00)
// Address: 68122d00
// Size: 150 bytes
// Params: int param_1, void * param_2, size_t param_3, void * param_4, size_t param_5, char * param_6, int param_7, int param_8, int param_9, int param_10, int param_11
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_createPropertyBlockWithData(int param_1,void *param_2,size_t param_3,void *param_4,size_t param_5,
                  char *param_6,int param_7,int param_8,int param_9,int param_10,int param_11)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = runtime_allocPropertyBlock(param_1,param_3 + param_5);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar1[2] = piVar1[2] + param_5;
  memcpy((void *)*piVar1,param_4,param_5);
  memcpy((void *)piVar1[2],param_2,param_3);
  if (param_6 != (char *)0x0) {
    iVar2 = xtra_findMethodByName(param_1,param_6);
    piVar1[6] = iVar2;
    if (iVar2 == 0) {
      runtime_getObjectPrototype(param_1,(int)piVar1);
      return (int *)0x0;
    }
  }
  piVar1[7] = param_7;
  piVar1[10] = param_10;
  piVar1[8] = param_8;
  piVar1[9] = param_9;
  if (param_11 != 0) {
    *(int *)(param_11 + 0xc) = *(int *)(param_11 + 0xc) + 1;
  }
  piVar1[0xb] = param_11;
  return piVar1;
}



// ============================================================
// Function: runtime_loadExternalScript (FUN_68122da0)
// Address: 68122da0
// Size: 160 bytes
// Params: uint param_1, int param_2, undefined4 param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_loadExternalScript(uint param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  void *pvVar2;
  int *piVar3;
  int iVar4;
  
  iVar4 = param_2;
  iVar1 = javascript_objectSetPrototype(param_1,param_2,&param_2);
  if (iVar1 == 0) {
    return (int *)0x0;
  }
  pvVar2 = javascript_objectClone(param_1,iVar4);
  piVar3 = *(int **)(iVar4 + 0x40);
  piVar3 = runtime_createPropertyBlockWithData(param_1,(void *)*piVar3,piVar3[2] - *piVar3,*(void **)(iVar4 + 0x28),
                        *(int *)(iVar4 + 0x30) - (int)*(void **)(iVar4 + 0x28),
                        *(char **)(iVar4 + 0x44),*(int *)(iVar4 + 0x48),*(int *)(iVar4 + 100),
                        (int)pvVar2,param_2,*(int *)(iVar4 + 0x50));
  if (piVar3 != (int *)0x0) {
    if (pvVar2 != (void *)0x0) {
      iVar4 = javascript_atomTableSerialize(param_1,piVar3 + 4,(int *)(iVar4 + 0x54));
      if (iVar4 != 0) {
        runtime_invokeDebugCallback(param_1,(int)piVar3,param_3);
        return piVar3;
      }
    }
    runtime_getObjectPrototype(param_1,(int)piVar3);
  }
  return (int *)0x0;
}



// ============================================================
// Function: runtime_duplicateProperties (FUN_68122e40)
// Address: 68122e40
// Size: 226 bytes
// Params: uint param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_duplicateProperties(uint param_1)

{
  size_t _Size;
  int in_EAX;
  uint uVar1;
  int **_Dst;
  int unaff_EBX;
  int *piVar2;
  uint local_c;
  int *local_8;
  
  piVar2 = *(int **)(in_EAX + 4);
  local_8 = piVar2;
  xtra_getScriptProperty(unaff_EBX,piVar2,0,&local_c);
  uVar1 = (uint)*(ushort *)(*(int *)(in_EAX + 0x10) + 0x10);
  if (uVar1 < *(uint *)(in_EAX + 0x18)) {
    uVar1 = *(uint *)(in_EAX + 0x18);
  }
  if (local_c == 0x80000001) {
    if (uVar1 < 0x20) {
      local_8 = (int *)0x0;
      _Dst = &local_8;
    }
    else {
      _Size = (uVar1 + 0x1f >> 5) * 4;
      _Dst = (int **)xtra_getPropertyById(unaff_EBX,_Size);
      if (_Dst == (int **)0x0) {
        return 0;
      }
      memset(_Dst,0,_Size);
      local_c = (uint)_Dst | 1;
      xtra_setScriptProperty(unaff_EBX,local_8,0,local_c);
      piVar2 = local_8;
    }
  }
  else if (uVar1 < 0x20) {
    local_8 = (int *)((int)local_c >> 1);
    _Dst = &local_8;
  }
  else {
    _Dst = (int **)(local_c & 0xfffffffe);
  }
  _Dst[param_1 >> 5] = (int *)((uint)_Dst[param_1 >> 5] | 1 << ((byte)param_1 & 0x1f));
  if (_Dst == &local_8) {
    local_c = (int)local_8 * 2 | 1;
    xtra_setScriptProperty(unaff_EBX,piVar2,0,local_c);
  }
  return 1;
}



// ============================================================
// Function: runtime_isPrototypeOf (FUN_68122f30)
// Address: 68122f30
// Size: 112 bytes
// Params: int param_1, undefined4 param_2
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall runtime_isPrototypeOf(int param_1,undefined4 param_2)

{
  uint in_EAX;
  int *piVar1;
  uint uVar2;
  int local_c;
  uint local_8;
  
  xtra_getScriptProperty(param_2,*(int **)(param_1 + 4),0,&local_8);
  if (local_8 == 0x80000001) {
    return false;
  }
  uVar2 = (uint)*(ushort *)(*(int *)(param_1 + 0x10) + 0x10);
  if (uVar2 < *(uint *)(param_1 + 0x18)) {
    uVar2 = *(uint *)(param_1 + 0x18);
  }
  if (uVar2 < 0x20) {
    local_c = (int)local_8 >> 1;
    piVar1 = &local_c;
  }
  else {
    piVar1 = (int *)(local_8 & 0xfffffffe);
  }
  return (1 << ((byte)in_EAX & 0x1f) & piVar1[in_EAX >> 5]) != 0;
}



// ============================================================
// Function: runtime_enumerateProperties (FUN_68122fa0)
// Address: 68122fa0
// Size: 331 bytes
// Params: uint param_1, undefined4 * param_2, uint param_3, undefined4 * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_enumerateProperties(uint param_1,undefined4 *param_2,uint param_3,undefined4 *param_4,uint *param_5)

{
  undefined4 *puVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined3 extraout_var;
  uint uVar8;
  
  uVar2 = param_3;
  puVar1 = param_2;
  if ((param_2[0x13] & 0x1000000) != 0) {
    iVar4 = (**(code **)(*(int *)(*(int *)*param_2 + 4) + 0x10))
                      (param_1,(int *)*param_2,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xd8),
                       &param_2);
    if (iVar4 == 0) {
      return 0;
    }
    if ((((uint)param_2 & 7) == 0) && (param_2 != (undefined4 *)0x0)) {
      piVar5 = (int *)((uint)param_2 & 0xfffffff8);
    }
    else {
      piVar5 = (int *)runtime_hasProperty(param_1,(uint)param_2);
      if (piVar5 == (int *)0x0) {
        return 0;
      }
    }
    *param_4 = piVar5;
    uVar6 = (**(code **)(*(int *)(*piVar5 + 4) + 0x10))(param_1,piVar5,param_3,param_5);
    return uVar6;
  }
  *param_4 = 0;
  *param_5 = 0x80000001;
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    if (param_3 == *(uint *)(*(int *)(param_1 + 0x14) + 0x108)) {
      if ((param_2[1] != 0) && ((param_2[0x13] & 0x4000000) != 0)) {
        uVar6 = (**(code **)(*(int *)(*(int *)param_2[1] + 4) + 0x10))
                          (param_1,(int *)param_2[1],param_3,param_5);
        return uVar6;
      }
      *param_5 = param_2[6] * 2 | 1;
    }
  }
  else {
    uVar8 = (int)param_3 >> 1;
    uVar7 = (uint)*(ushort *)(param_2[4] + 0x10);
    if ((uint)*(ushort *)(param_2[4] + 0x10) < (uint)param_2[6]) {
      uVar7 = param_2[6];
    }
    if (uVar8 < uVar7) {
      if ((param_2[1] != 0) &&
         (bVar3 = runtime_isPrototypeOf((int)param_2,param_1), CONCAT31(extraout_var,bVar3) != 0)) {
        piVar5 = (int *)puVar1[1];
        uVar6 = (**(code **)(*(int *)(*piVar5 + 4) + 0x10))(param_1,piVar5,uVar2,param_5);
        return uVar6;
      }
      *param_5 = *(uint *)(puVar1[7] + uVar8 * 4);
      return 1;
    }
  }
  return 1;
}



// ============================================================
// Function: runtime_getOrCreateObjectPrototype (FUN_681230f0)
// Address: 681230f0
// Size: 81 bytes
// Params: int param_1, uint param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_getOrCreateObjectPrototype(int param_1,uint param_2)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_2 + 4);
  if (piVar1 == (int *)0x0) {
    piVar1 = runtime_setProperty(param_1,&PTR_s_Object_68192798,(undefined4 *)0x0,0);
    if (piVar1 != (int *)0x0) {
      iVar2 = xtra_getResourceById(param_1,(int)piVar1,param_2);
      if (iVar2 != 0) {
        *(int **)(param_2 + 4) = piVar1;
        return piVar1;
      }
    }
    *(undefined4 *)(param_1 + 0x90) = 0;
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



// ============================================================
// Function: runtime_objectValueOf (FUN_68123150)
// Address: 68123150
// Size: 137 bytes
// Params: undefined4 param_1, int param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_objectValueOf(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  if (((param_3 & 1) != 0) && (param_3 != 0x80000001)) {
    iVar1 = xtra_callMethodEx(param_1,param_2,&PTR_s_Object_68192798,0);
    if (iVar1 != 0) {
      uVar3 = (int)param_3 >> 1;
      if (((int)uVar3 < -4) || (-3 < (int)uVar3)) {
        uVar2 = (uint)*(ushort *)(*(int *)(iVar1 + 0x10) + 0x10);
        if (uVar2 < *(uint *)(iVar1 + 0x18)) {
          uVar2 = *(uint *)(iVar1 + 0x18);
        }
        if (uVar3 < uVar2) {
          iVar1 = runtime_duplicateProperties(uVar3);
          if (iVar1 == 0) {
            return 0;
          }
        }
      }
      else {
        *(uint *)(iVar1 + 0x4c) = *(uint *)(iVar1 + 0x4c) | 1 << (0x17U - (char)uVar3 & 0x1f);
      }
    }
    return 1;
  }
  return 1;
}



// ============================================================
// Function: runtime_objectHasOwnProperty (FUN_681231e0)
// Address: 681231e0
// Size: 241 bytes
// Params: undefined4 param_1, int param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_objectHasOwnProperty(undefined4 param_1,int param_2,uint param_3,uint *param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined3 extraout_var;
  uint uVar4;
  
  if (((param_3 & 1) != 0) && (param_3 != 0x80000001)) {
    iVar2 = xtra_callMethodEx(param_1,param_2,&PTR_s_Object_68192798,0);
    if (iVar2 == 0) {
      return 1;
    }
    uVar4 = (int)param_3 >> 1;
    if (uVar4 == 0xfffffffc) {
      if ((*(uint *)(iVar2 + 0x4c) & 0x8000000) == 0) {
        if (*(int *)(iVar2 + 0x1c) != 0) {
          *param_4 = *(uint *)(*(int *)(iVar2 + 0x1c) + -8);
          return 1;
        }
        *param_4 = *(uint *)(*(int *)(iVar2 + 0x10) + 4);
      }
    }
    else if (uVar4 == 0xfffffffd) {
      if ((*(uint *)(iVar2 + 0x4c) & 0x4000000) == 0) {
        *param_4 = *(int *)(iVar2 + 0x18) * 2 | 1;
        return 1;
      }
    }
    else {
      uVar3 = (uint)*(ushort *)(*(int *)(iVar2 + 0x10) + 0x10);
      if (uVar3 < *(uint *)(iVar2 + 0x18)) {
        uVar3 = *(uint *)(iVar2 + 0x18);
      }
      if (uVar4 < uVar3) {
        bVar1 = runtime_isPrototypeOf(iVar2,param_1);
        if (CONCAT31(extraout_var,bVar1) == 0) {
          *param_4 = *(uint *)(*(int *)(iVar2 + 0x1c) + uVar4 * 4);
          return 1;
        }
      }
    }
    return 1;
  }
  return 1;
}



// ============================================================
// Function: runtime_objectPropertyIsEnumerable (FUN_681232e0)
// Address: 681232e0
// Size: 177 bytes
// Params: undefined4 param_1, int param_2, uint param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_objectPropertyIsEnumerable(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined3 extraout_var;
  uint uVar4;
  
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    return 1;
  }
  iVar2 = xtra_callMethodEx(param_1,param_2,&PTR_s_Object_68192798,0);
  if (iVar2 == 0) {
    return 1;
  }
  uVar4 = (int)param_3 >> 1;
  if ((-5 < (int)uVar4) && ((int)uVar4 < -2)) {
    *(uint *)(iVar2 + 0x4c) = *(uint *)(iVar2 + 0x4c) | 1 << (0x17U - (char)uVar4 & 0x1f);
    return 1;
  }
  uVar3 = (uint)*(ushort *)(*(int *)(iVar2 + 0x10) + 0x10);
  if (uVar3 < *(uint *)(iVar2 + 0x18)) {
    uVar3 = *(uint *)(iVar2 + 0x18);
  }
  if (uVar4 < uVar3) {
    bVar1 = runtime_isPrototypeOf(iVar2,param_1);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      *(undefined4 *)(*(int *)(iVar2 + 0x1c) + uVar4 * 4) = *param_4;
    }
  }
  return 1;
}



// ============================================================
// Function: runtime_objectToString (FUN_681233a0)
// Address: 681233a0
// Size: 328 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_objectToString(uint param_1,int *param_2,uint param_3,undefined4 param_4,undefined4 *param_5)

{
  bool bVar1;
  int iVar2;
  uint uVar3;
  undefined3 extraout_var;
  uint uVar4;
  undefined4 uVar5;
  
  *param_5 = 0;
  iVar2 = xtra_callMethodEx(param_1,(int)param_2,&PTR_s_Object_68192798,0);
  if (iVar2 == 0) {
    return 1;
  }
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    uVar3 = *(uint *)(*(int *)(param_1 + 0x14) + 0x108);
    if ((param_3 & 0xfffffff8) == (*(uint *)(uVar3 + 8) & 0xfffffff8)) {
      uVar5 = 0xfffffffd;
      uVar4 = *(int *)(iVar2 + 0x18) * 2 | 1;
    }
    else {
      uVar3 = *(uint *)(*(int *)(param_1 + 0x14) + 0xe0);
      if ((param_3 & 0xfffffff8) != (*(uint *)(uVar3 + 8) & 0xfffffff8)) {
        return 1;
      }
      uVar5 = 0xfffffffc;
      if (*(int *)(iVar2 + 0x1c) == 0) {
        uVar4 = *(uint *)(*(int *)(iVar2 + 0x10) + 4);
      }
      else {
        uVar4 = *(uint *)(*(int *)(iVar2 + 0x1c) + -8);
      }
    }
    if ((*(uint *)(iVar2 + 0x4c) & 1 << (0x17U - (char)uVar5 & 0x1f)) != 0) {
      return 1;
    }
    iVar2 = runtime_invokeMethod(param_1,param_2,uVar3,uVar4,0x681231e0,0x681232e0,0,8,uVar5,
                         (undefined4 *)0x0);
  }
  else {
    uVar3 = (uint)*(ushort *)(*(int *)(iVar2 + 0x10) + 0x10);
    if (uVar3 < *(uint *)(iVar2 + 0x18)) {
      uVar3 = *(uint *)(iVar2 + 0x18);
    }
    if (uVar3 <= (uint)((int)param_3 >> 1)) {
      return 1;
    }
    bVar1 = runtime_isPrototypeOf(iVar2,param_1);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      return 1;
    }
    if ((*(int *)(param_1 + 0xc) == 0) || (0x81 < *(int *)(param_1 + 0xc))) {
      uVar3 = 0;
    }
    else {
      uVar3 = 1;
    }
    iVar2 = runtime_callProperty(param_1,param_2,param_3,
                         *(undefined4 *)(*(int *)(iVar2 + 0x1c) + ((int)param_3 >> 1) * 4),
                         0x681231e0,0x681232e0,uVar3,(undefined4 *)0x0);
  }
  if (iVar2 != 0) {
    *param_5 = param_2;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: runtime_objectDefaultValue (FUN_681234f0)
// Address: 681234f0
// Size: 263 bytes
// Params: uint param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_objectDefaultValue(uint param_1,int *param_2)

{
  code *pcVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int *local_8;
  
  piVar3 = param_2;
  uVar2 = param_1;
  iVar4 = xtra_callMethodEx(param_1,(int)param_2,&PTR_s_Object_68192798,0);
  if (iVar4 == 0) {
    return 1;
  }
  iVar5 = runtime_getProperty(uVar2,piVar3,*(uint *)(*(int *)(uVar2 + 0x14) + 0x108),&local_8,&param_1);
  if (iVar5 != 0) {
    if ((param_1 != 0) &&
       (pcVar1 = *(code **)(*(int *)(*local_8 + 4) + 0x34), pcVar1 != (code *)0x0)) {
      (*pcVar1)(uVar2,local_8,param_1);
    }
    iVar5 = runtime_getProperty(uVar2,piVar3,*(uint *)(*(int *)(uVar2 + 0x14) + 0xe0),&local_8,&param_1);
    if (iVar5 != 0) {
      if ((param_1 != 0) &&
         (pcVar1 = *(code **)(*(int *)(*local_8 + 4) + 0x34), pcVar1 != (code *)0x0)) {
        (*pcVar1)(uVar2,local_8,param_1);
      }
      uVar6 = (uint)*(ushort *)(*(int *)(iVar4 + 0x10) + 0x10);
      uVar7 = *(uint *)(iVar4 + 0x18);
      if (*(uint *)(iVar4 + 0x18) <= uVar6) {
        uVar7 = uVar6;
      }
      uVar6 = 0;
      if (uVar7 == 0) {
        return 1;
      }
      do {
        iVar4 = runtime_getProperty(uVar2,param_2,uVar6 * 2 | 1,&local_8,&param_1);
        if (iVar4 == 0) {
          return 0;
        }
        if ((param_1 != 0) &&
           (pcVar1 = *(code **)(*(int *)(*local_8 + 4) + 0x34), pcVar1 != (code *)0x0)) {
          (*pcVar1)(uVar2,local_8,param_1);
        }
        uVar6 = uVar6 + 1;
      } while (uVar6 < uVar7);
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_createPrototypeChain (FUN_68123600)
// Address: 68123600
// Size: 127 bytes
// Params: int param_1, int * param_2, uint param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_createPrototypeChain(int param_1,int *param_2,uint param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  
  piVar2 = (int *)*param_2;
  if (piVar2 == (int *)0x0) {
    if (param_3 == 0) {
      if (param_2[7] == 0) {
        uVar1 = *(uint *)(param_2[4] + 4);
      }
      else {
        uVar1 = *(uint *)(param_2[7] + -8) & 0xfffffff8;
      }
      if (uVar1 != 0) {
        param_3 = *(uint *)(*(int *)(uVar1 + 4) + 4) & 0xfffffff8;
      }
    }
    piVar2 = runtime_setProperty(param_1,&PTR_DAT_68192810,(undefined4 *)0x0,param_3);
    if (piVar2 != (int *)0x0) {
      iVar3 = xtra_getResourceById(param_1,(int)piVar2,(uint)param_2);
      if (iVar3 != 0) {
        *param_2 = (int)piVar2;
        param_2[0xd] = (int)piVar2;
        param_2[2] = (int)piVar2;
        return piVar2;
      }
    }
    *(undefined4 *)(param_1 + 0x90) = 0;
    piVar2 = (int *)0x0;
  }
  return piVar2;
}



// ============================================================
// Function: runtime_getPrototypeProperty (FUN_68123680)
// Address: 68123680
// Size: 213 bytes
// Params: int param_1, int param_2, uint param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPrototypeProperty(int param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    return 1;
  }
  uVar1 = xtra_getObjectTag(param_1,param_2);
  if (uVar1 != 0) {
    uVar4 = (int)param_3 >> 1;
    if (uVar4 == 0xfffffffe) {
      if ((*(uint *)(uVar1 + 0x4c) & 0x2000000) == 0) {
        if (*(int *)(uVar1 + 0x1c) != 0) {
          *param_4 = *(undefined4 *)(*(int *)(uVar1 + 0x1c) + -8);
          return 1;
        }
        *param_4 = *(undefined4 *)(*(int *)(uVar1 + 0x10) + 4);
      }
    }
    else if (uVar4 == 0xffffffff) {
      if ((*(uint *)(uVar1 + 0x4c) & 0x1000000) == 0) {
        piVar2 = runtime_getOrCreateObjectPrototype(param_1,uVar1);
        if (piVar2 == (int *)0x0) {
          return 0;
        }
        *param_4 = piVar2;
        return 1;
      }
    }
    else {
      uVar3 = (uint)*(ushort *)(*(int *)(uVar1 + 0x10) + 0x10);
      if (uVar3 < *(uint *)(uVar1 + 0x18)) {
        uVar3 = *(uint *)(uVar1 + 0x18);
      }
      if (uVar4 < uVar3) {
        *param_4 = *(undefined4 *)(*(int *)(uVar1 + 0x1c) + uVar4 * 4);
        return 1;
      }
    }
  }
  return 1;
}



// ============================================================
// Function: runtime_setPrototypeProperty (FUN_68123760)
// Address: 68123760
// Size: 120 bytes
// Params: undefined4 param_1, int param_2, uint param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_setPrototypeProperty(undefined4 param_1,int param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  if (((param_3 & 1) != 0) && (param_3 != 0x80000001)) {
    uVar1 = xtra_getObjectTag(param_1,param_2);
    if (uVar1 != 0) {
      uVar3 = (int)param_3 >> 1;
      if ((-3 < (int)uVar3) && ((int)uVar3 < 0)) {
        *(uint *)(uVar1 + 0x4c) = *(uint *)(uVar1 + 0x4c) | 1 << (0x17U - (char)uVar3 & 0x1f);
        return 1;
      }
      uVar2 = (uint)*(ushort *)(*(int *)(uVar1 + 0x10) + 0x10);
      if (uVar2 < *(uint *)(uVar1 + 0x18)) {
        uVar2 = *(uint *)(uVar1 + 0x18);
      }
      if (uVar3 < uVar2) {
        *(undefined4 *)(*(int *)(uVar1 + 0x1c) + uVar3 * 4) = *param_4;
      }
    }
  }
  return 1;
}



// ============================================================
// Function: runtime_createObject (FUN_681237e0)
// Address: 681237e0
// Size: 50 bytes
// Params: undefined4 param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_createObject(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  
  uVar1 = xtra_getObjectTag(param_1,param_2);
  if ((uVar1 != 0) && ((uint)(param_3 >> 1) < *(uint *)(uVar1 + 0x24))) {
    *param_4 = *(undefined4 *)(*(int *)(uVar1 + 0x28) + (param_3 >> 1) * 4);
  }
  return 1;
}



// ============================================================
// Function: runtime_deletePrototypeProperty (FUN_68123820)
// Address: 68123820
// Size: 50 bytes
// Params: undefined4 param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_deletePrototypeProperty(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  
  uVar1 = xtra_getObjectTag(param_1,param_2);
  if ((uVar1 != 0) && ((uint)(param_3 >> 1) < *(uint *)(uVar1 + 0x24))) {
    *(undefined4 *)(*(int *)(uVar1 + 0x28) + (param_3 >> 1) * 4) = *param_4;
  }
  return 1;
}



// ============================================================
// Function: runtime_enumerateObject (FUN_68123860)
// Address: 68123860
// Size: 197 bytes
// Params: uint param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_enumerateObject(uint param_1,int *param_2)

{
  uint *puVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint local_8;
  
  uVar3 = xtra_getObjectTag(param_1,(int)param_2);
  if ((uVar3 == 0) || (piVar5 = *(int **)(*(int *)(uVar3 + 0x10) + 4), piVar5 == (int *)0x0)) {
    return 1;
  }
  puVar1 = *(uint **)(*piVar5 + 0x24);
  piVar5 = param_2;
  do {
    if (puVar1 == (uint *)0x0) {
      return 1;
    }
    if ((code *)puVar1[1] == certs_executeVerify) {
      iVar6 = *(int *)(uVar3 + 0x1c);
LAB_681238b9:
      iVar4 = runtime_getProperty(param_1,piVar5,*puVar1,&param_2,&local_8);
      if (iVar4 == 0) {
        return 0;
      }
      *(undefined4 *)(param_2[1] + *(int *)(local_8 + 0xc) * 4) =
           *(undefined4 *)(iVar6 + *(short *)((int)puVar1 + 0x12) * 4);
      pcVar2 = *(code **)(*(int *)(*param_2 + 4) + 0x34);
      piVar5 = param_2;
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(param_1,param_2,local_8);
        piVar5 = param_2;
      }
    }
    else if ((code *)puVar1[1] == certs_initVerifier) {
      iVar6 = *(int *)(uVar3 + 0x28);
      goto LAB_681238b9;
    }
    puVar1 = (uint *)puVar1[5];
  } while( true );
}



// ============================================================
// Function: runtime_resolveObjectProperty (FUN_68123930)
// Address: 68123930
// Size: 358 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_resolveObjectProperty(uint param_1,int *param_2,uint param_3,undefined4 param_4,undefined4 *param_5)

{
  undefined **ppuVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  uint uVar10;
  code *pcVar11;
  code *pcVar12;
  int *piVar13;
  uint *local_c;
  int *local_8;
  
  uVar4 = xtra_getObjectTag(param_1,(int)param_2);
  if ((uVar4 == 0) || (((byte)param_3 & 7) != 4)) {
    return 1;
  }
  if (*(int *)(uVar4 + 0x1c) == 0) {
    piVar13 = *(int **)(*(int *)(uVar4 + 0x10) + 4);
  }
  else {
    piVar13 = (int *)(*(uint *)(*(int *)(uVar4 + 0x1c) + -8) & 0xfffffff8);
  }
  if (piVar13 != (int *)0x0) {
    puVar5 = js_findOrCreateAtom(param_1,(uint *)(param_3 & 0xfffffff8),0);
    if ((puVar5 == (undefined4 *)0x0) ||
       (iVar6 = runtime_getProperty(param_1,piVar13,(uint)puVar5,&local_8,(uint *)&local_c), iVar6 == 0)) {
      return 0;
    }
    if ((local_c != (uint *)0x0) &&
       ((ppuVar1 = *(undefined ***)(*local_8 + 4), ppuVar1 == &PTR_FUN_68192948 ||
        ((ppuVar1 != (undefined **)0x0 && (*ppuVar1 == PTR_FUN_68192948)))))) {
      uVar2 = *local_c;
      uVar3 = local_c[4];
      pcVar11 = (code *)local_c[1];
      uVar10 = (uint)*(short *)((int)local_c + 0x12);
      if ((code *)ppuVar1[0xd] != (code *)0x0) {
        (*(code *)ppuVar1[0xd])(param_1,local_8,local_c);
      }
      if (pcVar11 == certs_executeVerify) {
        uVar7 = (uint)*(ushort *)(*(int *)(uVar4 + 0x10) + 0x10);
        iVar6 = *(int *)(uVar4 + 0x1c);
        if (uVar7 < *(uint *)(uVar4 + 0x18)) {
          uVar7 = *(uint *)(uVar4 + 0x18);
        }
        pcVar11 = (code *)0x0;
        pcVar12 = (code *)0x0;
      }
      else {
        if (pcVar11 != certs_initVerifier) {
          return 1;
        }
        iVar6 = *(int *)(uVar4 + 0x28);
        uVar7 = *(uint *)(uVar4 + 0x24);
        pcVar12 = runtime_createObject;
        pcVar11 = runtime_deletePrototypeProperty;
      }
      if (uVar10 < uVar7) {
        uVar8 = *(undefined4 *)(iVar6 + uVar10 * 4);
        uVar9 = 8;
      }
      else {
        uVar9 = 0;
        uVar8 = 0x80000001;
        uVar10 = 0;
      }
      iVar6 = runtime_invokeMethod(param_1,param_2,uVar2,uVar8,(uint)pcVar12,(uint)pcVar11,
                           (byte)uVar3 & 0xffffffbf,uVar9,uVar10,(undefined4 *)0x0);
      if (iVar6 == 0) {
        return 0;
      }
      *param_5 = param_2;
    }
    return 1;
  }
  return 1;
}



// ============================================================
// Function: runtime_hasOwnPropertyCheck (FUN_68123aa0)
// Address: 68123aa0
// Size: 70 bytes
// Params: undefined4 param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_hasOwnPropertyCheck(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  uint uVar1;
  
  if (param_3 == 2) {
    uVar1 = xtra_getObjectTag(param_1,param_2);
    if (uVar1 != 0) {
      if (*(int *)(uVar1 + 0x1c) != 0) {
        *param_4 = *(undefined4 *)(*(int *)(uVar1 + 0x1c) + -8);
        return 1;
      }
      *param_4 = *(undefined4 *)(*(int *)(uVar1 + 0x10) + 4);
    }
  }
  return 1;
}



// ============================================================
// Function: runtime_getCallableProperty (FUN_68123af0)
// Address: 68123af0
// Size: 252 bytes
// Params: int param_1, int * param_2, uint param_3, byte param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getCallableProperty(int param_1,int *param_2,uint param_3,byte param_4,undefined4 *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  
  if (((byte)param_3 & 7) != 4) {
    return 1;
  }
  iVar1 = xtra_callMethodEx(param_1,(int)param_2,&PTR_s_Function_681928b8,0);
  if (iVar1 == 0) {
    return 1;
  }
  piVar4 = *(int **)(iVar1 + 4);
  if (piVar4 == (int *)0x0) {
    return 1;
  }
  if ((param_4 & 2) != 0) {
    return 1;
  }
  iVar3 = *(int *)(*(int *)(param_1 + 0x14) + 0xe8);
  if (((*(uint *)(iVar3 + 8) ^ param_3) & 0xfffffff8) != 0) {
    return 1;
  }
  puVar2 = (undefined4 *)0x0;
  if (piVar4 != param_2) {
    iVar3 = (**(code **)(*(int *)(*piVar4 + 4) + 0x10))(param_1,piVar4,iVar3,&param_3);
    if (iVar3 == 0) {
      return 0;
    }
    if ((param_3 & 7) == 0) {
      puVar2 = (undefined4 *)(param_3 & 0xfffffff8);
      if (puVar2 != (undefined4 *)0x0) goto LAB_68123b84;
    }
    else {
      puVar2 = (undefined4 *)0x0;
    }
  }
  if (*(int *)(iVar1 + 0x18) == *(int *)(*(int *)(param_1 + 0x14) + 0xc4)) {
    return 1;
  }
LAB_68123b84:
  piVar4 = runtime_setProperty(param_1,&PTR_s_Object_681929a8,puVar2,*(uint *)(param_2[1] + 4) & 0xfffffff8
                       );
  if (piVar4 != (int *)0x0) {
    iVar1 = runtime_copyPropertyDescriptor(param_1,param_2,piVar4,4);
    if (iVar1 != 0) {
      *param_5 = param_2;
      return 1;
    }
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  return 0;
}



// ============================================================
// Function: runtime_convertToObject (FUN_68123bf0)
// Address: 68123bf0
// Size: 49 bytes
// Params: uint param_1, int * param_2, int param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_convertToObject(uint param_1,int *param_2,int param_3,int *param_4)

{
  undefined4 uVar1;
  
  if (param_3 != 2) {
    uVar1 = runtime_definePropertyOnObject(param_1,param_2,param_3,param_4);
    return uVar1;
  }
  *param_4 = (int)param_2;
  return 1;
}



// ============================================================
// Function: runtime_freeObjectAndPrototype (FUN_68123c30)
// Address: 68123c30
// Size: 69 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_freeObjectAndPrototype(int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = (int *)xtra_getObjectTag(param_1,param_2);
  if (piVar1 != (int *)0x0) {
    if (piVar1[1] == param_2) {
      piVar1[1] = 0;
    }
    *piVar1 = *piVar1 + -1;
    if (*piVar1 == 0) {
      if (piVar1[3] != 0) {
        runtime_getObjectPrototype(param_1,piVar1[3]);
      }
      xtra_checkAndFlush(param_1,(int)piVar1);
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_resolveCallable (FUN_68123c80)
// Address: 68123c80
// Size: 336 bytes
// Params: uint param_1, undefined * * param_2, uint param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_resolveCallable(uint param_1,undefined **param_2,uint param_3,int *param_4)

{
  uint uVar1;
  undefined **ppuVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  int *piVar7;
  uint local_8;
  
  ppuVar2 = param_2;
  uVar1 = param_1;
  iVar3 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))
                    (param_1,param_2,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xe8),&param_1);
  piVar7 = param_4;
  uVar4 = param_3;
  if (iVar3 != 0) {
    if (((param_1 & 7) == 0) && (param_1 != 0)) {
      iVar3 = runtime_resolvePropertyByAtom(uVar1,param_1 & 0xfffffff8,param_3,param_4);
      if (iVar3 != 0) {
        if (((*piVar7 != 0) || ((uVar4 & 7) != 0)) || (uVar4 == 0)) {
          return 1;
        }
        piVar7 = (int *)(uVar4 & 0xfffffff8);
        while (iVar3 = (**(code **)(*(int *)(*piVar7 + 4) + 0x10))
                                 (uVar1,piVar7,*(undefined4 *)(*(int *)(uVar1 + 0x14) + 0xec),
                                  &local_8), iVar3 != 0) {
          if ((((local_8 & 7) == 0) && ((local_8 & 0xfffffff8) != 0)) &&
             ((undefined **)(*(uint *)(*(int *)((local_8 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
              &PTR_s_Function_681928b8)) {
            uVar4 = xtra_getObjectTag(uVar1,local_8 & 0xfffffff8);
            uVar5 = xtra_getObjectTag(uVar1,(int)param_2);
            if ((*(int *)(uVar4 + 8) == *(int *)(uVar5 + 8)) &&
               (*(int *)(uVar4 + 0xc) == *(int *)(uVar5 + 0xc))) {
              *param_4 = 1;
              return 1;
            }
          }
          piVar7 = (int *)(*(uint *)piVar7[1] & 0xfffffff8);
          if (piVar7 == (int *)0x0) {
            return 1;
          }
        }
      }
      return 0;
    }
    puVar6 = crypto_decompileExpr(uVar1,(int *)0xffffffff,ppuVar2,(uint *)0x0);
    if (puVar6 != (uint *)0x0) {
      xtra_getStringValue(puVar6);
      xtra_invokeMethod(uVar1,xtra_getErrorString,0,0x87);
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_freeObjectCompletely (FUN_68123dd0)
// Address: 68123dd0
// Size: 81 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_freeObjectCompletely(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = xtra_getObjectTag(param_1,param_2);
  if (uVar2 != 0) {
    iVar1 = *(int *)(uVar2 + 0x18);
    if ((iVar1 != 0) && ((*(byte *)(iVar1 + 0x10) & 4) == 0)) {
      js_allocAtomSlot(param_1,iVar1);
    }
    if (*(int *)(uVar2 + 0xc) != 0) {
      runtime_freeObjectSlots(param_1,*(int *)(uVar2 + 0xc));
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: runtime_resolveConstructor (FUN_68123e30)
// Address: 68123e30
// Size: 257 bytes
// Params: ushort * param_1, uint param_2, uint param_3, int param_4, uint * param_5, uint * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_resolveConstructor(ushort *param_1,uint param_2,uint param_3,int param_4,uint *param_5,uint *param_6)

{
  byte bVar1;
  int iVar2;
  undefined3 extraout_var;
  uint uVar3;
  uint *puVar4;
  
  puVar4 = param_5;
  if (param_5 != (uint *)0x0) {
    param_5 = (uint *)param_5[-1];
    if (((((uint)param_5 & 7) != 0) || (((uint)param_5 & 0xfffffff8) == 0)) ||
       (param_2 = (uint)param_5 & 0xfffffff8,
       (undefined **)(*(uint *)(*(int *)(param_2 + 4) + 8) & 0xfffffffe) != &PTR_s_Function_681928b8
       )) {
      if ((((uint)param_5 & 7) == 0) &&
         (iVar2 = (**(code **)((*(uint *)(*(int *)(((uint)param_5 & 0xfffffff8) + 4) + 8) &
                               0xfffffffe) + 0x20))(param_1,(uint)param_5 & 0xfffffff8,2,&param_5),
         iVar2 == 0)) {
        return 0;
      }
      if (((((uint)param_5 & 7) != 0) || (((uint)param_5 & 0xfffffff8) == 0)) ||
         (param_2 = (uint)param_5 & 0xfffffff8,
         (undefined **)(*(uint *)(*(int *)(param_2 + 4) + 8) & 0xfffffffe) !=
         &PTR_s_Function_681928b8)) {
        bVar1 = xtra_lookupHashByte(param_1,(uint)param_5);
        xtraRuntime_getTypeName(param_1,CONCAT31(extraout_var,bVar1));
        xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,8);
        return 0;
      }
    }
  }
  uVar3 = xtra_getObjectTag(param_1,param_2);
  if (uVar3 != 0) {
    if (((param_4 != 0) && (iVar2 = runtime_parseFloat(param_1,*puVar4,&param_3), iVar2 == 0)) ||
       (puVar4 = xtra_createPropertyByName((int)param_1,uVar3,param_3), puVar4 == (uint *)0x0)) {
      return 0;
    }
    *param_6 = (uint)puVar4 | 4;
  }
  return 1;
}



// ============================================================
// Function: runtime_callConstructor (FUN_68123f40)
// Address: 68123f40
// Size: 34 bytes
// Params: ushort * param_1, uint param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_callConstructor(ushort *param_1,uint param_2,int param_3,uint *param_4,uint *param_5)
{
  runtime_resolveConstructor(param_1,param_2,0,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_callConstructorNew (FUN_68123f70)
// Address: 68123f70
// Size: 37 bytes
// Params: ushort * param_1, uint param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_callConstructorNew(ushort *param_1,uint param_2,int param_3,uint *param_4,uint *param_5)
{
  runtime_resolveConstructor(param_1,param_2,0x8000,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_applyFunction (FUN_68123fa0)
// Address: 68123fa0
// Size: 305 bytes
// Params: uint param_1, int * param_2, int param_3, uint * param_4, undefined4 * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_applyFunction(uint param_1,int *param_2,int param_3,uint *param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  
  puVar8 = param_4;
  uVar2 = param_1;
  puVar6 = param_4 + -1;
  iVar3 = (**(code **)(*(int *)(*param_2 + 4) + 0x24))(param_1,param_2,2,puVar6);
  iVar1 = param_3;
  if (iVar3 != 0) {
    param_4 = (uint *)*puVar6;
    if (((((uint)param_4 & 7) == 0) && (((uint)param_4 & 0xfffffff8) != 0)) &&
       ((undefined **)(*(uint *)(*(int *)(((uint)param_4 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
        &PTR_s_Function_681928b8)) {
      if (param_3 == 0) {
        param_2 = (int *)(*(uint *)(param_2[1] + 4) & 0xfffffff8);
        uVar5 = 0;
      }
      else {
        iVar3 = runtime_deleteProperty(uVar2,*puVar8,(uint *)&param_2);
        if (iVar3 == 0) {
          return 0;
        }
        uVar5 = iVar1 - 1;
        puVar8 = puVar8 + 1;
      }
      piVar4 = certs_findExtension(uVar2,uVar5 + 2,&param_1);
      if (piVar4 != (int *)0x0) {
        *piVar4 = (int)param_4;
        piVar4[1] = (int)param_2;
        puVar6 = (uint *)(piVar4 + 2);
        uVar7 = 0;
        if (uVar5 != 0) {
          do {
            *puVar6 = puVar8[uVar7];
            uVar7 = uVar7 + 1;
            puVar6 = puVar6 + 1;
          } while (uVar7 < uVar5);
        }
        iVar1 = *(int *)(uVar2 + 0x34);
        param_4 = *(uint **)(iVar1 + 0x3c);
        *(uint **)(iVar1 + 0x3c) = puVar6;
        uVar5 = certs_verifyChain(uVar2,uVar5,2);
        *param_5 = *(undefined4 *)(*(int *)(iVar1 + 0x3c) + -4);
        *(uint **)(iVar1 + 0x3c) = param_4;
        certs_checkValidity(uVar2,param_1);
        return uVar5;
      }
    }
    else {
      puVar6 = (uint *)xtra_lookupHash(uVar2,(uint)param_4);
      xtra_getStringValue(puVar6);
      xtra_invokeMethod(uVar2,xtra_getErrorString,0,8);
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_callApplyFunction (FUN_681240e0)
// Address: 681240e0
// Size: 485 bytes
// Params: ushort * param_1, int * param_2, uint param_3, uint * param_4, undefined4 * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_callApplyFunction(ushort *param_1,int *param_2,uint param_3,uint *param_4,undefined4 *param_5)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  uint uVar4;
  undefined **ppuVar5;
  int local_14;
  uint local_10;
  int *local_c;
  uint local_8;
  
  uVar1 = param_3;
  if (param_3 == 0) {
    uVar1 = runtime_applyFunction((uint)param_1,param_2,0,param_4,param_5);
    return uVar1;
  }
  puVar3 = param_4 + -1;
  iVar2 = (**(code **)(*(int *)(*param_2 + 4) + 0x24))(param_1,param_2,2,puVar3);
  if (iVar2 != 0) {
    local_10 = *puVar3;
    if ((((local_10 & 7) == 0) && ((local_10 & 0xfffffff8) != 0)) &&
       ((undefined **)(*(uint *)(*(int *)((local_10 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
        &PTR_s_Function_681928b8)) {
      local_c = (int *)0x0;
      local_8 = 0;
      if (((1 < uVar1) && (uVar1 = param_4[1], uVar1 != 0)) && (uVar1 != 0x80000001)) {
        if ((uVar1 & 7) != 0) {
LAB_68124271:
          xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x9a);
          return 0;
        }
        local_c = (int *)(uVar1 & 0xfffffff8);
        ppuVar5 = (undefined **)(*(uint *)(local_c[1] + 8) & 0xfffffffe);
        if ((ppuVar5 != &PTR_s_Object_68192798) && (ppuVar5 != &PTR_s_Array_681939b8))
        goto LAB_68124271;
        iVar2 = js_arrayToString(param_1,local_c,(int *)&local_8);
        if (iVar2 == 0) {
          return 0;
        }
      }
      iVar2 = runtime_deleteProperty((uint)param_1,*param_4,(uint *)&param_2);
      if (iVar2 != 0) {
        param_3 = local_8;
        puVar3 = (uint *)certs_findExtension((int)param_1,local_8 + 2,&local_14);
        if (puVar3 != (uint *)0x0) {
          *puVar3 = local_10;
          puVar3[1] = (uint)param_2;
          uVar1 = 0;
          puVar3 = puVar3 + 2;
          if (param_3 != 0) {
            do {
              iVar2 = xtraRuntime_setPropertyByIndex(param_1,local_c,uVar1,puVar3);
              uVar4 = 0;
              if (iVar2 == 0) goto LAB_68124259;
              uVar1 = uVar1 + 1;
              puVar3 = puVar3 + 1;
            } while (uVar1 < param_3);
          }
          iVar2 = *(int *)(param_1 + 0x1a);
          param_4 = *(uint **)(iVar2 + 0x3c);
          *(uint **)(iVar2 + 0x3c) = puVar3;
          uVar4 = certs_verifyChain((uint)param_1,param_3,2);
          *param_5 = *(undefined4 *)(*(int *)(iVar2 + 0x3c) + -4);
          *(uint **)(iVar2 + 0x3c) = param_4;
LAB_68124259:
          certs_checkValidity((int)param_1,local_14);
          return uVar4;
        }
      }
    }
    else {
      puVar3 = (uint *)xtra_lookupHash((int)param_1,local_10);
      xtra_getStringValue(puVar3);
      xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,8);
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_isValidIdentifier (FUN_681242d0)
// Address: 681242d0
// Size: 206 bytes
// Params: uint * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

undefined4 runtime_isValidIdentifier(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  ushort *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x40000000) == 0) {
    puVar3 = (ushort *)param_1[1];
  }
  else {
    uVar5 = (-(uint)((uVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar1;
    puVar2 = (uint *)param_1[1];
    if ((*puVar2 & 0x40000000) == 0) {
      if ((int)uVar1 < 0) {
        puVar3 = (ushort *)puVar2[1];
        uVar1 = uVar5;
      }
      else {
        puVar3 = (ushort *)(puVar2[1] + (uVar1 >> 0xf & 0x7fff) * 2);
        uVar1 = uVar5;
      }
    }
    else {
      puVar3 = (ushort *)crypto_getStringLen(param_1);
      uVar1 = uVar5;
    }
  }
  uVar5 = (uint)*puVar3;
  if (uVar1 != 0) {
    uVar4 = crypto_getStringCapacity(uVar5);
    uVar4 = 0x43e >> ((byte)uVar4 & 0x1f);
    while ((((uVar4 & 1) != 0 || (uVar5 == 0x5f)) || (uVar5 == 0x24))) {
      uVar1 = uVar1 - 1;
      if (uVar1 == 0) {
        return 1;
      }
      uVar5 = (uint)puVar3[1];
      puVar3 = puVar3 + 1;
      uVar4 = crypto_getStringCapacity(uVar5);
      uVar4 = 0x80077e >> ((byte)uVar4 & 0x1f);
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_initArgumentsPrototype (FUN_681243a0)
// Address: 681243a0
// Size: 42 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_initArgumentsPrototype(int param_1,int *param_2)
{
  xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_DAT_68192810,0,0,
               (int *)&PTR_s_arguments_681927e0,(int *)0x0,(int *)0x0,(int *)0x0);
  return 0;
}



// ============================================================
// Function: runtime_bindPrototype (FUN_681243d0)
// Address: 681243d0
// Size: 51 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_bindPrototype(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  
  if (param_2[1] == 0) {
    param_2[1] = param_3;
  }
  iVar1 = xtra_getResourceById(param_1,param_3,(uint)param_2);
  if (iVar1 == 0) {
    return 0;
  }
  *param_2 = *param_2 + 1;
  return 1;
}



// ============================================================
// Function: runtime_callObjectMethod (FUN_68124410)
// Address: 68124410
// Size: 108 bytes
// Params: int param_1, uint * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_callObjectMethod(int param_1,uint *param_2,int param_3)
{
  byte bVar1;
  undefined3 extraout_var;
  int *piVar2;
  uint *puVar3;
  
  bVar1 = xtra_lookupHashByte(param_1,*param_2);
  if (*(int *)(param_1 + 0x34) == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    piVar2 = (int *)((int)param_2 - *(int *)(*(int *)(param_1 + 0x34) + 0x3c) >> 2);
  }
  puVar3 = crypto_decompileExpr(param_1,piVar2,(undefined **)*param_2,
                        (uint *)(*(uint *)(*(int *)(*(int *)(param_1 + 0x14) + 0x7c +
                                                   CONCAT31(extraout_var,bVar1) * 4) + 8) &
                                0xfffffff8));
  if (puVar3 != (uint *)0x0) {
    xtra_getStringValue(puVar3);
    xtra_invokeMethod(param_1,xtra_getErrorString,0,(param_3 != 0) + 0x16);
  }
  return 0;
}



// ============================================================
// Function: runtime_createObjectFromPrototype (FUN_68124480)
// Address: 68124480
// Size: 84 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_createObjectFromPrototype(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int *piVar2;
  
  if ((param_2[0x13] & 0x1000000) != 0) {
    uVar1 = (**(code **)(*(int *)(*(int *)*param_2 + 4) + 0x10))
                      (param_1,(int *)*param_2,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xd8),
                       param_3);
    return uVar1;
  }
  piVar2 = runtime_getOrCreateObjectPrototype(param_1,(uint)param_2);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  *param_3 = piVar2;
  return 1;
}



// ============================================================
// Function: runtime_initObjectProperties (FUN_681244e0)
// Address: 681244e0
// Size: 227 bytes
// Params: uint param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_initObjectProperties(uint param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint local_c;
  int local_8;
  
  uVar7 = param_1;
  piVar1 = *(int **)(param_2 + 4);
  uVar2 = runtime_objectDefaultValue(param_1,piVar1);
  xtra_getScriptProperty(uVar7,piVar1,0,&local_c);
  if (local_c != 0x80000001) {
    xtra_setScriptProperty(uVar7,piVar1,0,0x80000001);
    uVar3 = (uint)*(ushort *)(*(int *)(param_2 + 0x10) + 0x10);
    if (uVar3 < *(uint *)(param_2 + 0x18)) {
      uVar3 = *(uint *)(param_2 + 0x18);
    }
    if (0x1f < uVar3) {
      xtra_checkAndFlush(uVar7,local_c & 0xfffffffe);
    }
  }
  local_8 = *(int *)(uVar7 + 0x14);
  uVar3 = runtime_getPropertyValue(uVar7,piVar1,*(uint *)(local_8 + 0xe0),(int *)&param_1);
  uVar4 = runtime_getPropertyEx(uVar7,piVar1,*(uint *)(local_8 + 0xe0),&param_1);
  uVar5 = runtime_getPropertyValue(uVar7,piVar1,*(uint *)(local_8 + 0x108),(int *)&param_1);
  uVar6 = runtime_getPropertyEx(uVar7,piVar1,*(uint *)(local_8 + 0x108),&param_1);
  uVar7 = xtra_getResourceById(uVar7,(int)piVar1,0);
  *(undefined4 *)(param_2 + 4) = 0;
  return uVar2 & uVar3 & uVar4 & uVar5 & uVar6 & uVar7;
}



// ============================================================
// Function: runtime_initObjectInstance (FUN_681245d0)
// Address: 681245d0
// Size: 131 bytes
// Params: uint param_1, undefined4 * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_initObjectInstance(uint param_1,undefined4 *param_2)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = param_1;
  piVar1 = (int *)*param_2;
  if (piVar1 == (int *)0x0) {
    return 1;
  }
  uVar2 = runtime_enumerateObject(param_1,piVar1);
  if (param_2[1] != 0) {
    uVar4 = *(uint *)(*(int *)(uVar6 + 0x14) + 0xd8);
    uVar3 = runtime_getPropertyValue(uVar6,piVar1,uVar4,(int *)&param_1);
    uVar4 = runtime_getPropertyEx(uVar6,piVar1,uVar4,&param_1);
    uVar5 = runtime_initObjectProperties(uVar6,(int)param_2);
    uVar2 = uVar2 & uVar3 & uVar4 & uVar5;
  }
  uVar6 = xtra_getResourceById(uVar6,(int)piVar1,0);
  *param_2 = 0;
  return uVar6 & uVar2;
}



// ============================================================
// Function: runtime_getFunctionProperty (FUN_68124660)
// Address: 68124660
// Size: 510 bytes
// Params: int param_1, int param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getFunctionProperty(int param_1,int param_2,uint param_3,uint *param_4)

{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    return 1;
  }
  uVar2 = (int)param_3 >> 1;
  iVar3 = xtra_callMethodEx(param_1,param_2,&PTR_s_Function_681928b8,0);
  if (iVar3 == 0) {
    return 1;
  }
  for (puVar1 = *(undefined4 **)(param_1 + 0x34);
      (puVar1 != (undefined4 *)0x0 &&
      ((puVar1[4] != iVar3 || ((*(byte *)(puVar1 + 0x13) & 0xc) != 0))));
      puVar1 = (undefined4 *)puVar1[0xb]) {
  }
  switch(uVar2) {
  case 0xfffffff9:
    if ((((puVar1 == (undefined4 *)0x0) || (iVar3 = puVar1[0xb], iVar3 == 0)) ||
        (*(int *)(iVar3 + 0x10) == 0)) || (*(int *)(iVar3 + 0x1c) == 0)) {
      *param_4 = 0;
    }
    else {
      *param_4 = *(uint *)(*(int *)(iVar3 + 0x1c) + -8);
    }
    if ((*param_4 & 7) != 0) {
      return 1;
    }
    if (*param_4 == 0) {
      return 1;
    }
    iVar3 = *(int *)(param_1 + 0x14);
    if (*(int *)(iVar3 + 0x2254) == 0) {
      return 1;
    }
    iVar3 = (**(code **)(iVar3 + 0x2254))
                      (param_1,param_2,*(undefined4 *)(*(int *)(iVar3 + 0xe4) + 8),4,param_4);
    break;
  case 0xfffffffa:
    if (*(int *)(iVar3 + 0x18) == 0) {
      *param_4 = *(uint *)(*(int *)(param_1 + 0x14) + 0x1dc) | 4;
      return 1;
    }
    *param_4 = *(uint *)(*(int *)(iVar3 + 0x18) + 8);
    return 1;
  default:
    if (puVar1 == (undefined4 *)0x0) {
      return 1;
    }
    if (puVar1[4] == 0) {
      return 1;
    }
    if (*(ushort *)(puVar1[4] + 0x10) <= uVar2) {
      return 1;
    }
    *param_4 = *(uint *)(puVar1[7] + uVar2 * 4);
    return 1;
  case 0xfffffffd:
    if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 0xc) < 0x82)) {
      if ((puVar1 != (undefined4 *)0x0) && (puVar1[4] != 0)) {
        *param_4 = puVar1[6] * 2 | 1;
        return 1;
      }
      *param_4 = (uint)*(ushort *)(iVar3 + 0x10) * 2 | 1;
      return 1;
    }
  case 0xfffffffb:
    *param_4 = (uint)*(ushort *)(iVar3 + 0x10) * 2 | 1;
    return 1;
  case 0xffffffff:
    iVar3 = xtra_invokeWithArgs(param_1,5,xtra_getErrorString,0,0x9e);
    if (iVar3 == 0) {
      return 0;
    }
    if (puVar1 == (undefined4 *)0x0) {
      *param_4 = 0;
      return 1;
    }
    iVar3 = runtime_createObjectFromPrototype(param_1,puVar1,param_4);
  }
  if (iVar3 != 0) {
    return 1;
  }
  return 0;
}



