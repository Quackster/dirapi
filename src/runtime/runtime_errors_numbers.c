// Module: runtime
// Topic: Error objects, Number type operations, type coercion, and numeric formatting
// Address range: 0x6812ace0 - 0x6812d950
// Functions (48):
//   runtime_initErrorPrototype
//   runtime_freeErrorObject
//   runtime_getErrorType
//   runtime_createErrorObject
//   runtime_constructErrorObject
//   runtime_errorToString
//   runtime_errorToSource
//   runtime_initErrorClasses
//   runtime_throwError
//   runtime_isNaN
//   runtime_constructErrorDefault
//   runtime_numberToFixed
//   runtime_formatNumberDigits
//   runtime_numberToExponential
//   runtime_freeNumberAtoms
//   runtime_storeFloat
//   runtime_formatNumber
//   runtime_convertToNumber
//   runtime_createNumberObject
//   runtime_divideFloat
//   runtime_multiplyFloat
//   runtime_addFloat
//   runtime_powFloat
//   runtime_parseNumberFromWchar
//   runtime_numberToString
//   runtime_parseNumberWithRadix
//   runtime_numberConstructor
//   runtime_initNumberConstants
//   runtime_parseNumber (FUN_6812cd90)
//   runtime_parseInt
//   runtime_parseFloat
//   runtime_convertStringToNumber
//   runtime_parseNumberToInt
//   runtime_globalParseInt
//   runtime_globalParseFloat
//   runtime_numberValueOf
//   runtime_numberToStringWithRadix
//   runtime_numberToPrecision
//   runtime_numberToLocaleString
//   runtime_formatNumberWithPrecision
//   runtime_formatNumberComplete
//   runtime_numberToFixedMethod
//   runtime_numberToExponentialMethod
//   runtime_numberToPrecisionMethod
//   runtime_initNumberPrototype
//   runtime_allocStringBuffer
//   runtime_traverseErrorChain
//   runtime_parseStringToInt

// ============================================================
// Function: runtime_initErrorPrototype (FUN_6812ace0)
// Address: 6812ace0
// Size: 468 bytes
// Params: int param_1
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_initErrorPrototype(int param_1)

{
  size_t sVar1;
  undefined4 *in_EAX;
  int *piVar2;
  int *_Dst;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  int local_8;
  
  piVar2 = (int *)xtra_getPropertyById(param_1,4);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  *piVar2 = 0;
  _Dst = (int *)xtra_getPropertyById(param_1,0x30);
  if (_Dst == (int *)0x0) {
LAB_6812ad36:
    runtime_freePropertyChain(piVar2);
    return (int *)0x0;
  }
  memset(_Dst,0,0x30);
  *piVar2 = (int)_Dst;
  if ((char *)*in_EAX == (char *)0x0) {
    *_Dst = 0;
  }
  else {
    iVar3 = xtra_findMethodByName(param_1,(char *)*in_EAX);
    *_Dst = iVar3;
    if (iVar3 == 0) goto LAB_6812ad36;
  }
  _Dst[1] = in_EAX[1];
  _Dst[2] = in_EAX[2];
  _Dst[3] = in_EAX[3];
  if ((short *)in_EAX[4] == (short *)0x0) {
    _Dst[5] = 0;
    _Dst[4] = 0;
  }
  else {
    iVar3 = certs_getStringLength((short *)in_EAX[4]);
    sVar1 = iVar3 * 2 + 2;
    pvVar4 = (void *)xtra_getPropertyById(param_1,sVar1);
    _Dst[4] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_6812ad36;
    memcpy(pvVar4,(void *)in_EAX[4],sVar1);
    _Dst[5] = _Dst[4] + ((int)(in_EAX[5] - in_EAX[4]) >> 1) * 2;
  }
  if ((short *)in_EAX[8] == (short *)0x0) {
    _Dst[8] = 0;
  }
  else {
    iVar3 = certs_getStringLength((short *)in_EAX[8]);
    sVar1 = iVar3 * 2 + 2;
    pvVar4 = (void *)xtra_getPropertyById(param_1,sVar1);
    _Dst[8] = (int)pvVar4;
    if (pvVar4 == (void *)0x0) goto LAB_6812ad36;
    memcpy(pvVar4,(void *)in_EAX[8],sVar1);
    piVar5 = (int *)in_EAX[9];
    iVar3 = 0;
    if (piVar5 != (int *)0x0) {
      iVar7 = 0;
      iVar6 = *piVar5;
      while (iVar6 != 0) {
        piVar5 = piVar5 + 1;
        iVar7 = iVar7 + 1;
        iVar6 = *piVar5;
      }
      iVar6 = xtra_getPropertyById(param_1,iVar7 * 4 + 4);
      _Dst[9] = iVar6;
      if (iVar6 == 0) goto LAB_6812ad36;
      piVar5 = (int *)in_EAX[9];
      local_8 = 0;
      iVar6 = *piVar5;
      while (iVar6 != 0) {
        iVar6 = certs_getStringLength(*(short **)(iVar3 + (int)piVar5));
        sVar1 = (iVar6 + 1) * 2;
        iVar6 = xtra_getPropertyById(param_1,sVar1);
        *(int *)(iVar3 + _Dst[9]) = iVar6;
        if (*(int *)(iVar3 + _Dst[9]) == 0) goto LAB_6812ad36;
        memcpy(*(void **)(iVar3 + _Dst[9]),*(void **)(iVar3 + in_EAX[9]),sVar1);
        piVar5 = (int *)in_EAX[9];
        local_8 = local_8 + 1;
        iVar3 = local_8 * 4;
        iVar6 = piVar5[local_8];
      }
      *(undefined4 *)(_Dst[9] + local_8 * 4) = 0;
      goto LAB_6812ae96;
    }
  }
  _Dst[9] = 0;
LAB_6812ae96:
  _Dst[7] = in_EAX[7];
  _Dst[6] = in_EAX[6];
  _Dst[0xb] = in_EAX[0xb];
  return piVar2;
}



// ============================================================
// Function: runtime_freeErrorObject (FUN_6812aec0)
// Address: 6812aec0
// Size: 39 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_freeErrorObject(undefined4 param_1,int param_2)
{
  uint uVar1;
  int *piVar2;
  
  uVar1 = *(uint *)(*(int *)(param_2 + 4) + 0xc);
  if ((uVar1 != 0x80000001) && (piVar2 = (int *)(uVar1 & 0xfffffffe), piVar2 != (int *)0x0)) {
    runtime_freePropertyChain(piVar2);
  }
  return 0;
}



// ============================================================
// Function: runtime_getErrorType (FUN_6812aef0)
// Address: 6812aef0
// Size: 61 bytes
// Params: undefined4 param_1, uint param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getErrorType(undefined4 param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  if (((((param_2 & 7) == 0) && (param_2 != 0)) &&
      (iVar1 = *(int *)((param_2 & 0xfffffff8) + 4),
      (undefined **)(*(uint *)(iVar1 + 8) & 0xfffffffe) == &PTR_s_Error_68192bb8)) &&
     ((uVar2 = *(uint *)(iVar1 + 0xc), uVar2 != 0x80000001 &&
      (puVar3 = (undefined4 *)(uVar2 & 0xfffffffe), puVar3 != (undefined4 *)0x0)))) {
    return *puVar3;
  }
  return 0;
}



// ============================================================
// Function: runtime_createErrorObject (FUN_6812af30)
// Address: 6812af30
// Size: 1966 bytes
// Params: uint * param_1, undefined4 param_2, uint param_3, uint param_4, int param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall runtime_createErrorObject(uint *param_1,undefined4 param_2,uint param_3,uint param_4,int param_5)
{
  int local_14;
  char cVar1;
  code *pcVar2;
  undefined4 uVar3;
  uint *puVar4;
  int iVar5;
  uint uVar6;
  void *pvVar7;
  uint *puVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint *puVar12;
  undefined4 local_a8;
  int *local_9c;
  uint local_94;
  uint *local_90;
  uint local_8c;
  uint *local_88;
  int local_84;
  uint *local_80;
  uint *local_7c;
  char local_78 [100];
  /* FIXUP(C2040: 'local_14': 'uint): uint local_14 [3]; */
  uint local_8;
  
  local_7c = param_1;
  iVar5 = events_registerProperty(param_1,param_2,"message",param_3 | 4,0,0);
  if (((iVar5 != 0) &&
      (iVar5 = events_registerProperty(param_1,param_2,"fileName",param_4 | 4,0,0), iVar5 != 0)) &&
     (iVar5 = events_registerProperty(param_1,param_2,"lineNumber",param_5 * 2 | 1,0,0), iVar5 != 0))
  {
    pcVar2 = *(code **)(param_1[5] + 0x2254);
    if (pcVar2 != (code *)0x0) {
      local_a8 = xtra_setPropertyDirect((int)param_1,0);
      local_9c = xtra_allocScriptBlock((int)param_1);
    }
    local_8c = param_1[0xd];
    uVar3 = *(undefined4 *)(*(int *)(param_1[5] + 0xe4) + 8);
    puVar12 = (uint *)0x0;
    local_80 = (uint *)0x0;
    local_84 = 1;
    uVar9 = 0;
    puVar8 = local_80;
    for (; local_80 = puVar8, local_8c != 0; local_8c = *(uint *)(local_8c + 0x2c)) {
      if (pcVar2 != (code *)0x0) {
        if ((*(int *)(local_8c + 0x10) == 0) || (*(int *)(local_8c + 0x1c) == 0)) {
          local_94 = 0;
        }
        else {
          local_94 = *(uint *)(*(int *)(local_8c + 0x1c) + -8);
        }
        if ((((local_94 & 7) == 0) && (local_94 != 0)) &&
           (local_84 = (*pcVar2)(local_7c,*(undefined4 *)(*(int *)(local_8c + 0x10) + 4),uVar3,4,
                                 &local_94), local_84 == 0)) {
          local_84 = 1;
          break;
        }
      }
      uVar6 = uVar9;
      if (*(int *)(local_8c + 0x10) != 0) {
        iVar5 = *(int *)(*(int *)(local_8c + 0x10) + 0x18);
        if (iVar5 == 0) {
LAB_6812b170:
          uVar10 = uVar6;
          if (puVar8 == puVar12) {
            if (puVar12 == (uint *)0x0) {
              puVar12 = (uint *)0x40;
            }
            else {
              puVar12 = (uint *)((int)puVar12 * 2);
            }
            uVar10 = xtra_allocJSString((int)local_7c,uVar6,(int)puVar12 * 2 + 2);
            uVar9 = uVar6;
            if (uVar10 == 0) goto LAB_6812b5d4;
          }
          *(undefined2 *)(uVar10 + (int)puVar8 * 2) = 0x28;
          local_90 = (uint *)0x0;
          local_80 = (uint *)((int)puVar8 + 1);
          if (*(int *)(local_8c + 0x18) != 0) {
            do {
              local_94 = *(uint *)(*(int *)(local_8c + 0x1c) + (int)local_90 * 4);
              uVar9 = uVar10;
              if (((local_94 & 7) == 0) && (local_94 != 0)) {
                if (((local_94 & 0xfffffff8) == 0) ||
                   ((undefined **)
                    (*(uint *)(*(int *)((local_94 & 0xfffffff8) + 4) + 8) & 0xfffffffe) !=
                    &PTR_s_Function_681928b8)) {
                  runtime_snprintf(local_78,100,"[object %s]");
                  local_88 = xtra_findSymbolByName((uint)local_7c,local_78);
                  goto LAB_6812b287;
                }
                iVar5 = xtraRuntime_callFunction((int)local_7c);
                local_88 = (uint *)xtra_getGlobalFlags(iVar5);
                if (local_88 == (uint *)0x0) {
                  local_88 = certs_resizeString(local_7c,local_94);
                  goto LAB_6812b287;
                }
              }
              else {
                local_88 = certs_resizeString(local_7c,local_94);
LAB_6812b287:
                if (local_88 == (uint *)0x0) goto LAB_6812b5d4;
              }
              puVar8 = local_88;
              uVar6 = uVar10;
              if (local_90 != (uint *)0x0) {
                if (local_80 == puVar12) {
                  if (puVar12 == (uint *)0x0) {
                    puVar12 = (uint *)0x40;
                  }
                  else {
                    puVar12 = (uint *)((int)puVar12 * 2);
                  }
                  uVar6 = xtra_allocJSString((int)local_7c,uVar10,(int)puVar12 * 2 + 2);
                  if (uVar6 == 0) goto LAB_6812b5d4;
                }
                *(undefined2 *)(uVar6 + (int)local_80 * 2) = 0x2c;
                local_80 = (uint *)((int)local_80 + 1);
              }
              uVar11 = *puVar8;
              if ((uVar11 & 0x40000000) != 0) {
                uVar11 = (-(uint)((uVar11 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar11;
              }
              puVar8 = (uint *)((int)local_80 + uVar11);
              uVar10 = uVar6;
              if (puVar12 < puVar8) {
                uVar9 = crypto_decompileNode((uint)puVar8);
                puVar12 = (uint *)(1 << ((byte)uVar9 & 0x1f));
                uVar10 = xtra_allocJSString((int)local_7c,uVar6,(int)puVar12 * 2 + 2);
                uVar9 = uVar6;
                if (uVar10 == 0) goto LAB_6812b5d4;
              }
              uVar9 = *local_88;
              if ((uVar9 & 0x40000000) == 0) {
                pvVar7 = (void *)local_88[1];
              }
              else {
                puVar4 = (uint *)local_88[1];
                if ((*puVar4 & 0x40000000) == 0) {
                  if ((int)uVar9 < 0) {
                    pvVar7 = (void *)puVar4[1];
                  }
                  else {
                    pvVar7 = (void *)(puVar4[1] + (uVar9 >> 0xf & 0x7fff) * 2);
                  }
                }
                else {
                  pvVar7 = (void *)crypto_getStringLen(local_88);
                }
              }
              memcpy((void *)(uVar10 + (int)local_80 * 2),pvVar7,uVar11 * 2);
              local_90 = (uint *)((int)local_90 + 1);
              local_80 = puVar8;
            } while (local_90 < *(uint **)(local_8c + 0x18));
          }
          puVar8 = local_80;
          uVar6 = uVar10;
          if (local_80 == puVar12) {
            if (puVar12 == (uint *)0x0) {
              puVar12 = (uint *)0x40;
            }
            else {
              puVar12 = (uint *)((int)puVar12 * 2);
            }
            uVar6 = xtra_allocJSString((int)local_7c,uVar10,(int)puVar12 * 2 + 2);
            uVar9 = uVar10;
            if (uVar6 == 0) goto LAB_6812b5d4;
          }
          *(undefined2 *)(uVar6 + (int)puVar8 * 2) = 0x29;
          puVar8 = (uint *)((int)puVar8 + 1);
          local_80 = puVar8;
          goto LAB_6812b3eb;
        }
        local_90 = (uint *)(*(uint *)(iVar5 + 8) & 0xfffffff8);
        uVar10 = *local_90;
        if ((uVar10 & 0x40000000) != 0) {
          uVar10 = (-(uint)((uVar10 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar10;
        }
        local_88 = (uint *)(uVar10 + (int)local_80);
        if (local_88 <= puVar12) {
LAB_6812b108:
          uVar9 = *local_90;
          if ((uVar9 & 0x40000000) == 0) {
            pvVar7 = (void *)local_90[1];
          }
          else {
            puVar8 = (uint *)local_90[1];
            if ((*puVar8 & 0x40000000) == 0) {
              if ((int)uVar9 < 0) {
                pvVar7 = (void *)puVar8[1];
              }
              else {
                pvVar7 = (void *)(puVar8[1] + (uVar9 >> 0xf & 0x7fff) * 2);
              }
            }
            else {
              pvVar7 = (void *)crypto_getStringLen(local_90);
            }
          }
          memcpy((void *)(uVar6 + (int)local_80 * 2),pvVar7,uVar10 * 2);
          local_80 = local_88;
          puVar8 = local_88;
          goto LAB_6812b170;
        }
        uVar6 = crypto_decompileNode((uint)local_88);
        puVar12 = (uint *)(1 << ((byte)uVar6 & 0x1f));
        uVar6 = xtra_allocJSString((int)local_7c,uVar9,(int)puVar12 * 2 + 2);
        if (uVar6 != 0) goto LAB_6812b108;
LAB_6812b5d4:
        local_84 = 0;
        break;
      }
LAB_6812b3eb:
      uVar10 = uVar6;
      if (puVar8 == puVar12) {
        if (puVar12 == (uint *)0x0) {
          puVar12 = (uint *)0x40;
        }
        else {
          puVar12 = (uint *)((int)puVar12 * 2);
        }
        uVar10 = xtra_allocJSString((int)local_7c,uVar6,(int)puVar12 * 2 + 2);
        uVar9 = uVar6;
        if (uVar10 == 0) goto LAB_6812b5d4;
      }
      *(undefined2 *)(uVar10 + (int)puVar8 * 2) = 0x40;
      puVar8 = (uint *)((int)puVar8 + 1);
      local_80 = puVar8;
      if ((*(int *)(local_8c + 0xc) != 0) &&
         (puVar4 = *(uint **)(*(int *)(local_8c + 0xc) + 0x18), puVar4 != (uint *)0x0)) {
        cVar1 = (char)*puVar4;
        local_88 = puVar4;
        while (local_80 = puVar8, cVar1 != '\0') {
          uVar6 = uVar10;
          if (puVar8 == puVar12) {
            if (puVar12 == (uint *)0x0) {
              puVar12 = (uint *)0x40;
            }
            else {
              puVar12 = (uint *)((int)puVar12 * 2);
            }
            uVar6 = xtra_allocJSString((int)local_7c,uVar10,(int)puVar12 * 2 + 2);
            uVar9 = uVar10;
            if (uVar6 == 0) goto LAB_6812b5d4;
          }
          *(short *)(uVar6 + (int)puVar8 * 2) = (short)(char)*local_88;
          local_88 = (uint *)((int)local_88 + 1);
          puVar8 = (uint *)((int)puVar8 + 1);
          uVar10 = uVar6;
          cVar1 = *(char *)local_88;
        }
      }
      puVar4 = local_80;
      if (local_80 == puVar12) {
        if (puVar12 == (uint *)0x0) {
          puVar12 = (uint *)0x40;
        }
        else {
          puVar12 = (uint *)((int)puVar12 * 2);
        }
        uVar6 = xtra_allocJSString((int)local_7c,uVar10,(int)puVar12 * 2 + 2);
        uVar9 = uVar10;
        uVar10 = uVar6;
        if (uVar6 == 0) goto LAB_6812b5d4;
      }
      uVar9 = uVar10;
      *(undefined2 *)(uVar9 + (int)puVar4 * 2) = 0x3a;
      puVar8 = (uint *)((int)puVar4 + 1);
      uVar6 = uVar9;
      local_80 = puVar8;
      if ((*(uint *)(local_8c + 0xc) == 0) || (*(int *)(local_8c + 0x38) == 0)) {
        if (puVar8 == puVar12) {
          if (puVar12 == (uint *)0x0) {
            puVar12 = (uint *)0x40;
          }
          else {
            puVar12 = (uint *)((int)puVar12 * 2);
          }
          uVar6 = xtra_allocJSString((int)local_7c,uVar9,(int)puVar12 * 2 + 2);
          if (uVar6 == 0) goto LAB_6812b5d4;
        }
        *(undefined2 *)(uVar6 + (int)puVar8 * 2) = 0x30;
        puVar8 = (uint *)((int)puVar4 + 2);
        local_80 = puVar8;
      }
      else {
        runtime_getObjectField(*(uint *)(local_8c + 0xc),*(int *)(local_8c + 0x38));
        runtime_snprintf((undefined1 *)local_14,0xb,"%u");
        local_88 = local_14;
        cVar1 = (char)((int *)(size_t)local_14)[ /* FIXUP(C2109): cast to pointer for subscript */0];
        while (cVar1 != '\0') {
          uVar10 = uVar6;
          if (puVar8 == puVar12) {
            if (puVar12 == (uint *)0x0) {
              puVar12 = (uint *)0x40;
            }
            else {
              puVar12 = (uint *)((int)puVar12 * 2);
            }
            uVar10 = xtra_allocJSString((int)local_7c,uVar6,(int)puVar12 * 2 + 2);
            uVar9 = uVar6;
            if (uVar10 == 0) goto LAB_6812b5d4;
          }
          *(short *)(uVar10 + (int)puVar8 * 2) = (short)(char)*local_88;
          local_88 = (uint *)((int)local_88 + 1);
          puVar8 = (uint *)((int)puVar8 + 1);
          uVar6 = uVar10;
          local_80 = puVar8;
          cVar1 = *(char *)local_88;
        }
      }
      uVar10 = uVar6;
      if (puVar8 == puVar12) {
        if (puVar12 == (uint *)0x0) {
          puVar12 = (uint *)0x40;
        }
        else {
          puVar12 = (uint *)((int)puVar12 * 2);
        }
        uVar10 = xtra_allocJSString((int)local_7c,uVar6,(int)puVar12 * 2 + 2);
        uVar9 = uVar6;
        if (uVar10 == 0) goto LAB_6812b5d4;
      }
      *(undefined2 *)(uVar10 + (int)puVar8 * 2) = 10;
      puVar8 = (uint *)((int)puVar8 + 1);
      uVar9 = uVar10;
    }
    puVar8 = local_7c;
    if (pcVar2 != (code *)0x0) {
      if (local_84 == 0) {
        xtra_releaseObject((int)local_7c,local_9c);
        puVar8 = local_7c;
        xtra_setPropertyDirect((int)local_7c,local_a8);
      }
      else {
        xtra_storeResult((int)local_7c,local_9c);
        xtra_setPropertyDirect((int)puVar8,local_a8);
      }
    }
    puVar4 = local_80;
    if (local_84 != 0) {
      if (uVar9 == 0) {
        puVar12 = *(uint **)(puVar8[5] + 0x1dc);
      }
      else {
        if ((local_80 < puVar12) && (uVar6 = js_allocAtomBlock(uVar9,(int)local_80 * 2 + 2), uVar6 != 0))
        {
          uVar9 = uVar6;
        }
        *(undefined2 *)(uVar9 + (int)puVar4 * 2) = 0;
        puVar12 = certs_allocHashEntry((int)local_7c,uVar9,(uint)puVar4,0);
        puVar8 = local_7c;
        if (puVar12 == (uint *)0x0) {
          xtra_checkAndFlush(local_7c,uVar9);
          return 0;
        }
      }
      events_registerProperty(puVar8,param_2,"stack",(uint)puVar12 | 4,0,0);
      return 0;
    }
    xtra_checkAndFlush(puVar8,uVar9);
  }
  return 0;
}



// ============================================================
// Function: runtime_constructErrorObject (FUN_6812b6e0)
// Address: 6812b6e0
// Size: 321 bytes
// Params: uint * param_1, int * param_2, uint param_3, uint * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_constructErrorObject(uint *param_1,int *param_2,uint param_3,uint *param_4,undefined4 *param_5)

{
  uint *puVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined8 uVar7;
  uint local_8;
  
  puVar2 = param_4;
  puVar1 = param_1;
  if (*(char *)((int)param_1 + 0x159) != '\0') {
    return 0;
  }
  *(undefined1 *)((int)param_1 + 0x159) = 1;
  if ((*(byte *)(param_1[0xd] + 0x4c) & 1) == 0) {
    iVar3 = (**(code **)(*(int *)(*(int *)(param_4[-2] & 0xfffffff8) + 4) + 0x10))
                      (param_1,(int *)(param_4[-2] & 0xfffffff8),*(undefined4 *)(param_1[5] + 0xe8),
                       &local_8);
    uVar6 = 0;
    if (iVar3 == 0) goto LAB_6812b812;
    param_2 = runtime_setProperty((int)puVar1,&PTR_s_Error_68192bb8,(undefined4 *)(local_8 & 0xfffffff8),0)
    ;
    if (param_2 == (int *)0x0) {
      *(undefined1 *)((int)puVar1 + 0x159) = 0;
      return 0;
    }
    *param_5 = param_2;
  }
  if ((undefined **)(*(uint *)(param_2[1] + 8) & 0xfffffffe) == &PTR_s_Error_68192bb8) {
    *(undefined4 *)(param_2[1] + 0xc) = 0x80000001;
  }
  if (param_3 == 0) {
    uVar4 = *(uint *)(puVar1[5] + 0x1dc);
LAB_6812b7af:
    uVar5 = *(uint *)(puVar1[5] + 0x1dc);
  }
  else {
    uVar4 = certs_hashLookup((int)puVar1,*puVar2);
    if (uVar4 == 0) {
      *(undefined1 *)((int)puVar1 + 0x159) = 0;
      return 0;
    }
    if (param_3 < 2) goto LAB_6812b7af;
    uVar5 = certs_hashLookup((int)puVar1,puVar2[1]);
    if (uVar5 == 0) {
      *(undefined1 *)((int)puVar1 + 0x159) = 0;
      return 0;
    }
  }
  if (param_3 < 3) {
    param_1 = (uint *)0x0;
  }
  else {
    uVar7 = runtime_convertStringToNumber((ushort *)puVar1,(undefined **)param_4[2],(int *)&param_1);
    uVar6 = 0;
    if ((int)uVar7 == 0) goto LAB_6812b812;
  }
  uVar6 = runtime_createErrorObject(puVar1,param_2,uVar4,uVar5,(int)param_1);
LAB_6812b812:
  *(undefined1 *)((int)puVar1 + 0x159) = 0;
  return uVar6;
}



// ============================================================
// Function: runtime_errorToString (FUN_6812b830)
// Address: 6812b830
// Size: 489 bytes
// Params: int param_1, int * param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_errorToString(int param_1,int *param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  int *piVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  void *_Dst;
  void *pvVar9;
  undefined4 *puVar10;
  uint uVar11;
  
  piVar4 = param_2;
  iVar5 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))
                    (param_1,param_2,*(undefined4 *)(*(int *)(param_1 + 0x14) + 0x10c),&param_2);
  if (iVar5 == 0) {
    return 0;
  }
  puVar6 = (uint *)certs_hashLookup(param_1,(uint)param_2);
  if (((puVar6 != (uint *)0x0) &&
      (iVar5 = xtra_parsePath(param_1,piVar4,"message",&param_2), iVar5 != 0)) &&
     (puVar7 = (uint *)certs_hashLookup(param_1,(uint)param_2), puVar7 != (uint *)0x0)) {
    uVar11 = *puVar7;
    uVar8 = uVar11;
    if ((uVar11 & 0x40000000) != 0) {
      uVar8 = (-(uint)((uVar11 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar11;
    }
    if (uVar8 == 0) {
LAB_6812ba03:
      *param_5 = (uint)puVar6 | 4;
      return 1;
    }
    uVar8 = *puVar6;
    if ((uVar8 & 0x40000000) != 0) {
      uVar8 = (-(uint)((uVar8 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar8;
    }
    if ((uVar11 & 0x40000000) != 0) {
      uVar11 = (-(uint)((uVar11 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar11;
    }
    uVar1 = uVar11 + 2 + uVar8;
    _Dst = (void *)xtra_getPropertyById(param_1,uVar1 * 2 + 2);
    if (_Dst != (void *)0x0) {
      uVar2 = *puVar6;
      if ((uVar2 & 0x40000000) == 0) {
        pvVar9 = (void *)puVar6[1];
      }
      else {
        puVar3 = (uint *)puVar6[1];
        if ((*puVar3 & 0x40000000) == 0) {
          if ((int)uVar2 < 0) {
            pvVar9 = (void *)puVar3[1];
          }
          else {
            pvVar9 = (void *)(puVar3[1] + (uVar2 >> 0xf & 0x7fff) * 2);
          }
        }
        else {
          pvVar9 = (void *)crypto_getStringLen(puVar6);
        }
      }
      memcpy(_Dst,pvVar9,uVar8 * 2);
      puVar10 = (undefined4 *)(uVar8 * 2 + (int)_Dst);
      *puVar10 = 0x20003a;
      uVar8 = *puVar7;
      puVar10 = puVar10 + 1;
      if ((uVar8 & 0x40000000) == 0) {
        pvVar9 = (void *)puVar7[1];
      }
      else {
        puVar6 = (uint *)puVar7[1];
        if ((*puVar6 & 0x40000000) == 0) {
          if ((int)uVar8 < 0) {
            pvVar9 = (void *)puVar6[1];
          }
          else {
            pvVar9 = (void *)(puVar6[1] + (uVar8 >> 0xf & 0x7fff) * 2);
          }
        }
        else {
          pvVar9 = (void *)crypto_getStringLen(puVar7);
        }
      }
      memcpy(puVar10,pvVar9,uVar11 * 2);
      *(undefined2 *)(uVar11 * 2 + (int)puVar10) = 0;
      puVar6 = certs_allocHashEntry(param_1,(uint)_Dst,uVar1,0);
      if (puVar6 != (uint *)0x0) goto LAB_6812ba03;
      xtra_checkAndFlush(param_1,(int)_Dst);
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_errorToSource (FUN_6812ba20)
// Address: 6812ba20
// Size: 978 bytes
// Params: uint * param_1, undefined * * param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_errorToSource(uint *param_1,undefined **param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  uint uVar1;
  size_t _Size;
  undefined **ppuVar2;
  int iVar3;
  undefined2 *puVar4;
  void *pvVar5;
  uint *puVar6;
  uint uVar7;
  undefined2 *_Dst;
  undefined4 *_Dst_00;
  uint uVar8;
  undefined8 uVar9;
  int local_24;
  uint *local_20;
  uint *local_1c;
  uint *local_18;
  uint local_14;
  uint local_10;
  uint *local_c;
  uint local_8;
  
  ppuVar2 = param_2;
  iVar3 = (**(code **)(*(int *)(*param_2 + 4) + 0x10))
                    (param_1,param_2,*(undefined4 *)(param_1[5] + 0x10c),&param_2);
  if (iVar3 == 0) {
    return 0;
  }
  local_18 = (uint *)certs_hashLookup((int)param_1,(uint)param_2);
  if (local_18 == (uint *)0x0) {
    return 0;
  }
  iVar3 = xtra_parsePath((int)param_1,(int *)ppuVar2,"message",&param_2);
  if (iVar3 == 0) {
    return 0;
  }
  local_1c = certs_resizeString(param_1,(uint)param_2);
  if (local_1c == (uint *)0x0) {
    return 0;
  }
  iVar3 = xtra_parsePath((int)param_1,(int *)ppuVar2,"fileName",&param_2);
  if (iVar3 == 0) {
    return 0;
  }
  local_20 = certs_resizeString(param_1,(uint)param_2);
  if (local_20 == (uint *)0x0) {
    return 0;
  }
  iVar3 = xtra_parsePath((int)param_1,(int *)ppuVar2,"lineNumber",&param_2);
  if (iVar3 == 0) {
    return 0;
  }
  uVar9 = runtime_convertStringToNumber((ushort *)param_1,param_2,&local_24);
  if ((int)uVar9 == 0) {
    return 0;
  }
  if (local_24 == 0) {
    local_c = (uint *)0x0;
    local_10 = 0;
  }
  else {
    local_c = (uint *)certs_hashLookup((int)param_1,(uint)param_2);
    if (local_c == (uint *)0x0) {
      return 0;
    }
    local_10 = *local_c;
    if ((local_10 & 0x40000000) != 0) {
      local_10 = (-(uint)((local_10 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & local_10;
    }
  }
  uVar8 = *local_18;
  if ((uVar8 & 0x40000000) != 0) {
    uVar8 = (-(uint)((uVar8 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar8;
  }
  uVar7 = *local_1c;
  if ((uVar7 & 0x40000000) != 0) {
    uVar7 = (-(uint)((uVar7 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar7;
  }
  local_14 = *local_20;
  local_8 = uVar7 + 8 + uVar8;
  if ((local_14 & 0x40000000) != 0) {
    local_14 = (-(uint)((local_14 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & local_14;
  }
  if (local_14 == 0) {
    if (local_c != (uint *)0x0) {
      iVar3 = local_8 + 6;
      goto LAB_6812bbed;
    }
  }
  else {
    local_8 = local_8 + 2 + local_14;
    if (local_c != (uint *)0x0) {
      iVar3 = local_8 + 2;
LAB_6812bbed:
      local_8 = iVar3 + local_10;
    }
  }
  puVar4 = (undefined2 *)xtra_getPropertyById((int)param_1,local_8 * 2 + 2);
  if (puVar4 == (undefined2 *)0x0) {
    return 0;
  }
  *puVar4 = 0x28;
  *(undefined4 *)(puVar4 + 1) = 0x65006e;
  *(undefined4 *)(puVar4 + 3) = 0x200077;
  uVar1 = *local_18;
  _Dst = puVar4 + 5;
  if ((uVar1 & 0x40000000) == 0) {
    pvVar5 = (void *)local_18[1];
  }
  else {
    puVar6 = (uint *)local_18[1];
    if ((*puVar6 & 0x40000000) == 0) {
      if ((int)uVar1 < 0) {
        pvVar5 = (void *)puVar6[1];
      }
      else {
        pvVar5 = (void *)(puVar6[1] + (uVar1 >> 0xf & 0x7fff) * 2);
      }
    }
    else {
      pvVar5 = (void *)crypto_getStringLen(local_18);
    }
  }
  memcpy(_Dst,pvVar5,uVar8 * 2);
  _Dst[uVar8] = 0x28;
  _Dst_00 = (undefined4 *)(_Dst + uVar8 + 1);
  if (uVar7 != 0) {
    uVar8 = *local_1c;
    if ((uVar8 & 0x40000000) == 0) {
      pvVar5 = (void *)local_1c[1];
    }
    else {
      puVar6 = (uint *)local_1c[1];
      if ((*puVar6 & 0x40000000) == 0) {
        if ((int)uVar8 < 0) {
          pvVar5 = (void *)puVar6[1];
        }
        else {
          pvVar5 = (void *)(puVar6[1] + (uVar8 >> 0xf & 0x7fff) * 2);
        }
      }
      else {
        pvVar5 = (void *)crypto_getStringLen(local_1c);
      }
    }
    memcpy(_Dst_00,pvVar5,uVar7 * 2);
    _Dst_00 = (undefined4 *)((int)_Dst_00 + uVar7 * 2);
  }
  uVar8 = local_14;
  if (local_14 == 0) {
    if (local_c == (uint *)0x0) goto LAB_6812bda8;
    *_Dst_00 = 0x20002c;
    _Dst_00[1] = 0x220022;
    _Dst_00 = _Dst_00 + 2;
  }
  else {
    *_Dst_00 = 0x20002c;
    uVar7 = *local_20;
    if ((uVar7 & 0x40000000) == 0) {
      pvVar5 = (void *)local_20[1];
    }
    else {
      puVar6 = (uint *)local_20[1];
      if ((*puVar6 & 0x40000000) == 0) {
        if ((int)uVar7 < 0) {
          pvVar5 = (void *)puVar6[1];
        }
        else {
          pvVar5 = (void *)(puVar6[1] + (uVar7 >> 0xf & 0x7fff) * 2);
        }
      }
      else {
        pvVar5 = (void *)crypto_getStringLen(local_20);
      }
    }
    memcpy(_Dst_00 + 1,pvVar5,uVar8 * 2);
    _Dst_00 = (undefined4 *)((int)(_Dst_00 + 1) + uVar8 * 2);
  }
  if (local_c != (uint *)0x0) {
    *_Dst_00 = 0x20002c;
    uVar8 = *local_c;
    if ((uVar8 & 0x40000000) == 0) {
      pvVar5 = (void *)local_c[1];
    }
    else {
      puVar6 = (uint *)local_c[1];
      if ((*puVar6 & 0x40000000) == 0) {
        if ((int)uVar8 < 0) {
          pvVar5 = (void *)puVar6[1];
        }
        else {
          pvVar5 = (void *)(puVar6[1] + (uVar8 >> 0xf & 0x7fff) * 2);
        }
      }
      else {
        pvVar5 = (void *)crypto_getStringLen(local_c);
      }
    }
    _Size = local_10 * 2;
    memcpy(_Dst_00 + 1,pvVar5,_Size);
    _Dst_00 = (undefined4 *)((int)(_Dst_00 + 1) + _Size);
  }
LAB_6812bda8:
  *_Dst_00 = 0x290029;
  *(undefined2 *)(_Dst_00 + 1) = 0;
  puVar6 = certs_allocHashEntry((int)param_1,(uint)puVar4,local_8,0);
  if (puVar6 == (uint *)0x0) {
    xtra_checkAndFlush(param_1,(int)puVar4);
    return 0;
  }
  *param_5 = (uint)puVar6 | 4;
  return 1;
}



// ============================================================
// Function: runtime_initErrorClasses (FUN_6812be00)
// Address: 6812be00
// Size: 411 bytes
// Params: uint param_1, int * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_initErrorClasses(uint param_1,int *param_2)

{
  char cVar1;
  char *pcVar2;
  undefined *puVar3;
  int *piVar4;
  int *piVar5;
  char *pcVar6;
  int iVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  int *local_28 [8];
  int local_8;
  
  iVar10 = 0;
  local_8 = 0;
  piVar5 = local_28[0];
  puVar3 = PTR_s_Error_68192c04;
  while( true ) {
    if (puVar3 == (undefined *)0x0) {
      iVar10 = events_registerProperty(param_1,piVar5,"message",
                            *(uint *)(*(int *)(param_1 + 0x14) + 0x1dc) | 4,0,0);
      if (((iVar10 != 0) &&
          (iVar10 = events_registerProperty(param_1,piVar5,"fileName",
                                 *(uint *)(*(int *)(param_1 + 0x14) + 0x1dc) | 4,0,0), iVar10 != 0))
         && (iVar10 = events_registerProperty(param_1,piVar5,"lineNumber",1,0,0), iVar10 != 0)) {
        iVar10 = events_attachVtable(param_1,piVar5,(int *)&PTR_s_toSource_68192c6c);
        return -(uint)(iVar10 != 0) & (uint)piVar5;
      }
      return 0;
    }
    if (*(int *)((int)&DAT_68192c00 + iVar10) == -1) {
      piVar4 = (int *)0x0;
    }
    else {
      piVar4 = local_28[*(int *)((int)&DAT_68192c00 + iVar10)];
    }
    local_28[0] = piVar5;
    piVar5 = runtime_setProperty(param_1,&PTR_s_Error_68192bb8,piVar4,(uint)param_2);
    local_28[local_8] = piVar5;
    if (piVar5 == (int *)0x0) {
      return 0;
    }
    *(undefined4 *)(piVar5[1] + 0xc) = 0x80000001;
    pcVar2 = *(char **)((int)&PTR_s_Error_68192c04 + iVar10);
    pcVar6 = pcVar2;
    do {
      cVar1 = *pcVar6;
      pcVar6 = pcVar6 + 1;
    } while (cVar1 != '\0');
    iVar7 = javascript_registerAtom(param_1,pcVar2,(int)pcVar6 - (int)(pcVar2 + 1),0);
    if (iVar7 == 0) {
      return 0;
    }
    uVar8 = runtime_registerFunction(param_1,param_2,iVar7,*(int *)((int)&PTR_FUN_68192c08 + iVar10),3,0);
    if (uVar8 == 0) {
      return 0;
    }
    *(undefined ***)(uVar8 + 0x1c) = &PTR_s_Error_68192bb8;
    iVar7 = runtime_copyPropertyDescriptor(param_1,*(int **)(uVar8 + 4),piVar5,6);
    if (iVar7 == 0) break;
    puVar9 = xtra_findSymbolByName(param_1,*(char **)((int)&PTR_s_Error_68192c04 + iVar10));
    if (puVar9 == (uint *)0x0) {
      return 0;
    }
    iVar10 = events_registerProperty(param_1,piVar5,"name",(uint)puVar9 | 4,0,0);
    if (iVar10 == 0) {
      return 0;
    }
    local_8 = local_8 + 1;
    iVar10 = local_8 * 0xc;
    puVar3 = (&PTR_s_Error_68192c04)[local_8 * 3];
    piVar5 = local_28[0];
  }
  return 0;
}



// ============================================================
// Function: runtime_throwError (FUN_6812bfa0)
// Address: 6812bfa0
// Size: 295 bytes
// Params: uint * param_1, char * param_2, undefined4 * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_throwError(uint *param_1,char *param_2,undefined4 *param_3)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint *puVar5;
  int iVar6;
  int *piVar7;
  undefined4 *local_8;
  
  uVar1 = param_1[0xd];
  if ((((uVar1 == 0) || ((*(byte *)(param_3 + 6) & 1) != 0)) ||
      (iVar2 = *(int *)(&DAT_68192c90 + param_3[7] * 4), iVar2 == -1)) ||
     (*(char *)((int)param_1 + 0x159) != '\0')) {
    return 0;
  }
  *(undefined1 *)((int)param_1 + 0x159) = 1;
  iVar6 = *(int *)(uVar1 + 0x38);
  *(undefined4 *)(uVar1 + 0x38) = 0;
  iVar2 = runtime_resolveAndSetProperty((&PTR_s_Error_68192c04)[iVar2 * 3],param_1,(&PTR_s_Error_68192c04)[iVar2 * 3]
                       ,(uint *)&local_8);
  if (iVar6 != 0) {
    *(int *)(uVar1 + 0x38) = iVar6;
  }
  iVar6 = 0;
  if (iVar2 == 0) goto LAB_6812c0ab;
  piVar3 = runtime_setProperty((int)param_1,&PTR_s_Error_68192bb8,local_8,0);
  if (piVar3 != (int *)0x0) {
    xtra_setInterruptData((int)param_1,piVar3);
    puVar4 = xtra_findSymbolByName((uint)param_1,param_2);
    if (puVar4 != (uint *)0x0) {
      puVar5 = xtra_findSymbolByName((uint)param_1,(char *)*param_3);
      if (puVar5 != (uint *)0x0) {
        iVar6 = runtime_createErrorObject(param_1,piVar3,(uint)puVar4,(uint)puVar5,param_3[1]);
        if (iVar6 != 0) {
          piVar7 = runtime_initErrorPrototype((int)param_1);
          if (piVar7 == (int *)0x0) goto LAB_6812c03b;
          *(uint *)(piVar3[1] + 0xc) = (uint)piVar7 | 1;
          param_3[6] = param_3[6] | 2;
        }
LAB_6812c0ab:
        *(undefined1 *)((int)param_1 + 0x159) = 0;
        return iVar6;
      }
    }
  }
LAB_6812c03b:
  *(undefined1 *)((int)param_1 + 0x159) = 0;
  return 0;
}



// ============================================================
// Function: runtime_isNaN (FUN_6812c0d0)
// Address: 6812c0d0
// Size: 195 bytes
// Params: uint param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_isNaN(uint param_1)

{
  uint uVar1;
  undefined1 uVar2;
  undefined3 extraout_var;
  int iVar3;
  uint *puVar4;
  char *pcVar5;
  uint extraout_EDX;
  uint local_8;
  
  uVar1 = param_1;
  uVar2 = xtra_getStrictMode(param_1);
  if ((CONCAT31(extraout_var,uVar2) != 0) && (iVar3 = xtra_getInterruptData(uVar1,&local_8), iVar3 != 0)) {
    if (((local_8 & 7) == 0) && (local_8 != 0)) {
      param_1 = local_8 & 0xfffffff8;
      iVar3 = js_internAtom(uVar1,(uint)&param_1,0x6817e9e8);
      if (iVar3 == 0) {
        return 0;
      }
    }
    else {
      param_1 = 0;
    }
    iVar3 = runtime_getErrorType(uVar1,local_8);
    puVar4 = (uint *)certs_hashLookup(uVar1,extraout_EDX);
    if (puVar4 == (uint *)0x0) {
      pcVar5 = "null";
    }
    else {
      pcVar5 = (char *)certs_encodeUri(puVar4);
    }
    if (iVar3 == 0) {
      xtra_invokeMethod(uVar1,xtra_getErrorString,0,0x93);
    }
    else {
      *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) | 2;
      xtra_reportErrorDirect(uVar1,pcVar5,iVar3);
    }
    if (param_1 != 0) {
      js_markAtom(*(int *)(uVar1 + 0x14),&param_1);
    }
    return 1;
  }
  return 0;
}



// ============================================================
// Function: runtime_constructErrorDefault (FUN_6812c1a0)
// Address: 6812c1a0
// Size: 9 bytes
// Params: uint * param_1, int * param_2, uint param_3, uint * param_4, undefined4 * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_constructErrorDefault(uint *param_1,int *param_2,uint param_3,uint *param_4,undefined4 *param_5)
{
  runtime_constructErrorObject(param_1,param_2,param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_numberToFixed (FUN_6812c1b0)
// Address: 6812c1b0
// Size: 202 bytes
// Params: uint param_1, int param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_numberToFixed(uint param_1,int param_2,undefined4 param_3,int param_4,uint *param_5)
{
  double dVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  uint *puVar5;
  char local_64 [64];
  undefined1 local_24 [28];
  uint local_8;
  
  iVar3 = xtra_callMethod(param_1,param_2,&PTR_s_Number_68192f80,param_4);
  if (iVar3 != 0) {
    uVar2 = *(uint *)(*(int *)(param_2 + 4) + 0xc);
    if (((uVar2 & 1) == 0) || (uVar2 == 0x80000001)) {
      dVar1 = *(double *)(uVar2 & 0xfffffff8);
    }
    else {
      dVar1 = (double)((int)uVar2 >> 1);
    }
    pcVar4 = javascript_numberToExponential((int)local_24,0x1a,(char *)0x0,(char *)0x0,SUB84(dVar1,0),
                          (uint)((ulonglong)dVar1 >> 0x20));
    if (pcVar4 == (char *)0x0) {
      xtra_reportError(param_1);
    }
    else {
      runtime_snprintf(local_64,0x40,"(new %s(%s))");
      puVar5 = xtra_findSymbolByName(param_1,local_64);
      if (puVar5 != (uint *)0x0) {
        *param_5 = (uint)puVar5 | 4;
        return 0;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_formatNumberDigits (FUN_6812c280)
// Address: 6812c280
// Size: 88 bytes
// Params: int param_1, int param_2
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * runtime_formatNumberDigits(int param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  char *pcVar3;
  char *pcVar4;
  uint unaff_EDI;
  
  pcVar4 = (char *)(param_1 + -1 + param_2);
  *pcVar4 = '\0';
  uVar1 = (unaff_EDI ^ (int)unaff_EDI >> 0x1f) - ((int)unaff_EDI >> 0x1f);
  do {
    pcVar3 = pcVar4;
    uVar2 = uVar1 / 10;
    pcVar4 = pcVar3 + -1;
    *pcVar4 = (char)uVar1 + (char)uVar2 * -10 + '0';
    uVar1 = uVar2;
  } while (uVar2 != 0);
  if ((int)unaff_EDI < 0) {
    pcVar3[-2] = '-';
    return pcVar3 + -2;
  }
  return pcVar4;
}



// ============================================================
// Function: runtime_numberToExponential (FUN_6812c2e0)
// Address: 6812c2e0
// Size: 56 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, int param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_numberToExponential(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  
  iVar1 = xtra_callMethod(param_1,param_2,&PTR_s_Number_68192f80,param_4);
  if (iVar1 == 0) {
    return 0;
  }
  *param_5 = *(undefined4 *)(*(int *)(param_2 + 4) + 0xc);
  return 1;
}



// ============================================================
// Function: runtime_freeNumberAtoms (FUN_6812c320)
// Address: 6812c320
// Size: 74 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_freeNumberAtoms(int param_1)
{
  int iVar1;
  
  iVar1 = *(int *)(param_1 + 0x14);
  js_freeAtom(iVar1,*(uint *)(iVar1 + 0x1d0));
  js_freeAtom(iVar1,*(uint *)(iVar1 + 0x1d4));
  js_freeAtom(iVar1,*(uint *)(iVar1 + 0x1d8));
  *(undefined4 *)(iVar1 + 0x1d0) = 0;
  *(undefined4 *)(iVar1 + 0x1d4) = 0;
  *(undefined4 *)(iVar1 + 0x1d8) = 0;
  return 0;
}



// ============================================================
// Function: runtime_storeFloat (FUN_6812c370)
// Address: 6812c370
// Size: 31 bytes
// Params: int param_1, undefined8 param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_storeFloat(int param_1,undefined8 param_2)
{
  undefined8 *puVar1;
  
  puVar1 = (undefined8 *)js_bignumFree(param_1,2);
  if (puVar1 == (undefined8 *)0x0) {
    return 0;
  }
  *puVar1 = param_2;
  return 0;
}



// ============================================================
// Function: runtime_formatNumber (FUN_6812c390)
// Address: 6812c390
// Size: 46 bytes
// Params: int param_1, undefined8 param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_formatNumber(int param_1,undefined8 param_2,uint *param_3)

{
  uint uVar1;
  
  uVar1 = runtime_storeFloat(param_1,param_2);
  if (uVar1 == 0) {
    return 0;
  }
  *param_3 = uVar1 | 2;
  return 1;
}



// ============================================================
// Function: runtime_convertToNumber (FUN_6812c3c0)
// Address: 6812c3c0
// Size: 127 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, int param_4, uint param_5, uint * param_6
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
runtime_convertToNumber(undefined4 param_1,undefined4 param_2,int param_3,int param_4,uint param_5,
            uint *param_6)

{
  int iVar1;
  float10 fVar2;
  float10 extraout_ST0;
  ulonglong uVar3;
  
  fVar2 = (float10)(double)CONCAT44(param_5,param_4);
  if (((param_5 & 0x7ff00000) != 0x7ff00000) && ((param_5 != 0x80000000 || (param_4 != 0)))) {
    uVar3 = strings_floatToUint64(param_5 & 0x7ff00000,param_2);
    iVar1 = (int)uVar3;
    fVar2 = extraout_ST0;
    if ((extraout_ST0 == (float10)iVar1) && (iVar1 + 0x3fffffffU < 0x7fffffff)) {
      *param_6 = iVar1 * 2 | 1;
      return 1;
    }
  }
  iVar1 = runtime_formatNumber(param_3,(double)fVar2,param_6);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
}



// ============================================================
// Function: runtime_createNumberObject (FUN_6812c440)
// Address: 6812c440
// Size: 83 bytes
// Params: uint param_1, undefined8 param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_createNumberObject(uint param_1,undefined8 param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  uVar1 = param_1;
  piVar2 = runtime_setProperty(param_1,&PTR_s_Number_68192f80,(undefined4 *)0x0,0);
  if (piVar2 != (int *)0x0) {
    iVar3 = runtime_convertToNumber(extraout_ECX,extraout_EDX,uVar1,(int)param_2,
                         (uint)((ulonglong)param_2 >> 0x20),&param_1);
    if (iVar3 != 0) {
      *(uint *)(piVar2[1] + 0xc) = param_1;
      return piVar2;
    }
    *(undefined4 *)(uVar1 + 0x90) = 0;
  }
  return (int *)0x0;
}



// ============================================================
// Function: runtime_divideFloat (FUN_6812c4a0)
// Address: 6812c4a0
// Size: 174 bytes
// Params: undefined4 param_1, undefined4 param_2, uint param_3, double param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall runtime_divideFloat(undefined4 param_1,undefined4 param_2,uint param_3,double param_4)
{
  char *pcVar1;
  float10 fVar2;
  float10 extraout_ST0;
  ulonglong uVar3;
  uint uStack_28;
  undefined1 local_24 [28];
  uint local_8;
  
  fVar2 = (float10)param_4;
  uStack_28 = (uint)((ulonglong)param_4 >> 0x20);
  if ((((uStack_28 & 0x7ff00000) == 0x7ff00000) || (param_4 == -0.0)) ||
     (uVar3 = strings_floatToUint64(uStack_28 & 0x7ff00000,param_2), fVar2 = extraout_ST0,
     extraout_ST0 != (float10)(int)uVar3)) {
    pcVar1 = javascript_numberToExponential((int)local_24,0x1a,(char *)0x0,(char *)0x0,SUB84((double)fVar2,0),
                          (uint)((ulonglong)(double)fVar2 >> 0x20));
    if (pcVar1 == (char *)0x0) {
      xtra_reportError(param_3);
      return 0;
    }
  }
  else {
    pcVar1 = runtime_formatNumberDigits((int)local_24,0x1a);
  }
  xtra_findSymbolByName(param_3,pcVar1);
  return 0;
}



// ============================================================
// Function: runtime_multiplyFloat (FUN_6812c550)
// Address: 6812c550
// Size: 163 bytes
// Params: undefined4 param_1, undefined4 param_2, uint param_3, undefined4 * param_4
// Return: undefined8
// Calling convention: __stdcall
// ============================================================

undefined8 runtime_multiplyFloat(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar1;
  undefined4 in_EDX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar2;
  float10 fVar3;
  ulonglong uVar4;
  double dVar5;
  
  if (((param_3 & 0x7ff00000) == 0x7ff00000) || ((double)CONCAT44(param_3,param_2) == 0.0)) {
    *param_4 = 0;
    return CONCAT44(in_EDX,1);
  }
  fVar3 = (float10)_CIfmod();
  if ((float10)0 < fVar3 == ((float10)0 == fVar3)) {
    dVar5 = ceil((double)fVar3);
    dVar5 = dVar5 + 4294967296.0;
    uVar1 = extraout_ECX_00;
    uVar2 = extraout_EDX_00;
  }
  else {
    dVar5 = floor((double)fVar3);
    uVar1 = extraout_ECX;
    uVar2 = extraout_EDX;
  }
  /* FIXUP(C2064: term does not evaluate to a function taking 0 arguments): if (NAN(dVar5) || 2147483648.0 < dVar5 == (dVar5 == 2147483648.0)) { */
    uVar4 = strings_floatToUint64(uVar1,uVar2);
    *param_4 = (int)uVar4;
    return CONCAT44(param_4,1);
  }
  /* FIXUP(C2065: undeclared 'uVar1'): uVar4 = strings_floatToUint64(uVar1,uVar2); */
  /* FIXUP(C2065: undeclared 'uVar4'): *param_4 = (int)uVar4; */
  /* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: 'return'): return CONCAT44((int)(uVar4 >> 0x20),1); */
/* FIXUP(syntax error - Ghidra decompilation artifact: syntax error: '}'): } */



// ============================================================
// Function: runtime_addFloat (FUN_6812c600)
// Address: 6812c600
// Size: 182 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_addFloat(undefined4 param_1,undefined4 param_2,uint param_3,undefined4 *param_4)

{
  double _X;
  float10 fVar1;
  undefined4 local_c;
  
  if (((param_3 & 0x7ff00000) != 0x7ff00000) &&
     (_X = (double)CONCAT26((*(unsigned short *)((char *)&param_3 + 2)),CONCAT24((undefined2)param_3,param_2)), _X != 0.0)) {
    if (_X < 0.0) {
      _X = -_X;
    }
    floor(_X);
    fVar1 = (float10)_CIfmod();
    if ((float10)0 < fVar1 == ((float10)0 == fVar1)) {
      fVar1 = fVar1 + (float10)4294967296.0;
    }
    local_c = (undefined4)(longlong)ROUND(fVar1);
    *param_4 = local_c;
    return 1;
  }
  *param_4 = 0;
  return 1;
}



// ============================================================
// Function: runtime_powFloat (FUN_6812c6c0)
// Address: 6812c6c0
// Size: 113 bytes
// Params: int param_1, uint param_2
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 runtime_powFloat(int param_1,uint param_2)

{
  float10 fVar1;
  float10 fVar2;
  float10 fVar3;
  double dVar4;
  
  fVar2 = (float10)(double)CONCAT44(param_2,param_1);
  fVar1 = (float10)0;
  if (fVar1 != fVar2) {
    if ((param_2 & 0x7ff00000) != 0x7ff00000) {
      fVar3 = fVar2;
      if (fVar2 < fVar1) {
        fVar3 = -fVar2;
      }
      dVar4 = floor((double)fVar3);
      fVar3 = (float10)dVar4;
      if (fVar2 < fVar1) {
        fVar3 = -fVar3;
      }
      return fVar3;
    }
    if ((param_1 != 0) || ((param_2 & 0xfffff) != 0)) {
      return fVar1;
    }
  }
  return fVar2;
}



// ============================================================
// Function: runtime_parseNumberFromWchar (FUN_6812c740)
// Address: 6812c740
// Size: 460 bytes
// Params: int param_1, ushort * param_2, int * param_3, double * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_parseNumberFromWchar(int param_1,ushort *param_2,int *param_3,double *param_4)
{
  char cVar1;
  ushort *puVar2;
  uint uVar3;
  char *pcVar4;
  uint uVar5;
  int iVar6;
  double *pdVar7;
  float10 fVar8;
  double local_3c;
  char *local_34;
  char *local_30;
  int local_2c;
  char local_28 [32];
  uint local_8;
  
  local_2c = param_1;
  puVar2 = certs_duplicateString(param_2);
  uVar3 = certs_getStringLength((short *)puVar2);
  if (uVar3 < 0x20) {
    pcVar4 = local_28;
  }
  else {
    pcVar4 = (char *)xtra_getPropertyById(param_1,uVar3 + 1);
    if (pcVar4 == (char *)0x0) {
      return 0;
    }
  }
  uVar5 = 0;
  do {
    if ((puVar2[uVar5] & 0xff00) != 0) {
      pcVar4[uVar5] = '\0';
      break;
    }
    pcVar4[uVar5] = (char)puVar2[uVar5];
    uVar5 = uVar5 + 1;
  } while (uVar5 <= uVar3);
  cVar1 = *pcVar4;
  if ((cVar1 == '-') || (local_30 = pcVar4, cVar1 == '+')) {
    local_30 = pcVar4 + 1;
  }
  iVar6 = strncmp(local_30,"Infinity",8);
  if (iVar6 == 0) {
    if (cVar1 == '-') {
      fVar8 = (float10)**(double **)(*(int *)(local_2c + 0x14) + 0x1d4);
      local_34 = local_30 + 8;
    }
    else {
      fVar8 = (float10)**(double **)(*(int *)(local_2c + 0x14) + 0x1d8);
      local_34 = local_30 + 8;
    }
  }
  else {
    fVar8 = FUN_6813a980(pcVar4,&local_34,&local_30);
    iVar6 = local_2c;
    local_3c = (double)fVar8;
    if (local_30 == (char *)0x2) {
      xtra_reportError(local_2c);
      if (pcVar4 != local_28) {
        xtra_checkAndFlush(iVar6,(int)pcVar4);
      }
      return 0;
    }
    if (local_30 != (char *)0x1) goto LAB_6812c8cb;
    if ((float10)*(double *)_HUGE_exref == fVar8) {
      pdVar7 = *(double **)(*(int *)(local_2c + 0x14) + 0x1d8);
    }
    else {
      if (fVar8 != -(float10)*(double *)_HUGE_exref) goto LAB_6812c8cb;
      pdVar7 = *(double **)(*(int *)(local_2c + 0x14) + 0x1d4);
    }
    fVar8 = (float10)*pdVar7;
  }
  local_3c = (double)fVar8;
LAB_6812c8cb:
  iVar6 = (int)local_34 - (int)pcVar4;
  if (pcVar4 != local_28) {
    xtra_checkAndFlush(local_2c,(int)pcVar4);
    fVar8 = (float10)local_3c;
  }
  puVar2 = puVar2 + iVar6;
  if (iVar6 == 0) {
    puVar2 = param_2;
  }
  *param_3 = (int)puVar2;
  *param_4 = (double)fVar8;
  return 0;
}



// ============================================================
// Function: runtime_numberToString (FUN_6812c920)
// Address: 6812c920
// Size: 86 bytes
// Params: uint * param_1
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall runtime_numberToString(uint *param_1)

{
  ushort *puVar1;
  uint uVar2;
  
  if (param_1[2] == 0) {
    puVar1 = (ushort *)param_1[3];
    if (puVar1 == (ushort *)param_1[4]) {
      return 0xffffffff;
    }
    uVar2 = (uint)*puVar1;
    param_1[3] = (uint)(puVar1 + 1);
    if (uVar2 - 0x30 < 10) {
      uVar2 = uVar2 - 0x30;
    }
    else if (uVar2 - 0x61 < 0x1a) {
      uVar2 = uVar2 - 0x57;
    }
    else {
      uVar2 = uVar2 - 0x37;
    }
    param_1[1] = uVar2;
    param_1[2] = *param_1 >> 1;
  }
  uVar2 = param_1[2];
  param_1[2] = uVar2 >> 1;
  return (uint)((param_1[1] & uVar2) != 0);
}



// ============================================================
// Function: runtime_parseNumberWithRadix (FUN_6812c980)
// Address: 6812c980
// Size: 638 bytes
// Params: int param_1, ushort * param_2, undefined4 * param_3, uint param_4, double * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_parseNumberWithRadix(int param_1,ushort *param_2,undefined4 *param_3,uint param_4,double *param_5)

{
  ushort uVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  uint uVar5;
  uint *extraout_ECX;
  uint *extraout_ECX_00;
  ushort *puVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  float10 fVar10;
  float10 fVar11;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST0_01;
  float10 fVar12;
  float10 extraout_ST1;
  float10 extraout_ST1_00;
  float10 extraout_ST1_01;
  uint local_2c [2];
  undefined4 local_24;
  ushort *local_20;
  ushort *local_1c;
  double local_18;
  uint local_10;
  ushort *local_c;
  ushort *local_8;
  
  local_20 = certs_duplicateString(param_2);
  iVar8 = param_1;
  local_10 = (uint)(*local_20 == 0x2d);
  if ((local_10 != 0) || (*local_20 == 0x2b)) {
    local_20 = local_20 + 1;
  }
  if (param_4 == 0) {
    if (*local_20 != 0x30) {
      param_4 = 10;
      goto LAB_6812ca03;
    }
    if ((local_20[1] != 0x58) && (local_20[1] != 0x78)) {
      param_4 = 8;
      goto LAB_6812ca03;
    }
    param_4 = 0x10;
  }
  else if (((param_4 != 0x10) || (*local_20 != 0x30)) ||
          ((local_20[1] != 0x58 && (local_20[1] != 0x78)))) goto LAB_6812ca03;
  local_20 = local_20 + 2;
LAB_6812ca03:
  fVar11 = (float10)0;
  puVar6 = local_20;
  fVar12 = fVar11;
  do {
    uVar1 = *puVar6;
    uVar2 = (uint)uVar1;
    if ((ushort)(uVar1 - 0x30) < 10) {
      uVar2 = uVar2 - 0x30;
    }
    else if ((ushort)(uVar1 - 0x61) < 0x1a) {
      uVar2 = uVar2 - 0x57;
    }
    else {
      if (0x19 < (ushort)(uVar1 - 0x41)) break;
      uVar2 = uVar2 - 0x37;
    }
    if (param_4 <= uVar2) break;
    fVar10 = (float10)(int)uVar2;
    if ((int)uVar2 < 0) {
      fVar10 = fVar10 + (float10)4294967296.0;
    }
    fVar12 = fVar10 + fVar12 * (float10)(int)param_4;
    puVar6 = puVar6 + 1;
  } while( true );
  local_c = local_20;
  if ((float10)9007199254740992.0 < fVar12 != ((float10)9007199254740992.0 == fVar12)) {
    local_8 = puVar6;
    if (param_4 == 10) {
      iVar7 = (int)puVar6 - (int)local_20 >> 1;
      pcVar3 = (char *)xtra_getPropertyById(param_1,iVar7 + 1);
      iVar4 = 0;
      param_4 = 0;
      if (pcVar3 != (char *)0x0) {
        if (iVar7 != 0) {
          do {
            pcVar3[iVar4] = (char)local_c[iVar4];
            iVar4 = iVar4 + 1;
          } while (iVar4 != iVar7);
        }
        pcVar3[iVar7] = '\0';
        fVar11 = FUN_6813a980(pcVar3,&param_1,&param_4);
        local_18 = (double)fVar11;
        if (param_4 != 2) {
          if ((param_4 == 1) && ((float10)*(double *)_HUGE_exref == fVar11)) {
            local_18 = **(double **)(*(int *)(iVar8 + 0x14) + 0x1d8);
          }
          xtra_checkAndFlush(iVar8,(int)pcVar3);
          fVar12 = (float10)local_18;
          fVar11 = (float10)0;
          puVar6 = local_8;
          goto LAB_6812cb1e;
        }
        xtra_reportError(iVar8);
        xtra_checkAndFlush(iVar8,(int)pcVar3);
      }
      return 0;
    }
    if ((param_4 & param_4 - 1) == 0) {
      local_24 = 0;
      local_2c[0] = param_4;
      local_1c = puVar6;
      do {
        uVar2 = runtime_numberToString(local_2c);
      } while (uVar2 == 0);
      fVar12 = extraout_ST0;
      fVar11 = extraout_ST1;
      if (uVar2 == 1) {
        iVar8 = 0x34;
        do {
          uVar2 = runtime_numberToString(local_2c);
          fVar12 = extraout_ST1_00;
          if ((int)uVar2 < 0) goto LAB_6812cb1e;
          iVar8 = iVar8 + -1;
          param_4 = uVar2;
        } while (iVar8 != 0);
        param_4 = runtime_numberToString(extraout_ECX);
        fVar12 = extraout_ST1_01;
        if (-1 < (int)param_4) {
          fVar10 = extraout_ST1_01;
          uVar5 = runtime_numberToString(extraout_ECX_00);
          uVar9 = 0;
          fVar12 = extraout_ST0_00;
          while (-1 < (int)uVar5) {
            uVar9 = uVar9 | uVar5;
            uVar5 = runtime_numberToString(local_2c);
            fVar12 = extraout_ST0_01;
          }
          fVar12 = fVar12 * ((float10)(int)((uVar9 | uVar2) & param_4) + fVar10);
        }
      }
    }
  }
LAB_6812cb1e:
  if (puVar6 == local_c) {
    *param_5 = (double)fVar11;
    *param_3 = param_2;
    return 1;
  }
  if (local_10 != 0) {
    fVar12 = -fVar12;
  }
  *param_5 = (double)fVar12;
  *param_3 = puVar6;
  return 1;
}



// ============================================================
// Function: runtime_numberConstructor (FUN_6812cc00)
// Address: 6812cc00
// Size: 138 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_numberConstructor(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  undefined8 uVar3;
  double local_c;
  
  puVar1 = (uint *)certs_hashLookup(param_1,*param_4);
  if (puVar1 == (uint *)0x0) {
    return 0;
  }
  puVar1 = (uint *)crypto_normalizeString(param_1,puVar1);
  if (puVar1 != (uint *)0x0) {
    uVar3 = runtime_parseNumberFromWchar(param_1,(ushort *)puVar1,(int *)&param_4,&local_c);
    if ((int)uVar3 != 0) {
      if (param_4 == puVar1) {
        *param_5 = *(uint *)(*(int *)(param_1 + 0x14) + 0x1d0) | 2;
        return 1;
      }
      uVar2 = runtime_convertToNumber(param_5,(int)((ulonglong)uVar3 >> 0x20),param_1,SUB84(local_c,0),
                           (uint)((ulonglong)local_c >> 0x20),param_5);
      return uVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_initNumberConstants (FUN_6812cc90)
// Address: 6812cc90
// Size: 251 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 runtime_initNumberConstants(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x14);
  _control87(0x9001f,0xb001f);
  _DAT_68193028 = 0x7fffffffffffffff;
  _DAT_68196978 = _DAT_68193028;
  uVar1 = runtime_storeFloat(param_1,0x7fffffffffffffff);
  *(uint *)(iVar3 + 0x1d0) = uVar1;
  if (uVar1 != 0) {
    iVar2 = js_getAtomString(param_1,uVar1);
    if (iVar2 != 0) {
      _DAT_68193038 = 0x7ff0000000000000;
      uVar1 = runtime_storeFloat(param_1,0x7ff0000000000000);
      *(uint *)(iVar3 + 0x1d8) = uVar1;
      if (uVar1 != 0) {
        iVar2 = js_getAtomString(param_1,uVar1);
        if (iVar2 != 0) {
          _DAT_68193048 = 0xfff0000000000000;
          uVar1 = runtime_storeFloat(param_1,0xfff0000000000000);
          *(uint *)(iVar3 + 0x1d4) = uVar1;
          if (uVar1 != 0) {
            iVar3 = js_getAtomString(param_1,uVar1);
            if (iVar3 != 0) {
              _DAT_68193068 = 1;
              return 1;
            }
          }
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_parseNumber (FUN_6812cd90)
// Address: 6812cd90
// Size: 309 bytes
// Params: ushort * param_1, uint param_2, double * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_parseNumber(ushort *param_1,uint param_2,double *param_3)

{
  int local_14;
  ushort *puVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  ushort *puVar5;
  ushort *puVar6;
  uint uVar7;
  
  puVar1 = param_1;
  if ((param_2 & 7) == 0) {
    piVar2 = (int *)(param_2 & 0xfffffff8);
    if (piVar2 == (int *)0x0) {
      *param_3 = 0.0;
      return 1;
    }
    iVar3 = (**(code **)(*(int *)(*piVar2 + 4) + 0x24))(param_1,piVar2,4,&param_2);
    if (iVar3 == 0) {
      return 0;
    }
  }
  if (((param_2 & 1) != 0) && (param_2 != 0x80000001)) {
    *param_3 = (double)((int)param_2 >> 1);
    return 1;
  }
  uVar7 = param_2 & 7;
  if (uVar7 == 2) {
    *param_3 = *(double *)(param_2 & 0xfffffff8);
    return 1;
  }
  if (uVar7 == 4) {
    puVar4 = (uint *)(param_2 & 0xfffffff8);
    puVar5 = (ushort *)crypto_normalizeString((int)puVar1,puVar4);
    if (puVar5 == (ushort *)0x0) {
      return 0;
    }
    iVar3 = runtime_parseNumberFromWchar((int)puVar1,puVar5,(int *)&param_1,param_3);
    if ((iVar3 != 0) && (puVar6 = certs_duplicateString(param_1), puVar6 == puVar5 + *puVar4)) {
      return 1;
    }
    iVar3 = runtime_parseNumberWithRadix((int)puVar1,puVar5,&param_1,0,param_3);
    if ((iVar3 != 0) && (puVar6 = certs_duplicateString(param_1), puVar6 == puVar5 + *puVar4)) {
      return 1;
    }
  }
  else if (uVar7 == 6) {
    *param_3 = (double)((param_2 & 0xfffffff8) != 0);
    return 1;
  }
  *param_3 = **(double **)(*(int *)(puVar1 + 10) + 0x1d0);
  return 1;
}



// ============================================================
// Function: runtime_parseInt (FUN_6812ced0)
// Address: 6812ced0
// Size: 61 bytes
// Params: ushort * param_1, uint param_2, undefined4 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_parseInt(ushort *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  undefined8 uVar2;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,param_2,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  uVar2 = runtime_multiplyFloat(param_1,SUB84(local_c,0),(uint)((ulonglong)local_c >> 0x20),param_3);
  return (int)uVar2;
}



// ============================================================
// Function: runtime_parseFloat (FUN_6812cf10)
// Address: 6812cf10
// Size: 61 bytes
// Params: ushort * param_1, uint param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_parseFloat(ushort *param_1,uint param_2,undefined4 *param_3)
{
  int iVar1;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,param_2,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  runtime_addFloat(param_1,SUB84(local_c,0),(int)((ulonglong)local_c >> 0x20),param_3);
  return 0;
}



// ============================================================
// Function: runtime_convertStringToNumber (FUN_6812cf50)
// Address: 6812cf50
// Size: 225 bytes
// Params: ushort * param_1, undefined * * param_2, int * param_3
// Return: undefined8
// Calling convention: __stdcall
// ============================================================

undefined8 runtime_convertStringToNumber(ushort *param_1,undefined **param_2,int *param_3)

{
  double dVar1;
  int iVar2;
  uint *puVar3;
  undefined4 extraout_ECX;
  undefined4 in_EDX;
  uint extraout_EDX;
  undefined4 extraout_EDX_00;
  uint extraout_EDX_01;
  uint extraout_EDX_02;
  uint uVar4;
  ulonglong uVar5;
  int local_c;
  uint uStack_8;
  
  if ((((uint)param_2 & 1) != 0) && (param_2 != (undefined **)0x80000001)) {
    *param_3 = (int)param_2 >> 1;
    return CONCAT44(in_EDX,1);
  }
  iVar2 = runtime_parseNumber(param_1,(uint)param_2,(double *)&local_c);
  uVar4 = extraout_EDX;
  if (iVar2 != 0) {
    if (((((uStack_8 & 0x7ff00000) != 0x7ff00000) || ((local_c == 0 && ((uStack_8 & 0xfffff) == 0)))
         ) && (dVar1 = (double)CONCAT44(uStack_8,local_c),
              dVar1 < -2147483649.0 == (dVar1 == -2147483649.0))) && (dVar1 < 2147483648.0)) {
      floor(dVar1 + 0.5);
      uVar5 = strings_floatToUint64(extraout_ECX,extraout_EDX_00);
      *param_3 = (int)uVar5;
      return CONCAT44((int)(uVar5 >> 0x20),1);
    }
    puVar3 = crypto_decompileExpr((int)param_1,(int *)0x1,param_2,(uint *)0x0);
    uVar4 = extraout_EDX_01;
    if (puVar3 != (uint *)0x0) {
      xtra_getStringValue(puVar3);
      xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x23);
      uVar4 = extraout_EDX_02;
    }
  }
  return (ulonglong)uVar4 << 0x20;
}



// ============================================================
// Function: runtime_parseNumberToInt (FUN_6812d040)
// Address: 6812d040
// Size: 293 bytes
// Params: ushort * param_1, uint param_2, undefined2 * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_parseNumberToInt(ushort *param_1,uint param_2,undefined2 *param_3)

{
  double _X;
  double dVar1;
  int iVar2;
  float10 fVar3;
  undefined8 local_c;
  
  iVar2 = runtime_parseNumber(param_1,param_2,(double *)&local_c);
  _X = local_c;
  if (iVar2 == 0) {
    return 0;
  }
  if ((local_c != 0.0) && (((*(unsigned int *)((char *)&local_c + 4)) & 0x7ff00000) != 0x7ff00000)) {
    local_c = (double)(longlong)ROUND(local_c);
    dVar1 = (double)(int)local_c;
    if ((int)local_c < 0) {
      dVar1 = dVar1 + 4294967296.0;
    }
    if (_X == dVar1) {
      *param_3 = SUB82(local_c,0);
      return 1;
    }
    if (_X < 0.0) {
      _X = -_X;
    }
    floor(_X);
    fVar3 = (float10)_CIfmod();
    if (fVar3 < (float10)0) {
      fVar3 = fVar3 + (float10)65536.0;
    }
    (*(unsigned short *)((char *)&param_1 + 0)) = (undefined2)(int)ROUND(fVar3);
    *param_3 = (*(unsigned short *)((char *)&param_1 + 0));
    return 1;
  }
  *param_3 = 0;
  return 1;
}



// ============================================================
// Function: runtime_globalParseInt (FUN_6812d170)
// Address: 6812d170
// Size: 102 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_globalParseInt(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  int local_c;
  uint local_8;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,(double *)&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  if (((local_8 & 0x7ff00000) == 0x7ff00000) && ((local_c != 0 || ((local_8 & 0xfffff) != 0)))) {
    iVar1 = 1;
  }
  else {
    iVar1 = 0;
  }
  *param_5 = iVar1 * 8 | 6;
  return 1;
}



// ============================================================
// Function: runtime_globalParseFloat (FUN_6812d1e0)
// Address: 6812d1e0
// Size: 80 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
runtime_globalParseFloat(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  undefined8 local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,(double *)&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  *param_5 = (uint)(((*(unsigned int *)((char *)&local_c + 4)) & 0x7ff00000) != 0x7ff00000) * 8 | 6;
  return 1;
}



// ============================================================
// Function: runtime_numberValueOf (FUN_6812d230)
// Address: 6812d230
// Size: 212 bytes
// Params: ushort * param_1, undefined4 param_2, uint param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_numberValueOf(ushort *param_1,undefined4 param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 extraout_ECX;
  uint *puVar4;
  double local_c;
  
  puVar4 = param_4;
  puVar1 = (uint *)certs_hashLookup((int)param_1,*param_4);
  if (puVar1 != (uint *)0x0) {
    if (param_3 < 2) {
      puVar4 = (uint *)0x0;
    }
    else {
      iVar2 = runtime_parseInt(param_1,puVar4[1],&param_4);
      if (iVar2 == 0) {
        return 0;
      }
      puVar4 = param_4;
      if ((param_4 != (uint *)0x0) && (((int)param_4 < 2 || (0x24 < (int)param_4)))) {
        *param_5 = *(uint *)(*(int *)(param_1 + 10) + 0x1d0) | 2;
        return 1;
      }
    }
    puVar1 = (uint *)crypto_normalizeString((int)param_1,puVar1);
    if ((puVar1 != (uint *)0x0) &&
       (iVar2 = runtime_parseNumberWithRadix((int)param_1,(ushort *)puVar1,&param_4,(uint)puVar4,&local_c),
       iVar2 != 0)) {
      if (param_4 != puVar1) {
        uVar3 = runtime_convertToNumber(extraout_ECX,param_5,(int)param_1,SUB84(local_c,0),
                             (uint)((ulonglong)local_c >> 0x20),param_5);
        return uVar3;
      }
      *param_5 = *(uint *)(*(int *)(param_1 + 10) + 0x1d0) | 2;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_numberToStringWithRadix (FUN_6812d310)
// Address: 6812d310
// Size: 119 bytes
// Params: undefined4 param_1, undefined4 param_2, ushort * param_3, int param_4, uint param_5, uint * param_6, uint * param_7
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
runtime_numberToStringWithRadix(undefined4 param_1,undefined4 param_2,ushort *param_3,int param_4,uint param_5,
            uint *param_6,uint *param_7)

{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  double local_c;
  
  if (param_5 == 0) {
    local_c = 0.0;
  }
  else {
    iVar1 = runtime_parseNumber(param_3,*param_6,&local_c);
    param_1 = extraout_ECX;
    param_2 = extraout_EDX;
    if (iVar1 == 0) {
      return 0;
    }
  }
  iVar1 = runtime_convertToNumber(param_1,param_2,(int)param_3,SUB84(local_c,0),
                       (uint)((ulonglong)local_c >> 0x20),&param_5);
  if (iVar1 == 0) {
    return 0;
  }
  if ((*(byte *)(*(int *)(param_3 + 0x1a) + 0x4c) & 1) == 0) {
    *param_7 = param_5;
    return 1;
  }
  *(uint *)(*(int *)(param_4 + 4) + 0xc) = param_5;
  return 1;
}



// ============================================================
// Function: runtime_numberToPrecision (FUN_6812d390)
// Address: 6812d390
// Size: 303 bytes
// Params: ushort * param_1, int param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_numberToPrecision(ushort *param_1,int param_2,int param_3,uint *param_4,uint *param_5)
{
  uint uVar1;
  int iVar2;
  uint *puVar3;
  char *pcVar4;
  int extraout_ECX;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar5;
  uint local_18;
  undefined1 local_14 [4];
  double local_10;
  uint local_8;
  
  iVar2 = xtra_callMethod(param_1,param_2,&PTR_s_Number_68192f80,(int)param_4);
  if (iVar2 == 0) goto LAB_6812d42f;
  iVar2 = *(int *)(param_2 + 4);
  uVar1 = *(uint *)(iVar2 + 0xc);
  if (((uVar1 & 1) == 0) || (uVar1 == 0x80000001)) {
    local_10 = *(double *)(uVar1 & 0xfffffff8);
  }
  else {
    local_10 = (double)((int)uVar1 >> 1);
  }
  local_18 = 10;
  uVar5 = extraout_EDX;
  if (param_3 == 0) {
LAB_6812d449:
    puVar3 = (uint *)runtime_divideFloat(iVar2,uVar5,(uint)param_1,local_10);
  }
  else {
    iVar2 = runtime_parseInt(param_1,*param_4,&local_18);
    if (iVar2 == 0) goto LAB_6812d42f;
    if (((int)local_18 < 2) || (0x24 < (int)local_18)) {
      runtime_formatNumberDigits((int)local_14,0xc);
      xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x21);
      goto LAB_6812d42f;
    }
    iVar2 = extraout_ECX;
    uVar5 = extraout_EDX_00;
    if (local_18 == 10) goto LAB_6812d449;
    pcVar4 = javascript_numberValueOfMethod(local_18,local_10);
    if (pcVar4 == (char *)0x0) {
      xtra_reportError((int)param_1);
      return 0;
    }
    puVar3 = xtra_findSymbolByName((uint)param_1,pcVar4);
    js_freeHandle();
  }
  if (puVar3 != (uint *)0x0) {
    *param_5 = (uint)puVar3 | 4;
    return 0;
  }
LAB_6812d42f:
  return 0;
}



// ============================================================
// Function: runtime_numberToLocaleString (FUN_6812d4c0)
// Address: 6812d4c0
// Size: 30 bytes
// Params: ushort * param_1, int param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_numberToLocaleString(ushort *param_1,int param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  runtime_numberToPrecision(param_1,param_2,0,param_4,param_5);
  return 0;
}



// ============================================================
// Function: runtime_formatNumberWithPrecision (FUN_6812d4e0)
// Address: 6812d4e0
// Size: 287 bytes
// Params: undefined4 param_1, int param_2, int param_3, uint * param_4, uint * param_5, char * param_6, int param_7, int param_8
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
runtime_formatNumberWithPrecision(char *param_1,int param_2,int param_3,uint *param_4,uint *param_5,char *param_6,
            int param_7,int param_8)
{
  uint uVar1;
  int iVar2;
  char *pcVar3;
  uint *puVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 uVar5;
  undefined4 extraout_EDX;
  undefined4 extraout_EDX_00;
  undefined4 uVar6;
  ushort *unaff_EDI;
  float10 fVar7;
  ulonglong uVar8;
  double dVar9;
  double local_a4;
  uint *local_9c;
  char *local_98;
  int local_94;
  double local_90;
  undefined1 local_88 [128];
  uint local_8;
  
  local_9c = param_5;
  local_98 = param_1;
  local_94 = param_2;
  iVar2 = xtra_callMethod(unaff_EDI,param_3,&PTR_s_Number_68192f80,(int)param_4);
  if (iVar2 != 0) {
    uVar1 = *(uint *)(*(int *)(param_3 + 4) + 0xc);
    if (((uVar1 & 1) == 0) || (uVar1 == 0x80000001)) {
      local_90 = *(double *)(uVar1 & 0xfffffff8);
    }
    else {
      local_90 = (double)((int)uVar1 >> 1);
    }
    uVar5 = extraout_ECX;
    uVar6 = extraout_EDX;
    if (*param_4 != 0x80000001) {
      iVar2 = runtime_parseNumber(unaff_EDI,*param_4,&local_a4);
      if (iVar2 == 0) goto LAB_6812d64b;
      fVar7 = runtime_powFloat(SUB84(local_a4,0),(uint)((ulonglong)local_a4 >> 0x20));
      if ((fVar7 < (float10)param_7) ||
         (uVar5 = extraout_ECX_00, uVar6 = extraout_EDX_00, param_6 = local_98,
         (float10)param_8 < fVar7)) {
        pcVar3 = javascript_numberToExponential((int)local_88,0x7d,(char *)0x0,(char *)0x0,SUB84((double)fVar7,0),
                              (uint)((ulonglong)(double)fVar7 >> 0x20));
        if (pcVar3 != (char *)0x0) {
          xtra_invokeMethod((uint)unaff_EDI,xtra_getErrorString,0,0x96);
          goto LAB_6812d64b;
        }
        goto LAB_6812d61b;
      }
    }
    dVar9 = local_90;
    uVar8 = strings_floatToUint64(uVar5,uVar6);
    pcVar3 = javascript_numberToExponential((int)local_88,0x7d,param_6,(char *)((int)uVar8 + local_94),SUB84(dVar9,0),
                          (uint)((ulonglong)dVar9 >> 0x20));
    if (pcVar3 == (char *)0x0) {
LAB_6812d61b:
      xtra_reportError((int)unaff_EDI);
      return 0;
    }
    puVar4 = xtra_findSymbolByName((uint)unaff_EDI,pcVar3);
    if (puVar4 != (uint *)0x0) {
      *local_9c = (uint)puVar4 | 4;
      return 0;
    }
  }
LAB_6812d64b:
  return 0;
}



// ============================================================
// Function: runtime_formatNumberComplete (FUN_6812d5ff)
// Address: 6812d5ff
// Size: 96 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_formatNumberComplete(void)
{
  char *pcVar1;
  uint unaff_EBP;
  uint unaff_EDI;
  float10 in_ST0;
  undefined4 uStack00000004;
  
  pcVar1 = javascript_numberToExponential(unaff_EBP - 0x84,0x7d,(char *)0x0,(char *)0x0,SUB84((double)in_ST0,0),
                        (uint)((ulonglong)(double)in_ST0 >> 0x20));
  if (pcVar1 == (char *)0x0) {
    xtra_reportError(unaff_EDI);
    uStack00000004 = 0x6812d62f;
    __security_check_cookie(*(uint *)(unaff_EBP - 4) ^ unaff_EBP);
    return 0;
  }
  xtra_invokeMethod(unaff_EDI,xtra_getErrorString,0,0x96);
  uStack00000004 = 0x6812d659;
  __security_check_cookie(*(uint *)(unaff_EBP - 4) ^ unaff_EBP);
  return 0;
}



// ============================================================
// Function: runtime_numberToFixedMethod (FUN_6812d660)
// Address: 6812d660
// Size: 40 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_numberToFixedMethod(undefined4 param_1,int param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  runtime_formatNumberWithPrecision(2,0,param_2,param_4,param_5,(char *)0x2,-0x14,100);
  return 0;
}



// ============================================================
// Function: runtime_numberToExponentialMethod (FUN_6812d690)
// Address: 6812d690
// Size: 43 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_numberToExponentialMethod(undefined4 param_1,int param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  runtime_formatNumberWithPrecision(3,1,param_2,param_4,param_5,(char *)0x1,0,100);
  return 0;
}



// ============================================================
// Function: runtime_numberToPrecisionMethod (FUN_6812d6c0)
// Address: 6812d6c0
// Size: 40 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_numberToPrecisionMethod(undefined4 param_1,int param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  runtime_formatNumberWithPrecision(4,0,param_2,param_4,param_5,(char *)0x0,1,100);
  return 0;
}



// ============================================================
// Function: runtime_initNumberPrototype (FUN_6812d6f0)
// Address: 6812d6f0
// Size: 219 bytes
// Params: uint param_1, int * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_initNumberPrototype(uint param_1,int *param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 extraout_EDX;
  
  _control87(0x9001f,0xb001f);
  iVar1 = events_attachVtable(param_1,param_2,(int *)&PTR_s_isNaN_68192f40);
  if (iVar1 != 0) {
    piVar2 = xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_s_Number_68192f80,0x6812d310,1,
                          (int *)0x0,(int *)&PTR_s_toSource_68192fc8,(int *)0x0,(int *)0x0);
    if (piVar2 != (int *)0x0) {
      uVar3 = xtra_lookupConstructor(param_1,piVar2);
      if (uVar3 != 0) {
        iVar1 = piVar2[1];
        *(undefined4 *)(iVar1 + 0xc) = 1;
        iVar1 = xtraRuntime_resolveChainedProps(iVar1,extraout_EDX,param_1,uVar3,0x68193028);
        if (iVar1 != 0) {
          iVar1 = *(int *)(param_1 + 0x14);
          iVar4 = events_registerProperty(param_1,param_2,"NaN",*(uint *)(iVar1 + 0x1d0) | 2,0,0);
          if (iVar4 == 0) {
            return 0;
          }
          iVar1 = events_registerProperty(param_1,param_2,"Infinity",*(uint *)(iVar1 + 0x1d8) | 2,0,0);
          return -(uint)(iVar1 != 0) & (uint)piVar2;
        }
      }
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_allocStringBuffer (FUN_6812d7d0)
// Address: 6812d7d0
// Size: 55 bytes
// Params: undefined1 param_1, undefined4 param_2
// Return: undefined1 *
// Calling convention: __stdcall
// ============================================================

undefined1 * runtime_allocStringBuffer(undefined1 param_1,undefined4 param_2)

{
  int iVar1;
  int *in_EAX;
  undefined1 *puVar2;
  
  iVar1 = *in_EAX;
  puVar2 = (undefined1 *)xtra_getPropertyById(iVar1,0x14);
  if (puVar2 == (undefined1 *)0x0) {
    xtra_reportError(iVar1);
    return (undefined1 *)0x0;
  }
  puVar2[1] = 0;
  *(undefined4 *)(puVar2 + 4) = 0;
  *puVar2 = param_1;
  *(undefined4 *)(puVar2 + 8) = param_2;
  return puVar2;
}



// ============================================================
// Function: runtime_traverseErrorChain (FUN_6812d810)
// Address: 6812d810
// Size: 253 bytes
// Params: undefined4 param_1, char * param_2, int param_3, char * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_traverseErrorChain(undefined4 param_1,char *param_2,int param_3,char *param_4)

{
  char *pcVar1;
  bool bVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  undefined1 *puVar6;
  int iVar7;
  byte bVar8;
  
  if ((param_3 == 0) || (bVar2 = true, (*(byte *)(param_3 + 1) & 8) != 0)) {
    bVar2 = false;
  }
  pcVar1 = *(char **)(param_2 + 4);
  do {
    pcVar3 = pcVar1;
    if ((pcVar3 == (char *)0x0) || (pcVar3 == param_4)) {
      if (param_3 != 0) {
        bVar8 = *(byte *)(param_3 + 1);
        if ((bVar8 & 8) == 0) {
          bVar8 = bVar8 | 8;
        }
        else {
          bVar8 = bVar8 | 0x20;
        }
        *(byte *)(param_3 + 1) = bVar8;
      }
      *(int *)(param_2 + 4) = param_3;
      if (bVar2) {
        param_2[1] = param_2[1] | 0x10;
      }
      switch(*param_2) {
      case '\x01':
      case '\x06':
      case '\a':
      case '\b':
      case '\t':
      case '\n':
      case '\'':
      case ')':
      case '*':
        iVar7 = runtime_traverseErrorChain(param_1,*(char **)(param_2 + 8),param_3,param_4);
        if (iVar7 == 0) {
          return 0;
        }
      }
      return 1;
    }
    if ((*param_2 == '\x01') && (pcVar1 = *(char **)(param_2 + 8), *pcVar1 != '\x17')) {
      pcVar4 = pcVar1;
      for (pcVar5 = *(char **)(pcVar1 + 4); pcVar5 != (char *)0x0; pcVar5 = *(char **)(pcVar5 + 4))
      {
        pcVar4 = pcVar5;
      }
      puVar6 = runtime_allocStringBuffer(0x17,0);
      *(undefined1 **)(pcVar4 + 4) = puVar6;
      if (puVar6 == (undefined1 *)0x0) {
        return 0;
      }
      puVar6[1] = puVar6[1] | 8;
      pcVar4[1] = pcVar4[1] | 0x10;
      iVar7 = runtime_traverseErrorChain(param_1,pcVar1,param_3,param_4);
      if (iVar7 == 0) {
        return 0;
      }
    }
    pcVar1 = *(char **)(pcVar3 + 4);
    param_2 = pcVar3;
  } while( true );
}



// ============================================================
// Function: runtime_parseStringToInt (FUN_6812d950)
// Address: 6812d950
// Size: 11 bytes
// Params: char * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall runtime_parseStringToInt(char *param_1,undefined4 param_2)
{
  int in_EAX;
  
  runtime_traverseErrorChain(param_2,param_1,in_EAX,(char *)0x0);
  return 0;
}



