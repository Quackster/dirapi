// Module: javascript
// Topic: Arena pool allocator, hash tables, code generation, bytecode emitter
// Address range: 0x6813cce5 - 0x6813fff0
// Functions (74):

//   javascript_emitBytecode
//   js_setPropertyDirect
//   js_getSlotIndex
//   js_resolveProperty
//   js_reallocObject
//   javascript_resolveSlot
//   js_getPrototype
//   javascript_getSlotByName
//   javascript_resizeSlotTable
//   js_getPrototypeChain
//   javascript_freeArenaPool
//   javascript_arenaPoolReserve
//   javascript_arenaPoolAlloc
//   javascript_arenaPoolFree
//   javascript_arenaPoolGrow
//   javascript_arenaPoolShrink
//   javascript_arenaPoolGetInfo
//   javascript_getDefaultAllocator
//   javascript_initHashTable
//   javascript_freeHashTable
//   js_findPropertySlot
//   javascript_hashTableGrow
//   js_enumerateProperties
//   javascript_hashTableIterate
//   javascript_hashTableCreate
//   javascript_hashTableDestroy
//   js_getPropertySlot
//   javascript_hashTableInsert
//   javascript_hashTableLookup
//   javascript_hashTableRemove
//   javascript_hashTableResize
//   js_setPropertyFlag
//   js_setMultipleFlags
//   javascript_hashTableCount
//   javascript_hashTableEntrySize
//   js_getClassId
//   javascript_objectSetSlot
//   javascript_objectResolveSlot
//   javascript_objectDefineSlot
//   js_setObjectSlot
//   javascript_objectConfigureSlot
//   javascript_objectSetGetter
//   javascript_objectSetSetter
//   javascript_objectGetAccessor
//   js_callGetter
//   javascript_objectPutSlot
//   js_defineProperty
//   javascript_objectRemoveSlot
//   js_storeProperty
//   javascript_objectStoreSlotDirect
//   javascript_objectStoreSlotResolved
//   js_initPropertySlot
//   js_setPropertyFlags
//   js_freezeObject
//   js_deleteProperty
//   js_hasProperty
//   js_getPropertyDescriptor
//   js_enumerateKeys
//   javascript_objectEnumerateSlots
//   javascript_objectAllocSlots
//   js_allocObject
//   javascript_objectCreateScoped
//   javascript_objectCreateWithClass
//   js_getObjectType
//   js_getObjectFlags
//   js_allocObjectWithProto
//   javascript_objectClone
//   javascript_objectSetParent
//   javascript_objectGetParent
//   javascript_objectSetPrototype
//   javascript_objectCreateFromLiteral
//   javascript_objectSealProperties
//   javascript_objectFreezeProperties
//   javascript_objectIsSealed

// ============================================================
// Function: javascript_emitBytecode (FUN_6813cce5)
// Address: 6813cce5
// Size: 881 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_emitBytecode(void)

{
  uint uVar1;
  char *pcVar2;
  int iVar3;
  int iVar4;
  char cVar5;
  uint uVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar7;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  int iVar8;
  int unaff_EBP;
  int iVar9;
  char *unaff_EDI;
  char *pcVar10;
  undefined2 in_FPUControlWord;
  float10 in_ST0;
  double dVar11;
  
  dVar11 = floor((double)in_ST0);
  *(double *)(unaff_EBP + -0x1c) = dVar11;
  pcVar10 = unaff_EDI;
  if (4294967295.0 < dVar11) {
    iVar9 = javascript_bignumExtractExponent(SUB84(dVar11,0),(uint)((ulonglong)dVar11 >> 0x20),
                         (int *)(unaff_EBP + -0x24),(int *)(unaff_EBP + -0x20));
    if ((iVar9 == 0) || (iVar9 = js_bignumDivide(iVar9,*(uint *)(unaff_EBP + -0x24)), iVar9 == 0))
    goto LAB_6813cffb;
    do {
      uVar6 = javascript_numberToPrecision(iVar9,*(uint *)(unaff_EBP + 8));
      if (uVar6 < 10) {
        cVar5 = (char)uVar6 + '0';
      }
      else {
        cVar5 = (char)uVar6 + 'W';
      }
      *pcVar10 = cVar5;
      pcVar10 = pcVar10 + 1;
    } while (*(int *)(iVar9 + 0x10) != 0);
    js_freePooledObject();
    dVar11 = *(double *)(unaff_EBP + -0x1c);
  }
  else {
    *(undefined2 *)(unaff_EBP + -2) = in_FPUControlWord;
    *(uint *)(unaff_EBP + -0x24) = *(ushort *)(unaff_EBP + -2) | 0xc00;
    *(longlong *)(unaff_EBP + -0x28) = (longlong)ROUND(dVar11);
    uVar6 = *(uint *)(unaff_EBP + -0x28);
    if (*(uint *)(unaff_EBP + -0x28) == 0) {
      *unaff_EDI = '0';
      pcVar10 = unaff_EDI + 1;
    }
    else {
      do {
        uVar1 = uVar6 / *(uint *)(unaff_EBP + 8);
        uVar6 = uVar6 - uVar1 * *(uint *)(unaff_EBP + 8);
        cVar5 = (char)uVar6;
        if (uVar6 < 10) {
          cVar5 = cVar5 + '0';
        }
        else {
          cVar5 = cVar5 + 'W';
        }
        *pcVar10 = cVar5;
        pcVar10 = pcVar10 + 1;
        uVar6 = uVar1;
      } while (uVar1 != 0);
    }
  }
  pcVar2 = pcVar10 + -1;
  if (unaff_EDI < pcVar2) {
    do {
      cVar5 = *unaff_EDI;
      *unaff_EDI = *pcVar2;
      *pcVar2 = cVar5;
      unaff_EDI = unaff_EDI + 1;
      pcVar2 = pcVar2 + -1;
    } while (unaff_EDI < pcVar2);
  }
  dVar11 = *(double *)(unaff_EBP + 0xc) - dVar11;
  if (dVar11 == 0.0) {
    uVar7 = *(undefined4 *)(unaff_EBP + -0x2c);
    *pcVar10 = '\0';
    return uVar7;
  }
  *pcVar10 = '.';
  iVar9 = 0;
  iVar8 = 0;
  *(undefined4 *)(unaff_EBP + -0xc) = 0;
  *(char **)(unaff_EBP + -0x10) = pcVar10 + 1;
  iVar3 = javascript_bignumExtractExponent(SUB84(dVar11,0),(uint)((ulonglong)dVar11 >> 0x20),(int *)(unaff_EBP + -0x24),
                       (int *)(unaff_EBP + -0x20));
  if (iVar3 != 0) {
    iVar9 = -(*(uint *)(unaff_EBP + 0x10) >> 0x14 & 0x7ff);
    if (iVar9 == 0) {
      *(undefined4 *)(unaff_EBP + -0x18) = 0xffffffff;
      iVar9 = *(int *)(unaff_EBP + -0x18);
    }
    uVar6 = iVar9 + 0x434;
    *(uint *)(unaff_EBP + -0x18) = uVar6;
    iVar4 = js_bignumNormalize(1);
    *(int *)(unaff_EBP + -4) = iVar4;
    if (iVar4 != 0) {
      iVar8 = iVar4;
      if (((*(int *)(unaff_EBP + 0xc) == 0) && ((*(uint *)(unaff_EBP + 0x10) & 0xfffff) == 0)) &&
         ((*(uint *)(unaff_EBP + 0x10) & 0x7fe00000) != 0)) {
        uVar6 = iVar9 + 0x435;
        *(uint *)(unaff_EBP + -0x18) = uVar6;
        iVar8 = js_bignumNormalize(2);
        if (iVar8 == 0) goto LAB_6813cfde;
      }
      iVar9 = js_bignumDivide(iVar3,uVar6 + *(int *)(unaff_EBP + -0x24));
      if (iVar9 != 0) {
        iVar3 = js_bignumNormalize(1);
        *(int *)(unaff_EBP + -0xc) = iVar3;
        if (iVar3 != 0) {
          iVar3 = js_bignumDivide(iVar3,uVar6);
          *(int *)(unaff_EBP + -0xc) = iVar3;
          if (iVar3 != 0) {
            *(undefined4 *)(unaff_EBP + -0x14) = 0;
            while (iVar9 = js_bignumMultiply(iVar9,*(uint *)(unaff_EBP + 8),0), iVar9 != 0) {
              uVar6 = javascript_numberToFixed(iVar9);
              *(uint *)(unaff_EBP + -8) = uVar6;
              iVar3 = *(int *)(unaff_EBP + -4);
              if (iVar3 == iVar8) {
                iVar8 = js_bignumMultiply(iVar3,*(uint *)(unaff_EBP + 8),0);
                *(int *)(unaff_EBP + -4) = iVar8;
                uVar7 = extraout_ECX;
              }
              else {
                uVar6 = *(uint *)(unaff_EBP + 8);
                iVar3 = js_bignumMultiply(iVar3,uVar6,0);
                *(int *)(unaff_EBP + -4) = iVar3;
                if (iVar3 == 0) break;
                iVar8 = js_bignumMultiply(iVar8,uVar6,0);
                uVar7 = extraout_ECX_00;
              }
              if (iVar8 == 0) break;
              iVar3 = js_bignumCompare(uVar7,iVar9);
              *(int *)(unaff_EBP + -0x24) = iVar3;
              iVar3 = javascript_bignumDivideRemainder(*(int *)(unaff_EBP + -0xc));
              if (iVar3 == 0) break;
              if (*(int *)(iVar3 + 0xc) == 0) {
                iVar3 = js_bignumCompare(extraout_ECX_01,iVar9);
                *(int *)(unaff_EBP + -0x20) = iVar3;
              }
              else {
                *(undefined4 *)(unaff_EBP + -0x20) = 1;
              }
              js_freePooledObject();
              iVar3 = *(int *)(unaff_EBP + -0x20);
              if ((iVar3 == 0) && ((*(byte *)(unaff_EBP + 0xc) & 1) == 0)) {
                iVar3 = *(int *)(unaff_EBP + -0x24);
LAB_6813cfab:
                if (0 < iVar3) {
                  *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 1;
                }
LAB_6813cfb0:
                *(undefined4 *)(unaff_EBP + -0x14) = 1;
              }
              else {
                if ((*(int *)(unaff_EBP + -0x24) < 0) ||
                   ((*(int *)(unaff_EBP + -0x24) == 0 && ((*(byte *)(unaff_EBP + 0xc) & 1) == 0))))
                {
                  if (iVar3 < 1) goto LAB_6813cfb0;
                  iVar9 = js_bignumDivide(iVar9,1);
                  if (iVar9 != 0) {
                    iVar3 = js_bignumCompare(extraout_ECX_02,iVar9);
                    goto LAB_6813cfab;
                  }
                  break;
                }
                if (0 < iVar3) {
                  *(int *)(unaff_EBP + -8) = *(int *)(unaff_EBP + -8) + 1;
                  *(undefined4 *)(unaff_EBP + -0x14) = 1;
                }
              }
              cVar5 = (char)*(uint *)(unaff_EBP + -8);
              if (*(uint *)(unaff_EBP + -8) < 10) {
                cVar5 = cVar5 + '0';
              }
              else {
                cVar5 = cVar5 + 'W';
              }
              pcVar10 = *(char **)(unaff_EBP + -0x10);
              *pcVar10 = cVar5;
              *(char **)(unaff_EBP + -0x10) = pcVar10 + 1;
              if (*(int *)(unaff_EBP + -0x14) != 0) {
                js_freePooledObject();
                js_freePooledObject();
                if (*(int *)(unaff_EBP + -4) != iVar8) {
                  js_freePooledObject();
                }
                js_freePooledObject();
                uVar7 = *(undefined4 *)(unaff_EBP + -0x2c);
                **(undefined1 **)(unaff_EBP + -0x10) = 0;
                return uVar7;
              }
            }
          }
        }
      }
    }
LAB_6813cfde:
    iVar9 = *(int *)(unaff_EBP + -4);
  }
  js_freePooledObject();
  js_freePooledObject();
  if (iVar9 != iVar8) {
    js_freePooledObject();
  }
LAB_6813cffb:
  js_freePooledObject();
  return 0;
}



// ============================================================
// Function: js_setPropertyDirect (FUN_6813d060)
// Address: 6813d060
// Size: 75 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, uint param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_setPropertyDirect(undefined4 *param_1,undefined4 param_2,undefined4 param_3,uint param_4)
{
  uint uVar1;
  int iVar2;
  
  if (param_4 == 0) {
    param_4 = 8;
  }
  uVar1 = crypto_decompileNode(param_4);
  iVar2 = 1 << ((byte)uVar1 & 0x1f);
  *param_1 = 0;
  param_1[4] = param_1;
  uVar1 = iVar2 - 1;
  param_1[6] = uVar1;
  uVar1 = iVar2 + 0xf + (int)param_1 & ~uVar1;
  param_1[2] = uVar1;
  param_1[3] = uVar1;
  param_1[1] = uVar1;
  param_1[5] = param_3;
  return 0;
}



// ============================================================
// Function: js_getSlotIndex (FUN_6813d0b0)
// Address: 6813d0b0
// Size: 297 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_getSlotIndex(int param_1,uint param_2)

{
  int iVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  int iVar8;
  
  puVar4 = *(undefined4 **)(param_1 + 0x10);
  puVar7 = puVar4;
  if ((uint)puVar4[2] < puVar4[3] + param_2) {
    do {
      puVar4 = (undefined4 *)*puVar7;
      if (puVar4 == (undefined4 *)0x0) {
        uVar6 = *(uint *)(param_1 + 0x14);
        if (uVar6 < param_2) {
          uVar3 = *(uint *)(param_1 + 0x18);
          if (uVar3 < 3) {
            iVar8 = 7 - uVar3;
          }
          else {
            iVar8 = uVar3 + 1;
          }
        }
        else {
          iVar8 = 0;
        }
        iVar1 = *(int *)(param_1 + 0x18) + 0x10 + iVar8;
        uVar3 = param_2;
        if (param_2 <= uVar6) {
          uVar3 = uVar6;
        }
        uVar3 = uVar3 + iVar1;
        puVar2 = &DAT_68196a08;
        for (puVar4 = DAT_68196a08; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)*puVar4) {
          uVar5 = puVar4[2] - (int)puVar4;
          if (iVar8 == 0) {
            if (uVar5 == uVar3) goto LAB_6813d13b;
          }
          else if ((uVar3 <= uVar5) && (uVar5 <= uVar6 + uVar3)) {
LAB_6813d13b:
            *puVar2 = *puVar4;
            goto LAB_6813d169;
          }
          puVar2 = puVar4;
        }
        puVar4 = (undefined4 *)js_runGC();
        if (puVar4 == (undefined4 *)0x0) {
          return 0;
        }
        puVar4[2] = (int)puVar4 + uVar3;
LAB_6813d169:
        *puVar4 = 0;
        *puVar7 = puVar4;
        uVar6 = *(uint *)(param_1 + 0x18);
        if (iVar8 == 0) {
          uVar6 = uVar6 + 0x10 + (int)puVar4 & ~uVar6;
          puVar4[3] = uVar6;
          puVar4[1] = uVar6;
        }
        else {
          uVar6 = ~(uVar6 | 3) & iVar1 + (int)puVar4;
          puVar4[3] = uVar6;
          puVar4[1] = uVar6;
          *(undefined4 **)(uVar6 - 4) = puVar7;
        }
      }
      *(undefined4 **)(param_1 + 0x10) = puVar4;
      puVar7 = puVar4;
    } while ((uint)puVar4[2] < puVar4[3] + param_2);
  }
  iVar8 = puVar4[3];
  puVar4[3] = iVar8 + param_2;
  return iVar8;
}



// ============================================================
// Function: js_resolveProperty (FUN_6813d1e0)
// Address: 6813d1e0
// Size: 254 bytes
// Params: int * param_1, int param_2, uint param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_resolveProperty(int *param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  int iVar2;
  void *_Dst;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  piVar3 = param_1;
  if ((uint)param_1[5] < param_3) {
    param_1 = *(int **)(param_2 + -4);
    piVar4 = (int *)*param_1;
  }
  else {
    piVar4 = (int *)*param_1;
    if (piVar4 != (int *)param_1[4]) {
      piVar5 = param_1 + 4;
      do {
        param_1 = piVar4;
        piVar4 = (int *)*param_1;
      } while (piVar4 != (int *)*piVar5);
    }
  }
  iVar1 = piVar4[1];
  uVar6 = piVar3[6];
  if (uVar6 < 3) {
    iVar7 = 3 - uVar6;
  }
  else {
    iVar7 = uVar6 - 3;
  }
  iVar7 = uVar6 + 0x14 + iVar7;
  uVar6 = iVar7 + param_3 + param_4;
  piVar5 = (int *)js_allocAtomBlock((int)piVar4,uVar6);
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  if (piVar5 != (int *)*param_1) {
    if ((int *)piVar3[4] == (int *)*param_1) {
      piVar3[4] = (int)piVar5;
    }
    iVar2 = *piVar5;
    if ((iVar2 != 0) && ((uint)piVar3[5] < (uint)(*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 4)))) {
      *(int **)(*(int *)(iVar2 + 4) + -4) = piVar5;
    }
    *param_1 = (int)piVar5;
  }
  piVar5[1] = ~(piVar3[6] | 3U) & iVar7 + (int)piVar5;
  piVar5[2] = uVar6 + (int)piVar5;
  _Dst = (void *)piVar5[1];
  piVar5[3] = (int)_Dst + param_3 + param_4 + piVar3[6] & ~piVar3[6];
  if (iVar1 - (int)piVar4 != (int)_Dst - (int)piVar5) {
    memmove(_Dst,(void *)((iVar1 - (int)piVar4) + (int)piVar5),param_3);
  }
  *(int **)(piVar5[1] + -4) = param_1;
  return piVar5[1];
}



// ============================================================
// Function: js_reallocObject (FUN_6813d2e0)
// Address: 6813d2e0
// Size: 106 bytes
// Params: int * param_1, void * param_2, uint param_3, int param_4
// Return: void *
// Calling convention: __stdcall
// ============================================================

void * js_reallocObject(int *param_1,void *param_2,uint param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  if ((uint)param_1[5] < param_3) {
    pvVar3 = (void *)js_resolveProperty(param_1,(int)param_2,param_3,param_4);
    return pvVar3;
  }
  iVar2 = param_1[4];
  pvVar3 = *(void **)(iVar2 + 0xc);
  uVar4 = param_1[6] + param_3 + param_4 & ~param_1[6];
  uVar1 = (int)pvVar3 + uVar4;
  if (*(uint *)(iVar2 + 8) < uVar1) {
    pvVar3 = (void *)js_getSlotIndex((int)param_1,uVar4);
  }
  else {
    *(uint *)(iVar2 + 0xc) = uVar1;
  }
  if (pvVar3 != (void *)0x0) {
    memcpy(pvVar3,param_2,param_3);
  }
  return pvVar3;
}



// ============================================================
// Function: javascript_resolveSlot (FUN_6813d350)
// Address: 6813d350
// Size: 79 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_resolveSlot(int param_1,int param_2)
{
  int *piVar1;
  int *piVar2;
  int *unaff_ESI;
  
  piVar1 = (int *)*unaff_ESI;
  if (piVar1 != (int *)0x0) {
    piVar2 = unaff_ESI;
    if (param_2 != 0) {
      do {
        *unaff_ESI = *piVar1;
        js_freeHandle();
        piVar1 = (int *)*unaff_ESI;
      } while (piVar1 != (int *)0x0);
      *(int **)(param_1 + 0x10) = unaff_ESI;
      return 0;
    }
    do {
      piVar2 = (int *)*piVar2;
    } while (*piVar2 != 0);
    *piVar2 = (int)DAT_68196a08;
    DAT_68196a08 = piVar1;
    *unaff_ESI = 0;
    *(int **)(param_1 + 0x10) = unaff_ESI;
  }
  return 0;
}



// ============================================================
// Function: js_getPrototype (FUN_6813d3b0)
// Address: 6813d3b0
// Size: 74 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_getPrototype(int *param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = param_1;
  if (param_1 != (int *)0x0) {
    while ((uint)(piVar1[3] - piVar1[1]) < (uint)(param_2 - piVar1[1])) {
      piVar1 = (int *)*piVar1;
      if (piVar1 == (int *)0x0) {
        return 0;
      }
    }
    piVar1[3] = param_2 + param_1[6] & ~param_1[6];
    javascript_resolveSlot((int)param_1,1);
  }
  return 0;
}



// ============================================================
// Function: javascript_getSlotByName (FUN_6813d400)
// Address: 6813d400
// Size: 122 bytes
// Params: int * param_1, int param_2, uint param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_getSlotByName(int *param_1,int param_2,uint param_3)
{
  int iVar1;
  int *piVar2;
  int *piVar3;
  int *piVar4;
  
  if ((uint)param_1[5] < param_3) {
    piVar4 = *(int **)(param_2 + -4);
    piVar3 = (int *)*piVar4;
  }
  else {
    piVar2 = (int *)*param_1;
    piVar4 = param_1;
    while (piVar3 = piVar2, piVar3 != (int *)0x0) {
      if (piVar3[3] == (param_1[6] + param_2 + param_3 & ~param_1[6])) {
        if (piVar3[1] != param_2) {
          piVar3[3] = param_2;
          return 0;
        }
        break;
      }
      piVar4 = piVar3;
      piVar2 = (int *)*piVar3;
    }
  }
  if ((int *)param_1[4] == piVar3) {
    param_1[4] = (int)param_1;
  }
  iVar1 = *piVar3;
  *piVar4 = iVar1;
  if ((iVar1 != 0) && ((uint)param_1[5] < (uint)(*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 4)))) {
    *(int **)(*(int *)(iVar1 + 4) + -4) = piVar4;
  }
  js_freeHandle();
  return 0;
}



// ============================================================
// Function: javascript_resizeSlotTable (FUN_6813d480)
// Address: 6813d480
// Size: 20 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_resizeSlotTable(int param_1)
{
  javascript_resolveSlot(param_1,0);
  return 0;
}



// ============================================================
// Function: js_getPrototypeChain (FUN_6813d4a0)
// Address: 6813d4a0
// Size: 20 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_getPrototypeChain(int param_1)
{
  javascript_resolveSlot(param_1,1);
  return 0;
}



// ============================================================
// Function: javascript_freeArenaPool (FUN_6813d4c0)
// Address: 6813d4c0
// Size: 36 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_freeArenaPool(void)
{
  undefined4 *puVar1;
  
  puVar1 = DAT_68196a08;
  DAT_68196a08 = (undefined4 *)0x0;
  while (puVar1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar1;
    js_freeHandle();
  }
  return 0;
}



// ============================================================
// Function: javascript_arenaPoolReserve (FUN_6813d4f0)
// Address: 6813d4f0
// Size: 16 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_arenaPoolReserve(void)
{
  js_freeHandle();
  return 0;
}



// ============================================================
// Function: javascript_arenaPoolAlloc (FUN_6813d500)
// Address: 6813d500
// Size: 13 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_arenaPoolAlloc(undefined4 param_1,int param_2)

{
  return *(undefined4 *)(param_2 + 4);
}



// ============================================================
// Function: javascript_arenaPoolFree (FUN_6813d510)
// Address: 6813d510
// Size: 13 bytes
// Params: undefined4 param_1, uint param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint javascript_arenaPoolFree(undefined4 param_1,uint param_2)

{
  return param_2 >> 2;
}



// ============================================================
// Function: javascript_arenaPoolGrow (FUN_6813d520)
// Address: 6813d520
// Size: 21 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool javascript_arenaPoolGrow(undefined4 param_1,int param_2,int param_3)

{
  return *(int *)(param_2 + 4) == param_3;
}



// ============================================================
// Function: javascript_arenaPoolShrink (FUN_6813d540)
// Address: 6813d540
// Size: 30 bytes
// Params: int param_1, void * param_2, void * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_arenaPoolShrink(int param_1,void *param_2,void *param_3)
{
  memcpy(param_3,param_2,*(size_t *)(param_1 + 0xc));
  return 0;
}



// ============================================================
// Function: javascript_arenaPoolGetInfo (FUN_6813d560)
// Address: 6813d560
// Size: 28 bytes
// Params: int param_1, void * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_arenaPoolGetInfo(int param_1,void *param_2)
{
  memset(param_2,0,*(size_t *)(param_1 + 0xc));
  return 0;
}



// ============================================================
// Function: javascript_getDefaultAllocator (FUN_6813d580)
// Address: 6813d580
// Size: 6 bytes
// Return: undefined * *
// Calling convention: __stdcall
// ============================================================

undefined ** javascript_getDefaultAllocator(void)

{
  return &PTR_FUN_6817f3a0;
}



// ============================================================
// Function: javascript_initHashTable (FUN_6813d590)
// Address: 6813d590
// Size: 156 bytes
// Params: undefined4 * param_1, undefined4 * param_2, undefined4 param_3, int param_4, uint param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_initHashTable(undefined4 *param_1,undefined4 *param_2,undefined4 param_3,int param_4,uint param_5)

{
  uint uVar1;
  size_t _Size;
  void *_Dst;
  uint uVar2;
  
  *param_1 = param_2;
  param_1[1] = param_3;
  if (param_5 < 0x10) {
    param_5 = 0x10;
  }
  uVar1 = crypto_decompileNode(param_5);
  uVar2 = 1 << ((byte)uVar1 & 0x1f);
  if (0xffffff < uVar2) {
    return 0;
  }
  param_1[3] = param_4;
  _Size = param_4 * uVar2;
  *(short *)(param_1 + 2) = 0x20 - (short)uVar1;
  *(undefined2 *)((int)param_1 + 10) = 0x40c0;
  param_1[5] = 0;
  param_1[4] = 0;
  param_1[6] = 0;
  _Dst = (void *)(*(code *)*param_2)(param_1,_Size);
  param_1[7] = _Dst;
  if (_Dst == (void *)0x0) {
    return 0;
  }
  memset(_Dst,0,_Size);
  return 1;
}



// ============================================================
// Function: javascript_freeHashTable (FUN_6813d630)
// Address: 6813d630
// Size: 95 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_freeHashTable(int *param_1)
{
  int iVar1;
  uint *puVar2;
  uint *puVar3;
  
  (**(code **)(*param_1 + 0x1c))(param_1);
  iVar1 = param_1[3];
  puVar2 = (uint *)param_1[7];
  puVar3 = (uint *)((1 << (0x20U - (char)(short)param_1[2] & 0x1f)) * iVar1 + (int)puVar2);
  for (; puVar2 < puVar3; puVar2 = (uint *)((int)puVar2 + iVar1)) {
    if (1 < *puVar2) {
      (**(code **)(*param_1 + 0x18))(param_1,puVar2);
    }
  }
  (**(code **)(*param_1 + 4))(param_1,param_1[7]);
  return 0;
}



// ============================================================
// Function: js_findPropertySlot (FUN_6813d690)
// Address: 6813d690
// Size: 266 bytes
// Params: undefined4 param_1, uint param_2, int param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * js_findPropertySlot(undefined4 param_1,uint param_2,int param_3)

{
  code *pcVar1;
  int iVar2;
  uint uVar3;
  byte bVar4;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  int *unaff_EDI;
  uint *local_8;
  
  bVar4 = (byte)(short)unaff_EDI[2];
  uVar7 = param_2 >> (bVar4 & 0x1f);
  puVar9 = (uint *)(unaff_EDI[3] * uVar7 + unaff_EDI[7]);
  if ((*puVar9 != 0) &&
     ((pcVar1 = *(code **)(*unaff_EDI + 0x10), (*puVar9 & 0xfffffffe) != param_2 ||
      (iVar2 = (*pcVar1)(), iVar2 == 0)))) {
    bVar5 = 0x20 - (char)(short)unaff_EDI[2];
    uVar6 = (param_2 << (bVar5 & 0x1f)) >> (bVar4 & 0x1f) | 1;
    uVar3 = (1 << (bVar5 & 0x1f)) - 1;
    local_8 = puVar9;
    if ((*puVar9 != 1) && (local_8 = (uint *)0x0, param_3 == 1)) {
      *puVar9 = *puVar9 | 1;
    }
    uVar8 = uVar7 - uVar6 & uVar3;
    puVar9 = (uint *)(unaff_EDI[3] * uVar8 + unaff_EDI[7]);
    uVar7 = *puVar9;
    while (uVar7 != 0) {
      if (((*puVar9 & 0xfffffffe) == param_2) && (iVar2 = (*pcVar1)(), iVar2 != 0)) {
        return puVar9;
      }
      if (*puVar9 == 1) {
        if (local_8 == (uint *)0x0) {
          local_8 = puVar9;
        }
      }
      else if (param_3 == 1) {
        *puVar9 = *puVar9 | 1;
      }
      uVar8 = uVar8 - uVar6 & uVar3;
      puVar9 = (uint *)(unaff_EDI[3] * uVar8 + unaff_EDI[7]);
      uVar7 = *puVar9;
    }
    if ((local_8 != (uint *)0x0) && (param_3 == 1)) {
      return local_8;
    }
  }
  return puVar9;
}



// ============================================================
// Function: javascript_hashTableGrow (FUN_6813d7a0)
// Address: 6813d7a0
// Size: 230 bytes
// Params: undefined4 param_1, short param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall javascript_hashTableGrow(undefined4 param_1,short param_2)

{
  int local_14;
  int iVar1;
  code *pcVar2;
  code *pcVar3;
  int *in_EAX;
  int iVar4;
  uint uVar5;
  void *_Dst;
  undefined4 uVar6;
  uint *puVar7;
  short sVar8;
  uint *puVar9;
  int *piVar10;
  
  sVar8 = 0x20 - (short)in_EAX[2];
  iVar4 = 1 << ((byte)sVar8 & 0x1f);
  sVar8 = param_2 + sVar8;
  uVar5 = 1 << ((byte)sVar8 & 0x1f);
  if (0xffffff < uVar5) {
    return 0;
  }
  iVar1 = in_EAX[3];
  _Dst = (void *)(**(code **)*in_EAX)();
  if (_Dst == (void *)0x0) {
    return 0;
  }
  in_EAX[6] = in_EAX[6] + 1;
  *(short *)(in_EAX + 2) = 0x20 - sVar8;
  in_EAX[5] = 0;
  memset(_Dst,0,iVar1 * uVar5);
  puVar9 = (uint *)in_EAX[7];
  in_EAX[7] = (int)_Dst;
  pcVar2 = *(code **)(*in_EAX + 8);
  pcVar3 = *(code **)(*in_EAX + 0x14);
  for (; iVar4 != 0; iVar4 = iVar4 + -1) {
    if (1 < *puVar9) {
      *puVar9 = *puVar9 & 0xfffffffe;
      piVar10 = in_EAX;
      puVar7 = puVar9;
      uVar6 = (*pcVar2)();
      puVar7 = js_findPropertySlot(uVar6,(uint)piVar10,(int)puVar7);
      (*pcVar3)();
      *puVar7 = *puVar9;
    }
    puVar9 = (uint *)((int)puVar9 + iVar1);
  }
  (**(code **)(*in_EAX + 4))();
  return 1;
}



// ============================================================
// Function: js_enumerateProperties (FUN_6813d890)
// Address: 6813d890
// Size: 63 bytes
// Params: int * param_1, uint * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_enumerateProperties(int *param_1,uint *param_2)
{
  uint uVar1;
  
  uVar1 = *param_2;
  (**(code **)(*param_1 + 0x18))(param_1,param_2);
  if ((uVar1 & 1) != 0) {
    *param_2 = 1;
    param_1[5] = param_1[5] + 1;
    param_1[4] = param_1[4] + -1;
    return 0;
  }
  *param_2 = 0;
  param_1[4] = param_1[4] + -1;
  return 0;
}



// ============================================================
// Function: javascript_hashTableIterate (FUN_6813d8d0)
// Address: 6813d8d0
// Size: 240 bytes
// Params: int * param_1, undefined * param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_hashTableIterate(int *param_1,undefined *param_2,undefined4 param_3)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  undefined4 extraout_ECX;
  uint uVar6;
  uint *puVar7;
  uint *puVar8;
  
  piVar3 = param_1;
  iVar1 = param_1[3];
  puVar8 = (uint *)param_1[7];
  uVar6 = 1 << (0x20U - (char)(short)param_1[2] & 0x1f);
  param_1 = (int *)0x0;
  bVar2 = false;
  puVar7 = (uint *)(uVar6 * iVar1 + (int)puVar8);
  if (puVar8 < puVar7) {
    piVar5 = (int *)0x0;
    do {
      if (1 < *puVar8) {
        uVar4 = (*(code *)param_2)(piVar3,puVar8,piVar5,param_3);
        piVar5 = (int *)((int)param_1 + 1);
        if ((uVar4 & 2) != 0) {
          js_enumerateProperties(piVar3,puVar8);
          bVar2 = true;
        }
        param_1 = piVar5;
        if ((uVar4 & 1) != 0) break;
      }
      puVar8 = (uint *)((int)puVar8 + iVar1);
    } while (puVar8 < puVar7);
    if ((!bVar2) ||
       (((uint)piVar3[5] < uVar6 >> 2 &&
        ((uVar6 < 0x11 || (*(byte *)((int)piVar3 + 0xb) * uVar6 >> 8 < (uint)piVar3[4])))))) {
      return (int)piVar5;
    }
    uVar6 = piVar3[4] + ((uint)piVar3[4] >> 1);
    if (uVar6 < 0x10) {
      uVar6 = 0x10;
    }
    uVar6 = crypto_decompileNode(uVar6);
    javascript_hashTableGrow(extraout_ECX,(short)uVar6 + -0x20 + (short)piVar3[2]);
  }
  return (int)param_1;
}



// ============================================================
// Function: javascript_hashTableCreate (FUN_6813d9c0)
// Address: 6813d9c0
// Size: 63 bytes
// Params: undefined4 * param_1, undefined4 param_2, int param_3, uint param_4
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * javascript_hashTableCreate(undefined4 *param_1,undefined4 param_2,int param_3,uint param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)js_runGC();
  if (puVar1 != (undefined4 *)0x0) {
    iVar2 = javascript_initHashTable(puVar1,param_1,param_2,param_3,param_4);
    if (iVar2 != 0) {
      return puVar1;
    }
    js_freeHandle();
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: javascript_hashTableDestroy (FUN_6813da00)
// Address: 6813da00
// Size: 24 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_hashTableDestroy(int *param_1)
{
  javascript_freeHashTable(param_1);
  js_freeHandle();
  return 0;
}



// ============================================================
// Function: js_getPropertySlot (FUN_6813da20)
// Address: 6813da20
// Size: 300 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * js_getPropertySlot(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(*param_1 + 0xc))(param_1,param_2);
  uVar4 = iVar1 * -0x61c88647;
  if (uVar4 < 2) {
    uVar4 = uVar4 - 2;
  }
  uVar4 = uVar4 & 0xfffffffe;
  if (param_3 == 0) {
    puVar2 = js_findPropertySlot(param_2,uVar4,0);
  }
  else {
    if (param_3 != 1) {
      if (param_3 == 2) {
        puVar2 = js_findPropertySlot(param_2,uVar4,2);
        if (1 < *puVar2) {
          js_enumerateProperties(param_1,puVar2);
          uVar4 = 1 << (0x20U - (char)(short)param_1[2] & 0x1f);
          if ((0x10 < uVar4) &&
             (uVar4 = *(byte *)((int)param_1 + 0xb) * uVar4 >> 8, (uint)param_1[4] <= uVar4)) {
            javascript_hashTableGrow(uVar4,-1);
          }
        }
      }
      return (uint *)0x0;
    }
    uVar3 = 1 << (0x20U - (char)(short)param_1[2] & 0x1f);
    if (*(byte *)((int)param_1 + 10) * uVar3 >> 8 <= (uint)(param_1[4] + param_1[5])) {
      iVar1 = javascript_hashTableGrow(uVar3 >> 2,(ushort)((uint)param_1[5] < uVar3 >> 2));
      if ((iVar1 == 0) && (param_1[5] + param_1[4] == uVar3 - 1)) {
        return (uint *)0x0;
      }
    }
    puVar2 = js_findPropertySlot(param_2,uVar4,1);
    if (*puVar2 < 2) {
      if (*puVar2 == 1) {
        param_1[5] = param_1[5] + -1;
        uVar4 = uVar4 | 1;
      }
      if (*(code **)(*param_1 + 0x20) != (code *)0x0) {
        (**(code **)(*param_1 + 0x20))(param_1,puVar2,param_2);
      }
      *puVar2 = uVar4;
      param_1[4] = param_1[4] + 1;
      return puVar2;
    }
  }
  return puVar2;
}



// ============================================================
// Function: javascript_hashTableInsert (FUN_6813db50)
// Address: 6813db50
// Size: 134 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_hashTableInsert(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
            undefined4 param_5)

{
  undefined4 uVar1;
  
  memset(param_2,0,0x9c);
  param_2[1] = 0;
  param_2[2] = 0;
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  *param_2 = 1;
  param_2[7] = *(undefined4 *)(*(int *)(param_1 + 0x48) + 0xc);
  param_2[8] = *(undefined4 *)(*(int *)(param_1 + 100) + 0xc);
  uVar1 = *(undefined4 *)(*(int *)(param_1 + 0x80) + 0xc);
  param_2[0x11] = param_3;
  param_2[9] = uVar1;
  param_2[0x13] = param_4;
  param_2[0x12] = param_4;
  param_2[0x15] = 0;
  param_2[0x16] = 0;
  param_2[0x17] = 0;
  param_2[0x10] = param_2 + 0xd;
  param_2[0x14] = param_5;
  param_2[0x1c] = 0x3f;
  return 1;
}



// ============================================================
// Function: javascript_hashTableLookup (FUN_6813dbe0)
// Address: 6813dbe0
// Size: 198 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_hashTableLookup(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  iVar1 = *(int *)(param_2 + 0x1c);
  iVar2 = *(int *)(param_1 + 0x48);
  if ((iVar2 == param_1 + 0x38) ||
     ((uint)(*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 4)) < (uint)(iVar1 - *(int *)(iVar2 + 4)))) {
    js_getPrototype((int *)(param_1 + 0x38),iVar1);
  }
  else {
    *(uint *)(iVar2 + 0xc) = iVar1 + *(uint *)(param_1 + 0x50) & ~*(uint *)(param_1 + 0x50);
  }
  iVar1 = *(int *)(param_2 + 0x20);
  iVar2 = *(int *)(param_1 + 100);
  if ((iVar2 == param_1 + 0x54) ||
     ((uint)(*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 4)) < (uint)(iVar1 - *(int *)(iVar2 + 4)))) {
    js_getPrototype((int *)(param_1 + 0x54),iVar1);
  }
  else {
    *(uint *)(iVar2 + 0xc) = iVar1 + *(uint *)(param_1 + 0x6c) & ~*(uint *)(param_1 + 0x6c);
  }
  iVar1 = *(int *)(param_2 + 0x24);
  piVar3 = *(int **)(param_1 + 0x80);
  if ((piVar3 != (int *)(param_1 + 0x70)) &&
     ((uint)(iVar1 - piVar3[1]) <= (uint)(piVar3[3] - piVar3[1]))) {
    piVar3[3] = iVar1 + *(uint *)(param_1 + 0x88) & ~*(uint *)(param_1 + 0x88);
    return 0;
  }
  js_getPrototype((int *)(param_1 + 0x70),iVar1);
  return 0;
}



// ============================================================
// Function: javascript_hashTableRemove (FUN_6813dcb0)
// Address: 6813dcb0
// Size: 303 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_hashTableRemove(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int in_EAX;
  void *pvVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  puVar1 = *(undefined4 **)(param_1 + 0x40);
  pvVar3 = (void *)*puVar1;
  uVar7 = puVar1[1];
  iVar5 = puVar1[2] - (int)pvVar3;
  if ((uint)(puVar1[2] + param_2) <= uVar7) {
    return iVar5;
  }
  if (param_2 + iVar5 < 0x101) {
    param_2 = 0x100;
  }
  else {
    uVar4 = crypto_decompileNode(param_2 + iVar5);
    param_2 = 1 << ((byte)uVar4 & 0x1f);
  }
  if (pvVar3 == (void *)0x0) {
    iVar2 = *(int *)(in_EAX + 0x48);
    uVar4 = param_2 + *(uint *)(in_EAX + 0x50) & ~*(uint *)(in_EAX + 0x50);
    pvVar3 = *(void **)(iVar2 + 0xc);
    uVar7 = (int)pvVar3 + uVar4;
    if (*(uint *)(iVar2 + 8) < uVar7) {
      pvVar3 = (void *)js_getSlotIndex(in_EAX + 0x38,uVar4);
    }
    else {
      *(uint *)(iVar2 + 0xc) = uVar7;
    }
    goto LAB_6813dda2;
  }
  iVar2 = *(int *)(in_EAX + 0x48);
  uVar7 = uVar7 - (int)pvVar3;
  iVar6 = param_2 - uVar7;
  if (*(int *)(iVar2 + 0xc) ==
      (*(uint *)(in_EAX + 0x50) + uVar7 & ~*(uint *)(in_EAX + 0x50)) + (int)pvVar3) {
    uVar4 = (*(uint *)(in_EAX + 0x50) + uVar7 + iVar6 & ~*(uint *)(in_EAX + 0x50)) + (int)pvVar3;
    if (uVar4 <= *(uint *)(iVar2 + 8)) {
      *(uint *)(iVar2 + 0xc) = uVar4;
      goto LAB_6813dda2;
    }
    if (pvVar3 == *(void **)(iVar2 + 4)) {
      pvVar3 = (void *)js_resolveProperty((int *)(in_EAX + 0x38),(int)pvVar3,uVar7,iVar6);
      goto LAB_6813dda2;
    }
  }
  pvVar3 = js_reallocObject((int *)(in_EAX + 0x38),pvVar3,uVar7,iVar6);
LAB_6813dda2:
  if (pvVar3 != (void *)0x0) {
    **(undefined4 **)(param_1 + 0x40) = pvVar3;
    *(int *)(*(int *)(param_1 + 0x40) + 4) = param_2 + (int)pvVar3;
    *(int *)(*(int *)(param_1 + 0x40) + 8) = iVar5 + (int)pvVar3;
    return iVar5;
  }
  xtra_reportError(in_EAX);
  return -1;
}



// ============================================================
// Function: javascript_hashTableResize (FUN_6813dde0)
// Address: 6813dde0
// Size: 154 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall javascript_hashTableResize(undefined4 param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint unaff_EBX;
  int iVar4;
  int unaff_EDI;
  undefined1 local_14 [12];
  uint local_8;
  
  iVar2 = **(int **)(unaff_EDI + 0x40);
  iVar4 = (uint)*(byte *)(iVar2 + param_2) * 0x10;
  iVar3 = (int)(char)(&DAT_68193cb9)[iVar4];
  if (iVar3 < 0) {
    iVar3 = CONCAT11(*(undefined1 *)(iVar2 + 1 + param_2),*(undefined1 *)(iVar2 + 2 + param_2)) + 2;
  }
  piVar1 = (int *)(unaff_EDI + 0x60);
  *piVar1 = *piVar1 - iVar3;
  if (*piVar1 < 0) {
    runtime_snprintf(local_14,0xc,"%d");
    xtra_invokeMethod(unaff_EBX,xtra_getErrorString,0,0x10);
  }
  *(int *)(unaff_EDI + 0x60) = *(int *)(unaff_EDI + 0x60) + (int)(char)(&DAT_68193cba)[iVar4];
  if (*(uint *)(unaff_EDI + 100) < *(uint *)(unaff_EDI + 0x60)) {
    *(uint *)(unaff_EDI + 100) = *(uint *)(unaff_EDI + 0x60);
  }
  return 0;
}



// ============================================================
// Function: js_setPropertyFlag (FUN_6813de80)
// Address: 6813de80
// Size: 61 bytes
// Params: undefined4 param_1, int param_2, undefined1 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_setPropertyFlag(undefined4 param_1,int param_2,undefined1 param_3)

{
  int local_14;
  int *piVar1;
  undefined1 *puVar2;
  int iVar3;
  
  iVar3 = javascript_hashTableRemove(param_2,1);
  if (-1 < iVar3) {
    puVar2 = *(undefined1 **)(*(int *)(param_2 + 0x40) + 8);
    *puVar2 = param_3;
    piVar1 = (int *)(*(int *)(param_2 + 0x40) + 8);
    *piVar1 = *piVar1 + 1;
    javascript_hashTableResize(puVar2,iVar3);
  }
  return iVar3;
}



// ============================================================
// Function: js_setMultipleFlags (FUN_6813dec0)
// Address: 6813dec0
// Size: 76 bytes
// Params: undefined4 param_1, int param_2, undefined1 param_3, undefined1 param_4, undefined1 param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_setMultipleFlags(undefined4 param_1,int param_2,undefined1 param_3,undefined1 param_4,
                undefined1 param_5)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 extraout_ECX;
  
  iVar2 = javascript_hashTableRemove(param_2,3);
  if (-1 < iVar2) {
    puVar1 = *(undefined1 **)(*(int *)(param_2 + 0x40) + 8);
    *puVar1 = param_3;
    puVar1[1] = param_4;
    puVar1[2] = param_5;
    *(undefined1 **)(*(int *)(param_2 + 0x40) + 8) = puVar1 + 3;
    javascript_hashTableResize(CONCAT31((int3)((uint)extraout_ECX >> 8),param_5),iVar2);
  }
  return iVar2;
}



// ============================================================
// Function: javascript_hashTableCount (FUN_6813df10)
// Address: 6813df10
// Size: 94 bytes
// Params: undefined4 param_1, int param_2, undefined1 param_3, size_t param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_hashTableCount(undefined4 param_1,int param_2,undefined1 param_3,size_t param_4)

{
  undefined1 *puVar1;
  int iVar2;
  undefined4 extraout_ECX;
  
  iVar2 = javascript_hashTableRemove(param_2,param_4 + 1);
  if (-1 < iVar2) {
    puVar1 = *(undefined1 **)(*(int *)(param_2 + 0x40) + 8);
    *puVar1 = param_3;
    memset(puVar1 + 1,0,param_4);
    *(undefined1 **)(*(int *)(param_2 + 0x40) + 8) = puVar1 + param_4 + 1;
    javascript_hashTableResize(extraout_ECX,iVar2);
  }
  return iVar2;
}



// ============================================================
// Function: javascript_hashTableEntrySize (FUN_6813df70)
// Address: 6813df70
// Size: 23 bytes
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * javascript_hashTableEntrySize(void)

{
  int in_EAX;
  
  if (*(int **)(in_EAX + 8) == (int *)0x0) {
    return "script";
  }
  return (&PTR_s_block_68193b38)[**(int **)(in_EAX + 8)];
}



// ============================================================
// Function: js_getClassId (FUN_6813df90)
// Address: 6813df90
// Size: 34 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_getClassId(uint param_1)
{
  javascript_hashTableEntrySize();
  xtra_invokeMethod(param_1,xtra_getErrorString,0,0x11);
  return 0;
}



// ============================================================
// Function: javascript_objectSetSlot (FUN_6813dfc0)
// Address: 6813dfc0
// Size: 217 bytes
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool javascript_objectSetSlot(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int *in_EAX;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  iVar1 = *in_EAX;
  if (*(int *)(iVar1 + 4) < -1) {
    iVar5 = 1;
    bVar6 = 0 < *(int *)(*(int *)(iVar1 + 8) + 4);
  }
  else {
    if (*(int *)(iVar1 + 4) < 2) {
      return false;
    }
    iVar5 = 0;
    bVar6 = *(int *)(*(int *)(iVar1 + 0xc) + 4) < 0;
  }
  iVar4 = 1 - iVar5;
  if (bVar6) {
    iVar2 = *(int *)(iVar1 + 8 + iVar4 * 4);
    iVar3 = *(int *)(iVar2 + 8 + iVar5 * 4);
    *in_EAX = iVar3;
    *(undefined4 *)(iVar1 + 8 + iVar4 * 4) = *(undefined4 *)(iVar3 + 8 + iVar5 * 4);
    *(int *)(iVar3 + 8 + iVar5 * 4) = iVar1;
    *(undefined4 *)(iVar2 + 8 + iVar5 * 4) = *(undefined4 *)(iVar3 + 8 + iVar4 * 4);
    *(int *)(iVar3 + 8 + iVar4 * 4) = iVar2;
    *(uint *)(*(int *)(iVar3 + 8) + 4) =
         -(*(uint *)(iVar3 + 4) & ((int)*(uint *)(iVar3 + 4) < 1) - 1);
    *(uint *)(*(int *)(iVar3 + 0xc) + 4) =
         -(*(uint *)(iVar3 + 4) & (-1 < (int)*(uint *)(iVar3 + 4)) - 1);
    *(undefined4 *)(iVar3 + 4) = 0;
    return true;
  }
  iVar2 = *(int *)(iVar1 + 8 + iVar4 * 4);
  *in_EAX = iVar2;
  *(undefined4 *)(iVar1 + 8 + iVar4 * 4) = *(undefined4 *)(iVar2 + 8 + iVar5 * 4);
  *(int *)(iVar2 + 8 + iVar5 * 4) = iVar1;
  iVar3 = *(int *)(iVar2 + 4);
  iVar4 = iVar3 + -1;
  if (iVar5 != 0) {
    iVar4 = iVar3 + 1;
  }
  *(int *)(iVar2 + 4) = iVar4;
  *(int *)(iVar1 + 4) = -iVar4;
  return iVar3 != 0;
}



// ============================================================
// Function: javascript_objectResolveSlot (FUN_6813e0a0)
// Address: 6813e0a0
// Size: 265 bytes
// Params: int * param_1, int * param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_objectResolveSlot(int *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  int *piVar5;
  int iVar6;
  undefined3 extraout_var;
  uint uVar7;
  
  piVar5 = (int *)*param_2;
  if (piVar5 == (int *)0x0) {
    iVar6 = param_1[1];
    piVar5 = *(int **)(iVar6 + 0x8c);
    if (piVar5 == (int *)0x0) {
      iVar3 = *param_1;
      iVar2 = *(int *)(iVar3 + 0x80);
      uVar7 = *(uint *)(iVar3 + 0x88) + 0x10 & ~*(uint *)(iVar3 + 0x88);
      piVar5 = *(int **)(iVar2 + 0xc);
      uVar1 = (int)piVar5 + uVar7;
      if (*(uint *)(iVar2 + 8) < uVar1) {
        piVar5 = (int *)js_getSlotIndex(iVar3 + 0x70,uVar7);
      }
      else {
        *(uint *)(iVar2 + 0xc) = uVar1;
      }
      if (piVar5 == (int *)0x0) {
        xtra_reportError(*param_1);
        return 0;
      }
    }
    else {
      *(int *)(iVar6 + 0x8c) = piVar5[2];
    }
    iVar3 = param_1[2];
    piVar5[1] = 0;
    piVar5[3] = 0;
    piVar5[2] = 0;
    *piVar5 = iVar3;
    *(int *)(iVar6 + 0x94) = *(int *)(iVar6 + 0x94) + 1;
    param_1[3] = (int)piVar5;
    *param_2 = (int)piVar5;
    return 1;
  }
  if (param_1[2] == *piVar5) {
    param_1[3] = (int)piVar5;
    return 0;
  }
  if (param_1[2] < *piVar5) {
    iVar6 = javascript_objectResolveSlot(param_1,piVar5 + 2);
    iVar6 = -iVar6;
  }
  else {
    iVar6 = javascript_objectResolveSlot(param_1,piVar5 + 3);
  }
  if (param_1[3] == 0) {
    return 0;
  }
  piVar5[1] = piVar5[1] + iVar6;
  if ((iVar6 != 0) && (piVar5[1] != 0)) {
    bVar4 = javascript_objectSetSlot();
    return 1 - CONCAT31(extraout_var,bVar4);
  }
  return 0;
}



// ============================================================
// Function: javascript_objectDefineSlot (FUN_6813e1b0)
// Address: 6813e1b0
// Size: 88 bytes
// Params: int param_1, uint param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x6813e1fc) */

undefined4 __fastcall javascript_objectDefineSlot(int param_1,uint param_2)

{
  int in_EAX;
  int *unaff_ESI;
  uint local_14 [2];
  int local_c;
  uint local_8;
  
  local_c = *unaff_ESI + param_1;
  local_8 = 0;
  local_14[0] = param_2;
  javascript_objectResolveSlot((int *)local_14,(int *)(in_EAX + 0x88));
  if (local_8 == 0) {
    return 0;
  }
  unaff_ESI[3] = local_8 | 1;
  return 1;
}



// ============================================================
// Function: js_setObjectSlot (FUN_6813e210)
// Address: 6813e210
// Size: 421 bytes
// Params: byte * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_setObjectSlot(byte *param_1,int param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int unaff_EBX;
  int *piVar6;
  uint unaff_EDI;
  
  uVar4 = *(uint *)(unaff_EBX + 0x90);
  if (uVar4 + 1 == 0) {
    js_getClassId(unaff_EDI);
    return 0;
  }
  if ((uVar4 & uVar4 - 1) != 0) goto LAB_6813e306;
  pvVar1 = *(void **)(unaff_EBX + 0x84);
  if (pvVar1 == (void *)0x0) {
    iVar2 = *(int *)(unaff_EDI + 0x80);
    uVar5 = *(uint *)(unaff_EDI + 0x88) + 0x1000 & ~*(uint *)(unaff_EDI + 0x88);
    pvVar1 = *(void **)(iVar2 + 0xc);
    uVar3 = (int)pvVar1 + uVar5;
    if (*(uint *)(iVar2 + 8) < uVar3) {
      pvVar1 = (void *)js_getSlotIndex(unaff_EDI + 0x70,uVar5);
    }
    else {
      *(uint *)(iVar2 + 0xc) = uVar3;
    }
    goto LAB_6813e2f9;
  }
  if (uVar4 < 0x100) goto LAB_6813e306;
  iVar2 = *(int *)(unaff_EDI + 0x80);
  uVar3 = uVar4 * 0x10;
  if (*(int *)(iVar2 + 0xc) ==
      (*(uint *)(unaff_EDI + 0x88) + uVar3 & ~*(uint *)(unaff_EDI + 0x88)) + (int)pvVar1) {
    uVar5 = (*(uint *)(unaff_EDI + 0x88) + uVar4 * 0x20 & ~*(uint *)(unaff_EDI + 0x88)) +
            (int)pvVar1;
    if (*(uint *)(iVar2 + 8) < uVar5) {
      if (pvVar1 != *(void **)(iVar2 + 4)) goto LAB_6813e2f1;
      pvVar1 = (void *)js_resolveProperty((int *)(unaff_EDI + 0x70),(int)pvVar1,uVar3,uVar3);
    }
    else {
      *(uint *)(iVar2 + 0xc) = uVar5;
    }
  }
  else {
LAB_6813e2f1:
    pvVar1 = js_reallocObject((int *)(unaff_EDI + 0x70),pvVar1,uVar3,uVar3);
  }
LAB_6813e2f9:
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  *(void **)(unaff_EBX + 0x84) = pvVar1;
LAB_6813e306:
  *(uint *)(unaff_EBX + 0x90) = uVar4 + 1;
  piVar6 = (int *)(uVar4 * 0x10 + *(int *)(unaff_EBX + 0x84));
  *piVar6 = (int)param_1 - **(int **)(unaff_EBX + 0x40);
  iVar2 = param_2 - **(int **)(unaff_EBX + 0x40);
  piVar6[2] = iVar2;
  piVar6[1] = iVar2;
  if ((*(uint *)(&DAT_68193cbc + (uint)*param_1 * 0x10) & 0x4000) == 0) {
    if (param_3 == 0) {
      piVar6[3] = 1;
    }
    else {
      iVar2 = javascript_objectDefineSlot(param_3,unaff_EDI);
      if (iVar2 == 0) {
        return 0;
      }
    }
  }
  else {
    if ((param_3 != 0) && (0x3fffffff < param_3)) {
      js_getClassId(unaff_EDI);
      return 0;
    }
    piVar6[3] = param_3 * 2;
  }
  if (0xfffe < uVar4) {
    uVar4 = 0xffff;
  }
  *(char *)(param_2 + 1) = (char)(uVar4 >> 8);
  *(char *)(param_2 + 2) = (char)uVar4;
  return 1;
}



// ============================================================
// Function: javascript_objectConfigureSlot (FUN_6813e3c0)
// Address: 6813e3c0
// Size: 431 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_objectConfigureSlot(void)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  int in_EAX;
  uint uVar4;
  int iVar5;
  byte *pbVar6;
  byte *local_8;
  
  pbVar6 = (byte *)**(undefined4 **)(in_EAX + 0x40);
  pbVar3 = (byte *)(*(undefined4 **)(in_EAX + 0x40))[2];
  do {
    if (pbVar3 <= pbVar6) {
      return 1;
    }
    local_8 = (byte *)(int)(char)(&DAT_68193cb8)[(uint)*pbVar6 * 0x10];
    uVar4 = *(uint *)(&DAT_68193cbc + (uint)*pbVar6 * 0x10) & 0xf;
    if (uVar4 == 1) {
      iVar5 = js_setObjectSlot(pbVar6,(int)pbVar6,(int)(short)((ushort)pbVar6[1] << 8) | (uint)pbVar6[2]
                          );
      if (iVar5 == 0) {
        return 0;
      }
    }
    else if (uVar4 == 4) {
      iVar5 = js_setObjectSlot(pbVar6,(int)pbVar6,(int)(short)((ushort)pbVar6[1] << 8) | (uint)pbVar6[2]
                          );
      if (iVar5 == 0) {
        return 0;
      }
      bVar1 = pbVar6[5];
      local_8 = pbVar6 + 6;
      bVar2 = *local_8;
      for (uVar4 = (int)(short)((ushort)pbVar6[3] << 8) | (uint)pbVar6[4];
          (int)uVar4 <= (int)((int)(short)((ushort)bVar1 << 8) | (uint)bVar2); uVar4 = uVar4 + 1) {
        iVar5 = js_setObjectSlot(pbVar6,(int)local_8,
                             (int)(short)((ushort)local_8[1] << 8) | (uint)local_8[2]);
        if (iVar5 == 0) {
          return 0;
        }
        local_8 = local_8 + 2;
      }
      local_8 = local_8 + (1 - (int)pbVar6);
    }
    else if (uVar4 == 5) {
      iVar5 = js_setObjectSlot(pbVar6,(int)pbVar6,(int)(short)((ushort)pbVar6[1] << 8) | (uint)pbVar6[2]
                          );
      if (iVar5 == 0) {
        return 0;
      }
      local_8 = pbVar6;
      for (uVar4 = (uint)CONCAT11(pbVar6[3],pbVar6[4]); local_8 = local_8 + 4, uVar4 != 0;
          uVar4 = uVar4 - 1) {
        iVar5 = js_setObjectSlot(pbVar6,(int)(local_8 + 2),
                             (int)(short)((ushort)local_8[3] << 8) | (uint)local_8[4]);
        if (iVar5 == 0) {
          return 0;
        }
      }
      local_8 = local_8 + (1 - (int)pbVar6);
    }
    pbVar6 = pbVar6 + (int)local_8;
  } while( true );
}



// ============================================================
// Function: javascript_objectSetGetter (FUN_6813e580)
// Address: 6813e580
// Size: 119 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall javascript_objectSetGetter(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  uVar2 = (uint)CONCAT11(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2));
  if (uVar2 != 0xffff) {
    return uVar2 * 0x10 + *(int *)(param_2 + 0x84);
  }
  iVar3 = param_1 - **(int **)(param_2 + 0x40);
  iVar6 = 0;
  iVar5 = *(int *)(param_2 + 0x90) + -1;
  if (-1 < iVar5) {
    do {
      iVar4 = (iVar5 + iVar6) / 2;
      iVar1 = *(int *)(iVar4 * 0x10 + 8 + *(int *)(param_2 + 0x84));
      if (iVar1 == iVar3) {
        return iVar4 * 0x10 + *(int *)(param_2 + 0x84);
      }
      if (iVar1 < iVar3) {
        iVar6 = iVar4 + 1;
      }
      else {
        iVar5 = iVar4 + -1;
      }
    } while (iVar6 <= iVar5);
  }
  return 0;
}



// ============================================================
// Function: javascript_objectSetSetter (FUN_6813e600)
// Address: 6813e600
// Size: 96 bytes
// Params: uint param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall javascript_objectSetSetter(uint param_1)

{
  int in_EAX;
  int iVar1;
  int unaff_ESI;
  int unaff_EDI;
  
  if ((*(int *)(unaff_ESI + 0x84) == 0) && (in_EAX < 0x7fff)) {
    *(char *)(unaff_EDI + 1) = (char)((uint)in_EAX >> 8);
    *(char *)(unaff_EDI + 2) = (char)in_EAX;
    return 1;
  }
  if (0x3fffffff < in_EAX) {
    js_getClassId(param_1);
    return 0;
  }
  if ((*(int *)(unaff_ESI + 0x84) == 0) && (iVar1 = javascript_objectConfigureSlot(), iVar1 == 0)) {
    return 0;
  }
  iVar1 = javascript_objectSetGetter(unaff_EDI,unaff_ESI);
  *(int *)(iVar1 + 0xc) = in_EAX * 2;
  return 1;
}



// ============================================================
// Function: javascript_objectGetAccessor (FUN_6813e660)
// Address: 6813e660
// Size: 55 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_objectGetAccessor(int *param_1,int param_2,int param_3)
{
  do {
    if (param_2 < *param_1) {
      *param_1 = *param_1 + param_3;
      if ((int *)param_1[2] != (int *)0x0) {
        javascript_objectGetAccessor((int *)param_1[2],param_2,param_3);
      }
    }
    param_1 = (int *)param_1[3];
  } while (param_1 != (int *)0x0);
  return 0;
}



// ============================================================
// Function: js_callGetter (FUN_6813e6a0)
// Address: 6813e6a0
// Size: 107 bytes
// Params: void * this, int param_1, int param_2
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall js_callGetter(void *this,int param_1,int param_2)

{
  int iVar1;
  int in_EAX;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = (int)*(void **)(in_EAX + 0x90) + -1;
  if ((int)this <= iVar4) {
    do {
      iVar3 = (iVar4 + (int)this) / 2;
      iVar2 = iVar3 * 0x10;
      iVar1 = *(int *)(iVar2 + 8 + *(int *)(in_EAX + 0x84));
      if (iVar1 == param_1) goto LAB_6813e702;
      if (iVar1 < param_1) {
        this = (void *)(iVar3 + 1);
      }
      else {
        iVar4 = iVar3 + -1;
      }
    } while ((int)this <= iVar4);
  }
  if (this == *(void **)(in_EAX + 0x90)) {
    return param_2;
  }
  iVar2 = (int)this << 4;
LAB_6813e702:
  return iVar2 + *(int *)(in_EAX + 0x84);
}



// ============================================================
// Function: javascript_objectPutSlot (FUN_6813e710)
// Address: 6813e710
// Size: 60 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_objectPutSlot(int param_1,int param_2)
{
  if (*(int *)(param_2 + 8) != 0) {
    javascript_objectPutSlot(param_1,*(int *)(param_2 + 8));
  }
  if (*(int *)(param_2 + 0xc) != 0) {
    javascript_objectPutSlot(param_1,*(int *)(param_2 + 0xc));
  }
  *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x8c);
  *(int *)(param_1 + 0x8c) = param_2;
  return 0;
}



// ============================================================
// Function: js_defineProperty (FUN_6813e750)
// Address: 6813e750
// Size: 130 bytes
// Params: void * this, undefined4 param_1, undefined1 param_2
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall js_defineProperty(void *this,undefined4 param_1,undefined1 param_2)

{
  int in_EAX;
  int iVar1;
  byte *pbVar2;
  int iVar3;
  
  if (((in_EAX < -0x8000) || (0x7fff < in_EAX)) && (*(int *)((int)this + 0x84) == 0)) {
    iVar1 = javascript_objectConfigureSlot();
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = js_setMultipleFlags(param_1,(int)this,param_2,(char)((uint)in_EAX >> 8),(char)in_EAX);
  if ((-1 < iVar1) && (*(int *)((int)this + 0x84) != 0)) {
    pbVar2 = (byte *)(**(int **)((int)this + 0x40) + iVar1);
    iVar3 = js_setObjectSlot(pbVar2,(int)pbVar2,in_EAX);
    if (iVar3 == 0) {
      return 0;
    }
  }
  return iVar1;
}



// ============================================================
// Function: javascript_objectRemoveSlot (FUN_6813e7e0)
// Address: 6813e7e0
// Size: 69 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall javascript_objectRemoveSlot(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  int *piVar4;
  int *piVar5;
  
  piVar1 = *(int **)(param_2 + 0x84);
  if (piVar1 == (int *)0x0) {
    return (int)(short)((ushort)*(byte *)(param_1 + 1) << 8) | (uint)*(byte *)(param_1 + 2);
  }
  piVar3 = (int *)javascript_objectSetGetter(param_1,param_2);
  uVar2 = piVar3[3];
  if ((uVar2 & 1) == 0) {
    return (int)uVar2 >> 1;
  }
  piVar4 = piVar3;
  do {
    piVar5 = piVar4;
    piVar4 = piVar5 + -4;
    if (piVar4 < piVar1) break;
  } while (*piVar4 == *piVar3);
  return *(int *)(uVar2 & 0xfffffffe) - piVar5[1];
}



// ============================================================
// Function: js_storeProperty (FUN_6813e830)
// Address: 6813e830
// Size: 111 bytes
// Params: uint param_1, int param_2, int param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_storeProperty(uint param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  if (*(int *)(param_2 + 0x84) == 0) {
    if (param_4 + 0x8000U < 0x10000) {
      *(char *)(param_3 + 2) = (char)param_4;
      *(char *)(param_3 + 1) = (char)((uint)param_4 >> 8);
      return 1;
    }
    iVar1 = javascript_objectConfigureSlot();
    if (iVar1 == 0) {
      return 0;
    }
  }
  javascript_objectSetGetter(param_3,param_2);
  uVar2 = javascript_objectDefineSlot(param_4,param_1);
  return uVar2;
}



// ============================================================
// Function: javascript_objectStoreSlotDirect (FUN_6813e8a0)
// Address: 6813e8a0
// Size: 43 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_objectStoreSlotDirect(int param_1)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if (*piVar1 == 5) break;
    piVar1 = (int *)piVar1[7];
  }
  return 1;
}



// ============================================================
// Function: javascript_objectStoreSlotResolved (FUN_6813e8d0)
// Address: 6813e8d0
// Size: 48 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_objectStoreSlotResolved(int param_1,int param_2)

{
  int *piVar1;
  
  piVar1 = *(int **)(param_1 + 8);
  while( true ) {
    if (piVar1 == (int *)0x0) {
      return 0;
    }
    if ((*piVar1 == 7) && (piVar1[6] == param_2)) break;
    piVar1 = (int *)piVar1[7];
  }
  return 1;
}



// ============================================================
// Function: js_initPropertySlot (FUN_6813e900)
// Address: 6813e900
// Size: 55 bytes
// Params: int param_1, undefined4 * param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_initPropertySlot(int param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4)
{
  *param_2 = param_3;
  param_2[4] = 0xffffffff;
  param_2[5] = 0xffffffff;
  param_2[3] = 0xffffffff;
  param_2[2] = 0xffffffff;
  param_2[1] = param_4;
  param_2[6] = 0;
  param_2[7] = *(undefined4 *)(param_1 + 8);
  *(undefined4 **)(param_1 + 8) = param_2;
  return 0;
}



// ============================================================
// Function: js_setPropertyFlags (FUN_6813e940)
// Address: 6813e940
// Size: 86 bytes
// Params: void * this, uint param_1, int param_2, undefined1 param_3
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall js_setPropertyFlags(void *this,uint param_1,int param_2,undefined1 param_3)

{
  uint uVar1;
  int iVar2;
  undefined1 *puVar3;
  int unaff_EDI;
  
  puVar3 = (undefined1 *)(**(int **)(unaff_EDI + 0x40) + (int)this);
  if (puVar3 != (undefined1 *)(**(int **)(unaff_EDI + 0x40) + -1)) {
    do {
      uVar1 = javascript_objectRemoveSlot((int)puVar3,unaff_EDI);
      iVar2 = js_storeProperty(param_1,unaff_EDI,(int)puVar3,param_2 - (int)puVar3);
      if (iVar2 == 0) {
        return 0;
      }
      *puVar3 = param_3;
      puVar3 = puVar3 + -uVar1;
    } while (puVar3 != (undefined1 *)(**(int **)(unaff_EDI + 0x40) + -1));
  }
  return 1;
}



// ============================================================
// Function: js_freezeObject (FUN_6813e9a0)
// Address: 6813e9a0
// Size: 19 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_freezeObject(int param_1)
{
  *(undefined4 *)(param_1 + 8) = *(undefined4 *)(*(int *)(param_1 + 8) + 0x1c);
  return 0;
}



// ============================================================
// Function: js_deleteProperty (FUN_6813e9c0)
// Address: 6813e9c0
// Size: 88 bytes
// Params: uint param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_deleteProperty(uint param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = *(int *)(param_2 + 8);
  iVar1 = js_setPropertyFlags(*(void **)(iVar2 + 8),param_1,*(int *)(*(int *)(param_2 + 0x40) + 8),6);
  if (iVar1 != 0) {
    iVar2 = js_setPropertyFlags(*(void **)(iVar2 + 0xc),param_1,
                         *(int *)(iVar2 + 4) + **(int **)(param_2 + 0x40),6);
    if (iVar2 != 0) {
      js_freezeObject(param_2);
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: js_hasProperty (FUN_6813ea20)
// Address: 6813ea20
// Size: 61 bytes
// Params: void * this, undefined1 param_1
// Return: bool
// Calling convention: __thiscall
// ============================================================

bool __thiscall js_hasProperty(void *this,undefined1 param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int unaff_ESI;
  int unaff_EDI;
  
  puVar1 = js_createAtom(unaff_EDI,*(int *)((int)this + 0x18),(undefined4 *)(unaff_ESI + 0x54));
  if (puVar1 == (undefined4 *)0x0) {
    return false;
  }
  iVar2 = js_setMultipleFlags(unaff_EDI,unaff_ESI,param_1,(char)((uint)puVar1[3] >> 8),
                       *(undefined1 *)(puVar1 + 3));
  return -1 < iVar2;
}



// ============================================================
// Function: js_getPropertyDescriptor (FUN_6813ea60)
// Address: 6813ea60
// Size: 468 bytes
// Params: uint param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_getPropertyDescriptor(uint param_1,uint *param_2)

{
  int *piVar1;
  int iVar2;
  code *pcVar3;
  undefined **ppuVar4;
  int iVar5;
  int iVar6;
  int extraout_ECX;
  int extraout_EDX;
  uint extraout_EDX_00;
  int unaff_EDI;
  uint local_c;
  int *local_8;
  
  if (((-1 < *(int *)(unaff_EDI + 0x20)) || (*(int *)(unaff_EDI + 0xc) == 9)) ||
     ((*param_2 & 0x20) != 0)) {
    return 1;
  }
  piVar1 = *(int **)(*(int *)(param_1 + 0x34) + 8);
  ppuVar4 = (undefined **)(*(uint *)(piVar1[1] + 8) & 0xfffffffe);
  if ((ppuVar4 != &PTR_s_Function_681928b8) && (ppuVar4 != &PTR_DAT_68192810)) {
    return 1;
  }
  iVar2 = *(int *)(unaff_EDI + 0x18);
  if (*(int **)(*(int *)(param_1 + 0x34) + 0x34) != piVar1) {
    return 1;
  }
  iVar5 = javascript_objectStoreSlotDirect((int)param_2);
  if (iVar5 != 0) {
    return 1;
  }
  iVar5 = javascript_objectStoreSlotResolved(extraout_ECX,extraout_EDX);
  if (iVar5 != 0) {
    return 1;
  }
  iVar5 = runtime_getProperty(param_1,piVar1,extraout_EDX_00,&local_8,&local_c);
  if (iVar5 == 0) {
    return 0;
  }
  iVar5 = *(int *)(unaff_EDI + 0xc);
  if (local_c == 0) goto LAB_6813ebf0;
  if (local_8 == piVar1) {
    pcVar3 = *(code **)(local_c + 4);
    iVar6 = iVar5;
    if (pcVar3 == certs_executeVerify) {
      switch(iVar5) {
      case 0x24:
switchD_6813eb2d_caseD_24:
        iVar6 = 0x42;
        break;
      case 0x29:
        iVar6 = 0x5f;
        break;
      case 0x2c:
        iVar6 = 0x61;
        break;
      case 0x2f:
        iVar6 = 99;
        break;
      case 0x32:
        iVar6 = 0x65;
        break;
      case 0x3b:
        iVar6 = 0x54;
        break;
      case 0x68:
        iVar6 = 10;
        break;
      case 0x6d:
        iVar6 = 0x55;
      }
    }
    else if ((pcVar3 == certs_initVerifier) || (pcVar3 == runtime_createObject)) {
      switch(iVar5) {
      case 0xe:
      case 0x6d:
        iVar6 = 0x57;
        break;
      case 0x24:
        goto switchD_6813eb2d_caseD_24;
      case 0x29:
        iVar6 = 0x60;
        break;
      case 0x2c:
        iVar6 = 0x62;
        break;
      case 0x2f:
        iVar6 = 100;
        break;
      case 0x32:
        iVar6 = 0x66;
        break;
      case 0x3b:
        iVar6 = 0x56;
        break;
      case 0x68:
        iVar6 = 0xb;
      }
    }
    if (iVar6 != iVar5) {
      *(int *)(unaff_EDI + 0xc) = iVar6;
      *(int *)(unaff_EDI + 0x20) = (int)*(short *)(local_c + 0x12);
    }
    *(uint *)(unaff_EDI + 0x24) = (uint)*(byte *)(local_c + 0x10);
  }
  pcVar3 = *(code **)(*(int *)(*local_8 + 4) + 0x34);
  if (pcVar3 != (code *)0x0) {
    (*pcVar3)(param_1,local_8,local_c);
  }
LAB_6813ebf0:
  if (*(int *)(unaff_EDI + 0x20) < 0) {
    if ((*(int *)(unaff_EDI + 0xc) == 0x3b) && (iVar2 == *(int *)(*(int *)(param_1 + 0x14) + 0xd8)))
    {
      *(undefined4 *)(unaff_EDI + 0xc) = 9;
      return 1;
    }
    *param_2 = *param_2 | 0x40;
  }
  return 1;
}



// ============================================================
// Function: js_enumerateKeys (FUN_6813ed30)
// Address: 6813ed30
// Size: 553 bytes
// Params: uint param_1, uint * param_2, int * param_3, int * param_4
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint js_enumerateKeys(uint param_1,uint *param_2,int *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  
  uVar4 = 1;
  if (param_3 == (int *)0x0) {
    return 1;
  }
  if (*param_4 != 0) {
    return 1;
  }
  switch(param_3[5]) {
  case 0:
    if (*param_3 != 0x3c) {
      return 1;
    }
    break;
  case 1:
    iVar2 = *param_3;
    if ((((iVar2 != 0x14) && (iVar2 != 0x15)) && (iVar2 != 0x34)) &&
       ((iVar2 != 0x3a && (iVar2 != 0x35)))) {
      uVar4 = js_enumerateKeys(param_1,param_2,(int *)param_3[6],param_4);
      return uVar4;
    }
    break;
  case 2:
    if (*param_3 != 4) {
      if (*param_3 == 0x17) {
        piVar3 = (int *)param_3[6];
        if ((*piVar3 == 0x1d) && (iVar2 = js_getPropertyDescriptor(param_1,param_2), iVar2 == 0)) {
          return 0;
        }
        if (piVar3[3] != 9) {
          *param_4 = 1;
        }
      }
      uVar4 = js_enumerateKeys(param_1,param_2,(int *)param_3[6],param_4);
      if (uVar4 == 0) {
        return 0;
      }
      piVar3 = (int *)param_3[7];
      goto LAB_6813edf5;
    }
    break;
  case 3:
    uVar4 = js_enumerateKeys(param_1,param_2,(int *)param_3[6],param_4);
    if (uVar4 == 0) {
      return 0;
    }
    uVar4 = js_enumerateKeys(param_1,param_2,(int *)param_3[7],param_4);
    if (uVar4 == 0) {
      return 0;
    }
    piVar3 = (int *)param_3[8];
LAB_6813edf5:
    uVar4 = js_enumerateKeys(param_1,param_2,piVar3,param_4);
    if (uVar4 == 0) {
      return 0;
    }
    return 1;
  case -3:
    if (*(int *)(param_3[6] + 0x18) == 0) {
      return 1;
    }
    *param_4 = 1;
    return 1;
  case -2:
    iVar2 = *param_3;
    if (((iVar2 != 0x33) && (iVar2 != 0x1b)) && (iVar2 != 0x17)) {
      piVar3 = (int *)param_3[6];
      if (piVar3 == (int *)0x0) {
        return 1;
      }
      do {
        uVar1 = js_enumerateKeys(param_1,param_2,piVar3,param_4);
        piVar3 = (int *)piVar3[10];
        uVar4 = uVar4 & uVar1;
      } while (piVar3 != (int *)0x0);
      return uVar4;
    }
    break;
  case -1:
    if (*param_3 == 0x1d) {
      iVar2 = js_getPropertyDescriptor(param_1,param_2);
      if (iVar2 == 0) {
        return 0;
      }
      if ((param_3[8] < 0) && (param_3[3] != 9)) {
        *param_4 = 1;
      }
    }
    piVar3 = (int *)param_3[7];
    if ((*param_3 == 0x16) && (*piVar3 == 0x1d)) {
      iVar2 = js_getPropertyDescriptor(param_1,param_2);
      if (iVar2 == 0) {
        return 0;
      }
      if ((piVar3[3] != 9) || (param_3[6] != *(int *)(*(int *)(param_1 + 0x14) + 0x108))) {
        *param_4 = 1;
      }
    }
    uVar4 = js_enumerateKeys(param_1,param_2,piVar3,param_4);
    return uVar4;
  default:
    goto switchD_6813ed61_default;
  }
  *param_4 = 1;
switchD_6813ed61_default:
  return 1;
}



// ============================================================
// Function: javascript_objectEnumerateSlots (FUN_6813ef80)
// Address: 6813ef80
// Size: 260 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, uint param_4
// Return: bool
// Calling convention: __fastcall
// ============================================================

bool __fastcall javascript_objectEnumerateSlots(undefined4 param_1,undefined4 param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  undefined4 *puVar3;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar4;
  float10 extraout_ST0;
  ulonglong uVar5;
  
  fVar4 = (float10)(double)CONCAT44(param_4,param_3);
  if (((param_4 & 0x7ff00000) != 0x7ff00000) && ((param_4 != 0x80000000 || (param_3 != 0)))) {
    uVar5 = strings_floatToUint64(param_4 & 0x7ff00000,param_2);
    uVar1 = (uint)uVar5;
    fVar4 = extraout_ST0;
    if ((extraout_ST0 == (float10)(int)uVar1) && (uVar1 + 0x3fffffff < 0x7fffffff)) {
      if (uVar1 == 0) {
        iVar2 = js_setPropertyFlag(unaff_ESI,unaff_EDI,0x3e);
        return -1 < iVar2;
      }
      if (uVar1 == 1) {
        iVar2 = js_setPropertyFlag(unaff_ESI,unaff_EDI,0x3f);
        return -1 < iVar2;
      }
      if (uVar1 < 0x10000) {
        iVar2 = js_setMultipleFlags(unaff_ESI,unaff_EDI,0x58,(char)(uVar5 >> 8),(char)uVar5);
        return -1 < iVar2;
      }
      iVar2 = javascript_gcSweepInteger(unaff_ESI,uVar1,0);
      goto LAB_6813f049;
    }
  }
  iVar2 = javascript_gcSweepFloat(unaff_ESI,(double)fVar4,0);
LAB_6813f049:
  if (iVar2 != 0) {
    puVar3 = js_createAtom(unaff_ESI,iVar2,(undefined4 *)(unaff_EDI + 0x54));
    if (puVar3 != (undefined4 *)0x0) {
      iVar2 = js_setMultipleFlags(unaff_ESI,unaff_EDI,0x3c,(char)((uint)puVar3[3] >> 8),
                           *(undefined1 *)(puVar3 + 3));
      return -1 < iVar2;
    }
  }
  return false;
}



// ============================================================
// Function: javascript_objectAllocSlots (FUN_6813f090)
// Address: 6813f090
// Size: 222 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint javascript_objectAllocSlots(int param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  void *pvVar5;
  int *piVar6;
  int unaff_EBX;
  uint uVar7;
  
  uVar1 = *(uint *)(unaff_EBX + 0x6c);
  if ((uVar1 & *(uint *)(unaff_EBX + 0x70)) != 0) goto LAB_6813f160;
  pvVar5 = *(void **)(unaff_EBX + 0x68);
  piVar6 = (int *)(param_1 + 0x54);
  uVar3 = *(uint *)(unaff_EBX + 0x70) + 1;
  if (pvVar5 == (void *)0x0) {
    iVar4 = *(int *)(param_1 + 100);
    iVar2 = *(int *)(iVar4 + 0xc);
    uVar7 = *(uint *)(param_1 + 0x6c) + uVar3 & ~*(uint *)(param_1 + 0x6c);
    uVar3 = iVar2 + uVar7;
    if (*(uint *)(iVar4 + 8) < uVar3) {
      iVar4 = js_getSlotIndex((int)piVar6,uVar7);
      *(int *)(unaff_EBX + 0x68) = iVar4;
    }
    else {
      *(uint *)(iVar4 + 0xc) = uVar3;
      *(int *)(unaff_EBX + 0x68) = iVar2;
    }
  }
  else {
    iVar4 = *(int *)(param_1 + 100);
    if (*(int *)(iVar4 + 0xc) ==
        (*(uint *)(param_1 + 0x6c) + uVar3 & ~*(uint *)(param_1 + 0x6c)) + (int)pvVar5) {
      uVar7 = (*(uint *)(param_1 + 0x6c) + uVar3 * 2 & ~*(uint *)(param_1 + 0x6c)) + (int)pvVar5;
      if (*(uint *)(iVar4 + 8) < uVar7) {
        if (pvVar5 != *(void **)(iVar4 + 4)) goto LAB_6813f12a;
        pvVar5 = (void *)js_resolveProperty(piVar6,(int)pvVar5,uVar3,uVar3);
        goto LAB_6813f12f;
      }
      *(uint *)(iVar4 + 0xc) = uVar7;
    }
    else {
LAB_6813f12a:
      pvVar5 = js_reallocObject(piVar6,pvVar5,uVar3,uVar3);
LAB_6813f12f:
      *(void **)(unaff_EBX + 0x68) = pvVar5;
    }
    if (*(int *)(unaff_EBX + 0x68) != 0) {
      *(uint *)(unaff_EBX + 0x70) = *(int *)(unaff_EBX + 0x70) * 2 | 1;
    }
  }
  if (*(int *)(unaff_EBX + 0x68) == 0) {
    xtra_reportError(param_1);
    return 0xffffffff;
  }
LAB_6813f160:
  *(uint *)(unaff_EBX + 0x6c) = uVar1 + 1;
  return uVar1;
}



// ============================================================
// Function: js_allocObject (FUN_6813f170)
// Address: 6813f170
// Size: 180 bytes
// Params: int param_1, int param_2, int param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint js_allocObject(int param_1,int param_2,int param_3)

{
  uint uVar1;
  byte *pbVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  uVar1 = javascript_objectAllocSlots(param_1);
  if ((int)uVar1 < 0) {
    return 0xffffffff;
  }
  iVar5 = (*(int **)(param_2 + 0x40))[2] - **(int **)(param_2 + 0x40);
  iVar4 = iVar5 - *(int *)(param_2 + 0x74);
  pbVar2 = (byte *)(*(int *)(param_2 + 0x68) + uVar1);
  *(int *)(param_2 + 0x74) = iVar5;
  while( true ) {
    if (iVar4 < 8) {
      *pbVar2 = (char)param_3 << 3 | (byte)iVar4 & 7;
      uVar6 = (uint)(byte)(&DAT_68193b74)[param_3 * 8];
      if (uVar6 != 0) {
        do {
          uVar3 = js_allocObject(param_1,param_2,0);
          if ((int)uVar3 < 0) {
            return 0xffffffff;
          }
          uVar6 = uVar6 - 1;
        } while (0 < (int)uVar6);
      }
      return uVar1;
    }
    iVar5 = iVar4;
    if (0x3e < iVar4) {
      iVar5 = 0x3f;
    }
    iVar4 = iVar4 - iVar5;
    *pbVar2 = (byte)iVar5 | 0xc0;
    uVar1 = javascript_objectAllocSlots(param_1);
    if ((int)uVar1 < 0) break;
    pbVar2 = (byte *)(*(int *)(param_2 + 0x68) + uVar1);
  }
  return 0xffffffff;
}



// ============================================================
// Function: javascript_objectCreateScoped (FUN_6813f230)
// Address: 6813f230
// Size: 145 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_objectCreateScoped(int param_1)

{
  int iVar1;
  uint uVar2;
  void *pvVar3;
  uint uVar4;
  int unaff_EBX;
  
  iVar1 = *(int *)(param_1 + 100);
  pvVar3 = *(void **)(unaff_EBX + 0x68);
  uVar2 = *(int *)(unaff_EBX + 0x70) + 1;
  if (*(int *)(iVar1 + 0xc) ==
      (*(uint *)(param_1 + 0x6c) + uVar2 & ~*(uint *)(param_1 + 0x6c)) + (int)pvVar3) {
    uVar4 = (*(uint *)(param_1 + 0x6c) + uVar2 * 2 & ~*(uint *)(param_1 + 0x6c)) + (int)pvVar3;
    if (uVar4 <= *(uint *)(iVar1 + 8)) {
      *(uint *)(iVar1 + 0xc) = uVar4;
      goto LAB_6813f292;
    }
    if (pvVar3 != *(void **)(iVar1 + 4)) goto LAB_6813f28a;
    pvVar3 = (void *)js_resolveProperty((int *)(param_1 + 0x54),(int)pvVar3,uVar2,uVar2);
  }
  else {
LAB_6813f28a:
    pvVar3 = js_reallocObject((int *)(param_1 + 0x54),pvVar3,uVar2,uVar2);
  }
  *(void **)(unaff_EBX + 0x68) = pvVar3;
LAB_6813f292:
  if (*(int *)(unaff_EBX + 0x68) != 0) {
    *(uint *)(unaff_EBX + 0x70) = *(int *)(unaff_EBX + 0x70) * 2 | 1;
    return 1;
  }
  xtra_reportError(param_1);
  return 0;
}



// ============================================================
// Function: javascript_objectCreateWithClass (FUN_6813f2d0)
// Address: 6813f2d0
// Size: 181 bytes
// Params: int param_1, int param_2, byte * param_3, int param_4
// Return: byte *
// Calling convention: __stdcall
// ============================================================

byte * javascript_objectCreateWithClass(int param_1,int param_2,byte *param_3,int param_4)

{
  byte bVar1;
  int iVar2;
  byte bVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  
  bVar1 = *param_3;
  bVar5 = bVar1 >> 3;
  if (bVar5 < 0x18) {
    uVar4 = bVar1 & 7;
  }
  else {
    uVar4 = bVar1 & 0x3f;
  }
  if ((int)(uVar4 + param_4) < (int)((-(uint)(bVar5 < 0x18) & 0xffffffc8) + 0x40)) {
    bVar3 = (byte)(uVar4 + param_4);
    if (0x17 < bVar5) {
      *param_3 = bVar3 | 0xc0;
      return param_3;
    }
    *param_3 = bVar1 & 0xf8 | bVar3 & 7;
    return param_3;
  }
  iVar6 = (int)param_3 - *(int *)(param_2 + 0x68);
  if ((*(uint *)(param_2 + 0x6c) & *(uint *)(param_2 + 0x70)) == 0) {
    iVar2 = javascript_objectCreateScoped(param_1);
    if (iVar2 == 0) {
      return (byte *)0x0;
    }
    param_3 = (byte *)(*(int *)(param_2 + 0x68) + iVar6);
  }
  iVar2 = *(int *)(param_2 + 0x6c);
  *(int *)(param_2 + 0x6c) = iVar2 + 1;
  memmove(param_3 + 1,param_3,iVar2 - iVar6);
  *param_3 = (byte)param_4 | 0xc0;
  return param_3 + 1;
}



// ============================================================
// Function: js_getObjectType (FUN_6813f390)
// Address: 6813f390
// Size: 68 bytes
// Params: byte * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_getObjectType(byte *param_1)

{
  byte *pbVar1;
  uint uVar2;
  
  if ((*param_1 & 0xf8) < 0xc0) {
    uVar2 = (uint)(*param_1 >> 3);
  }
  else {
    uVar2 = 0x18;
  }
  uVar2 = (uint)(byte)(&DAT_68193b74)[uVar2 * 8];
  pbVar1 = param_1;
  while (pbVar1 = pbVar1 + 1, uVar2 != 0) {
    uVar2 = uVar2 - 1;
    if ((*pbVar1 & 0x80) != 0) {
      pbVar1 = pbVar1 + 2;
    }
  }
  return (int)pbVar1 - (int)param_1;
}



// ============================================================
// Function: js_getObjectFlags (FUN_6813f3e0)
// Address: 6813f3e0
// Size: 62 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint js_getObjectFlags(int param_1,int param_2)

{
  uint uVar1;
  byte *pbVar2;
  
  pbVar2 = (byte *)(param_1 + 1);
  for (; param_2 != 0; param_2 = param_2 + -1) {
    if ((*pbVar2 & 0x80) != 0) {
      pbVar2 = pbVar2 + 2;
    }
    pbVar2 = pbVar2 + 1;
  }
  uVar1 = (uint)*pbVar2;
  if ((char)*pbVar2 < '\0') {
    uVar1 = ((uVar1 & 0x7f) << 8 | (uint)pbVar2[1]) << 8 | (uint)pbVar2[2];
  }
  return uVar1;
}



// ============================================================
// Function: js_allocObjectWithProto (FUN_6813f420)
// Address: 6813f420
// Size: 193 bytes
// Params: uint param_1, int param_2, int param_3, int param_4, uint param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 js_allocObjectWithProto(uint param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  size_t _Size;
  byte *pbVar2;
  int iVar3;
  
  if (0x7fffff < param_5) {
    js_getClassId(param_1);
    return 0;
  }
  pbVar2 = (byte *)(*(int *)(param_2 + 0x68) + 1 + param_3);
  for (; param_4 != 0; param_4 = param_4 + -1) {
    if ((*pbVar2 & 0x80) != 0) {
      pbVar2 = pbVar2 + 2;
    }
    pbVar2 = pbVar2 + 1;
  }
  if (0x7f < (int)param_5) {
    if ((*pbVar2 & 0x80) == 0) {
      iVar3 = (int)pbVar2 - *(int *)(param_2 + 0x68);
      if ((*(int *)(param_2 + 0x6c) + 1U & *(uint *)(param_2 + 0x70)) < 2) {
        iVar1 = javascript_objectCreateScoped(param_1);
        if (iVar1 == 0) {
          return 0;
        }
        pbVar2 = (byte *)(*(int *)(param_2 + 0x68) + iVar3);
      }
      *(int *)(param_2 + 0x6c) = *(int *)(param_2 + 0x6c) + 2;
      _Size = (*(int *)(param_2 + 0x6c) - iVar3) - 3;
      if (0 < (int)_Size) {
        memmove(pbVar2 + 3,pbVar2 + 1,_Size);
      }
    }
    *pbVar2 = (byte)(param_5 >> 0x10) | 0x80;
    pbVar2[1] = (byte)(param_5 >> 8);
    pbVar2 = pbVar2 + 2;
  }
  *pbVar2 = (byte)param_5;
  return 1;
}



// ============================================================
// Function: javascript_objectClone (FUN_6813f4f0)
// Address: 6813f4f0
// Size: 65 bytes
// Params: int param_1, int param_2
// Return: void *
// Calling convention: __stdcall
// ============================================================

void * javascript_objectClone(int param_1,int param_2)

{
  void *_Src;
  size_t _Size;
  void *_Dst;
  
  _Src = *(void **)(param_2 + 0x68);
  _Size = *(size_t *)(param_2 + 0x6c);
  _Dst = (void *)xtra_getPropertyById(param_1,_Size + 1);
  if (_Dst == (void *)0x0) {
    return (void *)0x0;
  }
  memcpy(_Dst,_Src,_Size);
  *(undefined1 *)((int)_Dst + _Size) = 0;
  return _Dst;
}



// ============================================================
// Function: javascript_objectSetParent (FUN_6813f540)
// Address: 6813f540
// Size: 353 bytes
// Params: int param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_objectSetParent(int param_1,int param_2)

{
  uint uVar1;
  void *pvVar2;
  int iVar3;
  int iVar4;
  void *pvVar5;
  uint uVar6;
  int iVar7;
  
  uVar1 = *(uint *)(param_2 + 0x80);
  uVar6 = *(int *)(param_2 + 4) * 0xc;
  if (uVar6 <= uVar1) {
    return 1;
  }
  pvVar2 = *(void **)(param_2 + 0x78);
  if (pvVar2 == (void *)0x0) {
    iVar3 = *(int *)(param_1 + 0x80);
    iVar7 = ((uVar6 + 0x2ff) / 0x300) * 0x300;
    uVar6 = *(uint *)(param_1 + 0x88) + iVar7 & ~*(uint *)(param_1 + 0x88);
    iVar4 = *(int *)(iVar3 + 0xc);
    uVar1 = iVar4 + uVar6;
    if (*(uint *)(iVar3 + 8) < uVar1) {
      iVar4 = js_getSlotIndex(param_1 + 0x70,uVar6);
    }
    else {
      *(uint *)(iVar3 + 0xc) = uVar1;
    }
    *(int *)(param_2 + 0x78) = iVar4;
    if (iVar4 == 0) {
      return 0;
    }
    *(int *)(param_2 + 0x80) = iVar7;
    *(int *)(param_2 + 0x7c) = iVar4;
    return 1;
  }
  iVar3 = *(int *)(param_2 + 0x7c);
  iVar4 = *(int *)(param_1 + 0x80);
  iVar7 = (((uVar6 - uVar1) + 0x2ff) / 0x300) * 0x300;
  if (*(int *)(iVar4 + 0xc) ==
      (*(uint *)(param_1 + 0x88) + uVar1 & ~*(uint *)(param_1 + 0x88)) + (int)pvVar2) {
    uVar6 = (*(uint *)(param_1 + 0x88) + iVar7 + uVar1 & ~*(uint *)(param_1 + 0x88)) + (int)pvVar2;
    if (uVar6 <= *(uint *)(iVar4 + 8)) {
      *(uint *)(iVar4 + 0xc) = uVar6;
      goto LAB_6813f670;
    }
    if (pvVar2 != *(void **)(iVar4 + 4)) {
      pvVar5 = js_reallocObject((int *)(param_1 + 0x70),pvVar2,uVar1,iVar7);
      *(void **)(param_2 + 0x78) = pvVar5;
      goto LAB_6813f670;
    }
    pvVar5 = (void *)js_resolveProperty((int *)(param_1 + 0x70),(int)pvVar2,uVar1,iVar7);
  }
  else {
    pvVar5 = js_reallocObject((int *)(param_1 + 0x70),pvVar2,uVar1,iVar7);
  }
  *(void **)(param_2 + 0x78) = pvVar5;
LAB_6813f670:
  if (*(int *)(param_2 + 0x78) == 0) {
    return 0;
  }
  *(uint *)(param_2 + 0x80) = iVar7 + uVar1;
  *(int *)(param_2 + 0x7c) = *(int *)(param_2 + 0x78) + (iVar3 - (int)pvVar2);
  return 1;
}



// ============================================================
// Function: javascript_objectGetParent (FUN_6813f6b0)
// Address: 6813f6b0
// Size: 38 bytes
// Params: undefined4 param_1, int param_2, int param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_objectGetParent(undefined4 param_1,int param_2,int param_3,int param_4,int param_5)
{
  int *piVar1;
  
  piVar1 = *(int **)(param_2 + 0x7c);
  *(int **)(param_2 + 0x7c) = piVar1 + 3;
  *piVar1 = param_3;
  piVar1[1] = param_4 - param_3;
  piVar1[2] = param_5;
  return 0;
}



// ============================================================
// Function: javascript_objectSetPrototype (FUN_6813f6e0)
// Address: 6813f6e0
// Size: 155 bytes
// Params: int param_1, int param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_objectSetPrototype(int param_1,int param_2,undefined4 *param_3)

{
  void *_Src;
  size_t _Size;
  int iVar1;
  void *_Dst;
  
  _Src = *(void **)(param_2 + 0x78);
  iVar1 = (*(int *)(param_2 + 0x7c) - (int)_Src) / 0xc;
  if (iVar1 == 0) {
    *param_3 = 0;
    return 1;
  }
  _Size = iVar1 * 0xc;
  _Dst = (void *)xtra_getPropertyById(param_1,_Size + 0xc);
  if (_Dst == (void *)0x0) {
    *param_3 = 0;
    return 0;
  }
  memcpy(_Dst,_Src,_Size);
  *(undefined4 *)(_Size + (int)_Dst) = 0;
  *(int *)(_Size + 4 + (int)_Dst) = (*(int **)(param_2 + 0x40))[2] - **(int **)(param_2 + 0x40);
  *(undefined4 *)(_Size + 8 + (int)_Dst) = 0;
  *param_3 = _Dst;
  return 1;
}



// ============================================================
// Function: javascript_objectCreateFromLiteral (FUN_6813f780)
// Address: 6813f780
// Size: 1586 bytes
// Params: uint param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int javascript_objectCreateFromLiteral(uint param_1,int param_2)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  byte bVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int extraout_ECX;
  uint *puVar5;
  size_t _Size;
  void *pvVar6;
  int extraout_ECX_00;
  uint uVar7;
  int iVar8;
  uint extraout_EDX;
  byte *pbVar9;
  uint *puVar10;
  uint uVar11;
  int iVar12;
  int *piVar13;
  int iVar14;
  byte *pbVar15;
  uint local_44;
  byte *local_40;
  int local_3c;
  undefined4 local_38;
  uint *local_34;
  byte *local_30;
  uint *local_2c;
  undefined1 *local_28;
  uint *local_24;
  uint *local_20;
  byte *local_1c;
  byte *local_18;
  uint *local_14;
  byte *local_10;
  int local_c;
  void *local_8;
  
  piVar13 = *(int **)(param_2 + 0x40);
  local_8 = (void *)*piVar13;
  local_20 = *(uint **)(param_2 + 0x84) + *(int *)(param_2 + 0x90) * 4;
  local_c = piVar13[2] - *piVar13;
  local_14 = *(uint **)(param_2 + 0x84);
  local_10 = (byte *)0x0;
  do {
    uVar7 = 0;
    uVar11 = 0;
    local_34 = (uint *)0x1;
    local_18 = (byte *)0x0;
    local_24 = (uint *)0xffffffff;
    local_1c = (byte *)0xffffffff;
    local_2c = (uint *)0x0;
    local_28 = (undefined1 *)0x0;
    puVar10 = local_14;
    if (local_14 < local_20) {
      do {
        puVar10[1] = (uint)(local_18 + puVar10[1]);
        uVar3 = *puVar10;
        if ((byte *)(size_t)uVar3 == local_1c) {
LAB_6813f8b9:
          if ((2 < uVar11 - 9) &&
             ((iVar8 = *(int *)(puVar10[3] & 0xfffffffe) - (int)local_24, iVar8 < -0x8000 ||
              (0x7fff < iVar8)))) {
            local_30 = (byte *)0x0;
            local_34 = (uint *)0x0;
            switch(uVar7) {
            case 6:
              uVar7 = 0x8b;
              break;
            case 7:
              uVar7 = 0x8c;
              break;
            case 8:
              uVar7 = 0x8d;
              break;
            case 0x44:
              uVar7 = 0x8e;
              break;
            case 0x45:
              uVar7 = 0x8f;
              break;
            case 0x46:
              uVar7 = 0x93;
              break;
            case 0x47:
              uVar7 = 0x94;
              break;
            case 0x72:
              uVar7 = 0x90;
              break;
            case 0x77:
              uVar7 = 0x91;
              break;
            case 0x78:
              uVar7 = 0x92;
            }
            *local_28 = (char)uVar7;
            puVar5 = local_2c;
            pbVar9 = local_18;
            if (local_2c < local_20) {
              do {
                if ((byte *)*puVar5 != local_1c) break;
                if (puVar10 < puVar5) {
                  puVar5[1] = (uint)(pbVar9 + puVar5[1]);
                }
                else {
                  puVar5[1] = (uint)(local_30 + puVar5[1]);
                  local_30 = local_30 + 2;
                }
                pbVar9 = pbVar9 + 2;
                javascript_objectGetAccessor(*(int **)(param_2 + 0x88),puVar5[1],2);
                puVar5 = (uint *)(extraout_ECX + 0x10);
                uVar7 = extraout_EDX;
              } while (puVar5 < local_20);
            }
            local_18 = pbVar9;
            puVar10 = puVar5 + -4;
          }
        }
        else {
          uVar7 = (uint)*(byte *)((int)local_8 + uVar3);
          uVar11 = *(uint *)(&DAT_68193cbc + uVar7 * 0x10) & 0xf;
          local_2c = puVar10;
          local_28 = (undefined1 *)((int)local_8 + uVar3);
          local_24 = (uint *)puVar10[1];
          local_1c = (byte *)(size_t)uVar3;
          if (2 < uVar11 - 9) goto LAB_6813f8b9;
        }
        puVar10 = puVar10 + 4;
      } while (puVar10 < local_20);
    }
    local_10 = local_10 + (int)local_18;
  } while (local_34 == (uint *)0x0);
  /* FIXUP(C2094): if (local_10 == (byte *)0x0) goto LAB_6813fa1c; */
  local_30 = local_10 + local_c;
  pbVar15 = *(byte **)(*(int *)(param_2 + 0x40) + 4);
  pbVar9 = local_30 + (int)local_8;
  if (pbVar15 < pbVar9) {
    uVar7 = (int)pbVar15 - (int)local_8;
    local_34 = *(uint **)(param_1 + 0x48);
    iVar8 = (int)local_30 - uVar7;
    if (local_34[3] ==
        (*(uint *)(param_1 + 0x50) + uVar7 & ~*(uint *)(param_1 + 0x50)) + (int)local_8) {
      uVar3 = (*(uint *)(param_1 + 0x50) + iVar8 + uVar7 & ~*(uint *)(param_1 + 0x50)) +
              (int)local_8;
      if (local_34[2] < uVar3) {
        if (local_8 != (void *)local_34[1]) goto LAB_6813f9c6;
        local_8 = (void *)js_resolveProperty((int *)(param_1 + 0x38),(int)local_8,uVar7,iVar8);
        /* FIXUP(C2094): goto LAB_6813f9cb; */
      }
      local_34[3] = uVar3;
    }
    else {
LAB_6813f9c6:
      local_8 = js_reallocObject((int *)(param_1 + 0x38),local_8,uVar7,iVar8);
/* FIXUP(C2143-ctx): LAB_6813f9cb: */
    } /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */; /* FIXUP(C2143): added missing semicolon */;
    /* FIXUP(C2143-ctx): if (local_8 == (void *)0x0) { */
      xtra_reportError(param_1);
      return 0;
    }
    **(undefined4 **)(param_2 + 0x40) = local_8;
    pbVar9 = (byte *)((int)local_8 + (int)local_30);
    *(byte **)(*(int *)(param_2 + 0x40) + 4) = pbVar9;
  }
  /* FIXUP(C2059): *(byte **)(*(int *)(param_2 + 0x40) + 8) = pbVar9; */
  local_44 = 0xffffffff;
  /* FIXUP(C2065): local_40 = local_30; */
  /* FIXUP(C2065): local_3c = local_c; */
  local_38 = 0;
/* FIXUP(C2143): LAB_6813fa1c: */
  pbVar9 = (byte *)0xffffffff;
  /* FIXUP(C2099): puVar10 = puVar10 + -4; */
  local_1c = (byte *)0xffffffff;
  /* FIXUP(C2059): if (local_14 <= puVar10) { */
    /* FIXUP(C2059): do { */
      /* FIXUP(C2065): pvVar6 = local_8; */
      /* FIXUP(C2065): pbVar15 = (byte *)*puVar10; */
      /* FIXUP(C2059): if (pbVar15 != pbVar9) { */
        /* FIXUP(C2065): uVar11 = *(uint *)(&DAT_68193cbc + (uint)pbVar15[(int)local_8] * 0x10) & 0xf; */
        /* FIXUP(C2374): local_1c = pbVar15; */
        /* FIXUP(C2065): puVar5 = puVar10; */
        /* FIXUP(C2059): do { */
          /* FIXUP(C2065): puVar2 = puVar5; */
          /* FIXUP(C2099): puVar5 = puVar2 + -4; */
          /* FIXUP(C2059): if (puVar5 < local_14) break; */
        /* FIXUP(C2059): } while ((byte *)*puVar5 == pbVar15); */
        /* FIXUP(C2065): local_24 = (uint *)puVar2[1]; */
        /* FIXUP(C2374): pbVar9 = pbVar15; */
      /* FIXUP(C2059): } */
      /* FIXUP(C2065): local_34 = (uint *)(puVar10[2] + (int)local_8); */
      /* FIXUP(C2065): local_30 = (byte *)(*(int *)(puVar10[3] & 0xfffffffe) - (int)local_24); */
      /* FIXUP(C2059): if (uVar11 - 9 < 3) { */
        /* FIXUP(C2065): uVar7 = puVar10[1]; */
        /* FIXUP(C2065): iVar8 = local_c - puVar10[2]; */
        /* FIXUP(C2065): local_c = puVar10[2] + 1; */
        /* FIXUP(C2099): _Size = iVar8 - 3; */
        /* FIXUP(C2059): if (_Size != 0) { */
          /* FIXUP(C2143): memmove((void *)((int)local_8 + uVar7 + 5),(void *)((int)local_34 + 3),_Size); */
        /* FIXUP(C2059): } */
        /* FIXUP(C2059): *(char *)((int)pvVar6 + uVar7 + 1) = (char)((uint)local_30 >> 0x18); */
        /* FIXUP(C2059): *(char *)((int)pvVar6 + uVar7 + 2) = (char)((uint)local_30 >> 0x10); */
        /* FIXUP(C2059): *(char *)((int)pvVar6 + uVar7 + 3) = (char)((uint)local_30 >> 8); */
        /* FIXUP(C2059): *(char *)((int)pvVar6 + uVar7 + 4) = (char)local_30; */
        /* FIXUP(C2374): pbVar9 = local_1c; */
      /* FIXUP(C2059): } */
      /* FIXUP(C2059): else { */
        /* FIXUP(C2059): *(char *)((int)local_34 + 1) = (char)((uint)local_30 >> 8); */
        /* FIXUP(C2059): *(char *)((int)local_34 + 2) = (char)local_30; */
      /* FIXUP(C2059): } */
      /* FIXUP(C2099): puVar10 = puVar10 + -4; */
    /* FIXUP(C2059): } while (local_14 <= puVar10); */
  /* FIXUP(C2059): } */
  /* FIXUP(C2059): if (local_10 != (byte *)0x0) { */
    /* FIXUP(C2374): pbVar9 = *(byte **)(param_2 + 0x68); */
    local_10 = (byte *)0x0;
    /* FIXUP(C2374): local_c = 0; */
    /* FIXUP(C2065): local_24 = local_14; */
    /* FIXUP(C2065): local_18 = pbVar9 + *(int *)(param_2 + 0x6c); */
    /* FIXUP(C2059): if (pbVar9 < pbVar9 + *(int *)(param_2 + 0x6c)) { */
      /* FIXUP(C2059): do { */
        /* FIXUP(C2100): bVar1 = *pbVar9; */
        /* FIXUP(C2059): if ((bVar1 & 0xf8) < 0xc0) { */
          /* FIXUP(C2374): uVar7 = bVar1 & 7; */
        /* FIXUP(C2059): } */
        /* FIXUP(C2059): else { */
          /* FIXUP(C2065): uVar7 = bVar1 & 0x3f; */
        /* FIXUP(C2059): } */
        /* FIXUP(C2374): local_c = local_c + uVar7; */
        /* FIXUP(C2065): puVar10 = local_20; */
        /* FIXUP(C2059): if (local_24 < local_20) { */
          /* FIXUP(C2059): do { */
            /* FIXUP(C2059): if (local_c <= (int)local_24[2]) break; */
            /* FIXUP(C2065): local_34 = local_24 + 4; */
            /* FIXUP(C2099): puVar5 = local_34; */
            /* FIXUP(C2059): if (local_34 == puVar10) { */
              puVar5 = &local_44;
            /* FIXUP(C2059): } */
            /* FIXUP(C2109): iVar8 = (puVar5[1] - puVar5[2]) - (int)local_10; */
            /* FIXUP(C2059): if (0 < iVar8) { */
              /* FIXUP(C2374): pbVar9 = javascript_objectCreateWithClass(param_1,param_2,pbVar9,iVar8); */
              /* FIXUP(C2059): if (pbVar9 == (byte *)0x0) { */
                /* FIXUP(C2059): return 0; */
              /* FIXUP(C2059): } */
              /* FIXUP(C2374): local_10 = local_10 + iVar8; */
              /* FIXUP(C2065): local_18 = (byte *)(*(int *)(param_2 + 0x68) + *(int *)(param_2 + 0x6c)); */
              /* FIXUP(C2065): puVar10 = local_20; */
            /* FIXUP(C2059): } */
            /* FIXUP(C2099): local_24 = local_34; */
          /* FIXUP(C2059): } while (local_34 < puVar10); */
        /* FIXUP(C2059): } */
        /* FIXUP(C2059): if ((*pbVar9 & 0xf8) < 0xc0) { */
          /* FIXUP(C2100): uVar7 = (uint)(*pbVar9 >> 3); */
        /* FIXUP(C2059): } */
        /* FIXUP(C2059): else { */
          /* FIXUP(C2374): uVar7 = 0x18; */
        /* FIXUP(C2059): } */
        /* FIXUP(C2065): local_34 = (uint *)(&DAT_68193b76 + uVar7 * 8); */
        /* FIXUP(C2059): if ((&DAT_68193b76)[uVar7 * 8] != '\0') { */
          /* FIXUP(C2374): iVar8 = (uint)(byte)(&DAT_68193b75)[uVar7 * 8] + local_c; */
          /* FIXUP(C2099): local_30 = (byte *)(uint)(byte)(&DAT_68193b74)[uVar7 * 8]; */
          /* FIXUP(C2374): local_1c = (byte *)0x0; */
          /* FIXUP(C2059): if ((byte *)(uint)(byte)(&DAT_68193b74)[uVar7 * 8] != (byte *)0x0) { */
            /* FIXUP(C2059): do { */
              pbVar15 = local_1c;
              /* FIXUP(C2099): uVar7 = js_getObjectFlags((int)pbVar9,(int)local_1c); */
              /* FIXUP(C2059): if (uVar7 != 0) { */
                /* FIXUP(C2065): iVar14 = (int)(char)*local_34 * uVar7 + iVar8; */
                /* FIXUP(C2059): if (iVar14 < iVar8) { */
                  pvVar6 = (void *)0x0;
                }
                /* FIXUP(C2059): else { */
                  pvVar6 = (void *)((int)local_24 - (int)local_14 >> 4);
                }
                /* FIXUP(C2065): iVar4 = js_callGetter(pvVar6,iVar14,(int)&local_44); */
                /* FIXUP(C2065): iVar12 = (int)pbVar9 - *(int *)(param_2 + 0x68); */
                /* FIXUP(C2374): iVar14 = js_allocObjectWithProto(param_1,param_2,iVar12,(int)local_1c, */
                                      /* FIXUP(C2065): ((((*(int *)(iVar4 + 4) - *(int *)(iVar4 + 8)) - iVar8) - */
                                       /* FIXUP(C2065): (int)local_10) + iVar14) * (int)(char)*local_34); */
                /* FIXUP(C2059): if (iVar14 == 0) { */
                  return 0;
                }
                /* FIXUP(C2374): pbVar9 = (byte *)(iVar12 + *(int *)(param_2 + 0x68)); */
                /* FIXUP(C2065): local_18 = (byte *)(*(int *)(param_2 + 0x6c) + *(int *)(param_2 + 0x68)); */
                /* FIXUP(C2099): pbVar15 = local_1c; */
              /* FIXUP(C2059): } */
              /* FIXUP(C2374): local_1c = pbVar15 + 1; */
            /* FIXUP(C2059): } while (pbVar15 + 1 < local_30); */
          /* FIXUP(C2059): } */
        /* FIXUP(C2059): } */
        /* FIXUP(C2059): if ((*pbVar9 & 0xf8) < 0xc0) { */
          /* FIXUP(C2374): uVar7 = (uint)(*pbVar9 >> 3); */
        /* FIXUP(C2059): } */
        /* FIXUP(C2059): else { */
          /* FIXUP(C2374): uVar7 = 0x18; */
        /* FIXUP(C2059): } */
        /* FIXUP(C2059): if ((&DAT_68193b74)[uVar7 * 8] == '\0') { */
          iVar8 = 1;
        /* FIXUP(C2059): } */
        /* FIXUP(C2059): else { */
          /* FIXUP(C2374): iVar8 = js_getObjectType(pbVar9); */
        /* FIXUP(C2059): } */
        /* FIXUP(C2374): pbVar9 = pbVar9 + iVar8; */
      /* FIXUP(C2059): } while (pbVar9 < local_18); */
    /* FIXUP(C2059): } */
    /* FIXUP(C2065): piVar13 = *(int **)(param_2 + 0x78); */
    /* FIXUP(C2065): local_34 = *(uint **)(param_2 + 0x7c); */
    /* FIXUP(C2059): if (piVar13 < local_34) { */
      /* FIXUP(C2059): do { */
        /* FIXUP(C2065): local_c = *piVar13; */
        /* FIXUP(C2065): iVar8 = js_callGetter((void *)0x0,local_c,(int)&local_44); */
        /* FIXUP(C2099): iVar4 = *(int *)(iVar8 + 4) - *(int *)(iVar8 + 8); */
        /* FIXUP(C2065): *piVar13 = iVar4 + local_c; */
        /* FIXUP(C2065): iVar14 = js_callGetter((void *)(iVar8 - (int)local_14 >> 4),piVar13[1] + local_c, */
                              /* FIXUP(C2059): (int)&local_44); */
        /* FIXUP(C2059): if (iVar14 != iVar8) { */
          /* FIXUP(C2065): piVar13[1] = ((*(int *)(iVar14 + 4) - *(int *)(iVar14 + 8)) - iVar4) + piVar13[1]; */
        /* FIXUP(C2059): } */
        /* FIXUP(C2374): iVar8 = piVar13[2]; */
        /* FIXUP(C2059): if (iVar8 != 0) { */
          /* FIXUP(C2065): iVar14 = js_callGetter((void *)(iVar14 - (int)local_14 >> 4),iVar8,(int)&local_44); */
          /* FIXUP(C2369): piVar13[2] = (*(int *)(iVar14 + 4) - *(int *)(iVar14 + 8)) + iVar8; */
        /* FIXUP(C2059): } */
        /* FIXUP(C2040): piVar13 = piVar13 + 3; */
      /* FIXUP(C2059): } while (piVar13 < local_34); */
    /* FIXUP(C2059): } */
  /* FIXUP(C2059): } */
  /* FIXUP(C2065): uVar7 = crypto_decompileNode(*(uint *)(param_2 + 0x90)); */
  /* FIXUP(C2374): uVar7 = (1 << ((byte)uVar7 & 0x1f)) * 0x10; */
  /* FIXUP(C2059): if (uVar7 < 0x1001) { */
    /* FIXUP(C2374): uVar7 = 0x1000; */
  /* FIXUP(C2059): } */
  /* FIXUP(C2143): javascript_getSlotByName((int *)(param_1 + 0x70),*(int *)(param_2 + 0x84),uVar7); */
  /* FIXUP(C2059): *(undefined4 *)(param_2 + 0x84) = 0; */
  /* FIXUP(C2059): javascript_objectPutSlot(param_2,*(int *)(param_2 + 0x88)); */
  /* FIXUP(C2059): *(int *)(param_2 + 0x88) = extraout_ECX_00; */
  /* FIXUP(C2059): *(int *)(param_2 + 0x94) = extraout_ECX_00; */
  /* FIXUP(C2059): *(int *)(param_2 + 0x90) = extraout_ECX_00; */
  /* FIXUP(C2059): return extraout_ECX_00 + 1; */
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: javascript_objectSealProperties (FUN_6813fe60)
// Address: 6813fe60
// Size: 239 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_objectSealProperties(int *param_1)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int *piVar1;
  undefined4 uVar2;
  int *in_EAX;
  int iVar3;
  uint uVar4;
  int unaff_EBX;
  void *unaff_ESI;
  undefined1 uVar5;
  
  if (in_EAX != (int *)0x0) {
    for (piVar1 = *(int **)((int)unaff_ESI + 8); piVar1 != param_1; piVar1 = (int *)piVar1[7]) {
      if (*piVar1 == 8) {
        iVar3 = js_setPropertyFlag(unaff_EBX,(int)unaff_ESI,0x98);
        if (iVar3 < 0) {
          return 0;
        }
        *in_EAX = 0x99;
        goto LAB_6813fe8a;
      }
    }
    if (*in_EAX == 5) {
      return 1;
    }
  }
LAB_6813fe8a:
  piVar1 = *(int **)((int)unaff_ESI + 8);
  uVar2 = *(undefined4 *)((int)unaff_ESI + 0x60);
  do {
    if (piVar1 == param_1) {
      *(undefined4 *)((int)unaff_ESI + 0x60) = uVar2;
      return 1;
    }
    switch(*piVar1) {
    case 5:
    case 7:
      uVar4 = js_allocObject(unaff_EBX,(int)unaff_ESI,0xb);
      if ((int)uVar4 < 0) {
        return 0;
      }
      uVar5 = 4;
      break;
    default:
      goto switchD_6813feae_caseD_6;
    case 8:
      uVar4 = js_allocObject(unaff_EBX,(int)unaff_ESI,0xb);
      if ((int)uVar4 < 0) {
        return 0;
      }
      piVar1[4] = (*(int **)((int)unaff_ESI + 0x40))[2] - **(int **)((int)unaff_ESI + 0x40);
      iVar3 = js_defineProperty(unaff_ESI,unaff_EBX,0x97);
      goto LAB_6813ff2d;
    case 9:
      uVar4 = js_allocObject(unaff_EBX,(int)unaff_ESI,0xb);
      if ((int)uVar4 < 0) {
        return 0;
      }
      uVar5 = 0x51;
      break;
    case 0xc:
      uVar5 = 0x6b;
    }
    iVar3 = js_setPropertyFlag(unaff_EBX,(int)unaff_ESI,uVar5);
LAB_6813ff2d:
    if (iVar3 < 0) {
      return 0;
    }
switchD_6813feae_caseD_6:
    piVar1 = (int *)piVar1[7];
  } while( true );
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: javascript_objectFreezeProperties (FUN_6813ff70)
// Address: 6813ff70
// Size: 121 bytes
// Params: void * param_1, uint param_2, int * param_3, int param_4
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall javascript_objectFreezeProperties(void *param_1,uint param_2,int *param_3,int param_4)

{
  /* FIXUP(STUB): Original body disabled - Ghidra decompilation produced
     invalid C that could not be automatically fixed.
     Revisit this function to restore the original logic. */
#if 0  /* Original Ghidra output: */
  int *in_EAX;
  int iVar1;
  uint uVar2;
  int unaff_EDI;
  
  iVar1 = javascript_objectSealProperties(in_EAX);
  if (iVar1 == 0) {
    return -1;
  }
  if (param_4 == 0) {
    if ((unaff_EDI != 0) && (uVar2 = js_allocObject(param_2,(int)param_1,unaff_EDI), (int)uVar2 < 0))
    {
      return -1;
    }
  }
  else {
    uVar2 = js_allocObject(param_2,(int)param_1,unaff_EDI);
    if ((int)uVar2 < 0) {
      return -1;
    }
    iVar1 = js_allocObjectWithProto(param_2,(int)param_1,uVar2,0,*(uint *)(param_4 + 0xc));
    if (iVar1 == 0) {
      return -1;
    }
  }
  *param_3 = (*(int **)((int)param_1 + 0x40))[2] - **(int **)((int)param_1 + 0x40);
  iVar1 = js_defineProperty(param_1,param_2,0x95);
  return iVar1;
#endif
  return 0; /* FIXUP(STUB): zero return */
}



// ============================================================
// Function: javascript_objectIsSealed (FUN_6813fff0)
// Address: 6813fff0
// Size: 171 bytes
// Params: uint param_1, byte * param_2, undefined4 param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_objectIsSealed(uint param_1,byte *param_2,int *param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined1 local_5c [8];
  undefined4 local_54;
  int local_4c;
  int local_30;
  undefined4 local_28;
  
  iVar1 = javascript_objectSetParent(param_1,(int)param_2);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = *(int *)(param_1 + 0x34);
  if ((((iVar1 == 0) || (*(int *)(iVar1 + 0x10) != param_4)) ||
      (*(int *)(iVar1 + 8) != *(int *)(param_4 + 4))) ||
     (*(int *)(iVar1 + 0x34) != *(int *)(param_4 + 4))) {
    memset(local_5c,0,0x58);
    local_54 = *(undefined4 *)(param_4 + 4);
    local_4c = param_4;
    *(undefined1 **)(param_1 + 0x34) = local_5c;
    local_30 = iVar1;
    local_28 = local_54;
  }
  iVar2 = crypto_bigEval((uint *)param_1,(uint *)param_2,param_3);
  *(int *)(param_1 + 0x34) = iVar1;
  if (iVar2 != 0) {
    piVar3 = runtime_loadExternalScript(param_1,(int)param_2,param_4);
    *(int **)(param_4 + 0xc) = piVar3;
    if (piVar3 != (int *)0x0) {
      if ((*param_2 & 0x80) != 0) {
        *(byte *)(param_4 + 0x16) = *(byte *)(param_4 + 0x16) | 0x80;
      }
      return 1;
    }
  }
  return 0;
}



