// Module: cast
// Topic: Perlin noise generation and random number utilities
// Address range: 0x6802A1F0 - 0x6802B370
// Functions (9):
//   cast_initGlobalProperties
//   cast_clampSeed
//   cast_stepRandom
//   cast_initPermutationTable
//   cast_evalNoise2d
//   cast_generateNoiseTexture
//   cast_resolveStringRef
//   cast_resolveMemberRef
//   cast_resolveSymbolRef

// ============================================================
// Function: cast_initGlobalProperties (FUN_6802a1f0)
// Address: 6802a1f0
// Size: 142 bytes
// Params: int param_1, int * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_initGlobalProperties(int param_1,int *param_2)
{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  
  events_registerProperty(param_1,param_2,"_global",param_2,0,0);
  events_attachVtable(param_1,param_2,(int *)&PTR_DAT_6818bb28);
  sprites_initEventContext();
  cast_createGenericObject(param_1,param_2);
  cast_createAccessObject(param_1,param_2);
  cast_registerPlayerScope(param_1,(uint)param_2);
  cast_registerMovieTypes(param_1,(uint)param_2);
  cast_registerKeyTypes(param_1,(uint)param_2);
  cast_registerMouseTypes(param_1,(uint)param_2);
  cast_registerSoundTypes(param_1,(uint)param_2);
  cast_registerSystemTypes(param_1,(uint)param_2);
  cast_createSymbolObject(param_1,param_2);
  uVar3 = 0;
  uVar2 = 0;
  iVar1 = cast_loadMenuBarResource();
  events_registerProperty(param_1,param_2,"_menuBar",iVar1,uVar2,uVar3);
  return 0;
}



// ============================================================
// Function: cast_clampSeed (FUN_6802a280)
// Address: 6802a280
// Size: 50 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_clampSeed(int param_1)

{
  int iVar1;
  
  if (param_1 < 1) {
    param_1 = ((param_1 / 0x7ffffffe) * 0x7ffffffe - param_1) + 1;
  }
  iVar1 = 0x7ffffffe;
  if (param_1 != 0x7fffffff) {
    iVar1 = param_1;
  }
  return iVar1;
}



// ============================================================
// Function: cast_stepRandom (FUN_6802a2c0)
// Address: 6802a2c0
// Size: 45 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_stepRandom(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 0x41a7 + (param_1 / 0x1f31d) * -0x7fffffff;
  if (iVar1 < 1) {
    iVar1 = iVar1 + 0x7fffffff;
  }
  return iVar1;
}



// ============================================================
// Function: cast_initPermutationTable (FUN_6802a2f0)
// Address: 6802a2f0
// Size: 380 bytes
// Params: void * this, int param_1, double * param_2
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_initPermutationTable(void *this,int param_1,double *param_2)
{
  undefined4 uVar1;
  uint uVar2;
  double *pdVar3;
  int iVar4;
  uint uVar5;
  double *pdVar6;
  double *pdVar7;
  float10 extraout_ST0;
  float10 fVar8;
  int local_14;
  int local_10;
  double *local_c;
  int local_8;
  
  uVar2 = cast_clampSeed((int)this);
  local_c = param_2;
  local_14 = 4;
  do {
    local_8 = 0;
    pdVar3 = local_c;
    iVar4 = local_8;
    do {
      local_8 = iVar4;
      *(int *)(param_1 + local_8 * 4) = local_8;
      local_10 = 2;
      pdVar6 = pdVar3;
      do {
        uVar2 = cast_stepRandom(uVar2);
        uVar5 = uVar2 & 0x800001ff;
        if ((int)uVar5 < 0) {
          uVar5 = (uVar5 - 1 | 0xfffffe00) + 1;
        }
        pdVar7 = pdVar6 + 1;
        local_10 = local_10 + -1;
        *pdVar6 = (double)((float10)(int)(uVar5 - 0x100) * extraout_ST0);
        pdVar6 = pdVar7;
      } while (local_10 != 0);
      fVar8 = (float10)Ordinal_1522(*pdVar3 * *pdVar3 + pdVar3[1] * pdVar3[1]);
      *pdVar3 = (double)((float10)*pdVar3 / fVar8);
      pdVar3[1] = (double)((float10)pdVar3[1] / fVar8);
      pdVar3 = pdVar7;
      iVar4 = local_8 + 1;
    } while (local_8 + 1 < 0x100);
    local_c = local_c + 0x404;
    local_14 = local_14 + -1;
  } while (local_14 != 0);
  while (local_8 != 0) {
    uVar1 = *(undefined4 *)(param_1 + local_8 * 4);
    uVar2 = cast_stepRandom(uVar2);
    uVar5 = uVar2 & 0x800000ff;
    if ((int)uVar5 < 0) {
      uVar5 = (uVar5 - 1 | 0xffffff00) + 1;
    }
    local_8 = local_8 + -1;
    *(undefined4 *)(param_1 + 4 + local_8 * 4) = *(undefined4 *)(param_1 + uVar5 * 4);
    *(undefined4 *)(param_1 + uVar5 * 4) = uVar1;
  }
  iVar4 = 0;
  pdVar3 = param_2 + 1;
  do {
    *(undefined4 *)(param_1 + 0x400 + iVar4 * 4) = *(undefined4 *)(param_1 + iVar4 * 4);
    pdVar3[0x1ff] = pdVar3[-1];
    iVar4 = iVar4 + 1;
    pdVar3[0x200] = *pdVar3;
    pdVar3[0x603] = pdVar3[0x403];
    pdVar3[0x604] = pdVar3[0x404];
    pdVar3[0xa07] = pdVar3[0x807];
    pdVar3[0xa08] = pdVar3[0x808];
    pdVar3[0xe0b] = pdVar3[0xc0b];
    pdVar3[0xe0c] = pdVar3[0xc0c];
    pdVar3 = pdVar3 + 2;
  } while (iVar4 < 0x102);
  return 0;
}



// ============================================================
// Function: cast_evalNoise2d (FUN_6802a480)
// Address: 6802a480
// Size: 1373 bytes
// Params: int param_1, double * param_2, int param_3, double * param_4, uint param_5
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_evalNoise2d(int param_1,double *param_2,int param_3,double *param_4,uint param_5)
{
  double *pdVar1;
  double *pdVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  double dVar7;
  double dVar8;
  double dVar9;
  double dVar10;
  double dVar11;
  double dVar12;
  double dVar13;
  double dVar14;
  int in_EAX;
  uint uVar15;
  double *pdVar16;
  double *pdVar17;
  uint uVar18;
  double *pdVar19;
  int iVar20;
  double *local_20;
  double *local_1c;
  uint local_14;
  double *local_10;
  double *local_c;
  double *local_8;
  
  dVar7 = (*param_2 + 4096.0) - 0.5;
  local_14 = (uint)ROUND(dVar7);
  uVar15 = local_14 + 1;
  dVar7 = (*param_2 + 4096.0) - (double)(int)ROUND(dVar7);
  dVar8 = dVar7 - 1.0;
  dVar9 = (param_2[1] + 4096.0) - 0.5;
  local_8 = (double *)(int)ROUND(dVar9);
  uVar18 = (int)local_8 + 1;
  dVar9 = (param_2[1] + 4096.0) - (double)(int)ROUND(dVar9);
  dVar10 = dVar9 - 1.0;
  if (param_4 != (double *)0x0) {
    if (*(int *)(param_4 + 1) <= (int)local_14) {
      local_14 = local_14 - *(int *)param_4;
    }
    if (*(int *)(param_4 + 1) <= (int)uVar15) {
      uVar15 = uVar15 - *(int *)param_4;
    }
    if (*(int *)((int)param_4 + 0xc) <= (int)local_8) {
      local_8 = (double *)((int)local_8 - *(int *)((int)param_4 + 4));
    }
    if (*(int *)((int)param_4 + 0xc) <= (int)uVar18) {
      uVar18 = uVar18 - *(int *)((int)param_4 + 4);
    }
  }
  iVar3 = *(int *)(param_1 + (local_14 & 0xff) * 4);
  iVar4 = *(int *)(param_1 + (uVar15 & 0xff) * 4);
  iVar5 = *(int *)(param_1 + (((uint)local_8 & 0xff) + iVar3) * 4);
  iVar6 = *(int *)(param_1 + (((uint)local_8 & 0xff) + iVar4) * 4);
  dVar13 = dVar7 * dVar7 * (3.0 - dVar7 * 2.0);
  iVar3 = *(int *)(param_1 + (iVar3 + (uVar18 & 0xff)) * 4);
  iVar4 = *(int *)(param_1 + (iVar4 + (uVar18 & 0xff)) * 4);
  uVar15 = 0;
  dVar14 = dVar9 * dVar9 * (3.0 - dVar9 * 2.0);
  if (3 < (int)param_5) {
    pdVar19 = (double *)(in_EAX + 0x2020 + iVar3 * 0x10);
    local_10 = (double *)(in_EAX + 0x4048 + iVar3 * 0x10);
    local_c = (double *)(in_EAX + 0x4048 + iVar6 * 0x10);
    local_8 = (double *)(in_EAX + 0x4048 + iVar5 * 0x10);
    local_1c = (double *)(iVar5 * 0x10 + in_EAX);
    pdVar17 = (double *)(iVar4 * 0x10 + 0x4040 + in_EAX);
    pdVar16 = (double *)(iVar6 * 0x10 + 8 + in_EAX);
    iVar20 = (param_5 - 4 >> 2) + 1;
    uVar15 = iVar20 * 4;
    param_4 = (double *)(param_3 + 0x10);
    do {
      dVar12 = dVar7 * *local_1c + pdVar16[iVar6 * -2 + iVar5 * 2] * dVar9;
      dVar12 = ((*pdVar16 * dVar9 + pdVar16[-1] * dVar8) - dVar12) * dVar13 + dVar12;
      dVar11 = pdVar19[-0x404] * dVar7 + pdVar16[iVar6 * -2 + iVar3 * 2] * dVar10;
      param_4[-2] = ((((pdVar17[-0x808] * dVar8 + pdVar16[iVar6 * -2 + iVar4 * 2] * dVar10) - dVar11
                      ) * dVar13 + dVar11) - dVar12) * dVar14 + dVar12;
      dVar11 = local_8[-0x404] * dVar9 + pdVar19[iVar3 * -2 + iVar5 * 2] * dVar7;
      dVar11 = ((pdVar16[0x403] * dVar8 + local_c[-0x404] * dVar9) - dVar11) * dVar13 + dVar11;
      dVar12 = *pdVar19 * dVar7 + local_10[-0x404] * dVar10;
      param_4[-1] = ((((pdVar17[-0x403] * dVar10 + pdVar19[iVar3 * -2 + iVar4 * 2] * dVar8) - dVar12
                      ) * dVar13 + dVar12) - dVar11) * dVar14 + dVar11;
      dVar11 = dVar9 * *local_8 + pdVar17[iVar4 * -2 + iVar5 * 2] * dVar7;
      dVar11 = ((*local_c * dVar9 + pdVar16[0x807] * dVar8) - dVar11) * dVar13 + dVar11;
      dVar12 = dVar10 * *local_10 + pdVar19[0x404] * dVar7;
      *param_4 = ((((*pdVar17 * dVar8 + pdVar17[1] * dVar10) - dVar12) * dVar13 + dVar12) - dVar11)
                 * dVar14 + dVar11;
      dVar11 = local_1c[0xc0c] * dVar7 + local_8[0x404] * dVar9;
      dVar11 = ((local_c[0x404] * dVar9 + pdVar16[0xc0b] * dVar8) - dVar11) * dVar13 + dVar11;
      dVar12 = pdVar19[0x808] * dVar7 + local_10[0x404] * dVar10;
      pdVar1 = pdVar17 + 0x405;
      pdVar2 = pdVar17 + 0x404;
      local_1c = local_1c + 0x1010;
      local_8 = local_8 + 0x1010;
      local_c = local_c + 0x1010;
      local_10 = local_10 + 0x1010;
      pdVar16 = pdVar16 + 0x1010;
      pdVar19 = pdVar19 + 0x1010;
      pdVar17 = pdVar17 + 0x1010;
      iVar20 = iVar20 + -1;
      param_4[1] = ((((*pdVar2 * dVar8 + *pdVar1 * dVar10) - dVar12) * dVar13 + dVar12) - dVar11) *
                   dVar14 + dVar11;
      param_4 = param_4 + 4;
    } while (iVar20 != 0);
  }
  if (uVar15 < param_5) {
    iVar20 = uVar15 * 0x404;
    pdVar16 = (double *)(uVar15 * 0x2020 + iVar6 * 0x10 + in_EAX);
    pdVar19 = (double *)(in_EAX + 8 + (iVar20 + iVar5 * 2) * 8);
    param_4 = (double *)(in_EAX + 8 + (iVar20 + iVar3 * 2) * 8);
    local_20 = (double *)(in_EAX + 8 + (iVar20 + iVar4 * 2) * 8);
    do {
      uVar15 = uVar15 + 1;
      pdVar17 = pdVar16 + 0x404;
      dVar11 = dVar9 * *pdVar19 + pdVar16[iVar6 * -2 + iVar5 * 2] * dVar7;
      dVar11 = ((*pdVar16 * dVar8 + pdVar16[1] * dVar9) - dVar11) * dVar13 + dVar11;
      dVar12 = dVar10 * *param_4 + pdVar17[iVar6 * -2 + iVar3 * 2 + -0x404] * dVar7;
      *(double *)(param_3 + -8 + uVar15 * 8) =
           ((((*local_20 * dVar10 + pdVar17[iVar6 * -2 + iVar4 * 2 + -0x404] * dVar8) - dVar12) *
             dVar13 + dVar12) - dVar11) * dVar14 + dVar11;
      pdVar16 = pdVar17;
      pdVar19 = pdVar19 + 0x404;
      param_4 = param_4 + 0x404;
      local_20 = local_20 + 0x404;
    } while (uVar15 < param_5);
  }
  return 0;
}



// ============================================================
// Function: cast_generateNoiseTexture (FUN_6802a9e0)
// Address: 6802a9e0
// Size: 2209 bytes
// Params: void * param_1, void * param_2, double param_3, double param_4, int param_5, void * param_6, int param_7, int param_8, byte param_9, int param_10, int param_11, double * param_12
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_generateNoiseTexture(void *param_1,void *param_2,double param_3,double param_4,int param_5,
                 void *param_6,int param_7,int param_8,byte param_9,int param_10,int param_11,
                 double *param_12)
{
  double dVar1;
  int iVar2;
  double *pdVar3;
  int iVar4;
  double *pdVar5;
  uint uVar6;
  double dVar7;
  double dVar8;
  double local_144;
  double local_13c;
  double local_134;
  double local_12c;
  double local_124;
  void *local_11c;
  double *local_118;
  undefined8 local_114;
  int local_10c;
  int local_108;
  void *local_104;
  double *local_100;
  int local_fc;
  double *local_f8;
  int local_f4;
  int local_f0;
  int local_ec;
  int local_e8;
  int local_e4;
  int local_e0;
  double *local_dc;
  int local_d8;
  double *local_d4;
  int local_d0;
  double *local_cc;
  double *local_c8;
  int local_c4;
  undefined8 local_c0;
  int local_b8;
  int local_b4;
  uint local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  double *local_9c;
  double local_98;
  double *local_90;
  double *local_8c;
  int local_88;
  double local_84;
  double *local_7c;
  int local_78;
  int local_74;
  int local_70;
  int local_6c;
  int local_68;
  int local_64;
  int local_60 [2];
  undefined8 local_58;
  int local_50;
  int local_4c;
  double local_48 [8];
  uint local_8;
  
  local_108 = param_11;
  local_11c = param_1;
  local_104 = param_2;
  local_118 = param_12;
  local_d8 = 0;
  local_74 = 0;
  local_7c = (double *)0x0;
  if (param_3 != 0.0) {
    param_3 = 1.0 / ABS(param_3);
  }
  if (param_4 != 0.0) {
    param_4 = 1.0 / ABS(param_4);
  }
  iVar2 = cast_acquireXtraBitmap(param_1,param_2,&local_78);
  if (iVar2 == 0) {
    local_d8 = 1;
    pdVar3 = (double *)cast_getXtraBitmapInfo(param_1,param_2,&local_70);
    if (((pdVar3 == (double *)0x0) && (local_64 == 0x20)) && (local_78 != 0)) {
      local_9c = (double *)0xff;
      local_c8 = pdVar3;
      local_90 = pdVar3;
      local_8c = pdVar3;
      local_74 = Ordinal_1126(0x808);
      local_7c = (double *)Ordinal_1126(0x8080,0);
      local_b0 = (uint)(local_60[0] != 0);
      cast_initPermutationTable(param_6,local_74,local_7c);
      local_78 = local_78 + (local_6c + -1) * (local_68 >> 2) * 4;
      pdVar3 = (double *)0x0;
      local_a4 = local_70;
      local_a0 = local_6c;
      if (param_10 == 0) {
        uVar6 = (uint)((param_9 & 1) != 0);
        if ((param_9 & 2) != 0) {
          uVar6 = uVar6 + 1;
        }
        if ((param_9 & 4) != 0) {
          uVar6 = uVar6 + 1;
        }
      }
      else {
        uVar6 = 1;
      }
      if ((local_b0 != 0) && ((param_9 & 8) != 0)) {
        uVar6 = uVar6 + 1;
      }
      local_e4 = 0;
      local_e8 = 0;
      local_f0 = 0;
      local_ec = 0;
      local_4c = 0;
      local_50 = 0;
      (*(unsigned int *)((char *)&local_58 + 0)) = 0;
      (*(unsigned int *)((char *)&local_58 + 4)) = 0;
      if (((param_7 != 0) && (local_70 != 0)) && (local_6c != 0)) {
        if (param_3 != 0.0) {
          local_98 = (double)local_70;
          local_c0 = local_98 * param_3;
          dVar7 = floor(local_c0);
          local_98 = dVar7 / local_98;
          dVar8 = ceil(local_c0);
          dVar1 = param_3 / local_98;
          dVar7 = (dVar8 / (double)local_a4) / param_3;
          param_3 = dVar8 / (double)local_a4;
          if (dVar1 < dVar7) {
            param_3 = local_98;
          }
        }
        if (param_4 != 0.0) {
          local_98 = (double)local_a0;
          local_c0 = local_98 * param_4;
          local_114 = floor(local_c0);
          local_114 = local_114 / local_98;
          dVar8 = ceil(local_c0);
          dVar1 = param_4 / local_114;
          dVar7 = (dVar8 / local_98) / param_4;
          param_4 = dVar8 / local_98;
          if (dVar1 < dVar7) {
            param_4 = local_114;
          }
        }
        local_c8 = (double *)&local_58;
        local_f0 = (int)ROUND((double)local_a4 * param_3);
        local_e8 = local_f0 + 0x1000;
        local_98 = (double)local_a0 * param_4;
        local_ec = (int)ROUND(local_98);
        local_e4 = local_ec + 0x1000;
        local_88 = local_ec;
      }
      local_b4 = 0;
      param_2 = local_104;
      param_1 = local_11c;
      if (0 < local_a0) {
        local_88 = 0;
        local_c0 = (double)CONCAT44((local_68 >> 2) * -4,(undefined4)local_c0);
        do {
          local_114 = (double)CONCAT44(local_88 + local_78,(undefined4)local_114);
          local_ac = 0;
          if (0 < local_a4) {
            do {
              local_98 = 255.0;
              local_b8 = 0;
              if (param_7 != 0) {
                (*(unsigned int *)((char *)&local_58 + 0)) = local_f0;
                (*(unsigned int *)((char *)&local_58 + 4)) = local_ec;
                local_50 = local_e8;
                local_4c = local_e4;
              }
              local_48[4] = 0.0;
              local_48[5] = 0.0;
              local_48[6] = 0.0;
              local_48[7] = 0.0;
              local_12c = param_3;
              local_124 = param_4;
              if (0 < param_5) {
                local_134 = (double)local_ac;
                local_10c = local_108 - (int)local_118;
                local_84 = (double)local_b4;
                local_fc = param_5;
                pdVar5 = local_118;
                do {
                  local_144 = (*(double *)(local_10c + (int)pdVar5) + local_134) * local_12c;
                  local_13c = (local_84 + *pdVar5) * local_124;
                  cast_evalNoise2d(local_74,&local_144,(int)local_48,local_c8,uVar6);
                  iVar2 = 0;
                  if (param_8 == 0) {
                    if (3 < uVar6) {
                      iVar4 = iVar2;
                      do {
                        iVar2 = iVar4 + 4;
                        local_48[iVar2] = ABS(local_48[iVar4]) * local_98 + local_48[iVar2];
                        local_48[iVar4 + 5] =
                             ABS(*(double *)(local_60 + iVar2 * 2)) * local_98 + local_48[iVar4 + 5]
                        ;
                        local_48[iVar4 + 6] =
                             ABS((double)(&local_58)[iVar2]) * local_98 + local_48[iVar4 + 6];
                        local_48[iVar4 + 7] =
                             ABS(*(double *)(&local_50 + iVar2 * 2)) * local_98 +
                             local_48[iVar4 + 7];
                        iVar4 = iVar2;
                      } while (iVar2 < (int)(uVar6 - 3));
                    }
                    for (; iVar2 < (int)uVar6; iVar2 = iVar2 + 1) {
                      local_48[iVar2 + 4] = ABS(local_48[iVar2]) * local_98 + local_48[iVar2 + 4];
                    }
                  }
                  else {
                    if (3 < uVar6) {
                      iVar4 = iVar2;
                      do {
                        iVar2 = iVar4 + 4;
                        local_48[iVar2] = local_48[iVar4] * local_98 + local_48[iVar2];
                        local_48[iVar4 + 5] =
                             *(double *)(local_60 + iVar2 * 2) * local_98 + local_48[iVar4 + 5];
                        local_48[iVar4 + 6] =
                             (double)(&local_58)[iVar2] * local_98 + local_48[iVar4 + 6];
                        local_48[iVar4 + 7] =
                             *(double *)(&local_50 + iVar2 * 2) * local_98 + local_48[iVar4 + 7];
                        iVar4 = iVar2;
                      } while (iVar2 < (int)(uVar6 - 3));
                    }
                    for (; iVar2 < (int)uVar6; iVar2 = iVar2 + 1) {
                      local_48[iVar2 + 4] = local_48[iVar2] * local_98 + local_48[iVar2 + 4];
                    }
                  }
                  local_12c = local_12c * 2.0;
                  local_124 = local_124 * 2.0;
                  local_98 = local_98 * 0.5;
                  if (param_7 != 0) {
                    (*(unsigned int *)((char *)&local_58 + 0)) = (int)local_58 * 2;
                    local_50 = local_50 * 2 + -0x1000;
                    (*(unsigned int *)((char *)&local_58 + 4)) = (*(unsigned int *)((char *)&local_58 + 4)) * 2;
                    local_4c = local_4c * 2 + -0x1000;
                  }
                  pdVar5 = pdVar5 + 1;
                  local_fc = local_fc + -1;
                } while (local_fc != 0);
                local_fc = 0;
              }
              if (param_8 == 0) {
                if (param_10 == 0) {
                  iVar2 = local_b8;
                  if ((param_9 & 1) != 0) {
                    local_d4 = (double *)(int)ROUND(local_48[4]);
                    iVar2 = 1;
                    local_8c = local_d4;
                    local_84 = local_48[4];
                  }
                  if ((param_9 & 2) != 0) {
                    local_84 = local_48[iVar2 + 4];
                    local_dc = (double *)(int)ROUND(local_84);
                    iVar2 = iVar2 + 1;
                    local_90 = local_dc;
                  }
                  if ((param_9 & 4) != 0) {
                    local_84 = local_48[iVar2 + 4];
                    pdVar3 = (double *)(int)ROUND(local_84);
                    iVar2 = iVar2 + 1;
                    local_f8 = pdVar3;
                  }
                }
                else {
                  pdVar3 = (double *)(int)ROUND(local_48[4]);
                  iVar2 = 1;
                  local_cc = pdVar3;
                  local_90 = pdVar3;
                  local_8c = pdVar3;
                  local_84 = local_48[4];
                }
                if ((local_b0 != 0) && ((param_9 & 8) != 0)) {
                  local_84 = local_48[iVar2 + 4];
                  local_100 = (double *)(int)ROUND(local_84);
                  local_9c = local_100;
                }
              }
              else {
                if (param_10 == 0) {
                  iVar2 = local_b8;
                  if ((param_9 & 1) != 0) {
                    local_84 = local_48[4] + 255.0;
                    local_c4 = (int)ROUND(local_84);
                    local_8c = (double *)(local_c4 >> 1);
                    iVar2 = 1;
                  }
                  if ((param_9 & 2) != 0) {
                    local_84 = local_48[iVar2 + 4] + 255.0;
                    local_e0 = (int)ROUND(local_84);
                    local_90 = (double *)(local_e0 >> 1);
                    iVar2 = iVar2 + 1;
                  }
                  if ((param_9 & 4) != 0) {
                    local_84 = local_48[iVar2 + 4] + 255.0;
                    local_d0 = (int)ROUND(local_84);
                    pdVar3 = (double *)(local_d0 >> 1);
                    iVar2 = iVar2 + 1;
                  }
                }
                else {
                  local_84 = local_48[4] + 255.0;
                  local_f4 = (int)ROUND(local_84);
                  pdVar3 = (double *)(local_f4 >> 1);
                  iVar2 = 1;
                  local_90 = pdVar3;
                  local_8c = pdVar3;
                }
                if ((local_b0 != 0) && ((param_9 & 8) != 0)) {
                  local_84 = local_48[iVar2 + 4] + 255.0;
                  local_a8 = (int)ROUND(local_84);
                  local_9c = (double *)(local_a8 >> 1);
                }
              }
              if ((int)local_9c < 0) {
                local_9c = (double *)0x0;
              }
              else if (0xff < (int)local_9c) {
                local_9c = (double *)0xff;
              }
              if ((int)local_8c < 0) {
                pdVar5 = (double *)0x0;
LAB_6802b1bd:
                local_8c = pdVar5;
              }
              else {
                pdVar5 = local_9c;
                if ((int)local_9c < (int)local_8c) goto LAB_6802b1bd;
              }
              if ((int)local_90 < 0) {
                pdVar5 = (double *)0x0;
LAB_6802b1d1:
                local_90 = pdVar5;
              }
              else {
                pdVar5 = local_9c;
                if ((int)local_9c < (int)local_90) goto LAB_6802b1d1;
              }
              if ((int)pdVar3 < 0) {
                pdVar3 = (double *)0x0;
              }
              else if ((int)local_9c < (int)pdVar3) {
                pdVar3 = local_9c;
              }
              *(double **)((*(unsigned int *)((char *)&local_114 + 4)) + local_ac * 4) =
                   pdVar3 + (int)(local_90 + (int)(local_8c + (int)local_9c * 0x20) * 0x20) * 0x20;
              local_ac = local_ac + 1;
            } while (local_ac < local_a4);
          }
          local_88 = local_88 + (*(unsigned int *)((char *)&local_c0 + 4));
          local_b4 = local_b4 + 1;
          param_2 = local_104;
          param_1 = local_11c;
        } while (local_b4 < local_a0);
      }
    }
  }
  if (local_7c != (double *)0x0) {
    Ordinal_1127();
  }
  if (local_74 != 0) {
    Ordinal_1127();
  }
  if (local_d8 != 0) {
    cast_releaseXtraBitmap(param_1,param_2);
  }
  return 0;
}



// ============================================================
// Function: cast_resolveStringRef (FUN_6802b290)
// Address: 6802b290
// Size: 187 bytes
// Params: char * param_1, int param_2, uint * param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_resolveStringRef(char *param_1,int param_2,uint *param_3)

{
  int param_4;
  char cVar1;
  int iVar2;
  uint uVar3;
  char *pcVar4;
  char *pcVar5;
  uint *puVar6;
  uint unaff_EBX;
  int local_c;
  int *local_8;
  
  iVar2 = xtra_getPlatformData(unaff_EBX);
  uVar3 = xtra_getObjectTag(unaff_EBX,param_2);
  local_8 = (int *)((int)uVar3 >> 1);
  local_c = 8;
  props_getStringLength(iVar2,&local_c);
  if ((local_c != 0x40) && (local_c != 0x43)) {
    return 0;
  }
  props_getStringData(&local_c,(int *)0x0);
  pcVar4 = (char *)runtime_strlen(param_1);
  props_unlockString(&local_c);
  props_releaseValue(iVar2,(byte)local_c,local_8);
  if (pcVar4 != (char *)0x0) {
    pcVar5 = pcVar4;
    do {
      cVar1 = *pcVar5;
      pcVar5 = pcVar5 + 1;
    } while (cVar1 != '\0');
    puVar6 = xtra_getScriptContextEx(unaff_EBX,(int)pcVar4,(int)pcVar5 - (int)(pcVar4 + 1));
    if (puVar6 != (uint *)0x0) {
      *param_3 = (uint)puVar6 | 4;
      return 1;
    }
    xtra_checkAndFlush(unaff_EBX,(int)pcVar4);
  }
  return 0;
}



// ============================================================
// Function: cast_resolveMemberRef (FUN_6802b350)
// Address: 6802b350
// Size: 30 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveMemberRef(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,uint *param_5
                 )
{
  cast_resolveStringRef("#%s",param_2,param_5);
  return 0;
}



// ============================================================
// Function: cast_resolveSymbolRef (FUN_6802b370)
// Address: 6802b370
// Size: 30 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_resolveSymbolRef(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,uint *param_5
                 )
{
  cast_resolveStringRef("<symbol(\"%s\")>",param_2,param_5);
  return 0;
}



