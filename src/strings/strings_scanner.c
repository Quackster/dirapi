// Module: strings
// Topic: Lexer/scanner - tokenization, character reading, source line parsing
// Address range: 0x68163550 - 0x68166a30
// Functions (19):
//   strings_registerKeywords (FUN_68163550)
//   strings_createParser
//   strings_allocParser (FUN_68163630)
//   strings_setParserMode
//   strings_scanToken (FUN_68163810)
//   strings_initParser
//   strings_beginParse
//   strings_parseExpression
//   strings_peekChar
//   strings_readLine (FUN_68166430)
//   strings_appendToken
//   strings_peekNextChar
//   strings_matchAndEmit
//   strings_emitToken
//   strings_getCharAt
//   strings_matchKeyword
//   strings_growParserBuffer (FUN_681666a0)
//   strings_parseUnicodeEscape (FUN_68166860)
//   strings_resetScanner

// ============================================================
// Function: strings_registerKeywords (FUN_68163550)
// Address: 68163550
// Size: 99 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_registerKeywords(int param_1)

{
  size_t sVar1;
  int iVar2;
  uint uVar3;
  undefined **local_8;
  
  local_8 = &PTR_s_break_68194b70;
  while( true ) {
    if (*local_8 == (undefined *)0x0) {
      return 1;
    }
    uVar3 = 1;
    sVar1 = strlen(*local_8);
    iVar2 = javascript_registerAtom(param_1,*local_8,sVar1,uVar3);
    if (iVar2 == 0) break;
    *(undefined ***)(iVar2 + 0xc) = local_8;
    local_8 = local_8 + 4;
  }
  return 0;
}



// ============================================================
// Function: strings_createParser (FUN_681635c0)
// Address: 681635c0
// Size: 97 bytes
// Params: int param_1, int param_2, int param_3, undefined4 param_4, undefined4 param_5, int param_6
// Return: void *
// Calling convention: __stdcall
// ============================================================

void * strings_createParser(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5,
                   int param_6)

{
  void *pvVar1;
  
  pvVar1 = strings_allocParser(param_1,param_2,param_3);
  if (pvVar1 == (void *)0x0) {
    pvVar1 = (void *)0x0;
  }
  else {
    *(undefined4 *)((int)pvVar1 + 0xac) = param_4;
    *(undefined4 *)((int)pvVar1 + 0x68) = param_5;
    if (param_6 != 0) {
      *(int *)(param_6 + 0xc) = *(int *)(param_6 + 0xc) + 1;
    }
    *(int *)((int)pvVar1 + 0xb4) = param_6;
  }
  return pvVar1;
}



// ============================================================
// Function: strings_allocParser (FUN_68163630)
// Address: 68163630
// Size: 312 bytes
// Params: int param_1, int param_2, int param_3
// Return: void *
// Calling convention: __stdcall
// ============================================================

void * strings_allocParser(int param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_14;
  
  iVar2 = *(int *)(param_1 + 0x80);
  uVar1 = *(int *)(param_1 + 0x88) + 0x2c8U & ~*(uint *)(param_1 + 0x88);
  local_14 = *(void **)(iVar2 + 0xc);
  uVar3 = (int)local_14 + uVar1;
  if (*(uint *)(iVar2 + 8) < uVar3) {
    local_14 = (void *)js_getSlotIndex(param_1 + 0x70,uVar1);
  }
  else {
    *(uint *)(iVar2 + 0xc) = uVar3;
  }
  if (local_14 == (void *)0x0) {
    xtra_reportError(param_1);
    local_14 = (void *)0x0;
  }
  else {
    memset(local_14,0,0x2c8);
    *(undefined4 *)((int)local_14 + 0x68) = 1;
    iVar2 = (int)local_14 + 200;
    *(int *)((int)local_14 + 0x90) = iVar2;
    *(int *)((int)local_14 + 0x8c) = iVar2;
    *(int *)((int)local_14 + 0x88) = iVar2;
    *(int *)((int)local_14 + 0x94) = param_2;
    *(int *)((int)local_14 + 0x98) = param_2 + param_3 * 2;
    *(int *)((int)local_14 + 0x9c) = param_2;
    *(undefined4 *)((int)local_14 + 0xb8) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x208);
    *(undefined4 *)((int)local_14 + 0xbc) = *(undefined4 *)(*(int *)(param_1 + 0x14) + 0x20c);
  }
  return local_14;
}



// ============================================================
// Function: strings_setParserMode (FUN_68163770)
// Address: 68163770
// Size: 145 bytes
// Params: undefined4 param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_setParserMode(undefined4 param_1,int param_2)

{
  int iVar1;
  
  if ((*(int *)(param_2 + 0xb4) != 0) &&
     (iVar1 = *(int *)(*(int *)(param_2 + 0xb4) + 0xc) + -1,
     *(int *)(*(int *)(param_2 + 0xb4) + 0xc) = iVar1, iVar1 == 0)) {
    (**(code **)(*(int *)(param_2 + 0xb4) + 0x10))(param_1,*(undefined4 *)(param_2 + 0xb4));
  }
  if ((*(int *)(param_2 + 0xb0) != 0) && (iVar1 = fclose(*(FILE **)(param_2 + 0xb0)), iVar1 != 0)) {
    return 0;
  }
  return 1;
}



// ============================================================
// Function: strings_scanToken (FUN_68163810)
// Address: 68163810
// Size: 790 bytes
// Params: uint * param_1, int param_2, int param_3, uint param_4, undefined4 param_5
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl strings_scanToken(uint *param_1,int param_2,int param_3,uint param_4,undefined4 param_5)

{
  int iVar1;
  int local_64;
  uint local_60;
  undefined *local_5c;
  undefined *local_58;
  int local_54;
  uint local_48;
  char *local_44;
  uint *local_40;
  int local_3c;
  code *local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined *local_2c;
  undefined *local_28;
  uint local_24;
  int local_20;
  uint local_1c;
  undefined4 local_18;
  int local_14;
  int local_10;
  
  local_40 = (uint *)0x0;
  if (((param_4 & 4) == 0) || ((param_1[0x59] & 1) != 0)) {
    memset(&local_34,0,0x30);
    local_1c = param_4;
    local_18 = param_5;
    local_44 = (char *)0x0;
    iVar1 = xtra_formatError((int)param_1,xtra_getErrorString,0,param_5,(int *)&local_44,(int)&local_34,
                         &local_48,1,(undefined4 *)&stack0x00000018);
    if (iVar1 == 0) {
      local_48 = 0;
    }
    else {
      js_internAtom((int)param_1,(uint)&local_40,0x681825f4);
      local_38 = (code *)param_1[0x52];
      if (local_38 != (code *)0x0) {
        if (param_2 == 0) {
          if (param_3 != 0) {
            local_34 = *(undefined4 *)(param_3 + 0x44);
            local_30 = *(undefined4 *)(param_3 + 0x4c);
          }
        }
        else {
          local_34 = *(undefined4 *)(param_2 + 0xac);
          local_30 = *(undefined4 *)(param_2 + 0x68);
          local_40 = certs_allocFromPool((int)param_1,*(void **)(param_2 + 0x88),
                                  *(int *)(param_2 + 0x8c) - *(int *)(param_2 + 0x88) >> 1,0);
          if (local_40 == (uint *)0x0) {
            local_58 = (undefined *)0x0;
          }
          else {
            local_58 = xtra_getStringValue(local_40);
          }
          local_2c = local_58;
          local_3c = *(int *)(param_2 + 0xc +
                             (*(int *)(param_2 + 0x60) + *(int *)(param_2 + 100) & 3U) * 0x18);
          if (local_40 == (uint *)0x0) {
            local_5c = (undefined *)0x0;
          }
          else {
            local_5c = local_58 + (local_3c - *(int *)(param_2 + 0x88) >> 1);
          }
          local_28 = local_5c;
          if (local_40 == (uint *)0x0) {
            local_60 = 0;
          }
          else {
            local_60 = xtra_getStringData(local_40);
          }
          local_24 = local_60;
          if (local_40 == (uint *)0x0) {
            local_64 = 0;
          }
          else {
            local_64 = local_60 + (local_3c - *(int *)(param_2 + 0x88) >> 1) * 2;
          }
          local_20 = local_64;
        }
        if (((param_2 == 0) || ((*(uint *)(param_2 + 0x7c) & 1) == 0)) &&
           (iVar1 = runtime_throwError(param_1,local_44,&local_34), iVar1 != 0)) {
          local_38 = (code *)0x0;
        }
        if (param_1[2] != 0) {
          local_38 = (code *)0x0;
        }
        if (((*(int *)(param_1[5] + 0x230) != 0) && (local_38 != (code *)0x0)) &&
           ((*(code **)(param_1[5] + 0x230) != (code *)0x0 &&
            (iVar1 = (**(code **)(param_1[5] + 0x230))
                               (param_1,local_44,&local_34,*(undefined4 *)(param_1[5] + 0x234)),
            iVar1 == 0)))) {
          local_38 = (code *)0x0;
        }
        if (local_38 != (code *)0x0) {
          (*local_38)(param_1,local_44,&local_34);
        }
      }
      if (local_44 != (char *)0x0) {
        xtra_checkAndFlush(param_1,(int)local_44);
      }
      if (local_10 != 0) {
        for (local_54 = 0; *(int *)(local_10 + local_54 * 4) != 0; local_54 = local_54 + 1) {
          xtra_checkAndFlush(param_1,*(int *)(local_10 + local_54 * 4));
        }
        xtra_checkAndFlush(param_1,local_10);
      }
      if (local_14 != 0) {
        xtra_checkAndFlush(param_1,local_14);
      }
      js_markAtom(param_1[5],&local_40);
      if ((param_2 != 0) && ((param_4 & 1) == 0)) {
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
      }
    }
  }
  else {
    local_48 = 1;
  }
  return local_48;
}



// ============================================================
// Function: strings_initParser (FUN_68163b30)
// Address: 68163b30
// Size: 76 bytes
// Params: uint * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_initParser(uint *param_1,int param_2)

{
  undefined4 local_8;
  
  if (*(int *)(param_2 + 100) == 0) {
    local_8 = strings_parseExpression(param_1,param_2);
    strings_resetScanner(param_2);
  }
  else {
    local_8 = *(undefined4 *)
               (param_2 + (*(int *)(param_2 + 0x60) + *(int *)(param_2 + 100) & 3U) * 0x18);
  }
  return local_8;
}



// ============================================================
// Function: strings_beginParse (FUN_68163b80)
// Address: 68163b80
// Size: 59 bytes
// Params: uint * param_1, int param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_beginParse(uint *param_1,int param_2)

{
  undefined4 uVar1;
  
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 4;
  uVar1 = strings_initParser(param_1,param_2);
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xfffffffb;
  return uVar1;
}



// ============================================================
// Function: strings_parseExpression (FUN_68163bc0)
// Address: 68163bc0
// Size: 8690 bytes
// Params: uint * param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x68165c9d) */
/* WARNING: Removing unreachable block (ram,0x68164fd4) */
/* WARNING: Removing unreachable block (ram,0x6816492f) */
/* WARNING: Removing unreachable block (ram,0x68165c45) */
/* WARNING: Removing unreachable block (ram,0x681658ea) */
/* WARNING: Removing unreachable block (ram,0x681640a6) */
/* WARNING: Removing unreachable block (ram,0x68163cfd) */

int strings_parseExpression(uint *param_1,int param_2)
{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined3 extraout_var_02;
  undefined3 extraout_var_03;
  undefined3 extraout_var_04;
  undefined3 extraout_var_05;
  undefined3 extraout_var_06;
  undefined3 extraout_var_07;
  undefined3 extraout_var_08;
  undefined3 extraout_var_09;
  undefined3 extraout_var_10;
  undefined3 extraout_var_11;
  undefined3 extraout_var_12;
  undefined3 extraout_var_13;
  undefined3 extraout_var_14;
  undefined3 extraout_var_15;
  undefined3 extraout_var_16;
  undefined3 extraout_var_17;
  undefined3 extraout_var_18;
  undefined3 extraout_var_19;
  undefined3 extraout_var_20;
  undefined3 extraout_var_21;
  undefined3 extraout_var_22;
  undefined3 extraout_var_23;
  undefined3 extraout_var_24;
  undefined3 extraout_var_25;
  undefined3 extraout_var_26;
  undefined3 extraout_var_27;
  undefined3 extraout_var_28;
  undefined3 extraout_var_29;
  undefined3 extraout_var_30;
  undefined3 extraout_var_31;
  undefined3 extraout_var_32;
  uint uVar3;
  uint local_a4;
  uint local_a0;
  int local_98;
  int local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  uint local_7c;
  uint local_78;
  uint local_70;
  int local_6c;
  undefined1 local_68 [20];
  uint local_54;
  int *local_50;
  uint local_4c;
  ushort local_48;
  ushort local_46;
  ushort local_44;
  ushort local_42;
  ushort local_40;
  ushort local_3e;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  double local_2c;
  int local_24;
  uint local_20;
  int local_1c;
  uint *local_18;
  uint local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  uVar3 = *(uint *)(param_2 + 0x7c) & 1;
  while (uVar3 == 0) {
    if (*(int *)(param_2 + 100) == 0) goto LAB_68163c3d;
    *(int *)(param_2 + 100) = *(int *)(param_2 + 100) + -1;
    *(uint *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1U & 3;
    local_10 = *(int *)(param_2 + *(int *)(param_2 + 0x60) * 0x18);
    if (local_10 != 1) break;
    uVar3 = *(uint *)(param_2 + 0x7c) & 4;
  }
  goto LAB_68165da2;
LAB_68163c3d:
  local_c = strings_peekChar(param_2);
  if ((local_c != 10) ||
     (*(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) & 0xffffff7f,
     (*(uint *)(param_2 + 0x7c) & 4) == 0)) {
    uVar3 = crypto_allocString(local_c);
    if ((uVar3 & 0x70000) == 0x40000) goto LAB_68163c3d;
  }
  *(uint *)(param_2 + 0x60) = *(int *)(param_2 + 0x60) + 1U & 3;
  local_18 = (uint *)(*(int *)(param_2 + 0x60) * 0x18 + param_2);
  local_18[3] = *(int *)(param_2 + 0x90) - 2;
  *(short *)(local_18 + 1) =
       (short)((int)(local_18[3] - *(int *)(param_2 + 0x88)) >> 1) +
       (short)*(undefined4 *)(param_2 + 0x84);
  *(undefined2 *)((int)local_18 + 10) = *(undefined2 *)(param_2 + 0x68);
  *(undefined2 *)((int)local_18 + 6) = *(undefined2 *)((int)local_18 + 10);
  if (local_c == 0xffffffff) {
    *(short *)(local_18 + 2) =
         ((short)*(undefined4 *)(param_2 + 0x84) +
         (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
         (short)*(undefined4 *)(param_2 + 0x6c);
    *local_18 = 0;
    goto LAB_68165da2;
  }
  if ((local_c != 0x2d) && (local_c != 10)) {
    *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 0x80;
  }
  local_8 = 0;
  uVar3 = crypto_getStringCapacity(local_c);
  if ((((0x43e >> ((byte)uVar3 & 0x1f) & 1U) != 0) || (local_c == 0x5f)) || (local_c == 0x24)) {
LAB_68163de8:
    *(undefined4 *)(param_2 + 0xa8) = *(undefined4 *)(param_2 + 0xa0);
    goto LAB_68163dfa;
  }
  if (local_c == 0x5c) {
    local_c = strings_parseUnicodeEscape(param_2);
    uVar3 = crypto_getStringCapacity(local_c);
    if ((((0x43e >> ((byte)uVar3 & 0x1f) & 1U) == 0) && (local_c != 0x5f)) && (local_c != 0x24)) {
      local_6c = 0;
    }
    else {
      local_6c = 1;
    }
    local_8 = local_6c;
    if (local_6c != 0) goto LAB_68163de8;
  }
  if (((int)local_c < 0x80) && (iVar2 = isdigit(local_c), iVar2 != 0)) {
LAB_68164147:
    local_20 = 10;
    *(undefined4 *)(param_2 + 0xa8) = *(undefined4 *)(param_2 + 0xa0);
    if (local_c != 0x30) goto LAB_681642c2;
    iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),0x30);
    if (iVar2 == 0) {
      *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
      *(short *)(local_18 + 2) =
           ((short)*(undefined4 *)(param_2 + 0x84) +
           (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
           (short)*(undefined4 *)(param_2 + 0x6c);
      *local_18 = 0xffffffff;
      goto LAB_68165da2;
    }
    local_c = strings_peekChar(param_2);
    uVar3 = crypto_allocString(local_c);
    if ((uVar3 & 0x200000) == 0) {
      local_70 = local_c;
    }
    else {
      iVar2 = crypto_allocString(local_c);
      local_70 = (iVar2 >> 0x16) + local_c;
    }
    if (local_70 != 0x78) {
      if (((int)local_c < 0x80) && (iVar2 = isdigit(local_c), iVar2 != 0)) {
        local_20 = 8;
      }
      goto LAB_681642c2;
    }
    iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),(short)local_c);
    if (iVar2 == 0) {
      *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
      *(short *)(local_18 + 2) =
           ((short)*(undefined4 *)(param_2 + 0x84) +
           (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
           (short)*(undefined4 *)(param_2 + 0x6c);
      *local_18 = 0xffffffff;
      goto LAB_68165da2;
    }
    local_c = strings_peekChar(param_2);
    local_20 = 0x10;
    goto LAB_681642c2;
  }
  if ((local_c == 0x2e) && (iVar2 = strings_peekNextChar(param_2), iVar2 < 0x80)) {
    iVar2 = strings_peekNextChar(param_2);
    iVar2 = isdigit(iVar2);
    if (iVar2 != 0) goto LAB_68164147;
  }
  if ((local_c == 0x22) || (local_c == 0x27)) {
    local_34 = local_c;
    *(undefined4 *)(param_2 + 0xa8) = *(undefined4 *)(param_2 + 0xa0);
    goto LAB_681649a5;
  }
  switch(local_c) {
  case 10:
    local_c = 1;
    break;
  default:
    goto switchD_68165054_caseD_b;
  case 0x21:
    bVar1 = strings_getCharAt(param_2,0x3d);
    if (CONCAT31(extraout_var_08,bVar1) == 0) {
      local_18[4] = 0x20;
      local_c = 0x13;
    }
    else {
      bVar1 = strings_getCharAt(param_2,0x3d);
      if (CONCAT31(extraout_var_09,bVar1) == 0) {
        local_a4 = (uint)*(byte *)((int)param_1 + 0x11);
      }
      else {
        local_a4 = 0x49;
      }
      local_18[4] = local_a4;
      local_c = 0xc;
    }
    break;
  case 0x23:
    local_c = strings_peekChar(param_2);
    if ((0x7f < (int)local_c) || (iVar2 = isdigit(local_c), iVar2 == 0)) {
      strings_appendToken(param_2,local_c);
      goto switchD_68165054_caseD_b;
    }
    local_54 = local_c - 0x30;
    goto LAB_68165ab2;
  case 0x25:
    local_18[4] = 0x1f;
    bVar1 = strings_getCharAt(param_2,0x3d);
    local_c = (-(uint)(CONCAT31(extraout_var_28,bVar1) != 0) & 0xfffffff2) + 0x12;
    break;
  case 0x26:
    bVar1 = strings_getCharAt(param_2,local_c);
    if (CONCAT31(extraout_var_04,bVar1) == 0) {
      bVar1 = strings_getCharAt(param_2,0x3d);
      if (CONCAT31(extraout_var_05,bVar1) == 0) {
        local_c = 0xb;
      }
      else {
        local_18[4] = 0x11;
        local_c = 4;
      }
    }
    else {
      local_c = 8;
    }
    break;
  case 0x28:
    local_c = 0x1b;
    break;
  case 0x29:
    local_c = 0x1c;
    break;
  case 0x2a:
    local_18[4] = 0x1d;
    bVar1 = strings_getCharAt(param_2,0x3d);
    local_c = (-(uint)(CONCAT31(extraout_var_20,bVar1) != 0) & 0xfffffff3) + 0x11;
    break;
  case 0x2b:
    bVar1 = strings_getCharAt(param_2,0x3d);
    if (CONCAT31(extraout_var_29,bVar1) == 0) {
      bVar1 = strings_getCharAt(param_2,local_c);
      if (CONCAT31(extraout_var_30,bVar1) == 0) {
        local_18[4] = 0x52;
        local_c = 0xf;
      }
      else {
        local_c = 0x14;
      }
    }
    else {
      local_18[4] = 0x1b;
      local_c = 4;
    }
    break;
  case 0x2c:
    local_c = 3;
    break;
  case 0x2d:
    bVar1 = strings_getCharAt(param_2,0x3d);
    if (CONCAT31(extraout_var_31,bVar1) == 0) {
      bVar1 = strings_getCharAt(param_2,local_c);
      if (CONCAT31(extraout_var_32,bVar1) == 0) {
        local_18[4] = 0x22;
        local_c = 0x10;
      }
      else {
        iVar2 = strings_peekNextChar(param_2);
        if ((iVar2 == 0x3e) && ((*(uint *)(param_2 + 0x7c) & 0x80) == 0)) goto LAB_681653c1;
        local_c = 0x15;
      }
    }
    else {
      local_18[4] = 0x1c;
      local_c = 4;
    }
    *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 0x80;
    break;
  case 0x2e:
    local_c = 0x16;
    break;
  case 0x2f:
    bVar1 = strings_getCharAt(param_2,0x2f);
    if (CONCAT31(extraout_var_21,bVar1) == 0) {
      bVar1 = strings_getCharAt(param_2,0x2a);
      if (CONCAT31(extraout_var_22,bVar1) != 0) goto LAB_68165400;
      if ((*(uint *)(param_2 + 0x7c) & 8) == 0) {
        local_18[4] = 0x1e;
        bVar1 = strings_getCharAt(param_2,0x3d);
        local_c = (-(uint)(CONCAT31(extraout_var_27,bVar1) != 0) & 0xfffffff2) + 0x12;
        break;
      }
      *(undefined4 *)(param_2 + 0xa8) = *(undefined4 *)(param_2 + 0xa0);
      goto LAB_681654c3;
    }
LAB_681653c1:
    do {
      local_c = strings_peekChar(param_2);
      if (local_c == 0xffffffff) break;
    } while (local_c != 10);
    strings_appendToken(param_2,local_c);
    goto LAB_68163c3d;
  case 0x3a:
    local_18[4] = 0;
    local_c = 6;
    break;
  case 0x3b:
    local_c = 2;
    break;
  case 0x3c:
    bVar1 = strings_getCharAt(param_2,0x21);
    if (CONCAT31(extraout_var_10,bVar1) != 0) {
      bVar1 = strings_getCharAt(param_2,0x2d);
      if (CONCAT31(extraout_var_11,bVar1) != 0) {
        bVar1 = strings_getCharAt(param_2,0x2d);
        if (CONCAT31(extraout_var_12,bVar1) != 0) goto LAB_681653c1;
        strings_appendToken(param_2,0x2d);
      }
      strings_appendToken(param_2,0x21);
    }
    bVar1 = strings_getCharAt(param_2,local_c);
    if (CONCAT31(extraout_var_13,bVar1) == 0) {
      bVar1 = strings_getCharAt(param_2,0x3d);
      local_18[4] = (CONCAT31(extraout_var_15,bVar1) != 0) + 0x14;
      local_c = 0xd;
    }
    else {
      local_18[4] = 0x18;
      bVar1 = strings_getCharAt(param_2,0x3d);
      local_c = (-(uint)(CONCAT31(extraout_var_14,bVar1) != 0) & 0xfffffff6) + 0xe;
    }
    break;
  case 0x3d:
    bVar1 = strings_getCharAt(param_2,local_c);
    if (CONCAT31(extraout_var_06,bVar1) == 0) {
      local_18[4] = 0;
      local_c = 4;
    }
    else {
      bVar1 = strings_getCharAt(param_2,local_c);
      if (CONCAT31(extraout_var_07,bVar1) == 0) {
        local_a0 = (uint)(byte)param_1[4];
      }
      else {
        local_a0 = 0x48;
      }
      local_18[4] = local_a0;
      local_c = 0xc;
    }
    break;
  case 0x3e:
    bVar1 = strings_getCharAt(param_2,local_c);
    if (CONCAT31(extraout_var_16,bVar1) == 0) {
      bVar1 = strings_getCharAt(param_2,0x3d);
      local_18[4] = (CONCAT31(extraout_var_19,bVar1) != 0) + 0x16;
      local_c = 0xd;
    }
    else {
      bVar1 = strings_getCharAt(param_2,local_c);
      local_18[4] = (CONCAT31(extraout_var_17,bVar1) != 0) + 0x19;
      bVar1 = strings_getCharAt(param_2,0x3d);
      local_c = (-(uint)(CONCAT31(extraout_var_18,bVar1) != 0) & 0xfffffff6) + 0xe;
    }
    break;
  case 0x3f:
    local_c = 5;
    break;
  case 0x5b:
    local_c = 0x17;
    break;
  case 0x5d:
    local_c = 0x18;
    break;
  case 0x5e:
    bVar1 = strings_getCharAt(param_2,0x3d);
    if (CONCAT31(extraout_var_03,bVar1) == 0) {
      local_c = 10;
    }
    else {
      local_18[4] = 0x10;
      local_c = 4;
    }
    break;
  case 0x7b:
    local_c = 0x19;
    break;
  case 0x7c:
    bVar1 = strings_getCharAt(param_2,local_c);
    if (CONCAT31(extraout_var_01,bVar1) == 0) {
      bVar1 = strings_getCharAt(param_2,0x3d);
      if (CONCAT31(extraout_var_02,bVar1) == 0) {
        local_c = 9;
      }
      else {
        local_18[4] = 0xf;
        local_c = 4;
      }
    }
    else {
      local_c = 7;
    }
    break;
  case 0x7d:
    local_c = 0x1a;
    break;
  case 0x7e:
    local_18[4] = 0x21;
    local_c = 0x13;
  }
  if (local_c == 0xffffffff) {
    *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
  }
  *(short *)(local_18 + 2) =
       ((short)*(undefined4 *)(param_2 + 0x84) +
       (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
       (short)*(undefined4 *)(param_2 + 0x6c);
  *local_18 = local_c;
  goto LAB_68165da2;
  while (((uVar3 = crypto_getStringCapacity(local_c), (0x80077e >> ((byte)uVar3 & 0x1f) & 1U) != 0 ||
          (local_c == 0x5f)) || (local_c == 0x24))) {
LAB_68163dfa:
    iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),(short)local_c);
    if (iVar2 == 0) {
      *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
      *(short *)(local_18 + 2) =
           ((short)*(undefined4 *)(param_2 + 0x84) +
           (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
           (short)*(undefined4 *)(param_2 + 0x6c);
      *local_18 = 0xffffffff;
      goto LAB_68165da2;
    }
    local_c = strings_peekChar(param_2);
    if (local_c == 0x5c) {
      local_c = strings_parseUnicodeEscape(param_2);
      uVar3 = crypto_getStringCapacity(local_c);
      if ((((0x80077e >> ((byte)uVar3 & 0x1f) & 1U) == 0) && (local_c != 0x5f)) && (local_c != 0x24)
         ) break;
      local_8 = 1;
      goto LAB_68163dfa;
    }
  }
  strings_appendToken(param_2,local_c);
  iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),0);
  if (iVar2 == 0) {
    *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
    *(short *)(local_18 + 2) =
         ((short)*(undefined4 *)(param_2 + 0x84) +
         (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
         (short)*(undefined4 *)(param_2 + 0x6c);
    *local_18 = 0xffffffff;
  }
  else {
    local_14 = javascript_registerAtomInline((int)param_1,*(undefined4 *)(param_2 + 0xa0),
                            (*(int *)(param_2 + 0xa8) - *(int *)(param_2 + 0xa0) >> 1) - 1,0);
    if (local_14 == 0) {
      *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
      *(short *)(local_18 + 2) =
           ((short)*(undefined4 *)(param_2 + 0x84) +
           (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
           (short)*(undefined4 *)(param_2 + 0x6c);
      *local_18 = 0xffffffff;
    }
    else if (((local_8 == 0) && (*(int *)(local_14 + 0xc) != 0)) &&
            ((local_1c = *(int *)(local_14 + 0xc), param_1[3] == 0 ||
             ((0x81 < (int)param_1[3] || (*(int *)(local_1c + 0xc) <= (int)param_1[3])))))) {
      local_18[4] = *(uint *)(local_1c + 8);
      if (*(int *)(local_1c + 4) == -1) {
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
      }
      *(short *)(local_18 + 2) =
           ((short)*(undefined4 *)(param_2 + 0x84) +
           (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
           (short)*(undefined4 *)(param_2 + 0x6c);
      *local_18 = *(uint *)(local_1c + 4);
    }
    else {
      local_18[4] = 0x3b;
      local_18[5] = local_14;
      *(short *)(local_18 + 2) =
           ((short)*(undefined4 *)(param_2 + 0x84) +
           (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
           (short)*(undefined4 *)(param_2 + 0x6c);
      *local_18 = 0x1d;
    }
  }
  goto LAB_68165da2;
LAB_681642c2:
  if ((0x7f < (int)local_c) || (iVar2 = isxdigit(local_c), iVar2 == 0)) goto LAB_68164435;
  if ((int)local_20 < 0x10) {
    if (((int)local_c < 0x80) && (iVar2 = isalpha(local_c), iVar2 != 0)) goto LAB_68164435;
    if ((local_20 == 8) && (0x37 < (int)local_c)) {
      uVar3 = strings_scanToken(param_1,param_2,0,1,0x91);
      if (uVar3 == 0) {
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0xffffffff;
        goto LAB_68165da2;
      }
      local_20 = 10;
    }
  }
  iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),(short)local_c);
  if (iVar2 == 0) {
    *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
    *(short *)(local_18 + 2) =
         ((short)*(undefined4 *)(param_2 + 0x84) +
         (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
         (short)*(undefined4 *)(param_2 + 0x6c);
    *local_18 = 0xffffffff;
    goto LAB_68165da2;
  }
  local_c = strings_peekChar(param_2);
  goto LAB_681642c2;
LAB_68164435:
  if (local_20 == 10) {
    if (local_c != 0x2e) {
      uVar3 = crypto_allocString(local_c);
      if ((uVar3 & 0x200000) == 0) {
        local_78 = local_c;
      }
      else {
        iVar2 = crypto_allocString(local_c);
        local_78 = (iVar2 >> 0x16) + local_c;
      }
      if (local_78 != 0x65) goto LAB_6816477a;
    }
    if (local_c == 0x2e) {
      do {
        iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),(short)local_c);
        if (iVar2 == 0) {
          *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
          *(short *)(local_18 + 2) =
               ((short)*(undefined4 *)(param_2 + 0x84) +
               (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
               (short)*(undefined4 *)(param_2 + 0x6c);
          *local_18 = 0xffffffff;
          goto LAB_68165da2;
        }
        local_c = strings_peekChar(param_2);
      } while (((int)local_c < 0x80) && (iVar2 = isdigit(local_c), iVar2 != 0));
    }
    uVar3 = crypto_allocString(local_c);
    if ((uVar3 & 0x200000) == 0) {
      local_7c = local_c;
    }
    else {
      iVar2 = crypto_allocString(local_c);
      local_7c = (iVar2 >> 0x16) + local_c;
    }
    if (local_7c == 0x65) {
      iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),(short)local_c);
      if (iVar2 == 0) {
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0xffffffff;
        goto LAB_68165da2;
      }
      local_c = strings_peekChar(param_2);
      if ((local_c == 0x2b) || (local_c == 0x2d)) {
        iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),(short)local_c);
        if (iVar2 == 0) {
          *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
          *(short *)(local_18 + 2) =
               ((short)*(undefined4 *)(param_2 + 0x84) +
               (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
               (short)*(undefined4 *)(param_2 + 0x6c);
          *local_18 = 0xffffffff;
          goto LAB_68165da2;
        }
        local_c = strings_peekChar(param_2);
      }
      if ((0x7f < (int)local_c) || (iVar2 = isdigit(local_c), iVar2 == 0)) {
        strings_scanToken(param_1,param_2,0,0,0x88);
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0xffffffff;
        goto LAB_68165da2;
      }
      do {
        iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),(short)local_c);
        if (iVar2 == 0) {
          *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
          *(short *)(local_18 + 2) =
               ((short)*(undefined4 *)(param_2 + 0x84) +
               (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
               (short)*(undefined4 *)(param_2 + 0x6c);
          *local_18 = 0xffffffff;
          goto LAB_68165da2;
        }
        local_c = strings_peekChar(param_2);
      } while (((int)local_c < 0x80) && (iVar2 = isdigit(local_c), iVar2 != 0));
    }
  }
LAB_6816477a:
  strings_appendToken(param_2,local_c);
  iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),0);
  if (iVar2 == 0) {
    *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
    *(short *)(local_18 + 2) =
         ((short)*(undefined4 *)(param_2 + 0x84) +
         (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
         (short)*(undefined4 *)(param_2 + 0x6c);
    *local_18 = 0xffffffff;
  }
  else {
    if (local_20 == 10) {
      iVar2 = runtime_parseNumberFromWchar((int)param_1,*(ushort **)(param_2 + 0xa0),&local_24,&local_2c);
      if (iVar2 == 0) {
        strings_scanToken(param_1,param_2,0,0,0x89);
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0xffffffff;
        goto LAB_68165da2;
      }
    }
    else {
      iVar2 = runtime_parseNumberWithRadix((int)param_1,*(ushort **)(param_2 + 0xa0),&local_24,local_20,&local_2c);
      if (iVar2 == 0) {
        strings_scanToken(param_1,param_2,0,0,0x89);
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0xffffffff;
        goto LAB_68165da2;
      }
    }
    *(double *)(local_18 + 4) = local_2c;
    *(short *)(local_18 + 2) =
         ((short)*(undefined4 *)(param_2 + 0x84) +
         (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
         (short)*(undefined4 *)(param_2 + 0x6c);
    *local_18 = 0x1e;
  }
  goto LAB_68165da2;
  while (iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),(short)local_c), iVar2 != 0) {
LAB_681649a5:
    local_c = strings_peekChar(param_2);
    if (local_c == local_34) {
      iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),0);
      if (iVar2 == 0) {
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0xffffffff;
      }
      else {
        local_14 = javascript_registerAtomInline((int)param_1,*(undefined4 *)(param_2 + 0xa0),
                                (*(int *)(param_2 + 0xa8) - *(int *)(param_2 + 0xa0) >> 1) - 1,0);
        if (local_14 == 0) {
          *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
          *(short *)(local_18 + 2) =
               ((short)*(undefined4 *)(param_2 + 0x84) +
               (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
               (short)*(undefined4 *)(param_2 + 0x6c);
          *local_18 = 0xffffffff;
        }
        else {
          *(undefined2 *)((int)local_18 + 10) = *(undefined2 *)(param_2 + 0x68);
          local_18[4] = 0x3d;
          local_18[5] = local_14;
          *(short *)(local_18 + 2) =
               ((short)*(undefined4 *)(param_2 + 0x84) +
               (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
               (short)*(undefined4 *)(param_2 + 0x6c);
          *local_18 = 0x1f;
        }
      }
      goto LAB_68165da2;
    }
    if ((local_c == 10) || (local_c == 0xffffffff)) {
      strings_appendToken(param_2,local_c);
      strings_scanToken(param_1,param_2,0,0,0x8a);
      *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
      *(short *)(local_18 + 2) =
           ((short)*(undefined4 *)(param_2 + 0x84) +
           (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
           (short)*(undefined4 *)(param_2 + 0x6c);
      *local_18 = 0xffffffff;
      goto LAB_68165da2;
    }
    if (local_c == 0x5c) {
      local_c = strings_peekChar(param_2);
      switch(local_c) {
      case 0x62:
        local_c = 8;
        break;
      default:
        if (((int)local_c < 0x30) || (0x37 < (int)local_c)) {
          if (local_c == 0x75) {
            bVar1 = strings_matchAndEmit(param_2,4,(int)&local_44);
            if (((((CONCAT31(extraout_var,bVar1) != 0) && (local_44 < 0x80)) &&
                 (iVar2 = isxdigit((uint)local_44), iVar2 != 0)) &&
                ((local_42 < 0x80 && (iVar2 = isxdigit((uint)local_42), iVar2 != 0)))) &&
               (((local_40 < 0x80 &&
                 ((iVar2 = isxdigit((uint)local_40), iVar2 != 0 && (local_3e < 0x80)))) &&
                (iVar2 = isxdigit((uint)local_3e), iVar2 != 0)))) {
              iVar2 = isdigit((uint)local_44);
              if (iVar2 == 0) {
                local_84 = tolower((uint)local_44);
                local_84 = local_84 + -0x57;
              }
              else {
                local_84 = local_44 - 0x30;
              }
              iVar2 = isdigit((uint)local_42);
              if (iVar2 == 0) {
                local_88 = tolower((uint)local_42);
                local_88 = local_88 + -0x57;
              }
              else {
                local_88 = local_42 - 0x30;
              }
              iVar2 = isdigit((uint)local_40);
              if (iVar2 == 0) {
                local_8c = tolower((uint)local_40);
                local_8c = local_8c + -0x57;
              }
              else {
                local_8c = local_40 - 0x30;
              }
              iVar2 = isdigit((uint)local_3e);
              if (iVar2 == 0) {
                local_90 = tolower((uint)local_3e);
                local_90 = local_90 + -0x57;
              }
              else {
                local_90 = local_3e - 0x30;
              }
              local_c = ((local_84 * 0x10 + local_88) * 0x10 + local_8c) * 0x10 + local_90;
              strings_emitToken(param_2,4);
            }
          }
          else if (local_c == 0x78) {
            bVar1 = strings_matchAndEmit(param_2,2,(int)&local_48);
            if ((((CONCAT31(extraout_var_00,bVar1) != 0) && (local_48 < 0x80)) &&
                (iVar2 = isxdigit((uint)local_48), iVar2 != 0)) &&
               ((local_46 < 0x80 && (iVar2 = isxdigit((uint)local_46), iVar2 != 0)))) {
              iVar2 = isdigit((uint)local_48);
              if (iVar2 == 0) {
                local_94 = tolower((uint)local_48);
                local_94 = local_94 + -0x57;
              }
              else {
                local_94 = local_48 - 0x30;
              }
              iVar2 = isdigit((uint)local_46);
              if (iVar2 == 0) {
                local_98 = tolower((uint)local_46);
                local_98 = local_98 + -0x57;
              }
              else {
                local_98 = local_46 - 0x30;
              }
              local_c = local_94 * 0x10 + local_98;
              strings_emitToken(param_2,2);
            }
          }
          else if ((local_c == 10) && ((param_1[3] == 0 || (0x81 < (int)param_1[3]))))
          goto LAB_681649a5;
        }
        else {
          local_30 = local_c - 0x30;
          local_c = strings_peekNextChar(param_2);
          if ((0x2f < (int)local_c) && ((int)local_c < 0x38)) {
            local_30 = local_c + -0x30 + local_30 * 8;
            strings_peekChar(param_2);
            local_c = strings_peekNextChar(param_2);
            if ((0x2f < (int)local_c) && ((int)local_c < 0x38)) {
              local_38 = local_30;
              uVar3 = local_c + -0x30 + local_30 * 8;
              if ((int)uVar3 < 0x100) {
                local_30 = uVar3;
                strings_peekChar(param_2);
              }
            }
          }
          local_c = local_30 & 0xffff;
        }
        break;
      case 0x66:
        local_c = 0xc;
        break;
      case 0x6e:
        local_c = 10;
        break;
      case 0x72:
        local_c = 0xd;
        break;
      case 0x74:
        local_c = 9;
        break;
      case 0x76:
        local_c = 0xb;
      }
    }
  }
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
  *(short *)(local_18 + 2) =
       ((short)*(undefined4 *)(param_2 + 0x84) +
       (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
       (short)*(undefined4 *)(param_2 + 0x6c);
  *local_18 = 0xffffffff;
  goto LAB_68165da2;
LAB_68165400:
  do {
    local_c = strings_peekChar(param_2);
    if (local_c == 0xffffffff) break;
  } while ((local_c != 0x2a) ||
          (bVar1 = strings_getCharAt(param_2,0x2f), CONCAT31(extraout_var_23,bVar1) == 0));
  if (local_c == 0xffffffff) goto code_r0x6816542f;
  goto LAB_68163c3d;
code_r0x6816542f:
  strings_scanToken(param_1,param_2,0,0,0x8c);
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
  *(short *)(local_18 + 2) =
       ((short)*(undefined4 *)(param_2 + 0x84) +
       (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
       (short)*(undefined4 *)(param_2 + 0x6c);
  *local_18 = 0xffffffff;
  goto LAB_68165da2;
  while( true ) {
    if ((local_c == 10) || (local_c == 0xffffffff)) {
      strings_appendToken(param_2,local_c);
      strings_scanToken(param_1,param_2,0,0,0x8d);
      *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
      *(short *)(local_18 + 2) =
           ((short)*(undefined4 *)(param_2 + 0x84) +
           (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
           (short)*(undefined4 *)(param_2 + 0x6c);
      *local_18 = 0xffffffff;
      goto LAB_68165da2;
    }
    if (local_c == 0x5c) {
      iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),0x5c);
      if (iVar2 == 0) {
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0xffffffff;
        goto LAB_68165da2;
      }
      local_c = strings_peekChar(param_2);
    }
    iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),(short)local_c);
    if (iVar2 == 0) break;
LAB_681654c3:
    local_c = strings_peekChar(param_2);
    if (local_c == 0x2f) {
      iVar2 = strings_matchKeyword((int)param_1,(int *)(param_2 + 0xa0),0);
      if (iVar2 == 0) {
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0xffffffff;
      }
      else {
        local_4c = 0;
        while( true ) {
          while( true ) {
            while (bVar1 = strings_getCharAt(param_2,0x67), CONCAT31(extraout_var_24,bVar1) != 0) {
              local_4c = local_4c | 2;
            }
            bVar1 = strings_getCharAt(param_2,0x69);
            if (CONCAT31(extraout_var_25,bVar1) == 0) break;
            local_4c = local_4c | 1;
          }
          bVar1 = strings_getCharAt(param_2,0x6d);
          if (CONCAT31(extraout_var_26,bVar1) == 0) break;
          local_4c = local_4c | 4;
        }
        local_c = strings_peekNextChar(param_2);
        if (((int)local_c < 0x80) && (iVar2 = isalpha(local_c), iVar2 != 0)) {
          local_18[3] = *(int *)(param_2 + 0x90) - 2;
          strings_scanToken(param_1,param_2,0,0,0x8e);
          strings_peekChar(param_2);
          *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
          *(short *)(local_18 + 2) =
               ((short)*(undefined4 *)(param_2 + 0x84) +
               (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
               (short)*(undefined4 *)(param_2 + 0x6c);
          *local_18 = 0xffffffff;
        }
        else {
          local_50 = javascript_createRegexpFromString((uint)param_1,param_2,*(void **)(param_2 + 0xa0),
                                  (*(int *)(param_2 + 0xa8) - *(int *)(param_2 + 0xa0) >> 1) - 1,
                                  local_4c);
          if (local_50 == (int *)0x0) {
            *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
            *(short *)(local_18 + 2) =
                 ((short)*(undefined4 *)(param_2 + 0x84) +
                 (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
                 (short)*(undefined4 *)(param_2 + 0x6c);
            *local_18 = 0xffffffff;
          }
          else {
            local_14 = javascript_gcSweepObject((int)param_1,local_50,0);
            if (local_14 == 0) {
              *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
              *(short *)(local_18 + 2) =
                   ((short)*(undefined4 *)(param_2 + 0x84) +
                   (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
                   (short)*(undefined4 *)(param_2 + 0x6c);
              *local_18 = 0xffffffff;
            }
            else {
              local_18[4] = 0x50;
              local_18[5] = local_14;
              *(short *)(local_18 + 2) =
                   ((short)*(undefined4 *)(param_2 + 0x84) +
                   (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
                   (short)*(undefined4 *)(param_2 + 0x6c);
              *local_18 = 0x20;
            }
          }
        }
      }
      goto LAB_68165da2;
    }
  }
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
  *(short *)(local_18 + 2) =
       ((short)*(undefined4 *)(param_2 + 0x84) +
       (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
       (short)*(undefined4 *)(param_2 + 0x6c);
  *local_18 = 0xffffffff;
  goto LAB_68165da2;
  while (local_54 = local_54 * 10 + -0x30 + local_c, local_54 < 0x10000) {
LAB_68165ab2:
    local_c = strings_peekChar(param_2);
    if ((0x7f < (int)local_c) || (iVar2 = isdigit(local_c), iVar2 == 0)) {
      *(double *)(local_18 + 4) = (double)local_54;
      if (((param_1[0x59] & 1) != 0) && ((local_c == 0x3d || (local_c == 0x23)))) {
        runtime_snprintf(local_68,0x14,"#%u%c");
        uVar3 = strings_scanToken(param_1,param_2,0,5,0x9e);
        if (uVar3 == 0) {
          *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
          *(short *)(local_18 + 2) =
               ((short)*(undefined4 *)(param_2 + 0x84) +
               (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
               (short)*(undefined4 *)(param_2 + 0x6c);
          *local_18 = 0xffffffff;
          goto LAB_68165da2;
        }
      }
      if (local_c == 0x3d) {
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0x35;
      }
      else if (local_c == 0x23) {
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0x36;
      }
      else {
switchD_68165054_caseD_b:
        strings_scanToken(param_1,param_2,0,0,0x90);
        *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
        *(short *)(local_18 + 2) =
             ((short)*(undefined4 *)(param_2 + 0x84) +
             (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
             (short)*(undefined4 *)(param_2 + 0x6c);
        *local_18 = 0xffffffff;
      }
      goto LAB_68165da2;
    }
  }
  strings_scanToken(param_1,param_2,0,0,0x8f);
  *(uint *)(param_2 + 0x7c) = *(uint *)(param_2 + 0x7c) | 1;
  *(short *)(local_18 + 2) =
       ((short)*(undefined4 *)(param_2 + 0x84) +
       (short)(*(int *)(param_2 + 0x90) - *(int *)(param_2 + 0x88) >> 1)) -
       (short)*(undefined4 *)(param_2 + 0x6c);
  *local_18 = 0xffffffff;
LAB_68165da2:
  return 0;
}



// ============================================================
// Function: strings_peekChar (FUN_68165ed0)
// Address: 68165ed0
// Size: 1369 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_peekChar(int param_1)
{
  uint uVar1;
  int iVar2;
  int local_12c;
  uint local_128;
  byte local_124 [260];
  uint local_20;
  undefined2 *local_1c;
  ushort *local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  if (*(int *)(param_1 + 0x6c) == 0) {
    do {
      if (*(int *)(param_1 + 0x90) == *(int *)(param_1 + 0x8c)) {
        local_14 = *(int *)(param_1 + 0x98) - *(int *)(param_1 + 0x9c) >> 1;
        if (local_14 < 1) {
          if (*(int *)(param_1 + 0xb0) == 0) {
            *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 2;
            goto LAB_68166419;
          }
          local_8 = (uint)((*(uint *)(param_1 + 0x7c) & 0x40) != 0);
          local_14 = strings_readLine((int)local_124,0x100 - local_8,*(FILE **)(param_1 + 0xb0));
          if (local_14 < 1) {
            *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 2;
            goto LAB_68166419;
          }
          local_10 = local_14;
          local_1c = *(undefined2 **)(param_1 + 0x94);
          local_c = 0;
          if ((local_8 != 0) &&
             (*(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xffffffbf, local_124[0] != 10
             )) {
            *local_1c = 10;
            local_c = 1;
            local_14 = local_14 + 1;
            *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + -1;
          }
          local_12c = 0;
          for (; local_c < local_14; local_c = local_c + 1) {
            local_1c[local_c] = (ushort)local_124[local_12c];
            local_12c = local_12c + 1;
          }
          *(undefined2 **)(param_1 + 0x98) = local_1c + local_14;
          *(undefined2 **)(param_1 + 0x9c) = local_1c;
        }
        if (*(int *)(param_1 + 0xb8) != 0) {
          (**(code **)(param_1 + 0xb8))
                    (*(undefined4 *)(param_1 + 0xac),*(undefined4 *)(param_1 + 0x68),
                     *(undefined4 *)(param_1 + 0x9c),local_14,param_1 + 0xc0,
                     *(undefined4 *)(param_1 + 0xbc));
        }
        for (local_18 = *(ushort **)(param_1 + 0x9c); local_18 < *(ushort **)(param_1 + 0x98);
            local_18 = local_18 + 1) {
          if ((*local_18 & 0xdfd0) == 0) {
            if (*local_18 == 10) break;
            if (*local_18 == 0xd) {
              if ((local_18 + 1 < *(ushort **)(param_1 + 0x98)) && (local_18[1] == 10)) {
                local_18 = local_18 + 1;
              }
              break;
            }
            if ((*local_18 == 0x2028) || (*local_18 == 0x2029)) break;
          }
        }
        if (local_18 < *(ushort **)(param_1 + 0x98)) {
          local_14 = ((int)local_18 - *(int *)(param_1 + 0x9c) >> 1) + 1;
        }
        if (0xff < local_14) {
          local_14 = 0xff;
        }
        memcpy(*(void **)(param_1 + 0x88),*(void **)(param_1 + 0x9c),local_14 << 1);
        iVar2 = local_14;
        *(int *)(param_1 + 0x9c) = *(int *)(param_1 + 0x9c) + local_14 * 2;
        local_10 = local_14;
        if (local_18 < *(ushort **)(param_1 + 0x98)) {
          if (*local_18 == 0xd) {
            if (*(short *)(*(int *)(param_1 + 0x88) + -2 + local_14 * 2) == 0xd) {
              if ((local_18 + 1 == *(ushort **)(param_1 + 0x98)) && (*(int *)(param_1 + 0xb0) != 0))
              {
                local_14 = local_14 + -1;
                *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 0x40;
                if (local_14 == 0) {
                  strings_peekChar(param_1);
                  goto LAB_68166419;
                }
              }
              else {
                *(undefined2 *)(*(int *)(param_1 + 0x88) + -2 + local_14 * 2) = 10;
              }
            }
          }
          else if (*local_18 == 10) {
            if (((*(ushort **)(param_1 + 0x94) < local_18) && (local_18[-1] == 0xd)) &&
               (*(short *)(*(int *)(param_1 + 0x88) + -4 + local_14 * 2) == 0xd)) {
              local_14 = local_14 + -1;
              *(undefined2 *)(*(int *)(param_1 + 0x88) + -2 + local_14 * 2) = 10;
            }
          }
          else if ((*local_18 == 0x2028) || (*local_18 == 0x2029)) {
            *(undefined2 *)(*(int *)(param_1 + 0x88) + -2 + local_14 * 2) = 10;
          }
        }
        *(int *)(param_1 + 0x8c) = *(int *)(param_1 + 0x88) + local_14 * 2;
        *(undefined4 *)(param_1 + 0x90) = *(undefined4 *)(param_1 + 0x88);
        if ((*(uint *)(param_1 + 0x7c) & 0x20) == 0) {
          *(int *)(param_1 + 0x84) = *(int *)(param_1 + 0x84) + *(int *)(param_1 + 0x80);
        }
        else {
          *(undefined4 *)(param_1 + 0x84) = 0;
        }
        if (*(short *)(*(int *)(param_1 + 0x8c) + -2) == 10) {
          *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) | 0x20;
        }
        else {
          *(uint *)(param_1 + 0x7c) = *(uint *)(param_1 + 0x7c) & 0xffffffdf;
        }
        *(int *)(param_1 + 0x80) = iVar2;
      }
      local_128 = (uint)**(ushort **)(param_1 + 0x90);
      *(int *)(param_1 + 0x90) = *(int *)(param_1 + 0x90) + 2;
      uVar1 = crypto_getStringCapacity(local_128);
    } while ((0x10000 >> ((byte)uVar1 & 0x1f) & 1U) != 0);
  }
  else {
    iVar2 = *(int *)(param_1 + 0x6c) + -1;
    *(int *)(param_1 + 0x6c) = iVar2;
    local_128 = (uint)*(ushort *)(param_1 + 0x70 + iVar2 * 2);
  }
  if (local_128 == 10) {
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + 1;
  }
LAB_68166419:
  return 0;
}



// ============================================================
// Function: strings_readLine (FUN_68166430)
// Address: 68166430
// Size: 165 bytes
// Params: int param_1, int param_2, FILE * param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_readLine(int param_1,int param_2,FILE *param_3)

{
  int _Ch;
  bool bVar1;
  undefined1 local_14;
  undefined4 local_c;
  
  if (param_2 + -1 < 0) {
    local_c = -1;
  }
  else {
    bVar1 = false;
    for (local_c = 0; local_c < param_2 + -1; local_c = local_c + 1) {
      _Ch = getc(param_3);
      if (_Ch == -1) break;
      local_14 = (undefined1)_Ch;
      *(undefined1 *)(param_1 + local_c) = local_14;
      if (_Ch == 10) {
        local_c = local_c + 1;
        break;
      }
      if (bVar1) {
        ungetc(_Ch,param_3);
        break;
      }
      bVar1 = _Ch == 0xd;
    }
    *(undefined1 *)(param_1 + local_c) = 0;
  }
  return local_c;
}



// ============================================================
// Function: strings_appendToken (FUN_681664e0)
// Address: 681664e0
// Size: 69 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_appendToken(int param_1,int param_2)
{
  if (param_2 != -1) {
    if (param_2 == 10) {
      *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + -1;
    }
    *(undefined2 *)(param_1 + 0x70 + *(int *)(param_1 + 0x6c) * 2) = (undefined2)param_2;
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + 1;
  }
  return 0;
}



// ============================================================
// Function: strings_peekNextChar (FUN_68166530)
// Address: 68166530
// Size: 38 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int strings_peekNextChar(int param_1)

{
  int iVar1;
  
  iVar1 = strings_peekChar(param_1);
  strings_appendToken(param_1,iVar1);
  return iVar1;
}



// ============================================================
// Function: strings_matchAndEmit (FUN_68166560)
// Address: 68166560
// Size: 135 bytes
// Params: int param_1, int param_2, int param_3
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool strings_matchAndEmit(int param_1,int param_2,int param_3)

{
  int iVar1;
  int local_10;
  undefined2 local_c;
  int local_8;
  
  local_8 = 0;
  while ((local_10 = local_8, local_8 < param_2 && (iVar1 = strings_peekChar(param_1), iVar1 != -1))) {
    local_c = (undefined2)iVar1;
    *(undefined2 *)(param_3 + local_8 * 2) = local_c;
    local_8 = local_8 + 1;
  }
  while (local_10 = local_10 + -1, -1 < local_10) {
    strings_appendToken(param_1,(uint)*(ushort *)(param_3 + local_10 * 2));
  }
  return local_8 == param_2;
}



// ============================================================
// Function: strings_emitToken (FUN_681665f0)
// Address: 681665f0
// Size: 29 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_emitToken(int param_1,int param_2)
{
  while (param_2 = param_2 + -1, -1 < param_2) {
    strings_peekChar(param_1);
  }
  return 0;
}



// ============================================================
// Function: strings_getCharAt (FUN_68166610)
// Address: 68166610
// Size: 52 bytes
// Params: int param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool strings_getCharAt(int param_1,int param_2)

{
  int iVar1;
  
  iVar1 = strings_peekChar(param_1);
  if (iVar1 != param_2) {
    strings_appendToken(param_1,iVar1);
  }
  return iVar1 == param_2;
}



// ============================================================
// Function: strings_matchKeyword (FUN_68166650)
// Address: 68166650
// Size: 75 bytes
// Params: int param_1, int * param_2, undefined2 param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 strings_matchKeyword(int param_1,int *param_2,undefined2 param_3)

{
  bool bVar1;
  undefined3 extraout_var;
  
  if ((param_2[2] == param_2[1]) &&
     (bVar1 = strings_growParserBuffer(param_1,param_2), CONCAT31(extraout_var,bVar1) == 0)) {
    return 0;
  }
  *(undefined2 *)param_2[2] = param_3;
  param_2[2] = param_2[2] + 2;
  return 1;
}



// ============================================================
// Function: strings_growParserBuffer (FUN_681666a0)
// Address: 681666a0
// Size: 447 bytes
// Params: int param_1, int * param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool strings_growParserBuffer(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  void *local_20;
  void *local_c;
  int local_8;
  
  local_c = (void *)*param_2;
  iVar2 = param_2[2] - (int)local_c;
  piVar3 = (int *)(param_1 + 0x70);
  if (local_c == (void *)0x0) {
    local_8 = 0x40;
    iVar1 = *(int *)(param_1 + 0x80);
    uVar5 = *(int *)(param_1 + 0x88) + 0x80U & ~*(uint *)(param_1 + 0x88);
    local_20 = *(void **)(iVar1 + 0xc);
    uVar4 = (int)local_20 + uVar5;
    if (*(uint *)(iVar1 + 8) < uVar4) {
      local_20 = (void *)js_getSlotIndex((int)piVar3,uVar5);
    }
    else {
      *(uint *)(iVar1 + 0xc) = uVar4;
    }
    local_c = local_20;
  }
  else {
    iVar6 = param_2[1] - (int)local_c >> 1;
    uVar4 = iVar6 * 2;
    local_8 = iVar6 << 1;
    iVar1 = *(int *)(param_1 + 0x80);
    if (*(int *)(iVar1 + 0xc) ==
        (uVar4 + *(int *)(param_1 + 0x88) & ~*(uint *)(param_1 + 0x88)) + (int)local_c) {
      uVar5 = (iVar6 * 4 + *(int *)(param_1 + 0x88) & ~*(uint *)(param_1 + 0x88)) + (int)local_c;
      if (*(uint *)(iVar1 + 8) < uVar5) {
        if (local_c == *(void **)(iVar1 + 4)) {
          local_c = (void *)js_resolveProperty(piVar3,(int)local_c,uVar4,uVar4);
        }
        else {
          local_c = js_reallocObject(piVar3,local_c,uVar4,uVar4);
        }
      }
      else {
        *(uint *)(iVar1 + 0xc) = uVar5;
      }
    }
    else {
      local_c = js_reallocObject(piVar3,local_c,uVar4,uVar4);
    }
  }
  if (local_c != (void *)0x0) {
    *param_2 = (int)local_c;
    param_2[1] = (int)((int)local_c + local_8 * 2);
    param_2[2] = (int)((int)local_c + (iVar2 >> 1) * 2);
  }
  else {
    xtra_reportError(param_1);
  }
  return local_c != (void *)0x0;
}



// ============================================================
// Function: strings_parseUnicodeEscape (FUN_68166860)
// Address: 68166860
// Size: 463 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_parseUnicodeEscape(int param_1)
{
  bool bVar1;
  undefined3 extraout_var;
  int iVar2;
  short local_14;
  ushort local_12;
  ushort local_10;
  ushort local_e;
  ushort local_c;
  uint local_8;
  
  bVar1 = strings_matchAndEmit(param_1,5,(int)&local_14);
  if ((((((CONCAT31(extraout_var,bVar1) != 0) && (local_14 == 0x75)) && (local_12 < 0x80)) &&
       ((iVar2 = isxdigit((uint)local_12), iVar2 != 0 && (local_10 < 0x80)))) &&
      ((iVar2 = isxdigit((uint)local_10), iVar2 != 0 &&
       ((local_e < 0x80 && (iVar2 = isxdigit((uint)local_e), iVar2 != 0)))))) &&
     ((local_c < 0x80 && (iVar2 = isxdigit((uint)local_c), iVar2 != 0)))) {
    iVar2 = isdigit((uint)local_12);
    if (iVar2 == 0) {
      tolower((uint)local_12);
    }
    iVar2 = isdigit((uint)local_10);
    if (iVar2 == 0) {
      tolower((uint)local_10);
    }
    iVar2 = isdigit((uint)local_e);
    if (iVar2 == 0) {
      tolower((uint)local_e);
    }
    iVar2 = isdigit((uint)local_c);
    if (iVar2 == 0) {
      tolower((uint)local_c);
    }
    strings_emitToken(param_1,5);
  }
  return 0;
}



// ============================================================
// Function: strings_resetScanner (FUN_68166a30)
// Address: 68166a30
// Size: 53 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int strings_resetScanner(int param_1)
{
  if ((*(uint *)(param_1 + 0x7c) & 1) == 0) {
    *(int *)(param_1 + 100) = *(int *)(param_1 + 100) + 1;
    *(uint *)(param_1 + 0x60) = *(int *)(param_1 + 0x60) - 1U & 3;
  }
  return 0;
}



