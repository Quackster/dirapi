// Module: runtime
// Topic: Regular expression parsing, compilation, character class building, and matching engine
// Address range: 0x6812d960 - 0x6812ff10
// Functions (13):
//   runtime_parseRegexAtom
//   runtime_freeRegexTree
//   runtime_regexBacktrack
//   runtime_regexCompareChar
//   runtime_regexMatchRecursive
//   runtime_regexMatchEntry
//   runtime_regexScanForward
//   runtime_regexComputeCharClassSize
//   runtime_regexBuildCharClass
//   runtime_matchRegex
//   runtime_regexSearchFrom
//   runtime_execRegex
//   runtime_getRegexProperty

// ============================================================
// Function: runtime_parseRegexAtom (FUN_6812d960)
// Address: 6812d960
// Size: 1923 bytes
// Params: int * param_1
// Return: char *
// Calling convention: __stdcall
// ============================================================

char * runtime_parseRegexAtom(int *param_1)

{
  ushort uVar1;
  short sVar2;
  short sVar3;
  undefined1 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 uVar7;
  short *psVar8;
  char *pcVar9;
  char cVar10;
  ushort uVar11;
  short sVar12;
  uint uVar13;
  ushort *puVar14;
  ushort *puVar15;
  ushort *puVar16;
  short sVar17;
  undefined1 uVar18;
  int local_10;
  char *local_c;
  ushort *local_8;
  
  puVar14 = (ushort *)param_1[4];
  if ((puVar14 == (ushort *)param_1[3]) || (*puVar14 == 0x7c)) {
    pcVar9 = runtime_allocStringBuffer(0,0);
    return pcVar9;
  }
  local_8 = puVar14;
  switch(*puVar14) {
  case 0x28:
    local_10 = -1;
    if (puVar14[1] == 0x3f) {
      uVar11 = puVar14[2];
      if (uVar11 == 0x21) {
        cVar10 = '*';
      }
      else if (uVar11 == 0x3a) {
        cVar10 = '\'';
      }
      else {
        if (uVar11 != 0x3d) goto LAB_6812da81;
        cVar10 = ')';
      }
      puVar14 = puVar14 + 3;
    }
    else {
LAB_6812da81:
      local_10 = param_1[6];
      param_1[6] = local_10 + 1;
      cVar10 = '\n';
      puVar14 = puVar14 + 1;
    }
    param_1[4] = (int)puVar14;
    if (*puVar14 == 0x29) {
      local_c = runtime_allocStringBuffer(0,0);
    }
    else {
      local_c = javascript_parseRegexAlternation((int)param_1);
      if (local_c == (char *)0x0) {
        return (char *)0x0;
      }
      puVar14 = (ushort *)param_1[4];
      if (*puVar14 != 0x29) {
        strings_scanToken((uint *)*param_1,param_1[1],0,0,0x36);
        return (char *)0x0;
      }
    }
    puVar16 = puVar14 + 1;
    pcVar9 = runtime_allocStringBuffer(cVar10,local_c);
    if (pcVar9 == (char *)0x0) {
      return (char *)0x0;
    }
    pcVar9[1] = local_c[1] & 5;
    *(int *)(pcVar9 + 0xc) = local_10;
    if ((cVar10 == '\n') || (cVar10 == '\'')) {
      puVar4 = runtime_allocStringBuffer(cVar10 + '\x01',0);
      if (puVar4 == (undefined1 *)0x0) {
        return (char *)0x0;
      }
      iVar5 = runtime_parseStringToInt(pcVar9,param_1);
      if (iVar5 == 0) {
        return (char *)0x0;
      }
      *(int *)(puVar4 + 0xc) = local_10;
      param_1[4] = (int)puVar16;
      return pcVar9;
    }
    goto LAB_6812e0c5;
  default:
    goto switchD_6812d99e_caseD_29;
  case 0x2e:
    puVar16 = puVar14 + 1;
    cVar10 = '\f';
    if (*puVar16 == 0x2a) {
      puVar16 = puVar14 + 2;
      cVar10 = '\x18';
      if (*puVar16 == 0x3f) {
        puVar16 = puVar14 + 3;
        cVar10 = '&';
      }
    }
    pcVar9 = runtime_allocStringBuffer(cVar10,0);
    if ((pcVar9 != (char *)0x0) && (cVar10 == '\f')) {
      pcVar9[1] = '\x06';
      param_1[4] = (int)puVar16;
      return pcVar9;
    }
    goto LAB_6812e0c5;
  case 0x5b:
    pcVar9 = runtime_allocStringBuffer(0xd,puVar14 + 1);
    if (pcVar9 == (char *)0x0) {
      return (char *)0x0;
    }
    puVar14 = puVar14 + 1;
    while (puVar16 = puVar14, puVar16 != (ushort *)param_1[3]) {
      puVar14 = puVar16 + 1;
      if (*puVar16 == 0x5d) {
        *(ushort **)(pcVar9 + 0xc) = puVar16;
        pcVar9[0x10] = '\0';
        pcVar9[0x11] = '\0';
        pcVar9[0x12] = '\0';
        pcVar9[0x13] = '\0';
        pcVar9[1] = '\x06';
        param_1[4] = (int)puVar14;
        return pcVar9;
      }
      if (*puVar16 == 0x5c) {
        if (puVar14 == (ushort *)param_1[3]) break;
        puVar14 = puVar16 + 2;
      }
    }
    strings_scanToken((uint *)*param_1,param_1[1],0,0,0x37);
    return (char *)0x0;
  case 0x5c:
    uVar11 = puVar14[1];
    puVar16 = puVar14 + 1;
    if (puVar16 == (ushort *)param_1[3]) {
      strings_scanToken((uint *)*param_1,param_1[1],0,0,0x38);
      return (char *)0x0;
    }
  }
  local_8 = puVar16;
  switch((uint)uVar11) {
  case 0x30:
    if ((*(byte *)(*param_1 + 0x164) & 1) != 0) {
      param_1[4] = (int)(puVar14 + 2);
      return (char *)0x0;
    }
    goto LAB_6812dccd;
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
  case 0x38:
  case 0x39:
    puVar15 = puVar14 + 2;
    uVar13 = uVar11 - 0x30;
    uVar11 = *puVar15;
    while (uVar11 < 0x80) {
      iVar5 = isdigit((uint)uVar11);
      if (iVar5 == 0) break;
      puVar16 = puVar15 + 1;
      puVar15 = puVar15 + 1;
      uVar13 = (uVar13 * 10 - (uint)uVar11) + 0x30;
      uVar11 = *puVar16;
    }
    if (((uVar13 < 10) || (uVar13 <= (uint)param_1[6])) ||
       (puVar16 = puVar14, (*(byte *)(*param_1 + 0x164) & 1) != 0)) {
      pcVar9 = runtime_allocStringBuffer(0x14,0);
      if (pcVar9 == (char *)0x0) {
        return (char *)0x0;
      }
      *(uint *)(pcVar9 + 0xc) = uVar13 - 1;
      pcVar9[1] = '\x04';
      param_1[4] = (int)puVar15;
      return pcVar9;
    }
LAB_6812dccd:
    puVar14 = puVar16 + 1;
    uVar11 = puVar16[1];
    uVar13 = 0;
    while (((0x2f < uVar11 && (uVar11 < 0x38)) &&
           (uVar6 = (uVar11 - 0x30) + uVar13 * 8, uVar6 < 0x100))) {
      puVar14 = puVar14 + 1;
      uVar13 = uVar6;
      uVar11 = *puVar14;
    }
    puVar16 = puVar14 + -1;
    pcVar9 = runtime_allocStringBuffer(0x16,0);
    uVar11 = (ushort)uVar13;
    goto LAB_6812e097;
  default:
    goto switchD_6812dbf4_caseD_3a;
  case 0x44:
    uVar18 = 0xf;
    break;
  case 0x53:
    uVar18 = 0x13;
    break;
  case 0x57:
    uVar18 = 0x11;
    break;
  case 99:
    uVar11 = puVar14[2];
    uVar13 = (uint)uVar11;
    puVar16 = puVar14 + 2;
    local_8 = puVar14;
    if ((uVar11 < 0x80) && (iVar5 = isalpha(uVar13), iVar5 != 0)) {
      uVar6 = crypto_allocString(uVar13);
      if ((uVar6 & 0x100000) == 0) {
        uVar11 = uVar11 ^ 0x40;
      }
      else {
        uVar7 = crypto_allocString(uVar13);
        uVar11 = uVar11 - (short)((int)uVar7 >> 0x16) ^ 0x40;
      }
LAB_6812e089:
      uVar18 = 0x16;
      break;
    }
    goto switchD_6812dbf4_caseD_3a;
  case 100:
    uVar18 = 0xe;
    break;
  case 0x66:
  case 0x6e:
  case 0x72:
  case 0x74:
  case 0x76:
    pcVar9 = runtime_allocStringBuffer(0x16,0);
    psVar8 = certs_findChar((short *)&DAT_68194650,uVar11);
    uVar11 = psVar8[-1];
    goto LAB_6812e097;
  case 0x73:
    uVar18 = 0x12;
    break;
  case 0x75:
    if ((((puVar14[2] < 0x80) && (iVar5 = isxdigit((uint)puVar14[2]), iVar5 != 0)) &&
        (puVar14[3] < 0x80)) &&
       (((iVar5 = isxdigit((uint)puVar14[3]), iVar5 != 0 && (puVar14[4] < 0x80)) &&
        ((iVar5 = isxdigit((uint)puVar14[4]), iVar5 != 0 &&
         ((puVar14[5] < 0x80 && (iVar5 = isxdigit((uint)puVar14[5]), iVar5 != 0)))))))) {
      iVar5 = isdigit((uint)puVar14[2]);
      if (iVar5 == 0) {
        iVar5 = tolower((uint)puVar14[2]);
        sVar17 = (short)iVar5 + -0x57;
      }
      else {
        sVar17 = puVar14[2] - 0x30;
      }
      iVar5 = isdigit((uint)puVar14[3]);
      if (iVar5 == 0) {
        iVar5 = tolower((uint)puVar14[3]);
        sVar2 = (short)iVar5 + -0x57;
      }
      else {
        sVar2 = puVar14[3] - 0x30;
      }
      iVar5 = isdigit((uint)puVar14[4]);
      if (iVar5 == 0) {
        iVar5 = tolower((uint)puVar14[4]);
        sVar12 = (short)iVar5 + -0x57;
      }
      else {
        sVar12 = puVar14[4] - 0x30;
      }
      iVar5 = isdigit((uint)puVar14[5]);
      if (iVar5 == 0) {
        iVar5 = tolower((uint)puVar14[5]);
        sVar3 = (short)iVar5 + -0x57;
      }
      else {
        sVar3 = puVar14[5] - 0x30;
      }
      uVar11 = ((sVar17 * 0x10 + sVar2) * 0x10 + sVar12) * 0x10 + sVar3;
      puVar16 = puVar14 + 5;
      goto LAB_6812e089;
    }
switchD_6812dbf4_caseD_3a:
    puVar14 = local_8;
switchD_6812d99e_caseD_29:
    do {
      puVar15 = puVar14;
      uVar11 = puVar15[1];
      puVar14 = puVar15 + 1;
      if ((uVar11 == 0) || (puVar14 == (ushort *)param_1[3])) break;
      psVar8 = certs_findChar(u_______________68193088,uVar11);
    } while (psVar8 == (short *)0x0);
    uVar13 = (int)puVar14 - (int)local_8 >> 1;
    puVar16 = puVar14;
    if (((puVar14 != (ushort *)param_1[3]) && (1 < uVar13)) &&
       (psVar8 = certs_findChar(u______681930a4,uVar11), psVar8 != (short *)0x0)) {
      uVar13 = uVar13 - 1;
      puVar16 = puVar15;
    }
    if (0xff < uVar13) {
      uVar13 = 0xff;
      puVar16 = local_8 + 0xff;
    }
    pcVar9 = runtime_allocStringBuffer('\x16' - (uVar13 != 1),local_8);
    if (pcVar9 == (char *)0x0) {
      return (char *)0x0;
    }
    pcVar9[1] = '\x04';
    if (1 < uVar13) {
      *(ushort **)(pcVar9 + 0xc) = puVar16;
      param_1[4] = (int)puVar16;
      return pcVar9;
    }
    pcVar9[1] = '\x06';
    *(ushort *)(pcVar9 + 0xc) = *local_8;
LAB_6812e0c5:
    param_1[4] = (int)puVar16;
    return pcVar9;
  case 0x77:
    uVar18 = 0x10;
    break;
  case 0x78:
    uVar11 = puVar14[2];
    uVar13 = (uint)uVar11;
    if ((uVar11 < 0x80) && (iVar5 = isxdigit(uVar13), iVar5 != 0)) {
      iVar5 = isdigit(uVar13);
      if (iVar5 == 0) {
        iVar5 = tolower(uVar13);
        uVar11 = (short)iVar5 - 0x57;
      }
      else {
        uVar11 = uVar11 - 0x30;
      }
      uVar1 = puVar14[3];
      uVar13 = (uint)uVar1;
      if ((uVar1 < 0x80) && (iVar5 = isxdigit(uVar13), iVar5 != 0)) {
        iVar5 = isdigit(uVar13);
        puVar16 = puVar14 + 3;
        if (iVar5 == 0) {
          iVar5 = tolower(uVar13);
          uVar11 = uVar11 * 0x10 + (short)iVar5 + -0x57;
          pcVar9 = runtime_allocStringBuffer(0x16,0);
        }
        else {
          uVar11 = uVar11 * 0x10 + (uVar1 - 0x30);
          pcVar9 = runtime_allocStringBuffer(0x16,0);
        }
        goto LAB_6812e097;
      }
      if ((*(int *)(*param_1 + 0xc) != 0) && (*(int *)(*param_1 + 0xc) < 0x8d)) {
        puVar16 = puVar14 + 2;
        pcVar9 = runtime_allocStringBuffer(0x16,0);
        goto LAB_6812e097;
      }
    }
    pcVar9 = runtime_allocStringBuffer(0x16,0);
    uVar11 = 0x78;
    goto LAB_6812e097;
  }
  pcVar9 = runtime_allocStringBuffer(uVar18,0);
LAB_6812e097:
  if (pcVar9 != (char *)0x0) {
    *(ushort *)(pcVar9 + 0xc) = uVar11;
    pcVar9[1] = '\x06';
  }
  param_1[4] = (int)(puVar16 + 1);
  return pcVar9;
}



// ============================================================
// Function: runtime_freeRegexTree (FUN_6812e1c0)
// Address: 6812e1c0
// Size: 129 bytes
// Params: undefined4 param_1, undefined1 * param_2, undefined1 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_freeRegexTree(undefined4 param_1,undefined1 *param_2,undefined1 *param_3)
{
  char *pcVar1;
  undefined1 *puVar2;
  
  while ((param_2 != (undefined1 *)0x0 && (param_2 != param_3))) {
    switch(*param_2) {
    case 1:
      for (pcVar1 = *(char **)(param_2 + 4); (pcVar1 != (char *)0x0 && (*pcVar1 == '\x01'));
          pcVar1 = *(char **)(pcVar1 + 4)) {
      }
      runtime_freeRegexTree(param_1,*(undefined1 **)(param_2 + 8),pcVar1);
      break;
    case 6:
    case 7:
    case 8:
    case 9:
    case 10:
    case 0x27:
    case 0x29:
    case 0x2a:
      runtime_freeRegexTree(param_1,*(undefined1 **)(param_2 + 8),*(undefined1 **)(param_2 + 4));
      break;
    case 0xd:
      if (*(int *)(param_2 + 0x10) != 0) {
        xtra_checkAndFlush(param_1,*(int *)(param_2 + 0x10));
      }
    }
    puVar2 = *(undefined1 **)(param_2 + 4);
    xtra_checkAndFlush(param_1,(int)param_2);
    param_2 = puVar2;
  }
  return 0;
}



// ============================================================
// Function: runtime_regexBacktrack (FUN_6812e280)
// Address: 6812e280
// Size: 40 bytes
// Params: undefined4 param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_regexBacktrack(undefined4 param_1,int *param_2)
{
  *param_2 = *param_2 + -1;
  if (*param_2 == 0) {
    runtime_freeRegexTree(param_1,(undefined1 *)param_2[2],(undefined1 *)0x0);
    xtra_checkAndFlush(param_1,(int)param_2);
  }
  return 0;
}



// ============================================================
// Function: runtime_regexCompareChar (FUN_6812e2b0)
// Address: 6812e2b0
// Size: 199 bytes
// Params: ushort param_1, byte param_2
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall runtime_regexCompareChar(ushort param_1,byte param_2)

{
  ushort in_AX;
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  uint uVar5;
  
  if (in_AX == param_1) {
    return 1;
  }
  if ((param_2 & 1) == 0) {
    return 0;
  }
  uVar4 = (uint)in_AX;
  uVar1 = crypto_allocString(uVar4);
  if ((uVar1 & 0x100000) != 0) {
    iVar2 = crypto_allocString(uVar4);
    uVar4 = uVar4 - (iVar2 >> 0x16);
  }
  uVar1 = crypto_allocString((uint)param_1);
  if ((uVar1 & 0x100000) != 0) {
    uVar3 = crypto_allocString((uint)param_1);
    param_1 = param_1 - (short)((int)uVar3 >> 0x16);
  }
  uVar1 = uVar4 & 0xffff;
  if ((ushort)uVar4 != param_1) {
    uVar4 = crypto_allocString(uVar1);
    if ((uVar4 & 0x200000) != 0) {
      iVar2 = crypto_allocString(uVar1);
      uVar1 = (iVar2 >> 0x16) + uVar1;
    }
    uVar5 = (uint)param_1;
    uVar4 = crypto_allocString(uVar5);
    if ((uVar4 & 0x200000) != 0) {
      iVar2 = crypto_allocString(uVar5);
      uVar5 = (iVar2 >> 0x16) + uVar5;
    }
    if (uVar1 != uVar5) {
      return 0;
    }
  }
  return 1;
}



// ============================================================
// Function: runtime_regexMatchRecursive (FUN_6812e380)
// Address: 6812e380
// Size: 243 bytes
// Params: int * param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_regexMatchRecursive(int *param_1,int param_2,int param_3)

{
  uint uVar1;
  ushort *puVar2;
  int iVar3;
  ushort *puVar4;
  
  uVar1 = ((uint *)*param_1)[8];
  puVar2 = runtime_matchRegex((uint *)*param_1,(undefined1 *)param_1[1],(undefined1 *)param_1[2],
                        (ushort *)param_2);
  if (puVar2 == (ushort *)0x0) {
    puVar2 = runtime_matchRegex((uint *)*param_1,(undefined1 *)param_1[2],(undefined1 *)param_1[3],
                          (ushort *)param_2);
    if (puVar2 != (ushort *)0x0) {
      *(uint *)(*param_1 + 0x20) = uVar1;
      if (param_3 != 0) {
        runtime_matchRegex((uint *)*param_1,(undefined1 *)param_1[1],(undefined1 *)param_1[2],
                     (ushort *)param_3);
      }
      return param_2;
    }
  }
  else {
    if (puVar2 == (ushort *)param_2) {
      if (param_3 != 0) {
        runtime_matchRegex((uint *)*param_1,(undefined1 *)param_1[1],(undefined1 *)param_1[2],
                     (ushort *)param_3);
      }
      return (int)puVar2;
    }
    if ((param_1[5] == 0) || (param_1[4] = param_1[4] + 1, param_1[4] < param_1[5])) {
      iVar3 = runtime_regexMatchRecursive(param_1,(int)puVar2,param_2);
      if (iVar3 != 0) {
        return iVar3;
      }
      if (param_1[5] != 0) {
        param_1[4] = param_1[4] + -1;
      }
    }
    *(uint *)(*param_1 + 0x20) = uVar1;
    puVar4 = runtime_matchRegex((uint *)*param_1,(undefined1 *)param_1[2],(undefined1 *)param_1[3],puVar2)
    ;
    if (puVar4 != (ushort *)0x0) {
      runtime_matchRegex((uint *)*param_1,(undefined1 *)param_1[1],(undefined1 *)param_1[2],
                   (ushort *)param_2);
      return (int)puVar2;
    }
  }
  return 0;
}



// ============================================================
// Function: runtime_regexMatchEntry (FUN_6812e480)
// Address: 6812e480
// Size: 100 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_regexMatchEntry(int param_1,int param_2)
{
  int in_EAX;
  int iVar1;
  int unaff_EBX;
  int unaff_EDI;
  int local_1c;
  undefined4 local_18;
  undefined4 local_14;
  int local_10;
  
  local_18 = *(undefined4 *)(in_EAX + 8);
  local_1c = param_1;
  local_14 = *(undefined4 *)(in_EAX + 4);
  local_10 = 0;
  iVar1 = runtime_regexMatchRecursive(&local_1c,unaff_EBX,unaff_EDI);
  if ((iVar1 == 0) && (param_2 != 0)) {
    local_10 = param_2;
    runtime_regexMatchRecursive(&local_1c,unaff_EBX,unaff_EDI);
  }
  return 0;
}



// ============================================================
// Function: runtime_regexScanForward (FUN_6812e4f0)
// Address: 6812e4f0
// Size: 70 bytes
// Return: int
// Calling convention: __stdcall
// ============================================================

int runtime_regexScanForward(void)

{
  ushort *in_EAX;
  ushort *puVar1;
  ushort *puVar2;
  uint *unaff_EBX;
  int unaff_ESI;
  
  puVar1 = runtime_matchRegex(unaff_EBX,*(undefined1 **)(unaff_ESI + 4),(undefined1 *)0x0,in_EAX);
  while( true ) {
    if (puVar1 != (ushort *)0x0) {
      return (int)in_EAX;
    }
    puVar2 = runtime_matchRegex(unaff_EBX,*(undefined1 **)(unaff_ESI + 8),*(undefined1 **)(unaff_ESI + 4),
                          in_EAX);
    if (puVar2 == (ushort *)0x0) break;
    if (puVar2 == in_EAX) {
      return (int)puVar2;
    }
    puVar1 = runtime_matchRegex(unaff_EBX,*(undefined1 **)(unaff_ESI + 4),(undefined1 *)0x0,puVar2);
    in_EAX = puVar2;
  }
  return 0;
}



// ============================================================
// Function: runtime_regexComputeCharClassSize (FUN_6812e540)
// Address: 6812e540
// Size: 594 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int runtime_regexComputeCharClassSize(int param_1,int param_2)
{
  ushort uVar1;
  ushort *puVar2;
  ushort *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  ushort *puVar11;
  ushort *puVar12;
  ushort *local_c;
  uint local_8;
  
  puVar2 = *(ushort **)(param_2 + 0xc);
  puVar11 = *(ushort **)(param_2 + 8);
  local_8 = 0;
  if (puVar11 < puVar2) {
    local_c = puVar11 + 5;
    do {
      uVar10 = (uint)*puVar11;
      puVar3 = local_c + 1;
      puVar12 = puVar11 + 1;
      if (uVar10 == 0x5c) {
        if (((((puVar3 <= puVar2) && (*puVar12 == 0x75)) && (puVar11[2] < 0x80)) &&
            ((((iVar4 = isxdigit((uint)puVar11[2]), iVar4 != 0 && (puVar11[3] < 0x80)) &&
              ((iVar4 = isxdigit((uint)puVar11[3]), iVar4 != 0 &&
               ((puVar11[4] < 0x80 && (iVar4 = isxdigit((uint)puVar11[4]), iVar4 != 0)))))) &&
             (puVar11[5] < 0x80)))) && (iVar4 = isxdigit((uint)puVar11[5]), iVar4 != 0)) {
          iVar4 = isdigit((uint)puVar11[2]);
          if (iVar4 == 0) {
            iVar4 = tolower((uint)puVar11[2]);
            iVar4 = iVar4 + -0x57;
          }
          else {
            iVar4 = puVar11[2] - 0x30;
          }
          iVar5 = isdigit((uint)puVar11[3]);
          if (iVar5 == 0) {
            iVar5 = tolower((uint)puVar11[3]);
            iVar5 = iVar5 + -0x57;
          }
          else {
            iVar5 = puVar11[3] - 0x30;
          }
          iVar6 = isdigit((uint)puVar11[4]);
          if (iVar6 == 0) {
            iVar6 = tolower((uint)puVar11[4]);
            iVar6 = iVar6 + -0x57;
          }
          else {
            iVar6 = puVar11[4] - 0x30;
          }
          iVar7 = isdigit((uint)puVar11[5]);
          if (iVar7 == 0) {
            iVar7 = tolower((uint)puVar11[5]);
            iVar7 = iVar7 + -0x57;
          }
          else {
            iVar7 = puVar11[5] - 0x30;
          }
          puVar12 = puVar11 + 6;
          uVar10 = ((iVar4 * 0x10 + iVar5) * 0x10 + iVar6) * 0x10 + iVar7 & 0xffff;
          puVar3 = local_c + 6;
          goto LAB_6812e6e3;
        }
        uVar1 = *puVar12;
        if (((uVar1 == 0x53) || (uVar1 == 0x57)) || (uVar1 == 0x44)) {
          local_8 = 0xffff;
          break;
        }
        uVar10 = 0xff;
        local_c = puVar3;
        if (local_8 < 0xff) goto LAB_6812e769;
      }
      else {
LAB_6812e6e3:
        local_c = puVar3;
        if ((*(byte *)(param_1 + 0x1c) & 1) != 0) {
          uVar8 = crypto_allocString(uVar10);
          uVar9 = uVar10;
          if ((uVar8 & 0x100000) != 0) {
            iVar4 = crypto_allocString(uVar10);
            uVar9 = uVar10 - (iVar4 >> 0x16) & 0xffff;
          }
          if (local_8 < uVar9) {
            local_8 = uVar9;
          }
          uVar8 = crypto_allocString(uVar9);
          if ((uVar8 & 0x200000) != 0) {
            iVar4 = crypto_allocString(uVar9);
            uVar9 = (iVar4 >> 0x16) + uVar9 & 0xffff;
          }
          if (local_8 < uVar9) {
            local_8 = uVar9;
          }
        }
        if (local_8 < uVar10) {
LAB_6812e769:
          local_8 = uVar10;
        }
      }
      puVar11 = puVar12;
    } while (puVar12 < puVar2);
  }
  *(short *)(param_2 + 0xe) = (short)(local_8 + 8 >> 3);
  return 0;
}



// ============================================================
// Function: runtime_regexBuildCharClass (FUN_6812e7a0)
// Address: 6812e7a0
// Size: 2038 bytes
// Params: uint * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_regexBuildCharClass(uint *param_1)

{
  byte *pbVar1;
  ushort uVar2;
  ushort *puVar3;
  uint uVar4;
  bool bVar5;
  int in_EAX;
  void *_Dst;
  short *psVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  byte bVar10;
  byte bVar11;
  ushort *puVar12;
  uint uVar13;
  uint _Size;
  int iVar14;
  uint uVar15;
  uint uVar16;
  uint local_18;
  int local_10;
  ushort *local_c;
  
  puVar12 = *(ushort **)(in_EAX + 8);
  puVar3 = *(ushort **)(in_EAX + 0xc);
  runtime_regexComputeCharClassSize((int)param_1,in_EAX);
  _Dst = (void *)xtra_getPropertyById(*param_1,(uint)*(ushort *)(in_EAX + 0xe));
  *(void **)(in_EAX + 0x10) = _Dst;
  if (_Dst == (void *)0x0) {
    xtra_reportError(*param_1);
    return 0;
  }
  if (*puVar12 == 0x5e) {
    puVar12 = puVar12 + 1;
    local_10 = CONCAT31((*(unsigned int *)((char *)&local_10 + 1)),0xff);
  }
  else {
    local_10 = (uint)(*(unsigned int *)((char *)&local_10 + 1)) << 8;
  }
  _Size = (uint)*(ushort *)(in_EAX + 0xe);
  if (_Size != 0) {
    memset(_Dst,local_10,_Size);
  }
  uVar4 = _Size * 8;
  bVar5 = false;
  uVar16 = uVar4;
joined_r0x6812e82f:
  if (puVar3 <= puVar12) {
    return 1;
  }
  local_c = puVar12 + 1;
  uVar15 = (uint)*puVar12;
  if (*puVar12 != 0x5c) goto switchD_6812e866_caseD_38;
  uVar2 = *local_c;
  uVar13 = (uint)uVar2;
  local_c = puVar12 + 2;
  bVar10 = (byte)uVar16;
  uVar15 = uVar13;
  switch(uVar13) {
  case 0x30:
  case 0x31:
  case 0x32:
  case 0x33:
  case 0x34:
  case 0x35:
  case 0x36:
  case 0x37:
    uVar2 = *local_c;
    uVar15 = uVar13 - 0x30;
    if (uVar2 - 0x30 < 8) {
      local_c = puVar12 + 3;
      uVar13 = (uVar2 - 0x30) + (uVar13 - 0x30) * 8;
      uVar2 = *local_c;
      uVar15 = uVar13;
      if (uVar2 - 0x30 < 8) {
        local_c = puVar12 + 4;
        uVar15 = (uVar2 - 0x30) + uVar13 * 8;
        if (0xff < uVar15) {
          local_c = puVar12 + 3;
          uVar15 = uVar13;
        }
      }
    }
    break;
  case 0x44:
    if (bVar5) {
      bVar10 = (byte)(1 << (bVar10 & 7));
      if ((char)local_10 == '\0') {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 | bVar10;
        *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) | 0x20;
      }
      else {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 & ~bVar10;
        *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) & 0xdf;
      }
      bVar5 = false;
    }
    uVar15 = 0;
    do {
      bVar10 = (byte)(1 << ((byte)uVar15 & 7));
      if ((char)local_10 == '\0') {
        pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 | bVar10;
      }
      else {
        pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 & ~bVar10;
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 < 0x30);
    uVar15 = 0x3a;
    puVar12 = local_c;
    if (0x3a < uVar4) {
      do {
        bVar10 = (byte)(1 << ((byte)uVar15 & 7));
        if ((char)local_10 == '\0') {
          pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
          *pbVar1 = *pbVar1 | bVar10;
        }
        else {
          pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
          *pbVar1 = *pbVar1 & ~bVar10;
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 < uVar4);
    }
    goto joined_r0x6812e82f;
  case 0x53:
    if (bVar5) {
      bVar10 = (byte)(1 << (bVar10 & 7));
      if ((char)local_10 == '\0') {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 | bVar10;
        *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) | 0x20;
      }
      else {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 & ~bVar10;
        *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) & 0xdf;
      }
      bVar5 = false;
    }
    uVar15 = 0;
    puVar12 = local_c;
    if (_Size != 0) {
      do {
        uVar13 = crypto_allocString(uVar15);
        if ((uVar13 & 0x70000) != 0x40000) {
          bVar10 = (byte)(1 << ((byte)uVar15 & 7));
          if ((char)local_10 == '\0') {
            pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
            *pbVar1 = *pbVar1 | bVar10;
          }
          else {
            pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
            *pbVar1 = *pbVar1 & ~bVar10;
          }
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 < uVar4);
    }
    goto joined_r0x6812e82f;
  case 0x57:
    if (bVar5) {
      bVar10 = (byte)(1 << (bVar10 & 7));
      if ((char)local_10 == '\0') {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 | bVar10;
        *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) | 0x20;
      }
      else {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 & ~bVar10;
        *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) & 0xdf;
      }
      bVar5 = false;
    }
    uVar15 = 0;
    puVar12 = local_c;
    if (_Size != 0) {
      do {
        uVar13 = crypto_getStringCapacity(uVar15);
        if (((0x23e >> ((byte)uVar13 & 0x1f) & 1U) == 0) && (uVar15 != 0x5f)) {
          bVar10 = (byte)(1 << ((byte)uVar15 & 7));
          if ((char)local_10 == '\0') {
            pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
            *pbVar1 = *pbVar1 | bVar10;
          }
          else {
            pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
            *pbVar1 = *pbVar1 & ~bVar10;
          }
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 < uVar4);
    }
    goto joined_r0x6812e82f;
  case 0x62:
  case 0x66:
  case 0x6e:
  case 0x72:
  case 0x74:
  case 0x76:
    psVar6 = certs_findChar((short *)&DAT_68194650,uVar2);
    uVar15 = (uint)(ushort)psVar6[-1];
    break;
  case 99:
    uVar13 = (uint)*local_c;
    local_c = puVar12 + 3;
    uVar15 = crypto_allocString(uVar13);
    if ((uVar15 & 0x100000) != 0) {
      iVar9 = crypto_allocString(uVar13);
      uVar13 = uVar13 - (iVar9 >> 0x16);
    }
    uVar15 = uVar13 ^ 0x40;
    break;
  case 100:
    if (bVar5) {
      bVar10 = (byte)(1 << (bVar10 & 7));
      if ((char)local_10 == '\0') {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 | bVar10;
        *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) | 0x20;
      }
      else {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 & ~bVar10;
        *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) & 0xdf;
      }
      bVar5 = false;
    }
    uVar15 = 0x30;
    do {
      bVar10 = (byte)(1 << ((byte)uVar15 & 7));
      if ((char)local_10 == '\0') {
        pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 | bVar10;
      }
      else {
        pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 & ~bVar10;
      }
      uVar15 = uVar15 + 1;
      puVar12 = local_c;
    } while (uVar15 < 0x3a);
    goto joined_r0x6812e82f;
  case 0x73:
    if (bVar5) {
      bVar10 = (byte)(1 << (bVar10 & 7));
      if ((char)local_10 == '\0') {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 | bVar10;
        *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) | 0x20;
      }
      else {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 & ~bVar10;
        *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) & 0xdf;
      }
      bVar5 = false;
    }
    uVar15 = 0;
    puVar12 = local_c;
    if (_Size != 0) {
      do {
        uVar13 = crypto_allocString(uVar15);
        if ((uVar13 & 0x70000) == 0x40000) {
          bVar10 = (byte)(1 << ((byte)uVar15 & 7));
          if ((char)local_10 == '\0') {
            pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
            *pbVar1 = *pbVar1 | bVar10;
          }
          else {
            pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
            *pbVar1 = *pbVar1 & ~bVar10;
          }
        }
        uVar15 = uVar15 + 1;
      } while (uVar15 < uVar4);
    }
    goto joined_r0x6812e82f;
  case 0x75:
    if ((((*local_c < 0x80) && (iVar9 = isxdigit((uint)*local_c), iVar9 != 0)) &&
        (puVar12[3] < 0x80)) &&
       (((iVar9 = isxdigit((uint)puVar12[3]), iVar9 != 0 && (puVar12[4] < 0x80)) &&
        ((iVar9 = isxdigit((uint)puVar12[4]), iVar9 != 0 &&
         ((puVar12[5] < 0x80 && (iVar9 = isxdigit((uint)puVar12[5]), iVar9 != 0)))))))) {
      iVar9 = isdigit((uint)*local_c);
      if (iVar9 == 0) {
        iVar9 = tolower((uint)*local_c);
        iVar9 = iVar9 + -0x57;
      }
      else {
        iVar9 = *local_c - 0x30;
      }
      iVar14 = isdigit((uint)puVar12[3]);
      if (iVar14 == 0) {
        iVar14 = tolower((uint)puVar12[3]);
        iVar14 = iVar14 + -0x57;
      }
      else {
        iVar14 = puVar12[3] - 0x30;
      }
      iVar7 = isdigit((uint)puVar12[4]);
      if (iVar7 == 0) {
        iVar7 = tolower((uint)puVar12[4]);
        iVar7 = iVar7 + -0x57;
      }
      else {
        iVar7 = puVar12[4] - 0x30;
      }
      iVar8 = isdigit((uint)puVar12[5]);
      if (iVar8 == 0) {
        iVar8 = tolower((uint)puVar12[5]);
        iVar8 = iVar8 + -0x57;
      }
      else {
        iVar8 = puVar12[5] - 0x30;
      }
      local_c = puVar12 + 6;
      uVar15 = (iVar7 + (iVar9 * 0x10 + iVar14) * 0x10) * 0x10 + iVar8;
    }
    break;
  case 0x77:
    goto switchD_6812e866_caseD_77;
  case 0x78:
    uVar2 = *local_c;
    if ((uVar2 < 0x80) && (iVar9 = isxdigit((uint)uVar2), iVar9 != 0)) {
      iVar14 = (int)(char)uVar2;
      iVar9 = isdigit(iVar14);
      if (iVar9 == 0) {
        iVar9 = tolower(iVar14);
        uVar15 = iVar9 - 0x57;
      }
      else {
        uVar15 = iVar14 - 0x30;
      }
      uVar2 = puVar12[3];
      local_c = puVar12 + 4;
      if ((uVar2 < 0x80) && (iVar9 = isxdigit((uint)uVar2), iVar9 != 0)) {
        iVar14 = (int)(char)uVar2;
        iVar9 = isdigit(iVar14);
        if (iVar9 == 0) {
          iVar9 = tolower(iVar14);
          uVar15 = uVar15 * 0x10 + iVar9 + -0x57;
        }
        else {
          uVar15 = uVar15 * 0x10 + iVar14 + -0x30;
        }
      }
    }
    else {
      uVar15 = 0x78;
    }
  }
switchD_6812e866_caseD_38:
  if (bVar5) {
    if (uVar15 < uVar16) {
      xtra_invokeMethod(*param_1,xtra_getErrorString,0,0x39);
      return 0;
    }
    bVar5 = false;
    local_18 = uVar16;
  }
  else {
    local_18 = uVar15;
    if (((*local_c == 0x2d) && (puVar12 = local_c + 1, puVar12 < puVar3)) && (*puVar12 != 0x5d)) {
      bVar5 = true;
      uVar16 = uVar15;
      goto joined_r0x6812e82f;
    }
  }
  bVar10 = (byte)local_18 & 7;
  bVar10 = '\x01' << bVar10 | 1U >> 8 - bVar10;
  for (; puVar12 = local_c, uVar16 = uVar15, local_18 <= uVar15; local_18 = local_18 + 1) {
    if ((char)local_10 == '\0') {
      pbVar1 = (byte *)((local_18 >> 3) + (int)_Dst);
      *pbVar1 = *pbVar1 | bVar10;
    }
    else {
      pbVar1 = (byte *)((local_18 >> 3) + (int)_Dst);
      *pbVar1 = *pbVar1 & ~bVar10;
    }
    if ((param_1[7] & 1) != 0) {
      uVar13 = crypto_allocString(local_18);
      uVar16 = local_18;
      if ((uVar13 & 0x100000) != 0) {
        iVar9 = crypto_allocString(local_18);
        uVar16 = local_18 - (iVar9 >> 0x16);
      }
      bVar11 = (byte)(1 << ((byte)uVar16 & 7));
      if ((char)local_10 == '\0') {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 | bVar11;
      }
      else {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 & ~bVar11;
      }
      uVar13 = crypto_allocString(uVar16);
      if ((uVar13 & 0x200000) != 0) {
        iVar9 = crypto_allocString(uVar16);
        uVar16 = uVar16 + (iVar9 >> 0x16);
      }
      bVar11 = (byte)(1 << ((byte)uVar16 & 7));
      if ((char)local_10 == '\0') {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 | bVar11;
      }
      else {
        pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
        *pbVar1 = *pbVar1 & ~bVar11;
      }
    }
    bVar10 = bVar10 << 1 | (char)bVar10 < '\0';
  }
  goto joined_r0x6812e82f;
switchD_6812e866_caseD_77:
  if (bVar5) {
    bVar10 = (byte)(1 << (bVar10 & 7));
    if ((char)local_10 == '\0') {
      pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
      *pbVar1 = *pbVar1 | bVar10;
      *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) | 0x20;
    }
    else {
      pbVar1 = (byte *)((uVar16 >> 3) + (int)_Dst);
      *pbVar1 = *pbVar1 & ~bVar10;
      *(byte *)((int)_Dst + 5) = *(byte *)((int)_Dst + 5) & 0xdf;
    }
    bVar5 = false;
  }
  uVar15 = 0;
  puVar12 = local_c;
  if (_Size != 0) {
    do {
      uVar13 = crypto_getStringCapacity(uVar15);
      if (((0x23e >> ((byte)uVar13 & 0x1f) & 1U) != 0) || (uVar15 == 0x5f)) {
        bVar10 = (byte)(1 << ((byte)uVar15 & 7));
        if ((char)local_10 == '\0') {
          pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
          *pbVar1 = *pbVar1 | bVar10;
        }
        else {
          pbVar1 = (byte *)((uVar15 >> 3) + (int)_Dst);
          *pbVar1 = *pbVar1 & ~bVar10;
        }
      }
      uVar15 = uVar15 + 1;
    } while (uVar15 < uVar4);
  }
  goto joined_r0x6812e82f;
}



// ============================================================
// Function: runtime_matchRegex (FUN_6812f020)
// Address: 6812f020
// Size: 2122 bytes
// Params: uint * param_1, undefined1 * param_2, undefined1 * param_3, ushort * param_4
// Return: ushort *
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

ushort * runtime_matchRegex(uint *param_1,undefined1 *param_2,undefined1 *param_3,ushort *param_4)

{
  undefined4 *puVar1;
  uint *puVar2;
  ushort uVar3;
  ushort *puVar4;
  undefined1 *puVar5;
  uint uVar6;
  ushort *puVar7;
  ushort *puVar8;
  uint uVar9;
  int iVar10;
  undefined1 *puVar11;
  ushort *puVar12;
  uint local_c;
  
  puVar4 = (ushort *)param_1[4];
  if (param_2 != param_3) {
    while (puVar5 = param_2, param_2 != (undefined1 *)0x0) {
      puVar12 = param_4;
      switch(*param_2) {
      case 1:
        puVar1 = (undefined4 *)(param_2 + 4);
        param_2 = *(undefined1 **)(param_2 + 8);
        if (*(char *)*puVar1 == '\x01') {
          uVar9 = param_1[8];
          puVar7 = runtime_matchRegex(param_1,param_2,param_3,param_4);
          if (puVar7 != (ushort *)0x0) {
            return puVar7;
          }
          uVar6 = uVar9;
          if (uVar9 < param_1[8]) {
            do {
              *(undefined4 *)(param_1[10] + uVar6 * 8) = 0;
              uVar6 = uVar6 + 1;
            } while (uVar6 < param_1[8]);
          }
          param_1[8] = uVar9;
          break;
        }
        goto LAB_6812f13e;
      case 2:
        if (param_4 != (ushort *)param_1[3]) {
          if (puVar4 <= param_4) {
            return (ushort *)0x0;
          }
          if ((*(int *)(*param_1 + 0xb8) == 0) && ((param_1[7] & 4) == 0)) {
            return (ushort *)0x0;
          }
          uVar3 = param_4[-1];
joined_r0x6812f5b1:
          if ((((uVar3 != 10) && (uVar3 != 0xd)) && (uVar3 != 0x2028)) && (uVar3 != 0x2029)) {
            return (ushort *)0x0;
          }
        }
        break;
      case 3:
      case 0x1a:
        if (param_4 != puVar4) {
          if ((*(int *)(*param_1 + 0xb8) == 0) && ((param_1[7] & 4) == 0)) {
            return (ushort *)0x0;
          }
          uVar3 = *param_4;
          goto joined_r0x6812f5b1;
        }
        break;
      case 4:
        if ((param_4 == (ushort *)param_1[3]) ||
           ((uVar9 = crypto_getStringCapacity((uint)param_4[-1]), (0x23e >> ((byte)uVar9 & 0x1f) & 1U) == 0 &&
            (param_4[-1] != 0x5f)))) {
          param_2 = (undefined1 *)0x1;
        }
        else {
          param_2 = (undefined1 *)0x0;
        }
        if ((param_4 < puVar4) &&
           ((uVar9 = crypto_getStringCapacity((uint)*param_4), (0x23e >> ((byte)uVar9 & 0x1f) & 1U) != 0 ||
            (*param_4 == 0x5f)))) {
          puVar11 = (undefined1 *)0x0;
        }
        else {
          puVar11 = (undefined1 *)0x1;
        }
        if (param_2 == puVar11) {
          return (ushort *)0x0;
        }
        break;
      case 5:
        if ((param_4 == (ushort *)param_1[3]) ||
           ((uVar9 = crypto_getStringCapacity((uint)param_4[-1]), (0x23e >> ((byte)uVar9 & 0x1f) & 1U) == 0 &&
            (param_4[-1] != 0x5f)))) {
          param_2 = (undefined1 *)0x1;
        }
        else {
          param_2 = (undefined1 *)0x0;
        }
        if ((param_4 < puVar4) &&
           ((uVar9 = crypto_getStringCapacity((uint)*param_4), (0x23e >> ((byte)uVar9 & 0x1f) & 1U) != 0 ||
            (*param_4 == 0x5f)))) {
          puVar11 = (undefined1 *)0x1;
        }
        else {
          puVar11 = (undefined1 *)0x0;
        }
        if (param_2 == puVar11) {
          return (ushort *)0x0;
        }
        break;
      case 6:
        local_c = 0;
        puVar8 = (ushort *)0x0;
        if (*(short *)(param_2 + 0xc) != 0) {
          do {
            puVar12 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 8),
                                   *(undefined1 **)(param_2 + 4),param_4);
            if (puVar12 == (ushort *)0x0) {
              return (ushort *)0x0;
            }
            local_c = local_c + 1;
            puVar8 = param_4;
            param_4 = puVar12;
          } while (local_c < *(ushort *)(param_2 + 0xc));
        }
        puVar12 = param_4;
        if (local_c != *(ushort *)(param_2 + 0xe)) {
          if ((param_2[1] & 0x80) != 0) goto LAB_6812f1e9;
          puVar7 = (ushort *)runtime_regexMatchEntry((int)param_1,(int)param_3);
          if (puVar7 == (ushort *)0x0) {
            if (puVar8 == (ushort *)0x0) break;
            puVar7 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 8),
                                  *(undefined1 **)(param_2 + 4),puVar8);
          }
LAB_6812f12f:
          puVar12 = puVar7;
        }
        break;
      case 7:
        if ((param_2[1] & 0x80) != 0) {
LAB_6812f1e9:
          puVar12 = (ushort *)runtime_regexScanForward();
          puVar7 = puVar12;
          goto joined_r0x6812f2fa;
        }
        puVar7 = (ushort *)runtime_regexMatchEntry((int)param_1,(int)param_3);
        if (puVar7 != (ushort *)0x0) goto LAB_6812f12f;
        break;
      case 8:
        puVar12 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 8),*(undefined1 **)(param_2 + 4),
                               param_4);
        if (puVar12 == (ushort *)0x0) {
          return (ushort *)0x0;
        }
        if ((param_2[1] & 0x80) == 0) {
          puVar12 = (ushort *)runtime_regexMatchEntry((int)param_1,(int)param_3);
          puVar7 = puVar12;
          if (puVar12 == (ushort *)0x0) {
            puVar12 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 8),
                                   *(undefined1 **)(param_2 + 4),param_4);
            puVar7 = puVar12;
          }
        }
        else {
          puVar12 = (ushort *)runtime_regexScanForward();
          puVar7 = puVar12;
        }
        goto joined_r0x6812f2fa;
      case 9:
        uVar9 = param_1[8];
        if (((param_2[1] & 0x80) != 0) &&
           (puVar7 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 4),param_3,param_4),
           puVar7 != (ushort *)0x0)) {
          return puVar7;
        }
        puVar7 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 8),*(undefined1 **)(param_2 + 4),
                              param_4);
        if (puVar7 == (ushort *)0x0) {
          uVar6 = uVar9;
          if (uVar9 < param_1[8]) {
            do {
              *(undefined4 *)(param_1[10] + uVar6 * 8) = 0;
              uVar6 = uVar6 + 1;
            } while (uVar6 < param_1[8]);
          }
          param_1[8] = uVar9;
        }
        else {
          puVar7 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 4),param_3,puVar7);
          if (puVar7 != (ushort *)0x0) {
            return puVar7;
          }
          uVar6 = uVar9;
          if (uVar9 < param_1[8]) {
            do {
              *(undefined4 *)(param_1[10] + uVar6 * 8) = 0;
              uVar6 = uVar6 + 1;
            } while (uVar6 < param_1[8]);
          }
          param_1[8] = uVar9;
        }
        break;
      case 10:
        puVar5 = *(undefined1 **)(param_2 + 8);
        uVar9 = *(uint *)(param_2 + 0xc);
        puVar1 = (undefined4 *)(param_1[10] + uVar9 * 8);
        puVar1[1] = param_4;
        *puVar1 = 0;
        param_2 = puVar5;
        if (param_1[8] <= uVar9) {
          param_1[8] = uVar9 + 1;
        }
        goto LAB_6812f13e;
      case 0xb:
        *(int *)(param_1[10] + *(int *)(param_2 + 0xc) * 8) =
             (int)param_4 - *(int *)(param_1[10] + 4 + *(int *)(param_2 + 0xc) * 8) >> 1;
        break;
      case 0xc:
        if (param_4 == puVar4) {
          return (ushort *)0x0;
        }
        uVar3 = *param_4;
        if (uVar3 == 10) {
          return (ushort *)0x0;
        }
        if (uVar3 == 0xd) {
          return (ushort *)0x0;
        }
        if (uVar3 == 0x2028) {
          return (ushort *)0x0;
        }
        if (uVar3 == 0x2029) {
          return (ushort *)0x0;
        }
        puVar12 = param_4 + 1;
        break;
      case 0xd:
        if (param_4 == puVar4) {
          return (ushort *)0x0;
        }
        if ((*(int *)(param_2 + 0x10) == 0) && (iVar10 = runtime_regexBuildCharClass(param_1), iVar10 == 0)) {
LAB_6812f806:
          param_1[0xb] = 0;
          return (ushort *)0x0;
        }
        uVar9 = (uint)(*param_4 >> 3);
        if (uVar9 < *(ushort *)(param_2 + 0xe)) {
          if ((*(byte *)(uVar9 + *(int *)(param_2 + 0x10)) & (byte)(1 << ((byte)*param_4 & 7))) == 0
             ) {
            return (ushort *)0x0;
          }
          puVar12 = param_4 + 1;
        }
        else {
          if (**(short **)(param_2 + 8) != 0x5e) {
            return (ushort *)0x0;
          }
          puVar12 = param_4 + 1;
        }
        break;
      case 0xe:
        if (param_4 == puVar4) {
          return (ushort *)0x0;
        }
        uVar9 = crypto_getStringCapacity((uint)*param_4);
        if (uVar9 != 9) {
          return (ushort *)0x0;
        }
        puVar12 = param_4 + 1;
        break;
      case 0xf:
        if (param_4 == puVar4) {
          return (ushort *)0x0;
        }
        uVar9 = crypto_getStringCapacity((uint)*param_4);
        if (uVar9 == 9) {
          return (ushort *)0x0;
        }
        puVar12 = param_4 + 1;
        break;
      case 0x10:
        if (param_4 == puVar4) {
          return (ushort *)0x0;
        }
        uVar9 = crypto_getStringCapacity((uint)*param_4);
        if (((0x23e >> ((byte)uVar9 & 0x1f) & 1U) == 0) && (*param_4 != 0x5f)) {
          return (ushort *)0x0;
        }
        puVar12 = param_4 + 1;
        break;
      case 0x11:
        if (param_4 == puVar4) {
          return (ushort *)0x0;
        }
        uVar9 = crypto_getStringCapacity((uint)*param_4);
        if ((0x23e >> ((byte)uVar9 & 0x1f) & 1U) != 0) {
          return (ushort *)0x0;
        }
        if (*param_4 == 0x5f) {
          return (ushort *)0x0;
        }
        puVar12 = param_4 + 1;
        break;
      case 0x12:
        if (param_4 == puVar4) {
          return (ushort *)0x0;
        }
        uVar9 = crypto_allocString((uint)*param_4);
        if ((uVar9 & 0x70000) != 0x40000) {
          return (ushort *)0x0;
        }
        puVar12 = param_4 + 1;
        break;
      case 0x13:
        if (param_4 == puVar4) {
          return (ushort *)0x0;
        }
        uVar9 = crypto_allocString((uint)*param_4);
        if ((uVar9 & 0x70000) == 0x40000) {
          return (ushort *)0x0;
        }
        puVar12 = param_4 + 1;
        break;
      case 0x14:
        if (param_1[8] <= *(uint *)(param_2 + 0xc)) {
          xtra_invokeMethod(*param_1,xtra_getErrorString,0,0x95);
          goto LAB_6812f806;
        }
        puVar2 = (uint *)(param_1[10] + *(uint *)(param_2 + 0xc) * 8);
        if (puVar4 < param_4 + *puVar2) {
          return (ushort *)0x0;
        }
        puVar7 = (ushort *)puVar2[1];
        param_2 = (undefined1 *)0x0;
        if (*puVar2 != 0) {
          do {
            iVar10 = runtime_regexCompareChar(*puVar7,(byte)param_1[7]);
            param_4 = param_4 + 1;
            puVar7 = puVar7 + 1;
            if (iVar10 == 0) {
              return (ushort *)0x0;
            }
            param_2 = param_2 + 1;
            puVar12 = param_4;
          } while (param_2 < (undefined1 *)*puVar2);
        }
        break;
      case 0x15:
        puVar7 = *(ushort **)(param_2 + 8);
        puVar11 = (undefined1 *)(*(int *)(param_2 + 0xc) - (int)puVar7 >> 1);
        if (puVar4 < param_4 + (int)puVar11) {
          return (ushort *)0x0;
        }
        param_2 = (undefined1 *)0x0;
        if (puVar11 != (undefined1 *)0x0) {
          do {
            iVar10 = runtime_regexCompareChar(*puVar7,(byte)param_1[7]);
            param_4 = param_4 + 1;
            puVar7 = puVar7 + 1;
            if (iVar10 == 0) {
              return (ushort *)0x0;
            }
            param_2 = param_2 + 1;
            puVar12 = param_4;
          } while (param_2 < puVar11);
        }
        break;
      case 0x16:
        if (param_4 == puVar4) {
          return (ushort *)0x0;
        }
        iVar10 = runtime_regexCompareChar(*param_4,(byte)param_1[7]);
        if (iVar10 == 0) {
          return (ushort *)0x0;
        }
        puVar12 = param_4 + 1;
        break;
      case 0x18:
        puVar7 = param_4;
        if (param_4 < puVar4) {
          while ((uVar3 = *puVar7, uVar3 != 10 && (uVar3 != 0xd))) {
            if ((uVar3 == 0x2028) || ((uVar3 == 0x2029 || (puVar7 = puVar7 + 1, puVar4 <= puVar7))))
            break;
          }
          if (puVar7 < param_4) break;
        }
        do {
          puVar8 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 4),(undefined1 *)0x0,puVar7);
          puVar12 = puVar7;
          if (puVar8 != (ushort *)0x0) break;
          puVar7 = puVar7 + -1;
          puVar12 = param_4;
        } while (param_4 <= puVar7);
        break;
      case 0x26:
        if (puVar4 < param_4) {
          return (ushort *)0x0;
        }
        while( true ) {
          puVar12 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 4),param_3,param_4);
          if (puVar12 != (ushort *)0x0) {
            return puVar12;
          }
          if ((((param_4 == puVar4) || (uVar3 = *param_4, uVar3 == 10)) || (uVar3 == 0xd)) ||
             ((uVar3 == 0x2028 || (uVar3 == 0x2029)))) break;
          param_4 = param_4 + 1;
          if (puVar4 < param_4) {
            return (ushort *)0x0;
          }
        }
        return (ushort *)0x0;
      case 0x27:
        param_2 = *(undefined1 **)(param_2 + 8);
        goto LAB_6812f13e;
      case 0x29:
        puVar7 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 8),*(undefined1 **)(param_2 + 4),
                              param_4);
joined_r0x6812f2fa:
        if (puVar7 == (ushort *)0x0) {
          return (ushort *)0x0;
        }
        break;
      case 0x2a:
        puVar7 = runtime_matchRegex(param_1,*(undefined1 **)(param_2 + 8),*(undefined1 **)(param_2 + 4),
                              param_4);
        if (puVar7 != (ushort *)0x0) {
          return (ushort *)0x0;
        }
      }
      param_4 = puVar12;
      param_2 = *(undefined1 **)(puVar5 + 4);
LAB_6812f13e:
      if (param_2 == param_3) {
        return param_4;
      }
    }
  }
  return param_4;
}



// ============================================================
// Function: runtime_regexSearchFrom (FUN_6812f910)
// Address: 6812f910
// Size: 72 bytes
// Params: undefined1 * param_1
// Return: ushort *
// Calling convention: __stdcall
// ============================================================

ushort * runtime_regexSearchFrom(undefined1 *param_1)

{
  ushort *in_EAX;
  ushort *puVar1;
  int iVar2;
  uint *unaff_ESI;
  
  if (in_EAX <= (ushort *)unaff_ESI[4]) {
    iVar2 = 0;
    do {
      unaff_ESI[6] = iVar2 >> 1;
      unaff_ESI[8] = 0;
      puVar1 = runtime_matchRegex(unaff_ESI,param_1,(undefined1 *)0x0,in_EAX);
      if (unaff_ESI[0xb] == 0) {
        return (ushort *)0x0;
      }
      if (puVar1 != (ushort *)0x0) {
        return puVar1;
      }
      in_EAX = in_EAX + 1;
      iVar2 = iVar2 + 2;
    } while (in_EAX <= (ushort *)unaff_ESI[4]);
  }
  return (ushort *)0x0;
}



// ============================================================
// Function: runtime_execRegex (FUN_6812f960)
// Address: 6812f960
// Size: 1441 bytes
// Params: void * param_1, int param_2, uint * param_3, uint * param_4, int param_5, undefined4 * param_6
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x6812fbbd) */
/* WARNING: Removing unreachable block (ram,0x6812fd02) */
/* WARNING: Removing unreachable block (ram,0x6812fbc7) */
/* WARNING: Removing unreachable block (ram,0x6812fbd5) */
/* WARNING: Removing unreachable block (ram,0x6812fbf8) */
/* WARNING: Removing unreachable block (ram,0x6812fc16) */
/* WARNING: Removing unreachable block (ram,0x6812fc23) */
/* WARNING: Removing unreachable block (ram,0x6812fc02) */
/* WARNING: Removing unreachable block (ram,0x6812fc3a) */
/* WARNING: Removing unreachable block (ram,0x6812fcb7) */
/* WARNING: Removing unreachable block (ram,0x6812fc3e) */
/* WARNING: Removing unreachable block (ram,0x6812fbe3) */
/* WARNING: Removing unreachable block (ram,0x6812fc5f) */
/* WARNING: Removing unreachable block (ram,0x6812fc65) */
/* WARNING: Removing unreachable block (ram,0x6812fcd5) */
/* WARNING: Removing unreachable block (ram,0x6812fc7a) */
/* WARNING: Removing unreachable block (ram,0x6812fce9) */
/* WARNING: Removing unreachable block (ram,0x6812fc9d) */
/* WARNING: Removing unreachable block (ram,0x6812fca3) */
/* WARNING: Removing unreachable block (ram,0x6812fcb5) */
/* WARNING: Removing unreachable block (ram,0x6812fd05) */

int runtime_execRegex(void *param_1,int param_2,uint *param_3,uint *param_4,int param_5,
                undefined4 *param_6)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  uint *puVar4;
  void *_Dst;
  ushort *puVar5;
  uint *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  size_t _Size;
  uint local_38;
  
  uVar9 = *param_3;
  uVar11 = uVar9;
  if ((uVar9 & 0x40000000) != 0) {
    uVar11 = (-(uint)((uVar9 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & uVar9;
  }
  uVar10 = *param_4;
  if (uVar11 < *param_4) {
    uVar10 = uVar11;
  }
  puVar4 = (uint *)param_3[1];
  if ((uVar9 & 0x40000000) != 0) {
    if ((*puVar4 & 0x40000000) == 0) {
      if ((int)uVar9 < 0) {
        puVar4 = (uint *)puVar4[1];
      }
      else {
        puVar4 = (uint *)(puVar4[1] + (uVar9 >> 0xf & 0x7fff) * 2);
      }
    }
    else {
      puVar4 = (uint *)crypto_getStringLen(param_3);
    }
  }
  iVar3 = uVar10 * 2;
  iVar7 = *(int *)((int)param_1 + 0x80);
  local_38 = 0;
  iVar1 = *(int *)(iVar7 + 0xc);
  _Dst = *(void **)(iVar7 + 0xc);
  _Size = (*(uint *)(param_2 + 4) & 0xffffff) * 0x10;
  uVar8 = *(uint *)((int)param_1 + 0x88) + _Size & ~*(uint *)((int)param_1 + 0x88);
  uVar9 = (int)_Dst + uVar8;
  if (*(uint *)(iVar7 + 8) < uVar9) {
    _Dst = (void *)js_getSlotIndex((int)param_1 + 0x70,uVar8);
  }
  else {
    *(uint *)(iVar7 + 0xc) = uVar9;
  }
  if (_Dst == (void *)0x0) {
    xtra_reportError((int)param_1);
    return 0;
  }
  memset(_Dst,0,_Size);
  puVar5 = runtime_regexSearchFrom(*(undefined1 **)(param_2 + 8));
  param_2 = 1;
  if (puVar5 == (ushort *)0x0) {
    *param_6 = 0;
    goto LAB_6812feac;
  }
  uVar9 = (int)puVar5 - (int)puVar4 >> 1;
  *param_4 = uVar9;
  uVar9 = uVar9 - uVar10;
  if (param_5 == 0) {
    param_4 = (uint *)js_arrayEnsureCapacity(param_1,0,0);
    if (param_4 == (uint *)0x0) {
      param_2 = 0;
      goto LAB_6812feac;
    }
    *param_6 = param_4;
    puVar6 = certs_allocFromPool((int)param_1,puVar5 + -uVar9,uVar9,0);
    if (puVar6 == (uint *)0x0) {
      *(undefined4 *)((int)param_1 + 0x90) = 0;
      param_2 = 0;
      goto LAB_6812feac;
    }
    param_2 = runtime_callProperty((uint)param_1,(int *)param_4,1,(uint)puVar6 | 4,0x6811de30,0x6811de30,1,
                           (undefined4 *)0x0);
    if (param_2 == 0) {
      *(undefined4 *)((int)param_1 + 0x90) = 0;
      *(undefined4 *)((int)param_1 + 0x94) = 0;
      goto LAB_6812feac;
    }
  }
  else {
    *param_6 = 0xe;
    param_4 = (uint *)0x0;
  }
  *(uint **)((int)param_1 + 0xb4) = param_3;
  *(undefined4 *)((int)param_1 + 0xbc) = 0;
  *(undefined4 *)((int)param_1 + 0x118) = DAT_681948f8;
  *(undefined **)((int)param_1 + 0x11c) = PTR_DAT_681948fc;
  if (param_5 == 0) {
    iVar7 = runtime_callProperty((uint)param_1,(int *)param_4,
                         *(uint *)(*(int *)((int)param_1 + 0x14) + 0x100),uVar10 * 2 | 1,0x6811de30,
                         0x6811de30,1,(undefined4 *)0x0);
    if (iVar7 == 0) {
      *(undefined4 *)((int)param_1 + 0x90) = 0;
      *(undefined4 *)((int)param_1 + 0x94) = 0;
      param_2 = 0;
      goto LAB_6812feac;
    }
    param_2 = runtime_callProperty((uint)param_1,(int *)param_4,
                           *(uint *)(*(int *)((int)param_1 + 0x14) + 0x104),(uint)param_3 | 4,
                           0x6811de30,0x6811de30,1,(undefined4 *)0x0);
    if (param_2 == 0) {
      *(undefined4 *)((int)param_1 + 0x90) = 0;
      *(undefined4 *)((int)param_1 + 0x94) = 0;
      goto LAB_6812feac;
    }
  }
  *(ushort **)((int)param_1 + 0x114) = puVar5 + -uVar9;
  *(uint *)((int)param_1 + 0x110) = uVar9;
  uVar9 = *param_3;
  if (*(int *)((int)param_1 + 0xc) == 0x78) {
    if ((uVar9 & 0x40000000) == 0) {
      uVar10 = 0;
      *(uint *)((int)param_1 + 0x124) = iVar3 + param_3[1];
    }
    else {
      puVar6 = (uint *)param_3[1];
      if ((*puVar6 & 0x40000000) == 0) {
        if ((int)uVar9 < 0) {
          uVar10 = 0;
          *(uint *)((int)param_1 + 0x124) = iVar3 + puVar6[1];
        }
        else {
          uVar10 = 0;
          *(uint *)((int)param_1 + 0x124) = iVar3 + puVar6[1] + (uVar9 >> 0xf & 0x7fff) * 2;
        }
      }
      else {
        iVar7 = crypto_getStringLen(param_3);
        *(int *)((int)param_1 + 0x124) = iVar3 + iVar7;
        uVar10 = local_38;
      }
    }
  }
  else {
    if ((uVar9 & 0x40000000) == 0) {
      uVar9 = param_3[1];
    }
    else {
      puVar6 = (uint *)param_3[1];
      if ((*puVar6 & 0x40000000) == 0) {
        if ((int)uVar9 < 0) {
          uVar9 = puVar6[1];
        }
        else {
          uVar9 = puVar6[1] + (uVar9 >> 0xf & 0x7fff) * 2;
        }
      }
      else {
        uVar9 = crypto_getStringLen(param_3);
      }
    }
    *(uint *)((int)param_1 + 0x124) = uVar9;
  }
  *(uint *)((int)param_1 + 0x120) = uVar10;
  *(ushort **)((int)param_1 + 300) = puVar5;
  *(int *)((int)param_1 + 0x128) = (int)((int)puVar4 + (uVar11 * 2 - (int)puVar5)) >> 1;
LAB_6812feac:
  piVar2 = *(int **)((int)param_1 + 0x80);
  if ((piVar2 != (int *)((int)param_1 + 0x70)) &&
     ((uint)(iVar1 - piVar2[1]) <= (uint)(piVar2[3] - piVar2[1]))) {
    piVar2[3] = iVar1 + *(uint *)((int)param_1 + 0x88) & ~*(uint *)((int)param_1 + 0x88);
    return param_2;
  }
  js_getPrototype((int *)((int)param_1 + 0x70),iVar1);
  return param_2;
}



// ============================================================
// Function: runtime_getRegexProperty (FUN_6812ff10)
// Address: 6812ff10
// Size: 225 bytes
// Params: undefined4 param_1, int * param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 runtime_getRegexProperty(undefined4 param_1,int *param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  if (((param_3 & 1) != 0) && (param_3 != 0x80000001)) {
    if ((int)param_3 >> 1 == -4) {
      uVar1 = xtra_getScriptProperty(param_1,param_2,0,param_4);
      return uVar1;
    }
    iVar2 = xtra_callMethodEx(param_1,(int)param_2,&PTR_s_RegExp_68193210,0);
    if (iVar2 != 0) {
      switch((int)param_3 >> 1) {
      case -5:
        *param_4 = (*(uint *)(iVar2 + 4) >> 0x1a & 1) * 8 | 6;
        break;
      case -3:
        *param_4 = (*(byte *)(iVar2 + 7) & 1) * 8 | 6;
        return 1;
      case -2:
        *param_4 = (*(uint *)(iVar2 + 4) >> 0x19 & 1) * 8 | 6;
        return 1;
      case -1:
        *param_4 = *(uint *)(iVar2 + 0xc) | 4;
        return 1;
      }
    }
    return 1;
  }
  return 1;
}



