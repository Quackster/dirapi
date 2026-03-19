// Module: runtime
// Topic: Property lookup/set, scope chain resolution, object creation, and prototype operations
// Address range: 0x68126a30 - 0x6812ac50
// Functions (74):
//   runtime_setPropertyVtable
//   runtime_setPropertyVtableEx
//   runtime_propertyStubA
//   runtime_propertyStubB
//   runtime_getPropertyAttributes
//   runtime_checkPropertyWatch
//   runtime_setPropertyFromResource
//   runtime_setPropertyFromResourceEx
//   runtime_getPropertyWithVerify
//   runtime_setPropertyWithVerify
//   runtime_deletePropertyWithCheck
//   runtime_hasPropertyWithCheck
//   runtime_resolvePropertyOwner
//   runtime_initPropertyVtable
//   runtime_insertPropertyEntry
//   runtime_deletePropertyEntry
//   runtime_freePropertyTable
//   runtime_resolvePropertyRef
//   runtime_registerAtomFromString
//   runtime_removePropertyRef
//   runtime_growPropertyTable
//   runtime_shrinkPropertyTable
//   runtime_callPropertyEx
//   runtime_setPropertyValue
//   runtime_getPropertyDataOffset
//   runtime_computePropertyHash
//   runtime_comparePropertyKeys
//   runtime_getProperty
//   runtime_setPropertyEx
//   runtime_setPropertyByName
//   runtime_getPropertyValue
//   runtime_getPropertyEx
//   runtime_getPropertyAndCheck
//   runtime_getPropertyWithFlags
//   runtime_getPropertyDetailed
//   runtime_allocPropertySlots
//   runtime_resizePropertySlots
//   runtime_accessPropertySlot
//   runtime_invokePropertyGetter
//   runtime_callObjectMethodByIndex
//   runtime_callObjectMethodApply
//   runtime_callObjectMethodCall
//   runtime_resolvePropertyValue
//   runtime_resolvePropertyByAtom
//   runtime_resolvePropertyByString
//   runtime_copyPropertyDescriptor
//   runtime_deleteProperty
//   runtime_hasProperty
//   runtime_defineProperty
//   runtime_removePropertyAtom
//   runtime_cleanupPropertyRefs
//   runtime_getPropertySlotValue
//   runtime_setPropertySlotValue
//   runtime_getPropertyDescriptor
//   runtime_resolveAndGetProperty
//   runtime_getPropertySafe
//   runtime_getPropertyValueSafe
//   runtime_getPropertyExSafe
//   runtime_getPropertyAndCheckSafe
//   runtime_getPropertyWithFlagsSafe
//   runtime_getPropertyDetailedSafe
//   runtime_accessPropertySlotSafe
//   runtime_invokePropertyGetterSafe
//   runtime_setProperty
//   runtime_createPropertyFromName
//   runtime_invokeMethod
//   runtime_definePropertyFromAtom
//   runtime_resolveAndSetProperty
//   runtime_definePropertyOnObject
//   runtime_serializeObjectRef
//   runtime_getPropertyForIn
//   runtime_setPropertyOnObject
//   runtime_deletePropertyOnObject
//   runtime_definePropertyOnObjectSafe
//   runtime_constructError
//   runtime_initGlobalObject
//   runtime_callProperty
//   runtime_freePropertyChain


/* FIXUP(STUB-FILE): The following 4 functions have been stubbed out.
   The Ghidra decompilation produced code with severe structural issues
   (broken switch statements, missing variables, invalid casts) that
   could not be automatically repaired. Each function needs manual
   review against the original binary to restore correct logic. */

// ============================================================
// Function: runtime_setPropertyVtable (FUN_68126a30)
// Address: 68126a30
// Size: 1770 bytes
// Params: uint * param_1, int * param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_setPropertyVtable(uint *param_1,int *param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

// ============================================================
// Function: runtime_setPropertyVtableEx (FUN_68127120)
// Address: 68127120
// Size: 233 bytes
// Params: uint * param_1, int * param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_setPropertyVtableEx(uint *param_1,int *param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

// ============================================================
// Function: runtime_propertyStubA (FUN_68127210)
// Address: 68127210
// Size: 28 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_propertyStubA(void)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

// ============================================================
// Function: runtime_propertyStubB (FUN_68127230)
// Address: 68127230
// Size: 90 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_propertyStubB(void)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

// ============================================================
// Function: runtime_getPropertyAttributes (FUN_68127290)
// Address: 68127290
// Size: 151 bytes
// Params: uint * param_1, int * param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPropertyAttributes(uint *param_1,int *param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined *puVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  uint *puVar6;
  undefined1 local_c [4];
  byte local_8 [4];
  
  puVar2 = param_1;
  puVar6 = param_4 + 1;
  uVar3 = runtime_callFunction((int)param_1,puVar6,0);
  if (uVar3 != 0) {
    *puVar6 = *(uint *)(uVar3 + 4);
    puVar1 = (undefined *)*param_4;
    iVar4 = xtra_getResourceData((int)puVar2,(uint)puVar1,(uint *)&param_1);
    if (iVar4 != 0) {
      iVar4 = (**(code **)(*(int *)(*param_2 + 4) + 0x2c))(puVar2,param_2,param_1,3,local_c,local_8)
      ;
      if (iVar4 != 0) {
        if ((local_8[0] & 2) != 0) {
          return 1;
        }
        uVar5 = runtime_registerWatch(puVar2,param_2,puVar1,0x68127230,*(int *)(uVar3 + 4));
        return uVar5;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_checkPropertyWatch (FUN_68127330)
// Address: 68127330
// Size: 30 bytes
// Params: int param_1, int param_2, undefined4 param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_checkPropertyWatch(int param_1,int param_2,undefined4 param_3,uint *param_4)
{
  runtime_lookupWatch(param_1,param_2,*param_4,(undefined4 *)0x0,(undefined4 *)0x0);
  return 0;
}



// ============================================================
// Function: runtime_setPropertyFromResource (FUN_68127350)
// Address: 68127350
// Size: 217 bytes
// Params: int param_1, int * param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_setPropertyFromResource(int param_1,int *param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  undefined **ppuVar1;
  code *pcVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  int *local_8;
  
  iVar3 = param_1;
  iVar5 = xtra_getResourceData(param_1,*param_4,(uint *)&param_4);
  piVar4 = param_2;
  if (iVar5 == 0) {
    return 0;
  }
  iVar5 = (**(code **)(*(int *)(*param_2 + 4) + 8))(iVar3,param_2,param_4,&local_8,&param_1);
  if (iVar5 == 0) {
    return 0;
  }
  if (param_1 == 0) {
    *param_5 = 6;
    return 1;
  }
  if (local_8 == piVar4) {
    *param_5 = 0xe;
  }
  else {
    ppuVar1 = *(undefined ***)(*local_8 + 4);
    if ((ppuVar1 == &PTR_FUN_68192948) ||
       ((ppuVar1 != (undefined **)0x0 && (*ppuVar1 == PTR_FUN_68192948)))) {
      *param_5 = (uint)((~*(byte *)(param_1 + 0x10) & 0x44) == 0) * 8 | 6;
    }
    else {
      *param_5 = 6;
    }
  }
  pcVar2 = *(code **)(*(int *)(*local_8 + 4) + 0x34);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(iVar3,local_8,param_1);
  }
  return 1;
}



// ============================================================
// Function: runtime_setPropertyFromResourceEx (FUN_68127430)
// Address: 68127430
// Size: 267 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_setPropertyFromResourceEx(int *param_1,int *param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  undefined **ppuVar1;
  code *pcVar2;
  int *piVar3;
  int *piVar4;
  int iVar5;
  uint local_c;
  int local_8;
  
  piVar3 = param_1;
  iVar5 = xtra_getResourceData((int)param_1,*param_4,(uint *)&param_4);
  piVar4 = param_2;
  if (iVar5 == 0) {
    return 0;
  }
  iVar5 = (**(code **)(*(int *)(*param_2 + 4) + 8))(piVar3,param_2,param_4,&param_1,&local_8);
  if (iVar5 == 0) {
    return 0;
  }
  if (local_8 == 0) {
    *param_5 = 6;
    return 1;
  }
  if ((param_1 != piVar4) &&
     (((ppuVar1 = *(undefined ***)(*param_1 + 4), ppuVar1 != &PTR_FUN_68192948 &&
       ((ppuVar1 == (undefined **)0x0 || (*ppuVar1 != PTR_FUN_68192948)))) ||
      ((~*(byte *)(local_8 + 0x10) & 0x44) != 0)))) {
    if ((code *)ppuVar1[0xd] != (code *)0x0) {
      (*(code *)ppuVar1[0xd])(piVar3,param_1,local_8);
    }
    *param_5 = 6;
    return 1;
  }
  iVar5 = (**(code **)(*(int *)(*param_1 + 4) + 0x18))(piVar3,param_1,param_4,local_8,&local_c);
  pcVar2 = *(code **)(*(int *)(*param_1 + 4) + 0x34);
  if (pcVar2 != (code *)0x0) {
    (*pcVar2)(piVar3,param_1,local_8);
  }
  if (iVar5 != 0) {
    *param_5 = (local_c & 1) * 8 | 6;
  }
  return iVar5;
}



// ============================================================
// Function: runtime_getPropertyWithVerify (FUN_68127540)
// Address: 68127540
// Size: 178 bytes
// Params: uint param_1, int * param_2, undefined4 param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPropertyWithVerify(uint param_1,int *param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  byte bVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined4 uVar7;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  puVar4 = param_4;
  uVar2 = param_1;
  uVar1 = param_4[1];
  bVar5 = xtra_lookupHashByte(param_1,uVar1);
  if (CONCAT31(extraout_var,bVar5) == 2) {
    iVar6 = xtra_getResourceData(uVar2,*puVar4,(uint *)&param_4);
    piVar3 = param_2;
    if (iVar6 != 0) {
      iVar6 = certs_verifySignature(uVar2,param_2,(int)param_4,0x10,&param_1);
      if (iVar6 != 0) {
        iVar6 = (**(code **)(*(int *)(*piVar3 + 4) + 0x2c))(uVar2,piVar3,param_4,3,local_c,local_8);
        if (iVar6 != 0) {
          uVar7 = (**(code **)(*(int *)(*piVar3 + 4) + 0xc))
                            (uVar2,piVar3,param_4,0x80000001,uVar1 & 0xfffffff8,0,0x50,0);
          return uVar7;
        }
      }
    }
  }
  else {
    xtra_invokeMethod(uVar2,xtra_getErrorString,0,0x97);
  }
  return 0;
}



// ============================================================
// Function: runtime_setPropertyWithVerify (FUN_68127600)
// Address: 68127600
// Size: 178 bytes
// Params: uint param_1, int * param_2, undefined4 param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_setPropertyWithVerify(uint param_1,int *param_2,undefined4 param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  uint *puVar4;
  byte bVar5;
  undefined3 extraout_var;
  int iVar6;
  undefined4 uVar7;
  undefined1 local_c [4];
  undefined1 local_8 [4];
  
  puVar4 = param_4;
  uVar2 = param_1;
  uVar1 = param_4[1];
  bVar5 = xtra_lookupHashByte(param_1,uVar1);
  if (CONCAT31(extraout_var,bVar5) == 2) {
    iVar6 = xtra_getResourceData(uVar2,*puVar4,(uint *)&param_4);
    piVar3 = param_2;
    if (iVar6 != 0) {
      iVar6 = certs_verifySignature(uVar2,param_2,(int)param_4,0x20,&param_1);
      if (iVar6 != 0) {
        iVar6 = (**(code **)(*(int *)(*piVar3 + 4) + 0x2c))(uVar2,piVar3,param_4,3,local_c,local_8);
        if (iVar6 != 0) {
          uVar7 = (**(code **)(*(int *)(*piVar3 + 4) + 0xc))
                            (uVar2,piVar3,param_4,0x80000001,0,uVar1 & 0xfffffff8,0x60,0);
          return uVar7;
        }
      }
    }
  }
  else {
    xtra_invokeMethod(uVar2,xtra_getErrorString,0,0x97);
  }
  return 0;
}



// ============================================================
// Function: runtime_deletePropertyWithCheck (FUN_681276c0)
// Address: 681276c0
// Size: 121 bytes
// Params: int param_1, int * param_2, undefined4 param_3, uint * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_deletePropertyWithCheck(int param_1,int *param_2,undefined4 param_3,uint *param_4,undefined4 *param_5)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *local_8;
  
  iVar2 = param_1;
  iVar3 = xtra_getResourceData(param_1,*param_4,(uint *)&param_4);
  if (iVar3 != 0) {
    iVar3 = (**(code **)(*(int *)(*param_2 + 4) + 8))(iVar2,param_2,param_4,&local_8,&param_1);
    if (iVar3 != 0) {
      if (param_1 != 0) {
        if ((*(byte *)(param_1 + 0x10) & 0x10) != 0) {
          *param_5 = *(undefined4 *)(param_1 + 4);
        }
        pcVar1 = *(code **)(*(int *)(*local_8 + 4) + 0x34);
        if (pcVar1 != (code *)0x0) {
          (*pcVar1)(iVar2,local_8,param_1);
        }
      }
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_hasPropertyWithCheck (FUN_68127740)
// Address: 68127740
// Size: 121 bytes
// Params: int param_1, int * param_2, undefined4 param_3, uint * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_hasPropertyWithCheck(int param_1,int *param_2,undefined4 param_3,uint *param_4,undefined4 *param_5)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int *local_8;
  
  iVar2 = param_1;
  iVar3 = xtra_getResourceData(param_1,*param_4,(uint *)&param_4);
  if (iVar3 != 0) {
    iVar3 = (**(code **)(*(int *)(*param_2 + 4) + 8))(iVar2,param_2,param_4,&local_8,&param_1);
    if (iVar3 != 0) {
      if (param_1 != 0) {
        if ((*(byte *)(param_1 + 0x10) & 0x20) != 0) {
          *param_5 = *(undefined4 *)(param_1 + 8);
        }
        pcVar1 = *(code **)(*(int *)(*local_8 + 4) + 0x34);
        if (pcVar1 != (code *)0x0) {
          (*pcVar1)(iVar2,local_8,param_1);
        }
      }
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_resolvePropertyOwner (FUN_681277c0)
// Address: 681277c0
// Size: 45 bytes
// Params: undefined4 param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_resolvePropertyOwner(undefined4 param_1,int *param_2)

{
  code *pcVar1;
  int *piVar2;
  
  piVar2 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
  if ((piVar2 != (int *)0x0) &&
     (pcVar1 = *(code **)(*(int *)(*piVar2 + 4) + 0x30), param_2 = piVar2, pcVar1 != (code *)0x0)) {
    piVar2 = (int *)(*pcVar1)(param_1,piVar2);
    return piVar2;
  }
  return param_2;
}



// ============================================================
// Function: runtime_initPropertyVtable (FUN_68127800)
// Address: 68127800
// Size: 55 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, int param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_initPropertyVtable(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)
{
  param_1[1] = param_3;
  *param_1 = param_2;
  param_1[2] = 5;
  param_1[3] = ((*(byte *)(param_4 + 4) & 1) != 0) + 3 + (uint)*(byte *)(param_4 + 5);
  return 0;
}



// ============================================================
// Function: runtime_insertPropertyEntry (FUN_68127840)
// Address: 68127840
// Size: 9 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_insertPropertyEntry(int param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5)
{
  strings_insertTableEntry(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_deletePropertyEntry (FUN_68127850)
// Address: 68127850
// Size: 9 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_deletePropertyEntry(undefined4 param_1,int param_2)
{
  strings_freeTableEntry(param_1,param_2);
  return 0;
}



// ============================================================
// Function: runtime_freePropertyTable (FUN_68127860)
// Address: 68127860
// Size: 12 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_freePropertyTable(undefined4 param_1,int *param_2)
{
  *param_2 = *param_2 + 1;
  return 0;
}



// ============================================================
// Function: runtime_resolvePropertyRef (FUN_68127870)
// Address: 68127870
// Size: 70 bytes
// Params: undefined4 param_1, int * param_2, int param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_resolvePropertyRef(undefined4 param_1,int *param_2,int param_3)

{
  undefined **ppuVar1;
  
  *param_2 = *param_2 + -1;
  ppuVar1 = (undefined **)param_2[1];
  if (*param_2 == 0) {
    (*(code *)ppuVar1[1])(param_1,param_2);
    return (int *)0x0;
  }
  if (((ppuVar1 == &PTR_FUN_68192948) ||
      ((ppuVar1 != (undefined **)0x0 && (*ppuVar1 == PTR_FUN_68192948)))) && (param_2[4] == param_3)
     ) {
    param_2[4] = 0;
  }
  return param_2;
}



// ============================================================
// Function: runtime_registerAtomFromString (FUN_681278c0)
// Address: 681278c0
// Size: 209 bytes
// Params: undefined4 param_1, char * param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall runtime_registerAtomFromString(undefined4 param_1,char *param_2,undefined4 *param_3)

{
  int param_4;
  char cVar1;
  code *pcVar2;
  int *in_EAX;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int unaff_EBX;
  int *local_c;
  int local_8;
  
  pcVar3 = param_2;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar4 = javascript_registerAtom(unaff_EBX,param_2,(int)pcVar3 - (int)(param_2 + 1),0);
  if (iVar4 != 0) {
    if ((in_EAX == (int *)0x0) &&
       ((*(int *)(unaff_EBX + 0x34) == 0 ||
        (in_EAX = *(int **)(*(int *)(unaff_EBX + 0x34) + 0x34), in_EAX == (int *)0x0)))) {
      piVar5 = *(int **)(unaff_EBX + 0x8c);
      if (piVar5 == (int *)0x0) {
        *param_3 = 0x80000001;
        return 1;
      }
    }
    else {
      do {
        piVar5 = in_EAX;
        in_EAX = (int *)(*(uint *)(piVar5[1] + 4) & 0xfffffff8);
      } while (in_EAX != (int *)0x0);
    }
    iVar4 = (**(code **)(*(int *)(*piVar5 + 4) + 8))();
    if (iVar4 != 0) {
      if (local_8 == 0) {
        *param_3 = 0x80000001;
        return 1;
      }
      *param_3 = *(undefined4 *)(local_c[1] + *(int *)(local_8 + 0xc) * 4);
      pcVar2 = *(code **)(*(int *)(*local_c + 4) + 0x34);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)();
      }
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_removePropertyRef (FUN_681279a0)
// Address: 681279a0
// Size: 113 bytes
// Params: int param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_removePropertyRef(int param_1,undefined4 *param_2)
{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)*param_2;
  if (piVar1 != (int *)0x0) {
    iVar2 = *(int *)(param_1 + 0x14);
    if (*(int *)(iVar2 + 0x220) != 0) {
      (**(code **)(iVar2 + 0x220))(param_1,param_2,0,*(undefined4 *)(iVar2 + 0x224));
    }
    runtime_checkWatchStates(param_1,(int)param_2);
    (**(code **)((*(uint *)(param_2[1] + 8) & 0xfffffffe) + 0x24))(param_1,param_2);
    runtime_resolvePropertyRef(param_1,piVar1,(int)param_2);
    *param_2 = 0;
    xtra_checkAndFlush(param_1,param_2[1] + -4);
    param_2[1] = 0;
  }
  return 0;
}



// ============================================================
// Function: runtime_growPropertyTable (FUN_68127a20)
// Address: 68127a20
// Size: 122 bytes
// Params: int param_1, int * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_growPropertyTable(int param_1,int *param_2,undefined4 *param_3)
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  iVar1 = *param_2;
  uVar5 = *(uint *)(iVar1 + 0xc);
  if (*(uint *)(iVar1 + 8) <= uVar5) {
    uVar5 = uVar5 + (uVar5 + 1 >> 1);
    puVar2 = (uint *)xtra_allocJSString(param_1,param_2[1] + -4,uVar5 * 4 + 4);
    if (puVar2 == (uint *)0x0) {
      return 0;
    }
    uVar3 = *puVar2 + 1;
    if (uVar3 <= uVar5) {
      puVar6 = puVar2 + uVar3;
      for (iVar4 = (uVar5 - uVar3) + 1; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0x80000001;
        puVar6 = puVar6 + 1;
      }
    }
    *(uint *)(iVar1 + 8) = uVar5;
    *puVar2 = uVar5;
    param_2[1] = (int)(puVar2 + 1);
  }
  *param_3 = *(undefined4 *)(iVar1 + 0xc);
  *(int *)(iVar1 + 0xc) = *(int *)(iVar1 + 0xc) + 1;
  return 0;
}



// ============================================================
// Function: runtime_shrinkPropertyTable (FUN_68127aa0)
// Address: 68127aa0
// Size: 114 bytes
// Params: int param_1, int * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_shrinkPropertyTable(int param_1,int *param_2,int param_3)
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  
  *(undefined4 *)(param_2[1] + param_3 * 4) = 0x80000001;
  iVar1 = *param_2;
  if (*(int *)(iVar1 + 0xc) == param_3 + 1) {
    *(int *)(iVar1 + 0xc) = param_3;
  }
  if ((5 < *(uint *)(iVar1 + 8)) &&
     (uVar3 = *(uint *)(iVar1 + 0xc), uVar3 < *(uint *)(iVar1 + 8) >> 1)) {
    uVar3 = uVar3 + (uVar3 >> 1);
    if (uVar3 < 5) {
      uVar3 = 5;
    }
    puVar2 = (uint *)xtra_allocJSString(param_1,param_2[1] + -4,uVar3 * 4 + 4);
    if (puVar2 != (uint *)0x0) {
      *(uint *)(iVar1 + 8) = uVar3;
      *puVar2 = uVar3;
      param_2[1] = (int)(puVar2 + 1);
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_callPropertyEx (FUN_68127b20)
// Address: 68127b20
// Size: 299 bytes
// Params: uint param_1, undefined4 * param_2, uint param_3, undefined * param_4, undefined * param_5, int param_6, uint param_7, uint param_8, int param_9
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_callPropertyEx(uint param_1,undefined4 *param_2,uint param_3,undefined *param_4,
                 undefined *param_5,int param_6,uint param_7,uint param_8,int param_9)
{
  ushort uVar1;
  ushort uVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  uint uVar9;
  ushort *puVar10;
  ushort *puVar11;
  
  piVar3 = strings_getTableEntry(param_1,param_2);
  if (piVar3 != (int *)0x0) {
    if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
      piVar8 = (int *)(*(uint *)(param_3 + 8) & 0xfffffff8);
      puVar10 = (ushort *)piVar8[1];
      uVar6 = (uint)(*puVar10 == 0x2d);
      if (uVar6 != 0) {
        puVar10 = puVar10 + 1;
      }
      if (((*puVar10 < 0x80) && (iVar4 = isdigit((uint)*puVar10), iVar4 != 0)) &&
         (*piVar8 - uVar6 < 0xb)) {
        uVar5 = 0;
        puVar11 = puVar10 + 1;
        uVar7 = 0;
        uVar9 = *puVar10 - 0x30;
        if (uVar9 != 0) {
          uVar1 = *puVar11;
          while ((uVar1 < 0x80 && (iVar4 = isdigit((uint)uVar1), iVar4 != 0))) {
            uVar2 = *puVar11;
            uVar1 = puVar11[1];
            puVar11 = puVar11 + 1;
            uVar7 = uVar2 - 0x30;
            uVar5 = uVar9;
            uVar9 = uVar7 + uVar9 * 10;
          }
        }
        if ((*puVar11 == 0) && ((uVar5 < 0x6666666 || ((uVar5 == 0x6666666 && (uVar7 < 4)))))) {
          if (uVar6 != 0) {
            uVar9 = -uVar9;
          }
          param_3 = uVar9 * 2 | 1;
        }
      }
    }
    strings_createTableEntry(param_1,(int)piVar3,param_3,param_4,param_5,param_6,param_7,param_8,param_9);
    return 0;
  }
  return 0;
}



// ============================================================
// Function: runtime_setPropertyValue (FUN_68127c50)
// Address: 68127c50
// Size: 135 bytes
// Params: uint param_1, undefined4 * param_2, uint * param_3, uint param_4, uint param_5, undefined * param_6, undefined * param_7
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_setPropertyValue(uint param_1,undefined4 *param_2,uint *param_3,uint param_4,uint param_5,
                 undefined *param_6,undefined *param_7)
{
  undefined4 *puVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  
  piVar3 = strings_getTableEntry(param_1,param_2);
  if (piVar3 == (int *)0x0) {
    return 0;
  }
  puVar4 = strings_addTableRange(param_1,(int)piVar3,param_3,param_4,param_5,param_6,param_7);
  if ((puVar4 != (uint *)0x0) && (iVar2 = *(int *)(param_1 + 0x14), *(int *)(iVar2 + 0x224c) == 0))
  {
    puVar1 = (undefined4 *)(iVar2 + 0x248 + (((uint)param_2 >> 3 ^ *puVar4) & 0x3ff) * 8);
    *(undefined4 *)(iVar2 + 0x2248) = 0;
    *puVar1 = param_2;
    puVar1[1] = puVar4;
  }
  return 0;
}



// ============================================================
// Function: runtime_getPropertyDataOffset (FUN_68127ce0)
// Address: 68127ce0
// Size: 13 bytes
// Params: undefined4 param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_getPropertyDataOffset(undefined4 param_1,int param_2)

{
  return param_2 + 4;
}



// ============================================================
// Function: runtime_computePropertyHash (FUN_68127cf0)
// Address: 68127cf0
// Size: 18 bytes
// Params: undefined4 param_1, uint * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_computePropertyHash(undefined4 param_1,uint *param_2)

{
  return *param_2 >> 3 ^ param_2[1];
}



// ============================================================
// Function: runtime_comparePropertyKeys (FUN_68127d10)
// Address: 68127d10
// Size: 39 bytes
// Params: undefined4 param_1, int param_2, int * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_comparePropertyKeys(undefined4 param_1,int param_2,int *param_3)

{
  if ((*(int *)(param_2 + 4) == *param_3) && (*(int *)(param_2 + 8) == param_3[1])) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: runtime_getProperty (FUN_68127d40)
// Address: 68127d40
// Size: 963 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 * param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_getProperty(uint param_1,int *param_2,uint param_3,undefined4 *param_4,uint *param_5)

{
  ushort uVar1;
  ushort uVar2;
  undefined **ppuVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  code *pcVar7;
  uint uVar8;
  int *piVar9;
  uint uVar10;
  ushort *puVar11;
  ushort *puVar12;
  int *local_28;
  uint local_24;
  uint *local_20;
  int local_1c;
  int *local_18;
  code *local_14;
  int *local_10;
  uint local_c;
  uint local_8;
  
  uVar4 = param_1;
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    piVar9 = (int *)(*(uint *)(param_3 + 8) & 0xfffffff8);
    puVar11 = (ushort *)piVar9[1];
    pcVar7 = (code *)(uint)(*puVar11 == 0x2d);
    if (pcVar7 != (code *)0x0) {
      puVar11 = puVar11 + 1;
    }
    local_14 = pcVar7;
    if (((*puVar11 < 0x80) && (iVar5 = isdigit((uint)*puVar11), iVar5 != 0)) &&
       ((uint)(*piVar9 - (int)pcVar7) < 0xb)) {
      local_c = 0;
      puVar12 = puVar11 + 1;
      uVar8 = 0;
      uVar10 = *puVar11 - 0x30;
      if (uVar10 != 0) {
        uVar1 = *puVar12;
        while ((uVar1 < 0x80 && (iVar5 = isdigit((uint)uVar1), iVar5 != 0))) {
          uVar2 = *puVar12;
          uVar1 = puVar12[1];
          puVar12 = puVar12 + 1;
          uVar8 = uVar2 - 0x30;
          local_c = uVar10;
          uVar10 = uVar8 + uVar10 * 10;
        }
      }
      if ((*puVar12 == 0) && ((local_c < 0x6666666 || ((local_c == 0x6666666 && (uVar8 < 4)))))) {
        if (local_14 != (code *)0x0) {
          uVar10 = -uVar10;
        }
        param_3 = uVar10 * 2 | 1;
      }
    }
  }
  local_18 = param_2;
  do {
    uVar8 = *param_2;
    local_c = uVar8;
    if (*(int **)(uVar8 + 0x10) == param_2) {
      puVar6 = strings_lookupInTable(uVar8,param_3,0);
      param_1 = *puVar6 & 0xfffffffe;
      if (param_1 != 0) goto LAB_681280c9;
    }
    else {
      param_1 = 0;
    }
    uVar8 = *(uint *)(param_2[1] + 8) & 0xfffffffe;
    local_14 = *(code **)(uVar8 + 0x1c);
    if (local_14 != (code *)&LAB_6811de40) {
      piVar9 = *(int **)(uVar4 + 0x170);
      local_24 = param_3;
      local_28 = param_2;
      if (*(int *)(uVar4 + 0x16c) == 0) {
        if (piVar9 == (int *)0x0) {
          piVar9 = javascript_hashTableCreate(&PTR_FUN_6817e928,0,0xc,0x10);
          if (piVar9 == (int *)0x0) goto LAB_681280a7;
          *(int **)(uVar4 + 0x170) = piVar9;
        }
      }
      else {
        puVar6 = js_getPropertySlot(piVar9,&local_28,0);
        if (*puVar6 != 0) goto LAB_68127e8d;
      }
      local_20 = js_getPropertySlot(piVar9,&local_28,1);
      if (local_20 == (uint *)0x0) {
LAB_681280a7:
        xtra_reportError(uVar4);
        return 0;
      }
      local_20[1] = (uint)local_28;
      local_20[2] = local_24;
      local_1c = piVar9[6];
      *(int *)(uVar4 + 0x16c) = *(int *)(uVar4 + 0x16c) + 1;
      *param_5 = 0;
      uVar8 = *(uint *)(uVar8 + 4);
      if ((uVar8 & 4) == 0) {
        uVar8 = param_3;
        if ((param_3 & 1) == 0) {
          uVar8 = *(uint *)(param_3 + 8);
        }
        iVar5 = (*local_14)(uVar4,param_2,uVar8);
        if ((iVar5 != 0) && (local_c = *param_2, *(int **)(local_c + 0x10) == param_2)) {
LAB_68128012:
          puVar6 = strings_lookupInTable(local_c,param_3,0);
          param_1 = *puVar6 & 0xfffffffe;
        }
      }
      else {
        iVar5 = *(int *)(uVar4 + 0x34);
        local_8 = 0;
        if (((iVar5 != 0) && (*(byte **)(iVar5 + 0x38) != (byte *)0x0)) &&
           ((local_8 = (uint)(((byte)*(uint *)(&DAT_68193cbc +
                                              (uint)**(byte **)(iVar5 + 0x38) * 0x10) & 0x30) !=
                             0x10),
            (*(uint *)(&DAT_68193cbc + (uint)**(byte **)(iVar5 + 0x38) * 0x10) & 0x40) != 0 ||
            ((*(byte *)(iVar5 + 0x4c) & 2) != 0)))) {
          local_8 = local_8 | 2;
        }
        local_10 = (int *)(-(uint)((uVar8 & 0x20) != 0) & (uint)local_18);
        uVar8 = param_3;
        if ((param_3 & 1) == 0) {
          uVar8 = *(uint *)(param_3 + 8);
        }
        iVar5 = (*local_14)(uVar4,param_2,uVar8,local_8,&local_10);
        if ((iVar5 != 0) && (local_10 != (int *)0x0)) {
          local_c = *local_10;
          ppuVar3 = *(undefined ***)(local_c + 4);
          if ((ppuVar3 == &PTR_FUN_68192948) ||
             ((ppuVar3 != (undefined **)0x0 && (*ppuVar3 == PTR_FUN_68192948)))) {
            if (*(int **)(local_c + 0x10) == local_10) goto LAB_68128012;
          }
          else {
            iVar5 = (**(code **)(*(int *)(local_c + 4) + 8))(uVar4,local_10,param_3,param_4,param_5)
            ;
          }
        }
      }
      if ((piVar9[6] == local_1c) &&
         ((uint)piVar9[5] < (uint)(1 << (0x20U - (char)(short)piVar9[2] & 0x1f)) >> 2)) {
        js_enumerateProperties(piVar9,local_20);
      }
      else {
        js_getPropertySlot(piVar9,&local_28,2);
      }
      *(int *)(uVar4 + 0x16c) = *(int *)(uVar4 + 0x16c) + -1;
      if ((iVar5 == 0) || (*param_5 != 0)) {
        return iVar5;
      }
      uVar8 = local_c;
      if (param_1 != 0) {
LAB_681280c9:
        *param_4 = *(undefined4 *)(uVar8 + 0x10);
        *param_5 = param_1;
        return 1;
      }
    }
    param_2 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
    if (param_2 == (int *)0x0) {
LAB_68127e8d:
      *param_4 = 0;
      *param_5 = 0;
      return 1;
    }
    ppuVar3 = *(undefined ***)(*param_2 + 4);
    if ((ppuVar3 != &PTR_FUN_68192948) &&
       ((ppuVar3 == (undefined **)0x0 || (*ppuVar3 != PTR_FUN_68192948)))) {
      iVar5 = (**(code **)(*(int *)(*param_2 + 4) + 8))(uVar4,param_2,param_3,param_4,param_5);
      return iVar5;
    }
  } while( true );
}



// ============================================================
// Function: runtime_setPropertyEx (FUN_68128110)
// Address: 68128110
// Size: 323 bytes
// Params: int param_1, uint param_2, undefined4 * param_3, undefined4 * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_setPropertyEx(int param_1,uint param_2,undefined4 *param_3,undefined4 *param_4,uint *param_5)

{
  undefined4 *puVar1;
  int iVar2;
  undefined **ppuVar3;
  uint *puVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  int *local_8;
  
  uVar5 = param_2;
  iVar2 = *(int *)(param_1 + 0x14);
  piVar8 = *(int **)(*(int *)(param_1 + 0x34) + 0x34);
  while( true ) {
    piVar7 = piVar8;
    ppuVar3 = *(undefined ***)(*piVar7 + 4);
    if ((ppuVar3 == &PTR_FUN_68192948) ||
       ((ppuVar3 != (undefined **)0x0 && (*ppuVar3 == PTR_FUN_68192948)))) {
      puVar1 = (undefined4 *)(iVar2 + 0x248 + (((uint)piVar7 >> 3 ^ uVar5) & 0x3ff) * 8);
      puVar4 = (uint *)puVar1[1];
      if ((puVar4 != (uint *)0x0) && (((int *)*puVar1 == piVar7 && (*puVar4 == uVar5)))) {
        *param_3 = piVar7;
        *param_4 = piVar7;
        *param_5 = (uint)puVar4;
        return 1;
      }
    }
    iVar6 = (*(code *)ppuVar3[2])(param_1,piVar7,uVar5,&local_8,&param_2);
    if (iVar6 == 0) {
      return 0;
    }
    if (param_2 != 0) break;
    piVar8 = (int *)(*(uint *)(piVar7[1] + 4) & 0xfffffff8);
    if (piVar8 == (int *)0x0) {
      *param_3 = piVar7;
      *param_4 = 0;
      *param_5 = 0;
      return 1;
    }
  }
  ppuVar3 = *(undefined ***)(*local_8 + 4);
  if (((ppuVar3 == &PTR_FUN_68192948) ||
      ((ppuVar3 != (undefined **)0x0 && (*ppuVar3 == PTR_FUN_68192948)))) &&
     (*(int *)(iVar2 + 0x224c) == 0)) {
    puVar1 = (undefined4 *)(iVar2 + 0x248 + (((uint)local_8 >> 3 ^ uVar5) & 0x3ff) * 8);
    *(undefined4 *)(iVar2 + 0x2248) = 0;
    *puVar1 = local_8;
    puVar1[1] = param_2;
  }
  *param_3 = piVar7;
  *param_4 = local_8;
  *param_5 = param_2;
  return 1;
}



// ============================================================
// Function: runtime_setPropertyByName (FUN_68128260)
// Address: 68128260
// Size: 150 bytes
// Params: uint param_1, uint param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_setPropertyByName(uint param_1,uint param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *local_8;
  
  uVar4 = param_2;
  uVar2 = param_1;
  iVar3 = runtime_setPropertyEx(param_1,param_2,&param_2,&local_8,&param_1);
  if (iVar3 == 0) {
    return 0;
  }
  if (param_1 == 0) {
    if ((*(byte *)(uVar2 + 0x164) & 1) != 0) {
      if ((uVar4 & 1) == 0) {
        uVar4 = *(uint *)(uVar4 + 8);
      }
      xtra_getStringValue((uint *)(uVar4 & 0xfffffff8));
      iVar3 = xtra_invokeWithArgs(uVar2,5,xtra_getErrorString,0,0x9c);
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  else {
    pcVar1 = *(code **)(*(int *)(*local_8 + 4) + 0x34);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(uVar2,local_8,param_1);
      return param_2;
    }
  }
  return param_2;
}



// ============================================================
// Function: runtime_getPropertyValue (FUN_68128300)
// Address: 68128300
// Size: 849 bytes
// Params: uint param_1, int * param_2, uint param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPropertyValue(uint param_1,int *param_2,uint param_3,int *param_4)

{
  undefined4 *puVar1;
  char cVar2;
  ushort uVar3;
  ushort uVar4;
  char *pcVar5;
  undefined **ppuVar6;
  code *pcVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  uint *puVar11;
  undefined4 uVar12;
  int iVar13;
  uint uVar14;
  uint uVar15;
  int *piVar16;
  uint uVar17;
  ushort *puVar18;
  ushort *puVar19;
  uint *local_c;
  int *local_8;
  
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    piVar16 = (int *)(*(uint *)(param_3 + 8) & 0xfffffff8);
    puVar18 = (ushort *)piVar16[1];
    uVar9 = (uint)(*puVar18 == 0x2d);
    if (uVar9 != 0) {
      puVar18 = puVar18 + 1;
    }
    if (((*puVar18 < 0x80) && (iVar8 = isdigit((uint)*puVar18), iVar8 != 0)) &&
       (*piVar16 - uVar9 < 0xb)) {
      uVar14 = 0;
      puVar19 = puVar18 + 1;
      uVar15 = 0;
      uVar17 = *puVar18 - 0x30;
      if (uVar17 != 0) {
        uVar3 = *puVar19;
        while ((uVar3 < 0x80 && (iVar8 = isdigit((uint)uVar3), iVar8 != 0))) {
          uVar4 = *puVar19;
          uVar3 = puVar19[1];
          puVar19 = puVar19 + 1;
          uVar15 = uVar4 - 0x30;
          uVar14 = uVar17;
          uVar17 = uVar15 + uVar17 * 10;
        }
      }
      if ((*puVar19 == 0) && ((uVar14 < 0x6666666 || ((uVar14 == 0x6666666 && (uVar15 < 4)))))) {
        if (uVar9 != 0) {
          uVar17 = -uVar17;
        }
        param_3 = uVar17 * 2 | 1;
      }
    }
  }
  iVar8 = runtime_getProperty(param_1,param_2,param_3,&local_8,(uint *)&local_c);
  if (iVar8 == 0) {
    return 0;
  }
  if (local_c == (uint *)0x0) {
    *param_4 = -0x7fffffff;
    uVar9 = param_3;
    if ((param_3 & 1) == 0) {
      uVar9 = *(uint *)(param_3 + 8);
    }
    iVar8 = (**(code **)((*(uint *)(param_2[1] + 8) & 0xfffffffe) + 0x10))
                      (param_1,param_2,uVar9,param_4);
    if (iVar8 == 0) {
      return 0;
    }
    if ((*(byte *)(param_1 + 0x164) & 1) == 0) {
      return 1;
    }
    if (*param_4 != -0x7fffffff) {
      return 1;
    }
    if (*(int *)(param_1 + 0x34) == 0) {
      return 1;
    }
    pcVar5 = *(char **)(*(int *)(param_1 + 0x34) + 0x38);
    if (pcVar5 == (char *)0x0) {
      return 1;
    }
    cVar2 = *pcVar5;
    if ((cVar2 != '5') && (cVar2 != '7')) {
      return 1;
    }
    pbVar10 = *(byte **)(*(int *)(param_1 + 0x34) + 0x38);
    piVar16 = *(int **)(*(int *)(param_1 + 0x34) + 0xc);
    for (pbVar10 = pbVar10 + (char)(&DAT_68193cb8)[(uint)*pbVar10 * 0x10];
        pbVar10 < (byte *)(piVar16[1] + *piVar16); pbVar10 = pbVar10 + 1) {
      if (*pbVar10 == 0x27) {
        return 1;
      }
      if (*pbVar10 != 0x83) break;
    }
    if ((param_3 & 1) == 0) {
      param_3 = *(undefined4 *)(param_3 + 8);
    }
    puVar11 = crypto_decompileExpr(param_1,(int *)0x0,(undefined **)param_3,(uint *)0x0);
    if (puVar11 == (uint *)0x0) {
      return 0;
    }
    xtra_getStringValue(puVar11);
    iVar8 = xtra_invokeWithArgs(param_1,5,xtra_getErrorString,0,0xa2);
    if (iVar8 == 0) {
      return 0;
    }
    return 1;
  }
  iVar8 = *local_8;
  ppuVar6 = *(undefined ***)(iVar8 + 4);
  if ((ppuVar6 != &PTR_FUN_68192948) &&
     ((ppuVar6 == (undefined **)0x0 || (*ppuVar6 != PTR_FUN_68192948)))) {
    if ((code *)ppuVar6[0xd] != (code *)0x0) {
      (*(code *)ppuVar6[0xd])(param_1,local_8,local_c);
    }
    uVar12 = (**(code **)(*(int *)(*local_8 + 4) + 0x10))(param_1,local_8,param_3,param_4);
    return uVar12;
  }
  uVar9 = local_c[3];
  if (uVar9 == 0xffffffff) {
    iVar13 = -0x7fffffff;
  }
  else {
    iVar13 = *(int *)(local_8[1] + uVar9 * 4);
  }
  *param_4 = iVar13;
  if ((local_c[4] & 0x10) == 0) {
    if (local_c[1] == 0) goto LAB_68128598;
    if ((*(byte *)((int)local_c + 0x11) & 8) == 0) {
      uVar14 = *local_c;
      if ((uVar14 & 1) == 0) {
        uVar14 = *(uint *)(uVar14 + 8);
      }
    }
    else {
      uVar14 = *(short *)((int)local_c + 0x12) * 2 | 1;
    }
    pcVar7 = *(code **)(*(int *)(*param_2 + 4) + 0x30);
    if (pcVar7 != (code *)0x0) {
      param_2 = (int *)(*pcVar7)(param_1,param_2);
    }
    iVar13 = (*(code *)local_c[1])(param_1,param_2,uVar14,param_4);
  }
  else {
    iVar13 = certs_processKeyUsage(param_1,param_2,*local_c,local_c[1],4,0,0,param_4);
  }
  if (iVar13 == 0) {
    return 0;
  }
LAB_68128598:
  if (local_c[3] < *(uint *)(iVar8 + 0xc)) {
    *(int *)(local_8[1] + uVar9 * 4) = *param_4;
    iVar8 = *(int *)(param_1 + 0x14);
    if (*(int *)(iVar8 + 0x224c) == 0) {
      puVar1 = (undefined4 *)(iVar8 + 0x248 + (((uint)local_8 >> 3 ^ param_3) & 0x3ff) * 8);
      *(undefined4 *)(iVar8 + 0x2248) = 0;
      *puVar1 = local_8;
      puVar1[1] = local_c;
    }
  }
  return 1;
}



// ============================================================
// Function: runtime_getPropertyEx (FUN_68128660)
// Address: 68128660
// Size: 1194 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPropertyEx(uint param_1,int *param_2,uint param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  ushort uVar2;
  undefined **ppuVar3;
  code *pcVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  uint *puVar9;
  uint uVar10;
  int *piVar11;
  uint uVar12;
  uint uVar13;
  ushort *puVar14;
  undefined *local_1c;
  undefined *local_18;
  uint local_14;
  uint local_10;
  int *local_c;
  uint *local_8;
  
  piVar5 = param_2;
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    piVar11 = (int *)(*(uint *)(param_3 + 8) & 0xfffffff8);
    puVar14 = (ushort *)piVar11[1];
    uVar13 = (uint)(*puVar14 == 0x2d);
    if (uVar13 != 0) {
      puVar14 = puVar14 + 1;
    }
    if (((*puVar14 < 0x80) && (iVar7 = isdigit((uint)*puVar14), iVar7 != 0)) &&
       (*piVar11 - uVar13 < 0xb)) {
      uVar10 = 0;
      uVar12 = *puVar14 - 0x30;
      puVar14 = puVar14 + 1;
      local_10 = 0;
      if (uVar12 != 0) {
        uVar2 = *puVar14;
        uVar6 = uVar12;
        while ((uVar12 = uVar6, uVar2 < 0x80 && (iVar7 = isdigit((uint)uVar2), iVar7 != 0))) {
          uVar10 = *puVar14 - 0x30;
          puVar14 = puVar14 + 1;
          uVar2 = *puVar14;
          uVar6 = uVar10 + uVar12 * 10;
          local_10 = uVar12;
        }
      }
      if ((*puVar14 == 0) && ((local_10 < 0x6666666 || ((local_10 == 0x6666666 && (uVar10 < 4))))))
      {
        if (uVar13 != 0) {
          uVar12 = -uVar12;
        }
        param_3 = uVar12 * 2 | 1;
      }
    }
  }
  iVar7 = runtime_getProperty(param_1,param_2,param_3,&local_c,(uint *)&local_8);
  if (iVar7 == 0) {
    return 0;
  }
  if (((local_8 != (uint *)0x0) &&
      (ppuVar3 = *(undefined ***)(*local_c + 4), ppuVar3 != &PTR_FUN_68192948)) &&
     ((ppuVar3 == (undefined **)0x0 || (*ppuVar3 != PTR_FUN_68192948)))) {
    if ((code *)ppuVar3[0xd] != (code *)0x0) {
      (*(code *)ppuVar3[0xd])(param_1,local_c,local_8);
    }
    local_8 = (uint *)0x0;
  }
  uVar13 = *(uint *)(param_2[1] + 8) & 0xfffffffe;
  local_1c = *(undefined **)(uVar13 + 0x10);
  local_18 = *(undefined **)(uVar13 + 0x14);
  local_14 = 0;
  local_10 = 0;
  if (local_8 == (uint *)0x0) {
LAB_681288cc:
    uVar10 = 1;
    if ((*(byte *)(*param_2 + 0x14) & 2) != 0) {
LAB_681288d4:
      if ((param_3 & 1) == 0) {
        param_3 = *(undefined4 *)(param_3 + 8);
      }
      puVar9 = crypto_decompileExpr(param_1,(int *)0x0,(undefined **)param_3,(uint *)0x0);
      if (puVar9 != (uint *)0x0) {
        xtra_getStringValue(puVar9);
        xtra_invokeMethod(param_1,xtra_getErrorString,0,0x13);
      }
      return 0;
    }
    piVar11 = strings_getTableEntry(param_1,param_2);
    if (piVar11 == (int *)0x0) {
      return 0;
    }
    if ((*(byte *)(uVar13 + 4) & 0x10) != 0) {
      uVar10 = 0x41;
    }
    local_8 = (uint *)strings_createTableEntry(param_1,(int)piVar11,param_3,local_1c,local_18,-1,uVar10,local_14
                                   ,local_10);
    if (local_8 == (uint *)0x0) {
      return 0;
    }
    if ((*(byte *)((int)local_8 + 0x11) & 8) == 0) {
      uVar10 = *local_8;
      if ((uVar10 & 1) == 0) {
        uVar10 = *(uint *)(uVar10 + 8);
      }
    }
    else {
      uVar10 = *(short *)((int)local_8 + 0x12) * 2 | 1;
    }
    iVar7 = (**(code **)(uVar13 + 8))(param_1,param_2,uVar10,param_4);
    if (iVar7 == 0) {
      strings_setTableValue(param_1,(int)piVar11,param_3);
      return 0;
    }
    if (local_8[3] < (uint)piVar11[3]) {
      *(undefined4 *)(param_2[1] + local_8[3] * 4) = 0x80000001;
    }
    iVar7 = *(int *)(param_1 + 0x14);
    if (*(int *)(iVar7 + 0x224c) == 0) {
      puVar1 = (undefined4 *)(iVar7 + 0x248 + (((uint)param_2 >> 3 ^ param_3) & 0x3ff) * 8);
      *(undefined4 *)(iVar7 + 0x2248) = 0;
      *puVar1 = param_2;
      puVar1[1] = local_8;
    }
  }
  else {
    uVar10 = local_8[4];
    if (((uVar10 & 2) != 0) || ((*(byte *)((int *)*local_c + 5) & 2) != 0)) {
      if ((uVar10 & 2) != 0) {
        if (*(int *)(param_1 + 0xc) == 0) {
          return 1;
        }
        if (0x81 < *(int *)(param_1 + 0xc)) {
          return 1;
        }
      }
      goto LAB_681288d4;
    }
    piVar11 = (int *)*local_c;
    if (local_c != param_2) {
      if ((uVar10 & 0x40) != 0) {
        if ((uVar10 & 0x20) != 0) {
          uVar8 = certs_processKeyUsage(param_1,param_2,*local_8,local_8[2],8,1,param_4,param_4);
          return uVar8;
        }
        if ((uVar10 & 0x10) != 0) {
          xtra_invokeMethod(param_1,xtra_getErrorString,0,0xa0);
          return 0;
        }
        if (local_8[2] == 0) {
          return 1;
        }
        if ((*(byte *)((int)local_8 + 0x11) & 8) == 0) {
          uVar13 = *local_8;
          if ((uVar13 & 1) == 0) {
            uVar13 = *(uint *)(uVar13 + 8);
          }
        }
        else {
          uVar13 = *(short *)((int)local_8 + 0x12) * 2 | 1;
        }
        pcVar4 = *(code **)(*(int *)(*param_2 + 4) + 0x30);
        if (pcVar4 != (code *)0x0) {
          param_2 = (int *)(*pcVar4)(param_1,param_2);
        }
        iVar7 = (*(code *)local_8[2])(param_1,param_2,uVar13,param_4);
        if (iVar7 != 0) {
          return 1;
        }
        return 0;
      }
      if ((*(byte *)((int)local_8 + 0x11) & 8) != 0) {
        local_10 = (uint)*(short *)((int)local_8 + 0x12);
        local_1c = (undefined *)local_8[1];
        local_18 = (undefined *)local_8[2];
        local_14 = 8;
      }
      local_8 = (uint *)0x0;
      goto LAB_681288cc;
    }
  }
  param_2 = piVar11;
  uVar13 = local_8[3];
  if ((uVar13 != 0xffffffff) && (local_8[2] == 0)) goto LAB_68128ae7;
  if ((local_8[4] & 0x20) == 0) {
    if ((local_8[4] & 0x10) != 0) {
      xtra_invokeMethod(param_1,xtra_getErrorString,0,0xa0);
      return 0;
    }
    if (local_8[2] != 0) {
      if ((*(byte *)((int)local_8 + 0x11) & 8) == 0) {
        uVar10 = *local_8;
        if ((uVar10 & 1) == 0) {
          uVar10 = *(uint *)(uVar10 + 8);
        }
      }
      else {
        uVar10 = *(short *)((int)local_8 + 0x12) * 2 | 1;
      }
      pcVar4 = *(code **)(*(int *)(*piVar5 + 4) + 0x30);
      piVar11 = piVar5;
      if (pcVar4 != (code *)0x0) {
        piVar11 = (int *)(*pcVar4)(param_1,piVar5);
      }
      iVar7 = (*(code *)local_8[2])(param_1,piVar11,uVar10,param_4);
      goto LAB_68128ad1;
    }
  }
  else {
    iVar7 = certs_processKeyUsage(param_1,piVar5,*local_8,local_8[2],8,1,param_4,param_4);
LAB_68128ad1:
    if (iVar7 == 0) {
      return 0;
    }
  }
  if ((uint)param_2[3] <= local_8[3]) {
    return 1;
  }
LAB_68128ae7:
  *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x60) = 1;
  *(undefined4 *)(piVar5[1] + uVar13 * 4) = *param_4;
  return 1;
}



// ============================================================
// Function: runtime_getPropertyAndCheck (FUN_68128b10)
// Address: 68128b10
// Size: 222 bytes
// Params: uint param_1, int * param_2, uint param_3, uint param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPropertyAndCheck(uint param_1,int *param_2,uint param_3,uint param_4,uint *param_5)

{
  undefined **ppuVar1;
  code *pcVar2;
  uint uVar3;
  int iVar4;
  undefined4 uVar5;
  bool bVar6;
  
  uVar3 = param_3;
  bVar6 = param_4 == 0;
  if (bVar6) {
    iVar4 = runtime_getProperty(param_1,param_2,param_3,&param_2,&param_4);
    if (iVar4 == 0) {
      return 0;
    }
    if (param_4 == 0) {
      *param_5 = 0;
      return 1;
    }
    ppuVar1 = *(undefined ***)(*param_2 + 4);
    if ((ppuVar1 != &PTR_FUN_68192948) &&
       ((ppuVar1 == (undefined **)0x0 || (*ppuVar1 != PTR_FUN_68192948)))) {
      uVar5 = (*(code *)ppuVar1[6])(param_1,param_2,uVar3,param_4,param_5);
      pcVar2 = *(code **)(*(int *)(*param_2 + 4) + 0x34);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(param_1,param_2,param_4);
      }
      return uVar5;
    }
  }
  *param_5 = (uint)*(byte *)(param_4 + 0x10);
  if ((bVar6) && (pcVar2 = *(code **)(*(int *)(*param_2 + 4) + 0x34), pcVar2 != (code *)0x0)) {
    (*pcVar2)(param_1,param_2,param_4);
  }
  return 1;
}



// ============================================================
// Function: runtime_getPropertyWithFlags (FUN_68128bf0)
// Address: 68128bf0
// Size: 234 bytes
// Params: uint param_1, int * param_2, uint param_3, uint * param_4, uint * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_getPropertyWithFlags(uint param_1,int *param_2,uint param_3,uint *param_4,uint *param_5)

{
  undefined **ppuVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  
  bVar5 = param_4 == (uint *)0x0;
  if (bVar5) {
    iVar3 = runtime_getProperty(param_1,param_2,param_3,&param_2,(uint *)&param_4);
    if (iVar3 == 0) {
      return 0;
    }
    if (param_4 == (uint *)0x0) {
      return 1;
    }
    ppuVar1 = *(undefined ***)(*param_2 + 4);
    if ((ppuVar1 != &PTR_FUN_68192948) &&
       ((ppuVar1 == (undefined **)0x0 || (*ppuVar1 != PTR_FUN_68192948)))) {
      uVar4 = (*(code *)ppuVar1[7])(param_1,param_2,param_3,param_4,param_5);
      pcVar2 = *(code **)(*(int *)(*param_2 + 4) + 0x34);
      if (pcVar2 != (code *)0x0) {
        (*pcVar2)(param_1,param_2,param_4);
      }
      return uVar4;
    }
  }
  iVar3 = runtime_setPropertyValue(param_1,param_2,param_4,*param_5 & 0xffffffcf,0,(undefined *)param_4[1],
                       (undefined *)param_4[2]);
  if ((bVar5) && (pcVar2 = *(code **)(*(int *)(*param_2 + 4) + 0x34), pcVar2 != (code *)0x0)) {
    (*pcVar2)(param_1,param_2,param_4);
  }
  return (uint)(iVar3 != 0);
}



// ============================================================
// Function: runtime_getPropertyDetailed (FUN_68128ce0)
// Address: 68128ce0
// Size: 766 bytes
// Params: uint param_1, int * param_2, undefined * * param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPropertyDetailed(uint param_1,int *param_2,undefined **param_3,int *param_4)

{
  undefined4 *puVar1;
  ushort uVar2;
  ushort uVar3;
  undefined *puVar4;
  code *pcVar5;
  int iVar6;
  undefined **ppuVar7;
  uint uVar8;
  int iVar9;
  uint *puVar10;
  undefined4 uVar11;
  uint uVar12;
  uint uVar13;
  ushort *puVar14;
  ushort *puVar15;
  int *local_18;
  undefined4 local_14;
  uint local_10;
  uint local_c;
  uint *local_8;
  
  if ((*(int *)(param_1 + 0xc) == 0) || (iVar9 = -0x7fffffff, 0x81 < *(int *)(param_1 + 0xc))) {
    iVar9 = 0xe;
  }
  *param_4 = iVar9;
  if ((((uint)param_3 & 1) == 0) || (param_3 == (undefined **)0x80000001)) {
    puVar4 = param_3[2];
    puVar14 = (ushort *)((int *)((uint)puVar4 & 0xfffffff8))[1];
    uVar12 = (uint)(*puVar14 == 0x2d);
    if (uVar12 != 0) {
      puVar14 = puVar14 + 1;
    }
    local_10 = uVar12;
    if (((*puVar14 < 0x80) && (iVar9 = isdigit((uint)*puVar14), iVar9 != 0)) &&
       (*(int *)((uint)puVar4 & 0xfffffff8) - uVar12 < 0xb)) {
      puVar15 = puVar14 + 1;
      uVar12 = 0;
      uVar13 = *puVar14 - 0x30;
      local_c = 0;
      if (uVar13 != 0) {
        uVar2 = *puVar15;
        uVar8 = uVar13;
        while ((uVar13 = uVar8, uVar2 < 0x80 && (iVar9 = isdigit((uint)uVar2), iVar9 != 0))) {
          uVar3 = *puVar15;
          uVar2 = puVar15[1];
          puVar15 = puVar15 + 1;
          uVar12 = uVar3 - 0x30;
          uVar8 = uVar12 + uVar13 * 10;
          local_c = uVar13;
        }
      }
      if ((*puVar15 == 0) && ((local_c < 0x6666666 || ((local_c == 0x6666666 && (uVar12 < 4)))))) {
        if (local_10 != 0) {
          uVar13 = -uVar13;
        }
        param_3 = (undefined **)(uVar13 * 2 | 1);
      }
    }
  }
  iVar9 = runtime_getProperty(param_1,param_2,(uint)param_3,&local_18,(uint *)&local_8);
  puVar10 = local_8;
  if (iVar9 == 0) {
    return 0;
  }
  if (local_8 == (uint *)0x0) {
LAB_68128fb3:
    if (((uint)param_3 & 1) == 0) {
      param_3 = (undefined **)param_3[2];
    }
    uVar11 = (**(code **)((*(uint *)(param_2[1] + 8) & 0xfffffffe) + 0xc))
                       (param_1,param_2,param_3,param_4);
    return uVar11;
  }
  if (local_18 == param_2) {
    if ((local_8[4] & 4) == 0) {
      if ((*(byte *)((int)local_8 + 0x11) & 8) == 0) {
        uVar12 = *local_8;
        if ((uVar12 & 1) == 0) {
          uVar12 = *(uint *)(uVar12 + 8);
        }
      }
      else {
        uVar12 = *(short *)((int)local_8 + 0x12) * 2 | 1;
      }
      iVar9 = (**(code **)((*(uint *)(param_2[1] + 8) & 0xfffffffe) + 0xc))
                        (param_1,param_2,uVar12,param_4);
      if (iVar9 != 0) {
        iVar9 = *param_2;
        if (puVar10[3] < *(uint *)(iVar9 + 0xc)) {
          *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x60) = 1;
        }
        iVar6 = *(int *)(param_1 + 0x14);
        if (*(int *)(iVar6 + 0x224c) == 0) {
          uVar12 = ((uint)param_2 >> 3 ^ (uint)param_3) & 0x3ff;
          local_14 = *(undefined4 *)(iVar6 + 0x248 + uVar12 * 8);
          puVar1 = (undefined4 *)(iVar6 + 0x248 + uVar12 * 8);
          local_10 = puVar1[1];
          *(undefined4 *)(iVar6 + 0x2248) = 0;
          *puVar1 = param_2;
          puVar1[1] = 0;
        }
        uVar11 = strings_setTableValue(param_1,iVar9,(uint)param_3);
        pcVar5 = *(code **)(*(int *)(*param_2 + 4) + 0x34);
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)(param_1,param_2,local_8);
        }
        return uVar11;
      }
      pcVar5 = *(code **)(*(int *)(*param_2 + 4) + 0x34);
      if (pcVar5 != (code *)0x0) {
        (*pcVar5)(param_1,param_2,local_8);
      }
      return 0;
    }
    pcVar5 = *(code **)(*(int *)(*param_2 + 4) + 0x34);
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)(param_1,param_2,local_8);
    }
    if ((*(int *)(param_1 + 0xc) != 0) && (*(int *)(param_1 + 0xc) < 0x82)) {
      if (((uint)param_3 & 1) == 0) {
        param_3 = (undefined **)param_3[2];
      }
      puVar10 = crypto_decompileExpr(param_1,(int *)0x0,param_3,(uint *)0x0);
      if (puVar10 == (uint *)0x0) {
        return 0;
      }
      xtra_getStringValue(puVar10);
      xtra_invokeMethod(param_1,xtra_getErrorString,0,0x25);
      return 0;
    }
    *param_4 = 6;
  }
  else {
    ppuVar7 = *(undefined ***)(*local_18 + 4);
    if (((ppuVar7 == &PTR_FUN_68192948) ||
        ((ppuVar7 != (undefined **)0x0 && (*ppuVar7 == PTR_FUN_68192948)))) &&
       ((~(byte)local_8[4] & 0x44) == 0)) {
      *param_4 = 6;
    }
    pcVar5 = *(code **)(*(int *)(*local_18 + 4) + 0x34);
    if (pcVar5 != (code *)0x0) {
      (*pcVar5)(param_1,local_18,local_8);
    }
    if (*param_4 != 6) goto LAB_68128fb3;
  }
  return 1;
}



// ============================================================
// Function: runtime_allocPropertySlots (FUN_68128fe0)
// Address: 68128fe0
// Size: 35 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_allocPropertySlots(int param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = (int *)xtra_getPropertyById(param_1,param_2 * 4 + 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_2;
  }
  return 0;
}



// ============================================================
// Function: runtime_resizePropertySlots (FUN_68129010)
// Address: 68129010
// Size: 39 bytes
// Params: int param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_resizePropertySlots(int param_1,int param_2,int param_3)
{
  int *piVar1;
  
  piVar1 = (int *)xtra_allocJSString(param_1,param_2,param_3 * 4 + 4);
  if (piVar1 != (int *)0x0) {
    *piVar1 = param_3;
  }
  return 0;
}



// ============================================================
// Function: runtime_accessPropertySlot (FUN_68129040)
// Address: 68129040
// Size: 448 bytes
// Params: int param_1, int * param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_accessPropertySlot(int param_1,int *param_2,int param_3,uint *param_4,uint *param_5)

{
  code *pcVar1;
  uint uVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  uint *puVar7;
  undefined4 *puVar8;
  uint *puVar9;
  uint *puVar10;
  
  uVar2 = *(uint *)(param_2[1] + 8) & 0xfffffffe;
  pcVar1 = *(code **)(uVar2 + 0x18);
  if ((*(byte *)(uVar2 + 4) & 2) != 0) {
    uVar3 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5);
    return uVar3;
  }
  if (param_3 != 0) {
    if (param_3 == 1) {
      piVar4 = (int *)(*param_4 & 0xfffffffe);
      if (*piVar4 != *(int *)piVar4[1]) {
        *param_5 = ((int *)piVar4[1])[*piVar4 + 1];
        *piVar4 = *piVar4 + 1;
        return 1;
      }
    }
    else if (param_3 != 2) {
      return 0;
    }
    uVar2 = *param_4;
    xtra_flushAndCheck(param_1,*(int *)((uVar2 & 0xfffffffe) + 4));
    xtra_checkAndFlush(param_1,uVar2 & 0xfffffffe);
    *param_4 = 0;
    return 1;
  }
  iVar5 = (*pcVar1)(param_1,param_2);
  if (iVar5 != 0) {
    iVar5 = *param_2;
    param_3 = 0;
    if (((int *)(*(uint *)param_2[1] & 0xfffffff8) == (int *)0x0) ||
       (iVar5 != *(int *)(*(uint *)param_2[1] & 0xfffffff8))) {
      puVar9 = *(uint **)(iVar5 + 0x24);
      for (puVar10 = puVar9; puVar10 != (uint *)0x0; puVar10 = (uint *)puVar10[5]) {
        if ((((puVar10[4] & 1) != 0) && ((*(byte *)((int)puVar10 + 0x11) & 4) == 0)) &&
           (((*(byte *)(iVar5 + 0x14) & 1) == 0 ||
            (puVar7 = strings_lookupInTable(iVar5,*puVar10,0), (uint *)(*puVar7 & 0xfffffffe) == puVar10))))
        {
          param_3 = param_3 + 1;
        }
      }
      iVar6 = runtime_allocPropertySlots(param_1,param_3);
      if (iVar6 == 0) goto LAB_681291bf;
      if (puVar9 != (uint *)0x0) {
        puVar10 = (uint *)(iVar6 + 4 + param_3 * 4);
        do {
          if ((((puVar9[4] & 1) != 0) && ((*(byte *)((int)puVar9 + 0x11) & 4) == 0)) &&
             (((*(byte *)(iVar5 + 0x14) & 1) == 0 ||
              (puVar7 = strings_lookupInTable(iVar5,*puVar9,0), (uint *)(*puVar7 & 0xfffffffe) == puVar9))))
          {
            puVar10 = puVar10 + -1;
            *puVar10 = *puVar9;
          }
          puVar9 = (uint *)puVar9[5];
        } while (puVar9 != (uint *)0x0);
      }
    }
    else {
      iVar6 = runtime_allocPropertySlots(param_1,0);
      if (iVar6 == 0) goto LAB_681291bf;
    }
    puVar8 = (undefined4 *)xtra_getPropertyById(param_1,8);
    if (puVar8 != (undefined4 *)0x0) {
      puVar8[1] = iVar6;
      *puVar8 = 0;
      *param_4 = (uint)puVar8 | 1;
      if (param_5 != (uint *)0x0) {
        *param_5 = param_3 * 2 | 1;
      }
      return 1;
    }
    xtra_flushAndCheck(param_1,iVar6);
  }
LAB_681291bf:
  *param_4 = 0;
  return 0;
}



// ============================================================
// Function: runtime_invokePropertyGetter (FUN_68129200)
// Address: 68129200
// Size: 334 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 param_4, undefined4 * param_5, uint * param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_invokePropertyGetter(uint param_1,int *param_2,uint param_3,undefined4 param_4,undefined4 *param_5,
            uint *param_6)

{
  code *pcVar1;
  undefined **ppuVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  uint uVar6;
  uint local_8;
  
  piVar3 = param_2;
  iVar4 = runtime_getProperty(param_1,param_2,param_3,&param_2,&local_8);
  if (iVar4 == 0) {
    return 0;
  }
  if (local_8 != 0) {
    ppuVar2 = *(undefined ***)(*param_2 + 4);
    if ((ppuVar2 != &PTR_FUN_68192948) &&
       ((ppuVar2 == (undefined **)0x0 || (*ppuVar2 != PTR_FUN_68192948)))) {
      if ((code *)ppuVar2[0xd] != (code *)0x0) {
        (*(code *)ppuVar2[0xd])(param_1,param_2,local_8);
      }
      uVar5 = (**(code **)(*(int *)(*param_2 + 4) + 0x2c))
                        (param_1,param_2,param_3,param_4,param_5,param_6);
      return uVar5;
    }
    if (*(uint *)(local_8 + 0xc) < *(uint *)(*param_2 + 0xc)) {
      uVar5 = *(undefined4 *)(param_2[1] + *(uint *)(local_8 + 0xc) * 4);
    }
    else {
      uVar5 = 0x80000001;
    }
    *param_5 = uVar5;
    *param_6 = (uint)*(byte *)(local_8 + 0x10);
    pcVar1 = *(code **)((*(uint *)(piVar3[1] + 8) & 0xfffffffe) + 0x2c);
    if (pcVar1 == (code *)0x0) {
      uVar5 = 1;
    }
    else {
      uVar6 = param_3;
      if ((param_3 & 1) == 0) {
        uVar6 = *(uint *)(param_3 + 8);
      }
      uVar5 = (*pcVar1)(param_1,piVar3,uVar6,param_4,param_5);
    }
    pcVar1 = *(code **)(*(int *)(*param_2 + 4) + 0x34);
    if (pcVar1 != (code *)0x0) {
      (*pcVar1)(param_1,param_2,local_8);
    }
    return uVar5;
  }
  *param_5 = 0x80000001;
  *param_6 = 0;
  pcVar1 = *(code **)((*(uint *)(piVar3[1] + 8) & 0xfffffffe) + 0x2c);
  if (pcVar1 != (code *)0x0) {
    uVar6 = param_3;
    if ((param_3 & 1) == 0) {
      uVar6 = *(uint *)(param_3 + 8);
    }
    iVar4 = (*pcVar1)(param_1,piVar3,uVar6,param_4,param_5);
    if (iVar4 == 0) {
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: runtime_callObjectMethodByIndex (FUN_68129350)
// Address: 68129350
// Size: 75 bytes
// Params: undefined4 param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall runtime_callObjectMethodByIndex(undefined4 param_1,int param_2,uint *param_3)
{
  int iVar1;
  int unaff_EDI;
  
  iVar1 = *(int *)(unaff_EDI + 0x34);
  if (*(int *)(iVar1 + 0x2c) != 0) {
    *(undefined4 *)(iVar1 + 0x50) = *(undefined4 *)(unaff_EDI + 0x150);
    *(int *)(unaff_EDI + 0x150) = iVar1;
    *(undefined4 *)(unaff_EDI + 0x34) = *(undefined4 *)(iVar1 + 0x2c);
  }
  runtime_callObjectMethod(unaff_EDI,param_3,param_2);
  if (*(int *)(iVar1 + 0x2c) != 0) {
    *(undefined4 *)(unaff_EDI + 0x150) = *(undefined4 *)(iVar1 + 0x50);
    *(undefined4 *)(iVar1 + 0x50) = 0;
    *(int *)(unaff_EDI + 0x34) = iVar1;
  }
  return 0;
}



// ============================================================
// Function: runtime_callObjectMethodApply (FUN_681293a0)
// Address: 681293a0
// Size: 73 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_callObjectMethodApply(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            )

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = *(code **)((*(uint *)(*(int *)((*(uint *)(param_4 + -8) & 0xfffffff8) + 4) + 8) &
                      0xfffffffe) + 0x30);
  if (pcVar1 == (code *)0x0) {
    runtime_callObjectMethodByIndex(param_4 + -8,0,(uint *)(param_4 + -8));
    return 0;
  }
  uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5);
  return uVar2;
}



// ============================================================
// Function: runtime_callObjectMethodCall (FUN_681293f0)
// Address: 681293f0
// Size: 74 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, int param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_callObjectMethodCall(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4,undefined4 param_5
            )

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = *(code **)((*(uint *)(*(int *)((*(uint *)(param_4 + -8) & 0xfffffff8) + 4) + 8) &
                      0xfffffffe) + 0x34);
  if (pcVar1 == (code *)0x0) {
    runtime_callObjectMethodByIndex(param_4 + -8,1,(uint *)(param_4 + -8));
    return 0;
  }
  uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4,param_5);
  return uVar2;
}



// ============================================================
// Function: runtime_resolvePropertyValue (FUN_68129440)
// Address: 68129440
// Size: 56 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_resolvePropertyValue(undefined4 param_1,int param_2,undefined4 param_3,undefined4 *param_4)

{
  code *pcVar1;
  undefined4 uVar2;
  
  pcVar1 = *(code **)((*(uint *)(*(int *)(param_2 + 4) + 8) & 0xfffffffe) + 0x3c);
  if (pcVar1 != (code *)0x0) {
    uVar2 = (*pcVar1)(param_1,param_2,param_3,param_4);
    return uVar2;
  }
  *param_4 = 0;
  return 1;
}



// ============================================================
// Function: runtime_resolvePropertyByAtom (FUN_68129480)
// Address: 68129480
// Size: 77 bytes
// Params: undefined4 param_1, uint param_2, uint param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_resolvePropertyByAtom(undefined4 param_1,uint param_2,uint param_3,undefined4 *param_4)

{
  uint uVar1;
  
  *param_4 = 0;
  if ((((param_3 & 7) == 0) && (param_3 != 0)) &&
     (uVar1 = **(uint **)((param_3 & 0xfffffff8) + 4) & 0xfffffff8, uVar1 != 0)) {
    while (uVar1 != param_2) {
      uVar1 = **(uint **)(uVar1 + 4) & 0xfffffff8;
      if (uVar1 == 0) {
        return 1;
      }
    }
    *param_4 = 1;
  }
  return 1;
}



// ============================================================
// Function: runtime_resolvePropertyByString (FUN_681294d0)
// Address: 681294d0
// Size: 137 bytes
// Params: undefined4 param_1, char * param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall runtime_resolvePropertyByString(undefined4 param_1,char *param_2,uint param_3,uint *param_4)

{
  int iVar1;
  
  iVar1 = runtime_registerAtomFromString(param_1,param_2,&param_3);
  if (iVar1 == 0) {
    return 0;
  }
  if ((param_3 & 7) == 0) {
    if ((((param_3 & 0xfffffff8) != 0) &&
        ((undefined **)(*(uint *)(((int *)(param_3 & 0xfffffff8))[1] + 8) & 0xfffffffe) ==
         &PTR_s_Function_681928b8)) &&
       (iVar1 = (**(code **)(*(int *)(*(int *)(param_3 & 0xfffffff8) + 4) + 0x10))(), iVar1 == 0)) {
      return 0;
    }
    if ((param_3 & 7) == 0) {
      *param_4 = param_3 & 0xfffffff8;
      return 1;
    }
  }
  *param_4 = 0;
  return 1;
}



// ============================================================
// Function: runtime_copyPropertyDescriptor (FUN_68129560)
// Address: 68129560
// Size: 97 bytes
// Params: int param_1, int * param_2, int * param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_copyPropertyDescriptor(int param_1,int *param_2,int *param_3,undefined4 param_4)
{
  int iVar1;
  
  iVar1 = (**(code **)(*(int *)(*param_2 + 4) + 0xc))
                    (param_1,param_2,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xe8),param_3,0,0,
                     param_4,0);
  if (iVar1 == 0) {
    return 0;
  }
  (**(code **)(*(int *)(*param_3 + 4) + 0xc))
            (param_1,param_3,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xec),param_2,0,0,0,0);
  return 0;
}



// ============================================================
// Function: runtime_deleteProperty (FUN_681295d0)
// Address: 681295d0
// Size: 224 bytes
// Params: uint param_1, uint param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_deleteProperty(uint param_1,uint param_2,uint *param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  
  if ((param_2 == 0) || (param_2 == 0x80000001)) {
    piVar1 = (int *)0x0;
  }
  else {
    uVar3 = param_2 & 7;
    if (uVar3 == 0) {
      piVar1 = (int *)(param_2 & 0xfffffff8);
      iVar2 = (**(code **)(*(int *)(*piVar1 + 4) + 0x24))(param_1,piVar1,1,&param_2);
      if (iVar2 == 0) {
        return 0;
      }
      if ((param_2 & 7) == 0) {
        *param_3 = param_2 & 0xfffffff8;
        return 1;
      }
    }
    else {
      if (uVar3 == 4) {
        piVar1 = certificates_createStringObject(param_1,param_2 & 0xfffffff8);
      }
      else if ((param_2 & 1) == 0) {
        if (uVar3 == 2) {
          piVar1 = runtime_createNumberObject(param_1,*(undefined8 *)(param_2 & 0xfffffff8));
        }
        else {
          piVar1 = (int *)javascript_numberGetDefaultValue(param_1,(int)param_2 >> 3);
        }
      }
      else {
        piVar1 = runtime_createNumberObject(param_1,(double)((int)param_2 >> 1));
      }
      if (piVar1 == (int *)0x0) {
        return 0;
      }
    }
  }
  *param_3 = (uint)piVar1;
  return 1;
}



// ============================================================
// Function: runtime_hasProperty (FUN_681296b0)
// Address: 681296b0
// Size: 87 bytes
// Params: uint param_1, uint param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_hasProperty(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *puVar4;
  
  uVar1 = param_2;
  iVar3 = runtime_deleteProperty(param_1,param_2,&param_2);
  uVar2 = param_2;
  if (iVar3 == 0) {
    return 0;
  }
  if (param_2 == 0) {
    puVar4 = crypto_decompileExpr(param_1,(int *)0x1,(undefined **)uVar1,(uint *)0x0);
    if (puVar4 != (uint *)0x0) {
      xtra_getStringValue(puVar4);
      xtra_invokeMethod(param_1,xtra_getErrorString,0,0x27);
    }
  }
  return uVar2;
}



// ============================================================
// Function: runtime_defineProperty (FUN_68129710)
// Address: 68129710
// Size: 118 bytes
// Params: uint param_1, int * param_2, undefined4 param_3, uint param_4, int param_5, int * param_6
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_defineProperty(uint param_1,int *param_2,undefined4 param_3,uint param_4,int param_5,int *param_6
                 )

{
  uint uVar1;
  int *piVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar1 = param_1;
  uVar3 = xtra_setPropertyDirect(param_1,0);
  piVar2 = param_2;
  iVar4 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))(uVar1,param_2,param_3,&param_1);
  if (((iVar4 != 0) && ((param_1 & 7) == 0)) && (param_1 != 0)) {
    uVar5 = certs_validateExtension(uVar1,(int)piVar2,param_1,0,param_4,param_5,param_6);
    xtra_setPropertyDirect(uVar1,uVar3);
    return uVar5;
  }
  xtra_setPropertyDirect(uVar1,uVar3);
  return 1;
}



// ============================================================
// Function: runtime_removePropertyAtom (FUN_68129790)
// Address: 68129790
// Size: 201 bytes
// Params: undefined4 param_1, int * param_2, undefined4 param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_removePropertyAtom(undefined4 param_1,int *param_2,undefined4 param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  code *pcVar4;
  uint *puVar5;
  uint uVar6;
  
  iVar1 = *param_2;
  for (puVar2 = *(uint **)(iVar1 + 0x24); puVar2 != (uint *)0x0; puVar2 = (uint *)puVar2[5]) {
    if (((*(byte *)(iVar1 + 0x14) & 1) == 0) ||
       (puVar5 = strings_lookupInTable(iVar1,*puVar2,0), (uint *)(*puVar5 & 0xfffffffe) == puVar2)) {
      uVar3 = *puVar2;
      *(byte *)((int)puVar2 + 0x11) = *(byte *)((int)puVar2 + 0x11) | 1;
      if ((((uVar3 & 1) == 0) || (uVar3 == 0x80000001)) && ((*(byte *)(uVar3 + 0x10) & 4) == 0)) {
        js_allocAtomSlot(param_1,uVar3);
      }
      if ((puVar2[4] & 0x30) != 0) {
        if ((puVar2[4] & 0x10) != 0) {
          js_lookupAtom(param_1,puVar2[1] & 0xfffffff8,0);
        }
        if ((puVar2[4] & 0x20) != 0) {
          js_lookupAtom(param_1,puVar2[2] & 0xfffffff8,0);
        }
      }
    }
  }
  pcVar4 = *(code **)((*(uint *)(param_2[1] + 8) & 0xfffffffe) + 0x40);
  if (pcVar4 != (code *)0x0) {
    (*pcVar4)(param_1,param_2,param_3);
  }
  if (*(int **)(iVar1 + 0x10) != param_2) {
    return *(uint *)(param_2[1] + -4);
  }
  uVar3 = *(uint *)(*param_2 + 0xc);
  uVar6 = *(uint *)(*param_2 + 8);
  if (uVar3 < uVar6) {
    uVar6 = uVar3;
  }
  return uVar6;
}



// ============================================================
// Function: runtime_cleanupPropertyRefs (FUN_68129860)
// Address: 68129860
// Size: 212 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_cleanupPropertyRefs(int param_1,int *param_2)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  uint uVar6;
  uint uVar7;
  
  iVar2 = *param_2;
  if (*(int **)(iVar2 + 0x10) == param_2) {
    iVar3 = *(int *)(param_1 + 0x14);
    for (puVar4 = *(uint **)(iVar2 + 0x24); puVar4 != (uint *)0x0; puVar4 = (uint *)puVar4[5]) {
      if ((((*(byte *)(iVar2 + 0x14) & 1) == 0) ||
          (puVar5 = strings_lookupInTable(iVar2,*puVar4,0), (uint *)(*puVar5 & 0xfffffffe) == puVar4)) &&
         (*(int *)(iVar3 + 0x224c) == 0)) {
        puVar1 = (undefined4 *)(iVar3 + 0x248 + (((uint)param_2 >> 3 ^ *puVar4) & 0x3ff) * 8);
        *(undefined4 *)(iVar3 + 0x2248) = 0;
        *puVar1 = param_2;
        puVar1[1] = 0;
      }
    }
    strings_clearTable(param_1,iVar2);
    uVar6 = *(uint *)(param_2[1] + 8) & 0xfffffffe;
    uVar7 = ((*(byte *)(uVar6 + 4) & 1) != 0) + 3 + (uint)*(byte *)(uVar6 + 5);
    uVar6 = *(uint *)(iVar2 + 8);
    while (uVar6 = uVar6 - 1, uVar7 <= uVar6) {
      *(undefined4 *)(param_2[1] + uVar6 * 4) = 0x80000001;
    }
    *(uint *)(iVar2 + 0xc) = uVar7;
  }
  return 0;
}



// ============================================================
// Function: runtime_getPropertySlotValue (FUN_68129940)
// Address: 68129940
// Size: 33 bytes
// Params: undefined4 param_1, int param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPropertySlotValue(undefined4 param_1,int param_2,uint param_3)

{
  if (param_3 < *(uint *)(*(int *)(param_2 + 4) + -4)) {
    return *(undefined4 *)(*(int *)(param_2 + 4) + param_3 * 4);
  }
  return 0x80000001;
}



// ============================================================
// Function: runtime_setPropertySlotValue (FUN_68129970)
// Address: 68129970
// Size: 144 bytes
// Params: int param_1, int * param_2, uint param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_setPropertySlotValue(int param_1,int *param_2,uint param_3,undefined4 param_4)
{
  uint uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  
  iVar4 = param_2[1];
  uVar5 = *(uint *)(iVar4 + -4);
  if (uVar5 <= param_3) {
    uVar1 = *(uint *)(iVar4 + 8) & 0xfffffffe;
    uVar1 = ((*(byte *)(uVar1 + 4) & 1) != 0) + 3 + (uint)*(byte *)(uVar1 + 5);
    if (uVar5 < uVar1) {
      uVar5 = uVar1;
    }
    puVar2 = (uint *)xtra_allocJSString(param_1,iVar4 + -4,uVar5 * 4 + 4);
    if (puVar2 == (uint *)0x0) {
      return 0;
    }
    uVar3 = *puVar2 + 1;
    if (uVar3 <= uVar1) {
      puVar6 = puVar2 + uVar3;
      for (iVar4 = (uVar1 - uVar3) + 1; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar6 = 0x80000001;
        puVar6 = puVar6 + 1;
      }
    }
    *puVar2 = uVar5;
    if (*(int **)(*param_2 + 0x10) == param_2) {
      *(uint *)(*param_2 + 8) = uVar5;
    }
    param_2[1] = (int)(puVar2 + 1);
  }
  *(undefined4 *)(param_2[1] + param_3 * 4) = param_4;
  return 0;
}



// ============================================================
// Function: runtime_getPropertyDescriptor (FUN_68129a00)
// Address: 68129a00
// Size: 271 bytes
// Params: uint param_1, int * param_2, int param_3, int * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPropertyDescriptor(uint param_1,int *param_2,int param_3,int *param_4)

{
  undefined **ppuVar1;
  int *piVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  int *piVar4;
  undefined8 uVar5;
  
  for (piVar3 = param_4; piVar3 != (int *)0x0;
      piVar3 = (int *)(*(uint *)(piVar3[1] + param_3 * 4) & 0xfffffff8)) {
    if (piVar3 == param_2) {
      xtra_invokeMethod(param_1,xtra_getErrorString,0,0x24);
      return 0;
    }
  }
  if (param_3 == 0) {
    piVar3 = (int *)*param_2;
    ppuVar1 = (undefined **)piVar3[1];
    if ((ppuVar1 == &PTR_FUN_68192948) ||
       ((ppuVar1 != (undefined **)0x0 && (*ppuVar1 == PTR_FUN_68192948)))) {
      piVar4 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
      if ((piVar4 != (int *)0x0) && ((int *)*piVar4 == piVar3)) {
        if (param_4 != (int *)0x0) {
          piVar2 = (int *)*param_4;
          ppuVar1 = (undefined **)piVar2[1];
          if (((ppuVar1 == &PTR_FUN_68192948) ||
              ((ppuVar1 != (undefined **)0x0 && (*ppuVar1 == PTR_FUN_68192948)))) &&
             (((*(uint *)(piVar4[1] + 8) ^ *(uint *)(param_4[1] + 8)) & 0xfffffffe) == 0)) {
            if (piVar2 != piVar3) {
              uVar5 = runtime_freePropertyTable(param_1,piVar2);
              *param_2 = (int)uVar5;
              runtime_resolvePropertyRef(extraout_ECX,(int *)((ulonglong)uVar5 >> 0x20),(int)param_2);
            }
            goto LAB_68129ab0;
          }
        }
        piVar3 = strings_getTableEntry(param_1,param_2);
        if (piVar3 == (int *)0x0) {
          return 0;
        }
      }
LAB_68129ab0:
      *(int **)param_2[1] = param_4;
      return 1;
    }
  }
  *(int **)(param_2[1] + param_3 * 4) = param_4;
  return 1;
}



// ============================================================
// Function: runtime_resolveAndGetProperty (FUN_68129b10)
// Address: 68129b10
// Size: 61 bytes
// Params: undefined4 param_1, uint param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_resolveAndGetProperty(undefined4 param_1,uint param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  
  iVar1 = runtime_resolvePropertyByAtom(param_1,param_2,*param_4,&param_4);
  if (iVar1 == 0) {
    return 0;
  }
  *param_5 = (int)param_4 * 8 | 6;
  return 1;
}



// ============================================================
// Function: runtime_getPropertySafe (FUN_68129b50)
// Address: 68129b50
// Size: 73 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_getPropertySafe(uint param_1,int *param_2,uint param_3,undefined4 *param_4,uint *param_5)
{
  int *piVar1;
  
  piVar1 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
  if (piVar1 == (int *)0x0) {
    runtime_getProperty(param_1,param_2,param_3,param_4,param_5);
    return 0;
  }
  (**(code **)(*(int *)(*piVar1 + 4) + 8))(param_1,piVar1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_getPropertyValueSafe (FUN_68129ba0)
// Address: 68129ba0
// Size: 65 bytes
// Params: uint param_1, int * param_2, uint param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_getPropertyValueSafe(uint param_1,int *param_2,uint param_3,int *param_4)
{
  int *piVar1;
  
  piVar1 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
  if (piVar1 == (int *)0x0) {
    runtime_getPropertyValue(param_1,param_2,param_3,param_4);
    return 0;
  }
  (**(code **)(*(int *)(*piVar1 + 4) + 0x10))(param_1,piVar1,param_3,param_4);
  return 0;
}



// ============================================================
// Function: runtime_getPropertyExSafe (FUN_68129bf0)
// Address: 68129bf0
// Size: 65 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_getPropertyExSafe(uint param_1,int *param_2,uint param_3,undefined4 *param_4)
{
  int *piVar1;
  
  piVar1 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
  if (piVar1 == (int *)0x0) {
    runtime_getPropertyEx(param_1,param_2,param_3,param_4);
    return 0;
  }
  (**(code **)(*(int *)(*piVar1 + 4) + 0x14))(param_1,piVar1,param_3,param_4);
  return 0;
}



// ============================================================
// Function: runtime_getPropertyAndCheckSafe (FUN_68129c40)
// Address: 68129c40
// Size: 73 bytes
// Params: uint param_1, int * param_2, uint param_3, uint param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_getPropertyAndCheckSafe(uint param_1,int *param_2,uint param_3,uint param_4,uint *param_5)
{
  int *piVar1;
  
  piVar1 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
  if (piVar1 == (int *)0x0) {
    runtime_getPropertyAndCheck(param_1,param_2,param_3,param_4,param_5);
    return 0;
  }
  (**(code **)(*(int *)(*piVar1 + 4) + 0x18))(param_1,piVar1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_getPropertyWithFlagsSafe (FUN_68129c90)
// Address: 68129c90
// Size: 73 bytes
// Params: uint param_1, int * param_2, uint param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_getPropertyWithFlagsSafe(uint param_1,int *param_2,uint param_3,uint *param_4,uint *param_5)
{
  int *piVar1;
  
  piVar1 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
  if (piVar1 == (int *)0x0) {
    runtime_getPropertyWithFlags(param_1,param_2,param_3,param_4,param_5);
    return 0;
  }
  (**(code **)(*(int *)(*piVar1 + 4) + 0x1c))(param_1,piVar1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_getPropertyDetailedSafe (FUN_68129ce0)
// Address: 68129ce0
// Size: 65 bytes
// Params: uint param_1, int * param_2, undefined * * param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_getPropertyDetailedSafe(uint param_1,int *param_2,undefined **param_3,int *param_4)
{
  int *piVar1;
  
  piVar1 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
  if (piVar1 == (int *)0x0) {
    runtime_getPropertyDetailed(param_1,param_2,param_3,param_4);
    return 0;
  }
  (**(code **)(*(int *)(*piVar1 + 4) + 0x20))(param_1,piVar1,param_3,param_4);
  return 0;
}



// ============================================================
// Function: runtime_accessPropertySlotSafe (FUN_68129d30)
// Address: 68129d30
// Size: 73 bytes
// Params: int param_1, int * param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_accessPropertySlotSafe(int param_1,int *param_2,int param_3,uint *param_4,uint *param_5)
{
  int *piVar1;
  
  piVar1 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
  if (piVar1 == (int *)0x0) {
    runtime_accessPropertySlot(param_1,param_2,param_3,param_4,param_5);
    return 0;
  }
  (**(code **)(*(int *)(*piVar1 + 4) + 0x28))(param_1,piVar1,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_invokePropertyGetterSafe (FUN_68129d80)
// Address: 68129d80
// Size: 81 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 param_4, undefined4 * param_5, uint * param_6
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_invokePropertyGetterSafe(uint param_1,int *param_2,uint param_3,undefined4 param_4,undefined4 *param_5,
                 uint *param_6)
{
  int *piVar1;
  
  piVar1 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
  if (piVar1 == (int *)0x0) {
    runtime_invokePropertyGetter(param_1,param_2,param_3,param_4,param_5,param_6);
    return 0;
  }
  (**(code **)(*(int *)(*piVar1 + 4) + 0x2c))(param_1,piVar1,param_3,param_4,param_5,param_6);
  return 0;
}



// ============================================================
// Function: runtime_setProperty (FUN_68129de0)
// Address: 68129de0
// Size: 394 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3, uint param_4
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_setProperty(int param_1,undefined4 *param_2,undefined4 *param_3,uint param_4)

{
  int *piVar1;
  code *pcVar2;
  int *piVar3;
  int iVar4;
  undefined **ppuVar5;
  uint *puVar6;
  undefined4 extraout_ECX;
  uint uVar7;
  uint *puVar8;
  uint local_8;
  
  piVar3 = js_bignumFree(param_1,0);
  uVar7 = param_4;
  if (piVar3 == (int *)0x0) {
    return (int *)0x0;
  }
  if (param_3 == (undefined4 *)0x0) {
    iVar4 = runtime_resolvePropertyByString(extraout_ECX,(char *)*param_2,param_4,(uint *)&param_3);
    if (iVar4 == 0) goto LAB_68129f02;
    if (param_3 == (undefined4 *)0x0) {
      iVar4 = runtime_resolvePropertyByString(&param_3,"Object",uVar7,(uint *)&param_3);
      if (iVar4 == 0) goto LAB_68129f02;
    }
  }
  if ((code *)param_2[10] == (code *)0x0) {
    ppuVar5 = &PTR_FUN_68192948;
  }
  else {
    ppuVar5 = (undefined **)(*(code *)param_2[10])(param_1,param_2);
  }
  if (((param_3 == (undefined4 *)0x0) ||
      (piVar1 = (int *)*param_3, (undefined **)piVar1[1] != ppuVar5)) ||
     (((*(uint *)((*(uint *)(param_3[1] + 8) & 0xfffffffe) + 4) ^ param_2[1]) & 0xff01) != 0)) {
    iVar4 = (*(code *)*ppuVar5)(param_1,1,ppuVar5,param_2,piVar3);
    if (iVar4 == 0) goto LAB_68129f02;
    *piVar3 = iVar4;
    uVar7 = *(uint *)(iVar4 + 8);
  }
  else {
    if (param_4 == 0) {
      iVar4 = (**(code **)(piVar1[1] + 0x10))
                        (param_1,param_3,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xec),&local_8);
      if (iVar4 == 0) goto LAB_68129f02;
      if (((local_8 & 7) == 0) && ((local_8 & 0xfffffff8) != 0)) {
        param_4 = *(uint *)(*(int *)((local_8 & 0xfffffff8) + 4) + 4) & 0xfffffff8;
      }
    }
    iVar4 = runtime_freePropertyTable(param_1,piVar1);
    *piVar3 = iVar4;
    uVar7 = 5;
  }
  puVar6 = (uint *)xtra_getPropertyById(param_1,uVar7 * 4 + 4);
  if (puVar6 != (uint *)0x0) {
    *puVar6 = uVar7;
    puVar6[1] = (uint)param_3;
    puVar6[2] = param_4;
    puVar6[3] = (uint)param_2 | 1;
    if (3 < uVar7) {
      puVar8 = puVar6 + 4;
      for (iVar4 = uVar7 - 3; iVar4 != 0; iVar4 = iVar4 + -1) {
        *puVar8 = 0x80000001;
        puVar8 = puVar8 + 1;
      }
    }
    piVar3[1] = (int)(puVar6 + 1);
    pcVar2 = *(code **)(*(int *)(param_1 + 0x14) + 0x220);
    if (pcVar2 != (code *)0x0) {
      (*pcVar2)(param_1,piVar3,1,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x224));
    }
    return piVar3;
  }
  runtime_resolvePropertyRef(param_1,(int *)*piVar3,(int)piVar3);
  *piVar3 = 0;
LAB_68129f02:
  *(undefined4 *)(param_1 + 0x90) = 0;
  return (int *)0x0;
}



// ============================================================
// Function: runtime_createPropertyFromName (FUN_68129f70)
// Address: 68129f70
// Size: 229 bytes
// Params: uint param_1, undefined4 * param_2, undefined4 * param_3, uint param_4, undefined4 param_5, undefined4 param_6
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_createPropertyFromName(uint param_1,undefined4 *param_2,undefined4 *param_3,uint param_4,uint param_5,
                  int param_6)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar5 = param_4;
  uVar1 = param_1;
  iVar2 = runtime_registerAtomFromString(param_2,(char *)*param_2,&param_1);
  puVar4 = param_3;
  if (iVar2 != 0) {
    if (((param_1 & 7) == 0) && (param_1 != 0)) {
      piVar3 = (int *)(param_1 & 0xfffffff8);
      if (uVar5 == 0) {
        uVar5 = *(uint *)(piVar3[1] + 4) & 0xfffffff8;
      }
      if (param_3 == (undefined4 *)0x0) {
        iVar2 = (**(code **)(*(int *)(*piVar3 + 4) + 0x10))
                          (uVar1,piVar3,*(undefined4 *)(*(int *)(uVar1 + 0x14) + 0xe8),&param_4);
        if (iVar2 == 0) {
          return (int *)0x0;
        }
        if ((param_4 & 7) == 0) {
          puVar4 = (undefined4 *)(param_4 & 0xfffffff8);
        }
      }
      piVar3 = runtime_setProperty(uVar1,param_2,puVar4,uVar5);
      if (piVar3 != (int *)0x0) {
        uVar5 = certs_validateExtension(uVar1,(int)piVar3,param_1,1,param_5,param_6,(int *)&param_4);
        if (uVar5 == 0) {
          *(undefined4 *)(uVar1 + 0x90) = 0;
          return (int *)0x0;
        }
        if ((param_4 & 7) != 0) {
          return piVar3;
        }
        return (int *)(param_4 & 0xfffffff8);
      }
    }
    else {
      runtime_callObjectMethod(uVar1,&param_1,1);
    }
  }
  return (int *)0x0;
}



// ============================================================
// Function: runtime_invokeMethod (FUN_6812a060)
// Address: 6812a060
// Size: 731 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 param_4, uint param_5, uint param_6, uint param_7, undefined4 param_8, undefined4 param_9, undefined4 * param_10
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_invokeMethod(uint param_1,int *param_2,uint param_3,undefined4 param_4,uint param_5,uint param_6,
            uint param_7,uint param_8,int param_9,undefined4 *param_10)

{
  undefined4 *puVar1;
  ushort uVar2;
  ushort uVar3;
  code *pcVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  uint uVar8;
  undefined *puVar9;
  uint uVar10;
  undefined *puVar11;
  int *piVar12;
  uint uVar13;
  ushort *puVar14;
  ushort *puVar15;
  uint *local_8;
  
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    piVar12 = (int *)(*(uint *)(param_3 + 8) & 0xfffffff8);
    puVar14 = (ushort *)piVar12[1];
    uVar7 = (uint)(*puVar14 == 0x2d);
    if (uVar7 != 0) {
      puVar14 = puVar14 + 1;
    }
    if (((*puVar14 < 0x80) && (iVar5 = isdigit((uint)*puVar14), iVar5 != 0)) &&
       (*piVar12 - uVar7 < 0xb)) {
      uVar8 = 0;
      puVar15 = puVar14 + 1;
      uVar10 = 0;
      uVar13 = *puVar14 - 0x30;
      if (uVar13 != 0) {
        uVar2 = *puVar15;
        while ((uVar2 < 0x80 && (iVar5 = isdigit((uint)uVar2), iVar5 != 0))) {
          uVar3 = *puVar15;
          uVar2 = puVar15[1];
          puVar15 = puVar15 + 1;
          uVar10 = uVar3 - 0x30;
          uVar8 = uVar13;
          uVar13 = uVar10 + uVar13 * 10;
        }
      }
      if ((*puVar15 == 0) && ((uVar8 < 0x6666666 || ((uVar8 == 0x6666666 && (uVar10 < 4)))))) {
        if (uVar7 != 0) {
          uVar13 = -uVar13;
        }
        param_3 = uVar13 * 2 | 1;
      }
    }
  }
  piVar12 = param_2;
  if ((param_7 & 0x30) != 0) {
    iVar5 = runtime_getProperty(param_1,param_2,param_3,&param_2,(uint *)&local_8);
    if (iVar5 == 0) {
      return 0;
    }
    if (local_8 != (uint *)0x0) {
      if ((param_2 == piVar12) && (((byte)local_8[4] & 0x30) != 0)) {
        puVar11 = (undefined *)param_6;
        if ((param_7 & 0x20) == 0) {
          puVar11 = (undefined *)local_8[2];
        }
        puVar9 = (undefined *)param_5;
        if ((param_7 & 0x10) == 0) {
          puVar9 = (undefined *)local_8[1];
        }
        local_8 = strings_addTableRange(param_1,*piVar12,local_8,param_7,(uint)(byte)local_8[4],puVar9,
                               puVar11);
        iVar5 = *(int *)(param_1 + 0x14);
        if (*(int *)(iVar5 + 0x224c) == 0) {
          puVar1 = (undefined4 *)(iVar5 + 0x248 + (((uint)piVar12 >> 3 ^ param_3) & 0x3ff) * 8);
          *(undefined4 *)(iVar5 + 0x2248) = 0;
          *puVar1 = piVar12;
          puVar1[1] = local_8;
        }
        if (local_8 == (uint *)0x0) {
          return 0;
        }
        goto LAB_6812a324;
      }
      pcVar4 = *(code **)(*(int *)(*param_2 + 4) + 0x34);
      if (pcVar4 != (code *)0x0) {
        (*pcVar4)(param_1,param_2,local_8);
      }
      local_8 = (uint *)0x0;
    }
  }
  param_2 = (int *)(*(uint *)(piVar12[1] + 8) & 0xfffffffe);
  if (param_5 == 0) {
    param_5 = param_2[4];
  }
  if (param_6 == 0) {
    param_6 = param_2[5];
  }
  piVar6 = strings_getTableEntry(param_1,piVar12);
  if (piVar6 != (int *)0x0) {
    if ((*(byte *)(param_2 + 1) & 0x10) != 0) {
      param_7 = param_7 | 0x40;
    }
    local_8 = (uint *)strings_createTableEntry(param_1,(int)piVar6,param_3,(undefined *)param_5,
                                   (undefined *)param_6,-1,param_7,param_8,param_9);
    if (local_8 != (uint *)0x0) {
      if ((*(byte *)((int)local_8 + 0x11) & 8) == 0) {
        uVar7 = *local_8;
        if ((uVar7 & 1) == 0) {
          uVar7 = *(uint *)(uVar7 + 8);
        }
      }
      else {
        uVar7 = *(short *)((int)local_8 + 0x12) * 2 | 1;
      }
      iVar5 = (*(code *)param_2[2])(param_1,piVar12,uVar7,&param_4);
      if (iVar5 != 0) {
        iVar5 = *(int *)(param_1 + 0x14);
        if (*(int *)(iVar5 + 0x224c) == 0) {
          puVar1 = (undefined4 *)(iVar5 + 0x248 + (((uint)piVar12 >> 3 ^ param_3) & 0x3ff) * 8);
          *(undefined4 *)(iVar5 + 0x2248) = 0;
          *puVar1 = piVar12;
          puVar1[1] = local_8;
        }
        if (local_8[3] < (uint)piVar6[3]) {
          *(undefined4 *)(piVar12[1] + local_8[3] * 4) = param_4;
        }
LAB_6812a324:
        if (param_10 != (undefined4 *)0x0) {
          *param_10 = local_8;
        }
        return 1;
      }
      strings_setTableValue(param_1,(int)piVar6,param_3);
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_definePropertyFromAtom (FUN_6812a340)
// Address: 6812a340
// Size: 496 bytes
// Params: uint param_1, undefined * * param_2, int param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_definePropertyFromAtom(uint param_1,undefined **param_2,int param_3,uint *param_4)

{
  char cVar1;
  undefined **ppuVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  undefined3 extraout_var;
  uint uVar6;
  char *pcVar7;
  char *pcVar8;
  uint *puVar9;
  
  iVar3 = param_3;
  ppuVar2 = param_2;
  if (param_3 == 3) {
    uVar6 = runtime_defineProperty(param_1,(int *)param_2,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x128),0,
                         0,(int *)&param_2);
    if (uVar6 == 0) {
      return 0;
    }
    if (((uint)param_2 & 7) != 0) goto LAB_6812a51f;
    if (param_2 != (undefined **)0x0) {
      iVar5 = (**(code **)((*(uint *)(ppuVar2[1] + 8) & 0xfffffffe) + 0x20))
                        (param_1,ppuVar2,3,&param_2);
      if (iVar5 == 0) {
        return 0;
      }
      if (((uint)param_2 & 7) != 0) goto LAB_6812a51f;
      if ((param_2 != (undefined **)0x0) && (*(int *)(param_1 + 0xc) == 0x78)) {
        pcVar7 = (char *)runtime_strlen("[object %s]");
        if (pcVar7 == (char *)0x0) {
          return 0;
        }
        pcVar8 = pcVar7;
        do {
          cVar1 = *pcVar8;
          pcVar8 = pcVar8 + 1;
        } while (cVar1 != '\0');
        puVar9 = xtra_getScriptContextEx(param_1,(int)pcVar7,(int)pcVar8 - (int)(pcVar7 + 1));
        if (puVar9 == (uint *)0x0) {
          js_freeHandle();
          return 0;
        }
        *param_4 = (uint)puVar9 | 4;
        return 1;
      }
    }
  }
  else {
    iVar5 = (**(code **)((*(uint *)(param_2[1] + 8) & 0xfffffffe) + 0x20))
                      (param_1,param_2,param_3,&param_2);
    if (iVar5 == 0) {
      return 0;
    }
    if (((uint)param_2 & 7) != 0) goto LAB_6812a51f;
    if (param_2 != (undefined **)0x0) {
      bVar4 = xtra_lookupHashByte(param_1,(uint)param_2);
      if (((CONCAT31(extraout_var,bVar4) == iVar3) ||
          ((CONCAT31(extraout_var,bVar4) == 2 && (iVar3 == 1)))) ||
         ((*(int *)(param_1 + 0xc) == 0x78 && (iVar3 == 5)))) goto LAB_6812a51f;
      uVar6 = runtime_defineProperty(param_1,(int *)ppuVar2,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x128),
                           0,0,(int *)&param_2);
      if (uVar6 == 0) {
        return 0;
      }
    }
  }
  if ((((uint)param_2 & 7) == 0) && (param_2 != (undefined **)0x0)) {
    if (iVar3 == 3) {
      puVar9 = (uint *)xtra_lookupAtomValue(param_1,*(char **)(*(uint *)(ppuVar2[1] + 8) & 0xfffffffe));
      if (puVar9 == (uint *)0x0) {
        return 0;
      }
    }
    else {
      puVar9 = (uint *)0x0;
    }
    *param_4 = (uint)ppuVar2;
    puVar9 = crypto_decompileExpr(param_1,(int *)0x1,param_2,puVar9);
    if (puVar9 != (uint *)0x0) {
      xtra_getStringValue(puVar9);
      xtra_invokeMethod(param_1,xtra_getErrorString,0,0x26);
    }
    return 0;
  }
LAB_6812a51f:
  *param_4 = (uint)param_2;
  return 1;
}



// ============================================================
// Function: runtime_resolveAndSetProperty (FUN_6812a530)
// Address: 6812a530
// Size: 24 bytes
// Params: void * this, undefined4 param_1, char * param_2, uint * param_3
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall runtime_resolveAndSetProperty(void *this,undefined4 param_1,char *param_2,uint *param_3)
{
  runtime_resolvePropertyByString(this,param_2,0,param_3);
  return 0;
}



// ============================================================
// Function: runtime_definePropertyOnObject (FUN_6812a550)
// Address: 6812a550
// Size: 53 bytes
// Params: uint param_1, int * param_2, int param_3, int * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_definePropertyOnObject(uint param_1,int *param_2,int param_3,int *param_4)
{
  int *piVar1;
  uint uVar2;
  
  uVar2 = param_1;
  piVar1 = (int *)(param_1 + 0x14);
  param_1 = *(uint *)(*(int *)(*piVar1 + 0x7c + param_3 * 4) + 8);
  runtime_defineProperty(uVar2,param_2,*(undefined4 *)(*piVar1 + 300),1,(int)&param_1,param_4);
  return 0;
}



// ============================================================
// Function: runtime_serializeObjectRef (FUN_6812a590)
// Address: 6812a590
// Size: 396 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_serializeObjectRef(int *param_1,int *param_2)
{
  int iVar1;
  uint *puVar2;
  uint local_28;
  uint local_24;
  byte *local_20;
  uint local_1c;
  int local_18;
  undefined1 local_14 [12];
  uint local_8;
  
  local_1c = param_1[2];
  if (*param_1 == 0) {
    puVar2 = (uint *)(*(uint *)(*(int *)(*param_2 + 4) + 8) & 0xfffffffe);
    local_20 = (byte *)*puVar2;
    local_18 = runtime_lookupSerializationEntry((int)param_1,local_20);
    local_24 = (uint)(local_18 == 0);
    if (local_24 != 0) {
      iVar1 = runtime_addSerializationEntry((int)param_1,puVar2,&local_18);
      if (iVar1 == 0) goto LAB_6812a5f1;
    }
  }
  else {
    local_24 = 0;
    local_20 = (byte *)0x0;
    puVar2 = (uint *)0x0;
  }
  iVar1 = runtime_serializeValue(param_1,&local_24);
  if (iVar1 == 0) {
LAB_6812a5f1:
    return 0;
  }
  if (local_24 != 0) {
    iVar1 = runtime_deserializeValue(param_1,(int *)&local_20);
    if (iVar1 == 0) goto LAB_6812a5f1;
  }
  iVar1 = runtime_serializeValue(param_1,&local_18);
  if (iVar1 == 0) goto LAB_6812a6f1;
  if (*param_1 != 0) {
    if (local_24 == 0) {
      puVar2 = (uint *)runtime_getSerializationEntryByIndex((int)param_1,local_18);
      if (puVar2 == (uint *)0x0) {
        runtime_snprintf(local_14,0xc,"%ld");
        xtra_invokeMethod(local_1c,xtra_getErrorString,0,0x28);
        goto LAB_6812a6f1;
      }
    }
    else {
      iVar1 = runtime_resolveAndSetProperty(local_20,local_1c,(char *)local_20,&local_28);
      if (iVar1 == 0) goto LAB_6812a6f1;
      puVar2 = (uint *)(*(uint *)(*(int *)(local_28 + 4) + 8) & 0xfffffffe);
      iVar1 = runtime_addSerializationEntry((int)param_1,puVar2,&local_18);
      if (iVar1 == 0) goto LAB_6812a6f1;
    }
  }
  if ((code *)puVar2[0xe] == (code *)0x0) {
    xtra_invokeMethod(local_1c,xtra_getErrorString,0,0x29);
  }
  else {
    (*(code *)puVar2[0xe])(param_1,param_2);
  }
LAB_6812a6f1:
  if ((*param_1 != 0) && (local_20 != (byte *)0x0)) {
    xtra_checkAndFlush(local_1c,(int)local_20);
  }
  return 0;
}



// ============================================================
// Function: runtime_getPropertyForIn (FUN_6812a720)
// Address: 6812a720
// Size: 134 bytes
// Params: uint param_1, int * param_2, int param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getPropertyForIn(uint param_1,int *param_2,int param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  
  uVar2 = param_1;
  uVar1 = *param_4;
  if ((uVar1 & 7) != 0) {
    return 1;
  }
  iVar6 = param_3 >> 1;
  if ((*(byte *)(param_1 + 0x164) & 1) != 0) {
    iVar4 = runtime_checkDebugFlag(param_1);
    if (iVar4 == 0) {
      return 0;
    }
  }
  piVar3 = param_2;
  iVar4 = (**(code **)(*(int *)(*param_2 + 4) + 0x2c))(uVar2,param_2,param_3,8,param_4,&param_1);
  if (iVar4 == 0) {
    return 0;
  }
  uVar5 = runtime_getPropertyDescriptor(uVar2,piVar3,iVar6,(int *)(uVar1 & 0xfffffff8));
  return uVar5;
}



// ============================================================
// Function: runtime_setPropertyOnObject (FUN_6812a7b0)
// Address: 6812a7b0
// Size: 545 bytes
// Params: uint * param_1, undefined4 * param_2, uint param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_setPropertyOnObject(uint *param_1,undefined4 *param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  bool bVar4;
  bool bVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined4 uVar9;
  uint *puVar10;
  uint uVar11;
  bool bVar12;
  undefined4 *local_1c;
  undefined4 *local_14;
  int local_c;
  int *local_8;
  
  uVar1 = param_1[0xd];
  iVar2 = *(int *)(uVar1 + 0x2c);
  local_14 = (undefined4 *)0x0;
  local_1c = (undefined4 *)0x0;
  bVar5 = false;
  bVar12 = false;
  if ((*(char **)(iVar2 + 0x38) == (char *)0x0) || (bVar4 = false, **(char **)(iVar2 + 0x38) != 'y')
     ) {
    bVar4 = true;
  }
  if ((((param_1[3] == 0) || (0x81 < (int)param_1[3])) && (bVar4)) &&
     (iVar6 = xtra_invokeWithArgs(param_1,5,xtra_getErrorString,0,0x92), iVar6 == 0)) {
    return 0;
  }
  if (((byte)*param_4 & 7) != 4) {
    *param_5 = *param_4;
    return 1;
  }
  local_8 = (int *)0x0;
  if (1 < param_3) {
    iVar6 = runtime_deleteProperty((uint)param_1,param_4[1],(uint *)&local_8);
    if (iVar6 == 0) {
      return 0;
    }
    param_4[1] = (uint)local_8;
    if (local_8 != (int *)0x0) goto LAB_6812a8cd;
  }
  if (bVar4) {
    local_14 = *(undefined4 **)(iVar2 + 0x34);
    if (param_2 != local_14) {
      piVar7 = runtime_setProperty((int)param_1,&PTR_DAT_68192b48,param_2,(uint)local_14);
      if (piVar7 == (int *)0x0) {
        return 0;
      }
      *(int **)(uVar1 + 0x34) = piVar7;
      *(int **)(iVar2 + 0x34) = piVar7;
      bVar5 = true;
    }
    local_1c = *(undefined4 **)(iVar2 + 8);
    bVar12 = param_2 != local_1c;
    if (bVar12) {
      *(undefined4 **)(uVar1 + 8) = param_2;
      *(undefined4 **)(iVar2 + 8) = param_2;
    }
  }
  local_8 = *(int **)(iVar2 + 0x34);
LAB_6812a8cd:
  uVar11 = *(uint *)(iVar2 + 0xc);
  puVar10 = (uint *)(*param_4 & 0xfffffff8);
  if (uVar11 == 0) {
    param_2 = (undefined4 *)0x0;
    param_4 = (uint *)0x0;
    local_c = 0;
  }
  else {
    param_2 = *(undefined4 **)(uVar11 + 0x18);
    param_4 = (uint *)runtime_getObjectField(uVar11,*(int *)(iVar2 + 0x38));
    local_c = *(int *)(*(int *)(iVar2 + 0xc) + 0x2c);
  }
  *(uint *)(uVar1 + 0x4c) = *(uint *)(uVar1 + 0x4c) | 8;
  uVar1 = *puVar10;
  if ((uVar1 & 0x40000000) == 0) {
    uVar8 = puVar10[1];
  }
  else {
    uVar11 = (-(uint)((uVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar1;
    puVar3 = (uint *)puVar10[1];
    if ((*puVar3 & 0x40000000) == 0) {
      if ((int)uVar1 < 0) {
        uVar8 = puVar3[1];
        uVar1 = uVar11;
      }
      else {
        uVar8 = puVar3[1] + (uVar1 >> 0xf & 0x7fff) * 2;
        uVar1 = uVar11;
      }
    }
    else {
      uVar8 = crypto_getStringLen(puVar10);
      uVar1 = uVar11;
    }
  }
  piVar7 = xtra_evalScriptBuffer(param_1,local_8,local_c,uVar8,uVar1,param_2,param_4);
  uVar9 = 0;
  if (piVar7 != (int *)0x0) {
    if (param_3 < 2) {
      local_8 = *(int **)(iVar2 + 0x34);
    }
    uVar9 = certs_processExtension((int)param_1,(uint)local_8,piVar7,iVar2,8,param_5);
    xtra_getInterfacePtr((int)param_1,(int)piVar7);
  }
  if (bVar5) {
    *(undefined4 **)(iVar2 + 0x34) = local_14;
  }
  if (bVar12) {
    *(undefined4 **)(iVar2 + 8) = local_1c;
  }
  return uVar9;
}



// ============================================================
// Function: runtime_deletePropertyOnObject (FUN_6812a9e0)
// Address: 6812a9e0
// Size: 90 bytes
// Params: uint param_1, int * param_2, int param_3, uint * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_deletePropertyOnObject(uint param_1,int *param_2,int param_3,uint *param_4,undefined4 *param_5)

{
  int iVar1;
  
  if (param_3 != 0) {
    iVar1 = runtime_deleteProperty(param_1,*param_4,(uint *)&param_2);
    if (iVar1 == 0) {
      return 0;
    }
    if (param_2 != (int *)0x0) goto LAB_6812aa2b;
  }
  if ((*(byte *)(*(int *)(param_1 + 0x34) + 0x4c) & 1) != 0) {
    return 1;
  }
  param_2 = runtime_setProperty(param_1,&PTR_s_Object_681929a8,(undefined4 *)0x0,0);
  if (param_2 == (int *)0x0) {
    return 0;
  }
LAB_6812aa2b:
  *param_5 = param_2;
  return 1;
}



// ============================================================
// Function: runtime_definePropertyOnObjectSafe (FUN_6812aa40)
// Address: 6812aa40
// Size: 65 bytes
// Params: uint param_1, undefined * * param_2, int param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_definePropertyOnObjectSafe(uint param_1,undefined **param_2,int param_3,uint *param_4)
{
  int *piVar1;
  
  piVar1 = (int *)(*(uint *)param_2[1] & 0xfffffff8);
  if (piVar1 == (int *)0x0) {
    runtime_definePropertyFromAtom(param_1,param_2,param_3,param_4);
    return 0;
  }
  (**(code **)(*(int *)(*piVar1 + 4) + 0x24))(param_1,piVar1,param_3,param_4);
  return 0;
}



// ============================================================
// Function: runtime_constructError (FUN_6812aa90)
// Address: 6812aa90
// Size: 213 bytes
// Params: int * param_1, int * param_2, uint param_3, uint * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_constructError(int *param_1,int *param_2,uint param_3,uint *param_4,undefined4 *param_5)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined4 uVar5;
  
  piVar1 = param_1;
  iVar3 = xtra_invokeWithArgs(param_1,5,xtra_getErrorString,0,0x9e);
  if (iVar3 == 0) {
    return 0;
  }
  piVar4 = param_2;
  if ((*(byte *)(piVar1[0xd] + 0x4c) & 1) == 0) {
    piVar4 = runtime_setProperty((int)piVar1,&PTR_DAT_68192b48,(undefined4 *)0x0,0);
    if (piVar4 == (int *)0x0) {
      return 0;
    }
    *param_5 = piVar4;
  }
  uVar2 = param_3;
  param_5 = *(undefined4 **)(piVar1[0xd] + 0x34);
  if (param_3 != 0) {
    iVar3 = runtime_deleteProperty((uint)piVar1,*param_4,(uint *)&param_2);
    if (iVar3 != 0) {
      param_1 = param_2;
      iVar3 = runtime_getPropertyForIn((uint)piVar1,piVar4,1,(uint *)&param_1);
      if ((iVar3 != 0) &&
         ((uVar2 < 2 || (iVar3 = runtime_deleteProperty((uint)piVar1,param_4[1],(uint *)&param_5), iVar3 != 0)
          ))) goto LAB_6812ab4b;
    }
    return 0;
  }
LAB_6812ab4b:
  param_1 = param_5;
  uVar5 = runtime_getPropertyForIn((uint)piVar1,piVar4,3,(uint *)&param_1);
  return uVar5;
}



// ============================================================
// Function: runtime_initGlobalObject (FUN_6812ab70)
// Address: 6812ab70
// Size: 172 bytes
// Params: int param_1, int * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_initGlobalObject(int param_1,int *param_2)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  
  piVar1 = param_2;
  piVar2 = xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_s_Object_681929a8,0x6812a9e0,1,
                        (int *)&PTR_s___proto___681929f0,(int *)&PTR_s_toSource_68192a30,(int *)0x0,
                        (int *)0x0);
  if (piVar2 != (int *)0x0) {
    piVar3 = xtra_createScriptObject(param_1,piVar1,(undefined4 *)0x0,&PTR_DAT_68192b48,0x6812aa90,0,(int *)0x0
                          ,(int *)0x0,(int *)0x0,(int *)0x0);
    if (piVar3 != (int *)0x0) {
      iVar4 = (**(code **)(*(int *)(*piVar2 + 4) + 0x10))
                        (param_1,piVar2,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xf4),&param_2);
      if (iVar4 != 0) {
        iVar4 = (**(code **)(*(int *)(*piVar1 + 4) + 0xc))
                          (param_1,piVar1,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0xf4),param_2,0
                           ,0,0,0);
        return -(uint)(iVar4 != 0) & (uint)piVar2;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_callProperty (FUN_6812ac20)
// Address: 6812ac20
// Size: 48 bytes
// Params: uint param_1, int * param_2, uint param_3, undefined4 param_4, uint param_5, uint param_6, uint param_7, undefined4 * param_8
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_callProperty(uint param_1,int *param_2,uint param_3,undefined4 param_4,uint param_5,
                 uint param_6,uint param_7,undefined4 *param_8)
{
  runtime_invokeMethod(param_1,param_2,param_3,param_4,param_5,param_6,param_7,0,0,param_8);
  return 0;
}



// ============================================================
// Function: runtime_freePropertyChain (FUN_6812ac50)
// Address: 6812ac50
// Size: 130 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_freePropertyChain(int *param_1)
{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  undefined4 unaff_EDI;
  
  if (param_1 != (int *)0x0) {
    piVar2 = (int *)*param_1;
    if (piVar2 != (int *)0x0) {
      if (piVar2[4] != 0) {
        xtra_checkAndFlush(unaff_EDI,piVar2[4]);
      }
      if (*piVar2 != 0) {
        xtra_checkAndFlush(unaff_EDI,*piVar2);
      }
      if (piVar2[8] != 0) {
        xtra_checkAndFlush(unaff_EDI,piVar2[8]);
      }
      piVar4 = (int *)piVar2[9];
      if (piVar4 != (int *)0x0) {
        iVar3 = *piVar4;
        while (iVar3 != 0) {
          xtra_checkAndFlush(unaff_EDI,iVar3);
          piVar1 = piVar4 + 1;
          piVar4 = piVar4 + 1;
          iVar3 = *piVar1;
        }
        xtra_checkAndFlush(unaff_EDI,piVar2[9]);
      }
      xtra_checkAndFlush(unaff_EDI,(int)piVar2);
    }
    xtra_checkAndFlush(unaff_EDI,(int)param_1);
  }
  return 0;
}



