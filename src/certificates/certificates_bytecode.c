// Source: decompiled_functions.c
// Module: certificates
// Address range: 0x68155070 - 0x68155070
// Functions (1):
//   certificates_executeByteCode

// ============================================================
// Function: certificates_executeByteCode (FUN_68155070)
// Address: 68155070
// Size: 50265 bytes
// Return: undefined
// Calling convention: unknown
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int certificates_executeByteCode(ushort *param_1,uint *param_2)
{
  byte *pbVar1;
  byte *pbVar2;
  double dVar3;
  double dVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  undefined **ppuVar8;
  code *pcVar9;
  bool bVar10;
  byte bVar11;
  undefined3 extraout_var;
  uint uVar12;
  uint *puVar13;
  undefined3 extraout_var_00;
  undefined3 extraout_var_01;
  undefined4 *_Dst;
  undefined4 uVar14;
  undefined *puVar15;
  undefined3 extraout_var_02;
  int iVar16;
  uint uVar17;
  uint extraout_EDX;
  byte *pbVar18;
  ulonglong uVar19;
  undefined **local_65c;
  undefined **local_658;
  undefined **local_654;
  uint local_64c;
  uint local_648;
  uint local_644;
  uint local_640;
  uint local_63c;
  undefined **local_638;
  uint local_634;
  uint local_630;
  uint local_62c;
  undefined **local_628;
  uint local_624;
  undefined **local_620;
  uint local_61c;
  uint local_618;
  uint local_614;
  undefined **local_610;
  uint local_608;
  undefined **local_604;
  uint local_600;
  uint local_5fc;
  uint local_5f8;
  uint local_5f4;
  uint local_5f0;
  undefined **local_5ec;
  uint local_5e8;
  uint local_5e4;
  uint local_5e0;
  uint local_5dc;
  uint local_5d8;
  undefined **local_5d4;
  uint local_5d0;
  uint local_5cc;
  uint local_5c8;
  undefined **local_5c4;
  uint local_5c0;
  undefined **local_5bc;
  uint local_5b8;
  uint local_5b4;
  uint local_5b0;
  uint local_5ac;
  uint local_5a8;
  undefined **local_5a4;
  uint local_5a0;
  uint local_59c;
  uint local_598;
  undefined **local_594;
  uint local_57c;
  undefined **local_578;
  uint local_574;
  uint local_570;
  uint local_56c;
  uint local_568;
  uint local_548;
  undefined **local_544;
  uint local_540;
  uint local_53c;
  uint local_538;
  undefined **local_534;
  undefined4 *local_530;
  uint local_4e8;
  uint local_4e4;
  uint local_4d8;
  uint local_4d4;
  double local_4d0;
  double local_4c4;
  uint local_4b8;
  uint local_4b4;
  uint local_4a8;
  uint local_4a4;
  double local_4a0;
  double local_494;
  uint local_488;
  uint local_484;
  uint local_478;
  uint local_474;
  double local_470;
  double local_464;
  uint local_458;
  uint local_454;
  uint local_448;
  uint local_444;
  double local_440;
  double local_434;
  uint local_428;
  uint local_424;
  uint local_41c;
  uint local_418;
  uint local_410;
  uint local_40c;
  uint local_408;
  uint local_404;
  uint local_3fc;
  uint local_3f8;
  uint local_3f0;
  uint local_3ec;
  uint local_3e8;
  uint local_3e4;
  uint local_3dc;
  uint local_3d8;
  uint local_3d0;
  uint local_3cc;
  uint local_3c8;
  uint local_3c4;
  uint local_3bc;
  uint local_3b8;
  uint local_3b0;
  uint local_3ac;
  uint local_3a8;
  uint local_3a4;
  uint local_394;
  uint local_390;
  uint local_38c;
  uint local_388;
  uint local_378;
  uint local_374;
  uint local_364;
  undefined **local_360;
  uint local_35c;
  uint local_358;
  uint local_354;
  uint local_350;
  byte *local_338;
  int *local_334;
  undefined1 local_32c [12];
  code *local_320;
  undefined1 local_31c [12];
  undefined1 local_310 [12];
  uint local_300;
  uint local_2fc;
  uint local_2f8;
  uint local_2f4;
  undefined *local_2f0;
  undefined **local_2ec;
  uint *local_2e8;
  uint local_2e4;
  int local_2e0;
  uint *local_2dc;
  undefined4 *local_2d8;
  int local_2d4;
  undefined4 *local_2d0;
  int local_2cc;
  code *local_2c8;
  uint local_2c4;
  undefined **local_2c0;
  uint *local_2bc;
  uint local_2b8;
  int local_2b4;
  uint *local_2b0;
  undefined4 *local_2ac;
  undefined *local_2a8;
  undefined **local_2a4;
  uint *local_2a0;
  uint local_29c;
  int local_298;
  uint *local_294;
  undefined4 *local_290;
  undefined *local_28c;
  undefined *local_288;
  undefined **local_284;
  uint *local_280;
  uint local_27c;
  int local_278;
  uint *local_274;
  undefined4 *local_270;
  undefined **local_26c;
  uint *local_268;
  uint local_264;
  int local_260;
  uint *local_25c;
  undefined4 *local_258;
  undefined *local_254;
  undefined *local_250;
  undefined **local_24c;
  uint *local_248;
  uint local_244;
  int local_240;
  uint *local_23c;
  undefined4 *local_238;
  undefined **local_234;
  uint *local_230;
  uint local_22c;
  int local_228;
  uint *local_224;
  undefined4 *local_220;
  undefined *local_21c;
  undefined *local_218;
  undefined **local_214;
  uint *local_210;
  uint local_20c;
  int local_208;
  uint *local_204;
  undefined4 *local_200;
  uint local_1fc;
  int local_1f8;
  uint local_1f4;
  uint local_1f0;
  int local_1ec;
  uint local_1e8;
  uint local_1e4;
  int local_1e0;
  uint local_1dc;
  uint local_1d8;
  int local_1d4;
  uint local_1d0;
  uint local_1cc;
  uint local_1c8;
  int local_1c4;
  uint local_1c0;
  uint local_1bc;
  uint local_1b8;
  int local_1b4;
  uint local_1b0;
  uint local_1ac;
  uint local_1a8;
  int local_1a4;
  uint local_1a0;
  uint local_19c;
  uint local_198;
  int local_194;
  uint local_190;
  int local_18c;
  uint local_188;
  uint local_184;
  uint local_180;
  uint local_17c;
  uint local_178;
  int local_174;
  uint local_170;
  uint local_16c;
  uint local_168;
  int local_164;
  uint local_160;
  uint local_15c;
  uint local_158;
  int local_154;
  uint local_150;
  uint local_14c;
  uint local_148;
  int local_144;
  uint local_140;
  uint local_13c;
  uint local_138;
  int local_134;
  uint local_130;
  uint local_12c;
  undefined **local_128;
  uint *local_124;
  uint local_120;
  int local_11c;
  uint *local_118;
  undefined4 *local_114;
  undefined *local_110;
  int local_10c;
  ushort *local_108;
  code *local_104;
  int local_100;
  undefined4 *local_fc;
  int local_f8;
  uint local_f4;
  uint *local_f0;
  uint *local_ec;
  uint local_e8;
  uint local_e4;
  uint local_e0;
  uint local_dc;
  undefined **local_d8;
  int local_d4;
  uint *local_d0;
  undefined8 local_cc;
  int local_c4;
  int local_c0;
  uint *local_bc;
  uint local_b8;
  uint local_b4;
  uint *local_b0;
  undefined **local_ac;
  uint *local_a8;
  undefined4 *local_a4;
  int *local_a0;
  int local_9c;
  int *local_98;
  uint local_94;
  code *local_90;
  uint local_8c;
  undefined **local_88;
  int *local_84;
  undefined **local_80;
  undefined8 local_7c;
  undefined **local_74;
  uint local_70;
  byte *local_6c;
  undefined **local_68;
  uint local_64;
  undefined **local_60;
  int *local_5c;
  uint local_58;
  undefined4 *local_54;
  int local_50;
  uint local_4c;
  int local_48;
  undefined **local_44;
  int local_40;
  uint local_3c;
  uint *local_38;
  undefined **local_34;
  undefined **local_30;
  byte *local_2c;
  undefined4 *local_28;
  byte *local_24;
  byte *local_20;
  uint local_1c;
  uint local_18;
  int local_14;
  int local_10;
  uint local_c;
  uint local_8;
  
  local_e0 = (uint)(byte)param_1[0xb0];
  *param_2 = 0x80000001;
  local_9c = *(int *)(param_1 + 10);
  local_54 = *(undefined4 **)(param_1 + 0x1a);
  local_98 = (int *)local_54[3];
  local_50 = 0;
  local_10 = local_98[3];
  local_40 = *(int *)(param_1 + 6);
  if (local_10 != local_40) {
    xtra_setPlatformRef((int)param_1,local_10);
  }
  local_90 = *(code **)(param_1 + 0xa2);
  local_3c = 1;
  local_6c = (byte *)*local_98;
  local_20 = local_6c + local_98[1];
  local_8c = 0xffffffff;
  local_f8 = local_98[8];
  local_a4 = (undefined4 *)certs_checkConstraint((int)param_1,local_f8 << 1,&local_d4);
  if (local_a4 == (undefined4 *)0x0) {
    local_3c = 0;
  }
  else {
    local_38 = local_a4 + local_f8;
    local_54[0x10] = local_38;
    local_54[0xf] = local_38;
    bVar10 = js_isGCActive();
    if (CONCAT31(extraout_var,bVar10) == 0) goto LAB_681551bc;
    xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x1a);
    local_3c = 0;
  }
LAB_681612b1:
  do {
    if ((local_3c == 0) && ((char)param_1[0xad] != '\0')) {
      pcVar9 = *(code **)(local_9c + 0x228);
      if (pcVar9 == (code *)0x0) {
LAB_68161378:
        local_334 = (int *)local_98[10];
        local_338 = (byte *)0x0;
        if (local_334 != (int *)0x0) {
          for (; (byte *)local_334[1] <= local_6c + (-*local_334 - local_98[2]);
              local_334 = local_334 + 3) {
          }
          if (local_334[2] != 0) {
            local_338 = (byte *)(local_98[2] + local_334[2]);
          }
        }
        local_6c = local_338;
        if (local_338 != (byte *)0x0) {
          local_8c = 0;
          *(undefined1 *)(param_1 + 0xad) = 0;
          local_3c = 1;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        }
        if ((char)param_1[0xb0] == '\0') {
          runtime_isNaN((uint)param_1);
        }
      }
      else {
        local_54[0xf] = local_38;
        iVar16 = (*pcVar9)(param_1,local_98,local_6c,&local_34,*(undefined4 *)(local_9c + 0x22c));
        if (iVar16 == 0) {
          *(undefined1 *)(param_1 + 0xad) = 0;
        }
        else {
          if (iVar16 != 2) {
            if (iVar16 == 3) {
              *(undefined ***)(param_1 + 0xae) = local_34;
            }
            goto LAB_68161378;
          }
          local_3c = 1;
          *(undefined1 *)(param_1 + 0xad) = 0;
          local_54[8] = local_34;
        }
      }
    }
    if (local_50 == 0) {
      local_54[0xf] = local_54[0x10];
      local_54[0x10] = 0;
      certificates_resetStack((int)param_1,local_d4);
      if ((*(int *)(param_1 + 6) == local_10) && (local_10 != local_40)) {
        xtra_setPlatformRef((int)param_1,local_40);
      }
      *(int *)(param_1 + 4) = *(int *)(param_1 + 4) + -1;
      *(undefined1 *)(param_1 + 0xb0) = (undefined1)local_e0;
      return 0;
    }
LAB_681554bc:
    local_fc = local_54;
    local_100 = local_54[0x17];
    if ((local_100 != 0) &&
       (local_104 = *(code **)(*(int *)(param_1 + 10) + 0x218), local_104 != (code *)0x0)) {
      (*local_104)(param_1,local_54,0,&local_3c,local_100);
    }
    if (local_54[1] != 0) {
      uVar12 = runtime_initObjectProperties((uint)param_1,(int)local_54);
      local_3c = uVar12 & local_3c;
    }
    if ((*(int *)(param_1 + 6) == local_10) &&
       (local_10 = local_fc[0x18], local_10 != *(int *)(param_1 + 6))) {
      xtra_setPlatformRef((int)param_1,local_10);
    }
    local_b0 = (uint *)(local_54[7] + -8);
    *local_b0 = local_54[8];
    local_54 = (undefined4 *)local_54[0xb];
    *(undefined4 **)(param_1 + 0x1a) = local_54;
    local_10c = local_fc[0x16];
    local_108 = *(ushort **)(param_1 + 0x14);
    if ((local_108 == param_1 + 0xc) ||
       ((uint)(*(int *)(local_108 + 6) - *(int *)(local_108 + 2)) <
        (uint)(local_10c - *(int *)(local_108 + 2)))) {
      js_getPrototype((int *)(param_1 + 0xc),local_10c);
    }
    else {
      *(uint *)(local_108 + 6) = local_10c + *(int *)(param_1 + 0x18) & ~*(uint *)(param_1 + 0x18);
    }
    local_54[0xf] = local_b0 + 1;
    local_38 = (uint *)local_54[0xf];
    local_98 = (int *)local_54[3];
    local_f8 = local_98[8];
    local_6c = (byte *)local_54[0xe];
    local_20 = (byte *)(*local_98 + local_98[1]);
    local_b0[-local_f8] = (uint)local_6c;
    local_dc = (uint)*local_6c;
    local_60 = &PTR_DAT_68193cb0 + local_dc * 4;
    local_8c = (uint)(char)(&DAT_68193cb8)[local_dc * 0x10];
    local_50 = local_50 + -1;
joined_r0x681556b3:
    puVar13 = local_38;
    pbVar18 = local_24;
    if (local_3c != 0) {
switchD_6815fd70_default:
      local_24 = pbVar18;
      local_38 = puVar13;
      local_6c = local_6c + local_8c;
LAB_681551bc:
      if (local_6c < local_20) {
        local_54[0xe] = local_6c;
        local_dc = (uint)*local_6c;
LAB_681551dd:
        local_60 = &PTR_DAT_68193cb0 + local_dc * 4;
        local_8c = (uint)(char)(&DAT_68193cb8)[local_dc * 0x10];
        if (*(int *)(local_9c + 0x1e8) != 0) {
          local_54[0xf] = local_38;
          iVar16 = (**(code **)(local_9c + 0x1e8))
                             (param_1,local_98,local_6c,&local_34,*(undefined4 *)(local_9c + 0x1ec))
          ;
          if (iVar16 == 0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          if (iVar16 == 2) {
            local_54[8] = local_34;
            goto LAB_681612b1;
          }
          if (iVar16 == 3) {
            *(undefined1 *)(param_1 + 0xad) = 1;
            *(undefined ***)(param_1 + 0xae) = local_34;
            local_3c = 0;
            goto LAB_681612b1;
          }
        }
        puVar13 = local_38;
        pbVar18 = local_24;
        switch(local_dc) {
        case 0:
          goto switchD_6815fd70_default;
        case 1:
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = 0x80000001;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 2:
          *param_2 = local_38[-1];
          puVar13 = local_38 + -1;
          goto switchD_6815fd70_default;
        case 3:
          local_34 = (undefined **)local_38[-1];
          if ((((uint)local_34 & 7) == 0) && (local_34 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_34 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_34);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_5c = runtime_setProperty((int)param_1,&PTR_DAT_68192b48,local_d8,local_54[0xd]);
          if (local_5c == (int *)0x0) goto LAB_681612b1;
          local_54[0xd] = local_5c;
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = (uint)local_5c;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 4:
          local_5c = (int *)(local_38[-1] & 0xfffffff8);
          local_34 = *(undefined ***)(local_5c[1] + 4);
          local_54[0xd] = (uint)local_34 & 0xfffffff8;
          puVar13 = local_38 + -1;
          goto switchD_6815fd70_default;
        case 5:
          if (local_90 != (code *)0x0) {
            local_54[0xf] = local_38;
            local_3c = (*local_90)(param_1,local_98);
            if (local_3c == 0) goto LAB_681612b1;
          }
          local_38 = local_38 + -1;
          local_54[8] = *local_38;
          goto switchD_681552c9_caseD_99;
        case 6:
          goto switchD_681552c9_caseD_6;
        case 7:
          local_34 = (undefined **)local_38[-1];
          if (local_34 == (undefined **)0x0) {
            local_70 = 0;
          }
          else if (((uint)local_34 & 7) == 6) {
            local_70 = (int)local_34 >> 3;
          }
          else {
            local_54[0xf] = local_38;
            local_3c = js_getDateComponent((int)param_1,(uint)local_34,&local_70);
            if (local_3c == 0) goto LAB_681612b1;
          }
          local_38 = local_38 + -1;
          puVar13 = local_38;
          pbVar18 = local_24;
          if (((local_70 != 0) ||
              (local_8c = (uint)CONCAT11(local_6c[1],local_6c[2]), 0 < (int)local_8c)) ||
             (local_90 == (code *)0x0)) goto switchD_6815fd70_default;
          local_54[0xf] = local_38;
          local_3c = (*local_90)(param_1,local_98);
          goto joined_r0x681556b3;
        case 8:
          local_34 = (undefined **)local_38[-1];
          if (local_34 == (undefined **)0x0) {
            local_70 = 0;
          }
          else if (((uint)local_34 & 7) == 6) {
            local_70 = (int)local_34 >> 3;
          }
          else {
            local_54[0xf] = local_38;
            local_3c = js_getDateComponent((int)param_1,(uint)local_34,&local_70);
            if (local_3c == 0) goto LAB_681612b1;
          }
          local_38 = local_38 + -1;
          puVar13 = local_38;
          pbVar18 = local_24;
          if (((local_70 == 0) ||
              (local_8c = (uint)CONCAT11(local_6c[1],local_6c[2]), 0 < (int)local_8c)) ||
             (local_90 == (code *)0x0)) goto switchD_6815fd70_default;
          local_54[0xf] = local_38;
          local_3c = (*local_90)(param_1,local_98);
          goto joined_r0x681556b3;
        case 9:
          local_54[0xf] = local_38;
          local_3c = runtime_createObjectFromPrototype((int)param_1,local_54,&local_34);
          if (local_3c == 0) goto LAB_681612b1;
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_34;
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 10:
        case 0xb:
        case 0x6a:
          goto switchD_681552c9_caseD_a;
        case 0xc:
          local_34 = (undefined **)local_38[-1];
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_34;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0xd:
          local_88 = (undefined **)local_38[-2];
          local_34 = (undefined **)local_38[-1];
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_88;
          (local_38 + 1)[-local_f8] = (uint)local_6c;
          local_38[1] = (uint)local_34;
          puVar13 = local_38 + 2;
          goto switchD_6815fd70_default;
        case 0xe:
          local_d8 = (undefined **)local_54[2];
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_34 = (undefined **)local_38[-1];
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0xc))
                               (param_1,local_d8,local_f4,local_34,0,0,7,0);
          if (local_3c == 0) goto LAB_681612b1;
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = (uint)local_34;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0xf:
          local_12c = local_38[-1];
          if (((local_12c & 1) == 0) || (local_12c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_12c,&local_e8);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_e8 = (int)local_12c >> 1;
          }
          local_130 = local_38[-2];
          if (((local_130 & 1) == 0) || (local_130 == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_130,&local_2c);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_2c = (byte *)((int)local_130 >> 1);
          }
          if (local_3c == 0) goto LAB_681612b1;
          dVar3 = (double)(int)((uint)local_2c | local_e8);
          local_38 = local_38 + -1;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          uVar12 = (*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000;
          if ((uVar12 == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_68156c09:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_138);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64(local_38,uVar12);
            local_134 = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_134) || (0x7ffffffe < local_134 + 0x3fffffffU))
            goto LAB_68156c09;
            local_138 = local_134 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_138;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x10:
          local_13c = local_38[-1];
          if (((local_13c & 1) == 0) || (local_13c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_13c,&local_e8);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_e8 = (int)local_13c >> 1;
          }
          local_140 = local_38[-2];
          if (((local_140 & 1) == 0) || (local_140 == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_140,&local_2c);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_2c = (byte *)((int)local_140 >> 1);
          }
          if (local_3c == 0) goto LAB_681612b1;
          dVar3 = (double)(int)((uint)local_2c ^ local_e8);
          local_38 = local_38 + -1;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          if ((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_68156dcd:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_148);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64((uint)local_2c ^ local_e8,local_38);
            local_144 = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_144) || (0x7ffffffe < local_144 + 0x3fffffffU))
            goto LAB_68156dcd;
            local_148 = local_144 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_148;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x11:
          local_14c = local_38[-1];
          if (((local_14c & 1) == 0) || (local_14c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_14c,&local_e8);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_e8 = (int)local_14c >> 1;
          }
          local_150 = local_38[-2];
          if (((local_150 & 1) == 0) || (local_150 == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_150,&local_2c);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_2c = (byte *)((int)local_150 >> 1);
          }
          if (local_3c == 0) goto LAB_681612b1;
          dVar3 = (double)(int)((uint)local_2c & local_e8);
          local_38 = local_38 + -1;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          uVar12 = (*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000;
          if ((uVar12 == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_68156f93:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_158);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64(uVar12,(uint)local_2c & local_e8);
            local_154 = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_154) || (0x7ffffffe < local_154 + 0x3fffffffU))
            goto LAB_68156f93;
            local_158 = local_154 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_158;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x12:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          local_30 = (undefined **)((uint)local_88 & 7);
          local_ac = (undefined **)((uint)local_34 & 7);
          if (local_30 == local_ac) {
            if (local_30 == (undefined **)0x4) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(iVar16 == 0);
            }
            else if (local_30 == (undefined **)0x2) {
              dVar3 = *(double *)((uint)local_88 & 0xfffffff8);
              dVar4 = *(double *)((uint)local_34 & 0xfffffff8);
              (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc != 0 ||
                   (((ulonglong)dVar3 & 0xfffff00000000) != 0)))) ||
                 (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar4 >> 0x20),
                  ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar4,0), (int)local_7c != 0 ||
                   (((ulonglong)dVar4 & 0xfffff00000000) != 0)))))) {
                local_378 = 0;
              }
              else {
                local_374 = (uint)(dVar4 == dVar3);
                local_378 = local_374;
              }
              local_70 = local_378;
              local_cc = dVar3;
              local_7c = dVar4;
            }
            else {
              local_70 = (uint)(local_88 == local_34);
            }
          }
          else if ((local_88 == (undefined **)0x0) || (local_88 == (undefined **)0x80000001)) {
            if ((local_34 == (undefined **)0x0) || (local_34 == (undefined **)0x80000001)) {
              bVar11 = 1;
            }
            else {
              bVar11 = 0;
            }
            local_70 = (uint)bVar11;
          }
          else if ((local_34 == (undefined **)0x0) || (local_34 == (undefined **)0x80000001)) {
            local_70 = 0;
          }
          else {
            if (local_30 == (undefined **)0x0) {
              if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
                local_54[0xf] = local_38;
                local_3c = (**(code **)(*(int *)(*(int *)((uint)local_88 & 0xfffffff8) + 4) + 0x24))
                                     (param_1,(uint)local_88 & 0xfffffff8,0,&local_88);
                if (local_3c == 0) goto LAB_681612b1;
              }
              local_30 = (undefined **)((uint)local_88 & 7);
            }
            else if (local_ac == (undefined **)0x0) {
              if ((((uint)local_34 & 7) == 0) && (local_34 != (undefined **)0x0)) {
                local_54[0xf] = local_38;
                local_3c = (**(code **)(*(int *)(*(int *)((uint)local_34 & 0xfffffff8) + 4) + 0x24))
                                     (param_1,(uint)local_34 & 0xfffffff8,0,&local_34);
                if (local_3c == 0) goto LAB_681612b1;
              }
              local_ac = (undefined **)((uint)local_34 & 7);
            }
            if ((local_30 == (undefined **)0x4) && (local_ac == (undefined **)0x4)) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(iVar16 == 0);
            }
            else {
              if ((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) {
                if (((uint)local_88 & 7) == 2) {
                  local_cc = *(double *)((uint)local_88 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_88,(double *)&local_cc);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_cc = (double)((int)local_88 >> 1);
              }
              if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) {
                if (((uint)local_34 & 7) == 2) {
                  local_7c = *(double *)((uint)local_34 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_34,(double *)&local_7c);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_7c = (double)((int)local_34 >> 1);
              }
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((int)local_cc != 0 || (((ulonglong)local_cc & 0xfffff00000000) != 0)))) ||
                 ((((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((int)local_7c != 0 || (((ulonglong)local_7c & 0xfffff00000000) != 0)))))) {
                local_38c = 0;
              }
              else {
                local_388 = (uint)(local_7c == local_cc);
                local_38c = local_388;
              }
              local_70 = local_38c;
            }
          }
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = local_70 << 3 | 6;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x13:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          local_30 = (undefined **)((uint)local_88 & 7);
          local_ac = (undefined **)((uint)local_34 & 7);
          if (local_30 == local_ac) {
            if (local_30 == (undefined **)0x4) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(iVar16 != 0);
            }
            else if (local_30 == (undefined **)0x2) {
              dVar3 = *(double *)((uint)local_88 & 0xfffffff8);
              dVar4 = *(double *)((uint)local_34 & 0xfffffff8);
              (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc != 0 ||
                   (((ulonglong)dVar3 & 0xfffff00000000) != 0)))) ||
                 (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar4 >> 0x20),
                  ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar4,0), (int)local_7c != 0 ||
                   (((ulonglong)dVar4 & 0xfffff00000000) != 0)))))) {
                local_394 = 1;
              }
              else {
                local_390 = (uint)(dVar4 != dVar3);
                local_394 = local_390;
              }
              local_70 = local_394;
              local_cc = dVar3;
              local_7c = dVar4;
            }
            else {
              local_70 = (uint)(local_88 != local_34);
            }
          }
          else if ((local_88 == (undefined **)0x0) || (local_88 == (undefined **)0x80000001)) {
            if ((local_34 == (undefined **)0x0) || (local_34 == (undefined **)0x80000001)) {
              bVar10 = true;
            }
            else {
              bVar10 = false;
            }
            local_70 = (uint)!bVar10;
          }
          else if ((local_34 == (undefined **)0x0) || (local_34 == (undefined **)0x80000001)) {
            local_70 = 1;
          }
          else {
            if (local_30 == (undefined **)0x0) {
              if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
                local_54[0xf] = local_38;
                local_3c = (**(code **)(*(int *)(*(int *)((uint)local_88 & 0xfffffff8) + 4) + 0x24))
                                     (param_1,(uint)local_88 & 0xfffffff8,0,&local_88);
                if (local_3c == 0) goto LAB_681612b1;
              }
              local_30 = (undefined **)((uint)local_88 & 7);
            }
            else if (local_ac == (undefined **)0x0) {
              if ((((uint)local_34 & 7) == 0) && (local_34 != (undefined **)0x0)) {
                local_54[0xf] = local_38;
                local_3c = (**(code **)(*(int *)(*(int *)((uint)local_34 & 0xfffffff8) + 4) + 0x24))
                                     (param_1,(uint)local_34 & 0xfffffff8,0,&local_34);
                if (local_3c == 0) goto LAB_681612b1;
              }
              local_ac = (undefined **)((uint)local_34 & 7);
            }
            if ((local_30 == (undefined **)0x4) && (local_ac == (undefined **)0x4)) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(iVar16 != 0);
            }
            else {
              if ((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) {
                if (((uint)local_88 & 7) == 2) {
                  local_cc = *(double *)((uint)local_88 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_88,(double *)&local_cc);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_cc = (double)((int)local_88 >> 1);
              }
              if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) {
                if (((uint)local_34 & 7) == 2) {
                  local_7c = *(double *)((uint)local_34 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_34,(double *)&local_7c);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_7c = (double)((int)local_34 >> 1);
              }
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((int)local_cc != 0 || (((ulonglong)local_cc & 0xfffff00000000) != 0)))) ||
                 ((((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((int)local_7c != 0 || (((ulonglong)local_7c & 0xfffff00000000) != 0)))))) {
                local_3a8 = 1;
              }
              else {
                local_3a4 = (uint)(local_7c != local_cc);
                local_3a8 = local_3a4;
              }
              local_70 = local_3a8;
            }
          }
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = local_70 << 3 | 6;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x14:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          if (((uint)local_88 & (uint)local_34 & 1) == 0) {
            if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
              local_54[0xf] = local_38;
              local_3c = (**(code **)(*(int *)(*(int *)((uint)local_88 & 0xfffffff8) + 4) + 0x24))
                                   (param_1,(uint)local_88 & 0xfffffff8,4,&local_88);
              if (local_3c == 0) goto LAB_681612b1;
            }
            if ((((uint)local_34 & 7) == 0) && (local_34 != (undefined **)0x0)) {
              local_54[0xf] = local_38;
              local_3c = (**(code **)(*(int *)(*(int *)((uint)local_34 & 0xfffffff8) + 4) + 0x24))
                                   (param_1,(uint)local_34 & 0xfffffff8,4,&local_34);
              if (local_3c == 0) goto LAB_681612b1;
            }
            if ((((uint)local_88 & 7) == 4) && (((uint)local_34 & 7) == 4)) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(iVar16 < 0);
            }
            else {
              if ((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) {
                if (((uint)local_88 & 7) == 2) {
                  local_cc = *(double *)((uint)local_88 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_88,(double *)&local_cc);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_cc = (double)((int)local_88 >> 1);
              }
              if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) {
                if (((uint)local_34 & 7) == 2) {
                  local_7c = *(double *)((uint)local_34 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_34,(double *)&local_7c);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_7c = (double)((int)local_34 >> 1);
              }
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((int)local_cc != 0 || (((ulonglong)local_cc & 0xfffff00000000) != 0)))) ||
                 ((((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((int)local_7c != 0 || (((ulonglong)local_7c & 0xfffff00000000) != 0)))))) {
                local_458 = 0;
              }
              else {
                local_454 = (uint)(local_cc < local_7c);
                local_458 = local_454;
              }
              local_70 = local_458;
            }
          }
          else {
            local_30 = (undefined **)((uint)local_88 ^ 0x80000001);
            local_ac = (undefined **)((uint)local_34 ^ 0x80000001);
            if ((local_30 == (undefined **)0x0) || (local_ac == (undefined **)0x0)) {
              if (local_30 == (undefined **)0x0) {
                local_434 = **(double **)(local_9c + 0x1d0);
              }
              else {
                local_434 = (double)((int)local_88 >> 1);
              }
              local_cc = local_434;
              dVar3 = local_cc;
              if (local_ac == (undefined **)0x0) {
                local_440 = **(double **)(local_9c + 0x1d0);
              }
              else {
                local_440 = (double)((int)local_34 >> 1);
              }
              local_7c = local_440;
              dVar4 = local_7c;
              (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)local_434 >> 0x20);
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(local_434,0), (int)local_cc != 0 ||
                   (((ulonglong)local_434 & 0xfffff00000000) != 0)))) ||
                 (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)local_440 >> 0x20),
                  ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(local_440,0), (int)local_7c != 0 ||
                   (((ulonglong)local_440 & 0xfffff00000000) != 0)))))) {
                local_448 = 0;
              }
              else {
                local_444 = (uint)(local_434 < local_440);
                local_448 = local_444;
              }
              local_70 = local_448;
              local_cc = dVar3;
              local_7c = dVar4;
            }
            else {
              local_70 = (uint)((int)local_88 >> 1 < (int)local_34 >> 1);
            }
          }
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = local_70 << 3 | 6;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x15:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          if (((uint)local_88 & (uint)local_34 & 1) == 0) {
            if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
              local_54[0xf] = local_38;
              local_3c = (**(code **)(*(int *)(*(int *)((uint)local_88 & 0xfffffff8) + 4) + 0x24))
                                   (param_1,(uint)local_88 & 0xfffffff8,4,&local_88);
              if (local_3c == 0) goto LAB_681612b1;
            }
            if ((((uint)local_34 & 7) == 0) && (local_34 != (undefined **)0x0)) {
              local_54[0xf] = local_38;
              local_3c = (**(code **)(*(int *)(*(int *)((uint)local_34 & 0xfffffff8) + 4) + 0x24))
                                   (param_1,(uint)local_34 & 0xfffffff8,4,&local_34);
              if (local_3c == 0) goto LAB_681612b1;
            }
            if ((((uint)local_88 & 7) == 4) && (((uint)local_34 & 7) == 4)) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(iVar16 < 1);
            }
            else {
              if ((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) {
                if (((uint)local_88 & 7) == 2) {
                  local_cc = *(double *)((uint)local_88 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_88,(double *)&local_cc);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_cc = (double)((int)local_88 >> 1);
              }
              if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) {
                if (((uint)local_34 & 7) == 2) {
                  local_7c = *(double *)((uint)local_34 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_34,(double *)&local_7c);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_7c = (double)((int)local_34 >> 1);
              }
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((int)local_cc != 0 || (((ulonglong)local_cc & 0xfffff00000000) != 0)))) ||
                 ((((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((int)local_7c != 0 || (((ulonglong)local_7c & 0xfffff00000000) != 0)))))) {
                local_488 = 0;
              }
              else {
                local_484 = (uint)(local_cc <= local_7c);
                local_488 = local_484;
              }
              local_70 = local_488;
            }
          }
          else {
            local_30 = (undefined **)((uint)local_88 ^ 0x80000001);
            local_ac = (undefined **)((uint)local_34 ^ 0x80000001);
            if ((local_30 == (undefined **)0x0) || (local_ac == (undefined **)0x0)) {
              if (local_30 == (undefined **)0x0) {
                local_464 = **(double **)(local_9c + 0x1d0);
              }
              else {
                local_464 = (double)((int)local_88 >> 1);
              }
              local_cc = local_464;
              dVar3 = local_cc;
              if (local_ac == (undefined **)0x0) {
                local_470 = **(double **)(local_9c + 0x1d0);
              }
              else {
                local_470 = (double)((int)local_34 >> 1);
              }
              local_7c = local_470;
              dVar4 = local_7c;
              (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)local_464 >> 0x20);
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(local_464,0), (int)local_cc != 0 ||
                   (((ulonglong)local_464 & 0xfffff00000000) != 0)))) ||
                 (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)local_470 >> 0x20),
                  ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(local_470,0), (int)local_7c != 0 ||
                   (((ulonglong)local_470 & 0xfffff00000000) != 0)))))) {
                local_478 = 0;
              }
              else {
                local_474 = (uint)(local_464 <= local_470);
                local_478 = local_474;
              }
              local_70 = local_478;
              local_cc = dVar3;
              local_7c = dVar4;
            }
            else {
              local_70 = (uint)((int)local_88 >> 1 <= (int)local_34 >> 1);
            }
          }
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = local_70 << 3 | 6;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x16:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          if (((uint)local_88 & (uint)local_34 & 1) == 0) {
            if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
              local_54[0xf] = local_38;
              local_3c = (**(code **)(*(int *)(*(int *)((uint)local_88 & 0xfffffff8) + 4) + 0x24))
                                   (param_1,(uint)local_88 & 0xfffffff8,4,&local_88);
              if (local_3c == 0) goto LAB_681612b1;
            }
            if ((((uint)local_34 & 7) == 0) && (local_34 != (undefined **)0x0)) {
              local_54[0xf] = local_38;
              local_3c = (**(code **)(*(int *)(*(int *)((uint)local_34 & 0xfffffff8) + 4) + 0x24))
                                   (param_1,(uint)local_34 & 0xfffffff8,4,&local_34);
              if (local_3c == 0) goto LAB_681612b1;
            }
            if ((((uint)local_88 & 7) == 4) && (((uint)local_34 & 7) == 4)) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(0 < iVar16);
            }
            else {
              if ((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) {
                if (((uint)local_88 & 7) == 2) {
                  local_cc = *(double *)((uint)local_88 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_88,(double *)&local_cc);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_cc = (double)((int)local_88 >> 1);
              }
              if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) {
                if (((uint)local_34 & 7) == 2) {
                  local_7c = *(double *)((uint)local_34 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_34,(double *)&local_7c);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_7c = (double)((int)local_34 >> 1);
              }
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((int)local_cc != 0 || (((ulonglong)local_cc & 0xfffff00000000) != 0)))) ||
                 ((((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((int)local_7c != 0 || (((ulonglong)local_7c & 0xfffff00000000) != 0)))))) {
                local_4b8 = 0;
              }
              else {
                local_4b4 = (uint)(local_7c < local_cc);
                local_4b8 = local_4b4;
              }
              local_70 = local_4b8;
            }
          }
          else {
            local_30 = (undefined **)((uint)local_88 ^ 0x80000001);
            local_ac = (undefined **)((uint)local_34 ^ 0x80000001);
            if ((local_30 == (undefined **)0x0) || (local_ac == (undefined **)0x0)) {
              if (local_30 == (undefined **)0x0) {
                local_494 = **(double **)(local_9c + 0x1d0);
              }
              else {
                local_494 = (double)((int)local_88 >> 1);
              }
              local_cc = local_494;
              dVar3 = local_cc;
              if (local_ac == (undefined **)0x0) {
                local_4a0 = **(double **)(local_9c + 0x1d0);
              }
              else {
                local_4a0 = (double)((int)local_34 >> 1);
              }
              local_7c = local_4a0;
              dVar4 = local_7c;
              (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)local_494 >> 0x20);
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(local_494,0), (int)local_cc != 0 ||
                   (((ulonglong)local_494 & 0xfffff00000000) != 0)))) ||
                 (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)local_4a0 >> 0x20),
                  ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(local_4a0,0), (int)local_7c != 0 ||
                   (((ulonglong)local_4a0 & 0xfffff00000000) != 0)))))) {
                local_4a8 = 0;
              }
              else {
                local_4a4 = (uint)(local_4a0 < local_494);
                local_4a8 = local_4a4;
              }
              local_70 = local_4a8;
              local_cc = dVar3;
              local_7c = dVar4;
            }
            else {
              local_70 = (uint)((int)local_34 >> 1 < (int)local_88 >> 1);
            }
          }
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = local_70 << 3 | 6;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x17:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          if (((uint)local_88 & (uint)local_34 & 1) == 0) {
            if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
              local_54[0xf] = local_38;
              local_3c = (**(code **)(*(int *)(*(int *)((uint)local_88 & 0xfffffff8) + 4) + 0x24))
                                   (param_1,(uint)local_88 & 0xfffffff8,4,&local_88);
              if (local_3c == 0) goto LAB_681612b1;
            }
            if ((((uint)local_34 & 7) == 0) && (local_34 != (undefined **)0x0)) {
              local_54[0xf] = local_38;
              local_3c = (**(code **)(*(int *)(*(int *)((uint)local_34 & 0xfffffff8) + 4) + 0x24))
                                   (param_1,(uint)local_34 & 0xfffffff8,4,&local_34);
              if (local_3c == 0) goto LAB_681612b1;
            }
            if ((((uint)local_88 & 7) == 4) && (((uint)local_34 & 7) == 4)) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(-1 < iVar16);
            }
            else {
              if ((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) {
                if (((uint)local_88 & 7) == 2) {
                  local_cc = *(double *)((uint)local_88 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_88,(double *)&local_cc);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_cc = (double)((int)local_88 >> 1);
              }
              if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) {
                if (((uint)local_34 & 7) == 2) {
                  local_7c = *(double *)((uint)local_34 & 0xfffffff8);
                }
                else {
                  local_54[0xf] = local_38;
                  local_3c = runtime_parseNumber(param_1,(uint)local_34,(double *)&local_7c);
                  if (local_3c == 0) goto LAB_681612b1;
                }
              }
              else {
                local_7c = (double)((int)local_34 >> 1);
              }
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((int)local_cc != 0 || (((ulonglong)local_cc & 0xfffff00000000) != 0)))) ||
                 ((((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((int)local_7c != 0 || (((ulonglong)local_7c & 0xfffff00000000) != 0)))))) {
                local_4e8 = 0;
              }
              else {
                local_4e4 = (uint)(local_7c < local_cc != (local_7c == local_cc));
                local_4e8 = local_4e4;
              }
              local_70 = local_4e8;
            }
          }
          else {
            local_30 = (undefined **)((uint)local_88 ^ 0x80000001);
            local_ac = (undefined **)((uint)local_34 ^ 0x80000001);
            if ((local_30 == (undefined **)0x0) || (local_ac == (undefined **)0x0)) {
              if (local_30 == (undefined **)0x0) {
                local_4c4 = **(double **)(local_9c + 0x1d0);
              }
              else {
                local_4c4 = (double)((int)local_88 >> 1);
              }
              local_cc = local_4c4;
              dVar3 = local_cc;
              if (local_ac == (undefined **)0x0) {
                local_4d0 = **(double **)(local_9c + 0x1d0);
              }
              else {
                local_4d0 = (double)((int)local_34 >> 1);
              }
              local_7c = local_4d0;
              dVar4 = local_7c;
              (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)local_4c4 >> 0x20);
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(local_4c4,0), (int)local_cc != 0 ||
                   (((ulonglong)local_4c4 & 0xfffff00000000) != 0)))) ||
                 (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)local_4d0 >> 0x20),
                  ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(local_4d0,0), (int)local_7c != 0 ||
                   (((ulonglong)local_4d0 & 0xfffff00000000) != 0)))))) {
                local_4d8 = 0;
              }
              else {
                local_4d4 = (uint)(local_4d0 < local_4c4 != (local_4d0 == local_4c4));
                local_4d8 = local_4d4;
              }
              local_70 = local_4d8;
              local_cc = dVar3;
              local_7c = dVar4;
            }
            else {
              local_70 = (uint)((int)local_34 >> 1 <= (int)local_88 >> 1);
            }
          }
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = local_70 << 3 | 6;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x18:
          local_15c = local_38[-1];
          if (((local_15c & 1) == 0) || (local_15c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_15c,&local_e8);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_e8 = (int)local_15c >> 1;
          }
          local_160 = local_38[-2];
          if (((local_160 & 1) == 0) || (local_160 == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_160,&local_2c);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_2c = (byte *)((int)local_160 >> 1);
          }
          if (local_3c == 0) goto LAB_681612b1;
          local_e8 = local_e8 & 0x1f;
          iVar16 = (int)local_2c << (sbyte)local_e8;
          dVar3 = (double)iVar16;
          local_38 = local_38 + -1;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          uVar12 = (*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000;
          if ((uVar12 == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_68159a9a:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_168);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64(uVar12,iVar16);
            local_164 = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_164) || (0x7ffffffe < local_164 + 0x3fffffffU))
            goto LAB_68159a9a;
            local_168 = local_164 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_168;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x19:
          local_16c = local_38[-1];
          if (((local_16c & 1) == 0) || (local_16c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_16c,&local_e8);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_e8 = (int)local_16c >> 1;
          }
          local_170 = local_38[-2];
          if (((local_170 & 1) == 0) || (local_170 == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_170,&local_2c);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_2c = (byte *)((int)local_170 >> 1);
          }
          if (local_3c == 0) goto LAB_681612b1;
          local_e8 = local_e8 & 0x1f;
          iVar16 = (int)local_2c >> (sbyte)local_e8;
          dVar3 = (double)iVar16;
          local_38 = local_38 + -1;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          uVar12 = (*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000;
          if ((uVar12 == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_68159c71:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_178);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64(uVar12,iVar16);
            local_174 = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_174) || (0x7ffffffe < local_174 + 0x3fffffffU))
            goto LAB_68159c71;
            local_178 = local_174 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_178;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x1a:
          local_180 = local_38[-1];
          if (((local_180 & 1) == 0) || (local_180 == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_180,&local_e8);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_e8 = (int)local_180 >> 1;
          }
          local_188 = local_38[-2];
          if ((((local_188 & 1) == 0) || (local_188 == 0x80000001)) ||
             (local_184 = (int)local_188 >> 1, uVar12 = local_184, (int)local_184 < 0)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseFloat(param_1,local_188,&local_17c);
            uVar12 = local_17c;
            if (local_3c == 0) goto LAB_681612b1;
          }
          local_17c = uVar12;
          local_e8 = local_e8 & 0x1f;
          uVar17 = local_17c >> (sbyte)local_e8;
          dVar3 = (double)uVar17;
          local_38 = local_38 + -1;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          uVar12 = (*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000;
          if ((uVar12 == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_68159e5e:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_190);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64(uVar12,uVar17);
            local_18c = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_18c) || (0x7ffffffe < local_18c + 0x3fffffffU))
            goto LAB_68159e5e;
            local_190 = local_18c << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_190;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x1b:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          ppuVar8 = local_88;
          if ((((uint)local_88 & 7) == 0) && (ppuVar8 = local_88, local_88 != (undefined **)0x0)) {
            local_54[0xf] = local_38;
            local_3c = (**(code **)(*(int *)(*(int *)((uint)local_88 & 0xfffffff8) + 4) + 0x24))
                                 (param_1,(uint)local_88 & 0xfffffff8,0,&local_30);
            ppuVar8 = local_30;
            if (local_3c == 0) goto LAB_681612b1;
          }
          local_30 = ppuVar8;
          if ((((uint)local_34 & 7) == 0) && (local_34 != (undefined **)0x0)) {
            local_54[0xf] = local_38;
            local_3c = (**(code **)(*(int *)(*(int *)((uint)local_34 & 0xfffffff8) + 4) + 0x24))
                                 (param_1,(uint)local_34 & 0xfffffff8,0,&local_ac);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_ac = local_34;
          }
          local_70 = (uint)(((uint)local_30 & 7) == 4);
          if ((local_70 != 0) || (((uint)local_ac & 7) == 4)) {
            if (local_70 == 0) {
              local_bc = (uint *)((uint)local_ac & 0xfffffff8);
              local_54[0xf] = local_38;
              local_ec = (uint *)certs_hashLookup((int)param_1,(uint)local_30);
              puVar13 = local_ec;
            }
            else {
              local_ec = (uint *)((uint)local_30 & 0xfffffff8);
              local_54[0xf] = local_38;
              local_bc = (uint *)certs_hashLookup((int)param_1,(uint)local_ac);
              puVar13 = local_bc;
            }
            local_3c = (uint)(puVar13 != (uint *)0x0);
            if (local_3c == 0) goto LAB_681612b1;
            local_ec = crypto_concatStrings((int)param_1,local_ec,local_bc);
            if (local_ec == (uint *)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
            (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
            local_38[-2] = (uint)local_ec | 4;
            puVar13 = local_38 + -1;
            pbVar18 = local_24;
            goto switchD_6815fd70_default;
          }
          if ((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) {
            if (((uint)local_88 & 7) == 2) {
              local_cc = *(double *)((uint)local_88 & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,(uint)local_88,(double *)&local_cc);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_cc = (double)((int)local_88 >> 1);
          }
          if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) {
            if (((uint)local_34 & 7) == 2) {
              local_7c = *(double *)((uint)local_34 & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,(uint)local_34,(double *)&local_7c);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_7c = (double)((int)local_34 >> 1);
          }
          dVar3 = local_cc + local_7c;
          local_38 = local_38 + -1;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          uVar12 = (*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000;
          if ((uVar12 == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_6815a215:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_198);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64(uVar12,0);
            local_194 = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_194) || (0x7ffffffe < local_194 + 0x3fffffffU))
            goto LAB_6815a215;
            local_198 = local_194 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_198;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x1c:
          local_19c = local_38[-1];
          if (((local_19c & 1) == 0) || (local_19c == 0x80000001)) {
            if ((local_19c & 7) == 2) {
              local_7c = *(double *)(local_19c & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,local_19c,(double *)&local_7c);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_7c = (double)((int)local_19c >> 1);
          }
          local_1a0 = local_38[-2];
          if (((local_1a0 & 1) == 0) || (local_1a0 == 0x80000001)) {
            if ((local_1a0 & 7) == 2) {
              local_cc = *(double *)(local_1a0 & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,local_1a0,(double *)&local_cc);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_cc = (double)((int)local_1a0 >> 1);
          }
          dVar3 = local_cc - local_7c;
          local_38 = local_38 + -1;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          if ((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_6815a425:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_1a8);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64(0,local_38);
            local_1a4 = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_1a4) || (0x7ffffffe < local_1a4 + 0x3fffffffU))
            goto LAB_6815a425;
            local_1a8 = local_1a4 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_1a8;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x1d:
          local_1ac = local_38[-1];
          if (((local_1ac & 1) == 0) || (local_1ac == 0x80000001)) {
            if ((local_1ac & 7) == 2) {
              local_7c = *(double *)(local_1ac & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,local_1ac,(double *)&local_7c);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_7c = (double)((int)local_1ac >> 1);
          }
          local_1b0 = local_38[-2];
          if (((local_1b0 & 1) == 0) || (local_1b0 == 0x80000001)) {
            if ((local_1b0 & 7) == 2) {
              local_cc = *(double *)(local_1b0 & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,local_1b0,(double *)&local_cc);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_cc = (double)((int)local_1b0 >> 1);
          }
          dVar3 = local_cc * local_7c;
          local_38 = local_38 + -1;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          if ((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_6815a63d:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_1b8);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64(0,local_38);
            local_1b4 = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_1b4) || (0x7ffffffe < local_1b4 + 0x3fffffffU))
            goto LAB_6815a63d;
            local_1b8 = local_1b4 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_1b8;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x1e:
          local_1bc = local_38[-1];
          if (((local_1bc & 1) == 0) || (local_1bc == 0x80000001)) {
            if ((local_1bc & 7) == 2) {
              local_7c = *(double *)(local_1bc & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,local_1bc,(double *)&local_7c);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_7c = (double)((int)local_1bc >> 1);
          }
          local_1c0 = local_38[-2];
          if (((local_1c0 & 1) == 0) || (local_1c0 == 0x80000001)) {
            if ((local_1c0 & 7) == 2) {
              local_cc = *(double *)(local_1c0 & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,local_1c0,(double *)&local_cc);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_cc = (double)((int)local_1c0 >> 1);
          }
          puVar13 = local_38 + -1;
          if (local_7c == 0.0) {
            if ((((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000) &&
               (((int)local_7c != 0 || (((ulonglong)local_7c & 0xfffff00000000) != 0)))) {
              local_34 = (undefined **)(*(uint *)(local_9c + 0x1d0) | 2);
            }
            else if ((local_cc == 0.0) ||
                    ((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000 &&
                     (((int)local_cc != 0 || (((ulonglong)local_cc & 0xfffff00000000) != 0)))))) {
              local_34 = (undefined **)(*(uint *)(local_9c + 0x1d0) | 2);
            }
            else if ((int)((*(unsigned int *)((char *)&local_cc + 4)) ^ (*(unsigned int *)((char *)&local_7c + 4))) < 0) {
              local_34 = (undefined **)(*(uint *)(local_9c + 0x1d4) | 2);
            }
            else {
              local_34 = (undefined **)(*(uint *)(local_9c + 0x1d8) | 2);
            }
            puVar13[-1 - local_f8] = (uint)local_6c;
            local_38[-2] = (uint)local_34;
            pbVar18 = local_24;
          }
          else {
            dVar3 = local_cc / local_7c;
            (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
            local_38 = puVar13;
            if ((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) ||
               (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 &&
                ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)))) {
LAB_6815a944:
              local_cc = dVar3;
              local_3c = runtime_formatNumber((int)param_1,local_cc,&local_1c8);
              if (local_3c == 0) goto LAB_681612b1;
            }
            else {
              local_cc = dVar3;
              uVar19 = strings_floatToUint64(0,puVar13);
              local_1c4 = (int)uVar19;
              dVar3 = local_cc;
              if ((local_cc != (double)local_1c4) || (0x7ffffffe < local_1c4 + 0x3fffffffU))
              goto LAB_6815a944;
              local_1c8 = local_1c4 << 1 | 1;
            }
            local_38[-1 - local_f8] = (uint)local_6c;
            local_38[-1] = local_1c8;
            puVar13 = local_38;
            pbVar18 = local_24;
          }
          goto switchD_6815fd70_default;
        case 0x1f:
          local_1cc = local_38[-1];
          if (((local_1cc & 1) == 0) || (local_1cc == 0x80000001)) {
            if ((local_1cc & 7) == 2) {
              local_7c = *(double *)(local_1cc & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,local_1cc,(double *)&local_7c);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_7c = (double)((int)local_1cc >> 1);
          }
          local_1d0 = local_38[-2];
          if (((local_1d0 & 1) == 0) || (local_1d0 == 0x80000001)) {
            if ((local_1d0 & 7) == 2) {
              local_cc = *(double *)(local_1d0 & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,local_1d0,(double *)&local_cc);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_cc = (double)((int)local_1d0 >> 1);
          }
          puVar13 = local_38 + -1;
          if (local_7c == 0.0) {
            puVar13[-1 - local_f8] = (uint)local_6c;
            local_38[-2] = *(uint *)(local_9c + 0x1d0) | 2;
            pbVar18 = local_24;
            goto switchD_6815fd70_default;
          }
          uVar12 = (*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000;
          local_38 = puVar13;
          if (((uVar12 == 0x7ff00000) || (((*(unsigned int *)((char *)&local_7c + 4)) & 0x7fffffff) != 0x7ff00000)) ||
             ((int)local_7c != 0)) {
            local_cc = fmod(local_cc,local_7c);
            uVar12 = extraout_EDX;
          }
          if ((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((int)local_cc == 0)))) {
LAB_6815abcd:
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_1d8);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            uVar19 = strings_floatToUint64((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000,uVar12);
            local_1d4 = (int)uVar19;
            if ((local_cc != (double)local_1d4) || (0x7ffffffe < local_1d4 + 0x3fffffffU))
            goto LAB_6815abcd;
            local_1d8 = local_1d4 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_1d8;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x20:
          local_34 = (undefined **)local_38[-1];
          if (local_34 == (undefined **)0x0) {
            local_70 = 0;
          }
          else if (((uint)local_34 & 7) == 6) {
            local_70 = (int)local_34 >> 3;
          }
          else {
            local_54[0xf] = local_38;
            local_3c = js_getDateComponent((int)param_1,(uint)local_34,&local_70);
            if (local_3c == 0) goto LAB_681612b1;
          }
          (local_38 + -1)[-local_f8] = (uint)local_6c;
          local_38[-1] = (uint)(local_70 == 0) << 3 | 6;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x21:
          local_1dc = local_38[-1];
          if (((local_1dc & 1) == 0) || (local_1dc == 0x80000001)) {
            local_54[0xf] = local_38;
            local_3c = runtime_parseInt(param_1,local_1dc,&local_2c);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_2c = (byte *)((int)local_1dc >> 1);
          }
          dVar3 = (double)(int)~(uint)local_2c;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          uVar12 = (*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000;
          if ((uVar12 == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_6815ada4:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_1e4);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64(uVar12,0);
            local_1e0 = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_1e0) || (0x7ffffffe < local_1e0 + 0x3fffffffU))
            goto LAB_6815ada4;
            local_1e4 = local_1e0 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_1e4;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x22:
          local_1e8 = local_38[-1];
          if (((local_1e8 & 1) == 0) || (local_1e8 == 0x80000001)) {
            if ((local_1e8 & 7) == 2) {
              local_cc = *(double *)(local_1e8 & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,local_1e8,(double *)&local_cc);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_cc = (double)((int)local_1e8 >> 1);
          }
          dVar3 = -local_cc;
          (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
          uVar12 = (*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000;
          if ((uVar12 == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc == 0)
              ))) {
LAB_6815af1b:
            local_cc = dVar3;
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_1f0);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            local_cc = dVar3;
            uVar19 = strings_floatToUint64(uVar12,0);
            local_1ec = (int)uVar19;
            dVar3 = local_cc;
            if ((local_cc != (double)local_1ec) || (0x7ffffffe < local_1ec + 0x3fffffffU))
            goto LAB_6815af1b;
            local_1f0 = local_1ec << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_1f0;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x23:
          local_1c = (uint)CONCAT11(local_6c[1],local_6c[2]);
          goto LAB_6815b0ef;
        case 0x24:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_54[0xf] = local_38;
          local_c = local_f4;
          local_3c = runtime_setPropertyEx((int)param_1,local_f4,&local_d8,&local_44,(uint *)&local_f0);
          if (local_3c == 0) goto LAB_681612b1;
          local_34 = (undefined **)0xe;
          if (local_f0 != (uint *)0x0) {
            if (*(int *)(*(int *)(*local_44 + 4) + 0x34) != 0) {
              (**(code **)(*(int *)(*local_44 + 4) + 0x34))(param_1,local_44,local_f0);
            }
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x20))
                                 (param_1,local_d8,local_c,&local_34);
            if (local_3c == 0) goto LAB_681612b1;
          }
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_34;
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x25:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_88 = (undefined **)local_38[-1];
          local_c = local_f4;
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_54[0xf] = local_38;
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x20))
                               (param_1,local_d8,local_c,&local_34);
          if (local_3c == 0) goto LAB_681612b1;
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = (uint)local_34;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x26:
          local_c = local_38[-1];
          if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_f4 = js_resolveAtom((int)param_1,local_c);
            uVar12 = local_f4;
            if (local_f4 == 0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          else {
            local_f4 = 0;
            uVar12 = local_c;
          }
          local_c = uVar12;
          local_88 = (undefined **)local_38[-2];
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_54[0xf] = local_38;
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x20))
                               (param_1,local_d8,local_c,&local_34);
          if (local_3c == 0) goto LAB_681612b1;
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = (uint)local_34;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x27:
          local_38 = local_38 + -1;
          local_34 = (undefined **)*local_38;
          bVar11 = xtra_lookupHashByte(param_1,(uint)local_34);
          local_48 = CONCAT31(extraout_var_00,bVar11);
          local_f4 = *(uint *)(local_9c + 0x7c + local_48 * 4);
          local_ec = (uint *)(*(uint *)(local_f4 + 8) & 0xfffffff8);
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_ec | 4;
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x28:
          (local_38 + -1)[-local_f8] = (uint)local_6c;
          local_38[-1] = 0x80000001;
          goto switchD_6815fd70_default;
        case 0x29:
        case 0x2c:
        case 0x2f:
        case 0x32:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_54[0xf] = local_38;
          local_c = local_f4;
          local_3c = runtime_setPropertyEx((int)param_1,local_f4,&local_d8,&local_44,(uint *)&local_f0);
          if (local_3c != 0) {
            if (local_f0 != (uint *)0x0) {
              if (*(int *)(*(int *)(*local_44 + 4) + 0x34) != 0) {
                (**(code **)(*(int *)(*local_44 + 4) + 0x34))(param_1,local_44,local_f0);
              }
              local_88 = local_d8;
              goto LAB_6815b8fb;
            }
            puVar15 = xtra_getStringValue((uint *)(*(uint *)(local_f4 + 8) & 0xfffffff8));
            runtime_addBreakpoint(param_1,puVar15);
            local_3c = 0;
          }
          goto LAB_681612b1;
        case 0x2a:
        case 0x2d:
        case 0x30:
        case 0x33:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_38 = local_38 + -1;
          local_88 = (undefined **)*local_38;
          local_c = local_f4;
          goto LAB_6815b8fb;
        case 0x2b:
        case 0x2e:
        case 0x31:
        case 0x34:
          local_c = local_38[-1];
          if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_f4 = js_resolveAtom((int)param_1,local_c);
            uVar12 = local_f4;
            if (local_f4 == 0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          else {
            local_f4 = 0;
            uVar12 = local_c;
          }
          local_c = uVar12;
          local_38 = local_38 + -2;
          local_88 = (undefined **)*local_38;
LAB_6815b8fb:
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_54[0xf] = local_38;
          if ((*(undefined ***)(*local_d8 + 4) == &PTR_FUN_68192948) ||
             ((*(int *)(*local_d8 + 4) != 0 &&
              ((undefined *)**(int **)(*local_d8 + 4) == PTR_FUN_68192948)))) {
            local_20c = ((uint)local_d8 >> 3 ^ local_c) & 0x3ff;
            local_208 = local_9c + 0x248;
            local_200 = (undefined4 *)(local_208 + local_20c * 8);
            local_214 = (undefined **)*local_200;
            local_210 = (uint *)local_200[1];
            if ((local_210 == (uint *)0x0) ||
               ((local_214 != local_d8 || (local_a8 = local_210, *local_210 != local_c)))) {
              local_a8 = (uint *)0x0;
            }
            local_204 = local_210;
            if (local_a8 == (uint *)0x0) {
              local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x10))
                                   (param_1,local_d8,local_c,&local_34);
            }
            else {
              local_218 = *local_d8;
              local_b4 = local_a8[3];
              if (local_b4 == 0xffffffff) {
                local_534 = (undefined **)0x80000001;
              }
              else {
                local_534 = *(undefined ***)(local_d8[1] + local_b4 * 4);
              }
              local_34 = local_534;
              if ((local_a8[4] & 0x10) == 0) {
                if (local_a8[1] == 0) {
LAB_6815bbee:
                  local_548 = 1;
                }
                else {
                  if ((*(byte *)((int)local_a8 + 0x11) & 8) == 0) {
                    if ((*local_a8 & 1) == 0) {
                      local_540 = *(uint *)(*local_a8 + 8);
                    }
                    else {
                      local_540 = *local_a8;
                    }
                    local_53c = local_540;
                  }
                  else {
                    local_53c = (int)*(short *)((int)local_a8 + 0x12) << 1 | 1;
                  }
                  if (*(int *)(*(int *)(*local_d8 + 4) + 0x30) == 0) {
                    local_544 = local_d8;
                  }
                  else {
                    local_544 = (undefined **)
                                (**(code **)(*(int *)(*local_d8 + 4) + 0x30))(param_1,local_d8);
                  }
                  iVar16 = (*(code *)local_a8[1])(param_1,local_544,local_53c,&local_34);
                  if (iVar16 != 0) goto LAB_6815bbee;
                  local_548 = 0;
                }
                local_538 = local_548;
              }
              else {
                local_538 = certs_processKeyUsage((int)param_1,local_d8,*local_a8,local_a8[1],4,0,0,&local_34
                                        );
              }
              local_3c = local_538;
              if ((local_538 != 0) && (local_a8[3] < *(uint *)(local_218 + 0xc))) {
                *(undefined ***)(local_d8[1] + local_b4 * 4) = local_34;
              }
            }
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x10))
                                 (param_1,local_d8,local_c,&local_34);
          }
          if (local_3c == 0) goto LAB_681612b1;
          if ((((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) ||
              (local_34 == (undefined **)0x80000003)) || (local_34 == (undefined **)0x7fffffff)) {
            if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) {
              if (((uint)local_34 & 7) == 2) {
                local_cc = *(double *)((uint)local_34 & 0xfffffff8);
              }
              else {
                local_54[0xf] = local_38;
                local_3c = runtime_parseNumber(param_1,(uint)local_34,(double *)&local_cc);
                if (local_3c == 0) {
                  local_3c = 0;
                  goto LAB_681612b1;
                }
              }
            }
            else {
              local_cc = (double)((int)local_34 >> 1);
            }
            if (((uint)local_60[3] & 0x400) == 0) {
              if (((uint)local_60[3] & 0x200) == 0) {
                local_cc = local_cc - 1.0;
              }
              else {
                local_cc = local_cc + 1.0;
              }
              local_3c = runtime_convertToNumber(param_1,(uint)local_60[3] & 0x200,(int)param_1,
                                      SUB84(local_cc,0),(uint)((ulonglong)local_cc >> 0x20),
                                      (uint *)&local_34);
              local_ac = local_34;
            }
            else {
              local_ac = local_34;
              if (((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) &&
                 ((((uint)local_34 & 7) != 2 &&
                  (local_3c = runtime_convertToNumber(&local_ac,param_1,(int)param_1,SUB84(local_cc,0),
                                           (uint)((ulonglong)local_cc >> 0x20),(uint *)&local_ac),
                  local_3c == 0)))) {
                local_3c = 0;
                goto LAB_681612b1;
              }
              if (((uint)local_60[3] & 0x200) == 0) {
                local_cc = local_cc - 1.0;
              }
              else {
                local_cc = local_cc + 1.0;
              }
              local_3c = runtime_convertToNumber((uint)local_60[3] & 0x200,&local_34,(int)param_1,
                                      SUB84(local_cc,0),(uint)((ulonglong)local_cc >> 0x20),
                                      (uint *)&local_34);
            }
            if (local_3c == 0) goto LAB_681612b1;
          }
          else if (((uint)local_60[3] & 0x400) == 0) {
            if (((uint)local_60[3] & 0x200) == 0) {
              local_34 = (undefined **)((int)local_34 - 2);
            }
            else {
              local_34 = (undefined **)((int)local_34 + 2);
            }
            local_ac = local_34;
          }
          else {
            local_ac = local_34;
            if (((uint)local_60[3] & 0x200) == 0) {
              local_34 = (undefined **)((int)local_34 - 2);
            }
            else {
              local_34 = (undefined **)((int)local_34 + 2);
            }
          }
          if ((*(undefined ***)(*local_d8 + 4) == &PTR_FUN_68192948) ||
             ((*(int *)(*local_d8 + 4) != 0 &&
              ((undefined *)**(int **)(*local_d8 + 4) == PTR_FUN_68192948)))) {
            local_22c = ((uint)local_d8 >> 3 ^ local_c) & 0x3ff;
            local_228 = local_9c + 0x248;
            local_220 = (undefined4 *)(local_228 + local_22c * 8);
            local_234 = (undefined **)*local_220;
            local_230 = (uint *)local_220[1];
            if ((local_230 == (uint *)0x0) ||
               ((local_234 != local_d8 || (local_a8 = local_230, *local_230 != local_c)))) {
              local_a8 = (uint *)0x0;
            }
            local_224 = local_230;
            if (((local_a8 == (uint *)0x0) || ((local_a8[4] & 2) != 0)) ||
               (local_21c = *local_d8, (*(ushort *)(local_21c + 0x14) & 2) != 0)) {
              local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))
                                   (param_1,local_d8,local_c,&local_34);
            }
            else {
              if ((local_a8[4] & 0x20) == 0) {
                if ((local_a8[4] & 0x10) == 0) {
                  if (local_a8[2] == 0) {
LAB_6815c1ab:
                    local_57c = 1;
                  }
                  else {
                    if ((*(byte *)((int)local_a8 + 0x11) & 8) == 0) {
                      if ((*local_a8 & 1) == 0) {
                        local_574 = *(uint *)(*local_a8 + 8);
                      }
                      else {
                        local_574 = *local_a8;
                      }
                      local_570 = local_574;
                    }
                    else {
                      local_570 = (int)*(short *)((int)local_a8 + 0x12) << 1 | 1;
                    }
                    if (*(int *)(*(int *)(*local_d8 + 4) + 0x30) == 0) {
                      local_578 = local_d8;
                    }
                    else {
                      local_578 = (undefined **)
                                  (**(code **)(*(int *)(*local_d8 + 4) + 0x30))(param_1,local_d8);
                    }
                    iVar16 = (*(code *)local_a8[2])(param_1,local_578,local_570,&local_34);
                    if (iVar16 != 0) goto LAB_6815c1ab;
                    local_57c = 0;
                  }
                  local_56c = local_57c;
                }
                else {
                  xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0xa0);
                  local_56c = 0;
                }
                local_568 = local_56c;
              }
              else {
                local_568 = certs_processKeyUsage((int)param_1,local_d8,*local_a8,local_a8[2],8,1,&local_34,
                                         &local_34);
              }
              local_3c = local_568;
              if ((local_568 != 0) && (local_a8[3] < *(uint *)(local_21c + 0xc))) {
                *(undefined ***)(local_d8[1] + local_a8[3] * 4) = local_34;
                *(undefined1 *)(*(int *)(param_1 + 10) + 0x60) = 1;
              }
            }
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))
                                 (param_1,local_d8,local_c,&local_34);
          }
          if (local_3c == 0) goto LAB_681612b1;
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_ac;
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x35:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_88 = (undefined **)local_38[-1];
          local_c = local_f4;
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_54[0xf] = local_38;
          if ((*(undefined ***)(*local_d8 + 4) == &PTR_FUN_68192948) ||
             ((*(int *)(*local_d8 + 4) != 0 &&
              ((undefined *)**(int **)(*local_d8 + 4) == PTR_FUN_68192948)))) {
            local_244 = ((uint)local_d8 >> 3 ^ local_c) & 0x3ff;
            local_240 = local_9c + 0x248;
            local_238 = (undefined4 *)(local_240 + local_244 * 8);
            local_24c = (undefined **)*local_238;
            local_248 = (uint *)local_238[1];
            if ((local_248 == (uint *)0x0) ||
               ((local_24c != local_d8 || (local_a8 = local_248, *local_248 != local_c)))) {
              local_a8 = (uint *)0x0;
            }
            local_23c = local_248;
            if (local_a8 == (uint *)0x0) {
              local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x10))
                                   (param_1,local_d8,local_c,&local_34);
            }
            else {
              local_250 = *local_d8;
              local_b4 = local_a8[3];
              if (local_b4 == 0xffffffff) {
                local_594 = (undefined **)0x80000001;
              }
              else {
                local_594 = *(undefined ***)(local_d8[1] + local_b4 * 4);
              }
              local_34 = local_594;
              if ((local_a8[4] & 0x10) == 0) {
                if (local_a8[1] == 0) {
LAB_6815cc86:
                  local_5a8 = 1;
                }
                else {
                  if ((*(byte *)((int)local_a8 + 0x11) & 8) == 0) {
                    if ((*local_a8 & 1) == 0) {
                      local_5a0 = *(uint *)(*local_a8 + 8);
                    }
                    else {
                      local_5a0 = *local_a8;
                    }
                    local_59c = local_5a0;
                  }
                  else {
                    local_59c = (int)*(short *)((int)local_a8 + 0x12) << 1 | 1;
                  }
                  if (*(int *)(*(int *)(*local_d8 + 4) + 0x30) == 0) {
                    local_5a4 = local_d8;
                  }
                  else {
                    local_5a4 = (undefined **)
                                (**(code **)(*(int *)(*local_d8 + 4) + 0x30))(param_1,local_d8);
                  }
                  iVar16 = (*(code *)local_a8[1])(param_1,local_5a4,local_59c,&local_34);
                  if (iVar16 != 0) goto LAB_6815cc86;
                  local_5a8 = 0;
                }
                local_598 = local_5a8;
              }
              else {
                local_598 = certs_processKeyUsage((int)param_1,local_d8,*local_a8,local_a8[1],4,0,0,&local_34
                                        );
              }
              local_3c = local_598;
              if ((local_598 != 0) && (local_a8[3] < *(uint *)(local_250 + 0xc))) {
                *(undefined ***)(local_d8[1] + local_b4 * 4) = local_34;
              }
            }
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x10))
                                 (param_1,local_d8,local_c,&local_34);
          }
          if (local_3c == 0) goto LAB_681612b1;
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = (uint)local_34;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x36:
          local_34 = (undefined **)local_38[-1];
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_88 = (undefined **)local_38[-2];
          local_c = local_f4;
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_54[0xf] = local_38;
          if ((*(undefined ***)(*local_d8 + 4) == &PTR_FUN_68192948) ||
             ((*(int *)(*local_d8 + 4) != 0 &&
              ((undefined *)**(int **)(*local_d8 + 4) == PTR_FUN_68192948)))) {
            local_264 = ((uint)local_d8 >> 3 ^ local_c) & 0x3ff;
            local_260 = local_9c + 0x248;
            local_258 = (undefined4 *)(local_260 + local_264 * 8);
            local_26c = (undefined **)*local_258;
            local_268 = (uint *)local_258[1];
            if ((local_268 == (uint *)0x0) ||
               ((local_26c != local_d8 || (local_a8 = local_268, *local_268 != local_c)))) {
              local_a8 = (uint *)0x0;
            }
            local_25c = local_268;
            if (((local_a8 == (uint *)0x0) || ((local_a8[4] & 2) != 0)) ||
               (local_254 = *local_d8, (*(ushort *)(local_254 + 0x14) & 2) != 0)) {
              local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))
                                   (param_1,local_d8,local_c,&local_34);
            }
            else {
              if ((local_a8[4] & 0x20) == 0) {
                if ((local_a8[4] & 0x10) == 0) {
                  if (local_a8[2] == 0) {
LAB_6815d090:
                    local_5c0 = 1;
                  }
                  else {
                    if ((*(byte *)((int)local_a8 + 0x11) & 8) == 0) {
                      if ((*local_a8 & 1) == 0) {
                        local_5b8 = *(uint *)(*local_a8 + 8);
                      }
                      else {
                        local_5b8 = *local_a8;
                      }
                      local_5b4 = local_5b8;
                    }
                    else {
                      local_5b4 = (int)*(short *)((int)local_a8 + 0x12) << 1 | 1;
                    }
                    if (*(int *)(*(int *)(*local_d8 + 4) + 0x30) == 0) {
                      local_5bc = local_d8;
                    }
                    else {
                      local_5bc = (undefined **)
                                  (**(code **)(*(int *)(*local_d8 + 4) + 0x30))(param_1,local_d8);
                    }
                    iVar16 = (*(code *)local_a8[2])(param_1,local_5bc,local_5b4,&local_34);
                    if (iVar16 != 0) goto LAB_6815d090;
                    local_5c0 = 0;
                  }
                  local_5b0 = local_5c0;
                }
                else {
                  xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0xa0);
                  local_5b0 = 0;
                }
                local_5ac = local_5b0;
              }
              else {
                local_5ac = certs_processKeyUsage((int)param_1,local_d8,*local_a8,local_a8[2],8,1,&local_34,
                                         &local_34);
              }
              local_3c = local_5ac;
              if ((local_5ac != 0) && (local_a8[3] < *(uint *)(local_254 + 0xc))) {
                *(undefined ***)(local_d8[1] + local_a8[3] * 4) = local_34;
                *(undefined1 *)(*(int *)(param_1 + 10) + 0x60) = 1;
              }
            }
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))
                                 (param_1,local_d8,local_c,&local_34);
          }
          if (local_3c == 0) goto LAB_681612b1;
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = (uint)local_34;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x37:
          local_c = local_38[-1];
          if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_f4 = js_resolveAtom((int)param_1,local_c);
            uVar12 = local_f4;
            if (local_f4 == 0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          else {
            local_f4 = 0;
            uVar12 = local_c;
          }
          local_c = uVar12;
          local_88 = (undefined **)local_38[-2];
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_54[0xf] = local_38;
          if ((*(undefined ***)(*local_d8 + 4) == &PTR_FUN_68192948) ||
             ((*(int *)(*local_d8 + 4) != 0 &&
              ((undefined *)**(int **)(*local_d8 + 4) == PTR_FUN_68192948)))) {
            local_27c = ((uint)local_d8 >> 3 ^ local_c) & 0x3ff;
            local_278 = local_9c + 0x248;
            local_270 = (undefined4 *)(local_278 + local_27c * 8);
            local_284 = (undefined **)*local_270;
            local_280 = (uint *)local_270[1];
            if ((local_280 == (uint *)0x0) ||
               ((local_284 != local_d8 || (local_a8 = local_280, *local_280 != local_c)))) {
              local_a8 = (uint *)0x0;
            }
            local_274 = local_280;
            if (local_a8 == (uint *)0x0) {
              local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x10))
                                   (param_1,local_d8,local_c,&local_34);
            }
            else {
              local_288 = *local_d8;
              local_b4 = local_a8[3];
              if (local_b4 == 0xffffffff) {
                local_5c4 = (undefined **)0x80000001;
              }
              else {
                local_5c4 = *(undefined ***)(local_d8[1] + local_b4 * 4);
              }
              local_34 = local_5c4;
              if ((local_a8[4] & 0x10) == 0) {
                if (local_a8[1] == 0) {
LAB_6815d4c5:
                  local_5d8 = 1;
                }
                else {
                  if ((*(byte *)((int)local_a8 + 0x11) & 8) == 0) {
                    if ((*local_a8 & 1) == 0) {
                      local_5d0 = *(uint *)(*local_a8 + 8);
                    }
                    else {
                      local_5d0 = *local_a8;
                    }
                    local_5cc = local_5d0;
                  }
                  else {
                    local_5cc = (int)*(short *)((int)local_a8 + 0x12) << 1 | 1;
                  }
                  if (*(int *)(*(int *)(*local_d8 + 4) + 0x30) == 0) {
                    local_5d4 = local_d8;
                  }
                  else {
                    local_5d4 = (undefined **)
                                (**(code **)(*(int *)(*local_d8 + 4) + 0x30))(param_1,local_d8);
                  }
                  iVar16 = (*(code *)local_a8[1])(param_1,local_5d4,local_5cc,&local_34);
                  if (iVar16 != 0) goto LAB_6815d4c5;
                  local_5d8 = 0;
                }
                local_5c8 = local_5d8;
              }
              else {
                local_5c8 = certs_processKeyUsage((int)param_1,local_d8,*local_a8,local_a8[1],4,0,0,&local_34
                                        );
              }
              local_3c = local_5c8;
              if ((local_5c8 != 0) && (local_a8[3] < *(uint *)(local_288 + 0xc))) {
                *(undefined ***)(local_d8[1] + local_b4 * 4) = local_34;
              }
            }
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x10))
                                 (param_1,local_d8,local_c,&local_34);
          }
          if (local_3c == 0) goto LAB_681612b1;
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = (uint)local_34;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x38:
          local_34 = (undefined **)local_38[-1];
          local_c = local_38[-2];
          if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_f4 = js_resolveAtom((int)param_1,local_c);
            uVar12 = local_f4;
            if (local_f4 == 0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          else {
            local_f4 = 0;
            uVar12 = local_c;
          }
          local_c = uVar12;
          local_88 = (undefined **)local_38[-3];
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_54[0xf] = local_38;
          if ((*(undefined ***)(*local_d8 + 4) == &PTR_FUN_68192948) ||
             ((*(int *)(*local_d8 + 4) != 0 &&
              ((undefined *)**(int **)(*local_d8 + 4) == PTR_FUN_68192948)))) {
            local_29c = ((uint)local_d8 >> 3 ^ local_c) & 0x3ff;
            local_298 = local_9c + 0x248;
            local_290 = (undefined4 *)(local_298 + local_29c * 8);
            local_2a4 = (undefined **)*local_290;
            local_2a0 = (uint *)local_290[1];
            if ((local_2a0 == (uint *)0x0) ||
               ((local_2a4 != local_d8 || (local_a8 = local_2a0, *local_2a0 != local_c)))) {
              local_a8 = (uint *)0x0;
            }
            local_294 = local_2a0;
            if (((local_a8 == (uint *)0x0) || ((local_a8[4] & 2) != 0)) ||
               (local_28c = *local_d8, (*(ushort *)(local_28c + 0x14) & 2) != 0)) {
              local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))
                                   (param_1,local_d8,local_c,&local_34);
            }
            else {
              if ((local_a8[4] & 0x20) == 0) {
                if ((local_a8[4] & 0x10) == 0) {
                  if (local_a8[2] == 0) {
LAB_6815d90d:
                    local_5f0 = 1;
                  }
                  else {
                    if ((*(byte *)((int)local_a8 + 0x11) & 8) == 0) {
                      if ((*local_a8 & 1) == 0) {
                        local_5e8 = *(uint *)(*local_a8 + 8);
                      }
                      else {
                        local_5e8 = *local_a8;
                      }
                      local_5e4 = local_5e8;
                    }
                    else {
                      local_5e4 = (int)*(short *)((int)local_a8 + 0x12) << 1 | 1;
                    }
                    if (*(int *)(*(int *)(*local_d8 + 4) + 0x30) == 0) {
                      local_5ec = local_d8;
                    }
                    else {
                      local_5ec = (undefined **)
                                  (**(code **)(*(int *)(*local_d8 + 4) + 0x30))(param_1,local_d8);
                    }
                    iVar16 = (*(code *)local_a8[2])(param_1,local_5ec,local_5e4,&local_34);
                    if (iVar16 != 0) goto LAB_6815d90d;
                    local_5f0 = 0;
                  }
                  local_5e0 = local_5f0;
                }
                else {
                  xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0xa0);
                  local_5e0 = 0;
                }
                local_5dc = local_5e0;
              }
              else {
                local_5dc = certs_processKeyUsage((int)param_1,local_d8,*local_a8,local_a8[2],8,1,&local_34,
                                         &local_34);
              }
              local_3c = local_5dc;
              if ((local_5dc != 0) && (local_a8[3] < *(uint *)(local_28c + 0xc))) {
                *(undefined ***)(local_d8[1] + local_a8[3] * 4) = local_34;
                *(undefined1 *)(*(int *)(param_1 + 10) + 0x60) = 1;
              }
            }
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))
                                 (param_1,local_d8,local_c,&local_34);
          }
          if (local_3c == 0) goto LAB_681612b1;
          (local_38 + -2)[-1 - local_f8] = (uint)local_6c;
          local_38[-3] = (uint)local_34;
          puVar13 = local_38 + -2;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x39:
          if ((local_d8 == (undefined **)0x1) &&
             (local_d8 = (undefined **)runtime_getOrCreateObjectPrototype((int)param_1,(uint)local_54),
             local_d8 == (undefined **)0x0)) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_d8;
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x3a:
        case 0x79:
          goto switchD_681552c9_caseD_3a;
        case 0x3b:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_54[0xf] = local_38;
          local_c = local_f4;
          local_3c = runtime_setPropertyEx((int)param_1,local_f4,&local_d8,&local_44,(uint *)&local_f0);
          if (local_3c == 0) goto LAB_681612b1;
          if (local_f0 == (uint *)0x0) {
            local_24 = local_6c + local_8c;
            goto LAB_6815e829;
          }
          if (((*(undefined ***)(*local_d8 + 4) != &PTR_FUN_68192948) &&
              ((*(int *)(*local_d8 + 4) == 0 ||
               ((undefined *)**(int **)(*local_d8 + 4) != PTR_FUN_68192948)))) ||
             ((*(undefined ***)(*local_44 + 4) != &PTR_FUN_68192948 &&
              ((*(int *)(*local_44 + 4) == 0 ||
               ((undefined *)**(int **)(*local_44 + 4) != PTR_FUN_68192948)))))) {
            if (*(int *)(*(int *)(*local_44 + 4) + 0x34) != 0) {
              (**(code **)(*(int *)(*local_44 + 4) + 0x34))(param_1,local_44,local_f0);
            }
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x10))
                                 (param_1,local_d8,local_c,&local_34);
            if (local_3c == 0) goto LAB_681612b1;
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)local_34;
            puVar13 = local_38 + 1;
            pbVar18 = local_24;
            goto switchD_6815fd70_default;
          }
          local_a8 = local_f0;
          local_b4 = local_f0[3];
          if (local_b4 == 0xffffffff) {
            local_628 = (undefined **)0x80000001;
          }
          else {
            local_628 = *(undefined ***)(local_44[1] + local_b4 * 4);
          }
          local_34 = local_628;
          if ((local_f0[4] & 0x10) == 0) {
            if (local_f0[1] == 0) {
LAB_6815eb05:
              local_63c = 1;
            }
            else {
              if ((*(byte *)((int)local_f0 + 0x11) & 8) == 0) {
                if ((*local_f0 & 1) == 0) {
                  local_634 = *(uint *)(*local_f0 + 8);
                }
                else {
                  local_634 = *local_f0;
                }
                local_630 = local_634;
              }
              else {
                local_630 = (int)*(short *)((int)local_f0 + 0x12) << 1 | 1;
              }
              if (*(int *)(*(int *)(*local_d8 + 4) + 0x30) == 0) {
                local_638 = local_d8;
              }
              else {
                local_638 = (undefined **)
                            (**(code **)(*(int *)(*local_d8 + 4) + 0x30))(param_1,local_d8);
              }
              iVar16 = (*(code *)local_a8[1])(param_1,local_638,local_630,&local_34);
              if (iVar16 != 0) goto LAB_6815eb05;
              local_63c = 0;
            }
            local_62c = local_63c;
          }
          else {
            local_62c = certs_processKeyUsage((int)param_1,local_d8,*local_f0,local_f0[1],4,0,0,&local_34);
          }
          local_3c = local_62c;
          if (local_62c == 0) {
            if (*(int *)(*(int *)(*local_44 + 4) + 0x34) != 0) {
              (**(code **)(*(int *)(*local_44 + 4) + 0x34))(param_1,local_44,local_f0);
            }
            goto LAB_681612b1;
          }
          if (local_a8[3] < *(uint *)(*local_44 + 0xc)) {
            *(undefined ***)(local_44[1] + local_b4 * 4) = local_34;
          }
          if (*(int *)(*(int *)(*local_44 + 4) + 0x34) != 0) {
            (**(code **)(*(int *)(*local_44 + 4) + 0x34))(param_1,local_44,local_f0);
          }
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_34;
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x3c:
        case 0x3d:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = *(uint *)(local_f4 + 8);
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x3e:
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = 1;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x3f:
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = 3;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x40:
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = 0;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x41:
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = local_54[5];
          local_d8 = (undefined **)0x0;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x42:
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = 6;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x43:
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = 0xe;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x44:
          local_34 = (undefined **)local_38[-1];
          if (local_34 == (undefined **)0x0) {
            local_70 = 0;
          }
          else if (((uint)local_34 & 7) == 6) {
            local_70 = (int)local_34 >> 3;
          }
          else {
            local_54[0xf] = local_38;
            local_3c = js_getDateComponent((int)param_1,(uint)local_34,&local_70);
            if (local_3c == 0) goto LAB_681612b1;
          }
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          if (local_70 == 1) {
            local_8c = (uint)CONCAT11(local_6c[1],local_6c[2]);
            puVar13[-local_f8] = (uint)local_6c;
            *puVar13 = (uint)local_34;
            puVar13 = local_38;
          }
          goto switchD_6815fd70_default;
        case 0x45:
          local_34 = (undefined **)local_38[-1];
          if (local_34 == (undefined **)0x0) {
            local_70 = 0;
          }
          else if (((uint)local_34 & 7) == 6) {
            local_70 = (int)local_34 >> 3;
          }
          else {
            local_54[0xf] = local_38;
            local_3c = js_getDateComponent((int)param_1,(uint)local_34,&local_70);
            if (local_3c == 0) goto LAB_681612b1;
          }
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          if (local_70 == 0) {
            local_8c = (uint)CONCAT11(local_6c[1],local_6c[2]);
            puVar13[-local_f8] = (uint)local_6c;
            *puVar13 = (uint)local_34;
            puVar13 = local_38;
          }
          goto switchD_6815fd70_default;
        case 0x46:
          local_24 = local_6c;
          local_8c = (uint)CONCAT11(local_6c[1],local_6c[2]);
          if ((*(int *)(param_1 + 6) == 0) || (0x8b < *(int *)(param_1 + 6))) {
            local_38 = local_38 + -1;
            local_34 = (undefined **)*local_38;
            puVar13 = local_38;
            pbVar18 = local_24;
            if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001))
            goto switchD_6815fd70_default;
            local_2c = (byte *)((int)local_34 >> 1);
          }
          else {
            local_2f4 = local_38[-1];
            if (((local_2f4 & 1) == 0) || (local_2f4 == 0x80000001)) {
              local_54[0xf] = local_38;
              local_3c = runtime_parseInt(param_1,local_2f4,&local_2c);
              if (local_3c == 0) goto LAB_681612b1;
            }
            else {
              local_2c = (byte *)((int)local_2f4 >> 1);
            }
            local_38 = local_38 + -1;
          }
          local_c4 = (int)CONCAT11(local_24[3],local_24[4]);
          local_14 = (int)CONCAT11(local_24[5],local_24[6]);
          local_2c = local_2c + -local_c4;
          puVar13 = local_38;
          pbVar18 = local_24 + 4;
          if (local_2c < (byte *)((local_14 - local_c4) + 1)) {
            pbVar18 = local_24 + (int)local_2c * 2 + 6;
            local_58 = (uint)CONCAT11(pbVar18[1],pbVar18[2]);
            if (local_58 != 0) {
              local_8c = local_58;
            }
          }
          goto switchD_6815fd70_default;
        case 0x47:
          local_38 = local_38 + -1;
          local_88 = (undefined **)*local_38;
          local_24 = local_6c;
          local_8c = (uint)CONCAT11(local_6c[1],local_6c[2]);
          if ((((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) &&
              (((uint)local_88 & 7) != 2)) &&
             ((((uint)local_88 & 7) != 4 &&
              (puVar13 = local_38, pbVar18 = local_24, ((uint)local_88 & 7) != 6))))
          goto switchD_6815fd70_default;
          local_8 = (uint)CONCAT11(local_6c[3],local_6c[4]);
          local_24 = local_6c + 4;
          if (((uint)local_88 & 7) == 4) {
            local_ec = (uint *)((uint)local_88 & 0xfffffff8);
            goto LAB_6815f004;
          }
          if (((uint)local_88 & 7) != 2) goto LAB_6815f1ed;
          local_cc = *(double *)((uint)local_88 & 0xfffffff8);
          goto LAB_6815f117;
        case 0x48:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          local_30 = (undefined **)((uint)local_88 & 7);
          local_ac = (undefined **)((uint)local_34 & 7);
          if (local_30 == local_ac) {
            if (local_30 == (undefined **)0x4) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(iVar16 == 0);
            }
            else if (local_30 == (undefined **)0x2) {
              dVar3 = *(double *)((uint)local_88 & 0xfffffff8);
              dVar4 = *(double *)((uint)local_34 & 0xfffffff8);
              (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc != 0 ||
                   (((ulonglong)dVar3 & 0xfffff00000000) != 0)))) ||
                 (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar4 >> 0x20),
                  ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar4,0), (int)local_7c != 0 ||
                   (((ulonglong)dVar4 & 0xfffff00000000) != 0)))))) {
                local_3b0 = 0;
              }
              else {
                local_3ac = (uint)(dVar4 == dVar3);
                local_3b0 = local_3ac;
              }
              local_70 = local_3b0;
              local_cc = dVar3;
              local_7c = dVar4;
            }
            else {
              local_70 = (uint)(local_88 == local_34);
            }
          }
          else if (((local_30 == (undefined **)0x2) && (((uint)local_34 & 1) != 0)) &&
                  (local_34 != (undefined **)0x80000001)) {
            dVar3 = *(double *)((uint)local_88 & 0xfffffff8);
            dVar4 = (double)((int)local_34 >> 1);
            (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
            if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc != 0 ||
                 (((ulonglong)dVar3 & 0xfffff00000000) != 0)))) ||
               (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar4 >> 0x20),
                ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar4,0), (int)local_7c != 0 ||
                 (((ulonglong)dVar4 & 0xfffff00000000) != 0)))))) {
              local_3bc = 0;
            }
            else {
              local_3b8 = (uint)(dVar4 == dVar3);
              local_3bc = local_3b8;
            }
            local_70 = local_3bc;
            local_cc = dVar3;
            local_7c = dVar4;
          }
          else if (((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) ||
                  (local_ac != (undefined **)0x2)) {
            local_70 = (uint)(local_88 == local_34);
          }
          else {
            dVar4 = (double)((int)local_88 >> 1);
            dVar3 = *(double *)((uint)local_34 & 0xfffffff8);
            (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar4 >> 0x20);
            if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar4,0), (int)local_cc != 0 ||
                 (((ulonglong)dVar4 & 0xfffff00000000) != 0)))) ||
               (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar3 >> 0x20),
                ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar3,0), (int)local_7c != 0 ||
                 (((ulonglong)dVar3 & 0xfffff00000000) != 0)))))) {
              local_3c8 = 0;
            }
            else {
              local_3c4 = (uint)(dVar3 == dVar4);
              local_3c8 = local_3c4;
            }
            local_70 = local_3c8;
            local_cc = dVar4;
            local_7c = dVar3;
          }
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = local_70 << 3 | 6;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x49:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          local_30 = (undefined **)((uint)local_88 & 7);
          local_ac = (undefined **)((uint)local_34 & 7);
          if (local_30 == local_ac) {
            if (local_30 == (undefined **)0x4) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(iVar16 != 0);
            }
            else if (local_30 == (undefined **)0x2) {
              dVar3 = *(double *)((uint)local_88 & 0xfffffff8);
              dVar4 = *(double *)((uint)local_34 & 0xfffffff8);
              (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc != 0 ||
                   (((ulonglong)dVar3 & 0xfffff00000000) != 0)))) ||
                 (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar4 >> 0x20),
                  ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar4,0), (int)local_7c != 0 ||
                   (((ulonglong)dVar4 & 0xfffff00000000) != 0)))))) {
                local_3d0 = 1;
              }
              else {
                local_3cc = (uint)(dVar4 != dVar3);
                local_3d0 = local_3cc;
              }
              local_70 = local_3d0;
              local_cc = dVar3;
              local_7c = dVar4;
            }
            else {
              local_70 = (uint)(local_88 != local_34);
            }
          }
          else if (((local_30 == (undefined **)0x2) && (((uint)local_34 & 1) != 0)) &&
                  (local_34 != (undefined **)0x80000001)) {
            dVar3 = *(double *)((uint)local_88 & 0xfffffff8);
            dVar4 = (double)((int)local_34 >> 1);
            (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
            if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc != 0 ||
                 (((ulonglong)dVar3 & 0xfffff00000000) != 0)))) ||
               (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar4 >> 0x20),
                ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar4,0), (int)local_7c != 0 ||
                 (((ulonglong)dVar4 & 0xfffff00000000) != 0)))))) {
              local_3dc = 1;
            }
            else {
              local_3d8 = (uint)(dVar4 != dVar3);
              local_3dc = local_3d8;
            }
            local_70 = local_3dc;
            local_cc = dVar3;
            local_7c = dVar4;
          }
          else if (((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) ||
                  (local_ac != (undefined **)0x2)) {
            local_70 = (uint)(local_88 != local_34);
          }
          else {
            dVar4 = (double)((int)local_88 >> 1);
            dVar3 = *(double *)((uint)local_34 & 0xfffffff8);
            (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar4 >> 0x20);
            if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar4,0), (int)local_cc != 0 ||
                 (((ulonglong)dVar4 & 0xfffff00000000) != 0)))) ||
               (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar3 >> 0x20),
                ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar3,0), (int)local_7c != 0 ||
                 (((ulonglong)dVar3 & 0xfffff00000000) != 0)))))) {
              local_3e8 = 1;
            }
            else {
              local_3e4 = (uint)(dVar3 != dVar4);
              local_3e8 = local_3e4;
            }
            local_70 = local_3e8;
            local_cc = dVar4;
            local_7c = dVar3;
          }
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = local_70 << 3 | 6;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x4a:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_d8 = (undefined **)(*(uint *)(local_f4 + 8) & 0xfffffff8);
          local_84 = (int *)local_54[0xd];
          if (((int *)(*(uint *)(local_d8[1] + 4) & 0xfffffff8) != local_84) &&
             (local_d8 = (undefined **)runtime_lookupFunction((int)param_1,local_d8,(uint)local_84),
             local_d8 == (undefined **)0x0)) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          local_18 = xtra_getObjectTag(param_1,(int)local_d8);
          local_4c = *(byte *)(local_18 + 0x16) & 0x30;
          if ((*(byte *)(local_18 + 0x16) & 0x30) != 0) {
            local_4c = local_4c | 0x40;
          }
          if (local_4c == 0) {
            local_65c = local_d8;
          }
          else {
            local_65c = (undefined **)0x80000001;
          }
          local_3c = (**(code **)(*(int *)(*(int *)local_54[2] + 4) + 0xc))
                               (param_1,local_54[2],*(undefined4 *)(local_18 + 0x18),local_65c,
                                -(uint)((local_4c & 0x10) != 0) & (uint)local_d8,
                                -(uint)((local_4c & 0x20) != 0) & (uint)local_d8,local_4c | 1,0);
          puVar13 = local_38;
          pbVar18 = local_24;
          if (local_3c != 0) goto switchD_6815fd70_default;
          param_1[0x48] = 0;
          param_1[0x49] = 0;
          goto LAB_681612b1;
        case 0x4b:
          local_d8 = (undefined **)local_54[2];
          local_d0 = (uint *)xtra_resolvePath((uint)param_1,(int *)local_d8);
          if (local_d0 != (uint *)0x0) {
            local_2c = (byte *)0x0;
            local_e8 = *local_d0;
            goto LAB_6815f82b;
          }
          local_3c = 0;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x4c:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_d8 = (undefined **)local_54[2];
          local_c = local_f4;
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 8))
                               (param_1,local_d8,local_f4,&local_44,&local_f0);
          if (local_3c == 0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          if (local_f0 == (uint *)0x0) {
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0xc))
                                 (param_1,local_d8,local_c,0x80000001,0,0,8,0);
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x18))
                                 (param_1,local_d8,local_c,local_f0,&local_4c);
            if (local_3c != 0) {
              local_4c = local_4c | 8;
              local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x1c))
                                   (param_1,local_d8,local_c,local_f0,&local_4c);
            }
            if (*(int *)(*(int *)(*local_44 + 4) + 0x34) != 0) {
              (**(code **)(*(int *)(*local_44 + 4) + 0x34))(param_1,local_44,local_f0);
            }
          }
          goto joined_r0x681556b3;
        case 0x4d:
          local_c = 0x80000001;
          local_88 = (undefined **)local_38[-1];
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_54[0xf] = local_38;
          local_3c = strings_searchTable((uint)param_1,(int *)local_d8,local_c);
          if (local_3c == 0) goto LAB_681612b1;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x4e:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_88 = (undefined **)local_38[-1];
          local_c = local_f4;
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_54[0xf] = local_38;
          local_3c = strings_searchTable((uint)param_1,(int *)local_d8,local_c);
          if (local_3c == 0) goto LAB_681612b1;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x4f:
          local_c = local_38[-1];
          if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_f4 = js_resolveAtom((int)param_1,local_c);
            uVar12 = local_f4;
            if (local_f4 == 0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          else {
            local_f4 = 0;
            uVar12 = local_c;
          }
          local_c = uVar12;
          local_88 = (undefined **)local_38[-2];
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_54[0xf] = local_38;
          local_3c = strings_searchTable((uint)param_1,(int *)local_d8,local_c);
          if (local_3c == 0) goto LAB_681612b1;
          puVar13 = local_38 + -2;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x50:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_34 = *(undefined ***)(local_f4 + 8);
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_34;
          local_d8 = (undefined **)0x0;
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x51:
          puVar13 = local_38 + -1;
          goto switchD_6815fd70_default;
        case 0x52:
          local_1f4 = local_38[-1];
          if (((local_1f4 & 1) == 0) || (local_1f4 == 0x80000001)) {
            if ((local_1f4 & 7) == 2) {
              local_cc = *(double *)(local_1f4 & 0xfffffff8);
            }
            else {
              local_54[0xf] = local_38;
              local_3c = runtime_parseNumber(param_1,local_1f4,(double *)&local_cc);
              if (local_3c == 0) goto LAB_681612b1;
            }
          }
          else {
            local_cc = (double)((int)local_1f4 >> 1);
          }
          if ((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) ||
             (((*(unsigned int *)((char *)&local_cc + 4)) == 0x80000000 && ((int)local_cc == 0)))) {
LAB_6815b084:
            local_3c = runtime_formatNumber((int)param_1,local_cc,&local_1fc);
            if (local_3c == 0) goto LAB_681612b1;
          }
          else {
            uVar19 = strings_floatToUint64((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000,0);
            local_1f8 = (int)uVar19;
            if ((local_cc != (double)local_1f8) || (0x7ffffffe < local_1f8 + 0x3fffffffU))
            goto LAB_6815b084;
            local_1fc = local_1f8 << 1 | 1;
          }
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = local_1fc;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x53:
          uVar14 = runtime_invokeBreakpointCallback((int)param_1,local_98,(int)local_6c,(uint *)&local_34);
          puVar13 = local_38;
          pbVar18 = local_24;
          switch(uVar14) {
          case 0:
            local_3c = 0;
            break;
          case 1:
            goto switchD_6815fd70_caseD_1;
          case 2:
            local_54[8] = local_34;
            break;
          case 3:
            *(undefined1 *)(param_1 + 0xad) = 1;
            *(undefined ***)(param_1 + 0xae) = local_34;
            local_3c = 0;
            break;
          default:
            goto switchD_6815fd70_default;
          }
          goto LAB_681612b1;
        case 0x54:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = *(uint *)(local_54[7] + local_b4 * 4);
          local_d8 = (undefined **)0x0;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x55:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_b0 = (uint *)(local_54[7] + local_b4 * 4);
          *(undefined1 *)(*(int *)(param_1 + 10) + 0x60) = 1;
          *local_b0 = local_38[-1];
          local_d8 = (undefined **)0x0;
          goto switchD_6815fd70_default;
        case 0x56:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = *(uint *)(local_54[10] + local_b4 * 4);
          local_d8 = (undefined **)0x0;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x57:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_b0 = (uint *)(local_54[10] + local_b4 * 4);
          *(undefined1 *)(*(int *)(param_1 + 10) + 0x60) = 1;
          *local_b0 = local_38[-1];
          local_d8 = (undefined **)0x0;
          goto switchD_6815fd70_default;
        case 0x58:
          local_2c = (byte *)(uint)CONCAT11(local_6c[1],local_6c[2]);
          local_34 = (undefined **)((int)local_2c << 1 | 1);
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_34;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x59:
          local_1c = 0;
          local_54[0x11] = local_54[0x11] + 1;
LAB_6815b0ef:
          local_b0 = (uint *)((int)local_38 - (local_1c * 4 + 8));
          local_18 = 0;
          local_44 = (undefined **)0x0;
          local_88 = (undefined **)*local_b0;
          if ((((((uint)local_88 & 7) != 0) ||
               (local_44 = (undefined **)((uint)local_88 & 0xfffffff8),
               local_44 == (undefined **)0x0)) ||
              ((undefined **)(*(uint *)(local_44[1] + 8) & 0xfffffffe) == &PTR_s_Function_681928b8))
             || (*(int *)(*(int *)(*local_44 + 4) + 0x3c) == 0)) {
            local_54[0xf] = local_38;
            local_18 = runtime_callFunction((int)param_1,local_b0,1);
            if (local_18 == 0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_68 = &PTR_s_Object_681929a8;
          if (local_44 == (undefined **)0x0) {
            local_84 = (int *)0x0;
            local_28 = (undefined4 *)0x0;
            local_18 = 0;
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_44 + 4) + 0x10))
                                 (param_1,local_44,*(undefined4 *)(local_9c + 0xe8),&local_34);
            if (local_3c == 0) goto LAB_681612b1;
            if (((uint)local_34 & 7) == 0) {
              local_530 = (undefined4 *)((uint)local_34 & 0xfffffff8);
            }
            else {
              local_530 = (undefined4 *)0x0;
            }
            local_28 = local_530;
            local_84 = (int *)(*(uint *)(local_44[1] + 4) & 0xfffffff8);
            if ((undefined **)(*(uint *)(local_44[1] + 8) & 0xfffffffe) == &PTR_s_Function_681928b8)
            {
              uVar12 = xtra_getObjectTag(param_1,(int)local_44);
              local_74 = *(undefined ***)(uVar12 + 0x1c);
              if (local_74 != (undefined **)0x0) {
                local_68 = local_74;
              }
            }
          }
          local_d8 = (undefined **)runtime_setProperty((int)param_1,local_68,local_28,(uint)local_84);
          if (local_d8 == (undefined **)0x0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          local_b0[1] = (uint)local_d8;
          local_54[0xf] = local_38;
          local_3c = certs_verifyChain((uint)param_1,local_1c,1);
          local_38 = (uint *)local_54[0xf];
          if (local_3c == 0) {
            param_1[0x48] = 0;
            param_1[0x49] = 0;
            goto LAB_681612b1;
          }
          local_34 = (undefined **)*local_b0;
          puVar13 = local_38;
          pbVar18 = local_24;
          if ((((uint)local_34 & 7) == 0) && (local_34 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_34 & 0xfffffff8);
            goto switchD_6815fd70_default;
          }
          if ((local_18 != 0) || ((*(int *)(param_1 + 6) != 0 && (*(int *)(param_1 + 6) < 0x82)))) {
            *local_b0 = (uint)local_d8;
            goto switchD_6815fd70_default;
          }
          local_ec = (uint *)certs_hashLookup((int)param_1,(uint)local_34);
          if (local_ec != (uint *)0x0) {
            xtra_getStringValue(local_ec);
            xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x1c);
          }
          local_3c = 0;
          goto LAB_681612b1;
        case 0x5a:
          iVar16 = local_54[0x11];
          local_54[0x11] = iVar16 + -1;
          if (iVar16 + -1 == 0) {
            local_54[0x12] = 0;
          }
          local_88 = (undefined **)local_38[-1];
          *(uint *)(param_1 + 0x48) = (uint)local_88 & 0xfffffff8;
          goto switchD_6815fd70_default;
        case 0x5b:
          local_34 = (undefined **)local_38[-1];
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_2c = (byte *)0xffffffff;
          local_c = local_f4;
          goto LAB_68160c68;
        case 0x5c:
          local_34 = (undefined **)local_38[-1];
          local_c = local_38[-2];
          if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_f4 = js_resolveAtom((int)param_1,local_c);
            uVar12 = local_f4;
            if (local_f4 == 0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          else {
            local_f4 = 0;
            uVar12 = local_c;
          }
          local_c = uVar12;
          local_2c = (byte *)0xfffffffe;
LAB_68160c68:
          local_88 = (undefined **)local_38[(int)(local_2c + -1)];
          local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))
                               (param_1,local_d8,local_c,&local_34);
          if (local_3c == 0) goto LAB_681612b1;
          puVar13 = local_38 + (int)local_2c;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x5d:
          local_d8 = (undefined **)local_54[0x12];
          if (local_d8 == (undefined **)0x0) {
            local_d8 = (undefined **)js_arrayEnsureCapacity(param_1,0,0);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
            local_54[0x12] = local_d8;
          }
          local_2c = (byte *)(uint)CONCAT11(local_6c[1],local_6c[2]);
          local_c = (int)local_2c << 1 | 1;
          local_34 = (undefined **)local_38[-1];
          if ((((uint)local_34 & 7) != 0) || (local_34 == (undefined **)0x0)) {
            runtime_snprintf(local_310,0xc,"%u");
            xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x1d);
            local_3c = 0;
            goto LAB_681612b1;
          }
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))
                               (param_1,local_d8,local_c,&local_34);
          goto joined_r0x681556b3;
        case 0x5e:
          local_2c = (byte *)(uint)CONCAT11(local_6c[1],local_6c[2]);
          local_c = (int)local_2c << 1 | 1;
          local_d8 = (undefined **)local_54[0x12];
          if (local_d8 == (undefined **)0x0) {
            local_34 = (undefined **)0x80000001;
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x10))
                                 (param_1,local_d8,local_c,&local_34);
            if (local_3c == 0) goto LAB_681612b1;
          }
          if (((uint)local_34 & 7) == 0) {
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)local_34;
            puVar13 = local_38 + 1;
            pbVar18 = local_24;
            goto switchD_6815fd70_default;
          }
          runtime_snprintf(local_31c,0xc,"%u");
          xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x1e);
          local_3c = 0;
          goto LAB_681612b1;
        case 0x5f:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_b0 = (uint *)(local_54[7] + local_b4 * 4);
          local_34 = (undefined **)*local_b0;
          if (((((uint)local_34 & 1) != 0) && (local_34 != (undefined **)0x80000001)) &&
             (local_34 != (undefined **)0x7fffffff)) {
            local_34 = (undefined **)((int)local_34 + 2);
            *local_b0 = (uint)local_34;
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)local_34;
            puVar13 = local_38 + 1;
            goto switchD_6815fd70_default;
          }
          break;
        case 0x60:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_b0 = (uint *)(local_54[10] + local_b4 * 4);
          local_34 = (undefined **)*local_b0;
          if (((((uint)local_34 & 1) != 0) && (local_34 != (undefined **)0x80000001)) &&
             (local_34 != (undefined **)0x7fffffff)) {
            local_34 = (undefined **)((int)local_34 + 2);
            *local_b0 = (uint)local_34;
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)local_34;
            puVar13 = local_38 + 1;
            goto switchD_6815fd70_default;
          }
          break;
        case 0x61:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_b0 = (uint *)(local_54[7] + local_b4 * 4);
          local_34 = (undefined **)*local_b0;
          if (((((uint)local_34 & 1) != 0) && (local_34 != (undefined **)0x80000001)) &&
             (local_34 != (undefined **)0x80000003)) {
            local_34 = (undefined **)((int)local_34 - 2);
            *local_b0 = (uint)local_34;
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)local_34;
            puVar13 = local_38 + 1;
            goto switchD_6815fd70_default;
          }
          break;
        case 0x62:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_b0 = (uint *)(local_54[10] + local_b4 * 4);
          local_34 = (undefined **)*local_b0;
          if (((((uint)local_34 & 1) != 0) && (local_34 != (undefined **)0x80000001)) &&
             (local_34 != (undefined **)0x80000003)) {
            local_34 = (undefined **)((int)local_34 - 2);
            *local_b0 = (uint)local_34;
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)local_34;
            puVar13 = local_38 + 1;
            goto switchD_6815fd70_default;
          }
          break;
        case 99:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_b0 = (uint *)(local_54[7] + local_b4 * 4);
          ppuVar8 = (undefined **)*local_b0;
          local_34 = ppuVar8;
          if (((((uint)ppuVar8 & 1) != 0) && (ppuVar8 != (undefined **)0x80000001)) &&
             (ppuVar8 != (undefined **)0x7fffffff)) {
            local_34 = (undefined **)((int)ppuVar8 + 2);
            *local_b0 = (uint)local_34;
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)ppuVar8;
            local_ac = ppuVar8;
            puVar13 = local_38 + 1;
            goto switchD_6815fd70_default;
          }
          break;
        case 100:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_b0 = (uint *)(local_54[10] + local_b4 * 4);
          ppuVar8 = (undefined **)*local_b0;
          local_34 = ppuVar8;
          if (((((uint)ppuVar8 & 1) != 0) && (ppuVar8 != (undefined **)0x80000001)) &&
             (ppuVar8 != (undefined **)0x7fffffff)) {
            local_34 = (undefined **)((int)ppuVar8 + 2);
            *local_b0 = (uint)local_34;
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)ppuVar8;
            local_ac = ppuVar8;
            puVar13 = local_38 + 1;
            goto switchD_6815fd70_default;
          }
          break;
        case 0x65:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_b0 = (uint *)(local_54[7] + local_b4 * 4);
          ppuVar8 = (undefined **)*local_b0;
          local_34 = ppuVar8;
          if (((((uint)ppuVar8 & 1) != 0) && (ppuVar8 != (undefined **)0x80000001)) &&
             (ppuVar8 != (undefined **)0x80000003)) {
            local_34 = (undefined **)((int)ppuVar8 - 2);
            *local_b0 = (uint)local_34;
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)ppuVar8;
            local_ac = ppuVar8;
            puVar13 = local_38 + 1;
            goto switchD_6815fd70_default;
          }
          break;
        case 0x66:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_b0 = (uint *)(local_54[10] + local_b4 * 4);
          ppuVar8 = (undefined **)*local_b0;
          local_34 = ppuVar8;
          if (((((uint)ppuVar8 & 1) != 0) && (ppuVar8 != (undefined **)0x80000001)) &&
             (ppuVar8 != (undefined **)0x80000003)) {
            local_34 = (undefined **)((int)ppuVar8 - 2);
            *local_b0 = (uint)local_34;
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)ppuVar8;
            local_ac = ppuVar8;
            puVar13 = local_38 + 1;
            goto switchD_6815fd70_default;
          }
          break;
        case 0x67:
          local_54[0xf] = local_38;
          local_3c = runtime_deleteProperty((uint)param_1,local_38[-1],(uint *)&local_d8);
          if (local_3c == 0) goto LAB_681612b1;
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = (uint)local_d8;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x68:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_54[0xf] = local_38;
          local_c = local_f4;
          local_3c = runtime_setPropertyEx((int)param_1,local_f4,&local_d8,&local_44,(uint *)&local_f0);
          if (local_3c == 0) goto LAB_681612b1;
          if ((local_f0 != (uint *)0x0) && (*(int *)(*(int *)(*local_44 + 4) + 0x34) != 0)) {
            (**(code **)(*(int *)(*local_44 + 4) + 0x34))(param_1,local_44,local_f0);
          }
          local_88 = local_d8;
switchD_681552c9_caseD_a:
          local_2c = (byte *)0xffffffff;
LAB_68156091:
          local_d8 = (undefined **)(local_38[(int)local_2c] & 0xfffffff8);
          if (local_d8 == (undefined **)0x0) {
            local_34 = (undefined **)0x6;
            goto LAB_681564df;
          }
          local_b0 = local_38 + (int)(local_2c + -1);
          local_34 = (undefined **)*local_b0;
          local_80 = local_d8;
          if (local_34 != (undefined **)0x80000001) {
            local_a0 = (int *)((uint)local_34 & 0xfffffff8);
            local_c0 = *(int *)(local_a0[1] + 0xc);
            local_d8 = (undefined **)(*(uint *)(local_a0[1] + 4) & 0xfffffff8);
            goto LAB_681561d6;
          }
          local_a0 = runtime_setProperty((int)param_1,&PTR_s_PropertyIterator_68194b28,(undefined4 *)0x0,
                                  (uint)local_d8);
          if (local_a0 == (int *)0x0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          *(undefined4 *)(local_a0[1] + 0xc) = 0;
          local_3c = js_internAtom((int)param_1,local_a0[1] + 4,0x68182500);
          if (local_3c == 0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          *local_b0 = (uint)local_a0;
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x28))(param_1,local_d8,0,&local_c0,0);
          *(int *)(local_a0[1] + 0xc) = local_c0;
          if (local_3c != 0) goto LAB_681561d6;
          goto LAB_681612b1;
        case 0x69:
          local_88 = (undefined **)local_38[-1];
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_2c = (byte *)0xfffffffe;
          local_c = local_f4;
          goto LAB_68156091;
        case 0x6b:
          puVar13 = local_38 + -2;
          goto switchD_6815fd70_default;
        case 0x6c:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_54[0xf] = local_38;
          local_d8 = (undefined **)runtime_setPropertyByName((uint)param_1,local_f4);
          if (local_d8 != (undefined **)0x0) {
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)local_d8;
            puVar13 = local_38 + 1;
            pbVar18 = local_24;
            goto switchD_6815fd70_default;
          }
          local_3c = 0;
          goto LAB_681612b1;
        case 0x6d:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          local_360 = (undefined **)((uint)local_88 & 0xfffffff8);
          local_54[0xf] = local_38;
          local_d8 = local_360;
          local_c = local_f4;
          if ((*(undefined ***)(*local_360 + 4) == &PTR_FUN_68192948) ||
             ((*(int *)(*local_360 + 4) != 0 &&
              ((undefined *)**(int **)(*local_360 + 4) == PTR_FUN_68192948)))) {
            local_120 = ((uint)local_88 >> 3 ^ local_f4) & 0x3ff;
            local_11c = local_9c + 0x248;
            local_114 = (undefined4 *)(local_11c + local_120 * 8);
            local_128 = (undefined **)*local_114;
            local_124 = (uint *)local_114[1];
            if ((local_124 == (uint *)0x0) ||
               ((local_128 != local_360 || (local_a8 = local_124, *local_124 != local_f4)))) {
              local_a8 = (uint *)0x0;
            }
            local_118 = local_124;
            if (((local_a8 == (uint *)0x0) || ((local_a8[4] & 2) != 0)) ||
               (local_110 = *local_360, (*(ushort *)(local_110 + 0x14) & 2) != 0)) {
              local_3c = (**(code **)(*(int *)(*local_360 + 4) + 0x14))
                                   (param_1,local_360,local_f4,&local_34);
            }
            else {
              if ((local_a8[4] & 0x20) == 0) {
                if ((local_a8[4] & 0x10) == 0) {
                  if (local_a8[2] == 0) {
LAB_681569d7:
                    local_364 = 1;
                  }
                  else {
                    if ((*(byte *)((int)local_a8 + 0x11) & 8) == 0) {
                      if ((*local_a8 & 1) == 0) {
                        local_35c = *(uint *)(*local_a8 + 8);
                      }
                      else {
                        local_35c = *local_a8;
                      }
                      local_358 = local_35c;
                    }
                    else {
                      local_358 = (int)*(short *)((int)local_a8 + 0x12) << 1 | 1;
                    }
                    if (*(int *)(*(int *)(*local_360 + 4) + 0x30) != 0) {
                      local_360 = (undefined **)
                                  (**(code **)(*(int *)(*local_360 + 4) + 0x30))(param_1,local_360);
                    }
                    iVar16 = (*(code *)local_a8[2])(param_1,local_360,local_358,&local_34);
                    if (iVar16 != 0) goto LAB_681569d7;
                    local_364 = 0;
                  }
                  local_354 = local_364;
                }
                else {
                  xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0xa0);
                  local_354 = 0;
                }
                local_350 = local_354;
              }
              else {
                local_350 = certs_processKeyUsage((int)param_1,local_360,*local_a8,local_a8[2],8,1,&local_34,
                                         &local_34);
              }
              local_3c = local_350;
              if ((local_350 != 0) && (local_a8[3] < *(uint *)(local_110 + 0xc))) {
                *(undefined ***)(local_d8[1] + local_a8[3] * 4) = local_34;
                *(undefined1 *)(*(int *)(param_1 + 10) + 0x60) = 1;
              }
            }
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_360 + 4) + 0x14))
                                 (param_1,local_360,local_f4,&local_34);
          }
          if (local_3c == 0) goto LAB_681612b1;
          (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
          local_38[-2] = (uint)local_34;
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x6e:
          *(undefined1 *)(param_1 + 0xad) = 1;
          *(uint *)(param_1 + 0xae) = local_38[-1];
          local_3c = 0;
          local_38 = local_38 + -1;
          goto LAB_681612b1;
        case 0x6f:
          local_34 = (undefined **)local_38[-1];
          if ((((uint)local_34 & 7) != 0) || (local_34 == (undefined **)0x0)) {
            local_ec = crypto_decompileExpr((int)param_1,(int *)0xffffffff,local_34,(uint *)0x0);
            if (local_ec != (uint *)0x0) {
              xtra_getStringValue(local_ec);
              xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x1b);
            }
            local_3c = 0;
            goto LAB_681612b1;
          }
          puVar13 = local_38 + -1;
          local_d8 = (undefined **)((uint)local_34 & 0xfffffff8);
          local_c = local_38[-2];
          local_38 = puVar13;
          if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
            local_54[0xf] = puVar13;
            local_f4 = js_resolveAtom((int)param_1,local_c);
            uVar12 = local_f4;
            if (local_f4 == 0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          else {
            local_f4 = 0;
            uVar12 = local_c;
          }
          local_c = uVar12;
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 8))
                               (param_1,local_d8,local_c,&local_44,&local_f0);
          if (local_3c == 0) goto LAB_681612b1;
          local_38[-1 - local_f8] = (uint)local_6c;
          local_38[-1] = (uint)(local_f0 != (uint *)0x0) << 3 | 6;
          puVar13 = local_38;
          pbVar18 = local_24;
          if ((local_f0 != (uint *)0x0) && (*(int *)(*(int *)(*local_44 + 4) + 0x34) != 0)) {
            (**(code **)(*(int *)(*local_44 + 4) + 0x34))(param_1,local_44,local_f0);
            puVar13 = local_38;
            pbVar18 = local_24;
          }
          goto switchD_6815fd70_default;
        case 0x70:
          local_34 = (undefined **)local_38[-1];
          if ((((uint)local_34 & 7) == 0) && (local_34 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_34 & 0xfffffff8);
            local_88 = (undefined **)local_38[-2];
            local_70 = 0;
            if (*(int *)(*(int *)(*local_d8 + 4) + 0x44) != 0) {
              local_54[0xf] = local_38;
              local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x44))
                                   (param_1,local_d8,local_88,&local_70);
              if (local_3c == 0) goto LAB_681612b1;
            }
            (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
            local_38[-2] = local_70 << 3 | 6;
            puVar13 = local_38 + -1;
            pbVar18 = local_24;
            goto switchD_6815fd70_default;
          }
          local_54[0xf] = local_38;
          local_ec = crypto_decompileExpr((int)param_1,(int *)0xffffffff,local_34,(uint *)0x0);
          if (local_ec != (uint *)0x0) {
            xtra_getStringValue(local_ec);
            xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x1f);
          }
          local_3c = 0;
          goto LAB_681612b1;
        case 0x71:
          local_320 = *(code **)(local_9c + 0x200);
          if (local_320 == (code *)0x0) goto switchD_6815fd70_default;
          local_54[0xf] = local_38;
          iVar16 = (*local_320)(param_1,local_98,local_6c,&local_34,
                                *(undefined4 *)(local_9c + 0x204));
          if (iVar16 == 0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          if (iVar16 == 2) {
            local_54[8] = local_34;
          }
          else {
            puVar13 = local_38;
            pbVar18 = local_24;
            if (iVar16 != 3) goto switchD_6815fd70_default;
            *(undefined1 *)(param_1 + 0xad) = 1;
            *(undefined ***)(param_1 + 0xae) = local_34;
            local_3c = 0;
          }
          goto LAB_681612b1;
        case 0x72:
          local_2c = local_6c + (local_8c - local_98[2]);
          bVar11 = local_6c[1];
          bVar5 = local_6c[2];
          *local_38 = (int)local_2c * 2 | 1;
          local_8c = (int)CONCAT11(bVar11,bVar5);
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x73:
          local_34 = (undefined **)local_38[-1];
          local_2c = (byte *)((int)local_34 >> 1);
          local_6c = local_2c + local_98[2];
          local_8c = 0;
          puVar13 = local_38 + -1;
          goto switchD_6815fd70_default;
        case 0x74:
          *local_38 = *(uint *)(param_1 + 0xae);
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x75:
          local_2c = (byte *)(uint)CONCAT11(local_6c[1],local_6c[2]);
          puVar13 = (uint *)(local_54[0x10] + (int)local_2c * 4);
          goto switchD_6815fd70_default;
        case 0x76:
          goto switchD_6815fd70_default;
        case 0x77:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          local_30 = (undefined **)((uint)local_88 & 7);
          local_ac = (undefined **)((uint)local_34 & 7);
          if (local_30 == local_ac) {
            if (local_30 == (undefined **)0x4) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(iVar16 == 0);
            }
            else if (local_30 == (undefined **)0x2) {
              dVar3 = *(double *)((uint)local_88 & 0xfffffff8);
              dVar4 = *(double *)((uint)local_34 & 0xfffffff8);
              (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc != 0 ||
                   (((ulonglong)dVar3 & 0xfffff00000000) != 0)))) ||
                 (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar4 >> 0x20),
                  ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar4,0), (int)local_7c != 0 ||
                   (((ulonglong)dVar4 & 0xfffff00000000) != 0)))))) {
                local_3f0 = 0;
              }
              else {
                local_3ec = (uint)(dVar4 == dVar3);
                local_3f0 = local_3ec;
              }
              local_70 = local_3f0;
              local_cc = dVar3;
              local_7c = dVar4;
            }
            else {
              local_70 = (uint)(local_88 == local_34);
            }
          }
          else if (((local_30 == (undefined **)0x2) && (((uint)local_34 & 1) != 0)) &&
                  (local_34 != (undefined **)0x80000001)) {
            dVar3 = *(double *)((uint)local_88 & 0xfffffff8);
            dVar4 = (double)((int)local_34 >> 1);
            (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
            if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc != 0 ||
                 (((ulonglong)dVar3 & 0xfffff00000000) != 0)))) ||
               (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar4 >> 0x20),
                ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar4,0), (int)local_7c != 0 ||
                 (((ulonglong)dVar4 & 0xfffff00000000) != 0)))))) {
              local_3fc = 0;
            }
            else {
              local_3f8 = (uint)(dVar4 == dVar3);
              local_3fc = local_3f8;
            }
            local_70 = local_3fc;
            local_cc = dVar3;
            local_7c = dVar4;
          }
          else if (((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) ||
                  (local_ac != (undefined **)0x2)) {
            local_70 = (uint)(local_88 == local_34);
          }
          else {
            dVar4 = (double)((int)local_88 >> 1);
            dVar3 = *(double *)((uint)local_34 & 0xfffffff8);
            (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar4 >> 0x20);
            if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar4,0), (int)local_cc != 0 ||
                 (((ulonglong)dVar4 & 0xfffff00000000) != 0)))) ||
               (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar3 >> 0x20),
                ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar3,0), (int)local_7c != 0 ||
                 (((ulonglong)dVar3 & 0xfffff00000000) != 0)))))) {
              local_408 = 0;
            }
            else {
              local_404 = (uint)(dVar3 == dVar4);
              local_408 = local_404;
            }
            local_70 = local_408;
            local_cc = dVar4;
            local_7c = dVar3;
          }
          local_38[-2 - local_f8] = (uint)local_6c;
          local_38[-2] = local_70 << 3 | 6;
          puVar13 = local_38 + -2;
          pbVar18 = local_24;
          if (local_70 == 0) {
            *puVar13 = (uint)local_88;
            puVar13 = local_38 + -1;
            goto switchD_6815fd70_default;
          }
          local_8c = (uint)CONCAT11(local_6c[1],local_6c[2]);
          if ((0 < (int)local_8c) || (local_90 == (code *)0x0)) goto switchD_6815fd70_default;
          local_54[0xf] = puVar13;
          local_38 = puVar13;
          local_3c = (*local_90)(param_1,local_98);
          goto joined_r0x681556b3;
        case 0x78:
          local_38 = local_38 + -1;
switchD_681552c9_caseD_6:
          local_8c = (uint)CONCAT11(local_6c[1],local_6c[2]);
          puVar13 = local_38;
          if ((0 < (int)local_8c) || (local_90 == (code *)0x0)) goto switchD_6815fd70_default;
          local_54[0xf] = local_38;
          local_3c = (*local_90)(param_1,local_98);
          goto joined_r0x681556b3;
        case 0x7a:
          local_c = local_38[-1];
          if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
            local_54[0xf] = local_38;
            local_f4 = js_resolveAtom((int)param_1,local_c);
            uVar12 = local_f4;
            if (local_f4 == 0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          else {
            local_f4 = 0;
            uVar12 = local_c;
          }
          local_c = uVar12;
          local_88 = (undefined **)local_38[-2];
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
          local_34 = (undefined **)local_38[-3];
          local_54[0xf] = local_38;
          if ((*(undefined ***)(*local_d8 + 4) == &PTR_FUN_68192948) ||
             ((*(int *)(*local_d8 + 4) != 0 &&
              ((undefined *)**(int **)(*local_d8 + 4) == PTR_FUN_68192948)))) {
            local_2b8 = ((uint)local_d8 >> 3 ^ local_c) & 0x3ff;
            local_2b4 = local_9c + 0x248;
            local_2ac = (undefined4 *)(local_2b4 + local_2b8 * 8);
            local_2c0 = (undefined **)*local_2ac;
            local_2bc = (uint *)local_2ac[1];
            if ((local_2bc == (uint *)0x0) ||
               ((local_2c0 != local_d8 || (local_a8 = local_2bc, *local_2bc != local_c)))) {
              local_a8 = (uint *)0x0;
            }
            local_2b0 = local_2bc;
            if (((local_a8 == (uint *)0x0) || ((local_a8[4] & 2) != 0)) ||
               (local_2a8 = *local_d8, (*(ushort *)(local_2a8 + 0x14) & 2) != 0)) {
              local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))
                                   (param_1,local_d8,local_c,&local_34);
            }
            else {
              if ((local_a8[4] & 0x20) == 0) {
                if ((local_a8[4] & 0x10) == 0) {
                  if (local_a8[2] == 0) {
LAB_6815dd6f:
                    local_608 = 1;
                  }
                  else {
                    if ((*(byte *)((int)local_a8 + 0x11) & 8) == 0) {
                      if ((*local_a8 & 1) == 0) {
                        local_600 = *(uint *)(*local_a8 + 8);
                      }
                      else {
                        local_600 = *local_a8;
                      }
                      local_5fc = local_600;
                    }
                    else {
                      local_5fc = (int)*(short *)((int)local_a8 + 0x12) << 1 | 1;
                    }
                    if (*(int *)(*(int *)(*local_d8 + 4) + 0x30) == 0) {
                      local_604 = local_d8;
                    }
                    else {
                      local_604 = (undefined **)
                                  (**(code **)(*(int *)(*local_d8 + 4) + 0x30))(param_1,local_d8);
                    }
                    iVar16 = (*(code *)local_a8[2])(param_1,local_604,local_5fc,&local_34);
                    if (iVar16 != 0) goto LAB_6815dd6f;
                    local_608 = 0;
                  }
                  local_5f8 = local_608;
                }
                else {
                  xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0xa0);
                  local_5f8 = 0;
                }
                local_5f4 = local_5f8;
              }
              else {
                local_5f4 = certs_processKeyUsage((int)param_1,local_d8,*local_a8,local_a8[2],8,1,&local_34,
                                         &local_34);
              }
              local_3c = local_5f4;
              if ((local_5f4 != 0) && (local_a8[3] < *(uint *)(local_2a8 + 0xc))) {
                *(undefined ***)(local_d8[1] + local_a8[3] * 4) = local_34;
                *(undefined1 *)(*(int *)(param_1 + 10) + 0x60) = 1;
              }
            }
          }
          else {
            local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))
                                 (param_1,local_d8,local_c,&local_34);
          }
          if (local_3c == 0) goto LAB_681612b1;
          puVar13 = local_38 + -3;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x7b:
        case 0x7c:
          pbVar18 = local_6c + 1;
          local_94 = (uint)*pbVar18;
          local_60 = &PTR_DAT_68193cb0 + local_94 * 4;
          local_8c = (uint)(char)(&DAT_68193cb8)[local_94 * 0x10];
          switch(local_94) {
          case 0x36:
          case 0x6d:
            pbVar1 = local_6c + 2;
            pbVar2 = local_6c + 3;
            local_6c = pbVar18;
            local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(*pbVar1,*pbVar2));
            local_2c = (byte *)0xffffffff;
            local_34 = (undefined **)local_38[-1];
            uVar12 = local_f4;
            break;
          default:
            goto switchD_681607a2_caseD_37;
          case 0x38:
            local_34 = (undefined **)local_38[-1];
            local_2c = (byte *)0xfffffffe;
            local_c = local_38[-2];
            if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
              local_54[0xf] = local_38;
              local_6c = pbVar18;
              local_f4 = js_resolveAtom((int)param_1,local_c);
              uVar12 = local_f4;
              if (local_f4 == 0) {
                local_3c = 0;
                goto LAB_681612b1;
              }
            }
            else {
              local_f4 = 0;
              local_6c = pbVar18;
              uVar12 = local_c;
            }
            break;
          case 0x5b:
            local_2c = (byte *)0xffffffff;
            local_34 = (undefined **)local_38[-1];
            pbVar1 = local_6c + 2;
            pbVar2 = local_6c + 3;
            local_6c = pbVar18;
            local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(*pbVar1,*pbVar2));
            uVar12 = local_f4;
            goto LAB_6816099f;
          case 0x5c:
            local_34 = (undefined **)local_38[-1];
            local_2c = (byte *)0xfffffffe;
            local_c = local_38[-2];
            if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
              local_54[0xf] = local_38;
              local_6c = pbVar18;
              local_f4 = js_resolveAtom((int)param_1,local_c);
              uVar12 = local_f4;
              if (local_f4 == 0) {
                local_3c = 0;
                goto LAB_681612b1;
              }
            }
            else {
              local_f4 = 0;
              local_6c = pbVar18;
              uVar12 = local_c;
            }
LAB_6816099f:
            local_c = uVar12;
            local_88 = (undefined **)local_38[(int)(local_2c + -1)];
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
            pbVar18 = local_6c;
            goto switchD_681607a2_caseD_37;
          }
          local_c = uVar12;
          local_88 = (undefined **)local_38[(int)(local_2c + -1)];
          if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
            local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
            pbVar18 = local_6c;
          }
          else {
            local_54[0xf] = local_38;
            local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
            pbVar18 = local_6c;
            if (local_d8 == (undefined **)0x0) {
              local_3c = 0;
              goto LAB_681612b1;
            }
          }
switchD_681607a2_caseD_37:
          local_6c = pbVar18;
          bVar11 = xtra_lookupHashByte(param_1,(uint)local_34);
          if (CONCAT31(extraout_var_02,bVar11) != 2) {
            xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x97);
            local_3c = 0;
            goto LAB_681612b1;
          }
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x2c))
                               (param_1,local_d8,local_c,3,&local_ac,&local_4c);
          if (local_3c == 0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          if (local_dc == 0x7b) {
            local_64 = (uint)local_34 & 0xfffffff8;
            local_e4 = 0;
            local_4c = 0x10;
          }
          else {
            local_64 = 0;
            local_e4 = (uint)local_34 & 0xfffffff8;
            local_4c = 0x20;
          }
          local_4c = local_4c | 0x41;
          local_3c = certs_verifySignature(param_1,(int *)local_d8,local_c,local_4c,&local_70);
          if (local_3c == 0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0xc))
                               (param_1,local_d8,local_c,0x80000001,local_64,local_e4,local_4c,0);
          if (local_3c == 0) goto LAB_681612b1;
          puVar13 = local_38 + (int)local_2c;
          pbVar18 = local_24;
          if (*(char *)((int)local_60 + 10) != '\0') {
            puVar13[-1 - local_f8] = (uint)local_6c;
            puVar13[-1] = (uint)local_34;
          }
          goto switchD_6815fd70_default;
        case 0x7d:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_d8 = (undefined **)(*(uint *)(local_f4 + 8) & 0xfffffff8);
          local_18 = xtra_getObjectTag(param_1,(int)local_d8);
          local_c = *(uint *)(local_18 + 0x18);
          local_84 = (int *)local_54[0xd];
          if (((int *)(*(uint *)(local_d8[1] + 4) & 0xfffffff8) != local_84) &&
             (local_d8 = (undefined **)runtime_lookupFunction((int)param_1,local_d8,(uint)local_84),
             local_d8 == (undefined **)0x0)) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          local_4c = 1;
          if ((local_54[0x13] & 8) == 0) {
            local_4c = 5;
          }
          local_300 = *(byte *)(local_18 + 0x16) & 0x30;
          if ((*(byte *)(local_18 + 0x16) & 0x30) != 0) {
            local_4c = local_300 | 0x40 | local_4c;
          }
          local_84 = (int *)local_54[2];
          local_3c = certs_verifySignature(param_1,local_84,local_c,local_4c,&local_70);
          if (local_3c == 0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          if (local_300 == 0) {
            local_654 = local_d8;
          }
          else {
            local_654 = (undefined **)0x80000001;
          }
          local_3c = (**(code **)(*(int *)(*local_84 + 4) + 0xc))
                               (param_1,local_84,local_c,local_654,
                                -(uint)((local_300 & 0x10) != 0) & (uint)local_d8,
                                -(uint)((local_300 & 0x20) != 0) & (uint)local_d8,local_4c,0);
          goto joined_r0x681556b3;
        case 0x7e:
        case 0x7f:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_d8 = (undefined **)local_54[2];
          local_4c = 1;
          if ((local_54[0x13] & 8) == 0) {
            local_4c = 5;
          }
          if (local_dc == 0x7e) {
            local_4c = local_4c | 2;
          }
          local_c = local_f4;
          local_3c = certs_verifySignature(param_1,(int *)local_d8,local_f4,local_4c,&local_2fc);
          if (local_3c == 0) goto LAB_681612b1;
          puVar13 = local_38;
          pbVar18 = local_24;
          if (local_2fc != 0) goto switchD_6815fd70_default;
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0xc))
                               (param_1,local_d8,local_c,0x80000001,0,0,local_4c,0);
          goto joined_r0x681556b3;
        case 0x80:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_d8 = (undefined **)(*(uint *)(local_f4 + 8) & 0xfffffff8);
          local_84 = (int *)local_54[0xd];
          if (((int *)(*(uint *)(local_d8[1] + 4) & 0xfffffff8) != local_84) &&
             (local_d8 = (undefined **)runtime_lookupFunction((int)param_1,local_d8,(uint)local_84),
             local_d8 == (undefined **)0x0)) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_d8;
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x81:
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_34 = *(undefined ***)(local_f4 + 8);
          local_54[0xf] = local_38;
          local_84 = runtime_createPropertyFromName((uint)param_1,&PTR_s_Object_681929a8,(undefined4 *)0x0,
                                  local_54[0xd],0,0);
          if (local_84 == (int *)0x0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          local_d8 = (undefined **)
                     runtime_lookupFunction((int)param_1,(undefined4 *)((uint)local_34 & 0xfffffff8),
                                  (uint)local_84);
          if (local_d8 == (undefined **)0x0) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          local_18 = xtra_getObjectTag(param_1,(int)local_d8);
          local_4c = *(byte *)(local_18 + 0x16) & 0x30;
          if ((*(byte *)(local_18 + 0x16) & 0x30) != 0) {
            local_4c = local_4c | 0x40;
          }
          if (local_4c == 0) {
            local_658 = local_d8;
          }
          else {
            local_658 = (undefined **)0x80000001;
          }
          local_3c = (**(code **)(*(int *)(*local_84 + 4) + 0xc))
                               (param_1,local_84,*(undefined4 *)(local_18 + 0x18),local_658,
                                -(uint)((local_4c & 0x10) != 0) & (uint)local_d8,
                                -(uint)((local_4c & 0x20) != 0) & (uint)local_d8,local_4c | 7,0);
          if (local_3c != 0) {
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = (uint)local_d8;
            puVar13 = local_38 + 1;
            pbVar18 = local_24;
            goto switchD_6815fd70_default;
          }
          param_1[0x48] = 0;
          param_1[0x49] = 0;
          goto LAB_681612b1;
        case 0x82:
          local_38 = local_38 + -1;
          local_34 = (undefined **)*local_38;
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[1],local_6c[2]));
          local_88 = (undefined **)local_38[-1];
          local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
          local_c = local_f4;
          local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0xc))
                               (param_1,local_d8,local_f4,local_34,0,0,4,0);
          goto joined_r0x681556b3;
        case 0x83:
          local_d8 = (undefined **)0x0;
          goto switchD_6815fd70_default;
        case 0x84:
          local_1c = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_54[0xf] = local_38;
          local_3c = certs_verifyChain((uint)param_1,local_1c,0);
          local_38 = (uint *)local_54[0xf];
          if (local_3c == 0) goto LAB_681612b1;
          if ((char)param_1[0xac] != '\0') {
            local_38[-local_f8] = (uint)local_6c;
            *local_38 = *(uint *)(param_1 + 0xaa);
            *(undefined1 *)(param_1 + 0xac) = 0;
            local_d8 = (undefined **)0x0;
            puVar13 = local_38 + 1;
            pbVar18 = local_24;
            goto switchD_6815fd70_default;
          }
          xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x81);
          local_3c = 0;
          goto LAB_681612b1;
        case 0x85:
        case 0x86:
          *(undefined1 *)(param_1 + 0xb0) = 1;
          goto switchD_6815fd70_default;
        case 0x87:
          local_30 = (undefined **)local_38[-1];
          local_38[-1] = local_38[-2];
          local_38[-2] = (uint)local_30;
          goto switchD_6815fd70_default;
        case 0x88:
          local_c = (uint)CONCAT11(local_6c[1],local_6c[2]) << 1 | 1;
          local_54[0xf] = local_38;
          local_3c = runtime_enumerateProperties((uint)param_1,local_54,local_c,&local_d8,(uint *)&local_34);
          if (local_3c == 0) goto LAB_681612b1;
          if (local_d8 == (undefined **)0x0) {
            local_d8 = (undefined **)0x1;
          }
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_34;
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x89:
          local_c = *(uint *)(local_9c + 0x108);
          local_54[0xf] = local_38;
          local_3c = runtime_enumerateProperties((uint)param_1,local_54,local_c,&local_d8,(uint *)&local_34);
          if (local_3c == 0) goto LAB_681612b1;
          local_38[-local_f8] = (uint)local_6c;
          *local_38 = (uint)local_34;
          puVar13 = local_38 + 1;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x8a:
          local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
          local_24 = local_6c + 2;
          local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_6c[3],local_6c[4]));
          local_d8 = (undefined **)(*(uint *)(local_f4 + 8) & 0xfffffff8);
          local_18 = xtra_getObjectTag(param_1,(int)local_d8);
          local_84 = (int *)local_54[0xd];
          if (((int *)(*(uint *)(local_d8[1] + 4) & 0xfffffff8) != local_84) &&
             (local_d8 = (undefined **)runtime_lookupFunction((int)param_1,local_d8,(uint)local_84),
             local_d8 == (undefined **)0x0)) {
            local_3c = 0;
            goto LAB_681612b1;
          }
          *(undefined ***)(local_54[10] + local_b4 * 4) = local_d8;
          puVar13 = local_38;
          pbVar18 = local_24;
          goto switchD_6815fd70_default;
        case 0x8b:
          goto switchD_681552c9_caseD_8b;
        case 0x8c:
          local_34 = (undefined **)local_38[-1];
          if (local_34 == (undefined **)0x0) {
            local_70 = 0;
          }
          else if (((uint)local_34 & 7) == 6) {
            local_70 = (int)local_34 >> 3;
          }
          else {
            local_54[0xf] = local_38;
            local_3c = js_getDateComponent((int)param_1,(uint)local_34,&local_70);
            if (local_3c == 0) goto LAB_681612b1;
          }
          local_38 = local_38 + -1;
          puVar13 = local_38;
          pbVar18 = local_24;
          if (((local_70 != 0) ||
              (local_8c = (uint)local_6c[1] << 0x18 | (uint)local_6c[2] << 0x10 |
                          (uint)local_6c[3] << 8 | (uint)local_6c[4], 0 < (int)local_8c)) ||
             (local_90 == (code *)0x0)) goto switchD_6815fd70_default;
          local_54[0xf] = local_38;
          local_3c = (*local_90)(param_1,local_98);
          goto joined_r0x681556b3;
        case 0x8d:
          local_34 = (undefined **)local_38[-1];
          if (local_34 == (undefined **)0x0) {
            local_70 = 0;
          }
          else if (((uint)local_34 & 7) == 6) {
            local_70 = (int)local_34 >> 3;
          }
          else {
            local_54[0xf] = local_38;
            local_3c = js_getDateComponent((int)param_1,(uint)local_34,&local_70);
            if (local_3c == 0) goto LAB_681612b1;
          }
          local_38 = local_38 + -1;
          puVar13 = local_38;
          pbVar18 = local_24;
          if (((local_70 == 0) ||
              (local_8c = (uint)local_6c[1] << 0x18 | (uint)local_6c[2] << 0x10 |
                          (uint)local_6c[3] << 8 | (uint)local_6c[4], 0 < (int)local_8c)) ||
             (local_90 == (code *)0x0)) goto switchD_6815fd70_default;
          local_54[0xf] = local_38;
          local_3c = (*local_90)(param_1,local_98);
          goto joined_r0x681556b3;
        case 0x8e:
          local_34 = (undefined **)local_38[-1];
          if (local_34 == (undefined **)0x0) {
            local_70 = 0;
          }
          else if (((uint)local_34 & 7) == 6) {
            local_70 = (int)local_34 >> 3;
          }
          else {
            local_54[0xf] = local_38;
            local_3c = js_getDateComponent((int)param_1,(uint)local_34,&local_70);
            if (local_3c == 0) goto LAB_681612b1;
          }
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          if (local_70 == 1) {
            bVar11 = local_6c[1];
            bVar5 = local_6c[2];
            bVar6 = local_6c[3];
            bVar7 = local_6c[4];
            puVar13[-local_f8] = (uint)local_6c;
            *puVar13 = (uint)local_34;
            local_8c = (uint)bVar11 << 0x18 | (uint)bVar5 << 0x10 | (uint)bVar6 << 8 | (uint)bVar7;
            puVar13 = local_38;
          }
          goto switchD_6815fd70_default;
        case 0x8f:
          local_34 = (undefined **)local_38[-1];
          if (local_34 == (undefined **)0x0) {
            local_70 = 0;
          }
          else if (((uint)local_34 & 7) == 6) {
            local_70 = (int)local_34 >> 3;
          }
          else {
            local_54[0xf] = local_38;
            local_3c = js_getDateComponent((int)param_1,(uint)local_34,&local_70);
            if (local_3c == 0) goto LAB_681612b1;
          }
          puVar13 = local_38 + -1;
          pbVar18 = local_24;
          if (local_70 == 0) {
            bVar11 = local_6c[1];
            bVar5 = local_6c[2];
            bVar6 = local_6c[3];
            bVar7 = local_6c[4];
            puVar13[-local_f8] = (uint)local_6c;
            *puVar13 = (uint)local_34;
            local_8c = (uint)bVar11 << 0x18 | (uint)bVar5 << 0x10 | (uint)bVar6 << 8 | (uint)bVar7;
            puVar13 = local_38;
          }
          goto switchD_6815fd70_default;
        case 0x90:
          local_2c = local_6c + (local_8c - local_98[2]);
          bVar11 = local_6c[1];
          bVar5 = local_6c[2];
          bVar6 = local_6c[3];
          bVar7 = local_6c[4];
          *local_38 = (int)local_2c * 2 | 1;
          local_8c = (uint)bVar11 << 0x18 | (uint)bVar5 << 0x10 | (uint)bVar6 << 8 | (uint)bVar7;
          puVar13 = local_38 + 1;
          goto switchD_6815fd70_default;
        case 0x91:
          local_34 = (undefined **)local_38[-1];
          local_88 = (undefined **)local_38[-2];
          local_30 = (undefined **)((uint)local_88 & 7);
          local_ac = (undefined **)((uint)local_34 & 7);
          if (local_30 == local_ac) {
            if (local_30 == (undefined **)0x4) {
              local_ec = (uint *)((uint)local_88 & 0xfffffff8);
              local_bc = (uint *)((uint)local_34 & 0xfffffff8);
              iVar16 = certs_compareStrings(local_ec,local_bc);
              local_70 = (uint)(iVar16 == 0);
            }
            else if (local_30 == (undefined **)0x2) {
              dVar3 = *(double *)((uint)local_88 & 0xfffffff8);
              dVar4 = *(double *)((uint)local_34 & 0xfffffff8);
              (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
              if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                  (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc != 0 ||
                   (((ulonglong)dVar3 & 0xfffff00000000) != 0)))) ||
                 (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar4 >> 0x20),
                  ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                  (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar4,0), (int)local_7c != 0 ||
                   (((ulonglong)dVar4 & 0xfffff00000000) != 0)))))) {
                local_410 = 0;
              }
              else {
                local_40c = (uint)(dVar4 == dVar3);
                local_410 = local_40c;
              }
              local_70 = local_410;
              local_cc = dVar3;
              local_7c = dVar4;
            }
            else {
              local_70 = (uint)(local_88 == local_34);
            }
          }
          else if (((local_30 == (undefined **)0x2) && (((uint)local_34 & 1) != 0)) &&
                  (local_34 != (undefined **)0x80000001)) {
            dVar3 = *(double *)((uint)local_88 & 0xfffffff8);
            dVar4 = (double)((int)local_34 >> 1);
            (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar3 >> 0x20);
            if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar3,0), (int)local_cc != 0 ||
                 (((ulonglong)dVar3 & 0xfffff00000000) != 0)))) ||
               (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar4 >> 0x20),
                ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar4,0), (int)local_7c != 0 ||
                 (((ulonglong)dVar4 & 0xfffff00000000) != 0)))))) {
              local_41c = 0;
            }
            else {
              local_418 = (uint)(dVar4 == dVar3);
              local_41c = local_418;
            }
            local_70 = local_41c;
            local_cc = dVar3;
            local_7c = dVar4;
          }
          else if (((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) ||
                  (local_ac != (undefined **)0x2)) {
            local_70 = (uint)(local_88 == local_34);
          }
          else {
            dVar4 = (double)((int)local_88 >> 1);
            dVar3 = *(double *)((uint)local_34 & 0xfffffff8);
            (*(unsigned int *)((char *)&local_cc + 4)) = (uint)((ulonglong)dVar4 >> 0x20);
            if (((((*(unsigned int *)((char *)&local_cc + 4)) & 0x7ff00000) == 0x7ff00000) &&
                (((*(unsigned int *)((char *)&local_cc + 0)) = SUB84(dVar4,0), (int)local_cc != 0 ||
                 (((ulonglong)dVar4 & 0xfffff00000000) != 0)))) ||
               (((*(unsigned int *)((char *)&local_7c + 4)) = (uint)((ulonglong)dVar3 >> 0x20),
                ((*(unsigned int *)((char *)&local_7c + 4)) & 0x7ff00000) == 0x7ff00000 &&
                (((*(unsigned int *)((char *)&local_7c + 0)) = SUB84(dVar3,0), (int)local_7c != 0 ||
                 (((ulonglong)dVar3 & 0xfffff00000000) != 0)))))) {
              local_428 = 0;
            }
            else {
              local_424 = (uint)(dVar3 == dVar4);
              local_428 = local_424;
            }
            local_70 = local_428;
            local_cc = dVar4;
            local_7c = dVar3;
          }
          local_38[-2 - local_f8] = (uint)local_6c;
          local_38[-2] = local_70 << 3 | 6;
          puVar13 = local_38 + -2;
          pbVar18 = local_24;
          if (local_70 == 0) {
            *puVar13 = (uint)local_88;
            puVar13 = local_38 + -1;
            goto switchD_6815fd70_default;
          }
          local_8c = (uint)local_6c[1] << 0x18 | (uint)local_6c[2] << 0x10 | (uint)local_6c[3] << 8
                     | (uint)local_6c[4];
          if ((0 < (int)local_8c) || (local_90 == (code *)0x0)) goto switchD_6815fd70_default;
          local_54[0xf] = puVar13;
          local_38 = puVar13;
          local_3c = (*local_90)(param_1,local_98);
          goto joined_r0x681556b3;
        case 0x92:
          local_38 = local_38 + -1;
switchD_681552c9_caseD_8b:
          local_8c = (uint)local_6c[1] << 0x18 | (uint)local_6c[2] << 0x10 | (uint)local_6c[3] << 8
                     | (uint)local_6c[4];
          puVar13 = local_38;
          if ((0 < (int)local_8c) || (local_90 == (code *)0x0)) goto switchD_6815fd70_default;
          local_54[0xf] = local_38;
          local_3c = (*local_90)(param_1,local_98);
          goto joined_r0x681556b3;
        case 0x93:
          local_24 = local_6c;
          local_8c = (uint)local_6c[1] << 0x18 | (uint)local_6c[2] << 0x10 | (uint)local_6c[3] << 8
                     | (uint)local_6c[4];
          if ((*(int *)(param_1 + 6) == 0) || (0x8b < *(int *)(param_1 + 6))) {
            local_38 = local_38 + -1;
            local_34 = (undefined **)*local_38;
            puVar13 = local_38;
            pbVar18 = local_24;
            if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001))
            goto switchD_6815fd70_default;
            local_2c = (byte *)((int)local_34 >> 1);
          }
          else {
            local_2f8 = local_38[-1];
            if (((local_2f8 & 1) == 0) || (local_2f8 == 0x80000001)) {
              local_54[0xf] = local_38;
              local_3c = runtime_parseInt(param_1,local_2f8,&local_2c);
              if (local_3c == 0) goto LAB_681612b1;
            }
            else {
              local_2c = (byte *)((int)local_2f8 >> 1);
            }
            local_38 = local_38 + -1;
          }
          local_c4 = (int)CONCAT11(local_24[5],local_24[6]);
          local_14 = (int)CONCAT11(local_24[7],local_24[8]);
          local_2c = local_2c + -local_c4;
          puVar13 = local_38;
          pbVar18 = local_24 + 6;
          if (local_2c < (byte *)((local_14 - local_c4) + 1)) {
            pbVar18 = local_24 + (int)local_2c * 4 + 8;
            local_58 = (uint)pbVar18[1] << 0x18 | (uint)pbVar18[2] << 0x10 | (uint)pbVar18[3] << 8 |
                       (uint)pbVar18[4];
            if (local_58 != 0) {
              local_8c = local_58;
            }
          }
          goto switchD_6815fd70_default;
        case 0x94:
          local_38 = local_38 + -1;
          local_88 = (undefined **)*local_38;
          local_24 = local_6c;
          local_8c = (uint)local_6c[1] << 0x18 | (uint)local_6c[2] << 0x10 | (uint)local_6c[3] << 8
                     | (uint)local_6c[4];
          if ((((((uint)local_88 & 1) == 0) || (local_88 == (undefined **)0x80000001)) &&
              (((uint)local_88 & 7) != 2)) &&
             ((((uint)local_88 & 7) != 4 &&
              (puVar13 = local_38, pbVar18 = local_24, ((uint)local_88 & 7) != 6))))
          goto switchD_6815fd70_default;
          local_8 = (uint)CONCAT11(local_6c[5],local_6c[6]);
          local_24 = local_6c + 6;
          if (((uint)local_88 & 7) == 4) {
            local_ec = (uint *)((uint)local_88 & 0xfffffff8);
            goto LAB_6815f501;
          }
          if (((uint)local_88 & 7) != 2) goto LAB_6815f714;
          local_cc = *(double *)((uint)local_88 & 0xfffffff8);
          goto LAB_6815f629;
        default:
          runtime_snprintf(local_32c,0xc,"%d");
          xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x20);
          local_3c = 0;
          goto LAB_681612b1;
        case 0x98:
          local_54[8] = local_38[-1];
          puVar13 = local_38 + -1;
          goto switchD_6815fd70_default;
        case 0x99:
switchD_681552c9_caseD_99:
          if (local_50 == 0) goto LAB_681612b1;
          goto LAB_681554bc;
        }
        if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) {
          if (((uint)local_34 & 7) == 2) {
            local_cc = *(double *)((uint)local_34 & 0xfffffff8);
          }
          else {
            local_54[0xf] = local_38;
            local_3c = runtime_parseNumber(param_1,(uint)local_34,(double *)&local_cc);
            if (local_3c == 0) goto LAB_681612b1;
          }
        }
        else {
          local_cc = (double)((int)local_34 >> 1);
        }
        if (((uint)local_60[3] & 0x400) == 0) {
          if (((uint)local_60[3] & 0x200) == 0) {
            local_cc = local_cc - 1.0;
          }
          else {
            local_cc = local_cc + 1.0;
          }
          local_3c = runtime_convertToNumber((uint)local_60[3] & 0x200,&local_34,(int)param_1,SUB84(local_cc,0)
                                  ,(uint)((ulonglong)local_cc >> 0x20),(uint *)&local_34);
          local_ac = local_34;
        }
        else {
          local_ac = local_34;
          if ((((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) &&
              (((uint)local_34 & 7) != 2)) &&
             (local_3c = runtime_convertToNumber(param_1,(uint)local_34 & 7,(int)param_1,SUB84(local_cc,0),
                                      (uint)((ulonglong)local_cc >> 0x20),(uint *)&local_ac),
             local_3c == 0)) goto LAB_681612b1;
          if (((uint)local_60[3] & 0x200) == 0) {
            local_cc = local_cc - 1.0;
          }
          else {
            local_cc = local_cc + 1.0;
          }
          local_3c = runtime_convertToNumber(&local_34,param_1,(int)param_1,SUB84(local_cc,0),
                                  (uint)((ulonglong)local_cc >> 0x20),(uint *)&local_34);
        }
        if (local_3c == 0) goto LAB_681612b1;
        *local_b0 = (uint)local_34;
        local_38[-local_f8] = (uint)local_6c;
        *local_38 = (uint)local_ac;
        puVar13 = local_38 + 1;
        pbVar18 = local_24;
        goto switchD_6815fd70_default;
      }
    }
  } while( true );
LAB_6815f501:
  puVar13 = local_38;
  pbVar18 = local_24;
  if (local_8 == 0) goto switchD_6815fd70_default;
  local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_24[1],local_24[2]));
  local_34 = *(undefined ***)(local_f4 + 8);
  if ((((uint)local_34 & 7) == 4) &&
     ((local_bc = (uint *)((uint)local_34 & 0xfffffff8), local_bc == local_ec ||
      (iVar16 = certs_compareStrings(local_bc,local_ec), iVar16 == 0)))) {
    local_648 = 1;
  }
  else {
    local_648 = 0;
  }
  local_b8 = local_648;
  if (local_648 != 0) {
    local_8c = (uint)local_24[3] << 0x18 | (uint)local_24[4] << 0x10 | (uint)local_24[5] << 8 |
               (uint)local_24[6];
    puVar13 = local_38;
    pbVar18 = local_24 + 2;
    goto switchD_6815fd70_default;
  }
  local_24 = local_24 + 6;
  local_8 = local_8 - 1;
  goto LAB_6815f501;
LAB_6815f714:
  puVar13 = local_38;
  pbVar18 = local_24;
  if (local_8 == 0) goto switchD_6815fd70_default;
  local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_24[1],local_24[2]));
  local_34 = *(undefined ***)(local_f4 + 8);
  local_b8 = (uint)(local_88 == local_34);
  if (local_b8 != 0) {
    local_8c = (uint)local_24[3] << 0x18 | (uint)local_24[4] << 0x10 | (uint)local_24[5] << 8 |
               (uint)local_24[6];
    puVar13 = local_38;
    pbVar18 = local_24 + 2;
    goto switchD_6815fd70_default;
  }
  local_24 = local_24 + 6;
  local_8 = local_8 - 1;
  goto LAB_6815f714;
LAB_6815f629:
  puVar13 = local_38;
  pbVar18 = local_24;
  if (local_8 == 0) goto switchD_6815fd70_default;
  local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_24[1],local_24[2]));
  local_34 = *(undefined ***)(local_f4 + 8);
  if ((((uint)local_34 & 7) == 2) && (local_cc == *(double *)((uint)local_34 & 0xfffffff8))) {
    local_64c = 1;
  }
  else {
    local_64c = 0;
  }
  local_b8 = local_64c;
  if (local_64c != 0) {
    local_8c = (uint)local_24[3] << 0x18 | (uint)local_24[4] << 0x10 | (uint)local_24[5] << 8 |
               (uint)local_24[6];
    puVar13 = local_38;
    pbVar18 = local_24 + 2;
    goto switchD_6815fd70_default;
  }
  local_24 = local_24 + 6;
  local_8 = local_8 - 1;
  goto LAB_6815f629;
switchD_6815fd70_caseD_1:
  local_dc = (int)local_34 >> 1;
  goto LAB_681551dd;
LAB_6815f82b:
  if ((int)local_e8 <= (int)local_2c) goto LAB_6815f92d;
  local_c = local_d0[(int)(local_2c + 1)];
  local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 8))
                       (param_1,local_d8,local_c,&local_44,&local_f0);
  if (local_3c == 0) goto LAB_6815f92d;
  if (local_f0 != (uint *)0x0) {
    local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x18))
                         (param_1,local_d8,local_c,local_f0,&local_4c);
    if (local_3c != 0) {
      local_4c = local_4c | 8;
      local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x1c))
                           (param_1,local_d8,local_c,local_f0,&local_4c);
    }
    if (*(int *)(*(int *)(*local_44 + 4) + 0x34) != 0) {
      (**(code **)(*(int *)(*local_44 + 4) + 0x34))(param_1,local_44,local_f0);
    }
    if (local_3c == 0) goto LAB_6815f92d;
  }
  local_2c = local_2c + 1;
  goto LAB_6815f82b;
LAB_6815f92d:
  xtra_flushAndCheck(param_1,(int)local_d0);
  puVar13 = local_38;
  pbVar18 = local_24;
  goto switchD_6815fd70_default;
LAB_6815f004:
  puVar13 = local_38;
  pbVar18 = local_24;
  if (local_8 == 0) goto switchD_6815fd70_default;
  local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_24[1],local_24[2]));
  local_34 = *(undefined ***)(local_f4 + 8);
  if ((((uint)local_34 & 7) == 4) &&
     ((local_bc = (uint *)((uint)local_34 & 0xfffffff8), local_bc == local_ec ||
      (iVar16 = certs_compareStrings(local_bc,local_ec), iVar16 == 0)))) {
    local_640 = 1;
  }
  else {
    local_640 = 0;
  }
  local_b8 = local_640;
  if (local_640 != 0) {
    local_8c = (int)CONCAT11(local_24[3],local_24[4]);
    puVar13 = local_38;
    pbVar18 = local_24 + 2;
    goto switchD_6815fd70_default;
  }
  local_24 = local_24 + 4;
  local_8 = local_8 - 1;
  goto LAB_6815f004;
LAB_6815f1ed:
  puVar13 = local_38;
  pbVar18 = local_24;
  if (local_8 == 0) goto switchD_6815fd70_default;
  local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_24[1],local_24[2]));
  local_34 = *(undefined ***)(local_f4 + 8);
  local_b8 = (uint)(local_88 == local_34);
  if (local_b8 != 0) {
    local_8c = (int)CONCAT11(local_24[3],local_24[4]);
    puVar13 = local_38;
    pbVar18 = local_24 + 2;
    goto switchD_6815fd70_default;
  }
  local_24 = local_24 + 4;
  local_8 = local_8 - 1;
  goto LAB_6815f1ed;
LAB_6815f117:
  puVar13 = local_38;
  pbVar18 = local_24;
  if (local_8 == 0) goto switchD_6815fd70_default;
  local_f4 = js_allocAtom(param_1,local_98 + 4,(uint)CONCAT11(local_24[1],local_24[2]));
  local_34 = *(undefined ***)(local_f4 + 8);
  if ((((uint)local_34 & 7) == 2) && (local_cc == *(double *)((uint)local_34 & 0xfffffff8))) {
    local_644 = 1;
  }
  else {
    local_644 = 0;
  }
  local_b8 = local_644;
  if (local_644 != 0) {
    local_8c = (int)CONCAT11(local_24[3],local_24[4]);
    puVar13 = local_38;
    pbVar18 = local_24 + 2;
    goto switchD_6815fd70_default;
  }
  local_24 = local_24 + 4;
  local_8 = local_8 - 1;
  goto LAB_6815f117;
LAB_6815e829:
  if (local_20 <= local_24) {
LAB_6815e87e:
    puVar15 = xtra_getStringValue((uint *)(*(uint *)(local_f4 + 8) & 0xfffffff8));
    runtime_addBreakpoint(param_1,puVar15);
    local_3c = 0;
    goto LAB_681612b1;
  }
  local_94 = (uint)*local_24;
  if (local_94 == 0x27) goto code_r0x6815e846;
  if (local_94 != 0x83) goto LAB_6815e87e;
  local_24 = local_24 + 1;
  goto LAB_6815e829;
code_r0x6815e846:
  local_38[-local_f8] = (uint)local_6c;
  *local_38 = 0x80000001;
  puVar13 = local_38 + 1;
  pbVar18 = local_24;
  goto switchD_6815fd70_default;
switchD_681552c9_caseD_3a:
  local_1c = (uint)CONCAT11(local_6c[1],local_6c[2]);
  local_b0 = (uint *)((int)local_38 - (local_1c * 4 + 8));
  local_88 = (undefined **)*local_b0;
  local_54[0xf] = local_38;
  if (((((uint)local_88 & 7) != 0) || (((uint)local_88 & 0xfffffff8) == 0)) ||
     ((undefined **)(*(uint *)(*(int *)(((uint)local_88 & 0xfffffff8) + 4) + 8) & 0xfffffffe) !=
      &PTR_s_Function_681928b8)) goto LAB_6815e248;
  local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
  local_18 = xtra_getObjectTag(param_1,(int)local_d8);
  if (((*(int *)(local_18 + 8) == 0) && ((*(byte *)(local_18 + 0x16) & 0xc0) == 0)) &&
     ((uint)*(ushort *)(local_18 + 0x10) + (uint)*(ushort *)(local_18 + 0x12) <= local_1c)) {
    bVar10 = true;
  }
  else {
    bVar10 = false;
  }
  if (!bVar10) goto LAB_6815e248;
  bVar10 = js_isGCActive();
  if (CONCAT31(extraout_var_01,bVar10) != 0) {
    xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x1a);
    local_3c = 0;
    goto LAB_681612b1;
  }
  local_2d4 = 0x19;
  local_2c4 = (uint)*(ushort *)(local_18 + 0x14);
  local_98 = *(int **)(local_18 + 0xc);
  local_f8 = local_98[8];
  _Dst = (undefined4 *)certs_checkConstraint((int)param_1,local_2c4 + 0x19 + local_f8 * 2,&local_2cc);
  if (_Dst == (undefined4 *)0x0) {
    local_3c = 0;
    local_a4 = (undefined4 *)0x0;
  }
  else {
    local_a4 = _Dst + local_2d4;
    local_2d0 = _Dst;
    memset(_Dst,0,100);
    local_2d0[3] = local_98;
    local_2d0[4] = local_18;
    local_2d0[6] = local_1c;
    local_2d0[7] = local_b0 + 2;
    local_2d0[8] = 0x80000001;
    local_2d0[9] = local_2c4;
    local_2d0[10] = local_a4;
    local_2d0[0xb] = local_54;
    local_2d0[0xd] = *(uint *)(local_d8[1] + 4) & 0xfffffff8;
    local_2d0[0x16] = local_2cc;
    local_3c = certificates_initScope((int)param_1,(int *)(local_b0[1] & 0xfffffff8),(int)local_2d0);
    if (local_3c != 0) {
      local_38 = local_a4;
      while (uVar12 = local_2c4 - 1, local_2c4 != 0) {
        *local_38 = 0x80000001;
        local_38 = local_38 + 1;
        local_2c4 = uVar12;
      }
      local_38 = local_38 + local_f8;
      local_2d0[0x10] = local_38;
      local_2d0[0xf] = local_38;
      local_2c8 = *(code **)(*(int *)(param_1 + 10) + 0x218);
      local_2c4 = uVar12;
      if (local_2c8 != (code *)0x0) {
        uVar14 = (*local_2c8)(param_1,local_2d0,1,0,*(undefined4 *)(*(int *)(param_1 + 10) + 0x21c))
        ;
        local_2d0[0x17] = uVar14;
      }
      local_2d0[0x18] = *(undefined4 *)(param_1 + 6);
      if ((*(int *)(param_1 + 6) == local_10) &&
         (local_10 = local_98[3], local_10 != *(int *)(param_1 + 6))) {
        xtra_setPlatformRef((int)param_1,local_10);
      }
      local_54 = local_2d0;
      *(undefined4 **)(param_1 + 0x1a) = local_2d0;
      local_6c = (byte *)*local_98;
      local_20 = local_6c + local_98[1];
      local_50 = local_50 + 1;
      goto LAB_681551bc;
    }
    certificates_resetStack((int)param_1,local_2cc);
  }
  local_98 = (int *)local_54[3];
  local_f8 = local_98[8];
  goto LAB_681612b1;
LAB_6815e248:
  local_3c = certs_verifyChain((uint)param_1,local_1c,0);
  puVar13 = (uint *)local_54[0xf];
  local_38 = puVar13;
  if (local_3c == 0) goto LAB_681612b1;
  if ((char)param_1[0xac] == '\0') goto LAB_6815e6d2;
  puVar13[-local_f8] = (uint)local_6c;
  *puVar13 = *(uint *)(param_1 + 0xaa);
  local_38 = puVar13 + 1;
  *(undefined1 *)(param_1 + 0xac) = 0;
  local_c = *puVar13;
  if (((local_c & 1) == 0) || (local_c == 0x80000001)) {
    local_54[0xf] = local_38;
    local_f4 = js_resolveAtom((int)param_1,local_c);
    uVar12 = local_f4;
    if (local_f4 == 0) {
      local_3c = 0;
      goto LAB_681612b1;
    }
  }
  else {
    local_f4 = 0;
    uVar12 = local_c;
  }
  local_c = uVar12;
  local_88 = (undefined **)local_38[-2];
  if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
    local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
  }
  else {
    local_54[0xf] = local_38;
    local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
    if (local_d8 == (undefined **)0x0) {
      local_3c = 0;
      goto LAB_681612b1;
    }
  }
  local_54[0xf] = local_38;
  if ((*(undefined ***)(*local_d8 + 4) == &PTR_FUN_68192948) ||
     ((*(int *)(*local_d8 + 4) != 0 && ((undefined *)**(int **)(*local_d8 + 4) == PTR_FUN_68192948))
     )) {
    local_2e4 = ((uint)local_d8 >> 3 ^ local_c) & 0x3ff;
    local_2e0 = local_9c + 0x248;
    local_2d8 = (undefined4 *)(local_2e0 + local_2e4 * 8);
    local_2ec = (undefined **)*local_2d8;
    local_2e8 = (uint *)local_2d8[1];
    if ((local_2e8 == (uint *)0x0) ||
       ((local_2ec != local_d8 || (local_a8 = local_2e8, *local_2e8 != local_c)))) {
      local_a8 = (uint *)0x0;
    }
    local_2dc = local_2e8;
    if (local_a8 == (uint *)0x0) {
      local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x10))(param_1,local_d8,local_c,&local_34);
    }
    else {
      local_2f0 = *local_d8;
      local_b4 = local_a8[3];
      if (local_b4 == 0xffffffff) {
        local_610 = (undefined **)0x80000001;
      }
      else {
        local_610 = *(undefined ***)(local_d8[1] + local_b4 * 4);
      }
      local_34 = local_610;
      if ((local_a8[4] & 0x10) == 0) {
        if (local_a8[1] == 0) {
LAB_6815e615:
          local_624 = 1;
        }
        else {
          if ((*(byte *)((int)local_a8 + 0x11) & 8) == 0) {
            if ((*local_a8 & 1) == 0) {
              local_61c = *(uint *)(*local_a8 + 8);
            }
            else {
              local_61c = *local_a8;
            }
            local_618 = local_61c;
          }
          else {
            local_618 = (int)*(short *)((int)local_a8 + 0x12) << 1 | 1;
          }
          if (*(int *)(*(int *)(*local_d8 + 4) + 0x30) == 0) {
            local_620 = local_d8;
          }
          else {
            local_620 = (undefined **)
                        (**(code **)(*(int *)(*local_d8 + 4) + 0x30))(param_1,local_d8);
          }
          iVar16 = (*(code *)local_a8[1])(param_1,local_620,local_618,&local_34);
          if (iVar16 != 0) goto LAB_6815e615;
          local_624 = 0;
        }
        local_614 = local_624;
      }
      else {
        local_614 = certs_processKeyUsage((int)param_1,local_d8,*local_a8,local_a8[1],4,0,0,&local_34);
      }
      local_3c = local_614;
      if ((local_614 != 0) && (local_a8[3] < *(uint *)(local_2f0 + 0xc))) {
        *(undefined ***)(local_d8[1] + local_b4 * 4) = local_34;
      }
    }
  }
  else {
    local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x10))(param_1,local_d8,local_c,&local_34);
  }
  if (local_3c == 0) goto LAB_681612b1;
  (local_38 + -1)[-1 - local_f8] = (uint)local_6c;
  local_38[-2] = (uint)local_34;
  local_38 = local_38 + -1;
LAB_6815e6d2:
  local_d8 = (undefined **)0x0;
  puVar13 = local_38;
  pbVar18 = local_24;
  goto switchD_6815fd70_default;
  while( true ) {
    local_3c = (**(code **)(*(int *)(*local_80 + 4) + 8))
                         (param_1,local_80,local_34,&local_44,&local_f0);
    if (local_3c == 0) goto LAB_681612b1;
    if (local_f0 == (uint *)0x0) break;
    if (*(int *)(*(int *)(*local_44 + 4) + 0x34) != 0) {
      (**(code **)(*(int *)(*local_44 + 4) + 0x34))(param_1,local_44,local_f0);
    }
    if (local_44 == local_d8) break;
LAB_681561d6:
    (**(code **)(*(int *)(*local_d8 + 4) + 0x28))(param_1,local_d8,1,&local_c0,&local_34);
    *(int *)(local_a0[1] + 0xc) = local_c0;
    if (local_c0 == 0) {
      local_d8 = (undefined **)(*(uint *)local_d8[1] & 0xfffffff8);
      if (local_d8 == (undefined **)0x0) {
        local_34 = (undefined **)0x6;
        goto LAB_681564df;
      }
      local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x28))(param_1,local_d8,0,&local_c0,0);
      *(int *)(local_a0[1] + 0xc) = local_c0;
      if (local_3c == 0) goto LAB_681612b1;
      *(undefined ***)(local_a0[1] + 4) = local_d8;
      goto LAB_681561d6;
    }
  }
  if ((((uint)local_34 & 1) == 0) || (local_34 == (undefined **)0x80000001)) {
    local_34 = (undefined **)local_34[2];
  }
  else if (*(int *)(param_1 + 6) != 0x78) {
    local_ec = (uint *)runtime_divideFloat((int)local_34 >> 1,param_1,(uint)param_1,
                                    (double)((int)local_34 >> 1));
    if (local_ec == (uint *)0x0) {
      local_3c = 0;
      goto LAB_681612b1;
    }
    local_34 = (undefined **)((uint)local_ec | 4);
  }
  if (local_dc == 10) {
    local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
    *(undefined ***)(local_54[7] + local_b4 * 4) = local_34;
  }
  else if (local_dc == 0xb) {
    local_b4 = (uint)CONCAT11(local_6c[1],local_6c[2]);
    *(undefined ***)(local_54[10] + local_b4 * 4) = local_34;
  }
  else if (local_dc == 0x6a) {
    local_38[-local_f8] = (uint)local_6c;
    *local_38 = (uint)local_34;
    local_38 = local_38 + 1;
  }
  else {
    if ((((uint)local_88 & 7) == 0) && (local_88 != (undefined **)0x0)) {
      local_d8 = (undefined **)((uint)local_88 & 0xfffffff8);
    }
    else {
      local_54[0xf] = local_38;
      local_d8 = (undefined **)runtime_hasProperty((uint)param_1,(uint)local_88);
      if (local_d8 == (undefined **)0x0) {
        local_3c = 0;
        goto LAB_681612b1;
      }
    }
    local_54[0x13] = local_54[0x13] | 2;
    local_3c = (**(code **)(*(int *)(*local_d8 + 4) + 0x14))(param_1,local_d8,local_c,&local_34);
    local_54[0x13] = local_54[0x13] & 0xfffffffd;
    if (local_3c == 0) goto LAB_681612b1;
  }
  local_34 = (undefined **)0xe;
LAB_681564df:
  local_38 = local_38 + (int)(local_2c + 1);
  local_38[-local_f8] = (uint)local_6c;
  *local_38 = (uint)local_34;
  puVar13 = local_38 + 1;
  pbVar18 = local_24;
  goto switchD_6815fd70_default;
}



