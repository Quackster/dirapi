// Module: javascript
// Topic: RegExp object - pattern parsing, compilation, matching, flags
// Address range: 0x68130010 - 0x681314b0
// Functions (26):

//   javascript_regexpSetInput
//   javascript_regexpFinalize
//   javascript_regexpMark
//   javascript_regexpGetProperty
//   javascript_regexpSetProperty
//   javascript_regexpFreeData
//   javascript_regexpShareData
//   javascript_regexpToSource
//   javascript_regexpGetIndex
//   js_regexpExec
//   javascript_parseRegexQuantifier
//   javascript_regexpExecCore
//   javascript_regexpExecNoResult
//   javascript_regexpTest
//   javascript_parseRegexAssertion
//   javascript_regexpExecOnSelf
//   javascript_parseRegexSequence
//   javascript_parseRegexAlternation
//   js_mathRandom
//   javascript_compileRegexWithFlags
//   javascript_serializeRegex
//   javascript_regexpCompile
//   javascript_regexpConstruct
//   javascript_initRegExpClass
//   javascript_createRegexpFromString
//   javascript_mathAbs

// ============================================================
// Function: javascript_regexpSetInput (FUN_68130010)
// Address: 68130010
// Size: 135 bytes
// Params: ushort * param_1, int * param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_regexpSetInput(ushort *param_1,int *param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar3;
  double local_c;
  
  uVar1 = 1;
  if ((((param_3 & 1) != 0) && (param_3 != 0x80000001)) && ((param_3 & 0xfffffffe) == 0xfffffff8)) {
    iVar2 = runtime_parseNumber(param_1,*param_4,&local_c);
    if (iVar2 != 0) {
      fVar3 = runtime_powFloat(SUB84(local_c,0),(uint)((ulonglong)local_c >> 0x20));
      local_c = (double)fVar3;
      iVar2 = runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84((double)fVar3,0),
                           (uint)((ulonglong)(double)fVar3 >> 0x20),param_4);
      if ((iVar2 != 0) && (iVar2 = xtra_setScriptProperty(param_1,param_2,0,*param_4), iVar2 != 0)) {
        return 1;
      }
    }
    uVar1 = 0;
  }
  return uVar1;
}



// ============================================================
// Function: javascript_regexpFinalize (FUN_681300a0)
// Address: 681300a0
// Size: 33 bytes
// Params: int param_1, uint param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_regexpFinalize(int param_1,uint param_2)
{
  xtra_initScriptState(param_1);
  js_internAtom(param_1,param_2,0x6817eb6c);
  return 0;
}



// ============================================================
// Function: javascript_regexpMark (FUN_681300d0)
// Address: 681300d0
// Size: 48 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_regexpMark(int param_1,int param_2)
{
  if (*(int *)(param_2 + 0x58) != 0) {
    xtra_checkAndFlush(param_1,*(int *)(param_2 + 0x58));
    *(undefined4 *)(param_2 + 0x58) = 0;
  }
  js_markAtom(*(int *)(param_1 + 0x14),param_2);
  return 0;
}



// ============================================================
// Function: javascript_regexpGetProperty (FUN_68130100)
// Address: 68130100
// Size: 219 bytes
// Params: int param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_regexpGetProperty(int param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  uint uVar1;
  uint *puVar2;
  
  if ((param_3 & 1) == 0) {
    return 1;
  }
  if (param_3 == 0x80000001) {
    return 1;
  }
  uVar1 = (int)param_3 >> 1;
  switch(uVar1) {
  case 0xfffffffa:
    puVar2 = (uint *)(param_1 + 0x128);
    break;
  case 0xfffffffb:
    puVar2 = (uint *)(param_1 + 0x120);
    break;
  case 0xfffffffc:
    puVar2 = (uint *)(param_1 + 0x118);
    break;
  case 0xfffffffd:
    puVar2 = (uint *)(param_1 + 0x110);
    break;
  case 0xfffffffe:
    *param_4 = *(int *)(param_1 + 0xb8) * 8 | 6;
    return 1;
  case 0xffffffff:
    puVar2 = *(uint **)(param_1 + 0xb4);
    if (puVar2 == (uint *)0x0) {
      uVar1 = xtraRuntime_getCapabilitiesHi(param_1);
      *param_4 = uVar1;
      return 1;
    }
    goto LAB_681301ca;
  default:
    if (uVar1 < *(uint *)(param_1 + 0xbc)) {
      if (uVar1 < 9) {
        puVar2 = (uint *)(param_1 + 0xc4 + uVar1 * 8);
      }
      else {
        puVar2 = (uint *)(*(int *)(param_1 + 0x10c) + -0x48 + uVar1 * 8);
      }
    }
    else {
      puVar2 = &DAT_681948f8;
    }
  }
  puVar2 = certs_allocFromPool(param_1,(void *)puVar2[1],*puVar2,0);
  if (puVar2 == (uint *)0x0) {
    return 0;
  }
LAB_681301ca:
  *param_4 = (uint)puVar2 | 4;
  return 1;
}



// ============================================================
// Function: javascript_regexpSetProperty (FUN_68130200)
// Address: 68130200
// Size: 157 bytes
// Params: ushort * param_1, undefined4 param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_regexpSetProperty(ushort *param_1,undefined4 param_2,uint param_3,uint *param_4)

{
  int iVar1;
  
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    return 1;
  }
  if ((int)param_3 >> 1 != -1) {
    if ((int)param_3 >> 1 == -2) {
      if ((((byte)*param_4 & 7) != 6) &&
         (iVar1 = xtra_convertValue(param_1,*param_4,5,param_4), iVar1 == 0)) {
        return 0;
      }
      *(int *)(param_1 + 0x5c) = (int)*param_4 >> 3;
    }
    return 1;
  }
  if ((((byte)*param_4 & 7) != 4) && (iVar1 = xtra_convertValue(param_1,*param_4,3,param_4), iVar1 == 0))
  {
    return 0;
  }
  *(uint *)(param_1 + 0x5a) = *param_4 & 0xfffffff8;
  return 1;
}



// ============================================================
// Function: javascript_regexpFreeData (FUN_681302a0)
// Address: 681302a0
// Size: 33 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_regexpFreeData(undefined4 param_1,int param_2)
{
  int *piVar1;
  
  piVar1 = (int *)xtra_getObjectTag(param_1,param_2);
  if (piVar1 != (int *)0x0) {
    runtime_regexBacktrack(param_1,piVar1);
  }
  return 0;
}



// ============================================================
// Function: javascript_regexpShareData (FUN_681302d0)
// Address: 681302d0
// Size: 47 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_regexpShareData(undefined4 param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = xtra_getObjectTag(param_1,param_2);
  if (uVar1 != 0) {
    xtraRuntime_lookupAtom(param_1,*(uint *)(uVar1 + 0xc));
  }
  return 0;
}



// ============================================================
// Function: javascript_regexpToSource (FUN_68130300)
// Address: 68130300
// Size: 375 bytes
// Params: int param_1, int param_2, undefined4 param_3, int param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_regexpToSource(int param_1,int param_2,undefined4 param_3,int param_4,uint *param_5)

{
  uint uVar1;
  uint *puVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  undefined2 *puVar7;
  void *_Src;
  uint *puVar8;
  uint uVar9;
  
  iVar4 = xtra_callMethod(param_1,param_2,&PTR_s_RegExp_68193210,param_4);
  if (iVar4 == 0) {
    return 0;
  }
  uVar5 = xtra_getObjectTag(param_1,param_2);
  if (uVar5 == 0) {
    *param_5 = *(uint *)(*(int *)(param_1 + 0x14) + 0x1dc) | 4;
    return 1;
  }
  uVar6 = **(uint **)(uVar5 + 0xc);
  if ((uVar6 & 0x40000000) != 0) {
    uVar6 = (-(uint)((uVar6 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar6;
  }
  uVar9 = uVar6 + 2;
  iVar4 = 0;
  for (bVar3 = *(byte *)(uVar5 + 7); bVar3 != 0; bVar3 = bVar3 & bVar3 - 1) {
    iVar4 = iVar4 + 1;
  }
  puVar7 = (undefined2 *)xtra_getPropertyById(param_1,(iVar4 + uVar9) * 2 + 2);
  if (puVar7 != (undefined2 *)0x0) {
    *puVar7 = 0x2f;
    puVar8 = *(uint **)(uVar5 + 0xc);
    uVar1 = *puVar8;
    if ((uVar1 & 0x40000000) == 0) {
      _Src = (void *)puVar8[1];
    }
    else {
      puVar2 = (uint *)puVar8[1];
      if ((*puVar2 & 0x40000000) == 0) {
        if ((int)uVar1 < 0) {
          _Src = (void *)puVar2[1];
        }
        else {
          _Src = (void *)(puVar2[1] + (uVar1 >> 0xf & 0x7fff) * 2);
        }
      }
      else {
        _Src = (void *)crypto_getStringLen(puVar8);
      }
    }
    memcpy(puVar7 + 1,_Src,(uVar6 - 2) + uVar9);
    puVar7[uVar6 + 1] = 0x2f;
    if (iVar4 != 0) {
      if ((*(byte *)(uVar5 + 7) & 2) != 0) {
        puVar7[uVar9] = 0x67;
        uVar9 = uVar6 + 3;
      }
      if ((*(byte *)(uVar5 + 7) & 1) != 0) {
        puVar7[uVar9] = 0x69;
        uVar9 = uVar9 + 1;
      }
      if ((*(byte *)(uVar5 + 7) & 4) != 0) {
        puVar7[uVar9] = 0x6d;
        uVar9 = uVar9 + 1;
      }
    }
    puVar7[uVar9] = 0;
    puVar8 = certs_allocHashEntry(param_1,(uint)puVar7,uVar9,0);
    if (puVar8 != (uint *)0x0) {
      *param_5 = (uint)puVar8 | 4;
      return 1;
    }
    xtra_checkAndFlush(param_1,(int)puVar7);
  }
  return 0;
}



// ============================================================
// Function: javascript_regexpGetIndex (FUN_68130480)
// Address: 68130480
// Size: 62 bytes
// Params: ushort * param_1, int * param_2, double * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_regexpGetIndex(ushort *param_1,int *param_2,double *param_3)

{
  int iVar1;
  
  iVar1 = xtra_getScriptProperty(param_1,param_2,0,&param_2);
  if (iVar1 != 0) {
    iVar1 = runtime_parseNumber(param_1,(uint)param_2,param_3);
    if (iVar1 != 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: js_regexpExec (FUN_681304c0)
// Address: 681304c0
// Size: 67 bytes
// Params: undefined4 param_1, undefined4 param_2, uint param_3, int * param_4, undefined8 param_5
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
js_regexpExec(undefined4 param_1,undefined4 param_2,uint param_3,int *param_4,undefined8 param_5)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = param_3;
  iVar2 = runtime_convertToNumber(param_1,param_2,param_3,(int)param_5,(uint)((ulonglong)param_5 >> 0x20),
                       &param_3);
  if (iVar2 != 0) {
    iVar2 = xtra_setScriptProperty(uVar1,param_4,0,param_3);
    if (iVar2 != 0) {
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: javascript_parseRegexQuantifier (FUN_68130510)
// Address: 68130510
// Size: 697 bytes
// Params: int * param_1
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * javascript_parseRegexQuantifier(int *param_1)

{
  ushort uVar1;
  char *pcVar2;
  int iVar3;
  uint uVar4;
  ushort *puVar5;
  ushort *puVar6;
  uint uVar7;
  undefined1 uVar8;
  undefined4 uVar9;
  char *local_8;
  
  pcVar2 = runtime_parseRegexAtom(param_1);
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  puVar6 = (ushort *)param_1[4];
  local_8 = pcVar2;
  if (puVar6 < (ushort *)param_1[3]) {
    do {
      pcVar2 = local_8;
      switch(*puVar6) {
      case 0x2a:
        uVar8 = 7;
        goto LAB_68130713;
      case 0x2b:
        puVar6 = puVar6 + 1;
        pcVar2 = runtime_allocStringBuffer(8,local_8);
        if (pcVar2 == (char *)0x0) {
          return (char *)0x0;
        }
        if ((local_8[1] & 4U) != 0) {
          pcVar2[1] = pcVar2[1] | 4;
        }
        break;
      default:
        goto switchD_68130556_caseD_2c;
      case 0x3f:
        uVar8 = 9;
LAB_68130713:
        puVar6 = puVar6 + 1;
        pcVar2 = runtime_allocStringBuffer(uVar8,local_8);
        break;
      case 0x7b:
        uVar1 = puVar6[1];
        if ((0x7f < uVar1) || (iVar3 = isdigit((uint)uVar1), iVar3 == 0)) {
          strings_scanToken((uint *)*param_1,param_1[1],0,0,0x2e);
          return (char *)0x0;
        }
        puVar5 = puVar6 + 2;
        uVar4 = uVar1 - 0x30;
        uVar1 = puVar6[2];
        while (uVar1 < 0x80) {
          iVar3 = isdigit((uint)uVar1);
          if (iVar3 == 0) break;
          uVar4 = (uVar1 - 0x30) + uVar4 * 10;
          if ((uVar4 & 0xffff0000) != 0) {
            uVar9 = 0x2f;
            goto LAB_6813067d;
          }
          puVar6 = puVar5 + 1;
          puVar5 = puVar5 + 1;
          uVar1 = *puVar6;
        }
        if (*puVar5 == 0x2c) {
          if ((puVar5[1] < 0x80) && (iVar3 = isdigit((uint)puVar5[1]), iVar3 != 0)) {
            puVar6 = puVar5 + 2;
            uVar7 = puVar5[1] - 0x30;
            uVar1 = puVar5[2];
            while (uVar1 < 0x80) {
              iVar3 = isdigit((uint)uVar1);
              if (iVar3 == 0) break;
              uVar7 = (uVar1 - 0x30) + uVar7 * 10;
              if ((uVar7 & 0xffff0000) != 0) {
                uVar9 = 0x30;
                goto LAB_6813067d;
              }
              puVar5 = puVar6 + 1;
              puVar6 = puVar6 + 1;
              uVar1 = *puVar5;
            }
            if (uVar7 == 0) goto LAB_68130763;
            puVar5 = puVar6;
            if (uVar7 < uVar4) {
              uVar9 = 0x31;
LAB_6813067d:
              strings_scanToken((uint *)*param_1,param_1[1],0,0,uVar9);
              return (char *)0x0;
            }
          }
          else {
            puVar5 = puVar5 + 1;
            uVar7 = 0;
          }
        }
        else {
          uVar7 = uVar4;
          if (uVar4 == 0) {
LAB_68130763:
            strings_scanToken((uint *)*param_1,param_1[1],0,0,0x32);
            return (char *)0x0;
          }
        }
        if (*puVar5 != 0x7d) {
          strings_scanToken((uint *)*param_1,param_1[1],0,0,0x33);
          return (char *)0x0;
        }
        puVar6 = puVar5 + 1;
        pcVar2 = runtime_allocStringBuffer(6,local_8);
        if (pcVar2 == (char *)0x0) {
          return (char *)0x0;
        }
        if ((uVar4 != 0) && ((local_8[1] & 4U) != 0)) {
          pcVar2[1] = pcVar2[1] | 4;
        }
        *(short *)(pcVar2 + 0xe) = (short)uVar7;
        *(short *)(pcVar2 + 0xc) = (short)uVar4;
      }
      if (*puVar6 == 0x3f) {
        pcVar2[1] = pcVar2[1] | 0x80;
        puVar6 = puVar6 + 1;
      }
      local_8 = pcVar2;
    } while (puVar6 < (ushort *)param_1[3]);
  }
switchD_68130556_caseD_2c:
  param_1[4] = (int)puVar6;
  return pcVar2;
}



// ============================================================
// Function: javascript_regexpExecCore (FUN_68130840)
// Address: 68130840
// Size: 523 bytes
// Params: int * param_1, int param_2, uint * param_3, int param_4, int * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int javascript_regexpExecCore(int *param_1,int param_2,uint *param_3,int param_4,int *param_5)

{
  double dVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint *extraout_EDX;
  uint *extraout_EDX_00;
  uint *puVar5;
  ushort *unaff_EDI;
  uint *local_14;
  double local_c;
  
  iVar2 = xtra_callMethod(unaff_EDI,(int)param_1,&PTR_s_RegExp_68193210,(int)param_3);
  if (iVar2 == 0) {
    return 0;
  }
  piVar3 = (int *)xtra_getObjectTag(unaff_EDI,(int)param_1);
  if (piVar3 == (int *)0x0) {
    return 1;
  }
  *piVar3 = *piVar3 + 1;
  if ((*(byte *)((int)piVar3 + 7) & 2) == 0) {
    local_c = 0.0;
    puVar5 = extraout_EDX;
  }
  else {
    iVar2 = javascript_regexpGetIndex(unaff_EDI,param_1,&local_c);
    puVar5 = extraout_EDX_00;
  }
  if (iVar2 != 0) {
    if (param_2 == 0) {
      puVar4 = *(uint **)(unaff_EDI + 0x5a);
      if (puVar4 == (uint *)0x0) {
        xtra_getStringValue((uint *)piVar3[3]);
        xtra_invokeMethod((uint)unaff_EDI,xtra_getErrorString,0,0x3b);
        runtime_regexBacktrack(unaff_EDI,piVar3);
        return 0;
      }
    }
    else {
      puVar4 = (uint *)certs_hashLookup((int)unaff_EDI,*param_3);
      if (puVar4 == (uint *)0x0) goto LAB_68130a3a;
      *param_3 = (uint)puVar4 | 4;
      puVar5 = param_3;
    }
    if (0.0 <= local_c) {
      puVar5 = (uint *)*puVar4;
      param_3 = puVar5;
      if (((uint)puVar5 & 0x40000000) != 0) {
        param_3 = (uint *)((-(uint)(((uint)puVar5 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff &
                          (uint)puVar5);
      }
      dVar1 = (double)(int)param_3;
      if ((int)param_3 < 0) {
        dVar1 = dVar1 + 4294967296.0;
      }
      if (local_c <= dVar1) {
        local_14 = (uint *)(longlong)ROUND(local_c);
        param_3 = local_14;
        iVar2 = runtime_execRegex(unaff_EDI,(int)piVar3,puVar4,(uint *)&param_3,param_4,param_5);
        if ((iVar2 != 0) && ((*(byte *)((int)piVar3 + 7) & 2) != 0)) {
          param_3 = (uint *)(-(uint)(*param_5 != 0) & (uint)param_3);
          dVar1 = (double)(int)param_3;
          if ((int)param_3 < 0) {
            dVar1 = dVar1 + 4294967296.0;
          }
          iVar2 = js_regexpExec(param_3,param_1,(uint)unaff_EDI,param_1,dVar1);
          runtime_regexBacktrack(unaff_EDI,piVar3);
          return iVar2;
        }
        goto LAB_68130a3a;
      }
    }
    iVar2 = js_regexpExec(puVar4,puVar5,(uint)unaff_EDI,param_1,0);
    *param_5 = 0;
    runtime_regexBacktrack(unaff_EDI,piVar3);
    return iVar2;
  }
LAB_68130a3a:
  runtime_regexBacktrack(unaff_EDI,piVar3);
  return iVar2;
}



// ============================================================
// Function: javascript_regexpExecNoResult (FUN_68130a50)
// Address: 68130a50
// Size: 35 bytes
// Params: undefined4 param_1, int * param_2, int param_3, uint * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_regexpExecNoResult(undefined4 param_1,int *param_2,int param_3,uint *param_4,int *param_5)
{
  javascript_regexpExecCore(param_2,param_3,param_4,0,param_5);
  return 0;
}



// ============================================================
// Function: javascript_regexpTest (FUN_68130a80)
// Address: 68130a80
// Size: 63 bytes
// Params: undefined4 param_1, int * param_2, int param_3, uint * param_4, int * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_regexpTest(undefined4 param_1,int *param_2,int param_3,uint *param_4,int *param_5)

{
  int iVar1;
  
  iVar1 = javascript_regexpExecCore(param_2,param_3,param_4,1,param_5);
  if (iVar1 == 0) {
    return 0;
  }
  if (*param_5 != 0xe) {
    *param_5 = 6;
  }
  return 1;
}



// ============================================================
// Function: javascript_parseRegexAssertion (FUN_68130ac0)
// Address: 68130ac0
// Size: 189 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_parseRegexAssertion(void)
{
  short sVar1;
  short *psVar2;
  int *in_EAX;
  undefined1 *puVar3;
  undefined1 uVar4;
  
  psVar2 = (short *)in_EAX[4];
  if (psVar2 < (short *)in_EAX[3]) {
    sVar1 = *psVar2;
    if (sVar1 == 0x24) {
      in_EAX[4] = (int)(psVar2 + 1);
      if ((psVar2 != (short *)in_EAX[2]) &&
         (((psVar2[-1] != 0x28 && (psVar2[-1] != 0x7c)) ||
          ((psVar2 + -1 != (short *)in_EAX[2] && (psVar2[-2] == 0x5c)))))) {
        runtime_allocStringBuffer(3,0);
        return 0;
      }
      runtime_allocStringBuffer(0x1a,0);
      return 0;
    }
    if (sVar1 == 0x5c) {
      if (psVar2[1] == 0x42) {
        uVar4 = 5;
      }
      else {
        if (psVar2[1] != 0x62) goto LAB_68130b76;
        uVar4 = 4;
      }
      in_EAX[4] = (int)(psVar2 + 2);
      puVar3 = runtime_allocStringBuffer(uVar4,0);
      if (puVar3 == (undefined1 *)0x0) {
        return 0;
      }
      puVar3[1] = puVar3[1] | 4;
      return 0;
    }
    if (sVar1 == 0x5e) {
      in_EAX[4] = (int)(psVar2 + 1);
      puVar3 = runtime_allocStringBuffer(2,0);
      if (puVar3 == (undefined1 *)0x0) {
        return 0;
      }
      puVar3[1] = puVar3[1] | 1;
      return 0;
    }
  }
LAB_68130b76:
  javascript_parseRegexQuantifier(in_EAX);
  return 0;
}



// ============================================================
// Function: javascript_regexpExecOnSelf (FUN_68130b80)
// Address: 68130b80
// Size: 35 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3, uint * param_4, int * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_regexpExecOnSelf(undefined4 param_1,undefined4 param_2,int param_3,uint *param_4,int *param_5)
{
  javascript_regexpExecNoResult(param_1,(int *)(param_4[-2] & 0xfffffff8),param_3,param_4,param_5);
  return 0;
}



// ============================================================
// Function: javascript_parseRegexSequence (FUN_68130bb0)
// Address: 68130bb0
// Size: 130 bytes
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * javascript_parseRegexSequence(void)

{
  byte bVar1;
  char *pcVar2;
  short *psVar3;
  char *pcVar4;
  int iVar5;
  char *pcVar6;
  int unaff_EDI;
  
  pcVar2 = (char *)javascript_parseRegexAssertion();
  if (pcVar2 == (char *)0x0) {
    return (char *)0x0;
  }
  psVar3 = *(short **)(unaff_EDI + 0x10);
  bVar1 = 0;
  pcVar6 = pcVar2;
  if (psVar3 < *(short **)(unaff_EDI + 0xc)) {
    do {
      if ((*psVar3 == 0x7c) || (*psVar3 == 0x29)) break;
      pcVar4 = (char *)javascript_parseRegexAssertion();
      if ((pcVar4 == (char *)0x0) || (iVar5 = runtime_parseStringToInt(pcVar6,unaff_EDI), iVar5 == 0)) {
        return (char *)0x0;
      }
      bVar1 = bVar1 | pcVar4[1];
      psVar3 = *(short **)(unaff_EDI + 0x10);
      pcVar6 = pcVar4;
    } while (psVar3 < *(short **)(unaff_EDI + 0xc));
  }
  pcVar2[1] = pcVar2[1] | bVar1 & 4;
  return pcVar2;
}



// ============================================================
// Function: javascript_parseRegexAlternation (FUN_68130c40)
// Address: 68130c40
// Size: 202 bytes
// Params: int param_1
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * javascript_parseRegexAlternation(int param_1)

{
  char *pcVar1;
  char *pcVar2;
  char *pcVar3;
  char *pcVar4;
  short *psVar5;
  
  pcVar1 = javascript_parseRegexSequence();
  if (pcVar1 == (char *)0x0) {
    return (char *)0x0;
  }
  psVar5 = *(short **)(param_1 + 0x10);
  pcVar2 = pcVar1;
  if ((psVar5 < *(short **)(param_1 + 0xc)) && (*psVar5 == 0x7c)) {
    pcVar2 = runtime_allocStringBuffer(1,pcVar1);
    if (pcVar2 == (char *)0x0) {
      return (char *)0x0;
    }
    pcVar2[1] = pcVar1[1] & 5;
    pcVar1 = pcVar2;
    do {
      psVar5 = psVar5 + 1;
      *(short **)(param_1 + 0x10) = psVar5;
      if ((*psVar5 == 0x7c) || (*psVar5 == 0x29)) {
        pcVar3 = runtime_allocStringBuffer(0,0);
      }
      else {
        pcVar3 = javascript_parseRegexSequence();
        psVar5 = *(short **)(param_1 + 0x10);
      }
      if (pcVar3 == (char *)0x0) {
        return (char *)0x0;
      }
      pcVar4 = runtime_allocStringBuffer(1,pcVar3);
      if (pcVar4 == (char *)0x0) {
        return (char *)0x0;
      }
      pcVar1[1] = pcVar1[1] | 0x10;
      *(char **)(pcVar1 + 4) = pcVar4;
      pcVar4[1] = pcVar3[1] & 5U | 8;
    } while ((psVar5 < *(short **)(param_1 + 0xc)) && (pcVar1 = pcVar4, *psVar5 == 0x7c));
  }
  return pcVar2;
}



// ============================================================
// Function: js_mathRandom (FUN_68130d10)
// Address: 68130d10
// Size: 539 bytes
// Params: int param_1, undefined4 param_2, uint * param_3, undefined4 param_4, int param_5
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 *
js_mathRandom(int param_1,undefined4 param_2,uint *param_3,undefined4 param_4,int param_5)

{
  uint *puVar1;
  int *piVar2;
  undefined2 *puVar3;
  char *pcVar4;
  int iVar5;
  undefined1 *puVar6;
  uint uVar7;
  char *pcVar8;
  uint uVar9;
  int local_2c;
  undefined4 local_28;
  undefined2 *local_24;
  undefined2 *local_20;
  undefined2 *local_1c;
  undefined4 local_18;
  uint local_14;
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  local_c = *(int *)(*(int *)(param_1 + 0x80) + 0xc);
  local_2c = param_1;
  local_28 = param_2;
  uVar9 = *param_3;
  local_8 = (undefined4 *)0x0;
  if ((uVar9 & 0x40000000) == 0) {
    puVar3 = (undefined2 *)param_3[1];
  }
  else {
    puVar1 = (uint *)param_3[1];
    if ((*puVar1 & 0x40000000) == 0) {
      if ((int)uVar9 < 0) {
        puVar3 = (undefined2 *)puVar1[1];
      }
      else {
        puVar3 = (undefined2 *)(puVar1[1] + (uVar9 >> 0xf & 0x7fff) * 2);
      }
    }
    else {
      puVar3 = (undefined2 *)crypto_getStringLen(param_3);
    }
  }
  uVar9 = *param_3;
  uVar7 = uVar9;
  if ((uVar9 & 0x40000000) != 0) {
    uVar7 = (-(uint)((uVar9 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar9;
  }
  local_20 = puVar3 + uVar7;
  local_18 = param_4;
  local_14 = 0;
  local_10 = 0;
  if ((uVar9 & 0x40000000) != 0) {
    uVar9 = (-(uint)((uVar9 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar9;
  }
  local_24 = puVar3;
  local_1c = puVar3;
  if ((uVar9 == 0) || (param_5 == 0)) {
    pcVar4 = javascript_parseRegexAlternation((int)&local_2c);
  }
  else {
    pcVar8 = (char *)0x0;
    do {
      pcVar4 = runtime_allocStringBuffer('\x16' - (uVar9 != 1),puVar3);
      if (pcVar4 == (char *)0x0) goto LAB_68130e4d;
      pcVar4[1] = '\x04';
      if (uVar9 < 2) {
        pcVar4[1] = '\x06';
        *(undefined2 *)(pcVar4 + 0xc) = *puVar3;
        uVar9 = 0;
      }
      else if (uVar9 < 0x100) {
        puVar3 = puVar3 + uVar9;
        uVar9 = 0;
        *(undefined2 **)(pcVar4 + 0xc) = puVar3;
      }
      else {
        puVar3 = puVar3 + 0xff;
        uVar9 = uVar9 - 0xff;
        *(undefined2 **)(pcVar4 + 0xc) = puVar3;
      }
      if ((pcVar8 != (char *)0x0) &&
         (iVar5 = runtime_parseStringToInt(pcVar8,&local_2c), pcVar4 = pcVar8, iVar5 == 0)) goto LAB_68130e4d;
      pcVar8 = pcVar4;
    } while (uVar9 != 0);
  }
  if ((((pcVar4 != (char *)0x0) && (puVar6 = runtime_allocStringBuffer(0x2b,0), puVar6 != (undefined1 *)0x0)) &&
      (iVar5 = runtime_parseStringToInt(pcVar4,&local_2c), iVar5 != 0)) &&
     (local_8 = (undefined4 *)xtra_getPropertyById(param_1,local_10 + 0x12U & 0xfffffffc),
     local_8 != (undefined4 *)0x0)) {
    *local_8 = 1;
    local_8[3] = param_3;
    local_8[1] = local_8[1] ^ (local_8[1] ^ local_14) & 0xffffff;
    *(undefined1 *)((int)local_8 + 7) = (undefined1)param_4;
    local_8[2] = pcVar4;
  }
LAB_68130e4d:
  piVar2 = *(int **)(param_1 + 0x80);
  if ((piVar2 != (int *)(param_1 + 0x70)) &&
     ((uint)(local_c - piVar2[1]) <= (uint)(piVar2[3] - piVar2[1]))) {
    piVar2[3] = local_c + *(uint *)(param_1 + 0x88) & ~*(uint *)(param_1 + 0x88);
    return local_8;
  }
  js_getPrototype((int *)(param_1 + 0x70),local_c);
  return local_8;
}



// ============================================================
// Function: javascript_compileRegexWithFlags (FUN_68130f30)
// Address: 68130f30
// Size: 244 bytes
// Params: uint * param_1, int param_2, uint * param_3, uint * param_4, int param_5
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * javascript_compileRegexWithFlags(uint *param_1,int param_2,uint *param_3,uint *param_4,int param_5)

{
  short sVar1;
  uint *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar6 = 0;
  if (param_4 != (uint *)0x0) {
    uVar3 = *param_4;
    if ((uVar3 & 0x40000000) == 0) {
      uVar3 = param_4[1];
    }
    else {
      puVar2 = (uint *)param_4[1];
      if ((*puVar2 & 0x40000000) == 0) {
        if ((int)uVar3 < 0) {
          uVar3 = puVar2[1];
        }
        else {
          uVar3 = puVar2[1] + (uVar3 >> 0xf & 0x7fff) * 2;
        }
      }
      else {
        uVar3 = crypto_getStringLen(param_4);
      }
    }
    uVar5 = *param_4;
    uVar7 = 0;
    if ((uVar5 & 0x40000000) != 0) {
      uVar5 = (-(uint)((uVar5 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar5;
    }
    if (uVar5 != 0) {
      uVar6 = 0;
      do {
        sVar1 = *(short *)(uVar3 + uVar7 * 2);
        if (sVar1 == 0x67) {
          uVar6 = uVar6 | 2;
        }
        else if (sVar1 == 0x69) {
          uVar6 = uVar6 | 1;
        }
        else {
          if (sVar1 != 0x6d) {
            strings_scanToken(param_1,param_2,0,0,0x3a);
            return (undefined4 *)0x0;
          }
          uVar6 = uVar6 | 4;
        }
        uVar7 = uVar7 + 1;
      } while (uVar7 < uVar5);
    }
  }
  puVar4 = js_mathRandom((int)param_1,param_2,param_3,uVar6,param_5);
  return puVar4;
}



// ============================================================
// Function: javascript_serializeRegex (FUN_68131030)
// Address: 68131030
// Size: 210 bytes
// Params: int * param_1, uint * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_serializeRegex(int *param_1,uint *param_2)

{
  int *piVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  undefined4 extraout_EDX;
  
  puVar2 = param_2;
  piVar1 = param_1;
  if (*param_1 == 0) {
    uVar3 = xtra_getObjectTag(param_1[2],*param_2);
    if (uVar3 == 0) {
      return 0;
    }
    param_2 = *(uint **)(uVar3 + 0xc);
    param_1 = (int *)CONCAT13(*(undefined1 *)(uVar3 + 7),(*(unsigned int *)((char *)&param_1 + 0)));
  }
  iVar4 = runtime_serializeWideString(piVar1,(int *)&param_2);
  if ((iVar4 != 0) && (iVar4 = runtime_serializeByte(piVar1,(byte *)((int)&param_1 + 3)), iVar4 != 0)) {
    if (*piVar1 != 1) {
      return 1;
    }
    piVar5 = runtime_setProperty(piVar1[2],&PTR_s_RegExp_68193210,(undefined4 *)0x0,0);
    *puVar2 = (uint)piVar5;
    if ((piVar5 != (int *)0x0) &&
       (piVar5 = js_mathRandom(piVar1[2],0,param_2,(uint)param_1 >> 0x18,0), piVar5 != (int *)0x0)) {
      iVar4 = xtra_getResourceById(piVar1[2],*puVar2,(uint)piVar5);
      if ((iVar4 != 0) &&
         (iVar4 = js_regexpExec(piVar1[2],extraout_EDX,piVar1[2],(int *)*puVar2,0), iVar4 != 0)) {
        return 1;
      }
      runtime_regexBacktrack(piVar1[2],piVar5);
    }
    return 0;
  }
  return 0;
}



// ============================================================
// Function: javascript_regexpCompile (FUN_68131110)
// Address: 68131110
// Size: 355 bytes
// Params: uint * param_1, int * param_2, uint param_3, uint * param_4, undefined4 * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_regexpCompile(uint *param_1,int *param_2,uint param_3,uint *param_4,undefined4 *param_5)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  int *piVar5;
  int *piVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  uint *puVar7;
  
  iVar1 = xtra_callMethod(param_1,(int)param_2,&PTR_s_RegExp_68193210,(int)param_4);
  if (iVar1 == 0) {
    return 0;
  }
  puVar7 = (uint *)0x0;
  if (param_3 == 0) {
    puVar4 = *(uint **)(param_1[5] + 0x1dc);
  }
  else {
    uVar3 = *param_4;
    if ((((uVar3 & 7) == 0) && (uVar2 = uVar3 & 0xfffffff8, uVar2 != 0)) &&
       ((undefined **)(*(uint *)(*(int *)(uVar2 + 4) + 8) & 0xfffffffe) == &PTR_s_RegExp_68193210))
    {
      if ((1 < param_3) && (param_4[1] != 0x80000001)) {
        xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0xa5);
        return 0;
      }
      uVar3 = xtra_getObjectTag(param_1,uVar2);
      if (uVar3 == 0) {
        return 0;
      }
      piVar5 = js_mathRandom((int)param_1,0,*(uint **)(uVar3 + 0xc),(uint)*(byte *)(uVar3 + 7),0);
      goto LAB_68131206;
    }
    puVar4 = (uint *)certs_hashLookup((int)param_1,uVar3);
    if (puVar4 == (uint *)0x0) {
      return 0;
    }
    *param_4 = (uint)puVar4 | 4;
    if (1 < param_3) {
      if (param_4[1] == 0x80000001) {
        puVar7 = (uint *)0x0;
      }
      else {
        puVar7 = (uint *)certs_hashLookup((int)param_1,param_4[1]);
        if (puVar7 == (uint *)0x0) {
          return 0;
        }
        param_4[1] = (uint)puVar7 | 4;
      }
    }
  }
  piVar5 = javascript_compileRegexWithFlags(param_1,0,puVar4,puVar7,0);
LAB_68131206:
  if (piVar5 == (int *)0x0) {
    return 0;
  }
  piVar6 = (int *)xtra_getObjectTag(param_1,(int)param_2);
  iVar1 = xtra_getResourceById(param_1,(int)param_2,(uint)piVar5);
  if ((iVar1 != 0) &&
     (iVar1 = js_regexpExec(extraout_ECX,extraout_EDX,(uint)param_1,param_2,0), iVar1 != 0)) {
    if (piVar6 != (int *)0x0) {
      runtime_regexBacktrack(param_1,piVar6);
    }
    *param_5 = param_2;
    return 1;
  }
  runtime_regexBacktrack(param_1,piVar5);
  return 0;
}



// ============================================================
// Function: javascript_regexpConstruct (FUN_68131280)
// Address: 68131280
// Size: 132 bytes
// Params: uint * param_1, int * param_2, uint param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 javascript_regexpConstruct(uint *param_1,int *param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((*(byte *)(param_1[0xd] + 0x4c) & 1) == 0) {
    if ((((param_3 < 2) || (param_4[1] == 0x80000001)) && (uVar1 = *param_4, (uVar1 & 7) == 0)) &&
       ((undefined **)(*(uint *)(*(int *)((uVar1 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
        &PTR_s_RegExp_68193210)) {
      *param_5 = uVar1;
      return 1;
    }
    param_2 = runtime_setProperty((int)param_1,&PTR_s_RegExp_68193210,(undefined4 *)0x0,0);
    if (param_2 == (int *)0x0) {
      return 0;
    }
  }
  uVar2 = javascript_regexpCompile(param_1,param_2,param_3,param_4,param_5);
  return uVar2;
}



// ============================================================
// Function: javascript_initRegExpClass (FUN_68131310)
// Address: 68131310
// Size: 261 bytes
// Params: uint * param_1, int * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * javascript_initRegExpClass(uint *param_1,int *param_2)

{
  uint *puVar1;
  bool bVar2;
  int *piVar3;
  int *piVar4;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  int iVar5;
  
  puVar1 = param_1;
  piVar3 = xtra_createScriptObject((int)param_1,param_2,(undefined4 *)0x0,&PTR_s_RegExp_68193210,0x68131280,1,
                        (int *)&PTR_s_source_681930b0,(int *)&PTR_s_toSource_68193258,
                        (int *)&PTR_s_input_68193110,(int *)0x0);
  if (piVar3 != (int *)0x0) {
    piVar4 = (int *)xtra_lookupConstructor((uint)puVar1,piVar3);
    if (piVar4 != (int *)0x0) {
      bVar2 = xtra_matchMethodName((uint)puVar1,piVar4,"input","$_");
      if (CONCAT31(extraout_var,bVar2) != 0) {
        bVar2 = xtra_matchMethodName((uint)puVar1,piVar4,"multiline","$*");
        if (CONCAT31(extraout_var_00,bVar2) != 0) {
          bVar2 = xtra_matchMethodName((uint)puVar1,piVar4,"lastMatch","$&");
          if (CONCAT31(extraout_var_01,bVar2) != 0) {
            bVar2 = xtra_matchMethodName((uint)puVar1,piVar4,"lastParen","$+");
            if (CONCAT31(extraout_var_02,bVar2) != 0) {
              bVar2 = xtra_matchMethodName((uint)puVar1,piVar4,"leftContext","$`");
              if (CONCAT31(extraout_var_03,bVar2) != 0) {
                bVar2 = xtra_matchMethodName((uint)puVar1,piVar4,"rightContext","$\'");
                if (CONCAT31(extraout_var_04,bVar2) != 0) {
                  iVar5 = javascript_regexpCompile(puVar1,piVar3,0,(uint *)0x0,&param_1);
                  if (iVar5 != 0) {
                    return piVar3;
                  }
                }
              }
            }
          }
        }
      }
      xtra_registerNamedMethod((int)puVar1,param_2,PTR_s_RegExp_68193210);
    }
  }
  return (int *)0x0;
}



// ============================================================
// Function: javascript_createRegexpFromString (FUN_68131420)
// Address: 68131420
// Size: 140 bytes
// Params: uint param_1, undefined4 param_2, void * param_3, uint param_4, undefined4 param_5
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * javascript_createRegexpFromString(uint param_1,undefined4 param_2,void *param_3,uint param_4,undefined4 param_5)

{
  uint *puVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  
  puVar1 = certs_allocFromPool(param_1,param_3,param_4,0);
  if (puVar1 == (uint *)0x0) {
    return (int *)0x0;
  }
  piVar2 = js_mathRandom(param_1,param_2,puVar1,param_5,0);
  if (piVar2 == (int *)0x0) {
    return (int *)0x0;
  }
  piVar3 = runtime_setProperty(param_1,&PTR_s_RegExp_68193210,(undefined4 *)0x0,0);
  if (piVar3 != (int *)0x0) {
    iVar4 = xtra_getResourceById(param_1,(int)piVar3,(uint)piVar2);
    if (iVar4 != 0) {
      iVar4 = js_regexpExec(extraout_ECX,extraout_EDX,param_1,piVar3,0);
      if (iVar4 != 0) {
        return piVar3;
      }
    }
  }
  runtime_regexBacktrack(param_1,piVar2);
  return (int *)0x0;
}



// ============================================================
// Function: javascript_mathAbs (FUN_681314b0)
// Address: 681314b0
// Size: 65 bytes
// Params: ushort * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int javascript_mathAbs(ushort *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  double local_c;
  
  iVar1 = runtime_parseNumber(param_1,*param_4,&local_c);
  if (iVar1 == 0) {
    return 0;
  }
  runtime_convertToNumber(extraout_ECX,extraout_EDX,(int)param_1,SUB84(ABS(local_c),0),
               (uint)((ulonglong)ABS(local_c) >> 0x20),param_5);
  return 0;
}



