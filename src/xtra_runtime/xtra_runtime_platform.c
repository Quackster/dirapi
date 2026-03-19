// Module: xtra_runtime
// Topic: Platform services, decompression, property accessors, GC, value types, initialization
// Address range: 0x6811d7c0 - 0x6811e530
// Functions (55):
//   xtraRuntime_initDecompressor
//   xtraRuntime_decompressBlock
//   xtraRuntime_cleanupDecompressor
//   xtraRuntime_getCapabilitiesLo
//   xtraRuntime_getCapabilitiesHi
//   xtraRuntime_callFunction
//   xtra_lookupHash
//   xtra_lookupHashByte
//   xtraRuntime_getTypeName
//   xtraRuntime_destroyRuntime
//   xtraRuntime_destroyGlobals
//   xtraRuntime_delegateCall
//   xtraRuntime_setMode
//   xtra_getPlatformData
//   xtra_setPlatformValue
//   xtraRuntime_getPlatformRef
//   xtra_setPlatformRef
//   xtra_getPlatformFlags
//   xtraRuntime_setPlatformFlags
//   xtra_checkAndFlush (xtra_checkAndFlush)
//   xtraRuntime_storeFloat
//   xtraRuntime_addAtomRef
//   xtraRuntime_markAtomIndirect
//   xtraRuntime_markAtomDirect
//   xtraRuntime_lookupAtom
//   xtra_getPlatformSize
//   xtraRuntime_checkGcThreshold
//   xtra_flushAndCheck
//   xtra_getResourceData
//   xtra_getResourceDataEx
//   xtra_getPlatformVersion
//   xtraRuntime_defineProperty
//   xtraRuntime_getClassPointer
//   xtra_getObjectTag
//   xtra_getResourceById
//   xtraRuntime_getObjectPointer
//   xtra_loadResource
//   xtra_loadResourceBlock
//   xtraRuntime_loadResourceInline
//   events_createScope
//   xtraRuntime_resolveChainedProps
//   xtra_queryPlatform
//   events_registerProperty
//   xtraRuntime_registerAtomByName
//   xtraRuntime_getPropertyByIndex
//   xtraRuntime_hasProperty
//   xtraRuntime_getPropertyByName
//   xtraRuntime_getPropertyValue
//   xtra_parsePath
//   xtra_parsePathEx
//   xtraRuntime_deletePropertyByName
//   xtraRuntime_callMethodInline
//   xtraRuntime_setPropertyByIndex
//   xtra_resolvePathDir
//   xtra_resolvePath

// ============================================================
// Function: xtraRuntime_initDecompressor (FUN_6811d7c0)
// Address: 6811d7c0
// Size: 228 bytes
// Params: int param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_initDecompressor(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  
  iVar2 = (**(code **)(*param_2 + 0x28))(param_2,*(int *)(param_1 + 4) + 0x24);
  if (iVar2 != 0) {
    *(undefined4 *)(*(int *)(param_1 + 4) + 0x24) = 10000;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 0xc);
  uVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,0x1c00);
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x28) = uVar3;
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 0xc);
  uVar3 = (**(code **)(*piVar1 + 0xc))(piVar1,0x2400);
  *(undefined4 *)(*(int *)(param_1 + 4) + 0x2c) = uVar3;
  piVar1 = *(int **)(*(int *)(param_1 + 4) + 0xc);
  iVar4 = (**(code **)(*piVar1 + 0xc))(piVar1,0x38);
  *(int *)(*(int *)(param_1 + 4) + 0x30) = iVar4;
  iVar2 = *(int *)(param_1 + 4);
  if (((*(int *)(iVar2 + 0x28) == 0) || (*(int *)(iVar2 + 0x2c) == 0)) || (iVar4 == 0)) {
    iVar2 = -0x7ffbfffe;
  }
  else {
    iVar2 = Ordinal_981(*(undefined4 *)(iVar2 + 0x30),"1.2.3",0x38);
    if (iVar2 == 0) {
      *(undefined4 *)(iVar4 + 4) = 0;
      *(undefined4 *)(iVar4 + 8) = 0;
      uVar3 = *(undefined4 *)(*(int *)(param_1 + 4) + 0x2c);
      *(undefined4 *)(iVar4 + 0x14) = 0;
      *(undefined4 *)(iVar4 + 0xc) = uVar3;
      *(undefined4 *)(iVar4 + 0x10) = 0x2400;
      *(undefined1 *)(*(int *)(param_1 + 4) + 0x34) = 0;
      *(undefined4 *)(*(int *)(param_1 + 4) + 0x38) = 0x2400;
      return 0;
    }
  }
  xtra_getSerializedState(param_1);
  return iVar2;
}



// ============================================================
// Function: xtraRuntime_decompressBlock (FUN_6811d8b0)
// Address: 6811d8b0
// Size: 388 bytes
// Params: int param_1, int * param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_decompressBlock(int param_1,int *param_2,int *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  iVar4 = param_1;
  puVar2 = *(undefined4 **)(*(int *)(param_1 + 4) + 0x30);
  iVar5 = 0;
  if (puVar2 == (undefined4 *)0x0) {
    xtra_getSerializedState(param_1);
    return -0x7ffbfffe;
  }
  if (puVar2[4] == 0) {
    iVar5 = *(int *)(*(int *)(param_1 + 4) + 0x38);
    iVar5 = (**(code **)(*param_3 + 0x1c))(param_3,puVar2[3] - iVar5,iVar5,&param_1);
    if (iVar5 != 0) goto LAB_6811da25;
    piVar1 = (int *)(*(int *)(iVar4 + 4) + 0x38);
    *piVar1 = *piVar1 - param_1;
    if (*(int *)(*(int *)(iVar4 + 4) + 0x38) == 0) {
      puVar2[3] = *(undefined4 *)(*(int *)(iVar4 + 4) + 0x2c);
      puVar2[4] = 0x2400;
      *(undefined4 *)(*(int *)(iVar4 + 4) + 0x38) = 0x2400;
    }
  }
  if (*(char *)(*(int *)(iVar4 + 4) + 0x34) == '\0') {
    if (puVar2[1] != 0) {
LAB_6811d9c8:
      if ((puVar2[4] != 0) && (iVar5 = Ordinal_982(puVar2,0), iVar5 == 1)) {
        if (puVar2[4] == 0x2400) {
          return -0x7ffbfbb4;
        }
        *(undefined1 *)(*(int *)(iVar4 + 4) + 0x34) = 1;
        *(int *)(*(int *)(iVar4 + 4) + 0x38) = 0x2400 - puVar2[4];
        goto LAB_6811da00;
      }
      goto LAB_6811da03;
    }
    iVar5 = (**(code **)(*param_2 + 0x14))
                      (param_2,*(undefined4 *)(*(int *)(iVar4 + 4) + 0x28),0x1c00,&param_1);
    *puVar2 = *(undefined4 *)(*(int *)(iVar4 + 4) + 0x28);
    puVar2[1] = param_1;
    if ((iVar5 == -0x7ffbffac) || (iVar5 == -0x7ffbed20)) {
      iVar5 = 0;
      if (param_1 == 0) {
        *(undefined1 *)(*(int *)(iVar4 + 4) + 0x34) = 1;
      }
      if (puVar2[1] == 0) goto LAB_6811da03;
      goto LAB_6811d9c8;
    }
  }
  else {
    if ((puVar2[4] != 0) && (iVar5 = Ordinal_982(puVar2,4), iVar5 == 1)) {
      if (puVar2[4] == 0x2400) {
        return -0x7ffbfbb4;
      }
      *(int *)(*(int *)(iVar4 + 4) + 0x38) = 0x2400 - puVar2[4];
LAB_6811da00:
      iVar5 = 0;
      puVar2[4] = 0;
    }
LAB_6811da03:
    iVar3 = *(int *)(iVar4 + 4);
    if (*(int *)(iVar3 + 0x20) != 0) {
      (**(code **)(**(int **)(iVar3 + 0x20) + 0x18))
                (*(int **)(iVar3 + 0x20),*(int *)(iVar3 + 0x24) - puVar2[2],*(int *)(iVar3 + 0x24));
    }
  }
  if (iVar5 == 0) {
    return 0;
  }
LAB_6811da25:
  xtra_getSerializedState(iVar4);
  return iVar5;
}



// ============================================================
// Function: xtraRuntime_cleanupDecompressor (FUN_6811da40)
// Address: 6811da40
// Size: 18 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtraRuntime_cleanupDecompressor(int param_1)

{
  xtra_getSerializedState(param_1);
  return 0;
}



// ============================================================
// Function: xtraRuntime_getCapabilitiesLo (FUN_6811da60)
// Address: 6811da60
// Size: 22 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtraRuntime_getCapabilitiesLo(int param_1)

{
  return *(uint *)(*(int *)(param_1 + 0x14) + 0x1d0) | 2;
}



// ============================================================
// Function: xtraRuntime_getCapabilitiesHi (FUN_6811da80)
// Address: 6811da80
// Size: 22 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtraRuntime_getCapabilitiesHi(int param_1)

{
  return *(uint *)(*(int *)(param_1 + 0x14) + 0x1dc) | 4;
}



// ============================================================
// Function: xtraRuntime_callFunction (FUN_6811daa0)
// Address: 6811daa0
// Size: 22 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_callFunction(int param_1)
{
  runtime_callFunction(param_1,(uint *)&stack0x00000008,0);
  return 0;
}



// ============================================================
// Function: xtra_lookupHash (FUN_6811dac0)
// Address: 6811dac0
// Size: 9 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_lookupHash(int param_1,uint param_2)
{
  certs_hashLookup(param_1,param_2);
  return 0;
}



// ============================================================
// Function: xtra_lookupHashByte (FUN_6811dad0)
// Address: 6811dad0
// Size: 138 bytes
// Params: undefined4 param_1, uint param_2
// Return: byte
// Calling convention: __stdcall
// ============================================================

byte xtra_lookupHashByte(undefined4 param_1,uint param_2)

{
  int *piVar1;
  undefined **ppuVar2;
  uint uVar3;
  
  uVar3 = param_2 & 7;
  if (uVar3 == 0) {
    piVar1 = (int *)(param_2 & 0xfffffff8);
    if (piVar1 != (int *)0x0) {
      if (*(undefined ***)(*piVar1 + 4) == &PTR_FUN_68192948) {
        ppuVar2 = (undefined **)(*(uint *)(piVar1[1] + 8) & 0xfffffffe);
        if ((ppuVar2[0xc] != (undefined *)0x0) || (ppuVar2 == &PTR_s_Function_681928b8)) {
          return 2;
        }
      }
      else if ((*(undefined ***)(*piVar1 + 4))[0xe] != (undefined *)0x0) {
        return 2;
      }
    }
    return 1;
  }
  if ((((param_2 & 1) == 0) || (param_2 == 0x80000001)) && (uVar3 != 2)) {
    if (uVar3 != 4) {
      return (uVar3 != 6) - 1U & 5;
    }
    return 3;
  }
  return 4;
}



// ============================================================
// Function: xtraRuntime_getTypeName (FUN_6811db60)
// Address: 6811db60
// Size: 28 bytes
// Params: undefined4 param_1, uint param_2
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

undefined * xtraRuntime_getTypeName(undefined4 param_1,uint param_2)

{
  if (5 < param_2) {
    return (undefined *)0x0;
  }
  return (&PTR_s_undefined_68193af8)[param_2];
}



// ============================================================
// Function: xtraRuntime_destroyRuntime (FUN_6811db80)
// Address: 6811db80
// Size: 39 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_destroyRuntime(int param_1)
{
  javascript_gcFreeTable((undefined4 *)(param_1 + 0x6c));
  javascript_destroyGcArena(param_1);
  strings_destroyPropertyTable(param_1);
  js_freeHandle();
  return 0;
}



// ============================================================
// Function: xtraRuntime_destroyGlobals (FUN_6811dbb0)
// Address: 6811dbb0
// Size: 15 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_destroyGlobals(void)
{
  xtra_certNoOp();
  certificates_destroyStringTable();
  javascript_numberToStringRadix();
  return 0;
}



// ============================================================
// Function: xtraRuntime_delegateCall (FUN_6811dbc0)
// Address: 6811dbc0
// Size: 9 bytes
// Params: int * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_delegateCall(int *param_1,undefined4 param_2)
{
  xtra_createContext(param_1,param_2);
  return 0;
}



// ============================================================
// Function: xtraRuntime_setMode (FUN_6811dbd0)
// Address: 6811dbd0
// Size: 18 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_setMode(int *param_1)
{
  xtra_destroyContext(param_1,2);
  return 0;
}



// ============================================================
// Function: xtra_getPlatformData (FUN_6811dbf0)
// Address: 6811dbf0
// Size: 16 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getPlatformData(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14c);
}



// ============================================================
// Function: xtra_setPlatformValue (FUN_6811dc00)
// Address: 6811dc00
// Size: 19 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_setPlatformValue(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x14c) = param_2;
  return 0;
}



// ============================================================
// Function: xtraRuntime_getPlatformRef (FUN_6811dc20)
// Address: 6811dc20
// Size: 13 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtraRuntime_getPlatformRef(int param_1)

{
  return *(undefined4 *)(param_1 + 0xc);
}



// ============================================================
// Function: xtra_setPlatformRef (FUN_6811dc30)
// Address: 6811dc30
// Size: 44 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_setPlatformRef(int param_1,int param_2)
{
  if (param_2 != *(int *)(param_1 + 0xc)) {
    *(int *)(param_1 + 0xc) = param_2;
    if (param_2 == 0x78) {
      *(undefined2 *)(param_1 + 0x10) = 0x4948;
      return 0;
    }
    *(undefined2 *)(param_1 + 0x10) = 0x1312;
  }
  return 0;
}



// ============================================================
// Function: xtra_getPlatformFlags (FUN_6811dc60)
// Address: 6811dc60
// Size: 16 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getPlatformFlags(int param_1)

{
  return *(undefined4 *)(param_1 + 0x8c);
}



// ============================================================
// Function: xtraRuntime_setPlatformFlags (FUN_6811dc70)
// Address: 6811dc70
// Size: 19 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_setPlatformFlags(int param_1,undefined4 param_2)
{
  *(undefined4 *)(param_1 + 0x8c) = param_2;
  return 0;
}



// ============================================================
// Function: xtra_checkAndFlush (xtra_checkAndFlush)
// Address: 6811dc90
// Size: 20 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_checkAndFlush(undefined4 param_1,int param_2)
{
  if (param_2 != 0) {
    js_freeHandle();
  }
  return 0;
}



// ============================================================
// Function: xtraRuntime_storeFloat (FUN_6811dcb0)
// Address: 6811dcb0
// Size: 25 bytes
// Params: int param_1, undefined8 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_storeFloat(int param_1,undefined8 param_2)
{
  runtime_storeFloat(param_1,param_2);
  return 0;
}



// ============================================================
// Function: xtraRuntime_addAtomRef (FUN_6811dcd0)
// Address: 6811dcd0
// Size: 9 bytes
// Params: int param_1, uint param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_addAtomRef(int param_1,uint param_2,uint param_3)
{
  javascript_addAtomReference(param_1,param_2,param_3);
  return 0;
}



// ============================================================
// Function: xtraRuntime_markAtomIndirect (FUN_6811dce0)
// Address: 6811dce0
// Size: 23 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_markAtomIndirect(int param_1,undefined4 param_2)
{
  js_markAtom(*(int *)(param_1 + 0x14),param_2);
  return 0;
}



// ============================================================
// Function: xtraRuntime_markAtomDirect (FUN_6811dd00)
// Address: 6811dd00
// Size: 9 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_markAtomDirect(int param_1,undefined4 param_2)
{
  js_markAtom(param_1,param_2);
  return 0;
}



// ============================================================
// Function: xtraRuntime_lookupAtom (FUN_6811dd10)
// Address: 6811dd10
// Size: 22 bytes
// Params: undefined4 param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_lookupAtom(undefined4 param_1,uint param_2)
{
  js_lookupAtom(param_1,param_2,0);
  return 0;
}



// ============================================================
// Function: xtra_getPlatformSize (FUN_6811dd30)
// Address: 6811dd30
// Size: 61 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_getPlatformSize(int param_1)
{
  if (*(int *)(*(int *)(param_1 + 0x14) + 0x48) == 0) {
    if (*(int *)(param_1 + 0x28) == param_1 + 0x18) {
      js_getPrototypeChain(param_1 + 0x18);
    }
    js_getPrototypeChain(param_1 + 0x38);
    js_getPrototypeChain(param_1 + 0x70);
    javascript_gcProcessRoots(param_1,0);
  }
  return 0;
}



// ============================================================
// Function: xtraRuntime_checkGcThreshold (FUN_6811dd70)
// Address: 6811dd70
// Size: 55 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_checkGcThreshold(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  if (((0x2000 < *(uint *)(iVar1 + 0x4c)) &&
      ((*(uint *)(iVar1 + 0x50) >> 1) + *(uint *)(iVar1 + 0x50) < *(uint *)(iVar1 + 0x4c))) ||
     (*(uint *)(iVar1 + 0x54) < *(uint *)(iVar1 + 0x68))) {
    xtra_getPlatformSize(param_1);
  }
  return 0;
}



// ============================================================
// Function: xtra_flushAndCheck (FUN_6811ddb0)
// Address: 6811ddb0
// Size: 9 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_flushAndCheck(undefined4 param_1,int param_2)
{
  xtra_checkAndFlush(param_1,param_2);
  return 0;
}



// ============================================================
// Function: xtra_getResourceData (FUN_6811ddc0)
// Address: 6811ddc0
// Size: 49 bytes
// Params: int param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getResourceData(int param_1,uint param_2,uint *param_3)

{
  if (((param_2 & 1) == 0) || (param_2 == 0x80000001)) {
    param_2 = js_resolveAtom(param_1,param_2);
    if (param_2 == 0) {
      return 0;
    }
  }
  *param_3 = param_2;
  return 1;
}



// ============================================================
// Function: xtra_getResourceDataEx (FUN_6811de00)
// Address: 6811de00
// Size: 41 bytes
// Params: undefined4 param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getResourceDataEx(undefined4 param_1,uint param_2,uint *param_3)

{
  if ((param_2 & 1) != 0) {
    *param_3 = param_2;
    return 1;
  }
  *param_3 = *(uint *)(param_2 + 8);
  return 1;
}



// ============================================================
// Function: xtra_getPlatformVersion (FUN_6811de30)
// Address: 6811de30
// Size: 8 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getPlatformVersion(void)

{
  return 1;
}



// ============================================================
// Function: xtraRuntime_defineProperty (FUN_6811de50)
// Address: 6811de50
// Size: 9 bytes
// Params: uint param_1, int * param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_defineProperty(uint param_1,int *param_2,int param_3,int *param_4)
{
  runtime_definePropertyOnObject(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtraRuntime_getClassPointer (FUN_6811de60)
// Address: 6811de60
// Size: 19 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtraRuntime_getClassPointer(int param_1)

{
  return *(uint *)(*(int *)(param_1 + 4) + 8) & 0xfffffffe;
}



// ============================================================
// Function: xtra_getObjectTag (xtra_getObjectTag)
// Address: 6811de80
// Size: 36 bytes
// Params: undefined4 param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint xtra_getObjectTag(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = *(uint *)(*(int *)(param_2 + 4) + 0xc);
  if (((uVar1 & 1) != 0) && (uVar1 != 0x80000001)) {
    return uVar1 & 0xfffffffe;
  }
  return 0;
}



// ============================================================
// Function: xtra_getResourceById (FUN_6811deb0)
// Address: 6811deb0
// Size: 27 bytes
// Params: undefined4 param_1, int param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtra_getResourceById(undefined4 param_1,int param_2,uint param_3)

{
  *(uint *)(*(int *)(param_2 + 4) + 0xc) = param_3 | 1;
  return 1;
}



// ============================================================
// Function: xtraRuntime_getObjectPointer (FUN_6811ded0)
// Address: 6811ded0
// Size: 28 bytes
// Params: undefined4 param_1, int param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * xtraRuntime_getObjectPointer(undefined4 param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = (int *)(*(uint *)(*(int *)(param_2 + 4) + 4) & 0xfffffff8);
  if ((piVar1 == (int *)0x0) || (*piVar1 == 0)) {
    piVar1 = (int *)0x0;
  }
  return piVar1;
}



// ============================================================
// Function: xtra_loadResource (FUN_6811def0)
// Address: 6811def0
// Size: 37 bytes
// Params: int param_1, undefined * * param_2, undefined4 * param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_loadResource(int param_1,undefined **param_2,undefined4 *param_3,uint param_4)
{
  if (param_2 == (undefined **)0x0) {
    param_2 = &PTR_s_Object_681929a8;
  }
  runtime_setProperty(param_1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_loadResourceBlock (FUN_6811df20)
// Address: 6811df20
// Size: 166 bytes
// Params: undefined4 param_1, char * param_2, undefined4 param_3, uint param_4, uint param_5, int param_6, undefined4 param_7
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
xtra_loadResourceBlock(undefined4 param_1,char *param_2,undefined4 param_3,uint param_4,uint param_5,
            int param_6,undefined4 param_7)
{
  char cVar1;
  undefined **ppuVar2;
  uint in_EAX;
  uint uVar3;
  char *pcVar4;
  int *unaff_ESI;
  uint unaff_EDI;
  
  if ((char)in_EAX < '\0') {
    uVar3 = (int)param_2 * 2 | 1;
    in_EAX = in_EAX & 0xffffff7f;
  }
  else {
    pcVar4 = param_2;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    uVar3 = javascript_registerAtom(unaff_EDI,param_2,(int)pcVar4 - (int)(param_2 + 1),0);
    if (uVar3 == 0) {
      return 0;
    }
  }
  if ((param_6 != 0) &&
     ((ppuVar2 = *(undefined ***)(*unaff_ESI + 4), ppuVar2 == &PTR_FUN_68192948 ||
      ((ppuVar2 != (undefined **)0x0 && (*ppuVar2 == PTR_FUN_68192948)))))) {
    runtime_invokeMethod(unaff_EDI,unaff_ESI,uVar3,param_3,param_4,param_5,in_EAX,param_6,param_7,
                 (undefined4 *)0x0);
    return 0;
  }
  (**(code **)(*(int *)(*unaff_ESI + 4) + 0xc))();
  return 0;
}



// ============================================================
// Function: xtraRuntime_loadResourceInline (FUN_6811dfd0)
// Address: 6811dfd0
// Size: 136 bytes
// Params: short * param_1, undefined4 param_2, uint param_3, uint param_4, int param_5, undefined4 param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_loadResourceInline(short *param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,
                 undefined4 param_6)
{
  undefined **ppuVar1;
  uint in_EAX;
  uint uVar2;
  uint unaff_EBX;
  int *unaff_ESI;
  uint unaff_EDI;
  
  if (in_EAX == 0xffffffff) {
    in_EAX = certs_getStringLength(param_1);
  }
  uVar2 = javascript_registerAtomInline(unaff_EDI,param_1,in_EAX,0);
  if (uVar2 == 0) {
    return 0;
  }
  if ((param_5 != 0) &&
     ((ppuVar1 = *(undefined ***)(*unaff_ESI + 4), ppuVar1 == &PTR_FUN_68192948 ||
      ((ppuVar1 != (undefined **)0x0 && (*ppuVar1 == PTR_FUN_68192948)))))) {
    runtime_invokeMethod(unaff_EDI,unaff_ESI,uVar2,param_2,param_3,param_4,unaff_EBX,param_5,param_6,
                 (undefined4 *)0x0);
    return 0;
  }
  (**(code **)(*(int *)(*unaff_ESI + 4) + 0xc))();
  return 0;
}



// ============================================================
// Function: events_createScope (FUN_6811e060)
// Address: 6811e060
// Size: 90 bytes
// Params: int param_1, uint param_2, char * param_3, undefined * * param_4, undefined4 * param_5
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * events_createScope(int param_1,uint param_2,char *param_3,undefined **param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  undefined4 extraout_ECX;
  
  if (param_4 == (undefined **)0x0) {
    param_4 = &PTR_s_Object_681929a8;
  }
  piVar1 = runtime_setProperty(param_1,param_4,param_5,param_2);
  if (piVar1 != (int *)0x0) {
    iVar2 = xtra_loadResourceBlock(extraout_ECX,param_3,piVar1,0,0,0,0);
    if (iVar2 != 0) {
      return piVar1;
    }
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  return (int *)0x0;
}



// ============================================================
// Function: xtraRuntime_resolveChainedProps (FUN_6811e0c0)
// Address: 6811e0c0
// Size: 109 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, undefined4 param_4, uint param_5
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall
xtraRuntime_resolveChainedProps(undefined4 param_1,undefined4 param_2,int param_3,undefined4 param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  undefined4 extraout_ECX;
  int *piVar3;
  undefined8 uVar4;
  
  piVar3 = (int *)(param_5 + 8);
  iVar1 = 1;
  if (*piVar3 != 0) {
    while( true ) {
      iVar2 = runtime_convertToNumber(param_1,param_2,param_3,(int)*(undefined8 *)(piVar3 + -2),
                           (uint)((ulonglong)*(undefined8 *)(piVar3 + -2) >> 0x20),&param_5);
      iVar1 = 0;
      if (iVar2 == 0) break;
      uVar4 = xtra_loadResourceBlock(param_5,(char *)*piVar3,param_5,0,0,0,0);
      param_2 = (undefined4)((ulonglong)uVar4 >> 0x20);
      if ((int)uVar4 == 0) {
        return 0;
      }
      piVar3 = piVar3 + 4;
      param_1 = extraout_ECX;
      if (*piVar3 == 0) {
        return (int)uVar4;
      }
    }
  }
  return iVar1;
}



// ============================================================
// Function: xtra_queryPlatform (FUN_6811e130)
// Address: 6811e130
// Size: 86 bytes
// Params: undefined4 param_1, undefined4 param_2, int * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtra_queryPlatform(undefined4 param_1,undefined4 param_2,int *param_3)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 1;
  if (*param_3 != 0) {
    iVar3 = (int)param_3 + 5;
    do {
      iVar2 = xtra_loadResourceBlock(*(undefined4 *)(iVar3 + 7),*(char **)(iVar3 + -5),0x80000001,
                           *(uint *)(iVar3 + 3),*(undefined4 *)(iVar3 + 7),8,
                           (int)*(char *)(iVar3 + -1));
      if (iVar2 == 0) {
        return 0;
      }
      piVar1 = (int *)(iVar3 + 0xb);
      iVar3 = iVar3 + 0x10;
    } while (*piVar1 != 0);
  }
  return iVar2;
}



// ============================================================
// Function: events_registerProperty (FUN_6811e190)
// Address: 6811e190
// Size: 44 bytes
// Params: undefined4 param_1, undefined4 param_2, char * param_3, undefined4 param_4, undefined4 param_5, uint param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int events_registerProperty(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6)
{
  xtra_loadResourceBlock(param_5,param_3,param_4,param_5,param_6,0,0);
  return 0;
}



// ============================================================
// Function: xtraRuntime_registerAtomByName (FUN_6811e1c0)
// Address: 6811e1c0
// Size: 69 bytes
// Params: undefined4 param_1, char * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall xtraRuntime_registerAtomByName(undefined4 param_1,char *param_2)
{
  char cVar1;
  char *pcVar2;
  int iVar3;
  int *unaff_EBX;
  int unaff_EDI;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = javascript_registerAtom(unaff_EDI,param_2,(int)pcVar2 - (int)(param_2 + 1),0);
  if (iVar3 == 0) {
    return 0;
  }
  (**(code **)(*(int *)(*unaff_EBX + 4) + 8))();
  return 0;
}



// ============================================================
// Function: xtraRuntime_getPropertyByIndex (FUN_6811e210)
// Address: 6811e210
// Size: 87 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtraRuntime_getPropertyByIndex(undefined4 param_1)

{
  undefined **ppuVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  int unaff_EDI;
  
  if (unaff_EDI == 0) {
    return 0x80000001;
  }
  ppuVar1 = *(undefined ***)(*unaff_ESI + 4);
  if (((ppuVar1 == &PTR_FUN_68192948) ||
      ((ppuVar1 != (undefined **)0x0 && (*ppuVar1 == PTR_FUN_68192948)))) &&
     (*(uint *)(unaff_EDI + 0xc) < *(uint *)(*unaff_ESI + 0xc))) {
    uVar2 = *(undefined4 *)(unaff_ESI[1] + *(uint *)(unaff_EDI + 0xc) * 4);
  }
  else {
    uVar2 = 0xe;
  }
  if ((code *)ppuVar1[0xd] != (code *)0x0) {
    (*(code *)ppuVar1[0xd])(param_1);
  }
  return uVar2;
}



// ============================================================
// Function: xtraRuntime_hasProperty (FUN_6811e270)
// Address: 6811e270
// Size: 161 bytes
// Params: undefined4 param_1, undefined4 * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 xtraRuntime_hasProperty(undefined4 param_1,undefined4 *param_2)

{
  code *pcVar1;
  int in_EAX;
  int iVar2;
  undefined4 uVar3;
  int *unaff_ESI;
  undefined4 local_c;
  undefined4 local_8;
  
  if (in_EAX != 0) {
    iVar2 = (**(code **)(*(int *)(*unaff_ESI + 4) + 8))();
    if (iVar2 != 0) {
      if ((local_8 != 0) && (unaff_ESI == local_c)) {
        *param_2 = 1;
        uVar3 = (**(code **)(*(int *)(*unaff_ESI + 4) + 0x18))();
        pcVar1 = *(code **)(*(int *)(*unaff_ESI + 4) + 0x34);
        if (pcVar1 != (code *)0x0) {
          (*pcVar1)();
        }
        return uVar3;
      }
      *param_2 = 0;
      if ((local_8 != 0) &&
         (pcVar1 = *(code **)(*(int *)(*(unsigned int *)(size_t)local_c /* FIXUP(C2100): cast for dereference */ + 4) + 0x34), pcVar1 != (code *)0x0)) {
        (*pcVar1)();
      }
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: xtraRuntime_getPropertyByName (FUN_6811e320)
// Address: 6811e320
// Size: 60 bytes
// Params: int param_1, undefined4 param_2, char * param_3, undefined4 param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_getPropertyByName(int param_1,undefined4 param_2,char *param_3,undefined4 param_4,
                 undefined4 *param_5)
{
  char cVar1;
  char *pcVar2;

  pcVar2 = param_3;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  javascript_registerAtom(param_1,param_3,(int)pcVar2 - (int)(param_3 + 1),0);
  xtraRuntime_hasProperty(param_4,param_5);
  return 0;
}



// ============================================================
// Function: xtraRuntime_getPropertyValue (FUN_6811e360)
// Address: 6811e360
// Size: 60 bytes
// Params: undefined4 param_1, undefined4 param_2, char * param_3, undefined4 * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_getPropertyValue(undefined4 param_1,undefined4 param_2,char *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 uVar2;

  iVar1 = xtraRuntime_registerAtomByName(&param_2,param_3);
  if (iVar1 != 0) {
    uVar2 = xtraRuntime_getPropertyByIndex(param_1);
    *param_4 = uVar2;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_parsePath (FUN_6811e3a0)
// Address: 6811e3a0
// Size: 74 bytes
// Params: int param_1, int * param_2, char * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_parsePath(int param_1,int *param_2,char *param_3,undefined4 param_4)
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
  (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,iVar3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_parsePathEx (FUN_6811e3f0)
// Address: 6811e3f0
// Size: 74 bytes
// Params: int param_1, int * param_2, char * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_parsePathEx(int param_1,int *param_2,char *param_3,undefined4 param_4)
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
  (**(code **)(*(int *)(*param_2 + 4) + 0x14))(param_1,param_2,iVar3,param_4);
  return 0;
}



// ============================================================
// Function: xtraRuntime_deletePropertyByName (FUN_6811e440)
// Address: 6811e440
// Size: 74 bytes
// Params: int param_1, int * param_2, char * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_deletePropertyByName(int param_1,int *param_2,char *param_3,undefined4 param_4)
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
  (**(code **)(*(int *)(*param_2 + 4) + 0x20))(param_1,param_2,iVar3,param_4);
  return 0;
}



// ============================================================
// Function: xtraRuntime_callMethodInline (FUN_6811e490)
// Address: 6811e490
// Size: 50 bytes
// Params: undefined4 param_1, undefined4 param_2, short * param_3, undefined4 param_4, undefined4 param_5, uint param_6, uint param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_callMethodInline(undefined4 param_1,undefined4 param_2,short *param_3,undefined4 param_4,
                 undefined4 param_5,uint param_6,uint param_7)
{
  xtraRuntime_loadResourceInline(param_3,param_5,param_6,param_7,0,0);
  return 0;
}



// ============================================================
// Function: xtraRuntime_setPropertyByIndex (FUN_6811e4d0)
// Address: 6811e4d0
// Size: 38 bytes
// Params: undefined4 param_1, int * param_2, int param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtraRuntime_setPropertyByIndex(undefined4 param_1,int *param_2,int param_3,undefined4 param_4)
{
  (**(code **)(*(int *)(*param_2 + 4) + 0x10))(param_1,param_2,param_3 * 2 | 1,param_4);
  return 0;
}



// ============================================================
// Function: xtra_resolvePathDir (FUN_6811e500)
// Address: 6811e500
// Size: 38 bytes
// Params: undefined4 param_1, int * param_2, int param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int xtra_resolvePathDir(undefined4 param_1,int *param_2,int param_3,undefined4 param_4)
{
  (**(code **)(*(int *)(*param_2 + 4) + 0x14))(param_1,param_2,param_3 * 2 | 1,param_4);
  return 0;
}



// ============================================================
// Function: xtra_resolvePath (FUN_6811e530)
// Address: 6811e530
// Size: 232 bytes
// Params: uint param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * xtra_resolvePath(uint param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  int local_c;
  int local_8;
  
  piVar5 = param_2;
  uVar1 = param_1;
  piVar4 = (int *)0x0;
  local_8 = 0;
  iVar2 = (**(code **)(*(int *)(*param_2 + 4) + 0x28))(param_1,param_2,0,&local_8,&param_1);
  if (((iVar2 != 0) && ((param_1 & 1) != 0)) && (param_1 != 0x80000001)) {
    iVar2 = (int)param_1 >> 1;
    if (iVar2 < 1) {
      iVar2 = 8;
    }
    piVar4 = (int *)runtime_allocPropertySlots(uVar1,iVar2);
    if (piVar4 != (int *)0x0) {
      iVar2 = 0;
      while (((iVar3 = *piVar4, iVar2 != iVar3 ||
              (piVar4 = (int *)runtime_resizePropertySlots(uVar1,(int)piVar4,(iVar3 + 1U >> 1) + iVar3),
              piVar5 = param_2, piVar4 != (int *)0x0)) &&
             (iVar3 = (**(code **)(*(int *)(*param_2 + 4) + 0x28))
                                (uVar1,param_2,1,&local_8,&local_c), piVar5 = param_2, iVar3 != 0)))
      {
        if (local_8 == 0) {
          *piVar4 = iVar2;
          return piVar4;
        }
        piVar4[iVar2 + 1] = local_c;
        iVar2 = iVar2 + 1;
      }
    }
  }
  if (local_8 != 0) {
    (**(code **)(*(int *)(*piVar5 + 4) + 0x28))(uVar1,piVar5,2,&local_8,0);
  }
  if (piVar4 != (int *)0x0) {
    xtra_flushAndCheck(uVar1,(int)piVar4);
  }
  return (int *)0x0;
}



