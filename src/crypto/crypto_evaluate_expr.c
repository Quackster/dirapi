// Source: decompiled_functions.c
// Module: crypto
// Address range: 0x68148b50 - 0x68148b50
// Functions (1):
//   crypto_evaluateExpr

// ============================================================
// Function: crypto_evaluateExpr (FUN_68148b50)
// Address: 68148b50
// Size: 10126 bytes
// Params: int * param_1, undefined * * param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_evaluateExpr(int *param_1,undefined **param_2,int param_3)
{
  undefined **ppuVar1;
  char cVar2;
  ushort uVar3;
  byte bVar4;
  undefined **ppuVar5;
  undefined **ppuVar6;
  int iVar7;
  char *pcVar8;
  undefined *puVar9;
  int iVar10;
  int iVar11;
  uint *puVar12;
  byte *pbVar13;
  uint uVar14;
  char *pcVar15;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int *piVar16;
  undefined **ppuVar17;
  bool bVar18;
  undefined8 uVar19;
  uint local_5c;
  byte *local_58;
  byte *local_54;
  undefined **local_50;
  byte *local_4c;
  byte *local_48;
  undefined **local_44;
  byte *local_40;
  undefined **local_3c;
  uint *local_38;
  undefined **local_34;
  undefined **local_30;
  int *local_2c;
  uint local_28;
  undefined1 local_24 [28];
  
  ppuVar1 = (undefined **)((int)param_2 + param_3);
  local_58 = (byte *)0x0;
  local_28 = 0xfffffffe;
  local_54 = (byte *)0xffffffff;
  local_48 = (byte *)0x0;
  puVar12 = (uint *)*param_1;
  piVar16 = (int *)param_1[8];
  ppuVar17 = (undefined **)0x0;
joined_r0x68148b99:
  local_3c = param_2;
  local_38 = puVar12;
  local_2c = piVar16;
  if (ppuVar1 <= param_2) {
    return 0;
  }
  ppuVar5 = (undefined **)(uint)*(byte *)param_2;
  ppuVar6 = ppuVar5;
  if ((undefined **)0x99 < ppuVar5) {
    if (ppuVar5 == (undefined **)0xfe) {
      ppuVar6 = (undefined **)0x35;
    }
    else if (ppuVar5 == (undefined **)0xff) {
      ppuVar6 = (undefined **)0x37;
    }
  }
  iVar7 = (int)ppuVar6 * 0x10;
  local_30 = &PTR_DAT_68193cb0 + (int)ppuVar6 * 4;
  local_4c = (byte *)(int)(char)(&DAT_68193cb8)[iVar7];
  pcVar8 = *(char **)(&DAT_68193cb4 + iVar7);
  local_50 = ppuVar5;
  local_40 = local_4c;
  local_34 = ppuVar17;
  if (pcVar8 != (char *)0x0) {
    cVar2 = (&DAT_68193cb9)[iVar7];
    if (cVar2 == '\0') {
      if ((ppuVar5 == (undefined **)0x7b) || (pcVar15 = pcVar8, ppuVar5 == (undefined **)0x7c)) {
LAB_68148c00:
        local_28 = 0xfffffffe;
        goto switchD_68148d4f_caseD_5;
      }
      do {
        cVar2 = *pcVar15;
        pcVar15 = pcVar15 + 1;
      } while (cVar2 != '\0');
      local_28 = crypto_parseOperator(pcVar8);
    }
    else if (cVar2 == '\x01') {
      crypto_evalNode((int)ppuVar5);
      local_28 = crypto_parseString("%s%s");
    }
    else {
      if (cVar2 != '\x02') goto LAB_68148c00;
      iVar7 = crypto_evalNode((int)ppuVar5);
      local_40 = (byte *)(iVar7 + param_1[2]);
      crypto_evalNode((int)ppuVar5);
      local_48 = runtime_getObjectSlot(local_2c[0xe],(int)param_2);
      if (((local_48 == (byte *)0x0) || (0xbf < (*local_48 & 0xf8))) ||
         (pbVar13 = local_40, *local_48 >> 3 != 8)) {
        local_28 = crypto_parseString("%s %s %s");
      }
      else {
        do {
          bVar4 = *pbVar13;
          pbVar13 = pbVar13 + 1;
        } while (bVar4 != 0);
        local_28 = crypto_parseOperator(local_40);
      }
    }
    goto switchD_68148cfb_caseD_99;
  }
  if ((undefined **)0xff < ppuVar5) {
switchD_68148cfb_default:
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  }
  uVar14 = (uint)*(byte *)(ppuVar5 + 0x1a052d0a);
  switch((int)(size_t)ppuVar5) {
  case (undefined **)0x0:
    pbVar13 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
    piVar16 = local_2c;
    local_28 = 0xfffffffe;
    if (pbVar13 == (byte *)0x0) {
      bVar4 = 0;
    }
    else if ((*pbVar13 & 0xf8) < 0xc0) {
      bVar4 = *pbVar13 >> 3;
    }
    else {
      bVar4 = 0x18;
    }
    local_48 = pbVar13;
    switch(bVar4) {
    case 3:
      crypto_parseNumber(local_2c,"\tdo {\n");
      piVar16[0xc] = piVar16[0xc] + 4;
      break;
    case 4:
      local_40 = "";
LAB_681491fd:
      local_28 = 0xfffffffe;
      param_2 = (undefined **)((int)param_2 + 1);
      local_34 = (undefined **)js_getObjectFlags((int)pbVar13,0);
      local_3c = (undefined **)js_getObjectFlags((int)pbVar13,1);
      pbVar13 = (byte *)js_getObjectFlags((int)pbVar13,2);
      local_54 = pbVar13;
      uVar14 = crypto_getNodeType((int)((int)param_2 + (int)pbVar13));
      piVar16 = local_2c;
      if (pbVar13 + uVar14 != (byte *)0x0) goto LAB_6814b274;
      crypto_parseNumber(local_2c,"\tfor (%s;");
      local_30 = (undefined **)((int)param_2 + (int)local_34);
      if ((*(byte *)local_30 == 7) || (*(byte *)local_30 == 0x8c)) {
        iVar7 = crypto_evaluateExpr(param_1,param_2,(int)local_34);
        if (iVar7 == 0) goto LAB_6814b274;
        crypto_evalNode((int)local_50);
        crypto_parseNumber(piVar16," %s");
      }
      crypto_appendLiteral(piVar16,";");
      if ((*(byte *)((int)local_3c + (int)param_2) != 6) &&
         (*(byte *)((int)local_3c + (int)param_2) != 0x8b)) {
        iVar7 = crypto_evaluateExpr(param_1,(undefined **)((int)local_3c + (int)param_2),
                             (int)(local_54 + (-1 - (int)local_3c)));
        if (iVar7 == 0) goto LAB_6814b274;
        crypto_evalNode((int)local_50);
        crypto_parseNumber(piVar16," %s");
      }
      crypto_appendLiteral(piVar16,") {\n");
      piVar16[0xc] = piVar16[0xc] + 4;
      if (local_34 == (undefined **)0x0) {
        iVar7 = 0;
      }
      else {
        iVar7 = (int)(char)(&DAT_68193cb8)[(uint)*(byte *)local_30 * 0x10];
      }
      iVar7 = crypto_evaluateExpr(param_1,(undefined **)((int)local_30 + iVar7),
                           (int)((int)local_3c + (-iVar7 - (int)local_34)));
      if (iVar7 == 0) goto LAB_6814b274;
      piVar16[0xc] = piVar16[0xc] + -4;
      crypto_parseNumber(piVar16,"\t}\n");
      local_4c = local_54 +
                 (char)(&DAT_68193cb8)[(uint)*(byte *)((int)param_2 + (int)local_54) * 0x10];
      break;
    case 0xd:
      uVar14 = js_getObjectFlags((int)pbVar13,0);
      piVar16 = local_2c;
      js_allocAtom(local_38,(int *)(local_2c[0xe] + 0x10),uVar14);
      piVar16[0xc] = piVar16[0xc] + -4;
      iVar7 = crypto_parseAtom((int)param_1,0);
      if (iVar7 == 0) goto LAB_6814b274;
      param_1[4] = iVar7 - param_1[2];
      crypto_parseNumber(piVar16,"\t%s:\n");
      piVar16[0xc] = piVar16[0xc] + 4;
      break;
    case 0xe:
      uVar14 = js_getObjectFlags((int)pbVar13,0);
      piVar16 = local_2c;
      js_allocAtom(local_38,(int *)(local_2c[0xe] + 0x10),uVar14);
      iVar7 = crypto_parseAtom((int)param_1,0);
      if (iVar7 == 0) goto LAB_6814b274;
      param_1[4] = iVar7 - param_1[2];
      crypto_parseNumber(piVar16,"\t%s: {\n");
      piVar16 = piVar16 + 0xc;
      *piVar16 = *piVar16 + 4;
      break;
    case 0xf:
      local_2c[0xc] = local_2c[0xc] + -4;
      crypto_parseNumber(local_2c,"\t}\n");
      break;
    case 0x13:
      uVar14 = js_getObjectFlags((int)pbVar13,0);
      goto LAB_6814ad2d;
    case 0x14:
      local_2c[0xc] = local_2c[0xc] + -4;
      local_48 = runtime_getObjectSlot(local_2c[0xe],(int)param_2);
      pbVar13 = (byte *)((int)param_2 + (int)local_40);
      crypto_parseNumber(piVar16,"\t} catch (");
      if ((((*pbVar13 != 0x3b) || (pbVar13 = pbVar13 + DAT_68194068, *pbVar13 != 0x39)) ||
          (pbVar13 = pbVar13 + DAT_68194048, *pbVar13 != 0x59)) ||
         ((pbVar13[DAT_68194248] != 0x74 ||
          (pbVar13 = pbVar13 + DAT_68194248 + DAT_681943f8, *pbVar13 != 0x82)))) goto LAB_6814b274;
      js_allocAtom(local_38,(int *)(piVar16[0xe] + 0x10),(uint)CONCAT11(pbVar13[1],pbVar13[2]));
      iVar7 = crypto_parseAtom((int)param_1,0);
      if (iVar7 == 0) goto LAB_6814b274;
      param_1[4] = iVar7 - param_1[2];
      crypto_parseNumber(piVar16,"%s");
      if (pbVar13[DAT_681944d8] != 3) goto LAB_6814b274;
      param_2 = (undefined **)(pbVar13 + DAT_681944d8 + DAT_68193ce8);
      local_4c = (byte *)js_getObjectFlags((int)local_48,0);
      if (local_4c != (byte *)0x0) {
        crypto_parseNumber(piVar16," if ");
        iVar7 = crypto_evaluateExpr(param_1,param_2,(int)local_4c);
        if (iVar7 == 0) goto LAB_6814b274;
        crypto_evalNode(0);
        crypto_parseNumber(piVar16,"%s");
        bVar4 = *(byte *)((int)param_2 + (int)local_4c);
        if ((bVar4 != 7) && (bVar4 != 0x8c)) goto LAB_6814b274;
        param_2 = (undefined **)
                  ((byte *)((int)param_2 + (int)local_4c) +
                  (char)(&DAT_68193cb8)[(uint)bVar4 * 0x10]);
      }
      crypto_parseNumber(piVar16,") {\n");
      piVar16[0xc] = piVar16[0xc] + 4;
      local_4c = (byte *)0x0;
    }
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x1:
  case (undefined **)0x39:
  case (undefined **)0x6c:
switchD_68148cfb_caseD_1:
    local_28 = crypto_parseString("");
    break;
  case (undefined **)0x2:
  case (undefined **)0x51:
    pbVar13 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
    local_48 = pbVar13;
    if ((pbVar13 != (byte *)0x0) && ((*pbVar13 & 0xf8) < 0xc0)) {
      bVar4 = *pbVar13 >> 3;
      if (bVar4 == 4) {
        iVar7 = crypto_evalNode((int)local_50);
        local_40 = (byte *)(iVar7 + param_1[2]);
        goto LAB_681491fd;
      }
      if (bVar4 == 7) {
        iVar7 = crypto_evalNode((int)local_50);
        local_30 = (undefined **)xtra_findMethodByName((int)local_38,(char *)(iVar7 + param_1[2]));
        if (local_30 == (undefined **)0x0) goto LAB_6814b274;
        local_34 = (undefined **)((int)param_2 + (int)local_40);
        uVar14 = js_getObjectFlags((int)pbVar13,0);
        local_4c = (byte *)0x0;
        iVar7 = crypto_evaluateExpr(param_1,local_34,(int)((int)param_2 + uVar14) - (int)local_34);
        if (iVar7 == 0) {
          xtra_checkAndFlush(local_38,(int)local_30);
          goto LAB_6814b274;
        }
        crypto_evalNode((int)local_50);
        ppuVar17 = local_30;
        local_28 = crypto_parseString("%s, %s");
        xtra_checkAndFlush(local_38,(int)ppuVar17);
        param_2 = (undefined **)((int)param_2 + uVar14);
        break;
      }
      if (bVar4 == 0xb) goto switchD_68148cfb_caseD_72;
    }
    iVar7 = crypto_evalNode((int)local_50);
    if (*(char *)(iVar7 + param_1[2]) != '\0') {
      pcVar8 = "\t%s;\n";
      goto LAB_68149148;
    }
    goto LAB_68149154;
  case (undefined **)0x3:
    local_48 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
    if (((local_48 == (byte *)0x0) || (0xbf < (*local_48 & 0xf8))) || (*local_48 >> 3 != 0xb)) {
      crypto_evalNode(3);
      crypto_parseNumber(piVar16,"\twith (%s) {\n");
      piVar16[0xc] = piVar16[0xc] + 4;
      local_28 = crypto_parseString("with-cookie");
      break;
    }
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x4:
    local_48 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
    local_28 = 0xfffffffe;
    if (((local_48 == (byte *)0x0) || (0xbf < (*local_48 & 0xf8))) || (*local_48 >> 3 != 0xb)) {
      iVar7 = crypto_evalNode(4);
      pbVar13 = (byte *)(iVar7 + param_1[2]);
      pcVar8 = "with-cookie";
      do {
        bVar4 = *pbVar13;
        bVar18 = bVar4 < (byte)*pcVar8;
        if (bVar4 != *pcVar8) {
LAB_68149447:
          iVar7 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
          goto LAB_6814944c;
        }
        if (bVar4 == 0) break;
        bVar4 = pbVar13[1];
        bVar18 = bVar4 < (byte)pcVar8[1];
        if (bVar4 != pcVar8[1]) goto LAB_68149447;
        pbVar13 = pbVar13 + 2;
        pcVar8 = pcVar8 + 2;
      } while (bVar4 != 0);
      iVar7 = 0;
LAB_6814944c:
      if (iVar7 != 0) goto LAB_6814b274;
      piVar16[0xc] = piVar16[0xc] + -4;
      crypto_parseNumber(piVar16,"\t}\n");
    }
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x5:
  case (undefined **)0x98:
    iVar7 = crypto_evalNode((int)ppuVar5);
    if (*(char *)(iVar7 + param_1[2]) == '\0') {
      pcVar8 = "\t%s;\n";
      goto LAB_681494a8;
    }
    crypto_parseNumber(local_2c,"\t%s %s;\n");
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x6:
  case (undefined **)0x8b:
    local_48 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
    if (local_48 == (byte *)0x0) {
      bVar4 = 0;
    }
    else if ((*local_48 & 0xf8) < 0xc0) {
      bVar4 = *local_48 >> 3;
    }
    else {
      bVar4 = 0x18;
    }
    switch(bVar4) {
    case 5:
      pcVar8 = "\tcontinue;\n";
      goto LAB_6814961a;
    default:
      pcVar8 = "\tbreak;\n";
LAB_6814961a:
      crypto_parseNumber(piVar16,pcVar8);
switchD_68149563_caseD_b:
      local_28 = 0xfffffffe;
      break;
    case 0xb:
      goto switchD_68149563_caseD_b;
    case 0x10:
      uVar14 = js_getObjectFlags((int)local_48,0);
      js_allocAtom(local_38,(int *)(piVar16[0xe] + 0x10),uVar14);
      iVar7 = crypto_parseAtom((int)param_1,0);
      if (iVar7 == 0) goto LAB_6814b274;
      param_1[4] = iVar7 - param_1[2];
      crypto_parseNumber(piVar16,"\tbreak %s;\n");
      local_28 = 0xfffffffe;
      break;
    case 0x11:
      uVar14 = js_getObjectFlags((int)local_48,0);
      js_allocAtom(local_38,(int *)(piVar16[0xe] + 0x10),uVar14);
      iVar7 = crypto_parseAtom((int)param_1,0);
      if (iVar7 == 0) goto LAB_6814b274;
      param_1[4] = iVar7 - param_1[2];
      crypto_parseNumber(piVar16,"\tcontinue %s;\n");
      local_28 = 0xfffffffe;
    }
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x7:
  case (undefined **)0x8c:
    local_4c = (byte *)crypto_getNodeType((int)param_2);
    piVar16 = local_2c;
    local_48 = runtime_getObjectSlot(local_2c[0xe],(int)param_2);
    if (local_48 == (byte *)0x0) {
      bVar4 = 0;
    }
    else if ((*local_48 & 0xf8) < 0xc0) {
      bVar4 = *local_48 >> 3;
    }
    else {
      bVar4 = 0x18;
    }
    switch(bVar4) {
    case 1:
    case 2:
      crypto_evalNode((int)local_50);
      crypto_parseNumber(piVar16,"\tif (%s) {\n");
      piVar16[0xc] = piVar16[0xc] + 4;
      if ((0xbf < (*local_48 & 0xf8)) || (*local_48 >> 3 != 1)) {
        local_4c = (byte *)js_getObjectFlags((int)local_48,0);
        iVar7 = crypto_evaluateExpr(param_1,(undefined **)(local_40 + (int)param_2),
                             (int)local_4c - (int)local_40);
        if (iVar7 == 0) goto LAB_6814b274;
        param_2 = (undefined **)((int)param_2 + (int)local_4c);
        piVar16[0xc] = piVar16[0xc] + -4;
        bVar4 = *(byte *)param_2;
        if ((bVar4 != 6) && (bVar4 != 0x8b)) goto LAB_6814b274;
        local_40 = (byte *)(int)(char)(&DAT_68193cb8)[(uint)bVar4 * 0x10];
        local_4c = (byte *)crypto_getNodeType((int)param_2);
        crypto_parseNumber(piVar16,"\t} else {\n");
        piVar16[0xc] = piVar16[0xc] + 4;
        pbVar13 = local_4c;
        goto LAB_68149739;
      }
      iVar7 = (int)local_4c - (int)local_40;
      ppuVar17 = (undefined **)(local_40 + (int)param_2);
      goto LAB_68149743;
    case 3:
      crypto_evalNode((int)local_50);
      crypto_parseNumber(piVar16,"\twhile (%s) {\n");
      piVar16[0xc] = piVar16[0xc] + 4;
      local_54 = (byte *)js_getObjectFlags((int)local_48,0);
      pbVar13 = local_54;
LAB_68149739:
      iVar7 = (int)pbVar13 - (int)local_40;
      ppuVar17 = (undefined **)((int)param_2 + (int)local_40);
LAB_68149743:
      iVar7 = crypto_evaluateExpr(param_1,ppuVar17,iVar7);
      if (iVar7 == 0) goto LAB_6814b274;
      piVar16[0xc] = piVar16[0xc] + -4;
      pcVar8 = "\t}\n";
      goto LAB_6814961a;
    case 9:
      iVar7 = crypto_evalNode((int)local_50);
      local_44 = (undefined **)xtra_findMethodByName((int)local_38,(char *)(iVar7 + param_1[2]));
      if (local_44 == (undefined **)0x0) goto LAB_6814b274;
      local_4c = (byte *)js_getObjectFlags((int)local_48,0);
      iVar7 = crypto_evaluateExpr(param_1,(undefined **)(local_40 + (int)param_2),
                           (int)local_4c - (int)local_40);
      if (iVar7 == 0) goto LAB_6814b274;
      iVar7 = crypto_evalNode((int)local_50);
      iVar7 = xtra_findMethodByName((int)local_38,(char *)(iVar7 + param_1[2]));
      if (iVar7 == 0) {
        xtra_checkAndFlush(local_38,(int)local_44);
        return 0;
      }
      param_2 = (undefined **)((int)param_2 + (int)local_4c);
      bVar4 = *(byte *)param_2;
      if ((bVar4 != 6) && (bVar4 != 0x8b)) goto LAB_6814b274;
      local_40 = (byte *)(int)(char)(&DAT_68193cb8)[(uint)bVar4 * 0x10];
      local_4c = (byte *)crypto_getNodeType((int)param_2);
      iVar10 = crypto_evaluateExpr(param_1,(undefined **)((int)param_2 + (int)local_40),
                            (int)local_4c - (int)local_40);
      if (iVar10 == 0) goto LAB_6814b274;
      crypto_evalNode((int)local_50);
      local_28 = crypto_parseString("%s ? %s : %s");
      xtra_checkAndFlush(local_38,(int)local_44);
      xtra_checkAndFlush(local_38,iVar7);
    }
    break;
  case (undefined **)0x8:
  case (undefined **)0x8d:
    piVar16[0xc] = piVar16[0xc] + -4;
    crypto_evalNode((int)ppuVar5);
    pcVar8 = "\t} while (%s);\n";
LAB_681494a8:
    crypto_parseNumber(local_2c,pcVar8);
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  default:
    goto switchD_68148cfb_default;
  case (undefined **)0xa:
    iVar7 = crypto_parseAssignment(uVar14,(uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),
                                               *(undefined1 *)((int)param_2 + 2)));
    if ((iVar7 == 0) ||
       (local_30 = (undefined **)crypto_parseAtom((int)param_1,0), local_30 == (undefined **)0x0))
    goto LAB_6814b274;
    param_1[4] = (int)local_30 - param_1[2];
    goto LAB_68149ac2;
  case (undefined **)0xb:
    iVar7 = crypto_parseAssignment((uint)*(byte *)((int)param_2 + 2),
                         (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),
                                        *(byte *)((int)param_2 + 2)));
    if (iVar7 == 0) goto LAB_6814b274;
    goto LAB_68149a9e;
  case (undefined **)0xc:
    goto switchD_68148cfb_caseD_c;
  case (undefined **)0xd:
    pcVar15 = (char *)(*(int *)(param_1[5] + -8 + param_1[7] * 4) + param_1[2]);
    pcVar8 = pcVar15;
    do {
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    iVar7 = crypto_parseOperator(pcVar15);
    if ((iVar7 < 0) || (iVar7 = crypto_emitOperand(iVar7), iVar7 == 0)) goto LAB_6814b274;
    goto switchD_68148cfb_caseD_c;
  case (undefined **)0xe:
  case (undefined **)0x6d:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    goto LAB_68149d8a;
  case (undefined **)0x23:
  case (undefined **)0x3a:
  case (undefined **)0x79:
  case (undefined **)0x84:
    local_30 = (undefined **)
               (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2));
    local_44 = (undefined **)xtra_getPropertyById((int)puVar12,(int)local_30 * 4 + 4);
    if (local_44 == (undefined **)0x0) goto LAB_6814b274;
    local_34 = (undefined **)0x1;
    for (local_3c = local_30; 0 < (int)local_3c; local_3c = (undefined **)((int)local_3c + -1)) {
      iVar7 = crypto_evalNode(0);
      puVar9 = (undefined *)xtra_findMethodByName((int)local_38,(char *)(iVar7 + param_1[2]));
      local_44[(int)local_3c] = puVar9;
      if (puVar9 == (undefined *)0x0) {
        local_34 = (undefined **)0x0;
        break;
      }
    }
    if ((uint)param_1[7] < 2) goto LAB_6814b274;
    crypto_evalNode(0);
    iVar7 = crypto_evalNode(0);
    puVar9 = (undefined *)xtra_findMethodByName((int)local_38,(char *)(iVar7 + param_1[2]));
    *local_44 = puVar9;
    if (local_44[(int)local_3c] == (undefined *)0x0) {
      local_34 = (undefined **)0x0;
    }
    if (ppuVar5 == (undefined **)0x23) {
      local_28 = crypto_parseString("%s %s%s");
    }
    else {
      local_28 = crypto_parseString("%s%s");
    }
    if ((int)local_28 < 0) {
      local_34 = (undefined **)0x0;
    }
    local_3c = (undefined **)0x1;
    if (0 < (int)local_30) {
      do {
        if ((local_44[(int)local_3c] == (undefined *)0x0) ||
           (iVar7 = crypto_parseString("%s%s"), iVar7 < 0)) {
          local_34 = (undefined **)0x0;
          break;
        }
        local_3c = (undefined **)((int)local_3c + 1);
      } while ((int)local_3c <= (int)local_30);
    }
    iVar7 = crypto_parseString(")");
    if (iVar7 < 0) {
      local_34 = (undefined **)0x0;
    }
    local_3c = (undefined **)0x0;
    if (-1 < (int)local_30) {
      do {
        if (local_44[(int)local_3c] != (undefined *)0x0) {
          xtra_checkAndFlush(local_38,(int)local_44[(int)local_3c]);
        }
        local_3c = (undefined **)((int)local_3c + 1);
      } while ((int)local_3c <= (int)local_30);
    }
    xtra_checkAndFlush(local_38,(int)local_44);
    if (local_34 == (undefined **)0x0) goto LAB_6814b274;
    if (ppuVar5 == (undefined **)0x84) {
      iVar7 = crypto_emitOperand(local_28);
      if (iVar7 == 0) goto LAB_6814b274;
      goto switchD_68148cfb_caseD_1;
    }
    break;
  case (undefined **)0x24:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    iVar7 = crypto_parseAtom((int)param_1,0);
    if (iVar7 == 0) goto LAB_6814b274;
    param_1[4] = iVar7 - param_1[2];
    local_28 = crypto_parseString("%s %s");
    break;
  case (undefined **)0x25:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    iVar7 = crypto_parseAtom((int)param_1,0);
    if (iVar7 == 0) goto LAB_6814b274;
    crypto_evalNode(0x25);
    local_28 = crypto_parseString("%s %s.%s");
    break;
  case (undefined **)0x26:
    crypto_evalNode(0x26);
    crypto_evalNode(0x26);
    local_28 = crypto_parseString("%s %s[%s]");
    break;
  case (undefined **)0x27:
  case (undefined **)0x28:
    crypto_evalNode((int)ppuVar5);
    local_28 = crypto_parseString("%s %s");
    break;
  case (undefined **)0x29:
  case (undefined **)0x2c:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    goto LAB_6814a117;
  case (undefined **)0x2a:
  case (undefined **)0x2d:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    local_40 = (byte *)crypto_parseAtom((int)param_1,0);
    if (local_40 == (byte *)0x0) goto LAB_6814b274;
    crypto_evalNode((int)ppuVar5);
    local_28 = crypto_parseString("%s%s.%s");
    break;
  case (undefined **)0x2b:
  case (undefined **)0x2e:
    iVar7 = crypto_evalNode((int)ppuVar5);
    local_44 = (undefined **)(iVar7 + param_1[2]);
    crypto_evalNode((int)ppuVar5);
    local_28 = crypto_parseString("%s%s[%s]");
    break;
  case (undefined **)0x2f:
  case (undefined **)0x32:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    goto LAB_6814a26f;
  case (undefined **)0x30:
  case (undefined **)0x33:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    local_40 = (byte *)crypto_parseAtom((int)param_1,0);
    if (local_40 == (byte *)0x0) goto LAB_6814b274;
    crypto_evalNode((int)ppuVar5);
    local_28 = crypto_parseString("%s.%s%s");
    break;
  case (undefined **)0x31:
  case (undefined **)0x34:
    iVar7 = crypto_evalNode((int)ppuVar5);
    local_44 = (undefined **)(iVar7 + param_1[2]);
    crypto_evalNode((int)ppuVar5);
    local_28 = crypto_parseString("%s[%s]%s");
    break;
  case (undefined **)0x35:
    goto switchD_68148cfb_caseD_35;
  case (undefined **)0x36:
    local_48 = runtime_getObjectSlot(piVar16[0xe],(int)param_2 + -1);
    iVar7 = js_allocAtom(local_38,(int *)(piVar16[0xe] + 0x10),
                         (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),
                                        *(undefined1 *)((int)param_2 + 2)));
    puVar12 = (uint *)(*(uint *)(iVar7 + 8) & 0xfffffff8);
    iVar7 = crypto_isValidIdentifier(extraout_ECX_00,puVar12);
    if (iVar7 == 0) {
      local_44 = (undefined **)crypto_parseAtom((int)param_1,0x27);
      crypto_evalNode(0x36);
      crypto_evalNode(0x36);
      if (((local_48 != (byte *)0x0) && ((*local_48 & 0xf8) < 0xc0)) && (*local_48 >> 3 == 8)) {
        pcVar8 = "%s[%s] %s= %s";
        goto LAB_6814a4b8;
      }
LAB_6814a6da:
      local_28 = crypto_parseString("%s[%s] = %s");
    }
    else {
      iVar7 = crypto_evalNode(0x36);
      local_40 = (byte *)(iVar7 + param_1[2]);
      iVar7 = crypto_evalNode(0x36);
      local_30 = (undefined **)(iVar7 + param_1[2]);
      xtra_getStringValue(puVar12);
      if (((local_48 != (byte *)0x0) && ((*local_48 & 0xf8) < 0xc0)) && (*local_48 >> 3 == 8)) {
        pcVar8 = "%s.%s %s= %s";
        goto LAB_6814a4b8;
      }
      local_28 = crypto_parseString("%s.%s = %s");
    }
    break;
  case (undefined **)0x37:
    goto switchD_68148cfb_caseD_37;
  case (undefined **)0x38:
    iVar7 = crypto_evalNode(0);
    local_40 = (byte *)(iVar7 + param_1[2]);
    iVar10 = crypto_evalNode(0);
    iVar7 = param_1[2];
    local_50 = (undefined **)0x38;
    iVar11 = crypto_evalNode(0x38);
    local_30 = (undefined **)(iVar11 + param_1[2]);
    if (*(char *)(iVar10 + iVar7) != '\0') {
      local_48 = runtime_getObjectSlot(local_2c[0xe],(int)param_2 + -1);
      if (((local_48 == (byte *)0x0) || (0xbf < (*local_48 & 0xf8))) || (*local_48 >> 3 != 8))
      goto LAB_6814a6da;
      pcVar8 = "%s[%s] %s= %s";
      goto LAB_6814a4b8;
    }
    goto LAB_6814a5fb;
  case (undefined **)0x3b:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    goto LAB_6814a797;
  case (undefined **)0x3c:
    iVar7 = js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                         (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),
                                        *(undefined1 *)((int)param_2 + 2)));
    local_5c = *(uint *)(iVar7 + 8);
    if (((local_5c & 1) == 0) || (local_5c == 0x80000001)) {
      pcVar8 = javascript_numberToExponential((int)local_24,0x1a,(char *)0x0,(char *)0x0,
                            (int)*(undefined8 *)(local_5c & 0xfffffff8),
                            (uint)((ulonglong)*(undefined8 *)(local_5c & 0xfffffff8) >> 0x20));
      if (pcVar8 == (char *)0x0) {
        xtra_reportError((int)puVar12);
        return 0;
      }
      local_28 = crypto_parseString(pcVar8);
    }
    else {
      local_28 = crypto_parseString("%ld");
    }
    break;
  case (undefined **)0x3d:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    iVar7 = crypto_parseAtom((int)param_1,0x22);
    if (iVar7 == 0) goto LAB_6814b274;
    local_28 = iVar7 - param_1[2];
    break;
  case (undefined **)0x44:
  case (undefined **)0x8e:
    local_44 = (undefined **)&DAT_6817fbcc;
    goto LAB_681498b4;
  case (undefined **)0x45:
  case (undefined **)0x8f:
    local_44 = (undefined **)&DAT_6817b8cc;
LAB_681498b4:
    iVar7 = crypto_evalNode((int)ppuVar5);
    local_30 = (undefined **)xtra_findMethodByName((int)local_38,(char *)(iVar7 + param_1[2]));
    if (local_30 == (undefined **)0x0) goto LAB_6814b274;
    uVar14 = crypto_getNodeType((int)param_2);
    ppuVar17 = (undefined **)((int)param_2 + (int)local_40);
    local_4c = (byte *)((int)param_2 + (uVar14 - (int)ppuVar17));
    iVar7 = crypto_evaluateExpr(param_1,ppuVar17,(int)local_4c);
    if (iVar7 == 0) goto LAB_6814b274;
    iVar7 = crypto_evalNode((int)ppuVar5);
    pcVar8 = (char *)(iVar7 + param_1[2]);
    param_2 = ppuVar17;
    if (local_2c[0xd] == 0) {
LAB_681499e1:
      local_28 = crypto_parseString("%s %s %s");
    }
    else {
      ppuVar17 = local_30;
      do {
        bVar4 = *(byte *)ppuVar17;
        ppuVar17 = (undefined **)((int)ppuVar17 + 1);
      } while (bVar4 != 0);
      local_34 = (undefined **)(pcVar8 + 1);
      pcVar15 = pcVar8;
      do {
        cVar2 = *pcVar15;
        pcVar15 = pcVar15 + 1;
      } while (cVar2 != '\0');
      if ((byte *)((int)ppuVar17 +
                  (int)(pcVar15 + (((local_2c[0xc] - (int)local_34) + 8) - (int)((int)local_30 + 1))
                       )) < (byte *)0x4c) goto LAB_681499e1;
      iVar7 = xtra_findMethodByName((int)local_38,pcVar8);
      if (iVar7 == 0) {
        local_54 = (byte *)0xffffffff;
        local_28 = 0xffffffff;
        xtra_checkAndFlush(local_38,(int)local_30);
        break;
      }
      local_28 = crypto_parseString("%s %s\n");
      local_54 = (byte *)crypto_parseString("%*s%s");
      xtra_checkAndFlush(local_38,iVar7);
      if ((int)local_54 < 0) {
        local_28 = 0xffffffff;
        xtra_checkAndFlush(local_38,(int)local_30);
        break;
      }
    }
    xtra_checkAndFlush(local_38,(int)local_30);
    break;
  case (undefined **)0x46:
  case (undefined **)0x93:
    local_48 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
    local_4c = (byte *)js_getObjectFlags((int)local_48,0);
    local_28 = crypto_getNodeType((int)param_2);
    local_44 = (undefined **)crypto_getNodeType((int)param_2 + 2);
    ppuVar17 = param_2 + 1;
    uVar14 = crypto_getNodeType((int)ppuVar17);
    local_30 = (undefined **)(uVar14 + (1 - (int)local_44));
    if (local_30 == (undefined **)0x0) {
      local_3c = (undefined **)0x0;
      local_34 = (undefined **)0x0;
    }
    else {
      local_3c = (undefined **)xtra_getPropertyById((int)local_38,(int)local_30 * 8);
      if (local_3c == (undefined **)0x0) goto LAB_6814b274;
      local_34 = (undefined **)0x0;
      if (0 < (int)local_30) {
        ppuVar6 = (undefined **)((int)local_44 * 2);
        local_44 = local_30;
        local_30 = ppuVar6;
        do {
          ppuVar17 = (undefined **)((int)ppuVar17 + 2);
          local_40 = (byte *)crypto_getNodeType((int)ppuVar17);
          if (local_40 != (byte *)0x0) {
            local_3c[(int)local_34 * 2] = (undefined *)((uint)local_30 | 1);
            local_3c[(int)local_34 * 2 + 1] = local_40;
            local_34 = (undefined **)((int)local_34 + 1);
          }
          local_30 = (undefined **)((int)local_30 + 2);
          local_44 = (undefined **)((int)local_44 + -1);
        } while (local_44 != (undefined **)0x0);
      }
      javascript_heapSort((int)local_3c,(uint)local_34,8,crypto_compareByOffset,0);
    }
    iVar7 = crypto_decompileSwitch((int)local_3c,(uint)local_34,param_2,(int)local_4c,local_28,0);
    ppuVar17 = local_3c;
    goto LAB_6814aa61;
  case (undefined **)0x47:
  case (undefined **)0x94:
    local_48 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
    local_4c = (byte *)js_getObjectFlags((int)local_48,0);
    local_28 = crypto_getNodeType((int)param_2);
    local_30 = (undefined **)
               (uint)CONCAT11(*(undefined1 *)((int)param_2 + 3),*(undefined1 *)(param_2 + 1));
    local_44 = (undefined **)xtra_getPropertyById((int)local_38,(int)local_30 * 8);
    if (local_44 == (undefined **)0x0) goto LAB_6814b274;
    local_3c = (undefined **)0x0;
    ppuVar17 = param_2;
    if (0 < (int)local_30) {
      do {
        local_34 = (undefined **)
                   js_allocAtom(local_38,(int *)(local_2c[0xe] + 0x10),
                                (uint)CONCAT11(*(undefined1 *)((int)ppuVar17 + 5),
                                               *(undefined1 *)((int)ppuVar17 + 6)));
        local_40 = (byte *)crypto_getNodeType((int)ppuVar17 + 6);
        local_44[(int)local_3c * 2] = local_34[2];
        local_44[(int)local_3c * 2 + 1] = local_40;
        local_3c = (undefined **)((int)local_3c + 1);
        ppuVar17 = ppuVar17 + 1;
      } while ((int)local_3c < (int)local_30);
    }
    iVar7 = crypto_decompileSwitch((int)local_44,(uint)local_30,param_2,(int)local_4c,local_28,0);
    xtra_checkAndFlush(local_38,(int)local_44);
    if (iVar7 == 0) goto LAB_6814b274;
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x48:
  case (undefined **)0x49:
    iVar7 = crypto_evalNode((int)ppuVar5);
    local_40 = (byte *)(iVar7 + param_1[2]);
    crypto_evalNode((int)ppuVar5);
    pcVar8 = "%s %c%s %s";
LAB_6814a4b8:
    local_28 = crypto_parseString(pcVar8);
    break;
  case (undefined **)0x4a:
    uVar14 = (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2));
LAB_6814ad2d:
    piVar16 = local_2c;
    iVar7 = js_allocAtom(local_38,(int *)(local_2c[0xe] + 0x10),uVar14);
    local_3c = (undefined **)xtra_getObjectTag(local_38,*(uint *)(iVar7 + 8) & 0xfffffff8);
    uVar19 = *(undefined8 *)(piVar16 + 0xc);
    pcVar8 = xtra_setScriptPropertyEx((int)local_3c);
    local_34 = (undefined **)
               crypto_createBinaryOp((int)local_38,pcVar8,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
    if (local_34 == (undefined **)0x0) goto LAB_6814b274;
    local_34[0xf] = (undefined *)piVar16[0xf];
    iVar7 = crypto_decompileArrayAccess((int *)local_34,(int)local_3c);
    if ((iVar7 != 0) && (puVar12 = crypto_getOperandType((uint *)local_34), puVar12 != (uint *)0x0)) {
      xtra_getStringValue(puVar12);
      crypto_parseNumber(piVar16,"%s\n");
    }
    crypto_getOperandCount(local_34);
    break;
  case (undefined **)0x4b:
    crypto_parseNumber(piVar16,"\texport *\n");
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x4c:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    iVar7 = crypto_parseAtom((int)param_1,0);
    if (iVar7 == 0) goto LAB_6814b274;
    param_1[4] = iVar7 - param_1[2];
    crypto_parseNumber(piVar16,"\texport %s\n");
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x4d:
    crypto_evalNode(0x4d);
    pcVar8 = "\timport %s.*\n";
    goto LAB_68149148;
  case (undefined **)0x4e:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    iVar7 = crypto_parseAtom((int)param_1,0);
    if (iVar7 == 0) goto LAB_6814b274;
    crypto_evalNode(0x4e);
    crypto_parseNumber(local_2c,"\timport %s.%s\n");
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x4f:
    crypto_evalNode(0x4f);
    local_50 = (undefined **)0x37;
    crypto_evalNode(0x37);
    crypto_parseNumber(local_2c,"\timport %s[%s]\n");
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x50:
  case (undefined **)0x80:
  case (undefined **)0x81:
    iVar7 = js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                         (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),
                                        *(undefined1 *)((int)param_2 + 2)));
    if (ppuVar5 == (undefined **)0x50) {
      puVar12 = certs_resizeString(local_38,*(uint *)(iVar7 + 8));
      if (puVar12 == (uint *)0x0) goto LAB_6814b274;
    }
    else {
      iVar7 = runtime_resolveConstructor((ushort *)local_38,*(uint *)(iVar7 + 8) & 0xfffffff8,0x8000,0,(uint *)0x0
                           ,&local_5c);
      if (iVar7 == 0) goto LAB_6814b274;
      puVar12 = (uint *)(local_5c & 0xfffffff8);
    }
    puVar9 = xtra_getStringValue(puVar12);
    local_28 = crypto_parseOperator(puVar9);
    break;
  case (undefined **)0x53:
    local_50 = (undefined **)runtime_getBreakpointOpcode((int)puVar12,piVar16[0xe],(int)param_2);
    if (local_50 == (undefined **)0x9a) goto LAB_6814b274;
    *(char *)param_2 = (char)local_50;
    local_4c = (byte *)(int)(char)(&DAT_68193cb8)[(int)local_50 * 0x10];
    iVar7 = crypto_evaluateExpr(param_1,param_2,(int)local_4c);
    if (iVar7 == 0) goto LAB_6814b274;
    *(undefined1 *)param_2 = 0x53;
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x54:
    uVar3 = CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2));
    goto LAB_6814a749;
  case (undefined **)0x55:
    uVar14 = (uint)*(byte *)((int)param_2 + 2);
    uVar3 = CONCAT11(*(undefined1 *)((int)param_2 + 1),*(byte *)((int)param_2 + 2));
    goto LAB_68149d40;
  case (undefined **)0x56:
    uVar14 = (uint)*(byte *)((int)param_2 + 2);
    uVar3 = CONCAT11(*(undefined1 *)((int)param_2 + 1),*(byte *)((int)param_2 + 2));
LAB_6814a749:
    iVar7 = crypto_parseAssignment(uVar14,(uint)uVar3);
    if (iVar7 == 0) goto LAB_6814b274;
LAB_6814a797:
    local_48 = runtime_getObjectSlot(local_2c[0xe],(int)local_3c);
    iVar7 = crypto_parseAtom((int)param_1,0);
    if (iVar7 == 0) goto LAB_6814b274;
    param_1[4] = iVar7 - param_1[2];
    crypto_getTypePrefix();
LAB_6814a7d3:
    local_28 = crypto_parseString("%s%s");
    param_2 = local_3c;
    break;
  case (undefined **)0x57:
    uVar3 = CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2));
LAB_68149d40:
    iVar7 = crypto_parseAssignment(uVar14,(uint)uVar3);
    if (iVar7 == 0) goto LAB_6814b274;
LAB_68149d8a:
    local_30 = (undefined **)crypto_parseAtom((int)param_1,0);
    if (local_30 == (undefined **)0x0) goto LAB_6814b274;
    iVar7 = crypto_evalNode((int)ppuVar5);
    local_40 = (byte *)(iVar7 + param_1[2]);
    if (ppuVar5 == (undefined **)0x6d) {
      crypto_evalNode(0x6d);
    }
LAB_6814a5fb:
    piVar16 = local_2c;
    param_2 = local_3c;
    local_48 = runtime_getObjectSlot(local_2c[0xe],(int)((int)local_3c + -1));
    if (((local_48 == (byte *)0x0) || (0xbf < (*local_48 & 0xf8))) || (*local_48 >> 3 != 8)) {
      local_48 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
      crypto_getTypePrefix();
      local_28 = crypto_parseString("%s%s = %s");
    }
    else {
      local_28 = crypto_parseString("%s %s= %s");
    }
    break;
  case (undefined **)0x58:
    local_28 = crypto_parseString("%u");
    break;
  case (undefined **)0x59:
    if ((uint)param_1[7] < 2) goto LAB_6814b274;
    crypto_evalNode(0x59);
    iVar7 = crypto_evalNode(0x59);
    local_50 = (undefined **)(uint)*(byte *)((int)param_2 + (int)local_40);
    if (local_50 == (undefined **)0x5d) {
      param_2 = (undefined **)((int)param_2 + (int)local_40);
      local_4c = (byte *)(int)DAT_68194288;
      local_28 = crypto_parseString("#%u=%c");
    }
    else {
      pcVar8 = "{";
      if (*(char *)(iVar7 + param_1[2]) != 'O') {
        pcVar8 = "[";
      }
      local_28 = crypto_parseString(pcVar8);
    }
    break;
  case (undefined **)0x5a:
    crypto_evalNode(0x5a);
    local_48 = runtime_getObjectSlot(local_2c[0xe],(int)param_2);
    local_28 = crypto_parseString("%s%s%c");
    break;
  case (undefined **)0x5b:
  case (undefined **)0x82:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
    local_44 = (undefined **)crypto_parseAtom((int)param_1,0);
    if (local_44 == (undefined **)0x0) goto LAB_6814b274;
    iVar7 = crypto_evalNode((int)ppuVar5);
    local_40 = (byte *)(iVar7 + param_1[2]);
    crypto_evalNode((int)ppuVar5);
LAB_6814b105:
    if ((local_34 != (undefined **)0x7b) && (local_34 != (undefined **)0x7c)) {
      pcVar8 = "%s%s%s:%s";
      goto LAB_6814a4b8;
    }
    pcVar8 = "function";
    do {
      cVar2 = *pcVar8;
      pcVar8 = pcVar8 + 1;
    } while (cVar2 != '\0');
    bVar18 = local_34 != (undefined **)0x7b;
    local_34 = (undefined **)&DAT_6817f180;
    if (bVar18) {
      local_34 = (undefined **)&DAT_6817f1c4;
    }
    local_28 = crypto_parseString("%s%s%s %s%s");
    break;
  case (undefined **)0x5c:
    iVar7 = crypto_evalNode(0x5c);
    local_40 = (byte *)(iVar7 + param_1[2]);
    iVar7 = crypto_evalNode(0x5c);
    local_44 = (undefined **)(iVar7 + param_1[2]);
    crypto_evalNode(0x5c);
    local_48 = runtime_getObjectSlot(local_2c[0xe],(int)param_2);
    if (((local_48 != (byte *)0x0) && ((*local_48 & 0xf8) < 0xc0)) && (*local_48 >> 3 == 0xd))
    goto LAB_6814b105;
    local_28 = crypto_parseString("%s%s%s");
    break;
  case (undefined **)0x5d:
    crypto_evalNode(0x5d);
    local_28 = crypto_parseString("#%u=%s");
    break;
  case (undefined **)0x5e:
    local_28 = crypto_parseString("#%u#");
    break;
  case (undefined **)0x5f:
  case (undefined **)0x61:
    uVar3 = CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2));
    goto LAB_6814a0cd;
  case (undefined **)0x60:
  case (undefined **)0x62:
    uVar14 = (uint)*(byte *)((int)param_2 + 2);
    uVar3 = CONCAT11(*(undefined1 *)((int)param_2 + 1),*(byte *)((int)param_2 + 2));
LAB_6814a0cd:
    iVar7 = crypto_parseAssignment(uVar14,(uint)uVar3);
    if (iVar7 == 0) goto LAB_6814b274;
LAB_6814a117:
    iVar7 = crypto_parseAtom((int)param_1,0);
    if (iVar7 == 0) goto LAB_6814b274;
    param_1[4] = iVar7 - param_1[2];
    goto LAB_6814a7d3;
  case (undefined **)0x63:
  case (undefined **)0x65:
    uVar3 = CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2));
    goto LAB_6814a225;
  case (undefined **)0x64:
  case (undefined **)0x66:
    uVar14 = (uint)*(byte *)((int)param_2 + 2);
    uVar3 = CONCAT11(*(undefined1 *)((int)param_2 + 1),*(byte *)((int)param_2 + 2));
LAB_6814a225:
    iVar7 = crypto_parseAssignment(uVar14,(uint)uVar3);
    if (iVar7 == 0) goto LAB_6814b274;
LAB_6814a26f:
    iVar7 = crypto_parseAtom((int)param_1,0);
    if (iVar7 == 0) goto LAB_6814b274;
    local_28 = iVar7 - param_1[2];
    crypto_parseOperator(*(void **)((~((uint)local_30[3] >> 9) & 1) * 4 + 0x68193ca4));
    param_2 = local_3c;
    break;
  case (undefined **)0x68:
    js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                 (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
                );
LAB_68149a9e:
    local_30 = (undefined **)crypto_parseAtom((int)param_1,0);
    if (local_30 == (undefined **)0x0) goto LAB_6814b274;
    param_1[4] = (int)local_30 - param_1[2];
    piVar16 = local_2c;
LAB_68149ac2:
    ppuVar17 = local_3c;
    runtime_getObjectSlot(piVar16[0xe],(int)local_3c);
    local_44 = (undefined **)0x0;
    local_34 = (undefined **)0x0;
LAB_68149b1c:
    ppuVar17 = (undefined **)((int)ppuVar17 + (int)local_40);
    bVar4 = *(byte *)ppuVar17;
    local_3c = ppuVar17;
    if ((bVar4 != 7) && (bVar4 != 0x8c)) goto LAB_6814b274;
    local_40 = (byte *)(int)(char)(&DAT_68193cb8)[(uint)bVar4 * 0x10];
    local_4c = (byte *)crypto_getNodeType((int)ppuVar17);
    local_48 = runtime_getObjectSlot(piVar16[0xe],(int)ppuVar17);
    local_54 = (byte *)js_getObjectFlags((int)local_48,0);
LAB_68149bf0:
    crypto_getTypePrefix();
    crypto_parseNumber(piVar16,"\tfor (%s%s");
    if (local_34 == (undefined **)0x0) {
      if (local_44 != (undefined **)0x0) {
        pcVar8 = "[%s]";
        goto LAB_68149c49;
      }
    }
    else {
      iVar7 = crypto_parseAtom((int)param_1,0);
      if (iVar7 == 0) goto LAB_6814b274;
      param_1[4] = iVar7 - param_1[2];
      pcVar8 = ".%s";
LAB_68149c49:
      crypto_parseNumber(piVar16,pcVar8);
    }
    crypto_parseNumber(piVar16," in %s) {\n");
    piVar16[0xc] = piVar16[0xc] + 4;
    iVar7 = crypto_evaluateExpr(param_1,(undefined **)((int)ppuVar17 + (int)local_40),
                         (int)local_54 - (int)local_40);
    if (iVar7 == 0) goto LAB_6814b274;
    piVar16[0xc] = piVar16[0xc] + -4;
    crypto_parseNumber(piVar16,"\t}\n");
    local_28 = 0xfffffffe;
    param_2 = local_3c;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x69:
    local_44 = (undefined **)0x0;
    local_34 = (undefined **)
               js_allocAtom(puVar12,(int *)(piVar16[0xe] + 0x10),
                            (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),
                                           *(undefined1 *)((int)param_2 + 2)));
    iVar7 = crypto_evalNode(0x69);
    local_30 = (undefined **)(iVar7 + param_1[2]);
    piVar16 = local_2c;
    ppuVar17 = local_3c;
    goto LAB_68149b1c;
  case (undefined **)0x6a:
    bVar4 = *(byte *)((int)param_2 + 1);
    ppuVar17 = (undefined **)((int)param_2 + 1);
    if ((bVar4 != 7) && (bVar4 != 0x8c)) goto LAB_6814b274;
    local_4c = (byte *)(int)(char)(&DAT_68193cb8)[(uint)bVar4 * 0x10];
    local_48 = runtime_getObjectSlot(piVar16[0xe],(int)ppuVar17);
    uVar14 = js_getObjectFlags((int)local_48,0);
    local_54 = (byte *)(uVar14 - (int)local_40);
    uVar14 = crypto_getNodeType((int)ppuVar17);
    local_58 = (byte *)(uVar14 + (int)ppuVar17);
    param_2 = ppuVar17;
    break;
  case (undefined **)0x6b:
    crypto_evalNode(0x6b);
    crypto_evalNode(0x6b);
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x6e:
    local_48 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
    local_28 = 0xfffffffe;
    if (((local_48 == (byte *)0x0) || (0xbf < (*local_48 & 0xf8))) || (*local_48 >> 3 != 0xb)) {
      crypto_evalNode(0x6e);
      crypto_parseNumber(local_2c,"\t%s %s;\n");
    }
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x71:
    crypto_parseNumber(piVar16,"\tdebugger;\n");
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x72:
  case (undefined **)0x87:
  case (undefined **)0x90:
    goto switchD_68148cfb_caseD_72;
  case (undefined **)0x73:
    iVar7 = crypto_evalNode(0x73);
    pbVar13 = (byte *)(iVar7 + param_1[2]);
    pcVar8 = "finally-cookie";
    do {
      bVar4 = *pbVar13;
      bVar18 = bVar4 < (byte)*pcVar8;
      if (bVar4 != *pcVar8) {
LAB_68149080:
        iVar7 = (1 - (uint)bVar18) - (uint)(bVar18 != 0);
        goto LAB_68149085;
      }
      if (bVar4 == 0) break;
      bVar4 = pbVar13[1];
      bVar18 = bVar4 < (byte)pcVar8[1];
      if (bVar4 != pcVar8[1]) goto LAB_68149080;
      pbVar13 = pbVar13 + 2;
      pcVar8 = pcVar8 + 2;
    } while (bVar4 != 0);
    iVar7 = 0;
LAB_68149085:
    if (iVar7 != 0) goto LAB_6814b274;
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x74:
    local_48 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
    if (((local_48 == (byte *)0x0) || (0xbf < (*local_48 & 0xf8))) || (*local_48 >> 3 != 0xb))
    goto LAB_6814b274;
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x75:
    param_1[7] = (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),*(undefined1 *)((int)param_2 + 2))
    ;
    break;
  case (undefined **)0x76:
    pbVar13 = runtime_getObjectSlot(piVar16[0xe],(int)param_2);
    local_48 = pbVar13;
    local_4c = (byte *)js_getObjectFlags((int)pbVar13,0);
    ppuVar17 = (undefined **)js_getObjectFlags((int)pbVar13,1);
    local_34 = (undefined **)0x0;
    local_3c = ppuVar17;
    ppuVar6 = param_2;
    while (ppuVar17 != (undefined **)0x0) {
      ppuVar6 = (undefined **)((int)ppuVar6 + (int)ppuVar17);
      if ((*(byte *)ppuVar6 == 0x78) || (*(byte *)ppuVar6 == 0x92)) {
        ppuVar17 = (undefined **)0x0;
      }
      else {
        local_48 = runtime_getObjectSlot(local_2c[0xe],(int)ppuVar6);
        ppuVar17 = (undefined **)js_getObjectFlags((int)local_48,0);
      }
      local_34 = (undefined **)((int)local_34 + 1);
    }
    local_30 = (undefined **)xtra_getPropertyById((int)local_38,(int)local_34 * 8);
    if (local_30 == (undefined **)0x0) goto LAB_6814b274;
    local_44 = local_3c;
    local_3c = (undefined **)0x0;
    ppuVar17 = param_2;
    if (0 < (int)local_34) {
      do {
        ppuVar17 = (undefined **)((int)ppuVar17 + (int)local_44);
        local_40 = (byte *)((int)ppuVar17 - (int)param_2);
        local_30[(int)local_3c * 2] = (undefined *)((int)local_40 * 2 | 1);
        uVar14 = crypto_getNodeType((int)ppuVar17);
        local_30[(int)local_3c * 2 + 1] = local_40 + uVar14;
        if ((*(byte *)ppuVar17 == 0x77) || (*(byte *)ppuVar17 == 0x91)) {
          local_48 = runtime_getObjectSlot(local_2c[0xe],(int)ppuVar17);
          local_44 = (undefined **)js_getObjectFlags((int)local_48,0);
        }
        local_3c = (undefined **)((int)local_3c + 1);
      } while ((int)local_3c < (int)local_34);
    }
    puVar9 = local_30[(int)local_34 * 2 + -2];
    uVar14 = crypto_getNodeType((int)param_2 + ((int)puVar9 >> 1));
    iVar7 = crypto_decompileSwitch((int)local_30,(uint)local_34,param_2,(int)local_4c,
                         ((int)puVar9 >> 1) + uVar14,1);
    ppuVar17 = local_30;
LAB_6814aa61:
    xtra_checkAndFlush(local_38,(int)ppuVar17);
    if (iVar7 == 0) goto LAB_6814b274;
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x77:
  case (undefined **)0x91:
    iVar7 = crypto_evalNode((int)ppuVar5);
    if (iVar7 + param_1[2] == 0) goto LAB_6814b274;
    pcVar8 = "\tcase %s:\n";
LAB_68149148:
    crypto_parseNumber(local_2c,pcVar8);
LAB_68149154:
    local_28 = 0xfffffffe;
    goto switchD_68148d4f_caseD_5;
  case (undefined **)0x7a:
    local_34 = (undefined **)0x0;
    iVar7 = crypto_evalNode(0x7a);
    local_44 = (undefined **)(iVar7 + param_1[2]);
    iVar7 = crypto_evalNode(0x7a);
    local_30 = (undefined **)(iVar7 + param_1[2]);
    local_4c = local_58 + -(int)param_2;
    local_58 = (byte *)0x0;
    piVar16 = local_2c;
    ppuVar17 = local_3c;
    goto LAB_68149bf0;
  case (undefined **)0x83:
    local_28 = crypto_evalNode((int)ppuVar17);
    if ((byte)(&DAT_68193cbb)[(int)ppuVar17 * 0x10] <=
        (byte)(&DAT_68193cbb)[(uint)*(byte *)(param_1[7] + param_1[6]) * 0x10]) {
      local_28 = crypto_parseString("(%s)");
    }
    break;
  case (undefined **)0x85:
    crypto_parseNumber(piVar16,"\ttry {\n");
    piVar16[0xc] = piVar16[0xc] + 4;
    goto switchD_68148cfb_caseD_72;
  case (undefined **)0x86:
    piVar16[0xc] = piVar16[0xc] + -4;
    crypto_parseNumber(piVar16,"\t} finally {\n");
    piVar16[0xc] = piVar16[0xc] + 4;
    local_28 = crypto_parseString("finally-cookie");
    break;
  case (undefined **)0x88:
    local_28 = crypto_parseString("%s[%d]");
    break;
  case (undefined **)0x89:
    local_28 = crypto_parseString("%s.%s");
    break;
  case (undefined **)0x99:
    break;
  case (undefined **)0xfe:
    local_50 = (undefined **)0x35;
    crypto_evalNode((int)ppuVar17);
    goto switchD_68148cfb_caseD_35;
  case (undefined **)0xff:
    crypto_evalNode((int)ppuVar17);
switchD_68148cfb_caseD_37:
    iVar10 = crypto_evalNode(0);
    iVar7 = param_1[2];
    local_50 = (undefined **)0x37;
    crypto_evalNode(0x37);
    if (*(char *)(iVar10 + iVar7) == '\0') {
      local_28 = crypto_parseString("%s");
      break;
    }
    goto LAB_6814a5ab;
  }
switchD_68148cfb_caseD_99:
  if ((int)local_28 < 0) {
    bVar18 = local_28 == 0xffffffff;
  }
  else {
    iVar7 = crypto_emitOperand(local_28);
    bVar18 = iVar7 == 0;
  }
  if (bVar18) {
LAB_6814b274:
    return 0;
  }
switchD_68148d4f_caseD_5:
  param_2 = (undefined **)((int)param_2 + (int)local_4c);
  puVar12 = local_38;
  piVar16 = local_2c;
  ppuVar17 = local_50;
  goto joined_r0x68148b99;
switchD_68148cfb_caseD_35:
  ppuVar17 = local_50;
  iVar7 = js_allocAtom(local_38,(int *)(local_2c[0xe] + 0x10),
                       (uint)CONCAT11(*(undefined1 *)((int)param_2 + 1),
                                      *(undefined1 *)((int)param_2 + 2)));
  local_34 = (undefined **)(*(uint *)(iVar7 + 8) & 0xfffffff8);
  iVar7 = crypto_isValidIdentifier(extraout_ECX,(uint *)local_34);
  if (iVar7 == 0) {
    local_44 = (undefined **)crypto_parseAtom((int)param_1,0x27);
    crypto_evalNode((int)ppuVar17);
LAB_6814a5ab:
    local_28 = crypto_parseString("%s[%s]");
  }
  else {
    crypto_evalNode((int)ppuVar17);
    xtra_getStringValue((uint *)local_34);
    local_28 = crypto_parseString("%s.%s");
  }
  goto switchD_68148cfb_caseD_99;
switchD_68148cfb_caseD_c:
  local_50 = (undefined **)(uint)*(byte *)(param_1[6] + -1 + param_1[7]);
  pcVar15 = (char *)(*(int *)(param_1[5] + -4 + param_1[7] * 4) + param_1[2]);
  pcVar8 = pcVar15;
  do {
    cVar2 = *pcVar8;
    pcVar8 = pcVar8 + 1;
  } while (cVar2 != '\0');
  local_28 = crypto_parseOperator(pcVar15);
  goto switchD_68148cfb_caseD_99;
switchD_68148cfb_caseD_72:
  local_28 = 0xfffffffe;
  goto switchD_68148d4f_caseD_5;
}



