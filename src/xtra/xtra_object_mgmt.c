// Module: xtra
// Topic: Object allocation, management, error handling, ASN.1 template parsing
// Address range: 0x681035E0 - 0x68105110
// Functions (28):
//   xtra_freeObjectBlock
//   xtra_writeCertData
//   xtra_writeBERSequenceEx
//   xtra_readCertFieldEx
//   xtra_validateBERTagEx
//   xtra_encodeBERRawEx
//   xtra_parseBERCryptoHeader
//   xtra_readCertFieldFull
//   xtra_findTemplateEntry
//   xtra_validatePrintableString
//   xtra_createObjectSet
//   xtra_formatUTCTime
//   xtra_createObjectDataBlock
//   xtra_createObjectBlock
//   xtra_buildObjectBlock
//   xtra_getObjectBlockData
//   xtra_getObjectDerivedData
//   xtra_getObjectExtension
//   xtra_getObjectUserData
//   xtra_initObjectBlock
//   xtra_allocAndCopyBlock
//   xtra_allocZeroedBlock
//   xtra_allocObjectBlock
//   xtra_createContainerInstance
//   xtra_freeContainerIfValid
//   xtra_insertContainerData
//   xtra_storeContainerRawData
//   xtra_getContainerEncodedEntry

// ============================================================
// Function: xtra_freeObjectBlock (FUN_681035e0)
// Address: 681035e0
// Size: 114 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freeObjectBlock(undefined4 *param_1,int param_2)
{
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  
  if ((param_1 != (undefined4 *)0x0) && ((undefined4 *)param_1[10] == param_1)) {
    uVar3 = 0;
    if (param_1[5] != 0) {
      piVar1 = (int *)param_1[7];
      piVar4 = piVar1;
      do {
        if (*piVar4 == param_2) {
          iVar2 = piVar1[uVar3 * 2 + 1];
          piVar1[uVar3 * 2] = 0;
          *(undefined4 *)(param_1[7] + 4 + uVar3 * 8) = 0;
          xtra_resetBERReader(param_1);
          *(int *)param_1[7] = param_2;
          *(int *)(param_1[7] + 4) = iVar2;
          param_1[5] = 1;
          return 0;
        }
        piVar4 = piVar4 + 2;
        uVar3 = uVar3 + 1;
      } while (uVar3 < (uint)param_1[5]);
    }
    xtra_resetBERReader(param_1);
  }
  return 0;
}



// ============================================================
// Function: xtra_writeCertData (FUN_68103660)
// Address: 68103660
// Size: 50 bytes
// Params: uint * param_1, uint * param_2, int param_3, byte * param_4, uint param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_writeCertData(uint *param_1,uint *param_2,int param_3,byte *param_4,uint param_5)

{
  int iVar1;
  
  iVar1 = xtra_readCertField(param_1,param_2,param_3,param_4,param_5);
  if (iVar1 != 0) {
    iVar1 = xtra_getBERLength(iVar1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: xtra_writeBERSequenceEx (FUN_681036a0)
// Address: 681036a0
// Size: 40 bytes
// Params: undefined4 * param_1, uint * param_2, int param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_writeBERSequenceEx(undefined4 *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = xtra_writeBERSequence(param_1,param_2,param_3);
  if (uVar1 != 0) {
    iVar2 = xtra_getBERLength(uVar1);
    return iVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_readCertFieldEx (FUN_681036d0)
// Address: 681036d0
// Size: 50 bytes
// Params: int * param_1, uint * param_2, int param_3, byte * param_4, uint param_5
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readCertFieldEx(int *param_1,uint *param_2,int param_3,byte *param_4,uint param_5)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = xtra_readCertFieldFull(param_1,param_2,param_3,param_4,param_5);
  if (uVar1 != 0) {
    iVar2 = xtra_getBERLength(uVar1);
    return iVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_validateBERTagEx (FUN_68103710)
// Address: 68103710
// Size: 40 bytes
// Params: undefined4 * param_1, uint param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_validateBERTagEx(undefined4 *param_1,uint param_2,undefined4 *param_3)

{
  int iVar1;
  
  iVar1 = xtra_validateBERTag(param_1,param_2,param_3);
  if (iVar1 != 0) {
    iVar1 = xtra_getBERLength(iVar1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: xtra_encodeBERRawEx (FUN_68103740)
// Address: 68103740
// Size: 45 bytes
// Params: undefined4 * param_1, int param_2, uint param_3, byte param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_encodeBERRawEx(undefined4 *param_1,int param_2,uint param_3,byte param_4)

{
  int iVar1;
  
  iVar1 = xtra_encodeBERRaw(param_1,param_2,param_3,param_4);
  if (iVar1 != 0) {
    iVar1 = xtra_getBERLength(iVar1);
    return iVar1;
  }
  return 0;
}



// ============================================================
// Function: xtra_parseBERCryptoHeader (FUN_68103770)
// Address: 68103770
// Size: 55 bytes
// Params: uint * param_1, uint * param_2, int * param_3, undefined4 * param_4, byte * param_5, uint param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_parseBERCryptoHeader(uint *param_1,uint *param_2,int *param_3,undefined4 *param_4,byte *param_5,uint param_6
            )

{
  byte bVar1;
  undefined3 extraout_var;
  int iVar2;
  
  bVar1 = xtra_processCryptoOp(param_1,param_2,param_3,param_4,param_5,param_6);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    iVar2 = xtra_getBERLength(CONCAT31(extraout_var,bVar1));
    return iVar2;
  }
  return 0;
}



// ============================================================
// Function: xtra_readCertFieldFull (FUN_681037f0)
// Address: 681037f0
// Size: 341 bytes
// Params: int * param_1, uint * param_2, int param_3, byte * param_4, uint param_5
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_readCertFieldFull(int *param_1,uint *param_2,int param_3,byte *param_4,uint param_5)

{
  uint *puVar1;
  uint uVar2;
  int iVar3;
  uint local_30;
  int local_2c;
  int local_28;
  int local_24 [3];
  int local_18;
  int *local_10;
  
  xtra_initBEREncoder(local_24,0);
  *param_1 = 0;
  uVar2 = xtra_createObjectSet((int *)0x0,&local_2c,&local_30,param_2,param_3,param_4,param_5);
  if (uVar2 == 0) {
    if (local_2c != 0) {
      if (0x7fff < local_30) {
        return 0x219;
      }
      iVar3 = display_allocBlock(local_30);
      *param_1 = iVar3;
      if (iVar3 == 0) {
        return 0x206;
      }
      param_1[1] = local_30;
      display_checkAndFree(iVar3,param_4,local_30);
      return 0;
    }
    uVar2 = xtra_createObjectSet(local_24,&local_2c,&local_30,param_2,param_3,param_4,param_5);
    if (uVar2 != 0) {
      return uVar2;
    }
    if (local_18 == 0) {
      param_1[1] = 0;
      uVar2 = 0;
    }
    else {
      puVar1 = (uint *)(param_1 + 1);
      uVar2 = xtra_readCertChainEx(puVar1,&local_28,local_10);
      if (uVar2 == 0) {
        iVar3 = display_allocBlock(*puVar1);
        *param_1 = iVar3;
        if (iVar3 == 0) {
          uVar2 = 0x206;
        }
        else {
          xtra_readCertSequence(iVar3,puVar1,*puVar1,&local_28,(int)local_10,local_18 + -1);
        }
      }
    }
    xtra_freeBEREncoder(local_24);
  }
  return uVar2;
}



// ============================================================
// Function: xtra_findTemplateEntry (FUN_68103950)
// Address: 68103950
// Size: 82 bytes
// Params: int * param_1, uint * param_2, uint param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_findTemplateEntry(int *param_1,uint *param_2,uint param_3)
{
  uint *puVar1;
  uint uVar2;
  uint local_4;
  
  xtra_readCertData((int *)&local_4,param_2);
  uVar2 = 0;
  if (local_4 != 0) {
    puVar1 = param_2 + 3;
    do {
      if (*puVar1 == param_3) {
        *param_1 = (int)(param_2 + uVar2 * 4);
        return 0;
      }
      puVar1 = puVar1 + 4;
      uVar2 = uVar2 + 1;
    } while (uVar2 < local_4);
  }
  *param_1 = 0;
  return 0;
}



// ============================================================
// Function: xtra_validatePrintableString (FUN_681039b0)
// Address: 681039b0
// Size: 84 bytes
// Params: int param_1, uint param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_validatePrintableString(int param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  
  uVar2 = 0;
  if (param_2 != 0) {
    do {
      bVar1 = *(byte *)(param_1 + uVar2);
      if ((((bVar1 < 0x41) || (0x5a < bVar1)) && ((bVar1 < 0x61 || (0x7a < bVar1)))) &&
         ((bVar1 != 0x20 &&
          ((((bVar1 < 0x27 || (0x3a < bVar1)) || (bVar1 == 0x2a)) &&
           ((bVar1 != 0x3d && (bVar1 != 0x3f)))))))) {
        return 0;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < param_2);
  }
  return 1;
}



// ============================================================
// Function: xtra_createObjectSet (FUN_68103ab0)
// Address: 68103ab0
// Size: 2196 bytes
// Params: int * param_1, int * param_2, uint * param_3, uint * param_4, int param_5, byte * param_6, uint param_7
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl
xtra_createObjectSet(int *param_1,int *param_2,uint *param_3,uint *param_4,int param_5,byte *param_6,
            uint param_7)

{
  undefined4 *puVar1;
  byte bVar2;
  undefined3 extraout_var;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  bool bVar7;
  uint local_4c;
  int local_48;
  uint local_44;
  int local_40;
  int local_3c;
  int local_38;
  uint *local_34;
  int local_30;
  int local_2c;
  uint local_28;
  int local_24;
  int local_20;
  byte *local_1c;
  uint local_18;
  byte *local_14;
  size_t local_10;
  byte *local_c;
  int local_8;
  uint local_4;
  
  local_30 = 0;
  local_2c = 0;
  *param_2 = 1;
  bVar2 = xtra_processCryptoOp(param_3,&local_28,&local_24,&local_1c,param_6,param_7);
  if (CONCAT31(extraout_var,bVar2) != 0) {
    return 0x20c;
  }
  if (*param_3 == 0) {
    *param_2 = 0;
    if (param_1 == (int *)0x0) {
      return 0;
    }
    local_30 = local_24 + 4;
  }
  else {
    uVar5 = (uint)param_6[local_24 + 1];
    if (uVar5 != 0x80) {
      if (local_18 < 0x80) {
        if (local_18 != uVar5) goto LAB_68103b6d;
        if (local_18 < 0x80) goto LAB_68103b89;
      }
      if ((0xff < local_18) || (uVar5 == 0x81)) goto LAB_68103b89;
    }
LAB_68103b6d:
    *param_2 = 0;
    if (param_1 == (int *)0x0) {
      return 0;
    }
  }
LAB_68103b89:
  uVar5 = (*param_4 | 0x100) - 0x100;
  if (uVar5 == 0x1d) {
    if (*param_3 == 0) {
      uVar3 = xtra_readBERData(param_3,param_6,param_7);
      if (uVar3 != 0) {
        return uVar3;
      }
      local_18 = *param_3 - local_30;
    }
  }
  else if ((uVar5 & 0xff) != local_28) {
    if ((*param_4 & 0x100) != 0) {
      *param_3 = 0;
      return 0;
    }
    return 0x20c;
  }
  if (param_1 != (int *)0x0) {
    local_2c = param_1[3];
  }
  if ((uVar5 & 0x20) == 0) {
    if (((local_28 == 3) && (*local_1c != 0)) &&
       ((0xff >> (8 - *local_1c & 0x1f) & (uint)local_1c[local_18 - 1]) != 0)) {
      *param_2 = 0;
      if (param_1 == (int *)0x0) goto LAB_68103d63;
      local_c = local_1c + 1;
      local_8 = local_18 - 1;
      local_4 = (uint)*local_1c;
      uVar5 = xtra_writeBERBitString(param_1,3,0,(int *)&local_c);
      if (uVar5 != 0) {
        return uVar5;
      }
    }
    if ((param_1 != (int *)0x0) && (param_1[3] == local_2c)) {
      if (*param_2 == 0) {
        uVar5 = xtra_processCertChain((int)param_1,local_1c,local_18,local_28,0);
        if (uVar5 != 0) {
          return uVar5;
        }
      }
      else {
        uVar5 = xtra_processCertChain((int)param_1,param_6,*param_3,0x1b,0);
        if (uVar5 != 0) {
          return uVar5;
        }
      }
    }
  }
  else {
    local_40 = 0;
    if (param_1 != (int *)0x0) {
      uVar3 = xtra_processCertChain((int)param_1,&DAT_6818f000,0,uVar5 & 0xff,0);
      if (uVar3 != 0) {
        return uVar3;
      }
      *(byte **)(*(int *)(param_1[5] + -4 + param_1[3] * 4) + 0xc) = param_6 + 1;
    }
    if (((uVar5 & 0xc0) == 0) || ((uVar5 & 0x800) != 0)) {
      if ((uVar5 == 0x31) || ((uVar5 == 0x231 || ((uVar5 & 0x1820) == 0x1820)))) {
        local_40 = 1;
      }
      if ((uVar5 & 0x200) == 0) {
        if (((uVar5 == 0x30) || (uVar5 == 0x31)) || (uVar3 = local_18, (uVar5 & 0x800) != 0)) {
          local_3c = 1;
          if (*param_3 == 0) {
            uVar3 = 0;
            for (; ((pbVar4 = local_1c + uVar3, *pbVar4 != 0 || (pbVar4[1] != 0)) &&
                   (local_34 = param_4 + local_3c * 4, *local_34 != 0x1e));
                local_3c = local_3c + local_38) {
              uVar5 = xtra_createObjectSet(param_1,&local_48,&local_4c,local_34,param_5,pbVar4,
                                   (param_7 - uVar3) - local_30);
              if (uVar5 != 0) {
                return uVar5;
              }
              if (local_48 == 0) {
                *param_2 = 0;
              }
              if (((*param_2 != 0) && (local_40 != 0)) &&
                 (xtra_readCertRange(&local_44,local_1c + uVar3,local_4c,(int)local_1c,uVar3),
                 local_44 != uVar3)) {
                *param_2 = 0;
              }
              xtra_readCertData(&local_38,local_34);
              uVar3 = uVar3 + local_4c;
            }
          }
          else {
            uVar5 = 0;
            bVar7 = local_18 == 0;
            if (local_18 != 0) {
              do {
                local_34 = param_4 + local_3c * 4;
                if (*local_34 == 0x1e) break;
                uVar3 = xtra_createObjectSet(param_1,&local_48,&local_4c,local_34,param_5,local_1c + uVar5,
                                     local_18 - uVar5);
                if (uVar3 != 0) {
                  return uVar3;
                }
                if (local_48 == 0) {
                  *param_2 = 0;
                }
                if (((*param_2 != 0) && (local_40 != 0)) &&
                   (xtra_readCertRange(&local_44,local_1c + uVar5,local_4c,(int)local_1c,uVar5),
                   local_44 != uVar5)) {
                  *param_2 = 0;
                }
                xtra_readCertData(&local_38,local_34);
                uVar5 = uVar5 + local_4c;
                local_3c = local_3c + local_38;
              } while (uVar5 < local_18);
              bVar7 = local_18 == uVar5;
            }
            uVar3 = local_18;
            if (!bVar7) {
              return 0x20c;
            }
          }
        }
      }
      else if (*param_3 == 0) {
        for (uVar3 = 0; (pbVar4 = local_1c + uVar3, *pbVar4 != 0 || (pbVar4[1] != 0));
            uVar3 = uVar3 + local_4c) {
          uVar5 = xtra_createObjectSet(param_1,&local_48,&local_4c,param_4 + 4,param_5,pbVar4,
                               (param_7 - uVar3) - local_30);
          if (uVar5 != 0) {
            return uVar5;
          }
          if (local_48 == 0) {
            *param_2 = 0;
          }
          if (((*param_2 != 0) && (local_40 != 0)) &&
             (xtra_readCertRange(&local_44,local_1c + uVar3,local_4c,(int)local_1c,uVar3),
             local_44 != uVar3)) {
            *param_2 = 0;
          }
        }
      }
      else {
        uVar5 = 0;
        bVar7 = local_18 == 0;
        if (local_18 != 0) {
          do {
            uVar3 = xtra_createObjectSet(param_1,&local_48,&local_4c,param_4 + 4,param_5,local_1c + uVar5,
                                 local_18 - uVar5);
            if (uVar3 != 0) {
              return uVar3;
            }
            if (local_48 == 0) {
              *param_2 = 0;
            }
            if (((*param_2 != 0) && (local_40 != 0)) &&
               (xtra_readCertRange(&local_44,local_1c + uVar5,local_4c,(int)local_1c,uVar5),
               local_44 != uVar5)) {
              *param_2 = 0;
            }
            uVar5 = uVar5 + local_4c;
          } while (uVar5 < local_18);
          bVar7 = local_18 == uVar5;
        }
        uVar3 = local_18;
        if (!bVar7) {
          return 0x20c;
        }
      }
    }
    else {
      if (*param_3 == 0) {
        uVar5 = xtra_createObjectSet(param_1,&local_48,&local_18,param_4 + 4,param_5,local_1c,
                             param_7 - local_30);
        if (uVar5 != 0) {
          return uVar5;
        }
      }
      else {
        uVar5 = xtra_createObjectSet(param_1,&local_48,&local_4c,param_4 + 4,param_5,local_1c,local_18);
        if (uVar5 != 0) {
          return uVar5;
        }
        if (local_18 != local_4c) {
          return 0x20c;
        }
      }
      uVar3 = local_18;
      if (local_48 == 0) {
        *param_2 = 0;
      }
    }
    local_18 = uVar3;
    if (*param_3 == 0) {
      *param_3 = local_18 + local_30;
    }
    if (param_1 != (int *)0x0) {
      if (*param_2 == 0) {
        uVar5 = xtra_processCertChain((int)param_1,(local_40 == 0) - 1 & 0x6818f004,0,0x1e,0);
        if (uVar5 != 0) {
          return uVar5;
        }
      }
      else {
        **(undefined4 **)(param_1[5] + local_2c * 4) = param_6;
        *(uint *)(*(int *)(param_1[5] + local_2c * 4) + 4) = *param_3;
        *(undefined4 *)(*(int *)(param_1[5] + local_2c * 4) + 8) = 0x1b;
        param_1[3] = local_2c + 1;
      }
    }
  }
LAB_68103d63:
  if (*param_2 == 0) {
    if (((param_1 != (int *)0x0) && ((*param_4 & 0x100) != 0)) &&
       ((param_5 != 0 && (*(int *)(param_5 + param_4[3] * 4) != 0)))) {
      iVar6 = local_2c * 4;
      uVar5 = xtra_readCertChainEx(&local_10,&local_20,(int *)(param_1[5] + iVar6));
      if (uVar5 != 0) {
        return uVar5;
      }
      local_14 = (byte *)display_allocBlock(local_10);
      if (local_14 == (byte *)0x0) {
        return 0x206;
      }
      uVar5 = xtra_readCertBlockEx(param_1,(int *)&local_14,local_10);
      if (uVar5 != 0) {
        return uVar5;
      }
      xtra_readCertSequence((int)local_14,&local_10,local_10,&local_20,param_1[5] + iVar6,
                   (param_1[3] - local_2c) + -1);
      uVar5 = display_decodeFormat(local_14,*(byte **)(param_5 + param_4[3] * 4),local_10);
      if (uVar5 != 0) {
        param_1[3] = local_2c;
        return 0;
      }
      puVar1 = *(undefined4 **)(param_1[5] + iVar6);
      *puVar1 = local_14;
      puVar1[1] = local_10;
      *(undefined4 *)(*(int *)(param_1[5] + iVar6) + 8) = 0x1b;
      param_1[3] = local_2c + 1;
    }
  }
  else if ((((*param_4 & 0x100) != 0) && (param_5 != 0)) &&
          ((pbVar4 = *(byte **)(param_5 + param_4[3] * 4), pbVar4 != (byte *)0x0 &&
           ((uVar5 = display_decodeFormat(param_6,pbVar4,*param_3), uVar5 == 0 &&
            (*param_2 = 0, param_1 != (int *)0x0)))))) {
    param_1[3] = local_2c;
    return 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_formatUTCTime (FUN_68104350)
// Address: 68104350
// Size: 432 bytes
// Params: char * param_1, undefined4 * param_2, uint param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_formatUTCTime(char *param_1,undefined4 *param_2,uint param_3)

{
  ulonglong uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  uint uVar7;
  int iVar8;
  
  uVar2 = 0x1e13380;
  uVar7 = 0x46;
  if (0x1e1337f < param_3) {
    do {
      param_3 = param_3 - uVar2;
      uVar7 = uVar7 + 1;
      uVar2 = (int)uVar7 >> 0x1f;
      uVar2 = (-(uint)(((uVar7 ^ uVar2) - uVar2 & 3 ^ uVar2) == uVar2) & 0x15180) + 0x1e13380;
    } while (uVar2 <= param_3);
  }
  if (0xa9 < (int)uVar7) {
    return 0x208;
  }
  iVar8 = 1;
  piVar6 = &DAT_6818f140;
  uVar2 = (int)uVar7 >> 0x1f;
  while( true ) {
    if ((((uVar7 ^ uVar2) - uVar2 & 3 ^ uVar2) != uVar2) || (iVar5 = 0x1d, iVar8 != 2)) {
      iVar5 = *piVar6;
    }
    if (param_3 < (uint)(iVar5 * 0x15180)) break;
    param_3 = param_3 + iVar5 * -0x15180;
    piVar6 = piVar6 + 1;
    iVar8 = iVar8 + 1;
  }
  uVar2 = param_3 / 0x15180 + 1;
  uVar4 = param_3 + (1 - uVar2) * 0x15180;
  uVar1 = (ulonglong)uVar4 / 0xe10;
  uVar4 = uVar4 + (int)uVar1 * -0xe10;
  uVar3 = uVar4 / 0x3c;
  uVar4 = uVar4 % 0x3c;
  if (99 < (int)uVar7) {
    uVar7 = uVar7 - 100;
  }
  *param_1 = (char)((int)uVar7 / 10) + '0';
  param_1[1] = (char)((int)uVar7 % 10) + '0';
  param_1[2] = (char)(iVar8 / 10) + '0';
  param_1[3] = (char)(iVar8 % 10) + '0';
  param_1[4] = (char)(uVar2 / 10) + '0';
  param_1[5] = (char)(uVar2 % 10) + '0';
  param_1[6] = (char)(uVar1 / 10) + '0';
  param_1[7] = (char)(uVar1 % 10) + '0';
  param_1[8] = (char)(uVar3 / 10) + '0';
  param_1[9] = (char)(uVar3 % 10) + '0';
  param_1[10] = (char)(uVar4 / 10) + '0';
  param_1[0xb] = (char)(uVar4 % 10) + '0';
  param_1[0xc] = 'Z';
  *param_2 = 0xd;
  return 0;
}



// ============================================================
// Function: xtra_createObjectDataBlock (FUN_68104a30)
// Address: 68104a30
// Size: 25 bytes
// Params: int * param_1, int * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_createObjectDataBlock(int *param_1,int *param_2)
{
  xtra_writeBERBlock(param_1,(int *)0x0,0x24,*param_2);
  return 0;
}



// ============================================================
// Function: xtra_createObjectBlock (FUN_68104a50)
// Address: 68104a50
// Size: 149 bytes
// Params: undefined4 * param_1, int * param_2, int * param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_createObjectBlock(undefined4 *param_1,int *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int *local_8;
  undefined4 local_4;
  
  iVar1 = xtra_encodeBER(&local_8,param_1,*param_3);
  if (iVar1 != 0) {
    display_freeIfNonNull(*param_2);
    *param_2 = 0;
    return iVar1;
  }
  iVar1 = xtra_writeBERBytes(param_2,param_2[1],(int)param_1);
  if (iVar1 == 0) {
    xtra_freeObjectBlock(param_1,*param_2);
    iVar1 = param_2[1];
    *local_8 = *param_2;
    local_8[1] = iVar1;
    iVar1 = xtra_getObjectDerivedData(&local_4,param_1,param_3,param_4);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_buildObjectBlock (FUN_68104af0)
// Address: 68104af0
// Size: 237 bytes
// Params: int * param_1, undefined4 * param_2, int * param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_buildObjectBlock(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int *local_28;
  undefined4 uStack_24;
  undefined1 local_20 [8];
  int local_18 [2];
  undefined1 auStack_10 [4];
  int *piStack_c;
  undefined1 *puStack_8;
  undefined4 uStack_4;
  
  iVar1 = xtra_encodeBER(&local_28,param_2,*param_3);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (*local_28 == 0) {
    iVar1 = xtra_getObjectBlockData(local_18,param_2,param_3,param_4);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = (*(code *)param_3[1])(local_20,param_2,param_4);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = xtra_getObjectExtension(&uStack_24,param_2,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
    display_fillMemory(auStack_10,0,0x10);
    piStack_c = local_18;
    puStack_8 = local_20;
    uStack_4 = uStack_24;
    iVar1 = xtra_writeBERSequenceEx(local_28,(uint *)&DAT_6818f170,(int)auStack_10);
    if (iVar1 != 0) {
      return iVar1;
    }
    iVar1 = xtra_writeBERBytes(local_28,local_28[1],(int)param_2);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = local_28[1];
  *param_1 = *local_28;
  param_1[1] = iVar1;
  return 0;
}



// ============================================================
// Function: xtra_getObjectBlockData (FUN_68104be0)
// Address: 68104be0
// Size: 322 bytes
// Params: int * param_1, undefined4 * param_2, int * param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getObjectBlockData(int *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  uint uVar2;
  int *local_24;
  byte *local_20;
  uint uStack_1c;
  byte *local_18;
  uint uStack_14;
  undefined1 local_10 [4];
  int *local_c;
  byte **local_8;
  int *local_4;
  
  iVar1 = xtra_encodeBER(&local_24,param_2,*param_3);
  if (iVar1 != 0) {
    return iVar1;
  }
  if (local_24[2] == 0) {
    if (*local_24 == 0) {
      if (local_24[8] == 0) {
        return 0x124;
      }
      iVar1 = (*(code *)param_3[2])(local_24 + 2,local_24[8],param_4);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = xtra_writeBERBytes(local_24 + 2,local_24[3],(int)param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
    }
    else {
      display_fillMemory(local_10,0,0x10);
      local_8 = &local_20;
      local_c = local_24 + 2;
      local_4 = local_24 + 5;
      iVar1 = xtra_writeCertData((uint *)0x0,(uint *)&DAT_6818f170,(int)local_10,(byte *)*local_24,
                           local_24[1]);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = (*(code *)param_3[1])(&local_18,param_2,param_4);
      if (iVar1 != 0) {
        return iVar1;
      }
      if (uStack_14 != uStack_1c) {
        return 0x10a;
      }
      uVar2 = display_decodeFormat(local_20,local_18,uStack_1c);
      if (uVar2 != 0) {
        return 0x10a;
      }
    }
  }
  iVar1 = local_24[3];
  *param_1 = local_24[2];
  param_1[1] = iVar1;
  return 0;
}



// ============================================================
// Function: xtra_getObjectDerivedData (FUN_68104d30)
// Address: 68104d30
// Size: 121 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int * param_3, undefined4 param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getObjectDerivedData(undefined4 *param_1,undefined4 *param_2,int *param_3,undefined4 param_4)

{
  int iVar1;
  int local_c;
  int local_8 [2];
  
  iVar1 = xtra_encodeBER(&local_c,param_2,*param_3);
  if (iVar1 == 0) {
    if (*(int *)(local_c + 0x10) == 0) {
      iVar1 = xtra_getObjectBlockData(local_8,param_2,param_3,param_4);
      if (iVar1 != 0) {
        return iVar1;
      }
      if ((*(int *)(local_c + 0x10) == 0) &&
         (iVar1 = (*(code *)param_3[3])((int *)(local_c + 0x10),local_8,param_2,param_4), iVar1 != 0
         )) {
        return iVar1;
      }
    }
    iVar1 = 0;
    *param_1 = *(undefined4 *)(local_c + 0x10);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_getObjectExtension (FUN_68104db0)
// Address: 68104db0
// Size: 65 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getObjectExtension(undefined4 *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_2,*param_3);
  if (iVar1 == 0) {
    if (*(int *)(local_4 + 0x14) == 0) {
      return 0x124;
    }
    *param_1 = (int *)(local_4 + 0x14);
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_getObjectUserData (FUN_68104e00)
// Address: 68104e00
// Size: 51 bytes
// Params: int * param_1, undefined4 * param_2, int * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getObjectUserData(int *param_1,undefined4 *param_2,int *param_3)

{
  int iVar1;
  int local_4;
  
  iVar1 = xtra_encodeBER(&local_4,param_2,*param_3);
  if (iVar1 == 0) {
    *param_1 = local_4 + 0x20;
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_initObjectBlock (FUN_68104e40)
// Address: 68104e40
// Size: 44 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initObjectBlock(int *param_1)
{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)*param_1;
  if (puVar1 != (undefined4 *)0x0) {
    if (*(code **)*puVar1 != (code *)0x0) {
      (**(code **)*puVar1)(puVar1);
    }
    display_freeIfNonNull((int)puVar1);
    *param_1 = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_allocAndCopyBlock (FUN_68104e70)
// Address: 68104e70
// Size: 41 bytes
// Params: undefined4 param_1, int param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_allocAndCopyBlock(undefined4 param_1,int param_2)

{
  int iVar1;
  
  iVar1 = display_allocBlock(param_2);
  if (iVar1 != 0) {
    display_checkAndFree(iVar1,param_1,param_2);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_allocZeroedBlock (FUN_68104ea0)
// Address: 68104ea0
// Size: 38 bytes
// Params: size_t param_1
// Return: void *
// Calling convention: __cdecl
// ============================================================

void * __cdecl xtra_allocZeroedBlock(size_t param_1)

{
  void *pvVar1;
  
  pvVar1 = (void *)display_allocBlock(param_1);
  if (pvVar1 != (void *)0x0) {
    display_fillMemory(pvVar1,0,param_1);
  }
  return pvVar1;
}



// ============================================================
// Function: xtra_allocObjectBlock (FUN_68104ed0)
// Address: 68104ed0
// Size: 46 bytes
// Params: int * param_1, size_t param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_allocObjectBlock(int *param_1,size_t param_2)
{
  if ((void *)*param_1 != (void *)0x0) {
    display_fillMemory((void *)*param_1,0,param_2);
    display_freeIfNonNull(*param_1);
    *param_1 = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_createContainerInstance (FUN_68104f00)
// Address: 68104f00
// Size: 40 bytes
// Params: int * param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_createContainerInstance(int *param_1)

{
  int iVar1;
  
  if (param_1 == (int *)0x0) {
    return 0;
  }
  iVar1 = xtra_initContainerVtable((undefined4 *)0x0);
  if (iVar1 == 0) {
    return 0x100;
  }
  *param_1 = iVar1;
  return 0;
}



// ============================================================
// Function: xtra_freeContainerIfValid (FUN_68104f30)
// Address: 68104f30
// Size: 29 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freeContainerIfValid(int *param_1)
{
  if ((*param_1 != 0) && (*(int *)(*param_1 + 4) == 0x7cc)) {
    xtra_initObjectBlock(param_1);
  }
  return 0;
}



// ============================================================
// Function: xtra_insertContainerData (FUN_68104f50)
// Address: 68104f50
// Size: 150 bytes
// Params: int param_1, undefined4 * param_2
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_insertContainerData(int param_1,undefined4 *param_2)

{
  int iVar1;
  byte *local_8;
  uint local_4;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 4) != 0x7cc)) {
    return 0x11b;
  }
  if (param_2 == (undefined4 *)0x0) {
    return 0;
  }
  display_fillMemory(&local_8,0,8);
  iVar1 = xtra_readCertFieldEx((int *)&local_8,(uint *)&DAT_6818f258,0,(byte *)*param_2,param_2[1]);
  if ((iVar1 == 0) && (iVar1 = xtra_storeContainerRawData(param_1,local_8,local_4), iVar1 == 0)) {
    return 0;
  }
  xtra_allocObjectBlock((int *)&local_8,local_4);
  return iVar1;
}



// ============================================================
// Function: xtra_storeContainerRawData (FUN_68104ff0)
// Address: 68104ff0
// Size: 276 bytes
// Params: int param_1, byte * param_2, uint param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_storeContainerRawData(int param_1,byte *param_2,uint param_3)

{
  int iVar1;
  int local_3c;
  uint local_38;
  uint local_34;
  undefined4 local_30;
  int local_2c;
  undefined1 local_28 [4];
  int *local_24;
  int *local_20;
  int local_1c [3];
  undefined1 local_10 [16];
  
  display_fillMemory(local_1c,0,0xc);
  display_checkAndFree(local_10,param_1 + 0x10,0x10);
  display_fillMemory((void *)(param_1 + 0x10),0,0x10);
  local_1c[0] = param_1;
  iVar1 = xtra_parseBERCryptoHeader(&local_34,&local_38,&local_3c,&local_30,param_2,param_3);
  if (iVar1 == 0) {
    if (local_2c == 0) {
      *(undefined4 *)(param_1 + 0x24) = 1;
    }
    else {
      display_fillMemory(local_28,0,0xc);
      local_24 = local_1c;
      local_20 = local_24;
      iVar1 = xtra_writeCertData((uint *)0x0,(uint *)&DAT_6818f258,(int)local_28,param_2,param_3);
    }
    if (iVar1 == 0) {
      xtra_allocObjectBlock((int *)(param_1 + 8),*(size_t *)(param_1 + 0xc));
      *(int *)(param_1 + 8) = (int)param_2;
      *(uint *)(param_1 + 0xc) = param_3;
      *(undefined4 *)(param_1 + 0x20) = 1;
      xtra_freeAttributeList((int)local_10);
      return 0;
    }
  }
  xtra_freeAttributeList(param_1 + 0x10);
  display_checkAndFree(param_1 + 0x10,local_10,0x10);
  return iVar1;
}



// ============================================================
// Function: xtra_getContainerEncodedEntry (FUN_68105110)
// Address: 68105110
// Size: 81 bytes
// Params: undefined4 * param_1, int param_2, uint param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getContainerEncodedEntry(undefined4 *param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if ((param_2 == 0) || (*(int *)(param_2 + 4) != 0x7cc)) {
    return 0x11b;
  }
  if (param_1 == (undefined4 *)0x0) {
    return 0;
  }
  iVar1 = xtra_getAttributeByIndex(param_2 + 0x10,param_3);
  if (iVar1 == 0) {
    return 0x11f;
  }
  iVar1 = xtra_getContainerEncoded(iVar1,param_1,param_1 + 1);
  return iVar1;
}



