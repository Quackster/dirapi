// Source: decompiled_functions.c
// Module: javascript
// Address range: 0x6813b6e0 - 0x6813b6e0
// Functions (1):
//   javascript_convertDoubleToAscii

// ============================================================
// Function: javascript_convertDoubleToAscii (FUN_6813b6e0)
// Address: 6813b6e0
// Size: 4814 bytes
// Params: double param_1, char * param_2, int param_3, char * param_4, undefined4 * param_5, undefined4 * param_6, undefined4 * param_7, char * param_8, char * param_9
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
javascript_convertDoubleToAscii(double param_1,char *param_2,int param_3,char *param_4,undefined4 *param_5,
            undefined4 *param_6,undefined4 *param_7,char *param_8,char *param_9)

{
  char cVar1;
  double dVar2;
  char *pcVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  char *pcVar7;
  char *extraout_ECX;
  char *extraout_ECX_00;
  char *extraout_ECX_01;
  char *extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  uint uVar8;
  char *pcVar9;
  bool bVar10;
  ulonglong uVar11;
  char *local_dc;
  char *local_d8;
  char *local_d4;
  char *local_d0;
  uint local_c0;
  char *local_bc;
  char *local_b0;
  char *local_ac;
  char *local_a8;
  char *local_a0;
  char local_9c;
  char *local_94;
  int local_90;
  int local_8c;
  int local_88;
  int local_84;
  char *local_80;
  char *local_7c;
  uint local_78;
  char *local_74;
  char *local_70;
  char *local_6c;
  int local_68;
  char *local_64;
  int local_60;
  double local_5c;
  char *local_50;
  undefined8 local_4c;
  char *local_40;
  int local_3c;
  int local_38;
  int local_34;
  char *local_30;
  undefined8 local_2c;
  char *local_24;
  char *local_20;
  uint local_1c;
  int local_18;
  uint local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  if (((ulonglong)param_1 & 0x8000000000000000) == 0) {
    *param_6 = 0;
  }
  else {
    *param_6 = 1;
    param_1 = ABS(param_1);
  }
  if (((*(unsigned int *)((char *)&param_1 + 4)) & 0x7ff00000) == 0x7ff00000) {
    *param_5 = 9999;
    if (((*(unsigned int *)((char *)&param_1 + 0)) == 0) && (((ulonglong)param_1 & 0xfffff00000000) == 0)) {
      local_a8 = "Infinity";
    }
    else {
      local_a8 = "NaN";
    }
    if (((*local_a8 != 'I') || ((char *)0x8 < param_9)) &&
       ((*local_a8 != 'N' || ((char *)0x3 < param_9)))) {
      local_ac = local_a8;
      local_b0 = param_8;
      do {
        cVar1 = *local_ac;
        *local_b0 = cVar1;
        local_ac = local_ac + 1;
        local_b0 = local_b0 + 1;
      } while (cVar1 != '\0');
      if (param_7 != (undefined4 *)0x0) {
        if (param_8[3] == '\0') {
          local_bc = param_8 + 3;
        }
        else {
          local_bc = param_8 + 8;
        }
        *param_7 = local_bc;
      }
      return 1;
    }
    return 0;
  }
  local_60 = 0;
  local_34 = 0;
  local_18 = 0;
  local_90 = 0;
  iVar6 = local_34;
  if (param_1 == 0.0) goto LAB_6813b857;
  local_60 = javascript_bignumExtractExponent((*(unsigned int *)((char *)&param_1 + 0)),(*(unsigned int *)((char *)&param_1 + 4)),&local_3c,&local_8c);
  if (local_60 == 0) goto LAB_6813c96a;
  uVar4 = (*(unsigned int *)((char *)&param_1 + 4)) >> 0x14 & 0x7ff;
  if (uVar4 == 0) {
    iVar6 = local_8c + 0x432 + local_3c;
    cVar1 = (char)iVar6;
    if (iVar6 < 0x21) {
      local_c0 = (*(unsigned int *)((char *)&param_1 + 0)) << (0x20U - cVar1 & 0x1f);
    }
    else {
      local_c0 = (*(unsigned int *)((char *)&param_1 + 4)) << (0x40U - cVar1 & 0x1f) | (*(unsigned int *)((char *)&param_1 + 0)) >> (cVar1 - 0x20U & 0x1f);
    }
    local_1c = local_c0;
    (*(unsigned int *)((char *)&local_4c + 4)) = (uint)((ulonglong)(double)local_c0 >> 0x20);
    uVar8 = (*(unsigned int *)((char *)&local_4c + 4)) + 0xfe100000;
    local_4c = (double)CONCAT44(uVar8,SUB84((double)local_c0,0));
    local_20 = (char *)(iVar6 + -0x433);
    local_68 = 1;
  }
  else {
    local_c0 = (*(unsigned int *)((char *)&param_1 + 4)) & 0xfffff;
    local_4c = (double)((ulonglong)param_1 & 0xfffffffffffff);
    uVar8 = (*(unsigned int *)((char *)&local_4c + 4)) | 0x3ff00000;
    local_4c = (double)((ulonglong)local_4c | 0x3ff0000000000000);
    local_20 = (char *)(uVar4 - 0x3ff);
    local_68 = 0;
  }
  local_5c = (double)(int)local_20 * 0.301029995663981 +
             (local_4c - 1.5) * 0.289529654602168 + 0.1760912590558;
  uVar11 = strings_floatToUint64(local_c0,uVar8);
  pcVar9 = (char *)(uVar11 >> 0x20);
  local_80 = (char *)(size_t)uVar11;
  if ((local_5c < 0.0) && (local_5c != (double)(int)local_80)) {
    local_80 = local_80 + -1;
  }
  pcVar3 = local_80;
  local_84 = 1;
  if ((-1 < (int)local_80) && ((int)local_80 < 0x17)) {
    if (param_1 < *(double *)(&DAT_6817f228 + (int)local_80 * 8)) {
      local_80 = local_80 + -1;
    }
    local_84 = 0;
    pcVar9 = pcVar3;
  }
  local_7c = (char *)((local_8c - (int)local_20) + -1);
  if ((int)local_7c < 0) {
    local_40 = (char *)-(int)local_7c;
    local_7c = (char *)0x0;
  }
  else {
    local_40 = (char *)0x0;
    pcVar9 = local_7c;
  }
  if ((int)local_80 < 0) {
    local_40 = local_40 + -(int)local_80;
    local_c = -(int)local_80;
    local_6c = (char *)0x0;
  }
  else {
    local_c = 0;
    local_6c = local_80;
    pcVar9 = local_7c + (int)local_80;
    local_7c = pcVar9;
  }
  if (((int)param_2 < 0) || (9 < (int)param_2)) {
    param_2 = (char *)0x0;
  }
  bVar10 = 5 < (int)param_2;
  if (bVar10) {
    pcVar9 = param_2 + -4;
    param_2 = pcVar9;
  }
  local_78 = (uint)!bVar10;
  local_38 = 1;
  local_50 = (char *)0x0;
  local_94 = (char *)0x0;
  switch ((int)(size_t)param_2) { /* FIXUP(C2050): cast non-integral switch to int */
  case (char *)0x0:
  case (char *)0x1:
    local_50 = (char *)0xffffffff;
    local_94 = (char *)0xffffffff;
    local_20 = (char *)0x12;
    param_4 = (char *)0x0;
    pcVar9 = param_2;
    break;
  case (char *)0x2:
    local_38 = 0;
  case (char *)0x4:
    if ((int)param_4 < 1) {
      param_4 = (char *)0x1;
    }
    local_20 = param_4;
    local_50 = param_4;
    local_94 = param_4;
    pcVar9 = param_4;
    break;
  case (char *)0x3:
    local_38 = 0;
  case (char *)0x5:
    local_94 = param_4 + 1 + (int)local_80;
    local_50 = local_94 + -1;
    pcVar9 = local_50;
    local_20 = local_94;
    if ((int)local_94 < 1) {
      local_20 = (char *)0x1;
    }
  }
  pcVar3 = local_94;
  if (param_9 <= local_20) {
    js_freePooledObject();
    return 0;
  }
  local_24 = param_8;
  if ((((int)local_94 < 0) || (0xe < (int)local_94)) || (local_78 == 0)) {
LAB_6813bf72:
    local_24 = param_8;
    if ((-1 < local_3c) && ((int)local_80 < 0xf)) {
      local_5c = *(double *)(&DAT_6817f228 + (int)local_80 * 8);
      if ((-1 < (int)param_4) || (0 < (int)pcVar3)) {
        local_20 = (char *)0x1;
        pcVar7 = local_80;
        while( true ) {
          uVar11 = strings_floatToUint64(pcVar7,pcVar9);
          dVar2 = param_1 - (double)(int)uVar11 * local_5c;
          local_9c = (char)uVar11;
          *local_24 = local_9c + '0';
          pcVar5 = local_24 + 1;
          if (local_20 == pcVar3) break;
          param_1 = dVar2 * 10.0;
          if (param_1 == 0.0) goto LAB_6813c93c;
          pcVar7 = local_20;
          pcVar9 = local_24;
          local_24 = pcVar5;
          local_20 = local_20 + 1;
        }
        if ((dVar2 + dVar2 <= local_5c) &&
           ((local_5c != dVar2 + dVar2 || (((uVar11 & 1) == 0 && (param_3 == 0))))))
        goto LAB_6813c93c;
LAB_6813c07b:
        do {
          local_24 = pcVar5;
          pcVar5 = local_24 + -1;
          if (*pcVar5 != '9') goto LAB_6813c0aa;
        } while (pcVar5 != param_8);
        local_80 = local_80 + 1;
        *pcVar5 = '0';
LAB_6813c0aa:
        *pcVar5 = *pcVar5 + '\x01';
        pcVar5 = local_24;
        goto LAB_6813c93c;
      }
      local_18 = 0;
      iVar6 = 0;
      local_34 = 0;
      if ((((int)pcVar3 < 0) || (param_1 < local_5c * 5.0)) ||
         ((param_3 == 0 && (param_1 == local_5c * 5.0)))) goto LAB_6813b857;
      goto LAB_6813c4e0;
    }
    local_70 = local_40;
    local_14 = local_c;
    if (local_38 != 0) {
      if ((int)param_2 < 2) {
        if (local_68 == 0) {
          local_d0 = (char *)(0x36 - local_8c);
        }
        else {
          local_d0 = (char *)(local_3c + 0x433);
        }
        local_20 = local_d0;
      }
      else {
        pcVar9 = pcVar3 + -1;
        if ((int)local_c < (int)pcVar9) {
          local_6c = local_6c + ((int)pcVar9 - local_c);
          local_c = local_c + ((int)pcVar9 - local_c);
          local_14 = 0;
        }
        else {
          local_14 = local_c - (int)pcVar9;
        }
        local_20 = pcVar3;
        if ((int)pcVar3 < 0) {
          local_70 = local_40 + -(int)pcVar3;
          local_20 = (char *)0x0;
        }
      }
      local_40 = local_40 + (int)local_20;
      local_7c = local_7c + (int)local_20;
      local_18 = js_bignumNormalize(1);
      if (local_18 == 0) goto LAB_6813c96a;
    }
    if ((0 < (int)local_70) && (0 < (int)local_7c)) {
      if ((int)local_70 < (int)local_7c) {
        local_d4 = local_70;
      }
      else {
        local_d4 = local_7c;
      }
      local_20 = local_d4;
      local_40 = local_40 + -(int)local_d4;
      local_70 = local_70 + -(int)local_d4;
      local_7c = local_7c + -(int)local_d4;
    }
    if (0 < (int)local_c) {
      if (local_38 == 0) {
        local_60 = js_bignumShift(local_c);
      }
      else {
        if (0 < (int)local_14) {
          local_18 = js_bignumShift(local_14);
          if ((local_18 == 0) || (iVar6 = javascript_bignumMultiplyFull(local_18), iVar6 == 0)) goto LAB_6813c96a;
          js_freePooledObject();
          local_60 = iVar6;
        }
        if (local_c - local_14 == 0) goto LAB_6813c2c5;
        local_60 = js_bignumShift(local_c - local_14);
      }
      if (local_60 == 0) goto LAB_6813c96a;
    }
LAB_6813c2c5:
    local_34 = js_bignumNormalize(1);
    if ((local_34 == 0) ||
       ((pcVar9 = extraout_ECX, 0 < (int)local_6c &&
        (local_34 = js_bignumShift((uint)local_6c), pcVar9 = extraout_ECX_00, local_34 == 0)))) {
LAB_6813c96a:
      js_freePooledObject();
      if (local_18 != 0) {
        if ((local_90 != 0) && (local_90 != local_18)) {
          js_freePooledObject();
        }
        js_freePooledObject();
      }
      js_freePooledObject();
      return 0;
    }
    local_10 = 0;
    if (((int)param_2 < 2) &&
       ((((*(unsigned int *)((char *)&param_1 + 0)) == 0 && (((ulonglong)param_1 & 0xfffff00000000) == 0)) &&
        (((ulonglong)param_1 & 0x7fe0000000000000) != 0)))) {
      pcVar9 = local_40 + 1;
      local_7c = local_7c + 1;
      local_10 = 1;
      local_40 = pcVar9;
    }
    if (local_6c == (char *)0x0) {
      local_d8 = (char *)0x1;
    }
    else {
      iVar6 = javascript_bignumCountLeadingZeros(*(uint *)(local_34 + 0x10 + *(int *)(local_34 + 0x10) * 4));
      pcVar9 = (char *)(0x20 - iVar6);
      local_d8 = pcVar9;
    }
    local_20 = (char *)((uint)(local_d8 + (int)local_7c) & 0x1f);
    if (local_20 != (char *)0x0) {
      local_20 = (char *)(0x20 - (int)local_20);
    }
    if ((int)local_20 < 5) {
      if ((int)local_20 < 4) {
        local_20 = local_20 + 0x1c;
        local_40 = local_40 + (int)local_20;
        pcVar9 = local_70 + (int)local_20;
        local_7c = local_7c + (int)local_20;
        local_70 = pcVar9;
      }
    }
    else {
      local_20 = local_20 + -4;
      local_40 = local_40 + (int)local_20;
      pcVar9 = local_7c + (int)local_20;
      local_7c = pcVar9;
      local_70 = local_70 + (int)local_20;
    }
    if (((0 < (int)local_40) &&
        (local_60 = js_bignumDivide(local_60,(uint)local_40), pcVar9 = extraout_ECX_01, local_60 == 0))
       || ((0 < (int)local_7c &&
           (local_34 = js_bignumDivide(local_34,(uint)local_7c), pcVar9 = extraout_ECX_02,
           local_34 == 0)))) goto LAB_6813c96a;
    local_94 = pcVar3;
    if ((local_84 != 0) && (iVar6 = js_bignumCompare(pcVar9,local_60), iVar6 < 0)) {
      local_80 = local_80 + -1;
      local_60 = js_bignumMultiply(local_60,10,0);
      if ((local_60 == 0) ||
         ((local_38 != 0 && (local_18 = js_bignumMultiply(local_18,10,0), local_18 == 0))))
      goto LAB_6813c96a;
      local_94 = local_50;
    }
    if (((int)local_94 < 1) && (2 < (int)param_2)) {
      iVar6 = local_34;
      if ((int)local_94 < 0) {
LAB_6813b857:
        local_34 = iVar6;
        *param_5 = 1;
        if (param_9 < (char *)0x2) {
          return 0;
        }
        *param_8 = '0';
        param_8[1] = '\0';
        if (param_7 != (undefined4 *)0x0) {
          *param_7 = param_8 + 1;
        }
        js_freePooledObject();
        js_freePooledObject();
        if (local_18 != 0) {
          js_freePooledObject();
        }
        js_freePooledObject();
        return 1;
      }
      local_34 = js_bignumMultiply(local_34,5,0);
      if (local_34 == 0) {
        local_34 = 0;
        goto LAB_6813c96a;
      }
      local_20 = (char *)js_bignumCompare(extraout_ECX_03,local_60);
      iVar6 = local_34;
      if (((int)local_20 < 0) || ((local_20 == (char *)0x0 && (param_3 == 0)))) goto LAB_6813b857;
      goto LAB_6813c4e0;
    }
    if (local_38 != 0) {
      if ((0 < (int)local_70) && (local_18 = js_bignumDivide(local_18,(uint)local_70), local_18 == 0))
      goto LAB_6813c96a;
      iVar6 = local_18;
      local_90 = local_18;
      if (local_10 != 0) {
        local_18 = js_bignumAlloc();
        if (local_18 == 0) {
          local_18 = 0;
          goto LAB_6813c96a;
        }
        memcpy((void *)(local_18 + 0xc),(void *)(iVar6 + 0xc),*(int *)(iVar6 + 0x10) * 4 + 8);
        local_18 = js_bignumDivide(local_18,1);
        if (local_18 == 0) goto LAB_6813c96a;
      }
      local_20 = (char *)0x1;
      while( true ) {
        local_8 = javascript_bignumDivideQuotient(local_60,local_34);
        local_8 = local_8 + 0x30;
        iVar6 = js_bignumCompare(extraout_ECX_04,local_60);
        local_88 = javascript_bignumDivideRemainder(local_34);
        if (local_88 == 0) break;
        if (*(int *)(local_88 + 0xc) == 0) {
          local_dc = (char *)js_bignumCompare(local_88,local_60);
        }
        else {
          local_dc = (char *)0x1;
        }
        local_74 = local_dc;
        js_freePooledObject();
        uVar4 = local_8;
        if (((local_74 == (char *)0x0) && (param_2 == (char *)0x0)) &&
           (((ulonglong)param_1 & 1) == 0)) {
          if (local_8 != 0x39) {
            if (0 < iVar6) {
              local_8 = local_8 + 1;
            }
            *local_24 = (char)local_8;
            local_24 = local_24 + 1;
            goto LAB_6813c907;
          }
LAB_6813c70e:
          local_8 = uVar4;
          *local_24 = '9';
          pcVar9 = local_24 + 1;
          goto LAB_6813c898;
        }
        if ((iVar6 < 0) ||
           (((iVar6 == 0 && (param_2 == (char *)0x0)) && (((ulonglong)param_1 & 1) == 0)))) {
          if (0 < (int)local_74) {
            local_60 = js_bignumDivide(local_60,1);
            if (local_60 == 0) {
              local_60 = 0;
              break;
            }
            local_74 = (char *)js_bignumCompare(extraout_ECX_05,local_60);
            if (((0 < (int)local_74) ||
                ((local_74 == (char *)0x0 && (((local_8 & 1) != 0 || (param_3 != 0)))))) &&
               (uVar4 = local_8 + 1, bVar10 = local_8 == 0x39, local_8 = uVar4, bVar10))
            goto LAB_6813c70e;
          }
          *local_24 = (char)local_8;
          local_24 = local_24 + 1;
          goto LAB_6813c907;
        }
        if (0 < (int)local_74) {
          if (local_8 == 0x39) goto LAB_6813c70e;
          *local_24 = (char)local_8 + '\x01';
          local_24 = local_24 + 1;
          goto LAB_6813c907;
        }
        *local_24 = (char)local_8;
        local_24 = local_24 + 1;
        if (local_20 == local_94) goto LAB_6813c84e;
        local_60 = js_bignumMultiply(local_60,10,0);
        if (local_60 == 0) break;
        if (local_90 == local_18) {
          local_90 = js_bignumMultiply(local_18,10,0);
          local_18 = local_90;
        }
        else {
          local_90 = js_bignumMultiply(local_90,10,0);
          if (local_90 == 0) break;
          local_18 = js_bignumMultiply(local_18,10,0);
        }
        if (local_18 == 0) break;
        local_20 = local_20 + 1;
      }
      goto LAB_6813c96a;
    }
    local_20 = (char *)0x1;
    while( true ) {
      local_8 = javascript_bignumDivideQuotient(local_60,local_34);
      local_8 = local_8 + 0x30;
      *local_24 = (char)local_8;
      local_24 = local_24 + 1;
      if ((int)local_94 <= (int)local_20) break;
      local_60 = js_bignumMultiply(local_60,10,0);
      if (local_60 == 0) {
        local_60 = 0;
        goto LAB_6813c96a;
      }
      local_20 = local_20 + 1;
    }
LAB_6813c84e:
    local_60 = js_bignumDivide(local_60,1);
    if (local_60 == 0) {
      local_60 = 0;
      goto LAB_6813c96a;
    }
    iVar6 = js_bignumCompare(extraout_ECX_06,local_60);
    pcVar9 = local_24;
    if ((iVar6 < 1) && ((iVar6 != 0 || (((local_8 & 1) == 0 && (param_3 == 0)))))) {
      do {
        local_24 = pcVar9;
        pcVar9 = local_24 + -1;
      } while (local_24[-1] == '0');
    }
    else {
LAB_6813c898:
      do {
        local_24 = pcVar9;
        pcVar9 = local_24 + -1;
        if (*pcVar9 != '9') {
          *pcVar9 = *pcVar9 + '\x01';
          goto LAB_6813c907;
        }
      } while (pcVar9 != param_8);
      local_80 = local_80 + 1;
      *pcVar9 = '1';
    }
  }
  else {
    local_20 = (char *)0x0;
    local_4c = param_1;
    local_30 = local_80;
    local_64 = (char *)0x2;
    if ((int)local_80 < 1) {
      local_74 = (char *)-(int)local_80;
      pcVar9 = local_74;
      if (local_74 != (char *)0x0) {
        param_1 = param_1 * *(double *)(&DAT_6817f228 + ((uint)local_74 & 0xf) * 8);
        local_a0 = (char *)((int)local_74 >> 4);
        while (local_a0 != (char *)0x0) {
          if (((uint)local_a0 & 1) != 0) {
            local_64 = local_64 + 1;
            param_1 = param_1 * (double)(&DAT_6817f2e0)[(int)local_20];
          }
          local_20 = local_20 + 1;
          pcVar9 = (char *)((int)local_a0 >> 1);
          local_a0 = pcVar9;
        }
      }
    }
    else {
      local_5c = *(double *)(&DAT_6817f228 + ((uint)local_80 & 0xf) * 8);
      pcVar9 = (char *)((int)local_80 >> 4);
      local_a0 = pcVar9;
      if (((uint)pcVar9 & 0x10) != 0) {
        local_a0 = (char *)((uint)pcVar9 & 0xf);
        param_1 = param_1 / 1e+256;
        pcVar9 = (char *)0x3;
        local_64 = pcVar9;
      }
      for (; local_a0 != (char *)0x0; local_a0 = (char *)((int)local_a0 >> 1)) {
        pcVar9 = (char *)((uint)local_a0 & 1);
        if (pcVar9 != (char *)0x0) {
          local_64 = local_64 + 1;
          local_5c = local_5c * (double)(&DAT_6817f2e0)[(int)local_20];
        }
        local_20 = local_20 + 1;
      }
      param_1 = param_1 / local_5c;
    }
    if (((local_84 != 0) && (param_1 < 1.0)) && (0 < (int)local_94)) {
      if (0 < (int)local_50) {
        local_94 = local_50;
        pcVar9 = local_80 + -1;
        param_1 = param_1 * 10.0;
        local_64 = local_64 + 1;
        local_80 = pcVar9;
        goto LAB_6813bd6c;
      }
LAB_6813bf54:
      param_1 = local_4c;
      local_80 = local_30;
      pcVar9 = local_30;
      goto LAB_6813bf72;
    }
LAB_6813bd6c:
    dVar2 = (double)(int)local_64 * param_1 + 7.0;
    (*(unsigned int *)((char *)&local_2c + 4)) = (int)((ulonglong)dVar2 >> 0x20);
    pcVar5 = (char *)((*(unsigned int *)((char *)&local_2c + 4)) + -0x3400000);
    local_2c = (double)CONCAT44(pcVar5,SUB84(dVar2,0));
    if (local_94 != (char *)0x0) {
      if (local_38 != 0) {
        local_2c = 0.5 / *(double *)(&DAT_6817f220 + (int)local_94 * 8) - local_2c;
        local_20 = (char *)0x0;
        while( true ) {
          uVar11 = strings_floatToUint64(pcVar5,pcVar9);
          dVar2 = param_1 - (double)(int)uVar11;
          local_9c = (char)uVar11;
          *local_24 = local_9c + '0';
          local_24 = local_24 + 1;
          pcVar5 = local_24;
          if (dVar2 < local_2c) break;
          if (1.0 - dVar2 < local_2c) goto LAB_6813c07b;
          pcVar5 = local_20 + 1;
          local_20 = pcVar5;
          if ((int)local_94 <= (int)pcVar5) goto LAB_6813bf54;
          local_2c = local_2c * 10.0;
          param_1 = dVar2 * 10.0;
          pcVar9 = pcVar5;
        }
        goto LAB_6813c93c;
      }
      local_2c = local_2c * *(double *)(&DAT_6817f220 + (int)local_94 * 8);
      local_20 = (char *)0x1;
      while( true ) {
        uVar11 = strings_floatToUint64(pcVar5,pcVar9);
        dVar2 = param_1 - (double)(int)uVar11;
        local_9c = (char)uVar11;
        *local_24 = local_9c + '0';
        local_24 = local_24 + 1;
        if (local_20 == local_94) break;
        pcVar5 = local_20 + 1;
        param_1 = dVar2 * 10.0;
        pcVar9 = local_20;
        local_20 = pcVar5;
      }
      pcVar5 = local_24;
      if (dVar2 <= local_2c + 0.5) {
        if (dVar2 < 0.5 - local_2c) {
          do {
            pcVar9 = local_24 + -1;
            pcVar5 = local_24;
            local_24 = pcVar9;
          } while (*pcVar9 == '0');
          goto LAB_6813c93c;
        }
        goto LAB_6813bf54;
      }
      goto LAB_6813c07b;
    }
    local_18 = 0;
    local_34 = 0;
    if (param_1 - 5.0 <= local_2c) {
      iVar6 = local_34;
      if (param_1 - 5.0 < -local_2c) goto LAB_6813b857;
      goto LAB_6813bf54;
    }
LAB_6813c4e0:
    *local_24 = '1';
    local_24 = local_24 + 1;
    local_80 = local_80 + 1;
  }
LAB_6813c907:
  js_freePooledObject();
  pcVar5 = local_24;
  if (local_18 != 0) {
    if ((local_90 != 0) && (local_90 != local_18)) {
      js_freePooledObject();
    }
    js_freePooledObject();
    pcVar5 = local_24;
  }
LAB_6813c93c:
  local_24 = pcVar5;
  js_freePooledObject();
  *local_24 = '\0';
  if (param_7 != (undefined4 *)0x0) {
    *param_7 = local_24;
  }
  *param_5 = local_80 + 1;
  return 1;
}



