// Module: cast
// Topic: Image format conversion and pixel data handling
// Address range: 0x68021C20 - 0x68022220
// Functions (4):
//   cast_convertImageToBitmap (FUN_68021c20)
//   cast_encodePixelData (FUN_68021e90)
//   cast_exportBitmapImage (FUN_68022150)
//   cast_convertPixelFormat (FUN_68022220)

// ============================================================
// Function: cast_convertImageToBitmap (FUN_68021c20)
// Address: 68021c20
// Size: 609 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int cast_convertImageToBitmap(int param_1)
{
  int *piVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int extraout_ECX_02;
  int extraout_ECX_03;
  int extraout_ECX_04;
  int extraout_ECX_05;
  int extraout_ECX_06;
  int extraout_ECX_07;
  int extraout_ECX_08;
  int extraout_ECX_09;
  int extraout_ECX_10;
  int iVar5;
  void *unaff_EDI;
  int local_5c;
  uint local_58;
  int *local_54;
  undefined4 *local_50;
  int local_4c;
  int local_48;
  undefined4 local_44;
  undefined4 local_40;
  undefined4 local_3c;
  undefined4 local_38;
  undefined4 local_34;
  int local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  uint local_8;
  
  iVar5 = 0;
  local_48 = 0;
  local_4c = 0;
  local_5c = 0;
  local_50 = (undefined4 *)0x0;
  local_44 = 0;
  local_40 = 0;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  iVar2 = props_getInt((int)unaff_EDI);
  if ((iVar2 == 2) || (iVar2 == 3)) {
    iVar2 = *(int *)((int)unaff_EDI + 0x18);
    puVar3 = (uint *)(**(int **)((int)unaff_EDI + 0x10) + *(int *)((int)unaff_EDI + 0x20) * -8 + 8 +
                     iVar2);
    if (puVar3 != (uint *)0x0) {
      local_58 = *puVar3;
      piVar1 = (int *)puVar3[1];
      local_54 = piVar1;
      if (local_58 != 3) {
LAB_68021e2c:
        iVar5 = 0x13;
        goto LAB_68021e2e;
      }
      iVar2 = props_getInt((int)unaff_EDI);
      if (iVar2 == 3) {
        iVar2 = **(int **)((int)unaff_EDI + 0x10);
        puVar3 = (uint *)(iVar2 + (2 - *(int *)((int)unaff_EDI + 0x20)) * 8 +
                         *(int *)((int)unaff_EDI + 0x18));
        if (puVar3 == (uint *)0x0) goto LAB_68021e34;
        local_58 = *puVar3;
        local_54 = (int *)puVar3[1];
        if ((local_58 != 3) || (iVar2 = props_createRect(unaff_EDI,(int *)&local_58), iVar2 == 0))
        goto LAB_68021e2c;
        local_50 = &local_18;
      }
      local_4c = cast_processBitmap(unaff_EDI,param_1);
      iVar2 = extraout_ECX;
      if (local_4c == 0) goto LAB_68021e42;
      iVar4 = Ordinal_1656(local_4c,&local_44);
      iVar2 = extraout_ECX_00;
      if (iVar4 != 0) {
        if (local_50 == (undefined4 *)0x0) {
          local_50 = &local_18;
          local_14 = 0;
          local_18 = 0;
          local_c = local_40;
          local_10 = local_44;
        }
        iVar2 = (*(code *)**(undefined4 **)*piVar1)();
        if (iVar2 == 0xba) {
          local_48 = props_getListLength(unaff_EDI,piVar1);
          iVar2 = extraout_ECX_03;
          if (local_48 < 1) {
LAB_68021e21:
            local_48 = 1;
          }
          else {
            do {
              props_getListEntry(unaff_EDI,piVar1,iVar5,&local_58);
              iVar2 = extraout_ECX_04;
              if (local_54 != (int *)0x0) {
                if ((local_58 != 3) ||
                   (iVar2 = (*(code *)**(undefined4 **)*local_54)(), iVar2 != 0x63a)) {
                  props_setError((int)unaff_EDI,0x13);
                  iVar2 = extraout_ECX_07;
                  goto LAB_68021e21;
                }
                iVar4 = cast_setXtraTransform((int)unaff_EDI,local_54,local_4c,local_50);
                iVar2 = extraout_ECX_05;
                if (iVar4 != 0) {
                  props_setError((int)unaff_EDI,iVar4);
                  local_48 = 1;
                  iVar2 = extraout_ECX_06;
                  goto LAB_68021e34;
                }
              }
              iVar5 = iVar5 + 1;
            } while (iVar5 < local_48);
            local_48 = 1;
          }
        }
        else {
          if (iVar2 != 0x63a) goto LAB_68021e2c;
          iVar2 = extraout_ECX_01;
          if (local_30 == 0x20) {
            if (local_20 == 0) {
              Ordinal_1684(local_4c,0xff);
            }
            iVar5 = cast_setXtraTransform((int)unaff_EDI,piVar1,local_4c,local_50);
            iVar2 = extraout_ECX_02;
            if (iVar5 != 0) goto LAB_68021e2e;
          }
          local_48 = 1;
        }
      }
    }
  }
  else {
    iVar5 = 0x19;
LAB_68021e2e:
    props_setError((int)unaff_EDI,iVar5);
    iVar2 = extraout_ECX_08;
  }
LAB_68021e34:
  if (local_4c != 0) {
    Ordinal_1653(&local_4c);
    iVar2 = extraout_ECX_09;
  }
LAB_68021e42:
  if (local_5c != 0) {
    Ordinal_1604(local_5c,0);
    Ordinal_1601(&local_5c);
    iVar2 = extraout_ECX_10;
  }
  if (local_48 != 0) {
    cast_initBitmapOp(iVar2,(int)unaff_EDI);
  }
  return 0;
}



// ============================================================
// Function: cast_encodePixelData (FUN_68021e90)
// Address: 68021e90
// Size: 701 bytes
// Params: int param_1, undefined4 * param_2, int * param_3, int * param_4
// Return: undefined
// Calling convention: __fastcall
// ============================================================

int __fastcall cast_encodePixelData(int param_1,undefined4 *param_2,int *param_3,int *param_4)
{
  undefined1 *puVar1;
  undefined4 uVar2;
  int *piVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined4 *puVar6;
  undefined1 *puVar7;
  int iVar8;
  int *local_2c;
  int *local_28;
  int local_24;
  int *local_20;
  undefined4 *local_1c;
  int local_18;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 local_c;
  
  puVar7 = (undefined1 *)param_3[4];
  iVar8 = ((uint)param_3[5] >> 3) * param_3[1] * *param_3;
  local_20 = (int *)0x0;
  local_2c = (int *)0x0;
  local_1c = (undefined4 *)0x0;
  local_18 = *(int *)(*(int *)(param_1 + 8) + 4);
  local_28 = param_3;
  puVar1 = puVar7 + iVar8;
  local_24 = param_1;
  Ordinal_2330();
  local_14 = *(undefined4 *)(local_18 + 0x28);
  local_c = 0;
  local_10 = DAT_68196374;
  DAT_68196374 = &local_14;
  uVar2 = Ordinal_1038();
  piVar3 = (int *)Ordinal_2075(uVar2);
  if ((piVar3 != (int *)0x0) &&
     (iVar4 = (**(code **)(*piVar3 + 0xc))(piVar3,&DAT_68176608,&DAT_681765f8,&local_20), iVar4 == 0
     )) {
    iVar4 = *param_4;
    if (iVar4 < 0x65c) {
      if ((iVar4 < 0x65a) && (iVar4 != 0x43c)) {
LAB_680220f1:
        props_setError(local_24,0x79);
        goto LAB_680220fc;
      }
      local_18 = local_28[1] * *local_28 * 4;
    }
    else {
      if (1 < iVar4 - 0x65cU) goto LAB_680220f1;
      local_18 = local_28[1] * *local_28 * 3;
    }
    local_1c = (undefined4 *)Ordinal_1126(local_18,0);
    if ((local_1c != (undefined4 *)0x0) && (local_28[5] == 0x20)) {
      iVar4 = *param_4;
      if (iVar4 < 0x65b) {
        if (iVar4 == 0x65a) {
          if (puVar7 < puVar1) {
            puVar5 = puVar7 + 2;
            iVar8 = ((uint)(puVar1 + (-1 - (int)puVar7)) >> 2) + 1;
            puVar6 = local_1c;
            do {
              *puVar6 = CONCAT31(CONCAT21(CONCAT11(puVar5[-2],puVar5[-1]),*puVar5),puVar5[1]);
              puVar5 = puVar5 + 4;
              puVar6 = puVar6 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
        }
        else if (iVar4 == 0x43c) {
          if (puVar7 < puVar1) {
            puVar5 = puVar7 + 1;
            iVar8 = ((uint)(puVar1 + (-1 - (int)puVar7)) >> 2) + 1;
            puVar6 = local_1c;
            do {
              *puVar6 = CONCAT31(CONCAT21(CONCAT11(puVar5[2],puVar5[-1]),*puVar5),puVar5[1]);
              puVar5 = puVar5 + 4;
              puVar6 = puVar6 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
        }
        else {
LAB_68022048:
          props_setError(local_24,0x79);
        }
      }
      else if (iVar4 == 0x65b) {
        Ordinal_1128(local_1c,puVar7,iVar8);
      }
      else if (iVar4 == 0x65c) {
        if (puVar7 < puVar1) {
          puVar5 = (undefined1 *)((int)local_1c + 2);
          do {
            puVar5[-2] = puVar7[2];
            puVar5[-1] = puVar7[1];
            *puVar5 = *puVar7;
            puVar7 = puVar7 + 4;
            puVar5 = puVar5 + 3;
          } while (puVar7 < puVar1);
        }
      }
      else {
        if (iVar4 != 0x65d) goto LAB_68022048;
        if (puVar7 < puVar1) {
          puVar5 = (undefined1 *)((int)local_1c + 2);
          do {
            puVar5[-2] = *puVar7;
            puVar5[-1] = puVar7[1];
            *puVar5 = puVar7[2];
            puVar7 = puVar7 + 4;
            puVar5 = puVar5 + 3;
          } while (puVar7 < puVar1);
        }
      }
      (**(code **)(*local_20 + 0x1c))(local_20,local_18,0,local_1c);
      iVar8 = (**(code **)*local_20)(local_20,&DAT_68176308,&local_2c);
      if (iVar8 == 0) {
        score_setMediaProperty(local_24,local_2c,param_2);
        goto LAB_6802210b;
      }
    }
  }
LAB_680220fc:
  if (local_2c != (int *)0x0) {
    (**(code **)(*local_2c + 8))(local_2c);
  }
LAB_6802210b:
  if (local_20 != (int *)0x0) {
    (**(code **)(*local_20 + 8))(local_20);
  }
  if (local_1c != (undefined4 *)0x0) {
    Ordinal_1127(&local_1c);
  }
  DAT_68196374 = (undefined4 *)local_10;
  Ordinal_2331();
  return 0;
}



// ============================================================
// Function: cast_exportBitmapImage (FUN_68022150)
// Address: 68022150
// Size: 194 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Type propagation algorithm not settling */

int cast_exportBitmapImage(undefined4 *param_1)
{
  int iVar1;
  void *unaff_ESI;
  int unaff_EDI;
  uint local_3c;
  int local_38 [13];
  
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
  iVar1 = props_getInt((int)unaff_ESI);
  if (iVar1 == 2) {
    iVar1 = props_getTypedValue((int)unaff_ESI,2,8,&local_3c);
    if (iVar1 != 0) {
      local_38[0] = cast_processBitmap(unaff_ESI,unaff_EDI);
      if (local_38[0] == 0) goto LAB_680221ff;
      iVar1 = Ordinal_1654(local_38[0],local_38 + 1);
      if (iVar1 != 0) {
        cast_encodePixelData((int)unaff_ESI,param_1,local_38 + 1,(int *)&local_3c);
        Ordinal_1655(local_38[0]);
      }
    }
  }
  else {
    props_setError((int)unaff_ESI,0x15);
  }
  if (local_38[0] != 0) {
    Ordinal_1653(local_38);
  }
LAB_680221ff:
  return 0;
}



// ============================================================
// Function: cast_convertPixelFormat (FUN_68022220)
// Address: 68022220
// Size: 496 bytes
// Params: byte * param_1, int param_2, uint * param_3, int param_4
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall cast_convertPixelFormat(byte *param_1,int param_2,uint *param_3,int param_4)

{
  int in_EAX;
  byte *pbVar1;
  int iVar2;
  
  if (in_EAX < 0x65c) {
    if (((0x659 < in_EAX) || (in_EAX == 0x43c)) &&
       (param_2 = ((int)(param_2 + (param_2 >> 0x1f & 3U)) >> 2) * 4, param_4 < param_2)) {
      param_2 = param_4;
    }
  }
  else if ((0x65b < in_EAX) && (in_EAX < 0x65e)) {
    param_2 = (param_2 / 3) * 3;
    iVar2 = (int)((param_4 >> 0x1f & 3U) + param_4) >> 2;
    if (iVar2 < param_2 / 3) {
      param_2 = iVar2 * 3;
    }
  }
  if (in_EAX < 0x65b) {
    if (in_EAX == 0x65a) {
      if (param_1 < param_1 + param_2) {
        pbVar1 = param_1 + 2;
        iVar2 = ((uint)(param_1 + param_2 + (-1 - (int)param_1)) >> 2) + 1;
        do {
          *param_3 = CONCAT31(CONCAT21(CONCAT11(pbVar1[-2],pbVar1[-1]),*pbVar1),pbVar1[1]);
          pbVar1 = pbVar1 + 4;
          param_3 = param_3 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        return 1;
      }
    }
    else {
      if (in_EAX != 0x43c) {
        return 0;
      }
      if (param_1 < param_1 + param_2) {
        pbVar1 = param_1 + 1;
        iVar2 = ((uint)(param_1 + param_2 + (-1 - (int)param_1)) >> 2) + 1;
        do {
          *param_3 = CONCAT31(CONCAT21(CONCAT11(pbVar1[2],pbVar1[-1]),*pbVar1),pbVar1[1]);
          pbVar1 = pbVar1 + 4;
          param_3 = param_3 + 1;
          iVar2 = iVar2 + -1;
        } while (iVar2 != 0);
        return 1;
      }
    }
  }
  else if (in_EAX == 0x65b) {
    Ordinal_1128(param_3,param_1,param_2);
  }
  else if (in_EAX == 0x65c) {
    pbVar1 = param_1 + param_2;
    if (param_1 < pbVar1) {
      do {
        *param_3 = ((*param_1 | 0xffffff00) << 8 | (uint)param_1[1]) << 8 | (uint)param_1[2];
        param_1 = param_1 + 3;
        param_3 = param_3 + 1;
      } while (param_1 < pbVar1);
      return 1;
    }
  }
  else {
    if (in_EAX != 0x65d) {
      return 0;
    }
    pbVar1 = param_1 + param_2;
    if (param_1 < pbVar1) {
      do {
        *param_3 = ((param_1[2] | 0xffffff00) << 8 | (uint)param_1[1]) << 8 | (uint)*param_1;
        param_1 = param_1 + 3;
        param_3 = param_3 + 1;
      } while (param_1 < pbVar1);
      return 1;
    }
  }
  return 1;
}



