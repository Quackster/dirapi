// Module: certificates
// Topic: URI encoding/decoding, UTF-8 conversion, string-to-multibyte caching
// Address range: 0x68152DD0 - 0x68153A40
// Functions (10):
//   certs_encodeUri
//   certificates_decodeUriReserved
//   certificates_decodeUriCore
//   certs_decodeUri
//   certificates_decodeUriComponent
//   certificates_encodeUriReserved
//   certificates_encodeUriCore
//   certificates_encodeUriComponent
//   certificates_encodeToUtf8
//   certificates_decodeUtf8

// ============================================================
// Function: certs_encodeUri (FUN_68152dd0)
// Address: 68152dd0
// Size: 349 bytes
// Params: uint * param_1
// Return: int
// Calling convention: __stdcall
// ============================================================

int certs_encodeUri(uint *param_1)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint local_2c;
  uint local_28;
  uint local_24;
  uint local_20;
  int local_c;
  int local_8;

  piVar1 = certificates_getStringCache();
  if (piVar1 == (int *)0x0) {
    local_c = 0;
  }
  else {
    uVar2 = runtime_getCharType((uint)param_1);
    piVar3 = crypto_findHashEntry(piVar1,uVar2,param_1);
    if (*piVar3 == 0) {
      if ((*param_1 & 0x40000000) == 0) {
        local_20 = *param_1;
      }
      else {
        local_20 = (-(uint)((*param_1 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_1;
      }
      if ((*param_1 & 0x40000000) == 0) {
        local_2c = param_1[1];
      }
      else {
        if ((*(uint *)param_1[1] & 0x40000000) == 0) {
          if ((*param_1 & 0x80000000) == 0) {
            local_28 = *param_1 >> 0xf & 0x7fff;
          }
          else {
            local_28 = 0;
          }
          local_24 = *(int *)(param_1[1] + 4) + local_28 * 2;
        }
        else {
          local_24 = crypto_getStringLen(param_1);
        }
        local_2c = local_24;
      }
      local_c = certs_formatString(0,local_2c,local_20,&local_8);
      if ((local_c != 0) &&
         (puVar4 = crypto_decompileBlock(piVar1,piVar3,uVar2,param_1,local_c), puVar4 == (undefined4 *)0x0))
      {
        js_freeHandle();
        local_c = 0;
      }
    }
    else {
      local_c = *(int *)(*piVar3 + 0xc);
    }
  }
  return local_c;
}



// ============================================================
// Function: certificates_decodeUriReserved (FUN_68152f30)
// Address: 68152f30
// Size: 60 bytes
// Params: uint param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
certificates_decodeUriReserved(uint param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;

  puVar1 = (uint *)certs_hashLookup(param_1,*param_4);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = certificates_decodeUriCore(param_1,puVar1,L";/?:@&=+$,#",param_5);
  }
  return uVar2;
}



// ============================================================
// Function: certificates_decodeUriCore (FUN_68152f70)
// Address: 68152f70
// Size: 1376 bytes
// Params: uint param_1, uint * param_2, short * param_3, uint * param_4
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_decodeUriCore(uint param_1,uint *param_2,short *param_3,uint *param_4)
{
  uint *puVar1;
  int iVar2;
  int iVar3;
  short *psVar4;
  uint uVar5;
  int local_5c;
  int local_58;
  int local_54;
  int local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  int local_3c;
  uint local_34;
  short local_2c [2];
  uint local_28;
  byte local_24 [8];
  uint local_1c;
  uint local_18;
  uint local_14;
  int local_10;
  uint local_c;
  short local_8 [2];

  puVar1 = certs_allocHashEntry(param_1,0,0,0);
  if (puVar1 != (uint *)0x0) {
    if ((*param_2 & 0x40000000) == 0) {
      local_48 = param_2[1];
    }
    else {
      if ((*(uint *)param_2[1] & 0x40000000) == 0) {
        if ((*param_2 & 0x80000000) == 0) {
          local_44 = *param_2 >> 0xf & 0x7fff;
        }
        else {
          local_44 = 0;
        }
        local_40 = *(int *)(param_2[1] + 4) + local_44 * 2;
      }
      else {
        local_40 = crypto_getStringLen(param_2);
      }
      local_48 = local_40;
    }
    if ((*param_2 & 0x40000000) == 0) {
      local_4c = *param_2;
    }
    else {
      local_4c = (-(uint)((*param_2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_2;
    }
    local_c = local_4c;
    for (local_34 = 0; local_34 < local_c; local_34 = local_34 + 1) {
      local_2c[0] = *(short *)(local_48 + local_34 * 2);
      if (local_2c[0] == 0x25) {
        local_28 = local_34;
        if ((((local_34 + 2 < local_c) && (*(ushort *)(local_48 + 2 + local_34 * 2) < 0x80)) &&
            (iVar2 = isxdigit((uint)*(ushort *)(local_48 + 2 + local_34 * 2)), iVar2 != 0)) &&
           ((*(ushort *)(local_48 + 4 + local_34 * 2) < 0x80 &&
            (iVar2 = isxdigit((uint)*(ushort *)(local_48 + 4 + local_34 * 2)), iVar2 != 0)))) {
          iVar2 = isdigit((uint)*(ushort *)(local_48 + 2 + local_34 * 2));
          if (iVar2 == 0) {
            local_50 = tolower((uint)*(ushort *)(local_48 + 2 + local_34 * 2));
            local_50 = local_50 + -0x57;
          }
          else {
            local_50 = *(ushort *)(local_48 + 2 + local_34 * 2) - 0x30;
          }
          iVar2 = isdigit((uint)*(ushort *)(local_48 + 4 + local_34 * 2));
          if (iVar2 == 0) {
            local_54 = tolower((uint)*(ushort *)(local_48 + 4 + local_34 * 2));
            local_54 = local_54 + -0x57;
          }
          else {
            local_54 = *(ushort *)(local_48 + 4 + local_34 * 2) - 0x30;
          }
          local_14 = local_50 * 0x10 + local_54;
          local_34 = local_34 + 2;
          if ((local_14 & 0x80) == 0) {
            local_2c[0] = (short)local_14;
            goto LAB_681533eb;
          }
          local_10 = 1;
          while ((0x80 >> ((byte)local_10 & 0x1f) & local_14) != 0) {
            local_10 = local_10 + 1;
          }
          if ((local_10 != 1) && (local_10 < 7)) {
            local_24[0] = (byte)local_14;
            if ((local_10 + -1) * 3 + local_34 < local_c) {
              for (local_3c = 1; local_3c < local_10; local_3c = local_3c + 1) {
                iVar2 = local_34 + 1;
                if ((((*(short *)(local_48 + iVar2 * 2) != 0x25) ||
                     (0x7f < *(ushort *)(local_48 + 2 + iVar2 * 2))) ||
                    (iVar3 = isxdigit((uint)*(ushort *)(local_48 + 2 + iVar2 * 2)), iVar3 == 0)) ||
                   ((0x7f < *(ushort *)(local_48 + 4 + iVar2 * 2) ||
                    (iVar3 = isxdigit((uint)*(ushort *)(local_48 + 4 + iVar2 * 2)), iVar3 == 0))))
                goto LAB_681534a6;
                iVar3 = isdigit((uint)*(ushort *)(local_48 + 2 + iVar2 * 2));
                if (iVar3 == 0) {
                  local_58 = tolower((uint)*(ushort *)(local_48 + 2 + iVar2 * 2));
                  local_58 = local_58 + -0x57;
                }
                else {
                  local_58 = *(ushort *)(local_48 + 2 + iVar2 * 2) - 0x30;
                }
                iVar3 = isdigit((uint)*(ushort *)(local_48 + 4 + iVar2 * 2));
                if (iVar3 == 0) {
                  local_5c = tolower((uint)*(ushort *)(local_48 + 4 + iVar2 * 2));
                  local_5c = local_5c + -0x57;
                }
                else {
                  local_5c = *(ushort *)(local_48 + 4 + iVar2 * 2) - 0x30;
                }
                local_14 = local_58 * 0x10 + local_5c;
                if ((local_14 & 0xc0) != 0x80) goto LAB_681534a6;
                local_34 = local_34 + 3;
                local_24[local_3c] = (byte)local_14;
              }
              local_18 = certificates_decodeUtf8(local_24,local_10);
              if (local_18 < 0x10000) {
                local_2c[0] = (short)local_18;
              }
              else {
                local_18 = local_18 - 0x10000;
                if (0xfffff < local_18) goto LAB_681534a6;
                local_2c[0] = ((ushort)local_18 & 0x3ff) + 0xdc00;
                local_8[0] = (short)(local_18 >> 10) + -0x2800;
                iVar2 = certs_decodeUri(param_1,(int *)puVar1,local_8,1);
                if (iVar2 == 0) goto LAB_681534c0;
              }
LAB_681533eb:
              psVar4 = certs_findChar(param_3,local_2c[0]);
              if (psVar4 == (short *)0x0) {
                iVar2 = certs_decodeUri(param_1,(int *)puVar1,local_2c,1);
                goto joined_r0x68153440;
              }
              iVar2 = certs_decodeUri(param_1,(int *)puVar1,(void *)(local_48 + local_28 * 2),
                                   (local_34 - local_28) + 1);
              if (iVar2 != 0) goto LAB_68153062;
              goto LAB_681534c0;
            }
          }
        }
LAB_681534a6:
        xtra_invokeMethod(param_1,xtra_getErrorString,0,0x9f);
        goto LAB_681534c0;
      }
      iVar2 = certs_decodeUri(param_1,(int *)puVar1,local_2c,1);
joined_r0x68153440:
      if (iVar2 == 0) goto LAB_681534c0;
LAB_68153062:
    ; /* FIXUP: label needs statement */ }
    uVar5 = xtra_allocJSString(param_1,puVar1[1],*puVar1 * 2 + 2);
    if (uVar5 != 0) {
      puVar1[1] = uVar5;
    }
    *param_4 = (uint)puVar1 | 4;
  }
LAB_681534c0:
  return 0;
}



// ============================================================
// Function: certs_decodeUri (FUN_681534d0)
// Address: 681534d0
// Size: 182 bytes
// Params: int param_1, int * param_2, void * param_3, int param_4
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4 certs_decodeUri(int param_1,int *param_2,void *param_3,int param_4)

{
  int iVar1;

  iVar1 = *param_2 + 1 + param_4;
  if ((param_2[1] == 0) || (*param_2 + 0x40U >> 6 < iVar1 + 0x3fU >> 6)) {
    iVar1 = xtra_allocJSString(param_1,param_2[1],(iVar1 + 0x3fU & 0xffffffc0) << 1);
    param_2[1] = iVar1;
    if (param_2[1] == 0) {
      return 0;
    }
  }
  memcpy((void *)(param_2[1] + *param_2 * 2),param_3,param_4 << 1);
  *param_2 = *param_2 + param_4;
  *(undefined2 *)(param_2[1] + *param_2 * 2) = 0;
  return 1;
}



// ============================================================
// Function: certificates_decodeUriComponent (FUN_68153590)
// Address: 68153590
// Size: 60 bytes
// Params: uint param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
certificates_decodeUriComponent(uint param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;

  puVar1 = (uint *)certs_hashLookup(param_1,*param_4);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = certificates_decodeUriCore(param_1,puVar1,(short *)&DAT_68196a34,param_5);
  }
  return uVar2;
}



// ============================================================
// Function: certificates_encodeUriReserved (FUN_681535d0)
// Address: 681535d0
// Size: 65 bytes
// Params: uint param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
certificates_encodeUriReserved(uint param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;

  puVar1 = (uint *)certs_hashLookup(param_1,*param_4);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = certificates_encodeUriCore(param_1,puVar1,L";/?:@&=+$,#",
                         L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_.!~*\'()"
                         ,param_5);
  }
  return uVar2;
}



// ============================================================
// Function: certificates_encodeUriCore (FUN_68153620)
// Address: 68153620
// Size: 804 bytes
// Params: uint param_1, uint * param_2, short * param_3, short * param_4, uint * param_5
// Return: undefined
// Calling convention: __stdcall
// ============================================================

int certificates_encodeUriCore(uint param_1,uint *param_2,short *param_3,short *param_4,uint *param_5)
{
  short *psVar1;
  int iVar2;
  uint uVar3;
  uint local_4c;
  uint local_48;
  uint local_44;
  uint local_40;
  uint local_3c;
  uint local_30;
  undefined2 local_2c;
  short local_2a;
  short local_28;
  undefined2 local_26;
  uint *local_24;
  ushort local_20 [2];
  byte local_1c [8];
  uint local_14;
  uint local_10;
  uint local_c;
  ushort local_8;

  local_24 = certs_allocHashEntry(param_1,0,0,0);
  if (local_24 != (uint *)0x0) {
    local_2c = 0x25;
    local_26 = 0;
    if ((*param_2 & 0x40000000) == 0) {
      local_48 = param_2[1];
    }
    else {
      if ((*(uint *)param_2[1] & 0x40000000) == 0) {
        if ((*param_2 & 0x80000000) == 0) {
          local_44 = *param_2 >> 0xf & 0x7fff;
        }
        else {
          local_44 = 0;
        }
        local_40 = *(int *)(param_2[1] + 4) + local_44 * 2;
      }
      else {
        local_40 = crypto_getStringLen(param_2);
      }
      local_48 = local_40;
    }
    if ((*param_2 & 0x40000000) == 0) {
      local_4c = *param_2;
    }
    else {
      local_4c = (-(uint)((*param_2 & 0x80000000) != 0) & 0x3fff8000) + 0x7fff & *param_2;
    }
    local_c = local_4c;
    for (local_30 = 0; local_30 < local_c; local_30 = local_30 + 1) {
      local_20[0] = *(ushort *)(local_48 + local_30 * 2);
      psVar1 = certs_findChar(param_3,local_20[0]);
      if ((psVar1 == (short *)0x0) &&
         ((param_4 == (short *)0x0 ||
          (psVar1 = certs_findChar(param_4,local_20[0]), psVar1 == (short *)0x0)))) {
        if ((0xdbff < local_20[0]) && (local_20[0] < 0xe000)) {
          xtra_invokeMethod(param_1,xtra_getErrorString,0,0x9f);
          goto LAB_68153934;
        }
        if ((local_20[0] < 0xd800) || (0xdbff < local_20[0])) {
          local_10 = (uint)local_20[0];
        }
        else {
          local_30 = local_30 + 1;
          if (local_30 == local_c) {
            xtra_invokeMethod(param_1,xtra_getErrorString,0,0x9f);
            goto LAB_68153934;
          }
          local_8 = *(ushort *)(local_48 + local_30 * 2);
          if ((local_8 < 0xdc00) || (0xdfff < local_8)) {
            xtra_invokeMethod(param_1,xtra_getErrorString,0,0x9f);
            goto LAB_68153934;
          }
          local_10 = (local_20[0] - 0xd800) * 0x400 + 0x2400 + (uint)local_8;
        }
        uVar3 = certificates_encodeToUtf8((char *)local_1c,local_10);
        for (local_3c = 0; local_3c < uVar3; local_3c = local_3c + 1) {
          local_2a = (short)"0123456789ABCDEF"[(int)(uint)local_1c[local_3c] >> 4];
          local_28 = (short)"0123456789ABCDEF"[local_1c[local_3c] & 0xf];
          iVar2 = certs_decodeUri(param_1,(int *)local_24,&local_2c,3);
          if (iVar2 == 0) goto LAB_68153934;
        }
      }
      else {
        iVar2 = certs_decodeUri(param_1,(int *)local_24,local_20,1);
        if (iVar2 == 0) goto LAB_68153934;
      }
    }
    uVar3 = xtra_allocJSString(param_1,local_24[1],*local_24 * 2 + 2);
    if (uVar3 != 0) {
      local_24[1] = uVar3;
    }
    *param_5 = (uint)local_24 | 4;
  }
LAB_68153934:
  return 0;
}



// ============================================================
// Function: certificates_encodeUriComponent (FUN_68153950)
// Address: 68153950
// Size: 62 bytes
// Params: uint param_1, undefined4 param_2, undefined4 param_3, uint * param_4, uint * param_5
// Return: undefined4
// Calling convention: __stdcall
// ============================================================

undefined4
certificates_encodeUriComponent(uint param_1,undefined4 param_2,undefined4 param_3,uint *param_4,uint *param_5)

{
  uint *puVar1;
  undefined4 uVar2;

  puVar1 = (uint *)certs_hashLookup(param_1,*param_4);
  if (puVar1 == (uint *)0x0) {
    uVar2 = 0;
  }
  else {
    uVar2 = certificates_encodeUriCore(param_1,puVar1,
                         L"0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz-_.!~*\'()"
                         ,(short *)0x0,param_5);
  }
  return uVar2;
}



// ============================================================
// Function: certificates_encodeToUtf8 (FUN_68153990)
// Address: 68153990
// Size: 161 bytes
// Params: char * param_1, uint param_2
// Return: int
// Calling convention: __stdcall
// ============================================================

int certificates_encodeToUtf8(char *param_1,uint param_2)

{
  int local_10;
  uint local_c;
  int local_8;

  local_8 = 1;
  if (param_2 < 0x80) {
    *param_1 = (char)param_2;
  }
  else {
    local_8 = 2;
    for (local_c = param_2 >> 0xb; local_c != 0; local_c = local_c >> 5) {
      local_8 = local_8 + 1;
    }
    local_10 = local_8;
    while (local_10 = local_10 + -1, local_10 != 0) {
      param_1[local_10] = (byte)param_2 & 0x3f | 0x80;
      param_2 = param_2 >> 6;
    }
    *param_1 = (byte)param_2 - (char)(1 << (8U - (char)local_8 & 0x1f));
  }
  return local_8;
}



// ============================================================
// Function: certificates_decodeUtf8 (FUN_68153a40)
// Address: 68153a40
// Size: 158 bytes
// Params: byte * param_1, int param_2
// Return: uint
// Calling convention: __stdcall
// ============================================================

uint certificates_decodeUtf8(byte *param_1,int param_2)

{
  int iVar1;
  uint local_c;

  if (param_2 == 1) {
    local_c = (uint)*param_1;
  }
  else {
    local_c = (uint)*param_1 & (1 << (7U - (char)param_2 & 0x1f)) - 1U;
    iVar1 = param_2 * 4;
    while (param_1 = param_1 + 1, param_2 = param_2 + -1, param_2 != 0) {
      local_c = local_c << 6 | *param_1 & 0x3f;
    }
    if (((local_c < *(uint *)("0123456789ABCDEF" + iVar1 + 0xc)) || (local_c == 0xfffe)) ||
       (local_c == 0xffff)) {
      local_c = 0xfffd;
    }
  }
  return local_c;
}



