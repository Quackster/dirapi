// Module: xtra_runtime
// Topic: Script engine API, error handling, object/property registration, execution contexts
// Address range: 0x6811e620 - 0x6811ffe0
// Functions (63):
//   xtra_registerNamedFunction (FUN_6811e620)
//   xtra_getScriptContext
//   xtra_getGlobalFlags (FUN_6811e690)
//   xtra_isFunction (FUN_6811e6b0)
//   xtra_registerMethod (FUN_6811e6d0)
//   xtra_compileScript (FUN_6811e720)
//   xtra_evalScriptBuffer (FUN_6811e7d0)
//   xtra_getInterfacePtr
//   xtra_createProperty (FUN_6811e840)
//   xtra_processExtension (FUN_6811e8b0)
//   xtra_validateExtension (FUN_6811e8f0)
//   xtra_setInterruptHandler (FUN_6811e940)
//   xtra_getScriptContextEx
//   xtra_allocHashEntry (FUN_6811e9d0)
//   xtra_findSymbolByName
//   xtra_lookupAtomValue (FUN_6811ea90)
//   xtra_allocHashEntryDirect (FUN_6811ead0)
//   xtra_allocFromPool (FUN_6811eaf0)
//   xtra_getStringValue
//   xtra_getStringData (FUN_6811eb30)
//   xtra_getStringLength (FUN_6811eb90)
//   xtra_normalizeString (FUN_6811ebc0)
//   xtra_invokeMethod (FUN_6811ebf0)
//   xtra_invokeWithArgs
//   xtra_reportError
//   xtra_setPropertyDirect
//   xtra_initScriptState (FUN_6811ec90)
//   xtra_getStrictMode (FUN_6811ed20)
//   xtra_getInterruptData (FUN_6811ed40)
//   xtra_setInterruptData (FUN_6811ed70)
//   xtra_clearInterrupt (FUN_6811ed90)
//   xtra_releaseObject (FUN_6811edb0)
//   xtra_convertValue (FUN_6811edf0)
//   xtra_initRuntime (FUN_6811efa0)
//   xtra_initGlobalScope (FUN_6811f040)
//   xtra_initBuiltins (FUN_6811f130)
//   xtra_getPropertyById (FUN_6811f1f0)
//   xtra_allocJSString
//   xtra_findMethodByName
//   xtra_getMethodById
//   xtra_resolveMethodId
//   xtra_lookupConstructor (FUN_6811f330)
//   xtra_matchMethodName
//   xtra_registerNamedMethod (FUN_6811f4d0)
//   xtra_getScriptProperty
//   xtra_setScriptProperty
//   xtra_setScriptPropertyEx
//   events_attachVtable
//   xtra_evalScriptString (FUN_6811f680)
//   xtra_createPropertyByName (FUN_6811f6b0)
//   xtra_allocScriptBlock (FUN_6811f720)
//   xtra_storeResult (FUN_6811f770)
//   xtra_createScriptObject
//   xtra_callMethod
//   xtra_callMethodEx
//   xtra_evalSubstring (FUN_6811f9b0)
//   xtra_destroyContext (FUN_6811fa00)
//   xtra_iterateObjects (FUN_6811fb30)
//   xtra_dispatchError (FUN_6811fb60)
//   xtra_formatError (FUN_6811fc30)
//   xtra_reportErrorDirect (FUN_6811ff40)
//   xtra_getErrorString (xtra_getErrorString)
//   xtra_createContext (FUN_6811ffe0)

// ============================================================
// Function: xtra_registerNamedFunction (FUN_6811e620)
// Address: 6811e620
// Size: 81 bytes
// Params: int param_1, int param_2, undefined2 param_3, byte param_4, uint param_5, char * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_registerNamedFunction(int param_1,int param_2,undefined2 param_3,byte param_4,uint param_5,char *param_6
                 )
{
  char cVar1;
  int iVar2;
  char *pcVar3;
  
  if (param_6 == (char *)0x0) {
    iVar2 = 0;
  }
  else {
    pcVar3 = param_6;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    iVar2 = javascript_registerAtom(param_1,param_6,(int)pcVar3 - (int)(param_6 + 1),0);
    if (iVar2 == 0) {
      return 0;
    }
  }
  runtime_createFunction(param_1,(int *)0x0,param_2,param_3,param_4,param_5,iVar2);
  return 0;
}



// ============================================================
// Function: xtra_getScriptContext (FUN_6811e680)
// Address: 6811e680
// Size: 13 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getScriptContext(int param_1)

{
  return *(undefined4 *)(param_1 + 4);
}



// ============================================================
// Function: xtra_getGlobalFlags (FUN_6811e690)
// Address: 6811e690
// Size: 29 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtra_getGlobalFlags(int param_1)

{
  if (*(int *)(param_1 + 0x18) != 0) {
    return *(uint *)(*(int *)(param_1 + 0x18) + 8) & 0xfffffff8;
  }
  return 0;
}



// ============================================================
// Function: xtra_isFunction (FUN_6811e6b0)
// Address: 6811e6b0
// Size: 30 bytes
// Params: undefined4 param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool xtra_isFunction(undefined4 param_1,int param_2)

{
  return (undefined **)(*(uint *)(*(int *)(param_2 + 4) + 8) & 0xfffffffe) ==
         &PTR_s_Function_681928b8;
}



// ============================================================
// Function: xtra_registerMethod (FUN_6811e6d0)
// Address: 6811e6d0
// Size: 75 bytes
// Params: int param_1, int * param_2, char * param_3, int param_4, undefined2 param_5, uint param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_registerMethod(int param_1,int *param_2,char *param_3,int param_4,undefined2 param_5,uint param_6
                 )
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = param_3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = javascript_registerAtom(param_1,param_3,(int)pcVar2 - (int)(param_3 + 1),0);
  if (iVar3 == 0) {
    return 0;
  }
  runtime_registerFunction(param_1,param_2,iVar3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: xtra_compileScript (FUN_6811e720)
// Address: 6811e720
// Size: 175 bytes
// Params: uint * param_1, int * param_2, undefined4 param_3, uint * param_4
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * xtra_compileScript(uint *param_1,int *param_2,undefined4 param_3,uint *param_4)

{
  int *in_EAX;
  int iVar1;
  int *piVar2;
  uint uVar3;
  uint local_a0 [9];
  undefined4 local_7c;
  
  uVar3 = 0;
  iVar1 = javascript_hashTableInsert((int)param_1,local_a0,in_EAX[0x2b],in_EAX[0x1a],in_EAX[0x2d]);
  if (iVar1 == 0) {
    piVar2 = (int *)0x0;
  }
  else {
    iVar1 = crypto_compileFunction(param_1,param_2,in_EAX,local_a0);
    if (iVar1 == 0) {
      piVar2 = (int *)0x0;
      uVar3 = (uint)in_EAX[0x1f] >> 1 & 1;
    }
    else {
      piVar2 = runtime_loadExternalScript((uint)param_1,(int)local_a0,0);
    }
  }
  if (param_4 != (uint *)0x0) {
    *param_4 = uVar3;
  }
  iVar1 = strings_setParserMode(param_1,(int)in_EAX);
  if (iVar1 == 0) {
    if (piVar2 != (int *)0x0) {
      runtime_getObjectPrototype((int)param_1,(int)piVar2);
    }
    piVar2 = (int *)0x0;
  }
  local_7c = param_3;
  javascript_hashTableLookup((int)param_1,(int)local_a0);
  return piVar2;
}



// ============================================================
// Function: xtra_evalScriptBuffer (FUN_6811e7d0)
// Address: 6811e7d0
// Size: 91 bytes
// Params: uint * param_1, int * param_2, int param_3, int param_4, int param_5, undefined4 param_6, undefined4 param_7
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * xtra_evalScriptBuffer(uint *param_1,int *param_2,int param_3,int param_4,int param_5,undefined4 param_6
                  ,undefined4 param_7)

{
  undefined4 uVar1;
  void *pvVar2;
  int *piVar3;
  
  uVar1 = *(undefined4 *)(param_1[0x20] + 0xc);
  pvVar2 = strings_createParser((int)param_1,param_4,param_5,param_6,param_7,param_3);
  if (pvVar2 == (void *)0x0) {
    return (int *)0x0;
  }
  piVar3 = xtra_compileScript(param_1,param_2,uVar1,(uint *)0x0);
  if ((piVar3 == (int *)0x0) && (param_1[0xd] == 0)) {
    runtime_isNaN((uint)param_1);
  }
  return piVar3;
}



// ============================================================
// Function: xtra_getInterfacePtr (FUN_6811e830)
// Address: 6811e830
// Size: 9 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_getInterfacePtr(int param_1,int param_2)
{
  runtime_getObjectPrototype(param_1,param_2);
  return 0;
}



// ============================================================
// Function: xtra_createProperty (FUN_6811e840)
// Address: 6811e840
// Size: 101 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3, uint param_4
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * xtra_createProperty(int param_1,undefined4 *param_2,undefined4 param_3,uint param_4)

{
  uint *puVar1;
  int iVar2;
  uint *puVar3;
  
  puVar1 = (uint *)crypto_createBinaryOp(param_1,param_3,param_4 & 0xffff7fff,~(param_4 >> 0xf) & 1);
  if (puVar1 == (uint *)0x0) {
    return (uint *)0x0;
  }
  iVar2 = crypto_evalDecompileWrapper((int *)puVar1,param_2);
  if (iVar2 != 0) {
    puVar3 = crypto_getOperandType(puVar1);
    crypto_getOperandCount(puVar1);
    return puVar3;
  }
  crypto_getOperandCount(puVar1);
  return (uint *)0x0;
}



// ============================================================
// Function: xtra_processExtension (FUN_6811e8b0)
// Address: 6811e8b0
// Size: 61 bytes
// Params: uint param_1, uint param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_processExtension(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = certs_processExtension(param_1,param_2,param_3,0,0,param_4);
  if (iVar1 == 0) {
    if (*(int *)(param_1 + 0x34) == 0) {
      runtime_isNaN(param_1);
    }
    return 0;
  }
  return 1;
}



// ============================================================
// Function: xtra_validateExtension (FUN_6811e8f0)
// Address: 6811e8f0
// Size: 67 bytes
// Params: uint param_1, int param_2, int param_3, uint param_4, int param_5, int * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_validateExtension(uint param_1,int param_2,int param_3,uint param_4,int param_5,int *param_6)

{
  uint uVar1;
  
  uVar1 = certs_validateExtension(param_1,param_2,param_3,0,param_4,param_5,param_6);
  if (uVar1 == 0) {
    if (*(int *)(param_1 + 0x34) == 0) {
      runtime_isNaN(param_1);
    }
    return 0;
  }
  return 1;
}



// ============================================================
// Function: xtra_setInterruptHandler (FUN_6811e940)
// Address: 6811e940
// Size: 25 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_setInterruptHandler(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x144);
  *(undefined4 *)(param_1 + 0x144) = param_2;
  return uVar1;
}



// ============================================================
// Function: xtra_getScriptContextEx (FUN_6811e960)
// Address: 6811e960
// Size: 108 bytes
// Params: uint param_1, int param_2, undefined4 param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * xtra_getScriptContextEx(uint param_1,int param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  bool bVar3;
  short *psVar4;
  uint *puVar5;
  undefined3 extraout_var;
  
  uVar1 = param_1;
  psVar4 = certs_createSubstring(param_1,param_2,param_3,&param_1);
  if (psVar4 == (short *)0x0) {
    return (uint *)0x0;
  }
  puVar5 = certs_allocHashEntry(uVar1,(uint)psVar4,param_1,0);
  iVar2 = param_2;
  if (puVar5 == (uint *)0x0) {
    xtra_checkAndFlush(uVar1,(int)psVar4);
    return (uint *)0x0;
  }
  bVar3 = certificates_cacheString((uint)puVar5,param_2);
  if (CONCAT31(extraout_var,bVar3) == 0) {
    xtra_checkAndFlush(uVar1,iVar2);
  }
  return puVar5;
}



// ============================================================
// Function: xtra_allocHashEntry (FUN_6811e9d0)
// Address: 6811e9d0
// Size: 74 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * xtra_allocHashEntry(int param_1,undefined4 param_2,uint param_3)

{
  short *psVar1;
  uint *puVar2;
  
  psVar1 = certs_createSubstring(param_1,param_2,param_3,&param_3);
  if (psVar1 == (short *)0x0) {
    return (uint *)0x0;
  }
  puVar2 = certs_allocHashEntry(param_1,(uint)psVar1,param_3,0);
  if (puVar2 == (uint *)0x0) {
    xtra_checkAndFlush(param_1,(int)psVar1);
  }
  return puVar2;
}



// ============================================================
// Function: xtra_findSymbolByName (FUN_6811ea20)
// Address: 6811ea20
// Size: 105 bytes
// Params: uint param_1, char * param_2
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * xtra_findSymbolByName(uint param_1,char *param_2)

{
  char cVar1;
  uint uVar2;
  char *pcVar3;
  short *psVar4;
  uint *puVar5;
  
  uVar2 = param_1;
  if (param_2 == (char *)0x0) {
    return *(uint **)(*(int *)(param_1 + 0x14) + 0x1dc);
  }
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  psVar4 = certs_createSubstring(param_1,param_2,(int)pcVar3 - (int)(param_2 + 1),&param_1);
  if (psVar4 == (short *)0x0) {
    return (uint *)0x0;
  }
  puVar5 = certs_allocHashEntry(uVar2,(uint)psVar4,param_1,0);
  if (puVar5 == (uint *)0x0) {
    xtra_checkAndFlush(uVar2,(int)psVar4);
  }
  return puVar5;
}



// ============================================================
// Function: xtra_lookupAtomValue (FUN_6811ea90)
// Address: 6811ea90
// Size: 57 bytes
// Params: int param_1, char * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtra_lookupAtomValue(int param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = javascript_registerAtom(param_1,param_2,(int)pcVar2 - (int)(param_2 + 1),2);
  if (iVar3 == 0) {
    return 0;
  }
  return *(uint *)(iVar3 + 8) & 0xfffffff8;
}



// ============================================================
// Function: xtra_allocHashEntryDirect (FUN_6811ead0)
// Address: 6811ead0
// Size: 26 bytes
// Params: int param_1, uint param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_allocHashEntryDirect(int param_1,uint param_2,uint param_3)
{
  certs_allocHashEntry(param_1,param_2,param_3,0);
  return 0;
}



// ============================================================
// Function: xtra_allocFromPool (FUN_6811eaf0)
// Address: 6811eaf0
// Size: 26 bytes
// Params: int param_1, void * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_allocFromPool(int param_1,void *param_2,uint param_3)
{
  int local_14;
  certs_allocFromPool(param_1,param_2,param_3,0);
  return 0;
}



// ============================================================
// Function: xtra_getStringValue (FUN_6811eb10)
// Address: 6811eb10
// Size: 25 bytes
// Params: uint * param_1
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

undefined * xtra_getStringValue(uint *param_1)

{
  undefined *puVar1;
  
  puVar1 = (undefined *)certs_encodeUri(param_1);
  if (puVar1 == (undefined *)0x0) {
    puVar1 = "";
  }
  return puVar1;
}



// ============================================================
// Function: xtra_getStringData (FUN_6811eb30)
// Address: 6811eb30
// Size: 92 bytes
// Params: uint * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtra_getStringData(uint *param_1)

{
  uint *puVar1;
  uint uVar2;
  
  uVar2 = crypto_flattenString(param_1);
  if (uVar2 == 0) {
    uVar2 = *param_1;
    if ((uVar2 & 0x40000000) != 0) {
      puVar1 = (uint *)param_1[1];
      if ((*puVar1 & 0x40000000) != 0) {
        uVar2 = crypto_getStringLen(param_1);
        return uVar2;
      }
      if ((int)uVar2 < 0) {
        return puVar1[1];
      }
      return puVar1[1] + (uVar2 >> 0xf & 0x7fff) * 2;
    }
    uVar2 = param_1[1];
  }
  return uVar2;
}



// ============================================================
// Function: xtra_getStringLength (FUN_6811eb90)
// Address: 6811eb90
// Size: 43 bytes
// Params: uint * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtra_getStringLength(uint *param_1)

{
  uint uVar1;
  
  uVar1 = *param_1;
  if ((uVar1 & 0x40000000) != 0) {
    uVar1 = (-(uint)((uVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar1;
  }
  return uVar1;
}



// ============================================================
// Function: xtra_normalizeString (FUN_6811ebc0)
// Address: 6811ebc0
// Size: 45 bytes
// Params: int param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_normalizeString(int param_1,uint *param_2)

{
  uint uVar1;
  byte *pbVar2;
  
  uVar1 = crypto_normalizeString(param_1,param_2);
  if (uVar1 == 0) {
    return 0;
  }
  pbVar2 = (byte *)js_getAtomSize((uint)param_2);
  *pbVar2 = *pbVar2 & 0xfd;
  return 1;
}



// ============================================================
// Function: xtra_invokeMethod (FUN_6811ebf0)
// Address: 6811ebf0
// Size: 34 bytes
// Params: uint param_1, undefined * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_invokeMethod(uint param_1,undefined *param_2,undefined4 param_3,undefined4 param_4)
{
  runtime_dispatchBreakpoint(param_1,0,param_2,param_3,param_4,1,(undefined4 *)&stack0x00000014);
  return 0;
}



// ============================================================
// Function: xtra_invokeWithArgs (FUN_6811ec20)
// Address: 6811ec20
// Size: 36 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_invokeWithArgs(uint param_1,uint param_2,undefined *param_3,undefined4 param_4,undefined4 param_5)
{
  runtime_dispatchBreakpoint(param_1,param_2,param_3,param_4,param_5,1,(undefined4 *)&stack0x00000018);
  return 0;
}



// ============================================================
// Function: xtra_reportError (xtra_reportError)
// Address: 6811ec50
// Size: 21 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_reportError(int param_1)
{
  xtra_dispatchError(param_1,xtra_getErrorString);
  return 0;
}



// ============================================================
// Function: xtra_setPropertyDirect (FUN_6811ec70)
// Address: 6811ec70
// Size: 25 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_setPropertyDirect(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x148);
  *(undefined4 *)(param_1 + 0x148) = param_2;
  return uVar1;
}



// ============================================================
// Function: xtra_initScriptState (FUN_6811ec90)
// Address: 6811ec90
// Size: 133 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_initScriptState(int param_1)
{
  *(undefined4 *)(param_1 + 0xb4) = 0;
  *(undefined4 *)(param_1 + 0xb8) = 0;
  *(undefined4 *)(param_1 + 0xbc) = 0;
  *(undefined4 *)(param_1 + 0x118) = DAT_681948f8;
  *(undefined **)(param_1 + 0x11c) = PTR_DAT_681948fc;
  *(undefined4 *)(param_1 + 0x110) = DAT_681948f8;
  *(undefined **)(param_1 + 0x114) = PTR_DAT_681948fc;
  *(undefined4 *)(param_1 + 0x128) = DAT_681948f8;
  *(undefined **)(param_1 + 300) = PTR_DAT_681948fc;
  *(undefined4 *)(param_1 + 0x120) = DAT_681948f8;
  *(undefined **)(param_1 + 0x124) = PTR_DAT_681948fc;
  *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x60) = 1;
  return 0;
}



// ============================================================
// Function: xtra_getStrictMode (FUN_6811ed20)
// Address: 6811ed20
// Size: 17 bytes
// Params: int param_1
// Return: undefined1
// Calling convention: __stdcall
// ============================================================

undefined1 xtra_getStrictMode(int param_1)

{
  return *(undefined1 *)(param_1 + 0x15a);
}



// ============================================================
// Function: xtra_getInterruptData (FUN_6811ed40)
// Address: 6811ed40
// Size: 41 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getInterruptData(int param_1,undefined4 *param_2)

{
  if (*(char *)(param_1 + 0x15a) == '\0') {
    return 0;
  }
  *param_2 = *(undefined4 *)(param_1 + 0x15c);
  return 1;
}



// ============================================================
// Function: xtra_setInterruptData (FUN_6811ed70)
// Address: 6811ed70
// Size: 26 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_setInterruptData(int param_1,undefined4 param_2)
{
  *(undefined1 *)(param_1 + 0x15a) = 1;
  *(undefined4 *)(param_1 + 0x15c) = param_2;
  return 0;
}



// ============================================================
// Function: xtra_clearInterrupt (FUN_6811ed90)
// Address: 6811ed90
// Size: 17 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_clearInterrupt(int param_1)
{
  *(undefined1 *)(param_1 + 0x15a) = 0;
  return 0;
}



// ============================================================
// Function: xtra_releaseObject (FUN_6811edb0)
// Address: 6811edb0
// Size: 57 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_releaseObject(int param_1,int *param_2)
{
  if (param_2 != (int *)0x0) {
    if (*param_2 != 0) {
      if (((param_2[1] & 1U) == 0) && (((byte)param_2[1] & 7) != 6)) {
        xtraRuntime_markAtomIndirect(param_1,param_2 + 1);
      }
    }
    xtra_checkAndFlush(param_1,(int)param_2);
  }
  return 0;
}



// ============================================================
// Function: xtra_convertValue (FUN_6811edf0)
// Address: 6811edf0
// Size: 396 bytes
// Params: ushort * param_1, uint param_2, undefined4 param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_convertValue(ushort *param_1,uint param_2,undefined4 param_3,uint *param_4)
{
  uint uVar1;
  int iVar2;
  double local_28;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined1 local_14 [12];
  uint local_8;
  
  local_1c = param_2;
  switch(param_3) {
  case 0:
    *param_4 = 0x80000001;
    return 0;
  case 1:
    iVar2 = runtime_deleteProperty((uint)param_1,param_2,&local_20);
    if (iVar2 != 0) {
      *param_4 = local_20;
      return 0;
    }
    break;
  case 2:
    uVar1 = runtime_callFunction((int)param_1,&local_1c,0);
    if (uVar1 != 0) {
      *param_4 = *(uint *)(uVar1 + 4);
      return 0;
    }
    break;
  case 3:
    uVar1 = certs_hashLookup((int)param_1,param_2);
    if (uVar1 != 0) {
      *param_4 = uVar1 | 4;
      return 0;
    }
    break;
  case 4:
    iVar2 = runtime_parseNumber(param_1,param_2,&local_28);
    if ((iVar2 != 0) && (uVar1 = runtime_storeFloat((int)param_1,local_28), uVar1 != 0)) {
      *param_4 = uVar1 | 2;
      return 0;
    }
    break;
  case 5:
    iVar2 = js_getDateComponent((int)param_1,param_2,&local_18);
    if (iVar2 != 0) {
      *param_4 = local_18 * 8 | 6;
      return 0;
    }
    break;
  default:
    runtime_snprintf(local_14,0xc,"%d");
    xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,5);
  }
  return 0;
}



// ============================================================
// Function: xtra_initRuntime (FUN_6811efa0)
// Address: 6811efa0
// Size: 145 bytes
// Params: undefined4 param_1
// Return: void *
// Calling convention: __stdcall
// ============================================================

void * xtra_initRuntime(undefined4 param_1)

{
  bool bVar1;
  int iVar2;
  void *_Dst;
  undefined3 extraout_var;
  
  iVar2 = certificates_initStringTable();
  if (iVar2 == 0) {
    return (void *)0x0;
  }
  _Dst = (void *)js_runGC();
  if (_Dst != (void *)0x0) {
    memset(_Dst,0,0x22a0);
    iVar2 = javascript_initGcArena((int)_Dst,param_1);
    if (iVar2 != 0) {
      *(undefined4 *)((int)_Dst + 0x2248) = 1;
      bVar1 = strings_initPropertyTable((int)_Dst);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        iVar2 = (int)_Dst + 0x1e0;
        *(int *)((int)_Dst + 0x1e4) = iVar2;
        *(int *)(size_t)iVar2 = iVar2;
        iVar2 = (int)_Dst + 0x238;
        *(int *)((int)_Dst + 0x23c) = iVar2;
        *(int *)(size_t)iVar2 = iVar2;
        iVar2 = (int)_Dst + 0x240;
        *(int *)((int)_Dst + 0x244) = iVar2;
        *(int *)(size_t)iVar2 = iVar2;
        return _Dst;
      }
    }
    xtraRuntime_destroyRuntime((int)_Dst);
  }
  return (void *)0x0;
}



// ============================================================
// Function: xtra_initGlobalScope (FUN_6811f040)
// Address: 6811f040
// Size: 227 bytes
// Params: int * param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * xtra_initGlobalScope(int *param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  int *piVar5;
  uint uVar6;
  int *local_c;
  uint local_8;
  
  piVar3 = param_1;
  if (param_1[0x23] == 0) {
    param_1[0x23] = (int)param_2;
  }
  iVar1 = param_1[0x5b];
  param_1 = (int *)0x0;
  if (iVar1 != 0) {
    param_1 = (int *)piVar3[0x5c];
    iVar2 = piVar3[5];
    local_c = param_2;
    local_8 = *(uint *)(iVar2 + 0xb8);
    puVar4 = js_getPropertySlot(param_1,&local_c,0);
    if (*puVar4 != 0) {
      local_8 = *(uint *)(iVar2 + 0xc4);
    }
    puVar4 = js_getPropertySlot(param_1,&local_c,1);
    if (puVar4 == (uint *)0x0) {
      xtra_reportError((int)piVar3);
      return (int *)0x0;
    }
    puVar4[1] = (uint)local_c;
    puVar4[2] = local_8;
  }
  piVar5 = runtime_initFunctionPrototype((int)piVar3,param_2);
  if ((piVar5 != (int *)0x0) && (uVar6 = runtime_initGlobalObject((int)piVar3,param_2), uVar6 != 0)) {
    *(uint *)piVar5[1] = uVar6;
    if ((*(uint *)param_2[1] & 0xfffffff8) == 0) {
      *(uint *)param_2[1] = uVar6;
    }
    if (iVar1 != 0) {
      js_getPropertySlot(param_1,&local_c,2);
    }
    return piVar5;
  }
  return (int *)0x0;
}



// ============================================================
// Function: xtra_initBuiltins (FUN_6811f130)
// Address: 6811f130
// Size: 191 bytes
// Params: uint * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_initBuiltins(uint *param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  
  iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0xc))
                    (param_1,param_2,*(undefined4 *)(param_1[5] + 0x7c),0x80000001,0,0,4,0);
  if (iVar1 != 0) {
    piVar2 = xtra_initGlobalScope((int *)param_1,param_2);
    if (piVar2 != (int *)0x0) {
      piVar2 = javascript_createArrayObject(param_1,param_2);
      if (piVar2 != (int *)0x0) {
        iVar1 = javascript_numberToString((int)param_1,param_2);
        if (iVar1 != 0) {
          uVar3 = javascript_initMathObject((int)param_1,(uint)param_2);
          if (uVar3 != 0) {
            uVar3 = runtime_initNumberPrototype((uint)param_1,param_2);
            if (uVar3 != 0) {
              piVar2 = certificates_createStringPrototype((int)param_1,param_2);
              if (piVar2 != (int *)0x0) {
                iVar1 = runtime_initArgumentsPrototype((int)param_1,param_2);
                if (iVar1 != 0) {
                  piVar2 = javascript_initRegExpClass(param_1,param_2);
                  if (piVar2 != (int *)0x0) {
                    iVar1 = runtime_initScriptPrototype((int)param_1,param_2);
                    if (iVar1 != 0) {
                      uVar3 = runtime_initErrorClasses((uint)param_1,param_2);
                      if (uVar3 != 0) {
                        piVar2 = javascript_createDateObject((uint)param_1,param_2);
                        if (piVar2 != (int *)0x0) {
                          return 1;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_getPropertyById (FUN_6811f1f0)
// Address: 6811f1f0
// Size: 52 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_getPropertyById(int param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  if (param_2 == 0) {
    param_2 = 1;
  }
  piVar1 = (int *)(*(int *)(param_1 + 0x14) + 0x68);
  *piVar1 = *piVar1 + param_2;
  iVar2 = js_runGC();
  if (iVar2 == 0) {
    xtra_reportError(param_1);
  }
  return iVar2;
}



// ============================================================
// Function: xtra_allocJSString (FUN_6811f230)
// Address: 6811f230
// Size: 39 bytes
// Params: int param_1, int param_2, uint param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_allocJSString(int param_1,int param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = js_allocAtomBlock(param_2,param_3);
  if (iVar1 == 0) {
    xtra_reportError(param_1);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_findMethodByName (FUN_6811f260)
// Address: 6811f260
// Size: 65 bytes
// Params: int param_1, char * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_findMethodByName(int param_1,char *param_2)
{
  char cVar1;
  char *pcVar2;
  void *_Dst;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  _Dst = (void *)xtra_getPropertyById(param_1,(int)(pcVar2 + (1 - (int)(param_2 + 1))));
  if (_Dst == (void *)0x0) {
    return 0;
  }
  memcpy(_Dst,param_2,(size_t)(pcVar2 + (1 - (int)(param_2 + 1))));
  return 0;
}



// ============================================================
// Function: xtra_getMethodById (FUN_6811f2b0)
// Address: 6811f2b0
// Size: 49 bytes
// Params: uint param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_getMethodById(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = js_getAtomString(param_1,param_2);
  if (iVar1 == 0) {
    xtra_invokeMethod(param_1,xtra_getErrorString,0,6);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_resolveMethodId (FUN_6811f2f0)
// Address: 6811f2f0
// Size: 52 bytes
// Params: uint param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_resolveMethodId(uint param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = js_freeAtom(*(int *)(param_1 + 0x14),param_2);
  if (iVar1 == 0) {
    xtra_invokeMethod(param_1,xtra_getErrorString,0,7);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_lookupConstructor (FUN_6811f330)
// Address: 6811f330
// Size: 113 bytes
// Params: uint param_1, int * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtra_lookupConstructor(uint param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))
                    (param_1,param_2,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xec),&param_2);
  if (iVar1 != 0) {
    if (((((uint)param_2 & 7) == 0) && (((uint)param_2 & 0xfffffff8) != 0)) &&
       ((undefined **)(*(uint *)(*(int *)(((uint)param_2 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
        &PTR_s_Function_681928b8)) {
      return (uint)param_2 & 0xfffffff8;
    }
    xtra_invokeMethod(param_1,xtra_getErrorString,0,9);
  }
  return 0;
}



// ============================================================
// Function: xtra_matchMethodName (FUN_6811f3b0)
// Address: 6811f3b0
// Size: 281 bytes
// Params: uint param_1, int * param_2, char * param_3, char * param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool xtra_matchMethodName(uint param_1,int *param_2,char *param_3,char *param_4)

{
  char cVar1;
  undefined **ppuVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  char *pcVar6;
  uint uVar7;
  bool bVar8;
  
  pcVar6 = param_3;
  piVar4 = param_2;
  iVar5 = xtraRuntime_registerAtomByName(&param_2,param_3);
  if (iVar5 != 0) {
    if (param_3 == (char *)0x0) {
      runtime_addBreakpoint(param_1,pcVar6);
      return false;
    }
    if ((param_2 == piVar4) &&
       ((ppuVar2 = *(undefined ***)(*piVar4 + 4), ppuVar2 == &PTR_FUN_68192948 ||
        ((ppuVar2 != (undefined **)0x0 && (*ppuVar2 == PTR_FUN_68192948)))))) {
      pcVar6 = param_4;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      uVar7 = javascript_registerAtom(param_1,param_4,(int)pcVar6 - (int)(param_4 + 1),0);
      if (uVar7 == 0) {
        bVar8 = false;
      }
      else {
        iVar5 = runtime_callPropertyEx(param_1,piVar4,uVar7,*(undefined **)(param_3 + 4),
                             *(undefined **)(param_3 + 8),*(int *)(param_3 + 0xc),
                             (uint)(byte)param_3[0x10],(byte)param_3[0x11] | 4,
                             (int)*(short *)(param_3 + 0x12));
        bVar8 = iVar5 != 0;
      }
      pcVar3 = *(code **)(*(int *)(*piVar4 + 4) + 0x34);
      if (pcVar3 != (code *)0x0) {
        (*pcVar3)(param_1,piVar4,param_3);
      }
      return bVar8;
    }
    pcVar3 = *(code **)(*(int *)(*param_2 + 4) + 0x34);
    if (pcVar3 != (code *)0x0) {
      (*pcVar3)(param_1,param_2,param_3);
    }
    xtra_invokeMethod(param_1,xtra_getErrorString,0,10);
  }
  return false;
}



// ============================================================
// Function: xtra_registerNamedMethod (FUN_6811f4d0)
// Address: 6811f4d0
// Size: 28 bytes
// Params: int param_1, int * param_2, char * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_registerNamedMethod(int param_1,int *param_2,char *param_3)
{
  xtraRuntime_deletePropertyByName(param_1,param_2,param_3,&param_3);
  return 0;
}



// ============================================================
// Function: xtra_getScriptProperty (FUN_6811f4f0)
// Address: 6811f4f0
// Size: 128 bytes
// Params: undefined4 param_1, int * param_2, uint param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getScriptProperty(uint param_1,int *param_2,uint param_3,undefined4 *param_4)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_2[1] + 8) & 0xfffffffe;
  if (*(byte *)(uVar2 + 5) <= param_3) {
    xtra_invokeMethod(param_1,xtra_getErrorString,0,0xa6);
    return 0;
  }
  pcVar1 = *(code **)(*(int *)(*param_2 + 4) + 0x58);
  if (pcVar1 != (code *)0x0) {
    uVar3 = (*pcVar1)(param_1,param_2,param_3 + ((*(byte *)(uVar2 + 4) & 1) != 0) + 3);
    *param_4 = uVar3;
    return 1;
  }
  *param_4 = 0x80000001;
  return 1;
}



// ============================================================
// Function: xtra_setScriptProperty (FUN_6811f570)
// Address: 6811f570
// Size: 111 bytes
// Params: undefined4 param_1, int * param_2, uint param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_setScriptProperty(uint param_1,int *param_2,uint param_3,undefined4 param_4)

{
  code *pcVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_2[1] + 8) & 0xfffffffe;
  if (*(byte *)(uVar2 + 5) <= param_3) {
    xtra_invokeMethod(param_1,xtra_getErrorString,0,0xa6);
    return 0;
  }
  pcVar1 = *(code **)(*(int *)(*param_2 + 4) + 0x5c);
  if (pcVar1 != (code *)0x0) {
    (*pcVar1)(param_1,param_2,((*(byte *)(uVar2 + 4) & 1) != 0) + 3 + param_3,param_4);
  }
  return 1;
}



// ============================================================
// Function: xtra_setScriptPropertyEx (FUN_6811f5e0)
// Address: 6811f5e0
// Size: 38 bytes
// Params: int param_1
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * xtra_setScriptPropertyEx(int param_1)

{
  char *pcVar1;
  
  if (*(int *)(param_1 + 0x18) != 0) {
    pcVar1 = xtra_getStringValue((uint *)(*(uint *)(*(int *)(param_1 + 0x18) + 8) & 0xfffffff8));
    return pcVar1;
  }
  return "anonymous";
}



// ============================================================
// Function: events_attachVtable (FUN_6811f610)
// Address: 6811f610
// Size: 91 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 events_attachVtable(int param_1,int *param_2,int *param_3)

{
  byte *pbVar1;
  int iVar2;
  byte *pbVar3;
  
  if (*param_3 != 0) {
    pbVar3 = (byte *)(param_3 + 2);
    do {
      iVar2 = xtra_registerMethod(param_1,param_2,*(char **)(pbVar3 + -8),*(int *)(pbVar3 + -4),
                           (ushort)*pbVar3,(uint)pbVar3[1]);
      if (iVar2 == 0) {
        return 0;
      }
      *(undefined2 *)(iVar2 + 0x12) = *(undefined2 *)(pbVar3 + 2);
      pbVar1 = pbVar3 + 4;
      pbVar3 = pbVar3 + 0xc;
    } while (*(int *)pbVar1 != 0);
  }
  return 1;
}



// ============================================================
// Function: xtra_evalScriptString (FUN_6811f680)
// Address: 6811f680
// Size: 38 bytes
// Params: uint * param_1, int * param_2, int param_3, int param_4, undefined4 param_5, undefined4 param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_evalScriptString(uint *param_1,int *param_2,int param_3,int param_4,undefined4 param_5,
                 undefined4 param_6)
{
  xtra_evalScriptBuffer(param_1,param_2,0,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: xtra_createPropertyByName (FUN_6811f6b0)
// Address: 6811f6b0
// Size: 105 bytes
// Params: int param_1, int param_2, uint param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * xtra_createPropertyByName(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  char *pcVar2;
  uint *puVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  
  uVar6 = ~(param_3 >> 0xf) & 1;
  uVar1 = param_3 & 0xffff7fff;
  pcVar2 = xtra_setScriptPropertyEx(param_2);
  puVar3 = (uint *)crypto_createBinaryOp(param_1,pcVar2,uVar1,uVar6);
  if (puVar3 == (uint *)0x0) {
    return (uint *)0x0;
  }
  iVar4 = crypto_decompileArrayAccess((int *)puVar3,param_2);
  if (iVar4 != 0) {
    puVar5 = crypto_getOperandType(puVar3);
    crypto_getOperandCount(puVar3);
    return puVar5;
  }
  crypto_getOperandCount(puVar3);
  return (uint *)0x0;
}



// ============================================================
// Function: xtra_allocScriptBlock (FUN_6811f720)
// Address: 6811f720
// Size: 71 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * xtra_allocScriptBlock(int param_1)

{
  int *piVar1;
  int iVar2;
  uint *extraout_EDX;
  
  piVar1 = (int *)xtra_getPropertyById(param_1,8);
  if (piVar1 != (int *)0x0) {
    iVar2 = xtra_getInterruptData(param_1,piVar1 + 1);
    *piVar1 = iVar2;
    if (((iVar2 != 0) && ((*extraout_EDX & 1) == 0)) && (((byte)*extraout_EDX & 7) != 6)) {
      js_internAtom(param_1,(uint)extraout_EDX,0x6817d258);
    }
  }
  return piVar1;
}



// ============================================================
// Function: xtra_storeResult (FUN_6811f770)
// Address: 6811f770
// Size: 59 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_storeResult(int param_1,int *param_2)
{
  int *extraout_EDX;
  int *extraout_EDX_00;
  
  if (param_2 != (int *)0x0) {
    if (*param_2 != 0) {
      xtra_setInterruptData(param_1,param_2[1]);
      xtra_releaseObject(param_1,extraout_EDX);
      return 0;
    }
    xtra_clearInterrupt(param_1);
    xtra_releaseObject(param_1,extraout_EDX_00);
  }
  return 0;
}



// ============================================================
// Function: xtra_createScriptObject (FUN_6811f7b0)
// Address: 6811f7b0
// Size: 329 bytes
// Params: int param_1, int * param_2, undefined4 * param_3, undefined4 * param_4, int param_5, undefined2 param_6, int * param_7, int * param_8, int * param_9, int * param_10
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * xtra_createScriptObject(int param_1,int *param_2,undefined4 *param_3,undefined4 *param_4,int param_5,
                  undefined2 param_6,int *param_7,int *param_8,int *param_9,int *param_10)

{
  char cVar1;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined1 local_8 [4];
  
  pcVar2 = (char *)*param_4;
  pcVar3 = pcVar2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar4 = javascript_registerAtom(param_1,pcVar2,(int)pcVar3 - (int)(pcVar2 + 1),0);
  if (iVar4 == 0) {
    return (int *)0x0;
  }
  piVar5 = runtime_setProperty(param_1,param_4,param_3,(uint)param_2);
  if (piVar5 == (int *)0x0) {
    return (int *)0x0;
  }
  if (param_5 == 0) {
    param_3 = (undefined4 *)
              (**(code **)(*(int *)(*param_2 + 4) + 0xc))(param_1,param_2,iVar4,piVar5,0,0,0);
    piVar8 = piVar5;
    if (param_3 == (undefined4 *)0x0) goto LAB_6811f8d9;
LAB_6811f870:
    if (((((param_7 == (int *)0x0) || (iVar7 = xtra_queryPlatform(param_1,piVar5,param_7), iVar7 != 0)) &&
         ((param_8 == (int *)0x0 || (iVar7 = events_attachVtable(param_1,piVar5,param_8), iVar7 != 0)))) &&
        ((param_9 == (int *)0x0 || (iVar7 = xtra_queryPlatform(param_1,piVar8,param_9), iVar7 != 0)))) &&
       ((param_10 == (int *)0x0 || (iVar7 = events_attachVtable(param_1,piVar8,param_10), iVar7 != 0)))) {
      return piVar5;
    }
  }
  else {
    uVar6 = runtime_registerFunction(param_1,param_2,iVar4,param_5,param_6,0);
    param_3 = (undefined4 *)(uint)(uVar6 != 0);
    if (uVar6 != 0) {
      piVar8 = *(int **)(uVar6 + 4);
      *(undefined4 **)(uVar6 + 0x1c) = param_4;
      iVar7 = runtime_copyPropertyDescriptor(param_1,piVar8,piVar5,6);
      if (iVar7 != 0) {
        if ((undefined4 *)(((undefined4 *)piVar8[1])[2] & 0xfffffffe) == param_4) {
          *(undefined4 *)piVar8[1] = piVar5;
        }
        goto LAB_6811f870;
      }
    }
  }
  if (param_3 != (undefined4 *)0x0) {
    (**(code **)(*(int *)(*param_2 + 4) + 0x20))(param_1,param_2,iVar4,local_8);
  }
LAB_6811f8d9:
  *(undefined4 *)(param_1 + 0x90) = 0;
  return (int *)0x0;
}



// ============================================================
// Function: xtra_callMethod (FUN_6811f900)
// Address: 6811f900
// Size: 111 bytes
// Params: undefined4 param_1, int param_2, undefined4 * param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_callMethod(uint param_1,int param_2,undefined4 *param_3,int param_4)

{
  uint uVar1;
  
  if ((undefined4 *)(*(uint *)(*(int *)(param_2 + 4) + 8) & 0xfffffffe) != param_3) {
    if ((param_4 != 0) && (uVar1 = runtime_callFunction(param_1,(uint *)(param_4 + -8),0), uVar1 != 0)) {
      xtra_setScriptPropertyEx(uVar1);
      xtra_invokeMethod(param_1,xtra_getErrorString,0,8);
    }
    return 0;
  }
  return 1;
}



// ============================================================
// Function: xtra_callMethodEx (FUN_6811f970)
// Address: 6811f970
// Size: 49 bytes
// Params: undefined4 param_1, int param_2, undefined4 * param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_callMethodEx(undefined4 param_1,int param_2,undefined4 *param_3,int param_4)
{
  int iVar1;
  
  iVar1 = xtra_callMethod(param_1,param_2,param_3,param_4);
  if (iVar1 == 0) {
    return 0;
  }
  xtra_getObjectTag(param_1,param_2);
  return 0;
}



// ============================================================
// Function: xtra_evalSubstring (FUN_6811f9b0)
// Address: 6811f9b0
// Size: 80 bytes
// Params: uint * param_1, int * param_2, undefined4 param_3, uint param_4, undefined4 param_5, undefined4 param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
xtra_evalSubstring(uint *param_1,int *param_2,undefined4 param_3,uint param_4,undefined4 param_5,
            undefined4 param_6)

{
  short *psVar1;
  undefined4 uVar2;
  
  psVar1 = certs_createSubstring((int)param_1,param_3,param_4,&param_4);
  if (psVar1 == (short *)0x0) {
    return 0;
  }
  uVar2 = xtra_evalScriptString(param_1,param_2,(int)psVar1,param_4,param_5,param_6);
  xtra_checkAndFlush(param_1,(int)psVar1);
  return uVar2;
}



// ============================================================
// Function: xtra_destroyContext (FUN_6811fa00)
// Address: 6811fa00
// Size: 296 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_destroyContext(int *param_1,int param_2)
{
  undefined4 *puVar1;
  char cVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  
  puVar3 = (undefined4 *)param_1[5];
  *(int *)param_1[1] = *param_1;
  *(int *)(*param_1 + 4) = param_1[1];
  puVar1 = puVar3 + 0x78;
  puVar4 = (undefined4 *)*puVar1;
  if (puVar4 == puVar1) {
    *puVar3 = 3;
    javascript_gcClearAllMarks((int)(puVar3 + 0x1b));
    runtime_freeNumberAtoms((int)param_1);
    certificates_freeStringPool((int)param_1);
    runtime_clearAllBreakpoints((int)param_1);
    runtime_checkAllWatchStates((int)param_1);
  }
  javascript_regexpMark((int)param_1,(int)(param_1 + 0x2d));
  if (puVar4 != puVar1) {
    if (param_2 == 2) {
      javascript_gcProcessRoots((int)param_1,0);
    }
    else if (param_2 == 1) {
      xtraRuntime_checkGcThreshold((int)param_1);
    }
  }
  else {
    javascript_gcProcessRoots((int)param_1,2);
    cVar2 = *(char *)(puVar3 + 0x18);
    while (cVar2 != '\0') {
      javascript_gcCollect((int)param_1,2);
      cVar2 = *(char *)(puVar3 + 0x18);
    }
    if (puVar3[0x1e] == 0) {
      javascript_gcClearTable(param_1,puVar3 + 0x1b);
    }
    *puVar3 = 0;
  }
  js_getPrototypeChain((int)(param_1 + 6));
  js_getPrototypeChain((int)(param_1 + 0xe));
  js_getPrototypeChain((int)(param_1 + 0x15));
  js_getPrototypeChain((int)(param_1 + 0x1c));
  if (param_1[0x50] != 0) {
    js_freeHandle();
  }
  iVar6 = param_1[0x4f];
  while (iVar6 != 0) {
    iVar5 = *(int *)(iVar6 + 0xc);
    xtra_checkAndFlush(param_1,iVar6);
    iVar6 = iVar5;
  }
  if ((int *)param_1[0x5c] != (int *)0x0) {
    javascript_hashTableDestroy((int *)param_1[0x5c]);
    param_1[0x5c] = 0;
  }
  js_freeHandle();
  return 0;
}



// ============================================================
// Function: xtra_iterateObjects (FUN_6811fb30)
// Address: 6811fb30
// Size: 41 bytes
// Params: int param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_iterateObjects(int param_1,undefined4 param_2,int *param_3)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_3;
  if (piVar1 == (int *)0x0) {
    piVar1 = (int *)(param_1 + 0x1e0);
  }
  iVar2 = *piVar1;
  if (iVar2 == param_1 + 0x1e0) {
    iVar2 = 0;
  }
  *param_3 = iVar2;
  return 0;
}



// ============================================================
// Function: xtra_dispatchError (FUN_6811fb60)
// Address: 6811fb60
// Size: 194 bytes
// Params: int param_1, undefined * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_dispatchError(int param_1,undefined *param_2)
{
  code *pcVar1;
  code *pcVar2;
  undefined4 *puVar3;
  int iVar4;
  char *pcVar5;
  undefined4 local_34;
  uint local_30;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_8;
  
  pcVar1 = *(code **)(param_1 + 0x148);
  iVar4 = *(int *)(param_1 + 0x34);
  puVar3 = (undefined4 *)(*(code *)param_2)(0,0,0x89);
  if (puVar3 == (undefined4 *)0x0) {
    pcVar5 = "Out of memory";
  }
  else {
    pcVar5 = (char *)*puVar3;
  }
  memset(&local_34,0,0x30);
  local_18 = 0x89;
  local_1c = 0;
  do {
    if (iVar4 == 0) {
LAB_6811fbea:
      if (pcVar1 != (code *)0x0) {
        pcVar2 = *(code **)(*(int *)(param_1 + 0x14) + 0x230);
        if ((pcVar2 == (code *)0x0) ||
           (iVar4 = (*pcVar2)(param_1,pcVar5,&local_34,
                              *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x234)), iVar4 != 0)) {
          (*pcVar1)(param_1,pcVar5,&local_34);
        }
      }
      return 0;
    }
    if ((*(int *)(iVar4 + 0xc) != 0) && (*(int *)(iVar4 + 0x38) != 0)) {
      local_34 = *(undefined4 *)(*(int *)(iVar4 + 0xc) + 0x18);
      local_30 = runtime_getObjectField(*(uint *)(iVar4 + 0xc),*(int *)(iVar4 + 0x38));
      local_8 = *(undefined4 *)(*(int *)(iVar4 + 0xc) + 0x34);
      goto LAB_6811fbea;
    }
    iVar4 = *(int *)(iVar4 + 0x2c);
  } while( true );
}



// ============================================================
// Function: xtra_formatError (FUN_6811fc30)
// Address: 6811fc30
// Size: 783 bytes
// Params: int param_1, undefined * param_2, undefined4 param_3, undefined4 param_4, int * param_5, int param_6, uint * param_7, int param_8, undefined4 * param_9
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_formatError(int param_1,undefined *param_2,undefined4 param_3,undefined4 param_4,int *param_5,
                 int param_6,uint *param_7,int param_8,undefined4 *param_9)
{
  char cVar1;
  byte bVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  char *pcVar6;
  short *psVar7;
  int iVar8;
  char *pcVar9;
  ushort *_Dst;
  undefined1 *puVar10;
  byte *pbVar11;
  int aiStackY_f0 [30];
  undefined4 uStackY_78;
  int local_58;
  char *local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 *local_48;
  int local_44;
  int local_40;
  undefined4 *local_3c;
  int *local_38;
  byte *local_34;
  int aiStack_30 [10];
  uint local_8;
  
  local_4c = param_4;
  local_3c = param_9;
  local_38 = param_5;
  uVar4 = *(uint *)(param_6 + 0x18) & 1;
  local_44 = param_1;
  *param_7 = uVar4;
  if ((uVar4 != 0) && ((*(byte *)(param_1 + 0x164) & 2) != 0)) {
    *(uint *)(param_6 + 0x18) = *(uint *)(param_6 + 0x18) & 0xfffffffe;
    *param_7 = 0;
  }
  *param_5 = 0;
  if (param_2 == (undefined *)0x0) {
LAB_6811feff:
    puVar10 = (undefined1 *)xtra_getPropertyById(param_1,0x3e);
    *local_38 = (int)puVar10;
    if (puVar10 != (undefined1 *)0x0) {
      uStackY_78 = 0x6811ff25;
      runtime_snprintf(puVar10,0x3e,"No error message available for error number %d");
LAB_6811ff28:
      return 0;
    }
  }
  else {
    local_48 = (undefined4 *)(*(code *)param_2)();
    if (local_48 == (undefined4 *)0x0) {
LAB_6811fef7:
      if (*local_38 != 0) goto LAB_6811ff28;
      goto LAB_6811feff;
    }
    pbVar11 = (byte *)local_48[1];
    local_40 = 0;
    local_34 = pbVar11;
    if (0 < (int)pbVar11) {
      iVar5 = xtra_getPropertyById(param_1,(int)pbVar11 * 4 + 4);
      *(int *)(param_6 + 0x24) = iVar5;
      if (iVar5 == 0) goto LAB_6811fea1;
      *(undefined4 *)(iVar5 + (int)pbVar11 * 4) = 0;
      iVar5 = 0;
      if (0 < (int)local_34) {
        local_3c = local_3c + -1;
        do {
          local_3c = local_3c + 1;
          if (param_8 == 0) {
            *(undefined4 *)(*(int *)(param_6 + 0x24) + iVar5 * 4) = *local_3c;
          }
          else {
            pcVar9 = (char *)*local_3c;
            local_54 = pcVar9 + 1;
            pcVar6 = pcVar9;
            do {
              cVar1 = *pcVar6;
              pcVar6 = pcVar6 + 1;
            } while (cVar1 != '\0');
            uStackY_78 = 0x6811fd26;
            psVar7 = certs_createSubstring(param_1,pcVar9,(int)pcVar6 - (int)local_54,&local_50);
            *(short **)(*(int *)(param_6 + 0x24) + iVar5 * 4) = psVar7;
            if (*(int *)(*(int *)(param_6 + 0x24) + iVar5 * 4) == 0) goto LAB_6811fe38;
          }
          iVar8 = certs_getStringLength(*(short **)(*(int *)(param_6 + 0x24) + iVar5 * 4));
          local_40 = local_40 + iVar8;
          aiStack_30[iVar5] = iVar8;
          iVar5 = iVar5 + 1;
        } while (iVar5 < (int)local_34);
      }
      *(undefined4 *)(*(int *)(param_6 + 0x24) + iVar5 * 4) = 0;
      pcVar9 = (char *)*local_48;
      if (pcVar9 != (char *)0x0) {
        pcVar6 = pcVar9 + 1;
        do {
          cVar1 = *pcVar9;
          pcVar9 = pcVar9 + 1;
        } while (cVar1 != '\0');
        _Dst = (ushort *)
               xtra_getPropertyById(param_1,(int)(pcVar9 + local_40 + ((int)local_34 * -3 - (int)pcVar6)) *
                                    2 + 2);
        *(ushort **)(param_6 + 0x20) = _Dst;
        if (_Dst != (ushort *)0x0) {
          pbVar11 = (byte *)*local_48;
          bVar2 = *pbVar11;
          while (local_34 = pbVar11, bVar2 != 0) {
            if ((bVar2 == 0x7b) && (iVar5 = isdigit((int)(char)pbVar11[1]), iVar5 != 0)) {
              iVar5 = aiStackY_f0[(char)pbVar11[1]];
              memcpy(_Dst,*(void **)(*(int *)(param_6 + 0x24) + -0xc0 + (char)pbVar11[1] * 4),
                     iVar5 * 2);
              _Dst = _Dst + iVar5;
              pbVar11 = local_34 + 3;
            }
            else {
              *_Dst = (ushort)*pbVar11;
              _Dst = _Dst + 1;
              pbVar11 = pbVar11 + 1;
            }
            bVar2 = *pbVar11;
          }
          *_Dst = 0;
          uStackY_78 = 0x6811fe28;
          iVar5 = certs_formatString(local_44,*(int *)(param_6 + 0x20),
                               (int)_Dst - *(int *)(param_6 + 0x20) >> 1,&local_58);
          *local_38 = iVar5;
          param_1 = local_44;
          if (iVar5 != 0) goto LAB_6811ff28;
        }
        goto LAB_6811fe38;
      }
      goto LAB_6811fef7;
    }
    if ((char *)*local_48 == (char *)0x0) goto LAB_6811fef7;
    pcVar9 = (char *)xtra_findMethodByName(param_1,(char *)*local_48);
    *local_38 = (int)pcVar9;
    if (pcVar9 != (char *)0x0) {
      pcVar6 = pcVar9;
      do {
        cVar1 = *pcVar6;
        pcVar6 = pcVar6 + 1;
      } while (cVar1 != '\0');
      uStackY_78 = 0x6811feec;
      psVar7 = certs_createSubstring(param_1,pcVar9,(int)pcVar6 - (int)(pcVar9 + 1),&local_50);
      *(short **)(param_6 + 0x20) = psVar7;
      if (psVar7 != (short *)0x0) goto LAB_6811fef7;
    }
  }
LAB_6811fe38:
  if (*(int **)(param_6 + 0x24) != (int *)0x0) {
    iVar5 = 0;
    if (**(int **)(param_6 + 0x24) != 0) {
      iVar8 = 0;
      do {
        xtra_checkAndFlush(param_1,*(int *)(iVar8 + *(int *)(param_6 + 0x24)));
        iVar5 = iVar5 + 1;
        iVar8 = iVar5 * 4;
      } while (*(int *)(iVar8 + *(int *)(param_6 + 0x24)) != 0);
    }
    xtra_checkAndFlush(param_1,*(int *)(param_6 + 0x24));
    *(undefined4 *)(param_6 + 0x24) = 0;
  }
  if (*(int *)(param_6 + 0x20) != 0) {
    xtra_checkAndFlush(param_1,*(int *)(param_6 + 0x20));
    *(undefined4 *)(param_6 + 0x20) = 0;
  }
  piVar3 = local_38;
  if (*local_38 != 0) {
    xtra_checkAndFlush(param_1,*local_38);
    *piVar3 = 0;
  }
LAB_6811fea1:
  return 0;
}



// ============================================================
// Function: xtra_reportErrorDirect (FUN_6811ff40)
// Address: 6811ff40
// Size: 109 bytes
// Params: int param_1, char * param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_reportErrorDirect(int param_1,char *param_2,undefined4 param_3)
{
  int param_4;
  code *pcVar1;
  code *pcVar2;
  int iVar3;
  
  if (param_2 != (char *)0x0) {
    if (*(int *)(param_1 + 0x140) != 0) {
      js_freeHandle();
    }
    iVar3 = xtra_findMethodByName(param_1,param_2);
    *(int *)(param_1 + 0x140) = iVar3;
    if ((iVar3 != 0) && (pcVar1 = *(code **)(param_1 + 0x148), pcVar1 != (code *)0x0)) {
      pcVar2 = *(code **)(*(int *)(param_1 + 0x14) + 0x230);
      if ((pcVar2 == (code *)0x0) ||
         (iVar3 = (*pcVar2)(param_1,iVar3,param_3,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x234))
         , iVar3 != 0)) {
        (*pcVar1)(param_1,*(undefined4 *)(param_1 + 0x140),param_3);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: xtra_getErrorString (xtra_getErrorString)
// Address: 6811ffb0
// Size: 34 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined * *
// Calling convention: __stdcall
// ============================================================

undefined ** xtra_getErrorString(undefined4 param_1,undefined4 param_2,int param_3)

{
  if (param_3 - 1U < 0xaa) {
    return &PTR_s__Error__0_is_reserved__68192160 + param_3 * 2;
  }
  return (undefined **)0x0;
}



// ============================================================
// Function: xtra_createContext (FUN_6811ffe0)
// Address: 6811ffe0
// Size: 336 bytes
// Params: int * param_1, undefined4 param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * xtra_createContext(int *param_1,undefined4 param_2)

{
  int *piVar1;
  int *piVar2;
  bool bVar3;
  int *_Dst;
  int iVar4;
  undefined3 extraout_var;
  
  _Dst = (int *)js_runGC();
  if (_Dst == (int *)0x0) {
    return (int *)0x0;
  }
  memset(_Dst,0,0x178);
  _Dst[5] = (int)param_1;
  piVar1 = param_1 + 0x78;
  piVar2 = (int *)*piVar1;
  while (*param_1 != 2) {
    if (*param_1 == 0) {
      *param_1 = 1;
      break;
    }
    piVar2 = (int *)*piVar1;
  }
  *_Dst = (int)piVar1;
  _Dst[1] = param_1[0x79];
  *(int **)param_1[0x79] = _Dst;
  param_1[0x79] = (int)_Dst;
  _Dst[3] = 0;
  *(undefined2 *)(_Dst + 4) = 0x1312;
  js_setPropertyDirect(_Dst + 6,"stack",param_2,4);
  js_setPropertyDirect(_Dst + 0xe,&DAT_6817e7ac,0x400,1);
  js_setPropertyDirect(_Dst + 0x15,&DAT_6817e7a4,0x400,1);
  js_setPropertyDirect(_Dst + 0x1c,&DAT_6817e79c,0x400,8);
  iVar4 = javascript_regexpFinalize((int)_Dst,(uint)(_Dst + 0x2d));
  if (iVar4 != 0) {
    *(undefined1 *)((int)_Dst + 0x15a) = 0;
    if (piVar2 == piVar1) {
      if (param_1[0x1e] == 0) {
        iVar4 = javascript_initAtomTableFull((int)_Dst,param_1 + 0x1b);
      }
      else {
        iVar4 = javascript_registerBuiltinAtoms((int)_Dst,param_1 + 0x1b);
      }
      if ((((iVar4 == 0) || (iVar4 = strings_registerKeywords((int)_Dst), iVar4 == 0)) ||
          (iVar4 = runtime_initNumberConstants((int)_Dst), iVar4 == 0)) ||
         (bVar3 = certificates_initStringPool((int)_Dst), CONCAT31(extraout_var,bVar3) == 0)) goto LAB_68120110;
      *param_1 = 2;
    }
    return _Dst;
  }
LAB_68120110:
  xtra_destroyContext(_Dst,0);
  return (int *)0x0;
}



