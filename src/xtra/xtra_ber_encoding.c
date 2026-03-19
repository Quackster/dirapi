// Module: xtra
// Topic: BER/DER encoding output and template-driven encoding
// Address range: 0x68101EA0 - 0x681035E0
// Functions (34):
//   xtra_initBEREncoder
//   xtra_freeBEREncoder
//   xtra_readBERData
//   xtra_readBERField
//   xtra_parseBERField
//   xtra_readBERBlock
//   xtra_writeBEREndMarker
//   xtra_flushBEROutput
//   xtra_decodeBERPair
//   xtra_encodeBERField
//   xtra_writeBERPair
//   xtra_writeBERField
//   xtra_initBERWriter
//   xtra_writeBERSequence
//   xtra_allocBERBuffer
//   xtra_writeBERBlock
//   xtra_encodeBER
//   xtra_writeBERTagEx
//   xtra_writeBERContent
//   xtra_writeBERBytes
//   xtra_writeBERInt
//   xtra_freeBERContent
//   xtra_writeBERTag
//   xtra_resetBERReader
//   xtra_resetBER
//   xtra_findBEREntry
//   xtra_decodeBER
//   xtra_decodeBERDirect
//   xtra_readBERValue
//   xtra_getBERLength
//   xtra_resizeBEREntry
//   xtra_writeBERData
//   xtra_detachBERNode
//   xtra_resetBERKeepChild

// ============================================================
// Function: xtra_initBEREncoder (xtra_initBEREncoder)
// Address: 68101ea0
// Size: 39 bytes
// Params: void * param_1, undefined4 param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initBEREncoder(void *param_1,undefined4 param_2)
{
  int local_8;
  xtra_clearCertBlockHeader(param_1);
  display_fillMemory((void *)((int)param_1 + 0xc),0,0x14);
  *(undefined4 *)((int)param_1 + 0x20) = param_2;
  return 0;
}



// ============================================================
// Function: xtra_freeBEREncoder (xtra_freeBEREncoder)
// Address: 68101ed0
// Size: 100 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freeBEREncoder(int *param_1)
{
  int iVar1;
  uint uVar2;
  
  if ((void *)param_1[6] != (void *)0x0) {
    display_fillMemory((void *)param_1[6],0,param_1[7]);
    display_freeIfNonNull(param_1[6]);
  }
  uVar2 = 0;
  if (param_1[4] != 0) {
    iVar1 = 0;
    do {
      iVar1 = iVar1 + 4;
      uVar2 = uVar2 + 1;
      display_freeIfNonNull(*(int *)(param_1[5] + -4 + iVar1));
    } while (uVar2 < (uint)param_1[4]);
  }
  display_freeIfNonNull(param_1[5]);
  xtra_readCertBlockData(param_1);
  return 0;
}



// ============================================================
// Function: xtra_readBERData (FUN_68101f40)
// Address: 68101f40
// Size: 151 bytes
// Params: uint * param_1, byte * param_2, uint param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readBERData(uint *param_1,byte *param_2,uint param_3)

{
  byte bVar1;
  undefined3 extraout_var;
  byte *pbVar2;
  int iVar3;
  int iVar4;
  uint local_14;
  int local_10;
  uint local_c;
  int local_8 [2];
  
  bVar1 = xtra_processCryptoOp(param_1,&local_c,&local_10,local_8,param_2,param_3);
  if (CONCAT31(extraout_var,bVar1) != 0) {
    return 0x20c;
  }
  if (*param_1 == 0) {
    for (iVar4 = 0; (pbVar2 = (byte *)(local_8[0] + iVar4), *pbVar2 != 0 || (pbVar2[1] != 0));
        iVar4 = iVar4 + local_14) {
      iVar3 = xtra_readBERData(&local_14,pbVar2,(param_3 - (local_10 + 4)) - iVar4);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    *param_1 = iVar4 + local_10 + 4;
    return 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_readBERField (xtra_readBERField)
// Address: 68101fe0
// Size: 1233 bytes
// Params: uint * param_1, uint * param_2, int param_3, byte * param_4, uint param_5, undefined4 * param_6
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_readBERField(uint *param_1,uint *param_2,int param_3,byte *param_4,uint param_5,undefined4 *param_6)

{
  undefined4 *puVar1;
  byte bVar2;
  int iVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  uint uVar4;
  uint *puVar5;
  int iVar6;
  uint uStack_40;
  uint local_3c;
  uint *puStack_38;
  int iStack_34;
  uint uStack_30;
  uint uStack_2c;
  int iStack_28;
  int iStack_24;
  byte *pbStack_20;
  uint uStack_1c;
  uint uStack_18;
  byte *pbStack_14;
  byte *pbStack_10;
  uint uStack_c;
  byte *pbStack_8;
  uint uStack_4;
  
  local_3c = (*param_2 | 0x100) - 0x100;
  if (param_6 != (undefined4 *)0x0) {
    iVar3 = (**(code **)*param_6)(param_6,&param_4,&param_5);
    if (iVar3 != 0) {
      return iVar3;
    }
    bVar2 = xtra_processCryptoOp(param_1,&uStack_2c,&iStack_24,&pbStack_20,param_4,param_5);
    if ((CONCAT31(extraout_var,bVar2) == 6) &&
       (iVar3 = xtra_readBERExplicitTag((int)param_6,&param_4,&param_5), iVar3 != 0)) {
      return iVar3;
    }
    if ((*(int *)(param_3 + param_2[3] * 4) != 0) && ((local_3c & 0x2400) == 0)) {
      param_6 = (undefined4 *)0x0;
    }
  }
  if (*(undefined **)(param_3 + param_2[3] * 4) == &DAT_6818eff8) {
    *param_1 = 0;
    return 0;
  }
  bVar2 = xtra_processCryptoOp(param_1,&uStack_2c,&iStack_24,&pbStack_20,param_4,param_5);
  if (CONCAT31(extraout_var_00,bVar2) != 0) {
    if ((CONCAT31(extraout_var_00,bVar2) == 6) && ((local_3c & 0x400) != 0)) {
      iVar3 = xtra_parseBERCertChunked(param_1,(int *)param_2,param_3,(int)param_4,param_5,param_6,uStack_2c,
                           (int *)&pbStack_20);
      return iVar3;
    }
    return 0x20c;
  }
  uVar4 = *param_1;
  if (uVar4 == 0) {
    iStack_28 = iStack_24 + 4;
  }
  else {
    param_6 = (undefined4 *)0x0;
  }
  if ((local_3c & 0xff) == 0x1d) {
    if (uVar4 != 0) goto LAB_68102437;
    iVar3 = xtra_readBERData(param_1,param_4,param_5);
  }
  else {
    if ((local_3c & 0xff) != uStack_2c) {
      if ((((local_3c & 0x2220) == 0) || ((param_2[4] & 0x20) != 0)) ||
         ((local_3c & 0xdf) != uStack_2c)) {
        if ((*param_2 & 0x100) == 0) {
          return 0x20c;
        }
        *param_1 = 0;
        return 0;
      }
      iVar3 = xtra_readBERField(&uStack_30,param_2 + 4,param_3,param_4,uVar4,(undefined4 *)0x0);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
    if ((uStack_2c & 0x20) == 0) goto LAB_68102437;
    xtra_readCertData((int *)&uStack_40,param_2);
    uVar4 = 1;
    puVar5 = param_2;
    if (1 < uStack_40) {
      do {
        if ((puVar5[4] != 0x1e) && (*(int *)(param_3 + puVar5[7] * 4) != 0)) break;
        uVar4 = uVar4 + 1;
        puVar5 = puVar5 + 4;
      } while (uVar4 < uStack_40);
      if (uVar4 < uStack_40) {
        if (*param_1 == 0) {
          uStack_1c = param_5 - iStack_28;
        }
        if (((local_3c & 0xc0) == 0) || (iStack_34 = 1, (local_3c & 0x800) != 0)) {
          iStack_34 = 0;
        }
        uVar4 = 0;
        if (param_6 != (undefined4 *)0x0) {
          uVar4 = iStack_24 + 2;
          pbStack_20 = param_4;
        }
        iVar3 = 1;
LAB_6810228e:
        if (iStack_34 == 0) {
          if (((local_3c & 0x200) == 0) && (param_2[iVar3 * 4] == 0x1e)) goto LAB_681022d1;
          if (*param_1 == 0) {
            if ((pbStack_20[uVar4] == 0) && ((pbStack_20 + uVar4)[1] == 0)) goto LAB_681022d1;
          }
          else if (uStack_1c <= uVar4) goto LAB_681022d1;
        }
        puStack_38 = param_2 + iVar3 * 4;
        iVar6 = xtra_readBERField(&uStack_30,puStack_38,param_3,pbStack_20 + uVar4,uStack_1c - uVar4,
                             param_6);
        if (iVar6 != 0) {
          return iVar6;
        }
        if (param_6 != (undefined4 *)0x0) {
          uVar4 = 0;
        }
        uVar4 = uVar4 + uStack_30;
        if (iStack_34 != 0) goto LAB_681022d1;
        if ((local_3c & 0x200) == 0) {
          xtra_readCertData((int *)&uStack_40,puStack_38);
          iVar3 = iVar3 + uStack_40;
        }
        goto LAB_6810228e;
      }
    }
    if (*param_1 != 0) goto LAB_68102437;
    iVar3 = xtra_readBERData(param_1,param_4,param_5);
  }
  if (iVar3 != 0) {
    return iVar3;
  }
  uStack_1c = *param_1 - iStack_28;
LAB_68102437:
  puVar1 = *(undefined4 **)(param_3 + param_2[3] * 4);
  if (puVar1 != (undefined4 *)0x0) {
    if ((code *)param_2[1] == (code *)0x0) {
      *puVar1 = param_4;
      *(uint *)(*(int *)(param_3 + param_2[3] * 4) + 4) = *param_1;
    }
    else {
      uStack_18 = uStack_2c;
      pbStack_14 = param_4 + 1;
      uStack_4 = *param_1;
      pbStack_8 = param_4;
      pbStack_10 = pbStack_20;
      uStack_c = uStack_1c;
      iVar3 = (*(code *)param_2[1])(&uStack_18,puVar1);
      if (iVar3 != 0) {
        return iVar3;
      }
    }
  }
  return 0;
LAB_681022d1:
  if (*param_1 == 0) {
    if (param_6 != (undefined4 *)0x0) {
      iStack_28 = 2;
    }
    *param_1 = iStack_28 + uVar4;
    uStack_1c = uVar4;
  }
  else if (uVar4 != uStack_1c) {
    return 0x20c;
  }
  if ((iStack_34 == 0) && ((local_3c & 0x200) == 0)) {
    uVar4 = param_2[iVar3 * 4];
    while (uVar4 != 0x1e) {
      puVar5 = param_2 + iVar3 * 4;
      if (((*puVar5 & 0x100) == 0) && (*(undefined **)(param_3 + puVar5[3] * 4) != &DAT_6818eff8)) {
        return 0x20c;
      }
      xtra_readCertData((int *)&uStack_40,puVar5);
      iVar3 = iVar3 + uStack_40;
      uVar4 = param_2[iVar3 * 4];
    }
  }
  goto LAB_68102437;
}



// ============================================================
// Function: xtra_parseBERField (FUN_681024c0)
// Address: 681024c0
// Size: 821 bytes
// Params: int * param_1, uint * param_2, int param_3
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_parseBERField(int *param_1,uint *param_2,int param_3)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  uint uVar6;
  int iVar7;
  int iStack_4;
  
  uVar6 = param_1[3];
  uVar2 = (*param_2 | 0x100) - 0x100;
  if ((code *)param_2[2] == (code *)0x0) {
    puVar1 = *(undefined4 **)(param_3 + param_2[3] * 4);
    if (puVar1 != (undefined4 *)0x0) {
      uVar2 = xtra_processCertChain((int)param_1,*puVar1,puVar1[1],0x1b,0);
      if (uVar2 != 0) {
        return uVar2;
      }
      goto LAB_681027b6;
    }
  }
  else {
    uVar3 = (*(code *)param_2[2])(param_1,uVar2 & 0xff,0,*(undefined4 *)(param_3 + param_2[3] * 4));
    if (uVar3 != 0) {
      return uVar3;
    }
    uVar3 = param_1[3];
    if (uVar6 < uVar3) {
      if (*(int *)(*(int *)(param_1[5] + -4 + uVar3 * 4) + 8) == 0x1e) {
        param_1[3] = uVar3 - 1;
        uVar2 = xtra_readBERBlock((int)param_1,uVar2 & 0xff,param_2);
        if (uVar2 != 0) {
          return uVar2;
        }
        uVar2 = xtra_processCertChain((int)param_1,0,0,0x1e,0);
        if (uVar2 != 0) {
          return uVar2;
        }
      }
      goto LAB_681027b6;
    }
  }
  if ((uVar2 & 0x20) == 0) {
    return -(uint)((*param_2 & 0x100) == 0) & 0x208;
  }
  if (((uVar2 & 0xc0) == 0) || ((uVar2 & 0x800) != 0)) {
    if (param_2[4] == 0x1e) {
      return -(uint)((*param_2 & 0x100) == 0) & 0x208;
    }
    if ((uVar2 & 0x200) == 0) {
      if (((uVar2 == 0x30) || (uVar2 == 0x31)) || ((uVar2 & 0x800) != 0)) {
        uVar3 = xtra_readBERBlock((int)param_1,uVar2 & 0xff,param_2);
        if (uVar3 != 0) {
          return uVar3;
        }
        iVar7 = 1;
        uVar3 = param_2[4];
        while (uVar3 != 0x1e) {
          uVar3 = xtra_parseBERField(param_1,param_2 + iVar7 * 4,param_3);
          if (uVar3 != 0) {
            return uVar3;
          }
          xtra_readCertData(&iStack_4,param_2 + iVar7 * 4);
          iVar7 = iVar7 + iStack_4;
          uVar3 = param_2[iVar7 * 4];
        }
        if ((uVar2 == 0x31) || ((uVar2 & 0x1820) == 0x1820)) {
          puVar5 = &DAT_6818f004;
        }
        else {
          puVar5 = (undefined *)0x0;
        }
        uVar2 = xtra_processCertChain((int)param_1,puVar5,0,0x1e,0);
        if (uVar2 != 0) {
          return uVar2;
        }
      }
    }
    else {
      if (param_2[2] == 0) {
        return 0x208;
      }
      uVar3 = xtra_readBERBlock((int)param_1,uVar2 & 0xff,param_2);
      if (uVar3 != 0) {
        return uVar3;
      }
      do {
        uVar3 = xtra_parseBERField(param_1,param_2 + 4,param_3);
        if (uVar3 != 0) {
          return uVar3;
        }
        uVar3 = param_1[3];
        uVar4 = (*(code *)param_2[2])
                          (param_1,uVar2 & 0xff,0,*(undefined4 *)(param_3 + param_2[3] * 4));
        if (uVar4 != 0) {
          return uVar4;
        }
      } while (((uint)param_1[3] <= uVar3) ||
              (*(int *)(*(int *)(param_1[5] + -4 + param_1[3] * 4) + 8) != 0x1e));
      if ((uVar2 == 0x231) || ((uVar2 & 0x1820) == 0x1820)) {
        **(undefined4 **)(param_1[5] + -4 + param_1[3] * 4) = &DAT_6818f004;
      }
      else {
        **(undefined4 **)(param_1[5] + -4 + param_1[3] * 4) = 0;
      }
    }
  }
  else {
    uVar2 = xtra_readBERBlock((int)param_1,uVar2 & 0xff,param_2);
    if (uVar2 != 0) {
      return uVar2;
    }
    uVar2 = xtra_parseBERField(param_1,param_2 + 4,param_3);
    if (uVar2 != 0) {
      return uVar2;
    }
    uVar2 = xtra_processCertChain((int)param_1,0,0,0x1e,0);
    if (uVar2 != 0) {
      return uVar2;
    }
  }
LAB_681027b6:
  if ((uVar6 != 0) ||
     ((((param_1[3] == 0 || (*(int *)(*(int *)(param_1[5] + -4 + param_1[3] * 4) + 8) != 0x1e)) ||
       (uVar6 = xtra_writeBEREndMarker((int)param_1), uVar6 == 0)) &&
      (uVar6 = xtra_flushBEROutput(param_1), uVar6 == 0)))) {
    uVar6 = 0;
  }
  return uVar6;
}



// ============================================================
// Function: xtra_readBERBlock (FUN_68102800)
// Address: 68102800
// Size: 124 bytes
// Params: int param_1, int param_2, uint * param_3
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readBERBlock(int param_1,int param_2,uint *param_3)
{
  uint uVar1;
  undefined1 local_6;
  undefined1 local_5;
  uint local_4;
  
  xtra_readCertData((int *)&local_4,param_3);
  uVar1 = 0;
  if (local_4 != 0) {
    do {
      if ((*param_3 & 0x2000) != 0) break;
      param_3 = param_3 + 4;
      uVar1 = uVar1 + 1;
    } while (uVar1 < local_4);
    if (uVar1 < local_4) {
      local_6 = (undefined1)param_2;
      local_5 = 0x80;
      (**(code **)**(undefined4 **)(param_1 + 0x20))(*(undefined4 **)(param_1 + 0x20),&local_6,2);
      return 0;
    }
  }
  xtra_processCertChain(param_1,&DAT_6818f000,0,param_2,0);
  return 0;
}



// ============================================================
// Function: xtra_writeBEREndMarker (xtra_writeBEREndMarker)
// Address: 68102880
// Size: 39 bytes
// Params: int param_1
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_writeBEREndMarker(int param_1)

{
  int local_2c;
  undefined4 uVar1;
  
  if (*(int *)(param_1 + 0xc) == 1) {
    *(undefined4 *)(param_1 + 0xc) = 0;
    uVar1 = (**(code **)**(undefined4 **)(param_1 + 0x20))
                      (*(undefined4 **)(param_1 + 0x20),&DAT_6818f008,2);
    return uVar1;
  }
  return 0;
}



// ============================================================
// Function: xtra_flushBEROutput (xtra_flushBEROutput)
// Address: 681028b0
// Size: 197 bytes
// Params: int * param_1
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_flushBEROutput(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint local_8;
  int local_4;
  
  if (param_1[3] == 0) {
    return 0;
  }
  uVar1 = xtra_readCertChainEx(&local_8,&local_4,(int *)param_1[5]);
  if (uVar1 == 0) {
    if ((uint)param_1[7] < local_8) {
      if ((void *)param_1[6] != (void *)0x0) {
        display_fillMemory((void *)param_1[6],0,param_1[7]);
      }
      iVar2 = display_freeFormatBlock(param_1[6],local_8);
      param_1[6] = iVar2;
      if (iVar2 == 0) {
        return 0x206;
      }
      param_1[7] = local_8;
    }
    xtra_readCertSequence(param_1[6],&local_8,local_8,&local_4,param_1[5],param_1[3] + -1);
    xtra_freeCertBlockItems(param_1);
    param_1[3] = 0;
    uVar1 = (*(code *)**(undefined4 **)param_1[8])((undefined4 *)param_1[8],param_1[6],local_8);
  }
  return uVar1;
}



// ============================================================
// Function: xtra_decodeBERPair (xtra_decodeBERPair)
// Address: 68102980
// Size: 118 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 * param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_decodeBERPair(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 local_1c;
  undefined4 local_18;
  int local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined4 *local_4;
  
  display_fillMemory(local_10,0,0x10);
  local_4 = &local_1c;
  local_c = param_1;
  local_8 = param_2;
  iVar1 = xtra_readCertField((uint *)0x0,(uint *)&DAT_6818f010,(int)local_10,(byte *)*param_4,param_4[1]);
  if (iVar1 == 0) {
    if (local_14 != 0) {
      return 0x20c;
    }
    *param_3 = local_1c;
    iVar1 = 0;
    param_3[1] = local_18;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_encodeBERField (xtra_encodeBERField)
// Address: 68102a00
// Size: 84 bytes
// Params: undefined4 param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_encodeBERField(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)
{
  undefined1 local_14 [4];
  undefined *local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  display_fillMemory(local_14,0,0x14);
  local_c = param_1;
  local_8 = param_2;
  local_4 = param_3;
  local_10 = &DAT_6818f100;
  xtra_readCertField((uint *)0x0,(uint *)&DAT_6818f080,(int)local_14,(byte *)*param_4,param_4[1]);
  return 0;
}



// ============================================================
// Function: xtra_writeBERPair (xtra_writeBERPair)
// Address: 68102a60
// Size: 93 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_writeBERPair(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)
{
  undefined4 local_1c;
  undefined4 local_18;
  undefined4 local_14;
  undefined1 local_10 [4];
  undefined4 local_c;
  undefined4 local_8;
  undefined1 *local_4;
  
  display_fillMemory(local_10,0,0x10);
  local_c = param_2;
  local_8 = param_3;
  local_4 = (undefined1 *)&local_1c;
  local_1c = *param_4;
  local_18 = param_4[1];
  local_14 = 0;
  xtra_writeBERSequence(param_1,(uint *)&DAT_6818f010,(int)local_10);
  return 0;
}



// ============================================================
// Function: xtra_writeBERField (xtra_writeBERField)
// Address: 68102ac0
// Size: 76 bytes
// Params: undefined4 * param_1, undefined4 param_2, undefined4 param_3, undefined4 param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl
xtra_writeBERField(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)
{
  undefined1 local_14 [4];
  undefined *local_10;
  undefined4 local_c;
  undefined4 local_8;
  undefined4 local_4;
  
  display_fillMemory(local_14,0,0x14);
  local_c = param_2;
  local_8 = param_3;
  local_4 = param_4;
  local_10 = &DAT_6818f100;
  xtra_writeBERSequence(param_1,(uint *)&DAT_6818f080,(int)local_14);
  return 0;
}



// ============================================================
// Function: xtra_initBERWriter (xtra_initBERWriter)
// Address: 68102b10
// Size: 31 bytes
// Params: undefined4 * param_1, undefined4 * param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_initBERWriter(undefined4 *param_1,undefined4 *param_2)
{
  param_1[1] = param_2;
  param_2[1] = 0;
  *param_2 = 0;
  *param_1 = &PTR_FUN_6818f108;
  return 0;
}



// ============================================================
// Function: xtra_writeBERSequence (FUN_68102b30)
// Address: 68102b30
// Size: 85 bytes
// Params: undefined4 * param_1, uint * param_2, int param_3
// Return: uint
// Calling convention: __cdecl
// ============================================================

uint __cdecl xtra_writeBERSequence(undefined4 *param_1,uint *param_2,int param_3)

{
  uint uVar1;
  undefined4 local_2c [2];
  int local_24 [9];
  
  xtra_initBERWriter(local_2c,param_1);
  xtra_initBEREncoder(local_24,local_2c);
  uVar1 = xtra_parseBERField(local_24,param_2,param_3);
  xtra_freeBEREncoder(local_24);
  return uVar1;
}



// ============================================================
// Function: xtra_allocBERBuffer (xtra_allocBERBuffer)
// Address: 68102b90
// Size: 88 bytes
// Params: int param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_allocBERBuffer(int param_1,undefined4 param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  
  piVar1 = *(int **)(param_1 + 4);
  if (*piVar1 != 0) {
    return 0x208;
  }
  iVar2 = display_allocBlock(param_3);
  *piVar1 = iVar2;
  if (**(int **)(param_1 + 4) == 0) {
    return 0x206;
  }
  (*(int **)(param_1 + 4))[1] = param_3;
  display_checkAndFree(**(undefined4 **)(param_1 + 4),param_2,(*(undefined4 **)(param_1 + 4))[1]);
  return 0;
}



// ============================================================
// Function: xtra_writeBERBlock (FUN_68102c20)
// Address: 68102c20
// Size: 139 bytes
// Params: int * param_1, int * param_2, size_t param_3, int param_4
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_writeBERBlock(int *param_1,int *param_2,size_t param_3,int param_4)

{
  int *piVar1;
  void *pvVar2;
  int iVar3;
  
  pvVar2 = (void *)display_allocBlock(0x2c);
  *param_1 = (int)pvVar2;
  if (pvVar2 == (void *)0x0) {
    return 0x100;
  }
  display_fillMemory(pvVar2,0,0x2c);
  piVar1 = (int *)*param_1;
  iVar3 = display_allocBlock(param_3);
  *piVar1 = iVar3;
  if (iVar3 == 0) {
    display_freeIfNonNull(*param_1);
    *param_1 = 0;
    return 0x100;
  }
  if (param_2 != (int *)0x0) {
    *param_2 = iVar3;
  }
  display_fillMemory((void *)*piVar1,0,param_3);
  piVar1[1] = param_3;
  piVar1[9] = param_4;
  piVar1[10] = *param_1;
  return 0;
}



// ============================================================
// Function: xtra_encodeBER (FUN_68102cb0)
// Address: 68102cb0
// Size: 49 bytes
// Params: undefined4 * param_1, undefined4 * param_2, int param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_encodeBER(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  if (((param_2 != (undefined4 *)0x0) && ((undefined4 *)param_2[10] == param_2)) &&
     (param_2[9] == param_3)) {
    *param_1 = *param_2;
    return 0;
  }
  *param_1 = 0;
  return 0x124;
}



// ============================================================
// Function: xtra_writeBERTagEx (FUN_68102cf0)
// Address: 68102cf0
// Size: 187 bytes
// Params: int * param_1, undefined4 param_2, int param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_writeBERTagEx(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  *param_1 = 0;
  if ((param_3 == 0) || (*(int *)(param_3 + 0x28) != param_3)) {
    return 0x124;
  }
  iVar2 = *(int *)(param_3 + 0x14);
  if (*(uint *)(param_3 + 0x18) < iVar2 + 1U) {
    iVar1 = display_allocBlock(iVar2 * 8 + 0x58);
    if (iVar1 == 0) {
      return 0x100;
    }
    display_checkAndFree(iVar1,*(undefined4 *)(param_3 + 0x1c),*(int *)(param_3 + 0x14) << 3);
    display_freeIfNonNull(*(int *)(param_3 + 0x1c));
    *(int *)(param_3 + 0x1c) = iVar1;
    *(int *)(param_3 + 0x18) = iVar2 + 0xb;
  }
  iVar2 = display_allocBlock(param_2);
  *param_1 = iVar2;
  if (iVar2 == 0) {
    return 0x100;
  }
  *(int *)(*(int *)(param_3 + 0x1c) + *(int *)(param_3 + 0x14) * 8) = iVar2;
  *(undefined4 *)(*(int *)(param_3 + 0x1c) + 4 + *(int *)(param_3 + 0x14) * 8) = param_2;
  *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) + 1;
  return 0;
}



// ============================================================
// Function: xtra_writeBERContent (FUN_68102db0)
// Address: 68102db0
// Size: 51 bytes
// Params: int * param_1, undefined4 param_2, int param_3, int param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_writeBERContent(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  
  iVar1 = xtra_writeBERTagEx(param_1,param_3,param_4);
  if (iVar1 == 0) {
    display_checkAndFree(*param_1,param_2,param_3);
    iVar1 = 0;
  }
  return iVar1;
}



// ============================================================
// Function: xtra_writeBERBytes (FUN_68102df0)
// Address: 68102df0
// Size: 232 bytes
// Params: int * param_1, size_t param_2, int param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_writeBERBytes(int *param_1,size_t param_2,int param_3)

{
  int iVar1;
  int iVar2;
  
  if ((param_3 != 0) && (*(int *)(param_3 + 0x28) == param_3)) {
    iVar1 = *(int *)(param_3 + 0x14);
    if (*(uint *)(param_3 + 0x18) < iVar1 + 1U) {
      iVar2 = display_allocBlock(iVar1 * 8 + 0x58);
      if (iVar2 == 0) {
        display_fillMemory((void *)*param_1,0,param_2);
        display_freeIfNonNull(*param_1);
        *param_1 = 0;
        return 0x100;
      }
      display_checkAndFree(iVar2,*(undefined4 *)(param_3 + 0x1c),*(int *)(param_3 + 0x14) << 3);
      display_freeIfNonNull(*(int *)(param_3 + 0x1c));
      *(int *)(param_3 + 0x1c) = iVar2;
      *(int *)(param_3 + 0x18) = iVar1 + 0xb;
    }
    *(int *)(*(int *)(param_3 + 0x1c) + *(int *)(param_3 + 0x14) * 8) = *param_1;
    *(size_t *)(*(int *)(param_3 + 0x1c) + 4 + *(int *)(param_3 + 0x14) * 8) = param_2;
    *(int *)(param_3 + 0x14) = *(int *)(param_3 + 0x14) + 1;
    return 0;
  }
  display_fillMemory((void *)*param_1,0,param_2);
  display_freeIfNonNull(*param_1);
  *param_1 = 0;
  return 0x124;
}



// ============================================================
// Function: xtra_writeBERInt (FUN_68102ee0)
// Address: 68102ee0
// Size: 142 bytes
// Params: int * param_1, uint param_2, int param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_writeBERInt(int *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  int *local_4;
  
  if (*param_1 == 0) {
    uVar1 = xtra_writeBERTagEx(param_1,param_2,param_3);
    return uVar1;
  }
  iVar2 = xtra_findBEREntry((int *)&local_4,*param_1,param_3);
  if (iVar2 != 0) {
    *param_1 = 0;
    return 0x124;
  }
  iVar2 = display_freeFormatBlock(*param_1,param_2);
  *local_4 = iVar2;
  iVar2 = *local_4;
  *param_1 = iVar2;
  if (iVar2 == 0) {
    local_4[1] = 0;
    return 0x100;
  }
  local_4[1] = param_2;
  return 0;
}



// ============================================================
// Function: xtra_freeBERContent (xtra_freeBERContent)
// Address: 68102f70
// Size: 101 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_freeBERContent(int *param_1,int param_2)
{
  int iVar1;
  undefined4 *local_4;
  
  if (param_1 != (int *)0x0) {
    iVar1 = xtra_findBEREntry((int *)&local_4,*param_1,param_2);
    if (iVar1 == 0) {
      display_fillMemory((void *)*param_1,0,local_4[1]);
      display_freeIfNonNull(*param_1);
      *local_4 = 0;
      local_4[1] = 0;
    }
    *param_1 = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_writeBERTag (FUN_68102fe0)
// Address: 68102fe0
// Size: 196 bytes
// Params: int * param_1, int param_2
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_writeBERTag(int *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  if ((((param_2 != 0) && (*(int *)(param_2 + 0x28) == param_2)) && (iVar1 = *param_1, iVar1 != 0))
     && ((*(int *)(iVar1 + 0x28) == iVar1 && (*(int *)(iVar1 + 0x20) == 0)))) {
    iVar1 = *(int *)(param_2 + 8);
    if (*(uint *)(param_2 + 0xc) < iVar1 + 1U) {
      iVar2 = display_allocBlock(iVar1 * 4 + 0x2c);
      if (iVar2 == 0) {
        xtra_resetBER(param_1);
        return 0x100;
      }
      display_checkAndFree(iVar2,*(undefined4 *)(param_2 + 0x10),*(int *)(param_2 + 8) << 2);
      display_freeIfNonNull(*(int *)(param_2 + 0x10));
      *(int *)(param_2 + 0x10) = iVar2;
      *(int *)(param_2 + 0xc) = iVar1 + 0xb;
    }
    *(int *)(*(int *)(param_2 + 0x10) + *(int *)(param_2 + 8) * 4) = *param_1;
    *(int *)(param_2 + 8) = *(int *)(param_2 + 8) + 1;
    *(int *)(*param_1 + 0x20) = param_2;
    return 0;
  }
  xtra_resetBER(param_1);
  return 0x124;
}



// ============================================================
// Function: xtra_resetBERReader (FUN_681030b0)
// Address: 681030b0
// Size: 174 bytes
// Params: undefined4 * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_resetBERReader(undefined4 *param_1)
{
  undefined4 *puVar1;
  uint uVar2;
  int iVar3;
  
  if ((param_1 != (undefined4 *)0x0) && ((undefined4 *)param_1[10] == param_1)) {
    if ((code *)param_1[9] != (code *)0x0) {
      (*(code *)param_1[9])(*param_1);
    }
    uVar2 = 0;
    display_fillMemory((void *)*param_1,0,param_1[1]);
    if (param_1[2] != 0) {
      iVar3 = 0;
      do {
        if (*(int *)(param_1[4] + iVar3) != 0) {
          *(undefined4 *)(*(int *)(param_1[4] + iVar3) + 0x20) = 0;
          xtra_resetBER((int *)(param_1[4] + iVar3));
        }
        iVar3 = iVar3 + 4;
        uVar2 = uVar2 + 1;
      } while (uVar2 < (uint)param_1[2]);
    }
    iVar3 = 0;
    uVar2 = 0;
    param_1[2] = 0;
    if (param_1[5] != 0) {
      do {
        uVar2 = uVar2 + 1;
        puVar1 = (undefined4 *)(param_1[7] + iVar3);
        iVar3 = iVar3 + 8;
        display_fillMemory((void *)*puVar1,0,puVar1[1]);
        display_freeIfNonNull(*(int *)(param_1[7] + -8 + iVar3));
      } while (uVar2 < (uint)param_1[5]);
    }
    param_1[5] = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_resetBER (FUN_68103160)
// Address: 68103160
// Size: 118 bytes
// Params: int * param_1
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_resetBER(int *param_1)
{
  int *piVar1;
  
  piVar1 = (int *)*param_1;
  if (param_1 != (int *)0x0) {
    if (((piVar1 != (int *)0x0) && ((int *)piVar1[10] == piVar1)) && (piVar1[8] == 0)) {
      xtra_resetBERReader(piVar1);
      display_freeIfNonNull(piVar1[4]);
      display_freeIfNonNull(piVar1[7]);
      display_fillMemory((void *)*piVar1,0,piVar1[1]);
      display_freeIfNonNull(*piVar1);
      piVar1[10] = 0;
      display_freeIfNonNull(*param_1);
    }
    *param_1 = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_findBEREntry (xtra_findBEREntry)
// Address: 681031e0
// Size: 77 bytes
// Params: int * param_1, int param_2, int param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_findBEREntry(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (param_2 == 0) {
    return 0x124;
  }
  if ((param_3 != 0) && (*(int *)(param_3 + 0x28) == param_3)) {
    iVar1 = *(int *)(param_3 + 0x14);
    *param_1 = *(int *)(param_3 + 0x1c);
    while (iVar1 != 0) {
      iVar1 = iVar1 + -1;
      if (*(int *)*param_1 == param_2) {
        return 0;
      }
      *param_1 = (int)((int *)*param_1 + 2);
    }
  }
  return 0x124;
}



// ============================================================
// Function: xtra_decodeBER (FUN_68103230)
// Address: 68103230
// Size: 68 bytes
// Params: undefined4 param_1, int param_2, int param_3, undefined4 * param_4
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_decodeBER(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = param_2;
  if ((((param_2 != 0x100) && (param_2 != 0x113)) && (param_2 != 0x11d)) &&
     (((param_2 != 0x10b && (iVar1 = param_3, param_4 != (undefined4 *)0x0)) && (param_3 != param_2)
      ))) {
    (*(code *)*param_4)(param_1,0,param_2,param_4[1]);
  }
  return iVar1;
}



// ============================================================
// Function: xtra_decodeBERDirect (FUN_68103280)
// Address: 68103280
// Size: 38 bytes
// Params: undefined4 param_1, int param_2, int param_3, undefined4 * param_4
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_decodeBERDirect(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)
{
  int iVar1;
  
  iVar1 = xtra_getBERLength(param_2);
  xtra_decodeBER(param_1,iVar1,param_3,param_4);
  return 0;
}



// ============================================================
// Function: xtra_readBERValue (FUN_681032b0)
// Address: 681032b0
// Size: 60 bytes
// Params: undefined4 param_1, int param_2, undefined4 * param_3
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_readBERValue(undefined4 param_1,int param_2,undefined4 *param_3)

{
  if ((((param_2 != 0x100) && (param_2 != 0x113)) && (param_2 != 0x11d)) && (param_2 != 0x10b)) {
    if (param_3 != (undefined4 *)0x0) {
      (*(code *)*param_3)(param_1,1,param_2,param_3[1]);
    }
    param_2 = 0;
  }
  return param_2;
}



// ============================================================
// Function: xtra_getBERLength (FUN_681032f0)
// Address: 681032f0
// Size: 171 bytes
// Params: int param_1
// Return: int
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_getBERLength(int param_1)

{
  if ((param_1 < 0x100) || (0x1ff < param_1)) {
    switch(param_1) {
    case 0x202:
      return 0x124;
    case 0x203:
      return 0x124;
    case 0x204:
      return 0x124;
    case 0x205:
      return 0x124;
    case 0x206:
      return 0x100;
    case 0x207:
      return 0x10b;
    case 0x208:
      return 0x112;
    case 0x209:
      return 0x119;
    case 0x20a:
      return 0x11a;
    case 0x20b:
      return 0x11d;
    case 0x20c:
      return 0x10a;
    case 0x20d:
      return 0x120;
    default:
      return 0x112;
    case 0x212:
      return 0x124;
    case 0x214:
      return 0x124;
    case 0x215:
      return 0x129;
    case 0x217:
      return 0x12e;
    case 0x218:
      return 0x12f;
    case 0x219:
      return 0x131;
    case 0x21a:
      return 0x13d;
    case 0x21b:
      return 0x13d;
    case 0x21c:
      param_1 = 0x125;
    }
  }
  return param_1;
}



// ============================================================
// Function: xtra_resizeBEREntry (xtra_resizeBEREntry)
// Address: 68103410
// Size: 187 bytes
// Params: int * param_1, uint param_2, int param_3
// Return: undefined4
// Calling convention: __cdecl
// ============================================================

undefined4 __cdecl xtra_resizeBEREntry(int *param_1,uint param_2,int param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  int *local_4;
  
  if (*param_1 == 0) {
    uVar1 = xtra_writeBERTagEx(param_1,param_2,param_3);
    return uVar1;
  }
  iVar2 = xtra_findBEREntry((int *)&local_4,*param_1,param_3);
  if (iVar2 != 0) {
    return 0x124;
  }
  iVar2 = display_allocBlock(param_2);
  if (iVar2 == 0) {
    return 0x100;
  }
  uVar3 = local_4[1];
  if (param_2 <= (uint)local_4[1]) {
    uVar3 = param_2;
  }
  display_checkAndFree(iVar2,*param_1,uVar3);
  display_fillMemory((void *)*param_1,0,local_4[1]);
  display_freeIfNonNull(*param_1);
  *local_4 = iVar2;
  *param_1 = *local_4;
  local_4[1] = param_2;
  return 0;
}



// ============================================================
// Function: xtra_writeBERData (FUN_681034d0)
// Address: 681034d0
// Size: 49 bytes
// Params: int * param_1, int * param_2, size_t param_3, int param_4, int param_5
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_writeBERData(int *param_1,int *param_2,size_t param_3,int param_4,int param_5)
{
  int iVar1;
  
  iVar1 = xtra_writeBERBlock(param_1,param_2,param_3,param_5);
  if (iVar1 == 0) {
    xtra_writeBERTag(param_1,param_4);
  }
  return 0;
}



// ============================================================
// Function: xtra_detachBERNode (xtra_detachBERNode)
// Address: 68103510
// Size: 111 bytes
// Params: int * param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_detachBERNode(int *param_1,int param_2)
{
  uint uVar1;
  int *piVar2;
  
  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {
    if ((param_2 != 0) && (*(int *)(param_2 + 0x28) == param_2)) {
      uVar1 = 0;
      if (*(uint *)(param_2 + 8) != 0) {
        piVar2 = *(int **)(param_2 + 0x10);
        while (*piVar2 != *param_1) {
          piVar2 = piVar2 + 1;
          uVar1 = uVar1 + 1;
          if (*(uint *)(param_2 + 8) <= uVar1) {
            *param_1 = 0;
            return 0;
          }
        }
        *(undefined4 *)((*(int **)(param_2 + 0x10))[uVar1] + 0x20) = 0;
        xtra_resetBER((int *)(*(int *)(param_2 + 0x10) + uVar1 * 4));
      }
    }
    *param_1 = 0;
  }
  return 0;
}



// ============================================================
// Function: xtra_resetBERKeepChild (xtra_resetBERKeepChild)
// Address: 68103580
// Size: 91 bytes
// Params: undefined4 * param_1, int param_2
// Return: undefined
// Calling convention: __cdecl
// ============================================================

int __cdecl xtra_resetBERKeepChild(undefined4 *param_1,int param_2)
{
  uint uVar1;
  int *piVar2;
  
  if ((param_1 != (undefined4 *)0x0) && ((undefined4 *)param_1[10] == param_1)) {
    uVar1 = 0;
    if (param_1[2] != 0) {
      piVar2 = (int *)param_1[4];
      do {
        if (*piVar2 == param_2) {
          ((int *)param_1[4])[uVar1] = 0;
          xtra_resetBERReader(param_1);
          *(int *)param_1[4] = param_2;
          param_1[2] = 1;
          return 0;
        }
        piVar2 = piVar2 + 1;
        uVar1 = uVar1 + 1;
      } while (uVar1 < (uint)param_1[2]);
    }
    xtra_resetBERReader(param_1);
  }
  return 0;
}



