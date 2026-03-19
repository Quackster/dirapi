// Module: crypto
// Topic: String rope/unicode operations, math sqrt, and String prototype methods
// Address range: 0x6814CB70 - 0x6814FEA0
// Functions (35):
//   crypto_sqrt
//   crypto_allocString
//   crypto_getStringCapacity
//   crypto_resolveRopeOffset
//   crypto_getStringLen
//   crypto_flattenString
//   crypto_concatStrings
//   crypto_normalizeString
//   crypto_encodeUri
//   crypto_decodeUri
//   crypto_toLowerCaseSimple
//   crypto_getStringLenValue
//   crypto_splitStringChars
//   crypto_getCharAt
//   crypto_toQuotedString
//   crypto_wrapStringConstructor
//   crypto_convertToString
//   crypto_getStringValueOf
//   crypto_substringByRange
//   crypto_toUpperCase
//   crypto_toUpperCaseLocale
//   crypto_toLowerCase
//   crypto_toLowerCaseLocale
//   crypto_localeCompare
//   crypto_charAt
//   crypto_charCodeAt
//   crypto_boyerMooreSearch
//   crypto_indexOf
//   crypto_lastIndexOf
//   crypto_matchString
//   crypto_bigDivide
//   crypto_matchCallback
//   crypto_searchString
//   crypto_replaceString
//   crypto_evalReplacement

// ============================================================
// Function: crypto_sqrt (FUN_6814cb70)
// Address: 6814cb70
// Size: 500 bytes
// Params: uint param_1, uint param_2
// Return: float10
// Calling convention: __stdcall
// ============================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 crypto_sqrt(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  float10 fVar8;
  undefined8 local_1c;
  uint local_c;
  uint local_8;
  
  fVar8 = (float10)(double)CONCAT44(param_2,param_1);
  if ((param_2 & 0x7ff00000) == 0x7ff00000) {
    return fVar8 * fVar8 + fVar8;
  }
  if ((int)param_2 < 1) {
    if ((param_2 & 0x7fffffff) == 0 && param_1 == 0) {
      return fVar8;
    }
    if ((int)param_2 < 0) {
      return (fVar8 - fVar8) / (fVar8 - fVar8);
    }
  }
  iVar3 = (int)param_2 >> 0x14;
  if (iVar3 == 0) {
    iVar3 = 0;
    while (param_2 == 0) {
      iVar3 = iVar3 + -0x15;
      param_2 = param_1 >> 0xb;
      param_1 = param_1 << 0x15;
    }
    iVar4 = 0;
    for (; (param_2 & 0x100000) == 0; param_2 = param_2 * 2) {
      iVar4 = iVar4 + 1;
    }
    iVar3 = iVar3 + (1 - iVar4);
    param_2 = param_2 | param_1 >> (0x20 - (byte)iVar4 & 0x1f);
    param_1 = param_1 << ((byte)iVar4 & 0x1f);
  }
  uVar1 = param_2 & 0xfffff | 0x100000;
  if ((iVar3 - 0x3ffU & 1) != 0) {
    uVar1 = uVar1 * 2 - ((int)param_1 >> 0x1f);
    param_1 = param_1 * 2;
  }
  iVar6 = 0;
  param_2 = 0;
  iVar4 = uVar1 * 2 - ((int)param_1 >> 0x1f);
  uVar1 = param_1 * 2;
  local_8 = 0;
  local_c = 0;
  uVar5 = 0x200000;
  do {
    iVar7 = uVar5 + iVar6;
    if (iVar7 <= iVar4) {
      iVar4 = iVar4 - iVar7;
      iVar6 = iVar7 + uVar5;
      param_2 = param_2 + uVar5;
    }
    iVar7 = (int)uVar1 >> 0x1f;
    uVar1 = uVar1 * 2;
    uVar5 = uVar5 >> 1;
    iVar4 = iVar4 * 2 - iVar7;
  } while (uVar5 != 0);
  uVar5 = 0x80000000;
  do {
    uVar2 = local_8 + uVar5;
    if ((iVar6 < iVar4) || ((iVar6 == iVar4 && (uVar2 <= uVar1)))) {
      local_8 = uVar2 + uVar5;
      iVar7 = iVar6;
      if (((uVar2 & 0x80000000) == 0x80000000) && ((local_8 & 0x80000000) == 0)) {
        iVar7 = iVar6 + 1;
      }
      iVar4 = iVar4 - iVar6;
      if (uVar1 < uVar2) {
        iVar4 = iVar4 + -1;
      }
      uVar1 = uVar1 - uVar2;
      local_c = local_c + uVar5;
      iVar6 = iVar7;
    }
    iVar7 = (int)uVar1 >> 0x1f;
    uVar1 = uVar1 * 2;
    uVar5 = uVar5 >> 1;
    iVar4 = iVar4 * 2 - iVar7;
  } while (uVar5 != 0);
  if ((uVar1 != 0 || iVar4 != 0) && (_DAT_68194888 <= _DAT_68194888 - _DAT_68194890)) {
    if (local_c == 0xffffffff) {
      local_c = 0;
      param_2 = param_2 + 1;
    }
    else if (_DAT_68194890 + _DAT_68194888 <= _DAT_68194888) {
      local_c = local_c + (local_c & 1);
    }
    else {
      if (local_c == 0xfffffffe) {
        param_2 = param_2 + 1;
      }
      local_c = local_c + 2;
    }
  }
  local_c = local_c >> 1;
  if ((param_2 & 1) != 0) {
    local_c = local_c | 0x80000000;
  }
  local_1c = (double)CONCAT44(((int)(iVar3 - 0x3ffU) >> 1) * 0x100000 +
                              ((int)param_2 >> 1) + 0x3fe00000,local_c);
  return (float10)local_1c;
}



// ============================================================
// Function: crypto_allocString (FUN_6814cd70)
// Address: 6814cd70
// Size: 46 bytes
// Params: uint param_1
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_allocString(uint param_1)

{
  return *(undefined4 *)
          (&DAT_681821f8 +
          (uint)(byte)(&DAT_68180378)
                      [(uint)(byte)(&DAT_6817ff78)[(int)(param_1 & 0xffff) >> 6] << 6 |
                       param_1 & 0x3f] * 4);
}



// ============================================================
// Function: crypto_getStringCapacity (FUN_6814cda0)
// Address: 6814cda0
// Size: 49 bytes
// Params: uint param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crypto_getStringCapacity(uint param_1)

{
  return *(uint *)(&DAT_681821f8 +
                  (uint)(byte)(&DAT_68180378)
                              [(uint)(byte)(&DAT_6817ff78)[(int)(param_1 & 0xffff) >> 6] << 6 |
                               param_1 & 0x3f] * 4) & 0x1f;
}



// ============================================================
// Function: crypto_resolveRopeOffset (FUN_6814cde0)
// Address: 6814cde0
// Size: 283 bytes
// Params: uint * param_1, int param_2, uint * param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crypto_resolveRopeOffset(uint *param_1,int param_2,uint *param_3)

{
  uint local_18;
  uint local_14;
  uint local_10;
  uint *local_c [2];
  
  local_c[0] = (uint *)param_1[1];
  if ((*param_1 & 0x80000000) == 0) {
    local_14 = *param_1 >> 0xf & 0x7fff;
  }
  else {
    local_14 = 0;
  }
  local_10 = local_14;
  if ((*local_c[0] & 0x40000000) != 0) {
    if (param_2 < 100) {
      local_10 = crypto_resolveRopeOffset(local_c[0],param_2 + 1,(uint *)local_c);
      local_10 = local_10 + local_14;
    }
    else {
      do {
        if ((*local_c[0] & 0x80000000) == 0) {
          local_18 = *local_c[0] >> 0xf & 0x7fff;
        }
        else {
          local_18 = 0;
        }
        local_10 = local_10 + local_18;
        local_c[0] = (uint *)local_c[0][1];
      } while ((*local_c[0] & 0x40000000) != 0);
    }
    if (local_10 == 0) {
      param_1[1] = (uint)local_c[0];
    }
    else if (local_10 < 0x8000) {
      *param_1 = local_10 << 0xf | 0x40000000 |
                 (-(uint)((*param_1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_1;
      param_1[1] = (uint)local_c[0];
    }
  }
  *param_3 = (uint)local_c[0];
  return local_10;
}



// ============================================================
// Function: crypto_getStringLen (crypto_getStringLen)
// Address: 6814cf00
// Size: 42 bytes
// Params: uint * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int crypto_getStringLen(uint *param_1)

{
  uint uVar1;
  uint local_8;
  
  uVar1 = crypto_resolveRopeOffset(param_1,0,&local_8);
  return *(int *)(local_8 + 4) + uVar1 * 2;
}



// ============================================================
// Function: crypto_flattenString (FUN_6814cf30)
// Address: 6814cf30
// Size: 74 bytes
// Params: uint * param_1
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crypto_flattenString(uint *param_1)

{
  uint uVar1;
  byte *pbVar2;
  
  if (((*param_1 & 0x40000000) != 0) && (uVar1 = crypto_normalizeString(0,param_1), uVar1 == 0)) {
    return 0;
  }
  pbVar2 = (byte *)js_getAtomSize((uint)param_1);
  *pbVar2 = *pbVar2 & 0xfd;
  return param_1[1];
}



// ============================================================
// Function: crypto_concatStrings (FUN_6814cf80)
// Address: 6814cf80
// Size: 790 bytes
// Params: int param_1, uint * param_2, uint * param_3
// Return: uint *
// Calling convention: __stdcall
// ============================================================

uint * crypto_concatStrings(int param_1,uint *param_2,uint *param_3)

{
  byte *pbVar1;
  uint *puVar2;
  uint uVar3;
  void *local_40;
  uint local_3c;
  void *local_38;
  uint local_34;
  uint local_30;
  void *local_2c;
  uint *local_28;
  void *local_1c;
  uint local_18;
  uint local_14;
  void *local_10;
  void *local_c;
  
  if ((*param_3 & 0x40000000) == 0) {
    local_18 = *param_3;
    local_10 = (void *)param_3[1];
  }
  else {
    local_18 = (-(uint)((*param_3 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_3;
    if ((*(uint *)param_3[1] & 0x40000000) == 0) {
      if ((*param_3 & 0x80000000) == 0) {
        local_30 = *param_3 >> 0xf & 0x7fff;
      }
      else {
        local_30 = 0;
      }
      local_2c = (void *)(*(int *)(param_3[1] + 4) + local_30 * 2);
    }
    else {
      local_2c = (void *)crypto_getStringLen(param_3);
    }
    local_10 = local_2c;
  }
  if (local_18 == 0) {
    return param_2;
  }
  if (((*param_2 & 0x40000000) == 0) &&
     (pbVar1 = (byte *)js_getAtomSize((uint)param_2), (*pbVar1 & 2) != 0)) {
    local_14 = *param_2;
    if (local_14 == 0) {
      return param_3;
    }
    uVar3 = param_2[1];
    local_1c = (void *)xtra_allocJSString(param_1,uVar3,(local_14 + local_18) * 2 + 2);
    if (local_1c == (void *)0x0) {
      return (uint *)0x0;
    }
    uVar3 = (int)((int)local_10 - uVar3) >> 1;
    if (uVar3 < local_14) {
      local_10 = (void *)((int)local_1c + uVar3 * 2);
    }
    param_2[1] = (uint)local_1c;
    local_28 = param_2;
    local_c = local_1c;
  }
  else {
    if ((*param_2 & 0x40000000) == 0) {
      local_34 = *param_2;
    }
    else {
      local_34 = (-(uint)((*param_2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_2;
    }
    local_14 = local_34;
    if (local_34 == 0) {
      return param_3;
    }
    if ((local_34 == 1) && (*(short *)param_2[1] == 0)) {
      return param_3;
    }
    if ((*param_2 & 0x40000000) == 0) {
      local_40 = (void *)param_2[1];
    }
    else {
      if ((*(uint *)param_2[1] & 0x40000000) == 0) {
        if ((*param_2 & 0x80000000) == 0) {
          local_3c = *param_2 >> 0xf & 0x7fff;
        }
        else {
          local_3c = 0;
        }
        local_38 = (void *)(*(int *)(param_2[1] + 4) + local_3c * 2);
      }
      else {
        local_38 = (void *)crypto_getStringLen(param_2);
      }
      local_40 = local_38;
    }
    local_1c = local_40;
    local_c = (void *)xtra_getPropertyById(param_1,(local_34 + local_18) * 2 + 2);
    if (local_c == (void *)0x0) {
      return (uint *)0x0;
    }
    memcpy(local_c,local_40,local_34 << 1);
    local_28 = (uint *)0x0;
  }
  memcpy((void *)((int)local_c + local_14 * 2),local_10,local_18 << 1);
  *(undefined2 *)((int)local_c + (local_14 + local_18) * 2) = 0;
  puVar2 = certs_allocHashEntry(param_1,(uint)local_c,local_14 + local_18,2);
  if (puVar2 == (uint *)0x0) {
    if (local_28 == (uint *)0x0) {
      xtra_checkAndFlush(param_1,(int)local_c);
    }
    else {
      uVar3 = xtra_allocJSString(param_1,(int)local_1c,local_14 * 2 + 2);
      if (uVar3 != 0) {
        param_2[1] = uVar3;
      }
    }
  }
  else if (local_28 != (uint *)0x0) {
    *local_28 = local_14 | 0xc0000000;
    local_28[1] = (uint)puVar2;
  }
  return puVar2;
}



// ============================================================
// Function: crypto_normalizeString (FUN_6814d2a0)
// Address: 6814d2a0
// Size: 269 bytes
// Params: int param_1, uint * param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crypto_normalizeString(int param_1,uint *param_2)

{
  uint uVar1;
  uint local_1c;
  void *local_18;
  void *local_14;
  
  if ((*param_2 & 0x40000000) != 0) {
    uVar1 = (-(uint)((*param_2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_2;
    if (param_1 == 0) {
      local_14 = (void *)js_runGC();
    }
    else {
      local_14 = (void *)xtra_getPropertyById(param_1,uVar1 * 2 + 2);
    }
    if (local_14 == (void *)0x0) {
      return 0;
    }
    if ((*(uint *)param_2[1] & 0x40000000) == 0) {
      if ((*param_2 & 0x80000000) == 0) {
        local_1c = *param_2 >> 0xf & 0x7fff;
      }
      else {
        local_1c = 0;
      }
      local_18 = (void *)(*(int *)(param_2[1] + 4) + local_1c * 2);
    }
    else {
      local_18 = (void *)crypto_getStringLen(param_2);
    }
    memcpy(local_14,local_18,uVar1 << 1);
    *(undefined2 *)((int)local_14 + uVar1 * 2) = 0;
    *param_2 = uVar1;
    param_2[1] = (uint)local_14;
  }
  return param_2[1];
}



// ============================================================
// Function: crypto_encodeUri (FUN_6814d3b0)
// Address: 6814d3b0
// Size: 1157 bytes
// Params: ushort * param_1, undefined4 param_2, uint param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_encodeUri(ushort *param_1,undefined4 param_2,uint param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  undefined4 extraout_EDX;
  ulonglong uVar2;
  uint local_60;
  uint local_5c;
  uint local_58;
  uint local_54;
  undefined1 local_50 [12];
  uint *local_44;
  int local_40;
  uint local_3c;
  ushort local_38;
  undefined4 local_34;
  uint uStack_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  char local_20 [16];
  uint local_10;
  uint local_c;
  uint local_8;
  
  builtin_strncpy(local_20,"0123456789ABCDEF",0x10);
  local_24 = 7;
  if (param_3 < 2) {
LAB_6814d49a:
    local_44 = (uint *)certs_hashLookup((int)param_1,*param_4);
    if (local_44 != (uint *)0x0) {
      *param_4 = (uint)local_44 | 4;
      if ((*local_44 & 0x40000000) == 0) {
        local_5c = local_44[1];
      }
      else {
        if ((*(uint *)local_44[1] & 0x40000000) == 0) {
          if ((*local_44 & 0x80000000) == 0) {
            local_58 = *local_44 >> 0xf & 0x7fff;
          }
          else {
            local_58 = 0;
          }
          local_54 = *(int *)(local_44[1] + 4) + local_58 * 2;
        }
        else {
          local_54 = crypto_getStringLen(local_44);
        }
        local_5c = local_54;
      }
      local_3c = local_5c;
      if ((*local_44 & 0x40000000) == 0) {
        local_60 = *local_44;
      }
      else {
        local_60 = (-(uint)((*local_44 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_44;
      }
      local_28 = local_60;
      local_8 = local_60;
      for (local_c = 0; local_c < local_60; local_c = local_c + 1) {
        local_38 = *(ushort *)(local_5c + local_c * 2);
        if ((0x7f < local_38) || (((byte)(&DAT_6817fe18)[(byte)local_38] & local_24) == 0)) {
          if (local_38 < 0x100) {
            if ((local_24 != 2) || (local_38 != 0x20)) {
              local_28 = local_28 + 2;
            }
          }
          else {
            local_28 = local_28 + 5;
          }
        }
      }
      local_2c = xtra_getPropertyById((int)param_1,local_28 * 2 + 2);
      if (local_2c != 0) {
        local_40 = 0;
        for (local_c = 0; local_c < local_8; local_c = local_c + 1) {
          local_38 = *(ushort *)(local_3c + local_c * 2);
          if ((local_38 < 0x80) && (((byte)(&DAT_6817fe18)[(byte)local_38] & local_24) != 0)) {
            *(ushort *)(local_2c + local_40 * 2) = local_38;
            local_40 = local_40 + 1;
          }
          else if (local_38 < 0x100) {
            if ((local_24 == 2) && (local_38 == 0x20)) {
              *(undefined2 *)(local_2c + local_40 * 2) = 0x2b;
              local_40 = local_40 + 1;
            }
            else {
              *(undefined2 *)(local_2c + local_40 * 2) = 0x25;
              *(short *)(local_2c + (local_40 + 1) * 2) = (short)local_20[(int)(uint)local_38 >> 4];
              *(short *)(local_2c + (local_40 + 2) * 2) = (short)local_20[local_38 & 0xf];
              local_40 = local_40 + 3;
            }
          }
          else {
            *(undefined2 *)(local_2c + local_40 * 2) = 0x25;
            *(undefined2 *)(local_2c + (local_40 + 1) * 2) = 0x75;
            *(short *)(local_2c + (local_40 + 2) * 2) = (short)local_20[(int)(uint)local_38 >> 0xc];
            *(short *)(local_2c + (local_40 + 3) * 2) =
                 (short)local_20[(int)(local_38 & 0xf00) >> 8];
            *(short *)(local_2c + (local_40 + 4) * 2) = (short)local_20[(int)(local_38 & 0xf0) >> 4]
            ;
            *(short *)(local_2c + (local_40 + 5) * 2) = (short)local_20[local_38 & 0xf];
            local_40 = local_40 + 6;
          }
        }
        *(undefined2 *)(local_2c + local_28 * 2) = 0;
        local_44 = certs_allocHashEntry((int)param_1,local_2c,local_28,0);
        if (local_44 == (uint *)0x0) {
          xtra_checkAndFlush(param_1,local_2c);
        }
        else {
          *param_5 = (uint)local_44 | 4;
        }
      }
    }
  }
  else {
    iVar1 = runtime_parseNumber(param_1,param_4[1],(double *)&local_34);
    if (iVar1 == 0) goto LAB_6814d825;
    if ((uStack_30 & 0x7ff00000) != 0x7ff00000) {
      uVar2 = strings_floatToUint64(uStack_30 & 0x7ff00000,extraout_EDX);
      local_24 = (uint)uVar2;
      if (((double)CONCAT44(uStack_30,local_34) == (double)(int)local_24) &&
         ((uVar2 & 0xfffffff8) == 0)) goto LAB_6814d49a;
    }
    runtime_snprintf(local_50,0xc,"%lx");
    xtra_invokeMethod((uint)param_1,xtra_getErrorString,0,0x3d);
  }
LAB_6814d825:
  return 0;
}



// ============================================================
// Function: crypto_decodeUri (FUN_6814d840)
// Address: 6814d840
// Size: 1267 bytes
// Params: int param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
crypto_decodeUri(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  short local_48;
  short local_44;
  short local_40;
  int local_3c;
  short local_38;
  int local_34;
  uint local_30;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_1c;
  short local_14;
  uint local_c;
  
  puVar1 = (uint *)certs_hashLookup(param_1,*param_4);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    *param_4 = (uint)puVar1 | 4;
    if ((*puVar1 & 0x40000000) == 0) {
      local_2c = puVar1[1];
    }
    else {
      if ((*(uint *)puVar1[1] & 0x40000000) == 0) {
        if ((*puVar1 & 0x80000000) == 0) {
          local_28 = *puVar1 >> 0xf & 0x7fff;
        }
        else {
          local_28 = 0;
        }
        local_24 = *(int *)(puVar1[1] + 4) + local_28 * 2;
      }
      else {
        local_24 = crypto_getStringLen(puVar1);
      }
      local_2c = local_24;
    }
    if ((*puVar1 & 0x40000000) == 0) {
      local_30 = *puVar1;
    }
    else {
      local_30 = (-(uint)((*puVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar1;
    }
    uVar3 = xtra_getPropertyById(param_1,local_30 * 2 + 2);
    if (uVar3 == 0) {
      uVar2 = 0;
    }
    else {
      local_c = 0;
      local_1c = 0;
      while (local_c < local_30) {
        local_14 = *(short *)(local_2c + local_c * 2);
        uVar5 = local_c + 1;
        if (local_14 == 0x25) {
          if ((local_c + 2 < local_30) && (*(ushort *)(local_2c + uVar5 * 2) < 0x80)) {
            iVar4 = isxdigit((uint)*(ushort *)(local_2c + uVar5 * 2));
            if ((iVar4 != 0) && (*(ushort *)(local_2c + 2 + uVar5 * 2) < 0x80)) {
              iVar4 = isxdigit((uint)*(ushort *)(local_2c + 2 + uVar5 * 2));
              if (iVar4 != 0) {
                iVar4 = isdigit((uint)*(ushort *)(local_2c + uVar5 * 2));
                if (iVar4 == 0) {
                  local_34 = tolower((uint)*(ushort *)(local_2c + uVar5 * 2));
                  local_34 = local_34 + -0x57;
                }
                else {
                  local_34 = *(ushort *)(local_2c + uVar5 * 2) - 0x30;
                }
                iVar4 = isdigit((uint)*(ushort *)(local_2c + 2 + uVar5 * 2));
                if (iVar4 == 0) {
                  iVar4 = tolower((uint)*(ushort *)(local_2c + 2 + uVar5 * 2));
                  local_38 = (short)iVar4 + -0x57;
                }
                else {
                  local_38 = *(short *)(local_2c + 2 + uVar5 * 2) + -0x30;
                }
                local_14 = (short)(local_34 << 4) + local_38;
                uVar5 = local_c + 3;
                goto LAB_6814dcc8;
              }
            }
          }
          if (((local_c + 5 < local_30) && (*(short *)(local_2c + uVar5 * 2) == 0x75)) &&
             (*(ushort *)(local_2c + 2 + uVar5 * 2) < 0x80)) {
            iVar4 = isxdigit((uint)*(ushort *)(local_2c + 2 + uVar5 * 2));
            if ((iVar4 != 0) && (*(ushort *)(local_2c + 4 + uVar5 * 2) < 0x80)) {
              iVar4 = isxdigit((uint)*(ushort *)(local_2c + 4 + uVar5 * 2));
              if ((iVar4 != 0) && (*(ushort *)(local_2c + 6 + uVar5 * 2) < 0x80)) {
                iVar4 = isxdigit((uint)*(ushort *)(local_2c + 6 + uVar5 * 2));
                if ((iVar4 != 0) && (*(ushort *)(local_2c + 8 + uVar5 * 2) < 0x80)) {
                  iVar4 = isxdigit((uint)*(ushort *)(local_2c + 8 + uVar5 * 2));
                  if (iVar4 != 0) {
                    iVar4 = isdigit((uint)*(ushort *)(local_2c + 2 + uVar5 * 2));
                    if (iVar4 == 0) {
                      local_3c = tolower((uint)*(ushort *)(local_2c + 2 + uVar5 * 2));
                      local_3c = local_3c + -0x57;
                    }
                    else {
                      local_3c = *(ushort *)(local_2c + 2 + uVar5 * 2) - 0x30;
                    }
                    iVar4 = isdigit((uint)*(ushort *)(local_2c + 4 + uVar5 * 2));
                    if (iVar4 == 0) {
                      iVar4 = tolower((uint)*(ushort *)(local_2c + 4 + uVar5 * 2));
                      local_40 = (short)iVar4 + -0x57;
                    }
                    else {
                      local_40 = *(short *)(local_2c + 4 + uVar5 * 2) + -0x30;
                    }
                    iVar4 = isdigit((uint)*(ushort *)(local_2c + 6 + uVar5 * 2));
                    if (iVar4 == 0) {
                      iVar4 = tolower((uint)*(ushort *)(local_2c + 6 + uVar5 * 2));
                      local_44 = (short)iVar4 + -0x57;
                    }
                    else {
                      local_44 = *(short *)(local_2c + 6 + uVar5 * 2) + -0x30;
                    }
                    iVar4 = isdigit((uint)*(ushort *)(local_2c + 8 + uVar5 * 2));
                    if (iVar4 == 0) {
                      iVar4 = tolower((uint)*(ushort *)(local_2c + 8 + uVar5 * 2));
                      local_48 = (short)iVar4 + -0x57;
                    }
                    else {
                      local_48 = *(short *)(local_2c + 8 + uVar5 * 2) + -0x30;
                    }
                    local_14 = (((short)(local_3c << 4) + local_40) * 0x10 + local_44) * 0x10 +
                               local_48;
                    uVar5 = local_c + 6;
                  }
                }
              }
            }
          }
        }
LAB_6814dcc8:
        local_c = uVar5;
        *(short *)(uVar3 + local_1c * 2) = local_14;
        local_1c = local_1c + 1;
      }
      *(undefined2 *)(uVar3 + local_1c * 2) = 0;
      puVar1 = certs_allocHashEntry(param_1,uVar3,local_1c,0);
      if (puVar1 == (uint *)0x0) {
        xtra_checkAndFlush(param_1,uVar3);
        uVar2 = 0;
      }
      else {
        *param_5 = (uint)puVar1 | 4;
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



// ============================================================
// Function: crypto_toLowerCaseSimple (FUN_6814dd40)
// Address: 6814dd40
// Size: 54 bytes
// Params: uint * param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool crypto_toLowerCaseSimple(uint *param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  
  puVar1 = certs_resizeString(param_1,*param_4);
  if (puVar1 != (uint *)0x0) {
    *param_5 = (uint)puVar1 | 4;
  }
  return puVar1 != (uint *)0x0;
}



// ============================================================
// Function: crypto_getStringLenValue (FUN_6814dd80)
// Address: 6814dd80
// Size: 152 bytes
// Params: int param_1, uint param_2, uint param_3, uint * param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_getStringLenValue(int param_1,uint param_2,uint param_3,uint *param_4)

{
  undefined4 uVar1;
  uint *puVar2;
  undefined4 local_10;
  
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    uVar1 = 1;
  }
  else {
    puVar2 = (uint *)certs_hashLookup(param_1,param_2);
    if (puVar2 == (uint *)0x0) {
      uVar1 = 0;
    }
    else {
      if ((int)param_3 >> 1 == -1) {
        if ((*puVar2 & 0x40000000) == 0) {
          local_10 = *puVar2;
        }
        else {
          local_10 = (-(uint)((*puVar2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar2;
        }
        *param_4 = local_10 << 1 | 1;
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}



// ============================================================
// Function: crypto_splitStringChars (FUN_6814de20)
// Address: 6814de20
// Size: 224 bytes
// Params: int param_1, int * param_2
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_splitStringChars(int param_1,int *param_2)

{
  uint *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  int iVar4;
  uint local_18;
  uint local_c;
  
  puVar1 = (uint *)certs_hashLookup(param_1,(uint)param_2);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    if ((*puVar1 & 0x40000000) == 0) {
      local_18 = *puVar1;
    }
    else {
      local_18 = (-(uint)((*puVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar1;
    }
    for (local_c = 0; local_c < local_18; local_c = local_c + 1) {
      puVar3 = certs_concatStrings(param_1,puVar1,local_c,1,0);
      if (puVar3 == (uint *)0x0) {
        return 0;
      }
      iVar4 = (**(code **)(*(int *)(*param_2 + 4) + 0xc))
                        (param_1,param_2,local_c << 1 | 1,(uint)puVar3 | 4,0,0,7,0);
      if (iVar4 == 0) {
        return 0;
      }
    }
    uVar2 = 1;
  }
  return uVar2;
}



// ============================================================
// Function: crypto_getCharAt (FUN_6814df00)
// Address: 6814df00
// Size: 234 bytes
// Params: int param_1, int * param_2, uint param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_getCharAt(int param_1,int *param_2,uint param_3)

{
  undefined4 uVar1;
  uint *puVar2;
  uint uVar3;
  int iVar4;
  uint local_14;
  
  if (((param_3 & 1) == 0) || (param_3 == 0x80000001)) {
    uVar1 = 1;
  }
  else {
    puVar2 = (uint *)certs_hashLookup(param_1,(uint)param_2);
    if (puVar2 == (uint *)0x0) {
      uVar1 = 0;
    }
    else {
      uVar3 = (int)param_3 >> 1;
      if ((*puVar2 & 0x40000000) == 0) {
        local_14 = *puVar2;
      }
      else {
        local_14 = (-(uint)((*puVar2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar2;
      }
      if (uVar3 < local_14) {
        puVar2 = certs_concatStrings(param_1,puVar2,uVar3,1,0);
        if (puVar2 == (uint *)0x0) {
          return 0;
        }
        iVar4 = (**(code **)(*(int *)(*param_2 + 4) + 0xc))
                          (param_1,param_2,uVar3 << 1 | 1,(uint)puVar2 | 4,0,0,7,0);
        if (iVar4 == 0) {
          return 0;
        }
      }
      uVar1 = 1;
    }
  }
  return uVar1;
}



// ============================================================
// Function: crypto_toQuotedString (FUN_6814dff0)
// Address: 6814dff0
// Size: 80 bytes
// Params: uint * param_1, uint param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
crypto_toQuotedString(uint *param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  uint *puVar3;
  
  uVar1 = certs_hashLookup((int)param_1,param_2);
  if (uVar1 == 0) {
    uVar2 = 0;
  }
  else {
    puVar3 = crypto_createUnaryOp(param_1,uVar1,0x22);
    if (puVar3 == (uint *)0x0) {
      uVar2 = 0;
    }
    else {
      *param_5 = (uint)puVar3 | 4;
      uVar2 = 1;
    }
  }
  return uVar2;
}



// ============================================================
// Function: crypto_wrapStringConstructor (FUN_6814e040)
// Address: 6814e040
// Size: 640 bytes
// Params: uint * param_1, int * param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_wrapStringConstructor(uint *param_1,int *param_2,undefined4 param_3,uint *param_4,uint *param_5)
{
  int iVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_34;
  char local_28 [16];
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  iVar1 = xtra_callMethod(param_1,(int)param_2,&PTR_s_String_68194920,(int)param_4);
  if (iVar1 != 0) {
    local_8 = *(uint *)(param_2[1] + 0xc);
    if ((local_8 & 7) == 4) {
      puVar2 = crypto_createUnaryOp(param_1,local_8 & 0xfffffff8,0x22);
      if (puVar2 != (uint *)0x0) {
        uVar3 = runtime_snprintf(local_28,0x10,"(new %s(");
        if ((*puVar2 & 0x40000000) == 0) {
          local_44 = puVar2[1];
        }
        else {
          if ((*(uint *)puVar2[1] & 0x40000000) == 0) {
            if ((*puVar2 & 0x80000000) == 0) {
              local_40 = *puVar2 >> 0xf & 0x7fff;
            }
            else {
              local_40 = 0;
            }
            local_3c = *(int *)(puVar2[1] + 4) + local_40 * 2;
          }
          else {
            local_3c = crypto_getStringLen(puVar2);
          }
          local_44 = local_3c;
        }
        local_14 = local_44;
        if ((*puVar2 & 0x40000000) == 0) {
          local_48 = *puVar2;
        }
        else {
          local_48 = (-(uint)((*puVar2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar2;
        }
        local_c = uVar3 + 2 + local_48;
        uVar4 = xtra_getPropertyById((int)param_1,local_c * 2 + 2);
        if (uVar4 != 0) {
          for (local_10 = 0; local_10 < uVar3; local_10 = local_10 + 1) {
            *(short *)(uVar4 + local_10 * 2) = (short)local_28[local_10];
          }
          for (local_34 = 0; local_34 < local_48; local_34 = local_34 + 1) {
            *(undefined2 *)(uVar4 + local_10 * 2) = *(undefined2 *)(local_14 + local_34 * 2);
            local_10 = local_10 + 1;
          }
          *(undefined2 *)(uVar4 + local_10 * 2) = 0x29;
          *(undefined2 *)(uVar4 + (local_10 + 1) * 2) = 0x29;
          local_10 = local_10 + 2;
          *(undefined2 *)(uVar4 + local_10 * 2) = 0;
          puVar2 = certs_allocHashEntry((int)param_1,uVar4,local_c,0);
          if (puVar2 == (uint *)0x0) {
            xtra_checkAndFlush(param_1,uVar4);
          }
          else {
            *param_5 = (uint)puVar2 | 4;
          }
        }
      }
    }
    else {
      runtime_setPropertyVtable(param_1,param_2,param_3,param_4,param_5);
    }
  }
  return 0;
}



// ============================================================
// Function: crypto_convertToString (FUN_6814e2c0)
// Address: 6814e2c0
// Size: 103 bytes
// Params: uint * param_1, int * param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int crypto_convertToString(uint *param_1,int *param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  
  iVar1 = xtra_callMethod(param_1,(int)param_2,&PTR_s_String_68194920,(int)param_4);
  if (iVar1 == 0) {
    iVar1 = 0;
  }
  else if ((*(uint *)(param_2[1] + 0xc) & 7) == 4) {
    *param_5 = *(uint *)(param_2[1] + 0xc);
    iVar1 = 1;
  }
  else {
    iVar1 = runtime_setPropertyVtableEx(param_1,param_2,param_3,param_4,param_5);
  }
  return iVar1;
}



// ============================================================
// Function: crypto_getStringValueOf (FUN_6814e330)
// Address: 6814e330
// Size: 56 bytes
// Params: undefined4 param_1, int param_2, undefined4 param_3, int param_4, undefined4 * param_5
// Return: bool
// Calling convention: __stdcall
// ============================================================

bool crypto_getStringValueOf(undefined4 param_1,int param_2,undefined4 param_3,int param_4,undefined4 *param_5)

{
  int iVar1;
  
  iVar1 = xtra_callMethod(param_1,param_2,&PTR_s_String_68194920,param_4);
  if (iVar1 != 0) {
    *param_5 = *(undefined4 *)(*(int *)(param_2 + 4) + 0xc);
  }
  return iVar1 != 0;
}



// ============================================================
// Function: crypto_substringByRange (FUN_6814e370)
// Address: 6814e370
// Size: 484 bytes
// Params: ushort * param_1, uint param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_substringByRange(ushort *param_1,uint param_2,int param_3,uint *param_4,uint *param_5)

{
  double dVar1;
  int iVar2;
  float10 fVar3;
  uint local_60;
  uint local_50;
  uint local_38;
  uint *local_28;
  double local_24;
  double local_1c;
  double local_14;
  double local_c;
  
  local_28 = (uint *)certs_hashLookup((int)param_1,param_2);
  if (local_28 == (uint *)0x0) {
    return 0;
  }
  param_4[-1] = (uint)local_28 | 4;
  if (param_3 != 0) {
    iVar2 = runtime_parseNumber(param_1,*param_4,&local_24);
    if (iVar2 == 0) {
      return 0;
    }
    if ((*local_28 & 0x40000000) == 0) {
      local_38 = *local_28;
    }
    else {
      local_38 = (-(uint)((*local_28 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_28;
    }
    local_14 = (double)local_38;
    fVar3 = runtime_powFloat(SUB84(local_24,0),(uint)((ulonglong)local_24 >> 0x20));
    local_c = (double)fVar3;
    if (0.0 <= local_c) {
      if (local_14 < local_c) {
        local_c = local_14;
      }
    }
    else {
      local_c = 0.0;
    }
    if (param_3 == 1) {
      local_1c = local_14;
    }
    else {
      iVar2 = runtime_parseNumber(param_1,param_4[1],&local_24);
      if (iVar2 == 0) {
        return 0;
      }
      fVar3 = runtime_powFloat(SUB84(local_24,0),(uint)((ulonglong)local_24 >> 0x20));
      dVar1 = local_c;
      local_1c = (double)fVar3;
      if (0.0 <= local_1c) {
        if (local_14 < local_1c) {
          local_1c = local_14;
        }
      }
      else {
        local_1c = 0.0;
      }
      if (local_1c < local_c) {
        if (*(int *)(param_1 + 6) == 0x78) {
          local_1c = local_c;
        }
        else {
          local_c = local_1c;
          local_1c = dVar1;
        }
      }
    }
    local_50 = (uint)(longlong)ROUND(local_1c - local_c);
    local_60 = (uint)(longlong)ROUND(local_c);
    local_28 = certs_concatStrings((int)param_1,local_28,local_60,local_50,0);
    if (local_28 == (uint *)0x0) {
      return 0;
    }
  }
  *param_5 = (uint)local_28 | 4;
  return 1;
}



// ============================================================
// Function: crypto_toUpperCase (FUN_6814e560)
// Address: 6814e560
// Size: 449 bytes
// Params: int param_1, uint param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
crypto_toUpperCase(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  short local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_c;
  
  puVar1 = (uint *)certs_hashLookup(param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    if ((*puVar1 & 0x40000000) == 0) {
      local_1c = *puVar1;
    }
    else {
      local_1c = (-(uint)((*puVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar1;
    }
    uVar3 = xtra_getPropertyById(param_1,local_1c * 2 + 2);
    if (uVar3 == 0) {
      uVar2 = 0;
    }
    else {
      if ((*puVar1 & 0x40000000) == 0) {
        local_28 = puVar1[1];
      }
      else {
        if ((*(uint *)puVar1[1] & 0x40000000) == 0) {
          if ((*puVar1 & 0x80000000) == 0) {
            local_24 = *puVar1 >> 0xf & 0x7fff;
          }
          else {
            local_24 = 0;
          }
          local_20 = *(int *)(puVar1[1] + 4) + local_24 * 2;
        }
        else {
          local_20 = crypto_getStringLen(puVar1);
        }
        local_28 = local_20;
      }
      for (local_c = 0; local_c < local_1c; local_c = local_c + 1) {
        uVar4 = crypto_allocString((uint)*(ushort *)(local_28 + local_c * 2));
        if ((uVar4 & 0x200000) == 0) {
          local_2c = *(short *)(local_28 + local_c * 2);
        }
        else {
          local_2c = *(short *)(local_28 + local_c * 2);
          uVar2 = crypto_allocString((uint)*(ushort *)(local_28 + local_c * 2));
          local_2c = local_2c + (short)((int)uVar2 >> 0x16);
        }
        *(short *)(uVar3 + local_c * 2) = local_2c;
      }
      *(undefined2 *)(uVar3 + local_1c * 2) = 0;
      puVar1 = certs_allocHashEntry(param_1,uVar3,local_1c,0);
      if (puVar1 == (uint *)0x0) {
        xtra_checkAndFlush(param_1,uVar3);
        uVar2 = 0;
      }
      else {
        *param_5 = (uint)puVar1 | 4;
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



// ============================================================
// Function: crypto_toUpperCaseLocale (FUN_6814e730)
// Address: 6814e730
// Size: 114 bytes
// Params: int param_1, uint param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
crypto_toUpperCaseLocale(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x168) == 0) || (*(int *)(*(int *)(param_1 + 0x168) + 4) == 0)) {
    uVar2 = crypto_toUpperCase(param_1,param_2,0,param_4,param_5);
  }
  else {
    uVar1 = certs_hashLookup(param_1,param_2);
    if (uVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (**(code **)(*(int *)(param_1 + 0x168) + 4))(param_1,uVar1,param_5);
    }
  }
  return uVar2;
}



// ============================================================
// Function: crypto_toLowerCase (FUN_6814e7b0)
// Address: 6814e7b0
// Size: 449 bytes
// Params: int param_1, uint param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
crypto_toLowerCase(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  short local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  uint local_c;
  
  puVar1 = (uint *)certs_hashLookup(param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    if ((*puVar1 & 0x40000000) == 0) {
      local_1c = *puVar1;
    }
    else {
      local_1c = (-(uint)((*puVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar1;
    }
    uVar3 = xtra_getPropertyById(param_1,local_1c * 2 + 2);
    if (uVar3 == 0) {
      uVar2 = 0;
    }
    else {
      if ((*puVar1 & 0x40000000) == 0) {
        local_28 = puVar1[1];
      }
      else {
        if ((*(uint *)puVar1[1] & 0x40000000) == 0) {
          if ((*puVar1 & 0x80000000) == 0) {
            local_24 = *puVar1 >> 0xf & 0x7fff;
          }
          else {
            local_24 = 0;
          }
          local_20 = *(int *)(puVar1[1] + 4) + local_24 * 2;
        }
        else {
          local_20 = crypto_getStringLen(puVar1);
        }
        local_28 = local_20;
      }
      for (local_c = 0; local_c < local_1c; local_c = local_c + 1) {
        uVar4 = crypto_allocString((uint)*(ushort *)(local_28 + local_c * 2));
        if ((uVar4 & 0x100000) == 0) {
          local_2c = *(short *)(local_28 + local_c * 2);
        }
        else {
          local_2c = *(short *)(local_28 + local_c * 2);
          uVar2 = crypto_allocString((uint)*(ushort *)(local_28 + local_c * 2));
          local_2c = local_2c - (short)((int)uVar2 >> 0x16);
        }
        *(short *)(uVar3 + local_c * 2) = local_2c;
      }
      *(undefined2 *)(uVar3 + local_1c * 2) = 0;
      puVar1 = certs_allocHashEntry(param_1,uVar3,local_1c,0);
      if (puVar1 == (uint *)0x0) {
        xtra_checkAndFlush(param_1,uVar3);
        uVar2 = 0;
      }
      else {
        *param_5 = (uint)puVar1 | 4;
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



// ============================================================
// Function: crypto_toLowerCaseLocale (FUN_6814e980)
// Address: 6814e980
// Size: 112 bytes
// Params: int param_1, uint param_2, undefined4 param_3, undefined4 param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
crypto_toLowerCaseLocale(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  uint uVar1;
  undefined4 uVar2;
  
  if ((*(int *)(param_1 + 0x168) == 0) || (**(int **)(param_1 + 0x168) == 0)) {
    uVar2 = crypto_toLowerCase(param_1,param_2,0,param_4,param_5);
  }
  else {
    uVar1 = certs_hashLookup(param_1,param_2);
    if (uVar1 == 0) {
      uVar2 = 0;
    }
    else {
      uVar2 = (*(code *)**(undefined4 **)(param_1 + 0x168))(param_1,uVar1,param_5);
    }
  }
  return uVar2;
}



// ============================================================
// Function: crypto_localeCompare (FUN_6814e9f0)
// Address: 6814e9f0
// Size: 185 bytes
// Params: int param_1, uint param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_localeCompare(int param_1,uint param_2,int param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  uint *puVar2;
  undefined4 uVar3;
  int iVar4;
  
  puVar1 = (uint *)certs_hashLookup(param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    return 0;
  }
  param_4[-1] = (uint)puVar1 | 4;
  if (param_3 == 0) {
    *param_5 = 1;
  }
  else {
    puVar2 = (uint *)certs_hashLookup(param_1,*param_4);
    if (puVar2 == (uint *)0x0) {
      return 0;
    }
    if ((*(int *)(param_1 + 0x168) != 0) && (*(int *)(*(int *)(param_1 + 0x168) + 8) != 0)) {
      uVar3 = (**(code **)(*(int *)(param_1 + 0x168) + 8))(param_1,puVar1,puVar2,param_5);
      return uVar3;
    }
    iVar4 = certs_compareStrings(puVar1,puVar2);
    *param_5 = iVar4 << 1 | 1;
  }
  return 1;
}



// ============================================================
// Function: crypto_charAt (FUN_6814eab0)
// Address: 6814eab0
// Size: 307 bytes
// Params: ushort * param_1, uint param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_charAt(ushort *param_1,uint param_2,int param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  float10 fVar4;
  uint local_34;
  uint local_1c;
  double local_14;
  uint local_8;
  
  puVar1 = (uint *)certs_hashLookup((int)param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    return 0;
  }
  param_4[-1] = (uint)puVar1 | 4;
  if (param_3 == 0) {
    local_14 = 0.0;
  }
  else {
    iVar2 = runtime_parseNumber(param_1,*param_4,&local_14);
    if (iVar2 == 0) {
      return 0;
    }
    fVar4 = runtime_powFloat(SUB84(local_14,0),(uint)((ulonglong)local_14 >> 0x20));
    local_14 = (double)fVar4;
  }
  if (0.0 <= local_14) {
    if ((*puVar1 & 0x40000000) == 0) {
      local_1c = *puVar1;
    }
    else {
      local_1c = (-(uint)((*puVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar1;
    }
    if ((double)local_1c < local_14 == ((double)local_1c == local_14)) {
      local_34 = (uint)(longlong)ROUND(local_14);
      local_8 = local_34;
      puVar1 = certs_concatStrings((int)param_1,puVar1,local_34,1,0);
      if (puVar1 != (uint *)0x0) {
        *param_5 = (uint)puVar1 | 4;
        return 1;
      }
      return 0;
    }
  }
  uVar3 = xtraRuntime_getCapabilitiesHi((int)param_1);
  *param_5 = uVar3;
  return 1;
}



// ============================================================
// Function: crypto_charCodeAt (FUN_6814ebf0)
// Address: 6814ebf0
// Size: 402 bytes
// Params: ushort * param_1, uint param_2, int param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_charCodeAt(ushort *param_1,uint param_2,int param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  int iVar2;
  uint uVar3;
  float10 fVar4;
  uint local_40;
  uint local_3c;
  uint local_38;
  int local_34;
  uint local_1c;
  double local_14;
  int local_8;
  
  puVar1 = (uint *)certs_hashLookup((int)param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    return 0;
  }
  param_4[-1] = (uint)puVar1 | 4;
  if (param_3 == 0) {
    local_14 = 0.0;
  }
  else {
    iVar2 = runtime_parseNumber(param_1,*param_4,&local_14);
    if (iVar2 == 0) {
      return 0;
    }
    fVar4 = runtime_powFloat(SUB84(local_14,0),(uint)((ulonglong)local_14 >> 0x20));
    local_14 = (double)fVar4;
  }
  if (0.0 <= local_14) {
    if ((*puVar1 & 0x40000000) == 0) {
      local_1c = *puVar1;
    }
    else {
      local_1c = (-(uint)((*puVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar1;
    }
    if ((double)local_1c < local_14 == ((double)local_1c == local_14)) {
      local_34 = (int)(longlong)ROUND(local_14);
      local_8 = local_34;
      if ((*puVar1 & 0x40000000) == 0) {
        local_40 = puVar1[1];
      }
      else {
        if ((*(uint *)puVar1[1] & 0x40000000) == 0) {
          if ((*puVar1 & 0x80000000) == 0) {
            local_3c = *puVar1 >> 0xf & 0x7fff;
          }
          else {
            local_3c = 0;
          }
          local_38 = *(int *)(puVar1[1] + 4) + local_3c * 2;
        }
        else {
          local_38 = crypto_getStringLen(puVar1);
        }
        local_40 = local_38;
      }
      *param_5 = (uint)*(ushort *)(local_40 + local_8 * 2) << 1 | 1;
      return 1;
    }
  }
  uVar3 = xtraRuntime_getCapabilitiesLo((int)param_1);
  *param_5 = uVar3;
  return 1;
}



// ============================================================
// Function: crypto_boyerMooreSearch (FUN_6814ed90)
// Address: 6814ed90
// Size: 400 bytes
// Params: int param_1, int param_2, int param_3, uint param_4, int param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_boyerMooreSearch(int param_1,int param_2,int param_3,uint param_4,int param_5)
{
  ushort uVar1;
  int iVar2;
  uint local_120;
  int local_11c;
  int local_110;
  byte abStack_10c [256];
  uint local_c;
  int local_8;
  
  for (local_8 = 0; local_8 < 0x100; local_8 = local_8 + 1) {
    abStack_10c[local_8] = (byte)param_4;
  }
  iVar2 = param_4 - 1;
  for (local_8 = 0; local_8 < iVar2; local_8 = local_8 + 1) {
    uVar1 = *(ushort *)(param_3 + local_8 * 2);
    if (0xff < uVar1) goto LAB_6814ef10;
    abStack_10c[uVar1] = (char)iVar2 - (char)local_8;
  }
  for (local_110 = param_5 + iVar2; local_110 < param_2; local_110 = local_110 + local_120) {
    local_8 = local_110;
    local_11c = iVar2;
    while( true ) {
      if (local_11c < 0) goto LAB_6814ef10;
      if (*(short *)(param_1 + local_8 * 2) != *(short *)(param_3 + local_11c * 2)) break;
      local_8 = local_8 + -1;
      local_11c = local_11c + -1;
    }
    uVar1 = *(ushort *)(param_1 + local_110 * 2);
    if (uVar1 < 0x100) {
      local_120 = (uint)abStack_10c[uVar1];
    }
    else {
      local_120 = param_4;
    }
  }
LAB_6814ef10:
  return 0;
}



// ============================================================
// Function: crypto_indexOf (FUN_6814ef20)
// Address: 6814ef20
// Size: 786 bytes
// Params: ushort * param_1, uint param_2, uint param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_indexOf(ushort *param_1,uint param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_ECX;
  undefined4 extraout_EDX;
  float10 fVar4;
  ulonglong uVar5;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_2c;
  double local_24;
  uint *local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = (uint *)certs_hashLookup((int)param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    param_4[-1] = (uint)puVar1 | 4;
    if ((*puVar1 & 0x40000000) == 0) {
      local_3c = puVar1[1];
    }
    else {
      if ((*(uint *)puVar1[1] & 0x40000000) == 0) {
        if ((*puVar1 & 0x80000000) == 0) {
          local_38 = *puVar1 >> 0xf & 0x7fff;
        }
        else {
          local_38 = 0;
        }
        local_34 = *(int *)(puVar1[1] + 4) + local_38 * 2;
      }
      else {
        local_34 = crypto_getStringLen(puVar1);
      }
      local_3c = local_34;
    }
    local_8 = local_3c;
    if ((*puVar1 & 0x40000000) == 0) {
      local_40 = *puVar1;
    }
    else {
      local_40 = (-(uint)((*puVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar1;
    }
    local_18 = local_40;
    local_1c = (uint *)certs_hashLookup((int)param_1,*param_4);
    if (local_1c == (uint *)0x0) {
      uVar2 = 0;
    }
    else {
      *param_4 = (uint)local_1c | 4;
      if ((*local_1c & 0x40000000) == 0) {
        local_4c = local_1c[1];
      }
      else {
        if ((*(uint *)local_1c[1] & 0x40000000) == 0) {
          if ((*local_1c & 0x80000000) == 0) {
            local_48 = *local_1c >> 0xf & 0x7fff;
          }
          else {
            local_48 = 0;
          }
          local_44 = *(int *)(local_1c[1] + 4) + local_48 * 2;
        }
        else {
          local_44 = crypto_getStringLen(local_1c);
        }
        local_4c = local_44;
      }
      if ((*local_1c & 0x40000000) == 0) {
        local_50 = *local_1c;
      }
      else {
        local_50 = (-(uint)((*local_1c & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_1c;
      }
      local_14 = local_50;
      if (param_3 < 2) {
        local_c = 0;
      }
      else {
        iVar3 = runtime_parseNumber(param_1,param_4[1],&local_24);
        if (iVar3 == 0) {
          return 0;
        }
        fVar4 = runtime_powFloat(SUB84(local_24,0),(uint)((ulonglong)local_24 >> 0x20));
        local_24 = (double)fVar4;
        if (0.0 <= local_24) {
          if (local_24 <= (double)(int)local_18) {
            uVar5 = strings_floatToUint64(extraout_ECX,extraout_EDX);
            local_c = (uint)uVar5;
          }
          else {
            local_c = local_18;
          }
        }
        else {
          local_c = 0;
        }
      }
      if (local_14 == 0) {
        *param_5 = local_c << 1 | 1;
        uVar2 = 1;
      }
      else {
        if (((0xfd < local_14 - 2) || ((int)local_18 < 0x200)) ||
           (local_10 = crypto_boyerMooreSearch(local_8,local_18,local_4c,local_14,local_c),
           local_10 == 0xfffffffe)) {
          local_10 = 0xffffffff;
          local_2c = 0;
          do {
            while( true ) {
              if ((int)local_18 <= (int)(local_c + local_2c)) goto LAB_6814f21a;
              if (*(short *)(local_8 + (local_c + local_2c) * 2) ==
                  *(short *)(local_4c + local_2c * 2)) break;
              local_c = local_c + 1;
              local_2c = 0;
            }
            local_2c = local_2c + 1;
          } while (local_2c != local_14);
          local_10 = local_c;
        }
LAB_6814f21a:
        *param_5 = local_10 << 1 | 1;
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



// ============================================================
// Function: crypto_lastIndexOf (FUN_6814f240)
// Address: 6814f240
// Size: 774 bytes
// Params: ushort * param_1, uint param_2, uint param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_lastIndexOf(ushort *param_1,uint param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 extraout_EDX;
  float10 fVar4;
  ulonglong uVar5;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  uint local_28;
  undefined8 local_24;
  uint *local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  uint local_8;
  
  puVar1 = (uint *)certs_hashLookup((int)param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    param_4[-1] = (uint)puVar1 | 4;
    if ((*puVar1 & 0x40000000) == 0) {
      local_3c = puVar1[1];
    }
    else {
      if ((*(uint *)puVar1[1] & 0x40000000) == 0) {
        if ((*puVar1 & 0x80000000) == 0) {
          local_38 = *puVar1 >> 0xf & 0x7fff;
        }
        else {
          local_38 = 0;
        }
        local_34 = *(int *)(puVar1[1] + 4) + local_38 * 2;
      }
      else {
        local_34 = crypto_getStringLen(puVar1);
      }
      local_3c = local_34;
    }
    local_8 = local_3c;
    if ((*puVar1 & 0x40000000) == 0) {
      local_40 = *puVar1;
    }
    else {
      local_40 = (-(uint)((*puVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar1;
    }
    local_14 = local_40;
    local_18 = (uint *)certs_hashLookup((int)param_1,*param_4);
    if (local_18 == (uint *)0x0) {
      uVar2 = 0;
    }
    else {
      *param_4 = (uint)local_18 | 4;
      if ((*local_18 & 0x40000000) == 0) {
        local_4c = local_18[1];
      }
      else {
        if ((*(uint *)local_18[1] & 0x40000000) == 0) {
          if ((*local_18 & 0x80000000) == 0) {
            local_48 = *local_18 >> 0xf & 0x7fff;
          }
          else {
            local_48 = 0;
          }
          local_44 = *(int *)(local_18[1] + 4) + local_48 * 2;
        }
        else {
          local_44 = crypto_getStringLen(local_18);
        }
        local_4c = local_44;
      }
      if ((*local_18 & 0x40000000) == 0) {
        local_50 = *local_18;
      }
      else {
        local_50 = (-(uint)((*local_18 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_18;
      }
      local_10 = local_50;
      if (param_3 < 2) {
        local_c = local_14;
      }
      else {
        iVar3 = runtime_parseNumber(param_1,param_4[1],(double *)&local_24);
        if (iVar3 == 0) {
          return 0;
        }
        if ((((*(unsigned int *)((char *)&local_24 + 4)) & 0x7ff00000) == 0x7ff00000) &&
           (((int)local_24 != 0 || (((ulonglong)local_24 & 0xfffff00000000) != 0)))) {
          local_c = local_14;
        }
        else {
          fVar4 = runtime_powFloat((int)local_24,(*(unsigned int *)((char *)&local_24 + 4)));
          local_24 = (double)fVar4;
          if (0.0 <= local_24) {
            if (local_24 <= (double)(int)(local_14 - local_10)) {
              uVar5 = strings_floatToUint64(local_14 - local_10,extraout_EDX);
              local_c = (uint)uVar5;
            }
            else {
              local_c = local_14 - local_10;
            }
          }
          else {
            local_c = 0;
          }
        }
      }
      if (local_10 == 0) {
        *param_5 = local_c << 1 | 1;
        uVar2 = 1;
      }
      else {
        local_28 = 0;
        do {
          while( true ) {
            if ((int)local_c < 0) goto LAB_6814f52e;
            if (((int)(local_c + local_28) < (int)local_14) &&
               (*(short *)(local_8 + (local_c + local_28) * 2) ==
                *(short *)(local_4c + local_28 * 2))) break;
            local_c = local_c - 1;
            local_28 = 0;
          }
          local_28 = local_28 + 1;
        } while (local_28 != local_10);
LAB_6814f52e:
        *param_5 = local_c << 1 | 1;
        uVar2 = 1;
      }
    }
  }
  return uVar2;
}



// ============================================================
// Function: crypto_matchString (FUN_6814f550)
// Address: 6814f550
// Size: 108 bytes
// Params: uint * param_1, uint param_2, uint param_3, uint * param_4, uint * param_5
// Return: int
// Calling convention: __stdcall
// ============================================================

int crypto_matchString(uint *param_1,uint param_2,uint param_3,uint *param_4,uint *param_5)

{
  int iVar1;
  uint local_1c [4];
  uint *local_c;
  
  local_1c[0] = 0;
  local_1c[1] = 1;
  local_c = param_4 + 2;
  *local_c = 0;
  iVar1 = crypto_bigDivide(param_1,param_2,param_3,param_4,crypto_matchCallback,local_1c,param_5);
  if ((iVar1 != 0) && (*local_c != 0)) {
    *param_5 = *local_c;
  }
  return iVar1;
}



// ============================================================
// Function: crypto_bigDivide (FUN_6814f5c0)
// Address: 6814f5c0
// Size: 885 bytes
// Params: uint * param_1, uint param_2, uint param_3, uint * param_4, undefined * param_5, uint * param_6, uint * param_7
// Return: int
// Calling convention: __stdcall
// ============================================================

int crypto_bigDivide(uint *param_1,uint param_2,uint param_3,uint *param_4,undefined *param_5,
                uint *param_6,uint *param_7)

{
  uint *puVar1;
  uint *puVar2;
  uint local_34;
  uint local_30;
  int *local_24;
  uint local_20;
  int local_1c;
  uint *local_18;
  uint local_14;
  int local_10;
  uint local_c;
  int local_8;
  
  puVar1 = (uint *)certs_hashLookup((int)param_1,param_2);
  if (puVar1 == (uint *)0x0) {
    return 0;
  }
  param_4[-1] = (uint)puVar1 | 4;
  param_6[2] = (uint)puVar1;
  if ((((*param_4 & 7) == 0) && ((*param_4 & 0xfffffff8) != 0)) &&
     ((undefined **)(*(uint *)(*(int *)((*param_4 & 0xfffffff8) + 4) + 8) & 0xfffffffe) ==
      &PTR_s_RegExp_68193210)) {
    local_20 = *param_4 & 0xfffffff8;
    local_24 = (int *)xtra_getObjectTag(param_1,local_20);
  }
  else {
    puVar2 = (uint *)certs_hashLookup((int)param_1,*param_4);
    if (puVar2 == (uint *)0x0) {
      return 0;
    }
    if (param_6[1] < param_3) {
      *param_4 = (uint)puVar2 | 4;
      local_18 = (uint *)certs_hashLookup((int)param_1,param_4[param_6[1]]);
      if (local_18 == (uint *)0x0) {
        return 0;
      }
    }
    else {
      local_18 = (uint *)0x0;
    }
    local_24 = javascript_compileRegexWithFlags(param_1,0,puVar2,local_18,(uint)((*param_6 & 4) != 0));
    if (local_24 == (int *)0x0) {
      return 0;
    }
    local_20 = 0;
  }
  param_6[3] = (uint)local_24;
  if (((uint)local_24[1] >> 0x18 & 2) != 0) {
    *param_6 = *param_6 | 0x10;
  }
  local_14 = 0;
  if ((*param_6 & 3) == 2) {
    local_10 = runtime_execRegex(param_1,(int)local_24,puVar1,&local_14,1,param_7);
    if (local_10 != 0) {
      if (*param_7 == 0xe) {
        local_30 = param_1[0x48] << 1 | 1;
      }
      else {
        local_30 = 0xffffffff;
      }
      *param_7 = local_30;
    }
  }
  else {
    if ((*param_6 & 0x10) != 0) {
      if (local_20 == 0) {
        local_10 = 1;
      }
      else {
        local_10 = js_regexpExec(*param_6 & 0x10,local_20,(uint)param_1,(int *)local_20,0);
        if (local_10 == 0) {
          return 0;
        }
      }
      if ((*puVar1 & 0x40000000) == 0) {
        local_34 = *puVar1;
      }
      else {
        local_34 = (-(uint)((*puVar1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *puVar1;
      }
      local_c = local_34;
      local_8 = 0;
      do {
        if (((local_c < local_14) ||
            (local_10 = runtime_execRegex(param_1,(int)local_24,puVar1,&local_14,1,param_7),
            local_10 == 0)) ||
           ((*param_7 != 0xe || (local_10 = (*(code *)param_5)(param_1,local_8), local_10 == 0))))
        goto LAB_6814f8f6;
        if (param_1[0x44] == 0) {
          if (local_14 == local_c) goto LAB_6814f8f6;
          local_14 = local_14 + 1;
        }
        local_8 = local_8 + 1;
      } while( true );
    }
    if ((*param_6 & 3) == 1) {
      local_1c = 1;
    }
    else {
      switch(*(undefined1 *)(*(int *)(*(int *)(param_1[0xd] + 0x2c) + 0x38) + 3)) {
      case 7:
      case 8:
      case 0x51:
      case 0x8c:
      case 0x8d:
        local_1c = 1;
        break;
      default:
        local_1c = 0;
      }
    }
    local_10 = runtime_execRegex(param_1,(int)local_24,puVar1,&local_14,local_1c,param_7);
  }
LAB_6814f8f6:
  if (local_20 == 0) {
    if ((*param_6 & 8) == 0) {
      param_6[3] = 0;
      runtime_regexBacktrack(param_1,local_24);
    }
  }
  else {
    *param_6 = *param_6 & 0xfffffff7;
  }
  return local_10;
}



// ============================================================
// Function: crypto_matchCallback (FUN_6814f9d0)
// Address: 6814f9d0
// Size: 164 bytes
// Params: uint param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 crypto_matchCallback(uint param_1,int param_2,int param_3)

{
  uint *puVar1;
  undefined4 uVar2;
  int *local_10;
  uint local_8;
  
  local_10 = (int *)(**(uint **)(param_3 + 0x10) & 0xfffffff8);
  if (local_10 == (int *)0x0) {
    local_10 = runtime_createPropertyFromName(param_1,&PTR_s_Array_681939b8,(undefined4 *)0x0,0,0,0);
    if (local_10 == (int *)0x0) {
      return 0;
    }
    **(undefined4 **)(param_3 + 0x10) = local_10;
  }
  puVar1 = certs_allocFromPool(param_1,*(void **)(param_1 + 0x114),*(uint *)(param_1 + 0x110),0);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    local_8 = (uint)puVar1 | 4;
    uVar2 = runtime_getPropertyEx(param_1,local_10,param_2 << 1 | 1,&local_8);
  }
  return uVar2;
}



// ============================================================
// Function: crypto_searchString (FUN_6814fa80)
// Address: 6814fa80
// Size: 57 bytes
// Params: uint * param_1, uint param_2, uint param_3, uint * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int crypto_searchString(uint *param_1,uint param_2,uint param_3,uint *param_4,uint *param_5)
{
  uint local_14 [4];
  
  local_14[0] = 2;
  local_14[1] = 1;
  crypto_bigDivide(param_1,param_2,param_3,param_4,(undefined *)0x0,local_14,param_5);
  return 0;
}



// ============================================================
// Function: crypto_replaceString (FUN_6814fac0)
// Address: 6814fac0
// Size: 986 bytes
// Params: uint * param_1, uint param_2, uint param_3, uint * param_4, uint * param_5
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crypto_replaceString(uint *param_1,uint param_2,uint param_3,uint *param_4,uint *param_5)

{
  uint uVar1;
  byte bVar2;
  undefined3 extraout_var;
  int iVar3;
  void *_Dst;
  uint uVar4;
  uint *puVar5;
  short *local_78;
  uint local_74;
  short *local_70;
  uint local_6c;
  uint local_68;
  uint local_64;
  uint local_60;
  uint *local_4c;
  uint local_48 [3];
  int *local_3c;
  uint local_38;
  uint *local_34;
  short *local_30;
  short *local_2c;
  void *local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  uint local_10;
  uint local_c;
  uint local_8;
  
  bVar2 = xtra_lookupHashByte(param_1,param_4[1]);
  if (CONCAT31(extraout_var,bVar2) == 2) {
    local_c = param_4[1] & 0xfffffff8;
    local_4c = (uint *)0x0;
  }
  else {
    iVar3 = xtra_convertValue((ushort *)param_1,param_4[1],3,param_4 + 1);
    if (iVar3 == 0) {
      return 0;
    }
    local_4c = (uint *)(param_4[1] & 0xfffffff8);
    local_c = 0;
  }
  local_48[0] = 9;
  if ((param_1[3] == 0) || (0x8c < (int)param_1[3])) {
    local_48[0] = 0xd;
  }
  local_48[1] = 2;
  local_38 = local_c;
  local_34 = local_4c;
  if (local_4c == (uint *)0x0) {
    local_2c = (short *)0x0;
    local_30 = (short *)0x0;
  }
  else {
    if ((*local_4c & 0x40000000) == 0) {
      local_68 = local_4c[1];
    }
    else {
      if ((*(uint *)local_4c[1] & 0x40000000) == 0) {
        if ((*local_4c & 0x80000000) == 0) {
          local_64 = *local_4c >> 0xf & 0x7fff;
        }
        else {
          local_64 = 0;
        }
        local_60 = *(int *)(local_4c[1] + 4) + local_64 * 2;
      }
      else {
        local_60 = crypto_getStringLen(local_4c);
      }
      local_68 = local_60;
    }
    if ((*local_4c & 0x40000000) == 0) {
      local_6c = *local_4c;
    }
    else {
      local_6c = (-(uint)((*local_4c & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_4c;
    }
    local_2c = (short *)(local_68 + local_6c * 2);
    if ((*local_4c & 0x40000000) == 0) {
      local_78 = (short *)local_4c[1];
    }
    else {
      if ((*(uint *)local_4c[1] & 0x40000000) == 0) {
        if ((*local_4c & 0x80000000) == 0) {
          local_74 = *local_4c >> 0xf & 0x7fff;
        }
        else {
          local_74 = 0;
        }
        local_70 = (short *)(*(int *)(local_4c[1] + 4) + local_74 * 2);
      }
      else {
        local_70 = (short *)crypto_getStringLen(local_4c);
      }
      local_78 = local_70;
    }
    local_30 = certs_findCharInString(local_78,0x24,local_2c);
  }
  local_28 = (void *)0x0;
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  local_10 = crypto_bigDivide(param_1,param_2,param_3,param_4,certificates_executeReplace,local_48,param_5);
  if (local_10 == 0) {
    return 0;
  }
  if (local_28 == (void *)0x0) {
    if (((local_48[0] & 0x10) != 0) || (*param_5 != 0xe)) {
      *param_5 = local_48[2] | 4;
      goto LAB_6814fe7c;
    }
    uVar1 = param_1[0x48];
    local_10 = crypto_evalReplacement((uint)param_1,(int)local_48,&local_8);
    if (local_10 == 0) goto LAB_6814fe7c;
    local_8 = local_8 + uVar1;
    _Dst = (void *)xtra_getPropertyById((int)param_1,local_8 * 2 + 2);
    if (_Dst == (void *)0x0) {
      local_10 = 0;
      goto LAB_6814fe7c;
    }
    memcpy(_Dst,(void *)param_1[0x49],uVar1 << 1);
    certificates_applyReplace((int)param_1,(int)local_48,(void *)((int)_Dst + uVar1 * 2));
    local_24 = local_8;
    local_28 = _Dst;
  }
  uVar1 = param_1[0x4a];
  local_8 = local_24 + uVar1;
  uVar4 = xtra_allocJSString((int)param_1,(int)local_28,local_8 * 2 + 2);
  if (uVar4 == 0) {
    xtra_checkAndFlush(param_1,(int)local_28);
    local_10 = 0;
  }
  else {
    memcpy((void *)(uVar4 + local_24 * 2),(void *)param_1[0x4b],uVar1 << 1);
    *(undefined2 *)(uVar4 + local_8 * 2) = 0;
    puVar5 = certs_allocHashEntry((int)param_1,uVar4,local_8,0);
    if (puVar5 == (uint *)0x0) {
      xtra_checkAndFlush(param_1,uVar4);
      local_10 = 0;
    }
    else {
      *param_5 = (uint)puVar5 | 4;
    }
  }
LAB_6814fe7c:
  if ((local_48[0] & 8) != 0) {
    runtime_regexBacktrack(param_1,local_3c);
  }
  return local_10;
}



// ============================================================
// Function: crypto_evalReplacement (FUN_6814fea0)
// Address: 6814fea0
// Size: 1032 bytes
// Params: uint param_1, int param_2, uint * param_3
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint crypto_evalReplacement(uint param_1,int param_2,uint *param_3)

{
  uint uVar1;
  undefined4 uVar2;
  int *piVar3;
  uint *puVar4;
  uint local_70;
  uint local_6c;
  uint local_68;
  int local_58;
  int local_4c;
  int local_48;
  uint local_44;
  uint local_40;
  uint *local_3c;
  uint local_38;
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  undefined4 local_28;
  uint local_24;
  short *local_20;
  int *local_1c;
  uint *local_18;
  int local_14;
  ushort *local_10;
  int local_c;
  uint local_8;
  
  local_c = *(int *)(param_2 + 0x10);
  if (local_c == 0) {
    local_18 = *(uint **)(param_2 + 0x14);
    if ((*local_18 & 0x40000000) == 0) {
      local_70 = *local_18;
    }
    else {
      local_70 = (-(uint)((*local_18 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_18;
    }
    local_8 = local_70;
    local_20 = *(short **)(param_2 + 0x1c);
    local_c = 0;
    for (local_10 = *(ushort **)(param_2 + 0x18); local_10 != (ushort *)0x0;
        local_10 = (ushort *)certs_findCharInString((short *)local_10,0x24,local_20)) {
      local_1c = certificates_resolveBackref(param_1,local_10,param_2,&local_14);
      if (local_1c == (int *)0x0) {
        local_10 = local_10 + 1;
      }
      else {
        local_8 = (*local_1c - local_14) + local_8;
        local_10 = local_10 + local_14;
      }
    }
    *param_3 = local_8;
    local_34 = 1;
  }
  else {
    local_2c = *(undefined4 *)(param_1 + 0x128);
    local_28 = *(undefined4 *)(param_1 + 300);
    local_24 = *(uint *)(*(int *)(param_2 + 0xc) + 4) & 0xffffff;
    local_30 = local_24 + 3;
    piVar3 = certs_findExtension(param_1,local_24 + 5,&local_4c);
    if (piVar3 == (int *)0x0) {
      local_34 = 0;
    }
    else {
      *piVar3 = local_c;
      piVar3[1] = *(uint *)(*(int *)(local_c + 4) + 4) & 0xfffffff8;
      local_3c = (uint *)(piVar3 + 2);
      puVar4 = certs_allocFromPool(param_1,*(void **)(param_1 + 0x114),*(uint *)(param_1 + 0x110),0);
      if (puVar4 == (uint *)0x0) {
        local_34 = 0;
      }
      else {
        *local_3c = (uint)puVar4 | 4;
        local_44 = 0;
        uVar1 = *(uint *)(param_1 + 0xbc);
        local_68 = uVar1;
        if (8 < uVar1) {
          local_68 = 9;
        }
        local_40 = local_68;
        local_58 = 0;
        for (; local_3c = local_3c + 1, local_44 < local_40; local_44 = local_44 + 1) {
          puVar4 = certs_allocFromPool(param_1,*(void **)(param_1 + 200 + local_58 * 8),
                                *(uint *)(param_1 + 0xc4 + local_58 * 8),0);
          if (puVar4 == (uint *)0x0) {
            local_34 = 0;
            goto LAB_681501b4;
          }
          *local_3c = (uint)puVar4 | 4;
          local_58 = local_58 + 1;
        }
        local_58 = 0;
        for (; local_44 < uVar1; local_44 = local_44 + 1) {
          puVar4 = certs_allocFromPool(param_1,*(void **)(*(int *)(param_1 + 0x10c) + 4 + local_58 * 8),
                                *(uint *)(*(int *)(param_1 + 0x10c) + local_58 * 8),0);
          if (puVar4 == (uint *)0x0) {
            local_34 = 0;
            goto LAB_681501b4;
          }
          *local_3c = (uint)puVar4 | 4;
          local_3c = local_3c + 1;
          local_58 = local_58 + 1;
        }
        for (; local_44 < local_24; local_44 = local_44 + 1) {
          *local_3c = 0x80000001;
          local_3c = local_3c + 1;
        }
        *local_3c = *(int *)(param_1 + 0x120) << 1 | 1;
        local_3c[1] = *(uint *)(param_2 + 8) | 4;
        local_3c = local_3c + 2;
        local_48 = *(int *)(param_1 + 0x34);
        uVar2 = *(undefined4 *)(local_48 + 0x3c);
        *(uint **)(local_48 + 0x3c) = local_3c;
        local_34 = certs_verifyChain(param_1,local_30,2);
        local_38 = *(uint *)(*(int *)(local_48 + 0x3c) + -4);
        *(undefined4 *)(local_48 + 0x3c) = uVar2;
        if (local_34 != 0) {
          local_18 = (uint *)certs_hashLookup(param_1,local_38);
          if (local_18 == (uint *)0x0) {
            local_34 = 0;
          }
          else {
            *(uint **)(param_2 + 0x14) = local_18;
            if ((*local_18 & 0x40000000) == 0) {
              local_6c = *local_18;
            }
            else {
              local_6c = (-(uint)((*local_18 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *local_18;
            }
            *param_3 = local_6c;
          }
        }
      }
LAB_681501b4:
      certs_checkValidity(param_1,local_4c);
      *(undefined4 *)(param_1 + 0x128) = local_2c;
      *(undefined4 *)(param_1 + 300) = local_28;
    }
  }
  return local_34;
}



