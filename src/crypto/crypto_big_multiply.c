// Source: decompiled_functions.c
// Module: crypto
// Address range: 0x68145cc0 - 0x68145cc0
// Functions (1):
//   crypto_bigMultiply

// ============================================================
// Function: crypto_bigMultiply (FUN_68145cc0)
// Address: 68145cc0
// Size: 4808 bytes
// Params: uint * param_1, int * param_2, uint * param_3
// Return: int *
// Calling convention: __stdcall
// ============================================================

int * crypto_bigMultiply(uint *param_1,int *param_2,uint *param_3)

{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  int *piVar3;
  undefined4 *puVar4;
  undefined3 extraout_var_03;
  undefined4 *puVar5;
  undefined3 extraout_var_04;
  uint uVar6;
  int *piVar7;
  int *piVar8;
  int *piVar9;
  undefined4 uVar10;
  undefined4 local_38 [6];
  int local_20;
  int local_18;
  int local_14;
  int *local_10;
  int *local_c;
  int *local_8;
  
  piVar7 = param_2;
  param_2[0x1f] = param_2[0x1f] | 8;
  iVar2 = strings_parseExpression(param_1,(int)param_2);
  param_2[0x1f] = param_2[0x1f] & 0xfffffff7;
  if ((iVar2 == 0x1d) && (iVar2 = crypto_consumeToken(0x22), iVar2 == -1)) {
    return (int *)0x0;
  }
  switch(iVar2) {
  default:
    local_18 = param_2[param_2[0x18] * 6];
    strings_resetScanner((int)param_2);
    piVar7 = crypto_parseTokenList((int)param_2,param_3);
    if (piVar7 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar2 = strings_initParser(param_1,(int)param_2);
    if (iVar2 != 6) {
      if (((uint)*(ushort *)((int)piVar7 + 10) == param_2[0x1a]) &&
         (iVar2 = crypto_peekToken(local_18), iVar2 == 0)) {
        return (int *)0x0;
      }
      local_8 = crypto_createNode(param_3,1);
      if (local_8 == (int *)0x0) {
        return (int *)0x0;
      }
      *local_8 = 2;
      local_8[1] = piVar7[1];
      local_8[2] = piVar7[2];
      local_8[6] = (int)piVar7;
      goto LAB_68146f7b;
    }
    if (*piVar7 == 0x1d) {
      piVar8 = (int *)param_3[2];
      iVar2 = piVar7[6];
      while( true ) {
        if (piVar8 == (int *)0x0) {
          strings_parseExpression(param_1,(int)param_2);
          js_initPropertySlot((int)param_3,local_38,1,0xffffffff);
          local_20 = iVar2;
          piVar8 = crypto_bigMultiply(param_1,param_2,param_3);
          if (piVar8 == (int *)0x0) {
            return (int *)0x0;
          }
          js_freezeObject((int)param_3);
          *piVar7 = 6;
          iVar2 = piVar8[2];
          piVar7[7] = (int)piVar8;
          piVar7[2] = iVar2;
          return piVar7;
        }
        if ((*piVar8 == 1) && (piVar8[6] == iVar2)) break;
        piVar8 = (int *)piVar8[7];
      }
      uVar10 = 0x7e;
    }
    else {
      uVar10 = 0x7d;
    }
    goto LAB_68145e2b;
  case 1:
  case 2:
    piVar7 = crypto_createNode(param_3,1);
    if (piVar7 != (int *)0x0) {
      *piVar7 = 2;
      piVar7[6] = 0;
      return piVar7;
    }
    break;
  case 0x19:
    js_initPropertySlot((int)param_3,local_38,0,0xffffffff);
    local_8 = crypto_parseExprPrimary(param_1,param_2,param_3);
    if (local_8 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar2 = strings_parseExpression(param_1,(int)param_2);
    if (iVar2 == 0x1a) {
      js_freezeObject((int)param_3);
      return local_8;
    }
    uVar10 = 0x65;
    goto LAB_68145e2b;
  case 0x22:
    local_8 = (int *)crypto_compileExpr((uint)param_2,param_1);
    if (local_8 == (int *)0x0) {
      return (int *)0x0;
    }
    if (((uint)*(ushort *)((int)local_8 + 10) == param_2[0x1a]) &&
       (iVar2 = crypto_peekToken(0x22), iVar2 == 0)) {
      return (int *)0x0;
    }
    goto LAB_68146f7b;
  case 0x23:
    local_8 = crypto_createNode(param_3,0xfffffffe);
    if (local_8 == (int *)0x0) {
      return (int *)0x0;
    }
    local_8[6] = 0;
    local_8[7] = (int)(local_8 + 6);
    local_8[8] = 0;
    bVar1 = strings_compareRange(param_1,(int)param_2,0x11);
    if (CONCAT31(extraout_var,bVar1) == 0) {
      do {
        iVar2 = strings_parseExpression(param_1,(int)param_2);
        if (iVar2 != 0x1d) {
          uVar10 = 0x4f;
          goto LAB_68145e2b;
        }
        puVar5 = crypto_createNode(param_3,0xffffffff);
        if (puVar5 == (undefined4 *)0x0) {
          return (int *)0x0;
        }
        puVar5[3] = 0x3b;
        iVar2 = param_2[param_2[0x18] * 6 + 5];
        puVar5[7] = 0;
        puVar5[9] = 0;
        puVar5[6] = iVar2;
        puVar5[8] = 0xffffffff;
        *(undefined4 **)local_8[7] = puVar5;
        local_8[8] = local_8[8] + 1;
        local_8[7] = (int)(puVar5 + 10);
        bVar1 = strings_compareRange(param_1,(int)param_2,3);
      } while (CONCAT31(extraout_var_00,bVar1) != 0);
    }
    else {
      puVar5 = crypto_createNode(param_3,0);
      if (puVar5 == (undefined4 *)0x0) {
        return (int *)0x0;
      }
      *(undefined4 **)local_8[7] = puVar5;
      local_8[8] = local_8[8] + 1;
      local_8[7] = (int)(puVar5 + 10);
    }
    local_8[2] = *(int *)(local_8[7] + -0x20);
    if (((uint)*(ushort *)((int)local_8 + 10) == param_2[0x1a]) &&
       (iVar2 = crypto_peekToken(-1), iVar2 == 0)) {
      return (int *)0x0;
    }
    goto LAB_68145daa;
  case 0x24:
    piVar7 = crypto_createNode(param_3,0xfffffffe);
    if (piVar7 == (int *)0x0) {
      return (int *)0x0;
    }
    piVar7[6] = 0;
    piVar7[7] = (int)(piVar7 + 6);
    piVar7[8] = 0;
    local_8 = piVar7;
    do {
      puVar5 = crypto_parseFuncDef(param_3);
      if (puVar5 == (undefined4 *)0x0) {
        return (int *)0x0;
      }
      *(undefined4 **)piVar7[7] = puVar5;
      piVar7[8] = piVar7[8] + 1;
      piVar7[7] = (int)(puVar5 + 10);
      bVar1 = strings_compareRange(param_1,(int)param_2,3);
    } while (CONCAT31(extraout_var_01,bVar1) != 0);
    piVar7[2] = *(int *)(piVar7[7] + -0x20);
    if (((uint)*(ushort *)((int)piVar7 + 10) == param_2[0x1a]) &&
       (iVar2 = crypto_peekToken(-1), iVar2 == 0)) {
      return (int *)0x0;
    }
LAB_68145daa:
    *param_3 = *param_3 | 0x80;
LAB_68146f7b:
    strings_compareRange(param_1,(int)param_2,2);
    return local_8;
  case 0x25:
    piVar7 = crypto_createNode(param_3,3);
    if ((piVar7 != (int *)0x0) && (local_c = crypto_parseForIn(param_3), local_c != (int *)0x0)) {
      js_initPropertySlot((int)param_3,local_38,2,0xffffffff);
      piVar8 = crypto_bigMultiply(param_1,param_2,param_3);
      if (piVar8 != (int *)0x0) {
        bVar1 = strings_compareRange(param_1,(int)param_2,0x26);
        if (CONCAT31(extraout_var_02,bVar1) == 0) {
          piVar3 = (int *)0x0;
          piVar7[2] = piVar8[2];
        }
        else {
          local_38[0] = 3;
          piVar3 = crypto_bigMultiply(param_1,param_2,param_3);
          if (piVar3 == (int *)0x0) {
            return (int *)0x0;
          }
          piVar7[2] = piVar3[2];
        }
        js_freezeObject((int)param_3);
        piVar7[7] = (int)piVar8;
        piVar7[8] = (int)piVar3;
        piVar7[6] = (int)local_c;
        return piVar7;
      }
    }
    break;
  case 0x27:
    local_18 = 0;
    local_8 = crypto_createNode(param_3,2);
    if (local_8 == (int *)0x0) {
      return (int *)0x0;
    }
    iVar2 = strings_parseExpression(param_1,(int)param_2);
    if (iVar2 == 0x1b) {
      local_c = crypto_parseTokenList((int)param_2,param_3);
      if (local_c == (int *)0x0) {
        return (int *)0x0;
      }
      iVar2 = strings_parseExpression(param_1,(int)param_2);
      if (iVar2 == 0x1c) {
        iVar2 = strings_parseExpression(param_1,(int)param_2);
        if (iVar2 == 0x19) {
          puVar5 = crypto_createNode(param_3,0xfffffffe);
          if (puVar5 == (undefined4 *)0x0) {
            return (int *)0x0;
          }
          puVar5[6] = 0;
          puVar5[7] = puVar5 + 6;
          puVar5[8] = 0;
          js_initPropertySlot((int)param_3,local_38,4,0xffffffff);
          local_14 = strings_parseExpression(param_1,(int)param_2);
          if (local_14 != 0x1a) {
            do {
              if (local_14 == -1) {
                return (int *)0x0;
              }
              if (local_14 != 0x28) {
                if (local_14 != 0x29) {
                  strings_scanToken(param_1,(int)param_2,0,0,0x74);
                  return (int *)0x0;
                }
                if (local_18 != 0) {
                  strings_scanToken(param_1,(int)param_2,0,0,0x72);
                  return (int *)0x0;
                }
                local_18 = 1;
              }
              local_10 = crypto_createNode(param_3,2);
              if (local_10 == (int *)0x0) {
                return (int *)0x0;
              }
              if (local_14 == 0x29) {
                local_10[6] = 0;
              }
              else {
                piVar7 = crypto_parseTokenList((int)param_2,param_3);
                local_10[6] = (int)piVar7;
                if (piVar7 == (int *)0x0) {
                  return (int *)0x0;
                }
              }
              *(int **)puVar5[7] = local_10;
              puVar5[8] = puVar5[8] + 1;
              puVar5[7] = local_10 + 10;
              if (puVar5[8] == 0x10000) {
                uVar10 = 0x73;
                goto LAB_68145e2b;
              }
              iVar2 = strings_parseExpression(param_1,(int)param_2);
              if (iVar2 != 6) {
                uVar10 = 0x53;
                goto LAB_68145e2b;
              }
              puVar4 = crypto_createNode(param_3,0xfffffffe);
              if (puVar4 == (undefined4 *)0x0) {
                return (int *)0x0;
              }
              *puVar4 = 0x19;
              puVar4[6] = 0;
              puVar4[7] = puVar4 + 6;
              puVar4[8] = 0;
              iVar2 = strings_initParser(param_1,(int)param_2);
              while (((iVar2 != 0x1a && (iVar2 != 0x28)) && (iVar2 != 0x29))) {
                if (iVar2 == -1) {
                  return (int *)0x0;
                }
                piVar7 = crypto_bigMultiply(param_1,param_2,param_3);
                if (piVar7 == (int *)0x0) {
                  return (int *)0x0;
                }
                puVar4[2] = piVar7[2];
                *(int **)puVar4[7] = piVar7;
                puVar4[8] = puVar4[8] + 1;
                puVar4[7] = piVar7 + 10;
                iVar2 = strings_initParser(param_1,(int)param_2);
              }
              if (puVar4[6] != 0) {
                puVar4[1] = *(undefined4 *)(puVar4[6] + 4);
              }
              local_10[2] = puVar4[2];
              local_10[7] = (int)puVar4;
              local_14 = strings_parseExpression(param_1,(int)param_2);
            } while (local_14 != 0x1a);
            local_14 = 0x1a;
          }
          js_freezeObject((int)param_3);
          iVar2 = param_2[param_2[0x18] * 6 + 2];
          puVar5[2] = iVar2;
          local_8[7] = (int)puVar5;
          local_8[2] = iVar2;
          local_8[6] = (int)local_c;
          return local_8;
        }
        uVar10 = 0x52;
      }
      else {
        uVar10 = 0x51;
      }
    }
    else {
      uVar10 = 0x50;
    }
    goto LAB_68145e2b;
  case 0x2a:
    piVar7 = crypto_createNode(param_3,2);
    if (piVar7 != (int *)0x0) {
      js_initPropertySlot((int)param_3,local_38,0xd,0xffffffff);
      piVar8 = crypto_parseForIn(param_3);
      if (piVar8 != (int *)0x0) {
        piVar7[6] = (int)piVar8;
        piVar8 = crypto_bigMultiply(param_1,param_2,param_3);
        if (piVar8 != (int *)0x0) {
          js_freezeObject((int)param_3);
          iVar2 = piVar8[2];
          piVar7[7] = (int)piVar8;
          piVar7[2] = iVar2;
          return piVar7;
        }
      }
    }
    break;
  case 0x2b:
    piVar7 = crypto_createNode(param_3,2);
    if (piVar7 != (int *)0x0) {
      local_8 = piVar7;
      js_initPropertySlot((int)param_3,local_38,10,0xffffffff);
      piVar8 = crypto_bigMultiply(param_1,param_2,param_3);
      if (piVar8 != (int *)0x0) {
        piVar7[6] = (int)piVar8;
        iVar2 = strings_parseExpression(param_1,(int)param_2);
        if (iVar2 != 0x2a) {
          strings_scanToken(param_1,(int)param_2,0,0,0x54);
          return (int *)0x0;
        }
        piVar8 = crypto_parseForIn(param_3);
        if (piVar8 != (int *)0x0) {
          js_freezeObject((int)param_3);
          piVar7[2] = piVar8[2];
          piVar7[7] = (int)piVar8;
          goto LAB_68146f7b;
        }
      }
    }
    break;
  case 0x2c:
    local_8 = crypto_createNode(param_3,2);
    if (local_8 == (int *)0x0) {
      return (int *)0x0;
    }
    js_initPropertySlot((int)param_3,local_38,0xb,0xffffffff);
    iVar2 = strings_parseExpression(param_1,(int)param_2);
    if (iVar2 != 0x1b) {
      strings_scanToken(param_1,(int)param_2,0,0,0x55);
      return (int *)0x0;
    }
    iVar2 = strings_initParser(param_1,(int)param_2);
    if (iVar2 == 2) {
      local_c = (int *)0x0;
LAB_681464ff:
      iVar2 = strings_parseExpression(param_1,(int)param_2);
      if (iVar2 != 2) {
        strings_scanToken(param_1,(int)param_2,0,0,0x56);
        return (int *)0x0;
      }
      iVar2 = strings_initParser(param_1,(int)param_2);
      if (iVar2 == 2) {
        param_2 = (int *)0x0;
      }
      else {
        param_2 = crypto_parseTokenList((int)param_2,param_3);
        if (param_2 == (int *)0x0) {
          return (int *)0x0;
        }
      }
      iVar2 = strings_parseExpression(param_1,(int)piVar7);
      if (iVar2 != 2) {
        strings_scanToken(param_1,(int)piVar7,0,0,0x57);
        return (int *)0x0;
      }
      iVar2 = strings_initParser(param_1,(int)piVar7);
      if (iVar2 == 0x1c) {
        local_10 = (int *)0x0;
      }
      else {
        local_10 = crypto_parseTokenList((int)piVar7,param_3);
        if (local_10 == (int *)0x0) {
          return (int *)0x0;
        }
      }
      piVar8 = crypto_createNode(param_3,3);
      if (piVar8 == (int *)0x0) {
        return (int *)0x0;
      }
      piVar8[6] = (int)local_c;
      *piVar8 = 0x3d;
      piVar8[3] = 0;
      piVar8[7] = (int)param_2;
      piVar8[8] = (int)local_10;
    }
    else {
      *param_3 = *param_3 | 0x10;
      if (iVar2 == 0x30) {
        strings_parseExpression(param_1,(int)param_2);
        piVar8 = crypto_parseStatementBody((int)param_2,param_3);
      }
      else {
        piVar8 = crypto_parseTokenList((int)param_2,param_3);
      }
      *param_3 = *param_3 & 0xffffffef;
      if (piVar8 == (int *)0x0) {
        return (int *)0x0;
      }
      local_c = piVar8;
      bVar1 = strings_compareRange(param_1,(int)param_2,0x2f);
      if (CONCAT31(extraout_var_03,bVar1) == 0) goto LAB_681464ff;
      local_38[0] = 0xc;
      iVar2 = *piVar8;
      if (iVar2 == 0x30) {
        if ((1 < (uint)piVar8[8]) || (piVar8[3] == 0x7e)) {
LAB_68146499:
          strings_scanToken(param_1,(int)param_2,0,0,0x75);
          return (int *)0x0;
        }
      }
      else if (((iVar2 != 0x1d) && (iVar2 != 0x16)) && (iVar2 != 0x17)) goto LAB_68146499;
      if (iVar2 == 0x30) {
        piVar8 = (int *)piVar8[6];
      }
      if ((*piVar8 == 0x1d) && (piVar8[6] == *(int *)(param_1[5] + 0xd8))) {
        *param_3 = *param_3 | 0x80;
      }
      crypto_parseTokenList((int)param_2,param_3);
      piVar8 = crypto_createBinaryNode(param_3,param_1,0x2f,0);
      if (piVar8 == (int *)0x0) {
        return (int *)0x0;
      }
    }
    local_8[6] = (int)piVar8;
    iVar2 = strings_parseExpression(param_1,(int)piVar7);
    if (iVar2 != 0x1c) {
      strings_scanToken(param_1,(int)piVar7,0,0,0x58);
      return (int *)0x0;
    }
    piVar8 = crypto_bigMultiply(param_1,piVar7,param_3);
    piVar7 = local_8;
    if (piVar8 != (int *)0x0) {
      local_8[7] = (int)piVar8;
      js_freezeObject((int)param_3);
      piVar7[2] = piVar8[2];
      return piVar7;
    }
    break;
  case 0x2d:
    piVar7 = crypto_createNode(param_3,0);
    if ((piVar7 != (int *)0x0) && (local_8 = piVar7, iVar2 = crypto_parseFunctionArgs(param_1), iVar2 != 0)) {
      piVar8 = (int *)param_3[2];
      if (piVar7[6] == 0) {
        while( true ) {
          if (piVar8 == (int *)0x0) {
            strings_scanToken(param_1,(int)param_2,0,0,0x7a);
            return (int *)0x0;
          }
          if ((9 < *piVar8) || (*piVar8 == 4)) break;
          piVar8 = (int *)piVar8[7];
        }
      }
      else {
        while( true ) {
          if (piVar8 == (int *)0x0) {
            strings_scanToken(param_1,(int)param_2,0,0,0x79);
            return (int *)0x0;
          }
          if ((*piVar8 == 1) && (piVar8[6] == piVar7[6])) break;
          piVar8 = (int *)piVar8[7];
        }
        piVar7[2] = param_2[param_2[0x18] * 6 + 2];
      }
      goto LAB_68146f7b;
    }
    break;
  case 0x2e:
    piVar7 = crypto_createNode(param_3,0);
    if ((piVar7 != (int *)0x0) && (local_8 = piVar7, iVar2 = crypto_parseFunctionArgs(param_1), iVar2 != 0)) {
      piVar8 = (int *)param_3[2];
      if (piVar7[6] == 0) {
        while( true ) {
          if (piVar8 == (int *)0x0) {
            strings_scanToken(param_1,(int)param_2,0,0,0x7b);
            return (int *)0x0;
          }
          if (9 < *piVar8) break;
          piVar8 = (int *)piVar8[7];
        }
      }
      else {
        piVar3 = (int *)0x0;
        while( true ) {
          if (piVar8 == (int *)0x0) {
            strings_scanToken(param_1,(int)param_2,0,0,0x79);
            return (int *)0x0;
          }
          piVar9 = piVar8;
          if ((*piVar8 == 1) && (piVar9 = piVar3, piVar8[6] == piVar7[6])) break;
          piVar8 = (int *)piVar8[7];
          piVar3 = piVar9;
        }
        if ((piVar3 == (int *)0x0) || (*piVar3 < 10)) {
          strings_scanToken(param_1,(int)param_2,0,0,0x7b);
          return (int *)0x0;
        }
        piVar7[2] = param_2[param_2[0x18] * 6 + 2];
      }
      goto LAB_68146f7b;
    }
    break;
  case 0x30:
    local_8 = crypto_parseStatementBody((int)param_2,param_3);
    if ((local_8 != (int *)0x0) &&
       (((uint)*(ushort *)((int)local_8 + 10) != param_2[0x1a] ||
        (iVar2 = crypto_peekToken(-1), iVar2 != 0)))) {
      local_8[9] = 1;
      goto LAB_68146f7b;
    }
    break;
  case 0x31:
    local_8 = crypto_createNode(param_3,2);
    if (local_8 != (int *)0x0) {
      iVar2 = strings_parseExpression(param_1,(int)param_2);
      if (iVar2 != 0x1b) {
        strings_scanToken(param_1,(int)param_2,0,0,99);
        return (int *)0x0;
      }
      piVar7 = crypto_parseTokenList((int)param_2,param_3);
      if (piVar7 != (int *)0x0) {
        iVar2 = strings_parseExpression(param_1,(int)param_2);
        if (iVar2 != 0x1c) {
          strings_scanToken(param_1,(int)param_2,0,0,100);
          return (int *)0x0;
        }
        local_8[6] = (int)piVar7;
        js_initPropertySlot((int)param_3,local_38,5,0xffffffff);
        piVar7 = crypto_bigMultiply(param_1,param_2,param_3);
        if (piVar7 != (int *)0x0) {
          js_freezeObject((int)param_3);
          uVar6 = strings_scanToken(param_1,(int)param_2,0,5,0x9e);
          if (uVar6 != 0) {
            local_8[2] = piVar7[2];
            local_8[7] = (int)piVar7;
            *param_3 = *param_3 | 0x80;
            return local_8;
          }
        }
      }
    }
    break;
  case 0x32:
    if ((*param_3 & 2) != 0) {
      local_8 = crypto_createNode(param_3,1);
      if (local_8 == (int *)0x0) {
        return (int *)0x0;
      }
      param_2[0x1f] = param_2[0x1f] | 8;
      iVar2 = strings_beginParse(param_1,(int)param_2);
      param_2[0x1f] = param_2[0x1f] & 0xfffffff7;
      if (iVar2 == -1) {
        return (int *)0x0;
      }
      if ((((iVar2 == 0) || (iVar2 == 1)) || (iVar2 == 2)) || (iVar2 == 0x1a)) {
        *param_3 = *param_3 | 8;
        local_8[6] = 0;
      }
      else {
        piVar7 = crypto_parseTokenList((int)param_2,param_3);
        if (piVar7 == (int *)0x0) {
          return (int *)0x0;
        }
        if (((uint)*(ushort *)((int)piVar7 + 10) == param_2[0x1a]) &&
           (iVar2 = crypto_peekToken(-1), iVar2 == 0)) {
          return (int *)0x0;
        }
        *param_3 = *param_3 | 4;
        local_8[2] = piVar7[2];
        local_8[6] = (int)piVar7;
      }
      if ((((param_1[0x59] & 1) != 0) && ((~*param_3 & 0xc) == 0)) &&
         (iVar2 = crypto_reportLabelError(), iVar2 == 0)) {
        return (int *)0x0;
      }
      goto LAB_68146f7b;
    }
    uVar10 = 0x7c;
    goto LAB_68145e2b;
  case 0x37:
    local_8 = crypto_createNode(param_3,3);
    local_8[3] = 0;
    iVar2 = strings_parseExpression(param_1,(int)param_2);
    if (iVar2 != 0x19) {
      strings_scanToken(param_1,(int)param_2,0,0,0x59);
      return (int *)0x0;
    }
    js_initPropertySlot((int)param_3,local_38,6,0xffffffff);
    puVar5 = crypto_parseExprPrimary(param_1,param_2,param_3);
    local_8[6] = (int)puVar5;
    if (puVar5 == (undefined4 *)0x0) {
      return (int *)0x0;
    }
    iVar2 = strings_parseExpression(param_1,(int)param_2);
    if (iVar2 == 0x1a) {
      js_freezeObject((int)param_3);
      local_10 = local_8;
      iVar2 = strings_initParser(param_1,(int)param_2);
      while (iVar2 == 0x38) {
        if ((local_10 != local_8) && (*(int *)(local_10[6] + 0x1c) == 0)) {
          strings_scanToken(param_1,(int)param_2,0,0,0x76);
          return (int *)0x0;
        }
        strings_parseExpression(param_1,(int)param_2);
        piVar7 = crypto_createNode(param_3,3);
        if (piVar7 == (int *)0x0) {
          return (int *)0x0;
        }
        iVar2 = strings_parseExpression(param_1,(int)param_2);
        if (iVar2 != 0x1b) {
          uVar10 = 0x5b;
          goto LAB_68145e2b;
        }
        iVar2 = strings_parseExpression(param_1,(int)param_2);
        if (iVar2 != 0x1d) {
          uVar10 = 0x5c;
          goto LAB_68145e2b;
        }
        puVar5 = crypto_createNode(param_3,0xffffffff);
        if (puVar5 == (undefined4 *)0x0) {
          return (int *)0x0;
        }
        puVar5[6] = param_2[param_2[0x18] * 6 + 5];
        puVar5[7] = 0;
        iVar2 = strings_initParser(param_1,(int)param_2);
        if (iVar2 == 0x25) {
          strings_parseExpression(param_1,(int)param_2);
          piVar8 = crypto_parseTokenList((int)param_2,param_3);
          puVar5[7] = piVar8;
          if (piVar8 == (int *)0x0) {
            return (int *)0x0;
          }
        }
        piVar7[6] = (int)puVar5;
        iVar2 = strings_parseExpression(param_1,(int)param_2);
        if (iVar2 != 0x1c) {
          strings_scanToken(param_1,(int)param_2,0,0,0x5d);
          return (int *)0x0;
        }
        iVar2 = strings_parseExpression(param_1,(int)param_2);
        if (iVar2 != 0x19) {
          strings_scanToken(param_1,(int)param_2,0,0,0x5e);
          return (int *)0x0;
        }
        js_initPropertySlot((int)param_3,local_38,7,0xffffffff);
        local_20 = puVar5[6];
        puVar5 = crypto_parseExprPrimary(param_1,param_2,param_3);
        piVar7[8] = (int)puVar5;
        if (puVar5 == (undefined4 *)0x0) {
          return (int *)0x0;
        }
        iVar2 = strings_parseExpression(param_1,(int)param_2);
        if (iVar2 != 0x1a) {
          strings_scanToken(param_1,(int)param_2,0,0,0x5f);
          return (int *)0x0;
        }
        js_freezeObject((int)param_3);
        local_10[7] = (int)piVar7;
        local_10 = piVar7;
        iVar2 = strings_initParser(param_1,(int)param_2);
      }
      local_10[7] = 0;
      bVar1 = strings_compareRange(param_1,(int)param_2,0x39);
      if (CONCAT31(extraout_var_04,bVar1) == 0) {
        local_8[8] = 0;
LAB_68146929:
        if ((local_8[7] != 0) || (local_8[8] != 0)) {
          param_3[1] = param_3[1] + 1;
          return local_8;
        }
        uVar10 = 0x62;
      }
      else {
        param_3[1] = param_3[1] + 1;
        iVar2 = strings_parseExpression(param_1,(int)param_2);
        if (iVar2 == 0x19) {
          js_initPropertySlot((int)param_3,local_38,8,0xffffffff);
          puVar5 = crypto_parseExprPrimary(param_1,param_2,param_3);
          local_8[8] = (int)puVar5;
          if (puVar5 == (undefined4 *)0x0) {
            return (int *)0x0;
          }
          iVar2 = strings_parseExpression(param_1,(int)param_2);
          if (iVar2 == 0x1a) {
            js_freezeObject((int)param_3);
            goto LAB_68146929;
          }
          uVar10 = 0x61;
        }
        else {
          uVar10 = 0x60;
        }
      }
    }
    else {
      uVar10 = 0x5a;
    }
    goto LAB_68145e2b;
  case 0x38:
    uVar10 = 0x77;
    goto LAB_68145e2b;
  case 0x39:
    uVar10 = 0x78;
LAB_68145e2b:
    strings_scanToken(param_1,(int)param_2,0,0,uVar10);
    break;
  case 0x3a:
    local_8 = crypto_createNode(param_3,1);
    if (((local_8 != (int *)0x0) &&
        (piVar7 = crypto_parseTokenList((int)param_2,param_3), piVar7 != (int *)0x0)) &&
       ((local_8[2] = piVar7[2], (uint)*(ushort *)((int)local_8 + 10) != param_2[0x1a] ||
        (iVar2 = crypto_peekToken(-1), iVar2 != 0)))) {
      local_8[3] = 0x6e;
      local_8[6] = (int)piVar7;
      goto LAB_68146f7b;
    }
    break;
  case 0x3c:
    iVar2 = crypto_peekToken(-1);
    if ((iVar2 != 0) && (piVar7 = crypto_createNode(param_3,0), piVar7 != (int *)0x0)) {
      *piVar7 = 0x3c;
      *param_3 = *param_3 | 0x80;
      return piVar7;
    }
    break;
  case -1:
    break;
  }
  return (int *)0x0;
}



