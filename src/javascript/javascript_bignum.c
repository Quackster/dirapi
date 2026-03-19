// Module: javascript
// Topic: Arbitrary precision arithmetic (bignum), number-to-string conversion
// Address range: 0x681397f0 - 0x6813cc40
// Functions (26):

//   javascript_gcCollect
//   js_bignumFree
//   javascript_gcProcessRoots
//   js_bignumAlloc
//   js_freePooledObject
//   js_bignumMultiply
//   javascript_bignumAdd
//   javascript_bignumCountLeadingZeros
//   javascript_bignumSubtract
//   js_bignumNormalize
//   javascript_bignumMultiplyFull
//   js_bignumShift
//   js_bignumDivide
//   js_bignumCompare
//   javascript_bignumDivideRemainder
//   javascript_bignumSetFromDouble
//   javascript_bignumSetFromInt
//   javascript_bignumExtractExponent
//   javascript_bignumConvertFromDouble
//   javascript_numberToStringRadix
//   javascript_numberToFixed
//   javascript_bignumDivideQuotient
//   javascript_numberToExponential
//   javascript_numberToPrecision
//   javascript_numberToStringMethod
//   javascript_numberValueOfMethod

// ============================================================
// Function: javascript_gcCollect (FUN_681397f0)
// Address: 681397f0
// Size: 1520 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcCollect(int param_1,uint param_2)
{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  int *piVar9;
  uint *puVar10;
  uint *puVar11;
  uint *puVar12;
  uint *local_1c;
  int *local_18;
  int local_14;
  uint *local_10;
  int *local_c;
  int *local_8;
  
  piVar9 = *(int **)(param_1 + 0x14);
  if ((((*piVar9 == 2) && (piVar9[0x12] == 0)) || ((param_2 & 2) != 0)) &&
     ((((local_8 = piVar9, (code *)piVar9[0x19] == (code *)0x0 ||
        (iVar4 = (*(code *)piVar9[0x19])(param_1,0), iVar4 != 0)) || ((param_2 & 2) != 0)) &&
      ((char)piVar9[0x18] != '\0')))) {
    piVar9[0x16] = piVar9[0x16] + 1;
    *(undefined1 *)(piVar9 + 0x18) = 0;
    if ((uint)piVar9[0x16] < 2) {
      *(undefined1 *)((int)piVar9 + 0x61) = 1;
      piVar9[0x1a] = 0;
      certificates_enableGc(param_1);
      certificates_initArena(param_1);
      while( true ) {
        piVar9[0x17] = piVar9[0x17] + 1;
        javascript_hashTableIterate(piVar9 + 8,javascript_gcMarkScopeEntry,param_1);
        if ((int *)piVar9[0x10] != (int *)0x0) {
          javascript_hashTableIterate((int *)piVar9[0x10],javascript_gcMarkLinkedEntry,param_1);
        }
        javascript_gcTraverseTable((int)(piVar9 + 0x1b),param_2,javascript_gcMarkAtomValue,param_1);
        local_14 = 0;
        local_c = (int *)xtra_iterateObjects((int)piVar9,1,&local_14);
        local_18 = local_8;
        while (local_8 = local_18, local_c != (int *)0x0) {
          puVar11 = *(uint **)((int)local_c + 0x34);
          piVar9 = local_c;
          if (puVar11 == (uint *)0x0) {
            puVar11 = *(uint **)((int)local_c + 0x150);
          }
          else {
            puVar11[0x14] = *(uint *)((int)local_c + 0x150);
          }
          while (local_10 = puVar11, local_c = piVar9, puVar11 != (uint *)0x0) {
            do {
              if (*puVar11 != 0) {
                js_lookupAtom(param_1,*puVar11,0);
              }
              if (puVar11[1] != 0) {
                js_lookupAtom(param_1,puVar11[1],0);
              }
              if (puVar11[2] != 0) {
                js_lookupAtom(param_1,puVar11[2],0);
              }
              if (puVar11[3] != 0) {
                runtime_freeObjectSlots(param_1,puVar11[3]);
                puVar6 = (uint *)puVar11[0x10];
                if (puVar6 != (uint *)0x0) {
                  iVar4 = *(int *)(puVar11[3] + 0x20);
                  if (puVar11[0xf] - (int)puVar6 < (uint)(iVar4 * 4)) {
                    iVar4 = (int)(puVar11[0xf] - (int)puVar6) >> 2;
                  }
                  puVar10 = puVar6 + iVar4;
                  for (; puVar6 < puVar10; puVar6 = puVar6 + 1) {
                    uVar5 = *puVar6;
                    if (((uVar5 & 1) == 0) && (((byte)uVar5 & 7) != 6)) {
                      js_lookupAtom(param_1,uVar5 & 0xfffffff8,0);
                    }
                  }
                }
              }
              js_lookupAtom(param_1,puVar11[5],0);
              puVar6 = (uint *)puVar11[7];
              if (puVar6 != (uint *)0x0) {
                uVar5 = puVar11[6];
                if ((puVar11[4] != 0) &&
                   (uVar7 = (uint)*(ushort *)(puVar11[4] + 0x10), uVar5 < uVar7)) {
                  uVar5 = uVar7;
                }
                puVar10 = puVar6 + uVar5;
                for (; puVar6 < puVar10; puVar6 = puVar6 + 1) {
                  uVar5 = *puVar6;
                  if (((uVar5 & 1) == 0) && (((byte)uVar5 & 7) != 6)) {
                    js_lookupAtom(param_1,uVar5 & 0xfffffff8,0);
                  }
                }
              }
              uVar5 = puVar11[8];
              if (((uVar5 & 1) == 0) && (((byte)uVar5 & 7) != 6)) {
                js_lookupAtom(param_1,uVar5 & 0xfffffff8,0);
              }
              puVar6 = (uint *)puVar11[10];
              if (puVar6 != (uint *)0x0) {
                puVar10 = puVar6 + puVar11[9];
                for (; puVar6 < puVar10; puVar6 = puVar6 + 1) {
                  uVar5 = *puVar6;
                  if (((uVar5 & 1) == 0) && (((byte)uVar5 & 7) != 6)) {
                    js_lookupAtom(param_1,uVar5 & 0xfffffff8,0);
                  }
                }
              }
              js_lookupAtom(param_1,puVar11[0xd],0);
              if (puVar11[0x12] != 0) {
                js_lookupAtom(param_1,puVar11[0x12],0);
              }
              if (puVar11[0x15] != 0) {
                uVar5 = ((int *)puVar11[0x15])[1];
                iVar4 = *(int *)puVar11[0x15];
                uVar7 = 0;
                if (uVar5 != 0) {
                  do {
                    iVar2 = *(int *)(iVar4 + uVar7 * 4);
                    if ((iVar2 != 0) && ((*(byte *)(iVar2 + 0x10) & 4) == 0)) {
                      js_allocAtomSlot(param_1,iVar2);
                    }
                    uVar7 = uVar7 + 1;
                  } while (uVar7 < uVar5);
                }
              }
              puVar11 = (uint *)puVar11[0xb];
            } while (puVar11 != (uint *)0x0);
            piVar9 = local_c;
            puVar11 = (uint *)local_10[0x14];
          }
          if (*(int *)((int)piVar9 + 0x34) != 0) {
            *(undefined4 *)(*(int *)((int)piVar9 + 0x34) + 0x50) = 0;
          }
          js_lookupAtom(param_1,*(uint *)((int)piVar9 + 0x8c),0);
          js_lookupAtom(param_1,*(uint *)((int)piVar9 + 0x90),0);
          js_lookupAtom(param_1,*(uint *)((int)piVar9 + 0x94),0);
          js_lookupAtom(param_1,*(uint *)((int)piVar9 + 0x98),0);
          js_lookupAtom(param_1,*(uint *)((int)piVar9 + 0x9c),0);
          puVar11 = (uint *)((int)piVar9 + 0xa0);
          iVar4 = 4;
          do {
            js_lookupAtom(param_1,*puVar11,0);
            piVar9 = local_c;
            puVar11 = puVar11 + 1;
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
          iVar4 = *(int *)((int)local_c + 0xb0);
          if ((iVar4 != 0) && ((*(byte *)(iVar4 + 0x10) & 4) == 0)) {
            js_allocAtomSlot(param_1,iVar4);
          }
          if (((*(char *)((int)piVar9 + 0x15a) != '\0') &&
              (uVar5 = *(uint *)((int)piVar9 + 0x15c), (uVar5 & 1) == 0)) &&
             (((byte)uVar5 & 7) != 6)) {
            js_lookupAtom(param_1,uVar5 & 0xfffffff8,0);
          }
          if (((*(char *)((int)piVar9 + 0x158) != '\0') &&
              (uVar5 = *(uint *)((int)piVar9 + 0x154), (uVar5 & 1) == 0)) &&
             (((byte)uVar5 & 7) != 6)) {
            js_lookupAtom(param_1,uVar5 & 0xfffffff8,0);
          }
          for (piVar9 = *(int **)((int)piVar9 + 0x174); piVar9 != (int *)0x0;
              piVar9 = (int *)piVar9[1]) {
            puVar11 = (uint *)(piVar9 + 2);
            puVar6 = puVar11 + *piVar9;
            for (; puVar11 < puVar6; puVar11 = puVar11 + 1) {
              uVar5 = *puVar11;
              if (((uVar5 & 1) == 0) && (((byte)uVar5 & 7) != 6)) {
                js_lookupAtom(param_1,uVar5 & 0xfffffff8,0);
              }
            }
          }
          local_c = (int *)xtra_iterateObjects((int)local_8,1,&local_14);
          local_18 = local_8;
        }
        if ((code *)local_18[0x19] != (code *)0x0) {
          (*(code *)local_18[0x19])(param_1,2);
        }
        javascript_gcResetMarks((int)(local_18 + 0x1b));
        strings_sweepTable((int)local_18);
        piVar9 = (int *)local_18[1];
        local_c = piVar9;
        if (piVar9 != (int *)0x0) {
          do {
            puVar11 = (uint *)piVar9[1];
            puVar6 = (uint *)piVar9[3];
            puVar8 = (uint *)((uint)(puVar11 + 0x100) & 0xfffffc00);
            puVar10 = puVar8;
            local_10 = puVar6;
            local_c = piVar9;
            if (puVar8 < puVar6) {
              do {
                puVar12 = puVar11;
                if (((uint)puVar10 & 0x3ff) == 0) {
                  puVar12 = (uint *)((int)puVar11 + 1);
                  puVar10 = puVar10 + 2;
                }
                bVar1 = (byte)*puVar12;
                if ((bVar1 & 8) == 0) {
                  if ((bVar1 & 0xf0) == 0) {
                    pcVar3 = (code *)(&DAT_681969a0)[bVar1 & 7];
                    if (pcVar3 != (code *)0x0) {
                      *(byte *)puVar12 = bVar1 | 0x10;
                      if (3 < (bVar1 & 7)) {
                        certificates_removeFromCache((uint)puVar10);
                      }
                      (*pcVar3)(param_1,puVar10);
                    }
                    *(byte *)puVar12 = 0x10;
                    local_8[0x13] = local_8[0x13] + -9;
                    piVar9 = local_c;
                    puVar6 = local_10;
                  }
                }
                else {
                  *(byte *)puVar12 = bVar1 & 0xf7;
                }
                puVar11 = (uint *)((int)puVar12 + 1);
                if (puVar11 == puVar8) {
                  puVar11 = (uint *)((int)puVar12 + 0x2001);
                }
                puVar10 = puVar10 + 2;
              } while (puVar10 < puVar6);
            }
            piVar9 = (int *)*piVar9;
          } while (piVar9 != (int *)0x0);
          local_c = (int *)0x0;
          local_18 = local_8;
        }
        local_18 = local_18 + 1;
        piVar9 = (int *)*local_18;
        if (piVar9 != (int *)0x0) {
          local_1c = (uint *)(local_8 + 0x11);
          local_c = (int *)0x1;
          *local_1c = 0;
          do {
            local_10 = (uint *)piVar9[3];
            puVar8 = (uint *)((uint)((uint *)piVar9[1] + 0x100) & 0xfffffc00);
            puVar11 = (uint *)piVar9[1];
            puVar10 = local_1c;
            for (puVar6 = puVar8; puVar6 < local_10; puVar6 = puVar6 + 2) {
              if (((uint)puVar6 & 0x3ff) == 0) {
                puVar11 = (uint *)((int)puVar11 + 1);
                puVar6 = puVar6 + 2;
              }
              if ((byte)*puVar11 == 0x10) {
                puVar6[1] = (uint)puVar11;
                *puVar10 = (uint)puVar6;
                puVar10 = puVar6;
              }
              else {
                local_c = (int *)0x0;
              }
              puVar12 = (uint *)((int)puVar11 + 1);
              if (puVar12 == puVar8) {
                puVar12 = (uint *)((int)puVar11 + 0x2001);
              }
              puVar11 = puVar12;
            }
            if (local_c == (int *)0x0) {
              local_c = (int *)0x1;
              local_1c = puVar10;
              local_18 = piVar9;
            }
            else {
              if ((int *)local_8[5] == piVar9) {
                local_8[5] = (int)(local_8 + 1);
              }
              *local_18 = *piVar9;
              js_freeHandle();
            }
            piVar9 = (int *)*local_18;
          } while (piVar9 != (int *)0x0);
          *local_1c = 0;
          if ((code *)local_8[0x19] != (code *)0x0) {
            (*(code *)local_8[0x19])(param_1,3);
          }
        }
        if ((uint)local_8[0x16] < 2) break;
        local_8[0x16] = 1;
        piVar9 = local_8;
      }
      certificates_disableGc(param_1);
      local_8[0x16] = 0;
      local_8[0x14] = local_8[0x13];
      *(undefined1 *)((int)local_8 + 0x61) = 0;
      if ((code *)local_8[0x19] != (code *)0x0) {
        (*(code *)local_8[0x19])(param_1,1);
      }
    }
  }
  return 0;
}



// ============================================================
// Function: js_bignumFree (FUN_68139df0)
// Address: 68139df0
// Size: 224 bytes
// Params: int param_1, uint param_2
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * js_bignumFree(int param_1,uint param_2)

{
  uint *puVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  uint *puVar6;
  undefined1 *puVar7;
  uint *puVar8;
  undefined4 *extraout_EDX;
  undefined4 *puVar9;
  
  iVar2 = *(int *)(param_1 + 0x14);
  bVar4 = false;
  bVar5 = false;
  if (*(char *)(iVar2 + 0x61) != '\0') {
    return (undefined4 *)0x0;
  }
  puVar9 = *(undefined4 **)(iVar2 + 0x44);
  do {
    if (puVar9 != (undefined4 *)0x0) {
      *(undefined4 *)(iVar2 + 0x44) = *puVar9;
      puVar7 = (undefined1 *)puVar9[1];
LAB_68139ea2:
      *puVar7 = (char)param_2;
      *(int *)(iVar2 + 0x4c) = *(int *)(iVar2 + 0x4c) + 9;
      *(undefined4 **)(param_1 + 0x90 + (param_2 & 7) * 4) = puVar9;
      *puVar9 = 0;
      puVar9[1] = 0;
      return puVar9;
    }
    puVar6 = (uint *)0x0;
    if ((*(uint *)(iVar2 + 0x4c) < *(uint *)(iVar2 + 0x54)) &&
       ((bVar4 || (*(uint *)(iVar2 + 0x68) < *(uint *)(iVar2 + 0x54))))) {
      iVar3 = *(int *)(iVar2 + 0x14);
      puVar6 = *(uint **)(iVar3 + 0xc);
      puVar1 = puVar6 + 2;
      if ((uint *)(*(uint *)(iVar3 + 8) & 0xfffffc00) < puVar1) {
        puVar6 = javascript_initPoolBlock();
      }
      else {
        puVar8 = puVar1;
        if (((uint)puVar6 & 0x3ff) == 0) {
          puVar8 = puVar6 + 4;
          puVar6 = puVar1;
        }
        *(uint **)(iVar3 + 0xc) = puVar8;
      }
    }
    if (puVar6 != (uint *)0x0) {
      puVar7 = (undefined1 *)js_getAtomSize((uint)puVar6);
      puVar9 = extraout_EDX;
      goto LAB_68139ea2;
    }
    if (bVar5) {
      xtra_reportError(param_1);
      return (undefined4 *)0x0;
    }
    *(undefined1 *)(iVar2 + 0x60) = 1;
    javascript_gcCollect(param_1,5);
    puVar9 = *(undefined4 **)(iVar2 + 0x44);
    bVar4 = true;
    bVar5 = true;
  } while( true );
}



// ============================================================
// Function: javascript_gcProcessRoots (FUN_68139ed0)
// Address: 68139ed0
// Size: 88 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_gcProcessRoots(int param_1,uint param_2)
{
  *(undefined4 *)(param_1 + 0x90) = 0;
  *(undefined4 *)(param_1 + 0x94) = 0;
  *(undefined4 *)(param_1 + 0x98) = 0;
  *(undefined4 *)(param_1 + 0x9c) = 0;
  *(undefined4 *)(param_1 + 0xa0) = 0;
  *(undefined4 *)(param_1 + 0xa4) = 0;
  *(undefined4 *)(param_1 + 0xa8) = 0;
  *(undefined4 *)(param_1 + 0xac) = 0;
  *(undefined4 *)(param_1 + 0xb0) = 0;
  *(undefined1 *)(*(int *)(param_1 + 0x14) + 0x60) = 1;
  javascript_gcCollect(param_1,param_2);
  javascript_freeArenaPool();
  return 0;
}



// ============================================================
// Function: js_bignumAlloc (FUN_68139f30)
// Address: 68139f30
// Size: 87 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_bignumAlloc(void)
{
  undefined4 *puVar1;
  int iVar2;
  int unaff_EDI;
  
  puVar1 = (undefined4 *)(&DAT_681969c8)[unaff_EDI];
  if (puVar1 != (undefined4 *)0x0) {
    (&DAT_681969c8)[unaff_EDI] = *puVar1;
    puVar1[4] = 0;
    puVar1[3] = 0;
    return 0;
  }
  iVar2 = js_runGC();
  if (iVar2 == 0) {
    return 0;
  }
  *(int *)(iVar2 + 8) = 1 << ((byte)unaff_EDI & 0x1f);
  *(int *)(iVar2 + 4) = unaff_EDI;
  *(undefined4 *)(iVar2 + 0x10) = 0;
  *(undefined4 *)(iVar2 + 0xc) = 0;
  return 0;
}



// ============================================================
// Function: js_freePooledObject (FUN_68139f90)
// Address: 68139f90
// Size: 24 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_freePooledObject(void)
{
  undefined4 *in_EAX;
  
  if (in_EAX != (undefined4 *)0x0) {
    *in_EAX = (&DAT_681969c8)[in_EAX[1]];
    (&DAT_681969c8)[in_EAX[1]] = in_EAX;
  }
  return 0;
}



// ============================================================
// Function: js_bignumMultiply (FUN_68139fb0)
// Address: 68139fb0
// Size: 202 bytes
// Params: int param_1, uint param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_bignumMultiply(int param_1,uint param_2,int param_3)

{
  int iVar1;
  int iVar2;
  uint *puVar3;
  longlong lVar4;
  int local_c;
  
  iVar1 = *(int *)(param_1 + 0x10);
  iVar2 = param_3 >> 0x1f;
  puVar3 = (uint *)(param_1 + 0x14);
  local_c = 0;
  do {
    lVar4 = __allmul(*puVar3,0,param_2,(int)param_2 >> 0x1f);
    lVar4 = lVar4 + CONCAT44(iVar2,param_3);
    param_3 = (int)((ulonglong)lVar4 >> 0x20);
    *puVar3 = (uint)lVar4;
    local_c = local_c + 1;
    iVar2 = 0;
    puVar3 = puVar3 + 1;
  } while (local_c < iVar1);
  iVar2 = param_1;
  if (param_3 != 0) {
    if (*(int *)(param_1 + 8) <= iVar1) {
      iVar2 = js_bignumAlloc();
      if (iVar2 == 0) {
        js_freePooledObject();
        return 0;
      }
      memcpy((void *)(iVar2 + 0xc),(void *)(param_1 + 0xc),*(int *)(param_1 + 0x10) * 4 + 8);
      js_freePooledObject();
    }
    *(int *)(iVar2 + 0x14 + iVar1 * 4) = param_3;
    *(int *)(iVar2 + 0x10) = iVar1 + 1;
  }
  return iVar2;
}



// ============================================================
// Function: javascript_bignumAdd (FUN_6813a080)
// Address: 6813a080
// Size: 169 bytes
// Params: void * this, int param_1, undefined4 param_2
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall javascript_bignumAdd(void *this,int param_1,undefined4 param_2)

{
  char *pcVar1;
  int in_EAX;
  int iVar2;
  char *pcVar3;
  int iVar4;
  
  iVar4 = (param_1 + 8) / 9;
  iVar2 = 1;
  if (1 < iVar4) {
    do {
      iVar2 = iVar2 * 2;
    } while (iVar2 < iVar4);
  }
  iVar2 = js_bignumAlloc();
  if (iVar2 != 0) {
    iVar4 = 9;
    *(undefined4 *)(iVar2 + 0x14) = param_2;
    *(undefined4 *)(iVar2 + 0x10) = 1;
    if (in_EAX < 10) {
      pcVar3 = (char *)((int)this + 10);
    }
    else {
      pcVar1 = (char *)((int)this + 9);
      do {
        pcVar3 = pcVar1;
        iVar2 = js_bignumMultiply(iVar2,10,*pcVar3 + -0x30);
        if (iVar2 == 0) {
          return 0;
        }
        iVar4 = iVar4 + 1;
        pcVar1 = pcVar3 + 1;
      } while (iVar4 < in_EAX);
      pcVar3 = pcVar3 + 2;
    }
    if (param_1 <= iVar4) {
      return iVar2;
    }
    while( true ) {
      iVar2 = js_bignumMultiply(iVar2,10,*pcVar3 + -0x30);
      pcVar3 = pcVar3 + 1;
      if (iVar2 == 0) break;
      iVar4 = iVar4 + 1;
      if (param_1 <= iVar4) {
        return iVar2;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_bignumCountLeadingZeros (FUN_6813a130)
// Address: 6813a130
// Size: 80 bytes
// Params: uint param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall javascript_bignumCountLeadingZeros(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  if ((param_1 & 0xffff0000) == 0) {
    iVar1 = 0x10;
    param_1 = param_1 << 0x10;
  }
  if ((param_1 & 0xff000000) == 0) {
    iVar1 = iVar1 + 8;
    param_1 = param_1 << 8;
  }
  if ((param_1 & 0xf0000000) == 0) {
    iVar1 = iVar1 + 4;
    param_1 = param_1 << 4;
  }
  if ((param_1 & 0xc0000000) == 0) {
    iVar1 = iVar1 + 2;
    param_1 = param_1 * 4;
  }
  if ((-1 < (int)param_1) && (iVar1 = iVar1 + 1, (param_1 & 0x40000000) == 0)) {
    iVar1 = 0x20;
  }
  return iVar1;
}



// ============================================================
// Function: javascript_bignumSubtract (FUN_6813a180)
// Address: 6813a180
// Size: 115 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_bignumSubtract(void)

{
  int iVar1;
  uint uVar2;
  uint *unaff_ESI;
  
  uVar2 = *unaff_ESI;
  if ((uVar2 & 7) == 0) {
    iVar1 = 0;
    if ((short)uVar2 == 0) {
      iVar1 = 0x10;
      uVar2 = uVar2 >> 0x10;
    }
    if ((char)uVar2 == '\0') {
      iVar1 = iVar1 + 8;
      uVar2 = uVar2 >> 8;
    }
    if ((uVar2 & 0xf) == 0) {
      iVar1 = iVar1 + 4;
      uVar2 = uVar2 >> 4;
    }
    if ((uVar2 & 3) == 0) {
      iVar1 = iVar1 + 2;
      uVar2 = uVar2 >> 2;
    }
    if ((uVar2 & 1) == 0) {
      iVar1 = iVar1 + 1;
      uVar2 = uVar2 >> 1;
      if (uVar2 == 0) {
        return 0x20;
      }
    }
  }
  else {
    if ((uVar2 & 1) != 0) {
      return 0;
    }
    if ((uVar2 & 2) == 0) {
      *unaff_ESI = uVar2 >> 2;
      return 2;
    }
    uVar2 = uVar2 >> 1;
    iVar1 = 1;
  }
  *unaff_ESI = uVar2;
  return iVar1;
}



// ============================================================
// Function: js_bignumNormalize (FUN_6813a200)
// Address: 6813a200
// Size: 37 bytes
// Params: undefined4 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int js_bignumNormalize(undefined4 param_1)
{
  int iVar1;
  
  iVar1 = js_bignumAlloc();
  if (iVar1 == 0) {
    return 0;
  }
  *(undefined4 *)(iVar1 + 0x10) = 1;
  *(undefined4 *)(iVar1 + 0x14) = param_1;
  return 0;
}



// ============================================================
// Function: javascript_bignumMultiplyFull (FUN_6813a230)
// Address: 6813a230
// Size: 267 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall javascript_bignumMultiplyFull(int param_1)
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int in_EAX;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  int *piVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  int iVar14;
  longlong lVar15;
  uint local_2c;
  
  iVar14 = in_EAX;
  if (*(int *)(param_1 + 0x10) < *(int *)(in_EAX + 0x10)) {
    iVar14 = param_1;
    param_1 = in_EAX;
  }
  iVar2 = *(int *)(param_1 + 0x10);
  iVar3 = *(int *)(iVar14 + 0x10);
  iVar5 = iVar2 + iVar3;
  iVar6 = js_bignumAlloc();
  if (iVar6 != 0) {
    puVar12 = (uint *)(iVar6 + 0x14);
    if (puVar12 < puVar12 + iVar5) {
      puVar13 = puVar12;
      for (iVar9 = ((uint)((int)(puVar12 + iVar5) + (-1 - (int)puVar12)) >> 2) + 1; iVar9 != 0;
          iVar9 = iVar9 + -1) {
        *puVar13 = 0;
        puVar13 = puVar13 + 1;
      }
    }
    puVar13 = (uint *)(iVar14 + 0x14);
    puVar1 = puVar13 + iVar3;
    while (puVar13 < puVar1) {
      uVar4 = *puVar13;
      puVar13 = puVar13 + 1;
      if (uVar4 != 0) {
        local_2c = 0;
        iVar14 = (param_1 + 0x14) - (int)puVar12;
        puVar11 = puVar12;
        do {
          lVar15 = __allmul(*(uint *)(iVar14 + (int)puVar11),0,uVar4,0);
          uVar7 = (uint)lVar15 + *puVar11;
          uVar8 = uVar7 + local_2c;
          local_2c = (int)((ulonglong)lVar15 >> 0x20) + (uint)CARRY4((uint)lVar15,*puVar11) +
                     (uint)CARRY4(uVar7,local_2c);
          *puVar11 = uVar8;
          puVar11 = puVar11 + 1;
        } while ((uint)(iVar14 + (int)puVar11) < (uint)(param_1 + 0x14 + iVar2 * 4));
        *puVar11 = local_2c;
      }
      puVar12 = puVar12 + 1;
    }
    piVar10 = (int *)(iVar6 + 0x14 + iVar5 * 4);
    while ((0 < iVar5 && (piVar10 = piVar10 + -1, *piVar10 == 0))) {
      iVar5 = iVar5 + -1;
    }
    *(int *)(iVar6 + 0x10) = iVar5;
    return 0;
  }
  return 0;
}



// ============================================================
// Function: js_bignumShift (FUN_6813a340)
// Address: 6813a340
// Size: 206 bytes
// Params: uint param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_bignumShift(uint param_1)

{
  int in_EAX;
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (((param_1 & 3) != 0) &&
     (in_EAX = js_bignumMultiply(in_EAX,*(uint *)("gc-arena" + (param_1 & 3) * 4 + 8),0), in_EAX == 0)) {
    return 0;
  }
  param_1 = (int)param_1 >> 2;
  if (param_1 == 0) {
    return in_EAX;
  }
  puVar1 = DAT_681969c0;
  if (DAT_681969c0 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)js_bignumNormalize(0x271);
    DAT_681969c0 = puVar1;
    if (puVar1 == (undefined4 *)0x0) {
      js_freePooledObject();
      return 0;
    }
    *puVar1 = 0;
  }
  while( true ) {
    puVar2 = puVar1;
    if ((param_1 & 1) != 0) {
      in_EAX = javascript_bignumMultiplyFull(in_EAX);
      js_freePooledObject();
      if (in_EAX == 0) {
        return 0;
      }
    }
    param_1 = (int)param_1 >> 1;
    if (param_1 == 0) break;
    puVar1 = (undefined4 *)*puVar2;
    if ((undefined4 *)*puVar2 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)javascript_bignumMultiplyFull((int)puVar2);
      if (puVar1 == (undefined4 *)0x0) {
        js_freePooledObject();
        return 0;
      }
      *puVar1 = 0;
      *puVar2 = puVar1;
    }
  }
  return in_EAX;
}



// ============================================================
// Function: js_bignumDivide (FUN_6813a410)
// Address: 6813a410
// Size: 202 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int js_bignumDivide(int param_1,uint param_2)

{
  uint *puVar1;
  sbyte sVar2;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  uint *puVar7;
  uint *puVar8;
  int iVar9;
  uint uVar10;
  int local_c;
  
  iVar9 = (int)param_2 >> 5;
  local_c = iVar9 + 1 + *(int *)(param_1 + 0x10);
  for (iVar3 = *(int *)(param_1 + 8); iVar3 < local_c; iVar3 = iVar3 * 2) {
  }
  iVar3 = js_bignumAlloc();
  if (iVar3 != 0) {
    puVar7 = (uint *)(iVar3 + 0x14);
    iVar6 = iVar9;
    puVar4 = puVar7;
    if (0 < iVar9) {
      for (; iVar6 != 0; iVar6 = iVar6 + -1) {
        *puVar4 = 0;
        puVar4 = puVar4 + 1;
      }
      puVar7 = puVar7 + iVar9;
    }
    puVar4 = (uint *)(param_1 + 0x14);
    puVar1 = puVar4 + *(int *)(param_1 + 0x10);
    if ((param_2 & 0x1f) == 0) {
      do {
        *puVar7 = *puVar4;
        puVar4 = puVar4 + 1;
        puVar7 = puVar7 + 1;
      } while (puVar4 < puVar1);
    }
    else {
      sVar2 = (sbyte)(param_2 & 0x1f);
      uVar10 = 0;
      do {
        puVar5 = puVar4 + 1;
        puVar8 = puVar7 + 1;
        *puVar7 = *puVar4 << sVar2 | uVar10;
        uVar10 = *puVar4 >> (0x20U - sVar2 & 0x1f);
        puVar4 = puVar5;
        puVar7 = puVar8;
      } while (puVar5 < puVar1);
      *puVar8 = uVar10;
      if (uVar10 != 0) {
        local_c = local_c + 1;
      }
    }
    *(int *)(iVar3 + 0x10) = local_c + -1;
  }
  js_freePooledObject();
  return iVar3;
}



// ============================================================
// Function: js_bignumCompare (FUN_6813a4e0)
// Address: 6813a4e0
// Size: 65 bytes
// Params: undefined4 param_1, int param_2
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall js_bignumCompare(undefined4 param_1,int param_2)

{
  uint *puVar1;
  int iVar2;
  int in_EAX;
  int iVar3;
  uint *puVar4;
  uint *puVar5;
  
  iVar2 = *(int *)(in_EAX + 0x10);
  iVar3 = *(int *)(param_2 + 0x10) - iVar2;
  if (iVar3 != 0) {
    return iVar3;
  }
  puVar4 = (uint *)(param_2 + 0x10 + iVar2 * 4);
  puVar5 = (uint *)(in_EAX + 0x10 + iVar2 * 4);
  if (*puVar4 == *puVar5) {
    do {
      if (puVar4 <= (uint *)(param_2 + 0x14)) {
        return 0;
      }
      puVar1 = puVar4 + -1;
      puVar4 = puVar4 + -1;
      puVar5 = puVar5 + -1;
    } while (*puVar1 == *puVar5);
  }
  return (-(uint)(*puVar4 < *puVar5) & 0xfffffffe) + 1;
}



// ============================================================
// Function: javascript_bignumDivideRemainder (FUN_6813a530)
// Address: 6813a530
// Size: 269 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall javascript_bignumDivideRemainder(int param_1)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  int in_EAX;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int *piVar8;
  uint *puVar9;
  uint *puVar10;
  int iVar11;
  uint local_20;
  uint local_8;
  
  iVar4 = js_bignumCompare(param_1,param_1);
  if (iVar4 == 0) {
    iVar4 = js_bignumAlloc();
    if (iVar4 != 0) {
      *(undefined4 *)(iVar4 + 0x14) = 0;
      *(undefined4 *)(iVar4 + 0x10) = 1;
      return iVar4;
    }
  }
  else {
    iVar11 = in_EAX;
    if (iVar4 < 0) {
      iVar11 = param_1;
      param_1 = in_EAX;
    }
    local_8 = (uint)(iVar4 < 0);
    iVar4 = js_bignumAlloc();
    if (iVar4 != 0) {
      *(uint *)(iVar4 + 0xc) = local_8;
      iVar7 = *(int *)(param_1 + 0x10);
      puVar9 = (uint *)(param_1 + 0x14);
      puVar1 = puVar9 + iVar7;
      iVar2 = *(int *)(iVar11 + 0x10);
      piVar8 = (int *)(iVar4 + 0x14);
      puVar10 = (uint *)((int)piVar8 + (iVar11 - iVar4));
      local_20 = 0;
      do {
        uVar3 = *puVar10;
        uVar5 = *puVar9 - uVar3;
        iVar6 = uVar5 - local_20;
        puVar10 = puVar10 + 1;
        local_20 = -(uint)(uVar5 < local_20) - (uint)(*puVar9 < uVar3) & 1;
        *piVar8 = iVar6;
        puVar9 = puVar9 + 1;
        piVar8 = piVar8 + 1;
      } while (puVar10 < (uint *)(iVar11 + 0x14 + iVar2 * 4));
      for (; puVar9 < puVar1; puVar9 = puVar9 + 1) {
        iVar11 = *puVar9 - local_20;
        local_20 = -(uint)(*puVar9 < local_20) & 1;
        *piVar8 = iVar11;
        piVar8 = piVar8 + 1;
      }
      piVar8 = piVar8 + -1;
      iVar11 = *piVar8;
      while (iVar11 == 0) {
        piVar8 = piVar8 + -1;
        iVar7 = iVar7 + -1;
        iVar11 = *piVar8;
      }
      *(int *)(iVar4 + 0x10) = iVar7;
      return iVar4;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_bignumSetFromDouble (FUN_6813a640)
// Address: 6813a640
// Size: 118 bytes
// Params: undefined4 param_1, uint param_2
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 javascript_bignumSetFromDouble(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = (param_2 & 0x7ff00000) + 0xfcc00000;
  if (0 < (int)uVar1) {
    return (float10)(double)((ulonglong)uVar1 << 0x20);
  }
  iVar2 = (int)-uVar1 >> 0x14;
  if (iVar2 < 0x14) {
    return (float10)(double)((ulonglong)(uint)(0x80000 >> ((byte)iVar2 & 0x1f)) << 0x20);
  }
  if (0x1e < iVar2 + -0x14) {
    return (float10)4.94065645841247e-324;
  }
  return (float10)(double)(ulonglong)(uint)(1 << (0x1fU - (char)(iVar2 + -0x14) & 0x1f));
}



// ============================================================
// Function: javascript_bignumSetFromInt (FUN_6813a6c0)
// Address: 6813a6c0
// Size: 246 bytes
// Params: int * param_1
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 javascript_bignumSetFromInt(int *param_1)

{
  char cVar1;
  int in_EAX;
  int iVar2;
  byte bVar3;
  uint extraout_EDX;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  
  uVar6 = in_EAX + 0x14;
  uVar5 = in_EAX + 0x10 + *(int *)(in_EAX + 0x10) * 4;
  iVar2 = javascript_bignumCountLeadingZeros(*(uint *)(in_EAX + 0x10 + *(int *)(in_EAX + 0x10) * 4));
  *param_1 = 0x20 - iVar2;
  if (iVar2 < 0xb) {
    cVar1 = (char)iVar2;
    bVar3 = 0xb - cVar1;
    uVar4 = extraout_EDX >> (bVar3 & 0x1f);
    if (uVar6 < uVar5) {
      return (float10)(double)(CONCAT44(uVar4,extraout_EDX << (cVar1 + 0x15U & 0x1f) |
                                              *(uint *)(uVar5 - 4) >> (bVar3 & 0x1f)) |
                              0x3ff0000000000000);
    }
    return (float10)(double)(CONCAT44(uVar4,extraout_EDX << (cVar1 + 0x15U & 0x1f) |
                                            0U >> (bVar3 & 0x1f)) | 0x3ff0000000000000);
  }
  if (uVar6 < uVar5) {
    uVar4 = *(uint *)(uVar5 - 4);
    uVar5 = uVar5 - 4;
  }
  else {
    uVar4 = 0;
  }
  if (iVar2 + -0xb != 0) {
    bVar3 = (byte)(iVar2 + -0xb);
    if (uVar6 < uVar5) {
      uVar6 = *(uint *)(uVar5 - 4);
    }
    else {
      uVar6 = 0;
    }
    return (float10)(double)(CONCAT44(uVar4 >> (0x20 - bVar3 & 0x1f) |
                                      extraout_EDX << (bVar3 & 0x1f),
                                      uVar6 >> (0x20 - bVar3 & 0x1f) | uVar4 << (bVar3 & 0x1f)) |
                            0x3ff0000000000000);
  }
  return (float10)(double)(CONCAT44(extraout_EDX,uVar4) | 0x3ff0000000000000);
}



// ============================================================
// Function: javascript_bignumExtractExponent (FUN_6813a7c0)
// Address: 6813a7c0
// Size: 250 bytes
// Params: uint param_1, uint param_2, int * param_3, int * param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_bignumExtractExponent(uint param_1,uint param_2,int *param_3,int *param_4)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int extraout_EDX;
  uint uVar5;
  uint uVar6;
  
  iVar1 = js_bignumAlloc();
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = (param_2 & 0x7fffffff) >> 0x14;
  uVar5 = param_2 & 0xfffff;
  if (uVar2 != 0) {
    uVar5 = uVar5 | 0x100000;
  }
  if (param_1 == 0) {
    iVar3 = javascript_bignumSubtract();
    *(uint *)(iVar1 + 0x14) = uVar5;
    iVar4 = 1;
    iVar3 = iVar3 + 0x20;
  }
  else {
    iVar3 = javascript_bignumSubtract();
    if (iVar3 == 0) {
      *(uint *)(iVar1 + 0x14) = param_1;
      *(uint *)(iVar1 + 0x18) = uVar5;
      iVar4 = (uVar5 != 0) + 1;
    }
    else {
      uVar6 = uVar5 >> ((byte)iVar3 & 0x1f);
      *(uint *)(iVar1 + 0x14) = uVar5 << (0x20 - (byte)iVar3 & 0x1f) | param_1;
      *(uint *)(iVar1 + 0x18) = uVar6;
      iVar4 = (uVar6 != 0) + 1;
    }
  }
  *(int *)(iVar1 + 0x10) = iVar4;
  if (uVar2 != 0) {
    *param_3 = iVar3 + -0x433 + uVar2;
    *param_4 = 0x35 - iVar3;
    return iVar1;
  }
  *param_3 = iVar3 + -0x432;
  iVar3 = javascript_bignumCountLeadingZeros(*(uint *)(iVar1 + 0x10 + iVar4 * 4));
  *param_4 = extraout_EDX * 0x20 - iVar3;
  return iVar1;
}



// ============================================================
// Function: javascript_bignumConvertFromDouble (FUN_6813a8c0)
// Address: 6813a8c0
// Size: 88 bytes
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 javascript_bignumConvertFromDouble(void)

{
  double dVar1;
  double dVar2;
  int unaff_ESI;
  int unaff_EDI;
  float10 fVar3;
  undefined8 local_1c;
  undefined8 local_14;
  int local_c;
  int local_8;
  
  fVar3 = javascript_bignumSetFromInt(&local_c);
  dVar1 = (double)fVar3;
  fVar3 = javascript_bignumSetFromInt(&local_8);
  dVar2 = (double)fVar3;
  local_c = ((*(int *)(unaff_EDI + 0x10) - *(int *)(unaff_ESI + 0x10)) * 0x20 - local_8) + local_c;
  if (0 < local_c) {
    (*(unsigned int *)((char *)&local_14 + 4)) = (int)((ulonglong)dVar1 >> 0x20);
    local_14 = (double)CONCAT44((*(unsigned int *)((char *)&local_14 + 4)) + local_c * 0x100000,SUB84(dVar1,0));
    return (float10)local_14 / (float10)dVar2;
  }
  (*(unsigned int *)((char *)&local_1c + 4)) = (int)((ulonglong)dVar2 >> 0x20);
  local_1c = (double)CONCAT44((*(unsigned int *)((char *)&local_1c + 4)) + local_c * -0x100000,SUB84(dVar2,0));
  return (float10)dVar1 / (float10)local_1c;
}



// ============================================================
// Function: javascript_numberToStringRadix (FUN_6813a920)
// Address: 6813a920
// Size: 85 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_numberToStringRadix(void)
{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  puVar2 = &DAT_681969c8;
  do {
    puVar1 = (undefined4 *)*puVar2;
    while (puVar1 != (undefined4 *)0x0) {
      *puVar2 = *puVar1;
      js_freeHandle();
      puVar1 = (undefined4 *)*puVar2;
    }
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while ((int)puVar2 < 0x68196a05);
  while (DAT_681969c0 != (undefined4 *)0x0) {
    DAT_681969c0 = (undefined4 *)*(int *)(size_t)DAT_681969c0 /* FIXUP(C2100): cast for dereference */;
    js_freeHandle();
  }
  return 0;
}



// ============================================================
// Function: javascript_numberToFixed (FUN_6813b500)
// Address: 6813b500
// Size: 129 bytes
// Params: int param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint javascript_numberToFixed(int param_1)

{
  uint uVar1;
  uint in_EAX;
  sbyte sVar2;
  uint *puVar3;
  int iVar4;
  int iVar5;
  uint local_8;
  
  iVar5 = (int)in_EAX >> 5;
  iVar4 = *(int *)(param_1 + 0x10) - iVar5;
  if (0 < iVar4) {
    puVar3 = (uint *)(param_1 + 0x14 + iVar5 * 4);
    sVar2 = (sbyte)(in_EAX & 0x1f);
    local_8 = *puVar3 >> sVar2;
    *puVar3 = (1 << sVar2) - 1U & *puVar3;
    if ((iVar4 == 2) && ((in_EAX & 0x1f) != 0)) {
      local_8 = local_8 | puVar3[1] << (0x20U - sVar2 & 0x1f);
    }
    iVar5 = iVar5 + 1;
    uVar1 = *puVar3;
    while ((uVar1 == 0 && (puVar3 != (uint *)(param_1 + 0x14)))) {
      puVar3 = puVar3 + -1;
      iVar5 = iVar5 + -1;
      uVar1 = *puVar3;
    }
    *(int *)(param_1 + 0x10) = iVar5;
    return local_8;
  }
  return 0;
}



// ============================================================
// Function: javascript_bignumDivideQuotient (FUN_6813b590)
// Address: 6813b590
// Size: 331 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint javascript_bignumDivideQuotient(int param_1,int param_2)

{
  int *piVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint *puVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  longlong lVar14;
  uint *local_20;
  uint local_c;
  int local_8;
  
  if (*(int *)(param_2 + 0x10) <= *(int *)(param_1 + 0x10)) {
    local_8 = *(int *)(param_2 + 0x10) + -1;
    puVar12 = (uint *)(param_2 + 0x14);
    puVar2 = puVar12 + local_8;
    puVar13 = (uint *)(param_1 + 0x14);
    puVar3 = puVar13 + local_8;
    local_c = *puVar3 / (*puVar2 + 1);
    local_20 = (uint *)0x0;
    if (local_c != 0) {
      local_20 = (uint *)0x0;
      uVar10 = 0;
      puVar11 = puVar12;
      do {
        lVar14 = __allmul(*puVar11,0,local_c,0);
        uVar4 = (uint)(lVar14 + (ulonglong)uVar10);
        uVar10 = (uint)(lVar14 + (ulonglong)uVar10 >> 0x20);
        puVar11 = puVar11 + 1;
        puVar7 = (uint *)(*puVar13 - uVar4);
        uVar8 = (int)puVar7 - (int)local_20;
        local_20 = (uint *)(-(uint)(puVar7 < local_20) - (uint)(*puVar13 < uVar4) & 1);
        *puVar13 = uVar8;
        puVar13 = puVar13 + 1;
      } while (puVar11 <= puVar2);
      if (*puVar3 == 0) {
        local_20 = (uint *)(param_1 + 0x14);
        while ((puVar3 = puVar3 + -1, local_20 < puVar3 && (*puVar3 == 0))) {
          local_8 = local_8 + -1;
        }
        *(int *)(param_1 + 0x10) = local_8;
      }
    }
    iVar5 = js_bignumCompare(local_20,param_1);
    if (-1 < iVar5) {
      local_c = local_c + 1;
      uVar10 = 0;
      local_20 = (uint *)0x0;
      puVar13 = (uint *)(param_1 + 0x14);
      do {
        uVar9 = *puVar12 + uVar10;
        uVar10 = (uint)CARRY4(*puVar12,uVar10);
        puVar12 = puVar12 + 1;
        uVar4 = *puVar13 - uVar9;
        uVar8 = uVar4 - (int)local_20;
        local_20 = (uint *)(-(uint)(uVar4 < local_20) - (uint)(*puVar13 < uVar9) & 1);
        *puVar13 = uVar8;
        puVar13 = puVar13 + 1;
      } while (puVar12 <= puVar2);
      piVar1 = (int *)(param_1 + 0x14);
      if (piVar1[local_8] == 0) {
        for (piVar6 = piVar1 + local_8 + -1; (piVar1 < piVar6 && (*piVar6 == 0));
            piVar6 = piVar6 + -1) {
          local_8 = local_8 + -1;
        }
        *(int *)(param_1 + 0x10) = local_8;
      }
    }
    return local_c;
  }
  return 0;
}


/* FIXUP(STUB-FILE): The following 4 functions have been stubbed out.
   The Ghidra decompilation produced code with severe structural issues
   (broken switch statements, missing variables, invalid casts) that
   could not be automatically repaired. Each function needs manual
   review against the original binary to restore correct logic. */

// ============================================================
// Function: javascript_numberToExponential (FUN_6813c9d0)
// Address: 6813c9d0
// Size: 448 bytes
// Params: int param_1, int param_2, char * param_3, char * param_4, int param_5, uint param_6
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * javascript_numberToExponential(int param_1,int param_2,char *param_3,char *param_4,int param_5,uint param_6)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

// ============================================================
// Function: javascript_numberToPrecision (FUN_6813cbb0)
// Address: 6813cbb0
// Size: 22 bytes
// Params: int param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_numberToPrecision(int param_1,uint param_2)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

// ============================================================
// Function: javascript_numberToStringMethod (FUN_6813cbc6)
// Address: 6813cbc6
// Size: 118 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall javascript_numberToStringMethod(int param_1,int param_2)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}

// ============================================================
// Function: javascript_numberValueOfMethod (FUN_6813cc40)
// Address: 6813cc40
// Size: 165 bytes
// Params: uint param_1, double param_2
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * javascript_numberValueOfMethod(uint param_1,double param_2)
{
  /* FIXUP(STUB): Function body disabled - needs manual reconstruction */
  return 0;
}
