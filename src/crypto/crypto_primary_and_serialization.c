// Module: crypto
// Topic: Primary expressions, buffer operations, and decompiler serialization
// Address range: 0x68147880 - 0x68148AE0
// Functions (20):
//   crypto_parsePrimaryExpr
//   crypto_getNodeType
//   crypto_growBuffer
//   crypto_parseOperator
//   crypto_parseString
//   crypto_parseAtom
//   crypto_createUnaryOp
//   crypto_createBinaryOp
//   crypto_getOperandCount
//   crypto_getOperandType
//   crypto_parseNumber
//   crypto_appendLiteral
//   crypto_emitOperand
//   crypto_evalNode
//   crypto_compareByOffset
//   crypto_decompileSwitch
//   crypto_parseAssignment
//   crypto_getTypePrefix
//   crypto_isValidIdentifier
//   crypto_decompileArrayAccess

// ============================================================
// Function: crypto_parsePrimaryExpr (FUN_68147880)
// Address: 68147880
// Size: 1595 bytes
// Params: uint * param_1, uint param_2, uint * param_3
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * crypto_parsePrimaryExpr(uint *param_1,uint param_2,uint *param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined4 *puVar4;
  undefined3 extraout_var_03;
  uint uVar5;
  int *piVar6;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_EDX;
  undefined4 *puVar7;
  ulonglong uVar8;
  undefined4 uVar9;
  int local_10;
  uint local_c;
  undefined4 *local_8;
  
  puVar7 = (undefined4 *)0x0;
  local_8 = (undefined4 *)0x0;
  local_c = 0;
LAB_68147897:
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 8;
  iVar3 = strings_parseExpression(param_1,param_2);
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xfffffff7;
  if ((iVar3 == 0x1d) && (iVar3 = crypto_consumeToken(0x22), puVar7 = local_8, iVar3 == -1)) {
    return (undefined4 *)0x0;
  }
  switch(iVar3) {
  default:
    uVar9 = 0x85;
    goto LAB_68147ea5;
  case 0x17:
    puVar7 = crypto_createNode(param_3,0xfffffffe);
    if (puVar7 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    *puVar7 = 0x18;
    puVar7[9] = 0;
    if (local_8 == (undefined4 *)0x0) {
      puVar4 = puVar7 + 6;
      *puVar4 = 0;
      puVar7[8] = 0;
    }
    else {
      puVar7[6] = local_8;
      puVar4 = local_8 + 10;
      puVar7[8] = 1;
    }
    puVar7[7] = puVar4;
    *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 8;
    bVar2 = strings_compareRange(param_1,param_2,0x18);
    *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xfffffff7;
    if (CONCAT31(extraout_var,bVar2) != 0) goto LAB_68147a4a;
    local_c = 0;
    goto LAB_681479b0;
  case 0x19:
    puVar7 = crypto_createNode(param_3,0xfffffffe);
    if (puVar7 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    *puVar7 = 0x1a;
    if (local_8 == (undefined4 *)0x0) {
      puVar4 = puVar7 + 6;
      *puVar4 = 0;
      puVar7[8] = 0;
    }
    else {
      puVar7[6] = local_8;
      puVar4 = local_8 + 10;
      puVar7[8] = 1;
    }
    puVar7[7] = puVar4;
    bVar2 = strings_compareRange(param_1,param_2,0x1a);
    if (CONCAT31(extraout_var_01,bVar2) != 0) goto LAB_68147c8e;
    goto LAB_68147ac2;
  case 0x1b:
    puVar7 = crypto_createNode(param_3,1);
    if (puVar7 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    uVar5 = *param_3;
    *param_3 = uVar5 & 0xffffffef;
    piVar6 = crypto_parseTokenList(param_2,param_3);
    *param_3 = *param_3 & 0xe0 | uVar5;
    if (piVar6 == (int *)0x0) {
      return (undefined4 *)0x0;
    }
    iVar3 = strings_parseExpression(param_1,param_2);
    if (iVar3 != 0x1c) {
      uVar9 = 0x6c;
      goto LAB_68147ea5;
    }
    *puVar7 = 0x1c;
    puVar7[2] = *(undefined4 *)(param_2 + 8 + *(int *)(param_2 + 0x60) * 0x18);
    puVar7[6] = piVar6;
    break;
  case 0x1d:
  case 0x20:
    goto switchD_681478d7_caseD_1d;
  case 0x1e:
    puVar7 = crypto_createNode(param_3,0);
    if (puVar7 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    *(undefined8 *)(puVar7 + 6) = *(undefined8 *)(param_2 + 0x10 + *(int *)(param_2 + 0x60) * 0x18);
    goto LAB_68147e29;
  case 0x1f:
    local_c = 1;
switchD_681478d7_caseD_1d:
    puVar7 = crypto_createNode(param_3,0);
    if (puVar7 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar7[3] = *(undefined4 *)(param_2 + 0x10 + *(int *)(param_2 + 0x60) * 0x18);
    puVar7[6] = *(undefined4 *)(param_2 + 0x14 + *(int *)(param_2 + 0x60) * 0x18);
    if (iVar3 == 0x1d) {
      puVar7[5] = 0xffffffff;
      puVar7[8] = 0xffffffff;
      puVar7[7] = 0;
      puVar7[9] = 0;
      if ((puVar7[6] == *(int *)(param_1[5] + 0x110)) || (puVar7[6] == *(int *)(param_1[5] + 0x114))
         ) {
        *param_3 = *param_3 | 0x80;
      }
    }
    break;
  case 0x21:
    puVar7 = crypto_createNode(param_3,0);
    if (puVar7 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    puVar7[3] = *(undefined4 *)(param_2 + 0x10 + *(int *)(param_2 + 0x60) * 0x18);
    goto LAB_68147e29;
  case 0x22:
    puVar7 = (undefined4 *)crypto_compileExprFast(param_2,param_1);
    if (puVar7 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    break;
  case 0x35:
    if (puVar7 == (undefined4 *)0x0) goto code_r0x681478e6;
    goto LAB_68147e40;
  case 0x36:
    puVar7 = crypto_createNode(param_3,0);
    if (puVar7 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    uVar8 = strings_floatToUint64(extraout_ECX_00,extraout_EDX);
    puVar7[7] = (int)uVar8;
LAB_68147e29:
    local_c = 1;
    break;
  case 0x3d:
    iVar3 = param_2 + *(int *)(param_2 + 0x60) * 0x18;
    iVar3 = certs_formatString((int)param_1,*(undefined4 *)(iVar3 + 0xc),
                         (uint)*(ushort *)(iVar3 + 8) - (uint)*(ushort *)(iVar3 + 4),&local_10);
    strings_scanToken(param_1,param_2,0,0,0x84);
    xtra_checkAndFlush(param_1,iVar3);
    return (undefined4 *)0x0;
  case -1:
    goto switchD_681478d7_caseD_ffffffff;
  }
  if (local_8 == (undefined4 *)0x0) {
    return puVar7;
  }
  if (local_c == 0) {
    local_8[6] = puVar7;
    return local_8;
  }
LAB_68147e40:
  uVar9 = 0x86;
  goto LAB_68147ea5;
code_r0x681478e6:
  puVar7 = crypto_createNode(param_3,1);
  if (puVar7 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar7[6] = 0;
  local_8 = puVar7;
  uVar8 = strings_floatToUint64(extraout_ECX,*(int *)(param_2 + 0x60) * 3);
  puVar7[7] = (int)uVar8;
  goto LAB_68147897;
LAB_68147ac2:
  do {
    uVar9 = strings_parseExpression(param_1,param_2);
    switch(uVar9) {
    case 0x1a:
      uVar5 = strings_scanToken(param_1,param_2,0,5,0xa1);
      if (uVar5 == 0) {
        return (undefined4 *)0x0;
      }
      goto LAB_68147c8e;
    default:
      uVar9 = 0x83;
      goto LAB_68147ea5;
    case 0x1d:
      iVar3 = *(int *)(param_1[5] + 0xf8);
      iVar1 = *(int *)(param_2 + 0x14 + *(int *)(param_2 + 0x60) * 0x18);
      if ((iVar1 != iVar3) && (iVar1 != *(int *)(param_1[5] + 0x118)))
      goto switchD_68147ad5_caseD_1f;
      local_c = (iVar1 != iVar3) + 0x7b;
      bVar2 = strings_compareRange(param_1,param_2,0x1d);
      if (CONCAT31(extraout_var_02,bVar2) == 0) goto switchD_68147ad5_caseD_1f;
      puVar4 = crypto_createNode(param_3,0xffffffff);
      if (puVar4 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      puVar4[6] = *(undefined4 *)(param_2 + 0x14 + *(int *)(param_2 + 0x60) * 0x18);
      puVar4[7] = 0;
      *(undefined4 *)(param_2 + 0x10 + *(int *)(param_2 + 0x60) * 0x18) = 0;
      *(undefined4 *)(param_2 + *(int *)(param_2 + 0x60) * 0x18) = 0x22;
      crypto_compileExprFast(param_2,param_1);
      goto LAB_68147c11;
    case 0x1e:
      puVar4 = crypto_createNode(param_3,0);
      if (puVar4 != (undefined4 *)0x0) {
        *(undefined8 *)(puVar4 + 6) =
             *(undefined8 *)(param_2 + 0x10 + *(int *)(param_2 + 0x60) * 0x18);
      }
      break;
    case 0x1f:
switchD_68147ad5_caseD_1f:
      puVar4 = crypto_createNode(param_3,0);
      if (puVar4 != (undefined4 *)0x0) {
        puVar4[6] = *(undefined4 *)(param_2 + 0x14 + *(int *)(param_2 + 0x60) * 0x18);
      }
    }
    iVar3 = strings_parseExpression(param_1,param_2);
    if ((iVar3 == 0x1d) && (iVar3 = crypto_consumeToken(6), iVar3 == -1)) {
      return (undefined4 *)0x0;
    }
    if (iVar3 != 6) {
      uVar9 = 0x6a;
      goto LAB_68147ea5;
    }
    local_c = *(uint *)(param_2 + 0x10 + *(int *)(param_2 + 0x60) * 0x18);
    crypto_parseUnary(param_1,param_2,param_3);
LAB_68147c11:
    piVar6 = crypto_createBinaryNode(param_3,param_1,6,local_c);
    if (piVar6 == (int *)0x0) {
      return (undefined4 *)0x0;
    }
    *(int **)puVar7[7] = piVar6;
    puVar7[8] = puVar7[8] + 1;
    puVar7[7] = piVar6 + 10;
    bVar2 = strings_compareRange(param_1,param_2,3);
  } while (CONCAT31(extraout_var_03,bVar2) != 0);
  iVar3 = strings_parseExpression(param_1,param_2);
  if (iVar3 == 0x1a) {
LAB_68147c8e:
    puVar7[2] = *(undefined4 *)(param_2 + 8 + *(int *)(param_2 + 0x60) * 0x18);
    return puVar7;
  }
  uVar9 = 0x6b;
  goto LAB_68147ea5;
LAB_681479b0:
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 8;
  iVar3 = strings_initParser(param_1,param_2);
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xfffffff7;
  if (iVar3 != 0x18) {
    if (iVar3 == 3) {
      strings_compareRange(param_1,param_2,3);
      piVar6 = crypto_createNode(param_3,0);
    }
    else {
      piVar6 = crypto_parseUnary(param_1,param_2,param_3);
    }
    if (piVar6 == (int *)0x0) {
      return (undefined4 *)0x0;
    }
    *(int **)puVar7[7] = piVar6;
    puVar7[8] = puVar7[8] + 1;
    puVar7[7] = piVar6 + 10;
    if (((iVar3 != 3) &&
        (bVar2 = strings_compareRange(param_1,param_2,3), CONCAT31(extraout_var_00,bVar2) == 0)) ||
       (local_c = local_c + 1, 0xffff < local_c)) goto LAB_68147a37;
    goto LAB_681479b0;
  }
  puVar7[9] = 1;
LAB_68147a37:
  iVar3 = strings_parseExpression(param_1,param_2);
  if (iVar3 == 0x18) {
LAB_68147a4a:
    puVar7[2] = *(undefined4 *)(param_2 + 8 + *(int *)(param_2 + 0x60) * 0x18);
    return puVar7;
  }
  uVar9 = 0x69;
LAB_68147ea5:
  strings_scanToken(param_1,param_2,0,0,uVar9);
switchD_681478d7_caseD_ffffffff:
  return (undefined4 *)0x0;
}



// ============================================================
// Function: crypto_getNodeType (FUN_68147f50)
// Address: 68147f50
// Size: 73 bytes
// Params: int param_1
// Return: uint
// Calling convention: __fastcall
// ============================================================

uint __fastcall crypto_getNodeType(int param_1)

{
  byte *in_EAX;
  
  if ((*(uint *)(&DAT_68193cbc + (uint)*in_EAX * 0x10) & 0xf) - 9 < 3) {
    return CONCAT31(CONCAT21(CONCAT11(*(undefined1 *)(param_1 + 1),*(undefined1 *)(param_1 + 2)),
                             *(undefined1 *)(param_1 + 3)),*(undefined1 *)(param_1 + 4));
  }
  return (int)(short)((ushort)*(byte *)(param_1 + 1) << 8) | (uint)*(byte *)(param_1 + 2);
}



// ============================================================
// Function: crypto_growBuffer (FUN_68147fa0)
// Address: 68147fa0
// Size: 191 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_growBuffer(int param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  void *pvVar5;
  uint uVar6;
  int *unaff_ESI;
  
  pvVar5 = (void *)unaff_ESI[2];
  if (pvVar5 == (void *)0x0) {
    iVar2 = unaff_ESI[1];
    iVar3 = *(int *)(iVar2 + 0x10);
    uVar6 = param_1 + *(uint *)(iVar2 + 0x18) & ~*(uint *)(iVar2 + 0x18);
    pvVar5 = *(void **)(iVar3 + 0xc);
    uVar1 = (int)pvVar5 + uVar6;
    if (*(uint *)(iVar3 + 8) < uVar1) {
      pvVar5 = (void *)js_getSlotIndex(iVar2,uVar6);
    }
    else {
      *(uint *)(iVar3 + 0xc) = uVar1;
    }
  }
  else {
    piVar4 = (int *)unaff_ESI[1];
    iVar2 = piVar4[4];
    uVar1 = unaff_ESI[3];
    if (*(int *)(iVar2 + 0xc) == (uVar1 + piVar4[6] & ~piVar4[6]) + (int)pvVar5) {
      uVar6 = (piVar4[6] + uVar1 + param_1 & ~piVar4[6]) + (int)pvVar5;
      if (uVar6 <= *(uint *)(iVar2 + 8)) {
        *(uint *)(iVar2 + 0xc) = uVar6;
        goto LAB_68148036;
      }
      if (pvVar5 == *(void **)(iVar2 + 4)) {
        pvVar5 = (void *)js_resolveProperty(piVar4,(int)pvVar5,uVar1,param_1);
        goto LAB_68148033;
      }
    }
    pvVar5 = js_reallocObject(piVar4,pvVar5,uVar1,param_1);
  }
LAB_68148033:
  unaff_ESI[2] = (int)pvVar5;
LAB_68148036:
  if (unaff_ESI[2] != 0) {
    unaff_ESI[3] = unaff_ESI[3] + param_1;
    return 1;
  }
  xtra_reportError(*unaff_ESI);
  return 0;
}



// ============================================================
// Function: crypto_parseOperator (FUN_68148060)
// Address: 68148060
// Size: 82 bytes
// Params: void * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crypto_parseOperator(void *param_1)

{
  int in_EAX;
  int iVar1;
  size_t unaff_EBX;
  void *_Dst;
  
  iVar1 = (unaff_EBX - *(int *)(in_EAX + 0xc)) + 1 + *(int *)(in_EAX + 0x10);
  if (0 < iVar1) {
    iVar1 = crypto_growBuffer(iVar1);
    if (iVar1 == 0) {
      return -1;
    }
  }
  iVar1 = *(int *)(in_EAX + 0x10);
  *(size_t *)(in_EAX + 0x10) = iVar1 + unaff_EBX;
  _Dst = (void *)(*(int *)(in_EAX + 8) + iVar1);
  memmove(_Dst,param_1,unaff_EBX);
  *(undefined1 *)((int)_Dst + unaff_EBX) = 0;
  return iVar1;
}



// ============================================================
// Function: crypto_parseString (FUN_681480c0)
// Address: 681480c0
// Size: 83 bytes
// Params: char * param_1
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl crypto_parseString(char *param_1)

{
  char cVar1;
  int *in_EAX;
  char *pcVar2;
  char *pcVar3;
  int iVar4;
  
  pcVar2 = (char *)runtime_sprintfAlloc(param_1,(uint *)&stack0x00000008);
  pcVar3 = pcVar2;
  if (pcVar2 != (char *)0x0) {
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    iVar4 = crypto_parseOperator(pcVar2);
    js_freeHandle();
    return iVar4;
  }
  xtra_reportError(*in_EAX);
  return -1;
}



// ============================================================
// Function: crypto_parseAtom (FUN_68148120)
// Address: 68148120
// Size: 512 bytes
// Params: int param_1, short param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crypto_parseAtom(int param_1,short param_2)

{
  ushort *puVar1;
  uint *puVar2;
  int iVar3;
  uint *in_EAX;
  int iVar4;
  uint uVar5;
  undefined1 *puVar6;
  short *psVar7;
  int iVar8;
  char *pcVar9;
  uint *local_c;
  uint *local_8;
  
  iVar3 = *(int *)(param_1 + 0x10);
  if ((param_2 == 0) || (iVar4 = crypto_parseString("%c"), -1 < iVar4)) {
    uVar5 = *in_EAX;
    local_c = (uint *)in_EAX[1];
    if ((uVar5 & 0x40000000) != 0) {
      if ((*local_c & 0x40000000) == 0) {
        if ((int)uVar5 < 0) {
          local_c = (uint *)local_c[1];
        }
        else {
          local_c = (uint *)(local_c[1] + (uVar5 >> 0xf & 0x7fff) * 2);
        }
      }
      else {
        local_c = (uint *)crypto_getStringLen(in_EAX);
      }
    }
    uVar5 = *in_EAX;
    if ((uVar5 & 0x40000000) != 0) {
      uVar5 = (-(uint)((uVar5 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar5;
    }
    puVar2 = (uint *)((int)local_c + uVar5 * 2);
    while (local_c < puVar2) {
      uVar5 = (uint)(ushort)*local_c;
      local_8 = local_c;
      if ((ushort)*local_c < 0x80) {
        while ((((iVar4 = isprint(uVar5), iVar4 != 0 && ((short)uVar5 != param_2)) &&
                ((short)uVar5 != 0x5c)) && ((uVar5 & 0xff00) == 0))) {
          puVar1 = (ushort *)((int)local_8 + 2);
          uVar5 = (uint)*puVar1;
          local_8 = (uint *)((int)local_8 + 2);
          if ((local_8 == puVar2) || (0x7f < *puVar1)) break;
        }
      }
      iVar8 = (int)local_8 - (int)local_c >> 1;
      iVar4 = (iVar8 - *(int *)(param_1 + 0xc)) + 1 + *(int *)(param_1 + 0x10);
      if ((0 < iVar4) && (iVar4 = crypto_growBuffer(iVar4), iVar4 == 0)) {
        return 0;
      }
      puVar6 = (undefined1 *)(*(int *)(param_1 + 8) + *(int *)(param_1 + 0x10));
      *(int *)(param_1 + 0x10) = *(int *)(param_1 + 0x10) + iVar8;
      while (iVar8 = iVar8 + -1, -1 < iVar8) {
        *puVar6 = (char)*local_c;
        local_c = (uint *)((int)local_c + 2);
        puVar6 = puVar6 + 1;
      }
      *puVar6 = 0;
      if (local_8 == puVar2) break;
      psVar7 = certs_findChar((short *)&DAT_68194650,(short)uVar5);
      if (psVar7 == (short *)0x0) {
        pcVar9 = "\\u%04X";
        if ((uVar5 & 0xff00) == 0) {
          pcVar9 = "\\x%02X";
        }
      }
      else {
        pcVar9 = "\\%c";
      }
      iVar4 = crypto_parseString(pcVar9);
      if (iVar4 < 0) {
        return 0;
      }
      local_c = (uint *)((int)local_8 + 2);
    }
    if ((param_2 == 0) || (iVar4 = crypto_parseString("%c"), -1 < iVar4)) {
      return *(int *)(param_1 + 8) + iVar3;
    }
  }
  return 0;
}



// ============================================================
// Function: crypto_createUnaryOp (FUN_68148320)
// Address: 68148320
// Size: 159 bytes
// Params: uint * param_1, undefined4 param_2, short param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * crypto_createUnaryOp(uint *param_1,undefined4 param_2,short param_3)

{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  char *pcVar5;
  uint *puVar6;
  uint *local_1c;
  uint *local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint *local_8;
  
  puVar4 = param_1;
  iVar1 = *(int *)(param_1[0x20] + 0xc);
  puVar6 = param_1 + 0x1c;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_1c = param_1;
  local_18 = puVar6;
  local_8 = puVar6;
  pcVar5 = (char *)crypto_parseAtom((int)&local_1c,param_3);
  if (pcVar5 == (char *)0x0) {
    param_1 = (uint *)0x0;
  }
  else {
    param_1 = xtra_findSymbolByName((uint)param_1,pcVar5);
  }
  puVar2 = (uint *)puVar4[0x20];
  if ((puVar2 != puVar6) && (puVar6 = local_8, iVar1 - puVar2[1] <= puVar2[3] - puVar2[1])) {
    uVar3 = puVar4[0x22];
    puVar2[3] = uVar3 + iVar1 & ~uVar3;
    return param_1;
  }
  js_getPrototype((int *)puVar6,iVar1);
  return param_1;
}



// ============================================================
// Function: crypto_createBinaryOp (FUN_681483c0)
// Address: 681483c0
// Size: 145 bytes
// Params: int param_1, undefined4 param_2, int param_3, int param_4
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * crypto_createBinaryOp(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  undefined **ppuVar3;
  int *piVar4;
  
  piVar4 = (int *)xtra_getPropertyById(param_1,0x40);
  if (piVar4 == (int *)0x0) {
    return (int *)0x0;
  }
  *piVar4 = param_1;
  piVar4[1] = (int)(piVar4 + 5);
  piVar4[2] = 0;
  piVar4[3] = 0;
  piVar4[4] = 0;
  js_setPropertyDirect(piVar4 + 5,param_2,0x100,1);
  piVar4[0xc] = param_3;
  piVar4[0xd] = param_4;
  piVar4[0xe] = 0;
  piVar4[0xf] = 0;
  if (((*(int *)(param_1 + 0x34) != 0) &&
      (iVar1 = *(int *)(*(int *)(param_1 + 0x34) + 0x10), iVar1 != 0)) &&
     (piVar2 = *(int **)(iVar1 + 4), piVar2 != (int *)0x0)) {
    iVar1 = *piVar2;
    ppuVar3 = *(undefined ***)(iVar1 + 4);
    if ((ppuVar3 == &PTR_FUN_68192948) ||
       ((ppuVar3 != (undefined **)0x0 && (*ppuVar3 == PTR_FUN_68192948)))) {
      piVar4[0xf] = iVar1;
    }
  }
  return piVar4;
}



// ============================================================
// Function: crypto_getOperandCount (FUN_68148460)
// Address: 68148460
// Size: 30 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_getOperandCount(undefined4 *param_1)
{
  js_getPrototypeChain((int)(param_1 + 5));
  xtra_checkAndFlush(*param_1,(int)param_1);
  return 0;
}



// ============================================================
// Function: crypto_getOperandType (FUN_68148480)
// Address: 68148480
// Size: 88 bytes
// Params: uint * param_1
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * crypto_getOperandType(uint *param_1)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = *param_1;
  if ((char *)param_1[2] == (char *)0x0) {
    return *(uint **)(*(int *)(uVar1 + 0x14) + 0x1dc);
  }
  puVar2 = xtra_findSymbolByName(uVar1,(char *)param_1[2]);
  if (puVar2 == (uint *)0x0) {
    return (uint *)0x0;
  }
  javascript_resizeSlotTable((int)(param_1 + 5));
  param_1[1] = (uint)(param_1 + 5);
  *param_1 = uVar1;
  param_1[2] = 0;
  param_1[3] = 0;
  param_1[4] = 0;
  return puVar2;
}



// ============================================================
// Function: crypto_parseNumber (FUN_681484e0)
// Address: 681484e0
// Size: 232 bytes
// Params: int * param_1, char * param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl crypto_parseNumber(int *param_1,char *param_2)

{
  char cVar1;
  int iVar2;
  char *pcVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  
  if (*param_2 == '\0') {
    return 0;
  }
  if (*param_2 == '\t') {
    if ((param_1[0xd] != 0) && (iVar2 = crypto_parseString("%*s"), iVar2 < 0)) {
      return -1;
    }
    param_2 = param_2 + 1;
  }
  pcVar5 = (char *)0x0;
  if (param_1[0xd] == 0) {
    pcVar4 = param_2 + 1;
    pcVar3 = param_2;
    do {
      cVar1 = *pcVar3;
      pcVar3 = pcVar3 + 1;
    } while (cVar1 != '\0');
    if (param_2[(int)(pcVar3 + (-1 - (int)pcVar4))] == '\n') {
      param_2 = (char *)xtra_findMethodByName(*param_1,param_2);
      if (param_2 == (char *)0x0) {
        return -1;
      }
      param_2[(int)(pcVar3 + (-1 - (int)pcVar4))] = '\0';
      pcVar5 = param_2;
    }
  }
  pcVar4 = (char *)runtime_sprintfAlloc(param_2,(uint *)&stack0x0000000c);
  if (pcVar5 != (char *)0x0) {
    xtra_checkAndFlush(*param_1,(int)pcVar5);
  }
  if (pcVar4 == (char *)0x0) {
    xtra_reportError(*param_1);
    return -1;
  }
  pcVar5 = pcVar4;
  do {
    cVar1 = *pcVar5;
    pcVar5 = pcVar5 + 1;
  } while (cVar1 != '\0');
  iVar2 = (int)pcVar5 - (int)(pcVar4 + 1);
  iVar6 = crypto_parseOperator(pcVar4);
  if (iVar6 < 0) {
    iVar2 = -1;
  }
  js_freeHandle();
  return iVar2;
}



// ============================================================
// Function: crypto_appendLiteral (FUN_681485d0)
// Address: 681485d0
// Size: 51 bytes
// Params: undefined4 param_1, char * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool crypto_appendLiteral(undefined4 param_1,char *param_2)

{
  char cVar1;
  char *pcVar2;
  int iVar3;
  
  pcVar2 = param_2;
  do {
    cVar1 = *pcVar2;
    pcVar2 = pcVar2 + 1;
  } while (cVar1 != '\0');
  iVar3 = crypto_parseOperator(param_2);
  return -1 < iVar3;
}



// ============================================================
// Function: crypto_emitOperand (FUN_68148610)
// Address: 68148610
// Size: 110 bytes
// Params: undefined4 param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_emitOperand(undefined4 param_1)

{
  uint uVar1;
  int *in_EAX;
  int iVar2;
  undefined1 uVar3;
  int unaff_EBX;
  
  iVar2 = crypto_growBuffer(3);
  if (iVar2 != 0) {
    uVar1 = in_EAX[7];
    if (uVar1 < *(uint *)(*(int *)(in_EAX[8] + 0x38) + 0x20)) {
      *(undefined4 *)(in_EAX[5] + uVar1 * 4) = param_1;
      if (unaff_EBX == 0xfe) {
        uVar3 = 0x35;
      }
      else {
        uVar3 = 0x37;
        if (unaff_EBX != 0xff) {
          uVar3 = (undefined1)unaff_EBX;
        }
      }
      *(undefined1 *)(uVar1 + in_EAX[6]) = uVar3;
      in_EAX[4] = in_EAX[4] + 3;
      in_EAX[7] = uVar1 + 1;
      return 1;
    }
    xtra_reportError(*in_EAX);
  }
  return 0;
}



// ============================================================
// Function: crypto_evalNode (FUN_68148680)
// Address: 68148680
// Size: 109 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall crypto_evalNode(int param_1)

{
  int *piVar1;
  int in_EAX;
  int iVar2;
  
  if (*(int *)(in_EAX + 0x1c) == 0) {
    return 0;
  }
  iVar2 = *(int *)(in_EAX + 0x1c) + -1;
  *(int *)(in_EAX + 0x1c) = iVar2;
  if (((&DAT_68193cbb)[(uint)*(byte *)(*(int *)(in_EAX + 0x18) + iVar2) * 0x10] != 0) &&
     ((byte)(&DAT_68193cbb)[(uint)*(byte *)(*(int *)(in_EAX + 0x18) + iVar2) * 0x10] <
      (byte)(&DAT_68193cbb)[param_1 * 0x10])) {
    piVar1 = (int *)(*(int *)(in_EAX + 0x14) + iVar2 * 4);
    *piVar1 = *piVar1 + -2;
    *(undefined4 *)(in_EAX + 0x10) = *(undefined4 *)(*(int *)(in_EAX + 0x14) + iVar2 * 4);
    iVar2 = crypto_parseString("(%s)");
    return iVar2;
  }
  iVar2 = *(int *)(*(int *)(in_EAX + 0x14) + iVar2 * 4);
  *(int *)(in_EAX + 0x10) = iVar2;
  return iVar2;
}



// ============================================================
// Function: crypto_compareByOffset (FUN_681486f0)
// Address: 681486f0
// Size: 19 bytes
// Params: int param_1, int param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int crypto_compareByOffset(int param_1,int param_2)

{
  return *(int *)(param_1 + 4) - *(int *)(param_2 + 4);
}



// ============================================================
// Function: crypto_decompileSwitch (FUN_68148710)
// Address: 68148710
// Size: 507 bytes
// Params: int param_1, uint param_2, undefined4 param_3, int param_4, int param_5, int param_6
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_decompileSwitch(int param_1,uint param_2,int param_3,int param_4,int param_5,int param_6)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint *puVar8;
  int *piVar9;
  int *unaff_EBX;
  int iVar10;
  int iVar11;
  int local_8;
  
  iVar2 = *unaff_EBX;
  piVar3 = (int *)unaff_EBX[8];
  crypto_evalNode(0);
  crypto_parseNumber(piVar3,"\tswitch (%s) {\n");
  if (param_2 != 0) {
    iVar10 = *(int *)(param_1 + 4) - param_5;
    if (0 < iVar10) {
      piVar3[0xc] = piVar3[0xc] + 2;
      crypto_parseNumber(piVar3,"\tdefault:\n");
      piVar3[0xc] = piVar3[0xc] + 2;
      iVar10 = crypto_evaluateExpr(unaff_EBX,(undefined **)(param_3 + param_5),iVar10);
      if (iVar10 == 0) {
        return 0;
      }
      piVar3[0xc] = piVar3[0xc] + -4;
    }
    uVar5 = 0;
    if (param_6 == 0) {
      local_8 = 0;
    }
    else {
      local_8 = (int)DAT_68194418;
    }
    if (param_2 != 0) {
      piVar9 = (int *)(param_1 + 0xc);
      do {
        iVar10 = piVar9[-2];
        uVar5 = uVar5 + 1;
        iVar6 = param_4;
        if (uVar5 < param_2) {
          iVar6 = *piVar9;
        }
        uVar4 = piVar9[-3];
        if (param_6 == 0) {
          puVar8 = (uint *)certs_hashLookup(iVar2,uVar4);
          if (puVar8 == (uint *)0x0) {
            return 0;
          }
          piVar3[0xc] = piVar3[0xc] + 2;
          if (((byte)uVar4 & 7) == 4) {
            iVar7 = crypto_parseAtom((int)unaff_EBX,0x22);
            if (iVar7 == 0) {
              return 0;
            }
            unaff_EBX[4] = iVar7 - unaff_EBX[2];
          }
          else {
            xtra_getStringValue(puVar8);
          }
          crypto_parseNumber(piVar3,"\tcase %s:\n");
        }
        else {
          cVar1 = (&DAT_68193cb8)[(uint)*(byte *)(((int)uVar4 >> 1) + param_3) * 0x10];
          piVar3[0xc] = piVar3[0xc] + 2;
          iVar11 = ((int)uVar4 >> 1) + (int)cVar1;
          iVar7 = crypto_evaluateExpr(unaff_EBX,(undefined **)(local_8 + param_3),iVar11 - local_8);
          local_8 = iVar11;
          if (iVar7 == 0) {
            return 0;
          }
        }
        piVar3[0xc] = piVar3[0xc] + 2;
        if ((iVar10 <= param_5) && (param_5 < iVar6)) {
          if ((param_5 - iVar10 != 0) &&
             (iVar7 = crypto_evaluateExpr(unaff_EBX,(undefined **)(iVar10 + param_3),param_5 - iVar10),
             iVar10 = param_5, iVar7 == 0)) {
            return 0;
          }
          piVar3[0xc] = piVar3[0xc] + -2;
          crypto_parseNumber(piVar3,"\tdefault:\n");
          piVar3[0xc] = piVar3[0xc] + 2;
        }
        iVar10 = crypto_evaluateExpr(unaff_EBX,(undefined **)(iVar10 + param_3),iVar6 - iVar10);
        if (iVar10 == 0) {
          return 0;
        }
        piVar3[0xc] = piVar3[0xc] + -4;
        piVar9 = piVar9 + 2;
      } while (uVar5 < param_2);
    }
  }
  if (param_5 == param_4) {
    piVar3[0xc] = piVar3[0xc] + 2;
    crypto_parseNumber(piVar3,"\tdefault:\n");
    piVar3[0xc] = piVar3[0xc] + -2;
  }
  crypto_parseNumber(piVar3,"\t}\n");
  return 1;
}



// ============================================================
// Function: crypto_parseAssignment (FUN_68148910)
// Address: 68148910
// Size: 67 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall crypto_parseAssignment(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int in_EAX;
  int *piVar3;
  int unaff_ESI;
  
  iVar1 = *(int *)(in_EAX + 0x3c);
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    for (puVar2 = *(undefined4 **)(iVar1 + 0x24); puVar2 != (undefined4 *)0x0;
        puVar2 = (undefined4 *)puVar2[5]) {
      if ((puVar2[1] == unaff_ESI) && (*(short *)((int)puVar2 + 0x12) == param_2)) {
        return *puVar2;
      }
    }
    if (*(int *)(iVar1 + 0x10) == 0) {
      return 0;
    }
    piVar3 = (int *)(**(uint **)(*(int *)(iVar1 + 0x10) + 4) & 0xfffffff8);
    if (piVar3 == (int *)0x0) break;
    iVar1 = *piVar3;
  }
  return 0;
}



// ============================================================
// Function: crypto_getTypePrefix (FUN_68148960)
// Address: 68148960
// Size: 86 bytes
// Return: undefined *
// Calling convention: __stdcall
// ============================================================

undefined * crypto_getTypePrefix(void)

{
  byte bVar1;
  byte *in_EAX;
  
  if (in_EAX != (byte *)0x0) {
    bVar1 = *in_EAX;
    if ((bVar1 >> 3 < 0x18) && ((bVar1 >> 3 == 6 || ((bVar1 >> 3 < 0x18 && (bVar1 >> 3 == 0x15))))))
    {
      runtime_snprintf(&DAT_68196a0c,8,"%s ");
      return &DAT_68196a0c;
    }
  }
  return "";
}



// ============================================================
// Function: crypto_isValidIdentifier (FUN_681489c0)
// Address: 681489c0
// Size: 278 bytes
// Params: undefined4 param_1, uint * param_2
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall crypto_isValidIdentifier(undefined4 param_1,uint *param_2)

{
  ushort uVar1;
  uint uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  ushort *local_8;
  
  uVar2 = *param_2;
  if ((uVar2 & 0x40000000) == 0) {
    local_8 = (ushort *)param_2[1];
  }
  else {
    uVar6 = (-(uint)((uVar2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar2;
    puVar3 = (uint *)param_2[1];
    if ((*puVar3 & 0x40000000) == 0) {
      if ((int)uVar2 < 0) {
        local_8 = (ushort *)puVar3[1];
        uVar2 = uVar6;
      }
      else {
        local_8 = (ushort *)(puVar3[1] + (uVar2 >> 0xf & 0x7fff) * 2);
        uVar2 = uVar6;
      }
    }
    else {
      local_8 = (ushort *)crypto_getStringLen(param_2);
      uVar2 = uVar6;
    }
  }
  uVar1 = *local_8;
  uVar6 = (uint)uVar1;
  if (((uVar2 != 0) &&
      (((uVar4 = crypto_getStringCapacity(uVar6), (0x43e >> ((byte)uVar4 & 0x1f) & 1U) != 0 || (uVar6 == 0x5f))
       || (uVar6 == 0x24)))) && (uVar1 < 0x80)) {
    iVar5 = isprint(uVar6);
    while (iVar5 != 0) {
      uVar2 = uVar2 - 1;
      if (uVar2 == 0) {
        return 1;
      }
      uVar1 = local_8[1];
      uVar4 = (uint)uVar1;
      local_8 = local_8 + 1;
      uVar6 = crypto_getStringCapacity(uVar4);
      if ((((0x80077e >> ((byte)uVar6 & 0x1f) & 1U) == 0) && (uVar4 != 0x5f)) && (uVar4 != 0x24)) {
        return 0;
      }
      if (0x7f < uVar1) {
        return 0;
      }
      iVar5 = isprint(uVar4);
    }
  }
  return 0;
}



// ============================================================
// Function: crypto_decompileArrayAccess (FUN_68148ae0)
// Address: 68148ae0
// Size: 83 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_decompileArrayAccess(int *param_1,int param_2)

{
  int iVar1;
  
  crypto_parseNumber(param_1,"[%s ");
  if (*(int *)(param_2 + 0x18) != 0) {
    iVar1 = crypto_parseAtom((int)param_1,0);
    if (iVar1 == 0) {
      return 0;
    }
  }
  crypto_parseNumber(param_1,"]");
  return 1;
}



