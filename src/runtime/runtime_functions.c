// Module: runtime
// Topic: Function object creation, invocation, apply/call, and number formatting helpers
// Address range: 0x68124880 - 0x68125930
// Functions (14):
//   runtime_createFunction
//   runtime_lookupFunction
//   runtime_registerFunction
//   runtime_callFunction
//   runtime_deserializeFunction
//   runtime_compileFunction
//   runtime_initFunctionPrototype
//   runtime_padOutput
//   runtime_formatWithPadding
//   runtime_formatInt
//   runtime_formatLongInt
//   runtime_formatFloat
//   runtime_formatString
//   runtime_parseFormatArgs

// ============================================================
// Function: runtime_createFunction (FUN_68124880)
// Address: 68124880
// Size: 154 bytes
// Params: int param_1, int * param_2, int param_3, undefined2 param_4, byte param_5, uint param_6, int param_7
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_createFunction(int param_1,int *param_2,int param_3,undefined2 param_4,byte param_5,uint param_6
                  ,int param_7)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = (int *)xtra_getPropertyById(param_1,0x24);
  if (piVar1 == (int *)0x0) {
    return (int *)0x0;
  }
  if (param_2 == (int *)0x0) {
    param_2 = runtime_setProperty(param_1,&PTR_s_Function_681928b8,(undefined4 *)0x0,param_6);
    if (param_2 == (int *)0x0) goto LAB_68124901;
  }
  else {
    *(uint *)(param_2[1] + 4) = param_6;
  }
  piVar1[2] = param_3;
  *(undefined4 *)((int)piVar1 + 0x12) = 0;
  *(undefined2 *)(piVar1 + 4) = param_4;
  *piVar1 = 0;
  piVar1[1] = 0;
  piVar1[3] = 0;
  *(byte *)((int)piVar1 + 0x16) = param_5 & 0xf8;
  *(undefined1 *)((int)piVar1 + 0x17) = 0;
  piVar1[6] = param_7;
  piVar1[7] = 0;
  iVar2 = runtime_bindPrototype(param_1,piVar1,(int)param_2);
  if (iVar2 != 0) {
    return piVar1;
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
LAB_68124901:
  xtra_checkAndFlush(param_1,(int)piVar1);
  return (int *)0x0;
}



// ============================================================
// Function: runtime_lookupFunction (FUN_68124920)
// Address: 68124920
// Size: 77 bytes
// Params: int param_1, undefined4 * param_2, uint param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_lookupFunction(int param_1,undefined4 *param_2,uint param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  piVar1 = runtime_setProperty(param_1,&PTR_s_Function_681928b8,param_2,param_3);
  if (piVar1 != (int *)0x0) {
    piVar2 = (int *)xtra_getObjectTag(param_1,(int)param_2);
    iVar3 = runtime_bindPrototype(param_1,piVar2,(int)piVar1);
    if (iVar3 != 0) {
      return piVar1;
    }
    *(undefined4 *)(param_1 + 0x90) = 0;
  }
  return (int *)0x0;
}



// ============================================================
// Function: runtime_registerFunction (FUN_68124970)
// Address: 68124970
// Size: 99 bytes
// Params: int param_1, int * param_2, int param_3, int param_4, undefined2 param_5, uint param_6
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_registerFunction(int param_1,int *param_2,int param_3,int param_4,undefined2 param_5,uint param_6)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = runtime_createFunction(param_1,(int *)0x0,param_4,param_5,(byte)param_6,(uint)param_2,param_3);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  iVar2 = (**(code **)(*(int *)(*param_2 + 4) + 0xc))
                    (param_1,param_2,param_3,piVar1[1],0,0,param_6 & 0xffffff07,0);
  return -(uint)(iVar2 != 0) & (uint)piVar1;
}



// ============================================================
// Function: runtime_callFunction (FUN_681249e0)
// Address: 681249e0
// Size: 134 bytes
// Params: int param_1, uint * param_2, int param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint runtime_callFunction(int param_1,uint *param_2,int param_3)

{
  uint *puVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  
  puVar1 = param_2;
  param_2 = (uint *)*param_2;
  if ((((uint)param_2 & 7) == 0) &&
     (piVar2 = (int *)((uint)param_2 & 0xfffffff8), piVar2 != (int *)0x0)) {
    if ((undefined **)(*(uint *)(piVar2[1] + 8) & 0xfffffffe) != &PTR_s_Function_681928b8) {
      iVar3 = (**(code **)(*(int *)(*piVar2 + 4) + 0x24))(param_1,piVar2,2,&param_2);
      if (iVar3 == 0) {
        return 0;
      }
      if (((((uint)param_2 & 7) != 0) || (((uint)param_2 & 0xfffffff8) == 0)) ||
         (piVar2 = (int *)((uint)param_2 & 0xfffffff8),
         (undefined **)(*(uint *)(piVar2[1] + 8) & 0xfffffffe) != &PTR_s_Function_681928b8))
      goto LAB_68124a46;
    }
    if (piVar2 != (int *)0x0) {
      uVar4 = xtra_getObjectTag(param_1,(int)piVar2);
      return uVar4;
    }
  }
LAB_68124a46:
  runtime_callObjectMethod(param_1,puVar1,param_3);
  return 0;
}



// ============================================================
// Function: runtime_deserializeFunction (FUN_68124a70)
// Address: 68124a70
// Size: 1140 bytes
// Params: int * param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_deserializeFunction(int *param_1,int *param_2)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  uint *puVar5;
  undefined4 *puVar6;
  uint uVar7;
  int iVar8;
  code *pcVar9;
  undefined4 *puVar10;
  uint uVar11;
  int *piVar12;
  undefined4 *puVar13;
  int *piVar14;
  uint uVar15;
  undefined4 local_44 [8];
  int *local_24;
  uint local_20;
  uint *local_1c;
  char *local_18;
  uint local_14;
  undefined4 *local_10;
  code *local_c;
  int *local_8;
  
  puVar10 = (undefined4 *)param_1[2];
  local_10 = puVar10;
  if (*param_1 == 0) {
    local_8 = (int *)xtra_getObjectTag(puVar10,*param_2);
    if (local_8 == (int *)0x0) {
      return 1;
    }
    if (local_8[6] != 0) {
      local_1c = (uint *)(*(uint *)(local_8[6] + 8) & 0xfffffff8);
      goto LAB_68124ad8;
    }
  }
  else {
    local_8 = runtime_createFunction((int)puVar10,(int *)0x0,0,0,0,0,0);
    if (local_8 == (int *)0x0) {
      return 0;
    }
  }
  local_1c = (uint *)0x0;
LAB_68124ad8:
  piVar14 = local_8;
  iVar3 = runtime_serializeOptionalWideString(param_1,(int *)&local_1c);
  if (((iVar3 != 0) && (iVar3 = runtime_serializeShort(param_1,(ushort *)(piVar14 + 4)), iVar3 != 0)) &&
     (iVar3 = runtime_serializeShort(param_1,(ushort *)((int)piVar14 + 0x12)), iVar3 != 0)) {
    iVar3 = runtime_serializeShort(param_1,(ushort *)(piVar14 + 5));
    if ((iVar3 != 0) && (iVar3 = runtime_serializeByte(param_1,(byte *)((int)piVar14 + 0x16)), iVar3 != 0)) {
      if (piVar14[1] != 0) {
        uVar11 = (uint)*(ushort *)(piVar14 + 5) + (uint)*(ushort *)(piVar14 + 4);
        local_24 = (int *)(size_t)uVar11;
        if (*param_1 == 0) {
          if (uVar11 < 9) {
            puVar6 = local_44;
            local_10 = puVar6;
            local_c = (code *)0x0;
          }
          else {
            iVar3 = puVar10[0x20];
            local_c = *(code **)(iVar3 + 0xc);
            uVar7 = puVar10[0x22] + uVar11 * 4 & ~puVar10[0x22];
            puVar6 = *(undefined4 **)(iVar3 + 0xc);
            uVar15 = (int)puVar6 + uVar7;
            if (*(uint *)(iVar3 + 8) < uVar15) {
              puVar6 = (undefined4 *)js_getSlotIndex((int)(puVar10 + 0x1c),uVar7);
            }
            else {
              *(uint *)(iVar3 + 0xc) = uVar15;
            }
            local_10 = puVar6;
            piVar14 = local_8;
            if (puVar6 == (undefined4 *)0x0) {
              xtra_reportError((int)puVar10);
              return 0;
            }
          }
          uVar2 = *(undefined4 *)(*(int *)piVar14[1] + 0x24);
          uVar15 = uVar11;
          puVar13 = puVar6;
          local_10 = puVar6;
          if (uVar11 != 0) {
            for (; piVar14 = local_8, uVar15 != 0; uVar15 = uVar15 - 1) {
              *puVar13 = uVar2;
              puVar13 = puVar13 + 1;
            }
          }
          for (iVar3 = *(int *)(*(int *)piVar14[1] + 0x24); iVar3 != 0;
              iVar3 = *(int *)(iVar3 + 0x14)) {
            if (*(code **)(iVar3 + 4) == certs_executeVerify) {
              iVar8 = (int)*(short *)(iVar3 + 0x12);
LAB_68124c06:
              puVar6[iVar8] = iVar3;
            }
            else if (*(code **)(iVar3 + 4) == certs_initVerifier) {
              iVar8 = (int)*(short *)(iVar3 + 0x12) + (uint)*(ushort *)(piVar14 + 4);
              puVar6 = local_10;
              goto LAB_68124c06;
            }
          }
          uVar15 = 0;
          if (uVar11 != 0) {
            do {
              piVar14 = (int *)puVar6[uVar15];
              if (uVar15 < *(ushort *)(local_8 + 4)) {
                local_14 = 1;
              }
              else {
                local_14 = (*(byte *)(piVar14 + 4) & 2 | 4) >> 1;
              }
              local_20 = *(short *)((int)piVar14 + 0x12) * 2 | 1;
              local_18 = xtra_getStringValue((uint *)(*(uint *)(*piVar14 + 8) & 0xfffffff8));
              iVar3 = runtime_serializeValue(param_1,&local_14);
              if (((iVar3 == 0) || (iVar3 = runtime_serializeValue(param_1,&local_20), iVar3 == 0)) ||
                 (iVar3 = runtime_deserializeValue(param_1,(int *)&local_18), iVar3 == 0)) {
                if (local_c == (code *)0x0) {
                  return 0;
                }
                piVar14 = (int *)puVar10[0x20];
                if ((piVar14 != puVar10 + 0x1c) &&
                   ((uint)((int)local_c - piVar14[1]) <= (uint)(piVar14[3] - piVar14[1]))) {
                  /* FIXUP(C2296: '+': not valid as left operand has type 'code (__cdecl *)'): piVar14[3] = (uint)(local_c + puVar10[0x22]) & ~puVar10[0x22]; */
                  return 0;
                }
                js_getPrototype(puVar10 + 0x1c,(int)local_c);
                return 0;
              }
              uVar15 = uVar15 + 1;
              puVar6 = local_10;
            } while (uVar15 < uVar11);
          }
          piVar14 = local_8;
          if (local_c != (code *)0x0) {
            puVar6 = (undefined4 *)puVar10[0x20];
            if ((puVar6 == puVar10 + 0x1c) ||
               ((uint)(puVar6[3] - puVar6[1]) < (uint)((int)local_c - puVar6[1]))) {
              js_getPrototype(puVar10 + 0x1c,(int)local_c);
              piVar14 = local_8;
            }
            else {
              /* FIXUP(C2296: '+': not valid as left operand has type 'code (__cdecl *)'): puVar6[3] = (uint)(local_c + puVar10[0x22]) & ~puVar10[0x22]; */
            }
          }
        }
        else {
          for (; local_24 != (int *)0x0; local_24 = (int *)((int)local_24 - 1)) {
            uVar11 = 5;
            iVar3 = runtime_serializeValue(param_1,&local_14);
            if (iVar3 == 0) {
              return 0;
            }
            iVar3 = runtime_serializeValue(param_1,&local_20);
            if (iVar3 == 0) {
              return 0;
            }
            iVar3 = runtime_deserializeValue(param_1,(int *)&local_18);
            if (iVar3 == 0) {
              return 0;
            }
            if (local_14 == 1) {
              pcVar9 = certs_executeVerify;
              local_c = certs_verifyExtension;
            }
            else if ((local_14 == 2) || (local_14 == 3)) {
              pcVar9 = certs_initVerifier;
              local_c = certs_validatePath;
              if (local_14 == 3) {
                uVar11 = 7;
              }
            }
            else {
              pcVar9 = (code *)0x0;
              local_c = (code *)0x0;
            }
            pcVar4 = local_18;
            do {
              cVar1 = *pcVar4;
              pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            uVar15 = javascript_registerAtom((int)local_10,local_18,(int)pcVar4 - (int)(local_18 + 1),0);
            xtra_checkAndFlush(local_10,(int)local_18);
            if (uVar15 == 0) {
              return 0;
            }
            puVar5 = strings_lookupInTable(*(int *)local_8[1],uVar15,0);
            iVar3 = runtime_callPropertyEx((uint)local_10,(undefined4 *)local_8[1],uVar15,pcVar9,local_c,-1,
                                 uVar11 | 0x40,-(uint)((*puVar5 & 0xfffffffe) != 0) & 2 | 8,
                                 (int)local_20 >> 1);
            if (iVar3 == 0) {
              return 0;
            }
            puVar10 = local_10;
            piVar14 = local_8;
          }
        }
      }
      piVar12 = piVar14 + 3;
      local_24 = piVar12;
      iVar3 = runtime_resolvePrototype(param_1,piVar12,(undefined4 *)0x0);
      if (iVar3 != 0) {
        if (*param_1 == 1) {
          *param_2 = piVar14[1];
          if (local_1c != (uint *)0x0) {
            puVar6 = js_findOrCreateAtom((int)puVar10,local_1c,0);
            piVar14[6] = (int)puVar6;
            if (puVar6 == (undefined4 *)0x0) {
              return 0;
            }
            iVar3 = (**(code **)(*(int *)(*(int *)puVar10[0x23] + 4) + 0xc))
                              (puVar10,(int *)puVar10[0x23],puVar6,*param_2,0,0,1,0);
            piVar12 = local_24;
            if (iVar3 == 0) {
              return 0;
            }
          }
          runtime_invokeDebugCallback((int)puVar10,*piVar12,piVar14);
        }
        return 1;
      }
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_compileFunction (FUN_68124ef0)
// Address: 68124ef0
// Size: 1418 bytes
// Params: uint * param_1, int * param_2, int param_3, int param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_compileFunction(uint *param_1,int *param_2,int param_3,int param_4,undefined4 *param_5)

{
  uint *puVar1;
  code *pcVar2;
  uint uVar3;
  uint *puVar4;
  uint uVar5;
  void *pvVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  int *local_28;
  ushort *local_24;
  int *local_20;
  undefined4 local_1c;
  uint local_18;
  int local_14;
  uint local_10;
  ushort *local_c;
  uint local_8;
  
  if ((param_1[0xd] != 0) && ((*(byte *)(param_1[0xd] + 0x4c) & 1) == 0)) {
    param_2 = runtime_setProperty((int)param_1,&PTR_s_Function_681928b8,(undefined4 *)0x0,0);
    if (param_2 == (int *)0x0) {
      return 0;
    }
    *param_5 = param_2;
  }
  uVar3 = xtra_getObjectTag(param_1,(int)param_2);
  if (uVar3 != 0) {
    return 1;
  }
  if ((param_1[3] == 0) || (0x81 < (int)param_1[3])) {
    iVar8 = *(int *)(param_1[5] + 0xd4);
  }
  else {
    iVar8 = 0;
  }
  local_20 = runtime_createFunction((int)param_1,param_2,0,0,8,
                          *(uint *)(*(int *)((*(uint *)(param_4 + -8) & 0xfffffff8) + 4) + 4) &
                          0xfffffff8,iVar8);
  if (local_20 == (int *)0x0) {
    return 0;
  }
  for (iVar8 = *(int *)(param_1[0xd] + 0x2c); iVar8 != 0; iVar8 = *(int *)(iVar8 + 0x2c)) {
    if (*(int *)(iVar8 + 0xc) != 0) {
      uVar3 = *(uint *)(iVar8 + 0xc);
      local_14 = *(int *)(uVar3 + 0x2c);
      local_1c = *(undefined4 *)(uVar3 + 0x18);
      local_18 = runtime_getObjectField(uVar3,*(int *)(iVar8 + 0x38));
      goto LAB_68124fcb;
    }
  }
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
LAB_68124fcb:
  if (param_3 == 0) {
    puVar4 = certificates_createFromWchar((int)param_1,(short *)&DAT_68196a34,0);
  }
  else {
    local_8 = param_3 - 1;
    if (local_8 != 0) {
      uVar3 = 0;
      param_5 = (undefined4 *)0x0;
      if (local_8 != 0) {
        do {
          puVar4 = (uint *)certs_hashLookup((int)param_1,*(uint *)(param_4 + uVar3 * 4));
          if (puVar4 == (uint *)0x0) {
            return 0;
          }
          *(uint *)(param_4 + uVar3 * 4) = (uint)puVar4 | 4;
          uVar5 = *puVar4;
          if ((uVar5 & 0x40000000) != 0) {
            uVar5 = (-(uint)((uVar5 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar5;
          }
          param_5 = (undefined4 *)((int)param_5 + uVar5);
          uVar3 = uVar3 + 1;
        } while (uVar3 < local_8);
      }
      uVar10 = local_8;
      uVar5 = param_1[0x20];
      iVar8 = (int)param_5 + (local_8 - 1);
      iVar7 = *(int *)(uVar5 + 0xc);
      uVar9 = param_1[0x22] + 2 + iVar8 * 2 & ~param_1[0x22];
      local_24 = *(ushort **)(uVar5 + 0xc);
      uVar3 = (int)local_24 + uVar9;
      if (*(uint *)(uVar5 + 8) < uVar3) {
        local_24 = (ushort *)js_getSlotIndex((int)(param_1 + 0x1c),uVar9);
      }
      else {
        *(uint *)(uVar5 + 0xc) = uVar3;
      }
      if (local_24 == (ushort *)0x0) {
        return 0;
      }
      uVar3 = 0;
      local_c = local_24;
      if (uVar10 != 0) {
        do {
          puVar4 = (uint *)(*(uint *)(param_4 + uVar3 * 4) & 0xfffffff8);
          uVar5 = *puVar4;
          if ((uVar5 & 0x40000000) == 0) {
            pvVar6 = (void *)puVar4[1];
          }
          else {
            uVar10 = (-(uint)((uVar5 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar5;
            puVar1 = (uint *)puVar4[1];
            if ((*puVar1 & 0x40000000) == 0) {
              if ((int)uVar5 < 0) {
                pvVar6 = (void *)puVar1[1];
                uVar5 = uVar10;
              }
              else {
                pvVar6 = (void *)(puVar1[1] + (uVar5 >> 0xf & 0x7fff) * 2);
                uVar5 = uVar10;
              }
            }
            else {
              pvVar6 = (void *)crypto_getStringLen(puVar4);
              uVar5 = uVar10;
            }
          }
          memcpy(local_c,pvVar6,uVar5 * 2);
          uVar3 = uVar3 + 1;
          local_c[uVar5] = -(ushort)(uVar3 < local_8) & 0x2c;
          local_c = local_c + uVar5 + 1;
        } while (uVar3 < local_8);
      }
      pvVar6 = strings_createParser((int)param_1,(int)local_24,iVar8,local_1c,local_18,local_14);
      if (pvVar6 == (void *)0x0) {
        puVar4 = (uint *)param_1[0x20];
        if ((puVar4 != param_1 + 0x1c) && (iVar7 - puVar4[1] <= puVar4[3] - puVar4[1])) {
          puVar4[3] = iVar7 + param_1[0x22] & ~param_1[0x22];
          return 0;
        }
LAB_6812518c:
        js_getPrototype((int *)(param_1 + 0x1c),iVar7);
        return 0;
      }
      iVar8 = strings_parseExpression(param_1,(int)pvVar6);
      if (iVar8 != 0) {
        if (iVar8 == 0x1d) {
          while( true ) {
            local_24 = *(ushort **)((int)pvVar6 + *(int *)((int)pvVar6 + 0x60) * 0x18 + 0x14);
            iVar8 = runtime_getProperty((uint)param_1,param_2,(uint)local_24,&local_28,&local_10);
            if (iVar8 == 0) break;
            uVar3 = 0;
            if (local_10 != 0) {
              param_5 = (undefined4 *)0x1;
              if (local_28 == param_2) {
                xtra_getStringValue((uint *)(*(uint *)(local_24 + 4) & 0xfffffff8));
                param_5 = (undefined4 *)strings_scanToken(param_1,(int)pvVar6,0,5,0x6f);
                uVar3 = 2;
              }
              pcVar2 = *(code **)(*(int *)(*local_28 + 4) + 0x34);
              if (pcVar2 != (code *)0x0) {
                (*pcVar2)(param_1,local_28,local_10);
              }
              if (param_5 == (undefined4 *)0x0) break;
              local_10 = 0;
            }
            iVar8 = runtime_callPropertyEx((uint)param_1,(undefined4 *)local_20[1],(uint)local_24,certs_executeVerify
                                 ,certs_verifyExtension,-1,0x45,uVar3 | 8,(uint)*(ushort *)(local_20 + 4));
            if (iVar8 == 0) break;
            *(short *)(local_20 + 4) = (short)local_20[4] + 1;
            iVar8 = strings_parseExpression(param_1,(int)pvVar6);
            if (iVar8 == 0) goto LAB_681252f7;
            if ((iVar8 != 3) || (iVar8 = strings_parseExpression(param_1,(int)pvVar6), iVar8 != 0x1d)) break;
          }
        }
        if ((*(byte *)((int)pvVar6 + 0x7c) & 1) == 0) {
          xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x14);
        }
        strings_setParserMode(param_1,(int)pvVar6);
        puVar4 = (uint *)param_1[0x20];
        if ((puVar4 != param_1 + 0x1c) && (iVar7 - puVar4[1] <= puVar4[3] - puVar4[1])) {
          puVar4[3] = param_1[0x22] + iVar7 & ~param_1[0x22];
          return 0;
        }
        goto LAB_6812518c;
      }
LAB_681252f7:
      iVar8 = strings_setParserMode(param_1,(int)pvVar6);
      puVar4 = (uint *)param_1[0x20];
      if ((puVar4 == param_1 + 0x1c) || (puVar4[3] - puVar4[1] < iVar7 - puVar4[1])) {
        js_getPrototype((int *)(param_1 + 0x1c),iVar7);
      }
      else {
        puVar4[3] = iVar7 + param_1[0x22] & ~param_1[0x22];
      }
      if (iVar8 == 0) {
        return 0;
      }
    }
    puVar4 = (uint *)certs_hashLookup((int)param_1,*(uint *)(param_4 + -4 + param_3 * 4));
  }
  if (puVar4 == (uint *)0x0) {
    return 0;
  }
  *(uint *)(param_4 + -4 + param_3 * 4) = (uint)puVar4 | 4;
  iVar8 = *(int *)(param_1[0x20] + 0xc);
  uVar3 = *puVar4;
  if ((uVar3 & 0x40000000) == 0) {
    uVar10 = puVar4[1];
  }
  else {
    uVar5 = (-(uint)((uVar3 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar3;
    puVar1 = (uint *)puVar4[1];
    if ((*puVar1 & 0x40000000) == 0) {
      if ((int)uVar3 < 0) {
        uVar10 = puVar1[1];
        uVar3 = uVar5;
      }
      else {
        uVar10 = puVar1[1] + (uVar3 >> 0xf & 0x7fff) * 2;
        uVar3 = uVar5;
      }
    }
    else {
      uVar10 = crypto_getStringLen(puVar4);
      uVar3 = uVar5;
    }
  }
  pvVar6 = strings_createParser((int)param_1,uVar10,uVar3,local_1c,local_18,local_14);
  if ((pvVar6 != (void *)0x0) &&
     (iVar7 = crypto_compileScript((uint)param_1,(int)pvVar6,(int)local_20), iVar7 != 0)) {
    iVar7 = strings_setParserMode(param_1,(int)pvVar6);
    param_5 = (undefined4 *)0x1;
    if (iVar7 != 0) goto LAB_6812542a;
  }
  param_5 = (undefined4 *)0x0;
LAB_6812542a:
  puVar4 = (uint *)param_1[0x20];
  if ((puVar4 != param_1 + 0x1c) && (iVar8 - puVar4[1] <= puVar4[3] - puVar4[1])) {
    puVar4[3] = param_1[0x22] + iVar8 & ~param_1[0x22];
    return param_5;
  }
  js_getPrototype((int *)(param_1 + 0x1c),iVar8);
  return param_5;
}



// ============================================================
// Function: runtime_initFunctionPrototype (FUN_68125480)
// Address: 68125480
// Size: 161 bytes
// Params: int param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * runtime_initFunctionPrototype(int param_1,int *param_2)

{
  char cVar1;
  int *piVar2;
  char *pcVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  piVar2 = xtra_createScriptObject(param_1,param_2,(undefined4 *)0x0,&PTR_s_Function_681928b8,0x68124ef0,1,
                        (int *)&PTR_s_arguments_68192858,(int *)&PTR_s_toSource_68192900,(int *)0x0,
                        (int *)0x0);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  pcVar3 = PTR_s_Function_681928b8;
  do {
    cVar1 = *pcVar3;
    pcVar3 = pcVar3 + 1;
  } while (cVar1 != '\0');
  iVar4 = javascript_registerAtom(param_1,PTR_s_Function_681928b8,
                       (int)pcVar3 - (int)(PTR_s_Function_681928b8 + 1),0);
  if (iVar4 != 0) {
    piVar5 = runtime_createFunction(param_1,piVar2,0,0,0,(uint)param_2,0);
    if (piVar5 != (int *)0x0) {
      piVar6 = runtime_allocPropertyBlock(param_1,0);
      piVar5[3] = (int)piVar6;
      if (piVar6 != (int *)0x0) {
        return piVar2;
      }
    }
  }
  *(undefined4 *)(param_1 + 0x90) = 0;
  return (int *)0x0;
}



// ============================================================
// Function: runtime_padOutput (FUN_68125530)
// Address: 68125530
// Size: 107 bytes
// Params: undefined4 param_1, byte param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_padOutput(undefined4 param_1,byte param_2)

{
  int in_EAX;
  int iVar1;
  int unaff_EBX;
  undefined4 *unaff_ESI;
  int iVar2;
  
  iVar2 = in_EAX - unaff_EBX;
  if ((iVar2 < 1) || ((param_2 & 1) != 0)) {
LAB_68125565:
    iVar1 = (*(code *)*unaff_ESI)();
    if (-1 < iVar1) {
      if ((iVar2 < 1) || ((param_2 & 1) == 0)) {
LAB_68125592:
        iVar1 = 0;
      }
      else {
        do {
          iVar2 = iVar2 + -1;
          if (iVar2 < 0) goto LAB_68125592;
          iVar1 = (*(code *)*unaff_ESI)();
        } while (-1 < iVar1);
      }
    }
  }
  else {
    do {
      iVar2 = iVar2 + -1;
      if (iVar2 < 0) goto LAB_68125565;
      iVar1 = (*(code *)*unaff_ESI)();
    } while (-1 < iVar1);
  }
  return iVar1;
}



// ============================================================
// Function: runtime_formatWithPadding (FUN_681255a0)
// Address: 681255a0
// Size: 318 bytes
// Params: void * this, undefined4 param_1, int param_2, byte param_3, byte param_4
// Return: int
// Calling convention: __thiscall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int __thiscall runtime_formatWithPadding(void *this,undefined4 param_1,int param_2,byte param_3,byte param_4)

{
  int in_EAX;
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *unaff_ESI;
  undefined1 in_stack_0000000f;
  int local_14;
  int local_10;
  int local_c;
  
  iVar3 = 0;
  local_10 = 0;
  local_c = 0;
  local_14 = 0;
  if ((param_3 & 1) == 0) {
    if ((param_4 & 0x10) == 0) {
      if ((param_4 & 2) == 0) {
        if ((param_4 & 4) == 0) goto LAB_681255e4;
        in_stack_0000000f = 0x20;
      }
      else {
        in_stack_0000000f = 0x2b;
      }
    }
    else {
      in_stack_0000000f = 0x2d;
    }
    iVar3 = 1;
  }
LAB_681255e4:
  iVar1 = param_2 + iVar3;
  if ((0 < in_EAX) && (param_2 < in_EAX)) {
    local_c = in_EAX - param_2;
    iVar1 = iVar1 + local_c;
  }
  if ((((param_4 & 8) != 0) && (in_EAX < 0)) && (iVar1 < (int)this)) {
    local_10 = (int)this - iVar1;
    iVar1 = iVar1 + local_10;
  }
  if ((param_4 & 1) == 0) {
    if (iVar1 < (int)this) {
      iVar1 = (int)this - iVar1;
      goto joined_r0x6812562b;
    }
  }
  else if (iVar1 < (int)this) {
    local_14 = (int)this - iVar1;
  }
  iVar1 = 0;
joined_r0x6812562b:
  do {
    iVar1 = iVar1 + -1;
    if (iVar1 < 0) {
      if (iVar3 == 0) goto joined_r0x6812565e;
      iVar3 = (*(code *)*unaff_ESI)();
      while( true ) {
        if (iVar3 < 0) {
          return iVar3;
        }
joined_r0x6812565e:
        local_c = local_c + -1;
        if (local_c < 0) break;
        iVar3 = (*(code *)*unaff_ESI)();
      }
      do {
        local_10 = local_10 + -1;
        if (local_10 < 0) {
          iVar3 = (*(code *)*unaff_ESI)();
          while( true ) {
            if (iVar3 < 0) {
              return iVar3;
            }
            local_14 = local_14 + -1;
            if (local_14 < 0) break;
            iVar3 = (*(code *)*unaff_ESI)();
          }
          return 0;
        }
        iVar3 = (*(code *)*unaff_ESI)();
      } while (-1 < iVar3);
      return iVar3;
    }
    iVar2 = (*(code *)*unaff_ESI)();
  } while (-1 < iVar2);
  return iVar2;
}



// ============================================================
// Function: runtime_formatInt (FUN_681256e0)
// Address: 681256e0
// Size: 137 bytes
// Params: undefined4 param_1, int param_2, uint param_3, void * param_4, uint param_5, byte param_6, byte param_7
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall
runtime_formatInt(undefined4 param_1,int param_2,uint param_3,void *param_4,uint param_5,byte param_6,
            byte param_7)
{
  uint uVar1;
  uint *puVar2;
  int unaff_EBX;
  int iVar3;
  undefined1 local_9;
  uint local_8;
  
  if ((unaff_EBX == 0) && (param_3 == 0)) {
    return 0;
  }
  iVar3 = 0;
  puVar2 = &local_8;
  if (param_3 != 0) {
    do {
      uVar1 = param_3 / param_5;
      puVar2 = (uint *)((int)puVar2 + -1);
      iVar3 = iVar3 + 1;
      *(undefined1 *)puVar2 = *(undefined1 *)((param_3 % param_5 & 0xf) + param_2);
      param_3 = uVar1;
    } while (uVar1 != 0);
    if (iVar3 != 0) goto LAB_68125740;
  }
  puVar2 = (uint *)((int)puVar2 + -1);
  *(undefined1 *)puVar2 = 0x30;
  iVar3 = 1;
LAB_68125740:
  runtime_formatWithPadding(param_4,puVar2,iVar3,param_6,param_7);
  return 0;
}



// ============================================================
// Function: runtime_formatLongInt (FUN_68125770)
// Address: 68125770
// Size: 198 bytes
// Params: undefined4 param_1, int param_2, int param_3, void * param_4, int param_5, uint param_6, byte param_7, byte param_8, int param_9
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_formatLongInt(undefined4 param_1,int param_2,int param_3,void *param_4,int param_5,uint param_6,
                 byte param_7,byte param_8,int param_9)
{
  uint extraout_ECX;
  uint *puVar1;
  longlong lVar2;
  int local_70;
  undefined1 local_9;
  uint local_8;
  
  lVar2 = CONCAT44(param_3,param_2);
  if ((param_5 == 0) && (param_2 == 0 && param_3 == 0)) {
    return 0;
  }
  puVar1 = &local_8;
  local_70 = 0;
  if (param_2 != 0 || param_3 != 0) {
    do {
      puVar1 = (uint *)((int)puVar1 + -1);
      lVar2 = __aulldvrm((uint)lVar2,(uint)((ulonglong)lVar2 >> 0x20),param_6,(int)param_6 >> 0x1f);
      local_70 = local_70 + 1;
      *(undefined1 *)puVar1 = *(undefined1 *)((extraout_ECX & 0xf) + param_9);
    } while (lVar2 != 0);
    if (local_70 != 0) goto LAB_6812580c;
  }
  puVar1 = (uint *)((int)puVar1 + -1);
  *(undefined1 *)puVar1 = 0x30;
  local_70 = 1;
LAB_6812580c:
  runtime_formatWithPadding(param_4,puVar1,local_70,param_7,param_8);
  return 0;
}



// ============================================================
// Function: runtime_formatFloat (FUN_68125840)
// Address: 68125840
// Size: 142 bytes
// Params: void * this, undefined8 param_1, int param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall runtime_formatFloat(void *this,undefined8 param_1,int param_2)
{
  char cVar1;
  char *pcVar2;
  size_t _Size;
  undefined4 *unaff_EDI;
  char local_148 [300];
  char local_1c [20];
  uint local_8;
  
  _Size = param_2 - (int)this;
  if (0x13 < (int)_Size) {
    return 0;
  }
  memcpy(local_1c,this,_Size);
  local_1c[_Size] = '\0';
  sprintf(local_148,local_1c,param_1);
  pcVar2 = local_148;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  (*(code *)*unaff_EDI)();
  return 0;
}



// ============================================================
// Function: runtime_formatString (FUN_681258d0)
// Address: 681258d0
// Size: 85 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4, byte param_5
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall
runtime_formatString(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,byte param_5)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  char *unaff_EDI;
  
  if (param_2 != 0) {
    pcVar2 = unaff_EDI;
    if (unaff_EDI != (char *)0x0) {
      do {
        cVar1 = *pcVar2;
        pcVar2 = pcVar2 + 1;
      } while (cVar1 != '\0');
    }
    if (unaff_EDI == (char *)0x0) {
      unaff_EDI = "(null)";
    }
    iVar3 = runtime_padOutput(unaff_EDI,param_5);
    return iVar3;
  }
  return 0;
}



// ============================================================
// Function: runtime_parseFormatArgs (FUN_68125930)
// Address: 68125930
// Size: 621 bytes
// Params: int param_1, int * param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_parseFormatArgs(int param_1,int *param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  char cVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  int iVar8;
  char *unaff_EDI;
  
  *param_2 = 0;
  cVar4 = *unaff_EDI;
  bVar2 = false;
  if (cVar4 != '\0') {
    iVar8 = 0;
    pcVar7 = unaff_EDI;
    do {
      pcVar5 = pcVar7 + 1;
      if (cVar4 == '%') {
        cVar4 = *pcVar5;
        pcVar5 = pcVar7 + 2;
        if (cVar4 != '%') {
          while (cVar4 != '\0') {
            if (9 < (byte)(cVar4 - 0x30U)) {
              if (cVar4 == '$') {
                if (bVar2) goto LAB_68125b98;
                iVar8 = iVar8 + 1;
              }
              else {
                if (0 < iVar8) {
                  *param_2 = -1;
                  return 0;
                }
                bVar2 = true;
              }
              break;
            }
            cVar4 = *pcVar5;
            pcVar5 = pcVar5 + 1;
          }
        }
      }
      cVar4 = *pcVar5;
      pcVar7 = pcVar5;
    } while (cVar4 != '\0');
    if (iVar8 != 0) {
      iVar3 = param_3;
      if ((0x14 < iVar8) && (iVar3 = js_runGC(), iVar3 == 0)) {
        *param_2 = -1;
        return 0;
      }
      iVar6 = 0;
      if (0 < iVar8) {
        do {
          *(undefined4 *)(iVar3 + iVar6 * 8) = 0x14;
          iVar6 = iVar6 + 1;
        } while (iVar6 < iVar8);
      }
      cVar4 = *unaff_EDI;
      while (cVar4 != '\0') {
        pcVar7 = unaff_EDI + 1;
        if (cVar4 == '%') {
          cVar4 = *pcVar7;
          pcVar7 = unaff_EDI + 2;
          if (cVar4 != '%') {
            iVar6 = 0;
            if (cVar4 != '\0') {
              while (cVar4 != '$') {
                iVar6 = cVar4 + -0x30 + iVar6 * 10;
                cVar4 = *pcVar7;
                pcVar7 = pcVar7 + 1;
                if (cVar4 == '\0') goto LAB_68125a36;
              }
              if ((0 < iVar6) && (iVar6 <= iVar8)) {
                if (*(int *)(iVar3 + -8 + iVar6 * 8) != 0x14) goto LAB_68125b29;
                cVar4 = *pcVar7;
                if (cVar4 != '*') {
                  while ((pcVar7 = pcVar7 + 1, '/' < cVar4 && (cVar4 < ':'))) {
                    cVar4 = *pcVar7;
                  }
                  if (cVar4 == '.') {
                    cVar4 = *pcVar7;
                    if (cVar4 == '*') goto LAB_68125a36;
                    while ((pcVar7 = pcVar7 + 1, '/' < cVar4 && (cVar4 < ':'))) {
                      cVar4 = *pcVar7;
                    }
                  }
                  *(undefined4 *)(iVar3 + -8 + iVar6 * 8) = 2;
                  if (cVar4 == 'h') {
                    *(undefined4 *)(iVar3 + -8 + iVar6 * 8) = 0;
LAB_68125ad6:
                    cVar4 = *pcVar7;
                    pcVar7 = pcVar7 + 1;
                  }
                  else {
                    if (cVar4 == 'L') {
LAB_68125ace:
                      *(undefined4 *)(iVar3 + -8 + iVar6 * 8) = 6;
                      goto LAB_68125ad6;
                    }
                    if (cVar4 == 'l') {
                      *(undefined4 *)(iVar3 + -8 + iVar6 * 8) = 4;
                      cVar4 = *pcVar7;
                      pcVar7 = pcVar7 + 1;
                      if (cVar4 == 'l') goto LAB_68125ace;
                    }
                  }
                  switch(cVar4) {
                  default:
                    *(undefined4 *)(iVar3 + -8 + iVar6 * 8) = 0x14;
                    break;
                  case 'X':
                  case 'c':
                  case 'd':
                  case 'i':
                  case 'o':
                  case 'u':
                  case 'x':
                    break;
                  case 'e':
                  case 'f':
                  case 'g':
                    *(undefined4 *)(iVar3 + -8 + iVar6 * 8) = 9;
                    break;
                  case 'n':
                    *(undefined4 *)(iVar3 + -8 + iVar6 * 8) = 10;
                    break;
                  case 'p':
                    *(undefined4 *)(iVar3 + -8 + iVar6 * 8) = 5;
                    break;
                  case 's':
                    *(undefined4 *)(iVar3 + -8 + iVar6 * 8) = 8;
                  }
                  if (*(int *)(iVar3 + -8 + iVar6 * 8) != 0x14) goto LAB_68125b29;
                }
                *param_2 = -1;
                goto LAB_68125b3b;
              }
            }
LAB_68125a36:
            *param_2 = -1;
            goto LAB_68125b3b;
          }
        }
LAB_68125b29:
        unaff_EDI = pcVar7;
        cVar4 = *pcVar7;
      }
      if (-1 < *param_2) {
        iVar6 = 0;
        if (iVar8 < 1) {
          return iVar3;
        }
        do {
          iVar1 = *(int *)(iVar3 + iVar6 * 8);
          if (iVar1 != 0x14) {
            *(int *)(iVar3 + 4 + iVar6 * 8) = param_1;
            switch(iVar1) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 8:
            case 10:
              param_1 = param_1 + 4;
              break;
            case 6:
            case 7:
            case 9:
              param_1 = param_1 + 8;
              break;
            default:
              if (iVar3 != param_3) {
                js_freeHandle();
              }
LAB_68125b98:
              *param_2 = -1;
              return 0;
            }
          }
          iVar6 = iVar6 + 1;
          if (iVar8 <= iVar6) {
            return iVar3;
          }
        } while( true );
      }
LAB_68125b3b:
      if (iVar3 != param_3) {
        js_freeHandle();
        return 0;
      }
    }
  }
  return 0;
}



