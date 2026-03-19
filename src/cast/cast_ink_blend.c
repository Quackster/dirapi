// Module: cast
// Topic: Ink effects, blending, and image compositing dispatch
// Address range: 0x68023290 - 0x68024DF0
// Functions (13):
//   cast_createBlankBitmap (FUN_68023290)
//   cast_blendInk
//   cast_compositeInkBlend (FUN_680233d0)
//   cast_createBitmapFromSource (FUN_68023e80)
//   cast_cropBitmap (FUN_68023f00)
//   cast_createBitmapMatte (FUN_680242f0)
//   cast_duplicateBitmap (FUN_68024460)
//   cast_transformBitmapPalette (FUN_680244e0)
//   cast_applyInkMask (FUN_680245e0)
//   cast_trimBitmap (FUN_680246d0)
//   cast_generateNoiseBitmap (FUN_68024730)
//   cast_dispatchImageCommand (FUN_68024bd0)
//   cast_compareBitmaps (FUN_68024df0)

// ============================================================
// Function: cast_createBlankBitmap (FUN_68023290)
// Address: 68023290
// Size: 202 bytes
// Params: int param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_createBlankBitmap(int param_1,int param_2,int param_3,undefined4 *param_4)
{
  int local_2c;
  int iVar1;
  int iVar2;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  undefined4 local_8;
  
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_8 = 0;
  if (((param_4 != (undefined4 *)0x0) && (-1 < param_2)) && (-1 < param_3)) {
    *param_4 = 2;
    iVar2 = Ordinal_1650(0x20,8,1,param_2,param_3,4);
    if (iVar2 != 0) {
      Ordinal_1665(iVar2,0);
      iVar1 = *(int *)(*(int *)(param_1 + 8) + 4);
      Ordinal_360(*(int **)(iVar1 + 0x20),*(undefined4 ****)(iVar1 + 0x28),0x11,(double *)&local_1c)
      ;
      Ordinal_362(*(int *)(iVar1 + 0x20),*(int *)(iVar1 + 0x28),&local_1c);
      cast_setCastMemberData(iVar2,0,(undefined4 *)0x0,0,0);
    }
  }
  return 0;
}



// ============================================================
// Function: cast_blendInk (FUN_68023360)
// Address: 68023360
// Size: 99 bytes
// Params: void * this, undefined4 param_1
// Return: undefined4
// Calling convention: __thiscall
// ============================================================

undefined4 __thiscall cast_blendInk(void *this,undefined4 param_1)

{
  undefined **ppuVar1;
  int iVar2;
  int *extraout_ECX;
  int *piVar3;
  undefined4 *unaff_ESI;
  int local_c [2];
  
  *unaff_ESI = 0;
  if (*(int *)this == 3) {
    ppuVar1 = cast_getVtable();
    piVar3 = extraout_ECX;
    do {
      if ((undefined **)**(int **)piVar3[1] == ppuVar1) {
        *unaff_ESI = (undefined4 *)piVar3[1];
        return 1;
      }
      iVar2 = core_unwrapMember(param_1,piVar3,local_c);
      if (iVar2 == 0) {
        return 0;
      }
      piVar3 = local_c;
      *unaff_ESI = 0;
    } while (local_c[0] == 3);
  }
  return 0;
}



// ============================================================
// Function: cast_compositeInkBlend (FUN_680233d0)
// Address: 680233d0
// Size: 2612 bytes
// Params: void * this, void * param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_compositeInkBlend(void *this,void *param_1)
{
  bool bVar1;
  int iVar2;
  undefined3 extraout_var;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar3;
  int extraout_EDX;
  int extraout_EDX_00;
  int extraout_EDX_01;
  int iVar4;
  undefined4 local_160;
  undefined4 local_15c;
  undefined4 local_150;
  undefined4 local_14c;
  undefined4 local_148;
  undefined4 local_144;
  int local_140;
  uint local_13c;
  int *local_138;
  uint local_134;
  undefined4 local_130;
  int *local_12c;
  int local_128;
  int local_124;
  int local_120;
  int local_11c;
  uint local_118;
  int local_114;
  undefined4 local_110;
  int local_10c;
  void *local_108;
  int local_104;
  undefined4 local_100;
  int local_fc;
  int local_f8;
  void *local_f4;
  int local_f0;
  uint local_ec;
  uint local_e8;
  undefined4 local_e4;
  undefined4 local_e0;
  uint local_dc;
  int *local_d8;
  undefined4 local_d4;
  undefined4 local_d0;
  undefined4 local_cc;
  undefined4 local_c8;
  undefined4 local_c4;
  uint local_c0;
  int local_bc;
  undefined4 local_b8;
  undefined4 local_b4;
  undefined4 local_b0;
  undefined4 local_ac;
  undefined4 local_a8;
  undefined4 local_a4;
  undefined4 local_a0;
  undefined4 local_9c;
  undefined4 local_98;
  uint local_94;
  int local_90;
  undefined4 local_8c;
  undefined4 local_88;
  undefined4 local_84;
  undefined4 local_80;
  undefined4 local_7c [16];
  undefined1 local_3c [4];
  int local_38;
  int local_30;
  undefined1 local_2c [4];
  int local_28;
  int local_20;
  int local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar4 = 0;
  local_f4 = param_1;
  local_128 = 0;
  local_fc = 0;
  local_f0 = 0;
  local_120 = 0;
  local_148 = 0;
  local_124 = 0;
  local_10c = 0;
  local_104 = 0;
  local_11c = 0;
  local_f8 = 0;
  iVar2 = props_getInt((int)this);
  if (iVar2 < 4) {
    props_setError((int)this,0x17);
    goto LAB_68023d8c;
  }
  iVar2 = cast_blendInk((void *)(**(int **)((int)this + 0x10) + *(int *)((int)this + 0x20) * -8 + 8 +
                               *(int *)((int)this + 0x18)),this);
  if ((iVar2 == 0) || (local_108 = (void *)Ordinal_1114(local_120), local_108 == (void *)0x0))
  goto LAB_68023d8c;
  iVar2 = cast_initBitmapState((void *)0x3,(int)this);
  if (iVar2 == 0) {
    bVar1 = cast_lookupBitmapEntry(3,local_7c);
    if (CONCAT31(extraout_var,bVar1) != 0) {
      local_10c = 1;
      goto LAB_680234c3;
    }
  }
  else {
LAB_680234c3:
    iVar2 = cast_initBitmapState((void *)0x4,(int)this);
    if (iVar2 != 0) {
      iVar2 = props_getInt((int)this);
      if (4 < iVar2) {
        iVar4 = score_resolveProplistEntry((int)this,5,&local_12c);
      }
      local_e0 = 0;
      local_e4 = 0;
      local_134 = 0;
      local_100 = 0;
      local_150 = 0;
      local_14c = 0;
      local_d4 = 0;
      local_d0 = 0;
      local_cc = 0;
      local_c8 = 0;
      local_c4 = 0;
      local_c0 = 0;
      local_bc = 0;
      local_b8 = 0;
      local_b4 = 0;
      local_b0 = 0;
      local_ac = 0;
      local_a8 = 0;
      local_a4 = 0;
      local_a0 = 0;
      local_9c = 0;
      local_98 = 0;
      local_94 = 0;
      local_90 = 0;
      local_8c = 0;
      local_88 = 0;
      local_84 = 0;
      local_80 = 0;
      local_130 = 0;
      local_140 = 0;
      Ordinal_1130(&local_1c,0x14);
      local_1c = 0;
      local_18 = 0x100;
      local_14 = 0x1ffffff;
      local_e8 = 0x1ffffff;
      local_ec = 0x1000000;
      if (iVar4 != 0) {
        iVar2 = cast_getMemberData(this,local_12c);
        local_114 = 1;
        if (0 < iVar2) {
          do {
            cast_getContextData(this,local_12c,local_114,&local_13c,&local_dc);
            props_resolveValue((int)this,&local_13c);
            if (local_13c == 8) {
              if ((int)local_138 < 0x35d) {
                if (local_138 == (int *)0x35c) {
                  iVar4 = props_callBuiltinMethod(8,extraout_EDX,(int)this,(byte *)&local_dc);
                  if ((iVar4 == 0) && (local_d8 != (int *)0x0)) {
                    local_100 = 1;
                    if (local_d8 == (int *)0x4bf) {
                      local_100 = 2;
                    }
                    else if (local_d8 == (int *)0x7b1) {
                      local_100 = 3;
                    }
                  }
                }
                else if ((int)local_138 < 0x236) {
                  if (local_138 == (int *)0x235) {
                    iVar4 = props_callBuiltinMethod(8,(int)&local_dc,(int)this,(byte *)&local_dc);
                    if (iVar4 == 0) {
                      local_18 = ((int)local_d8 * 0x100 + 0x32) / 100;
                    }
                  }
                  else if (local_138 == (int *)0xbe) {
                    iVar4 = props_coerceAndStore((int)this,&local_dc,(int *)&local_118);
                    if (iVar4 == 0) {
                      local_f8 = 1;
                      local_ec = local_118;
                    }
                    else {
                      iVar4 = props_callBuiltinMethod(extraout_ECX,extraout_EDX_00,(int)this,(byte *)&local_dc)
                      ;
                      if (iVar4 == 0) {
                        local_f8 = 1;
                        local_ec = CONCAT31((int3)(local_ec >> 8),(*(unsigned char *)((char *)&local_d8 + 0))) & 0xffffff;
                      }
                    }
                  }
                  else if (local_138 == (int *)0x16c) {
                    if (local_dc == 8) {
                      local_1c = cast_mapInkToType();
                    }
                    else {
                      iVar4 = props_callBuiltinMethod(8,(int)&local_dc,(int)this,(byte *)&local_dc);
                      if (iVar4 == 0) {
                        local_1c = cast_mapTypeToInk();
                      }
                    }
                  }
                }
                else if (local_138 == (int *)0x359) {
                  iVar4 = props_coerceAndStore((int)this,&local_dc,(int *)&local_118);
                  if (iVar4 == 0) {
                    local_f8 = 1;
                    local_e8 = local_118;
                  }
                  else {
                    iVar4 = props_callBuiltinMethod(&local_dc,extraout_EDX_01,(int)this,(byte *)&local_dc);
                    if (iVar4 == 0) {
                      local_f8 = 1;
                      local_e8 = CONCAT31((int3)(local_e8 >> 8),(*(unsigned char *)((char *)&local_d8 + 0))) & 0xffffff;
                    }
                  }
                }
              }
              else if ((int)local_138 - 0x367U < 0x4d) {
                switch((int)(size_t)local_138) {
                case (int *)0x367:
                  iVar4 = props_callBuiltinMethod((uint)*(byte *)((int)local_138 + 0x68023abd),(int)&local_dc,
                                       (int)this,(byte *)&local_dc);
                  if (iVar4 == 0) {
                    local_18 = ((int)local_d8 * 0x100 + 0x80) / 0xff;
                  }
                  break;
                case (int *)0x377:
                  iVar4 = props_callBuiltinMethod(&local_dc,extraout_EDX,(int)this,(byte *)&local_dc);
                  if (iVar4 == 0) {
                    local_134 = (uint)(local_d8 != (int *)0x0);
                  }
                  break;
                case (int *)0x3b2:
                  iVar4 = cast_blendInk(&local_dc,this);
                  uVar3 = local_148;
                  if ((iVar4 != 0) && (iVar4 = Ordinal_1114(local_148), iVar4 != 0)) {
                    local_f0 = cast_getPaletteIndex();
                    if (local_f0 == 0) {
                      local_144 = cast_processBitmap(this,iVar4);
                      local_110 = 0;
                      local_110 = Ordinal_1600();
                      Ordinal_1604(local_110,local_144);
                      local_f0 = Ordinal_1670(local_110,0,0,0);
                      Ordinal_1604(local_110,0);
                      Ordinal_1601(&local_110);
                      Ordinal_1653(&local_144);
                    }
                    Ordinal_1115(uVar3);
                  }
                  break;
                case (int *)0x3b3:
                  iVar4 = props_getRectField((int)this,(int *)&local_dc);
                  if (iVar4 != 0) {
                    local_150 = local_15c;
                    local_14c = local_160;
                  }
                }
              }
            }
            props_releaseValue(this,(byte)local_13c,local_138);
            props_releaseValue(this,(byte)local_dc,local_d8);
            local_114 = local_114 + 1;
          } while (local_114 <= iVar2);
        }
        if ((local_1c == 0x1a) || (local_1c == 0x1c)) {
          local_10 = local_e8;
          local_c = local_ec;
        }
        if (local_1c == 2) {
          local_14 = local_e8;
        }
        if (local_18 < 0x100) {
          local_1c = (uint)(local_1c == 2) * 2 + 10;
        }
      }
      local_128 = cast_processBitmap(this,(int)local_108);
      if ((local_128 != 0) && (iVar2 = Ordinal_1656(local_128,&local_d4), iVar2 != 0)) {
        if (local_c0 < 9) {
          local_104 = cast_getBitmapState((int)this);
        }
        local_fc = cast_processBitmap(this,(int)local_f4);
        if ((local_fc != 0) && (iVar2 = Ordinal_1656(local_fc,&local_a8), iVar2 != 0)) {
          if (((local_f8 == 0) && (8 < local_94)) ||
             (local_11c = cast_getBitmapState((int)this), 8 < local_94)) {
LAB_68023b07:
            if (((local_94 == 0x20) && (local_90 == 8)) &&
               ((local_c0 != 0x20 || ((local_bc != 8 || (local_f0 != 0)))))) {
              local_90 = 0;
              local_140 = 1;
              local_94 = 0x20;
              Ordinal_1657(local_fc,0x20,0,local_8c);
            }
          }
          else if ((((((local_f8 != 0) || (local_c0 != 8)) || (local_94 != 8)) ||
                    ((local_11c != local_104 || (local_f0 != 0)))) ||
                   ((local_10c == 0 && (local_20 - local_28 < local_30 - local_38)))) ||
                  ((local_1c != 0 && (local_1c != 2)))) {
            local_130 = cast_cachePalette();
            goto LAB_68023b07;
          }
          local_e4 = Ordinal_1600();
          local_e0 = Ordinal_1600();
          Ordinal_1604(local_e4,local_128);
          Ordinal_1604(local_e0,local_fc);
          Ordinal_1609(local_e4,local_104);
          Ordinal_1609(local_e0,local_11c);
          Ordinal_1611(local_e0,local_130);
          if (local_10c == 0) {
            cast_checkInkEffect(local_f4,(int)this);
            cast_checkInkEffect(local_108,(int)this);
            local_124 = Ordinal_1616(local_e0,local_2c,local_e4,local_3c,local_f0,&local_150,
                                     &local_1c,&local_ec,local_100);
          }
          else {
            cast_resetInkEffect(local_f4,(int)this);
            cast_checkInkEffect(local_108,(int)this);
            local_124 = Ordinal_1634(local_e0,local_7c,local_e4,local_3c,local_f0,&local_150,
                                     &local_1c,&local_ec,local_100,local_134);
          }
          Ordinal_1609(local_e4,0);
          Ordinal_1609(local_e0,0);
          Ordinal_1611(local_e0,0);
          Ordinal_1604(local_e4,0);
          Ordinal_1604(local_e0,0);
          Ordinal_1601(&local_e4);
          Ordinal_1601(&local_e0);
          if (local_140 != 0) {
            local_90 = 8;
            local_94 = 0x20;
            Ordinal_1657(local_fc,0x20,8,local_8c);
          }
        }
      }
    }
  }
  if (local_120 != 0) {
    Ordinal_1115(local_120);
  }
LAB_68023d8c:
  Ordinal_1653(&local_128);
  Ordinal_1653(&local_fc);
  Ordinal_1733(&local_104);
  Ordinal_1733(&local_11c);
  Ordinal_1671(&local_f0);
  if (local_124 != 0) {
    uVar3 = extraout_ECX_00;
    if (local_10c != 0) {
      Ordinal_1082(local_7c,local_2c);
      uVar3 = extraout_ECX_01;
    }
    cast_initBitmapOp(uVar3,(int)this);
  }
  return 0;
}



// ============================================================
// Function: cast_createBitmapFromSource (FUN_68023e80)
// Address: 68023e80
// Size: 119 bytes
// Params: void * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall cast_createBitmapFromSource(void *param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 local_c;
  int local_8;
  
  local_c = 0;
  local_8 = 0;
  local_8 = cast_processBitmap(param_1,in_EAX);
  if (local_8 != 0) {
    cast_processBitmapEx(param_1,in_EAX);
    iVar1 = cast_releaseBitmapRef();
    if (iVar1 == 0) {
      iVar1 = cast_compositeBitmapInk();
    }
    else {
      iVar1 = cast_convertBitmapDepth();
    }
    if (iVar1 != 0) {
      local_c = cast_setCastMemberData(iVar1,0,(undefined4 *)0x0,0,0);
    }
  }
  Ordinal_1653(&local_8);
  return local_c;
}



// ============================================================
// Function: cast_cropBitmap (FUN_68023f00)
// Address: 68023f00
// Size: 1003 bytes
// Params: void * param_1
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int __fastcall cast_cropBitmap(void *param_1)
{
  int iVar1;
  int iVar2;
  void *unaff_EBX;
  int local_b8;
  int local_b4;
  int local_b0;
  uint local_ac;
  uint local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  undefined4 local_98;
  undefined4 local_94;
  undefined4 local_90;
  undefined4 local_8c;
  undefined4 local_88;
  int local_84;
  undefined4 local_80;
  undefined4 local_7c;
  undefined4 local_78;
  undefined4 local_74;
  undefined4 local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60 [6];
  undefined1 local_48 [16];
  undefined1 local_38 [16];
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  uint local_8;
  
  local_b4 = 0;
  local_a4 = 0;
  local_98 = 0;
  local_94 = 0;
  local_90 = 0;
  local_8c = 0;
  local_88 = 0;
  local_84 = 0;
  local_80 = 0;
  local_7c = 0;
  local_78 = 0;
  local_74 = 0;
  local_70 = 0;
  local_9c = 0;
  local_a0 = 0;
  local_b0 = 0;
  local_a4 = cast_processBitmap(param_1,(int)unaff_EBX);
  if (local_a4 == 0) goto LAB_68024295;
  iVar1 = cast_initBitmapState((void *)0x2,(int)param_1);
  if (iVar1 == 0) {
    iVar1 = props_getRectField((int)param_1,
                         (int *)(**(int **)((int)param_1 + 0x10) +
                                 *(int *)((int)param_1 + 0x20) * -8 + 8 +
                                *(int *)((int)param_1 + 0x18)));
    if (iVar1 == 0) {
      iVar1 = props_getTypedValue((int)param_1,2,4,&local_6c);
      if ((((iVar1 == 0) || (iVar1 = props_getTypedValue((int)param_1,3,4,&local_68), iVar1 == 0)) ||
          (iVar1 = props_getTypedValue((int)param_1,4,4,&local_64), iVar1 == 0)) ||
         (iVar1 = props_getTypedValue((int)param_1,5,4,local_60), iVar1 == 0)) goto LAB_68024295;
    }
    else {
      local_6c = local_a8;
      local_68 = local_ac;
      iVar1 = props_getRectField((int)param_1,
                           (int *)(**(int **)((int)param_1 + 0x10) +
                                   (2 - *(int *)((int)param_1 + 0x20)) * 8 +
                                  *(int *)((int)param_1 + 0x18)));
      if (iVar1 == 0) {
        props_setErrorAndReturn((int)param_1,0xf);
        goto LAB_68024295;
      }
      local_64 = local_a8;
      local_60[0] = local_ac;
    }
  }
  iVar1 = Ordinal_1656(local_a4,&local_98);
  if (iVar1 != 0) {
    if (local_84 == 0x18) {
      local_b0 = 1;
      local_84 = 0x20;
    }
    local_a8 = cast_processBitmapEx(param_1,(int)unaff_EBX);
    local_28 = local_6c;
    local_24 = local_68;
    local_20 = local_64;
    local_1c = local_60[0];
    cast_checkInkEffect(unaff_EBX,(int)param_1);
    Ordinal_1060(local_38,0,0,local_94,local_98);
    iVar1 = Ordinal_1066(&local_18,&local_28,local_38);
    if (iVar1 == 0) {
      Ordinal_1061(&local_18);
      Ordinal_1061(&local_6c);
    }
    else {
      iVar1 = Ordinal_1063(&local_18,&local_28);
      if (iVar1 == 0) {
        Ordinal_1071(&local_6c,&local_28,&local_18);
      }
    }
    iVar1 = Ordinal_1650(local_84,local_80,local_7c,local_64 - local_6c,local_60[0] - local_68,0);
    if (iVar1 != 0) {
      local_9c = Ordinal_1600();
      local_a0 = Ordinal_1600();
      if ((local_9c != 0) && (local_a0 != 0)) {
        Ordinal_1604(local_9c,local_a4);
        Ordinal_1604(local_a0,iVar1);
        if ((local_b0 == 0) && (iVar2 = Ordinal_1063(&local_6c,&local_18), iVar2 != 0)) {
          local_b8 = -local_18;
          local_b4 = -local_14;
          Ordinal_1614(local_a0,&local_b8,local_9c,local_38);
        }
        else {
          Ordinal_1060(local_48,0,0,local_64 - local_6c,local_60[0] - local_68);
          local_60[1] = 0;
          iVar2 = Ordinal_1616(local_a0,local_48,local_9c,&local_18,0,0,local_60 + 1,0,0);
          if (iVar2 == 0) goto LAB_68024295;
        }
        local_b4 = cast_setCastMemberData(iVar1,0,(undefined4 *)0x0,0,0);
      }
    }
  }
LAB_68024295:
  Ordinal_1604(local_9c,0);
  Ordinal_1604(local_a0,0);
  Ordinal_1601(&local_9c);
  Ordinal_1601(&local_a0);
  Ordinal_1653(&local_a4);
  return 0;
}



// ============================================================
// Function: cast_createBitmapMatte (FUN_680242f0)
// Address: 680242f0
// Size: 366 bytes
// Params: void * param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_createBitmapMatte(void *param_1,int param_2)
{
  undefined1 uVar1;
  int iVar2;
  int local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  uint local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_44 = 0;
  local_38 = 0;
  uVar1 = 1;
  local_40 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  local_44 = cast_processBitmap(param_1,param_2);
  if (local_44 != 0) {
    iVar2 = Ordinal_1656(local_44,&local_34);
    if (iVar2 != 0) {
      if (local_20 < 9) {
        local_40 = cast_getBitmapState((int)param_1);
      }
      iVar2 = props_getInt((int)param_1);
      if (1 < iVar2) {
        iVar2 = **(int **)((int)param_1 + 0x10) + *(int *)((int)param_1 + 0x20) * -8;
        iVar2 = props_callBuiltinMethod(iVar2,*(int *)((int)param_1 + 0x18),(int)param_1,
                             (byte *)(iVar2 + 8 + *(int *)((int)param_1 + 0x18)));
        if ((iVar2 == 0) &&
           (iVar2 = **(int **)((int)param_1 + 0x10) + *(int *)((int)param_1 + 0x20) * -8 + 8 +
                    *(int *)((int)param_1 + 0x18), iVar2 != 0)) {
          uVar1 = *(undefined1 *)(iVar2 + 4);
        }
      }
      local_3c = 0x1ffffff;
      local_38 = Ordinal_1600();
      Ordinal_1604(local_38,local_44);
      Ordinal_1609(local_38,local_40);
      iVar2 = Ordinal_1670(local_38,3,&local_3c,uVar1);
      if (iVar2 != 0) {
        cast_setCastMemberData(0,iVar2,(undefined4 *)0x0,0,0);
      }
    }
  }
  Ordinal_1609(local_38,0);
  Ordinal_1604(local_38,0);
  Ordinal_1601(&local_38);
  Ordinal_1653(&local_44);
  Ordinal_1733(&local_40);
  return 0;
}



// ============================================================
// Function: cast_duplicateBitmap (FUN_68024460)
// Address: 68024460
// Size: 124 bytes
// Params: void * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall cast_duplicateBitmap(void *param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int local_c;
  undefined4 local_8;
  
  uVar2 = 0;
  local_c = 0;
  local_8 = 0;
  local_c = cast_processBitmap(param_1,in_EAX);
  if (local_c != 0) {
    local_8 = Ordinal_1600();
    Ordinal_1604(local_8,local_c);
    iVar1 = Ordinal_1670(local_8,0,0,0);
    if (iVar1 != 0) {
      Ordinal_1604(local_8,0);
      Ordinal_1601(&local_8);
      uVar2 = cast_setCastMemberData(0,iVar1,(undefined4 *)0x0,0,0);
    }
  }
  Ordinal_1653(&local_c);
  return uVar2;
}



// ============================================================
// Function: cast_transformBitmapPalette (FUN_680244e0)
// Address: 680244e0
// Size: 252 bytes
// Params: void * param_1, int param_2
// Return: undefined
// Calling convention: __fastcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int __fastcall cast_transformBitmapPalette(void *param_1,int param_2)
{
  int iVar1;
  undefined4 local_40;
  int local_3c;
  int local_38 [13];
  
  local_3c = 0;
  local_38[0] = 0;
  local_38[1] = 0;
  local_38[2] = 0;
  local_38[3] = 0;
  local_38[4] = 0;
  local_38[5] = 0;
  local_38[6] = 0;
  local_38[7] = 0;
  local_38[8] = 0;
  local_38[9] = 0;
  local_38[10] = 0;
  local_38[0xb] = 0;
  local_40 = 0;
  local_3c = cast_processBitmap(param_1,param_2);
  if (local_3c != 0) {
    iVar1 = Ordinal_1656(local_3c,local_38 + 1);
    if (iVar1 != 0) {
      local_40 = cast_getBitmapState((int)param_1);
      cast_processBitmapEx(param_1,param_2);
      iVar1 = cast_releaseBitmapRef();
      if (iVar1 == 0) {
        local_38[0] = cast_compositeBitmapInk();
      }
      else {
        local_38[0] = cast_convertBitmapDepth();
      }
      if (local_38[0] != 0) {
        iVar1 = Ordinal_1663(local_38,local_40,0);
        if (iVar1 != 0) {
          cast_setCastMemberData(local_38[0],0,(undefined4 *)0x0,0,0);
        }
      }
    }
  }
  Ordinal_1653(&local_3c);
  Ordinal_1733(&local_40);
  return 0;
}



// ============================================================
// Function: cast_applyInkMask (FUN_680245e0)
// Address: 680245e0
// Size: 232 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_applyInkMask(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 uVar4;
  int extraout_EDX;
  int iVar5;
  void *unaff_EDI;
  undefined4 local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  iVar5 = 0;
  local_8 = 0;
  local_8 = cast_processBitmap(unaff_EDI,param_1);
  if (((local_8 != 0) && (iVar2 = props_getInt((int)unaff_EDI), 1 < iVar2)) &&
     (puVar1 = (undefined4 *)
               (**(int **)((int)unaff_EDI + 0x10) + *(int *)((int)unaff_EDI + 0x20) * -8 + 8 +
               *(int *)((int)unaff_EDI + 0x18)), puVar1 != (undefined4 *)0x0)) {
    local_14 = *puVar1;
    local_10 = puVar1[1];
    iVar3 = cast_blendInk(&local_14,unaff_EDI);
    iVar2 = local_c;
    if (iVar3 == 0) {
      iVar2 = props_callBuiltinMethod(extraout_ECX,extraout_EDX,(int)unaff_EDI,(byte *)&local_14);
      if (iVar2 != 0) goto LAB_680246b6;
      iVar5 = Ordinal_1684(local_8,local_10);
      uVar4 = extraout_ECX_01;
    }
    else {
      iVar3 = Ordinal_1114(local_c);
      if (iVar3 != 0) {
        local_c = cast_processBitmap(unaff_EDI,iVar3);
        Ordinal_1115(iVar2);
      }
      if (local_c == 0) goto LAB_680246b6;
      iVar5 = Ordinal_1687(local_8,local_c);
      Ordinal_1653(&local_c);
      uVar4 = extraout_ECX_00;
    }
    if (iVar5 != 0) {
      cast_initBitmapOp(uVar4,(int)unaff_EDI);
    }
  }
LAB_680246b6:
  Ordinal_1653(&local_8);
  return iVar5;
}



// ============================================================
// Function: cast_trimBitmap (FUN_680246d0)
// Address: 680246d0
// Size: 91 bytes
// Params: void * param_1
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall cast_trimBitmap(void *param_1)

{
  int in_EAX;
  int iVar1;
  undefined4 uVar2;
  int local_c;
  undefined2 local_8;
  undefined2 local_6;
  
  uVar2 = 0;
  local_c = 0;
  local_c = cast_processBitmap(param_1,in_EAX);
  if (local_c != 0) {
    iVar1 = Ordinal_1688(local_c);
    if (iVar1 != 0) {
      local_8 = 0xffff;
      local_6 = 0xfffd;
      uVar2 = cast_setCastMemberData(iVar1,0,(undefined4 *)0x0,0,0);
    }
  }
  Ordinal_1653(&local_c);
  return uVar2;
}



// ============================================================
// Function: cast_generateNoiseBitmap (FUN_68024730)
// Address: 68024730
// Size: 1184 bytes
// Params: void * this, int param_1
// Return: undefined
// Calling convention: __thiscall
// ============================================================

int __thiscall cast_generateNoiseBitmap(void *this,int param_1)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  undefined4 extraout_ECX_02;
  undefined4 extraout_ECX_03;
  undefined4 extraout_ECX_04;
  undefined4 extraout_ECX_05;
  undefined4 extraout_ECX_06;
  undefined4 extraout_ECX_07;
  undefined4 extraout_ECX_08;
  undefined4 extraout_ECX_09;
  undefined4 extraout_ECX_10;
  undefined4 extraout_ECX_11;
  undefined4 extraout_ECX_12;
  undefined4 extraout_ECX_13;
  undefined4 uVar4;
  undefined4 extraout_ECX_14;
  undefined4 extraout_ECX_15;
  double local_b8;
  double local_b0;
  uint local_a8;
  uint local_a4;
  int *local_a0;
  void *local_9c;
  uint local_98;
  byte local_94 [4];
  int *local_90;
  int local_8c;
  int local_88;
  int local_84;
  uint local_80;
  int *local_7c;
  int *local_78;
  int local_74;
  int local_70;
  uint local_6c;
  int local_68;
  int local_64;
  int local_60;
  uint local_5c;
  int *local_58;
  int local_54;
  double *local_50;
  int local_4c;
  int local_48;
  undefined1 local_44 [16];
  undefined4 local_34;
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  local_84 = param_1;
  local_64 = 0;
  iVar1 = props_getInt((int)this);
  local_4c = 0;
  local_50 = (double *)0x0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  if (iVar1 < 6) {
    props_setError((int)this,0x19);
    uVar4 = extraout_ECX;
  }
  else {
    iVar2 = props_coerceAndReturnDouble((int)this,
                         (uint *)(**(int **)((int)this + 0x10) + *(int *)((int)this + 0x20) * -8 + 8
                                 + *(int *)((int)this + 0x18)),&local_b8);
    uVar4 = extraout_ECX_00;
    if ((((iVar2 == 0) &&
         (iVar2 = props_coerceAndReturnDouble((int)this,
                               (uint *)(**(int **)((int)this + 0x10) +
                                        (2 - *(int *)((int)this + 0x20)) * 8 +
                                       *(int *)((int)this + 0x18)),&local_b0),
         uVar4 = extraout_ECX_01, iVar2 == 0)) &&
        (iVar2 = props_coerceAndReturnInt((int)this,
                              (uint *)(**(int **)((int)this + 0x10) +
                                       (3 - *(int *)((int)this + 0x20)) * 8 +
                                      *(int *)((int)this + 0x18)),&local_48),
        uVar4 = extraout_ECX_02, iVar2 == 0)) &&
       ((iVar2 = props_coerceAndReturnInt((int)this,
                              (uint *)(**(int **)((int)this + 0x10) +
                                       (4 - *(int *)((int)this + 0x20)) * 8 +
                                      *(int *)((int)this + 0x18)),(int *)&local_9c),
        uVar4 = extraout_ECX_03, iVar2 == 0 &&
        (iVar2 = props_coerceAndReturnInt((int)this,
                              (uint *)(**(int **)((int)this + 0x10) +
                                       (5 - *(int *)((int)this + 0x20)) * 8 +
                                      *(int *)((int)this + 0x18)),&local_60),
        uVar4 = extraout_ECX_04, iVar2 == 0)))) {
      local_98 = (uint)(local_60 != 0);
      iVar2 = props_coerceAndReturnInt((int)this,
                           (uint *)(**(int **)((int)this + 0x10) +
                                    (6 - *(int *)((int)this + 0x20)) * 8 +
                                   *(int *)((int)this + 0x18)),&local_60);
      uVar4 = extraout_ECX_05;
      if (iVar2 == 0) {
        local_a8 = (uint)(local_60 != 0);
        local_88 = 7;
        local_6c = 0;
        local_4c = Ordinal_1126(local_48 * 8 + 8,0);
        uVar4 = extraout_ECX_06;
        if (local_4c != 0) {
          local_50 = (double *)Ordinal_1126(local_48 * 8 + 8,0);
          uVar4 = extraout_ECX_07;
          iVar2 = 0;
          if (local_50 == (double *)0x0) goto LAB_68024b9b;
          iVar2 = 0;
          if (local_48 != -1 && -1 < local_48 + 1) {
            do {
              local_50[iVar2] = 0.0;
              *(undefined8 *)(local_4c + iVar2 * 8) = 0;
              iVar2 = iVar2 + 1;
            } while (iVar2 < local_48 + 1);
          }
          if (6 < iVar1) {
            iVar1 = score_resolveProplistEntry((int)this,8,&local_78);
            if (iVar1 != 0) {
              local_8c = cast_getMemberData(this,local_78);
              local_68 = 1;
              if (0 < local_8c) {
                do {
                  cast_getContextData(this,local_78,local_68,&local_80,&local_5c);
                  props_resolveValue((int)this,&local_80);
                  if (local_80 == 8) {
                    local_54 = 0;
                    if (local_7c == (int *)0x2c1) {
                      iVar1 = props_coerceAndReturnInt((int)this,&local_5c,&local_54);
                      uVar4 = extraout_ECX_09;
                      if (iVar1 != 0) goto LAB_68024b89;
                      local_6c = (uint)(local_54 != 0);
                    }
                    else if (local_7c == (int *)0x644) {
                      iVar1 = props_coerceAndReturnInt((int)this,&local_5c,&local_54);
                      uVar4 = extraout_ECX_08;
                      if (iVar1 != 0) goto LAB_68024b89;
                      local_88 = local_54;
                    }
                    else if (local_7c == (int *)0x645) {
                      iVar1 = props_checkIsList(this,(int *)&local_5c);
                      if (iVar1 == 0) {
                        iVar1 = props_getContextState((int)this,&local_5c);
                        if ((iVar1 == 0) && (iVar1 = 0, 0 < local_48)) {
                          do {
                            iVar2 = iVar1 + 1;
                            *(double *)(local_4c + -8 + iVar2 * 8) = (double)local_70;
                            local_50[iVar1] = (double)local_74;
                            iVar1 = iVar2;
                          } while (iVar2 < local_48);
                        }
                      }
                      else {
                        iVar1 = props_resolveRef(this,&local_5c);
                        if (local_48 <= iVar1) {
                          iVar1 = local_48;
                        }
                        iVar2 = 1;
                        if (0 < iVar1) {
                          do {
                            iVar3 = props_callMethodDirect(this,&local_5c,iVar2,(int *)&local_a4);
                            if ((iVar3 == 0) &&
                               (iVar3 = props_getContextState((int)this,&local_a4), iVar3 == 0)) {
                              *(double *)(local_4c + iVar2 * 8) = (double)local_70;
                              local_50[iVar2] = (double)local_74;
                            }
                            props_releaseValue(this,(byte)local_a4,local_a0);
                            iVar2 = iVar2 + 1;
                          } while (iVar2 <= iVar1);
                        }
                      }
                    }
                  }
                  props_releaseValue(this,(byte)local_80,local_7c);
                  props_releaseValue(this,(byte)local_5c,local_58);
                  local_68 = local_68 + 1;
                } while (local_68 <= local_8c);
              }
            }
          }
          iVar1 = cast_processBitmap(this,local_84);
          uVar4 = extraout_ECX_10;
          if ((iVar1 != 0) &&
             (iVar2 = Ordinal_1656(iVar1,&local_34), uVar4 = extraout_ECX_11, iVar2 != 0)) {
            Ordinal_1060(local_44,0,0,local_30,local_34);
            iVar1 = cast_setCastMemberData(iVar1,0,(undefined4 *)0x0,0,0);
            uVar4 = extraout_ECX_12;
            if (iVar1 != 0) {
              cast_generateNoiseTexture(this,local_94,local_b8,local_b0,local_48,local_9c,local_98,local_a8,
                           (byte)local_88,local_6c,local_4c,local_50);
              props_releaseValue(this,local_94[0],local_90);
              local_64 = 1;
              uVar4 = extraout_ECX_13;
            }
          }
        }
      }
    }
  }
LAB_68024b89:
  iVar2 = local_64;
  if (local_50 != (double *)0x0) {
    Ordinal_1127(&local_50);
    uVar4 = extraout_ECX_14;
    iVar2 = local_64;
  }
LAB_68024b9b:
  if (local_4c != 0) {
    Ordinal_1127(&local_4c);
    uVar4 = extraout_ECX_15;
  }
  if (iVar2 != 0) {
    cast_initBitmapOp(uVar4,(int)this);
  }
  return 0;
}



// ============================================================
// Function: cast_dispatchImageCommand (FUN_68024bd0)
// Address: 68024bd0
// Size: 506 bytes
// Params: void * param_1, undefined4 param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_dispatchImageCommand(void *param_1,undefined4 param_2,int param_3)

{
  void *pvVar1;
  undefined4 local_10;
  int local_c;
  int local_8;
  
  local_8 = 1;
  pvVar1 = (void *)Ordinal_1114(param_2);
  if (pvVar1 == (void *)0x0) {
    return 0;
  }
  local_10 = 4;
  local_c = 0;
  if (param_3 < 0x370) {
    if (param_3 == 0x36f) {
      cast_getPixelValue(param_1,pvVar1,&local_10);
      goto LAB_68024da6;
    }
    if (param_3 == 0xe3) {
      Ordinal_1115(param_2);
      score_resolveType((uint)param_1);
      return 1;
    }
    if (param_3 == 0xe4) {
      cast_createBitmapFromSource(param_1);
      goto LAB_68024da6;
    }
    if (param_3 == 0x244) {
      cast_cropBitmap(param_1);
      goto LAB_68024da6;
    }
  }
  else if (param_3 < 0x388) {
    if (param_3 == 0x387) {
      local_c = cast_compositeInkBlend(param_1,pvVar1);
      goto LAB_68024da6;
    }
    if (param_3 == 0x370) {
      local_c = cast_setPixelRegion(pvVar1);
      goto LAB_68024da6;
    }
  }
  else {
    if (param_3 < 0x3b5) {
      if (param_3 == 0x3b4) {
        cast_duplicateBitmap(param_1);
        goto LAB_68024da6;
      }
      switch(param_3) {
      case 0x388:
        local_c = cast_renderBitmapEffect(pvVar1,param_1);
        break;
      case 0x389:
        cast_createBitmapMatte(param_1,(int)pvVar1);
        break;
      case 0x38a:
        cast_transformBitmapPalette(param_1,(int)pvVar1);
        break;
      case 0x38b:
        cast_trimBitmap(param_1);
        break;
      case 0x38c:
        local_c = cast_applyInkMask((int)pvVar1);
        break;
      case 0x38d:
        local_c = cast_renderBitmapTransition(param_1,pvVar1);
        break;
      default:
        goto switchD_68024cce_default;
      }
      goto LAB_68024da6;
    }
    if (param_3 < 0x644) {
      if (param_3 == 0x643) {
        cast_generateNoiseBitmap(param_1,(int)pvVar1);
        goto LAB_68024da6;
      }
      if (param_3 == 0x554) {
        local_c = cast_processBitmapPalette((int)pvVar1);
        goto LAB_68024da6;
      }
      if (param_3 == 0x63c) {
        cast_convertImageToBitmap((int)pvVar1);
        goto LAB_68024da6;
      }
    }
    else {
      if (param_3 == 0x658) {
        cast_exportBitmapImage(&local_10);
        goto LAB_68024da6;
      }
      if (param_3 == 0x659) {
        local_c = cast_importBitmap((int)pvVar1);
        goto LAB_68024da6;
      }
    }
  }
switchD_68024cce_default:
  local_8 = 0;
LAB_68024da6:
  Ordinal_1115(param_2);
  if (local_8 != 0) {
    props_popArgs((int)param_1,&local_10);
  }
  return local_8;
}



// ============================================================
// Function: cast_compareBitmaps (FUN_68024df0)
// Address: 68024df0
// Size: 411 bytes
// Params: void * param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 cast_compareBitmaps(void *param_1,undefined4 param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  undefined4 local_8;
  
  local_8 = 0;
  local_c = 0;
  local_10 = 0;
  local_14 = 0;
  local_18 = 0;
  if ((param_3 == 0xf) &&
     (puVar1 = (undefined4 *)(**(int **)((int)param_1 + 0x10) + -8 + *(int *)((int)param_1 + 0x18)),
     puVar1 != (undefined4 *)0x0)) {
    local_20 = *puVar1;
    local_1c = puVar1[1];
    local_24 = *(undefined4 *)((int)param_1 + 0x20);
    local_28 = *(undefined4 *)((int)param_1 + 0x1c);
    iVar2 = cast_blendInk(&local_20,param_1);
    if ((iVar2 == 0) || (iVar2 = cast_blendInk(&local_28,param_1), iVar2 == 0)) {
LAB_68024f19:
      Ordinal_1653(&local_14);
      Ordinal_1653(&local_18);
      props_popValue((int)param_1);
      props_popValue((int)param_1);
      props_pushValue((int)param_1);
      *(undefined4 *)((int)param_1 + 0x20) = local_8;
      *(undefined4 *)((int)param_1 + 0x1c) = 4;
      return 1;
    }
    iVar2 = Ordinal_1114(local_c);
    iVar3 = Ordinal_1114(local_10);
    if (iVar2 == 0) {
      iVar6 = local_10;
      if (iVar3 == 0) goto LAB_68024f6e;
    }
    else {
      iVar6 = local_c;
      if (iVar3 != 0) {
        uVar4 = cast_processBitmapEx(param_1,iVar2);
        uVar5 = cast_processBitmapEx(param_1,iVar3);
        (*(unsigned short *)((char *)&param_3 + 0)) = (short)uVar4;
        if (((short)param_3 == (short)uVar5) &&
           ((*(unsigned short *)((char *)&param_3 + 2)) = (short)((uint)uVar4 >> 0x10),
           (*(unsigned short *)((char *)&param_3 + 2)) == (short)((uint)uVar5 >> 0x10))) {
          if ((*(int *)(iVar2 + 0x20) == 0) || (*(int *)(iVar3 + 0x20) == 0)) {
            local_14 = cast_processBitmap(param_1,iVar2);
            local_18 = cast_processBitmap(param_1,iVar3);
            if ((local_14 != 0) && (local_18 != 0)) {
              if (local_14 == local_18) {
                local_8 = 1;
              }
              else {
                local_8 = Ordinal_1664(local_14,local_18);
              }
            }
          }
          else {
            local_8 = 1;
          }
        }
        if (local_c != 0) {
          Ordinal_1115(local_c);
        }
        if (local_10 != 0) {
          Ordinal_1115(local_10);
        }
        goto LAB_68024f19;
      }
    }
    if (iVar6 != 0) {
      Ordinal_1115(iVar6);
    }
  }
LAB_68024f6e:
  Ordinal_1653(&local_14);
  Ordinal_1653(&local_18);
  return 0;
}



