// Module: cast
// Topic: Data table read/write and ordinal helpers
// Address range: 0x6802D4C0 - 0x6802DC60
// Functions (8):
//   cast_writeDataEntry
//   Ordinal_36
//   Ordinal_37
//   cast_lookupDataEntry
//   Ordinal_38
//   cast_readDataEntry
//   Ordinal_39
//   cast_compareHandleData (FUN_6802dc60)

// ============================================================
// Function: cast_writeDataEntry (FUN_6802d4c0)
// Address: 6802d4c0
// Size: 503 bytes
// Params: undefined4 param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_writeDataEntry(undefined4 param_1,int param_2,int param_3)

{
  short sVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  int iVar8;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  int local_8;
  
  local_14 = 0;
  local_10 = 0;
  local_c = 0;
  iVar2 = Ordinal_1435(param_1);
  if (((param_2 <= iVar2) && (local_10 = Ordinal_1111(param_2 + 2,1), local_10 != 0)) &&
     (iVar2 = Ordinal_1404(&local_c,local_10,3), iVar2 != 0)) {
    local_8 = Ordinal_1414(param_1);
    iVar2 = Ordinal_1042();
    if (((iVar2 == 0) && (-1 < local_8)) && (iVar2 = Ordinal_1420(local_c,&local_8,4), iVar2 != 0))
    {
      uVar7 = param_2 - 4;
      uVar3 = local_8 - 4;
      if (param_3 == 1) {
        if (((uVar3 & 1) != 0) || (uVar3 = uVar3 >> 1, (int)uVar7 < (int)(uVar3 * 2)))
        goto LAB_6802d686;
        if (uVar3 != 0) {
          do {
            local_18 = Ordinal_1412(param_1);
            local_18 = local_18 & 0xffff;
            iVar2 = Ordinal_1420(local_c,&local_18,2);
            if (iVar2 == 0) goto LAB_6802d686;
            uVar3 = uVar3 - 1;
            uVar7 = uVar7 - 2;
          } while (0 < (int)uVar3);
        }
      }
      else {
        if (((uVar3 & 3) != 0) || (uVar3 = uVar3 >> 2, (int)uVar7 < (int)(uVar3 * 4)))
        goto LAB_6802d686;
        if (uVar3 != 0) {
          do {
            local_8 = Ordinal_1414(param_1);
            iVar2 = Ordinal_1420(local_c,&local_8,4);
            if (iVar2 == 0) goto LAB_6802d686;
            uVar3 = uVar3 - 1;
            uVar7 = uVar7 - 4;
          } while (0 < (int)uVar3);
        }
      }
      if (1 < uVar7) {
        sVar1 = Ordinal_1412(param_1);
        local_8 = (int)sVar1;
        iVar2 = Ordinal_1420(local_c,&local_8,4);
        if (iVar2 != 0) {
          iVar8 = uVar7 - 2;
          iVar5 = 0;
          for (iVar2 = local_8 + 1; 0 < iVar2; iVar2 = iVar2 + -1) {
            iVar4 = Ordinal_1414(param_1);
            local_8 = iVar4;
            if ((((iVar8 < iVar4) || (iVar8 < 0)) || (iVar4 < iVar5)) ||
               (iVar5 = Ordinal_1420(local_c,&local_8,4), iVar5 == 0)) goto LAB_6802d686;
            iVar8 = iVar8 + -4;
            iVar5 = iVar4;
          }
          if (0 < iVar8) {
            uVar6 = Ordinal_1433(param_1,iVar8);
            uVar6 = Ordinal_1433(local_c,param_1,uVar6);
            iVar2 = Ordinal_1431(local_c,uVar6);
            if (iVar2 == 0) goto LAB_6802d686;
          }
          local_14 = 1;
        }
      }
    }
  }
LAB_6802d686:
  if (local_c != 0) {
    Ordinal_1407(&local_c);
  }
  if ((local_14 == 0) && (local_10 != 0)) {
    Ordinal_1113(&local_10);
  }
  return local_10;
}



// ============================================================
// Function: Ordinal_36
// Address: 6802d6c0
// Size: 26 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_36(int *param_1)

{
                    /* 0x2d6c0  36   */
  if (*param_1 != 0) {
    Ordinal_1113(param_1);
  }
  return 1;
}



// ============================================================
// Function: Ordinal_37
// Address: 6802d6e0
// Size: 573 bytes
// Params: undefined4 * param_1, short param_2, undefined4 param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_37(undefined4 *param_1,short param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  int *local_c;
  undefined4 local_8;
  
                    /* 0x2d6e0  37   */
  local_8 = 0;
  if (param_2 < 0) goto LAB_6802d906;
  local_8 = 0;
  local_c = (int *)Ordinal_1114(*param_1);
  iVar6 = *local_c;
  piVar7 = (int *)(iVar6 + (int)local_c);
  if (*piVar7 < 0) goto LAB_6802d906;
  iVar2 = *piVar7;
  iVar1 = Ordinal_1116(*param_1);
  if (iVar1 < iVar2) goto LAB_6802d906;
  iVar1 = (int)param_2;
  if (iVar1 < iVar2) {
    iVar2 = iVar6 + 8 + iVar2 * 4;
    if (piVar7[iVar1 + 2] < 0) {
      piVar7[iVar1 + 2] = 0;
    }
    if (piVar7[iVar1 + 1] < 0) {
      piVar7[iVar1 + 1] = 0;
    }
    iVar3 = (param_4 - piVar7[iVar1 + 2]) + piVar7[iVar1 + 1];
    if (iVar3 != 0) {
      if (0 < iVar3) {
        Ordinal_1115(*param_1);
        iVar4 = Ordinal_1116(*param_1,1);
        iVar4 = Ordinal_1117(param_1,iVar4 + iVar3);
        if (iVar4 == 0) {
          return 0;
        }
        local_c = (int *)Ordinal_1114(*param_1);
        piVar7 = (int *)(iVar6 + (int)local_c);
      }
      if (iVar1 < *piVar7 + -1) {
        iVar4 = iVar2 + piVar7[iVar1 + 2] + (int)local_c;
        Ordinal_1129(iVar4 + iVar3,iVar4,piVar7[*piVar7 + 1] - piVar7[iVar1 + 2]);
      }
      if (iVar3 < 0) {
        Ordinal_1115(*param_1);
        iVar4 = Ordinal_1116(*param_1);
        if (-1 < iVar4 + iVar3) {
          iVar4 = Ordinal_1116(*param_1,1);
          Ordinal_1117(param_1,iVar4 + iVar3);
        }
        local_c = (int *)Ordinal_1114(*param_1);
        piVar7 = (int *)(iVar6 + (int)local_c);
      }
      iVar6 = iVar1 + 1;
      if (iVar6 <= *piVar7) {
        piVar5 = piVar7 + iVar1 + 2;
        do {
          *piVar5 = *piVar5 + iVar3;
          iVar6 = iVar6 + 1;
          piVar5 = piVar5 + 1;
        } while (iVar6 <= *piVar7);
      }
    }
    if (0 < param_4) {
      iVar6 = piVar7[iVar1 + 1] + iVar2 + (int)local_c;
      goto LAB_6802d8f7;
    }
  }
  else {
    if (param_4 < 1) {
      local_8 = 1;
      goto LAB_6802d906;
    }
    iVar2 = Ordinal_1116(*param_1);
    iVar2 = iVar2 + param_4 + 4 + (iVar1 - *piVar7) * 4;
    Ordinal_1115(*param_1);
    iVar3 = Ordinal_1117(param_1,iVar2,1);
    if (iVar3 == 0) {
      return 0;
    }
    local_c = (int *)Ordinal_1114(*param_1);
    piVar7 = (int *)(iVar6 + (int)local_c);
    iVar3 = piVar7[*piVar7 + 1];
    if ((iVar3 < 0) || (iVar2 - (iVar1 * 4 + 0xc) < iVar3)) goto LAB_6802d906;
    Ordinal_1129(piVar7 + iVar1 + 3,piVar7 + *piVar7 + 2,iVar3);
    iVar2 = *piVar7;
    iVar4 = iVar2 + 1;
    *piVar7 = iVar1 + 1;
    if (iVar4 < iVar1 + 1) {
      piVar5 = piVar7 + iVar2 + 2;
      do {
        *piVar5 = iVar3;
        iVar4 = iVar4 + 1;
        piVar5 = piVar5 + 1;
      } while (iVar4 < *piVar7);
    }
    piVar7[*piVar7 + 1] = iVar3 + param_4;
    iVar6 = iVar3 + 8 + *piVar7 * 4 + iVar6 + (int)local_c;
LAB_6802d8f7:
    Ordinal_1128(iVar6,param_3,param_4);
  }
  local_8 = 1;
LAB_6802d906:
  if (local_c != (int *)0x0) {
    Ordinal_1115(*param_1);
  }
  return local_8;
}



// ============================================================
// Function: cast_lookupDataEntry (FUN_6802d920)
// Address: 6802d920
// Size: 194 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x6802d96c) */
/* WARNING: Removing unreachable block (ram,0x6802d97c) */
/* WARNING: Removing unreachable block (ram,0x6802d980) */
/* WARNING: Removing unreachable block (ram,0x6802d982) */
/* WARNING: Removing unreachable block (ram,0x6802d989) */
/* WARNING: Removing unreachable block (ram,0x6802d98e) */
/* WARNING: Removing unreachable block (ram,0x6802d995) */
/* WARNING: Removing unreachable block (ram,0x6802d9a3) */
/* WARNING: Removing unreachable block (ram,0x6802d9bb) */
/* WARNING: Removing unreachable block (ram,0x6802d9d2) */

int cast_lookupDataEntry(int param_1,int param_2,int param_3)

{
  int *piVar1;
  
  if (((-1 < (short)param_2) && (param_1 != 0)) &&
     (piVar1 = (int *)Ordinal_1114(param_1), piVar1 != (int *)0x0)) {
    cast_lookupTableEntry((int)(short)param_2,piVar1);
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: Ordinal_38
// Address: 6802d9f0
// Size: 132 bytes
// Params: int param_1, short param_2, undefined4 param_3, int param_4
// Return: int
// Calling convention: __stdcall
// ============================================================

/* WARNING: Removing unreachable block (ram,0x6802da33) */
/* WARNING: Removing unreachable block (ram,0x6802da43) */
/* WARNING: Removing unreachable block (ram,0x6802da4a) */
/* WARNING: Removing unreachable block (ram,0x6802da4c) */
/* WARNING: Removing unreachable block (ram,0x6802da50) */
/* WARNING: Removing unreachable block (ram,0x6802da52) */
/* WARNING: Removing unreachable block (ram,0x6802da56) */

int Ordinal_38(int param_1,short param_2,undefined4 param_3,int param_4)

{
  int *piVar1;
  
                    /* 0x2d9f0  38   */
  if (((-1 < param_2) && (param_1 != 0)) &&
     (piVar1 = (int *)Ordinal_1114(param_1), piVar1 != (int *)0x0)) {
    cast_lookupTableEntry((int)param_2,piVar1);
    Ordinal_1115(param_1);
  }
  return 0;
}



// ============================================================
// Function: cast_readDataEntry (FUN_6802da80)
// Address: 6802da80
// Size: 433 bytes
// Params: int param_1, int param_2, int param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int cast_readDataEntry(int param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined4 local_14;
  int local_10;
  int local_c;
  int local_8;
  
  iVar6 = param_1;
  local_10 = 0;
  local_8 = 0;
  local_c = 0;
  iVar1 = Ordinal_1404(&local_8,param_1,1);
  if (iVar1 != 0) {
    iVar1 = Ordinal_1116(iVar6);
    Ordinal_1409(local_8,&param_1,4);
    iVar6 = param_2;
    if (param_2 != 0) {
      Ordinal_1425(param_2,param_1);
    }
    if (param_3 == 1) {
      uVar2 = param_1 - 4U >> 1;
      iVar1 = iVar1 + -4 + uVar2 * -2;
      local_c = uVar2 * 2 + 4;
      if (uVar2 != 0) {
        do {
          Ordinal_1409(local_8,&local_14,2);
          if ((iVar6 != 0) && (iVar3 = Ordinal_1423(iVar6,local_14), iVar3 == 0)) goto LAB_6802dc0a;
          uVar2 = uVar2 - 1;
        } while (0 < (int)uVar2);
      }
    }
    else {
      uVar2 = param_1 - 4U >> 2;
      iVar1 = iVar1 + -4 + uVar2 * -4;
      local_c = uVar2 * 4 + 4;
      if (uVar2 != 0) {
        do {
          Ordinal_1409(local_8,&param_1,4);
          if ((iVar6 != 0) && (iVar3 = Ordinal_1425(iVar6,param_1), iVar3 == 0)) goto LAB_6802dc0a;
          uVar2 = uVar2 - 1;
        } while (0 < (int)uVar2);
      }
    }
    Ordinal_1409(local_8,&param_1,4);
    if ((iVar6 == 0) || (iVar3 = Ordinal_1423(iVar6,param_1), iVar3 != 0)) {
      iVar3 = param_1 + 1;
      iVar1 = iVar1 + iVar3 * -4 + -4;
      local_c = local_c + 2 + iVar3 * 4;
      for (; 0 < iVar3; iVar3 = iVar3 + -1) {
        Ordinal_1409(local_8,&param_1,4);
        if ((iVar6 != 0) && (iVar4 = Ordinal_1425(iVar6,param_1), iVar4 == 0)) goto LAB_6802dc0a;
      }
      if (0 < iVar1) {
        if (iVar6 != 0) {
          uVar5 = Ordinal_1433(local_8,iVar1);
          uVar5 = Ordinal_1433(iVar6,local_8,uVar5);
          iVar6 = Ordinal_1431(iVar6,uVar5);
          if (iVar6 == 0) goto LAB_6802dc0a;
        }
        local_c = local_c + iVar1;
      }
      local_10 = 1;
    }
  }
LAB_6802dc0a:
  if (local_8 != 0) {
    Ordinal_1407(&local_8);
  }
  if (local_10 == 0) {
    return 0;
  }
  return local_c;
}



// ============================================================
// Function: Ordinal_39
// Address: 6802dc40
// Size: 23 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 Ordinal_39(int *param_1)

{
  undefined4 uVar1;
  
                    /* 0x2dc40  39   */
  uVar1 = 0;
  if (param_1 != (int *)0x0) {
    uVar1 = *(undefined4 *)(*param_1 + *(int *)*param_1);
  }
  return uVar1;
}



// ============================================================
// Function: cast_compareHandleData (FUN_6802dc60)
// Address: 6802dc60
// Size: 121 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint cast_compareHandleData(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    iVar1 = Ordinal_1116(param_1);
    iVar2 = Ordinal_1116(param_1);
    if (iVar1 == iVar2) {
      piVar3 = (int *)Ordinal_1114(param_1);
      iVar4 = Ordinal_1114(param_2);
      iVar2 = *piVar3;
      uVar5 = Ordinal_1131(iVar2 + (int)piVar3,iVar2 + iVar4,iVar1 - iVar2);
      Ordinal_1115(param_1);
      Ordinal_1115(param_2);
      return uVar5;
    }
    return 0;
  }
  return (uint)(param_1 == param_2);
}



