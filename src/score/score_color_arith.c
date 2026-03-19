// Module: score
// Topic: Color arithmetic and comparison operations
// Address range: 0x680484e0 - 0x68049680
// Functions (8):
//   score_colorFromInt (FUN_680484e0)
//   score_colorFromArgs (FUN_68048560)
//   score_computeColorOp (FUN_68048850)
//   score_computeColorFloatOp (FUN_68048bc0)
//   score_dispatchColorArith (FUN_68049400)
//   score_readColorValue (FUN_68049570)
//   score_wrapColorObject (FUN_68049650)
//   score_dateFromArgs (FUN_68049680)

// ============================================================
// Function: score_colorFromInt (FUN_680484e0)
// Address: 680484e0
// Size: 125 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_colorFromInt(uint param_1)
{
  uint3 uVar1;
  uint uVar2;
  int iVar3;
  int local_8;
  
  uVar2 = param_1;
  iVar3 = props_getInt(param_1);
  if (iVar3 != 1) {
    props_setError(uVar2,0x15);
    return 0;
  }
  iVar3 = props_requireInt(uVar2,(int *)(**(int **)(uVar2 + 0x10) + *(int *)(uVar2 + 0x20) * -8 +
                                    *(int *)(uVar2 + 0x18)),&local_8);
  if (iVar3 != 0) {
    uVar1 = (uint3)(param_1 >> 8);
    (*(unsigned int *)((char *)&param_1 + 1)) = uVar1 & 0xffff;
    if (local_8 < 0) {
      param_1 = (uint)(*(unsigned int *)((char *)&param_1 + 1)) << 8;
    }
    else {
      param_1 = CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),0xff);
      if (local_8 < 0x100) {
        param_1 = CONCAT31(uVar1,(char)local_8) & 0xffffff;
      }
    }
    iVar3 = score_createColorObject(uVar2,&param_1);
    props_normalizeType(uVar2,3,iVar3);
  }
  return 0;
}


// ============================================================
// Function: score_colorFromArgs (FUN_68048560)
// Address: 68048560
// Size: 740 bytes
// Params: uint param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_colorFromArgs(uint param_1)
{
  uint uVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  int local_c;
  int local_8;
  
  uVar1 = param_1;
  iVar2 = props_getInt(param_1);
  if (iVar2 == 1) {
    piVar4 = (int *)(**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 + *(int *)(uVar1 + 0x18)
                    );
LAB_680487ff:
    param_1 = param_1 & 0xffffff;
    iVar2 = props_requireInt(uVar1,piVar4,&local_8);
    if (iVar2 == 0) {
      return 0;
    }
    if (local_8 < 0) {
      param_1 = (uint)(*(unsigned int *)((char *)&param_1 + 1)) << 8;
    }
    else {
      param_1 = CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),0xff);
      if (local_8 < 0x100) {
        param_1 = CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),(char)local_8);
      }
    }
  }
  else {
    if (iVar2 == 3) {
      param_1 = CONCAT13(1,(uint3)param_1);
      iVar2 = props_requireInt(uVar1,(int *)(**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 +
                                        *(int *)(uVar1 + 0x18)),&local_8);
      if (iVar2 == 0) {
        return 0;
      }
      if (local_8 < 0) {
        param_1 = (uint)(*(unsigned int *)((char *)&param_1 + 1)) << 8;
      }
      else {
        param_1 = CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),0xff);
        if (local_8 < 0x100) {
          param_1 = CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),(char)local_8);
        }
      }
      iVar2 = props_requireInt(uVar1,(int *)(**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 + 8
                                        + *(int *)(uVar1 + 0x18)),&local_8);
      if (iVar2 == 0) {
        return 0;
      }
      if (local_8 < 0) {
        (*(unsigned short *)((char *)&param_1 + 0)) = (ushort)(byte)param_1;
        iVar2 = 2;
      }
      else {
        (*(unsigned short *)((char *)&param_1 + 0)) = CONCAT11(0xff,(byte)param_1);
        if (local_8 < 0x100) {
          (*(unsigned short *)((char *)&param_1 + 0)) = CONCAT11((char)local_8,(byte)param_1);
        }
        iVar2 = 2;
      }
    }
    else {
      if ((iVar2 != 2) && (iVar2 != 4)) {
LAB_68048594:
        props_setError(uVar1,0x19);
        return 0;
      }
      iVar3 = props_requireSymbolId(uVar1,(int *)(**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 +
                                        *(int *)(uVar1 + 0x18)),&local_c);
      if (iVar3 == 0) {
        return 0;
      }
      if (local_c != (iVar2 == 2) + 0xbf) {
        _DAT_68197764 =
             **(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 + *(int *)(uVar1 + 0x18);
        if (_DAT_68197764 == 0) {
          props_setErrorAndReturn(uVar1,0x3d);
          return 0;
        }
        DAT_6819776c = 0;
        DAT_68197768 = 0;
        props_setErrorAndReturn(uVar1,0x3d);
        return 0;
      }
      iVar2 = props_getInt(uVar1);
      if (iVar2 == 2) {
        piVar4 = (int *)(**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 + 8 +
                        *(int *)(uVar1 + 0x18));
        goto LAB_680487ff;
      }
      if (iVar2 != 4) goto LAB_68048594;
      param_1 = CONCAT13(1,(uint3)param_1);
      iVar2 = props_requireInt(uVar1,(int *)(**(int **)(uVar1 + 0x10) + *(int *)(uVar1 + 0x20) * -8 + 8
                                        + *(int *)(uVar1 + 0x18)),&local_8);
      if (iVar2 == 0) {
        return 0;
      }
      if (local_8 < 0) {
        param_1 = (uint)(*(unsigned int *)((char *)&param_1 + 1)) << 8;
      }
      else {
        param_1 = CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),0xff);
        if (local_8 < 0x100) {
          param_1 = CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),(char)local_8);
        }
      }
      iVar2 = props_requireInt(uVar1,(int *)(**(int **)(uVar1 + 0x10) + (2 - *(int *)(uVar1 + 0x20)) * 8
                                        + *(int *)(uVar1 + 0x18)),&local_8);
      if (iVar2 == 0) {
        return 0;
      }
      if (local_8 < 0) {
        (*(unsigned short *)((char *)&param_1 + 0)) = (ushort)(byte)param_1;
      }
      else {
        (*(unsigned short *)((char *)&param_1 + 0)) = CONCAT11(0xff,(byte)param_1);
        if (local_8 < 0x100) {
          (*(unsigned short *)((char *)&param_1 + 0)) = CONCAT11((char)local_8,(byte)param_1);
        }
      }
      iVar2 = 3;
    }
    iVar2 = props_requireInt(uVar1,(int *)(**(int **)(uVar1 + 0x10) +
                                       (iVar2 - *(int *)(uVar1 + 0x20)) * 8 + *(int *)(uVar1 + 0x18)
                                      ),&local_8);
    if (iVar2 == 0) {
      return 0;
    }
    if (local_8 < 0) {
      (*(unsigned int *)((char *)&param_1 + 0)) = (uint3)(ushort)param_1;
    }
    else if (local_8 < 0x100) {
      (*(unsigned int *)((char *)&param_1 + 0)) = CONCAT12((char)local_8,(ushort)param_1);
    }
    else {
      (*(unsigned int *)((char *)&param_1 + 0)) = CONCAT12(0xff,(ushort)param_1);
    }
  }
  iVar2 = score_createColorObject(uVar1,&param_1);
  props_normalizeType(uVar1,3,iVar2);
  return 0;
}


// ============================================================
// Function: score_computeColorOp (FUN_68048850)
// Address: 68048850
// Size: 808 bytes
// Params: int param_1, byte * param_2, int param_3, undefined4 * param_4
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x68048a20) */
/* WARNING: Removing unreachable block (ram,0x68048a67) */
/* WARNING: Removing unreachable block (ram,0x68048a80) */
/* WARNING: Removing unreachable block (ram,0x68048a37) */
/* WARNING: Removing unreachable block (ram,0x680489cc) */

undefined4 __fastcall score_computeColorOp(int param_1,byte *param_2,int param_3,undefined4 *param_4)

{
  byte bVar1;
  byte *in_EAX;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  undefined4 local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  byte local_5;
  
  if ((((param_1 == 5) || (param_1 == 4)) || (param_1 == 6)) || (param_1 == 7)) {
    bVar11 = true;
  }
  else {
    bVar11 = false;
  }
  bVar1 = param_2[3];
  if (!bVar11) {
    *param_4 = 4;
    switch(param_1) {
    case 0xe:
      iVar3 = Ordinal_1079(param_2);
      param_4[1] = (uint)(iVar3 == 0);
      return 1;
    case 0xf:
      uVar2 = Ordinal_1079(param_2);
      param_4[1] = uVar2;
      return 1;
    default:
      goto switchD_680488ad_caseD_10;
    case 0x24:
    case 0x25:
      goto switchD_680488ad_caseD_24;
    }
  }
  local_5 = bVar1;
  if (in_EAX[3] != bVar1) {
    local_c = *(undefined4 *)in_EAX;
    in_EAX = (byte *)&local_c;
    events_manageCastMember(param_3,(undefined2 *)in_EAX,(uint)bVar1);
  }
  uVar4 = (uint)*param_2;
  if (bVar1 != 0) {
    uVar6 = (uint)param_2[2];
    uVar8 = (uint)param_2[1];
    uVar10 = (uint)in_EAX[1];
    uVar7 = (uint)*in_EAX;
    uVar9 = (uint)in_EAX[2];
    switch(param_1 + -4) {
    case 0:
      local_8 = 0xff;
      if (uVar7 * uVar4 < 0x100) {
        local_8 = (undefined1)(uVar7 * uVar4);
      }
      local_7 = 0xff;
      if (uVar10 * uVar8 < 0x100) {
        local_7 = (undefined1)(uVar10 * uVar8);
      }
      uVar6 = uVar9 * uVar6;
      break;
    case 1:
      local_8 = 0xff;
      if (uVar7 + uVar4 < 0x100) {
        local_8 = (undefined1)(uVar7 + uVar4);
      }
      local_7 = 0xff;
      if (uVar10 + uVar8 < 0x100) {
        local_7 = (undefined1)(uVar10 + uVar8);
      }
      uVar6 = uVar9 + uVar6;
      break;
    case 2:
      iVar3 = uVar4 - uVar7;
      if (iVar3 < 0) {
        local_8 = 0;
      }
      else {
        local_8 = 0xff;
        if (iVar3 < 0x100) {
          local_8 = (undefined1)iVar3;
        }
      }
      iVar3 = uVar8 - uVar10;
      if (iVar3 < 0) {
        local_7 = 0;
        uVar6 = uVar6 - uVar9;
        bVar11 = (int)uVar6 < 0;
      }
      else {
        local_7 = 0xff;
        if (iVar3 < 0x100) {
          local_7 = (undefined1)iVar3;
        }
        uVar6 = uVar6 - uVar9;
        bVar11 = (int)uVar6 < 0;
      }
      goto LAB_68048b29;
    case 3:
      if (((uVar7 == 0) || (uVar10 == 0)) || (uVar9 == 0)) goto LAB_68048b62;
      uVar5 = (uint)((ulonglong)uVar4 / (ulonglong)(longlong)(int)uVar7);
      if ((int)uVar5 < 0) {
        local_8 = 0;
      }
      else {
        local_8 = 0xff;
        if (uVar5 < 0x100) {
          local_8 = (undefined1)((ulonglong)uVar4 / (ulonglong)(longlong)(int)uVar7);
        }
      }
      uVar8 = uVar8 / uVar10;
      if ((int)uVar8 < 0) {
        local_7 = 0;
      }
      else {
        local_7 = 0xff;
        if (uVar8 < 0x100) {
          local_7 = (undefined1)uVar8;
        }
      }
      uVar6 = uVar6 / uVar9;
      break;
    default:
      goto switchD_680488ad_caseD_10;
    }
    bVar11 = false;
LAB_68048b29:
    if (bVar11) {
      local_6 = 0;
    }
    else {
      local_6 = 0xff;
      if ((int)uVar6 < 0x100) {
        local_6 = (undefined1)uVar6;
      }
    }
    goto LAB_68048b3b;
  }
  uVar6 = (uint)*in_EAX;
  switch(param_1 + -4) {
  case 0:
    uVar6 = uVar6 * uVar4;
    if (0xff < uVar6) {
      local_8 = 0xff;
      goto LAB_68048b3b;
    }
LAB_68048990:
    local_8 = (undefined1)uVar6;
    goto LAB_68048b3b;
  case 1:
    uVar6 = uVar6 + uVar4;
    if (uVar6 < 0x100) goto LAB_68048990;
    goto LAB_680489de;
  case 2:
    iVar3 = uVar4 - uVar6;
    if (iVar3 < 0) {
      local_8 = 0;
      goto LAB_68048b3b;
    }
    break;
  case 3:
    if (uVar6 == 0) {
LAB_68048b62:
      props_setError(param_3,6);
switchD_680488ad_caseD_10:
      return 0;
    }
    iVar3 = (int)((ulonglong)uVar4 / (ulonglong)(longlong)(int)uVar6);
    break;
  default:
    goto switchD_680488ad_caseD_10;
  }
  if (iVar3 < 0x100) {
    local_8 = (undefined1)iVar3;
  }
  else {
LAB_680489de:
    local_8 = 0xff;
  }
LAB_68048b3b:
  *param_4 = 3;
  uVar2 = score_createColorObject(param_3,(undefined4 *)&local_8);
  param_4[1] = uVar2;
  return 1;
switchD_680488ad_caseD_24:
  uVar4 = (uint)*param_2;
  uVar6 = (uint)*in_EAX;
  if (bVar1 != 0) {
    iVar3 = uVar4 - uVar6;
    if ((iVar3 != 0) || (iVar3 = (uint)param_2[1] - (uint)in_EAX[1], iVar3 != 0)) goto LAB_68048913;
    uVar4 = (uint)param_2[2];
    uVar6 = (uint)in_EAX[2];
  }
  iVar3 = uVar4 - uVar6;
LAB_68048913:
  if (iVar3 < 0) {
    param_4[1] = 0xffffffff;
    return 1;
  }
  if (0 < iVar3) {
    iVar3 = 1;
  }
  param_4[1] = iVar3;
  return 1;
}


// ============================================================
// Function: score_computeColorFloatOp (FUN_68048bc0)
// Address: 68048bc0
// Size: 2073 bytes
// Params: byte * param_1, int param_2, int param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4
// Calling convention: __fastcall
// ============================================================

undefined4 __fastcall
score_computeColorFloatOp(byte *param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  byte bVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  undefined1 uVar5;
  undefined4 uVar6;
  undefined4 *unaff_EBX;
  int unaff_ESI;
  undefined4 local_8;
  
  bVar1 = param_1[3];
  (*(unsigned int *)((char *)&local_8 + 0)) = SUB43(param_1,0);
  local_8 = CONCAT13(bVar1,(undefined3)local_8);
  if (bVar1 == 0) {
    switch(param_2 + -4) {
    case 0:
      dVar2 = (double)*param_1 * (double)CONCAT44(param_5,param_4);
      dVar3 = 0.0;
      if ((0.0 <= dVar2) && (dVar3 = 255.0, dVar2 <= 255.0)) {
        dVar3 = dVar2;
      }
      (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
      local_8 = CONCAT31((*(unsigned int *)((char *)&local_8 + 1)),(undefined1)param_5);
      break;
    case 1:
      dVar2 = (double)*param_1 + (double)CONCAT44(param_5,param_4);
      dVar3 = 0.0;
      if ((0.0 <= dVar2) && (dVar3 = 255.0, dVar2 <= 255.0)) {
        dVar3 = dVar2;
      }
      (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
      local_8 = CONCAT31((*(unsigned int *)((char *)&local_8 + 1)),(undefined1)param_5);
      break;
    case 2:
      if (unaff_ESI == 0) {
        dVar2 = (double)*param_1 - (double)CONCAT44(param_5,param_4);
        dVar3 = 0.0;
        if ((0.0 <= dVar2) && (dVar3 = 255.0, dVar2 <= 255.0)) {
          dVar3 = dVar2;
        }
        (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
        local_8 = CONCAT31((*(unsigned int *)((char *)&local_8 + 1)),(undefined1)param_5);
      }
      else {
        dVar2 = (double)CONCAT44(param_5,param_4) - (double)*param_1;
        dVar3 = 0.0;
        if ((0.0 <= dVar2) && (dVar3 = 255.0, dVar2 <= 255.0)) {
          dVar3 = dVar2;
        }
        (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
        local_8 = CONCAT31((*(unsigned int *)((char *)&local_8 + 1)),(undefined1)param_5);
      }
      break;
    case 3:
      if (unaff_ESI == 0) {
        dVar2 = 0.0;
        if ((double)CONCAT44(param_5,param_4) != 0.0) {
          dVar3 = (double)*param_1 / (double)CONCAT44(param_5,param_4);
          if ((0.0 <= dVar3) && (dVar2 = 255.0, dVar3 <= 255.0)) {
            dVar2 = dVar3;
          }
          (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar2);
          local_8 = CONCAT31((*(unsigned int *)((char *)&local_8 + 1)),(undefined1)param_5);
          break;
        }
      }
      else if (*param_1 != 0) {
        dVar2 = (double)CONCAT44(param_5,param_4) / (double)*param_1;
        dVar3 = 0.0;
        if ((0.0 <= dVar2) && (dVar3 = 255.0, dVar2 <= 255.0)) {
          dVar3 = dVar2;
        }
        (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
        local_8 = CONCAT31((*(unsigned int *)((char *)&local_8 + 1)),(undefined1)param_5);
        break;
      }
LAB_68048da4:
      props_setError(param_3,6);
switchD_68048be2_default:
      return 0;
    default:
      goto switchD_68048be2_default;
    }
    goto LAB_680493ab;
  }
  switch(param_2 + -4) {
  case 0:
    dVar3 = (double)CONCAT44(param_5,param_4);
    dVar2 = (double)*param_1 * dVar3;
    dVar4 = 0.0;
    if ((0.0 <= dVar2) && (dVar4 = dVar2, 255.0 < dVar2)) {
      dVar4 = 255.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar4);
    uVar5 = (undefined1)param_5;
    dVar2 = (double)param_1[1] * dVar3;
    if (0.0 <= dVar2) {
      if (255.0 < dVar2) {
        dVar2 = 255.0;
      }
    }
    else {
      dVar2 = 0.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar2);
    (*(unsigned short *)((char *)&local_8 + 0)) = CONCAT11((undefined1)param_5,uVar5);
    dVar3 = (double)param_1[2] * dVar3;
    dVar2 = 0.0;
    if ((0.0 <= dVar3) && (dVar2 = dVar3, 255.0 < dVar3)) {
      dVar2 = 255.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar2);
    (*(unsigned int *)((char *)&local_8 + 0)) = CONCAT12((undefined1)param_5,(undefined2)local_8);
    local_8 = CONCAT13(bVar1,(undefined3)local_8);
    goto LAB_680493ab;
  case 1:
    dVar3 = (double)CONCAT44(param_5,param_4);
    dVar2 = (double)*param_1 + dVar3;
    dVar4 = 0.0;
    if ((0.0 <= dVar2) && (dVar4 = dVar2, 255.0 < dVar2)) {
      dVar4 = 255.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar4);
    uVar5 = (undefined1)param_5;
    dVar2 = (double)param_1[1] + dVar3;
    if (0.0 <= dVar2) {
      if (255.0 < dVar2) {
        dVar2 = 255.0;
      }
    }
    else {
      dVar2 = 0.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar2);
    (*(unsigned short *)((char *)&local_8 + 0)) = CONCAT11((undefined1)param_5,uVar5);
    dVar3 = (double)param_1[2] + dVar3;
    dVar2 = 0.0;
    if ((0.0 <= dVar3) && (dVar2 = dVar3, 255.0 < dVar3)) {
      dVar2 = 255.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar2);
    break;
  case 2:
    if (unaff_ESI == 0) {
      dVar3 = (double)CONCAT44(param_5,param_4);
      dVar2 = (double)*param_1 - dVar3;
      dVar4 = 0.0;
      if ((0.0 <= dVar2) && (dVar4 = dVar2, 255.0 < dVar2)) {
        dVar4 = 255.0;
      }
      (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar4);
      uVar5 = (undefined1)param_5;
      dVar2 = (double)param_1[1] - dVar3;
      if (0.0 <= dVar2) {
        if (255.0 < dVar2) {
          dVar2 = 255.0;
        }
      }
      else {
        dVar2 = 0.0;
      }
      (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar2);
      (*(unsigned short *)((char *)&local_8 + 0)) = CONCAT11((undefined1)param_5,uVar5);
      dVar3 = (double)param_1[2] - dVar3;
      dVar2 = 0.0;
      if ((0.0 <= dVar3) && (dVar2 = dVar3, 255.0 < dVar3)) {
        dVar2 = 255.0;
      }
      (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar2);
      (*(unsigned int *)((char *)&local_8 + 0)) = CONCAT12((undefined1)param_5,(undefined2)local_8);
      local_8 = CONCAT13(bVar1,(undefined3)local_8);
      goto LAB_680493ab;
    }
    dVar2 = (double)CONCAT44(param_5,param_4);
    dVar4 = dVar2 - (double)*param_1;
    dVar3 = 0.0;
    if ((0.0 <= dVar4) && (dVar3 = dVar4, 255.0 < dVar4)) {
      dVar3 = 255.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
    uVar5 = (undefined1)param_5;
    dVar3 = dVar2 - (double)param_1[1];
    if (0.0 <= dVar3) {
      if (255.0 < dVar3) {
        dVar3 = 255.0;
      }
    }
    else {
      dVar3 = 0.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
    (*(unsigned short *)((char *)&local_8 + 0)) = CONCAT11((undefined1)param_5,uVar5);
    dVar2 = dVar2 - (double)param_1[2];
    dVar3 = 0.0;
    if ((0.0 <= dVar2) && (dVar3 = dVar2, 255.0 < dVar2)) {
      dVar3 = 255.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
    break;
  case 3:
    if (unaff_ESI != 0) {
      if (((*param_1 != 0) && (param_1[1] != 0)) && (param_1[2] != 0)) {
        dVar2 = (double)CONCAT44(param_5,param_4);
        dVar4 = dVar2 / (double)*param_1;
        dVar3 = 0.0;
        if ((0.0 <= dVar4) && (dVar3 = dVar4, 255.0 < dVar4)) {
          dVar3 = 255.0;
        }
        (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
        uVar5 = (undefined1)param_5;
        dVar3 = dVar2 / (double)param_1[1];
        if (0.0 <= dVar3) {
          if (255.0 < dVar3) {
            dVar3 = 255.0;
          }
        }
        else {
          dVar3 = 0.0;
        }
        (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
        (*(unsigned short *)((char *)&local_8 + 0)) = CONCAT11((undefined1)param_5,uVar5);
        dVar2 = dVar2 / (double)param_1[2];
        dVar3 = 0.0;
        if ((0.0 <= dVar2) && (dVar3 = dVar2, 255.0 < dVar2)) {
          dVar3 = 255.0;
        }
        (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
        (*(unsigned int *)((char *)&local_8 + 0)) = CONCAT12((undefined1)param_5,(undefined2)local_8);
        local_8 = CONCAT13(bVar1,(undefined3)local_8);
        goto LAB_680493ab;
      }
      goto LAB_68048da4;
    }
    dVar2 = (double)CONCAT44(param_5,param_4);
    dVar3 = 0.0;
    if (dVar2 == 0.0) {
      props_setError(param_3,6);
      return 0;
    }
    dVar4 = (double)*param_1 / dVar2;
    if ((0.0 <= dVar4) && (dVar3 = dVar4, 255.0 < dVar4)) {
      dVar3 = 255.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
    uVar5 = (undefined1)param_5;
    dVar3 = (double)param_1[1] / dVar2;
    if (0.0 <= dVar3) {
      if (255.0 < dVar3) {
        dVar3 = 255.0;
      }
    }
    else {
      dVar3 = 0.0;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
    (*(unsigned short *)((char *)&local_8 + 0)) = CONCAT11((undefined1)param_5,uVar5);
    dVar2 = (double)param_1[2] / dVar2;
    dVar3 = 255.0;
    if (0.0 <= dVar2) {
      if (dVar2 <= 255.0) goto LAB_6804938b;
    }
    else {
      dVar2 = 0.0;
LAB_6804938b:
      dVar3 = dVar2;
    }
    (*(unsigned char *)((char *)&param_5 + 0)) = (undefined1)(int)ROUND(dVar3);
    break;
  default:
    goto switchD_68048be2_default;
  }
  (*(unsigned int *)((char *)&local_8 + 0)) = CONCAT12((undefined1)param_5,(undefined2)local_8);
LAB_680493ab:
  *unaff_EBX = 3;
  uVar6 = score_createColorObject(param_3,&local_8);
  unaff_EBX[1] = uVar6;
  return 1;
}


// ============================================================
// Function: score_dispatchColorArith (FUN_68049400)
// Address: 68049400
// Size: 363 bytes
// Params: int param_1, int * param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_dispatchColorArith(int param_1,int *param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  int iVar3;
  int *extraout_EDX;
  int *piVar4;
  double local_24;
  int local_1c;
  int *local_18;
  undefined4 local_14;
  uint local_10;
  int local_c;
  int *local_8;
  
  _DAT_68197764 = (int *)(**(int **)(param_1 + 0x10) + -8 + *(int *)(param_1 + 0x18));
  bVar2 = false;
  iVar3 = DAT_68197768;
  piVar4 = DAT_6819776c;
  if (_DAT_68197764 != (int *)0x0) {
    DAT_6819776c = (int *)0x0;
    DAT_68197768 = 0;
    iVar3 = *(int *)(size_t)_DAT_68197764;
    piVar4 = (int *)((int *)(size_t)_DAT_68197764)[1];
  }
  local_c = *(int *)(param_1 + 0x1c);
  local_8 = *(int **)(param_1 + 0x20);
  local_1c = iVar3;
  local_18 = piVar4;
  if ((local_c == 3) && (local_8 == param_2)) {
    local_18 = *(int **)(param_1 + 0x20);
    bVar2 = true;
    local_1c = 3;
    local_c = iVar3;
    local_8 = piVar4;
  }
  piVar4 = local_18;
  iVar3 = score_isColorObject(param_1,&local_c);
  if (iVar3 == 0) {
    iVar3 = props_coerceToFloat(param_1,&local_c,&local_24);
    if (iVar3 == 0) {
      if ((param_3 != 0xf) && (param_3 != 0xe)) {
        return 0;
      }
      local_10 = (uint)(param_3 == 0xe);
      local_14 = 4;
      iVar3 = 1;
      goto LAB_680494a7;
    }
    iVar3 = score_computeColorFloatOp((byte *)(*piVar4 + 8),param_3,param_1,SUB84(local_24,0),
                         (int)((ulonglong)local_24 >> 0x20));
    piVar4 = local_18;
  }
  else {
    if (bVar2) {
      iVar3 = *extraout_EDX;
    }
    else {
      iVar3 = *piVar4;
    }
    iVar3 = score_computeColorOp(param_3,(byte *)(iVar3 + 8),param_1,&local_14);
  }
  if (iVar3 == 0) {
    return 0;
  }
LAB_680494a7:
  *(int *)(param_1 + 0x18) = *(int *)(param_1 + 0x18) + -0x10;
  iVar1 = **(int **)(param_1 + 0x10);
  *(undefined4 *)(param_1 + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(param_1 + 0x18));
  *(undefined4 *)(param_1 + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(param_1 + 0x18));
  props_pushValue(param_1);
  *(undefined4 *)(param_1 + 0x1c) = local_14;
  *(uint *)(param_1 + 0x20) = local_10;
  props_releaseValue(param_1,(byte)local_1c,piVar4);
  props_releaseValue(param_1,(byte)local_c,local_8);
  return iVar3;
}


// ============================================================
// Function: score_readColorValue (FUN_68049570)
// Address: 68049570
// Size: 221 bytes
// Params: int * param_1, undefined4 param_2, int param_3, undefined4 * param_4
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint score_readColorValue(int *param_1,undefined4 param_2,int param_3,undefined4 *param_4)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint extraout_EDX;
  uint extraout_EDX_00;
  uint extraout_EDX_01;
  uint extraout_EDX_02;
  uint extraout_EDX_03;
  uint extraout_EDX_04;
  undefined8 uVar4;
  uint local_10;
  undefined1 local_c;
  int local_8;
  
  piVar1 = param_1;
  uVar4 = stage_allocFactorySlot((int)param_1,&local_8);
  if ((int)uVar4 != 0) {
    return (uint)((ulonglong)uVar4 >> 0x20);
  }
  if (param_3 == 1) {
    param_1 = (int *)((uint)param_1 & 0xffffff);
    uVar2 = stage_allocString(piVar1,&local_10);
    if (uVar2 != 0) {
      return extraout_EDX;
    }
    param_1 = (int *)CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),local_c);
  }
  else {
    iVar3 = param_3;
    if (param_3 == 3) {
      param_1 = (int *)CONCAT13(1,(*(unsigned int *)((char *)&param_1 + 0)));
      uVar2 = stage_allocString(piVar1,&local_10);
      if (uVar2 != 0) {
        return extraout_EDX_00;
      }
      param_1 = (int *)CONCAT31((*(unsigned int *)((char *)&param_1 + 1)),local_c);
      uVar2 = stage_allocString(piVar1,&local_10);
      if (uVar2 != 0) {
        return extraout_EDX_01;
      }
      (*(unsigned int *)((char *)&param_1 + 0)) = CONCAT12(local_c,(*(unsigned short *)((char *)&param_1 + 0)));
      uVar2 = stage_allocString(piVar1,&local_10);
      if (uVar2 != 0) {
        return extraout_EDX_02;
      }
      (*(unsigned short *)((char *)&param_1 + 0)) = CONCAT11(local_c,(*(unsigned char *)((char *)&param_1 + 0)));
    }
    else {
      while (0 < iVar3) {
        iVar3 = iVar3 + -1;
        uVar2 = stage_allocString(piVar1,&local_10);
        if (uVar2 != 0) {
          return extraout_EDX_03;
        }
      }
    }
  }
  iVar3 = score_createColorObject(*piVar1,&param_1);
  uVar2 = (uint)(iVar3 == 0);
  param_4[1] = iVar3;
  if (uVar2 == 0) {
    *param_4 = 3;
    stage_createFactory((int)piVar1,local_8,param_4);
    uVar2 = extraout_EDX_04;
  }
  return uVar2;
}


// ============================================================
// Function: score_wrapColorObject (FUN_68049650)
// Address: 68049650
// Size: 34 bytes
// Params: int param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_wrapColorObject(int param_1,undefined4 *param_2,undefined4 *param_3)
{
  undefined4 uVar1;
  
  *param_3 = 3;
  uVar1 = score_createColorObject(param_1,param_2);
  param_3[1] = uVar1;
  return 0;
}


// ============================================================
// Function: score_dateFromArgs (FUN_68049680)
// Address: 68049680
// Size: 832 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int score_dateFromArgs(int param_1)
{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  void *pvVar4;
  undefined4 uVar5;
  undefined4 extraout_ECX;
  int iVar6;
  uint uVar7;
  bool bVar8;
  ulonglong uVar9;
  undefined4 local_430;
  int local_42c;
  int local_428;
  uint local_424;
  void *pvStack_420;
  int local_41c;
  undefined1 local_418 [10];
  short local_40e;
  short local_40c;
  byte local_408;
  undefined1 local_407 [1023];
  uint local_8;
  
  iVar2 = props_getInt(param_1);
  if (iVar2 == 0) {
    _time64((__time64_t *)&local_424);
    ftime64(local_418);
    iVar2 = (int)local_40e;
    uVar3 = local_40c * 0xe10;
    local_41c = (int)uVar3 >> 0x1f;
    iVar6 = iVar2 * 0x3c >> 0x1f;
    uVar7 = uVar3 + iVar2 * -0x3c;
    bVar8 = CARRY4(local_424,uVar7);
    local_424 = local_424 + uVar7;
    pvStack_420 = (void *)((int)pvStack_420 +
                          (uint)bVar8 + ((local_41c - iVar6) - (uint)(uVar3 < (uint)(iVar2 * 0x3c)))
                          );
    uVar9 = strings_floatToUint64(iVar2,iVar6);
    local_41c = (int)uVar9;
    uVar9 = strings_floatToUint64(extraout_ECX,(int)(uVar9 >> 0x20));
    uVar5 = (undefined4)uVar9;
LAB_6804995f:
    local_42c = score_setDateProperty(param_1,local_41c,uVar5);
    if (local_42c != 0) {
      local_430 = 3;
      props_popArgs(param_1,&local_430);
      return 0;
    }
    iVar2 = 2;
  }
  else {
    if (iVar2 == 1) {
      _DAT_68197764 =
           (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                   *(int *)(param_1 + 0x18));
      pvVar4 = DAT_6819776c;
      uVar3 = DAT_68197768;
      if (_DAT_68197764 != (uint *)0x0) {
        DAT_6819776c = (void *)0x0;
        DAT_68197768 = 0;
        pvVar4 = (void *)((int *)(size_t)_DAT_68197764)[1];
        uVar3 = *(int *)(size_t)_DAT_68197764;
      }
      if ((uVar3 != 0x40) && (uVar3 != 0x43)) {
        if (uVar3 != 4) {
          _DAT_68197764 =
               (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                       *(int *)(param_1 + 0x18));
          if (_DAT_68197764 == (uint *)0x0) {
            props_setErrorAndReturn(param_1,10);
            return 0;
          }
          DAT_6819776c = (void *)0x0;
          DAT_68197768 = 0;
          props_setErrorAndReturn(param_1,10);
          return 0;
        }
        score_convertDateValue(pvVar4);
        goto LAB_6804995d;
      }
      Ordinal_1130(&local_408,0x400);
      _DAT_68197764 =
           (uint *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                   *(int *)(param_1 + 0x18));
      pvStack_420 = DAT_6819776c;
      local_424 = DAT_68197768;
      if (_DAT_68197764 != (uint *)0x0) {
        DAT_6819776c = (void *)0x0;
        DAT_68197768 = 0;
        pvStack_420 = (void *)((int *)(size_t)_DAT_68197764)[1];
        local_424 = *(int *)(size_t)_DAT_68197764;
      }
      props_toPascalString((int *)&local_424,&local_408);
      if (local_408 == 0xff) {
        uVar1 = Ordinal_1201(local_407);
      }
      else {
        uVar1 = (ushort)local_408;
      }
      score_parseDateString((int)(short)uVar1,&local_41c);
      uVar5 = 0;
      goto LAB_6804995f;
    }
    if (iVar2 == 3) {
      iVar2 = props_requireInt(param_1,(int *)(**(int **)(param_1 + 0x10) +
                                           *(int *)(param_1 + 0x20) * -8 + *(int *)(param_1 + 0x18))
                           ,(int *)&pvStack_420);
      if (((iVar2 == 0) ||
          (iVar2 = props_requireInt(param_1,(int *)(**(int **)(param_1 + 0x10) +
                                                *(int *)(param_1 + 0x20) * -8 + 8 +
                                               *(int *)(param_1 + 0x18)),&local_428), iVar2 == 0))
         || (iVar2 = props_requireInt(param_1,(int *)(**(int **)(param_1 + 0x10) +
                                                  (2 - *(int *)(param_1 + 0x20)) * 8 +
                                                 *(int *)(param_1 + 0x18)),&local_41c), iVar2 == 0))
      goto LAB_680499ad;
      local_41c = score_getColorValue(pvStack_420,local_41c);
LAB_6804995d:
      uVar5 = 0;
      goto LAB_6804995f;
    }
    iVar2 = 0x19;
  }
  props_setError(param_1,iVar2);
LAB_680499ad:
  return 0;
}


