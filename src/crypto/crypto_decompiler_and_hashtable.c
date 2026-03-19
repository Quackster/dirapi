// Module: crypto
// Topic: Decompiler output, hash table implementation, and math (atan2, pow)
// Address range: 0x6814B5A0 - 0x6814CB50
// Functions (22):
//   crypto_evalDecompileBlock
//   crypto_evalDecompileWrapper
//   crypto_decompileExpr
//   crypto_freeHandleCallback
//   crypto_insertHashEntry
//   crypto_getHashTableSize
//   crypto_findHashEntry
//   crypto_decompileBlock
//   crypto_removeHashEntry
//   crypto_decompileToString
//   crypto_isDecompileReady
//   crypto_decompileNode
//   crypto_computeAtan2
//   crypto_decompileFloat
//   crypto_computePow
//   crypto_getStoredFloat
//   crypto_atan2
//   crypto_pow
//   crypto_fabs
//   crypto_atan
//   crypto_scalbn
//   crypto_computeSqrt

// ============================================================
// Function: crypto_evalDecompileBlock (FUN_6814b5a0)
// Address: 6814b5a0
// Size: 294 bytes
// Params: int * param_1, int param_2, undefined * * param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

int crypto_evalDecompileBlock(int *param_1,int param_2,undefined **param_3,int param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  int local_2c;
  int local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  int local_18;
  int local_14;
  int local_10;
  int *local_c;
  int local_8;
  
  iVar2 = *param_1;
  local_c = param_1;
  iVar3 = *(int *)(*(int *)(iVar2 + 0x80) + 0xc);
  local_28 = iVar2 + 0x70;
  local_24 = 0;
  local_20 = 0;
  local_1c = 3;
  iVar4 = *(int *)(iVar2 + 0x80);
  local_8 = *(int *)(param_2 + 0x20) * 4;
  uVar7 = *(int *)(param_2 + 0x20) * 5 + *(uint *)(iVar2 + 0x88) & ~*(uint *)(iVar2 + 0x88);
  iVar6 = *(int *)(iVar4 + 0xc);
  uVar1 = iVar6 + uVar7;
  local_2c = iVar2;
  if (*(uint *)(iVar4 + 8) < uVar1) {
    iVar6 = js_getSlotIndex(iVar2 + 0x70,uVar7);
  }
  else {
    *(uint *)(iVar4 + 0xc) = uVar1;
  }
  if (iVar6 == 0) {
    param_2 = 0;
  }
  else {
    iVar4 = param_1[0xe];
    local_14 = iVar6 + local_8;
    local_10 = 0;
    param_1[0xe] = param_2;
    local_18 = iVar6;
    param_2 = crypto_evaluateExpr(&local_2c,param_3,param_4);
    param_1[0xe] = iVar4;
    if (local_10 != 0) {
      do {
        crypto_evalNode(0);
      } while (local_10 != 0);
      crypto_parseNumber(param_1,"%s");
    }
  }
  piVar5 = *(int **)(iVar2 + 0x80);
  if ((piVar5 != (int *)(iVar2 + 0x70)) &&
     ((uint)(iVar3 - piVar5[1]) <= (uint)(piVar5[3] - piVar5[1]))) {
    piVar5[3] = iVar3 + *(uint *)(iVar2 + 0x88) & ~*(uint *)(iVar2 + 0x88);
    return param_2;
  }
  js_getPrototype((int *)(iVar2 + 0x70),iVar3);
  return param_2;
}



// ============================================================
// Function: crypto_evalDecompileWrapper (FUN_6814b6d0)
// Address: 6814b6d0
// Size: 27 bytes
// Params: int * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_evalDecompileWrapper(int *param_1,undefined4 *param_2)
{
  crypto_evalDecompileBlock(param_1,(int)param_2,(undefined **)*param_2,param_2[1]);
  return 0;
}



// ============================================================
// Function: crypto_decompileExpr (FUN_6814b6f0)
// Address: 6814b6f0
// Size: 657 bytes
// Params: int param_1, int * param_2, undefined * * param_3, uint * param_4
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * crypto_decompileExpr(int param_1,int *param_2,undefined **param_3,uint *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  undefined **_Dst;
  uint *puVar8;
  uint *puVar9;
  int *piVar10;
  int *piVar11;
  uint uVar12;
  int iVar13;
  undefined **ppuVar14;
  undefined **local_8;
  
  iVar13 = *(int *)(param_1 + 0x34);
  if (iVar13 != 0) {
    ppuVar14 = *(undefined ***)(iVar13 + 0x38);
    local_8 = ppuVar14;
    if (param_2 == (int *)0x1) {
      if (ppuVar14 == (undefined **)0x0) {
        if (*(int *)(iVar13 + 0x2c) == 0) goto LAB_6814b964;
        piVar11 = *(int **)(*(int *)(iVar13 + 0x2c) + 0xc);
        piVar10 = *(int **)(iVar13 + 0x1c);
        piVar4 = piVar10 + *(int *)(iVar13 + 0x18);
      }
      else {
        piVar11 = *(int **)(iVar13 + 0xc);
        piVar10 = *(int **)(iVar13 + 0x40);
        piVar4 = *(int **)(iVar13 + 0x3c);
      }
      if (((piVar11 == (int *)0x0) || (piVar10 == (int *)0x0)) || (piVar4 == (int *)0x0))
      goto LAB_6814b964;
      for (; piVar10 < piVar4; piVar10 = piVar10 + 1) {
        if ((undefined **)*piVar10 == param_3) {
          local_8 = (undefined **)piVar10[-piVar11[8]];
          break;
        }
      }
    }
    else {
      if ((ppuVar14 == (undefined **)0x0) ||
         (piVar11 = *(int **)(iVar13 + 0xc), piVar11 == (int *)0x0)) goto LAB_6814b964;
      if ((param_2 != (int *)0x0) &&
         (iVar2 = *(int *)(*(int *)(param_1 + 0x28) + 4),
         puVar1 = (undefined4 *)(*(int *)(iVar13 + 0x3c) + ((int)param_2 - piVar11[8]) * 4),
         (uint)((int)puVar1 - iVar2) < (uint)(*(int *)(*(int *)(param_1 + 0x28) + 0xc) - iVar2))) {
        local_8 = (undefined **)*puVar1;
      }
    }
    param_2 = piVar11;
    if (((uint)((int)local_8 - *param_2) < (uint)param_2[1]) ||
       (local_8 = ppuVar14, ppuVar14 != (undefined **)0x0)) {
      uVar12 = (uint)*(byte *)local_8;
      if (uVar12 == 0x53) {
        uVar12 = runtime_getBreakpointOpcode(param_1,param_2,(int)local_8);
      }
      iVar13 = uVar12 * 0x10;
      uVar3 = *(uint *)(&DAT_68193cbc + iVar13);
      uVar5 = uVar3 & 0x30;
      ppuVar14 = local_8;
      if (uVar5 != 0x10) {
        pbVar6 = runtime_getObjectSlot((int)param_2,(int)local_8);
        if (((pbVar6 == (byte *)0x0) || (0xbf < (*pbVar6 & 0xf8))) || (*pbVar6 >> 3 != 0xc))
        goto LAB_6814b964;
        uVar7 = js_getObjectFlags((int)pbVar6,0);
        ppuVar14 = (undefined **)((int)local_8 - uVar7);
      }
      pbVar6 = (byte *)(((int)(char)(&DAT_68193cb8)[iVar13] - (int)ppuVar14) + (int)local_8);
      if ((uVar3 & 0x1bc0) == 0) {
        param_3 = (undefined **)0x0;
        _Dst = ppuVar14;
      }
      else {
        _Dst = (undefined **)xtra_getPropertyById(param_1,(int)pbVar6);
        if (_Dst == (undefined **)0x0) {
          return (uint *)0x0;
        }
        memcpy(_Dst,ppuVar14,(size_t)pbVar6);
        param_3 = _Dst;
        if (uVar5 == 0x10) {
          *(undefined1 *)_Dst = 0x3b;
        }
        else {
          iVar13 = (int)pbVar6 - (int)(char)(&DAT_68193cb8)[iVar13];
          if (uVar5 == 0x20) {
            *(byte *)(iVar13 + (int)_Dst) = (-((uVar3 & 0x40) != 0) & 0xc9U) + 0x35;
          }
          else if (uVar5 == 0x30) {
            *(byte *)(iVar13 + (int)_Dst) = (-((uVar3 & 0x40) != 0) & 200U) + 0x37;
          }
          else if (uVar12 == 0x7a) {
            *(undefined1 *)(iVar13 + (int)_Dst) = 0x37;
          }
          else if (uVar12 == 0x84) {
            *(undefined1 *)(iVar13 + (int)_Dst) = 0x3a;
          }
        }
      }
      puVar8 = (uint *)crypto_createBinaryOp(param_1,"js_DecompileValueGenerator",0,0);
      if ((puVar8 == (uint *)0x0) ||
         (iVar13 = crypto_evalDecompileBlock((int *)puVar8,(int)param_2,_Dst,(int)pbVar6), iVar13 == 0)) {
        puVar9 = (uint *)0x0;
      }
      else {
        puVar9 = crypto_getOperandType(puVar8);
      }
      crypto_getOperandCount(puVar8);
      if (param_3 != (undefined **)0x0) {
        xtra_checkAndFlush(param_1,(int)param_3);
      }
      return puVar9;
    }
  }
LAB_6814b964:
  if (param_4 == (uint *)0x0) {
    param_4 = (uint *)certs_hashLookup(param_1,(uint)param_3);
  }
  return param_4;
}



// ============================================================
// Function: crypto_freeHandleCallback (FUN_6814b9a0)
// Address: 6814b9a0
// Size: 22 bytes
// Params: undefined4 param_1, undefined4 param_2, int param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_freeHandleCallback(undefined4 param_1,undefined4 param_2,int param_3)
{
  if (param_3 == 1) {
    js_freeHandle();
  }
  return 0;
}



// ============================================================
// Function: crypto_insertHashEntry (FUN_6814b9c0)
// Address: 6814b9c0
// Size: 205 bytes
// Params: uint param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4, undefined * * param_5, undefined4 param_6
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 *
crypto_insertHashEntry(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
            undefined **param_5,undefined4 param_6)

{
  size_t _Size;
  undefined4 *puVar1;
  void *_Dst;
  undefined4 *puVar2;
  
  if (param_1 < 0x11) {
    param_1 = 4;
  }
  else {
    param_1 = crypto_decompileNode(param_1);
    if ((int)param_1 < 0) {
      return (undefined4 *)0x0;
    }
  }
  if (param_5 == (undefined **)0x0) {
    param_5 = &PTR_FUN_68194678;
  }
  puVar1 = (undefined4 *)(*(code *)*param_5)(param_6,0x20);
  puVar2 = (undefined4 *)0x0;
  if (puVar1 != (undefined4 *)0x0) {
    *puVar1 = 0;
    puVar1[1] = 0;
    puVar1[3] = 0;
    puVar1[4] = 0;
    puVar1[5] = 0;
    puVar1[6] = 0;
    puVar1[7] = 0;
    _Size = (1 << ((byte)param_1 & 0x1f)) * 4;
    puVar1[2] = 0x20 - param_1;
    _Dst = (void *)(*(code *)*param_5)(param_6,_Size);
    *puVar1 = _Dst;
    if (_Dst == (void *)0x0) {
      (*(code *)param_5[1])(param_6,puVar1);
      return (undefined4 *)0x0;
    }
    memset(_Dst,0,_Size);
    puVar1[3] = param_2;
    puVar1[5] = param_4;
    puVar1[4] = param_3;
    puVar1[6] = param_5;
    puVar1[7] = param_6;
    puVar2 = puVar1;
  }
  return puVar2;
}



// ============================================================
// Function: crypto_getHashTableSize (FUN_6814ba90)
// Address: 6814ba90
// Size: 122 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_getHashTableSize(int *param_1)
{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint local_8;
  
  iVar2 = param_1[7];
  uVar5 = 1 << (0x20U - (char)param_1[2] & 0x1f);
  iVar3 = param_1[6];
  local_8 = 0;
  if (uVar5 != 0) {
    do {
      puVar1 = (undefined4 *)(*param_1 + local_8 * 4);
      puVar4 = (undefined4 *)*puVar1;
      while (puVar4 != (undefined4 *)0x0) {
        *puVar1 = *puVar4;
        (**(code **)(iVar3 + 0xc))(iVar2,puVar4,1);
        puVar4 = (undefined4 *)*puVar1;
      }
      local_8 = local_8 + 1;
    } while (local_8 < uVar5);
  }
  (**(code **)(iVar3 + 4))(iVar2,*param_1);
  (**(code **)(iVar3 + 4))(iVar2,param_1);
  return 0;
}



// ============================================================
// Function: crypto_findHashEntry (FUN_6814bb10)
// Address: 6814bb10
// Size: 105 bytes
// Params: int * param_1, int param_2, undefined4 param_3
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 * crypto_findHashEntry(int *param_1,int param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  
  uVar6 = (uint)(param_2 * -0x61c88647) >> ((byte)param_1[2] & 0x1f);
  puVar1 = (undefined4 *)(*param_1 + uVar6 * 4);
  puVar4 = *(undefined4 **)(*param_1 + uVar6 * 4);
  puVar3 = puVar1;
  while( true ) {
    puVar2 = puVar4;
    if (puVar2 == (undefined4 *)0x0) {
      return puVar3;
    }
    if ((puVar2[1] == param_2) && (iVar5 = (*(code *)param_1[4])(param_3,puVar2[2]), iVar5 != 0))
    break;
    puVar4 = (undefined4 *)*puVar2;
    puVar3 = puVar2;
  }
  if (puVar3 != puVar1) {
    *puVar3 = *puVar2;
    *puVar2 = *puVar1;
    *puVar1 = puVar2;
  }
  return puVar1;
}



// ============================================================
// Function: crypto_decompileBlock (FUN_6814bb80)
// Address: 6814bb80
// Size: 266 bytes
// Params: int * param_1, undefined4 * param_2, int param_3, undefined4 param_4, undefined4 param_5
// Return: undefined4 *
// Calling convention: __stdcall
// ============================================================

undefined4 *
crypto_decompileBlock(int *param_1,undefined4 *param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  void *_Dst;
  undefined4 *puVar4;
  undefined4 *puVar5;
  
  puVar5 = (undefined4 *)(1 << (0x20U - (char)param_1[2] & 0x1f));
  if ((int)puVar5 - ((uint)puVar5 >> 3) <= (uint)param_1[1]) {
    iVar1 = *param_1;
    _Dst = (void *)(**(code **)param_1[6])(param_1[7],(int)puVar5 * 8);
    *param_1 = (int)_Dst;
    if (_Dst == (void *)0x0) {
      *param_1 = iVar1;
      return (undefined4 *)0x0;
    }
    memset(_Dst,0,(int)puVar5 * 8);
    param_1[2] = param_1[2] + -1;
    param_2 = (undefined4 *)0x0;
    if (puVar5 != (undefined4 *)0x0) {
      do {
        puVar3 = *(undefined4 **)(iVar1 + (int)param_2 * 4);
        while (puVar3 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)*puVar3;
          puVar4 = crypto_findHashEntry(param_1,puVar3[1],puVar3[2]);
          *puVar3 = 0;
          *puVar4 = puVar3;
          puVar3 = puVar2;
        }
        param_2 = (undefined4 *)((int)param_2 + 1);
      } while (param_2 < puVar5);
    }
    (**(code **)(param_1[6] + 4))(param_1[7],iVar1);
    param_2 = crypto_findHashEntry(param_1,param_3,param_4);
  }
  puVar5 = (undefined4 *)(**(code **)(param_1[6] + 8))(param_1[7],param_4);
  if (puVar5 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar5[2] = param_4;
  puVar5[1] = param_3;
  puVar5[3] = param_5;
  *puVar5 = *param_2;
  *param_2 = puVar5;
  param_1[1] = param_1[1] + 1;
  return puVar5;
}



// ============================================================
// Function: crypto_removeHashEntry (FUN_6814bc90)
// Address: 6814bc90
// Size: 227 bytes
// Params: int * param_1, undefined4 * param_2, undefined4 * param_3
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_removeHashEntry(int *param_1,undefined4 *param_2,undefined4 *param_3)
{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  void *_Dst;
  undefined4 *puVar5;
  undefined4 *puVar6;
  
  *param_2 = *param_3;
  (**(code **)(param_1[6] + 0xc))(param_1[7],param_3,1);
  puVar6 = (undefined4 *)(1 << (0x20U - (char)param_1[2] & 0x1f));
  if (puVar6 < (undefined4 *)0x11) {
    uVar4 = 0;
  }
  else {
    uVar4 = (uint)puVar6 >> 2;
  }
  param_1[1] = param_1[1] + -1;
  if ((uint)param_1[1] < uVar4) {
    iVar1 = *param_1;
    uVar4 = (uint)((int)puVar6 * 4) >> 1;
    _Dst = (void *)(**(code **)param_1[6])(param_1[7],uVar4);
    *param_1 = (int)_Dst;
    if (_Dst == (void *)0x0) {
      *param_1 = iVar1;
      return 0;
    }
    memset(_Dst,0,uVar4);
    param_1[2] = param_1[2] + 1;
    param_2 = (undefined4 *)0x0;
    if (puVar6 != (undefined4 *)0x0) {
      do {
        puVar3 = *(undefined4 **)(iVar1 + (int)param_2 * 4);
        while (puVar3 != (undefined4 *)0x0) {
          puVar2 = (undefined4 *)*puVar3;
          puVar5 = crypto_findHashEntry(param_1,puVar3[1],puVar3[2]);
          *puVar3 = 0;
          *puVar5 = puVar3;
          puVar3 = puVar2;
        }
        param_2 = (undefined4 *)((int)param_2 + 1);
      } while (param_2 < puVar6);
    }
    (**(code **)(param_1[6] + 4))(param_1[7],iVar1);
  }
  return 0;
}



// ============================================================
// Function: crypto_decompileToString (FUN_6814bd80)
// Address: 6814bd80
// Size: 162 bytes
// Params: int * param_1, undefined * param_2, undefined4 param_3
// Return: int
// Calling convention: __stdcall
// ============================================================

int crypto_decompileToString(int *param_1,undefined *param_2,undefined4 param_3)

{
  int *piVar1;
  int *piVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint local_c;
  int *local_8;
  
  uVar4 = 1 << (0x20U - (char)param_1[2] & 0x1f);
  iVar5 = 0;
  local_8 = (int *)0x0;
  local_c = 0;
  if (uVar4 != 0) {
    do {
      piVar1 = *(int **)(*param_1 + local_c * 4);
      piVar2 = (int *)(*param_1 + local_c * 4);
      while (piVar1 != (int *)0x0) {
        uVar3 = (*(code *)param_2)(piVar1,iVar5,param_3);
        iVar5 = iVar5 + 1;
        piVar6 = piVar1;
        if (((uVar3 & 6) != 0) && (*piVar2 = *piVar1, piVar6 = piVar2, (uVar3 & 2) != 0)) {
          *piVar1 = (int)local_8;
          local_8 = piVar1;
        }
        if ((uVar3 & 1) != 0) goto joined_r0x6814be00;
        piVar2 = piVar6;
        piVar1 = (int *)*piVar6;
      }
      local_c = local_c + 1;
    } while (local_c < uVar4);
  }
joined_r0x6814be00:
  while (local_8 != (int *)0x0) {
    crypto_removeHashEntry(param_1,&local_8,local_8);
  }
  return iVar5;
}



// ============================================================
// Function: crypto_isDecompileReady (FUN_6814be30)
// Address: 6814be30
// Size: 18 bytes
// Params: int param_1, int param_2
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool crypto_isDecompileReady(int param_1,int param_2)

{
  return param_1 == param_2;
}



// ============================================================
// Function: crypto_decompileNode (FUN_6814be50)
// Address: 6814be50
// Size: 89 bytes
// Params: uint param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crypto_decompileNode(uint param_1)

{
  uint uVar1;
  
  uVar1 = (uint)((param_1 & param_1 - 1) != 0);
  if (param_1 >> 0x10 != 0) {
    uVar1 = uVar1 + 0x10;
    param_1 = param_1 >> 0x10;
  }
  if (param_1 >> 8 != 0) {
    uVar1 = uVar1 + 8;
    param_1 = param_1 >> 8;
  }
  if (param_1 >> 4 != 0) {
    uVar1 = uVar1 + 4;
    param_1 = param_1 >> 4;
  }
  if (param_1 >> 2 != 0) {
    uVar1 = uVar1 + 2;
    param_1 = param_1 >> 2;
  }
  if ((param_1 & 0xfffffffe) != 0) {
    uVar1 = uVar1 + 1;
  }
  return uVar1;
}



// ============================================================
// Function: crypto_computeAtan2 (FUN_6814beb0)
// Address: 6814beb0
// Size: 28 bytes
// Params: double param_1, double param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_computeAtan2(double param_1,double param_2)
{
  crypto_atan2(param_1,param_2);
  return 0;
}



// ============================================================
// Function: crypto_decompileFloat (FUN_6814bed0)
// Address: 6814bed0
// Size: 41 bytes
// Params: double param_1, undefined8 param_2
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 crypto_decompileFloat(double param_1,undefined8 param_2)

{
  param_1 = (double)CONCAT44(((*(unsigned int *)((char *)&param_2 + 4)) ^ (*(unsigned int *)((char *)&param_1 + 4))) & 0x7fffffff ^ (*(unsigned int *)((char *)&param_2 + 4)),
                             (*(unsigned int *)((char *)&param_1 + 0)));
  return (float10)param_1;
}



// ============================================================
// Function: crypto_computePow (FUN_6814bf00)
// Address: 6814bf00
// Size: 28 bytes
// Params: double param_1, double param_2
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_computePow(double param_1,double param_2)
{
  crypto_pow(param_1,param_2);
  return 0;
}



// ============================================================
// Function: crypto_getStoredFloat (FUN_6814bf20)
// Address: 6814bf20
// Size: 16 bytes
// Return: undefined8
// Calling convention: __stdcall
// ============================================================

undefined8 crypto_getStoredFloat(void)

{
  return CONCAT44(DAT_68196a1c,DAT_68196a18);
}



// ============================================================
// Function: crypto_atan2 (FUN_6814bf30)
// Address: 6814bf30
// Size: 607 bytes
// Params: double param_1, double param_2
// Return: float10
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 crypto_atan2(double param_1,double param_2)

{
  double dVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  float10 fVar6;
  float10 fVar7;
  uint local_c;
  uint uStack_8;
  
  dVar1 = param_2;
  fVar6 = (float10)param_2;
  uStack_8 = (uint)((ulonglong)param_2 >> 0x20);
  fVar7 = (float10)param_1;
  local_c = SUB84(param_2,0);
  (*(unsigned int *)((char *)&param_2 + 4)) = (uint)((ulonglong)param_1 >> 0x20);
  uVar4 = uStack_8 & 0x7fffffff;
  uVar2 = (*(unsigned int *)((char *)&param_2 + 4)) & 0x7fffffff;
  if ((0x7ff00000 < ((-local_c | local_c) >> 0x1f | uVar4)) ||
     ((*(unsigned int *)((char *)&param_2 + 0)) = SUB84(param_1,0),
     0x7ff00000 < ((-(*(unsigned int *)((char *)&param_2 + 0)) | (*(unsigned int *)((char *)&param_2 + 0))) >> 0x1f | uVar2))) {
    return fVar7 + fVar6;
  }
  if (dVar1 == 1.0) {
    fVar6 = crypto_atan(param_1);
    return fVar6;
  }
  uVar5 = (int)(*(unsigned int *)((char *)&param_2 + 4)) >> 0x1f & 1U | (int)uStack_8 >> 0x1e & 2U;
  if ((*(unsigned int *)((char *)&param_2 + 0)) == 0 && ((ulonglong)param_1 & 0x7fffffff00000000) == 0) {
    switch(uVar5) {
    case 0:
    case 1:
      return fVar7;
    case 2:
      goto switchD_6814bfc6_caseD_2;
    case 3:
      goto switchD_6814bfc6_caseD_3;
    }
  }
  if (local_c != 0 || ((ulonglong)dVar1 & 0x7fffffff00000000) != 0) {
    if (uVar4 == 0x7ff00000) {
      if (uVar2 == 0x7ff00000) {
        switch(uVar5) {
        case 0:
          fVar6 = (float10)_DAT_681946a0;
          goto LAB_6814c057;
        case 1:
          return -(float10)_DAT_681946a0 - (float10)_DAT_68194698;
        case 2:
          return (float10)_DAT_681946a0 * (float10)3.0 + (float10)_DAT_68194698;
        case 3:
          return (float10)_DAT_681946a0 * (float10)-3.0 - (float10)_DAT_68194698;
        }
        goto switchD_6814c04a_default;
      }
      switch(uVar5) {
      case 0:
        return (float10)_DAT_68196a20;
      case 1:
        return -(float10)_DAT_68196a20;
      case 2:
switchD_6814bfc6_caseD_2:
        return (float10)_DAT_68194698 + (float10)_DAT_681946b0;
      case 3:
switchD_6814bfc6_caseD_3:
        return -(float10)_DAT_681946b0 - (float10)_DAT_68194698;
      }
    }
    if (uVar2 != 0x7ff00000) {
      iVar3 = (int)(uVar2 - uVar4) >> 0x14;
      if (iVar3 < 0x3d) {
        if (((longlong)dVar1 < 0) && (iVar3 < -0x3c)) {
          fVar6 = (float10)0;
        }
        else {
          fVar6 = crypto_fabs((double)(fVar7 / fVar6));
          fVar6 = crypto_atan((double)fVar6);
        }
      }
      else {
        fVar6 = (float10)_DAT_681946b8 * (float10)0.5 + (float10)_DAT_681946a8;
      }
      if (uVar5 == 0) {
        return fVar6;
      }
      if (uVar5 == 1) {
        param_2 = -(double)fVar6;
        return (float10)param_2;
      }
      if (uVar5 != 2) {
        return (fVar6 - (float10)_DAT_681946b8) - (float10)_DAT_681946b0;
      }
      return (float10)_DAT_681946b0 - (fVar6 - (float10)_DAT_681946b8);
    }
  }
switchD_6814c04a_default:
  fVar6 = (float10)_DAT_681946a8;
  if ((longlong)param_1 < 0) {
    return -fVar6 - (float10)_DAT_68194698;
  }
LAB_6814c057:
  return fVar6 + (float10)_DAT_68194698;
}



// ============================================================
// Function: crypto_pow (FUN_6814c1c0)
// Address: 6814c1c0
// Size: 1730 bytes
// Params: double param_1, double param_2
// Return: float10
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 crypto_pow(double param_1,double param_2)

{
  double dVar1;
  char cVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  uint uVar8;
  float10 fVar9;
  float10 fVar10;
  float10 fVar11;
  float10 fVar12;
  float10 fVar13;
  undefined8 local_18;
  undefined8 local_10;
  
  dVar1 = param_1;
  fVar9 = (float10)param_1;
  fVar10 = (float10)param_2;
  (*(unsigned int *)((char *)&local_10 + 4)) = (uint)((ulonglong)param_1 >> 0x20);
  (*(unsigned int *)((char *)&local_18 + 4)) = (uint)((ulonglong)param_2 >> 0x20);
  (*(unsigned int *)((char *)&local_18 + 0)) = SUB84(param_2,0);
  uVar8 = (*(unsigned int *)((char *)&local_18 + 4)) & 0x7fffffff;
  (*(unsigned int *)((char *)&local_10 + 4)) = (*(unsigned int *)((char *)&local_10 + 4)) & 0x7fffffff;
  if (((ulonglong)param_2 & 0x7fffffff00000000) == 0 && (uint)local_18 == 0) {
    return (float10)_DAT_681946f0;
  }
  if (((0x7ff00000 < (*(unsigned int *)((char *)&local_10 + 4))) ||
      ((((*(unsigned int *)((char *)&local_10 + 0)) = SUB84(param_1,0), (*(unsigned int *)((char *)&local_10 + 4)) == 0x7ff00000 && ((int)local_10 != 0)) ||
       (0x7ff00000 < uVar8)))) || ((uVar8 == 0x7ff00000 && ((uint)local_18 != 0)))) {
    return fVar10 + fVar9;
  }
  iVar7 = 0;
  if ((longlong)param_1 < 0) {
    if (0x433fffff < uVar8) {
      iVar7 = 2;
      goto LAB_6814c2aa;
    }
    if (uVar8 < 0x3ff00000) goto LAB_6814c2aa;
    iVar5 = ((int)uVar8 >> 0x14) + -0x3ff;
    cVar2 = (char)iVar5;
    if (0x14 < iVar5) {
      bVar6 = 0x34 - cVar2;
      uVar4 = (uint)local_18 >> (bVar6 & 0x1f);
      if (uVar4 << (bVar6 & 0x1f) == (uint)local_18) {
        iVar7 = 2 - (uVar4 & 1);
      }
      else {
        iVar7 = 0;
      }
      goto LAB_6814c2aa;
    }
    if ((uint)local_18 == 0) {
      bVar6 = 0x14 - cVar2;
      uVar4 = (int)uVar8 >> (bVar6 & 0x1f);
      if (uVar4 << (bVar6 & 0x1f) == uVar8) {
        iVar7 = 2 - (uVar4 & 1);
      }
      goto LAB_6814c2b2;
    }
  }
  else {
LAB_6814c2aa:
    if ((uint)local_18 == 0) {
LAB_6814c2b2:
      if (uVar8 == 0x7ff00000) {
        if ((*(unsigned int *)((char *)&local_10 + 4)) != 0x3ff00000 || (int)local_10 != 0) {
          if ((*(unsigned int *)((char *)&local_10 + 4)) < 0x3ff00000) {
            if ((longlong)param_2 < 0) {
              return -fVar10;
            }
          }
          else if (-1 < (longlong)param_2) {
            return fVar10;
          }
          return (float10)_DAT_68196a28;
        }
        goto LAB_6814c3ca;
      }
      if (uVar8 == 0x3ff00000) {
        if (-1 < (longlong)param_2) {
          return fVar9;
        }
        return (float10)_DAT_681946f0 / fVar9;
      }
      if ((*(unsigned int *)((char *)&local_18 + 4)) == 0x40000000) goto LAB_6814c44e;
      if (((*(unsigned int *)((char *)&local_18 + 4)) == 0x3fe00000) && (-1 < (longlong)param_1)) {
        fVar10 = (float10)crypto_computeSqrt(param_1);
        return fVar10;
      }
    }
  }
  fVar10 = crypto_fabs(param_1);
  if (((int)local_10 == 0) &&
     ((((*(unsigned int *)((char *)&local_10 + 4)) == 0x7ff00000 || (((ulonglong)param_1 & 0x7fffffff00000000) == 0)) ||
      ((*(unsigned int *)((char *)&local_10 + 4)) == 0x3ff00000)))) {
    if ((longlong)param_2 < 0) {
      fVar10 = (float10)_DAT_681946f0 / fVar10;
    }
    if (-1 < (longlong)param_1) {
      return fVar10;
    }
    if ((*(unsigned int *)((char *)&local_10 + 4)) != 0x3ff00000 || iVar7 != 0) {
      if (iVar7 != 1) {
        return fVar10;
      }
      return -fVar10;
    }
  }
  else {
    if (-1 < (longlong)param_1 || iVar7 != 0) {
      (*(unsigned int *)((char *)&local_10 + 0)) = SUB84(_DAT_68196a28,0);
      uVar3 = (int)local_10;
      if (uVar8 < 0x41e00001) {
        iVar5 = 0;
        if ((*(unsigned int *)((char *)&local_10 + 4)) < 0x100000) {
          iVar5 = -0x35;
          fVar10 = (float10)_DAT_68194700 * fVar10;
          (*(unsigned int *)((char *)&local_10 + 4)) = (uint)((ulonglong)(double)fVar10 >> 0x20);
        }
        (*(unsigned int *)((char *)&param_1 + 4)) = iVar5 + -0x3ff + ((int)(*(unsigned int *)((char *)&local_10 + 4)) >> 0x14);
        (*(unsigned int *)((char *)&local_10 + 4)) = (*(unsigned int *)((char *)&local_10 + 4)) & 0xfffff;
        uVar8 = (*(unsigned int *)((char *)&local_10 + 4)) | 0x3ff00000;
        if ((*(unsigned int *)((char *)&local_10 + 4)) < 0x3988f) {
          iVar5 = 0;
        }
        else if ((*(unsigned int *)((char *)&local_10 + 4)) < 0xbb67a) {
          iVar5 = 1;
        }
        else {
          (*(unsigned int *)((char *)&param_1 + 4)) = (*(unsigned int *)((char *)&param_1 + 4)) + 1;
          iVar5 = 0;
          uVar8 = uVar8 - 0x100000;
        }
        (*(unsigned int *)((char *)&local_10 + 0)) = SUB84((double)fVar10,0);
        local_10 = (double)CONCAT44(uVar8,(int)local_10);
        fVar10 = (float10)local_10;
        fVar12 = (float10)_DAT_681946f0 / ((float10)(double)(&DAT_681946c0)[iVar5] + fVar10);
        fVar9 = fVar12 * (fVar10 - (float10)(double)(&DAT_681946c0)[iVar5]);
        local_10 = (double)((ulonglong)(double)fVar9 & 0xffffffff00000000);
        fVar11 = (float10)local_10;
        local_10 = (double)CONCAT44(((int)(uVar8 | 0x40000000) >> 1) + (iVar5 + 2) * 0x40000,uVar3);
        fVar12 = (((fVar10 - (float10)(double)(&DAT_681946c0)[iVar5]) - fVar11 * (float10)local_10)
                 - (fVar10 - ((float10)local_10 - (float10)(double)(&DAT_681946c0)[iVar5])) * fVar11
                 ) * fVar12;
        fVar10 = fVar9 * fVar9;
        fVar13 = (fVar11 + fVar9) * fVar12 +
                 ((((((float10)_DAT_68194740 * fVar10 + (float10)_DAT_68194738) * fVar10 +
                    (float10)_DAT_68194730) * fVar10 + (float10)_DAT_68194728) * fVar10 +
                  (float10)_DAT_68194720) * fVar10 + (float10)_DAT_68194718) * fVar10 * fVar10;
        local_10 = (double)((ulonglong)(double)(fVar11 * fVar11 + (float10)3.0 + fVar13) &
                           0xffffffff00000000);
        fVar10 = (float10)local_10;
        fVar13 = (fVar13 - ((fVar10 - (float10)3.0) - fVar11 * fVar11)) * fVar9 + fVar10 * fVar12;
        local_10 = (double)((ulonglong)(double)(fVar13 + fVar11 * fVar10) & 0xffffffff00000000);
        fVar9 = (float10)local_10;
        fVar10 = (fVar13 - (fVar9 - fVar11 * fVar10)) * (float10)_DAT_68194790 +
                 (float10)_DAT_681947a0 * fVar9 + (float10)(double)(&DAT_681946e0)[iVar5];
        local_10 = (double)((ulonglong)
                            (double)(fVar10 + (float10)_DAT_68194798 * fVar9 +
                                     (float10)(double)(&DAT_681946d0)[iVar5] +
                                    (float10)(*(unsigned int *)((char *)&param_1 + 4))) & 0xffffffff00000000);
        fVar11 = (float10)local_10;
        fVar10 = fVar10 - (((fVar11 - (float10)(*(unsigned int *)((char *)&param_1 + 4))) -
                           (float10)(double)(&DAT_681946d0)[iVar5]) - (float10)_DAT_68194798 * fVar9
                          );
        goto LAB_6814c658;
      }
      if (uVar8 < 0x43f00001) {
LAB_6814c419:
        if ((*(unsigned int *)((char *)&local_10 + 4)) < 0x3fefffff) {
LAB_6814c421:
          if ((longlong)param_2 < 0) {
LAB_6814c428:
            return (float10)_DAT_68194708 * (float10)_DAT_68194708;
          }
        }
        else {
          if ((*(unsigned int *)((char *)&local_10 + 4)) < 0x3ff00001) {
            fVar9 = (float10)param_1 - (float10)1.0;
            fVar10 = (float10)_DAT_681947b8 * fVar9 -
                     ((float10)0.5 - ((float10)0.3333333333333333 - fVar9 * (float10)0.25) * fVar9)
                     * fVar9 * fVar9 * (float10)_DAT_681947a8;
            local_10 = (double)((ulonglong)(double)(fVar10 + (float10)_DAT_681947b0 * fVar9) &
                               0xffffffff00000000);
            fVar11 = (float10)local_10;
            fVar10 = fVar10 - (fVar11 - (float10)_DAT_681947b0 * fVar9);
LAB_6814c658:
            fVar13 = (float10)_DAT_681946f0;
            param_1 = _DAT_681946f0;
            fVar9 = fVar13;
            if (iVar7 == 1 && (longlong)dVar1 < 0) {
              fVar9 = -fVar13;
              param_1 = (double)fVar9;
            }
            local_18 = (double)((ulonglong)param_2 & 0xffffffff00000000);
            fVar12 = ((float10)param_2 - (float10)local_18) * fVar11 + fVar10 * (float10)param_2;
            fVar11 = fVar11 * (float10)local_18;
            fVar10 = fVar12 + fVar11;
            dVar1 = (double)fVar10;
            (*(unsigned int *)((char *)&local_10 + 4)) = (uint)((ulonglong)dVar1 >> 0x20);
            if ((longlong)dVar1 < 0x4090000000000000) {
              if ((0x4090cbff < ((*(unsigned int *)((char *)&local_10 + 4)) & 0x7fffffff)) &&
                 ((dVar1 != -1075.0 || (fVar12 <= fVar10 - fVar11)))) {
                return (float10)_DAT_68194710 * fVar9 * (float10)_DAT_68194710;
              }
            }
            else {
              if (dVar1 != 1024.0) {
                return (float10)_DAT_68194708 * fVar9 * (float10)_DAT_68194708;
              }
              if (fVar10 - fVar11 < fVar12 + (float10)_DAT_68194788) {
                return (float10)_DAT_68194708 * fVar9 * (float10)_DAT_68194708;
              }
            }
            iVar7 = 0;
            if (0x3fe00000 < ((*(unsigned int *)((char *)&local_10 + 4)) & 0x7fffffff)) {
              (*(unsigned int *)((char *)&local_10 + 4)) =
                   (0x100000 >> ((char)((int)((*(unsigned int *)((char *)&local_10 + 4)) & 0x7fffffff) >> 0x14) + 2U & 0x1f)) +
                   (*(unsigned int *)((char *)&local_10 + 4));
              bVar6 = (char)((int)(*(unsigned int *)((char *)&local_10 + 4)) >> 0x14) + 1;
              iVar7 = (int)((*(unsigned int *)((char *)&local_10 + 4)) & 0xfffff | 0x100000) >> (0x14 - bVar6 & 0x1f);
              local_10 = (double)CONCAT44(~(0xfffff >> (bVar6 & 0x1f)) & (*(unsigned int *)((char *)&local_10 + 4)),uVar3);
              if ((longlong)dVar1 < 0) {
                iVar7 = -iVar7;
              }
              fVar11 = fVar11 - (float10)local_10;
            }
            local_10 = (double)((ulonglong)(double)(fVar12 + fVar11) & 0xffffffff00000000);
            fVar10 = (float10)local_10;
            fVar12 = (fVar12 - (fVar10 - fVar11)) * (float10)_DAT_68194770 +
                     (float10)_DAT_68194780 * fVar10;
            fVar11 = fVar12 + (float10)_DAT_68194778 * fVar10;
            fVar12 = fVar12 - (fVar11 - (float10)_DAT_68194778 * fVar10);
            fVar10 = fVar11 * fVar11;
            fVar10 = fVar11 - (((((float10)_DAT_68194768 * fVar10 + (float10)_DAT_68194760) * fVar10
                                + (float10)_DAT_68194758) * fVar10 + (float10)_DAT_68194750) *
                               fVar10 + (float10)_DAT_68194748) * fVar10;
            fVar13 = fVar13 - (((fVar10 * fVar11) / (fVar10 - (float10)_DAT_681946f8) -
                               (fVar12 * fVar11 + fVar12)) - fVar11);
            (*(unsigned int *)((char *)&local_10 + 4)) = (uint)((ulonglong)(double)fVar13 >> 0x20);
            if ((int)((*(unsigned int *)((char *)&local_10 + 4)) + iVar7 * 0x100000 & 0xfff00000) < 1) {
              fVar10 = crypto_scalbn((double)fVar13,iVar7);
              return (float10)param_1 * fVar10;
            }
            (*(unsigned int *)((char *)&local_10 + 4)) = (uint)((ulonglong)(double)fVar13 >> 0x20);
            (*(unsigned int *)((char *)&local_10 + 0)) = SUB84((double)fVar13,0);
            local_10 = (double)CONCAT44((*(unsigned int *)((char *)&local_10 + 4)) + iVar7 * 0x100000,(int)local_10);
            return fVar9 * (float10)local_10;
          }
          if (0xffffffff < (longlong)param_2) goto LAB_6814c428;
        }
      }
      else {
        if ((*(unsigned int *)((char *)&local_10 + 4)) < 0x3ff00000) goto LAB_6814c421;
        if ((*(unsigned int *)((char *)&local_10 + 4)) < 0x3ff00000) goto LAB_6814c419;
        if (0xffffffff < (longlong)param_2) {
          return (float10)_DAT_68194708 * (float10)_DAT_68194708;
        }
      }
      fVar9 = (float10)_DAT_68194710;
LAB_6814c44e:
      return fVar9 * fVar9;
    }
    fVar10 = (float10)param_1;
  }
  fVar10 = fVar10 - fVar10;
LAB_6814c3ca:
  return fVar10 / fVar10;
}



// ============================================================
// Function: crypto_fabs (FUN_6814c890)
// Address: 6814c890
// Size: 23 bytes
// Params: double param_1
// Return: float10
// Calling convention: __stdcall
// ============================================================

float10 crypto_fabs(double param_1)

{
  param_1 = ABS(param_1);
  return (float10)param_1;
}



// ============================================================
// Function: crypto_atan (FUN_6814c8b0)
// Address: 6814c8b0
// Size: 411 bytes
// Params: double param_1
// Return: float10
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 crypto_atan(double param_1)

{
  int iVar1;
  uint uVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  
  fVar3 = (float10)param_1;
  uVar2 = (*(unsigned int *)((char *)&param_1 + 4)) & 0x7fffffff;
  if (uVar2 < 0x44100000) {
    if (uVar2 < 0x3fdc0000) {
      if ((uVar2 < 0x3e200000) && ((float10)_DAT_68194858 < (float10)_DAT_68194860 + fVar3)) {
        return fVar3;
      }
      iVar1 = -1;
    }
    else {
      fVar3 = crypto_fabs(param_1);
      if (uVar2 < 0x3ff30000) {
        if (uVar2 < 0x3fe60000) {
          iVar1 = 0;
          fVar3 = (fVar3 * (float10)2.0 - (float10)_DAT_68194858) / (fVar3 + (float10)2.0);
        }
        else {
          iVar1 = 1;
          fVar3 = (fVar3 - (float10)_DAT_68194858) / ((float10)_DAT_68194858 + fVar3);
        }
      }
      else if (uVar2 < 0x40038000) {
        iVar1 = 2;
        fVar3 = (fVar3 - (float10)1.5) / ((float10)1.5 * fVar3 + (float10)_DAT_68194858);
      }
      else {
        fVar3 = (float10)-1.0 / fVar3;
        iVar1 = 3;
      }
    }
    fVar4 = fVar3 * fVar3;
    fVar5 = fVar4 * fVar4;
    fVar4 = ((((((float10)_DAT_68194848 * fVar5 + (float10)_DAT_68194838) * fVar5 +
               (float10)_DAT_68194828) * fVar5 + (float10)_DAT_68194818) * fVar5 +
             (float10)_DAT_68194808) * fVar5 +
            ((((((float10)_DAT_68194850 * fVar5 + (float10)_DAT_68194840) * fVar5 +
               (float10)_DAT_68194830) * fVar5 + (float10)_DAT_68194820) * fVar5 +
             (float10)_DAT_68194810) * fVar5 + (float10)_DAT_68194800) * fVar4) * fVar3;
    if (-1 < iVar1) {
      fVar3 = (float10)*(double *)(&DAT_681947c0 + iVar1 * 8) -
              ((fVar4 - (float10)*(double *)(&DAT_681947e0 + iVar1 * 8)) - fVar3);
      if ((longlong)param_1 < 0) {
        fVar3 = -fVar3;
      }
      return fVar3;
    }
    return fVar3 - fVar4;
  }
  if ((uVar2 < 0x7ff00001) && ((uVar2 != 0x7ff00000 || ((*(unsigned int *)((char *)&param_1 + 0)) == 0)))) {
    if ((longlong)param_1 < 0x100000000) {
      return -(float10)_DAT_681947d8 - (float10)_DAT_681947f8;
    }
    return (float10)_DAT_681947f8 + (float10)_DAT_681947d8;
  }
  return fVar3 + fVar3;
}



// ============================================================
// Function: crypto_scalbn (FUN_6814ca50)
// Address: 6814ca50
// Size: 243 bytes
// Params: double param_1, int param_2
// Return: float10
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 crypto_scalbn(double param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  float10 fVar3;
  
  fVar3 = (float10)param_1;
  uVar1 = (int)(*(unsigned int *)((char *)&param_1 + 4)) >> 0x14 & 0x7ff;
  if (uVar1 == 0) {
    if (((ulonglong)param_1 & 0x7fffffff00000000) == 0 && (*(unsigned int *)((char *)&param_1 + 0)) == 0) {
      return fVar3;
    }
    fVar3 = fVar3 * (float10)_DAT_68194868;
    (*(unsigned int *)((char *)&param_1 + 4)) = (uint)((ulonglong)(double)fVar3 >> 0x20);
    uVar1 = ((int)(*(unsigned int *)((char *)&param_1 + 4)) >> 0x14 & 0x7ffU) - 0x36;
    if (param_2 < -50000) {
      return fVar3 * (float10)_DAT_68194880;
    }
  }
  if (uVar1 == 0x7ff) {
    return fVar3 + fVar3;
  }
  iVar2 = uVar1 + param_2;
  if (iVar2 < 0x7ff) {
    if (0 < iVar2) {
      (*(unsigned int *)((char *)&param_1 + 0)) = SUB84((double)fVar3,0);
      param_1 = (double)CONCAT44(iVar2 * 0x100000 | (*(unsigned int *)((char *)&param_1 + 4)) & 0x800fffff,(*(unsigned int *)((char *)&param_1 + 0)));
      return (float10)param_1;
    }
    if (-0x36 < iVar2) {
      (*(unsigned int *)((char *)&param_1 + 0)) = SUB84((double)fVar3,0);
      param_1 = (double)CONCAT44((iVar2 + 0x36) * 0x100000 | (*(unsigned int *)((char *)&param_1 + 4)) & 0x800fffff,
                                 (*(unsigned int *)((char *)&param_1 + 0)));
      return (float10)_DAT_68194870 * (float10)param_1;
    }
    if (param_2 < 0xc351) {
      fVar3 = crypto_decompileFloat(_DAT_68194880,(double)fVar3);
      return fVar3 * (float10)_DAT_68194880;
    }
  }
  fVar3 = crypto_decompileFloat(_DAT_68194878,(double)fVar3);
  return fVar3 * (float10)_DAT_68194878;
}



// ============================================================
// Function: crypto_computeSqrt (FUN_6814cb50)
// Address: 6814cb50
// Size: 21 bytes
// Params: undefined8 param_1
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_computeSqrt(undefined8 param_1)
{
  crypto_sqrt((uint)param_1,(uint)((ulonglong)param_1 >> 0x20));
  return 0;
}



