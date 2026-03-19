// Module: javascript
// Topic: Garbage collector, atom table, string interning, reference counting
// Address range: 0x68138140 - 0x681397b0
// Functions (54):

//   javascript_computeValueHash
//   javascript_compareValues
//   javascript_gcAllocWrapper
//   javascript_gcCreateNode
//   javascript_gcClearTable
//   javascript_gcVisitEntry
//   javascript_gcFreeTable
//   javascript_gcTraverseEntry
//   javascript_gcTraverseTable
//   javascript_gcSweepEntry
//   javascript_gcResetMarks
//   javascript_gcClearEntryMark
//   javascript_gcClearAllMarks
//   js_gcSweep
//   javascript_gcSweepObject
//   javascript_gcSweepBoolean
//   javascript_gcSweepInteger
//   javascript_gcSweepFloat
//   js_findOrCreateAtom
//   javascript_registerAtom
//   javascript_registerAtomInline
//   javascript_gcSweepValue
//   js_resolveAtom
//   js_initAtomTable
//   javascript_arenaAlloc
//   javascript_arenaAllocAligned
//   js_createAtom
//   js_allocAtom
//   javascript_atomTableCopyEntry
//   javascript_atomTableSerialize
//   javascript_atomTableFree
//   javascript_registerBuiltinAtoms
//   javascript_initAtomTableFull
//   javascript_delegateToHost
//   js_runGC
//   js_allocAtomBlock
//   javascript_callocWrapper
//   js_freeHandle
//   js_isGCActive
//   javascript_initPoolBlock
//   js_getAtomSize
//   javascript_initGcArena
//   javascript_destroyGcArena
//   javascript_addAtomReference
//   js_markAtom
//   javascript_acquireAtomRef
//   js_freeAtom
//   js_lookupAtom
//   javascript_gcMarkScopeEntry
//   javascript_gcMarkLinkedEntry
//   js_internAtom
//   js_getAtomString
//   javascript_gcMarkAtomValue
//   js_allocAtomSlot

// ============================================================
// Function: javascript_computeValueHash (FUN_68138140)
// Address: 68138140
// Size: 88 bytes
// Params: uint param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint javascript_computeValueHash(uint param_1)

{
  uint uVar1;
  
  uVar1 = param_1 & 7;
  if (uVar1 == 4) {
    uVar1 = certificates_computeStringHash((uint *)(param_1 & 0xfffffff8));
    return uVar1;
  }
  if (((param_1 & 1) != 0) && (param_1 != 0x80000001)) {
    return (int)param_1 >> 1;
  }
  if (uVar1 == 2) {
    return ((uint *)(param_1 & 0xfffffff8))[1] ^ *(uint *)(param_1 & 0xfffffff8);
  }
  if (uVar1 == 0) {
    return param_1 >> 3;
  }
  if (uVar1 == 6) {
    param_1 = (int)param_1 >> 3;
  }
  return param_1;
}



// ============================================================
// Function: javascript_compareValues (FUN_681381a0)
// Address: 681381a0
// Size: 259 bytes
// Params: uint param_1, uint param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool javascript_compareValues(uint param_1,uint param_2)

{
  double dVar1;
  double dVar2;
  int iVar3;
  int local_14;
  uint uStack_10;
  int local_c;
  uint uStack_8;
  
  if (((param_1 & 7) == 4) && (((byte)param_2 & 7) == 4)) {
    iVar3 = certs_compareStrings((uint *)(param_1 & 0xfffffff8),(uint *)(param_2 & 0xfffffff8));
    return (bool)('\x01' - (iVar3 != 0));
  }
  if (((param_1 & 7) == 2) && (((byte)param_2 & 7) == 2)) {
    dVar1 = *(double *)(param_1 & 0xfffffff8);
    dVar2 = *(double *)(param_2 & 0xfffffff8);
    uStack_10 = (uint)((ulonglong)dVar1 >> 0x20);
    local_c = SUB84(dVar2,0);
    uStack_8 = (uint)((ulonglong)dVar2 >> 0x20);
    if (((uStack_10 & 0x7ff00000) == 0x7ff00000) &&
       ((local_14 = SUB84(dVar1,0), local_14 != 0 || (((ulonglong)dVar1 & 0xfffff00000000) != 0))))
    {
      if (((uStack_8 & 0x7ff00000) == 0x7ff00000) &&
         ((local_c != 0 || (((ulonglong)dVar2 & 0xfffff00000000) != 0)))) {
        return true;
      }
    }
    else if ((((uStack_8 & 0x7ff00000) != 0x7ff00000) ||
             ((local_c == 0 && (((ulonglong)dVar2 & 0xfffff00000000) == 0)))) && (dVar2 == dVar1)) {
      return true;
    }
    return false;
  }
  return param_1 == param_2;
}



// ============================================================
// Function: javascript_gcAllocWrapper (FUN_681382c0)
// Address: 681382c0
// Size: 16 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcAllocWrapper(void)
{
  js_runGC();
  return 0;
}



// ============================================================
// Function: javascript_gcCreateNode (FUN_681382d0)
// Address: 681382d0
// Size: 50 bytes
// Params: int param_1, undefined4 param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_gcCreateNode(int param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = js_runGC();
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 8) = param_2;
  *(undefined4 *)(iVar1 + 0x14) = *(undefined4 *)(param_1 + 8);
  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
  return iVar1;
}



// ============================================================
// Function: javascript_gcClearTable (FUN_68138310)
// Address: 68138310
// Size: 41 bytes
// Params: undefined4 param_1, void * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcClearTable(undefined4 param_1,void *param_2)
{
  if (*(int **)((int)param_2 + 4) != (int *)0x0) {
    crypto_getHashTableSize(*(int **)((int)param_2 + 4));
  }
  memset(param_2,0,0x138);
  return 0;
}



// ============================================================
// Function: javascript_gcVisitEntry (FUN_68138340)
// Address: 68138340
// Size: 56 bytes
// Params: int param_1, undefined4 param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_gcVisitEntry(int param_1,undefined4 param_2,undefined4 *param_3)

{
  uint uVar1;
  
  uVar1 = *(uint *)(param_1 + 8) & 7;
  if (uVar1 == 4) {
    certificates_freeStringNode(*param_3,(uint *)(*(uint *)(param_1 + 8) & 0xfffffff8));
    return 0;
  }
  if (uVar1 == 0) {
    param_3[1] = param_3[1] + 1;
  }
  return 0;
}



// ============================================================
// Function: javascript_gcFreeTable (FUN_68138380)
// Address: 68138380
// Size: 59 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcFreeTable(undefined4 *param_1)
{
  undefined4 local_c;
  undefined4 local_8;
  
  if ((int *)param_1[1] != (int *)0x0) {
    local_c = *param_1;
    local_8 = 0;
    crypto_decompileToString((int *)param_1[1],javascript_gcVisitEntry,&local_c);
    javascript_gcClearTable(0,param_1);
  }
  return 0;
}



// ============================================================
// Function: javascript_gcTraverseEntry (FUN_681383c0)
// Address: 681383c0
// Size: 63 bytes
// Params: int param_1, undefined4 param_2, byte * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_gcTraverseEntry(int param_1,undefined4 param_2,byte *param_3)

{
  uint uVar1;
  
  if (((*(uint *)(param_1 + 0x10) & 3) != 0) || ((*param_3 & 1) != 0)) {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | 4;
    uVar1 = *(uint *)(param_1 + 8);
    if (((uVar1 & 1) == 0) && (((byte)uVar1 & 7) != 6)) {
      (**(code **)(param_3 + 4))(uVar1 & 0xfffffff8,*(undefined4 *)(param_3 + 8));
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_gcTraverseTable (FUN_68138400)
// Address: 68138400
// Size: 55 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcTraverseTable(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    local_c = param_3;
    local_10 = param_2;
    local_8 = param_4;
    crypto_decompileToString(*(int **)(param_1 + 4),javascript_gcTraverseEntry,&local_10);
  }
  return 0;
}



// ============================================================
// Function: javascript_gcSweepEntry (FUN_68138440)
// Address: 68138440
// Size: 48 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_gcSweepEntry(int param_1,undefined4 param_2,int param_3)

{
  if ((*(uint *)(param_1 + 0x10) & 4) != 0) {
    *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffb;
    *(int *)(param_3 + 0xc) = *(int *)(param_3 + 0xc) + 1;
    return 0;
  }
  *(undefined4 *)(param_1 + 8) = 0;
  *(undefined4 *)(param_1 + 0x10) = 0;
  return 2;
}



// ============================================================
// Function: javascript_gcResetMarks (FUN_68138470)
// Address: 68138470
// Size: 36 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcResetMarks(int param_1)
{
  *(undefined4 *)(param_1 + 0xc) = 0;
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    crypto_decompileToString(*(int **)(param_1 + 4),javascript_gcSweepEntry,param_1);
  }
  return 0;
}



// ============================================================
// Function: javascript_gcClearEntryMark (FUN_681384a0)
// Address: 681384a0
// Size: 16 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_gcClearEntryMark(int param_1)

{
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) & 0xfffffffe;
  return 0;
}



// ============================================================
// Function: javascript_gcClearAllMarks (FUN_681384b0)
// Address: 681384b0
// Size: 30 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcClearAllMarks(int param_1)
{
  if (*(int **)(param_1 + 4) != (int *)0x0) {
    crypto_decompileToString(*(int **)(param_1 + 4),javascript_gcClearEntryMark,0);
  }
  return 0;
}



// ============================================================
// Function: js_gcSweep (FUN_681384d0)
// Address: 681384d0
// Size: 79 bytes
// Params: int param_1, uint param_2
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * js_gcSweep(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  undefined4 *puVar3;
  undefined4 unaff_EBX;
  int unaff_EDI;
  
  piVar1 = *(int **)(*(int *)(param_1 + 0x14) + 0x70);
  piVar2 = crypto_findHashEntry(piVar1,unaff_EDI,unaff_EBX);
  puVar3 = (undefined4 *)*piVar2;
  if (puVar3 == (undefined4 *)0x0) {
    puVar3 = crypto_decompileBlock(piVar1,piVar2,unaff_EDI,unaff_EBX,0);
    if (puVar3 == (undefined4 *)0x0) {
      xtra_reportError(param_1);
      return (undefined4 *)0x0;
    }
  }
  puVar3[4] = puVar3[4] | param_2;
  *(undefined4 **)(param_1 + 0xb0) = puVar3;
  return puVar3;
}



// ============================================================
// Function: javascript_gcSweepObject (FUN_68138520)
// Address: 68138520
// Size: 32 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcSweepObject(int param_1,undefined4 param_2,uint param_3)
{
  js_gcSweep(param_1,param_3);
  return 0;
}



// ============================================================
// Function: javascript_gcSweepBoolean (FUN_68138540)
// Address: 68138540
// Size: 37 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcSweepBoolean(int param_1,undefined4 param_2,uint param_3)
{
  js_gcSweep(param_1,param_3);
  return 0;
}



// ============================================================
// Function: javascript_gcSweepInteger (FUN_68138570)
// Address: 68138570
// Size: 33 bytes
// Params: int param_1, undefined4 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcSweepInteger(int param_1,undefined4 param_2,uint param_3)
{
  js_gcSweep(param_1,param_3);
  return 0;
}



// ============================================================
// Function: javascript_gcSweepFloat (FUN_681385a0)
// Address: 681385a0
// Size: 174 bytes
// Params: int param_1, undefined8 param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcSweepFloat(int param_1,undefined8 param_2,uint param_3)
{
  int *piVar1;
  undefined8 uVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint local_1c [3];
  undefined8 local_10;
  uint local_8;
  
  local_10 = param_2;
  uVar2 = local_10;
  (*(unsigned int *)((char *)&local_10 + 4)) = (uint)((ulonglong)param_2 >> 0x20);
  (*(unsigned int *)((char *)&local_10 + 0)) = (uint)param_2;
  uVar6 = (*(unsigned int *)((char *)&local_10 + 4)) ^ (uint)local_10;
  local_1c[0] = (uint)&local_10 | 2;
  piVar1 = *(int **)(*(int *)(param_1 + 0x14) + 0x70);
  local_10 = uVar2;
  piVar3 = crypto_findHashEntry(piVar1,uVar6,local_1c[0]);
  puVar5 = (undefined4 *)*piVar3;
  if (puVar5 == (undefined4 *)0x0) {
    iVar4 = runtime_formatNumber(param_1,param_2,local_1c);
    if (iVar4 != 0) {
      puVar5 = crypto_decompileBlock(piVar1,piVar3,uVar6,local_1c[0],0);
      if (puVar5 != (undefined4 *)0x0) goto LAB_6813862f;
      xtra_reportError(param_1);
    }
    return 0;
  }
LAB_6813862f:
  puVar5[4] = puVar5[4] | param_3;
  *(undefined4 **)(param_1 + 0xb0) = puVar5;
  return 0;
}



// ============================================================
// Function: js_findOrCreateAtom (FUN_68138650)
// Address: 68138650
// Size: 181 bytes
// Params: int param_1, uint * param_2, uint param_3
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * js_findOrCreateAtom(int param_1,uint *param_2,uint param_3)

{
  int local_14;
  int *piVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  
  uVar2 = certificates_computeStringHash(param_2);
  piVar1 = *(int **)(*(int *)(param_1 + 0x14) + 0x70);
  uVar7 = (uint)param_2 | 4;
  piVar3 = crypto_findHashEntry(piVar1,uVar2,uVar7);
  puVar6 = (undefined4 *)*piVar3;
  if (puVar6 == (undefined4 *)0x0) {
    if ((char)param_3 < '\0') {
      if ((param_3 & 0x40) == 0) {
        puVar4 = certs_allocFromPool(param_1,(void *)param_2[1],*param_2,0);
      }
      else {
        puVar4 = certs_allocHashEntry(param_1,param_2[1],*param_2,0);
      }
      if (puVar4 == (uint *)0x0) {
        return (undefined4 *)0x0;
      }
      uVar7 = (uint)puVar4 | 4;
    }
    else {
      iVar5 = xtra_normalizeString(param_1,param_2);
      if (iVar5 == 0) {
        return (undefined4 *)0x0;
      }
    }
    puVar6 = crypto_decompileBlock(piVar1,piVar3,uVar2,uVar7,0);
    if (puVar6 == (undefined4 *)0x0) {
      xtra_reportError(param_1);
      return (undefined4 *)0x0;
    }
  }
  puVar6[4] = puVar6[4] | param_3 & 3;
  *(undefined4 **)(param_1 + 0xb0) = puVar6;
  return puVar6;
}



// ============================================================
// Function: javascript_registerAtom (FUN_68138710)
// Address: 68138710
// Size: 201 bytes
// Params: int param_1, char * param_2, int param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_registerAtom(int param_1,char *param_2,int param_3,uint param_4)
{
  short *psVar1;
  undefined4 *puVar2;
  uint local_5c;
  short local_58 [36];
  uint local_10;
  short *psStack_c;
  uint local_8;
  
  local_5c = certificates_convertMultibyte((short *)0x0,param_2,param_3);
  if (local_5c < 0x20) {
    local_5c = certificates_convertMultibyte(local_58,param_2,param_3);
    if (-1 < (int)local_5c) {
      psVar1 = local_58;
LAB_68138787:
      local_10 = local_5c;
      psStack_c = psVar1;
      puVar2 = js_findOrCreateAtom(param_1,&local_10,param_4 | 0x80);
      if ((psVar1 != local_58) &&
         ((puVar2 == (undefined4 *)0x0 || (*(short **)((puVar2[2] & 0xfffffff8) + 4) != psVar1)))) {
        xtra_checkAndFlush(param_1,(int)psVar1);
      }
      return 0;
    }
  }
  else {
    psVar1 = certs_createSubstring(param_1,param_2,param_3,&local_5c);
    if (psVar1 != (short *)0x0) {
      param_4 = param_4 | 0x40;
      goto LAB_68138787;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_registerAtomInline (FUN_681387e0)
// Address: 681387e0
// Size: 74 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_registerAtomInline(int param_1,undefined4 param_2,uint param_3,uint param_4)
{
  uint local_10;
  undefined4 uStack_c;
  uint local_8;
  
  uStack_c = param_2;
  local_10 = param_3;
  js_findOrCreateAtom(param_1,&local_10,param_4 | 0x80);
  return 0;
}



// ============================================================
// Function: javascript_gcSweepValue (FUN_68138830)
// Address: 68138830
// Size: 182 bytes
// Params: int param_1, uint param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcSweepValue(int param_1,uint param_2,uint param_3)
{
  uint uVar1;
  
  uVar1 = param_2 & 7;
  if (uVar1 == 4) {
    js_findOrCreateAtom(param_1,(uint *)(param_2 & 0xfffffff8),param_3);
    return 0;
  }
  if (((param_2 & 1) != 0) && (param_2 != 0x80000001)) {
    javascript_gcSweepInteger(param_1,(int)param_2 >> 1,param_3);
    return 0;
  }
  if (uVar1 == 2) {
    javascript_gcSweepFloat(param_1,*(undefined8 *)(param_2 & 0xfffffff8),param_3);
    return 0;
  }
  if (uVar1 == 0) {
    javascript_gcSweepObject(param_1,param_2 & 0xfffffff8,param_3);
    return 0;
  }
  if (uVar1 == 6) {
    javascript_gcSweepBoolean(param_1,(int)param_2 >> 3,param_3);
    return 0;
  }
  js_gcSweep(param_1,param_3);
  return 0;
}



// ============================================================
// Function: js_resolveAtom (FUN_681388f0)
// Address: 681388f0
// Size: 40 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_resolveAtom(int param_1,uint param_2)
{
  uint *puVar1;
  
  puVar1 = (uint *)certs_hashLookup(param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    return 0;
  }
  js_findOrCreateAtom(param_1,puVar1,0);
  return 0;
}



// ============================================================
// Function: js_initAtomTable (FUN_68138920)
// Address: 68138920
// Size: 13 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_initAtomTable(int param_1)

{
  return *(undefined4 *)(param_1 + 0x14);
}



// ============================================================
// Function: javascript_arenaAlloc (FUN_68138930)
// Address: 68138930
// Size: 75 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_arenaAlloc(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x80);
  iVar3 = *(int *)(iVar2 + 0xc);
  uVar4 = param_2 + *(uint *)(param_1 + 0x88) & ~*(uint *)(param_1 + 0x88);
  uVar1 = iVar3 + uVar4;
  if (*(uint *)(iVar2 + 8) < uVar1) {
    iVar3 = js_getSlotIndex(param_1 + 0x70,uVar4);
  }
  else {
    *(uint *)(iVar2 + 0xc) = uVar1;
  }
  if (iVar3 == 0) {
    xtra_reportError(param_1);
  }
  return iVar3;
}



// ============================================================
// Function: javascript_arenaAllocAligned (FUN_68138980)
// Address: 68138980
// Size: 71 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_arenaAllocAligned(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  
  iVar2 = *(int *)(param_1 + 0x80);
  uVar4 = *(uint *)(param_1 + 0x88) + 0x10 & ~*(uint *)(param_1 + 0x88);
  iVar3 = *(int *)(iVar2 + 0xc);
  uVar1 = iVar3 + uVar4;
  if (*(uint *)(iVar2 + 8) < uVar1) {
    iVar3 = js_getSlotIndex(param_1 + 0x70,uVar4);
  }
  else {
    *(uint *)(iVar2 + 0xc) = uVar1;
  }
  if (iVar3 == 0) {
    xtra_reportError(param_1);
    iVar3 = 0;
  }
  return iVar3;
}



// ============================================================
// Function: js_createAtom (FUN_681389d0)
// Address: 681389d0
// Size: 300 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * js_createAtom(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  if ((int *)param_3[1] == (int *)0x0) {
    piVar3 = (int *)0x0;
    puVar2 = (undefined4 *)*param_3;
    puVar4 = param_3;
    while (puVar5 = puVar2, puVar5 != (undefined4 *)0x0) {
      if (puVar5[2] == param_2) {
        *puVar4 = *puVar5;
        *puVar5 = *param_3;
        *param_3 = puVar5;
        goto LAB_68138a23;
      }
      puVar4 = puVar5;
      puVar2 = (undefined4 *)*puVar5;
    }
  }
  else {
    piVar3 = crypto_findHashEntry((int *)param_3[1],*(int *)(param_2 + 0x14),param_2);
    puVar5 = (undefined4 *)*piVar3;
    if (puVar5 != (undefined4 *)0x0) {
LAB_68138a23:
      if (puVar5 != (undefined4 *)0x0) {
        return puVar5;
      }
    }
  }
  if ((uint)param_3[2] < 6) {
    puVar4 = (undefined4 *)javascript_arenaAllocAligned(param_1);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[2] = param_2;
      *puVar4 = *param_3;
      *param_3 = puVar4;
      puVar4[3] = param_3[2];
      param_3[2] = param_3[2] + 1;
      return puVar4;
    }
  }
  else {
    if (param_3[1] == 0) {
      puVar4 = crypto_insertHashEntry(8,js_initAtomTable,crypto_isDecompileReady,crypto_isDecompileReady,&PTR_FUN_68193b28,param_1);
      param_3[1] = puVar4;
      if (puVar4 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      puVar4 = (undefined4 *)*param_3;
      while (puVar4 != (undefined4 *)0x0) {
        iVar1 = *(int *)(puVar4[2] + 0x14);
        puVar2 = (undefined4 *)*puVar4;
        puVar4[1] = iVar1;
        puVar5 = crypto_findHashEntry((int *)param_3[1],iVar1,puVar4[2]);
        *puVar4 = *puVar5;
        *puVar5 = puVar4;
        puVar4 = puVar2;
      }
      *param_3 = 0;
      piVar3 = crypto_findHashEntry((int *)param_3[1],*(int *)(param_2 + 0x14),param_2);
    }
    puVar4 = crypto_decompileBlock((int *)param_3[1],piVar3,*(int *)(param_2 + 0x14),param_2,0);
    if (puVar4 != (undefined4 *)0x0) {
      puVar4[3] = param_3[2];
      param_3[2] = param_3[2] + 1;
      return puVar4;
    }
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: js_allocAtom (FUN_68138b00)
// Address: 68138b00
// Size: 118 bytes
// Params: undefined4 param_1, int * param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_allocAtom(uint param_1,int *param_2,uint param_3)
{
  undefined1 local_14 [12];
  uint local_8;
  
  if ((*param_2 != 0) && (param_3 < (uint)param_2[1])) {
    return 0;
  }
  runtime_snprintf(local_14,0xc,"%lu");
  xtra_invokeMethod(param_1,xtra_getErrorString,0,0xd);
  return 0;
}



// ============================================================
// Function: javascript_atomTableCopyEntry (FUN_68138b80)
// Address: 68138b80
// Size: 24 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_atomTableCopyEntry(int param_1,undefined4 param_2,int param_3)

{
  *(undefined4 *)(param_3 + *(int *)(param_1 + 0xc) * 4) = *(undefined4 *)(param_1 + 8);
  return 0;
}



// ============================================================
// Function: javascript_atomTableSerialize (FUN_68138ba0)
// Address: 68138ba0
// Size: 183 bytes
// Params: uint param_1, int * param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_atomTableSerialize(uint param_1,int *param_2,int *param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = (int *)*param_3;
  if ((piVar3 == (int *)0x0) && (param_3[1] == 0)) {
    *param_2 = 0;
    param_2[1] = 0;
    return 1;
  }
  uVar1 = param_3[2];
  if (0xffff < uVar1) {
    xtra_invokeMethod(param_1,xtra_getErrorString,0,0xe);
    return 0;
  }
  iVar2 = xtra_getPropertyById(param_1,uVar1 * 4);
  if (iVar2 == 0) {
    return 0;
  }
  if ((int *)param_3[1] == (int *)0x0) {
    do {
      if ((uint)piVar3[3] < uVar1) {
        *(int *)(iVar2 + piVar3[3] * 4) = piVar3[2];
      }
      piVar3 = (int *)*piVar3;
    } while (piVar3 != (int *)0x0);
  }
  else {
    crypto_decompileToString((int *)param_3[1],javascript_atomTableCopyEntry,iVar2);
  }
  *param_3 = 0;
  param_3[1] = 0;
  param_3[2] = 0;
  *param_2 = iVar2;
  param_2[1] = uVar1;
  return 1;
}



// ============================================================
// Function: javascript_atomTableFree (FUN_68138c60)
// Address: 68138c60
// Size: 41 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_atomTableFree(undefined4 param_1,int *param_2)
{
  if (*param_2 != 0) {
    xtra_checkAndFlush(param_1,*param_2);
    *param_2 = 0;
  }
  param_2[1] = 0;
  return 0;
}



// ============================================================
// Function: javascript_registerBuiltinAtoms (FUN_68138ca0)
// Address: 68138ca0
// Size: 1268 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_registerBuiltinAtoms(int param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  int *piVar3;
  char *pcVar4;
  int iVar5;
  uint local_8;
  
  piVar3 = param_2;
  param_2 = param_2 + 4;
  local_8 = 0;
  while( true ) {
    pcVar2 = *(char **)((int)&PTR_s_undefined_68193af8 + local_8);
    pcVar4 = pcVar2;
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    iVar5 = javascript_registerAtom(param_1,pcVar2,(int)pcVar4 - (int)(pcVar2 + 1),1);
    *param_2 = iVar5;
    if (iVar5 == 0) break;
    param_2 = param_2 + 1;
    local_8 = local_8 + 4;
    if (0x17 < local_8) {
      pcVar2 = "false";
      do {
        pcVar4 = pcVar2;
        pcVar2 = pcVar4 + 1;
      } while (*pcVar4 != '\0');
      iVar5 = javascript_registerAtom(param_1,"false",(int)(pcVar4 + -0x68193c94),1);
      piVar3[10] = iVar5;
      if (iVar5 != 0) {
        pcVar2 = &DAT_68193c9c;
        do {
          pcVar4 = pcVar2;
          pcVar2 = pcVar4 + 1;
        } while (*pcVar4 != '\0');
        iVar5 = javascript_registerAtom(param_1,&DAT_68193c9c,(int)(pcVar4 + -0x68193c9c),1);
        piVar3[0xb] = iVar5;
        if (iVar5 != 0) {
          pcVar2 = &DAT_68193c84;
          do {
            pcVar4 = pcVar2;
            pcVar2 = pcVar4 + 1;
          } while (*pcVar4 != '\0');
          iVar5 = javascript_registerAtom(param_1,&DAT_68193c84,(int)(pcVar4 + -0x68193c84),1);
          piVar3[0xc] = iVar5;
          if (iVar5 != 0) {
            iVar5 = javascript_registerAtom(param_1,"Arguments",9,1);
            piVar3[0xd] = iVar5;
            if (iVar5 != 0) {
              iVar5 = javascript_registerAtom(param_1,"Array",5,1);
              piVar3[0xe] = iVar5;
              if (iVar5 != 0) {
                iVar5 = javascript_registerAtom(param_1,"Boolean",7,1);
                piVar3[0xf] = iVar5;
                if (iVar5 != 0) {
                  iVar5 = javascript_registerAtom(param_1,"Call",4,1);
                  piVar3[0x10] = iVar5;
                  if (iVar5 != 0) {
                    iVar5 = javascript_registerAtom(param_1,"Date",4,1);
                    piVar3[0x11] = iVar5;
                    if (iVar5 != 0) {
                      pcVar2 = "Error";
                      do {
                        pcVar4 = pcVar2;
                        pcVar2 = pcVar4 + 1;
                      } while (*pcVar4 != '\0');
                      iVar5 = javascript_registerAtom(param_1,"Error",(int)(pcVar4 + -0x6817e984),1);
                      piVar3[0x12] = iVar5;
                      if (iVar5 != 0) {
                        iVar5 = javascript_registerAtom(param_1,"Function",8,1);
                        piVar3[0x13] = iVar5;
                        if (iVar5 != 0) {
                          iVar5 = javascript_registerAtom(param_1,"Math",4,1);
                          piVar3[0x14] = iVar5;
                          if (iVar5 != 0) {
                            iVar5 = javascript_registerAtom(param_1,"Number",6,1);
                            piVar3[0x15] = iVar5;
                            if (iVar5 != 0) {
                              iVar5 = javascript_registerAtom(param_1,"Object",6,1);
                              piVar3[0x16] = iVar5;
                              if (iVar5 != 0) {
                                iVar5 = javascript_registerAtom(param_1,"RegExp",6,1);
                                piVar3[0x17] = iVar5;
                                if (iVar5 != 0) {
                                  iVar5 = javascript_registerAtom(param_1,"Script",6,1);
                                  piVar3[0x18] = iVar5;
                                  if (iVar5 != 0) {
                                    iVar5 = javascript_registerAtom(param_1,"String",6,1);
                                    piVar3[0x19] = iVar5;
                                    if (iVar5 != 0) {
                                      iVar5 = javascript_registerAtom(param_1,"anonymous",9,1);
                                      piVar3[0x1a] = iVar5;
                                      if (iVar5 != 0) {
                                        iVar5 = javascript_registerAtom(param_1,"arguments",9,1);
                                        piVar3[0x1b] = iVar5;
                                        if (iVar5 != 0) {
                                          iVar5 = javascript_registerAtom(param_1,"arity",5,1);
                                          piVar3[0x1c] = iVar5;
                                          if (iVar5 != 0) {
                                            iVar5 = javascript_registerAtom(param_1,"callee",6,1);
                                            piVar3[0x1d] = iVar5;
                                            if (iVar5 != 0) {
                                              iVar5 = javascript_registerAtom(param_1,"caller",6,1);
                                              piVar3[0x1e] = iVar5;
                                              if (iVar5 != 0) {
                                                iVar5 = javascript_registerAtom(param_1,"prototype",9,1);
                                                piVar3[0x1f] = iVar5;
                                                if (iVar5 != 0) {
                                                  iVar5 = javascript_registerAtom(param_1,"constructor",0xb,1);
                                                  piVar3[0x20] = iVar5;
                                                  if (iVar5 != 0) {
                                                    iVar5 = javascript_registerAtom(param_1,"__count__",9,1);
                                                    piVar3[0x21] = iVar5;
                                                    if (iVar5 != 0) {
                                                      iVar5 = javascript_registerAtom(param_1,"eval",4,1);
                                                      piVar3[0x22] = iVar5;
                                                      if (iVar5 != 0) {
                                                        iVar5 = javascript_registerAtom(param_1,"get",3,1);
                                                        piVar3[0x23] = iVar5;
                                                        if (iVar5 != 0) {
                                                          iVar5 = javascript_registerAtom(param_1,"getter",6,1)
                                                          ;
                                                          piVar3[0x24] = iVar5;
                                                          if (iVar5 != 0) {
                                                            iVar5 = javascript_registerAtom(param_1,"index",5,1
                                                                                );
                                                            piVar3[0x25] = iVar5;
                                                            if (iVar5 != 0) {
                                                              iVar5 = javascript_registerAtom(param_1,"input",5
                                                                                   ,1);
                                                              piVar3[0x26] = iVar5;
                                                              if (iVar5 != 0) {
                                                                iVar5 = javascript_registerAtom(param_1,
                                                  "length",6,1);
                                                  piVar3[0x27] = iVar5;
                                                  if (iVar5 != 0) {
                                                    iVar5 = javascript_registerAtom(param_1,"name",4,1);
                                                    piVar3[0x28] = iVar5;
                                                    if (iVar5 != 0) {
                                                      iVar5 = javascript_registerAtom(param_1,"__parent__",10,1
                                                                          );
                                                      piVar3[0x29] = iVar5;
                                                      if (iVar5 != 0) {
                                                        iVar5 = javascript_registerAtom(param_1,"__proto__",9,1
                                                                            );
                                                        piVar3[0x2a] = iVar5;
                                                        if (iVar5 != 0) {
                                                          iVar5 = javascript_registerAtom(param_1,"set",3,1);
                                                          piVar3[0x2b] = iVar5;
                                                          if (iVar5 != 0) {
                                                            iVar5 = javascript_registerAtom(param_1,"setter",6,
                                                                                 1);
                                                            piVar3[0x2c] = iVar5;
                                                            if (iVar5 != 0) {
                                                              iVar5 = javascript_registerAtom(param_1,
                                                  "toSource",8,1);
                                                  piVar3[0x2e] = iVar5;
                                                  if (iVar5 != 0) {
                                                    iVar5 = javascript_registerAtom(param_1,"toString",8,1);
                                                    piVar3[0x2f] = iVar5;
                                                    if (iVar5 != 0) {
                                                      iVar5 = javascript_registerAtom(param_1,"toLocaleString",
                                                                           0xe,1);
                                                      piVar3[0x2d] = iVar5;
                                                      if (iVar5 != 0) {
                                                        iVar5 = javascript_registerAtom(param_1,"valueOf",7,1);
                                                        piVar3[0x30] = iVar5;
                                                        if (iVar5 != 0) {
                                                          memset(piVar3 + 0x31,0,0x74);
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
          }
        }
      }
      return 0;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_initAtomTableFull (FUN_681391a0)
// Address: 681391a0
// Size: 107 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_initAtomTableFull(int param_1,int *param_2)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = crypto_insertHashEntry(0x400,javascript_computeValueHash,javascript_compareValues,&LAB_681382b0,&PTR_FUN_68193b18,param_2);
  param_2[1] = (int)puVar1;
  if (puVar1 == (undefined4 *)0x0) {
    xtra_reportError(param_1);
    return 0;
  }
  *param_2 = *(int *)(param_1 + 0x14);
  iVar2 = javascript_registerBuiltinAtoms(param_1,param_2);
  if (iVar2 == 0) {
    javascript_gcClearTable(param_1,param_2);
    return 0;
  }
  return 1;
}



// ============================================================
// Function: javascript_delegateToHost (FUN_68139210)
// Address: 68139210
// Size: 34 bytes
// Params: int param_1, ushort * param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_delegateToHost(int param_1,ushort *param_2,undefined4 param_3,int param_4)
{
  int iVar1;
  
  iVar1 = xtra_getPlatformData(param_1);
  events_renderChannelSprite(iVar1,param_2,param_3,param_4);
  return 0;
}



// ============================================================
// Function: js_runGC (FUN_68139240)
// Address: 68139240
// Size: 9 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_runGC(void)
{
  Ordinal_1124();
  return 0;
}



// ============================================================
// Function: js_allocAtomBlock (FUN_68139250)
// Address: 68139250
// Size: 104 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_allocAtomBlock(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = param_2;
  if (param_1 == 0) {
    iVar1 = Ordinal_1124(param_2);
    return iVar1;
  }
  if (param_2 == 0) {
    Ordinal_1125(&param_1);
    return 0;
  }
  uVar2 = Ordinal_1137(param_1);
  iVar1 = Ordinal_1124(uVar3);
  if (iVar1 != 0) {
    if (uVar2 <= uVar3) {
      uVar3 = uVar2;
    }
    Ordinal_1128(iVar1,param_1,uVar3);
  }
  Ordinal_1125(&param_1);
  return iVar1;
}



// ============================================================
// Function: javascript_callocWrapper (FUN_681392c0)
// Address: 681392c0
// Size: 20 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_callocWrapper(int param_1,int param_2)
{
  Ordinal_1124(param_1 * param_2);
  return 0;
}



// ============================================================
// Function: js_freeHandle (FUN_681392e0)
// Address: 681392e0
// Size: 16 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_freeHandle(void)
{
  Ordinal_1125(&stack0x00000004);
  return 0;
}



// ============================================================
// Function: js_isGCActive (FUN_681392f0)
// Address: 681392f0
// Size: 16 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool js_isGCActive(void)

{
  int iVar1;
  
  iVar1 = Ordinal_1103(90000);
  return (bool)('\x01' - (iVar1 != 0));
}



// ============================================================
// Function: javascript_initPoolBlock (FUN_68139300)
// Address: 68139300
// Size: 88 bytes
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * javascript_initPoolBlock(void)

{
  int in_EAX;
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  uVar1 = js_getSlotIndex(in_EAX,0x2400);
  if (uVar1 == 0) {
    return (uint *)0x0;
  }
  puVar2 = (uint *)(*(int *)(*(int *)(in_EAX + 0x10) + 4) + 0x400U & 0xfffffc00);
  *(uint **)(*(int *)(in_EAX + 0x10) + 0xc) = puVar2 + 4;
  puVar3 = puVar2;
  do {
    puVar3[1] = uVar1;
    *puVar3 = (uint)puVar2;
    puVar3 = puVar3 + 0x100;
    uVar1 = uVar1 + 0x80;
  } while (puVar3 < puVar2 + 0x800);
  return puVar2 + 2;
}



// ============================================================
// Function: js_getAtomSize (FUN_68139360)
// Address: 68139360
// Size: 36 bytes
// Params: uint param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint js_getAtomSize(uint param_1)

{
  uint uVar1;
  
  uVar1 = (param_1 >> 3 & 0x7f) + ((uint *)(param_1 & 0xfffffc00))[1];
  if (*(uint *)(param_1 & 0xfffffc00) <= uVar1) {
    uVar1 = uVar1 + 0x2000;
  }
  return uVar1;
}



// ============================================================
// Function: javascript_initGcArena (FUN_68139390)
// Address: 68139390
// Size: 123 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 javascript_initGcArena(int param_1,undefined4 param_2)

{
  undefined **ppuVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  
  if (DAT_681969a0 == (code *)0x0) {
    DAT_681969a0 = runtime_removePropertyRef;
    _DAT_681969a4 = certificates_freeStringContext;
    _DAT_681969ac = certificates_freeStringContext;
  }
  js_setPropertyDirect((undefined4 *)(param_1 + 4),"gc-arena",0x2400,8);
  uVar4 = 0x100;
  iVar3 = 0xc;
  uVar2 = 0;
  ppuVar1 = javascript_getDefaultAllocator();
  iVar3 = javascript_initHashTable((undefined4 *)(param_1 + 0x20),ppuVar1,uVar2,iVar3,uVar4);
  if (iVar3 == 0) {
    *(undefined4 *)(param_1 + 0x20) = 0;
    return 0;
  }
  *(undefined4 *)(param_1 + 0x40) = 0;
  *(undefined4 *)(param_1 + 0x54) = param_2;
  return 1;
}



// ============================================================
// Function: javascript_destroyGcArena (FUN_68139410)
// Address: 68139410
// Size: 76 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_destroyGcArena(int param_1)
{
  js_getPrototypeChain(param_1 + 4);
  javascript_freeArenaPool();
  if (*(int *)(param_1 + 0x20) != 0) {
    javascript_freeHashTable((int *)(param_1 + 0x20));
    *(int *)(param_1 + 0x20) = 0;
  }
  if (*(int **)(param_1 + 0x40) != (int *)0x0) {
    javascript_hashTableDestroy(*(int **)(param_1 + 0x40));
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  *(undefined4 *)(param_1 + 0x44) = 0;
  return 0;
}



// ============================================================
// Function: javascript_addAtomReference (FUN_68139460)
// Address: 68139460
// Size: 52 bytes
// Params: int param_1, uint param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_addAtomReference(int param_1,uint param_2,uint param_3)

{
  uint *puVar1;
  
  puVar1 = js_getPropertySlot((int *)(param_1 + 0x20),param_2,1);
  if (puVar1 != (uint *)0x0) {
    puVar1[1] = param_2;
    puVar1[2] = param_3;
    return 1;
  }
  return 0;
}



// ============================================================
// Function: js_markAtom (FUN_681394a0)
// Address: 681394a0
// Size: 35 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_markAtom(int param_1,undefined4 param_2)
{
  js_getPropertySlot((int *)(param_1 + 0x20),param_2,2);
  *(undefined1 *)(param_1 + 0x60) = 1;
  return 0;
}



// ============================================================
// Function: javascript_acquireAtomRef (FUN_681394d0)
// Address: 681394d0
// Size: 185 bytes
// Params: int param_1, uint param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_acquireAtomRef(int param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  undefined **ppuVar3;
  undefined4 *puVar4;
  uint *puVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  
  if (param_2 == 0) {
    return 1;
  }
  pbVar2 = (byte *)js_getAtomSize(param_2);
  bVar1 = *pbVar2;
  if ((bVar1 & 0xe0) != 0xe0) {
    if ((bVar1 & 7) == 0) {
      if ((bVar1 & 0xe0) != 0) {
        puVar5 = js_getPropertySlot(*(int **)(param_1 + 0x40),param_2,0);
        if (*puVar5 == 0) {
          return 1;
        }
        puVar5[2] = puVar5[2] + 1;
        return 1;
      }
      if (*(int *)(param_1 + 0x40) == 0) {
        uVar8 = 0x100;
        iVar7 = 0xc;
        uVar6 = 0;
        ppuVar3 = javascript_getDefaultAllocator();
        puVar4 = javascript_hashTableCreate(ppuVar3,uVar6,iVar7,uVar8);
        *(undefined4 **)(param_1 + 0x40) = puVar4;
        if (puVar4 == (undefined4 *)0x0) {
          return 0;
        }
      }
      puVar5 = js_getPropertySlot(*(int **)(param_1 + 0x40),param_2,1);
      if (puVar5 == (uint *)0x0) {
        return 0;
      }
      puVar5[1] = param_2;
      puVar5[2] = 1;
    }
    *pbVar2 = bVar1 + 0x20;
  }
  return 1;
}



// ============================================================
// Function: js_freeAtom (FUN_68139590)
// Address: 68139590
// Size: 134 bytes
// Params: int param_1, uint param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_freeAtom(int param_1,uint param_2)

{
  byte bVar1;
  byte *pbVar2;
  uint *puVar3;
  
  if (param_2 == 0) {
    return 1;
  }
  pbVar2 = (byte *)js_getAtomSize(param_2);
  bVar1 = *pbVar2;
  if ((bVar1 & 0xe0) != 0xe0) {
    if ((bVar1 & 7) == 0) {
      if ((bVar1 & 0xe0) != 0) {
        puVar3 = js_getPropertySlot(*(int **)(param_1 + 0x40),param_2,0);
        if (*puVar3 != 0) {
          puVar3 = puVar3 + 2;
          *puVar3 = *puVar3 - 1;
          if (*puVar3 == 0) {
            js_getPropertySlot(*(int **)(param_1 + 0x40),param_2,2);
            *pbVar2 = bVar1 & 0x1f;
            *(undefined1 *)(param_1 + 0x60) = 1;
            return 1;
          }
        }
      }
    }
    else {
      *pbVar2 = bVar1 - 0x20;
    }
  }
  *(undefined1 *)(param_1 + 0x60) = 1;
  return 1;
}



// ============================================================
// Function: js_lookupAtom (FUN_68139620)
// Address: 68139620
// Size: 171 bytes
// Params: undefined4 param_1, uint param_2, undefined4 param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_lookupAtom(undefined4 param_1,uint param_2,undefined4 param_3)
{
  uint *puVar1;
  byte bVar2;
  uint uVar3;
  code *pcVar4;
  byte *pbVar5;
  uint uVar6;
  uint *extraout_EDX;
  uint *puVar7;
  
  if (param_2 != 0) {
    while( true ) {
      pbVar5 = (byte *)js_getAtomSize(param_2);
      bVar2 = *pbVar5;
      if ((bVar2 & 8) != 0) break;
      *pbVar5 = bVar2 | 8;
      if ((bVar2 & 7) == 0) {
        puVar7 = (uint *)extraout_EDX[1];
        if (puVar7 == (uint *)0x0) {
          return 0;
        }
        uVar3 = *extraout_EDX;
        pcVar4 = *(code **)(*(int *)(uVar3 + 4) + 0x50);
        if (pcVar4 == (code *)0x0) {
          uVar6 = *(uint *)(uVar3 + 8);
          if (*(uint *)(uVar3 + 0xc) < *(uint *)(uVar3 + 8)) {
            uVar6 = *(uint *)(uVar3 + 0xc);
          }
        }
        else {
          uVar6 = (*pcVar4)(param_1,extraout_EDX,param_3);
        }
        puVar1 = puVar7 + uVar6;
        for (; puVar7 < puVar1; puVar7 = puVar7 + 1) {
          uVar3 = *puVar7;
          if (((uVar3 & 1) == 0) && (((byte)uVar3 & 7) != 6)) {
            js_lookupAtom(param_1,uVar3 & 0xfffffff8,0);
          }
        }
        return 0;
      }
      if ((bVar2 & 7) != 3) {
        return 0;
      }
      if ((*extraout_EDX & 0x40000000) == 0) {
        return 0;
      }
      param_2 = extraout_EDX[1];
      param_3 = 0;
      if (param_2 == 0) {
        return 0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_gcMarkScopeEntry (FUN_681396d0)
// Address: 681396d0
// Size: 50 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_gcMarkScopeEntry(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = **(uint **)(param_2 + 4);
  if (((uVar1 != 0) && ((uVar1 & 1) == 0)) && (((byte)uVar1 & 7) != 6)) {
    js_lookupAtom(param_4,uVar1 & 0xfffffff8,0);
  }
  return 0;
}



// ============================================================
// Function: javascript_gcMarkLinkedEntry (FUN_68139710)
// Address: 68139710
// Size: 27 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_gcMarkLinkedEntry(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  js_lookupAtom(param_4,*(uint *)(param_2 + 4),0);
  return 0;
}



// ============================================================
// Function: js_internAtom (FUN_68139730)
// Address: 68139730
// Size: 45 bytes
// Params: int param_1, uint param_2, uint param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_internAtom(int param_1,uint param_2,uint param_3)

{
  int iVar1;
  
  iVar1 = javascript_addAtomReference(*(int *)(param_1 + 0x14),param_2,param_3);
  if (iVar1 == 0) {
    xtra_reportError(param_1);
  }
  return iVar1;
}



// ============================================================
// Function: js_getAtomString (FUN_68139760)
// Address: 68139760
// Size: 41 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_getAtomString(int param_1,uint param_2)

{
  int iVar1;
  
  iVar1 = javascript_acquireAtomRef(*(int *)(param_1 + 0x14),param_2);
  if (iVar1 == 0) {
    xtra_reportError(param_1);
  }
  return iVar1;
}



// ============================================================
// Function: javascript_gcMarkAtomValue (FUN_68139790)
// Address: 68139790
// Size: 22 bytes
// Params: uint param_1, undefined4 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcMarkAtomValue(uint param_1,undefined4 param_2)
{
  js_lookupAtom(param_2,param_1,0);
  return 0;
}



// ============================================================
// Function: js_allocAtomSlot (FUN_681397b0)
// Address: 681397b0
// Size: 55 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_allocAtomSlot(undefined4 param_1,int param_2)
{
  uint uVar1;
  
  if ((*(uint *)(param_2 + 0x10) & 4) == 0) {
    *(uint *)(param_2 + 0x10) = *(uint *)(param_2 + 0x10) | 4;
    uVar1 = *(uint *)(param_2 + 8);
    if (((uVar1 & 1) == 0) && (((byte)uVar1 & 7) != 6)) {
      js_lookupAtom(param_1,uVar1 & 0xfffffff8,0);
    }
  }
  return 0;
}



