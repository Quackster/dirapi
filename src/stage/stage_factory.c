// Module: stage
// Topic: Factory runtime data operations
// Address range: 0x6805A1C0 - 0x6805A690
// Functions (14):
//   stage_dispatchPropertyRead (FUN_6805A1C0)
//   stage_readRawValue (FUN_6805A2A0)
//   stage_readIndexedProperty (FUN_6805A2E0)
//   stage_readFloatValue (FUN_6805A330)
//   stage_appendAllocVar (FUN_6805A380)
//   stage_allocFactorySlot (FUN_6805A3F0)
//   stage_createFactory (FUN_6805A420)
//   stage_initFactoryContext (FUN_6805A460)
//   stage_initFactoryShared (FUN_6805A510)
//   stage_initFactoryCopied (FUN_6805A530)
//   stage_destroyFactoryContext (FUN_6805A550)
//   stage_storeSymbolValue (FUN_6805A5D0)
//   stage_storeNumberValue (FUN_6805A650)
//   stage_storeStringValue (FUN_6805A690)

// ============================================================
// Function: stage_dispatchPropertyRead (FUN_6805A1C0)
// Address: 6805a1c0
// Size: 157 bytes
// Params: int * param_1, uint * param_2
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall stage_dispatchPropertyRead(int *param_1,uint *param_2)

{
  undefined **in_EAX;
  uint extraout_EAX;
  uint uVar1;
  int unaff_ESI;
  
  if ((int)in_EAX < 0x40) {
    switch ((int)(size_t)in_EAX) { /* FIXUP(C2050): cast non-integral switch to int */
    case (undefined **)0x1:
      uVar1 = crt_codecNoOp();
      return uVar1;
    case (undefined **)0x9:
    case (undefined **)0xa:
    case (undefined **)0xb:
      uVar1 = props_parseRectOp(param_1,in_EAX,unaff_ESI,param_2);
      return uVar1;
    case (undefined **)0xc:
      uVar1 = score_deserializeProplist(param_1,in_EAX,unaff_ESI,param_2);
      return uVar1;
    case (undefined **)0xd:
      uVar1 = stage_deserializeScriptData(param_1,in_EAX,unaff_ESI,param_2);
      return uVar1;
    case (undefined **)0xe:
      uVar1 = score_resolveXtraString((int)param_1,in_EAX,unaff_ESI,param_2);
      return uVar1;
    case (undefined **)0xf:
      score_readColorValue(param_1,in_EAX,unaff_ESI,param_2);
      return extraout_EAX;
    case (undefined **)0x10:
      uVar1 = score_allocDateValue(param_1,in_EAX,unaff_ESI,param_2);
      return uVar1;
    case (undefined **)0x11:
      uVar1 = sprites_getEventContext();
      return uVar1;
    case (undefined **)0x12:
      uVar1 = sprites_getEventContext();
      return uVar1;
    }
  }
  else {
    in_EAX = in_EAX + -0x10;
    if (*(int *)(*(int *)param_1[3] + 0x10) <= (int)in_EAX) {
      return 1;
    }
  }
  stage_allocStringLoop(param_1,0,in_EAX,unaff_ESI,param_2);
  return 0;
}



// ============================================================
// Function: stage_readRawValue (FUN_6805A2A0)
// Address: 6805a2a0
// Size: 55 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall stage_readRawValue(int param_1)

{
  short sVar1;
  int in_EAX;
  undefined4 uVar2;
  undefined4 *unaff_ESI;
  
  *unaff_ESI = 4;
  if (in_EAX == 2) {
    sVar1 = Ordinal_1412(*(undefined4 *)(param_1 + 4));
    unaff_ESI[1] = (int)sVar1;
    return 0;
  }
  if (in_EAX == 4) {
    uVar2 = Ordinal_1414(*(undefined4 *)(param_1 + 4));
    unaff_ESI[1] = uVar2;
    return 0;
  }
  return 1;
}



// ============================================================
// Function: stage_readIndexedProperty (FUN_6805A2E0)
// Address: 6805a2e0
// Size: 69 bytes
// Params: uint * param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_readIndexedProperty(uint *param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 *unaff_EDI;
  
  iVar2 = stage_readRawValue((int)unaff_EDI);
  if (iVar2 == 0) {
    iVar2 = *(int *)unaff_EDI[6];
    uVar1 = param_1[1];
    if (((int)uVar1 < *(int *)(iVar2 + 0x10)) && (-1 < (int)uVar1)) {
      *param_1 = *(uint *)(iVar2 + 0x20 + uVar1 * 8);
      param_1[1] = *(uint *)(iVar2 + 0x24 + uVar1 * 8);
      props_retainValue(*unaff_EDI,param_1);
      return 0;
    }
    iVar2 = 1;
  }
  return iVar2;
}



// ============================================================
// Function: stage_readFloatValue (FUN_6805A330)
// Address: 6805a330
// Size: 74 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_readFloatValue(int param_1)

{
  float fVar1;
  undefined4 uVar2;
  int *unaff_ESI;
  int *unaff_EDI;
  
  if (param_1 != 4) {
    return 1;
  }
  fVar1 = (float)Ordinal_1414(unaff_EDI[1]);
  props_storeNumber(*unaff_EDI,(double)fVar1,unaff_ESI);
  if ((*unaff_ESI == 0x20) || (uVar2 = 1, *unaff_ESI == 0x23)) {
    uVar2 = 0;
  }
  return uVar2;
}



// ============================================================
// Function: stage_appendAllocVar (FUN_6805A380)
// Address: 6805a380
// Size: 100 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_appendAllocVar(void)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *unaff_EBX;
  uint local_c;
  int *local_8;
  
  uVar3 = stage_allocString(unaff_EBX,&local_c);
  if (uVar3 == 0) {
    iVar1 = *(int *)(*(int *)unaff_EBX[3] + 0x10);
    stage_emitStoreVar((int *)unaff_EBX[3],iVar1);
    iVar2 = DAT_68195a8c;
    if (DAT_68195a8c != 0) {
      props_releaseValue(*unaff_EBX,(byte)local_c,local_8);
      return iVar2;
    }
    iVar2 = *(int *)unaff_EBX[3];
    *(uint *)(iVar2 + 0x20 + iVar1 * 8) = local_c;
    *(int **)(iVar2 + 0x24 + iVar1 * 8) = local_8;
    uVar3 = 0;
  }
  return uVar3;
}



// ============================================================
// Function: stage_allocFactorySlot (FUN_6805A3F0)
// Address: 6805a3f0
// Size: 41 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_allocFactorySlot(int param_1,int *param_2)
{
  int iVar1;
  
  iVar1 = *(int *)(**(int **)(param_1 + 0x18) + 0x10);
  stage_emitStoreVar(*(int **)(param_1 + 0x18),iVar1);
  if (DAT_68195a8c == 0) {
    *param_2 = iVar1;
  }
  return 0;
}



// ============================================================
// Function: stage_createFactory (FUN_6805a420)
// Address: 6805a420
// Size: 61 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_createFactory(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  if ((-1 < param_2) || (iVar2 = stage_allocFactorySlot(param_1,&param_2), iVar2 == 0)) {
    iVar1 = **(int **)(param_1 + 0x18);
    *(undefined4 *)(iVar1 + 0x20 + param_2 * 8) = *param_3;
    *(undefined4 *)(iVar1 + 0x24 + param_2 * 8) = param_3[1];
  }
  return iVar2;
}



// ============================================================
// Function: stage_initFactoryContext (FUN_6805A460)
// Address: 6805a460
// Size: 170 bytes
// Params: int param_1, int * param_2, int param_3, int param_4
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall stage_initFactoryContext(int param_1,int *param_2,int param_3,int param_4)

{
  int in_EAX;
  int *piVar1;
  int iVar2;
  int unaff_EDI;
  
  *param_2 = unaff_EDI;
  param_2[1] = param_1;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0x40;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  if (param_4 == 0) {
    piVar1 = (int *)score_deleteProplistEntry(unaff_EDI,in_EAX);
    param_2[2] = (int)piVar1;
    if (DAT_68195a8c != 0) {
      return DAT_68195a8c;
    }
    score_insertProplistEntry(unaff_EDI,piVar1,1);
    piVar1 = (int *)score_deleteProplistEntry(unaff_EDI,param_3);
    param_2[5] = (int)piVar1;
    iVar2 = DAT_68195a8c;
    if (DAT_68195a8c == 0) {
      score_insertProplistEntry(unaff_EDI,piVar1,1);
    }
  }
  else {
    piVar1 = stage_allocDispatchEntry(0x28,0x20,8,in_EAX);
    param_2[3] = (int)piVar1;
    iVar2 = DAT_68195a8c;
    if (DAT_68195a8c == 0) {
      piVar1 = stage_allocDispatchEntry(0x28,0x20,8,param_3);
      param_2[6] = (int)piVar1;
      return DAT_68195a8c;
    }
  }
  return iVar2;
}



// ============================================================
// Function: stage_initFactoryShared (FUN_6805A510)
// Address: 6805a510
// Size: 32 bytes
// Params: undefined4 param_1, int * param_2, int param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_initFactoryShared(undefined4 param_1,int *param_2,int param_3,undefined4 param_4,int param_5)
{
  stage_initFactoryContext(param_3,param_2,param_5,0);
  return 0;
}



// ============================================================
// Function: stage_initFactoryCopied (FUN_6805A530)
// Address: 6805a530
// Size: 32 bytes
// Params: undefined4 param_1, int * param_2, int param_3, undefined4 param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_initFactoryCopied(undefined4 param_1,int *param_2,int param_3,undefined4 param_4,int param_5)
{
  stage_initFactoryContext(param_3,param_2,param_5,1);
  return 0;
}



// ============================================================
// Function: stage_destroyFactoryContext (FUN_6805A550)
// Address: 6805a550
// Size: 118 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_destroyFactoryContext(undefined4 *param_1)
{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  uVar1 = *param_1;
  props_releaseObject(uVar1,(int *)param_1[2]);
  if ((int *)param_1[3] != (int *)0x0) {
    iVar2 = *(int *)param_1[3];
    iVar4 = 0;
    if (0 < *(int *)(iVar2 + 0x10)) {
      iVar3 = 0x20;
      do {
        props_releaseValue(uVar1,(byte)*(undefined4 *)(iVar3 + iVar2),*(int **)(iVar3 + 4 + iVar2));
        iVar2 = *(int *)param_1[3];
        iVar4 = iVar4 + 1;
        iVar3 = iVar3 + 8;
      } while (iVar4 < *(int *)(iVar2 + 0x10));
    }
    cast_freeHandle(param_1[3]);
  }
  props_releaseObject(uVar1,(int *)param_1[5]);
  cast_freeHandle(param_1[6]);
  return 0;
}



// ============================================================
// Function: stage_storeSymbolValue (FUN_6805A5D0)
// Address: 6805a5d0
// Size: 124 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int stage_storeSymbolValue(void)
{
  undefined4 uVar1;
  uint unaff_EBX;
  undefined4 *unaff_ESI;
  undefined4 *unaff_EDI;
  undefined1 local_108 [256];
  uint local_8;
  
  if ((unaff_EBX < 0x101) && (-1 < (int)unaff_EBX)) {
    stage_compareScriptRef((int)unaff_ESI,local_108,unaff_EBX);
    uVar1 = props_lookupSymbol(*unaff_ESI,local_108,unaff_EBX);
    unaff_EDI[1] = uVar1;
    *unaff_EDI = 8;
    stage_createFactory((int)unaff_ESI,-1,unaff_EDI);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: stage_storeNumberValue (FUN_6805A650)
// Address: 6805a650
// Size: 57 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 stage_storeNumberValue(void)

{
  int *unaff_ESI;
  int *unaff_EDI;
  float10 fVar1;
  
  fVar1 = (float10)Ordinal_1447(unaff_EDI[1]);
  props_storeNumber(*unaff_EDI,(double)fVar1,unaff_ESI);
  if ((*unaff_ESI != 0x20) && (*unaff_ESI != 0x23)) {
    return 1;
  }
  stage_createFactory((int)unaff_EDI,-1,unaff_ESI);
  return 0;
}



// ============================================================
// Function: stage_storeStringValue (FUN_6805A690)
// Address: 6805a690
// Size: 124 bytes
// Params: int * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int stage_storeStringValue(int *param_1)

{
  bool bVar1;
  int in_EAX;
  int iVar2;
  int *piVar3;
  undefined3 extraout_var;
  int *unaff_ESI;
  
  if (-1 < in_EAX) {
    iVar2 = stage_resolveString(*param_1,in_EAX,unaff_ESI);
    if (iVar2 != 0) {
      piVar3 = props_getStringData(unaff_ESI,(int *)0x0);
      bVar1 = stage_compareScriptRef((int)param_1,piVar3,in_EAX);
      *(undefined1 *)((int)piVar3 + in_EAX) = 0;
      props_unlockString(unaff_ESI);
      if (CONCAT31(extraout_var,bVar1) != 0) {
        props_clearValue(*param_1,unaff_ESI);
        return CONCAT31(extraout_var,bVar1);
      }
      stage_createFactory((int)param_1,-1,unaff_ESI);
      return 0;
    }
  }
  return 1;
}



