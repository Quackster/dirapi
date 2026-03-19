// Module: crypto
// Topic: AST node management, parsing helpers, and constant folding
// Address range: 0x681400A0 - 0x68144530
// Functions (25):
//   crypto_evalExpression
//   crypto_allocObjectWithProtos
//   crypto_evalAssignment
//   crypto_matchOperator
//   crypto_emitLineNumber
//   crypto_advanceParser
//   crypto_allocAstNode
//   crypto_createNode
//   crypto_createBinaryNode
//   crypto_peekToken
//   crypto_consumeToken
//   crypto_getTokenValue
//   crypto_reportLabelError
//   crypto_validateToken
//   crypto_compileExpr
//   crypto_parseFunctionArgs
//   crypto_parseTokenList
//   crypto_resolveAssignTarget
//   crypto_resolveAssignOpcode
//   crypto_parseListTail
//   crypto_parsePostfixExpr
//   crypto_parseStatement
//   crypto_nextToken
//   crypto_foldConstants
//   crypto_parsePrimary

// ============================================================
// Function: crypto_evalExpression (FUN_681400a0)
// Address: 681400a0
// Size: 66 bytes
// Params: uint param_1, int param_2, int param_3, uint param_4
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crypto_evalExpression(uint param_1,int param_2,int param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = js_allocObject(param_1,param_2,param_3);
  if (-1 < (int)uVar1) {
    iVar2 = js_allocObjectWithProto(param_1,param_2,uVar1,0,param_4);
    if (iVar2 == 0) {
      return 0xffffffff;
    }
  }
  return uVar1;
}



// ============================================================
// Function: crypto_allocObjectWithProtos (FUN_681400f0)
// Address: 681400f0
// Size: 84 bytes
// Params: uint param_1, int param_2, int param_3, uint param_4, uint param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crypto_allocObjectWithProtos(uint param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = js_allocObject(param_1,param_2,param_3);
  if ((int)uVar1 < 0) {
    return uVar1;
  }
  iVar2 = js_allocObjectWithProto(param_1,param_2,uVar1,0,param_4);
  if ((iVar2 != 0) && (iVar2 = js_allocObjectWithProto(param_1,param_2,uVar1,1,param_5), iVar2 != 0)) {
    return uVar1;
  }
  return 0xffffffff;
}



// ============================================================
// Function: crypto_evalAssignment (FUN_68140150)
// Address: 68140150
// Size: 422 bytes
// Params: uint param_1, int * param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool crypto_evalAssignment(uint param_1,int *param_2,int param_3)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  undefined4 *puVar6;
  uint *unaff_EBX;
  int *piVar7;
  int *piVar8;
  
  piVar1 = (int *)param_2[7];
  if (((param_3 == 0x35) && (*param_2 == 0x16)) && (*piVar1 == 0x1d)) {
    iVar3 = js_getPropertyDescriptor(param_1,unaff_EBX);
    if (iVar3 == 0) {
      return false;
    }
    if ((piVar1[3] == 9) && (param_2[6] == *(int *)(*(int *)(param_1 + 0x14) + 0x108))) {
      iVar3 = js_setPropertyFlag(param_1,(int)unaff_EBX,0x89);
      return -1 < iVar3;
    }
  }
  if (*piVar1 == 0x16) {
    iVar4 = ((int *)unaff_EBX[0x10])[2] - *(int *)unaff_EBX[0x10];
    piVar7 = (int *)piVar1[7];
    piVar1[4] = iVar4;
    piVar1[7] = 0;
    iVar3 = *piVar7;
    piVar8 = piVar1;
    while (iVar3 == 0x16) {
      piVar7[4] = iVar4;
      piVar2 = (int *)piVar7[7];
      piVar7[7] = (int)piVar8;
      piVar8 = piVar7;
      piVar7 = piVar2;
      iVar3 = *piVar2;
    }
    iVar3 = crypto_bigEval((uint *)param_1,unaff_EBX,piVar7);
    if (iVar3 == 0) {
      return false;
    }
    do {
      uVar5 = crypto_evalExpression(param_1,(int)unaff_EBX,0xc,
                           (((int *)unaff_EBX[0x10])[2] - piVar7[4]) - *(int *)unaff_EBX[0x10]);
      if ((int)uVar5 < 0) {
        return false;
      }
      puVar6 = js_createAtom(param_1,piVar8[6],unaff_EBX + 0x15);
      if (puVar6 == (undefined4 *)0x0) {
        return false;
      }
      iVar3 = js_setMultipleFlags(param_1,(int)unaff_EBX,(char)piVar8[3],(char)((uint)puVar6[3] >> 8),
                           *(undefined1 *)(puVar6 + 3));
      if (iVar3 < 0) {
        return false;
      }
      piVar2 = (int *)piVar8[7];
      piVar8[7] = (int)piVar7;
      piVar7 = piVar8;
      piVar8 = piVar2;
    } while (piVar2 != (int *)0x0);
  }
  else {
    iVar3 = crypto_bigEval((uint *)param_1,unaff_EBX,piVar1);
    if (iVar3 == 0) {
      return false;
    }
  }
  uVar5 = crypto_evalExpression(param_1,(int)unaff_EBX,0xc,
                       (((int *)unaff_EBX[0x10])[2] - piVar1[4]) - *(int *)unaff_EBX[0x10]);
  if ((int)uVar5 < 0) {
    return false;
  }
  if (param_2[6] == 0) {
    iVar3 = js_setPropertyFlag(param_1,(int)unaff_EBX,(char)param_3);
    if (iVar3 < 0) {
      return false;
    }
  }
  else {
    puVar6 = js_createAtom(param_1,param_2[6],unaff_EBX + 0x15);
    if (puVar6 == (undefined4 *)0x0) {
      return false;
    }
    iVar3 = js_setMultipleFlags(param_1,(int)unaff_EBX,(char)param_3,(char)((uint)puVar6[3] >> 8),
                         *(undefined1 *)(puVar6 + 3));
    if (iVar3 < 0) {
      return false;
    }
  }
  return true;
}



// ============================================================
// Function: crypto_matchOperator (FUN_68140300)
// Address: 68140300
// Size: 628 bytes
// Params: int param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool crypto_matchOperator(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int *extraout_EDX;
  int *piVar4;
  int *extraout_EDX_00;
  int *piVar5;
  uint *unaff_EBX;
  uint *unaff_ESI;
  int *piVar6;
  ulonglong uVar7;
  int *local_c;
  int *local_8;
  
  iVar2 = ((int *)unaff_ESI[0x10])[2] - *(int *)unaff_ESI[0x10];
  piVar6 = *(int **)(param_1 + 0x18);
  if (*(int *)(param_1 + 0x14) == -2) {
    local_c = (int *)(*(int *)(param_1 + 0x1c) + -0x28);
    piVar5 = (int *)piVar6[10];
    local_8 = piVar5;
    if ((*piVar6 == 0x1d) && (*piVar5 == 0x1e)) {
      iVar1 = js_getPropertyDescriptor((uint)unaff_EBX,unaff_ESI);
      if (iVar1 == 0) {
        return false;
      }
      if (piVar6[3] == 9) {
        uVar3 = piVar5[7] & 0x7ff00000;
        if ((uVar3 != 0x7ff00000) &&
           ((piVar4 = extraout_EDX, piVar5[7] != 0x80000000 || (piVar4 = piVar5, piVar5[6] != 0))))
        {
          uVar7 = strings_floatToUint64(uVar3,piVar4);
          if ((*(double *)(piVar5 + 6) == (double)(int)(uint)uVar7) && ((uint)uVar7 < 0x10000)) {
            piVar5[4] = iVar2;
            piVar6[4] = iVar2;
            iVar1 = js_setMultipleFlags(unaff_EBX,(int)unaff_ESI,0x88,(char)(uVar7 >> 8),(char)uVar7);
            if (iVar1 < 0) {
              return false;
            }
            local_8 = (int *)piVar5[10];
            piVar6 = piVar5;
          }
        }
      }
    }
    if ((piVar6 == *(int **)(param_1 + 0x18)) &&
       (iVar1 = crypto_bigEval(unaff_EBX,unaff_ESI,piVar6), iVar1 == 0)) {
      return false;
    }
    for (; local_8 != local_c; local_8 = (int *)local_8[10]) {
      iVar1 = crypto_bigEval(unaff_EBX,unaff_ESI,local_8);
      if (iVar1 == 0) {
        return false;
      }
      uVar3 = crypto_evalExpression((uint)unaff_EBX,(int)unaff_ESI,0xc,
                           (((int *)unaff_ESI[0x10])[2] - *(int *)unaff_ESI[0x10]) - iVar2);
      if ((int)uVar3 < 0) {
        return false;
      }
      iVar1 = js_setPropertyFlag(unaff_EBX,(int)unaff_ESI,0x37);
      if (iVar1 < 0) {
        return false;
      }
    }
  }
  else {
    local_c = *(int **)(param_1 + 0x1c);
    if (((param_2 == 0x37) && (*piVar6 == 0x1d)) && (*local_c == 0x1e)) {
      iVar1 = js_getPropertyDescriptor((uint)unaff_EBX,unaff_ESI);
      if (iVar1 == 0) {
        return false;
      }
      if (piVar6[3] == 9) {
        uVar3 = local_c[7] & 0x7ff00000;
        if ((uVar3 != 0x7ff00000) &&
           ((piVar5 = extraout_EDX_00, local_c[7] != 0x80000000 ||
            (piVar5 = local_c, local_c[6] != 0)))) {
          uVar7 = strings_floatToUint64(uVar3,piVar5);
          if ((*(double *)(local_c + 6) == (double)(int)(uint)uVar7) && ((uint)uVar7 < 0x10000)) {
            local_c[4] = iVar2;
            piVar6[4] = iVar2;
            iVar2 = js_setMultipleFlags(unaff_EBX,(int)unaff_ESI,0x88,(char)(uVar7 >> 8),(char)uVar7);
            return -1 < iVar2;
          }
        }
      }
    }
    iVar1 = crypto_bigEval(unaff_EBX,unaff_ESI,piVar6);
    if (iVar1 == 0) {
      return false;
    }
  }
  iVar1 = crypto_bigEval(unaff_EBX,unaff_ESI,local_c);
  if ((iVar1 != 0) &&
     (uVar3 = crypto_evalExpression((uint)unaff_EBX,(int)unaff_ESI,0xc,
                           (((int *)unaff_ESI[0x10])[2] - *(int *)unaff_ESI[0x10]) - iVar2),
     -1 < (int)uVar3)) {
    iVar2 = js_setPropertyFlag(unaff_EBX,(int)unaff_ESI,(char)param_2);
    return -1 < iVar2;
  }
  return false;
}



// ============================================================
// Function: crypto_emitLineNumber (FUN_68140580)
// Address: 68140580
// Size: 75 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_emitLineNumber(void)

{
  int in_EAX;
  uint uVar1;
  uint unaff_EBX;
  uint uVar2;
  int unaff_EDI;
  
  uVar1 = (uint)*(ushort *)(in_EAX + 6);
  uVar2 = uVar1 - *(int *)(unaff_EDI + 0x4c);
  if (uVar2 != 0) {
    *(uint *)(unaff_EDI + 0x4c) = uVar1;
    if (uVar2 < (uint)(0x7f < uVar1) * 2 + 2) {
      do {
        uVar1 = js_allocObject(unaff_EBX,unaff_EDI,0x16);
        if ((int)uVar1 < 0) {
          return 0;
        }
        uVar2 = uVar2 - 1;
      } while (uVar2 != 0);
    }
    else {
      uVar1 = crypto_evalExpression(unaff_EBX,unaff_EDI,0x17,uVar1);
      if ((int)uVar1 < 0) {
        return 0;
      }
    }
  }
  return 1;
}



// ============================================================
// Function: crypto_advanceParser (FUN_681435c0)
// Address: 681435c0
// Size: 14 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall crypto_advanceParser(int param_1)
{
  int in_EAX;
  
  if (in_EAX != 0) {
    *(undefined4 *)(in_EAX + 0x28) = *(undefined4 *)(param_1 + 0x18);
    *(int *)(param_1 + 0x18) = in_EAX;
  }
  return 0;
}



// ============================================================
// Function: crypto_allocAstNode (FUN_681435d0)
// Address: 681435d0
// Size: 174 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall crypto_allocAstNode(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int unaff_EDI;
  
  iVar4 = *(int *)(param_1 + 0x18);
  if (iVar4 == 0) {
    iVar2 = *(int *)(unaff_EDI + 0x80);
    uVar5 = *(uint *)(unaff_EDI + 0x88) + 0x30 & ~*(uint *)(unaff_EDI + 0x88);
    iVar4 = *(int *)(iVar2 + 0xc);
    uVar1 = iVar4 + uVar5;
    if (*(uint *)(iVar2 + 8) < uVar1) {
      iVar4 = js_getSlotIndex(unaff_EDI + 0x70,uVar5);
    }
    else {
      *(uint *)(iVar2 + 0xc) = uVar1;
    }
    if (iVar4 == 0) {
      xtra_reportError(unaff_EDI);
      return 0;
    }
  }
  else {
    uVar3 = *(undefined4 *)(iVar4 + 0x28);
    *(undefined4 *)(param_1 + 0x18) = uVar3;
    switch(*(undefined4 *)(iVar4 + 0x14)) {
    case 1:
      crypto_advanceParser(param_1);
      return iVar4;
    case 2:
      crypto_advanceParser(param_1);
      param_1 = extraout_ECX_01;
    case 0xfffffffd:
    case 0xffffffff:
      crypto_advanceParser(param_1);
      break;
    case 3:
      crypto_advanceParser(param_1);
      crypto_advanceParser(extraout_ECX);
      crypto_advanceParser(extraout_ECX_00);
      return iVar4;
    case 0xfffffffe:
      if (*(int *)(iVar4 + 0x18) != 0) {
        **(undefined4 **)(iVar4 + 0x1c) = uVar3;
        *(undefined4 *)(param_1 + 0x18) = *(undefined4 *)(iVar4 + 0x18);
        return iVar4;
      }
    }
  }
  return iVar4;
}



// ============================================================
// Function: crypto_createNode (crypto_createNode)
// Address: 681436a0
// Size: 52 bytes
// Params: void * this, undefined4 param_1
// Return: undefined4 *
// Calling convention: __thiscall
// ============================================================

undefined4 * __thiscall crypto_createNode(void *this,undefined4 param_1)

{
  undefined4 *puVar1;
  undefined4 *unaff_ESI;
  
  puVar1 = (undefined4 *)crypto_allocAstNode((int)this);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  *puVar1 = *unaff_ESI;
  puVar1[1] = unaff_ESI[1];
  puVar1[2] = unaff_ESI[2];
  puVar1[3] = 0;
  puVar1[5] = param_1;
  puVar1[10] = 0;
  return puVar1;
}



// ============================================================
// Function: crypto_createBinaryNode (FUN_681436e0)
// Address: 681436e0
// Size: 337 bytes
// Params: void * this, undefined4 param_1, int param_2, int param_3
// Return: int *
// Calling convention: __thiscall
// ============================================================

int * __thiscall crypto_createBinaryNode(void *this,undefined4 param_1,int param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  int *in_EAX;
  int *piVar3;
  int *unaff_ESI;
  
  if ((unaff_ESI == (int *)0x0) || (in_EAX == (int *)0x0)) {
    return (int *)0x0;
  }
  if (((*unaff_ESI == param_2) && (unaff_ESI[3] == param_3)) &&
     ((*(uint *)(&DAT_68193cbc + param_3 * 0x10) & 0x8000) != 0)) {
    if (unaff_ESI[5] != -2) {
      piVar3 = (int *)unaff_ESI[7];
      piVar1 = (int *)unaff_ESI[6];
      unaff_ESI[5] = -2;
      unaff_ESI[8] = 1;
      piVar1[10] = (int)piVar3;
      unaff_ESI[8] = unaff_ESI[8] + 1;
      unaff_ESI[7] = (int)(piVar3 + 10);
      unaff_ESI[9] = 0;
      if (param_2 == 0xf) {
        iVar2 = *piVar1;
        if (iVar2 == 0x1f) {
          unaff_ESI[9] = 1;
        }
        else if (iVar2 != 0x1e) {
          unaff_ESI[9] = 2;
        }
        if (*piVar3 == 0x1f) {
          unaff_ESI[9] = unaff_ESI[9] | 1;
        }
        else if (*piVar3 != 0x1e) {
          unaff_ESI[9] = unaff_ESI[9] | 2;
        }
      }
    }
    *(int **)unaff_ESI[7] = in_EAX;
    unaff_ESI[8] = unaff_ESI[8] + 1;
    unaff_ESI[7] = (int)(in_EAX + 10);
    unaff_ESI[2] = in_EAX[2];
    if (param_2 == 0xf) {
      if (*in_EAX == 0x1f) {
        unaff_ESI[9] = unaff_ESI[9] | 1;
      }
      else if (*in_EAX != 0x1e) {
        unaff_ESI[9] = unaff_ESI[9] | 2;
        return unaff_ESI;
      }
    }
    return unaff_ESI;
  }
  if (((param_2 == 0xf) && (*unaff_ESI == 0x1e)) && (*in_EAX == 0x1e)) {
    *(double *)(unaff_ESI + 6) = *(double *)(in_EAX + 6) + *(double *)(unaff_ESI + 6);
    crypto_advanceParser((int)this);
    return unaff_ESI;
  }
  piVar3 = (int *)crypto_allocAstNode((int)this);
  if (piVar3 == (int *)0x0) {
    return (int *)0x0;
  }
  *piVar3 = param_2;
  piVar3[1] = unaff_ESI[1];
  iVar2 = in_EAX[2];
  piVar3[7] = (int)in_EAX;
  piVar3[2] = iVar2;
  piVar3[3] = param_3;
  piVar3[5] = 2;
  piVar3[6] = (int)unaff_ESI;
  piVar3[10] = 0;
  return piVar3;
}



// ============================================================
// Function: crypto_peekToken (FUN_68143840)
// Address: 68143840
// Size: 82 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_peekToken(int param_1)

{
  int iVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  iVar1 = strings_beginParse(unaff_ESI,unaff_EDI);
  if (iVar1 != -1) {
    if ((((iVar1 == 0) || (iVar1 == 1)) || (iVar1 == 2)) ||
       ((iVar1 == 0x1a || (((iVar1 == 0x22 || (param_1 == 0x22)) && ((int)unaff_ESI[3] < 0x78))))))
    {
      return 1;
    }
    strings_scanToken(unaff_ESI,unaff_EDI,0,0,0x6d);
  }
  return 0;
}



// ============================================================
// Function: crypto_consumeToken (FUN_681438a0)
// Address: 681438a0
// Size: 199 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crypto_consumeToken(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int unaff_ESI;
  uint *unaff_EDI;
  undefined4 local_8;
  
  iVar1 = *(int *)(unaff_ESI + 0x14 + *(int *)(unaff_ESI + 0x60) * 0x18);
  if (iVar1 == *(int *)(unaff_EDI[5] + 0xfc)) {
    local_8 = 0x7b;
  }
  else {
    if (iVar1 != *(int *)(unaff_EDI[5] + 0x11c)) {
      return 0x1d;
    }
    local_8 = 0x7c;
  }
  iVar2 = strings_beginParse(unaff_EDI,unaff_ESI);
  if (iVar2 != param_1) {
    return 0x1d;
  }
  strings_parseExpression(unaff_EDI,unaff_ESI);
  if (*(int *)(unaff_ESI + 0x10 + *(int *)(unaff_ESI + 0x60) * 0x18) == 0) {
    *(undefined4 *)(unaff_ESI + 0x10 + *(int *)(unaff_ESI + 0x60) * 0x18) = local_8;
    xtra_getStringValue((uint *)(*(uint *)(iVar1 + 8) & 0xfffffff8));
    uVar3 = strings_scanToken(unaff_EDI,unaff_ESI,0,5,0x9e);
    if (uVar3 != 0) {
      return param_1;
    }
  }
  else {
    strings_scanToken(unaff_EDI,unaff_ESI,0,0,0x97);
  }
  return -1;
}



// ============================================================
// Function: crypto_getTokenValue (FUN_68143970)
// Address: 68143970
// Size: 295 bytes
// Params: undefined4 * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crypto_getTokenValue(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int *piVar6;
  
  uVar1 = *param_1;
  do {
    switch(uVar1) {
    case 0x19:
      if (param_1[6] == 0) {
        return 0;
      }
      param_1 = (undefined4 *)(param_1[7] + -0x28);
      break;
    default:
      return 0;
    case 0x25:
      uVar4 = crypto_getTokenValue((undefined4 *)param_1[7]);
      if (((undefined4 *)param_1[8] != (undefined4 *)0x0) &&
         (uVar5 = crypto_getTokenValue((undefined4 *)param_1[8]), uVar5 != 0)) {
        return uVar4 & 1;
      }
      return 0;
    case 0x27:
      piVar6 = *(int **)(param_1[7] + 0x18);
      uVar5 = 1;
      uVar4 = 0;
      goto LAB_681439f4;
    case 0x31:
      param_1 = (undefined4 *)param_1[7];
      break;
    case 0x32:
    case 0x3a:
      return 1;
    case 0x37:
      if (((undefined4 *)param_1[8] != (undefined4 *)0x0) &&
         (uVar4 = crypto_getTokenValue((undefined4 *)param_1[8]), uVar4 != 0)) {
        return 1;
      }
      uVar4 = crypto_getTokenValue((undefined4 *)param_1[6]);
      if ((undefined4 *)param_1[7] != (undefined4 *)0x0) {
        uVar5 = crypto_getTokenValue((undefined4 *)param_1[7]);
        uVar4 = uVar4 & uVar5;
      }
      return uVar4;
    case 0x38:
      uVar4 = crypto_getTokenValue((undefined4 *)param_1[8]);
      for (iVar2 = param_1[7]; iVar2 != 0; iVar2 = *(int *)(iVar2 + 0x1c)) {
        uVar5 = crypto_getTokenValue(*(undefined4 **)(iVar2 + 0x20));
        uVar4 = uVar4 & uVar5;
      }
      return uVar4;
    }
    uVar1 = *param_1;
  } while( true );
  while( true ) {
    if (*piVar6 == 0x29) {
      uVar4 = 1;
    }
    if (*(int *)(piVar6[7] + 0x18) != 0) {
      uVar3 = crypto_getTokenValue((undefined4 *)(*(int *)(piVar6[7] + 0x1c) + -0x28));
      uVar5 = uVar5 & uVar3;
    }
    piVar6 = (int *)piVar6[10];
    if (uVar5 == 0) break;
LAB_681439f4:
    if (piVar6 == (int *)0x0) break;
  }
  return uVar4 & uVar5;
}



// ============================================================
// Function: crypto_reportLabelError (FUN_68143ae0)
// Address: 68143ae0
// Size: 63 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_reportLabelError(void)
{
  int iVar1;
  uint *unaff_ESI;
  int unaff_EDI;
  
  iVar1 = *(int *)(*(int *)(unaff_ESI[0xd] + 0x10) + 0x18);
  if (iVar1 != 0) {
    certs_encodeUri((uint *)(*(uint *)(iVar1 + 8) & 0xfffffff8));
    strings_scanToken(unaff_ESI,unaff_EDI,0,5,0x6e);
    return 0;
  }
  strings_scanToken(unaff_ESI,unaff_EDI,0,5,0x9d);
  return 0;
}



// ============================================================
// Function: crypto_validateToken (FUN_68143b20)
// Address: 68143b20
// Size: 26 bytes
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_validateToken(void)

{
  undefined4 *in_EAX;
  uint uVar1;
  int iVar2;
  
  uVar1 = crypto_getTokenValue(in_EAX);
  if (uVar1 == 0) {
    iVar2 = crypto_reportLabelError();
    if (iVar2 == 0) {
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: crypto_compileExpr (FUN_68143b40)
// Address: 68143b40
// Size: 11 bytes
// Params: uint param_1, uint * param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall crypto_compileExpr(uint param_1,uint *param_2)
{
  uint *in_EAX;
  
  crypto_compileExpression(param_2,param_1,in_EAX,0);
  return 0;
}



// ============================================================
// Function: crypto_parseFunctionArgs (FUN_68143b50)
// Address: 68143b50
// Size: 79 bytes
// Params: uint * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall crypto_parseFunctionArgs(uint *param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int unaff_EBX;
  
  iVar1 = strings_beginParse(param_1,in_EAX);
  if (iVar1 == -1) {
    return 0;
  }
  if (iVar1 == 0x1d) {
    strings_parseExpression(param_1,in_EAX);
    uVar2 = *(undefined4 *)(in_EAX + 0x14 + *(int *)(in_EAX + 0x60) * 0x18);
  }
  else {
    uVar2 = 0;
  }
  *(undefined4 *)(unaff_EBX + 0x18) = uVar2;
  if ((uint)*(ushort *)(unaff_EBX + 10) == *(uint *)(in_EAX + 0x68)) {
    uVar2 = crypto_peekToken(-1);
    return uVar2;
  }
  return 1;
}



// ============================================================
// Function: crypto_parseTokenList (FUN_68143ba0)
// Address: 68143ba0
// Size: 160 bytes
// Params: int param_1, uint * param_2
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * crypto_parseTokenList(int param_1,uint *param_2)

{
  int iVar1;
  bool bVar2;
  uint *in_EAX;
  int *piVar3;
  undefined3 extraout_var;
  int *piVar4;
  undefined3 extraout_var_00;
  
  piVar3 = crypto_parseUnary(in_EAX,param_1,param_2);
  piVar4 = piVar3;
  if ((piVar3 != (int *)0x0) &&
     (bVar2 = strings_compareRange(in_EAX,param_1,3), CONCAT31(extraout_var,bVar2) != 0)) {
    piVar4 = crypto_createNode(param_2,0xfffffffe);
    if (piVar4 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar1 = piVar3[1];
    piVar4[6] = (int)piVar3;
    piVar4[7] = (int)(piVar3 + 10);
    piVar4[1] = iVar1;
    piVar4[8] = 1;
    do {
      piVar3 = crypto_parseUnary(in_EAX,param_1,param_2);
      if (piVar3 == (int *)0x0) {
        return (int *)0x0;
      }
      *(int **)piVar4[7] = piVar3;
      piVar4[8] = piVar4[8] + 1;
      piVar4[7] = (int)(piVar3 + 10);
      bVar2 = strings_compareRange(in_EAX,param_1,3);
    } while (CONCAT31(extraout_var_00,bVar2) != 0);
    piVar4[2] = *(int *)(piVar4[7] + -0x20);
  }
  return piVar4;
}



// ============================================================
// Function: crypto_resolveAssignTarget (FUN_68143c40)
// Address: 68143c40
// Size: 89 bytes
// Params: uint * param_1, int param_2, int param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * crypto_resolveAssignTarget(uint *param_1,int param_2,int param_3)

{
  int iVar1;
  int *in_EAX;
  
  iVar1 = *in_EAX;
  while (iVar1 == 0x1c) {
    in_EAX = (int *)in_EAX[6];
    iVar1 = *in_EAX;
  }
  iVar1 = *in_EAX;
  if ((((iVar1 != 0x1d) && (iVar1 != 0x16)) && ((iVar1 != 0x1b || (in_EAX[3] != 0x3a)))) &&
     (iVar1 != 0x17)) {
    strings_scanToken(param_1,param_2,0,0,0x82);
    return (int *)0x0;
  }
  *(int **)(param_3 + 0x18) = in_EAX;
  return in_EAX;
}



// ============================================================
// Function: crypto_resolveAssignOpcode (FUN_68143ca0)
// Address: 68143ca0
// Size: 274 bytes
// Params: int param_1, uint * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_resolveAssignOpcode(int param_1,uint *param_2,int param_3)

{
  int in_EAX;
  int *piVar1;
  uint *unaff_EBX;
  int iVar2;
  int unaff_EDI;
  
  piVar1 = crypto_resolveAssignTarget(unaff_EBX,param_1,param_3);
  if (piVar1 == (int *)0x0) {
    return 0;
  }
  switch(*piVar1) {
  case 0x16:
    if (unaff_EDI == 0x14) {
      *(uint *)(param_3 + 0xc) = (-(uint)(in_EAX != 0) & 0xfffffffa) + 0x30;
      return 1;
    }
    *(uint *)(param_3 + 0xc) = (-(uint)(in_EAX != 0) & 0xfffffffa) + 0x33;
    return 1;
  default:
    iVar2 = 0;
    break;
  case 0x1b:
    piVar1[3] = 0x84;
  case 0x17:
    if (unaff_EDI == 0x14) {
      *(uint *)(param_3 + 0xc) = (-(uint)(in_EAX != 0) & 0xfffffffa) + 0x31;
      return 1;
    }
    *(uint *)(param_3 + 0xc) = (-(uint)(in_EAX != 0) & 0xfffffffa) + 0x34;
    return 1;
  case 0x1d:
    if (unaff_EDI == 0x14) {
      iVar2 = (-(uint)(in_EAX != 0) & 0xfffffffa) + 0x2f;
    }
    else {
      iVar2 = (-(uint)(in_EAX != 0) & 0xfffffffa) + 0x32;
    }
    if (piVar1[6] == *(int *)(unaff_EBX[5] + 0xd8)) {
      *param_2 = *param_2 | 0x80;
      *(int *)(param_3 + 0xc) = iVar2;
      return 1;
    }
  }
  *(int *)(param_3 + 0xc) = iVar2;
  return 1;
}



// ============================================================
// Function: crypto_parseListTail (FUN_68143de0)
// Address: 68143de0
// Size: 109 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_parseListTail(uint *param_1)

{
  bool bVar1;
  undefined3 extraout_var;
  int *piVar2;
  undefined3 extraout_var_00;
  int iVar3;
  uint *unaff_EBX;
  int unaff_ESI;
  int unaff_EDI;
  
  *(uint *)(unaff_ESI + 0x7c) = *(uint *)(unaff_ESI + 0x7c) | 8;
  bVar1 = strings_compareRange(unaff_EBX,unaff_ESI,0x1c);
  *(uint *)(unaff_ESI + 0x7c) = *(uint *)(unaff_ESI + 0x7c) & 0xfffffff7;
  if (CONCAT31(extraout_var,bVar1) == 0) {
    do {
      piVar2 = crypto_parseUnary(unaff_EBX,unaff_ESI,param_1);
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      **(undefined4 **)(unaff_EDI + 0x1c) = piVar2;
      *(int *)(unaff_EDI + 0x20) = *(int *)(unaff_EDI + 0x20) + 1;
      *(int **)(unaff_EDI + 0x1c) = piVar2 + 10;
      bVar1 = strings_compareRange(unaff_EBX,unaff_ESI,3);
    } while (CONCAT31(extraout_var_00,bVar1) != 0);
    iVar3 = strings_parseExpression(unaff_EBX,unaff_ESI);
    if (iVar3 != 0x1c) {
      strings_scanToken(unaff_EBX,unaff_ESI,0,0,0x68);
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: crypto_parsePostfixExpr (FUN_68143e50)
// Address: 68143e50
// Size: 830 bytes
// Params: uint * param_1, uint param_2, uint * param_3, int param_4
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * crypto_parsePostfixExpr(uint *param_1,uint param_2,uint *param_3,int param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined3 extraout_var;
  int *piVar4;
  undefined4 *local_8;
  
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 8;
  iVar2 = strings_initParser(param_1,param_2);
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xfffffff7;
  if (iVar2 == 0x33) {
    strings_parseExpression(param_1,param_2);
    local_8 = crypto_createNode(param_3,0xfffffffe);
    if ((local_8 != (undefined4 *)0x0) &&
       (puVar3 = crypto_parsePostfixExpr(param_1,param_2,param_3,0), puVar3 != (undefined4 *)0x0)) {
      local_8[3] = 0x23;
      local_8[6] = puVar3;
      local_8[7] = puVar3 + 10;
      local_8[8] = 1;
      local_8[1] = puVar3[1];
      bVar1 = strings_compareRange(param_1,param_2,0x1b);
      if ((CONCAT31(extraout_var,bVar1) == 0) || (iVar2 = crypto_parseListTail(param_3), iVar2 != 0)) {
        if (local_8[8] - 1 < 0x10000) {
          local_8[2] = *(undefined4 *)(local_8[7] + -0x20);
          goto LAB_68143f39;
        }
        xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x2c);
      }
    }
  }
  else {
    local_8 = crypto_parsePrimaryExpr(param_1,param_2,param_3);
    if (local_8 != (undefined4 *)0x0) {
LAB_68143f39:
      iVar2 = strings_parseExpression(param_1,param_2);
      if (iVar2 < 1) {
        return (undefined4 *)(-(uint)(iVar2 != -1) & (uint)local_8);
      }
      do {
        if (iVar2 == 0x16) {
          puVar3 = crypto_createNode(param_3,0xffffffff);
          if (puVar3 == (undefined4 *)0x0) {
            return (undefined4 *)0x0;
          }
          iVar2 = strings_parseExpression(param_1,param_2);
          if (iVar2 != 0x1d) {
            strings_scanToken(param_1,param_2,0,0,0x4d);
            return (undefined4 *)0x0;
          }
          puVar3[1] = local_8[1];
          puVar3[2] = *(undefined4 *)(param_2 + 8 + *(int *)(param_2 + 0x60) * 0x18);
          puVar3[3] = 0x35;
          puVar3[7] = local_8;
          puVar3[6] = *(undefined4 *)(param_2 + 0x14 + *(int *)(param_2 + 0x60) * 0x18);
        }
        else if (iVar2 == 0x17) {
          puVar3 = crypto_createNode(param_3,2);
          if (puVar3 == (undefined4 *)0x0) {
            return (undefined4 *)0x0;
          }
          piVar4 = crypto_parseTokenList(param_2,param_3);
          if (piVar4 == (int *)0x0) {
            return (undefined4 *)0x0;
          }
          iVar2 = strings_parseExpression(param_1,param_2);
          if (iVar2 != 0x18) {
            strings_scanToken(param_1,param_2,0,0,0x4e);
            return (undefined4 *)0x0;
          }
          puVar3[1] = local_8[1];
          puVar3[2] = *(undefined4 *)(param_2 + 8 + *(int *)(param_2 + 0x60) * 0x18);
          if (*piVar4 == 0x1f) {
            *puVar3 = 0x16;
            puVar3[3] = 0x35;
            puVar3[5] = 0xffffffff;
            puVar3[7] = local_8;
            puVar3[6] = piVar4[6];
          }
          else {
            puVar3[3] = 0x37;
            puVar3[6] = local_8;
            puVar3[7] = piVar4;
          }
        }
        else {
          if ((param_4 == 0) || (iVar2 != 0x1b)) {
            strings_resetScanner(param_2);
            return local_8;
          }
          puVar3 = crypto_createNode(param_3,0xfffffffe);
          if (puVar3 == (undefined4 *)0x0) {
            return (undefined4 *)0x0;
          }
          puVar3[3] = 0x3a;
          if ((local_8[3] == 0x3b) && (local_8[6] == *(int *)(param_1[5] + 0xf4))) {
            puVar3[3] = 0x79;
            *param_3 = *param_3 | 0x80;
          }
          puVar3[6] = local_8;
          puVar3[7] = local_8 + 10;
          puVar3[8] = 1;
          puVar3[1] = local_8[1];
          iVar2 = crypto_parseListTail(param_3);
          if (iVar2 == 0) {
            return (undefined4 *)0x0;
          }
          if (0xffff < puVar3[8] - 1) {
            xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x2d);
            return (undefined4 *)0x0;
          }
          puVar3[2] = *(undefined4 *)(puVar3[7] + -0x20);
        }
        iVar2 = strings_parseExpression(param_1,param_2);
        local_8 = puVar3;
        if (iVar2 < 1) {
          return (undefined4 *)(-(uint)(iVar2 != -1) & (uint)puVar3);
        }
      } while( true );
    }
  }
  return (undefined4 *)0x0;
}



// ============================================================
// Function: crypto_parseStatement (FUN_68144190)
// Address: 68144190
// Size: 177 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_parseStatement(int *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (int *)0x0) {
switchD_681441af_caseD_ffffffff:
    return 0;
  }
LAB_681441a0:
  switch(param_1[5]) {
  case 1:
    goto switchD_681441af_caseD_1;
  case 2:
    if (param_1[3] != 0) {
      return 0;
    }
    iVar1 = crypto_parseStatement((int *)param_1[6]);
    if (iVar1 != 0) {
      return 1;
    }
    piVar2 = (int *)param_1[7];
    break;
  case 3:
    iVar1 = crypto_parseStatement((int *)param_1[6]);
    if (iVar1 != 0) {
      return 1;
    }
    iVar1 = crypto_parseStatement((int *)param_1[7]);
    if (iVar1 != 0) {
      return 1;
    }
    piVar2 = (int *)param_1[8];
    break;
  case -2:
    if (*param_1 == 0x30) {
      return 1;
    }
    piVar2 = (int *)param_1[6];
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    do {
      iVar1 = crypto_parseStatement(piVar2);
      if (iVar1 != 0) {
        return 1;
      }
      piVar2 = (int *)piVar2[10];
    } while (piVar2 != (int *)0x0);
    return 0;
  default:
    goto switchD_681441af_caseD_ffffffff;
  }
  iVar1 = crypto_parseStatement(piVar2);
  if (iVar1 != 0) {
    return 1;
  }
  return 0;
switchD_681441af_caseD_1:
  if (param_1[3] != 0) {
    return 0;
  }
  param_1 = (int *)param_1[6];
  if (param_1 == (int *)0x0) {
    return 0;
  }
  goto LAB_681441a0;
}



// ============================================================
// Function: crypto_nextToken (FUN_68144260)
// Address: 68144260
// Size: 142 bytes
// Params: int param_1, undefined4 param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall crypto_nextToken(int param_1,undefined4 param_2)

{
  uint *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *unaff_ESI;
  ushort *unaff_EDI;
  double local_c;
  
  iVar3 = *unaff_ESI;
  if (iVar3 != param_1) {
    if (param_1 == 0x1e) {
      if (iVar3 == 0x1f) {
        iVar3 = runtime_parseNumber(unaff_EDI,*(uint *)(unaff_ESI[6] + 8),&local_c);
        if (iVar3 == 0) {
          return 0;
        }
        *unaff_ESI = 0x1e;
        *(double *)(unaff_ESI + 6) = local_c;
        unaff_ESI[3] = 0x3c;
      }
    }
    else if ((param_1 == 0x1f) && (iVar3 == 0x1e)) {
      puVar1 = (uint *)runtime_divideFloat(0,param_2,(uint)unaff_EDI,*(double *)(unaff_ESI + 6));
      if (puVar1 != (uint *)0x0) {
        puVar2 = js_findOrCreateAtom((int)unaff_EDI,puVar1,0);
        unaff_ESI[6] = (int)puVar2;
        if (puVar2 != (undefined4 *)0x0) {
          *unaff_ESI = 0x1f;
          unaff_ESI[3] = 0x3d;
          return 1;
        }
      }
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: crypto_foldConstants (FUN_681442f0)
// Address: 681442f0
// Size: 533 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_foldConstants(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  double dVar1;
  double dVar2;
  int in_EAX;
  int iVar3;
  uint uVar4;
  undefined4 *unaff_EBX;
  int unaff_EDI;
  float10 fVar5;
  float10 fVar6;
  undefined8 uVar7;
  int local_1c;
  uint uStack_18;
  undefined8 local_14;
  int local_c;
  byte local_8 [4];
  
  dVar1 = *(double *)(unaff_EBX + 6);
  fVar5 = (float10)dVar1;
  dVar2 = *(double *)(param_1 + 6);
  fVar6 = (float10)dVar2;
  local_1c = SUB84(dVar2,0);
  uStack_18 = (uint)((ulonglong)dVar2 >> 0x20);
  (*(unsigned int *)((char *)&local_14 + 4)) = (uint)((ulonglong)dVar1 >> 0x20);
  uVar4 = (*(unsigned int *)((char *)&local_14 + 4));
  iVar3 = SUB84(dVar1,0);
  local_14 = dVar1;
  switch(in_EAX) {
  case 0x18:
  case 0x19:
    uVar7 = runtime_multiplyFloat(unaff_EDI,iVar3,uVar4,&local_c);
    if (((int)uVar7 == 0) ||
       (uVar7 = runtime_multiplyFloat(unaff_EDI,local_1c,uStack_18,(undefined4 *)local_8), (int)uVar7 == 0))
    {
      return 0;
    }
    dVar1 = local_14;
    if (in_EAX == 0x18) {
      local_c = local_c << (local_8[0] & 0x1f);
      fVar5 = (float10)local_c;
    }
    else {
      local_c = local_c >> (local_8[0] & 0x1f);
      fVar5 = (float10)local_c;
    }
    break;
  case 0x1a:
    iVar3 = runtime_addFloat(unaff_EDI,iVar3,uVar4,(undefined4 *)((int)&local_14 + 4));
    if (iVar3 == 0) {
      return 0;
    }
    uVar7 = runtime_multiplyFloat(unaff_EDI,local_1c,uStack_18,(undefined4 *)local_8);
    if ((int)uVar7 == 0) {
      return 0;
    }
    uVar4 = (*(unsigned int *)((char *)&local_14 + 4)) >> (local_8[0] & 0x1f);
    local_14 = (double)CONCAT44(uVar4,(undefined4)local_14);
    fVar5 = (float10)(int)uVar4;
    dVar1 = local_14;
    if ((int)uVar4 < 0) {
      fVar5 = fVar5 + (float10)4294967296.0;
    }
    break;
  case 0x1b:
    fVar5 = fVar6 + fVar5;
    break;
  case 0x1c:
    fVar5 = fVar5 - fVar6;
    break;
  case 0x1d:
    fVar5 = fVar6 * fVar5;
    break;
  case 0x1e:
    if ((float10)0 == fVar6) {
      if (((((uStack_18 & 0x7ff00000) == 0x7ff00000) &&
           ((local_1c != 0 || (((ulonglong)dVar2 & 0xfffff00000000) != 0)))) ||
          ((float10)0 == fVar5)) ||
         ((((*(unsigned int *)((char *)&local_14 + 4)) & 0x7ff00000) == 0x7ff00000 &&
          ((iVar3 != 0 || (((ulonglong)dVar1 & 0xfffff00000000) != 0)))))) {
        fVar5 = (float10)**(double **)(*(int *)(unaff_EDI + 0x14) + 0x1d0);
      }
      else if ((int)((*(unsigned int *)((char *)&local_14 + 4)) ^ uStack_18) < 0) {
        fVar5 = (float10)**(double **)(*(int *)(unaff_EDI + 0x14) + 0x1d4);
      }
      else {
        fVar5 = (float10)**(double **)(*(int *)(unaff_EDI + 0x14) + 0x1d8);
      }
    }
    else {
      fVar5 = fVar5 / fVar6;
    }
    break;
  case 0x1f:
    if ((float10)0 == fVar6) {
      fVar5 = (float10)**(double **)(*(int *)(unaff_EDI + 0x14) + 0x1d0);
    }
    else if (((((*(unsigned int *)((char *)&local_14 + 4)) & 0x7ff00000) == 0x7ff00000) ||
             ((uStack_18 & 0x7fffffff) != 0x7ff00000)) || (local_1c != 0)) {
      fVar5 = (float10)_CIfmod();
      dVar1 = local_14;
    }
  }
  local_14 = dVar1;
  if (unaff_EBX != param_2) {
    fVar5 = (float10)crypto_advanceParser(param_3);
  }
  if (param_1 != param_2) {
    fVar5 = (float10)crypto_advanceParser(param_3);
  }
  *(double *)(param_2 + 6) = (double)fVar5;
  *param_2 = 0x1e;
  param_2[3] = 0x3c;
  param_2[5] = 0;
  return 1;
}



// ============================================================
// Function: crypto_parsePrimary (FUN_68144530)
// Address: 68144530
// Size: 1574 bytes
// Params: undefined4 param_1, int * param_2, uint param_3, int * param_4, int param_5
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall crypto_parsePrimary(int param_1,int *param_2,uint param_3,int *param_4,int param_5)

{
  double dVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  undefined2 *_Dst;
  uint *puVar7;
  int *piVar8;
  undefined4 *puVar9;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int *extraout_EDX;
  int *extraout_EDX_00;
  int *extraout_EDX_01;
  int *extraout_EDX_02;
  int *extraout_EDX_03;
  int *extraout_EDX_04;
  int *extraout_EDX_05;
  int *extraout_EDX_06;
  undefined4 extraout_EDX_07;
  int *piVar10;
  undefined8 uVar11;
  int *piVar12;
  int *local_c;
  int *local_8;
  
  piVar3 = param_4;
  piVar10 = (int *)0x0;
  local_c = (int *)0x0;
  local_8 = (int *)0x0;
  switch(param_4[5]) {
  case 1:
    piVar10 = (int *)param_4[6];
    piVar8 = piVar10;
    piVar12 = (int *)param_5;
    iVar4 = param_1;
    goto joined_r0x68144604;
  case 2:
    piVar10 = (int *)param_4[6];
    local_c = (int *)param_4[7];
    if ((piVar10 != (int *)0x0) &&
       (iVar4 = crypto_parsePrimary(param_5,(int *)param_3,param_3,piVar10,param_5),
       param_2 = extraout_EDX_04, iVar4 == 0)) {
      return 0;
    }
    iVar4 = crypto_parsePrimary(param_3,param_2,param_3,local_c,param_5);
    param_2 = extraout_EDX_05;
    if (iVar4 == 0) {
      return 0;
    }
    break;
  case 3:
    piVar10 = (int *)param_4[6];
    local_c = (int *)param_4[7];
    piVar8 = (int *)param_4[8];
    param_2 = piVar8;
    if ((piVar10 != (int *)0x0) &&
       (iVar4 = crypto_parsePrimary(param_3,piVar8,param_3,piVar10,param_5), param_1 = extraout_ECX,
       param_2 = extraout_EDX_01, iVar4 == 0)) {
      return 0;
    }
    piVar12 = piVar8;
    local_8 = piVar8;
    iVar4 = param_5;
    if ((local_c != (int *)0x0) &&
       (iVar5 = crypto_parsePrimary(param_1,(int *)param_5,param_3,local_c,param_5),
       param_2 = extraout_EDX_02, iVar4 = param_5, iVar5 == 0)) {
      return 0;
    }
joined_r0x68144604:
    if ((piVar8 != (int *)0x0) &&
       (iVar4 = crypto_parsePrimary(iVar4,piVar12,param_3,piVar8,param_5), param_2 = extraout_EDX_03,
       iVar4 == 0)) {
      return 0;
    }
    break;
  case -3:
    piVar8 = (int *)param_4[7];
    piVar12 = (int *)param_4[7];
LAB_68144560:
    iVar4 = crypto_parsePrimary((int)piVar8,(int *)param_3,param_3,piVar12,param_5);
    param_2 = extraout_EDX;
    if (iVar4 == 0) {
      return 0;
    }
    break;
  case -2:
    piVar10 = (int *)param_4[6];
    piVar8 = piVar10;
    local_c = piVar10;
    if (piVar10 != (int *)0x0) {
      do {
        iVar4 = crypto_parsePrimary(param_3,param_2,param_3,piVar8,param_5);
        if (iVar4 == 0) {
          return 0;
        }
        piVar8 = (int *)piVar8[10];
        param_2 = extraout_EDX_00;
      } while (piVar8 != (int *)0x0);
      local_c = (int *)0x0;
    }
    break;
  case -1:
    for (piVar10 = (int *)param_4[7]; piVar10 != (int *)0x0; piVar10 = (int *)piVar10[7]) {
      piVar8 = (int *)param_5;
      piVar12 = piVar10;
      if (piVar10[5] != -1) goto LAB_68144560;
    }
  }
  uVar6 = param_3;
  switch(*piVar3) {
  case 5:
    goto switchD_681445ba_caseD_5;
  default:
    goto switchD_681445ba_caseD_6;
  case 0xe:
  case 0x10:
  case 0x12:
    break;
  case 0xf:
    if (piVar3[5] == -2) {
      if ((piVar3[9] & 2U) != 0) {
        return 1;
      }
      if (piVar3[9] == 1) {
        local_8 = (int *)0x0;
        for (piVar8 = piVar10; piVar8 != (int *)0x0; piVar8 = (int *)piVar8[10]) {
          iVar4 = crypto_nextToken(0x1f,param_2);
          if (iVar4 == 0) {
            return 0;
          }
          if (*piVar8 != 0x1f) {
            return 1;
          }
          param_2 = *(int **)(*(uint *)(piVar8[6] + 8) & 0xfffffff8);
          local_8 = (int *)((int)local_8 + (int)param_2);
          piVar3 = param_4;
        }
        _Dst = (undefined2 *)xtra_getPropertyById(param_3,(int)local_8 * 2 + 2);
        if (_Dst == (undefined2 *)0x0) {
          return 0;
        }
        puVar7 = certs_allocHashEntry(param_3,(uint)_Dst,(uint)local_8,0);
        if (puVar7 != (uint *)0x0) {
          while (piVar10 != (int *)0x0) {
            piVar8 = (int *)(*(uint *)(piVar10[6] + 8) & 0xfffffff8);
            param_4 = (int *)(*piVar8 * 2);
            memcpy(_Dst,(void *)piVar8[1],(size_t)param_4);
            piVar10 = (int *)piVar10[10];
            _Dst = (undefined2 *)((int)_Dst + (int)param_4);
            crypto_advanceParser(param_5);
          }
          *_Dst = 0;
          puVar9 = js_findOrCreateAtom(param_3,puVar7,0);
          piVar3[6] = (int)puVar9;
          if (puVar9 == (undefined4 *)0x0) {
            return 0;
          }
          *piVar3 = 0x1f;
          piVar3[3] = 0x3d;
          piVar3[5] = 0;
          return 1;
        }
        xtra_checkAndFlush(param_3,(int)_Dst);
        return 0;
      }
    }
    else if ((*piVar10 == 0x1f) || (*local_c == 0x1f)) {
      iVar4 = crypto_nextToken(0x1f,param_2);
      if (iVar4 == 0) {
        return 0;
      }
      if (*piVar10 != 0x1f) {
        return 1;
      }
      if (*local_c != 0x1f) {
        return 1;
      }
      puVar7 = crypto_concatStrings(uVar6,(uint *)(*(uint *)(piVar10[6] + 8) & 0xfffffff8),
                            (uint *)(*(uint *)(local_c[6] + 8) & 0xfffffff8));
      if (puVar7 == (uint *)0x0) {
        return 0;
      }
      puVar9 = js_findOrCreateAtom(uVar6,puVar7,0);
      param_4[6] = (int)puVar9;
      if (puVar9 == (undefined4 *)0x0) {
        return 0;
      }
      *param_4 = 0x1f;
      param_4[3] = 0x3d;
      param_4[5] = 0;
      crypto_advanceParser(param_5);
      crypto_advanceParser(extraout_ECX_01);
      return 1;
    }
    break;
  case 0x11:
    if (piVar3[5] == 0) {
      return 1;
    }
    break;
  case 0x13:
    if (*piVar10 != 0x1e) {
      return 1;
    }
    dVar1 = *(double *)(piVar10 + 6);
    switch(piVar3[3]) {
    case 0x20:
      *piVar3 = 0x21;
      iVar4 = 0x43;
      if (dVar1 != 0.0) {
        iVar4 = 0x42;
      }
      piVar3[3] = iVar4;
      piVar3[5] = 0;
      return 1;
    case 0x21:
      uVar11 = runtime_multiplyFloat(param_3,SUB84(dVar1,0),(uint)((ulonglong)dVar1 >> 0x20),&param_3);
      if ((int)uVar11 == 0) {
        return 0;
      }
      param_3 = ~param_3;
      dVar1 = (double)(int)param_3;
      break;
    case 0x22:
      dVar1 = -dVar1;
      break;
    default:
      return 1;
    case 0x52:
      break;
    }
    *(double *)(piVar3 + 6) = dVar1;
    *piVar3 = 0x1e;
    piVar3[3] = 0x3c;
    piVar3[5] = 0;
    crypto_advanceParser(param_5);
    return 1;
  case 0x25:
    iVar4 = crypto_parseStatement(local_c);
    if (iVar4 != 0) {
      return 1;
    }
    iVar4 = crypto_parseStatement(local_8);
    if (iVar4 != 0) {
      return 1;
    }
switchD_681445ba_caseD_5:
    iVar4 = *piVar10;
    if (iVar4 == 0x1e) {
      if (*(double *)(piVar10 + 6) == 0.0) goto LAB_68144730;
    }
    else if (iVar4 == 0x1f) {
      uVar6 = *(uint *)(*(uint *)(piVar10[6] + 8) & 0xfffffff8);
      if ((uVar6 & 0x40000000) != 0) {
        uVar6 = *(uint *)(*(uint *)(piVar10[6] + 8) & 0xfffffff8);
        uVar6 = (-(uint)((uVar6 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar6;
      }
      if (uVar6 == 0) goto LAB_68144730;
    }
    else {
      if (iVar4 != 0x21) {
        return 1;
      }
      iVar4 = piVar10[3];
      if (iVar4 != 0x43) {
        if ((iVar4 != 0x42) && (iVar4 != 0x40)) {
          return 1;
        }
LAB_68144730:
        local_c = local_8;
      }
    }
    if (local_c == (int *)0x0) {
      *piVar3 = 2;
      piVar3[5] = 1;
      piVar3[6] = 0;
    }
    else {
      *piVar3 = *local_c;
      piVar3[3] = local_c[3];
      piVar3[5] = local_c[5];
      piVar3[6] = local_c[6];
      piVar3[7] = local_c[7];
      piVar3[8] = local_c[8];
      piVar3[9] = local_c[9];
      *local_c = 0;
      local_c[3] = 0;
      local_c[5] = 0;
    }
    crypto_advanceParser(param_5);
    if ((local_8 != (int *)0x0) && (local_8 != local_c)) {
      crypto_advanceParser(extraout_ECX_00);
      return 1;
    }
    goto switchD_681445ba_caseD_6;
  }
  piVar8 = piVar10;
  if (piVar3[5] == -2) {
    for (; piVar8 != (int *)0x0; piVar8 = (int *)piVar8[10]) {
      iVar4 = crypto_nextToken(0x1e,param_2);
      if (iVar4 == 0) {
        return 0;
      }
      if (*piVar8 != 0x1e) {
        return 1;
      }
      param_2 = extraout_EDX_06;
    }
    puVar9 = (undefined4 *)((undefined4 *)piVar10[10])[10];
    iVar4 = crypto_foldConstants((undefined4 *)piVar10[10],param_4,param_5);
    if (iVar4 != 0) {
      if (puVar9 == (undefined4 *)0x0) {
        return 1;
      }
      while( true ) {
        puVar2 = (undefined4 *)puVar9[10];
        iVar4 = crypto_foldConstants(puVar9,param_4,param_5);
        if (iVar4 == 0) break;
        puVar9 = puVar2;
        if (puVar2 == (undefined4 *)0x0) {
          return 1;
        }
      }
    }
  }
  else {
    iVar4 = crypto_nextToken(0x1e,param_2);
    if ((iVar4 != 0) && (iVar4 = crypto_nextToken(0x1e,extraout_EDX_07), iVar4 != 0)) {
      if ((*piVar10 == 0x1e) &&
         ((*local_c == 0x1e && (iVar4 = crypto_foldConstants(local_c,param_4,param_5), iVar4 == 0)))) {
        return 0;
      }
switchD_681445ba_caseD_6:
      return 1;
    }
  }
  return 0;
}



