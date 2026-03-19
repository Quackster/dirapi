// Module: score
// Topic: Symbol/string table and hash operations
// Address range: 0x68049e20 - 0x6804a3a0
// Functions (10):
//   score_initStringPool (FUN_68049e20)
//   score_appendString (FUN_68049e40)
//   score_compareStrings (FUN_68049ef0)
//   score_nextPowerOfTwo (FUN_68049fc0)
//   score_createSymbolTable (FUN_68049fe0)
//   score_freeSymbolTable (FUN_6804a070)
//   score_hashSymbol (FUN_6804a0b0)
//   score_resolveSymbolName (FUN_6804a0f0)
//   score_lookupSymbol (FUN_6804a310)
//   score_getSymbolName (FUN_6804a3a0)

// ============================================================
// Function: score_initStringPool (FUN_68049e20)
// Address: 68049e20
// Size: 27 bytes
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_initStringPool(void)
{
  int local_8;
  int local_c;
  undefined4 *puVar1;
  int unaff_ESI;
  
  puVar1 = (undefined4 *)cast_allocHandle(unaff_ESI + 0xb,1);
  if (puVar1 != (undefined4 *)0x0) {
    puVar1 = (undefined4 *)*puVar1;
    *puVar1 = 0;
    puVar1[1] = unaff_ESI;
  }
  return 0;
}


// ============================================================
// Function: score_appendString (FUN_68049e40)
// Address: 68049e40
// Size: 172 bytes
// Params: void * this, int * param_1, byte * param_2
// Return: int
// Calling convention: __thiscall
// ============================================================

int __thiscall score_appendString(void *this,int *param_1,byte *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  
  if (*param_2 == 0xff) {
    uVar1 = Ordinal_1201(param_2 + 1,this);
  }
  else {
    uVar1 = (ushort)*param_2;
  }
  iVar5 = (short)uVar1 + 1;
  uVar2 = (int)(short)uVar1 + 3U & 0xfffe;
  piVar6 = (int *)*param_1;
  iVar3 = uVar2 + *piVar6;
  if (piVar6[1] < iVar3) {
    iVar7 = (piVar6[1] >> 1) + 1 + piVar6[1];
    if (iVar7 < iVar3) {
      iVar7 = iVar3;
    }
    uVar4 = cast_resizeHandle((uint)param_1,iVar7 + 0xb,1);
    if (uVar4 == 0) {
      iVar7 = *(int *)(*param_1 + 4) + uVar2;
      uVar4 = cast_resizeHandle((uint)param_1,iVar7 + 0xb,1);
      if (uVar4 == 0) {
        return -1;
      }
    }
    piVar6 = (int *)*param_1;
    piVar6[1] = iVar7;
  }
  iVar3 = *piVar6 + 8 + (int)piVar6;
  Ordinal_1129(iVar3,param_2,iVar5);
  *(undefined1 *)(iVar3 + iVar5) = 0;
  iVar3 = *piVar6;
  *piVar6 = iVar3 + uVar2;
  return iVar3;
}


// ============================================================
// Function: score_compareStrings (FUN_68049ef0)
// Address: 68049ef0
// Size: 205 bytes
// Params: byte * param_1, byte * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_compareStrings(byte *param_1,byte *param_2)

{
  ushort uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int local_10;
  short local_c [2];
  short local_8 [2];
  
  iVar7 = 1;
  local_10 = 1;
  if (*param_1 == 0xff) {
    uVar1 = Ordinal_1201(param_1 + 1);
  }
  else {
    uVar1 = (ushort)*param_1;
  }
  iVar6 = (int)(short)uVar1;
  if (*param_2 == 0xff) {
    uVar1 = Ordinal_1201(param_2 + 1);
  }
  else {
    uVar1 = (ushort)*param_2;
  }
  if (iVar6 == (short)uVar1) {
    while( true ) {
      if (iVar6 < 1) {
        return 1;
      }
      uVar2 = stage_convertToShort(param_1 + iVar7,0,local_8);
      uVar3 = stage_convertToShort(param_2 + local_10,0,local_c);
      if (local_8[0] != local_c[0]) break;
      iVar4 = Ordinal_1253(uVar2);
      iVar5 = Ordinal_1253(uVar3);
      if (iVar4 != iVar5) {
        return 0;
      }
      local_10 = local_10 + local_c[0];
      iVar6 = iVar6 - local_8[0];
      iVar7 = iVar7 + local_8[0];
    }
  }
  return 0;
}


// ============================================================
// Function: score_nextPowerOfTwo (FUN_68049fc0)
// Address: 68049fc0
// Size: 25 bytes
// Params: int param_1
// Return: int
// Calling convention: __fastcall
// ============================================================

int __fastcall score_nextPowerOfTwo(int param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = 1;
  for (iVar2 = param_1 + -1; 0 < iVar2; iVar2 = iVar2 >> 1) {
    iVar1 = iVar1 * 2;
  }
  return iVar1;
}


// ============================================================
// Function: score_createSymbolTable (FUN_68049fe0)
// Address: 68049fe0
// Size: 131 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_createSymbolTable(int param_1,int param_2)
{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;

  iVar2 = score_initStringPool();
  if (iVar2 == 0) {
    return 0;
  }
  iVar3 = score_nextPowerOfTwo(param_1);
  iVar1 = iVar3 + -1;
  if (param_2 < iVar1) {
    param_2 = iVar1;
  }
  puVar4 = (undefined4 *)cast_allocHandle(param_2 * 0x14 + 0x18,1);
  if (puVar4 != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)*puVar4;
    *puVar4 = 1;
    puVar4[1] = iVar3;
    puVar4[3] = iVar1;
    puVar4[2] = param_2;
    puVar4[5] = iVar2;
    puVar4[4] = 0;
    if (0 < param_2) {
      puVar4 = puVar4 + 6;
      do {
        *puVar4 = 0xffffffff;
        puVar4 = puVar4 + 5;
        param_2 = param_2 + -1;
      } while (param_2 != 0);
    }
  }
  return 0;
}


// ============================================================
// Function: score_freeSymbolTable (FUN_6804a070)
// Address: 6804a070
// Size: 51 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_freeSymbolTable(undefined4 *param_1)
{
  int *piVar1;
  
  if ((((undefined4 *)*param_1 != (undefined4 *)0x0) &&
      (piVar1 = *(int **)*param_1, piVar1 != (int *)0x0)) && (*piVar1 = *piVar1 + -1, *piVar1 == 0))
  {
    cast_freeHandle(piVar1[5]);
    cast_freeHandle(*param_1);
  }
  *param_1 = 0;
  return 0;
}


// ============================================================
// Function: score_hashSymbol (FUN_6804a0b0)
// Address: 6804a0b0
// Size: 63 bytes
// Params: int param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint score_hashSymbol(int param_1,int param_2)

{
  uint uVar1;
  
  uVar1 = ((uint)(param_2 + param_1) >> 0x10) + (param_2 + param_1 & 0xffffU);
  return (uVar1 >> 8) + uVar1 & 0xff;
}


// ============================================================
// Function: score_resolveSymbolName (FUN_6804a0f0)
// Address: 6804a0f0
// Size: 531 bytes
// Params: int param_1, int * param_2, byte * param_3, uint * param_4, byte param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int score_resolveSymbolName(int param_1,int *param_2,byte *param_3,uint *param_4,byte param_5)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  undefined4 *this;
  undefined4 *extraout_ECX;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  undefined8 uVar9;
  short local_8 [2];
  
  uVar6 = 0;
  if (*param_3 == 0xff) {
    uVar1 = Ordinal_1201(param_3 + 1);
  }
  else {
    uVar1 = (ushort)*param_3;
  }
  iVar8 = (int)(short)uVar1;
  if (param_1 == 0) {
    for (; 0 < iVar8; iVar8 = iVar8 + -1) {
      uVar9 = Ordinal_1253(param_3[iVar8]);
      uVar4 = score_hashSymbol((int)uVar9,(int)((ulonglong)uVar9 >> 0x20));
      uVar6 = uVar6 + uVar4;
    }
  }
  else {
    iVar5 = 1;
    if (0 < iVar8) {
      do {
        uVar2 = stage_convertToShort(param_3 + iVar5,0,local_8);
        iVar3 = Ordinal_1253(uVar2);
        uVar4 = score_hashSymbol(iVar3,iVar3 >> 0x1f);
        iVar5 = iVar5 + local_8[0];
        uVar6 = uVar6 + uVar4;
      } while (iVar5 <= iVar8);
    }
  }
  iVar8 = *param_2;
  uVar6 = *(uint *)(iVar8 + 0xc) & uVar6;
  this = (undefined4 *)(**(int **)(iVar8 + 0x14) + 8);
  piVar7 = (int *)(iVar8 + 0x18 + uVar6 * 0x14);
  iVar5 = *(int *)(iVar8 + 0x18 + uVar6 * 0x14);
  while (-1 < iVar5) {
    if ((0 < piVar7[4]) || ((param_5 & 1) == 0)) {
      if (param_1 == 0) {
        iVar5 = Ordinal_1254(*piVar7 + 1 + (int)this,param_3 + 1);
        iVar3 = Ordinal_1042();
        if (iVar3 != 0) {
          return -1;
        }
        if (iVar5 == 0) goto LAB_6804a1b8;
      }
      else {
        iVar5 = score_compareStrings((byte *)(*piVar7 + (int)this),param_3);
        if (iVar5 != 0) {
LAB_6804a1b8:
          if (((param_5 & 2) != 0) || ((piVar7[4] == 0 && ((param_5 & 4) == 0)))) {
            piVar7[4] = piVar7[4] + 1;
            *param_4 = uVar6;
            return piVar7[2];
          }
          goto LAB_6804a2f2;
        }
      }
    }
    uVar4 = piVar7[1];
    if ((int)uVar4 < 0) break;
    piVar7 = (int *)(iVar8 + 0x18 + uVar4 * 0x14);
    uVar6 = uVar4;
    iVar5 = *(int *)(iVar8 + 0x18 + uVar4 * 0x14);
  }
  if ((param_5 & 1) == 0) {
    if (-1 < *piVar7) {
      if (*(int *)(iVar8 + 8) <= *(int *)(iVar8 + 4)) {
        iVar5 = (*(int *)(iVar8 + 8) >> 1) + 1 + *(int *)(iVar8 + 8);
        uVar4 = cast_resizeHandle((uint)param_2,iVar5 * 0x14 + 0x18,1);
        if (uVar4 == 0) {
          return -1;
        }
        iVar8 = *param_2;
        piVar7 = (int *)(iVar8 + 0x18 + uVar6 * 0x14);
        iVar3 = *(int *)(iVar8 + 8);
        this = extraout_ECX;
        if (iVar3 < iVar5) {
          this = (undefined4 *)(iVar8 + 0x18 + iVar3 * 0x14);
          iVar3 = iVar5 - iVar3;
          do {
            *this = 0xffffffff;
            this = this + 5;
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
        }
        *(int *)(iVar8 + 8) = iVar5;
      }
      uVar6 = *(uint *)(iVar8 + 4);
      piVar7[1] = uVar6;
      *(int *)(iVar8 + 4) = *(int *)(iVar8 + 4) + 1;
    }
    iVar8 = score_appendString(this,*(int **)(iVar8 + 0x14),param_3);
    if (-1 < iVar8) {
      iVar5 = *param_2;
      piVar7 = (int *)(iVar5 + 0x18 + uVar6 * 0x14);
      *piVar7 = iVar8;
      piVar7[1] = -1;
      piVar7[2] = *(int *)(iVar5 + 0x10);
      *(int *)(iVar5 + 0x10) = *(int *)(iVar5 + 0x10) + 1;
      piVar7[4] = ((int)(char)~param_5 & 4U) >> 2;
      *(uint *)(iVar5 + 0x24 + piVar7[2] * 0x14) = uVar6;
LAB_6804a2f2:
      *param_4 = uVar6;
      return piVar7[2];
    }
  }
  return -1;
}


// ============================================================
// Function: score_lookupSymbol (FUN_6804a310)
// Address: 6804a310
// Size: 140 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 score_lookupSymbol(int *param_1,int param_2,int param_3)

{
  char *pcVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  char *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  
  iVar3 = *param_1;
  if ((-1 < param_2) && (param_2 <= *(int *)(iVar3 + 4))) {
    iVar4 = *(int *)(iVar3 + 0x18 + *(int *)(iVar3 + 0x24 + param_2 * 0x14) * 0x14);
    iVar8 = (int)*(char *)(**(int **)(iVar3 + 0x14) + 8 + iVar4);
    pcVar5 = (char *)(**(int **)(iVar3 + 0x14) + 8 + iVar4);
    if (iVar8 == 0xff) {
      pcVar1 = pcVar5 + 1;
      do {
        cVar2 = *pcVar5;
        pcVar5 = pcVar5 + 1;
      } while (cVar2 != '\0');
      iVar8 = (int)pcVar5 - (int)pcVar1;
    }
    iVar6 = iVar8;
    if (-1 < iVar8) {
      do {
        iVar7 = iVar6 + -1;
        *(undefined1 *)(iVar6 + param_3) =
             *(undefined1 *)(**(int **)(iVar3 + 0x14) + iVar4 + 9 + iVar7);
        iVar6 = iVar7;
      } while (-1 < iVar7);
      *(undefined1 *)(iVar8 + 1 + param_3) = 0;
    }
    return 1;
  }
  Ordinal_1233(param_3,"");
  return 0;
}


// ============================================================
// Function: score_getSymbolName (FUN_6804a3a0)
// Address: 6804a3a0
// Size: 85 bytes
// Params: int param_1, int param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int score_getSymbolName(int param_1,int param_2)
{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_2 < param_1) {
    param_2 = param_1;
  }
  piVar2 = (int *)cast_allocHandle(param_2 * 0x10 + 0x24,1);
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    *(int *)(iVar1 + 0x14) = param_1 + 1;
    iVar3 = 0;
    *(int *)(iVar1 + 0x20) = param_1;
    *(int *)(iVar1 + 0x18) = param_2;
    if (0 < param_2) {
      puVar4 = (undefined4 *)(iVar1 + 0x24);
      do {
        *puVar4 = 0xffffffff;
        iVar3 = iVar3 + 1;
        puVar4 = puVar4 + 4;
      } while (iVar3 < *(int *)(iVar1 + 0x18));
    }
  }
  return 0;
}


