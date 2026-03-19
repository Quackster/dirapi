// Module: props
// Topic: Runtime and thread initialization and destruction
// Address range: 0x68030230 - 0x680377f0
// Functions (17):
//   props_setTraceMode (FUN_68030230)
//   props_setSingleStep (FUN_680302a0)
//   props_isSingleStep (FUN_68030310)
//   props_evalExpression (FUN_68030340)
//   props_collectProperties (FUN_680303e0)
//   props_parseSymbolTable (FUN_680304e0)
//   props_parseConstant (FUN_68032440)
//   props_destroyContextArray (FUN_68037350)
//   props_destroyTable (FUN_680373b0)
//   props_createScriptTable (FUN_68037450)
//   props_createHandlerTable (FUN_68037470)
//   props_initSymbolDict (FUN_68037490)
//   props_createLocalTable (FUN_68037560)
//   props_initThread (FUN_68037570)
//   props_initRuntime (FUN_68037660)
//   props_destroyThread (FUN_68037720)
//   props_destroyRuntime (FUN_680377f0)



// ============================================================
// Function: props_setTraceMode (FUN_68030230)
// Address: 68030230
// Size: 106 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// Enables or disables the trace/debug mode for the VM
// ============================================================

int props_setTraceMode(int param_1,int param_2)
{
  int param_4;
  int iVar1;
  
  iVar1 = *(int *)(*(int *)(param_1 + 8) + 8);
  if (param_2 != 0) {
    *(undefined4 *)(iVar1 + 0xe8) = 4;
    *(code **)(iVar1 + 0x90) = cast_dispatchDebugEvent;
    *(undefined4 *)(iVar1 + 0x78) = 4;
    *(undefined4 *)(iVar1 + 0x74) = 4;
    stage_enableTrace(iVar1);
    strings_debugStep(iVar1,param_2);
    return 0;
  }
  *(undefined4 *)(iVar1 + 0xe8) = 0;
  *(undefined4 *)(iVar1 + 0x90) = 0;
  *(undefined4 *)(iVar1 + 0x78) = 0;
  *(undefined4 *)(iVar1 + 0x74) = 0;
  stage_disableTrace(iVar1);
  strings_debugStep(iVar1,0);
  return 0;
}



// ============================================================
// Function: props_setSingleStep (FUN_680302a0)
// Address: 680302a0
// Size: 107 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// Enables or disables single-step debugging
// ============================================================

int props_setSingleStep(int param_1,int param_2)
{
  bool bVar1;
  undefined3 extraout_var;
  
  *(int *)(param_1 + 0xec) = param_2;
  if (param_2 != 0) {
    *(undefined4 *)(param_1 + 0x78) = 4;
    *(undefined4 *)(param_1 + 0x74) = 4;
    *(code **)(param_1 + 0x90) = cast_dispatchDebugEvent;
    *(undefined4 *)(param_1 + 0x98) = *(undefined4 *)(param_1 + 0xf0);
    *(undefined4 *)(param_1 + 0xf0) = 0xffffffff;
    return 0;
  }
  bVar1 = cast_isContextValid(param_1);
  if (CONCAT31(extraout_var,bVar1) == 0) {
    *(undefined4 *)(param_1 + 0x90) = 0;
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x74) = 0;
    *(undefined4 *)(param_1 + 0xf0) = *(undefined4 *)(param_1 + 0x98);
  }
  return 0;
}



// ============================================================
// Function: props_isSingleStep (FUN_68030310)
// Address: 68030310
// Size: 42 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// Checks if single-step debugging is currently active
// ============================================================

undefined4 props_isSingleStep(int param_1)

{
  if ((*(int *)(param_1 + 0xec) != 0) && (*(code **)(param_1 + 0x90) == cast_dispatchDebugEvent)) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: props_evalExpression (FUN_68030340)
// Address: 68030340
// Size: 151 bytes
// Params: int * param_1, undefined4 param_2, int * param_3
// Return: undefined
// Calling convention: __stdcall
// Evaluates an expression string in a context, returns result
// ============================================================

int props_evalExpression(int *param_1,undefined4 param_2,int *param_3)
{
  int iVar1;
  int iVar2;
  
  iVar1 = param_1[0x3b];
  if (iVar1 != 0) {
    props_setSingleStep((int)param_1,0);
  }
  *param_3 = 0;
  iVar2 = score_resolveExpression(param_1,0x840,param_2);
  if ((iVar2 == 0) || (param_1[0x1d] != 2)) {
    param_1[0x1f] = 0;
  }
  else {
    props_pushValue((int)param_1);
    param_1[7] = 4;
    param_1[8] = -0x80000000;
    props_dispatchOpcode(param_1,(int *)0x2,0,0);
    if (param_1[0x1d] != 8) {
      iVar2 = props_serializeValue((int)param_1,param_1 + 7,0);
      *param_3 = iVar2;
      props_popValue((int)param_1);
    }
  }
  if (iVar1 != 0) {
    props_setSingleStep((int)param_1,1);
  }
  return 0;
}



// ============================================================
// Function: props_collectProperties (FUN_680303e0)
// Address: 680303e0
// Size: 254 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// Iterates through a property list, collecting member values
// ============================================================

undefined4 props_collectProperties(int param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  int *local_18;
  uint local_14;
  int *local_10;
  undefined8 local_c;
  
  local_c = cast_handleGetProperty(param_1,param_2);
  piVar1 = (int *)cast_getProplistValue(param_1,(int *)&local_c);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  local_24 = 8;
  local_20 = 0x10b;
  uVar2 = cast_resetProplist(param_1);
  iVar3 = cast_getMemberData(param_1,piVar1);
  iVar6 = 1;
  if (0 < iVar3) {
    do {
      cast_getContextData(param_1,piVar1,iVar6,&local_14,(uint *)&local_c);
      props_resolveValue(param_1,&local_14);
      if (local_14 == 8) {
        piVar4 = (int *)cast_getProplistValue(param_1,(int *)&local_c);
        if (piVar4 != (int *)0x0) {
          iVar5 = cast_updateProplist(param_1,piVar4,&local_24,&local_1c);
          if (iVar5 != 0) {
            cast_setPropertyFromProplist(param_1,uVar2,&local_14,&local_1c,1);
            props_releaseValue(param_1,(byte)local_1c,local_18);
          }
        }
      }
      props_releaseValue(param_1,(byte)local_14,local_10);
      props_releaseValue(param_1,(byte)local_c,(*(unsigned int *)((char *)&local_c + 4)));
      iVar6 = iVar6 + 1;
    } while (iVar6 <= iVar3);
  }
  cast_releaseObject(param_1,piVar1);
  return uVar2;
}



// ============================================================
// Function: props_parseSymbolTable (FUN_680304e0)
// Address: 680304e0
// Size: 715 bytes
// Params: void * param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// Parses a symbol table (handler table) from a locked handle
// ============================================================

int props_parseSymbolTable(void *param_1,int *param_2,undefined4 *param_3)
{
  undefined4 uVar1;
  int iVar2;
  int *piVar3;
  uint local_880;
  int *local_87c;
  undefined4 *local_878;
  uint local_874;
  int *local_870;
  uint local_86c;
  int *local_868;
  int local_864 [23];
  undefined1 local_808 [1024];
  undefined2 local_408 [512];
  uint local_8;
  
  local_878 = param_3;
  uVar1 = Ordinal_1114(param_3);
  iVar2 = Ordinal_1116(param_3);
  props_hashSymbol(local_864,uVar1,iVar2);
  props_searchSymbolTable(param_1,local_864);
  if ((local_86c == 8) && (local_868 == (int *)0x6)) {
    props_searchSymbolTable(param_1,local_864);
    while (local_86c != 0) {
      if (local_86c == 8) {
        if ((local_868 == (int *)0x7) || (local_868 == (int *)0xa)) break;
        if (((local_868 != (int *)0x3) || (props_searchSymbolTable(param_1,local_864), local_86c == 8)) &&
           (local_868 == (int *)0x24)) {
          props_searchSymbolTable(param_1,local_864);
        }
      }
      props_resolveValue((int)param_1,&local_86c);
      piVar3 = local_868;
      if (((local_86c != 8) || (props_searchSymbolTable(param_1,local_864), local_86c != 8)) ||
         (local_868 != (int *)0xa)) {
        props_releaseValue(param_1,(byte)local_86c,local_868);
LAB_680306a2:
        piVar3 = (int *)cast_invokeNamedHandler(param_1,param_3);
        if (piVar3 == (int *)0x0) {
          props_cStringToPascal(param_3,local_808);
          local_408[0] = 0;
          props_formatError((int)param_1,0,2000,0x6e,(int)local_808,-1,(int)local_408,0,0);
          return 0;
        }
        local_868 = (int *)cast_getMemberData(param_1,piVar3);
        iVar2 = 1;
        if (0 < (int)local_868) {
          do {
            cast_getContextData(param_1,piVar3,iVar2,&local_874,&local_880);
            props_resolveValue((int)param_1,&local_874);
            if (local_874 == 8) {
              cast_setPropertyValue(param_1,param_2,(uint)local_870,&local_880);
            }
            props_releaseValue(param_1,(byte)local_874,local_870);
            props_releaseValue(param_1,(byte)local_880,local_87c);
            iVar2 = iVar2 + 1;
          } while (iVar2 <= (int)local_868);
        }
        cast_releaseObject(param_1,piVar3);
        param_3 = local_878;
        break;
      }
      props_searchSymbolTable(param_1,local_864);
      if ((local_86c == 8) && ((int)local_868 < 0x2f)) goto LAB_680306a2;
      cast_setPropertyValue(param_1,param_2,(uint)piVar3,&local_86c);
      props_releaseValue(param_1,(byte)local_86c,local_868);
      props_searchSymbolTable(param_1,local_864);
    }
  }
  Ordinal_1115(param_3);
  return 0;
}



// ============================================================
// Function: props_parseConstant (FUN_68032440)
// Address: 68032440
// Size: 104 bytes
// Params: int param_1, byte * param_2, byte * param_3
// Return: undefined
// Calling convention: __stdcall
// Parses a constant value from bytecode data into a value slot
// ============================================================

int props_parseConstant(int param_1,byte *param_2,byte *param_3)
{
  bool bVar1;
  ushort uVar2;
  undefined3 extraout_var;
  double local_c;
  
  if (*param_2 == 0xff) {
    uVar2 = Ordinal_1201(param_2 + 1);
  }
  else {
    uVar2 = (ushort)*param_2;
  }
  if (0 < (short)uVar2) {
    bVar1 = cast_parseDouble(param_2,&local_c);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      if ((*param_3 & 1) != 0) {
        props_releaseValue(param_1,(byte)*(undefined4 *)param_3,*(int **)(param_3 + 4));
        param_3[0] = 2;
        param_3[1] = 0;
        param_3[2] = 0;
        param_3[3] = 0;
      }
      props_storeNumber(param_1,local_c,(undefined4 *)param_3);
    }
  }
  return 0;
}



// ============================================================
// Function: props_destroyContextArray
// Address: 68037350
// Size: 78 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_destroyContextArray(int *param_1)
{
  int *piVar1;
  int unaff_EBX;
  int iVar2;
  undefined4 local_8;
  
  local_8 = *(int *)(*param_1 + 0x10);
  if (0 < local_8) {
    iVar2 = 0;
    do {
      piVar1 = *(int **)(iVar2 + 0xa8 + *param_1);
      if (piVar1 != (int *)0x0) {
        props_destroyContext(unaff_EBX,piVar1,0);
        cast_freeHandle(piVar1);
        *(int *)(unaff_EBX + 0xf8) = *(int *)(unaff_EBX + 0xf8) + -1;
      }
      iVar2 = iVar2 + 0x10;
      local_8 = local_8 + -1;
    } while (local_8 != 0);
  }
  return 0;
}



// ============================================================
// Function: props_destroyTable
// Address: 680373b0
// Size: 158 bytes
// Params: uint param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_destroyTable(uint param_1,int *param_2)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  
  piVar4 = param_2;
  iVar1 = *(int *)(*param_2 + 0x10);
  iVar5 = 0;
  if (0 < iVar1) {
    do {
      props_invalidateTableEntry(param_1,param_2,iVar5,0);
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  iVar5 = 0;
  if (0 < iVar1) {
    param_2 = (int *)0x0;
    do {
      piVar2 = *(int **)((int)param_2 + *piVar4 + 0x30);
      piVar3 = *(int **)((int)param_2 + *piVar4 + 0x2c);
      if (piVar3 != (int *)0x0) {
        props_destroyContextArray(piVar3);
        stage_freeAllAllocSlots(param_1,piVar2);
        props_freeTableEntry(param_1,piVar4,iVar5);
      }
      param_2 = param_2 + 6;
      iVar5 = iVar5 + 1;
    } while (iVar5 < iVar1);
  }
  cast_freeHandle(piVar4);
  return 0;
}



// ============================================================
// Function: props_createScriptTable
// Address: 68037450
// Size: 27 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_createScriptTable(void)
{
  int *piVar1;
  
  piVar1 = stage_allocDispatchEntry(0x3c,0x24,0x18,10);
  if (piVar1 != (int *)0x0) {
    *(undefined4 *)(*piVar1 + 0x20) = 0xffffffff;
  }
  return 0;
}



// ============================================================
// Function: props_createHandlerTable
// Address: 68037470
// Size: 17 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_createHandlerTable(void)
{
  stage_allocDispatchEntry(0x30,0x20,0x10,0xa5);
  return 0;
}



// ============================================================
// Function: props_initSymbolDict
// Address: 68037490
// Size: 189 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_initSymbolDict(void)
{
  undefined **ppuVar1;
  int *piVar2;
  undefined *puVar3;
  int iVar4;
  int *unaff_EBX;
  undefined **ppuVar5;
  int unaff_EDI;
  uint local_40c;
  byte local_408 [1024];
  uint local_8;
  
  DAT_68196304 = (int *)score_createSymbolTable(0x3ff,0x5ff);
  ppuVar5 = &PTR_DAT_6818da98;
  puVar3 = PTR_DAT_6818da98;
  while (puVar3 != (undefined *)0x0) {
    Ordinal_1233(local_408,puVar3);
    score_resolveSymbolName(unaff_EDI,DAT_68196304,local_408,&local_40c,0);
    ppuVar1 = ppuVar5 + 1;
    ppuVar5 = ppuVar5 + 1;
    puVar3 = *ppuVar1;
  }
  iVar4 = *unaff_EBX;
  while (iVar4 != 0) {
    Ordinal_1233(local_408,iVar4);
    score_resolveSymbolName(unaff_EDI,DAT_68196304,local_408,&local_40c,0);
    piVar2 = unaff_EBX + 1;
    unaff_EBX = unaff_EBX + 1;
    iVar4 = *piVar2;
  }
  return 0;
}



// ============================================================
// Function: props_createLocalTable
// Address: 68037560
// Size: 14 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_createLocalTable(void)
{
  stage_allocDispatchEntry(0x2c,0x20,0xc,0x20);
  return 0;
}



// ============================================================
// Function: props_initThread
// Address: 68037570
// Size: 227 bytes
// Params: undefined4 * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_initThread(undefined4 *param_1,undefined4 param_2)
{
  int *piVar1;
  undefined4 uVar2;
  
  uVar2 = *(undefined4 *)(*(int *)param_1[2] + 0x570);
  piVar1 = (int *)(*(int *)param_1[2] + 0x570);
  param_1[1] = piVar1;
  *param_1 = uVar2;
  *(undefined4 **)(*piVar1 + 4) = param_1;
  *piVar1 = (int)param_1;
  param_1[5] = param_2;
  uVar2 = cast_allocHandle(param_2,1);
  param_1[4] = uVar2;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[0x35] = 0x2e;
  param_1[0x36] = 0x5c;
  Ordinal_1130(param_1 + 0x10,0x34);
  props_selectScript((int)param_1,0);
  param_1[0x10] = 0xffffffff;
  param_1[0x19] = 0;
  param_1[0x24] = 0;
  param_1[0x2a] = 0;
  param_1[0x2b] = 2;
  param_1[0x2e] = 0xffffffff;
  param_1[0x30] = 0;
  param_1[0x31] = 0;
  uVar2 = props_createLocalTable();
  param_1[0x33] = 0;
  param_1[0x24] = 0;
  param_1[0x39] = 0;
  param_1[0x3a] = 0;
  param_1[0x3b] = 0;
  param_1[0x4e] = 0;
  param_1[0x32] = uVar2;
  param_1[0x34] = 0xffffffff;
  param_1[0x2f] = 0x20;
  return 0;
}



// ============================================================
// Function: props_initRuntime
// Address: 68037660
// Size: 188 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_initRuntime(int param_1)
{
  undefined4 uVar1;
  int *piVar2;
  
  if (DAT_68196304 == 0) {
    props_initSymbolDict();
  }
  uVar1 = score_getSymbolName(0xff,0x13f);
  *(undefined4 *)(param_1 + 0x4ec) = uVar1;
  uVar1 = props_createHandlerTable();
  *(undefined4 *)(param_1 + 0x4f0) = uVar1;
  piVar2 = (int *)props_createScriptTable();
  *(int **)(param_1 + 0x4f4) = piVar2;
  props_allocScriptEntry(0,piVar2);
  uVar1 = cast_allocHandle(0x400,3);
  *(undefined4 *)(param_1 + 0x4dc) = uVar1;
  uVar1 = Ordinal_1114(uVar1);
  *(undefined4 *)(param_1 + 0x4e0) = uVar1;
  *(undefined4 *)(param_1 + 0x4f8) = 0;
  *(undefined4 *)(param_1 + 0x4fc) = 4;
  *(undefined4 *)(param_1 + 0x500) = 0x2c;
  uVar1 = score_createPropertyTable();
  *(undefined4 *)(param_1 + 0x4e4) = uVar1;
  uVar1 = score_createPropertyTable();
  *(undefined4 *)(param_1 + 0x4e8) = uVar1;
  stage_initDispatchTable(param_1);
  score_registerBuiltins(param_1);
  core_registerAllHandlers(param_1);
  strings_registerCommands(param_1);
  return 0;
}



// ============================================================
// Function: props_destroyThread
// Address: 68037720
// Size: 195 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_destroyThread(int *param_1)
{
  int iVar1;
  int *piVar2;
  
  props_unwindStack((int)param_1);
  if (param_1[0x4e] == 0) {
    iVar1 = param_1[0x10];
    while (iVar1 != -1) {
      props_popFrame((uint)param_1);
      iVar1 = param_1[0x10];
    }
  }
  iVar1 = param_1[0x2b];
  param_1[0x2b] = 0;
  props_releaseValue(param_1,(byte)iVar1,(int *)param_1[0x2c]);
  iVar1 = param_1[0x20];
  param_1[0x20] = 0;
  props_releaseValue(param_1,(byte)iVar1,(int *)param_1[0x21]);
  piVar2 = (int *)param_1[0x43];
  param_1[0x43] = 0;
  props_releaseObject(param_1,piVar2);
  iVar1 = param_1[0x44];
  param_1[0x44] = 0;
  props_releaseValue(param_1,(byte)iVar1,(int *)param_1[0x45]);
  cast_freeHandle(param_1[0x32]);
  cast_freeHandle(param_1[0x33]);
  cast_freeHandle(param_1[4]);
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  return 0;
}



// ============================================================
// Function: props_destroyRuntime
// Address: 680377f0
// Size: 60 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_destroyRuntime(int param_1)
{
  Ordinal_1115(*(undefined4 *)(param_1 + 0x4dc));
  cast_freeHandle(*(undefined4 *)(param_1 + 0x4dc));
  cast_freeHandle(*(undefined4 *)(param_1 + 0x4f0));
  score_freePropertyHandle(*(undefined4 *)(param_1 + 0x4ec));
  return 0;
}


