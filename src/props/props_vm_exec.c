// Module: props
// Topic: VM execution, opcode dispatch, main interpreter loop
// Address range: 0x68033fb0 - 0x68034b30
// Functions (8):
//   props_tryNextIterator (FUN_68033fb0)
//   props_dispatchPropertyAccess (FUN_68034040)
//   props_executeOpcode (FUN_68034730)
//   props_fetchNextOpcode (FUN_680347f0)
//   props_reexecuteOpcode (FUN_68034810)
//   props_computeStringDelta (FUN_68034840)
//   props_reconvertStrings (FUN_68034920)
//   props_dispatchOpcode



// ============================================================
// Function: props_tryNextIterator (FUN_68033fb0)
// Address: 68033fb0
// Size: 144 bytes
// Return: undefined4
// Calling convention: __stdcall
// Tries to invoke a "next" iteration method on an object
// ============================================================

undefined4 props_tryNextIterator(void)

{
  int iVar1;
  int unaff_ESI;
  undefined4 *unaff_EDI;
  undefined4 local_c;
  undefined4 local_8;
  
  iVar1 = props_getInt(unaff_ESI);
  if ((iVar1 == 2) &&
     (*(int *)(**(int **)(unaff_ESI + 0x10) + *(int *)(unaff_ESI + 0x20) * -8 + 8 +
              *(int *)(unaff_ESI + 0x18)) == 8)) {
    iVar1 = (**(code **)(*(int *)*unaff_EDI + 0x18))();
    if (iVar1 != 0) {
      *(int *)(unaff_ESI + 0x18) = *(int *)(unaff_ESI + 0x18) + -8;
      iVar1 = **(int **)(unaff_ESI + 0x10);
      *(undefined4 *)(unaff_ESI + 0x1c) = *(undefined4 *)(iVar1 + *(int *)(unaff_ESI + 0x18));
      *(undefined4 *)(unaff_ESI + 0x20) = *(undefined4 *)(iVar1 + 4 + *(int *)(unaff_ESI + 0x18));
      props_popValue(unaff_ESI);
      props_releaseValue(unaff_ESI,(byte)*(undefined4 *)(unaff_ESI + 0x1c),*(int **)(unaff_ESI + 0x20));
      *(undefined4 *)(unaff_ESI + 0x1c) = local_c;
      *(undefined4 *)(unaff_ESI + 0x20) = local_8;
      return 1;
    }
  }
  return 0;
}



// ============================================================
// Function: props_dispatchPropertyAccess (FUN_68034040)
// Address: 68034040
// Size: 806 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// Dispatches a property access (get/set/delete) on an object's handler
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

int props_dispatchPropertyAccess(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 uVar6;
  int local_2c;
  int local_28;
  int local_24;
  int local_20;
  int *local_18;
  int *local_10;
  undefined4 local_c;
  int *local_8;
  
  iVar1 = param_1;
  iVar2 = props_getInt(param_1);
  if (*(int *)(param_1 + 0x18) < iVar2 * 8) {
    props_setError(param_1,0x33);
    return 0;
  }
  if ((param_2 < 0) || (*(int *)(**(int **)(param_1 + 0x28) + 0x14) <= param_2)) {
    props_setError(param_1,5);
    return 0;
  }
  *(int *)(param_1 + 0xa4) = param_2;
  iVar2 = props_getInt(param_1);
  if (iVar2 < 1) {
    if (*(int *)(param_1 + 0x7c) == 0x33) {
      return 0;
    }
    props_setError(param_1,0xc);
    return 0;
  }
  piVar3 = (int *)(**(int **)(param_1 + 0x10) + *(int *)(param_1 + 0x20) * -8 +
                  *(int *)(param_1 + 0x18));
  param_1 = *(int *)(**(int **)(param_1 + 0x28) + 0x24 + *(int *)(param_1 + 0xa4) * 0x18);
LAB_680340d0:
  while (iVar4 = *piVar3, iVar4 != 3) {
    if ((iVar4 != 0x40) && (iVar4 != 0x43)) {
      return 0;
    }
    local_20 = piVar3[1];
    local_24 = iVar4;
    iVar4 = score_getXtraProperty(iVar1,&local_24,0,(undefined4 *)0x0,&local_2c);
    if (iVar4 == 0) {
      return 0;
    }
    piVar3 = (int *)(**(int **)(iVar1 + 0x10) + *(int *)(iVar1 + 0x20) * -8 + *(int *)(iVar1 + 0x18)
                    );
    *piVar3 = local_2c;
    piVar3[1] = local_28;
  }
  iVar4 = (**(code **)(**(int **)piVar3[1] + 4))(iVar1,(undefined4 *)piVar3[1],param_1);
  if (iVar4 != 0) {
    return 0;
  }
  switch(param_1) {
  case 0x81:
  case 0xd4:
    if (iVar2 != 3) goto switchD_6803410d_caseD_82;
    _DAT_68197764 =
         (undefined4 *)
         (**(int **)(iVar1 + 0x10) + (2 - *(int *)(iVar1 + 0x20)) * 8 + *(int *)(iVar1 + 0x18));
    if (_DAT_68197764 == (undefined4 *)0x0) {
      local_10 = DAT_6819776c;
      uVar6 = DAT_68197768;
    }
    else {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_10 = (int *)((int *)(size_t)_DAT_68197764)[1];
      uVar6 = *(int *)(size_t)_DAT_68197764;
    }
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -8;
    *(undefined1 **)(iVar1 + 0x20) = &DAT_80000002;
    iVar4 = props_tryNextIterator();
    piVar3 = local_10;
    if (iVar4 != 0) {
      props_pushValue(iVar1);
      *(undefined4 *)(iVar1 + 0x1c) = uVar6;
      *(int **)(iVar1 + 0x20) = local_10;
      props_pushValue(iVar1);
      *(undefined1 **)(iVar1 + 0x20) = &DAT_80000002;
      piVar3 = (int *)(**(int **)(iVar1 + 0x10) + -0x10 + *(int *)(iVar1 + 0x18));
      param_1 = 0xd3;
      goto LAB_680340d0;
    }
    break;
  default:
    goto switchD_6803410d_caseD_82;
  case 0xdb:
    if (iVar2 != 4) goto switchD_6803410d_caseD_82;
    puVar5 = (undefined4 *)
             (**(int **)(iVar1 + 0x10) + (2 - *(int *)(iVar1 + 0x20)) * 8 + *(int *)(iVar1 + 0x18));
    if (puVar5 == (undefined4 *)0x0) {
      local_c = DAT_68197768;
      local_8 = DAT_6819776c;
    }
    else {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_c = *puVar5;
      local_8 = (int *)puVar5[1];
    }
    _DAT_68197764 =
         (undefined4 *)
         (**(int **)(iVar1 + 0x10) + (3 - *(int *)(iVar1 + 0x20)) * 8 + *(int *)(iVar1 + 0x18));
    uVar6 = DAT_68197768;
    local_18 = DAT_6819776c;
    if (_DAT_68197764 != (undefined4 *)0x0) {
      DAT_6819776c = (int *)0x0;
      DAT_68197768 = 0;
      local_18 = (int *)((int *)(size_t)_DAT_68197764)[1];
      uVar6 = *(int *)(size_t)_DAT_68197764;
    }
    *(int *)(iVar1 + 0x18) = *(int *)(iVar1 + 0x18) + -0x10;
    *(undefined1 **)(iVar1 + 0x20) = &DAT_80000002;
    iVar4 = props_tryNextIterator();
    if (iVar4 != 0) {
      props_pushValue(iVar1);
      *(undefined4 *)(iVar1 + 0x1c) = local_c;
      *(int **)(iVar1 + 0x20) = local_8;
      props_pushValue(iVar1);
      *(undefined4 *)(iVar1 + 0x1c) = uVar6;
      *(int **)(iVar1 + 0x20) = local_18;
      props_pushValue(iVar1);
      *(undefined4 *)(iVar1 + 0x20) = 3;
      piVar3 = (int *)(**(int **)(iVar1 + 0x10) + -0x18 + *(int *)(iVar1 + 0x18));
      param_1 = 0xda;
      goto LAB_680340d0;
    }
    props_releaseValue(iVar1,(byte)local_c,local_8);
    piVar3 = local_18;
    break;
  case 0xdd:
    iVar4 = props_tryNextIterator();
    if (iVar4 == 0) goto switchD_6803410d_caseD_82;
    props_pushValue(iVar1);
    *(undefined4 *)(iVar1 + 0x20) = 0x80000001;
    piVar3 = (int *)(**(int **)(iVar1 + 0x10) + -8 + *(int *)(iVar1 + 0x18));
    goto LAB_680340d0;
  }
  props_releaseValue(iVar1,(byte)uVar6,piVar3);
switchD_6803410d_caseD_82:
  if (*(int *)(iVar1 + 0x7c) != 0) {
    return 0;
  }
  props_reportError(iVar1,5);
  return 0;
}



// ============================================================
// Function: props_executeOpcode (FUN_68034730)
// Address: 68034730
// Size: 177 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// Decodes an opcode operand and dispatches to the opcode handler
// ============================================================

int props_executeOpcode(int param_1,int param_2)
{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined1 uVar4;
  int *piVar5;
  uint uVar6;
  int iVar7;
  
  iVar7 = param_2 >> 6;
  uVar6 = 0;
  *(int *)(param_1 + 0x104) = param_2;
  if (iVar7 == 1) {
    iVar7 = *(int *)(param_1 + 0x4c);
    uVar6 = (uint)*(byte *)(**(int **)(param_1 + 0x50) + iVar7);
  }
  else {
    if (iVar7 != 2) {
      if (iVar7 == 3) {
        piVar5 = *(int **)(param_1 + 0x50);
        iVar7 = *(int *)(param_1 + 0x4c);
        bVar1 = *(byte *)(*piVar5 + iVar7);
        *(int *)(param_1 + 0x4c) = iVar7 + 1;
        bVar2 = *(byte *)(*piVar5 + iVar7 + 1);
        *(int *)(param_1 + 0x4c) = iVar7 + 2;
        bVar3 = *(byte *)(iVar7 + 2 + *piVar5);
        *(int *)(param_1 + 0x4c) = iVar7 + 3;
        uVar6 = (uint)bVar1 << 0x18 | (uint)bVar2 << 0x10 | (uint)bVar3 << 8 |
                (uint)*(byte *)(iVar7 + 3 + *piVar5);
        *(int *)(param_1 + 0x4c) = iVar7 + 4;
      }
      goto LAB_680347bf;
    }
    uVar4 = *(undefined1 *)(**(int **)(param_1 + 0x50) + *(int *)(param_1 + 0x4c));
    iVar7 = *(int *)(param_1 + 0x4c) + 1;
    *(int *)(param_1 + 0x4c) = iVar7;
    uVar6 = (uint)CONCAT11(uVar4,*(undefined1 *)(**(int **)(param_1 + 0x50) + iVar7));
  }
  *(int *)(param_1 + 0x4c) = iVar7 + 1;
LAB_680347bf:
  (**(code **)(*(int *)(**(int **)(param_1 + 8) + 0x4e0) + param_2 * 4))(param_1,uVar6);
  *(undefined4 *)(param_1 + 0x104) = 0xffffffff;
  return 0;
}



// ============================================================
// Function: props_fetchNextOpcode (FUN_680347f0)
// Address: 680347f0
// Size: 24 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_fetchNextOpcode(void)
{
  byte bVar1;
  int in_EAX;
  
  bVar1 = *(byte *)(**(int **)(in_EAX + 0x50) + *(int *)(in_EAX + 0x4c));
  *(int *)(in_EAX + 0x4c) = *(int *)(in_EAX + 0x4c) + 1;
  props_executeOpcode(in_EAX,(uint)bVar1);
  return 0;
}



// ============================================================
// Function: props_reexecuteOpcode (FUN_68034810)
// Address: 68034810
// Size: 35 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_reexecuteOpcode(int param_1)
{
  props_executeOpcode(param_1,*(int *)(param_1 + 0x104));
  *(undefined4 *)(param_1 + 0x104) = 0xffffffff;
  return 0;
}



// ============================================================
// Function: props_computeStringDelta (FUN_68034840)
// Address: 68034840
// Size: 221 bytes
// Params: int param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int props_computeStringDelta(int param_1)

{
  char *pcVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  int *piVar6;
  int local_c;
  int local_8;
  
  local_c = *(int *)(param_1 + 0x88);
  iVar4 = *(int *)(param_1 + 0x94) + param_1;
  piVar6 = (int *)(*(int *)(param_1 + 0x8c) + param_1);
  local_8 = 0;
  if (local_c < 1) {
    return 0;
  }
  do {
    iVar5 = *piVar6;
    if (((iVar5 == 1) || (iVar5 == 0x40)) || (iVar5 == 0x43)) {
      iVar5 = piVar6[1];
      if ((iVar5 < 0) || (*(int *)(param_1 + 0x90) <= iVar5)) {
        piVar6[1] = 0;
      }
      else {
        uVar2 = *(uint *)(iVar5 + iVar4);
        pcVar1 = (char *)(iVar5 + 4 + iVar4);
        uVar3 = Ordinal_1274(pcVar1,uVar2,0,0);
        if ((*pcVar1 != '\0') && (pcVar1[uVar2 - 1] == '\0')) {
          uVar3 = uVar3 + 1;
        }
        if ((uVar3 & 3) == 0) {
          iVar5 = 0;
        }
        else {
          iVar5 = 4 - (uVar3 & 3);
        }
        if ((uVar2 & 3) == 0) {
          local_8 = local_8 + ((uVar3 + iVar5) - uVar2);
        }
        else {
          local_8 = local_8 + (((uVar3 + iVar5) - (4 - (uVar2 & 3))) - uVar2);
        }
      }
    }
    piVar6 = piVar6 + 2;
    local_c = local_c + -1;
  } while (local_c != 0);
  return local_8;
}



// ============================================================
// Function: props_reconvertStrings (FUN_68034920)
// Address: 68034920
// Size: 513 bytes
// Params: int param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int props_reconvertStrings(int param_1)
{
  uint *puVar1;
  uint uVar2;
  uint *_Src;
  uint *_Dst;
  int iVar3;
  uint uVar4;
  size_t _Size;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  int *piVar8;
  uint uVar9;
  int local_24;
  int local_14;
  uint *local_10;
  uint *local_8;
  
  _Src = (uint *)(*(int *)(param_1 + 0x94) + param_1);
  piVar8 = (int *)(*(int *)(param_1 + 0x8c) + param_1);
  _Dst = malloc(*(size_t *)(param_1 + 0x90));
  if (_Dst != (uint *)0x0) {
    memcpy(_Dst,_Src,*(size_t *)(param_1 + 0x90));
    local_14 = 0;
    local_24 = 0;
    local_10 = _Dst;
    iVar3 = 0;
    local_8 = _Src;
    if (0 < *(int *)(param_1 + 0x88)) {
      do {
        iVar3 = *piVar8;
        if (((iVar3 == 1) || (iVar3 == 0x40)) || (iVar3 == 0x43)) {
          iVar3 = piVar8[1];
          puVar6 = (uint *)(local_14 + iVar3 + (int)_Src);
          puVar1 = (uint *)(iVar3 + (int)_Dst);
          if (((-1 < iVar3) && (iVar3 < *(int *)(param_1 + 0x90))) &&
             ((local_10 <= puVar1 &&
              (puVar6 == (uint *)(((int)puVar1 - (int)local_10) + (int)local_8))))) {
            memcpy(local_8,local_10,(int)puVar1 - (int)local_10);
            uVar2 = *puVar1;
            puVar7 = puVar1 + 1;
            iVar3 = Ordinal_1274(puVar7,uVar2,0,0);
            iVar5 = *(int *)(param_1 + 0x90) - piVar8[1];
            if (((int)uVar2 <= iVar5) && (iVar3 <= iVar5)) {
              uVar4 = Ordinal_1274(puVar7,uVar2,puVar6 + 1,iVar3);
              uVar9 = uVar4;
              if (((char)*puVar7 != '\0') && (*(char *)((int)puVar1 + uVar2 + 3) == '\0')) {
                uVar9 = uVar4 + 1;
                *(undefined1 *)(uVar4 + 4 + (int)puVar6) = 0;
              }
              uVar4 = uVar9 & 3;
              *puVar6 = uVar9;
              if (uVar4 == 0) {
                _Size = 0;
              }
              else {
                _Size = 4 - uVar4;
              }
              memset((void *)(uVar9 + 4 + (int)puVar6),0,_Size);
              if ((uVar2 & 3) == 0) {
                iVar3 = 0;
              }
              else {
                iVar3 = 4 - (uVar2 & 3);
              }
              if (uVar4 == 0) {
                uVar4 = 0;
              }
              else {
                uVar4 = -uVar9 & 3;
              }
              piVar8[1] = piVar8[1] + local_14;
              local_14 = local_14 + ((uVar9 + uVar4) - (uVar2 + iVar3));
              local_10 = (uint *)((int)puVar1 + uVar2 + iVar3 + 4);
              local_8 = (uint *)((int)puVar6 + uVar9 + uVar4 + 4);
              goto LAB_68034ae1;
            }
          }
          piVar8[1] = 0;
          local_10 = puVar1;
          local_8 = puVar6;
        }
        else {
          piVar8[1] = piVar8[1] + local_14;
        }
LAB_68034ae1:
        local_24 = local_24 + 1;
        piVar8 = piVar8 + 2;
        iVar3 = local_14;
      } while (local_24 < *(int *)(param_1 + 0x88));
    }
    memcpy(local_8,local_10,(int)_Dst + *(int *)(param_1 + 0x90) + (-iVar3 - (int)local_10));
  }
  return 0;
}



// ============================================================
// Function: props_executeOpcode (FUN_68034b30)
// Address: 68034b30
// Size: 9557 bytes
// Params: int * param_1, int * param_2, undefined4 param_3, uint param_4
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool props_dispatchOpcode(int *param_1,int *param_2,int param_3,uint param_4)

{
  int *piVar1;
  uint *puVar2;
  byte bVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  int *piVar7;
  ushort uVar8;
  int *piVar9;
  int iVar10;
  uint uVar11;
  uint *puVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint *puVar16;
  byte *pbVar17;
  byte *pbVar18;
  byte *pbVar19;
  bool bVar20;
  int *piVar21;
  undefined4 local_18;
  uint local_14;
  uint *local_10;
  int local_c;
  int local_8;
  
  piVar9 = param_1;
  if (param_1[0x4e] != 0) {
    return false;
  }
  local_18 = 1;
  param_1[0x1f] = 0;
  param_1[0x1d] = (int)param_2;
  switch ((int)(size_t)param_2) { /* FIXUP(C2050): cast non-integral switch to int */
  case (int *)0x2:
    param_1[0x26] = -1;
    if (param_1[0x24] != 0) {
      param_1[0x1d] = 2;
      goto LAB_68034b92;
    }
    param_1[0x1d] = 0;
    break;
  default:
    param_1[0x26] = -1;
    props_pushValue((int)param_1);
    param_1[7] = 4;
    param_1[8] = 0;
    param_1[0x27] = param_3;
    param_1[0x28] = param_4;
    break;
  case (int *)0x12:
  case (int *)0x13:
  case (int *)0x14:
    if (param_1[0x41] < 1) {
      if (param_2 != (int *)0x14) {
        props_fetchNextOpcode();
        goto LAB_68034b92;
      }
      param_1[0x26] = -1;
      param_1[0x1d] = 0;
      goto switchD_68034ba8_caseD_4;
    }
    param_1[0x1e] = (int)param_2;
    props_reexecuteOpcode((int)param_1);
    if (param_1[0x1d] != 0x14) goto LAB_68034b92;
  case (int *)0x7:
    param_1[0x26] = -1;
    param_1[0x1d] = 0;
    goto switchD_68034ba8_caseD_4;
  case (int *)0x15:
    param_1[0x1d] = 9;
    goto LAB_68034b92;
  }
LAB_68034c20:
  iVar10 = piVar9[0x1d];
LAB_68034c28:
  props_pushFrame((int)piVar9,iVar10,local_18);
switchD_68034ba8_caseD_4:
  iVar10 = piVar9[0x1d];
  local_18 = 0;
  if (iVar10 == 0) {
LAB_68034ca4:
    iVar10 = cast_getRuntimeRef((int)piVar9);
    if (iVar10 == 0) {
      piVar7 = (int *)piVar9[0x14];
      piVar9[0x1e] = piVar9[0x1d];
      if (piVar7 == (int *)0x0) goto LAB_68036fee;
      local_14 = 0;
      local_c = *piVar7;
      local_8 = *(int *)piVar9[4];
      puVar16 = (uint *)(piVar9[6] + local_8);
      pbVar18 = (byte *)(piVar9[0x13] + local_c);
      param_1 = (int *)piVar9[8];
      param_4 = piVar9[7];
      local_10 = (uint *)(piVar9[6] + local_8);
LAB_68034d60:
      do {
        iVar10 = piVar9[6];
        if (piVar9[5] <= iVar10 + 100) {
          iVar10 = props_growStack((int)piVar9,100);
          if (iVar10 == 0) goto LAB_68036fee;
          local_8 = *(int *)piVar9[4];
          iVar10 = piVar9[6];
          puVar16 = (uint *)(iVar10 + local_8);
          local_10 = puVar16;
        }
        if ((0 < piVar9[0x10]) && (iVar10 < piVar9[0x10] + 0x34)) {
          props_setError((int)piVar9,0x33);
          piVar9[0x4e] = 1;
          goto LAB_68036fee;
        }
        uVar11 = (uint)*pbVar18;
        pbVar17 = pbVar18 + 1;
        if (0xf3 < uVar11) {
switchD_68034dbd_caseD_24:
          props_setErrorAndReturn((int)piVar9,0x33);
          piVar9[0x4e] = 1;
          goto switchD_68034dbd_caseD_0;
        }
        uVar14 = (int)uVar11 >> 6;
        switch(uVar11) {
        case 0:
          goto switchD_68034dbd_caseD_0;
        case 1:
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[7] = 0;
          piVar9[8] = 0;
          piVar9[0x1d] = 1;
          props_unwindStack((int)piVar9);
          goto switchD_68034dbd_caseD_0;
        case 2:
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[0x13] = (int)pbVar17 - local_c;
          if ((int *)piVar9[0x18] == (int *)0x0) {
            piVar9[7] = 0;
            piVar9[8] = 0;
            piVar9[0x1d] = 1;
          }
          else {
            puVar16 = score_lookupProperty((int *)piVar9[0x18],0x3f,0,(uint *)0x0);
            if ((puVar16 == (uint *)0x0) || (*puVar16 != 6)) {
              piVar9[7] = 0;
              piVar9[8] = 0;
              piVar9[0x1d] = 1;
            }
            else {
              piVar9[7] = *puVar16;
              piVar9[8] = puVar16[1];
              piVar9[0x1d] = 1;
            }
          }
          goto LAB_68034b92;
        case 3:
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          local_10 = puVar16 + 2;
          param_4 = 4;
          param_1 = (int *)0x0;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 4:
          if ((puVar16[-2] == 4) && (param_4 == 4)) {
            param_1 = (int *)(puVar16[-1] * (int)param_1);
            local_10 = puVar16 + -2;
            puVar16 = local_10;
            pbVar18 = pbVar17;
            local_14 = uVar11;
            goto LAB_68034d60;
          }
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          score_computeArithmetic((int)piVar9,4,puVar16[-2],(int *)puVar16[-1]);
          break;
        case 5:
          if ((puVar16[-2] != 4) || (param_4 != 4)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            piVar21 = (int *)puVar16[-1];
            uVar14 = puVar16[-2];
            iVar10 = 5;
LAB_68034ed8:
            score_computeArithmetic((int)piVar9,iVar10,uVar14,piVar21);
            goto LAB_68034ede;
          }
          param_1 = (int *)((int)param_1 + puVar16[-1]);
          local_10 = puVar16 + -2;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 6:
          if ((puVar16[-2] != 4) || (param_4 != 4)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            score_computeArithmetic((int)piVar9,6,puVar16[-2],(int *)puVar16[-1]);
            goto LAB_68034f59;
          }
          param_1 = (int *)(puVar16[-1] - (int)param_1);
          local_10 = puVar16 + -2;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 7:
          if ((puVar16[-2] != 4) || (param_4 != 4)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            piVar21 = (int *)puVar16[-1];
            uVar14 = puVar16[-2];
            iVar10 = 7;
            goto LAB_68034ed8;
          }
          if (param_1 == (int *)0x0) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = 4;
            piVar9[8] = 0;
            props_setError((int)piVar9,6);
            goto switchD_68034dbd_caseD_0;
          }
          param_1 = (int *)((int)puVar16[-1] / (int)param_1);
          local_10 = puVar16 + -2;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 8:
          if ((puVar16[-2] != 4) || (param_4 != 4)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            score_moduloCoerce((int)piVar9);
            goto LAB_68034ede;
          }
          if (param_1 != (int *)0x0) {
            param_1 = (int *)((int)puVar16[-1] % (int)param_1);
          }
          local_10 = puVar16 + -2;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 9:
          if (param_4 != 4) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            score_negateValue((int)piVar9);
            goto LAB_68034f59;
          }
          param_1 = (int *)-(int)param_1;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 10:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          score_stringConcat((int)piVar9);
          break;
        case 0xb:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          score_stringConcatSpace((int)piVar9);
          goto LAB_68034ede;
        case 0xc:
          if ((puVar16[-2] == 4) && (param_4 == 4)) {
            param_1 = (int *)(uint)((int)puVar16[-1] < (int)param_1);
            local_10 = puVar16 + -2;
            puVar16 = local_10;
            pbVar18 = pbVar17;
            local_14 = uVar11;
            goto LAB_68034d60;
          }
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_compareStrings((int)piVar9,0xc,-1,0);
          break;
        case 0xd:
          if ((puVar16[-2] != 4) || (param_4 != 4)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            stage_compareStrings((int)piVar9,0xd,1,1);
            goto LAB_68034f59;
          }
          param_1 = (int *)(uint)((int)puVar16[-1] <= (int)param_1);
          local_10 = puVar16 + -2;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 0xe:
          if ((puVar16[-2] != 4) || (param_4 != 4)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            stage_compareStrings((int)piVar9,0xe,0,1);
            goto LAB_68034ede;
          }
          param_1 = (int *)(uint)((int *)puVar16[-1] != param_1);
          local_10 = puVar16 + -2;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 0xf:
          if ((puVar16[-2] == 4) && (param_4 == 4)) {
            param_1 = (int *)(uint)((int *)puVar16[-1] == param_1);
            local_10 = puVar16 + -2;
            puVar16 = local_10;
            pbVar18 = pbVar17;
            local_14 = uVar11;
            goto LAB_68034d60;
          }
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_compareStrings((int)piVar9,0xf,0,0);
          break;
        case 0x10:
          if ((puVar16[-2] != 4) || (param_4 != 4)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            stage_compareStrings((int)piVar9,0x10,1,0);
            goto LAB_68034f59;
          }
          param_1 = (int *)(uint)((int)param_1 < (int)puVar16[-1]);
          local_10 = puVar16 + -2;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 0x11:
          if ((puVar16[-2] != 4) || (param_4 != 4)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            stage_compareStrings((int)piVar9,0x11,-1,1);
            goto LAB_68034ede;
          }
          param_1 = (int *)(uint)((int)param_1 <= (int)puVar16[-1]);
          local_10 = puVar16 + -2;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 0x12:
          if ((puVar16[-2] != 4) || (param_4 != 4)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            score_logicalAndCoerce((int)piVar9);
            goto LAB_68034ede;
          }
          if ((puVar16[-1] == 0) || (bVar20 = param_1 == (int *)0x0, param_1 = (int *)0x1, bVar20))
          {
            param_1 = (int *)0x0;
          }
          local_10 = puVar16 + -2;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 0x13:
          if ((puVar16[-2] != 4) || (param_4 != 4)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            score_logicalOrCoerce((int)piVar9);
            goto LAB_68034ede;
          }
          if ((puVar16[-1] != 0) || (bVar20 = param_1 != (int *)0x0, param_1 = (int *)0x0, bVar20))
          {
            param_1 = (int *)0x1;
          }
          local_10 = puVar16 + -2;
          puVar16 = local_10;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 0x14:
          if (((byte)param_4 & 0x1f) == 3) {
            iVar10 = *param_1;
            piVar21 = (int *)(iVar10 + 4);
            *piVar21 = *piVar21 + -1;
            if (*(int *)(iVar10 + 4) < 1) {
              (**(code **)(*(int *)*param_1 + 0xc))(piVar9,param_1);
              param_4 = 4;
              param_1 = (int *)(uint)(param_1 == (int *)0x0);
              goto switchD_68034dbd_caseD_0;
            }
          }
          else if ((param_4 & 1) != 0) {
            cast_freeHandle(param_1);
          }
          param_4 = 4;
          param_1 = (int *)(uint)(param_1 == (int *)0x0);
          goto switchD_68034dbd_caseD_0;
        case 0x15:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_compareStackValue((int)piVar9,1);
          goto LAB_68034f59;
        case 0x16:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_compareStackValue((int)piVar9,0);
          goto LAB_68034f59;
        case 0x17:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_extractChunkSubstring((int)piVar9);
          break;
        case 0x18:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_hiliteChunk(piVar9);
          goto LAB_68034ede;
        case 0x19:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_putChunkValue((int)piVar9);
          goto LAB_68034f59;
        case 0x1a:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_putChunkValueAfter((int)piVar9);
          break;
        case 0x1b:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_evalChunkAndPush((int)piVar9);
          goto LAB_68034ede;
        case 0x1c:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_iterateInit((int)piVar9);
LAB_68034f59:
          local_c = *piVar7;
          param_4 = piVar9[7];
          param_1 = (int *)piVar9[8];
          pbVar17 = (byte *)(piVar9[0x13] + local_c);
          local_8 = *(int *)piVar9[4];
          puVar16 = (uint *)(piVar9[6] + local_8);
          local_10 = puVar16;
          goto switchD_68034dbd_caseD_0;
        case 0x1d:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_iterateNext((int)piVar9);
          break;
        case 0x1e:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          props_getRectOpsCount((int)piVar9);
          break;
        case 0x1f:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          score_initProplistDispatch((int)piVar9);
          break;
        case 0x20:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          cast_executeScriptHandler((int)piVar9);
          break;
        case 0x21:
          uVar14 = puVar16[-2];
          piVar21 = (int *)puVar16[-1];
          puVar16[-2] = param_4;
          puVar16[-1] = (uint)param_1;
          pbVar18 = pbVar17;
          param_1 = piVar21;
          param_4 = uVar14;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 0x22:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_putStackValue(piVar9);
          break;
        case 0x23:
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_getStackValue((int)piVar9);
          goto LAB_68034ede;
        default:
          goto switchD_68034dbd_caseD_24;
        case 0x26:
          if (local_14 != 0x44) goto LAB_68036f41;
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          core_dispatchExternalCall((uint)piVar9);
LAB_68034ede:
          local_c = *piVar7;
          param_1 = (int *)piVar9[8];
          pbVar17 = (byte *)(piVar9[0x13] + local_c);
          local_8 = *(int *)piVar9[4];
          puVar16 = (uint *)(piVar9[6] + local_8);
          param_4 = piVar9[7];
          local_10 = puVar16;
          goto switchD_68034dbd_caseD_0;
        case 0x41:
        case 0x81:
        case 0xc1:
          (*(unsigned char *)((char *)&param_2 + 0)) = *pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            (*(unsigned char *)((char *)&param_2 + 0)) = *pbVar19;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              (*(unsigned char *)((char *)&param_2 + 0)) = pbVar18[4];
              pbVar19 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          param_2 = (int *)(int)(char)(byte)param_2;
          goto LAB_68036d83;
        case 0x42:
        case 0x46:
        case 0x82:
        case 0x86:
        case 0xc2:
        case 0xc6:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          goto LAB_68036d83;
        case 0x43:
        case 0x83:
        case 0xc3:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          local_10 = puVar16 + 2;
          param_4 = 4;
          puVar16 = local_10;
          pbVar18 = pbVar19;
          param_1 = (int *)((uint)param_2 | 0x80000000);
          local_14 = uVar11;
          goto LAB_68034d60;
        case 0x44:
        case 0x84:
        case 0xc4:
          bVar3 = *pbVar17;
          param_2 = (int *)(uint)bVar3;
          pbVar17 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(bVar3,*pbVar17);
            param_2 = (int *)(uint)uVar8;
            pbVar17 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar17),pbVar18[4]);
              pbVar17 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          puVar16 = puVar16 + 2;
          local_10 = puVar16;
          if (((int)param_2 < 0) || (*(int *)(local_c + 0x88) <= (int)param_2)) {
            props_setError((int)piVar9,0x33);
            goto switchD_68034dbd_caseD_0;
          }
          iVar10 = *(int *)(local_c + 0x8c) + (int)param_2 * 8;
          param_1 = *(int **)(local_c + 4 + iVar10);
          param_4 = *(uint *)(local_c + iVar10) & 0xff;
          pbVar18 = pbVar17;
          local_14 = uVar11;
          if ((*(uint *)(local_c + iVar10) & 1) != 0) {
            piVar9[7] = param_4;
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[8] = (int)param_1;
            stage_resolveConstValue((int)piVar9,(uint *)(piVar9 + 7),iVar10);
            goto LAB_68034f59;
          }
          goto LAB_68034d60;
        case 0x45:
        case 0x85:
        case 0xc5:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          puVar16 = puVar16 + 2;
          param_4 = 8;
          pbVar18 = pbVar19;
          local_10 = puVar16;
          if (((int)param_2 < 0) || (*(int *)(*(int *)piVar9[10] + 0x14) <= (int)param_2)) {
            props_setError((int)piVar9,0x33);
            param_1 = (int *)0x0;
            local_14 = uVar11;
          }
          else {
            param_1 = *(int **)(*(int *)piVar9[10] + 0x24 + (int)param_2 * 0x18);
            local_14 = uVar11;
          }
          goto LAB_68034d60;
        case 0x47:
        case 0x87:
        case 199:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)(puVar16 + 1) + (4 - local_8);
          puVar12 = props_resolveVariable((int)piVar9,(uint)param_2,0,0);
          goto LAB_680358d6;
        case 0x48:
        case 0x88:
        case 200:
          bVar3 = *pbVar17;
          param_2 = (int *)(uint)bVar3;
          pbVar17 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(bVar3,*pbVar17);
            param_2 = (int *)(uint)uVar8;
            pbVar17 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar17),pbVar18[4]);
              pbVar17 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          local_10 = puVar16 + 2;
          puVar12 = (uint *)props_ensureProperty((int)piVar9,(uint)param_2,0);
          goto LAB_680358f3;
        case 0x49:
        case 0x89:
        case 0xc9:
          bVar3 = *pbVar17;
          param_2 = (int *)(uint)bVar3;
          pbVar17 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(bVar3,*pbVar17);
            param_2 = (int *)(uint)uVar8;
            pbVar17 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar17),pbVar18[4]);
              pbVar17 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          local_10 = puVar16 + 2;
          puVar12 = props_getProperty((int)piVar9,(uint)param_2,0,(undefined4 *)0x0);
          goto LAB_680358f3;
        case 0x4a:
        case 0x8a:
        case 0xca:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)(puVar16 + 1) + (4 - local_8);
          puVar12 = props_getLocalProperty((int)piVar9,(int)param_2,0);
LAB_680358d6:
          local_c = *piVar7;
          pbVar17 = (byte *)(piVar9[0x13] + local_c);
          local_8 = *(int *)piVar9[4];
          local_10 = (uint *)(piVar9[6] + local_8);
LAB_680358f3:
          puVar16 = local_10;
          if (puVar12 == (uint *)0x0) {
            param_4 = 2;
            param_1 = (int *)0x0;
          }
          else {
            param_4 = *puVar12;
            param_1 = (int *)puVar12[1];
            if (((byte)param_4 & 0x1f) == 3) {
              *(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) + 1;
            }
            else if ((param_4 & 1) != 0) {
              piVar9[0x13] = (int)pbVar17 - local_c;
              piVar9[6] = (int)local_10 - local_8;
              param_1 = (int *)props_copyHandle((int)piVar9);
              local_c = *piVar7;
              pbVar17 = (byte *)(piVar9[0x13] + local_c);
              local_8 = *(int *)piVar9[4];
              puVar16 = (uint *)(piVar9[6] + local_8);
              local_10 = (uint *)(piVar9[6] + local_8);
            }
          }
          goto switchD_68034dbd_caseD_0;
        case 0x4b:
        case 0x8b:
        case 0xcb:
          bVar3 = *pbVar17;
          uVar14 = (uint)bVar3;
          pbVar17 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(bVar3,*pbVar17);
            uVar14 = (uint)uVar8;
            pbVar17 = pbVar18 + 3;
            if (0xbf < uVar11) {
              uVar14 = CONCAT31(CONCAT21(uVar8,*pbVar17),pbVar18[4]);
              pbVar17 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          uVar14 = uVar14 * 8;
          puVar16[1] = (uint)param_1;
          if (-1 < (int)uVar14) {
            uVar15 = piVar9[0x11];
            uVar13 = ((int)uVar15 >> 0x1f) + ((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar15,uVar14);
            if (((-2 < (int)uVar13) &&
                ((((uVar13 < 0x80000000 || (0x80000000 < uVar15 + uVar14)) && ((int)uVar13 < 1)) &&
                 (((int)uVar13 < 0 || (uVar15 + uVar14 < 0x80000000)))))) &&
               ((int)(piVar9[0x11] + uVar14) < piVar9[0x10])) {
              puVar12 = (uint *)(piVar9[0x11] + local_8 + uVar14);
              param_4 = *puVar12;
              param_1 = (int *)puVar12[1];
              if (((byte)param_4 & 0x1f) == 3) goto LAB_68035c6e;
LAB_68035b5f:
              if ((param_4 & 1) == 0) goto LAB_68035c73;
              piVar9[6] = (int)puVar16 + (8 - local_8);
              piVar9[0x13] = (int)pbVar17 - local_c;
              param_1 = (int *)props_copyHandle((int)piVar9);
              local_c = *piVar7;
              pbVar17 = (byte *)(piVar9[0x13] + local_c);
              local_8 = *(int *)piVar9[4];
              puVar16 = (uint *)(piVar9[6] + local_8);
              local_10 = (uint *)(piVar9[6] + local_8);
              goto switchD_68034dbd_caseD_0;
            }
          }
          goto LAB_68036f41;
        case 0x4c:
        case 0x8c:
        case 0xcc:
          bVar3 = *pbVar17;
          uVar14 = (uint)bVar3;
          pbVar17 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(bVar3,*pbVar17);
            uVar14 = (uint)uVar8;
            pbVar17 = pbVar18 + 3;
            if (0xbf < uVar11) {
              uVar14 = CONCAT31(CONCAT21(uVar8,*pbVar17),pbVar18[4]);
              pbVar17 = pbVar18 + 5;
            }
          }
          *puVar16 = param_4;
          uVar14 = uVar14 * 8;
          puVar16[1] = (uint)param_1;
          if (-1 < (int)uVar14) {
            uVar15 = piVar9[0x12];
            uVar13 = ((int)uVar15 >> 0x1f) + ((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar15,uVar14);
            if (((((-2 < (int)uVar13) && ((uVar13 < 0x80000000 || (0x80000000 < uVar15 + uVar14))))
                 && ((int)uVar13 < 1)) && (((int)uVar13 < 0 || (uVar15 + uVar14 < 0x80000000)))) &&
               ((int)(piVar9[0x12] + uVar14) < piVar9[0x10])) {
              puVar12 = (uint *)(piVar9[0x12] + local_8 + uVar14);
              param_4 = *puVar12;
              param_1 = (int *)puVar12[1];
              if (((byte)param_4 & 0x1f) != 3) goto LAB_68035b5f;
LAB_68035c6e:
              *(int *)(*param_1 + 4) = *(int *)(*param_1 + 4) + 1;
LAB_68035c73:
              local_10 = puVar16 + 2;
              puVar16 = local_10;
              goto switchD_68034dbd_caseD_0;
            }
          }
          goto LAB_68036f41;
        case 0x4d:
        case 0x8d:
        case 0xcd:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          puVar12 = props_resolveVariable((int)piVar9,(uint)param_2,1,0);
          goto LAB_68035cdc;
        case 0x4e:
        case 0x8e:
        case 0xce:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          puVar12 = (uint *)props_ensureProperty((int)piVar9,(uint)param_2,1);
          goto LAB_68035cdc;
        case 0x4f:
        case 0x8f:
        case 0xcf:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_setProperty((uint)piVar9,(uint)param_2);
          local_c = *piVar7;
          local_8 = *(int *)piVar9[4];
          puVar16 = (uint *)(piVar9[6] + local_8);
          pbVar18 = (byte *)(piVar9[0x13] + local_c);
          param_1 = (int *)piVar9[8];
          param_4 = piVar9[7];
          local_14 = uVar11;
          local_10 = (uint *)(piVar9[6] + local_8);
          goto LAB_68034d60;
        case 0x50:
        case 0x90:
        case 0xd0:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          puVar12 = props_getLocalProperty((int)piVar9,(int)param_2,1);
LAB_68035cdc:
          local_c = *piVar7;
          pbVar18 = (byte *)(piVar9[0x13] + local_c);
          local_8 = *(int *)piVar9[4];
          puVar16 = (uint *)(piVar9[6] + local_8);
          local_14 = uVar11;
          local_10 = puVar16;
          if (puVar12 != (uint *)0x0) {
            piVar21 = (int *)puVar12[1];
            local_14 = *puVar12;
            *puVar12 = param_4;
            puVar12[1] = (uint)param_1;
            param_1 = (int *)puVar16[-1];
            param_4 = puVar16[-2];
            puVar16 = puVar16 + -2;
            local_10 = puVar16;
            if (((byte)local_14 & 0x1f) == 3) {
              iVar10 = *piVar21;
              piVar1 = (int *)(iVar10 + 4);
              *piVar1 = *piVar1 + -1;
              if (*(int *)(iVar10 + 4) < 1) {
                (**(code **)(*(int *)*piVar21 + 0xc))(piVar9,piVar21);
              }
            }
            else if ((local_14 & 1) != 0) {
              cast_freeHandle(piVar21);
            }
          }
          goto LAB_68034d60;
        case 0x51:
        case 0x91:
        case 0xd1:
          uVar14 = (uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,pbVar18[2]);
            uVar14 = (uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              uVar14 = CONCAT31(CONCAT21(uVar8,pbVar18[3]),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          pbVar18 = pbVar19;
          uVar14 = uVar14 * 8;
          local_14 = uVar11;
          if (-1 < (int)uVar14) {
            uVar15 = piVar9[0x11];
            uVar13 = ((int)uVar15 >> 0x1f) + ((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar15,uVar14);
            puVar16 = local_10;
            if (((-2 < (int)uVar13) && ((uVar13 < 0x80000000 || (0x80000000 < uVar15 + uVar14)))) &&
               (((int)uVar13 < 1 &&
                ((((int)uVar13 < 0 || (uVar15 + uVar14 < 0x80000000)) &&
                 ((int)(piVar9[0x11] + uVar14) < piVar9[0x10])))))) {
              iVar10 = piVar9[0x11] + local_8;
              param_2 = *(int **)(iVar10 + 4 + uVar14);
              puVar16 = (uint *)(iVar10 + uVar14);
              local_14 = *puVar16;
              *puVar16 = param_4;
              puVar16[1] = (uint)param_1;
              param_1 = (int *)local_10[-1];
              puVar16 = local_10 + -2;
              param_4 = *puVar16;
              if (((byte)local_14 & 0x1f) != 3) goto LAB_6803609e;
              iVar10 = *param_2;
              piVar21 = (int *)(iVar10 + 4);
              *piVar21 = *piVar21 + -1;
              local_10 = puVar16;
              if (*(int *)(iVar10 + 4) < 1) {
                (**(code **)(*(int *)*param_2 + 0xc))(piVar9,param_2);
              }
            }
          }
          goto LAB_68034d60;
        case 0x52:
        case 0x92:
        case 0xd2:
          uVar14 = (uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,pbVar18[2]);
            uVar14 = (uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              uVar14 = CONCAT31(CONCAT21(uVar8,pbVar18[3]),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          pbVar18 = pbVar19;
          uVar14 = uVar14 * 8;
          local_14 = uVar11;
          if (-1 < (int)uVar14) {
            uVar15 = piVar9[0x12];
            uVar13 = ((int)uVar15 >> 0x1f) + ((int)uVar14 >> 0x1f) + (uint)CARRY4(uVar15,uVar14);
            puVar16 = local_10;
            if (((-2 < (int)uVar13) &&
                (((uVar13 < 0x80000000 || (0x80000000 < uVar15 + uVar14)) && ((int)uVar13 < 1)))) &&
               ((((int)uVar13 < 0 || (uVar15 + uVar14 < 0x80000000)) &&
                ((int)(piVar9[0x12] + uVar14) < piVar9[0x10])))) {
              iVar10 = piVar9[0x12] + local_8;
              param_2 = *(int **)(iVar10 + 4 + uVar14);
              puVar16 = (uint *)(iVar10 + uVar14);
              local_14 = *puVar16;
              *puVar16 = param_4;
              puVar16[1] = (uint)param_1;
              param_1 = (int *)local_10[-1];
              puVar16 = local_10 + -2;
              param_4 = *puVar16;
              if (((byte)local_14 & 0x1f) == 3) {
                iVar10 = *param_2;
                piVar21 = (int *)(iVar10 + 4);
                *piVar21 = *piVar21 + -1;
                local_10 = puVar16;
                if (*(int *)(iVar10 + 4) < 1) {
                  (**(code **)(*(int *)*param_2 + 0xc))(piVar9,param_2);
                }
              }
              else {
LAB_6803609e:
                puVar16 = local_10 + -2;
                local_10 = puVar16;
                if ((local_14 & 1) != 0) {
                  cast_freeHandle(param_2);
                }
              }
            }
          }
          goto LAB_68034d60;
        case 0x53:
        case 0x93:
        case 0xd3:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          local_14 = uVar14;
          if (uVar14 == 3) {
            local_14 = 4;
          }
          if (*(int *)(*piVar7 + 0x10) - (int)*(short *)(*piVar7 + 0x18) <
              (int)((int)param_2 + (-1 - local_14))) {
LAB_68036f41:
            piVar9[0x4e] = 1;
            props_setError((int)piVar9,0x33);
            goto LAB_68036fee;
          }
          pbVar18 = pbVar19 + (int)param_2 + (-1 - local_14);
          goto LAB_68034d60;
        case 0x54:
        case 0x94:
        case 0xd4:
          bVar3 = *pbVar17;
          param_2 = (int *)(uint)bVar3;
          pbVar17 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(bVar3,*pbVar17);
            param_2 = (int *)(uint)uVar8;
            pbVar17 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar17),pbVar18[4]);
              pbVar17 = pbVar18 + 5;
            }
          }
          local_14 = uVar14;
          if (uVar14 == 3) {
            local_14 = 4;
          }
          piVar9[0x13] = (int)pbVar17 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          iVar10 = cast_getRuntimeRef((int)piVar9);
          uVar11 = local_14;
          if (iVar10 != 0) goto switchD_68034dbd_caseD_0;
          local_c = *piVar7;
          local_8 = *(int *)piVar9[4];
          if (*(int *)(local_c + 0x10) - (int)*(short *)(local_c + 0x18) <
              (int)(local_14 + 1 + (int)param_2)) goto LAB_68036f41;
          puVar16 = (uint *)(piVar9[6] + local_8);
          pbVar18 = (byte *)(((piVar9[0x13] - local_14) - (int)param_2) + -1 + local_c);
          param_1 = (int *)piVar9[8];
          param_4 = piVar9[7];
          local_10 = (uint *)(piVar9[6] + local_8);
          goto LAB_68034d60;
        case 0x55:
        case 0x95:
        case 0xd5:
          bVar3 = *pbVar17;
          param_2 = (int *)(uint)bVar3;
          pbVar17 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(bVar3,*pbVar17);
            param_2 = (int *)(uint)uVar8;
            pbVar17 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar17),pbVar18[4]);
              pbVar17 = pbVar18 + 5;
            }
          }
          local_14 = uVar14;
          if (uVar14 == 3) {
            local_14 = 4;
          }
          if ((param_4 != 4) && (param_4 != 2)) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            piVar9[7] = param_4;
            piVar9[8] = (int)param_1;
            props_setErrorAndReturn((int)piVar9,7);
            uVar11 = local_14;
            goto switchD_68034dbd_caseD_0;
          }
          if (param_1 == (int *)0x0) {
            pbVar17 = pbVar17 + (int)param_2 + (-1 - local_14);
          }
          puVar12 = puVar16 + -1;
          puVar2 = puVar16 + -2;
          puVar16 = puVar16 + -2;
          pbVar18 = pbVar17;
          param_1 = (int *)*puVar12;
          param_4 = *puVar2;
          local_10 = puVar16;
          goto LAB_68034d60;
        case 0x56:
        case 0x96:
        case 0xd6:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          props_enterHandler((int)piVar9,param_2);
          break;
        case 0x57:
        case 0x97:
        case 0xd7:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          props_invokeHandler((int)piVar9,(int)param_2);
          break;
        case 0x58:
        case 0x98:
        case 0xd8:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          props_callMethod((uint)piVar9,(int)param_2);
          break;
        case 0x59:
        case 0x99:
        case 0xd9:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_formatChunkString((int)piVar9,(uint)param_2);
          break;
        case 0x5a:
        case 0x9a:
        case 0xda:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_formatChunkStringEx((int)piVar9,(uint)param_2);
          break;
        case 0x5b:
        case 0x9b:
        case 0xdb:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_deleteChunkRange((int)piVar9,(uint)param_2);
          break;
        case 0x5c:
        case 0x9c:
        case 0xdc:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_dispatchGetProp((uint)piVar9,(int)param_2);
          break;
        case 0x5d:
        case 0x9d:
        case 0xdd:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_dispatchSetProp((uint)piVar9,(int)param_2);
          break;
        case 0x5e:
        case 0x9e:
        case 0xde:
          pbVar17 = pbVar18 + 2;
          if ((0x7f < uVar11) && (pbVar17 = pbVar18 + 3, 0xbf < uVar11)) {
            pbVar17 = pbVar18 + 5;
          }
          goto switchD_68034dbd_caseD_0;
        case 0x5f:
        case 0x9f:
        case 0xdf:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_getSymbolProp((uint)piVar9,(int)param_2);
          break;
        case 0x60:
        case 0xa0:
        case 0xe0:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_setSymbolProp((uint)piVar9,(int)param_2);
          break;
        case 0x61:
        case 0xa1:
        case 0xe1:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_getPropFromObject((int)piVar9,(int)param_2);
          break;
        case 0x62:
        case 0xa2:
        case 0xe2:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_dispatchPropSet((int)piVar9,(int)param_2);
          break;
        case 99:
        case 0xa3:
        case 0xe3:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_dispatchPropGet((int)piVar9,(int)param_2);
          break;
        case 100:
        case 0xa4:
        case 0xe4:
          bVar3 = *pbVar17;
          uVar14 = (uint)bVar3;
          pbVar17 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(bVar3,*pbVar17);
            uVar14 = (uint)uVar8;
            pbVar17 = pbVar18 + 3;
            if (0xbf < uVar11) {
              uVar14 = CONCAT31(CONCAT21(uVar8,*pbVar17),pbVar18[4]);
              pbVar17 = pbVar18 + 5;
            }
          }
          param_2 = param_1;
          uVar15 = param_4;
          if (uVar14 != 0) {
            if (((int)uVar14 < 0) || ((int)puVar16 - local_8 >> 3 < (int)uVar14)) goto LAB_68036943;
            param_2 = (int *)(puVar16 + uVar14 * -2)[1];
            uVar15 = puVar16[uVar14 * -2];
          }
          if (((byte)uVar15 & 0x1f) == 3) {
            *(int *)(*param_2 + 4) = *(int *)(*param_2 + 4) + 1;
          }
          else if ((uVar15 & 1) != 0) {
            piVar9[0x13] = (int)pbVar17 - local_c;
            piVar9[6] = (int)puVar16 - local_8;
            param_2 = (int *)props_copyHandle((int)piVar9);
            local_c = *piVar7;
            pbVar17 = (byte *)(piVar9[0x13] + local_c);
            local_8 = *(int *)piVar9[4];
            puVar16 = (uint *)(piVar9[6] + local_8);
          }
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          puVar16 = puVar16 + 2;
          param_1 = param_2;
          param_4 = uVar15;
          uVar11 = uVar15;
          local_10 = puVar16;
          goto switchD_68034dbd_caseD_0;
        case 0x65:
        case 0xa5:
        case 0xe5:
          bVar3 = *pbVar17;
          param_2 = (int *)(uint)bVar3;
          pbVar17 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(bVar3,*pbVar17);
            param_2 = (int *)(uint)uVar8;
            pbVar17 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar17),pbVar18[4]);
              pbVar17 = pbVar18 + 5;
            }
          }
          if ((-1 < (int)param_2) && ((int)param_2 <= (int)puVar16 - local_8 >> 3)) {
            while (0 < (int)param_2) {
              param_2 = (int *)((int)param_2 + -1);
              if (((byte)param_4 & 0x1f) == 3) {
                iVar10 = *param_1;
                piVar21 = (int *)(iVar10 + 4);
                *piVar21 = *piVar21 + -1;
                if (*(int *)(iVar10 + 4) < 1) {
                  (**(code **)(*(int *)*param_1 + 0xc))(piVar9,param_1);
                }
              }
              else if ((param_4 & 1) != 0) {
                cast_freeHandle(param_1);
              }
              param_1 = (int *)puVar16[-1];
              puVar16 = puVar16 + -2;
              param_4 = *puVar16;
              local_10 = puVar16;
            }
            goto switchD_68034dbd_caseD_0;
          }
LAB_68036943:
          props_setError((int)piVar9,0x33);
          pbVar18 = pbVar17;
          local_14 = uVar11;
          goto LAB_68034d60;
        case 0x66:
        case 0xa6:
        case 0xe6:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          props_callPropertyHandler((int)piVar9,(int)param_2);
          break;
        case 0x67:
        case 0xa7:
        case 0xe7:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          props_dispatchPropertyAccess((int)piVar9,(int)param_2);
          break;
        case 0x68:
        case 0xa8:
        case 0xe8:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_formatChunkStringPersist((int)piVar9,(uint)param_2);
          break;
        case 0x69:
        case 0xa9:
        case 0xe9:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_formatStackString((int)piVar9,(uint)param_2);
          break;
        case 0x6a:
        case 0xaa:
        case 0xea:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_deleteStackRange((int)piVar9,(uint)param_2);
          break;
        case 0x6b:
        case 0xab:
        case 0xeb:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_dispatchGetMovieProp((uint)piVar9,(int)param_2);
          break;
        case 0x6c:
        case 0xac:
        case 0xec:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_dispatchSetMovieProp((uint)piVar9,(int)param_2);
          break;
        case 0x6d:
        case 0xad:
        case 0xed:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_getChunkProperty((int)piVar9,param_2);
          break;
        case 0x70:
        case 0xb0:
        case 0xf0:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          stage_dispatchPropCall((int)piVar9,(int)param_2);
          break;
        case 0x72:
        case 0xb2:
        case 0xf2:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          core_resolveClassProperty((int)piVar9,(int)param_2);
          break;
        case 0x73:
        case 0xb3:
        case 0xf3:
          param_2 = (int *)(uint)*pbVar17;
          pbVar19 = pbVar18 + 2;
          if (0x7f < uVar11) {
            uVar8 = CONCAT11(*pbVar17,*pbVar19);
            param_2 = (int *)(uint)uVar8;
            pbVar19 = pbVar18 + 3;
            if (0xbf < uVar11) {
              param_2 = (int *)CONCAT31(CONCAT21(uVar8,*pbVar19),pbVar18[4]);
              pbVar19 = pbVar18 + 5;
            }
          }
          piVar9[0x13] = (int)pbVar19 - local_c;
          piVar9[6] = (int)puVar16 - local_8;
          piVar9[7] = param_4;
          piVar9[8] = (int)param_1;
          core_dispatchPropertyAccess((uint)piVar9,(int)param_2);
          break;
        case 0xae:
          bVar3 = *pbVar17;
          bVar4 = pbVar18[2];
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          local_10 = puVar16 + 2;
          param_4 = 4;
          puVar16 = local_10;
          pbVar18 = pbVar18 + 3;
          param_1 = (int *)(int)CONCAT11(bVar3,bVar4);
          local_14 = uVar11;
          goto LAB_68034d60;
        case 0xef:
          param_2 = (int *)CONCAT31(CONCAT21(CONCAT11(*pbVar17,pbVar18[2]),pbVar18[3]),pbVar18[4]);
          *puVar16 = param_4;
          pbVar19 = pbVar18 + 5;
          puVar16[1] = (uint)param_1;
LAB_68036d83:
          puVar16 = puVar16 + 2;
          param_4 = 4;
          pbVar18 = pbVar19;
          param_1 = param_2;
          local_14 = uVar11;
          local_10 = puVar16;
          goto LAB_68034d60;
        case 0xf1:
          bVar3 = *pbVar17;
          bVar4 = pbVar18[2];
          bVar5 = pbVar18[3];
          bVar6 = pbVar18[4];
          *puVar16 = param_4;
          puVar16[1] = (uint)param_1;
          puVar16 = puVar16 + 2;
          param_4 = 0x20;
          pbVar18 = pbVar18 + 5;
          param_1 = (int *)CONCAT31(CONCAT21(CONCAT11(bVar3,bVar4),bVar5),bVar6);
          local_14 = uVar11;
          local_10 = puVar16;
          goto LAB_68034d60;
        }
        local_c = *piVar7;
        pbVar17 = (byte *)(piVar9[0x13] + local_c);
        local_8 = *(int *)piVar9[4];
        param_1 = (int *)piVar9[8];
        puVar16 = (uint *)(piVar9[6] + local_8);
        param_4 = piVar9[7];
        local_10 = (uint *)(piVar9[6] + local_8);
switchD_68034dbd_caseD_0:
        local_14 = uVar11;
        pbVar18 = pbVar17;
      } while (piVar9[0x1d] == 0);
    }
    goto LAB_68034b92;
  }
  if (piVar9[0x24] == 0) {
    if ((iVar10 == 4) || (iVar10 == 5)) {
      piVar9[0x1d] = 0;
    }
  }
  else {
    iVar10 = stage_compileHandlerBody((int)piVar9,0);
    if (iVar10 != piVar9[0x26]) {
      piVar9[0x26] = iVar10;
      iVar10 = (*(code *)piVar9[0x24])(piVar9,piVar9[0x1d],piVar9[0x14],piVar9[0x15],iVar10);
      piVar9[0x1d] = iVar10;
    }
  }
  iVar10 = piVar9[0x1d];
  if ((((iVar10 == 0x12) || (iVar10 == 0x13)) || (iVar10 == 4)) || (iVar10 == 5)) {
    iVar10 = cast_getRuntimeRef((int)piVar9);
    if (iVar10 == 0) {
      piVar9[0x1e] = piVar9[0x1d];
      while( true ) {
        do {
          props_fetchNextOpcode();
        } while (piVar9[0x1d] == 0);
        if ((piVar9[0x1d] != 0x12) && (piVar9[0x1d] != 0x13)) break;
        iVar10 = stage_compileHandlerBody((int)piVar9,0);
        if (iVar10 != piVar9[0x26]) {
          piVar9[0x26] = iVar10;
          piVar9[0x1d] = 0xd;
          goto switchD_68034ba8_caseD_3;
        }
      }
    }
    goto LAB_68034b92;
  }
  if ((iVar10 < 8) || (10 < iVar10)) goto LAB_68034ca4;
  goto LAB_68036fee;
LAB_68034b92:
  switch(piVar9[0x1d]) {
  case 2:
    break;
  case 4:
  case 5:
  case 6:
  case 0x12:
  case 0x13:
    goto switchD_68034ba8_caseD_4;
  case 7:
    piVar9[0x1d] = piVar9[0x1e];
    if (piVar9[0x14] == 0) {
      return piVar9[0x1e] != 10;
    }
    goto switchD_68034ba8_caseD_4;
  case 8:
    if ((code *)piVar9[0x24] != (code *)0x0) {
      (*(code *)piVar9[0x24])(piVar9,8,piVar9[0x14],piVar9[0x15],piVar9[0x26]);
    }
    if (*(code **)(*(int *)piVar9[2] + 0x4f8) != (code *)0x0) {
      (**(code **)(*(int *)piVar9[2] + 0x4f8))(piVar9);
    }
LAB_68036fee:
    if (((int *)piVar9[0x14] != (int *)0x0) &&
       (((*(uint *)(*(int *)piVar9[0x14] + 0x54) & 0x800) != 0 || (piVar9[0x1f] == 0x33)))) {
      piVar9[0x1d] = 1;
    }
    props_unwindStack((int)piVar9);
    piVar9[7] = 2;
    piVar9[8] = 0;
  default:
    piVar9[0x26] = -1;
    if (((code *)piVar9[0x24] != (code *)0x0) && (piVar9[0x1e] != 0)) {
      (*(code *)piVar9[0x24])(piVar9,1,piVar9[0x14],piVar9[0x15],0xffffffff);
    }
    if (piVar9[0x4e] == 0) {
      props_popFrame((uint)piVar9);
      if (piVar9[0x1c] != 0) {
        return piVar9[0x1d] != 10;
      }
      goto switchD_68034ba8_caseD_4;
    }
  case 3:
  case 0xc:
  case 0xd:
  case 0xe:
  case 0xf:
  case 0x10:
  case 0x11:
switchD_68034ba8_caseD_3:
    return piVar9[0x1d] != 10;
  }
  iVar10 = piVar9[0x1e];
  piVar9[0x26] = -1;
  switch(iVar10) {
  case 4:
  case 0x12:
    piVar9[0x1d] = iVar10;
    break;
  case 5:
  case 0x13:
    piVar9[0x1d] = 0;
    break;
  default:
    goto switchD_68036f78_caseD_6;
  }
  goto LAB_68034c28;
switchD_68036f78_caseD_6:
  piVar9[0x1d] = 0;
  goto LAB_68034c20;
}


